# Session 25 — worker launch-order / id map

Mode: CLOUD-FIRST (user directive 2026-10-16, re-confirmed 2026-11-22): every slot is a cloud session in env
"SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator
local (merge, CI dispatch, results accounting, exporter oracle). Size: full (user 2026-11-22: fan-outs also use
expiring credits, so diminishing returns are fine).
Trace baseline: run `45043930556` (graphics/full) at `746c39489`, results `7f945eb41` (merged `64c742e9e`): 4613 eff,
49 failing graphics rows. Pixel baseline: s24 final `44986836161` at `9561027db` (results `08fdbcad6`): 539 / 613.
Upstream `bcac30c19..3ac8dcb07` (9 commits, 3 new AVM2 tests) — `wave0-upstream-drift-namestatus.txt`.
Wave-0 local oracles (exporter `0ddd12b6a`): `w0-local-oracles/` (attach Ratio + PO3 variants == fixture oracle;
Array generics on Function/MovieClip receivers work in Ruffle).
Parallel LOCAL one-task session: `n-play-game` (N "play game" click does nothing; wsl-launch, Opus, PID 57630,
handshake sent).

## Wave 1 (diagnosis, cloud)

| # | slug | axis | task | session id |
|---|---|---|---|---|
| 1 | w1-drift-avm2 | trace | 3 new upstream AVM2 rows (ShaderJob 1/2-channel, recreateTextLine width, LC allowNetworking) | session_018CoDi6J5YQJTWUQrMyZKvW — DELIVERED; prototype LANDED directly `1a10f176e` (+2: `pixelbender_shaderjob_output_channels`, `textblock_recreate_text_line_width`; LC row drift already passing; 0 riders/53, both modes; touches recompiler + browser-shared header → Pages dry run at grading) |
| 2 | w1-textfield-vn | trace | gnash TextField-v6/7/8 plan of record (13 phases) + edittext_set_text_same pair | session_018CoDi6KKD2sWxiZX1qXQHn — DELIVERED; +46/+48/+49 lines, 0 flips yet (ruffle_matched needs 6-8 more phases, ≈L); plan of record's Phase-2 mechanism refuted (props live on the prototype, defined at first instantiation) → w2-textfield-vn, w2-edittext-span-model |
| 3 | w1-avm1-proto-timeline | trace | loaded-root goto routing, TextFormat accessors, attach L4/L5/L2 (oracles in hand) | session_018CoDi7npxwH9NpjHNi23Dm — DELIVERED; prototype LANDED directly `5b50cd4a0` (+1 trace `text_format_prototype_lazy` (s24 "L" refuted); L4 + L5 fixed; +3 fixtures; 0 moves/123 rows). `video_prototype_lazy_swf6_child` NO-GO at L (loaded child depths collide in the shared display list → per-movie display list arc, board); L2 parked (no row); L5 "String object" row was a probe artifact (0x53 = NewMethod) |
| 4 | w1-avm1-filters-complete | both | AVM1 PO3 multi-filter, getter depth, CM/Convolution/DM, dynamic-root bitmaps/text | session_018CoDi7rZSo5uSZfocqWxZk — DELIVERED; 0 corpus flips (game-visibility family); prototype items 1+2+3a+4 ORACLE-CONFIRMED locally (dyn_ABD Ruffle render == prototype render; l1 nested == root) → w2-avm1-filters + w2-dynclip-cxform |
| 5 | w1-pixel-nearpass | pixel | ~17 small-excess comparisons | session_018CoDi459cXj5v4ThUCiZ74 — DELIVERED; GO +6 px measured (doubleAndRegister, acid-scale, acid-gradient-2, acid-gc, bitmapdata_draw_rotation, gradient_focal_point); 5 hunks incl. lyon stroke joins (recompiler) → w2-nearpass-land |
| 6 | w1-pixel-text | pixel | acid-text*, captions, hardwrap, stylesheet, edittext device transform/gutter, static_text_offstage (c), acid-color-0 | session_018CoDi7WfMsx8cJhBoubZ9c — DELIVERED; prototype LANDED directly `20cd63b32` (+3 px: `edittext_device_transform_basic`, `_negative`, `edittext_gutter`; firing probe 116 tests) → w2-acid-text-kerning; button-bound EditText (`String_path_variable_button`) HELD until n-play-game lands |
| 7 | w1-pixel-blend-mask | pixel | layer_alpha/erase, masks, colortransform, place_object_test, bitmapbuttons | session_018CoDi3WCycTC59VRC5FWW5 — DELIVERED; prototype LANDED directly `ee9ea8738` (+3 px: `layer_alpha`, `layer_erase`, `bitmapdata_colortransform`; canary 164/164; s21 layer NO-GO refuted) → w2-avm2-layer-groups, w2-netstream-flv-screen, w2-acid-morph-gradient |
| 8 | w1-pixel-drawing | both | drawing API, strokes, bitmap fills, dithering; DrawingApiTest hitTest plan | session_018CoDi7j4VX9FRpURSWw5EY — DELIVERED; prototype LANDED directly `0f35012bd` (+2 px `drawing_order`, `cache_as_bitmap/drawing_api`; band line_gradient_style 1023→33; DrawingApiTest 12→5+2 lines, plan of record refuted; sweep 177 cmp) → w2-avm2-cm-copyfrom, w2-avm1-with-scope |

## Wave 2 (implementation, cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|
| (landed direct) w1-drift-avm2 prototype | w1-drift-avm2 | trace `pixelbender_shaderjob_output_channels`, `textblock_recreate_text_line_width` (+2) | — |
| (landed direct) w1-pixel-blend-mask prototype | w1-pixel-blend-mask 1+2 | px `layer_alpha`, `layer_erase`, `bitmapdata_colortransform` (+3) | — |
| (landed direct) w1-avm1-proto-timeline prototype | w1-avm1-proto-timeline L4+L5+item 2 | trace `text_format_prototype_lazy` (+1); fixtures `avm1_attached_clip_tagorder_ratio/_po3`, `avm1_array_generic_receivers` | — |
| (landed direct) w1-pixel-text prototype | w1-pixel-text A+B | px `edittext_device_transform_basic`, `edittext_device_transform_negative`, `edittext_gutter` (+3) | — |
| (landed direct) w1-pixel-drawing prototype | w1-pixel-drawing A+B+C | px `drawing_order`, `cache_as_bitmap/drawing_api` (+2) | — |
| w2-avm1-filters | w1-avm1-filters-complete 1+2+3a+4 (+XS side bugs) | 0 corpus; new `regression/avm1_runtime_filters_cm_bitmap`, `avm1_nested_po3_filters` | session_018CoDi6SmBg5ngKPi9f1Fi1 — DELIVERED, LANDED `f2325de53` (2 fixtures at max 0; side bugs a+b; coordinator merge fix: fillAttachedBitmapInfo missed dynclip's cxform fields → garbage slot) |
| w2-dynclip-cxform | w1-avm1-filters-complete 5+3b | 0 corpus expected; new `regression/avm1_dynclip_color_transform` | session_018CoDi86KRFXMH7buLiVYv9 — DELIVERED, LANDED `d83fbab22` (fixture pixel-exact vs Ruffle; coordinator 3-way merge with 0f35012bd in apply_dynamic_mc_transforms) |
| w2-acid-text-kerning | w1-pixel-text C | px `acid-text` (likely, unmeasured) | session_018CoDi5bPZfEpmUKXk6hibE — DELIVERED, LANDED `7d1d2bd6e` (+1 px `acid-text` 3429 → 0; 200/201 PNGs identical) |
| w2-netstream-flv-screen | w1-pixel-blend-mask L1 | px `netstream_play_flv_screen` (possible; ignored row → prune) | session_018CoDi3Vyahsk5YixoaurwN  — DELIVERED, LANDED (+1 px; cause = timer.c method-form MC receiver `this`, game-visible; RVF entry refuted + removed; fixture held: exporter never fires timers) |
| w2-avm2-layer-groups | w1-pixel-blend-mask L4+L5 | 0 corpus; fixtures | session_018CoDi4yHAmxMG1pYf1JQnB — DELIVERED, LANDED `a281b60d4` (exact nested child layer + AVM2 port; 6 fixtures, all goldens confirmed vs local Ruffle exporter; canary 171/171) |
| w2-acid-morph-gradient | w1-pixel-blend-mask L2 | px `acid-morph` (unpriced) | session_018CoDi5kNpLqLbTbXGooXKw — DELIVERED, LANDED `78f15f639` (+1 px `acid-morph`; premise refuted: recompiler morph ramp over-emitted rows; generated C identical for 122 SWFs). NB commit trailer carries the worker's session URL by mistake |
| w2-nearpass-land | w1-pixel-nearpass D+A+C+S+B | px +6 (+1 if B finishes) | session_018CoDi6T6H97ToTZbb3Tbeb |
| w2-textfield-vn | w1-textfield-vn P0-P21 | trace gnash `TextField-v6/v7/v8` → ruffle_matched | session_018CoDi4kG6RDoukZHuF7UbE |
| w2-edittext-span-model | w1-textfield-vn §4 | trace `edittext_set_text_same` (pass), `_after_edits` (rm) | session_018CoDi43SuykYDpM156pYNz |
| w2-avm2-cm-copyfrom | w1-pixel-drawing D+E | px `bitmapdata_draw_filters`, `graphics_direct_commands` (unpriced) | session_018CoDi8AeP44PYDaUTrzWMN |
| w2-avm1-with-scope | w1-pixel-drawing C residual | trace DrawingApiTest lines (flip unpriced) | session_018CoDi645BCNVuhoF2enBcy |

## Grading runs

| run | mode / categories / images | code | result |
|---|---|---|---|
| 45060637552 | graphics / full / **images** | 2f7be1710 (drift-avm2 +2 trace; blend-mask +3 px; pixel-text +3 px) | **DONE, ledger exact**: trace 4613 → 4615 eff / 4662 (+2 by name: `pixelbender_shaderjob_output_channels`, `textblock_recreate_text_line_width`), 0 regressions; pixels 538 → 544 (+6 by name), 0 regressions. Pages dry run 45060640334 success. Results merge (this commit series) |
| 45065076248 | graphics / full / **images** | 9e24c763c (+ proto-timeline +1 trace/3 fixtures; pixel-drawing +2 px; acid-morph +1 px; layer-groups 6 fixtures; n-play-game 8615da904 1 fixture) | pending (Pages dry run 45065078933) |
