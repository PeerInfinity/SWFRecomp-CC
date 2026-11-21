# Session 23 — worker launch-order / id map

Mode: CLOUD-FIRST (user directive 2026-10-16, re-confirmed 2026-11-21): every slot is a cloud session in env
"SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator
local (merge, CI dispatch, results accounting, exporter oracle).
Session-start infra fix: `08709f658` pins CI runners to `ubuntu-24.04` (`ubuntu-latest` = 26.04 has no
swfmill; the weekly canary's WASM link-smoke had failed 4 weeks running; also keeps CI lavapipe == cloud env).
Baseline runs at `08709f658` (upstream `0ddd12b6a`): graphics/full/images `44922638965`, no-graphics/full
`44922646202`.

## Fresh baseline (17:30 UTC)

**FRESH BASELINE (landed 17:30 UTC, merged to master at `12ecaf53c`; read by the coordinator):** graphics/full/images
run `44922638965` at `08709f658` vs s22 final `8d83af7e2`: trace intersection 4563 rows, effective **4503 → 4495 (−8)**;
all graded rows **4625 effective / 4752**. Pixels: intersection 587, pass **490 → 487 (−3)**; plus 6 NEW comparisons
(1 pass: `visual/scroll_rect_culling`) → **488 / 593**. **Every move is upstream drift** (the row's `output.txt`,
`output.ruffle.txt` or `output.expected.png` changed in `45366370e..0ddd12b6a`); no row moved without a test change, so
the CI rasterizer did not change (runner pin `08709f658` worked; WASM link-smoke green again).
- Trace drift losses: `avm1/netconnection_serialize_arrays` (pass→fail), `avm2/filereference_browse_select` (pass→fail),
  `avm2/event_handler_exception`, `from_avmplus/as3/RuntimeErrors/Error1092XmlUnterminatedXmlDecl`,
  `from_avmplus/e4x/XML/bug_564468`, `from_avmplus/e4x/XML/misc_errors`, `from_avmplus/regress/bug_478501`,
  `from_gnash/misc-ming.all/NetStream-SquareTest` (ruffle_matched→fail: sidecar changed or deleted).
- Pixel drift losses: `avm2/graphics_draw_path`, `visual/cache_as_bitmap/avm1_color` (re-goldened `e7d71c98b`, +`output.ruffle.png`),
  `avm2/stage3d_texture_bytearray_compressed_alpha` (`5021d0ed7`). Worsened bands (re-goldened): `Video-EmbedSquareTest`,
  `graphics_simple_shapes`, `graphics_gradients`, `sprite_with_frames`. New failing comparisons: `bitmapdata_encode_jpeg_visual`,
  `bitmapdata_encode_png_visual`, `context3d_draw_to_bitmap_data`, `visual/filters/empty_child_filter_bounds`, `visual/static_text_offstage`.
- `origin/ruffle-image-results` now holds this run's failing PNGs (commit `10e5e39ca`), so fidelity checks compare against run `44922638965`.

## Wave 1 (diagnosis) + direct wave-2 slots

| # | slug | axis | task | session id |
|---|---|---|---|---|
| 1 | w2-crossvm-legf | trace | cross-VM leg F (focus_events_mixed_avm_edittext, selection_onsetfocus_mixed_avm), direct wave 2 | session_018CoDi4rG1CSwsyx1QLEnLz — LANDED `d35a55154` (+2) |
| 2 | w1-trace-tail | trace | html dup-attr CSS, movieclip_destruction_test3/4, audio aac/g711, new s22 upstream rows, NO-GO reconfirm | session_018CoDi4r4bKbsW24Nr5EZWc — DELIVERED 16:54 (+7 priced; slots A-F) |
| 3 | w1-filter-label | pixel | glow/drop_shadow/bevel_* label glyph pixels (7 rows) | session_018CoDi3uVweQJapey3LuzYo — DELIVERED 16:45; mech A = 7e2a045c1 (confirmed independently), mech B → w2-glyph-levien |
| 4 | w1-padded-filter | pixel | drop_shadow_angles, displacement_map, bevel edge row | session_018CoDi4bjPQagEMxkuV7Yx4 — DELIVERED 16:56 (+2 px; bevel y=305 refuted → oracle) |
| 5 | w1-glyph-precision | pixel | morph_test1/Video-EmbedSquareTest glyph pixels, edittext_scroll, bitmapdata_draw, shape_test attribution | session_018CoDi4gT9iTUdsyJmtmsV5 — DELIVERED 16:32; prototype LANDED directly `7e2a045c1` |
| 6 | w1-pixel-misc | pixel | Spark decode, ShaderFilter/blendShader, stage3d_texture, acid-color-0, definefont4, ignore=true/subtest harness | session_018CoDi4JVo1n3vja6iLtpWF — DELIVERED 16:58; FAAN LANDED `7b6a69124` |

| 7 | w2-glyph-levien | pixel | productionize w1-filter-label mech B (recompiler device-font glyph Levien + float); glow trio, bevel_* ×3, glow_with_alpha_strength | session_018CoDi74CQBH5j8NnH5mCXM — LANDED `57015b2db` (+7 px) |

| 8 | w2-tf-css | trace | trace-tail slot A: AVM1 htmlText CSS + getTextFormat url/para; + 5 new upstream getTextFormat rows | session_018CoDi3RqHac9QhfSJkkY34 — LANDED `228a5ff0c` (+4) |
| 9 | w2-attached-timeline | trace | trace-tail slot B: attached clips run natural timeline in CI modes; movieclip_destruction_test3/4 | session_018CoDi5yeX7FkuGneLRRe8H — LANDED `3cdde8be0` (+2) |
| 10 | w2-padded-filter | pixel | productionize w1-padded-filter (gated padded filter layer); drop_shadow_angles, displacement_map | session_018CoDi6x1pyS9L9PSYoDJZL — LANDED (+2 px) |
| 11 | w2-stage3d-text | pixel | Stage3D RTT + budget 48M, AVM2 default-font advance rounding; stage3d_texture, stage3d_bitmap | session_018CoDi7QtMALGjWbWyYvecw — LANDED (+2 px) |
| 12 | w2-netstream-audio | trace | trace-tail D: NetStream audio tap + computeSpectrum; audio/aac, audio/g711 | session_018CoDi3x3Uds6hHMQAvVQFk — LANDED (+2 graphics) |
| 13 | w2-qname-dict | trace | trace-tail C: QName multiname keys + #1069 rule; dictionary_qname_keys | session_018CoDi78a5woqe4YXREWSin — LANDED (+1) |
| 14 | w1-drift-avm1 | trace | AVM1/gnash/shumway upstream drift 45366370e..0ddd12b6a | session_018CoDi7LLFpbdSTkfTYwW6s — DELIVERED 18:11; prototype LANDED (+8) |
| 15 | w1-drift-avm2 | both | AVM2/visual/small-suite drift + harness num_ticks | session_018CoDi6ghpj4pXCMReEcqgP — DELIVERED 18:00; prototype LANDED (+15 trace, +2 px) |
| 16 | w2-avm1-devicefont | trace | trace-tail F: AVM1 device-font registry; fonts/device_font_name_case | session_018CoDi6nBjtTJ4GPXVQ2ife — LANDED (+1) |
| 17 | w2-avm2-small-errors | trace | drift-avm2 S9 | session_018CoDi3zkCYHJCnpQGnoYp3 — LANDED (+6 eff) |
| 18 | w2-stack-trace-names | trace | drift-avm2 S7 | session_018CoDi3a6sipw1TH1D3Q1bY — LANDED (+2) |
| 19 | w2-array-vector-args | trace | drift-avm2 S5 | session_018CoDi3UaEumY9kycvtZWDx — LANDED (+5) |
| 20 | w2-tf-css-avm2 | trace | AVM2 TextField format twins | session_018CoDi5BFztjYCFbFqJUhD8 — LANDED (+4 eff) |
| 21 | w2-context3d-readback | both | drift-avm2 S4: drawToBitmapData + #3692 | session_018CoDi61VeqnzLTiyF5rwmk — LANDED (+3 trace, +1 px) |
| 22 | w2-doc-removal-events | trace | drift-avm2 S8 | session_018CoDi7jBSFh59hTPEMaK7G — LANDED (+3) |
| 23 | w2-video-props | trace | drift-avm1 V: Video width/height lazy accessors | session_018CoDi3srDrx6YECoWarZYc — LANDED (+2 eff) |
| 24 | w2-harness-subtests | px (instrument) | ignore=true + [subtests] images + drawWithQuality + report-only ruffle-png bucket | session_018CoDi5m6iYZTWzXtXE2S8s — LANDED (instrument) |
| 25 | w2-xml-status | trace | drift-avm1 M3 XML status + AVM1 bundle | session_018CoDi58gxyHZVyRcAu87S1 — LANDED (+6) |
| 26 | w2-dynclip-transform | px+correctness | AVM1 nested dynamic-clip transform/alpha inheritance (empty_child_filter_bounds) | session_018CoDi57QaPasoFxvAJyUzd — LANDED (correctness, 0 flips) |
## Landed patches + expected ledgers

| commit | from | expected (CI check) |
|---|---|---|
| `7e2a045c1` | w1-glyph-precision prototype (landed directly, no w2 slot) | px fail→pass: `misc-ming.all/morph_test1` frame2..6, `cache_as_bitmap/edittext_scroll .02`, `simple_shapes/text_field_mask`, `shumway acid-text-escape` (+8); md5 moves on passing `edittext_scroll .01`, `text-bind`, `cache_as_bitmap/text`; trace: none. Drift: `Video-EmbedSquareTest` re-goldened upstream (`74323048b`, Flash HQ + KF), not yield |
| `d35a55154` | w2-crossvm-legf | trace fail→pass (both modes): `avm2/focus_events_mixed_avm_edittext`, `avm2/selection_onsetfocus_mixed_avm`; pixels none |
| `7b6a69124` | w1-pixel-misc §1 (FAAN IDCT, landed directly) | px fail→pass: `avm2/netstream_play_flv`, `avm1/netstream_play_flv`, `visual/video/deblocking`; `colorconversion/h263` 10808→3 (still fail); trace none |
| `57015b2db` | w2-glyph-levien | px fail→pass: `visual/filters/glow`, `glow_without_composite_source`, `drop_shadow`, `bevel_inner`, `bevel_outer`, `bevel_full`, `glow_with_alpha_strength` (last 4 at 18/18 zero headroom); md5 moves on passing text-bind, cache_as_bitmap/text, edittext_scroll .01; trace none |
| `9ba5e552c` | w2-netstream-audio | trace fail→pass GRAPHICS: `audio/aac`, `audio/g711`; NO-GRAPHICS: `audio/g711` only (`audio/aac` stays fail by design: no libavcodec in no-graphics builds → known mode-parity gap, 1 row); pixels none. AAC mono 44.1k/48k depend on matching Ruffle's mixer-clock alignment (fragile, see report §2) |
| `228a5ff0c` | w2-tf-css | trace fail→pass (both modes): `avm1/edittext_html_duplicate_attributes` (KF, Flash-exact pass), `textfield_get_text_format_args`, `textfield_set_text_format_args`, `textfield_set_text_format_text_change`; HOLD (L): `edittext_set_text_same(_after_edits)`; pixels: md5-only canary members added |
| `3cdde8be0` | w2-attached-timeline | trace fail→pass (both modes): `from_gnash/misc-swfc.all/movieclip_destruction_test3`, `_test4` (Flash-exact); pixels none |
| `353732f52` | w2-padded-filter | px fail→pass: `visual/filters/drop_shadow_angles`, `visual/filters/displacement_map`; md5 move on passing `displacement_map_scales_with_screen`; trace none |
| `ca9c46595` | w1-drift-avm2 prototype (S1, landed directly) | trace +15 (graphics): drift re-flips `avm2/event_handler_exception` (→rm), `avm2/filereference_browse_select`, `from_avmplus/as3/RuntimeErrors/Error1092XmlUnterminatedXmlDecl`, `from_avmplus/e4x/XML/bug_564468` (→rm), `e4x/XML/misc_errors` (→rm), `from_avmplus/regress/bug_478501`; new rows `avm2/xml_unescaping_nul_char_ref`, `xml_many_namespace_declarations`, `edittext_event_link_case_insensitive`, `bitmapdata_encode_png_visual`, `bitmapdata_encode_png_roundtrip`, `bitmapdata_encode_jpeg_visual`, `textfield_default_text_format_null`, `perspective_projection_center`, `allow_networking` (NEW graded row via harness H1 subtest discovery; also `avm1/allow_networking_import_assets(2)` become graded — unpriced). px +2: `stage3d_texture_bytearray_compressed_alpha`, `bitmapdata_encode_png_visual` |
| `cfbcb6658` | w2-stage3d-text | px fail→pass: `avm2/stage3d_texture`, `avm2/stage3d_bitmap`; bands improve: `visual/fonts/font_lookup_as3` 19560→11592, away3d_shallow_water, stage3d_fractal; trace none (23 with_default_font rows identical both modes) |
| `0798e815a` | w2-qname-dict | trace fail→pass (both modes): `avm2/dictionary_qname_keys`; 311-row #1069/#1081/ReferenceError sweep 0 other moves; pixels none |
| `cfc56d74b` | w1-drift-avm1 prototype (landed directly) | trace +8 (both modes): `avm1/netconnection_serialize_arrays` (drift re-flip), new rows `array_truncation_non_canonical_keys`, `sparse_array_truncation_non_canonical_keys`, `amf_array_indices`, `localconnection_serialize_function_array_elements`, `xml_stringify_utf16`, `amf0_utf8_probe`, `shared_object_secure`; partial `amf0_array_matrix` 39→49/50, `localconnection_serialize_sparse_array_getters` 23→25/26; pixels none |
| `995782154` | w2-context3d-readback | trace fail→pass (both modes): `avm2/context3d_draw_to_bitmap_data`, `avm2/stage3d_missing_vertex_stream` (KF, Flash-exact pass), `stage3d/draw_to_bitmap_data_unconfigured`; px fail→pass: `avm2/context3d_draw_to_bitmap_data` |
| `9cf79e2fd` | w2-stack-trace-names | trace fail→pass (both modes): `avm2/error_stack_trace_class_names`, `avm2/error_stack_trace_limit`; 93-row `at`-frame sweep 0 other moves; pixels none |
| `6f65d2115` | w2-tf-css-avm2 | trace (both modes): fail→pass `avm2/textfield_get_text_format_args`, `avm2/textfield_set_text_format_args`, `avm2/edittext_set_text_same`; fail→ruffle_matched `avm2/edittext_set_text_same_after_edits` (KF; Flash/Ruffle disagree, Flash-exact HOLD); pixels none (md5-only canary members added) |
| `be53cbeaf` | w2-array-vector-args | trace fail→pass (both modes): `avm2/array_join_reentrant`, `avm2/vector_join_reentrant` (KF), `avm2/array_sort_arguments` (KF), `avm2/vector_sort_arguments` (KF), `avm2/array_constructor` (Flash-exact, avmplus source as oracle); 237-row sweep identical to CI; pixels none |
| `f5613a76c` | w2-avm1-devicefont | trace fail→pass (both modes): `fonts/device_font_name_case` (misc group → needs categories=full); pixels none. New generated `RecompiledTags/device_fonts.c` for AVM1 movies with named [fonts.*] faces |
| `00077a281` | w2-doc-removal-events | trace fail→pass (both modes): `avm2/displayobjectcontainer_remove_reentrant`, `_remove_reparent`, `_removechildren_events`; 141-row add/remove sweep exact; pixels none |
| `72ef0be14` | w2-harness-subtests (GRADING INSTRUMENT) | image report: denominator **+2** (ignored rows excluded; `[subtests]` rows keyed `<subtest>__<cmp>`; version-keyed subtests canonical-variant only), passes **+2** (`avm2/bitmapdata_drawwithquality` low__output.low + high__output.high, via drawWithQuality→bd_draw), fails ±0 (−`avm2/bitmap_pixelsnapping` → ignored, +`visual/edittext/edittext_device_transform_basic [embedded__output]` fail); new totals ignored=6, ruffle_matched_fail=9 (report-only: graphics_draw_path, cache_as_bitmap/avm1_color, …); band: `bitmapdata_draw_cab_quality` 2320→2640 (alias exposes a separate gap); `fonts/leading_device_font output` → `embedded__output` RENAME (image_status_diff pairs it); trace 0 moves |
| `a0b18bc93` | w2-video-props | trace (both modes): `from_gnash/misc-ming.all/NetStream-SquareTest` fail→ruffle_matched (KF; last drift re-flip), `avm1/video_width_height` fail→pass; partial `video_prototype_lazy` 9→20/21, `_swf6_child` 2→4/8; pixels none |
| `c216160c4` | w2-dynclip-transform (correctness) | px: `visual/filters/empty_child_filter_bounds` fail→fail 72840→24876 (no flip); 169-PNG A/B otherwise md5-identical; trace none. Lead R1: AVM1 runtime `mc.filters = [...]` is never rendered on ANY clip (1 corpus row, game-visible) |
| `64e1aa60a` | w2-avm2-small-errors | trace (both modes) fail→pass: `avm2/shared_object_get_local_error`, `loaderinfo_root_progress`, `loaderinfo_root_progress_goto`, `amf_xmllist`, `hit_test_scroll_rect`; fail→ruffle_matched `from_shumway/as3-loader/events/loader-events` (KF; via Flash-correct root progress line); pixels none |
| `fcd7e1335` | w2-xml-status | trace fail→pass (both modes): `avm1/xml_status_mismatched_tags`, `file_reference_listeners_per_instance`, `localconnection_serialize_inherited_array_indices`, `localconnection_reference_identity`, `shared_object_members_swf5`, `edittext_asfunction_case_insensitive`; must stay rm: gnash XML-v5..8, XMLNode-v5..8, NetConnection-v6..8; pixels none |

## Leads held for wave 2 (from delivered reports)
- glyph-precision lead 1: per-line max ascent/descent for the AVM1 render pitch (`br_at_start`, `style_changes_in_html`).
- glyph-precision lead 2: quality=low hairline tie-break (Flash takes the +0.5 px side); `shape_test` 17911 attributed to `e62daeb6f`. A/B on `acid-small .01/.05` first.
- trace-tail slots queued (launch as cloud slots free): C `w2-qname-dict` (avm2_ops.c; dictionary_qname_keys +1; full CI for #1069/#1081), D `w2-netstream-audio` (audio/aac, g711 +2), E `w2-definefont4` (textline_metrics +1, recompiler DefineFont4), F `w2-avm1-devicefont` (device_font_name_case +1).
- trace-tail oracle request 1: DONE 18:10 — `w2-attached-timeline-probe/output.ruffle-exporter-45366370e.txt` (Ruffle exporter, 8 frames). Ticks ≥2 are IDENTICAL to ours (newest-first, child-before-parent, root last; stopped / 1-frame containers animate children). Attach tick DIFFERS (pre-existing, untouched by the patch): Ruffle runs each attached clip's timeline child frame 1 BEFORE its parent (`kid, kid2, stopper, kid3, multi`), we run parent first (`kid, stopper, kid2, multi, kid3`). Lead → s24 board / small slot; a `regression/` fixture from this probe would fail on that tick today, so none added.
- padded-filter oracle request (bevel row 305 at quality=low): DEFERRED — the local exporter has no quality option (renders at default/high quality on a real GPU, so it cannot answer a 1-sample point-sampling tie); needs Ruffle's own test runner (`cargo test` of the tests crate on lavapipe) or an exporter `--quality` patch. 0 flips at stake (disposition only). s24 board / optional.
- pixel-misc queued: `w2-harness-subtests` (§4 GRADING-INSTRUMENT: ignore=true + [subtests] images + drawWithQuality alias; land AFTER an interim images run so attribution stays clean), `w2-text-cxform` (§3b acid-color-0 band, AVM1/timeline text gets ancestor colour transforms; correctness, 0 flips), `w2-shaderfilter` (§2a glassDisplace_shaderfilter +1 medium; rider pixelbender_dithering).

## Grading runs

| run | mode / categories / images | code | result |
|---|---|---|---|
| 44922638965 / 44922646202 | graphics/full/images + no-graphics/full | 08709f658 (baseline) | trace 4495/4563 intersection (4625/4752 all); pixels 488/593; all moves vs s22 = upstream drift |
| 44930669727 / 44930677490 | graphics/full/images + no-graphics/full | bc91565ce (7e2a045c1, d35a55154, 7b6a69124, 57015b2db) | graphics: trace **4515 → 4517/4642** (+2 = the two focus rows; 0 regressions, 0 other moves); pixels **488 → 506** on the 593-comparison intersection (+18 = exactly the 7e2a045c1 + 7b6a69124 + 57015b2db ledgers; 0 losses; bands 5 improved / 0 worsened) + 16 NEW upstream `visual/video/vp6_inter_frames` comparisons all passing → **522 / 609**. LEDGER EXACT. no-graphics `44930677490`: INCOMPLETE (shard 12/30 lost to an apt mirror flake: `build-essential has no installation candidate` ×3 → ccache exit 127; 67 rows ungraded); on the 4484-row intersection +1 pass / 0 losses — the other focus row is presumably in the lost shard. Infra, not code |
- padded-filter N1: `visual/filters/empty_child_filter_bounds` is NOT filters — AVM1 nested dynamic-clip transform/alpha inheritance (parent _x/_xscale/_alpha set after children drawn never reaches grandchildren). Wave-1 diagnosis candidate.
- drift-avm2 queued slots: S3 `w2-bitmapdata-jpeg` (JPEG encoder; bitmapdata_encode + jpeg_visual px), S4 `w2-context3d-readback` (drawToBitmapData; context3d_draw_to_bitmap_data trace+px, draw_to_bitmap_data_unconfigured, stage3d_missing_vertex_stream), S5 `w2-array-vector-args` (join snapshot, sort arg errors, array_constructor frames), S6 `w2-bound-method-cache` (primitive/weird_number_bound_methods), S7 `w2-stack-trace-names` (error_stack_trace_class_names, _limit), S8 `w2-doc-removal-events` (displayobjectcontainer_remove_*), S9 `w2-avm2-small-errors` (shared_object_get_local_error, loaderinfo_root_progress(_goto), amf_xmllist, hit_test_scroll_rect); plus `w2-tf-css-avm2` (AVM2 twins: avm2/textfield_{get,set}_text_format_args, avm2/edittext_set_text_same(_after_edits)); e4x residual leads (bug_564468 caseless CDATA → pass; misc_errors #1095).
- drift-avm2 H3 policy question (coordinator/user): image `known_failure` + `output.ruffle.png` rows (`graphics_draw_path`, `cache_as_bitmap/avm1_color` byte-identical to Ruffle's sidecar). Recommendation adopted: report as a separate ruffle_matched image bucket, NOT as passes (Flash-over-Ruffle).
- **Correction (drift-avm2 §2):** the "4752 graded / 4625 effective" totals in the 17:30 baseline note double-counted the 47 nested `from_shumway/avm1` rows plus an artifact; corpus_status_diff convention gives **4642 rows / 4515 effective** (79 new upstream rows, 0 removed).
- drift-avm1 queued: `w2-video-props` (NetStream-SquareTest drift re-flip → rm; video_width_height, video_prototype_lazy(_swf6_child) stretch), `w2-xml-status` (xml_status_mismatched_tags; keep gnash XML-v*/XMLNode-v* rm), AVM1 bundle (file_reference_listeners_per_instance, localconnection_reference_identity, shared_object_members_swf5, edittext_asfunction_case_insensitive, M1d inherited holes, amf0_array_matrix instanceof). New cross-cutting lead: native builtin methods expose a `prototype` (global_*_decls) — price as its own wave-1 slot.
| 44935781892 / 44935788709 | graphics/full/images + no-graphics/full | c489b84d9 (+ 8 patches: 9ba5e552c, 228a5ff0c, 3cdde8be0, 353732f52, ca9c46595, cfbcb6658, 0798e815a, cfc56d74b; cumulative) | graphics `44935781892`: trace **4517 → 4548/4643 intersection (+31 = every ledger row by name, 0 regressions, 0 other moves)**; NEW graded rows all pass: `avm2/allow_networking`, `avm1/allow_networking_import_assets(2)` (H1 discovery) → 4551/4645 overall. Pixels **522 → 528/609 (+6 = padded-filter ×2, stage3d-text ×2, drift-avm2 ×2; 0 regressions; 3 bands improved)**. LEDGER EXACT. no-graphics `44935788709`: pending |
