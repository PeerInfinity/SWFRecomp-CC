# Build/Test Mode Consolidation Plan

**Created:** 2026-07-23
**Status:** Planning — Phase 1/2 approved in principle, Phases 3–5 are investigations.

## Background: mode audit findings (2026-07-23)

The runtime ships three test/build modes plus the browser target:

| Mode | Frame loop | Renderer | Defines | Who uses it |
|------|-----------|----------|---------|-------------|
| `no-graphics` | `swf_core.c` | none | `NO_GRAPHICS` | default `verify_output.py`, `build_test.sh`, all WASM console-test builds, in-browser-recomp demo, `profile_game_native.sh` isolation mode, CMake option |
| `graphics` | `swf.c` | offscreen Dawn (native) | `USE_WEBGPU OFFSCREEN_RENDER` | `verify_output.py --mode=graphics`, `run_image_tests.py`, divergence harness |
| `graphics-headless-legacy` | `swf_headless.c` | offscreen Dawn | `NO_GRAPHICS HEADLESS_GRAPHICS USE_WEBGPU` | **nobody** (dead since 2026-05-12) |
| browser-WASM (not a test mode) | `swf.c` | Dawn→WebGPU via emscripten | `USE_WEBGPU` only | shipped games/demos |

Key audit facts driving this plan:

- **Result parity is essentially complete.** Diffing every per-test result across
  all suites (avm1 711, avm2 1215, gnash 403, shumway 92, regression 70) in the
  2026-07-23 baselines: pass/fail status AND line-level match counts are
  identical between `no-graphics` and `graphics` for every test except
  **`place_and_remove_object_insane_test`** (from_gnash/misc-ming.all: passes
  no-graphics, fails graphics). The only other strict-parity item is the
  `case-v6` CI flake (graphics mode, intermittent).
- **Historical divergence was real and bidirectional** (May 2026 Phase 2 push):
  graphics-only failures (the whole swf.c parity backlog, e.g. actionscript.all
  0/190 at launch) and no-graphics-masked bugs (`tag_stubs.c::tagDefineSound`
  differing from real `audio.c`; playbook gotcha #15 root-stopped exit gate).
  Both directions have since been driven to the single divergence above.
- **CI cost is the dual-run.** Last 30 days: 147 no-graphics + 105 graphics
  full-suite result commits; wall time ~19–20 min (no-graphics) vs ~28–30 min
  (graphics), 30 shards each. Graphics is the flakier mode (case-v6,
  apt/Vulkan shard flakes) but is also the production frame loop browsers run.
- **`graphics-headless-legacy` is dead.** Zero unique callers since
  `run_image_tests.py` migrated to `--mode=graphics` (commit `c0def42f`,
  2026-05-12). Its `results_headless.json` has been stale since 2026-04-02.
  The graphics-native plan's Phase 3 already scopes its deletion, gated on
  "≥1 month with zero unique callers" — that clock has now run 2+ months.
- **`NO_GRAPHICS` (the define) is load-bearing far beyond testing** and is NOT
  being retired: ~450 references across 16 runtime files, many deliberately
  widened to `NO_GRAPHICS || OFFSCREEN_RENDER` so the symbol now selects the
  shared "real frame-loop machinery" for both native modes. The no-graphics
  *build mode* stays; only its CI cadence changes.

---

## Phase 1 — Delete `graphics-headless-legacy` / `HEADLESS_GRAPHICS`

Execute the already-scoped Phase 3 of `graphics-native-test-mode-plan.md`.

Deletion checklist:

1. `SWFModernRuntime/src/libswf/swf_headless.c` (1183 lines).
2. `HEADLESS_GRAPHICS` gates: simplify every `#if` that mentions it
   (`tag_stubs.c` ~17 sites, `swf_core.c`, `tag.h`, `wasm_wrappers/main.c`,
   scattered singles). Each becomes the remaining condition
   (usually plain `NO_GRAPHICS`). `grep -rn HEADLESS_GRAPHICS` must end empty
   (excluding docs).
3. `SWFModernRuntime/CMakeLists.txt`: drop `option(HEADLESS_GRAPHICS ...)` and
   its branch.
4. `ruffle-tests/verify_output.py`: remove `mode="graphics-headless-legacy"`
   branch and the deprecated `--headless` alias. Decision: `--headless` should
   **error with a pointer to `--mode=graphics`** rather than silently remap —
   the two modes' results files differ and silent remapping would hide stale
   muscle memory.
5. `SWFRecomp/scripts/build_test.sh`: remove the `--headless` branch.
6. `.github/workflows/ruffle-tests.yml`: remove `graphics-headless-legacy`
   from the mode input docs and the `results_headless` stem case; delete the
   stale `results_headless*.{json,md}` files from `avm1/_results/` (and any
   other suite that has them) in the same commit.
7. Docs: mark Phase 3 done in `graphics-native-test-mode-plan.md`; sweep
   `SESSION_START_GUIDE.md` / playbook for `--headless` references.

Verification: local single-test run in both surviving modes
(`--test=place_and_remove_object_insane_test` is a good double-duty pick),
then full CI in **both** modes (this touches shared build config), zero
regressions expected.

## Phase 2 — CI cadence: graphics per-change, no-graphics weekly canary — **DONE 2026-07-23**

Implemented: policy flipped in `CLAUDE.md` + `.claude/pipeline-handoff.md`;
weekly canary added as `.github/workflows/weekly-no-graphics.yml` — a thin
`workflow_call` caller with a Sunday 08:00 UTC cron, so `ruffle-tests.yml`
never runs with the empty `inputs` context a direct `schedule:` trigger
would produce. Reversion criterion documented in the workflow header.
Verified by a manual `workflow_dispatch` of the canary (full no-graphics
suite green through the caller path).

Rationale: with parity at 1 known divergence, the second full-suite run per
shared-runtime change buys almost no signal. Graphics is the production
(browser) frame loop, so it becomes the per-change gate; no-graphics becomes a
scheduled canary that exists to catch mask-type divergences (the
gotcha-#15 class) late rather than never.

1. **Policy flip** in `CLAUDE.md` + `.claude/pipeline-handoff.md` §"Build mode":
   - Default per-change CI mode: `graphics`.
   - Run `no-graphics` per-change **only** when the change touches
     no-graphics-only code: `swf_core.c`, `tag_stubs.c`, or `#ifdef
     NO_GRAPHICS` arms that lack `|| OFFSCREEN_RENDER`.
   - "Both modes" remains the when-in-doubt fallback, no longer the default
     for shared runtime code.
2. **Weekly no-graphics schedule**: `ruffle-tests.yml` is dispatch/call-only
   today. Add a `schedule:` trigger (one cron, e.g. Sunday after the
   `build-dawn.yml` warmer) that runs mode=no-graphics across all suites, or
   add it to `all-tests.yml` if that's where suite fan-out lives. The run
   publishes `results.json` baselines as usual so drift is visible in the
   normal diff reports.
3. **Reversion criterion** (write into the workflow comment): if the weekly
   canary ever reports a divergence the graphics run missed, restore
   per-change dual runs and reopen this plan.
4. Note the flake asymmetry explicitly in the policy text: a red graphics run
   needs the case-v6 / apt-flake triage step before being read as a
   regression (see `graphics-ci-aptget-flaky-shards` and CURRENT_STATUS).

Savings estimate: ~147 no-graphics full-suite runs/month drop to ~4–5.

## Phase 3 — Investigate `place_and_remove_object_insane_test` — **DONE 2026-07-23**

**Root cause found and fixed.** Not a `tag.c` bug as the May triage guessed —
the survives-rewind machinery in `tag.c` is compiled into both native modes.
The divergence was in the frame loops: `swf_core.c` (~line 1257,
TRANSFORMED_BY_SCRIPT_WRAP_BACK Phase 4) *promotes* a natural backward wrap
that leaves stale later-frame display-list entries into an implicit backward
goto (`goto_from_action=1; g_natural_wrap_cleanup_pending=1`), routing frame-0
re-placement through the catch-up path's survives_rewind semantics. `swf.c`
never got that promotion — its light wrap path re-placed non-survivors fresh,
resetting script-written `_x` (mc_blue 60→0) and skipping the depth rename
(mc_black → mc_black_name_changed).

Fix: ported the promotion block to `swf.c` immediately before its catch-up
loop, gated `#ifdef OFFSCREEN_RENDER` — browser-WASM deliberately keeps the
light wrap path its restart flows were tuned on (Snake game-over→restart; see
the comment above `ng_display_clear_after`) pending Phase 5 probe coverage.
Verified locally in graphics mode: target test passes; 11 sensitive neighbors
(loop_test family, place/replace/reverse-execute tests,
displaylist_depths_test8, avm1/looping, avm1/goto_frame_number, the shumway
FSCommand:quit fuzz test) all match their baselines.

The last real mode divergence (no-graphics PASS, graphics FAIL; CLAUDE.md calls
it a shared-code bug). Goal: fix it or formally accept it, so "graphics is a
strict superset oracle" becomes true before Phase 2's cadence flip fully lands.

1. Repro: `python3 ruffle-tests/verify_output.py
   --test=place_and_remove_object_insane_test --mode=graphics --diff --verbose`
   (test lives in from_gnash/misc-ming.all — pass the suite's `--tests-dir`).
2. Diff against the no-graphics run of the same test; use the playbook's
   parity-diagnosis flow (no-graphics as oracle, divergence tracer if the
   trace order differs).
3. Check the graphics-native plan/playbook history — this test is mentioned in
   the Phase 2 docs; prior triage notes may already localize the arm.
4. Outcome: either a fix (likely a mis-widened gate in `tag.c` place/remove
   handling, given the test name) or an entry in the accepted-diffs doc with
   the mechanism explained. Also re-check `case-v6` while in the area and
   document its flake mechanism if reproducible.

## Phase 4 — Native graphics capability assessment — **DONE 2026-07-23**

**Deliverable:** `SWFRecompDocs/reference/native-windowed-graphics-assessment.md`
(capability matrix + per-gap costs). Findings: all native-windowed source
(`render_webgpu.c`, `sdl3webgpu.c`, `swf.c`, `tag.c`, `flashbang.c`) compiles
clean — no source rot — but **no build system produces a windowed binary
today**: `build_test.sh --graphics` native omits the SDL3/Dawn link + sdl3webgpu.c,
and the CMake `USE_WEBGPU=ON` native path fails to configure because a
`.gitignore` `build_*/` rule swallowed SDL3's vendored `build_config/` templates.
Mouse input already reaches AVM1 in a window; keyboard does not (native pumps are
ESC-to-quit only) and AVM2 gets no live input. Audio is silent natively (only a
Web Audio sink; native stub empty). Native pacing is vsync-only (SWF fps ignored).
Reaching a playable native windowed AVM1 game is ~Medium: build wiring (S) →
keyboard (S) → native SDL3 audio sink (S-M), all finishing wiring the
offscreen/browser paths already prove out — not design work.

**Follow-up (flashbang verdict — delete/fold):** `flashbang.c` is a second,
older SDL3-GPU renderer that duplicates the pipeline in a different API, carries
a shader set that diverged 2026-02 (WGSL updated, its GLSL frozen at 2025-11),
needs a Vulkan + `glslc` toolchain `render_webgpu` avoids, has weaker input, and
has never had CI. `render_webgpu.c` already serves all three surface configs
(offscreen / browser canvas / native SDL window). Recommend a cleanup task:
repoint the CMake default `else()` arm at `USE_WEBGPU` and delete
`src/flashbang/` + its shaders. (Not done here — Phase 4 is assessment-only.)

Question: can this repo run graphics in *native* builds, or has graphics
testing been wasm-only?

Already known (record in the assessment doc, then verify the open parts):

- Graphics **testing is native**, not wasm: `--mode=graphics` compiles with
  native gcc + offscreen Dawn (`OFFSCREEN_RENDER`) and has since 2026-05.
  All 1000+ graphics-mode suite runs and the image tests are native binaries.
- The open question is **windowed/interactive** native playback: everything
  native renders offscreen (screenshots/traces); actually *playing* a game
  with a window has only been done in browser-WASM.

Investigate and write up:

1. What `src/flashbang/flashbang.c` + `src/flashbang/shaders` are (SDL-based
   player? historical?), whether it still builds, and against which loop.
2. Whether `render_webgpu.c` has (or is structured to accept) a native
   swapchain/window surface path vs. the offscreen texture path.
3. Input: native input pump status (`input_events_pump_tick` exists for
   OFFSCREEN_RENDER replay — what would live keyboard/mouse need?).
4. Audio: `audio_output_web.c` is web-only; identify what a native sink needs
   (SDL3 audio is the obvious candidate if flashbang vendors SDL).
5. Deliverable: a capability-matrix doc (target × mode × window/offscreen ×
   input × audio) and a rough cost estimate for a windowed native player, so
   we can decide if it's ever worth building.

## Phase 5 — Browser-WASM branch coverage audit ("the wasm-branch index")

History: a main source of bugs has been shared runtime code with no
browser-WASM arm (or a stale one) — the `#if NO_GRAPHICS || OFFSCREEN_RENDER`
gates whose `#else` is missing or wrong. Two prior indexing attempts —
`browser-wasm-testing-plan.md` (2026-05-25) and `wasm-probe-suite.md`
(2026-05-27) — plus a long tail of individual memory entries
(removemovieclip-noop, xmouse-root-only, frame-func-rerun, ...). Bugs kept
surfacing after both. The hypothesis "by now we caught most of them" is
testable.

1. **Mechanical gate inventory** (new script, `tools/gate_inventory.py`):
   parse `action.c`, `tag.c`, `swf.c`, `libswf/*.c` for every preprocessor
   region mentioning `NO_GRAPHICS` / `OFFSCREEN_RENDER` / `__EMSCRIPTEN__`;
   for each site classify which of the three execution contexts
   (no-graphics, graphics-native, browser-WASM) get real code vs. nothing.
   Today's raw counts: `OFFSCREEN_RENDER` 133 in action.c / 122 in tag.c / 38
   in swf.c; `NO_GRAPHICS` ~450 repo-wide — so expect an inventory of a few
   hundred sites, most benign.
2. **Triage output**: table of sites where the browser-WASM context falls
   into an empty/absent arm, annotated by hand (intentional — e.g. offscreen
   readback — vs. suspicious). The suspicious list is the actual "index we
   kept failing to build", now derived instead of hand-maintained.
3. **Trend check**: `git log --grep` for browser-wasm-branch fix commits per
   month since May; if the rate has genuinely decayed, that supports the
   "mostly caught" hypothesis; the inventory says how much surface remains.
4. **Ratchet (optional)**: run the inventory in CI and fail if the
   suspicious-site count grows without a doc update — this makes the index
   self-maintaining instead of rotting like the two prior attempts.
5. Cross-link with the browser-WASM testing plan: the inventory prioritizes
   which probe SWFs (wasm-probe-suite) would pay off first.

**Status 2026-07-23 — tooling half DONE, triage pending.** `tools/gate_inventory.py`
(steps 1 and 3) + the generated `SWFRecompDocs/reference/browser-wasm-gate-inventory.md`:
415 gate sites, **157 where browser-WASM compiles nothing while a native config
does** (action.c 61, tag.c 49); `--verify-cpp` cross-checks 1014 (site, config)
line counts against `cpp` with 0 mismatches. The trend check says the fix-rate
decay is an *exposure* artifact — the per-game-debug-commit hit rate peaked at
0.92 in the last full week of AVM1 browser debugging — so "we caught most of
them" is unsupported. Remaining: step 2 (fill the empty `triage` column, needs
deep runtime context) and step 4 (ratchet — deferred until triage exists,
otherwise it just pins 157).

**Status 2026-07-23 (later) — triage DONE; Phase 5 complete.** All 157 flagged
sites classified (see the inventory's "Triage pass" tail section):
98 `intentional-paired`, 21 `intentional-model` (the native-vs-browser
sprite-advance model split), 17 `intentional`, **21 `suspicious`** in 10
behavioral clusters (transform setters, TextFormat-from-field, GetProperty
display-truth reads, typeof refinement, delete guard, `_alpha` cxform read,
drag/_droptarget, var→textfield sync, focus rect, ByteArray charset). None
promoted to `bug` without a reproducing SWF — the 10 clusters are the
priority list for `wasm-probe-suite`. The tool now preserves triage cells
across regeneration (`_harvest_triage`). Ratchet decision: with triage done,
a CI ratchet would pin "0 untriaged sites" — deferred until the probe suite
exists to give a failed ratchet an actionable meaning; regenerating the
inventory at session start when touching gated files is the interim practice.

## Sequencing

Phase 1 → Phase 2 in order (the cadence text should describe the
two-mode world, and Phase 1's CI verification wants the old dual-run policy
still in force). Phase 3 should land before or with Phase 2 (it's the last
blocker to "graphics is a superset oracle"). Phases 4 and 5 are independent
investigations, any time.

## Open questions

- Weekly canary day/time; whether the schedule lives in `ruffle-tests.yml`
  or `all-tests.yml`.
- Whether the regression suite (fast, 70 tests) should keep running in both
  modes per-change regardless — it's cheap and hand-written to probe exactly
  the divergence-prone machinery.
- Whether Phase 5's ratchet is worth CI minutes vs. a standing
  session-start check.
