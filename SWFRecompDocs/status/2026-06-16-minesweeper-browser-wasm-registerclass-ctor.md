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

## cont. 40e (2026-06-16) — radio circle: nested-build + bounds-stub fixed; deep nested-bounds still open

User re-tested in a real browser after the super-arg fix: labels render but are still
clipped a bit at the right, and the radio circles are not visible. Both turned out to
share one browser-WASM root — **attached/nested clip `_width` reads short or 0** — chased
through several layers (each fix is committed, browser-WASM-only, CI byte-identical):

1. **Nested-sprite content wasn't built (`8494da83d`).** `frb_states_mc` (the circle) is
   built from two nested sprites (cid 14/17, the ring's 3D layers). `ng_attachMovie` placed
   them but left them as just-allocated holders with NULL `sprite_display_list`;
   `render_display_list`/`compose_children` recurse into nested sprites, so they drew
   nothing. NO_GRAPHICS/OFFSCREEN build them via `process_sprite_needs_init` (no such pass
   in browser-WASM). Fix: run `advance_sprite_frames` over the clip's list right after
   `funcs[0]` in `ng_attachMovie`. Confirmed nested lists now populate (nsmd 7/1).

2. **`sprite_content_bounds_twips` was a 0-returning stub (`e9c2a1e14`).** In
   `graphics_stubs.c` it returned 0 unconditionally, so `ng_attachMovie` set every attached
   clip's `mc->width/height = 0`. Implemented it via `ng_computeBoundsFromDL_matrix`.
   Corrects attached clips with direct/shallow content; regression-smoked Tetris + DJ clean.

3. **STILL OPEN — deep nested-bounds recursion zeroes out.** Even after (1)+(2),
   `frb_states_mc._width` is still **0**. Instrumented `mcGetEffectiveSize` /
   `ng_computeBoundsFromDL_matrix`: `frb_states`'s children cid 14/17 are identity-placed
   (`place_a/d=1`, tx/ty=0) with built nested lists, but the recursion into their children
   (cid 14 has 7 grandchildren) yields no bounds, so the whole clip computes 0. Net effect:
   `radioWidth = frb_states._width = 0` → `FRadioButton.setLabelPlacement` sets
   `fLabel_mc._x = 0` → the label draws **on top of** the circle (circle hidden), and the
   component width math still falls a bit short (labels clipped). The circle content almost
   certainly renders now (transforms come from `transform_id`, not `place_*`) but is covered.
   **Next step:** find why `ng_computeBoundsFromDL_matrix`'s recursion into cid 14's
   grandchildren returns 0 — likely their cached `place_*` weren't set when built via the
   attach-context `advance_sprite_frames` (vs the `funcs[0]` placement that cached cid
   14/17 correctly). Fixing that should make `frb_states._width` correct → `fLabel_mc._x`
   offsets the label right → circle becomes visible, and tighten the label width.

`render_attached_child` cxform (`compose_children(...,0,0)`) + cache-order z-order remain a
possible secondary follow-up once the bounds/overlap is fixed.

## cont. 40f (2026-06-16) — DEEP nested build → radio circles VISIBLE (`327ef4378`)

Re-confirmed the cont.40e "place_* unset" hypothesis with fresh instrumentation
(a recursive DL dump in `ng_attachMovie` + the bounds engine) — and it was **wrong
again** (process lesson, yet again). The grandchildren's `place_*` WERE correctly
cached (a=1, d=1, proper tx/ty). The real cause: the grandchildren (cid 7/9/11/13/16)
are themselves **nested sprites** that were *placed but never built* — `nDL=NULL
nsmd=0`. `frb_states`'s circle is cid 14/17 (built, nsmd 7/1), each holding nested
sprites cid 7/9/11/13/16, which wrap the actual ring shapes cid 6/8/10/12/15. The
bounds engine can't recurse into empty holders → the clip computed `_width=0`.

**Why only one level built:** `advance_sprite_frames` gates its
recurse-into-nested-children step on `!g_advance_defer_nested` (tag.c:1185). Both
the attach-time nested build (`ng_attachMovie`, `8494da83d`) and the registerClass
eager build (`exec_sprite_frame`) run INSIDE the root frame advance, where the flag
is 1 — so they built each clip's DIRECT children and stopped, leaving the next level
as unbuilt holders.

**Fix (`327ef4378`):** clear `g_advance_defer_nested` (save/restore) around the
`advance_sprite_frames` call in BOTH `ng_attachMovie` (tag_stubs.c) and
`exec_sprite_frame`'s eager build (graphics_stubs.c), so the full subtree builds.
Confirmed: `frb_states_mc._width` 0 → **10** (matches the OFFSCREEN reference
exactly), every leaf shape now has `charBounds=yes`, and the deployed-demo
**circles render** (gray rings left of each label). Both sites are browser-WASM-only
(ng_attachMovie block gated `!NO_GRAPHICS && !OFFSCREEN_RENDER`; exec_sprite_frame
under `#ifndef OFFSCREEN_RENDER`) → CI byte-identical (OFFSCREEN divergence 634
lines, unchanged). Regression-smoked Tetris + Doodle Jump clean. Not CI-dispatched.

**Still possibly open (needs the human's real-browser eyeball — smoke is unreliable):**
the labels may still clip a few px at the right (`radio._width` reads 100 vs OFFSCREEN
108). [RESOLVED in cont.40g below.]

## cont. 40g (2026-06-16) — labels fully un-clip: placement scale → MC _xscale (`8df7ff325`)

User re-tested: circles visible (cont.40f win) but labels still clipped at the right —
and tellingly **all three clipped at the SAME x** despite differing lengths. That's
fixed-field-width clipping, not text overflow. Traced (browser-vs-OFFSCREEN DBG on the
exact render path `actionIterateTextFieldGlyphs` `info.w = mc->width`):
- browser-WASM labelField width = **90** for all three; OFFSCREEN = **98 / 115 / 115**
  (per-label). So OFFSCREEN sizes each field to its text; browser used one fixed width.
- The field is `autoSize=none` in BOTH modes (tf_flags 0x0048 = HTML+ReadOnly, no
  WordWrap/AutoSize) — so autoSize was a red herring. The width comes from
  `FRadioButton.setLabelPlacement`: `labelField._width = this.width - frb_states._width`.
- `this.width` is set at init by `super.setSize(this._width, …)` — read BEFORE init's
  `this._xscale = 100` (line 30). So `this._width` = local-bounds × placement-xscale.
  **The three radios are placed at different xscale — `place_a` = 1.08 / 1.25 / 1.25 —
  to fit their labels.** OFFSCREEN reflects that on the MC (`_width` = 100×1.08 = 108 …),
  but browser-WASM created the registerClass MC with `_xscale = 100` (placement scale
  never transferred) → every radio read width 100 → label 90 → clip.

**Fix (`8df7ff325`, `graphics_stubs.c` exec_sprite_frame, browser-WASM-only):** before
firing the constructor, set the MC's `_xscale`/`_yscale` from the placement-matrix
magnitude (`sqrt(a²+b²)`, `sqrt(c²+d²)`) when scale isn't AS-overridden yet (init's later
`_xscale=100` sets the as_set_flags, so later frames don't re-apply). Matches Flash
(a clip's `_xscale` reflects its placement matrix). Confirmed: browser-WASM labelField
widths now **98/115/115** = OFFSCREEN exactly; all three labels render fully
("Easy (40 mines)" / "Medium (70 mines)" / "Tough (100 mines)"). Browser-WASM-only
(exec_sprite_frame `#ifndef OFFSCREEN_RENDER`) → CI byte-identical (OFFSCREEN 634 lines).
Tetris + Doodle Jump smokes clean.

**Still open — circle APPEARANCE differs from Ruffle (user report).** The circle ring
now renders and is correctly positioned, but looks different from Ruffle — diagnosed
precisely with the new Ruffle harness (`tools/divergence/game_drive/minesweeper_ruffle*`,
committed `d962010e0`) + DBG on `render_attached_child` and the frb_states structure.

**frb_states (cid 29) is a 5-STATE multi-frame clip** (FrameLabels): `unselectedEnabled`
(f1: place cid14 frb_frame_mc @d1 + cid17 @d9), `press` (f6: +cid20), `unselectedDisabled`
(f11: cid22), `selectedDisabled` (f15: +cid25), `selectedEnabled` (f21: +cid28 = the dot).
FRadioButton.setState does `frb_states_mc.gotoAndStop("selectedEnabled"/"unselectedEnabled")`.

TWO confirmed browser-WASM-only gaps, BOTH non-trivial:

1. **Selected-dot missing (Medium should be ◉).** DBG on `render_attached_child`: ALL
   three frb_states render at `cur_frame=0` (unselectedEnabled), `playing=0`, children
   cid14+cid17 only — **no radio ever reaches `selectedEnabled` (cid28 dot)**. Root: the
   attached-clip `gotoAndStop("selectedEnabled")` is never applied in browser-WASM. The
   whole goto-by-label + attached-clip frame-navigation machinery is `#if NO_GRAPHICS ||
   OFFSCREEN_RENDER`-gated (action.c ~45036 `ng_findSpriteLabelFrame`, ~58192 the
   `gotoAndStop` apply has no browser-WASM `#else` arm, and the bare-call path at 58189
   uses `varToDouble(args[0])` which can't resolve a string label anyway). Fixing this
   means giving browser-WASM a real attached-clip goto-to-label: resolve the label →
   frame, navigate the attached clip's `sprite_display_list` to that frame (run/build
   frames 0..target like advance_sprite_frames' manual-nav branch), and stop. Substantial.

2. **Ring shading: glossy 3D "bead" vs Ruffle's flat circle.** Both show the SAME content
   (unselectedEnabled = cid14 frb_frame_mc + cid17), so it's NOT a wrong frame — it's how
   cid14's nested 3D shading sub-layers (grandchildren cid6/8/10/12/15 shapes) render.
   `compose_children` DOES preserve each child's baked `cxform_id` for direct children, so
   the cxform isn't trivially dropped; the suspect is whether the DEEP-BUILT grandchildren
   (built via the cont.40f `advance_sprite_frames` path) got their `cxform_id` cached at
   placement (transform_id was cached correctly; cxform_id may not be) — if they're left at
   identity, the alpha/tint that flattens the ring is lost → opaque bead. Needs a DBG on
   the grandchildren's cxform_id vs OFFSCREEN.

Both are follow-ups beyond the original two complaints (circles-visible + labels-clipped),
which are fixed and committed (40f/40g). Ruffle ground-truth + side-by-side:
`DISPLAY=:0 …/minesweeper_ruffle_capture.py` then crop vs `smoke_Minesweeper.png`.

## cont. 40h (2026-06-17) — selected-dot investigation: NOT the gotoAndStop wiring

Investigated the selected-dot (#1). The `gotoAndStop` machinery is NOT the problem — it
WORKS in browser-WASM: instrumented the MOVIECLIP `gotoAndStop` handler (action.c ~64808)
and `ng_gotoFrameByMC` — `frb_states_mc.gotoAndStop(label)` IS reached, the label resolves
(`ng_findSpriteLabelFrame`, ungated, in tag.c), the browser-WASM `#else` arm calls
`ng_gotoFrameByMC` for the attached non-root clip, and `advance_attached_clip_frames`
rebuilds its display list. All wired up (much was already done in a prior session — see the
frb_states comment at action.c ~64877 / tag_stubs.c ~1102).

**The real break is UPSTREAM in the radio-group selection chain.** Probe result: every
`gotoAndStop` call on frb_states_mc is `frame_num=1` (**unselectedEnabled**) — `selectedEnabled`
(frame 21) is NEVER requested. So no radio's `setState(true)` ever fires. The default
selection flows: `frame_4: _root.bombs_amount=70` → `frame_5: diff_level.setValue(70)` →
`FRadioButtonGroupClass.setValue` iterates `radioInstances`, finds `data==70` (Medium) →
`Medium.setValue(true)` → `setState(true)` → `gotoAndStop("selectedEnabled")`. That chain
never reaches Medium in browser-WASM. (All radios' `initialState=false`, confirmed in their
`on(initialize)` params — so the default is set ONLY by the group's `setValue`, not per-radio.)

Two red flags from the probe, both pointing at the registerClass/frame-execution model:
- Every gotoAndStop fires at `root_frame=1` (not frame 5 where the radios/`diff_level.setValue`
  live) — root frame counter / frame-5-DoAction execution timing is suspect.
- Each radio's `setState(false)` fires **11×** (re-initialization across frames, not once) —
  the registerClass ctor / init `setValue(false)` appears to re-run, which would also RESET
  any selection applied by the group.

**Conclusion:** the selected-dot needs work in the browser-WASM registerClass-component
group-selection + re-init / frame-execution model (does `frame_5`'s `diff_level.setValue(70)`
run? is the group `radioInstances` array populated when it does? why do radios re-init 11×?),
NOT the goto path. This is a deeper, separate investigation than the goto wiring — deferred.
The ring-shading (#2) remains deferred too. Both primary complaints (40f/40g) stay fixed.
No code changed in 40h (investigation only; all DBG stripped, demo redeployed clean).

## cont. 40i (2026-06-17) — selected-dot FIXED (`f437520b0`)

The selected dot (Medium ◉) now renders in browser-WASM. Re-confirmed cont.40h's
root cause with fresh instrumentation (CTOR / CALLM setValue,setState /
GOTOSTOP-frame DBG in shared code → stderr, diffed browser-WASM vs the working
OFFSCREEN reference). cont.40h's "frame map" was wrong: frb_states (cid 29) has
**5 frames** (selectedEnabled = frame **5**, not 21 — that was a tag index). Two
browser-WASM-only gaps, both fixed:

**Gap 1 — selection chain never fired (registerClass construction ORDERING).**
DBG delta: browser-WASM `setValue f64=70` fired at seq=3 on **objtype=3
(undefined)** BEFORE any radio constructor (seq 4/45/86); OFFSCREEN fires it at
seq=129 on **objtype=11 (the real group)** AFTER all 3 radios construct +
`addToRadioGroup`. The radios are placed in (recompiler) `frame_4`; the DoAction
`diff_level.setValue(70)` is `actionQueueScript(script_22)` drained at that frame's
`actionDrainAllInPriorityOrder` (tagMain.c:108) — which runs BEFORE `tagShowFrame`
(:109), where browser-WASM constructs the radios (exec_sprite_frame). So the group
`diff_level` was un-built (undefined) when setValue ran → no-op → nobody selected.
NO_GRAPHICS/OFFSCREEN construct at PLACEMENT (process_sprite_needs_init), before
the DoAction. (cont.40h red flag #2 "11× re-init" was a MISREAD — that's the
normal init cascade, identical count in both modes; constructors fire once each.
Red flag #1 "root_frame=1" was the never-updated browser-WASM root counter, a
red herring.) **Fix:** `ng_construct_pending_registerclass_sprites` (tag.c) runs
the just_allocated construction for freshly-placed registerClass timeline sprites
at the top of `actionDrainAllInPriorityOrder` — so the group exists before the
DoAction. Idempotent (skips allocated) + re-entrancy-guarded.

**Gap 2 — the dot didn't render even after the chain fired.** Render DBG
(`render_attached_child`) showed Medium's frb_states at cf=5, smd=11, with cid 28
present at depth 11 — yet no visible dot. cid 28 (the dot) is itself a 1-frame
SPRITE wrapping the dot shape (cid 27). `ng_gotoFrameByMC`'s synchronous frame
replay places cid 28 but — unlike `advance_attached_clip_frames`' post-replay
`advance_sprite_frames` (tag.c:1873) — never built its nested content, so the
holder rendered empty (the ring, cid 14/17, was deep-built during initial
construction so it showed; the dot was not). **Fix:** `advance_sprite_frames`
after the replay in `ng_gotoFrameByMC` with `g_advance_defer_nested` cleared
(cont.40f deep-build), g_current_context still the clip.

Both gated `!NO_GRAPHICS && !OFFSCREEN_RENDER` → CI byte-identical (OFFSCREEN
Minesweeper divergence unchanged at 634 lines; not CI-dispatched). Verified
in the deployed demo: **Medium ◉, Easy/Tough ○** (matches Ruffle/OFFSCREEN
F0014.png). Regression: Tetris title + GAMEPLAY (board cells via
`ng_gotoFrameByMC` — correct colors, no stale trail) and Doodle Jump menu clean.
The ring-SHADING gap (#2 from cont.40g, glossy bead vs flat) remains DEFERRED.

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
