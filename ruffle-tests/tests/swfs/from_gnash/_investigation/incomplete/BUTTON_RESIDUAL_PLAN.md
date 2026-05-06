# Button Residual Plan

<!-- TESTS: ButtonEventsTest, key_event_test, DragDropTest, button_test1 -->

<!-- PLAN_META
id: BUTTON_RESIDUAL
status: pending
phases:
  - id: 1
    name: "ButtonEventsTest residual lines"
    status: complete
  - id: 1a
    name: "ButtonEventsTest buttonChild population (bias 16383)"
    status: complete
  - id: 1c
    name: "ButtonEventsTest test progression past line 58"
    status: complete
  - id: 1c1
    name: "Recompiler: prefer SHAPE hit record over SPRITE"
    status: complete
  - id: 1c2
    name: "Bounds: sprites with button-only children get AABB from hit shape"
    status: complete
  - id: 1c3
    name: "Event ordering: SWFBUTTON_* fires before frame advance"
    status: complete
  - id: 1d
    name: "for-in on inner button MC returns zero (Button.prototype enum)"
    status: complete
  - id: 1e
    name: "Transient enumeration of removed button-state children (instance6 missing)"
    status: complete
  - id: 1f
    name: "Transient onUnload dispatch + bias-16383 propagation"
    status: complete
  - id: 1g
    name: "Transient property access on just-removed button-state children"
    status: complete
  - id: 1h
    name: "Bare-call MC method dispatch (getBounds/getRect from button event handlers)"
    status: complete
  - id: 1i
    name: "ButtonEventsTest instance-numbering drift (extra script_2 fires after preserved 3→0 transitions)"
    status: complete
  - id: 1j
    name: "ButtonEventsTest realLength upstream divergence (vestigial PUSH in actionEnumerate ARRAY arm)"
    status: complete
  - id: 1k
    name: "OUT_DOWN effective state shows OVER (fixes buttonChild[13] off-by-one)"
    status: complete
  - id: 2
    name: "key_event_test progression past frame 5"
    status: deferred
  - id: 3
    name: "DragDropTest _level50 droptarget"
    status: complete
  - id: 4
    name: "button_test1 remaining mismatches"
    status: complete
dependencies: []
blockers: []
parent_plan: "complete/BUTTON_INFRASTRUCTURE_PLAN.md"
-->

Last updated: 2026-05-06 (Phase 3 complete: DragDropTest `_level50` droptarget
promoted from `output_mismatch` (27/44) to `ruffle_matched`. Two narrow fixes:
(a) `getOrCreateLevel` now sets `xscale = yscale = 100` so the level MC's
local matrix is identity — previously HCALLOC zeroed scale to 0, making
det==0 and silently skipping all `_level50.targetN` candidates in
`actionFindDynamicDropTarget`; (b) slash-path resolvers
(`resolveSlashPathToMC`, `resolveFlashPathToMC`) now handle `_levelN`
segments (N > 0) and resolve to `g_levels[N]` — required for
`eval("_level50/target10")` paths to navigate into level descendants.
Combined with Phase 1k (ButtonEventsTest), the misc-ming.all suite is
+2 effective passes today. Phase 2 (key_event_test, 33/66) remains
deferred. See Phase 3 section for full diagnosis + 47-test regression
battery.)

Previously (2026-05-06): Phase 1k complete: OUT_DOWN button state (3)
now shows OVER children, not UP. Resolves the `buttonChild[13].exe/.uld
== 3 vs 4` off-by-one identified at the 1f "remaining gaps" section.
ButtonEventsTest promoted from `output_mismatch` (237/679 line-aligned)
to `ruffle_matched` — full effective pass for misc-ming.all suite
(+1 effective). Single-line change: `effective_state` for state 3 in
`SWFModernRuntime/src/libswf/tag.c` `ng_update_button_states_in_dl`
flipped from 0 (UP) to 1 (OVER), matching Ruffle's `avm1_button.rs`
`event_dispatch` where `ClipEvent::DragOut → ButtonState::Over`.
Mirrors Flash's "Push tracking" semantics where the button visually
stays in OVER frame while tracking a press, even when the cursor exits
the hit area. Mirror change at the second placement site (state-3
fresh init at tag.c:2891). See Phase 1k section for full diagnosis
+ regression battery (48 tests across AVM1 button/lifecycle/enum
+ Gnash misc-ming/swfc/actionscript Inheritance, all PASS).)

Previously (2026-05-06): Phase 1j complete: vestigial `PUSH(arr_var.type, ...)`
in `actionEnumerate` ARRAY arm left the array on the stack across
`for (var i in arr)` enumerations from SWF5-style functions. Inside
`Array.prototype.realLength`, this leaked the receiver array into the
caller's argument stack, causing the literal `3` second arg to
`check_equals(_root.buttonChild.realLength(), 3)` to be replaced by
the array. Removed the vestigial PUSH (the surrounding code already
enumerates inline; the PUSH was for an aborted "delegate to Enumerate2"
approach). Internal #passed 158→160 (+2), #failed 6→4 (-2); line-aligned
237/679 (+2). The remaining `key_event_test`/`DragDropTest` gaps are
unrelated subsystems.

2026-05-06 (Phase 1i complete: spurious `script_2` fires on
preserved button-state children eliminated by extending the state-transition
snapshot to capture the grandchild `sprite_display_list` pointer. Internal
test pass count +2 (156→158), failed -2 (8→6); line-aligned count unchanged
at 235/679 (early upstream `realLength()` divergence still present —
separate issue). All 4 spurious fires across 2 OUT→UP transitions are
gone; instance27-30 still blocked by the upstream divergence. See Phase 1i
section below for full diagnosis.

2026-05-05 (Phase 1h complete: bare `getBounds()` calls from inside button event handlers (e.g. SWFBUTTON_MOUSEOVER) now route to the MovieClip method on `g_current_context`. +7 lines (231→235) — 5 bounds checks across testno clusters now PASS, plus 2 downstream lines that were positionally aligned. Remaining gaps: instance numbering drift, exe off-by-one for instance7.

## Summary status (CI at `08e560fe`)

| Test | Suite | Lines | Status | Phase |
|------|-------|-------|--------|-------|
| `button_test1` | misc-swfc.all | **31/31 PASS** | complete | 4 |
| `ButtonEventsTest` | misc-ming.all | **ruffle_matched** (1k complete: OUT_DOWN→effective OVER. Promoted from 237/679 line-aligned `output_mismatch` to full ruffle_matched effective pass.) | complete | 1 |
| `key_event_test` | misc-ming.all | 33/66 (50%) | deferred | 2 |
| `DragDropTest` | misc-ming.all | **ruffle_matched** (Phase 3 complete: level50 default scale + _levelN path resolver. Promoted from 27/44 `output_mismatch` to full ruffle_matched effective pass.) | complete | 3 |

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

#### 1c3 — Event ordering: SWFBUTTON_* fires before frame advance (PARTIAL)

**Original observation.** Test at 58/679 matching. SWFBUTTON_MOUSEOVER
fired on the FIRST MM(60,60) when `testno=0`, emitting
`FAILED: Unexpectedly got SWFBUTTON_MOUSEOVER event (testno:0)`. Ruffle's
expected output skips this entirely.

**Root cause (identified 2026-05-05).** Ruffle's `mouse_pick_avm1` for a
MovieClip returns the MC itself (not its children) when the MC is in
*button mode* — i.e. has any of the BUTTON_EVENT_METHODS handlers
(onRollOver/onRollOut/onPress/onRelease/onReleaseOutside/onDragOver/
onDragOut). See `core/src/display_object/movie_clip.rs:2912-2918`. RollOver
events go to that MC, and the inner button never receives them. Square1
in ButtonEventsTest has `onRollOut` defined in frame 2, so it's
button-mode; Ruffle dispatches RollOver to square1 (which has no
onRollOver handler — silent), and the inner button stays in UP state.

Our impl previously walked into sprites unconditionally inside
`ng_update_button_states_in_dl`, firing SWFBUTTON_MOUSEOVER on the inner
button regardless of whether the parent sprite was button-mode. And
`actionDispatchMCMouseMove` dispatched onRollOver/onRollOut to *every*
MC whose AABB contained the mouse, including button-mode descendants
already shadowed by their parent.

**Fix landed.** Two-part change:

1. `SWFModernRuntime/src/actionmodern/action.c` — added
   `actionMCHasButtonHandlers()` (own-property check for the 7 button-event
   method names) and `actionMCMouseInsidePick()` (mouse-inside-AABB check).

2. `SWFModernRuntime/src/libswf/tag.c` `ng_update_button_states_in_dl` —
   before recursing into a sprite child, if the sprite's MC is button-mode
   AND the mouse is inside its AABB AND no hover has been claimed yet,
   set `*found_hover = 1` and skip recursion (mirrors Ruffle's
   "topmost button-mode MC catches mouse").

3. `actionDispatchMCMouseMove` — added `mc_has_button_mode_ancestor_with_mouse()`
   helper and skips MCs whose ancestor is button-mode AND catching the
   mouse. Prevents inner `square1.button.onRollOver` from firing while
   the parent square1 is the catching object.

After this fix, ButtonEventsTest no longer emits `FAILED: Unexpectedly got
SWFBUTTON_MOUSEOVER event (testno:0)` (verified: zero `Unexpectedly got
SWFBUTTON` lines in actual output). Test progresses through testno=1, 2, 3,
4 logic. Matching went 61 → 62 (small increase because subsequent line
content still diverges for a different reason — see below).

**Synchronous nextFrame() inside event handlers (LANDED at 08e560fe).**

`g_inside_event_handler` counter, incremented around
`mc_call_as2_handler_ng` invocations (input-pump dispatch path for
mouse/focus/onChanged events). When set, `actionNextFrame` at the root
timeline runs `ng_executeGotoCatchUp` inline AND drains the queued
`AQ_KIND_SCRIPT` entries via `actionDrainOnloadAndScript` — the catch-up
wraps `funcs[target]` in drain-suppress; without an outer frame script
caller's drain to pick them up, the target frame's DoAction would queue
but never fire until the next tick.

`actionGotoFrame` at root already runs inline catch-up unconditionally,
so it didn't need a parallel branch.

After the fix, frame 3's `1. Roll over the red square.` note appears at
expected line 59 (was at line ~110 prior). Subsequent state notes
(`2. Press...`, `3. Depress...`, etc.) also align. Match count went
62 → 61 (-1) because incidental drift-matches were lost — strict
positional matching can regress when actual lines shift toward their
correct positions while a separate gap (Phase 1d, for-in enum) keeps
the rest of the output offset by ~19 lines per state. CI verified no
regressions in any other suite.

**Phase 1d (PARTIAL — 2026-05-05): script_2 didn't fire on state transitions.**

Initial framing was wrong: the for-in *did* push 18 properties (8 dyn
+ 10 from Button.prototype + children) — the issue was that `script_2`
(the for-in's host script, which is ermc's frame_0) only ran during
initial UP-state placement. Subsequent button state transitions never
re-fired it because `g_button_state_change_depth` (added for issue_9885
to suppress double-firing of preserved children) gated `actionEagerInitActive()`,
which gates the recompiler-emitted sprite-DoAction queue call. So
sprite_12_frame_0 ran inside button state changes but its
actionQueueSpriteScript gate evaluated false, and script_2 never queued.

**Fix landed.** Implemented Ruffle's `set_state` "child exists in both
states" preservation per-depth instead of suppressing scripts globally:

1. `tag.c` `ng_update_button_states_in_dl` snapshots OLD (depth → char_id,
   instance_name) before clearing dl. Sets `g_btn_state_active=1`,
   removes the `g_button_state_change_depth++` (so scripts queue normally),
   runs state func.

2. `tag.c` `tagPlaceObject2` early gate: if `g_btn_state_active && char_id != 0
   && g_btn_state_old_chars[depth] == char_id`, treat as preserved —
   minimal placement (transform/cxform), keep instance_name (clear left
   it intact), skip `ng_on_place_object2` and all queue_clip_*/eager init.
   Mirrors Ruffle's `child_by_depth(depth).id() == record.id` reuse.

3. After state func, drain `actionDrainOnloadAndScript` so the queued
   script_2 fires synchronously inline rather than waiting for the next
   tagShowFrame (would land many input events later).

Result: ButtonEventsTest 61 → 79 line matches (+18). Verified zero
regressions in: issue_9885 (PASS), 9 button + 4 drag + 13 prototype/lifecycle
+ 2 misc-swfc + 9 enum/prototype tests (all PASS or effective).

### 1e — Transient enumeration of removed button-state children (COMPLETE 2026-05-05)

**Resolved.** ButtonEventsTest now matches 217/679 lines (was 79/679,
+138). Lines 1-78 align cleanly through the first state transition's
for-in (`instance7, instance5, instance6` — including the just-removed
depth-12 ermc as the third entry).

**Implementation (Sketch A from prior plan).** Two changes:

1. `SWFModernRuntime/src/libswf/tag.c` — added `g_btn_transient_dobj`,
   `g_btn_transient_names[256]`, `g_btn_transient_count` globals.
   `ng_update_button_states_in_dl` now strdup's the snapshot names
   (Phase 1d previously stored raw pointers — safe for unused storage,
   but Phase 1e reads them, and tagPlaceObject2 may free the original
   when an owned name is replaced at the same depth). After the state
   func runs (and before `actionDrainOnloadAndScript`), walks the
   snapshot: for each old depth whose new char_id differs (removed or
   replaced), strdup's the old instance_name into `g_btn_transient_names`.

2. `SWFModernRuntime/include/libswf/tag.h` + `tag.c` —
   `ng_iterateTransientButtonChildren(button_dobj, cb, user)` public
   accessor. Returns silently if the dobj doesn't match the most recent
   transitioned button.

3. `SWFModernRuntime/src/actionmodern/action.c` `actionEnumerate2` —
   MOVIECLIP arm now calls `ng_iterateTransientButtonChildren` BEFORE
   the existing display walk (so transient names get pushed first →
   popped LAST, yielding the expected `liveChild1, liveChild2,
   removedChild` order in for-in iteration).

**Why before the display walk.** Stack is LIFO. Display walk pushes
in depth order (low to high) → pops in reverse depth order. To make
the transient name pop last (after both live children), it must be
pushed first. The expected for-in trace `instance7, instance5,
instance6` corresponds to push order `instance6` (transient),
`instance5` (depth 10), `instance7` (depth 12).

**Remaining downstream gaps (not Phase 1e):**

- `_root.buttonChild[N].uld` reads 0 instead of 2 — `onUnload` is not
  firing for transient (just-removed) button-state children. The
  populator's `this.onUnload = function() { ... }` is registered, but
  our impl removes the dl entry immediately (with the strdup'd
  transient list separate); we never invoke onUnload on the removed MC.
  Need to dispatch onUnload during `ng_update_button_states_in_dl`
  state-func wrap-up for each transient child.
- `exe` counter off-by-one for some indices (e.g. 4 obtained vs 3
  expected for instance6) — script_2 may be firing one extra time
  somewhere (likely an artifact of the `actionDrainOnloadAndScript`
  drain landing the queued script alongside an ng_executeGotoCatchUp
  drain or similar). Needs trace at the script_2 entry point.
- Instance numbering drift (e.g. `instance25` ours vs `instance29`
  theirs) — auto-name counter is incrementing differently because
  of the missing onUnload causing reclamation of slot numbers to
  diverge from Flash's allocation pattern. Likely resolves once
  onUnload dispatch lands.

**Verification battery passed (no regressions):**

- AVM1 enum/prototype: enumerate, array_enumerate, new_object_enumerate,
  prototype_enumerate, stage_object_enumerate, prototype_delete,
  prototype_properties, movieclip_prototype_extension,
  recursive_prototypes (9 PASS).
- AVM1 button: mouse_events, mouse_events_visible_enabled, button_v5,
  button_v6, button_children, button_order, button_keypress,
  button_goto, button_key_events, issue_9885 (10 PASS).
- AVM1 lifecycle: unload, register_class, register_and_init_order,
  init_object_order, on_construct, extends_chain, as2_super_and_this_v6,
  as2_super_and_this_v8 (8 PASS).
- Gnash misc-ming: ButtonPropertiesTest, RollOverOutTest (2 PASS).
- Gnash misc-swfc: mouse_drag_test, button_test1 (2 PASS).

#### Original investigation steps (kept for reference)

#### Original investigation steps (kept for reference)

Initial trace approach was: log every SWFBUTTON_* dispatch and AS-level
handler call. That trace immediately revealed the recompiler bug (1c1):
`[BTN_HIT] btn_hit_char_id=12 hit_ch=(nil)` — char 12 was a sprite, not
a shape. Manually re-running SWFRecomp confirmed `tagDefineButton(...,
hit_char_id=12)` before the fix, `hit_char_id=13` after.

### 1f — Transient onUnload dispatch + bias-16383 propagation (COMPLETE 2026-05-05)

**Resolved.** ButtonEventsTest: 217/679 → 228/679 (+11). All
`_root.buttonChild[N].uld` and `[N].exe` assertions on the
preserved-MC paths now PASS. Two coupled fixes:

1. **`SWFModernRuntime/src/libswf/tag.c` `ng_update_button_states_in_dl`:**
   set `g_current_context = button_mc` before invoking
   `button_state_funcs[effective_state]`. tagPlaceObject2's eager-init
   MC creation site (the `_parent_for_mc = g_current_context` path
   around tag.c:4799) had been receiving root (or whatever MC was
   active before the input pump) as the parent for state-change
   placements, which made `findOrCreateMovieClip` skip the
   `parent->is_button_mc` branch and apply bias **16384** instead of
   **16383** to all subsequent button-state child placements
   (instance7, instance8, …). Only the very first placement (during
   the button's eager init at tag.c:4886) had used the right context
   because that block already set `g_current_context = button_mc`.

   Symptom before fix: `instance7.getDepth()` returned `-16371`
   (12-16383? no — 13-16384=-16371) instead of `-16370` (13-16383).
   The script_2 populator's
   `myDepth = getDepth() + 16383 = -16371 + 16383 = 12` (WRONG)
   then overwrote `_root.buttonChild[12]`'s `nam` field with
   `instance7`'s name. Every subsequent UP→OVER state transition's
   ermc placement compounded the drift.

   After fix: all button-state child placements use bias 16383,
   so `getDepth()+16383 == swf_depth_in_button_dl`, and
   `_root.buttonChild[N].nam` populates correctly:
   `[10].nam = instance5`, `[12].nam = instance6`, `[13].nam = instance7`,
   `[14].nam = instance8` (matches Flash exactly).

2. **`SWFModernRuntime/src/libswf/tag.c` `ng_update_button_states_in_dl`:**
   inside the post-state-func transient-walk loop, call
   `actionFireOnUnload(app_context, old_name, swf_depth + 1)` for each
   transient (depth, name) pair whose new char_id differs from old.

   The `+1` adjustment compensates for `actionFireOnUnload`'s
   hardcoded bias-16384 in both the cache lookup (`as_depth =
   swf_depth - 16384`) and the post-shift formula
   (`mc->depth = -(swf_depth) - 1 - 16384`). With bias 16383 in
   placement, `mc->depth` is one greater than the bias-16384 case;
   passing `swf_depth + 1` makes both formulas come out one less,
   so the lookup hits and the post-shift `mc->depth = -swf_depth -
   16386` matches Flash's expected value (the test's
   `myDepth = -(getDepth()+32769-16383)` formula needs exactly this
   value to reverse-compute back to the original SWF depth).

**Remaining gaps in ButtonEventsTest (downstream — see 1g for transient
property access):**

- **`square1.getBounds()` returns `0,0 0,0` after first state
  transition** (expected `-0.05,-0.05 40.05,40.05`). RESOLVED by
  Phase 1h (bare-call dispatch routes `getBounds()` to the active
  MC); local baseline 2026-05-06 confirms `printBounds(square1.getBounds())
  == '-0.05,-0.05 40.05,40.05'` PASSES at testno 5 (line 263).
- **`buttonChild[13].exe == 3` (expected 4) and `[13].uld == 3`
  (expected 4):** RESOLVED by Phase 1k. Root cause was OUT_DOWN
  state 3 mapping to effective UP (0) instead of OVER (1) in
  `ng_update_button_states_in_dl`. Flipping the mapping makes
  the 2→3 DragOut transition place depth 13 (OVER-only ermc)
  and the 3→0 ReleaseOutside transition unload it — adding the
  missing exe/uld pair to depth 13. ButtonEventsTest promoted
  to ruffle_matched.

### 1g — Transient property access on just-removed button-state children (COMPLETE 2026-05-05)

**Resolved.** ButtonEventsTest: 228/679 → 231/679 (+3). Test source
(`ButtonEventsTest.c:238-240`) checks at testno==1:

```as
_root.check_equals(typeof(_level0.square1.button.instance6), 'movieclip');
_root.check_equals(_level0.square1.button.instance6._name, 'instance6');
_root.check_equals(_level0.square1.button.instance6.getDepth(), -16398);
```

After Phase 1f's onUnload dispatch shifts `instance6.depth` to `-16398`
and sets `avm1_removed=1`, the MC stays alive in `child_mc_cache` but
isn't reachable through `actionGetMember`'s normal child-name walks
(those iterate the *live* `sprite_display_list[]`, where the dl entry's
char_id no longer matches the removed child's). Phase 1e wired up
for-in via `g_btn_transient_names[]`; Phase 1g extends the same window
to direct property access.

**Implementation.** Two changes:

1. `SWFModernRuntime/include/libswf/tag.h` + `SWFModernRuntime/src/libswf/tag.c` —
   added `ng_isTransientButtonChildName(button_dobj, name, name_len)`,
   a direct-lookup companion to `ng_iterateTransientButtonChildren`.
   Returns 1 iff the receiver is the most-recently-transitioned button
   AND the name matches one of the transient entries.

2. `SWFModernRuntime/src/actionmodern/action.c` `actionGetMember`
   MOVIECLIP arm — after both display-list walks (display_obj-local
   and root-level fallback) miss, gate on
   `ng_isTransientButtonChildName(mc->display_obj, prop_name, ...)`.
   On hit, walk `child_mc_cache[]` for an entry where `parent==mc`,
   `depth!=INT_MIN`, and `swf_name_match(name, prop_name)`. The walk
   intentionally allows `avm1_removed=1` (the relaxation we need),
   but the gate scopes it to the active transient window only — other
   unload-sensitive paths see no behavior change.

**Why this is safe.** The `avm1_removed` allowlist is gated on three
conjuncts: (a) `mc->display_obj == g_btn_transient_dobj` (only the
transitioned button), (b) `prop_name` is in `g_btn_transient_names[]`
(only just-removed names), (c) `_tc->parent == mc` (no
cross-button/cross-parent resolution). After
`actionFinalizePendingRemovals` runs at the next frame start,
`depth==INT_MIN` shuts the window — the early-return at the start of
the MOVIECLIP arm (`mc->depth == INT_MIN → undefined`) handles
follow-up access on the receiver, and the cache walk's
`depth==INT_MIN` skip handles follow-up on the resolved transient.

**typeof works without a separate path.** `actionTypeof`'s MOVIECLIP
case checks `mc->is_button_mc` (false for ermc sprite),
`MC_IS_TEXTFIELD` (false), and `ng_findDisplayEntryByName` (returns
SIZE_MAX for the removed name, so the "not a sprite at depth" override
doesn't fire). Falls through to "movieclip". Verified against test's
`typeof(...) == 'movieclip'` assertion.

**Verification battery passed (no regressions):**

- AVM1 lifecycle: unload, register_class, register_and_init_order,
  init_object_order, on_construct, extends_chain,
  as2_super_and_this_v6, as2_super_and_this_v8 (8/8 PASS).
- AVM1 button: mouse_events, mouse_events_visible_enabled, button_v5,
  button_v6, button_children, button_order, button_keypress,
  button_goto, button_key_events, issue_9885 (10/10 PASS).
- AVM1 enumeration: enumerate, array_enumerate, new_object_enumerate,
  prototype_enumerate, stage_object_enumerate, prototype_delete,
  prototype_properties, movieclip_prototype_extension,
  recursive_prototypes (9/9 PASS).
- Gnash misc-ming: ButtonPropertiesTest, RollOverOutTest (2/2
  effective).
- Gnash misc-swfc: mouse_drag_test, button_test1,
  movieclip_destruction_test2 (3/3 PASS).

### 1h — Bare-call MC method dispatch (getBounds/getRect from button event handlers) (COMPLETE 2026-05-05)

**Resolved.** ButtonEventsTest: 231/679 → 235/679 (+7). Test source
emits `_root.printBounds(getBounds())` inside SWFBUTTON_MOUSEOVER /
MOUSEDOWN / MOUSEUP / etc. handlers — bare `getBounds()` (no
explicit receiver) intended to resolve to the button's parent
context's MovieClip method.

**Diagnosis.** Stderr-instrumented `actionCallFunction` showed
`getBounds` arriving via the `actionCallFunction` path (not
`actionCallMethod`) for every button-event invocation, with
`g_current_context = square1`. The `_is_mc_nav` block at action.c
~51237 already handles bare `gotoAndStop`/`stop`/`play`/etc. for
similar reasons but didn't include `getBounds` or `getRect`. Without
a dispatch, scope walk found the MovieClip.prototype `getBounds`
stub (function_type=1, simple_func=NULL), fell through to "Built-in
constructor as plain function," and pushed undefined.
`printBounds(undefined)` then yielded `0,0 0,0` — every bounds
assertion across testno clusters failed.

**Implementation.** `SWFModernRuntime/src/actionmodern/action.c`
`actionCallFunction`, immediately after the `_is_mc_nav` block:
when the unhandled bare name is `getBounds` or `getRect` and
`g_current_context != NULL`, synthesize the `actionCallMethod`
stack and delegate. Re-pushes args (in reverse-of-popped order so
`actionCallMethod`'s `popVar` recovers the same indices), pushes
`num_args`, the receiver MC, and the method name; calls
`actionCallMethod` and returns directly. Limited to these two
methods to keep the relaxation narrow.

**Why this is safe.** The dispatch is gated on (a)
`!builtin_handled` so the existing `_is_mc_nav` cases still win,
(b) the name being one of two specific MC methods, (c)
`g_current_context != NULL`. User-defined globals named
`getBounds` are extremely unlikely to coexist with this dispatch in
practice (and none appear in the regression battery). For ordinary
explicit calls (`mc.getBounds()` via `actionCallMethod` directly),
this code path is bypassed entirely.

**Verification battery passed (no regressions):**

- AVM1 lifecycle: unload, register_class, register_and_init_order,
  init_object_order, on_construct, extends_chain,
  as2_super_and_this_v6, as2_super_and_this_v8 (8/8 PASS).
- AVM1 button: mouse_events, mouse_events_visible_enabled, button_v5,
  button_v6, button_children, button_order, button_keypress,
  button_goto, button_key_events, issue_9885 (10/10 PASS).
- AVM1 enum + drag: enumerate, array_enumerate, new_object_enumerate,
  prototype_enumerate, stage_object_enumerate, prototype_delete,
  prototype_properties, movieclip_prototype_extension,
  recursive_prototypes, drag_drop, drag_over_from_outside,
  drag_over_without_startdrag, mouse_hover_events_while_dragging
  (13/13 PASS).
- Gnash misc-ming: ButtonPropertiesTest, RollOverOutTest (2/2
  effective).
- Gnash misc-swfc: mouse_drag_test, button_test1,
  movieclip_destruction_test2 (3/3 PASS).

### 1i — Instance-numbering drift in ButtonEventsTest (COMPLETE 2026-05-06)

**Resolved.** ButtonEventsTest line-aligned: 235/679 (unchanged — see "Why
the line-aligned count didn't move" below). Internal test pass count:
156→158 PASSED (+2), 8→6 FAILED (-2). All 4 spurious `script_2` fires
across 2 OUT→UP preserved-only state transitions are eliminated.

**Root cause.** `ng_update_button_states_in_dl` at the start of every
state transition runs a "Clear existing children" loop (`tag.c` ~1845)
that frees `obj->sprite_display_list[j].sprite_display_list` (the
grandchild display-list array) for every child. The Phase 1d preserved
branch in `tagPlaceObject2` (`tag.c` ~4280) restores `char_id`,
`transform_id`, etc. but does NOT re-allocate the grandchild
`sprite_display_list`. On the next tick, `advance_sprite_frames` recurses
into the button's children, finds the preserved sprite at depth N with
`sprite_display_list == NULL`, hits the `just_allocated = 1` branch
(`tag.c` ~795), and unconditionally calls `sprite_frame_funcs[0]`. For
ermc (the events-reporting MC), that frame func is the recompiler-emitted
`sprite_12_frame_0`, which calls `actionQueueSpriteScript(script_2)` —
producing the spurious for-in trace and `_root.buttonChild[N].exe++`
double-increment. The earlier hypothesis (stale `AQ_KIND_SCRIPT` queue
entries leaking past their owning drain) was wrong; the leak is
*upstream* of the queue, in the per-tick sprite advance.

**Why only after OUT→UP (3→0) preserved-only transitions.** Within an
input-event group (no Wait between events), state transitions fire
back-to-back without an intervening `advance_sprite_frames` pass — so
fresh-placement transitions also temporarily null `sprite_display_list`,
but the next transition's clear loop frees the (just-allocated) old
pointer cleanly before any spurious advance happens. Only when a
preserved-only transition is the LAST transition before a tick boundary
does `advance_sprite_frames` see the nulled pointers and re-init. In
ButtonEventsTest's input sequence, that's the OUT→UP transition that
ends each "press inside, drag outside, release outside" cycle.

**Mechanism (one-paragraph mental model).** Snapshot extension. The
clear loop captures the grandchild `sprite_display_list` pointer (and
its `sprite_max_depth`/`sprite_dl_capacity`/`sprite_initialized`/
`sprite_current_frame`/`sprite_is_playing` per depth) into the existing
`g_btn_state_old_*` snapshot before nulling the dl entry. The clear
loop no longer frees the grandchild pointer — the snapshot owns it
until either (a) the preserved branch in `tagPlaceObject2` consumes
it (re-attaching to the dl entry and nulling the snapshot slot), or
(b) the post-state-func cleanup loop frees the unconsumed snapshot
entries (depths the new state placed differently or didn't touch at
all).

**Files touched.**

- `SWFModernRuntime/src/libswf/tag.c`:
  - Snapshot globals (~`tag.c:206-220`): added
    `g_btn_state_old_sprite_dl[]`, `g_btn_state_old_sprite_max[]`,
    `g_btn_state_old_sprite_cap[]`, `g_btn_state_old_sprite_init[]`,
    `g_btn_state_old_sprite_cf[]`, `g_btn_state_old_sprite_playing[]`.
  - Snapshot capture loop (`ng_update_button_states_in_dl`,
    ~`tag.c:1822`): capture grandchild dl + per-sprite advance state
    per depth.
  - Clear loop (~`tag.c:1845`): drop the FREE on grandchild
    `sprite_display_list`; null the dl entry's pointer fields only.
    Snapshot is now the authoritative owner.
  - Post-state-func cleanup (after state func returns,
    pre-transient-walk): free any snapshot grandchild pointers whose
    depth was NOT consumed by the preserved branch (the preserved
    branch nulls the snapshot slot when it consumes one).
  - `tagPlaceObject2` preserved branch (~`tag.c:4296`): restore
    grandchild `sprite_display_list` + per-sprite advance state from
    snapshot; null the snapshot slot to mark consumed.

**Why the line-aligned count didn't move.** The pre-fix actual output
was 694 lines vs 622 lines post-fix — the 72-line reduction is the
spurious for-in dumps being eliminated. Both pre- and post-fix have
the same upstream divergence at expected line 79 (a separate
`Array.prototype.realLength()` comparison-stringification issue —
`_root.buttonChild.realLength()` is being stringified instead of
called as a function — outside Phase 1i's scope). That early
divergence shifts every later position. The fix corrects 2 specific
internal assertions (`buttonChild[10].exe == 1` and
`buttonChild[12].exe == 5` were FAILED with off-by-one counts pre-fix,
both now PASS) but they fall at different positions vs expected after
the spurious-dump removal, so the line-aligned `m/n` metric doesn't
capture the gain. The internal `#passed` count went 156→158 (+2),
`#failed` went 8→6 (-2).

**Why instance27-30 didn't get allocated.** The auto-name counter
reaches `instance27` both pre- and post-fix. The remaining 3
instances (28-30) are blocked by an earlier-in-the-test divergence,
not by the spurious script_2 fires. Likely the same `realLength`
upstream issue; tracked separately.

**Verification battery passed (no regressions):**

- AVM1 lifecycle: unload, register_class, register_and_init_order,
  init_object_order, on_construct, extends_chain,
  as2_super_and_this_v6, as2_super_and_this_v8 (8/8 PASS).
- AVM1 button: mouse_events, mouse_events_visible_enabled, button_v5,
  button_v6, button_children, button_order, button_keypress,
  button_goto, button_key_events, issue_9885 (10/10 PASS).
- AVM1 enum + drag: enumerate, array_enumerate, new_object_enumerate,
  prototype_enumerate, stage_object_enumerate, prototype_delete,
  prototype_properties, movieclip_prototype_extension,
  recursive_prototypes, drag_drop, drag_over_from_outside,
  drag_over_without_startdrag, mouse_hover_events_while_dragging
  (13/13 PASS).
- Timeline / sprite-init: execution_order2, execution_order3,
  goto_execution_order2, goto_rewind3 (4/4 PASS),
  consecutive_goto_frame_test (1/1 PASS).
- Gnash misc-ming: ButtonPropertiesTest, RollOverOutTest (2/2
  effective).
- Gnash misc-swfc: mouse_drag_test, button_test1,
  movieclip_destruction_test2 (3/3 PASS).

#### Original investigation steps (kept for reference)


**Symptoms.** Beginning at testno=6, our auto-name allocator drifts
behind Flash's: where Flash sees `instance15, instance5, instance14`
(testno=6's MOUSEOVER for-in), we produce `instance13, instance5`
twice in succession — same name reused, no transient. The drift
cascades through every later testno cluster, leaving instance27–30
entirely absent from our output (Flash references them 7 times
total).

**Empirical findings (BET_DIAG instrumentation in
`tag.c::ng_update_button_states_in_dl` + recompiler-emitted
`script_2.c`):**

- 24 button state transitions fire across the test's 38 input
  events (`old=0..3 new=0..3` log lines).
- Of these, 3 are "OUT→UP preserved-only" transitions
  (`old=3 new=0` with btn_dn=0): every dl entry is preserved by
  Phase 1d's `g_btn_state_active && old_chars[depth] == char_id`
  branch, so the state func queues NO new scripts.
- Yet `script_2` fires **27 times** — 4 more than the simple
  model predicts (21 transition-driven + 2 initial = 23).
- The extras cluster at exactly the OUT→UP boundaries: each
  preserved-only transition is followed by 2 `script_2` fires
  before the next state func places anything. So every preserved
  transition yields 2 spurious for-ins, all producing the
  current-state's live-children name list (no transient — the
  transient list was already consumed by the prior transition's
  drain).

**Hypothesis.** Phase 1d's preserved branch correctly suppresses
script queueing for the current placement, but some queue entries
from a *prior* transition's state func remain in the
`AQ_KIND_SCRIPT` queue past their owning transition's
`actionDrainOnloadAndScript` call. They get drained during the
preserved transition's drain (or during a subsequent
`tagShowFrame` / mouse-event drain), generating extra `script_2`
firings that re-iterate the for-in over the now-stale child list.
This in turn leaves `g_btn_transient_*` empty (already consumed),
producing the "2-entry for-in, no transient" pattern observed in
actual output lines 282-302.

**Why "instance-numbering drift" is misleading framing.** The
auto-name counter is correct — each fresh ermc placement does
allocate a new instance name (verified via `placeobj2-fresh
char=12` log lines: 21 fresh state-driven + 2 initial = 23 fresh
ermc placements, matches Flash's expected count). What's wrong
is that we fire `script_2` *more* times than we have fresh
placements, and each extra fire repeats the for-in for whichever
ermc was most recently placed. The "drifted" names in the for-in
output are just the same names re-traced.

**Where to look for the fix.**

1. `SWFModernRuntime/src/libswf/tag.c::ng_update_button_states_in_dl`
   — `actionDrainOnloadAndScript` is called at the end of the
   state-active block. Verify it drains *only* scripts queued by
   the current state func — not leftovers from earlier transitions.
2. `SWFModernRuntime/src/libswf/tag.c::tagShowFrame` and
   `swf_core.c::dispatch_input_event` — these also drain. Check
   whether they re-fire `script_2` from queue entries that should
   have been consumed by an earlier transition.
3. The recompiler-emitted `script_2.c` ends up in
   `process_sprite_needs_init` (depth-12/13/14 fresh placement) AND
   in the AQ_KIND_SCRIPT queue (via `actionQueueSpriteScript` from
   inside the recompiler-emitted bytecode). Either path firing
   redundantly would account for the extras.

**Repro.** `BET_DIAG=1` env var, plus add `fprintf(stderr,
"[BET][script_2] enter\n")` at the top of `script_2.c` (note that
`rm -rf RecompiledScripts/` regenerates and discards the diag).
Add `[BET][btn-trans]` log inside the state-transition gate at
`tag.c:1929` and `[BET][placeobj2-fresh|preserved]` logs around
the preserved branch at `tag.c:4280`. Sequential `nl`-numbered
output makes the drift cluster visible at OUT→UP boundaries.

**Estimated effort.** 4-8 hours: needs trace of the AQ_KIND_SCRIPT
queue during the OUT→UP transition to identify what's leaking
through. Higher-leverage than ButtonEventsTest's other remaining
gaps (~exe off-by-one is a tighter scope).

### 1j — `realLength` upstream divergence at expected line 79 (COMPLETE 2026-05-06)

**Resolved.** ButtonEventsTest line-aligned: 235/679 → 237/679.
Internal `#passed: 158→160 (+2)`, `#failed: 6→4 (-2)`. The
divergence was on the simple-form `check_equals(_root.buttonChild.realLength(), N)`
calls (expected lines 79, 115, etc.) where actual output showed
`FAILED: expected: ,,,,,,,,,,[object Object],,[object Object],[object Object] , obtained: 3`
— the literal `N` second arg of check_equals was being replaced by
the receiver array.

**Root cause.** Vestigial `PUSH(arr_var.type, arr_var.data.numeric_value)`
at the top of `actionEnumerate`'s ARRAY arm
(`SWFModernRuntime/src/actionmodern/action.c` ~line 25420). The
surrounding code already enumerates the array inline (UNDEFINED
terminator + numeric indices + arr->props names), and the comments
admit the PUSH was vestigial from an aborted "delegate to
Enumerate2" approach: `// Remove the value we just pushed and call
enumerate2 manually / Actually, just push undefined terminator and
enumerate the array inline`. The PUSH was supposed to be
consumed by an `actionEnumerate2` call that never landed; the
inline enumeration that replaced it doesn't pop the array, so the
array entry persisted on the stack across the entire `for` loop
and the function's return.

**Mechanism.**
`Array.prototype.realLength = function() { var c=0; for (var i in
this) if (Number(i)==i) ++c; return c; }` — defined as
`DefineFunction` (SWF5-style), so AS2's `for-in` lowers to the
`Enumerate` opcode (not `Enumerate2`). When called as
`buttonChild.realLength()`, the ARRAY arm of `actionCallMethod`
binds `this` to the array and dispatches the simple_func.
`Enumerate "this"` resolves to the array, takes the ARRAY branch,
and pushes the array (vestigial) + UNDEFINED terminator + numeric
indices. The loop consumes K+1 stack entries (one per index plus
the terminator), but never the leading array. After the function
returns its `c` value, the ARRAY arm pushes the result on top of
the stranded array.

The caller (`button_10_action_4` for SWFBUTTON_MOUSEOVER) had
pushed `3` (the literal expected value) BEFORE the realLength
call, then receiver/method-name and called CallMethod. Stack
post-realLength (top→bottom): `[result=3, leftover=array,
literal=3, ...]`. The next `_root.check_equals(realLen_result, 3)`
CallMethod popped name/receiver/num_args=2, then args[0] = top =
realLen result (3), args[1] = next = the leftover array. So
check_equals received `obt=3, exp=array` — emitting `FAILED:
expected: <array> , obtained: 3`.

**Fix.** Removed the vestigial `PUSH(arr_var.type, ...)` line.
The inline enumeration that follows is already correct (matches
the standard Enumerate post-condition: pops the variable name,
pushes UNDEFINED terminator + keys).

**Why didn't this break anything else.** The bug only manifests
when:
1. A SWF5-style `for-in` (Enumerate, not Enumerate2) iterates an array.
2. Code after the for-in implicitly relies on stack discipline being
   preserved (e.g. the for-in is inside a function whose result feeds
   another function call).

Most AS2 code uses Enumerate2 (`DefineFunction2`/SWF6+), where this
arm is never hit. Existing tests that use `for-in` on arrays via
SWF5-style functions (Gnash test harness's
`Array.prototype.realLength`/`isUndefined` patterns) showed the
same bug but at lower-leverage call sites where the stranded array
got harmlessly popped before causing visible damage.

**Files touched.**
`SWFModernRuntime/src/actionmodern/action.c` `actionEnumerate`
ARRAY arm — removed 4 lines (the PUSH + two stale comments + the
unused `ActionVar arr_var = *var;`).

**Verification battery passed (no regressions):**

- AVM1 lifecycle: unload, register_class, register_and_init_order,
  init_object_order, on_construct, extends_chain,
  as2_super_and_this_v6, as2_super_and_this_v8 (8/8 PASS).
- AVM1 button: mouse_events, mouse_events_visible_enabled, button_v5,
  button_v6, button_children, button_order, button_keypress,
  button_goto, button_key_events, issue_9885 (10/10 PASS).
- AVM1 enum + drag: enumerate, array_enumerate, new_object_enumerate,
  prototype_enumerate, stage_object_enumerate, prototype_delete,
  prototype_properties, movieclip_prototype_extension,
  recursive_prototypes, drag_drop, drag_over_from_outside,
  drag_over_without_startdrag, mouse_hover_events_while_dragging
  (13/13 PASS).
- Timeline / sprite-init: execution_order2, execution_order3,
  goto_execution_order2, goto_rewind3 (4/4 PASS).
- SWF5-specific: swf5_to_6_cross_call, swf5_no_closure,
  as2_super_via_manual_prototype, set_interval, goto_frame,
  goto_frame2, goto_label, goto_methods (8/8 PASS).
- Gnash misc-ming: ButtonPropertiesTest, RollOverOutTest,
  consecutive_goto_frame_test (3/3 effective PASS).
- Gnash misc-swfc: mouse_drag_test, button_test1,
  movieclip_destruction_test2 (3/3 PASS).
- Gnash actionscript Inheritance v5/v6/v7/v8 + Global v6/v7/v8
  (7/7 effective PASS).

### 1k — OUT_DOWN button state shows OVER children (COMPLETE 2026-05-06)

**Resolved.** ButtonEventsTest promoted from `output_mismatch` (237/679
line-aligned) to **`ruffle_matched`** — full effective pass on the
misc-ming.all suite. This addresses the `buttonChild[13].exe == 4 vs 3`
and `[13].uld == 4 vs 3` off-by-one originally listed under Phase 1f
"remaining gaps."

**Root cause.** Our button state machine has 4 internal states:
0=UP, 1=OVER, 2=DOWN (over+pressed), 3=OUT_DOWN (outside+pressed,
"tracking"). Flash-defined button records carry state masks for UP,
OVER, DOWN, HIT — there is no native OUT_DOWN frame, so we map state 3
to one of {0,1,2} for placement (`effective_state` at `tag.c:1855`).
The previous mapping was `state 3 → effective 0 (UP)` (comment said
"outDown shows up"), but Ruffle's `core/src/display_object/avm1_button.rs`
`event_dispatch` shows the correct mapping: `ClipEvent::DragOut`
(transition 2→3 in our model) sets `ButtonState::Over`, meaning the
button visually stays in OVER state while tracking a press across a
drag-out — Flash's "Push tracking" semantics.

**Mechanism (testno-5 trace, ButtonEventsTest cycle 1).** Cycle 1
(events 0-14) fires 8 state transitions on the inner button MC after
`square1.onRollOut` deletes itself:

| Event | Cursor | Pressed | Old | New | Effective old → new (pre-fix) | Effective old → new (post-fix) |
|-------|--------|---------|-----|-----|-------------------------------|--------------------------------|
| E5    | inside  | no  | 0 | 1 | UP→OVER     | UP→OVER     |
| E6    | inside  | yes | 1 | 2 | OVER→DOWN   | OVER→DOWN   |
| E7    | inside  | no  | 2 | 1 | DOWN→OVER   | DOWN→OVER   |
| E8    | outside | no  | 1 | 0 | OVER→UP     | OVER→UP     |
| E11   | inside  | no  | 0 | 1 | UP→OVER     | UP→OVER     |
| E12   | inside  | yes | 1 | 2 | OVER→DOWN   | OVER→DOWN   |
| E13   | outside | yes | 2 | 3 | DOWN→**UP**     | DOWN→**OVER**   |
| E14   | outside | no  | 3 | 0 | **UP**→UP (no-op) | **OVER**→UP |

The two changes at the bottom: pre-fix, E13 (DragOut) placed depth-12
(UP-only) child and unloaded depth-14 (DOWN-only); E14 (ReleaseOutside)
was effectively no-op since both 3 and 0 mapped to UP. Post-fix, E13
places depth-13 (OVER-only) child and unloads depth-14, then E14 unloads
depth-13 and places depth-12. Net: depth 13 gains one extra exe + one
extra uld, exactly the off-by-one Flash expects.

**Files touched.**

- `SWFModernRuntime/src/libswf/tag.c` `ng_update_button_states_in_dl`
  at `tag.c:1855`: changed `effective_state = (new_state == 3) ? 0 : new_state`
  to `... ? 1 : new_state` with comment.
- `SWFModernRuntime/src/libswf/tag.c` at `tag.c:2891` (button fresh-init
  fallback site): mirror change for consistency.

**Why this is safe (regression battery — all PASS):**

- AVM1 button: `mouse_events`, `mouse_events_visible_enabled`,
  `mouse_hover_events_while_dragging`, `button_keypress`,
  `button_keypress_vs_press`, `button_keypress_vs_tab`,
  `button_keypress_vs_textinput`, `button_v5`, `button_v6`,
  `button_children`, `button_order`, `button_goto`,
  `button_key_events`, `issue_9885`, `button_properties_special_cases`
  (15/15).
- AVM1 lifecycle/scope: `unload`, `register_class`,
  `register_and_init_order`, `init_object_order`, `on_construct`,
  `extends_chain`, `as2_super_and_this_v6/v8`,
  `register_class_return_value`, `as2_super_via_manual_prototype`,
  `closure_scope` (10/10).
- AVM1 timeline / sprite-init / set_interval: `goto_rewind3`,
  `execution_order2`, `execution_order3`, `set_interval` (4/4).
- AVM1 enumeration + drag: `enumerate`, `array_enumerate`,
  `prototype_enumerate`, `drag_drop`, `drag_over_from_outside`,
  `drag_over_without_startdrag` (6/6).
- AVM1 mouse / focus: `focus_mouse`, `focus_mouse_focusable`,
  `focus_mouse_rollout`, `mouse_listeners`, `tab_ordering_events_mouse`
  (5/5).
- Gnash misc-ming: `ButtonPropertiesTest`, `RollOverOutTest` (2/2
  effective).
- Gnash misc-swfc: `mouse_drag_test`, `button_test1`,
  `movieclip_destruction_test2` (3/3 PASS).
- Gnash actionscript: `Inheritance-v5/v6/v7/v8` (4/4 ruffle_matched
  effective).

DragDropTest and key_event_test (Phases 2, 3) remain at their existing
deferred line counts — neither regressed nor improved (expected, since
their failures are in unrelated subsystems per the plan).

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

## Phase 3 — DragDropTest `_level50` droptarget — COMPLETE 2026-05-06

**Resolved.** DragDropTest promoted from `output_mismatch` (27/44) to
`ruffle_matched` — full effective pass on misc-ming.all. Two narrow fixes:

### 3a — Default identity transform on `_levelN` MCs

`getOrCreateLevel` (`action.c:18341`) HCALLOCs the level MC, leaving
`xscale = yscale = 0`. This made `getLocalMatrixForMC` for the level
return a matrix with `a=b=c=d=0` (det=0), which propagated to all
level-rooted descendants via `getConcatMatrixForMC`. In
`actionFindDynamicDropTarget`, the `det == 0.0` early-exit then
silently skipped all `_level50.targetN` candidates, leaving
`_droptarget = ""` for the second-cluster click positions in
DragDropTest tests 5/6/7.

**Fix.** Set `mc->xscale = mc->yscale = 100` in `getOrCreateLevel`
so the level acts as identity. Required because the previous
sub-phase 3a hypothesis (walk `g_levels[]`) was already partially
correct — the cache contains the level descendants, but the world
matrix path was broken.

### 3b — `_levelN` (N > 0) handler in slash-path resolvers

`resolveSlashPathToMC` and `resolveFlashPathToMC` only special-cased
`_root` and `_level0`. For paths like `_level50/target10` (emitted by
`actionFindDynamicDropTarget` after 3a's fix and read back by
`eval(_root.draggable50._droptarget)`), the first segment `_level50`
fell through to named-child resolution, didn't match anything, and
the resolver returned NULL — surfacing as `obtained: _level50`
(plain variable lookup) instead of `_level0.square1.button.instance7`.

**Fix.** Both resolvers now detect `_levelN` segments (N > 0,
all-digit suffix) and resolve them to `g_levels[N]`. Applies to
both first-segment and subsequent-segment positions in
`resolveFlashPathToMC` (since `eval()` calls it with
`first_element=0`).

**Files touched.**

- `SWFModernRuntime/src/actionmodern/action.c` `getOrCreateLevel`
  (~`action.c:18341`): default identity transform.
- `SWFModernRuntime/src/actionmodern/action.c` `resolveSlashPathToMC`
  (~`action.c:17738`): `_levelN` segment handler.
- `SWFModernRuntime/src/actionmodern/action.c` `resolveFlashPathToMC`
  (~`action.c:18011`): `_levelN` segment handler (both first and
  subsequent positions).

**Why this is safe (regression battery — all PASS):**

- AVM1 button (15): mouse_events, mouse_events_visible_enabled,
  mouse_hover_events_while_dragging, button_keypress (3 variants),
  button_v5/v6, button_children, button_order, button_goto,
  button_key_events, issue_9885, button_properties_special_cases.
- AVM1 drag + path (9): drag_drop, drag_over_from_outside,
  drag_over_without_startdrag, mouse_hover_events_while_dragging,
  path_string, tell_target, tell_target_invalid (2 variants),
  target_path.
- AVM1 timeline / scope / enum (15): swf5_to_6_cross_call,
  swf5_no_closure, as2_super_via_manual_prototype, goto_frame,
  goto_frame2, goto_label, goto_methods, set_interval, goto_rewind3,
  execution_order2/3, enumerate, array_enumerate,
  prototype_enumerate, stage_object_enumerate.
- AVM1 loadmovie (4 PASS, 1 pre-existing MISMATCH): loadmovie,
  loadmovie_fail, loadmovie_flashvars, loadmovie_method, load_vars
  (load_vars MISMATCH was already present pre-fix, not a regression).
- Gnash misc-ming: ButtonEventsTest, ButtonPropertiesTest,
  RollOverOutTest, DragDropTest (4/4 effective).
- Gnash misc-swfc: mouse_drag_test, button_test1,
  movieclip_destruction_test2 (3/3).
- Gnash misc-mtasc: levels (1/1 effective).
- Gnash actionscript: Inheritance-v5/v6/v7/v8, Global-v6/v7/v8 (7/7
  effective).

### Original investigation notes (kept for reference)

Status pre-fix: `27/44 (61%)`. Lines 1-15 PASS, 16-23 FAIL on
`_level50/*`, 24-32 PASS (`/loadedTarget/*` works), 34-41 FAIL on
later tests.

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
