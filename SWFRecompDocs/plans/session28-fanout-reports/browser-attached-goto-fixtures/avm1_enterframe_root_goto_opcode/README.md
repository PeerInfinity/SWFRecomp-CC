# avm1_enterframe_root_goto_opcode: CI drops a root GotoFrame opcode issued in onEnterFrame (Flash does not)

Found in s28 browser-attached-goto (goal 4). Funded as its own cloud slot by the coordinator. **Do not land this
fix without a corpus gate**: gnash Dejagnu rows depend on the rule.

**SWF** (`create_test_swf.py` → `test.swf`, SWF 8, 12 fps, 3 frames). Frame 1 sets
`_root.onEnterFrame = function () { trace("ef cf=" + _root._currentframe); if (!_root.done) { _root.done = 1;
gotoAndStop(3) /* bare GotoFrame 0x81, frame index 2 */; trace("after cf=" + _root._currentframe); } }`,
traces `f1` and `stop()`s. Frame 3 traces `f3 cf=` + `_currentframe`.

**Flash 32** (`tools/flash-oracle/run_trace.py`, direct mode, Linux projector): `flash32.trace.txt`. The first 4
lines, then `ef cf=3` every frame:

    f1 / ef cf=1 / after cf=3 / f3 cf=3 / ef cf=3 ...

The playhead moves inline: `_currentframe` is 3 before the handler returns, and frame 3's DoAction runs after the
handler.

**Native no-graphics at 60877dc63** (`verify_output.py --test=… --tests-dir=<dir containing this one>`, num_frames=5):
`native_nographics.trace.txt`:

    f1 / ef cf=1 / after cf=1 / ef cf=1 ...

The goto is dropped. Cause: `actionGotoFrame` (action.c) returns early under `g_inside_enterframe_dispatch`
("When called from inside an enterFrame handler, skip the goto entirely ... Dejagnu checker retries every tick").
Since s28 browser-root-goto (dc6c75a64) the browser takes this arm too. Graphics native was not run separately;
it compiles the same action.c arm.

The method forms (`_root.gotoAndStop(3)`) do not hit this rule. Only the opcode does, when it resolves to the
root (no sprite context, no SetTarget).

Note on the `output.txt` for grading: as a regression fixture, use the Flash lines with `num_frames` sized to the
native span (5 frames → `f1`, `ef cf=1`, `after cf=3`, `f3 cf=3`, then one `ef cf=3` per remaining frame; confirm
the count against a native run once fixed).
