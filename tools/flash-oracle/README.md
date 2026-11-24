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
  measured on `avm1/add2`).
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
- **Windows `draw()` leaves alpha < 255 under scrollRect'd content**, even in an opaque BitmapData; the RGB is identical.
  `run_image.py` forces alpha to 255.
- Otherwise Windows == Linux on every image and trace compared: both validation goldens, scroll_rect_culling (after the
  alpha fix), `glow_kernels`, `draw_filtered`, `avm2/add`, `avm1/add2`.
- **Windows timing:** about 4 s before the first flashlog write, then flushes of about 5 KB/s. The runner adds 8 s and
  counts idle only after the first write. A force-kill loses the unflushed tail.

## Trace-mode limits

- **Direct mode doesn't stop at `num_frames`.** It runs for num_frames/fps + 2 s, so looping content appends extra
  lines past the Ruffle cut. Take the stable prefix over several runs (as done for the loaded-shell captures), or cut at
  a known last-frame trace.
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

## Files

- `flashenv.py`: player environments (Linux temp-HOME + Xvfb; Windows interop) and the SWF header parse/patch.
- `run_trace.py`, `run_image.py`, `validate_images.py`: the CLIs above.
- `capture/CaptureWrapper.as` + `build.sh` → `CaptureWrapper.swf` (committed, 4.7 KB).
- `xgrab/xgrab.c`: X window tree, root screenshot (PPM), and XTest typing.
- `probes/tick_avm1`, `probes/tick_avm2`: the tick-alignment probes (MTASC / mxmlc sources + SWFs).
