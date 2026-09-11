#!/usr/bin/env python3
"""Headless-SwiftShader smoke check for a browser-WASM graphics page.

Boots the page in headless Chromium (SwiftShader), presses Start / Run SWF,
waits, and checks that the WebGPU renderer neither hangs the frame loop nor
floods the page with errors. Written for the device-lost slice
(SWFRecompDocs/status/browser-webgpu-device-lost.md).

Two Chromium configurations, because they behave differently:

  --gl=angle-swiftshader (default)  the flags headless harnesses usually pass.
      Chromium LOSES the WebGPU device at the page's first canvas present: the
      GPU process has no shared-image backing for the WebGPU swapchain when
      the compositor runs on ANGLE-SwiftShader GL. This checks that the
      runtime degrades gracefully: the loss is handled (window.__swfGpu.lost),
      no frame takes over 1 s, and the work-done rejections do not keep coming.

  --gl=vulkan  adds --enable-features=Vulkan --use-vulkan=swiftshader, so the
      compositor runs on SwiftShader Vulkan too. The device survives and the
      canvas shows real pixels. This checks for no loss and a non-blank canvas.

usage:
  python3 tools/browser-test/webgpu_headless_smoke.py <page url> [--gl=vulkan]
      [--wait=3] [--screenshot=out.png] [--chrome=/path/to/headless_shell]

Serve docs2 yourself first (python3 -m http.server <port> in docs2/). Exit
status 0 = all checks passed.
"""
import argparse
import sys
import time

from playwright.sync_api import sync_playwright

BASE_FLAGS = ["--enable-unsafe-webgpu", "--ignore-gpu-blocklist",
              "--enable-unsafe-swiftshader", "--use-angle=swiftshader", "--no-sandbox"]
VULKAN_FLAGS = ["--enable-features=Vulkan", "--use-vulkan=swiftshader"]

INIT = r"""
(() => {
  const P = window.__smoke = { lost: [] };
  const oReq = GPUAdapter.prototype.requestDevice;
  GPUAdapter.prototype.requestDevice = function (d) {
    return oReq.call(this, d).then(dev => {
      dev.lost.then(i => P.lost.push({ t: performance.now(), reason: i.reason, message: i.message }));
      return dev;
    });
  };
})();
"""

# __swfPerf.cpu is a ring buffer (cap S.cap, next slot S.i); unroll it so the
# last k entries are the last k frames.
READ = r"""
() => {
  const S = window.__swfPerf || { frames: 0, cpu: [], cap: 1, i: 0 };
  const cpu = S.cpu.length < S.cap ? S.cpu.slice() : S.cpu.slice(S.i).concat(S.cpu.slice(0, S.i));
  return { frames: S.frames, cpu: cpu, gpu: window.__swfGpu || null,
           lost: window.__smoke.lost, t: performance.now() };
}
"""


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("url")
    ap.add_argument("--gl", choices=["angle-swiftshader", "vulkan"], default="angle-swiftshader")
    ap.add_argument("--wait", type=float, default=3.0, help="seconds after Start")
    ap.add_argument("--screenshot", default=None)
    ap.add_argument("--chrome", default=None,
                    help="browser binary (default: Playwright's own headless shell)")
    a = ap.parse_args()

    flags = BASE_FLAGS + (VULKAN_FLAGS if a.gl == "vulkan" else [])
    errors = []
    with sync_playwright() as p:
        browser = p.chromium.launch(headless=True, args=flags, executable_path=a.chrome)
        page = browser.new_page()
        page.on("pageerror", lambda e: errors.append((time.time(), str(e))))
        page.add_init_script(INIT)
        page.goto(a.url)
        page.wait_for_function(
            "() => !!window.__runtimeReady || (document.getElementById('btn-run')"
            " && !document.getElementById('btn-run').disabled)", timeout=180000)
        page.click("#btn-start" if page.query_selector("#btn-start") else "#btn-run")
        page.wait_for_timeout(int(a.wait * 1000))
        mid = page.evaluate(READ)
        n_err_mid = len(errors)
        page.wait_for_timeout(2000)
        end = page.evaluate(READ)
        shot_stats = None
        if a.screenshot or a.gl == "vulkan":
            png = page.query_selector("#canvas").screenshot(path=a.screenshot)
            try:
                import io
                from PIL import Image
                im = Image.open(io.BytesIO(png)).convert("RGB")
                shot_stats = len(im.resize((120, 120)).getcolors(120 * 120))
            except ImportError:
                shot_stats = None
        browser.close()

    ext = [m for _, m in errors if "external Instance" in m]
    # Steady state = the frames finished between the two reads (startup frames
    # can legitimately take > 1 s on a live SwiftShader device: first-use
    # pipeline compiles). No frame at all in 2 s is itself a frame over 1 s.
    in_window = end["frames"] - mid["frames"]
    window_cpu = end["cpu"][-in_window:] if in_window > 0 else []
    over = [round(c) for c in window_cpu if c > 1000] if in_window > 0 else ["none finished in 2 s"]
    tick_rate = in_window / ((end["t"] - mid["t"]) / 1000.0)
    checks = []
    if a.gl == "vulkan":
        checks.append(("device not lost", not end["lost"]))
        checks.append(("canvas shows content (distinct colours > 4)",
                       shot_stats is None or shot_stats > 4))
    else:
        handled = (not end["lost"]) or (end["gpu"] is not None and end["gpu"].get("lost", 0) >= 1)
        checks.append(("device.lost pending or handled by the runtime", handled))
        checks.append(("work-done rejections stop (none in the last 2 s)", len(errors) == n_err_mid))
    checks.append(("no steady-state frame over 1 s", not over))
    checks.append(("frame loop ticking (>= 2 ticks/s)", tick_rate >= 2.0))

    print(f"gl={a.gl} ticks/s={tick_rate:.1f} frames={end['frames']} lost={end['lost']} "
          f"__swfGpu={end['gpu']} pageerrors={len(errors)} (external Instance: {len(ext)}) "
          f"steady frames>1s={over} canvas_colours={shot_stats}")
    ok = True
    for name, passed in checks:
        print(("PASS " if passed else "FAIL ") + name)
        ok = ok and passed
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()
