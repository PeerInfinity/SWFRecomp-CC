# Shumway Test Suite Status

Last updated: 2026-04-17 (CI run at db6a0198)

## Quick Summary

### Flat suite (`from_shumway/`)

| Metric | Value |
|--------|-------|
| Total tests | 92 |
| Passing | **57** (62.0%) |
| Ruffle-matched | 1 |
| Effective pass | **58** (63.0%) |
| Failing | 34 |

**Breakdown by sub-tree** (flat suite recurses into subdirs):

| Sub-tree | Total | Pass | RM | Fail |
|----------|-------|------|----|------|
| Flat root (no subdir) | 10 | 10 | 0 | 0 |
| `avm1/` | 47 | 41 | 1 | 5 |
| `fuzz/` | 30 | 3 | 0 | 27 |
| `timeline/` | 5 | 3 | 0 | 2 |

**Flat root is still 100% passing**: all 10 remaining tests (add, avm1timeline1, avm1timeline2, button3, doubleAndRegister, fscommand1, gradientTransform, invalidClipDepth, movieinfo1, targetPath1) pass.

**Remaining failing clusters** come from `fuzz/` (27 fail — fuzzer-generated SWFs, likely useful for finding edge cases in runtime/recompiler), `avm1/` sub-tree (5 fail — see below), and `timeline/` (2 fail).

### AVM1 subdirectory (`from_shumway/avm1/`)

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **41** (87.2%) |
| Ruffle-matched | 1 |
| Effective pass | **42** (89.4%) |
| Ignored | 2 |
| **Filtered pass rate** | **41/45 (91.1%)** |
| Failing (filtered) | 4 |

**Per-category status:**

| Category | Total | Pass | Fail |
|----------|-------|------|------|
| Flat (root-level tests) | 23 | 21 (+1 RM) | 1 (`moviecliploader`) |
| `bitmapdata/` | 2 | 2 | 0 |
| `doactionorder/` | 2 | 1 | 1 (`doactionorder`) |
| `duplicateMovieClip/` | 4 | 1 | 3 (`duplicateMovieClip`, `dontremove`, `samedepth`) |
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
| `incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md` | Active plan — 5 remaining sub-tree failures, handoff notes |

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

## Still Failing (5 in `avm1/`, plus `moviecliploader` at flat)

See `incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md` for per-cluster analysis and handoff notes.

- `duplicateMovieClip/duplicateMovieClip` (2/4) — clone bounds for dynamic MCs.
- `duplicateMovieClip/dontremove` (3/6) — source timeline MC name-resolution after clone.
- `duplicateMovieClip/samedepth` (4/6) — `getInstanceAtDepth` depth-bias mismatch for DuplicateSprite-placed clones.
- `doactionorder/doactionorder` (3/7) — DoAction sequencing / cross-script variable visibility.
- `moviecliploader` (1/7) — async `onLoadStart` deferral across frame tick.

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
