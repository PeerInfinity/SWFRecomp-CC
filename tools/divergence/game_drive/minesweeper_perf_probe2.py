import asyncio, http.server, socketserver, threading, time, os, json
from pathlib import Path
from playwright.async_api import async_playwright
ROOT=Path("/home/robert/CC/SWFRecomp-CC"); DOCS=ROOT/"docs2"
def serve(d,p):
    os.chdir(d); h=http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address=True
    s=socketserver.TCPServer(("127.0.0.1",p),h)
    threading.Thread(target=s.serve_forever,daemon=True).start()
def pct(b,q):
    n=len(b);
    if n==0: return 0
    return b[min(n-1,int(n*q))]
async def main():
    serve(str(DOCS),8421); time.sleep(1)
    async with async_playwright() as p:
        b=await p.chromium.launch(executable_path="/usr/bin/google-chrome",headless=False,args=["--enable-unsafe-webgpu","--ignore-gpu-blocklist","--no-sandbox"])
        pg=await b.new_page(viewport={"width":900,"height":700})
        await pg.goto("http://127.0.0.1:8421/demo.html?test=flasharchive/Minesweeper&perfhud=1",wait_until="load",timeout=20000)
        await pg.wait_for_selector("#btn-run",timeout=20000)
        for _ in range(40):
            if await pg.get_attribute("#btn-run","disabled") is None: break
            await asyncio.sleep(0.25)
        await pg.click("#btn-run")
        await asyncio.sleep(9.0)  # let difficulty screen settle + construction spike pass
        # Reset rolling buffer to capture clean steady-state only.
        await pg.evaluate("()=>{const S=globalThis.__swfPerf; if(S){S.cpu=[];S.iv=[];S.i=0;}}")
        await asyncio.sleep(8.0)  # steady-state capture window
        raw=await pg.evaluate("()=>{const S=globalThis.__swfPerf; return S?{cpu:S.cpu.slice(),iv:S.iv.slice(),frames:S.frames}:null;}")
        await pg.close(); await b.close()
    cpu=sorted(raw["cpu"]); iv=sorted(raw["iv"])
    def rep(name,arr):
        n=len(arr);
        if n==0: print(name,"empty"); return
        mean=sum(arr)/n
        print(f"{name}: n={n} median={pct(arr,0.5):.1f} p90={pct(arr,0.90):.1f} p95={pct(arr,0.95):.1f} max={arr[-1]:.1f} mean={mean:.1f}")
    print("frames_total",raw["frames"])
    rep("CPU ms",cpu)
    rep("interval ms",iv)
    # histogram of CPU buckets
    import collections
    buckets=collections.Counter()
    for v in cpu:
        if v<8: buckets["<8"]+=1
        elif v<16: buckets["8-16"]+=1
        elif v<33: buckets["16-33"]+=1
        elif v<66: buckets["33-66"]+=1
        elif v<120: buckets["66-120"]+=1
        else: buckets[">120"]+=1
    print("CPU buckets:",dict(buckets))
asyncio.run(main())
