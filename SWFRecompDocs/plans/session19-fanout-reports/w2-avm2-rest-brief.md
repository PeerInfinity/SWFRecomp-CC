# w2-avm2-rest: EdgeBounds in the recompiler, ID3Info, EditText scroll event (G5, G7, G6)

Read `BRIEFS_COMMON.md` (wave-2 section included), then `w1-avm2-report.md` items G5, G7, G6.
Worktree agent: nothing commits, you deliver patches — **one file per item**, since they are
unrelated and G5 is a recompiler change. Branch from current master (say which commit).

## Scope (+3 effective, in descending confidence)
**G5 `avm2/displayobject_getrect` (+1, M-small, recompiler).** We throw away DefineShape4's
`EdgeBounds` AND DefineMorphShape2's `StartEdgeBounds`. **The morph half is required for the flip** —
3 of 5 lines depend on it, so a DefineShape4-only fix scores nothing. Recompiler change: rebuild in
your worktree and pass `--recompile` on first use of every copied test dir.

**G7 `avm2/id3_info` (+1, M, ~150 LOC).** There is no ID3Info class at all. The bytes are already
in memory; dispatch between `progress` and `complete`.

**G6 `avm2/edittext_scroll_event` (+1, S, weakest pricing on the board — the diagnosis says so
itself).** No `scroll` event is ever dispatched. Whether it flips depends on our embedded-font
`maxscroll` matching. Do G6 LAST, and if the flip does not materialize, deliver the dispatch plus a
HOLD naming what `maxscroll` would have to do — do not chase font metrics in this slice.

## Required checks
- Headlines both ways for each item.
- G5 changes shape parsing for every SWF: after rebuilding, spot-check a handful of tests across
  `avm1` and `avm2` for unchanged recompilation, and run the bounds families
  (`avm2/displayobject_getbounds*`, `bounds_mode`, `avm2/*rect*`). **Note a sibling landed an AVM2
  curve-bounds change on master (`displayobject_getbounds_shape`, margin only 84 channels) — run
  that test with `--mode=graphics --images` and confirm you have not eaten its margin.**
- G7: the sound/ID3 families (`avm2/sound*`, `avm2/id3*`).
- G6: the EditText families (`avm2/edittext*`, `avm2/textline*`). **A sibling (w2-gfx-text) is
  editing `avm2_text.c` at-point probes and may land first** — if your G6 touches that file, check
  master before you start and say so in your final message.
- The `regression` suite for all three, and the render canary if you touch anything the renderer
  reads (G5 does).
