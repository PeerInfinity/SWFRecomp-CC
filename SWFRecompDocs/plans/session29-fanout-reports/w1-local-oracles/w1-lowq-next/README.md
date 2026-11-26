# w1-lowq-next local oracle results (s29 coordinator, 2026-11-26, FP32)

| request | result |
|---|---|
| 1. `lowq_tsnap_tie_probe` (SWF sets `_quality="LOW"`), LNX draw | `tie_probe.lnx.png`; `--screen` == draw() (0 px); **WIN == LNX (0 px)**. Golden for the fixture. Per 40-px row, px ≠ Flash: **ours_master 120 / 120 / 84 / 356 / 629 / 574; ours_tsnap 0 / 0 / 0 / 234 / 629 / 570**. TSNAP is exact on the placement/tie rows 0–2; row 3 (nesting) has a scope residual; rows 4–5 (45° static strokes; drawing_order rect, acid-stroke-0 matrices, Drawing-API lineStyle(5), drawRect .5) are unmodelled by both legs. |
| 2. `visual/drawing_api/drawing_order` at HIGH | `drawing_order.high.png`; vs the (non-Flash) golden 4898 px. Compare with the s28 LOW capture (`session28-fanout-reports/lowq-recapture/png/`) to decide whether the 3-px band inset and the 45° width are LOW-only. |
