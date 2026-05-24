# MovieClip-vN Investigation Plan
<!-- TESTS: MovieClip-v6, MovieClip-v7, MovieClip-v8 -->

Last updated: 2026-05-23 (Phase 1 partial — `MovieClip.prototype.meth`
implemented as a real function_type=2 builtin. MovieClip-v5/v6/v7/v8
each gain +23/+24 matching lines (315→338, 814→838, 836→860,
924→948). v5 stays ruffle_matched; v6/v7/v8 stay output_mismatch.
Two residual `meth`-related lines remain in v6/v7/v8: line 2097
(`retCaller == _root.meth`) needs `arguments.caller` tracking
across the native-builtin frame, and line 2100
(`_root.meth(1)` after Number.prototype.toLowerCase override) needs
user-method dispatch on primitive Number receivers in actionCallMethod
(currently only String primitives walk the wrapper-prototype chain
for user overrides). Phase 1 status updated below.)

Last updated: 2026-05-23 (Phase 11 _yscale-sign marked
`not_actionable`: Ruffle's `output.fp23.ruffle.txt` also reads
`obtained: -50` at line 616, so this line is common to both diffs
and doesn't block ruffle_matched promotion. Reasoning in section K.
No code change this update — docs only.)

Last updated: 2026-05-22 (Phase 5 landed → MovieClip-v6/v7/v8 each
−3 mismatched lines: renamed-parent `_target` now cascades to
descendants. Test still `output_mismatch`; zero regressions across
AVM1 + gnash batteries.)

Last updated: 2026-05-21 (Phase 17 landed → MovieClip-v6/v7/v8 each
−20 mismatched lines, still `output_mismatch`. Phases 2 + 4 earlier
the same day landed −5 each. Zero regressions across AVM1 + gnash
batteries.)

<!-- PLAN_META
id: MOVIECLIP_VN_PLAN
status: pending
phases:
  - id: 1
    name: "MovieClip.prototype.X = fn — user-added method visibility on instances"
    status: in_progress
  - id: 2
    name: "mc.getSWFVersion() returning 5 instead of OUTPUT_VERSION"
    status: completed
  - id: 3
    name: "mc.hitTest method not on prototype"
    status: pending
  - id: 4
    name: "_soundbuftime is per-root, not per-MC"
    status: completed
  - id: 5
    name: "Renamed-parent _target path propagation to children"
    status: completed
  - id: 6
    name: "Soft-reference / hard-reference depth and replacement semantics"
    status: pending
  - id: 7
    name: "unloadMovie binding deletion timing (umc undefined too early)"
    status: pending
  - id: 8
    name: "getBounds undefined fallback for empty MovieClip vs always returning 10"
    status: pending
  - id: 9
    name: "getBounds with reference-clip argument (transform into ref's coord space)"
    status: pending
  - id: 10
    name: "getBounds reflects _xscale/_yscale transforms"
    status: pending
  - id: 11
    name: "_yscale assignment after negative value preserves new sign"
    status: not_actionable
  - id: 12
    name: "getBounds with plain-Object reference (Object treated as identity)"
    status: pending
  - id: 13
    name: "setProperty (SWF action 0x23) on MC properties returning the assigned value"
    status: pending
  - id: 14
    name: "mc.addProperty for MC virtual properties (_x/_y) invokes getter/setter"
    status: pending
  - id: 15
    name: "MovieClip method dispatch with call/apply (mcm counter)"
    status: pending
  - id: 16
    name: "_visible cascading from parent to child"
    status: pending
  - id: 17
    name: "_quality setter 'BEST' value"
    status: completed
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac); MovieClip-v6/v7/v8 became visible at that point. MovieClip-v5 was already RM via complete/GNASH_FEATURE_PLAN.md."
related:
  - id: FUNCTION_VN_PLAN
    reason: "Phase 15 (call/apply dispatch counter) parallels FUNCTION_VN Phase 2 (apply/call this-binding)."
  - id: TEXTFIELD_VN_PLAN
    reason: "Phase 17 (_quality / _highquality) is the inverse of TEXTFIELD's MC-only-property gating — _quality is a stage property accessible through any MC, including TextFields."
blockers: []
status_note: |
  Large surface area (~140 failures per version). Most clusters are
  small but independent. Some are interactions with already-passing
  AVM1 tests, so regression risk is moderate — add representative
  AVM1 MC tests to each phase's verification battery (e.g.
  movieclip_state_values, movieclip_setmask, target_clip_removed,
  unload_nested_child).
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| MovieClip-v6 | 777/936 | 83.0% | output_mismatch |
| MovieClip-v7 | 798/969 | 82.4% | output_mismatch |
| MovieClip-v8 | 885/1087 | 81.4% | output_mismatch |

MovieClip-v5 already at ruffle_matched (per
complete/GNASH_FEATURE_PLAN.md).

### Fixes landed (2026-05-23, pending CI)

- **Phase 1 partial — `MovieClip.prototype.meth` builtin
  (MovieClip.as:182/193/2084-2134/2552/2553).** `meth` is an
  undocumented Flash MovieClip method that parses case-insensitive
  "get" → 1, "post" → 2, anything else → 0 from `arg.toLowerCase()`.
  Mirrors Gnash's `movieclip_meth` in
  `libcore/asobj/MovieClip_as.cpp:1175`. Implemented as a real
  function_type=2 builtin (`builtin_mc_meth`) on
  `MovieClip.prototype`, not as an explicit case in actionCallMethod's
  MOVIECLIP arm — this keeps `o.meth = MovieClip.prototype.meth;
  o.meth("post")` working on plain OBJECTs (line 2552/2553) via the
  generic prototype-method dispatch in the OBJECT arm. The builtin
  delegates `arg.toLowerCase()` to a recursive `actionCallMethod`
  call. Matching lines per test gain +23/+24:

  | Test | Before | After | Δ |
  |------|--------|-------|---|
  | MovieClip-v5 | 315/363 | 338/363 | +23 |
  | MovieClip-v6 | 814/936 | 838/936 | +24 |
  | MovieClip-v7 | 836/969 | 860/969 | +24 |
  | MovieClip-v8 | 924/1087 | 948/1087 | +24 |

  v5 stays ruffle_matched; v6/v7/v8 stay output_mismatch (other
  phase blockers — getBounds reference-clip transforms, soft/hard
  reference semantics — dominate the residual diff).

  Two residual `meth`-related lines remain across v6/v7/v8:
  - Line 2097 `retCaller == _root.meth`: requires
    `arguments.caller` to point at the `_root.meth` function value
    from inside the recursive `Number.prototype.toLowerCase` call.
    Native-builtin frames don't currently push a caller, so
    `arguments.caller` reads as undefined.
  - Line 2100 `_root.meth(1)` after `Number.prototype.toLowerCase =
    function(){ return "post"; }`: requires user-method dispatch on
    primitive Number receivers. The String primitive arm of
    `actionCallMethod` (action.c ~61672) checks
    `getPrimitiveWrapperProto` for user overrides, but the
    Number/Boolean arm (action.c ~67104) only handles
    `toString`/`valueOf`/`hasOwnProperty` and falls to
    `pushUndefined` otherwise. Extending the Number/Boolean arm
    with a String-arm-style override walk would also fix this
    line. Out of scope for this commit — would carry wider
    regression risk; deferred.

  Verified no regressions across:
  - 14-test AVM1 MC/scope/super battery (swf5_to_6_cross_call,
    movieclip_state_values, movieclip_default_state, on_construct,
    as2_super_and_this_v6/v8, clone_sprite_edittext, clip_constructors,
    function_base_clip, movieclip_setmask, goto_rewind3,
    swf5_no_closure, closure_scope, set_interval) — all PASS.
  - 15-test gnash actionscript.all prototype-heavy battery (case-v6,
    Inheritance-v6/v7/v8, Function-v6/v7/v8, Object-v6/v7/v8,
    delete-v6, Global-v6, ASnative-v8, getvariable-v6,
    MovieClipLoader-v6) — all effective pass (3 PASS + 12 RM).
  - 18-test AVM1 broader regression (closure_scope,
    register_and_init_order, swf5_xml_event_handler_context,
    movieclip_default_state, movieclip_library_state_values,
    array_constructor, watch, add_property, enumerate, swf5_no_closure,
    extends_chain, on_construct, funky_function_calls, goto_methods,
    goto_frame, function_as_function, tell_target, swf5_to_6_cross_call)
    — all effective pass.
  - 6-test misc-ming.all (DragDropTest, key_event_test,
    loop/loop_test, loop/loop_test10, register_class/registerClassTest,
    register_class/registerClassTest2) — all effective pass.
  - 2-test from_shumway (targetPath1, doubleAndRegister) — PASS.

### Fixes landed (2026-05-22, pending CI)

- **Phase 5 — Renamed-parent `_target` cascades to descendants
  (MovieClip.as:623/625/629).** After `mc4._name = 'changed'` the
  child `mc5._target` should read `"/changed/mc5_mc"`, but we
  reported `"/mc4_mc/mc5_mc"`: the `_name` setter (and
  `actionRenameMovieClip`) rebuilt the renamed MC's own `target`
  but never updated descendants whose `target` was a literal copy
  of the old parent path plus their own name. New helper
  `propagateTargetToDescendants(mc)` in
  `SWFModernRuntime/src/actionmodern/action.c` walks `child_mc_cache`
  for direct children (`child->parent == mc`), rewrites their
  `target` from the new `mc->target + "/" + child->name`, then
  recurses. Called from both rename sites: `actionRenameMovieClip`
  (NO_GRAPHICS path) and the `_name` setter in
  `actionSetMember`'s MOVIECLIP arm (all builds). Cluster
  collapses to 0 ours-only lines on v6/v7/v8 (−3 each).

  Verified no regressions on a representative AVM1 / Gnash MC
  battery: tell_target, tell_target_invalid{,_swf6},
  property_invalid_base_clip, mcl_replace_root_swf7_to_swf6,
  string_paths_eval2, string_paths_other, target_clip_removed,
  target_path, path_string, swf5_to_6_cross_call,
  movieclip_default_state, movieclip_state_values,
  movieclip_setmask, unload_nested_child, removed_clip_halts_script,
  clone_sprite_edittext, clip_constructors, on_construct,
  function_base_clip, goto_rewind3 — all PASS;
  gnash misc-swfc soft_reference_test1 + movieclip_destruction_test2 RM/PASS;
  gnash actionscript.all case-v6, MovieClip-v5, MovieClipLoader-v6,
  Function-v6, getvariable-v6, Inheritance-v6, Object-v6,
  delete-v6, Global-v6 all effective-pass.

### Fixes landed (2026-05-21, pending CI)

- **Phase 17 — `_quality` / `_highquality` are stage-wide and linked
  (MovieClip.as:2411-2494).** Both properties were stored per-MC
  (`mc->quality`, `mc->highquality`) and were independent of each
  other; the test sets them on one clip and reads them back through
  another clip and `_root`, and cross-checks `_quality` ⇄
  `_highquality`. Added a `g_stage_quality[16]` global
  (`SWFModernRuntime/src/actionmodern/action.c`, default `"HIGH"`) plus
  two helpers: `stageQualityToHighqualityInt()` (BEST→2, HIGH→1, else→0,
  mirrors Ruffle `high_quality()`) and `setStageQualityFromHighquality()`
  (NaN→no-op, `>1.5`→BEST, `==0`→LOW, else→HIGH, mirrors Ruffle
  `set_high_quality()`). All `_quality`/`_highquality` read sites
  (bare-var, GetProperty case 16/19, dotted getter) and write sites
  (SetVariable, dotted SetMember, **and the previously-missing
  SetProperty action 0x23** cases 16/18/19) now route through the
  global. `actionToggleQuality` updated too. `mc->quality` /
  `mc->highquality` left in place but unused.

  Each of v6/v7/v8 dropped ~20 mismatched lines. Verified no
  regressions: AVM1 movieclip_default_state, movieclip_library_state_values,
  movieclip_state_values, swf5_to_6_cross_call, target_clip_removed,
  unload_nested_child, movieclip_setmask, loadmovienum_cross_version_prototype
  all effective-pass; gnash case-v6, Inheritance-v6, MovieClip-v5 all
  effective-pass.

- **Phase 4 — `_soundbuftime` is stage-wide (MovieClip.as:531/533).**
  `_soundbuftime` was stored per-MC (`mc->soundbuftime`); the test sets
  `mc._soundbuftime` and reads it back through `mc2`. Flash's
  `_soundbuftime` is a single stage-wide value. Added a `g_soundbuftime`
  global (`SWFModernRuntime/src/actionmodern/action.c`, default 5.0f);
  all three read sites (bare-var getter, GetProperty case 18, dotted
  getter) and both write sites (SetVariable, SetProperty) now route
  through it. `mc->soundbuftime` is left in place but unused.

- **Phase 2 — `_root.getSWFVersion()` returns OUTPUT_VERSION
  (MovieClip.as:184/2537).** `getSWFVersion()` on `_root` returned 5
  instead of the movie version. Root cause: `root_movieclip.swf_version`
  is set by `ensureGlobalInit` from the live `g_swf_version`, but
  `ensureGlobalInit` first runs *inside* `actionImportAssets("Dejagnu.swf")`
  — a SWF5 import context where `g_swf_version` is transiently 5. Added
  `g_main_movie_swf_version`, captured once in
  `SWFRecomp/wasm_wrappers/main.c` from the `SWF_VERSION` constant (never
  swapped by child-SWF context switches); `ensureGlobalInit` now uses it
  for `root_movieclip.swf_version`. Lines 909/910 (`o.getSWFVersion()`,
  unloaded-`t1.getSWFVersion()`) remain failures — separate clusters.

Each of v6/v7/v8 dropped 5 mismatched lines (151→146, 162→157,
192→187). Verified no regressions: AVM1 movieclip_default_state,
movieclip_library_state_values, movieclip_state_values,
swf5_to_6_cross_call, loadmovienum_cross_version_prototype all
effective-pass; gnash case-v6, Inheritance-v6, delete-v6, Global-v7,
ASnative-v8 all effective-pass.

## Test source

Gnash testsuite/actionscript.all/MovieClip.as (~2400 lines).
Exercises method visibility, soft/hard MC references, depth swap
semantics, getBounds geometry, addProperty on MC virtual props,
call/apply on MC methods, _quality/_visible cascading.

## Failure clusters

### A. Prototype method visibility (Phase 1)

Lines: 182, 193.

```
- PASSED: typeof(mc.meth) == 'function' [./MovieClip.as:182]
+ FAILED: expected: 'function' obtained: undefined
- PASSED: MovieClip.prototype.hasOwnProperty('meth') [./MovieClip.as:193]
+ FAILED: MovieClip.prototype.hasOwnProperty('meth')
```

Test source: `MovieClip.prototype.meth = function(){...}`. The
assignment should land as own prop on `MovieClip.prototype`, and
every MC instance should see `meth` via prototype lookup. Neither
side is working — the assignment may be landing somewhere else
(global var_map?) instead of on the actual MovieClip.prototype
singleton.

### B. getSWFVersion returning 5 (Phase 2)

Lines: 184.

```
- PASSED: mc.getSWFVersion() == OUTPUT_VERSION [./MovieClip.as:184]
+ FAILED: expected: OUTPUT_VERSION obtained: 5
```

For v6/v7/v8 tests, OUTPUT_VERSION is 6/7/8 respectively. We always
return 5. Likely the per-MC swf version isn't being set, or
`getSWFVersion` is reading a wrong default.

### C. hitTest missing (Phase 3)

Lines: 248.

```
- PASSED: typeof(mc.hitTest) == 'function' [./MovieClip.as:248]
+ FAILED: expected: 'function' obtained: undefined
```

`mc.hitTest` should be a function inherited from MovieClip.prototype.
We have the hitTest implementation in AVM1 (VECTOR_PATH_HITTEST_PLAN
complete, 329/338) but apparently it isn't registered as a
discoverable method via `typeof(mc.hitTest)`.

### D. _soundbuftime is per-root, not per-MC (Phase 4)

Lines: 531, 533.

```
- PASSED: mc2._soundbuftime == 10 [./MovieClip.as:531]
+ FAILED: expected: 10 obtained: 5
```

After `mc._soundbuftime = 10` the test verifies that `mc2._soundbuftime`
also reads 10 (Flash's `_soundbuftime` is a stage-wide property,
accessible through any MC). We are storing per-MC.

### E. Renamed-parent _target propagation (Phase 5)

Lines: 623, 625, 629.

```
- PASSED: mc5._target == "/changed/mc5_mc" [./MovieClip.as:623]
+ FAILED: expected: "/changed/mc5_mc" obtained: /mc4_mc/mc5_mc
```

After `mc4._name = "changed"`, the child `mc4.mc5_mc._target` should
reflect the new parent name. We continue to report the old name.
`_target` should be computed on-demand from the live parent name,
not cached at child-construction time.

### F. Soft-reference / hard-reference semantics (Phase 6)

Lines: 388, 390, 391, 401, 402, 416, 421-435, 445, 447.

```
- PASSED: typeof(hardref3) == 'movieclip' [./MovieClip.as:712]
+ FAILED: expected: 'movieclip' obtained: undefined
- PASSED: typeof(sr62.member) == 'undefined' [./MovieClip.as:846]
+ FAILED: expected: 'undefined' obtained: string
- PASSED: sr62.member == "hardref4_63" [./MovieClip.as:861]
+ FAILED: expected: "hardref4_63" obtained: hardref4_original
```

Complex multi-line cluster exercising Flash's distinction between:
- **Hard references** — variables that hold a MovieClip value
  directly (typeof "movieclip"). When the underlying MC is removed,
  the variable should become undefined.
- **Soft references** — variables that re-resolve to the MC by name
  on each read. When the MC is replaced at the same depth, the
  variable transparently follows.

Our implementation appears to confuse the two; soft references
keep stale values (`sr62.member == "hardref4_original"` when it
should be `"hardref4_63"` because the slot now holds a different MC
with member `_63`), and hard references aren't being cleared on
unload (`typeof(hardref3) == undefined` expected, we return
`movieclip`).

This is the single largest cluster by line count. Verify against the
AVM1 `target_clip_removed`, `string_paths_eval2`, and
`removed_clip_halts_script` tests before committing fixes.

### G. unloadMovie binding clearance (Phase 7)

Lines: 996.

```
- PASSED: typeof(umc) == 'movieclip' [./MovieClip.as:996]
+ FAILED: expected: 'movieclip' obtained: undefined
```

After `umc.unloadMovie()`, the test expects `umc` (a script-local
binding to the MC) to still be typeof "movieclip" — the MC remains
present, just emptied. We are clearing the binding to undefined.

### H. getBounds for empty MC (Phase 8)

Lines: 1367, 1389.

```
- PASSED: c.xMin == undefined [./MovieClip.as:1367]
+ FAILED: expected: undefined obtained: 10
```

`c.xMin` where `c` is the second argument to `getBounds` (the
reference) — on certain configurations Flash returns a bounds
object with undefined fields. We are returning 10 (whatever happens
to be in the field-default position). Likely our getBounds always
populates all four fields; Flash sometimes returns sparse.

### I. getBounds with reference-clip (Phase 9)

Lines: 1402, 1403, 1409, 1410.

```
- PASSED: b.xMin == 30 [./MovieClip.as:1402]
+ FAILED: expected: 30 obtained: 10
```

`mc.getBounds(refClip)` returns bounds in refClip's coordinate
space. We return bounds in the calling MC's local space (always
10/20 since the shape was drawn at 10..20). Transform missing.

### J. getBounds + _xscale/_yscale (Phase 10)

Lines: 1436, 1437, 1450, 1451, 1487, 1488, 1500, 1501, 1512-1515,
1528, 1529, 1540, 1541.

```
- PASSED: b.xMin == -30 [./MovieClip.as:1436]
+ FAILED: expected: -30 obtained: 10
- PASSED: b.yMin == 5 [./MovieClip.as:1487]
+ FAILED: expected: 5 obtained: 10
```

After `_xscale = -200` or `_yscale = 50`, getBounds should report
the post-transform bounds. We are returning pre-transform bounds.

### K. _yscale sign preservation (Phase 11) — NOT ACTIONABLE (2026-05-23)

Lines: 1520.

```
- PASSED: draw._yscale == 50 [./MovieClip.as:1520]
+ FAILED: expected: 50 obtained: -50
```

**The original framing was wrong on two counts.** First, the test
sequence is NOT `draw._yscale = -50; draw._yscale = 50` — it is
`draw._yscale = -50; draw._xscale = -50; draw._width = 10`, and
Flash's _width setter resets both axes to positive sign as a side
effect. Second, **Ruffle's `output.fp23.ruffle.txt` line 616 reads
`FAILED: expected: 50 obtained: -50`** — Ruffle's set_width does
not implement the sign-reset side effect either, and our output
already matches Ruffle here. This line is in BOTH our diff and
Ruffle's diff against expected, so it does not block ruffle_matched
promotion. Fixing it would require Flash-specific math in
`mcSetEffectiveWidth` that Ruffle doesn't have; not worth pursuing
unless we deliberately want to be more correct than Ruffle on
MovieClip-vN. Mark phase status `not_actionable` in the meta block.

### L. getBounds with plain-Object reference (Phase 12)

Lines: 1604-1623.

```
- PASSED: b.xMin == 10 [./MovieClip.as:1604]
+ FAILED: expected: 10 obtained: 6710886.35
```

`mc.getBounds({})` — Flash treats a plain Object as the identity
reference matrix and returns the unmodified bounds. We return the
INT_MIN-twips sentinel (6710886.35 ≈ MAX_TWIPS), which is what
`getBounds` would return when it can't compute bounds. Likely we
are rejecting the plain-Object arg as not-an-MC.

### M. setProperty (SWF action 0x23) return value (Phase 13)

Lines: 2085-2134 (many similar).

```
- PASSED: typeof(ret) == 'number' [./MovieClip.as:2085]
+ FAILED: expected: 'number' obtained: undefined
```

The SWF action 0x23 (SetProperty) sets a MC property AND
pushes the assigned numeric value. We are pushing nothing (the test
captures the stack-top result via `var ret = setProperty(...);`).
Implementation gap in the bytecode emitter or the action handler.

### N. mc.addProperty for MC virtual props (Phase 14)

Lines: 2152, 2153, 2156, 2167, 2176, 2177, 2180.

```
- PASSED: inspect == 17 [./MovieClip.as:2152]
+ FAILED: expected: 17 obtained: 20
- PASSED: getCalls == 1 [./MovieClip.as:2153]
+ FAILED: expected: 1 obtained: 0
```

`mc.addProperty('_x', getter, setter)` should install user getters
that fire on `mc._x` reads. We are bypassing the addProperty
override and returning the native `_x` value (20). The
MovieClip-specific virtual property dispatch needs to consult
`dynamic_props` (where addProperty stores) before falling through
to the native getter.

### O. MovieClip method dispatch (Phase 15)

Lines: 2257-2305 (`mcm == 1/2/3/4`).

```
- PASSED: mcm == 1 [./MovieClip.as:2257]
+ FAILED: expected: 1 obtained: 0
```

Test does something like `mc.method = function(){ mcm++; };` and
then invokes via various dispatch paths (`mc.method()`,
`mc.method.call(mc)`, `mc.method.apply(mc)`). `mcm` stays 0 — the
method isn't being called at all. Likely the function lookup on the
MC fails because the assignment didn't land where the lookup looks.

Closely related to Phase A.

### P. _visible cascading (Phase 16)

Lines: 2343, 2345, 2347, 2349.

```
- PASSED: vis._visible == false [./MovieClip.as:2343]
+ FAILED: expected: false obtained: true
```

After setting `parent._visible = false`, `child._visible` should
also read false. We are not cascading. Note: Flash's behaviour here
is actually that `_visible` on a child reports its OWN flag (not the
cascaded), but the test expects cascaded — verify whether Ruffle
cascades or not before fixing.

### Q. _quality setter 'BEST' (Phase 17)

Lines: 2419, 2420, 2421.

```
- PASSED: r._quality == "BEST" [./MovieClip.as:2419]
+ FAILED: expected: "BEST" obtained: HIGH
- PASSED: r._highquality == 2 [./MovieClip.as:2420]
+ FAILED: expected: 2 obtained: 3
```

`_quality = "BEST"` should set quality to BEST (`_highquality == 2`).
We don't accept BEST. Quality values: LOW=0, MEDIUM=4 (or 1?), HIGH=1,
BEST=2 — verify the integer mapping; the line 2420 expected `2` for
BEST suggests BEST maps to `_highquality == 2`.

## Recommended fix order

1. **Phase 1 + Phase 15 + Phase 2** — prototype-method visibility
   and getSWFVersion likely share a single root cause (something in
   the MovieClip prototype-lookup or per-MC swf version). Diagnose
   together. Estimate: 2-3 hours.
2. **Phase 13 (setProperty action return value)** — single bytecode
   handler fix, unblocks ~25 lines mechanically. Estimate: 1-2 hours.
3. **Phase 5 (renamed-parent _target propagation)** — small fix in
   the _target getter (compute on read instead of cache). Estimate:
   1 hour.
4. **Phase 4 (_soundbuftime is per-root)** — move from per-MC
   storage to a global. Estimate: 30 min.
5. **Phase 17 (_quality BEST)** — small enum addition. Estimate:
   30 min.
6. ~~**Phase 11 (_yscale sign preservation)**~~ — NOT ACTIONABLE
   (2026-05-23). Ruffle's output also reads `obtained: -50`, so the
   line is already common to both diffs and doesn't block
   ruffle_matched promotion. See section K for the full reasoning.
7. **Phase 7 (unloadMovie keeps typeof movieclip)** — small.
   Estimate: 1 hour.
8. **Phase 9 + 10 + 12 (getBounds reference-clip transform, scale,
   plain-Object identity)** — likely the same code path. Tackle
   together. Estimate: 3-4 hours.
9. **Phase 8 (getBounds undefined fallback)** — small after Phase 9.
   Estimate: 30 min.
10. **Phase 14 (mc.addProperty for MC props)** — touches MC virtual
    property dispatch; coordinate with AVM1 `addProperty` /
    `watch_textfield` regression battery. Estimate: 2-3 hours.
11. **Phase 16 (_visible cascading)** — verify against Ruffle first
    (could be ACCEPTED_DIFFS). Estimate: 1-2 hours.
12. **Phase 6 (soft/hard reference semantics)** — biggest cluster,
    save for last; needs careful diagnosis since it touches
    soft_reference_test1 (already RM in misc-swfc) and similar
    tests. Estimate: 4-6 hours.
13. **Phase 3 (hitTest registration)** — 30 min once Phase 1's
    prototype-method visibility is fixed.

Total estimate: 18-26 hours, 5-7 sessions.

## Promotion plumbing

All three tests have `known_failure = true` + `output.fpN.ruffle.txt`
sidecars. Closest to threshold is v6 at 83% — phases 1, 13, 5, and
9-10 should be enough to push to ruffle_matched if the diffs
become a subset of Ruffle's diff against expected.
