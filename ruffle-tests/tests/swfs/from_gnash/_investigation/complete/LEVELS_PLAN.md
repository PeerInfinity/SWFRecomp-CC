# levels Plan (gnash/misc-mtasc)
<!-- TESTS: levels -->

Test: `ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/levels/`
Status (local, 2026-04-27): **`ruffle_matched` (effective pass)** — 44/68 lines match Flash output.txt; remaining 20 diffs are a subset of Ruffle's 21 diffs (`our.issubset(ruffle)` true via `ruffle_subset_match`). `output.ruffle.txt` sidecar + `known_failure = true` in `test.toml` triggers the promotion.

Plan **complete**: misc-mtasc.all suite expected to move 8/9 → 9/9 (100%) once CI re-runs.

## Session progress (2026-04-27, pending CI)

Three additional fixes on top of the earlier 2026-04-19 work (which had reduced our diff to "6 blocker lines":
25, 35, 38, 44, 50, 60).

1. **Lines 35 / 38 / 60 — `typeof(_level5)` returned "object", expected "movieclip".**
   `getOrCreateLevel()` (`SWFModernRuntime/src/actionmodern/action.c`) HCALLOCs a
   fresh MovieClip and zero-initializes `ng_textfield_idx`. The macro
   `MC_IS_TEXTFIELD(mc) ((mc)->ng_textfield_idx >= 0 || ...)` then returned true
   for level MCs (because `0 >= 0`), so `actionTypeof`'s textfield gate at
   ~line 35095 reported "object" for SWF6+. Fixed by stamping
   `mc->ng_textfield_idx = -1` in `getOrCreateLevel`, matching the convention
   used by every other dynamic-MC creation site (createEmptyMovieClip,
   duplicateMovieClip, etc.).

2. **Lines 44 / 50 — `level5ref._name` / `level99ref._name` returned the level
   path, expected empty string.** Flash semantics: any MC that is the root of a
   loaded level (whether `_root` or `_levelN`) has an empty `_name` even though
   `mc->name` continues to hold "_levelN" for toString / target paths. Added
   `isLevelRootMC(mc)` helper that checks against `&root_movieclip` and
   `g_levels[1..MAX_LEVELS]`, and gated the four `_name` resolution sites in
   `actionGetVariable` (scope-MC builtin path + tellTarget context builtin path
   + last-resort MC member dispatch) and `actionGetMember` (MOVIECLIP receiver
   property handler) on it.

3. **Line 25 — `eval("/ch")` returned undefined inside `_level99`.**
   `resolveFlashPathToMC` hard-coded the leading-`/` jump to `&root_movieclip`,
   meaning a slash-prefixed path inside level99 fell back to level0 (where no
   `ch` exists). Fixed by walking `start_mc->parent` to its topmost ancestor
   for the `/` reset, so "/ch" inside `_level99` resolves to `_level99.ch`.
   This matches Ruffle's `start_clip()` semantics for absolute slash paths.

After these fixes the test promotes to `ruffle_matched`:
- Our diff vs `output.txt`: 20 lines (5, 18, 21, 37, 40, 41, 42, 43, 47, 48,
  49, 56, 57, 58, 59, 61, 62, 65, 66 + the 65/66 totals lines).
- Ruffle's diff vs `output.txt`: 21 lines (same indices plus 39 and 46 where
  Ruffle fails but we pass).
- Subset check: ours ⊆ ruffle ✓.

## Verification

`python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all --test=levels --diff --verbose`
prints `RUFFLE_MATCHED`. Effective-pass total for misc-mtasc.all expected to
move from 8/9 (88.9%) to 9/9 (100%) once CI re-runs.

A 12-test AVM1 spot battery covering levels-related code (loadmovie,
loadmovienum, loadmovie_method, loadmovie_replace_root, unloadmovie,
path_string, string_paths_basic, tell_target_invalid,
tell_target_invalid_swf6, removed_target_clip_scope, swf5_to_6_cross_call,
swf5_no_closure) was run to look for regressions in the touched paths
(`isLevelRootMC` `_name` gates, `_name` MC builtin, slash-prefixed
`resolveFlashPathToMC`).

## Earlier session progress (2026-04-19, in source)

Fixed five distinct issues in `SWFModernRuntime/src/actionmodern/action.c`:

1. **`_level5._depth` returns 0, should be -16379.** `getOrCreateLevel()` was
   HCALLOC-ing the synthetic level MC without stamping `depth`. Added
   `mc->depth = level_num - 16384;`.

2. **`_level5` toString returns `_level0._level5`, should be `_level5`.** The
   MC→string path at `actionToString` (and the removed-MC fallback) had a
   catch-all `snprintf(..., "_level0.%s", ...)` that didn't recognize
   level-root targets. Added an `else if (strncmp(tgt, "_level", 6) == 0)`
   branch that copies the target as-is while slash-to-dot converting any
   child segments. Same branch added to the trace-print path.

3. **`_level87`/`_level99` never load.** `MAX_LEVELS` was 16; test uses level
   IDs 87 and 99. Bumped to 128.

4. **Level load order.** Added a stable insertion-sort in
   `actionFirePendingDirectLoads` that reorders `is_level=1` entries by
   `mc->depth` (== `level_num - 16384`) ascending so lower levels run their
   init scripts first.

5. **Dot-path resolution for `_levelN.child`.** `getMovieClipByTarget()` only
   matched `_level0.` / `_root.` prefixes for dot-path descent. Added a
   pre-step that, when the `_levelN` path has a dot after the digits, uses
   `g_levels[N]` as the dot-path root.

## Related

- AVM1 `complete/LOADMOVIE_PLAN.md` covers `loadMovieNum` + `_level` on the
  AVM1 suite (32/35 passing).
- `ruffle_matched` promotion mechanism: `complete/RUFFLE_KNOWN_FAILURE_HANDLING_PLAN.md`.
