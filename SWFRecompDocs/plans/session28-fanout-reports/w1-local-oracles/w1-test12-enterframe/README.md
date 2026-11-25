# w1-test12-enterframe local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX, direct pinned)

| request | file | result |
|---|---|---|
| 1 `avm1_enterframe_removed_same_tick` (SWF 8), 8 frames | `…same_tick.flash32.txt` | ≠ both prototype legs (9 diff lines each). Notable: Flash orders `c clipEvent(enterFrame)` AFTER the `t`/`n` method handlers on rf=3/4; `frame 4 typeof(a.k)=movieclip` (k still alive in frame 4 although `k unload` fired); rf=5 fires `s`, `b cf=2`, `a` only |
| 2 same at SWF 7 | `…same_tick_swf7.flash32.txt` | == #1 byte for byte: **no SWF-version gate** |
| 3a corpus `avm1/clip_events` | `clip_events.flash32.txt` | == golden |
| 3b corpus `avm1/movieclip_in_removed_button` | `movieclip_in_removed_button.flash32.txt` | golden is an exact prefix (direct mode overruns `num_ticks = 4`) — golden = Flash |

So the brief's case (a) holds: both Ruffle goldens are Flash. The discriminator is not the SWF version; fit it from #1.
