# 2026-05-25 — Doodle Jump browser-WASM follow-up

Continues `2026-05-25-doodle-jump-browser-investigation.md`. The
hero/block sprite-cycling bug from that handoff is now fixed; the
button-label issue remains open and is the natural next thing to chase
if the user wants the demo perfect.

## What landed (commit `98b388e46`)

**`browser-WASM: stop/play inside sprite frame routes to the sprite`** —
three coupled changes:

1. `graphics_stubs.c` `exec_sprite_frame`: the bare-call stub now sets
   `g_current_sprite_obj` for the duration of the call, so
   `ng_isInsideSprite()` returns true while a sprite's frame_func or
   its queued sprite scripts run.

2. `action_queue.c` `aq_dispatch_sprite_script`: restore
   `g_current_sprite_obj` unconditionally from the captured payload,
   not only when `ctx_mc` was non-NULL. In browser-WASM,
   `exec_sprite_frame` doesn't swap `g_current_context`, so `ctx_mc`
   captured at queue time is NULL, but `ctx_sprite_obj` was captured
   correctly — gating the sprite-obj restore on `ctx_mc` was
   discarding it.

3. `action.c` `actionStop` / `actionPlay`: dropped the
   `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` gate around
   the modern arm so the `ng_isInsideSprite()` → `ng_stopCurrentSprite()`
   route applies in browser-WASM too.

## Verification

- Doodle Jump browser demo: 8 1-second canvas snapshots (`t02..t08`) are
  byte-identical (md5 `b408253b3dc89ca0f2ac3a6aa2a43ecf`). Hero in
  standing pose, block in broken pose. **Pre-fix was 4 cycling visual
  states.**
- Trace divergence harness (graphics-native): 407=407, identical.
  ```
  python3 tools/divergence/divergence_test.py \
    SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf \
    --frames 30 --skip-ruffle
  ```
- Pong browser demo: stable (unique_canvas_sizes=1).
- Snake browser demo: stable (t02..t05 byte-identical).

## What's still broken: button labels

In the deployed Doodle Jump demo the four buttons still display the
static `"menu"` text rather than the script-set `"play"` / `"info"` /
`"scores"` / `"options"`. Confirmed by visual inspection of
`/tmp/dj-probe-final/canvas/t05.png`.

### Root cause

The button text is set by `CLIP_EVENT_LOAD` clip-action handlers
attached at placement time:

```
tagPlaceObject2WithClipActions(app_context, 3, 46, 47, 32, 0, clip_actions_145, 2, 0);
   clip_actions_145 = { {0x1, clip_action_17}, {0x800, clip_action_18} }

clip_action_17:
   _root.button_txt.text = "scores"
```

In browser-WASM, those LOAD handlers **never fire**. The dispatching
path lives entirely inside
`#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`:

- `tag.c:5614-5619` (inside the gate at 5608): consumption of
  `g_pending_clip_actions` into `display_list[depth].clip_actions` —
  in browser-WASM, the clip_actions array is never even attached to
  the DisplayObject. Set by `tagPlaceObject2WithClipActions`, dropped
  on the floor by gated `tagPlaceObject2`.
- `tag.c:5639`: `queue_clip_load_events(app_context, depth)` —
  not called.
- `tag.c:4900-4965`: `queue_clip_load_events` + its dispatcher
  `aq_dispatch_clip_load` — gated inside `#if NO_GRAPHICS || OFFSCREEN_RENDER`
  at 4672-5004, so the symbols aren't even compiled for browser-WASM.

This is **the 5th instance today** of the same pattern (render/AS
support gated `NO_GRAPHICS || OFFSCREEN_RENDER`, browser-WASM the
afterthought). The original handoff predicted the buttons "might
require the same sprite display-list mechanism that's broken" — that
guess was directionally right but a different mechanism (clip-events,
not sprite frame scripts).

### Suggested fix scope

Two options:

**A. Surgical widening.** Move just the two things needed
(`g_pending_clip_actions` consumption + `queue_clip_load_events`
invocation) outside the gate at `tag.c:5608`, and widen the
definitions of `queue_clip_load_events` / `aq_dispatch_clip_load` (and
the `PendingClipLoad` struct they share) to compile in browser-WASM.

The dependencies are all browser-WASM-safe:
- `actionQueueCallbackEx` (action_queue.c, unguarded)
- `actionFindOrCreateMovieClip` (action.c:21636, unguarded)
- `root_movieclip`, `g_current_context`, `actionSetCurrentContext` —
  all available
- `actionDrainAllInPriorityOrder` is already called from the
  recompiler-emitted `tagMain.c` regardless of build mode, so the
  queued entries would drain.

Risk: any other code that touches `display_list[depth].clip_actions`
in browser-WASM might encounter an unexpectedly-populated array.
Worth grepping before pulling the trigger.

**B. Systematic audit (per original handoff's recommendation).** Audit
every `#if defined(HEADLESS_GRAPHICS) || defined(OFFSCREEN_RENDER)`
and `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` site in
`tag.c` / `action.c` for "browser-WASM was the afterthought" gaps.
The handoff explicitly called this out at the 4th-instance threshold,
and we're now at 5.

A reasonable middle path: do (A) for the buttons (small, well-scoped),
then start (B) only if more bugs surface.

## Tools / state

Branch `master` is now `1 commit ahead of origin/master`:
- `98b388e46 browser-WASM: stop/play inside sprite frame routes to the sprite`

Working tree clean. Push when ready.

Latest known-good probe output:
```
out: /tmp/dj-probe-final
md5 b408253b3dc89ca0f2ac3a6aa2a43ecf  t02..t08.png   (all 7 identical)
```

Pong: `/tmp/pong-probe-fix`. Snake: `/tmp/snake-probe-fix`.
