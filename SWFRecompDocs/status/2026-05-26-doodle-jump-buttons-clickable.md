# 2026-05-26 — Doodle Jump browser-WASM, buttons clickable

Sixth handoff in the Doodle Jump browser-WASM debugging chain:

1. `2026-05-25-doodle-jump-browser-investigation.md` — initial
   investigation + cycling-bug diagnosis.
2. `2026-05-25-doodle-jump-followup.md` — cycling fix landed
   (`98b388e46`).
3. `2026-05-25-doodle-jump-clip-events.md` — clip-event LOAD/ENTER_FRAME
   dispatch wired (`3ac27552e`).
4. `2026-05-25-doodle-jump-audit.md` — 22-gate audit in action.c
   (`c9b11cc99`).
5. `2026-05-25-doodle-jump-bounce-fix.md` — 6 more gates widened for
   AS-side bounds/hitTest (`68889f5ed`).
6. **This doc** — buttons-now-clickable fix landed (`92606558b`).

**Branch state at writing:** `master`, ahead of `origin/master` by 1
commit. Working tree clean. Push when ready.

## TL;DR

- **Fixed (`92606558b`):** Doodle Jump menu buttons now respond to
  mouse clicks in browser-WASM. Clicking "play" transitions
  menu → gameplay (display_list count 9 → 6). Two coupled root causes:
  - swf.c's per-tick mouse handler dispatched the AS2 onPress/onRelease
    family but never `dispatch_clip_event_press/release/roll` (the
    PlaceObject2-ClipActions variant). DJ buttons use CLIP_EVENT_RELEASE
    handlers attached via ClipActions, not as MC properties, so AS2
    dispatch missed them entirely.
  - `on_mouse_*` in render_webgpu.c used `evt->targetX/Y` (CSS pixels
    relative to canvas) as if they were canvas-internal pixels. With
    the canvas displayed at 796×1327 CSS px on a 320×480 internal buffer
    every click landed at far-off SWF stage coordinates that missed
    every hit-test.
- **Tooling:** `tools/browser-test/probe.py` now accepts `--click X,Y@T`
  and `--move X,Y@T` for synthetic mouse input against deployed demos.
  Coordinates are CSS pixels relative to the canvas bounding box.
- **No regressions:** trace harness 407=407, Pong byte-identical
  (md5 `bb1f52f690672bd558f6e5c6b1c64301`), Snake t02..t05 byte-
  identical (md5 `a213fc90328ab539f9c9e7288670d498`), DJ menu still
  bouncing (stable display_list_count=9).

## What landed

### Group 1: swf.c clip-event dispatchers (browser-WASM tick)

`swf.c`'s `#ifndef OFFSCREEN_RENDER` mouse block (line ~437) previously
called only AS2 handlers (`actionDispatchMCPress` / `actionDispatchMCRelease`
/ `actionDispatchMCMouseMove`). swf_core.c's
`input_events_deliver` (line ~528-582) does both: AS2 **and**
`dispatch_clip_event_press/release/roll/flag`. The browser-WASM path
was the asymmetric one. Added all four dispatch calls to the per-tick
moved/clicked/released branches, mirroring swf_core.c ordering exactly.

### Group 2: CSS-pixel → canvas-pixel rescale

`compute_canvas_mouse_pos` in `render_webgpu.c` reads
`canvas.clientWidth/Height` via `EM_ASM` and rescales `targetX/Y` to
canvas-internal coordinates before the `*20.0f` twip conversion.

Note: `EmscriptenMouseEvent.canvasX/canvasY` is marked deprecated in
`html5.h` ("there no longer exists a Module['canvas'] object") and is
not populated, so manual rescaling is the only path. This is a generic
fix — affects every browser-WASM demo whose canvas is rendered at a
non-1:1 CSS:internal ratio, not just DJ.

### Group 3: tag.c clip-event dispatcher gate widening

The four `dispatch_clip_event_*` functions in `tag.c` were inside a
single `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` block
(lines 3879–4536 before the edit) shared with sprite-content-bounds
and `ng_compute_droptarget`. Moved the closing `#endif` up to line
4189 so the four dispatchers compile in browser-WASM. Also removed the
matching `#ifdef NO_GRAPHICS` wrapper around their declarations in
`tag.h` (kept the gate on `ng_compute_droptarget`'s declaration since
that function is still gated).

Heuristic from the audit handoff re-confirmed: when widening a body in
a `.c` file, also widen the declaration in the header — otherwise the
wasm-link sees an implicit-int declaration and the function signatures
mismatch as `(i32) -> i32` vs `(i32) -> void`.

### Group 4: cursor-change for ClipActions-only buttons

`ng_update_button_states_in_dl`'s sprite-button-mode catcher (around
line 1853) was gated on `actionMCHasButtonHandlers(sprite_mc)` (which
checks for `onPress`/`onRelease`/`onRollOver`/etc. as own dynamic
props on the MC). DJ buttons never set those props — they use
`CLIP_EVENT_PRESS|RELEASE|ROLL_OVER|ROLL_OUT|DRAG_OVER|DRAG_OUT` clip
actions on the DisplayObject. Extended the catcher to also check
`obj->clip_actions[].event_flags` for the mouse-related mask. With
this, the canvas cursor (set per-tick in `tagShowFrame` via
`EM_ASM(... .style.cursor = 'pointer' ...)`) changes on hover over
DJ-style buttons.

### Group 5: probe.py click/move support

Added `--click X,Y@T` and `--move X,Y@T` flags (repeatable) to
`tools/browser-test/probe.py`. Times are seconds after the Run-SWF
click. Coordinates are CSS-pixels relative to the canvas bounding box
(so when the canvas is rendered at 796×1327, the play button at SWF
(86, 104) is at CSS (~286, ~346)).

The new probe flow: build sorted timeline of input events → for each
snapshot interval, fire any pending events before the interval target
time → snapshot. Mouse coordinates pass through Playwright's
`page.mouse.move/down/up` to honor the same browser-side event
plumbing as a real user.

## Diagnosis pattern that worked

Same pattern as the bounce-fix handoff:

1. **Reproduce** the bug deterministically. Built/deployed DJ, added
   `--click "286,346@2.5"` to the probe, observed dl_count stayed at 9
   (no transition).
2. **Add an instrumented printf** in the most-likely-broken path. Two
   probes in this session:
   - `on_mouse_down` to confirm the event reached the SWF.
   - `dispatch_clip_event_press` to enumerate display_list entries
     and their `clip_action_count` + `event_flags`.
3. **First probe surfaced two facts:**
   - Mouse-down DID fire with `targetX=286 targetY=346` → stage was
     `(5720, 6920)` twips. SWF stage is `(6400, 9600)` twips for
     320×480 px — so click was technically inside, but the actual
     button bounds were 0..2300 twips wide. Wrong coordinate system.
   - All 4 DJ buttons had `clip_action[0].flags=0x1` (LOAD) and
     `clip_action[1].flags=0x800` (RELEASE), no PRESS. Confirms the
     CLIP_EVENT_RELEASE dispatch was the gap.
4. **Two minimal fixes**, each verified by re-probing.
5. **Cleanup pass**: removed all printfs, confirmed clean build, ran
   regression triad (trace harness + Pong + Snake).

The state-dump tooling stays out of the commit — same convention as
prior handoffs. Re-add temporarily with `-DDJ_DEBUG_DUMP` plumbing if
needed.

## Audit of remaining tag.c NO_GRAPHICS||OFFSCREEN_RENDER gates

After this session there are ~53 such gates left in `tag.c`. Spawned
an Explore agent to classify them per the W/K/? scheme from earlier
handoffs (Widen / Keep / ambiguous).

**Audit summary:**
- **42 keep** — genuine NO_GRAPHICS/OFFSCREEN_RENDER architecture forks
  (frame-loop globals, rewind/goto state, deferred finalization,
  script-only mode, tag-skip mode, font/video recording stubs,
  hasPlayingSprites loop control). Browser-WASM has different
  execution model for these.
- **~11 widen candidates** the agent flagged, prioritized:
  - `ng_cache_transform` call sites in `tagPlaceObject2` /
    `tagPlaceObject2Ratio` modify/REPLACE branches (lines 5079, 5219,
    5243, 5500, 5598, 6064, 6077). NOTE: the function definition was
    already widened in `68889f5ed`; these are CALLERS that are still
    gated. Risk: medium — these are inside large blocks with other
    NO_GRAPHICS-specific logic (script-only mode, button-state
    preservation), need careful slicing.
  - `ng_on_place_object2` + `queue_clip_load_events` calls (5727,
    6210). Similar — callers gated, but the helpers are now widened.
  - `actionFindOrCreateMovieClip` in REPLACE path (6408). Ensures AS
    can find the new MC.
  - `ng_record_button` in `tagDefineButton` (7153). Records button
    hit bounds — needed for AS-side hitTest.
  - `actionRenameMovieClip` (7675), `actionInvokeRegisteredClassConstructor`
    (7698).

**Recommendation:** Don't widen speculatively. The previous five
handoffs widened gates ONLY after a state-dump diagnosis pinpointed a
specific broken AS value. Blind widening risks regressions in
NO_GRAPHICS / OFFSCREEN_RENDER paths (which have different storage
models and call patterns inside these blocks). The next browser-WASM
bug should be the next diagnosis entry point; cross-reference the
audit candidates against the broken AS path when it surfaces.

## Open item: post-transition stale text

After clicking play, the transition fires correctly (dl_count 9→6,
gameplay state visible: score=0 textfield, "menu" button, hero MC at
depth 4) — but the canvas screenshot shows leftover "play"/"info"/
"score"/"options" text at the same positions they occupied in the
menu. None of those texts are in the post-transition display list.

Visual evidence: `/tmp/dj-clean1/canvas/t04.png` and `t06.png`. The
display list (`display_list/t06.json`) has 6 entries: shape 54
(bg), sprite 25, hero (char 40, off-screen at y=632), shape 56,
sprite 46 (back button), text 57 (score).

Likely a render-side stale glyph issue — the EditTexts inside the
removed button sprites persist in render state after their
DisplayObjects are gone. Could be:
- Static-text-skip gate (commit `faee65274`) that doesn't run cleanup
  when EditText sprite is removed.
- Render queue retaining glyph data past sprite removal.
- A renderer-level "last-frame text" cache that isn't invalidated on
  sprite removal.

Also: hero (depth 4) at y=632 is off-canvas — the bounce-fix made the
menu hero bounce on the menu's static block, but gameplay's hero
behavior depends on a different physics setup that may still have
issues. Not investigated here. This is a separate diagnosis with
similar pattern (per-tick state dump → find first divergent value →
trace through gated code).

## How to reproduce

```
source emsdk/emsdk_env.sh > /dev/null 2>&1
SWFRecomp/scripts/build_test.sh flasharchive/Doodle_Jump wasm --graphics
SWFRecomp/scripts/deploy_example.sh flasharchive/Doodle_Jump \
  "$(pwd)/docs2/examples" --no-index --graphics

source /tmp/pong-probe/venv/bin/activate
# Menu screen: hero bouncing, no click
python3 tools/browser-test/probe.py flasharchive/Doodle_Jump \
  --wall-clock-seconds 6 --snapshot-interval-seconds 1 \
  --screenshot-timeout-ms 30000 --out /tmp/dj-menu

# Click play button: menu→gameplay
python3 tools/browser-test/probe.py flasharchive/Doodle_Jump \
  --wall-clock-seconds 6 --snapshot-interval-seconds 1 \
  --screenshot-timeout-ms 30000 \
  --move "286,346@2.0" --click "286,346@2.5" \
  --out /tmp/dj-play

# Verify: t01..t02 = menu (dl_count=9). t03..t06 = gameplay (dl_count=6).
```

The click coords `(286, 346)` are CSS pixels for the Playwright
viewport's auto-scaled canvas (320×480 internal → ~796×1327 CSS). At
1:1 CSS scaling (i.e. native window), the play button is at SWF px
(~115, ~125) directly.

## Pass criteria for follow-on work

1. **Trace harness clean:** 407=407 on
   `python3 tools/divergence/divergence_test.py SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf --frames 30 --skip-ruffle`.
2. **Pong:** `unique_canvas_sizes=1`, md5 `bb1f52f690672bd558f6e5c6b1c64301`.
3. **Snake:** t02..t05 md5 `a213fc90328ab539f9c9e7288670d498`.
4. **DJ menu:** dl_count=9 stable, hero visible bouncing, buttons
   rendered with correct labels.
5. **DJ click on play:** dl_count transitions 9 → 6 within 1 snapshot
   of the click time, with no `page_errors` in console.

## Don't-touch list (cumulative)

Same as the bounce-fix handoff's list, plus:
- The four `dispatch_clip_event_*` calls in `swf.c`'s
  `#ifndef OFFSCREEN_RENDER` mouse block are interlocking with the
  AS2 dispatch and the cursor update. Don't re-gate just one.
- `compute_canvas_mouse_pos` MUST be called for all three of
  `on_mouse_move/down/up` — they share the convention that
  `app_context->mouse.stage_x/y` is in SWF twips.
- `ng_update_button_states_in_dl`'s `has_mouse_clip_event` check is
  separate from `actionMCHasButtonHandlers` for a reason: AS2-only
  buttons use the latter; ClipActions-only buttons use the former; a
  sprite with both gets matched by either.

## Tools / state

- Local Ruffle source: `~/CC/ruffle`
- MTASC: `~/CC/mtasc/bin/mtasc`
- Probe venv: `/tmp/pong-probe/venv`
- Latest known-good probes:
  - DJ menu: `/tmp/dj-menu-stable/`
  - DJ click → gameplay: `/tmp/dj-clean1/`
  - Pong regression baseline: `/tmp/pong-reg/`
  - Snake regression baseline: `/tmp/snake-reg/`

Branch `master` is 1 commit ahead of `origin/master`:
- `92606558b browser-WASM: wire CLIP_EVENT_PRESS/RELEASE/ROLL dispatch + canvas-px mouse coords`

Push when ready.

## Pattern note (7th instance)

The buttons-clickable fix turned out to be **two** gate-asymmetry
instances stacked: the dispatcher gate (NO_GRAPHICS||OFFSCREEN_RENDER
in tag.c + matching declaration gate in tag.h) AND the canvas
coordinate system mismatch (browser-WASM-specific code path that was
never written correctly because the test harness modes don't have a
DOM-resized canvas to expose the bug). The latter is a different
shape from prior instances: not a `#ifdef`-induced silent no-op, but a
unit/coordinate-system bug that simply never manifested in any test
mode because tests deliver mouse events in SWF-stage coordinates
directly (via `input.json` → `input_events.txt`).

Future browser-WASM bugs may also have this two-tier pattern:
gate-asymmetry hides the proximate symptom, then a deeper
browser-WASM-only assumption (e.g. that canvas internal pixels =
CSS pixels) hides the actual fix. State-dump diagnosis at both levels
caught both in this session.
