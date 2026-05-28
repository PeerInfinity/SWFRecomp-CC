import asyncio, sys, os
sys.path.insert(0, "/home/robert/CC/SWFRecomp-CC/tools/browser-test")
import serve
from playwright.async_api import async_playwright

# Click slug (stage ~45, 208), with explicit mouse hover + down + up.

async def main():
    outdir = "/tmp/snake-play-shots"
    os.makedirs(outdir, exist_ok=True)
    with serve.serve("/home/robert/CC/SWFRecomp-CC/docs2", 0) as (url_base, _):
        target = f"{url_base}/demo.html?test=flasharchive/Snake"
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
            await asyncio.sleep(1.5)

            # Use canvas locator
            box = await page.locator("#canvas").bounding_box()
            print(f"canvas box: {box}", flush=True)
            cw, ch = box["width"], box["height"]

            # Stage is 320x320. Click slug at stage (45, 208) => canvas pixel (45/320*cw, 208/320*ch).
            pos_x = (45.0 / 320.0) * cw
            pos_y = (208.0 / 320.0) * ch
            print(f"click position in canvas: ({pos_x:.1f}, {pos_y:.1f})", flush=True)

            # Hover first, then mousedown+mouseup with delay
            await page.locator("#canvas").hover(position={"x": pos_x, "y": pos_y})
            await asyncio.sleep(0.2)
            await page.mouse.down()
            await asyncio.sleep(0.05)
            await page.mouse.up()
            print("clicked", flush=True)

            await asyncio.sleep(0.15)
            for i in range(60):
                t = i * 0.5
                fname = f"{outdir}/t{i:02d}_{t:04.1f}s.png"
                try:
                    await page.locator("#canvas").screenshot(path=fname, timeout=5000)
                except Exception as e:
                    print(f"shot {i} failed: {e}", flush=True)
                    break
                await asyncio.sleep(0.5)

            await browser.close()
            print("done", flush=True)

asyncio.run(main())
