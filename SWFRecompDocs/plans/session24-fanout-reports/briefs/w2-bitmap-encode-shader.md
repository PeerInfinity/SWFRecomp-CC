**Implement `w1-pixel-bitmap` items 1–3 as a landable patch** (report `SWFRecompDocs/plans/session24-fanout-reports/w1-pixel-bitmap-report.md`, measured prototype `w1-pixel-bitmap-prototype.patch` — start from it). Categories to download: `avm2` (+ `visual` for the blend-shader rows).

EXPECTED-FLIP LEDGER to reproduce: pixel `avm2/bitmapdata_encode_jpeg_visual`, `avm2/pixelbender_effect_glassDisplace_shaderfilter`, `avm2/bitmapdata_draw_cab_quality`; trace `avm2/bitmapdata_encode`. 0 moves elsewhere.

Required beyond the prototype (report §1 / §2 "Wave 2"):
1. **JPEG in BOTH modes.** Vendor `SWFRecomp/lib/stb/stb_image_write.h` into `SWFModernRuntime/lib/stb/`, compile it inside `avm2_bitmap.c` with `STB_IMAGE_WRITE_STATIC` + `STB_IMAGE_WRITE_IMPLEMENTATION` (no symbol clash with `render_webgpu.c`), add the header to `verify_output.py`'s copy list next to `stb_image.h`, CMake and the Emscripten include path; drop the `#if !defined(NO_GRAPHICS)`. Prove `bitmapdata_encode` PASSES in no-graphics too (`tag_stubs.c`/`NO_GRAPHICS` untouched, but the encoder must exist there).
2. **ShaderFilter on Bitmap: don't recompute every frame.** Cache the shader output keyed on the source BitmapData's version counter (add one if none exists) plus a shader-parameter generation; invalidate on any setPixel/draw/lock-unlock path that bumps the version. Apply the filter's left/right/top/bottom extensions. Non-Bitmap sources stay unfiltered (document it).
3. Keep item 3 (`drawWithQuality` vector cxform/blend + explicit quality + top-left rule) exactly as measured; `draw()` without arg 6 must keep the s22 AA ruling.
4. Append the three canary members the report names at EOF of `ruffle-tests/render_canary_tests.txt`.
5. Re-run the report's sweeps (draw 20, encode 4, pixelbender 33) plus the render canary A/B: md5 identity outside the ledger.
6. Optional (only if everything above is done): the report's LOCAL ORACLE REQUEST for a vector `draw()` cxform+blend fixture — write the probe SWF and leave the request; the coordinator runs the exporter.
Do NOT start the CPU bitmap-fill raster (lead 1) or the hairline bias (item 4): out of scope.
