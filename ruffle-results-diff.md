# Ruffle Test Results Diff

**Previous:** `a50d38f8e84b` (2026-03-04T21:19:14.827281+00:00)
**Current:** `24f215aaddfb` (2026-03-05T02:15:40.350484+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 445 | 452 | +7 |
| Total | 619 | 619 | 0 |
| Pass rate | 71.9% | 73.0% | +1.1% |
| Mismatched lines | 21694 | 21665 | -29 |
|   Decreased | | | -305 |
|   Increased | | | +276 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as_broadcaster` | output_mismatch | 7/41 | 41/41 |
| `as_broadcaster_undef` | output_mismatch | 35/89 | 89/89 |
| `edittext_stylesheet` | output_mismatch | 301/325 | 325/325 |
| `function_as_function` | output_mismatch | 13/35 | 35/35 |
| `issue_3169` | output_mismatch | 0/2 | 2/2 |
| `printjob_props_swf5` | output_mismatch | 40/45 | 45/45 |
| `printjob_props_swf6` | output_mismatch | 40/45 | 45/45 |
| `printjob_props_swf7` | output_mismatch | 40/45 | 45/45 |
| `textsnapshot_available_text` | output_mismatch | 10/20 | 20/20 |
| `textsnapshot_findtext` | output_mismatch | 5/44 | 44/44 |
| `textsnapshot_gettext` | output_mismatch | 4/55 | 55/55 |
| `textsnapshot_text_order` | output_mismatch | 0/1 | 1/1 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `edittext_html_entity` | output_mismatch | 4/4 | 3/4 |
| `remove_movie_clip` | output_mismatch | 29/29 | 27/29 |
| `stylesheet` | output_mismatch | 283/283 | 34/283 |
| `textsnapshot_props_swf5` | output_mismatch | 56/56 | 44/56 |
| `textsnapshot_props_swf6` | output_mismatch | 56/56 | 44/56 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `funky_function_calls` | segfault | output_mismatch | 9/56 | 52/56 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `coerce_to_object_monkeypatch` | output_mismatch | 7/129 | 16/129 | -9 |
| `define_local_with_paths` | output_mismatch | 21/54 | 22/54 | -1 |
