# Polish-sweep session 8 — step 0 (triage)

Snapshot: HEAD `1c7c23761` (session-7 closeout + docs). All 19 leaf suites'
`results_graphics.json` carry `git_sha = 375373786` (CI `30679378384`,
`graphics` / `categories=full` / `images=false`) — one consistent SHA, no
frozen stems. Working tree clean.

Corpus: **4424 tests, 4153 effective (93.9%), 271 failures.**

---

## 1. The regenerated candidate list

Rule (unchanged): the **19 top-level leaf suites** only, never the 5 nested
`_results` dirs; `status ∉ {pass, ruffle_matched}` and
`lines.expected_lines − lines.matching_lines ≤ 5`.
(`t['lines']['expected_lines']`, not `t.get('expected_lines')` — the latter
silently returns 0 and produces a plausible-looking all-gap-0 list.)

Script: `scratchpad/near_pass.py`. Machine-readable output:
`scratchpad/wave1/s8-near-pass.json` (78 rows, each with suite, test, status,
gap, line counts, `error_signature`, `phases.compile`, and the windowed
expected/actual outputs).

| | tr0 | s3 | s4 | s5 | s6 | s7 | **now (s8)** |
|---|---:|---:|---:|---:|---:|---:|---:|
| candidates | 172 | 136 | 122 | 110 | 102 | 97 | **78** |
| avm2 | 82 | 67 | 55 | 50 | 48 | 45 | **32** |
| from_avmplus | 48 | 37 | 35 | 28 | 22 | 20 | **13** |
| from_shumway | 21 | 12 | 12 | 12 | 12 | 12 | **12** |
| avm1 | 9 | — | — | — | — | 9 | **9** |
| mixed_avm | 6 | — | — | — | — | 6 | **6** |
| visual | | | | | | 1 | **2** |
| audio / fonts / from_gnash·misc-swfc.all / text | | | | | | 1 each | **1 each** |

Gap histogram `0:6  1:23  2:17  3:10  4:13  5:9`.
Candidate status `output_mismatch 75`, `runtime_error 2`, `recomp_fail 1`.

### 1.1 The window finally stopped refilling — and that is the headline

Session 7 shipped **+24**; the list shrank by **19** (97 → 78).

Every prior session the window refilled by 5–10 rows as larger-gap tests were
pushed into it. **This session it refilled by exactly ONE**, and that one is
the *predicted regression* from s7's uncaught-error re-land:

| new row | gap | note |
|---|---:|---|
| `visual/definefont4` | 0 | the s7 bundle's known loser — a 0-byte-silence test now printing the TLF `#1009` the re-landed tracing surfaces. Owned by a future TLF arc. |

**Removed (20)** — 19 shipped by s7 plus one arithmetic artifact:

`avm2/activation_class`, `avm2/bitmapdata_zero_size`,
`avm2/flash_media_video_setter`, `avm2/getouterscope_two_classobjects`,
`avm2/instantiate_root_character`, `avm2/invalid_utf8`,
`avm2/issue_8630_placeremoveplace`, `avm2/loader_method`,
`avm2/parse_float_swf10`, `avm2/stylesheet`,
`avm2/system_setclipboard_null`, `avm2/uncaught_error_basic`,
`avm2/verify_illegal_opcode`,
`from_avmplus/as3/RuntimeErrors/Error1052InvalidUriPassed`,
`from_avmplus/e4x/XML/e13_4_4_36`,
`from_avmplus/ecma3/Exceptions/exception_011_rt`,
`from_avmplus/ecma3/ObjectObjects/hasOwnProperty`,
`from_avmplus/ecma3/Statements/e12_10`,
`from_avmplus/ecma3/String/e15_5_4_5_4`,
`from_avmplus/ecma3/Unicode/utf8count`.

**Gap improved but still failing (2)** — these are the *partial* wins, and
they are where the next line lives:

| test | gap s7 → s8 | remaining |
|---|---|---|
| `avm2/issue_8630_placeremoveplace_scriptremove` | 3 → **1** | the `transformed_by_script` line (OWNED elsewhere this session) |
| `avm2/loader_load` | 4 → **2** | the 2 uncaught-error lines landed; what remains is purely **URLVariables emission order** |

**Implication for pricing.** The list has been a *lower bound* on a batch's
yield in every session because a mechanism fix drags in tests outside the
≤5-line window. It is now also, for the first time, close to a genuine
inventory: the 78 rows are what is actually left near the line, and s7 did not
create a fresh crop of near-misses. Expect a session-8 yield **below** s7's
+24 unless a shared-mechanism fix reaches outside the window.

---

## 2. Clustering keys — all three cheap keys run, as required

### (a) `runtime_error` / `recomp_fail` / `segfault` / `timeout` over the WHOLE corpus — FLAT, and the population self-describes

| status | count | tests |
|---|---:|---|
| `runtime_error` | **2** | `avm2/verify_typecheck`, `from_avmplus/regress/bug_483783` |
| `recomp_fail` | **1** | `visual/simple_shapes/heavy_tesselation` |
| `segfault` / `timeout` / `compile_fail` | **0** | — |

Byte-identical to s7's close. **No regressions, no new crash bucket, no new
mechanism named by stderr.** Session 6's cheapest axis stays spent:

- `avm2/verify_typecheck` — **OWNED by the parallel type-lattice agent this
  session.** Noted, not clustered, per the brief.
- `from_avmplus/regress/bug_483783` — large-string construction; diagnosed
  and unowned, but a one-test ceiling-shaped item.
- `visual/simple_shapes/heavy_tesselation` — `recomp_fail`, tessellation, its
  own thing.

### (a2) NEW result — the uncaught-error blocker query now returns ZERO

`status ∈ {pass, ruffle_matched} AND error_signature != null AND
expected_lines == 0` over the whole corpus returns **no rows**. Session 7
landed the re-land and the risk set is gone; `visual/definefont4` already
converted from "risk" to "actual failure" and is on the candidate list. The
standing instruction in [[avm2-uncaught-error-tracing-blocked]] to re-run this
query each session can be retired — but re-run it, because it is one script.

### (b) `Counter` over `error_signature` — DRIEST IT HAS EVER BEEN (7th session)

**8 of 78** carry a signature, and the largest group is **1** — every single
one is a singleton. (s6: 15/102 max 2. s7: 13/97 max 2.) Session 3's vein is
fully mined and the corpus no longer produces repeated first-throws among
near-passes.

The 8, for the record: `#1006 computeSpectrum` (audio/g711), `#1034
→URLRequest` (loader_load), `#1035 illegal super` (supercalls_weird, owned),
`#1034 Concrete→BaseInterface` (superinterface_call — see C2 below), `#1090 XML
malformed` (bug_550958), and three flavours of `#1009` (esc,
avm2_loads_avm1_v10, definefont4).

### (c) "expected Error #NNNN, got no error / got #MMMM" — 4 avmplus-phrasing, 11 corpus-wide (UNCHANGED count, DIFFERENT membership)

The avmplus-harness spelling (`FAILED! expected: <Error> got: <Error>`, which
lives in the ACTUAL line, not the expected one — a regex on the expected side
returns 0 and is a trap):

| test | wants | gets |
|---|---|---|
| `as3/RuntimeErrors/Error1081ReadSealedErrorNs` | #1081 | #1069 (documented dead end, §1 B6) |
| `as3/RuntimeErrors/Error1115NotAConstructor/v10` (×3 rows) | #1115 | #1007 |
| `e4x/XML/e13_4_4_17` | an exception | no exception |
| `ecma3/Number/toLocaleString_rt` (×3 rows) | #1056 | #1037 |

Widened to the same *shape* in the avm2 suite (which does not use the avmplus
phrasing) adds 7:

| test | wants | gets |
|---|---|---|
| `avm2/verify_method_info_oob` | #1027 | **nothing at all** |
| `avm2/verify_method_info_duplicate` | #1121 + #1065 | **nothing at all** |
| `avm2/verify_exception_target_two_jumps` | #1030 | #1024 |
| `avm2/constructsuper_null` | #1009 | nothing |
| `avm2/method_association` | #1107 ×2, #1034 | nothing |
| `avm2/system_exit` | #2017 | #1006 |
| `from_avmplus/e4x/Global/e13_1_2_1` | #2023 | nothing (OWNED) |

Count is 11, exactly as s7 measured — but **three of the members changed, and
the three that changed now share a SITE** (the first three rows of the second
table). s7 filed all three under "uncaught-error re-land"; that re-land has
landed, so what is left is not a *tracing* gap but a *detection* gap in the
recompiler. That is cluster **C3** below and it is the payoff for re-running a
key that "returned the same number".

### (d) Engine-structure axis — E4X NAME RESOLUTION, the third leg of s5/s6

- s5 clustered on the multiname's **namespace half**.
- s6 clustered on the multiname's **name half** (runtime-named / MultinameL).
- s7 clustered on the **string code-unit model**.

This session's axis is the same structure one subsystem over: **an E4X name is
a (namespace, local-name, is-attribute) triple, and each of the three parts is
dropped somewhere.** Nothing in the diff text groups them — `1 FAILED!
expected: |<foo>one</foo>...`, `x1.@ns::['v'] FAILED! expected: 555 got: 55`,
`a.parent(): <root>`, `MYXML.replace('*',…) FAILED!` and an extra
`<a>Test</a>` look like five unrelated tests.

| part of the name dropped | tests |
|---|---|
| **namespace**, when the local name is a wildcard | `e4x/Regress/regress-263935`, `e4x/Statements/e12_1` (case 8) |
| **is-attribute**, when the local name is a runtime value | `e4x/Expressions/e11_1_2` |
| **wildcard local name** on a mutator | `e4x/XML/e13_4_4_32/v9` (`replace('*',…)`) |
| the node's **parent link**, on delete | `avm2/xml_list_delete_clear_parent` |
| a **version gate** on the same mutator family | `avm2/xml_appendchild_swf_v21` |
| **argument arity** on the same native family | `e4x/XML/e13_4_4_17` |

Seven candidates, one file family (`avm2_e4x.c` / `avm2_xml.c` /
`avm2_nsqname.c`), and two of the seven are one-liners. This is the largest
same-owner group on the board.

---

## 3. Already spoken for — excluded from this session's batches

Per the brief, owned by parallel agents this session:

| test | gap | owner |
|---|---:|---|
| `avm2/verify_typecheck` | 4 | verifier type-lattice arc |
| `avm2/rtqname_not_namespace` | 3 | verifier type-lattice arc (case 3) |
| `avm2/supercalls_weird` | 2 | class-side super chain |
| `avm2/bom` | 5 | BOM / UTF-16 / URLVariables order |
| `from_avmplus/e4x/Global/e13_1_2_1` | 3 | XML 1.0 name-char tables |
| `avm2/issue_8630_placeremoveplace_scriptremove` | 1 | `transformed_by_script` |
| `avm1/form_loader_encoding_2` | 3 | AVM1 legacy charsets |
| `avm1/form_loader_encoding_3` | 2 | AVM1 legacy charsets |
| root-class-binding riders | | (no candidate rows named) |

Owned by prior sections of `polish-sweep-arc.md` (§5.5 / §6.6 / §7.7 / §8.7 /
§9.2) or by a standing skip:

| test | gap | owner |
|---|---:|---|
| `avm2/scope_optimizations` | 1 | §9.2 — static early binding, NOT the lattice arc |
| `avm2/system_exit` | 3 | §6.6 — the `getStackTrace()` format is the work |
| `avm2/stylesheet_parse_color`, `avm2/stylesheet_transform` | 4, 3 | B10 |
| `from_avmplus/as3/RuntimeErrors/Error1081ReadSealedErrorNs` | 1 | B6 — documented dead end (reverted `0241861f4`) |
| `from_avmplus/recursion/pcre_find_fixedlength` | 1 | D-ceiling, unfixable |
| `from_shumway/fuzz/f40458686e…` | 5 | D-fuzz, low-confidence oracle |
| `avm2/swz`, `avm2/loader_applicationDomain` | 2, 4 | s7 §4 — SWZ container + Flex framework recompile, NOT polish |
| `from_shumway/as3-loader/bug1157243/{empty,invalid}` | 1, 1 | s7 §4 — no source shipped |
| `visual/definefont4` | 0 | TLF arc (s7's predicted regression) |
| `visual/simple_shapes/heavy_tesselation` | 0 | `recomp_fail`, tessellation |
| **D-crossvm (13)** — `mixed_avm/*` (6), `avm1/shared_stack`, `avm1/remove_different_level`, `avm1/sandbox_type_remote`, `avm2/sandbox_type_remote`, `avm2/selection_onsetfocus_mixed_avm`, `avm2/mouse_pick_avm1_root`, `avm1/load_cancel_via_removemovieclip` | | infrastructure, not polish |

That is **34 of the 78** already spoken for, leaving **44 takeable**.

---

## 4. Fresh local diff sweep

All 78 tests, 16 batched `verify_output.py --mode=graphics --diff` invocations
at `xargs -P 4` (the machine was at load ~8 with five other agents; the brief's
`-P 5` cap was reduced by one for that reason). ~50 min wall. Raw output in
`scratchpad/jobs/j*.txt`, per-batch summaries in `scratchpad/jobs/progress.log`.

**Result: 78 run, 0 pass, 78 fail — every candidate reproduced its CI status
exactly.** Zero stale rows, zero already-passing candidates, and **zero
false positives of either known kind** (no float-formatting mismatch, no
long-compile timeout). The long-compile risk set was checked in advance from
`phases.compile` — `visual/definefont4` 91 s, `from_shumway/esc` 71 s,
`fonts/device_font_kerning` 27.5 s, `avm2/selection_onsetfocus_mixed_avm`
27.9 s, `from_shumway/acid/acid-morph` 27.3 s,
`from_shumway/as3-loader/LoaderTest2` 26 s — and each was given its own or a
small batch, which is what kept them clean at `-P 4` on a saturated box.

Findings past the `_results` window:

- **`avm2/superinterface_call`** — the 41-line-looking failure is **one
  throw**. The first two blocks (direct call, `concrete["name"]()` string
  lookup) pass completely; the third block dies on
  `var launder: BaseInterface = concrete;` with `#1034 cannot convert
  Test.as$38::Concrete to Test.as$38.BaseInterface`. `Concrete` *directly*
  `implements BaseInterface`; the interface is script-internal
  (`Test.as$38`) and declared `extends ParentOne, ParentTwo`. One cause, five
  graded rows.
- **`avm2/subclass_superclass_linked_symbol`** — not a reorder: our actual has
  **two extra leading lines**, i.e. we run `SuperClass`'s constructor an extra
  time before `SubClass`'s. A "stop producing output" fix.
- **`avm2/doabc_and_symbolclass_script_init_normal`** — two independent order
  facts: the later DoABC script inits must run *after* the frame-1 symbol
  instance is constructed (we run them before), and among themselves the order
  is `C, Z` not `Z, C`.
- **`from_avmplus/ecma3/Statements/eforin_001`** — pure for-in order on the
  literal `{ length:4, company:"netscape", year:2000, 0:"zero" }`. avmplus
  yields `0, company, year, length`; we yield `0, year, company, length`. Note
  `length` is last in the oracle despite being declared first, so this is
  **not** plain insertion order and needs a probe before it is priced.
- **`avm1/string_relational_compare`** — the single failing row is
  `"｡" < "𐀂"` → expected `true`, we say `false`. Code-point
  (equivalently UTF-8 byte) ordering says true; UTF-16 code-unit ordering says
  false. We are comparing code units.

---

## 5. Proposed clusters, ranked by yield-per-effort

### Cluster C1 — E4X: the three parts of a name, plus two one-liners on the same natives — **predicted +4 of 7**

**Owner:** `SWFModernRuntime/src/avm2/avm2_e4x.c`, `avm2_xml.c`,
`avm2_nsqname.c` (runtime only — no recompiler rebuild needed).

| test | suite | gap | rule | confidence |
|---|---|---:|---|---|
| `e4x/Regress/regress-263935` | from_avmplus | 2 | `none = new Namespace()` (uri `""`); `x1.none::*` must return ONLY the no-namespace children. We return all four. **Site found — see C1.1.** | **very high** |
| `e4x/Expressions/e11_1_2` | from_avmplus | 3 | `x1.@ns::['v'] = '555'` — an **attribute** write with an explicit namespace and a **runtime** local name. We drop the attribute flag and CREATE an element child `<ns:v>555</ns:v>`; the second failing row (`x1.*`) is that spurious child showing up. **Site found — see C1.2.** | **very high** |
| `avm2/xml_appendchild_swf_v21` | avm2 | 1 | SWF **≥ 21** `appendChild` must detach the node from its previous parent first. **The rule is already implemented** — `avm2_xml.c:1969 maybe_escape_child` has the exact `ctx->swf_version >= 21` arm — but it reads the **global** `ctx->swf_version` (set once from `avm2_generated_swf_version`, `avm2_main.c:368`), which is the v20 root movie. The failing line is the loaded `loadable.swf`, which is v21. `Avm2MovieTables` already carries a per-movie `swf_version` (`avm2_abc.h:591`); the fix is to read the *executing* movie's. | medium (see note) |
| `e4x/XML/e13_4_4_32/v9` | from_avmplus | 1 | `MYXML.replace('*', "<phone>…</phone>")` — for the wildcard name, ECMA-357 13.4.4.32 sends the value through **ToXMLList** (so the markup parses) and returns **x**. We return the parsed list instead of `x`. | medium-high |
| `avm2/xml_list_delete_clear_parent` | avm2 | 5 | `delete` must **detach**: `parent() → undefined` and `childIndex() → -1`, for elements *and* attributes. `avm2_e4x_remove_matching` already nulls `node->parent` (`avm2_e4x.c:714`); the XMLList delete callers (`avm2_xml.c:459 / :504`) do not, and the attribute path prints empty rather than `undefined`. | medium |
| `e4x/XML/e13_4_4_17` | from_avmplus | 1 | `x1.addNamespace()` with **zero** arguments must throw. avmplus declares it with one required param → **ArgumentError #1063**. We have #1063 for script methods and for Number/Vector/String natives (`avm2_function.c:85`, `avm2_number.c:496`, `avm2_vector.c:1002`, `avm2_string.c:401`) but not for the E4X natives. | medium |
| `e4x/Statements/e12_1` | from_avmplus | 4 | **three** causes: (case 4) a method whose body contains a `default xml namespace` statement starts with DXNS `""`, not the caller's — the ABC `SETS_DXNS` method flag; (case 8) the empty-uri explicit namespace rule, **shared with regress-263935**; (cases 13/14) single-argument `new QName(name)` must capture the **default XML namespace of its construction site**. | low-medium |

**Why this is one cluster and not seven singles:** every row is the same
structure — an E4X name is `(namespace, local-name, is-attribute)` and one of
the three is being thrown away — and `e12_1` case 8 is literally the same rule
as `regress-263935`, which is what makes the two-for-one.

**Prediction:** `regress-263935`, `e11_1_2`, `xml_appendchild_swf_v21`,
`e13_4_4_32/v9` = **+4**. `xml_list_delete_clear_parent` and `e13_4_4_17` are
plausible stretch (+2). `e12_1` needs all three of its causes and is not
counted.

#### C1.1 — the empty-URI runtime Namespace is turned into "any namespace"

`SWFModernRuntime/src/avm2/avm2_ops.c:44 e4x_name_from_rtns`:

```c
Avm2NamespaceExt* n = avm2_namespace_ext_of(ns_val);
if (n != NULL && n->uri != NULL && n->uri->len > 0)   // <-- the `len > 0` is the bug
{ … name.is_qname = 1; name.single_uri = n->uri; name.single_is_real = 1; … }
if (local == NULL)
{
    // `ns::*` where the runtime namespace has an empty URI: any name,
    // any namespace (the `*` branch of avm2_e4x_name_from_string).
    name.any_ns = 1;                                   // <-- wrong for an EXPLICIT ns
    …
}
return avm2_e4x_name_from_string(ctx, local, attr);    // <-- rebuilds onto public/DXNS
```

An explicit `new Namespace()` / `new Namespace("")` is the **no-namespace**,
not "any namespace". The matcher already handles it correctly the moment the
name is built right — `avm2_e4x.c:645-652` reads
`if (self_uri == NULL) return name->single_uri->len == 0;` — so the fix is to
drop the `len > 0` test and let an empty real URI through as
`single_uri = ""`, `single_is_real = 1`.

**This is the two-for-one.** The same condition is what sends `e12_1` case 8
(`ns = new Namespace(""); x1.b.ns::c`, where `<c xmlns=""/>`) down the
`avm2_e4x_name_from_string` fall-through, which rebuilds the name onto the
**current DXNS** (`soap` at that point in the test) and therefore matches
nothing. One condition, two tests.

**Canary specific to C1.1:** the code comment names
`e4x/Expressions/e11_1_1` (`y1.@ns::*`) and `xml_explicit_use_namespace` as the
tests that pinned the current behaviour. Both must stay green — they use
NON-empty URIs, so they take the first arm either way, but verify.

#### C1.2 — the attribute flag and the any-name are passed on READ and dropped on WRITE/DELETE

Same file. `avm2_op_getproperty_rtns` (`:1837`) builds the name with

```c
act->file->data->multinames[mn_idx].name != 0 ? avm2_string_new(…) : NULL,
mn_is_attribute_kind(act->file->data, mn_idx)
```

while `setproperty_rtns_common` (`:1893`) and `deleteproperty_rtns_common`
(`:1948`) both pass `avm2_string_new(ctx, name, name_len)` unconditionally and
a hard-coded **`0`** for `attr`. So `x1.@ns::['v'] = '555'` builds a
non-attribute name and creates the element `<ns:v>555</ns:v>` that
`e11_1_2`'s second failing row then prints. `avm2_op_setproperty_rtns_l` also
does `(void) mn_idx;` and never learns the multiname is an attribute kind.

This is the identical shape to §8.4's *"the lazy-multiname arms existed for
four ops and were missing for five"* — the fix is to pass the two facts the
read path already computes.

**Second hypothesis, now ruled OUT** (carried from s7 §5 Batch B): the
`regress-263935` failure is not on the write side; `x1.ns1::foo = "two"`
stores its namespace correctly, and the read-side name construction above is
the whole cause. No creation-site instrumentation is needed.

**Canaries (content-grep, not name-grep):**
- all 169 currently-passing `from_avmplus/e4x/**` tests (177 total, 8 failing);
- the 101 `avm2/*/Test.as` files containing `XML` or `xml`;
- `regression/` in full (70 tests — [[local-regression-sweep-stash-diff]]:
  never omit it);
- `grep -rl "appendChild\|replace(\|addNamespace\|childIndex\|parent()"` over
  all suites' `.as` sources for the mutator half.

---

### Cluster C2 — high-confidence singles, each diagnosed to a named site — **predicted +4 of 5**

These are not one mechanism; they are five independent one-site fixes that
were each read down to the line this session. Ship as one batch only if they
touch disjoint files (they do).

| test | gap | site | rule | confidence |
|---|---:|---|---|---|
| `from_shumway/avm2/flash/geom/matrix3d/Matrix3DClass` | 5 | `avm2_stage3d.c:1541 matrix3d_xform` | **`appendRotation`/`prependRotation` ignore their third argument.** The `kind == 2` arm reads arg 0 (degrees) and arg 1 (axis) and never reads arg 2 (`pivotPoint`). All 5 failing rows are the pivot-dependent ones ("doesn't transform point on axis" ×2, "transform on p + {x,y,z} axis" ×3); the local sweep confirms every non-pivot row in the same two test methods already passes (`New rotation doesn't transform own axis`, `axis length is irrelevant`, `360 degrees`, `transform on {x,y,z} axis` are all `SUCCESS`). Fix: translate by `-pivot`, rotate, translate back. | **very high** (read directly off the source, confirmed by the row split) |
| `avm2/superinterface_call` | 5 | `avm2_class.c:1600 resolve_interfaces` / `:1612 avm2_class_has_interface` / `:1833` (the #1034 throw) | `var launder: BaseInterface = concrete;` throws `#1034` although `Concrete implements BaseInterface` **directly**. The walk in `avm2_class_has_interface` is already transitive and correct, so the failure is an **identity** mismatch: `resolve_interfaces` mints the interface via `avm2_class_for_mn(cls->iface_file, cls->interface_mns[i])` and the coercion target is resolved separately, producing two distinct `Avm2Class*` for one interface. The error text is the tell — it prints the value as `Test.as$38::Concrete` (colons, a namespace URI) and the target as `Test.as$38.BaseInterface` (a dot, a package-joined name), i.e. the two sides went through different key constructions for the same script-internal namespace. Instrument at the throw and print both pointers ([[polish-sweep-arc]] §4: instrument the VALUE, not the site). One throw, five rows; the direct-call and `concrete["name"]()` blocks (15 lines) already pass. | high |
| `from_avmplus/as3/RuntimeErrors/Error1115NotAConstructor/v10` | 3 | `avm2_class.c:1552` | **SWF-version gate.** `new <non-constructor>()` is `#1007` for SWF ≥ 11 and `#1115 "%1 is not a constructor."` for SWF ≤ 10. The **v11 sibling already passes** with #1007, which is the whole specification. `#1115` is already in `avm2_error.c:674` and has zero throw sites. The `%1` text is ungraded (the harness extracts only `TypeError: Error #1115`). | high |
| `avm1/string_relational_compare` | 1 | `action.c:285 u16_cmp`, reached from `action.c:30629 actionLess2` | `"｡" < "𐀂"` must be **true**. `u16_cmp` compares raw UTF-16 code units (`(int)a[i] - (int)b[i]`), so `0xFF61 > 0xD800` gives false; Flash stores AVM1 strings as UTF-8 and its byte order is **code-point** order, which gives true. The test carries no `known_failure` and has no `output.ruffle.txt`, so `output.txt` is the Flash answer and Ruffle passes it too. Fix: decode surrogate pairs (or apply the UTF-8-order remap) inside the compare. **`u16_cmp` has 8 callers** — check each before making the change global. | high |
| `avm1/native_objects_swf6` | 1 | AVM1 globals, SWF6 gate | `new TextField()` must report `non-object: undefined` at SWF6 — the global constructor must not exist. Its neighbour `new TextField.StyleSheet()` already reports `non-object: undefined` and passes; line 56 is the only failing row of 115. | high |

**Prediction: +4 of 5** (Matrix3D, superinterface_call,
Error1115NotAConstructor/v10, and one of the two avm1 rows; both avm1 rows are
one line each so +5 is realistic).

**Canaries:**
- Matrix3D: `grep -rl "appendRotation\|prependRotation" --include=*.as` returns
  20 files and **every call site uses the 2-argument form** — blast radius of
  the pivot arm is effectively zero. Still sweep `avm2/matrix3d*`,
  `avm2/geom_transform`, `avm2/utils3d`, `avm2/perspective_projection`,
  `avm2/stage3d_*`, `from_shumway/avm2/flash/geom/**`.
- `#1115`: grep the **sources** as well as the expected outputs for `1115` and
  `1007` (§3's lesson — `AccStatPropViaSubClass` hid its code in an assertion,
  not its output); sweep every `as3/RuntimeErrors/*` and every test whose
  `test.toml`/directory names a `v9`/`v10`/`v11` variant.
- interface coercion: `grep -rl "implements\|interface " --include=*.as` over
  `avm2/` and `from_avmplus/as3/Definitions/`.
- avm1 rows: `avm1/` in full plus `from_gnash/actionscript.all` (string
  comparison) — cheap suites.

---

### Cluster C3 — the recompiler's ABC **file-level** error path: detected, then dropped to stderr — **predicted +2 of 3**

**Owner:** `SWFRecomp/src/swf.cpp:6217-6231`, `SWFRecomp/src/abc/abc_parser.cpp`,
`SWFRecomp/src/abc/abc_verifier.cpp`.
**Requires `cmake --build SWFRecomp/build`** — `--recompile` alone will look
like a no-op (§3 method notes).

The shape, read straight out of `swf.cpp`:

```c
if (!abc::parseAbc(abc_data, abc_len, abc_file, abc_error))
{
    fprintf(stderr, "DoABC: parse failed: %s\n", abc_error.c_str());
}
else if (!abc::validateAbcFile(abc_file, verr))
{
    fprintf(stderr, "DoABC: validation failed: %s (%s)\n", …);
}
else { … emit … }
```

Both arms emit **nothing** — the whole DoABC tag silently disappears.
Per-*body* verify failures are different and already work: they travel to the
runtime in `bodies[bi].verify_error`, which is why `avm2/verify_illegal_opcode`
was won by s7's uncaught-error bundle while these two were not.

| test | gap | wants | today |
|---|---:|---|---|
| `avm2/verify_method_info_oob` | 1 | `VerifyError: Error #1027: Method_info 7 exceeds method_count=4.` | nothing (`abc_parser.cpp:562` throws `AbcError("method body references out-of-range method …")`, `parseAbc` returns false, stderr) |
| `avm2/verify_method_info_duplicate` | 2 | `#1121: Method Test/hello() has a duplicate method body.` then `#1065: Variable Test is not defined.` | nothing (`abc_parser.cpp:568`, whose comment already says *"FP throws error 1121 here"*) |
| `avm2/verify_exception_target_two_jumps` | 1 | `#1030: Stack depth is unbalanced. 1 != 2.` | `#1024: Stack underflow occurred.` — a per-body verify that already reaches the runtime, but merges the stack depth at a jump target wrongly. Different site, same file family. |

Both codes and message templates already exist: `#1027` at
`abc_verifier.cpp:802/950` and `avm2_error.c:593`, `#1121` at
`avm2_error.c:680`. The work is (i) give `AbcError` an error **code** + args,
(ii) make the two `swf.cpp` arms emit a file-level "throw this VerifyError as
an uncaught error at load, then continue" stub instead of returning silently.
The `#1065` follow-on in `verify_method_info_duplicate` then falls out for free
(the class never gets defined).

**Risk, and the canary that covers it:** any test whose ABC *currently* fails
to parse or validate and is silently ignored will start throwing. Before
coding, run a full recompile and grep the recompiler log for
`DoABC: parse failed` / `DoABC: validation failed`; every hit is a canary, and
if the set is larger than these two tests, gate the change on the specific
error kinds rather than on "any parse failure".

**Adjacent, NOT counted** (same "the error never happens" shape, different
sites, each its own diagnosis): `avm2/constructsuper_null` (#1009 for
`constructsuper` on a null `this`; its ABC recompiles and runs — we print
"This shouldn't be traced!" twice) and `avm2/method_association` (#1107 ×2 +
#1034, wants lazy per-call ABC validation).

---

### Cluster C4 — the ES3 prototype surface, second instalment — **predicted +1, but read the trap**

`from_avmplus/ecma3/Number/toLocaleString_rt` (gap 4) wants
`o.toLocaleString = s` on a `new Number()` to throw **#1056 "Cannot create
property"**; we throw **#1037 "Cannot assign to a method"**. `#1037` fires at
`avm2_ops.c:1087` when the setproperty lookup finds a vtable entry of kind
`AVM2_PROP_METHOD` — and `avm2_number.c:588` registers `toLocaleString` as a
**public ivtable method** as well as a prototype function (`:597`). avmplus has
it on the prototype only.

This is exactly the shape s7 fixed for `String` (§9.1: *"String's instance
methods were public-keyed instead of AS3-keyed"*, which closed
`ecma3/ObjectObjects/hasOwnProperty`). **A mechanism can need fixing twice** —
here it is a different class, and the audit worth doing once is: for each ES3
class, which instance methods are registered as public ivtable traits that
avmplus keeps prototype-only?

The test's fourth row is separate: `new Number(.00000012345).toLocaleString()`
must print `1.2345e-7` (the shortest round-trip) and we print
`1.2345000000000002e-7`. It **may** fall out of the same change (the call would
then route to the prototype's formatter rather than `number_to_string`) — verify,
do not assume. Both rows are needed for the flip, so this is +1 or +0.

**Canary:** every `from_avmplus/ecma3/Number/**` and `ecma3/String/**` test, plus
content-grep for `toLocaleString`, `propertyIsEnumerable`, `hasOwnProperty`
across all suites.

---

### Cluster C5 — diagnosed, sized, deliberately NOT proposed

| test(s) | gap | why not |
|---|---:|---|
| `avm2/sound_rootless`, `avm2/sound_constructor_with_args` | 2, 4 | Both need `Event.SOUND_COMPLETE`, and `avm2_media.c:583`'s own comment says it is *"trace-inert by construction"* in the trace harness — nothing drains a mixer channel because there is no sink. Winning them means a **virtual audio clock** that retires a channel after its duration in ticks. Real feature, not polish. `sound_constructor_with_args` additionally needs `new Sound(URLRequest)` to auto-load and dispatch OPEN/PROGRESS/COMPLETE. |
| `from_shumway/avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 4 | Four causes, and one of them is an oracle conflict: `avm2_display.c:9650`'s comment says we deliberately mirror **Ruffle** (`fov 55, centre (250,250)`, an `(double)(float)` cast kept "because Ruffle computes this half in f32"), while this test grades **Flash** — which wants full f64 (`480.2455317428` vs our `480.2455444336`), `projectionCenter` = stage centre `(250, 187.5)` not `(250, 250)`, a `focalLength` write that persists, and `perspectiveProjection` returning a clone. Settle the oracle question first; it is RUFFLE_VS_FLASH material as much as a bug. |
| `from_avmplus/ecma3/Statements/eforin_001` | 4 | for-in order on `{length:4, company:…, year:…, 0:…}`. Oracle order is `0, company, year, length`; ours is `0, year, company, length`. `length` being LAST in the oracle despite being declared first means this is not plain insertion order — needs a probe SWF before it can be priced. |
| `avm2/doabc_and_symbolclass_script_init_normal` | 5 | Two ordering facts (later DoABC script inits must run after the frame-1 symbol construction; and `C` before `Z`). §1(a) "misordered actual" family — a fix here reorders output and can silently regress a neighbour. |
| `avm2/subclass_superclass_linked_symbol` | 4 | We run `SuperClass`'s constructor an **extra** time; a "stop producing output" fix, which no added behaviour reaches. |
| `avm2/graphic_linkage` | 2 | A Graphic-linked symbol constructed as a timeline child must read `width == 0` in its constructor; we read `40.35`. Construction-order × bounds. |
| `avm2/bitmapdata_draw_alpha_erase` | 2 | `BitmapData.draw` with ALPHA/ERASE blend modes. Two rows, likely two blend formulas. |
| `from_shumway/hittesting/hittesting` | 2 | The **same** assertion string appears twice; the first occurrence fails and the second passes, in both places. A state/ordering effect inside `getObjectsUnderPoint`, not a bounds value. |
| `avm1/geturl` | 3 | The harness's getURL report prints URL/Target/Method but no `Param:` rows — needs the POST body decomposed plus the synthetic `$version=LNX 32,0,0,0`. |
| `from_shumway/as3-loader/LoaderTest2`, `LoaderLoadBytesTest` | 1, 3 | `loadBytes` child-SWF symbol visibility. Loader infrastructure. |
| `fonts/device_font_kerning` | 4 | `LM width: 50` vs `23` — device-font advance metrics. |
| `from_shumway/acid/acid-morph` | 2 | Six booleans, positions 3–4 disagree; morph-shape hit/bounds state. |
| `from_shumway/bitmapdata/getpixel-from-embedded` | 1 | `200d04` vs `220a06` — embedded-JPEG chroma upsampling differs from Flash's decoder. Decoder-parity, see [[decoder-tolerance-read-the-oracle]]. |
| `from_avmplus/regress/bug_550958` | 1 | `#1090 XML parser failure: element is malformed` on a mixed-case document. XML parser, one row. |
| `from_gnash/misc-swfc.all/sound` | 0 | Harness self-report `FAILED: TOTAL tests run: 1, expected: 2` — one sub-assertion never runs. Extra-output class. |
| `avm2/cross_api_version_call_newer` | 1 | `Event = undefined` expected, we give `workerState` — an api-version-gated definition leak. Single line, plausible one-liner, but no site identified yet. |
| `avm2/netstream_flv_date` | 2 | `onMetaData` never runs for an FLV with a date field. |
| `text/links_in_scrolled_text` | 1 | Single `Success!`; needs the link hit-test inside a scrolled TextField. |
| `audio/g711` | 4 | `#1006 computeSpectrum is not a function` blocks it before the A-law/µ-law rows. |
| `from_shumway/esc` | 2 | A Scheme compiler in AS3; dies on `#1009` deep in `Util::Hashtable/makeTable()`. Chain of blockers. |

---

## 6. Predicted total

| cluster | predicted |
|---|---:|
| C1 — E4X name resolution (+ two natives one-liners) | **+4** (stretch +6) |
| C2 — high-confidence singles with a named site | **+4** (stretch +5) |
| C3 — recompiler ABC file-level error path | **+2** |
| C4 — ES3 prototype surface (Number) | **+1** |
| **total** | **+11** (stretch +14) |

Historical accuracy for calibration: s1 +19, s2 +21, s3 +15, s4 +16, s5 +11,
s6 +8, s7 +24 (a seven-agent fan-out). A single-wave +11 is consistent with the
trend once the +24 outlier is read as a headcount effect rather than a density
one.

**The one prediction risk worth stating.** Every prior session's overshoot came
from a shared-mechanism fix carrying tests **outside** the ≤5-line window. None
of C1–C4 is shared in that way — an E4X name rule reaches exactly the E4X tests,
a pivot argument reaches exactly the 3-argument callers, a version gate reaches
exactly the version. Per §5.3's rule (*a name-keyed cluster prices exactly, a
behaviour-keyed one overshoots*), expect these to land **on** prediction rather
than over it. The single place an overshoot could come from is C3, if the
file-level error path turns out to be swallowing more ABCs than the two tests
that grade it — which is exactly what its canary measures.

---

## 7. Things a session-8 implementer should not re-derive

- **`error_signature` clustering is dry for the seventh consecutive session**
  (8/78, max group **1** — every one a singleton). Measure it (one minute) and
  move on.
- **`runtime_error` is 2, `recomp_fail` is 1, and both `runtime_error` members
  are owned.** Session 6's cheapest axis stays spent. It refills only on a
  regression.
- **The uncaught-error blocker query now returns ZERO.** That standing
  worklist item is closed; `visual/definefont4` is its residue and belongs to a
  TLF arc.
- **Key (c) returns 11 again but three members MOVED** — the three `verify_*`
  rows are no longer a tracing gap (that shipped) but a recompiler detection
  gap. Re-running a key that returns the same *number* still pays.
- **The near-pass window refilled by exactly one row this session** (vs 5–10 in
  every prior session), and that row is s7's predicted regression. The list is
  now closer to a true inventory than a lower bound.
- **The avmplus `expected: … got: …` phrasing lives in the ACTUAL line.** A
  regex over `expected_output` returns 0 hits and looks like a dry key.
- **`avm2/swz`, `avm2/loader_applicationDomain`,
  `from_shumway/as3-loader/bug1157243/*`** were re-checked and remain not-polish
  (SWZ container + Flex framework recompile; no source shipped).
- **A recompiler change needs `cmake --build SWFRecomp/build`** —
  `--recompile` regenerates RecompiledScripts but not the recompiler binary
  (C3 is the only cluster this bites).
- **The full 78-test local sweep found NOTHING the `_results` JSON did not
  already carry**, other than confirming statuses. `results_graphics.json`'s
  windowed `expected_output` / `actual_output` covered 74 of the 78 diffs in
  full; only `superinterface_call`, `e13_1_2_1`, `esc` and `definefont4` needed
  the local run to see past the window. If the next session is time-boxed, run
  `--diff` only for candidates whose `actual_lines` exceed the window (~51
  lines) — the rest is a Python script (s7 §1's method note, re-confirmed).

---

## 8. Files

| path | what |
|---|---|
| `scratchpad/near_pass.py` | the regeneration script (19 leaf suites, nested schema, corpus totals) |
| `scratchpad/wave1/s8-near-pass.json` | **78 candidates**, machine-readable: suite, test, status, gap, expected/matching/actual line counts, `error_signature`, `phases.compile`, windowed expected & actual output |
| `scratchpad/wave1/first-diff-lines.txt` | every candidate's differing lines, generated from the JSON with zero test runs |
| `scratchpad/jobs/j01..j16.txt` | the local `--mode=graphics --diff` sweep output |
| `scratchpad/s7-near-pass.json` | session 7's list, reconstructed from `git show 46dcf3a06:` for the delta in §1 |
