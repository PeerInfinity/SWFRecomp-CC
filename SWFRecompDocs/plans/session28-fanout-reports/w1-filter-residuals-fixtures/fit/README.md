Fit scripts behind `w1-filter-residuals-report.md` (pure Python, no deps beyond Pillow).

- `fit_shadow.py DIR`: DIR holds `output.actual.png` (ours) and `output.expected.png` (FP32
  `w2b_shadow_shape_a50/flash.screen.png`). It compares the nearest-offset and bilinear-fractional-offset models.
- `fit_ds.py DIR`: DIR holds ours and the FP32 `avm1_applyfilter_dropshadow` flash.png. It is a replica of
  `fb_glowlike_region` for DropShadow and prints the Flash-minus-ours sign map.
- `fit_ds2.py DIR fit_ds.py`: grid search over offset quantisation, bilinear forms and the alpha multiply.
- `bevel.py` … `bevel4.py`: the `bevel full knockout` residual replica, the offset-perturbation search, the
  shift-then-blur test and the blur-division variants (all refuted; report §3).
