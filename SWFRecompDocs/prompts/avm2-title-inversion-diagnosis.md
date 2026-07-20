# Session prompt — the title inversion: why we beat Ruffle 2.8x on Seedling and lose ~11x on RWK

**This is a DIAGNOSIS session, not a lever session.** Its deliverable is a
decision backed by evidence, not shipped perf code. Six consecutive RWK
levers have shipped (arc log `tools/divergence/perf/RWK_AB_STATUS.md`);
the last two returned ~1.1x and no-rig-measurable. That is the signal to
stop pulling and re-scout — the same instinct that produced the Step-0
census discipline in the first place.

## The observation that motivates it

Same runtime, same recompiler, same rig, measured within days:

| title | engine | ours | Ruffle (as recorded) | apparent verdict |
|---|---|---|---|---|
| Seedling | FlashPunk | ~16.5 ms | ~46 ms (stale) | we win 2.8x |
| RWK | Flixel 2.21 | ~74 ms | ~6.4 ms (**suspect — see Step 0**) | we lose ~11x |

That would be a **~30x swing between two titles on one runtime** —
structurally bigger than anything the six levers touched (1.1x–1.5x each).
But **Step 0 shows the RWK Ruffle figure is almost certainly a title-screen
measurement**, so the headline gap is unestablished and the first job is
to replace it with a real one. Both outcomes are valuable: a surviving
large gap names the next multi-session arc; a collapsed one retires a
target we have been steering by for four sessions.

## Step 0 — the RWK Ruffle anchor is almost certainly NOT gameplay

**Do not treat 6.4 ms as a gameplay number.** Re-reading the lever-1 raw
data (`/mnt/c/playwright/rw_o2ab/rwk_ruffle_gp.json`) against the user's
suspicion (2026-07-20) that it was captured on the title screen:

| Ruffle phase | total p50 | tick p50 | rAF p50 |
|---|---|---|---|
| `ruffleperf_menu` (600 frames) | 6.2 ms | 5.0 | 16.7 |
| `ruffleperf_gameplay` (600 frames) | **6.4 ms** | 5.3 | 16.7 |

**A +3% menu→"gameplay" delta is not credible.** Over the same transition
our build went ~6 ms → ~450 ms (75x) at that time; a Flixel PlayState
rebuilding its whole collision quadtree every frame cannot cost 3% more
than a static title screen with two buttons. The run also saved **no
screenshot** (only the JSON), so nothing attests to the state; and an
earlier session's rwk_ruffle probe is on record as having stayed on the
title screen because a center-click missed the "Play Game" button — the
same failure, one session earlier. Treat the 6.4 ms as menu/attract and
the "~11x gap" as **unestablished**.

Likely mechanical cause, already documented in
`SWFRecompDocs/plans/avm2-robot-wants-sequels.md`: **click coordinates are
CSS pixels of the displayed canvas, not the game's internal 640x480
space** — the canvas renders ~779x585 (scale ~1.217), so internal
(320,176) is CSS (389,214). Center-clicking or clicking internal
coordinates silently does nothing.

**Get a real number, with the state proven:**
1. **Preferred — identical teleport SWF on BOTH sides** (the user's
   suggestion, and the cleanest experimental design): inject AS3 that
   boots straight into PlayState, exactly as `seedling_teleport` does
   (precedent: [[seedling-teleport-gameplay]],
   [[ruffle_injection_techniques]]). Loading the SAME teleport SWF in
   Ruffle and in our demo removes the click-reliability variable
   entirely AND guarantees an identical start state — a better comparison
   than clicking through, not a compromise. Note the honest caveat in the
   write-up: the anchor is then "RWK PlayState from a scripted start",
   not "RWK as a player reaches it".
2. Fallback — real press-release click at CSS-corrected coordinates
   (down, ~100 ms, up; Flixel's FlxButton needs press and release on
   separate ticks).
3. **Whatever the method: prove the state.** Save a screenshot per phase
   on both sides, plus an in-frame quantity that shows the scene matches
   (HUD clock/level, entity count). A phase labelled "gameplay" with no
   evidence is what produced this whole detour.

Seedling's ~46 ms Ruffle anchor is also stale (pre-property-arc,
~2026-07-14, different build of everything) — re-measure it the same day,
same rig, same way.

**Report the corrected table before doing anything else**, and state
plainly how much of the claimed 11x survives. If it collapses to 2-3x —
or inverts — that rewrites the arc's goal and the rest of this session.
`docs2/examples/avm2/{rwk,seedling}_ruffle/` exist; the per-frame
tick/render shim is [[ruffle-wasm-perf-shim-and-build]]. Method: `rw_ab.py`,
≥5 interleaved rounds, same-session ratios, mean + p50 + stalls together.

## Step 1 — (only once Step 0 has a trustworthy number) the leading hypothesis: object birth/death

If the corrected gap is small or inverted, SKIP this step and write the
verdict — the arc's remaining question becomes "what is RWK's own frame
budget for 30 fps", not "why do we lose to Ruffle". If a substantial gap
survives, test this:

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
