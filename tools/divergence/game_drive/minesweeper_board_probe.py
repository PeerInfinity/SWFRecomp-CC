#!/usr/bin/env python3
"""minesweeper_board_probe.py — click Start, then dump the root display list
(do the cellX_Y duplicateMovieClip clones exist?) + capture the canvas.
Usage: DISPLAY=:0 .../python3 minesweeper_board_probe.py
"""
import asyncio, http.server, socketserver, threading, time, os, sys, base64, json
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


async def snap(page, path):
    cdp = await page.context.new_cdp_session(page)
    data = await cdp.send("Page.captureScreenshot", {"format": "png", "captureBeyondViewport": False})
    Path(path).write_bytes(base64.b64decode(data["data"]))


async def dump_dl(page):
    raw = await page.evaluate(
        """() => { try {
            if (!window.Module || !Module.cwrap) return JSON.stringify({_err:'no Module'});
            if (!window.__dl_get) window.__dl_get = Module.cwrap('getDisplayListJSON','string',[]);
            return window.__dl_get();
        } catch(e){ return JSON.stringify({_err: String(e)}); } }"""
    )
    return raw


async def main():
    OUT.mkdir(exist_ok=True)
    serve(str(DOCS), PORT)
    time.sleep(1)
    lines = []
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False, args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 900, "height": 700})
        page.on("console", lambda m: lines.append(m.text))
        page.on("pageerror", lambda e: lines.append("PAGEERROR " + str(e)[:300]))
        await page.goto(f"http://127.0.0.1:{PORT}/demo.html?test=flasharchive/Minesweeper",
                        wait_until="load", timeout=20000)
        await page.wait_for_selector("#btn-run", timeout=20000)
        for _ in range(40):
            if await page.get_attribute("#btn-run", "disabled") is None:
                break
            await asyncio.sleep(0.25)
        await page.click("#btn-run")
        await asyncio.sleep(3.0)

        # before-Start display list
        dl_before = await dump_dl(page)
        (OUT / "board_dl_before.json").write_text(dl_before)
        await snap(page, OUT / "board_before.png")

        # click Start at (0.5, 0.896)
        box = await page.locator("#canvas").bounding_box()
        ax = box["x"] + box["width"] * 0.5
        ay = box["y"] + box["height"] * 0.896
        print(f"=== canvas box {box}; Start px=({ax:.0f},{ay:.0f}) ===", file=sys.stderr)
        await page.mouse.move(ax, ay); await asyncio.sleep(0.3)
        await page.mouse.down(); await asyncio.sleep(0.35); await page.mouse.up()
        await asyncio.sleep(3.0)

        dl_after = await dump_dl(page)
        (OUT / "board_dl_after.json").write_text(dl_after)
        await snap(page, OUT / "board_after.png")

        await page.close(); await browser.close()

    # summarize display lists
    for tag, raw in (("BEFORE", dl_before), ("AFTER", dl_after)):
        try:
            obj = json.loads(raw)
        except Exception:
            print(f"{tag}: unparseable ({raw[:120]})")
            continue
        dl = obj.get("displayList") or obj.get("display_list") or obj
        s = json.dumps(obj)
        ncell = s.count('"cell')
        print(f"{tag}: keys={list(obj.keys())[:8]} bytes={len(s)} 'cell' occurrences={ncell}")
    print(f"=== {len(lines)} console lines (last 40) ===")
    for l in lines[-40:]:
        print(l)


if __name__ == "__main__":
    asyncio.run(main())
