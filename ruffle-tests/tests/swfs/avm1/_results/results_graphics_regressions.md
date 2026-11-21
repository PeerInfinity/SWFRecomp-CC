# Graphics vs Trace Mode Differences

Trace: 727/777 passing | Graphics: 734/777 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (7 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `edittext_asfunction_case_insensitive` | Output Mismatch | 0/1 lines match |
| 2 | `file_reference_listeners_per_instance` | Output Mismatch | 2/24 lines match |
| 3 | `localconnection_reference_identity` | Output Mismatch | 2/5 lines match |
| 4 | `localconnection_serialize_inherited_array_indices` | Output Mismatch | 10/12 lines match |
| 5 | `shared_object_members_swf5` | Output Mismatch | 25/32 lines match |
| 6 | `video_width_height` | Output Mismatch | 3/19 lines match |
| 7 | `xml_status_mismatched_tags` | Output Mismatch | 40/63 lines match |
