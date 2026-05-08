# Test Suite Overview

Cross-suite summary of all Ruffle-derived test suites. Each suite has its own `_investigation/` directory with detailed status docs.

Last updated: 2026-05-08 (CI runs `25537136769` + `25537749870` — same-frame Remove+Place at root depth 100 fix landed in two passes. Initial commit `96a5d81e` promoted misc-ming.all `loop/loop_test10` output_mismatch (3/28) → ruffle_matched (5/28) but regressed `register_class/RegisterClassTest4` (17/42 → 6/42) because the char_id-based clear-skip fired for sprite-internal pending entries against the wrong (root) `display_list` array. Refinement `f0d575ca` snapshots the queue-time array pointer + orig instance_name and only honors the slot-renamed skip when the live array matches: RegisterClassTest4 restored to 17/42, loop_test10 stays ruffle_matched, +1 effective on misc-ming.all. Misc-ming.all effective: 88 → 89 (88/101 → 89/101 filtered, 86.3% → 87.3% raw / 88.1% filtered)).

Local edits since CI `d11aa45a`:
- **`opcode_guard_test` (misc-ming.all) added to ignored list.** Test cannot promote to `ruffle_matched` because we are *more* correct than Ruffle on the mc1 Construct/Load/Unload event handler assertions, which throws off line alignment with Flash's expected output (we emit one extra `Target not found` warning that Gnash's `output.txt` omits, while Ruffle emits the same warning but balances the line count by missing the event-handler success lines we get right). Cannot suppress the warning without regressing 8+ AVM1 tests that assert it. Documented in `from_gnash/_investigation/ACCEPTED_DIFFS.md` Category 1. Misc-ming.all filtered effective: 86/102 (84.3%) → 88/101 (87.1%).
- **`array-v5` (actionscript.all): +3 lines (519/560 → 520/560).** ASSetPropFlags now handles ARRAY targets — lazy-inits `arr->props`, finds-or-creates a metadata entry per named property (UNDEFINED placeholder + requested flags). Length-truncation in `actionSetMember` ARRAY-`length`-set branch honors DontDelete: protected indices are not cleared, and the preserved value is copied into `arr->props[<idx>]` so the props fallback in `actionGetMember` returns it once the index is past the new length. Fixes the `ASSetPropFlags(c, "2", 7, 0)` block (lines 278/279/280: `! delete c[2]`, `c[2] == 30` after failed delete, `c[2] == 30` after `c.length = 2`). Test stays `output_mismatch` (still no path to `known_failure` promotion — it's a raw failure). Effective rate unchanged on actionscript.all suite. No regressions on a 51-test battery (20 AVM1 array/object + 19 Gnash actionscript.all coercion + 12 misc-ming lifecycle).

## Suite Summary

"Effective pass" = raw pass + `ruffle_matched` (diffs ⊆ Ruffle's diffs against Flash; auto-promoted when upstream has `known_failure=true` + `output.ruffle.txt`).

| Suite | Tests | Pass | RM | Effective | Effective Rate | Filtered Rate | Notes |
|-------|-------|------|----|-----------| ---------------|---------------|-------|
| [avm1](../avm1/_investigation/CURRENT_STATUS.md) | 648 | 605 | 9 | 614 | 94.8% | **100.0%** (608/608) | 40 ignored. Zero filtered failures. `placeobject_occupied_depth` + `textsnapshot_available_text` recovered this CI via place-before-define narrowing. |
| [from_gnash/actionscript.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 190 | 126 | 63 | 189 | **99.5%** | — | Full Dejagnu recovery this CI: place-before-define narrowing skips the check inside `DefineSprite` and registers `ImportAssets` char_ids so the imported `dejagnu`/`dejafont` chars are no longer degraded. Only `array-v5` remains as raw failure (sort/Array-method-on-Object semantics). |
| [from_gnash/misc-mtasc.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 9 | 7 | 2 | 9 | **100.0%** | — | All effective pass. Unchanged this CI. |
| [from_gnash/misc-swfmill.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 18 | 17 | 1 | 18 | **100.0%** | — | All effective pass. Unchanged this CI. |
| [from_gnash/misc-ming.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 102 | 65 | 24 | 89 | 87.3% | **88.1%** (89/101) | 1 ignored (`opcode_guard_test`). `loop/loop_test10` promoted to ruffle_matched this CI via the same-frame Remove+Place fix (root timeline narrow). |
| [from_gnash/misc-swfc.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 16 | 8 | 6 | 14 | 87.5% | — | `opcode_guard_test2` promoted to ruffle_matched this CI: AS-level `removeMovieClip` on clips with `onUnload` now follows the deferred-removal pattern (shifted depth, dynamic_props/var_map preserved for same-frame reads). |
| [from_shumway](../from_shumway/_investigation/CURRENT_STATUS.md) (flat) | 92 | 72 | 3 | 75 | 81.5% | **98.7%** (75/76) | Place-before-define gain (+4 fuzz PASSes incl. 2 RMATCH→PASS for `1276557624…`, `a86fee6d…`; 2 newly RMATCH for `4949de46…`, `887c02ab…`) landed in CI `873e520e` and survived the narrowing in CI `8fdf3311` (fuzz tests have no inner-sprite PlaceObjects, so the inner-sprite skip didn't undo them). 16 still MISMATCH (in `ignored_tests.txt` as fuzzer noise). `avm1/moviecliploader` is the only non-fuzz failure. |
| [from_shumway/avm1](../from_shumway/_investigation/CURRENT_STATUS.md) | 47 | 45 | 0 | 45 | 95.7% | **100.0%** (45/45) | 2 ignored. Only `moviecliploader` remains (MCL one-tick deferral). Unchanged this CI. |
| **SWFRecomp/tests** (old suite) | 158+59 | all trace pass | — | — | **100%** | — | Hand-written opcode tests. CI only. |

## Progress Since 2026-05-08 (CI runs `25537136769` + `25537749870`) — same-frame Remove+Place at root depth

- **`loop/loop_test10` (misc-ming.all) → `ruffle_matched`** (was 3/28 output_mismatch → 5/28 ruffle_matched; +1 effective on misc-ming.all). Two paired fixes in `SWFModernRuntime/src/libswf/tag.c` for the same-frame Remove+Place at the same depth pattern (frame 3: `Remove(mc1)` + `SetInstanceName("mc2")` + `Place(mc2)` at depth 100):
  1. `tagSetInstanceName` skips the inline rename path and stashes the name as `g_pending_instance_name` when (a) `ng_depth_has_pending_finalize(depth)` is true AND (b) the new name differs from `display_list[depth].instance_name`. Without this, the still-live mc1 entry (deferred for finalize because of its UNLOAD clip event) was renamed to "mc2" inline, causing its queued UNLOAD trace to evaluate `this+' unloaded'` to `_level0.mc2 unloaded` (wrong binding) and making `actionFindOrCreateMovieClip("mc2")` return the dying mc1 pointer instead of creating a fresh MovieClip. The same-name guard preserves the existing event-ordering behavior for Remove+Place where the new placement keeps the same name (e.g., `RegisterClassTest4`'s mc3.frame_2 sprite-internal `Remove(Segments)` + `Place(Segments)` at depth 1).
  2. `PendingFinalizeEntry` now snapshots the queue-time `display_list` pointer (`queued_dl_array`) and the orig `instance_name` (64-byte buffer). `run_pending_finalize` only honors the slot-renamed skip when the live `display_list` array matches the queue-time pointer AND the live name differs from orig. For sprite-internal pending entries, `display_list` is swapped back to root by the time `run_pending_finalize` fires (it's a global pointer, swapped per-frame in `exec_sprite_frame` call sites), so without the array-pointer guard the comparison would be against the wrong slot in root's array.

- **Initial fix (`96a5d81e`) regressed `RegisterClassTest4`** (17/42 → 6/42) because the original char_id-based skip was firing on sprite-internal pending entries when their queue-time char_id differed from root's depth-1 char_id (where the test's "mc" lives). Refinement `f0d575ca` added the `queued_dl_array` snapshot to gate the skip to root-context entries only. Restored RegisterClassTest4 to 17/42 baseline, kept loop_test10 at ruffle_matched.

- **Verified no regressions** across 32-test AVM1 lifecycle/clone/register/replace battery, 28-test misc-ming.all near-passing battery, 13-test misc-swfc battery, 9-test misc-ming.all loop battery, 12-test misc-ming.all action_order battery. Other suites (avm1, actionscript.all, misc-mtasc.all, misc-swfmill.all, misc-swfc.all, from_shumway*) all unchanged.

## Progress Since 2026-05-07 (CI run `46d78af6`) — AS-level removeMovieClip onUnload deferred path

- **`opcode_guard_test2` (misc-swfc.all) → `ruffle_matched`** (was 2/24 output_mismatch → 19/24, diffs `{4,7}` ⊆ Ruffle's `{12,13,18}`). +1 effective on misc-swfc.all (8/16 → 9/16; 8 PASS + 6 RM = 14 effective; -17 mismatched lines). Three fixes in `SWFModernRuntime/src/actionmodern/action.c`:
  1. `actionSetTarget` var_map MOVIECLIP fallback. AS-created clips (`duplicateMovieClip` / `CloneSprite` / `createEmptyMovieClip`) register their clones in `var_map` (via `setVariableByName`) but not in the parent's `display_list` / `dynamic_props`, so `resolveSlashPathToMC` walks failed and `SetTarget('<name>')` fell through to "Target not found". Mirroring the existing GetMember var_map check (action.c ~44801) as the final fallback before the warning emission lets `setTarget('dup1')` / `setTarget('dup3')` resolve, matching Ruffle's stage-object lookup for AS-created MCs.
  2. `actionRemoveSprite` + `mc.removeMovieClip()` deferred path for AS-level `onUnload`. Both sites previously set `mc->depth = INT_MIN` and cleared `var_map` / `parent.dynamic_props` immediately, regardless of `onUnload`. Mirroring the tag-level RemoveObject2 pattern (`actionMarkMCPendingRemoval`), a clip with `onUnload` now parks at shifted depth `-(swf_depth) - 1 - 16384` with `pending_removal=1`, keeps `dynamic_props` intact, and leaves `var_map` / `parent.dynamic_props` bindings alone for same-frame reads. The "no-onUnload" path is unchanged. Also extends the "removed-MC was the active SetTarget context" reset to fire when `g_base_clip` is NULL but `g_settarget_context_changed` is set, so subsequent variable reads in the now-dead clip's setTarget block fall back to root via `g_settarget_invalid` / `g_settarget_none`.
  3. `actionFinalizePendingRemovals` cleanup of `var_map` / `parent.dynamic_props` for finalized deferred-removal MCs (only when bindings still reference the MC, to avoid clobbering same-name re-placements). Without this, the AVM1 `unload` test sees `_root.clip4` still resolving to a MOVIECLIP value with `depth=INT_MIN` instead of expected `undefined`.

- **No regressions.** AVM1 `unload` and 43 other lifecycle/clone/unload/movieclip-state tests still pass. Other suites unchanged.

## Progress Since 2026-05-07 (CI runs `f3965a99` + `d11aa45a`) — net zero, two attempts reverted

- **`native_objects_swf6` SWF6 `new TextField()` triage.** Tried gating
  `actionNewObject` on `g_swf_version == 6` to push UNDEFINED so line 56
  (`new TextField(): non-object: undefined`) would match. CI surfaced two
  regressions the local 16-test battery missed: `avm1/textfield_props_swf6`
  (PASS 210/210 → 77/210; expects `new TextField()` to be a real object
  with 35 enumerable properties) and `from_gnash/actionscript.all/toString_valueOf-v6`
  (ruffle_matched 150/155 → output_mismatch 141/155; asserts
  `typeof(new TextField()) == "object"`). Both Flash and Ruffle return a
  real object for `new TextField()` in SWF6 per these tests' expected
  output (neither marked `known_failure`); the `native_objects_swf6` line
  56 expectation is internally inconsistent with the rest of the AVM1
  corpus. Reverted (`d11aa45a`); documented in
  `avm1/_investigation/ACCEPTED_DIFFS.md` Category 2. The test stays in
  `ignored_tests.txt` as `known_failure`, so the residual 1-line diff
  doesn't affect the filtered pass rate.

- **`from_gnash/misc-ming.all/action_order/action_execution_order_test5` triage.**
  Tried the conservative half of `SPRITE_REWIND_IDENTITY` (Phase 1
  metadata + survives_rewind preservation in `advance_sprite_frames`
  natural-wrap, no UNLOAD lifecycle for non-survivors). Test went 26/35 →
  PASS locally, avm1 sprite/loop battery (15/15) and gnash sprite-loop
  battery (7/7) unchanged. But `RegisterClassTest4` regressed by ~9
  lines (8/42 vs baseline 17/42) — the documented STOP signal from
  `blocked/SPRITE_REWIND_IDENTITY_PLAN.md`. Reverted before commit.

## Progress Since 2026-05-07 (CI run `8fdf3311`) — place-before-define narrowing landed

CI deltas vs broken CI `873e520e`: AVM1 +2, Gnash actionscript.all +189 effective, all other suites unchanged. Vs pre-place-before-define baseline `e0af5c2d`: only +4 Shumway flat fuzz PASSes survive (the intended gain). No regressions.

The CI run `873e520e` exposed a much wider blast radius for the original place-before-define fix than the pre-CI canaries (26 AVM1 + 12 Shumway flat) caught. Two unintended regressions, both from the same root cause:

1. **Gnash actionscript.all collapse 189 → 0 effective.** All Dejagnu-driven tests went 0/N. `delete-v5/test.swf` (and every other actionscript.all test) imports the `dejagnu` sprite + `dejafont` font from `Dejagnu.swf` via `ImportAssets`, which assigns local `char_id=2` (dejagnu) and `char_id=3` (dejafont). Then it `DefineSprite char_id=1` containing inner `PlaceObject2 char_id=2 / 3`. The recompiler's tag-stream `defined_chars` set didn't track `ImportAssets` registrations, AND it applied the place-before-define check inside `DefineSprite` even though sprite-internal placements run at runtime (long after the full root dictionary is built). Result: the `xtrace_win` EditText that Dejagnu uses for trace assertions never instantiated.

2. **2 AVM1 PASSes regressed.** `placeobject_occupied_depth` (DefineSprite 1 places char_id=2 internally before DefineSprite 2 in root tag stream) and `textsnapshot_available_text` (DefineSprite 1 places char_ids 2/3/4 internally before their Define* tags). Same root cause as Dejagnu — sprite-internal place-before-define is overzealous because inner tags don't fire until runtime instantiation.

**Narrowing fix in `SWFRecomp/src/swf.cpp` (commit `8fdf3311`):**
- Removed the place-before-define check at both sprite-internal sites (PlaceObject and PlaceObject2/3 inside `DefineSprite`'s sub-tag handler). Sprite placement runs at runtime; the check should only apply to root-timeline tags.
- Added `defined_chars.insert(imp.char_id)` in the `ImportAssets`/`ImportAssets2` handler so root-level PlaceObject* of imported chars isn't degraded.
- The +4 Shumway gain is preserved (fuzz tests have no inner-sprite PlaceObjects, so removing the inner-sprite check doesn't undo them).

For audit, the un-narrowed CI `873e520e` (commits `7875fb4a` / `ba7a4725` / `5331ed4b`) deltas vs `e0af5c2d`:
- **+4 Shumway flat fuzz PASSes** — `1276557624…`, `4935e4ae…`, `a86fee6d…`, `b480790b…`. Plus 2 RMATCH→PASS upgrades and 11 fuzz tests with reduced mismatched lines.
- **-189 effective Gnash actionscript.all** — 126 PASS + 63 RMATCH all collapsed to 0/N matching lines (Dejagnu init broken).
- **-2 AVM1 PASS** — `placeobject_occupied_depth` (runtime_error), `textsnapshot_available_text` (13/20).

## Progress Since 2026-05-07 (CI snapshot at `035950cf`)

- **`TextFormat-v7` (Gnash actionscript.all) → ruffle_matched (136/174, was 132/174 → output_mismatch).** `ng_getTextExtent` now returns `textFieldWidth = wrap_width` when a wrap width arg is provided, matching Flash's `EditText` with `AutoSize::Left + word_wrap=true` (which keeps the assigned width). Without wrap, behavior is unchanged: `tf_width = text_width + 4` gutter. Confirmed via Ruffle's source (`text_format.rs::get_text_extent`: creates EditText with `width.unwrap_or(0.0)` + `set_word_wrap(width.is_some())`, then returns `temp_edittext.width()`) and Ruffle's own AVM1 `gettextextent` test where `textFieldWidth` exactly equals the wrap width passed in. Fix is one line in `SWFModernRuntime/src/libswf/ng_shared.c`. Promotes the test because the 4 wrap-width assertion lines (`textFieldWidth == 10/5/30/30` at TextFormat.as:380/397/413/422) flip from FAILED to PASSED, eliminating the only diff-set lines that were ours-but-not-Ruffle's. Verified no regressions: AVM1 `gettextextent` and `text_format_get_text_extent_undefined_width` both still PASS (former has `epsilon = 30.0` tolerance plus `with_default_font = true`; latter only checks `> 0`); 8-test edittext battery (8/8 PASS); Gnash actionscript.all `TextFormat-v5/v6` unchanged PASS; misc-ming `DefineEditTextTest` / `DefineEditTextVariableNameTest2` / `DefineTextTest` / `EmbeddedFontTest` / `DefineEditTextVariableNameTest` all unchanged from baseline (the latter two were already failing — their pre-existing diffs do not touch the wrap-width path).

## Progress Since 2026-05-06 (CI snapshot at `c8f6452a`)

- **`assetnativeaccessor` + `assetnativeaccessor_ids` (AVM1) → PASS.** `ASSetNativeAccessor` builtin and ConvolutionFilter (class 1109) `ASnative` dispatch landed. Plan moved to `avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md`.
- **`key_event_test` (Gnash misc-ming.all) → ruffle_matched (61/66, was 33/66 → output_mismatch).** Phase 2 of the key-event work narrowed `tagRemoveObject2`'s backward-catch-up early-return.
- **`loop/loop_test6` (Gnash misc-ming.all) → ruffle_matched (22/23, was 11/23 → output_mismatch).**

## Progress Since 2026-05-06 (CI snapshot at `c8f6452a`) — fixed

- **`try_catch_stack` (AVM1) → PASS (16/16).** `actionCatchEnter` now truncates the value stack to its size at try-begin if the body net-pushed values that survived the throw — mirrors Ruffle commit `0fc689cce` (`Vec::truncate(original_stack_size)`). Truncate-only is load-bearing: symmetric SP restore would un-pop body-side pops, breaking the test's "in reverse" section. Plan in `avm1/_investigation/complete/TRY_CATCH_STACK_PLAN.md`.

## Progress Since 2026-05-05 (CI snapshot at `c5994ec1`)

The 2026-05-04 fixes that were "NOT yet in CI" in the last snapshot landed in this CI run:

- **frame_label_test (Gnash misc-ming.all) → PASS** via `actionCall`'s isolated drain (snapshot+suppress+above pattern in `CALL_FRAME_FUNC`). See "Progress Since 2026-05-04" below for full details.
- **soft_reference_test1 (Gnash misc-swfc.all) → ruffle_matched** via `_name` setter syncing `parent.dynamic_props` + `var_map`.
- **Global-v6 (Gnash actionscript.all) → ruffle_matched, Global-v7/v8 → PASS** via `ASSetNative` implementation (was a noop).
- **`assetnative` + `assetnative_ids` (AVM1) → PASS** as side-effect of ASSetNative.
- **5 Shumway fuzz tests with `this._currentframe` traces → PASS** via natural-advance `mc->currentframe` sync in `advance_sprite_frames`.

## Progress Since 2026-05-04

- **Shumway fuzz timeline tests `this._currentframe` (+5 effective).** `c8b8069c…`, `ac93c8c9…`, `07580c34…`, `2f4f46bf…`, `81004241…` (all `from_shumway/fuzz/`) → PASS. Root cause: `mc->currentframe` was never updated during natural sprite advance in `advance_sprite_frames`. The C runtime tracks two parallel frame counters: `obj->sprite_current_frame` (DisplayObject, 0-indexed, advances each tick) and `mc->currentframe` (MovieClip, 1-indexed, exposed to ActionScript via `_currentframe`). Only `obj->sprite_current_frame` was incremented per frame; `mc->currentframe` was set to 1 at MC creation and only updated by `ng_setSpriteFrame`/`ng_gotoFrameByMC` (goto paths) and by the recompiler-emitted root-frame updates. So `this._currentframe` from inside any sprite frame script returned 1 always (initial value) instead of the executing frame number. Fix in `SWFModernRuntime/src/libswf/tag.c` `advance_sprite_frames`: just before `CALL_FRAME(...)` at line ~941 (natural advance), look up the sprite's MC by `obj->instance_name` and set `smc->currentframe = (int)frame + 1`. Mirrors `swf_core.c`'s update of `root_movieclip.currentframe` before each root frame func. Manual nav (gotoAndPlay/gotoAndStop catch-up) intentionally not affected — those paths already set `mc->currentframe` to the target value before the catch-up loop. Bumps Shumway flat from 67/92 → 72/92 (+5 effective). Verified: 22-test AVM1 lifecycle (22/22), 17-test AVM1 lifecycle/scope (17/17), 6-test sprite state (6/6), 14-test misc-ming goto/loop/timeline (14/14), 14-test AVM1 timeline (14/14), 5-test gnash actionscript.all spot-check (5/5 effective). The 27 numeric-output fuzz tests in `from_shumway/fuzz/*` likely all use this pattern; expect more flips on next CI run.

- **`frame_label_test` (Gnash misc-ming.all) → PASS (+1, was 12/17 + 153 lines of timeline-loop noise).** `actionCall`'s
  `CALL_FRAME_FUNC` was invoking the called frame's recompiler-emitted `actionDrainOnloadAndScript` while the outer
  frame's drain was in progress, so the inner drain consumed the parent's pending queue entries — running
  `script_31`/`32`/`33` (`_root.x1==0` checks) **before** the called frame's `script_0` (`x1=0; ...`), and running
  `script_34` (`_root.totals(); stop()`) inside the call's `is_playing` save/restore window so the `stop()` was
  overwritten on call return. The assertions then read the pre-call values and `is_playing` stayed true, looping the
  timeline ~9× and emitting the assertion set on each cycle. Fix: snapshot `g_aq_count` at `CALL_FRAME_FUNC` entry,
  bracket the frame call with `actionDrainSuppressEnter`/`Leave`, then drain only entries with index ≥ snapshot via a
  new `actionDrainOnloadScriptAbove(floor)` helper — outer pending entries stay in the queue for the outer drain to
  process in FIFO order. Mirrors Ruffle's per-call action stack: each `call()` runs its own private action layer.
  Files: `SWFModernRuntime/include/actionmodern/action_queue.h`, `src/actionmodern/action_queue.c`,
  `src/actionmodern/action.c`. Bumps Gnash misc-ming.all from 78/102 → 79/102 effective. No regressions on a 25-test
  AVM1 call/scope/super battery or a 14-test misc-ming goto/loop/action-order battery (`ActionOrderTest3/4` already
  failing in CI baseline, unchanged).

- **`soft_reference_test1` (Gnash misc-swfc.all) → ruffle_matched (+1).** The `_name` setter (`actionSetMember` MOVIECLIP path in `action.c`) now syncs the rename to `parent.dynamic_props` (new key → MC, old key → undefined) and, when `mc->parent == &root_movieclip`, to `var_map` (with SWF<=6 lowercase folding via `setGlobalVariableByName`). Without this propagation, after `mc._name = "changed"` the stale `var_map["mc"]` and `parent.dynamic_props["mc"]` entries still resolved to the MC, breaking the test's "soft reference" semantics: `typeof(mc) == 'undefined'` returned false on the very first assertion (line 50), cascading into 20 follow-on failures. Mirrors Ruffle's `MovieClip::set_name`, which removes the old name binding on the parent's stage-object scope and installs the new one. The sync only fires when the existing binding is authoritative (entry references THIS MC under a key matching the MC's old name) to preserve case-collision entries from `case-v6` (`_root.clip` / `_root.CLIP`). Final residual diff is line 164 (`mcRef == _level0.mc1` after `removeMovieClip` + recreate at a different depth — Ruffle also fails this), so the test promotes via subset-match to ruffle_matched. Brings misc-swfc.all from 11/16 → 12/16 effective (68.8% → 75.0%).

- **ASSetNative implementation → Global-v6/v7/v8 (Gnash actionscript.all) effective pass + assetnative + assetnative_ids (AVM1) PASS.** `ASSetNative` was previously a noop (`builtin_noop_func`); now `builtin_assetnative` parses the comma-separated `props` argument (after `toString` coercion via `convertString`), strips an optional leading version-flag digit (`'1'`, `'6'`, `'7'`, `'8'`, `'9'`, or `"10"`), and for each non-empty name binds the result of `ASnative(major, minor + i)` on the target object (via `setProperty`). Position counter `i` increments per comma — matching gnash's `Global_as.cpp::global_assetnative` (which only handles `6/7/8/9`) plus the Flash-specific `1`/`10` prefixes exercised by `avm1/assetnative` and `avm1/assetnativeaccessor` under SWF 7. `minor` (4th arg, default 0) and `major` (2nd arg) are coerced via `convertFloat` so a `valueOf` exception unwinds through the bytecode-level try/catch. Empty names are skipped but still consume an index slot. Version-gating: when the prefix indicates SWF >= N and current player < N, the install behaviour depends on existing property state — own exists → overwrite with function; own absent + inherited present → install with the *inherited* value (which keeps `versions.X == proto.X` semantics in `for (i in o)` while still adding the name to `o`'s own properties); own absent + nothing inherited → install undefined. This three-way split is the exact rule observed in Flash for the `1a,2b,...,8h,...,10j` permutation in `avm1/assetnative` under SWF 7. Cross-cutting fix on the side: `convertString` for `ACTION_STACK_VALUE_ARRAY` now consults `objectCallToString` first (own-prop-only lookup on `arr->props`) before falling back to the existing `Array.prototype.join(",")` behaviour — required by Gnash's `ASSetNative(o, 200, a, 10)` with `a.toString = function() { return "o, j"; }`. Both `assetnative` (was 27-line diff) and `assetnative_ids` (was 6-line diff) AVM1 tests now PASS; the two `assetnativeaccessor*` tests still fail (need `ASSetNativeAccessor` impl + class 1109 ConvolutionFilter ASnative dispatch). Regression battery: 20-test AVM1 array/watch/execution-order suite (20/20 PASS), 22-test Gnash actionscript.all Global/Inheritance/Math/Number/Color/ASnative battery (22/22 effective pass).

## Progress Since 2026-05-02

- **mouse_drag_test (Gnash misc-swfc.all) → PASS.** `startDrag` on a MovieClip now sets `display_obj->transformed_by_script = 1` on the dragged clip directly, mirroring Ruffle where `update_drag` calls `set_x`/`set_y` per tick (which set the flag) even when the mouse hasn't moved. We don't run a `update_drag` analog in headless mode, so the flag must be set at startDrag time. Once set, subsequent timeline `PlaceObject` MOVE tags no-op on the dragged clip's matrix (per `apply_place_object`'s `if !transformed_by_script` guard in `tag.c`), and the flag persists past `stopDrag` — matching Flash semantics where a dragged clip stays "transform-locked." Applied to both the function-form `actionStartDrag` (resolves target name → MC) and the method-form `mc.startDrag()`. Fixes lines 5-8 of `mouse_drag_test.sc` (`check(mc1._x != 200/300)` and `check(mc1._y != 200/300)` after `.jump mc1 x=N y=N` during/after drag). Regression: 5/5 AVM1 drag tests + 18/18 transform/timeline tests + DragDropTest unchanged.

- **registerClassTest2 (Gnash misc-ming.all) → ruffle_matched** (commits 802674fd + 3c67568f). When `Object.registerClass` replaces an MC's `__proto__` chain to a class whose prototype does NOT extend MovieClip (e.g. `theClass2.prototype = {}` instead of `new MovieClip()`), MC-specific builtins like `getDepth()` should resolve to undefined — they're inherited from `MovieClip.prototype` which is no longer in the chain. Fix: at the top of the MOVIECLIP arm of `actionCallMethod`, walk `dynamic_props.__proto__` looking for any `MovieClip.prototype` variant (legacy/modern/default); if not found AND mc is not a TextField/Button, `goto _mc_user_dispatch` past the entire builtin chain. Object.prototype-inherited names (`addProperty`, `hasOwnProperty`, etc.) are explicitly preserved through the existing path. The TextField/Button exclusion is load-bearing — without it, 32 EditText + 3 TextFieldHTML + 1 DefineEditTextTest regress because TextField/Button MCs share the MOVIECLIP dispatch path but their `__proto__` chain ends at `Object.prototype`, not `MovieClip.prototype`. Reproduced in CI run 25259793074, fixed in 25260113699. Line 153 (`clip2.getDepth() == undefined`) now PASSES; residual 8-line diff (clipevs/clip3 onLoad ordering) is a subset of Ruffle's diff against Flash. See `from_gnash/_investigation/incomplete/REGISTERCLASS_LIFECYCLE_PLAN.md` "2026-05-02 session" section.
- **swf4opcode (Gnash misc-swfc.all) → ruffle_matched.** SWF4 `Equals` (action 0x0e) coerces both operands to f64 via `convertFloat`. Our `convertFloat` for `ACTION_STACK_VALUE_MOVIECLIP` returned NaN unconditionally; should return 0.0 in SWF<5 (matching Ruffle's `coerce_to_f64` for `Value::MovieClip`, which goes through `Value::Object(...) → primitive_as_number`, gating Object→0.0 on `swf_version < 5`). Group B (lines 363/365: bare `mc1` and `/:mc1` compared with undefined) now passes — both MC and undefined coerce to 0.0 → equal. Group A (lines 74/82/90/98: `/mc1:_PROPNAME` colon-path) still fails but is a subset of Ruffle's diff against Flash, so the test promotes to ruffle_matched (full PASS would require fixing SWF4 colon-var-vs-property semantics).

## Progress Since 2026-05-01

- **loadvars_tostring (AVM1) → PASS** (commit 48a97e0b). `builtin_loadvars_toString` iterated own_props and serialized `p->value` directly, ignoring addProperty-defined virtual properties; entries registered via `lv.addProperty(name, getter, setter)` serialized as `name=undefined`. Fix: when `p->getter` is non-NULL, call `invokePropertyGetter(lv)` and serialize the returned value. Throws inside the getter still longjmp through to the bytecode-level try/catch via `g_exception_state`, matching the test's `Caught: some error` path. Brings filtered AVM1 to 603/603 (100%).
- **bitmap_filters (AVM1) → PASS** (commit 900ae800). Timeline filter reconstruction reorders `BevelFilter` / `DropShadowFilter` / `GlowFilter` / `GradientGlow/GradientBevel` properties to match Flash's enumeration order. `verify_output.py` now honors `[approximations.number_patterns]` in test.toml — each regex's capture groups compared as floats with the configured `epsilon`, then matched substring stripped and the remainder compared exactly.
- **tags_after_last_showframe (Gnash misc-swfmill) → PASS** (commit 9020f664). Recompiler `swf.cpp` END_TAG handler: when the SWF has tags after the last `ShowFrame`, the recompiler opens a new dangling frame whose `ShowFrame` never lands (`another_frame == false` at END_TAG); previously this frame was treated as a normal frame and looped back to `frame_0`, re-executing the trailing DoActions on every iteration. Fix: emit `quit_swf = 1` in the dangling frame instead of `next_frame = 0; manual_next_frame = 1`. Mirrors Flash/Ruffle (trailing tags only on initial play).
- **Instance-v5/v6/v7/v8 (Gnash actionscript.all) → effective +4** (commit faf492a5). Three changes: (a) `new` on native non-constructor C functions (e.g. `new Math()`, `new Date.UTC()`) creates an empty object with `__proto__ = ctor.prototype` instead of crashing; (b) `Object.prototype` mutation protection — `Object.prototype.x = y` writes are silently dropped in SWF<=5 (matches Flash); (c) non-object prototype propagation: when `Foo.prototype` is set to a non-object value, `new Foo()` falls back to `Object.prototype`.
- **Global-v6 (Gnash actionscript.all) → effective +1** (commit 600dc2c1). `actionGetVariable` now folds the lookup name to lowercase before hitting the built-in registry in SWF<=6, so `Math.max` / `MATH.MAX` / `mAtH.mAx` all resolve to the same builtin (matches SWF<=6 case-insensitive variable resolution).
- **GetMember/SetMember own-prop walk (cross-cutting)** (commit fac77e42). `actionGetMember` and `actionSetMember` now walk past ASSetPropFlags-hidden own properties (where `isPropertyHiddenAtVersion(p->flash_flags)` returns true) instead of stopping at them — restores prototype-chain visibility when a hidden own-prop shadows a visible inherited property at the same name.
- **ecmaToInt32 / ASSetPropFlags array / convertFloat strict mode** (commit 7a1f04a0). `ecmaToInt32` now uses `trunc` semantics (rounds toward zero) instead of `floor`. `ASSetPropFlags` accepts an array of names. `convertFloat` strict mode for SWF6+ rejects strings with leading/trailing whitespace.

## Progress Since 2026-04-30

- **movieclip_destruction_test2 (Gnash misc-swfc) → PASS** (in CI at 25231855425). New `setGlobalVariableByName` helper bypasses the local-scope short-circuit in `setVariableByName` for the var_map sync inside `actionSetMember` on the root MC. Previously, `_root.foo = X` from inside any function dispatched through `actionCallMethod`'s MOVIECLIP user-method path created a stale local-scope shadow instead of updating `var_map`, so subsequent bare `foo` reads returned the pre-call value. Auto-fired unloads were unaffected because their dispatcher (`invokeSpecialFunction`) does not push a local scope for type-1 functions; manually-invoked `mc.onUnload()` did, exposing the bug.
- **case-v6 (Gnash actionscript.all) → PASS** (commits 6476ad2f, c42eb4d6, d2647520). Two SWF6-specific fixes: (a) slash-path `SetProperty`/`GetProperty` now route through `resolveSlashPathToMC` (with `swf_name_match` for `_root`/`_level0`) so `/_ROOT/MC0/` resolves case-insensitively in SWF<=6; (b) method-form `createEmptyMovieClip` skips rebinding `parent.dynamic_props[name]` and (root-only) `var_map[name]` when an existing entry references a LIVE MovieClip whose current `name` still matches the key (case-insensitive) — covers both `clip`/`CLIP` (case-collision) and `mc1`/`mc1` at different depths (same-name collision), while leaving renamed-MC stale entries available for rebinding (soft_reference_test1.sc:107-147 line 147 also flips PASSED).
- **ExternalInterface-v6 / ExternalInterface-v7 (Gnash actionscript.all) → PASS** (commit f62d59c4). All EI internal methods (`_argumentsToAS`, `_arrayToAS`, `_callIn`, `_escapeXML`, `_initJS`, `_jsQuoteString`, `_objectToAS`, `_toAS`, `_toJS`, `_toXML`, `_unescapeXML`, etc.) plus `addCallback` and `available` now marked with `flash_flags = 0x1000` — visible to `hasOwnProperty` but hidden from `getProperty` in SWF<=7 (SWF6 mask 0x7500 / SWF7 mask 0x7000 both include 0x1000; SWF8 mask 0x6000 does NOT). Only `EI.call` keeps `flash_flags=0` (visible in all versions, matching `Function.prototype.call` inheritance).
- **DepthLimitsTest (Gnash misc-ming) → PASS** (commit 61229899). `duplicateMovieClip` rejects out-of-range AS-depths (valid range [-16384, 2130690044]). Two checks: method-form rejects unbiased depth outside that range directly; function-form `actionCloneSprite` rejects `depth_int < -16384` (the recompiler bias-strip heuristic leaves small AS-depths unbiased while large positive depths arrive biased — biased depths are always ≥ 0 so the lower-bound check fires only on the unbiased path). Upper bound was already enforced by `ng_cloneSprite`'s biased-form guard.

## Progress Since 2026-04-18

- **ACTION_QUEUE_PLAN** — multi-phase architectural rework landing a Ruffle-style unified ActionQueue (Phases 0–8 all landed, plan marked complete at commit fe74d7aa). Motivated by `from_shumway/avm1/doactionorder` and timeline execution-order parity; enabled subsequent gnash and shumway fixes.
- **String wrapper dispatch + ruffle-match** (Gnash) — d05bbd56, f70ecdb0, 41f62c81. String-vN tests auto-promoted to `ruffle_matched` via stubbed call/apply, DontDelete, constructor, override, direct method dispatch, and enumerate fallback.
- **with-v6/v7/v8 → `ruffle_matched`** (Gnash) — 73983b0e + 7155a774 (latest CI delta). Two fixes: (a) `actionASSetPropFlags_func2` MOVIECLIP handling + WRITABLE check in WITH-scope assignment, (b) `resolveObjectPathToMC` walks dotted/colon paths via property lookup with `__proto__` fallback. Eliminated ~14 stray `Target not found`/`FAILED _target==` lines per test.
- **`depth_replacement_audio_unloading` PASS** (AVM1) — `verify_output.py` extracts all 14 raw-data arrays from a child SWF's `draws.c` and prefixes them; `actionFirePendingLoadInits` Phase 2 saves/restores `is_playing` so a child's `stop()` doesn't terminate the parent's frame loop.
- **`function_as_function` PASS** (AVM1) — `Function()` without `new` returns a bare object with no `__proto__`.
- **`bitmap_data_thorough/*` final cleanup** (AVM1) — suite now 16 PASS + 3 ruffle_matched + 1 accepted (pixelDissolve). All plan work complete.

## Progress Since 2026-03-19

### Shumway flat suite: Complete — 15/17 → 17/17 (100% AVM1)

Two fixes (commit 3b075cff):
1. **targetPath1** — MC `toString()` fallback to `MovieClip.prototype` → `Object.prototype` chain
2. **doubleAndRegister** — `registerClass` char_id-based lookup for multi-export sprites

Ignore list created for 30 AVM2/AS3 tests. Suite is complete.

### Gnash: Phase 1b complete, ignore list created

Phase 1b fixes (Math, ops, Error edge cases) applied. 9 tests with all-accepted diffs (Gnash bugs) added to ignore list. Line-level match improved from 65.0% → 69.1% (unfiltered) / 66.3% (filtered).

### Gnash: Phase 2 in progress (2026-03-23)

Phase 2 fixes applied (commit 15ce3f06):
- **Built-in prototype own toString/valueOf** — DONE. Number/String/Boolean prototypes now have own valueOf/toString distinct from Object.prototype. Line-level improvements across 15 tests: toString_valueOf +12 lines each, Number +2, String +1-3.
- **Function.prototype.apply/call** — DONE. Registered as own properties on Function.prototype.
- **Object.prototype.constructor** — DONE. Set constructor → Object on Object.prototype.

Note: Boolean-v5/v6/v7/v8, Video-v6/v7/v8, Selection-v5, Stage-v5 were already passing from Phase 1 fixes (CURRENT_STATUS.md was stale).

### Gnash: Phase 2 continued (2026-03-25)

- **Color valueOf + constructor target** — DONE. Color.setTransform/setRGB use `varToDoubleSWF` for valueOf on Number objects. Color constructor stores raw target argument as own property. Color-v5: 14→4 failures (-10), Color-v7/v8: 18→8 each (-10).
- **Stage/Selection non-constructable** — Stage-v5 already passes. Selection-v6/v7/v8 have deeper issues beyond non-constructable.

### AVM1: tab_ordering_properties_tab_index_edge_case (2026-03-25)

- **tabIndex string storage** — DONE. tabIndex setter now stores string values as-is (Flash behavior) instead of discarding non-numeric values. New PASS: tab_ordering_properties_tab_index_edge_case.

### AVM1 + Gnash fixes (2026-03-26)

- **Array.join HOLE→"undefined"** — DONE. Array.join/toString now correctly converts HOLE (unset) elements to "undefined" instead of empty string. Fixes 4 AVM1 tests: array_constructor, array_properties, external_interface_toxml_basic, global_array.
- **verify_output.py UTF-8 error handling** — DONE. Added `errors="replace"` to output.txt reads. Fixes string_relational_compare runtime_error → output_mismatch.
- **XMLSocket.connect returns false** — DONE. Fixes 4 Gnash tests: XMLSocket-v5/v6/v7/v8.

### Gnash: Color fixes (2026-03-27)

- **Color target toString() resolution** — DONE. Color methods now call toString() on object targets at each invocation. Fixes Color-v5.
- **Dynamic MC color transform** — DONE. Added cx_* fields to MovieClip struct for createEmptyMovieClip MCs. Fixes Color-v5/v7/v8.
- **_alpha / Color transform dual quantization** — DONE. _alpha getter uses roundf; cx_aa uses integer truncation (setTransform path). Fixes Color-v7/v8. Color-v6 improved to 97.6% (4 remaining: typeof(c)=='undefined').

### AVM1: Image test progress (2026-04-01)

- **Alpha blend fix** — Porter-Duff alpha blend factor corrected (SrcAlpha → One). Fixes `color` image test (30000 outlier channels → 0, max diff 48 → 1).
- **Stage.width/height init** — Was 0, now FRAME_WIDTH/FRAME_HEIGHT. Fixes Drawing API layout in `movieclip_setmask` (202K → 10K outliers).
- **Headless image test status**: 3 strict pass, 6 tolerance pass (was 12/31 strict + 10/31 tolerance before recompile; many tests had stale generated files).
- **RUNTIME_TRANSFORM_GPU and RUNTIME_CXFORM_GPU plans completed** (both already working, moved to complete/).
- **_global plain property resolution** — GetVariable now finds plain properties on _global in root context. Enables Gnash misc-mtasc AS2 class resolution.

## Per-Suite Docs

### avm1 (Ruffle)
- `avm1/_investigation/CURRENT_STATUS.md` — Current pass rates, plan status, remaining work
- `avm1/_investigation/SESSION_NOTES.md` — Historical session-by-session fix notes
- `avm1/_investigation/FAILING_TESTS_BY_FEATURE.md` — Failures by feature category
- `avm1/_investigation/REMAINING_FAILURES_ANALYSIS.md` — Detailed remaining failure analysis
- `avm1/_investigation/BLOCKER_SUMMARY.md` — Active and resolved blockers
- `avm1/_investigation/ACCEPTED_DIFFS.md` — Tests with permanently unfixable diffs
- `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` — Where we match Flash but not Ruffle

### from_gnash
- `from_gnash/_investigation/CURRENT_STATUS.md` — Pass rates, Phase 1/2/3 work order
- `from_gnash/_investigation/FAILING_TESTS_BY_FEATURE.md` — All 152 failures by root cause / feature
- `from_gnash/_investigation/REMAINING_FAILURES_ANALYSIS.md` — Tiered analysis with effort estimates
- `from_gnash/_investigation/BLOCKER_SUMMARY.md` — Active and resolved blockers

### from_shumway
- `from_shumway/_investigation/CURRENT_STATUS.md` — Flat suite complete (17/17 AVM1), avm1/ at 20/23 (87.0%)
- `from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md` — All actionable items done (9 tests fixed)

## Where to Focus

AVM1 filtered suite is at 100% (zero filtered failures); remaining actionable work is in the Gnash and Shumway suites.

1. **Gnash actionscript.all near-passing** — 22+ tests with <=18 line diffs. `global_proto_decls*` enumeration/ordering, `Number-v5..v8` float-to-string rounding, `Selection-v6/7/8`, `ExternalInterface-v8`. See `from_gnash/_investigation/incomplete/GNASH_NEAR_PASSING_PLAN.md`.
2. **Gnash `misc-mtasc/levels`** — only 1 failure in that sub-suite; needs multi-level SWF loading (`_level5`, `_level87`, `_level99`). See `LEVELS_PLAN.md`.
3. **Gnash `misc-swfmill`** — 1 remaining failure (`jump_to_prev_block`, cross-DoAction backward jump). `tags_after_last_showframe` was fixed this session. See `incomplete/MISC_SWFMILL_PLAN.md` for the consecutive-DoAction concatenation fix plan.
4. **Shumway `avm1/moviecliploader`** — sole remaining filtered failure. One-tick MCL deferral exposes latent getBounds / chained setInterval bugs. See `from_shumway/_investigation/incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md` Part B.
5. **Shumway `fuzz/*`** — 16 fuzzer-generated SWFs in `ignored_tests.txt` after the place-before-define fix; useful only as an occasional edge-case discovery source. Not a focus area.
6. **AVM1 image tests** — 14/31 strict pass, 10/31 tolerance. Remaining need Drawing API anti-aliasing, text layout, dynamic masks, or external media loading. Tracked in `IMAGE_COMPARISON_TESTS.md`.
7. **Gnash `misc-ming.all` / `misc-swfc.all`** — ~76 of ~83 failing tests are actionable via Phase 1 (near-passing) + Phase 2 (mid-rate cluster fixes); only ~7 zero-output tests are blocked on the inlined-Dejagnu DoInitAction architectural issue (Phase 3). See `incomplete/MISC_MING_SWFC_PLAN.md`.
