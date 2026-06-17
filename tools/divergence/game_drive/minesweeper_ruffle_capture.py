#!/usr/bin/env python3
"""minesweeper_ruffle_capture.py — capture the Minesweeper difficulty screen
under Ruffle web (ground truth) for a side-by-side diff against the SWFRecomp
browser-WASM render. Loads minesweeper_ruffle.html in headed Chrome (WebGPU via
WSLg) and screenshots the Ruffle canvas after it settles.

Output: compare_out/ruffle_Minesweeper.png
Run: DISPLAY=:0 /tmp/browser-test-venv/bin/python3 minesweeper_ruffle_capture.py [wait_s]
"""
import asyncio, http.server, socketserver, threading, os, sys, shutil
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
OUT = HERE / "compare_out"
OUT.mkdir(exist_ok=True)

# Stage the SWF next to the harness HTML (SWFs are gitignored, so copy from the
# canonical test dir at runtime rather than committing a binary).
SRC_SWF = ROOT / "SWFRecomp/tests/flasharchive/Minesweeper/test.swf"
DST_SWF = HERE / "Minesweeper.swf"
if SRC_SWF.exists():
    shutil.copy2(SRC_SWF, DST_SWF)
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"]
WAIT_S = float(sys.argv[1]) if len(sys.argv) > 1 else 6.0


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def main():
    serve(str(HERE), 8131)
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False,
                                           args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 520, "height": 360})
        logs = []
        page.on("console", lambda m: logs.append(m.text))
        await page.goto("http://127.0.0.1:8131/minesweeper_ruffle.html")
        await asyncio.sleep(WAIT_S)
        canvas = await page.query_selector("#ruffle-container")
        out = OUT / "ruffle_Minesweeper.png"
        if canvas:
            await canvas.screenshot(path=str(out))
            print(f"saved {out}")
        else:
            await page.screenshot(path=str(out))
            print(f"saved full page {out}")
        for l in logs:
            if "harness" in l or "error" in l.lower():
                print("  log:", l)
        await browser.close()


asyncio.run(main())
