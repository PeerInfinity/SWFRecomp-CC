# Session 28 — worker launch-order / id map

Mode: CLOUD-FIRST (standing user directive): every slot is a cloud session in env "SWFRecomp fan-out"
(`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator `s28-coordinator` local
(merge, CI dispatch, results accounting, Flash oracle, exporter `0ddd12b6a`). Size: full.
Baseline (read fresh 2026-11-25): graphics run `45547012629` at `7c3cfdcb7`, results `e1425f417`: trace 4781 eff / 4819
(4522 pass + 259 rm, 38 failing); pixels 630 pass / 39 fail / 678 comparisons (status sum; s27's "626 / 39" headline
counted differently — 0 status moves `cb14cd063` → `e1425f417`). No-graphics `2e286cf2f`: 4779 eff (40 failing).
Upstream: `efb612fd7..c2f7d24b7` → w1-drift.

## Local one-task sessions

- `trace-provenance` launched 2026-11-25 at startup (pid 1610143, cwd verified, handshake sent).

## Wave 1 (diagnosis, cloud)

| # | slug | task | session id |
|---|---|---|---|
| 1 | w1-acid-flash | `briefs/w1-acid-flash.md` | |
| 2 | w1-avm2-vector-flash | `briefs/w1-avm2-vector-flash.md` | |
| 3 | w1-drift | `briefs/w1-drift.md` | |
| 4 | w1-filter-residuals | `briefs/w1-filter-residuals.md` | |
| 5 | w1-leads | `briefs/w1-leads.md` | |
| 6 | w1-loaded-shell-residuals | `briefs/w1-loaded-shell-residuals.md` | |
| 7 | w1-render-flash-headroom | `briefs/w1-render-flash-headroom.md` | |
| 8 | w1-test12-enterframe | `briefs/w1-test12-enterframe.md` | |
| 9 | w1-text-edit-tail | `briefs/w1-text-edit-tail.md` | |
| 10 | w1-text-glyph-aa | `briefs/w1-text-glyph-aa.md` | |
