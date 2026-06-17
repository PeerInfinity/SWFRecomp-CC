# Minesweeper browser-WASM radios — registered-class constructors now fire — FIXED

**Date:** 2026-06-16 (cont. 39, follow-up to cont. 38/38b radio fixes)
**Game:** flasharchive/Minesweeper (browser-WASM graphics only)
**Bucket:** needs-browser (browser-WASM-only; invisible to the divergence
harness and CI — validated by the deployed demo + manual browser test).

## Symptom

On Minesweeper's difficulty screen the three `FUIComponent` radio buttons
rendered as mis-positioned white-bordered boxes instead of "○ Easy (40 mines)" /
"◉ Medium (70 mines)" / "○ Tough (100 mines)". The radio circle/dot and the
label text did not draw. (OFFSCREEN / headless rendered the whole screen
correctly; browser-WASM only.)

## Root cause — NOT the handoff's premise (re-confirmed with fresh instrumentation)

The prior handoff ([[browser-wasm-visible-and-nonroot-attach-render]] §2)
attributed this to a missing render pass for attachMovie children of a non-root
sprite. That premise was **stale**: the non-root-attach render pass already
landed (`7a27b0edd`, refined `0ca6e0abd`) — `render_attached_child` /the
interleave pass in `tagShowFrame` correctly draw `child_mc_cache` clips parented
to a non-root timeline sprite.

Instrumenting the deployed demo showed the real cause: **`attachMovie` was never
called at all** for the radio internals (`frb_states_mc`, `fLabel_mc`,
`frb_hitArea_mc`). Those clips are built by `FRadioButtonClass`'s registered-class
constructor → `this.init()` → `attachMovie(...)`. Browser-WASM's
`exec_sprite_frame` (`graphics_stubs.c`) does **not** run
`process_sprite_needs_init` (the function that fires the registered-class
constructor for a timeline-placed sprite is gated to
`NO_GRAPHICS || OFFSCREEN_RENDER` in `tag.c`). So in browser-WASM the constructor
never ran, `init()` never ran, and the circle/dot/label were never *created*
(not "not rendered"). The white boxes were the `boundingBox_mc` / `deadPreview`
clips placed on the radio's own DefineSprite timeline.

Enabling the constructor then exposed a **second, latent memory-safety bug** in
`ng_attachMovie`: for a non-root attach it registers the child in the parent MC's
`sprite_display_list` at `target_d = swf_depth = as_depth + 16384` (e.g. 16386
for a clip at AS depth 2). That forces a grow of the parent's buffer to ~16400
entries and `FREE`s the old one — but a timeline-placed parent's MC `display_obj`
shares that buffer pointer with its **root display_list registration entry** (a
distinct `DisplayObject` struct). The free left the root entry dangling;
`finalize_pending_removes_recursive` (and the render recursion) then walked the
freed buffer → `Aborted(segmentation fault)` / "memory access out of bounds".
(SAFE_HEAP + `-g2` debug build pinned the crash to
`finalize_pending_removes_recursive`; the float bit-pattern `0x3F800000` = `1.0f`
appearing as a `char_id` confirmed a reused/freed buffer.)

## Fixes (both browser-WASM-only — CI modes byte-identical)

1. **`graphics_stubs.c` `exec_sprite_frame`:** after the sprite's frame script
   runs, if a class is registered for this character (`lookupRegisteredClassByCharId`,
   side-effect-free gate) and `obj->constructor_invoked == 0`, resolve the
   sprite's MC (the `did_swap` MC, or find-or-create by name+context for
   clip-action sprites whose MC the LOAD path makes) and call
   `actionInvokeRegisteredClassConstructor` once. Mirrors
   `process_sprite_needs_init`'s post-frame-0 dispatch. The registered-class gate
   keeps ordinary exported clip-action sprites untouched (no shadow-MC).

2. **`tag_stubs.c` `ng_attachMovie`:** gate the "register the child in the
   parent's `sprite_display_list`" block to
   `NO_GRAPHICS || OFFSCREEN_RENDER || HEADLESS_GRAPHICS`. Browser-WASM skips it
   (exactly as root attaches already do): the child reaches the renderer via the
   `child_mc_cache` pass and is resolvable via `child_mc_cache` /
   `parent->dynamic_props`, so the registration is rendering-inert there — and it
   was the sole source of the UAF (the buffer free). CI modes keep the
   registration unchanged.

## Verification

- **Minesweeper (deployed demo):** constructors fire for all three radios →
  `frb_states_mc` / `fLabel_mc` / `frb_hitArea_mc` attach; no more
  "Error during rendering" crash. (Final radio visual — circle/dot/label
  placement — needs the human's real-browser eyeball: automated headed Chrome
  throttles rAF and the smoke screenshot shows a mid-init frame. Guide gotcha #8.)
- **Regression smokes (browser-WASM, no crash, correct render):** Tetris title,
  Doodle Jump menu, Snake menu, Pong menu — all clean.
- **OFFSCREEN no-regression gate:** `divergence_test.py Minesweeper --frames 16
  --skip-ruffle` trace is healthy (634 lines, real radio output, clean shutdown,
  no abort). My changes don't touch OFFSCREEN-compiled code by construction
  (`exec_sprite_frame` is `!OFFSCREEN`-gated; the `ng_attachMovie` block is
  unchanged for OFFSCREEN), so OFFSCREEN is byte-identical.

Not CI-dispatched: browser-WASM-only behavior, not CI-observable
([[ci-only-when-observable]]).

## Continuation (cont. 40, 2026-06-16) — child resolution + opaque rectangles FIXED

Re-confirmed gap #1's root cause with fresh instrumentation (and it was, again,
not quite the handoff's premise): `actionGetMember`'s child-resolution logic was
fine — the **data it read was empty**. At constructor time the radio sprite's
`sprite_display_list` was allocated but `sprite_max_depth == 0`, so the scan for
`boundingBox_mc` (cid 34) found nothing → undefined.

**Why `smd==0` at ctor time (browser-WASM only):** a timeline-placed sprite's
frame-0 placement tags run via `exec_sprite_frame` (caller =
`advance_sprite_frames` / the goto-replay paths in `tag.c`). Those callers swap
the GLOBAL `display_list`/`max_depth` to the sprite's list before the call and
only write `obj->sprite_max_depth` back AFTER `exec_sprite_frame` returns
(tag.c:1190 etc.). The constructor fires INSIDE `exec_sprite_frame` (right after
the frame func), so `obj->sprite_max_depth` is still the stale pre-frame value
(0 on first run) while the children actually live in the global `display_list`.
(The eager-init path in `tagPlaceObject2` that would otherwise populate this
earlier is gated to NO_GRAPHICS/OFFSCREEN — its browser-WASM `#else` is a no-op.)

**Fix 1 (`graphics_stubs.c` `exec_sprite_frame`, browser-WASM-only):** right
before firing the registered-class constructor, sync
`obj->sprite_display_list`/`sprite_max_depth`/`sprite_dl_capacity` from the
globals (which the caller already swapped to this sprite's populated list). Now
`this.boundingBox_mc` resolves to a MovieClip and `unloadMovie()` reaches its
handler. (Also repoints `obj->sprite_display_list` at the possibly-realloc'd
global buffer, avoiding a stale-pointer read.) Confirmed: `smd` 0 → 5,
`boundingBox_mc` (cid 34) found at d=1.

**Fix 2 (`action.c` `unloadMovie`, gated `!NO_GRAPHICS && !OFFSCREEN_RENDER`):**
firing `unloadMovie` exposed an ORDERING problem. In OFFSCREEN the nested clip's
frame-0 runs at placement (before the constructor), so unloadMovie's child-list
clear sticks. In browser-WASM that eager-init is gated out, so at unload time
`boundingBox_mc`'s own content isn't placed yet (`sdl==NULL/smd==0`) — the clear
is a no-op, and the deferred nested-sprite advance then runs the clip's frame-0
ONCE (`just_allocated` path, tag.c:1076), re-placing the shape. Fix: when (and
only when) the clip's content is still unplaced at unload, also zero the clip's
OWN display entry (`char_id=0`) so the deferred advance + renderer skip it —
making the empty state stick, matching Ruffle. Scoped to the unplaced case so a
normal unloadMovie on a populated clip keeps its entry (later loadMovie can
repopulate). **Result: the three opaque editor-bounding rectangles are GONE**
(confirmed in the deployed demo).

**Not CI-dispatched:** Fix 1 is in `exec_sprite_frame` (browser-WASM-only TU,
not compiled in CI). Fix 2 is entirely inside the `!NO_GRAPHICS &&
!OFFSCREEN_RENDER` gate → both CI modes are byte-identical (verified: OFFSCREEN
divergence trace unchanged at 634 lines, clean). Not CI-observable
([[ci-only-when-observable]]).

### cont. 40b — INITIALIZE clip event now runs → label TEXT renders

`render_attached_child` instrumentation confirmed the attached children DO reach
the renderer every frame, visible, at correct positions: `frb_states_mc`
(circle, `smd=9`) and `fLabel_mc` (label, `smd=1`, child = `labelField`
DefineEditText). So the gap was their CONTENT. The label text renders via the
GLOBAL `actionIterateTextFieldGlyphs` pass (child_mc_cache walk). `labelField`
WAS found there (is_tf=1, vis=1, tf_idx=0) but its `text` was just `' '`.

Root cause: the radio's label string is a **component parameter** the IDE emits
as a `{ 0x200, clip_action_24 }` handler — **0x200 = ClipEventInitialize** —
which does `label = " Easy (40 mines)"` (per radio). Per AVM1, Initialize runs
before Construct. But browser-WASM only dispatches `CLIP_EVENT_LOAD` (tag_stubs.c
pending-load queue) — Initialize never ran, so `this.label` was empty and
`FLabel.setLabel` wrote `this.labelField.text = label` = "".

**Fix 3 (`graphics_stubs.c` `exec_sprite_frame`, browser-WASM-only):** before
firing the registerClass constructor, run the sprite's INITIALIZE (0x200) clip
events (from `obj->clip_actions` + `accumulated_clip_actions`) in the clip's own
context. Once-only (constructor_invoked gate). Confirmed: labelField text now =
" Easy (40 mines)" / " Medium (70 mines)" / " Tough (100 mines)", and the labels
RENDER. (Not CI-observable; OFFSCREEN trace still 634 lines.)

### Still open after cont. 40b — label TEXT is width-CLIPPED (~2 chars)

The labels render but clip to ~18–20px ("Ea"/"M"/"To"). Traced precisely:
- `actionIterateTextFieldGlyphs` uses `info.w = mc->width` as the field layout
  width. labelField is created with the correct width (85px, from its
  DefineEditText bounds, via `findOrCreateMovieClip`'s nested-TF init), but
  `setSize` then overrides it: `FRadioButton.init()` calls
  `this.setSize(this._width, this._height)`, which cascades to
  `fLabel_mc.setWidth(...)` → `labelField._width = ~18.55` then `20`.
- Those tiny values come from **the radio's own `_width` reading ~18–20px** (just
  the circle) instead of ~120px. In Flash the component's width is defined by
  `boundingBox_mc` (the editor bounding rectangle, cid 32). But its shape isn't
  placed yet when `init()` reads `this._width`: boundingBox_mc is a nested 1-frame
  sprite whose own frame-0 runs in the DEFERRED nested-sprite advance (AFTER the
  constructor). So `this._width` excludes it. **Same nested-sprite-frame0-before-
  constructor ordering gap as cont.40, one level deeper** (radio bounds depend on
  boundingBox_mc's content, which isn't built until after construct).
- Proper fix is to eager-init the constructed sprite's nested timeline children
  (run their frame-0) BEFORE firing its registerClass constructor — mirroring
  OFFSCREEN's `process_sprite_needs_init` ordering — so `this._width` and any
  `this.<child>` access during `init()` see fully-built content. This is a
  broader/ordering change (touches the browser-WASM advance recursion) and is
  deferred to its own session; my cont.40/40b fixes are the contained foundation.
- Also still latent once width lands: `render_attached_child`'s
  `compose_children(..., 0, 0)` (no cxform) + cache-order (not depth-order)
  z-order; and the faint circle ring vs Ruffle.

## Remaining browser-WASM gaps (radios still not visually correct)

The user manual-tested after the fix above: the radios still don't show and the
"extra rectangles" (vs Ruffle) persist. Firing the constructor was necessary but
not sufficient — it exposed a cascade of further browser-WASM-only gaps in the
FUIComponent instance pipeline that had been fully masked while the constructor
never ran. Pinned with fresh browser instrumentation:

1. **`this.<timelineChild>` resolves to undefined in browser-WASM.**
   `FRadioButton.init()` runs `this.boundingBox_mc.unloadMovie()` (Ruffle empties
   the boundingBox so no rectangle shows). In browser-WASM the `unloadMovie`
   method handler is **never reached** — `actionCallMethod`'s MC-method chain is
   gated on `obj_var.type == ACTION_STACK_VALUE_MOVIECLIP`, and `this.boundingBox_mc`
   (a GetMember for a timeline-placed child of the component MC) resolves to a
   non-MOVIECLIP (undefined). So `boundingBox_mc` is never emptied → its
   `boundingBox` shape (charid 32, `_alpha`=100) keeps rendering as an opaque
   rectangle. This same GetMember gap almost certainly also blocks the label text
   (`FLabel.setLabel` writes `this.labelField.text`). The attached children
   (`frb_states_mc`/`fLabel_mc`/`frb_hitArea_mc`) DO render via
   `render_attached_child` (verified: `frb_states_mc` smd=9, `frb_hitArea_mc`
   correctly skipped `!visible`), but they're covered by / interleaved with the
   un-emptied opaque boundingBox, and the label glyphs never got their text.

   OFFSCREEN resolves `this.boundingBox_mc` correctly (it renders the radios
   fine), so this is a browser-WASM-specific child-resolution path — `actionGetMember`
   / the MC-child name lookup for a timeline child of a registerClass'd component
   instance. Fixing it is the next blocker for the visible result. NOTE:
   `actionGetMember` is shared across all build modes, so any change there is
   CI-observable and must be gated/verified accordingly.

2. **`render_attached_child` does not propagate cxform** (`compose_children(..., 0, 0)`)
   and renders the `child_mc_cache` candidates in cache order, not depth order —
   latent z-order / alpha-fidelity gaps that may matter once (1) is fixed.

These are tracked as the continuation of the browser-WASM component work; the
committed change here is the necessary foundation (construction + crash fix), not
the complete visual fix.

## Process lesson (again)

Same lesson as the cont.26 handoff: re-confirm a handoff's root cause with fresh
instrumentation before coding. The "missing render pass" framing was already
fixed; the real bug was one layer up (construction) plus a latent attach UAF —
and that in turn sits on top of further browser-WASM component-pipeline gaps
(child resolution, unloadMovie, label text).
