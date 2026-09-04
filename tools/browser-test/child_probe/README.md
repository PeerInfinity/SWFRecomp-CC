# Browser-WASM loaded-child probe

Builds and runs a **browser-WASM (graphics / WebGPU)** page for a regression
fixture whose parent SWF `loadMovie`s a child SWF, and reports what the runtime
actually did — trace lines diffed against the fixture's native oracle, plus the
rendered frame read back off the GPU.

```bash
bash tools/browser-test/child_probe/build_child_probe.sh avm1_parent_child_render
python3 tools/browser-test/child_probe/run_child_probe.py avm1_parent_child_render --pixels
python3 tools/browser-test/child_probe/pixcmp.py \
    /tmp/swf_child_probe/out/avm1_parent_child_render.cap3.png \
    ruffle-tests/tests/swfs/regression/avm1_parent_child_render/output.expected.png
```

`OUT_ROOT` (default `/tmp/swf_child_probe`) holds the generated C, the built
page and the captures. Re-running the build script reuses `gen_<fixture>/`;
delete it to force a recompile.

## Why it exists

Neither existing path can do this on its own:

* `SWFRecomp/scripts/build_test.sh … wasm --graphics` is the sanctioned
  browser-graphics demo build, but it has **no child-SWF support** — it
  recompiles a single `test.swf` and never defines `HAS_CHILD_MOVIES`, so
  `swf.c` compiles NULL-returning `findMovieEntry`/`getMovieEntryAt` stubs.
* `verify_output.py` knows the whole child walk (`find_child_swfs`, the
  per-child `char_id_base` stride, string-id rebasing), but its `--wasm` build
  is **NO_GRAPHICS** (`swf_core.c`) — a different frame loop from the browser's
  (`swf.c`), which is exactly where browser-only gaps live.

The build script takes the generated C from the first and the link recipe from
the second.

## Two traps this harness exists to avoid

1. **A Playwright screenshot of the WebGPU canvas comes back blank white under
   WSLg even while the page renders correctly.** The GPU readback of the same
   frame (`dbgCaptureBoard`, from `display_bridge.c`) shows the real image.
   Never read a blank canvas screenshot as "nothing rendered" — use `--pixels`.
2. **A regression fixture is a few frames long** and its loop has exited long
   before a screenshot can fire. `--pixels` first calls `dbgSetFrameCapMs` to
   stretch each frame out (`--cap-ms`, default 700).

And one that bites the comparison rather than the capture: in Pillow >= 10,
`Image.getbbox()` on an RGBA image is **alpha-only by default**, so
`ImageChops.difference(a, b).getbbox()` returns `None` for two fully-opaque
images no matter how different their colours are. `pixcmp.py` compares RGB per
pixel instead.

WSLg Chrome is SwiftShader. Fine for these functional and rendering-correctness
probes, **never** for frame rates (CLAUDE.md; real-GPU recipe in
`tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`).

## What it was built for

`SWFRecompDocs/status/browser-wasm-loaded-child-parity.md` — the measurement
that showed browser-WASM never loaded a child movie at all, and the two fixes
that closed it.
