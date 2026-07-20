# Session prompt — the title inversion: why we beat Ruffle 2.8x on Seedling and lose ~11x on RWK

**This is a DIAGNOSIS session, not a lever session.** Its deliverable is a
decision backed by evidence, not shipped perf code. Six consecutive RWK
levers have shipped (arc log `tools/divergence/perf/RWK_AB_STATUS.md`);
the last two returned ~1.1x and no-rig-measurable. That is the signal to
stop pulling and re-scout — the same instinct that produced the Step-0
census discipline in the first place.

## The observation that motivates it

Same runtime, same recompiler, same rig, measured within days:

| title | engine | ours | Ruffle | verdict |
|---|---|---|---|---|
| Seedling | FlashPunk | ~16.5 ms | ~46 ms | **we win 2.8x** |
| RWK | Flixel 2.21 | ~74 ms | ~6.4 ms | **we lose ~11x** |

That is a **~30x swing between two titles on one runtime**. Whatever
explains it is structurally bigger than anything the six levers touched
(they were 1.1x–1.5x each). If it names a real mechanism, that mechanism
is the multi-session arc worth opening next; if it dissolves under
scrutiny (see Step 0), the arc's target changes and we stop chasing a
number that was never real.

## Step 0 — validate BOTH anchors before theorising (mandatory, cheap)

The two Ruffle numbers were measured in different sessions, days apart,
by different drivers, and neither has evidence that the *workload* matched
ours:

- RWK's 6.4 ms (5.3 tick + 1.0 render) came from the lever-1 session via
  `/mnt/c/playwright/rw_o2ab/`. RWK gameplay is **bimodal ±30% and
  state-dependent** (the same doc records a "heavy regime" at ~340 ms vs
  a ~219 ms p50 for OUR build). If Ruffle was sampled in an early/light
  state — fewer entities, smaller quadtree, different level — while our
  window is a later/heavier one, a large part of "11x" is workload
  mismatch, not engine gap.
- Seedling's ~46 ms Ruffle number predates the entire property arc
  (~2026-07-14) and was measured on a different build of everything.

So: **re-measure both Ruffle anchors same-day, same rig, same states as
ours, with the workload pinned by evidence, not assumption.** Capture on
BOTH sides, simultaneously with the frame timings, something that proves
the scenes match — entity/object counts, level id, tick number, a
screenshot pair. `docs2/examples/avm2/{rwk,seedling}_ruffle/` already
exist; the Ruffle profiling shim (per-frame tick/render CPU) is in
[[ruffle-wasm-perf-shim-and-build]]. Method rules as ever: `rw_ab.py`
driver, ≥5 interleaved rounds, same-session ratios only, all-frames mean
+ p50 + stall count together.

**Report the corrected table before doing anything else.** If the RWK gap
collapses to (say) 3x on matched workloads, say so loudly — it rewrites
the arc's goal and this session's remaining steps.

## Step 1 — the leading hypothesis: object birth/death, not property access

The two engines differ in exactly the dimension our runtime is weakest:

- **RWK/Flixel rebuilds its collision quadtree from scratch every frame:
  ~9.2k object constructions/tick** (measured: FlxList 2.05M +
  FlxQuadTree 0.95M swept per 600 ticks = 93% of all sweeps).
- **Seedling/FlashPunk allocates ~nothing per frame** (its leak arc
  bottomed at ~9.5 KB/tick and its collect cadence is seconds apart).

Our per-object cost is: o1heap allocate → census enroll → slot defaults →
(later) mark → sweep → free. Ruffle's AVM2 uses `gc-arena` with bump
allocation and a generational/incremental collector — a fundamentally
cheaper birth/death path. **That predicts the inversion exactly**: we win
where allocation is rare (property access is our strength — six levers
made it so) and lose where allocation dominates.

Test it, don't assume it:
1. Attribute our RWK frame between allocation-driven work and everything
   else: alloc/ctor ~11% Ir + GC trace/sweep/enroll + the allocator
   itself. Sum honestly (post-lever-6 numbers, GC ON — the tier-3 arc
   would target the whole cluster, so size the cluster).
2. Profile **Ruffle** on RWK gameplay the same way we profile ourselves
   (CDP self-time on its wasm, profiling shim build). Does Ruffle's frame
   show a comparable allocation/GC cluster, or is it near-absent? This is
   the decisive comparison and nobody in the arc has run it.
3. Sanity-check the counterfactual: if allocation were free, what would
   our RWK frame be? (Ir minus the cluster is a crude but directional
   bound.) Does that land near Ruffle, or is there a second gap?

Competing hypotheses to keep alive rather than assume away: per-frame
blit volume differing between engines (blend_over is our #1 self-time at
6.8%, and Flixel/FlashPunk blit differently); the ~5x wasm multiplier
applying unevenly; Ruffle skipping work we do (audio, unimplemented
paths — check for silent no-ops that make its frame cheaper *incorrectly*,
which would make the anchor unfair in the other direction).

## Step 2 — the deliverable

A written verdict in `RWK_AB_STATUS.md` + a session memory answering:
1. What are the anchors on matched workloads? (corrected table)
2. What fraction of our RWK frame is object birth/death, end to end?
3. Does Ruffle pay a comparable cost, or is its allocator structurally
   cheaper?
4. **Therefore: is a nursery/bump-allocator + generational collector the
   next arc?** If yes, sketch it against our constraints — the conservative
   ext scan (a moving/bump allocator interacts badly with it), the arena
   bitmap membership test, `AVM2_GC_SWEEP_BUDGET`, the pinned-class-object
   and immortal-string surfaces, and rwic's ~96% arena occupancy. If no,
   name what is.

Do NOT ship a perf lever this session unless Step 0/1 hands you something
small, obvious and verified; the value here is the decision.

## Method rules (arc standard, binding)

- Native first for attribution (callgrind Ir 600t) — but note **Ir is not
  time** (lever 5: −13.1% Ir → ~1.1x wall) and **GC=0 runs are invalid for
  wall-clock A/B** (arms OOM at different tick counts:
  [[avm2-native-ab-recipe-gc0-invalid]]). Wall-clock uses default GC at
  equal tick counts.
- Rig: real-GPU Windows Chrome only; `rw_ab.py`; ≥5 interleaved rounds;
  judge mean + p50 + stalls together (the lazy-sweep p50 trap).
- Verify CI runs publish NOTHING now ([[ci-verify-run-results-clobber]]) —
  read their conclusion, never wait for or merge their results.
- A negative or deflationary result is a full session outcome. Record it
  the way the inline-slots and setup_locals findings were recorded.

## Budget note (delegation)

Fable-led. Opus subagents: the rig measurement legs (both engines, both
titles), Ruffle profiling-build setup, callgrind runs. Fable: workload-match
adjudication, the attribution arithmetic, the Ruffle-vs-us comparison, and
the verdict.
