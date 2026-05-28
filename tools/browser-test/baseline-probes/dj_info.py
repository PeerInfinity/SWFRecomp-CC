import asyncio, sys, os
sys.path.insert(0, "/home/robert/CC/SWFRecomp-CC/tools/browser-test")
import serve
from playwright.async_api import async_playwright

async def main():
    outdir = "/tmp/dj-play-shots"
    os.makedirs(outdir, exist_ok=True)
    with serve.serve("/home/robert/CC/SWFRecomp-CC/docs2", 0) as (url_base, _):
        target = f"{url_base}/demo.html?test=flasharchive/Doodle_Jump"
        async with async_playwright() as p:
            browser = await p.chromium.launch(
                executable_path="/opt/google/chrome/chrome",
                headless=False,
                args=["--enable-unsafe-webgpu","--no-sandbox","--ignore-gpu-blocklist"],
            )
            ctx = await browser.new_context(viewport={"width":900,"height":1500})
            ctx.set_default_timeout(60000)
            page = await ctx.new_page()
            await page.goto(target, wait_until="domcontentloaded")
            await page.wait_for_function("() => { const b = document.getElementById('btn-run'); return b && !b.disabled; }", timeout=20000)
            await page.click("#btn-run")
            await asyncio.sleep(2.0)
            # Click "play" — DJ menu has play button at stage ~(143, 198) of a 286x510 stage
            box = await page.locator("#canvas").bounding_box()
            cw, ch = box["width"], box["height"]
            px = (143.0/286.0) * cw
            py = (198.0/510.0) * ch
            await page.locator("#canvas").hover(position={"x":px, "y":py})
            await asyncio.sleep(0.2)
            await page.mouse.down(); await asyncio.sleep(0.05); await page.mouse.up()
            await asyncio.sleep(0.5)
            for i in range(6):
                try:
                    await page.locator("#canvas").screenshot(path=f"{outdir}/dj_play_t{i:02d}.png", timeout=5000)
                except Exception as e:
                    print(f"shot {i} failed: {e}", flush=True)
                await asyncio.sleep(0.7)
            await browser.close()

asyncio.run(main())
