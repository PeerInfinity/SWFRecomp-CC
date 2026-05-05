# Button Residual Plan

<!-- TESTS: ButtonEventsTest, key_event_test, DragDropTest, button_test1 -->

<!-- PLAN_META
id: BUTTON_RESIDUAL
status: pending
phases:
  - id: 1
    name: "ButtonEventsTest residual lines"
    status: partial
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

Last updated: 2026-05-05 (post-pipeline run `25393090111`).

## Summary status (CI at `91999a7c`)

| Test | Suite | Lines | Status | Phase |
|------|-------|-------|--------|-------|
| `button_test1` | misc-swfc.all | **31/31 PASS** | complete | 4 |
| `ButtonEventsTest` | misc-ming.all | 48/679 (~7%) | partial | 1 |
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
output is 81 lines (matches lines 1-10, then diverges and stops at line 81
because the test rolls over silently after one assertion fails). To make
progress we need to fix the *first* divergence cluster (lines 43-51) which
unblocks the test's onward progression.

### 1a — `_root.buttonChild` array population (lines 43-51, 9 lines)

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

### 1b — `getDepth()` off-by-1 for SWF-depth-12 button child (line 53, 1 line)

`_level0.square1.button.instance6.getDepth() == -16371` expected, our impl
returns `-16372`. Ruffle ALSO returns `-16372` (line 89 of
`output.ruffle.txt` is `FAILED: expected: -16371 obtained: -16372`). So
this is a **Ruffle-vs-Flash difference**, not our bug.

**Action.** Once 1a lands and unblocks the test progression: classify this
under `RUFFLE_VS_FLASH_DIFFERENCES.md` (Flash returns `swf_depth - 16383`
for a button-state UP-only child placed via `SWFButtonRecord`; Ruffle and
ours return `swf_depth - 16384` consistently with the standard
`AVM_DEPTH_BIAS = 16384`). The test promotes to ruffle_matched if 1a +
1c land, since our ⊆ Ruffle's diffs at that point.

**Note on asymmetry.** `_root.buttonChild[10]` (the ALL-states child at
SWF-depth 10) — Ruffle's PASS confirms `getDepth = -16373 = 10 - 16383`
for that child. So Flash uses bias 16383 for both; Ruffle's button-state
child depths use bias 16384 for the depth-12 (UP-only) entry but 16383
for the depth-10 (ALL-states) entry. That asymmetry is *Ruffle's* quirk —
not something we need to replicate or fix.

### 1c — Test progression divergence (lines 59+)

After line 58 PASSES (`hitTest(60, 60, true)`), the test enters the
mouse-event-driven phase: `input.json` has 38 events (14 MouseMove + 9
MouseDown + 9 MouseUp + 6 Wait), and the test expects 15 sequential
sub-tests gated by `_root.testno` (1, 2, 3, …, 15). Each sub-test fires
on a specific button event (RollOver/RollOut/Press/Release).

**Observed.** Lines 59-81 of our output show repeated `PASSED: / == /`
lines — the SWFBUTTON_MOUSEOVER handler's `_target == '/'` checks fire
many times, suggesting our button state machine fires MOUSEOVER repeatedly
without advancing `testno`. Eventually output stops at line 81 (~62
spurious PASSED lines + the original 19 prefix lines that matched).

**Subordinate to 1a.** Until buttonChild populates correctly, the test
cannot proceed past frame 2 in any meaningful way — `testno` advancement
is gated on the buttonChild assertions passing. So 1c is downstream of 1a
and cannot be diagnosed in isolation. Re-evaluate after 1a lands.

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

**Root cause.** `ng_compute_droptarget` in `tag.c` walks two location
sets:

1. `display_list` (root timeline) via `find_drop_target_in_dl`.
2. Dynamic MCs (createEmptyMovieClip / duplicateMovieClip / attachMovie)
   via `actionFindDynamicDropTarget`.

It does NOT iterate `g_levels[1..MAX_LEVELS]`. So when `loadMovieNum(url,
50)` loads a SWF into level 50, the contents of `_level50.target10`,
`_level50.target20`, etc. are present in `g_levels[50]->display_obj`'s
display list but never searched by droptarget computation.

The "loadedTarget" cluster works because that's `loadedTarget.loadMovie(...)`
— it loads into a NAMED sprite at `_root.loadedTarget`, which IS in
`display_list` and is reached by the existing static walk.

**Path format.** Test expects `_level50/target10` — a `_levelN/path`
prefix, distinct from `/path` for level 0. Ruffle's `MovieClip::path()`
returns this format for level-rooted clips. Our `mcToDotBasePath`
already handles `_levelN` for level roots; we need to apply the same
formatting to drop-target paths from level walks.

### 3a — Walk levels in `ng_compute_droptarget`

Add a third location set: iterate `g_levels[1..MAX_LEVELS]`, and for each
non-NULL level, call a level-aware variant of
`find_drop_target_in_dl` that produces paths starting with `_levelN/`
instead of `/`. The level's `display_obj` carries its own display list
(populated when `actionFirePendingDirectLoads` runs the level's frame_0
during the next-tick async load).

Skeleton:

```c
int ng_compute_droptarget(...)
{
    // Existing: static root display_list walk (paths "/x")
    if (find_drop_target_in_dl(display_list, max_depth, ..., out_path, out_size))
        return 1;
    // Existing: dynamic MCs
    if (actionFindDynamicDropTarget(...))
        return 1;
    // NEW: walk levels 1..N
    extern MovieClip* g_levels[];
    for (int lv = 1; lv < MAX_LEVELS; lv++) {
        MovieClip* lmc = g_levels[lv];
        if (lmc == NULL || lmc->display_obj == NULL) continue;
        DisplayObject* lvl_dl = ((DisplayObject*)lmc->display_obj)->sprite_display_list;
        size_t lvl_max = ((DisplayObject*)lmc->display_obj)->sprite_max_depth;
        if (lvl_dl == NULL) continue;
        char level_prefix[16];
        snprintf(level_prefix, sizeof(level_prefix), "_level%d", lv);
        if (find_drop_target_in_dl(lvl_dl, lvl_max,
            0.0f, 0.0f, stage_x_twips, stage_y_twips,
            skip_name, level_prefix, out_path, out_size))
            return 1;
    }
    return 0;
}
```

The 5th argument to `find_drop_target_in_dl` is `parent_path` — the path
prefix to prepend. Pass `"_level50"` instead of the empty string used by
the root walk. The function already concatenates `parent_path + "/" + child_name`
internally.

### 3b — Verify path format for level-rooted clips

Run the test after 3a and check the actual emitted path. Two formats to
disambiguate:
- `_level50/target10` (no leading slash, `_levelN` is the root prefix)
- `/_level50/target10` (with leading slash treating `_level50` as root child)

The test expects the first form. If `find_drop_target_in_dl` emits
`/<parent_path>/...`, strip the leading `/` for level paths, OR change the
helper to optionally not prepend `/` when `parent_path` starts with `_`.

### 3c — Don't return level matches when the dragged clip itself is in a level

Edge case: if the dragged clip is in `_level50` and overlaps with another
clip in `_level50`, the `skip_name` filter must work for level-rooted
clips. Add a level-aware skip check: `_level50/draggable50` should be
skipped just like `/draggable50` would be on the root walk.

### Phase 3 verification battery

- AVM1: `drag_drop`, `drag_over_from_outside`,
  `drag_over_without_startdrag`, `mouse_hover_events_while_dragging`
  (4 tests, must stay PASS).
- Gnash misc-swfc: `mouse_drag_test` (must stay PASS).
- Gnash misc-mtasc: `levels` (effective pass; verify level loading still
  works post-droptarget walk).

**Estimated effort.** 1-2 hours: 3a is mechanical (~30 min), 3b is a
quick run-and-tweak, 3c is conditional. Should land 6-8 lines on
DragDropTest (lines 16-23).

## Phase 4 — `button_test1` — COMPLETE

Done in 2026-05-05 session. See "Session findings" above.

## Investigation order recommendation

1. **Phase 3 first.** Smallest scope, mechanical fix in one file, +6-8
   lines. Low regression risk (verified 4-test AVM1 drag battery and
   mouse_drag_test sit on top of `ng_compute_droptarget`).
2. **Phase 1a second.** 2-4 hour investigation, potential +9 lines plus
   unblocks 1c. The diagnostic step (printf in `script_2` and write
   site) is cheap and concrete.
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
- Phase 3: 1-2 hours.
- Phase 4: COMPLETE.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `complete/BUTTON_INFRASTRUCTURE_PLAN.md` | Parent plan. This plan covers residual work after parent's 6 phases landed. |
| `complete/LEVELS_PLAN.md` | Phase 3a leverages level loading already working; extends `ng_compute_droptarget` to walk `g_levels[]`. |
| `incomplete/REMAINING_TAIL_TRIAGE.md` | These tests appeared in REMAINING_TAIL_TRIAGE's cluster table under BUTTON_INFRASTRUCTURE_PLAN; promoting them to a dedicated plan reflects that the parent plan didn't fully resolve them. |
| `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` | Phase 1b lands here when the test promotes — `getDepth` SWF-depth-12 button child returns `-16372` in our impl and Ruffle, `-16371` in Flash. |
