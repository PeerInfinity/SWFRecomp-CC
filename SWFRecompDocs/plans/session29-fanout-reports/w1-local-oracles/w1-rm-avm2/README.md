# w1-rm-avm2 local oracle results (s29 coordinator, 2026-11-26, FP32 LNX direct pinned)

| request | result |
|---|---|
| 1. `avm2/try_catch_typed` | FP32 prints `\tat Test()[Z:\tests\tests\swfs\avm2\try_catch_typed\Test.as:33]` and `\tat test_fla::MainTimeline/frame1()[test_fla.MainTimeline::frame1:1]` = the w1 prediction exactly. Golden (no suffixes) ≠ Flash → flash_fixes `output.txt` = `try_catch_typed.fp32.txt`. |
| 3. `from_avmplus/ecma3/Date/e15_9_5_35_1` with host `TZ=PST8PDT,M3.2.0,M11.1.0` | **BYTE-IDENTICAL to the golden** → the Date goldens are reproducible on Linux FP32 under that TZ; the `mock_timezone` key value is right. |
| 2. acid-text-x autoSize probe | not run (optional N4 lead; no fixture shipped). |
| 4. `slot_holes_fail`, `slot_id_exceeds_trait_count` | captures already on master: `session28-fanout-reports/trace-provenance/avm2__slot_*.r1.txt`. |
