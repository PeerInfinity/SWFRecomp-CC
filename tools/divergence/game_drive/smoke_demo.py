#!/usr/bin/env python3
"""smoke_demo.py — generic first-look smoke test for any deployed flasharchive
demo. Loads docs2's demo.html for the given game, clicks Run, waits, screenshots,
and reports console errors / page exceptions / WASM aborts.

Usage:
    DISPLAY=:0 /tmp/browser-test-venv/bin/python3 \
        tools/divergence/game_drive/smoke_demo.py <GameName> [wait_seconds]

    <GameName>      a folder under docs2/examples/flasharchive (e.g. Minesweeper,
                    Pacman, Snake). Deploy it first with
                    SWFRecomp/scripts/{build_test,deploy_example}.sh.
    wait_seconds    seconds to wait after clicking Run before the screenshot
                    (default 6).

Output: compare_out/smoke_<GameName>.png + an "errors=N" line (with the first few
error lines) on stdout. A lone 404 for rando_bridge.js / favicon.svg is benign.

Prereqs (same as tetris_compare.py): headed Chrome with WebGPU via WSLg
(--ignore-gpu-blocklist), DISPLAY set, Playwright venv at /tmp/browser-test-venv.
This is a triage aid — it confirms the page loads and renders *something* without
a crash; it does NOT validate gameplay. Use the per-game probes / manual testing
for that.
"""
import asyncio, http.server, socketserver, threading, time, os, sys, base64
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
DOCS = ROOT / "docs2"
OUT = HERE / "compare_out"
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"]
PORT = int(os.environ.get("SMOKE_PORT", "8414"))


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


def is_error(m):
    t = m.text
    return (m.type == "error"
            or "abort" in t.lower()
            or "RuntimeError" in t
            or "Uncaught" in t)


async def main(test, wait_s):
    OUT.mkdir(exist_ok=True)
    serve(str(DOCS), PORT)
    time.sleep(1)
    errs = []
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False,
                                           args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 900, "height": 700})
        page.on("console", lambda m: errs.append(m.text) if is_error(m) else None)
        page.on("pageerror", lambda e: errs.append("PAGEERROR " + str(e)[:160]))
        await page.goto(f"http://127.0.0.1:{PORT}/demo.html?test=flasharchive/{test}",
                        wait_until="load", timeout=20000)
        await page.wait_for_selector("#btn-run", timeout=20000)
        for _ in range(40):
            if await page.get_attribute("#btn-run", "disabled") is None:
                break
            await asyncio.sleep(0.25)
        await page.click("#btn-run")
        await asyncio.sleep(wait_s)
        try:
            cdp = await page.context.new_cdp_session(page)
            data = await cdp.send("Page.captureScreenshot",
                                  {"format": "png", "captureBeyondViewport": False})
            (OUT / f"smoke_{test}.png").write_bytes(base64.b64decode(data["data"]))
            print(f"screenshot: {OUT / f'smoke_{test}.png'}", file=sys.stderr)
        except Exception as e:
            print(f"  screenshot failed: {str(e)[:80]}", file=sys.stderr)
        await page.close()
        await browser.close()
    # Filter the well-known benign 404s (optional rando bridge / favicon).
    real = [e for e in errs if "rando_bridge.js" not in e and "favicon" not in e]
    print(f"{test}: errors={len(real)} (raw console-error lines={len(errs)})")
    for e in real[:8]:
        print("   ", e[:160])


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("usage: smoke_demo.py <GameName> [wait_seconds]", file=sys.stderr)
        sys.exit(2)
    test = sys.argv[1]
    wait_s = float(sys.argv[2]) if len(sys.argv) > 2 else 6.0
    asyncio.run(main(test, wait_s))
