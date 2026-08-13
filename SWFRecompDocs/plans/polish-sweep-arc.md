# Near-Pass Polish Sweep Arc

Created 2026-07-30. Ranked #1 by `feature-priority-map.md` §"Re-rank
2026-07-30": **172 of the 422 remaining corpus failures (41%) are
near-passes missing ≤5 expected lines.** The board's head is polish
*density*, not a mechanism, so this arc is a triage-then-batch sweep
rather than a feature build.

Baseline: `9277e0e1b` / CI `30519577386` — corpus **3999/4421 effective
(90.5%)**, histogram `runtime_error 7`, `recomp_fail 1`, no segfault /
timeout / compile_fail bucket.

## 0. Tranche 0 method (mechanized)

Candidate regeneration (`scratchpad/near_pass.py`):

- Read `results_graphics.json` from the **19 top-level leaf suites**
  only — `avm1`, `avm2`, `from_avmplus`, `from_shumway`, the five
  `from_gnash/*`, `regression`, and the nine misc categories. The five
  *nested* `_results` dirs (`from_avmplus/as3/Vector`,
  `.../Vector/nonindexproperty`, `from_gnash/misc-ming.all/displaylist_depths`,
  `from_shumway/avm1`, `from_shumway/timeline`) are already inside their
  parents — including them double-counts tests
  (`corpus-denominator-double-counts-nested`).
- Keep every test whose `status ∉ {pass, ruffle_matched}` and
  `expected_lines - matching_lines ≤ 5`.

Result: **exactly 172 candidates**, matching the re-rank's count.

| suite | candidates |
|---|---|
| avm2 | 82 |
| from_avmplus | 48 |
| from_shumway | 21 |
| avm1 | 9 |
| mixed_avm | 6 |
| visual | 2 |
| audio / fonts / text / from_gnash misc-swfc.all | 1 each |

Gap histogram: `0:4  1:68  2:47  3:22  4:18  5:13`.
Status: `output_mismatch 168`, `runtime_error 4`.

Diffs were collected by batched local runs into `scratchpad/jobs/*.txt`.
**Sizing note for a future session:** the first attempt ran one
invocation per suite sequentially and cost ~10 min for 9 tests. Separate
`/tmp/swf_verify_*` working dirs mean *parallel* invocations are safe, so
the sweep was re-shaped into **28 eight-test batches at `-P 5`** and the
whole 172-test corpus triaged in ~12 minutes. Always pin `--tests-dir`
per suite and never run a suite without `--test` filters.

### 0.1 Ignore-listed tests still count — hard vs soft on the trace axis ★★

**Added 2026-08-12 (session 14 wave-1 board audit §2.2).** Every wave-1 audit
from s12 on — including s14's own first regeneration — reported the near-pass
window as "N rows, of which M are ignore-listed", implying the flagged rows were
out of play. **They are not.** `verify_output.py:3514` computes
`effective_pass = pass + ruffle_matched` with **no ignore filtering anywhere**,
and both ignore files say so in their own headers: *"the headline corpus figure
is the UNFILTERED effective_pass, and ignored tests are run and counted there
either way. It only fixes the filtered report."* An ignore-listed near-pass is
worth exactly the same **+1 effective** as any other row if it is winnable; at
s14 that was 16 of the 35 rows at gap ≤ 5.

So the trace axis now uses **the pixel axis's hard/soft split** (the same rule
`scripts/image_triage.py` applies to image dispositions):

- **HARD** = backed by an entry in a disposition doc (`ACCEPTED_DIFFS.md`,
  `RUFFLE_VS_FLASH_DIFFERENCES.md`) that explains why the diff is permanent.
  Unwinnable; drop it from the board.
- **SOFT** = a suite-local `ignored_tests.txt` entry with no doc backing. Still
  a **candidate** — it only affects the *filtered* report. The suite-local lists
  were seeded mechanically from directory-name prefixes before any AVM2
  implementation existed (see the `avm2/ignored_tests.txt` header), which is
  precisely the provenance that made the pixel axis introduce the split.

When a board is regenerated, resolve each flag against the disposition docs
before writing it off, and state which of the two it is. A soft flag is a
bookkeeping fact about the filtered report, not a ruling about the test.

## 1. Triage table (bucketed by CAUSE)

Ranked by yield-per-effort. "Lines" = expected−matching summed over
members.

### Ranked, takeable

| # | Bucket | Owner | Tests | Lines | Example diff |
|---|---|---|---|---|---|
| B1 | **avmplus-format VerifyError messages** — the verifier already *detects* every one of these and already carries the right `Error #NNNN` code in `fail(err, code, …)`; only the message TEXT is our own generic prose, so the tests' `e.toString()` / `e.errorID` assertions miss | recompiler (`abc_verifier.cpp`) | 9 | 18 | `verify_stack`: exp `VerifyError: Error #1023: Stack overflow occurred.` / act `VerifyError: stack overflow at op 1 (depth 2 > max_stack 1)` |
| B2 | **`Math` is neither callable nor constructible** — `Math()` must throw TypeError #1075, `new Math()` #1076. We treat Math as an ordinary builtin class, so `Math()` takes the one-arg coercion path (#1112) and `new Math()` succeeds | avm2 runtime (`avm2_number.c`) | 6 | 6 | `ecma3/Exceptions/expression_005_rt`: exp `threw TypeError: Error #1076: Math is not a constructor` / act `[object Math]` |
| B3 | **`from_shumway/timeline/nav` — PlaceObject state not AS-visible / not reset on backward nav.** Two sub-causes, same family: (a) tag-set properties never reach the AS property (`cacheAsBitmap`, `colorTransform`, `blendMode`); (b) backward navigation must *re-create* the character rather than reuse it (`matrix`, `morphShape`, `ratio`, `ratio2`). **Do not implement (b) as a blanket rule:** `ratio` expects `New object placed on frame 1: true` while `ratio2` expects `false` on the same shape of test, so the recreate decision is a precise per-field comparison, not "backward nav always recreates" | avm1+avm2 timeline / display list | 8 (+2 riders `blendmode/blendmode_1`, `blendmode_2`) | 12 (+3) | `timeline/nav/colorTransform`: exp `redMultiplier=0` / act `redMultiplier=1`; `timeline/nav/blendMode`: exp `Blend mode: invert` / act `normal` |
| B4 | **hit-testing and interactive bounds** — button/shape-level hit tests and the bounds they derive from | avm2 runtime + bounds engine | 8 | 13 | `displayobject_hittestpoint` lines 35/47: exp `false` / act `true`; `button_bounds`: exp `(x=188.8,…)` / act `(x=0,y=0,w=0,h=0)` |
| B5 | **4-byte UTF-8 → surrogate pair** — our decoder rejects astral-plane sequences and emits replacement chars | avm2 runtime string decode | 2 | 2 | `invalid_utf8`: exp `🐌` / act `������`; `stylesheet`: exp `😜` / act `��` |
| B6 | **#1081 vs #1069 on a sealed read** — avmplus routes `isAttr() \|\| !containsAnyPublicNamespace()` to #1081; `getproperty_common` only has `dynamic \|\| mn_attr`, so a non-public multiname off a *sealed* receiver wrongly gets #1069 | avm2 runtime (`avm2_ops.c:561`) | 2 | 3 | `as3/RuntimeErrors/Error1081ReadSealedErrorNs`: exp `#1081` / act `#1069` |
| B7 | **`Function.prototype.apply`/`call` arity** — `.length` is 2 and 1, we report 0 | avm2 runtime | 2 | 2 | `ecma3/Function/e15_3_4_3_1`: exp `2` / act `0` |
| B8 | **e4x `processingInstructions('@name')`** — an `@`-prefixed argument matches no PI and must yield the empty list | avm2 runtime (`avm2_e4x.c`) | 2 | 2 | `e4x/XML/e13_4_4_28`: exp `` (empty) / act `<?xml-stylesheet href='mystyle.xsl'?>` |
| B9 | **namespace-qualified property names in error messages** (the map's long-standing polish row, still live) — #1074/#1069 must print `Package1:ns1::classItem7`, and definition-name dumps must print `p1::Same` | avm2 runtime | 2 | 3 | `as3/Definitions/Variable/ConstVariables_custom1`: exp `read-only property Package1:ns1::classItem7` / act `… property classItem7` |
| B10 | **CSS `StyleSheet` colour + transform parsing** — `#rrggbb` parses to 0; a few `transform` rows disagree | avm2 runtime (`avm2_text.c`) | 2 | 7 | `stylesheet_parse_color`: exp `parsed color: ff0000` / act `parsed color: 0` |
| B11 | **avm1 charset decoding for `loadVariables`** — Latin-1 and Shift-JIS payloads decode wrong (`System.useCodepage` family) | avm1 runtime | 2 | 5 | `form_loader_encoding_3`: exp `Shift Jis: 片仮名` / act `Շɼּ` |
| B12 | **private-member access must throw** — `super.privateMethod()` → #1070, cross-class private var read → #1069; we silently succeed | avm2 runtime | 2 | 2 | `as3/Definitions/Super/SuperRuntimeError`: exp `PASSED!` / act `FAILED! expected: ReferenceError: Error #1070 got: no exception thrown` |

### Deferred with a diagnosed cause (not taken this arc)

| Bucket | Owner | Tests | Why not now |
|---|---|---|---|
| **Uncaught-error tracing re-land** (`3b401b5f9`, reverted `d1c307c51`) | avm2 runtime, 34 lines | 4 (`uncaught_error_basic`, `loader_method`, `loader_load` tail, `bitmapdata_zero_size`) + `avm2/verify_illegal_opcode`, `verify_method_info_oob`, `verify_method_info_duplicate` | The revert message names the tripwire census. Its Stage3D/ShaderJob half is now closed by the shader arc, but `BlurFilter`, `ColorMatrixFilter`, `PNGEncoderOptions`, `BitmapDataChannel`, `GraphicsBitmapFill`, `CapsStyle`, `BreakOpportunity`, `drawRoundRectComplex`, `lineBitmapStyle` are **all still absent** from the tree — the filter half belongs to the **filters arc**. Re-land it as that arc's closeout, not here. |
| **AVM1↔AVM2 cross-VM child SWF execution** | infrastructure | 6 `mixed_avm/*` + `avm1/shared_stack`, `remove_different_level`, `sandbox_type_remote`, `avm2/sandbox_type_remote`, `selection_onsetfocus_mixed_avm` | The known "multi-SWF child-frame execution" blocker plus `AVM1Movie`. Real infrastructure, not polish. |
| **Filters** | filters arc | `timeline/nav/filters`, `visual/filters/avm1_convolution_initialization`, `acid/acid-filter`, `pixelbender_effect_glassDisplace_shaderfilter` | Explicitly out of scope; needs its own scoping pass. |
| **`recursion/pcre_find_fixedlength`** | — | 1 | Documented **ceiling** (libregexp stores capture indices as bytes; the last row wants 500 real capture values). Not fixable. |
| **`from_shumway/fuzz/f404586…`** | — | 1 | Low-confidence oracle material per the re-rank. |
| **`avm2/verify_typecheck`** | recompiler | 1 | Wants real type checking (#1058/#1051/#1026), not a message reformat. Bigger than a polish batch. |

### Flagged separately, per the tranche-0 brief

**(a) `matching == expected` — extra or misordered actual lines** (a
different failure class from "missing lines"; a fix here must *remove*
or *reorder* output, so these can silently regress a neighbour):

| Test | Shape |
|---|---|
| `avm1/load_cancel_via_removemovieclip` | 4 extra lines: `MovieClipLoader.onLoadStart` / `onLoadInit` fire after the clip was removed — the load should have been cancelled. Cross-VM/child-SWF family. |
| `avm2/button_nested_frame_simple` | 12 extra lines: we keep ticking frames past the expected end (frame-loop overrun). |
| `from_gnash/misc-swfc.all/sound` | 5 extra lines: the harness's own `FAILED: TOTAL tests run: 1, expected: 2` — one sub-assertion never runs. |
| `mixed_avm/avm1_loads_avm2_doaction` | 2 extra lines explicitly marked `this shouldn't print` — the inner SWF's DoAction/DoInitAction must NOT execute. |

Also worth noting three near-passes whose actual is *misordered* rather
than missing, and which therefore belong with (a) in spirit:
`avm2/doabc_and_symbolclass_script_init_normal` (script-init order),
`avm2/subclass_superclass_linked_symbol` (super-ctor trace order),
`avm2/loader_load` + `bom` (URL-variable emission order —
`cccc=true&aaa=bbb` vs `aaa=bbb&cccc=true`, i.e. hash order, likely
RUFFLE_VS_FLASH material like `loader_load`'s already-retired lines).

**(b) Accepted-diff / RUFFLE_VS_FLASH candidates** — routed to the avm1
investigation docs rather than fixed. Candidates found: the
`loader_load`/`bom` URL-variable ordering above (hashbrown enumeration
order — `loader_load` already has a RUFFLE_VS_FLASH entry for exactly
this), and `recursion/pcre_find_fixedlength` (already documented as a
ceiling in the ByteArray/PCRE arc). No new platform-UB cases surfaced —
this sweep's failures are overwhelmingly real, fixable behaviour.

**(c) `as3/RuntimeErrors` members** — 10 candidates. Standing policy
holds: never an arc, only riders. Their causes as diagnosed:
`Error1075MathNotAFunction` and `Error1076MathNotAConstructor` ride
**B2**; `Error1081ReadSealedErrorNs` rides **B6**;
`Error1074IllegalWriteToReadOnlyProp` rides **B9**. The remaining six
(`Error1052InvalidUriPassed`, `Error1064CannotCallMethodAsConstructor`,
`Error1120CannotDeleteProperty`, `Error1050CannotConvertToPrimitive`,
`Error1117InvalidXmlName`, `Error1119DeleteDoesNotSupportXMLListOperand`)
are six unrelated one-assertion causes — left on the board.

### Full inventory (generated)

`ruffle-tests/tests/swfs/_investigation/NEAR_PASS_TRIAGE_2026-07-30.md`
carries all 172 candidates as a table — suite, test, gap, post-sweep
status, bucket, and the first differing line — with the machine-readable
candidate list beside it as `near_pass_candidates_2026-07-30.json`. It is
generated from the tranche-0 diff sweep and is the working input for every
bucket below that is still open.

Accurate split from that table (the hand-written list further down was
incomplete — it named ~55 of them):

| | count |
|---|---:|
| candidates | 172 |
| shipped by session 1 | 19 |
| **still open, in a named bucket** | **56** |
| **still open, unbucketed single cause** | **97** |

So the tail is *larger* than this arc doc's prose first suggested: after
the ranked buckets are exhausted there are ~97 tests that each need their
own diagnosis-to-fix, which is the real reason a polish session yields
+19 rather than +40-60. The named-bucket remainder (56) is where the
next session's leverage is, and B3/B4 are 17 of it.

### Leftover singles with a diagnosed cause (for a future session)

*(a partial hand list, superseded by the generated table above)*

`avm2/accessibility` (`Accessibility.active`), `air_ifilepromise`
(`IFilePromise` class), `security_domain_current` (`SecurityDomain`),
`swz` (`ByteArrayAsset`/`BitmapAsset`), `print_job_options`
(`PrintJobOptions`), `game_input` (`GameInput` family),
`generate_random_bytes` (`flash.crypto`), `loader_applicationDomain`
(`PropertyChangeEvent`, `ByteArrayAsset`),
`stage_domain_getQualifiedDefinitionNames`, `av_tag_data`,
`textline_name`, `perspective_projection_basic`
(`PerspectiveProjection` — the flash.geom-3D tail),
`netstream_flv_date`, `sound_rootless`, `sound_constructor_with_args`,
`audio/g711` (A-law/µ-law FLV), `fonts/device_font_kerning`,
`text/links_in_scrolled_text`, `avm1/geturl` (`$version` + POST params),
`avm1/native_objects_swf6`, `avm1/string_relational_compare`
(code-point vs code-unit relational compare),
`avm2/parse_int`, `parse_float_swf10`, `activation_class`,
`method_association`, `newclass_mismatched`, `constructsuper_null`,
`constructprop_method`, `supercalls_weird`, `property_priority_chained`,
`scopes_dont_cache/order-{1,2}`, `scope_optimizations`,
`getouterscope_two_classobjects`, `superinterface_call`,
`place_and_lookup/swf{9,10}` (`[object Video]`), `static_text`
(`StaticText$` cannot be instantiated), `system_exit`,
`system_setclipboard_null`, `blend_mode_null`, `graphic_linkage`,
`issue_8630_placeremoveplace{,_scriptremove}`,
`instantiate_root_character`, `property_is_enumerable_reset`,
`displayobject_opaque_background`, `cross_api_version_call_newer`,
`applicationdomain_hasdefinition_null`, `bitmapdata_draw_alpha_erase`,
`bitmapdata_zero_size`, `error_tostring_more` (`DRMManagerError`),
`xml_appendchild_swf_v21`, `from_shumway/acid/*`, `stroke1`,
`esc`, `bitmapdata/getpixel-from-embedded`, `as3-loader/*`,
`visual/avm2_button_scroll_rect`, plus the `ecma3` singles
(`ObjectObjects/hasOwnProperty`, `Statements/e12_10`,
`Unicode/utf8count`), `e4x/{QName/e13_3_2, XML/e13_4_4_17,
XML/e13_4_4_32/v9, Namespace/e13_2_5}`, `regress/bug_483783`,
`regress/bug_550958`.

(The generated table is authoritative for the complete set.)

## 2. Fix batches

Every batch was predicted before coding and canary-checked before push,
with canaries chosen by **content-grep**, not by name (the encoding1
lesson — a name-based list misses the tests that reach a mechanism
through their data).

| Batch | Commit | Bucket | Predicted | Actual | Notes |
|---|---|---|---|---|---|
| 1 | `f50ac436b` | B1 avmplus VerifyError messages | +7 | **+8** | +1 CI-only rider: `cpool_index_invalid_bytecode_1` sat OUTSIDE the ≤5-line window and passed anyway |
| 2 | `846ef6538` | B2 `Math` not callable/constructible | +6 | **+6** | one cause, two suites |
| 3 | `c045e044c` | B6 `#1081` split + B7 apply/call arity | +5 | **+2** | B5 dropped mid-batch; `#1081` half REVERTED in `0241861f4` after CI (see §3) |
| 4 | `22404706d` | B9 qualified names in `#1074` + B8 e4x PI AttributeName | +3 | **+3** | |

**Final: +19, zero regressions, zero other status moves.** Verified by CI
`30548659769` (graphics/`categories=full`) against baseline `dae7ec9e7`:
corpus **3999 → 4018 / 4421**, avm2 998 → 1006 (+8), from_avmplus
1510 → 1521 (+11). Histogram otherwise flat — `runtime_error` 7 → 7,
`recomp_fail` 1 → 1, `ruffle_matched` 241 → 241, and still no
segfault / timeout / compile_fail bucket. The intermediate run
`30526275513` (batches 1–3) read +17 / 2 regressions before the revert.

The `ruffle_matched` count holding at 241 is the load-bearing check for
this arc specifically: two batches changed error-message TEXT, and a
`ruffle_matched` grade depends on our output staying a subset of Ruffle's
diffs, so it can flip without crossing the pass/fail line. Read the
"OTHER STATUS MOVES" line, not just regressions, after any
message-formatting change.

### Session 2 — the two medium buckets, plus two riders

Baseline `cbdddd750` (corpus 4041/4421). Predictions were re-made from
this session's own reading of the diffs, not carried over from §1.

| Batch | Commit | Bucket | Predicted | Actual (local) | Notes |
|---|---|---|---|---|---|
| 5 | `f1a80bdc8` | B3 timeline/nav PlaceObject state + rewind recreate | +9 of 10 | **+9 (+1)** | `nav/filters` had already been closed by the filters arc; `blendmode_3` already passed. `nav/clipDepth`, outside the window, rose to `ruffle_matched` |
| 6 | `92ca512ed` | B4 hit-test + interactive bounds | +7 of 8 | **+12** | 4 mechanisms, not 1; the integer-twips quantization carried four unpredicted riders |
| R1 | `387cfce60` | embedded JPEG characters for AVM2 | 0 corpus | **0 corpus** | closes 2 of the 4 uncaught-error worklist blockers; `define_bits_jpeg2_huge` 2 → 13 lines |
| R2 | `ff7151c15` | away3d `#1069 implicitPartition` | 0 corpus | **0 corpus** | a real property-resolution bug of ours; see §4 |

**Final: +21, zero regressions, zero other status moves.** CI
`30583810264` (graphics/`categories=full`) against `cbdddd750`: corpus
**4041 → 4062 / 4421 (91.9%)**, avm2 1026 → 1035 (+9), from_shumway
185 → 196 (+11), visual 137 → 138 (+1). Histogram otherwise flat —
`runtime_error` 7 → 7, `recomp_fail` 1 → 1, and still no segfault /
timeout / compile_fail bucket at all. No shard was lost.

The 21: the seven `timeline/nav` targets, `blendmode_1`, `blendmode_2`,
the six B4 targets, `visual/avm2_button_scroll_rect`, and **five CI-only
riders** — `tab_ordering_arrows` and `flash_media_video_rotation_probe`
(integer twips, both predicted locally), plus `blend_mode_null` (the new
`#2008` validation), `from_shumway/stroke1` (integer twips) and
`timeline/nav/clipDepth`, which was outside the ≤5-line window entirely
and rose to `ruffle_matched`.

## 3. Postmortem

### The one regression pair, and what it taught

Batch 3 widened the sealed-read error split from `dynamic || mn_attr` to
`mn_attr || !mn_public`, which won
`as3/RuntimeErrors/Error1081ReadSealedErrorNs` and lost **two** passing
tests: `avm2/catch_class` (`AS3::hasOwnProperty` on the catch scope
object) and `as3/Definitions/Classes/Ext/AccStatPropViaSubClass` (a
static in the base class's namespace, reached through the subclass). Both
pin **#1069** for a non-public **QName** miss on a sealed receiver, so
`!mn_public` is simply the wrong generalization — it traded two for one.
Reverted in `0241861f4`.

The valuable part is why the surviving target is unreachable from there.
`Error1081ReadSealedErrorNs` reads `a.name` — a **public** name — off a
sealed, interface-typed receiver. Ruffle's split
(`script_object.rs::get_dynamic_property`) is
`!valid_dynamic_name() && has_multiple_ns()`, where `valid_dynamic_name`
is `contains_public_namespace() && !is_attribute()`. For a public name
that predicate is TRUE, so the branch never fires: **that #1081 comes
from a different site entirely.** Finding that site is the follow-up;
broadening `getproperty_common` is not, and both the code comment and
`0241861f4`'s message say so explicitly to stop a re-attempt.

Canaries did not catch this, and could not have as chosen: they were
picked by content-grep for `Error #1069` / `1081` in **expected output**,
and `AccStatPropViaSubClass`'s expected text is just `PASSED!` — the
error code lives in its *assertion*, not its output. For an
error-taxonomy change, grep the test **sources** for the code too, not
only the expected output.

### Method notes worth reusing

- **Triage economics.** `verify_output.py` gives each invocation its own
  `/tmp/swf_verify_*` dir, so invocations are parallel-safe: 28
  eight-test batches at `-P 5` triaged all 172 candidates in ~12 minutes,
  where the first sequential attempt was ~10 minutes for 9 tests. Also:
  `--recompile` regenerates RecompiledScripts but does **not** rebuild
  the recompiler binary — a recompiler fix looks like a no-op until you
  `cmake --build SWFRecomp/build`.
- **A stale census makes the cheapest-looking batch a trap.** The
  uncaught-error-tracing re-land reads as 34 lines for +4, and half its
  blocker census closed with the shader arc — but re-checking the other
  half against today's tree found every filter class still absent. It
  belongs to the filters arc's closeout.
- **Predictions were accurate where the bucket was one mechanism**
  (B1, B2, B8, B9 all landed exactly) and wrong where "same missing line
  shape" hid two rules (B6). Same-symptom is not same-cause even inside
  one error code.

### Things that cost prediction accuracy

- **`fail()`'s code was already right, only its text was wrong.** The
  entire B1 bucket was a *message-formatting* bug, not a detection gap —
  every one of those verifier faults was already being caught with the
  correct `Error #NNNN`. Two codes *were* genuinely wrong
  (method-index → #1027, class-index → #1060, dxns → #1015 not #1114),
  and those were only visible because the corpus asserts the number.
- **A mechanism can need fixing twice in one file.** e4x has separate
  `xml_kind_filter` and `list_kind_filter`; fixing the XML one made
  `e13_4_4_28` pass and left `e13_5_4_17` failing on the identical
  assertion. Always check whether XMLList has its own copy.
- **`Function.prototype.apply.length` reads the ivtable trait, not the
  prototype function.** The prototype copies already declared the right
  arities; the shadowing ivtable methods (per
  `avm2-typed-prototype-trait-shadowing`) did not. Registering an ES3
  method in two places means declaring its arity in two places.
- **B5 (astral-plane UTF-8) was dropped after diagnosis, not after a
  failed fix.** `invalid_utf8` line 11 and `stylesheet` line 70 need a
  CESU-8 surrogate pair to survive round-trip, and the runtime carries a
  documented constraint — *our strings are UTF-8 and cannot hold a lone
  surrogate* — so every decoder deliberately maps a surrogate-range code
  point to U+FFFD. Making 🐌 work needs WTF-8 storage or a
  pair-combining pass across every UTF-8 decoder. That is its own
  scoping job, not a polish edit.
- **Two of the four `matching == expected` tests are "stop producing
  output" fixes**, which no amount of added behaviour will reach.
  `mixed_avm/avm1_loads_avm2_doaction` literally expects the inner SWF's
  DoAction *not* to run.

## 4. Session-2 postmortem (B3, B4, and the two riders)

### B3 — the paired tests ARE the specification

The triage's warning was load-bearing and worth generalising. `ratio`
wants `New object placed on frame 1: true` and `ratio2` wants `false` off
the *same* test shape; `ratio3` wants `false` again. Diffing the three
SWFs gives the rule directly — the only thing that changes between them
is which `ratio` value frame 1's `PlaceObject` carries and which value
the object is holding when the rewind starts. So the decision is
`old.ratio == final_placement.ratio`, not anything about direction. Our
old code compared the placement's ratio against the **constant 0**
instead of against the object, which is why we got `ratio` and `ratio2`
wrong in *opposite* directions — a shape that reads like two bugs and is
one.

Two details of Ruffle's `survives_rewind` are invisible from the diffs
and have to be read out of the source:

- **The field set depends on the object's TYPE.** A shape/text/morph
  compares id, ratio, clipDepth, matrix and colour transform; a
  button/edittext/bitmap/video skips the transform; a MovieClip is
  decided by its **ratio alone**. Comparing everything for everything
  (what we did) is not a conservative approximation — it makes a
  MovieClip that merely moved fail to survive.
- **A morph shape is re-checked even when it predates the target
  frame.** Every other child that old is waved through untouched. That
  single `&& old_object.as_morph_shape().is_none()` is the whole of
  `nav/morphShape`.

The other half of B3 was simpler than it looked: `colorTransform`,
`blendMode` and `cacheAsBitmap` were being **parsed and thrown away** by
the recompiler — `skipCxform`, `if (has_blend) r.u8();`. Same shape as
the filters arc's finding (a tag field that never reaches the AS
property), and worth checking for first whenever a "tag state not
visible" row appears: look at the *parser* before the runtime.

The rewind default-fill (`GotoPlaceObject::new`'s
`get_or_insert_default` on matrix / cxform / ratio / blend / cache /
filters) is what makes those properties *reset* on the way back — and it
is easy to miss because the tag being replayed genuinely has no such
field. Note what Ruffle purposely omits: name, clipDepth and
**visibility**, which persists across a rewind unlike everything else.

### B4 — one bucket label, four mechanisms

B4 was filed as "hit-testing and interactive bounds" and predicted +5 of
8. It is really four unrelated gaps that happen to be graded by the same
kind of assertion:

1. `hitTestPoint` ignored `shapeFlag` entirely, and the exact-shape walk
   it needed had *already been written* by the input arc
   (`hit_test_shape_obj`). The fix was three lines of routing plus the
   on-stage gate.
2. `hitTestPoint`'s coordinates are **root-relative for the player's own
   root** and stage-relative everywhere else. Nothing about the failing
   lines says so; it comes out of Ruffle's `is_player_root` branch.
3. SimpleButton had no bounds at all, because its state children are not
   in the render list.
4. `scrollRect` was a stub, and — the part that would have bitten a
   careless fix — it **shared its accessors with `scale9Grid`**, so
   making it real would silently have made a `scale9Grid` assignment
   resize the object.

**The lesson to carry: a bucket label that names a SYMPTOM ("hit
testing") predicts nothing about effort.** This is the same trap as
`worklist-labels-name-symptoms-not-owners`, one level up: there, a
worklist row named a symptom rather than an owner; here, a whole bucket
did. B3 by contrast was one family and landed exactly on prediction.

### The integer-twips quantization, finally taken

`ruffle-geometry-is-integer-twips` had recorded "still open: the
DisplayObject property getters return unquantized geometry… quantizing
them is corpus-wide and wants its own scoped item", and named
`avm2/tab_ordering_arrows` as the sole test blocked on it. It turned out
to be **two functions**: `mat_mul` and `rect_union_xform` (`mat_invert`
already did it). Ruffle rounds the f32 rotate/scale product half-to-even
into an i32 twip *before* adding the already-integral translation, at
every matrix compose and every `Matrix * Point`. Doing the same made
`width` read back `21` instead of `20.999999046325684`, which is what
`tab_ordering_arrows` had been failing on, and carried
`flash_media_video_rotation_probe` and `localconnection` with it.

**It was corpus-wide but not risky, for a reason worth stating:** the
expected outputs come from Flash, which is *also* integer twips, so
quantizing can only move us toward the oracle. 176 content-grepped
canaries across the bounds / hit-test / focus / transform families
showed zero regressions and zero status losses, and `bounds_mode` gained
20 matching lines. When a memory says "corpus-wide, wants its own scoped
item", check whether the *change* is corpus-wide or only its *blast
radius* — those are different, and only the first is expensive.

### Rider 1 — the fix was already in the other recompiler

The uncaught-error worklist recorded "embedded JPEG assets for AVM2" as a
residual blocker needing "a decode hop". In fact the **AVM1 tag
recompiler has decoded DefineBits/JPEG2/3/4 with stb_image since
forever**, including the two SWF quirks that make raw stb refuse the data
(the spurious `FF D9 FF D8` Flash's exporter leaves in the stream, and
the stripped trailing EOI). Hoisting three static helpers into a shared
header and writing ~90 lines over them was the whole job.

Generalisation: **before pricing a recompiler feature, check whether the
OTHER recompiler already has it.** The two paths (`swf.cpp` for AVM1
tags, `abc/abc_timeline.cpp` for AVM2 characters) parse the same tag
stream and have drifted apart feature by feature; `abc_timeline.cpp` is
the younger one and is missing things `swf.cpp` solved years ago. The
same check is worth making for the other named blocker, name-only font
characters.

Corpus delta is zero, as predicted — `stage3d_raytrace` and
`stage3d_texture` have empty expected output and already "passed" while
throwing #1009 on stderr. The value is that two of the worklist's four
blockers are closed, and any AVM2 game with a JPEG asset now renders it.

### Rider 2 — a getter/setter pair is TWO declarations

away3d's `#1069 implicitPartition` was a genuine property-resolution bug:
`Entity` overrides only the **setter** of the inherited
`arcane::implicitPartition` and calls `super.implicitPartition = value`
inside it. Our vtable kept one `defining_class` per property, and the
setter-merge path updated the method pointer without it — so the
overriding setter ran bound to `ObjectContainer3D`, and `super` resolved
to `Object3D`, which does not declare the property.

**AS3 lets the two halves of an accessor be declared by different
classes.** Anything that stores "the class that declared this property"
as a single field is wrong for a half-override, in both directions (a
getter-only override must not re-bind the setter it inherited either).

Two method notes from finding it:

- The `#1069` did **not** come from `getproperty_common`, which is where
  a "property not found" bug obviously lives. It came from
  `avm2_op_setsuper`. An `AVM2_DEBUG_1069` print at the site that
  actually threw took two minutes and pointed straight at
  `bound=ObjectContainer3D super=Object3D`, which named the bug outright.
  For an error thrown from N sites, instrument before reasoning.
- The demo is a **chain** of gaps, not one: past `#1069` it hit `#1074`
  on `ContextMenu.customItems` (declared `public var` in AS3, so a
  read-only accessor was simply wrong — now a real per-instance Array),
  and past that a `#1009` on a null `.width`, which is Stage3D-side and
  is recorded in the worklist rather than chased here. A demo SWF is a
  *sequence* of one-line blockers; each fix buys the next one, and the
  right stopping point is where the next cause changes subsystem.

### Prediction accuracy, session 2

+21 against +16 predicted, and every unit of the overshoot came from
**one** change — the integer-twips quantization, which is a *shared
mechanism* and therefore overshoots by the same rule
`shared-mechanism-fixes-overshoot-estimates` already records. The
per-bucket predictions themselves were good (B3 exactly right; B4's
+7-of-8 target list was right and the extra came from the rider).

Both CI-only riders that surprised us were **outside the ≤5-line
near-pass window** — `blend_mode_null`, `from_shumway/stroke1`,
`timeline/nav/clipDepth` — which is the same thing session 1 saw with
`cpool_index_invalid_bytecode_1`. **The near-pass candidate list is a
lower bound on a batch's yield, never an upper one:** it is filtered by
line gap, and a mechanism fix does not care how many lines a test was
missing.

## 5. Session 3 — the re-triage, and the missing-class cluster

Baseline `af2ac0795` (corpus **4079/4422**). The session opened with a
mandatory re-verification, and it paid for itself immediately: the
tranche-0 ledger is several arcs stale.

### 5.1 Step 0 — what the re-triage found

Regenerating the near-pass list from today's `results_graphics.json`
(same rule, same 19 leaf suites):

| | tranche 0 | now |
|---|---:|---:|
| candidates | 172 | **136** |
| avm2 | 82 | 67 |
| from_avmplus | 48 | 37 |
| from_shumway | 21 | 12 |

42 ledger rows are gone (fixed by sessions 1–2, the FTE arc, the filters
arc and the shader arc), and **6 candidates are NEW** —
`flash_media_video_setter`, `xml_list_delete_clear_parent`, from_shumway
`Matrix3DClass` / `PerspectiveProjectionClass` / `hittesting`, and
`visual/simple_shapes/heavy_tesselation` (a `recomp_fail`). The new ones
are all *near-passes created by a prior arc's partial fix* — a test that
was 40 lines short is now 4 short. **The near-pass list regenerates
itself as the corpus improves; never carry one forward.**

Of the 130 survivors, only ~15 are still in a named bucket (B1 verifier
messages 6, B10/B11/B12/B9 two each, B4 one). The rest is the 93-single
tail plus 12 `D-crossvm` and the standing skips.

### 5.2 The uncaught-error re-land is still blocked — by two tests

The corpus-wide query (`status == pass AND error_signature != null`)
returns exactly **2** survivors, down from 22 → 4:

| test | signature today | expected output |
|---|---|---|
| `avm2/away3d_advanced_shallow_water_demo` | `#1065 ContextMenuEvent is not defined` | **0 bytes** |
| `visual/definefont4` | `#1009 … (accessing field: getEffectiveLineHeight)` | **0 bytes** |

Both have `expected_lines == 0`, so **any** traced line flips them
pass → fail. The re-land measures +2 / −2 today; it is not landed, and
`ac2325c6f` stays.

What the query *did* show is that both survivors' causes have MOVED
since the last attempt, which is the useful part:

- `definefont4`'s blocker is no longer `#1065 ContentElement` — the FTE
  arc built that, so TLF now runs much further and dies on a null
  `getEffectiveLineHeight`. It is still "the Text Layout Framework", but
  a strictly later part of it, and the fix is now "finish TLF" rather
  than "start TLF".
- away3d's is no longer the Stage3D `#1009 width` recorded in
  `uncaught-error-worklist.md` §6 — it is `#1065 ContextMenuEvent`, an
  ordinary missing class, and past it the chain continues. **A demo
  SWF's blocker is a moving target: re-read the signature before pricing
  it, because each landed fix buys the next link and the recorded one
  goes stale.**

The `ruffle_matched` half of the risk set (7 tests) is unchanged and
still harmless for the reason §4.5 of the worklist records: Ruffle
traces the same line, so its reference output already contains it.

### 5.3 Batches

| Batch | Commit | Cluster | Predicted | Actual (CI) |
|---|---|---|---|---|
| 7 | `a62c4ce61` | missing playerglobal classes | +10 | **+10** |
| 8 | `da8a5f5df` | parseInt numerics + placed Video | +5 | **+5** |

**Final: +15, zero regressions, zero other status moves, histogram
completely flat.** Corpus **4079 -> 4094 / 4422 (92.6%)**.

- CI `30599630053` (graphics/`categories=full`, baseline `af2ac0795`):
  4079 -> 4089, avm2 1052 -> 1062. `output_mismatch` 335 -> 325,
  `ruffle_matched` 242 -> 242, `runtime_error` 7 -> 7, `recomp_fail`
  1 -> 1, no segfault / timeout / compile_fail bucket on either side.
- CI `30601250181` (same dispatch, baseline `7f26178e3`): 4089 -> 4094,
  avm2 1062 -> 1065, from_avmplus 1521 -> 1523. Histogram otherwise
  identical.

**Both batches landed EXACTLY on prediction, with zero CI-only riders** —
the first session in this arc where that happened. Sessions 1 and 2 each
overshot (+8 vs +7, +21 vs +16) and the overshoot always came from a
*shared* mechanism carrying tests outside the near-pass window. Neither
of this session's clusters is shared: a class that does not exist blocks
exactly the tests that name it, and `AVM2_CHAR_VIDEO` reaches exactly
the movies that place a video. **Prediction accuracy is a property of
the cluster's blast radius, not of the estimator** — a *name*-keyed
cluster prices exactly, a *behaviour*-keyed one overshoots.

**Batch 7 — the missing-class cluster.** Clustering the 93 singles by
their *current* `error_signature` rather than by their ledger bucket
made one group jump out: nine tests whose first `getlex` throws
`#1065 Variable X is not defined`, i.e. a playerglobal class that simply
does not exist. Nine unrelated-looking singles, one mechanism.

Adding the classes also closed `avm2/abstract_classes` (132 lines), the
FTE arc's "endgame, no partial credit" rider — because eight of the
fourteen classes it was missing were already on the batch's list. The
census `fte-arc.md` §6 recorded was **off by one**: `WorkerDomain` is
also absent, so it was 14 remaining, not 13.

**Batch 8 — parseInt + Video.** Two clusters of one mechanism each; see
the commit message for the numeric rule.

### 5.4 Postmortem

**Clustering by `error_signature` beats clustering by symptom.** The
tranche-0 ledger's bucket column called all nine of batch 7's tests
"single", because their *first differing lines* look nothing alike
(`false`, `[class IFilePromise]`, `test string`, `785077`, …). Their
error signatures are identical in shape. `results_graphics.json` already
carries the field; one `Counter` over it found in seconds what a
diff-reading pass had classified as nine separate problems. This is the
converse of `bucket-by-vm` and of B4's lesson: a SYMPTOM prices nothing,
but a THROWN ERROR names its own owner.

**A "class exists" fix has an inverse assertion somewhere.** Adding
`flash.desktop.IFilePromise` for `air_ifilepromise` would have broken
`air_hidden_lookup`, a passing test that asserts the very same name is
**inaccessible** from a plain Flash Player SWF. The discriminator was
already in the tree (`[player_options] runtime = "AIR"` →
`-DSWF_RUNTIME_AIR`). Content-grepping the PASSING corpus for each new
class name is what caught it, and it is the check to repeat for every
future class-stub batch: **before adding a name, grep for a test that
wants it absent.**

**Distinguishing a script `new` from an internal mint was free.** Twenty
already-registered classes needed the #2012 abstract gate, and the
runtime mints most of them itself. Both prior gates in the tree
(`TextLine`, `MorphShape`) carry an ad-hoc boolean for exactly this. The
general discriminator turned out to cost nothing: `avm2_construct_value`
is called ONLY from `avm2_ops.c`'s `construct*` opcodes, so it arms a
flag the first `alloc_instance` consumes — which also, correctly, makes
a constructor body's own internal mints not-a-script-new. New gates
should use `avm2_class_alloc_is_script_new()` rather than a new boolean.
The one exception is a class whose internal mint bypasses
`avm2_class_alloc_instance` entirely (`Stage`, via
`display_alloc_instance`) — there the flag is simply false already, and
the class needs its own chained hook only because it already had a
native_init to preserve.

**avmplus's parseInt is exact for a power-of-two radix and inexact
otherwise, and only three graded lines reveal it.** Two of them wanted
the exact answer and one wanted the double chain's — which is what
turned a plausible "just be exact everywhere" fix (which broke a
previously-passing line) into the right rule. **When two lines pull one
way and a third pulls the other, the third is the specification**, the
same shape as B3's `ratio`/`ratio2` pair in §4.

**The parallel canary sweep produces floating-point false positives.**
`verify-output-parallel-batching` records that `verify_output.py` is
parallel-safe, and it is — for *triage*. At `-P 6` with `--save-actual`,
seven number-formatting tests (`utils3d`, `number_tofixed`,
`number_toprecision`, `number_toexponential`, `coerce_string_precision`,
`parse_float`, …) reported f64-instead-of-f32 values and full-precision
instead of shortest-round-trip printing. **Every one passed on a clean
sequential re-run.** So: parallel sweeps are fine for reading diffs and
for finding *structural* regressions, but any floating-point mismatch
they report must be re-run sequentially before it is believed. Related
hazard, also observed: do not edit runtime sources while a sweep is
running — a test that compiles mid-edit reports garbage.

### 5.5 Diagnosed causes left on the board (not taken)

- **`avm2/scopes_dont_cache/order-{1,2}`** (+ the related
  `scope_optimizations`, `getouterscope_two_classobjects`) — a
  hand-generated ABC (`generate.py` upstream) whose `findpropstrict`
  uses a **MultinameL**: the name arrives on the runtime stack, and the
  namespace SET is `{outer, inner}`. Our scope walk resolves through
  `avm2_vtable_find_mn(vtable, data, mn_idx)`, which is keyed on the
  static multiname index alone and therefore cannot match a
  runtime-named multiname at all — hence `#1065 Variable value is not
  defined` on the very first lookup. Fixing it means threading a runtime
  name through `findproperty_scope_walk` (and the recompiler's
  emission). A real feature, not a polish edit.
- **`avm2/issue_8630_placeremoveplace{,_scriptremove}`** — a
  place/remove/place cycle where the re-placed child's `width` should be
  `2.75` and reads `0.75` (and, in the `_scriptremove` variant, should
  return to `0` and stays `2.75`). A TextField-bounds × timeline
  interaction, not a one-liner.
- **`avm2/parse_float_swf10`** — three causes in one test: two
  exponent-precision rows and the SWF≤10 `parseFloat("1.2345.678")`
  quirk (Flash yields `12345.678`, i.e. it drops the FIRST decimal
  point). Left as a genuine single.
- The **B1 verifier-message remainder** (6), **B9/B10/B11/B12** (2 each)
  and **B6** (the documented dead end) are unchanged from §1.

## 6. Session 4 — the error-taxonomy cluster, and a dry signature well

Baseline `a28b3e2cb` (corpus **4094/4422**, results from CI
`30604886586`). CI `30638028597` (graphics/`categories=full`,
`images=false`): **4094 -> 4110 / 4422 (92.9%)**, avm2 1065 -> 1072
(+7), from_avmplus 1523 -> 1532 (+9). `output_mismatch` 320 -> 304,
`ruffle_matched` 242 -> 242, `runtime_error` 7 -> 7, `recomp_fail`
1 -> 1, still no segfault / timeout / compile_fail bucket on either
side. **Zero regressions, zero other status moves.**

### 6.1 Step 0 — the list regenerated again

Same rule, same 19 leaf suites:

| | tranche 0 | session 3 | now |
|---|---:|---:|---:|
| candidates | 172 | 136 | **122** |
| avm2 | 82 | 67 | 55 |
| from_avmplus | 48 | 37 | 35 |
| from_shumway | 21 | 12 | 12 |

Gap histogram `0:5 1:42 2:31 3:14 4:17 5:13`; status `output_mismatch
117`, `runtime_error 4`, `recomp_fail 1`. The regeneration cost about
five minutes and is still mandatory — §5.1's finding holds every time.

One schema note for whoever writes the next script: the per-test line
counts live under a nested `lines` object
(`t['lines']['expected_lines']`), not at the top level. Reading them
with `t.get('expected_lines', 0)` silently yields 0 for every test and
produces a "328 candidates, all gap 0" list that looks plausible.

### 6.2 Step 1 — the signature well is dry, so cluster on the THROW ITSELF

Session 3's headline move was a `Counter` over `error_signature`. Run
again here it returns almost nothing: **only 18 of the 122 candidates
carry a signature at all**, and the largest group is 3. Session 3
harvested that vein — the missing-class batch removed exactly the tests
whose first `getlex` threw.

What replaced it: read the candidates' first differing line for the
*shape* `expected: Error #NNNN got: no error`. That is not a symptom, it
is a **thrown error that never happened** — the same "the error names its
owner" property as a signature, recorded on the expected side instead of
the actual side. Nine of the 122 have it, and they cluster by the SITE
that should have thrown, not by the error number:

| rule | tests |
|---|---|
| `delete` on a primitive -> #1120 | `Error1120CannotDeleteProperty`, `ecma3/String/e15_5_5_1` |
| construct a class-bound method -> #1064 | `Error1064CannotCallMethodAsConstructor`, `avm2/constructprop_method` |
| `delete` with an XMLList operand -> #1119 | `Error1119DeleteDoesNotSupportXMLListOperand` |
| `XML.setName(undefined)` -> #1117 | `Error1117InvalidXmlName` |
| `isXMLName` absent -> #1050 not #1065 | `Error1050CannotConvertToPrimitive`, `e4x/Global/isXMLNameTypeErr` |

Note what this does to the standing `as3/RuntimeErrors` policy. Six of
those tests are RuntimeErrors members, which §1(c) called "six unrelated
one-assertion causes, left on the board". They were unrelated *as a
directory*; they are five two-line fixes once each is keyed by its
throw site, and two of them carry a non-RuntimeErrors sibling with them.
**The policy ("never an arc, only riders") is right, but a rider needs a
mechanism to ride — this session's mechanism was "read the assertion for
the throw that should have happened".**

### 6.3 Batches

| Batch | Cluster | Predicted | Actual (CI) |
|---|---|---|---|
| 9 | error taxonomy: 5 targeted throws | +8 | **+9** |
| 10 | ApplicationDomain: gQDN / hasDefinition(null) / currentDomain identity | +3 | **+4** |
| 11 | object model: enumerable tombstones, isPrototypeOf on primitives, opaqueBackground | +3 | **+3** |

Shipped as one commit (`a28b3e2cb`) because all three touch
`avm2_globals.c`; attribution above is by test name, which is exact.

The **two CI-only riders** were both outside the ≤5-line window, as in
every prior session: `avm2/applicationdomain_getqualifieddefinitionnames`
(a second gQDN test — the name-keyed batch found it without being told)
and `from_avmplus/e4x/Expressions/e11_3_1` (the #1119 rule). +16 against
+14 predicted.

### 6.4 What each fix actually was

- **#1120 is about the RECEIVER'S KIND, not about traits.** Ruffle's
  `Value::delete_property` answers true/false for every *object* and
  throws unconditionally for every *primitive*. Our code returned `false`
  for non-objects, which is the ES3 answer. The reason this reaches an
  ecma3 String test at all is that `new String()` yields a String
  **value** in AVM2, so `delete s.length` is a delete on a primitive.
  Reading the rule off Ruffle's match arms took two minutes; reasoning
  from the three failing assertions would have suggested "sealed traits
  throw", which is wrong and would have broken
  `as3/Vector/initializer_expressions` and `ecma3/Number/e15_7_3_1_1`,
  both of which assert `delete <trait>` === **false**.
- **#1064 keys on the method's bound class**, so it fires for a method
  closure, a prototype method and `arguments.callee` alike, and never for
  a `newfunction` closure. Our function objects already carried
  `fn_bound_class` for exactly the set Ruffle gates on; the fix was the
  gate, not the plumbing.
- **#1119's operand is the property NAME, not the receiver.** `delete
  books.book.(@publisher == "Adobe")` compiles to a filter that leaves an
  XMLList on the stack *as the runtime name*, so the check belongs in the
  `_dyn` (runtime-name) delete op and nowhere else.
- **`setName(undefined)` is a QName-constructor rule.** setName routes
  its argument through `new QName(name)`, and the QName constructor maps
  a single `undefined` to the EMPTY local name rather than the string
  `"undefined"`. Empty is not an XML name, so the existing #1117 check
  fires on its own once the argument is mapped correctly. A fix in the
  *caller's* argument handling, not in the validator.
- **`isXMLName` was simply absent**, and its absence was *disguised*:
  both its tests reported `expected Error #1050 got Error #1065`, which
  reads like a taxonomy bug in the coercion path. It is a missing global
  — and #1050 already worked, so registering the function was the whole
  fix for both. **`#1065 Variable X is not defined` inside a "wrong error
  code" assertion is the missing-name signal wearing a disguise.**
- **`propertyIsEnumerable` matched TOMBSTONES.** `delete` leaves the
  entry in the dynamic-property list with its `dont_enum` intact, and a
  later assignment appends a *fresh, enumerable* entry behind it; the
  enumerable accessors were the only readers in the file not skipping
  `p->dead`. Everything else — enumeration, lookup, set — already did,
  which is why the property both "iterated over" and reported
  non-enumerable in the same trace. **A contradiction between two lines
  of the same test names the reader that is out of step.**
- **`isPrototypeOf` must walk a primitive's chain** (its class's
  prototype object). Same root cause as #1120: `new String("x")` is a
  value.
- **`opaqueBackground` is declared `Object`,** so assigning `undefined`
  stores the AS3 coercion — `null`. A one-line consequence of a
  *signature*, invisible from the runtime code.
- **`getQualifiedDefinitionNames` was free** — the domain already stores
  every script definition with its scope and namespace; the method is a
  filtered walk of `ctx->domain.entries`. `currentDomain === currentDomain
  === false` cost more: it means minting a fresh wrapper per read, so the
  scope now travels in the wrapper's `native_ext` and many wrappers can
  name one scope (`scope->obj` stays the cached wrapper that GC-marks the
  domain).

### 6.5 Method notes

- **The parallel canary sweep has a SECOND false-positive mode: compile
  timeouts.** §5.4 recorded floating-point noise at `-P 6`. At `-P 8`,
  `ecma3/Statements/eregress_74474_{002,003}` reported FAIL — they each
  need ~65 s of *gcc* (not run) time, and lose the race under load. Both
  pass sequentially. Generalised rule: **any parallel-sweep failure whose
  test has a long `phases.compile` in `results_graphics.json` is presumed
  false** — check that field before believing it, the same way §5.4 says
  to re-run float mismatches.
- **Capture the verify verdict from the SUMMARY block, not the progress
  line.** A sweep keyed on `grep -o '\.\.\. \(PASS\|FAIL\)'` returned
  `NORUN` for all 228 tests inside a nested-quoted `bash -c`, which the
  status comparison then reported as 68 regressions. Parsing
  `^Pass: *N` / `^Fail: *N` is quoting-proof and unambiguous.
- **Restricting canaries to baseline-PASSING tests halves the sweep.**
  229 canaries at `-P 8` took ~11 minutes; the unrestricted 320-directory
  version would have been ~40. A regression is by definition a
  pass -> fail move, so nothing is lost.

### 6.6 Left on the board (diagnosed, not taken)

Everything in §5.5 still stands, plus:

- **`ecma3/ObjectObjects/hasOwnProperty`** — `str.hasOwnProperty("split")`
  must be **false** for a String primitive. Our String class registers
  its methods as PUBLIC ivtable traits, where avmplus has them in the
  `AS3` namespace with only the prototype copy public. Fixing this test
  means moving that surface, which is [[avm2-es3-prototype-surface]]'s
  job, not a polish edit. (`isPrototypeOf`, its neighbour in the same
  cluster, was independent and shipped.)
- **`ecma3/Statements/e12_10`** — `with (7) x = valueOf()` must yield a
  *number*. Ruffle's scope stack holds a `Value`, ours holds an
  `Avm2Object*`, so `pushwith` on a primitive boxes it and `valueOf`
  returns the box. Widening `Avm2ScopeEntry` is a recompiler+runtime
  change.
- **`avm2/system_exit`** — wants a three-line `getStackTrace()` including
  a native frame (`at flash.system::System$/exit()`). The #2017 throw is
  trivial; the stack-trace format is the actual work.
- **`avm2/newclass_mismatched`** — three hand-built ABC cases wanting
  #1034 / #1009 / #1108 where we give #1108 first. Our `newclass`
  base-class check is both too strict and too early; it also blanks
  `as3/RuntimeErrors/Error1074IllegalWriteToReadOnlyProp` (a VALID
  program we reject with #1108). Worth taking next — it is one site with
  two graded tests — but it needs the ABC disassembled to order the three
  cases.

## 7. Session 5 — the namespace axis

Baseline `b4d4457f1` / CI `30659262052` (graphics/`categories=full`,
`images=false`): **4110 -> 4121 / 4422 (93.2%)**, avm2 1072 -> 1074 (+2),
from_avmplus 1532 -> 1541 (+9), regression 70 -> 70. `output_mismatch`
304 -> 293, `ruffle_matched` 242 -> 242, `runtime_error` 7 -> 7,
`recomp_fail` 1 -> 1, still no segfault / timeout / compile_fail bucket.
**Zero unexplained regressions, zero other status moves.** (The run itself
scored 4120 with one flagged regression — `regression/avm2_findprop_this_resolution`,
whose expected output this session's own fix invalidated; see §7.5.)

### 7.1 Step 0 — the list keeps regenerating

| | tranche 0 | s3 | s4 | now |
|---|---:|---:|---:|---:|
| candidates | 172 | 136 | 122 | **110** |
| avm2 | 82 | 67 | 55 | 50 |
| from_avmplus | 48 | 37 | 35 | 28 |
| from_shumway | 21 | 12 | 12 | 12 |

Gap histogram `0:5 1:37 2:26 3:14 4:16 5:12`; status `output_mismatch 105`,
`runtime_error 4`, `recomp_fail 1`. The nested-`lines` schema note from
§6.1 is still the one thing that silently corrupts the list.

### 7.2 Step 1 — BOTH prior keys are dry; the third axis is the NAMESPACE

- Session 3's key (`Counter` over `error_signature`): **16 of 110** carry a
  signature, largest group **2**. Dry, as §6.2 already found.
- Session 4's key (`expected: Error #NNNN got: no error` on the expected
  side): **zero hits**. That session harvested its own vein completely.

The replacement came from reading the 108 collected diffs for a shared
*mechanism* rather than a shared spelling, and one appeared in three
different corners at once:

| corner | tests |
|---|---|
| private-member access must fail across classes | `AccessPrivateClassVariable_rt`, `ExtPublicClassPriv`, `SuperRuntimeError` |
| a namespace-qualified name must be SPELLED in the error | `core_exceptions` |
| a namespaced/wildcard name must reach the right resolver | `WildcardOperator`, `e4x/QName/e13_3_2`, `e4x/Expressions/e11_1_1`, `e4x/Namespace/e13_2_5` |

Nothing in the diff TEXT groups these — `subclass PASSED!`, `Cannot create
property ns::asdf`, `|value3| got ||`, `|true| got |false|` look unrelated.
They group by *which part of a multiname the runtime got wrong*.
**When both the actual-side and expected-side error keys run dry, cluster on
the ENGINE STRUCTURE the tests exercise, not on any string in the diff.**

### 7.3 Batches

| Batch | Cluster | Predicted | Actual (CI) |
|---|---|---|---|
| 12 | newclass ordering + read-only class traits | +2 | **+3** |
| 13 | private-namespace IDENTITY | +3 | **+3** |
| 14 | qualified spellings, wildcards, E4X names | +5 | **+5** |

Shipped as one commit (`b4d4457f1`) — batches 13 and 14 both rewrite
`avm2_ops.c`'s key construction. The single CI-only rider,
`as3/Definitions/Classes/ClassDef/Bug118272Package` (0/6 -> 6/6), was
outside the ≤5-line window, as in every prior session. +11 against +10.

### 7.4 What each fix actually was

- **The #1108 we threw was a VICTIM, not a cause.** The brief named
  `newclass_mismatched` + `Error1074IllegalWriteToReadOnlyProp` as one site
  with two graded tests, on the evidence that both showed
  `VerifyError #1108: OP_newclass ... incorrect base class`. They are two
  unrelated bugs. Error1074's program is `Object = new Object()`, which
  must throw **#1074** — class traits are read-only (Ruffle vtable.rs:
  `TraitKind::Const | TraitKind::Class => new_const_slot`). We allowed the
  write, so the global's `Object` slot became a plain object, and the
  *next* script init to push `Object` as a newclass base died on #1108
  before printing a line. **The test's NAME named its owner; the error we
  emitted named a downstream victim three scripts away.** Our builtins are
  native rather than a playerglobal ABC, so `avm2_builtin_class` and the
  three global constants had to be given the const flag by hand.
- **newclass has three ordered arms, and ours had one.** Ruffle coerces the
  base VALUE to `Class` first (a non-class base is a failed **coercion**,
  #1034), then rejects a null base under a declared super (#1009), and only
  then compares against the declared superclass (#1108). Our #1108 check
  compares the base's **QName against `super_mn`**, not object identity:
  Ruffle compares `Class` objects, but two domains can legitimately hold
  distinct class objects for one declared superclass, and identity would
  throw #1108 on a valid program.
- **Private namespaces are compared by IDENTITY, and we compared URIs.**
  ASC emits one PrivateNamespace pool entry per class, *all with the same
  empty name* — Ruffle's `namespace.rs` says so in a comment: "private
  namespaces are always compared by pointer identity of the enclosing Gc".
  A URI compare therefore makes every class's privates alias every other
  class's, so `Class2` could read `Class1`'s `private var`. `Avm2PropKey`
  gains `ns_priv` (the pool record's address — unique per (file, index),
  stable for the process), consulted **only when both keys are private**,
  which is why the ~60 hand-built keys that never carry kind 0x05 needed no
  audit beyond a NULL init.
- **The same rule was needed TWICE in the recompiler, in two different
  matchers.** `nsKeysMatch` is a documented mirror of `avm2_propkey_matches`
  and took the identical two-line change (within one ABC the pool index IS
  the identity). But fixing it changed nothing for
  `ExtPublicClassPriv` lines 4-5, because `this.privArray` never reaches a
  runtime multiname match at all: `analyzeSlotSpec`'s lever A resolves it
  through `findUniqueSlot`, which searches the superclass chain **by local
  name only** and bakes a `getproperty_slot`. It now requires the found
  trait to ns-match the site multiname. *A "mirror the runtime" comment on
  one function does not mean the file has only one matcher* — grep for the
  other consumers of the same fact before believing a single edit covers
  the recompiler.
- **#1056/#1069 qualify a name only when the site multiname has EXACTLY ONE
  namespace with a non-empty URI** (Ruffle `Multiname::as_uri`). That is
  what makes the rule safe corpus-wide: a compiled `obj.name` carries a
  whole ns SET and keeps printing bare; only an explicit `obj.ns::name`
  qualifies.
- **A wildcard name (`obj.*`) is #1081 on an object and #1069 on a
  primitive**, and the sealed/dynamic split does not apply. Ruffle spells
  this out in a comment on `get_dynamic_property`'s `local_name() == None`
  arm; the failing assertions alone suggest "dynamic receivers should
  throw", which would have broken every expando read in the corpus.
- **A QName as a runtime property name was intercepted before the xmlish
  check**, so `x1.bravo.@[q3]` resolved as a generic `uri::local` key and
  never reached E4X. One `&& !avm2_value_is_xmlish(recv)`.
- **`ns::*` passed the EMPTY string where NULL (any-name) was meant.**
  `avm2_op_getproperty_rtns` builds the E4X name from `avm2_mn_name`, which
  returns `""` for multiname name index 0 — the ABC any-name sentinel. An
  empty local name matches no node, so `y1.@ns::*` counted 0 instead of 2.
- **`Namespace.prefix`/`.uri` report `propertyIsEnumerable == true`**
  (namespace_object.rs overrides it). QName has no such override, so its
  `uri`/`localName` enumerate in for-in yet report **false** — and
  `e4x/Namespace/e13_2_5` pins both halves. Same shape as §6.4's tombstone
  bug: our for-in already yielded them, so the two readers contradicted
  each other and the odd one out was the one to fix.

### 7.5 The one regression was a test this project wrote to predict it

`regression/avm2_findprop_this_resolution` went pass -> output_mismatch on
line 8 (`sub.readShadowed`). Its own README had carried this since it was
written:

> mxmlc emits private namespaces with EMPTY uris (unique only by pool
> index); our runtime compares namespaces by (kind, uri) … Real Flash keeps
> private namespaces distinct per class and would print `base-shadowed` …
> **if private-ns identity is ever fixed, update this line.**

Expected output and README updated. `Base.readShadowed()` reads BASE's
`private var shadowed` even on a `Sub` receiver, because private members
are not virtual — which is what the fix now produces.

Two process lessons, both cheap:

- **A hand-written regression test can be a NOTE TO THE FUTURE, and the
  note is in its README, not in the corpus.** Before committing an
  engine-semantics change, grep `ruffle-tests/tests/swfs/regression/*/README.md`
  for the mechanism — this one names it outright.
- **`regression` was the one suite the canary set omitted**, because the
  canary was built from `avm2` / `from_avmplus` / `from_shumway` results
  alone. It is 70 tests and takes ~5 minutes. Always include it: it is the
  suite most likely to pin OUR behavior rather than the oracle's.

### 7.6 Method notes

- **A header change makes a local canary sweep ~5x more expensive.** This
  session touched `avm2_class.h`, so every test's build recompiled the
  whole runtime and ccache could not help across tests (per-test
  `MOCK_DATE_TIME` already splits the cache). Measured throughput was
  **~13 tests/min at `-P 7` on 8 cores** (load average ~11 — saturated),
  where a source-only change runs several times faster. A 636-test canary
  was abandoned mid-run for a 310-test focused one; the focused set went
  310/310 in ~25 min. **Price the canary AFTER deciding whether the change
  touches a header** — and remember CI grades 4422 tests in 33 minutes on
  30 shards, which is ~50x the local rate, so past ~300 canaries the right
  move is to push.
- **`git checkout <file>` to drop debug instrumentation also drops the real
  edits in that file.** `avm2_ops.c` held both the `fprintf` probes and the
  newclass fix; the checkout reverted all of it silently and the loss was
  only visible because `git diff --stat` stopped listing the file. Strip
  probes with a targeted edit, or commit the real work first.
- **Instrument at the throw site, then print the RECEIVER, not the code.**
  Two `fprintf`s inside the #1108 branch — first the value kind, then
  `class_name_of` — turned "newclass rejects a valid program" into "the
  global's `Object` slot holds an Object instance", which named the real
  bug (a missing #1074) in one step. This is §4's "for an error thrown from
  N sites, instrument before reasoning", one level further: instrument the
  VALUE, not just the site.
- **The eager-snprintf trap from §4 nearly repeated.** The first cut of the
  qualified-name change computed `mn_display_name` on every static
  getproperty and every dynamic-property store. Both were moved onto the
  throw path before the canary ran.

### 7.7 Left on the board

Everything in §5.5 and §6.6 still stands, minus `newclass_mismatched` and
`Error1074IllegalWriteToReadOnlyProp` (shipped). New this session:

- **`avm2/activation_class`** — an activation object wants #1069 for a
  missing method (we give #1006), #1069 for `AS3::hasOwnProperty` (we give
  #1081) and #1056 for a dynamic write (we produce nothing). Three
  different rules on one receiver KIND; needs the activation object's
  sealed/dynamic model settled first, not three patches.
- **`avm2/property_priority_chained`** — a chained-shadowing read picks the
  superclass field where the subclass's is wanted. Adjacent to the
  recompiler slot lever this session touched (`findUniqueSlot` /
  `subclassRedeclares`), and worth taking next by whoever has that code
  paged in.
- **`e4x/XML/e13_4_4_36`** — `setNamespace` must MINT a prefix (`aaa:`) for
  the re-namespaced child rather than re-declaring a default `xmlns`. A
  prefix-allocation rule, not a matching rule.
- **`e4x/Regress/regress-524214`** — `x.@* = 1` (wildcard attribute
  ASSIGNMENT) writes the wrong attribute set. The read half of the
  wildcard rule shipped this session; the write half is its own site.

## 8. Session 6 — the runtime-name half of the multiname

Baseline `a9055f5e3` (CI `30659262052` + `30661785041`). Commits
`569a215e4` + `2ab0c01be`; CI `30670004778` then `30673203712`
(graphics/`categories=full`, `images=false`):
**4121 -> 4129 / 4422 (93.4%)**, avm2 1074 -> 1078 (+4), from_avmplus
1541 -> 1545 (+4). `pass` 3879 -> 3886, `ruffle_matched` 242 -> 243,
`output_mismatch` 293 -> 290, **`runtime_error` 7 -> 2**, `recomp_fail`
1 -> 1, still no segfault / timeout / compile_fail bucket.
**Zero regressions.** One other status move, and it is the intended one:
`avm2/rtqname_not_namespace` runtime_error -> output_mismatch (0/12 ->
9/12 lines). The first CI run also moved
`avm2/getter_different_namespace_setter` pass -> ruffle_matched, which
looked free and was not — §8.5.

Run `30670004778` first came back red with `Shard 26/30` failed. Every
*verify* step in that shard succeeded; the only failed step was
**"Upload misc results"**, an artifact-upload flake, which then failed
`Combine Results` with `INCOMPLETE RUN`. `gh run rerun <id> --failed`
recovered it. Worth checking the failing shard's STEP list before
treating a red `categories=full` run as a code problem — the step name
tells you immediately whether any test actually ran badly.

### 8.1 Step 0 — the list regenerated again

| | tranche 0 | s3 | s4 | s5 | now |
|---|---:|---:|---:|---:|---:|
| candidates | 172 | 136 | 122 | 110 | **102** |
| avm2 | 82 | 67 | 55 | 50 | 48 |
| from_avmplus | 48 | 37 | 35 | 28 | 22 |
| from_shumway | 21 | 12 | 12 | 12 | 12 |

Gap histogram `0:5 1:33 2:23 3:15 4:15 5:11`; status `output_mismatch 97`,
`runtime_error 4`, `recomp_fail 1`. Predicted ~99, got 102 — the list
keeps regenerating rather than depleting, for the fifth session running.

### 8.2 Step 1 — one dead key, one that CAME BACK, and the axis that paid

- Session 3's key (`Counter` over `error_signature`): **15 of 102** carry a
  signature, largest group **2**. Still dry, as §6.2 and §7.2 found.
- Session 4's key (`expected: Error #NNNN got: no error` on the expected
  side) returned **zero** in session 5. It returns **nine** here.
  **A mined-out key is not permanently dead — it refills as other fixes
  push tests into the window.** Re-run both cheap keys every session; they
  cost about a minute. (Those nine were not worth taking as a group this
  time — six want the uncaught-error trace, which is still blocked, and
  three want verifier operand typing — but the *measurement* is what
  stops you from skipping the key next session on a stale belief.)

The axis that paid is the direct continuation of session 5's. Session 5
clustered on **the multiname's NAMESPACE half**; this session's cluster is
**the multiname's NAME half — the runtime-named (`{rt-name}` / MultinameL)
forms**. Nothing in the diff text groups them: `inner-value` vs `||`,
`sanity check base object 3 FAILED!`, `superclass-field1`, an
`AVM2: unimplemented op` abort and a `AVM2 fatal:` abort all turned out to
be the same structure mishandled in five different places.

The tell was **`status == runtime_error`**, one of the structural axes the
session-5 brief listed as unmined. There are only 7 in the whole corpus,
so reading all 7 costs minutes — and 4 of them printed a stderr line
naming the mechanism outright:

| test | stderr |
|---|---|
| `from_avmplus/misc/bug_508617` | `unimplemented op InitProperty mn[66] {ns-set 6}::{rt-name}` |
| `from_avmplus/as3/Definitions/Super/SuperProps` | `unimplemented op InitProperty mn[84] {ns-set 4}::{rt-name}` |
| `from_avmplus/as3/Definitions/Super/SuperInForLoop` | `unimplemented op SetSuper mn[52] {ns-set 1}::{rt-name}` |
| `avm2/rtqname_not_namespace` | `lazy-ns property op: popped namespace is not a Namespace value` |

**`runtime_error` is the cheapest axis in the corpus to read** — the
population is tiny and each member hands you a stderr string that names
its own mechanism, which is more than any diff line does. Run it first.

### 8.3 Batches

| Batch | Cluster | Predicted | Actual |
|---|---|---|---|
| 15 | MultinameL resolution: scope walk, InitProperty/SetSuper emission | +5 | **+5** |
| 16 | ns-set trait priority: most-derived DEFINING CLASS wins | +1 | **+2** |
| 17 | two `avm2_fatal`s that should be catchable errors | +1 | **+1** |
| 18 | E4X wildcard attribute WRITE (§7.7 leftover) | +1 | **+1** |

Batch 16 scored +2 rather than +1 on its second cut: the first cut
(entry-index order) took `property_priority_chained` but silently pushed
`getter_different_namespace_setter` from Flash-correct to Ruffle-bug
compatible — see §8.5. The `defining_class` rule takes both.

### 8.4 What each fix actually was

- **`avm2_op_findproperty_dyn` did `(void) mn_idx`.** A MultinameL takes
  its local name off the stack but its namespace SET is still static, and
  we threw the set away and searched public-only. The correct order is
  **the whole ns set at EACH scope level**, never one namespace across the
  whole chain: `scopes_dont_cache` is built precisely to pin that — its set
  is `{outer, inner}` and the answer is the inner global *only* because it
  sits higher on the scope stack, so a namespace-outer loop returns
  `outer-value` and looks plausible. `avm2_vtable_find_mn_named` was
  already the right per-level primitive and was already in the tree; it
  just had no caller on the scope path.
- **The lazy-multiname arms existed for four ops and were missing for
  five.** GetProperty / SetProperty / DeleteProperty / FindProperty all had
  `mnLazyName` / `mnLazyNs` arms; InitProperty, GetSuper, SetSuper,
  CallSuper and CallSuperVoid `return false` and fell through to
  `avm2_unimplemented_op`. The verifier's stack model already accounted for
  the extra lazy pops (`pops = 2 + lazy`), so the emission was a two-line
  arm per op once the runtime entry points existed. InitProperty differs
  from SetProperty by exactly one flag (`allow_const`), and Get/SetSuper by
  exactly how `name` and the super-vtable entry are obtained — all three
  became shared bodies rather than copies.
- **A ns-set trait lookup can match SEVERAL entries, and the winner is the
  one whose DEFINING CLASS is most derived.** `property_priority_chained`
  has the base declare `field1` *internal* + `field2` *public* and the
  subclass declare `field1` *public* + `field2` *internal*, with a read
  site whose set holds both — so two vtable entries match and only priority
  decides. Ruffle's rule reads as "most recently inserted", encoded
  entirely in `PropertyMap::insert` doing **`bucket.insert(0, ...)`** — it
  PREPENDS, so `get_for_multiname`'s `.next()` yields it.
  **The one-line behaviour of a container (`insert(0, ..)` vs `push`) can
  BE the semantics** — reading `get_trait` alone says nothing.
  But copying that as "our flattened vtable appends, so take the LAST
  match" is **wrong**, and the corpus says so: see §8.5. The rule that
  satisfies both directions is *per-vtable, most-derived class first*,
  which on a flattened vtable means comparing each match's
  `defining_class` depth and, on a TIE, keeping the FIRST — so every
  single-match lookup (the overwhelming majority, and all builtins, whose
  entries carry no defining class) behaves exactly as before. Exact-key
  lookups are untouched: one `(name, ns)` pair has one entry.
- **The `!mn_public` gate was too narrow.** `getproperty_dyn` /
  `setproperty_dyn` consulted the ns-set trait lookup only when the set had
  no public namespace ("dict.test::[name]"). But ASC's ns set for
  `obj[expr]` inside a class routinely holds the package/internal
  namespaces **alongside** public — `SuperProps` reads an `internal var y`
  as `this["y"]` from such a site — so a public-key-only lookup misses the
  fixed property entirely and returns the `String` slot default `null`.
  A trait also beats a dynamic property (Ruffle runs `VTable::get_trait`
  first), so the widened lookup runs *before* the public-key resolve.
- **Two `avm2_fatal`s were catchable errors.** An RTQName/RTQNameL whose
  namespace operand is not a Namespace is a **VerifyError #1058** reported
  at the op, and a declared-but-bodyless ABC method is a **VerifyError
  #1001** reported at the CALL. Both tests catch the throw and print
  `e.errorID`, so a fatal loses the whole test rather than one line. #1001
  names the method the way a stack frame does (`Class/method()`), which is
  `avm2_class_qname_colons_buf` + the debug name, not the debug name alone.
- **The E4X wildcard-attribute WRITE was one early `return`.**
  `x.@* = 1` must keep the FIRST matching attribute, delete the rest and
  assign to it, and must never CREATE one. `avm2_e4x_remove_matching`
  already implemented exactly that (`any_name` included), and
  `xml_set_local` bailed on `name->local == NULL` two lines before reaching
  it. Session 5 shipped the read half; the write half was a deletion.

### 8.5 A `ruffle_matched` status move hid a real regression

The first CI run (`30670004778`) scored **+8 with zero regressions** — and
its `OTHER STATUS MOVES` line carried one entry that was not harmless:

```
avm2/getter_different_namespace_setter: pass -> ruffle_matched
```

`pass` and `ruffle_matched` are both effective passes, so the corpus
counter did not move and no regression check fires. But the two statuses
mean opposite things about correctness: the test had been matching
`output.txt` (**Flash**) and was now matching `output.ruffle.txt`
(**Ruffle**) — and its `test.toml` carries `known_failure = true`, i.e.
upstream knows Ruffle gets it wrong. The "last match wins" shortcut had
turned a Flash-correct test into a Ruffle-bug-compatible one.

**A `pass -> ruffle_matched` move is a REGRESSION in disguise whenever the
test is a `known_failure` upstream.** It costs nothing in the score, so
nothing flags it; the only defence is reading the OTHER STATUS MOVES line
and asking, for each entry, which oracle each side was matching. (This is
the mirror image of the `known_failure upstream = Ruffle NOT the oracle`
lesson: there it stops you *trusting* Ruffle's output, here it stops you
*drifting into* it.)

Better still, the answer was written down in advance. The same
`test.toml` says:

> Correct handling requires per-vtable lookup; with flattened vtables,
> overridden traits would need to be hackily promoted ahead of inherited
> traits.

That is a precise description of the shortcut *and* of why it fails —
sitting in the config file of the test the shortcut breaks. **Before
implementing a resolution-order rule, read the `test.toml` of every test
that exercises it, not just the one you are fixing**; upstream comments
its known-hard cases where the failure will happen, not where the fix
goes.

The fix (§8.4) compares `defining_class` depth instead of entry index.
Under it, `getter_different_namespace_setter` is a full **`pass`** —
Flash-correct, and strictly better than Ruffle, which still fails it.

### 8.6 Method notes

- **`runtime_error` is a 7-element population that self-describes.** See
  §8.2. Compare with the ≤5-line diff window, which is 102 rows of text
  you have to interpret.
- **Re-measure a "dead" clustering key every session.** Session 4's key
  went 9 -> 0 -> 9. Beliefs about which axis is mined out go stale exactly
  as fast as the candidate list regenerates.
- **The perf shape of a widened lookup matters more than the widening.**
  Removing the `!mn_public` gate put `avm2_vtable_find_mn_named` on the
  dynamic-property path for *every* `obj[expr]`, and it was written as a
  find-per-namespace loop — 7-9 hashes and 7-9 bucket walks for one
  bucket's worth of work. It was rewritten to hash once and walk the
  bucket once, testing each same-name entry against the whole set, before
  the gate was widened. (Same shape as §7.6's eager-`snprintf` trap: fix
  the cost before you multiply the call count.)
- **Instrument the vtable BUILD, not the lookup.** `property_priority_chained`
  looked like a lookup-order bug and is one — but the fact that made it
  legible was a four-line probe at the trait-append site printing the ns
  KIND of each entry. It showed `field1` internal/`field2` public in the
  base and the reverse in the subclass, which is the entire test. Guessing
  from the read side would have suggested "the subclass override didn't
  replace", which is false — there was never anything to replace.
- **Strip probes with a targeted edit** (§7.6's lesson, applied): the
  probe and the real fix were both in `avm2_class.c`, and a
  `git checkout` would have taken both.

### 8.7 Taken and deliberately NOT taken

Reached but not finished, and why — all still on the board:

- **`avm2/verify_typecheck` (+ case 3 of `avm2/rtqname_not_namespace`, +
  `avm2/scope_optimizations`)** all want the same missing thing: a
  **static type lattice in the ABC verifier**. `verify_typecheck` wants
  #1058 for `lookupswitch` on a Number, #1051 for `getslot` through a
  `CoerceA`'d value and #1026 twice for a slot index past `slotCount`;
  `rtqname_not_namespace` case 3 passes a REAL Namespace that has been
  `CoerceA`'d to `*`, which avmplus rejects at verify time on the static
  type alone. This is a genuine feature, and its failure mode is
  dangerous in a way the others are not: the rule is "throw when the
  operand is not PROVABLY typed", so any gap in our inference becomes a
  spurious #1058 on working code. Size it as its own arc, with the
  conservative direction settled first.
  (`rtqname_not_namespace` still improved 0/12 -> 9/12 and left
  `runtime_error`.)
- **`avm2/supercalls_weird`** — `super.hasOwnProperty(...)` in a SCRIPT
  init. Flash prints `true`; we (and, reading `activation.rs`
  `bound_superclass_object: None` plus the `type_aware.rs` `CallSuper`
  arm, Ruffle) throw #1035. The site is shared with the condition
  `array_access_interpreter` pins, so it is exactly the brief's "never
  widen a condition" trap. Needs evidence about what avmplus binds as a
  script init's class before touching it.
- **`avm2/getouterscope_two_classobjects`** — two causes (`null` vs
  `undefined` on line 1, and a `#1065 field` after line 9), so the
  MultinameL fix alone cannot land it.

Everything in §5.5, §6.6 and §7.7 still stands, minus
`property_priority_chained` and `e4x/Regress/regress-524214` (shipped).

## 9. Session 7 (2026-07-31/08-01) — the parallel fan-out: +24 vs +21 predicted, ONE predicted regression

Baseline `46dcf3a06` (4129/4424) → **4153/4424 (93.9%)**, CI `30679378384`
(graphics/`categories=full`, success). avm2 1078→**1095** (+17),
from_avmplus 1545→**1553** (+8), visual 138→137 (−1). Histogram:
output_mismatch 292→268, ruffle_matched +1 (a GAIN —
`uncaught_errors_stringified`), runtime_error/recomp_fail flat, OTHER
STATUS MOVES: **zero** (no disguised `pass → ruffle_matched`).

**Method: two-wave multi-agent fan-out, run in one evening.** Wave 1 = six
parallel read-only diagnosis/scoping agents (triage regen, verifier-lattice
scoping, pixel viewport, two singles deep-dives, fonts + uncaught re-measure).
Wave 2 = seven parallel implementation agents in ISOLATED WORKTREES, each
delivering a patch + canary report; patches applied to master serially with
per-patch headline re-verification, one trivial conflict, one combined CI run.
Eight commits `77bb5e660`..`73c786e3f`.

Landed: child-movie font tables (+2) · activation class /
`with(primitive)` box / callstatic scope (+3) · e4x prefix minting /
parseFloat SWF≤10 / per-depth tag queue / String AS3 keys (+4) ·
setClipboard #2007 / Fixed16 saturation / root-class binding (+3) ·
uncaught-error re-land bundle (measured net +4 in isolation) · viewport-size
offscreen capture (trace +0 BY DESIGN — image-axis measurement fix) ·
WTF-8 string storage (+5). Also: the ABC-verifier type-lattice arc is
SCOPED (`abc-verifier-type-lattice-arc.md`, +2 predicted, conservative
direction settled).

**The regression is the predicted one**: `visual/definefont4`
pass→output_mismatch — a 0-byte-silence test now printing the #1009 the
re-landed tracing surfaces; the root cause is a TLF compose invariant
(`TextFlowLine.getLineLeading` walks past the paragraph's leaf chain),
diagnosed in the bundle report and owned by a future TLF arc. The bundle's
OTHER predicted regression (`away3d_advanced_shallow_water_demo`) did NOT
materialize — it is a full pass on the merged tree: a sibling wave-2 patch
(most plausibly the root-class character binding; Flex `BitmapAsset` is a
child-SWF character class) closed the chain the bundle exposed in
isolation. **Cross-patch synergy is real: an in-isolation ledger is a
LOWER bound for a merged wave.**

### 9.1 Corrections to earlier sections (measured this session)

- §5.5 `issue_8630_placeremoveplace{,_scriptremove}`: NOT "TextField-bounds
  × timeline" — no TextField exists in either SWF. It is same-frame
  place/remove queue semantics (Ruffle `QueuedTagList`: a queued Remove
  annihilates an earlier queued Add). Shipped, minus the
  `transformed_by_script` gate (one line of `_scriptremove`, deferred).
- §5.5 `parse_float_swf10`: NOT "three causes" — one cause (SWF≤10
  accumulator span, bugzilla-513018), 4 lines. Shipped.
- §5.5 `scopes_dont_cache/order-{1,2}`: shipped in session 6, stale entry.
- §6.6 `hasOwnProperty`: NOT the ES3 prototype surface — String's instance
  methods were public-keyed instead of AS3-keyed. Shipped.
- §8.7 `supercalls_weird`: the "shared condition with
  `array_access_interpreter`" trap DOES NOT EXIST (that test contains no
  super opcode; the code comment at the throw site is a misattribution).
  Real remaining blocker: `super.prototype` in a STATIC method needs a
  class-side super chain. Script-init super binds to Object (~8 lines,
  ready) but does not land the test alone.
- Session-1's astral-plane verdict ("WTF-8 storage or pair-combining in
  every decoder — not polish") was HALF wrong: the decoders were already
  WTF-8-shaped; only six `cp=0xFFFD` discard sites + a concat seam-fold
  were needed. Population was 5 direct (+`stylesheet` as a bonus), not 2.
- The uncaught-error ledger goes stale on BOTH sides: the "+2" gain had
  been carried unmeasured since 2026-07-26 and was really +6; blocker 1
  (away3d #1065) was just a missing `ContextMenuEvent`.

### 9.2 Still open with diagnosed causes

From §8.7 minus shipped: `supercalls_weird` (class-side super chain),
`verify_typecheck` + `rtqname_not_namespace` case 3 (the scoped
type-lattice arc), `scope_optimizations` (static early binding — NOT the
lattice arc). New from session 7: `_scriptremove` final line
(`transformed_by_script`, six setters, wide blast radius); `avm2/bom`
(three causes: BOM strip, UTF-16 decode, URLVariables order — the last is
dispositioned RUFFLE_VS_FLASH); `e13_1_2_1` (XML 1.0 name-char tables,
the predicate exists TWICE); `avm1/form_loader_encoding_{2,3}` (AVM1
legacy charsets); main-movie root-class binding + child non-root bindings
(riders follow-up); embedded Flex `BitmapAsset` chain (away3d's next
error if the character-binding synergy ever regresses).

## 10. Session 8 (2026-07-31/08-01) — second fan-out: +23, one reverted trap

Baseline `1c7c23761` (4153/4424) → `07c119c50`: **4176/4424 (94.4%)**, CI
`30687131663` then corrective `30688965712` (both graphics/`categories=full`,
success). avm1 687→690, avm2 1095→**1107** (+12), from_avmplus
1553→**1560** (+7), from_shumway 196→197. Histogram: `pass` 3909→3932,
`output_mismatch` 268→246, **`runtime_error` 2→1**, `ruffle_matched` flat
at 244, `recomp_fail` 1. **Final: zero regressions, zero other status
moves.** Raw agent reports: `session8-fanout-reports/`.

**Method: the §9 two-wave fan-out, repeated.** Wave 1 = five read-only
diagnosis agents (triage regen + the §9.2 board) with the already-scoped
lattice arc's implementation launched immediately alongside; wave 2 = seven
implementation agents in isolated worktrees. Eight patches applied to
master serially (`3e36127c9`..`3ebcb54f1`), one trivial conflict
(`ul_set_data` — resolved to exactly Ruffle's shape: `strip_bom` feeding
the URLVariables ctor), one combined CI, one corrective commit.

### 10.1 Ledger (23 = 22 predicted-and-landed + 1 CI-only rider)

| Patch | Commit | Yield |
|---|---|---|
| AVM1 charsets (B11: cp1252 + generated Shift-JIS, Ruffle detection order) | `3e36127c9` | +2 |
| escapeMultiByte/unescapeMultiByte + URLVariables ctor/decode | `daaee588b` | +2 |
| E4X name-parts C1 (ns KIND for any-ns; attr/any-name on write+delete; two version gates) | `9c67067f2` | +7 |
| super in script inits / class-side frames + class-object scope fallback | `7ccca2c18` | +1 |
| XML 1.0 name tables (both predicate copies) + shared `avm2_strip_bom` | `b74aa0a82` | +1 |
| ABC verifier type lattice, Stage 0+1 (arc doc shipped as scoped) | `a835b09fb` | +2 |
| `transformed_by_script` gate (10 set sites, not the brief's 6) | `2a7715b7c` | +1 |
| C2 singles + C3 file-level ABC error path | `3ebcb54f1` | +7 → **+6** after revert |
| TextField-gate revert | `07c119c50` | +7 recovered, −1 given back |

CI-only rider: `avm2/superinterface_instanceof`, carried by the
superinterface cache-lifetime fix — outside the ≤5-line window, as in
every session (§4.5's rule holds: the near-pass list is a lower bound).

### 10.2 The one regression event — chasing an already-dispositioned test

CI `30687131663` scored +17 with **7 regressions**, all from one line of
the C2 batch: gating the `TextField` global to SWF7+ to win
`avm1/native_objects_swf6` line 56. Seven tests (avm1 `globals_swf6`,
`textfield_props_swf5/6`, `focusrect_property_swf6`; gnash `TextField-v5`,
`toString_valueOf-v5/v6`) pin the global as `[type Function]` and
`new TextField()` as an object at v5/v6. The test the gate won is
`known_failure` upstream, its Flash capture contradicts the Ruffle-passing
`textfield_props_swf6` on the same behavior at the same SWF version — and
this project had **already dispositioned it**: `ACCEPTED_DIFFS.md`
Category 2 carries the exact entry and the test sits in
`ignored_tests.txt`. Full revert (`07c119c50`); the narrow middle ground
(gate construction only) was measured and scores WORSE than reverting
(5-of-7 recovered vs 7-of-7).

**New brief rule (memory `triage-check-accepted-diffs-first`): every
triage row and every wave-2 brief checks its targets against
`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md` and
`ignored_tests.txt` before pricing** — the near-pass regeneration reads
`results_graphics.json`, which has no memory of dispositions.

### 10.3 Wave-1 findings worth keeping

- **The near-pass list is almost a true inventory now**: 78 candidates,
  refilled by exactly ONE row after s7's +24 (prior sessions refilled
  5–10). `error_signature` is fully dry (max group 1). The paying keys
  were structural: an E4X ops-layer cluster, a `--dump-abc` corpus census,
  and the `runtime_error` population (still the cheapest read).
- **`avm2/bom` can NEVER pass** — no `output.ruffle.txt` exists (Ruffle
  passes it) and 3 lines are URLVariables enumeration order (fixture is
  `lastName`-first; ours is insertion order = Flash). Dispositioned in
  RUFFLE_VS_FLASH_DIFFERENCES.md; ceiling measured at 6/9. The adjacent
  find (`escapeMultiByte` + `URLVariables.decode`) was worth more than the
  target.
- **Two session-7 sizings were wrong in opposite directions**:
  `supercalls_weird` needed no "class-side super chain" (Ruffle binds a
  static frame's super flatly to `Class` — ~20 lines, one file), while
  `transformed_by_script` had TEN set sites, not six.
- Root-class binding riders: **NO-GO measured** — zero corpus tests
  blocked; main-movie binding would regress the 177 from_avmplus tests
  whose expected output ends at the #2023 throw. New finding filed:
  `class_for_char`'s child arm resolves via the ROOT domain scope, the
  larger half of `loader_duplicate_class`.

### 10.4 Left on the board

§9.2 minus shipped, plus: `e12_1` (needs recompiler `SETS_DXNS` + an
oracle ruling on single-arg `new QName(n)` DXNS capture — Ruffle does NOT
capture, avmplus does), `scope_optimizations` (lattice Stage 3, separate
arc), C3.3 (trailing #1065 after file-level VerifyError: net 0, wins
`verify_method_info_duplicate` but demotes `verify_method_info_oob`),
`loader_duplicate_class` (3 independent fixes incl. the child-domain
resolution above), and the stale `avm2/ignored_tests.txt` bucket
(`url_vars`, `url_loader`, `urlrequest` listed but passing — prune pass
wanted).


## 11. Session 10 (2026-08-01) — the DUAL-AXIS fan-out: trace +12 exact, pixels +45 vs +34

Baseline `feb8882b0` (4176/4424 trace, 172/566 pixels) → `c4496a4c8`:
**trace 4188/4424 (94.7%)**, **pixels 217/566 (38.3%)**. ONE CI run
`30713776612` (graphics/`categories=full`/`images=true`) graded both axes.
**Zero regressions on either axis, zero other status moves.** 8 commits
`734a0fc2f`..`c4496a4c8`; raw reports `session10-fanout-reports/` (8 wave-1
+ 8 wave-2). First session drawing targets from BOTH boards
per the user's dual-axis direction; the two-wave shape held unchanged.

### 11.1 Ledger

Trace +12: hygiene (heavy_tesselation recomp-timeout 30→300s, e12_1 DXNS
×2 sites) · symbols (B5 AS3-tag suppression, B8a never-placed-binding gate)
· singles (StyleSheet ×2, StaticText.text ×2, hittesting full-pass +
getobjectsunderpoint rider) · taxonomy (toLocaleString_rt→ruffle_matched,
Error1081 full pass). Pixels +45 (predicted +34; 11 riders): text 14+
(edittext_selection_leading ×12 + autosize riders) · phase-cxform 13
(border_transform 4, cxform 5, attached-bitmap 3, loop-phase 1) · button 5
· blend 2 flips + 15 band moves 56–96% · riders incl. acid-blend-2 ×2 more
frames, define_font_glyph_table_overlap, acid-child. Band accounting:
improved 65 / worsened 22, ALL worsened fail→fail (caret_empty hairline
family +36 channels from the device-box corner-pixel trade; place_object_test
+73%; cab/masks .03/.04 ~+70% — flag for the next pixel board).

### 11.2 Method notes (what changed vs s7–s9)

1. **The near-pass well is a closed inventory**: 59 candidates, ZERO refill
   after s8's +23. Both error-string keys stayed dry; the paying key was
   capability-gap × oracle-conflict cross-checking.
2. **Wave-1 evidence-finishing agents now REFUTE briefs, profitably.**
   Four brief errors caught before they cost anything: PerspectiveProjection
   was NOT an oracle conflict (test.toml tolerance already covers it — back
   in the live pool); C3.3's "net 0" hid a ruffle_matched demotion; the B7
   GC-retry probe was use-after-free by construction (locals are invisible
   to the collector — scoped as the "GC during long loops" arc, do NOT
   re-file as polish); B6's diagnosis was inverted (state children must be
   ADDED to getObjectsUnderPoint, and reporting the SUBTREE beats Ruffle).
3. **The 8-patch serial merge hit ONE textual + ONE semantic conflict, same
   file**: text's alpha-only `avm2_text_slots` vs phase-cxform's full
   `avm2_alloc_cx_slot` (resolved: full cxform wins), and button's new
   `avm2_render_node` call site vs phase-cxform's widened signature
   (compile_fail at merge, fixed by passing `&node_cx`). When two patches
   restructure the same walk, headline-re-check EVERY patch pair that
   touches it — the per-patch checks caught it immediately.
4. **Graphics slices priced by mechanism flip cleanly; near-pass counts do
   not.** simple_loop_test "5 flips" was 1 flip + 4 demotions-to-hairline
   (the phase fix was still right — the residue is now single-mechanism).
   Blend "12 of 23" was 2 flips + 15 near-total band moves: `max_outliers=0`
   means only zero-residual flips, and the residual is ONE pre-existing
   extra element inside blend groups (visible pre-patch; the follow-on lead
   that likely unlocks the whole directory).
5. **Trade recorded**: EditText device-box now draws its bottom-right corner
   (3 border_transform flips) at the cost of edittext_device_transform_
   small_rotation sitting at exactly 11/11 outliers and caret_empty's
   hairline excess rising 48→84. Revert = `line_rect = 0` in the device_box
   branch of `textfield_render_cb`, cost −3 flips.

### 11.3 Left on the board

Trace: `graphic_linkage` (script-`new` vs timeline instantiation
discriminator in `display_native_init` — own batch, high-traffic arm);
B8b lazy script inits (rewrite of the step-3/4 contract the from_avmplus
drivers pin); B9 device-font test.toml TTFs (scope first); B7 → the GC arc
(shadow stack vs conservative C-stack scan, w2-taxonomy report §B7);
PerspectiveProjectionClass (~2 mechanisms, +1); loader_duplicate_class
cause C; heavy_tesselation is now a pixel candidate.
Pixels: blend residual extra-element (one mechanism, likely most of
`visual/blend_modes`); masks (4 defects, A=stencil-union gating 2 flips
HIGH risk, full slice needs the AVM2 T7 arc — wave1-gfx-masks report);
`avm2_button_scroll_rect`/`bitmapbuttons` (need AVM2 clipping / bitmap
fills); button2 states ×3 (Fix B landed, needs mouse-driven repro);
cacheAsBitmap = CARRIER (7 real cmps = alpha-mask path + size gates, pair
with a Filters arc); cab/masks .03/.04 + place_object_test worsened bands.

## 12. Session 11 (2026-08-05) — dual-axis fan-out #3: trace +17, pixels +40, zero regressions

Baseline `c4496a4c8`-run (4188/4424, 217/566) → `6de650432`: **trace
effective 4203/4422 intersection (+17 vs +15 predicted, 0 regressions, 0
other status moves)**, **pixels 257/566 (45.4%, +40, 0 regressions, bands
improved 73 / worsened 0)**. ONE CI run `31075033086`
(graphics/`categories=full`/`images=true`). 8 wave-1 + 8 wave-2 Opus agents,
9 commits `bed9d894b`..`6de650432` + results merge. Reports:
`session11-fanout-reports/`.

### 12.1 Ledger

Trace +17: triage-batch +7 (B1 malformed-sibling IOError ×2, DocType case,
constructsuper #1009, System.exit #2017, B4 dual load-cancel queues, B5
SWF≥17 API gate) · b9-fonts +4 (device-font TTF trio + scale_x rider; 2 more
at known_failure ceiling → ruffle_matched) · display-singles +2
(graphic_linkage, PerspectiveProjectionClass) · b8b-lazyinit +2 (doabc
normal+goto; delayed_symbolclass 16/28→2/28 blocked on frame-1 LAZY,
out of charter) · 2 unattributed riders. Pixels +40: quality-MSAA 24
(17 predicted + 7 sweep) · caret_empty ×12 · button2 ×3 · acid-clip 1
(masks clobber fix). masks excess 248261→1686 (defect-A × MSAA combined,
better than either alone). New `regression/mask_sibling_union` (first mask
regression test, byte-exact golden).

### 12.2 Method notes (deltas vs s10)

1. **The dominant pixel mechanism was found by CONVERGENCE**: three
   independent wave-1 agents (blend, masks, clipping) each hit the same
   wall — goldens exported at `quality="low"` = 1-sample vs our hard-coded
   4× MSAA. The "one extra element in blend groups" premise from s10 was
   REFUTED; the probe pixel was an AA fringe saturating under `add`.
2. **Wave-1 refutations again paid before implementation**: GC arc (census
   = 1 test, and even a perfect collector converts it OOM→timeout — real
   owner is a dependent-string arc, 2-3 sessions for +1, not scheduled);
   B8b "arc-sized rewrite" (real blast radius: 9 SWFs corpus-wide);
   loader_duplicate_class cause C (only pays as full A+B+C batch); CAB
   standalone (6 of 7 cmps are mask-arc debt); bitmapbuttons (whole-stage
   AVM2 static-bitmap upload gap, not a button bug).
3. **A stalled wave-2 agent was revived by SendMessage** after ~105 min
   idle (detached background sweep = no wake-up ever). Probe first
   (transcript mtime + ps + deliverables), then message with "resume
   actively, cap the sweep, finalize" — it delivered +24 within the hour.
4. **Serial merge: 8 patches, ZERO textual conflicts** (agents were told
   siblings' file lists up front and kept edits localized/wrapper-shaped);
   the quality×masks `render_webgpu.c` semantic pair was CI-ruled clean.
5. **Upstream corpus drift observed at CI**: download_tests.sh removed
   `avm2/av_networking_params` + `av_tag_data` (passing locally from cache)
   and added 4 new failing tests (`av_classes`,
   `avm1movie_addcallback_call`, `flash_trace`, `groupelement_text`) —
   denominator moves, not regressions.

### 12.3 Left on the board

Trace: triage's B2 verifier method_info is a hard oracle conflict
(verify_method_info_oob pins the opposite — leave); B6 morph hit-test is
recompiler-side (stroke tessellation missing from shape_data); the 4 new
upstream tests; `edittext_device_transform_layout` (bounds.x_min+GUTTER
layout offset, wide blast radius, ~+1); number→string tie-break
(half-away-from-zero vs tie-to-even; corpus-wide risk, isolated by the PP
work, 14 lines in avm2/perspective_projection); gap 6-10 shoulder (37
tests); dependent-string arc (bug_483783, 2-3 sessions, +1 — not
scheduled). Pixels: masks residual now single-mechanism c_small (1686) —
next mask defects B/C/D per wave1-gfx-masks; `avm2/mask_reapply` tag-path
no-op mask (new unowned bucket); scrollRect stencil sketch ready
(wave1-gfx-clipping §8) but needs its flips unblocked; blend_modes capped
at a_epsilon by sub-pixel ties (do NOT scope); F5 layer groups + F7-AVM2
remain; AVM2 static-bitmap upload (bitmapbuttons blocker) unscoped.

## 13. Session 12 (2026-08-06) — dual-axis fan-out #4: trace +25, pixels +28, zero regressions

### 13.1 Ledger

Closeout run `31090651530` at `1f8396f57` (10 commits `2ed78f692`..`1f8396f57`,
results merge `9c7a2dcb2`): trace effective **4204 → 4229 intersection (+25,
vs ~+25 predicted)**, pixels **258 → 286/567 (50.4%, +28)**, **zero
regressions and zero worsened bands on both axes**, 38 bands improved.
7 wave-1 + 9 wave-2 + 1 rider + 1 reconciliation agent; 11 patches, reports
in `session12-fanout-reports/`.

Per-patch trace yield: w2-xs +8 (8/8 exact-pin singles), w2-errframes +8
(T1 stack-trace frames, 41% of live mismatched lines), w2-avclasses +5,
w2-avm1movie +1, w2-singles +2, w2-textblock +1 eff. Pixels: bitmapmax+masks
pair +23 predicted → acid×16 + acid-clip-3×2 + acid-color/image/big +4 +
mask_reapply, plus riders pixelbender_effect_twirl, acid-textfield-scroll,
flash_text_TextField2; autosize +2 (auto_size/width at exactly 18=limit,
leading_define_font). Filters pair: 0 flips by design, 12/13 comparisons
-17..-93%, two engine-wide bug fixes (uniform ring: writeBuffer-vs-Submit
ordering made every blur single-axis; radians-vs-degrees filter angles).

### 13.2 Method notes (deltas vs s11)

- Mid-flight scope collision (bitmapmax and masks both implementing AVM2
  clipDepth) was resolved by SendMessage: warn the still-running agent, then
  delegate the reconciliation to it (superset merge, union canary). Cost one
  extra agent-cycle; caught before merge by `git apply --check` stacking.
- Rider-on-top-of-sibling-patch worked: filters-inner applied
  w2-gfx-filters.patch in its worktree, committed locally, delivered a
  stacked diff. Pair landed as one commit (land-together-or-drop).
- The isolation guard can block worktree agents from writing deliverables to
  the main tree — copy them out of `<worktree>/SWFRecompDocs/...` instead.
- "s11 worsened textblock_line_changes" was refuted by bisect: upstream
  REWROTE the test (expected_lines 158→282). Gap-histogram diffs must also
  diff expected_lines; stale local mirrors report the old numbers.
- Wave-1 refutation rate stayed high and profitable: F5 (0 flips), fonts
  "cheap head" (unit error: channels ≠ comparisons), acid "gradient ramp"
  (actually missing AVM2 clipDepth), B6 morph "recompiler emits it" (only
  into the AVM1 tag stream), filters "~11 cmps" (budgets vs residual).

### 13.3 Left on the board

Trace: T7 describeType is the largest mechanism (24 live tests, ~6800
lines) — needs a scoping doc, not a patch. loaderinfo_quine (1004 lines,
LoaderInfo.bytes). ImportAssets fetch-queue one-liner (+1, action.c:34563
entry==NULL early return). mixed_avm/avm2_loads_avm1_v9 one line from pass
(needs AVM1 child execution, dual-VM arc). advance_u16 recompiler s16→u16
(solved in w2-gfx-autosize-report §7, unshipped: generated-ABI reach).
C3b MethodInfo-N naming needs ABC debug_name modeling (recompiler item).
s11 hygiene never applied: ignore-list recs for avm2/loader_applicationDomain
+ avm2/swz (need ACCEPTED_DIFFS entries first). Pixels: mask defect B (s10
design has a UAF — redesign), defect C AVM2 scrollRect half (~20 lines,
w2-gfx-masks v1 report §6.1); char-id-0 "empty depth" sentinel blocks all 5
embedded-video tests (h263 blank + VP6 worth 0 until fixed, 21 tag.c sites);
acid-blend-2 B-channel halving in blend composite (may re-open capped
blend_modes rows); filters struck from flip leads (shared low-amplitude
render residual vs 0-18 budgets); simple_shapes/masks 1686 = rasterizer tie
at MSAA=1, reclassify hairline_edge_drift, do NOT re-book as mask work.

## 14. Session 13 (2026-08-06) — dual-axis fan-out #5: trace +8, pixels +15, zero regressions

Commits `8fdda9ca9..fb36ba110` (9 patches + hygiene, 10 commits), results
merge from run `31130292354` (graphics/full/images=true). Trace effective
4229→**4237** (+8, intersection 4427, histogram clean — no new crash
statuses). Pixels 286→**301/567 (53.1%)** (+15, denominator stable).
6 wave-1 + 9 wave-2 + 1 hygiene agent; reports in
`session13-fanout-reports/`.

### 14.1 Ledger

Trace (+8): describeType P0-P2 (+3: describe_type_basic, describe_type_json,
bug_539328 ruffle_matched); action-order rider (+2: remove_different_level
level-root enterFrame eligibility, action_execution_order_test via
subtest-scoped known_failure harness fix); trace singles (+3:
loaderinfo_quine root_swf_bytes weak-symbol embed, avm1_non_swf_import
tag_init preload fetch, error_stack_trace all-four naming rules).

Pixels (+15): video VP6 family ×4 (char-id-0 recompiler alias + BT.601
exact YUV); curve-subdiv ×7 (acid-blend-2 output.15 + timeline_loop ×6);
pixel rider ×2 (release_swf17 getStackTrace null, drawing_api/cursor
moveTo/lineStyle path-split); advance_u16 ×1; cache_as_bitmap/masks
output.07 ×1 (mask work bonus). avm2_button_scroll_rect landed a_epsilon
(9 excess) — predicted flip became near-pass. Band moves: 15 improved
(text_field_mask −100%, h263 −98%, scroll_rect_mask −97%,
displayobject_scrollrect −94%, cache_as_bitmap/masks family −75..−95%,
netstream_play_flv −97%); worsened: simple_shapes/masks tie pair +56%
(c_small→c_small, dispositioned rasterizer tie, curve-geometry side
effect) and bevel family +6-7% (fail→fail, filters already struck).

### 14.2 Method notes (deltas vs s12)

- Wave-1 refutation rate was the session's defining feature: 8 material
  refutations before implementation spent anything (T7 "scoping" label
  collision + 2.6× line undercount; char-id-0 21-sites→56 killed the
  occupied-flag refactor; acid-blend-2 B-halving → single stray pixel →
  curve flattening; mask-B s10 pricing 2 flips→0-1; ImportAssets one-liner
  wrong layer; lroundf refuted empirically; output.26 chord-joint pixel).
- `refs/stash` is SHARED across worktrees — two agents popped each other's
  stashes (both recovered). Worktree A/B legs must use `git diff` +
  `git apply -R`, never stash.
- Curve-subdiv grading: local Dawn reproduced all 67 CI comparison numbers
  exactly (before leg), making local grading CI-fidelity for tests where
  local==CI-actual — check per test, don't assume either way.
- Detached-sweep stale pollers re-notify the coordinator repeatedly after
  agent completion; harmless, ignore them.
- Serial merge with per-patch headline re-check: 9 patches, zero textual
  and zero semantic conflicts (sibling-files-in-brief practice held).

### 14.3 Left on the board

Trace: T7 P3 (recompiler ABC metadata → describe_type_metadata, +1) and
P4 playerglobal descriptor slices (+3/+11/+6, arc-sized;
describe_type_native is the clean pilot); AVM1 tick-pipeline arc (test11:
per-clip EF+advance adjacency, 3 of 5 assertions — an arc, not a rider);
avm2_loads_avm1 needs AVM1-child-execution AND LocalConnection bridge (two
arcs). Pixels: vertex-placement defect at curve joints (acid-blend-2
output.26, spun out of curve-subdiv); bitmap-fill U-pinning
(acid-bitmap-fill 100k + acid-bitmap-draw_quality ×194k — biggest single
pixel lead); Equal/IncrementClamp stencil intersection (3 named
beneficiaries incl. displayobject_scrollrect residual 12382);
AVM1 scrollRect translate (scroll_rect_mask residual 11310, transform-
composition work); deblocking (MAX_EMBEDDED_VIDEO_STREAMS 8→16 + flags
byte + 559-line deblock port); hairline_edge_drift is ≥2 mechanisms —
splitter is "large-deviation DefineShape quadratic present", worth a
re-triage after curve-subdiv.

## 15. Session 14 (2026-08-12) — dual-axis fan-out #6: trace +28, pixels +9, zero code regressions

Commits `f552cf8af..bf585e448` (9 code patches + hygiene, 10 commits), CI run
`31647430265` at `bf585e448` (graphics/full/images=true), results merge
`b15b9cbdf`. Trace effective **4237 → 4269 / 4443** = intersection **+28**
(29 gains, histogram clean, runtime_error flat) + **+4 drift** on 16 new
upstream tests (denominator 4427→4443). Pixels **301/567 → 310/569 (54.5%)**:
+8 intersection flips + the new `regression/mask_nested_intersect` passing;
bands improved 7 / worsened 0. 7 wave-1 + 10 wave-2 agents; reports in
`session14-fanout-reports/`.

### 15.1 Ledger

Trace (+28 intersection, exactly the four patches' predictions):
describeType T7 P0 gate + P3 metadata + P4 pilot (+9); fuzz block AVM1
timeline-order — ASF_SORT_CAP depth-index-vs-count + unterminated
DefineSprite (+15, fuzz suite 14/30→29/30, both prior ruffle_matched rows
upgraded to exact pass); host-I/O bucket re-cost (+3); watch re-entry
unified counter (+2, ACCEPTED_DIFFS Cat 10 RESOLVED). Pixels (+9):
stencil Equal/IncrementClamp nesting model (6× cache_as_bitmap/masks +
regression/mask_nested_intersect); AVM1 scrollRect end-to-end
(scroll_rect_scaled); bitmap-fill content-size tiling (acid-bitmap-fill).
Band moves: deblocking 2 906 999→104 (−99.996%, filter ported, 11/12
streams byte-exact); displayobject_scrollrect 12382→10;
scroll_rect_mask 11310→42; netstream_play_flv 1654→44;
scroll_rect 18378→2056; simple_shapes/masks pair 2624→1738 (wrong→right,
disposition partially refuted, flagged for re-baseline).

### 15.2 Accounting corrections (vs the wave-1 audit)

- The "regression" `avm2/textblock_line_changes` (ruffle_matched→
  output_mismatch) is an upstream TEST REWRITE: 282-line fixture at
  baseline, 481 lines in this run — the s12 trap on the same test family.
  Zero code regressions both axes.
- The audit's "+9 free drift on 11 on-disk ungraded tests" was WRONG in
  detail: upstream de-duplicated those dirs (they never reached CI); actual
  drift was a new matrix3d/textblock batch, +4 effective of 16 new tests.
  The watch_special pair flips booked to nothing.
- Wave-1 refutation rate stayed the defining feature: fuzz "error-recovery"
  premise (actually timeline order), morph P1 "+7" (zero quadratics in the
  named tests), U-pinning label (padded-layer tiling), test11 "one defect"
  (three), stencil rider set, scrollRect rounding rule, board §5 stale
  dispositions (already applied). Board pricing survived contact at ~50%;
  mechanism GO/NO-GO verdicts survived at 100%.

### 15.3 Left on the board

Trace: T10-playerglobal-descriptor arc (13 all_classes rows, ~16.5k lines,
needs typed member registration); fuzz 16th row (`e152812e2cfc`, depth-1015
placement warning, +1 self-contained, canary set named in the fuzz report);
watch_virtual_property dispatch-ordering (+1, watch must precede the
virtual-setter walk); textblock_line_changes re-triage vs the new 481-line
fixture (arrived with textblock_releaselines + textline_raw_text_length —
likely one FTE mechanism); matrix3d batch (9 failing rows, one class —
biggest new cluster); action_order arc DEFERRED with full plan
(wave1-avm1-tick.md = diagnosis of record, pair with extend_test for +2
ceiling). Pixels: displayobject_scrollrect at 10 channels (1-sample edge
tie, budget 0 — lavapipe AA class); morph ratio plumbing (end positions
never reach the rasteriser); morph path-command pairing half (~40 lines →
avm1/movieclip_hittest_shapeflag); scale-aware tolerance leg B HELD
(re-measure at 2 twips; archived patch beside the morph report);
acid-bitmap-draw_quality = dynamic_bitmap_max size-gate decision (VRAM
17→67 MB per AVM2 movie); blend-layer alpha defect (acid-blend-2 output.26,
renderer, one-dump bisect); blur_fractional/blur_quality structural extra
ink (774k/821k, un-struck by hygiene); displacement-map trio.

## 16. Session 15 (2026-08-13) — dual-axis fan-out #7: trace +29, pixels +14, zero regressions

Commits `98c6f99bd..82ec2a359` (15 code/doc patches + header fix + results
merge), CI run `31748059158` at `3db858cbc` (graphics/full/images=true).
Trace effective **4269 → 4298 / 4443** (+29 intersection, 29 gains, 0
regressions, histogram clean; +3 bonus ruffle_matched→pass upgrades:
int/uint_toprecision, e15_7_4_7_1). Pixels **310 → 324 / 569 (56.9%)**:
+14 flips, 0 regressions, bands improved 13 / worsened 0, drift 0/0.
7 wave-1 + 12 wave-2 agents; reports in `session15-fanout-reports/`.

### 16.1 Ledger (trace +29)

watch-on-addProperty (+1, full pass vs Flash oracle; watcher never fired at
all on addProperty props — un-ignored from ignored_tests.txt, entry had no
backing disposition); Matrix3D member semantics (+9, one file, missing-class
premise refuted); smalls (+3: asbroadcaster MOVIECLIP receiver,
sub_super_same_field static early-bind, number_convert_edge_cases);
AVM1-child-under-AVM2 timelines (+3 of a 14-row cluster that proved to be
3 unrelated problems); textblock FTE (+4 incl. visual/definefont4 TLF free
rider); T10 playerglobal descriptors slices 1-5 (+8 exactly as priced);
fuzz 16th row (+1, fuzz 30/30, block closed).

### 16.2 Ledger (pixels +14)

s16→s32 shape-delta sign fix (acid-blend, acid-blend-2.26 — 17-bit SB
fields, mis-signed |Δ|≥32768); capture cap 16→32 (acid .17/.18);
hasPlayingSprites recursion (acid-video .10/.20); lossless2 format 4
(+ grow-on-Z_BUF_ERROR); blur plumbing + budgeted bitmap capacity
(blur_fractional, bitmapdata_filter_sourcerect) + displacement CPU rider;
runtime lyon/Levien flattening leg R (displayobject_mask, loader_events ×2);
free rider avm2_button_state. Band moves: applyfilter_blur −94%,
blur_quality −80%, morph_test1 −76% ×5 (OOB fix + stroke end-colors).

### 16.3 Incident of record

First closeout run `31746548765` was POISONED: `git add -u` silently
skipped the new `curve_flatten.h` created by `git apply`, so every CI test
compile_failed (0 passes all suites). The WASM link-smoke job caught it;
results never merged; header committed at `3db858cbc`, re-dispatched clean.
RULE: after `git apply`, stage by name including NEW files from
`git apply --stat`; never bare `git add -u`.

### 16.4 Left on the board (session 16)

Trace: all_classes/display 6-row surface (+6 all-or-nothing; slices 1-5
built every mechanism except the declaredBy/defining_class re-point shape,
which the s15 XMLDocument fix now demonstrates); AVM1-child remainder
(depth constant −77824 for Loader-loaded AVM1 roots — derive from Ruffle's
depth model, 2 of 4 remaining lines on avm2_loads_avm1; mouse/focus
bridging rows are a separate cluster); number_convert_errors (int/uint
primitive dispatch, structural); bug_483783 NO-GO stands (arena genuinely
99.998% full; third-arc option: avmplus dependent strings, needs GC
single-block-free change); gnash array/MovieClip v6-8 and eforin NO-GO
evidence recorded in wave1-trace-board.md; action_order re-priced to +1
with a named −1 (test12 onLoad gate tag.c:772-788) — DEFER stands;
ignored_tests.txt "Permanently accepted diffs" heading: 6 remaining names
have no backing disposition entries (w2-watch-order-report.md §6) — audit.

Pixels: flattening leg C HELD for a SOLO dispatch (recompiler lyon port:
masks 1738→1497, −25-38% vertices, bounds shrink ~1 twip trace effect —
never bundle; patch archived in session15-fanout-reports/); AVM2 filters
Route 2 = offscreen/composite arc (~250-350 lines, five traps incl.
object-sized FilterSource vs our stage-sized textures); morph
end-color per-character offset (tag.c:6966 + avm2 twin :3197 index from c
not morph_end_color_start+c — needs tagDefineMorphShape signature change);
simple_shapes/masks 0.62px offset is a scale/transform defect (slope
differs — NOT flattening, NOT the old disposition); acid-large OOM (2.52GB
VK_ERROR_OUT_OF_DEVICE_MEMORY — dynamic-layer budgeting arc);
bitmapdata_applyfilter_blur residual is device-font text; morph pixel
ceiling +1 gated on gradient morph fill (tranche); cache_as_bitmap/morph
(2832, max diff 1) → disposition. Method note: on max_outliers=0 rows band
count is not monotone in correctness — compare changed-region bbox +
colour histogram vs golden before ruling NO-GO.
