#!/usr/bin/env python3
"""Run the WASM probe suite: serve docs2/, drive each probe in headed Chrome,
capture a canvas screenshot, diff vs the per-probe golden.png.

A "probe" lives at SWFRecomp/tests/wasm_probes/<slug>/. The harness reads
each probe's metadata from `probe.toml` (optional) with these keys:

    settle_seconds = 1.5          # wait after clicking Run before screenshot
    pixel_threshold = 5           # max number of differing pixels (default)
    channel_threshold = 16        # max channel delta per pixel (default)
    known_red = false             # if true, expected to fail (gap probe)
    golden_source = "ours"        # "ours" (default) | "ruffle"

Goldens live at SWFRecomp/tests/wasm_probes/<slug>/golden.png. KNOWN_RED
probes ship golden_ruffle.png alongside; the harness still diffs vs whichever
golden the toml selects and reports the result separately.

Usage:
    python3 tools/wasm_probe_runner.py                          # run all
    python3 tools/wasm_probe_runner.py --probe leaf_shared_slot # one probe
    python3 tools/wasm_probe_runner.py --capture-golden         # regenerate
                                                                # golden.png
                                                                # for every probe

Exit code is non-zero iff any non-KNOWN_RED probe fails. KNOWN_RED probes are
reported in a separate "wasm-gaps" section and never fail the run.
"""
import argparse
import asyncio
import json
import sys
import tomllib
from dataclasses import dataclass, field
from pathlib import Path

try:
    from playwright.async_api import async_playwright
except ImportError:
    print("error: playwright not installed.\n"
          "Setup:\n"
          "  python3 -m venv /tmp/browser-test-venv\n"
          "  source /tmp/browser-test-venv/bin/activate\n"
          "  pip install playwright\n"
          "  playwright install chromium",
          file=sys.stderr)
    sys.exit(2)

try:
    from PIL import Image
except ImportError:
    print("error: Pillow not installed (pip install pillow)", file=sys.stderr)
    sys.exit(2)

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools" / "browser-test"))
import serve  # noqa: E402

PROBES_DIR = REPO_ROOT / "SWFRecomp" / "tests" / "wasm_probes"
DOCS_ROOT = REPO_ROOT / "docs2"
DEFAULT_CHROME = "/usr/bin/google-chrome"


@dataclass
class ProbeConfig:
    slug: str
    settle_seconds: float = 1.5
    pixel_threshold: int = 5
    channel_threshold: int = 16
    known_red: bool = False
    golden_source: str = "ours"
    description: str = ""

    @property
    def golden_filename(self) -> str:
        return "golden_ruffle.png" if self.golden_source == "ruffle" else "golden.png"


@dataclass
class ProbeResult:
    slug: str
    known_red: bool
    status: str  # "pass" | "fail" | "missing_golden" | "error"
    detail: str = ""
    diff_pixels: int = 0
    max_channel_delta: int = 0
    diff_path: Path | None = None
    actual_path: Path | None = None


def load_probe_config(slug: str) -> ProbeConfig:
    cfg = ProbeConfig(slug=slug)
    toml_path = PROBES_DIR / slug / "probe.toml"
    if toml_path.is_file():
        with open(toml_path, "rb") as f:
            data = tomllib.load(f)
        cfg.settle_seconds = float(data.get("settle_seconds", cfg.settle_seconds))
        cfg.pixel_threshold = int(data.get("pixel_threshold", cfg.pixel_threshold))
        cfg.channel_threshold = int(data.get("channel_threshold", cfg.channel_threshold))
        cfg.known_red = bool(data.get("known_red", cfg.known_red))
        cfg.golden_source = str(data.get("golden_source", cfg.golden_source))
        cfg.description = str(data.get("description", ""))
    return cfg


def discover_probes() -> list[str]:
    if not PROBES_DIR.is_dir():
        return []
    return sorted(
        p.name for p in PROBES_DIR.iterdir()
        if p.is_dir() and (p / "test.xml").is_file()
    )


def diff_images(actual: Path, golden: Path,
                channel_threshold: int) -> tuple[int, int, Image.Image]:
    """Compare two PNGs. Returns (diff_pixel_count, max_channel_delta,
    visual_diff_image) where visual_diff_image is an RGBA image highlighting
    differing pixels in red.

    A pixel counts as different iff any channel differs by more than
    channel_threshold.
    """
    a = Image.open(actual).convert("RGBA")
    g = Image.open(golden).convert("RGBA")
    if a.size != g.size:
        # Force compare by resizing the smaller to the larger size; treat all
        # differing pixels as failures.
        target = (max(a.size[0], g.size[0]), max(a.size[1], g.size[1]))
        a = a.resize(target)
        g = g.resize(target)

    a_px = a.load()
    g_px = g.load()
    w, h = a.size
    diff_image = Image.new("RGBA", (w, h), (0, 0, 0, 0))
    diff_px = diff_image.load()
    differing = 0
    max_delta = 0
    for y in range(h):
        for x in range(w):
            ar, ag, ab, aa = a_px[x, y]
            gr, gg, gb, ga = g_px[x, y]
            dr = abs(ar - gr)
            dg = abs(ag - gg)
            db = abs(ab - gb)
            da = abs(aa - ga)
            local_max = max(dr, dg, db, da)
            if local_max > max_delta:
                max_delta = local_max
            if local_max > channel_threshold:
                differing += 1
                diff_px[x, y] = (255, 0, 0, 255)
            else:
                diff_px[x, y] = (ar, ag, ab, max(64, aa))  # faint actual
    return differing, max_delta, diff_image


async def capture_canvas(page, settle_seconds: float, out_path: Path) -> None:
    """Drive the demo page to first frame settled, capture the canvas at its
    intrinsic pixel resolution (canvas.width x canvas.height), write to
    out_path as PNG.

    Uses canvas.toDataURL() rather than Page.captureScreenshot — the latter's
    clip rect is unreliable on Chromium under xvfb, and toDataURL gives the
    framebuffer at the deterministic logical resolution regardless of CSS
    upscaling.
    """
    import base64
    await page.wait_for_function(
        "() => { const b = document.getElementById('btn-run');"
        "        return b && !b.disabled; }",
        timeout=20000,
    )
    await page.click("#btn-run")
    await asyncio.sleep(settle_seconds)

    data_url = await page.evaluate(
        "() => document.getElementById('canvas').toDataURL('image/png')"
    )
    if not isinstance(data_url, str) or not data_url.startswith("data:image/png;base64,"):
        raise RuntimeError(f"unexpected toDataURL result: {data_url!r:.200}")
    out_path.write_bytes(base64.b64decode(data_url.split(",", 1)[1]))


async def run_one_probe(p, browser, url_base: str, cfg: ProbeConfig,
                        capture_golden: bool, out_dir: Path) -> ProbeResult:
    target_url = f"{url_base}/demo.html?test=wasm_probes/{cfg.slug}"
    ctx = await browser.new_context(viewport={"width": 900, "height": 700})
    ctx.set_default_timeout(20000)
    page = await ctx.new_page()
    try:
        await page.goto(target_url, wait_until="domcontentloaded", timeout=20000)
        actual_path = out_dir / f"{cfg.slug}_actual.png"
        await capture_canvas(page, cfg.settle_seconds, actual_path)

        golden_path = PROBES_DIR / cfg.slug / cfg.golden_filename
        if capture_golden:
            golden_path.write_bytes(actual_path.read_bytes())
            return ProbeResult(
                slug=cfg.slug,
                known_red=cfg.known_red,
                status="pass",
                detail=f"captured golden -> {golden_path.relative_to(REPO_ROOT)}",
                actual_path=actual_path,
            )

        if not golden_path.is_file():
            return ProbeResult(
                slug=cfg.slug,
                known_red=cfg.known_red,
                status="missing_golden",
                detail=f"no {cfg.golden_filename} (run --capture-golden)",
                actual_path=actual_path,
            )

        diff_pixels, max_delta, diff_img = diff_images(
            actual_path, golden_path, cfg.channel_threshold,
        )
        diff_path = out_dir / f"{cfg.slug}_diff.png"
        diff_img.save(diff_path)

        passed = diff_pixels <= cfg.pixel_threshold
        return ProbeResult(
            slug=cfg.slug,
            known_red=cfg.known_red,
            status="pass" if passed else "fail",
            detail=f"diff_pixels={diff_pixels} max_channel_delta={max_delta}",
            diff_pixels=diff_pixels,
            max_channel_delta=max_delta,
            diff_path=diff_path,
            actual_path=actual_path,
        )
    except Exception as e:
        return ProbeResult(
            slug=cfg.slug,
            known_red=cfg.known_red,
            status="error",
            detail=str(e)[:200],
        )
    finally:
        await ctx.close()


async def run(args) -> int:
    slugs = [args.probe] if args.probe else discover_probes()
    if args.probe and args.probe not in discover_probes():
        print(f"error: probe '{args.probe}' not found under {PROBES_DIR}",
              file=sys.stderr)
        return 2
    if not slugs:
        print("no probes found")
        return 0

    out_dir = Path(args.out).resolve()
    out_dir.mkdir(parents=True, exist_ok=True)

    results: list[ProbeResult] = []
    with serve.serve(DOCS_ROOT, args.port) as (url_base, port):
        print(f"[serve] {url_base}", flush=True)
        async with async_playwright() as pw:
            browser = await pw.chromium.launch(
                executable_path=args.chrome,
                headless=False,
                args=["--enable-unsafe-webgpu", "--ignore-gpu-blocklist",
                      "--no-sandbox"],
            )
            try:
                for slug in slugs:
                    cfg = load_probe_config(slug)
                    print(f"[probe] {slug}", flush=True)
                    res = await run_one_probe(
                        pw, browser, url_base, cfg,
                        capture_golden=args.capture_golden,
                        out_dir=out_dir,
                    )
                    results.append(res)
                    suffix = " (KNOWN_RED)" if res.known_red else ""
                    print(f"  -> {res.status}{suffix}: {res.detail}",
                          flush=True)
            finally:
                await browser.close()

    # Report
    print("\n=== summary ===")
    passing = [r for r in results if r.status == "pass" and not r.known_red]
    failing = [r for r in results if r.status in ("fail", "error",
                                                   "missing_golden")
               and not r.known_red]
    known_red_actual_red = [r for r in results
                            if r.known_red and r.status != "pass"]
    known_red_unexpected_pass = [r for r in results
                                 if r.known_red and r.status == "pass"]
    print(f"passing      : {len(passing)}")
    print(f"failing      : {len(failing)}")
    for r in failing:
        print(f"  FAIL {r.slug}: {r.detail}")
    print(f"known-red    : {len(known_red_actual_red)} red as expected")
    for r in known_red_actual_red:
        print(f"  RED  {r.slug}: {r.detail}")
    if known_red_unexpected_pass:
        print(f"surprise pass: {len(known_red_unexpected_pass)} known-red now pass")
        for r in known_red_unexpected_pass:
            print(f"  GREEN {r.slug}: promote to required (clear known_red in probe.toml)")

    # Write JSON report.
    report = {
        "results": [
            {
                "slug": r.slug,
                "status": r.status,
                "known_red": r.known_red,
                "detail": r.detail,
                "diff_pixels": r.diff_pixels,
                "max_channel_delta": r.max_channel_delta,
                "actual_png": str(r.actual_path.relative_to(out_dir))
                if r.actual_path else None,
                "diff_png": str(r.diff_path.relative_to(out_dir))
                if r.diff_path else None,
            }
            for r in results
        ],
    }
    (out_dir / "report.json").write_text(json.dumps(report, indent=2))
    print(f"\nreport -> {out_dir / 'report.json'}")

    return 0 if not failing else 1


def parse_args():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--probe", default=None,
                    help="Run a single probe by slug (default: all).")
    ap.add_argument("--capture-golden", action="store_true",
                    help="Write captured canvas to <probe>/golden.png "
                         "(or golden_ruffle.png if probe.toml selects ruffle).")
    ap.add_argument("--port", type=int, default=0,
                    help="HTTP server port (default: auto-pick).")
    ap.add_argument("--chrome", default=DEFAULT_CHROME,
                    help=f"Chrome executable path (default: {DEFAULT_CHROME}).")
    ap.add_argument("--out", default=str(REPO_ROOT / "tools"
                                          / "wasm_probe_runner_out"),
                    help="Output directory for actual + diff PNGs and report.json.")
    return ap.parse_args()


def main():
    args = parse_args()
    try:
        rc = asyncio.run(run(args))
    except KeyboardInterrupt:
        rc = 130
    sys.exit(rc)


if __name__ == "__main__":
    main()
