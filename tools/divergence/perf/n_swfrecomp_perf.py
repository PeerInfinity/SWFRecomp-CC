#!/usr/bin/env python3
"""Measure SWFRecomp's per-frame WASM CPU on N via the in-build __swfPerf HUD,
using the same continuous-poll method as the Ruffle probe for a fair comparison.

Usage: python3 n_swfrecomp_perf.py [settle_s] [capture_s]
"""
import asyncio, http.server, socketserver, threading, os, sys, time
from pathlib import Path
from playwright.async_api import async_playwright

DOCS = Path("/home/robert/CC/SWFRecomp-CC/docs2")
PORT = 8546
SETTLE = float(sys.argv[1]) if len(sys.argv) > 1 else 8.0
CAPTURE = float(sys.argv[2]) if len(sys.argv) > 2 else 15.0
STEP = 0.5


def serve(d, p):
    os.chdir(d)
    socketserver.TCPServer.allow_reuse_address = True
    socketserver.TCPServer(("127.0.0.1", p), http.server.SimpleHTTPRequestHandler).serve_forever()


def pct(a, q):
    return sorted(a)[min(len(a) - 1, int(len(a) * q))] if a else 0.0


def rep(name, a):
    if not a:
        print(f"  {name}: (no samples)"); return
    n = len(a)
    print(f"  {name}: n={n} mean={sum(a)/n:6.2f} median={pct(a,0.5):6.2f} "
          f"p90={pct(a,0.90):6.2f} p95={pct(a,0.95):6.2f} max={max(a):6.2f}")


async def poll_active(pg, seconds):
    t = 0.0; last = 0
    while t < seconds:
        last = await pg.evaluate("() => (globalThis.__swfPerf ? globalThis.__swfPerf.cpu.length : 0)")
        await asyncio.sleep(STEP); t += STEP
    return last


async def main():
    threading.Thread(target=serve, args=(str(DOCS), PORT), daemon=True).start()
    time.sleep(1)
    async with async_playwright() as p:
        b = await p.chromium.launch(
            executable_path="/usr/bin/google-chrome", headless=False,
            args=["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"])
        pg = await b.new_page(viewport={"width": 900, "height": 700})
        await pg.goto(f"http://127.0.0.1:{PORT}/demo.html?test=flasharchive/N&perfhud=1",
                      wait_until="load", timeout=30000)
        await pg.bring_to_front()
        await pg.wait_for_selector("#btn-run", timeout=20000)
        for _ in range(40):
            if await pg.get_attribute("#btn-run", "disabled") is None:
                break
            await asyncio.sleep(0.25)
        await pg.click("#btn-run")
        print(f"settling {SETTLE}s ...")
        start_idx = await poll_active(pg, SETTLE)
        print(f"steady-state from index {start_idx}; capturing {CAPTURE}s ...")
        end_idx = await poll_active(pg, CAPTURE)
        print(f"captured {end_idx - start_idx} frames (index {start_idx}->{end_idx})")
        data = await pg.evaluate(
            f"() => {{const S=globalThis.__swfPerf; return S?{{cpu:S.cpu.slice({start_idx}), "
            f"iv:S.iv.slice({start_idx}), frames:S.frames}}:null;}}")
        await pg.close(); await b.close()
    if not data:
        print("!! __swfPerf missing — HUD not enabled in this build."); return
    cpu = data["cpu"]
    eff_fps = len(cpu) / CAPTURE if CAPTURE else 0
    print(f"\n=== SWFRecomp N per-frame WASM CPU (SwiftShader; ~{eff_fps:.1f} eff fps) ===")
    rep("frame CPU (total) ms", cpu)
    rep("interval          ms", data["iv"])

asyncio.run(main())
