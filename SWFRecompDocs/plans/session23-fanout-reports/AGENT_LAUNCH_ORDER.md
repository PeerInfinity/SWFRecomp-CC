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
| 1 | w2-crossvm-legf | trace | cross-VM leg F (focus_events_mixed_avm_edittext, selection_onsetfocus_mixed_avm), direct wave 2 | session_018CoDi4rG1CSwsyx1QLEnLz (16:08 UTC) |
| 2 | w1-trace-tail | trace | html dup-attr CSS, movieclip_destruction_test3/4, audio aac/g711, new s22 upstream rows, NO-GO reconfirm | session_018CoDi4r4bKbsW24Nr5EZWc |
| 3 | w1-filter-label | pixel | glow/drop_shadow/bevel_* label glyph pixels (7 rows) | session_018CoDi3uVweQJapey3LuzYo — DELIVERED 16:45; mech A = 7e2a045c1 (confirmed independently), mech B → w2-glyph-levien |
| 4 | w1-padded-filter | pixel | drop_shadow_angles, displacement_map, bevel edge row | session_018CoDi4bjPQagEMxkuV7Yx4 |
| 5 | w1-glyph-precision | pixel | morph_test1/Video-EmbedSquareTest glyph pixels, edittext_scroll, bitmapdata_draw, shape_test attribution | session_018CoDi4gT9iTUdsyJmtmsV5 — DELIVERED 16:32; prototype LANDED directly `7e2a045c1` |
| 6 | w1-pixel-misc | pixel | Spark decode, ShaderFilter/blendShader, stage3d_texture, acid-color-0, definefont4, ignore=true/subtest harness | session_018CoDi4JVo1n3vja6iLtpWF |

## Landed patches + expected ledgers

| commit | from | expected (CI check) |
|---|---|---|
| `7e2a045c1` | w1-glyph-precision prototype (landed directly, no w2 slot) | px fail→pass: `misc-ming.all/morph_test1` frame2..6, `cache_as_bitmap/edittext_scroll .02`, `simple_shapes/text_field_mask`, `shumway acid-text-escape` (+8); md5 moves on passing `edittext_scroll .01`, `text-bind`, `cache_as_bitmap/text`; trace: none. Drift: `Video-EmbedSquareTest` re-goldened upstream (`74323048b`, Flash HQ + KF), not yield |

## Leads held for wave 2 (from delivered reports)
- glyph-precision lead 1: per-line max ascent/descent for the AVM1 render pitch (`br_at_start`, `style_changes_in_html`).
- glyph-precision lead 2: quality=low hairline tie-break (Flash takes the +0.5 px side); `shape_test` 17911 attributed to `e62daeb6f`. A/B on `acid-small .01/.05` first.
