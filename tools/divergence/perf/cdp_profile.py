#!/usr/bin/env python3
"""Chrome DevTools-Protocol sampling CPU profile of N under either runtime, with
self-time aggregated by function. Keeps the page active with continuous polls so
the RAF loop never throttles.

Usage:
  python3 cdp_profile.py swfrecomp [capture_s]
  python3 cdp_profile.py ruffle    [capture_s]
"""
import asyncio, http.server, socketserver, threading, os, sys, time, collections
from pathlib import Path
from playwright.async_api import async_playwright

WHICH = sys.argv[1] if len(sys.argv) > 1 else "swfrecomp"
CAPTURE = float(sys.argv[2]) if len(sys.argv) > 2 else 12.0
STEP = 0.4

if WHICH == "ruffle":
    SDIR = Path("/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/92e86a23-5623-4f03-b243-4b1d200b57e1/scratchpad/ruffle_n")
    URL_PATH = "n_ruffle.html"
    READY = "() => !!window.__nLoaded"
    PORT = 8551
else:
    SDIR = Path("/home/robert/CC/SWFRecomp-CC/docs2")
    URL_PATH = "demo.html?test=flasharchive/N&perfhud=1"
    READY = "() => true"
    PORT = 8552


def serve(d, p):
    os.chdir(d)
    socketserver.TCPServer.allow_reuse_address = True
    socketserver.TCPServer(("127.0.0.1", p), http.server.SimpleHTTPRequestHandler).serve_forever()


async def keep_active(pg, seconds):
    t = 0.0
    while t < seconds:
        await pg.evaluate("() => 1")
        await asyncio.sleep(STEP); t += STEP


def aggregate(profile):
    nodes = {n["id"]: n for n in profile["nodes"]}
    self_hits = collections.Counter()
    for sid in profile["samples"]:
        self_hits[sid] += 1
    total = sum(self_hits.values()) or 1
    by_fn = collections.Counter()
    for nid, hits in self_hits.items():
        cf = nodes[nid]["callFrame"]
        name = cf.get("functionName") or "(anonymous)"
        url = cf.get("url") or ""
        tag = url.split("/")[-1] if url else ""
        key = f"{name}  [{tag}]" if tag else name
        by_fn[key] += hits
    return by_fn, total


async def main():
    threading.Thread(target=serve, args=(str(SDIR), PORT), daemon=True).start()
    time.sleep(1)
    async with async_playwright() as p:
        b = await p.chromium.launch(
            executable_path="/usr/bin/google-chrome", headless=False,
            args=["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"])
        pg = await b.new_page(viewport={"width": 900, "height": 700})
        await pg.goto(f"http://127.0.0.1:{PORT}/{URL_PATH}", wait_until="load", timeout=30000)
        await pg.bring_to_front()
        if WHICH == "swfrecomp":
            await pg.wait_for_selector("#btn-run", timeout=20000)
            for _ in range(40):
                if await pg.get_attribute("#btn-run", "disabled") is None:
                    break
                await asyncio.sleep(0.25)
            await pg.click("#btn-run")
        for _ in range(60):
            if await pg.evaluate(READY):
                break
            await asyncio.sleep(0.5)
        await keep_active(pg, 6)  # settle
        client = await pg.context.new_cdp_session(pg)
        await client.send("Profiler.enable")
        await client.send("Profiler.setSamplingInterval", {"interval": 200})  # us
        await client.send("Profiler.start")
        await keep_active(pg, CAPTURE)
        res = await client.send("Profiler.stop")
        await pg.close(); await b.close()
    by_fn, total = aggregate(res["profile"])
    print(f"\n=== {WHICH.upper()} N — CPU self-time by function (top 25 of {total} samples) ===")
    for name, hits in by_fn.most_common(25):
        print(f"  {100*hits/total:5.1f}%  {name}")

asyncio.run(main())
