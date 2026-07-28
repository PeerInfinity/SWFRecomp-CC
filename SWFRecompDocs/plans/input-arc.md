# Input arc — triage + tranches

**Created**: 2026-07-28 · **Baseline**: `ab92ddfbc` (session start), per-suite
`_results/results_graphics.json` from CI `30185616752`/`30327940850` (the
`38aa0a300` results merge).
**Status**: TRIAGED. Tranche 1 gated on "≥5 tests needing pure event/API
surface or harness replay plumbing" — **gate met** (8 candidates, §5).

Scope of this document: the **input block** named as row 4e of
`feature-priority-map.md` ("Focus / Tab / Mouse / Keyboard input, 25 tests,
partly reachable via `input.json` injection"). The census below finds **30
failing avm2 tests + 6 riders in other suites = 36**, not 25 — the map's
figure was a theme bucket over the avm2 suite alone and predates the
`text/` and `from_shumway/mouse/` categories being swept for the same
machinery.

Line counts throughout are `matching/expected` from the graphics baseline.

---

## 0. Method — and one caveat that bit this triage

Two sweeps, unioned:

1. **Name sweep** over every suite's results for
   `key|focus|tab|contextmenu|mouse|ime|selection|caret|input`.
2. **Content sweep** over every test's `*.as` for
   `KeyboardEvent|ContextMenu|Keyboard\.|stage\.focus|focusRect|tabIndex|
   tabEnabled|tabChildren|FocusEvent|TextEvent|IMEEvent|MouseEvent|Mouse\.|
   InteractiveObject` (158 tests hit; 45 of them failing).

Plus a third, decisive index: **which tests ship an `input.json`** (181
across the corpus, 36 of them failing). That list is what separates "the
API is missing" from "the recorded input never fires".

**Caveat — `results_graphics.json` truncates `actual_output`/
`expected_output` at ~51 lines.** For any test whose expected output is
longer, the JSON diff shows only the head. `tab_ordering_properties` looked
like a 2-line fix from the JSON and is actually a 173-line, three-cause
test (§4, bucket K). **Re-run long tests locally before sizing them.**

---

## 1. What exists today

The AVM2 input bridge is *not* a stub — Stage 8 (`ee2107860`) built most of
it, and it has been extended since. In `avm2_display.c`:

- **Event ring + pump.** `Avm2InputEvent` / `avm2_input_load(path)` parses
  the harness's line format; `avm2_input_pump_tick` drains one WAIT group
  per tick at the tail of `avm2_display_run_tick`, plus a separate live
  browser ring (`avm2_input_inject_key` / `avm2_input_inject_mouse`).
- **Mouse.** Full Ruffle `update_mouse_state` port: AABB hit-test,
  hover/press tracking, 3-phase dispatch (`mouseDown`/`mouseUp`/`click`/
  `doubleClick`/middle/right/`rollOver`/`rollOut`/`mouseOver`/`mouseOut`/
  `mouseMove`/`mouseWheel`), `mouseEnabled`/`mouseChildren` gating,
  `startDrag`/`stopDrag`/`dropTarget`, `buttonMode`/`useHandCursor`.
  Tranche 7 of the Loader arc last touched this; `mouse_children` (192/192)
  is its canary.
- **Focus.** `g_stage_focus`, `set_focus` (focusOut/focusIn with
  `relatedObject`), `update_focus_on_press` (mouseFocusChange),
  `is_focusable_by_mouse`, `obj_tab_enabled`/`obj_is_tabbable`/
  `obj_tab_children` per-type defaults, `build_tab_order` (Ruffle
  `fill_tab_order` DFS + the automatic `6*y + x` key + custom `tabIndex`
  order), `input_handle_tab`.
- **Keyboard.** `dispatch_key` → `KeyboardEvent` at `stage.focus` (or the
  Stage), a 256-entry `g_key_down_map` for `ctrlKey`/`altKey`/`shiftKey`,
  Tab traversal on keyDown, and `avm2_text_input_key/char/control` into the
  EditText engine.

**The AVM1 side of this arc is 100% green** — all 60-odd `avm1/focus*`,
`avm1/tab_ordering_*`, `avm1/key_*`, `avm1/mouse_*`, `avm1/selection*`,
`avm1/context_menu*`, `avm1/edittext_ime_focus_lost`,
`avm1/input_dead_keys_windows` and the six `visual/focus_highlight/*`
tests pass. Every mechanism these AVM2 tests want has a working AVM1
implementation to copy, in `src/libswf/input_events.c` +
`src/actionmodern/action.c`.

### The harness replay map (Loader-arc lesson: *missing input ≠ missing feature*)

`preprocess_input_json` (`verify_output.py:488`) emits **14** event kinds.
The two consumers diverge:

| Harness line | AVM1 (`input_events.c`) | AVM2 (`avm2_display.c`) |
|---|---|---|
| `WAIT` | ✅ | ✅ |
| `MOUSE_MOVE/DOWN_*/UP_*` | ✅ | ✅ |
| `MOUSE_WHEEL` | ✅ | ✅ dispatches; **does not scroll a TextField** |
| `KEY_DOWN` / `KEY_UP` | ✅ | ✅ |
| `TEXT_INPUT` | ✅ | ✅ |
| `TEXT_CONTROL` | ✅ | ✅ |
| `SET_CLIPBOARD_TEXT` | ✅ | ✅ |
| `FOCUSGAINED` | ✅ | **parsed, then dropped** — no `input_deliver` case |
| `FOCUSLOST` | ✅ `actionWindowFocusLost` | **parsed, then dropped** |
| `IME_PREEDIT` | ✅ `actionTextFieldImeCompose` | **not even parsed** (`continue`) |
| `IME_COMMIT` | ✅ `actionTextFieldImeCommit` | **not even parsed** |

`IN_FOCUS_GAINED`, `IN_FOCUS_LOST`, `IN_IME_PREEDIT` and `IN_IME_COMMIT`
all exist in the `Avm2InputKind` enum. Two of them are parsed and fall
through `input_deliver`'s `default: break`; two are never parsed at all.
**Three failing tests are entirely this** (`focusrect_focuslost`,
`ime_linux_dead_keys`, `edittext_ime_focus_lost`) — no missing API, just
four unrouted event kinds.

Determinism note: none of these carry a timestamp. Every event is paced by
the WAIT groups in `input.json`, i.e. by the tick counter, so replaying
them changes nothing about run-to-run reproducibility.

---

## 2. Per-test triage — avm2 suite (30 tests)

### Bucket A — `MouseEvent` value surface (pure API, no subsystem) · 3 tests

The whole bucket is `avm2_events.c:806-890`.

| Test | lines | What it actually asserts |
|---|---|---|
| `mouseevent_stagexy` | 1/35 | **`localX`/`localY` have no setter** → the first write throws `#1074 Illegal write to read-only property localX`, which blanks the remaining 34 lines. Registered as `avm2_builtin_add_getset(..., me_get_local_x, NULL)`. |
| `mouseevent_valueof_tostring` | 24/28 | `new MouseEvent(...)` with **no target**: expects `stageX=0 stageY=0`; we echo `localX`/`localY`. Ruffle returns `local_x * 0.0`. |
| `mouseevent_constr` | 62/66 | `isRelatedObjectInaccessible` is missing entirely → `undefined`, expected `false`. `[API("662")]` get/set pair over a plain flag. |

A fourth defect lives here and pays out in bucket F: **`me_get_local_x/y`
and `me_get_stage_x/y` truncate to `(double)(int)`**, so every coordinate
is floored. Ruffle's model
(`globals/flash/events/mouse_event.rs::local_to_stage_x`) is:

```
if local_x.is_nan() || local_y.is_nan() -> return local_x   (resp. local_y)
else if target is a DisplayObject       -> target.local_to_global(Point::from_pixels(lx, ly))
else                                    -> local_x * 0.0
```

`Point::from_pixels` snaps to twips (0.05 px), which is exactly where the
expected `stageY=282.8` / `at: 208.45 266.05` values come from. The int
truncation is why `mouse_pick_masking` prints `282` and `mouse_pick_text`
prints `208 139`.

### Bucket B — harness replay gaps · 3 tests

| Test | lines | What it needs |
|---|---|---|
| `focusrect_focuslost` | 7/9 | `input.json` is `[KeyDown Tab, KeyDown Tab, FocusLost, FocusGained, Wait]`. The two missing lines are the `focusOut` pair the player fires when the **window** loses focus. Route `IN_FOCUS_LOST` → `set_focus(ctx, NULL)`. |
| `ime_linux_dead_keys` | 0/10 | 28 events, 12 of them `ImePreedit`/`ImeCommit` that we drop. Expected output is `textInput á / ä / ¨r` + the shift keyDown/keyUp pairs — note it also **suppresses the `keyUp` for keys consumed by an active composition** (`Unknown`, and the `Char('a')` that follows a commit). Needs the AVM1 `actionTextFieldImeCompose/Commit` pair ported plus a composition-active flag that swallows key events. |
| `edittext_ime_focus_lost` | 0/9 | Same machinery, minimal case: a preedit `q` must show in the field (`Before: q`, `input q`, `After: q`) and survive the trailing empty preedit. |

### Bucket C — scalar property semantics · 4 tests

| Test | lines | Cause (confirmed by local run) |
|---|---|---|
| `focusrect_property` | 104/110 | Six identical lines: `focusRect = undefined` must read back **`null`**, we give `false`. `io_set_focus_rect` only treats `AVM2_VALUE_NULL` as "unset"; Ruffle types the property as `Object`, so `undefined` clears it too. One-line fix. |
| `tab_ordering_stage_tab_children_remove_root` | 3/5 | `stage.tabChildren = false` must leave **`stage.tabChildren === true`** and set **`root.tabChildren = false`**. Ruffle `stage.rs:476` + `Stage.as:169`: the Stage getter is hardcoded `true` and the setter forwards to the AVM2 root. We store it on the Stage's own ext. |
| `tab_ordering_tabbable` | 45/47 | Two identical lines: a **stateless `new SimpleButton()`** (`button10`) is expected to be tabbable and to receive focus during traversal; it never does in our `build_tab_order`. Its bounds are empty, so its automatic key is `6*0+0 = 0` — suspect the empty-bounds path or the equal-key dedup in `build_tab_order`. |
| `mouse_wheel_events` | 33/36 | Three lines: after each `MouseWheel {lines: -3}` over a TextField the field's **`scroll` must advance by 3** (1 → 4 → 7 → 4). We dispatch the `mouseWheel` event correctly and never scroll. |

### Bucket D — focus event model · 4 tests

| Test | lines | Cause |
|---|---|---|
| `focus_events_mouse_focusable` | 110/112 | `mouseFocusChange` must carry `relatedObject` = the object that *would* take focus, even when the object under the cursor is not itself focusable; we pass `null`. |
| `focus_events_mouse_basic` | 30/260 | Same defect plus: `mouseFocusChange` must fire **even when focus does not move** (expected line 7 dispatches it on the Stage with `focus: null` and `relatedObject=[object Sprite]`). Our `update_focus_on_press` is gated behind `if (focus != g_stage_focus)`. |
| `focus_events_key_basic` | 33/132 | The **first Tab lands on the wrong object** — expected `sprite1`, we pick `button1`. Automatic-order key computation for objects whose bounds come from a SimpleButton state (same family as `tab_ordering_tabbable`), so the whole 132-line transcript shifts. |
| `tab_ordering_stage_tab_children` | 15/32 | Half is the Stage-tabChildren proxy (bucket C); the rest is that setting `root.tabChildren = false` must actually stop traversal descending into the root's children — we keep tabbing into `clip2`. |

### Bucket E — arrow-key directional focus · 2 tests

Neither `keyFocusChange` for arrow keys nor Ruffle's directional-navigation
algorithm (`focus_tracker.rs`) exists; `input_handle_key` only special-cases
keyCode 9.

| Test | lines | Note |
|---|---|---|
| `focus_events_key_navigation` | 12/53 | Up/down/left/right must fire `keyFocusChange` with the arrow's keyCode and move focus by geometry. |
| `tab_ordering_arrows` | 1/998 | 998 lines, 60+ synthetic stages, is the *specification* of that algorithm (general direction / specific direction / overlapping bounds). One test, but it is the acceptance suite for bucket E. |

### Bucket F — mouse hit-test: masks + non-interactive + text · 5 tests

All five need real hit-testing beyond the AABB pick, and all five *also*
carry the bucket-A coordinate truncation, so bucket A must land first or
the diffs stay noisy.

| Test | lines | Note |
|---|---|---|
| `mouse_pick_masking` | 0/7 | A masked object must pick as its **mask's** intersection; we return the mask itself (`maskObject`, `maskObjectChild`) as the target. |
| `mouse_pick_dobj_mask` | 2/4 | `DisplayObject.mask` must exclude picks outside the mask. |
| `mouse_pick_non_interactive_dobj_mask` | 0/3 | Same for a non-interactive masked object. |
| `mouse_pick_non_interactive_bitmap_mask` | 2/4 | Same with a Bitmap mask (alpha-aware). |
| `mouse_pick_text` | 4/8 | A TextField picks on its **glyph/box geometry**, not its AABB — we produce one spurious `mouseDown` at (208.45, 139.05). |

### Bucket G — caret + selection from the mouse · 3 tests (+4 riders)

| Test | lines | Note |
|---|---|---|
| `textbox_click` | 1/37 | 566 events; every click must set the caret to the clicked character index. We never move the caret, so 36 of 37 traced indices are wrong. |
| `edittext_mouse_selection` | 334/363 | Press-drag-release must select a range; every `Selected:` line is empty for us. Also covers double-click-word and triple-click-line. |
| `selection` | 229/239 | Four off-by-one `caretIndex`/`selectionBeginIndex` values during `text_input`. |

### Bucket H — `TextEvent.LINK` from HTML anchors · 1 test (+1 rider)

| Test | lines | Note |
|---|---|---|
| `textfield_event` | 0/66 | `htmlText` with `<a href='event:alert1'>` — clicking the anchor must dispatch `TextEvent.LINK` with `text = "alert1"`. AVM1 has the equivalent (`asfunction:` handling, `action.c:72472`); AVM2 has nothing — no `TextEvent` link path in `avm2_text.c`. |

### Bucket J — AVM1 content under an AVM2 parent · 4 tests · **WON'T DO here**

`focus_events_mixed_avm_edittext` (1/49), `selection_onsetfocus_mixed_avm`
(0/5), `mouse_pick_avm1_root` (1/2), `mouse_pick_loader_avm1` (5/42).

Derived from what they assert, not from a subsystem name: each one's
expected output interleaves **AVM1 handler callbacks**
(`input_txt1.onSetFocus`, `Selection.onSetFocus`, `txt.onKillFocus`) with
AVM2 `FocusEvent`s. That needs both VMs live in one player with a shared
focus tracker — `feature-priority-map.md` arc 8, not this arc. The AVM2
half of each is already right (e.g. `focus_events_mixed_avm_edittext`
emits its `mouseFocusChange`/`focusIn`/`focusOut` lines correctly and only
misses the AVM1-side lines).

### Bucket K — blocked on sealed builtin classes · 1 test · **DEFERRED**

`tab_ordering_properties` (559/732). Three causes, only the first is ours
to fix here:

1. Stage `tabChildren` proxy (2 lines) — bucket C.
2. **`tabChildren` must not exist on `TextField` or `SimpleButton`.**
   Expected is `ReferenceError #1069 … not found on flash.text.TextField
   and there is no default value` on read and `#1056 Cannot create
   property` on write; we return `undefined` and then happily create a
   dynamic property (`tabChildren = -2147483648`, `= [object Object]`,
   `= 1.1`). That is not a tabbing bug — **our builtin display classes are
   not sealed**, so every absent property reads `undefined` instead of
   throwing. Blast radius well beyond this arc; wants its own
   investigation.
3. `MovieClip` with `buttonMode = true` must report `tabEnabled === true`
   by default — `obj_tab_enabled` already models this, but the public
   `tabEnabled` *getter* does not consult `button_mode`.

---

## 3. Riders in other suites (6 tests)

Found by the content sweep, invisible to the map's avm2-only census.

| Test | lines | Bucket |
|---|---|---|
| `text/text_caret_placement_align` | 189/248 | G — caret index from click x/y |
| `text/text_caret_placement_leading` | 183/244 | G |
| `text/text_caret_placement_scroll` | 81/108 | G |
| `text/text_caret_placement_translated_bounds` | 134/140 | G |
| `text/links_in_scrolled_text` | 0/1 | H |
| `from_shumway/mouse/start_drag_lock` | 2/3 | own bucket I |

**`start_drag_lock`** is a one-liner with a real semantic: `startDrag(true)`
(lockCenter) must **not** move the object on the same frame. Expected
`100 100 / 100 100 / 80 120` (the test's own comment: "in FP x and y will
update in about 70-100ms"); we snap immediately to `110 90`. Defer the
first drag update to the next tick's `update_drag`.

The four `text_caret_placement_*` tests all show the same single symptom —
the caret is pinned at end-of-text no matter where the click lands — so
they are one fix, not four.

---

## 4. Tests the sweeps caught and triage **excludes**

Recorded so the next census does not re-litigate them. In each case the
reason is what the test asserts, not the subsystem its name suggests.

| Test | Why not input |
|---|---|
| `avm2/tabstop_properties` (0/105) | `flash.text.engine.TabStop` — a **TLF** class (`Error #1065: Variable TabStop is not defined`), nothing to do with tab focus. Belongs to the Text Layout Framework arc. |
| `avm2/textline_inapplicable_properties`, `avm2/textline_throwerror` | TLF `TextLine`; they merely *enumerate* `tabIndex`/`focusRect`/`contextMenu` among the properties that must throw. |
| `avm2/stage_properties2` (23/213) | Reads `stage.focus`/`tabEnabled`/`contextMenu`, but every diff is the **stack-trace format** of `throwError` (missing `at Error$/throwError()` frame, `set height()` vs `height()`). Error-formatting arc. |
| `avm2/timer_invalid_delay` | `flash.utils.Timer`. |
| `avm2/displayobject_scrollrect` | `localToGlobal` float precision + scrollRect twips rounding. |
| `avm2/loader_try_click_root` (0/16) | Loader arc §10c — blocked on child-SWF geometry, already dispositioned. |
| `mixed_avm/avm2_loads_avm1` | Dual-VM (bucket J's problem), Loader/`AVM1Movie` half. |
| `avm2/abstract_classes`, `avm2/shaderparameter_value`, `avm2/stage3d_*`, `avm1/global_instance_decls`, `avm1/native_objects_swf6`, `avm1/set_property_values/*` | Content-sweep false positives — they mention `InteractiveObject`/`ContextMenu`/`focusrect` in a class census or a property table, and fail for unrelated reasons. |

**There are no failing ContextMenu tests.** `avm1/context_menu`,
`avm1/context_menu_item`, the four `from_gnash/…/ContextMenu-v{5,6,7,8}`
and `regression/avm2_contextmenu_stub` all pass; no avm2 test exercises
ContextMenu UI semantics. The map's "KeyboardEvent / ContextMenu / focus"
gloss over-counted ContextMenu at exactly zero.

---

## 5. Ranked tranches

Ranked by yield-per-effort. Predictions get postmortemed in §6 — arc
convention.

### Tranche 1 — MouseEvent value surface + scalar property semantics + FocusLost replay · **predicted +7** · SMALL

The gate item. Everything here is a getter, a setter, or a switch case; no
new subsystem, two files (`avm2_events.c`, `avm2_display.c`).

1. `me_get_local_x/y`: drop the `(double)(int)` truncation; register real
   setters.
2. `me_get_stage_x/y`: Ruffle's three-branch model (NaN passthrough /
   `local_to_global` through twips / `local_x * 0.0` when there is no
   display-object target).
3. `MouseEvent.isRelatedObjectInaccessible` get/set.
4. `input_deliver`: handle `IN_FOCUS_LOST` (→ `set_focus(NULL)`) and
   `IN_FOCUS_GAINED` (no-op, matching AVM1).
5. `io_set_focus_rect`: treat `undefined` like `null`.
6. Stage `tabChildren`: getter always `true`, setter forwards to the AVM2
   root.
7. `mouseWheel` over a TextField scrolls it by `-delta` lines.
8. Stateless `SimpleButton` reaches the automatic tab order.

Targets: `mouseevent_stagexy`, `mouseevent_valueof_tostring`,
`mouseevent_constr`, `focusrect_focuslost`, `focusrect_property`,
`tab_ordering_stage_tab_children_remove_root`, `mouse_wheel_events`,
`tab_ordering_tabbable` (8 candidates; predict 7 land — items 7 and 8 are
the two whose root cause is inferred rather than read off a one-line diff).

Blast radius: the mouse pipeline. Canaries `avm2/mouse_children` (192/192),
`avm2/loader_noninteractive_try_click_root`, `avm2/mouse_click_events`,
`avm2/mouse_double_click_events`, plus the link canaries
`avm2/verify_method_info_oob`, `avm2/verify_method_info_duplicate`,
`mixed_avm/avm1_loads_avm2`.

### Tranche 2 — mask + non-interactive + text hit-testing · **predicted +5** · MEDIUM

Bucket F. Ruffle `display_object.rs::hit_test_shape` with
`HitTestOptions::MOUSE_PICK`, plus mask intersection in the pick walk and
TextField box geometry. Depends on tranche 1 for coordinate precision.

### Tranche 3 — caret placement + mouse selection · **predicted +7** · MEDIUM

Bucket G plus the four `text/text_caret_placement_*` riders. One mechanism:
map a stage point to a character index in the EditText layout, then wire
press/drag/release and double/triple click on top. AVM1's
`edittext_focus_selection` family already does this, so the layout query
exists to copy.

### Tranche 4 — focus event model · **predicted +4** · MEDIUM

Bucket D. `mouseFocusChange` must fire unconditionally with the correct
`relatedObject`, and the automatic tab order must agree with Ruffle for
SimpleButton-shaped bounds and for `root.tabChildren = false`.

### Tranche 5 — IME composition · **predicted +2** · SMALL-MEDIUM

Bucket B's other half. Parse `IME_PREEDIT`/`IME_COMMIT` in
`avm2_input_load`, route to a new `avm2_text_ime_compose/commit` mirroring
`actionTextFieldImeCompose/Commit`, and add the composition-active flag
that swallows key events.

### Tranche 6 — `TextEvent.LINK` · **predicted +2** · SMALL-MEDIUM

Bucket H. Anchor spans already have to exist for HTML rendering; the work
is hit-testing them on click and dispatching the event.

### Tranche 7 — arrow-key directional focus · **predicted +2** · LARGE

Bucket E. 998 lines of acceptance for a two-test yield — schedule last
despite `tab_ordering_arrows` looking dramatic.

### Tranche 8 — `startDrag(lockCenter)` deferral · **predicted +1** · TRIVIAL

Bucket I. Fold into whichever tranche is already touching the drag code.

### Won't-do in this arc

- **Bucket J** (4 tests) — dual-VM; `feature-priority-map.md` arc 8.
- **Bucket K** `tab_ordering_properties` (1 test) — the load-bearing part
  is "builtin display classes are not sealed", which is an AVM2 object-model
  question with corpus-wide blast radius, not an input question.

**Arc total if tranches 1–8 land: +30**, leaving 5 dispositioned
(4 dual-VM + 1 sealed-classes).

---

## 6. Postmortem

*(Filled in per tranche as each lands — actual vs predicted, and why any
prediction missed. Nothing here until CI has reported.)*

---

## 7. Commits

| Tranche | Commit | CI | Yield |
|---|---|---|---|
| triage | (this doc) | — | — |
