#!/usr/bin/env python3
"""minesweeper_ruffle_click.py — click test points on the Minesweeper difficulty
screen under Ruffle (ground truth) and screenshot after each, to learn which
regions Ruffle treats as clickable (Start button interior, radios). Stage is
500x335; the ruffle player element is exactly that size, so canvas frac maps
directly to stage coords.
Run: DISPLAY=:0 .../python3 minesweeper_ruffle_click.py fx,fy [fx,fy ...]
"""
import asyncio, http.server, socketserver, threading, os, sys, shutil
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
OUT = HERE / "compare_out"
OUT.mkdir(exist_ok=True)
SRC_SWF = ROOT / "SWFRecomp/tests/flasharchive/Minesweeper/test.swf"
DST_SWF = HERE / "Minesweeper.swf"
if SRC_SWF.exists():
    shutil.copy2(SRC_SWF, DST_SWF)
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"]


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def main(clicks):
    serve(str(HERE), 8132)
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False, args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 520, "height": 360})
        page.on("console", lambda m: print("  log:", m.text) if ("harness" in m.text or "race" in m.text.lower()) else None)
        await page.goto("http://127.0.0.1:8132/minesweeper_ruffle.html")
        await asyncio.sleep(5.0)
        cont = await page.query_selector("#ruffle-container")
        box = await cont.bounding_box()
        print(f"=== container box {box} ===", file=sys.stderr)
        await cont.screenshot(path=str(OUT / "ruffle_click_before.png"))
        for idx, (fx, fy) in enumerate(clicks):
            ax = box["x"] + box["width"] * fx
            ay = box["y"] + box["height"] * fy
            print(f"--- ruffle click {idx} frac=({fx:.3f},{fy:.3f}) px=({ax:.0f},{ay:.0f}) ---")
            await page.mouse.move(ax, ay); await asyncio.sleep(0.2)
            await page.mouse.down(); await asyncio.sleep(0.25); await page.mouse.up()
            await asyncio.sleep(1.0)
            await cont.screenshot(path=str(OUT / f"ruffle_click_{idx}.png"))
        await browser.close()


if __name__ == "__main__":
    clicks = []
    for a in sys.argv[1:]:
        fx, fy = a.split(","); clicks.append((float(fx), float(fy)))
    if not clicks:
        clicks = [(0.5, 0.896)]
    asyncio.run(main(clicks))
