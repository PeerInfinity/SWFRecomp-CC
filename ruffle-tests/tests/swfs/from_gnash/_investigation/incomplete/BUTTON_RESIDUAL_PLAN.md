# Button Residual Plan

<!-- TESTS: ButtonEventsTest, key_event_test, DragDropTest, button_test1 -->

<!-- PLAN_META
id: BUTTON_RESIDUAL
status: pending
phases:
  - id: 1
    name: "ButtonEventsTest residual lines"
    status: partial
  - id: 1a
    name: "ButtonEventsTest buttonChild population (bias 16383)"
    status: complete
  - id: 1c
    name: "ButtonEventsTest test progression past line 58"
    status: partial
  - id: 1c1
    name: "Recompiler: prefer SHAPE hit record over SPRITE"
    status: complete
  - id: 1c2
    name: "Bounds: sprites with button-only children get AABB from hit shape"
    status: complete
  - id: 1c3
    name: "Event ordering: SWFBUTTON_* fires before frame advance"
    status: pending
  - id: 2
    name: "key_event_test progression past frame 5"
    status: deferred
  - id: 3
    name: "DragDropTest _level50 droptarget"
    status: deferred
  - id: 4
    name: "button_test1 remaining mismatches"
    status: complete
dependencies: []
blockers: []
parent_plan: "complete/BUTTON_INFRASTRUCTURE_PLAN.md"
-->

Last updated: 2026-05-05 (Phase 1c sub-fixes 1c1+1c2 landed locally; 1c3 still open).

## Summary status (CI at `aaa502d1`)

| Test | Suite | Lines | Status | Phase |
|------|-------|-------|--------|-------|
| `button_test1` | misc-swfc.all | **31/31 PASS** | complete | 4 |
| `ButtonEventsTest` | misc-ming.all | 58/679 (1c1+1c2 fixed prereqs but blocked by 1c3 ordering) | partial | 1 |
| `key_event_test` | misc-ming.all | 33/66 (50%) | deferred | 2 |
| `DragDropTest` | misc-ming.all | 27/44 (61%) | deferred | 3 |

## 2026-05-05 session findings

### Phase 4 — `button_test1` (misc-swfc.all) → PASS (+1, 20/31 → 31/31)

Two changes in `SWFModernRuntime/src/libswf/tag.c` `ng_update_button_states_in_dl`
(the headless button hit-test/state machine):

1. **Recurse into sprites in the display list.** Previously the loop only
   descended into nested *buttons*; nothing walked into a sprite to look for
   buttons inside it. button_test1's structure is `button3 → buttonContainer
   (sprite) → button1 + button2`, so the inner buttons never received
   hit-test or press dispatch even though `button3.instance1.button1` etc.
   resolved as movieclips. Mirrors Ruffle's `mouse_pick_avm1` which walks
   the render list for interactive children before falling back to the
   button's own `hit_area`.
2. **Replace `hit_test_shape` (triangle-mesh) with `ng_hitTestShapeChar`
   for resolved button hit shapes.** In NO_GRAPHICS mode shapes carry only
   path data (`ng_record_char_path`) — `shape_offset/size = 0/0` — so the
   triangle-based test always returned 0. `ng_hitTestShapeChar` understands
   path-based hit testing and is what the rest of the runtime uses for
   `hitTest`. Made it non-static and added a public extern in `tag.c`.
   Also extended `resolve_hit_shape` to return the resolved char id (and
   accept morph shapes).
3. The first inner-button hit consumes `*found_hover` so the outer button
   does not also press. Matches Ruffle's "first interactive child wins"
   semantics, exactly what button_test1's expected output requires
   (`green box`/`red box` only — never `button3` from the outer button's
   handler).

### Phase 1 — `ButtonEventsTest` line 2 (`instanceOf Button`) fixed

`instanceOfCoercing`'s MOVIECLIP arm fell back to `MovieClip.prototype` when
a button MC had no `dynamic_props.__proto__`. In Flash/Ruffle, buttons are
their own type with chain `Button.prototype → Object.prototype`, NOT a
subclass of MovieClip — so the walk never hit `Button.prototype`. Fix: when
the receiver is `is_button_mc`, fall back to `g_stub_ctors[1].prototype_obj`
(lazy-init via `initButtonPrototype`) before the `MovieClip.prototype`
fallback. Files: `SWFModernRuntime/src/actionmodern/action.c`
`instanceOfCoercing`. `attachMovie`-installed button MCs were already
correct via the explicit `__proto__` setup in the attachMovie path; this
fix covers timeline-placed button MCs.

ButtonEventsTest is still `output_mismatch` overall — see Phase 1
sub-phases below.

## Phase 1 — ButtonEventsTest sub-phases

ButtonEventsTest is a deep test: 679 expected lines exercising button child
sprite lifecycle (load/unload across state transitions), getDepth bias
quirks, button event dispatch, focus, key events, and unloadMovie. Our
output is 81 lines (matches lines 1-58 after Phase 1a, then diverges into
test-progression noise and stops). To make progress we need to fix the
test progression in Phase 1c (the next divergence cluster).

### 1a — `_root.buttonChild` array population (lines 43-51, 9 lines) — COMPLETE 2026-05-05

**Resolved.** Root cause was depth-bias mismatch for button-state child
sprites. Flash uses bias 16383 for these (one less than the standard
`AVM_DEPTH_BIAS = 16384` Ruffle and we use everywhere else). The test's
populator script at `for-in` time computes
`buttonChild[getDepth() + 16383] = …` — with our bias-16384 the indices
came out as `9, 11` instead of the expected `10, 12`, so every
`buttonChild[10|12]` assertion failed.

Fix: detect the case via `parent->is_button_mc` at three depth-set
sites in `action.c` (`findOrCreateMovieClip`, `resolveSlashPathToMC`
slash-path resolver, `actionGetMember` nested-child resolver) and
apply bias 16383 there. Other MC creation paths keep bias 16384.

Two pre-existing changes already in the working tree at session start
also load-bear:
- Bare-function `getDepth()` dispatch in `actionCallFunction` (mirrors
  the `actionCallMethod` MOVIECLIP arm) — needed for the script_2
  populator's `getDepth()` call inside the sprite's frame action,
  which doesn't go through the method dispatch path.
- `actionCallMethod` ARRAY user-method dispatch now binds `this` to
  the array itself (was `arr->props`) — the test's
  `Array.prototype.realLength` does `for (var i in this)` which needs
  the array as `this` to enumerate numeric indices.

Lines 43-53 of ButtonEventsTest now PASS. Total matching: 48 → 58
(+10). Verified no regressions: 14 AVM1 button + 4 drag tests, gnash
ButtonPropertiesTest/RollOverOutTest, 9 prototype/lifecycle, 11
timeline, 10 array, 8 Inheritance/Global/case-v6 tests — 56/56 still
PASS or effective.

#### Original investigation steps (kept for reference)

**Test mechanism.** A "events-reporting MC" (`ermc`, sprite char 12) is
placed at depths 10, 11, 12, 13, 14 inside the button across different
states. Each placement of `ermc` runs its frame-0 action (`script_2`),
which writes:

```as
if ( _root.buttonChild == undefined ) _root.buttonChild = [];
var myDepth = getDepth() + 16383;
var myName = ''+this;
if ( _root.buttonChild[myDepth] == undefined )
    _root.buttonChild[myDepth] = {nam:myName, exe:1, uld:0};
else
    _root.buttonChild[myDepth]['exe']++;
this.onUnload = function() {
    var myDepth = -(getDepth()+32769-16383);
    _root.buttonChild[myDepth]['uld']++;
};
```

Initial state (button on UP): `ermc` is placed at depths 10 (ALL states)
and 12 (UP only). Test expects `_root.buttonChild` to have entries at
indices 10 and 12.

**Observed.** `_root.buttonChild` is type `'object'` AND `instanceof Array`
PASSES (lines 41-42). But `realLength()` returns 0 (line 43 expects 2). So
the array exists but has no indexed entries — script_2's
`buttonChild[myDepth] = …` writes don't stick.

**Diagnostic added in this session** (since reverted): `script_2` IS being
executed twice during the initial frame, dispatched from the queued sprite
script at `actionDrainAllInPriorityOrder` at root-frame end. So the
populator runs.

**Cross-reference with Ruffle.** `output.ruffle.txt` for this test:
- Line 79 (line 565 in test): `realLength() == 2` → Ruffle gets **3**
  (extra entry from running an extra state's child).
- Line 80 (line 568): `typeof(buttonChild[10]) == 'object'` PASSES.
- Line 81 (line 569): `buttonChild[10].nam == 'instance5'` → Ruffle gets
  `'instance8'` (later state's instance, latest write wins at depth 10).
- Line 84 (line 574): `typeof(buttonChild[12]) == 'object'` → Ruffle gets
  `undefined` (depth-12 child not populated, like ours).

So Ruffle populates depth 10 (matches Flash on `typeof` and `exe`/`uld`
counts) but misses depth 12, plus has extra entries from later states. We
populate **nothing** — strictly worse than Ruffle.

**Hypothesis (untested in this session).** `script_2` runs in a context
where either:

(a) `_root` resolves to something other than `&root_movieclip` (e.g.,
    the button's MC because of `g_current_context` being set to the button
    MC during the queued drain), so the `_root.buttonChild = []` write
    creates a `buttonChild` on the button MC instead of root. Subsequent
    `_root.buttonChild[N] = …` at root then overwrites with the
    just-created `[]` because the property suddenly does exist on root for
    the array-base lookup but is missing for the indexed write.

(b) `getDepth()` returns NaN/undefined for button-state child sprites,
    making `myDepth = NaN+16383 = NaN`, and `arr[NaN] = …` creates a
    string-key property `"NaN"` rather than a numeric index — invisible to
    `realLength()`'s `Number(i) == i` filter.

(c) The button-state child MC's parent chain doesn't reach root through
    `_parent`, so `_root` resolution from inside the sprite's frame_0 walks
    the wrong way.

**Recommended approach.** Add stderr printf to `script_2` (or to
`actionSetMember` when key is `buttonChild`) to capture `mc->name` of the
recipient and the value of `myDepth` at write time. Three-line diagnostic:
the write site, the `_root` reference target, and the depth. From there:
fix the relevant resolver. This is *not* the same bug as the off-by-1
depth (1b below) — Ruffle has the off-by-1 too and still populates
buttonChild[10] correctly.

**Estimated effort.** 2-4 hours: 30 min instrumentation, 1-2 hours
identifying which of (a)/(b)/(c) is at fault, 1 hour landing the fix +
regression sweep.

**Expected line gain.** 9 lines (43-51) on success, plus possible
unblocking of lines 52-81 if the test loop progresses further.

### 1b — `getDepth()` off-by-1 for SWF-depth-12 button child (line 53, 1 line) — RESOLVED via 1a

Initial reading of this as a "Ruffle-vs-Flash difference" was wrong.
Flash uses bias 16383 for **all** button-state child sprites (both the
ALL-states depth 10 child AND the UP-only depth 12 child). Ruffle and
we used bias 16384 universally, which explains both:
- `getDepth() == -16371` direct check (depth 12 child)
- `buttonChild[10|12]` populator-derived check (depth 10 and 12 children)

Phase 1a's bias fix lands all of these together. Line 53 now PASSES.

### 1c — Test progression divergence (lines 59+) — partial (2 of 3 sub-fixes landed 2026-05-05)

After line 58 PASSES (`hitTest(60, 60, true)`), the test enters the
mouse-event-driven phase: `input.json` has 38 events (14 MouseMove + 9
MouseDown + 9 MouseUp + 6 Wait), and the test expects 15 sequential
sub-tests gated by `_root.testno` (1, 2, 3, …, 15). Each sub-test fires
on a specific button event (RollOver/RollOut/Press/Release).

#### 1c1 — Recompiler: prefer SHAPE hit record over SPRITE (COMPLETE)

**Root cause.** The Ming-generated SWF for ButtonEventsTest emits four
HIT records on the button: `sh1a` (small 5×5 shape), `sh1` (40×40 shape),
`ermc` (sprite at depth 10, all states including HIT), and `ermc` (sprite
at depth 11, HIT only). The recompiler at `SWFRecomp/src/swf.cpp:5587`
unconditionally overwrote `hit_char_id` with the LAST HIT record
encountered — picking the depth-11 ermc sprite. Since `ermc` is a sprite
with no graphics (just a script), `resolve_hit_shape` in
`SWFModernRuntime/src/libswf/tag.c` returned NULL, so
`ng_update_button_states_in_dl` never fired any button transitions. The
button's hit-test always returned 0, no SWFBUTTON_* actions fired, and
the test couldn't progress.

**Fix.** Track shape char IDs in the recompiler context as `DefineShape*`
/ `DefineMorphShape*` tags are processed (`SWFRecomp/include/context.hpp`
`shape_char_ids` set), then in the button parse loop only update
`hit_char_id` if the new char is a known shape OR if no shape has been
seen yet. Files: `SWFRecomp/include/context.hpp`, `SWFRecomp/src/swf.cpp`
(swf.cpp:5587 + interpretShape shape_id tracking).

After this fix, the button correctly hit-tests and SWFBUTTON_*
actions fire on transitions.

#### 1c2 — Bounds: sprites with button-only children get AABB from hit shape (COMPLETE)

**Root cause.** With 1c1 applied, button transitions fire — but
`_root.square1.onRollOut` (the handler that advances testno and
nextFrame()s to frame 3) still didn't fire. Trace showed
`mc_get_pixel_aabb_ng(square1)` returned `has_bounds=0`, so
`actionDispatchMCMouseMove` skipped square1. The sprite's content is the
button character; `ng_getCharBoundsForRatio(button_char_id, ...)` returns
0 because button characters don't register shape bounds. With no fallback,
square1's AABB came out empty.

**Fix.** In `mc_get_pixel_aabb_ng` at the children-walk fallback, when
`ng_getCharBoundsForRatio` fails for a child, look up the button's hit
shape via a new `ng_getButtonHitCharId(char_id)` accessor and use the hit
shape's bounds instead. Files: `SWFModernRuntime/src/libswf/tag.c` (new
`ng_getButtonHitCharId`), `SWFModernRuntime/src/actionmodern/action.c`
`mc_get_pixel_aabb_ng` fallback.

After this fix, square1 has `bounds=(39.95, 29.95, 80.05, 70.05)`,
`actionDispatchMCMouseMove` fires `square1.onRollOut` correctly, and
the handler invokes `nextFrame()` advancing the timeline to frame 3.

#### 1c3 — Event ordering: SWFBUTTON_* fires before frame advance (PENDING)

**Observed (post-1c1+1c2).** Test still at 58/679 matching. Trace shows
the test now executes through frames 3+, even reaching `2. Press (and
keep pressed)…` (frame 4). But output still diverges at line 59 because
SWFBUTTON_MOUSEOVER fires on the FIRST MM(60,60) when `testno=0`, taking
the else-branch and emitting `FAILED: Unexpectedly got
SWFBUTTON_MOUSEOVER event (testno:0)`. Ruffle's expected output skips this
line entirely — by the time MOUSEOVER fires, `testno` is already 1.

**Hypothesis.** Ruffle's event delivery model coalesces or delays
SWFBUTTON_* dispatch until after frame-advance scripts run, so that the
sub-test 0 → frame 3 transition completes before any "real" mouse event
is delivered to the button. Our impl delivers each MM event immediately
to `ng_update_button_states_in_dl`, firing SWFBUTTON_MOUSEOVER before
square1.onRollOut has a chance to advance the frame.

**Recommended approach.** Compare event-vs-frame ordering with Ruffle's
`tests/run.rs` event playback. Ruffle may queue the first frame-advance
side-effect (nextFrame) and re-run frame scripts before continuing event
delivery. Specifically the sequence for input
`[Wait, Wait, Wait, MM(60,60), MM(0,0), MM(60,60), MD(60,60), MU(60,60),
…]` should produce zero output between the frame 2 hitTest line and
the frame 3 "1. Roll over…" note.

**Estimated effort.** 4-6 hours: needs Ruffle source inspection of the
input-replay tick model + event-deferral logic.

**Expected line gain.** If 1c3 lands, ButtonEventsTest could jump from
58/679 to ~150-200/679 (subtests 1-3 worth of correct output), with
remaining failures from buttonChild assertion mismatches that Ruffle
also fails (Flash UB).

#### Original investigation steps (kept for reference)

Initial trace approach was: log every SWFBUTTON_* dispatch and AS-level
handler call. That trace immediately revealed the recompiler bug (1c1):
`[BTN_HIT] btn_hit_char_id=12 hit_ch=(nil)` — char 12 was a sprite, not
a shape. Manually re-running SWFRecomp confirmed `tagDefineButton(...,
hit_char_id=12)` before the fix, `hit_char_id=13` after.

### Phase 1 verification battery

In addition to the parent plan's required-pass guardrail:

- AVM1 button event tests: `mouse_events`, `mouse_events_visible_enabled`,
  `mouse_hover_events_while_dragging`, `button_keypress`,
  `button_keypress_vs_press`, `button_keypress_vs_tab`,
  `button_keypress_vs_textinput`, `button_v5`, `button_v6`,
  `button_children`, `button_order`, `button_properties_special_cases`,
  `button_goto`, `button_key_events` — 14 tests, must stay PASS.
- AVM1 lifecycle: `unload`, `register_class`, `register_and_init_order`,
  `init_object_order`, `register_class_return_value`, `on_construct`,
  `extends_chain`, `as2_super_and_this_v6/v8` — 9 tests. Likely sensitive
  to changes in `getDepth`, scope resolution, and `_root` resolution.
- Gnash misc-ming `ButtonPropertiesTest`, `RollOverOutTest` (effective).
- Gnash misc-swfc `mouse_drag_test`, `button_test1` — must stay PASS.

## Phase 2 — `key_event_test` progression past frame 5

Status: `33/66 (50%)`. Lines 1-30 match (tests 1-5). Line 31+ diverge.

**Diff shape.** Looking at the diff output, the test runs frames 5-10 with
KeyDown events triggering both clip-action handlers (`onClipKeyDown` on
`listenerClip2`, `ls1`/`ls2`/`ls3`) AND AS-level handlers
(`obj.onKeyDown` registered via `Key.addListener(obj)`). Our impl fires
events in the wrong order:

```
expected:                          actual:
mc.onKeyDown triggered             listenerClip2.onClipKeyDown
                                   mc.onKeyDown triggered
PASSED: ... 13 == 13               FAILED: 13 obtained 14
```

The expected sequence at line 56 is `'0+ls3+ls2+ls1+obj1+ls1+obj2+ls2+obj3+obj1+obj2+obj3'`
Our actual: `'0+ls3+ls1+ls2+ls3+ls1+ls2+obj1+obj2+obj3'` — listener
firings are in different order AND we have *fewer* `obj1+ls1+obj2+ls2+obj3`
interleavings. This means:

1. Our `Key.addListener` clip-event KEY_DOWN dispatches all `ls*` *before*
   the `obj*` AS listeners (we batch by source); Flash interleaves them
   per-listener-add-order.
2. We may double-fire some listeners or skip Key.removeListener calls.

**Sub-phases.**

### 2a — Listener dispatch ordering

`Key.addListener(obj)` adds an AS-level listener to a global broadcast
list. Clip-events `KEY_DOWN` are wired separately on each MC's clip event
table. In Flash both are dispatched in the order they were added,
interleaved into a single broadcast list keyed by add-order. Our impl
likely keeps two separate lists.

**Diagnostic.** Add stderr trace at `actionDispatchKeyDown` and at
`dispatch_clip_event_flag(KEY_DOWN)` to log every listener fire with its
type (clip-event vs AS-listener) and the registration order. Compare to
Ruffle source `core/src/avm1/globals/key.rs` and
`core/src/display_object/movie_clip.rs` clip event dispatch.

### 2b — `Key.removeListener` semantics

Test code at frame 5+ likely calls `Key.removeListener(obj1)` between
events. Verify that subsequent KEY_DOWN events skip `obj1.onKeyDown`
correctly. The trace string `'0+ls3+ls1+ls2+ls3+ls1+ls2+obj1+obj2+obj3'`
shows `ls1`/`ls2`/`ls3` fire 6 times across two events when only 3 fires
each are expected — so we may not be removing listeners on the second
event, OR we're firing each listener twice per event.

### 2c — `dynamic_mc.onKeyDown` MovieClip-as-listener path

Ruffle treats a MovieClip with `onKeyDown` defined as an implicit Key
listener (without explicit `Key.addListener(mc)`). Our impl may be firing
this via a separate path that doesn't interleave with explicit
`Key.addListener` registrations. Trace: when does `dynamic_mc.onKeyDown`
fire? Before or after `Key.addListener`-added handlers?

**Estimated effort.** 4-6 hours: needs fixture-grade understanding of
Flash's broadcaster timing across clip-events + AS-listeners + implicit
MC listeners. Subject to retreat if the underlying broadcaster API needs
reshaping.

## Phase 3 — DragDropTest `_level50` droptarget

Status: `27/44 (61%)`. Lines 1-15 PASS, 16-23 FAIL on `_level50/*`,
24-32 PASS (`/loadedTarget/*` works), 34-41 FAIL on later tests.

### Investigation (2026-05-05 session)

Initial hypothesis was that `ng_compute_droptarget` doesn't walk
`g_levels[1..127]`. Verified: a sketched walk produces no hits because
**`g_levels[50]->display_obj == NULL`** at drop-target compute time.
Level loads via `loadMovieNum(url, 50)` create the level MC in
`getOrCreateLevel`, but the level's `display_obj` is never wired to a
DisplayObject with a sprite_display_list. The `_did_swap` block in
`actionFirePendingDirectLoads` (action.c:19871) is gated on
`dobj != NULL && dobj->sprite_display_list != NULL`, so for fresh levels
the swap never fires and the loaded SWF's tagPlaceObject2 calls land in
the *root* `display_list`. (This is why level loads "work" for variable
access — `g_levels[50]->dynamic_props` is populated correctly via the
loaded SWF's createEmptyMovieClip path — but the *display list* never
exists at the level boundary.)

Adding a `g_levels[]` walk is the wrong shape. The actual mechanism in
play is `actionFindDynamicDropTarget` (action.c:26860), which already
*does* support level paths via the `hit_level_root` walk at
action.c:26921. Tracing in this session shows it correctly enumerates
all three `target10` candidates (root, _level50, loadedTarget) with
`draw_has_bounds=1`. So the level50 children ARE seen by the dynamic
walker.

The bug is in the **world-matrix lookup** for level-rooted MCs:

- Root's `target10`: parent=root, world matrix `tx=0 ty=0`. local point
  matches (50, 50) → bounds (30,30,70,70) hit. ✓
- loadedTarget's `target10`: parent=loadedTarget, world matrix tx=200
  (loadedTarget is positioned at x=200 in root). local=(-150, 50) at
  the same world coord → out of bounds. ✓ (correct miss)
- `_level50`'s `target10`: parent=g_levels[50], world matrix… **never
  fires HIT in the dragger's input range.** Either `getConcatMatrixForMC`
  for a level-rooted MC returns identity (so it competes at the same
  world position as root's target10 and loses the depth tiebreak), or
  it returns something with the level's offset baked in but the dragger
  position doesn't intersect.

The test's input.json drives the dragger to specific coordinates that —
under Flash semantics — overlap each container in turn (root, level50,
loadedTarget). For the root and loadedTarget phases we get the right
hit; for the level50 phase we see *no* hit at all (`_droptarget = ""`),
suggesting the world matrix puts level50's target10 somewhere the
dragger never reaches.

### 3a — Trace `getConcatMatrixForMC` for level-rooted MCs

Diagnostic step: at the start of `actionFindDynamicDropTarget`, log the
dragger's stage coords and ALL candidate world matrices for the level50
children specifically. Cross-reference against:

- The expected x/y where the test SWF places target10/target20/target100
  inside `_level50` (in the loaded SWF's frame 1; readable from
  `DragDropTestLoaded.swf` via ffdec).
- Ruffle's level positioning: by default a `_levelN` root has world
  matrix identity (no offset).

If the world matrix returns identity but the test still expects a hit at
the dragger's stage coords, then the test's drag positions must be
designed to land *inside* level50's target10 at its declared coords —
which means our world matrix is correct but our stage coords are wrong.

**Estimated effort.** 4-6 hours (was 1-2): we need to validate three
moving parts (world matrix, level placement, dragger stage coord) before
landing a fix. Recommend pairing with someone who's worked on
`getConcatMatrixForMC` previously.

### 3b — Path format (subordinate to 3a)

Once 3a lands hits at the right coords, check the emitted path. The
existing `actionFindDynamicDropTarget` at action.c:26921 walks the parent
chain looking for `_levelN` ancestors and emits `_levelN/segs…` already.
Verify it produces `_level50/target10` for the level50 case (no leading
slash, no extra `/` between `_level50` and `target10`).

### Phase 3 verification battery

- AVM1: `drag_drop`, `drag_over_from_outside`,
  `drag_over_without_startdrag`, `mouse_hover_events_while_dragging`
  (4 tests, must stay PASS).
- Gnash misc-swfc: `mouse_drag_test` (must stay PASS).
- Gnash misc-mtasc: `levels` (effective pass; verify level loading still
  works post-fix).

**Expected line gain.** 8 lines on DragDropTest (16-23) on success.
Note: lines 34-41 are downstream (post-`unloadMovieNum(50)`) and
probably need a separate level-cleanup fix.

### Why `g_levels[]` walk doesn't help

The hypothesis "iterate g_levels[]" implicitly assumed level content
lives in a separate display list. It doesn't — fresh levels have
`display_obj == NULL`, so loaded SWF tags place into root's display
list. Adding the walk produces zero hits because there's nothing to
walk into. Don't replace the dynamic-MC walk path; *fix* the
world-matrix path within it.

## Phase 4 — `button_test1` — COMPLETE

Done in 2026-05-05 session. See "Session findings" above.

## Investigation order recommendation

(Revised 2026-05-05 after Phase 3 deeper trace.)

1. **Phase 1a first.** 2-4 hour investigation, potential +9 lines plus
   unblocks 1c. The diagnostic step (printf at `actionSetMember` for
   key=`buttonChild` and the script_2 entry point) is cheap and
   concrete.
2. **Phase 3 second.** Larger scope than first thought (4-6 hours);
   needs world-matrix tracing for level-rooted MCs. Initial sketch
   ("walk g_levels[]") doesn't apply — `g_levels[N]->display_obj` is
   NULL after load, so there's nothing to walk into. The fix is in
   `getConcatMatrixForMC` (or its caller) for level-rooted MCs.
3. **Phase 2 last.** Largest scope (broadcaster restructuring). Deferring
   doesn't block anything else — key_event_test has been at 50% for
   multiple CIs and isn't on any user-facing path.

## Verification battery (cumulative across phases)

**Required-pass guardrail (must not regress):**

- AVM1: 14 button + 4 drag + 9 prototype/lifecycle = 27 tests.
- Gnash misc-ming: `ButtonPropertiesTest`, `RollOverOutTest` (effective).
- Gnash misc-swfc: `mouse_drag_test`, `button_test1`.
- Gnash actionscript.all: `Inheritance-v5..v8` (effective).

## Why this is the right shape

The parent plan's six phases addressed *architectural* button issues
(typeof, prototype enum order, eager state init, _droptarget
infrastructure, mask hitTest, key listener phase progression). Each
remaining failing test has a *narrow* residual issue that doesn't fit
back into the architectural phases. Phase 4 (button_test1) and the line-2
fix on Phase 1 confirm the residual-plan shape works — single-file fixes
landed both.

The remaining 3 sub-phases (1a/1b/1c) on ButtonEventsTest are the only
non-narrow issue. ButtonEventsTest exercises so many button features
that progress past line 43 needs sequential fixes; reasonable to track
as separate sub-phases of Phase 1 within this plan rather than promoting
to an architectural plan.

## Estimated session budget

- Phase 1: 4-8 hours (1a investigation + fix, 1c follow-up).
- Phase 2: 4-6 hours.
- Phase 3: 4-6 hours (revised after deeper trace; was 1-2).
- Phase 4: COMPLETE.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `complete/BUTTON_INFRASTRUCTURE_PLAN.md` | Parent plan. This plan covers residual work after parent's 6 phases landed. |
| `complete/LEVELS_PLAN.md` | Phase 3a leverages level loading already working; extends `ng_compute_droptarget` to walk `g_levels[]`. |
| `incomplete/REMAINING_TAIL_TRIAGE.md` | These tests appeared in REMAINING_TAIL_TRIAGE's cluster table under BUTTON_INFRASTRUCTURE_PLAN; promoting them to a dedicated plan reflects that the parent plan didn't fully resolve them. |
| `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` | Phase 1b lands here when the test promotes — `getDepth` SWF-depth-12 button child returns `-16372` in our impl and Ruffle, `-16371` in Flash. |
