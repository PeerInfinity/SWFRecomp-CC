**Pixel axis: bitmaps, shaders, hairlines, runtime-filter leftovers** (board `graphics-fanout-playbook.md` §22). Categories to download: `avm1 avm2 visual` (only what you need). Prove CI fidelity first (BRIEFS_COMMON "Your box").

Price each, with a measured prototype where cheap:
1. **JPEG encoder**: `avm2/bitmapdata_encode_jpeg_visual` (pixel) + `avm2/bitmapdata_encode` (trace, ~400 lines estimated). Which encoder does Flash/Ruffle use (`jpeg-encoder` crate?), what quality/subsampling, and is byte-exact output needed or only a decoded-pixel match? `w1-avm2-tail` triages the trace row; you own the implementation pricing.
2. **ShaderFilter on Bitmap + `applyFilter(ShaderFilter)`**: `pixelbender_effect_glassDisplace_shaderfilter` (+1 medium), rider `pixelbender_dithering`. `blend_shader_luma_lighten` stays NO-GO (needs PBJ→WGSL).
3. **`bitmapdata_draw_cab_quality`** (2640 outliers, exposed by the s23 drawWithQuality alias).
4. **quality=low hairline tie-break**: `shape_test` 15994 (Flash takes the +0.5 px side). A/B on `acid-small .01/.05` first: those are the s22 hairline flips and must not move.
5. **AVM1 runtime-filter leftovers** (post-s23 `avm1-runtime-filters-report.md` §6; game-visible, NO corpus rows, so LOWEST priority): ColorMatrix/Convolution/DisplacementMap runtime filters draw nothing; a dynamic filter root's `attachBitmap` bitmaps and text skip the filter layer. Price only; prototype one only if everything above is priced.

Deliver GO/NO-GO per item with priced pixel flips (comparison names) and the canary rider set. Siblings: `w1-pixel-text` owns text rows.
