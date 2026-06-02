# WASM Game Performance Profiling & Optimization Plan

**Created:** 2026-06-01
**Status:** Planning — investigation complete, no code written yet
**Owner direction:** Native-headless profiling first; in-browser HUD secondary.

## Motivation

We can now recompile full AVM1 games to WASM and run them in the browser. The
hope was that recompiled games would visibly outperform Ruffle, but no
difference has been observed in practice. This plan establishes how to *measure*
performance properly and *profile* the runtime to find inefficiencies worth
fixing.

## Phase 0 — Reframe the goal (the key finding)

**Both our runtime and Ruffle are capped at the SWF's declared framerate, so
wall-clock FPS looks identical regardless of how fast the engine is.**

The browser frame loop is frame-paced, not run flat-out
(`SWFModernRuntime/src/libswf/swf.c:217,1019-1023`):

```c
u32 frame_ms = app_context->fps > 0 ? 1000 / app_context->fps : 83;
...
double elapsed = emscripten_get_now() - frame_start;   // actual CPU work this frame
u32 sleep_ms = (elapsed < frame_ms) ? (frame_ms - elapsed) : 0;
emscripten_sleep(sleep_ms);                              // sleep off the rest
```

A Flash game declares e.g. 12 or 30 fps. As long as the per-frame CPU work fits
the budget (83 ms at 12 fps), both engines just hit the cap. The recompiler's
advantage only becomes *visible* as:

1. lower CPU%/battery per frame,
2. higher achievable FPS when uncapped, or
3. staying smooth on heavy frames where Ruffle drops below target.

**Therefore the metric that matters is per-frame CPU time (`elapsed`), not
observed FPS.** That value is already computed at `swf.c:1020` and currently
discarded — exposing it is the single highest-value measurement step.

## Investigation findings

### Build & profiling state
- All WASM builds are `-O2`, **no `-g`/`--profiling-funcs`**, with `-sASYNCIFY`
  + 64 KB async stack (`SWFRecomp/scripts/build_test.sh:320-362`). No LTO, no
  `-O3`. ASYNCIFY at -O2 instruments a large fraction of functions — real
  overhead in a hot interpreter.
- WASM has **stripped names**, so a browser CPU profile shows opaque
  `wasm-function[1234]` — unusable for attribution without a profiling build.
- **No FPS counter, frame-time HUD, or timing instrumentation exists** anywhere.
- The generated C is **portable and builds natively** via `verify_output.py`
  (gcc, `-O2`, `NO_GRAPHICS` or `OFFSCREEN_RENDER`,
  `ruffle-tests/verify_output.py:1790-1854`). We can profile the exact same
  runtime code natively with mature tools (`perf`, callgrind, `-pg`) and the
  wins transfer to WASM.

### Frame loop drive
- ASYNCIFY-based; `emscripten_sleep` between frames. `runSWF()` entry in
  `SWFRecomp/wasm_wrappers/main.c`. No `requestAnimationFrame` /
  `set_main_loop` — direct call + ASYNCIFY yielding.

### Candidate hot paths (from static reading; to be confirmed by profiler)
- **`child_mc_cache` linear scans** — O(n) up to 128 entries with
  `strlen`+`strncmp` per entry, hit on *every* variable/property resolution
  through a nested clip (`action.c:19877,19908`; ~30 scan sites). No name→MC
  hash.
- **Action queue drain** — O(n) scan **plus O(n) `memmove`** per dequeued entry
  (`action_queue.c:141-177`); multiple passes per frame.
- **Per-push string churn** — `utf8_to_u16()` mallocs a UTF-16 buffer for every
  dynamic string pushed (`action.c:200`); no interning.
- **`frame_func` runs every tick even when stopped** (`swf.c:688`).
- **Every opcode is a runtime function call** — no inlining / constant folding
  in codegen (`SWFRecomp/src/action/action.cpp:586-640`).

## Upstream merge: performance assessment

Per `upstream/MERGE-ANALYSIS.md`, the upstream `feature/objects-and-functions`
PRs contain ideas that map onto our hot paths — but the "merge" is a
re-architecture, not a code merge, with no firm date, and some pieces would
regress us.

**Upstream changes that target our actual bottlenecks:**

| Upstream change | Hot path addressed | Impact |
|---|---|---|
| String-ID interning (enum IDs, `str_table`/`str_len_table`) | `strcmp`/`strncmp` name lookups + `utf8_to_u16` malloc-per-push | **High** |
| Specialized arena allocators (objects/rbtrees/lists) — the item gating *their* merge | per-frame malloc/free churn | **High** |
| Red-black-tree property storage | linear `properties[]` scan on GetMember/SetMember | **Medium** (only wins for many-prop objects) |
| Stack-embedded function struct; `FUNC_TYPE_3` stack-arg ABI | ASFunction indirection / arg marshalling | **Low–medium** |

**Upstream changes that are NOT wins (or are risks) for us:**
- **Concurrent GC on a free thread + per-object read/write locks**
  (`OBJ_LOCK_READ/WRITE`): a correctness/memory feature, not a speed one. In
  single-threaded browser WASM the free thread doesn't apply (or forces
  `-pthread`/`SHARED_MEMORY`), and per-object locking adds per-access overhead.
  Our current simple refcounting is *lighter*. Treat as a potential regression
  to measure, not adopt.
- **Prelude-SWF AS2 standard library** (Math etc. moved from C to interpreted
  AS2): likely *slower* for us than our native-C builtins.

**Conclusion:** Steal the *ideas* — **string interning** and **pooled/arena
allocation** (and possibly faster property storage) — and apply them to our own
runtime incrementally, guided by the profiler. Do **not** wait for or depend on
the merge for performance, and do **not** adopt the concurrent-GC/locking or
AS2-prelude-stdlib pieces for perf reasons.

## The plan

### Phase 1 — Native headless profiling harness (workhorse)

1. Add a profiling build mode to `verify_output.py` / `build_test.sh`: compile a
   full game native, `NO_GRAPHICS` (or `OFFSCREEN_RENDER` if rendering must be
   exercised), `-O2 -g -fno-omit-frame-pointer`, capped at a fixed `MAX_FRAMES`
   with a deterministic input script (reuse existing `MOCK_DATE_TIME` seeding so
   runs are byte-identical).
2. Profile with `perf record`/`perf report` and/or
   `valgrind --tool=callgrind` (exact call counts). Output: a ranked
   function-level hot-path report on the actual runtime code.
3. **First concrete run:** Doodle Jump, ~500 deterministic frames, callgrind →
   ranked report. Determines whether cost is the AVM1 interpreter, rendering,
   allocation, or queue management — and grounds everything else.

### Phase 2 — In-browser numbers (secondary) — DONE (HUD + uncapped)

Implemented as a self-contained `EM_JS` hook in `swf.c` (`swf_perf_report`,
browser-only, called once per rendered frame in both the main loop and the
post-quit drain loop):
- **Frame-time/headroom HUD overlay** — a fixed overlay (created by the hook
  itself, no HTML-template change) showing per-frame CPU time mean / p95 / max,
  headroom % of the FPS budget, and the **max sustainable FPS** (`1000/mean`).
- **Uncapped benchmark mode** — skips the frame-pacing `emscripten_sleep` so the
  loop runs flat-out, giving an apples-to-apples max-FPS number vs Ruffle.

Usage (works on `docs/demo.html` and any page hosting a graphics WASM build):
- Key **`P`** toggles the HUD; key **`U`** toggles uncapped mode.
- URL **`?perfhud=1`** shows the HUD at load; **`?perfbench=1`** loads in uncapped
  mode with the HUD on.

Still optional / not done: a `--profiling-funcs` named WASM build to confirm
native findings hold under ASYNCIFY/WASM; a side-by-side Ruffle benchmark toggle
on `demo.html`.

### Phase 3 — Optimize (profiler-driven, ordered by impact)

Free experiments first (no code changes):
- Try `-O3 -flto`.
- Shrink ASYNCIFY instrumentation via an `ASYNCIFY_ONLY`/allowlist.
- Measure both with the Phase-1/2 harness.

Then algorithmic hot spots — **borrowing the upstream ideas independently of the
merge**, one change at a time, re-benchmarked after each:
- String interning for names (removes `strcmp` + `utf8_to_u16` malloc per access).
- Pool/arena for ActionVar strings/objects.
- Name→MC hash to replace the `child_mc_cache` linear scan.
- Better action-queue structure (drop the O(n) `memmove`).

## Open questions to resolve before Phase 3

- Does our fork already route allocations through **o1heap**? (`MERGE-ANALYSIS.md`
  Part 6 says "Local has o1heap integration.") This changes how much a custom
  pool buys us.
- Does the `frame_func`-every-tick behavior (`swf.c:688`) actually show up as
  cost in the profile, or is it cheap when stopped?

## Status log

- 2026-06-01: Plan created. Investigation complete.
- 2026-06-01: Phase 1 harness built — `SWFRecomp/scripts/profile_game_native.sh`
  (native, `-O2 -g`, `MAX_FRAMES`, deterministic `MOCK_DATE_TIME`; no-graphics
  and graphics/OFFSCREEN_RENDER modes). First callgrind profile of Doodle Jump
  (500 frames, NO_GRAPHICS) done. **Result: ~67% of all instructions go to
  object property-name lookup** (`prop_name_match` 37%, `getProperty` 14%,
  `findPropertyRaw` 13%), plus ~10% libc string-compare and ~9% UTF/alloc under
  it. Confirms the plan's hypothesis — string interning + a real property map is
  the highest-value fix. Full writeup:
  [wasm-game-performance-profiling-results-2026-06-01.md](wasm-game-performance-profiling-results-2026-06-01.md).
