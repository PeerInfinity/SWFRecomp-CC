# Minesweeper — number markers collapse + clicks after a mine + a pre-existing large-reveal crash

**Date:** 2026-06-22
**Game:** flasharchive/Minesweeper, browser-WASM graphics (graphics-mode shared code).

Follow-up to the same session's board-render / click / Splash fixes. User-reported
after the board became playable.

## #5 — only one number marker ("1"/"2"/"3") shows; revealing a new one moves it
The digit tiles (chid 93–100) are static **DefineText**, while the "Unknown"/"Empty"
tiles are DefineShape. `compose_children`'s `CHAR_TYPE_TEXT` branch wrote each
composed glyph transform into `glyph_xform_id = ch->transform_start + j` — a slot
keyed by the **character**, shared across every instance. The renderer batches
draws into a GPU transform buffer indexed by that slot, so all 480 cells showing
the same digit referenced the same slots and the GPU drew every one at the last
writer's position (one digit, "moving" to the last-revealed tile). Shapes avoid
this because they draw with the per-instance `obj->transform_id`.

**Fix** (`tag.c` + `swf.h`): allocate a per-INSTANCE run of `ch->text_size` dynamic
transform slots during compose (mirrors the shape path's dynamic-slot alloc),
record the base in a new `DisplayObject::text_glyph_xform_base`, and have
`render_single_object` / `render_display_list` draw the glyphs from that base.
A `text_glyph_overrides` save/restore stack clears the base each frame (the dynamic
pool resets per frame). Single-instance text is byte-identical (one writer → same
result, different slot). User-verified: numbers now display correctly.

## #6 — tiles still clickable after hitting a mine
On a mine, `openField` sets `_root.sensor._visible = false`, but the board
`sensor`'s `on(press)`/`on(release)` clip actions still fired. `dispatch_clip_event_press_dl`
(`tag.c`) didn't skip hidden entries. Added `if (obj->as_hidden) continue;` —
invisible clips (and their subtree) get no mouse events, matching Flash. Release
only fires for pressed entries, so guarding press is sufficient. User-verified.

## Defensive hardening — `mc_get_pixel_aabb_ng` (`action.c`)
Only walk a clip's sprite display list when its metadata is self-consistent
(`sprite_dl_capacity` in (0, 65536], scan clamped to capacity). Byte-identical for
valid clips; guards against an attached/cloned clip whose standalone `display_obj`
is stale/garbage. See the crash note below.

## Known pre-existing crash — large-area reveal (NOT this change)
Revealing a large empty region can segfault ("memory access out of bounds") in the
hit-AABB path (`mc_get_pixel_aabb_ng`), which is called for many clips at once.
**Confirmed pre-existing**: a build from before the #5/#6 changes crashes on large
reveals too; disabling #5/#6 still crashes. It became reachable only once the board
was made playable this session. SAFE_HEAP localizes it to an intermittent
stale-`display_obj` read on a FUIComponent child / cell. The hardening above did
not resolve the root cause. **The user cannot reproduce it on real Windows/GPU** —
it appears largely a WSL2/SwiftShader heap-layout artifact (the software renderer's
heap makes the latent read fault; real-GPU heap layout tolerates it). Left as a
documented follow-up for a dedicated session (a symbolized SAFE_HEAP build traps it
precisely at the faulting access).

## CI
Text compose/draw run in OFFSCREEN (graphics) + browser-WASM (NOT NO_GRAPHICS).
Shared `action.c` hardening + `tag.c` press-dispatch guard → dispatch both modes.
