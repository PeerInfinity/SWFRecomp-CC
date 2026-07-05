# Session prompt: looping-sprite child identity churn (per-tick DL/MC leak)

Fix the pre-existing per-tick churn leak discovered (and quantified) during the
sprite-display-list realloc-aliasing session — see
`SWFRecompDocs/plans/memory-reclamation-results-2026-07-04.md` §pre-existing
bugs, bug #1 follow-up notes. It is the reason Minesweeper's 3000-tick scripted
board workload still exits early (arena exhaustion) even after the aliasing +
occupancy-sizing fixes: the *documented* `heap_alloc(442368)` OOM at tick ~422
is gone, but a distinct leak continues.

## The behavior (measured, deterministic)

CI modes (NO_GRAPHICS measured; OFFSCREEN shares the path). Repro:
`profile_game_native.sh flasharchive/Minesweeper 3000 no-graphics --build-only`,
run with the board input script (menu→Start→15 cell clicks; preserved as
`ms_input.txt` in the aliasing-session scratchpad — regenerate via
`gen_inputs.py` if lost).

1. **From tick ~95, every tick**: a looping sprite's frame-0 rewind
   (`advance_sprite_frames` loop-back, tag.c ~1318) clears its child display
   list, and the next placement re-places the same nameless buttons (chars
   72/77/81 on the menu; more in-game) as **fresh entries with fresh
   auto-instance names** (`instanceN` climbing by ~4/tick, forever). Each
   re-place:
   - allocates a fresh 64-entry sprite DL (~27,648 B → 32 KB o1heap) whose
     predecessor is freed on the next wrap — but ~most stay live at OOM
     (measured 38,792 cumulative allocs, arena full at tick 1731 pre-cache-fix),
   - mints a **fresh cached MovieClip** (~4/tick) since the name is new —
     `child_mc_cache` grows monotonically (tombstones are never reclaimed in
     CI modes; browser swf.c has a dead-slot reclaim pass).
2. **Cache overflow** (~tick 541 at the old 4096 cap; ~tick 2023 at the current
   16384): once `child_mc_cache` is full, `actionFindOrCreateMovieClip` mints
   fresh *uncacheable* MCs on every lookup ([[child-mc-cache-cap-resolution]]
   memory), so the FRadioButton per-tick re-attach (`frb_states_mc` /
   `frb_hitArea_mc` / `fLabel_mc` onto `level_*`) stops reusing its MCs and
   leaks a standalone `display_obj` + 64-entry list ×3 per tick, plus the GC
   self-disables ("[swf-gc] child_mc_cache overflowed").

## Root cause to fix

Flash/Ruffle **preserve child identity across a loop wrap for same-char
same-depth placements** (run_goto removes only objects absent from the target
frame). Our root timeline has this preservation (tag.c ~7861 "Root timeline
loop-back preservation"); the **nested-sprite loop-back path does not** — it
clears everything and re-places fresh, which (a) churns identity (new
auto-instance names → unbounded MC minting), (b) churns DL allocations, and
(c) resets button state each tick.

Candidate fix: extend the root-timeline same-char preservation to the
`advance_sprite_frames` frame-0 rewind (preserve entries whose char_id will be
re-placed at the same depth by frame 0 — or Ruffle-style: diff against the
target frame's placements instead of clearing). Mind:
- auto-instance numbering changes → expected trace output may change; run FULL
  CI both modes and audit every diff (some tests print instance names).
- the old-entry sticky button state logic (`sticky_char_id`) and
  `g_btn_state_*` snapshots interact with re-placement.
- `ng_attachMovie` re-attach and the re-clone path already have reuse
  semantics to mirror.

Also worth fixing here (same cluster):
- **CI-mode dead-slot reclaim** for `child_mc_cache` tombstones (browser
  swf.c has one; swf_core.c does not), so long sessions cannot ratchet the
  cache to the cap even with bounded live clips.
- The **uncacheable-MC leak**: when the cache is full, fresh MCs (+ their
  standalone display_obj/lists via attach) are minted per lookup and never
  freed. With reclaim + identity preservation this should become cold, but a
  free-on-invalidate for standalone attach dobjs would close it.

## Verification

- Minesweeper 3000-tick board workload runs to MAX_FRAMES with flat memory
  (SWF_MEM_REPORT) and no cache-overflow message; stdout audited (identity
  preservation may legitimately change auto-instance numbering — compare
  against Flash/Ruffle where visible).
- N title demo / DJ clicks / Tetris: byte-identical stdout unless an audited,
  explainable identity change.
- ASAN soak all games; full CI both modes, zero unexplained pass→fail.

## Scope guard

This is the *identity/lifetime* session. Do not touch the realloc-rebase
machinery (`ng_spriteDLRealloc`) beyond registering any new holders you
introduce; do not chase the DJ bounds SEGV or `global_proto_decls` UAF.
