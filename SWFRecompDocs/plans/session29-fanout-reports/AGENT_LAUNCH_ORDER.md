# Session 29 — worker launch-order / id map

Mode: CLOUD-FIRST (standing user directive): every slot is a cloud session in env "SWFRecomp fan-out"
(`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator `s29-coordinator` local
(merge, CI dispatch, results accounting, Flash oracle, exporter `0ddd12b6a`). Size: wave 1 = 9 slots (thin trace board).
Baseline (read fresh 2026-11-26): s28 FINAL graphics run `45878805896` at `bfa47037b`, results `014124ed5`: trace 4827 eff /
4864 (4642 pass + 185 rm, 37 failing); pixels by status sum 548 pass / 140 fail / 6 ignored / 3 skip (697 rows; the s28
headline "545 / 140 / 694" counted differently, same failing set). No-graphics `336b83183`: 4825 eff.
Upstream: `c2f7d24b7..31e07df77` → w1-drift. Launched from master `ee14c39f9` + this scaffold.

## Local one-task sessions

(ladders: N, browser — filled in as launched)

## Wave 1 (diagnosis, cloud)

| # | slug | task | session id |
|---|---|---|---|
| 1 | w1-drift | `briefs/w1-drift.md` | session_018CoDi4ZFZ828kpeR8p1qoM — launched |
| 2 | w1-disposition-audit | `briefs/w1-disposition-audit.md` | session_018CoDi6ePRNuHb1YPKktDNL — launched |
| 3 | w1-timers-goto | `briefs/w1-timers-goto.md` | session_018CoDi7txoNJ1nDAZsFDGxN — launched |
| 4 | w1-rm-avm1-gnash | `briefs/w1-rm-avm1-gnash.md` | session_018CoDi4vq5d18kxhw4u2ixo — launched |
| 5 | w1-rm-avm2 | `briefs/w1-rm-avm2.md` | session_018CoDi3Zc75tdYLniTM5WCT — launched |
| 6 | w1-lowq-next | `briefs/w1-lowq-next.md` | session_018CoDi7qTxMBdBnSPwzNNpq — launched |
| 7 | w1-aa-sizing | `briefs/w1-aa-sizing.md` | session_018CoDi7ory8zEi6jZLvD2Ba — launched |
| 8 | w1-text-pixels | `briefs/w1-text-pixels.md` | session_018CoDi6VSAprpDm9DcBKpgn — launched |
| 9 | w1-pixel-flash-gaps | `briefs/w1-pixel-flash-gaps.md` | session_018CoDi3zqAaCrHtF3TEjcQB — launched |

## Wave 2 (implementation, cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|

## Grading runs

| run | code | trace | pixels | no-graphics |
|---|---|---|---|---|
