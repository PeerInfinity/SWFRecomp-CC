# New upstream timer rows: Flash 32 captures (s28 coordinator, 2026-11-25)

These 4 rows first appeared in interim #5 (`45750698566`, results `6129ad0e1`). They come from upstream Ruffle
`2fa4e1e4c` "tests: Add timer_tie_order tests for AVM1 and AVM2" and its neighbours. Each directory holds the upstream
files (`test.swf`, sources, `test.toml`, `output.txt`) plus `flash32.trace.txt`, a direct pinned run with
`--log-warnings` on the Linux FP32 projector.

| row | CI (graphics) | FP32 vs upstream `output.txt` |
|---|---|---|
| `avm1/timer_tie_order` | output_mismatch | **BYTE-IDENTICAL** |
| `avm2/timer_tie_order` | timeout | **BYTE-IDENTICAL** |
| `avm2/timer_checks_per_frame` (upstream `known_failure = true`, `tick_rate = 10`) | timeout | **BYTE-IDENTICAL** |
| `avm2/timer_timeout_ids` | output_mismatch | **BYTE-IDENTICAL** |

All 4 goldens are Flash, so each failure is a real gap.

## `regression/avm1_timer_clock_model` (w3-new-timer-rows oracle request)

3 direct FP32 runs, 12 frames at 10 fps: `regression__avm1_timer_clock_model/flash32.trace.txt`, `flash32.run2.txt`,
`flash32.run3.txt`. **Flash is not deterministic here**: the three runs differ from each other.
- F2/F3: the ordering of near-tie events (`n`, `a3`, `e`, `b` against the `F3` frame boundary) changes from run to run.
- F5–F7: two intervals (10 ms + 13 ms) give **cnt = 10 or 12 per 100 ms frame** in every run. The analytic golden says
  16/18/18, which assumes ideal catch-up on a 1 ms clock.

So Flash's idle polling fires about 5–6 times per interval per frame, about 16–20 ms resolution on this box. It does not
catch up to every due time, and it does not fire once per update either. The analytic golden stays as it is: no
deterministic Flash golden is possible for F5–F7. Open item for session 29: replace the analytic catch-up counts with a
rule fitted to Flash's poll granularity, or reduce F5–F7 to a bound check. No code change in s28.
