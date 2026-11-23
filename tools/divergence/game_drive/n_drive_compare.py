#!/usr/bin/env python3
"""n_drive_compare.py - run the NDrive-injected N (deterministic input script,
see ruffle-tests/tests/swfs/_swfbridge/livetest/n_drive/) in the browser, on
our WASM build (docs2 demo.html?test=flasharchive/N_drive) or on Ruffle web
(docs2/examples/flasharchive/N_drive_ruffle/), capture the probe's ND/NF trace
lines and a canvas screenshot shortly after each game event.
  DISPLAY=:0 python3 n_drive_compare.py ours|ruffle [seconds]
Outputs compare_out/ndrive_<which>_trace.txt and ndrive_<which>_<n>_<event>.png.
Functional only: WSL Chrome is SwiftShader - never use it for perf."""
import asyncio, http.server, socketserver, threading, time, os, sys, re
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
DOCS = HERE.parents[2] / "docs2"
OUT = HERE / "compare_out"
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox",
               "--enable-features=Vulkan", "--use-vulkan=swiftshader"]
PORT = int(os.environ.get("SMOKE_PORT", "8418"))
# Shots are taken when the probe prints "ND shot <label>": it freezes N at exact
# game ticks (and holds each menu phase), so both players are shot in the same state.


def serve(directory, port):
    handler = lambda *a, **k: http.server.SimpleHTTPRequestHandler(*a, directory=directory, **k)
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()


async def main(which, secs):
    OUT.mkdir(exist_ok=True)
    serve(str(DOCS), PORT); time.sleep(0.5)
    lines, pending = [], []
    async with async_playwright() as p:
        br = await p.chromium.launch(executable_path=CHROME, headless=False, args=CHROME_ARGS)
        pg = await br.new_page(viewport={"width": 1000, "height": 800})
        t0 = time.time()

        def on_console(m):
            txt = m.text
            mm = re.search(r"(N[DF] .*)", txt)
            if not mm:
                if "rror" in txt: lines.append(f"[{time.time()-t0:6.2f}] {txt[:200]}")
                return
            s = mm.group(1).split(" color:")[0].rstrip()
            lines.append(s)
            if s.startswith("ND shot "):
                pending.append([time.time() + 0.05, s.split()[2], len(pending), False])
        pg.on("console", on_console)
        pg.on("pageerror", lambda e: lines.append("PAGEERROR " + str(e)[:200]))
        if which == "ours":
            await pg.goto(f"http://127.0.0.1:{PORT}/demo.html?test=flasharchive/N_drive", wait_until="load")
            await pg.wait_for_selector("#btn-run:not([disabled])", timeout=60000)
            await pg.click("#btn-run")
            canvas = pg.locator("#canvas")
        else:
            await pg.goto(f"http://127.0.0.1:{PORT}/examples/flasharchive/N_drive_ruffle/index.html", wait_until="load")
            canvas = pg.locator("#c")
        end = time.time() + secs
        while time.time() < end:
            now = time.time()
            for q in pending:
                if not q[3] and now >= q[0]:
                    q[3] = True
                    await canvas.screenshot(path=str(OUT / f"ndrive_{which}_{q[1]}.png"))
                    lines.append(f"# shot {q[1]} at {now-t0:.2f}s")
            if any(l.startswith("ND shot a2t60") for l in lines) and all(q[3] for q in pending):
                break
            await asyncio.sleep(0.05)
        await br.close()
    (OUT / f"ndrive_{which}_trace.txt").write_text("\n".join(lines) + "\n")
    for l in lines:
        if not l.startswith("NF"): print(l)
    print("NF lines:", sum(1 for l in lines if l.startswith("NF")))


if __name__ == "__main__":
    asyncio.run(main(sys.argv[1] if len(sys.argv) > 1 else "ours", float(sys.argv[2]) if len(sys.argv) > 2 else 240))
