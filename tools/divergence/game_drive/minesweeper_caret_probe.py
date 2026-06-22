#!/usr/bin/env python3
"""minesweeper_caret_probe.py — focus the name field, clear it to a short string,
then exercise Home / End / arrow keys, screenshotting the caret position each
time. Verifies caret rendering + Home/End navigation.
Run: DISPLAY=:0 .../python3 minesweeper_caret_probe.py [fx] [fy]
"""
import asyncio, http.server, socketserver, threading, time, os, sys, base64
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
DOCS = ROOT / "docs2"
OUT = HERE / "compare_out"
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"]
PORT = int(os.environ.get("SMOKE_PORT", "8421"))


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def shot(page, name):
    cdp = await page.context.new_cdp_session(page)
    data = await cdp.send("Page.captureScreenshot", {"format": "png", "captureBeyondViewport": False})
    (OUT / f"{name}.png").write_bytes(base64.b64decode(data["data"]))


async def main(fx, fy):
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
        ax = box["x"] + box["width"] * fx
        ay = box["y"] + box["height"] * fy
        await page.mouse.move(ax, ay); await asyncio.sleep(0.3)
        await page.mouse.down(); await asyncio.sleep(0.2); await page.mouse.up()
        await asyncio.sleep(0.3)
        await page.evaluate("var c=document.getElementById('canvas'); if(c)c.focus();")
        await asyncio.sleep(0.3)
        # Clear most of the text to a short, fully-visible string.
        for _ in range(16):
            await page.keyboard.press("Backspace"); await asyncio.sleep(0.05)
        await asyncio.sleep(0.3)
        await shot(page, "caret_cleared")
        # End key -> caret to end of text.
        await page.keyboard.press("End"); await asyncio.sleep(0.4)
        await shot(page, "caret_end")
        # Home key -> caret to start.
        await page.keyboard.press("Home"); await asyncio.sleep(0.4)
        await shot(page, "caret_home")
        await page.close(); await browser.close()


if __name__ == "__main__":
    fx = float(sys.argv[1]) if len(sys.argv) > 1 else 0.595
    fy = float(sys.argv[2]) if len(sys.argv) > 2 else 0.719
    asyncio.run(main(fx, fy))
