# Mouse Events Implementation Plan
<!-- TESTS: mouse_pos, mouse_pos_with_scale_factor, mouse_events, mouse_events_visible_enabled, click_block -->

Last updated: 2026-02-25

## Status: COMPLETE — All 5 tests passing

All 5 tests pass:
- `mouse_pos` (666/666)
- `mouse_pos_with_scale_factor` (261/261)
- `mouse_events` (8/8) — was already passing at baseline
- `mouse_events_visible_enabled` (12/12)
- `click_block` (5/5)

### Commits
1. `20430e6a` — Fix _xmouse/_ymouse: Ruffle-compatible matrix composition and precision
2. `087db3e4` — Fix click_block: compute MC bounds from sprite display list children
3. `f7b40cc1` — Fix button _visible/_enabled gating and add middle mouse button support

### Key implementation details

**Phase A (_xmouse/_ymouse):** Rewrote `mc_get_local_mouse` in action.c to match Ruffle's
`local_mouse_position` algorithm: compose world matrix with `scale(pixel_ratio/20)`, invert,
apply to global device pixels. Changed output to double precision. Added pixel_ratio support
for scale_factor tests. Fixed frame loop off-by-one that broke before final enterFrame.

**Phase B (mouse_events):** Already passing — existing clip event dispatch and Mouse listener
broadcast infrastructure was sufficient.

**Phase C (_visible/_enabled):** Added `actionGetMCVisible`/`actionGetMCEnabled` helpers.
Modified `ng_update_button_states` in tag.c to check visibility (invisible → skip hit test,
allow rollOut/releaseOutside) and enabled (Ruffle-compatible: freeze state when mouse-over,
force to Idle when mouse-away; skip all actions). Added per-tick button state re-evaluation
in swf_core.c frame loop. Added middle mouse button support (VK_MBUTTON = key code 4).

**Phase D (click_block):** Enhanced `mc_get_pixel_aabb_ng` with NO_GRAPHICS fallback to
compute bounds from sprite display list children's character bounds via `ng_getCharBounds`.
