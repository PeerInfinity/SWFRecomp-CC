# w3-new-timer-rows

**4 new upstream timer rows fail, and all 4 goldens are Flash 32 (M).**

Rows (new upstream tests, Ruffle `2fa4e1e4c` and neighbours; they first ran in interim #5 `45750698566`):
`avm1/timer_tie_order` (output_mismatch), `avm2/timer_tie_order` (timeout), `avm2/timer_checks_per_frame` (timeout;
upstream marks it `known_failure = true`, `tick_rate = 10`), `avm2/timer_timeout_ids` (output_mismatch).

Inputs: `session28-fanout-reports/w1-local-oracles/new-timer-rows/` (README + per-row upstream files +
`flash32.trace.txt`). The coordinator's FP32 direct captures are **byte-identical to upstream `output.txt` for all 4**,
so match `output.txt` exactly. Download the rows with `download_tests.sh` as BRIEFS_COMMON says.

Task:
1. For each row, diff our output against the golden and find the owner: setInterval/setTimeout tie order at equal
   due times, how many timer checks run per frame, timeout id allocation, or why the AVM2 rows time out (a hang, or
   `num_ticks`/`tick_rate` handling in `verify_output.py`). Record the root cause per row.
2. Fix what you can, keeping the timer model shared by both modes and the browser (`timer_system`, `swf_core.c` /
   `swf.c` pumps). If a row needs a harness change (e.g. `tick_rate`), put it in `verify_output.py` and say so.
3. Gate: every avm1/avm2/from_gnash/from_shumway row with `timer`, `interval`, `timeout` or `settimeout` in its name,
   all of `regression`, both modes (no-graphics too if you touch `swf_core.c`). EXPECTED-FLIP LEDGER by name; explain
   every other move against its FP32 golden (`trace-provenance.md` tables say which goldens are Flash).
4. Anything left unfixed: name the remaining diff, its owner and a size.
