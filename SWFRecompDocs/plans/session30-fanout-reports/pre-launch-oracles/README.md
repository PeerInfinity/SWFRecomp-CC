# s30 pre-launch Flash oracle pass (s29 coordinator, 2026-11-27)

FP32 captures run before s30 launched, at Robert's request, so wave-1 briefs start from evidence. Tooling:
`tools/flash-oracle/run_trace.py` / `run_image.py` (direct, pinned). Our images: CI actuals on `origin/ruffle-image-results`
from the s29 FINAL run `45938113471`. Counts are channels with |Δ| > tolerance.

## 1. `avm1/movieclip_hittest_shapeflag` (trace) — resolves NO_GO §4.8

- `avm1__movieclip_hittest_shapeflag.lnx.txt`: FP32 LNX, 339 lines, **byte-identical to the golden** (golden = Flash).
- Ours differs on 6 lines: 71, 171, 173, 175, 177 (FP32 `true`, ours `false`) and 296 (FP32 `false`, ours `true`).
  - 171–177 (4): device-font glyph outlines (Noto vs Flash's proprietary font). ACCEPTED stands, now Flash-confirmed.
  - **71: real gap** (`// layers` section, `hitTest(300, 400, true)`: shape geometry, not a glyph). S–M lead.
  - **296: real gap.** The ACCEPTED entry's "both are technically correct at the boundary" is wrong: FP32 says `false`,
    like Ruffle's integer-twip morph path (`lerp_twips` + i64 cross product). Lead: integer-twip morph interpolation /
    winding for shape-flag hitTest (memory `ruffle-geometry-is-integer-twips`). S.

## 2. `from_shumway/acid/acid-large` (LOW, 500 ticks) — swap-ready

- LNX and WIN captures are **byte-identical** (`*.lnx.low.png` == `*.win.low.png`).
- ours→FP32 138 478 (t11) vs golden→FP32 178 720; ours→golden 108 639. Our render is closer to Flash than the golden.
- **A flash_fixes swap is valid** (WIN == LNX). It keeps the row failing (138 478 vs FP32), but honestly. Not applied
  pre-launch so s30's baseline stays the s29 FINAL; apply it in s30's first landing batch and ledger it.

## 3. `from_shumway/acid/acid-shapes` (HIGH, 1 tick) — the AA reopen-criterion capture

- LNX == WIN, and **the golden == FP32 exactly** (0 channels at every tolerance).
- ours→FP32 by check tolerance (3/16/32/64/128/200): 112 728 / 61 385 / 25 688 / 5 575 / 175 / 0, budgets
  113 000 / 61 300 / 25 600 / 5 600 / 180 / 0. **It fails only t16 (+85) and t32 (+88).**
- The t16/t32 excess is EDGE-ONLY (`acid-shapes-diffmap-t32.png`, `acid-shapes-residue-band.png`: rows = FP32 / ours /
  diff>32): 1-px outlines on the polygon rows, the thick curved "squiggle" strokes (y ≈ 260–420) and the ellipses. That
  is AA (w1-aa-sizing: under the faithful Flash rule this row's t16/t32 pass).
- The t128 geometry residue: 146 px, almost all on the squiggle-stroke edges, where **FP32 paints stroke colour and we
  leave background** (e.g. (360,267) ours 0,0,0 vs FP32 47,133,138). Our thick curved strokes miss coverage on their
  outer edge. Under the faithful AA rule this is the one check left (w1-aa-sizing: 210/180).
- So: fixing the curved-stroke edge geometry alone does not flip the row (t16/t32 are AA); AA alone leaves t128
  30 over. The row needs both — exactly the w1-aa-sizing reopen criterion. Correct the s29 closeout wording
  ("structural residue") accordingly.

## 4. `regression/avm2_layer_group_alpha` / `_erase` (LOW) — resolves the s29 UNSURE item

- Fresh LNX captures are byte-identical to the s29 ones (`w1-local-oracles/w2-lowq-tsnap/`), and **WIN == LNX**.
- t2 channels: alpha ours→FP32 81 986 vs exporter-golden→FP32 89 617; erase 79 910 vs 88 046. TSNAP's ~8 k move was
  **Flash-ward**. Both rows stay far from Flash (~80 k at t2): a separate gap (layer-group compositing at LOW).
- These are OUR fixtures with Ruffle-exporter HIGH goldens: re-golden them to the FP32 LOW captures in s30 (direct
  edit of `regression/`, not flash_fixes), then price the remaining gap.

## 5. Local build note (not a Flash capture)

`avm2/swz` failed locally against its FP32 golden (no `[file:line]` stack suffixes) while CI passes. Cause: the local
`SWFRecomp/build/SWFRecomp` binary predated `73d80aea1`'s `abc_emit.cpp` debug-line change. `verify_output.py` does not
rebuild the recompiler. After `cmake --build SWFRecomp/build -j4` it passes locally. **After any recompiler landing,
rebuild the local recompiler before local grading.**
