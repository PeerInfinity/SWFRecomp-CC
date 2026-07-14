#!/usr/bin/env python3
# seedling_cdp_profile_win.py — real-GPU Windows-Chrome CPU *self-time* profile of
# our Seedling tick (or Ruffle's), driven from WSL via WSL->Windows interop.
# Sibling of seedling_perf_win.py: same launch/real-GPU-adapter/Run-SWF flow, but
# instead of reading the __swfPerf HUD it attaches a CDP Profiler sampling session,
# captures for <capture_s>, and aggregates self-time by function. Symbolicated
# names require the WASM to be built with EMCC_CFLAGS=--profiling-funcs (adds the
# wasm Names section) — otherwise wasm frames show as "wasm-function[NNN]".
#
# HOW TO RUN FROM WSL (see WINDOWS_PLAYWRIGHT_FROM_WSL.md):
#   # 1. serve docs2 in WSL:   (cd docs2 && python3 -m http.server 8010)
#   # 2. copy to a Windows path (interop rule) and run with python.exe:
#   cp tools/divergence/perf/seedling_cdp_profile_win.py /mnt/c/playwright/cdp.py
#   python.exe "$(wslpath -w /mnt/c/playwright/cdp.py)" ours \
#     "http://localhost:8010/demo.html?test=avm2/seedling&perfhud=1" 20 \
#     "C:\playwright\seedling_profile.json"
# Then read the JSON back from WSL at /mnt/c/playwright/seedling_profile.json.
# Use python.exe (Windows, has Playwright), NOT python3 (Linux). Interval 200us.
#
# Usage: cdp.py <ours|ruffle> <url> <capture_s> [out_json_windows_path]
import sys, time, json, collections
from playwright.sync_api import sync_playwright

MODE    = sys.argv[1] if len(sys.argv) > 1 else "ours"
URL     = sys.argv[2] if len(sys.argv) > 2 else "http://localhost:8010/demo.html?test=avm2/seedling&perfhud=1"
CAPTURE = float(sys.argv[3]) if len(sys.argv) > 3 else 20.0
OUT     = sys.argv[4] if len(sys.argv) > 4 else None
SETTLE  = 8.0
INTERVAL_US = 200

FLAGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist"]


def aggregate(profile):
    nodes = {n["id"]: n for n in profile["nodes"]}
    self_hits = collections.Counter()
    for sid in profile.get("samples", []):
        self_hits[sid] += 1
    total = sum(self_hits.values()) or 1
    by_fn = collections.Counter()
    by_mod = collections.Counter()
    for nid, hits in self_hits.items():
        cf = nodes[nid]["callFrame"]
        name = cf.get("functionName") or "(anonymous)"
        url = cf.get("url") or ""
        tag = url.split("/")[-1] if url else ""
        key = f"{name}  [{tag}]" if tag else name
        by_fn[key] += hits
        by_mod[tag or "(native/idle)"] += hits
    return by_fn, by_mod, total


with sync_playwright() as p:
    b = p.chromium.launch(headless=False, args=FLAGS)
    pg = b.new_page(viewport={"width": 900, "height": 700})
    errs = []
    pg.on("pageerror", lambda e: errs.append("PAGEERROR: " + str(e)))
    try:
        pg.goto(URL, wait_until="domcontentloaded", timeout=60000)
    except Exception as e:
        print("GOTO_FAIL:", e); b.close(); sys.exit(2)
    adapter = pg.evaluate("""async()=>{ if(!navigator.gpu) return 'NO navigator.gpu';
        try{ const a=await navigator.gpu.requestAdapter(); if(!a) return 'NO adapter';
        let info={}; try{ info=a.info|| (a.requestAdapterInfo? await a.requestAdapterInfo():{});}catch(e){}
        return (info.vendor||'?')+' / '+(info.architecture||info.description||info.device||'?'); }
        catch(e){ return 'ERR '+e; } }""")
    print("WebGPU adapter:", adapter)
    if MODE == "ours":
        try:
            pg.wait_for_selector("#btn-run:not([disabled])", timeout=60000)
            pg.click("#btn-run")
            print("clicked Run SWF")
        except Exception as e:
            print("RUN_CLICK_FAIL:", e)
    pg.bring_to_front()
    # settle to steady state before sampling
    t0 = time.time()
    while time.time() - t0 < SETTLE:
        pg.wait_for_timeout(250)
    client = pg.context.new_cdp_session(pg)
    client.send("Profiler.enable")
    client.send("Profiler.setSamplingInterval", {"interval": INTERVAL_US})
    client.send("Profiler.start")
    t0 = time.time()
    while time.time() - t0 < CAPTURE:
        pg.evaluate("() => 1")          # keep the tab hot / RAF unthrottled
        pg.wait_for_timeout(200)
    res = client.send("Profiler.stop")
    by_fn, by_mod, total = aggregate(res["profile"])
    print(f"\n=== {MODE.upper()} Seedling — CPU self-time by FUNCTION (top 35 of {total} samples @ {INTERVAL_US}us) ===")
    for name, hits in by_fn.most_common(35):
        print(f"  {100*hits/total:5.1f}%  ({hits:5d})  {name}")
    print(f"\n=== self-time by MODULE ===")
    for name, hits in by_mod.most_common(20):
        print(f"  {100*hits/total:5.1f}%  ({hits:5d})  {name}")
    if errs:
        print("\nERRORS:", errs[:5])
    if OUT:
        with open(OUT, "w") as f:
            json.dump(res["profile"], f)
        print("\nwrote raw profile ->", OUT)
    b.close()
