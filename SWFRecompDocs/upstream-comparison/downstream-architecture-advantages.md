# Advantages of the Downstream (SWFRecomp-CC) Architecture

**Living document.** Last updated: September 22, 2026 (previous: July 4, 2026).

What this fork's architecture and process do better than upstream's. The flip side
is [`upstream-architecture-advantages.md`](upstream-architecture-advantages.md).
"Architecture" here includes the test/verification infrastructure — it has shaped
the code as much as any structural choice, and it is the harder half to replicate.

---

## 1. Proven behavioral parity — the asset everything else serves

- **The full upstream corpus, 4,437 tests across 14 categories, at 98.2%
  effective** (CI of Sep 22, 2026, graphics mode; effective = pass +
  `ruffle_matched`). Per suite: avm1 721/736, avm2 1255/1278, Tamarin
  `from_avmplus` 1570/1574, Gnash 375/403 over five sub-suites, Shumway
  225/229, the nine small categories 210/217 — plus our own 96-test
  `regression` suite at 96/96, and the 158 hand-written trace + 59 graphics
  tests. All in CI on every change. (July 2026 figure for comparison: 704
  AVM1 tests at 96.7% filtered; the corpus was AVM1-only then.)
- The remaining diffs are *classified*, not merely failing: unfixable-by-design
  cases are documented in `ACCEPTED_DIFFS.md`, Ruffle-divergences-from-Flash in
  `RUFFLE_VS_FLASH_DIFFERENCES.md`, deliberate bug replication in
  `FLASH_BUGS_REPLICATED.md`, judgment calls in `RUFFLE_COMPAT_TWEAKS.md`.
- **Complete games run end-to-end in the browser** — Minesweeper, Tetris,
  N (Metanet), Riddle School, Reaction, and others. Games are the integration test
  no unit suite substitutes for: they exposed dozens of bugs (execution ordering,
  display-list lifecycle, input, text) that trace tests never would.

This is the moat. Architecture can be refactored; nine months of adversarially
discovered AVM1 semantics cannot be re-derived quickly on any foundation.

## 2. Full AVM1 surface area — and an AVM2 runtime

Essentially the complete AVM1 opcode set plus the built-in class library: Object, Array,
String, Number, Boolean, Date, Math, Function, MovieClip, TextField, TextFormat,
TextField.StyleSheet-adjacent behaviors, Color, Transform/ColorTransform, Sound,
XML/XMLNode, BitmapData, Selection, Key, Mouse, Stage, plus the net surface
(AMF0, `NetConnection.call`, `SharedObject`, `LocalConnection` as a real wire
channel, `XMLSocket`) — with the deep semantics
attached: `super` depth-based dispatch, `__resolve`, `Object.registerClass`,
`addProperty` virtual properties with Flash's re-entry budget, `with` scope, soft
references, clip events, intervals/timeouts, drag, `tellTarget`, slash paths.
Upstream is at the "Sound class started, DefineFont2 in progress" stage of this
curve; we are at the long tail.

**AVM2 (ActionScript 3), July–September 2026.** A second VM under
`SWFModernRuntime/src/avm2/` (~93K lines, 36 files, deliberately *not* a second
monolith): ABC front-end in the recompiler with Ruffle's verifier/optimizer
design (resolved multinames, slot/vtable lowering), interned names, a
class/trait/vtable object model, E4X, Vector, ByteArray with LZMA, JSON, RegExp
via PCRE, AMF3, the display list and event model, Flash Text Engine, Loader,
Stage3D stubs, and enough of `flash.*` to run Flixel/FlashPunk games. Built
from a plan shared with upstream on July 10 (`plans/avm2-support-plan.md`);
crossed half the avm2 corpus within a day of starting and sits at 1255/1278 +
1570/1574 now. Upstream has no AVM2 work. Playable: Seedling, Robot Wants Kitty
and its sequels, Elephant Quest, Snailiad, and a 235-title Flixel survey.

## 3. Three execution modes upstream doesn't have

1. **`NO_GRAPHICS` headless** (`swf_core.c`) — sub-second recompile-and-run trace
   tests; what makes 1100+-test CI and fast bisection practical.
2. **Offscreen native graphics** (Dawn/WebGPU) — deterministic PNG capture per
   frame, enabling *pixel-level* comparison against **real Flash Player output as
   the oracle** (`expected.png`), with tooling that classifies divergences as
   fixable vs inherent-MSAA (`triage_image_tests.py`).
3. **Browser WASM** (emscripten + WebGPU) — the actual product target, with the
   perf work done to make it real: batched + retained-skip GPU uploads (57→3ms
   idle frame in Minesweeper), 8MB stack sizing, timer pumping, GPU readback
   debugging hooks. Since February 2026 the **recompiler itself also runs in the
   browser** (`docs/recompiler/`: drop a `.swf`, get C, or compile and run it
   in-page with no toolchain) — the whole pipeline is deployable as static
   files.

Upstream renders via SDL3 GPU natively; it has no headless trace mode, no
pixel-oracle harness, and no browser deployment. For a *correctness-first* project
these modes are the whole game.

## 4. Test and debugging infrastructure

- `verify_output.py` — one runner across four suites, `--diff`, per-test TOML
  config, ignore-list filtering, `results.json` as ground truth.
- **Sharded CI** (30-way) with regression detection *by name* (pass→fail surfaced
  per test), dispatchable per-mode, resumable pipeline state.
- **Determinism as policy** — `Math.random` and `Date.getTime` seeded per test
  (`MOCK_DATE_TIME`, matching Ruffle's `--deterministic`), and the reported host
  OS pinned the same way (`MOCK_PLATFORM`); two CI runs at the same
  SHA are byte-identical across all suites. "Flaky" therefore always means "real
  bug," which is worth more than it sounds.
- **Game debugging tooling** — divergence harnesses (frame-exact trace comparison
  vs Ruffle), headless game-drive scripts, per-frame heartbeats, one-shot state
  dumps, ASAN playbooks. Codified in reusable session guides.

## 5. Single-threaded, deterministic execution model

- AVM1 is single-threaded by spec; our engine simply *is* that model. No locks, no
  races, no cross-thread ordering to reason about — determinism falls out for free
  and underwrites both the byte-identical CI and every bisection workflow.
- Deterministic, immediate refcounting means destruction order is predictable —
  which AVM1 semantics visibly depend on (e.g. `onUnload` ordering, removal
  deferral). A concurrent collector must re-establish those orderings deliberately;
  we get them by construction.
- **WASM-friendly by default:** no SharedArrayBuffer / COOP-COEP requirements, no
  pthread builds. Upstream's free-thread GC and locks are a porting liability for
  any future browser target; our model drops in.
- **Proof point (July 2026):** we shipped GC-grade memory reclamation *within*
  this model — a single-threaded, between-frames, root-traced mark-sweep
  collector (default-on, `bac8b31e8`) that flattened N's unbounded leak with
  byte-identical output and zero test regressions. Concurrency was never the
  missing ingredient.

## 6. Everything-in-C stdlib: control where Flash is weird

The AS2-prelude approach (upstream) gets *standard* semantics by construction — but
Flash's built-ins are frequently *not* standard, and C-level implementation is
where we can express that:

- native re-entry budgets (the 65 getter+setter virtual-property limit);
- deliberate replication of Flash Player bugs (`FLASH_BUGS_REPLICATED.md`) — e.g.
  cxform aMult-only no-op — which an AS2-level class can't even see;
- avmplus-exact RNG and number formatting;
- performance: builtin hot paths run as compiled C, with no AVM1 dispatch overhead.

Single-artifact output is also operationally simpler: no MTASC toolchain or prelude
SWF in the build chain of every recompiled game.

## 7. Velocity, demonstrated

Nine months from fork (Oct 2025) to: four test suites passing at high rates, six-plus
playable browser games, a text pipeline, audio, input, an Archipelago integration,
and procgen research substrates. The architecture's lack of ceremony — globals,
one big file, direct C — is causally connected to that pace: the cost of adding the
next behavior is one function and a test, not a design negotiation. This is the
honest counterweight to upstream advantage #8 (tractability): monoliths are worse
to *read* and better to *grow into a spec-chasing problem domain*, at least until
they aren't. We monitor for the crossover (duplicate-site bugs are the early
symptom) rather than paying the modularity tax up front.

## 8. Recompile-time work over runtime work

Static shape tessellation happens at recompile time (libtess2): the runtime ships
pre-triangulated geometry, startup does no tessellation, and headless tests don't
pay geometry costs at all. Upstream tessellates at runtime — simpler and uniform
(their advantage #7), but it puts work on every startup that we do once, offline.
Same philosophy as the recompiler itself: move work from run time to build time.

## 9. Product surface beyond the engine

Deployment and integration machinery upstream hasn't needed yet: the docs/docs2
hosting split (OSS vs local-only licensing), batch build/deploy scripts with demo
catalogs, the Archipelago randomizer bridge (native APCpp + browser
archipelago.js), level loaders and injected-AS instrumentation for using recompiled
games as research substrates. These aren't architecture per se, but they are things
the architecture had to be shaped to support (external call handlers, after-tick
hooks, injected scripts).

---

## Summary

| # | Advantage | Upstream's position |
|---|-----------|---------------------|
| 1 | Behavioral parity (98.2% of a 4,437-test corpus), classified diffs, playable games | Early on the same curve |
| 2 | Full AVM1 opcode + builtin surface, **plus a complete AVM2 runtime** | ~10 AVM1 builtin classes; no AVM2 |
| 3 | Headless / pixel-oracle / browser-WASM modes | SDL3 native only |
| 4 | Test + debugging infrastructure, determinism policy | 56 test dirs, no harness |
| 5 | Single-threaded deterministic model (WASM-friendly) | Threads + concurrent GC |
| 6 | C stdlib expressing Flash's non-standard reality | AS2 prelude (standard-by-construction) |
| 7 | Demonstrated velocity on the parity problem | Deliberate, foundation-first pace |
| 8 | Build-time over run-time work | Runtime tessellation |
| 9 | Deployment/integration product surface | Not yet needed |
