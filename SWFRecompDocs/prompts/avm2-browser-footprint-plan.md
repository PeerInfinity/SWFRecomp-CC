# Session prompt — browser memory footprint: does it really need 2 GB? (measure + plan)

**Objective (user, 2026-07-21):** the playability arc is closed (5-of-5 titles
clear 30 fps), and the next priority is **browser resource footprint**. The
AVM2 demos ship a **1984 MB o1heap arena** (`heap.c`, `__EMSCRIPTEN__ &&
SWF_AVM2`) with `-sMAXIMUM_MEMORY=4GB` (`build_wasm_avm2.sh:208-210`).
"Playable in the browser" is not credible if every visitor's tab needs ~2 GB.
This is a **planning session**: measure, decompose, price the levers, write
the plan. **Do not ship a lever.**

**The central suspicion, to confirm or kill:** the 1984 MB figure is STALE.
It was sized on 2026-07-18 ([[avm2-rwk3-browser-demo]] lever 0) against a
pre-reclamation heap: RWK boot peak 1409 MB, strings immortal, +94 MB/min
leak. Since then collectable strings ([[avm2-collectable-strings]], boot
1467→129 MB), raw-alloc reclamation ([[avm2-raw-alloc-reclamation]], churn
−97%), and weak orphans landed. Steady-state live is now ~85-140 MB — the
arena may be ~10x oversized for steady state, with the true floor set by
**single-tick transients** (GC runs only between ticks; RWK's boot tick
string-concats a 188×84 CSV = ~0.8+ GB of garbage in ONE tick,
[[avm2-rwk2-text-gameplay]]).

Read: [[avm2-rwk3-browser-demo]] (how 1984 was chosen; o1heap wasm32
FRAGMENT_SIZE_MAX caps capacity at 2 GB; **emscripten anonymous mmap fails at
exactly 2048 MB**), [[avm2-collectable-strings]], [[avm2-raw-alloc-reclamation]]
(fn_scope is PROVEN aliased — never free), [[avm2-inline-slots-ruled-out-o1heap-binning]]
(o1heap pow-2 binning waste is real and measured),
`SWFRecompDocs/reference/performance-optimizations.md` §2.

## §1 — Measure what is actually true at HEAD (per title, all five + an AVM1 demo)

Nobody has re-measured since the reclamation arc. Produce a per-title table:

1. **Native heap truth** (`AVM2_HEAP_STATS=1`, fresh builds): boot peak,
   steady live, and — the number nobody has — **worst single-tick gross**
   (peak allocated during a tick minus live at the preceding boundary).
   Instrument if needed; a tick-boundary high-water reset is a few lines.
   Get it for the boot tick AND a gameplay window. RWIC ran at ~96% of the
   4 GB native arena in the tier-2 session — measure whether that was
   transient or live; it may be the worst-case title, not RWK.
2. **Browser truth** (Windows-Playwright rig; footprint questions don't need
   the GPU but RSS lies differ per platform — use the real target browser):
   `WebAssembly.Memory` growth over a session (`Module.HEAPU8.length`
   sampled boot → menu → gameplay → 10 min), plus browser-reported process
   memory. **Answer the commitment question explicitly:** with
   `INITIAL_MEMORY=512MB` + growth, does the boot-time 1984 MB arena mmap
   grow linear memory to ~2 GB immediately (every visitor pays it at load),
   or lazily on touch? This single fact decides whether the problem is
   "arena sizing" or merely "arena headroom".
3. **Non-arena consumers**, so the plan targets total tab cost, not just the
   arena: wasm module + JS, and GPU textures (Seedling once hit a
   texture-array layer blowup — [[webgpu-texture-array-layer-limit-blank-render]]).

## §2 — Decompose the peak

For the worst title(s), split peak arena demand into: (a) genuine live set,
(b) single-tick transient garbage (reclaimable next boundary — the concat
spike), (c) o1heap pow-2 binning slack (requested vs allocated — instrument
or estimate from the binning study), (d) fragmentation/headroom margin
(o1heap needs slack to avoid the eager-sweep safety valve and OOM). The plan
hangs off this split; without it every lever is a guess.

## §3 — The lever map (price each; build none)

Price at minimum these, and add what §2 surfaces:

1. **Arena growth / segmentation.** o1heap wants one fixed arena, and wasm32
   caps it. Options to price: start-small + **additional arena segments** on
   near-exhaustion (wrapper routes free by address range; interacts with the
   GC arena membership bitmap and `heap_arena_base/span` — tier-2 assumed ONE
   arena); vs a different allocator; vs simply shipping a smaller fixed arena
   once §1 shows the real ceiling. The "just works" objective disqualifies
   per-title arena settings — auto-growth or a universally-safe default only.
2. **Kill the single-tick concat spike.** Sub-options: a string-concat
   accumulation fast path (rope/builder or realloc-in-place when the LHS is
   the newest allocation and provably dead — mind string identity semantics);
   a **Flixel `FlxTilemap.arrayToCSV` native intrinsic** via the
   now-standing fingerprint gate (precedent set, all four RW titles ship it;
   check whether it is closure-building — the gate holes are closed, so even
   that is coverable); **within-tick emergency collection** — probably
   RULED OUT because in-tick VM state lives in C locals invisible to the
   marker ([[avm2-stage11-gc]] quiescence invariant); if so, record the
   ruling with the reason, don't leave it implied.
3. **Binning slack**, if §2(c) is material: size-class tweaks were ruled out
   once for object+slots specifically — the general question may differ.
4. **Small stuff that scales with arena size:** the GC membership bitmap
   (16 MB per 4 GB), `INITIAL_MEMORY`, the AVM1 demos' 1 GB arena (same
   question, one line of the plan).

For each lever: expected footprint reduction (from §1/§2 numbers), risk,
effort, and what it does to the perf numbers just banked — **any footprint
lever that regresses a title below 30 fps is a non-starter**, and GC cadence
interacts with arena headroom (adaptive watermark clamps on
`heap_capacity`), so shrinking the arena changes collection frequency;
price that.

## §4 — Deliverable: the plan

A written plan at `SWFRecompDocs/plans/avm2-browser-footprint.md`:

1. The §1 table and §2 split — the actual answer to "does it need 2 GB".
2. A defensible per-title target stated with its justification (e.g. "every
   title boots and plays indefinitely in ≤512 MB of linear memory" — adjust
   to what §1 supports; do not pick a round number the data contradicts).
3. Ordered levers with prices, and which are gated on which.
4. Explicit rulings for anything ruled out (with the §2 numbers that killed it).
5. Recommended first implementation session, prompt-ready.

Also update the stale arena comment in `heap.c` if §1 contradicts it —
measured-then-superseded numbers left in code comments are how the 1984
figure would mislead the next reader.

## Method rules (binding)

- Measure at HEAD with FRESH builds and FRESH recompiles (staged wasm rots;
  `.o` cache keys on mtime — [[avm2-flixel-native-intrinsic]] restage gotcha).
- State-prove every measured phase (boot / menu / PlayState); the title-screen
  trap applies to memory exactly as it did to frame time.
- Perf regression checks that involve wall-clock follow the standing rig
  rules (same-session interleaved only). Native wall-clock: default GC, equal
  ticks ([[avm2-native-ab-recipe-gc0-invalid]]).
- Soak long enough to see the sawtooth: tier-2 lazy sweep makes live counts
  sawtooth BY DESIGN ([[avm2-hud-counters-are-real-sawtooth]]) — do not
  report a sawtooth peak as a leak.
- No local full suites; no lever code beyond throwaway instrumentation
  (which ships only if it earns its keep as a permanent diagnostic, like
  AVM2_HEAP_STATS did).
- Docs-only/measurement session → CI only if instrumentation ships
  (`ci-only-when-observable`).

## Budget note (delegation)

Fable-led. Opus subagents: the per-title measurement runs (native + browser),
instrumentation patches, soak babysitting. Fable: the §2 decomposition, every
lever price, and the plan itself.
