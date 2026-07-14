#!/usr/bin/env python3
# render_bytes.py — read our __swfRender per-frame counters (writeTexture calls/bytes,
# writeBuffer calls/bytes, draws, submit ms) on the real-GPU Windows Chrome from WSL.
# Decides the writeTexture optimization approach (A padding vs B mechanism).
# Usage: render_bytes.py <url> <settle_seconds>
import sys, time, json
from playwright.sync_api import sync_playwright

URL    = sys.argv[1] if len(sys.argv) > 1 else "http://localhost:8010/demo.html?test=avm2/seedling&perfhud=1"
SETTLE = int(sys.argv[2]) if len(sys.argv) > 2 else 30
FLAGS  = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist"]

JS = r"""
() => { const R=window.__swfRender; if(!R||!R.wt||!R.wt.length) return null;
  const mean=a=>{const b=a.slice(-120);return b.length?b.reduce((p,c)=>p+c,0)/b.length:0;};
  const max=a=>{const b=a.slice(-120);return b.length?Math.max.apply(null,b):0;};
  return {samples:R.wt.length,
    wt_calls_mean:+mean(R.wt).toFixed(2), wt_calls_max:max(R.wt),
    wt_bytes_mean:Math.round(mean(R.wtbytes)), wt_bytes_max:max(R.wtbytes),
    wb_calls_mean:+mean(R.wb).toFixed(2), wb_bytes_mean:Math.round(mean(R.bytes)),
    draws_mean:+mean(R.draws).toFixed(2), submit_ms_mean:+mean(R.submit).toFixed(2)}; }
"""

with sync_playwright() as p:
    b = p.chromium.launch(headless=False, args=FLAGS)
    pg = b.new_page()
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
    try:
        pg.wait_for_selector("#btn-run:not([disabled])", timeout=60000)
        pg.click("#btn-run"); print("clicked Run SWF")
    except Exception as e:
        print("RUN_CLICK_FAIL:", e)
    pg.bring_to_front()
    t0=time.time()
    while time.time()-t0 < SETTLE:
        pg.wait_for_timeout(500)
    data = pg.evaluate(JS)
    print("RENDER_BYTES:", json.dumps(data))
    b.close()
