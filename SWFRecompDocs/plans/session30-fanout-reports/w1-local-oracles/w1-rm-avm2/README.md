# w1-rm-avm2 LOCAL ORACLE REQUESTS (s30 coordinator, 2026-11-27, FP32 LNX direct pinned unless noted)

0. `avm2/xml_appendchild_swf_v21`, `avm2/loaderinfo_child_progress` (`*.f3r{1,2}`): child_progress == golden, 2/2
   identical. xml_appendchild: the `[loadable.swf]` lines appear even with `--frames 1 --overrun 0` (`.f1hard.r{1,2}`),
   but a direct run's frame cut is wall-clock, and `--wrapped` never boots the child (`.wrapped{1,2}`: 0 loadable
   lines). **So FP32 cannot pin which tick the child traces land in: L1′'s two harness losses are not gradeable →
   HOLD L1′.**
1. `avm2/array_sort_swf10_32bit` (`.r1.lnx.txt`, `.r1.win.txt`): **LNX FP32 prints the `_64bit` golden, WIN FP32 prints
   the `_32bit` golden.** Both goldens are Flash; the split is the host projector's bitness. No swap (WIN ≠ LNX → keep);
   RvF/ACCEPTED as host-bitness.
2. `timeline/swf_9_frame_script_dynamic_goto`, `swf_9_event_goto_frame_script` (`.r{1,2}`): both == golden, 2/2.
3. `from_shumway/timeline/nav/clipDepth` `--frames 6` == golden (8 lines; nothing after) → a `kind: toml` `num_ticks`
   fix is valid. `avm2/swf_9_goto_in_construct_frame` `--frames 6` (`.f6`, `.f6r2`): the 20-line golden is an exact prefix;
   after it FP32 repeats a 6-line steady-state cycle (`MyOtherChild onEnterFrame` … `MyContainer enterFrame`), so the
   golden ends mid-cycle (the 21st line is `MyOtherChild onEnterFrame`).
4. `mask_removal/` (AS3, built here): script `removeChild(mask)` (direct, or of the mask's ancestor) does NOT null
   `maskee.mask`; hiding the mask keeps it; re-adding keeps it. M1 must stay scoped to the RemoveObject TAG path.
   (A goto-removal variant needs a timeline SWF: not built.)
5. `pixelbounds_offlist/` (AS3): off-list `transform.pixelBounds` = the transformed bounds (incl. the object's own x/y
   and scale) × 5 on every component (`(0,0,100,100)` at x=5,y=7 → `(25, 35, 500, 500)`; scaleX 2 → w 1000); on-list =
   the normal stage bounds; empty sprite → all 0. After `removeChild` it is the ×5 form again.
