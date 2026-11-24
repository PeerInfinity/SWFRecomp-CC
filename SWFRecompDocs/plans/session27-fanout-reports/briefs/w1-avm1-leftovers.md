**Trace, AVM1 leftovers** (arc §27.4 "AVM1 leftovers"). Categories: `avm1`, `from_gnash`, `from_shumway`, `regression`. Prior record: `session26-fanout-reports/w1-avm1-dispatch-scope-report.md`, `w2-avm1-text-resolve-report.md`.

1. Merge AS-handler MovieClip mouse dispatch (`onPress`/`onRelease`/`onRollOver` on clips) into the DefineButton pick, so one topmost target is picked across both (M). Fixture with a Ruffle-runner golden request (input.json).
2. Path-variable scope for non-button EditTexts (`variable = "_root.mc:foo"` binding resolution).
3. `__resolve` through dotted GetVariable paths (`a.b.c` where `b` misses).
4. `setNewTextFormat` size/font (s26 did colour).
5. Cut/Copy act on the whole text, not the selection.
6. Grep the other SWF≤6 case-sensitive builtin arms (s26 gnash `sound` was `gotoandPlay`; find every builtin name compare that is case-sensitive where SWF≤6 must be case-insensitive).
7. Re-check the 38 failing graphics trace rows (`s27-baseline-trace-failing.txt`) for any AVM1 row your fixes touch; the action_order family and `global_*` rows are standing NO-GOs, so do not re-diagnose them unless a fix moves them.

Each fix gets a `regression/` fixture with an oracle-outside-SWFRecomp golden (exporter for frame traces, Ruffle runner for input/timers; LOCAL ORACLE REQUESTS). Siblings: `w1-browser-avm1-gaps`, `w1-timers-robustness`. Name every function you touch in `action.c`.
