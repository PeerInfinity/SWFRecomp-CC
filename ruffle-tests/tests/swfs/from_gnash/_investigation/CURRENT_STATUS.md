# Gnash Test Suite Status

Last updated: 2026-06-18 (pending CI — newly-synced upstream tests triaged; see
`_investigation/NEW_UPSTREAM_TESTS_TRIAGE.md`. `misc-ming.all/gotoFrame2Test`
(new, NOT known_failure): timeout → **PASS** via a self-goto guard in
`swf_core.c::ng_executeGotoCatchUp` — a `GotoFrame2 play=1` whose target is the
frame whose own script is executing (`gotoAndPlay(_currentframe)` + `Stop()`) no
longer replays/re-queues that frame's script (it was re-issuing the goto →
unbounded loop). `misc-swfc.all/gotoFrameFromInterval` (timeout) and
`gotoFrameFromInterval2` (output_mismatch) are new `known_failure`s with a
distinct cross-frame gotoAndPlay-from-callback over-advance bug — still open,
see the triage doc. No regressions: AVM1 goto battery 7/7, misc-ming goto/loop
battery 8/9 effective (lone mismatch `action_execution_order_test5` byte-identical
with/without the change).)

Last updated: 2026-05-29 (pending CI — `getvariable-v5/v6/v7/v8` (actionscript.all)
output_mismatch/ruffle_matched → PASS (+4, v6 was already RM). The fix makes a
`_level0` segment resolve to `undefined` ONLY when it appears as an INTERMEDIATE
segment of a getVariable dotted-path walk (`this._root._level0.variable_in_root`
→ Flash returns undefined; gnash getvariable.as:105, whose comment notes "this
fails in all versions from 5 to 8"). Direct/final member access still resolves
`_level0`/`_level` to root (`_root['_level0']`, `_root._level`; gnash
MovieClip.as:149/153/600/601, avm1 stage_object_children). Two paired changes in
`SWFModernRuntime/src/actionmodern/action.c`: (1) `resolveFlashPathToMC`'s
non-first-element branch `return NULL` for a `_level0` segment (so the
GetVariable dotted-path handler's primary resolve fails and it falls to the
per-segment `GetVariable`+`GetMember` walk); (2) that walk sets a new global
`g_path_walk_level0_undef = 1` around its INTERMEDIATE-segment GetMember calls,
and `actionGetMember`'s MOVIECLIP `_level0` (level_id==0) branch returns
undefined when the flag is set, else root as before. The flag is clear for the
primary/final-prop GetMember and for explicit bytecode GetMember, so direct
member access is unaffected. `_root`/`_parent` (real MC properties) resolve
nested; bare/first-element `_level0` and `_levelN` (N>0) unaffected.
**First attempt (commit 921eeb06c) wrongly made `actionGetMember` return
undefined for `_level0` unconditionally** — that regressed avm1
`stage_object_children` (pass→mismatch) and gnash `MovieClip-v5` (RM→mismatch,
plus line drops in MovieClip-v6/v7, TextField-v6/v7/v8). The flag-scoped
follow-up restores all of those. No regressions across a 13-test AVM1 path/level
battery + gnash MovieClip-v5 (RM, restored) and stage_object_children (PASS,
restored). `geturl_target_normalize` fails on baseline too (pre-existing).)

Last updated: 2026-05-29 (pending CI — `with-v5/v6/v7/v8` (actionscript.all)
output_mismatch → `ruffle_matched` (+4 effective). Single fix in
`SWFModernRuntime/src/actionmodern/action.c::actionWithStart`: removed the
three `actionTrace_str("Error: A 'with' action failed because the specified
object did not exist.")` emissions (OBJECT-null, MOVIECLIP-null, UNDEFINED/NULL
branches). Flash's standalone player does NOT trace this error for
`with(invalid)` — no Flash `output.txt` in any suite contains the string; only
Ruffle emits it (case-v6/7/8 `output.ruffle.txt`). The body is still skipped
(return 0 unchanged), so `with(undefined){checkpoint=2}` followed by
`check(checkpoint==1)` still passes. The spurious 2-line error+blank was
shifting every downstream assertion line, collapsing with-v6/7/8 to 21%
line-match. Also flips AVM1 `with` output_mismatch → PASS. No regressions:
case-v5/6/7/8 still PASS (they resolve a valid `with` target, never hit the
error path); closure_scope/set_variable_scope/function_base_clip/tell_target
all PASS.)

Last updated: 2026-05-23 (pending CI — `loop/loop_test2` and `loop/loop_test3`
(misc-ming.all) output_mismatch → PASS (+2 PASSes). Single fix in
`SWFModernRuntime/src/libswf/tag.c::tagPlaceObject2`: added
`!catch_up_backward` to the early refuse gate at the "Failed to place
object at depth" warning site. The gate already excluded
`g_loopback_replay` (natural timeline wrap) so the survives_rewind
branch below could handle the modify; the analogous catch_up_backward
case (AS-driven `gotoAndStop`/`gotoAndPlay` backward catch-up) was
missing. Both tests do `swapDepths` in frame 3 then `gotoAndStop(2)`;
frame 2's Place tags target the original (now swapped) depths and
were spuriously refused with a warning that shifted all downstream
assertion lines. With the fix the placements fall through to the
survives_rewind branch, which treats them as modify-of-surviving-MC.
No regressions across 23-test AVM1 goto/lifecycle/clone/swap battery
and 10-test misc-ming goto/loop/replace/register-class battery, and
`avm1/placeobject_occupied_depth` (which exercises a different "Failed
to place" code path at `tag.c:5462`, the within-same-frame
`place_gen` check) still PASSES; `path_format_test`, `place_object_test`,
`place_object_test2` still RM.)

Last updated: 2026-05-15 (CI `eb8206f8`, no-graphics, run `25896064893` — first run after SUBTESTS_HARNESS shipped in commit `39b797ac`. 66 previously-undiscoverable tests (53 actionscript.all, 8 misc-ming.all, 3 misc-swfc.all, 2 misc-swfmill.all) now run. Per-suite totals jumped accordingly; effective rates dropped *numerically* purely from denominator growth, while raw passing counts grew (+2 Gnash, +9 effective). Newly-discovered passes/RMs: `Global-v5` PASS, `ops-v5/v6/v7` RM, `setProperty-v5/v6/v7/v8` RM, `BitmapDataDraw` RM, `trace-as2/arguments` PASS (misc-swfmill.all). Two new regressions: `misc-ming.all/loop/loop_test10` RM (5/28) → output_mismatch (1/28); `misc-ming.all/register_class/RegisterClassTest4` 17/42 → 7/42 lines. Triage of 45 newly-visible output_mismatch tests in `incomplete/SUBTESTS_NEWLY_VISIBLE_TRIAGE.md`.)

Last updated: 2026-05-13 (textfield-variable-binding plan complete: Phase A `fda90c99`, Phase B `a05dfc7c`, Phase C `b20ee462`. Dejagnu `_xtrace_win` trace TextField (bound to `_root._trace_text`) and similar variable-only-observed EditTexts now render correctly in graphics mode — driven by `place_object_test`, which stays RUFFLE_MATCHED but visually now matches what we'd expect under our AS2-spec depth handling. No pass-count delta (the affected tests were already effective-pass via RUFFLE_MATCHED); win is qualitative and architectural. See `SWFRecompDocs/plans/textfield-variable-binding-plan.md`.)

Last updated: 2026-05-08 (pending CI — `DrawingApiTest` 66/93 → 80/93 line match via Drawing-API `getBounds()` rewrite: `moveTo` no longer folds the pen into bounds, `lineTo`/`curveTo` always fold endpoints in, and stroked segments expand by FULL line thickness on each side (Flash semantics). Also fixed `lineStyle()` thickness coercion to handle Object-with-`valueOf`. Test stays `output_mismatch` — residual 13 diff lines are all hitTest precision issues unrelated to bounds.)

### CI snapshot (commit `eb8206f8`, 2026-05-15, no-graphics)

| Suite | Pass | RM | Effective | Total | Filtered Eff | Rate |
|-------|------|----|-----------|-------|-------------|------|
| actionscript.all | 127 | 70 | 197 | 243 | — | **81.1%** |
| misc-ming.all | 66 | 24 | 90 | 110 | 90/108 | 81.8% raw / **83.3% filtered** |
| misc-mtasc.all | 7 | 2 | 9 | 9 | — | **100.0%** |
| misc-swfc.all | 8 | 6 | 14 | 19 | 14/18 | 73.7% raw / **77.8% filtered** |
| misc-swfmill.all | 18 | 1 | 19 | 20 | — | **95.0%** |

The denominator growth comes from SUBTESTS_HARNESS shipping (+53 actionscript.all, +8 misc-ming.all, +3 misc-swfc.all, +2 misc-swfmill.all). Previous snapshot for comparison (commit `f8e172e9`, 2026-05-08): actionscript.all 126/63 of 190 (99.5%), misc-ming.all 65/24 of 102 (87.3% / 88.1%), misc-mtasc.all 7/2 of 9 (100%), misc-swfc.all 8/6 of 16 (87.5%), misc-swfmill.all 17/1 of 18 (100%). Raw passes grew (+2 across the four sub-suites) but effective rates fell numerically.

### CI baseline (2026-05-15, commit `eb8206f8`, no-graphics run `25896064893`) — SUBTESTS_HARNESS discovers 66 new tests

- **SUBTESTS_HARNESS (`39b797ac`).** `verify_output.py` now resolves expected-output filenames per-test via `resolve_expected_filename()`: `--expected-suffix` override → `output.txt` → `[subtests]` table's highest `player_options.version` variant. 66 tests that ship only `output.fpN.txt` were previously **invisible to discovery** (not failing — absent from totals). Distribution: 53 in actionscript.all, 8 in misc-ming.all, 3 in misc-swfc.all, 2 in misc-swfmill.all.

- **Newly-discovered: 2 PASS, 8 ruffle_matched, 45 output_mismatch.** Direct wins: `Global-v5` and `misc-swfmill.all/trace-as2/arguments` are clean PASSES. RMs: `ops-v5/v6/v7`, `setProperty-v5/v6/v7/v8`, and `BitmapDataDraw`. Effective gain: **+9 (2 raw + 7 RM, treating `ops-v5/v6/v7` as additions even though related v8 already passed)**. The 45 output_mismatch tests have widely varying line-match scores (1/2192 to 349/357) — triaged by tier in `incomplete/SUBTESTS_NEWLY_VISIBLE_TRIAGE.md`.

- **Two regressions in misc-ming.all** (unrelated to SUBTESTS_HARNESS).
  - `loop/loop_test10`: ruffle_matched 5/28 → output_mismatch 1/28. Status reverted from the 2026-05-08 RM promotion (`96a5d81e` + `f0d575ca` same-frame Remove+Place fix).
  - `register_class/RegisterClassTest4`: 17/42 → 7/42 lines (still output_mismatch but lost 10 lines). Already in `ignored_tests.txt`, so doesn't impact filtered rate.

- **Quiet line-match wins** (status unchanged but lines moved): `path_format_test` 0/27 → 16/27 (RM); `place_object_test2` 0/19 → 14/19 (RM); `place_object_test` 0/12 → 6/12 (RM). Likely follow-on from the 2026-05-13 textfield-variable-binding plan.

- **FAILING_TESTS_BY_FEATURE.md / _FILTERED.md regenerated this CI.** Several feature entries previously read "(1 failing / 1 total)" only because the other `-vN` versions weren't being discovered. Per-family cohorts (MovieClip-v6/v7/v8, TextField-v6/v7/v8, ops-v5/v6/v7, Date-v5..v8, Object-v5..v8, Function-v5..v8, XML/XMLNode-v5..v8, getvariable-v5..v8, setProperty-v5..v8, array-v6/v7/v8, NetConnection-v6/v7/v8, Stage-v6/v7/v8, argstest-v6/v7/v8, plus singletons like `flash-v8`, `Transform-v8`, `TextFormat-v8`) are now correctly represented.

## Missing dedicated plans (2026-05-19 audit)

Every non-ignored filtered failure across the four Gnash sub-suites is named in
some doc (FAILING_TESTS_BY_FEATURE listings or one of the two `incomplete/`
triage docs), but the following don't yet have a dedicated `*_PLAN.md`. Items
are grouped by likely shared root cause — one plan per group should cover the
whole row.

| Group / candidate plan name | Tests | Where currently noted | Notes |
|------|-------|-----------------------|-------|
| ~~`XML_XMLNODE_PLAN`~~ | XML-v5/v6/v7/v8, XMLNode-v5/v6/v7/v8 | `incomplete/XML_XMLNODE_PLAN.md` (2026-05-19) | Plan written — 12 phases covering own-vs-inherited prototype methods, XML.status/loaded coercion, send/sendAndLoad/addRequestHeader stubs, childNodes-as-Array, namespaceURI empty-string vs null, localName/prefix trailing-colon, attribute serialization (order + empty emit), text-node nodeValue, cloneNode parentNode reset, whitespace merging. Cross-references the AVM1 XML_PLAN. |
| ~~`FUNCTION_VN_PLAN`~~ | Function-v5/v6/v7/v8 | `incomplete/FUNCTION_VN_PLAN.md` (2026-05-19) | Plan written — 9 phases covering Function class identity, apply/call this-binding, custom toString, arguments enumeration, eval-stack survival, primitive __constructor__, super-property binding, Function.__proto__ identity. Cross-links to OBJECT_VN_PLAN Phase 1 and GETVARIABLE_VN_PLAN. |
| ~~`OBJECT_VN_PLAN`~~ | Object-v6/v7/v8 (v5 already RM) | `incomplete/OBJECT_VN_PLAN.md` (2026-05-19) | Plan written — 7 phases covering Function class identity (shared with FUNCTION_VN), `obj.hasOwnProperty('constructor')`, addProperty getter/setter dispatch (`obtained: 65` bug), watch() callback args, `o._target` undefined-vs-string, watch return-value validation. |
| ~~`GETVARIABLE_VN_PLAN`~~ | getvariable-v5/v6/v7/v8 | `incomplete/GETVARIABLE_VN_PLAN.md` (2026-05-19) | Plan written — 3 phases covering `var xx` local-shadow vs path-setvariable, path-call `this` binding (`_root.o.func` → this=_root.o), and the line-105 PASS-where-Gnash-expected-FAILED check. |
| ~~`MOVIECLIP_VN_PLAN`~~ | MovieClip-v6/v7/v8 | `incomplete/MOVIECLIP_VN_PLAN.md` (2026-05-19) | Plan written — 17 phases. Largest clusters: prototype method visibility (`MovieClip.prototype.meth`), getSWFVersion always returning 5, soft/hard reference semantics, getBounds reference-clip transforms, addProperty on MC virtual props. Several small wins (Phase 13 setProperty return-value, Phase 4 _soundbuftime per-root, Phase 11 _yscale sign, Phase 17 _quality BEST). |
| ~~`NETCONNECTION_VN_PLAN`~~ | NetConnection-v6/v7/v8 | `complete/NETCONNECTION_VN_PLAN.md` (2026-05-19) | **RESOLVED 2026-05-19 → all three ruffle_matched.** connect()/close() rewritten to Flash semantics; residual diff (blacklisted-http lines) ⊆ Ruffle's. |
| ~~`TEXTFIELD_VN_PLAN`~~ | TextField-v6/v7/v8 | `incomplete/TEXTFIELD_VN_PLAN.md` (2026-05-19) | Plan written — 13 phases covering AsBroadcaster integration, prototype-vs-instance own-prop layout, getFontList, boolean-setter coercion (background/embedFonts/multiline/selectable/password), null-state for maxChars/restrict/variable, MC-only frame-props gated off on TextFields, tf.type case-normalize, tf._width/_height initial value (likely biggest impact), tf.maxhscroll default, tf.length cache, tf._parent silent-no-op, replaceText stub, container-MC identity. |
| ~~`TEXTFORMAT_V8_PLAN`~~ | TextFormat-v8 | `incomplete/TEXTFORMAT_V8_PLAN.md` (2026-05-19) | Separate from TEXTFIELD — only 2 clusters: INT_MIN clamping on negative numeric setters (blockIndent/leading/indent/size), and getTextExtent font-metric precision (likely RUFFLE_VS_FLASH or ruffle_matched-eligible; diff against `output.fp9-18.ruffle.txt` first). |
| ~~`TRANSFORM_V8_PLAN`~~ | Transform-v8 | `incomplete/TRANSFORM_V8_PLAN.md` (2026-05-19) | Plan written — 6 phases. Cross-references MATRIX_TEST_SKEW (matrix float drift) and MOVIECLIP_VN (swapDepths binding). At 85% line-match — strong ruffle_matched candidate after Phases 1+2 land. |
| ~~`ARRAY_V6_V8_PLAN`~~ | array-v6/v7/v8 | `incomplete/ARRAY_V6_V8_PLAN.md` (2026-05-19) | Written as companion to ARRAY_V5_PLAN (same source file with `OUTPUT_VERSION > 5` gates). 5 phases for v6+-only residuals (own length, apply-with-Array-receiver, sparse hasOwnProperty, sortOn length, sort/splice edge cases). |
| ~~`ARGSTEST_VN_DECISION`~~ | argstest-v6/v7/v8 | `complete/ARGSTEST_VN_DECISION.md` (2026-05-20) | **RESOLVED 2026-05-20 → ACCEPTED_DIFFS Category 3.** Diffed: we over-emit ~3.5× (7731/7731/8093 vs 2192/2061/2434 expected); Ruffle under-emits (~1298). Our diff not a subset → no RM. Added to `actionscript.all/ignored_tests.txt`. |
| ~~`SOUND_VN_REGRESSION_PLAN`~~ | Sound-v6/v7/v8 | **No plan needed (2026-05-19)** | Local re-runs at current `master` SHA show all three at `ruffle_matched` (effective pass). The CI snapshot `eb8206f8` (2026-05-15) result file shows `output_mismatch` 91/121, 93/121, 93/121 — but local reproduction contradicts that. Discrepancy unexplained; recommend re-running CI to see whether the result file regenerates as RM. Don't write a plan until/unless CI confirms regression. |
| ~~`GRADIENTFILLTEST_PLAN`~~ | misc-ming.all/GradientFillTest | `incomplete/GRADIENTFILLTEST_PLAN.md` (2026-05-19) | 2 phases. Off-by-low-bit color sampling across all gradient points — gamma/sRGB-vs-linear interpolation precision. |
| ~~`PROTOTYPEEVENTLISTENERS_PLAN`~~ | misc-ming.all/PrototypeEventListeners | `incomplete/PROTOTYPEEVENTLISTENERS_PLAN.md` (2026-05-19) | 3 phases. Mouse/Key broadcaster doesn't walk prototype chain or `_global` for prototype-defined handlers. Substantial feature work but contained. |
| ~~`TEXTSNAPSHOTTEST_PLAN`~~ | misc-ming.all/TextSnapshotTest | `incomplete/TEXTSNAPSHOTTEST_PLAN.md` (2026-05-19) | 3 phases. AVM1 TextSnapshot work landed stubs; need to actually implement setSelected/getSelected/getSelectedText round-trip with selection-state storage. |
| ~~`PLACEANDREMOVE_PLAN`~~ | misc-ming.all/action_order/PlaceAndRemove | `incomplete/PLACEANDREMOVE_PLAN.md` (2026-05-19) | Same root cause as ACTION_EXECUTION_ORDER_TEST6 but inverse polarity: this test expects cancellation, that one expects firing. Diff `output.ruffle.txt` for both to determine model. |
| ~~`ACTION_EXECUTION_ORDER_EXTEND_PLAN`~~ | misc-ming.all/action_order/action_execution_order_extend_test | `blocked/ACTION_EXECUTION_ORDER_EXTEND_PLAN.md` (2026-05-19) | **BLOCKED (re-investigated 2026-05-19).** Not "2 small bugs" — Bug 1 is a missing feature: `onLoad`/`onUnload` METHOD-handler dispatch for plain timeline-placed sprites (`actionDispatchMCOnLoad` only fires for root/attachMovie/registerClass MCs). Fire/no-fire rule is subtle (Flash fires `mc_red.onLoad` but not `mc_blu.onLoad`; Ruffle wrongly fires both) and needs the Gnash C source to pin down. Bug 2 is the SPRITE_EXEC_LIST_LIFO interleave (that plan still in_progress). Neither bug alone promotes the test. |
| ~~`LOADBITMAPTEST_PLAN`~~ | misc-ming.all/loading/LoadBitmapTest | `complete/LOADBITMAPTEST_PLAN.md` (2026-05-19) | **RESOLVED 2026-05-19 → ruffle_matched.** `bitmapDataLoadBitmap` now derives the loaded bitmap's `__proto__` from the receiver object's `prototype` property (Flash `thisObj.prototype` semantics) when called as a method of a plain object, instead of always using `BitmapData.prototype`. Fixes `c.__proto__ == undefined`. Phases 1/2/3b are Flash-vs-Ruffle divergences (Ruffle fails the same lines). |
| ~~`MATRIX_ACCURACY_TEST1_DECISION`~~ | misc-swfc.all/matrix_accuracy_test1 | `complete/MATRIX_ACCURACY_TEST1_DECISION.md` (2026-05-20) | **RESOLVED 2026-05-20 → ACCEPTED_DIFFS Category 4.** Ruffle panics (`known_failure.panic`), no `output.ruffle.txt` → RM structurally impossible. 10/18 match; residual is twips u32-wrap off-by-one. Added to `misc-swfc.all/ignored_tests.txt`. |
| ~~`MOVIECLIP_DESTRUCTION_TEST3_PLAN`~~ | misc-swfc.all/movieclip_destruction_test3 | `incomplete/MOVIECLIP_DESTRUCTION_TEST3_PLAN.md` (2026-05-19) | 3 phases. Deferred removeMovieClip (let current frame's DoAction complete), depth-bias after removal, hard-reference clearance (shared with MOVIECLIP_VN Phase 6). |
| ~~`ACTION_EXECUTION_ORDER_TEST12_PLAN`~~ | misc-swfc.all/action_execution_order_test12 | `complete/ACTION_EXECUTION_ORDER_TEST12_PLAN.md` (2026-05-19) | **RESOLVED 2026-05-19 → ruffle_matched.** Two `tag.c` fixes: (1) sprite loop-back now fires child onUnload (was a silent free) — also stopped spurious child onEnterFrame; (2) timeline-sprite onLoad gated on an actually-registered class (was queued for every exported `.sprite`). |
| ~~`DRAWING_API_HITTEST_PLAN`~~ | misc-ming.all/DrawingApiTest | `incomplete/DRAWING_API_HITTEST_PLAN.md` (2026-05-19) | 3 phases. Drawing-API hitTest precision (undefined-on-stroke-only, winding rule, corner-pixel exclusion). |
| ~~`EMBEDDEDFONTTEST_PLAN`~~ | misc-ming.all/EmbeddedFontTest | `incomplete/EMBEDDEDFONTTEST_PLAN.md` (2026-05-19) | 3 phases. Diagnose first (FP-precision vs feature-gap), then DefineFont3 alignment zones or glyph FP drift. |
| ~~`NETSTREAM_SQUARETEST_PLAN`~~ | misc-ming.all/NetStream-SquareTest | `incomplete/NETSTREAM_SQUARETEST_PLAN.md` (2026-05-19) | Verify scope vs `VIDEO_EMBED_SQUARE_PLAN` first. If distinct: 4-6 hours timing investigation. |
| ~~`MASKS_TEST_PLAN`~~ | misc-ming.all/masks_test | `incomplete/MASKS_TEST_PLAN.md` (2026-05-19) | 2 phases. Blocked on synthetic-input infrastructure (auto-keypress or `--auto-keypress` flag). Then re-baseline. |
| ~~`MOVIECLIP_DESTRUCTION_TEST4_PLAN`~~ | misc-swfc.all/movieclip_destruction_test4 | `incomplete/MOVIECLIP_DESTRUCTION_TEST4_PLAN.md` (2026-05-19) | Blocked on SPRITE_REWIND_IDENTITY (blocked/) for sprite frame DoAction firing. Phase 2 (hard-reference clearance) shared with MOVIECLIP_VN. |
| ~~`ACTION_EXECUTION_ORDER_TEST6_PLAN`~~ | misc-ming.all/action_order/action_execution_order_test6 | `incomplete/ACTION_EXECUTION_ORDER_TEST6_PLAN.md` (2026-05-19) | 2 approaches: Flash-exact (high risk, regresses other tests) or match-Ruffle-for-RM (low risk, no PASS). Recommend Approach B first. |
| ~~`LOOP_TEST_REGRESSION_PLAN`~~ | misc-ming.all/loop/loop_test (4/21), loop_test10 (1/28) | `incomplete/LOOP_TEST_REGRESSION_PLAN.md` (2026-05-19) | Plan written — both regressions confirmed locally and in CI. Approach: git-bisect to find regressing commit (loop_test post-2026-05-02; loop_test10 post-2026-05-08). 2-4 hours bisect + ~1 hour patch. Not new design; rediscovery. |

Suggested write order:
1. **Investigation-first groups** (combine multiple families into one plan if root cause matches): Function-vN + Object-vN + getvariable-vN; XML-vN + XMLNode-vN; TextField-vN + TextFormat-v8. Spend one session reading expected vs. actual on a representative test from each before deciding plan granularity.
2. **Status-divergence plans** that just need rediscovery, not new design: Sound-vN regression, loop_test/loop_test10 regression. Cheap wins to write.
3. **Decision docs** (not fix plans): argstest-vN, matrix_accuracy_test1 — likely belong in ACCEPTED_DIFFS once confirmed.
4. **Single-test deferrals**: everything else, lowest priority unless picked up opportunistically.

### Latest fix (2026-05-22, pending CI)

- **`Function-v6` (actionscript.all): output_mismatch → `ruffle_matched`.**
  Implements the FUNCTION_VN_PLAN Phase 3/9 residual cluster — four
  changes in `SWFModernRuntime/src/actionmodern/action.c` clear the five
  ours-only diff lines (73, 146, 147, 221, 223): (1) builtin-`addProperty`
  guard now consults the full prototype chain
  (`findPropertyStructWithPrototype`, excluding `&g_object_addProperty_func`)
  so an `Object.prototype.addProperty` user override dispatches; (2)
  `actionNewObject` resolves a `"this"` constructor name via
  `actionGetVariable("this")` (g_this_stack) so `new this` works; (3) the
  type-1 FUNCTION-receiver method dispatch in `actionCallMethod` binds
  `this` to the function receiver (was leaving the caller's stale
  g_this_stack top); (4) `actionCallFunction`'s type-1 path binds `this`
  to a non-MC local scope object when the function was resolved from one
  (Ruffle `scope.resolve()` → `Callable(locals, fn)`). v5/v7/v8 unchanged.
  No regressions across 23-test AVM1 function/scope/super, 14-test
  addProperty/new/primitive, 15-test gnash Inheritance/Object/Global
  batteries. See `incomplete/FUNCTION_VN_PLAN.md`.

- **`Sound-v5/v6/v7/v8` (actionscript.all): output_mismatch → `ruffle_matched`
  (all four).** Two changes in `SWFModernRuntime/src/actionmodern/action.c`,
  both Sound-only (blast radius is the Sound builtins).
  1. **Invalid controllable-character argument.** `new Sound(arg)` where
     `arg` is anything other than a MovieClip / null / undefined (a Number,
     String, Object — e.g. `new Sound(54)`, `new Sound(o)`) produces a Sound
     bound to nothing: `getVolume`/`getPan`/`getTransform` return undefined,
     `setVolume`/`setPan` are no-ops. The three Sound-constructor sites now
     set a hidden `__sound_bad_target__` boolean for such args, and
     `resolveSoundTransformTarget` returns NULL when it is set. Previously a
     non-MC owner fell through to the shared global transform, so an invalid
     Sound's `setVolume` leaked into the global volume read by other
     ownerless Sounds (`s1e/s1f.getVolume()` came back 54 instead of 76).
  2. **`getPosition()` undefined until loaded.** `builtin_sound_getPosition`
     now returns undefined unless the Sound's `__loaded__` flag is set
     (attachSound / loadSound set it) — Flash returns undefined for
     `getPosition()` on a Sound that has never had audio bound. Mirrors the
     existing `_snd_is_loaded` gate on the `position` *property* getter.

  After both changes our diff against `output.fpN.txt` is a strict subset of
  Ruffle's, so all four versions auto-promote. Residual shared diffs
  (`checkPolicyFile` boolean property, unloaded-MC-owner getVolume, loaded
  mp3 duration 209 vs our 1000, getBytesTotal/Loaded) are Ruffle-failed too.
  No regressions: 15-test AVM1 sound battery — the 8 baseline passes stay
  PASS, the 7 baseline output_mismatch tests (all on `ignored_tests.txt`)
  stay output_mismatch.

### Latest update (2026-05-20, docs only — no code change)

- **`argstest-v6/v7/v8` (actionscript.all) and `matrix_accuracy_test1`
  (misc-swfc.all): resolved the two pending decision docs → ACCEPTED_DIFFS.**
  Both `ARGSTEST_VN_DECISION` and `MATRIX_ACCURACY_TEST1_DECISION` were
  pending a diff-and-decide pass. Neither is `ruffle_matched`-eligible:
  argstest over-emits ~3.5× (7731/7731/8093 vs 2192/2061/2434 expected) due
  to unimplemented / placeholder-prototype native objects (PrintJob,
  MovieClipLoader, …) while Ruffle *under*-emits (~1298 lines) — our diff is
  not a subset; matrix_accuracy_test1 has `known_failure.panic` so Ruffle
  panics and ships no `output.ruffle.txt` at all. Added all four tests to
  the respective `ignored_tests.txt` files and documented them in
  `ACCEPTED_DIFFS.md` (new Category 3: native-object enumeration divergence;
  new Category 4: twips arithmetic at integer boundaries). Both decision
  docs moved to `complete/`. No runtime/recompiler code changed.

### Latest fix (2026-05-19, pending CI)

- **`NetConnection-v6/v7/v8` (actionscript.all): output_mismatch → `ruffle_matched`.**
  Implements `complete/NETCONNECTION_VN_PLAN.md` (all 8 phases) in one
  `SWFModernRuntime/src/actionmodern/action.c` change. `NetConnection.connect()`
  rewritten to Flash semantics: no-arg is a no-op; `connect(null)` /
  `connect(undefined)`-on-SWF7+ → Connect.Success + `isConnected=true` +
  return `true`; non-URL string/number → Connect.Failed + return `false`;
  empty string → false with no onStatus (Flash Player ≥10 / fp30 behaviour);
  `"…://…"` → pending remote connection (no onStatus, native `has_remote`
  flag drives a later `close()`'s Connect.Closed). `nc.uri` is now a read-only
  string property set from the coerced first arg; `nc.isConnected` is
  read-only too. The onStatus infoObj got an `__proto__` so
  `infoObj instanceof Object` works. Residual diff `{75,76}` (blacklisted
  http URL — needs an unmodellable sandbox blacklist) ⊆ Ruffle's 44-line
  diff against `output.fp30.txt`, so all three auto-promote. No regressions
  (AVM1 `netconnection_close`, `native_objects_swf7/8`, gnash
  `NetConnection-v5`, `NetStream-v6/v7`, `Video-v6` all pass).

- **`loading/LoadBitmapTest` (misc-ming.all): 13/17 output_mismatch → ruffle_matched.**
  One change in `SWFModernRuntime/src/actionmodern/action.c::bitmapDataLoadBitmap`.
  Flash sets a loaded bitmap's `__proto__` to `thisObj.prototype` (the
  receiver of the `loadBitmap` call), not a fixed `BitmapData.prototype`.
  The test aliases the static method onto a plain object
  (`o.func = flash.display.BitmapData.loadBitmap`) and calls `o.func('img1')`;
  the result's `__proto__` must be `o.prototype` (undefined here).
  `bitmapDataLoadBitmap` now: recognises the genuine static call by
  pointer-comparing `this_obj` against the BitmapData ctor's `own_props`
  bag (`g_bitmapdata_ctor_own_props`) and keeps the default prototype;
  otherwise, when called as a method of a plain object
  (`g_call_this_type == OBJECT`), reads that object's own `prototype`
  property and uses it (leaving `__proto__` unset when absent). The
  bare-call path (`this_obj == NULL`) keeps the default unchanged. Our
  diff drops from `{4,9,11,12}` to `{4,9,12}` ⊆ Ruffle's `{4,9,12}`, so
  the test auto-promotes. Lines 4/9/12 are Flash-vs-Ruffle divergences
  (transparent flag, JPEG-decoder off-black sample, `typeof(d)`). No
  regressions: 6-test BitmapData battery all PASS.

### Latest fix (2026-05-08, pending CI)

- **`DrawingApiTest` (misc-ming.all): 66/93 → 80/93 lines match (+14, -14 mismatched).** Three paired changes in `SWFModernRuntime/src/actionmodern/action.c`:

  1. **`moveTo` no longer folds the pen into bounds.** Previously each `moveTo(x, y)` called `drawingUpdateBounds(mc, x, y)` so an empty MC with only a `moveTo` reported `(x,y,x,y)` instead of Flash's `(MAX_TWIPS,MAX_TWIPS,MAX_TWIPS,MAX_TWIPS)` sentinel (≈ `6710886.35,...` in pixels). Fix: drop the bounds update from both `moveTo` dispatch sites (the WITH-scope forwarder around line 50423 and the method-dispatch handler around line 60935). Test line 84 (`bnd == "6710886.35,..."` after `moveTo(100,100)`) flips to PASS.

  2. **`lineTo` / `curveTo` always fold endpoints into bounds, and expand by FULL line thickness when stroked.** Empirically Flash's `getBounds` for a stroked drawing extends each axis by the full `lineStyle` thickness (not the geometric half-thickness Ruffle uses): a `lineStyle(20)` line from (100,100) to (200,200) reports `(80,80) (220,220)` per the test source comment "line is 20 pixels thick". Fix: `lineTo`/`curveTo` now expand at BOTH the previous pen position and the new endpoint(s) by the current segment's `line_w` (full thickness); when `has_line == 0` the expansion is 0 but the points are still folded in (so fills without strokes still produce correct bounds — covers `beginFill; lineTo(100,100); ...; endFill;` with implicit `(0,0)` start). Both endpoints are re-expanded with each new segment's thickness, even when the start was already folded by a prior segment with a different thickness — this matches Flash's overestimate (e.g. `lineStyle(5)+lineTo(200,250) → lineStyle(10)+lineTo(400,200)` correctly extends y_max from 255 to 260 because the new segment's start (200,250) gets ±10 expansion).

  3. **`lineStyle` thickness coercion uses `varToDoubleSWF`.** Test source has `thick = {valueOf: () => 20}; lineStyle(thick, red, 100);` — `varToDouble` returns 0 for OBJECT type (no `valueOf` invocation), so `line_w` was 0 and bounds didn't expand even after the fix above. Switched all three `lineStyle` arg coercions in both dispatch sites to `varToDoubleSWF(app_context, &args[i], g_swf_version)`, which calls `objectCallValueOf` for OBJECT-typed args.

  Test stays `output_mismatch` — all 14 remaining diff lines are hitTest precision issues (`zshape.hitTest` returning undefined, `inv4.hitTest` / `inv8.hitTest` boolean drift, etc.) plus 2 trailing extra "delete onEnterFrame returned false" lines. No path to `ruffle_matched` promotion: our 20 diff indices are entirely disjoint from Ruffle's 14 diff indices (Ruffle gets the bounds wrong but the hitTests right; we now get the bounds right but still fail the hitTests). Promoting would require fixing the drawing-API hitTest precision, which is independent shape-rasterization work.

  Verified: `matrix_test` (1081/1086 ruffle_matched, unchanged), `duplicate_movie_clip_drawing` (was MISMATCH `0,0` → PASS — the fill-without-stroke case fixed by change #2), `mask_with_drawing`, `movieclip_default_state`, `movieclip_getbounds`, `movieclip_state_values`, `hittest_morph` all PASS unchanged. `movieclip_hittest_shapeflag` still MISMATCH (unrelated pre-existing hitTest issue). `ButtonEventsTest` (676/679 ruffle_matched) and `NetStream-SquareTest` (86/216 output_mismatch) unchanged.

### Earlier fix (2026-05-08, pending CI)

- **`array-v5` (actionscript.all): 535/560 → 536/560 lines match (+1, -1 mismatched).** Two paired changes in `SWFModernRuntime/src/actionmodern/action.c`:
  1. `resolveProtoVar` now handles `ACTION_STACK_VALUE_ARRAY` by returning `arr->props` (the array's string-keyed property bag whose own `__proto__` points at `Array.prototype`). Used by `walkProtoChain`, `getPropertyWithPrototype`, and `findPropertyStructWithPrototype`.
  2. The inline OBJECT-receiver method-lookup walk in `actionCallMethod` (line ~56235) does the same ARRAY-aware step inline.

  Trigger pattern: `function X() {}; X.prototype = new Array(); o = new X(); o.push("Array data"); ret = o.pop();` (array.as line 1701-1710). When a function's prototype is a non-object value (here an Array instance), `actionNewObject` stores the ARRAY-typed value verbatim on the new instance's `__proto__`. The OBJECT-receiver method-lookup loop in `actionCallMethod` previously broke the chain walk at the ARRAY-typed proto, so `push`/`pop` were never resolved through `Array.prototype` and `o.pop()` returned undefined. After the fix, the walk follows `o → X.prototype (Array instance) → arr->props → Array.prototype`, and the existing `objectToTempArray` / `callArrayMethod` / `syncArrayToObject` path mutates correctly. Line 1710 (`ret == "Array data"`) flips to PASS.

  No regressions across 31-test AVM1 array/lifecycle/super/scope battery, 19-test follow-up battery (closure_scope, register_and_init_order, set_variable_scope, on_construct, register_class_return_value, parse_int, typeof, enumerate, etc.), 11-test gnash actionscript.all prototype-heavy battery (Boolean-v5, Inheritance-v5/v6/v7/v8, Number-v5, case-v6, delete-v5/v6, enumerate-v6/v7), and 4-test Shumway `duplicateMovieClip` battery — all 65 effective passes preserved.

### Earlier fixes (2026-05-08, in CI at `f8e172e9`)

- **`array-v5` (actionscript.all): 528/560 → 535/560 lines match (+7, -7 mismatched).** Three changes in `SWFModernRuntime/src/actionmodern/action.c`:
  1. **`Array.prototype.shift` honors DontDelete on the target index.** The element-copy loop (`arr->elements[i] = arr->elements[i + 1]`) and the metadata-reset loop are now both gated on `arr->props["<i>"]` having `PROPERTY_FLAG_CONFIGURABLE` set. Matches Flash for `ASSetPropFlags(a, "0", 7, 0); a.shift()` — `a[0]` keeps its protected `'zero'` value (line 1416). Note: WRITABLE/ReadOnly is intentionally NOT honored here. Flash test array.as:1444 (`ASSetPropFlags(a, "0", 4, 0)`, ReadOnly only) explicitly expects shift to overwrite, so honoring WRITABLE would regress lines 1451/1454/1471/1474. Ruffle DOES honor WRITABLE (its `set_data` checks `is_overwritable()`) and so it fails 1451/1454/1471/1474 — those lines are in Ruffle's diff against Flash, so we can match Flash without falling outside Ruffle's diff for those particular lines.
  2. **`syncArrayToObject` skips HOLE-typed temp entries during writeback.** The plain-Object dispatch bridge for `Array.prototype.X.call(plainObj)` reads obj's indices into a temp ASArray via `objectToTempArray`; missing keys land as HOLE. Without skipping, the writeback loop creates spurious new properties on `obj` for indices that were never there (e.g. `pop` on a fakeArray creating `obj["0"]` from the missing slot). Skipping HOLEs fixes line 1537 (`traceProps(o)` after `o.pop()` no longer has a leading `0,`). Other plain-Object dispatch lines (1577 splice, 1630/1636 sort) didn't change because their internal HOLE→UNDEFINED densification runs before the writeback.
  3. **`actionGetMember` ARRAY branch fires `__resolve` on missing key.** Both the numeric-index and non-index fallthrough paths now call `findResolveMethod` / `invokeResolveFunction` on `arr->props` before returning undefined, mirroring the existing OBJECT path. Fixes `t = []; t.__resolve = function(a){...}; t[3]` returning `'resolved 3'` (line 1653) plus the `rs == 1` counter checks at lines 1654, 1665, 1669, 1671 (sort, reverse, join all flow through).

  Test stays `output_mismatch` — residual 25 lines are mostly sort/sortOn algorithm-dependent ordering (Category C in `incomplete/ARRAY_V5_PLAN.md`) and Flash's plain-Object Array.prototype.X.call insertion-order semantics (densify-vs-don't-delete divergence between pop, shift, splice). Promotion to `ruffle_matched` would also need the for-in-over-sorted-sparse-array key tracking (260/263) and the `X.prototype = new Array()` toString-override path (line 1710).

- **No regressions** across all 8 suites. Verified locally on a 16-test AVM1 array battery, a 17-test AVM1 lifecycle/scope/super battery (`funky_function_calls`, `swf4_function_calls`, `closure_scope`, `set_variable_scope`, `on_construct`, `execution_order2/3`, `goto_rewind3`, `set_interval`, `tell_target`, `as2_super_and_this_v6/v8`, `extends_chain`, `register_class_return_value`, `movieclip_state_values`, `swf5_to_6_cross_call`, `swf5_no_closure`), a 21-test gnash actionscript.all battery (delete-v5..v8, enumerate-v6..v8, case-v5..v7, ASnative-v6, Boolean-v5, Number-v5/v6, Inheritance-v5/v6/v7, Global-v6/v7, toString_valueOf-v5/v6), and an 8-test misc-ming battery covering the addProperty/__resolve-adjacent paths.

### Investigated 2026-05-08 (no fix attempted — `ButtonEventsTest` trailing-whitespace trap)

- **`ButtonEventsTest` (misc-ming.all) trailing-whitespace diff — not a tractable PASS target.**
  Status `ruffle_matched 676/679` on 3 ours-only diff lines (vs Ruffle's 642 diffs against
  Flash). On first inspection this looks like a 3-line gap to full PASS, but the diff is
  trailing-whitespace on `PASSED:  == ` (the Dejagnu `check_equals(_name, '')` output where
  both operands stringify to `""`).

  **Mechanism.** Test source: `_root.check_equals(_name, '');` (after `setTarget('/')` so
  `_name` returns the empty root name). Inlined AS-level `check_equals(obt, exp, msg)` with
  `obt == exp` and `msg == undefined` falls through to `_root.runtest.pass(obt + " == " + exp)`,
  which traces `"PASSED: " + why`. With both operands empty: `"" + " == " + "" = " == "` (4
  chars), then `"PASSED: " + " == " = "PASSED:  == "` (12 chars, trailing space). Our Add2
  and trace are correct — Ruffle's `output.ruffle.txt` for this test also has trailing
  whitespace on the analogous lines. Only Gnash's expected `output.txt` (the only file
  without trailing whitespace anywhere) lacks it, suggesting Gnash's testsuite capture
  strips trailing whitespace before writing `output.txt`.

  **Why we won't fix.** Stripping trailing whitespace from `actionTrace` output would break
  AVM1 tests that have intentional trailing whitespace in their expected output —
  `function_base_clip`, `logical_ops_swf4`, `mcl_target_jpg`, `focusrect_property_swf6`,
  `primitive_type_globals`, etc. all ship `output.txt` files with at least one trailing-
  space line. The 3 ButtonEventsTest lines are already inside Ruffle's diff set, so the
  test is `ruffle_matched` and counted as effective pass — promoting to PASS isn't
  worth regressing the AVM1 100% filtered rate.

  **Decision.** Leave as `ruffle_matched`. No code change. Future sessions seeing
  ButtonEventsTest at 99.6% line match should skip — the residual is structural to how
  the Gnash testsuite writes `output.txt`, not a bug in our trace.

### Investigated 2026-05-08 (CI `281f30b3`, reverted in `4c61f111`/`d1c3b9d5`)

- **`action_order/action_execution_order_test6` LOAD-filter attempt — reverted.** Identified
  that `queue_clip_load_events` in `SWFModernRuntime/src/libswf/tag.c` was passing
  `clip=NULL` to `actionQueueCallbackEx`, so the `aq_drain` filter at
  `action_queue.c:151-160` (skip on `avm1_removed`/`pending_removal`) couldn't apply
  to sprite `CLIP_EVENT_LOAD` entries — only `CLIP_EVENT_CONSTRUCT` entries (which
  pass non-NULL `clip`) got filtered. This is why test6's cycle 1 emitted LOADs
  but not Constructs for cancelled placements during the gotoAndPlay 2→9 catchup.

  Conservative fix tried: during `catch_up_mode` only, look up the sprite's MC via
  `actionFindOrCreateMovieClip(...)` and pass it as `clip` so the existing
  filter applies. Outside catchup, leave `clip=NULL` to preserve "fire even if
  removed mid-frame" semantics for natural play.

  Local verification: 22-test AVM1 lifecycle/event battery, 18-test
  misc-ming.all loop/key/event battery, 8-test misc-swfc.all battery, 10-test
  misc-ming.all action_order battery — all clean. Test6 cycle 1 LOAD events
  correctly suppressed (`check_result '4+5+6+7+8+9+1+2+4+5+x+xx+'` →
  `'6+7+9+1+2+4+5+x+xx+'`). Test stayed `output_mismatch` (cycle 1 UNLOADs and
  cycle 2 LOAD/frame_0 interleave still need fixing).

  CI surfaced regression the local battery missed:
  `reverse_execute_PlaceObject2_test2` flipped from `pass 10/10` to
  `ruffle_matched 7/10`. The test exercises a backward-rewind catchup that
  re-places a sprite — both LOAD events should fire (`_root.x1 ==
  'onLoad+onLoad+'`) but our fix suppressed the first LOAD because the MC was
  `pending_removal` at drain time. Net effective unchanged on misc-ming.all
  (89/102) but a true PASS was downgraded to RM (we now match Ruffle's
  divergent behavior here instead of Flash's expected output).

  Decision: revert. The `catch_up_mode`-only gate isn't specific enough — it
  catches goto-aggregation cancellation correctly, but also catches
  rewind-survives re-placements where Flash fires both LOADs. Need a finer
  signal — e.g., per-entry tracking of "this placement was paired with a
  same-sweep RemoveObject" — before this can land. Full notes in
  `incomplete/REMAINING_TAIL_TRIAGE.md` under the test6 entry.

### Latest fixes (2026-05-08, in CI at `068b46d8` — back-to-back determinism check)

- **`array-v5` (actionscript.all): 520/560 → 528/560 lines match (+8, -8 mismatched).** Three changes in `SWFModernRuntime/src/actionmodern/action.c`:
  1. `actionSetMember` ARRAY index-write path now consults `arr->props["<idx>"]` and skips the write when `WRITABLE` is cleared (mirrors the existing `actionDelete` CONFIGURABLE check). Fixes `ASSetPropFlags(a, "0", 4, 0); a[0] = X` silent-ignore (lines 1447, 1465).
  2. `Array.prototype.shift` resets ASSetPropFlags metadata on overwritten slots so subsequent userland writes succeed (Flash semantics: "flag was lost"), and preserves the deleted last element's value into `arr->props` when the slot is marked DontDelete (CONFIGURABLE cleared) — `a[length-1]` keeps its original value through the props fallback after length is decremented.
  3. `syncArrayToObject` (the temp-array bridge for `Array.prototype.X.call(plainObj)`) gained an `update_length` parameter; `shift`/`pop`/`unshift` now skip the length update on plain Object, matching Ruffle's `if let NativeObject::Array(_) = this.native()` gate (`o.length == 6` after `o.shift()` on a fakeArray-shaped object).
  
  Test stays `output_mismatch` (still no path to `known_failure` promotion — it's a raw failure). Effective rate unchanged on actionscript.all suite, but mismatched-lines metric drops 1580 → 1572.

- **CI back-to-back verified determinism.** Two CI runs at the same SHA (`25570298054` and `25571481603`, both at commit `068b46d8`) produced byte-identical results across all 8 suites — confirms `MOCK_DATE_TIME`-based RNG seeding works end-to-end (`verify_output.py:1538` passes `-DMOCK_DATE_TIME=<ms>LL`; `math.c::GenerateRandomNumber` uses it as the avmplus RNG seed). Stale "fluctuates by ~4 lines" disclaimer in `incomplete/ARRAY_V5_PLAN.md` removed.

- **No regressions** across 16-test AVM1 array battery, 13-test Gnash actionscript.all battery (delete-v5..v8, enumerate-v6..v8, case-v5..v7, ASnative-v6, Boolean-v5, Number-v5 — 13/13 effective), AVM1 assetnative/loadvars_tostring/add_property/watch/object_resolve/coerce_to_object_monkeypatch/register_class_return_value (7/7 PASS).

### Latest fixes (2026-05-08, in CI at `f0d575ca`)

- **`loop/loop_test10` (misc-ming.all) → ruffle_matched (5/28, was 3/28 output_mismatch).** Two paired fixes in `SWFModernRuntime/src/libswf/tag.c` for the same-frame Remove+Place at the same depth pattern (frame 3: `Remove(mc1)` + `SetInstanceName("mc2")` + `Place(mc2)` at depth 100):
  1. `tagSetInstanceName` skips the inline rename path and stashes the name as `g_pending_instance_name` when `ng_depth_has_pending_finalize(depth)` is true AND the new name differs from `display_list[depth].instance_name`. Without this, the still-live mc1 entry (deferred for finalize because of its UNLOAD clip event) was renamed to "mc2" inline, so its queued UNLOAD trace evaluated `this+' unloaded'` to `_level0.mc2 unloaded` (wrong binding) and `actionFindOrCreateMovieClip("mc2")` returned the dying mc1 pointer instead of creating a fresh MC.
  2. `PendingFinalizeEntry` now snapshots the queue-time `display_list` pointer + orig `instance_name`. `run_pending_finalize` only honors the slot-renamed skip when the live `display_list` array matches `queued_dl_array` AND the live name differs from orig. For sprite-internal pending entries, `display_list` (a global pointer) is swapped back to root by the time `run_pending_finalize` fires, so without the array-pointer guard the comparison was against the wrong slot in root's array — initially regressed `RegisterClassTest4` from 17/42 to 6/42 (commit `96a5d81e`); refined to 17/42 baseline in `f0d575ca` via the array-pointer gate.

- **Verified no regressions** across 32-test AVM1 lifecycle/clone/register/replace battery, 28-test misc-ming.all near-passing battery (incl. all four register_class tests, all loop tests, key_event_test, DragDropTest, replace_*test), 13-test misc-swfc battery, 9-test misc-ming.all loop battery, 12-test misc-ming.all action_order battery. Three small +1 mismatched-line drifts on `action_order/ActionOrderTest3/4/5` are within noise (still output_mismatch — same status, same effective pass).

Net change vs. `8fdf3311` snapshot: misc-ming.all picked up 1 ignored test (`opcode_guard_test`), so filtered effective rose 86/102 (84.3%) → 88/101 (87.1%). The OVERVIEW.md table for misc-ming.all in the prior snapshot under-reported raw effective by 2 (table said 64 PASS + 22 RM = 86, but `results.json` has consistently shown 65 PASS + 23 RM = 88 in both the `d11aa45a` previous CI and this CI). All other suites unchanged.

### Latest fixes (2026-05-07, in CI at `a3912cf2`)

- **`opcode_guard_test` (misc-ming.all) → ignored.** Test cannot promote to `ruffle_matched` because we are *more* correct than Ruffle on the mc1 Construct/Load/Unload event handler assertions, throwing off line alignment with Flash's expected output. We pass every assertion (11/11) and emit one extra `Target not found: Target="non-exist-target" Base="_level0"` warning that Gnash's `output.txt` omits but Flash and Ruffle both produce. Cannot suppress the warning without regressing 8+ AVM1 tests (`tell_target_invalid`, `path_string`, `tell_target`, `removed_base_clip_tell_target`, `swf4_actions_coercion_order`, `property_invalid_base_clip`, `call`, `tell_target_invalid_swf6`) that assert it. Documented in `from_gnash/_investigation/ACCEPTED_DIFFS.md` Category 1 (Gnash Implementation Bugs in Expected Output). New file `misc-ming.all/ignored_tests.txt` created; `.gitignore` updated to allowlist `misc-ming.all/` directory so the per-suite ignore list is tracked alongside `actionscript.all/` and `misc-swfc.all/`.

### Latest fixes (2026-05-07, in CI at `3b477b32`)

- **`TextFormat-v7` (actionscript.all) → ruffle_matched (136/174, was 132/174 → output_mismatch).**
  `ng_getTextExtent` in `SWFModernRuntime/src/libswf/ng_shared.c` now returns
  `textFieldWidth = wrap_width` when a wrap-width arg is provided (i.e.,
  `getTextExtent(text, w)` with `w > 0`). Previously it always returned
  `text_width_px + 4.0` (measured text width + gutter), which is correct for
  the unwrapped case but wrong when wrapping is in play — Flash's `EditText`
  with `AutoSize::Left + word_wrap=true` keeps the assigned width as the
  textfield's width. The fix mirrors Ruffle's `text_format.rs::get_text_extent`,
  which creates an `EditText` with `width.unwrap_or(0.0)` and
  `set_word_wrap(width.is_some())`, then returns `temp_edittext.width()`. With
  word_wrap=true the temp EditText's width stays at the assigned constraint;
  with word_wrap=false AutoSize::Left expands to fit content. Confirmed by
  Ruffle's AVM1 `gettextextent` test, whose expected output has
  `textFieldWidth == 100` for `getTextExtent("Lorem ipsum...", 100)` regardless
  of font size (12 vs 18). Without wrap, behavior unchanged.

  The four wrap-width assertion lines in TextFormat.as (`textFieldWidth == 10`
  at line 380 with wrap=10, `== 5` at 397 with wrap=5, `== 30` at 413 with
  wrap=30, `== 30` at 422 with wrap=30) flipped from FAILED to PASSED, which
  eliminated the only diff-set indices that were ours-but-not-Ruffle's.
  Pre-fix: ours = 42 diffs, Ruffle = 40 diffs, ours \ ruffle = {142, 146, 149,
  152}, ruffle \ ours = {24, 25}. Post-fix: ours = 38 diffs ⊂ ruffle's 40,
  auto-promoting via `verify_output.py::ruffle_subset_match`. The remaining
  ours-vs-expected diffs (font-metric precision: ascent 12.828 vs 11, descent
  3.516 vs 2, etc.) are all in Ruffle's diff set against the same
  `output.txt` — both are due to "dejafont" not being available so we both
  fall back to a different device font. The test source comment explicitly
  acknowledges this: "I don't know how to test this properly, as we can only
  test device fonts here, and the pp uses a different font from Gnash."

  Regression battery: AVM1 `gettextextent` (epsilon=30 tolerance, `with_default_font=true`)
  and `text_format_get_text_extent_undefined_width` (`> 0` checks) both still
  PASS. 8-test edittext battery (`edittext_default_format`, `_align`,
  `_autosize`, `_drag_select`, `_text_height_leading`, `_default_format_empty`,
  `_default_format_font_style`, `_font_size` — 8/8 PASS). Gnash actionscript.all
  `TextFormat-v5/v6` PASS unchanged (their getTextExtent block is gated on
  `OUTPUT_VERSION > 6`, so they don't exercise the wrap-width path). Gnash
  misc-ming text battery (`DefineEditTextTest`, `DefineEditTextVariableNameTest`,
  `DefineEditTextVariableNameTest2`, `DefineTextTest`, `EmbeddedFontTest`)
  unchanged from baseline. Gnash misc-swfc `edittext_test1`, `button_test1`
  unchanged PASS. AVM1 `clone_sprite_edittext`, `clone_sprite_edittext_dynamic`
  unchanged PASS.

### CI snapshot (commit `c8f6452a`, 2026-05-06)

| Suite | Pass | RM | Effective | Total | Rate |
|-------|------|----|-----------|-------|------|
| actionscript.all | 126 | 62 | 188 | 190 | **98.9%** |
| misc-ming.all | 64 | 22 | 86 | 102 | **84.3%** |
| misc-mtasc.all | 7 | 2 | 9 | 9 | 100.0% |
| misc-swfc.all | 8 | 5 | 13 | 15 | **86.7%** |
| misc-swfmill.all | 17 | 1 | 18 | 18 | 100.0% |

Net change vs. `c5994ec1` snapshot: misc-ming.all +4 effective (`key_event_test` 33/66 → ruffle_matched 61/66; `loop/loop_test6` 11/23 → ruffle_matched 22/23), misc-swfc.all +1 effective and total dropped 16→15 (one test moved to ignore list).

### Latest fixes (2026-05-06, in CI at `c8f6452a`)

- **`key_event_test` (misc-ming.all) → ruffle_matched (61/66, was 33/66 → output_mismatch).** Phase 2 of the key-event work narrowed `tagRemoveObject2`'s backward-catch-up early-return so depth-shifted unload bookkeeping no longer suppresses key-event dispatch on the surviving children. See git log `c8f6452a` for the diff. The 5 residual lines are a strict subset of Ruffle's diff against Flash, so the test promotes to ruffle_matched.
- **`loop/loop_test6` (misc-ming.all) → ruffle_matched (22/23, was 11/23 → output_mismatch).** Same root cause (key-event dispatch surviving the catch-up early-return); the single residual line is in Ruffle's diff against Flash.

### Latest fixes (2026-05-04, in CI at `c5994ec1`)

- **`frame_label_test` (misc-ming.all) → PASS (+1, was 12/17 with 153 lines of timeline-loop noise → 17/17 PASS).** Final
  bug behind both the `_root.x1==0` assertion failures and the timeline looping was that `actionCall`'s
  `CALL_FRAME_FUNC` invoked the called frame's recompiler-emitted `actionDrainOnloadAndScript` while the parent frame's
  drain was still in progress. The inner drain processed the parent's pending queue entries — running the
  `_root.x1==0` checks **before** the called frame's `script_0` (`x1=0; x2=0; ...`), and running the parent's `script_34`
  (`_root.totals(); stop()`) inside `actionCall`'s `is_playing` save/restore window so the `stop()` was overwritten on
  call return. Net effect: assertion checks ran against pre-call values (x1/x2/x3 still `mc11_frame4`/...), and
  `is_playing` stayed true so the timeline kept looping. Fix: snapshot `g_aq_count` at the start of `CALL_FRAME_FUNC`,
  bracket the called frame with `actionDrainSuppressEnter`/`Leave`, then drain only entries with index ≥ snapshot via a
  new `actionDrainOnloadScriptAbove(app_context, floor)` helper. Mirrors Ruffle's per-call action stack: each `call()`
  runs its own private action layer, leaving the outer drain's pending queue intact for FIFO continuation. Files:
  `SWFModernRuntime/include/actionmodern/action_queue.h`, `SWFModernRuntime/src/actionmodern/action_queue.c`,
  `SWFModernRuntime/src/actionmodern/action.c`. Verified: 25-test AVM1 call/scope/super/goto battery (call,
  closure_scope, set_variable_scope, goto_methods, local_to_global, string_paths_variable_scopes,
  get_variable_in_scope, function_as_function, function_base_clip, funky_function_calls, swf4_function_calls, watch,
  watch_textfield, on_construct, as2_super_and_this_v6/v8, swf5_to_6_cross_call, execution_order2/3, goto_rewind1/3,
  set_interval, tell_target, path_string, target_path — 25/25 PASS), 14 misc-ming.all goto/loop/action-order tests
  (10 PASS + 2 ruffle_matched + 2 pre-existing `ActionOrderTest3/4` failures unchanged from CI baseline).

- **`soft_reference_test1` (misc-swfc.all) → ruffle_matched (+1, was MISMATCH 23/45 → 44/45).** Root cause was the `_name`
  setter not propagating renames to `parent.dynamic_props` and `var_map`. `createEmptyMovieClip("mc", 10)` registers
  `var_map["mc"]` (root only) and `parent.dynamic_props["mc"]` pointing at the new MC; subsequent `mc._name = "changed"`
  updated `mc->name` and `display_list[d].instance_name` (via `ng_renameDisplayEntry`) but left both bindings stale. The
  test's first assertion (`typeof(mc) == 'undefined'` after rename — frame 3 line 50) then failed because `mc` resolved to
  the now-renamed MC instead of falling through to undefined; nine subsequent assertions failed for the same reason
  (`mc == undefined`, `_level0.changed` lookups, etc.). Fix: in `actionSetMember` MOVIECLIP path at `action.c:40711`,
  after updating `mc->name`/`mc->target` and calling `ng_renameDisplayEntry`, sync `mc->parent->dynamic_props` (set
  new key → MC, clear old key → undefined) and (only when `mc->parent == &root_movieclip`) `var_map` (with SWF<=6
  lowercase folding via the existing `setGlobalVariableByName` helper). The sync only fires when the existing entry is
  authoritative — references THIS MC under a key matching the MC's old name — to avoid clobbering case-collision
  entries (case-v6 path: `_root.clip` vs `_root.CLIP`) or unrelated rebinds. Mirrors Ruffle's `MovieClip::set_name`,
  which removes the old name binding on the parent's stage-object scope and installs the new one. Final residual diff
  is line 164 (`mcRef == _level0.mc1` after `removeMovieClip` + recreate at a different depth — Ruffle also fails
  this), so the test promotes via subset-match to ruffle_matched. Verified: 24-test AVM1 lifecycle/clone/register
  battery (24/24 PASS), 13-test gnash actionscript.all subset including case-v6 / Color-v6 / NetStream-v6/v7 /
  Inheritance-v5..v7 / Selection-v6/7/8 (12/13 effective; 1 missing dir is verifier path bug not a fix regression),
  4-test misc-swfc spot-check (4/4 effective), `opcode_guard_test` and `DepthLimitsTest` unchanged.

- **Global-v6 (actionscript.all) → ruffle_matched (+1).** **Global-v7 (actionscript.all) → PASS (+1).** **Global-v8 (actionscript.all) → PASS (+1).** Implemented `ASSetNative(target, major, props, minor=0)` (was a noop). Splits `props` (post-`toString`) on `,`, strips an optional leading version-flag digit (`'1'`/`'6'`/`'7'`/`'8'`/`'9'`/`"10"`), and binds each non-empty name on `target` to `ASnative(major, minor + position)`. Cross-cutting fix to `convertString` ARRAY case: now consults `objectCallToString` (own-prop-only on `arr->props`) before falling back to `Array.prototype.join(",")` so a user-set `a.toString = function () { ... }` actually fires (required by Gnash's `ASSetNative(o, 200, a, 10)` test). Global-v6 still has unrelated `xcheck_equals` failures around `ASsetPropFlags`-invisible-inherited-setter behaviour (lines 263/264/266/283/284/286), so it lands as ruffle_matched not full pass; v7/v8 don't exercise those paths and pass cleanly. AVM1 `assetnative_ids` (formerly 6-line diff) also flips PASS as a side-effect.

### Latest fixes (2026-05-02, NOT yet in CI)

- **`mouse_drag_test` (misc-swfc.all) → PASS (+1).** Calling `startDrag`
  on a MovieClip now sets `display_obj->transformed_by_script = 1` on
  the dragged clip, mirroring Ruffle's behavior where the per-tick
  `update_drag` calls `set_x`/`set_y` (which set the flag) even when
  the mouse hasn't moved. We don't run an `update_drag` analog in
  headless mode, so the flag is set directly at startDrag time. Once
  set, subsequent timeline `PlaceObject` MOVE tags no-op on the
  dragged clip's matrix (per `apply_place_object`'s
  `if !transformed_by_script` guard in `tag.c`), and the flag persists
  past `stopDrag` — matching Flash semantics where a clip that has
  been dragged stays "transform-locked" for the rest of its lifetime.
  Applied to both the function-form `actionStartDrag` (resolves
  target name → MC via `getMovieClipByTarget` /
  `getMovieClipByRelativeName`) and the method-form
  `mc.startDrag(...)` path. Fixes the four `check(mc1._x != 200/300)`
  / `check(mc1._y != 200/300)` lines in `mouse_drag_test.sc:57-67`
  where prior behavior left `mc1._x == 200` after a `.jump` MOVE
  during an active drag. Regression battery: 5-test AVM1 drag
  (drag_drop, drag_over_from_outside, drag_over_without_startdrag,
  edittext_drag_select, mouse_hover_events_while_dragging — 5/5
  PASS), 18-test transform/timeline (movieclip_setmask, goto_rewind1/2/3,
  execution_order1/2/3/4, tell_target_invalid{,_swf6},
  mouse_hover_events_while_dragging, drag_drop,
  drag_over_from_outside, drag_over_without_startdrag,
  movieclip_default_state, movieclip_get_instance_at_depth,
  movieclip_state_values, swf5_no_closure — 18/18 PASS), Gnash
  `DragDropTest` unchanged (was already failing on level50 droptarget
  paths, output identical pre/post-fix).

- **`swf4opcode` (misc-swfc.all) → ruffle_matched (+1).** SWF4
  `convertFloat` for `ACTION_STACK_VALUE_MOVIECLIP` returned NaN
  unconditionally; should return 0.0 in SWF<5 (matching Ruffle's
  `coerce_to_f64` → `Value::Object(...) → primitive_as_number`,
  which gates Object→0.0 on `swf_version < 5`). Fixes lines 363
  / 365 of the test (`mc1 == undefined` and `/:mc1 == undefined`):
  bytecode is `Push(name) + GetVariable` returning the child MC,
  then SWF4 `Equals` (action 0x0e) coerces both MC and undefined
  to 0.0 → equal → PASSED. Group A (lines 74/82/90/98 —
  `/mc1:_xscale` etc.) still fails but is a subset of Ruffle's
  diff against Flash, so the test promotes to ruffle_matched.
  Verified against 7 SWF4/equals AVM1 tests
  (add_swf4/divide_swf4/equals/equals2_swf5/equals_swf4/equals_swf4_alt/equals_swf5
  — 7/7 PASS) and 9 SWF5/path-related AVM1 tests
  (swf5_no_closure/swf5_to_6_cross_call/funky_function_calls/function_base_clip/path_string/target_path/string_paths_variable_scopes/movieclip_default_state/movieclip_get_instance_at_depth
  — 9/9 PASS), no regressions.

### CI snapshot (commit 48a97e0b, run 25231855425, 2026-05-01)

| Suite | Pass | RM | Effective | Total | Rate |
|-------|------|----|-----------|-------|------|
| actionscript.all | 122 | 63 | 185 | 190 | 97.4% |
| misc-ming.all | 61 | 14 | 75 | 102 | 73.5% |
| misc-mtasc.all | 7 | 2 | 9 | 9 | 100.0% |
| misc-swfc.all | 6 | 3 | 9 | 16 | 56.2% |
| misc-swfmill.all | 16 | 1 | 17 | 18 | 94.4% |

### CI snapshot (commit 61229899, run 2026-04-30)

| Suite | Pass | RM | Effective | Total | Rate |
|-------|------|----|-----------|-------|------|
| actionscript.all | 118 | 60 | 178 | 190 | 93.7% |
| misc-ming.all | 58 | 13 | 71 | 102 | 69.6% |
| misc-mtasc.all | 7 | 2 | 9 | 9 | 100.0% |
| misc-swfc.all | 5 | 3 | 8 | 16 | 50.0% |
| misc-swfmill.all | 15 | 1 | 16 | 18 | 88.9% |

### CI snapshot (commit 205a9a77, run 2026-04-25)

| Suite | Effective pass | Total | Rate |
|-------|----------------|-------|------|
| actionscript.all | 168 | 190 | 88.4% |
| misc-ming.all | 52 | 102 | 51.0% |
| misc-mtasc.all | 8 | 9 | 88.9% |
| misc-swfc.all | 8 | 16 | 50.0% |
| misc-swfmill.all | 16 | 18 | 88.9% |

### Latest fixes (2026-05-01, in CI at 25231855425)

- **Instance-v5 / Instance-v6 / Instance-v7 / Instance-v8 (actionscript.all) → effective +4 (commit faf492a5).** Three changes: (a) `new` on native non-constructor C functions (e.g. `new Math()`, `new Date.UTC()`) creates an empty object with `__proto__ = ctor.prototype` instead of crashing; (b) `Object.prototype` mutation protection — `Object.prototype.x = y` writes are silently dropped in SWF<=5 (matches Flash); (c) non-object prototype propagation: when `Foo.prototype` is set to a non-object value, `new Foo()` falls back to `Object.prototype`.

- **Global-v6 (actionscript.all) → effective +1 (commit 600dc2c1).** `actionGetVariable` now folds the lookup name to lowercase before hitting the built-in registry in SWF<=6, so `Math.max` / `MATH.MAX` / `mAtH.mAx` all resolve to the same builtin (matches SWF<=6 case-insensitive variable resolution).

- **`tags_after_last_showframe` (misc-swfmill) → PASS (+1).** Recompiler
  fix in `SWFRecomp/src/swf.cpp` END_TAG handler: when the SWF has tags
  after the last `ShowFrame`, the recompiler opens a new `frame_N` to
  hold them but no `ShowFrame` ever closes it (`another_frame == false`
  at END_TAG). Previously this dangling frame was treated like a normal
  frame and looped back to `frame_0`, so the trailing DoActions
  re-executed on every iteration (30 lines instead of 1 — 1 expected
  line + 29 cumulative-string repetitions). Fix: emit `quit_swf = 1`
  in the dangling frame instead of `next_frame = 0; manual_next_frame
  = 1`. Mirrors Flash/Ruffle, which run trailing tags only on initial
  play. Single-frame check `next_frame_i == 1` is preserved; new
  `!another_frame` clause covers the dangling case (any
  `next_frame_i`). Regression battery: 14-test goto/execution-order
  AVM1 (14/14), 17-test AVM1 lifecycle/scope (17/17), 14-test
  misc-swfmill (12 PASS + 1 RM + 1 pre-existing MISMATCH for
  `jump_to_prev_block`), 10-test Shumway flat (10/10), 9-test
  misc-ming AVM1 (9 PASS + 2 pre-existing failures `ButtonEventsTest`,
  `action_order` directory recomp_fail), 4-test Shumway avm1 spot
  check (4/4), 3-test Shumway timeline (3/3).

### Latest fixes (2026-04-30, in CI at 25231855425)

- **`movieclip_destruction_test2` (misc-swfc) → PASS (+1).** Cross-cutting
  fix: `actionSetMember` on the root MovieClip now propagates writes to
  `var_map` via a new `setGlobalVariableByName` helper that bypasses the
  local-scope short-circuit in `setVariableByName`. Previously,
  `_root.foo = X` from inside any function dispatched through
  `actionCallMethod`'s MOVIECLIP user-method path (which pushes a local
  scope holding `this`) routed the var_map sync into the local scope:
  `setVariableByName` saw a current local scope and called
  `setVariableOnLocalScope`, which unconditionally created a new property
  on the local scope, leaving `var_map[foo]` stale. Subsequent reads of
  `foo` (without the `_root.` prefix) returned the pre-call value.
  Reproduced by `mc.onUnload()` invoked manually on a pending-removal MC:
  `_root.mc2UnlaodedCount++` updated `root.dynamic_props` (visible to
  `_root.mc2UnlaodedCount`) but not `var_map` (visible to bare
  `mc2UnlaodedCount`). Auto-fired unloads were unaffected because
  `aq_dispatch_timeline_unload` calls the handler via
  `invokeSpecialFunction`, which does not push a local scope for type-1
  functions. The fix preserves `setVariableByName`'s parameter-binding
  semantics for `"this"` and other DefineFunction parameter sites — only
  the root-MC sync inside `actionSetMember` switches to the bypass
  helper. Verified: `unload`, `path_string`,
  `conflicting_instance_names`, `create_empty_movie_clip`,
  `register_class_return_value`, `register_and_init_order`,
  `init_object_order`, `extends_chain`, `as2_super_and_this_v8`,
  `swf5_no_closure`, `swf5_to_6_cross_call`, `execution_order2`,
  `execution_order3`, `set_interval`, `closure_scope`,
  `set_variable_scope`, `local_to_global`,
  `string_paths_variable_scopes`, `get_variable_in_scope`,
  `define_local`, `define_local_with_paths`, `constructor_function`,
  `define_function2`, `swf4_function_calls`, `funky_function_calls`,
  `function_base_clip`, `function_as_function`,
  `infinite_recursion_function_in_setter`, `watch`, `watch_textfield`,
  `watch_virtual_property_proto`, `add_property`, `on_construct`,
  `register_class` — 33/33 PASS, no regressions.

- **`DepthLimitsTest` (misc-ming) → PASS (+1).** AVM1
  `duplicateMovieClip` rejects out-of-range depths (valid AS-depth range
  is [-16384, 2130690044]). Two changes in
  `SWFModernRuntime/src/actionmodern/action.c`:
  1. **Method-form path** (`mc.duplicateMovieClip(name, depth)` inside
     `actionCallMethod`): reject `depth < -16384 || depth > 2130690044`
     directly, push `undefined`, and return. Method-form receives the
     raw AS-depth so the bounds are unbiased.
  2. **Function-form path** (`actionCloneSprite`): reject `depth_int <
     -16384`. The recompiler heuristically strips the SWF +16384 bias
     for I32 pushes (see `action.cpp:1849-1865`), so small AS-depths
     arrive unbiased while large positive depths typically arrive
     biased (≥ 0). The lower-bound check fires only on the unbiased
     path. The upper bound is already enforced by `ng_cloneSprite`'s
     `if (depth > 2130706428)` guard, which catches biased dup5
     (AS-depth 2130690045 → 2130706429). Together this catches the
     two test patterns: function-form `duplicateMovieClip('original',
     'dup3', -16385)` (bias-stripped, depth_int = -16385) and
     `duplicateMovieClip('original', 'dup5', 2130690045)` (bias-kept,
     depth_int = 2130706429). Mirrors gnash test source
     `misc-ming/DepthLimitsTest.c:148-187`. Verified: DepthLimitsTest
     14/17 → 17/17 PASS. 9-test AVM1 regression battery
     (duplicate_movie_clip, duplicate_movie_clip_drawing,
     clone_sprite_edittext{,_dynamic}, clone_sprite_types,
     attach_movie, create_empty_movie_clip, movieclip_depth_methods,
     movieclip_get_instance_at_depth — 9/9 PASS), 4-test Shumway
     duplicateMovieClip suite (4/4 PASS).

- **`ExternalInterface-v6` / `ExternalInterface-v7` (actionscript.all) → PASS (+2).**
  All `ExternalInterface` internal methods (`_argumentsToAS`, `_arrayToAS`,
  `_callIn`, `_escapeXML`, `_initJS`, `_jsQuoteString`, `_objectToAS`,
  `_toAS`, `_toJS`, `_toXML`, `_unescapeXML`, etc.) plus `addCallback`
  and `available` are now marked with `flash_flags = 0x1000` in
  `SWFModernRuntime/src/actionmodern/action.c` (the
  `MAKE_STUB_CTOR(fc_ExternalInterface, ...)` block in `ensureGlobalInit`).
  The `FLASH_HIDE_MASK` for SWF6 (0x7500) and SWF7 (0x7000) both include
  bit 0x1000 → properties are hidden from `getProperty` (so
  `typeof(EI._method)` returns `'undefined'`) but remain in `own_props`
  (so `EI.hasOwnProperty('_method')` still returns `true`). SWF8 mask
  (0x6000) does NOT include 0x1000 → properties become visible. Only
  `EI.call` keeps `flash_flags=0` (visible in all SWF versions, matching
  the gnash test's `check_equals(typeof(EI.call), 'function')` regardless
  of `OUTPUT_VERSION`). Mirrors gnash test source
  `actionscript.all/ExternalInterface.as:65-89` (`#if OUTPUT_VERSION < 8`
  → all internals undefined, `#else` → all functions/boolean). Verified:
  3-test ExternalInterface battery (v6/v7 PASS, v8 still RM unchanged),
  7-test AVM1 ExternalInterface battery (external_interface,
  external_interface_escapexml, external_interface_jsquotestring,
  external_interface_toas_basic, external_interface_toxml_array,
  external_interface_toxml_basic, external_interface_unescapexml — 7/7
  PASS), 7-test gnash adjacent battery (case-v6, Color-v6, Number-v6,
  System-v5/v6/v7/v8 — 7/7 PASS).

- **`case-v6` (actionscript.all) → PASS (+1).** Two-part fix in
  `SWFModernRuntime/src/actionmodern/action.c` for the residual SWF6
  blockers documented in `incomplete/GNASH_FEATURE_PLAN.md` §16.
  1. **Slash-path `SetProperty`/`GetProperty` (Issue A).**
     `actionSetProperty` and `actionGetProperty` now route absolute
     slash-path targets (e.g. `/_ROOT/MC0/`) through
     `resolveSlashPathToMC` when `getMovieClipByTarget` /
     `getMovieClipByRelativeName` both fail. `resolveSlashPathToMC`
     itself switched from `strcmp` to `swf_name_match` for `_root` /
     `_level0` special-name matching, so SWF<=6 case-insensitive
     lookup of the special-name segment works inside slash-path
     traversal. (The display-list/instance-name lookups in the same
     function are left at `strcmp` to avoid surprising other callers;
     the dynamic_props fallback already uses `getProperty` which is
     case-insensitive in SWF<=6 via `prop_name_match`.) Trailing `/`
     was already supported. Required by case.as:62-71's inline-asm
     `setproperty` of `mC0._X = 100` via `/_ROOT/MC0/`.
  2. **Case-insensitive `createEmptyMovieClip` variable rebind
     (Issue B).** The method-form `createEmptyMovieClip` path inside
     `actionCallMethod` now skips `setProperty(parent.dynamic_props,
     name, ...)` and (for root receivers) `setVariableByName(name,
     ...)` when the existing entry references a LIVE MovieClip
     **and** that MC's current `name` still matches the
     dynamic_props key / var_map key (case-insensitively in SWF<=6
     via `swf_name_match`). The "authoritative" check —
     `swf_name_match(existing_mc->name, entry_name)` — distinguishes
     three patterns:
       - case-v6 case.as:96-170: `_root.createEmptyMovieClip("clip",
         6)` then `_root.createEmptyMovieClip("CLIP", 7)`. The
         existing `_root.clip` entry's MC is named "clip" (matches
         key) → authoritative → skip rebind, `_root.clip` /
         `_root.CLIP` stay bound to MC1 at depth 6.
       - misc-swfc/soft_reference_test1.sc:107-147: createEmpty(mc1,
         30) → `mc._name = "mc2"` → createEmpty(mc1, 50). The
         existing `_root.mc1` entry's MC is now named "mc2" (does
         NOT match key "mc1") → stale → allow rebind, `_root.mc1`
         updates to the depth-50 MC. Verified by line 147's
         `check_equals(mc1.getDepth(), 50)` flipping from FAILED to
         PASSED.
       - misc-ming/loadMovieTest: `this.createEmptyMovieClip('tc',
         8)` repeatedly. Depth-conflict loop sets
         `dynamic_props["tc"]` to UNDEFINED before the new MC is
         created → existing entry isn't a MOVIECLIP → fall through
         and overwrite. Dead-MC pointers (`depth == INT_MIN`) also
         fall through. For non-root receivers `setVariableByName`
         remains unconditional, matching the prior behavior that
         loadMovieTest's `_root.check(tc instanceof MovieClip)`
         relies on.
     The dynamic_props lookup uses `findPropertyRaw` so it can read
     the existing entry's exact-cased key (not just the value), and
     the var_map lookup folds the lookup key with ASCII
     `[A-Z]→[a-z]` to mirror `setVariableByName` /
     `getVariableByName`'s SWF<=6 fold.
  Verified: 8-test AVM1 path battery (movieclip_state_values,
  path_string, slash_syntax, string_paths_basic, swf5_no_closure,
  target_path, tell_target_invalid, tell_target_invalid_swf6 — 8/8
  PASS), 9-test AVM1 createEmptyMovieClip / instance-name battery
  (attach_movie, conflicting_instance_names, create_empty_movie_clip,
  init_object_order, movieclip_init_object, movieclip_state_values,
  path_string, slash_syntax, target_path — 9/9 PASS), 14-test gnash
  actionscript.all primitives battery (Boolean-v5/v6, Color-v5..v8,
  Inheritance-v5/v6, Number-v5..v8, toString_valueOf-v5/v6 — 9 PASS
  + 5 RM = 14/14 effective), 11-test gnash mixed battery
  (Inheritance-v5/v6, MovieClip-v5 unchanged mismatch, Selection-v6
  RM, Stage-v5, case-v5 unchanged mismatch, case-v7, case-v8,
  targetPath-v6/v7/v8 RM — 4 PASS + 6 RM + 1 pre-existing mismatch),
  4-test case-vN battery (case-v5 unchanged mismatch, case-v6/v7/v8
  PASS), and 7-test misc-ming battery covering the regression case
  (DefineEditTextTest, attachMovieTest, instanceNameTest,
  loading/loadMovieTest, loop/loop_test3, loop/loop_test5,
  replace_sprites1test — 6 PASS + 1 RM = 7/7 effective; the
  `loadMovieTest` ruffle_matched is the regression target — its
  inner `coverart.createEmptyMovieClip('tc', 8)` call still rebinds
  `tc` globally because `tc_mc` from prior calls is dead post
  depth-conflict cleanup).

### Earlier fixes (2026-04-29, pending CI)

- **`replace_sprites1test` (misc-ming) → PASS (+1).** Two-part fix in
  `SWFModernRuntime/src/libswf/tag.c` for the AVM1 PlaceObject2/3 REPLACE
  pattern (move=1 + has_character=1) where an existing sprite at a depth is
  replaced by a *different* sprite character ID. Mirrors Ruffle's
  `PlaceObjectAction::Replace` path
  (`core/src/display_object/movie_clip.rs:4341-4357`):
  `child.replace_with(context, id)` is a no-op for MovieClip (default impl in
  `display_object.rs:2543-2546`), and `apply_place_object`
  (`display_object.rs:2492-2540`) updates only matrix / cxform / ratio —
  `name`, `clip_depth`, and `clip_actions` are explicitly excluded
  ("Purposely omitted properties: name, clip_depth, clip_actions"). No fresh
  CONSTRUCT/INIT/LOAD events fire because no fresh instantiation occurs.
  1. **`tagPlaceObject2` / `tagPlaceObject2Ratio`** now detect the cross-frame
     sprite-by-sprite REPLACE pattern (`existing.char_id != 0` && different
     `char_id` && `place_gen != current` && existing has `sprite_display_list`
     && new `dictionary[char_id].type == CHAR_TYPE_SPRITE`) and treat it as a
     modify: update `transform_id` / `cxform_id` / `ratio` only (gated on
     `transformed_by_script` and `cx_overridden` like the survives-rewind
     paths), discard pending `instance_name` / `clip_actions`, and call
     `ng_on_place_object2(...)` with the *existing* `char_id` so display-state
     sync stays consistent.
  2. **`tagSetInstanceName`** now stashes the name as `g_pending_instance_name`
     (instead of renaming in-place) when the existing entry at this depth was
     placed by a previous frame and is a sprite. The companion
     `tagPlaceObject2*` REPLACE-preservation path discards the pending name
     (matching Ruffle's "name omitted on subsequent PlaceObject"), while the
     rare full-replacement fallback can still consume it.
  Without these, frame-2's `tagSetInstanceName(3, "static2")` renamed depth 3
  in-place from "static1"→"static2", and `tagPlaceObject2WithClipActions`
  fully replaced the sprite — firing static2's `onClipConstruct (replace)`
  handler and breaking all subsequent `static1.*` lookups. Bundles into
  ZERO_OUTPUT_TRIAGE Phase 2 (companion to commit 8b6a0e34's non-sprite
  CONSTRUCT/INIT/LOAD gating). Verified: 35-test AVM1
  clip-event/lifecycle/rewind/unload/placement guardrail battery (35/35
  effective — 34 PASS + 1 ruffle_matched, no regressions).

- **Clip CONSTRUCT/INITIALIZE/LOAD events now sprite-only (Flash semantics).**
  `queue_clip_init_events`, `queue_clip_construct_events`, and
  `queue_clip_load_events` in `SWFModernRuntime/src/libswf/tag.c` now bail
  out early unless `dictionary[char_id].type == CHAR_TYPE_SPRITE`. Previously
  these events fired for any character with attached `clip_actions`, including
  buttons and shapes. Mirrors Ruffle's `Avm1Button::propagate_clip_event`
  (`core/src/display_object/avm1_button.rs:417-433`) which only handles mouse
  + KeyPress, and the absence of clip-event dispatch on shape/morph-shape/text
  display objects. Targets `replace_buttons1test` / `replace_shapes1test`
  (misc-ming, ZERO_OUTPUT_TRIAGE Phase 2): both produced 3+ extra leading
  `_level0.staticN onClipConstruct` / `PASSED: movieclip == movieclip` /
  `_root.depth3Constructed set to N` lines per replacement. Effect:
  replace_buttons1test 0/22 matching → 5/22 matching (extra-leading gone, 7
  later FAILs remain — separate name-resolution-after-replace issue);
  replace_shapes1test similar (10 matching, 4 later FAILs remain). 21-test
  AVM1 button/clip-event/goto-rewind/unload guardrail battery: 21/21 PASS,
  no regressions. 12-test misc-ming lifecycle battery: 10/12 (only the two
  target tests still fail, as expected).

- **Verifier: empty data files now generate valid C (ZERO_OUTPUT_TRIAGE Phase 1).**
  `generate_data_registry` in `ruffle-tests/verify_output.py` emitted
  `static const char data_empty_txt[] = { , 0x00 };` (leading-comma C syntax
  error) when a sidecar data file like `empty.txt` was zero-bytes; gcc
  errored `data_registry.c:5:40: error: expected expression before ','`.
  Now emits `{ 0x00 }` for the empty case. Effect: `loading/LoadVarsTest`
  flips from `compile_fail` to `output_mismatch` (26/29 lines match — 3
  remaining FAILs are LoadVars `decode()`-callback bugs, separate work).

- **HitTest-v6 / HitTest-v7 / HitTest-v8 (actionscript.all) → ruffle_matched (+3 effective).**
  Three-part fix to the AVM1 `MovieClip.hitTest` implementation in
  `SWFModernRuntime/src/actionmodern/action.c`:
  1. **`mcGetOriginalBounds` for root.** Removed the `if (mc != &root_movieclip)`
     gate around the dynamic-children fallback (was added in de8b5c0b for an
     unrelated fix). Without it, `_root._width` on a movie whose only children
     come from `createEmptyMovieClip`/`attachMovie` returned `nat_w = 0`, which
     made `mcSetEffectiveWidth(root, N)` zero out both `xscale` and `yscale`
     via the empty-clip branch — and `_xscale = 100;` only restores xscale, so
     yscale stayed 0 and silently degenerated every subsequent `hitTest` world
     matrix to `d=0` (lines 38–40 / 45–48 / 73–76 of HitTest expected the
     post-`a._y = 100` translation to propagate, but the collapsed yscale in
     `getConcatMatrixForMC` zeroed out the y component). Mirrors Ruffle's
     `bounds(BoundsMode::Script)` which recurses through children regardless of
     whether the receiver is the root.
  2. **Winding-number test for un-finalized drawing paths.** New
     `drawingCmdWindingHitTest` walks the live `DrawCmd` list (no `endFill`
     yet, so `path_count == 0`) and computes a winding number using
     half-open y intervals — mirrors Ruffle's `winding_number_line`
     (`render/src/shape_utils.rs:976`) and its NonZero rule. Replaces the
     prior over-approximation `path_count == 0 && cmd_count > 0 → hit = 1`
     which always reported a hit anywhere in the per-MC bounds, so corners
     and exterior-of-polygon points (lines 11/14, 37, 65–68) reported true
     even though Flash/Ruffle return false there.
  3. **Round matrix → twips for hit test.** Both the test point's root-space
     transform and the world-AABB corner transforms in `COMPUTE_GLOBAL_AABB`
     now `round(...)` the resulting twip values, mirroring Ruffle's
     `round_to_i32` in `Matrix * Point<Twips>` / `Matrix * Rectangle<Twips>`
     (`render/src/matrix.rs:208,229`). Without this, `_xscale = 0.5;
     b.hitTest(151, 250, false)` computes the test point at twip 15.1 vs
     gxmax = 15.0 (out), while Ruffle rounds 15.1 → 15 (in). Line 83.
  Net effect: each test goes from 12–17 line diffs to a diff that is a
  subset of Ruffle's 7-line diff against gnash, promoting all three to
  ruffle_matched. Verified on a 44-test AVM1 lifecycle/hit-test battery
  (44/44 — no regressions across `hittest_lockroot`, `hittest_morph`,
  `hittest_winding_rule`, `movieclip_hittest`, `bitmap_data_hittest`,
  `movieclip_setmask`, `selection`, `goto_*`, `unload`, etc.), a 17-test
  AVM1 transform/bounds battery (17/17 — `as_transformed_flag`,
  `color_transform`, `matrix`, `transform`, `edittext_width_height`,
  `movieclip_invalid_get_bounds_1..8`, etc.), a 37-test gnash actionscript
  primitives + HitTest battery (36/37 effective — only pre-existing
  `array-v5` failure unchanged), and a 15-test misc-ming recently-fixed
  battery (15/15).

- **Number-v5 (actionscript.all) → ruffle_matched (+1 effective).** `convertFloat`
  in `SWFModernRuntime/src/actionmodern/action.c` now coerces plain OBJECTs to
  NaN in SWF5+ when the valueOf-fallback is hit (i.e., `Object.prototype.valueOf`
  returned `this`), matching Ruffle's `primitive_as_number` gate
  (`core/src/avm1/value.rs:157` — `Value::Object(_) if swf_version() < 5 => 0.0`,
  otherwise NaN). FUNCTION receivers still fall through to the SWF<6 → 0.0 path
  to preserve the Flash quirk that `2 + Number` is `2`, not NaN (Number.as:231,
  PASSED in Flash, FAILED in Ruffle — we keep matching Flash here while Ruffle
  diverges). Net effect on Number-v5: the two `0+(new Object())` /
  `ToNumber(new Object())` lines (84/177 — gnash test source Number.as:225/442)
  now match Flash, and the remaining 6 functional diffs (Number.prototype/valueOf/
  toString/__proto__ visibility in SWF5) are all in Ruffle's diff set, so the
  test promotes to `ruffle_matched` via subset-of-Ruffle. No regressions on a
  17-test gnash primitives battery (Boolean-v5/v6, Color-v5/v6/v7/v8,
  Inheritance-v5/v6, Number-v5/v6/v7/v8, array-v5, toString_valueOf-v5/v6/v7/v8 —
  4 PASS unchanged + 7 ruffle_matched + Number-v5 newly ruffle_matched).

### Earlier fixes (2026-04-25, pending CI)

- **loop_test8 (misc-ming) → PASS (+1, 37/38 → 38/38).** Two-part fix for
  the trailing `_level0.mc5unloaded` trace:
  1. New `actionQueueClipActionUnloadDeferred` helper in
     `SWFModernRuntime/src/actionmodern/action.c` queues a clip-action
     UNLOAD callback as `kind=SCRIPT, is_unload=0` (rather than
     `kind=ONLOAD, is_unload=1`). This makes the entry invisible to
     `actionFirePendingUnloads` so the nested `tagShowFrame` inside
     `ng_executeGotoCatchUp`'s per-frame replay doesn't drain it
     mid-rewind. Instead it rides the outer `actionDrainOnloadAndScript`
     FIFO and lands after the calling gotoAndStop/Play script.
  2. `tagPlaceObject2` / `tagPlaceObject2Ratio`
     (`SWFModernRuntime/src/libswf/tag.c`) backward-rewind
     clear-and-replace path now calls
     `actionQueueClipActionUnloadDeferred` for the displaced MC's
     clip-action UNLOAD bits (current + accumulated) BEFORE calling
     `actionMarkMCPendingRemoval`. Previously only the Mark ran, dropping
     the CLIP_EVENT_UNLOAD trace entirely when a backward goto replaced
     an MC with a different ratio (loop_test8 frame 6 `gotoAndStop(3)`
     replaces mc5 ratio=0.003 with mc3 ratio=0.001 —
     `survives_rewind=false`).
  An earlier attempt added an `if (!catch_up_mode)` gate around
  `actionFirePendingUnloads` in `tagShowFrame`, but that regressed
  `reverse_execute_PlaceObject2_test2` (10/10 → 5/10) because the
  rewind's `tagPlaceObject2` then survives_rewind a not-yet-finalized
  pending entry instead of fresh-placing it. The Deferred-variant
  approach above keeps the existing drain timing intact.
  Verified: 36-test AVM1 lifecycle/goto/placement battery (36/36),
  25-test misc-ming recently-fixed battery (25/25 effective),
  4-test misc-swfc battery (movieclip_destruction_test2 unchanged at
  50/52), 4-test Shumway duplicateMovieClip suite (4/4).

### Earlier fixes (2026-04-24, in CI at 205a9a77)

- **ResolveEventsTest (misc-ming) → PASS (+1).** `actionCallMethod`
  (`SWFModernRuntime/src/actionmodern/action.c`) now invokes the
  `__resolve` hook when a method lookup on a MovieClip receiver fails,
  mirroring the existing OBJECT path. Lookup walks `mc->dynamic_props`
  (+ `__proto__` chain), then `MovieClip.prototype`. The hook is
  invoked with `this = mc` (MOVIECLIP type — set on a fresh local
  activation and via `g_event_this_mc` for type-2 functions),
  captured WITH scopes restored, version switched via
  `switchToFunctionVersion`, and `base_clip` set per SWF6+ closure
  rules. If `__resolve` returns a function, it is invoked with the
  original call args and `this = mc`; otherwise the resolved value
  is discarded and `undefined` is pushed. Test pattern:
  `mc1.__resolve = function(a){ resolveevents.push(a); }; mc1.func()`
  → 'func' captured into resolveevents (and same for onEnterFrame /
  onRollOver). No regressions on a 23-test AVM1 lifecycle/MC-method
  battery, a 19-test misc-ming recently-fixed battery, or a 4-test
  misc-swfc spot-check (line counts unchanged on the pre-existing
  failures button_test1 and movieclip_destruction_test2).

- **event_handler_scope_test (misc-ming) → PASS (+1).**
  `actionDispatchEnterFrameHandlers` (`SWFModernRuntime/src/actionmodern/action.c`)
  now pushes a fresh local activation `ASObject` and switches `g_current_context`
  to `func->base_clip` for the child-MC type 1 (`DefineFunction`) dispatch
  path, matching `actionCallMethod` / `runStoredFunctionCallback`. Without
  these, plain assignments inside
  `mc.onEnterFrame = function(){ scope_test = 3; var scope_test = 4; }` fell
  through `actionSetVariable`'s "tellTarget non-root context" branch onto
  `mc.dynamic_props` (because `g_current_context` was still the receiver
  `mc` rather than the function's defining clip), and `actionDefineLocal`
  leaked `var scope_test = 4` onto `mc.dynamic_props` for the same reason.
  Scoped to type 1 only — type 2 (`DefineFunction2`) already manages its
  hoisted locals via the per-call register array, and adding the same push
  to the type 2 path regressed `avm1/form_loader_encoding_1` /
  `form_loader_encoding_4` in CI. No regressions on a 28-test AVM1
  lifecycle/event battery, 24-test AVM1 broader battery, or 17-test
  misc-ming recently-fixed battery.

- **Selection-v6 / Selection-v7 / Selection-v8 (actionscript.all) → ruffle_matched (+3 effective).**
  `builtin_selection_setFocus` (`SWFModernRuntime/src/actionmodern/action.c`)
  now falls back to `getMovieClipByRelativeName` when `getMovieClipByTarget`
  returns NULL on a STRING argument — mirrors Ruffle's
  `resolve_target_display_object(start_clip, *focus, false)` in
  `core/src/avm1/globals/selection.rs:140`, which resolves relative to the
  caller's target clip. Previously `Selection.setFocus("mc")` returned
  `false` because `getMovieClipByTarget` only handles absolute `_root` /
  `_level0` / `/…` paths, while the gnash Selection test expects bare-name
  resolution against the current target. This fixed the one line
  (`Selection.as:121` — `setFocus("mc")` returns `true` like Flash/Ruffle)
  where our diff against Flash's `output.txt` was a superset of Ruffle's
  diff, so the remaining Selection output_mismatch lines (setSelection
  single-arg and 3-arg no-op divergence — Flash treats odd-count as no-op,
  Ruffle/we treat as normal set) now promote all three Selection-vN tests
  to `ruffle_matched` via the existing subset-of-Ruffle promotion. The
  `"tx"` relative lookup at `Selection.as:102` returns `NULL` (tx is an
  undefined variable, not a child MC), so the setFocus("tx") Flash-match at
  that line is preserved. No regressions on the AVM1 `selection` test
  (453/455 PASS unchanged) or a 15-test AVM1 battery covering
  selection/button_children/clip_events/attach_movie/on_construct/
  register_and_init_order/init_object_order/movieclip_state_values/
  goto_rewind1/2/3/unload/unload_clip_event/stage_object_properties/
  movieclip_get_instance_at_depth — 15/15 pass.

### Earlier fixes on 2026-04-24 (in CI at 205a9a77)

- **loop/loop_test8 (misc-ming) — +3 lines (34/38 → 37/38 matching).**
  Backward-rewind clear-and-replace path in `tagPlaceObject2` /
  `tagPlaceObject2Ratio` (`SWFModernRuntime/src/libswf/tag.c`) now calls
  `actionMarkMCPendingRemoval` on the existing named MC before clearing
  it, so the old MC persists in the "removed depth zone" for one frame
  and remains resolvable by name (`typeof(mc5) == 'movieclip'`). The
  call is gated on `has_unload` (clip-event UNLOAD bit 0x4, accumulated
  clip actions, AS-level `onUnload` property, or any child sprite with
  an UNLOAD handler), mirroring the existing gate in
  `ng_on_remove_object`. Without the gate, MCs that should disappear
  immediately (e.g. `loop_test5/movieClip3`, which has only a CONSTRUCT
  clip action) would incorrectly persist; loop_test5 verified to still
  pass. The remaining failing line on loop_test8 is the trailing
  `_level0.mc5unloaded` trace, which requires the deferred clip-event
  UNLOAD mechanism (the loop_test7 blocker — clip-event UNLOAD must be
  queued via `is_unload=true` to fire after `totals()`).
  Mirrors Ruffle's `remove_child` → `should_delay_removal` path
  (`core/src/display_object/container.rs:330-360`) called from
  run_goto's survives_rewind=false branch
  (`core/src/display_object/movie_clip.rs:1685-1694`). No regressions
  on a 37-test AVM1 rewind/unload/placement battery
  (goto_rewind1/2/3, execution_order1/2/3, goto_execution_order/2,
  goto_both_ways1/2, rewind_depth, unload, unload_clip_event,
  unload_nested_child, unloadmovie, mcl_unloadclip,
  depth_replacement_audio_unloading, textsnapshot_available_text,
  clip_events, on_construct, register_and_init_order,
  movieclip_state_values, movieclip_library_state_values,
  bad_placeobject_clipaction, movieclip_in_removed_button,
  button_children, attach_movie, set_interval,
  movieclip_depth_methods, movieclip_get_instance_at_depth,
  movieclip_name_from_timeline, conflicting_instance_names,
  default_names, access_unnamed_shape, named_shapes,
  place_and_lookup, placeobject_occupied_depth — 36/37 pass +
  1 ruffle_matched), an 18-test misc-ming recently-fixed battery
  (loop_test2/3/5/8/9, instanceNameTest, attachMovieTest,
  DefineEditTextTest, DefineEditTextVariableNameTest2,
  static_vs_dynamic1/2, displaylist_depths_test11,
  place_and_remove_object_test, get_frame_number_test, shape_test,
  test8-v5/v6, new_child_in_unload_test — 17/18 pass, only loop_test8
  still output_mismatch at 37/38), the 4-test Shumway
  duplicateMovieClip suite (4/4), 4-test misc-swfc battery
  (stackscope/edittext_test1/submoviegetvar pass,
  movieclip_destruction_test2 unchanged at 52/56), and a 31-test
  AVM1 broad battery covering super/this/string/object/text/loadvars
  (30/31 pass, loadvariables_method failure pre-existing in CI).


- **movieclip_destruction_test2 (misc-swfc) — +9 lines (41/56 → 50/56 matching).**
  Three-part fix to make removed-but-still-referenced MCs match Flash's
  "removed depth zone" semantics:
  1. `actionFireOnUnload` (`SWFModernRuntime/src/actionmodern/action.c`)
     now sets `mc->avm1_removed = 1` and shifts
     `mc->depth = -(swf_depth) - 1 - 16384` BEFORE invoking the AS-level
     handler — so `getDepth()` inside `mc.onUnload` returns the
     post-removal depth (test expects -16387 for a swf_depth=2 MC).
     `actionMarkMCPendingRemoval` and `actionInvalidateCachedMovieClip`
     were updated to accept the shifted depth in their lookups and skip
     the redundant re-shift. `ng_on_remove_object`
     (`SWFModernRuntime/src/libswf/tag_stubs.c`) now computes
     `has_unload` (including the AS-level `actionMCHasOnUnloadProperty`
     check) BEFORE the depth shift, since the property lookup uses the
     pre-shift `as_depth`.
  2. `swapDepths` (the MC method handler in
     `SWFModernRuntime/src/actionmodern/action.c`) now early-returns
     when the receiver `mc->avm1_removed`/`pending_removal` is set, AND
     when the MOVIECLIP target argument is similarly removed. Removed
     MCs in the "removed-depth zone" have a fixed depth that swap can't
     change.
  3. Numeric-form `swapDepths(N)` no longer clamps out-of-range depths
     to `[-16384, 2130690044]` — it now early-returns leaving depth
     unchanged when `N < -16384` or `N > 2130690044`. Test lines 175-183:
     `mc1.swapDepths(-16385)` / `swapDepths(-32769)` are no-ops; only
     the in-range `swapDepths(-16384)` succeeds.
  Two failing lines remain (`mc2UnlaodedCount == 2` after explicit
  `mc2.onUnload()` call at lines 156-157). The user-method dispatch IS
  invoking the function on the pending-removal MC (debug-confirmed
  during this session) but the function body produces no trace output
  despite running through ~8 `actionBaseClipRemoved` checks (all
  returning 0). Likely a deeper issue with how the inner
  `_root.check_equals` calls behave when invoked from a
  user-method-dispatched function on a pending-removal MC. Not a
  regression — these lines were already failing pre-fix. No regressions
  on a 24-test AVM1 lifecycle battery (unload/clip_event/goto_rewind/
  execution_order/on_construct/register_and_init_order/movieclip_state_values/
  set_interval/swf5_to_6_cross_call/attach_movie etc. — 24/24 effective),
  16-test misc-ming recently-fixed battery (loop_test3/5/9,
  instanceNameTest, attachMovieTest, DefineEditTextTest,
  DefineEditTextVariableNameTest2, static_vs_dynamic1/2,
  displaylist_depths_test11, place_and_remove_object_test,
  get_frame_number_test, shape_test, action_execution_order_test8-v5/v6,
  new_child_in_unload_test — 16/16 pass), or the Shumway
  duplicateMovieClip suite (4/4 pass).


- **loop/loop_test3 (misc-ming) → PASS (+1).** Three-part fix so a
  `swapDepths`-then-backward-`gotoAndStop` correctly preserves the MC
  that now occupies the target frame's depth slot and destroys the one
  that doesn't, matching Ruffle's AVM1 `survives_rewind`
  (`core/src/display_object/movie_clip.rs:1812`, MovieClip branch =
  `ratio_equals` only):
  1. `ng_swapDisplayDepths` / `ng_updateDisplayDepth`
     (`SWFModernRuntime/src/libswf/tag_stubs.c`) now keep
     `placed_at_frame` / `place_gen` pinned to the depth slot on swap
     instead of moving them along with the struct. These two fields
     track *which PlaceObject2 tag put something at this depth*, not
     the MC's identity — so after `mc1.swapDepths(mc2)` the depth
     that originally received mc1 in frame 1 still reports
     `placed_at_frame = 1` even though mc2's struct now lives there.
     The empty-target branch of `ng_updateDisplayDepth` sets the
     destination slot's `placed_at_frame` to `current_frame` (the
     move isn't a tag placement — rewind should clear it).
  2. `tagPlaceObject2` / `tagPlaceObject2Ratio`
     (`SWFModernRuntime/src/libswf/tag.c`) backward catch-up
     `survives` check now mirrors Ruffle's MovieClip branch:
     `existing_is_mc = (sprite_display_list != NULL) ⇒ ratio_equals
     alone`. Non-MC types (shapes, buttons, text, bitmaps) still
     require `id_equals`. When an MC survives, `ng_on_place_object2`
     is called with the EXISTING `char_id` instead of the tag's, so
     we don't accidentally reinitialize the preserved MC as the new
     character.
  3. `tagSetInstanceName` (`SWFModernRuntime/src/libswf/tag.c`) now
     pends the name whenever `catch_up_backward && (placed_at_frame
     > current_frame || depth_swapped)` — without the `depth_swapped`
     arm, `tagSetInstanceName(d, "movieClip1")` at target-frame
     replay would rename the swapped-in mc2 struct to "movieClip1",
     destroying both MCs' names. With the per-depth placed_at_frame
     fix alone, swapped entries no longer have
     `placed_at_frame > current_frame` and the existing gate missed
     them.
  The test does: frame 1 places mc1 at d=3, frame 2 places mc2 at d=4
  and swaps, frame 3 `gotoAndStop(2)` + checks. Expected: mc2 survives
  at d=3 (ratio-matches final_placement at that depth), mc1 at d=4 is
  destroyed (no final_placement). Also flips **loop/loop_test2** from
  failing (6/15) to passing (+1 effective). No regressions on a
  20-test AVM1 rewind/unload battery (`goto_rewind1/2/3`,
  `execution_order1/2/3`, `goto_execution_order/2`, `goto_both_ways1/2`,
  `rewind_depth`, `unload`, `unloadmovie`, `unload_clip_event`,
  `unload_nested_child`, `mcl_unloadclip`,
  `depth_replacement_audio_unloading`, `textsnapshot_available_text`),
  a 24-test AVM1 placement/name battery (`conflicting_instance_names`,
  `default_names`, `named_shapes`, `access_unnamed_shape`,
  `movieclip_depth_methods`, `movieclip_get_instance_at_depth`,
  `movieclip_name_from_timeline`, `place_and_lookup`,
  `bad_placeobject_clipaction`, `clip_events`, `register_and_init_order`,
  `movieclip_state_values`, `movieclip_library_state_values`,
  `on_construct`, `register_class_return_value`, `init_object_order`,
  `init_object_invalid`, `movieclip_init_object`, `attach_movie`,
  `attach_movie_stop`, `empty_movieclip_can_attach_movies`,
  `button_children`, `movieclip_in_removed_button`,
  `placeobject_occupied_depth` — 23 pass + 1 ruffle_matched), the
  4-test Shumway duplicateMovieClip suite (`dontremove`,
  `duplicateMovieClip`, `samedepth`, `name-coercion`), a 20-test
  misc-ming recent-fixes battery (`loop_test3/4/5/9`,
  `displaylist_depths_test11`, `place_and_remove_object_test`,
  `static_vs_dynamic1/2`, `shape_test`, `attachMovieTest`,
  `get_frame_number_test`, `instanceNameTest`, `DefineEditTextTest`,
  `DefineEditTextVariableNameTest2`, `new_child_in_unload_test`,
  `timeline_var_test`, `reverse_execute_PlaceObject2_test1/2`,
  `action_execution_order_test8-v5/v6`), or the 3 misc-swfc passing
  tests (`edittext_test1`, `stackscope`, `submoviegetvar`). Line
  counts on 6 near-passing swap/placement-adjacent failing tests
  (`duplicate_movie_clip_test/2`, `consecutive_goto_frame_test`,
  `goto_frame_test`, `displaylist_depths_test2/3`) unchanged within
  ±1 line (no substantive regression).

- **new_child_in_unload_test (misc-ming) → PASS (+1).** Cascading unload
  for dynamic children of timeline-removed MCs. `tagRemoveObject2` now calls
  a new `actionQueueDynamicChildUnloads(parent_mc)` helper (wrapping
  the existing static `queueChildOnUnloads`) between `fire_recursive_child_unloads`
  and the parent's own `CLIP_EVENT_UNLOAD` clip actions, so AS-level
  `onUnload` handlers on dynamic children created via `createEmptyMovieClip`
  / `duplicateMovieClip` (which live in `child_mc_cache`, not the parent
  sprite's `display_list`) are queued and fire at the next `tagShowFrame`.
  Queue-BEFORE-own-UNLOAD ordering matches Flash's observed behavior that
  a dynamic child created inside the parent's UNLOAD handler does NOT get
  its onUnload triggered (case1: dyn1 in the test source). Children that
  existed before the removal (case2: dyn2) do fire. Second part:
  `actionFinalizePendingRemovals` now cascades `depth = INT_MIN`
  invalidation to dynamic children of just-finalized MCs (iterate until
  no-change so grandchildren are reached), so `dyn1Ref.valueof() == null`
  picks up the dead-MC-valueOf path at frame 4. No regressions on a
  28-test AVM1 lifecycle battery, a 14-test misc-ming recent-fixes battery,
  the 4-test Shumway duplicateMovieClip suite, or the misc-swfc
  destruction tests (pre-existing failures unchanged; stackscope still
  passes).

- **LoadVars-v6/v7/v8 (actionscript.all) → ruffle_matched (+3 effective).** Two-part fix in `SWFModernRuntime/src/actionmodern/action.c` pushed all three LoadVars-vN tests from `output_mismatch` (146/152 matched) to `ruffle_matched` — our diffs are now a proper subset of Ruffle's diffs against Flash's `output.txt`.
  1. `objectCallToString` now signals `*found = 1` when the `toString` property exists in the prototype chain but is not callable (e.g. `obj.toString = undefined` or `obj.toString = 5`). This propagates through `convertString`'s OBJECT branch so user-shadowed non-callable toString coerces to `"[type Object]"` via the `found && non-string` path, matching Ruffle's `Value::coerce_to_string` (`core/src/avm1/value.rs:319-334` — `call_method("toString")` returns non-string → `[type Object]`). Fixes the `o.toString = undefined; lv2.toString()` line expecting `a=%5Btype%20Object%5D` instead of `a=%5Bobject%20Object%5D`. +2 lines per LoadVars-vN test.
  2. `builtin_xml_load` now returns `false` when `this` is not a NATIVE_XML (mirrors `core/src/avm1/globals/xml.rs:414` — `if let NativeObject::Xml(_) = this.native()`). The LoadVars test reassigns `x.load = XML.prototype.load` on a LoadVars instance and expects `false`; we were running the XML-load logic on a LoadVars this, which fired the synchronous onData/onLoad chain, producing extra out-of-order trace lines (the `x['var2']` check at line 183 and `check_totals(144)` at line 184 fired *inside* the wrong-this x.load call, bumping our diff set out of Ruffle subset). Returning false immediately keeps the ordering matching Ruffle. Fixes the remaining 2 diff lines on each LoadVars-vN.
  No regressions on a 12-test AVM1 string/object coerce battery (`string_coercion`, `add`, `this_scoping`, `mutable_this`, `asnew`, `native_objects_swf7/8`, `coerce_to_object_monkeypatch`, `coerce_to_primitive_resolve`, `object_string_coerce_swf5/6`, `string_methods`), a 12-test Gnash Number/String/Boolean/toString_valueOf-vN battery (11 effective pass — only Number-v5 remains failing, unchanged from pre-change), a 29-test AVM1 broad battery (register_class/attach_movie/execution_order/goto_rewind/unload/clip_events etc.), a 5-test AVM1 LoadVars/loadvariables battery (2 pre-existing failures unchanged), or a 4-test Gnash toString_valueOf-v5/v6/v7/v8 (all still ruffle_matched).

- **movieclip_destruction_test2 (misc-swfc) — partial (+4 lines, 37/56 → 41/56 match).** `builtin_object_valueOf` now returns `ACTION_STACK_VALUE_NULL` when the MovieClip receiver has been invalidated (`g_event_this_mc->depth == INT_MIN`). Previously returned a MOVIECLIP value pointing to the dead MC, which coerced to `""` — test expected `"null"` (Flash semantics: `typeof(mcRef) == 'undefined'` but `mcRef.valueOf() == null` after removeMovieClip). Scoped to the `this_obj == NULL && g_event_this_mc != NULL` path for method-style MC receivers. Also improves `misc-ming/new_child_in_unload_test` by 3 lines (same `dyn1Ref.valueof() == null` pattern, though that test still fails on a separate cascading-unload issue). No regressions on a 5-test AVM1 unload battery, 14-test valueOf-exercising battery, or the 13 misc-ming tests passing at CI snapshot. See `incomplete/MISC_MING_SWFC_PLAN.md` "dead MC valueOf returns null".

### Latest fixes (2026-04-23, in CI at 205a9a77)

- **shumway fuzz/81004241… and fuzz/2f4f46bf… → PASS (+2).** Two-part
  fix for FSCommand:quit in SWFs that use the literal-URL form of
  GetURL:
  1. `actionGetURL(url, target)` in
     `SWFModernRuntime/src/actionmodern/action.c` (the literal-URL
     entry point, as opposed to `actionGetURL2` which reads from the
     stack) did not handle the `FSCommand:` prefix at all. It now
     does, mirroring the handling already present in `actionGetURL2`:
     `FSCommand:quit` sets `quit_swf = 1` and in headless builds
     `FSCommand:capture` calls `headless_on_fscommand_capture()`.
  2. The main tick loop in `SWFModernRuntime/src/libswf/swf_core.c`
     only checked `quit_swf` in the past-last-frame branch. SWFs
     that FSCommand:quit from a non-last frame but still rely on the
     recompiler-emitted end-of-movie loopback (`manual_next_frame=1,
     next_frame=0`) kept looping forever. New top-of-tick check
     mirrors the past-last-frame conditions (no pending events,
     enter-frame handlers, timers, sounds, netstreams, or clip
     enter-frame handlers) — **but intentionally does NOT require
     `!hasPlayingSprites()`**, because the fuzz SWFs have sprites
     with no AS `stop()` that would otherwise keep the player alive
     indefinitely. Timers/sounds/etc. still drain naturally after
     quit (verified via `set_interval` which relies on that
     drain). No regressions on a 24-test AVM1 battery
     (unload/unloadmovie/unload_clip_event/unload_nested_child/
     goto_frame/goto_label/goto_rewind1/2/3/on_construct/
     register_class_return_value/register_and_init_order/
     clip_events/button_children/init_object_order/
     swf5_to_6_cross_call/swf6_to_5_cross_call/swf5_no_closure/
     attach_movie/movieclip_init_object/native_objects_swf7/8/
     set_interval/textsnapshot_available_text) or on the 6-test
     Shumway avm1 duplicateMovieClip + haxe/flocons1 + moviecliploader
     battery.

- **DefineEditTextVariableNameTest2 (misc-ming) → PASS (+1).** Extended
  primitive auto-boxing in `actionGetMember` (action.c) to STRING values.
  The final failing line `typeof(dtext4.text.toString) == 'function'`
  resolved: the STRING branch of `actionGetMember` previously handled only
  `.length` and returned undefined for every other member. Now, when the
  built-in `String` constructor is still in place (i.e.
  `tryAutoBoxPrimitive` returned `_autobox_result == -1` — same gate the
  existing F32/F64/BOOLEAN fallback uses), string property access falls
  back to `getPrimitiveWrapperProto(ACTION_STACK_VALUE_STRING)` and reads
  via `getPropertyWithPrototype` on String.prototype. `__proto__` on a
  STRING primitive returns String.prototype. No regressions on a 16-test
  AVM1 string battery (string_methods*, string_paths_*, string_coercion,
  object_string_coerce_swf5/6, path_string), a 17-test AVM1
  object/prototype battery, or a 12-test Gnash String-v5..v8,
  Number-v5..v8, Boolean-v5..v8 battery (all previously-pass/RM tests
  unchanged).

- **DefineEditTextVariableNameTest2 (misc-ming) — partial (+7 lines,
  28/36 → 35/36).** `ng_syncVarToTextFields` was skipping OBJECT / ARRAY /
  FUNCTION values with a "no side effects" comment, so
  `edit_text_var = new Object()` never propagated to bound textfields — the
  textfield kept its previous string value instead of coercing the object to
  `'[object Object]'` (or the user's `Object.prototype.toString` result when
  the test overrides it). Ruffle's `notify_property_change`
  (`core/src/avm1/object/stage_object.rs:87`) calls
  `value.coerce_to_string(activation)` on every value type, so the side-effect
  concern is actually part of the observable Flash/Ruffle behavior. Fix:
  route all non-STRING / non-UNDEFINED values (including OBJECT/ARRAY/FUNCTION)
  through `varToStringBuf`, which already invokes `objectCallToString` for
  OBJECT. No regressions on a 12-test AVM1 edittext/textfield battery or a
  5-test misc-ming battery. The one remaining failing line
  (`typeof(dtext4.text.toString) == 'function'`) is a separate, pre-existing
  limitation (STRING-primitive-to-String.prototype auto-boxing is only
  implemented for `.length`).

- **action_execution_order_test8-v5/v6 (misc-ming) → PASS (+2).**
  Tightened the Phase 3 filter in `process_sprite_needs_init` (libswf/
  tag.c) from `placed_at_frame >= g_sprite_init_target_frame` to
  `placed_at_frame == g_sprite_init_target_frame`. The `>=` semantics
  was wrong under nested gotos: `frame 2 DoAction → gotoAndPlay(4)`
  (inside the outer goto's Phase 2 for target=2) triggers
  `ng_executeGotoCatchUp` for the inner goto, which immediately runs
  frames 3–4 and places mc1 at frame 4. With `>=`, the OUTER Phase 3
  (filter `>= 2`) then fires mc1 before the inner goto's Phase 2 runs
  — producing mc1's `_root.gotoAndStop(6)` trace *before* the expected
  "root frame 4" / `typeof(_root.x)=='undefined'` lines. `==` restricts
  each goto's Phase 3 to sprites placed at exactly its own target
  frame, so mc1 fires during the inner goto's Phase 3 (target=4)
  as Ruffle expects. In a non-nested single goto, catch-up only places
  sprites up to target_frame, so `==` and `>=` are equivalent.
  No regressions on a 54-test AVM1 execution-order/rewind/clip-event
  battery, the Gnash action_order cluster (7 pre-existing failures
  unchanged — line counts identical), or the Shumway duplicateMovieClip
  suite.

- **static_vs_dynamic1 (misc-ming) → PASS (+1).** `actionRewindCleanup`
  now decides whether a display-list-less clone survives a backward
  goto by looking up the clone's registered SWF depth in
  `g_clone_depth_table` (via new `ng_clone_get_swf_depth` helper
  exported from `libswf/tag_stubs.c`), not by testing `ch->depth >=
  16384`. The table is populated at `clone_depth_register` time with
  the raw SWF depth produced by bytecode — so both Ming-biased
  (`Push(N) Push(16384) Add`) and Shumway-already-biased (`Push(N+16384)`)
  callers end up with the same canonical value, avoiding the heuristic
  ambiguity that the existing `ng_cloneSprite` bias-strip code inflicts
  on `ch->depth`. To keep the table in sync when a clone is moved
  post-create, `swapDepths` (numeric, MC-ref, and path-string paths in
  `action.c`) calls new `ng_clone_update_swf_depth` after updating
  `mc->depth`. Fixes the final `typeof(dup2)` check in
  static_vs_dynamic1 (dup2 at SWF 16386 now survives rewind, matching
  Ruffle's `survives_rewind` for the dynamic range). No regressions on
  the Shumway duplicateMovieClip suite (which relies on 16379 < 16384
  → removed) or a 45-test AVM1 rewind/unload/placement/clone battery.
  See `incomplete/MISC_MING_SWFC_PLAN.md` "survives_rewind via
  clone_depth_table".

- **stackscope (misc-swfc) → PASS (+1).** Flash clears the AVM1 action
  stack at each frame boundary; within a single frame, multiple DoAction
  blocks share the stack so later blocks see leftover pushes from earlier
  blocks (this is how `_root.var1 = val1` propagates from `script_0`'s
  trailing `Push "_root.var1", Push "val1"` into `script_1`'s `SetVariable`
  — and `var2` flows cross-sprite from `script_1` to `mc1`'s `script_2`
  the same way). Between frames, though, the stack must reset — otherwise
  `_root.var3 / val3` leaks into frame 1's `script_3` and sets
  `_root.var3 = "val3"`, whereas the test expects it to stay undefined.
  Our runtime never reset the stack, so we were persisting across frames
  indefinitely; Ruffle goes the other direction and clears per DoAction
  (stricter — `output.ruffle.txt` shows var1/var2 failing as `""`). Fix:
  add `app_context->sp = INITIAL_SP; app_context->oldSP = 0;` at the top
  of each tick in `SWFModernRuntime/src/libswf/swf_core.c` (NO_GRAPHICS),
  `swf_headless.c` (HEADLESS), and `swf.c` (GRAPHICS). No regressions on
  a 48-test AVM1 battery, a 9-test misc-ming battery of recently-fixed
  placement/rewind tests, or on misc-mtasc/misc-swfmill.

- **TextFieldHTML-v6/v7/v8 (actionscript.all) → PASS (+3).** Flash's HTML
  parser (and Ruffle's, which uses `quick_xml::Reader`) rejects unquoted
  attribute values per XML spec. When a start tag contains `name=value`
  without quotes around the value, parsing aborts and the resulting `text`
  is empty. Our `tf_parse_html` was too lenient: `tf_get_attr` happily
  read unquoted values up to the next whitespace or `>`, so
  `<font color=#00FF00>green2</font>` was treated as a valid font tag and
  left "green2" in `tf.text`. Fix (two parts in
  `SWFModernRuntime/src/actionmodern/action.c`):
  (1) New helper `tf_tag_has_malformed_attr(tag_content, tag_len)` scans
  for any `attr=X` where X is not a quote char, returning 1 if malformed.
  (2) In `tf_parse_html`, after a start tag is extracted, call the helper
  on the tag content; if malformed, clear the run table (`run_count=0`,
  `text_len=0`) and return, matching Ruffle's abort-on-parse-error
  behavior in `text_format.rs`. No regressions on an 19-test AVM1
  edittext/textfield/htmlText battery (`edittext_html_align_swf7/8`,
  `edittext_html_color`, `edittext_html_condensewhite_swf7/8`,
  `edittext_html_entity`, `edittext_html_roundtrip`,
  `edittext_html_swf6/7/8`, `edittext_stylesheet`, `clone_sprite_edittext`,
  `clone_sprite_edittext_dynamic`, `text_format`,
  `text_format_rounding_swf7/8`, `text_format_font_max_length`,
  `text_format_display`, `text_format_get_text_extent_undefined_width`).

### Latest fixes (2026-04-22, in CI at 205a9a77)
- **instanceNameTest (misc-ming) → PASS (+1).** SWF's PlaceObject2
  `HasName` flag distinguishes "name present but empty" (`setName("")`)
  from "no name at all", and Flash preserves that distinction (empty
  name → `_target == "/"`; no name → auto-assigned `instance2`). The
  recompiler's `tagSetInstanceName` emission sites used
  `!instance_name_str.empty()` to decide whether to write the call,
  collapsing the two cases and causing every explicit-empty-name MC
  to hit the runtime's auto-naming path — shifting every subsequent
  auto-index by one (hence our `/instance2` + `/instance3` diff vs.
  expected `/` + `/instance2`). Fix: seven sites in `swf.cpp` (four in
  `tag_main`, three in `sprite_definitions`) now gate on `has_name`
  instead of string emptiness. The runtime already handles the empty
  string via `g_pending_instance_name` (non-NULL pointer). No
  regressions on an 18-test AVM1 placement/name battery, the 8-test
  misc-ming cluster fixed earlier this session, or the Shumway
  duplicateMovieClip suite.

- **sound (misc-swfc) — partial +1 line.** `builtin_sound_attachSound`
  now sets `__loaded__ = true`, mirroring Ruffle's `attach_sound`
  (`core/src/avm1/globals/sound.rs:395-404`, which calls
  `sound.load_sound(...)` + `sound.set_position(0)`). Without it,
  `snd.position` returned `undefined` between `attachSound()` and
  `start()` — the getter required `__loaded__` to enter the computed
  path. With the flag set, it falls through to
  `soundGetElapsedForObject` → 0 for an inactive sound. Test still
  fails overall (separate timing-based frame-loop issue reaches
  frame 8 too early). No regressions on the 10-test AVM1 sound
  suite.

- **loop/loop_test5 (misc-ming) → PASS (+1).** After the survives-rewind
  landing took this test from 13/24 to 21/24, the one remaining diff was
  `typeof(movieClip1) == 'movieclip'` returning undefined after the rewind
  re-created movieClip1 at depth 3 (different ratio vs. the surviving
  movieClip4 at depth 4 forced a full-replace path for depth 3). The root
  cause was in `actionRewindCleanup` in
  `SWFModernRuntime/src/actionmodern/action.c`: for each child MC not
  present in the current display list, the code unconditionally wrote
  `root_movieclip.dynamic_props[name] = UNDEFINED`. That's correct for
  CloneSprite / duplicateMovieClip clones (which live in dynamic_props),
  but wrong for timeline-placed MCs — the leftover UNDEFINED entry later
  shadows the display-list fallback inside `actionGetVariable` (the plain
  own-prop hit in the dynamic_props check returns before
  `check_special_vars` scans `ng_findDisplayEntryByName`). Fix: narrow the
  clear so it only fires when `dynamic_props[name]` currently points to
  THIS MC (a MOVIECLIP value whose target equals `ch`), distinguishing
  genuine clone registrations from incidental entries. The var_map
  clearing was also narrowed the same way for symmetry. No regressions
  on a 32-test AVM1 rewind/placement/attachMovie/register-class/
  coerce-to-object battery, a 7-test misc-ming cluster (test11,
  place_and_remove_object, static_vs_dynamic2, loop_test9, loop_test5,
  shape_test, attachMovieTest), or the Shumway duplicateMovieClip suite.

- **displaylist_depths_test11 (misc-ming) → PASS (+1).** Backward-goto MovieClip
  survives-rewind implementation. During backward goto catch-up, initialized
  sprites whose `char_id` + `ratio` match the target frame's placement are
  preserved (instance_name, constructor state) instead of being cleared and
  re-created. Mirrors Ruffle `MovieClip::survives_rewind` and the
  `apply_place_object` comment that "name... can not be modified by subsequent
  PlaceObject tags". Four-part fix across `SWFModernRuntime/src/libswf/tag.c`
  and `libswf/swf_core.c`/`swf_headless.c`:
  (1) `ng_display_clear_after` now preserves entries with
  `sprite_display_list != NULL` (initialized MovieClips).
  (2) `tagPlaceObject2`/`tagPlaceObject2Ratio` backward-catch-up branch
  checks `(char_id == existing) && (ratio == existing)`. If matches → modify
  path (preserves `instance_name`, clears `g_pending_instance_name` BEFORE
  `ng_on_place_object2` so the preserved name survives). If not matches AND
  existing `placed_at_frame > catch_up_target` (truly stale from pre-rewind
  state) → clear and fall through to full placement. If not matches but within
  `[0, target]` (earlier catch-up replay of a later frame's intermediate
  placement) → skip (preserves previous behavior).
  (3) `tagSetInstanceName` during `catch_up_backward` with
  `placed_at_frame > current_frame` pends the name but doesn't rename
  in-place. Ruffle doesn't update name on surviving children. Also gated on
  `g_tag_skip_mode` so the deferred target-frame replay (`funcs[target]`
  called with `g_tag_skip_mode=1`) doesn't re-rename preserved entries.
  (4) Post-catch-up cleanup `ng_display_cleanup_unplaced_after` clears
  sprites whose depth wasn't re-placed during catch-up (effectively failed
  survives_rewind).
  No regressions on a 44-test AVM1 battery (goto_rewind1-3,
  execution_order1-3, goto_execution_order, goto_execution_order2,
  unload/unload_nested_child/unloadmovie/mcl_unloadclip, rewind_depth,
  goto_both_ways1/2, depth_replacement_audio_unloading,
  access_unnamed_shape, conflicting_instance_names, default_names,
  movieclip_depth_methods/get_instance_at_depth/name_from_timeline,
  named_shapes, place_and_lookup, bad_placeobject_clipaction, clip_events,
  register_and_init_order, on_construct, movieclip_state_values,
  movieclip_library_state_values, register_class_return_value,
  attach_movie, attach_movie_stop, empty_movieclip_can_attach_movies,
  init_object_invalid, init_object_order, movieclip_init_object,
  button_children, array_enumerate, enumerate, swf5_to_6_cross_call,
  swf6_to_5_cross_call, textsnapshot_available_text) and Shumway
  duplicateMovieClip/dontremove/duplicateMovieClip/samedepth/name-coercion.

### Latest fixes (2026-04-22, in CI at 205a9a77)
- **static_vs_dynamic2 (misc-ming) → PASS (+1).** Two-part fix for
  `RemoveObject2` targeting a depth whose display-list slot is empty
  because a swap moved the original occupant to a different SWF depth.
  After `duplicateMovieClip('mc1', 'dup', 1)` + `mc1.swapDepths(dup)`,
  mc1 moves to SWF 16385 and dup's AS depth becomes -16382 (SWF 2), but
  dup has no DL entry (ng_cloneSprite's `target_swf_depth >=
  INITIAL_DISPLAYLIST_CAPACITY` gate skipped DL placement). A subsequent
  `RemoveObject2` at SWF depth 2 found `display_list[2].char_id == 0`
  and returned silently, leaving `_root.dup` resolving to the stale
  clone. Fix: (1) `tagRemoveObject2` (tag.c) now falls through to a
  new `actionInvalidateMCAtASDepth` helper on empty DL slots, scanning
  `child_mc_cache` for a root-level MC whose current `depth` matches
  the AS depth of the removed tag and marking it `avm1_removed`.
  (2) `actionInvalidateMCAtASDepth` also clears the global `var_map`
  entry for the MC's name (via `setVariableByName(name, undefined)`)
  — CloneSprite registers the clone there, and `_root.dup` resolves
  through var_map bypassing the normal display-list / child_mc_cache
  path. Without step 2 `typeof(dup)` returned `'movieclip'` even after
  the MC was invalidated. No regressions on a 47-test AVM1 battery
  (rewind/unload/placement/clone/attachMovie/construct).
- **loop/loop_test9 (misc-ming) → PASS (+1).** Added a dynamic-range gate
  to `ng_display_clear_after` in `SWFModernRuntime/src/libswf/tag.c`:
  the loop now `break`s at `i >= 16384` so display entries at SWF depth
  >= `AVM_DEPTH_BIAS` survive backward jumps. This matches Ruffle's
  `survives_rewind` rule (`core/src/display_object/movie_clip.rs:1824`):
  for AVM1, `old_object.depth() < AVM_DEPTH_BIAS` is the precondition
  for considering an object for removal during rewind. Previously we
  cleared every entry placed after the target frame regardless of
  depth, which killed `movieClip2` (placed at SWF depth 30000 = AS
  13616) on `gotoAndStop(1)` even though it lives in the dynamic range.
  `static_vs_dynamic1` also partially improves: `typeof(mc1)` after
  swap-to-dynamic loopback now matches; the remaining `typeof(dup2)`
  diff is blocked on the punted CloneSprite depth-bias always-strip
  (preserving duplicateMovieClip clones would regress
  `from_shumway/avm1/duplicateMovieClip/dontremove`). No regressions
  on a 45-test AVM1 rewind/unload/placement battery (see MISC_MING_SWFC_PLAN).
- **place_and_remove_object_test (misc-ming) → PASS (+1).**
  `tagSetInstanceName` in `SWFModernRuntime/src/libswf/tag.c` now also sets
  `g_pending_instance_name` in the path where the display entry already
  exists (`display_list[depth].char_id != 0`). Without this, a subsequent
  `tagPlaceObject2` that replaces the old character with a different
  `char_id` walked the full-placement path and wiped `instance_name` back
  to NULL (because `g_pending_instance_name` was NULL — the existing
  branch set the name directly on the display entry but didn't stage it
  as pending). The test exposed it via the natural end-of-movie loopback:
  frame 0's `tagSetInstanceName(3, "sh1"); tagPlaceObject2(3, sh1, …)`
  ran against a depth still holding frame 2's sh2 (char_id=5), so the
  replace path lost "sh1" and `_root.sh1` resolved to undefined.
  Verified no regressions on AVM1 placement / MC-lifecycle tests
  (`access_unnamed_shape`, `conflicting_instance_names`, `default_names`,
  `depth_replacement_audio_unloading`, `movieclip_depth_methods`,
  `movieclip_get_instance_at_depth`, `movieclip_name_from_timeline`,
  `named_shapes`, `place_and_lookup`, `bad_placeobject_clipaction`,
  `clip_events`, `register_and_init_order`, `goto_rewind3`,
  `execution_order3`, `goto_execution_order2`,
  `movieclip_in_removed_button`, `unload`, `on_construct`,
  `movieclip_state_values`).
- **attachMovieTest (misc-ming) → PASS (+1).** `attachMovie` now skips the
  init-object property loop when the attached symbol is a Button
  (`attached->is_button_mc`). Flash behavior: the init object is not used
  for Buttons — test comment: "init object is not used for Buttons", and
  `butatt.f` is expected to be `undefined` even though `o.f = 56` was the
  init object's property. Both the CallFunction (`attachMovie` global)
  and CallMethod (`mc.attachMovie`) paths in
  `SWFModernRuntime/src/actionmodern/action.c` updated. The existing
  `!attached->is_button_mc` gate for registerClass constructor firing
  already matched the Flash semantics here — this just extends the same
  rule to the init-object application. No regressions on AVM1
  `attach_movie`, `attach_movie_stop`, `empty_movieclip_can_attach_movies`,
  `init_object_invalid`, `init_object_order`, `movieclip_init_object`,
  `button_children`, or `clip_events`.
- **shape_test (misc-ming) → PASS (+1).** Three-part fix in
  `SWFModernRuntime/src/actionmodern/action.c` for Flash's shape-as-MC quirk:
  (1) `getInstanceAtDepth` no longer returns the parent MC for
  `_found_type == 1` (shape / morph / static text) placements — both the
  global and method-form handlers now fall through to undefined. (2) The
  same handlers skip cached MCs that `mc_is_nonscriptable_shape` flags, so
  shapes which happen to have their own cache entry also return undefined.
  (3) `actionGetVariable` (via the `!ng_isScriptableAtDepth` branch) and
  `resolveSlashPathToMC` now set `g_shape_alias_resolution = 1` whenever a
  shape's instance name resolves to its parent MC. The `getDepth` method
  handler in `actionCallMethod` consumes the flag and pushes undefined on a
  shape-aliased receiver — matching Flash's `typeof(sh.getDepth()) ==
  'undefined'`. Property access like `sh.var = 10` / `sh._x` still lands
  on the parent MC. No regressions on AVM1 `movieclip_depth_methods`,
  `movieclip_state_values`, `movieclip_library_state_values`,
  `swf5_to_6_cross_call`, `swf6_to_5_cross_call`, `global_is_bare`,
  `enumerate`, `array_enumerate`, `register_class_return_value`, nor on
  Gnash `place_and_remove_object_test`, `DepthLimitsTest`, `attachMovieTest`,
  `reverse_execute_PlaceObject2_test2`, `displaylist_depths_test`,
  `case-v5..v8`, `MovieClip-v5`.

### Latest fixes (2026-04-21, confirmed in CI at 7155a774)

### Latest fixes (2026-04-21, confirmed in CI at 7155a774)
- **with-v6/v7/v8 → `ruffle_matched` (+3 effective).** Added
  `resolveObjectPathToMC` in `action.c` (after `resolveFlashPathToMC`) to
  walk dotted/colon path segments via property lookup when they don't
  resolve as timeline children. Mirrors Ruffle's
  `Activation::resolve_target_path` (`core/src/avm1/activation.rs:2513`):
  each segment tries display-list `child_by_name` first, then falls back
  to `object.get(name)` which walks `__proto__`. Final value must be a
  `MOVIECLIP`. `actionSetTarget` now calls this helper as a fallback when
  the path contains `.`, `:`, or `/`. Paths like `o.t`, `o:t`,
  `o2.o.t`, and `o2.inh.t` (inherited via `__proto__`) now resolve to
  the underlying MC, eliminating the ~14 stray `Target not found`/
  `FAILED _target==` lines per test. See `complete/SETTARGET_OBJECT_PATH_PLAN.md`.

### Plan rescoping (2026-04-21, no test deltas)
- **`WITH_AUTOBOXING_PLAN.md` shelved** (moved incomplete/ → blocked/, then 2026-04-27 to superseded/).
  with-v5 already `ruffle_matched`; v6/v7/v8 failures are *not*
  primitive-auto-boxing. The diffs targeted by the plan's
  `Number.prototype.checkpoint`/`String.prototype.checkpoint` assertions
  already pass in our output via the Object.prototype inheritance path.
  The real remaining blockers for with-v6/v7/v8 are three unrelated
  features; see new plans below.
- **Plans:**
  - `complete/SETTARGET_OBJECT_PATH_PLAN.md` — Done. Extended
    `actionSetTarget` to resolve dotted/colon object paths via property
    lookup (not just MovieClip parent/child). ~14 diff lines each on
    with-v6/v7/v8 (6 stray `Target not found` traces + 8 `_target` FAILs).
  - `complete/ASSETPROPFLAGS_WITH_READONLY_PLAN.md` — Done earlier
    (73983b0e). (a) handle MOVIECLIP arg in
    `actionASSetPropFlags_func2`; (b) honour `PROPERTY_FLAG_WRITABLE`
    in WITH-scope assignment.

### Latest fixes (2026-04-17, in CI at 205a9a77)
- **ASnative-v5/v6/v7/v8 → ruffle_matched (+4).** Three-part fix in `SWFModernRuntime/src/actionmodern/`:
  (1) ASnative class 103 (Date) dispatcher in `date.c` wired to existing Date prototype methods via Ruffle's index scheme (0-20 local, 128-143 UTC, 256 constructor, 257 Date.UTC); index 256 returns a bare ASFunction with `prototype_obj = NULL` so `new f()` produces a plain object (matches Ruffle `FunctionObject::table_native`).
  (2) ASnative class 200 (Math) remap table — Flash's order (0=abs, 1=min, 2=max, 3=sin, 4=cos, 5=atan2, ...) differs from internal `g_math_funcs[]` registration order.
  (3) ASnative class 100 indexes 2 (parseInt) and 3 (parseFloat) — standalone advanced_func implementations; previous NULL placeholders only worked via the name-dispatch path. See `complete/ASNATIVE_CLASSES_PLAN.md`.

### Latest fixes (2026-04-15/16, now in CI)
- **Primitive auto-boxing in GetMember** (cffa1dd8) — Primitive number (F32/F64) and
  boolean property access now looks up properties on Number.prototype /
  Boolean.prototype via `getPrimitiveWrapperProto()`. Handles Flash's
  auto-boxing: `typeof(1 .toString) == 'function'` and
  `(1).__proto__ == Number.prototype`. Number-v7/v8 each -5 diffs,
  Number-v5/v6 each -7 diffs. ~2 lines improved across many other tests.
- **convertFloat FUNCTION valueOf dispatch** (cffa1dd8) — The FUNCTION case in
  convertFloat was missing an obj handler, so custom valueOf on function
  objects was never invoked during toNumber. Number-v7/v8 +2 lines each.
- **convertFloat SWF6+ NaN threshold** (463b920c) — Object-to-number fallback changed
  from `SWF<7→0.0` to `SWF<6→0.0` (Flash returns NaN starting at SWF6).
  **Color-v6 → PASS** (+1 test). Number-v6: 8→4 failures.
- **`coerce_to_object_monkeypatch` avm1 regression fix** (998e879a, post-CI) — narrow fix to avoid regressing the avm1 coerce_to_object_monkeypatch test from the primitive auto-boxing work.

### Latest fixes (2026-04-15, in CI at 205a9a77)
- **TextFormat-v5/v6 → PASS (+2).** Three fixes to TextFormat in
  `SWFModernRuntime/src/actionmodern/action.c`: (1) `tfCoerceAlign` is now
  case-insensitive and normalizes to canonical lowercase (`"Left"` → `"left"`,
  `"cEnter"` → `"center"`, etc.), matching Ruffle `text_format.rs` set_align +
  align getter. (2) `getTextExtent` is now installed as an instance-own
  property by the TextFormat constructor, not on `TextFormat.prototype` —
  Flash's observable behavior is `!TextFormat.prototype.hasOwnProperty('getTextExtent')`
  + `tfObj.hasOwnProperty('getTextExtent')`. (3) `tfCoerceBoolean` now uses
  version-gated string coercion matching Ruffle `Value::as_bool`: SWF7+ →
  non-empty string is true, SWF5/6 → `varToDoubleSWF` then non-NaN non-zero
  check. No regressions on avm1 `text_format`, `text_format_rounding_swf7/8`,
  `text_format_font_max_length`, `text_format_display`,
  `text_format_get_text_extent_undefined_width`, `textfield_*`, Color/ColorTransform,
  flash-v5/v6/v7. TextFormat-v7 still fails — residual diffs are
  getTextExtent metric precision, unrelated to these fixes.
- **`flash` package unhide via ASSetPropFlags (SWF6/7)** — `flash` is now always
  registered on `global_object` with `flash_flags=0x1480` (hidden under SWF5/6/7
  version masks, visible SWF8+). `initFlashPackage` and `g_flash_object`
  creation are no longer gated on `SWF>=8`. Gnash's Transform-v6/v7 tests call
  `ASSetPropFlags(_global, "flash", 0, 5248)` to clear the visibility bits,
  after which `flash.geom.Transform` resolves to a function. **Impact:**
  Transform-v6/v7 → **PASS** (+2 tests). Matrix-v7 → **ruffle_matched**
  (+1 effective pass; previously output_mismatch). No regressions on
  Point-v5..v8, Rectangle-v5..v8, Matrix-v5/v8, ColorTransform-v5..v8,
  Inheritance-v5..v8, Try-v6/v7/v8, case-v5/v7/v8, delete-v5..v8,
  System-v5..v8, flash-v5/v6/v7, nor on avm1 global_is_bare, enumerate,
  mutable_this, this_scoping, register_class_return_value, string_coercion,
  array_enumerate, textsnapshot_available_text.

## Quick Summary

| Sub-suite | Tests | Pass | RM | Effective | Effective Rate | Ignored |
|-----------|-------|------|----|-----------| ---------------|---------|
| **actionscript.all** | 190 | 110 | 49 | 159 | **83.7%** | 0 (ignore list empty; see below) |
| **misc-mtasc.all** | 9 | 7 | 1 | 8 | **88.9%** | 0 |
| **misc-swfmill.all** | 18 | 15 | 1 | 16 | **88.9%** | 0 |
| **misc-ming.all** | 102 | 19 | 11 | 30 | 29.4% | 0 |
| **misc-swfc.all** | 16 | 3 | 3 | 6 | 37.5% | 0 |
| **Total** | 335 | 154 | 65 | 219 | **65.4%** | 0 |

"RM" = `ruffle_matched`: our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs (the test has `known_failure = true` + `output.ruffle.txt` in the Ruffle source repo, so matching Ruffle is as good as passing).

**Notable growth since 2026-04-18** (OVERVIEW's previous snapshot):
- actionscript.all: 106 → 110 pass (+4), 27 → 49 ruffle_matched (+22). Effective +26 → 159/190 (**83.7%**).
  - +22 RM from: String-vN ruffle-match bundles (`d05bbd56`, `f70ecdb0`, `41f62c81`), with-v6/v7/v8 (`73983b0e`, `7155a774`), remaining auto-promotions as plan work landed.
- misc-swfmill.all: `dict_event` resolved (+1 effective → 16/18). Remaining 2: `jump_to_prev_block`, `tags_after_last_showframe`.
- misc-ming.all: +2 effective (28 → 30).
- misc-swfc.all: +1 effective (5 → 6).
- actionscript.all `ignored_tests.txt` is still empty — previously-ignored Math/ops/Inheritance tests are auto-promoted to ruffle_matched by `verify_output.py` subset-match. See `complete/RUFFLE_KNOWN_FAILURE_HANDLING_PLAN.md`.

### Latest fixes (2026-04-13, confirmed in CI at 83d3748a)
- **Inheritance-v5 SWF5 version gates** — Four gates applied in `action.c`: (1) `actionExtends` skips `__constructor__` in SWF5 (gnash comment: "SWF5 or below don't set __constructor__"); (2) `actionGetVariable` "super" fallback gated on SWF ≥ 6 so SWF5 function bodies see super as undefined; (3) `actionCallFunction("super")` handler gated on SWF ≥ 6 so `super()` in SWF5 becomes an undefined-variable no-op; (4) `Function.prototype.apply`/`.call` marked `flash_flags=0x0080` (hidden in SWF5 per Gnash test source comment "Function.apply was introduced in SWF6"). **Impact:** Inheritance-v5 line-match 100/114 → 114/114 (all expected lines match); only residual diff is the 1 extra egg/chicken line. Added to `ignored_tests.txt` → passing via filtered results. See `complete/INHERITANCE_SEGFAULT_PLAN.md` Fix 3.

### Latest fixes (2026-04-13, session 2 — in CI at 205a9a77)
- **Inheritance-v6/v7/v8 accepted as Ruffle-matching** — Investigation into the remaining v6/v7/v8 super-chain diffs revealed that all 4 Inheritance tests carry `known_failure = true` in upstream Ruffle with `output.ruffle.txt` files documenting their divergent output. Verified locally that our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file for every version (v5: 1⊆17, v6: 9⊆16, v7: 5⊆10, v8: 5⊆10). The super-chain lines (`"undefinedFFC"` v7/v8, `"A.B.B"`/`"FAAC"`/`"FFFC"` v6) are Flash-only dynamic base class semantics that Ruffle does not replicate. Added v6/v7/v8 to `ignored_tests.txt` alongside v5, documented in `ACCEPTED_DIFFS.md` Category 1b. `INHERITANCE_SEGFAULT_PLAN.md` moved to `complete/`. **Impact:** filtered pass rate 95/184 → 95/181 = 52.5%. **Broader finding:** 84 of our 95 Gnash failures are tests Ruffle itself cannot pass; 11 are tests Ruffle passes. See `incomplete/RUFFLE_KNOWN_FAILURE_HANDLING_PLAN.md`.

### Latest fixes (2026-04-12, in CI at 205a9a77)
- **TextSnapshot method stubs (arg-count gated)** — Added dedicated builtins for `hitTestTextNearPos` (2-3 args → number, else undefined), `getSelected` (2 args → boolean, else undefined), `getSelectedText` (0-1 args → string, else undefined). `getCount` gates on arg_count==0 and on `native_type == NATIVE_TEXTSNAPSHOT` (no native → undefined). **Impact:** TextSnapshot-v6/v7/v8 improved from 128/167 to ~156/167 lines each. Note: a prior pass also made `getText` and `getCount` fall through to empty string / 0 for empty native TextSnapshots, which matched Gnash's `getText(...)=="string"` expectations but broke the avm1 suite's `textsnapshot_available_text` test — that fall-through was reverted in d7xxxx to match Ruffle's Value::Undefined semantics.

### Latest fixes (2026-04-10, in CI at 205a9a77)
- **Error constructor raw message storage** — `new Error(new Object())` now stores the Object reference as `.message` instead of coercing to string. `Error.prototype.toString` returns the raw message value (any type). **+4 tests: Error-v5, Error-v6, Error-v7, Error-v8 → PASS.**
- **delete-v8 now PASS** — confirmed locally, previous fixes (dot-path resolution, non-existent returns false, global_object check) pushed it over.
- **parseInt object toString coercion** — `parseInt(obj)` now calls `toString()` on object/array/function arguments instead of returning NaN. **+2 lines per toString_valueOf test** (v6/v7/v8).

### Latest fixes (2026-04-09, in CI at 205a9a77)
- **Delete dot-path resolution** — `actionDelete2("o.b")` and `actionDelete` with dot-path property names now resolve the path: split on last dot, look up container, delete final property. The `actionDelete` fallback is SWF5/6 only (SWF7+ uses strict property names). **+14 lines across delete-v5/v6/v7/v8** (delete-v5: 43→47/60, delete-v6: 41→45/60, delete-v7: 46→49/60, delete-v8: 47→50/60).
- **Color-v6 now PASS** — confirmed locally, was already 161/165 in CI; recent fixes pushed it over.
- **NetStream connected-construction property installation** — `new NetStream(nc)` where nc is a connected NetConnection now installs `currentFps` as an own property on `NetStream.prototype`. In Flash, the NetStream constructor lazily registers native data properties when first constructed with a connected NC. Detected via `__proto__ == NetConnection.prototype` + `isConnected == true` check. **+3 tests: NetStream-v6, NetStream-v7, NetStream-v8 → PASS.**

### Latest fixes (2026-04-08, batch 2 — confirmed by CI at 77/190)
- **Number constructor proper coercion** — `new Number(obj)` now uses `varToDoubleSWF` instead of defaulting OBJECT/BOOLEAN/etc to 0. Fixes `new Number(objWithValueOf)` returning wrong value. `varToDoubleSWF` OBJECT path now handles valueOf returning STRING/BOOLEAN/etc. Number-v5/v6/v7/v8 each +12-13 lines.
- **Number wrapper toString radix** — `new Number(10).toString(2)` now returns "1010". Wrapper toString supports radix 2-36.
- **Delete non-existent returns false** — `delete nonExistentVar` returns false (was true). Added global_object property check for `_global.name` deletion. delete-v5/v7/v8 +2 each.
- **actionEnumerate scope chain** — Old Enumerate opcode (SWF5 for-in) now checks scope chain for variable lookup. Fixes `enumerateObj(o)` inside functions. enumerate-v6/v7/v8 each +13 lines.
- **Total estimated impact**: ~120 lines improved across ~30 tests.

### Latest fixes (2026-04-08, batch 1)
- **Flash-compatible number formatting** — Replaced all `%.15g` with `flash_format_double()`: no leading zeros in exponents (e-7 not e-07), decimal format for exponent -5 (Flash uses -5 threshold, C uses -4). Number-v8: 192→204/237 (+12 lines), all Number tests improved ~10 lines each.
- **NaN/Infinity on _global** — Registered NaN and Infinity as F64 properties on global_object, fixing `typeof(_global.NaN) == 'number'` checks.
- **Number constructor own properties** — constructor, __proto__ (→Function.prototype), prototype registered on Number constructor, fixing `Number.hasOwnProperty(...)` checks.
- **Delete operator partial fixes** — `delete func.prototype` returns false (non-deletable), `delete undefined.prop` returns false. delete-v7 +2 lines, delete-v8 +2 lines.

### Latest fixes (2026-04-05)
- **SWF5 version hiding via flash_flags** — SWF6+ classes (LocalConnection, NetConnection, NetStream, Video, Camera, etc.) and AsBroadcaster methods (addListener, removeListener, broadcastMessage, _listeners) now hidden in SWF5 via `flash_flags=0x0080`. Uses the version mask system (SWF5 mask 0x7480 hides bit 0x0080). **+5 tests: Key-v5, AsBroadcaster-v5, LocalConnection-v5, NetConnection-v5, Video-v5.**
- **MovieClip.prototype.transform** — Registered as own property (undefined) on MovieClip.prototype so `hasOwnProperty("transform")` returns true. **+3 tests: flash-v5, flash-v6, flash-v7.**

### Latest fixes (2026-04-04)
- **Dual Array constructor prototype unification** — `g_ctors[1].prototype_obj` now set to `g_array_prototype`, matching `g_array_constructor_static`. Fixes `constructor ==` and some `instanceof Array` checks. array-v5 improved from ~440/560 to ~448/560 (80.0%).
- **builtin_array_method dispatch infrastructure** — Added `g_call_this_type` and callArrayMethod dispatch for array methods invoked via Function.prototype.call in CallMethod. Doesn't help array-v5 yet (SWF5 .call() blocker — see ARRAY_V5_PLAN.md).
- **Gnash misc-mtasc function_test PASS (21/21)** — Three fixes: (1) Array.prototype constructor property (file-scope g_array_constructor_static), (2) objectCallToString g_current_executing_func save/restore, (3) Array.prototype.toString stub returns "" instead of undefined. misc-mtasc now 5/9 passing.

### Latest fixes (2026-03-29)
- **Sort HOLE comparison (SWF < 7)** — HOLE elements now compare as empty string during sort for SWF5/6, matching Flash behavior where sparse array holes sort to the beginning.
- **Array.concat densification** — HOLE elements converted to UNDEFINED in concat results, matching Flash behavior.
- **Array.splice densification** — Remaining HOLE elements converted to UNDEFINED after splice, with proper enumeration key tracking.
- **sortOn UNIQUESORT fix** — UNIQUESORT without RETURNINDEXEDARRAY now correctly sorts in-place (was incorrectly returning index array). Fixes ~17 `tostr(r)` failures in array-v5.
- array-v5 improved from ~418/560 (74.6%) to ~440/560 (78.6%)

### Latest fixes (2026-03-27)
- **Color target toString() resolution** — Color.getRGB/getTransform/setRGB/setTransform now call toString() on object targets at each method invocation (Flash behavior). Fixes Color-v5.
- **Dynamic MC color transform** — Added color transform storage (cx_ra..cx_ab) to MovieClip struct. Dynamic MCs (createEmptyMovieClip) now support Color.getTransform/setTransform. Fixes Color-v5/v7/v8.
- **_alpha / Color transform dual quantization** — `_alpha` getter uses roundf quantization; `cx_aa` (Color.getTransform) uses integer truncation matching Flash's setTransform behavior. Fixes remaining Color-v7/v8 `trans2.aa` failures.
- Color-v6 improved from 93% to 97% (4 remaining failures: `typeof(c) == 'undefined'` for non-constructable Color in SWF6+).

### Latest fixes (2026-03-26)
- **XMLSocket.connect returns false** — All 4 XMLSocket tests now PASS (v5/v6/v7/v8). `connect()` stub changed from returning undefined to returning false.

## Related Documents

| Document | Purpose |
|----------|---------|
| `incomplete/GNASH_FEATURE_PLAN.md` | Hand-written phase plan: failures grouped by root cause / feature, per-phase progress notes |
| `FAILING_TESTS_BY_FEATURE.md` | Auto-generated (by `scripts/generate_failing_by_feature.py --suite=gnash/actionscript.all`): one category per `ClassName-vN` prefix, regenerated from latest results |
| `REMAINING_FAILURES_ANALYSIS.md` | Detailed tiered analysis with estimated fix effort |
| `incomplete/GNASH_NEAR_PASSING_PLAN.md` | 22 near-passing tests (<=18 diffs), 7 phases |
| `incomplete/ARRAY_V5_PLAN.md` | array-v5 investigation (450/560 = 80.4%) |
| `complete/SETTARGET_OBJECT_PATH_PLAN.md` | Extended setTarget to resolve dotted/colon object paths via property lookup (primary with-v6/v7/v8 blocker) — landed 2026-04-21 |
| `complete/ASSETPROPFLAGS_WITH_READONLY_PLAN.md` | ASSetPropFlags MOVIECLIP handling + WRITABLE check in WITH assignment (secondary with-v6/v7/v8 blocker) — landed 73983b0e |
| `superseded/WITH_AUTOBOXING_PLAN.md` | Shelved — primitive auto-boxing effectively works; see plan for actual remaining root causes |
| `complete/INHERITANCE_SEGFAULT_PLAN.md` | All 4 Inheritance tests pass filtered (v5 via SWF5 gates, v6/v7/v8 via Ruffle-matching acceptance) |
| `complete/RUFFLE_KNOWN_FAILURE_HANDLING_PLAN.md` | Phase 3 landed: `verify_output.py` auto-promotes `known_failure`+`output.ruffle.txt` tests to `ruffle_matched` when our diffs ⊆ Ruffle's diffs against Flash |
| `incomplete/MISC_SWFMILL_PLAN.md` | 5/6 fixed; only `jump_to_prev_block` remains, with a concrete consecutive-DoAction concatenation plan |
| `complete/DEJAGNU_FRAMEWORK_PLAN.md` | Dejagnu harness setup + misc-ming/misc-swfc blocker |
| `complete/TRY_FINALLY_PLAN.md` | Try-v6/v7/v8 OOM crash (FIXED) |
| `BLOCKER_SUMMARY.md` | Active and resolved blockers |
| `ACCEPTED_DIFFS.md` | Tests where our output is more correct than Gnash's expected |

## Test Structure

Gnash tests are organized as `ClassName-vN` where N is the SWF version (5-8). The same ActionScript class is tested across multiple SWF versions, so fixes often apply to 3-4 tests at once. All 190 actionscript.all tests include `Dejagnu.swf` as a child movie (SWF5 test harness).

---

## Critical Finding: Dejagnu.swf SWF5 Init Poisons Object.prototype

**Root cause**: All 190 Gnash tests load `Dejagnu.swf` (SWF version 5) via `actionImportAssets`. During import, `g_swf_version` is temporarily set to 5. If `getObjectPrototype()` is called for the first time during Dejagnu's init, the `if (g_swf_version >= 6)` guard at action.c:4732 prevents installation of `hasOwnProperty`, `isPropertyEnumerable`, `isPrototypeOf`, `watch`, and `unwatch`. Since Object.prototype is a singleton, these methods are permanently missing for the rest of execution.

**Impact**: This single bug causes ~33+ `hasOwnProperty` failures across Video, NetStream, Color, AsBroadcaster, Selection, Inheritance, and other test groups. It also breaks `instanceof` checks that depend on prototype chain methods.

**Fix**: Remove or restructure the `if (g_swf_version >= 6)` guard in `getObjectPrototype()`. Flash handles version-gating via ASSetPropFlags visibility masks, not by omitting methods. The methods should always be installed.

**Estimated improvement**: Fixing this alone should resolve 20+ tests' remaining diffs and could push the pass rate from 38 to 50+ tests.

---

## Segfaults (13 tests)

### Bug 1: Child Movie Transform Buffer Overflow (all 13 tests)

All Gnash tests include `Dejagnu.swf` as a child movie with 24 transforms (`Dejagnu_transform_data[24][16]`), but parent test SWFs typically have only 4 transforms. When the child sprite's frame function runs via `exec_sprite_frame` → `tagPlaceObject2` → `ng_cache_transform`, it uses the parent's `transform_data` array (because `g_active_transform_data` is NULL — only set during loadMovie, not direct sprite placement). Child transform indices (up to 23) overflow the parent's 4-entry array.

**Fix**: Set `g_active_transform_data` to the child's transform array in `exec_sprite_frame`, not just in the loadMovie path.

**Impact**: case-v5/v6/v7/v8 (4 tests) and HitTest-v6/v7/v8 (3 tests) would likely become output_mismatch or pass with just this fix.

### Bug 2: Try/Catch OOM via Infinite Loop (Try-v6/v7/v8) — FIXED

**Root cause**: Two bugs in exception handling:

1. **Runtime infinite loop**: `actionThrow` and `actionTryEnd` did not clear `has_jmp_buf` on exception handler frames before longjmp. For try-finally (no catch), where `actionCatchEnter` is never called, the handler's `has_jmp_buf` stayed set. When `actionTryEnd` in a nested try-catch inside the finally re-propagated a pending exception, it longjmp'd back to the same already-handled frame, creating an infinite loop that exhausted the heap.

2. **Recompiler: return inside finally skipped cleanup**: `actionReturn` inside a finally block emitted a direct C `return` without calling `actionTryEnd` or clearing the pending exception, leaving stale exception state after function return.

**Fix**: (1) Clear `has_jmp_buf` before longjmp in both `actionThrow` and `actionTryEnd`. (2) Recompiler emits `actionClearException` + `actionTryEnd` before return inside finally blocks.

Note: Try-v5 does not exist (only v6/v7/v8).

### Bug 3: NULL Property Name — ASArray/ASObject Cast (toString_valueOf-v5/v6)

During `actionAdd2` on two ARRAY values, `convertFloat` calls `getPropertyWithPrototype(obj, "valueOf", 7)`. The code at action.c:18042-18043 casts `ASArray*` to `ASObject*`, but these are different structs. The ASArray's `length` field is misinterpreted as `num_properties`, and iterating "properties" dereferences garbage, hitting a NULL `name` pointer.

**Fix**: In `convertFloat` (and similar sites), ARRAY type should use `arr->props` sub-object for property lookups, not cast to ASObject.

### Summary Table

| Test Group | Versions | Primary Bug | Secondary Bug | Fix Complexity |
|------------|----------|-------------|---------------|----------------|
| case | v5, v6, v7, v8 | Transform overflow | — | Low |
| HitTest | v6, v7, v8 | Transform overflow | — | Low |
| Try | v5, v6, v7, v8 | Transform overflow | OOM string concat | Medium |
| toString_valueOf | v5, v6 | Transform overflow | ASArray/ASObject cast | Medium |

---

## Compile Failures (35 tests)

### Category 1: `s16` Label Overflow (28 tests) — EASY FIX

**Error**: `error: expected ';' before '-' token` (negative label names like `label_-32710`)

**Tests**: BitmapData-v8, Global-v6/v7, Inheritance-v7/v8, Math-v5/v6/v7/v8, Matrix-v6/v7/v8, MovieClip-v5, Number-v5/v6/v7/v8, Point-v8, String-v5/v6/v7/v8, TextSnapshot-v6/v7/v8, array-v5, ops-v8, misc-swfmill/jump_to_prev_block

**Root cause**: In `action.cpp`, labels are generated using `(s16)(ptr - action_buffer_start)` at 8 sites (lines 309, 333, 650, 811, 1201, 1281, 1931, 1945). When bytecode blocks exceed 32KB (Gnash Dejagnu tests are large), offsets wrap to negative numbers.

**Fix**: Change `(s16)` to `(s32)` or `(int)` at all 8 label-generation sites. Pass 1 already uses `s64` for offset calculation.

### Category 2: Duplicate Labels from WITH Blocks (4 tests)

**Error**: `error: duplicate label 'label_91'`

**Tests**: with-v5/v6/v7/v8

**Root cause**: `parseActions()` is called recursively for WITH block bodies with a fresh `action_buffer_start`. Multiple WITH blocks with jump targets at the same relative offset produce identical labels in the same C function scope.

**Fix**: Namespace labels within WITH blocks (e.g., `label_W3_91` instead of `label_91`).

### Category 3: Cross-Frame ConstantPool (2 tests)

**Error**: Truncated C output (exception during Push)

**Tests**: misc-swfmill/dict_cross, misc-swfmill/dict_event

**Root cause**: Frame 1's DoAction defines a ConstantPool; frame 2's DoAction references it. But `constant_pool` is reset per `parseActions` call, so frame 2 has an empty pool and throws on out-of-range constant indices.

**Fix**: Persist ConstantPool across DoAction blocks within the same SWF.

### Category 4: Jump Past End of Actions (1 test)

**Error**: `error: label 'label_121' used but not defined`

**Test**: misc-swfmill/jump_after_end

**Root cause**: SWF bytecode jumps past END_OF_ACTIONS marker. Flash treats this as ending execution. Recompiler emits `goto label_121` but never defines the label.

**Fix**: Replace out-of-bounds gotos with `return;`.

### Priority

| Category | Tests | Fix Difficulty | Impact |
|----------|-------|---------------|--------|
| s16 overflow | 28 | Trivial (type cast change) | HIGH |
| WITH duplicate labels | 4 | Easy (label namespacing) | Medium |
| Cross-frame ConstantPool | 2 | Medium (state management) | Low |
| Jump past end | 1 | Easy (bounds check) | Low |

---

## Near-Passing Tests (>=80% match rate)

### Already identified root causes

| Test | Status | Notes |
|------|--------|-------|
| Boolean-v5/v6/v7/v8 | **PASS** (38/38) | Already passing since Phase 1 fixes |
| Video-v6/v7/v8 | **PASS** (85/85) | Already passing since Phase 1 fixes |
| Selection-v5 | **PASS** (21/21) | Already passing since Phase 1 fixes |
| Stage-v5 | **PASS** (38/38) | Already passing since Phase 1 fixes |
| Color-v5/v7/v8 | **PASS** (134/155/155) | Fixed: toString resolution, dynamic MC CxForm, dual quantization |
| Color-v6 | 161/165 (97.6%) | 4 remaining: `typeof(c) == 'undefined'` for non-constructable Color |
| NetStream-v6/v7/v8 | 72/74 (97.3%) | 2 remaining: `currentFps` not own property on prototype |
| TextFieldHTML-v6/v7/v8 | 86.5% | htmlText getter/text clearing bugs |
| Selection-v6/v7/v8 | ~86% | Selection non-constructable + `_listeners` own property |
| Inheritance-v5 | 114/114 expected | Filtered-passing; SWF5 gates + egg/chicken accepted |
| Inheritance-v6 | 173/181 (95.6%) | Filtered-passing; our diffs ⊆ Ruffle diffs (Ruffle known_failure upstream) |
| Inheritance-v7/v8 | 177/181 (97.8%) | Filtered-passing; our diffs ⊆ Ruffle diffs (Ruffle known_failure upstream) |

### v5-passes-but-v6-fails Pattern

11 classes pass at v5 but fail at v6+. SWF6+ tests exercise `_global.ClassName` access, `hasOwnProperty`, and `instanceof` — all features gated on SWF version 6+. The Dejagnu.swf SWF5 init poison is the primary cause.

---

## Recommended Work Order

### Phase 1: DONE — All compile failures, segfaults, and Object.prototype fixes applied
1. ~~**s16 label overflow**~~ — DONE (all 28 compile failures fixed)
2. ~~**Object.prototype SWF5 guard**~~ — DONE (hasOwnProperty always installed)
3. ~~**Transform buffer overflow**~~ — DONE (all 13 segfaults fixed)
4. ~~**WITH block label namespacing**~~ — DONE (4 compile failures fixed)
5. **ASnative class 101 (Object.prototype methods)** — DONE (2026-03-19). Gnash tests install hasOwnProperty/toString/valueOf/etc. on class prototypes via ASnative(101, N). Without this, ASnative returned undefined which shadowed the prototype chain.
6. **Color prototype unification** — DONE (2026-03-19). `new Color().__proto__` and `Color.prototype` now point to the same object, fixing `instanceof Color`.

### Phase 1b: DONE — Math, ops, Error edge case fixes (2026-03-20)
7. ~~**Math non-constructable**~~ — DONE. `new Math()` returns undefined (not object).
8. ~~**Empty string → NaN in convertFloat**~~ — DONE. `Math.round('')` now returns NaN for SWF5+, matching Flash/Ruffle. Also fixes `is_finite("")` consistency.
9. ~~**Math functions not standalone globals**~~ — DONE. Removed math builtins (acos, sin, etc.) from global function_registry — accessible only via `Math.method()`.
10. ~~**parseStringToNumber Infinity/NaN rejection**~~ — DONE. `Infinity == 'Infinity'` now correctly returns false in equality comparisons (strtod was parsing "Infinity"/"NaN" strings).
11. ~~**Error message coercion**~~ — DONE. `new Error(7.8898)` now coerces argument to string "7.8898".

**Impact**: Math-v5/v6: 6→5 diffs, Math-v7/v8: 7→5 diffs, ops-v8: 11→7 diffs, Error-v5/v6/v7/v8: 7→4 diffs each. All remaining diffs are accepted (Gnash bugs). See `ACCEPTED_DIFFS.md`.

### Phase 2: Prototype and constructor fixes (est. +10-15 tests)
12. ~~**ASArray/ASObject cast in convertFloat**~~ — Already fixed (arr->props sub-object used). toString_valueOf failures are from other causes.
13. ~~**`Object.prototype.constructor` setup**~~ — DONE (2026-03-23). Set constructor → Object on Object.prototype.
14. **Stage/Selection non-constructable** — Stage-v5 already passes. Selection-v6/v7/v8 have deeper issues (Selection indices, _listeners instanceof Array).
15. ~~**Color valueOf in setTransform + constructor target property**~~ — DONE (2026-03-25). Three fixes: (a) Color.setTransform now uses `varToDoubleSWF` (not `varToDoubleSimple`) for param properties, fixing valueOf on Number objects. (b) Color constructor stores raw target argument as own "target" property for all types. (c) Color.setRGB also uses varToDoubleSWF. Color-v5: 14→4 failures, Color-v7/v8: 18→8 failures each.
16. ~~**Try/finally control flow** — Try-v6/v7/v8 runtime errors.~~ **FIXED**
17. ~~**Built-in prototype own toString/valueOf**~~ — DONE (2026-03-23). Number.prototype, String.prototype, Boolean.prototype now have their own valueOf/toString methods distinct from Object.prototype's. Fixed in three locations: primary g_ctors, secondary constructors, and actionGetVariable special handlers.
18. ~~**Function.prototype.apply/call as properties**~~ — DONE (2026-03-23). apply and call registered as own properties on Function.prototype (both primary and secondary version groups).

**Phase 2 impact**: Line-level improvements across 15 tests (51 fewer mismatched lines). toString_valueOf +12 lines each, Number +2 each, String +1-3 each. Note: Boolean/Video/Selection-v5/Stage-v5 were already passing from Phase 1 fixes (CURRENT_STATUS.md was stale).

### Phase 3: Individual test fixes
12. TextFieldHTML htmlText getter
13. Cross-frame ConstantPool persistence
14. More ASnative classes (103=Date, 106=Number, 252=String, etc.)

---

## misc-ming.all and misc-swfc.all (74 tests, 11 passing)

These suites run in CI but were previously undocumented. Both use the **inlined
Dejagnu pattern** — test harness functions (`check_equals`, `pass`, `fail`,
`printtotals`) are compiled directly into each test SWF rather than loaded from
an external `Dejagnu.swf`.

| Sub-suite | Tests | Passing | Rate | Blocker |
|-----------|-------|---------|------|---------|
| misc-ming.all | 58 | 9 | 15.5% | Inlined Dejagnu DoInitAction ordering |
| misc-swfc.all | 16 | 2 | 12.5% | Same + 1 runtime error |

**Blocker:** Most failing tests produce zero PASSED/FAILED output despite
executing. The inlined Dejagnu functions are defined via DoInitAction on library
symbols. If the symbol's sprite isn't placed on the timeline, the DoInitAction
never fires and the check functions are never defined. This is an architectural
limitation of our DoInitAction handling — we only run DoInitAction for sprites
that are actually placed, while Flash runs them for all library exports.

See `complete/DEJAGNU_FRAMEWORK_PLAN.md` for the original investigation.
