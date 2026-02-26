# Ruffle Test Results Diff

**Previous:** `7a73471ab5c0` (2026-02-25T23:21:14.906438+00:00)
**Current:** `5990fc78c71c` (2026-02-26T00:26:44.146501+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 362 | 364 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 58.5% | 58.8% | +0.3% |
| Mismatched lines | 32899 | 32879 | -20 |
|   Decreased | | | -30 |
|   Increased | | | +10 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `constructor_function` | output_mismatch | 0/2 | 2/2 |
| `init_object_order` | output_mismatch | 5/15 | 15/15 |
| `property_invalid_base_clip` | output_mismatch | 34/36 | 36/36 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `array_constructor` | output_mismatch | 30/30 | 29/30 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `object_resolve` | output_mismatch | 0/38 | 14/38 | -14 |
| `path_string` | output_mismatch | 38/322 | 40/322 | -2 |
| `coerce_to_object_monkeypatch` | output_mismatch | 10/129 | 7/129 | +3 |
| `tell_target` | output_mismatch | 10/37 | 4/37 | +6 |
