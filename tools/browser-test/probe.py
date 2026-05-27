#!/usr/bin/env python3
"""Diagnostic browser-WASM probe. Loads a deployed demo in headed Chrome,
clicks "Run SWF", and captures canvas snapshots / console logs / display
list polls at fixed wall-clock intervals.

This is the Phase 1 deliverable from
`SWFRecompDocs/plans/browser-wasm-testing-plan.md`: a tool for humans, with
no assertions, no determinism hook, and no parity gates. The intent is to
characterize what a single demo is doing in-browser, fast, without having to
rewrite a one-off probe each time.

    python3 tools/browser-test/probe.py glaiel/Pong
    python3 tools/browser-test/probe.py local_batch/Bloons --wall-clock-seconds 15
    python3 tools/browser-test/probe.py glaiel/Pong --out /tmp/pong-run --keep-open

Originally planned as `inspect.py` in
`SWFRecompDocs/plans/browser-wasm-testing-plan.md`, but that name shadows
Python's stdlib `inspect`, which Playwright imports internally. Renamed to
`probe.py`.

Captures, per run, into `<out>/`:
    canvas/tNN.png       PNG snapshot of <canvas> via locator.screenshot
    console.json         every page console message + pageerror
    trace.txt            plain-text console.log lines only (one per line)
    display_list/tNN.json  parsed getDisplayListJSON output (if available)
    summary.txt          one-screen human summary

== Capture method warning ==
The canvas capture path is *not* substitutable. WebGPU on Linux without a
real compositor (Playwright bundled `chromium_headless_shell`, `--headless=new`,
`Xvfb`+swiftshader, etc.) silently produces blank-white PNGs even when the
demo visibly renders in a real browser. The only configuration that captures
real pixels here is **headed Chrome via WSLg/DISPLAY + locator("#canvas").
screenshot()**. See `memory/browser_wasm_test_capture.md` for the full table
of what was tried.

This probe enforces the headed path. CI integration (Phase 5) will need a
different capture mechanism — software Vulkan or a runtime readback export.
"""
import argparse
import asyncio
import json
import sys
import time
from pathlib import Path

try:
    from playwright.async_api import async_playwright
except ImportError:
    print("error: playwright not installed.\n"
          "Setup:\n"
          "  python3 -m venv /tmp/browser-test-venv\n"
          "  source /tmp/browser-test-venv/bin/activate\n"
          "  pip install playwright\n"
          "  playwright install chromium\n"
          "  python3 tools/browser-test/probe.py ...",
          file=sys.stderr)
    sys.exit(2)

# Allow `import serve` from the same dir even when invoked from elsewhere.
sys.path.insert(0, str(Path(__file__).resolve().parent))
import serve  # noqa: E402


REPO_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_DOCS_ROOT = REPO_ROOT / "docs2"
DEFAULT_OUT_BASE = REPO_ROOT / "tools" / "browser-test" / "runs"
DEFAULT_CHROME = "/usr/bin/google-chrome"


def _chromium_args() -> list[str]:
    # WebGPU + swiftshader fallback + sandbox off (WSLg-friendly).
    return [
        "--enable-unsafe-webgpu",
        "--ignore-gpu-blocklist",
        "--no-sandbox",
    ]


async def _wait_for_module_ready(page, timeout_ms: int = 20000):
    """Wait until the demo's Run-SWF button is enabled, i.e. Module is loaded."""
    await page.wait_for_function(
        "() => { const b = document.getElementById('btn-run');"
        "        return b && !b.disabled; }",
        timeout=timeout_ms,
    )


async def _try_display_list_json(page) -> tuple[str, str | None]:
    """Return ('json', value) on success or ('error', short_reason) on failure.

    Uses cwrap('getDisplayListJSON','string',[]) — only exported on graphics
    WASM builds. Non-graphics builds return ('error', 'export missing').
    """
    raw = await page.evaluate(
        """
        () => {
            try {
                if (!window.Module || !Module.cwrap) {
                    return JSON.stringify({_probe_err: 'Module/cwrap missing'});
                }
                if (!window.__dl_get) {
                    try {
                        window.__dl_get = Module.cwrap('getDisplayListJSON', 'string', []);
                    } catch (e) {
                        return JSON.stringify({_probe_err: 'cwrap-bind: ' + String(e)});
                    }
                }
                const v = window.__dl_get();
                return v == null ? JSON.stringify({_probe_err: 'returned null'}) : v;
            } catch (e) {
                return JSON.stringify({_probe_err: 'call: ' + String(e)});
            }
        }
        """
    )
    try:
        parsed = json.loads(raw)
        if isinstance(parsed, dict) and "_probe_err" in parsed:
            return ("error", parsed["_probe_err"])
        return ("json", raw)
    except Exception:
        snippet = (raw or "")[:200]
        return ("error", f"unparseable ({len(raw or '')} chars): {snippet!r}")


async def run(args):
    out = Path(args.out).resolve()
    out.mkdir(parents=True, exist_ok=True)
    (out / "canvas").mkdir(exist_ok=True)
    (out / "display_list").mkdir(exist_ok=True)

    console_msgs: list[dict] = []
    page_errors: list[str] = []

    with serve.serve(args.docs_root, args.port) as (url_base, port):
        target_url = f"{url_base}/demo.html?test={args.demo_id}"
        print(f"[serve] {url_base} (docs root: {args.docs_root})", flush=True)
        print(f"[open]  {target_url}", flush=True)

        async with async_playwright() as p:
            browser = await p.chromium.launch(
                executable_path=args.chrome,
                headless=False,
                args=_chromium_args(),
            )
            ctx = await browser.new_context(
                viewport={"width": args.viewport_width,
                          "height": args.viewport_height},
            )
            # Context-level default would otherwise be 30s and override the
            # per-screenshot timeout, hanging the probe on any animating canvas
            # (locator.screenshot's stability check never resolves for a
            # continuously-redrawing WebGPU canvas).
            ctx.set_default_timeout(args.screenshot_timeout_ms)
            ctx.set_default_navigation_timeout(args.load_timeout_ms)
            page = await ctx.new_page()

            def on_console(msg):
                console_msgs.append({
                    "t": time.time(),
                    "type": msg.type,
                    "text": msg.text,
                })

            def on_page_error(err):
                page_errors.append(str(err))

            page.on("console", on_console)
            page.on("pageerror", on_page_error)

            t_start = time.time()
            try:
                await page.goto(target_url, wait_until="domcontentloaded",
                                timeout=args.load_timeout_ms)
            except Exception as e:
                print(f"[error] navigation failed: {e}", file=sys.stderr)
                await browser.close()
                return 2

            try:
                await _wait_for_module_ready(page, timeout_ms=args.load_timeout_ms)
            except Exception as e:
                print(f"[error] Module never finished loading: {e}",
                      file=sys.stderr)
                _flush_outputs(out, console_msgs, page_errors, [],
                               t_start, args, ready=False, run_clicked=False)
                if not args.keep_open:
                    await browser.close()
                return 3

            await page.click("#btn-run")
            run_clicked_at = time.time()
            print(f"[run]   #btn-run clicked at t={run_clicked_at - t_start:.2f}s",
                  flush=True)

            def _parse_event_spec(s):
                # "X,Y@T" -> (x, y, t)
                xy, _, t = s.partition("@")
                x, _, y = xy.partition(",")
                return float(x), float(y), float(t)

            # Build a sorted timeline of synthetic input events.
            input_events = []
            for spec in getattr(args, "move", []) or []:
                x, y, t = _parse_event_spec(spec)
                input_events.append((t, "move", x, y))
            for spec in getattr(args, "click", []) or []:
                x, y, t = _parse_event_spec(spec)
                input_events.append((t, "click", x, y))
            input_events.sort()

            # Snapshot loop: every `snapshot_interval_seconds` for up to
            # `wall_clock_seconds`. snapshots are 1-indexed so output paths
            # sort naturally.
            snapshots: list[dict] = []
            n_snapshots = max(
                1, int(args.wall_clock_seconds / args.snapshot_interval_seconds)
            )
            input_ev_idx = 0
            for i in range(1, n_snapshots + 1):
                target_t = run_clicked_at + i * args.snapshot_interval_seconds
                # Fire any input events scheduled before target_t.
                while input_ev_idx < len(input_events):
                    ev_t, ev_kind, ev_x, ev_y = input_events[input_ev_idx]
                    fire_at = run_clicked_at + ev_t
                    if fire_at >= target_t:
                        break
                    now = time.time()
                    if fire_at > now:
                        await asyncio.sleep(fire_at - now)
                    canvas_box = await page.locator("#canvas").bounding_box()
                    abs_x = (canvas_box["x"] if canvas_box else 0) + ev_x
                    abs_y = (canvas_box["y"] if canvas_box else 0) + ev_y
                    if ev_kind == "move":
                        await page.mouse.move(abs_x, abs_y)
                        print(f"  [input] move @ t={ev_t:.2f}s → ({ev_x}, {ev_y})",
                              flush=True)
                    elif ev_kind == "click":
                        await page.mouse.move(abs_x, abs_y)
                        await page.mouse.down()
                        await page.mouse.up()
                        print(f"  [input] click @ t={ev_t:.2f}s → ({ev_x}, {ev_y})",
                              flush=True)
                    input_ev_idx += 1
                now = time.time()
                if target_t > now:
                    await asyncio.sleep(target_t - now)
                elapsed = time.time() - run_clicked_at
                rec: dict = {"i": i, "elapsed_seconds": round(elapsed, 3)}

                if not args.no_canvas:
                    png_path = out / "canvas" / f"t{i:02d}.png"
                    try:
                        await page.locator("#canvas").screenshot(
                            path=str(png_path),
                            animations="allow",
                            timeout=args.screenshot_timeout_ms,
                        )
                        rec["canvas_png"] = str(png_path.relative_to(out))
                        rec["canvas_bytes"] = png_path.stat().st_size
                    except Exception as e:
                        # Common failure mode: a continuously-redrawing canvas
                        # never reaches Playwright's stability bar. Captured
                        # as a recorded error and surfaced in the summary;
                        # the probe still finishes and reports console + dl.
                        rec["canvas_error"] = str(e).splitlines()[0][:200]

                kind, payload = await _try_display_list_json(page)
                if kind == "json":
                    dl_path = out / "display_list" / f"t{i:02d}.json"
                    dl_path.write_text(payload)
                    rec["display_list"] = str(dl_path.relative_to(out))
                    try:
                        obj = json.loads(payload)
                        if isinstance(obj, dict):
                            dl = obj.get("displayList") or obj.get("display_list")
                            if isinstance(dl, list):
                                rec["display_list_count"] = len(dl)
                    except Exception:
                        pass
                else:
                    rec["display_list_error"] = payload
                    # Dump raw bytes for debugging unparseable cases
                    err_path = out / "display_list" / f"t{i:02d}.raw"
                    try:
                        err_path.parent.mkdir(parents=True, exist_ok=True)
                        err_path.write_text(payload if payload is not None else "")
                    except Exception:
                        pass

                snapshots.append(rec)
                if args.no_canvas:
                    canvas_field = "canvas=skipped       "
                elif "canvas_bytes" in rec:
                    canvas_field = f"canvas={rec['canvas_bytes']:>7} bytes "
                else:
                    canvas_field = "canvas=ERR           "
                print(
                    f"  t={i*args.snapshot_interval_seconds:.1f}s  "
                    f"{canvas_field}"
                    f"dl_count={rec.get('display_list_count', rec.get('display_list_error', '?'))}",
                    flush=True,
                )

            _flush_outputs(out, console_msgs, page_errors, snapshots,
                           t_start, args, ready=True, run_clicked=True)

            if args.keep_open:
                print("\n[keep-open] Browser left open. Ctrl-C to exit.",
                      flush=True)
                try:
                    while True:
                        await asyncio.sleep(3600)
                except (KeyboardInterrupt, asyncio.CancelledError):
                    pass

            await browser.close()
    return 0


def _flush_outputs(out: Path, console_msgs, page_errors, snapshots,
                   t_start, args, *, ready: bool, run_clicked: bool):
    # Full console as JSON.
    (out / "console.json").write_text(json.dumps(console_msgs, indent=2))
    # Plain-text trace: just `console.log` text, one per line.
    trace_lines = [m["text"] for m in console_msgs if m["type"] == "log"]
    (out / "trace.txt").write_text("\n".join(trace_lines) + ("\n" if trace_lines else ""))
    (out / "snapshots.json").write_text(json.dumps(snapshots, indent=2))
    if page_errors:
        (out / "page_errors.txt").write_text("\n\n".join(page_errors) + "\n")

    summary_lines = [
        f"demo_id              : {args.demo_id}",
        f"docs_root            : {args.docs_root}",
        f"out                  : {out}",
        f"wall_clock_seconds   : {args.wall_clock_seconds}",
        f"snapshot_interval_s  : {args.snapshot_interval_seconds}",
        f"module_loaded        : {ready}",
        f"run_swf_clicked      : {run_clicked}",
        f"snapshots_captured   : {len(snapshots)}",
        f"console_messages     : {len(console_msgs)}",
        f"  log                : {sum(1 for m in console_msgs if m['type'] == 'log')}",
        f"  warning            : {sum(1 for m in console_msgs if m['type'] == 'warning')}",
        f"  error              : {sum(1 for m in console_msgs if m['type'] == 'error')}",
        f"page_errors          : {len(page_errors)}",
    ]
    if snapshots:
        canvas_ok = sum(1 for s in snapshots if "canvas_bytes" in s)
        canvas_err = sum(1 for s in snapshots if "canvas_error" in s)
        summary_lines.append(f"canvas_snapshots     : {canvas_ok} ok, {canvas_err} error")
        if canvas_ok:
            unique_canvas = len({s.get("canvas_bytes") for s in snapshots
                                 if "canvas_bytes" in s})
            summary_lines.append(f"unique_canvas_sizes  : {unique_canvas}")
        dl_counts = [s.get("display_list_count") for s in snapshots
                     if "display_list_count" in s]
        if dl_counts:
            summary_lines.append(f"display_list_counts  : {dl_counts}")
    summary_lines.append(f"wall_clock_total_s   : {time.time() - t_start:.2f}")
    (out / "summary.txt").write_text("\n".join(summary_lines) + "\n")
    print("\n" + "\n".join(summary_lines), flush=True)


def parse_args():
    ap = argparse.ArgumentParser(
        description=__doc__.splitlines()[0],
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    ap.add_argument("demo_id",
                    help="Demo identifier matching the docs catalog "
                         "(e.g. 'glaiel/Pong', 'local_batch/Bloons').")
    ap.add_argument("--wall-clock-seconds", type=float, default=8.0,
                    help="Total wall-clock time to capture after Run-SWF "
                         "(default: 8).")
    ap.add_argument("--snapshot-interval-seconds", type=float, default=1.0,
                    help="Seconds between canvas/display-list snapshots "
                         "(default: 1).")
    ap.add_argument("--out", type=Path,
                    default=None,
                    help="Output directory (default: "
                         "tools/browser-test/runs/<demo-id>/).")
    ap.add_argument("--docs-root", type=Path, default=DEFAULT_DOCS_ROOT,
                    help=f"Docs root to serve (default: {DEFAULT_DOCS_ROOT}).")
    ap.add_argument("--port", type=int, default=0,
                    help="HTTP server port (default: auto-pick).")
    ap.add_argument("--chrome", default=DEFAULT_CHROME,
                    help=f"Chrome executable path (default: {DEFAULT_CHROME}). "
                         "Must be a real headed Chrome — Playwright's bundled "
                         "headless_shell does not have a WebGPU compositor.")
    ap.add_argument("--viewport-width", type=int, default=900)
    ap.add_argument("--viewport-height", type=int, default=700)
    ap.add_argument("--load-timeout-ms", type=int, default=20000)
    ap.add_argument("--screenshot-timeout-ms", type=int, default=8000)
    ap.add_argument("--keep-open", action="store_true",
                    help="Keep the browser open after capture (until Ctrl-C). "
                         "Useful for poking at the page yourself.")
    ap.add_argument("--no-canvas", action="store_true",
                    help="Skip canvas screenshots. Faster for console-only "
                         "probes, and avoids the per-snapshot timeout cost "
                         "on continuously-redrawing demos where the "
                         "locator.screenshot stability check never resolves.")
    ap.add_argument("--click", action="append", default=[],
                    metavar="X,Y@T",
                    help="Send a synthetic mouse click at canvas-relative "
                         "(X, Y) pixel position at time T seconds after "
                         "Run-SWF. May be repeated. Example: --click '160,200@2.0'.")
    ap.add_argument("--move", action="append", default=[],
                    metavar="X,Y@T",
                    help="Send a synthetic mouse move at canvas-relative "
                         "(X, Y) pixel position at time T. May be repeated.")
    args = ap.parse_args()

    if args.out is None:
        # Filesystem-safe: replace path separators in the demo id.
        safe = args.demo_id.replace("/", "_")
        args.out = DEFAULT_OUT_BASE / safe
    return args


def main():
    args = parse_args()
    try:
        rc = asyncio.run(run(args))
    except KeyboardInterrupt:
        print("\n[abort] interrupted by user", file=sys.stderr)
        rc = 130
    sys.exit(rc)


if __name__ == "__main__":
    main()
