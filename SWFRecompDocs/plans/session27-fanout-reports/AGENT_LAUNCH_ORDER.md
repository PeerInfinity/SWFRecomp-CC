# Session 27 — worker launch-order / id map

Mode: CLOUD-FIRST (standing user directive): every slot is a cloud session in env "SWFRecomp fan-out"
(`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator `s27-coordinator` local
(merge, CI dispatch, results accounting, exporter oracle `0ddd12b6a`). Size: full.
Baseline: s26 record pair at code `005bea42a` — graphics/full/images `45284922078` (results `df7729df2`) + no-graphics/full
`45284938521` (results `81d32b9b2`). Read at `df7729df2`: trace 4684 eff / 4722 rows (38 failing); pixels 593 / 637.
Wave 0: local N `n-trap-stroke` landed `d70f2c0aa` (recompiler stroke line-style-id order + 2 fixtures) and dispatched
graphics/full/images `45300086369` before the handshake; graded as wave 0.
Upstream `3e98d9ba6..1e604fa87` (14 commits) → w1-drift.

## Wave 1 (diagnosis, cloud)

| # | slug | axis | task | session id |
|---|---|---|---|---|
| 1 | w1-drift | | `briefs/w1-drift.md` | session_018CoDi5N4PDwSYRb1BtcpsX |
| 2 | w1-applyfilter-tail | | `briefs/w1-applyfilter-tail.md` | session_018CoDi6BdM94P49fXHBfsXH |
| 3 | w1-text-wordwrap | | `briefs/w1-text-wordwrap.md` | session_018CoDi7dhY9K6fob9XQQ7hN |
| 4 | w1-text-glyph-fidelity | | `briefs/w1-text-glyph-fidelity.md` | session_018CoDi52c6j8TsgB2hBfqvM |
| 5 | w1-render-bitmap-leads | | `briefs/w1-render-bitmap-leads.md` | session_018CoDi4Ezx7K9RU17RnJauX |
| 6 | w1-per-movie-dl-phase3 | | `briefs/w1-per-movie-dl-phase3.md` | session_018CoDi5Y59Hqp3qwXLspLmJ |
| 7 | w1-browser-avm1-gaps | | `briefs/w1-browser-avm1-gaps.md` | session_018CoDi3xhg3Ln18HCEQsD5g |
| 8 | w1-avm1-leftovers | | `briefs/w1-avm1-leftovers.md` | session_018CoDi6RWXyLdLEJhQj9e9Q |
| 9 | w1-timers-robustness | | `briefs/w1-timers-robustness.md` | session_018CoDi67YHojVBN6gBU6L2N |
| 10 | w1-exec-order | | `briefs/w1-exec-order.md` | session_018CoDi3kpoY381JK8xx3ueY |

## N ladder (local one-task sessions)

- `n-trap-stroke` DONE (report `5eeda6444`, code `d70f2c0aa`; REPORT BACK verified on disk): trap switch = Ruffle
  tessellation-cache artifact (Flash rule kept); exit-door = strokes in line-style-id order (fixed); fixtures pass in CI.
- `n-ragdoll-strokes` launched 2026-11-24 ~01:45 UTC (run.S7bGuoXf, cwd verified, handshake sent): ragdoll Drawing-API
  thin strokes under scale, then the native residual (fps counter, edge px). CI folded into the coordinator's runs.
- `flash-oracle` (launched by s26-coordinator at Robert's request): real Flash Player 32 oracle; captures come to s27.

## Grading runs

| run | mode / categories / images | code | result |
|---|---|---|---|
| 45300086369 | graphics / full / images (wave 0, dispatched by n-trap-stroke) | d70f2c0aa | **exact**: trace 4684 eff on the 4722 intersection, 0 moves; +2 new fixture rows pass (4686 / 4724); pixels 0 moves, 0 band moves (595 / 639 summed incl. the 2 fixtures). Results `da51f878f` |
