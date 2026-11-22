#!/usr/bin/env python3
"""live_recompiler_run.py — drive the in-browser recompiler page (default: the
LIVE Pages deploy) end to end: upload a SWF, wait for recompile, click
"Build & run in browser (WebGPU)", and print the run's trace lines.
  DISPLAY=:0 python3 tools/browser-test/live_recompiler_run.py SWF [PREFIX] [URL] [WAIT_S]
PREFIX filters "[host] ..." console lines (default: all host lines).
Used to verify browser-only runtime fixes after a Pages deploy (2026-11-22,
N 'play game': SWF = ruffle-tests/tests/swfs/regression/avm1_closure_base_clip_root_frame/test.swf, PREFIX "BC:").
WSL Chrome is SwiftShader: functional checks only, never perf.
"""
import asyncio, os, sys, time
from playwright.async_api import async_playwright

SWF = os.path.abspath(sys.argv[1])
PREFIX = sys.argv[2] if len(sys.argv) > 2 else ""
URL = sys.argv[3] if len(sys.argv) > 3 else "https://peerinfinity.github.io/SWFRecomp-CC/recompiler/"
WAIT = float(sys.argv[4]) if len(sys.argv) > 4 else 600
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox",
        "--enable-features=Vulkan,WebAssemblyJSPromiseIntegration", "--use-vulkan=swiftshader"]


async def main():
    host, errs = [], []
    async with async_playwright() as p:
        br = await p.chromium.launch(executable_path=CHROME, headless=False, args=ARGS)
        pg = await br.new_page()
        t0 = time.time()
        def on_console(m):
            if m.text.startswith("[host] "):
                host.append(m.text[7:])
            elif m.type == "error":
                errs.append(m.text[:200])
        pg.on("console", on_console)
        pg.on("pageerror", lambda e: errs.append("PAGEERROR " + str(e)[:200]))
        await pg.goto(URL, wait_until="load", timeout=60000)
        await pg.set_input_files("#fileInput", SWF)
        await pg.wait_for_selector("#runBtn:not([disabled])", state="visible", timeout=120000)
        print(f"[{time.time()-t0:6.1f}s] recompiled; clicking Build & run", flush=True)
        await pg.click("#runBtn")
        deadline = time.time() + WAIT
        while time.time() < deadline:
            await asyncio.sleep(2)
            hits = [l for l in host if PREFIX in l] if PREFIX else host
            if PREFIX and any("done" in l for l in hits):
                break
        print(f"[{time.time()-t0:6.1f}s] runStatus: " + (await pg.evaluate("document.getElementById('runStatus').innerText"))[:200])
        await br.close()
    print("=== trace ===")
    for l in ([l for l in host if PREFIX in l] if PREFIX else host):
        print(l)
    if errs:
        print("=== errors ===")
        for e in errs[:10]:
            print(e)

asyncio.run(main())
