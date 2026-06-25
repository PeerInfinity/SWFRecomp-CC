#!/usr/bin/env python3
"""pacman_gameplay_probe.py — start the Pacman game (click Play, wait out the
Ready countdown), then poll the game's logic vars (_root.pacX/pacY/pacDir/...)
vs Pacman's RENDERED position (root display-list depth 88) to localize the
"pacman doesn't move" bug: does the logic advance while the render stays put?

Also dumps the Ghost container (depth 86) children. Optionally presses arrow
keys to test keyboard input.

Usage: DISPLAY=:0 .../python3 pacman_gameplay_probe.py [keys]
"""
import asyncio, http.server, socketserver, threading, time, os, sys, json
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
DOCS = ROOT / "docs2"
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"]
PORT = int(os.environ.get("SMOKE_PORT", "8423"))
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


async def children(page, depth):
    raw = await page.evaluate(
        f"""() => {{ try {{
            if (!window.__sc) window.__sc = Module.cwrap('getSpriteChildrenJSON','string',['number']);
            return window.__sc({depth});
        }} catch(e){{ return '{{}}'; }} }}""")
    try: return json.loads(raw).get("children", [])
    except Exception: return []


async def rvar(page, name):
    return await page.evaluate(
        f"""() => {{ try {{
            if (!window.__rv) window.__rv = Module.cwrap('dbgRootVarNum','number',['string']);
            return window.__rv("{name}");
        }} catch(e){{ return 'err'; }} }}""")


def depth_xy(items, d):
    for o in items:
        if o["depth"] == d:
            return (round(o["x"], 1), round(o["y"], 1), o["charId"])
    return None


async def main(keys):
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

        # click Play (chid 30)
        items = await dl(page)
        btn = next((o for o in items if o["charId"] == 30), None)
        ax = box["x"] + box["width"] * ((btn["x"] + 25) / STAGE_W)
        ay = box["y"] + box["height"] * ((btn["y"] + 8) / STAGE_H)
        await page.mouse.move(ax, ay); await asyncio.sleep(0.2)
        await page.mouse.down(); await asyncio.sleep(0.2); await page.mouse.up()
        print("=== clicked Play; focusing canvas + waiting out Ready countdown ===")
        await page.locator("#canvas").click(position={"x": 5, "y": 5})  # focus for key events
        await asyncio.sleep(7.0)   # Ready countdown

        async def snapshot(tag):
            items = await dl(page)
            pac = depth_xy(items, 88)
            ghc = await children(page, 86)
            vars = {k: await rvar(page, k) for k in
                    ("pacX","pacY","pacDir","nextPacDir","pacPos","pacStep")}
            ci = await page.evaluate("() => { if(!window.__ci) window.__ci=Module.cwrap('dbgClipInfo','string',['string']); return window.__ci('Pacman'); }")
            print(f"[{tag}] pac_render={pac} | findMC(Pacman)={ci} | vars={vars}")
            print(f"        ghosts(d86)={[(c.get('name'),round(c.get('x',0),1),round(c.get('y',0),1)) for c in ghc]}")

        print("=== GAMEPLAY SNAPSHOTS (no input) ===")
        for i in range(6):
            await snapshot(f"t{i}")
            await asyncio.sleep(0.8)

        if keys:
            print(f"=== pressing keys: {keys} ===")
            for k in keys:
                await page.keyboard.press(k)
                await asyncio.sleep(0.15)
                v = await rvar(page, "nextPacDir")
                print(f"  pressed {k} -> nextPacDir={v}")
            await asyncio.sleep(0.5)
            print("=== after keys ===")
            for i in range(5):
                await snapshot(f"k{i}")
                await asyncio.sleep(0.6)

        await page.close(); await browser.close()


if __name__ == "__main__":
    keys = sys.argv[1:] if len(sys.argv) > 1 else ["ArrowUp","ArrowRight","ArrowDown","ArrowLeft"]
    asyncio.run(main(keys))
