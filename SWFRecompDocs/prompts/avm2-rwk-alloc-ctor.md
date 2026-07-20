# Session prompt — RWK alloc/ctor cluster (slot templates, locals memo, inline slots)

Sixth compute leg of the RWK perf arc. Read
`tools/divergence/perf/RWK_AB_STATUS.md` FIRST. State after lever 5
(`a35afa7b8`): rig all-frames mean RWK 74.7 ms / rwp 43.0 / Seedling 16.5
(Seedling is now ~2.8x FASTER than Ruffle — the north star is banked);
stalls zero; native 40.28B Ir. The post-lever-5 map:

- **alloc/ctor = the largest addressable cluster, 11.4%**:
  `slots_init_defaults` 4.76 + `setup_locals` 4.10 + `o1heapAllocate` 2.58.
  (This is ~9.2k Flixel constructions/tick — FlxList/FlxQuadTree churn —
  paying a per-element defaults loop, a per-call locals loop, and one-to-two
  o1heap allocations each, then the mirrored free cost at sweep.)
- blend_over 6.82% is #1 but is pure pixel work (wasm runs the SIMD spans)
  — leave it. getproperty IC-hit residue ~9% is the recompiler endgame —
  note-only. GC tier-2 leftovers: trace ~15 ms pause (generational,
  separate session), sweep-budget tuning, and **lever 4 "inline slots" —
  which lands HERE, not in a GC session** (it's an allocation-shape
  change; the GC only sees fewer frees).

Size expectations honestly (the lever-5 lesson is written in the status
doc: −13.1% Ir bought ~1.1x — Ir is not time): this cluster is ~11%
Ir + real allocator work; call it a ~1.1x-class session unless Step 0
surprises.

## Step 0 — census before code (arc law)

1. Read `avm2_slots_init_defaults` (avm2_class.c ~662) COMPLETELY first:
   avm2_class.c:519's comment says some entries realize the METHOD SCOPE
   in there (closure slots?) — those entries can never be templated.
   Classify per-class: how many vtable entries have (a) non-pointer
   constant defaults (int/uint/Number/Boolean/null/undefined), (b)
   pointer defaults (string/namespace constants), (c) per-object
   realization (scopes/closures)?
2. Instrument constructions/tick by class on the plan_k TAS (the
   swept-class histogram tooling from `avm2-rw-gc-duty-cycle` gives the
   same answer from the death side: FlxList 2.05M + FlxQuadTree 0.95M per
   600 ticks — confirm the birth side matches) + slot counts of the hot
   classes + the o1heap allocation-count/size histogram per tick (the
   APROF `__builtin_return_address` temp tool from
   `avm2-raw-alloc-reclamation` attributes alloc sites in one rebuild).
3. `setup_locals`: the status doc says it recomputes an `unchecked` flag
   from method-static data EVERY call — confirm, and count calls/tick.

## Levers (one at a time, each A/B'd alone)

A. **setup_locals memo** (cheapest, do first): per-method one-time memo
   of the method-static computation (the `unchecked` flag et al.), plus —
   if the census shows the locals-init loop itself is the cost — a
   per-method precomputed locals template image. Method-static data is
   immutable after load; a memo keyed on the method struct is sound and
   deterministic. Expected: most of the 4.10%.
B. **slots_init_defaults template**: per-class precomputed default-slot
   image built once at class-define time; construction = memcpy + patch
   loop over ONLY the non-templatable entries (pointer-kind defaults +
   scope-realizing entries). **GC HAZARD RULE (recorded in the lever-5
   memory): the template must hold only non-pointer kinds.** Nuance the
   session may exploit AFTER verifying: default STRING constants come
   from the static pool (rodata, gc_flags==0, never swept — see
   avm2-collectable-strings) — if a pointer default is PROVABLY a
   static-pool/immortal pointer it could be templated too; anything
   census-tracked (or doubtful) stays in the patch loop. Verify with a
   GC-stress soak specifically covering template-constructed objects.
C. **Inline slots (GC tier-2 lever 4, the layout-SAFE variant):** allocate
   object + slots in ONE o1heap allocation, keeping the `Avm2Object.slots`
   POINTER field aimed at the inline tail (`(Avm2Value*)(o + 1)` region).
   No struct layout change → no ABI break for generated TUs (verify:
   `avm2_op_getproperty_slot` and friends read through the pointer — they
   don't care where it points). free_innards / any slots-realloc path must
   learn the ownership rule (only free `slots` when it is NOT the inline
   tail; a slots GROW path — does one exist? dynamic classes? — must fall
   back to a separate allocation cleanly). Kills one alloc + one free per
   object (~half of o1heapAllocate's 2.58% + a slice of residual sweep
   cost) and improves construction locality. Census first: what fraction
   of hot-class constructions have slot_count known at construction and
   never regrow?
D. (only if A-C leave budget) sweep-budget tuning: `AVM2_GC_SWEEP_BUDGET`
   default 25k entries ≈ 2-3 ms/tick — re-derive against the post-lever
   frame times; a smaller budget may now fit the frame better. Pure
   config; measure stall count + all-frames mean.

## Method rules (the arc's, binding)

- Native first (callgrind Ir 600t GC=0 + user-s 2900t ×3 interleaved);
  coverage counters before intuition; plan_k TAS; TZ=NPT-5:45.
- Rig A/B: `rw_ab.py`, `__swfPerf.cpu`, ≥5 interleaved rounds RWK +
  3-round spot-checks on Seedling and rwp (levers here are runtime-wide);
  judge all-frames mean + p50 + stall count together (post-GC-tier2 p50
  trap documented in the status doc).
- Lever B/C touch GC-adjacent invariants → the FULL GC ladder applies:
  traces + 600 CPU-dump frames byte-identical normal/stress/GC=0; the 3+1
  avm2_gc_* + typed-value regression tests in 3 modes; a stress soak on
  template/inline-constructed objects; soak targets (RWK ~1.03 KB/tick,
  Seedling-teleport ~9.5 KB/tick) not regressed. rwic note: it runs
  eager-sweep by the 1/8-headroom valve — include a native rwic probe if
  lever C changes free ordering.
- Verify pattern: extend the verify-defines family if a lever has a
  cross-checkable invariant (e.g. -DAVM2_SLOTTPL_VERIFY comparing
  templated vs loop-initialized slot images per construction); run the
  all-verify-defines CI on top of both normal modes; zero pass→fail
  (avm2 823/1215, regression 56 at 100%).
- ABI TRAP standing rule: lever C is DESIGNED to avoid a layout change —
  if the design drifts into one (new field, moved field), stop and
  re-justify; any by-value-in-generated-TU struct change = FRESH=1
  everywhere. Re-probe padding claims per change.
- Finish per `.claude/pipeline-handoff.md`: both CI modes (+ verify CI),
  all 7 demos FRESH-redeployed on runtime change, Archipelago-CC
  flashPanel restage, RWK_AB_STATUS update (same table format), session
  memory.

## Budget note (delegation)

Fable-led. Opus subagents: rebuilds, TAS/callgrind legs, rig rounds, CI
watching. Fable: the slots_init_defaults classification, the template/GC
soundness argument, the inline-slots ownership rule, every
free-vs-retain decision.
