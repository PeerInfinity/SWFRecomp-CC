# Session 30 — worker launch-order / id map

Mode: CLOUD-FIRST (standing user directive): every slot is a cloud session in env "SWFRecomp fan-out"
(`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator `s30-coordinator` local
(merge, CI dispatch, results accounting, Flash oracle). Launched by `s29-coordinator` (handshake 2026-11-27).
Baseline (read fresh 2026-11-27): s29 FINAL graphics `45938113471` at `2d40d3799`, results `51ab63688`: trace 4860 eff /
4893 (4704 pass + 156 rm, 33 failing); pixels by status sum 554 pass / 140 fail / 6 ignored / 3 skip (703 rows; the s29
headline "552 / 701" counted differently, same failing set). No-graphics `63bcc2dd8`: 4858 eff. Lists:
`s30-baseline-trace-failing.txt`, `s30-baseline-trace-rm.txt`, `s30-baseline-pixel-failing.txt`.
Upstream: `b7ff32d93..66f9073de` (11 commits; 1 new row `avm2/xmldocument_tostring`) → w1-drift-smalls.

## Coordinator pre-wave-1 (s30 launch)

- FP32 native-object table captures (LNX + WIN, 7 rows): `pre-launch-oracles/native-table/` (README §6). Goldens ==
  FP32 LNX apart from `capabilities.manufacturer` position + a TZ string; argstest-v8 untestable on LNX.
- FP32 TextField tabIndex fixture (v6/v8): `pre-launch-oracles/tf_tabindex_null/` (README §7): null already OK; negative
  unsets, delete no-op, enumerable = our gaps.
- FP32 LNX `avm2/html_text_img_parsing`: LNX also prints the 95 #2044 lines, 1 platform line.
- **layer_group correction**: the pre-launch draw() captures were invalid (non-LAYER blends). FP32 `--screen` LOW:
  golden 13 763 / 11 979, ours 4 268 / 2 143 → both fixtures re-goldened to the screen captures.
- `acid-large` flash_fix (94 entries); draw == screen confirmed.
- FP32 LOW `avm2/sprite_with_frames` (WIN == LNX): ours 44 694 / golden 41 822 channels from Flash.

## Local one-task sessions

- Browser ladder #1: `browser-attach-child-early` launched 2026-11-27 (brief `browser-attach-child-early-prompt.md`; pid 1609015, cwd verified; handshake sent). **DONE `3944257a4`** (REPORT BACK verified on disk + pushed): attach's force-nested-build pass now runs under `g_build_only` (browser fixture = FP32 82/82, Minesweeper radio 0 px); spurious loopback warning = s28 `613c0f100` regression (dropped `g_nested_loopback_quiet` reader), restored browser-only; native 48/48. Touches `tag.c` `tagPlaceObject2*` (browser-flag only). Grade: next interim (expected 0 CI moves).
- Browser ladder #2: `browser-nested-swapdepths-remove` (brief `browser-nested-swapdepths-remove-prompt.md`).
- N ladder: PARKED (no new lever). N procgen: CANCELLED.

## Wave 1 (cloud)

| # | slug | task | session id |
|---|---|---|---|
| 1 | w1-drift-smalls | `briefs/w1-drift-smalls.md` | session_018CoDi3UKNCYNXQnaGSMtpt (launched 2026-11-27) |
| 2 | w1-native-table | `briefs/w1-native-table.md` | session_018CoDi4Sch2FCj267pG7rvV (launched 2026-11-27) |
| 3 | w1-exec-order | `briefs/w1-exec-order.md` (IMPLEMENTATION) | session_018CoDi3wxmmmZzx6LvZSqQy (launched 2026-11-27) |
| 4 | w1-rm-avm1-gnash | `briefs/w1-rm-avm1-gnash.md` | session_018CoDi5SY1nuHbr85qkJ3v6 (launched 2026-11-27) |
| 5 | w1-rm-avm2 | `briefs/w1-rm-avm2.md` | session_018CoDi826BFpNusgFJQzZLD (launched 2026-11-27) |
| 6 | w1-lowq-residues | `briefs/w1-lowq-residues.md` | session_018CoDi5KLv9Hms3cZuawbmS (launched 2026-11-27) |
| 7 | w1-stroke-geometry | `briefs/w1-stroke-geometry.md` | session_018CoDi3XoxSKf3YqHyc4Zjr (launched 2026-11-27) |

## Wave 2 (cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|

## Grading runs

| run | code | trace | pixels | no-graphics |
|---|---|---|---|---|
| `46040854188` interim #1 (G full images) | `f4edebdce`: batch 0 (acid-large swap, layer_group re-golden) + fresh upstream | expected: new row `avm2/xmldocument_tostring` (status unknown); 0 moves | expected: acid-large fail→fail (vs FP32 ~138 478); layer_group ×2 fail→fail (~4 268 / 2 143); 0 status moves | — |
