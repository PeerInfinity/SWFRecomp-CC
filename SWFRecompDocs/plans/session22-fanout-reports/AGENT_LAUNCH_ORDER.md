# Session 22 — worker launch-order / id map

Mode: CLOUD-FIRST (user, 2026-10-16) — every slot is a cloud session in env "SWFRecomp fan-out"
(`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator local.
Baseline: trace 4476 eff / 4551 (results `846adcc6b`, run on `4c450f076`); pixels 433/587
(images run `36515003936`). Upstream Ruffle synced `0dacba55f → 45366370e`.

## Wave 1 (diagnosis, 8 cloud workers — the concurrency cap)

| # | slug | axis | task | session id |
|---|---|---|---|---|
| 1 | w1-drift-avm1 | trace | AVM1 + gnash upstream drift (matrix/point/rectangle/context_menu rewrites, html img, AsBroadcaster) | |
| 2 | w1-drift-avm2 | trace | AVM2/fonts drift + harness semantics (num_ticks, NaN approx, ignore=true) + ignore re-test | |
| 3 | w1-crossvm | trace | cross-VM focus/pick/load-tick (6 rows) | |
| 4 | w1-trace-tail | trace | non-drift tail (MovieClip-v8, action_order, bug_483783 runtime_error, …) | |
| 5 | w1-stroke-staircase | pixel | 1-px stroke staircase parity, measured prototype | |
| 6 | w1-offstage-filter | pixel | filter-layer bounds/edges, cab_mask_filters | |
| 7 | w1-pixel-smalls | pixel | near-passes + smalls; image-side ignore=true | |
| 8 | w1-pixel-catastrophic | pixel | blank/unrelated/missing/wrong-fill clusters | |
