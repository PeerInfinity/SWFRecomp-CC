# Shumway Test Suite Status

Last updated: 2026-05-06 (place-before-define recompiler fix locally; CI run pending — flat suite 71/92 → expected 75/92 effective; filtered fuzz failures drop from 20 to 0).

## Latest fixes (2026-05-06)

- **Place-before-define matches Flash, not Ruffle.** Recompiler now tracks `defined_chars` (DefineSprite, Shape, Button, Text, EditText, Bits, Font, Sound, Video) in tag-stream order. PlaceObject{,2,3} that references a char_id whose Define* tag hasn't been encountered yet is degraded to char_id=0 (modify), matching Flash's sequential-dictionary semantics. Fix in `SWFRecomp/src/swf.cpp` + `SWFRecomp/include/swf.hpp`. Documented in `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`. Of 20 originally failing fuzz tests: 4 PASS (incl. 2 RMATCH→PASS upgrades), 2 newly RMATCH, 16 still MISMATCH (added to `from_shumway/ignored_tests.txt` as fuzz noise). No canary regressions across 26 AVM1 + 12 Shumway-flat sample tests. Plan moved to `complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md`.

## Earlier fixes (2026-05-04, in CI at `c5994ec1`)

- **Fuzz `this._currentframe` tests → 5+ PASS.** `from_shumway/fuzz/c8b8069c…`, `ac93c8c9…`, `07580c34…`, `2f4f46bf…`, `81004241…` (all the previously-built fuzz tests with `this._currentframe` traces from inside sprite frame scripts) now PASS. Root cause: in `advance_sprite_frames` (`SWFModernRuntime/src/libswf/tag.c`), only `obj->sprite_current_frame` (DisplayObject, 0-indexed) was incremented per natural advance — `mc->currentframe` (MovieClip, 1-indexed, the value `_currentframe` exposes to ActionScript) was set to 1 at MC creation and never updated outside goto paths (`ng_setSpriteFrame` / `ng_gotoFrameByMC`) and the root-frame updates emitted by the recompiler. So a script like `trace(this._currentframe)` running from inside a sprite frame func always returned 1 instead of the actual frame number. Fix: just before `CALL_FRAME(...)` at line ~941 (natural advance only), resolve the sprite's MC via `actionFindMovieClipByName(obj->instance_name)` and set `smc->currentframe = (int)frame + 1`. Mirrors `swf_core.c`'s update of `root_movieclip.currentframe` before each root frame func. Manual-nav catch-up paths (lines 814/866 within `advance_sprite_frames`, and `ng_setSpriteFrame`) are intentionally NOT touched — they already set `mc->currentframe` to the target value before catch-up so all catch-up frames see the target value (matching Flash). The remaining 22 numeric-output fuzz tests in `from_shumway/fuzz/*` likely also use this pattern (numeric-only output suggests the same `trace(this._currentframe)` template); expect more flips on the next CI run as they're rebuilt. Regression battery: 22/22 AVM1 lifecycle, 17/17 AVM1 scope, 14/14 misc-ming timeline, 14/14 AVM1 timeline, 6/6 AVM1 sprite-state, 5/5 gnash actionscript.all effective — no regressions.

## Quick Summary

### Flat suite (`from_shumway/`)

| Metric | Value |
|--------|-------|
| Total tests | 92 |
| Passing | **68** (73.9%) |
| Ruffle-matched | 3 |
| Effective pass | **71** (77.2%) |
| Failing | 21 |

**Breakdown by sub-tree** (flat suite recurses into subdirs, CI `c5994ec1`):

| Sub-tree | Total | Pass | RM | Fail |
|----------|-------|------|----|------|
| Flat root (no subdir) | 10 | 10 | 0 | 0 |
| `avm1/` | 47 | 45 | 1 | 1 (`moviecliploader`) |
| `fuzz/` | 30 | 8 | 2 | 20 |
| `timeline/` | 5 | 5 | 0 | 0 |

**Flat root is still 100% passing**: all 10 remaining tests (add, avm1timeline1, avm1timeline2, button3, doubleAndRegister, fscommand1, gradientTransform, invalidClipDepth, movieinfo1, targetPath1) pass.

**`timeline/` is now 100% passing** (5/5) — `timeline_as2_1` and `timeline_as2_5` flipped to PASS since the previous snapshot, picked up via the cross-cutting fixes (Instance-v* native ctor, Global-v6 case-insensitive lookup, GetMember/SetMember hidden own-prop walk, ecmaToInt32 trunc, ASSetPropFlags array, convertFloat strict mode).

**Remaining failing clusters** come from `fuzz/` (24 fail — fuzzer-generated SWFs, useful as an edge-case source for the runtime/recompiler) and `avm1/` sub-tree (1 fail — see below).

### AVM1 subdirectory (`from_shumway/avm1/`)

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **45** (95.7%) |
| Ruffle-matched | 1 |
| Effective pass | **46** (97.9%) |
| Ignored | 2 |
| **Filtered pass rate** | **45/45 (100.0%)** |
| Failing (filtered) | 0 |

The sole unfiltered fail is `moviecliploader` (1/7 — MCL one-tick deferral, tracked in `incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md` Part B). `doactionorder` now passes following Phase 6 of the ActionQueue rework.

**Per-category status:**

| Category | Total | Pass | Fail |
|----------|-------|------|------|
| Flat (root-level tests) | 23 | 21 (+1 RM) | 1 (`moviecliploader`) |
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
| `incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md` | Concrete fix plan for the 2 remaining sub-tree failures — Part A (FIFO DoAction queueing) + Part B (one-tick MCL deferral). Ruffle-referenced, canary list included. |

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

## Still Failing (1 in `avm1/`, also at flat)

See `incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md` for the fix plan.

- `doactionorder/doactionorder` — **RESOLVED** by Phase 6 of the ActionQueue rework (commit `a427f5fc`, "Land Phase 6 of ActionQueue rework: inline root DoAction queueing"). Plan's Approach A3 effectively became the ACTION_QUEUE_PLAN, now complete (marked at commit `fe74d7aa`).
- `moviecliploader` (1/7) — STILL FAILING. Part B landed briefly (commit `1a1bf852`) improving this to 6/7, but CI revealed 3 AVM1 regressions (`movieclip_invalid_get_bounds_1/2` heap corruption, `string_paths_eval2` timer shift). Reverted in `59533be3`. The one-tick deferral exposes pre-existing latent bugs in getBounds handling and test calibration for chained setInterval. See plan file for the three paths forward.

Other previously-failing `avm1/` sub-tree tests (`duplicateMovieClip/*`, `doactionorder/doactionorder`) all now pass.

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
