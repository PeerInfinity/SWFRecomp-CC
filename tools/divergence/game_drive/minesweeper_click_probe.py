#!/usr/bin/env python3
"""minesweeper_click_probe.py — click at canvas fractions on the Minesweeper
difficulty screen and capture MSDBG console output. Usage:
  DISPLAY=:0 .../python3 minesweeper_click_probe.py PREFIX fx1,fy1 fx2,fy2 ...
Each fx,fy is a fraction of the canvas box. Default prefix MSDBG.
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
PORT = int(os.environ.get("SMOKE_PORT", "8416"))


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def held_click(page, x, y):
    await page.mouse.move(x, y); await asyncio.sleep(0.25)
    await page.mouse.down(); await asyncio.sleep(0.35); await page.mouse.up()
    await asyncio.sleep(0.6)


async def main(prefix, clicks):
    OUT.mkdir(exist_ok=True)
    serve(str(DOCS), PORT)
    time.sleep(1)
    lines = []
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False, args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 900, "height": 700})
        page.on("console", lambda m: lines.append(m.text) if prefix in m.text else None)
        page.on("pageerror", lambda e: lines.append("PAGEERROR " + str(e)[:200]))
        await page.goto(f"http://127.0.0.1:{PORT}/demo.html?test=flasharchive/Minesweeper",
                        wait_until="load", timeout=20000)
        await page.wait_for_selector("#btn-run", timeout=20000)
        for _ in range(40):
            if await page.get_attribute("#btn-run", "disabled") is None:
                break
            await asyncio.sleep(0.25)
        await page.click("#btn-run")
        await asyncio.sleep(3.0)
        box = await page.locator("#canvas").bounding_box()
        print(f"=== canvas box {box} ===", file=sys.stderr)
        for (fx, fy) in clicks:
            ax = box["x"] + box["width"] * fx
            ay = box["y"] + box["height"] * fy
            lines.append(f"--- CLICK frac=({fx:.3f},{fy:.3f}) px=({ax:.0f},{ay:.0f}) ---")
            await held_click(page, ax, ay)
        # final screenshot
        import base64
        cdp = await page.context.new_cdp_session(page)
        data = await cdp.send("Page.captureScreenshot", {"format": "png", "captureBeyondViewport": False})
        (OUT / "click_probe.png").write_bytes(base64.b64decode(data["data"]))
        await page.close(); await browser.close()
    print(f"=== {len(lines)} lines ===")
    for l in lines:
        print(l)


if __name__ == "__main__":
    prefix = sys.argv[1] if len(sys.argv) > 1 else "MSDBG"
    clicks = []
    for a in sys.argv[2:]:
        fx, fy = a.split(",")
        clicks.append((float(fx), float(fy)))
    if not clicks:
        clicks = [(0.5, 0.5)]
    asyncio.run(main(prefix, clicks))
