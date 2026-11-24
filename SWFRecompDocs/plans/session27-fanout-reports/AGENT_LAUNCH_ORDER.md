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
| 1 | w1-drift | | `briefs/w1-drift.md` | |
| 2 | w1-applyfilter-tail | | `briefs/w1-applyfilter-tail.md` | |
| 3 | w1-text-wordwrap | | `briefs/w1-text-wordwrap.md` | |
| 4 | w1-text-glyph-fidelity | | `briefs/w1-text-glyph-fidelity.md` | |
| 5 | w1-render-bitmap-leads | | `briefs/w1-render-bitmap-leads.md` | |
| 6 | w1-per-movie-dl-phase3 | | `briefs/w1-per-movie-dl-phase3.md` | |
| 7 | w1-browser-avm1-gaps | | `briefs/w1-browser-avm1-gaps.md` | |
| 8 | w1-avm1-leftovers | | `briefs/w1-avm1-leftovers.md` | |
| 9 | w1-timers-robustness | | `briefs/w1-timers-robustness.md` | |
| 10 | w1-exec-order | | `briefs/w1-exec-order.md` | |
