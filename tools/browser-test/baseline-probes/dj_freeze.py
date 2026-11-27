"""DJ freeze probe: load demo with ?mdt=<seed>, Run, click PLAY, watch rAF.
On a hang (page.evaluate times out), CDP Debugger.pause x3 and print wasm stacks.
usage: python3 dj_freeze.py <mdt|none> [watch_s] [port]
"""
import asyncio, sys, time
from playwright.async_api import async_playwright

MDT = sys.argv[1]
WATCH = float(sys.argv[2]) if len(sys.argv) > 2 else 12
PORT = sys.argv[3] if len(sys.argv) > 3 else "8017"

async def main():
    q = "" if MDT == "none" else f"&mdt={MDT}"
    url = f"http://localhost:{PORT}/demo.html?test=flasharchive/Doodle_Jump{q}"
    async with async_playwright() as p:
        b = await p.chromium.launch(executable_path="/opt/google/chrome/chrome", headless=False,
            args=["--enable-unsafe-webgpu", "--no-sandbox", "--ignore-gpu-blocklist"])
        ctx = await b.new_context(viewport={"width": 900, "height": 1200})
        page = await ctx.new_page()
        logs = []
        page.on("console", lambda m: logs.append(m.text))
        page.on("pageerror", lambda e: logs.append(f"[pageerror] {e}"))
        await page.add_init_script("window.__raf=0;(function f(){window.__raf++;requestAnimationFrame(f)})();")
        cdp = await ctx.new_cdp_session(page)
        await cdp.send("Debugger.enable")
        pausedq = asyncio.Queue()
        cdp.on("Debugger.paused", lambda ev: pausedq.put_nowait(ev))
        await page.goto(url, wait_until="domcontentloaded")
        await page.wait_for_function("() => { const b=document.getElementById('btn-run'); return b && !b.disabled; }", timeout=60000)
        await page.click("#btn-run")
        await asyncio.sleep(3.0)
        box = await page.locator("#canvas").bounding_box()
        px = 116.0 / 286.0 * box["width"]; py = 130.0 / 510.0 * box["height"]
        await page.mouse.move(box["x"] + px, box["y"] + py)
        await asyncio.sleep(0.2)
        await page.mouse.down(); await asyncio.sleep(0.05); await page.mouse.up()
        t0 = time.time(); hung = False; last = None
        while time.time() - t0 < WATCH:
            await asyncio.sleep(0.5)
            try:
                r = await asyncio.wait_for(page.evaluate("[window.__raf, (Module._dbgRootFrame?Module._dbgRootFrame():-9)]"), 3.0)
                last = r
            except asyncio.TimeoutError:
                hung = True; break
        seed = [l for l in logs if "[DJSEED]" in l]
        print(f"RESULT mdt={MDT} seedlog={seed[:1]} hung={hung} raf={last} t={time.time()-t0:.1f}", flush=True)
        if hung:
            for i in range(3):
                await cdp.send("Debugger.pause")
                try:
                    ev = await asyncio.wait_for(pausedq.get(), 10)
                except asyncio.TimeoutError:
                    print("pause did not land"); break
                print(f"--- sample {i+1} reason={ev['reason']}")
                for f in ev["callFrames"][:45]:
                    print("   ", f.get("functionName") or "(anon)")
                await cdp.send("Debugger.resume")
                await asyncio.sleep(0.7)
        tail = [l for l in logs if "WebGPU" not in l][-15:]
        print("LOGTAIL:", *tail, sep="\n  ")
        await b.close()

asyncio.run(main())
