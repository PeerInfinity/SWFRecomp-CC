# Ruffle Test Results Diff

**Previous:** `45164a5b0854` (2026-05-15T03:20:32.428760+00:00)
**Current:** `ef6584787e7e` (2026-05-16T20:55:02.523668+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 604 | 601 | -3 |
| Total | 654 | 655 | +1 |
| Pass rate | 92.4% | 91.8% | -0.6% |
| Mismatched lines | 9290 | 9292 | +2 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `action_to_integer` | runtime_error | 28/28 | - |
| `as2_super_and_this_v8` | runtime_error | 85/85 | - |
| `as2_super_via_manual_prototype` | runtime_error | 40/40 | - |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `sound_gettransform_props` | output_mismatch | 2/4 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_proto_decls_delete` | output_mismatch | 386/4158 | 386/4158 | 0 |
