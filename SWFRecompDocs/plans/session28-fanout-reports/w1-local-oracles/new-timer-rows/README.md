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
