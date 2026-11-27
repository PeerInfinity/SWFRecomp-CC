# s29 browser-attach-order: natural-advance frame-script order across timeline and attached clips

One-task local slice, browser ladder. It follows `browser-dj-freeze` (`3fd694def`); `browser-gotoandstop-current` (`c91637b7a`) first saw the defect.
Base: master `f6ca12a6c` (peer commits landed under the slice; see §5).

## 1. Verdict

- **Flash's rule is ONE exec list: every child clip's natural-advance frame script runs newest instantiation first, then `_root`.** Timeline-placed, nested and attachMovie'd clips interleave by creation order. Kind (timeline vs attached) and depth play no part. This is exactly Ruffle's `clip_exec_list` (`core/src/avm1/runtime.rs::run_frame`; `movie_clip.rs::post_instantiation` adds a clip at the head).
- **The memory line "attach-tick order is TAG order" is not a conflict.** It is about a clip's FIRST frame script, which runs from the action queue at its creation point (placement or attach) and so in queue order. Flash shows the same in the fixture's tick 1. The exec-list rule governs every later, natural-advance tick.
- **Ours, in every build:** nested sprites first, then root-level timeline sprites, then the attached pump. Each pass was sorted by `place_seq` on its own, so the scripts landed as three blocks, with timeline before attached.
- **Fixed, all builds.** The three passes now queue as one block sorted by `place_seq` desc (§3). An attached clip is also stamped before its frame-0 children, so they are newer than it, as in Flash.
- **Is this the gnash action_order NO-GO list?** It is the **script half** of it: requirement 2 of the three in `n-exec-order-report.md` §2b. It is not the whole list. Per-clip enterFrame fired immediately before that clip's own script (req. 1), and the clip-event walk merged into the same order (req. 3), are still open. So the NO-GO stands, minus its script-order part. No action_order row flips (§4).

## 2. FP32 fixture `regression/avm1_attach_timeline_frame_order`

Generator: `create_test_swf.py` (the `_lib/avm1asm` writer).
- Sprite T: 3 frames, loops, every frame traces `_name fN`.
- Sprite P: 3 frames, places a timeline T `pt`; its f1 attaches T `pa` into itself, once.
- Root f1: timeline `t10@10`, `t30@30`, P `p40@40`, then DoAction attaches `a5@5` (below), `a20@20` (between), `a50@50` (above) and P `ap60@60` (an attached holder with a timeline child plus an attached child).
- Root f2: timeline `t15@15` is placed, and `a25@25` is attached. Both are created on a later tick.

Golden: Linux FP32, direct, window-pinned. Two captures, byte-identical over their common prefix. The clips loop forever, so the golden is the first 82 lines, i.e. ticks 1–6 (`num_frames = 6`).

Steady-state order, every tick from tick 3 (Flash):

`a25, t15, ap60.pa, ap60.pt, ap60, a50, a20, a5, p40.pa, p40.pt, p40, t30, t10, root`

This is reverse creation exactly:
- `a5@5` runs before `p40@40`, so depth plays no part.
- `p40.pa` was attached by p40's f1 BEFORE the root script attached `a5`, so it runs after `a5`.
- `ap60.pt` runs before `ap60`: the attached clip is instantiated before its frame-0 children.

Before the fix, ours on tick 2 was `p40.pt, p40, t30, t10 | ap60.pa…` (timeline block first). After, it is byte-identical to Flash in both native modes.

## 3. Mechanism (shared by every build)

- `action_queue.c`: every queue entry gets an `order_key`. It is stamped from `g_aq_order_key` at queue time.
- `actionAQOrderMark` / `actionAQOrderSortSince` bracket the pre-frame-func advance block (nested-early pass, `advance_sprite_frames`, the attached pump):
  - in `swf.c`, which covers OFFSCREEN and the browser;
  - in `swf_core.c`, both the playing branch and the past-last-frame branch.
- After the block, the block's entries are stable-sorted by key desc. An entry with key 0 takes the key of the entry before it.
- The sort is skipped if anything popped from the queue inside the block, because the mark index would no longer be valid.
- `tag.c advance_sprite_frames` / `advance_nested_sprite_frames`: each iterated object sets the key to its `place_seq`. The public wrappers save the key and restore it.
  - So everything a clip's advance queues keeps that clip's slot: its frame script, and the init script of a child it places.
  - Ruffle has the same shape: `run_frame_avm1` queues these at the clip's position in the walk.
  - The pump's `ng_attached_run_tree` reaches the same loop through its 1-entry scratch list, so attached roots and their subtree children are keyed too.
- `tag_stubs.c ng_attachMovie`: `dobj->place_seq = ++g_place_seq` is set BEFORE frame 0 places the clip's children. Every attach, re-attach included, is a new instance. Before this, `ng_record_attached_playable` stamped the clip after its children.
- Kill switch: `SWF_EXEC_ORDER_MERGED=0` restores both the order and the old stamp point. A browser A/B build uses `EMCC_CFLAGS=-DSWF_EXEC_ORDER_MERGED_OFF`, because the browser has no env.

## 4. Pricing (native A/B, same tree, kill switch on and off; ACTUAL outputs diffed)

- **Candidates:** a scan of every AVM1 `test.swf` for an `attachMovie` string, or ≥2 sprites with a DoAction. That gave 155 rows across avm1, gnash, shumway, regression, import_assets and visual (`_swfbridge` games excluded). I added the 19 gnash `action_order`/`loop` rows the scan missed, including `ActionOrderTest3/4/5`.
- **No-graphics:** 174 rows. **Only 2 outputs change:**

| row | before → after | note |
|---|---|---|
| `regression/avm1_attach_timeline_frame_order` | FAIL → PASS | new fixture |
| gnash `misc-ming.all/action_order/action_execution_order_test11` | FAIL → FAIL | Flash-ward: the `doActionOrder` check now PASSES (`0+1+2+3+4+5+`). Diff 10→8 lines. 1 check left: its tail is enterFrame/ctor interleave, i.e. the req. 1/3 NO-GO half |

- Every other row is byte-identical, including `ActionOrderTest3/4/5`, `PlaceAndRemove`, `_extend_test`, all `regression/avm1_attach*` and `avm1_exec_order*`, and `avm1/attach*`.
- **Graphics:** 38-row subset (attach / exec_order / selfgoto / action_order). The same 2 rows change and match no-graphics. `PlaceAndRemove` has a mode difference, but it is identical before and after, so it predates this slice.
- **Expected CI ledger:** +1 passing row (the fixture), 0 flips elsewhere. test11 stays output_mismatch with a smaller diff. Any other flip is a defect of this slice. The suspect would be a tick where a clip created later than a timeline sibling has a natural-advance frame script.

## 5. Browser (WSLg Chrome, functional only)

- **Fixture via `child_probe`:** build rc=0, linked with `-Wl,--fatal-warnings`.
  - The exec-list order matches Flash.
  - Two **pre-existing, browser-only** differences remain. Both also show in the kill-switch build (`-DSWF_EXEC_ORDER_MERGED_OFF`), which has the old timeline-first order:
    1. **An attached clip's TIMELINE child advances on the attach tick** (`pt f2` on tick 1, so `ap60.pt` runs one frame ahead from then on). Cause: the browser-only "force nested build" block in `ng_attachMovie` (tag_stubs.c, `#if !NG && !OR`, after frame 0) calls `advance_sprite_frames` on the clip's list. Since s27 ported eager placement init to the browser, the child is already built, so this block ADVANCES it. That block exists for Minesweeper's `frb_states_mc` bounds. **Next slice (S):** gate it to unbuilt holders only (`sprite_display_list == NULL`), or delete it if eager init covers Minesweeper. Grade with this fixture plus the Minesweeper radio circle.
    2. `Warning: Failed to place object at depth 1.` each time P loops back to frame 1. This is the browser placement path warning on a same-char re-place. Flash prints nothing.
- **Doodle Jump:** `rebuild_docs2_demos.sh flasharchive --only Doodle_Jump,N --fast` (rc=0, 0 wasm-ld warnings). `dj_alive.py click` reached gameplay 3/3 (root frame 1, rAF climbing, page answering).
- **N:** `N_drive` rebuilt seeded (`EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000`), rc=0, 0 warnings. The ND/NF telemetry is **byte-identical** to the page's previous browser trace (Nov 26) over all 541 lines it reached in 90 s under load. Only the wall-clock `# shot … at` stamps differ.
- **Shared-tree note:** peer commits `6a27fc2e0`/`fec84dcea`/`758475172` (LOW stroke raster, render-only) landed while the sweep ran. The fixture was re-graded in both modes on the committed tree.

## 6. Method notes

- **Fit a Flash order capture to Ruffle's `clip_exec_list` FIRST.** I first misread a tick boundary and "found" clips created on tick 2 running after `_root`. Mark the ticks with a root trace in every frame, and cut the golden at a root line.
- An env kill switch makes a stash-free A/B in a shared tree. Both legs compile the same source, so ccache makes the second leg nearly free. The sweep was 310 single-test runs at `-P 4` under one lock hold, about 35 min.
