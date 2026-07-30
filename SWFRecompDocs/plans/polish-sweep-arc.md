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
