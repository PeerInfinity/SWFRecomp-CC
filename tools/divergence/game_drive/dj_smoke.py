#!/usr/bin/env python3
"""dj_smoke.py — minimal launch/run smoke test for Doodle Jump browser-WASM.

Purpose: regression check for the browser-WASM processTimers pump (Tetris fix).
DJ registers 4 setInterval()s for its sponsor/analytics subsystem
(checkStatusMovie / onLoadSpy / _sendInfos / idIntervalCheckLoading). Those
timers never fired before the pump; now they do. This confirms DJ still
launches, renders, and does NOT crash/hang/abort with those timers live.

Loads the deployed DJ demo, lets it run ~12s, captures console (flagging
errors/aborts), and screenshots early + late frames.
"""
import asyncio, http.server, socketserver, threading, time, os, sys
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
DOCS = ROOT / "docs2"
OUT = HERE / "compare_out"
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"]


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def main():
    OUT.mkdir(exist_ok=True)
    serve(str(DOCS), 8412)
    time.sleep(1)
    errors = []
    consolelines = []
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False,
                                           args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 900, "height": 800})

        def on_console(m):
            t = m.text
            consolelines.append(t)
            low = t.lower()
            if any(k in low for k in ("abort", "runtimeerror", "exception",
                                      "uncaught", "out of bounds", "segmentation",
                                      "memory access", "trap")):
                errors.append(t)
        page.on("console", on_console)
        page.on("pageerror", lambda e: errors.append(f"PAGEERROR: {e}"))

        await page.goto("http://127.0.0.1:8412/demo.html?test=flasharchive/Doodle_Jump",
                        wait_until="load", timeout=20000)
        # Start the runtime
        try:
            await page.click("#btn-run", timeout=8000)
        except Exception as e:
            print(f"  (no #btn-run / already running: {str(e)[:60]})", file=sys.stderr)

        await asyncio.sleep(3.0)
        try:
            await page.locator("#canvas").screenshot(path=str(OUT / "dj_smoke_early.png"),
                                                      timeout=8000)
        except Exception as e:
            print(f"  early shot failed: {str(e)[:60]}", file=sys.stderr)

        # Click roughly center to dismiss menu / start play, then run more
        try:
            box = await page.locator("#canvas").bounding_box()
            if box:
                await page.mouse.click(box["x"] + box["width"] * 0.5,
                                       box["y"] + box["height"] * 0.55)
        except Exception:
            pass

        await asyncio.sleep(9.0)
        try:
            await page.locator("#canvas").screenshot(path=str(OUT / "dj_smoke_late.png"),
                                                      timeout=8000)
        except Exception as e:
            print(f"  late shot failed: {str(e)[:60]}", file=sys.stderr)

        await page.close()
        await browser.close()

    print(f"console lines: {len(consolelines)}", file=sys.stderr)
    if errors:
        print("=== ERRORS/ABORTS DETECTED ===", file=sys.stderr)
        for e in errors[:20]:
            print("  " + e[:200], file=sys.stderr)
    else:
        print("No error/abort/exception console lines detected.", file=sys.stderr)
    print(f"Done. See {OUT}/dj_smoke_early.png, dj_smoke_late.png", file=sys.stderr)


if __name__ == "__main__":
    asyncio.run(main())
