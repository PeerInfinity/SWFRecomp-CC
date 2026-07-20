# Session prompt — playability scoreboard + the quadtree gate (game vs runtime)

**Objective (user, 2026-07-20):** make the games playable in the browser
via a recompilation process that needs **no per-game settings** — it just
works. Beating Ruffle is a proxy, not the target (Ruffle manages ~11 fps
on RWK, so parity leaves it unplayable). The bar is **30 fps = 33 ms**.

Read `tools/divergence/perf/RWK_AB_STATUS.md` and the memories
[[rwk-ruffle-gap-is-1_3x-not-11x]] (both old anchors were wrong; rig
absolutes do NOT transfer between sessions — only same-session ratios do)
and [[swfrecomp-purpose-beat-ruffle-perf]] (objective + local-only hosting).

This session is **measurement and a gate decision**. It supersedes the
lever-picking half of `avm2-rwk-fresh-profile-and-lever-7.md`: that
prompt's §1 (fresh profile) is absorbed here, and its §2 (build one
lever) is DEFERRED until this session says whether a runtime lever is
even the right target. Do not build a perf lever here.

## §1 — The playability scoreboard nobody has (do this first, it may reframe everything)

Every rig number on record is stale, session-relative, or both. Under the
real objective the first question is simply: **which titles are already
playable, and which are not?**

Same day, same rig, state-proven (screenshot + in-frame quantity per
phase; drivers `/mnt/c/playwright/ti_perf.py` + `ti_rwk_ruffle.py` — NOT
the old `rw_perf*.py`), ≥5 interleaved rounds, report mean + p50 + frames
over 33 ms + stall count:

| title | ours | Ruffle | playable at 30 fps? |
|---|---|---|---|
| Seedling | (was 30.5 ms) | (was 46.2) | borderline — recheck |
| RWK | (was 107.1) | (was 82.5) | no |
| RWP | ? | ? | ? |
| RWF | ? | ? | ? |
| RWIC | ? | ? | ? |

RWF and RWIC measured 42-51 ms and 23-27 ms respectively back at the GC
tier-1 session and have received six levers since — **they may already be
at or past 30 fps**, which would mean the pipeline already "just works"
for part of the corpus and the remaining problem is narrower than it
looks. Ruffle's column is needed only where it is cheap; ours is the one
that matters for the objective.

## §2 — Fresh HEAD profile (there is none)

The newest CDP profile on disk is `rwk_prof_postlever_2026-07-19.json` =
**post-lever-1**; levers 2-6 and GC tier-2 have landed since, several
aimed squarely at the clusters it ranks. Every current "next lever"
number — including the widely-quoted **property GET 28.4%** — is
extrapolation from it. (Native callgrind at post-lever-3+4 already put
that cluster's two headline functions at 4.64 + 4.30 ≈ 8.9%.)

Take both: **real-GPU CDP self-time at HEAD** (symbolicated,
`--profiling-funcs`, state-proven PlayState) and a **native callgrind at
HEAD** (600t, default GC). They disagree by construction — native runs
the scalar blit fallback and inflates `blend_over` — so keep both
denominators. Publish the ranked table in RWK_AB_STATUS.

## §3 — THE GATE: how big is the quadtree subsystem, really?

RWK's Flixel 2.21 rebuilds its collision quadtree from scratch on every
`FlxU.overlap`, with **zero pooling** — verified in the decompiled source
(`~/CC/jpexs/output/robotkitty/scripts/org/flixel/`): bare
`new FlxQuadTree(...)` / `new FlxList()` throughout `add`/`divide`, no
`_cachedTreesHead`, no `recycle` (later Flixel versions added exactly that
pool). Neither class is subclassed by the game. ~9.2k constructions/tick.

**Before building any pooled variant, compute its ceiling from the fresh
profile.** Sum everything attributable to the subsystem: the FlxQuadTree /
FlxList constructor bodies, their methods, the hot quadtree cluster
(m484/486/482/487 and whatever HEAD's profile names), plus the share of
allocation and GC they drive. Then:

- If the subsystem went to **zero**, what would the frame be? Compare to
  33 ms and to the ~3.2x needed.
- Pooling removes allocation + constructor execution but **NOT** the
  tree's insert/traverse logic — so the realistic prize is a fraction of
  that ceiling. State both numbers.
- Note that Ruffle pays the same churn (it interprets those constructors,
  we run them compiled), so this direction likely improves absolute
  playability for both engines without moving our ratio versus Ruffle.
  Under this objective that is acceptable — but say it plainly.

**GATE: if the whole subsystem going free cannot bring RWK within reach of
33 ms, the pooled-Flixel direction is answered — report that and stop.**
That verdict, reached for the cost of arithmetic on a profile, is a
complete and valuable session outcome. The arc has now had two levers
whose prize was known too late (lever 6 shipped for no measurable change);
do not repeat it at the scale of a whole library fork.

## §4 — Only if the gate passes: build the instrument

Build the pooled variant purely to **measure**, and note that the
instrument IS the prototype of the product direction (form (a) below):

1. Source: `org/flixel/**` decompiles cleanly in these games (unlike the
   game classes, which are `§`-mangled and control-flow obfuscated) —
   compile the whole `org.flixel` package standalone and splice its ABC
   over the game's, rather than recompiling the game.
2. Add pooling to `FlxQuadTree` + `FlxList` mirroring later Flixel's own
   `recycle()` / cached-list design (upstream is MIT — reference it rather
   than inventing a scheme).
3. **Validate it is still the same game before trusting any number:** run
   the plan_k TAS (`ruffle-tests/_rwk_tas/`) and require identical
   behaviour (trace + CPU-dump frames) against the unmodified build. A
   pooled build that diverges is measuring a different game.
4. Measure ours AND Ruffle on it, same session, same method as §1.

## §5 — Deliverable: a written direction call

1. The scoreboard: which titles already meet 30 fps, which do not.
2. The split: how much of RWK's frame is the game being wasteful vs our
   runtime being slow.
3. Therefore, which of these is the pipeline's next investment:
   - **(a) recompile-time library substitution** — fingerprint
     `org.flixel.*` and splice an optimized implementation. Generic across
     the Flixel corpus (thousands of titles), so compatible with "no
     per-game settings". Engine-neutral, validatable by the existing
     trace-identity harness.
   - **(b) native intrinsic classes** — bind library classes to native
     implementations at class-define time (the `flash.*` mechanism). The
     only form that moves our standing versus Ruffle, but it carries real
     semantic risk (node identity, iteration order, reflection,
     subclassing) and should be gated on (a) proving insufficient.
   - **(c) more runtime levers** — the deferred lever-7 work, if §3 says
     the runtime, not the game, is what holds RWK back.
   **Non-negotiable for (a) and (b): fingerprint the class and FALL BACK
   to the game's own code on any mismatch.** Flixel versions differ across
   these titles already (RWK 2.21, sequels 2.35); a silent substitution
   with different semantics is far worse than a slow game and would poison
   the "just works" premise.

## Method rules (binding)

- Rig: real-GPU Windows Chrome only; `ti_perf.py`; ≥5 interleaved rounds;
  **same-session ratios only** (our Seedling measured 16.5 one day and
  30.5 another, our *older* build 37.4 — absolutes do not transfer).
- Prove every phase's state (screenshot + in-frame quantity). A phase
  labelled "gameplay" without evidence is what cost this arc four
  sessions.
- Native: **GC=0 is invalid for wall-clock** (arms OOM at different tick
  counts — [[avm2-native-ab-recipe-gc0-invalid]]); default GC, equal ticks.
- **Ir is not time** (lever 5: −13.1% Ir → ~1.1x wall; lever 6: −5.2% Ir →
  nothing measurable). Discount instruction-count-only arguments.
- Verify-defines CI runs publish NOTHING ([[ci-verify-run-results-clobber]]).
- If any code ships (it should not, beyond the instrument): pipeline per
  `.claude/pipeline-handoff.md`, FRESH demo redeploys, both CI modes.
  A measurement-only session needs no CI dispatch (`ci-only-when-observable`).

## Budget note (delegation)

Fable-led. Opus subagents: the five-title rig scoreboard, the profiling
runs, the ABC splice mechanics if §4 is reached. Fable: the gate
arithmetic, the game-vs-runtime split, and the §5 direction call.
