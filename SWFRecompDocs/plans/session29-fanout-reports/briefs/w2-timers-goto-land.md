**Land w1-timers-goto items 3, 1, 4 and re-derive item 2 against FP32 (S–M).**

Read `session29-fanout-reports/w1-timers-goto-report.md`, `w1-timers-goto-prototype.patch` (+ `-goto-only.patch`) and
the coordinator's FP32 results `w1-local-oracles/w1-timers-goto/README.md` (goldens `<fixture>.r1.txt` there; fixture
sources `w1-timers-goto-fixtures/`).
1. **Item 3 (land):** tag-order goto hook (`SWF_GOTO_TAGORDER`); Flash confirms gotoscript/interval = proto. Ledger:
   gnash `gotoFrameFromInterval` and `gotoFrameFromInterval2` rm→pass (graphics AND no-graphics: you touch `swf_core.c`).
   Add `regression/avm1_goto_target_child_order_{normal,gotoscript,interval}` with the FP32 goldens. Update the stale RvF
   "Unbounded Runaway" line ("our runtime ... times out").
2. **Item 1 (land):** replace `regression/avm1_timer_clock_model` with the bound-check form (FP32 3/3 == proposed
   `output.txt`) + the callback-time clock refit (`SWF_TIMER_CB_CLOCK`). Re-run the 24-row timer gate.
3. **Item 4 (land root, derive sprite):** root nextFrame/prevFrame inline arm = proto (FP32 r1 == r2 == proto). The
   sprite fixture matches NEITHER leg: Flash runs a sprite's nextFrame/prevFrame inline inside onEnterFrame (target
   frame's script runs immediately, `_currentframe` updated). Implement that, make both fixtures pass against FP32, add
   them as `regression/avm1_enterframe_{root,sprite}_nextframe`.
4. **Item 2: the "timer check after enterFrame" prototype is REFUTED** (FP32 keeps TB/TC where master has them). Drop it.
   What remains vs master is `_currentframe` read inside a timer callback (`TA cf=4` vs ours 3, `TC cf=10` vs ours 9):
   find the rule (which frames' callbacks see the advanced frame), fix if S, and add the fixture with the FP32 golden.
   If no rule fits deterministically, land the fixture only if we pass it; otherwise report HOLD with the mechanism.
Ledger: +2 gnash rm→pass; new regression rows pass; 0 other moves in both modes (`categories=full` grading).
Siblings: local browser ladder (`ng_gotoFrameByMC` same-frame branch, browser gotoAndStop(current) guard — don't touch),
w2-disposition-land (action.c builtins, tabIndex). Name every function you touch in tag.c/swf.c/swf_core.c/action.c/timer.c.
