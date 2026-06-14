# game_drive — browser-faithful Ruffle-vs-SWFRecomp game-frame comparison

The divergence harness (`tools/divergence/divergence_test.py`) compares Ruffle vs
SWFRecomp **headless (OFFSCREEN)** frame images, but it feeds **no input**, so it
can only reach a game's first auto-played frames. For input-gated states (menu
clicks → gameplay) — and to compare what the **browser-WASM** build actually
renders (a different code path from OFFSCREEN) — use this harness.

## What it does

`tetris_compare.py` drives **both** runtimes in headed Chrome and screenshots
each UI stage, then writes side-by-side PNGs:

- **Tier A (ground truth):** `Tetris.swf` under **Ruffle web** (`tetris_ruffle.html`, Ruffle CDN).
- **Tier B (under test):** the **SWFRecomp browser-WASM** demo (`docs2/examples/flasharchive/Tetris`).

Stages: `menu` → (Play) `play` → (Right arrow) `up` → (OK) `ok` (game).

## The one critical Chrome flag

Launch Chrome with **`--ignore-gpu-blocklist`** (alongside `--enable-unsafe-webgpu`).
Without it, screenshots of the WebGPU canvas come back **black**. With it, both
full-page and `#canvas` element screenshots capture the live canvas.

## Run

```bash
# 1. Deploy the SWFRecomp Tetris demo (browser-WASM):
source emsdk/emsdk_env.sh
SWFRecomp/scripts/build_test.sh flasharchive/Tetris wasm --graphics --clean
SWFRecomp/scripts/deploy_example.sh flasharchive/Tetris "$(pwd)/docs2/examples" --no-index --graphics

# 2. Playwright venv (once):
python3 -m venv /tmp/browser-test-venv
/tmp/browser-test-venv/bin/pip install playwright pillow
/tmp/browser-test-venv/bin/playwright install chromium   # or use system google-chrome

# 3. Run the comparison (needs DISPLAY; uses /usr/bin/google-chrome):
/tmp/browser-test-venv/bin/python3 tools/divergence/game_drive/tetris_compare.py
#   -> tools/divergence/game_drive/compare_out/compare_{menu,play,up,ok}.png
```

Stage button coordinates (fractions of the 382×380 stage) are in `FRAC` in
`tetris_compare.py`; re-measure from the runtime's button hit-test reports if a
SWF differs.

## Note on the injected-AS alternative

Forcing gameplay by **injecting** a driver AS (the dj_probe pattern,
`inject_tracer.py --bytecode`) works under **Ruffle** but currently trips a
SWFRecomp **recompiler** string-pool bug (`str_NNN undeclared`) on Tetris — so
this harness drives the **already-built** runtimes via real input instead, which
needs no recompile and exercises the true browser path.

## Not committed (local-only / generated)

`Tetris.swf` (copyrighted game asset — staged at runtime from
`~/CC/flasharchive/Tetris.swf` or `$TETRIS_SWF`) and `compare_out/` are
gitignored.
