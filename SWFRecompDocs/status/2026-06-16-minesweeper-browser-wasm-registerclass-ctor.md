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
