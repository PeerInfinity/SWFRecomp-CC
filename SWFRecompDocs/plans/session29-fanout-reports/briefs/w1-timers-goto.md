**Timers tail + goto/nav residue (S–M).**

1. `regression/avm1_timer_clock_model`: our golden is analytic (cnt 16–18) but Flash gives cnt 10–12 over 3 FP32 runs
   (nondeterministic, wall-clock). Either refit the model to Flash or convert the fixture into a bound check that both
   Flash runs and ours satisfy (print a pass/fail line, not the raw count). Never grade a timer fixture on one capture.
2. An AVM1 timer check after enterFrame (the AVM2 side got "an overdue pass after enterFrame" in `8be319e93`): does
   AVM1 run due intervals after the enterFrame dispatch in the same tick? Build a minimal direct-mode fixture (MTASC, see
   CLAUDE.md; or a tiny hand-built SWF) that distinguishes the orders deterministically (busy-wait past the interval
   inside onEnterFrame), and put it under LOCAL ORACLE REQUESTS (FLASH, trace, several runs). Prototype our side so the
   wave-2 slot only needs the golden.
3. gnash `from_gnash/misc-swfc.all/gotoFrameFromInterval` and `gotoFrameFromInterval2`: still `ruffle_matched` against
   FLASH goldens (upstream also just changed `gotoFrameFromInterval/output.ruffle.txt`). Name the missing lines, the
   mechanism (owner file:line), and fix if S–M.
4. `actionNextFrame`'s `g_inside_enterframe_dispatch` arm (`SWFModernRuntime/src/actionmodern/action.c`): s28's
   `4a25debc9` removed the equivalent early return from GotoFrame because Flash moves the playhead. Is the NextFrame /
   PrevFrame arm stale in the same way? Build the fixture (root nextFrame() inside onEnterFrame, plus a sprite variant),
   predict Flash, FLASH request; prototype the removal and run the s28 fixture `regression/` rows near it
   (`grep -l enterframe ruffle-tests/tests/swfs/regression/*/test.toml` or by name) + canaries.
Siblings: the local browser ladder owns `ng_gotoFrameByMC`'s same-frame branch and the browser-only gotoAndStop(current)
guard: do NOT touch those. Name every function you touch in action.c / timer.c / tag.c.
