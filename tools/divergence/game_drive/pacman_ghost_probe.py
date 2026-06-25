#!/usr/bin/env python3
"""pacman_ghost_probe.py — verify the ghost-house-exit fix. Starts the game
(click Run, click Play chid 30, focus canvas, wait Ready), then polls each game
ghost's AI state via dbgChildState ("1".."4", parent="Ghost") plus root numEyes.

Fix check: ghosts should LEAVE the house — ghY should move out of the 11..15
house band and ghX should change — and numEyes must NOT run unboundedly negative
(the Shape-not-visible else-branch decrementing it every tick was the bug signal).

Usage: DISPLAY=:0 python3 pacman_ghost_probe.py
"""
import asyncio, http.server, socketserver, threading, time, os, json
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
DOCS = ROOT / "docs2"
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"]
PORT = int(os.environ.get("SMOKE_PORT", "8424"))
STAGE_W, STAGE_H = 360.0, 420.0


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def dl(page):
    raw = await page.evaluate(
        """() => { try {
            if (!window.__dl) window.__dl = Module.cwrap('getDisplayListJSON','string',[]);
            return window.__dl();
        } catch(e){ return '{}'; } }""")
    try: return json.loads(raw).get("displayList", [])
    except Exception: return []


async def cstate(page, name):
    return await page.evaluate(
        f"""() => {{ try {{
            if (!window.__cs) window.__cs = Module.cwrap('dbgChildState','string',['string']);
            return window.__cs("{name}");
        }} catch(e){{ return 'err'; }} }}""")


async def rvar(page, name):
    return await page.evaluate(
        f"""() => {{ try {{
            if (!window.__rv) window.__rv = Module.cwrap('dbgRootVarNum','number',['string']);
            return window.__rv("{name}");
        }} catch(e){{ return 'err'; }} }}""")


async def main():
    serve(str(DOCS), PORT)
    time.sleep(1)
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False, args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 700, "height": 760})
        page.on("pageerror", lambda e: print("PAGEERROR " + str(e)[:200]))
        await page.goto(f"http://127.0.0.1:{PORT}/demo.html?test=flasharchive/Pacman",
                        wait_until="load", timeout=20000)
        await page.wait_for_selector("#btn-run", timeout=20000)
        for _ in range(40):
            if await page.get_attribute("#btn-run", "disabled") is None: break
            await asyncio.sleep(0.25)
        await page.click("#btn-run")
        await asyncio.sleep(2.5)
        await page.evaluate("() => Module.ccall('dbgSetFrameCapMs', null, ['number'], [60])")
        box = await page.locator("#canvas").bounding_box()

        items = await dl(page)
        btn = next((o for o in items if o["charId"] == 30), None)
        ax = box["x"] + box["width"] * ((btn["x"] + 25) / STAGE_W)
        ay = box["y"] + box["height"] * ((btn["y"] + 8) / STAGE_H)
        await page.mouse.move(ax, ay); await asyncio.sleep(0.2)
        await page.mouse.down(); await asyncio.sleep(0.2); await page.mouse.up()
        print("=== clicked Play; focus + Ready countdown ===")
        await page.locator("#canvas").click(position={"x": 5, "y": 5})
        await asyncio.sleep(7.0)

        print("=== GHOST STATE OVER TIME ===")
        for i in range(16):
            line = []
            for g in ("1", "2", "3", "4"):
                s = await cstate(page, g)
                line.append(f"{g}:[{s}]")
            ne = await rvar(page, "numEyes")
            print(f"t{i:02d} numEyes={ne}")
            for L in line:
                print("    " + L)
            await asyncio.sleep(0.7)

        await browser.close()


if __name__ == "__main__":
    asyncio.run(main())
