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
  `this.<child>` access during `init()` see fully-built content.
- Also still latent once width lands: `render_attached_child`'s
  `compose_children(..., 0, 0)` (no cxform) + cache-order (not depth-order)
  z-order; and the faint circle ring vs Ruffle.

### cont. 40c (2026-06-16) — eager-build PROTOTYPED & validated, but the width
### chain has a 5th layer; eager-build REVERTED (not committed)

Implemented the eager-init-before-constructor fix above and validated it works:
- New shared flag `g_exec_eager_built_obj` (tag.c). In `exec_sprite_frame`
  (browser-WASM), before firing the ctor and when `!catch_up_mode`, call
  `advance_sprite_frames()` on the sprite's own list (the caller already swapped
  the globals to it) to build the nested children's frame-0, then set the flag so
  the caller's post-CALL_FRAME recursion (tag.c ~1169) skips the redundant rebuild
  (`g_exec_eager_built_obj != obj` guard + consume). NULL in CI modes → output-
  identical there.
- **Confirmed working:** boundingBox_mc now has content (`child_smd=3`) before the
  ctor, and the radio's first `setSize` read becomes correct: `setWidth(v=100)`
  (was 18.55). So the eager-build genuinely fixes the FIRST `_width` read.

**But it's invisible — a 5th layer dominates.** Instrumenting `mcSetEffectiveWidth`
showed `labelField._width` is set **twice** per radio, both in the radio's context:
`setWidth(100)` (radio `_width`=100, boundingBox present) THEN `setWidth(20)`
(radio `_width`=20, AFTER `boundingBox_mc.unloadMovie()`). The second call wins →
still clipped. The `20` is the radio's post-unload `_width`: with boundingBox
removed (cont.40 fix), the radio's `sprite_display_list` bounds = just `deadPreview`
(~20px). The attached children that SHOULD make it ~100px — `fLabel_mc` (label,
already 100px wide) and `frb_states_mc` (circle) — are in `child_mc_cache`
(attachMovie'd), NOT in the radio's `sprite_display_list`, so the browser-WASM
bounds engine (`mcGetEffectiveSize` / `ng_computeBoundsFromDL_*`) excludes them.
In Flash a clip's `_width` includes its attached children, so the post-unload
`_width` stays ~100 and the second `setSize` is a no-op. **5th gap: attached
(child_mc_cache) children parented to a clip are not counted in that clip's
`_width`/`_height`/bounds in browser-WASM.** (Not yet pinned: the exact source of
the SECOND setSize call — it runs once, in the radio's context, after unload;
likely a component `size()`/relayout. Worth confirming before fixing.)

Because eager-build (40c) is invisible until the 5th gap is also fixed AND it
touches the shared advance hot path (other games use `registerClass`), it was
**reverted** rather than committed half-finished — land it together with the
attached-children-bounds fix, tested as a unit (smokes + OFFSCREEN divergence).
The 40c patch is fully described here and was validated, so re-deriving it is
cheap. Committed state remains cont.40 + 40b (rectangles gone + labels render
with correct text, width-clipped).

**Next-session plan (the width chain, in order):**
1. Pin the source of the SECOND `setSize`/`setWidth(20)` call (instrument the
   radio's `setSize`/`size` method entry; confirm it reads live `this._width`).
2. Make the browser-WASM bounds engine count attached `child_mc_cache` children
   (parented to the clip) in `_width`/`_height`/getBounds — so post-unload
   `_width` ≈ 100 and the second `setSize` stops shrinking the label. (Broad
   surface — gate browser-WASM, regression-test bounds-sensitive games.)
3. Re-apply the 40c eager-build (first-read correctness) and land both together.
4. Then revisit the faint circle ring + `render_attached_child` cxform/z-order.

## cont. 40d (2026-06-16) — ROOT CAUSE was SHARED, not the width chain — FIXED (`bcacc3f70`)

The cont.40c "width chain" / "5th gap" premise was **wrong**, caught by re-confirming
with fresh instrumentation (process lesson, yet again). The plan above (esp. step 2,
"count attached children in the bounds engine") would have been **useless and risky**:

- Instrumented `mcGetEffectiveSize` + the `this.width`/`this.height` setMember writes
  in BOTH browser-WASM and OFFSCREEN. The radio's `_width` is read **once** at init
  (`super.setSize(this._width, this._height)`) and **never re-read** with attached
  children present — so making the bounds engine count attached children changes
  nothing observable. The "20 = radio post-unload `_width` = deadPreview" story was
  fiction: `deadPreview._width` is set to **1**, and the radio reads **0** (no eager-
  build) / **100** (eager-build), never 20.
- **OFFSCREEN clips the labels identically** (rendered `F0014.png`: "○ E / ◉ r / ○ -").
  So it was never a browser-WASM-only bug. The handoff's "OFFSCREEN renders the radios
  fine" was inferred from the NO_GRAPHICS *trace* (text), which is unaffected — not
  from a render.

**Real root cause (shared, all build modes):** decompiled the SWF with JPEXS
(`~/CC/jpexs/ffdec-cli.jar -export script`). `FUIComponentClass.setSize = function(w,h){
this.width=w; this.height=h; ... }` is a type-1 (simple `DefineFunction`); FRadioButton
reaches it via `super.setSize(this._width, this._height)`. Six type-1 dispatchers in
`actionCallMethod` (the SWF6 + SWF7+ super-ctor/super-method paths, the `__resolve` hook,
and array-element `arr[N](args)` calls) pushed args onto the stack in **reverse** order,
while the canonical non-super dispatcher (`action.c:~53488`) and the generated type-1
prologue both expect **forward** order (the prologue pops params last-declared-first).
Net: `super.setSize(108, 13)` bound `this.width=13, this.height=108` — confirmed by
instrumentation. That collapsed the component width, so `setLabelPlacement`'s
`w = this.width - frb_states._width` shrank each `labelField._width` to ~10px and the
single-line non-wordWrap labels clipped to ~2 chars.

**Fix:** make all 6 type-1 dispatchers push forward (`for i=0..num_args`), matching the
canonical path. Tagged `TYPE1_ARG_ORDER`. After the fix: `super.setSize(108,13)` →
`width=108, height=13`; `labelField._width` → 115 (OFFSCREEN) / 100 (browser-WASM); both
modes render full labels ("Easy (40 mines)" / "Medium (70 mines)" / "Tough (100 mines)").

**Eager-build (40c) kept, browser-WASM only:** still needed there so the radio's
`this._width` reads the (2-levels-deep) `boundingBox_mc` width at construct time (0 → 100)
— without it the swap fix has nothing but 0 to bind. Gated via `g_exec_eager_built_obj`
(NULL + inert in CI: `graphics_stubs.c` `exec_sprite_frame` isn't compiled there).

**CI:** the arg-order fix is shared/CI-observable (affects every `super.method(2+ args)` /
`super(2+ args)` / `__resolve` / array-element type-1 call suite-wide). Dispatched
no-graphics + graphics. Minesweeper NO_GRAPHICS trace unchanged (634 lines) — the fix
alters rendered component layout, not `trace()` output. Eager-build CI-inert.

**Still open (cont.40e):** the radio circle ring / dot (`frb_states_mc`) renders faint;
`render_attached_child` cxform + cache-order-not-depth-order (handoff step 4). The label
goal is DONE.

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
