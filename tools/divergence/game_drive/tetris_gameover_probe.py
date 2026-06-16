#!/usr/bin/env python3
"""tetris_gameover_probe.py — drive SWFRecomp Tetris to game-over (no lateral
input -> single-column top-out) and capture PMDIAG console + periodic shots.

Output: compare_out/pmdiag.log  and  compare_out/go_NN.png
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
FRAC = {"play": (200/382, 207/380), "up": (229/382, 247/380), "ok": (172/382, 285/380)}
RUNTIME = float(os.environ.get("GO_RUNTIME", "200"))


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
    await asyncio.sleep(1.0)


async def cdp_shot(page, name):
    try:
        cdp = await page.context.new_cdp_session(page)
        data = await cdp.send("Page.captureScreenshot", {"format": "png", "captureBeyondViewport": False})
        (OUT / f"{name}.png").write_bytes(base64.b64decode(data["data"]))
    except Exception as e:
        print(f"  shot {name} failed: {str(e)[:60]}", file=sys.stderr)


async def main():
    OUT.mkdir(exist_ok=True)
    serve(str(DOCS), 8414)
    time.sleep(1)
    pmlog = open(OUT / "pmdiag.log", "w")
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False, args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 900, "height": 700})

        def on_console(m):
            t = m.text
            if "PMDIAG" in t:
                pmlog.write(t + "\n"); pmlog.flush()
        page.on("console", on_console)

        await page.goto("http://127.0.0.1:8414/demo.html?test=flasharchive/Tetris",
                        wait_until="load", timeout=20000)
        await page.wait_for_selector("#btn-run", timeout=20000)
        for _ in range(40):
            if await page.get_attribute("#btn-run", "disabled") is None:
                break
            await asyncio.sleep(0.25)
        await page.click("#btn-run")
        await asyncio.sleep(3.0)
        box = await page.locator("#canvas").bounding_box()
        def at(frac):
            return box["x"] + box["width"]*frac[0], box["y"] + box["height"]*frac[1]
        ax, ay = at(FRAC["play"]); await held_click(page, ax, ay)
        ax, ay = at(FRAC["up"]);   await held_click(page, ax, ay)
        ax, ay = at(FRAC["ok"]);   await held_click(page, ax, ay)
        print(f"In game; running {RUNTIME}s to top-out...", file=sys.stderr)
        t0 = time.time(); i = 0
        while time.time() - t0 < RUNTIME:
            await cdp_shot(page, f"go_{i:02d}")
            i += 1
            await asyncio.sleep(8.0)
        await cdp_shot(page, "go_final")
        await page.close(); await browser.close()
    pmlog.close()
    print(f"Done. pmdiag.log + go_*.png in {OUT}", file=sys.stderr)


if __name__ == "__main__":
    asyncio.run(main())
