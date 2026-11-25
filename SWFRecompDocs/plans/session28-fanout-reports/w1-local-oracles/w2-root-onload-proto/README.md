# w2-root-onload-proto Flash variant captures (s28 coordinator, 2026-11-25; FP32 LNX, direct `--no-pin`)

| variant | result |
|---|---|
| v4 `this` probe | the `_global` call's `this`: **`typeof this = movieclip`**, `== _global` false, `== _level0` false, `_name/_target/_parent/_url` all `undefined`, `__proto__ == MovieClip.prototype` true. A hidden MovieClip-like receiver (ours models it as the string `"_global"`: typeof differs → follow-up). The second call is `_level0` (`_target = /`, `_name` empty) |
| v1 own + proto | `proto onLoad _global` then `own onLoad _level0` (the hidden receiver fires even when the root has an own handler) |
| v3 `_global.onLoad` only | nothing |
| v2 proto defined in f2 | see `v2_proto_in_f2.flash32.nopin.txt` |
| v5 SWF 6 | same 7 lines as SWF 8 (no version gate) |
| v6 DefineFunction2 | same 7 lines |
