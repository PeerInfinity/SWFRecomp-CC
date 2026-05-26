# 2026-05-25 — Doodle Jump browser-WASM, clip-events session

Third handoff in today's chain:
1. `2026-05-25-doodle-jump-browser-investigation.md` — original
   investigation + cycling-bug diagnosis.
2. `2026-05-25-doodle-jump-followup.md` — cycling fix landed
   (`98b388e46`), button-label diagnosis written.
3. **This doc** — clip-event LOAD/ENTER_FRAME dispatch wired up
   (`3ac27552e`). Two distinct symptoms remain.

**Branch state at writing:** `master`, ahead of `origin/master` by
3 commits. Working tree clean. Push when ready:
```
3ac27552e browser-WASM: wire CLIP_EVENT_LOAD / ENTER_FRAME dispatch
af109897a docs: Doodle Jump browser-WASM follow-up handoff
98b388e46 browser-WASM: stop/play inside sprite frame routes to the sprite
```

## TL;DR

- **Fixed today (2 commits):**
  - `98b388e46` — sprite-internal `actionStop()` now stops the
    sprite (not the root) in browser-WASM. Hero/block sprites no
    longer cycle through their internal frames.
  - `3ac27552e` — clip-event dispatch wired: LOAD handlers queue and
    drain after sprite children are populated; ENTER_FRAME handlers
    fire from the second tick onward. Hero's physics handler
    (`clip_action_26`) now runs each tick.
- **Still broken:**
  - **Button labels stay "menu".** All 4 button LOAD handlers
    dispatch (verified via instrumentation), execute
    `this.button_txt.text = "..."` — but displayed text doesn't
    change. EditText render still shows the static placeholder.
  - **Hero falls without bouncing.** EnterFrame fires and applies
    gravity (`_y` grew 2056 → 7846 over 5 1-second snapshots). The
    collision-detection / bounce branch in `clip_action_26` doesn't
    trigger, so the hero never reverses velocity.
- **No regressions.** Trace divergence harness 407=407. Pong + Snake
  browser demos byte-identical to pre-fix.

## What landed (commits in detail)

### `98b388e46` — sprite stop/play routes to sprite

In browser-WASM, a sprite's frame-0 `actionStop()` (the recompiler's
emit pattern for an in-sprite `stop()`) was stopping the root
timeline instead of the sprite. Three coupled changes:

1. `graphics_stubs.c` `exec_sprite_frame` stub now sets
   `g_current_sprite_obj` for the duration of the frame call.
2. `action_queue.c` `aq_dispatch_sprite_script` now restores
   `g_current_sprite_obj` unconditionally (was gated on `ctx_mc`,
   which is NULL in browser-WASM because exec_sprite_frame doesn't
   swap `g_current_context`).
3. `action.c` `actionStop` / `actionPlay` modern arm dropped its
   `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` gate.

### `3ac27552e` — clip-event LOAD / ENTER_FRAME dispatch

Six widenings in `tag.c` + `swf.c`:

1. Pulled `PendingClipLoad` struct + `queue_clip_load_events` +
   `aq_dispatch_clip_load` out of the
   `NO_GRAPHICS||OFFSCREEN_RENDER` gate.
2. Pulled `g_pending_clip_actions` consumption (clip_actions array
   attachment to the DisplayObject) out of the gate in
   `tagPlaceObject2` + `tagPlaceObject2Ratio`.
3. Inlined `ng_on_place_object2`-style auto-instance-name assignment
   for unnamed scriptable placements (Doodle Jump's buttons have
   no SetInstanceName, so they end up as "instance2".."instance5"
   instead of NULL).
4. Set `sprite_initialized=1` at placement + bump 1→2 in
   `tagShowFrame`'s browser-WASM block, so
   `dispatch_enterframe_clip_actions`'s
   `sprite_initialized >= 2` gate isn't always false.
5. Pulled `g_enterframe_flush_pending = 1` out of the
   `OFFSCREEN_RENDER` gate in `swf.c`. Without it set,
   `tagFlushPendingEnterFrame` (called by the recompiler before each
   DoAction) early-returned.
6. Browser-WASM clip-LOAD goes onto `AQ_KIND_LOAD` (not
   `AQ_KIND_SCRIPT`) and drains explicitly in `tagShowFrame` *after*
   `advance_sprite_frames` — graphics-native's eager init runs
   sprite frame_0 inline during `tagPlaceObject2`, so its
   `AQ_KIND_SCRIPT` LOAD fires after children exist; browser-WASM
   has no eager init and needs to wait until `advance_sprite_frames`
   populates children. `queue_clip_load_events_kind()` takes the
   kind as a parameter; gated callers still use `AQ_KIND_SCRIPT` via
   the unchanged `queue_clip_load_events()` signature.

## Remaining bug A: button labels stay "menu"

### Symptom

Deployed demo (`docs2/demo.html?test=flasharchive/Doodle_Jump`):
the four buttons display "menu" instead of the script-set labels
"play" / "info" / "scores" / "options".

### What we know

- All four button LOAD handlers (`clip_action_17/19/21/23`) DO
  dispatch — confirmed via instrumentation:
  ```
  [DBG aq_disp_clip_load] obj=0x15d0470 name=instance2
  [DBG aq_disp_clip_load] obj=0x15d06f0 name=instance3
  [DBG aq_disp_clip_load] obj=0x15d0970 name=instance4
  [DBG aq_disp_clip_load] obj=0x15d0ab0 name=instance5
  [DBG aq_disp_clip_load] obj=0x15d0bf0 name=hero
  ```
- Each handler runs `this.button_txt.text = "<label>"`. The script
  doesn't trace any errors and doesn't appear to halt.
- `button_txt` is `char_id=47`, defined as **both** `tagDefineText`
  (static) AND `tagDefineEditTextProps` (dynamic with initial
  text "menu\r") — the SWF6+ EditText pattern. The static glyph
  fallback is "menu"; the dynamic content should override it.
- Earlier commit `0a7567a28` (today) registered EditText props in
  browser-WASM. Earlier commit `faee65274` skipped static-glyph
  render when an EditText is present.

### Likely root cause

One of:
- `this.button_txt` resolves to `undefined` (the EditText child
  isn't reachable as a property of the button MC in browser-WASM,
  even though `advance_sprite_frames` placed it in the sprite's
  display list).
- The setter call runs but doesn't propagate the new text to the
  rendered EditText (writes don't reach the actual textfield data
  the renderer reads).
- The button sprite's `button_txt` child is registered as an MC
  but its `.text` property isn't tied to the EditText render state
  in browser-WASM the way it is in graphics-native.

The first hypothesis is most likely. In `aq_dispatch_clip_load`:
```c
MovieClip* mc = actionFindOrCreateMovieClip(
    app_context, pcl->obj->instance_name, parent);
if (mc) actionSetCurrentContext(mc);
pcl->action(app_context);
```

`actionSetCurrentContext(mc)` makes `g_current_context` the button
MC. The script then does `actionGetVariable("this")` → should resolve
to the button MC → `actionGetMember(this, "button_txt")` → should
return the EditText child if it's registered as a sub-MC.

**Test plan to confirm:** instrument
`action.c::actionGetMember`'s MOVIECLIP-receiver path to log
`getMember(mc->name, member_name) -> <result type>` and re-probe.
Look for `getMember(instance2, "button_txt") -> UNDEFINED` — if
that's what shows up, button_txt isn't reachable via the MC's
child-resolution path in browser-WASM.

If button_txt IS reachable but `.text` setting fails, instrument
`actionSetMember`'s TEXTFIELD branch.

## Remaining bug B: hero falls without bouncing

### Symptom

Hero (`_root.hero`) at deployed demo: gravity is applied each tick
(EnterFrame fires correctly) but never bounces. Display-list y
values from `/tmp/dj-probe-defer/display_list/t0*.json`:
```
t01: y=2056.6   t02: y=3136.6   t03: y=4801.5
t04: y=6646.5   t05: y=7846.5
```

The hero falls off the bottom of the canvas (~480px tall) within
~2 seconds. Ruffle bounces in place on the green block.

### What we know

- `clip_action_25` (LOAD) sets `vy=0, gravity=4, yradius=hero._height/2, jump=false, jumpspeed=9` on the hero MC.
  (Strings decoded: str_234="vy", str_235="gravity", str_236="yradius",
  str_237="jump", str_238="jumpspeed".)
- `clip_action_26` (EnterFrame) integrates `_root.hero._y += vy`,
  applies gravity, has a collision branch that should set
  `jump=true; vy = -jumpspeed` when touching a block.
- The collision check probably reads `_root.<blockname>` properties
  (`_x`, `_y`, etc.) and compares with hero's position. If
  `_root.block` (instance "block") returns undefined or wrong
  properties, the collision check silently fails.

### Likely root cause

`_root.block` resolution in browser-WASM might not find the block's
DisplayObject the way it does in graphics-native. Block is named
"block" via `tagSetInstanceName` at depth 10 (`tagMain.c:52-53`),
which is unguarded and DOES run in browser-WASM. But whether `_root`
is connected to root's display list for child lookups is a different
question.

**Test plan to confirm:** instrument the entry of `clip_action_26`
(or `actionGetMember` again) to log every property read during one
EnterFrame invocation. Compare against the graphics-native trace
(which works). The first divergence is where the bug is.

A simpler initial check: log `_root.block._x`, `_root.block._y`,
`_root.hero._y`, `_root.hero._height` once per second to confirm
the script sees the same values as graphics-native.

## Common thread

Both remaining bugs look like **AS value-resolution gaps in
browser-WASM** rather than dispatch gaps. The clip-event dispatch
flow is now wired up; what runs after dispatch hits state-lookup
paths that may also be gated or differently wired in browser-WASM.

If the next session finds that property/child resolution diverges,
that's instance ~6 of the gate-asymmetry pattern and a strong cue
to do the systematic audit the first handoff recommended at instance
4. Specifically, look for `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`
guards around:
- `actionGetMember` MOVIECLIP-receiver dispatch
- `actionSetMember` TEXTFIELD or MOVIECLIP-receiver dispatch
- `_root.*` resolution paths
- TextField `.text` setter wiring

## How to verify a fix

1. **Trace harness clean:**
   ```
   python3 tools/divergence/divergence_test.py \
     SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf \
     --frames 30 --skip-ruffle
   ```
   Must remain 407=407.

2. **Browser-WASM probe:**
   ```
   source emsdk/emsdk_env.sh > /dev/null 2>&1
   SWFRecomp/scripts/build_test.sh flasharchive/Doodle_Jump wasm --graphics --clean
   SWFRecomp/scripts/deploy_example.sh flasharchive/Doodle_Jump \
     "$(pwd)/docs2/examples" --no-index --graphics
   source /tmp/pong-probe/venv/bin/activate
   python3 tools/browser-test/probe.py flasharchive/Doodle_Jump \
     --wall-clock-seconds 8 --snapshot-interval-seconds 1 \
     --screenshot-timeout-ms 30000 --out /tmp/dj-probe-X
   ```
   Pass criteria:
   - Hero visible at a reasonable y (canvas is ~480 tall, hero
     should bounce around y=200..400 not fall to y=8000+).
   - Buttons read "play"/"info"/"scores"/"options" not "menu".
   - `unique_canvas_sizes >= 2` (hero is animating, not stuck).

3. **Don't regress:**
   - Pong: probe should report `unique_canvas_sizes: 1` and
     md5 `bb1f52f690672bd558f6e5c6b1c64301`.
   - Snake: t02..t05 should md5 `a213fc90328ab539f9c9e7288670d498`.

## Don't-touch list

The clip-event widening in `3ac27552e` is interlocking — touching
one piece without the others reintroduces the bugs. In particular:
- Don't re-gate `g_enterframe_flush_pending = 1` in `swf.c`.
- Don't move `queue_clip_load_events` back inside the
  `NO_GRAPHICS||OFFSCREEN_RENDER` block.
- Don't drop `sprite_initialized=1` set or the
  `upgrade_sprite_initialized` call in `tagShowFrame`.
- The browser-WASM LOAD path uses `AQ_KIND_LOAD` deliberately so
  the drain order is `tagPlaceObject2 → tagShowFrame's
  advance_sprite_frames → drain LOAD`. Reverting to
  `AQ_KIND_SCRIPT` would re-break the timing (LOAD fires before
  children exist).

## Quick reference

- Local Ruffle source: `~/CC/ruffle`
- MTASC: `~/CC/mtasc/bin/mtasc`
- Probe venv: `/tmp/pong-probe/venv` (activate then run)
- Working dir: `/home/robert/CC/SWFRecomp-CC`
- Latest known-good probes:
  - DJ (cycling fixed, physics fires, buttons broken):
    `/tmp/dj-probe-defer/`
  - Pong (regression baseline): `/tmp/pong-probe-defer/`
  - Snake (regression baseline): `/tmp/snake-probe-defer/`
