# Ruffle Test Results Diff

**Previous:** `513653e94312` (2026-11-22T08:44:18.527873+00:00)
**Current:** `697669e5f98f` (2026-11-22T23:31:11.604000+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 742 | 745 | +3 |
| Total | 780 | 781 | +1 |
| Pass rate | 95.1% | 95.4% | +0.3% |
| Mismatched lines | 12574 | 12614 | +40 |
|   Decreased | | | -118 |
|   Increased | | | +3 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_set_text_same` | output_mismatch | 28/70 | 70/70 |
| `edittext_set_text_same_after_edits` | output_mismatch | 30/98 | 98/98 |
| `text_format_prototype_lazy` | output_mismatch | 32/35 | 35/35 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `file_reference_upload_request` | output_mismatch | 3/158 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `globals_monkeypatch` | output_mismatch | 44/306 | 49/306 | -5 |
| `global_proto_decls` | output_mismatch | 50/4562 | 50/4562 | 0 |
| `global_instance_decls` | output_mismatch | 20/758 | 17/758 | +3 |
