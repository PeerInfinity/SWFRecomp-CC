# Offline fit harness (s26 w2-applyfilter-edge-growth)

numpy models of applyFilter, scored against the Flash goldens. Paths are hard-coded to
`/home/user/SWFRecomp-CC` (the cloud clone); run from this directory with `python3 <script>`.

- `model.py` — destpoint_edges source/background/composite; `check_ours.py` — our master blur model (reproduces
  master's actual PNG at 0 channels); `variants.py` — blur arithmetic variants; `flashblur.py` — Flash blur +
  glow/DS/bevel model (set `flashblur.QUANT='floor'`, `offmode='bil'`); `glowfit.py` / `allcells.py` — all 14 cells
  (prints 0).
- `bqfit.py` / `bffit.py` / `effsize.py` — blur_quality / blur_fractional fits (6-bit size truncation).
- `sr.py` — filter_sourcerect variants (whole-bitmap taps).
