#!/usr/bin/env python3
# seedling_perf_win.py — drive the Seedling perf A/B on the user's REAL-GPU Windows
# Chrome from WSL, via WSL->Windows interop (this is the *Windows* Python script;
# WSL calls the Windows python.exe to run it). Reads our __swfPerf HUD or Ruffle's
# __rufflePerf* globals and prints steady-state frame CPU / fps. Real GPU confirmed
# via the printed WebGPU adapter line (must NOT be SwiftShader/llvmpipe).
#
# Runs headed Chromium (Playwright's bundled browser) on the Windows desktop.
# WebGPU on via --enable-unsafe-webgpu. Serve docs2 from WSL (python3 -m http.server
# <PORT>); Windows Chromium reaches it over WSL2 localhost forwarding.
#
# HOW TO RUN FROM WSL (see WINDOWS_PLAYWRIGHT_FROM_WSL.md):
#   # 1. serve docs2 in WSL:   (cd docs2 && python3 -m http.server 8010)
#   # 2. keep a copy on a Windows path (interop rule): C:\playwright\ or /mnt/c/...
#   cp tools/divergence/perf/seedling_perf_win.py /mnt/c/playwright/seedling_perf.py
#   python.exe "$(wslpath -w /mnt/c/playwright/seedling_perf.py)" ours \
#     "http://localhost:8010/demo.html?test=avm2/seedling&perfhud=1" 45
#   python.exe "$(wslpath -w /mnt/c/playwright/seedling_perf.py)" ruffle \
#     "http://localhost:8010/examples/avm2/seedling_ruffle/" 45
# Use python.exe (Windows), NOT python3 (Linux, no Playwright). Script + any files
# it touches must be Windows paths (interop rule).
#
# Usage: seedling_perf.py <mode ours|ruffle> <url> <settle_seconds>
import sys, time, json
from playwright.sync_api import sync_playwright

MODE   = sys.argv[1] if len(sys.argv) > 1 else "ours"
URL    = sys.argv[2] if len(sys.argv) > 2 else "http://localhost:8000/demo.html?test=avm2/seedling&perfhud=1"
SETTLE = int(sys.argv[3]) if len(sys.argv) > 3 else 40

FLAGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist"]

OURS_JS = r"""
() => { const S=window.__swfPerf; if(!S) return null;
  const stat=(a,clean)=>{let b=[];for(let k=0;k<a.length;k++) if(!clean||!S.bad[k]) b.push(a[k]);
    b.sort((x,y)=>x-y); const n=b.length,s=b.reduce((p,c)=>p+c,0);
    return {n,mean:n?s/n:0,p95:n?b[Math.min(n-1,Math.floor(n*0.95))]:0,max:n?b[n-1]:0};};
  const total=S.cpu.length; let nbad=0; for(let i=0;i<total;i++) if(S.bad[i]) nbad++;
  const thr=(total>0&&nbad===total); const c=stat(S.cpu,!thr), rp=stat(S.rp,!thr);
  return {frames:S.frames,total,excluded:nbad,throttled:thr,
          mean:+c.mean.toFixed(1),p95:+c.p95.toFixed(1),max:+c.max.toFixed(1),
          present:+rp.mean.toFixed(1),avm_submit:+(c.mean-rp.mean).toFixed(1),
          fps:c.mean>0?+(1000/c.mean).toFixed(1):0}; }
"""
RUFFLE_JS = r"""
() => { const t=window.__rufflePerfTick, r=window.__rufflePerfRender; if(!t||!t.length) return null;
  const stat=a=>{let b=a.slice().sort((x,y)=>x-y); const n=b.length,s=b.reduce((p,c)=>p+c,0);
    return {n,mean:n?s/n:0,p95:n?b[Math.floor(n*0.95)]:0};};
  const warm=30, n=Math.min(t.length,(r&&r.length)||t.length); let tail=[];
  for(let i=Math.max(warm,n-120);i<n;i++) tail.push(t[i]+((r&&r[i])||0));
  const ts=stat(t.slice(-120)), rs=stat((r||[]).slice(-120)), all=stat(tail);
  return {frames:n,mean:+all.mean.toFixed(1),p95:+all.p95.toFixed(1),
          tick:+ts.mean.toFixed(1),render:+rs.mean.toFixed(1),
          fps:all.mean>0?+(1000/all.mean).toFixed(1):0}; }
"""

with sync_playwright() as p:
    b = p.chromium.launch(headless=False, args=FLAGS)
    pg = b.new_page()
    errs=[]
    pg.on("pageerror", lambda e: errs.append("PAGEERROR: "+str(e)))
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
    t0=time.time()
    while time.time()-t0 < SETTLE:
        pg.wait_for_timeout(500)   # keep the tab hot / event loop turning
    data = pg.evaluate(OURS_JS if MODE=="ours" else RUFFLE_JS)
    print("PERF:", json.dumps(data))
    if errs: print("ERRORS:", errs[:5])
    b.close()
