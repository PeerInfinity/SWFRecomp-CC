#!/usr/bin/env python3
"""dbg_capture.py — load a deployed demo, click Run, collect console lines
containing a prefix (default 'DBG'). Throwaway diagnostic harness."""
import asyncio, http.server, socketserver, threading, time, os, sys
from pathlib import Path
from playwright.async_api import async_playwright

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
DOCS = ROOT / "docs2"
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
CHROME_ARGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"]
PORT = int(os.environ.get("SMOKE_PORT", "8415"))


def serve(directory, port):
    os.chdir(directory)
    handler = http.server.SimpleHTTPRequestHandler
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port), handler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def main(test, wait_s, prefix):
    serve(str(DOCS), PORT)
    time.sleep(1)
    lines = []
    async with async_playwright() as p:
        browser = await p.chromium.launch(executable_path=CHROME, headless=False,
                                           args=CHROME_ARGS)
        page = await browser.new_page(viewport={"width": 900, "height": 700})
        def on_console(m):
            t = m.text
            if prefix in t:
                lines.append(t)
        page.on("console", on_console)
        page.on("pageerror", lambda e: lines.append("PAGEERROR " + str(e)[:200]))
        await page.goto(f"http://127.0.0.1:{PORT}/demo.html?test=flasharchive/{test}",
                        wait_until="load", timeout=20000)
        await page.wait_for_selector("#btn-run", timeout=20000)
        for _ in range(40):
            if await page.get_attribute("#btn-run", "disabled") is None:
                break
            await asyncio.sleep(0.25)
        await page.click("#btn-run")
        await asyncio.sleep(wait_s)
        await page.close()
        await browser.close()
    print(f"=== {len(lines)} lines matching '{prefix}' ===")
    for l in lines:
        print(l)


if __name__ == "__main__":
    test = sys.argv[1] if len(sys.argv) > 1 else "Minesweeper"
    wait_s = float(sys.argv[2]) if len(sys.argv) > 2 else 10.0
    prefix = sys.argv[3] if len(sys.argv) > 3 else "DBG"
    asyncio.run(main(test, wait_s, prefix))
