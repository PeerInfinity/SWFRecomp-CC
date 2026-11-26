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
| 2 | w1-disposition-audit | `briefs/w1-disposition-audit.md` | session_018CoDi6ePRNuHb1YPKktDNL — DELIVERED: +5 priced (native_objects_swf6, globals_swf5 [trade void: gnash v5 goldens Flash], loader_applicationDomain [securityError #2046 path], dependent_strings [swap only], tab edge case); 7 premises refuted; global_decls keep L with new mechanism (native table from FP32 golden). Coordinator FP32: for-in order hash-scattered + NONDETERMINISTIC (bom/loader_load NO-GO); tabIndex rule contradicted by MTASC fixtures (item 7 HOLD) → w2-disposition-land |
| 3 | w1-timers-goto | `briefs/w1-timers-goto.md` | session_018CoDi7txoNJ1nDAZsFDGxN — DELIVERED: gotoFrameFromInterval{,2} = goto target runs children frame-1 scripts in TAG order (+2 measured); clock_model → bound check; NextFrame arm stale. Coordinator FP32 (10 captures): items 1/3/4-root confirmed, item 2 after-EF REFUTED (residue = timer-callback _currentframe), sprite inline nav = neither leg → w2-timers-goto-land |
| 4 | w1-rm-avm1-gnash | `briefs/w1-rm-avm1-gnash.md` | session_018CoDi4vq5d18kxhw4u2ixo — launched |
| 5 | w1-rm-avm2 | `briefs/w1-rm-avm2.md` | session_018CoDi3Zc75tdYLniTM5WCT — DELIVERED: +19 rm→pass measured (D1 per-timestamp DST + `mock_timezone` + 15 toml fixes: all 15 avmplus Date rows incl. 'Windows-only' ones; P debug line info; O1/O2 verifier smalls; L1 scrollV), −1 priced (try_catch_typed, golden ≠ FP32). Coordinator FP32: try_catch_typed suffixes confirmed, 35_1 reproduced under PST8PDT → w2-rm-avm2-land |
| 6 | w1-lowq-next | `briefs/w1-lowq-next.md` | session_018CoDi7qTxMBdBnSPwzNNpq — launched |
| 7 | w1-aa-sizing | `briefs/w1-aa-sizing.md` | session_018CoDi7ory8zEi6jZLvD2Ba — launched |
| 8 | w1-text-pixels | `briefs/w1-text-pixels.md` | session_018CoDi6VSAprpDm9DcBKpgn — DELIVERED: **Flash HIGH = 4 sub-scanlines at y+j/4 × exact x coverage, 1/16 quantised** (refutes 4×4 SSAA); CPU-coverage prototype for skewed text (rotated_glyphs 1034→198 px vs FP32; 0 status moves); wordwrap golden already FP32 (refuted); 22 'unpriced' losses all priced (morph_test1 ×6 = only real Flash losses, LOW glyph rule). Coordinator FP32 W1 colour + W2 shapes: shape/stroke edges also on the 255−16n ladder → w2-text-coverage-land |
| 9 | w1-pixel-flash-gaps | `briefs/w1-pixel-flash-gaps.md` | session_018CoDi3zqAaCrHtF3TEjcQB — DELIVERED: place_object_test 100% LOW glyph text (A: pen→whole px, non-FlashType: 5073→2604); shape_test 89% open-fill parity across objects (NO-GO L); acid-shapes 243→88 (B); avm1_color 1200→230 (C: cab snaps LOW only); shadow/bevel already landed s28; s24 zero-headroom obsolete. Coordinator FP32: text_field_mask + gradientTransform swap-safe, fills_and_lines WIN≠LNX → w2-pixel-gaps-land |

## Wave 2 (implementation, cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|
| w2-palettemap-land | w1-drift + FP32 | `avm2/bitmapdata_palettemap_opaque` new→pass; new `regression/avm2_bitmapdata_palettemap_index` | session_018CoDi4Bkz9NG5UkK7xk674 — DELIVERED, LANDED `ab49742e5` |
| w2-text-coverage-land | w1-text-pixels + FP32 W1/W2 | rotated_glyphs/borders + edittext_border_transform .04/.06 bands toward goldens; new fixtures; 0 status moves | session_018CoDi3xgg2pUfZeojNd8Fe — launched |
| w2-disposition-land | w1-disposition-audit + FP32 | native_objects_swf6, globals_swf5, loader_applicationDomain, dependent_strings mm→pass; swz mm (1/3); +2 regression rows; 3 flash_fixes | session_018CoDi5vBfv1NbGkZQQDNaU — launched |
| w2-pixel-gaps-land | w1-pixel-flash-gaps + FP32 | bands toward Flash (place_object_test, shape_test, morph_test1, acid-shapes 243→88, avm1_color); 2 swaps (text_field_mask, gradientTransform) | session_018CoDi4gzPRPdoE9veAKVJK — launched |
| w2-timers-goto-land | w1-timers-goto + FP32 | gnash gotoFrameFromInterval{,2} rm→pass; ~6 new regression rows | session_018CoDi7QhSDj7YUWLFHhnVN — launched |
| w2-rm-avm2-land | w1-rm-avm2 + FP32 | 19 rm→pass; 3 trace flash_fixes; swz → pass together with w2-disposition-land | session_018CoDi7S9WQn3PdsJBA8GRr — launched |

## Grading runs

| run | code | trace | pixels | no-graphics |
|---|---|---|---|---|
| `45907020469` interim #1 | `4989a9dfb` 2 flash_fixes + fresh upstream download | **= ledger**: 4866 rows (4643 pass + 185 rm, 38 failing); only moves = 2 new rows (`avm1/bitmapdata_palettemap_values` pass, `avm2/bitmapdata_palettemap_opaque` mm, fixed later in `ab49742e5`). flash-fixes: APPLIED 64, 0 STALE / 0 UPSTREAMED. Results `e081322b5` | **= ledger**: `invalidClipDepth` fail→pass; `acid-filter` 432→104; 0 regressions (548 pass / 139 fail) | — |
