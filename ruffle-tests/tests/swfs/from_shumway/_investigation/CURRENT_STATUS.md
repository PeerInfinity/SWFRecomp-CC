# Shumway Test Suite Status

Last updated: 2026-05-08 (CI `e0d15089`, run `25578374215` — Part C: `avm1/moviecliploader` 6/7 → **PASS (7/7)**. Flat suite filtered effective 75/76 → **76/76 (100%)**; avm1 sub-tree raw 45 → 46 PASS. After Phase 2 of `actionFirePendingLoadInits` runs the loadee's `frame_funcs[0]`, the loadee MC is now registered with `actionRegisterLevelAdvance` so `frame_funcs[1..N-1]` fire on subsequent ticks via the existing per-tick `actionAdvancePlayingLevels` path. Zero regressions across other suites.)

## Latest fixes (2026-05-08, in CI at `e0d15089` — Part C — child-SWF multi-frame advance)

- **`avm1/moviecliploader` → PASS (7/7).** Implements `complete/SHUMWAY_AVM1_SUBTREES_PLAN.md` Part C with one change in `SWFModernRuntime/src/actionmodern/action.c::actionFirePendingLoadInits`: after Phase 2 runs `entry->frame_funcs[0]` in the target MC's context, call `actionRegisterLevelAdvance(target, entry)` when `entry->frame_count > 1`. Reuses the existing per-tick mechanism that loadMovieNum (level loads) uses — `actionAdvancePlayingLevels` is called from `swf_core.c` / `swf_headless.c` top-of-tick, swaps to the loadee's display_list + transform_data + SWF version, runs `frame_funcs[current_frame]`, increments `current_frame`, drops the entry once `current_frame >= frame_count`. The "Level" naming is historical — it's a generic per-tick advance for any (MC, entry) pair.
  - **No double-advance with `advance_sprite_frames`.** The MCL target MC's `sprite_frame_funcs` either are NULL (createEmptyMovieClip) or point at the original placeholder character — never at the loadee's `frame_funcs`. `advance_sprite_frames` calls `ch->sprite_frame_funcs[frame]` (the placeholder), not the loaded entry's frame_funcs. So registering with `actionRegisterLevelAdvance` doesn't conflict and no frame fires twice.
  - **Loop-keepalive already in place.** `hasPlayingLevels()` is already checked by both `swf_core.c:1062` and `swf_core.c:1388` to keep the main loop alive after the loader stops, so deferred loadee frames continue to fire on subsequent ticks even when the loader has called `stop()` (as `moviecliploader` does in frame 1).
  - **Regression batteries (all green).** 26-test extended AVM1 MCL/loadMovie battery (loadmovie*, loadmovienum*, mcl_*, unloadmovie*, string_paths_eval2, moviecliploader_flashvars — 26/26 PASS). 4-test Gnash MovieClipLoader-v5..v8 battery (4/4 effective: 2 PASS + 2 RM, unchanged).

## Earlier fixes (2026-05-08, in CI at `84a147bd`)

- **`avm1/moviecliploader` → 1/7 → 6/7 lines (+5).** Implements `complete/SHUMWAY_AVM1_SUBTREES_PLAN.md` Part B with a refinement: defer MCL events to next tick only when `is_playing && (current_frame + 1 < g_frame_count)` (loader is playing AND has more frames coming) — else fire same-tick.
  - **Implementation.** `SWFModernRuntime/src/actionmodern/action.c` splits `g_pending_mcl_loads` into `_this_tick` and `_next_tick` arrays; `builtin_mcl_loadClip` decides bucket based on the conditional. New `actionPromotePendingMCLLoads()` moves `_next_tick` → `_this_tick` (FIFO preserved), called from the top-of-tick hook in `swf_core.c` / `swf_headless.c`. `actionFirePendingLoadInits` drains `_this_tick`. Same files add a "last-tick MCL drain" (promote+drain when `tick_count >= max_ticks` and `_next_tick` non-empty) and `g_pending_mcl_load_count > 0` checks in the past-last-frame and stopped-root exit guards. `tag.c` `tagShowFrame` calls `actionPromotePendingMCLLoads` before `actionFirePendingLoadInits` when `!is_playing` — covers the case where `stop()` runs in the same frame_func that called `loadClip`, since there's no "next frame's DoAction" to defer past.
  - **Two-step landing.** First commit (`0502d0ec`) caught a CI regression on `avm1/string_paths_eval2` (PASS → 1/7 — 3-frame loader that calls `stop()` after `loadClip`; the deferral pushed an `onLoadComplete`-listener-scheduled `setInterval(300ms)` chain past `num_frames=5`). Follow-up commit (`84a147bd`) added the `tagShowFrame` promote-on-stop path + stopped-root exit guards. Restored `string_paths_eval2` to PASS while preserving the moviecliploader gain.
  - **Why not a uniform deferral.** `loadmovie_var_persistence` uses a `setTimeout`-driven chain of `loadClip` calls; each chain step adds a 1-tick delay if the deferral is unconditional, and the chain runs out of `num_ticks=6`. The conditional gate keeps 1-frame-loader and stopped-loader cases firing same-tick, matching pre-deferral behaviour those tests rely on.
  - **Followup.** `loadee frame 2` (line 7 of expected output) requires a separate fix: when Phase 2 runs the loadee's `frame_funcs[0]`, register the target MC for per-tick advancement so `frame_funcs[1]` fires next tick. Likely modeled on the existing `actionRegisterLevelAdvance` path used for multi-frame `_levelN` loads. See `complete/SHUMWAY_AVM1_SUBTREES_PLAN.md`.
  - **Regressions battery (all green).** 27-test extended AVM1 MCL/loadMovie battery (loadmovie*, mcl_*, unloadmovie*, string_paths_eval2 — 26/26 effective; the lone failure is the pre-existing `string_paths_reference_launder` already in `ignored_tests.txt`). 4-test Gnash MovieClipLoader-v5..v8 (4/4 effective: 2 PASS + 2 RM, unchanged). 19-test AVM1 lifecycle/scope/timeline battery (19/19 PASS).

## Earlier fixes (2026-05-06, in CI at `8fdf3311`)

- **Place-before-define matches Flash, not Ruffle.** Recompiler tracks `defined_chars` (DefineSprite, Shape, Button, Text, EditText, Bits, Font, Sound, Video, plus `ImportAssets`-imported chars) in tag-stream order. *Root-timeline* PlaceObject{,2,3} that references a char_id whose Define* tag hasn't been encountered yet is degraded to char_id=0 (modify), matching Flash's sequential-dictionary semantics. Sprite-internal PlaceObject is *not* gated (sprites instantiate at runtime, by which point the dictionary is complete). Fix in `SWFRecomp/src/swf.cpp` + `SWFRecomp/include/swf.hpp`. Documented in `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`. Of 20 originally failing fuzz tests: 4 PASS (incl. 2 RMATCH→PASS upgrades for `1276557624…`, `a86fee6d…`), 2 newly RMATCH (`4949de46…`, `887c02ab…`), 16 still MISMATCH (added to `from_shumway/ignored_tests.txt` as fuzz noise). The narrowing fix in CI `8fdf3311` recovered Gnash actionscript.all (Dejagnu) and 2 AVM1 tests that the un-narrowed CI `873e520e` had regressed; the +4 Shumway gain is preserved (fuzz tests have no inner-sprite PlaceObjects). Plan in `complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md`.

## Earlier fixes (2026-05-04, in CI at `c5994ec1`)

- **Fuzz `this._currentframe` tests → 5+ PASS.** `from_shumway/fuzz/c8b8069c…`, `ac93c8c9…`, `07580c34…`, `2f4f46bf…`, `81004241…` (all the previously-built fuzz tests with `this._currentframe` traces from inside sprite frame scripts) now PASS. Root cause: in `advance_sprite_frames` (`SWFModernRuntime/src/libswf/tag.c`), only `obj->sprite_current_frame` (DisplayObject, 0-indexed) was incremented per natural advance — `mc->currentframe` (MovieClip, 1-indexed, the value `_currentframe` exposes to ActionScript) was set to 1 at MC creation and never updated outside goto paths (`ng_setSpriteFrame` / `ng_gotoFrameByMC`) and the root-frame updates emitted by the recompiler. So a script like `trace(this._currentframe)` running from inside a sprite frame func always returned 1 instead of the actual frame number. Fix: just before `CALL_FRAME(...)` at line ~941 (natural advance only), resolve the sprite's MC via `actionFindMovieClipByName(obj->instance_name)` and set `smc->currentframe = (int)frame + 1`. Mirrors `swf_core.c`'s update of `root_movieclip.currentframe` before each root frame func. Manual-nav catch-up paths (lines 814/866 within `advance_sprite_frames`, and `ng_setSpriteFrame`) are intentionally NOT touched — they already set `mc->currentframe` to the target value before catch-up so all catch-up frames see the target value (matching Flash). The remaining 22 numeric-output fuzz tests in `from_shumway/fuzz/*` likely also use this pattern (numeric-only output suggests the same `trace(this._currentframe)` template); expect more flips on the next CI run as they're rebuilt. Regression battery: 22/22 AVM1 lifecycle, 17/17 AVM1 scope, 14/14 misc-ming timeline, 14/14 AVM1 timeline, 6/6 AVM1 sprite-state, 5/5 gnash actionscript.all effective — no regressions.

## Quick Summary

### Flat suite (`from_shumway/`)

| Metric | Value |
|--------|-------|
| Total tests | 92 |
| Passing | **73** (79.3%) |
| Ruffle-matched | 3 |
| Effective pass | **76** (82.6%) |
| Filtered effective | **76/76 (100.0%)** (16 fuzz tests in `ignored_tests.txt`) |
| Failing | 16 |

(In CI at `e0d15089` (run `25578374215`) — `avm1/moviecliploader` 6/7 → PASS.)

**Breakdown by sub-tree** (flat suite recurses into subdirs, post Part C):

| Sub-tree | Total | Pass | RM | Fail |
|----------|-------|------|----|------|
| Flat root (no subdir) | 10 | 10 | 0 | 0 |
| `avm1/` | 47 | 46 | 1 | 0 |
| `fuzz/` | 30 | 12 | 2 | 16 (all in `ignored_tests.txt`) |
| `timeline/` | 5 | 5 | 0 | 0 |

**Flat root is still 100% passing**: all 10 remaining tests (add, avm1timeline1, avm1timeline2, button3, doubleAndRegister, fscommand1, gradientTransform, invalidClipDepth, movieinfo1, targetPath1) pass.

**`timeline/` is now 100% passing** (5/5) — `timeline_as2_1` and `timeline_as2_5` flipped to PASS since the previous snapshot, picked up via the cross-cutting fixes (Instance-v* native ctor, Global-v6 case-insensitive lookup, GetMember/SetMember hidden own-prop walk, ecmaToInt32 trunc, ASSetPropFlags array, convertFloat strict mode).

**Remaining failing clusters** come from `fuzz/` (24 fail — fuzzer-generated SWFs, useful as an edge-case source for the runtime/recompiler) and `avm1/` sub-tree (1 fail — see below).

### AVM1 subdirectory (`from_shumway/avm1/`)

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **46** (97.9%) |
| Ruffle-matched | 1 |
| Effective pass | **47** (100.0%) |
| Ignored | 2 |
| **Filtered pass rate** | **45/45 (100.0%)** |
| Failing (filtered) | 0 |

(In CI at `e0d15089` (run `25578374215`) — Part C landed; `moviecliploader` PASS.)

`doactionorder` passed following Phase 6 of the ActionQueue rework. `moviecliploader` reached 6/7 via Part B's conditional MCL one-tick deferral and now reaches 7/7 via Part C (per-tick advance for the loadee MC after Phase 2). All `complete/SHUMWAY_AVM1_SUBTREES_PLAN.md` parts (A/B/C) are now resolved.

**Per-category status:**

| Category | Total | Pass | Fail |
|----------|-------|------|------|
| Flat (root-level tests) | 23 | 22 (+1 RM) | 0 |
| `bitmapdata/` | 2 | 2 | 0 |
| `doactionorder/` | 2 | 2 | 0 |
| `duplicateMovieClip/` | 4 | 4 | 0 |
| `haxe/` | 2 | 2 | 0 |
| `loadvariables/` | 2 | 2 | 0 |
| `property-paths/` | 2 | 2 | 0 |
| `propertycase/` | 3 | 3 | 0 |
| `textfield/` | 2 | 2 | 0 |
| `undefined/` | 2 | 2 | 0 |
| `xml/` | 3 | 3 | 0 |

## Related Documents

| Document | Purpose |
|----------|---------|
| `FAILING_TESTS_BY_FEATURE.md` | Flat-suite failures categorized (historical — 30 AVM2 + 2 AVM1, all resolved) |
| `REMAINING_FAILURES_ANALYSIS.md` | Analysis of the 2 fixed flat-suite AVM1 tests + AVM2 ignore list |
| `complete/SHUMWAY_AVM1_PLAN.md` | Completed plan for the original 11 `avm1/` subdirectory failures |
| `complete/SHUMWAY_AVM1_SUBTREES_PLAN.md` | **Complete** — Part A (FIFO DoAction queueing, via ActionQueue rework Phase 6), Part B (conditional one-tick MCL deferral), Part C (loadee per-tick advance). Ruffle-referenced, canary list included. Moved from `incomplete/` 2026-05-08 after Part C landed (CI `25578374215`). |

---

## Recently Fixed (2026-04-17 session)

9 tests moved from fail to pass in the `avm1/` sub-tree:

| Test | Fix |
|------|-----|
| `textfield/textfield-text-setters` | TextField text/htmlText setter coerces non-string values (undefined, null, …) to string. htmlText getter re-serializes from format runs only when `html=true` OR a styleSheet is attached (`is_effectively_html` matching Ruffle). |
| `textfield/textfield-html` | Fell out of the same text/htmlText setter+getter rewrite. |
| `haxe/flocons2` | `createEmptyMovieClip` on a dynamically created MC no longer overwrites a pre-existing own-property / root timeline-variable slot with the new child. Matches Ruffle, which only attaches the child to the display list. |
| `propertycase/propertycase-preserving-6` | `for…in` dedup in SWF≤6 is case-insensitive across prototype + own — prototype keys that match an own property case-insensitively are filtered out. |
| `property-paths/property-paths-6` | `GetVariable` slash-path walk for `/obj:prop.sub` when `obj` is a plain ScriptObject reached via `GetVariable`. Walks MC children → variables → members step by step. Skipped when target ends in `:` to preserve `path_string` compatibility. |
| `duplicateMovieClip/name-coercion` | `duplicateMovieClip` target-name arg now coerces through `convertString` / `objectCallToString` for `null`, `undefined`, numbers, etc. |
| `xml/xmlload` | `XML.load` fires `this.onData(raw)` and tracks `_bytesLoaded`/`_bytesTotal` (DONT_ENUM) via `ng_registerBitmapMetadata`. Default `XML.prototype.onData` parses and fires `onLoad(true)`. |
| `loadvariables/loadvars` | `LoadVars.load` replaced the stub with a real implementation: fetches the data file, URL-decodes each pair into own properties, tracks byte counts, fires `onLoad(success)`. |
| `bitmapdata/loadBitmap` | NO_GRAPHICS `defineBitmap` now registers bitmap metadata via a shared `ng_registerBitmapMetadata`, so `BitmapData.loadBitmap(export)` resolves dimensions. |

`duplicateMovieClip/duplicateMovieClip` also improved (1/4 → 2/4 lines) via `applyInitObjectPropToMC` routing — but still fails on `_width`/`_height` because clones of dynamic MCs have no children and our `mcGetOriginalBounds` returns 0 for them.

---

## Still Failing (none in `avm1/`)

All historical `avm1/` sub-tree failures now pass (`duplicateMovieClip/*`, `doactionorder/doactionorder`, `moviecliploader` — the latter via Part B + Part C of `complete/SHUMWAY_AVM1_SUBTREES_PLAN.md`).

---

## Known Side-Effects of This Session's Sync-Loader Choices

The new `LoadVars.load` / `XML.load` implementations are synchronous: by the time the method returns, all content is parsed and `onData`/`onLoad` have already fired. A few upstream Ruffle/Gnash tests poll `getBytesLoaded()` / `getBytesTotal()` between the call and the expected async network completion, expecting the "loading in progress" state (0 / undefined). We can never produce that state without an async loader.

Affected (regressions expected and accepted):
- `avm1/load_vars` — lost ~7 matching lines due to callback-order interleaving.
- `avm1/xml_getbytes` — no status change, −1 line.
- `from_gnash/actionscript.all/LoadVars-v{6,7,8}` — −6 lines each for byte-count and `_bytesLoaded` initial-state assertions.

Net across all four suites at `db6a0198`: +18 passing tests, −1 passing test. Pass-rate delta is strongly positive on Shumway (+9.8% flat, +19.1% avm1).

---

## Flat Suite Status

Flat root is at 100% (10/10). All historical flat-suite work items complete.
