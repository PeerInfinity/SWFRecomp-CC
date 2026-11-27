"""Play DJ with ?mdt seed, steer toward platforms randomly, capture frames via dbgCaptureBoard."""
import asyncio, sys, time, base64, os, random
from playwright.async_api import async_playwright
MDT, SECS, OUT = sys.argv[1], float(sys.argv[2]), sys.argv[3]
PORT = sys.argv[4] if len(sys.argv) > 4 else "8017"
os.makedirs(OUT, exist_ok=True)
async def main():
    url = f"http://localhost:{PORT}/demo.html?test=flasharchive/Doodle_Jump&mdt={MDT}"
    async with async_playwright() as p:
        b = await p.chromium.launch(executable_path="/opt/google/chrome/chrome", headless=False,
            args=["--enable-unsafe-webgpu", "--no-sandbox", "--ignore-gpu-blocklist"])
        page = await (await b.new_context(viewport={"width": 900, "height": 1200})).new_page()
        await page.goto(url, wait_until="domcontentloaded")
        await page.wait_for_function("() => { const b=document.getElementById('btn-run'); return b && !b.disabled; }", timeout=60000)
        await page.click("#btn-run"); await asyncio.sleep(3.0)
        box = await page.locator("#canvas").bounding_box()
        await page.mouse.move(box["x"] + 116/286*box["width"], box["y"] + 130/510*box["height"])
        await page.mouse.down(); await asyncio.sleep(0.05); await page.mouse.up()
        await page.focus("#canvas") if await page.locator("#canvas").count() else None
        rnd = random.Random(1); t0 = time.time(); i = 0
        while time.time() - t0 < SECS:
            key = rnd.choice(["ArrowLeft", "ArrowRight", None])
            if key: await page.keyboard.down(key)
            await asyncio.sleep(0.3)
            if key: await page.keyboard.up(key)
            try:
                d = await asyncio.wait_for(page.evaluate("window.dbgCaptureBoard ? window.dbgCaptureBoard() : (Module.ccall('dbgCapturePNG',null,[],[]), null)"), 15)
            except asyncio.TimeoutError:
                print("capture timeout"); break
            if d:
                open(f"{OUT}/s{i:03d}.png", "wb").write(base64.b64decode(d.split(",", 1)[1])); i += 1
            rf = await page.evaluate("Module._dbgRootFrame()")
            if rf != 1: print("root frame", rf, "at", round(time.time()-t0, 1))
        print("shots", i); await b.close()
asyncio.run(main())
