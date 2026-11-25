# s28 w3-mouse-pick-avm1-root: report (wave 2, implementation)

**New files:** this report and `w3-mouse-pick-avm1-root.patch`. No new source files, fixtures or canary members.

## Verdict: GO, 1 trace flip (fail→pass), 1 diff-line recovery

- **`avm2/mouse_pick_avm1_root`: output_mismatch → pass** (graphics and no-graphics). This undoes the interim #3 regression.
- `avm2/avm1_root` (`known_failure`, failing in the s28 baseline): matching lines go back from 5 to 12 of 58, the interim #2
  figure (CI `947443a23`: 12/58; `4163c12aa`: 5/58). The row still fails, so this is not a flip.
- Nothing else moved: the 36-row gate is identical apart from these two, the 7-test / 14-comparison render canary is
  md5-identical, and the w2-loaded-shell-land Flash fixtures still pass.

## Bisect

All runs were on this box in graphics mode (`verify_output.py --tests-dir=…/avm2 --test=mouse_pick_avm1_root --mode=graphics`).

| leg | result |
|---|---|
| origin/master `54eacd67` | fail: line 1 is `Clicked on: [object Stage] (null)` (reproduces CI) |
| master with `e7afd5ad2` + `5d186720f` reverse-applied | **pass** |
| master with only the C′ line of `e7afd5ad2` reverted (`builtin_mcl_loadClip`'s `defer_to_next_tick`) | **pass** |
| master with this patch | **pass** |

The cause is **`e7afd5ad2` hunk C′** ("frame-script loadClip delivers next tick"). It changed
`defer_to_next_tick` in `builtin_mcl_loadClip` from `is_playing && current_frame+1 < g_frame_count` to "always,
outside `processTimers`". The other suspects (`0f2caed84`, `613c0f100`, `bc585e9f2`, …) were not needed to explain it.

## Mechanism

- `avm1.swf` (the AVM1 movie under the AVM2 Loader) calls `mcl.loadClip("avm1_child.swf", clip)` in its frame 1. Under
  C′ this always goes into `g_pending_mcl_loads_next_tick`.
- Only `actionPromotePendingMCLLoads` moves that bucket into `_this_tick`. It is called from the AVM1-root tick loops
  (`swf_core.c`, `swf.c`) and from `tag.c`'s root-stopped mid-tick promote.
- An AVM2-root movie runs none of those. Its AVM1 half is `actionTickAvm1ChildrenUnderAvm2` (`action.c`, called from
  `avm2_display.c` `avm1_child_tick`), which drains only `_this_tick`.
- So the load sat in the next-tick bucket and never fired. `clip.getBytesTotal()` never passed 4, the setInterval poll
  never armed `clip.onRelease`, and the click at (1,1) fell through to the Stage.
- The old rule happened to work because `is_playing && current_frame+1 < g_frame_count` was false for this one-frame
  child, so the load went to `_this_tick`. A multi-frame AVM1 child under AVM2 calling loadClip from a frame script
  would have been stranded before C′ as well. C′ just made every such load hit the gap.

## Fix (`SWFModernRuntime/src/actionmodern/action.c` only)

- `actionPromotePendingMCLLoads`: the bucket move is split out into a new `static mclPromoteNextTickBucket()`. The
  function still does the same thing for every existing caller: it resets `g_level_advance_ran_this_tick`, calls
  `actionStampCarriedDirectLoads()`, then moves the bucket.
- New `actionPromotePendingMCLLoadsUnderAvm2(void)` does only the bucket move.
- `actionTickAvm1ChildrenUnderAvm2` calls it **at the top of the tick**, before the children's frames run. A loadClip
  issued during tick N's child frames therefore fires in tick N+1's MCL drain, which keeps C′'s next-tick semantics
  under AVM2 too.
- The direct-load epoch stamp and the advance-ran flag are deliberately left out of the AVM2 path:
  - that path has no epoch pass and uses `fire_all`;
  - its `actionAdvancePlayingLevels` always runs before the MCL drain, so the flag already reads 1 there.
- AVM1-root movies never set `g_avm1_under_avm2_ready`, so the new call returns early for them and their behaviour
  cannot change. C′'s Flash-proven behaviour for AVM1 roots is untouched.

Functions touched: `actionTickAvm1ChildrenUnderAvm2`, `actionPromotePendingMCLLoads`, plus the new
`actionPromotePendingMCLLoadsUnderAvm2` and `mclPromoteNextTickBucket`. None of them is in the sibling file map.
`swf_core.c`, `tag_stubs.c` and the `NO_GRAPHICS` arms are not touched, but I ran no-graphics on the headline rows anyway.

## Per-test before/after (same box; before = clean origin/master `54eacd67`, after = this patch)

Graphics mode. The value after each status is matching lines over expected lines.

| test | before | after |
|---|---|---|
| **avm2/mouse_pick_avm1_root** | output_mismatch 1/2 | **pass 2/2** |
| avm2/avm1_root (known_failure) | output_mismatch 5/58 | output_mismatch 12/58 |
| avm2/avm1movie_addcallback_call | pass | pass |
| avm2/localconnection | pass | pass |
| avm2/mouse_pick_button_mode, _dobj_mask, _loader_avm1, _masking, _non_interactive_bitmap_mask, _non_interactive_dobj_mask, _scroll_rect, _scroll_rect_button, _scroll_rect_loader, _text | pass ×10 | pass ×10 |
| mixed_avm/avm1_doabc, avm1_loads_avm2_doaction, avm1_sprite_sc_ignored, avm2_doaction, avm2_loads_avm1, avm2_loads_avm1_doabc, avm2_loads_avm1_loads_avm2_doabc, avm2_loads_avm1_loads_into_root, avm2_loads_avm1_v10, avm2_loads_avm1_v9 | pass ×10 | pass ×10 |
| mixed_avm/avm1_loads_avm2 (baseline-failing) | output_mismatch 3/7 | output_mismatch 3/7 |
| mixed_avm/avm2_loads_avm1_events | ruffle_matched 8/26 | ruffle_matched 8/26 |
| regression/avm1_loaded_bare_goto, _bare_goto_seq, _goto_play_deferred, _order_create_vs_load, _shell_consumers_seq, _shell_root_lookup, _timeline_holder, _unload_deferred | pass ×8 | pass ×8 |
| regression/avm1_mcl_holder_totalframes, avm1_mcl_load_tick (C′'s Flash fixtures) | pass ×2 | pass ×2 |
| avm1/load_cancel_via_unloadmovie, loadmovie_method, mcl_getprogress (after only) | — | pass ×3 |

No-graphics, both legs:

| test | before | after |
|---|---|---|
| mouse_pick_avm1_root | output_mismatch 1/2 | pass 2/2 |
| avm1_root | output_mismatch 5/58 | output_mismatch 12/58 |

So the two modes agree.

- **Regression suite:** all 10 `regression/avm1_loaded_*` / `*mcl*` rows pass in both legs.
- **Render canary:** run on a targeted subset, not the full 844-line list. The list's own note (line ~436) says no
  `mixed_avm` row carries `[image_comparisons]`, and the changed path only runs once an AVM1 child has booted under
  AVM2. The subset was `avm2/mouse_pick_dobj_mask`, `avm1/focusrect_mouse_swf8`, `avm2/loader_events`,
  `regression/avm1_parent_child_render`, `avm1/mcl_target_png`, `avm1/movieclip_methods_with_loaded_image` and
  `avm2/loader_jpegxr_alpha`. Result: 14/14 comparisons IDENTICAL, no trace or image status changes. I added no canary
  member, because no image-bearing AVM1-under-AVM2 row exists to add.
- **Upstream:** `download_tests.sh avm2 mixed_avm avm1` was run on 2026-11-25 against upstream Ruffle master (the brief
  names `c2f7d24b7`). Flash fixes were applied.

## EXPECTED-FLIP LEDGER (for CI grading against interim #3 `4163c12aa`)

**Trace axis:**

| test | expected move vs `4163c12aa` |
|---|---|
| avm2/mouse_pick_avm1_root | output_mismatch → **pass** (both modes) |
| avm2/avm1_root | stays output_mismatch; matching lines 5 → 12 of 58 (back to `947443a23`) |
| everything else | no change |

**Pixel axis:** none. The canary subset is md5-identical, and no AVM1-under-AVM2 row has an image comparison.

## Refutations / notes

- The brief listed 7 candidate commits. Only C′ in `e7afd5ad2` matters; reverting `5d186720f` was not needed (the C′
  line alone restores the pass).
- C′ is not wrong. Its Flash evidence (`avm1_mcl_load_tick`, `avm1_mcl_holder_totalframes`) is for AVM1 roots, and it
  stays in force there. The bug is a missing promote hook on the AVM2 path, which already existed before C′ for
  multi-frame AVM1 children.
- **Open question for a Flash check:** how long Flash takes to deliver an AVM1-under-AVM2 loadClip has not been
  measured. The Ruffle golden passes with next-tick delivery and the interim #2 code passed with same-tick delivery,
  so this row cannot tell the two apart. Done-mechanism: the FLASH request below.

## New unclaimed leads

- `avm2/avm1_root` (known_failure) still has 46 lines to go, with `RangeError #2006` as its error signature. It was not
  touched here.

## LOCAL ORACLE REQUESTS

- FLASH (optional, low priority): `avm2/mouse_pick_avm1_root`, trace, with a `trace(getTimer()/tick)` added in
  `checkLoadComplete`. The goal is to see which AVM2 frame an AVM1 child's frame-1 `loadClip` reaches onLoadComplete
  in under an AVM2 Loader, and confirm next-tick delivery. This only matters if a future row turns on that timing.
