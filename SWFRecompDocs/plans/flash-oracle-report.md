# Flash Player oracle: report (one-task session, 2026-11-23)

Brief: `c40b6560a` (flash-oracle one-task session). Tooling and how-to: `tools/flash-oracle/README.md`. Captures:
`SWFRecompDocs/plans/flash-oracle-captures/` (see `PROVENANCE.md`).

## What works

- **Both debug projectors, obtained from Adobe's own CDN.** `fpdownload.macromedia.com/pub/flashplayer/updaters/32/`
  still serves them. They are stored outside the repo (`~/CC/flashplayer/`, `C:\flashplayer\`); sha256s are in the
  README. The Windows exe has a Valid Adobe Authenticode signature. Neither projector has an EOL time bomb.
- **Traces:**
  - **Ruffle's `cargo testutils execute` runs as-is.** It is byte-identical to upstream `output.txt` on 6 tests.
  - **`run_trace.py`** does the same `mm.cfg` / temp-HOME / timeout dance for any Ruffle-layout dir, including our
    `regression/` and held fixtures. It adds a Windows mode, XTest typed input, and a wrapped exact-tick mode.
- **Images:**
  - **`run_image.py`** loads the SWF in an AS3 wrapper, draws the stage at tick N, and ships the pixels through
    flashlog. Optionally it also grabs the Xvfb window at the same tick.
  - **Both validation goldens reproduce exactly**: `avm2/pixelbender_dithering` (`5128d3943`) and `bitmapdata-clone`
    (`7facc1fcc`) give 0 outliers and max diff 0, on Linux AND Windows.
  - **7 older Ruffle image tests are also exact** (0 px), including 10–30-tick timelines.
- **Tick alignment is proved.**
  - For AVM2, INIT = tick 1. For AVM1, INIT = tick 0: the child's frame 1 runs in the next wrapper frame.
  - Flash traces and images equal the Ruffle exporter at ticks 1, 3 and 5 for both VMs.

## What doesn't / limits found

- **`draw()` mis-renders non-LAYER blend modes.**
  - `layer_alpha`: 27,638 px of draw() vs screen.
  - `acid-blend`: 4 px.
  - Use `--screen` there. Plain LAYER group alpha, cacheAsBitmap, morphs, text, filters and PixelBender are identical.
- **Screen capture needed a busy-wait hold.** Lowering `stage.frameRate` always let one more tick render.
- **Device text is host fonts.** Every `with_default_font` or device-text golden is unreproducible by real Flash, on
  Linux and on Windows.
- **Windows `draw()` leaves alpha < 255 under scrollRect.** RGB is unaffected, and the harness forces opaque.
- **Windows timing:** about 4 s startup and about 5 KB/s flushes. The harness compensates.
- **Direct trace mode overruns `num_frames`.** `--wrapped` cuts exactly at tick N, but it breaks `_level0` and AVM1
  `loadMovie` (the children never load). For loaded-shell content, take the stable prefix over several direct runs.
- **7 Ruffle image goldens don't come from Linux Flash** (table in the README). Upstream history is squashed, so their
  provenance can't be checked.
- **One upstream trace disagrees with Flash:** `avm1/movieclip_hittest`, `square.hitTest(50, 50)`. Flash gives
  `false`; the golden says `true`.

## First customers (captured; NOT landed; s27-coordinator owns landing)

| Fixture | Flash says |
|---|---|
| `avm1_edittext_html_typed_runs` | **byte-identical to the analytic golden** (with real typed "C","D"). Land it, plus an RvF entry for Ruffle's `c0=0`. |
| `avm2_applyfilter_glow_kernels` | stable, Linux == Windows; differs from the provisional golden on 22/23 rows. Use the Flash trace, not Ruffle's. |
| `avm2_bitmapdata_draw_filtered` | stable, Linux == Windows. Flash's draw() applies source filters, with numbers differing from ours on 10/13 rows (dropshadow tail, convolution edge). |
| N3 `n3_layer_alpha` | overlap = **(128,128,255)**: LAYER alpha is a transparency group (ours/Ruffle (127,63,191)). The N3 fix is confirmed and has a golden. |
| `bitmapdata_applyfilter_blur` | the grown-output blur model is confirmed visually. The text band is device serif, so a Flash golden needs a check region excluding the text, or a fixture without the default-font field. |
| `avm1_loaded_bare_goto` / `_unload_shell` / `_shell_consumers` | All three predictions are wrong, in different ways (PROVENANCE §Loaded-shell): (1) children load after frame 2's root script; (2) child frame 1 runs highest depth first (`e1 d1 c1`); (3) `unloadMovie` is NOT synchronous (Ruffle was right there). |

## Next step

- s27-coordinator: land the six trace/image results above (fixtures, goldens, RvF entries). The loaded-shell trio needs
  its `num_frames` cut taken from the Flash stable prefix, or re-derived with the timing rules above.
- Tooling follow-ups (S each):
  - `trigger = N` / `fs_command` image triggers;
  - a Windows screen path (PowerShell `CopyFromScreen`) for Windows-only text checks;
  - a `--frames-cut` for direct mode that injects a last-frame `fscommand("quit")` into a scratch copy of the SWF.
- Sweep idea: run `validate_images.py` over all 279 eligible Ruffle image tests to classify which goldens are
  Flash-made. Only goldens that are Flash-made should override a Ruffle disagreement.
