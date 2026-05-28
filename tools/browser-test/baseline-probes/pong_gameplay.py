import asyncio, sys, os
sys.path.insert(0, "/home/robert/CC/SWFRecomp-CC/tools/browser-test")
import serve
from playwright.async_api import async_playwright

async def main():
    outdir = "/tmp/pong-gameplay-shots"
    os.makedirs(outdir, exist_ok=True)
    with serve.serve("/home/robert/CC/SWFRecomp-CC/docs2", 0) as (url_base, _):
        target = f"{url_base}/demo.html?test=glaiel/Pong"
        async with async_playwright() as p:
            browser = await p.chromium.launch(
                executable_path="/opt/google/chrome/chrome",
                headless=False,
                args=["--enable-unsafe-webgpu","--no-sandbox","--ignore-gpu-blocklist"],
            )
            ctx = await browser.new_context(viewport={"width":900,"height":1500})
            ctx.set_default_timeout(60000)
            page = await ctx.new_page()
            errs = []
            page.on("pageerror", lambda e: errs.append(str(e)))
            page.on("console", lambda m: print(f"  [console] {m.text[:300]}", flush=True) if "TICK" in m.text or "DBG" in m.text else None)
            await page.goto(target, wait_until="domcontentloaded")
            await page.wait_for_function("() => { const b = document.getElementById('btn-run'); return b && !b.disabled; }", timeout=20000)
            await page.click("#btn-run")
            await asyncio.sleep(3.0)
            await page.locator("#canvas").screenshot(path=f"{outdir}/00_title.png", timeout=5000)

            # canvas geometry
            box = await page.locator("#canvas").bounding_box()
            print(f"canvas box: {box}", flush=True)
            # stage 550x400 -> click "1 Player" at stage (333,246)
            cx = box["x"] + 333/550 * box["width"]
            cy = box["y"] + 246/400 * box["height"]
            print(f"clicking 1 Player at canvas px ({cx:.0f},{cy:.0f})", flush=True)
            await page.mouse.move(cx, cy)
            await asyncio.sleep(0.3)
            await page.mouse.down()
            await asyncio.sleep(0.2)
            await page.mouse.up()
            await asyncio.sleep(1.5)
            await page.locator("#canvas").screenshot(path=f"{outdir}/01_after1p.png", timeout=5000)

            # Poll the display list for several seconds
            depths_seen = set()
            for i in range(12):
                await asyncio.sleep(0.5)
                try:
                    js = await page.evaluate("() => Module.cwrap('getDisplayListJSON','string',[])()")
                except Exception as e:
                    print(f"poll {i} eval failed: {e}", flush=True)
                    continue
                import json as _j
                try:
                    dl = _j.loads(js)
                    entries = dl.get("displayList", dl) if isinstance(dl, dict) else dl
                    depths = [(e.get("depth"), e.get("charId")) for e in entries]
                except Exception:
                    depths = js[:200]
                print(f"t={i*0.5+1.5:.1f}s dl={depths}", flush=True)
                if isinstance(depths, list):
                    for d,c in depths:
                        depths_seen.add(d)
            await page.locator("#canvas").screenshot(path=f"{outdir}/02_gameplay.png", timeout=5000)

            success = {7,9,11}.issubset(depths_seen)
            print(f"depths_seen={sorted(d for d in depths_seen if d is not None)}", flush=True)
            print(f"SUCCESS={success}  (need depths 7,9,11 present)", flush=True)
            await browser.close()
            print(f"errors: {len(errs)}", flush=True)
            for e in errs[:5]: print(f"  {e[:200]}", flush=True)

asyncio.run(main())
