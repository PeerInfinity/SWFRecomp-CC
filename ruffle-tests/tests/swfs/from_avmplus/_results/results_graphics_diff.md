# Ruffle Test Results Diff

**Previous:** `bc91565cea8e` (2026-11-21T18:24:43.187376+00:00)
**Current:** `c489b84d9946` (2026-11-21T19:32:37.141802+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1531 | 1533 | +2 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 97.3% | 97.4% | +0.1% |
| Mismatched lines | 434 | 428 | -6 |
|   Decreased | | | -6 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/RuntimeErrors/Error1092XmlUnterminatedXmlDecl` | output_mismatch | 0/1 | 1/1 |
| `regress/bug_478501` | output_mismatch | 0/1 | 1/1 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `e4x/XML/bug_564468` | output_mismatch | ruffle_matched | 3/10 | 6/10 |
| `e4x/XML/misc_errors` | output_mismatch | ruffle_matched | 31/33 | 32/33 |
