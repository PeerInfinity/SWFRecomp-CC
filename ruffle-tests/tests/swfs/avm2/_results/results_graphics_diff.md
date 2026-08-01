# Ruffle Test Results Diff

**Previous:** `375373786d2d` (2026-08-01T03:29:50.726669+00:00)
**Current:** `3ebcb54f10d2` (2026-08-01T06:45:19.619734+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1068 | 1080 | +12 |
| Total | 1224 | 1224 | 0 |
| Pass rate | 87.3% | 88.2% | +0.9% |
| Mismatched lines | 33380 | 33272 | -108 |
|   Decreased | | | -108 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `escape_multi_byte` | output_mismatch | 1/45 | 45/45 |
| `issue_8630_placeremoveplace_scriptremove` | output_mismatch | 15/16 | 16/16 |
| `rtqname_not_namespace` | output_mismatch | 9/12 | 12/12 |
| `supercalls_weird` | output_mismatch | 0/2 | 2/2 |
| `superinterface_call` | output_mismatch | 15/20 | 20/20 |
| `superinterface_instanceof` | output_mismatch | 4/18 | 18/18 |
| `url_vars` | output_mismatch | 3/27 | 27/27 |
| `verify_exception_target_two_jumps` | output_mismatch | 0/1 | 1/1 |
| `verify_method_info_oob` | output_mismatch | 0/1 | 1/1 |
| `verify_typecheck` | runtime_error | 0/4 | 4/4 |
| `xml_appendchild_swf_v21` | output_mismatch | 12/13 | 13/13 |
| `xml_list_delete_clear_parent` | output_mismatch | 1/6 | 6/6 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bom` | output_mismatch | 4/9 | 6/9 | -2 |
| `verify_method_info_duplicate` | output_mismatch | 0/2 | 1/2 | -1 |
