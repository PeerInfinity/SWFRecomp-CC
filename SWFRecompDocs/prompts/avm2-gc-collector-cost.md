# Session prompt — AVM2 GC collector-cost reduction (tier 2 after the adaptive watermark)

## STATUS 2026-07-19: levers 1-3 LANDED — see the GC section of
## `tools/divergence/perf/RWK_AB_STATUS.md` + memory
## `avm2-gc-tier2-collector-cost`. RWK collect pause 73 → ~23 ms native; on
## the rig the >250 ms stalls went 6/round → 0 and the all-frames mean
## 103.5 → 81.6 ms. Still open from this prompt: **lever 4 (inline slots)**,
## **generational collection**, and tuning `AVM2_GC_SWEEP_BUDGET`. Note the
## remaining pause is now dominated by TRACE (~15 ms), not sweep.

## 2026-07-19 REFRESH (post property-arc levers 2-4) — WHY THIS SESSION IS NOW

The base-compute arc (RWK_AB_STATUS.md) has taken rig gameplay
219 → 165 → 105 → **69 ms** p50 (HEAD `a2e4758fb`). The GC pause did NOT
shrink with it: RWK still collects every ~21 ticks and the wasm pause is
~675 ms (the 5x-native constant below). At 69 ms/frame that is ~1.45 s of
compute punctuated by a ~675 ms freeze — **the GC is now ~30-40% of
wall-clock and its share GROWS with every future compute lever.** This is
the biggest single lever left in the game.

Session shape: execute the tier-2 levers below (bitmap membership → epoch
marks → lazy sweep, in that order, ONE at a time, A/B'd individually).
Lever 4 (inline slots) and generational stay out unless the first three
leave the pause dominated by free() cost.

Step 0 — re-baseline at HEAD first (cheap, tooling exists): the pause
model below was measured pre-levers-2-4. Nothing in those levers touches
allocation volume, so cadence/census should be unchanged — VERIFY that
(AVM2_GC_TIME temp timer + phase timers from the `avm2-rw-gc-duty-cycle`
session memory; scratch-build recipe in RWK_AB_STATUS). Also re-measure
GC-on vs GC=0 native user-s at HEAD: at 46B Ir the GC's relative share is
much bigger than the ~8% recorded below at 92B.

Method rules accumulated by the arc (binding here too):
- Rig A/B: `/mnt/c/playwright/rw_scope_ab/rw_ab.py` driver (rw_perf.py
  hangs); `__swfPerf.cpu` gameplay p50 + the >250 ms discrete-stall
  count/spacing (THE collect signature — rAF >100ms counters mislead);
  ≥5 interleaved rounds; RWK gameplay is bimodal ±30%, only same-session
  interleaved ratios count. WebGPU screenshots blank on this rig.
- Seedling + rwp must be in the A/B set too: collector changes hit every
  game; Seedling (low churn, 30 fps at target) is the "don't regress the
  good case" control, and its 3.7 s collect cadence hitches should
  SHRINK.
- Verification precedent from the property arc: an all-verify-defines CI
  run (FIND/SLOT/SET/COERCE) on top of both normal CI modes; add the GC
  ladder from the bar section below. Soak targets updated: RWK ~1.03
  KB/tick and Seedling-teleport ~9.5 KB/tick still stand.
- ABI TRAP: Avm2Object/Avm2String layout changes (epoch field!) →
  FRESH=1 wasm rebuilds EVERYWHERE + all 7 demos redeployed + the
  Archipelago-CC flashPanel restage. Appended fields zero-init in the
  rodata string pool (the avm2-collectable-strings precedent) — check
  padding first; gc_mark is a small int with likely adjacent padding.
- Fable-led; Opus subagents for rebuilds, TAS/callgrind legs, rig rounds,
  CI watching. Fable: the GC invariants, sweep/mark code, and every
  free-vs-retain decision.

(Original tier-1-era context follows — its per-object cost constants and
lever designs remain the working plan; its "before" numbers predate the
property arc.)

Context (2026-07-18, RW-demo perf session): the RW-family "unplayably slow +
rhythmic pause" browser report was attributed NATIVELY, with per-collect
timers + a swept-class histogram, to the GC running at ~50%+ duty cycle
during Flixel gameplay:

- The watermark counts GROSS bytes since last collect (default 4 MB).
  RWK gameplay grosses **3.27 MB/tick** → a collect every **2 ticks**.
- Each RWK gameplay collect: **~55 ms native** (solo; census ~105k objects,
  live 85k, ~20k swept, 14.6k strings). Phases: snap ~23 ms (census walk +
  qsort of the membership snapshot), trace ~21 ms (live mark), sweep ~12 ms,
  strings ~2 ms.
- **The churn is the GAME's, not ours**: swept-class histogram over 600
  ticks = FlxList 2.05M + FlxQuadTree 0.95M = **93%** of 3.22M swept
  (~9.2k objects/tick). Flixel rebuilds the collision quadtree from scratch
  every frame; RWK's Flixel vintage has no pooling. Rectangle 39k, FlxPoint
  159k, everything else noise. rwp PlayState shows the same shape
  (12.8k swept/collect every 2 ticks, ~25 ms pauses over a 19k live set).
  Seedling (FlashPunk, no quadtree) grosses ~nothing — that's the whole
  Seedling-vs-RW split.
- Fix shipped in tier 1: **adaptive watermark** (avm2_gc.c) —
  `watermark = clamp(live_allocated_bytes, base 4MB, min(256MB, headroom/4))`
  retargeted after each completed collect via `heap_allocated_bytes()`
  (o1heap diagnostics), PLUS a census-entry trigger (`AVM2_GC_MAX_ENROLL`,
  default 200k new objects+strings since last collect) that bounds the
  snap+sweep pause for big-live-set games whose byte watermark would allow
  huge dead-entry accumulations. Collect frequency now tracks retention,
  not churn. Measured (RWK 3000-tick TAS, solo, native): 1364 → 126
  collects, GC CPU 82 s → 15.1 s (5.4x), pause 55-65 → 115-135 ms every
  ~21 ticks (0.7 s), retention/live census byte-identical, traces + 600
  CPU-dump frames byte-identical normal/stress/GC=0.

Rig verification of tier 1 (2026-07-18, real-GPU Windows Chrome,
before→after, gameplay CPU/frame median): rwk 484→205 ms, rwp 152→127,
rwf 47→42, rwic 24→23 (~29 fps), seedling 32→22 (now holds 30 fps).
Collects became discrete + metronomic (rwic cv 0.01). TWO measured
constants tier 2 must respect: **wasm collect pause ≈ 5x native**
(RWK: ~130 ms native → ~675 ms wasm), and **rwk's residual ~200 ms/frame
is NON-GC base compute** — profile RWK PlayState via CDP self-time
(seedling-perf method) as its own investigation before touching the
collector further for that game.

UPDATE 2026-07-19 (base-compute session, `RWK_AB_STATUS.md`): that
investigation ran. The base-compute #1 was the findpropstrict scope walk;
the scope-hit IC (`8caf10e4e`) took RWK gameplay 219→165 ms p50 on the rig
(native GC=0 1.54x). Constants here still hold: the 5x wasm pause
multiplier is NOT a build-flag artifact (ABC_OPT -O2/-O3 A/B'd: no effect),
and GC-on remains ~+8% native Ir over GC=0 at the adaptive watermark. The
census qsort inside gc_collect is ~6.5% of wasm frame self-time in default
mode — it dies with the tier-1 sort or tier-2 membership redesign as
planned. Ruffle GAMEPLAY anchor corrected: 6.4 ms/frame p50 (old 5.5 was
menu).

## Why tier 2 exists — the measured cost model

Native per-object collector costs (RWK, -O2): snap ≈ 0.22 µs/census-obj,
sweep walk ≈ 0.06, free ≈ 0.29/dead, trace ≈ 0.25/live. With churn g
(objs/tick) and interval T (ticks):

    pause(T) ≈ [trace·L + strsnap] + (snap+walk+free)·(L + g·T)
             ≈ 45 ms + 5.2 ms per interval-tick      (RWK numbers)
    duty(T)  ≈ 1.36/T + 0.158                        (native floor ~16%!)

The 0.158 floor = per-object census overhead × 9.2k/tick churn. The
watermark can trade hitch size vs frequency along this curve but cannot go
below the floor, and wasm multiplies everything ~1.5-2x. Getting RW-family
gameplay genuinely smooth needs the per-object constants cut.

## Tier-2 levers, in order (design notes)

1. **Kill the object snapshot (snap ≈ 0.22 µs/obj → ~0).** The sorted
   census snapshot exists only for `census_contains` in the conservative
   ext scan. Replace with an **arena bitmap**: 1 bit per O1HEAP_ALIGNMENT
   cell over the arena (`heap_capacity_bytes/ALIGN/8`; ~16 MB for a 2 GB
   wasm arena — decide native lazy-commit story), set on
   `avm2_gc_enroll`, cleared on sweep. Membership = O(1) bit test.
   Strings keep their (small, 15k) range snapshot.
2. **Epoch marks instead of the clear pass.** `gc_mark` clearing is the
   other reason the clear pass walks every census object. An epoch counter
   ("marked" ⟺ `mark_epoch == current`) makes clearing O(1). CAREFUL:
   pins (`gc_mark & 2`) are persistent — keep pins as a separate bit/flag,
   only the mark bit becomes epoch-relative. Check Avm2Object layout for
   padding before growing the struct — RecompiledABC .o files bake the
   layout (FRESH=1 everywhere if it changes; see avm2-collectable-strings
   memory for the precedent).
3. **Lazy (incremental) sweep.** Marking must stay atomic between ticks,
   but sweeping unmarked garbage can be budgeted (~2 ms/tick) across
   subsequent ticks: allocate-black during an in-progress sweep (epoch
   makes this trivial), next mark cannot start until the sweep cursor
   finishes. This converts the g·T sweep term from a pause into amortized
   background cost; the remaining pause is just trace(L) ≈ 21 ms native.
4. **Inline slots into the object allocation** (halves allocs AND frees
   for slot-only objects like FlxList — slot_count is known at
   construction). Allocator-layout change; measure first whether free
   cost still matters after 3.
5. (Real project, later) generational collection — the churn profile
   (stable 85k live, 9.2k/tick dying young) is the textbook case.

Bar for ANY of this: traces byte-identical normal/stress/GC=0 (RWK 3000-tick
TAS + CPU-dump frame grading), the 3 avm2_gc_* regression tests in 3 modes,
soak targets (RWK ~1.03 KB/tick, Seedling-teleport ~9.5 KB/tick) not
regressed, both CI modes zero pass→fail, FRESH wasm rebuilds if any layout
changed.

Measurement tooling from the tier-1 session (rebuild recipe, TEMP
AVM2_GC_TIME per-collect timer + phase timers + swept-class histogram,
plan_k TAS workload): see the session memory `avm2-rw-gc-duty-cycle` and
scratchpad `rwk_build` under the 66bdbf3a session dir.
