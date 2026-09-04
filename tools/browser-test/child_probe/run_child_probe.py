#!/usr/bin/env python3
"""Run a browser-WASM child-SWF probe page in WSLg Chrome and report what the
runtime actually did — trace lines, and (with --pixels) the rendered frame.

    run_child_probe.py <fixture> [--pixels] [--cap-ms N] [--secs N] [--port N]

Trace mode reads the recompiled movie's printf output off the console and
diffs it against the fixture's `output.txt` (the native/Ruffle oracle), so a
browser/native divergence shows up as a unified diff.

--pixels reads the framebuffer back off the GPU via `dbgCaptureBoard`
(display_bridge.c) instead of screenshotting the canvas. Two reasons, both
measured 2026-09-04 and neither obvious:
  * a Playwright screenshot of the WebGPU canvas comes back BLANK WHITE under
    WSLg even while the page is rendering correctly — the GPU readback of the
    very same frame shows the real image. Never read a blank canvas screenshot
    as "nothing rendered".
  * a regression fixture is a handful of frames long and is over (loop exited,
    nothing more presented) long before a screenshot can fire, so the probe
    first calls `dbgSetFrameCapMs` to stretch each frame out.

WSLg Chrome is SwiftShader: fine for these functional/correctness probes,
NEVER for frame rates (CLAUDE.md; see memory windows-playwright-from-wsl).
"""
import argparse, asyncio, base64, difflib, http.server, os, socketserver
import sys, threading, time
from pathlib import Path
from playwright.async_api import async_playwright

ROOT = Path(__file__).resolve().parents[3]
OUT_ROOT = Path(os.environ.get("OUT_ROOT", "/tmp/swf_child_probe"))
CHROME = os.environ.get("CHROME", "/usr/bin/google-chrome")
NOISE = ("[render]", "[HEAP]", "WASM SWF Runtime Loaded", "This is a recompiled",
         "Call runSWF()", "Starting SWF execution", "WebGPU is experimental",
         "ScriptProcessorNode is deprecated")


def serve(directory, port):
    os.chdir(directory)
    socketserver.TCPServer.allow_reuse_address = True
    httpd = socketserver.TCPServer(("127.0.0.1", port),
                                   http.server.SimpleHTTPRequestHandler)
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    return httpd


async def run(args):
    page_dir = OUT_ROOT / "web" / args.fixture
    if not page_dir.is_dir():
        sys.exit(f"no build at {page_dir} — run build_child_probe.sh {args.fixture} first")
    out_dir = OUT_ROOT / "out"; out_dir.mkdir(parents=True, exist_ok=True)
    serve(str(page_dir), args.port); time.sleep(0.6)

    lines, shots = [], []
    async with async_playwright() as p:
        browser = await p.chromium.launch(
            executable_path=CHROME, headless=False,
            args=["--enable-unsafe-webgpu", "--ignore-gpu-blocklist", "--no-sandbox"])
        page = await browser.new_page(viewport={"width": 900, "height": 800})
        page.on("console", lambda m: lines.append(m.text))
        page.on("pageerror", lambda e: lines.append(f"PAGEERROR: {e}"))
        await page.goto(f"http://127.0.0.1:{args.port}/index.html",
                        wait_until="load", timeout=30000)
        # Predicate must be a boolean expression: passing `Module.ccall` itself
        # makes Playwright try to CALL it as the predicate.
        await page.wait_for_function(
            '!!(window.Module && Module.ccall '
            '&& !document.getElementById("btn-run").disabled)', timeout=30000)
        if args.pixels:
            await page.evaluate(
                f"Module.ccall('dbgSetFrameCapMs', null, ['number'], [{args.cap_ms}])")
        await page.click("#btn-run", timeout=20000)
        if args.pixels:
            for i in range(args.frames):
                await page.wait_for_timeout(500)
                url = await page.evaluate(
                    "(async () => { if (!window.dbgCaptureBoard) {"
                    " Module.ccall('dbgCapturePNG', null, [], []);"
                    " await new Promise(r=>setTimeout(r,60)); }"
                    " return window.dbgCaptureBoard ? await window.dbgCaptureBoard() : null; })()")
                if url and url.startswith("data:image/png;base64,"):
                    f = out_dir / f"{args.fixture}.cap{i}.png"
                    f.write_bytes(base64.b64decode(url.split(",", 1)[1]))
                    shots.append(f)
        else:
            await page.wait_for_timeout(int(args.secs * 1000))
        await browser.close()

    traced = [l for l in lines if not any(l.startswith(n) or n in l for n in NOISE) and l.strip()]
    (out_dir / f"{args.fixture}.console.txt").write_text("\n".join(lines))
    print("--- browser trace ---")
    print("\n".join(traced))
    if shots:
        print(f"--- {len(shots)} framebuffer captures in {out_dir} ---")

    oracle = ROOT / args.tests_dir / args.fixture / "output.txt"
    if oracle.exists():
        want = oracle.read_text().splitlines()
        if traced == want:
            print("\nTRACE MATCHES the native oracle exactly.")
        else:
            print("\n--- diff vs native oracle (- browser, + native) ---")
            print("\n".join(difflib.unified_diff(traced, want, "browser", "native", lineterm="")))
    return 0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("fixture")
    ap.add_argument("--pixels", action="store_true",
                    help="GPU-read the framebuffer instead of waiting (see module docstring)")
    ap.add_argument("--cap-ms", type=int, default=700,
                    help="per-frame floor in ms while capturing, so the movie outlives the probe")
    ap.add_argument("--frames", type=int, default=14, help="capture attempts")
    ap.add_argument("--secs", type=float, default=12.0, help="trace-mode run time")
    ap.add_argument("--port", type=int, default=8477)
    ap.add_argument("--tests-dir", default="ruffle-tests/tests/swfs/regression")
    sys.exit(asyncio.run(run(ap.parse_args())))


if __name__ == "__main__":
    main()
