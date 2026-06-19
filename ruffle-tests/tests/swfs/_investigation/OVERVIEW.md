# Test Suite Overview

Cross-suite summary of all Ruffle-derived test suites. Each suite has its own `_investigation/` directory with detailed status docs.

Last updated: 2026-06-19 — **the `avm1` suite has grown to 701 tests** (was 654
in the snapshots below) as `download_tests.sh` syncs fresh from upstream master.
The new tests added real failures the per-suite tables below do **not** yet
reflect; the "100% filtered" claim for avm1 is stale. As of CI `1bef9e7b1`, avm1
is **635/656 (96.8%) effective filtered** with 21 non-ignored filtered failures,
all triaged in `avm1/_investigation/NEW_UPSTREAM_AVM1_TRIAGE.md`. This session
fixed the four `watch_special_recursion_*` SEGFAULTS (2 → ruffle_matched, 2 →
clean mismatch) and ignored the two `geturl_*_normalize` Ruffle-navigator-tracing
tests. The other suites' totals below are still current.

Last updated: 2026-05-19 — planning sweep. Every non-ignored filtered failure across the four Gnash sub-suites is now either passing/RM or covered by a dedicated `*_PLAN.md` in `from_gnash/_investigation/incomplete/`. 27 new plans landed this session; `SUBTESTS_NEWLY_VISIBLE_TRIAGE` graduated to `complete/`; six entries in `REMAINING_TAIL_TRIAGE` replaced with one-line cross-links per its own promotion convention. See `from_gnash/_investigation/CURRENT_STATUS.md` § "Missing dedicated plans" for the full per-test table.

Last updated: 2026-05-15 (CI `eb8206f8` no-graphics, run `25896064893` — first run after SUBTESTS_HARNESS shipped. 66 previously-undiscoverable tests with `[subtests]`/no `output.txt` are now visible (53 in actionscript.all, 8 in misc-ming.all, 3 in misc-swfc.all, 2 in misc-swfmill.all). Newly-added: 2 raw pass (`Global-v5`, `misc-swfmill.all/trace-as2/arguments`), 8 ruffle_matched (`ops-v5/v6/v7`, `setProperty-v5/v6/v7/v8`, `BitmapDataDraw`), 45 output_mismatch. Three regressions: `avm1/placeobject_occupied_depth` (pass → output_mismatch), `misc-ming.all/loop/loop_test10` (RM 5/28 → mismatch 1/28), `misc-ming.all/register_class/RegisterClassTest4` (17/42 → 7/42 lines). Triage of the new output_mismatch tests in `from_gnash/_investigation/incomplete/SUBTESTS_NEWLY_VISIBLE_TRIAGE.md` (now closed, moved to `complete/`).)

## Suite Summary

"Effective pass" = raw pass + `ruffle_matched` (diffs ⊆ Ruffle's diffs against Flash; auto-promoted when upstream has `known_failure=true` + `output.ruffle.txt`).

> **Policy — match Flash, not Ruffle.** `ruffle_matched` recognizes tests whose
> residual diffs are Flash limitations Ruffle *also* has; it is NOT a goal to
> chase by deliberately changing behavior to match Ruffle. When Ruffle and Flash
> genuinely **conflict** (both behave, they disagree), match **Flash**, document
> the difference in the suite's accepted-diffs / Ruffle-vs-Flash doc, and add the
> test to that suite's `ignored_tests.txt`. Do not adopt a Ruffle-matching
> implementation that regresses a line we already get Flash-correct. (Example:
> `from_gnash/actionscript.all/array-v5` sort-mutating-comparator UB — see
> `from_gnash/_investigation/ACCEPTED_DIFFS.md` Category 1.)

Numbers below are from CI `eb8206f8` (no-graphics, 2026-05-15). The four Gnash sub-suites grew this run because SUBTESTS_HARNESS now discovers tests that ship only `[subtests]`/`output.fpN.txt` — previous totals (190 / 102 / 16 / 18) silently omitted those.

| Suite | Tests | Pass | RM | Effective | Effective Rate | Filtered Rate | Notes |
|-------|-------|------|----|-----------| ---------------|---------------|-------|
| [avm1](../avm1/_investigation/CURRENT_STATUS.md) | 654 | 604 | 11 | 615 | 94.0% | **99.2%** (608/613) | 41 ignored. `placeobject_occupied_depth` regressed (pass → output_mismatch) this CI; needs root-cause. |
| [from_gnash/actionscript.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 243 | 127 | 70 | 197 | **81.1%** | — | +53 tests (SUBTESTS_HARNESS). Effective rate dropped from 99.5% denominator-growth, raw pass +1 (`Global-v5`). 45 newly-visible output_mismatch entries pending triage. |
| [from_gnash/misc-mtasc.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 9 | 7 | 2 | 9 | **100.0%** | — | All effective pass. Unchanged this CI. |
| [from_gnash/misc-swfmill.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 20 | 18 | 1 | 19 | **95.0%** | — | +2 tests (SUBTESTS_HARNESS): `trace-as2/arguments` → PASS, `registers` → output_mismatch (30/36). |
| [from_gnash/misc-ming.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 110 | 66 | 24 | 90 | 81.8% | **83.3%** (90/108) | +8 tests (SUBTESTS_HARNESS) including `BitmapDataDraw` (RM). `loop/loop_test10` regressed RM → output_mismatch; `RegisterClassTest4` dropped 17/42 → 7/42 lines (still mismatch). |
| [from_gnash/misc-swfc.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 19 | 8 | 6 | 14 | 73.7% | **77.8%** (14/18) | +3 tests (SUBTESTS_HARNESS): `matrix_accuracy_test1`, `movieclip_destruction_test3`, `action_execution_order_test12` (all output_mismatch). |
| [from_shumway](../from_shumway/_investigation/CURRENT_STATUS.md) (flat) | 92 | 73 | 3 | 76 | 82.6% | **100.0%** (76/76) | Unchanged this CI. 16 fuzz tests still MISMATCH (in `ignored_tests.txt`). |
| [from_shumway/avm1](../from_shumway/_investigation/CURRENT_STATUS.md) | 47 | 46 | 1 | 47 | **100.0%** | **100.0%** (45/45) | 2 ignored. Quietly added 1 RM since prior snapshot. |
| **SWFRecomp/tests** (old suite) | 158+59 | all trace pass | — | — | **100%** | — | Hand-written opcode tests. CI only. |

## Progress Since 2026-05-14 (CI `eb8206f8`, no-graphics, run `25896064893`) — SUBTESTS_HARNESS shipped, 66 newly-visible tests

- **SUBTESTS_HARNESS (commit `39b797ac`, plan `avm1/_investigation/complete/SUBTESTS_HARNESS_PLAN.md`).** `verify_output.py` now resolves the expected-output filename per-test via `resolve_expected_filename()`: honor `--expected-suffix` first, then `output.txt`, then `[subtests]` table's highest `player_options.version` variant. 66 tests that ship only `output.fpN.txt` (53 actionscript.all, 8 misc-ming.all, 3 misc-swfc.all, 2 misc-swfmill.all) were previously **invisible to discovery** — not "failing", not "errored", just absent from results. They now run and are counted.

- **Newly-discovered status mix.** 2 raw PASS (`Global-v5`, `misc-swfmill.all/trace-as2/arguments`). 8 ruffle_matched (`ops-v5/v6/v7`, `setProperty-v5/v6/v7/v8`, `BitmapDataDraw`). 45 output_mismatch. 11 ruffle_matched and pass entries are an immediate win; the 45 output_mismatch entries are triaged by line-match tier in `from_gnash/_investigation/incomplete/SUBTESTS_NEWLY_VISIBLE_TRIAGE.md`.

- **Three regressions (all unrelated to SUBTESTS_HARNESS).**
  1. `avm1/placeobject_occupied_depth` — pass → output_mismatch (6/6 → 0/6). New in this CI. Needs root-cause investigation.
  2. `misc-ming.all/loop/loop_test10` — ruffle_matched (5/28) → output_mismatch (1/28). Likely interaction with the same-frame Remove+Place fix landed in `f8e172e9`; that fix promoted loop_test10 to RM at the time.
  3. `misc-ming.all/register_class/RegisterClassTest4` — output_mismatch 17/42 → 7/42 (10-line drop, still mismatch).

- **Quiet wins among already-discovered tests.** `path_format_test` (0/27 → 16/27 lines, stays RM), `place_object_test2` (0/19 → 14/19, RM), `place_object_test` (0/12 → 6/12, RM) — line-match grew substantially despite static status, likely benefiting from the same upstream textfield-variable-binding plan that landed on 2026-05-13.

- **What changed in the per-suite "Tests" totals.** Previously-published totals were 190 (actionscript.all), 102 (misc-ming.all), 16 (misc-swfc.all), 18 (misc-swfmill.all). New totals are 243 / 110 / 19 / 20. Effective rates *dropped numerically* because the denominator grew faster than the raw passes did — this is denominator growth, not regression. Raw passes went up (Gnash +2 across the four sub-suites; effective +9). Per-feature failure tables (`from_gnash/_investigation/FAILING_TESTS_BY_FEATURE.md` + `_FILTERED.md`) were regenerated this CI; many `(1 failing / 1 total)` entries that reflected discovery limits now show their full version cohort (e.g. MovieClip-v6/v7/v8, TextField-v6/v7/v8, ops-v5/v6/v7, Date-v5..v8 — all newly present).

## Progress Since 2026-05-08 (pending CI) — `array-v5` ARRAY-typed __proto__ chain follow

- **`array-v5` (Gnash actionscript.all) → 535/560 → 536/560 (+1 line, -1 mismatched).** Two paired changes in `SWFModernRuntime/src/actionmodern/action.c`:
  1. `resolveProtoVar` now also handles `ACTION_STACK_VALUE_ARRAY` by returning `arr->props` — the array's string-keyed property bag whose own `__proto__` points at `Array.prototype`. Used by `walkProtoChain`, `getPropertyWithPrototype`, and `findPropertyStructWithPrototype`.
  2. The inline OBJECT-receiver method-lookup walk in `actionCallMethod` (line ~56235) does the same ARRAY-aware step inline — accepts both OBJECT and ARRAY-typed `__proto__`, switching to `arr->props` before continuing.

- **Trigger.** `function X() {}; X.prototype = new Array(); o = new X(); o.push("Array data"); ret = o.pop();` (array.as line 1701-1710). When a function's prototype is assigned a non-object value (an Array instance), `actionNewObject` stores the ARRAY-typed value verbatim on the new instance's `__proto__`. The OBJECT-receiver method-lookup loop previously broke the chain walk at the ARRAY-typed proto, so `push`/`pop` were never resolved through `Array.prototype` and `o.pop()` returned undefined. Now resolves via `o → X.prototype (Array instance) → arr->props → Array.prototype` and the existing `objectToTempArray` / `callArrayMethod` / `syncArrayToObject` path mutates correctly.

- **No regressions** across a 31-test AVM1 array/lifecycle/super/scope battery, 19-test follow-up battery (closure_scope, register_and_init_order, set_variable_scope, on_construct, register_class_return_value, parse_int, typeof, enumerate, function_as_function, coerce_to_object_monkeypatch, object_resolve, string_paths_eval2, string_coercion, etc.), 11-test gnash actionscript.all prototype-heavy battery (Boolean-v5, Inheritance-v5/v6/v7/v8, Number-v5, case-v6, delete-v5/v6, enumerate-v6/v7), and 4-test Shumway `duplicateMovieClip` battery — all 65 effective passes preserved.

## Progress Since 2026-05-08 (CI `f8e172e9`, run `25583473693`) — `array-v5` shift / sync / __resolve

- **`array-v5` (Gnash actionscript.all) → 528/560 → 535/560 (+7 lines, -7 mismatched).** Three fixes in `SWFModernRuntime/src/actionmodern/action.c`:
  1. `callArrayMethod` shift now honors **DontDelete on the target index** (CONFIGURABLE-cleared in `arr->props`). Skips the element-copy and the metadata-reset for protected slots. Matches Flash for `ASSetPropFlags(a, "0", 7, 0); a.shift()` — `a[0]` stays `'zero'` (line 1416). Note: WRITABLE/ReadOnly is intentionally NOT honored here, because Flash `ASSetPropFlags(a, "0", 4, 0)` (ReadOnly only) DOES allow shift to overwrite (line 1444), and matching that requires ignoring WRITABLE during the shift's element move.
  2. `syncArrayToObject` (the plain-Object dispatch bridge for `Array.prototype.X.call(plainObj)`) skips HOLE-typed temp entries during writeback so missing keys don't get materialized as new properties on the target. Stops `pop` from creating a spurious `"0"` property when `objectToTempArray` read missing keys as HOLE (line 1537).
  3. `actionGetMember` ARRAY branch fires `findResolveMethod` / `invokeResolveFunction` on `arr->props` before returning undefined, mirroring the OBJECT path. Fixes `t = []; t.__resolve = function(a){...}; t[3]` returning `'resolved 3'` plus the four `rs == 1` counter checks that follow it (lines 1653, 1654, 1665, 1669, 1671).

- **No regressions** across all 8 suites. AVM1 unchanged (605 / 614 effective, 100% filtered); other Gnash sub-suites unchanged; both Shumway sub-suites unchanged. Test stays `output_mismatch` (residual 25 lines are mostly sort/sortOn algorithm-dependent ordering and Flash's plain-Object Array.prototype.X.call insertion-order semantics) — not yet promotable to `ruffle_matched` because our diff still includes 14 lines outside Ruffle's diff set against expected.

## Progress Since 2026-05-08 (CI `e0d15089`, run `25578374215`) — Part C: loadee per-tick advance

- **`from_shumway/avm1/moviecliploader` → 6/7 → PASS (7/7).** Implements `complete/SHUMWAY_AVM1_SUBTREES_PLAN.md` Part C with one change in `SWFModernRuntime/src/actionmodern/action.c::actionFirePendingLoadInits` Phase 2: after running `entry->frame_funcs[0]` in the target MC's context, register the loadee for per-tick frame advancement via `actionRegisterLevelAdvance(target, entry)` when `entry->frame_count > 1`. Reuses the existing per-tick mechanism that loadMovieNum (level loads) uses — `actionAdvancePlayingLevels` (called from `swf_core.c` / `swf_headless.c` top-of-tick) swaps to the loadee's display_list + transform_data + SWF version, runs `frame_funcs[current_frame]`, increments `current_frame`, drops the entry once `current_frame >= frame_count`. The "Level" naming is historical — it's a generic per-tick advance for any (MC, entry) pair; loadMovieNum was simply its first caller.

- **No double-advance with `advance_sprite_frames`.** The MCL target MC's `sprite_frame_funcs` either are NULL (createEmptyMovieClip) or point at the original placeholder character — never at the loadee's `frame_funcs`. `advance_sprite_frames` calls `ch->sprite_frame_funcs[frame]` (the placeholder), not the loaded entry's frame_funcs. So registering with `actionRegisterLevelAdvance` doesn't conflict and no frame fires twice.

- **Loop-keepalive already in place.** `hasPlayingLevels()` is already checked by both `swf_core.c:1062` (post-last-frame `quit_swf` exit guard) and `swf_core.c:1388` (stopped-root exit) to keep the main loop alive. So deferred loadee frames continue to fire on subsequent ticks even after the loader has called `stop()` (as `moviecliploader` does in frame 1).

- **Regression batteries (all green).** 26-test extended AVM1 MCL/loadMovie battery (loadmovie*, loadmovienum*, mcl_*, unloadmovie*, string_paths_eval2, moviecliploader_flashvars — 26/26 PASS). 4-test Gnash MovieClipLoader-v5..v8 (4/4 effective: 2 PASS + 2 RM, unchanged). 21-test AVM1 lifecycle/scope/timeline battery (mcl_replace_root_swf7_to_swf{5,6}, on_construct, execution_order2/3, goto_rewind3, as2_super_and_this_v6, register_class_return_value, watch, movieclip_state_values/default_state, swf5_to_6_cross_call, set_interval, clone_sprite_edittext, tell_target, path_string, function_base_clip, goto_methods, movieclip_setmask, textsnapshot_available_text, placeobject_occupied_depth — 21/21 effective: 19 PASS + 2 RM).

- **Combined effect (Part B + Part C).** Shumway flat suite: filtered effective 75/76 → **76/76 (100%)**, raw 72 → 73 PASS (78.3% → 79.3%). Shumway avm1 sub-tree: raw 45 → 46 PASS (95.7% → 97.9%). Filtered remains 45/45 (100%) since `moviecliploader` is in `from_shumway/avm1/ignored_tests.txt`. Zero regressions across all 7 other suites (avm1, gnash actionscript.all, misc-mtasc.all, misc-swfmill.all, misc-ming.all, misc-swfc.all, from_shumway/timeline) — all unchanged from previous CI.

## Progress Since 2026-05-08 (CI `0502d0ec` + `84a147bd`) — conditional MCL one-tick deferral

- **`from_shumway/avm1/moviecliploader` → 1/7 → 6/7 lines (+5, mismatched 8 → 3).** Implements `SHUMWAY_AVM1_SUBTREES_PLAN.md` Part B with a refinement that gates the deferral conditionally so it doesn't break tests with chained-timer / stopped-root patterns. Test stays `output_mismatch` because line 7 ("loadee frame 2") requires separate Phase 2 frame-advancement work — `actionFirePendingLoadInits` Phase 2 currently runs the loadee's `frame_funcs[0]` once but doesn't register the loadee MC for per-tick `advance_sprite_frames` (followup, see plan).

- **Implementation.** `SWFModernRuntime/src/actionmodern/action.c` splits `g_pending_mcl_loads` into `_this_tick` and `_next_tick` arrays; `builtin_mcl_loadClip` decides bucket via `is_playing && (current_frame + 1 < g_frame_count)` — defer when the loader is playing and has more frames coming, else fire same-tick. New `actionPromotePendingMCLLoads()` moves `_next_tick` → `_this_tick` (FIFO preserved), called from the top-of-tick hook in `swf_core.c` / `swf_headless.c`. `actionFirePendingLoadInits` drains `_this_tick`. The same files add a "last-tick MCL drain" (promote+drain when `tick_count >= max_ticks` and `_next_tick` non-empty) and `g_pending_mcl_load_count > 0` checks in the past-last-frame and stopped-root exit guards so deferred loads always get a tick to drain. `tag.c` `tagShowFrame` calls `actionPromotePendingMCLLoads` first when `!is_playing` (covers the case where `stop()` ran in the same frame_func that called `loadClip` — no "next frame's DoAction" to defer past).

- **Two-step landing.** First commit (`0502d0ec`) introduced the deferral and the local 25-test MCL battery passed clean, but CI surfaced a PASS → output_mismatch regression on `avm1/string_paths_eval2` (3-frame loader that calls `stop()` after `loadClip`; the deferral pushed an `onLoadComplete`-listener-scheduled `setInterval(300ms)` past `num_frames=5`). Follow-up commit (`84a147bd`) added the `tagShowFrame` promote-on-stop path + stopped-root exit guard — restored `string_paths_eval2` to PASS while keeping the moviecliploader gain.

- **Why not a uniform deferral.** `loadmovie_var_persistence` uses a `setTimeout`-driven chain of `loadClip` calls; each chain step adds a 1-tick delay if the deferral is unconditional, and the chain runs out of `num_ticks=6`. The conditional gate (`current_frame + 1 < g_frame_count`) keeps 1-frame-loader and stopped-loader cases firing same-tick, matching pre-deferral behaviour those tests rely on.

- **Regressions battery (all green).** 27-test extended AVM1 MCL/loadMovie battery (loadmovie*, loadmovienum*, mcl_*, unloadmovie*, string_paths_eval2, string_paths_reference_launder — 26/26 effective; the lone failure is the pre-existing `string_paths_reference_launder` regression in `ignored_tests.txt`). 4-test Gnash MovieClipLoader-v5..v8 (4/4 effective: 2 PASS + 2 RM, unchanged). 19-test AVM1 lifecycle/scope/timeline battery (19/19 PASS).

## Progress Since 2026-05-08 (CI `4c7febd5` + back-to-back `068b46d8` at the same SHA) — `array-v5` ASSetPropFlags ARRAY semantics + RNG determinism confirmed

- **`array-v5` (Gnash actionscript.all) → 520/560 → 528/560 (+8 lines, -8 mismatched).** Three changes in `SWFModernRuntime/src/actionmodern/action.c`:
  1. `actionSetMember` ARRAY index-write path now consults `arr->props["<idx>"]` and skips the write when `WRITABLE` is cleared (mirrors the existing `actionDelete` CONFIGURABLE check and the length-truncation logic in the same function). Without this, `ASSetPropFlags(a, "0", 4, 0); a[0] = X` would silently overwrite the protected slot.
  2. `Array.prototype.shift` (in `callArrayMethod`): (a) resets ASSetPropFlags metadata on overwritten slots so subsequent userland writes succeed (Flash semantics: "flag was lost" once shift moves a different value into the slot); (b) preserves the deleted last element's value into `arr->props` when the slot is marked DontDelete (CONFIGURABLE cleared), so `a[length-1]` continues to read its original value through the props fallback after length is decremented.
  3. `syncArrayToObject` (the temp-array bridge for `Array.prototype.X.call(plainObj)` on plain Objects) gained an `update_length` parameter. `shift`, `pop`, and `unshift` now pass `update_length=0` because Ruffle gates `set_length` on `if let NativeObject::Array(_) = this.native()` — on a plain Object `o.length` keeps its user-set value (test expects `o.length == 6` after `o.shift()` on a fakeArray-shaped object).

- **CI back-to-back at the same SHA (`068b46d8` → `29c9b767`) produced byte-identical results across all 8 suites** — confirms full determinism via `MOCK_DATE_TIME`. `verify_output.py` defines `-DMOCK_DATE_TIME=<ms>LL` on every gcc invocation (default `981152406000` = 2001-02-03 04:05:06 NPT, matching Ruffle's `--deterministic` mode; per-test override via `mock_date_time` in `test.toml`). `math.c::GenerateRandomNumber` seeds the avmplus RNG with `MOCK_DATE_TIME * 1000` µs on first use, and `date.c` uses the same macro for `Date.getTime()` / `Date.UTC()`. The earlier "fluctuates by ~4 lines between runs" disclaimer in `ARRAY_V5_PLAN.md` was stale — removed.

- **No regressions** across all suites (avm1, misc-ming.all, misc-mtasc.all, misc-swfc.all, misc-swfmill.all, from_shumway, from_shumway/avm1 — all unchanged). 16-test AVM1 array battery (16/16 PASS), 13-test Gnash actionscript.all battery (13/13 effective), AVM1 assetnative/loadvars_tostring/add_property/watch/object_resolve/coerce_to_object_monkeypatch/register_class_return_value (7/7 PASS).

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

AVM1 filtered suite is at 100% (zero filtered failures). Shumway flat suite reached 100% filtered effective (76/76) and the avm1 sub-tree reached 100% raw effective (47/47, 100% filtered) after Part C landed (CI run `25578374215`). Remaining actionable work is mostly in the Gnash suites.

1. **Gnash actionscript.all near-passing** — 22+ tests with <=18 line diffs. `global_proto_decls*` enumeration/ordering, `Number-v5..v8` float-to-string rounding, `Selection-v6/7/8`, `ExternalInterface-v8`. See `from_gnash/_investigation/incomplete/GNASH_NEAR_PASSING_PLAN.md`.
2. **Gnash `misc-mtasc/levels`** — only 1 failure in that sub-suite; needs multi-level SWF loading (`_level5`, `_level87`, `_level99`). See `LEVELS_PLAN.md`.
3. **Gnash `misc-swfmill`** — 1 remaining failure (`jump_to_prev_block`, cross-DoAction backward jump). `tags_after_last_showframe` was fixed this session. See `incomplete/MISC_SWFMILL_PLAN.md` for the consecutive-DoAction concatenation fix plan.
4. **Shumway `fuzz/*`** — 16 fuzzer-generated SWFs in `ignored_tests.txt` after the place-before-define fix; useful only as an occasional edge-case discovery source. Not a focus area.
5. **AVM1 image tests** — 14/31 strict pass, 10/31 tolerance. Remaining need Drawing API anti-aliasing, text layout, dynamic masks, or external media loading. Tracked in `IMAGE_COMPARISON_TESTS.md`.
6. **Gnash `misc-ming.all` / `misc-swfc.all`** — ~76 of ~83 failing tests are actionable via Phase 1 (near-passing) + Phase 2 (mid-rate cluster fixes); only ~7 zero-output tests are blocked on the inlined-Dejagnu DoInitAction architectural issue (Phase 3). See `incomplete/MISC_MING_SWFC_PLAN.md`.
