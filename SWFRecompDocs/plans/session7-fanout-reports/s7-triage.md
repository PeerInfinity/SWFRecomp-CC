# Polish-sweep session 7 — step 0 (triage)

Snapshot: HEAD `46dcf3a06` (session-6 closeout), results from CI
`30673203712` (`graphics` / `categories=full` / `images=false`).
Working tree clean at the time of the sweep.

---

## 1. The regenerated candidate list

Rule (unchanged): the **19 top-level leaf suites** only, never the 5 nested
`_results` dirs; `status ∉ {pass, ruffle_matched}` and
`lines.expected_lines − lines.matching_lines ≤ 5`.
(`t['lines']['expected_lines']`, not `t.get('expected_lines')` — the latter
silently returns 0.)

Corpus now: **4424 tests, 4129 effective (93.3%), 295 failures.**
(4424, not 4422 — two tests entered the corpus since session 6.)

| | tr0 | s3 | s4 | s5 | s6 | **now (s7)** |
|---|---:|---:|---:|---:|---:|---:|
| candidates | 172 | 136 | 122 | 110 | 102 | **97** |
| avm2 | 82 | 67 | 55 | 50 | 48 | **45** |
| from_avmplus | 48 | 37 | 35 | 28 | 22 | **20** |
| from_shumway | 21 | 12 | 12 | 12 | 12 | **12** |
| avm1 | 9 | — | — | — | — | **9** |
| mixed_avm | 6 | — | — | — | — | **6** |
| audio / fonts / from_gnash·misc-swfc.all / text / visual | | | | | | **1 each** |

**Delta vs 102: −5.** Session 6 shipped +8 but the list only shrank by 5 —
for the **sixth** session running the window refills as fixes push
larger-gap tests into it. Ten of the 97 were **not** in the
2026-07-30 table at all:

`avm2/flash_media_video_setter`, `avm2/rtqname_not_namespace`,
`avm2/xml_list_delete_clear_parent`, `from_avmplus/e4x/Expressions/e11_1_2`,
`from_avmplus/e4x/Global/e13_1_2_1`, `from_avmplus/e4x/Statements/e12_1`,
`from_shumway/avm2/flash/geom/matrix3d/Matrix3DClass`,
`from_shumway/avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass`,
`from_shumway/hittesting/hittesting`, `visual/simple_shapes/heavy_tesselation`.

Gap histogram `0:5  1:31  2:22  3:14  4:15  5:10`.
Candidate status `output_mismatch 94`, `runtime_error 2`, `recomp_fail 1`.

**Method note worth reusing:** the whole triage table below was produced
**without running a single test** — `results_graphics.json` already carries
`expected_output` / `actual_output` (a windowed tail, prefixed
`... (N lines before) ...`) plus `error_signature` for every failure. Strip
the marker line, zip the two, and you have every first-differing line in
the corpus for the cost of one Python script. The local `--diff` sweep
(§4) was only needed to see *past* the window.

---

## 2. Clustering keys

### (a) `Counter` over `error_signature` — STILL DRY (6th session)

**13 of 97** carry a signature; largest group **2**
(`TypeError #1034 … to flash.net.URLRequest` — `avm2/loader_load` +
`avm2/loader_method`, and both belong to the uncaught-error group anyway).
Everything else is a singleton. Consistent with §6.2 / §7.2 / §8.2.

### (b) "expected Error #NNNN, got no error / got #MMMM" — 9→4 on the avmplus phrasing, 11 corpus-wide

The avmplus-harness spelling returns **4 distinct tests** (was 9 in s6, 0 in
s5, 9 in s4):

| test | wants | gets |
|---|---|---|
| `as3/RuntimeErrors/Error1052InvalidUriPassed` | #1052 | **no error** |
| `as3/RuntimeErrors/Error1081ReadSealedErrorNs` | #1081 | #1069 |
| `as3/RuntimeErrors/Error1115NotAConstructor/v10` (×3 rows) | #1115 | #1007 |
| `ecma3/Number/toLocaleString_rt` (×3 rows) | #1056 | #1037 |

Widening to the same *shape* in the avm2 suite (which doesn't use the
avmplus phrasing) adds 7 more: `activation_class` (1069/1069/1056 vs
1006/1081/nothing), `system_setclipboard_null` (2007 vs 1006), `system_exit`
(2017 vs 1006), `verify_exception_target_two_jumps` (1030 vs 1024),
`constructsuper_null` (1009 vs nothing), `method_association`
(1107/1107/1034 vs nothing), `stylesheet_transform` (1069 vs nothing).

**11 tests, 11 unrelated throwing sites.** The key refilled, exactly as
§8.6 predicted it would — but session 4 already mined the part of it that
*clustered*; what's left has no shared site. Measured, not skipped;
not proposed as a batch.

### (c) `status ∈ {runtime_error, recomp_fail, segfault, timeout}` over the WHOLE corpus — NO RISE

| status | count | tests |
|---|---:|---|
| `runtime_error` | **2** | `avm2/verify_typecheck`, `from_avmplus/regress/bug_483783` |
| `recomp_fail` | **1** | `visual/simple_shapes/heavy_tesselation` |
| `segfault` / `timeout` / `compile_fail` | **0** | — |

Identical to session 6's close. **No regressions, no new crash bucket.**
Both `runtime_error` members are already diagnosed (`verify_typecheck` =
the static type lattice, §8.7; `bug_483783` = large-string construction).
Session 6's cheapest axis is now exhausted — a 2-element self-describing
population with both members owned.

### (d) NEW mechanism axis — **the string's code-unit model at the non-ASCII boundary**

Session 5 clustered on the multiname's namespace half, session 6 on its
name half. This session's axis is a different engine structure entirely:
**what our `Avm2String` can and cannot represent, and what every
converter does at that edge.**

Session 1 diagnosed this as bucket **B5 ("4-byte UTF-8 → surrogate pair")**,
sized it at **2 tests**, and dropped it with the note *"our strings are
UTF-8 and cannot hold a lone surrogate … needs WTF-8 storage or a
pair-combining pass across every UTF-8 decoder. That is its own scoping
job, not a polish edit."* (§3 "Things that cost prediction accuracy").

**Its real population is 5, and three of the five look nothing like the
other two in diff text.** That is what the axis buys:

| test | gap | what it actually asks | why it's the same constraint |
|---|---:|---|---|
| `avm2/invalid_utf8` | 1 | `🐌` | 4-byte UTF-8 → surrogate pair |
| `avm2/stylesheet` | 1 | `😜` inside a CSS selector | same, through the StyleSheet parser |
| `from_avmplus/ecma3/Unicode/utf8count` | 1 | `"123𠮟咤ABC𠮷野屋abc南巽駅" == ` the same string built by `String.fromCharCode` of each **UTF-16 code unit** | the literal side needs astral storage, the built side needs **lone surrogates to survive and then combine** |
| `from_avmplus/ecma3/String/e15_5_4_5_4` | 2 | `String.fromCharCode(56200).charCodeAt(0) === 56200` (and 57199) | a lone surrogate must round-trip; we return 65533 |
| `from_avmplus/as3/RuntimeErrors/Error1052InvalidUriPassed` | 1 | `encodeURI(String.fromCharCode(0xDC00))` throws **#1052** | it can only throw if the lone surrogate is still there — we already have the #1052 site (`avm2_globals.c:1289`), it just never sees a surrogate |

The last two are the discovery. `Error1052InvalidUriPassed` sat in §1's
"six unrelated one-assertion causes" list and `e15_5_4_5_4`/`utf8count`
were "ecma3 singles"; all three are B5.

Four more candidates sit at the **same boundary through a different
converter** — same file neighbourhood, separately decidable:

| test | gap | converter |
|---|---:|---|
| `avm2/bom` | 5 | URLLoader must detect a **UTF-16 BOM** on loaded text (+ 1 line of URLVariables ordering) |
| `avm1/form_loader_encoding_2` | 3 | Latin-1 / Shift-JIS `loadVariables` decode (B11) |
| `avm1/form_loader_encoding_3` | 2 | same |
| `from_avmplus/e4x/Global/e13_1_2_1` | 3 | `isXMLName` non-ASCII char classes |

`e13_1_2_1` is the sharpest of these: `avm2_e4x.c:411` carries the comment
*"non-ASCII bytes count as name chars — **the corpus only exercises
ASCII**"*, and this test is precisely the counter-example (it walks
`[0x80-0xB6]`, `[0xD7]`, `[0x132-0x133]`, … asserting each is **not** a
name-start char). Note there are **two copies** of the predicate —
`avm2_e4x.c:413 avm2_e4x_is_xml_name` and `avm2_nsqname.c:130
ns_is_xml_name` (§3's "a mechanism can need fixing twice" applies).

**The axis owns 9 of 97 candidates — the largest single mechanism group on
the board, bigger than any tranche-0 bucket except B1.**

### (d′) Runner-up axis — E4X, 10 candidates

`e4x/Expressions/e11_1_2`, `e4x/Global/e13_1_2_1`, `e4x/Regress/regress-263935`,
`e4x/Statements/e12_1`, `e4x/XML/e13_4_4_17`, `e4x/XML/e13_4_4_32/v9`,
`e4x/XML/e13_4_4_36`, `from_avmplus/regress/bug_550958`,
`avm2/xml_appendchild_swf_v21`, `avm2/xml_list_delete_clear_parent`.

Sub-clusters that share a *site*, not just a subsystem, are in Batch B.

### (e) Re-priced: the uncaught-error re-land

The blocker query (`status ∈ {pass, ruffle_matched} AND error_signature
!= null AND expected_lines == 0`) was re-run per
[[avm2-uncaught-error-tracing-blocked]]'s standing instruction:

**Risk set 9; guaranteed flips still exactly 2, and both signatures are
unchanged since session 3:**

| test | signature |
|---|---|
| `avm2/away3d_advanced_shallow_water_demo` | `ReferenceError: Error #1065: Variable **ContextMenuEvent** is not defined.` |
| `visual/definefont4` | `TypeError: Error #1009 … (TLF `getEffectiveLineHeight`)` |

`grep -rn ContextMenuEvent SWFModernRuntime/` returns **zero hits** — the
away3d blocker is now a plain missing class, not a subsystem.

**But the GAIN side is stale and much bigger than the doc's "+2".** The
candidate list now holds 7–9 tests whose remaining gap *is* an uncaught
error printed to trace:

| test | gap | lines it needs |
|---|---:|---|
| `avm2/uncaught_error_basic` | 2 | `Error: hello` + `\tat Test()` |
| `avm2/loader_method` | 2 | #1034 + `\tat Test/onFrame()` (needs the coercion-frame pop) |
| `from_avmplus/ecma3/Exceptions/exception_011_rt` | 2 | `undefined` + `\tat global$init()` |
| `avm2/bitmapdata_zero_size` | 3 | #2015 + 2 native stack frames |
| `avm2/verify_illegal_opcode` | 1 | `error_signature` is **byte-identical** to the expected line |
| `avm2/verify_method_info_oob` | 1 | `VerifyError: Error #1027: Method_info 7 exceeds method_count=4.` |
| `avm2/verify_method_info_duplicate` | 2 | #1121 + a follow-on #1065 |
| `avm2/loader_load` | 4 | 2 of its 4 lines (rest is URLVariables order) |
| `avm2/system_exit` | 3 | needs #2017 implemented first |

**+4 to +7 against −2 (−1 if `ContextMenuEvent` is added first).** The
doc's "+2 / −2, net zero" price dates from session 3 and is exactly the
kind of stale pricing that file warns about. **Re-measure it; do not
price it from the doc.**

---

## 3. Already diagnosed elsewhere — excluded from this session's batches

Owned by §5.5 / §6.6 / §7.7 / §8.7 or by a named deferred bucket. Another
agent may be on these; listed so nobody re-diagnoses them.

| test | gap | owner |
|---|---:|---|
| `avm2/scope_optimizations` | 1 | §5.5 + §8.7 — static type lattice |
| `avm2/verify_typecheck` | 4 | §8.7 — static type lattice (its own arc) |
| `avm2/getouterscope_two_classobjects` | 5 | §5.5, §8.7 — two causes |
| `avm2/supercalls_weird` | 2 | §8.7 — `super` in a script init |
| `avm2/issue_8630_placeremoveplace` | 2 | §5.5 |
| `avm2/issue_8630_placeremoveplace_scriptremove` | 3 | §5.5 |
| `avm2/parse_float_swf10` | 2 | §5.5 — three causes in one test |
| `avm2/activation_class` | 3 | §7.7 — activation sealed/dynamic model |
| `avm2/system_exit` | 3 | §6.6 — the `getStackTrace()` format is the work |
| `from_avmplus/ecma3/ObjectObjects/hasOwnProperty` | 1 | §6.6 — `avm2-es3-prototype-surface` |
| `from_avmplus/ecma3/Statements/e12_10` | 1 | §6.6 — `Avm2ScopeEntry` must hold a Value |
| `from_avmplus/e4x/XML/e13_4_4_36` | 3 | §7.7 — prefix minting |
| `from_avmplus/as3/RuntimeErrors/Error1081ReadSealedErrorNs` | 1 | B6 — documented dead end (§1, reverted `0241861f4`) |
| `from_avmplus/recursion/pcre_find_fixedlength` | 1 | D-ceiling, unfixable |
| `from_shumway/fuzz/f40458686e…` | 5 | D-fuzz, low-confidence oracle |
| `avm2/stylesheet_parse_color`, `avm2/stylesheet_transform` | 4, 3 | B10 |
| `avm2/verify_exception_target_two_jumps` | 1 | B1 remainder |
| `visual/simple_shapes/heavy_tesselation` | 0 | `recomp_fail`, separate |
| **D-crossvm (11)** — `mixed_avm/*` (6), `avm1/shared_stack`, `avm1/remove_different_level`, `avm1/sandbox_type_remote`, `avm2/sandbox_type_remote`, `avm2/selection_onsetfocus_mixed_avm` | | infrastructure, not polish |

That is **30 of the 97** already spoken for.

---

## 4. Fresh local diff sweep

24 tests, 9 batched invocations, `xargs -P 4`, `--mode=graphics`,
~9 minutes wall. Raw output kept at
`scratchpad/jobs/*.txt`. No float-formatting or long-compile false
positives appeared (all 24 reproduced their CI status exactly). Findings
that the CI `_results` window had hidden:

- **`avm2/flash_media_video_setter`** — the whole diff *looked* like a
  41-line disaster; it is a **one-line shift** (`output.txt` opens with a
  blank line we never emit) plus exactly **4 real rows**, all the same
  rule: `width`/`height` must be **capped** — expected
  `v.width = 16777215 -> w=10485760.00` and
  `v.height = 10485760 -> h=7864320.00`, i.e. a clamp at scale 32768
  (`320 × 32768 = 10485760`, `240 × 32768 = 7864320`). We report the
  uncapped product. The `Test.as` header already flags a
  *"subtract-overflow inside `local_bounds()`"* on adjacent probes, so
  this is the same Twips-range issue observed from the getter side.
- **`avm2/loader_load`** — 4 diffs: **2** are URLVariables emission order,
  **2** are the uncaught-error trace. It needs both batches.
- **`avm2/bom`** — 5 diffs: **4** are UTF-16 BOM decode, **1** is
  URLVariables order.
- **`avm2/xml_list_delete_clear_parent`** — after `delete`, the removed
  node must report `parent() === undefined` and `childIndex() === -1`; we
  keep the parent link (and print the whole `<root>` subtree). The
  attribute half (`atrr.parent()`) prints empty rather than `undefined`.
- **`from_shumway/hittesting/hittesting`** — the SAME assertion string
  appears twice; the **first** occurrence fails and the second passes
  (both places). A state/ordering effect inside `getObjectsUnderPoint`,
  not a bounds value.
- **`avm2/swz` + `avm2/loader_applicationDomain`** — both load the shipped
  325 KB `framework_4.5.0.20967.swz` fixture (magic `30 83 04 f6` — an
  ASN.1/DER-wrapped signed library, not a bare SWF) and then
  `getDefinition("mx.core.ByteArrayAsset")`. Under an AOT recompiler this
  needs the SWZ container unwrapped **and** the Flex framework ABC
  recompiled — see `recompiler-giant-function-gcc-ice`. **Not polish.**
- **`from_shumway/as3-loader/bug1157243/{empty,invalid}`** — both expect a
  single `true` and produce nothing; there is no `.as` source shipped
  (prebuilt `test.swf` + `test.fla` only), so the assertion has to be
  recovered by decompiling. Low value per unit of effort.

---

## 5. Proposed batches

### Batch A — the string code-unit model (WTF-8) — **predicted +4**

| test | suite | gap |
|---|---|---:|
| `invalid_utf8` | avm2 | 1 |
| `stylesheet` | avm2 | 1 |
| `ecma3/Unicode/utf8count` | from_avmplus | 1 |
| `ecma3/String/e15_5_4_5_4` | from_avmplus | 2 |
| `as3/RuntimeErrors/Error1052InvalidUriPassed` | from_avmplus | 1 |

**Shared mechanism:** `Avm2String` is strict UTF-8, so every decoder maps
a surrogate-range code point to U+FFFD and a 4-byte sequence never becomes
a surrogate *pair*. The five tests are the five observable consequences:
astral literal round-trip (×2), lone-surrogate storage, astral-literal ==
surrogate-pair-built string, and a validator that can only fire on a
surrogate it never receives.

**Sites:** `SWFModernRuntime/src/avm2/avm2_string.c` (`fromCharCode`,
`charCodeAt`, `length`, the UTF-8 encode/decode helpers);
`avm2_globals.c:1240-1360` (`uri_encode` — add the lone-surrogate → #1052
check, the #1052 throw at :1289 already exists); the StyleSheet parser's
string path in `avm2_text.c`. The decision to make first is
**WTF-8 storage vs a pair-combining pass at each decoder** — pick one
before writing anything; the arc doc already ruled that this is the
scoping job, and this triage is the evidence that it now pays 4-5 rather
than 2.

**Risk:** highest blast radius of any batch here — every string in the
runtime. Canary with a stash-diff sweep that **includes the `regression`
suite** ([[local-regression-sweep-stash-diff]]).

**Adjacent, decide separately (not counted in the +4):** `avm2/bom`
(UTF-16 BOM detect in URLLoader, `avm2_net.c`; +1 only if the
URLVariables ordering below also lands) and `avm1/form_loader_encoding_{2,3}`
(B11, legacy charsets, avm1 runtime, +2).

### Batch B — E4X: names that carry a namespace, and detachment — **predicted +3**

| test | suite | gap | rule |
|---|---|---:|---|
| `e4x/Regress/regress-263935` | from_avmplus | 2 | `x1.none::*` (`none = new Namespace()`, uri `""`) must return **only** the no-namespace children. We return all four. |
| `e4x/Statements/e12_1` | from_avmplus | 4 | (case 4) an **attribute** is never in the default XML namespace; (cases 8/13/14) `new QName("a")` and `x[q]` must carry the default XML namespace of their construction site |
| `avm2/xml_list_delete_clear_parent` | avm2 | 5 | `delete` must **detach**: `parent() → undefined`, `childIndex() → -1`, for elements *and* attributes |
| `e4x/Global/e13_1_2_1` | from_avmplus | 3 | `isXMLName` must reject non-ASCII chars outside XML 1.0 `BaseChar`/`Ideographic`/`CombiningChar`/`Digit`/`Extender` |

**Shared mechanism (first three):** the namespace half of an E4X name is
dropped in two directions — on a *wildcard local name* with an explicit
namespace (read side), and on the *default XML namespace* when the name is
an attribute or a minted QName. This is the direct E4X continuation of
sessions 5 and 6.

**Sites:**
- `avm2_e4x.c:597` — the `handle_input_multiname` rebuild gate
  (`!explicit_ns && !n.is_attribute && n.local != NULL && !n.any_ns`);
  the `n.local != NULL` term is what excludes a wildcard.
- `avm2_e4x.c:639-643` — `avm2_e4x_matches_name`:
  `if (any_name && !name->is_qname) return 1;` — verify `is_qname` is set
  when the namespace arrives at runtime (`avm2_e4x_name_from_value:504-520`
  sets it only when `q->uri != NULL`). **Second hypothesis to rule out
  first:** the failure may be on the *write* side —
  `x1.ns1::foo = "two"` may be creating a no-namespace child, in which
  case `none::*` is correctly returning four no-namespace nodes. Instrument
  the node's stored namespace at CREATION before touching the matcher
  ([[polish-sweep-arc]] §8.6: "instrument the vtable BUILD, not the lookup").
- `avm2_e4x.c:692 avm2_e4x_remove_matching` (`node->parent = NULL` at :714
  already exists) and `avm2_xml.c:459 / :504` — the delete callers; check
  the **attribute** path and `childIndex`.
- `avm2_e4x.c:413 avm2_e4x_is_xml_name` **and** `avm2_nsqname.c:130
  ns_is_xml_name` — two copies, both carrying the "corpus only exercises
  ASCII" comment. Transcribe the XML 1.0 4th-ed. tables.

### Batch C — re-measure the uncaught-error re-land — **predicted +3 net (+4/−1)**

Apply the inverse of `ac2325c6f` (the stdout write + the parameter-coercion
frame pop; everything else already landed in `678e82e30` and must **not**
be re-derived). Before dispatching, add `flash.events.ContextMenuEvent` —
absent from the tree entirely — to remove one of the two guaranteed flips.

Expected winners: `uncaught_error_basic`, `loader_method`,
`exception_011_rt`, `verify_illegal_opcode` (+ possibly
`verify_method_info_oob`, `verify_method_info_duplicate`,
`bitmapdata_zero_size` if the stack-frame format lands).
Expected loser: `visual/definefont4` (TLF), and
`avm2/away3d_advanced_shallow_water_demo` unless `ContextMenuEvent` lands.

**Watch for the §8.5 trap:** read `OTHER STATUS MOVES` and check each
`pass → ruffle_matched` against the test's `known_failure` flag.

### Batch D — riders with a named single site — **predicted +3**

| test | gap | site / rule |
|---|---:|---|
| `avm2/system_setclipboard_null` | 1 | `System.setClipboard` does not exist (`grep setClipboard` → 0 hits); `setClipboard(null)` must throw **#2007**, we give #1006 |
| `avm2/flash_media_video_setter` | 4 | clamp `Video.width`/`height` at scale 32768 (`w ≤ 10485760`, `h ≤ 7864320`); the leading blank line of `output.txt` is a second, separate row |
| `avm2/loader_load` (2 of 4 lines) + `avm2/bom` (1 of 5) | | **URLVariables emission order is reversed** — `avm2_net.c`. Input `lastName=Jones&firstName=Tom` must re-serialize as `firstName=Tom&lastName=Jones`; `aaa=bbb&cccc=true` as `cccc=true&aaa=bbb`. Neither test passes on this alone (each needs its other cause), so treat it as an **enabler**, not a win. §1(b) already flags it as possible RUFFLE_VS_FLASH material — settle that first. |
| `avm2/instantiate_root_character` | 1 | a root character instantiated from AS must expose its timeline children (`instance.myChild` → `[object MovieClip]`, we give `null`) |

---

## 6. Predicted total

| batch | predicted |
|---|---:|
| A — string code-unit model (WTF-8) | +4 |
| B — E4X namespace-carrying names + detachment | +3 |
| C — uncaught-error re-land, re-measured | +3 net |
| D — riders | +3 |
| **total** | **+13** |

Optional stretch (own decisions, not costed): `avm1` legacy-charset decode
(+2), `avm2/bom` if both its causes land (+1).

Historical accuracy for calibration: s1 +19, s2 +21, s3 +15, s4 +16,
s5 +11, s6 +8. A +13 prediction is consistent with the trend, and Batch A
is the one that could over- or under-shoot most (it is a storage-model
change, and [[shared-mechanism-fixes-overshoot-estimates]] cuts both ways).

---

## 7. Things a session-7 implementer should not re-derive

- `error_signature` clustering is dry for the sixth consecutive session
  (13/97, max group 2). Measure it (1 minute) and move on.
- `runtime_error` is down to **2**, both owned. Session 6's cheapest axis
  is spent; it will refill only if something regresses.
- The **candidate list can be regenerated with zero test runs** —
  `results_graphics.json` carries windowed `expected_output` /
  `actual_output` per failure. Only run `--diff` for tests whose diff
  falls outside the window.
- `avm2/swz`, `avm2/loader_applicationDomain`,
  `from_shumway/as3-loader/bug1157243/*` were reached this session and are
  **not** polish (SWZ container + Flex framework recompile; and a test
  with no source shipped).
- The uncaught-error re-land's "+2/−2" price is from **session 3**. It is
  now +4…+7 / −2. Re-measure, don't re-read.
