#!/usr/bin/env python3
# ti_perf.py - title-inversion diagnosis driver (2026-07-20).
# Same rig as seedling_perf.py but ALWAYS saves a screenshot + JSON so every
# phase label is backed by evidence (Step 0 rule: "prove the state").
# Usage: ti_perf.py <ours|ruffle> <url> <settle_s> <out_prefix>
import sys, time, json
from playwright.sync_api import sync_playwright

MODE, URL = sys.argv[1], sys.argv[2]
SETTLE = int(sys.argv[3])
OUT = sys.argv[4]

FLAGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist"]

OURS_JS = r"""
() => { const S=window.__swfPerf; if(!S) return null;
  const stat=(a,clean)=>{let b=[];for(let k=0;k<a.length;k++) if(!clean||!S.bad[k]) b.push(a[k]);
    b.sort((x,y)=>x-y); const n=b.length,s=b.reduce((p,c)=>p+c,0);
    return {n,mean:n?s/n:0,p50:n?b[Math.floor(n*0.5)]:0,p95:n?b[Math.min(n-1,Math.floor(n*0.95))]:0,max:n?b[n-1]:0};};
  const total=S.cpu.length; let nbad=0; for(let i=0;i<total;i++) if(S.bad[i]) nbad++;
  const thr=(total>0&&nbad===total); const c=stat(S.cpu,!thr), rp=stat(S.rp,!thr);
  return {engine:'ours',frames:S.frames,total,excluded:nbad,throttled:thr,
          mean:+c.mean.toFixed(1),p50:+c.p50.toFixed(1),p95:+c.p95.toFixed(1),max:+c.max.toFixed(1),
          present:+rp.mean.toFixed(1),fps:c.mean>0?+(1000/c.mean).toFixed(1):0}; }
"""
RUFFLE_JS = r"""
() => { const t=window.__rufflePerfTick, r=window.__rufflePerfRender; if(!t||!t.length) return null;
  const stat=a=>{let b=a.slice().sort((x,y)=>x-y); const n=b.length,s=b.reduce((p,c)=>p+c,0);
    return {n,mean:n?s/n:0,p50:n?b[Math.floor(n*0.5)]:0,p95:n?b[Math.floor(n*0.95)]:0,max:n?b[n-1]:0};};
  const n=Math.min(t.length,(r&&r.length)||t.length); let tail=[];
  for(let i=Math.max(30,n-120);i<n;i++) tail.push(t[i]+((r&&r[i])||0));
  const ts=stat(t.slice(-120)), rs=stat((r||[]).slice(-120)), all=stat(tail);
  return {engine:'ruffle',frames:n,mean:+all.mean.toFixed(1),p50:+all.p50.toFixed(1),
          p95:+all.p95.toFixed(1),max:+all.max.toFixed(1),
          tick:+ts.mean.toFixed(1),tick_p50:+ts.p50.toFixed(1),render:+rs.mean.toFixed(1),
          fps:all.mean>0?+(1000/all.mean).toFixed(1):0}; }
"""

res = {"mode": MODE, "url": URL, "settle": SETTLE}
with sync_playwright() as p:
    b = p.chromium.launch(headless=False, args=FLAGS)
    pg = b.new_page(viewport={"width": 1100, "height": 800})
    errs = []
    pg.on("pageerror", lambda e: errs.append("PAGEERROR: " + str(e)))
    pg.goto(URL, wait_until="domcontentloaded", timeout=60000)
    res["adapter"] = pg.evaluate("""async()=>{ if(!navigator.gpu) return 'NO navigator.gpu';
        try{ const a=await navigator.gpu.requestAdapter(); if(!a) return 'NO adapter';
        let info={}; try{ info=a.info|| (a.requestAdapterInfo? await a.requestAdapterInfo():{});}catch(e){}
        return (info.vendor||'?')+' / '+(info.architecture||info.description||info.device||'?'); }
        catch(e){ return 'ERR '+e; } }""")
    print("WebGPU adapter:", res["adapter"])
    if MODE == "ours":
        try:
            pg.wait_for_selector("#btn-run:not([disabled])", timeout=60000)
            pg.click("#btn-run")
            print("clicked Run SWF")
        except Exception as e:
            print("RUN_CLICK_FAIL:", e)
    pg.bring_to_front()
    t0 = time.time()
    while time.time() - t0 < SETTLE:
        pg.wait_for_timeout(500)
    res["perf"] = pg.evaluate(OURS_JS if MODE == "ours" else RUFFLE_JS)
    pg.screenshot(path=OUT + ".png")
    res["errors"] = errs[:5]
    b.close()

print("PERF:", json.dumps(res["perf"]))
open(OUT + ".json", "w").write(json.dumps(res, indent=1))
print("saved", OUT + ".png", OUT + ".json")
