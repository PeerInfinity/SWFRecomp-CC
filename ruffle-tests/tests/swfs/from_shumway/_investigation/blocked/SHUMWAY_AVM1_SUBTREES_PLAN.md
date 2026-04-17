# Shumway avm1/ Sub-tree Failures Plan
<!-- TESTS: bitmapdata/loadBitmap, doactionorder/doactionorder, duplicateMovieClip/dontremove, duplicateMovieClip/duplicateMovieClip, duplicateMovieClip/name-coercion, duplicateMovieClip/samedepth, haxe/flocons2, loadvariables/loadvars, property-paths/property-paths-6, propertycase/propertycase-preserving-6, textfield/textfield-html, textfield/textfield-text-setters, xml/xmlload, avm1/bitmapdata/loadBitmap, avm1/doactionorder/doactionorder, avm1/duplicateMovieClip/dontremove, avm1/duplicateMovieClip/duplicateMovieClip, avm1/duplicateMovieClip/name-coercion, avm1/duplicateMovieClip/samedepth, avm1/haxe/flocons2, avm1/loadvariables/loadvars, avm1/property-paths/property-paths-6, avm1/propertycase/propertycase-preserving-6, avm1/textfield/textfield-html, avm1/textfield/textfield-text-setters, avm1/xml/xmlload -->

The Shumway `avm1/` test suite grew 23 → 47 tests between `from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md` (finished 2026-04-11) and the 2026-04-16 CI run. The new tests live in category sub-trees that weren't triaged in the earlier plan.

The TESTS list above includes both bare names (matching `from_shumway/avm1/_results/results.json`) and `avm1/`-prefixed names (matching `from_shumway/_results/results.json`) so the coverage index resolves in both suites.

Location: `ruffle-tests/tests/swfs/from_shumway/avm1/<category>/<name>`

Status (2026-04-17, second session baseline): 2 failing / 14 — 12 clusters now fully green. Both remaining tests need non-trivial architectural work in the recompiler/runtime and are moved to `blocked/`. See "Progress (2026-04-17 session 2)" at bottom. 1 ruffle_matched (`hitarea`) already passes filtered. Running in-suite via:

```bash
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/from_shumway \
  --test=avm1/<category>/<name> --diff
```

## Per-cluster breakdown

### Cluster 1: `duplicateMovieClip/` (4 tests)

| Test | Match | Failure shape |
|------|-------|---------------|
| `duplicateMovieClip` | 1/4 | Clone MC's `_y`, `_height`, `_width` all return `0` instead of `51`, `50`, `100` from `duplicateMovieClip(name, depth, initObj)`. |
| `name-coercion` | 1/3 | Test checks name coercion via `===` on some MC property; we return `false` where Ruffle returns `true`. |
| `dontremove` | 3/6 | `_target` traces return `undefined` for MCs created via `attachMovie` — should be `_level0.test`, `_level0.test1`, etc. |
| `samedepth` | 4/6 | Same `_target → undefined` issue when a duplicate is placed at the same depth. |

Unifying hypothesis: **our `duplicateMovieClip` implementation doesn't apply the `initObject` parameter to the new clone**, AND **`_target` on duplicated/attached MCs isn't tracking the full flash path**.

Investigation steps:
1. Find our `duplicateMovieClip` implementation (grep `SWFModernRuntime/src/actionmodern/action.c` for `duplicateMovieClip`).
2. Compare with Ruffle's `core/src/avm1/globals/movie_clip.rs` to see how they walk `initObject.__proto__` chain and apply virtual property setters.
3. For `_target`: check that attaching/duplicating MCs correctly sets `instance_name` and that `_target` getter walks up through parent sprites to build the `_level0.foo.bar` path.

Reference: existing AVM1 `MOVIECLIP_PLAN.md`, `REGISTERCLASS_PLAN.md` (both complete) — this extends attach/duplicate semantics.

### Cluster 2: `textfield/` (2 tests)

| Test | Match | Failure shape |
|------|-------|---------------|
| `textfield-html` | 3/4 | First `<a>foo</a>` prints, second prints empty. Missing second htmlText read or `htmlText =` assignment round-trip. |
| `textfield-text-setters` | 4/8 | `typeof tf.text` after setting to `undefined` / `null` should be `"string"` (Flash coerces to "undefined"/"null" strings), but we return the original type. |

Fix for `textfield-text-setters`: TextField.text setter must coerce any input to string (including `undefined` → `"undefined"`, `null` → `"null"`). Look for `tfSetText` / `TextField.text` setter in `SWFModernRuntime/src/actionmodern/action.c`. Small fix.

Fix for `textfield-html`: Needs a small repro to isolate whether it's `htmlText` getter idempotence or an assignment cycle issue.

### Cluster 3: `property-paths/property-paths-6` (1 test, 5/6)

Expected `2, TeSt, 1, tEst, 1, tEst`; we get the first four lines correct then `undefined, tEst`. Line 5 is expected `1` (property lookup succeeds), we return `undefined`.

Likely: some case-variant access to a property (e.g., `mc.TeSt` vs `mc.tEst`) in SWF6 case-preserving mode. Related to cluster 4.

### Cluster 4: `propertycase/propertycase-preserving-6` (1 test, 0/2)

Expected:
```
MIXEDcase 4
mixedCase 5
```

Actual:
```
MixEdcase 4
MIXEDcase 4
MixEdcase 5
mixedCase 5
```

Our runtime emits extra lines AND uses a different case variant. In SWF6, property names preserve case on lookup but are case-insensitive for matching. When multiple case variants are written, the original case of the *first* write is kept. It looks like we're either:
- Preserving each written variant separately (producing one line per variant), instead of coalescing.
- Matching case-insensitively but printing the wrong preserved variant.

Investigation: find `g_swf_version` gating around property name case preservation in `object.c` / `setProperty` / `getProperty`. Compare with Ruffle's `crate_avm1/property_map.rs`.

### Cluster 5: `haxe/flocons2` (1 test, 2/3)

Expected:
```
Test
Test
Done
```

Actual:
```
Test
undefined
Done
```

Single missing trace — second `Test`. Likely a closure or prototype inheritance edge case in code generated by Haxe-to-SWF. Possibly related to how Haxe constructs classes via `_global` assignment and inheritance chains.

Investigation: inspect the test's Test.as (if shipped) or decompile test.swf. Low-priority (1 line of 3).

### Cluster 6: `doactionorder/doactionorder` (1 test, 3/7)

Expected order:
```
root1
sym1: _level0.sym1
test1: undefined
sym1
root2
sym1: _level0.sym1
test2: hello
```

Actual:
```
root1
sym1: _level0.sym1
test1: undefined
root2                   <- out of order
sym1: _level0.sym1
test2: undefined        <- should be "hello"
sym1                    <- out of order
```

Two issues:
1. **Execution order**: `sym1` (symbol DoAction?) is traced *after* `root2`, but should be *before* and then *again* as part of `test2:` resolution.
2. **Variable persistence**: `test2: undefined` instead of `"hello"` — a variable set in one DoAction is not visible to a later DoAction.

This is a DoAction sequencing / execution-order issue. Probably related to sprite DoInitAction vs DoAction timing. Reference: complete `AVM1 SESSION_NOTES.md` for prior `execution_order*` fixes — this may be a new corner case.

### Cluster 7: `loadvariables/loadvars` (1 test, 0/2)

Expected:
```
loaded true
var1: test
```

Actual: empty.

`loadVariables` or `LoadVars.load()` isn't firing the onLoad/onData callback. Check whether the test has a sibling data file (`*.txt`) that `verify_output.py`'s data_registry picks up. May be a registry lookup miss or URL encoding issue.

Related: AVM1 LOADVARIABLES_PLAN.md (complete). This is a new corner case.

### Cluster 8: `bitmapdata/loadBitmap` (1 test, 0/3)

Expected:
```
1
1
(x=0, y=0, w=1, h=1)
```

Actual:
```
undefined
undefined
undefined
```

`BitmapData.loadBitmap(exportName)` returns undefined. The test likely uses a tiny 1x1 pixel bitmap export. Either the export isn't registered, or our `bitmapDataLoadBitmap` can't resolve it.

Related: existing `LOADBITMAP_PLAN.md` (complete) covers exportName lookups. New test may use a slightly different export mechanism.

### Cluster 9: `xml/xmlload` (1 test, 0/4)

Expected:
```
data: 18 string
load: true true
bytes: 18/18
xml: <test>data</test>
```

Actual:
```
load: true true
bytes: undefined/undefined
xml: <test>data</test>
```

Two issues:
1. First line missing — `XML.onData(data)` where data is raw bytes gives `data: 18 string` (length + typeof). Our `onData` dispatch likely skips the raw payload and goes straight to parse.
2. `xml.loaded` / `xml.getBytesLoaded()` / `getBytesTotal()` return undefined where expected `18/18`.

Related: existing `XML_PLAN.md` (complete). New test exercises the `onData(src)` hook and bytes tracking.

### Cluster 10: `moviecliploader` (1 test, 1/7)

Frame-ordering issue. Expected:
```
loading started
loader frame 2          <- async: next frame tick before onLoadStart
onLoadStart _level0.content
onLoadComplete _level0.content
loadee frame 1
onLoadInit _level0.content
loadee frame 2
```

Actual:
```
loading started
onLoadStart _level0.content   <- fires immediately, ahead of loader's frame 2
onLoadComplete _level0.content
loadee frame 1
onLoadInit _level0.content
loader frame 2                <- fires at end
```

MovieClipLoader event timing: real Flash defers `onLoadStart` by (at least) one frame tick. We fire it synchronously. This is a non-trivial timing fix.

Related: existing `MOVIECLIPLOADER_PLAN.md` (complete). This is a new edge case about the *exact* frame on which `onLoadStart` should fire.

## Recommended fix order

Small, tractable, likely-cheap first:

1. **`textfield/textfield-text-setters`** — TextField.text setter coerces to string. ~10 lines.
2. **`haxe/flocons2`** — 1 missing trace, may be small.
3. **`property-paths/property-paths-6`** — 1 diff, likely same root cause as propertycase-preserving-6.
4. **`propertycase/propertycase-preserving-6`** — SWF6 property case preservation. Known feature, likely a small gating bug.

Medium:

5. **`duplicateMovieClip/*`** (4 tests, 1 fix) — initObject application + `_target` tracking on duplicated MCs.
6. **`textfield/textfield-html`** — htmlText round-trip. Needs repro.
7. **`bitmapdata/loadBitmap`** — exportName resolution, extend existing LOADBITMAP_PLAN.
8. **`xml/xmlload`** — extend XML_PLAN with `onData` raw payload + `getBytesLoaded` / `getBytesTotal`.
9. **`loadvariables/loadvars`** — likely data_registry miss. Check with `--verbose`.

Larger/blocked:

10. **`doactionorder/doactionorder`** — DoAction execution-order regression. Needs careful investigation against Ruffle's order.
11. **`moviecliploader`** — MCL event deferral. Needs Ruffle source comparison and frame-timing work.

## Open questions

- Are any of these tests already marked `known_failure=true` in upstream Shumway or Ruffle? Check each sub-test dir for `output.ruffle.txt` — if present, we can rely on `ruffle_matched` auto-promotion for the harder ones (`moviecliploader`, `doactionorder`).
- Two tests currently report `ruffle_matched` in avm1/ (and 1 in flat): `avm1/hitarea`. Any other auto-promotable candidates after adding `output.ruffle.txt`?
- `hitarea` is a Ruffle known_failure. What are the diffs there? If trivial, consider whether we can actually match Flash rather than Ruffle.

## Progress (2026-04-16)

Passing (9/14 previously failing tests now green; confirmed locally, pending CI):

- `textfield/textfield-text-setters` — TextField text/htmlText setter coerces non-string values to string; htmlText getter skips HTML serialization when `html=false` so plain-text setters round-trip.
- `textfield/textfield-html` — fell out of the same fix above.
- `haxe/flocons2` — `createEmptyMovieClip` no longer overwrites an existing own-property / root timeline variable with the same name as the new child, matching Ruffle's display-list-only attachment.
- `propertycase/propertycase-preserving-6` — SWF ≤ 6 `for...in` dedup is case-insensitive across prototype + own.
- `property-paths/property-paths-6` — `GetVariable` slash-path walk now handles `/obj:prop.sub` when `obj` is a plain ScriptObject reached via `GetVariable`. (Skipped when target ends in `:` to preserve `path_string` compatibility.)
- `duplicateMovieClip/name-coercion` — `duplicateMovieClip` target-name coercion now runs through convertString / objectCallToString for `null`, `undefined`, numbers, etc.
- `duplicateMovieClip/duplicateMovieClip` — initObject is applied via `applyInitObjectPropToMC`, so MC builtins (`_x/_y/_width/_height/…`) and prototype-chain addProperty setters route correctly. Still fails 2/4 on `_width`/`_height` (see below).
- `xml/xmlload` — `XML.load` fires `this.onData(raw)` and records `_bytesLoaded/_bytesTotal`; added `builtin_xml_onData` as the default prototype method that parses and fires `onLoad(true)`.
- `loadvariables/loadvars` — `LoadVars.load` is no longer a stub; it fetches the data file, URL-decodes each pair into own properties, sets `_bytesLoaded/_bytesTotal`, marks `loaded=true`, and dispatches `onLoad(success)`.
- `bitmapdata/loadBitmap` — `defineBitmap` in NO_GRAPHICS builds now registers bitmap metadata via a shared `ng_registerBitmapMetadata`, so `BitmapData.loadBitmap(export)` resolves dimensions and the rectangle getter works.

Still failing (5/14):

- `duplicateMovieClip/duplicateMovieClip` (2/4 → 2/4 remaining) — clone's `_width`/`_height` are `0` instead of `100`/`50`. Ruffle's `clone_sprite` for a dynamically created MC does NOT copy children; container's width/height therefore comes from its dynamic children via `bounds_with_transform`, and an empty clone should reflect the source's bounds. Our `mcGetOriginalBounds` fallback over `child_mc_cache` only walks children of `mc` — the clone has none, so both dimensions resolve to 0. Needs a different source of bounds for dynamic MC clones (possibly snapshotted bounds, or a copy of the child-derived AABB at clone time).
- `duplicateMovieClip/dontremove` (3/6) — `GetVariable("test")` returns undefined even for the timeline-placed MC. The DuplicateSprite side-effect somehow breaks name resolution for the original at the root level. Suspected: `ng_cloneSprite` may be clobbering/shadowing the source's display-list or var-map entry (worth checking `instance_name_owned` handling after copy, and any write to `setVariableByName` for the source name). Needs a focused repro.
- `duplicateMovieClip/samedepth` (4/6) — `getInstanceAtDepth(AS-depth)` fails to find clones placed via `DuplicateSprite` at SWF depth 32769 (AS depth 16385). Likely a depth-space translation issue in our `getInstanceAtDepth`; compare with Ruffle's `child_by_depth` using `AVM_DEPTH_BIAS`.
- `doactionorder/doactionorder` (3/7) — DoAction sequencing: `sym1` tag action runs after `root2` instead of before, and a variable set in an earlier DoAction (`test2 = "hello"`) is not visible to a later one. Likely interacts with `g_sprite_init_filter_active` / `g_defer_sprite_init` from the 3-phase goto ordering; needs a targeted repro.
- `moviecliploader` (1/7) — `onLoadStart` fires synchronously during `loadMovie`/`loadClip` instead of deferring to the next frame tick. Needs to schedule the MCL event sequence across frames to match Ruffle's real Flash-player-style timing.

## Handoff notes

- Fix order for the next session: start with `duplicateMovieClip/samedepth` (likely a small depth-bias bug) and `dontremove` (name-resolution after clone). `moviecliploader` and `doactionorder` are the larger/blocked items.
- `xml_getbytes` in the Ruffle AVM1 suite is unchanged by this session's XML work — it was already failing because our sync-load model collapses the two-phase "before onData → after onData" state that the test polls.

## Progress (2026-04-17)

Three more tests fixed this session (confirmed locally, pending CI):

- `duplicateMovieClip/samedepth` — `getInstanceAtDepth(depth)` had no global-function handler, so calling it at timeline level fell through to the unimplemented `g_mc_method_funcs` slot and always returned `undefined`. Added a global handler in `actionCallFunction` that operates on `g_current_context`. To cope with the mixed depth-space convention (attachMovie/createEmptyMovieClip store AS depth; CloneSprite/duplicateMovieClip store SWF-biased depth), both the new global handler and the existing method handler now accept either AS-depth or SWF-depth matches when scanning `child_mc_cache`.
- `duplicateMovieClip/duplicateMovieClip` — `ng_duplicateMovieClip` was not copying Drawing-API bounds (`draw_has_bounds`, `draw_xmin/xmax/ymin/ymax`) from the source. When cloning a dynamic MC built via `createEmptyMovieClip` + `lineTo`/`beginFill`, the clone is born with no children, so `mcGetOriginalBounds` fell through to the child-MC bounds walk and returned 0 for both dimensions. Added the five-field copy so the clone reflects the source's accumulated draw bounds. (Earlier attempt also normalized `ng_cloneSprite{,FromMC}` to store AS-depth, but that regressed `textsnapshot_available_text`; the `getInstanceAtDepth` both-depths check avoids needing the storage-side normalization.)
- `duplicateMovieClip/dontremove` — two bugs: (1) `actionDefineLocal`/`actionSetVariable` were trusting `string_id` at stack slot +12 even when the name slot type wasn't STRING. The `PUSH(type, value)` macro only writes +0/+4/+16, so +12 still held the *previous* owner's string_id. When `Push undef; Push undef; DefineLocal` ran on a stack slot that previously held `Push "test"` (string_id 2), the DefineLocal wrote `undefined` into `var_array[2]` — clobbering the `test` global. Fixed both opcodes to ignore `string_id` unless the name slot's type is STRING. (2) `actionRewindCleanup` (called on backward `GotoFrame`) was wiping ALL dynamically-created MCs, including `CloneSprite` clones at high SWF depths. Ruffle preserves clones above the AS positive range across backward goto; gated the wipe on `ch->depth < 16384` so SWF-space clones persist.

Now failing (2/14):

- `doactionorder/doactionorder` (3/7) — unchanged. Likely a recompiler-level ordering issue: the generated `frame_0` hoists all `tagPlaceObject2` calls before the per-script calls, but in this test the first root `DoAction` tag appears *before* the sprite's `PlaceObject2` in the SWF, and Ruffle queues both into a single execution list so the sprite's own `DoAction` executes *between* the two root `DoAction`s. Fix likely needs recompiler work in `SWFRecomp/src/action/action.cpp` / `swf.cpp` to preserve tag order for `DoAction` vs `PlaceObject2` within a frame.
- `moviecliploader` (1/7) — unchanged; still a frame-scheduling problem, not a simple dispatch ordering one.

## Progress (2026-04-17 session 2) — blockers documented

No new fixes this session. Confirmed baseline: 2 failing locally and in CI (`db6a0198`).

### Blocker 1: `doactionorder/doactionorder` (3/7) — FIFO DoAction/sprite interleaving

**Observed diff**
```
expected:                         actual:
root1                             root1
sym1: _level0.sym1                sym1: _level0.sym1
test1: undefined                  test1: undefined
sym1                              root2                  <-- root DoAction #2 runs too early
root2                             sym1: _level0.sym1
sym1: _level0.sym1                test2: undefined       <-- sym1.test not yet set
test2: hello                      sym1                   <-- sprite DoAction runs last
```

**Root cause (in recompiler)**
`SWFRecomp/src/swf.cpp` queues root `SWF_TAG_DO_ACTION` script calls and flushes them at the `SWF_TAG_SHOW_FRAME` site — so the generated `frame_0` body is:
```
<all tagPlaceObject2 calls>
script_0(app_context);  // root DoAction #1
script_2(app_context);  // root DoAction #2
tagShowFrame(app_context);
```
then `tagShowFrame` → `process_sprite_needs_init` runs the sprite's Phase 2 scripts (including `script_1`) LAST. That yields order: `root1 → root2 → sprite`.

**Ruffle model**
Ruffle's `ActionQueue` is FIFO across all sources. The sprite's own `DoAction` is queued when the sprite's `PlaceObject2` is processed (inside the sprite's frame tag stream). So the queueing order is `script_0` → `script_1` → `script_2`, and the flush order is the same.

**What a fix looks like**
Two coupled changes:
1. **Recompiler (`SWFRecomp/src/swf.cpp` `SWF_TAG_DO_ACTION` case and the flush loops at ShowFrame / END_TAG)** — emit each root `script_N(app_context)` call INLINE at the point the DoAction tag is parsed (not batched at ShowFrame). Remove (or restrict to sprite-only) the `last_queued_script < next_script_i` flush loops around lines 548–555 / 807–815 / 861–868.
2. **Runtime (`SWFModernRuntime/src/libswf/tag.c` `tagPlaceObject2`)** — after the existing Phase 1 eager init (lines 3401–3432), also run Phase 2 (scripts) inline for the just-placed sprite, then clear `sprite_needs_init` so `tagShowFrame`'s `process_sprite_needs_init` won't re-run it. Needs care to replicate the tail-end housekeeping in `process_sprite_init_at_depth` (onLoad clip events, `ng_fire_pending_loads`, `actionFlushPendingOnLoads`, `actionFirePendingLoadInits`, `upgrade_sprite_initialized`, etc.).

**Risk**: this changes the global ordering of DoAction vs sprite scripts across all tests. Many currently-passing tests may depend on the current (non-FIFO) ordering either by accident or by design. A sweep of `execution_order*`, `goto_execution_order*`, `issue_*`, and `clip_events` tests is required before committing.

### Blocker 2: `moviecliploader` (1/7) — one-frame deferral of `onLoadStart`

**Observed diff**
```
expected:                         actual:
loading started                   loading started
loader frame 2                    onLoadStart ...        <-- fires at same-frame ShowFrame
onLoadStart ...                   onLoadComplete ...
onLoadComplete ...                loadee frame 1
loadee frame 1                    onLoadInit ...
onLoadInit ...                    loader frame 2         <-- fires at next-frame tick
loadee frame 2                    <end>
```

**Root cause**
`actionLoadClip` queues the load into `g_pending_mcl_loads`; `tagShowFrame` of the SAME frame calls `actionFirePendingLoadInits`, which fires `onLoadStart` → `onLoadComplete` → child init + frame 0 → `onLoadInit` all in one go. Expected: `onLoadStart` should fire on the NEXT frame tick (after the loader MC has advanced to and executed frame 2).

**What a fix looks like**
Real Flash's MovieClipLoader spreads the event sequence across ≥2 frame ticks:
- Tick T (loadMovie call): no MCL events.
- Tick T+1: the LOADER's frame tag script runs (so `loader frame 2` traces), THEN `onLoadStart`/`onLoadComplete` fire, THEN the loadee's first frame runs (so `loadee frame 1` traces), THEN `onLoadInit` fires.
- Tick T+2+: loadee frame advances continue (`loadee frame 2`).

Possible implementation path:
- Split `g_pending_mcl_loads` into two lists: `g_mcl_loads_next_tick` (queued by loadMovie/loadClip in the CURRENT frame) and `g_mcl_loads_firing` (promoted at the START of the next frame's tick).
- At the start of each frame's tick (before any `frame_N` script runs), move entries from `next_tick` into `firing`.
- `firing` entries drive `actionFirePendingLoadInits` — but that itself must run AFTER the loader's frame tags have executed for the new frame, so call it from the same slot in `tagShowFrame` as today.
- Audit other MCL tests (`movieclipLoader_events`, `loadclip_*`) before/after the change.

**Risk**: timing change affects every MCL-based test. Probably requires net-positive adjustments to `MOVIECLIPLOADER_PLAN.md` (marked `complete/`) and a full local Ruffle-suite dry run before commit.

## Handoff

Leaving at 2/14 failing. Both items need coordinated recompiler + runtime work that touches broadly-exercised codepaths, and fall outside the scope of the "fix the sub-tree failures" plan. Moving this file to `blocked/` so a future session picks it up deliberately.

