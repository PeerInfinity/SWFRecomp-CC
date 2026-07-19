# Session prompt — RWK base-compute profile (the non-GC ~200 ms/frame)

> **RESULT 2026-07-19 — lever 1 landed, session complete.** Flag check:
> ABC_OPT ruled out. Profiles (CDP + native callgrind) named the
> findpropstrict SCOPE WALK (~30% of frame); the scope-hit IC
> (`8caf10e4e`) delivered native 1.54x / rig 1.33x (219→165 ms p50),
> byte-identical + FIND_VERIFY clean + both CI modes zero drift. Full log,
> post-lever profile, and next-lever map:
> `tools/divergence/perf/RWK_AB_STATUS.md`. Re-running this prompt should
> START from that lever map (GET residue ~23%, coerce ~11%, IC guard
> inlining ~9%), not re-derive it.

You are profiling and fixing **RWK's residual gameplay cost**. After the
adaptive watermark (`fd5931661`), GC is off the critical path, but RWK
gameplay still runs **~205 ms/frame in browser wasm (4.8 fps)** and **~40
ms/tick native at GC=0**, while **Ruffle plays the same SWF at ~5.5 ms / 60
fps** (menu anchor — get a Ruffle *gameplay* number early for the honest
target). rwp (127 ms) is the same class; fixes should help it for free.
This is the Seedling-perf situation replayed on Flixel: Seedling went
280→~47 ms (~6x) to Ruffle parity through profile-named levers. Same
discipline, new engine.

Read first: memories `avm2-rw-gc-duty-cycle` (all measured constants; the
5x wasm-vs-native multiplier; `__swfPerf.cpu` not rAF),
`seedling-perf-hotpath-is-property-lookup` (the method + its lessons),
`seedling-fresh-profile-poststep4-lever-map` (**the #1 guessed lever was
wrong even WITH a profile** — measure, don't assume),
`profile-game-native-n-is-noisy` (never A/B single totals). Tools:
`tools/divergence/perf/seedling_cdp_profile_win.py` +
`WINDOWS_PLAYWRIGHT_FROM_WSL.md` (rig CDP profiling; symbolicated build via
`EMCC_CFLAGS=--profiling-funcs`), `SEEDLING_AB_STATUS.md` (report format
precedent).

## Known facts (don't re-derive)

- RWK PlayState churns **~9.2k objects/tick** (FlxList + FlxQuadTree = 93%
  of sweeps — Flixel 2.21 rebuilds the collision quadtree every frame, no
  pooling). The game's code is fixed; only our cost-per-operation is in play.
- Native plan_k TAS: 3000 ticks ≈ 121 s at GC=0 (~40 ms/tick). Deterministic
  and byte-reproducible — perfect for repeated profiling runs.
- wasm gameplay ≈ 5x native (205 vs ~40) — the SAME multiplier as GC pauses
  (675 vs 135 ms). Whether that's a real wasm tax (ASYNCIFY? -O1 ABC TUs?)
  or coincidence is itself a question this session should answer.
- The Seedling IC arc landed per-site inline caches for
  getproperty/callproperty/setproperty and name-hash indexes for
  vtable/domain. **findproperty/scope-chain lookup is the ONE un-IC'd
  lookup** (seedling next-lever #2). Flixel leans on statics (`FlxG.…`,
  `FlxU.…`) — getlex/findpropstrict density may be far higher than
  FlashPunk's.
- Prior session builds survive in scratchpads (`rwk_build` in session
  66bdbf3a's scratchpad, plan_k events; `rwp_build2`/`rwic_play` in
  e2286e83's) — reuse per the rebuild recipe in `avm2-rw-gc-duty-cycle`.

## Method — native first, rig second

1. **Cheap build-flag check before any profiling** (~30 min, could be the
   headline): the wasm ABC TUs compile at `ABC_OPT=-O1` (build_wasm_avm2.sh
   default; RWK's generated C is small — the 716 KB SWF is nothing like
   Seedling-teleport's 13 MB TU). A/B the rwk demo at `ABC_OPT=-O2` (and
   -O3 if -O2 moves) on the rig. Also time a native `-O2 -flto`-style
   sanity point if quick. If the 5x wasm multiplier collapses, the session
   pivots to "ship better flags" + a much smaller profile pass.
2. **Native profile** (Linux `perf record`/flamegraph on the solo -O2
   native build, plan_k TAS, GC=0 AND default): self-time ranking over a
   fixed tick window. This is cheaper and less noisy than CDP — do it
   FIRST; the 40 ms/tick native floor is 7x off Ruffle all by itself, so
   most of the win is visible natively.
3. **Rig CDP profile** (adapt `seedling_cdp_profile_win.py`;
   `--profiling-funcs` build): confirm the native shape holds in wasm and
   attribute whatever the wasm-only extra is. `__swfPerf.cpu` for frame
   cost, never rAF-derived counters.
4. **Lever, A/B, repeat**: fix only what the profile names. Every lever
   gets an end-to-end frame-time A/B on the rig (interleaved runs,
   distributions, ±10% noise floor — the writeTexture lesson: a big
   self-time % can be overlapped work that doesn't gate the frame).

## Suspect list (hypotheses for the profile to kill, ranked by prior)

1. **Object allocation + construction path under churn** — 9.2k
   ctor-chains/tick (FlxList/FlxQuadTree `new`): `avm2_op_construct` →
   class init → `avm2_object_new` → vtable/dyn-prop setup → census enroll,
   plus super() chains per object. Seedling never stressed this path;
   per-object constant costs that are invisible at 100 allocs/tick are the
   whole frame at 9.2k. If confirmed, levers: slim the per-object init
   (lazy dyn-prop table, pre-sized from class), a per-class ctor fast path,
   cheaper census enroll.
2. **findproperty / getlex / scope-chain resolution** — the un-IC'd lookup;
   Flixel's static-heavy style (`FlxU.overlap`, `FlxG.*` everywhere) may
   hammer it. Lever shape is pre-designed in the seedling memory (per-site
   global-domain entry cache keyed on domain identity; scope-chain part
   needs care).
3. **Quadtree traversal call patterns** — deep recursive
   callproperty/overlap callbacks; check whether IC hit-rates collapse here
   (polymorphic receivers defeat monomorphic ICs).
4. **wasm-specific tax** — ASYNCIFY instrumentation on hot recursive paths,
   -O1 ABC TUs (see step 1), or memory-growth/cache effects. Only chase
   after native is understood.

## Rules

- Measure before fixing; one lever at a time; every claim gets an A/B.
- All changes byte-identical: traces + CPU-dump frames across
  normal/stress/GC=0, zero avm2 suite drift, both CI modes zero pass→fail
  (the IC-arc bar). Recompiler changes (new IC shapes) need the same
  treatment as the Seedling emitters got.
- The game is never the oracle; any behavioral fix discovered en route gets
  its own graded test.
- Redeploy all RW demos + Seedling after landing; restage Archipelago-CC
  if a staged .c changed. Update the tier-2 collector prompt's constants if
  this session invalidates any (e.g. if the 5x wasm multiplier turns out to
  be a build flag).
- Success bar: **rwk gameplay ≥ 30 fps on the rig** is the goal;
  Ruffle-gameplay-parity-class (the Seedling precedent) is the stretch.
  If the session lands short with levers exhausted, write the honest
  floor + remaining lever map (the seedling-perf memory pattern).

## Budget note (delegation)

**Fable-led, Opus legs.** Opus: builds (flag matrix, --profiling-funcs,
bisect builds), TAS runs, rig sweeps, profile collection/symbolication,
CI babysitting. Fable: reading the profiles, choosing levers, IC/emitter
design, and the correctness argument for every hot-path change (the
Seedling IC invariants — plain-object receivers, no_index exclusion,
count-guarded replay — are the template and the bar).

Finish per `.claude/pipeline-handoff.md`; update the RW sequels plan doc +
avm2 `CURRENT_STATUS.md`; session memory with the profile table
(before/after self-time), per-lever measured wins, and the final
fps-per-game scoreboard.
