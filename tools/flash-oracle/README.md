# Flash Player oracle (traces + images)

Real Flash Player 32 debug projectors, scripted from WSL. Use Flash as the **first-choice oracle** wherever it works.
Fall back to the Ruffle exporter or runner only for what this README lists as out of reach. Built 2026-11-23; the
record is `SWFRecompDocs/plans/flash-oracle-report.md`.

## Setup (binaries live OUTSIDE the repo; never commit or upload them to CI or the cloud)

| What | Where | sha256 |
|---|---|---|
| Linux debug projector tarball | `~/CC/flashplayer/dl/flash_player_sa_linux_debug.x86_64.tar.gz` | `1adbd1f2df130c6f6a5e9d4da1e23513e6c682eeec0c9153bf17bcbeca1f4ac6` |
| ↳ extracted `flashplayerdebugger` (LNX 32,0,0,465) | `~/CC/flashplayer/linux/flashplayerdebugger` | `8d73e963ebbbb3cfd8418af0c692b019fe5c84e78466d9b8b6b56f9fac3db23a` |
| Windows debug projector (WIN 32,0,0,465; Authenticode **Valid**, signer Adobe Inc.) | `C:\flashplayer\flashplayer_32_sa_debug.exe` (= `/mnt/c/flashplayer/`; also `~/CC/flashplayer/dl/`) | `9d51df0c26e9ec4717a3da2e184cde831ca139d49e4a7c2f9e26028f8c4dfa52` |

- **Source:** Adobe's own CDN still serves both files (checked 2026-11-23). They are the "content debugger"
  projectors linked from the archived page
  `https://web.archive.org/web/20220401020702/https://www.adobe.com/support/flashplayer/debug_downloads.html`:
  - `https://fpdownload.macromedia.com/pub/flashplayer/updaters/32/flash_player_sa_linux_debug.x86_64.tar.gz`
  - `https://fpdownload.macromedia.com/pub/flashplayer/updaters/32/flashplayer_32_sa_debug.exe`
- **No EOL time bomb in the projectors.** Both run normally in Nov 2026. The Jan-2021 kill switch applies to the
  browser plugins only.
- **Linux runtime:** needs `xvfb-run` (installed). `ldd` shows no missing libraries. Each run gets a throwaway `HOME`
  holding `mm.cfg` and `.macromedia/Flash_Player/#Security/FlashPlayerTrust/flashoracle.cfg` (local loads and `draw()`
  report `sandbox=localTrusted`). It sets `LC_ALL=C`, the same as Ruffle's `tests/src/flashplayer/`.
- **Windows runtime (WSL interop):** `mm.cfg` is per-user at `C:\Users\<you>\mm.cfg`, the log at
  `%APPDATA%\Macromedia\Flash Player\Logs\flashlog.txt`, and trust at `%APPDATA%\…\#Security\FlashPlayerTrust\flashoracle.cfg`.
  The harness writes all three, so **runs must be sequential**. Files are staged under `C:\flashplayer\work\`, and a
  projector window briefly appears on the desktop.
- **mm.cfg** follows Ruffle: `TraceOutputFileEnable=1` and `SuppressDebuggerExceptionDialogs=1`. `ErrorReportingEnable=1`
  is set ONLY for `log_warnings` tests (`--log-warnings`). With it on, AVM1 emits extra `Warning: …` lines (Windows
  measured on `avm1/add2`). **`run_trace.py` also turns it on automatically when `output.txt` has a line starting
  `Warning: `** (s28: 8 corpus goldens carry ErrorReportingEnable lines without `log_warnings` in test.toml, e.g.
  `set_property_values/swf4`, `uncaught_exception*`, `placeobject_occupied_depth`; all 8 == golden with it on).
- **AS3 compiler:** Apache Flex SDK `~/CC/flex-sdk` (`mxmlc`, playerglobal 11.1). `capture/build.sh` rebuilds the
  wrapper. **`-omit-trace-statements=false` is mandatory**: flex-config.xml defaults to stripping `trace()`, and the
  wrapper then runs silently with an empty flashlog.
- **xgrab** (X screenshot + XTest typing): `gcc -O2 -o xgrab/xgrab xgrab/xgrab.c -lX11 -lXtst`. The binary is gitignored.
- **Ruffle's `cargo testutils execute`** works too (Linux only). `~/CC/ruffle/.flash_players.toml` (gitignored there)
  points at the Linux projector. The build lives outside the checkout, made under the lock:
  `flock /tmp/swfrecomp-cpu.lock env CARGO_BUILD_JOBS=4 CARGO_TARGET_DIR=~/CC/flashplayer/ruffle-target cargo build -p tests --bin tests`
  (3m44s). Run it as
  `cd ~/CC/ruffle && CARGO_TARGET_DIR=~/CC/flashplayer/ruffle-target cargo testutils execute --exact avm1/add2`.
  Use `--exact`: a bare filter substring-matches and concatenates several tests. Don't pass `--save-output` in the shared
  checkout. testutils is hard-wired to Ruffle's tests root, which is why `run_trace.py` exists.

## Commands

```bash
# Traces: direct mode = the projector runs test.swf as its root, exactly like testutils.
python3 tools/flash-oracle/run_trace.py <test_dir> --diff            # vs <test_dir>/output.txt
python3 tools/flash-oracle/run_trace.py <test_dir> -o flash.txt      # save
python3 tools/flash-oracle/run_trace.py <test_dir> --windows --diff  # Windows projector
python3 tools/flash-oracle/run_trace.py <test_dir> --type CD --type-after "before:"   # XTest typing (input.json fixtures)
python3 tools/flash-oracle/run_trace.py <test_dir> --wrapped         # exact num_frames cut (see limits)
python3 tools/flash-oracle/run_trace.py <test_dir> --no-pin --diff   # direct WITHOUT the window pin (old behaviour)
python3 tools/flash-oracle/run_trace.py <test_dir> --overrun 0       # hard cut at the cap (see "Run cap")

# Images: AS3 wrapper loads the SWF, draws the stage at tick N, and ships pixels through flashlog.
python3 tools/flash-oracle/run_image.py <test_dir> -o out.png [--ticks 1,3,5] [--quality low] \
        [--compare expected.png --tolerance T] [--screen] [--windows] [--verbose]
python3 tools/flash-oracle/validate_images.py <ruffle test dirs…> [--screen] [--windows] [--save-dir D]
```

- `run_image.py` reads `num_ticks`/`num_frames` and `player_options.with_renderer.quality` from `test.toml`. The default
  quality is `high`.
- The stage size, frame rate and background come from the test SWF header. The wrapper's own header is patched to
  match, and the background is painted behind the loader. A loaded SWF's `SetBackgroundColor` is otherwise ignored.
- `--compare` uses Ruffle's metric: outliers are counted **per channel** above the tolerance.
- `--screen` also saves `<out>.screen.png`, the Xvfb screenshot cropped to the stage, and compares it with `draw()`.

## Tick alignment (proved; `probes/tick_avm1`, `probes/tick_avm2`)

The rule is: Ruffle tick k (after k `run_frame`s) is the state captured by the wrapper at tick k. How the wrapper finds
tick k depends on the child's VM:

| Child | Tick 1 | Tick k > 1 |
|---|---|---|
| AVM2 (`MovieClip`) | the loader's `Event.INIT`: the child's frame 1 is constructed and its frame scripts have run. INIT fires after the wrapper's own EXIT_FRAME of that wrapper frame. | the (k−1)th wrapper `EXIT_FRAME` after INIT; the child's `currentFrame == k` |
| AVM1 (`AVM1Movie`) | the FIRST wrapper `EXIT_FRAME` after INIT. The child's frame-1 DoAction runs in the next wrapper frame, so INIT is tick 0. | the k-th `EXIT_FRAME` after INIT |

- **Proof:** at ticks 1, 3 and 5, both probes' Flash traces before the capture equal the Ruffle exporter's `-f k`
  `--trace-log`, and the Flash images equal the exporter frames with **0 differing pixels**.
- Real timelines agree. `from_shumway/timeline/Timeline3` (20 ticks) and `Timeline4` (10) match their goldens exactly,
  as does `acid-morph` (30 ticks).
- **Screen mode (`--screen`) shows the same tick.** Lowering `stage.frameRate` does NOT pin a frame: the window always
  showed tick N+1, even when frozen one tick early. So the wrapper blocks (busy-waits 4 s) at the wrapper `ENTER_FRAME`
  after tick N. At that point tick N has been presented and tick N+1 has not run, and the harness grabs the window. The
  probes give screen == `draw()` at ticks 1, 2 and 3 for both VMs.
- `image_comparisons` triggers other than the last frame (`trigger = N` or `fs_command`) are not wired up. An AVM1 child's
  `fscommand` can't reach the wrapper.

## `draw()` vs screen (measured on Linux, all at the same tick)

| Content | draw() == screen? |
|---|---|
| Plain vectors, bitmaps, cacheAsBitmap, morphs, device text, DefineFont4, scrollRect, BitmapData ops, applyFilter, PixelBender | **identical (0 px)**: 9 tests plus both tick probes (`nested_matrix`, `drawing_api`, `morph`, `cache_as_bitmap/text`, `nested_rotation`, `definefont4`, `Timeline3`, `n3_layer_alpha` (LAYER + alpha) and `bitmapdata_applyfilter_blur`) |
| `visual/blend_modes/layer_alpha` (ALPHA/ERASE-style blends inside layers) | **NO: 27 638 px differ.** The screen is right: 5 455 px off the golden, against 31 635 for draw(). |
| `from_shumway/acid/acid-blend` | 4 px differ (max 194) |

**Rule:** for blend-mode content beyond plain LAYER, use `--screen`. Stage3D and video were not measured; assume
`--screen` is needed. Windows has no screen path (`--windows --screen` is refused).

## Platform and host differences (Linux vs Windows Flash)

- **Device fonts are host fonts.** Times on Windows, the fontconfig serif under Linux, against Ruffle's bundled Noto
  Sans. Any `with_default_font` or device-text golden is unreproducible by real Flash on either platform:
  `cache_as_bitmap/text` 4 954 px, and the text band of `bitmapdata_applyfilter_blur`.
- **Windows has no direct-mode window race** (unpinned direct traces of both hitTest rows are byte-identical) and
  renders device text with the host's **ClearType** (colour fringes). The upstream device-text "Flash references"
  (`captions`, `stylesheet`, `hardwrap`, `MaskTest-2`, `acid-text-5`) use the same Windows faces in grayscale AA, so
  they don't reproduce here (s27 round 2).
- **Test fonts:** Linux direct runs install `test.toml` `[fonts.*]` into the temp HOME (fontconfig), so Ruffle's
  injected device fonts are reproducible on Linux. Bundled default-font goldens still are not.
- **Windows `draw()` leaves alpha < 255 under scrollRect'd content**, even in an opaque BitmapData; the RGB is identical.
  `run_image.py` forces alpha to 255.
- Otherwise Windows == Linux on every image and trace compared: both validation goldens, scroll_rect_culling (after the
  alpha fix), `glow_kernels`, `draw_filtered`, `avm2/add`, `avm1/add2`.
- **Windows timing:** about 4 s before the first flashlog write, then flushes of about 5 KB/s. The runner adds 8 s and
  counts idle only after the first write. A force-kill loses the unflushed tail.

## Trace-mode limits

- **Direct mode doesn't stop at `num_frames`.** Looping content appends extra lines past the Ruffle cut. Take the
  stable prefix over several runs (as done for the loaded-shell captures), or cut at a known last-frame trace.
- **Run cap (s28, `flashenv.run_cap`).** Cap = (num_frames + 1) / REAL frame rate + 2 s, plus the pin's cost
  (2.5 s Linux / 4 s Windows + 3 stub frame periods: the stub polls on enterFrame at the test's rate). Before s28 the
  rate was clamped to ≥ 1 fps and the pin's frames were not counted, so a 0.25-fps test
  (`avm2/goto_queued_invalid/swf9`, first trace at 13.7 s) was cut at a third of its length; it now captures the
  whole golden by default. **Overrun:** if flashlog is still being written when the cap hits, the run continues until
  it has been quiet for 0.5 s, for up to max(5 s, test length) more (`--overrun S`; 0 = hard cut). Still writing at
  the end → `stop=TRUNCATED` and a **boxed WARNING** on stderr: re-run with a larger `--max-duration`/`--overrun`
  before grading. A test that traces every frame forever also ends that way (+5 s; the warning says so).
  (s28's "`flash_text_TextField` came out empty" was not truncation: its golden is empty, Flash prints only FAILs.)
- **Root `onLoad` (s28).** The pin loads the test as a REPLACED `_level0`, and Flash then fires no frame-1 root
  `onLoad`. `run_trace.py` scans the root timeline's frame-1 DoActions (`flashenv.root_onload_defined`: `function
  onLoad`, `onLoad =`, `_root/_level0/this.onLoad =`; case-folded for SWF ≤ 6) and runs those SWFs **unpinned**, with
  a NOTE (`--force-pin` overrides). It flags exactly 4 of the 4 850 corpus SWFs: `avm1/root_onload`, gnash
  `action_execution_order_test4` and swfmill `trace-as2/root_onload` (all three now == golden by default), plus
  `regression/onload_type1_args`. Computed forms (`_root[k] = f`, a register-held root) are not detected: if a trace
  lacks an onLoad line, cross-check with `--no-pin`. `run_image.py`/`sweep_goldens.py` don't auto-switch.
- **Pin never released** (`pin=None` in the stop line, boxed WARNING): the test SWF never ran. Seen with 8 parallel
  Linux runs; keep Linux runs to ≤ 4 in parallel.
- **`--wrapped` cuts exactly at tick N**, but the SWF is then a loaded child:
  - `_level0` differs (`avm1/add2` diverges on its `_level0 + 1` lines);
  - **AVM1 `loadMovie` children never load** inside an AS3-hosted `AVM1Movie` (`h0 g0 k0` forever).
  So use it only for self-contained AVM2/AVM1 content.
- **Load timing is real I/O.** The loaded-shell fixtures were stable inside `num_frames` over 6 runs; only the tail past
  the cut varied.
- **Typed input:** XTest keys go to the projector's toplevel with **no click**. A click on empty stage clears Flash's
  text focus (measured).

## Validation (2026-11-23)

| Test | Golden | Result |
|---|---|---|
| `avm2/pixelbender_dithering` | upstream Flash golden `5128d3943` | **0 outliers, max diff 0** (Linux and Windows; limit tol 1 / 32 500) |
| `bitmapdata-clone` (from_shumway) | upstream Flash golden `7facc1fcc` | **0 outliers, max diff 0** (Linux and Windows; tol 77) |
| `cache_as_bitmap/nested_matrix`, `timeline/Timeline3` (20 t), `Timeline4` (10 t), `acid/acid-morph` (30 t), `avm1/bitmap_data_copypixels`, `avm2/bitmapdata_copypixels`, `visual/scroll_rect_culling` | goldens at Ruffle `0ddd12b6a` | **all exact (0 px)**: Flash-made goldens |
| `cache_as_bitmap/drawing_api` 600 px, `nested_rotation` 129 px, `morph` 2 832 px (max 1), `definefont4` 6 331 px, `cache_as_bitmap/text` 4 954 px, `acid-blend` 5 559 px, `blend_modes/layer_alpha` 5 455 px (screen) | same | not reproduced; screen == draw() except the blend rows. These goldens are not Linux-Flash output (Ruffle-made, other-platform, or device text); upstream history is squashed, so provenance can't be checked by git. |

Traces: `cargo testutils execute` is byte-identical on `avm1/add2`, `avm2/add`, `avm1/array_sort`, `avm2/array_sort`,
`avm1/textfield_text` and `pixelbender_dithering`. `run_trace.py` agrees in both direct and Windows modes. One upstream
`output.txt` disagrees with Flash: `avm1/movieclip_hittest`, at "Square, no scale / square.hitTest(50, 50)", where Flash
gives `false` and the golden says `true`.

## Golden sweep (`sweep_goldens.py`, s27)

```bash
python3 tools/flash-oracle/sweep_goldens.py <test rel to root> --root ruffle-tests/tests/swfs --out-dir D [--screen | --direct [--no-pin] | --windows]
```

- **What it does.**
  - Captures every numeric `trigger` tick in one wrapper run.
  - Grades each comparison with ALL of its `checks`, using Ruffle semantics.
  - Writes `D/<test>[.screen|.direct].json` and the Flash PNGs to `D/png/`.
  - `validate_images.py` only grades the first comparison at the last tick.
- **`--screen`:** one projector run per trigger tick, since the hold only happens at the last captured tick.
- **`--quality Q`** overrides `test.toml`'s quality. Some goldens are Flash at its DEFAULT quality (high) although
  `test.toml` says low (`gradientTransform` exact, `acid-color` frame1); a `--quality high` wrapper sweep finds them.
- **`--windows`:** draw mode on the Windows projector (strictly one run at a time).
- **Wrapper false negatives:** a pinned `--direct` root is a second opinion for "not Flash" wrapper verdicts.
  `displayobject_hittestpoint_boundary` (off-stage child), `loader_jpegxr`, `loader_jpegxr_alpha` and
  `acid-bitmap-draw_quality_low` all fail under the wrapper and pass exactly as roots, pinned or not.
- **`--direct`:** the SWF runs as the REAL root behind the window pin (`--no-pin` to skip it), and the Xvfb window is
  grabbed after it settles, twice, 1 s apart (`static`). The tick is NOT
  pinned, so use it only for static content.
  - It is needed for the ~50 AVM2 tests whose document-class constructor touches `stage`. In a Loader child `stage`
    is null, so under the wrapper they die with `TypeError #1009` before tick 1.
  - It is also needed for runtime-load tests (AVM1 `loadMovie` never loads under the wrapper).
  - A modal dialog (e.g. `FileReference.save`) covers the stage and spoils the crop.
- **`mm.cfg PreloadSwf` root agent: tried and ruled out.** The preload SWF runs (for AVM1 and AVM2 roots), but the
  main movie gets a NEW Stage. The preload's `stage` becomes null, and no stage event of the main movie reaches it.
- **Window-size race: FIXED by the direct-mode window pin (below).** Unpinned, the projector's GTK drawing area is
  640×468 for the first ~0.3–1.5 s, so a direct root plays its first frames show-all scaled (`concatenatedMatrix`
  ×640/550, hitTest results flipped). `--no-pin` (both tools) reproduces the old behaviour.

## Direct-mode window pin (s27 round 2; `capture/System/PinStub.as`)

Direct runs (`run_trace.py` default, `sweep_goldens.py --direct`) no longer start the test as the projector's first
root. They start `capture/PinStub.swf` (AVM1, built by `capture/build.sh` with MTASC), header-patched to the test's
stage RECT, frame rate and background colour, inside a **staged copy of the test dir**. The harness (`flashenv.PinGate`)
watches the X window tree, and once the toplevel has left its 640×520 startup size and held still for 0.5 s it drops
`__pin_go.txt`; the stub then `getURL(test.swf, "_level0")`, so the test replaces `_level0` and runs as the real root
at 1:1 from its frame 1. The Windows projector (no X tree) is released after a fixed 3 s.

- **Proof:** `displayobject_scrollrect`, `movieclip_hittest`, `displayobject_hittestpoint_boundary`, 4 parallel runs
  each: pinned 12/12 byte-identical to the goldens, unpinned 0/12. On the 106 image tests with an `output.txt`:
  72 byte-identical pinned vs 70 unpinned; the only loss was a load flake (`acid-text-x`, serial 3/3 identical).
- **Why the gate is X-side:** `Stage.width/height` (noScale) inside the stub report the final size from its first
  frame on, before GTK has resized the drawing area, so the stub can't time itself.
- **Staged copy:** Flash resolves relative URLs against the FIRST root's directory, so the stub must sit next to the
  test (`mcl_replace_root_*`, `movieclip_state_values` load siblings). Paths in traces therefore show a temp dir.
- **Background:** the stub's `SetBackgroundColor` survives the replacement, so the harness stamps the test's colour
  into the stub (`patch_swf_header(..., bg=)`); without it black-stage tests (`focus_*`) came out white.
- **Quality:** the stub sets `_root._quality` from `test.toml` `with_renderer.quality`. It carries into an **AVM1**
  root (`_quality` traces `LOW`) but **not an AVM2 root** (new Stage, `stage.quality` = `HIGH`). AVM2 `quality = "low"`
  rows can't be graded from a direct capture (use the wrapper when the test allows it).
  **Before s28 the stub's unqualified `_quality = …` set `_global._quality` and the player stayed HIGH**: every pinned
  direct capture of an AVM1 `quality = "low"` row before 2026-11-25 was really HIGH. Re-captures (`*.newstub.*`):
  s27 `golden-provenance/` and s28 `w1-local-oracles/w1-text-glyph-aa/`; gnash `place_object_test` and `shape_test`
  then PASS their goldens (were 5 209 / 1 071 px "not FP32").
- **No trace in the test's globals (s28).** `_global` survives the replacement. The old top-level `class PinStub`
  left `_global.PinStub` (+ `_global._quality`) in `_global` enumerations (`global_proto_decls*`, gnash `argstest-v*`)
  and, under ErrorReportingEnable, a `Warning: Reference to undeclared variable, 'PinStub'` (MTASC's class prologue
  probes the name with GetVariable). The stub is now `class System.PinStub` (the prologue then probes the EXISTING
  `System`), deletes `_global.System.PinStub` first thing, and keeps its state in closures: `global_proto_decls` and
  `argstest-v7` pinned == their `--no-pin` runs. Old stub for A/Bs: `FLASH_ORACLE_PIN_STUB=<path>` overrides the stub.
- **Narrow stages (< 296 px wide):** the menubar keeps the drawing area ≥ ~296 px wide while the toplevel is only
  stage-wide and clips it, so a centred stage sits off-window. Those stages are pinned with `Stage.align = "TL"`
  (it survives the replacement; the test then traces `Stage.align` = `TL`/`LT`, not `""`). Heights are not clamped.
- **Crop:** the stage is now the top-left of the **largest child of the projector toplevel** (`run_image.drawing_area`).
  The old rule ("smallest window ≥ w×h") picked the 20×72 toplevel (its menubar) for small stages.
- **Device fonts:** `[fonts.*]` files in `test.toml` (Ruffle injects them as device fonts) are copied into the temp
  HOME's `~/.fonts`; Linux Flash finds them through fontconfig (`device_font_no_ink`, `leading_device_font`,
  `edittext_device_transform_negative` now match their goldens). Windows has no equivalent yet.
- **Screen:** Xvfb is now 2048×2600 (`flashenv.XVFB_SCREEN`), so 800/1000-px-tall stages are not clipped (or
  constrained by GTK).
- **Static check:** `sweep_goldens.py --direct` grabs twice 1 s apart and records `static`; only a static PASS (or an
  exact match) is evidence for an animating test, whose tick is still unpinned.
- **Known divergence:** `from_gnash/misc-swfmill.all/missing_bitmap` (a fill naming an undefined bitmap) draws a
  200×200 red block as a first root (and under the wrapper) but only a 2×2 red block at (0,0) as a replaced `_level0`.
  Use `--no-pin` to cross-check anything that depends on first-root-only state.

- **The README's validation goldens.** The two rows below were validated against upstream goldens NEWER than our
  mirror. Ruffle re-baked them as Flash references on 2026-11-23 (`5128d3943`, `7facc1fcc`). Against our mirror's
  older goldens, Flash is 22 953 px / 23 380 px off. (CI is unaffected: it downloads upstream master at run time.)
- Results of the full sweep: `SWFRecomp-CC-history:SWFRecompDocs/plans/session27-fanout-reports/golden-provenance.md`.

## Files

- `flashenv.py`: player environments (Linux temp-HOME + Xvfb; Windows interop) and the SWF header parse/patch.
- `run_trace.py`, `run_image.py`, `validate_images.py`, `sweep_goldens.py`: the CLIs above.
- `capture/CaptureWrapper.as` + `build.sh` → `CaptureWrapper.swf` (committed, 4.7 KB).
- `capture/System/PinStub.as` + `build.sh` (MTASC) → `PinStub.swf` (committed): the direct-mode window pin.
- `xgrab/xgrab.c`: X window tree, root screenshot (PPM), and XTest typing.
- `probes/tick_avm1`, `probes/tick_avm2`: the tick-alignment probes (MTASC / mxmlc sources + SWFs).
