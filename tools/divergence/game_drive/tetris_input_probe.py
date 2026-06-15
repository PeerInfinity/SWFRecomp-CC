#!/usr/bin/env python3
"""tetris_input_probe.py — discriminate the stale-block-trail bug from legit
vertical stacking by driving the SWFRecomp Tetris piece HORIZONTALLY.

Navigates menu->play->up->ok (same FRAC coords as tetris_compare.py), then sends
keyboard arrows. A correct piece moves cleanly; the erase bug leaves a horizontal
smear of stale blocks. Captures: ok_early (one piece mid-fall), after_left,
after_right.
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
FRAC = {"play": (200/382, 207/380), "up": (229/382, 247/380), "ok": (172/382, 285/380)}


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def held_click(page, x, y):
    await page.mouse.move(x, y); await asyncio.sleep(0.3)
    await page.mouse.down(); await asyncio.sleep(0.4); await page.mouse.up()
    await asyncio.sleep(1.3)


async def shot(page, el, name):
    p = OUT / f"{name}.png"
    try:
        await el.screenshot(path=str(p), timeout=6000); return
    except Exception:
        pass
    try:
        import base64
        cdp = await page.context.new_cdp_session(page)
        data = await cdp.send("Page.captureScreenshot", {"format": "png", "captureBeyondViewport": False})
        p.write_bytes(base64.b64decode(data["data"]))
    except Exception as e:
        print(f"  {name}: shot failed {str(e)[:60]}", file=sys.stderr)


async def main():
    OUT.mkdir(exist_ok=True)
    serve(str(DOCS), 8413)
    time.sleep(1)
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False, args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 900, "height": 700})
        await page.goto("http://127.0.0.1:8413/demo.html?test=flasharchive/Tetris",
                        wait_until="load", timeout=20000)
        await page.wait_for_selector("#btn-run", timeout=20000)
        for _ in range(40):
            if await page.get_attribute("#btn-run", "disabled") is None:
                break
            await asyncio.sleep(0.25)
        await page.click("#btn-run")
        await asyncio.sleep(3.0)
        el = page.locator("#canvas")
        box = await el.bounding_box()
        def at(frac):
            return box["x"] + box["width"]*frac[0], box["y"] + box["height"]*frac[1]
        # menu -> play -> up -> ok
        ax, ay = at(FRAC["play"]); await held_click(page, ax, ay)
        ax, ay = at(FRAC["up"]);   await held_click(page, ax, ay)
        ax, ay = at(FRAC["ok"]);   await held_click(page, ax, ay)
        await asyncio.sleep(0.5)
        await shot(page, el, "probe_ok_early")  # one piece mid-fall
        # focus canvas, drive horizontally
        await page.mouse.click(box["x"] + box["width"]*0.5, box["y"] + box["height"]*0.4)
        for _ in range(5):
            await page.keyboard.press("ArrowLeft"); await asyncio.sleep(0.18)
        await shot(page, el, "probe_after_left")
        for _ in range(8):
            await page.keyboard.press("ArrowRight"); await asyncio.sleep(0.18)
        await shot(page, el, "probe_after_right")
        await page.close(); await browser.close()
    print(f"Done. probe_ok_early / probe_after_left / probe_after_right in {OUT}", file=sys.stderr)


if __name__ == "__main__":
    asyncio.run(main())
