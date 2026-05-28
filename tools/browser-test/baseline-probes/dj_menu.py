import asyncio, sys, os
sys.path.insert(0, "/home/robert/CC/SWFRecomp-CC/tools/browser-test")
import serve
from playwright.async_api import async_playwright

async def main():
    outdir = "/tmp/dj-baseline-shots"
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
            errs = []
            page.on("pageerror", lambda e: errs.append(str(e)))
            await page.goto(target, wait_until="domcontentloaded")
            await page.wait_for_function("() => { const b = document.getElementById('btn-run'); return b && !b.disabled; }", timeout=20000)
            await page.click("#btn-run")
            for i in range(8):
                await asyncio.sleep(1.0)
                try:
                    await page.locator("#canvas").screenshot(path=f"{outdir}/dj_t{i:02d}.png", timeout=5000)
                except Exception as e:
                    print(f"shot {i} failed: {e}", flush=True)
            await browser.close()
            print(f"errors: {len(errs)}", flush=True)
            for e in errs[:5]: print(f"  {e[:200]}", flush=True)

asyncio.run(main())
