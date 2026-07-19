# Session prompt — RWK property-read endgame (GET residue + find-IC call overhead)

Third leg of the RWK perf arc (after the adaptive-watermark GC fix and the
findpropstrict scope-hit IC, `8caf10e4e`). Current honest state
(`tools/divergence/perf/RWK_AB_STATUS.md` — READ IT FIRST, it has the full
post-lever profile and the A/B method that worked):

- Rig gameplay `__swfPerf.cpu` p50: **164.6 ms** (~6 fps). Goal 33 ms.
  Ruffle plays the same SWF's GAMEPLAY at **6.4 ms p50** (measured, not the
  old menu-only 5.5). This is a multi-session arc; this session's job is
  the next honest 1.3-2x, not the whole 5x.
- Post-lever native callgrind (600 ticks GC=0, 91.7B Ir) ranks the residue:
  **GET/property-read ~23%** (getproperty_static_ic 9.5 + resolved_get 7.9
  + vt_index_get/value_vtable/leftover find), **coerce ~10.7%**,
  **findpropstrict_ic SELF 8.75%** (pure guard+call overhead, ~50 instr ×
  158M replays/600 ticks), SET ~5%, alloc/ctor ~4.5%, CPU blit ~5.7%,
  mn_name ~2.65%. Wasm CDP mirrors the same shape (multiplier is uniform
  per-instruction — no wasm-specific hotspot; cutting instructions is the
  only way down).

## The new datum this prompt adds (measured 2026-07-19, HEAD recompiled RWK)

Grep of `~/CC/rwk_build/recompiled/RecompiledABC`:
**getproperty_slot 308** vs getproperty_static_ic 5,439 vs
findpropstrict_ic 6,082 (setproperty 774, initproperty 1,044).
Seedling got 5,039 this-slot + 1,432 static-slot sites from the same
recompiler. **The Seedling compile-time GET levers structurally missed
Flixel — 5.4% slot coverage.** The GET residue and the find-IC overhead are
probably the SAME underlying miss: Flixel-era code reaches members in ways
the current `analyzeSlotSpec` gates reject. Figure out WHY before building
anything.

## Step 0 — mandatory measure-first gate (the Seedling lesson, 3x proven)

The Seedling arc gated out three consecutive levers at Step-0 because the
sites weren't hot (`seedling-instance-slot-lever-gated-out` memory:
non-this instance-slot spec covered 0.4% of hot GET drivers in FlashPunk —
DO NOT assume that verdict transfers to Flixel; RWK's quadtree rebuild
reads OTHER objects' fields all frame). Reuse the existing read-only
tooling before writing any emitter code:

1. `SWF_SCOUT_TYPES=<csv>` scout (abc_emit.cpp, from the Seedling arc) on
   RWK: classify every static property op by receiver static type.
2. Weight by the ACTUAL hot methods from the post-lever profiles:
   abc0_m484 / m486 / m482 / m487 (Flixel quadtree/update cluster) — the
   RWK_AB_STATUS caller-attribution table and raw JSONs have the full list.
3. Answer specifically:
   - Why did this-slot spec reach only 308 sites? (Candidates: unqualified
     member reads compile as findpropstrict+getprop instead of
     getlocal0+getprop; `subclassRedeclares` too conservative over the
     FlxBasic→FlxObject→FlxSprite chain; non-sealed/dynamic classes;
     non-ABC ancestors.) Each rejected-site reason is countable in
     `analyzeSlotSpec` — add a temp census counter, don't guess.
   - What fraction of the 158M find replays/600 ticks are the
     lscope[0]-hit kind at sites whose multiname resolves AT COMPILE TIME
     to an instance trait of the enclosing class? (Those are candidates
     for resolving the whole findpropstrict+getprop pair statically.)
   - What receiver types dominate hot GETs: this / other-typed-instance /
     class-static / native flash.geom?

## Candidate levers (rank by Step-0 numbers × the profile %, then build ONE at a time)

A. **Compile-time resolution of with-free unqualified own-member access**:
   where the method is scope-stable and the multiname statically resolves
   to a trait of the enclosing instance class (and no activation/local
   shadowing is possible), emit the receiver directly (local0) and, where
   the slot gate passes, a bare slot read — collapsing
   findpropstrict_ic (8.75% self) + getproperty_static_ic + resolved_get
   for those sites. Semantics bar: the scope walk's answer must be
   PROVABLY invariant — argue it from the ABC (traits, scope shape),
   verify with an `AVM2_FIND_VERIFY`-style cross-check build, and respect
   the known non-cacheable cases from 8caf10e4e (with-tainted, scope_n>1
   locals, activation preambles).
B. **Non-this typed-instance slot spec** (the lever Seedling gated OUT) —
   only if Step-0 shows it hot in Flixel (quadtree node/object field
   reads). Reuse `avm2_op_getproperty_slot` + `-DAVM2_SLOT_VERIFY`;
   landmines list in `seedling-perf-compile-time-specialization` memory
   (subclass shadowing, getters, dynamic classes, exact slot-index match).
C. **Inline the find-IC fast path in generated code** (drop the function
   call; guard + return in the emitted C, slow-path call otherwise) — the
   mechanical 8.75%-self lever if A doesn't subsume it.
D. **Store path**: setproperty_resolved is 67% under op_initproperty with
   coerce_to_type_mn at 49% of the store path (constructor-time typed
   stores in the churn). Compile-time coerce elision for typed init
   stores / baked-slot init. Note `coerce_to_type_mn` has ZERO emitted
   sites in recompiled RWK — it's all runtime-internal from
   initproperty/setproperty, so this is a runtime+emitter lever, not a
   site rewrite.
E. **Blit check** (~5.7%): verify RWK's blend_over/bd_copy_pixels path
   actually engages the Seedling SIMD blit (`seedling-blit-simd` memory);
   if not, find why (format/alpha branch).

Do NOT touch the GC this session (census-qsort ~8.8% default-mode is the
tier-2 collector prompt, `avm2-gc-collector-cost.md`, separate session).

## Method rules (all proven this arc — deviate only with a reason)

- NATIVE FIRST: callgrind Ir (600-tick GC=0 TAS) + user-seconds (2900-tick
  TAS, interleaved ×3) name and size the lever before any wasm build.
  Counter-instrument coverage (the scope-IC session's counters caught that
  the first version missed the bigger half — counters, not intuition).
- Workload: RWK plan_k TAS (`ruffle-tests/_rwk_tas/`, events file in the
  66bdbf3a scratchpad; rebuild recipe in RWK_AB_STATUS + the
  `avm2-rw-gc-duty-cycle` memory). TZ=NPT-5:45, MOCK_DATE_TIME default.
- Rig A/B: Windows Chrome real GPU only (`WINDOWS_PLAYWRIGHT_FROM_WSL.md`);
  driver `/mnt/c/playwright/rw_scope_ab/rw_ab.py` (goto → poll
  `Module.calledRun` → runSwf; rw_perf.py hangs at button-enable). Metric
  `__swfPerf.cpu` gameplay p50, ≥5 interleaved rounds, report the
  distribution. WebGPU screenshots read back blank on this rig — never
  gate on pixels there.
- Correctness bar per lever: cross-check verify build
  (`AVM2_FIND_VERIFY` / `AVM2_SLOT_VERIFY` / new equivalent) clean over
  ≥1200 ticks; traces + CPU-dump frames byte-identical normal/stress/GC=0;
  both CI modes zero pass→fail (avm2 823/1215 is the current baseline);
  the game is never the oracle — new semantics get a regression test in
  `ruffle-tests/tests/swfs/regression/`.
- **ABI TRAP (cost a debugging cycle last session):** any change to a
  struct the generated ABC TUs instantiate by value (Avm2FindCache et al.)
  requires FRESH=1 full wasm rebuilds — incremental builds ship a wasm
  that boots then heap-corrupts on first input.
- Finish per `.claude/pipeline-handoff.md`; redeploy the AVM2 demos that
  benefit (rwk at minimum; all seven if the runtime changed); restage the
  Archipelago-CC flashPanel wasm if a staged .c changed; update
  RWK_AB_STATUS.md with the same A/B table format; write a session memory.

## Budget note (delegation)

Fable-led. Opus subagents for: rebuilds, TAS/callgrind runs, rig A/B
legs, CI watching. Fable: Step-0 census interpretation, lever choice,
emitter/runtime code, semantics arguments, reading the distributions.
