# w2b-lowq-stroke FP32 capture (s29 coordinator, 2026-11-27)

`lowq_stroke_probe` from branch `fanout/w2b-lowq-stroke` @ `fa4ced966` (SWF sets `_quality = "LOW"`; toml quality low).
- `lowq_stroke_probe.lnx.png`: FP32 LNX, wrapper draw(); `--screen` == draw() (0 px).
- `lowq_stroke_probe.win.png`: FP32 WIN, 0 px vs LNX at tol 0. ⇒ platform-stable; this is the fixture's golden.

Also (w2b-tabindex optional request, `../w2b-tabindex.t_child_numstr_null.txt`): timeline child `c.tabIndex="x"` →
`-2147483648` (= ours), `m.tabIndex="5"` → `5` (= ours), `m.tabIndex=null` → **`undefined`** (ours `0`): null unsets.
