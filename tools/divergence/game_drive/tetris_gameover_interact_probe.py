#!/usr/bin/env python3
"""tetris_gameover_interact_probe.py — reach Tetris game-over, then exercise the
name-entry screen: hover the OK button (over-state) and type into the name field.

Captures: go_before/go_hover/go_typed.png + PMDIAG console (SETFOCUS/TFINPUT/BTN).
ok_btn is at stage ~(110,252); hover target stage ~(132,262).
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
OKBTN = (132/382, 262/380)   # game-over OK button (stage ~132,262)
WAIT = float(os.environ.get("GO_WAIT", "115"))


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


async def shot(page, name):
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
        def at(frac):
            return box["x"] + box["width"]*frac[0], box["y"] + box["height"]*frac[1]
        ax, ay = at(FRAC["play"]); await held_click(page, ax, ay)
        ax, ay = at(FRAC["up"]);   await held_click(page, ax, ay)
        ax, ay = at(FRAC["ok"]);   await held_click(page, ax, ay)
        # move mouse away from any button while waiting for top-out
        await page.mouse.move(box["x"]+box["width"]*0.5, box["y"]+box["height"]*0.05)
        print(f"In game; waiting {WAIT}s for game-over...", file=sys.stderr)
        await asyncio.sleep(WAIT)
        await shot(page, "go_before")
        # 1) hover the OK button -> over-state
        hx, hy = at(OKBTN)
        print(f"hover ok_btn at canvas ({hx:.0f},{hy:.0f})", file=sys.stderr)
        await page.mouse.move(hx, hy); await asyncio.sleep(0.8)
        await page.mouse.move(hx, hy); await asyncio.sleep(0.8)
        await shot(page, "go_hover")
        # 2) give the canvas DOM focus (click a neutral spot), then type. The AS
        #    Selection.setFocus(name_txt) on game-over picks which field receives it.
        # Do NOT click the canvas — a click clears the AS field focus that
        # Selection.setFocus(name_txt) established. Dispatching keypress directly
        # to the canvas element doesn't need DOM focus and preserves AS focus.
        # (Playwright's keyboard.type also doesn't trigger emscripten's keypress.)
        for cc in (65, 66, 67):  # A B C
            await page.evaluate("""(cc) => {
                const c = document.getElementById('canvas'); if(!c) return;
                c.focus();
                c.dispatchEvent(new KeyboardEvent('keypress',{keyCode:cc,which:cc,charCode:cc,bubbles:true}));
            }""", cc)
            await asyncio.sleep(0.35)
        await asyncio.sleep(0.5)
        await shot(page, "go_typed")
        await page.close(); await browser.close()
    pmlog.close()
    print(f"Done. go_*.png + pmdiag.log in {OUT}", file=sys.stderr)


if __name__ == "__main__":
    asyncio.run(main())
