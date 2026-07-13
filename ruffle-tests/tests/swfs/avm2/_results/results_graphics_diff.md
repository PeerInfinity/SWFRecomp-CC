# Ruffle Test Results Diff

**Previous:** `bf93755e0cc9` (2026-07-13T01:11:36.270761+00:00)
**Current:** `8c4e8518e97f` (2026-07-13T02:38:03.411589+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 801 | 819 | +18 |
| Total | 1204 | 1204 | 0 |
| Pass rate | 66.5% | 68.0% | +1.5% |
| Mismatched lines | 51963 | 47838 | -4125 |
|   Decreased | | | -4125 |

## Newly Passing (18)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `agal_compiler` | output_mismatch | 1/13 | 13/13 |
| `get_timer` | output_mismatch | 0/2 | 2/2 |
| `movieclip_soundtransform` | output_mismatch | 3/831 | 831/831 |
| `shared_object_no_root` | output_mismatch | 0/3 | 3/3 |
| `sound_embeddedprops` | output_mismatch | 0/26 | 26/26 |
| `sound_play` | output_mismatch | 0/19 | 19/19 |
| `sound_valueof` | output_mismatch | 0/33 | 33/33 |
| `soundchannel_soundtransform` | output_mismatch | 0/835 | 835/835 |
| `soundchannel_soundtransform_exists` | output_mismatch | 0/5 | 5/5 |
| `soundchannel_stop` | output_mismatch | 0/8 | 8/8 |
| `soundmixer_buffertime` | output_mismatch | 0/5 | 5/5 |
| `soundmixer_stopall` | output_mismatch | 0/6 | 6/6 |
| `soundtransform` | output_mismatch | 1/442 | 442/442 |
| `timer` | output_mismatch | 0/90 | 90/90 |
| `timer_events` | output_mismatch | 0/3 | 3/3 |
| `timer_finished` | output_mismatch | 0/11 | 11/11 |
| `timer_reset` | output_mismatch | 1/8 | 8/8 |
| `timer_setdelay` | output_mismatch | 1/5 | 5/5 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `soundchannel_position` | output_mismatch | ruffle_matched | 0/140 | 66/140 |
| `soundchannel_soundcomplete` | output_mismatch | ruffle_matched | 0/16 | 6/16 |

## Line Count Changed (10)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `soundmixer_soundtransform` | output_mismatch | 3/900 | 888/900 | -885 |
| `simplebutton_soundtransform` | output_mismatch | 5/887 | 829/887 | -824 |
| `displayobject_scrollrect` | output_mismatch | 11/33 | 14/33 | -3 |
| `filter_rewind` | output_mismatch | 0/8 | 2/8 | -2 |
| `displayobject_early_init` | output_mismatch | 0/54 | 1/54 | -1 |
| `all_classes/events/swf10` | output_mismatch | 1/1638 | 1/1638 | 0 |
| `all_classes/events/swf11` | output_mismatch | 1/1750 | 1/1750 | 0 |
| `all_classes/events/swf12` | output_mismatch | 1/1814 | 1/1814 | 0 |
| `all_classes/events/swf30` | output_mismatch | 0/2353 | 0/2353 | 0 |
| `all_classes/events/swf9` | output_mismatch | 2/1030 | 2/1030 | 0 |
