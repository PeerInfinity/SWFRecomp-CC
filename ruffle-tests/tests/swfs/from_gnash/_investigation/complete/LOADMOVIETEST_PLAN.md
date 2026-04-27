# loadMovieTest Plan (Phase 5 of IMPORT_CHARACTER, split out)

<!-- TESTS: loading/loadMovieTest -->

<!-- PLAN_META
id: LOADMOVIETEST
status: complete
phases:
  - id: 1
    name: "Implement CLIP_EVENT_ROLL_OVER / CLIP_EVENT_ROLL_OUT clip-event dispatch"
    status: complete
  - id: 2
    name: "Implement CLIP_EVENT_DRAG_OVER / CLIP_EVENT_DRAG_OUT (related, similar machinery)"
    status: complete
  - id: 3
    name: "Verify loadMovie cross-target semantics (target:_level0.cont.coverart, /cont/coverart)"
    status: complete
  - id: 4
    name: "Address other line-by-line gaps once the test progresses past frame 5"
    status: complete
-->

## 2026-04-27 session — RESOLVED

`loading/loadMovieTest` is now **RUFFLE_MATCHED** (effective pass).

Implementation: added a `dispatch_clip_event_roll()` dispatcher in
`SWFModernRuntime/src/libswf/tag.c` that walks the display list,
hit-tests each placement carrying ROLL/DRAG clip actions against the
current mouse position, and fires the appropriate clip-action handler
on the `clip_mouse_inside` transition. Button-state at the time of
the move decides ROLL_OVER/OUT (button up) vs DRAG_OVER/OUT (button
down). Wired into `swf_core.c`'s EV_MOUSE_MOVE / EV_MOUSE_DOWN_LEFT /
EV_MOUSE_UP_LEFT handlers (the down/up calls catch the ROLL↔DRAG
state-flip on edge events). Per-DisplayObject `clip_mouse_inside` u8
added next to `clip_mc_pressed`.

Result: 80/80 lines match `output.ruffle.txt` (the only diff vs
`output.txt` is trailing whitespace on FAILED lines — Ruffle keeps
the trailing space, `output.txt` strips it). All Phase 3/4 line gaps
turned out to be already-implemented mechanics that were dormant
because the test never progressed past line 5 — once ROLL_OVER fired
and installed `coverart.onMouseDown`, every subsequent line dropped
into place.

Guardrails (all PASS):
- `clip_events`, `bad_placeobject_clipaction`, `movieclip_in_removed_button`
- `button_children`, `goto_rewind1/2/3`, `on_construct`
- `unload`, `unload_clip_event`, `movieclip_state_values`, `issue_1104`

## Problem statement

`loading/loadMovieTest` (gnash misc-ming.all) currently passes only 5 of
80 expected lines (6.2%). The test is `known_failure = true` in
`test.toml`. It was previously deferred from `IMPORT_CHARACTER_PLAN.md`
Phase 5; this plan splits it out for separate work.

The test SWF has a `coverart` MovieClip nested inside a `cont`
MovieClip (`_level0.cont.coverart`). Its placement carries
`SWFACTION_ROLLOVER` and `SWFACTION_ROLLOUT` clip actions:

```
clip_actions_63[] = {
    { 0x2000, clip_action_10 },   // CLIP_EVENT_ROLL_OVER → installs onMouseDown
    { 0x4000, clip_action_11 },   // CLIP_EVENT_ROLL_OUT  → deletes onMouseDown
};
tagPlaceObject2WithClipActions(app_context, 8, 23, 59, 0, 0, clip_actions_63, 2);
```

`clip_action_10` sets `_level0.coverart.onMouseDown = function() { ... }`,
which is the AS-level handler whose body produces the bulk of the
expected trace output. Until that handler is installed, mouseDown
events at the test's click location `(640,180)` (which is inside
coverart) produce no trace beyond the inline `xcheck` on
`getBytesLoaded()`.

## Diagnosis: why we stop at line 5

Our actual output matches expected lines 1–5 exactly:

| Line | Trace | Source |
|------|-------|--------|
| 1 | `PASSED: movieclip == movieclip` | initial setup `check_equals(typeof(_level0.cont), 'movieclip')` |
| 2 | `PASSED: movieclip == movieclip` | initial setup `check_equals(typeof(_level0.cont.coverart), 'movieclip')` |
| 3 | `0.0: Click on the first image…` | initial `note(…)` |
| 4 | `PASSED: true` | inline `xcheck(getBytesLoaded() < _root.getBytesLoaded())` (coverart sprite frame_0) |
| 5 | `PASSED: true` | inline `xcheck(getBytesTotal() < _root.getBytesTotal())` |

After that the input.json fires its first `MouseDown`/`MouseUp` at
`(640,180)`. Expected behaviour:

1. Earlier `MouseMove(640,180)` should have fired CLIP_EVENT_ROLL_OVER
   on coverart, which runs `clip_action_10` and installs
   `coverart.onMouseDown`.
2. `MouseDown` then fires the global AS-level `onMouseDown` callback
   (via `actionDispatchMCMouseDown`), which produces the next ~7
   expected lines.

We never reach step 1, so step 2 also produces nothing.

## Root cause: CLIP_EVENT_ROLL_OVER / ROLL_OUT are never dispatched

`SWFModernRuntime/src/libswf/tag.c` handles clip events as follows:

| Event flag | Bit | Dispatcher |
|------------|-----|------------|
| LOAD, ENTER_FRAME, UNLOAD, MOUSE_MOVE, MOUSE_DOWN, MOUSE_UP, KEY_DOWN, KEY_UP, DATA, INITIALIZE, KEY_PRESS, CONSTRUCT | various | `dispatch_clip_event_flag(flag)` (broadcast / non-hit-test) |
| PRESS | 0x00400 | `dispatch_clip_event_press` (hit-test based, with mc_mouse_inside semantics for press tracking) |
| RELEASE / RELEASE_OUTSIDE | 0x00800 / 0x01000 | `dispatch_clip_event_release` (hit-test based) |
| **ROLL_OVER** | **0x02000** | **(none)** |
| **ROLL_OUT** | **0x04000** | **(none)** |
| **DRAG_OVER** | **0x08000** | **(none)** |
| **DRAG_OUT** | **0x10000** | **(none)** |

The recompiler parses these flags and stores them as
`ClipAction[]` on the placement (confirmed in
`SWFRecomp/src/swf.cpp` and the generated
`RecompiledTags/tagMain.c`). The runtime stores them on
`DisplayObject.clip_actions[]`. There is no code in `tag.c`,
`tag_stubs.c`, `swf_core.c`, or `action.c` that fires
0x02000 / 0x04000 / 0x08000 / 0x10000.

Confirmed by `grep -rn "CLIP_EVENT_ROLL\|0x2000" SWFModernRuntime/src/`
(returns only the constant definition).

## Phase 1 — Implement CLIP_EVENT_ROLL_OVER / ROLL_OUT dispatch

The semantics (from Ruffle/Flash) are hit-test based, fired on
mouseMove transitions:

- ROLL_OVER fires on the placement when the mouse first enters its
  hit area (and the mouse button is up — otherwise it's DRAG_OVER).
- ROLL_OUT fires when the mouse leaves (button up — else DRAG_OUT).

### Storage: per-DisplayObject "mouse inside" flag

`MovieClip.mc_mouse_inside` already exists for the AS2-property roll
dispatcher (`actionDispatchMCMouseMove`). For clip events we need
the same tracking on `DisplayObject` (since clip actions are placed,
not on the MC). We can either:

- **Option A.** Add a `clip_mouse_inside` u8 to the DisplayObject
  struct (next to `clip_mc_pressed`).
- **Option B.** Reuse `mc_mouse_inside` from the corresponding
  MovieClip when the placement has an `instance_name`. But anonymous
  placements with clip events still need state — fall back to a
  per-DisplayObject flag for those.

Option A is simpler and matches existing precedent (`clip_mc_pressed`).

### Dispatcher: pattern after `dispatch_clip_event_press_dl`

`dispatch_clip_event_press_dl` already does the recursive sprite-DL
walk, transform composition, and `ng_hitTestShapeFromDL` call. The
new `dispatch_clip_event_roll_dl` would:

1. For each entry with ROLL_OVER or ROLL_OUT clip actions:
   - Hit-test the mouse against the placement's shape content.
   - If transitioning `was_inside=0 → now_inside=1` and mouse
     button is up: fire ROLL_OVER actions, set
     `clip_mouse_inside=1`.
   - If transitioning `was_inside=1 → now_inside=0` and mouse
     button is up: fire ROLL_OUT actions, set
     `clip_mouse_inside=0`.
   - For DRAG_OVER/DRAG_OUT (Phase 2), same transitions but with
     button down.
2. Recurse into nested sprite DLs.

Hook into `input_events_deliver` for `EV_MOUSE_MOVE` (right after
the existing MOUSE_MOVE clip-event broadcast and before button state
processing) and also from `swf_core.c`'s per-tick re-evaluation
(matches `ng_update_button_states` placement at line 1035) — visible
state changes (e.g. `_visible = true` revealing a clip) should also
trigger transitions.

### Verification

Targeted Tests:
- `from_gnash/misc-ming.all/loading/loadMovieTest` — should
  progress past line 5 once ROLL_OVER fires on coverart on the
  first MouseMove(640,180).
- AVM1 `clip_events` (currently 18/18) — guardrail; should not
  regress.
- AVM1 `bad_placeobject_clipaction` — guardrail.
- AVM1 `movieclip_in_removed_button` — guardrail.

Also re-run the AVM1 lifecycle/event battery (button_children,
clip_events, goto_rewind1/2/3, on_construct, unload,
unload_clip_event, movieclip_state_values) to confirm no
regressions in the clip-event machinery.

## Phase 2 — DRAG_OVER / DRAG_OUT

Same machinery as ROLL_OVER/OUT but gated on
`mouse.button_down == 1` instead of 0. Less common in tests, but
trivial extension once Phase 1 lands. Likely no test in the suite
specifically exercises DRAG_OVER/DRAG_OUT clip events
(grep the corpus to confirm).

## Phase 3 — loadMovie cross-target semantics

Once ROLL_OVER lands and the test progresses to line 6+, the
expected output exercises:

```
loadMovie('red.swf', '_level0.cont.coverart');
loadMovie('red.swf', '/cont/coverart');
loadMovie('red.swf', '_level0.coverart');     // commented out as #if SKIP_FAILING
```

These use the GETURL-style `loadMovie(url, target_path)` form. Verify
that our `loadMovie` resolves these slash paths and absolute paths
correctly. The `MovieClip.loadMovie` method form is exercised by
the first 3 click cycles (clicks 1–3); the GETURL form by clicks
4–6 and 7–9.

The expected output's `FAILED: expected: MovieClip.loadMovie ,
obtained:` lines come from `_root.loadMethod` not being set (the
test SWF only sets it inside red/green/blue's `onPress`, which
input.json never triggers). That mismatch is INTENTIONAL — the
expected output already contains those FAILED lines and we just
need to emit them too. Once we reach those lines, `loadMovie` is
not actually called (the click is on coverart, not red/green/blue),
so this phase may turn out to be a no-op once Phase 1 lands.

## Phase 4 — Other gaps

Once we progress past line 5, run the full test and triage any
remaining line mismatches. Candidates:

- `getBytesLoaded()` / `getBytesTotal()` returning correct values
  for an MC that hasn't been loaded into (returns the test SWF's
  byte counts).
- `getDepth()` returning -16376 for an attached coverart (the
  expected depth for a clip placed at SWF-depth 8 inside cont
  whose AS-depth would be 8 - 16384 = -16376; matches).
- The "_url is" / `lastUrlComponent` check against
  `_level0.expectLoaded` ("loadMovieTest.swf" initially).
- `_root.clicks++` / `_root.imagenames` indexing producing the
  right `note(…)` lines.

These are all already-implemented mechanics; they just haven't been
exercised yet for this test path.

## Estimated session budget

- Phase 1 (ROLL_OVER/OUT dispatch): 3–5 hours. Mostly mirroring
  `dispatch_clip_event_press_dl`. Needs care around event ordering
  vs `actionDispatchMCMouseMove` (which fires AS2 onRollOver) so
  Flash's "clip-event ROLL_OVER fires before AS2 onRollOver" is
  preserved.
- Phase 2 (DRAG_OVER/OUT): 1 hour, trivial after Phase 1.
- Phase 3 (loadMovie targets): 1–2 hours, may be a no-op.
- Phase 4 (line-by-line): 2–4 hours.

Total: 7–12 hours.

## Open questions

1. **Does Ruffle pass loadMovieTest?** The test has a Ruffle-specific
   `output.ruffle.txt` next to `output.txt`. Compare them to know
   what's already a Ruffle/Flash divergence vs what we need to
   match.
2. **Is `mc->mc_mouse_inside` driven for nested sprites today?**
   `actionDispatchMCMouseMove` walks `child_mc_cache` and updates
   `mc_mouse_inside` based on `mc_get_pixel_aabb_ng`. Confirm
   coverart appears in the cache (named MCs accessed via AS
   resolution should be cached).
3. **Should `dispatch_clip_event_flag(MOUSE_MOVE)` (the existing
   broadcast) also drive the new hit-test dispatcher, or should it
   live as a separate call site in `input_events_deliver`?**
   Likely separate, so MOUSE_MOVE clip events (which fire on every
   move regardless of position) and ROLL_OVER (which fires on
   transitions only) can be ordered correctly.

## Why this is the right shape

The IMPORT_CHARACTER plan correctly diagnosed loadMovieTest as a
"separate triage" rather than a sprite-import bug. This plan picks
up where that one left off, isolated to the missing
ROLL_OVER/ROLL_OUT/DRAG_OVER/DRAG_OUT clip-event dispatchers — a
small, focused gap in the otherwise complete clip-event machinery.
The full input-event driver, AS2 property dispatch, hit-testing,
and transform composition all already exist; what's missing is one
~50-line dispatcher function and a per-DisplayObject hover flag.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `complete/IMPORT_CHARACTER_PLAN.md` | Predecessor; Phase 5 (this plan) was deferred. |
| AVM1 `_investigation/CLIP_EVENTS_PLAN.md` (if exists) | Possible overlap with general clip-event work. |
| `MISC_MING_SWFC_PLAN.md` | Catalogues misc-ming.all status; loadMovieTest entry should reference this plan once landed. |
