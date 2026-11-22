#!/usr/bin/env python3
# n_cdp_win.py — CDP sampling profile of our N build on REAL-GPU Windows Chrome,
# run via the Windows python.exe from WSL (WINDOWS_PLAYWRIGHT_FROM_WSL.md).
# Prints self-time AND inclusive-time per function (the inclusive view is what
# attributes a pump like ng_advance_attached_clip_playheads, whose cost sits in
# callees). Build the bundle with EMCC_CFLAGS=--profiling-funcs for names.
#
#   cp tools/divergence/perf/n_cdp_win.py /mnt/c/playwright/
#   python.exe "$(wslpath -w /mnt/c/playwright/n_cdp_win.py)" \
#     "http://localhost:8010/demo.html?test=flasharchive/N_after&perfhud=1" 15 30 [focus,fns]
# Usage: n_cdp_win.py <url> <settle_s> <capture_s> [comma list of fns to report inclusive]
import sys, time, collections
from playwright.sync_api import sync_playwright

URL, SETTLE, CAPTURE = sys.argv[1], float(sys.argv[2]), float(sys.argv[3])
FOCUS = sys.argv[4].split(",") if len(sys.argv) > 4 and sys.argv[4] else []

with sync_playwright() as p:
    b = p.chromium.launch(headless=False, args=["--enable-unsafe-webgpu", "--ignore-gpu-blocklist"])
    pg = b.new_page(viewport={"width": 1000, "height": 800})
    pg.goto(URL, wait_until="domcontentloaded", timeout=60000)
    pg.wait_for_selector("#btn-run:not([disabled])", timeout=120000)
    pg.click("#btn-run"); pg.bring_to_front()
    t0 = time.time()
    while time.time() - t0 < SETTLE: pg.wait_for_timeout(200)
    c = pg.context.new_cdp_session(pg)
    c.send("Profiler.enable"); c.send("Profiler.setSamplingInterval", {"interval": 200}); c.send("Profiler.start")
    t0 = time.time()
    while time.time() - t0 < CAPTURE: pg.wait_for_timeout(200)
    prof = c.send("Profiler.stop")["profile"]
    b.close()

nodes = {n["id"]: n for n in prof["nodes"]}
parent = {}
for n in prof["nodes"]:
    for ch in n.get("children", []): parent[ch] = n["id"]
def name(nid):
    cf = nodes[nid]["callFrame"]; return cf.get("functionName") or "(anonymous)"
selfc = collections.Counter(); incl = collections.Counter()
for sid in prof["samples"]:
    selfc[name(sid)] += 1
    seen = set(); x = sid
    while x is not None:
        nm = name(x)
        if nm not in seen: seen.add(nm); incl[nm] += 1
        x = parent.get(x)
total = len(prof["samples"]) or 1
idle = selfc.get("(idle)", 0)
busy = total - idle
print(f"samples={total} idle={100*idle/total:.1f}%  (percentages below are of NON-idle samples, n={busy})")
print("--- self top 30 ---")
for nm, h in selfc.most_common(32):
    if nm == "(idle)": continue
    print(f"  {100*h/busy:5.1f}%  {nm}")
print("--- inclusive top 40 ---")
for nm, h in incl.most_common(45):
    if nm in ("(idle)", "(root)"): continue
    print(f"  {100*h/busy:5.1f}%  {nm}")
for f in FOCUS:
    print(f"FOCUS {f}: incl {100*incl.get(f,0)/busy:.2f}%  self {100*selfc.get(f,0)/busy:.2f}%")
