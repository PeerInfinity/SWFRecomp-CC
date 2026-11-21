# Ruffle Test Results Diff

**Previous:** `bc91565cea8e` (2026-11-21T19:30:16.389765+00:00)
**Current:** `c489b84d9946` (2026-11-21T19:49:24.020243+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1198 | 1253 | +55 |
| Total | 1289 | 1335 | +46 |
| Pass rate | 92.9% | 93.9% | +1.0% |
| Mismatched lines | 5876 | 5744 | -132 |
|   Decreased | | | -132 |

## Newly Passing (9)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmapdata_encode_jpeg_visual` | output_mismatch | 0/0 | 0/0 |
| `bitmapdata_encode_png_roundtrip` | output_mismatch | 1/33 | 33/33 |
| `bitmapdata_encode_png_visual` | output_mismatch | 0/0 | 0/0 |
| `dictionary_qname_keys` | output_mismatch | 29/45 | 45/45 |
| `edittext_event_link_case_insensitive` | output_mismatch | 0/1 | 1/1 |
| `perspective_projection_center` | output_mismatch | 6/34 | 34/34 |
| `textfield_default_text_format_null` | output_mismatch | 7/20 | 20/20 |
| `xml_many_namespace_declarations` | output_mismatch | 1/2 | 2/2 |
| `xml_unescaping_nul_char_ref` | output_mismatch | 4/19 | 19/19 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `event_handler_exception` | output_mismatch | ruffle_matched | 7/11 | 8/11 |

## Added Tests (46)

| Test | Status | Lines |
|------|--------|-------|
| `allow_networking` | pass | 72/72 |
| `eventdispatcher_dispatchevent_indirect` | pass | 9/9 |
| `eventdispatcher_dispatchevent_this` | pass | 5/5 |
| `eventdispatcher_haseventlistener` | pass | 25/25 |
| `eventdispatcher_interface_invoke` | pass | 1/1 |
| `eventdispatcher_tostring` | pass | 10/10 |
| `eventdispatcher_willtrigger` | pass | 25/25 |
| `external_interface` | pass | 105/105 |
| `falsiness` | pass | 30/30 |
| `fast_index_access` | pass | 12/12 |
| `filefilter_properties` | pass | 4/4 |
| `filereference_browse_cancel` | pass | 3/3 |
| `filereference_browse_select` | pass | 9/9 |
| `filereference_load` | pass | 31/31 |
| `filereference_save` | pass | 16/16 |
| `filereference_save_and_browse` | pass | 42/42 |
| `filereference_save_and_load` | pass | 22/22 |
| `filereference_uninitialized` | pass | 8/8 |
| `filereferencelist_browse_cancel` | pass | 6/6 |
| `filereferencelist_browse_select` | pass | 7/7 |
| `filter_rewind` | pass | 8/8 |
| `filters_array_holes` | pass | 25/25 |
| `finddef` | pass | 3/3 |
| `findprop_global_prototype` | pass | 6/6 |
| `flash_media_video_constructor` | pass | 156/156 |
| `flash_media_video_rotation_probe` | pass | 27/27 |
| `flash_media_video_setter` | pass | 40/40 |
| `flash_trace` | pass | 17/17 |
| `flash_ui_mouse_cursor` | pass | 35/35 |
| `flash_xml` | pass | 29/29 |
| `flash_xml_cloneNode` | pass | 22/22 |
| `flash_xml_namespace` | pass | 109/109 |
| `flash_xml_removeNode` | pass | 60/60 |
| `focus_events_code` | pass | 161/161 |
| `focus_events_key_basic` | pass | 132/132 |
| `focus_events_key_navigation` | pass | 53/53 |
| `focus_events_key_same_object` | pass | 26/26 |
| `focus_events_mixed_avm_edittext` | pass | 49/49 |
| `focus_events_mixed_key_mouse` | pass | 100/100 |
| `focus_events_mouse_basic` | pass | 260/260 |
| `focus_events_mouse_focusable` | pass | 112/112 |
| `focus_events_mouse_same_object` | pass | 40/40 |
| `focus_remove` | pass | 20/20 |
| `focus_root_movie` | pass | 4/4 |
| `focus_stage` | pass | 1/1 |
| `focusrect` | pass | 18/18 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bitmapdata_encode` | output_mismatch | 1/147 | 26/147 | -25 |
| `audio_computespectrum` | output_mismatch | 0/118 | 0/118 | 0 |
