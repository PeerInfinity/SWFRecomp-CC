# Ruffle Test Results Diff

**Previous:** `0f59569503a9` (2026-03-05T19:12:52.592953+00:00)
**Current:** `af0303883e72` (2026-03-05T20:45:05.086080+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 462 | 457 | -5 |
| Total | 619 | 619 | 0 |
| Pass rate | 74.6% | 73.8% | -0.8% |
| Mismatched lines | 21494 | 21832 | +338 |
|   Decreased | | | -74 |
|   Increased | | | +412 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `edittext_html_color` | output_mismatch | 114/114 | 38/114 |
| `funky_function_calls` | output_mismatch | 56/56 | 52/56 |
| `parse_int` | output_mismatch | 64/64 | 1/64 |
| `primitive_type_globals` | output_mismatch | 557/557 | 326/557 |
| `swf4_actions_coercion_order` | output_mismatch | 158/158 | 137/158 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `instanceof_coercions` | output_mismatch | 12/88 | 86/88 | -74 |
| `interface_implements_op` | output_mismatch | 1/47 | 0/47 | +1 |
| `movieclip_library_state_values` | output_mismatch | 76/78 | 71/78 | +5 |
| `coerce_to_object_monkeypatch` | output_mismatch | 16/129 | 5/129 | +11 |
