"""snake_keyboard — drives Snake to gameplay then issues ArrowRight / Down /
Left / Up. After each press the snake should change direction visibly. If
keys aren't reaching the runtime, the snake walks straight down to GAME OVER
the way snake_gameplay.py captures.

Visual check: after_right shows the snake against the east wall as a horizontal
trio; after_down at the SE corner; after_left mid-bottom as a horizontal trio
moving west; after_up center as a vertical pair moving north.
"""
import asyncio, sys, os
sys.path.insert(0, "/home/robert/CC/SWFRecomp-CC/tools/browser-test")
import serve
from playwright.async_api import async_playwright


async def main():
    outdir = "/tmp/snake-keyboard-shots"
    os.makedirs(outdir, exist_ok=True)
    with serve.serve("/home/robert/CC/SWFRecomp-CC/docs2", 0) as (url_base, _):
        target = f"{url_base}/demo.html?test=flasharchive/Snake"
        async with async_playwright() as p:
            browser = await p.chromium.launch(
                executable_path="/opt/google/chrome/chrome",
                headless=False,
                args=["--enable-unsafe-webgpu", "--no-sandbox",
                      "--ignore-gpu-blocklist"],
            )
            ctx = await browser.new_context(viewport={"width": 900, "height": 1500})
            ctx.set_default_timeout(60000)
            page = await ctx.new_page()
            await page.goto(target, wait_until="domcontentloaded")
            await page.wait_for_function(
                "() => { const b = document.getElementById('btn-run'); "
                "return b && !b.disabled; }",
                timeout=20000,
            )
            await page.click("#btn-run")
            await asyncio.sleep(2.5)

            box = await page.locator("#canvas").bounding_box()
            cw, ch = box["width"], box["height"]
            # Slug button is at stage (45, 208) on a 320x320 stage.
            pos_x = (45.0 / 320.0) * cw
            pos_y = (208.0 / 320.0) * ch
            await page.locator("#canvas").hover(position={"x": pos_x, "y": pos_y})
            await asyncio.sleep(0.2)
            await page.mouse.down()
            await asyncio.sleep(0.05)
            await page.mouse.up()
            print("clicked slug", flush=True)
            # Let the countdown finish and the snake spawn before pressing keys.
            await asyncio.sleep(2.0)

            await page.locator("#canvas").focus()
            await page.locator("#canvas").screenshot(path=f"{outdir}/01_before_keys.png")

            for label, key in [("right", "ArrowRight"),
                               ("down",  "ArrowDown"),
                               ("left",  "ArrowLeft"),
                               ("up",    "ArrowUp")]:
                await page.keyboard.press(key)
                await asyncio.sleep(2.0)
                await page.locator("#canvas").screenshot(
                    path=f"{outdir}/02_after_{label}.png")
                print(f"after {label}", flush=True)

            await browser.close()
            print("done", flush=True)


asyncio.run(main())
