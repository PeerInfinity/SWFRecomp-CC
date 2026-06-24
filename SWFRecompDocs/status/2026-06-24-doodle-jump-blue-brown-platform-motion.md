# 2026-06-24 — Doodle Jump: blue platforms don't move, brown debris doesn't drop (browser-WASM)

## Symptom (user, browser-WASM, real GPU)

- Blue (moving) platforms are stationary, stuck at the left edge of the screen.
- Broken brown platforms don't drop.

Both are driven by `onClipEvent(enterFrame)` on a **nested timeline clip inside an
attachMovie'd "cloud"**:

- Blue mover (`cloud` frame 3 → char 32 "aaa"): `onClipEvent(enterFrame){ this._x += ac; bounce 20..190 }`.
- Brown debris (`cloud` frame 4 → char 37): `onClipEvent(enterFrame){ this._y += ac; }` (ac=8, drops).

The cloud is `attachMovie("cloud","block_N",...)`'d to the `levelcontainer` (char 25),
and `levelcontainer.attachBlocks` deliberately places blue clouds at `block._x = 0`
(left edge) — the *visible* left-right travel comes entirely from the nested char-32
clip sliding inside the cloud. So "stuck at left" = the nested clip not moving.

## Root cause — two structural gaps in the attached-clip nested-enterFrame path

Diagnosed in-browser with a temporary debug build that force-navigated every cloud
to frame 3 (`char_id==27 → gotoAndStop(3)`) so blue platforms appear deterministically
(the seeded RNG produces few/no blue platforms in a short headless game-over run), plus
bounded `[DJ_DBG_*]` prints in `dispatch_attached_clip_enterframe` and the
`compose_children` overlay.

1. **`sprite_initialized` never reaches 2 for nested clips inside attached clips.**
   `upgrade_sprite_initialized` (called once/tick from `tagShowFrame`) only walks the
   **global** `display_list`. An attachMovie'd cloud's authoritative
   `sprite_display_list` is a **standalone** buffer not reachable from `display_list`,
   so its nested char-32/char-37 entry stayed at `sprite_initialized=1` forever.
   `gather_clip_ef_entries` requires `>= 2` (tag.c:3539) → the nested
   `onClipEvent(enterFrame)` clip action **never fired** (`as_set_flags` stayed 0,
   `_x`/`_y` never changed). Confirmed: entry `sinit=1`.

2. **The moving clip's MovieClip has `display_obj == NULL`, so the render overlay can't
   find it.** `compose_children` has a browser-WASM overlay (added `8deefbb5c`) that
   re-applies a nested timeline clip's AS-mutated `_x`/`_y` onto its static placement
   transform, matching the moving MC to its display entry **by `display_obj == obj`**.
   But the per-cloud "aaa" MC is created lazily **by name** during enterFrame dispatch
   (`actionFindOrCreateMovieClip`), which leaves `display_obj == NULL` — so the match
   never succeeded and the motion never rendered even once enterFrame fired. Confirmed:
   MC found by name had `display_obj=0`.

Both gaps had to be fixed; fixing only #1 made the clip move in logic (`as_set_flags=1`,
`_x` advancing) but it still rendered static; fixing only #2 was moot because the clip
never moved.

## Fix (`tag.c`, browser-WASM only — `!NO_GRAPHICS && !OFFSCREEN_RENDER && !HEADLESS_GRAPHICS`)

1. **`upgrade_attached_clip_initialized(app_context)`** — new per-tick pass that runs
   the same recursive `upgrade_sprite_initialized` promotion over each attachMovie'd
   clip's standalone `sprite_display_list` (skipping clips whose `display_obj` lives in
   the global `display_list`, already covered by the root walk). Called right after the
   two existing `upgrade_sprite_initialized(display_list, max_depth)` sites in
   `tagShowFrame`. Now the nested entry reaches `sprite_initialized=2` → its
   enterFrame clip action fires from the next tick.

2. **Link each nested clip's MovieClip to its display entry** in
   `dispatch_attached_clip_enterframe`: after dispatching, for each named entry in the
   cloud's standalone list, resolve the per-cloud MC (`actionFindOrCreateMovieClip(name,
   cloud_mc)` — keyed by name **and** parent, so each cloud owns a distinct "aaa") and
   set `mc->display_obj = entry` when it's NULL (never clobber an existing linkage). This
   restores the invariant the `compose_children` overlay relies on, so the overlay
   re-applies the AS `_x`/`_y` each tick.

Brown debris (char 37, frame 4) uses the **identical** nested-clip-in-attached-cloud
mechanism, so the same two fixes cover it.

## Verification

- Temporary force-blue debug build: every cloud → frame 3. After both fixes, per-cloud
  char-32 "aaa" MCs are distinct (unique pointers), `sinit=2`, `as_set_flags=1`, `_x`
  advancing per tick, and `[DJ_DBG_COMPOSE … APPLIED]` fires with varying x. Screenshots
  showed blue platforms distributed across x (left/center/right), not stuck at left.
- Production build (no force, no debug): greens/browns render normally, **0
  errors/aborts** over a steered ~12s run. (Seeded RNG produced no blue platforms in the
  short headless game-over run, so natural blue motion is to be confirmed by the user in
  real gameplay — the mechanism is identical to the force-blue path that was verified.)
- Interaction with `2285b6b0d` (render_attached_child skips nested timeline children):
  no conflict — once `display_obj` is linked to the cloud's standalone list, the nested
  clip is correctly skipped by its own `render_attached_child` (ancestor-list guard) and
  drawn via the cloud's `compose_children` overlay; no double-render.

CI: not dispatched — all new code is browser-WASM-gated and excluded from both CI modes
by construction (`ci-only-when-observable`).

## Files

- `SWFModernRuntime/src/libswf/tag.c` — `upgrade_attached_clip_initialized` (new) + two
  call sites; `display_obj` linking in `dispatch_attached_clip_enterframe`.

Deployed: `docs2/examples/flasharchive/Doodle_Jump/`.
