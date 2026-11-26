**Land w1-rm-avm2 (D1 Date DST + `mock_timezone`, P debug line info, O1, O2, L1) + 3 trace flash_fixes (M).**

Read `session29-fanout-reports/w1-rm-avm2-report.md` and apply `w1-rm-avm2-prototype.patch` (incl. its 15 toml
flash_fixes). Coordinator FP32: `w1-local-oracles/w1-rm-avm2/README.md`: `try_catch_typed` FP32 prints exactly your
predicted `[file:line]` suffixes; `e15_9_5_35_1` under host `TZ=PST8PDT,M3.2.0,M11.1.0` is byte-identical to its golden.
1. Land the prototype. Add trace flash_fixes (README rules; verify upstream sha256 on your fresh download; RvF entry):
   `avm2/try_catch_typed` → `w1-local-oracles/w1-rm-avm2/try_catch_typed.fp32.txt`;
   `avm2/slot_holes_fail`, `avm2/slot_id_exceeds_trait_count` → `session28-fanout-reports/trace-provenance/avm2__slot_*.r1.txt`
   (grade ours against them; they stay rm/mm unless O3 is cheap — price O3 but don't sprawl).
2. CI must see the `mock_timezone` key: check `.github/workflows/ruffle-tests.yml` / the CI runner path through
   `verify_output.py` (parallel runner, NG mode) so the override reaches every invocation; prove it in no-graphics too.
   Make the key fail-safe: an unknown value must not silently fall back.
3. Interaction: sibling `w2-disposition-land` prints FP32's #2044/#2046 securityError for `avm2/swz` but lacks the
   `[file:line]` suffixes (its lead L1 = your P). With both landed, `swz` should pass against its FP32 flash_fix. Your
   tree won't have their patch: just predict it in your ledger.
4. Regression fixture for P from a debug SWF if the corpus doesn't cover nested frames (otherwise none).
Ledger: the report's 19 rm→pass + `try_catch_typed` stays pass (swap) by name, both modes; `categories=full`.
Siblings: w2-disposition-land (`avm2_error.c` `avm2_error_callstack_tail` — you edit `callstack_snapshot`: keep hunks
separable), w2-timers-goto-land. Name every function you touch.
