# Ruffle Test Results Diff

**Previous:** `c489b84d9946` (2026-11-21T19:32:37.101881+00:00)
**Current:** `9a970370e096` (2026-11-21T20:48:06.931966+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 727 | 734 | +7 |
| Total | 777 | 777 | 0 |
| Pass rate | 93.6% | 94.5% | +0.9% |
| Mismatched lines | 12718 | 12634 | -84 |
|   Decreased | | | -84 |

## Newly Passing (7)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_asfunction_case_insensitive` | output_mismatch | 0/1 | 1/1 |
| `file_reference_listeners_per_instance` | output_mismatch | 2/20 | 20/20 |
| `localconnection_reference_identity` | output_mismatch | 2/5 | 5/5 |
| `localconnection_serialize_inherited_array_indices` | output_mismatch | 10/12 | 12/12 |
| `shared_object_members_swf5` | output_mismatch | 25/32 | 32/32 |
| `video_width_height` | output_mismatch | 3/19 | 19/19 |
| `xml_status_mismatched_tags` | output_mismatch | 40/63 | 63/63 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `video_prototype_lazy` | output_mismatch | 9/21 | 20/21 | -11 |
| `video_prototype_lazy_swf6_child` | output_mismatch | 2/8 | 4/8 | -2 |
| `globals_monkeypatch` | output_mismatch | 43/306 | 44/306 | -1 |
