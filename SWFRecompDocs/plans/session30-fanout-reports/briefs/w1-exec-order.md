**Exec order, the remaining halves: enterFrame before the clip's own script + the clip-event merge (M–L;
IMPLEMENTATION in wave 1).** This slot delivers a LANDABLE patch, so follow the **Wave-2 additional rules** in
`BRIEFS_COMMON.md` as well and deliver `w1-exec-order.patch` (not a prototype).

State: `078350610` (s29 browser-attach-order, report `session29-fanout-reports/browser-attach-order-report.md` §3 is
the mechanism: `action_queue.c` `order_key`, `actionAQOrderMark`/`actionAQOrderSortSince` in `swf.c` and `swf_core.c`,
`tag.c advance_sprite_frames`/`advance_nested_sprite_frames`, `tag_stubs.c ng_attachMovie` place_seq) made
natural-advance frame scripts ONE list, newest place_seq first, `_root` last, all builds; kill switch
`SWF_EXEC_ORDER_MERGED=0` (browser: `-DSWF_EXEC_ORDER_MERGED_OFF`). Still open (`n-exec-order-report.md` §2b reqs 1 and
3): (1) each child's enterFrame fires immediately before that child's own queued frame script; (3) the
`onClipEvent(enterFrame)` walk (display-list order, children before parents today) merges into the same order. Ruffle's
`run_frame_avm1` / `clip_exec_list` is the reference shape (read `/root/ruffle/core/src/display_object/movie_clip.rs` and
`core/src/frame_lifecycle.rs` in your clone), but **the goldens are Flash** (TP): fit to the goldens, not to Ruffle.

Family (all gnash misc-ming `action_order/` unless noted; register §1a first row): `ActionOrderTest3/4/5`,
`PlaceAndRemove`, `action_execution_order_extend_test`, `_test4`, `_test11` (mismatch), plus the rm members `_test`,
`_test6`, misc-swfc `_test10`, `loop_test10`. **`_test11` is the probe**: it moved Flash-ward 10 → 8 diff lines with
`078350610`; its tail is the enterFrame/ctor interleave.

Task:
1. Reproduce `_test11` and the family on origin/master; mark tick boundaries with a root trace before you fit an order
   (the s29 method note: misread ticks "found" false orders).
2. Implement reqs 1 and 3 behind the SAME kill switch (or a second one, `SWF_EXEC_ORDER_EF=0`), in every build
   (`swf.c`, `swf_core.c`; `#ifdef NO_GRAPHICS` arms too). Self-localize.
3. A/B with the kill switch over ALL action-order + timeline + clip-event rows (the s29 sweep scanned every AVM1
   `test.swf` with `attachMovie` or ≥2 scripted sprites, 174 rows; also every row with `onClipEvent(enterFrame)` or
   `onEnterFrame` in a test.as/`.sc`): ACTUAL outputs diffed, both modes (you touch `swf_core.c`). Every changed output
   by name with direction vs its golden.
4. `regression/` suite near the change; new fixtures only with an outside oracle (write FLASH requests: ship SWFs).
5. **Browser:** you cannot run a browser in the cloud. List under LOCAL ORACLE REQUESTS a "BROWSER child_probe" request:
   the fixtures to run in `tools/browser-test/child_probe/` (`build_child_probe.sh <fixture>` + `run_child_probe.py <fixture>`) and what to
   compare. The coordinator grades the browser build at landing.
Deliver an exact EXPECTED-FLIP LEDGER (both modes). If req 3 prices out L with losses, land req 1 alone and HOLD 3 with
its completion mechanism. Siblings: the local browser ladder works in `tag_stubs.c ng_attachMovie` (force-nested-build
advance) at the same time: name every function you touch in `tag_stubs.c`, `swf.c`, `swf_core.c`, `action_queue.c`,
`tag.c`; the coordinator lands you and the ladder one at a time.
