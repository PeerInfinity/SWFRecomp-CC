# Driving real-GPU Windows Chrome from WSL (Playwright over WSL→Windows interop)

**The unlock (2026-07-14):** we can run headed Playwright on the user's **Windows**
desktop *from inside WSL*, so an agent in WSL can measure real-GPU browser perf
itself — no more asking the user to paste HUD numbers. WSL2's own Chrome is
SwiftShader (software) and useless for perf; this drives the real Windows GPU.

## The mechanism
WSL interop is enabled (`/proc/sys/fs/binfmt_misc/WSLInterop` = enabled), so WSL
can execute Windows `.exe`s. The Windows host already has **Python 3.12 +
Playwright 1.61** (user site-packages) with browsers installed at
`C:\Users\Robert\AppData\Local\ms-playwright`. Calling the Windows `python.exe`
launches the browser as a native Windows process on the real desktop/GPU — no X
server / WSLg needed.

## The three rules that make it work
1. **`python.exe`, never `python3`.** `python.exe` is the Windows interpreter (on
   the Windows PATH, appended to WSL's PATH); `python3` is Linux (no Playwright).
   Confirm: `python.exe -c "import playwright,sys;print(sys.version,playwright.__file__)"`
   → `3.12.8 … C:\Users\Robert\AppData\Roaming\Python\...\playwright`.
2. **Windows paths only.** Windows `python.exe` can't take `/home/...` or `/mnt/c/...`
   as a script arg. Put the script on a Windows-visible disk and convert with
   `wslpath -w`. **Scratch dir: `C:\playwright\`** (per the user) = `/mnt/c/playwright/`
   from WSL. Files the script reads/writes (screenshots, traces) must be Windows
   paths too (e.g. `C:\playwright\shot.png`, read back at `/mnt/c/playwright/shot.png`).
3. **cmd.exe UNC noise is harmless.** `cmd.exe`/`python.exe` launched from a WSL cwd
   print "UNC paths are not supported. Defaulting to Windows directory." — cosmetic;
   filter it (`| tr -d '\r' | grep -viE 'wsl.localhost|CMD.EXE|UNC paths'`).

## Serving the pages
Serve `docs2` from WSL (`cd docs2 && python3 -m http.server 8010`); the Windows
Chromium reaches it via **WSL2 localhost forwarding** (`http://localhost:8010/...`).
Confirmed working. (Alt: serve the docs2 UNC dir from the Windows python itself via
`SimpleHTTPRequestHandler(directory=r"\\wsl.localhost\Ubuntu\...\docs2")` if
localhost forwarding ever flakes — Windows can't `chdir` to UNC but `directory=`
works.)

## Smoke test
```bash
mkdir -p /mnt/c/playwright
cat > /mnt/c/playwright/smoke.py <<'PY'
from playwright.sync_api import sync_playwright
with sync_playwright() as p:
    b=p.chromium.launch(headless=False); pg=b.new_page()
    pg.goto("https://example.com"); print("OK:",pg.title()); b.close()
PY
python.exe "$(wslpath -w /mnt/c/playwright/smoke.py)"
```

## The Seedling perf driver
`seedling_perf_win.py` (vendored here) launches headed Chromium
(`--enable-unsafe-webgpu`), prints the WebGPU adapter (real-GPU check), clicks
"Run SWF" for ours, keeps the tab hot, and reads steady-state frame CPU / fps from
`__swfPerf` (ours) or `__rufflePerf*` (Ruffle). See its header for the exact
commands. **First real-GPU A/B via this rig (2026-07-14, Intel Gen9):**
- Ours:   ~280 ms/frame (~3.6 fps), avm+submit ~264, present ~17.
- Ruffle: ~46 ms/frame (~22 fps), tick ~45, render ~0.7.
→ **Ruffle ~6x faster** (steady-state, same harness). Both AVM/CPU-bound.

## Next: CDP profiling to find our hot path
Same rig + `page` CDP session (`Profiler.start`) → self-time profile of our tick.
Symbolicate our WASM first: `EMCC_CFLAGS=--profiling-funcs` on the build (adds the
name section; no script edit) so functions show real names, not wasm indices.
