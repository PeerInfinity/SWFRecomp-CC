# WASM Game-Debugging Session Start Guide

Read this at the start of any session whose goal is **improving how a real
flasharchive / glaiel game runs under SWFRecomp** (browser-WASM graphics or the
headless graphics-native build it shares code with).

This is the game-debugging counterpart to
`ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md` (which covers the
trace-test suites). Where that guide is about pass-rate on small AVM1 trace
tests, this one is about finding and fixing where a full game diverges from
Ruffle/Flash.

**The strategy in one sentence:** run the *divergence harness* to find where a
game disagrees with Ruffle, fix the divergences that reproduce **headlessly**
first (no browser, no human in the loop), and only escalate to the browser
harness / manual-test loop for issues that genuinely require interaction or
browser-only code paths.

---

## 1. The corpus and where the games are

| Corpus | Source SWFs | Deploy to (namespace) |
|---|---|---|
| flasharchive | `~/CC/flasharchive/*.swf` (~58 games, names with spaces) | `docs2/examples/flasharchive/*` (namespace `flasharchive`) |
| glaiel | `~/CC/glaiel/swfs/*.swf` (~50 games) | `docs2/examples/glaiel/*` (namespace `glaiel`) |

Deploy each corpus into its own namespace — flasharchive games to
`docs2/examples/flasharchive/`, glaiel games to `docs2/examples/glaiel/`. (The
`local_batch` namespace was only used for an initial throwaway batch; don't
deploy debugging targets there.)

`.fla` source (ActionScript, inspectable but not recompilable) lives under
`~/CC/glaiel/` — see the AS-extraction recipe in
`SWFRecompDocs/status/2026-05-24-divergence-harness-findings.md`.

### Scope: AVM1 only — exclude AVM2/AS3 SWFs

The recompiler and the divergence tracer are **AVM1**. AVM2/AS3 SWFs won't run.

**Do NOT use the SWF version byte to detect AVM2 — it is unreliable.** AVM1
content is routinely published as SWF v9+ (Age of War is v9 AVM1, Duck Life 2 is
v15 AVM1). The authoritative signal is the tag stream: a `DoABC` tag (82) ⇒
AVM2; `DoAction`/`DoInitAction` (12/59) ⇒ AVM1. Use the classifier:

```bash
python3 tools/divergence/classify_avm.py ~/CC/flasharchive/*.swf
python3 tools/divergence/classify_avm.py --avm1-only ~/CC/glaiel/swfs/*.swf  # AVM1 names only
```

Known AVM2 exclusions in this corpus (classified 2026-05-30):
- **flasharchive:** `QWOP` (only one).
- **glaiel:** `Aether`, `Closure`, `Pilgrimage`, `Spectrum`, `attractor`,
  `nutcracker`, and `helenkellergame` (AS3 flag set, no AVM1 actions — verify).

### Work smallest-first

Small SWFs recompile and build fast and have fewer moving parts, so a divergence
is easier to localize. Sizes (run `ls -laS ~/CC/flasharchive/*.swf` to refresh):

- **flasharchive, smallest first:** Snake (9KB ✓done), Tetris (14KB),
  Minesweeper (29KB), Pacman (42KB), Checkers (136KB ✓done), ~~QWOP (137KB —
  AVM2, excluded)~~, Tron (303KB), N (380KB), Bloons (518KB ✓done),
  Avalanche (527KB ✓done), …
- **glaiel, smallest first:** pathsA (1.0MB), Deep…, sousapalooza (1.3MB),
  Magnetism (1.3MB), RedWhiteBlue (1.4MB), Arcade (1.5MB), … up to
  nutcracker (13.7MB).

> Big SWFs (>~2MB) hit the harness's **30s recompile timeout** (see §5) — expect
> to bump it or skip them until the smaller ones are clean.

---

## 2. How to check current status

1. **`tools/divergence/PROGRESS.md`** — the living progress tracker: per-game
   status board, fixes landed (with commits), hard-won gotchas, and the
   prioritized open follow-ups. **Start here** — it's "where we left off".
2. **`tools/divergence/RESULTS.md`** — the per-game divergence board (trace +
   image divergence per game, plus cross-cutting patterns); the raw "what's
   broken". (Note: results predating the tracer fix `6a08f06aa` are invalid for
   `_root.onEnterFrame`-driven games — see PROGRESS.md.)
3. **`SWFRecompDocs/games/FLASHARCHIVE_BUILD_RESULTS.md`** — which games build.
4. **`SWFRecompDocs/status/<date>-<game>-*.md`** — per-game investigation logs
   (Doodle Jump and Snake have extensive histories; grep `SWFRecompDocs/status/`
   for the game name).
5. **Auto-memory (`MEMORY.md`)** — load-bearing runtime gotchas. The
   game-relevant clusters: MovieClip timeline control, graphics/tag
   implementation, browser-WASM frame-func re-run, getBounds, clone/depth.
6. **`SWFRecompDocs/plans/<game-or-feature>*.md`** — open plans (e.g.
   `dj-platform-followups.md`).

---

## 3. The toolset

Six tools, ordered by how early in a session you reach for them. Each has a
fuller doc — this table is the "which one and why."

| Tool | What it does | Browser? | Doc |
|---|---|---|---|
| **Divergence harness** (`tools/divergence/`) | Runs a SWF through SWFRecomp (graphics-native, headless) **and** Ruffle; reports the first trace + image divergence | **No** — fully headless | `SWFRecompDocs/guides/divergence-harness-usage.md` |
| **verify_output.py** (`ruffle-tests/`) | Single-test recompile+run, NO_GRAPHICS (trace) or `--mode=graphics` (headless PNGs) | No | `ruffle-tests/.../SESSION_START_GUIDE.md` |
| **SWF analysis** (`tools/swf-analysis/`) | Static SWF inspection (DefineText flags, glyphs, tag bytes) — compare what the SWF *contains* vs what the runtime emits | No | `tools/swf-analysis/README.md` |
| **Injected-AS probe** (`ruffle-tests/.../_swfbridge/livetest/dj_probe/`) | Splices a custom AS class into a game's SWF (before recompiling) to **read/write/control its live AS object graph** and report via `trace()`; runs the same injected SWF under Ruffle, native, and WASM | Native headless + Ruffle/WASM headed | `…/dj_probe/README.md` |
| **WASM probe suite** (`SWFRecomp/tests/wasm_probes/`, `tools/wasm_probe_runner.py`) | Minimal hand-built SWFs, golden-image regression for isolated browser-WASM behaviors | Headed Chrome (automated) | `SWFRecompDocs/plans/wasm-probe-suite.md`, `wasm_probes/README.md` |
| **Browser-WASM probe** (`tools/browser-test/probe.py`) | Drives a deployed demo in headed Chrome; captures console, display-list JSON, canvas PNG. Diagnostic only | Headed Chrome | `SWFRecompDocs/guides/browser-test-harness-usage.md` |

### 3a. Divergence harness — the primary tool

```bash
# One-time: build tracer + patched Ruffle exporter (see the usage doc)
tools/divergence/build_tracer.sh
cd ~/CC/ruffle && cargo +nightly build --release -p exporter

# Per game (the recompiler reads the SWF directly — point at the source SWF
# or a deployed test dir's test.swf)
python3 tools/divergence/divergence_test.py "~/CC/flasharchive/Tetris.swf" --frames 16
cat tools/divergence/runs/Tetris/divergence.txt

# Re-run only the SWFRecomp side after a runtime fix (Ruffle output is reused)
python3 tools/divergence/divergence_test.py "<swf>" --frames 16 --skip-ruffle
```

`--skip-ruffle` is the iteration workhorse: change runtime code → rebuild is
automatic inside the harness → re-diff, all headless. To rebuild the whole
local_batch baseline at once, `tools/divergence/run_local_batch.sh`.

### 3b. Reading a divergence report

- **`Trace: first divergence at filtered line N`** — the first place AVM1 state
  diverges. This is almost always the most actionable signal and is **fully
  headless**. Example finding from RESULTS.md: SWFRecomp emits spurious
  `_root.instanceN=undefined` enumerable globals that Ruffle doesn't.
- **`Trace: identical`** — logic matches; any remaining diff is rendering.
- **`Image: first divergence at frame N`** — rendered pixels differ.
  `max_diff` near 255 with huge outlier counts = structural (background /
  preloader); `max_diff` ≤ ~8 = sub-pixel/AA, usually not worth chasing.

### 3c. Injected-AS object-graph probe

The divergence harness *diffs traces* — it can't tell you the live value of an
arbitrary variable, walk a game's object graph, or drive the game to a specific
state on demand. For that, **inject your own AS** into the game's SWF before
recompiling, using the same splice pipeline as the tracer:

```
Probe.as --(MTASC)--> probe.swf --(tools/divergence/extract_bytecode.py)-->
  probe_bytecode.bin --(tools/divergence/inject_tracer.py, --bytecode)--> game_probed.swf
```

The injected class hooks a dedicated high-depth clip's `onEnterFrame` (so it
doesn't clobber the game's own `_root.onEnterFrame`) and reads/writes the live
graph (`_root.foo`, `mc.bar`, `for..in` enumeration, `Key.isDown`), reporting via
`trace()`. Because `trace()` reaches stdout natively and the console under
Ruffle/WASM, **the same injected SWF runs on all three runtimes** — so you can
read ground truth (Ruffle) and the recompiled value (native/WASM) side by side.
The `dj_probe/` harness is the worked example (read/write/placement/steer modes,
plus `run_native.py`/`run_ruffle.sh`/`run_wasm.sh` drivers).

When to reach for it (vs the divergence harness):
- "What is `_root.someVar` actually *set to*?" / "what's in this MC's object
  graph?" — enumerate it live instead of inferring from a trace diff.
- "This bug only happens in a state the harness can't reach." — the probe can
  **drive the game to the state itself** (e.g. force gameplay with
  `_root.gotoAndPlay(N)` instead of relying on a menu click; see §5 gotcha on
  native hit-testing).
- "Does Ruffle and SWFRecomp agree on this live value/behavior?" — run the same
  injected SWF on both; for read/write of plain AS state they are typically
  byte-identical (deterministic `MOCK_DATE_TIME` seeding).

`run_native.py --input <input.json>` also drives **clicks/keypresses headlessly**
under native (file-driven `EV_*` events → `keys.down[]` / mouse), so injected
keys reach `Key.isDown` without a browser — useful for input-dependent logic.

---

## 4. Triage: which tasks need a browser, which don't

**Do these first — no human, no browser, fully scriptable:**

- Any **trace divergence** the harness reports (AVM1 logic, variable values,
  frame pacing, object enumeration). Reproduces in NO_GRAPHICS too.
- **Early-frame image divergences** (frames 1–16) on content that renders
  without input — preloaders, title screens, the first auto-played frames.
- Anything reproducible via `verify_output.py --mode=graphics` headless PNGs.
- Recompiler/codegen bugs (compare SWF bytes via `tools/swf-analysis/` vs the
  generated `RecompiledScripts/`).

**Defer to a manual / collaborative browser loop:**

- Anything **gated behind input** — a divergence that only appears after a
  click/keypress to start gameplay or navigate a menu. The harness runs with no
  input events, so it can't reach those states.
- **Browser-WASM-only code paths** — code gated
  `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER) && !defined(HEADLESS_GRAPHICS)`.
  These are invisible to both the divergence harness and CI; only the deployed
  demo exercises them. (See MEMORY.md: many timeline/clip-event paths are
  browser-WASM-only.)
- **Audio**, WebGPU-specific rendering, focus/cursor behavior.

For the deferred bucket, the loop is: change → rebuild+deploy → user tests in
browser → user reports. `tools/browser-test/probe.py` can capture console +
display-list JSON automatically (canvas PNG only in headed Chrome), but the
*verdict* is still the user's. Write the session prompt to make that loop
explicit (see §7).

> **Heuristic:** if you can write a regression gate as a `divergence_test.py`
> command, the task is in the headless bucket. If the only way to confirm the
> fix is "look at the running game and click things," it's in the browser bucket.

---

## 5. Known harness limits & gotchas (carry these into every session)

The single home for divergence-debugging gotchas (consolidated 2026-06-10;
`tools/divergence/PROGRESS.md` used to hold a second list). **Add new ones
here, not in PROGRESS.md.**

### Harness limits

1. **Image comparison covers only the first 16 frames by default** — set the
   `CAPTURE_MAX=<n>` env var (`ed198c7b7`; no rebuild needed). The tick loop
   runs the full `--frames` count; only PNG capture is capped. (This is why
   Checkers read "identical" at 16 frames — its real divergence is at
   frame 19.)
2. **Recompile timeout is 30s by default** — set
   `SWFRECOMP_RECOMPILE_TIMEOUT=600` (env, `ed198c7b7`) for big games (>~2MB,
   e.g. Art of War, Castle Hero; the docs2 WASM build path has its own longer
   timeout). There is ALSO a hardcoded **300s per-file compile timeout** in
   `verify_output.py`: a generated `script_defs.c` with one enormous function
   (e.g. a 152k-line garbage `DefineFunction2`) blowing past it is a
   *parse-desync symptom*, not a real game. A legit big game's `draws.c`
   (Tron: 51MB) compiles fine — `script_defs.c` is the one to watch.
3. **The harness compares against Ruffle's headless *exporter*, not the live
   browser player.** They can differ (preloader/streaming/wall-clock timing).
   "Trace: identical" does NOT prove a match with real Flash — both headless
   tools can be equally stuck (e.g. a preloader that only advances under real
   wall-clock).
4. **The tracer must not clobber game handlers** — it hooks a dedicated
   `__tracer__` clip's `onEnterFrame`, not `_root`'s (`6a08f06aa`). Any
   divergence result produced *before* that commit for a
   `_root.onEnterFrame`-driven game ran with the game's root loop disabled —
   **invalid, re-run**.
5. **v5 SWFs with PlaceObject2 clip-event handlers**: the injector's version
   bump to ≥6 changes CLIPACTIONS flag width (UI16→UI32); the injector
   rewrites them (`36fb13708`). If a v5 game still produces a giant garbage
   `DefineFunction2` / "compilation timed out", suspect a *new*
   version-dependent record the injector doesn't rewrite (CLIPACTIONS is the
   only one in practice). The recompiler is CORRECT on native-version SWFs —
   always compare a clean native recompile vs the injected one to tell an
   injector bug from a recompiler bug.
6. **Game `trace()` can contain non-UTF8 bytes** — `grep -c '^F'` on a trace
   file reports a blank/0 count (grep treats it as binary). Use `grep -a`.
7. **Graphics-mode SIGABRT *after* correct output = a real heap UAF/OOB, not
   a CI flake.** ASAN-pin it (`--asan`). See memory
   `graphics-sigabrt-real-heap-bugs`.
8. **Browser-probe canvas capture** of a live WebGPU canvas fails (Playwright
   stability timeout); only the display-list JSON is reliable there. And
   automated headed Chrome may throttle rAF (demo runs slowly / looks stuck).

### Runtime-behavior gotchas

9. **`_alpha` reads the placement/timeline CXFORM alpha** (`mcReadAlpha`,
   `0973204c3`/`f9efc2740`) — gated on `has_cxform` (placement CXFORM present)
   AND `!(as_set_flags & 32)` (script hasn't set `_alpha`). The display
   entry's `cx_aa` is only trustworthy when `has_cxform` (else uninitialized
   0) and as the *pre-script* value (the `_alpha` setter's write-through can
   miss a nested entry).

### Cross-runtime gotchas (found via the injected-AS probe, 2026-06-01, Doodle Jump)

10. **Native (OFFSCREEN_RENDER) does not hit-test menu buttons.** A file-driven
   `MOUSE_DOWN_LEFT`/`UP` at a button's coords does **not** navigate under the
   headless native build (the `targeted_sprite` / button-press dispatch that
   makes menu clicks work is browser-WASM-only). Ruffle (real Flash) and
   browser-WASM **do** hit-test. To reach a click-gated state headlessly, force
   it from injected AS (e.g. `_root.gotoAndPlay(N)`) rather than synthesizing a
   click. (Verify the target frame first — DJ's PLAY is `gotoAndPlay(2)`, and
   frame 6 is the INFO screen.)
11. **`_root._currentframe` reads `undefined` in browser-WASM** (native and Ruffle
   report the real number). Don't use `_currentframe` as a state signal when
   diagnosing under WASM; read a game variable instead.
12. **DJ's `Math.random`-driven layout is not perfectly cross-runtime
   deterministic** even under `MOCK_DATE_TIME`: initial platform positions/types
   differed Ruffle vs native, though scalar `trace()`/score *progression* matched
   byte-for-byte. So an *image* divergence can be a genuine RNG-layout difference,
   not a renderer bug — confirm with the trace before chasing pixels.
13. **Ruffle in headed Chrome with software WebGL pops a "hardware acceleration is
   disabled" modal** that covers the canvas and **intercepts clicks**. Strip it
   from the shadow DOM before driving input (see `dj_probe/run_browser.js`'s
   `dismissRuffleOverlay`). SWFRecomp's own WASM/WebGPU runtime has no such
   overlay.

---

## 6. Build, deploy, and regression gates

### Rebuild a demo (browser-WASM, docs2)

`<ns>` is `flasharchive` or `glaiel` — deploy each corpus into its own namespace.

```bash
source emsdk/emsdk_env.sh
# Single demo (test must exist under SWFRecomp/tests/<ns>/<name>/):
SWFRecomp/scripts/build_test.sh <ns>/<name> wasm --graphics --clean
SWFRecomp/scripts/deploy_example.sh <ns>/<name> "$(pwd)/docs2/examples" --no-index --graphics

# Or batch a directory of source SWFs into the right namespace (one SWF in the
# dir = one game at a time). flasharchive:
GRAPHICS_BUILD_TIMEOUT=1800 SWFRecomp/scripts/build_swf_batch.sh <swf_dir> \
    --docs-dir docs2 --namespace flasharchive \
    --catalog-name flasharchive_catalog.json --demo-type flasharchive
# glaiel: swap flasharchive → glaiel in all three flags.
```

`--clean` is **required** when runtime `.c` changed (the runtime is compiled into
each demo's `.wasm`). Full build/deploy reference:
`SWFRecompDocs/guides/building-docs2-demos.md`.

### Two CI build modes — know which one your change touches

- **NO_GRAPHICS** (`swf_core.c`, trace) and **graphics-native / OFFSCREEN_RENDER**
  (`swf.c`, headless PNGs) are both validated in CI via
  `.claude/pipeline-handoff.md`.
- **Browser-WASM-only** paths (gated out of both CI modes) are validated by the
  deployed demo, not CI.
- The divergence harness exercises the **graphics-native (OFFSCREEN_RENDER)**
  path — so a divergence it finds is CI-gateable; a browser-only bug is not.

### Regression gate pattern

After a fix, lock it with a divergence command, e.g.:

```bash
# Trace must stay matched / not regress
python3 tools/divergence/divergence_test.py "<swf>" --frames 16 --skip-ruffle
```

Don't run full test suites locally (CLAUDE.md). Only `--test=NAME` /
single-game divergence. Never branch first (trunk-based). **Autonomous
commit / push / CI is authorized** — when a piece of work is done or paused with
progress, run the pipeline end-to-end per `.claude/pipeline-handoff.md`
(commit → push `master` → trigger `ruffle-tests.yml` in the matching mode → `gh
run watch` → merge results → report regressions). For shared
`OFFSCREEN_RENDER` / graphics changes, run **both** CI modes (or `graphics` at
minimum); `no-graphics` otherwise.

---

## 7. Session prompt template

To **resume the effort** from where we left off, paste the ready-made prompt in
`tools/divergence/SESSION_RESUME_PROMPT.md` (it points the new session at
PROGRESS.md → guide → RESULTS.md and the top open follow-up).

For a **specific, scoped task**, use this skeleton instead (fill the brackets);
it mirrors the structure that has worked:

```
<One-sentence task>: <game> (<flasharchive|glaiel>, browser-WASM graphics /
graphics-native). Bucket: <headless-diagnosable | needs-browser>.

Symptom: <what diverges from Ruffle/Flash, observed where>.

Read first (session start):
- SWFRecompDocs/guides/wasm-game-debugging-session-guide.md (this guide)
- tools/divergence/PROGRESS.md (where we left off + gotchas)
- tools/divergence/RESULTS.md (per-game divergence board)
- <relevant SWFRecompDocs/status/*.md and MEMORY.md entries>

Reproduce:
- Diverge: python3 tools/divergence/divergence_test.py "<swf>" --frames 16
  → first divergence at <trace line / image frame>.
- <If headless:> iterate with --skip-ruffle after each runtime change.
- <If browser:> build_test.sh + deploy_example.sh (--clean), then a
  collaborative loop (change → rebuild+deploy → user reports). Run local
  probes DIRECTLY (never via `timeout … | tail` — SIGPIPE kills them).

Architecture leads (verify, don't trust blindly):
- <files / code paths suspected, e.g. action.c dispatch, tag.c render>.

Regression gates to hold:
- <divergence_test.py command(s) that must stay green>.
- <other already-landed fixes that must keep working>.

Constraints (CLAUDE.md): autonomous commit/push/CI is authorized — run the
pipeline (.claude/pipeline-handoff.md) when work is done/paused; never run full
suites locally (only --test / single-game divergence); shared OFFSCREEN_RENDER
code must be validated via .claude/pipeline-handoff.md (CI both modes); strip any
browser printf diagnostics before committing.
```

---

## 8. Architecture (pointers, not a duplicate)

The runtime/recompiler architecture is documented in
`ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md` §"Architecture
Overview" and in `CLAUDE.md`. The load-bearing facts for game debugging:

- **Recompiler** (`SWFRecomp/src/action/action.cpp`) → C; **runtime**
  (`SWFModernRuntime/src/actionmodern/action.c`, ~50K lines) executes it.
- **Graphics split:** `swf.c`/`tag.c`/`render_webgpu.c` (graphics) vs
  `swf_core.c`/`tag_stubs.c` (NO_GRAPHICS). `OFFSCREEN_RENDER` =
  headless-graphics-native (what the divergence harness builds).
- **`ASObject` ≠ `ASFunction` ≠ `ASArray`** — never cast between them
  (CLAUDE.md). The `instanceN`-global and proto-chain gotchas in MEMORY.md bite
  most games.
- **SWF spec:** `SWFRecompDocs/specs/swf-spec-19.txt`.
```
