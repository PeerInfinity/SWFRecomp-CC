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

Five tools, ordered by how early in a session you reach for them. Each has a
fuller doc — this table is the "which one and why."

| Tool | What it does | Browser? | Doc |
|---|---|---|---|
| **Divergence harness** (`tools/divergence/`) | Runs a SWF through SWFRecomp (graphics-native, headless) **and** Ruffle; reports the first trace + image divergence | **No** — fully headless | `SWFRecompDocs/guides/divergence-harness-usage.md` |
| **verify_output.py** (`ruffle-tests/`) | Single-test recompile+run, NO_GRAPHICS (trace) or `--mode=graphics` (headless PNGs) | No | `ruffle-tests/.../SESSION_START_GUIDE.md` |
| **SWF analysis** (`tools/swf-analysis/`) | Static SWF inspection (DefineText flags, glyphs, tag bytes) — compare what the SWF *contains* vs what the runtime emits | No | `tools/swf-analysis/README.md` |
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

## 5. Known harness limits (carry these into every session)

From the local_batch run (see `tools/divergence/RESULTS.md`):

1. **`MAX_CAPTURES 16` (`SWFModernRuntime/src/libswf/capture.c`)** — image
   comparison only ever covers the **first 16 frames** regardless of `--frames`.
   The tick loop runs the full count; only PNG capture is capped. Bump the
   `#define` + rebuild to see later frames. (This is why Checkers reads
   "identical" at 16 frames — its real divergence is at frame 19.)
2. **30s recompile timeout (`ruffle-tests/verify_output.py::recompile_swf`)** —
   large injected SWFs (Art of War 1.5MB, Castle Hero 14MB) time out. The docs2
   WASM build path uses a longer timeout, so the *demo* still builds. Bump the
   30s limit to diverge-test big games.
3. **Tracer `_root.onEnterFrame` doesn't dispatch for Snake** (the only
   originally-v5 SWF) — image-only comparison for it. The mechanism is otherwise
   sound (Checkers/Doodle Jump fire it on both sides).
4. **Game `trace()` can contain non-UTF8 bytes** — `grep -c '^F'` on a trace
   file reports a blank/0 count (grep treats it as binary). Use `grep -a`.

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
`SWFRecompDocs/building-docs2-demos.md`.

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
single-game divergence. Commit to master only when asked; never branch first.

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

Constraints (CLAUDE.md): commit to master only when asked; never run full
suites (only --test / single-game divergence); shared OFFSCREEN_RENDER code
must be validated via .claude/pipeline-handoff.md (CI both modes); strip any
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
