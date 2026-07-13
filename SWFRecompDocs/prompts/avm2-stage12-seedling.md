# Session prompt — AVM2 Stage 12: Seedling bring-up

You are implementing **Stage 12** (the final phase-2 stage) of the AVM2
Seedling-directed plan (`SWFRecompDocs/plans/avm2-seedling-plan.md` §2).
Everything up to here is done: the AVM2 language + display + input + audio +
render + **GC** (Stage 11) are all test-green. This stage opens the real game
for the first time.

Read the plan first, then `avm2/_investigation/CURRENT_STATUS.md`, then the
memories `seedling-avm2-readiness` (the census + remaining-work list),
`avm2-stage11-gc` (GC is done — the collector is safe to run during extended
play; default 4 MB watermark, `AVM2_GC=0` to disable while bisecting),
`avm2-stage9-render` / `avm2-stage10-audio` (render + audio state, including
what's still stubbed), and `wasm-game-debugging` (the divergence-harness-first
workflow — the AVM1 lesson: **don't divergence-hunt on a half-built
foundation**; the foundation is now built and graded).

## Target

Seedling: `/home/robert/CC/SeedlingArchipelagoInjector/Seedling.swf` (FlashPunk,
SWF10, 480x480 @30fps, 2 DoABC / 3,607 bodies / zero unimplemented ops). The
Archipelago-injected variant (`Seedling_injected.swf`) is the eventual endgame
(post-baseline: an AVM2 `Rando` counterpart — see
`archipelago-rando-integration`).

## Goal

Recompile the real SWF and drive it with the divergence-harness workflow until
it renders + plays correctly headless (and then in browser-WASM). The GC is now
enrolled, so extended play no longer grows unbounded — but this is the first
time the render/input/audio bridges meet real game content, so expect gaps the
trace suite didn't cover.

## Safeguards (carried from the whole plan)

1. **The game is the INTEGRATION check, never the oracle.** Any behavior gap you
   fix must be reproduced as (or backed by) a trace/regression test in the
   appropriate suite — never merge "looks right in Seedling".
2. **Divergence-harness first.** Fix headless-reproducible divergences (trace
   diffs, early-frame image diffs) before browser-only paths.
3. **Bisect GC vs feature.** If something misbehaves in extended play, re-run
   with `AVM2_GC=0` first to tell a collector bug (a marking gap the trace suite
   didn't exercise) from a feature gap. A GC bug shows as a UAF/wrong-value that
   vanishes with the collector off — capture it with ASAN + `-DHEAP_PASSTHROUGH`
   (the Stage-11 method; plain ASAN can't see intra-o1heap frees). Any new
   C-static object stash or avm2_alloc'd struct traced by the GC MUST be
   rooted/initialized (the two Stage-11 stress bugs were exactly these).

## Likely work (from the census + what's still stubbed)

- **Recompile**: the real SWF emits 284 bitmaps + 116 binaries + 88 sounds
  (asset zlib compression landed in Stage 10 → ~8.9 MB abc_timeline.c). Confirm
  it still recompiles + links (native + wasm-link-smoke).
- **Render gaps** (Stage 9 was bitmap-blit only): shape/gradient/text/mask
  rendering (Graphics records only an AABB today), the `draw()` offscreen-GPU
  pipeline (DisplayObject sources / alpha-erase group blends). FlashPunk is a
  blit engine, so the bitmap path covers most of it — verify what's missing.
- **Audio OUTPUT**: Stage 10 is trace-only (no real audio wiring to src/audio);
  Sound.load network path also deferred. Wire real output if the game needs it.
- **Input**: the Stage-8 bridge feeds injected input.json; native/browser real
  platform input reuses the same dispatch — verify keyboard/mouse.

## Verification & workflow

Unchanged: per-test local runs only, full suite via CI (both modes — GC is
shared runtime lifetime), pipeline per `.claude/pipeline-handoff.md`,
honest-failure everywhere. Conflict boundary: own `src/avm2/`,
`SWFRecomp/src/abc/`, `RecompiledABC/`; never touch `action.c`. For the game
itself use the divergence harness + `wasm-game-debugging` guide; keep the game
out of the CI pass-rate metric (it's an integration check).

## End-of-session bookkeeping

- Stage-12 landing note in `avm2-seedling-plan.md` §2; update
  `CURRENT_STATUS.md` and `seedling-avm2-readiness`.
- New per-game memory (first-playable status, gaps found, divergence baseline).
- If Seedling is first-playable, this completes phase 2 — note the pivot to the
  Archipelago-injected variant + the AVM2 `Rando` builtin as the next arc.
