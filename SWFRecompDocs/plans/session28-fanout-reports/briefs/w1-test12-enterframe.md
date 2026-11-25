**gnash `from_gnash/misc-swfc.all/action_execution_order_test12`: the only trace row lost vs Flash 32 in s27 (S–M).**

Facts of record (`polish-sweep-arc.md` §28 "Interim #3's three regressions"; `session27-fanout-reports/w3-interim3-regressions-report.md`, `w2b-timers-tail-report.md`):
- Real Flash 32 (direct, pinned) prints `output.fp10.txt` byte for byte; capture at
  `SWFRecompDocs/plans/session27-fanout-reports/flash-oracle-captures/action_execution_order_test12/flash32.lnx.direct.txt`.
  The graded golden is that FP10 file. `output.fp9.txt` is Flash Player 9 only.
- Line 19 (`asOrder`) already matches FP32 (s27's init flush at call return). **Do not undo that fix.**
- Line 17 (`enterFrameOrder`) does not: FP10+ runs onEnterFrame **once** on clips 4 and 5
  (`0+1+2+3+1+2+4+3+1+2+5+3+…`). We, Ruffle and FP9 don't.

Task:
1. Read the test source (`.sc`/swfc source in the gnash suite dir, or decompile the SWF) and find exactly which clips 4/5
   are, how they're created (placed / attached / duplicated / loaded) and on which frame, and the rule that gives them
   one extra enterFrame in FP10+ (e.g. a clip placed during the frame's action phase gets enterFrame that same tick?).
   Attack the premise: is it enterFrame on a newly-created clip, the ordering of the enterFrame list, or an unload/reload?
2. Write the minimal general rule, find our owner (`action.c` `actionDispatchEnterFrameHandlers` /
   `dispatch_root_dprops_enterframe`, `tag.c`/`swf.c` frame loop, `MovieClip.ef_fired_tick`), and prototype it.
3. Gate: this row + the whole gnash `action_order` family + `misc-swfc.all` + avm1 rows with `enterframe`/`onEnterFrame`
   in their name + the `regression` suite (graphics mode; also no-graphics for headline rows if you touch NG arms). The
   action_order NO-GOs (`ActionOrderTest3/4/5`, `PlaceAndRemove`, `extend_test`, `test11`) are known-failing: report any
   line movement on them, toward or away from their golden.
4. Write a regression fixture that isolates the rule (Flash capture request: direct, pinned) and list it under LOCAL
   ORACLE REQUESTS with a built SWF.
5. Ruffle misses this too: draft the RvF entry text in your report (the coordinator appends it on landing).
Deliver a measured prototype patch if it gates clean; otherwise a priced NO-GO with the mechanism.
