**Trace, timers + robustness tail** (arc §27.4 "Timer goto-skipped DoInitAction" and "Robustness tail"). Categories: `from_gnash`, `avm1`, `regression`. Prior record: `session26-fanout-reports/w2-timer-semantics-report.md`, `w2-robustness-land-report.md`.

1. **Timer goto-skipped DoInitAction:** `_root.gotoAndPlay(9)` from a frame-7 timer never runs frame 8's DoInitActions (`from_gnash/misc-swfc.all/gotoFrameFromInterval`, graded `ruffle_matched`; check `output.ruffle.txt` and `known_failure`: a `pass → ruffle_matched` move would be a regression, and a move toward Flash's output is the goal). Owner is the goto catch-up path when called from `processTimers` (`timer.c`) vs from a frame script. Fixture (Ruffle-runner golden request; the exporter never fires timers).
2. Small timer gaps: method-form `setInterval(obj, "name", ms, ...)` detection needs `num_args>=3`; `clearInterval` argument coercion. Fixtures.
3. **func2 register reads past RegisterCount** (XS): reads of registers ≥ RegisterCount must behave like Flash (what does Flash/Ruffle return?).
4. **Remaining fixed caps**: `MAX_SCROLL_CROPS`, `MAX_TEXT_CULLED`, `LAZY_PROTOS`, `WATCH`, `EI_CALLBACKS`, `CLONE_DEPTH`, `TIMERS`. For each: what happens at the cap today (silent drop? overflow?), and convert to growable where a game could reach it. Fixture for each overflow behaviour (s26 pattern: `avm1_*_overflow` fixtures).
5. Dead `tagSetFilter*`: confirm dead and remove, or show who calls it.

Siblings: `w1-avm1-leftovers` (`action.c` builtins), `w1-exec-order` (frame loop). Name every function you touch in `action.c`/`tag.c`/`ng_shared.c`.
