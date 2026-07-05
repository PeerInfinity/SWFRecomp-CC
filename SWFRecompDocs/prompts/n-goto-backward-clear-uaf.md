# Session prompt: fix the N use-after-free — backward-jump DL clear vs live readers

Fix the pre-existing use-after-free documented (with repro) in the latest
section of `SWFRecompDocs/plans/memory-reclamation-results-2026-07-04.md`:
**`actionGetMember` reads a child display list that `ng_gotoFrameByMC`'s
backward-jump branch freed**. It reproduces on N under ASAN and predates the
recent sprite-DL work (verified identical at prior HEAD).

## Context you inherit (read first)

- This is the same aliasing class that `2f20b1c59` just built funnels for:
  **`ng_freeSpriteDL`** frees a sprite DL and NULLs all known holder classes,
  and **`ng_spriteDLRealloc`** rebases them on grow. The holder rules are
  documented at the struct field in `swf.h`.
- `ng_gotoFrameByMC`'s backward-jump branch (tag_stubs.c ~1200) has history:
  it previously leaked materialized child MCs on the same clear
  (`cc09e0306` added child_mc_cache invalidation there — see
  `n-title-drone-instanceN-leak` / timeline memory entries).
- The brand-new loop-back identity preservation (`9030c61d9`,
  `loopback-identity-preservation` memory) changed rewind semantics in
  `advance_sprite_frames` — read it so the two mechanisms stay coherent.

## The likely shape (verify, don't assume)

First question: is the backward-jump clear one of the 11 sites funneled
through `ng_freeSpriteDL`? If not, routing it through the funnel may be the
whole fix. If it already is, then `actionGetMember` reaches the freed DL
through a holder class the funnel doesn't cover — inventory how GetMember gets
there (likely a `MovieClip*` whose `display_obj`/child-list pointer was
captured before the clear, or a nested-DL base copy) and either add that
holder class to the funnel or re-resolve instead of caching in the reader.

Also consider whether the backward-jump clear should now *preserve* survivors
the way `9030c61d9` made the natural wrap do — if the same
char/depth-match rule applies, the clear may be doing semantically wrong work,
and aligning it could fix the UAF as a side effect. Check Ruffle's `run_goto`
for whether explicit backward gotos and natural loop-back share survivorship
rules. If they do, prefer that fix (it's the correctness-first version), but
scope it carefully — goto semantics are the most regression-prone area in the
runtime (see the timeline memory entries before touching anything).

## Verification

- The ASAN N repro from the results doc: reproduce at HEAD first, then clean
  after the fix. Full ASAN soak on N (title demo 2+ min), Minesweeper board
  workload, DJ, Tetris.
- Byte-identical stdout on the soak set vs HEAD-source control builds.
- Full CI both modes, zero pass→fail. If survivorship semantics change for
  explicit backward gotos, watch the goto/execution-order clusters
  specifically (`goto_rewind*`, `execution_order*`, `displaylist_depths_*`,
  the misc-ming.all action-order family) and treat ANY movement there as
  needing individual audit, not bulk acceptance.
- GC interaction: run the repro with `SWF_GC=0` once to confirm the UAF story
  is independent of the collector (it should be — it predates it).

## Scope guard

One UAF, one site family. No general goto refactor; no chasing the other two
documented pre-existing bugs (DJ bounds SEGV, `global_proto_decls` UAF).
Close out: results doc bug entry updated, memory entry, pipeline end-to-end,
`.pipeline-state` done.
