# Session 24 — worker launch-order / id map

Mode: CLOUD-FIRST (user directive 2026-10-16, re-confirmed 2026-11-21): every slot is a cloud session in env
"SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator
local (merge, CI dispatch, results accounting, exporter oracle).
Baseline: run `44965247383` (graphics/full/images) at `ff2e2e9d6`, results `67fb47bc2`; upstream corpus `bcac30c19`.
Trace 4588 eff on the 4653-row intersection, 66 failing graphics rows; pixels 534/613.
Wave 1 sized at 6 (not 8): s23 took the cheap wins; fund wave-2 slots only on measured ledgers.
Parallel LOCAL one-task session: `n-perf-ab` (Windows real-GPU frame-rate A/B of N after the `161ecf124` attach pump; wsl-launch, Opus, PID 3052956, handshake sent; record goes into `session23-fanout-reports/browser-attached-timeline-report.md`).

## Wave 1 (diagnosis, cloud)

| # | slug | axis | task | session id |
|---|---|---|---|---|
| 1 | w1-native-proto | trace | AVM1 native builtin prototypes + lazy prototypes (9 rows, cross-cutting) || session_018CoDi6uqrzRVevzzxY9Y3o — DELIVERED; prototype LANDED directly (+2 ledger: `lazy_prototype_shared`, `video_prototype_lazy`; 0 riders/47) |
| 2 | w1-avm1-tail | trace | AVM1 + gnash/shumway tail triage (~27 rows) + filters-getter L1 || session_018CoDi4M3bEUKQMx1tkwhVv — DELIVERED; prototype LANDED directly (+5: `amf0_array_matrix`, `localconnection_serialize_sparse_array_getters`, `localconnection_xml_unavailable`, `load_vars`, `stylesheet_load`; last two pruned from ignored_tests.txt) |
| 3 | w1-avm2-tail | trace | AVM2 tail triage (~20 rows) || session_018CoDi67sPWpLegcVfoqSfP — DELIVERED; GO +9 → w2-avm2-netstream-sound + w2-avm2-small-natives (L6 → w2-bitmap-encode-shader) |
| 4 | w1-attach-order | trace | attach-tick tag order, action_order family, MovieClip-v8 buckets || session_018CoDi4TVY3qMVvqEyLqBSt — DELIVERED; GO → w2-attach-order-v8 (oracles run locally: nonroot == root, array probe `1,2`) |
| 5 | w1-pixel-text | pixel | acid-color-0, per-line ascent/descent, static_text_offstage, text-bind, definefont4 || session_018CoDi7fh5vYVwYccb2ey2L — DELIVERED; GO +2 px → w2-text-pitch |
| 6 | w1-pixel-bitmap | pixel | JPEG encoder, ShaderFilter, draw_cab_quality, quality=low hairline, runtime-filter leftovers || session_018CoDi4KP8AqoumFHJqZ626 — DELIVERED; GO +3 px +1 trace → wave 2 `w2-bitmap-encode-shader` |

## Wave 2 (implementation, cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|
| (landed direct) w1-native-proto prototype | w1-native-proto | avm1 `lazy_prototype_shared`, `video_prototype_lazy` (trace +2; `text_format_prototype_lazy` improves, no flip) | — |
| (landed direct) w1-avm1-tail prototype | w1-avm1-tail ranks 1-2 | avm1 `amf0_array_matrix`, `localconnection_serialize_sparse_array_getters`, `localconnection_xml_unavailable`, `load_vars`, `stylesheet_load` (trace +5; load_vars/stylesheet_load are ignored rows → count in unfiltered totals) | — |
| w2-bitmap-encode-shader | w1-pixel-bitmap 1-3 | px `bitmapdata_encode_jpeg_visual`, `pixelbender_effect_glassDisplace_shaderfilter`, `bitmapdata_draw_cab_quality`; trace `avm2/bitmapdata_encode` | session_018CoDi5gsDkGPC5YqN4cGsi |
| w2-textformat-ctor | w1-avm1-tail §3 + w1-native-proto §2.3(2)(3) | trace `avm1/text_format_get_text_extent_own` (+1; `text_format_prototype_lazy` improves, no flip) | session_018CoDi4u7e3tT9S75zqgX2n |
| w2-attach-order-v8 | w1-attach-order 1+3 | trace `MovieClip-v8` mismatch→ruffle_matched (KF gain); new `regression/avm1_attached_clip_tagorder{,_nonroot}`, `avm1_array_native_own_method`; touches tag_stubs.c → no-graphics leg | session_018CoDi3RnZbXUjuQMVpuobM |
| w2-text-pitch | w1-pixel-text 2 (+3ab riders) | px `text/br_at_start`, `text/style_changes_in_html`; `text-bind` max-1 move, outliers unchanged | session_018CoDi4vp6dB1DBvTMiPGjp |
| w2-avm2-netstream-sound | w1-avm2-tail L1+L2 | trace `netstream_play_flv`, `netstream_play_stop_replay`, `netstream_seek_flv`, `soundchannel_position_after_end`, `audio_computespectrum` (NG: all but computespectrum); `netstream_seek_flv` image md5 change, stays pass | session_018CoDi6zgpVTGFaRYn7t9vi |
| w2-avm2-small-natives | w1-avm2-tail L3+L4+L5 | trace `weird_number_bound_methods`, `textline_metrics`, `worker_terminate` pass; `primitive_bound_methods` rm | session_018CoDi6BbMw6PTYEbMiEn8G |

## Grading runs

| run | mode / categories / images | code | result |
|---|---|---|---|
| 44972916356 | graphics / full / no | 336749f14 (native-proto) | trace 4589 → 4591 (+2) on 4655, ledger exact (`lazy_prototype_shared`, `video_prototype_lazy`); 0 regressions |
| 44976721092 | graphics / full / no | 292d0121f (avm1-tail +5, textformat-ctor +1, 2 new fixtures) | trace 4591 → 4597 (+6) on 4655, ledger exact by name (amf0_array_matrix, load_vars, localconnection_serialize_sparse_array_getters, localconnection_xml_unavailable, stylesheet_load, text_format_get_text_extent_own); new regression/avm1_xml(node)_first_action_proto pass; 0 regressions |
