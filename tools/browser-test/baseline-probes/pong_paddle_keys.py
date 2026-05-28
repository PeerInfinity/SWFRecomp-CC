import asyncio, sys, os, json as _j
sys.path.insert(0, "/home/robert/CC/SWFRecomp-CC/tools/browser-test")
import serve
from playwright.async_api import async_playwright

async def dl(page):
    js = await page.evaluate("() => Module.cwrap('getDisplayListJSON','string',[])()")
    try:
        d = _j.loads(js)
        e = d.get("displayList", d) if isinstance(d, dict) else d
        return e
    except Exception:
        return js[:200]

async def main():
    outdir = "/tmp/pong-paddle-keys"
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
            page.on("console", lambda m: print(f"  [c] {m.text[:200]}", flush=True) if "DBG" in m.text else None)
            await page.goto(target, wait_until="domcontentloaded")
            await page.wait_for_function("() => { const b=document.getElementById('btn-run'); return b && !b.disabled; }", timeout=20000)
            await page.click("#btn-run")
            await asyncio.sleep(3.0)
            box = await page.locator("#canvas").bounding_box()
            cx = box["x"] + 333/550*box["width"]; cy = box["y"] + 246/400*box["height"]
            await page.mouse.move(cx, cy); await asyncio.sleep(0.2)
            await page.mouse.down(); await asyncio.sleep(0.2); await page.mouse.up()
            await asyncio.sleep(1.5)
            await page.locator("#canvas").focus()
            await page.locator("#canvas").screenshot(path=f"{outdir}/00_gameplay.png")
            print("DL before:", await dl(page), flush=True)

            print("=== HOLD ArrowUp 1.5s ===", flush=True)
            await page.keyboard.down("ArrowUp")
            await asyncio.sleep(1.5)
            await page.keyboard.up("ArrowUp")
            await page.locator("#canvas").screenshot(path=f"{outdir}/01_after_up.png")
            print("DL after up:", await dl(page), flush=True)

            print("=== HOLD ArrowDown 1.5s ===", flush=True)
            await page.keyboard.down("ArrowDown")
            await asyncio.sleep(1.5)
            await page.keyboard.up("ArrowDown")
            await page.locator("#canvas").screenshot(path=f"{outdir}/02_after_down.png")
            print("DL after down:", await dl(page), flush=True)

            await browser.close()

asyncio.run(main())
