# bitmap_data_thorough/* Plan
<!-- TESTS: bitmap_data_thorough/colorTransform, bitmap_data_thorough/compare, bitmap_data_thorough/constructor, bitmap_data_thorough/copyChannel, bitmap_data_thorough/copyPixels, bitmap_data_thorough/fillRect, bitmap_data_thorough/floodFill, bitmap_data_thorough/getColorBoundsRect, bitmap_data_thorough/getPixel, bitmap_data_thorough/getPixel32, bitmap_data_thorough/hitTest, bitmap_data_thorough/merge, bitmap_data_thorough/noise, bitmap_data_thorough/paletteMap, bitmap_data_thorough/perlinNoise, bitmap_data_thorough/pixelDissolve, bitmap_data_thorough/scroll, bitmap_data_thorough/setPixel, bitmap_data_thorough/setPixel32, bitmap_data_thorough/threshold -->

Tests: `ruffle-tests/tests/swfs/avm1/bitmap_data_thorough/*` (20 sub-tests)

Status after session 3 fixes (2026-04-17): **18 / 20 effective pass** (16 pass + 2 ruffle_matched). Remaining 2 (pixelDissolve, perlinNoise) both have `known_failure` markers upstream and need Flash-oracle data to fix.

| Sub-test | Initial | After scope fix | After per-method fixes | Session 3 |
|----------|---------|-----------------|------------------------|-----------|
| `compare` | 42.0% | 100% PASS | **PASS** | **PASS** |
| `hitTest` | 54.9% | 98.8% | **PASS** (100%) | **PASS** |
| `getColorBoundsRect` | 83.5% | 97.5% | **PASS** (100%) | **PASS** |
| `getPixel` / `getPixel32` | 78.7% | 89.4% | **PASS** (100%) | **PASS** |
| `fillRect` | 2.6% | 71.3% | **PASS** (100%) | **PASS** |
| `scroll` | 2.6% | 76.6% | **PASS** (100%) | **PASS** |
| `colorTransform` | 2.9% | 76.7% | **PASS** (100%) | **PASS** |
| `setPixel` / `setPixel32` | 2.3% | 75.1% | **PASS** (100%) | **PASS** |
| `floodFill` | 2.1% | 77.7% | **PASS** (100%) | **PASS** |
| `merge` | 1.9% | 70.8% | **PASS** (100%) | **PASS** |
| `constructor` | 6.7% | 6.7% | **PASS** (100%) | **PASS** |
| `threshold` | 2.4% | 76.0% | 93.4% | **PASS** (100%) — opaque-bmd getPixel32 raw read + mask-undefined coercion |
| `noise` | 1.9% | 78.3% | 93.9% | **PASS** (100%) — high=undefined coerces to 0; alpha-channel skip when !transparent; ECMA NaN→0 seed |
| `copyPixels` | 1.9% | 73.2% | ruffle_matched (94.3%) | ruffle_matched |
| `paletteMap` | 1.9% | 69.8% | 94.5% | **ruffle_matched** — Object-arg LUT lookup + & 0xFF mask |
| `copyChannel` | 1.8% | 66.9% | 93.4% | **PASS** (100%) — `MAX_BITMAP_NATIVES` 256 → 8192; the side table was overflowing partway through the Opaque iteration, leaving new BMDs unregistered → `bdHeightGetter` returned -1 → `printBmd` loop skipped |
| `pixelDissolve` | 2.0% | 78.4% | 91.8% | improved (~94%) — Flash-specific Feistel/return value behavior |
| `perlinNoise` | 5.1% | 25.4% | 29.6% | 29.6% — algorithm port mismatches (known_failure upstream) |

## Session 3 fixes (2026-04-17)

1. **threshold** (now PASS):
   - `bitmapDataGetPixel32`: opaque BMDs return raw stored pixel (no un-premul); only transparent BMDs un-premultiply. Matches Ruffle `get_pixel32` behavior.
   - `mask` arg defaults to `0xFFFFFFFF` only when missing; `undefined` coerces to `0` per Ruffle AVM1 `try_get_u32(UndefinedAs::Some)`.

2. **noise** (now PASS):
   - `high` arg defaults to `0xFF` only when missing; `undefined` coerces to `0`.
   - Alpha channel RNG only fires for transparent BMDs (not just `channelOptions & 8`). Prevents RNG state divergence on opaque BMDs.
   - Seed/low/high coerced via `doubleToUint32` → cast to `int32_t` so NaN/Infinity → 0 (ECMA ToInt32). Fixes `noise({}, ...)` where `{}` coerces to NaN.

3. **paletteMap** (now ruffle_matched):
   - Treat `OBJECT` (e.g. `{}`) as well as `ARRAY` for channel-array args, looking up numeric-indexed elements via `getPropertyWithPrototype`.
   - Mask each LUT entry with `& 0xFF` (Ruffle's per-channel byte contribution).

4. **pixelDissolve** (improved):
   - Require 5 args minimum (was 4) — `pixelDissolve(src, rect, point, seed)` now returns -1.
   - Validate rect has all `x/y/width/height` props → return -4.
   - Empty source/dest region returns `random_seed` (Flash behavior, not Ruffle's 0).
   - Use `getPropertyWithPrototype` for rect/point fields.

## Remaining issues by sub-test

- **pixelDissolve** (~97%): Flash-specific Feistel return-value semantics differ from Ruffle. Test is `known_failure.panic` upstream (Ruffle panics). Hard to match Flash exactly without a Flash Player oracle. Could mark as accepted diff or generate `output.ruffle.txt` for `ruffle_matched` promotion.
- **perlinNoise** (29.6%): gradient table / noise formula port mismatches Ruffle's exact pixel values. Test is `known_failure = true` upstream. `output.ruffle.txt` exists and our diff may be subset of Ruffle's, but apparently not enough to promote.

## Session 4 fixes (2026-04-17)

- **copyChannel** (now PASS): Bumped `MAX_BITMAP_NATIVES` from 256 to 8192. The `bitmap_data_thorough/copyChannel` test creates ~50 fresh BMDs per top-level iteration (Transparent / Opaque / Disposed), and the side table was full partway through Opaque. Once full, `setBitmapNative` silently drops new entries → `getBitmapNative` returns `NULL` → `bdHeightGetter` returns -1 → the test's `for (var y = 0; y < bmd.height; y++)` doesn't iterate → no rows in the bitmap dump. Five specific calls had this drift, all in the Opaque iteration after the table filled.

## Shared structure

Each sub-test follows the same pattern:

```
ruffle-tests/tests/swfs/avm1/bitmap_data_thorough/<method>/
├── Test.as        (same harness copied into every sub-test)
├── output.txt
├── test.swf       (compiled — SWF version 15)
└── test.toml      (num_frames = 1)
```

`Test.as` defines a thorough per-method harness:

- Module-scope `var` declarations: `disposedBmd`, `transparentBmd`, `opaqueBmd`, `triedSoFar`, `objLooksLikeNum`, `rect`, `rectAsObj`, etc.
- `main()` assigns the bitmaps and iterates:
  - `generateArgSets(goodArgs)` → all combinations of good + bad args
  - `callWithDifferentArgs()` → invokes `object[functionName].apply(object, args)` for each set
  - `valueToString(v)` — prints the test name for known sentinel refs via `v === <sentinel>`, else fallback
- `printBmd(bmd)` dumps the 3x3 pixel grid

The `valueToString` helper is the key to reading the test's output. It compares the value against module-scope sentinels using `===`.

## Cascade root cause — FIXED 2026-04-17

**Actual root cause** (different from the frame-script var hypothesis): `actionCallMethod` in `SWFModernRuntime/src/actionmodern/action.c` — the "empty method name + FUNCTION receiver" path (used when code does `f.apply(this, args)` or direct function invocation via `CallMethod(..., undefined)`) wipes the scope chain (`scope_depth = 0`) before invoking the callee but **never restores the function's `captured_scope[]`**. As a result, nested functions lose access to variables from their enclosing function.

In `fillRect/Test.as`, `main()` defines `createTransparent`/`createOpaque` as local vars, then calls `createDisposed()` (a closure that references `createTransparent`). Our old code wiped the scope chain before calling `createDisposed`, so its `GetVariable "createTransparent"` returned undefined, making `disposedBmd` undefined, making every `valueToString(v)` output match the first `v === disposedBmd` branch (`"disposedBmd"`) instead of the intended `"undefined"` / bitmap name. Every line in the output cascaded.

The fix (committed 2026-04-17): after `scope_depth = 0` in the empty-method-name path, push `func->captured_scope[]` entries onto the scope chain, then allocate and push a fresh local scope object. Mirrors the setup in `actionCallFunction` at line ~46066. Identical fixup applied in both FUNCTION-type-2 and FUNCTION-type-1 branches, with matching `releaseObject` on restore.

Original hypothesis (below, preserved for history) turned out to be wrong — frame-script top-level `var`s and nested writes are fine via our existing string_id var_array path.

## (Historical) Frame-script var capture hypothesis

Confirmed by inspecting fillRect's generated code and comparing expected vs actual output:

- Our actual output prints `disposedBmd` literally where expected prints `undefined`:
  ```
  // fillRect(null, 2557891634)        <- same in both
  disposedBmd                           <- expected: "undefined"  (argStr includes "undefined")
  // fillRect(disposedBmd, 2557891634)  <- our actual
                                         vs expected: // fillRect(undefined, ...)
  ```

- Root cause: `valueToString(undefined)` in our runtime evaluates `undefined === disposedBmd` as **true**, even though in an isolated MTASC-compiled class test (`class Foo { static var x; ... }`) our runtime correctly returns `false`.

- Why: Test.as declares `var disposedBmd;` at *frame-script top level*, then assigns `disposedBmd = createDisposed()` inside `main()`. The recompiler emits `DeclareLocal "disposedBmd"` at script_0 level, which our runtime stores on `root_movieclip.dynamic_props` (see `actionDeclareLocal` at `SWFModernRuntime/src/actionmodern/action.c:31605-31650`). When `main()` later executes `disposedBmd = ...`, our `actionSetVariable` *probably creates a new local in main()'s scope* rather than updating the root MC's dynamic_props slot — so the outer `disposedBmd` stays undefined forever, and `valueToString(undefined)` matches the first `=== undefined` sentinel, which is `disposedBmd`.

- Confirmation bytecode (script_defs.c:1734 — inside func2_valueToString_7):
  ```c
  pushVar(app_context, &regs[1]);         // v
  PUSH_STR_ID(str_5, strlen(str_5), 5);   // "disposedBmd"
  actionGetVariable(app_context);         // resolves "disposedBmd" → undefined  (BUG)
  actionStrictEquals(app_context);        // v === undefined
  ```

### Investigation steps to confirm

1. Write a minimal frame-script-level repro (not an MTASC class):
   ```as
   var outerVar;
   function mainFn() { outerVar = 42; }
   function checkFn(v) { return v === outerVar; }
   mainFn();
   trace("outerVar: " + outerVar);               // expected: 42
   trace("checkFn(42): " + checkFn(42));         // expected: true
   trace("checkFn(undefined): " + checkFn(undefined)); // expected: false
   ```
   MTASC refuses `var` at top level — this needs a real Flash compiler or hand-built SWF (swfmill / custom script). The actual `test.swf` is SWF v15 and was likely built by Flash Pro or a similar AS2 compiler.

2. Inspect `actionSetVariable`'s behavior at `g_call_depth > 0` for a variable that was DeclareLocal'd on `g_current_context->dynamic_props` at `g_call_depth == 0`.
   - Does it find the dynamic_props entry and update it, or does it create a new local in the current function's scope?
   - The correct Flash semantics: frame-script-level `var` is stored as a property on `this` (the timeline MC), and inside functions, identifier access walks through local scope → function caller chain → this.property → global.

3. Check whether our existing frame-script closure tests (`CLOSURE_CAPTURE_PLAN.md`, etc.) specifically cover the write-from-nested-function case. If not, add one.

### Expected fix

Two options:

1. **Emit-time:** have the recompiler treat frame-script top-level `var x;` as a call that registers `x` on the current MC's dynamic_props (which it already does via DeclareLocal), AND have nested `actionSetVariable` check the enclosing MC's dynamic_props before creating a new local.

2. **Runtime:** in `actionSetVariable`, when the name is not found in local scope or WITH scope, look up the name in `g_current_context->dynamic_props` *before* falling back to creating a new global. If found there, update in place.

Option 2 is likely the correct one — it mirrors real AS2 / AVM1 semantics where "timeline locals" are actually properties of the timeline MC.

## Per-test-specific issues (after the cascade fix lands)

### getPixel / getPixel32 (78.7%)

Two distinct bugs:

1. **Premultiplied-alpha round-trip loses 1 LSB per channel.** Expected pixel `0x00BBCCDC`, our actual `0x00BCCDDD` (off-by-one in every channel). Likely path: constructor premultiplies `0xAABBCCDD` → pixels buffer → getPixel32 un-premultiplies → off-by-one. Either use a lookup table for un-premultiplication, or store non-premultiplied pixels and premultiply only at draw time.

2. **Undefined/object args coerced to 0, but expected is same as `(0, y)` or `(x, 0)`.** For `getPixel(undefined, 2)` we return `0`, Ruffle returns the pixel at `(0, 2)`. Our bitmapDataGetPixel should coerce `undefined` → `NaN` → clamp/convert to `0`, then read pixel. Current code likely early-returns `0`.

### getColorBoundsRect (83.5%)

47 diffs out of 285 lines. Likely a mix of edge cases on mask/color argument combinations. Easy to investigate after the cascade fix lands (run the sub-test, diff by section, find the first divergence, fix).

### hitTest (54.9%)

234 diffs out of 519. Needs a walk through the diff to categorize. Possibly:

- Point-as-object vs Point instance handling.
- Alpha threshold comparison edge cases.
- Out-of-bounds behavior.

### compare (42.0%)

40 diffs out of 69. `BitmapData.compare` returns one of `-1, -2, -3, -4, 0, or a difference BitmapData`. The test likely exercises the error-return paths. Check that our implementation matches Flash's return codes for disposed bitmaps, mismatched sizes, etc.

### perlinNoise / noise (5.1% / 1.9%)

PRNG output difference. We implemented perlinNoise via a W3C SVG feTurbulence port (per BITMAPDATA_PERLINNOISE_PLAN.md) — may not match Flash's exact output for the thoroughness harness which uses specific seeds.

## Fix order

1. **Cascade fix first** (frame-script var → nested function write). This should take the 16 low-match sub-tests from ~2-7% to somewhere much higher. Once landed, re-measure.
2. Inspect newly-near-passing sub-tests and fix per-method issues:
   - `getPixel` / `getPixel32` premultiplied-alpha precision.
   - Undefined-arg coercion for coordinate inputs across all methods.
   - Error return codes (-1, -2, -3, -4) from `compare`, `copyChannel`, `paletteMap`, etc.

## Related code

| File | Purpose |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c:31472` | `actionDeclareLocal` — stores frame-script vars on `ctx_mc->dynamic_props` |
| `SWFModernRuntime/src/actionmodern/action.c` — `actionSetVariable` | **Suspected bug site** for the cascade issue |
| `SWFModernRuntime/src/actionmodern/action.c:29156` | `actionGetVariable` — would need to check the same dynamic_props when resolving names in nested functions |
| `SWFModernRuntime/src/actionmodern/action.c:9354` | `bitmapDataFillRect` — returns UNDEFINED; Flash/Ruffle return `-1` or `0`. Minor. |
| `SWFModernRuntime/src/actionmodern/action.c:9280-9350` | `bitmapDataGetPixel*` — premultiplied-alpha round-trip and undefined-arg paths |

## Open questions

1. Is the cascade root cause actually frame-script write-from-nested-function, or is there a different shared blocker? Verify with a targeted minimal repro before committing to the fix.
2. Once the cascade is fixed, how many of the 16 sub-tests climb to >=90% match? If all do, the remaining per-method fixes can be scheduled independently.
3. Does Ruffle itself pass all 20 sub-tests in their CI? If some are `known_failure` upstream, we may be able to rely on `ruffle_matched` auto-promotion for those rather than fixing our runtime — but verify before assuming.
