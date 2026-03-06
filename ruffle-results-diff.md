# Ruffle Test Results Diff

**Previous:** `6ebe9e2cba0a` (2026-03-06T05:53:33.077198+00:00)
**Current:** `36e2e955d8f5` (2026-03-06T17:05:14.034013+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 480 | 480 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 77.5% | 77.5% | 0% |
| Mismatched lines | 20229 | 20291 | +62 |
|   Decreased | | | -120 |
|   Increased | | | +182 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `external_interface` | output_mismatch | 11/84 | 84/84 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `native_subclasses` | output_mismatch | 191/191 | 9/191 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `coerce_to_object_monkeypatch` | output_mismatch | 17/129 | 64/129 | -47 |
| `loadmovienum_cross_version_prototype` | output_mismatch | 6/9 | 6/9 | 0 |
