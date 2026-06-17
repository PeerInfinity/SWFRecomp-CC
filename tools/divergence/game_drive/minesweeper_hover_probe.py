#!/usr/bin/env python3
"""minesweeper_hover_probe.py — move (no click) over canvas fractions, read the
canvas CSS cursor + screenshot, to verify hover-color + cursor changes.
Run: DISPLAY=:0 .../python3 minesweeper_hover_probe.py fx,fy [fx,fy ...]"""
import asyncio, http.server, socketserver, threading, time, os, sys
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
DOCS = ROOT / "docs2"
OUT = HERE / "compare_out"
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"]
PORT = int(os.environ.get("SMOKE_PORT", "8417"))


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def main(points):
    OUT.mkdir(exist_ok=True)
    serve(str(DOCS), PORT)
    time.sleep(1)
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False, args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 900, "height": 700})
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
        for idx, (fx, fy) in enumerate(points):
            ax = box["x"] + box["width"] * fx
            ay = box["y"] + box["height"] * fy
            await page.mouse.move(ax, ay)
            await asyncio.sleep(0.8)
            cur = await page.evaluate("() => { const c=document.querySelector('#canvas'); return c ? getComputedStyle(c).cursor : 'no-canvas'; }")
            print(f"point {idx} frac=({fx:.3f},{fy:.3f}) px=({ax:.0f},{ay:.0f}) cursor={cur}")
            import base64
            cdp = await page.context.new_cdp_session(page)
            data = await cdp.send("Page.captureScreenshot", {"format": "png", "captureBeyondViewport": False})
            (OUT / f"hover_{idx}.png").write_bytes(base64.b64decode(data["data"]))
        await page.close(); await browser.close()


if __name__ == "__main__":
    pts = []
    for a in sys.argv[1:]:
        fx, fy = a.split(","); pts.append((float(fx), float(fy)))
    if not pts:
        pts = [(0.5, 0.896)]
    asyncio.run(main(pts))
