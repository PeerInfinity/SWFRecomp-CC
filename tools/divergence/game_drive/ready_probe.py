import asyncio, http.server, socketserver, threading, time, os, json
from pathlib import Path
from playwright.async_api import async_playwright
ROOT=Path("/home/robert/CC/SWFRecomp-CC"); DOCS=ROOT/"docs2"
CHROME=os.environ.get("CHROME","/usr/bin/google-chrome")
ARGS=["--enable-unsafe-webgpu","--ignore-gpu-blocklist","--no-sandbox"]
PORT=8443
def serve(d,p):
    os.chdir(d); h=http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address=True
    s=socketserver.TCPServer(("127.0.0.1",p),h)
    threading.Thread(target=s.serve_forever,daemon=True).start()
async def rv(pg,n):
    return await pg.evaluate(f"""()=>{{try{{if(!window.__rv)window.__rv=Module.cwrap('dbgRootVarNum','number',['string']);return window.__rv("{n}");}}catch(e){{return 'err';}}}}""")
async def rf(pg):
    return await pg.evaluate("()=>{try{if(!window.__rf)window.__rf=Module.cwrap('dbgRootFrame','number',[]);return window.__rf();}catch(e){return 'err';}}")
async def main():
    serve(str(DOCS),PORT); time.sleep(1)
    async with async_playwright() as p:
        b=await p.chromium.launch(executable_path=CHROME,headless=False,args=ARGS)
        pg=await b.new_page(viewport={"width":700,"height":760})
        pg.on("pageerror",lambda e:print("PAGEERR "+str(e)[:160]))
        await pg.goto(f"http://127.0.0.1:{PORT}/demo.html?test=flasharchive/Pacman",wait_until="load",timeout=20000)
        await pg.wait_for_selector("#btn-run",timeout=20000)
        for _ in range(40):
            if await pg.get_attribute("#btn-run","disabled") is None: break
            await asyncio.sleep(0.25)
        await pg.click("#btn-run"); await asyncio.sleep(2.5)
        await pg.evaluate("()=>Module.ccall('dbgSetFrameCapMs',null,['number'],[30])")
        dlraw=await pg.evaluate("()=>{if(!window.__dl)window.__dl=Module.cwrap('getDisplayListJSON','string',[]);return window.__dl();}")
        items=json.loads(dlraw).get("displayList",[])
        btn=next((o for o in items if o["charId"]==30),None)
        box=await pg.locator("#canvas").bounding_box()
        ax=box["x"]+box["width"]*((btn["x"]+25)/360.0); ay=box["y"]+box["height"]*((btn["y"]+8)/420.0)
        await pg.mouse.move(ax,ay); await asyncio.sleep(0.2); await pg.mouse.down(); await asyncio.sleep(0.2); await pg.mouse.up()
        await pg.locator("#canvas").click(position={"x":5,"y":5}); await asyncio.sleep(6.0)
        print("=== sit; ghost catches pacman; watch death->restart->resume ===")
        phase="alive"; deaths=0
        for t in range(150):
            playing=await rv(pg,"playing"); lives=await rv(pg,"lives"); fr=await rf(pg)
            tag=""
            if phase=="alive" and playing==0: phase="dead"; tag=" <DEATH>"; deaths+=1
            elif phase=="dead" and lives<3: phase="restart"; tag=" <LIVES LOST -> Ready>"
            elif phase=="restart" and playing==1: phase="resumed"; tag=" <RESUMED!>"
            if t%2==0 or tag:
                print(f"t{t:03d} playing={playing} lives={lives} rootFrame={fr}{tag}")
            if phase=="resumed": print("=== game resumed after death ==="); break
            await asyncio.sleep(0.25)
        if phase!="resumed":
            print(f"=== STUCK in phase '{phase}' (playing never returned to 1) ===")
        await b.close()
asyncio.run(main())
