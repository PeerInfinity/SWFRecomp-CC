# Browser-WASM Test Harness — Usage Guide

`tools/browser-test/` is a diagnostic harness for **browser-WASM** demos
(the `-DUSE_WEBGPU` build that ships in `docs2/examples/...`, distinct
from headless graphics-native builds covered by
`ruffle-tests/verify_output.py`).

This is the Phase 1 deliverable from
`SWFRecompDocs/plans/browser-wasm-testing-plan.md`. It is **diagnostic
only** — there are no assertions, no determinism hook, and no parity
gates. It captures:

- A canvas PNG snapshot per interval (when possible — see "Canvas
  snapshot limits" below)
- Every page console message + page-level errors
- A `getDisplayListJSON` dump per interval (when the WASM build
  exports it — graphics WASM does, trace-only does not)
- A one-screen summary

It does **not** try to decide whether the demo is "working" — that's
the job of Phase 3+ (assertions against `output.txt`, parity check
against headless-graphics PNGs). Today the harness exists to make it
fast to characterize what a single demo is doing in-browser without
re-writing a one-off Playwright probe.

Background and rationale:
[`browser-wasm-testing-plan.md`](../plans/browser-wasm-testing-plan.md);
the Phase 0 spike that motivated this harness:
[`status/2026-05-25-pong-browser-diagnosis.md`](../status/2026-05-25-pong-browser-diagnosis.md).

## One-time setup

### A real headed Chrome

WebGPU canvas capture on Linux **requires** a headed Chrome with a
real display server. On WSL2 that means the WSLg-provided `DISPLAY`
(usually `:0`) and `/usr/bin/google-chrome`. Playwright's bundled
`chromium_headless_shell` does not have a WebGPU compositor and
silently captures blank pixels for the canvas region; see the
"Canvas snapshot limits" section for the full table of what was
tried.

```bash
which google-chrome           # should print /usr/bin/google-chrome
echo $DISPLAY                  # should print :0 (or similar)
```

If `google-chrome` lives elsewhere, pass `--chrome /path/to/google-chrome`.

### Python + Playwright

Playwright is not installed system-wide on this project. The simplest
path is a one-shot venv:

```bash
python3 -m venv /tmp/browser-test-venv
source /tmp/browser-test-venv/bin/activate
pip install playwright Pillow
playwright install chromium   # downloads Playwright's bundled browser; unused
                              # by us (we drive system Chrome) but the package
                              # requires the install step before importing
```

(`Pillow` is only needed for `compare.py images`. The probe itself
runs without it.)

The existing `/tmp/pong-probe/venv` already has these installed from
the Phase 0 spike; use it directly if you don't want to recreate one.

### Deployed demos

The harness drives the same `docs2/demo.html?test=<demo-id>` URL the
shipping demo page uses. Demos must already be built and deployed
under `docs2/examples/<demo-id>/`. For glaiel demos:

```bash
SWFRecomp/scripts/build_swf_batch.sh /tmp/glaiel-stage \
    --docs-dir docs2 --namespace glaiel \
    --catalog-name glaiel_catalog.json --demo-type glaiel
```

For graphics WASM demos to expose `getDisplayListJSON` for display-list
polling, no extra flags are needed — the export is already in
`build_test.sh`'s graphics-WASM export list.

## Running a probe

```bash
python3 tools/browser-test/probe.py <demo-id> [options]
```

Examples:

```bash
# Default: 8 seconds, 1s snapshot interval, output to runs/<demo-id>/
python3 tools/browser-test/probe.py glaiel/Pong

# Console + display list only — fast, no canvas screenshot timeouts
python3 tools/browser-test/probe.py local_batch/Bloons --no-canvas

# Longer run, every 0.5s, custom out dir
python3 tools/browser-test/probe.py glaiel/Pong \
    --wall-clock-seconds 30 --snapshot-interval-seconds 0.5 \
    --out /tmp/pong-debug

# Leave browser open after capture so you can poke at the page
python3 tools/browser-test/probe.py glaiel/Pong --keep-open
```

### Flags

| Flag | Default | Notes |
|---|---|---|
| `<demo-id>` | required | Matches `?test=<id>` in `docs2/demo.html`, e.g. `glaiel/Pong`. |
| `--wall-clock-seconds N` | 8 | Total time to capture after clicking Run-SWF. |
| `--snapshot-interval-seconds N` | 1 | Seconds between snapshots. |
| `--no-canvas` | off | Skip canvas screenshots. Fast iteration; avoids Playwright stability-check hangs on constantly-redrawing demos. |
| `--out DIR` | `tools/browser-test/runs/<demo-id>/` | Output directory. Re-runs overwrite. |
| `--docs-root DIR` | `docs2` | Which docs root to serve. |
| `--port N` | auto | HTTP server port. Auto-picks free if 0. |
| `--chrome PATH` | `/usr/bin/google-chrome` | Real headed Chrome path. |
| `--viewport-width N` / `--viewport-height N` | 900 / 700 | Browser viewport. Demo canvas is sized from `test_info.json`, not the viewport. |
| `--load-timeout-ms N` | 20000 | Navigation + Module-ready timeout. |
| `--screenshot-timeout-ms N` | 8000 | Per-screenshot wait. Also used as the context default for all other waits — see "Gotchas". |
| `--keep-open` | off | Don't close Chrome after capture. Ctrl-C to exit. |

### Output layout

```
tools/browser-test/runs/<demo-id>/
  summary.txt                one-screen text summary (also printed to stdout)
  trace.txt                  plain-text console.log lines, one per line
  console.json               every console.{log,warning,error,…} with timestamps
  page_errors.txt            uncaught page errors (only if any fired)
  canvas/t01.png             canvas snapshot at interval 1 (locator.screenshot)
  canvas/t02.png
  ...
  display_list/t01.json      getDisplayListJSON dump at interval 1
  display_list/t02.json
  ...
  snapshots.json             per-snapshot record (timing, sizes, errors, dl_count)
```

`/` in `<demo-id>` is replaced with `_` for the dir name (so
`glaiel/Pong` → `runs/glaiel_Pong/`).

### Reading the summary

```
demo_id              : glaiel/Pong
docs_root            : /home/robert/CC/SWFRecomp-CC/docs2
out                  : /tmp/browser-test-smoke/pong
wall_clock_seconds   : 6.0
snapshot_interval_s  : 2.0
module_loaded        : True
run_swf_clicked      : True
snapshots_captured   : 3
console_messages     : 8
  log                : 6
  warning            : 1
  error              : 0
page_errors          : 0
canvas_snapshots     : 3 ok, 0 error
unique_canvas_sizes  : 1
display_list_counts  : [3, 3, 3]
wall_clock_total_s   : 8.42
```

Useful at-a-glance signals:

- **`module_loaded: False`** → WASM never finished loading. Check
  `console.json` for the failure.
- **`unique_canvas_sizes: 1`** across several snapshots → canvas hasn't
  changed at all (Pong-style stuck). Worth a side-by-side `cmp` of
  the PNGs to be sure they're byte-identical.
- **`display_list_counts: [N, N, N, …]`** unchanged → timeline isn't
  placing/removing objects. Either stopped (often legitimate) or
  stuck.
- **High `error` count** → AVM exception spam or runtime asserts.
  Sort `console.json` by unique text — usually a small handful of
  patterns repeating.
- **`canvas_snapshots: 0 ok, N error`** without `--no-canvas` →
  Playwright's stability check timed out on every frame. The demo is
  rendering continuously and the WebGPU canvas never becomes "stable".
  Re-run with `--no-canvas` for fast iteration; canvas pixels aren't
  available until we add a runtime readback path (Phase 2-ish).

## Canvas snapshot limits

The capture method is **not** substitutable. Confirmed 2026-05-25
against Chromium 138 / Playwright 1.60:

| Config | Captures real canvas? |
|---|---|
| Headed `/usr/bin/google-chrome` via WSLg + `locator("#canvas").screenshot()` | **yes** |
| Playwright bundled `chromium_headless_shell` (any flags) | no — blank white |
| Headed Chrome + `page.screenshot()` (full-page) | no — blank for canvas region |
| Headed Chrome + CDP `Page.captureScreenshot` (both `fromSurface` modes) | no — blank for canvas region |
| `--headless=new` + swiftshader | no — blank |
| Xvfb-wrapped headed Chrome (no GPU) | no — blank |

The only path that works is the one the probe uses. CI integration
(Phase 5 of the plan) cannot use the obvious "Playwright + headless
Chromium" recipe. Three options outlined in the plan:

- Software Vulkan (Lavapipe) inside Xvfb — slow but real
- Runtime export of a WebGPU readback path
  (`canvas` surface with `COPY_SRC`, expose `_captureCanvas`)
- Skip pixel capture in CI; rely on trace-only assertions there
  + local headed runs for visual checks

`locator.screenshot` also has a quieter failure mode: on a
continuously-redrawing canvas the stability check never resolves and
the call times out. The probe catches the timeout and records it as
`canvas_error` rather than crashing, but if you're iterating and
don't need PNGs, just pass `--no-canvas`.

See the memory note `browser_wasm_test_capture.md` for additional
detail, and the Phase 0 doc
[`2026-05-25-pong-browser-diagnosis.md`](../status/2026-05-25-pong-browser-diagnosis.md)
for how this was discovered.

## Diffing outputs

`compare.py` provides two diagnostic diffs. Both exit `0` on match,
`1` on divergence, `2` on usage error — usable in pipelines but
intended for human reads.

```bash
# Diff two trace.txt files (after filtering startup noise lines)
python3 tools/browser-test/compare.py traces \
    runs/glaiel_Pong/trace.txt /some/baseline/trace.txt

# Diff two PNGs using the same algorithm verify_output.py uses
python3 tools/browser-test/compare.py images \
    runs/glaiel_Pong/canvas/t01.png runs/glaiel_Pong/canvas/t03.png \
    --tolerance 8 --max-outliers 1000
```

Image comparison delegates to `verify_output.compare_images` —
sharing that helper keeps the browser harness and `ruffle-tests/`
aligned on tolerance/outlier semantics.

## Stand-alone server

If you just want a local server on `docs2/` (e.g. to poke the page
in your own browser), `serve.py` runs the same one the probe uses:

```bash
python3 tools/browser-test/serve.py
# → http://127.0.0.1:<auto-port>
# Ctrl-C to stop
```

Bound to 127.0.0.1 only.

## Gotchas

- **`probe.py` was originally planned as `inspect.py`**. The plan
  document still calls it `inspect.py`. It was renamed because
  `inspect.py` shadows Python's stdlib `inspect`, which Playwright
  imports internally — leading to a misleading "playwright not
  installed" error at import time.
- **`--screenshot-timeout-ms` doubles as the context default for
  most other waits.** If you set it very short (under ~3000), other
  page operations (`wait_for_function`, etc.) may also time out.
  Use `--no-canvas` instead when you want fast iteration.
- **A failed `goto`/Module-ready wait still writes outputs.** If
  the WASM module never loads, the probe writes `console.json`,
  `page_errors.txt`, and `summary.txt` (with
  `module_loaded: False`) so you can see why. The browser then
  closes (unless `--keep-open`).
- **Auto-clicked `#btn-run`** happens once, ~0–500ms after
  Module-ready. Demos that need a user gesture to start audio still
  start fine — the auto-click is itself a synthetic gesture for
  Chrome's autoplay policy.
- **Headed mode steals the foreground**. The Chrome window pops on
  top of whatever else you're doing during the run. `--keep-open`
  is useful, but be aware the window will steal focus when it opens.

## Phase outlook

What's in this Phase 1 cut:
- Reusable harness (`serve.py`, `probe.py`, `compare.py`)
- Diagnostic-only; no determinism, no assertions, no CI

Coming in subsequent phases (see the plan for full details):
- **Phase 2** — `_stepSWF(n)` runtime export for byte-deterministic
  tick stepping
- **Phase 3** — Trace-only assertion runner against `output.txt`
- **Phase 4** — Per-frame PNG diff vs the headless-graphics baseline
- **Phase 5** — CI integration

If you find yourself reaching for state that this harness can't see,
that's a signal to bring forward whichever later phase would expose
it — not to grow `probe.py` into something it isn't.
