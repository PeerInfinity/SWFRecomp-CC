# Ruffle Test Results Diff

**Previous:** `08709f65842a` (2026-11-21T17:00:08.495417+00:00)
**Current:** `bc91565cea8e` (2026-11-21T19:30:16.389765+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1240 | 1198 | -42 |
| Total | 1334 | 1289 | -45 |
| Pass rate | 93.0% | 92.9% | -0.1% |
| Mismatched lines | 5920 | 5876 | -44 |
|   Decreased | | | -5 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `selection_onsetfocus_mixed_avm` | output_mismatch | 0/5 | 5/5 |

## Missing Tests — Shard Failure (45)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 43 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
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
| `filereference_browse_select` | output_mismatch | 7/9 |
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
| `focus_events_mixed_avm_edittext` | output_mismatch | 12/49 |
| `focus_events_mixed_key_mouse` | pass | 100/100 |
| `focus_events_mouse_basic` | pass | 260/260 |
| `focus_events_mouse_focusable` | pass | 112/112 |
| `focus_events_mouse_same_object` | pass | 40/40 |
| `focus_remove` | pass | 20/20 |
| `focus_root_movie` | pass | 4/4 |
| `focus_stage` | pass | 1/1 |
| `focusrect` | pass | 18/18 |

</details>
