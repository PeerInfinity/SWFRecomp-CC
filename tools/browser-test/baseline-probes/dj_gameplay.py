import asyncio, sys, os
sys.path.insert(0, "/home/robert/CC/SWFRecomp-CC/tools/browser-test")
import serve
from playwright.async_api import async_playwright

async def main():
    outdir = "/tmp/dj-gameplay-shots"
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
            msgs = []
            page.on("console", lambda m: msgs.append(f"[console:{m.type}] {m.text}"))
            page.on("pageerror", lambda e: msgs.append(f"[pageerror] {e}"))
            await page.goto(target, wait_until="domcontentloaded")
            await page.wait_for_function("() => { const b = document.getElementById('btn-run'); return b && !b.disabled; }", timeout=20000)
            await page.click("#btn-run")
            await asyncio.sleep(2.0)
            # Click "play" — DJ menu play button at stage ~(116, 130) of a 286x510 stage
            box = await page.locator("#canvas").bounding_box()
            cw, ch = box["width"], box["height"]
            px = (116.0/286.0) * cw
            py = (130.0/510.0) * ch
            await page.locator("#canvas").hover(position={"x":px, "y":py})
            await asyncio.sleep(0.2)
            await page.mouse.down(); await asyncio.sleep(0.05); await page.mouse.up()
            await asyncio.sleep(0.8)
            # Watch gameplay; nudge left/right to keep bouncing, screenshot frequently.
            for i in range(12):
                try:
                    await page.locator("#canvas").screenshot(path=f"{outdir}/dj_gp_t{i:02d}.png", timeout=5000)
                except Exception as e:
                    print(f"shot {i} failed: {e}", flush=True)
                key = "ArrowLeft" if (i % 2 == 0) else "ArrowRight"
                await page.keyboard.down(key)
                await asyncio.sleep(0.35)
                await page.keyboard.up(key)
            # Dump display list JSON if exposed
            try:
                dl = await page.evaluate("() => (window.Module && Module._getDisplayListJSON) ? UTF8ToString(Module._getDisplayListJSON()) : (window.getDisplayListJSON ? getDisplayListJSON() : 'NO_DL_FN')")
                with open(f"{outdir}/displaylist.json","w") as f: f.write(str(dl))
            except Exception as e:
                print(f"dl dump failed: {e}", flush=True)
            await browser.close()
            print(f"console/page messages: {len(msgs)}", flush=True)
            for m in msgs[:40]: print("  "+m[:240], flush=True)

asyncio.run(main())
