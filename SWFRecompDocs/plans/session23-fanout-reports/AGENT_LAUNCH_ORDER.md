# Session 23 — worker launch-order / id map

Mode: CLOUD-FIRST (user directive 2026-10-16, re-confirmed 2026-11-21): every slot is a cloud session in env
"SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator
local (merge, CI dispatch, results accounting, exporter oracle).
Session-start infra fix: `08709f658` pins CI runners to `ubuntu-24.04` (`ubuntu-latest` = 26.04 has no
swfmill; the weekly canary's WASM link-smoke had failed 4 weeks running; also keeps CI lavapipe == cloud env).
Baseline runs at `08709f658` (upstream `0ddd12b6a`): graphics/full/images `44922638965`, no-graphics/full
`44922646202`.

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

| 8 | w2-tf-css | trace | trace-tail slot A: AVM1 htmlText CSS + getTextFormat url/para; + 5 new upstream getTextFormat rows | session_018CoDi3RqHac9QhfSJkkY34 (16:58) |
| 9 | w2-attached-timeline | trace | trace-tail slot B: attached clips run natural timeline in CI modes; movieclip_destruction_test3/4 | session_018CoDi5yeX7FkuGneLRRe8H (16:58) |
| 10 | w2-padded-filter | pixel | productionize w1-padded-filter (gated padded filter layer); drop_shadow_angles, displacement_map | session_018CoDi6x1pyS9L9PSYoDJZL (17:03) |
| 11 | w2-stage3d-text | pixel | Stage3D RTT + budget 48M, AVM2 default-font advance rounding; stage3d_texture, stage3d_bitmap | session_018CoDi7QtMALGjWbWyYvecw (17:10) |
| 12 | w2-netstream-audio | trace | trace-tail D: NetStream audio tap + computeSpectrum; audio/aac, audio/g711 | session_018CoDi3x3Uds6hHMQAvVQFk (17:10) |
## Landed patches + expected ledgers

| commit | from | expected (CI check) |
|---|---|---|
| `7e2a045c1` | w1-glyph-precision prototype (landed directly, no w2 slot) | px fail→pass: `misc-ming.all/morph_test1` frame2..6, `cache_as_bitmap/edittext_scroll .02`, `simple_shapes/text_field_mask`, `shumway acid-text-escape` (+8); md5 moves on passing `edittext_scroll .01`, `text-bind`, `cache_as_bitmap/text`; trace: none. Drift: `Video-EmbedSquareTest` re-goldened upstream (`74323048b`, Flash HQ + KF), not yield |
| `d35a55154` | w2-crossvm-legf | trace fail→pass (both modes): `avm2/focus_events_mixed_avm_edittext`, `avm2/selection_onsetfocus_mixed_avm`; pixels none |
| `7b6a69124` | w1-pixel-misc §1 (FAAN IDCT, landed directly) | px fail→pass: `avm2/netstream_play_flv`, `avm1/netstream_play_flv`, `visual/video/deblocking`; `colorconversion/h263` 10808→3 (still fail); trace none |
| `57015b2db` | w2-glyph-levien | px fail→pass: `visual/filters/glow`, `glow_without_composite_source`, `drop_shadow`, `bevel_inner`, `bevel_outer`, `bevel_full`, `glow_with_alpha_strength` (last 4 at 18/18 zero headroom); md5 moves on passing text-bind, cache_as_bitmap/text, edittext_scroll .01; trace none |

## Leads held for wave 2 (from delivered reports)
- glyph-precision lead 1: per-line max ascent/descent for the AVM1 render pitch (`br_at_start`, `style_changes_in_html`).
- glyph-precision lead 2: quality=low hairline tie-break (Flash takes the +0.5 px side); `shape_test` 17911 attributed to `e62daeb6f`. A/B on `acid-small .01/.05` first.
- trace-tail slots queued (launch as cloud slots free): C `w2-qname-dict` (avm2_ops.c; dictionary_qname_keys +1; full CI for #1069/#1081), D `w2-netstream-audio` (audio/aac, g711 +2), E `w2-definefont4` (textline_metrics +1, recompiler DefineFont4), F `w2-avm1-devicefont` (device_font_name_case +1).
- trace-tail oracle request 1 (optional): attached 4-frame clip frame-order trace — do at w2-attached-timeline merge.
- padded-filter oracle request (bevel row 305 at quality=low): DEFERRED — the local exporter has no quality option (renders at default/high quality on a real GPU, so it cannot answer a 1-sample point-sampling tie); needs Ruffle's own test runner (`cargo test` of the tests crate on lavapipe) or an exporter `--quality` patch. 0 flips at stake (disposition only). s24 board / optional.
- pixel-misc queued: `w2-harness-subtests` (§4 GRADING-INSTRUMENT: ignore=true + [subtests] images + drawWithQuality alias; land AFTER an interim images run so attribution stays clean), `w2-text-cxform` (§3b acid-color-0 band, AVM1/timeline text gets ancestor colour transforms; correctness, 0 flips), `w2-shaderfilter` (§2a glassDisplace_shaderfilter +1 medium; rider pixelbender_dithering).
