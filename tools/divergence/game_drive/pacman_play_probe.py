#!/usr/bin/env python3
"""pacman_play_probe.py — run the Pacman demo, find + click the "Play Game"
button (DefineButton2 chid 94), then poll the ROOT display list over time to
detect the "play button bounce" (game screen → snaps back to title/attract).

Stage is 360x420. We log the charId signature of the root display list each
poll so we can see frame transitions (menu has button chid 94; game has the
maze/pacman/ghost sprites).

Usage: DISPLAY=:0 .../python3 pacman_play_probe.py
"""
import asyncio, http.server, socketserver, threading, time, os, sys, json, base64
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
DOCS = ROOT / "docs2"
OUT = HERE / "compare_out"
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"]
PORT = int(os.environ.get("SMOKE_PORT", "8421"))
STAGE_W, STAGE_H = 360.0, 420.0


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def dump_dl(page):
    raw = await page.evaluate(
        """() => { try {
            if (!window.Module || !Module.cwrap) return JSON.stringify({_err:'no Module'});
            if (!window.__dl_get) window.__dl_get = Module.cwrap('getDisplayListJSON','string',[]);
            return window.__dl_get();
        } catch(e){ return JSON.stringify({_err: String(e)}); } }"""
    )
    try:
        return json.loads(raw)
    except Exception:
        return {"_err": raw[:120]}


async def root_frame(page):
    return await page.evaluate(
        """() => { try {
            if (!window.__rf) window.__rf = Module.cwrap('dbgRootFrame','number',[]);
            if (!window.__ip) window.__ip = Module.cwrap('dbgIsPlaying','number',[]);
            return window.__rf() + ':' + window.__ip();
        } catch(e){ return 'err'; } }"""
    )


def sig(dl):
    """compact charId:depth signature of the root display list"""
    items = dl.get("displayList", [])
    return ",".join(f"{o['charId']}@{o['depth']}" for o in items)


async def snap(page, path):
    cdp = await page.context.new_cdp_session(page)
    data = await cdp.send("Page.captureScreenshot", {"format": "png", "captureBeyondViewport": False})
    Path(path).write_bytes(base64.b64decode(data["data"]))


async def main():
    OUT.mkdir(exist_ok=True)
    serve(str(DOCS), PORT)
    time.sleep(1)
    lines = []
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False, args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 700, "height": 760})
        page.on("console", lambda m: lines.append("CON " + m.text) if ("PACDBG" in m.text or "FRAME" in m.text) else None)
        page.on("pageerror", lambda e: lines.append("PAGEERROR " + str(e)[:200]))
        await page.goto(f"http://127.0.0.1:{PORT}/demo.html?test=flasharchive/Pacman",
                        wait_until="load", timeout=20000)
        await page.wait_for_selector("#btn-run", timeout=20000)
        for _ in range(40):
            if await page.get_attribute("#btn-run", "disabled") is None:
                break
            await asyncio.sleep(0.25)
        await page.click("#btn-run")
        await asyncio.sleep(2.5)
        # throttle frame rate so the present queue does not saturate on WSL2 SwiftShader
        await page.evaluate("() => window.Module && Module.ccall('dbgSetFrameCapMs', null, ['number'], [60])")
        await asyncio.sleep(0.5)

        box = await page.locator("#canvas").bounding_box()
        print(f"=== canvas box {box} ===", file=sys.stderr)

        # --- baseline: poll the menu/title for ~2s ---
        print("=== BASELINE (menu/title) ===")
        for i in range(5):
            dl = await dump_dl(page)
            rf = await root_frame(page)
            print(f"[base {i}] rootframe={rf} | {sig(dl)}")
            await asyncio.sleep(0.3)

        # find the Play button (chid 30) on the root display list
        dl = await dump_dl(page)
        btn = next((o for o in dl.get("displayList", []) if o["charId"] == 30), None)
        if btn:
            ax = box["x"] + box["width"] * ((btn["x"] + 25) / STAGE_W)
            ay = box["y"] + box["height"] * ((btn["y"] + 8) / STAGE_H)
            print(f"=== Play button chid30 at stage ({btn['x']:.1f},{btn['y']:.1f}) -> px ({ax:.0f},{ay:.0f}) ===")
        else:
            ax = box["x"] + box["width"] * 0.5
            ay = box["y"] + box["height"] * 0.62
            print(f"=== chid30 NOT on root DL; fallback click px ({ax:.0f},{ay:.0f}) ===")
        await snap(page, OUT / "pac_before_click.png")

        # click Play
        await page.mouse.move(ax, ay); await asyncio.sleep(0.3)
        await page.mouse.down(); await asyncio.sleep(0.25); await page.mouse.up()
        print("=== CLICKED Play; tracing playhead (frame:isplaying) ===")

        # --- poll the playhead fast for ~12s; print only on change ---
        last = None
        t0 = time.time()
        for i in range(900):
            rf = await root_frame(page)
            if rf != last:
                print(f"[+{time.time()-t0:5.2f}s] frame:playing = {rf}")
                last = rf
            await asyncio.sleep(0.03)

        await snap(page, OUT / "pac_after_click.png")
        await page.close(); await browser.close()

    print(f"=== {len(lines)} console/error lines (last 30) ===")
    for l in lines[-30:]:
        print(l)


if __name__ == "__main__":
    asyncio.run(main())
