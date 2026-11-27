# s30 interim #3 expected-flip ledger (coordinator, 2026-11-27)

Code: `1bd91cd6f` batch 3 = w2-native-instance + w2b-native-residues + native-table unlisted-last order fix +
w2b-lowq-text (DF2 ceil SWF ≥ 7; y half OFF by default) + w2b-stroke-timeline (timeline HIGH flatten) + flash_fixes
heavy_tesselation (image swap) and global_instance_decls (mock_timezone). Graded against interim #2 (graphics
`e2d30a710`). Graphics `full` `images=true` only (no `swf_core.c` / `tag_stubs.c` / NO_GRAPHICS arm in batch 3).

## Trace axis

- `from_gnash/actionscript.all/ExternalInterface-v8` rm → **pass** (w2-native-instance).
- `from_gnash/misc-ming.all/ButtonEventsTest` mm → **rm** (the interim #2 loss, restored).
- NEW pass: `regression/avm1_native_instance_layout`, `avm1_native_identity_probe_swf5/6/7/8`.
- Content-only, status unchanged: `global_instance_decls` (mm, Flash-ward incl. the TZ line + BitmapData block),
  `global_proto_decls` (stays rm), `global_proto_decls_delete` (mm; +184 numbered-diff lines from the order fix,
  priced), gnash `argstest-v6/7/8` (mm).
- Timeline flatten: 97 codegen-changed trace rows byte-identical (w2b-stroke-timeline).

## Pixel axis

- No status flips expected.
- Swap: `visual/simple_shapes/heavy_tesselation` now graded vs FP32 LOW (stays fail, ~44 486).
- w2b-stroke-timeline md5 moves (priced, toward unless noted): `strokes/scale` 12 570 → 8 718, acid-filter-2,
  acid-video ×3, acid-clip(-2), acid-color-2, 3_joystick, avm1_imports_avm1, acid-mask ×3, acid-bitmap-draw_quality_high,
  acid-morph, acid-blend-2 ×5, cache_as_bitmap/masks ×6, overlay_onto_stage, timeline_loop ×7,
  `avm1_stroke_pixel_snap_matrix` 11 730 → 11 856 (stays pass), acid ×N; **away: `cache_as_bitmap/scroll_rect_scaled`
  (t0 2 299 → 2 328), `acid-small` .01/.05 (t20 +78/+141)**; `avm2_parent_child_render` 0 → 252 / 400 (self golden).
- w2b-lowq-text: `BeginBitmapFill` 894 → 393 (fail), `lowq_glyph_probe_df2` 52 527 → 12 891 (pass, budget tightened).
- **Any pass → fail is NOT priced.**
