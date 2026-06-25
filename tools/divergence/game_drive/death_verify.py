import asyncio, http.server, socketserver, threading, time, os, json
from pathlib import Path
from playwright.async_api import async_playwright
ROOT=Path("/home/robert/CC/SWFRecomp-CC"); DOCS=ROOT/"docs2"
CHROME=os.environ.get("CHROME","/usr/bin/google-chrome")
ARGS=["--enable-unsafe-webgpu","--ignore-gpu-blocklist","--no-sandbox"]
PORT=8439
def serve(d,p):
    os.chdir(d); h=http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address=True
    s=socketserver.TCPServer(("127.0.0.1",p),h)
    threading.Thread(target=s.serve_forever,daemon=True).start()
async def rv(pg,n):
    return await pg.evaluate(f"""()=>{{try{{if(!window.__rv)window.__rv=Module.cwrap('dbgRootVarNum','number',['string']);return window.__rv("{n}");}}catch(e){{return 'err';}}}}""")
async def rf(pg):
    return await pg.evaluate("()=>{try{if(!window.__rf)window.__rf=Module.cwrap('dbgRootFrame','number',[]);return window.__rf();}catch(e){return 'err';}}")
async def runonce(tag):
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
        await pg.evaluate("()=>Module.ccall('dbgSetFrameCapMs',null,['number'],[40])")
        dlraw=await pg.evaluate("()=>{if(!window.__dl)window.__dl=Module.cwrap('getDisplayListJSON','string',[]);return window.__dl();}")
        items=json.loads(dlraw).get("displayList",[])
        btn=next((o for o in items if o["charId"]==30),None)
        box=await pg.locator("#canvas").bounding_box()
        ax=box["x"]+box["width"]*((btn["x"]+25)/360.0); ay=box["y"]+box["height"]*((btn["y"]+8)/420.0)
        await pg.mouse.move(ax,ay); await asyncio.sleep(0.2); await pg.mouse.down(); await asyncio.sleep(0.2); await pg.mouse.up()
        await pg.locator("#canvas").click(position={"x":5,"y":5}); await asyncio.sleep(6.0)
        # sit still; ghost catches pacman. detect death (playing=0) then watch lives + restart
        died=False; lives_before=await rv(pg,"lives"); restarted=False
        for t in range(120):
            playing=await rv(pg,"playing"); lives=await rv(pg,"lives"); fr=await rf(pg)
            if playing==0 and not died:
                died=True; t_death=t
            if died:
                if lives < lives_before:
                    print(f"[{tag}] DEATH->RESTART OK: lives {lives_before}->{lives}, rootFrame={fr} (t={t})")
                    restarted=True; break
            await asyncio.sleep(0.25)
        if died and not restarted:
            print(f"[{tag}] FROZEN: died but lives stayed {lives_before}, rootFrame={fr}")
        if not died:
            print(f"[{tag}] no death within window")
        await b.close()
async def main():
    serve(str(DOCS),PORT); time.sleep(1)
    for i in range(3):
        await runonce(f"run{i+1}")
asyncio.run(main())
