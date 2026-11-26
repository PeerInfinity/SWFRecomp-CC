# Session 29 — worker launch-order / id map

Mode: CLOUD-FIRST (standing user directive): every slot is a cloud session in env "SWFRecomp fan-out"
(`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator `s29-coordinator` local
(merge, CI dispatch, results accounting, Flash oracle, exporter `0ddd12b6a`). Size: wave 1 = 9 slots (thin trace board).
Baseline (read fresh 2026-11-26): s28 FINAL graphics run `45878805896` at `bfa47037b`, results `014124ed5`: trace 4827 eff /
4864 (4642 pass + 185 rm, 37 failing); pixels by status sum 548 pass / 140 fail / 6 ignored / 3 skip (697 rows; the s28
headline "545 / 140 / 694" counted differently, same failing set). No-graphics `336b83183`: 4825 eff.
Upstream: `c2f7d24b7..31e07df77` → w1-drift. Launched from master `ee14c39f9` + this scaffold.

## Local one-task sessions

- N ladder: `n-seam-caps` launched 2026-11-26 (brief `n-seam-caps-prompt.md`; handshake sent): closed stroke seam as two caps in builders/lyon.
- Browser ladder: `browser-gotoandstop-current` launched 2026-11-26 (brief `browser-gotoandstop-current-prompt.md`; handshake sent): FP32 gotoAndStop(current) fixtures, then one all-build rule.
- Coordinator-local: Windows FP32 check of the 5 LOW swap candidates (`w1-local-oracles/swapcheck-win/`): invalidClipDepth + acid-filter WIN == LNX → flash_fixes `4989a9dfb` (64 entries); gradient, acid-gradient, acid-gradient-0 WIN ≠ LNX → kept (host-dependent, RvF).

## Wave 1 (diagnosis, cloud)

| # | slug | task | session id |
|---|---|---|---|
| 1 | w1-drift | `briefs/w1-drift.md` | session_018CoDi4ZFZ828kpeR8p1qoM — DELIVERED: only the 2 paletteMap rows are new (rest of range already in FINAL); AVM2 paletteMap was a no-op → prototype (+1 new row pass); 62 fixes ALREADY, 0 STALE/UPSTREAMED; FP32: both goldens Flash, AVM2 reads arr[i] (Ruffle arr[i-1], RvF) → w2-palettemap-land |
| 2 | w1-disposition-audit | `briefs/w1-disposition-audit.md` | session_018CoDi6ePRNuHb1YPKktDNL — launched |
| 3 | w1-timers-goto | `briefs/w1-timers-goto.md` | session_018CoDi7txoNJ1nDAZsFDGxN — launched |
| 4 | w1-rm-avm1-gnash | `briefs/w1-rm-avm1-gnash.md` | session_018CoDi4vq5d18kxhw4u2ixo — launched |
| 5 | w1-rm-avm2 | `briefs/w1-rm-avm2.md` | session_018CoDi3Zc75tdYLniTM5WCT — launched |
| 6 | w1-lowq-next | `briefs/w1-lowq-next.md` | session_018CoDi7qTxMBdBnSPwzNNpq — launched |
| 7 | w1-aa-sizing | `briefs/w1-aa-sizing.md` | session_018CoDi7ory8zEi6jZLvD2Ba — launched |
| 8 | w1-text-pixels | `briefs/w1-text-pixels.md` | session_018CoDi6VSAprpDm9DcBKpgn — DELIVERED: **Flash HIGH = 4 sub-scanlines at y+j/4 × exact x coverage, 1/16 quantised** (refutes 4×4 SSAA); CPU-coverage prototype for skewed text (rotated_glyphs 1034→198 px vs FP32; 0 status moves); wordwrap golden already FP32 (refuted); 22 'unpriced' losses all priced (morph_test1 ×6 = only real Flash losses, LOW glyph rule). Coordinator FP32 W1 colour + W2 shapes: shape/stroke edges also on the 255−16n ladder → w2-text-coverage-land |
| 9 | w1-pixel-flash-gaps | `briefs/w1-pixel-flash-gaps.md` | session_018CoDi3zqAaCrHtF3TEjcQB — launched |

## Wave 2 (implementation, cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|
| w2-palettemap-land | w1-drift + FP32 | `avm2/bitmapdata_palettemap_opaque` new→pass; new `regression/avm2_bitmapdata_palettemap_index` | session_018CoDi4Bkz9NG5UkK7xk674 — launched |
| w2-text-coverage-land | w1-text-pixels + FP32 W1/W2 | rotated_glyphs/borders + edittext_border_transform .04/.06 bands toward goldens; new fixtures; 0 status moves | session_018CoDi3xgg2pUfZeojNd8Fe — launched |

## Grading runs

| run | code | trace | pixels | no-graphics |
|---|---|---|---|---|
| `45907020469` interim #1 | `4989a9dfb` 2 flash_fixes + fresh upstream download | expected: drift rows only (2 paletteMap rows new) | expected: invalidClipDepth fail→pass; acid-filter stays fail | — |
