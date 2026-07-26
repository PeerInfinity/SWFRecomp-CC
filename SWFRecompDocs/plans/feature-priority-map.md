# Feature-Priority Map — coverage gaps across the full Ruffle corpus

**Created**: 2026-07-24 · **Baseline**: `eabb3b366`, mode=graphics
(no-graphics identical bar two pre-existing one-test divergences).
**Purpose**: the corpus is a roadmap instrument. Rank the features we have
not implemented by how many tests each would unlock, so the map — not
intuition — decides what to build next (user direction 2026-07-23).

Regenerate the per-suite inputs with:

```bash
python3 scripts/generate_failing_by_feature.py --suite=from_avmplus
python3 scripts/generate_failing_by_feature.py --suite=avm1
python3 scripts/generate_failing_by_feature.py --suite=gnash/actionscript.all
```

## Where we stand

**Denominator correction (2026-07-24).** The 4463 figure used below the
import baseline double-counted three *nested* result directories that are
already included in their parents: `from_shumway/avm1` (47),
`from_shumway/timeline` (1) and
`from_gnash/misc-ming.all/displaylist_depths` (1) — exactly 49 tests.
`from_shumway`'s own `results_graphics.json` contains all 229 tests
including the 50 named `avm1/*`. Sum over top-level leaf suites only; do
not add nested `_results` dirs. **The `as3/Vector` arc added two more
nested dirs** to exclude — `from_avmplus/as3/Vector` (59) and
`from_avmplus/as3/Vector/nonindexproperty` (2) — so the naive sum is now
4477 against a true denominator of **4416** (up from 4414: upstream added
one `avm1` and one `avm2` test). Older figures in this document quote
4414; the two-test drift does not change any of them materially.

Full corpus, graphics mode at **`1884c6ab9`**: **3814/4416 effective
(86.4%)**, 602 failing — from CI run `30185616752`, complete over the full
4416-test intersection, so this figure needs no shard arithmetic. The mops
run improved the crash histogram (runtime_error 21 → 8, timeout 4 → 3),
the builtin-container-subclass arc held it flat, and the ByteArray +
Tamarin-PCRE arc **took timeout to 0** — all three remaining ones were the
same uint32 capacity-doubling infinite loop. segfault went 3 → 4 on
`avm2/edittext_align`, which is an intermittent crash-after-correct-output,
not a functional regression (see the arc's entry in the from_avmplus
CURRENT_STATUS).

Status histogram across the two runs of 2026-07-25, over all 4414: pass
**3452 → 3472 → 3497**, output_mismatch **696 → 676 → 651**, and
ruffle_matched (236), segfault (3), runtime_error (21), timeout (4) and
compile_fail (1) **all flat in both**, with **zero pass→fail regressions**.
Both gains are entirely inside `from_avmplus`.

| Suite | eff/total | % | failing | character of the failures |
|---|---|---|---|---|
| from_avmplus | **1508/1574** | 95.8 | 66 | **language + builtins** (Tamarin acceptance) |
| avm2 | 868/1218 | 71.3 | 350 | **platform APIs** (Loader, net, input, PixelBender, Stage3D) |
| avm1 | 655/717 | 91.4 | 62 | long tail |
| from_shumway | 172/229 | 75.1 | 57 | AVM2 half: Loader, timeline nav, fuzz corpus |
| from_gnash (5) | 371/403 | 92.1 | 32 | long tail |
| misc (9 cats) | 170/205 | 82.9 | 35 | text/fonts/mixed_avm/stage3d markers |
| regression | 70/70 | 100 | 0 | ours |

For reference, the import baseline `eabb3b366` was **871/1574** in
from_avmplus; the ranking below was originally computed from it, and the
arc yields have been updated in place as each landed.

The two big suites fail for *orthogonal* reasons, and that is the single
most useful fact in this document:

- **from_avmplus tells us which ECMAScript/AS3 builtins are missing.** It
  never touches the display list. Its failures are dense (one missing class
  blanks 150 tests) and cheap per test.
- **avm2 tells us which Flash platform APIs are missing.** Its failures are
  sparse and expensive per test (a Loader arc is weeks; it buys 31 tests).

Test-yield-per-unit-of-work is therefore *far* higher on the from_avmplus
side today, and that is where the next few arcs should go.

## How the avmplus driver amplifies a single gap

Worth internalising before reading the ranking. Every avmplus test builds
its whole assertion array eagerly at script-init time and prints as it goes:

```as3
var testcases = getTestCases();   // every Assert.expectEq() runs here
```

A single uncaught error anywhere in that build aborts the script and
suppresses **all** remaining output. So "one missing method" does not cost
one assertion — it costs the entire test, and (because Tamarin groups tests
by builtin) usually the entire directory. This is why the Date arc is worth
151 tests rather than 151 assertions.

`verify_output.py` now records `error_signature` (the first
`AVM[12] uncaught error:` line) on every result, and
`generate_failing_by_feature.py` emits a "Failing Tests by Uncaught Error"
table from it. **Read that table before re-deriving any of this by hand.**

---

## Ranked feature arcs (build X → unlock N)

Yields are tests that flip from failing to effective-pass. Known-failure
tests (Ruffle fails them too) are excluded from the yields.

### 1. ~~`Date`~~ — **DONE (`da35e5d77`, +171 + 2)** · LARGE arc · best-predicted arc in this document

| Suite | tests |
|---|---|
Exact, from the `error_signature` histogram at `17c19040c` (not estimated):

| Where | Tests | Blanking error |
|---|---|---|
| `ecma3/Date` | 153 (151 failing, 2 pass) | `getTimezoneOffset is not a function` |
| `as3/Definitions/Classes/{ClassDef/*, Ext/AccStatPropSubClassMeth}` | 14 | `getFullYear is not a function` |
| `ecma3/JSON/AS3Types` | 1 | `getFullYear` |
| `ecma3/String/e15_5_4_6_2_rt` | 1 | `getTimezoneOffset` — the test is otherwise **231/232** |
| plus 1 on `setTime` | 1 | |
| **from_avmplus total blanked on a Date method** | **171** | |
| avm2 suite `date`, `date_parse` | 2 | |

Also `ecma3/Exceptions/date_002_rt` and `date_004_rt` are ordinary
`output_mismatch` (not blanked) and may or may not fall out.

**The 18 tests outside `ecma3/Date` are the reason this arc beats its
directory count** — they were invisible until `error_signature` existed.

AVM2 `Date` is a **three-method stub** — `getTime`, `valueOf`, `toString`,
bolted on in `avm2_amf.c:1763` purely so AMF round-trips work. Everything
else (`getFullYear`, `setMonth`, `getTimezoneOffset`, the `UTC` statics,
`Date.parse`, the ES3 string formats, the 2-through-7-argument constructor)
is absent, and each missing method blanks a whole test file.

Cost is bounded and known. ECMA-262 §15.9 is fully specified; the test
determinism story is already solved (`MOCK_DATE_TIME`); and **AVM1 already
has a complete Date** — `SWFModernRuntime/src/actionmodern/date.c`, 1014
lines, 38 methods including the whole `getUTC*`/`setUTC*` family and
`getTimezoneOffset`. The arc is largely "expose that engine as an AVM2
class", plus the AS3-only surface (`Date.parse`, `Date.UTC`, the
multi-argument constructor, the AS3 accessor properties, and the
`toLocale*`/`toUTCString` formats). No display list, no rendering, no new
opcodes.

**Landed `da35e5d77`, CI `30134726316` (30/30 shards). Predicted 171 + 2;
delivered exactly 171 + 2, zero regressions.** `ecma3/Date` **2/153 →
152/153**; from_avmplus **1174 → 1345 (85.5%)**; corpus **78.6% → 82.5%**.

The 171 landed as: `ecma3/Date` 150, `as3/Definitions` 14,
`ecma3/Exceptions` 2, `ecma3/TypeConversion` 2, `ecma3/GlobalObject` 1,
`ecma3/Array` 1, `ecma3/JSON` 1. The last four were unpredicted bonuses
(tests that merely constructed a Date en route to something else), offsetting
`ecma3/String/e15_5_4_6_2_rt`, which was predicted to flip but only went
blanked → 230/232 (held back by the `[object Function]` item in Polish).

Implementation notes and the three load-bearing invariants (non-coercing
receivers, borrowed-receiver state, round-trip-pinned string formats) are in
`from_avmplus/_investigation/CURRENT_STATUS.md` §"Fix landed: the full `Date`
class". The single `ecma3/Date` holdout, `e15_9_5`, needed a typed
`Date.prototype` and landed with that arc (`e4d1e78f6`).

### 2. ~~String/Unicode semantics~~ — **DONE (`127a5f4d3`, +101)** · SMALL arc · best ratio in the corpus

**Predicted ~102, delivered 101.** `ecma3/Unicode` 6/108 → **107/108**,
zero regressions corpus-wide (CI `30126336695`). The 102nd test,
`utf8count`, is a different and much deeper problem — see below. The
diagnosis in this section was accurate in every particular and is kept
for the record.

**What did *not* flip as predicted:** `ecma3/String/esplit_002` and
`ematch_004` were listed here, but neither was blocked on these two bugs.
Both do `Number.prototype.split = String.prototype.split` — they need
arc 3, not arc 2. They pass under `d90353066`.

**`utf8count` is not adjacent-and-cheap.** It concatenates
`String.fromCharCode()` over surrogate *pairs* and compares to a UTF-8
literal. `Avm2String` is UTF-8 and cannot hold an unpaired surrogate, so
each half becomes U+FFFD and they never recombine. That needs WTF-8 or
pairing-at-concat — a representation change, and it should be scoped
separately rather than treated as String polish.

<details><summary>original diagnosis (kept — it was correct)</summary>

`ecma3/Unicode` is 102/108 failing, and **every one of those tests fails on
the same three assertions** (16/21 or 17/21 lines match, uniformly):

| Assertion | Expected | We produce | Fix |
|---|---|---|---|
| `String.search()` / `search(undefined)` | `-1` | `0` | coerce the pattern to a **string** first |
| `String.match()` / `match(undefined)` | `null` | `""` | same coercion; non-global no-match returns `null` |
| `String.split('')` | 128 elements | **256** | split by UTF-16 code unit, not UTF-8 byte |

The first two are one bug. Ruffle (`globals/string.rs::search`,
`match_internal`) does `pattern.coerce_to_string()` before constructing the
implicit RegExp, so `undefined` becomes the *pattern* `"undefined"` and
never matches. Our `pattern_to_regexp` (`avm2_regexp.c:567`) hands the raw
value to the RegExp constructor, where `undefined` yields an empty pattern
that matches at index 0.

The split bug is separate and the more interesting one:
`avm2_string_split_plain`'s empty-delimiter branch iterates `i < s->len`
— the **UTF-8 byte** length — and pushes 1-byte substrings. For
U+0080..U+00FF every character is two bytes, so we return exactly double.
The file already has the right helper (`utf16_length`, used by `substr`).
This is a real AVM2 string-indexing correctness bug, not a test artifact.

Three small fixes, ~102 tests. Nothing else in the corpus comes close on
effort-to-yield.

</details>

### 3. ~~ES3 `.prototype` surface + `Function.length`~~ — **DONE (`d90353066`, +36)** · MEDIUM

**Predicted ~35 blanked + a long tail; delivered 36, zero regressions**
(CI `30128240863`). `ecma3/String` 47/83 → **70/83**, `ecma3/Array`
43/51, `ecma3/GlobalObject` +4, `ecma3/Number` +2, `as3/Types` +2.
The whole `TypeError #1010 (accessing field: length)` cluster — 24 tests
in the previous histogram — is gone, as are the
`charAt/charCodeAt is not a function` entries.

Implementation notes worth keeping:

- The impls needed no change. Every String/Array/Number method already
  reads its receiver through a coercing `this_*()` helper, so a *foreign*
  `this` works — which is precisely what these tests do
  (`Number.prototype.split = String.prototype.split`).
- `prototype.split` must be re-pointed at the **regex-aware**
  `string_split_regex` in `avm2_regexp.c`; String registration seeds it
  with the plain one, matching how the class vtable entry is patched.
- `Function.length` was hardcoded 0 for natives (`fn_get_length` reads
  `param_count` off the ABC method, and natives have none). Added a
  `param_count` field to `Avm2MethodRef` plus
  `avm2_proto_add_function_n` / `avm2_builtin_add_global_fn_n`.
- **Take the arities from the corpus, not the spec.** ECMA-262 gives
  `String.prototype.concat.length` = 1; Flash/Ruffle give **0** (rest
  param), and the tests assert 0. `grep -rhoP '"\w+\.prototype\.\w+\.length",\s*\d+'`
  over the suite yields the ground-truth table directly.
- Ruffle omits `insertAt`/`removeAt` from `Array.prototype` — AS3-only
  additions, not ES3. Mirrored.

**Not covered by this arc, despite living in the same directories:**
`ecma3/FunctionObjects` is still 6/21, and its residue is four unrelated
small items, not one — see "Polish" below.

`String`, `Array`, `Number` and `Boolean` register **zero** prototype
functions (`grep avm2_proto_add_function` finds none in `avm2_string.c`,
`avm2_array.c`, `avm2_number.c`). In AS3 these exist as an ES3-compat layer
— Ruffle declares them in `core/src/avm2/globals/String.as` and friends.

Any test that opens with `String.prototype.substr.length` (Tamarin's
standard first assertion for a builtin) dies immediately with
`TypeError #1010`. That is ~35 blanked tests across `ecma3/String`,
`ecma3/Array`, `ecma3/FunctionObjects`, `ecma3/Boolean`,
`ecma3/ObjectObjects`, `ecma3/Number`.

Paired sub-item: **`Function.length` is always 0.** `parseInt.length`
returns 0 where 2 is expected (`ecma3/GlobalObject/e15_1_2_2_1`), and every
`X.prototype.m.length` assertion depends on it. Declared arity must be
carried on builtin function objects.

### 4. ~~`Number` static math (API 680)~~ — **DONE (`8e8370df1`, +27)** · SMALL

Predicted 21, delivered **27**: `as3/Types/Number` **3/30 → 30/30**. The
histogram counted only the 21 blanked by `TypeError #1006`; the eight
constant tests and `visibility/v16` failed on ordinary line mismatches, so
they never showed up there but fell out of the same fix. **When an arc
registers a whole API surface, treat the blanked count as a floor.**

Not an alias for `Math`, as predicted — and two further shape items the
map had not anticipated. The eight constants must be **read-only,
DontDelete and DontEnum** (`Number.E = 0` → `ReferenceError #1074`), which
`avm2_builtin_add_static_const` cannot do; they are getter-only static
traits instead. And the whole surface is **SWF16-gated** —
`as3/Types/Number/visibility/v15` asserts every member is still
`undefined` for SWF15 content, so registering them ungated would have
turned a *passing* test red.

### 5. ~~Global URI functions~~ — **DONE (`8e8370df1`, +11 + 5)** · SMALL

Predicted ~9, delivered **11 in from_avmplus and 5 in the avm2 suite**.
The four functions themselves were mechanical (ECMA-262 §15.1.3 over the
UTF-8 bytes our strings already are). The extra yield came from `escape`
and `unescape`, which turned out to belong to this arc: **`escape` encodes
by UTF-16 code unit, not UTF-8 byte** (`escape("😭")` is `%uD83D%uDE2D`),
and `unescape` has to re-pair those halves and must reject `%U`. That
fixed `ecma3/GlobalObject/e15_1_2_4` and `e15_1_2_5_1` (the latter had been
stuck at 530/531) plus the avm2 suite's `escape` and `unescape`.

`encode_uri_surrogate_pair_invalid` did **not** flip and is not part of
this arc: it needs `encodeURI` to throw on an unpaired surrogate, but
`String.fromCharCode(0xDC00)` collapses to U+FFFD before `encodeURI` sees
it. Same root cause as `utf8count` (arc 2) — it moves when the
representation does.

### 6. ~~`mops` / Alchemy domainMemory~~ — **DONE (`5da28a6a5`, +14)** · MEDIUM arc

All 13 `mops` tests were blank (the emitter's `avm2_unimplemented_op`
killed the driver's eager init); the avm2 suite's `domain_memory` test was
the same gap and landed as the 14th. CI `30179405893`, 0 regressions.
Post-mortem: `SWFRecompDocs/plans/alchemy-domain-memory-arc.md`.

### 7. ~~`flash.system.Capabilities`~~ — **DONE (`8e8370df1`, +3 + 1)** · TRIVIAL

The five blanked tests all only read `Capabilities.playerType` and branch
on it being `'AVMPlus'` (the Tamarin shell), so the class merely had to
exist and not claim to be the shell. **Three of the five flipped**;
`as3/Vector/nonindexproperty/v10` and
`as3/RuntimeErrors/Error1115NotAConstructor/v10` now *run* but fail on
their real assertions (`RangeError #1125` vs our `ReferenceError`, and
`TypeError #1115` vs `#1007`) — unblocking is not the same as passing, and
the error-signature histogram cannot tell you which you will get.

`capabilities_resolution` in the avm2 suite also passes: it needed
`screenResolutionX/Y` = viewport ÷ HiDPI scale factor, so
`verify_output.py` now passes `-DVIEWPORT_SCALE_FACTOR` alongside the
viewport dimensions it already defined.

### 8. Dual-VM movies (AVM1 ↔ AVM2 in one player) — 8 tests · LARGE arc

All 8 failing `mixed_avm` tests. A parked feature marker, not a regression
— we have no dual-VM-in-one-movie support. Large architectural cost for a
small, closed yield; the map does not recommend it now.

### 9. Stage3D / Context3D — 17 tests · LARGE arc

4 `stage3d` + 13 in the avm2 suite (`stage3d_*`, `matrix3d_*`). Also parked.
Real GPU-API surface for a small yield.

---

## Platform arcs (the avm2 suite's 362 failures)

Grouped by theme. These are the *expensive* arcs — listed so their cost is
visible next to their yield, not because they are next.

| Failing | Theme | Note |
|---|---|---|
| 31 | Loader / URLLoader / loaderInfo | + 9 more in from_shumway `as3-loader` |
| 30 | Sockets, NetConnection, NetStream, FileReference, SharedObject | network stack |
| 25 | Focus / Tab / Mouse / Keyboard input | partly reachable via `input.json` injection |
| 25 | PixelBender (`Shader`) | needs a PBJ interpreter |
| 22 | Display list / DisplayObject / Stage edge cases | closest to existing work |
| 22 | Verifier / cpool / ABC edge cases | closest to existing work |
| 13 | Stage3D / Context3D | parked (arc 9) |
| 9 | TextField / EditText / StyleSheet | |
| 8 | Security / sandbox / ApplicationDomain | |
| 8 | Filters / blend modes | |
| 7 | Text Layout Framework (`textline`, `textblock`, FTE) | |
| 5 | Sound / audio | |
| 4 | `describeType` / avmplus introspection | |
| 25 | `all_classes/*` | per-SWF-version class-existence census — these tick up incrementally as *any* class is added, so they are a free rider on every other arc |

Note `all_classes/*`: 25 tests that enumerate every class expected to exist
at a given SWF version. They are the corpus's built-in progress meter for
API surface, and no arc targets them directly.

## Polish (near-passes — bug fixes, not features)

108 from_avmplus tests were ≥90% line-matched at baseline. **60+ of those
were e4x tests missing only the root-link line and are resolved by
`d36c8da2b`** (below). The remaining polish bucket, with confirmed causes:

| Test(s) | Diff | Cause |
|---|---|---|
| `ecma3/Number/e15_7_4_2_4` | `1.2345000000000002e-7` vs `1.2345e-7` | double→string needs shortest-round-trip formatting |
| ~~`ecma3/JSON/e15_12_1`, `e15_12_3`~~ | ~~array/object parse corruption around whitespace~~ | **wrong diagnosis; both fixed** — `e15_12_1` by an earlier mechanism arc, `e15_12_3` by replacer dedup (`7ad4e0419`) |
| `as3/Definitions/Variable/ConstVariables_custom1`, `as3/RuntimeErrors/*` | `…read-only property classItem7…` vs `…property Package1:ns1::classItem7…` | error messages must use the namespace-qualified name |
| ~~`ecma3/ObjectObjects/e15_2_4_2`~~ | ~~`Object.prototype.toString` on a function~~ | **fixed by `e618f62ab`** (`[object Function-N]`) |
| ~~`ecma3/GlobalObject/e15_1_2_2_*`~~ | ~~`parseInt.length` → 0~~ | **fixed by `d90353066`** |
| `as3/Array/insertremove` | 30766/30870 lines | large-array edge cases |
| e4x residue (~20) | 10 at 50–90%, 6 below | ordinary E4X polish |

**`ecma3/FunctionObjects` — diagnosed 2026-07-24 as four unrelated items;
three of them shipped in `e618f62ab` and took the directory 6/21 → 20/21.**
The diagnosis was right that nothing here falls out of another arc, and
right that the classification item was worth more than its local count (it
also carried `ObjectObjects/e15_2_4_2`, `class_006`, `toLocaleString_rt`
and `String/e15_5_4_6_2_rt`).

| Item | Status |
|---|---|
| ~~`Object.prototype.toString` on a function → `[object Function-N]`~~ | **fixed `e618f62ab`** — note the format has a trailing `-<digits>`, which the tests regex-match; the plain text is Function.prototype's OWN toString |
| ~~`Function('function body')` must throw `EvalError #1066`~~ | **fixed `e618f62ab`** — both the call and construct forms, any argc > 0 |
| ~~Builtin **class objects** need `.length` (the ctor's arity)~~ | **fixed `e618f62ab`** — stated per class; nothing in the runtime carries builtin ctor arity |
| `Boolean.prototype` classification (`ecall_1`: `ToString.call(Boolean, Boolean.prototype)` expected `false`, got `true`) | **open** — this is the typed-builtin-prototypes arc, now #1 |

Misc-category failures (counts are *failing of total*, small and mostly
one-off): `text` 6 of 11 (caret placement ×4, HTML entity parsing, links in
scrolled text), `fonts` 3 of 6 (device-font glyph fallback, kerning, list),
`import_assets` 2 of 3, `audio` 2 of 5 (AAC, G.711 codecs), `timeline` 2 of
17, `visual` 8 of 142 (mostly image-only; `blend_modes` is a `recomp_fail`).
from_shumway's 58: 16 fuzz corpus, 9 `timeline/nav`, 9 `as3-loader`,
5 `acid`, rest scattered.

---

## Landed

**`c09985aa6` — `static const` is read-only, and `delete` can see a class
object's inherited traits.**

CI `30142225682` (graphics, `categories=full`, complete 4414-test
intersection): **+20 from_avmplus, zero regressions**, every crash bucket
flat. from_avmplus **1386 → 1406 (89.3%)**; corpus **3688 → 3708 (84.0%)**.

Predicted 10, local estimate 17, delivered 20. Two fixes in one commit:

- A `read_only` flag on `Avm2DynProp`, honoured by `setproperty_resolved`
  and `avm2_object_delete_dynamic`, gives all **91
  `avm2_builtin_add_static_const` call sites** ReadOnly + DontDelete at
  once. The C-side installer (`avm2_object_set_dynamic`) is deliberately
  **not** gated, which is what kept a change touching every builtin class
  safe: only ActionScript-level writes throw.
- `delete_trait_find` adds the class_class-ivtable fallback the resolve
  paths already had, so `delete Number.prototype` / `delete Array.prototype`
  finds the inherited `prototype` getter and returns false.

Where the 20 landed: the exact 10 `ecma3/Number/e15_7_3_*` predicted, plus
`Number/e15_7_3_1_1`, `Array/e15_4_3_1_2`, `Boolean/e15_6_3_1_2`,
`ObjectObjects/e15_2_3_1_2`, `String/e15_5_3_1_3`,
`FunctionObjects/e15_3_3_1_3`, `Types/e8_6_1` — and three nobody had
listed: `as3/Types/Int/{intMaxValue, intMinValue}` and
`ecma3/Expressions/e11_4_1`.

**`e618f62ab` — the `ecma3/FunctionObjects` arc.** `Function('body')` →
`EvalError #1066`, class-object `.length` (the ctor arity, stated for the
eleven ES3-visible classes), and the `[object Function-N]` classification.

CI `30143218958`: **+25 from_avmplus, zero regressions**, crash buckets
flat. from_avmplus **1406 → 1431 (90.9%)**; corpus **3708 → 3733 (84.6%)**.
Estimated ~15. `ecma3/FunctionObjects` **6/21 → 20/21**; the other 12 were
3 in `ObjectObjects`, 4 in `String`, plus `Number/e15_7_3`,
`Array/e15_4_3_2`, `Expressions/e11_2_1_1`, `Boolean/e15_6_3` and
`as3/RuntimeErrors/Error1066Function-body-NotAllowed`.

Ordering gotcha worth remembering: `Function.prototype.toString` had to be
registered *first* (returning `function Function() {}`, which ~19
avm2-suite tests expect from a plain `fn.toString()`) before
`Object.prototype.toString` could start reporting the classification —
we had never registered one, so `fn.toString()` was reaching
`Object.prototype.toString` by inheritance.

**`8e8370df1` — the cleanup batch (arcs 4, 5 and 7 above).**

CI `30139492178` (graphics, `categories=full`, complete 4414-test
intersection): **+41 from_avmplus, +5 avm2 = +46, zero regressions** and no
movement in `segfault` / `timeout` / `runtime_error`. from_avmplus
**1345 → 1386 (88.1%)**; corpus **3642 → 3688 (83.6%)**.

Where the 46 landed: `as3/Types/Number` **27**,
`ecma3/GlobalObject` **7**, `regress` **4**, `as3/Statements` **2**,
`as3/Vector` **1**, avm2 suite **5** (`escape`, `unescape`, `decode_uri`,
`encode_uri_surrogate_pair_swf11`, `capabilities_resolution`). The two
`as3/Statements/Exceptions` tests were unpredicted — both were catching a
`URIError` that had never existed.

**`da35e5d77` — the full `Date` class (arc 1 above).**

**`17c19040c` — guard prototype `toString`/`valueOf` against self-coercion.**

`d90353066` reused the class-method impls on the prototypes; those coerce
their receiver, and the receiver of `String.prototype.toString()` IS
`String.prototype`, so coercion re-entered the same function until the
stack died. 12 tests began crashing. **All 12 were already failing, so the
pass/fail transition diff said "zero regressions" — only the status
histogram showed it (from_avmplus segfault 2 → 14).** CI `30130444073`:
corpus segfaults **17 → 3**, runtime_error **21 → 7**, **+7**. Full
post-mortem in the suite's `CURRENT_STATUS.md`.

**`d90353066` — ES3 `.prototype` surface + `Function.length` (arc 3 above).**

CI `30128240863` (graphics, `categories=full`): **+36, zero regressions.**
`ecma3/String` 47/83 → 70/83; the `TypeError #1010 (accessing field:
length)` cluster is fully cleared. Details and the four implementation
gotchas are in arc 3 above.

**`127a5f4d3` — String/Unicode semantics (arc 2 above).**

Two independent AVM2 String bugs. (a) `search`/`match` handed the raw
argument to the implicit RegExp constructor, where `undefined` becomes the
*empty* pattern (ECMA-262 §15.10.4.1) and matches at index 0; Ruffle
coerces to a string first, making the pattern the literal `"undefined"`,
which never matches. (b) `String.split('')` iterated UTF-8 **bytes**, so
U+0080–U+00FF returned 256 elements instead of 128 and U+4E00–U+4EFA
returned 753 instead of 251; it now walks UTF-16 code units via
`utf16_unit_at`, mirroring `charAt` including the astral case.

CI-confirmed (`30126336695`, graphics, `categories=full`, full 30/30
shards): **+101 newly effective, every one in `ecma3/Unicode`
(6/108 → 107/108), and zero regressions in any suite.**

⚠️ **Shard-recovery caveat for anyone re-reading these runs.** The prior
run `30121943045` lost shard 25/30 to the apt/Vulkan flake, so 137 tests
corpus-wide (52 in from_avmplus) went unexecuted. Run `30126336695`
restored them, and a naive run-to-run diff shows those 137 as "new" — 98
of which were *already* effective. The +101 above counts only tests
present in **both** runs. Always diff on the intersection when a flaked
run is one of the endpoints.

**`d36c8da2b` — root SymbolClass must inherit Sprite, trace `TypeError #2023`.**

177 avmplus tests declare `public class Test {}` with no base class. Flash
and Ruffle fail to link such a class to the root, trace
`TypeError: Error #2023: Class Test$ must inherit from Sprite to link to the
root.`, and keep running with a plain MovieClip root. We instead constructed
the class with the stage as its sole argument, threw `ArgumentError #1063`
to stderr, and printed nothing — losing exactly one line.

**155 of the 175 failing e4x tests were missing only that line.**

CI-confirmed (`30121943045`, graphics, `categories=full`):
**+156 in from_avmplus** (155 e4x + `as3/Vector/concat`), **+4 in the avm2
suite** that were one line short of the same message (`parse_float`,
`string_concat_fromcharcode`, `string_slice_substr_substring`,
`xml_basic`), **+3 promoted to `ruffle_matched`**, and **zero regressions in
any suite**. e4x: 2/177 → **160/177**. from_avmplus: 55.3% → **65.7%**.

This also settles the E4X question: **E4X is not a coverage gap.** Our
engine passes Tamarin's XML/XMLList/QName/Namespace/TypeConversion suites
essentially in full; 2/177 was one linking bug, not missing features.

## Recommendation — the next arcs

| Order | Arc | Yield | Size | Status |
|---|---|---|---|---|
| ~~—~~ | String/Unicode: `search`/`match` coercion + `split('')` by code unit | **101** (pred. ~102) | small | **DONE `127a5f4d3`** |
| ~~—~~ | ES3 `.prototype` surface + `Function.length` | **36** (pred. ~35) | medium | **DONE `d90353066`** |
| ~~—~~ | prototype toString/valueOf self-coercion guard | **7** | tiny | **DONE `17c19040c`** — fixes a crash `d90353066` introduced |
| ~~—~~ | `Date` class (ECMA-262 §15.9) | **173** (pred. 173) | large | **DONE `da35e5d77`** |
| ~~—~~ | `Number` static math + URI functions + `Capabilities` | **46** (pred. ~35) | small | **DONE `8e8370df1`** |
| ~~—~~ | Static consts must be read-only (`#1074` + DontDelete) | **20** (pred. 10) | small | **DONE `c09985aa6`**, CI `30142225682` |
| ~~—~~ | `[object Function-N]` classification + `Function('body')` → `EvalError #1066` + class-object `.length` | **25** (pred. ~15) | small | **DONE `e618f62ab`**, CI `30143218958`; `ecma3/FunctionObjects` 6/21 → 20/21 |
| ~~—~~ | Builtin prototypes must be typed instances of their class (subsumes the old sealed-prototypes `#1037` item) | **24** (pred. 8-11) | medium | **DONE `cc4a7eece`+`e4d1e78f6`**, CI `30171938941` |
| ~~—~~ | `as3/Vector` (four independent root causes) | **15** (pred. 14) | medium | **DONE `81cf6a669`+`222b4a4b5`+`a85726a54`+`2b244c01b`**, CI `30174981516` |
| ~~—~~ | `ecma3/JSON` (four independent root causes) | **5** (pred. 4) | small | **DONE `7ad4e0419`**, CI `30176986441`; `ecma3/JSON` 8/12 → 12/12 |
| ~~—~~ | Alchemy domain memory (`li8`…`sf64` + `ApplicationDomain.domainMemory`) | **14** (pred. 13) | medium | **DONE `5da28a6a5`**, CI `30179405893`; `mops` 0/13 → 13/13 + `avm2/domain_memory` |
| ~~—~~ | Builtin-container subclasses (five independent causes) | **11** (pred. 4-6) | medium | **DONE** `20a3d24c7`+`4c6b18d5c`+`505b330f2`+`81b18da78`+`ffe48dff6`, CI `30182973510` |
| ~~—~~ | `as3/ByteArray` + `recursion/pcre_*` + `from_shumway/lzma_bytes` (five independent causes) | **11** (pred. 8–11) | medium | **DONE** `997d0c003`+`db7135ae5`+`e482c8b02`+`4cdea28fe`+`1884c6ab9`, CI `30185616752`; **timeout 3 → 0** |
| 1 | Declared-ABC method arity checking (`avm2/wrong_arg_count`, `avm2/error_geterrormessage`) | 2 | small | undiagnosed |
| 2 | avm2-platform mass: Loader (31), net/socket (30), input (25) | ~86 | large | the next real mass — see the avm2 section below |

**DONE — the `ecma3/JSON` arc.** `7ad4e0419`, CI `30176986441`: **+5**,
0 regressions, crash histogram flat. **The diagnosis this table carried
was wrong** — the arc had nothing to do with lexer whitespace, and
`e15_12_1`, the test named for it, had already been fixed by an earlier
mechanism arc. The four real causes were: `new JSON()` must throw `#2012`
and `JSON()` `#1112`; `JSON.parse`/`stringify` must report arity 2/3;
the PropertyList replacer must dedup (ES5 15.12.3 step 4.b); and cycle
detection capped nesting at 256 and reported the excess as `#1129` — a
cycle error for an acyclic structure.

The `#1112` half is the reusable piece: **calling a class object is the
coercion `C(x)` and takes exactly one argument**, so any other count is
`#1112`, not a coerce-undefined / ignore-the-extras approximation.
`avm2_call_value` now enforces that for every class without its own
`native_call`. That is what harvested
`as3/RuntimeErrors/Error1112ArgCountMismatchOnClassCoercion` for free and
fixed half of `regress/bug_420755`.

**DONE — the Alchemy domain-memory (mops) arc.** `5da28a6a5`, CI
`30179405893`: **+14** (predicted 13), 0 regressions, and the crash
histogram *improved* — runtime_error 21 → 8, timeout 4 → 3, everything
else flat. All 13 `mops/*` tests pass at full line count (`mops_basics`
was the timeout), and `avm2/domain_memory` (1/133 → 133/133) was the
14th. Domain memory IS the assigned ByteArray's buffer: every access
re-fetches `ext->bytes/len` through the object, so `set_length` reallocs
can never leave a stale pointer, and an unassigned domain uses a
persistent lazily-allocated 1024-byte zero-filled scratch. Loads
zero-extend, stores truncate, byte order is always little-endian
regardless of `ByteArray.endian`, out-of-range is `#1506`. Beyond the
corpus this unlocks Alchemy/CrossBridge-compiled SWFs. Post-mortem in
`SWFRecompDocs/plans/alchemy-domain-memory-arc.md`.

**DONE — the builtin-container-subclass arc.** `20a3d24c7` + `4c6b18d5c`
+ `505b330f2` + `81b18da78` + `ffe48dff6`, CI `30182973510`: **+11**
(predicted 4-6), 0 regressions, crash histogram flat (segfault 3 /
timeout 3 / runtime_error 8 / recomp_fail 1). All six targeted tests are
now effective passes. The "not homogeneous" warning was right — it was
**five** independent causes, not one:

1. **Object kind is not inherited.** `extends Array` allocated as
   `AVM2_OBJ_SCRIPT`, so `avm2_array_ext` returned NULL and every Array
   method saw no storage. Fixed with a per-class `instance_kind`
   resolved once at class-define time (NOT through `native_ext_size` —
   Array's is 0 by design and ByteArray already owns that mechanism).
   The same commit adds `native_super_init`, because `super(length)`
   into a builtin was a silent no-op: builtins get an `instance_init`
   stub and their real constructor lives in `native_construct`, which
   allocates and therefore cannot run on an already-allocated receiver.
2. **`delete` of a missing property on a sealed instance is `false`,**
   not the ES3 `true`. Cheapest cause, biggest overshoot: it took
   `DictionarySubclass` plus three `as3/Expressions/deleteOperator`
   tests and `avm2/indexing_delete`.
3. **The toplevel `AS3` namespace did not exist,** so `a.AS3::pop()`
   died with `#1065` before anything else could run.
4. **avmplus bug 654807 is version-gated,** and `bug_654807_swf12` vs
   `_swf13` — same source, SWF 12 and 13, opposite expectations — is
   the test *for that gate*. From SWF 13 a sealed Array subclass gets no
   element storage; below it, storage but sealed index access, so the
   dense-path methods work while the generic-loop ones throw `#1069`.
5. **Index reads did not resolve through an Array-valued prototype**
   (`D.prototype = new Array; D.prototype[1] = x`) for non-array
   receivers — the same family as `avm2-array-prototype-index-storage`,
   which had only covered array receivers.

`avm2/displayobject_early_init` was correctly excluded: its residue is
BitmapData `#2015` validation, i.e. platform work.

**DONE — the `as3/Vector` arc.** `81cf6a669` + `222b4a4b5` + `a85726a54`
+ `2b244c01b`, CI `30174981516`: **+15** from_avmplus, 0 regressions,
crash histogram flat, and corpus `compile_fail` **1 → 0**. Four
independent root causes, all as diagnosed: zero-arg `#1063` on the five
iteration methods (8); the Vector property-error taxonomy — valid-u32
read misses are `#1125` in every SWF version, sealed receivers reject
proto-chain writes with `#1056`, `delete` on a trait is `false`, and
attribute multinames report `#1081` (4); parameterized-class names built
at their true size instead of through `nb[224]`/`buf[160]` (1); and a
recompiler peephole collapsing consecutive-index literal runs into a
static table — the 250k-element literal emitted a 2M-line C function that
made gcc ICE even at `-O0` (1). The 15th was
`ecma3/String/localeCompare_rt`, from the `#1063` overshoot sweep.

Full post-mortem, including the two things the diagnosis got wrong and the
baseline-selection trap that manufactured a phantom regression:
`SWFRecompDocs/plans/as3-vector-arc.md`.

**DONE — builtin prototypes are typed instances of their class.**
`cc4a7eece` + `e4d1e78f6` + the `avm2_array_proto_index` follow-up,
CI `30171938941`: **+24** from_avmplus, 0 regressions, crash histogram
flat. Estimated 8–11, so the usual mechanism overshoot applied (four
`ecma3/Exceptions` tests and one `ecma3/Expressions` test came along).

What landed: an `is_prototype` bit keeps prototypes dynamic through class
sealing; `Array.prototype` and `Date.prototype` are real instances of
their class; Array's public `toString` trait is gone (avmplus keeps it
AS3-namespaced, so the public name stays shadowable); `Boolean.prototype`
gets receiver-guarded shims; `class_proto_to_string` classifies by actual
class; and the numeric/String/Boolean prototype methods throw `#1004` for
receivers that are neither the right primitive nor that class's own
prototype.

Two traps for anyone touching prototypes again. **Typing a prototype makes
ivtable traits shadow the ES3 prototype functions**, so
`Cls.prototype.method.length` reads the *trait's* arity — which
`avm2_builtin_add_method` left at 0, an instant regression until
`avm2_builtin_add_method_n` carried it. And **`Array.prototype[3] = x` now
lands in element storage, not a dyn prop named `"3"`**; every
hole-resolution path had to learn that (`avm2_array_proto_index`), which
cost 11 avm2-suite tests in CI `30170620108` before it was fixed.

Still open from this arc: `as3/Array/insertremove` (one test — with a
typed prototype, `insertAt`/`removeAt` shift holes in a way that disagrees
with prototype-supplied indices; it was already failing at `fc9a9bdf4`).

**Explicitly deprioritised.** `as3/RuntimeErrors` (now 13 tests, average 0%
line match) reads like a single blanked group in the histogram but is 13
*distinct* error ids with one assertion each — the worst
yield-per-unit-effort on the board. (It was 14; `e618f62ab` picked up
`Error1066Function-body-NotAllowed` for free, which is the *only* way to
harvest from this bucket: as a side effect of an arc that wants the same
error anyway.)

from_avmplus stands at **1488/1574 (94.5%)** and the corpus at
**3792/4416 (85.9%)**.

**Calibration, after two more arcs.** Both overshot the line-match table
(10 → 20, ~15 → 25), which is the mirror image of the error-histogram bias:
a fix to a *shared mechanism* — dyn-prop attributes, class-object property
lookup — drags in siblings that were failing on an ordinary line mismatch,
and no per-test table can see those. Read the line-match table as a floor
too, and expect the surplus to land in sibling directories rather than the
one you targeted. Before committing to a mechanism-shaped arc, grep the
whole corpus for the mechanism's *other users* — a one-minute pass over
`_results/results_graphics.json` plus a regex on each failing `Test.as`
found every surplus flip in both arcs before CI did.

**Calibration note after four predicted arcs.** The error-signature
histogram has now been right on `Date` (exactly 171 + 2) and *low* on this
batch (35 predicted, 46 delivered). Its systematic bias is understood:
it counts only tests killed by an uncaught error, so it **undercounts**
whenever an arc registers a whole API surface — sibling tests failing on
ordinary line mismatches come along for free. It also cannot tell
"unblocked" from "passing": two `Capabilities` tests started running and
still failed. Read it as a floor on yield and a ceiling on confidence.

**The error table has done its job and is now nearly empty.** Every result
carries `error_signature`, and `generate_failing_by_feature.py` emits a
"Failing Tests by Uncaught Error" histogram
(`from_avmplus/_investigation/FAILING_TESTS_BY_FEATURE.md`). It corrected
several estimates in this document — `Capabilities` is 5 tests, not 2, and
Date is ~166, not ~155 (finally 173, exactly as it said) — and surfaced
small items nobody had listed. As of `8e8370df1` it is down to **12 tests
across 11 distinct errors**, from ~200 at import and 44 before the cleanup
batch. **Rank the remaining work off the "Likely Fixable" line-match table
in the same document instead** — what is left is polish, not blanking, and
a histogram of uncaught errors can no longer see it.

Regression-guard every one of these with
`gh workflow run ruffle-tests.yml --ref master -f mode=graphics -f categories=full`
— they all touch shared AVM2 runtime code.
