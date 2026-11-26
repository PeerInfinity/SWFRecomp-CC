**CI drops a root GotoFrame OPCODE issued inside onEnterFrame; Flash 32 does not (M).**

Inputs: the fixture `session28-fanout-reports/browser-attached-goto-fixtures/avm1_enterframe_root_goto_opcode/`
(`README.md`, `create_test_swf.py`, `test.swf`, `test.toml`, `flash32.trace.txt` = FP32 direct, and
`native_nographics.trace.txt`). Flash: `f1 / ef cf=1 / after cf=3 / f3 cf=3 / ef cf=3 …` (the playhead moves INLINE, and
frame 3's DoAction runs after the handler). Ours: `after cf=1`, root stays on frame 1. Cause: `actionGotoFrame`
(`action.c`) returns early under `g_inside_enterframe_dispatch` ("Dejagnu checker retries every tick"); since
`dc6c75a64` the browser takes this arm too. The method forms (`_root.gotoAndStop(3)`) don't hit the rule.

Task:
1. Find why the rule exists: `git log -S g_inside_enterframe_dispatch`, the gnash Dejagnu rows it was written for, and
   what they print with the rule removed. Find the Flash-correct model that keeps those rows (FP32 goldens:
   `trace-provenance.md` table A/B) — e.g. a goto to the CURRENT frame is a no-op, or the retry pattern is really about
   a different mechanism.
2. Implement it (both modes; browser shares the arm), land the fixture as `regression/avm1_enterframe_root_goto_opcode`
   with the FP32 golden (cut to `num_frames`).
3. Gate: every gnash `misc-*` and `actionscript.all` row, avm1 rows with goto/enterframe in the name, `regression`, both
   modes. EXPECTED-FLIP LEDGER by name; any row that moves must be explained against its FP32 golden.
