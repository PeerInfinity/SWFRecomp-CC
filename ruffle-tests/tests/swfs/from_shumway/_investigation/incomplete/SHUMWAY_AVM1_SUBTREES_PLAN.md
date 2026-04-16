# Shumway avm1/ Sub-tree Failures Plan
<!-- TESTS: bitmapdata/loadBitmap, doactionorder/doactionorder, duplicateMovieClip/dontremove, duplicateMovieClip/duplicateMovieClip, duplicateMovieClip/name-coercion, duplicateMovieClip/samedepth, haxe/flocons2, loadvariables/loadvars, property-paths/property-paths-6, propertycase/propertycase-preserving-6, textfield/textfield-html, textfield/textfield-text-setters, xml/xmlload, avm1/bitmapdata/loadBitmap, avm1/doactionorder/doactionorder, avm1/duplicateMovieClip/dontremove, avm1/duplicateMovieClip/duplicateMovieClip, avm1/duplicateMovieClip/name-coercion, avm1/duplicateMovieClip/samedepth, avm1/haxe/flocons2, avm1/loadvariables/loadvars, avm1/property-paths/property-paths-6, avm1/propertycase/propertycase-preserving-6, avm1/textfield/textfield-html, avm1/textfield/textfield-text-setters, avm1/xml/xmlload -->

The Shumway `avm1/` test suite grew 23 → 47 tests between `from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md` (finished 2026-04-11) and the 2026-04-16 CI run. The new tests live in category sub-trees that weren't triaged in the earlier plan.

The TESTS list above includes both bare names (matching `from_shumway/avm1/_results/results.json`) and `avm1/`-prefixed names (matching `from_shumway/_results/results.json`) so the coverage index resolves in both suites.

Location: `ruffle-tests/tests/swfs/from_shumway/avm1/<category>/<name>`

Status (CI at 82a6ea07): 14 output_mismatch failures across 10 categories. 1 ruffle_matched (`hitarea`) already passes filtered. Running in-suite via:

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
