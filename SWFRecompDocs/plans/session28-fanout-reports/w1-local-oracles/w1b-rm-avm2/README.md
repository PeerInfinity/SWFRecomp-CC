# w1b-rm-avm2 local Flash oracles (s28 coordinator, 2026-11-25)

`array_sort_swf10_32bit.flash32.txt`: FP32 (a 64-bit player) on the 32bit dir == the `_64bit` golden byte for byte (the SWFs are identical). Coordinator decision: **platform split (32- vs 64-bit Flash), not a flash_fix** (README rule 4); `sort64.patch` NOT landed; `array_sort_swf10_64bit` stays rm with a platform-split disposition.
