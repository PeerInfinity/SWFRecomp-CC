# Browser-WASM Testing Infrastructure — Plan

**Document Version:** 1.0
**Created:** 2026-05-25
**Status:** Planning; no implementation yet.

Existing test infrastructure (`ruffle-tests/verify_output.py`) covers
two build modes well — **trace** (`swf_core.c`, `NO_GRAPHICS`) and
**graphics-native** (`swf.c` + offscreen Dawn, `OFFSCREEN_RENDER`) —
but the third mode SWFRecomp ships, **browser-WASM** (`-DUSE_WEBGPU`
only, no `NO_GRAPHICS`/`OFFSCREEN_RENDER`/`HEADLESS_GRAPHICS`), has no
automated tests. Symptoms have already surfaced (Pong loads but the
preloader hangs in-browser even though the headless-graphics build
passes the same checkpoint cleanly), and there's no way today to tell
whether a new runtime change has broken an unrelated browser-WASM
demo. This plan stands up that missing test layer using Playwright,
phased so the first useful artifact (a diagnostic harness for one
demo) lands before any runtime changes.

## Table of contents
1. [Why this matters](#why-this-matters)
2. [What we know](#what-we-know)
3. [What we don't know yet](#what-we-dont-know-yet)
4. [Design decisions](#design-decisions)
5. [Phases](#phases)
6. [Open questions](#open-questions)
7. [Risks](#risks)
8. [Out of scope](#out-of-scope)

---

## Why this matters

Three concrete gaps in coverage:

1. **The browser is the only path that real users see.** The headless
   tests validate logic + rendering correctness against Ruffle, but
   they run a different `swf.c` arm. The browser arm has its own
   tick-loop / sprite-advance / input-handling code that nothing
   exercises today. The Pong "stuck preloader in browser, works
   headlessly" finding (2026-05-25) is direct evidence that the two
   arms can drift.
2. **No regression signal for runtime changes affecting browser-only
   paths.** Commit `b163380e2` ("stub
   `ng_depth_has_pending_finalize` for non-headless builds") was a
   linker fix discovered only because someone tried to build a
   browser-WASM demo for the first time in 11 days. Nothing in CI
   would have caught it earlier.
3. **Demo page is one of the project's public artifacts.** The
   `docs/` site links to ~150 browser-WASM demos. We have no way to
   tell, short of clicking each one, whether they still launch after
   a runtime refactor.

Three categories of failure the test layer should catch:

- **Doesn't load** — JS-side exception during `Module` init, missing
  WASM export, mis-wired audio, etc.
- **Loads but stuck** — the live Pong symptom: WASM runs, canvas
  mounts, preloader renders, but timeline never advances.
- **Loads but wrong** — runs to completion but rendered output or
  trace diverges from Ruffle / from the headless-graphics build.

## What we know

- Browser-WASM build uses `swf.c` with `-DUSE_WEBGPU` only. Neither
  `NO_GRAPHICS`, `OFFSCREEN_RENDER`, nor `HEADLESS_GRAPHICS` is
  defined. Most of `swf.c`'s tick-loop body (`advance_sprite_frames`
  at top, `advance_nested_sprite_frames` at end, fallback enterFrame
  flush) is gated `#ifdef OFFSCREEN_RENDER` and **does not run in the
  browser**. Sprite advancement in the browser is driven by a
  different mechanism (`targeted_sprite` static + recompiler-emitted
  inline frame-func calls; see MEMORY.md "MovieClip Timeline
  Control"). The Pong fix from this session (Option B,
  `placed_at_tick == g_tick_count` skip) is therefore vacuously inert
  in the browser path — the field is stamped by `tagPlaceObject2` but
  never read.
- The deployed JS bundle (e.g. `docs2/examples/glaiel/Pong/Pong.js`)
  is Emscripten output with `runSWF` as the main async entrypoint
  (see `demo.html` ~line 637: `Module.ccall('runSWF', null, [], [],
  {async: true})`). `printf` lands in `console.log`. The canvas is a
  standard DOM `<canvas>` element, set up in `demo.html` and passed
  via `Module.canvas`.
- Determinism on the SWF side is already wired: `MOCK_DATE_TIME`
  compile-time macro seeds Date/Math.random; `verify_output.py`
  defines it on every gcc invocation. The same macro is set by
  `build_test.sh` for WASM builds (verify in Phase 1).
- Playwright supports WebGPU in Chromium with `--enable-unsafe-webgpu
  --use-angle=swiftshader` (or `--use-angle=vulkan` on newer drivers).
  GitHub Actions `ubuntu-latest` runners can run this with
  Playwright's bundled Chromium; the latency cost is the SwiftShader
  software path, ~5-10× slower than native GPU.

## What we don't know yet

These need a Phase 0 spike (probably ~30 minutes of one-off poking)
before the rest of the plan is settled:

- **Does `_root.play()` reach the right MC in the browser when
  called from a nested sprite?** The headless-graphics fix
  (`6fe6fb1a2`, "Fix `_root.play()/stop()` ignoring root receiver in
  graphics-native") added a `mc == &root_movieclip` short-circuit in
  `actionCallMethod`'s "play"/"stop" arms. That fix was for the
  `OFFSCREEN_RENDER` arm. The browser arm (`!NO_GRAPHICS &&
  !OFFSCREEN_RENDER`) has a separate code path — does it have the
  equivalent fix? If not, that's likely why Pong hangs in-browser:
  sprite_9 frame 2 calls `_root.play()` but the call no-ops.
- **What does `printf` from `swf.c`'s browser-arm sprite-advance
  code look like in-page?** Need to confirm Emscripten flushes to
  `console.log` reliably, not buffered until exit.
- **Is the `MOCK_DATE_TIME` define propagated to the browser
  build?** `build_test.sh` line ~283 (`emcc … -DUSE_WEBGPU
  ${EXTRA_DEFINES} …`) accepts an `EXTRA_DEFINES` env var; need to
  confirm the demo build pipeline sets it.
- **WebGPU availability under headless Chromium.** Recent Chrome
  (v131+) supports WebGPU headless without flags on Linux when
  ANGLE/Vulkan is present. Need to verify on the actual
  `ubuntu-latest` runner image. Fallback is `--use-angle=swiftshader`,
  which works but is slow.
- **`Module.canvas.toDataURL()` byte-determinism.** WebGPU rendering
  can produce slightly different pixels on different drivers even
  with SwiftShader. Need a test run to see if the same input + same
  Chromium binary on the same runner gives bit-identical PNGs across
  invocations. If not, the graphics tests need tolerance from the
  start (loose `--tolerance N`, `--max-outliers N` à la
  `verify_output.py`).

## Design decisions

### Playwright vs alternatives

**Playwright** chosen over:

- **Puppeteer**: maintained but less active than Playwright; same
  underlying Chromium control; Playwright has better waiting
  semantics (`waitFor*` family) and bundles its own Chromium
  download for cross-machine consistency.
- **Selenium**: heavyweight, no advantage for headless WASM/canvas
  work, slow to spin up.
- **Raw `chromium --headless`**: you'd reinvent the page-lifecycle /
  console-capture / screenshot wrappers Playwright already provides
  well. Worth ~zero engineering payback.

One Playwright-specific gotcha worth noting: `page.request`
interception can be used to inject a different WASM per-test
(useful for matrix runs across builds). Not needed Phase 1 but
helpful for Phase 5.

### Node vs Python harness

Playwright has first-class Node and Python bindings. The rest of the
project's test infrastructure (`verify_output.py`,
`tools/divergence/`) is **Python**. Recommend matching: use
Playwright-Python so the harness can share helpers (image comparison,
trace filtering) with `verify_output.py` and the divergence harness.

Cost: an extra dependency (`playwright` python pkg + bundled
Chromium download, ~150 MB). One-time setup; CI caches it cheaply.

### Tick determinism: synthetic step vs wall-clock

Two ways to make browser tests deterministic:

- **Synthetic step**: add a new runtime export `_stepSWF(n_ticks)`
  that advances exactly `n_ticks` then yields. Build with
  `-DBROWSER_TEST_MODE` (or similar) to enable. Tests call it from
  `page.evaluate()`. **Pros**: byte-identical to headless tests at
  the same tick count; assertions can be exact. **Cons**: adds a new
  build flag + small runtime branch; demos in production still use
  the existing autonomous `runSWF`.
- **Wall-clock with `page.waitForTimeout()`**: just let the demo
  run for N ms, capture state at fixed wall-clock points. **Pros**:
  no runtime changes. **Cons**: not byte-deterministic across
  runners (CPU speed varies); frame-rate jitter; hard to assert on
  exact trace sequences.

**Recommendation: synthetic step.** The byte-determinism is worth
the small build-flag cost. The wall-clock model can survive as a
"smoke test" tier for Phase 1 (diagnostic only, no assertions).

### Output formats

For symmetry with `tools/divergence/` and `verify_output.py`:

- **Trace output**: per-line `console.log` capture, filtered (drop
  Emscripten startup banner, drop `[HEAP]` lines), written to
  `runs/<demo>/trace.txt`. Diffable against existing `output.txt`
  expected files.
- **Image output**: `canvas.toDataURL()` decoded to PNG via Pillow
  in the harness, written `runs/<demo>/F0001.png`,
  `runs/<demo>/F0002.png`, etc. — same naming as
  `verify_output.py`'s `--mode=graphics` output for easy parity
  diffing against the headless-graphics baseline.
- **Console/error log**: full `page.on('console')` + `page.on('pageerror')`
  capture as `runs/<demo>/console.json`. Mostly for human debugging.

### Three baselines to compare against (Phase 4)

Per-test, pick one:

1. **Parity check against headless-graphics PNG**: most actionable
   early. If the same SWF + same build mode (graphics) produces
   different output in headless-Dawn vs browser-WebGPU, that's a
   real divergence worth chasing.
2. **Against Ruffle exporter PNG**: cross-runtime ground truth, but
   noisier (different rendering pipeline entirely).
3. **Against a frozen browser-WASM golden**: catches regressions,
   doesn't catch "we've always been wrong in this way." Use
   sparingly.

Default to (1). Add (2) selectively for demos that pass headless
but visibly look wrong in-browser (suggests the headless path is
also wrong but happens to match what we baselined).

## Phases

### Phase 0 — One-shot spike to characterize the Pong-stuck symptom
- No infrastructure yet. Run Playwright by hand against the
  deployed `docs2/examples/glaiel/Pong/`. Capture 5 seconds of
  `console.log`, snapshot the canvas once per second, write to
  `/tmp/pong-probe/`.
- Look for `script_2`-shaped trace output (the recompiler doesn't
  emit AS-level traces here, but if there's any `printf` from
  `actionCallMethod`'s "play" branch we'd see it). If no such
  output, instrument `actionCallMethod`'s receiver-lookup path
  temporarily with a `fprintf(stderr, ...)`, rebuild Pong, re-probe.
- **Goal**: one of four diagnoses (see "Why this matters" section's
  three categories, plus "WebGPU init failed"). Determines whether
  the browser bug is in the browser arm of the runtime or in
  page-side wiring.
- **Output**: a short follow-up doc in `SWFRecompDocs/status/` with
  the diagnosis, similar to the divergence-harness findings doc.
- **Time estimate**: 1-2 hours.

### Phase 1 — Diagnostic harness (no determinism, no assertions)
- New dir `tools/browser-test/`. Files:
  - `inspect.py` — Playwright-Python script. Args: `<demo-id>
    [--frames N] [--wall-clock-seconds N] [--out DIR]`. Defaults
    serve `docs2/` on a local port, open `demo.html?test=<id>`,
    capture for N seconds.
  - `serve.py` — small wrapper that picks a free port and starts
    `http.server` on `docs2/` (or whichever docs root).
  - `compare.py` — image / trace diff helpers, sharing as much as
    possible with `ruffle-tests/verify_output.py`'s helpers.
- Per-demo output: `tools/browser-test/runs/<demo-id>/trace.txt`,
  `console.json`, `t0.png`, `t1.png`, …, `t<N>.png`.
- No assertions yet. This is a tool for humans. Used immediately to
  bring up Pong (and any other "doesn't work in browser" demos).
- **Output**: a usage doc paralleling
  `SWFRecompDocs/guides/divergence-harness-usage.md`.
- **Time estimate**: ~half a day.

### Phase 2 — Synthetic step hook
- Add a new build flag (e.g. `-DBROWSER_TEST_MODE`) and a new
  export `_stepSWF(n_ticks)` to `swf.c`.
- The export takes over the tick loop: instead of `while(1) { tick;
  yield(0); }` (with ASYNCIFY), it runs the requested ticks then
  returns. State persists across calls.
- Add a new flag to `build_test.sh` (`--browser-test`) that sets
  this. `build_swf_batch.sh` learns to pass it through.
- **Behavioral guarantee**: a demo built with `--browser-test` and
  driven by `_stepSWF(N)` produces the same trace output as the
  same demo built with `--mode=graphics` (headless) and run for `N`
  ticks. This is the parity contract Phase 3 depends on.
- **Output**: build-flag documentation + a smoke test that `pong
  --browser-test` produces the same `F1..F3` trace lines as the
  headless equivalent.
- **Time estimate**: ~half a day plus some debug iterations.

### Phase 3 — Trace-only assertion runner
- Build each test demo with `--browser-test`.
- Playwright script:
  - Load page
  - Call `_stepSWF(<num_frames>)` via `page.evaluate()`
  - Gather all `console.log` (filtered)
  - Diff against `output.txt` (the existing expected output that the
    headless trace mode already compares against)
- Per-test output: `runs/<demo>/diff.txt`. Aggregate
  `runs/_summary.json` matching the structure of
  `ruffle-tests/.../_results/results.json`.
- Pick ~5 known-working trace demos for the initial smoke set; add
  the rest incrementally as they pass.
- **Time estimate**: ~half a day for the runner, then ongoing work
  to fix demos that don't match.

### Phase 4 — Graphics demo PNG capture + diff
- Same harness as Phase 3 but also capture `canvas.toDataURL()`
  per step.
- Pixel-diff against the headless-graphics PNG for the same demo +
  same tick number.
- Initial tolerance loose (`tolerance=8, max_outliers=many`);
  tighten over time.
- **Time estimate**: ~1 day, dominated by tolerance tuning.

### Phase 5 — CI integration
- New workflow file `browser-wasm-tests.yml` parallel to
  `ruffle-tests.yml`. Sharding similar to existing workflow.
- Action setup:
  ```yaml
  - uses: microsoft/playwright-github-action@v1
  - run: pip install playwright && playwright install chromium
  ```
- Chromium flags: `--enable-unsafe-webgpu --use-angle=swiftshader`
  (or whatever Phase 0 spike confirms works on `ubuntu-latest`).
- Results pushed to a `browser-wasm-results` branch matching the
  existing `ruffle-test-results` pattern.
- **Time estimate**: ~half a day if WebGPU works on the runner
  out-of-the-box; significantly more if Docker image is needed.

## Open questions

- **Should Phase 2's step hook persist in production builds, or
  only enabled by build flag?** If only build-flag, every test
  requires a separate build, doubling CI compile time. If
  production includes it (no-op when not driven by JS), there's a
  small binary-size cost and a chance of misuse. Recommend
  build-flag-only.
- **How granular should the synthetic step be?** `_stepSWF(1)`
  every-tick gives most flexibility but more JS round-trips. Bulk
  steps (`_stepSWF(30)`) are faster but harder to interleave with
  state inspection. Maybe both: `_stepSWF(N)` for bulk + an
  optional per-tick JS callback for fine-grained capture.
- **Does the harness drive `setInterval`/`requestAnimationFrame`
  callbacks correctly in step mode?** If the JS-side tick driver
  uses `rAF`, the synthetic step needs to either replace it or
  trigger it manually. Playwright can stub `requestAnimationFrame`
  via `page.evaluate()`.
- **Input event simulation.** Browser-mode interactive demos
  (most of the local_batch / glaiel SWFs) need mouse/keyboard
  input to progress beyond the menu. Playwright has
  `page.mouse.click()`, `page.keyboard.press()` etc. — works fine
  in principle but needs a per-test input script à la
  `verify_output.py`'s `input.json`. Out of scope for the initial
  phases.
- **Asset-loading races.** Some demos call `loadMovie()` /
  `loadSound()` against same-origin URLs. The Playwright-served
  `http.server` already handles these, but the test harness has
  no way to know "wait until all loads complete" — needs either a
  runtime export (`_swfReady`) or a heuristic timeout.

## Risks

| Area | Risk | Mitigation |
|---|---|---|
| WebGPU on CI | Runner doesn't have WebGPU enabled out of the box; tests pass locally and fail in CI | Phase 0 spike on the actual `ubuntu-latest` image; fall back to Docker image with known-good Chromium if needed |
| Determinism | `canvas.toDataURL()` produces non-bit-identical output across runs even on the same machine | Discover early in Phase 4; widen tolerance; worst case, fall back to "compare structural hashes" rather than pixel-exact |
| Browser-runtime divergence | The "browser arm" of `swf.c` has accumulated drift from the headless arm over many months; passing parity tests requires fixing real bugs in the runtime, not just the harness | Expected. The whole point is to surface these. Phase 1's diagnostic harness should reveal the worst offenders quickly. |
| Build-time blow-up | Each demo needing a separate `--browser-test` build doubles CI compile time | Cache `RecompiledScripts/` (already cached); only re-link the WASM with the new flag; should be ~30s per demo instead of ~2 min |
| ASYNCIFY overhead | `_stepSWF` needs to be ASYNCIFY-aware; could conflict with the existing async `runSWF` model | Phase 2 spike with one demo before committing to the design; if ASYNCIFY is awkward, switch to a fully-synchronous `runSWF_step` variant (no asyncify) |
| Maintenance | Yet another test infrastructure to keep in sync with `verify_output.py` and the divergence harness | Build Phase 1 to deliberately share `verify_output.py`'s comparison helpers (image_compare, trace filter). Don't fork. |

## Out of scope

- **Cross-browser testing** (Firefox, Safari). All initial tests
  run in Chromium only. Firefox WebGPU is still nightly-only;
  Safari WebGPU is shipping but in a different state. Add
  later if user demand warrants.
- **Mobile / touch input.** Same reason — Chromium-desktop only
  initially.
- **Audio rendering tests.** Hard to verify; depends on Web Audio
  output; needs an audio capture pipeline. Maybe later.
- **Network-dependent demos.** Any demo that fetches a remote
  asset (not just same-origin) is excluded — too flaky.
- **Performance regression tracking.** Could measure tick
  throughput in step mode, but that's a different concern;
  separate plan if/when needed.

## Concrete first deliverable

The smallest useful step is Phase 0 + Phase 1, plus the Pong
diagnosis doc. After those:

- `tools/browser-test/inspect.py <demo>` — exists, works locally.
- `SWFRecompDocs/status/2026-MM-DD-pong-browser-diagnosis.md` —
  documents *why* Pong hangs in browser, and the relationship (or
  lack thereof) to the OFFSCREEN_RENDER fix from this session.
- No CI integration, no determinism hook, no runtime changes yet.

From there, every subsequent phase has a clear value proposition:
Phase 2 enables exact assertions; Phase 3 gives a regression net
for trace demos; Phase 4 covers graphics demos; Phase 5 makes the
whole thing run automatically.
