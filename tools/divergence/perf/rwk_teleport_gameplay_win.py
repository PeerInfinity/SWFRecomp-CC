#!/usr/bin/env python3
# rwk_teleport_gameplay_win.py — drive INJECTED RWK into live gameplay via the
# AP bridge TELEPORT (constructs xplor.PlayState, so no menu click needed — the
# plain build's in-canvas mouse doesn't reach Flixel), then measure real-GPU
# GAMEPLAY frame cost + memory over a soak. This is the GC-cadence gate for the
# 512 MB arena: quadtree churns every frame in PlayState, so a smaller-arena
# watermark that stalled would show as >250ms frames or an OOM here.
#
# Usage: rwk_teleport_gameplay.py <game.html url> <soak_s> <out_prefix> <config.json>
import sys, time, json
from playwright.sync_api import sync_playwright

URL   = sys.argv[1]
SOAK  = int(sys.argv[2]) if len(sys.argv) > 2 else 60
OUT   = sys.argv[3] if len(sys.argv) > 3 else "C:\\playwright\\rwk_tp"
CFG   = sys.argv[4] if len(sys.argv) > 4 else None

FLAGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist"]
MB = 1024 * 1024
cfg = None
if CFG:
    with open(CFG) as f:
        cfg = json.load(f)

HEAP_JS = "() => (window.Module && Module.HEAPU8) ? Module.HEAPU8.length : -1"
# read the whole cpu ring; caller accumulates across polls to catch every stall
RING_JS = "() => { const S=window.__swfPerf; return S && S.cpu ? {frames:S.frames, cpu:Array.from(S.cpu)} : null; }"

res = {"url": URL, "soak_s": SOAK}
with sync_playwright() as p:
    b = p.chromium.launch(headless=False, args=FLAGS)
    pg = b.new_page(viewport={"width": 1100, "height": 800})
    errs = []
    pg.on("pageerror", lambda e: errs.append("PAGEERROR: " + str(e)))
    pg.on("console", lambda m: errs.append("CONSOLE:" + m.text) if m.type == "error" else None)
    pg.goto(URL, wait_until="domcontentloaded", timeout=60000)
    res["adapter"] = pg.evaluate("""async()=>{ if(!navigator.gpu) return 'NO navigator.gpu';
        try{ const a=await navigator.gpu.requestAdapter(); if(!a) return 'NO adapter';
        let info={}; try{ info=a.info||(a.requestAdapterInfo?await a.requestAdapterInfo():{});}catch(e){}
        return (info.vendor||'?')+' / '+(info.architecture||info.description||info.device||'?'); }
        catch(e){ return 'ERR '+e; } }""")
    print("WebGPU adapter:", res["adapter"])
    res["heap_before_start_mb"] = round(pg.evaluate(HEAP_JS) / MB, 1)

    pg.wait_for_selector("#btn-start:not([disabled])", timeout=60000)
    pg.click("#btn-start")
    print("clicked Start; waiting for bridge…")
    pg.wait_for_function("() => !!(window.__swfBridge && window.__runtimeReady)", timeout=60000)
    pg.wait_for_timeout(1500)
    res["heap_after_start_mb"] = round(pg.evaluate(HEAP_JS) / MB, 1)
    print("HEAPU8 before/after Start:", res["heap_before_start_mb"], "->", res["heap_after_start_mb"], "MB")

    # Bridge handshake: wireCheck + configure(robotkitty.json) — configure runs
    # resolveClasses (getDefinitionByName xplor.PlayState), REQUIRED before the
    # teleport's new_instance can resolve the class.
    pg.wait_for_function("() => { const g=window.__swfBridge&&window.__swfBridge.game;"
                         " return !!(g&&g.wireCheck&&g.configure&&g.readState); }", timeout=60000)
    print("wireCheck:", pg.evaluate("() => window.__swfBridge.game.wireCheck()"))
    print("configure:", pg.evaluate("(c) => window.__swfBridge.game.configure(JSON.stringify(c))", cfg))
    pg.wait_for_timeout(2000)

    # TELEPORT: pre_invocations (strip LogoState bitmap, construct xplor.PlayState
    # into FlxG.state) + the player x/y path writes. Starts live gameplay.
    ok = pg.evaluate("""(a) => { try {
        const tp=a.cfg.teleport||{}; const items=(tp.pre_invocations||[]).slice();
        for (const wr of (tp.writes||[])) items.push({path:wr.path,
            value: wr.value==='$x'?a.x : (wr.value==='$y'?a.y : wr.value)});
        window.__swfBridge.queueItems(items); return 'queued '+items.length;
    } catch(e){ return 'ERR '+e; } }""", {"cfg": cfg, "x": 100, "y": 100})
    print("teleport:", ok)
    pg.wait_for_timeout(3000)  # PlayState.create (arrayToCSV + level) runs here

    # Soak gameplay, accumulating every distinct frame's cost to catch all stalls.
    seen = {}  # frame_index -> cpu ms  (ring is 120 slots; poll < ring capacity)
    heaps = []
    t0 = time.time()
    while time.time() - t0 < SOAK:
        pg.wait_for_timeout(1000)
        heaps.append(round(pg.evaluate(HEAP_JS) / MB, 1))
        r = pg.evaluate(RING_JS)
        if r and r.get("cpu"):
            base = r["frames"] - len(r["cpu"])
            for i, v in enumerate(r["cpu"]):
                seen[base + i] = v
    vals = sorted(v for v in seen.values() if v is not None and v > 0)
    n = len(vals)
    res["gameplay_frames_sampled"] = n
    res["mean_ms"]  = round(sum(vals)/n, 1) if n else 0
    res["p50_ms"]   = round(vals[int(n*0.5)], 1) if n else 0
    res["p95_ms"]   = round(vals[int(n*0.95)], 1) if n else 0
    res["max_ms"]   = round(vals[-1], 1) if n else 0
    res["stalls_gt250ms"] = sum(1 for v in vals if v > 250)
    res["stalls_gt33ms"]  = sum(1 for v in vals if v > 33)
    res["fps_mean"] = round(1000.0/res["mean_ms"], 1) if res["mean_ms"] else 0
    res["heap_soak_min_mb"] = min(heaps) if heaps else None
    res["heap_soak_max_mb"] = max(heaps) if heaps else None
    res["errors"] = errs[:8]
    pg.screenshot(path=OUT + ".png")
    b.close()

print("HEAP soak min/max:", res["heap_soak_min_mb"], "/", res["heap_soak_max_mb"], "MB")
print("GAMEPLAY frames=%d mean=%.1fms p50=%.1f p95=%.1f max=%.1f fps=%.1f stalls>250ms=%d over33ms=%d" % (
    res["gameplay_frames_sampled"], res["mean_ms"], res["p50_ms"], res["p95_ms"],
    res["max_ms"], res["fps_mean"], res["stalls_gt250ms"], res["stalls_gt33ms"]))
print("ERRORS:", res["errors"][:4])
open(OUT + ".json", "w").write(json.dumps(res, indent=1))
print("saved", OUT + ".png", OUT + ".json")
