#!/usr/bin/env python3
"""Measure Ruffle's per-frame WASM CPU on N.swf via the `profiling`-build shim
(window.__rufflePerfTick = AVM/sim ms, __rufflePerfRender = cmd-build+GPU ms).

WSL2 headed-Chrome note: Ruffle re-arms requestAnimationFrame only from inside its
own tick, so if the page is ever throttled the RAF chain dies and never recovers.
We therefore keep the page active with CONTINUOUS short-interval CDP polls (never a
single long sleep) for the whole run. Steady state = samples after the settle index.

Usage: python3 n_ruffle_perf.py [settle_s] [capture_s]
"""
import asyncio, http.server, socketserver, threading, os, sys, time
from pathlib import Path
from playwright.async_api import async_playwright

SDIR = Path(__file__).resolve().parent
PORT = 8533
SETTLE = float(sys.argv[1]) if len(sys.argv) > 1 else 8.0
CAPTURE = float(sys.argv[2]) if len(sys.argv) > 2 else 15.0
STEP = 0.5


def serve(d, p):
    os.chdir(d)
    socketserver.TCPServer.allow_reuse_address = True
    socketserver.TCPServer((("127.0.0.1"), p), http.server.SimpleHTTPRequestHandler).serve_forever()


def pct(a, q):
    return sorted(a)[min(len(a) - 1, int(len(a) * q))] if a else 0.0


def rep(name, a):
    if not a:
        print(f"  {name}: (no samples)"); return
    n = len(a)
    print(f"  {name}: n={n} mean={sum(a)/n:6.2f} median={pct(a,0.5):6.2f} "
          f"p90={pct(a,0.90):6.2f} p95={pct(a,0.95):6.2f} max={max(a):6.2f}")


async def poll_active(pg, seconds):
    """Keep the page active by polling tick length every STEP s; return final len."""
    t = 0.0
    last = 0
    while t < seconds:
        last = await pg.evaluate("() => (window.__rufflePerfTick||[]).length")
        await asyncio.sleep(STEP); t += STEP
    return last


async def main():
    threading.Thread(target=serve, args=(str(SDIR), PORT), daemon=True).start()
    time.sleep(1)
    async with async_playwright() as p:
        b = await p.chromium.launch(
            executable_path="/usr/bin/google-chrome", headless=False,
            args=["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"])
        pg = await b.new_page(viewport={"width": 900, "height": 700})
        await pg.goto(f"http://127.0.0.1:{PORT}/n_ruffle.html", wait_until="load", timeout=30000)
        await pg.bring_to_front()
        for _ in range(60):
            if await pg.evaluate("() => !!window.__nLoaded"):
                break
            await asyncio.sleep(0.5)
        print(f"N loaded under Ruffle: {await pg.evaluate('() => !!window.__nLoaded')}")
        print(f"settling {SETTLE}s ...")
        start_idx = await poll_active(pg, SETTLE)
        print(f"steady-state from index {start_idx}; capturing {CAPTURE}s ...")
        end_idx = await poll_active(pg, CAPTURE)
        print(f"captured {end_idx - start_idx} frames (index {start_idx}->{end_idx})")
        data = await pg.evaluate(
            f"() => ({{tick: (window.__rufflePerfTick||[]).slice({start_idx}), "
            f"render: (window.__rufflePerfRender||[]).slice({start_idx}), "
            f"draws: (window.__rufflePerfDraws||[]).slice({start_idx})}})")
        await pg.close(); await b.close()
    tick, render, draws = data["tick"], data["render"], data["draws"]
    total = [t + r for t, r in zip(tick, render)]
    eff_fps = len(tick) / CAPTURE if CAPTURE else 0
    print(f"\n=== Ruffle N per-frame WASM CPU (SwiftShader; ~{eff_fps:.1f} eff fps) ===")
    rep("tick   (AVM/sim)  ms", tick)
    rep("render (cmd+GPU)  ms", render)
    rep("TOTAL  frame      ms", total)
    rep("draw calls (shape)  ", draws)

asyncio.run(main())
