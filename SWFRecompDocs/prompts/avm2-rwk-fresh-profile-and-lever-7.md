# Session prompt — fresh HEAD profile, then ONE lever (RWK needs 1.3x)

Read `tools/divergence/perf/RWK_AB_STATUS.md` first, and the corrected
scoreboard memory [[rwk-ruffle-gap-is-1_3x-not-11x]]. The situation after
the 2026-07-20 diagnosis session:

| title | ours | Ruffle | verdict |
|---|---|---|---|
| RWK | 107.1 ms p50 | 82.5 ms | **we lose 1.30x** |
| Seedling | 30.5 ms mean | 46.2 ms | we win 1.51x |

**Beating Ruffle on RWK needs 1.30x — one lever, not an arc.** Reaching
RWK's own 30 fps target needs ~3.2x and is a separate, much larger
question (see §4). Six levers have shipped; the last two returned ~1.1x
and no-rig-measurable, so the bar for "worth building" is now higher than
it was.

## §1 Step 0 — profile HEAD before ranking anything (mandatory)

**There is no CDP profile of current HEAD on disk.** The newest is
`/mnt/c/playwright/rwk_prof_postlever_2026-07-19.json` = **post-lever-1**.
Levers 2, 3, 4, 5, 6 and the GC tier-2 work have all landed since, and
several of them specifically attacked the clusters that profile ranks.
Every "next lever" number now in circulation is extrapolation.

Concretely, the figure the last session named as the top opportunity —
**property GET at 28.4%** (`getproperty_static_ic` 8.82 + `resolved_get`
6.78 + `value_vtable` + …) — comes from that post-lever-1 profile, i.e.
from *before* the three levers that were built specifically to cut
property reads (find→this, own-class-static bake, store/slot spec).
Native callgrind at post-lever-3+4 put the same two headline functions at
**4.64 + 4.30 ≈ 8.9%** of a much smaller total. GET may well still lead,
but "5x the alloc opportunity" is not a measured claim at HEAD. Do not
build against it unmeasured.

So, first:
1. **Fresh real-GPU CDP self-time profile of HEAD**, in a state-proven
   PlayState. The click path is now reliable — use `/mnt/c/playwright/
   ti_perf.py` / `ti_rwk_ruffle.py` (NOT the old `rw_perf*.py`), and hold
   the diagnosis session's standard: a screenshot per phase plus an
   in-frame quantity proving the state (ours: HUD/entity evidence;
   Ruffle: `__rufflePerfDraws` p50 1 → 65). Symbolicated build
   (`EMCC_CFLAGS=--profiling-funcs`).
2. **Fresh native callgrind at HEAD** (600t, default GC — cheap and
   deterministic) so both denominators exist side by side. Remember they
   disagree by construction: native runs the scalar blit fallback and
   inflates `blend_over`, while wasm runs the SIMD spans.
3. Publish the ranked cluster table in `RWK_AB_STATUS.md`. **This table is
   the session's first deliverable even if nothing else lands.**

## §2 Then pick ONE lever

Rank by (fresh share × plausible fraction removable × confidence it
converts to wall-clock). The last three sessions all found that Ir does
NOT convert linearly (lever 5: −13.1% Ir → ~1.1x wall; lever 6: −5.2% Ir →
no rig-measurable change) — the removed instructions were cheap and
well-predicted while the remaining work is memory-bound. **Apply a
discount to any pure-instruction-count lever, and prefer levers that
remove memory traffic, indirection, or calls over ones that remove
arithmetic.**

Candidates, all to be re-sized against the fresh profile rather than
assumed:
- **Property GET residue** — the IC-hit path itself
  (`getproperty_static_ic` + `resolved_get`). The remaining slice after
  three levers is receiver kinds the slot specialization can't reach
  (native `flash.geom`, non-`this` typed instances, dynamic). Seedling's
  arc ruled the non-`this` instance lever out at 0.4% hot coverage
  ([[seedling-instance-slot-lever-gated-out]]) — but that verdict was
  FlashPunk-shaped and lever 2 already proved one such verdict didn't
  transfer to Flixel. Census before believing either way.
- **Coerce residue** (~10.9% at post-lever-3+4; lever 5 removed the
  branch/compare half — what's left is store-path and call-path coercion).
- **`setup_locals` 3.58%** — lever 6 cut its fill loop to a memset; the
  remainder is per-call setup that may be hoistable per method.
- **Blit** — `blend_over` reads #1 natively but that is the scalar
  fallback; judge only on the wasm profile, where the SIMD spans run.
- **GC residual** — trace ~15 ms/collect is now the whole GC cost;
  generational is a real project ([[avm2-gc-tier2-collector-cost]]) and
  the alloc/birth-death arc was already ruled out at <1.10x ceiling
  ([[avm2-alloc-arc-ruled-out]]). Not this session.

**Build at most one.** If the fresh profile shows no single lever with a
credible ≥1.15x, say so and deliver a ranked plan of small ones instead —
that is a complete session outcome, and cheaper than discovering it after
building.

## §3 Verification + pipeline (unchanged, binding)

- Native first for attribution; **GC=0 runs are invalid for wall-clock
  A/B** (arms OOM at different tick counts —
  [[avm2-native-ab-recipe-gc0-invalid]]); wall-clock uses default GC at
  equal tick counts.
- Rig A/B: `ti_perf.py`, ≥5 interleaved rounds, **same-session ratios
  only** — rig absolutes do NOT transfer across sessions (our Seedling
  measured 16.5 one day, 30.5 another, with the *older* build at 37.4).
  Report mean + p50 + stall count together (the lazy-sweep p50 trap).
- Correctness bar per lever: the relevant verify define(s) from the
  FIND/SLOT/SET/ARITH/SLOTTPL family clean over ≥1200 ticks; traces +
  600 CPU-dump frames byte-identical vs HEAD across normal/stress/GC=0;
  a regression test in `regression/` for any new semantics; both CI modes
  zero pass→fail (avm2 823/1215, regression 57 at 100%).
- **Verify-defines CI runs now publish NOTHING** ([[ci-verify-run-results-clobber]])
  — read the conclusion, never wait for or merge their results.
- Finish per `.claude/pipeline-handoff.md`; FRESH demo redeploys on any
  recompiler/runtime change + Archipelago flashPanel restage; update
  RWK_AB_STATUS (ratios, not absolute waypoints — the arc is quoted as
  ≈2.9x compute / ≈3.7x with GC, a product of same-session ratios).

## §4 The strategic question to answer in writing (cheap, no code)

**The objective is PLAYABILITY via a recompilation pipeline that "just
works" — no per-game settings** (user, 2026-07-20). Beating Ruffle is a
proxy, not the goal: Ruffle only manages ~11 fps on RWK here, so matching
or beating it leaves the game unplayable either way. Judge levers against
30 fps (33 ms), which from 107 ms needs **~3.2x**.

Nobody has profiled Ruffle's 82.5 ms frame to ask whether 33 ms is
reachable for this title in wasm at all. Using the fresh profile plus one
Ruffle profile (its perf shim exists — [[ruffle-wasm-perf-shim-and-build]]),
state a view on:
1. Is RWK at 30 fps plausible, or is Flixel-on-wasm structurally a ~10 fps
   title here? Flixel 2.21 rebuilds its collision quadtree from scratch
   every `FlxU.overlap` with **zero pooling** (verified in the decompiled
   source at `~/CC/jpexs/output/robotkitty/scripts/org/flixel/`: bare
   `new FlxQuadTree(...)` / `new FlxList()` in add/divide, no
   `_cachedTreesHead`, no `recycle` — later Flixel versions added exactly
   that pool). Ruffle pays the same churn, which is *why* it also sits at
   ~11 fps.
2. **How much of the 107 ms is the GAME being wasteful vs OUR runtime
   being slow?** This is now the decisive question, because if the answer
   is "mostly the game", the pipeline lever (library-aware handling of
   Flixel — see §5) beats any further runtime micro-lever.
3. Which title should carry the 30 fps ambition if RWK cannot (Seedling
   is already at 30.5 ms)?

## §5 Flag for the session AFTER this one (do not build here)

Direction under active consideration: **library-aware recompilation**.
Flixel is MIT and used by a large fraction of the Flash game corpus, so
recognizing `org.flixel.*` and handling it better is a GENERIC pipeline
capability, not a per-game hack — which is what makes it compatible with
the "no per-game settings" objective. Two escalating forms:
(a) recompile-time substitution of an optimized AS3/ABC implementation
(pooled quadtree — algorithmic, engine-neutral, validated by the existing
trace-identity harness); (b) native intrinsic classes bound at class-define
time (the `flash.*` mechanism, applied to library classes), which is the
only form that changes our standing versus Ruffle rather than helping both
engines equally. **Non-negotiable safety property: fingerprint the class
and FALL BACK to the game's own code on any mismatch** — Flixel versions
differ across titles (RWK 2.21, sequels 2.35) and a silent substitution
with different semantics is far worse than a slow game.

Its first step is also this session's best instrument: build the pooled
variant purely to MEASURE, and §4.2 answers itself. Prefer that over
speculating.

A clear §4 answer is worth more than a marginal lever, and it decides
whether there is a lever 8 at all.

## Budget note (delegation)

Fable-led. Opus subagents: the profiling runs (ours + Ruffle), callgrind,
rig A/B rounds, CI watching. Fable: reading the fresh profile, the lever
decision and its census, the wall-clock-conversion discount, and the §4
verdict.
