# Ruffle Test Results Diff

**Previous:** `69193be1fbe0` (2026-03-08T20:20:23.214681+00:00)
**Current:** `d24c9463a80a` (2026-03-09T01:52:43.540546+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 503 | 503 | 0 |
| Total | 620 | 618 | -2 |
| Pass rate | 81.1% | 81.4% | +0.3% |
| Mismatched lines | 19453 | 19509 | +56 |
|   Decreased | | | -17 |
|   Increased | | | +79 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `define_local_with_paths` | output_mismatch | 53/54 | 54/54 |
| `interface_implements_op` | output_mismatch | 46/47 | 47/47 |
| `movieclip_getbounds` | output_mismatch | 189/191 | 191/191 |
| `text_format_get_text_extent_undefined_width` | output_mismatch | 8/10 | 10/10 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `textsnapshot_available_text` | output_mismatch | 20/20 | 10/20 |
| `textsnapshot_findtext` | output_mismatch | 44/44 | 26/44 |
| `textsnapshot_gettext` | output_mismatch | 55/55 | 5/55 |
| `textsnapshot_text_order` | output_mismatch | 1/1 | 0/1 |

## Removed Tests (2)

| Test | Previous Status | Lines |
|------|----------------|-------|
| `loading_avm2` | output_mismatch | 3/7 |
| `mixed_avm_load_into_root` | output_mismatch | 0/2 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_instance_decls` | output_mismatch | 1/758 | 12/758 | -11 |
