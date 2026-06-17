import asyncio, http.server, socketserver, threading, time, os, json
from pathlib import Path
from playwright.async_api import async_playwright
ROOT=Path("/home/robert/CC/SWFRecomp-CC"); DOCS=ROOT/"docs2"
def serve(d,p):
    os.chdir(d); h=http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address=True
    s=socketserver.TCPServer(("127.0.0.1",p),h)
    threading.Thread(target=s.serve_forever,daemon=True).start()
async def main():
    serve(str(DOCS),8420); time.sleep(1)
    async with async_playwright() as p:
        b=await p.chromium.launch(executable_path="/usr/bin/google-chrome",headless=False,args=["--enable-unsafe-webgpu","--ignore-gpu-blocklist","--no-sandbox"])
        pg=await b.new_page(viewport={"width":900,"height":700})
        await pg.goto("http://127.0.0.1:8420/demo.html?test=flasharchive/Minesweeper&perfhud=1",wait_until="load",timeout=20000)
        await pg.wait_for_selector("#btn-run",timeout=20000)
        for _ in range(40):
            if await pg.get_attribute("#btn-run","disabled") is None: break
            await asyncio.sleep(0.25)
        await pg.click("#btn-run")
        await asyncio.sleep(10.0)  # let difficulty screen settle
        stats=await pg.evaluate("""()=>{const S=globalThis.__swfPerf; if(!S)return null;
            const f=a=>{const b=a.slice().sort((x,y)=>x-y);const n=b.length;let s=0;for(const v of b)s+=v;
              return {n, mean:n?s/n:0, p95:n?b[Math.min(n-1,Math.floor(n*0.95))]:0, max:n?b[n-1]:0};};
            return {frames:S.frames, cpu:f(S.cpu), iv:f(S.iv)};}""")
        print("CAPPED:", json.dumps(stats))
        # toggle uncapped to read max sustainable
        await pg.evaluate("()=>{globalThis.__swfPerf.uncapped=true;}")
        await asyncio.sleep(6.0)
        stats2=await pg.evaluate("""()=>{const S=globalThis.__swfPerf;if(!S)return null;
            const f=a=>{const b=a.slice().sort((x,y)=>x-y);const n=b.length;let s=0;for(const v of b)s+=v;
              return {n,mean:n?s/n:0,p95:n?b[Math.min(n-1,Math.floor(n*0.95))]:0,max:n?b[n-1]:0};};
            return {frames:S.frames, cpu:f(S.cpu), iv:f(S.iv)};}""")
        print("UNCAPPED:", json.dumps(stats2))
        await pg.close(); await b.close()
asyncio.run(main())
