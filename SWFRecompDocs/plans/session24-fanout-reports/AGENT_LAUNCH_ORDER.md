# Session 24 — worker launch-order / id map

Mode: CLOUD-FIRST (user directive 2026-10-16, re-confirmed 2026-11-21): every slot is a cloud session in env
"SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator
local (merge, CI dispatch, results accounting, exporter oracle).
Baseline: run `44965247383` (graphics/full/images) at `ff2e2e9d6`, results `67fb47bc2`; upstream corpus `bcac30c19`.
Trace 4588 eff on the 4653-row intersection, 66 failing graphics rows; pixels 534/613.
Wave 1 sized at 6 (not 8): s23 took the cheap wins; fund wave-2 slots only on measured ledgers.
Parallel LOCAL one-task session: `n-perf-ab` (Windows real-GPU frame-rate A/B of N after the `161ecf124` attach pump).

## Wave 1 (diagnosis, cloud)

| # | slug | axis | task | session id |
|---|---|---|---|---|
| 1 | w1-native-proto | trace | AVM1 native builtin prototypes + lazy prototypes (9 rows, cross-cutting) | |
| 2 | w1-avm1-tail | trace | AVM1 + gnash/shumway tail triage (~27 rows) + filters-getter L1 | |
| 3 | w1-avm2-tail | trace | AVM2 tail triage (~20 rows) | |
| 4 | w1-attach-order | trace | attach-tick tag order, action_order family, MovieClip-v8 buckets | |
| 5 | w1-pixel-text | pixel | acid-color-0, per-line ascent/descent, static_text_offstage, text-bind, definefont4 | |
| 6 | w1-pixel-bitmap | pixel | JPEG encoder, ShaderFilter, draw_cab_quality, quality=low hairline, runtime-filter leftovers | |

## Wave 2 (implementation, cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|

## Grading runs

| run | mode / categories / images | code | result |
|---|---|---|---|
