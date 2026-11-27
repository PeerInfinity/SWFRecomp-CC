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
| 1 | w1-drift-smalls | `briefs/w1-drift-smalls.md` | session_018CoDi3UKNCYNXQnaGSMtpt — DELIVERED: xmldocument_tostring 12→23/32 (rest = XMLNode fields as traits, M); flash_fixes 94 ALREADY, 0 STALE/UPSTREAMED; TextField tabIndex = u32 −1 sentinel + delete no-op (+2 fixtures pass; 'negative unsets' + 'null already OK' refuted); html_text_img_parsing CAN pass (we print the Windows side) but needs FP32 load count (98 vs 95); hittest_shapeflag 71 (layer boundary in path_data) + 296 (min stroke width ignores scale; 'integer-twip morph' refuted) fixed. Coordinator FP32: clips/buttons same tabIndex rule; per-case img load counts → w2-drift-smalls-land |
| 2 | w1-native-table | `briefs/w1-native-table.md` | session_018CoDi4Sch2FCj267pG7rvV — DELIVERED: generated table prototype GO, 0 flips, all 6 rows Flash-ward (proto_decls 2593→878, _delete 2215→781); 76-row guard 0 moves; residue = ARRAY for..in proto walk (524 lines), instance layout, lazy/second-identity natives; real bug f.constructor===f fixed; 'golden flags are clean' refuted (DONT_ENUM unobservable for Object.prototype names). Coordinator FP32: SWF6/7/8 dumps; manufacturer 3/3 fresh runs agree (golden differs; not run-to-run) → w2-native-table-land, w2-array-forin-proto, w2-native-instance |
| 3 | w1-exec-order | `briefs/w1-exec-order.md` (IMPLEMENTATION) | session_018CoDi3wxmmmZzx6LvZSqQy (launched 2026-11-27) |
| 4 | w1-rm-avm1-gnash | `briefs/w1-rm-avm1-gnash.md` | session_018CoDi5SY1nuHbr85qkJ3v6 (launched 2026-11-27) |
| 5 | w1-rm-avm2 | `briefs/w1-rm-avm2.md` | session_018CoDi826BFpNusgFJQzZLD — DELIVERED: +9 rm→pass measured (R1/R2 SWF≤9 goto rules, L1′ loader boot, M1 mask RemoveObject, BA, RE, PI, FTE-1/2), −3 priced (all L1′); 'frame/event lifecycle is M–L' refuted for 3 rows; 2 FP32 goldens run past num_ticks. Coordinator FP32: L1′ timing ungradeable (HOLD); array_sort = host bitness (LNX=_64bit, WIN=_32bit); clipDepth toml fix valid; script removeChild keeps .mask; off-list pixelBounds ×5 → w2-rm-avm2-land |
| 6 | w1-lowq-residues | `briefs/w1-lowq-residues.md` | session_018CoDi5KLv9Hms3cZuawbmS — DELIVERED: A (TSNAP tie on LOCAL offset) 6 rows Flash-ward; C (y tie excl top/incl bottom) `gradients` fail→PASS, morph_test1 1401→804, cost +397 on 14 FP32 blend rows; glyph pen half-up REFUTED as universal; LOW glyph CHORD rule lead (recompiler); sprite_with_frames 44k = loop phase (my capture caught the other frame; golden IS Flash; FlashType NO-GO); layer_group alpha (a) = Flash erases painted-alpha-0 (RvF). Coordinator FP32 glyph probe: +2 px offset, current GPU closest → w2-lowq-land |
| 7 | w1-stroke-geometry | `briefs/w1-stroke-geometry.md` | session_018CoDi3XoxSKf3YqHyc4Zjr — DELIVERED: **acid-shapes fail→PASS** from AVM2 drawing-API curve flattening at 0.01 px (HIGH only; owner `gfx_flatten_cmds`, not the stroker/lyon/swf.cpp); AA NOT needed (AA NO-GO stands, −6/−4 for 0 flips); acid-stroke-0 HOLD (LOW diagonal raster 59%); AVM2 seam twin 0 px; union weld REFUTED (slivers are downstream of an exact union). Coordinator FP32: curve scale probes + translucent round strokes (WIN==LNX) → w2-stroke-geometry-land |

## Wave 2 (cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|
| w2-drift-smalls-land | w1-drift-smalls + FP32 req 1/2 | +4 regression rows; xmldocument_tostring mm (23/32+); html_text_img_parsing rm→pass or HOLD; hittest_shapeflag 6→4 lines | session_018CoDi4C9JHcd8ig5dPBV6B |
| w2-native-table-land | w1-native-table W2-a/c/d + per-version FP32 | 0 flips (W2-a), 6 rows Flash-ward; W2-c/d priced | session_018CoDi6z94o4EXoVajXQPSF |
| w2-array-forin-proto | w1-native-table W2-b | proto_decls −~524 lines; array rows priced | session_018CoDi6z9pU14k8efCNVaqu |
| w2-stroke-geometry-land | w1-stroke-geometry + FP32 probes | acid-shapes fail→pass; HIGH curve rows Flash-ward; timeline/AVM1 twins priced | session_018CoDi6oYbShZiTwxVTK8j3 |
| w2-rm-avm2-land | w1-rm-avm2 + FP32 0–5 | +8 rm→pass; L1′ HELD; clipDepth toml; pixelBounds; +2 regression rows | session_018CoDi3ZD3QFF5z4H83uq7b |
| w2-lowq-land | w1-lowq-residues + FP32 glyph probe | A + C: `gradients` fail→pass, 6+ rows Flash-ward, priced blend cost; glyph rule only if Flash-ward | session_018CoDi5vBAjwfeqdDXBD3t3 |
| w2-native-instance | w1-native-table W2-e | ExternalInterface-v8 rm→pass; instance_decls Flash-ward | session_018CoDi3bJoV7MPov8DtZfAQ |

## Grading runs

| run | code | trace | pixels | no-graphics |
|---|---|---|---|---|
| `46040854188` interim #1 (G full images) | `f4edebdce`: batch 0 (acid-large swap, layer_group re-golden) + fresh upstream | **GRADED = ledger** (results `dd22bc5b4`, merged `fcbbfd79e`): 4894 rows, 4704 pass + 156 rm + 34 mm; only move = new `avm2/xmldocument_tostring` mm (as w1-drift-smalls measured) | **= ledger**: 0 status moves (553/140); acid-large 108 639 → 138 478 (FP32 swap), layer_group_alpha 10 987 → 4 268, _erase 10 924 → 2 033 (local said 2 143; same direction) | — |
