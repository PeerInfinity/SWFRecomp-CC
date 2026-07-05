# Session prompt: fix attachMovie sprite_display_list realloc aliasing + growth cost

Fix the pre-existing bug #1 documented in
`SWFRecompDocs/plans/memory-reclamation-results-2026-07-04.md` (§pre-existing
bugs — read it first; repros are preserved there): **growing a sprite's
`sprite_display_list` on attachMovie invalidates aliased `DisplayObject*`
pointers**, and **each grow HCALLOCs ~14 MB**, which is one root cause behind
(a) an ASAN use-after-free in the register-constructor queue and (b)
Minesweeper's native `heap_alloc(442368)` OOM in CI modes.

This is two coupled fixes in one site's growth path:

## Fix 1 — pointer stability (the correctness bug)

`MovieClip.display_obj` (and possibly other holders) alias entries inside
`sprite_display_list` arrays; a grow/realloc moves the storage and strands
them. Precedents in this codebase for the *invalidation* shape:
`clear_display_entry`'s child_mc_cache range-walk (invalidates MCs whose
`display_obj` falls inside a freed DL), and `clone_depth_register`'s
keep-arg walk. Candidate approaches — pick after inventorying every holder of
a `DisplayObject*` into these arrays (grep for `display_obj` assignments and
any cached `DisplayObject*`):

1. **Repoint on grow** (smallest change): after realloc, walk the holders
   (child_mc_cache `display_obj`, register-ctor queue entries, any others the
   inventory finds) and rebase `old_base+offset → new_base`. Cheap because
   grows are rare; but every *future* holder is a latent bug — add a comment
   at the struct field naming the rule.
2. **Stable storage**: chunked allocation (fixed-size blocks, entries never
   move) or an index-based scheme (holders store `(sprite, depth)` or a slot
   index instead of a raw pointer). Bigger churn, structurally immune.

Prefer option 1 unless the inventory finds too many holder classes to walk
reliably — this is a targeted fix session, not a display-list refactor.
Whichever option: the ASAN register-ctor-queue repro from the results doc must
go from failing to clean, on otherwise-clean HEAD.

## Fix 2 — the ~14 MB-per-grow allocation (the OOM)

Diagnose why one grow allocates ~14 MB (suspect: sizing by max-depth range —
the +16384 depth-bias span — rather than by occupancy, and/or re-allocating
the full span per grow instead of geometric growth). Note the related known
fact: the attachMovie +16384 buffer memset is CI-modes-only and was already
identified as profiling noise (`wasm-game-performance-profiling` memory) — this
session is about the *allocation size/lifetime*, not the memset. Fix the
growth policy so Minesweeper's native CI-mode run no longer OOMs
(`heap_alloc(442368)` failure repro in the results doc). Mind `ENSURE_SIZE`
semantics and the o1heap arena's power-of-2 behavior when choosing sizes.

## Verification

- The two repros from the results doc: ASAN register-ctor UAF → clean;
  Minesweeper native OOM → completes. Both verified against clean HEAD first
  to reconfirm they still reproduce before fixing.
- ASAN game soak (Minesweeper menu→game→restart especially — it churns
  attachMovie); the other two documented pre-existing bugs (DJ bounds SEGV,
  `global_proto_decls` UAF) are NOT this session's scope — don't misattribute.
- Byte-identical trace/game stdout; full CI both modes (shared runtime), zero
  pass→fail. The GC is default-on now — if anything GC-adjacent trips, test
  with `SWF_GC=0` to isolate before assuming interaction.
- Update the results doc's pre-existing-bugs section (bug #1 → fixed, commit),
  memory entry, pipeline end-to-end, `.pipeline-state` done.

## Scope guard

No display-list architecture refactor, no chasing bugs #2/#3, no GC changes.
If Fix 1's holder inventory reveals the problem is much wider than
`sprite_display_list` (e.g. the same aliasing exists for other DL arrays),
fix this site, document the class, and propose the follow-up rather than
expanding mid-session.
