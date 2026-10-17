# Session 22 — worker launch-order / id map

Mode: CLOUD-FIRST (user, 2026-10-16) — every slot is a cloud session in env "SWFRecomp fan-out"
(`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator local.
Baseline: trace 4476 eff / 4551 (results `846adcc6b`, run on `4c450f076`); pixels 433/587
(images run `36515003936`). Upstream Ruffle synced `0dacba55f → 45366370e`.

## Wave 1 (diagnosis, 8 cloud workers — the concurrency cap)

| # | slug | axis | task | session id |
|---|---|---|---|---|
| 1 | w1-drift-avm1 | trace | AVM1 + gnash upstream drift (matrix/point/rectangle/context_menu rewrites, html img, AsBroadcaster) || session_017xPdvNzD1QpqzmWFhA57de (launched 22:03-22:06 UTC) |
| 2 | w1-drift-avm2 | trace | AVM2/fonts drift + harness semantics (num_ticks, NaN approx, ignore=true) + ignore re-test || session_014EjHH1tFvHsTTfCCHkmjPV (launched 22:03-22:06 UTC) |
| 3 | w1-crossvm | trace | cross-VM focus/pick/load-tick (6 rows) || session_01JQNgzi4t3ZGaDTvM1T8xmi (launched 22:03-22:06 UTC) |
| 4 | w1-trace-tail | trace | non-drift tail (MovieClip-v8, action_order, bug_483783 runtime_error, …) || session_01734S8K85eFhPCKDv96jBos (launched 22:03-22:06 UTC) |
| 5 | w1-stroke-staircase | pixel | 1-px stroke staircase parity, measured prototype || session_01XtPiAcw52mKcDbppWVpxJ5 (launched 22:03-22:06 UTC) |
| 6 | w1-offstage-filter | pixel | filter-layer bounds/edges, cab_mask_filters || session_01XoYMLVMtoh9SnQQwDhA41J (launched 22:03-22:06 UTC) |
| 7 | w1-pixel-smalls | pixel | near-passes + smalls; image-side ignore=true || session_01Tx6MKHzYM21omW2dfQGpry (launched 22:03-22:06 UTC) |
| 8 | w1-pixel-catastrophic | pixel | blank/unrelated/missing/wrong-fill clusters || session_01Fjmpo6LuUS5wfQZkUVsJaz (launched 22:03-22:06 UTC) |

**Pre-labelled DRIFT for the next CI read (w1-drift-avm1):** hidden pass→fail `avm1/as_broadcaster`,
`avm1/array_constructor` (→ SEGFAULT on new test); ruffle_matched→fail gnash `AsBroadcaster-v6..v8`,
`array-v6..v8`; deleted upstream `as_broadcaster_initialize`, `as_broadcaster_undef`,
`avm1/html_text_img_parsing`. None of these is a code regression.

## Wave 2 (implementation, cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|
| w2-array-global | w1-drift-avm1 S2 | array_constructor, gnash array-v6..v8 | session_016pAABBwk2wbPvc3rNN3pCE — LANDED (see log) |
| w2-as-core | w1-drift-avm1 S1 | as_broadcaster, AsBroadcaster-v6..v8, context_menu, context_menu_item, context_menu_swf6, as_setup_error | session_01CFASq4VYcgHb1361oQ9iiP — LANDED (as_broadcaster now expected to pass with array-global) |
| w2-crossvm | w1-crossvm slots 1-3 | mouse_pick_scroll_rect(+_loader,_button), mouse_pick_loader_avm1, avm2_loads_avm1_events (rm) | session_01WJfTLXUUuxzstmVBA8k32L — LANDED |
| w2-queue-regex | w1-trace-tail A | action_execution_order_test6 (rm), pcre_find_fixedlength | session_014xtNST7fsKSbQ6RVBmTLTy — LANDED |
| w2-goto-collator | w1-drift-avm2 slots 1(goto)+2 | goto_queued_invalid/swf9..11, collator_flags, collator_locale_ids_windows, collator_compare_basic | session_01HGTgTnncXGJ4Bi7uRJykNT — LANDED e783f14e5 |
| w2-float-verts | w1-stroke-staircase slot 1 | +22 px (12 blend_modes, masks pair, overlaps, scroll_rect_mask, heavy_tesselation, layers, blur_size_grows, color_matrix, avm2_button_scroll_rect, cab/avm2_button), −1 acid-small .05 | session_01GHaXsGDyCCvNJRoQh1p9mE — LANDED (main patch; morph leg HOLD) |
| w2-filter-fixes | w1-offstage-filter | any_blur_scales_with_screen, cab_mask_filters, acid-filter-2 | session_013VbsEmy2b4JKfMBadEJTrh |
| w2-drawing-api-lyon | w1-pixel-smalls W2-B | MaskTest, displayobject_opaque_background, fills_and_lines, graphics_draw_path | session_01W4qaTLdonsB2sRwZP3LAmB — LANDED |
| w2-glyph-subunit | w1-pixel-smalls W2-C | fonts/glyph, match_style, fallback_preferences | session_01KmL6XEUPUAPhFxEHtV67RK — LANDED |
| w2-default-fonts-draw | w1-pixel-catastrophic | text-bind, cab/text, bitmapdata_draw_masks, bitmapdata_draw | session_01MSbMWKPyx6Jy1iTxnUmLff — LANDED (+3; bitmapdata_draw band only, baseline HOLD) |
| w2-htmltext | w1-drift-avm1 S4 + w1-drift-avm2 §1.4 | edittext_html_duplicate_attributes, html_text_img_parsing_swf7/_swf8, html_text_img_numeric_attributes, avm2/html_text_img_parsing (rm) | session_01TTs24XtdUhz4v7x5CtLiMw — LANDED (+5; dup_attributes 241/247 not a flip) |
| w2-strbuf | w1-trace-tail B | bug_483783 (runtime_error -> pass) | session_01NLFHMLUtdLyVm8z4tkEcfq — LANDED |
| w2-geom-port | w1-drift-avm1 S3 | point, rectangle, matrix, Rectangle-v8, Matrix-v6..v8 | session_019oWz76tcX3D7afubJF3Wbg |
| w2-avm2-stage-view | w1-pixel-catastrophic | pixelbender_effect_glassDisplace, displayobject_z | session_01Sv4zxmSzXYtd4doWuLve4R — LANDED (+3 incl. geom_transform) |
| w2-font-registry | w1-trace-tail D | fonts/embed_name_lookup | session_01SKhEcTjpjxygKijBE1r4Dz |
| w2-ei-provider | w1-trace-tail C | avm2/external_interface | session_0171KTbmxMRKzLEq2FKryiT6 — LANDED |
| w2-atf-dxt5 | w1-pixel-catastrophic | stage3d_texture_bytearray_compressed_raw_alpha | session_01BCEB1oUi9rtAyWJhxtUX72 |
| w2-avm2-video-stamp | w1-pixel-catastrophic | visual/video/h264_multinalu | session_013tm6bjkHMY5ugv1wytug2c |
| w2-draw-bigcap-aa | w1-pixel-catastrophic | acid-bitmap-draw_quality_high/_low | session_01LXYQe4b2PbkKvF1qAiQgQg |
| w2-hairline-device-width | w1-stroke-staircase L1 | acid-small .05 (recover), .01, acid-scale, simple_loop_test | session_01JmdeVMCdk5knmRhi5YiyES |

**Queue:** empty — 21 wave-2 slots funded (s21-sized budget reached); further leads go to the s23 board.
| w2-jpegxr | user-approved dep | loader_jpegxr, loader_jpegxr_alpha, stage3d_texture_bytearray, _compressed_alpha | session_017A1bzC1vtg96PMxQT8BxpM — LANDED 5dee7a4b4 |

**Merge obligations (DISCHARGED: as-core builds `_listeners` as a literal):** at w2-as-core merge, `installAsBroadcaster`'s `_listeners` must go through `arrayResolveGlobalCtor()` (w2-array-global report §4; flips the as_broadcaster "with Array replaced" line) unless as-core creates it as a literal. Follow-up for after as-core: `actionCallMethod` object-method arm alias dispatch for `Array` (`pushArrayCalledAsFunction`).

**Local oracle requests (batch into ONE exporter rebuild near closeout):**
- w2-strbuf: Ruffle exporter run of `regression/avm2_strbuf_stale_prefix/test.swf` to confirm its ECMA-derived `output.txt` (report §LOCAL ORACLE REQUESTS).
- w2-as-core / w1-drift-avm1: closure-as-method fixture oracle (optional).
- w1-pixel-catastrophic: `font_lookup_as3` golden provenance; `stage3d_bitmap` RNG/timer trace; `bitmapdata_draw` line metrics; `displayobject_z` render (all optional).
