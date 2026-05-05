# Button Infrastructure Plan

<!-- TESTS: ButtonEventsTest, ButtonPropertiesTest, RollOverOutTest, key_event_test, DragDropTest, button_test1, mouse_drag_test -->

<!-- PLAN_META
id: BUTTON_INFRASTRUCTURE
status: in_progress
phases:
  - id: 1
    name: "Mark nested-child Button MCs with is_button_mc=1 (typeof fix)"
    status: complete
  - id: 2
    name: "Audit button-internal child sprite resolution (button.childname)"
    status: complete
  - id: 3
    name: "Re-order Button.prototype property registration to match Flash enumeration"
    status: complete
  - id: 4
    name: "_droptarget computation after drag-and-drop"
    status: complete
  - id: 5
    name: "Mask + hitTest interaction (RollOverOutTest)"
    status: complete
  - id: 6
    name: "Key event listener phase progression (key_event_test)"
    status: complete
dependencies: []
blockers:
  - reason: "None — input is already driven by verify_output.py via input.json → input_events.txt → swf_core.c's input_events_pump_tick. The earlier 'mouse/key input drivers' triage label was incorrect. Each phase is independent and addresses a distinct sub-issue."
-->

## All 6 phases COMPLETE (2026-04-25)

> **Residual work (2026-05-05):** 4 of the 7 listed tests still fail in CI at
> `c5994ec1`: `ButtonEventsTest`, `key_event_test`, `DragDropTest`,
> `button_test1`. Each has a narrow follow-up issue not covered by the 6
> architectural phases of this plan. Tracked in
> `incomplete/BUTTON_RESIDUAL_PLAN.md`.

- **Phase 2** (button-internal children) — `tagPlaceObject2` /
  `tagPlaceObject2Ratio` now eagerly run `button_state_funcs[0]` for
  newly-placed buttons (under `catch_up_mode=1` /
  `g_eager_init_depth++`), so AS code accessing
  `button3.instance1` sees the populated state-0 children before
  the parent frame's DoAction runs. `process_sprite_init_at_depth`'s
  button branch was updated to skip re-running state_funcs when
  `sprite_needs_init==2` (the eager-done marker), but still runs
  the recursive init so child sprites get Phase-2 scripts. AVM1
  enumeration (`actionEnumerate2` / its sibling) now walks
  `mc->display_obj->sprite_display_list` directly when available so
  nested MCs (e.g. button MCs) enumerate their auto-named instance
  children correctly. button_test1 (misc-swfc): 8/31 → 18/31
  matching. ButtonPropertiesTest (misc-ming): 2/23 → ruffle_matched.
- **Phase 4** (drag/drop) — `mc.startDrag()` / `mc.stopDrag()` now
  have proper method handlers in actionCallMethod (the registry
  listed them but no dispatcher existed, so the call was a no-op).
  `_droptarget` reads (3 sites) recompute on-the-fly while the drag
  is active. `ng_compute_droptarget` consults `child_mc_cache` via
  `actionFindDynamicDropTarget` for dynamic MCs (createEmptyMovieClip
  / duplicateMovieClip / attachMovie / loadMovie) — these aren't in
  display_list so the static walk missed them. The static walk's
  sprite branch was tightened to skip text fields (Flash treats
  them as transparent for drop_target). DragDropTest: 15/44 →
  ~25/44 matching. Lines 4-5 (Click outside), 7-14 (target10/20/100),
  25-32 (loadedTarget/target*) all PASS. Remaining failures
  (`_level50/*`) blocked on loadMovie level support.
- **Phase 6** (key dispatch) — the per-method `strncmp(method_name,
  "name", N)` checks in `actionCallMethod` (78 sites) now use
  `strncasecmp`. `_root.Play()` (capital P) inside `l.onKeyDown`
  handlers now resolves to `actionPlay`, advancing the timeline
  past the per-frame `stop()` calls. Without this, the test was
  stuck at frame 2 forever. key_event_test: 9/66 → ~33/66 matching
  (lines 1-30 now match — progresses through tests 1-5).

## Phase 1, 3, 5 status: COMPLETE (2026-04-25)

- **Phase 1** — `actionGetMember` MOVIECLIP path (action.c:41746) and the
  two `findOrCreateMovieClip` nested-child sites at action.c:42243 / 42286
  now set `is_button_mc=1` when the dictionary char is `CHAR_TYPE_BUTTON`.
  ButtonEventsTest line 1 (`typeof(square1.button) == 'object'`) now PASSES.
- **Phase 3** — `initButtonPrototype` (action.c:28990) reordered. Insertion
  order now (LIFO enum yields reverse): onRollOver, onRollOut, onPress,
  onRelease, onReleaseOutside, onSetFocus, onKeyDown, onKeyUp,
  useHandCursor, enabled, getDepth, scale9Grid, filters, cacheAsBitmap,
  blendMode, tabIndex. Note: onKillFocus was NOT in the test's expected
  enumeration (8 on* names total, not 9). ButtonEventsTest lines 5-20 now
  match (Button.prototype enum order).
- **Phase 5** — `actionMCHitTest` for `hitTest(x, y, true)` now
  (a) early-returns false when `mc->is_mask` is set (matches Ruffle
  AVM_HIT_TEST + SKIP_MASK gate at `core/src/display_object/movie_clip.rs:2586`),
  (b) falls back to bounds-only hit when drawing API has unfinalized
  commands (`cmd_count > 0 && path_count == 0` — drawing API doesn't
  triangulate until endFill / next beginFill / clear). The previous
  setMask-via-mask_mc gate (which checked the mask's sprite_display_list
  only, missing drawing API geometry) was removed — Ruffle gates the
  masker via `SKIP_INVISIBLE` not `SKIP_MASK`, so dynamic-drawn masks
  aren't rejected by the masker gate. RollOverOutTest now PASSES (5/5).

## Correction to prior triage

`MISC_MING_SWFC_PLAN.md` previously listed `RollOverOutTest`, `ButtonEventsTest`,
`ButtonPropertiesTest`, `key_event_test`, `DragDropTest`, `mouse_drag_test`,
and `button_test1` as blocked on **mouse/key input drivers** (verifier
doesn't drive input). **That's wrong.** The verifier already drives input:

- `ruffle-tests/verify_output.py:324` — `preprocess_input_json()` parses
  `input.json` into a line-based `input_events.txt`.
- `SWFRecomp/wasm_wrappers/main.c:92` — `input_events_load(argv[1])`
  loads the file at runtime startup.
- `SWFModernRuntime/src/libswf/swf_core.c:300, 391, 664` — event types,
  `input_events_deliver`, and `input_events_pump_tick` fire events
  between frames.
- 62 AVM1 tests use `input.json` and **all 62 currently pass** (e.g.
  `focus_mouse` 45/45, `edittext_restrict` 191/191, `button_keypress`
  3/3, `click_block` 5/5).

The Gnash button/drag/key tests fail for **distinct, non-input reasons**
unmasked once input was successfully driven. This plan triages the
real causes by cluster.

## Affected tests (CI 205a9a77, 2026-04-25)

| Test | Suite | Match | Cluster |
|------|-------|-------|---------|
| ButtonEventsTest | misc-ming | 16/679 (2.4%) | typeof / instance naming / Button.prototype enum order |
| ButtonPropertiesTest | misc-ming | 2/23 (8.7%) | instance naming for unnamed button placements |
| button_test1 | misc-swfc | 8/31 (25.8%) | button-internal child sprite resolution (`button.instance1`) |
| key_event_test | misc-ming | 9/66 (13.6%) | Key listener phase progression (multiple keyDown/keyUp without test continuation) |
| DragDropTest | misc-ming | 15/44 (34.1%) | `_droptarget` computation after drag |
| RollOverOutTest | misc-ming | 4/5 (80.0%) | `maskee.hitTest(80, 280, true)` returns false instead of true (mask + hitTest) |
| mouse_drag_test | misc-swfc | 6/12 (50.0%) | ~~Likely Dejagnu xcheck handling on no-arg `check()` calls inside `tellTarget` (lines 5-8 of the diff are empty `PASSED:` lines)~~ — **misdiagnosis.** Actual root cause (resolved 2026-05-02, commit 531d6bfa): timeline `PlaceObject` MOVE tags were overwriting the matrix of a clip mid-drag, so `check(mc1._x != 200)` saw `mc1._x == 200` after `.jump`. Fix: `startDrag` sets `transformed_by_script=1` on the dragged MC (mirroring Ruffle's `update_drag` → `set_x`/`set_y` side effect, which we don't run in headless mode). The "empty PASSED:" lines were `check(expr)` formatting where `expr` is the captured raw text — they only render with their text once both sides match. |

**Estimated impact:** the cleanest cluster (Phase 1, typeof + nested-child)
is a 2-line fix that resolves 1 line on ButtonEventsTest. Phase 3
(prototype enumeration) is a property-registration reorder that
recovers ~12 lines on ButtonEventsTest. Phases 4–6 are deeper
investigations, each with ~1 test impact.

## Phase 1 — Mark nested-child Button MCs

**Problem.** When `square1.button` is resolved (sprite-internal child
named "button"), the resolved MovieClip is created via
`findOrCreateMovieClip` at `action.c:41689` and pushed without setting
`is_button_mc = 1`. The typeof handler at `action.c:34775` correctly
returns `"object"` when `is_button_mc` is set, but our code only sets
that flag in the **root-level** GetVariable child-resolution path
(`action.c:33105`):

```c
if (_cid > 0 && dictionary[_cid].type == CHAR_TYPE_BUTTON)
    child_mc->is_button_mc = 1;
```

The nested-child path (sprite member access via `actionGetMember`) is
missing the equivalent. Diff symptom from ButtonEventsTest:

```
PASSED: typeof(square1.button) == 'object'
FAILED: expected: 'object' obtained: movieclip
```

**Fix.** In the nested-child resolution path
(`action.c:41689` and around the `findOrCreateMovieClip` call), check
the child's char_id and set `is_button_mc` on the resolved MC. The
char_id is already in scope as `_ecid` — code is two extra lines:

```c
MovieClip* _early_mc = findOrCreateMovieClip(app_context, _early_name, mc);
if (_early_mc != NULL) {
    extern Character* dictionary;
    if (_ecid > 0 && _ecid < INITIAL_DICTIONARY_CAPACITY &&
        dictionary[_ecid].type == CHAR_TYPE_BUTTON)
        _early_mc->is_button_mc = 1;
    ...
}
```

Audit other lookup paths that create MOVIECLIP values from nested
children. Search:

```bash
grep -n 'findOrCreateMovieClip(app_context.*\&display_list\|findOrCreateMovieClip(app_context.*sprite_display' \
    SWFModernRuntime/src/actionmodern/action.c
```

Each site that resolves a nested child by name should set `is_button_mc`
when the dictionary type is CHAR_TYPE_BUTTON. Same pattern, easy to
apply uniformly.

**Risk.** Low. Mirrors the existing root-level pattern.

## Phase 2 — Button-internal child sprite resolution

**Problem.** `button_test1` references `button3.instance1` (the auto-named
internal sprite of a button character) and gets `undefined`:

```
FAILED: typeof(button3.instance1): expected: "movieclip" , obtained: "undefined"
FAILED: typeof(button3.instance1.button1): expected: "object" , obtained: "undefined"
```

A SWF Button character contains 4 records (up, over, down, hit), each of
which can place display objects with their own depths. When the button
state is resolved, those display objects appear in the active state's
display list. The state functions
(`Character::button_state_funcs[0..2]`) are recompiler-generated
`tagPlaceObject2` sequences that run on state change.

Hypothesis: our button state functions either don't run at startup
(buttons in idle state should show the up-state record at frame 0), or
the children placed by them aren't reachable via `actionGetMember` from
the parent button MC. The `tagPlaceObject2` calls inside a state
function may target the **root** display list slot (the button's swf_depth)
rather than a nested sprite_display_list under the button MC's
display_obj.

**Investigation steps:**

1. Decompile `button_test1.swf` (or the Ming source if available) to
   confirm what `button3` and `button3.instance1` reference. `instance1`
   is the auto-name format — likely a sprite placed inside one of the
   button records.
2. Look at how button state functions are emitted in the recompiler
   (`SWFRecomp/src/swf.cpp` — search for `button_state` or
   `DefineButton2`). Confirm whether they emit
   `tagPlaceObject2WithClipActions(...)` against a button-local display
   list or against the root display list.
3. If state functions place into root display list: button-internal
   children land at unrelated SWF depths and don't get parented to the
   button MC. Fix: state function emission should populate the
   button's own `sprite_display_list` (DisplayObject struct already has
   `sprite_display_list` and `sprite_max_depth` fields available for
   button MCs, mirroring sprite MCs).
4. After children are correctly parented under the button MC, the same
   nested-child resolution path from Phase 1 should handle
   `button.instance1` lookup.

**Risk.** Medium. Buttons share enough infrastructure with sprites
that the fix should be a relatively small extension (give Button
characters their own sprite-style display list), but the recompiler
may need parallel emission paths for button state functions vs sprite
frame functions.

## Phase 3 — Button.prototype property registration order

**Problem.** ButtonEventsTest enumerates `Button.prototype` properties
via `for-in` and gets the order wrong (lines 10–32 of the diff). The
expected order (Flash semantics, reverse-chronological LIFO walk on
property bag) implies Flash's insertion order for Button.prototype was:

```
useHandCursor → enabled → getDepth → scale9Grid → filters →
cacheAsBitmap → blendMode → tabIndex
```

Our `initButtonPrototype` (`action.c:28933`) inserts in this order:

```
getDepth → useHandCursor → enabled → scale9Grid → filters →
cacheAsBitmap → blendMode → tabIndex
```

The test also enumerates a long list of `on*` event handlers
(`onKeyUp`, `onKeyDown`, `onSetFocus`, `onKillFocus`,
`onReleaseOutside`, `onRelease`, `onPress`, `onRollOut`, `onRollOver`)
which we don't add to Button.prototype at all — they're enumerable from
Flash's perspective even before being set, but only when the property
bag stores `undefined` placeholders for them.

**Fix.** Two parts:

1. **Reorder the explicit properties.** Move `getDepth` registration to
   AFTER `useHandCursor` and `enabled`:
   ```c
   setProperty(..., "useHandCursor", ...);
   setProperty(..., "enabled", ...);
   addStubMethodToProto(..., "getDepth", ...);
   ```
2. **Register the `on*` event-handler placeholders** as `undefined`
   enumerable own-properties on Button.prototype. The list (in
   insertion order — last added enumerates first):
   ```
   onRollOver, onRollOut, onPress, onRelease, onReleaseOutside,
   onKillFocus, onSetFocus, onKeyDown, onKeyUp
   ```
   Cross-check the order against ButtonEventsTest line 13–20:
   ```
   13  onKeyUp     ← most recently added
   14  onKeyDown
   15  onSetFocus
   16  onKillFocus
   17  onReleaseOutside
   18  onPress
   19  onRollOut
   20  onRollOver  ← first added
   ```
   So insertion order should be reverse: `onRollOver` first,
   `onKeyUp` last.

**Risk.** Low. Property registration order is a one-shot at constructor
init; no runtime dispatch implications.

## Phase 4 — `_droptarget` computation after drag

**Problem.** DragDropTest fails on
`_root.draggable50._droptarget == "/target10"` after a drag-and-drop
sequence. Mouse events fire (the test's earlier setup checks pass),
but `_droptarget` reads as empty string instead of `"/target10"`.

The runtime has `ng_compute_droptarget` (referenced from
`action.c:25503`) that walks the display list to find the clip under
the dragged hotspot, skipping the dragged clip itself.

**Investigation steps:**

1. Confirm that `ng_compute_droptarget` is invoked at the right time
   (at `_droptarget` getter? at drag-end? or every frame?). Read the
   call site in `action.c:25499–25510`.
2. Verify mouse coordinates at drag-end match the click position
   from `input.json`. If `g_drag_virt_x/y` aren't being updated by
   the input pump at the time `_droptarget` is read, the lookup
   would miss the target.
3. Verify the target clips (`/target10`, `/target20`, etc.) have
   correct hit boxes. They're DefineShape characters, so hit-testing
   uses `ng_hit_test_at_stage_xy` or similar.
4. The expected paths use slash-syntax: `"/target10"`,
   `"_level50/target10"`. Confirm the `_droptarget` formatter
   produces slash-paths consistently with Flash.

**Risk.** Medium. Drag mechanics span input dispatch, hit-test, and
clip resolution — three subsystems any one of which could be at
fault. Likely needs a tracing pass to find the missing piece.

## Phase 5 — Mask + hitTest interaction (RollOverOutTest)

**Problem.** RollOverOutTest at 80% (4/5) — only one line fails:

```
PASSED: ! dynamic_mask.hitTest(80, 280, true)  ← masking dynamic_mask is invisible at (80, 280)
FAILED: maskee.hitTest(80, 280, true)          ← maskee under dynamic_mask should still hitTest true (Flash: shape-level hit, ignoring mask occlusion)
```

Flash's `hitTest(x, y, true)` with `shapeFlag=true` does **shape-level**
hit testing on the target clip's *own* geometry, ignoring mask
occlusion. Our implementation may be respecting the mask (returning
false because the mask covers the maskee at that point) — Flash
doesn't.

**Fix sketch.** In `actionMCHitTest` (or wherever `hitTest(x, y, true)`
is implemented), when `shapeFlag=true`, walk only the target MC's own
shapes — ignore parent/sibling masks. The mask attribute affects
rendering and `hitTest(otherClip)` (clip-vs-clip), not coordinate
shape-flag hitTest.

Read `mcHitTest` / `actionMCHitTest` in
`SWFModernRuntime/src/actionmodern/action.c` and confirm the mask
handling.

**Risk.** Low-medium. One-line behavior change scoped to the
`shapeFlag=true` branch.

## Phase 6 — Key event listener phase progression

**Problem.** key_event_test fires the input.json keyboard sequence,
but our trace shows `l.onKeyDown` / `l.onKeyUp` repeating without the
test progressing past phase 1 ("Press a single key to continue the
test"):

```
Expected:
  l.onKeyDown
  l.onKeyUp
  PASSED: 1 == 1
  PASSED: 1 == 1
  PASSED: number == number
  2. Press a single key to continue the test

Actual:
  l.onKeyDown
  l.onKeyUp
  l.onKeyDown    ← should be PASSED check, not another keyDown
  l.onKeyUp
  l.onKeyDown
  ...
```

The test likely uses `Key.getCode()` / `Key.getAscii()` inside the
keyDown handler to gate progression — comparing against expected key
codes. If `Key.getCode()` returns the wrong value (or zero), the
test's progression conditional never fires and only the listener
output trace appears.

**Investigation steps:**

1. Decompile `key_event_test.swf` or read the Ming source if
   available. Find the `onKeyDown` handler and what condition it
   uses to advance.
2. Confirm `actionKeyGetCode` / `actionKeyGetAscii` (search
   `Key.getCode` in action.c) return the key codes that match the
   `KEY_DOWN`/`KEY_UP` events from `preprocess_input_json` (which
   uses `ruffle_key_to_flash_code` mapping).
3. Verify `Key.isDown(code)` works during handler dispatch — many
   tests gate on `Key.isDown`.
4. Confirm `TextInput` events (which key_event_test also uses) reach
   any focused TextField / dispatch via `Key.onKeyDown` listeners as
   well, in the right order.

**Risk.** Medium. Key dispatch + Key class state spans event injection,
clip-event firing, and the `Key` global. Could be a single-line key
code mapping fix, or a deeper dispatch issue.

## Verification battery (any phase)

**Required-pass guardrail (must remain green):**

- AVM1 input-driven (62 tests): `focus_mouse`, `click_block`,
  `button_keypress`, `button_keypress_vs_textinput`,
  `edittext_restrict`, `edittext_restrict_paste`,
  `edittext_password_copy`, `tab_ordering_*`, `drag_drop`,
  `mouse_events_visible_enabled`, `string_paths_keyevents`,
  `text_blocks_clicks`, `frame_size_translated_negative`,
  `focus_keyboard_press`, `mouse_hover_events_while_dragging`. All
  pass today; a regression here would be a flag for any phase.
- AVM1 button: `button_children`, `bad_placeobject_clipaction`,
  `movieclip_in_removed_button`, `clip_events`, `on_construct`. Pass
  today.
- Gnash misc-ming recently-fixed: 17-test battery from
  `CURRENT_STATUS.md` "Latest fixes" sections (instanceNameTest,
  attachMovieTest, etc.).

**Target tests (expected to flip per phase):**

- Phase 1: 1 line on ButtonEventsTest (typeof line); doesn't fully
  flip the test.
- Phase 2: ~10 lines on button_test1 (the `button3.instance1.*` chain).
- Phase 3: ~12 lines on ButtonEventsTest (enumeration order).
- Phase 4: most of DragDropTest's body (`_droptarget` chain).
- Phase 5: RollOverOutTest 4/5 → 5/5 (PASS).
- Phase 6: key_event_test long tail; likely partial improvement, not
  full pass.

## Open questions

1. ~~**mouse_drag_test cluster.** Lines 5–8 are `PASSED: ` (empty
   assertion text) in expected, `FAILED: ` (empty) in actual. These
   look like Dejagnu `xcheck()` calls (zero-arg or no-text variants)
   that PASS when the underlying condition fails. Not in this plan;
   needs separate triage.~~ — **Resolved 2026-05-02 (commit 531d6bfa).**
   Misdiagnosis: not a Dejagnu issue. The lines are `check(mc1._x != 200)`
   etc. — Dejagnu's `check(cond)` formatter outputs an empty trailing
   text when `cond` evaluates to false (because no comparand text was
   passed). Once we set `transformed_by_script=1` on the dragged MC at
   startDrag time (so timeline `PlaceObject` MOVE no-ops on it), the
   conditions become true, the formatter renders the captured expression
   text, and both `PASSED: mc1._x != 200` lines match. Lesson: empty
   `PASSED:` / `FAILED:` text in a Dejagnu diff is a signal about the
   *condition*, not about the *check function*. Look for a `check(expr)`
   (single-arg) call in the test source where `expr` is a comparison.
2. **`Button` *class* vs `is_button_mc` flag.** The runtime currently
   has both a Button *constructor* (registered via
   `g_ctors[i]` mechanism) and a per-MC `is_button_mc` flag. Verify
   that `obj instanceOf Button` (test ButtonEventsTest line 2) routes
   correctly through both layers — it currently fails. May tie into
   Phase 1 or Phase 3.
3. **Auto-instance-naming for buttons placed inside sprites.**
   `tag_stubs.c:668` auto-names sprites/buttons/textfields without
   names. Confirm this fires for buttons placed inside a sprite's
   `tagPlaceObject2` (the eager-init path during sprite frame_0).
   If it doesn't, that's a Phase 2 follow-up.

## Estimated session budget

- Phase 1: 30 min (2-line fix + battery).
- Phase 2: 3–4 hours. Real investigation; may discover the recompiler
  emission path needs reshaping.
- Phase 3: 1 hour (reorder + add 9 placeholder properties + battery).
- Phase 4: 2–3 hours.
- Phase 5: 1–2 hours.
- Phase 6: 2–3 hours.

Phases 1 + 3 are the cheapest wins (~1.5 hours, +13 lines on
ButtonEventsTest) and a good first session. Phase 2 (button-internal
children) is the largest single win (button_test1 + cascading
benefits) but has the highest investigation cost.

## Why this is the right shape

The earlier "needs mouse/key input drivers" categorization was a
plausible-sounding misclassification — these tests *do* have
`input.json` files, they *do* have mouse/key event types, and they
*do* fail. Dropping the (correct) infrastructure assumption and
running each test under the existing input-driven harness immediately
exposes the real causes: distinct, non-input bugs in Button typeof,
button child resolution, prototype enumeration order, drag mechanics,
and key dispatch. Splitting them into per-phase fixes lets the easy
wins (1, 3) land independently from the deeper investigations (2, 4,
6), and removes a misleading "blocker" entry from
`MISC_MING_SWFC_PLAN.md`'s input-driver category.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `MISC_MING_SWFC_PLAN.md` "Input-driven (need verifier mouse/key driver — out of scope)" | This plan supersedes that line. The verifier already drives input; the Gnash button/drag/key tests fail on the issues in this plan instead. |
| `DEFERRED_CLIP_UNLOAD_PLAN.md` | Independent. ButtonEventsTest references `onUnload` indirectly via clip event handlers but doesn't gate on the deferred-unload fix. |
| `CLONESPRITE_DEPTH_BIAS_PLAN.md` | Independent. |
| `verify_output.py:324` (`preprocess_input_json`) and `swf_core.c:300` (`input_events_load`) | Reference for the existing input-driving infrastructure. |
