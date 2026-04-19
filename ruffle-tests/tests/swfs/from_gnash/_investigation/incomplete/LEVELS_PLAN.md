# levels Plan (gnash/misc-mtasc)
<!-- TESTS: levels -->

Test: `ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/levels/`
Status (local, 2026-04-19): `output_mismatch`, ~42/68 matching lines. Test has `known_failure = true` with `output.ruffle.txt` sidecar. Our diffs vs Flash (25) are not yet ⊆ Ruffle's diffs vs Flash (21); **6 blocking lines** remain.

## Session progress (2026-04-19, not yet in CI)

Fixed three distinct issues in `SWFModernRuntime/src/actionmodern/action.c`:

1. **Cluster A — `_level5._depth` returns 0, should be -16379.** `getOrCreateLevel()` was HCALLOC-ing the synthetic level MC without stamping `depth`. Added `mc->depth = level_num - 16384;`. Flash semantics match our existing `root_movieclip.depth = -16384`.

2. **Cluster A — `_level5` toString returns `_level0._level5`, should be `_level5`.** The MC→string path at `actionToString` (and the removed-MC fallback) had a catch-all `snprintf(..., "_level0.%s", ...)` that didn't recognize level-root targets. Added an `else if (strncmp(tgt, "_level", 6) == 0)` branch that copies the target as-is while slash-to-dot converting any child segments (so a child of level99 with target `_level99/ch` renders as `_level99.ch`). Same branch added to the trace-print path.

3. **Cluster B — `_level87`/`_level99` never load.** `MAX_LEVELS` was 16; test uses level IDs 87 and 99. Bumped to 128. (Both sites — forward-decl and primary — updated.)

4. **Cluster B — level load order.** After MAX_LEVELS bump, level99 init ran before level87 because `g_pending_direct_loads` is FIFO and level5.swf happens to call `loadMovieNum("level99.swf", 99)` before `loadMovieNum("level87.swf", 87)`. Flash and Ruffle run levels in ascending level-number order. Added a stable insertion-sort in `actionFirePendingDirectLoads` that reorders `is_level=1` entries by `mc->depth` (== `level_num - 16384`) ascending.

5. **Dot-path resolution for `_levelN.child`.** `getMovieClipByTarget()` only matched `_level0.` / `_root.` prefixes for dot-path descent; `_level99.ch` fell through to NULL. Added a pre-step that, when the `_levelN` path has a dot after the digits, uses `g_levels[N]` as the dot-path root.

Verified no regressions on: avm1 `loadmovie`, `loadmovienum`, `loadmovie_method`, `loadmovie_replace_root`, `unloadmovie`, `path_string`, `string_paths_basic`, `define_local_with_paths`, `removed_target_clip_scope`, `tell_target_invalid`, `tell_target_invalid_swf6`.

## Remaining blockers (6 diff lines, all in level99 execution)

After the five fixes above, line-by-line diff vs Flash `output.txt`:
- our diffs: 25 lines
- Ruffle diffs: 21 lines
- 6 of our diffs are not in Ruffle's diff set, so subset-check fails (no `ruffle_matched` promotion):

| Expected line | Flash | Our output | Notes |
|---|---|---|---|
| 25 (level99.as:58) | `PASSED: _level99.ch == _level99.ch` | `FAILED: expected: "_level99.ch", obtained: ""` | `_level99.ch` MC not findable; toString returns "" because type is UNDEFINED and SWF<7 stringifies undefined to "". Likely root cause: synthetic level MCs have `display_obj=NULL`, so `ng_findChildEntryDepth` (which walks the root display_list for the parent's named entry) returns SIZE_MAX. Level5 works because level5.as:79 uses `_target` (slash format, no MC lookup), not toString. |
| 35 (level99.as:83) | `PASSED: movieclip == movieclip` | `FAILED: expected: "movieclip", obtained: "object"` | `typeof` returning "object" for something Ruffle/Flash report as "movieclip". Likely a duplicated/created MC whose type tag isn't set to MOVIECLIP. |
| 38 (level99.as:88) | `PASSED: movieclip == movieclip` | `FAILED: expected: "movieclip", obtained: "object"` | Same typeof issue. |
| 44 (level99.as:95) | `PASSED:  ==  ` (both empty) | `FAILED: expected: "", obtained: "_level5"` | Expected: a removed/orphaned MC toString-ing to empty. We retain `_level5` as the toString. Likely a removed/dead MC lookup that should return "" but doesn't. |
| 50 (level99.as:105) | `PASSED:  ==  ` (both empty) | `FAILED: expected: "", obtained: "_level99"` | Same class of issue as line 44, but for `_level99`. |
| 60 (level99.as:125) | `PASSED: movieclip == movieclip` | `FAILED: expected: "movieclip", obtained: "object"` | Same typeof "object" vs "movieclip" as lines 35/38. |

Lines 35/38/60 are likely the same underlying bug (typeof classification of a specific kind of MC-like value). Lines 25 might be fixable by giving synthetic level MCs a minimal `display_obj` / `sprite_display_list` so `ng_findChildEntryDepth` works — or by adding a level-aware fallback in `actionGetMember` when `mc->display_obj == NULL` but children exist in `child_mc_cache` with `parent == mc`. Lines 44/50 need targeted investigation of how `dupSprite`/dead-MC cleanup interacts with level roots.

## Suggested next steps

1. Fix `actionGetMember` on a level-root MC with `display_obj == NULL`: fall through to a `child_mc_cache` scan filtered by `parent == mc`. Should fix line 25.
2. Investigate `typeof` for lines 35/38/60 together — find the code path that creates the value the test is inspecting and ensure the type tag is `ACTION_STACK_VALUE_MOVIECLIP`, not `ACTION_STACK_VALUE_OBJECT`. Probably related to `attachMovie`/`duplicateMovieClip` output in the cross-level case.
3. For lines 44/50, read level99.as:95/:105 context (via SWF disassembly) to learn what the test is asserting is empty. Likely it's something like `removeMovieClip(x); check_equals(x + "", "")` and our MC isn't being marked as removed.

## Related

- Existing AVM1 `complete/LOADMOVIE_PLAN.md` covers `loadMovieNum` + `_level` on the AVM1 suite. The core loadMovie path works (32/35 AVM1 loadMovie tests pass). This Gnash test exposes deeper edge cases (levels >= 16, load ordering, level-to-level child lookup, typeof on cross-level MCs).
- `ruffle_matched` promotion mechanism: see `complete/RUFFLE_KNOWN_FAILURE_HANDLING_PLAN.md`. Once the 6 blocking diffs are resolved, `verify_output.py` auto-promotes.
