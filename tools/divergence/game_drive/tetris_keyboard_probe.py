#!/usr/bin/env python3
"""tetris_keyboard_probe.py — quick check: do keyboard events reach the WASM
runtime? Loads the game, clicks the canvas (DOM focus), presses an arrow + types,
and captures PMDIAG KEYDOWN/KEYPRESS console.
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
    h = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), h)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def main():
    OUT.mkdir(exist_ok=True)
    serve(str(DOCS), 8414)
    time.sleep(1)
    pmlog = open(OUT / "pmdiag.log", "w")
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False, args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 900, "height": 700})
        page.on("console", lambda m: (pmlog.write(m.text + "\n"), pmlog.flush()) if "PMDIAG" in m.text else None)
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
        # click canvas center to focus it
        await page.mouse.click(box["x"]+box["width"]*0.5, box["y"]+box["height"]*0.5)
        await asyncio.sleep(0.4)
        await page.evaluate("var c=document.getElementById('canvas'); if(c)c.focus();")
        await asyncio.sleep(0.3)
        print("pressing keys...", file=sys.stderr)
        await page.keyboard.press("ArrowLeft"); await asyncio.sleep(0.2)
        await page.keyboard.press("ArrowRight"); await asyncio.sleep(0.2)
        await page.keyboard.type("AbC"); await asyncio.sleep(0.3)
        # also try dispatching directly on the canvas element
        await page.evaluate("""() => {
            const c = document.getElementById('canvas'); if(!c) return;
            c.focus();
            c.dispatchEvent(new KeyboardEvent('keydown',{key:'Z',keyCode:90,which:90,charCode:0,bubbles:true}));
            c.dispatchEvent(new KeyboardEvent('keypress',{key:'Z',keyCode:90,which:90,charCode:90,bubbles:true}));
        }""")
        await asyncio.sleep(0.5)
        await page.close(); await browser.close()
    pmlog.close()
    print(f"Done. pmdiag.log in {OUT}", file=sys.stderr)


if __name__ == "__main__":
    asyncio.run(main())
