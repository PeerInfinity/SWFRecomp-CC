# Flash Player captures: provenance

Captured 2026-11-23 by the flash-oracle session (`tools/flash-oracle/`). Nothing here is landed. The s27 fan-out
coordinator owns turning these into fixtures, goldens and dispositions.

**Player:** Flash Player 32 debug projector, `LNX 32,0,0,465` (`flashplayerdebugger` sha256 `8d73e963…a3db23a`),
under `xvfb-run` on WSL2 (Linux 6.18). Each run gets a temp `HOME`, `mm.cfg` = `TraceOutputFileEnable=1` +
`SuppressDebuggerExceptionDialogs=1` (no `ErrorReportingEnable`), and `LC_ALL=C`. Where noted, the result was
cross-checked on the Windows projector `WIN 32,0,0,465`. All commands are run from the repo root, with
`H=SWFRecompDocs/plans/session26-fanout-reports`.

| Capture | Command | Stability / notes |
|---|---|---|
| `avm2_applyfilter_glow_kernels/output.flash.txt` | `python3 tools/flash-oracle/run_trace.py $H/w2-held-fixtures/avm2_applyfilter_glow_kernels -o …` | 3/3 Linux runs identical; **Windows identical**. Differs from the provisional output.txt on 22 of 23 rows. Most differences are a few levels per channel, but some edge pixels flip between 0 and non-zero (max channel diff 255). |
| `avm2_bitmapdata_draw_filtered/output.flash.txt` | same, on `…/avm2_bitmapdata_draw_filtered` | 3/3 identical; **Windows identical**. Flash's draw() DOES apply the source's filters, but 10 of 13 rows differ from the provisional output: the dropshadow tail is shorter, and the convolution edge is `ffff0000`, 1 px wider, where the provisional output had `ffaa0000`. |
| `avm1_edittext_html_typed_runs/output.flash.txt` | build `test.swf` from `$H/w1-avm1-dispatch-scope-fixtures/avm1_edittext_html_typed_runs/create_test_swf.py` into a scratch copy of the dir, then `run_trace.py <copy> --type CD --type-after "before:" --max-duration 4` | 3/3 identical. **Byte-identical to the fixture's analytic output.txt**: Flash gives `c0=16711680` after typing at index 0, so Ruffle's `c0=0` is a Ruffle artifact (RvF entry). |
| `avm1_loaded_bare_goto/output.flash.txt` | `run_trace.py $H/w2-held-fixtures/avm1_loaded_bare_goto -o …` (direct) | 6/6 identical (the SWF stops at frame 10). |
| `avm1_loaded_unload_shell/output.flash.stable-prefix.txt` (+ `run1-full`) | same, direct | 6 runs; the first 59 lines are identical. The tail past `num_frames` (the looping child) varies with the timeout cut. |
| `avm1_loaded_shell_consumers/output.flash.stable-prefix.txt` (+ `run1-full`) | same, direct | 6 runs; the first 66 lines are identical. Same tail caveat. |
| `n3_layer_alpha/flash.{high,low}.png` | copy `$H/w1-pixel-layer-colour-fixtures/probes/n3_layer_alpha.swf` to `<dir>/test.swf` with `num_ticks = 1`, then `run_image.py <dir> -o … --quality high\|low --screen` | screen == draw() (0 px) at both qualities. The overlap at (80,50) = **(128,128,255)**: LAYER alpha is a transparency group. Ours and Ruffle's per-child model gives (127,63,191). |
| `bitmapdata_applyfilter_blur/flash.png` | `run_image.py ruffle-tests/tests/swfs/avm2/bitmapdata_applyfilter_blur -o … --screen` (quality low from test.toml) | screen == draw(). Against the current golden: 29 971 px / 73 140 channel outliers at tol 12. The cells are grown by the blur reach (the s26 `6a6699c55` Flash model). The "Ruffle" text band uses Flash's device serif, so it can never match a Ruffle-default-font render. The trace is byte-identical to output.txt. |

**Loaded-shell readings** (direct mode, inside `num_frames`; `<` = predicted output.txt, `>` = Flash):
- `bare_goto`: in Flash the children are NOT loaded at frame 2 (`p2 h0 g0 k0`). Their frame 1 runs after the root's
  frame-2 script, in the order `e1, d1, c1` (k@3, g@2, h@1: highest depth first). The trace then reads
  `p3 h1 g2 k1`, `d2`, `c2`, `p4 h2 g2 k1`, `c3`, `p5`, `c2`, … Neither the prediction nor the Feb-2026 Ruffle runner
  has this order.
- `unload_shell`: Flash prints `a:movieclip b:movieclip` right after `h.unloadMovie()`, so **the unload is NOT
  synchronous**. Ruffle's runner was right on that point.
- `shell_consumers`: Flash has no `cx` before `t2`, and the frame-2 probe sees nothing loaded yet (`in:` /
  `ev:undefined …`). From `t3` to the end of the predicted output.txt the lines match. Flash keeps going past
  `num_frames`.
