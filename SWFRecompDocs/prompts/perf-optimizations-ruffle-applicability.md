# Session prompt — which of our performance optimizations apply to Ruffle?

**Objective (user, 2026-07-22):** take the shipped-optimization catalog,
`SWFRecompDocs/reference/performance-optimizations.md` (~30 entries across §1-§5),
and classify every entry by its relationship to Ruffle: **already there /
portable / structurally impossible / AOT-only**. Produce one living reference
document. This is an **analysis session** — no runtime or recompiler changes, and
no changes to the Ruffle checkout.

**Why this is worth a session.** We claim to beat Ruffle on perf
([[swfrecomp-purpose-beat-ruffle-perf]]), and the claim is now backed by real
numbers on five titles plus Elephant Quest. But "we're faster" is not an
architectural argument until you can say *which* wins are ours by construction
and which are just work Ruffle hasn't done yet. That distinction is the honest
version of the project's thesis, and it also produces a to-do list: the
**portable** column is a list of contributions Ruffle would accept, and the
**AOT-only** column is the actual moat.

## The four categories (the fourth is load-bearing — keep it separate)

| | Category | Definition | What it means for us |
|---|---|---|---|
| **A** | **Already in Ruffle** | Ruffle does this, in the same or a different form. Note if Ruffle's version is *better* — that is a finding, not an embarrassment | Nothing to claim; possibly something to learn |
| **B** | **Portable** | Ruffle does not do this, but could, without changing its architecture. Adaptation cost may be nonzero — say what it is | A genuine upstream contribution list |
| **C** | **Structurally impossible in Ruffle** | Ruffle would *want* this and cannot have it, blocked by an architectural commitment: gc-arena's borrow discipline, `Gc`/`GcWeak` layout, safe-Rust aliasing rules, the wasm/JS boundary, its interpreter loop's shape | An incidental edge — real, but a consequence of *their* choices, not of AOT |
| **D** | **Not applicable — AOT-only** | The optimization exists only because we compile ahead of time. There is no interpreter-shaped version of it; the nearest Ruffle analogue would be writing a JIT, i.e. a different project | **The actual moat.** This column is the architectural argument |

**Why C and D must not be merged.** C is "Ruffle painted itself into a corner";
D is "an interpreter cannot do this at all". Collapsing them would let the
catalog overstate our structural advantage — most of §1's recompiler levers are
D, and if those got scored as "Ruffle can't do it" without the AOT qualifier,
the conclusion would read as a much broader claim than the evidence supports.
Expect the interesting tension to be in **B vs C**: it is tempting to file
something as impossible when it is merely inconvenient in Rust.

If an entry splits (e.g. a [RC+RT] lever whose runtime half is portable and
whose emit half is AOT-only), **split the row** rather than picking the
dominant half.

## Binding evidence rule

**Every verdict cites a Ruffle `file.rs:symbol` you actually read.** No verdicts
from memory of how Ruffle works, and none from "it's an interpreter, so
presumably…". A verdict of "already there" needs the code that does it; a
verdict of "not there" needs the code that would contain it if it existed.

This rule exists because of a specific near-miss: the goto walk gate looked like
a *divergence* from Ruffle until the code was read, at which point it turned out
Ruffle does exactly the same full walk — the difference was constant factor, not
algorithm. Assuming the reference implementation is smarter than it is would have
produced the wrong verdict, and the wrong fix.

Cite **symbols, not just line numbers** — lines shift.

## Worked example (verified 2026-07-22 against `be11d7e89`; reuse the format)

> ### goto catch-up walk gate (§3) — **B, portable**
>
> **What we do.** Skip the construct / frame-script catch-up on display subtrees
> with no pending work (`walk_clean` per node, `dirty_kids` per container, a
> dirty-orphan candidate list). `SWFModernRuntime/src/avm2/avm2_display.c`,
> § "Catch-up walk gate", commit `6fefd4552`.
>
> **What Ruffle does.** The same full walk, ungated.
> `core/src/frame_lifecycle.rs::run_inner_goto_frame` (:124) runs
> `stage.construct_frame` then `stage.run_frame_scripts` over the whole tree plus
> every orphan, on **every** explicit goto — including a no-op goto to the
> current frame (`movie_clip.rs::goto_frame` :881 → `goto_frame_now` :923 →
> `no_op_goto` :940). Both walks are unconditional recursions with no quiescence
> check: `movie_clip.rs::run_frame_scripts` (:2648) is
> `run_local_frame_scripts` + `for child in self.iter_render_list()`, and the
> `DisplayObject` default (`display_object.rs`:2403) is the same. Orphans:
> `orphan_manager.rs::each_orphan_obj` (:45) iterates the entire vec.
>
> **Verdict: portable, and easier there than here.** The mechanism is a flag on
> `DisplayObjectBase` plus a mark up the parent chain — no architectural
> conflict. Ruffle has two advantages we lacked: `Cell`-based interior mutability
> makes the flag cheap, and it has a single `set_parent` choke point where we had
> to hook ten separate parent-assignment sites. Two porting hazards: (1) every
> playhead advance that bypasses `run_goto` needs its own mark — the equivalent
> of our `run_frame_internal`'s `current_frame++`, which broke the boot until
> marked; (2) the dirty-orphan list holds `DisplayObjectWeak`, so entries need an
> upgrade check on use.
>
> **Note.** gc-arena lets Ruffle's orphan list shrink when entries become
> unreachable, which we cannot do mid-tick. That did not save it on Elephant
> Quest — the tiles are held live by the game's own `this.tiles` array — but it
> is a real advantage on other workloads, and belongs in the writeup.

## Suggested order of work

1. **§3 is done** — copy the example above.
2. **§2 (GC) next.** Highest chance of category-A hits and of
   "Ruffle does it better": gc-arena is a mature incremental collector and our
   tier-1/tier-2 work may be re-deriving it. Read `core/src/` GC usage and the
   `gc-arena` crate. Being honest here buys credibility for the rest.
3. **§1, split carefully.** [RT] rows (vtable name hash, domain hash,
   coerce-class memo, the ICs) are the B-vs-A question — check what caching
   Ruffle's `avm2/` property path already has before concluding anything. [RC]
   rows (slot specialization, find→this, own-static bake, typed emission,
   coercion elision) are the D candidates. The **Flixel/arrayToCSV intrinsics**
   are their own question: a fingerprint-gated native replacement is not
   obviously AOT-only — an interpreter *could* pattern-match a known class — so
   reason about it rather than assuming.
4. **§4 (AVM1) and §5 (renderer).** The renderer rows may be the most directly
   portable of all (`writeBuffer` batching, sub-region upload) — check
   `render/wgpu/` for what Ruffle already batches.
5. **§6 (rejected) as a bonus pass, if time.** "We tried X and rejected it —
   does Ruffle do X?" If Ruffle ships something we measured as not worth it,
   that is worth knowing in both directions.

## Deliverable

`SWFRecompDocs/reference/performance-optimizations-vs-ruffle.md` — a living
reference beside the catalog it annotates. **Not** `upstream-comparison/`: that
directory is about the upstream *SWFRecomp org* fork, a different "upstream".

Shape: a summary table (one row per catalog entry → category + one-line reason),
then per-category sections with the detailed writeups. Open with the count per
category and the one-paragraph conclusion those counts support — and let the
counts write the conclusion, not the other way round.

Cross-link it from `performance-optimizations.md`'s header. Add a memory topic
file if the conclusion is durable.

## Guardrails

- **The Ruffle checkout is READ-ONLY this session.** `~/CC/ruffle` sits at
  `be11d7e89` carrying our uncommitted oracle/perf patches (12 modified files +
  2 new). Do not build, checkout, stash, or clean it. If you somehow need to
  modify it, stop and say so. Recovery if it is ever damaged:
  `SWFRecompDocs/reference/ruffle-local-patches.{md,patch}`.
- **No SWFRecomp code changes.** If the analysis turns up an optimization we
  should adopt *from* Ruffle, write it down as a finding — do not implement it.
- **Uncertainty is a legitimate verdict.** "Could not determine without a
  measurement" beats a confident guess. Mark those explicitly and say what
  measurement would settle it.
- No CI needed (docs only), but commit and push per the usual trailer.

## Context worth loading

- `SWFRecompDocs/reference/performance-optimizations.md` — the catalog (the input)
- `tools/divergence/perf/RWK_AB_STATUS.md`, `SEEDLING_AB_STATUS.md` — per-lever
  A/B evidence, for when a catalog row is too terse to classify
- Memory: [[avm2-goto-catchup-walk-gate]], [[swfrecomp-purpose-beat-ruffle-perf]],
  [[rwk-ruffle-gap-is-1_3x-not-11x]] (the retracted 11x — the cautionary tale
  about comparing phases), [[avm2-flixel-native-intrinsic]],
  [[avm2-gc-tier2-collector-cost]]
