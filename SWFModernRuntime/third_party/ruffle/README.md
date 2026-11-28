# Ruffle-derived code in this repository

[Ruffle](https://github.com/ruffle-rs/ruffle) is licensed MIT OR Apache-2.0. The code here that is ported from it,
or closely modelled on it, is used **under the MIT licence** (decision D12a, 2026-11-28). The licence text is in
[`LICENSE-MIT.txt`](LICENSE-MIT.txt), and `THIRD_PARTY_NOTICES.md` at the repository root lists it.

This page is the per-function attribution table from the A1 audit (2026-11-28, against a Ruffle checkout at
`0ddd12b6a`, 2026-11-20). Every function or block listed carries a comment in our source that names the Ruffle
file it came from. Paths in the "Ruffle source" column are relative to the root of `ruffle-rs/ruffle` unless they
name another repository.

## Scope and method

- **Searched:** every `ruffle` mention in `SWFModernRuntime/src/`, `SWFModernRuntime/include/` and `SWFRecomp/src/`
  (about 2,900 lines in 96 files), plus a check of each file's large literal tables and distinctive algorithms
  against the Ruffle tree.
- **Counted as a port:** the code (its structure, constants, tables, algorithm steps, shader text or class/method
  inventory) is taken from Ruffle, whether the comment says "port", "derived from", "mirrors `fn_name`" or nothing.
- **Not counted:** comments that only say our output matches Ruffle's, describe a deliberate divergence, or describe
  observable behaviour (event order, timeline semantics) that our own code implements. Those are behaviour
  references, not copies, and most of the 2,900 mentions are of this kind.
- **Result:** 165 rows across 63 of our files (59 distinct file cells below; some rows span a `.c` and its header).
  Kinds:
  - `port`: translated function or block;
  - `close model`: same algorithm and structure, written afresh;
  - `table/constants`: copied literal tables;
  - `shader`: WGSL ported from `render/wgpu/shaders/`;
  - `generated`: produced by a script from Ruffle's test goldens or data files.
- **Flag column:** "unattributed before A1" marks code that had no Ruffle credit until this audit. "near-verbatim"
  marks a close copy. The code was not rewritten; the attribution was added.
- **Commit column:** the Ruffle commit, where our comment recorded one. All of these hashes resolve in
  `ruffle-rs/ruffle`. Rows without one were read against Ruffle `master` at the time; the file path is the durable
  reference.

## Sources outside `ruffle-rs/ruffle`

Some rows name other repositories that Ruffle depends on. Their licences:

| Source | Licence | What we took |
|---|---|---|
| [ruffle-rs/h263-rs](https://github.com/ruffle-rs/h263-rs) @ `8215bc7` (crates h263-rs, h263-rs-deblock, h263-rs-yuv 0.1.0) | MIT OR Apache-2.0, used under MIT ([`LICENSE-MIT-h263-rs.txt`](LICENSE-MIT-h263-rs.txt)) | `video_codec.c`: deblock filter (line for line), BT.601 conversion, Spark header layout |
| [ruffle-rs/rust-flash-lso](https://github.com/ruffle-rs/rust-flash-lso) @ `11a0836` | MIT ([`LICENSE-MIT-rust-flash-lso.txt`](LICENSE-MIT-rust-flash-lso.txt)) | `avm2_amf.c`: the AMF0/AMF3 wire format |
| [ruffle-rs/jpegxr](https://github.com/ruffle-rs/jpegxr) @ `86cc1749` | BSD-3-Clause (Microsoft jxrlib) | Nothing copied. `avm2_jpegxr.c` calls the system `libjxr` in the same order as the crate's wrapper does |
| W3C SVG 1.1 feTurbulence reference code, via Ruffle `core/src/bitmap/turbulence.rs` | W3C Software Notice | `action.c` Perlin noise. W3C's notice is reproduced in the comment above it |
| lyon_geom 1.0.6 (a Ruffle dependency, not Ruffle code) | MIT OR Apache-2.0 | `include/curve_flatten.h`, credited in its own header |

Generated tables (`unicode_case_tables.h`, `avm1_native_table.inc`) come from Ruffle *test goldens*
(`tests/tests/swfs/avm1/...`). Their generator scripts write that source into the header.

## Attribution table

| Our file | Function / block | Ruffle source | Kind | Ruffle commit | Flag |
|---|---|---|---|---|---|
| SWFModernRuntime/include/actionmodern/action_queue.h | `ActionQueuePriority` (Initialize/Construct/Normal, highest-first FIFO) | core/src/context.rs (`ActionQueue`, `ActionPriority`) | close model |  |  |
| SWFModernRuntime/include/actionmodern/avm1_native_table.inc | AVM1 native member/attr table | tests/tests/swfs/avm1/global_proto_decls/output.txt (via scripts/gen_avm1_native_table.py) | generated (from Ruffle data) |  |  |
| SWFModernRuntime/include/avm2/avm2_external.h | provider + external::Value shape (already full path) | core/src/external.rs | close model |  |  |
| SWFModernRuntime/include/avm2/avm2_globals.h | avm2_avmplus_qsort declaration (impl in avm2_array.c, other group) | core/src/avm2/globals/array.rs (qsort) | port |  |  |
| SWFModernRuntime/include/avm2/avm2_object.h | ScriptObject layout | core/src/avm2/object/script_object.rs:61-79 | close model |  |  |
| SWFModernRuntime/include/gradient_ramp.h | 256-texel gradient ramp walk | render/wgpu/src/mesh.rs (`CommonGradient::new`, GRADIENT_SIZE) | port |  |  |
| SWFModernRuntime/include/html_img.h | htmlText `<img>` parse/serialise rules | core/src/html/text_format.rs | port | 8cbada89a..16b334374 |  |
| SWFModernRuntime/src/actionmodern/action.c | Array.sort UNIQUESORT/RETURNINDEXEDARRAY index quicksort + standard snapshot quicksort | core/src/avm1/globals/array.rs (sort_internal, qsort) | port |  | near-verbatim (qsort partition loop is a transliteration; credited Ruffle but without path) |
| SWFModernRuntime/src/actionmodern/action.c | ContextMenu / ContextMenuItem builtins (section header ~3447) | core/src/avm1/globals/ContextMenu.as, core/src/avm1/globals/ContextMenuItem.as | port | 8885104f0, dae634d8d |  |
| SWFModernRuntime/src/actionmodern/action.c | FLASH_PREMUL_FACTOR[256] + unpremultiplyAlpha | core/src/bitmap/bitmap_data.rs (Color::to_un_multiplied_alpha) | table/constants |  |  |
| SWFModernRuntime/src/actionmodern/action.c | avm1FkFixed16 etc. (AVM1 filter quantization for applyFilter) | core/src/avm1/globals/bitmap_filter.rs (avm1_to_filter) | close model |  |  |
| SWFModernRuntime/src/actionmodern/action.c | bitmapDataCopyPixels self-copy direction rule | core/src/bitmap/operations/copy_on_cpu.rs (copy_on_cpu_self) | close model | ea3956e89 |  |
| SWFModernRuntime/src/actionmodern/action.c | bitmapDataNoise (seed transform, Lehmer range RNG) | core/src/bitmap/operations.rs (noise); LehmerRng in core/src/bitmap/bitmap_data.rs | close model |  | unattributed before A1 |
| SWFModernRuntime/src/actionmodern/action.c | builtin_as_setup_error (AsSetupError) | core/src/avm1/globals/Error.as | port | 31223a80a |  |
| SWFModernRuntime/src/actionmodern/action.c | builtin_broadcaster_addListener / removeListener, builtin_asbroadcaster_initialize | core/src/avm1/globals/AsBroadcaster.as | port | c2a878a68 |  |
| SWFModernRuntime/src/actionmodern/action.c | builtin_sound_getPan / builtin_sound_setPan formulas | core/src/display_object.rs (SoundTransform::pan / with_pan) | close model |  |  |
| SWFModernRuntime/src/actionmodern/action.c | clampToI32 | core/src/avm1/clamp.rs (clamp_to_i32) | close model |  |  |
| SWFModernRuntime/src/actionmodern/action.c | copyPixelsUnpremultiplyRound | core/src/bitmap/operations.rs (copy_pixels_with_alpha_source, :1214) | close model |  |  |
| SWFModernRuntime/src/actionmodern/action.c | decimal_shift | core/src/avm1/value.rs (decimal_shift) | port |  |  |
| SWFModernRuntime/src/actionmodern/action.c | drawingGenerateGradientRamp (256-texel walk) | render/wgpu/src/mesh.rs (CommonGradient::new) | close model |  |  |
| SWFModernRuntime/src/actionmodern/action.c | drawingSegDistHit + stroke hit test over pending cmds | render/src/shape_utils.rs (draw_command_stroke_hit_test / hit_test_stroke) | port |  |  |
| SWFModernRuntime/src/actionmodern/action.c | drawingWindingLine / drawingCmdWindingHitTest | render/src/shape_utils.rs (winding_number_line, :991) | close model |  |  |
| SWFModernRuntime/src/actionmodern/action.c | flash.geom Point / Matrix / Rectangle methods (pointClone..rectUnion, section header ~11298) | core/src/avm1/globals/flash/geom/Point.as, Rectangle.as, Matrix.as | port | 82b84d3e5 / c717e9dc8 / ee9791463 |  |
| SWFModernRuntime/src/actionmodern/action.c | flash_format_double | core/src/avm1/value.rs (f64_to_string, :627-809) | port |  |  |
| SWFModernRuntime/src/actionmodern/action.c | mc_get_local_mouse | core/src/display_object.rs (local_mouse_position) | close model |  |  |
| SWFModernRuntime/src/actionmodern/action.c | perlin_* / perlin_turbulence (Perlin noise) | core/src/bitmap/turbulence.rs (Turbulence::turbulence, incl. octave_offsets); originally W3C SVG feTurbulence reference | port |  | unattributed before A1 (credited W3C only); near-verbatim |
| SWFModernRuntime/src/actionmodern/action.c | stageQualityToHighqualityInt / setStageQualityFromHighquality | core/src/avm1/object/stage_object.rs (high_quality / set_high_quality) | close model |  |  |
| SWFModernRuntime/src/actionmodern/action.c | tab-order automatic sort key 6*min_y + min_x | core/src/focus_tracker.rs | table/constants |  |  |
| SWFModernRuntime/src/actionmodern/date.c + include/actionmodern/actiondate.h | `actionDateGetASnativeMethod` ASnative(103,N) index scheme | core/src/avm1/globals/date.rs (method table) | table/constants |  |  |
| SWFModernRuntime/src/actionmodern/object.c | `flash_hide_masks` (SWF 5-9 ASSetPropFlags version masks) | core/src/avm1/property.rs (`VERSION_MASKS`, `allow_swf_version`) | table/constants |  | unattributed before A1 |
| SWFModernRuntime/src/actionmodern/timer.c | Timers clock model (add/update, MIN_INTERVAL, TIMER_SCALE, clock pull-back) | core/src/timer.rs (`Timers::update_timers`, `add_timer`) | port |  |  |
| SWFModernRuntime/src/actionmodern/unicode_case_tables.h | case-map tables | tests/tests/swfs/avm1/string_methods/output.txt (via scripts/generate_case_tables.py) | generated (from Ruffle data) |  |  |
| SWFModernRuntime/src/actionmodern/video_codec.c | `deblock_*` (floor_shr, up_down_ramp, clipd1, process_div/shr, horiz/vert/plane) + `VIDEO_QUANT_TO_STRENGTH` | ruffle-rs/h263-rs `deblock/src/deblock.rs` (crate h263-rs-deblock 0.1.0, rev 8215bc7; `scalar_impl::process`, `simd_impl::process_simd`, `QUANT_TO_STRENGTH`) | port (line-for-line) + table |  |  |
| SWFModernRuntime/src/actionmodern/video_codec.c | `spark_parse_header` (Sorenson picture header layout) | ruffle-rs/h263-rs `h263/src/parser/picture.rs` (`decode_picture`, `decode_sorenson_ptype`; crate h263-rs 0.1.0) | close model |  |  |
| SWFModernRuntime/src/actionmodern/video_codec.c | `video_deblock_strength` (deblock gate) | video/software/src/decoder/h263.rs (lines ~80-98) | close model |  |  |
| SWFModernRuntime/src/actionmodern/video_codec.c | `yuv420_planes_to_rgba_bt601` (BT.601 YUV420 to RGBA) | ruffle-rs/h263-rs `yuv/src/bt601.rs` (crate h263-rs-yuv 0.1.0, rev 8215bc7) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_amf.c | AMF0/AMF3 wire format (writer + reader, reference/trait caches, length encoding), as driven by Ruffle's core/src/avm2/amf.rs | ruffle-rs/rust-flash-lso `flash-lso/src/amf3/{write,length,element_cache}.rs`, `amf0/write.rs`, `read.rs` (rev 11a0836, pinned by Ruffle's core/Cargo.toml) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_amf.c | local_shared_object_key port (so_get_or_create key rules) | core/src/shared_object.rs (local_shared_object_key) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_array.c | ES3-compat Array.prototype method inventory | core/src/avm2/globals/Array.as | table/constants |  |  |
| SWFModernRuntime/src/avm2/avm2_array.c | Sorting section + avm2_avmplus_qsort (shared with Vector.sort) | core/src/avm2/globals/array.rs (qsort, sort postprocess) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_array.c | file header (Array builtin: holes, splice, sort flags) | core/src/avm2/globals/array.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_bitmap.c | ColorMatrixFilter / DisplacementMapFilter CPU passes | render/wgpu/shaders/filter/color_matrix.wgsl, render/wgpu/shaders/filter/displacement_map.wgsl | shader |  |  |
| SWFModernRuntime/src/avm2/avm2_bitmap.c | FB_PASS_SCALES[15] | swf/src/types/blur_filter.rs (PASS_SCALES) | table/constants |  |  |
| SWFModernRuntime/src/avm2/avm2_bitmap.c | FLASH_PREMUL_FACTOR[256] table; blend_over | core/src/bitmap/bitmap_data.rs | table/constants |  |  |
| SWFModernRuntime/src/avm2/avm2_bitmap.c | PixelRegion clipping | render/src/bitmap.rs (PixelRegion) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_bitmap.c | blend_add/subtract/screen; complex blends; ALPHA/ERASE | render/wgpu/src/blend.rs; render/wgpu/shaders/blend/*.wgsl ({alpha,erase}.wgsl) | shader |  |  |
| SWFModernRuntime/src/avm2/avm2_bitmap.c | file header: BitmapData pixel store + operation kit + AS3 glue | core/src/bitmap/{bitmap_data,operations}.rs + core/src/avm2/globals/flash/display/{bitmap_data,bitmap}.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_bitmap.c | histogram | core/src/avm2/globals/flash/display/BitmapData.as (histogram) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_bitmap.c | pixelDissolve (Feistel), copyPixels, threshold, colorTransform, compare, copyChannel, paletteMap, scroll, getColorBoundsRect, draw CPU fast path, encode | core/src/bitmap/operations.rs (+ operations/copy_on_cpu.rs; compare also core/src/avm2/globals/flash/display/bitmap_data.rs) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_bitmap.c | round_to_even | core/src/ecma_conversions.rs (round_to_even) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_bytearray.c | whole file (storage, natives, Endian/CompressionAlgorithm) | core/src/avm2/bytearray.rs; core/src/avm2/globals/flash/utils/byte_array.rs; core/src/avm2/globals/flash/utils/ByteArray.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_class.c, include/avm2/avm2_class.h | flattened vtable model | core/src/avm2/vtable.rs | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_cpu_raster.c | device-font TextField box | core/src/display_object/edit_text.rs (draw_device_text_box) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_cpu_raster.c | focal gradient t | render/wgpu/shaders/gradient.wgsl (find_t) | shader |  |  |
| SWFModernRuntime/src/avm2/avm2_cpu_raster.c | morph lerp weights, lerp_twips, lerp_color | core/src/display_object/morph_shape.rs (lerp_twips, lerp_color) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_date.c | Date.parse tokenizer | core/src/avm2/globals/date.rs (parse_full_date) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_dictionary.c | whole file | core/src/avm2/object/dictionary_object.rs; core/src/avm2/globals/flash/utils/Dictionary.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | ColorTransform.color get/set, concat | core/src/avm2/globals/flash/geom/ColorTransform.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | GFX_UCP table + gfx_emit_round_rect | core/src/avm2/globals/flash/display/graphics.rs (UNIT_CIRCLE_POINTS, draw_round_rect_internal) | table/constants + port |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | Matrix copyRowTo / copyColumnTo | core/src/avm2/globals/flash/geom/Matrix.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | NativeMenu / NativeMenuItem natives | core/src/avm2/globals/flash/display/NativeMenu.as + NativeMenuItem.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | PerspectiveProjection defaults (fov 55, centre 250,250, focal length) | render/src/perspective_projection.rs | table/constants |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | avm2_draw_border_line | render/src/lines.rs (emulate_line_as_rect) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | avm2_text_* Twips rounding helpers (round_to_pixel_ties_even / trunc_to_pixel on device grid) | swf/src/types/twips.rs (Twips::round_to_pixel_ties_even, trunc_to_pixel) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | flash.geom.Matrix method surface (MatF ops) | core/src/avm1/globals/matrix.rs + render/src/matrix.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | flash.geom.Vector3D surface (incl. nearEquals bug) | core/src/avm2/globals/flash/geom/Vector3D.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | flash.ui.Mouse cursor state (forced/custom cursor, registerCursor) | core/src/avm2/globals/flash/ui/mouse.rs + core/src/avm2/globals/flash/ui/MouseCursorData.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | gfx_finalize_path (fill path first, then deferred strokes) | core/src/drawing.rs (Drawing::new_fill) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | m3d_from_ext (Matrix3D from 2D matrix + tz) | render/src/matrix3d.rs (Matrix3D::from_matrix) + core/src/avm2/globals/flash/geom/transform.rs (get_matrix_3d) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | morph-shape vertex lerp (hit test + render) | core/src/display_object/morph_shape.rs (lerp_twips) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | pick_winding_line (+x ray winding) | render/src/shape_utils.rs (winding_number_line) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | point transform in localToGlobal/globalToLocal (twip-quantise point, round product, add translation) | render/src/matrix.rs (impl Mul<Point<Twips>>) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | round_twips_f32 (f32 product rounded half-to-even into i32 twips) | render/src/matrix.rs (round_to_i32) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | stage scale-mode matrix build (per-mode scale + align translation) | core/src/display_object/stage.rs (build_matrices) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_display.c | unified timer list (AS3 Timer + setTimeout/setInterval, MIN_INTERVAL clamp, tail-of-tick firing) | core/src/timer.rs (+ core/src/avm2/globals/flash/utils/Timer.as _onUpdateClosure) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_e4x.c | E4X_LETTER/DIGIT/COMBINING/EXTENDER range tables | core/src/avm2/e4x/is_xml_name.rs (also XML 1.0 spec / avmplus AvmCore.cpp) | table/constants |  |  |
| SWFModernRuntime/src/avm2/avm2_e4x.c, include/avm2/avm2_e4x.h | E4X node tree, serializer, name matching (parser hand-written) | core/src/avm2/e4x.rs; core/src/avm2/object/xml_object.rs; core/src/avm2/object/xml_list_object.rs; core/src/avm2/globals/xml*.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_error.c | ERROR_MESSAGES table (Error.getErrorMessage) | core/src/avm2/error_messages.rs | generated |  |  |
| SWFModernRuntime/src/avm2/avm2_error.c, include/avm2/avm2_error.h | error constructors / exact FP message strings; handle_err dispatch | core/src/avm2/error.rs; core/src/avm2/activation.rs (handle_err) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_events.c | Event state, DispatchList, 3-phase dispatch | core/src/avm2/events.rs; core/src/avm2/globals/flash/events/{Event,EventDispatcher}.as + event*.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_events.c | Event static const inventory | core/src/avm2/globals/flash/events/Event.as | table/constants |  |  |
| SWFModernRuntime/src/avm2/avm2_events.c | flash.automation classes | core/src/avm2/globals/flash/automation/*.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_events.c | k_broadcast_whitelist + broadcast registry | core/src/avm2.rs (BROADCAST_WHITELIST, broadcast_event) | table/constants |  |  |
| SWFModernRuntime/src/avm2/avm2_filters.c + include/avm2/avm2_filters.h | filter value classes + conversion layer | core/src/avm2/filters.rs + core/src/avm2/globals/flash/filters/*.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_function.c | ES3-compat Function.prototype inventory | core/src/avm2/globals/Function.as | table/constants |  |  |
| SWFModernRuntime/src/avm2/avm2_function.c | display_function (error 1063) | core/src/avm2/function.rs (display_function) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_globals.c (+ generated DT_DESC_DISPLAY/EVENTS rows) | flash.display / flash.events builtin type descriptors | core/src/avm2/globals/flash/display/*.as, core/src/avm2/globals/flash/events/*.as (via tools/descriptor/gen_display_descriptors.py) | generated (from Ruffle data) |  |  |
| SWFModernRuntime/src/avm2/avm2_globals.c | Worker / WorkerDomain state machine | core/src/avm2/object/worker_object.rs + core/src/avm2/globals/flash/system/{worker,worker_domain}.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_globals.c | accessibility describe-type descriptors | core/src/avm2/globals/flash/accessibility/*.as | table/constants |  |  |
| SWFModernRuntime/src/avm2/avm2_globals.c | describeType / describeTypeJSON split | core/src/avm2/globals/avmplus.rs (describe_type_json) + core/src/avm2/globals/avmplus.as (describeType) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_globals.c | flash.geom.Point method surface | core/src/avm2/globals/flash/geom/Point.as (formerly globals/flash/geom/point.rs) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_globals.c | flash.system.Capabilities values + screen formula | core/src/avm2/globals/flash/system/Capabilities.as + capabilities.rs | table/constants |  |  |
| SWFModernRuntime/src/avm2/avm2_globals.c | lenient UTF-8 decode for unescape | wstr/src/utils.rs (DecodeAvmUtf8) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_jpegxr.c + include/avm2/avm2_jpegxr.h | ATF JPEG-XR / CompressedAlpha DXT5 rebuild | core/src/avm2/globals/flash/display3D/textures/atf_jpegxr.rs (do_compressed_upload, :49-144) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_jpegxr.c + include/avm2/avm2_jpegxr.h | avm2_jxr_decode_rgba | render/src/utils.rs (decode_jpegxr) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_json.c | whole file (JSON parse/stringify, Value::normalize) | core/src/avm2/globals/json.rs; core/src/avm2/value.rs (normalize) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_media.c | Sound family (SoundTransform, SoundChannel, SoundMixer, Sound) | core/src/avm2/globals/flash/media/* + core/src/display_object.rs (SoundTransform) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_media.c | computeSpectrum | core/src/avm2/globals/flash/media/sound_mixer.rs (compute_spectrum) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_net.c | FileReferenceList (AS wrapper in Ruffle) | core/src/avm2/globals/flash/net/FileReferenceList.as | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_net.c | LocalConnection model | core/src/local_connection.rs + core/src/avm2/object/local_connection_object.rs | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_net.c | NetConnection two-variant protocol model | core/src/net_connection.rs | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_net.c | NetStream tick / FLV tag processing | core/src/streams.rs (NetStream::tick, flv_video_tag) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_net.c | XMLSocket wrapper (AS3 in Ruffle, C here) | core/src/avm2/globals/flash/net/XMLSocket.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_nsqname.c | Namespace + QName builtins | core/src/avm2/object/{namespace,qname}_object.rs; core/src/avm2/globals/{namespace,q_name}.rs; core/src/avm2/globals/{Namespace,QName}.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_number.c | ES3-compat Number.prototype inventory | core/src/avm2/globals/Number.as | table/constants |  |  |
| SWFModernRuntime/src/avm2/avm2_number.c | Number/int/uint/Boolean/Math builtins | core/src/avm2/globals/{number,int,uint,boolean,math}.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_number.c | math_pow Flash special-case branches | core/src/avm2/globals/math.rs (pow) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_ops.c, include/avm2/avm2_ops.h | opcode helper semantics (already full path) | core/src/avm2/activation.rs; core/src/avm2/value.rs | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_pixelbender.c | PBJ bytecode parser + error mapping | render/pixel_bender/src/parser.rs + core/src/avm2/globals/flash/display/shader_data.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_pixelbender.c | PBJ evaluator semantics | render/naga-pixelbender/src/lib.rs:857-1420 | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_proxy.c | flash.utils.Proxy | core/src/avm2/object/proxy_object.rs; core/src/avm2/globals/flash/utils/Proxy.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_regexp.c | RegExp + String regex paths | core/src/avm2/regexp.rs; core/src/avm2/globals/reg_exp.rs; core/src/avm2/globals/RegExp.as; core/src/avm2/globals/string.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_stage3d.c | AGAL interpreter (SourceField/DestField parse, swizzle load, extend_to_float4, emit_dest_store) | render/naga-agal/src/{types,builder}.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_stage3d.c | Context3D enum-string spellings | render/src/backend.rs (FromWStr impls) | table/constants |  |  |
| SWFModernRuntime/src/avm2/avm2_stage3d.c | Matrix3D recompose/decompose/transformVectors, interpolate/interpolateTo | core/src/avm2/globals/flash/geom/Matrix3D.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_stage3d.c | agal_validate + AgalError->FP error map | render/naga-agal/src/builder.rs (parse_bytecode, extract_sampler_configs) + core/src/avm2/error.rs (make_agal_upload_error) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_stage3d.c | flash.geom.Utils3D | core/src/avm2/globals/flash/geom/Utils3D.as (itself from OpenFL) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_stage3d.c | profile negotiation | core/src/avm2/globals/flash/display/Stage3D.as + core/src/avm2/globals/flash/display/stage_3d.rs | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_string.c | String builtin methods + ES3-compat prototype inventory | core/src/avm2/globals/string.rs; core/src/avm2/globals/String.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_text.c | AccessibilityImplementation ("faithful port") | core/src/avm2/globals/flash/accessibility/AccessibilityImplementation.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_text.c | ContentElement text() null-propagating fold | core/src/avm2/object/content_element_object.rs (text) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_text.c | StyleSheet innerParseColor / innerParseFontFamily | core/src/avm2/globals/flash/text/style_sheet.rs (inner_parse_color) + core/src/html/style_sheet.rs (parse_font_list) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_text.c | Text layout engine section (measurement, Font::evaluate kerning rule) | core/src/html/layout.rs + core/src/font.rs | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_text.c | file header: TextFormat / FormatSpans / HTML span parser / TextField property surface | core/src/html/text_format.rs + core/src/avm2/globals/flash/text/{text_format,text_field}.rs + core/src/display_object/edit_text.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_text.c | flash.geom.Rectangle method surface | core/src/avm2/globals/flash/geom/Rectangle.as (formerly avm2 geom/rectangle.rs) | port |  |  |
| SWFModernRuntime/src/avm2/avm2_text.c | flash.text.engine value objects + FTE enum sets | core/src/avm2/globals/flash/text/engine/*.{as,rs} + core/src/fte.rs | port / table |  |  |
| SWFModernRuntime/src/avm2/avm2_text.c | line wrapping + is_cjk_like etc. char sets ("ported verbatim") | core/src/html/line_wrapping.rs + wstr/src/utils.rs (swf_is_cjk_like etc.) | port / table |  |  |
| SWFModernRuntime/src/avm2/avm2_text.c | text-editing bridge, EditTextRestrict, caret placement / mouse selection / IME | core/src/display_object/edit_text.rs (text_input, text_control_input, EditTextRestrict, screen_position_to_index, handle_click, handle_drag) + core/src/html/layout.rs (find_line_index_by_y) | close model |  |  |
| SWFModernRuntime/src/avm2/avm2_value.c | ECMA f64 -> int conversions | core/src/ecma_conversions.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_value.c, include/avm2/avm2_value.h | Avm2Value coercions / abstract operators (helper names 1:1), string_to_int/string_to_f64 | core/src/avm2/value.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_vector.c | Vector storage, index access, parametrize, method family, sort | core/src/avm2/vector.rs; core/src/avm2/object/vector_object.rs; core/src/avm2/object/class_object.rs; core/src/avm2/globals/vector.rs; core/src/avm2/globals/VectorObject.as | port |  |  |
| SWFModernRuntime/src/avm2/avm2_xml.c | XML/XMLList method surface + property engine | core/src/avm2/globals/xml.rs; core/src/avm2/globals/xml_list.rs; core/src/avm2/globals/XML.as; core/src/avm2/globals/XMLList.as; core/src/avm2/object/xml_object.rs; core/src/avm2/object/xml_list_object.rs | port |  |  |
| SWFModernRuntime/src/avm2/avm2_xml.c | legacy flash.xml XMLNode/XMLDocument/XMLNodeType | core/src/avm2/globals/flash/xml/{XMLNode,XMLDocument,XMLNodeType}.as | port |  |  |
| SWFModernRuntime/src/libswf/ng_shared.c | `ng_device_font_ladder` | core/src/library.rs (`get_or_load_device_font`, `FontMap::find` bold/italic ladder) | close model |  |  |
| SWFModernRuntime/src/libswf/ng_shared.c | `ng_device_font_list` (comma split + trim-only-for-lists) | core/src/html/layout.rs:561-596 | close model |  |  |
| SWFModernRuntime/src/libswf/shape_hit_test.c | `ht_set_min_stroke` | render/src/shape_utils.rs (`stroke_minimum_width`) | close model |  |  |
| SWFModernRuntime/src/libswf/shape_hit_test.c | `winding_number_curve` (inlined solve_quadratic) | render/src/shape_utils.rs (`winding_number_curve`, `solve_quadratic`) | port |  | near-verbatim (already attributed) |
| SWFModernRuntime/src/libswf/tag.c | `pass_scales[15]` in `filter_draw_offset_px` and `filter_chain_reach_px` | swf/src/types/blur_filter.rs (`PASS_SCALES`, `calculate_dest_rect`) | table/constants |  | unattributed before A1; near-verbatim |
| SWFModernRuntime/src/libswf/tag.c | `tf_border_skewed_line_rect`, embedded/device text-box pixel snapping, caret geometry | core/src/display_object/edit_text.rs (`EditTextPixelSnapping::apply`, `draw_text_box`, `draw_device_text_box`, `render_caret`) | close model |  |  |
| SWFModernRuntime/src/libswf/tag.c | `tf_glyph_advance_twips`, `tf_kern_units`, `TF_FIXED8_MULT` | core/src/font/font_like.rs (`FontLike::evaluate`; comments said `font_like.rs`) | close model |  |  |
| SWFModernRuntime/src/libswf/tag.c | `tf_line_pitch_twips` | core/src/html/layout.rs (`newline`); core/src/font.rs (`FontMetrics`) | close model |  |  |
| SWFModernRuntime/src/libswf/tag.c | bevel type/composite_source decode; bevel highlight/shadow offsets; drop-shadow (-x,-y) | render/wgpu/src/filters/bevel.rs; render/wgpu/src/filters.rs (`vertices_with_highlight_and_shadow`); render/wgpu/src/filters/drop_shadow.rs | close model |  |  |
| SWFModernRuntime/src/libswf/tag.c | composed-translation whole-twip rounding (static-text glyph compose, hit-test compose, text glyph compose) | render/src/matrix.rs (`impl Mul for Matrix`) | close model |  |  |
| SWFModernRuntime/src/libswf/tag.c | word-wrap soft breaks (`tf_ww_wrap_line` and friends) | core/src/html/layout.rs (`lay_out_span`, `wrap_dimensions`); core/src/html/line_wrapping.rs (`wrap_line`, `find_allowed_breaks`) | port |  |  |
| SWFModernRuntime/src/rendering/render_webgpu.c | `blend_shader_wgsl_frag` (7 complex blends) | render/wgpu/shaders/blend/{multiply,lighten,darken,difference,invert,overlay,hardlight}.wgsl | shader |  |  |
| SWFModernRuntime/src/rendering/render_webgpu.c | `blur_wgsl` + `blur_box_kernel` | render/wgpu/shaders/filter/blur.wgsl; render/wgpu/src/filters/blur.rs | shader |  |  |
| SWFModernRuntime/src/rendering/render_webgpu.c | `compose_wgsl` (glow / drop shadow / bevel composite) | render/wgpu/shaders/filter/glow.wgsl, bevel.wgsl | shader |  |  |
| SWFModernRuntime/src/rendering/render_webgpu.c | `displace_wgsl` + displacement pass setup | render/wgpu/shaders/filter/displacement_map.wgsl; render/wgpu/src/filters/displacement_map.rs | shader |  |  |
| SWFModernRuntime/src/rendering/render_webgpu.c | `focal_radial_t` (fragment_wgsl) | render/wgpu/shaders/gradient.wgsl (`find_t`, focal arm) | shader |  |  |
| SWFModernRuntime/src/rendering/render_webgpu.c | bitmap-only `color.a > 0` cxform guard (fragment_wgsl) | render/wgpu/shaders/bitmap.wgsl | close model |  |  |
| SWFModernRuntime/src/rendering/render_webgpu.c | blur window stage scaling `(size-1)*s+1` | swf/src/types/blur_filter.rs (`BlurFilter::scale_blur`) | close model |  |  |
| SWFModernRuntime/src/rendering/render_webgpu.c | legacy blend pipelines (alpha OVER) + trivial layer composites (Add/Subtract/Screen factors) | render/wgpu/src/blend.rs (`TrivialBlend::blend_state`, 76-105) | table/constants |  |  |
| SWFModernRuntime/src/rendering/render_webgpu.c, include/rendering/render_webgpu.h | `color_matrix_wgsl` / `render_webgpu_run_color_matrix` | render/wgpu/shaders/filter/color_matrix.wgsl | shader |  |  |
| SWFModernRuntime/src/rendering/render_webgpu.c, include/rendering/render_webgpu.h | nested stencil-mask model (mask_ref Equal/Increment/Decrement, ClearMaskStencil pop) | render/wgpu/src/pipelines.rs:376-414; render/wgpu/src/surface/commands.rs:399-433 | close model |  |  |
| SWFModernRuntime/src/rendering/render_webgpu.c, src/libswf/tag.c | Alpha/Erase layer-group pipelines + `fs_alpha_layer` discard | render/wgpu/shaders/blend/alpha.wgsl, erase.wgsl | close model |  |  |
| SWFModernRuntime/src/utils.c + include/utils.h | test-navigator fetch log format + `socket.json` replay | tests/framework/src/backends/navigator.rs (`TestNavigatorBackend::fetch`, `connect_socket`) | close model |  |  |
| SWFRecomp/src/abc/abc_devicefont.cpp | bold/italic device-font ladder | core/src/library.rs (`FontMap::find`; comment cites :788-845, fn is now at :754) | close model |  |  |
| SWFRecomp/src/abc/abc_devicefont.cpp | device glyph outline (truncate, y-negate, twips) | core/src/font/font_face.rs (`GlyphToDrawing`) | close model |  |  |
| SWFRecomp/src/abc/abc_timeline.cpp | `decode_define_bits_lossless` | render/src/utils.rs (`decode_define_bits_lossless`) | port |  |  |
| SWFRecomp/src/abc/abc_timeline.cpp | `readFilterList` bit layouts | swf/src/read.rs (`read_filter`, *FilterFlags) | close model |  |  |
| SWFRecomp/src/abc/abc_verifier.cpp | `avmplusVerifyText` error strings | core/src/avm2/error_messages.rs (via runtime avm2_error.c) | table/constants |  |  |
| SWFRecomp/src/abc/abc_verifier.cpp | `verifyMethodBody` / `ByteState` / `translateOp` / `opCanThrowError` / compare-branch split | core/src/avm2/verify.rs (`verify_method`, `ByteInfo`, `translate_op`, `op_can_throw_error`) | close model |  |  |
| SWFRecomp/src/swf.cpp | directed-edge fill model + per-layer fill/stroke flush | render/src/shape_utils.rs (`ShapeConverter`, `flush_layer`) | close model |  |  |
| SWFRecomp/src/swf.cpp | gradient ramp bake (calls gradient_ramp.h; comments at ~8195, ~8586) | render/wgpu/src/mesh.rs (`CommonGradient::new`) | port (implementation lives in SWFModernRuntime/include/gradient_ramp.h, other group) |  |  |
| SWFRecomp/src/swf.cpp | morph edge-pairing pre-scan | core/src/display_object/morph_shape.rs (`lerp_edges`) | close model |  |  |
