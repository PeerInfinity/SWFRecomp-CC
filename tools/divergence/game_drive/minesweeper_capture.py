#!/usr/bin/env python3
"""minesweeper_capture.py — capture browser-WASM frames via the renderer-side
GPU framebuffer readback (window.dbgCaptureBoard, backed by dbgCapturePNG /
copyTextureToBuffer). Unlike page/CDP screenshots, this is a direct GPU copy and
does NOT hang on a busy board in WSL2 (no software-present-queue saturation).

Captures: menu (after Run) -> board (after Start) -> board (after Restart).
Each is a PNG data URL decoded and written to compare_out/.

Usage:
  DISPLAY=:0 python3 minesweeper_capture.py
"""
import asyncio, base64, http.server, socketserver, threading, time, os, sys
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
DOCS = ROOT / "docs2"
OUT = HERE / "compare_out"
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"]
PORT = int(os.environ.get("SMOKE_PORT", "8417"))

# Button centers as canvas fractions (from the status doc / handoff).
START = (0.5, 0.896)
RESTART = (0.32, 0.866)


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def held_click(page, box, fx, fy):
    ax = box["x"] + box["width"] * fx
    ay = box["y"] + box["height"] * fy
    await page.mouse.move(ax, ay); await asyncio.sleep(0.25)
    await page.mouse.down(); await asyncio.sleep(0.35); await page.mouse.up()
    await asyncio.sleep(0.8)


# Self-contained capture driver (does not depend on the C-side window.dbgCaptureBoard
# install, which only appears after the first dbgCapturePNG call). Uses the raw
# exported primitives: dbgCapturePNG (request) -> poll dbgCaptureReady -> read
# RGBA at dbgCaptureData -> encode PNG via a 2D canvas.
CAPTURE_JS = """
async () => {
  if (!window.Module || !Module.ccall) return null;
  Module.ccall('dbgCapturePNG', null, [], []);
  let ready = 0;
  for (let i = 0; i < 900; i++) {           // up to ~30s (C-side map wait can be ~20s)
    ready = Module.ccall('dbgCaptureReady', 'number', [], []);
    if (ready) break;
    await new Promise(r => setTimeout(r, 33));
  }
  if (!ready) return null;
  const ptr = Module.ccall('dbgCaptureData', 'number', [], []);
  const w = Module.ccall('dbgCaptureWidth', 'number', [], []);
  const h = Module.ccall('dbgCaptureHeight', 'number', [], []);
  if (!ptr || !w || !h) return null;
  const bytes = Module.HEAPU8.subarray(ptr, ptr + w * h * 4);
  const cnv = document.createElement('canvas');
  cnv.width = w; cnv.height = h;
  const cx = cnv.getContext('2d');
  const img = cx.createImageData(w, h);
  img.data.set(bytes);
  cx.putImageData(img, 0, 0);
  return cnv.toDataURL('image/png');
}
"""


async def capture(page, name):
    """Trigger a GPU-readback capture and write the PNG. Returns True on success."""
    t0 = time.time()
    try:
        data_url = await asyncio.wait_for(page.evaluate(CAPTURE_JS), timeout=35.0)
    except asyncio.TimeoutError:
        print(f"  [{name}] capture TIMED OUT after {time.time()-t0:.1f}s")
        return False
    print(f"  [{name}] evaluate returned in {time.time()-t0:.1f}s")
    if not data_url or "," not in data_url:
        print(f"  [{name}] capture FAILED (data_url={str(data_url)[:60]})")
        return False
    png = base64.b64decode(data_url.split(",", 1)[1])
    path = OUT / f"capture_{name}.png"
    path.write_bytes(png)
    print(f"  [{name}] wrote {path} ({len(png)} bytes)")
    return True


async def main():
    OUT.mkdir(exist_ok=True)
    serve(str(DOCS), PORT)
    time.sleep(1)
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False, args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 900, "height": 700})
        page.on("pageerror", lambda e: print("PAGEERROR", str(e)[:200]))
        page.on("console", lambda m: print("CONSOLE", m.text[:160]) if ("apture" in m.text or "rror" in m.text or "DBG" in m.text) else None)
        await page.goto(f"http://127.0.0.1:{PORT}/demo.html?test=flasharchive/Minesweeper",
                        wait_until="load", timeout=30000)
        await page.wait_for_selector("#btn-run", timeout=30000)
        for _ in range(40):
            if await page.get_attribute("#btn-run", "disabled") is None:
                break
            await asyncio.sleep(0.25)
        await page.click("#btn-run")
        await asyncio.sleep(3.0)
        # Throttle the render loop (~6fps) so the software-WebGPU present queue
        # stays drained — keeps captures fast and clicks responsive on the board.
        await page.evaluate("() => window.Module && Module.ccall('dbgSetFrameCapMs', null, ['number'], [160])")
        box = await page.locator("#canvas").bounding_box()
        print(f"=== canvas box {box} ===")

        print("--- capture MENU ---")
        await capture(page, "menu")

        print("--- click START ---")
        try:
            await asyncio.wait_for(held_click(page, box, *START), timeout=25.0)
        except asyncio.TimeoutError:
            print("  START click TIMED OUT")
        await asyncio.sleep(1.0)
        print("--- capture BOARD ---")
        await capture(page, "board")

        print("--- click RESTART ---")
        try:
            await asyncio.wait_for(held_click(page, box, *RESTART), timeout=25.0)
        except asyncio.TimeoutError:
            print("  RESTART click TIMED OUT")
        await asyncio.sleep(1.0)
        print("--- capture BOARD after RESTART ---")
        await capture(page, "board_after_restart")

        await page.close(); await browser.close()


if __name__ == "__main__":
    asyncio.run(main())
