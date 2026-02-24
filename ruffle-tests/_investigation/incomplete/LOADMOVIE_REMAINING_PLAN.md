# LoadMovie Remaining Tests Plan
<!-- TESTS: loadmovie_var_persistence, loadmovienum_cross_version_prototype, mcl_events_swf_version, movieclip_state_values, movieclip_library_state_values -->

Last updated: 2026-02-24

## Status: NOT STARTED — 0/5 tests

This plan covers the remaining feasible tests that are blocked by the loadMovie infrastructure
but aren't covered by other specific plans (LOADVARIABLES_PLAN, ROOT_REPLACEMENT_PLAN,
REGISTERCLASS_PLAN, GLOBALS_PLAN).

---

## Test Inventory

### 1. loadmovie_var_persistence (8 lines)

**Child SWFs**: `clip1.swf`, `clip2.swf`

**Expected output**:
```
Loading clip1.swf
Set exampleVariable
innerClip: _level0.innerClip
innerClip.exampleVariable: example value
Loading clip2.swf
Get exampleVariable: undefined
innerClip: _level0.innerClip
innerClip.exampleVariable: undefined
```

**What it tests**: After loading clip1.swf into a target clip, clip1 sets `exampleVariable`
on the target. When clip2.swf is subsequently loaded into the same target, `exampleVariable`
is `undefined` — proving that loadMovie clears the target clip's variables.

**What's needed**:
1. Target clip's dynamic_props must be cleared before loading a new child SWF
2. The target MC's `_url` must update to the child's filename
3. Child SWF runs in the target's context (already implemented via `g_current_context`)
4. `innerClip` — the child creates a child MC named "innerClip" inside the target

**Feasibility**: **HIGH** — The `dynamic_props` clearing was partially implemented for
MCL.loadClip but may not be in the actionGetURL2 loadMovie path. Need to verify and ensure
both paths clear target state consistently.

**Blocking issues**:
- Variable clearing on the target MC before loading new content
- Child clip creation (`innerClip`) must be accessible as `_level0.innerClip`

---

### 2. loadmovienum_cross_version_prototype (10 lines)

**Child SWFs**: `target.swf` (SWF8)

**Expected output**:
```
Test (SWF6): Loading target.swf into _level2
Test (SWF6): _level2.getSWFVersion() = 8
Test (SWF6): _level2.testProp =
Test (SWF6): _level2.__proto__ === MovieClip.prototype: false
Target (SWF8): _level2.customProp = FROM_SWF8
Target (SWF8): _level2.__proto__ === MovieClip.prototype: true
Test (SWF6): Unloading _level2
Test (SWF6): After unload - _level2.__proto__ === MovieClip.prototype: false
Test (SWF6): After unload - _level2.testProp =
```

**What it tests**: Cross-version prototype behavior. A SWF6 parent loads a SWF8 child into
`_level2`. The parent (SWF6) sees `_level2.__proto__ === MovieClip.prototype` as `false`
(because SWF6 uses case-insensitive property lookup and different scope rules). The child
(SWF8) sets `customProp` and sees `__proto__ === MovieClip.prototype` as `true`. After
unloading, the level reverts.

**What's needed**:
1. `loadMovieNum` into `_level2` — already partially working
2. `getSWFVersion()` returning child SWF's version — partially implemented
3. `__proto__` comparison against `MovieClip.prototype` — needs prototype chain setup
4. Cross-version `__proto__` behavior differences
5. Unload reverting level state

**Feasibility**: **MEDIUM** — The core loadMovieNum infrastructure exists. The `__proto__`
behavior is the main challenge. The test checks case-sensitive vs case-insensitive property
name matching for `__proto__`, which is version-dependent. Also needs `MovieClip.prototype`
to be a real object that `===` comparison works against.

**Blocking issues**:
- `MovieClip.prototype` as a proper object (not just string matching)
- Cross-version `__proto__` access semantics
- Level state revert on unload

---

### 3. mcl_events_swf_version (232 lines)

**Child SWFs**: `child5.swf` (SWF5), `child6.swf` (SWF6), `child7.swf` (SWF7),
`child8.swf` (SWF8), `child9.swf` (SWF9), `child10.swf` (SWF10)

**Expected output**: 232 lines of MCL event callbacks across 7 loads (6 children + 1
non-existent file). Each load produces: onLoadStart → onLoadProgress → onLoadComplete →
child trace → onLoadInit (or onLoadError for missing file). Each callback reports:
- `d=N` (counter incremented per load)
- `_target`, `_name`, `_url` of the listener (`this` = root)
- `mc=_level0.mcN`, `mc._target=/mcN`, `mc._name=mcN`, `mc._url=file:///childN.swf`

**What it tests**:
1. MCL fires events correctly for multiple sequential loads
2. Each load goes into a separate `createEmptyMovieClip("mcN", depth)`
3. Target MC properties (`_target`, `_name`, `_url`) are correct in callbacks
4. Error handling for non-existent SWF (`onLoadError` instead of `onLoadInit`)
5. Event argument passing (the `d` counter, target MC as first arg)
6. `_url` format uses `file:///` prefix

**What's needed**:
1. `_url` format: Currently our URLs are just filename (`child5.swf`), but test expects
   `file:///child5.swf`. Need to match Ruffle's URL scheme.
2. MCL event callbacks receiving correct `this` (the listener/root, not the MCL object)
3. MCL event callbacks can access `d` property on listener object
4. `mc._url` must be set to `file:///childN.swf` format on the target MC

**Feasibility**: **MEDIUM-HIGH** — Most of the MCL infrastructure is already implemented
(loadClip, events, deferred dispatch). The main gaps are:
- `_url` format (`file:///` prefix)
- Correct `this` binding in event callbacks (should be the listener, not the MCL)
- Each load's events fire sequentially (one full load cycle per ShowFrame)

**Blocking issues**:
- `_url` format consistency across all paths
- Sequential per-frame load execution (current MCL deferred system fires all at once)
- The test loads 7 clips across multiple frames (not all in one frame)

---

### 4. movieclip_state_values (114 lines)

**Child SWFs**: `target.swf`, `no correct file (text).swf`, `no correct file (image).swf`

**Expected output**: 4 test sections, each:
1. Issue loadMovie command
2. Compare target MC properties against reference
3. Report "Both targets have the same props" or "Change: Prop X is Y on first, but Z on second"
4. Issue unloadMovie command
5. Compare again

**What it tests**: Complete MC property dump after loadMovie/unloadMovie:
- `_currentframe`, `_framesloaded`, `_totalframes` (frame state)
- `_url` (child SWF URL)
- `getBytesLoaded()`, `getBytesTotal()` (file size)
- `getSWFVersion()` (child SWF version)
- `_height`, `_width`, `_rotation`, `_x`, `_y` (transform)
- `transform.pixelBounds`, `getBounds(this/mc)`, `getRect(this/mc)` (bounds)

Test 1 (missing file): `_framesloaded=-1`, `_totalframes=0`, `getBytesTotal=-1`, `getSWFVersion=-1`
Test 2 (text file): Same as Test 1
Test 3 (image file): Shows loaded image dimensions (1280x985), `getBytesLoaded/Total=2334995`
Test 4 (valid SWF): Shows `_url=target.swf`, `getBytesLoaded/Total=68`, `getSWFVersion=8`

**What's needed**:
1. **Failed load state**: When loadMovie URL doesn't resolve to a valid SWF:
   - `_framesloaded = -1`, `_totalframes = 0`, `_currentframe = 0`
   - `getBytesTotal() = -1`, `getSWFVersion() = -1`
   - `_url` set to the failed URL
2. **Image load state**: We can't decode images, but could fake the "text file" case
3. **Valid load state**: `_currentframe=1`, `getBytesLoaded/Total` from file size
4. **Unload state**: Reverts to pre-load or zeroed state

**Feasibility**: **LOW-MEDIUM** — This test requires:
- Correct state for failed loads (non-SWF URLs)
- Correct state for image loads (not feasible without image decoding)
- `getBytesLoaded/Total` and `getSWFVersion` returning `-1` for failed loads
- Extensive property dump matching (transforms, bounds, etc.)

Only Tests 1, 2, and 4 might be matchable (Test 3 needs image decoding). Even then,
the property dump is very detailed and many values would need to be exactly right.

**Blocking issues**:
- Failed load state values (-1 for various properties)
- Image loading (Test 3, 30 lines)
- Exact transform and bounds values in property dump

---

### 5. movieclip_library_state_values (79 lines)

**Child SWFs**: None (uses library assets within test.swf itself)

**Expected output**: Property dump of a library-imported MovieClip, then comparison after
unload showing state changes.

Lines 1-70: Full property dump (same format as movieclip_state_values)
Lines 72-79: "Both targets have the same props" + 5 change lines after unload

**What it tests**: MC state for clips placed via the library (ExportAssets + attachMovie),
not via loadMovie. After unloading, frame counts and byte counts go to 0.

**What's needed**:
1. Complete MC property dump matching (same properties as movieclip_state_values)
2. Library asset placement (ExportAssets + attachMovie from REGISTERCLASS_PLAN)
3. Correct default values for all MC properties

**Feasibility**: **LOW** — Depends on ExportAssets/attachMovie (REGISTERCLASS_PLAN Phase 1-2)
which are not yet implemented. Also requires matching a very detailed 79-line property dump.

**Blocking issues**:
- Needs ExportAssets + attachMovie infrastructure (REGISTERCLASS_PLAN)
- Detailed property dump matching

---

## Priority and Dependencies

| Test | Priority | Dependencies | Est. Effort |
|------|----------|-------------|-------------|
| loadmovie_var_persistence | **HIGH** | Variable clearing on loadMovie | Low |
| mcl_events_swf_version | **MEDIUM** | URL format, sequential MCL loading, event `this` binding | Medium |
| loadmovienum_cross_version_prototype | **MEDIUM** | __proto__ chain, MovieClip.prototype, version-dependent lookup | Medium |
| movieclip_state_values | **LOW** | Failed load state, image decoding, property dump | High |
| movieclip_library_state_values | **LOW** | REGISTERCLASS_PLAN (ExportAssets), property dump | High |

### Recommended Order

1. **loadmovie_var_persistence** — Quick win, just needs dynamic_props clearing in the
   actionGetURL2 loadMovie path (already done for MCL.loadClip).

2. **mcl_events_swf_version** — High value (232 lines), builds on existing MCL infrastructure.
   Main work: URL format fix, sequential per-frame loading, event `this` binding.

3. **loadmovienum_cross_version_prototype** — Medium value, requires `__proto__` and
   MovieClip.prototype infrastructure.

4. **movieclip_state_values** / **movieclip_library_state_values** — Low priority, high effort,
   depends on other plans.

---

## Implementation Notes

### Variable Clearing on loadMovie

Currently, `builtin_mcl_loadClip` clears `target_mc->dynamic_props` before loading. The
`actionGetURL2` loadMovie path does NOT clear dynamic_props. To fix `loadmovie_var_persistence`:

```c
// In actionGetURL2 loadMovie path, before findMovieEntry:
if (_gu2_mc != NULL && _gu2_mc->dynamic_props != NULL) {
    releaseObject(app_context, (ASObject*)_gu2_mc->dynamic_props);
    _gu2_mc->dynamic_props = NULL;
}
```

### URL Format (`file:///` prefix)

The `mcl_events_swf_version` test expects `_url = file:///child5.swf`. Currently we store
just the filename. Two options:
1. **Compile-time**: Set `SWF_URL` to `file:///test_name/test.swf` instead of `test_name/test.swf`
2. **Runtime**: In MC._url getter, prepend `file:///` to stored URL

Option 2 is cleaner. But we need to match what Ruffle does — it uses `file:///` for local
files. This affects `_url` on both root and child clips.

### Sequential Per-Frame MCL Loading

The `mcl_events_swf_version` test issues 7 `loadClip` calls in frame 0. The events should
fire sequentially across frames (one load cycle per ShowFrame). Current implementation fires
all deferred loads in a single ShowFrame. May need to throttle to one load per frame, or
the test may issue loads across multiple frames with `setInterval`.

Need to decompile the test SWF to understand the exact loading pattern.

---

## Verification

```bash
python3 ruffle-tests/verify_output.py --test=loadmovie_var_persistence --diff --verbose
python3 ruffle-tests/verify_output.py --test=loadmovienum_cross_version_prototype --diff --verbose
python3 ruffle-tests/verify_output.py --test=mcl_events_swf_version --diff --verbose
python3 ruffle-tests/verify_output.py --test=movieclip_state_values --diff --verbose
python3 ruffle-tests/verify_output.py --test=movieclip_library_state_values --diff --verbose

# Regression checks:
python3 ruffle-tests/verify_output.py --test=loadmovie --diff --verbose
python3 ruffle-tests/verify_output.py --test=mcl_loadclip --diff --verbose
python3 ruffle-tests/verify_output.py --test=loadmovie_flashvars --diff --verbose
```

---

## Cross-Plan Dependencies

| This Plan Needs | From Plan | Specifically |
|-----------------|-----------|-------------|
| Dynamic props clearing | LOADMOVIE_PLAN (Phase 2) | Consistent clearing across all loadMovie paths |
| `__proto__` chain | PROTOTYPE_OBJECT_PLAN | MovieClip.prototype as real object, `===` comparison |
| ExportAssets | REGISTERCLASS_PLAN (Phase 1) | Library asset placement for movieclip_library_state_values |
| setInterval | TIMER_PLAN | May be needed for mcl_events_swf_version sequential loading |
| Cross-version globals | GLOBALS_PLAN (Phase 8) | loadmovienum_cross_version_prototype __proto__ behavior |
