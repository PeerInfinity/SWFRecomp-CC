# s30 interim #2 expected-flip ledger (coordinator, 2026-11-27)

Code: `92f7d5e8a` (browser ladder #2) + batch 2: `17bc522de` w1-exec-order, w2-drift-smalls-land,
w2-array-forin-proto, w2-native-table-land, w2-stroke-geometry-land, w2-rm-avm2-land, w2-lowq-land.
Graded against interim #1 (`46040854188`, results `dd22bc5b4`). Modes: graphics `full` `images=true`, PLUS
no-graphics `full` (ladder #2 touches `tag_stubs.c`). Any move not listed here is a regression or drift.

## Trace axis, status flips (→ pass)

| row | before | owner |
|---|---|---|
| `from_gnash/misc-ming.all/action_order/action_execution_order_test11` | mm | w1-exec-order |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test4` | mm | w1-exec-order |
| `avm2/xmldocument_tostring` | mm | w2-drift-smalls-land |
| `avm2/html_text_img_parsing` | rm | w2-drift-smalls-land |
| `timeline/swf_9_frame_script_dynamic_goto` | rm | w2-rm-avm2-land |
| `timeline/swf_9_event_goto_frame_script` | rm | w2-rm-avm2-land |
| `from_shumway/MaskTest-3` | rm | w2-rm-avm2-land |
| `from_avmplus/regress/bug_558863_swf10` | rm | w2-rm-avm2-land |
| `from_avmplus/regress/bug_479786` | rm | w2-rm-avm2-land |
| `from_avmplus/as3/Math/e15_1_2_2` | rm | w2-rm-avm2-land |
| `avm2/textblock_releaselines` | rm | w2-rm-avm2-land |
| `avm2/textline_atom_index_at_char_index` | rm | w2-rm-avm2-land |
| `avm2/swf_9_goto_in_construct_frame` (flash_fixes FP32 cut) | rm | w2-rm-avm2-land |
| `from_shumway/timeline/nav/clipDepth` (flash_fixes num_ticks 4) | rm | w2-rm-avm2-land |
| `from_shumway/avm2/flash/geom/transform/pixelBounds` | rm | w2-rm-avm2-land |

**Combined-batch move (coordinator local, no-graphics):** `avm1/global_proto_decls` mm → **rm** (our diff is now a subset of
Ruffle's: native table + array for..in stacked; neither slot alone flipped it). `_delete` may follow. Effective +1 each.

Content-only moves, status unchanged (mm → mm): `avm1/movieclip_hittest_shapeflag` (6 → 4 lines), `avm1/global_proto_decls`,
`_delete`, `global_instance_decls`, gnash `argstest-v6/7/8` (native table + forin: Flash-ward; argstest raw diff may grow).

## New regression rows (expected pass)

Trace: `avm1_exec_order_sibling_interleave`, `avm1_tabindex_textfield_v6/_v8`, `avm1_tabindex_clip_button_v6/_v8`,
`avm2_html_img_loadcount`, `avm1_array_forin_proto_swf5/6/8`, `avm2_mask_removal_script`, `avm2_pixelbounds_offlist`;
`avm1_nested_child_swapdepths_remove` fail → pass (ladder #2).
Image: `avm2_stroke_curve_scale_s1s4`, `_s16_w4_k0/_k1`, `_s16_w16_k0/_k1`, `avm2_stroke_translucent_round` (0-slack
budgets: a 1-outlier CI miss is a fidelity finding), `lowq_glyph_probe_df2`, `lowq_glyph_probe_df3`.

## Pixel axis

- **fail → PASS:** `from_shumway/acid/acid-shapes` (stroke-geometry), `visual/simple_shapes/gradients/gradients` (lowq),
  `morph_test1` frame1 comparison (row stays fail).
- **Golden swaps (stay fail):** `from_shumway/acid/acid-scale`, `visual/simple_shapes/overlaps` (FP32 LOW, WIN == LNX).
- **Priced, status unchanged:** HIGH AVM2 drawing-API rows toward golden (`graphics_direct_commands`, `graphics_bitmaps`,
  `displayobject_getbounds_shape`, `bitmapdata_drawwithquality`, `blend_shader_luma_lighten`, `acid-bitmapData-draw`,
  `bitmapdata_draw`); `displayobject_hittestpoint_boundary` +4 (away). LOW (lowq) away-from-golden on already-failing
  rows: filters ×6 (Flash-ward per FP32), `style_changes_in_html` (+904 vs Flash, priced), `acid-scale` (+160 vs Flash,
  priced), `acid-child`, `acid-text-6`, `doubleAndRegister`, 5 AVM2 LOW rows, `fills_and_lines`, `nested_rotation`.
- **Any pass → fail is NOT priced.**
