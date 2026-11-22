#!/usr/bin/env python3
"""n_click_probe.py — N "play game" click probe (browser-WASM, WSL headed Chrome).
Loads demo.html?test=<test> (default flasharchive/N_click = N with the
ruffle-tests/.../livetest/n_click/NClick.as probe injected), waits for the main
menu, then performs ACTIONS and prints the probe's "NC ..." console lines.
  DISPLAY=:0 python3 n_click_probe.py [test] [actions]
actions: ';'-joined  "click@x,y" (stage px; mapped through the canvas box),
"key@KeyN", "hold@ArrowRight,sec", "wait@sec". Default: click on "play game" (690,142).
Functional only: WSL Chrome is SwiftShader — never use it for perf.
"""
import asyncio, http.server, socketserver, threading, time, os, sys, base64
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
DOCS = HERE.parents[2] / "docs2"
OUT = HERE / "compare_out"
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox",
               "--enable-features=Vulkan", "--use-vulkan=swiftshader"]
PORT = int(os.environ.get("SMOKE_PORT", "8417"))
STAGE_W, STAGE_H = 792.0, 600.0


def serve(directory, port):
    handler = lambda *a, **k: http.server.SimpleHTTPRequestHandler(*a, directory=directory, **k)
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()


async def main(test, actions):
    OUT.mkdir(exist_ok=True)
    serve(str(DOCS), PORT); time.sleep(0.5)
    lines = []
    async with async_playwright() as p:
        br = await p.chromium.launch(executable_path=CHROME, headless=False, args=CHROME_ARGS)
        pg = await br.new_page(viewport={"width": 1000, "height": 800})
        t0 = time.time()
        pg.on("console", lambda m: lines.append(f"[{time.time()-t0:6.2f}] {m.text}")
              if ("NC" in m.text or "rror" in m.text) and "NCDBG gotoStop frame_num=1 " not in m.text else None)
        pg.on("pageerror", lambda e: lines.append("PAGEERROR " + str(e)[:200]))
        await pg.goto(f"http://127.0.0.1:{PORT}/demo.html?test={test}", wait_until="load", timeout=30000)
        await pg.wait_for_selector("#btn-run:not([disabled])", timeout=60000)
        await pg.click("#btn-run")
        await asyncio.sleep(6.0)
        box = await pg.locator("#canvas").bounding_box()
        lines.append(f"--- canvas box {box}")
        for i, a in enumerate(actions):
            kind, arg = a.split("@", 1)
            lines.append(f"[{time.time()-t0:6.2f}] --- {a}")
            if kind == "click":
                x, y = (float(v) for v in arg.split(","))
                ax = box["x"] + box["width"] * x / STAGE_W
                ay = box["y"] + box["height"] * y / STAGE_H
                await pg.mouse.move(ax - 20, ay, steps=4); await asyncio.sleep(0.3)
                await pg.mouse.move(ax, ay, steps=4); await asyncio.sleep(0.3)
                await pg.mouse.down(); await asyncio.sleep(0.2); await pg.mouse.up()
                await asyncio.sleep(1.5)
            elif kind == "key":
                await pg.keyboard.down(arg); await asyncio.sleep(0.15); await pg.keyboard.up(arg)
                await asyncio.sleep(1.5)
            elif kind == "hold":
                k, sec = arg.split(",")
                await pg.keyboard.down(k); await asyncio.sleep(float(sec)); await pg.keyboard.up(k)
                await asyncio.sleep(0.5)
            elif kind == "wait":
                await asyncio.sleep(float(arg))
            data = await (await pg.context.new_cdp_session(pg)).send("Page.captureScreenshot", {"format": "png"})
            (OUT / f"n_click_{i}.png").write_bytes(base64.b64decode(data["data"]))
        await br.close()
    for l in lines:
        print(l)


if __name__ == "__main__":
    test = sys.argv[1] if len(sys.argv) > 1 else "flasharchive/N_click"
    acts = sys.argv[2].split(";") if len(sys.argv) > 2 else ["click@690,142"]
    asyncio.run(main(test, acts))
