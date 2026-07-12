# Session prompt — AVM2 Stage 7: embedded assets + BitmapData/Bitmap

You are implementing **Stage 7** of the AVM2 Seedling-directed plan
(`SWFRecompDocs/plans/avm2-seedling-plan.md`): the embedded-asset
pipeline (DefineBitsLossless/2 pixels, DefineBinaryData bytes,
DefineSound metadata) and flash.display.BitmapData/Bitmap at
trace-level correctness. This is the single biggest blocker for
Seedling (FlashPunk blit renderer: copyPixels/fillRect/setPixel32/
getPixel32/colorTransform/lock/unlock/draw/applyFilter/hitTest over
284 embedded bitmaps and 491 SymbolClass asset bindings).

Read the plan first, then
`ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`, then
the memories `seedling-avm2-readiness` / `avm2-stage6-text` /
`avm2-stage5-display` (the Stage-6 one has the debug-loop and
SymbolClass-binding gotchas), then skim the code seams below.

Stage 6 landed at `45a507da5`..`b92420ce2`. CI baseline: **avm2
727/1201 + 21 ruffle_matched = 748 effective (62.3%)**, run
29180816425; zero regressions anywhere; wasm-link-smoke green.

## Goal

Candidate list (31 names, all failing at the baseline):
`ruffle-tests/tests/swfs/avm2/_investigation/STAGE7_CANDIDATES.txt`
— Bitmap display object 7, BitmapData core 23, loader-adjacent 1.
~20 more bitmapdata_* tests are image-only (vacuous trace passes) —
keep them compiling/running; their pixels get graded in Stage 9.

Exit: **>=22 of the 31 candidates passing in CI; every miss triaged**;
zero pass->fail regressions anywhere (the avm2 748-effective baseline
must stay green). If you stop at a tranche boundary, refresh THIS
prompt with precise resume state (the Stage-3..6 convention) and
record the CI baseline you reached.

## Code seams (what exists today)

- `SWFRecomp/src/abc/abc_timeline.cpp` — the AVM2 static-table second
  pass. It already records DefineBitsLossless/2 WIDTH/HEIGHT as
  CharInfo bounds (kind BITMAP) but discards pixels; DefineBinaryData
  (tag 87) and DefineSound (tag 14) are unhandled. Add:
  - `avm2_generated_bitmaps`: char_id, width, height, transparency,
    and DECODED ARGB pixel data (decode zlib + 8/15/24-bit formats at
    RECOMPILE time — port `decode_define_bits_lossless` from Ruffle
    `render/src/utils.rs:266`; premultiplied-alpha questions: Ruffle
    stores straight RGBA in `BitmapData` pixel space — check
    to_rgba/from operations.rs first). Emit as compact byte arrays
    (282 images in Seedling — watch generated-file size; consider
    zlib-recompressed blobs + runtime inflate via the zlib already
    linked for ByteArray.compress).
  - `avm2_generated_binaries`: char_id + raw bytes (ByteArray seed).
  - `avm2_generated_sounds`: char_id + format/rate/size metadata (the
    audio DATA can wait for Stage 10; emit offsets or skip payloads).
  - zlib is already a recompiler dependency (SWF decompression) — the
    lossless decode can reuse it.
- `SWFModernRuntime/src/avm2/avm2_display.c` — SymbolClass binding
  machinery: `char_for_class` (exported as
  `avm2_display_char_for_class`) maps a class to its bound char id;
  `display_native_init` is the alloc hook pattern; Font (avm2_text.c
  `font_native_init`) is the model for "non-display class whose
  SymbolClass-bound subclass constructs its asset".
- New runtime file: `SWFModernRuntime/src/avm2/avm2_bitmap.c` — add to
  verify_output.py `compile_native`'s avm2 list (the one allowed edit
  there). BitmapData pixel store lives in native_ext; Bitmap is a
  DisplayObject (extends DisplayObject, NOT InteractiveObject) whose
  native_init must run display_native_init semantics — mirror how
  TextField wires `avm2_text_edittext_init` from the display alloc
  hook, and how `instantiate_child`/`replace_child_character` seed
  per-char state (Bitmap timeline placement = bitmap_timeline test).
- ByteArray already exists (`avm2_bytearray.c`,
  `avm2_bytearray_ext_of`, growable storage) — get/setPixels and
  copyPixelsToByteArray plug into it. Vector.<uint> exists
  (avm2_vector.c) for get/setVector.
- flash.geom.Rectangle/Point are minimal slot classes (Rectangle in
  avm2_text.c, Point in avm2_globals.c) — BitmapData methods take
  them as args; read slots directly (x/y/width/height at slots 1..4).
  The 8-slot ColorTransform (avm2_display.c) feeds colorTransform().
- GC note: BitmapData pixel buffers via avm2_alloc are immortal for
  now (Stage-11 enrolls them); `dispose()` must still make the object
  OBSERVABLY disposed (width/height -> -1? check Ruffle — 2015 errors
  on disposed access) without actually freeing.

## Ruffle reference (local at ~/CC/ruffle)

- `core/src/bitmap/operations.rs` (1978) — THE port target: every
  BitmapData operation as pure pixel math (get/set_pixel(32),
  fill_rect, copy_pixels incl. alpha/merge paths, color_transform,
  flood_fill, threshold, hit_test, pixel_dissolve (LCG order!),
  histogram, get/set_pixels via ByteArray, get/set_vector, clone,
  palette_map, merge, noise...). Port MEASUREMENT-exact: integer
  clamps, premultiply rules, channel order.
- `core/src/bitmap/bitmap_data.rs` (1037) — the pixel-store model
  (transparency flag, disposed state, premultiplied storage nuances,
  dirty regions — ignore GPU sync halves).
- `core/src/avm2/globals/flash/display/bitmap_data.rs` (1598) +
  `BitmapData.as` (216) — the AS3 glue: argument coercions/defaults,
  error codes (2015 disposed / 2004 params), constructor
  (width/height clamp 0<w,h<=8191, fillColor default 0xFFFFFFFF),
  SymbolClass-bound subclass construction (`fill_bitmap_data_from_symbol`).
- `core/src/avm2/globals/flash/display/bitmap.rs` (218) + `Bitmap.as`
  — Bitmap: bitmapData get/set, pixelSnapping ("auto" quirks),
  smoothing; the allocator's symbol-binding half.
- `core/src/display_object/bitmap.rs` (424) — display-object half
  (timeline instantiation, width/height from bitmap size).
- `render/src/utils.rs:266 decode_define_bits_lossless` — the decode
  to port into the recompiler (8-bit palettized, 15/24-bit RGB, with
  and without alpha).
- `core/src/character.rs` Character::BinaryData + the flash.utils
  ByteArray [Embed] binding for DefineBinaryData.

## Suggested tranche order (commit + local-batch at each checkpoint)

1. **BitmapData core, script-created** (~12 tests): class + pixel
   store + ctor validation, get/setPixel(32), fillRect, clone,
   dispose, zero_size, rectangle_rounding, accuracy,
   colortransform_oob, getpixels/setpixels (ByteArray),
   get/setvector, copypixelstobytearray.
2. **Operations** (~8): copyPixels (+blend_over), floodfill,
   threshold (+hittest_threshold), hittest, histogram, pixeldissolve
   (port the exact avmplus LCG traversal from operations.rs),
   draw_alpha_erase's TRACE half.
3. **Recompiler asset tables + embedded/timeline construction** (~6):
   lossless decode + emission, bitmapdata_embedded,
   bitmapdata_constructor_from_timeline, Bitmap class + display
   wiring (bitmap_constr/data/properties/subclass*/timeline/
   pixelsnapping), DefineBinaryData -> ByteArray binding.
4. Triage the misses (loader_bitmap_transparency may need Loader
   plumbing — triage rather than build Loader); refresh
   STAGE7_CANDIDATES.txt statuses.
5. **Seedling smoke**: `--check-abc` still clean, plus recompile
   `/home/robert/CC/SeedlingArchipelagoInjector/Seedling.swf` far
   enough to confirm the asset tables emit (282 bitmaps) without
   blowing up generated-code size or compile time. Not graded — just
   record findings in the memory for Stage 9.

## Constraints & conventions (unchanged)

- Trunk-based; commit directly to `master`; autonomous commit/push/CI
  authorized (CLAUDE.md). Standard trailer. Full pipeline per
  `.claude/pipeline-handoff.md` at the end (no-graphics mode);
  confirm zero pass->fail across ALL suites and wasm-link-smoke green.
- Conflict boundary: own `SWFRecomp/src/abc/`, `SWFRecomp/include/abc/`,
  `SWFModernRuntime/{src,include}/avm2/`, `RecompiledABC/` paths.
- Do NOT run the full avm2 suite locally. Single tests:
  `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`.
- Keep the honest-failure property: unimplemented paths abort with a
  named message, never silently mis-execute.

## Gotchas from Stages 5/6 you must not trip over

- REBUILD the recompiler after any SWFRecomp change
  (`cd SWFRecomp/build && make -j8`); verify_output only rebuilds the
  runtime side.
- Debug loop: `python3 ruffle-tests/build_test_debug.py --test=NAME
  --tests-dir=...` builds a persistent binary; verify_output HIDES
  stderr, so uncaught-error messages (1065 missing classes etc.) are
  only visible on the debug binary's stderr. Fastest triage for
  "output ends early".
- Crashes that print one empty line then stop = an uncaught 1065 for
  a MISSING CLASS touched at script init — stub constructible classes
  first (Stage 6 hit this repeatedly:
  AccessibilityImplementation/ContextMenu/Matrix3D/Vector3D...).
- SymbolClass-bound classes: binding resolves through the class
  HIERARCHY (ancestor walk); the no-char-0 fallback constructs
  bindings whose chars are never placed — make sure constructing a
  BitmapData-bound class at fallback time is harmless.
- vtable accessor OVERRIDES must replace in place (`add_getset` in
  avm2_display.c) — appends never shadow inherited entries. Builtin
  accessor stack frames read "get x"/"set x".
- Expected outputs embed FP's exact float formatting — use
  avm2_format_number; check test.toml `[approximations]` before
  chasing 1-ulp diffs. uint pixel values print via the Number path
  (0xFFFFFFFF -> 4294967295).
- Ruffle stores BitmapData pixels PREMULTIPLIED internally and
  un-premultiplies on read (operations.rs to_un_multiplied_alpha) —
  getPixel32 of a setPixel32 value can round-trip lossily on purpose.
  Port the exact rounding or half the pixel tests will be off-by-one.
- `avm2_alloc(0)` aborts o1heap — clamp (zero-size bitmap tables).
- The 74 input.json tests are Stage 8; don't chase bitmap tests that
  need injected input (only mouse_pick_non_interactive_bitmap_mask —
  already excluded).

## End-of-session bookkeeping

- Stage-7 landing note in `avm2-seedling-plan.md` §2 (promote to DONE
  or record partial tranche state).
- Update `avm2/_investigation/CURRENT_STATUS.md` (new CI baseline,
  what landed, misses triaged).
- New `avm2-stage7-bitmapdata` memory (gotchas, esp. premultiply
  rounding + asset-table size findings from the Seedling smoke);
  update `seedling-avm2-readiness` progress.
- If partial, refresh THIS prompt with precise "resume here" state; if
  complete, mark it COMPLETE at the top and draft the Stage-8 prompt
  (input.json harness — next per the Seedling plan).
