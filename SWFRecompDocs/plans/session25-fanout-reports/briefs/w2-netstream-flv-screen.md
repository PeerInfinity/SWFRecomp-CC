**`avm1/netstream_play_flv_screen` renders blank (possible +1; an RVF entry is REFUTED).** From `w1-pixel-blend-mask` §4 + lead L1 (report on master).

Our render is now blank, not the 160×120 overflow that the `RUFFLE_VS_FLASH_DIFFERENCES` "Video Display Object Render Bounds: netstream_play_flv_screen Asset Stamp" entry describes. Ruffle uses the same declared-bounds rule and passes at tol 1 on a lossless codec, so a correct path should be exact. The attached VideoPlayer subtree is never walked. Candidates:
- (a) FLVPlayback keeps the player `_visible = false` until a NetStream ready/metadata event that our AVM1 NetStream never delivers to the component;
- (b) attached clips under a nested timeline sprite are not walked in `OFFSCREEN_RENDER` (the interleave block in `render_display_list` is `#ifndef OFFSCREEN_RENDER`).
Diagnose with trace instrumentation (the component's `_visible`/`_width`/`_height` per frame, NetStream status events), fix the root cause, and size the Video to the 128×128 the golden shows.

Then: remove the stale RVF entry and the `ignored_tests.txt` line (or rewrite them with the true mechanism if a residual remains). Sweep every AVM1 NetStream/Video row (trace + image), `regression/avm1_*video*`/`*netstream*`, and attached-clip rows (`regression/avm1_attached_clip_*`). If you touch `render_display_list`'s OFFSCREEN_RENDER arm, run the full render canary. No-graphics parity if you touch NetStream event code shared with `swf_core.c`.

`n-play-game` (local) owns AVM1 button/mouse dispatch, so stay out of it. The s24 AVM2 NetStream state machine (`ba7cb4d63`) is AVM2-only.
