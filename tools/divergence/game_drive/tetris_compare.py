#!/usr/bin/env python3
"""tetris_compare.py — browser-faithful Ruffle-vs-SWFRecomp comparison for Tetris.

Drives BOTH runtimes in headed Chrome (WebGPU via WSLg) at identical stage
coordinates and screenshots each UI stage, then builds side-by-side PNGs:

  Tier A (ground truth) : Tetris.swf under Ruffle web   (tetris_ruffle.html)
  Tier B (under test)   : SWFRecomp browser-WASM demo   (docs2 demo.html)

Stages captured: menu -> (Play) level-select -> (Right arrow) level-select+1
                 -> (OK) game.

KEY: Chrome is launched with --ignore-gpu-blocklist so the WebGPU canvas is
captured (without it, screenshots come back black).

Prereqs:
  - Tetris demo deployed: SWFRecomp/scripts/{build_test,deploy_example}.sh
    flasharchive/Tetris  (docs2/examples/flasharchive/Tetris)
  - Playwright venv: /tmp/browser-test-venv  (pip install playwright pillow)
  - DISPLAY set (headed Chrome).

Output: tools/divergence/game_drive/compare_out/
  {ruffle,swfrecomp}_{menu,play,up,ok}.png  + compare_{stage}.png (side by side)
"""
import asyncio, http.server, socketserver, threading, time, os, sys
from pathlib import Path
from playwright.async_api import async_playwright
from PIL import Image, ImageDraw, ImageFont

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
DOCS = ROOT / "docs2"
OUT = HERE / "compare_out"
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"]

# Stage coordinates as fractions of the 382x380 Tetris stage (measured from the
# live runtime's button hit-test reports):
#   play_btn (200,207)  up_btn/right (229,247)  ok_btn (172,285)
FRAC = {
    "play":  (200/382, 207/380),
    "up":    (229/382, 247/380),
    "ok":    (172/382, 285/380),
}

STAGES = ["menu", "play", "up", "ok"]


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def held_click(page, x, y):
    await page.mouse.move(x, y)
    await asyncio.sleep(0.3)
    await page.mouse.down()
    await asyncio.sleep(0.4)
    await page.mouse.up()
    await asyncio.sleep(1.3)


async def drive(page, locator_sel, label, settle, click_run_sel=None):
    """Drive one runtime through the four stages, screenshotting each.
    Returns {stage: Path}."""
    shots = {}
    if click_run_sel:
        await page.wait_for_selector(click_run_sel, timeout=20000)
        for _ in range(40):
            if await page.get_attribute(click_run_sel, "disabled") is None:
                break
            await asyncio.sleep(0.25)
        await page.click(click_run_sel)
    await asyncio.sleep(settle)
    el = page.locator(locator_sel)
    box = await el.bounding_box()
    if not box:
        raise RuntimeError(f"{label}: locator {locator_sel} has no box")
    print(f"  {label}: box {box['width']:.0f}x{box['height']:.0f} @ "
          f"({box['x']:.0f},{box['y']:.0f})", file=sys.stderr)

    def at(frac):
        fx, fy = frac
        return box["x"] + box["width"] * fx, box["y"] + box["height"] * fy

    async def shot(stage):
        p = OUT / f"{label}_{stage}.png"
        try:
            await el.screenshot(path=str(p), timeout=6000)
        except Exception as e:
            # Fall back to a full-page shot cropped to the element box.
            print(f"    {label}/{stage}: element shot failed ({str(e)[:50]}), full-page",
                  file=sys.stderr)
            await page.screenshot(path=str(p))
        shots[stage] = p

    await shot("menu")
    ax, ay = at(FRAC["play"]); await held_click(page, ax, ay); await shot("play")
    ax, ay = at(FRAC["up"]);   await held_click(page, ax, ay); await shot("up")
    ax, ay = at(FRAC["ok"]);   await held_click(page, ax, ay)
    await asyncio.sleep(1.5)
    await shot("ok")
    return shots


def label_img(path, caption):
    img = Image.open(path).convert("RGB")
    bar = 22
    out = Image.new("RGB", (img.width, img.height + bar), (30, 30, 30))
    out.paste(img, (0, bar))
    d = ImageDraw.Draw(out)
    d.text((4, 4), caption, fill=(255, 255, 255))
    return out


def build_side_by_side(ruffle_shots, swf_shots):
    for stage in STAGES:
        r = ruffle_shots.get(stage)
        s = swf_shots.get(stage)
        if not (r and r.exists() and s and s.exists()):
            continue
        ri = label_img(r, f"Ruffle (truth) - {stage}")
        si = label_img(s, f"SWFRecomp WASM - {stage}")
        h = max(ri.height, si.height)
        # normalize heights
        if ri.height != h:
            ri = ri.resize((int(ri.width * h / ri.height), h))
        if si.height != h:
            si = si.resize((int(si.width * h / si.height), h))
        gap = 8
        combo = Image.new("RGB", (ri.width + gap + si.width, h), (60, 60, 60))
        combo.paste(ri, (0, 0))
        combo.paste(si, (ri.width + gap, 0))
        combo.save(OUT / f"compare_{stage}.png")
        print(f"  wrote compare_{stage}.png", file=sys.stderr)


def stage_swf():
    """Copy the (non-committed, local-only) Tetris SWF next to the ruffle
    harness so the served dir can fetch it. Source: $TETRIS_SWF or
    ~/CC/flasharchive/Tetris.swf."""
    dst = HERE / "Tetris.swf"
    if dst.exists():
        return
    src = Path(os.environ.get("TETRIS_SWF",
                              str(Path.home() / "CC" / "flasharchive" / "Tetris.swf")))
    if not src.exists():
        sys.exit(f"Tetris SWF not found at {src} (set $TETRIS_SWF)")
    import shutil
    shutil.copy2(src, dst)


async def main():
    OUT.mkdir(exist_ok=True)
    stage_swf()
    docs_httpd = serve(str(DOCS), 8410)
    # second server (different cwd) for the ruffle harness dir
    def serve2():
        h = http.server.SimpleHTTPRequestHandler
        socketserver.TCPServer.allow_reuse_address = True
        httpd = socketserver.TCPServer(("127.0.0.1", 8411),
                                       lambda *a, **k: h(*a, directory=str(HERE), **k))
        httpd.serve_forever()
    threading.Thread(target=serve2, daemon=True).start()
    time.sleep(1)

    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False,
                                           args=CHROME_ARGS)
        # Ruffle (ground truth)
        print("=== Ruffle ===", file=sys.stderr)
        rpage = await browser.new_page(viewport={"width": 900, "height": 700})
        rpage.on("console", lambda m: None)
        await rpage.goto("http://127.0.0.1:8411/tetris_ruffle.html", wait_until="load",
                         timeout=20000)
        ruffle_shots = await drive(rpage, "#ruffle-container", "ruffle", settle=4.0)
        await rpage.close()

        # SWFRecomp browser-WASM
        print("=== SWFRecomp ===", file=sys.stderr)
        spage = await browser.new_page(viewport={"width": 900, "height": 700})
        await spage.goto("http://127.0.0.1:8410/demo.html?test=flasharchive/Tetris",
                         wait_until="load", timeout=20000)
        swf_shots = await drive(spage, "#canvas", "swfrecomp", settle=3.0,
                                click_run_sel="#btn-run")
        await spage.close()
        await browser.close()

    build_side_by_side(ruffle_shots, swf_shots)
    print(f"Done. See {OUT}", file=sys.stderr)


if __name__ == "__main__":
    asyncio.run(main())
