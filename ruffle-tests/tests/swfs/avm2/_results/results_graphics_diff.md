# Ruffle Test Results Diff

**Previous:** `bc91565cea8e` (2026-11-21T18:24:43.162682+00:00)
**Current:** `c489b84d9946` (2026-11-21T19:32:37.118123+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1242 | 1253 | +11 |
| Total | 1334 | 1335 | +1 |
| Pass rate | 93.1% | 93.9% | +0.8% |
| Mismatched lines | 5878 | 5744 | -134 |
|   Decreased | | | -134 |

## Newly Passing (10)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmapdata_encode_jpeg_visual` | output_mismatch | 0/0 | 0/0 |
| `bitmapdata_encode_png_roundtrip` | output_mismatch | 1/33 | 33/33 |
| `bitmapdata_encode_png_visual` | output_mismatch | 0/0 | 0/0 |
| `dictionary_qname_keys` | output_mismatch | 29/45 | 45/45 |
| `edittext_event_link_case_insensitive` | output_mismatch | 0/1 | 1/1 |
| `filereference_browse_select` | output_mismatch | 7/9 | 9/9 |
| `perspective_projection_center` | output_mismatch | 6/34 | 34/34 |
| `textfield_default_text_format_null` | output_mismatch | 7/20 | 20/20 |
| `xml_many_namespace_declarations` | output_mismatch | 1/2 | 2/2 |
| `xml_unescaping_nul_char_ref` | output_mismatch | 4/19 | 19/19 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `event_handler_exception` | output_mismatch | ruffle_matched | 7/11 | 8/11 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `allow_networking` | pass | 72/72 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bitmapdata_encode` | output_mismatch | 1/147 | 26/147 | -25 |
| `audio_computespectrum` | output_mismatch | 0/118 | 0/118 | 0 |
