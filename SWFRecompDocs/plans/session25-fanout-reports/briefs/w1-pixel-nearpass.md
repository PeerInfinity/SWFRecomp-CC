**Pixel near-passes: every failing comparison with a small excess.** Categories: whatever these rows need. Fidelity-prove on one row first (BRIEFS_COMMON "Your box").

From the s24 final images run (`08fdbcad6`), failing with small excess (outliers / max_outliers / max_diff):
- `from_shumway/doubleAndRegister` 2/0 (max 255), `from_shumway/acid/acid-gradient-2` 3/0 (255), `avm2/bitmapdata_opaque` 4/0 (127), `from_shumway/3_joystick` 4/0 (187), `from_shumway/acid/acid-scale` 8/0 (255), `from_shumway/gradientTransform` 9/0 (11), `from_shumway/acid/acid-text-6` 12/0 and 198/0 (255), `visual/drawing_api/gradient_focal_point` 60/0 (39), `from_shumway/acid/acid-shapes` 25688/25600 (excess 88), `avm1/movieclip_begin_gradient_fill` 132/0 (209), `avm2/graphics_simple_shapes` 158/0, `from_gnash/morph_test1` 217/0, `from_shumway/acid/acid-gc` 234/0, `avm2/bitmapdata_draw_rotation` 348/0, `from_shumway/acid/acid-clip` 409/140.
- Known NO-GOs to only re-confirm in one line each: `visual/video/colorconversion/h263` (3 px, h263-rs port), `avm2/graphics_simple_shapes` (re-goldened to Flash upstream; we match Ruffle's sidecar; Flash-fidelity work, may still be live: say).

For each: locate the outlier pixels (`ruffle-tests/` image compare tools; diff the PNGs from `origin/ruffle-image-results`), name the mechanism (twip quantization, gradient ramp/focal math, AA tie, colour rounding), and price it. Memories that killed past "AA ties": vertex quantization, integer twips, gradient banding = sub-pixel phase. Prototype the cheap ones with the full render-canary md5 sweep; deliver a ranked GO list. Check the playbook for STRIKE / NO-GO entries on each row first.

Siblings: `w1-pixel-text` owns text rows, `w1-pixel-blend-mask` blend/mask rows, `w1-pixel-drawing` drawing-API/stroke rows.
