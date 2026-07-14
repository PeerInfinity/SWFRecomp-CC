#!/usr/bin/env python3
# iv_perf.py — read the GROUND-TRUTH delivered frame period (S.iv) from __swfPerf,
# steady-state filtered (S.bad), plus cpu/present, on real-GPU Windows Chrome.
# Usage: iv_perf.py <url> <settle_seconds>
import sys, time, json
from playwright.sync_api import sync_playwright
URL    = sys.argv[1] if len(sys.argv) > 1 else "http://localhost:8010/demo.html?test=avm2/seedling&perfhud=1"
SETTLE = int(sys.argv[2]) if len(sys.argv) > 2 else 40
FLAGS  = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist"]
JS = r"""
() => { const S=window.__swfPerf; if(!S) return null;
  const stat=(a,clean)=>{let b=[];for(let k=0;k<a.length;k++) if(!clean||!S.bad[k]) b.push(a[k]);
    b.sort((x,y)=>x-y); const n=b.length,s=b.reduce((p,c)=>p+c,0);
    return {n,mean:n?s/n:0,p50:n?b[Math.floor(n*0.5)]:0,p95:n?b[Math.min(n-1,Math.floor(n*0.95))]:0};};
  const total=S.cpu.length; let nbad=0; for(let i=0;i<total;i++) if(S.bad[i]) nbad++;
  const thr=(total>0&&nbad===total), clean=!thr;
  const iv=stat(S.iv,clean), cpu=stat(S.cpu,clean), rp=stat(S.rp,clean);
  return {frames:S.frames,total,excluded:nbad,throttled:thr,
    iv_mean:+iv.mean.toFixed(2), iv_p50:+iv.p50.toFixed(2), iv_p95:+iv.p95.toFixed(2),
    delivered_fps:iv.mean>0?+(1000/iv.mean).toFixed(2):0,
    cpu_mean:+cpu.mean.toFixed(2), present_mean:+rp.mean.toFixed(2)}; }
"""
with sync_playwright() as p:
    b = p.chromium.launch(headless=False, args=FLAGS)
    pg = b.new_page()
    pg.goto(URL, wait_until="domcontentloaded", timeout=60000)
    ad = pg.evaluate("""async()=>{const a=await navigator.gpu.requestAdapter();let i={};try{i=a.info||{}}catch(e){}return (i.vendor||'?')+' / '+(i.architecture||'?');}""")
    print("adapter:", ad)
    try:
        pg.wait_for_selector("#btn-run:not([disabled])", timeout=60000); pg.click("#btn-run")
    except Exception as e: print("RUN_FAIL:", e)
    pg.bring_to_front()
    t0=time.time()
    while time.time()-t0 < SETTLE: pg.wait_for_timeout(500)
    print("IVPERF:", json.dumps(pg.evaluate(JS)))
    b.close()
