Bevel sample-offset fit (s28 w2-filter-residuals-land, item 3). Pure Python, no deps.
Inputs (absolute paths in `load.py`): the FP32 capture
`w1-local-oracles/w1-filter-residuals/avm2_bevel_sample_isolation_probe.flash32.txt` and our provisional output.

- `load.py`: parse `<label> y=<y>: <getPixel32 hex>...` rows; `dval` = signed bevel d (alpha, sign from colour).
- `m.py`: B = Flash's `blur3` grid; `samp` = floored bilinear sample (float or 1/W weights).
- `s7.py`: `runq(q)` scores an offset-quantiser q over all 30 cases (d == floor(S(+o)) - floor(S(-o))).
- `s10.py` / `s11.py`: per-SIDE fit. They use pixels whose opposite sample sits in a flat B region, so d pins one
  sample alone. `s11.py` prints every exactly-fitting offset in 1/256 px per side and case. It showed:
  - the same nominal -362.04 fits -363 at 45 deg but -361 at 135 deg (not a per-component quantiser);
  - every d 2 / 3 case is round(o) + 1/256 toward +x +y on the +o side.
- `s13.py`: sweep of the `floor(o*256 + c)` constant. c in [1.34, 1.47) is the window; 1.4 is landed. Integral
  components must stay exact (c applied to a0 / a90 breaks them).
Result: 2175 px -> 177 px over the probe (C == Python: 177).
