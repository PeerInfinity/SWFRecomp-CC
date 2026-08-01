# Diagnosis batch — E4X and misc singles

Repo HEAD at diagnosis: `46dcf3a06` (session-6 closeout). Baseline CI results read
from `origin/ruffle-test-results` @ `2ab0c01be`
(`ruffle-tests/tests/swfs/{avm2,from_avmplus}/_results/results_graphics.json`).

All five items were re-measured locally (`--mode` default / no-graphics, one or two
at a time). **Two of the five are already fixed at HEAD** — the brief was written
against §5.5/§7.7, which session 6 (`569a215e4`) superseded.

| # | Test | Verdict |
|---|---|---|
| 1 | `from_avmplus/e4x/XML/e13_4_4_36` | **READY** — 2 rules, one site (`to_xml_string_inner`), ~30 lines |
| 2 | `from_avmplus/e4x/Regress/regress-524214` | **ALREADY FIXED** — shipped in `569a215e4`, passes at HEAD |
| 3 | `avm2/parse_float_swf10` | **READY** — 1 cause, 2 rows, ~4 lines. §5.5's "three causes" is wrong |
| 4 | `avm2/issue_8630_placeremoveplace{,_scriptremove}` | **READY-ish** — cause A ready (~35 lines); cause B (`transformed_by_script`) is ready but needs a broad timeline canary |
| 5 | `avm2/scopes_dont_cache/order-{1,2}` | **ALREADY FIXED** — shipped in `569a215e4`, both pass at HEAD |

---

## 1. `from_avmplus/e4x/XML/e13_4_4_36` — `setNamespace` prefix minting

**Status**: `output_mismatch`, 13/16 lines. `test.toml` has `known_failure = true`,
so **Ruffle is not the oracle** — the expected `output.txt` is avmplus's own, and
Ruffle's `e4x.rs` has no prefix-minting code at all. Grade against avmplus/ECMA-357.

### Current diff (local run, HEAD)

```
- 4 ... MYXML.setNamespace('http://zxz.org/xml'),MYXML.toString() PASSED!
+ 4 ... FAILED! expected: <a xmlns="http://foo"><b><aaa:c xmlns:aaa="http://bar">d</aaa:c></b></a>
                    got: <a xmlns="http://foo"><b><c    xmlns="http://bar">d</c></b></a>
- 5 Adding two namespaces by uri PASSED!
+ 5 FAILED! expected: <a xmlns="http://www.zzz.com"><aaa:b xmlns:aaa="http://www.zzz.org">c</aaa:b></a>
              got: <a xmlns="http://www.zzz.com"><b    xmlns="http://www.zzz.org">c</b></a>
- 7 Adding two namespaces with prefix 'zzz' PASSED!
+ 7 FAILED! expected: <abc:a xmlns:abc="http://www.zzz.com"><abc:b xmlns:def="http://www.zzz.com">c</abc:b></abc:a>
              got: <abc:a xmlns:abc="http://www.zzz.com"><def:b xmlns:def="http://www.zzz.com">c</def:b></abc:a>
```

**Two independent causes**, both in the serializer, both required to land the test.

### Cause A (rows 4 and 5) — no prefix minting

`new Namespace(uri)` with a non-empty uri has **prefix `undefined`** (ECMA-357
13.2.2; our `ns_from_arg`, `avm2_xml.c:1541-1563`, already gets this right — it
only assigns `""` when the uri is empty). `[[AddInScopeNamespace]]` (ECMA 9.1.1.13
step 2) therefore *returns immediately* for such a namespace: `setNamespace("http://bar")`
retags the node's QName and adds **nothing** to `[[InScopeNamespaces]]`.

The prefix is then chosen at serialization time, ECMA-357 **10.2.1 step 11**:

> If `ns.prefix == undefined`, let `ns.prefix` be an *arbitrary implementation
> defined* namespace prefix such that there is no `ns2` in
> (`AncestorNamespaces` ∪ `namespaceDeclarations`) with `ns2.prefix == ns.prefix`;
> add `ns` to `namespaceDeclarations`.

The test pins avmplus's choice exactly:

| node | currentNamespaces at that node | avmplus mints | why |
|---|---|---|---|
| root `<a>` (`setNamespace('http://foo')`) | `{}` | `""` | empty prefix free → default `xmlns=` |
| root `<stylesheet>` (row 2, passing) | `{xsl→w3}` | `""` | empty prefix free |
| `<c>` under `<a xmlns="http://foo">` | `{""→http://foo}` | `"aaa"` | `""` taken by a *different* uri |
| `<b>` under `<a xmlns="http://www.zzz.com">` | `{""→zzz.com}` | `"aaa"` | same |

So the rule is: **try `""` first; if some namespace in scope already binds the
empty prefix, mint `"aaa"`**. (Rhino mints `"ns"` — the test's own comment says so —
which is why this is implementation-defined and must be matched to avmplus, not
to a spec.)

Our code never mints: `avm2_e4x.c:1102-1106` pushes `node->ns` verbatim into
`decls`, and the emitter (`:1160`) prints `xmlns=` whenever the prefix is
`NULL`/empty. That is correct *by accident* whenever `""` happens to be free
(which is why rows 1/2/3/6 pass) and wrong the moment it isn't.

### Cause B (row 7) — the `[[GetNamespace]]` tie-break picks the wrong side

`n3 = Namespace('abc','http://www.zzz.com')` on `<a>`, `n4 = Namespace('def','http://www.zzz.com')`
on `<b>`. Both prefixes bind the *same* uri. At `<b>`, `currentNamespaces` =
`AncestorNamespaces {abc→zzz.com}` ∪ `namespaceDeclarations {def→zzz.com}`.
ECMA `[[GetNamespace]]` (13.3.5.4 step 2) says "if more than one such namespace
exists, the implementation may choose one arbitrarily" — **avmplus chooses the
ancestor one** (`abc`), while still emitting `xmlns:def` because `def` is in
`namespaceDeclarations`. Hence `<abc:b xmlns:def="...">`.

Our `anc_find_uri` (`avm2_e4x.c:1021-1031`) walks `anc` (the *local* frame,
`here`) before `anc->prev` (ancestors), so it returns `def`. Note this is *only*
a tie-break — `avm2_e4x_in_scope_namespaces` must keep its current inner→outer
order, since that is what makes an inner prefix *shadow* an outer one (row 6,
`zzz` rebound on `<b>`, depends on it). A naive reversal of the in-scope walk
would break row 6.

### Fix design

Single file, single function: `SWFModernRuntime/src/avm2/avm2_e4x.c`,
`to_xml_string_inner` (+ two small helpers next to `anc_find_uri`, line ~1021).

1. **Outermost-first uri lookup** (cause B). Add

   ```c
   static const E4XNamespace* anc_find_uri_outer(const AncNs* a, const Avm2String* uri)
   {
       if (a == NULL) return NULL;
       const E4XNamespace* r = anc_find_uri_outer(a->prev, uri);   /* ancestors first */
       if (r != NULL) return r;
       for (uint32_t i = 0; i < a->count; i++)
           if (str_eq(a->list[i].uri, uri)) return &a->list[i];
       return NULL;
   }
   ```

   and use it in **`PREFIX_OF`** (`:1118-1123`) and in the **close-tag** lookup
   (`:1199`). Leave the two *presence* tests at `:1102` and `:1110`
   (`anc_find_uri(&here, ...) == NULL`) on the existing function — order is
   irrelevant for a boolean, and switching them would be a pointless recursion.

2. **Prefix minting** (cause A). Add

   ```c
   /* ECMA-357 10.2.1 step 11. avmplus takes "" when the empty prefix is free
      and "aaa" otherwise (e4x/XML/e13_4_4_36). */
   static const Avm2String* mint_prefix(Avm2Context* ctx, const AncNs* here);
   ```

   which returns `NULL` (keep today's `xmlns=` emission — see "minimal form"
   below) when no entry in the `here` chain binds the empty prefix (treating a
   `NULL` prefix and a zero-length prefix as the same thing), and otherwise the
   first of `"aaa"`, `"aab"`, … not already bound in the chain.

   Apply it at the two push sites, e.g. `:1102-1106`:

   ```c
   if (node->has_ns && anc_find_uri(&here, node->ns.uri) == NULL && decl_count < 64)
   {
       E4XNamespace d = node->ns;
       if ((d.prefix == NULL || d.prefix->len == 0) && d.uri->len > 0)
           d.prefix = mint_prefix(ctx, &here);
       decls[decl_count++] = d;
       here.count = decl_count;
   }
   ```

   and identically for the attribute loop at `:1110-1114`. Guarding on
   `d.uri->len > 0` keeps the empty-uri case at `""` (ECMA requires that).

   Writing the minted prefix *into* the `decls` entry is what makes the rest
   work for free: `here` is what descendants receive as `ancestors`, and
   `PREFIX_OF` / the emitter already do the right thing with a concrete prefix.

   **Minimal form (recommended)**: have `mint_prefix` return `NULL` for the
   empty-prefix case rather than an interned `""`. Then the *only* behavioural
   delta versus today is the `"aaa"` branch. Returning a real `""` would also
   change `anc_contains_exact` (`:1039-1041`) results for descendants, since it
   distinguishes `NULL` from `""` — a second, unrelated behaviour change that
   the test does not ask for.

   The attribute path uses the same rule deliberately: row 9 of the test
   (`setNamespace("zoo")` on an attribute, currently passing) wants
   `<moo:bravo attr="1" xmlns="zoo">` — i.e. avmplus mints `""` for an
   *attribute* too and prints it unprefixed. One uniform helper reproduces
   both.

**Note on `"aab"`**: only the *first* mint is observable anywhere in the corpus
(`grep -rl 'aab' --include='*.as'` over all suites finds no E4X user; `xmlns:aaa`
appears only in this test). The `aaa → aab → …` odometer is an extrapolation
from a single datapoint; the alternative (always `"aaa"`, colliding on the
second mint) is untestable here. Prefer the odometer and say so in the comment.

**Risk**: low-medium. Minting is confined to `to_xml_string_inner`, does not
mutate nodes, and cannot affect `inScopeNamespaces()` / `namespaceDeclarations()`
/ `namespace()`. The outermost-first tie-break is the riskier half: it changes
prefix selection for *any* document that binds one uri to two prefixes at
different nesting levels. Canary the E4X slice (`from_avmplus/e4x/**`,
`avm2/xml*`, `avm2/e4x*`, plus the `regression` suite) before shipping.

**Verdict: READY.** Two rules, one site, ~30 lines. Lands all three rows.

---

## 2. `from_avmplus/e4x/Regress/regress-524214` — wildcard attribute WRITE

**ALREADY FIXED — no work to do.**

CI `2ab0c01be` and the run before it (`569a215e4`) both record
`status: pass`, `3/3` lines. §8.7 of the arc doc already lists it as shipped;
the brief's §7.7 reference is stale.

The write half landed in `569a215e4` ("avm2: runtime-named multinames, ns-set
trait priority, two catchable errors"), which lists `e4x/Regress/regress-524214`
in its `Fixes:` block. The site is
`SWFModernRuntime/src/avm2/avm2_xml.c:441-491` — the attribute arm of the XML
property-set path, with the rule written out at `:487-491`:

> An any-name (`x.@* = v`) can only REWRITE: ECMA-357 9.1.1.2 keeps the first
> matching attribute, deletes the rest, and assigns to it — but it never
> CREATES one, since there is no name to create. The read half of the wildcard
> rule shipped in session 5; this is the write.

The read half it refers to is the `any_name` arm at `avm2_xml.c:797-802`
(`name->local == NULL && !name->is_qname`), plus `any_name` in
`avm2_e4x_remove_matching` (`avm2_e4x.c:705`).

---

## 3. `avm2/parse_float_swf10` — SWF ≤ 10 `parseFloat` double-dot quirk

### Current diff (local run, HEAD) — **two rows, one cause**

```
    39  // parseFloat("1.2345.678")
-   40  12345.678
+   40  1.2345
    41  // parseFloat("1.2345.6e50")
-   42  12345.6
+   42  1.2345
```

### §5.5's "three causes" is wrong — corrected

§5.5 claims "two exponent-precision rows **and** the SWF≤10 quirk". That is not
what the data says. I walked `results_graphics.json` back through **20 CI runs**
on the results branch (`e4859db87` … `2ab0c01be`, spanning sessions 1-6):

```
parse_float_swf10  output_mismatch  {actual 81, expected 81, matching 79}   × 20
```

It has been **2 differing lines the whole time**, and those two lines are rows 40
and 42 — the double-dot quirk. The exponent rows (`+100e-100` → `9.999999999999998e-99`,
`-123.234E+66` → `-1.23234e+68`) have *never* differed; `f64_powi`
(`avm2_value.c:261-274`, a hand-rolled `__powidf2` clone specifically so the
1-ulp `powi` artefacts reproduce) has covered them since Stage 3.

**Relationship to session 3 batch 8 (`da8a5f5df`)**: none of `parse_float_swf10`'s
diff is shared with it. That commit touched `avm2_value.c` for **parseInt**
(`space_len_utf8` — the non-ASCII leading-whitespace set — plus the
exact-vs-chain radix split in `string_to_int`, plus the `undefined → "null"`
coercion). `space_len_utf8` *is* shared code (`skip_spaces` is called from
`avm2_string_to_f64`), but no row of this test reaches a non-ASCII space, and the
matching-line count did not move across that commit. **Nothing here was
already fixed; nothing here is blocked on parseInt work.**

### Root cause

Ruffle `core/src/avm2/value.rs::string_to_f64` (:285-461) has two passes:

* a **scanner** that validates and counts (`total_digits`, `exponent`), leaving
  `s` at the first unconsumed byte, and
* an **accumulator** that re-walks a digit string, treating `.` as "start (or
  RESTART) counting fractional digits" and breaking at the first other byte.

The version gate is `:380-385`:

```rust
// Bug compatibility: https://bugzilla.mozilla.org/show_bug.cgi?id=513018
let s = if swf_version >= 11 {
    &after_sign[..after_sign.len() - s.len()]   // only the SCANNED prefix
} else {
    after_sign                                   // the WHOLE remainder
};
```

For SWF ≤ 10 the accumulator runs past where the scanner stopped. On
`"1.2345.678"` the scanner stops at the second `.` (`total_digits = 5`), but the
accumulator consumes `1 . 2345 . 678`, and the second `.` **resets**
`decimal_digits` to 0. Result `12345678`, `decimal_digits = 3`,
`exponent = -3` → `12345.678`. On `"1.2345.6e50"` the accumulator breaks at `e`
(so the `e50` is *not* an exponent — the scanner never saw one either):
`123456 / 10 = 12345.6`.

Our `SWFModernRuntime/src/avm2/avm2_value.c:341-342` hardcodes the SWF ≥ 11 arm:

```c
	// Accumulate over the consumed span only (SWF >= 11 semantics).
	const char* span_end = p;
```

so we stop at the second `.` and yield `1.2345`. Sibling test `avm2/parse_float`
(`avm2_generated_swf_version = 38`) passes; this one is
`avm2_generated_swf_version = 10`.

### Fix design

`SWFModernRuntime/src/avm2/avm2_value.c`:

1. Thread the version in. `avm2_string_to_f64(const char*, uint32_t, bool strict,
   double*)` has no context param. `Avm2Context` already carries
   `uint8_t swf_version;  // for string_to_f64 bug compatibility`
   (`SWFModernRuntime/include/avm2/avm2_main.h:47` — the field was added for
   exactly this and has no reader yet). Ruffle uses the **root** SWF version
   (`activation.context.root_swf.version()`), which is what
   `ctx->swf_version` is (`avm2_main.c:342`, `= avm2_generated_swf_version`).
   Either add an `Avm2Context*` parameter (3 call sites:
   `avm2_value.c:616`, `avm2_globals.c:1052`, `avm2_text.c:4382`) or read the
   one global the runtime already exposes. A parameter is cleaner.

2. Replace `:341-342` with

   ```c
   	// Bug compatibility (Ruffle value.rs, bugzilla 513018): SWF <= 10
   	// accumulates over the WHOLE remainder, not just the scanned prefix, so a
   	// SECOND '.' resets the fractional-digit count instead of ending the
   	// number — parseFloat("1.2345.678") is 12345.678.
   	const char* span_end = (ctx->swf_version >= 11) ? p : end;
   ```

   Both accumulator arms (`> 15` digits, `avm2_value.c:352-370`, and the plain
   `f64` loop, `:374-391`) already break on the first byte that is neither a
   digit nor `.`, exactly like Ruffle's two loops — so this one line covers both.

**No other row of the test changes.** I hand-traced every case in `output.txt`
under the widened span: `"0000.12345GIBBERISH"`, `".2E20E1"`, `"-034.1+e20"`,
`"1   Infinity"`, `"1e4294967297"`, `"1e2147483648"`, `"9e99999"`,
`"+100e-100"` all break at the same byte the scanner stopped at, so the
accumulated digits are identical. The only inputs where the two spans differ are
those with a second `.`.

**Risk**: low, and lower still than it looks. The `strict` path (`Number()`
coercion, `avm2_value.c:616`) is unaffected: `strict` already rejects any
trailing garbage (`:339`), so `p == end` and the two spans coincide — same as
Ruffle, where the gate sits *after* the strict check. The change is inert for
SWF ≥ 11, i.e. for almost the whole corpus.

**Verdict: READY.** One cause, two rows, ~4 lines plus a parameter thread.
Correct §5.5 while you are there.

---

## 4. `avm2/issue_8630_placeremoveplace` and `..._scriptremove`

### What the SWF actually is

Both tests share one frame-0 tag stream (`RecompiledTags/tagMain.c`, identical
in both directories):

```c
tagSetInstanceName(app_context, 1, "child");   tagPlaceObject2(ctx, /*depth*/1, /*char*/1, /*placement*/1, …);
tagSetInstanceName(app_context, 2, "child2");  tagPlaceObject2(ctx, /*depth*/2, /*char*/1, /*placement*/2, …);
tagRemoveObject2(ctx, 1);
tagRemoveObject2(ctx, 2);
tagSetInstanceName(app_context, 1, "child");   tagPlaceObject2(ctx, /*depth*/1, /*char*/1, /*placement*/3, …);
tagSetInstanceName(app_context, 2, "child2");  tagPlaceObject2(ctx, /*depth*/2, /*char*/1, /*placement*/4, …);
```

i.e. **place / place / remove / remove / place / place, all inside one frame**.
Placements 1-2 have `x = 0.75`, placements 3-4 have `x = 2.75`.

The AS (`Test/Test`, the class constructor — `RecompiledABC/abc0_methods.c`
method 2) traces `child`, `child2`, identity, `.x`, `.x`; then sets both `.x = 0`;
then `removeChild(this.child)`; then

* `placeremoveplace`: `gotoAndStop(1)`
* `_scriptremove`: `gotoAndStop(2); gotoAndStop(1)`

and re-traces. §5.5 called this "a TextField-bounds × timeline interaction" —
**that is a misdiagnosis**. There is no TextField anywhere in these SWFs; the
character is `DefineSprite` id 1 linked to `ChildMovieClip`, and the traced
values are `.x`, not `.width`.

### Current diffs (local runs, HEAD)

```
issue_8630_placeremoveplace                          issue_8630_placeremoveplace_scriptremove
  stderr: AVM2 timeline: failed to queue place         stderr: (same, both depths)
          at depth 1 (already queued)
  stderr: … depth 2 (already queued)
-  7  2.75      +  7  0.75                            -  7  2.75      +  7  0.75
-  8  2.75      +  8  0.75                            -  8  2.75      +  8  0.75
   (9..15 all match)                                     (9..15 all match)
                                                      - 16  0         + 16  2.75
```

### Cause A (rows 7-8, both tests) — `QueuedTagList` is not modelled

`SWFModernRuntime/src/avm2/avm2_display.c::run_frame_internal`, **:1810-1854**.
We keep a flat array of queued place-op indices (`ext->queued_places`) and run
`AVM2_TLOP_REMOVE` **immediately**, in tag order:

```c
// QueuedTagList: one queued Add per depth — the FIRST wins
// (place_object_same_depth_frame).
int dup = 0;
for (uint32_t k = 0; k < ext->queued_place_count; k++) { … if (q->depth == op->depth …) {
        fprintf(stderr, "AVM2 timeline: failed to queue place at depth %u (already queued)\n", …);
        dup = 1; break; } }
if (!dup) ext->queued_places[ext->queued_place_count++] = (int32_t) i;
…
else if (op->kind == AVM2_TLOP_REMOVE) { run_remove_op(ctx, obj, op); }
```

Ruffle keeps a **per-depth four-state list**
(`core/src/display_object/movie_clip.rs:4845-4905`):

```rust
enum QueuedTagList { None, Add(t), Remove(t), RemoveThenAdd(t, t) }

queue_add:    None → Add(new) | Add(old) → Add(old) /*warn, first wins*/
              | Remove(r) → RemoveThenAdd(r,new) | RemoveThenAdd(r,_) → RemoveThenAdd(r,new)
queue_remove: None → Remove(new) | Add(_) → None   /*they CANCEL*/
              | Remove(_) → Remove(new) | RemoveThenAdd(r,_) → Remove(r)
```

and removes are **queued too** — drained after the whole tag stream
(`:1446`, `unqueue_filtered(|q| q.unqueue_remove())`), before the frame number
advances; adds drain later, in `enter_frame` (`:2567`,
`unqueue_filtered(|q| q.unqueue_add())`).

Feed our depth-1 sequence through Ruffle's automaton:
`Add(#1)` → `queue_remove` → **`None`** (the pair annihilates) → `Add(#3)`.
Final state `Add(#3)`, **no** remove and **no** rejection. Depth 2 likewise
ends at `Add(#4)`. Both children are therefore created from placement 3/4 →
`x = 2.75`.

We instead keep `#1`/`#2` (rejected `#3`/`#4` as duplicates) and fire two
removes against depths that hold nothing yet → `x = 0.75`.

**Two distinct bugs in one site**: (a) a queued Remove does not cancel an
earlier queued Add at that depth, and (b) the "first Add wins" rule is applied
across a Remove, where Ruffle resets to `None` first.

#### Fix design (cause A)

`SWFModernRuntime/src/avm2/avm2_display.c`, `run_frame_internal` (:1784-1862),
`flush_queued_places` (:1864-1875), and the `Avm2DisplayObjectExt` queue fields.

Replace the flat `int32_t queued_places[]` with a small per-depth table mirroring
`QueuedTagList`:

```c
typedef struct { int32_t depth; int32_t remove_op; int32_t add_op; } Avm2QueuedDepth;
/* remove_op / add_op are indices into tl->ops, or -1. The four states are
   (-1,-1) None, (-1,a) Add, (r,-1) Remove, (r,a) RemoveThenAdd. */
```

* `queue_add(depth, i)`: if the slot has `add_op >= 0` **and** `remove_op < 0`,
  keep the old one and warn (that is the real "first wins", and the existing
  `place_object_same_depth_frame` test pins it); otherwise set `add_op = i`.
* `queue_remove(depth, i)`: if `add_op >= 0` and `remove_op < 0`, reset the slot
  to `None` (drop the add, record no remove); else set `remove_op = i` and
  `add_op = -1`.
* After the op loop, drain removes in depth-slot order via the existing
  `run_remove_op` — still *before* `ext->current_frame++` (:1856), which is
  Ruffle's documented ordering ("we deliberately run all removals before the
  frame number or tag position updates").
* `flush_queued_places` drains `add_op` as it does today.

The `ext->loop_queued` reset (`run_goto`, :2532-2535, `ext->queued_place_count = 0`)
and the goto's own `queue_add` at Ruffle `:1803-1805` map onto the same table —
keep them pointed at the new structure.

**Risk**: medium. This is the AS3 per-frame display-tag pipeline, so every AVM2
timeline test runs through it. But the change is *narrowing*: today a
remove-after-place is a no-op-then-warn, and the only sequences whose behaviour
moves are ones that mix place and remove at the same depth in the same frame —
which is exactly the `already queued` stderr warning, a cheap grep-able signal.
Canary: the whole `avm2` suite's timeline slice (`issue_8630*`,
`place_object_same_depth_frame`, `goto*`, `timeline*`, `remove*`, `filter_rewind`)
plus the `regression` suite.

### Cause B (row 16, `_scriptremove` only) — no `transformed_by_script` gate

`_scriptremove` runs `gotoAndStop(2)` then `gotoAndStop(1)`. The second is a
rewind (`frame 1 <= current_frame 2`), so it takes the real `run_goto`; the
non-`scriptremove` variant's single `gotoAndStop(1)` hits
`mc_goto_frame`'s same-frame short-circuit (`avm2_display.c:2779-2788`,
`if (frame != ext->current_frame) run_goto(...) else { … }`) and never reaches
the apply path — which is why cause B shows up in only one of the two tests.

In the rewind, `child2` (depth 2) survives (`survives_rewind`, :2453-2516:
`place_frame 1 > 1` false, not `placed_by_avm2_script`), and we then do

```c
if (child != NULL && cext != NULL && is_rewind)
{
    // Rewind always modifies the surviving child in place
    apply_place_object(ctx, child, place);      /* avm2_display.c:2681-2686 */
}
```

`apply_place_object` (:1547-1596) unconditionally writes the matrix
(`apply_place_matrix`, :1495-1505). So the script's `child2.x = 0` is stomped
back to placement 4's `x = 2.75`.

Ruffle gates the whole body (`core/src/display_object.rs:2514-2516`):

```rust
fn apply_place_object(self, context, place_object: &swf::PlaceObject) {
    // PlaceObject tags only apply if this object has not been dynamically moved by AS code.
    if !self.transformed_by_script() { … matrix, color_transform, ratio,
                                           is_bitmap_cached, blend_mode,
                                           (v>=11) visible / background_color,
                                           filters … }
```

and sets the flag in **exactly six** setters (`display_object.rs`
:452, :465, :511, :553, :588, :645 — `set_x`, `set_y`, `set_rotation`,
`set_scale_x`, `set_scale_y`, `set_alpha`). Note `set_matrix` itself is *not*
one of them; `width`/`height` inherit it through `set_scale_*`.

We have **no such flag anywhere** in the AVM2 runtime
(`grep transformed_by_script SWFModernRuntime/` → nothing).

#### Fix design (cause B)

1. Add `uint8_t transformed_by_script;` to `Avm2DisplayObjectExt`.
2. Set it in the six natives in `avm2_display.c` that mirror Ruffle's six:
   `do_set_x` (:3414), `do_set_y` (:3443), `do_set_rotation` (:3729),
   `do_set_scale_x` (:3686), `do_set_scale_y` (:3704), `do_set_alpha` (:3837).
   `do_set_width` (:3819) / `do_set_height` (:3825) delegate to the scale
   setters, matching Ruffle — verify that before relying on it. Do **not** add
   `do_set_visible`, `do_set_filters`, `do_set_transform`, or `do_set_mask`:
   Ruffle does not, and widening the condition is the classic trap.
3. Guard the body of `apply_place_object` (:1547) on
   `if (!ext->transformed_by_script) { … }`. Keep `instantiate_child`'s call
   (:1634) as-is — a fresh child always has the flag clear.

**Risk**: medium-high, and the reason this half is not a clean "ready". The gate
is global to every timeline place/modify on every AVM2 clip, and there is no
`Test.as` in either test dir to reason from beyond the two graded rows. Anything
in the corpus that currently relies on the timeline *re-asserting* a placement
over a script-set property will flip. This one wants a full-`avm2` +
`from_shumway` canary, not a targeted one — or, if you want the cheap win first,
ship cause A alone: it lands `issue_8630_placeremoveplace` outright (rows 7-8
are its only diff) and takes `_scriptremove` from 13/16 to 15/16.

**Verdict**:
* `issue_8630_placeremoveplace` — **READY** (cause A only, ~35 lines).
* `issue_8630_placeremoveplace_scriptremove` — **READY, but two causes**;
  cause B is a real (if small) feature with a wide blast radius. Ship A first,
  B behind its own canary.

Also worth fixing in the same pass: the §5.5 label. Re-file this pair under
"AS3 queued display tags", not "TextField bounds".

---

## 5. `avm2/scopes_dont_cache/order-1` and `order-2` — MultinameL scope walk

**ALREADY FIXED — no work to do.** Both record `status: pass`, `1/1` lines at
CI `2ab0c01be` *and* at `569a215e4`.

`569a215e4` names them in its `Fixes:` block. Its first bullet is precisely
§5.5's diagnosis, resolved:

> `avm2_op_findproperty_dyn` dropped the MultinameL's namespace SET and searched
> public-only. The set must be tested at EACH scope level (a namespace-outer
> loop returns the wrong global); `avm2_vtable_find_mn_named` was already the
> right per-level primitive and had no caller here.

### The shared site, for the `getouterscope_two_classobjects` agent

Everything the runtime-name path needs already exists; the MultinameL
**vtable-keying** work should *reuse* it rather than build a parallel one. All
line numbers are `SWFModernRuntime/src/avm2/avm2_ops.c` unless noted.

| Layer | Static-name (`mn_idx`) | Runtime-name (MultinameL) | Note |
|---|---|---|---|
| per-vtable primitive | `avm2_vtable_find_mn` (`avm2_class.c`) | **`avm2_vtable_find_mn_named(vt, data, mn_idx, name, name_len)`** (`avm2_class.c:477-533`) | ns set from `mn->ns_set` for kinds `0x1b/0x1c`; single ns for `0x07/0x0d` (QName with the name replaced at runtime) |
| per-scope-entry predicate | `scope_defines_mn` (:2070-2085) | **`scope_defines_named`** (:2104-2133) | with-scopes fall back to a full `resolve_key` per namespace in the set; xmlish scopes to `avm2_xml_has_property_via_in` |
| chain walk | `findproperty_scope_walk_loc` (:2193-2225) | **`findproperty_scope_walk_named`** (:2135-2159) | both walk locals top→bottom then `act->outer` top→bottom |
| domain phase | `findproperty_domain_find` (:2241) | **`findproperty_domain_find_named`** (:2162-2177) | tries each ns in the set |
| kind test | — | **`mn_is_lazy_name_set`** (:2097-2101) — `kind == 0x1b \|\| 0x1c` | |
| op entry | `avm2_op_findpropstrict_ic` (:2354) | **`avm2_op_findproperty_dyn`** (:2714, dispatching to the `_named` walk at :2737) | |

The design comment at **:2087-2094** states the invariant the two fixes must
share, and is the thing to read first:

> A MultinameL carries a namespace SET but takes its local name off the operand
> stack, so none of the `mn_idx`-keyed lookups above can match it. The ONLY
> correct order is to test the whole ns set at EACH scope level, not one
> namespace across the whole chain: `scopes_dont_cache` pins exactly that — the
> set is `{outer, inner}` and the answer is the inner global purely because it
> sits higher on the scope stack.

Two further constraints the same commit established, which any new caller of
`avm2_vtable_find_mn_named` inherits:

* **Set matches take the LAST vtable hit, not the first** (`avm2_class.c:503-504,
  :527`, `entry_more_derived`). Ruffle gets most-derived-wins from
  `PropertyMap::insert` prepending (`bucket.insert(0, …)`); our vtable appends,
  so a set-matching lookup must scan to the end. Exact-key lookups are
  unchanged. (See memory `[vtable-override]` / `[avm2-builtin-vtable-override-is-not-append]`.)
* The **inline caches must not be used** on this path. `findproperty_scope_walk_loc`
  is cacheable precisely because a static `mn_idx` hit depends only on the entry
  object's class (:2182-2192); a runtime name breaks that, which is why
  `avm2_op_findproperty_dyn` calls `findproperty_scope_walk_named` directly and
  takes no `Avm2FindCache`.

`getouterscope_two_classobjects` remains `output_mismatch` (9 actual / 13
expected, 8 matching) at HEAD, consistent with §8.7: it has a second cause
(`null` vs `undefined` on line 1) on top of the `#1065` after line 9, so the
MultinameL half alone will not land it.
