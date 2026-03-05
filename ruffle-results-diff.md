# Ruffle Test Results Diff

**Previous:** `af0303883e72` (2026-03-05T20:45:05.086080+00:00)
**Current:** `f9c99c392d9a` (2026-03-05T21:14:01.149533+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 457 | 461 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 73.8% | 74.5% | +0.7% |
| Mismatched lines | 21832 | 21422 | -410 |
|   Decreased | | | -410 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_html_color` | output_mismatch | 38/114 | 114/114 |
| `parse_int` | output_mismatch | 1/64 | 64/64 |
| `primitive_type_globals` | output_mismatch | 326/557 | 557/557 |
| `swf4_actions_coercion_order` | output_mismatch | 137/158 | 158/158 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `coerce_to_object_monkeypatch` | output_mismatch | 5/129 | 17/129 | -12 |
| `movieclip_library_state_values` | output_mismatch | 71/78 | 76/78 | -5 |
| `funky_function_calls` | output_mismatch | 52/56 | 54/56 | -2 |
