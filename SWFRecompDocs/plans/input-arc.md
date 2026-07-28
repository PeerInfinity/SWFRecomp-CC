# Input arc — triage + tranches

**Created**: 2026-07-28 · **Baseline**: `ab92ddfbc` (session start), per-suite
`_results/results_graphics.json` from CI `30185616752`/`30327940850` (the
`38aa0a300` results merge).
**Status**: **ARC CLOSED.** All 8 tranches shipped — `9263f71a0` (**+10** vs
predicted 7), `786d765ee` + `b27909297` (**+12**, exactly the predicted
5 + 7), then the closeout `803055ca5` / `5231abf0c` / `5f48fecd7` /
`bbefcf376` (**+7**, including tranche 7 which the plan had deferred).
**+29 total against a predicted +30**, zero regressions in any tranche.
Closeout CI `30397635331` (graphics/full) is green on all 34 jobs and lands
**+7 exactly as predicted**: corpus effective 3883 → **3890 / 4420**, `avm2`
920 → **926 / 1221**, `from_shumway` 179 → **180**, zero `matching_lines`
drops corpus-wide and no `compile_fail` / `segfault` / `timeout` bucket.
Postmortems in §6; every one of the 36 scoped tests is reconciled in §8 —
29 shipped, 2 open with a named blocker, 5 dispositioned out.

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

### Tranche 2 — mask + non-interactive + text hit-testing · **predicted +5** · MEDIUM · **SHIPPED `786d765ee`, +5**

Bucket F. Ruffle `display_object.rs::hit_test_shape` with
`HitTestOptions::MOUSE_PICK`, plus mask intersection in the pick walk and
TextField box geometry. Depends on tranche 1 for coordinate precision.

### Tranche 3 — caret placement + mouse selection · **predicted +7** · MEDIUM · **SHIPPED `b27909297`, +7**

Bucket G plus the four `text/text_caret_placement_*` riders. One mechanism:
map a stage point to a character index in the EditText layout, then wire
press/drag/release and double/triple click on top. AVM1's
`edittext_focus_selection` family already does this, so the layout query
exists to copy.

### Tranche 4 — focus event model · **predicted +4** · MEDIUM · **SHIPPED `5f48fecd7`, +2**

Bucket D. `mouseFocusChange` must fire unconditionally with the correct
`relatedObject`, and the automatic tab order must agree with Ruffle for
SimpleButton-shaped bounds and for `root.tabChildren = false`.

### Tranche 5 — IME composition · **predicted +2** · SMALL-MEDIUM · **SHIPPED `5f48fecd7`, +2**

Bucket B's other half. Parse `IME_PREEDIT`/`IME_COMMIT` in
`avm2_input_load`, route to a new `avm2_text_ime_compose/commit` mirroring
`actionTextFieldImeCompose/Commit`, and add the composition-active flag
that swallows key events.

### Tranche 6 — `TextEvent.LINK` · **predicted +2** · SMALL-MEDIUM · **SHIPPED `5231abf0c`, +1**

Bucket H. Anchor spans already have to exist for HTML rendering; the work
is hit-testing them on click and dispatching the event.

### Tranche 7 — arrow-key directional focus · **predicted +2** · LARGE · **SHIPPED `bbefcf376`, +1**

Bucket E. 998 lines of acceptance for a two-test yield — schedule last
despite `tab_ordering_arrows` looking dramatic. (The LARGE label did not
survive contact — see §6.)

### Tranche 8 — `startDrag(lockCenter)` deferral · **predicted +1** · TRIVIAL · **SHIPPED `803055ca5`, +1**

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

### Tranche 1 — SHIPPED `9263f71a0`, CI `30381234241` (graphics, full)

**+10 actual vs +7 predicted**, zero regressions, zero `matching_lines`
drops anywhere in the corpus. Corpus effective **3860 → 3870 / 4419**;
`avm2` **902 → 912 / 1221 (74.7%)**; every other suite flat. Status
histogram moved only `output_mismatch 551 → 541` / `pass 3619 → 3629`;
`ruffle_matched` (241), `runtime_error` (7) and `recomp_fail` (1) all flat,
and there is no `compile_fail`, `segfault` or `timeout` bucket in the run.

All eight predicted targets landed:

| Test | before | after |
|---|---|---|
| `mouseevent_stagexy` | 1/35 | pass |
| `mouseevent_valueof_tostring` | 24/28 | pass |
| `mouseevent_constr` | 62/66 | pass |
| `focusrect_focuslost` | 7/9 | pass |
| `focusrect_property` | 104/110 | pass |
| `tab_ordering_stage_tab_children_remove_root` | 3/5 | pass |
| `mouse_wheel_events` | 33/36 | pass |
| `tab_ordering_tabbable` | 45/47 | pass |

Plus **two riders the triage listed under tranche 4, not tranche 1**:

- **`tab_ordering_stage_tab_children`** (15/32 → pass). §2 bucket D split
  this into two defects — "half is the Stage-tabChildren proxy, the rest is
  that `root.tabChildren = false` must actually stop traversal". The second
  half did not exist: `fill_tab_order` already gates on the root's flag.
  Nothing ever *set* that flag, because the Stage setter stored it on the
  Stage's own ext. One fix, not two.
- **`focus_events_key_basic`** (33/132 → pass). §2 bucket D guessed
  correctly here — "automatic-order key computation for objects whose
  bounds come from a SimpleButton state (same family as
  `tab_ordering_tabbable`)". The consequence is that the
  `highlight_bounds` fix is worth two tests, not one.

### Where the triage was wrong, and the transferable lesson

Item 8's diagnosis hedged: "suspect the empty-bounds path **or** the
equal-key dedup". It was **both, in sequence** — and the ordering is the
lesson. `obj_world_topleft` mapped invalid bounds to the *origin*, which
gave a stateless `SimpleButton` the key `0`; the equal-key dedup — which
reading `focus_tracker.rs::AutomaticTabOrdering::ignore_duplicates`
confirmed is **correct and deliberately matches Flash** — then dropped it
against `clip9.text`, also at `(0,0)`. The mechanism that visibly discarded
the object was not the bug. **When a correct-looking mechanism produces a
wrong result, check its input before changing the mechanism.**

The narrower miss underneath it: the triage said SimpleButton bounds were
"empty". Ruffle distinguishes *empty* from `Twips::INVALID` (`0x7ffffff`),
and `Matrix * Rectangle::INVALID == Rectangle::INVALID` — so an invalid
rect sorts to the far end of the order, not to the front. That distinction
is the entire defect.

### Partial credit visible in the rider sweep

`mouse_pick_masking` went from *all seven* lines differing to two matching:
the coordinate truncation was real and is gone, and what remains there is
genuinely mask hit-testing (tranche 2). `focus_events_mouse_focusable`
stayed at 110/112, which confirms its two lines are purely the
`mouseFocusChange` `relatedObject` model (tranche 4) with no coordinate
component. Both readings tighten tranche 2 and 4's predictions.

### Process notes

1. **The §0 truncation caveat paid for itself.** `focusrect_property`
   really was the six-line fix the JSON implied; `tab_ordering_properties`
   was a 173-line, three-cause test that would have blown this tranche had
   it been sized from the JSON. Deferring it to bucket K was right, and the
   local re-run is what showed why.
2. **Every item was a Ruffle-source read, not a guess** —
   `mouse_event.rs::local_to_stage_x`, `stage.rs::set_tab_children` +
   `Stage.as:169`, `MouseEvent.as`'s `[API("662")]` block,
   `edit_text.rs::event_dispatch`, `avm2_button.rs::highlight_bounds`,
   `focus_tracker.rs::AutomaticTabOrdering`. That is the same pattern that
   made the Loader arc's predictions hold, and the one prediction that
   needed correcting (item 8) is the one where the first read stopped one
   level too shallow.

### Regression evidence

58 tests re-run locally before the push (38 blast-radius canaries + the 20
remaining arc tests), zero regressions, and CI agrees. Load-bearing
canaries green: `mouse_children` 192/192, all four passing
`tab_ordering_*`, all eight `focus_*`, the whole `mouse_*` dispatch set,
`asymmetric_key_events` and `focus_events_mixed_key_mouse` (the other two
tests whose `input.json` carries `FocusLost`), `from_shumway/mouse/`
`{mouse_coords,start_drag}` (which print MouseEvent coordinates through the
changed twips path), and all three `visual/focus_highlight/*` AVM2 tests
(which consume the bounds code the tab-order fix changed). The link
canaries `verify_method_info_{oob,duplicate}` and `mixed_avm/avm1_loads_
avm2` still compile, link and run at their pre-existing `output_mismatch`.

---

### Tranches 2 + 3 — SHIPPED `786d765ee` + `b27909297`, CI `30389013458`

Both shipped in one graphics/full run, success, all 30 shards. **+12 actual vs
+12 predicted**, zero regressions, zero `matching_lines` drops corpus-wide.
Corpus effective **3871 → 3883 / 4420**; `avm2` **912 → 920 / 1221 (75.3%)`,
`text` **5 → 9**; every other suite flat. The histogram moved only
`output_mismatch 541 → 529` / `pass 3630 → 3643`; `runtime_error` (7) and
`recomp_fail` (1) flat, and the run carries no `compile_fail`, `segfault` or
`timeout` bucket.

The 12 flips are exactly the 12 named targets — no riders in either
direction, which is itself worth recording after tranche 1's +3 of them. One
extra move that does not change the effective count but is a real upgrade:
**`from_shumway/hittesting/mask-hit-test` went `ruffle_matched → pass`** —
with shape-accurate masks it now matches the test's own `output.txt` rather
than only matching Ruffle's divergent output.

### Tranche 2 — `786d765ee`

**+5 actual vs +5 predicted.** All five bucket-F targets flipped:
`mouse_pick_masking` (0/7), `mouse_pick_dobj_mask` (2/4),
`mouse_pick_non_interactive_dobj_mask` (0/3),
`mouse_pick_non_interactive_bitmap_mask` (2/4), `mouse_pick_text` (4/8).

Three mechanisms, all read off Ruffle rather than inferred:

1. **Shape-accurate hit testing.** The pick was an AABB test. Placed
   `DefineShape` characters now test the triangulated `shape_data` rows the
   renderer already carries, and drawing-API content tests the `Avm2GfxPath`
   tessellation — so the answer is a point-in-triangle sweep, not a rectangle.
   Bitmap / TextField / StaticText deliberately keep the box, which is exactly
   where Ruffle's `DisplayObject::hit_test_shape` default ("default to using
   bounding box") sits: only `graphic.rs` and `movie_clip.rs` override it.
   This is what lets `mouse_pick_masking`'s tilde-shaped clip mask reject a
   point that is inside its own AABB.
2. **`masker` / `maskee`.** The ext had `mask` but no back-pointer;
   `set mask` now keeps the pair symmetric the way `DisplayObject::set_mask`
   does. Both directions matter — a masked object misses outside its mask, and
   a mask is never itself a target.
3. **Timeline clip layers.** Children with `clip_depth > 0` are skipped as
   targets and instead mask the range `(depth+1 ..= clip_depth)`, through
   Ruffle's single reversed peekable cursor shared across both the interactive
   and non-interactive child passes.

**What the triage got wrong.** §2 bucket F said `mouse_pick_masking` needed the
masked object to "pick as its mask's intersection". That reading is backwards:
the mask is not intersected with anything, it is *consulted* — the pick either
proceeds or turns into a `Miss`. And the test's actual blocker was the
*timeline* clip-depth path (`maskObject`/`maskObjectChild` are clip layers),
not the scripted `DisplayObject.mask` path the bucket described. Same file,
different mechanism.

**Two riders the bucket did not predict, both required for its own tests.**

- **`local_mouse` had to snap to whole twips.** Ruffle's `global_to_local`
  returns a `Point<Twips>`, so `localX`/`localY` are *always* an exact twip
  count; `stageX`/`stageY` map that back through `Twips::from_pixels`, which
  **truncates**. An unsnapped local landing a hair below a twip boundary
  therefore came back one twip short — `mouse_pick_masking` printing 282.75
  for an expected 282.8, and four such values in `mouse_pick_text`. Tranche 1
  fixed the *model* of `stageX` (the three-branch `local_to_stage_x`); this is
  the other half, and it was invisible until the mask work made the rest of
  those two tests line up.
- **A whole class of mouse events is suppressed at dispatch.**
  `mouse_pick_text`'s spurious fifth `mouseDown` was not a hit-test error at
  all: Ruffle's `interactive.rs::event_dispatch_to_avm2` opens with "Flash
  appears to not fire events *at all* for a targeted EditText that was
  originally created by the timeline" when that field is selectable. The pick
  deliberately still *hits* such a field (that is what raises the I-beam
  cursor); the event is dropped one layer later. Reading only `mouse_pick_avm2`
  would have sent this the wrong way — the test's own source comment
  ("Uncomment this line ... a new event should get generated") is the clue that
  a hit was happening and the *event* was missing.

**Regression evidence.** ~55 tests locally, all byte-identical to the tranche-1
baseline: `mouse_children` 192/192, the whole `mouse_*` / `focus_*` /
`tab_ordering_*` dispatch set, all six `visual/focus_highlight/*`,
`from_shumway/mouse/{mouse_coords,start_drag}`, the `graphics_*` drawing tests
(whose tessellation the pick now reads), `getobjectsunderpoint` /
`MaskTest{,-2,-3}` / `clipping` / `hitTestStyleChange` / `invalidClipDepth`,
and the link canaries `verify_method_info_{oob,duplicate}` +
`mixed_avm/avm1_loads_avm2`.

### Tranche 3 — `b27909297`

**+7 actual vs +7 predicted.** `textbox_click` (1/37),
`edittext_mouse_selection` (334/363), `selection` (229/239), and all four
`text/text_caret_placement_*` riders.

The core is a port of `edit_text.rs`: `screen_position_to_index`
(local twips → layout coords → `find_line_index_by_y` → closest text box →
the glyph whose half-advance the point passes), then `handle_click` /
`handle_drag` on top, with the selection mode taken from the click index
(0 character, 1 word, 2+ line) and a drag spanning the anchor's and the current
position's selections *in that same mode*. Wiring detail that matters: the
press runs **before** `update_focus_on_press` (Ruffle's dispatch loop is
`handle_clip_event` → focus → `event_dispatch_to_avm2`), and the drag follows
the **pressed** object rather than the hovered one, so a selection keeps
extending after the cursor leaves the field.

**Where the triage was wrong — twice, and both times about which VM/mechanism
owned the test.**

- **`selection` (229/239) is not a mouse test.** It has no `input.json` at all.
  Its four remaining diffs are `TextField.caretIndex`, which Ruffle defines as
  `selection.to()` — the *moving* end, not the numerically larger one. The two
  differ exactly on a right-to-left selection: `setSelection(5, 2)` reads
  caretIndex 2 / begin 2 / end 5, and we read 5. A one-line fix that the bucket
  had filed under "off-by-one during `text_input`".
- **`text_caret_placement_translated_bounds` is an AVM1 test.** §3 filed all
  four `text_caret_placement_*` riders together, and the other three are AS3 —
  but this one is AVM1 (`Mouse.addListener` / `Selection.setFocus`), so no
  amount of AVM2 work could move it. Its real defect was in
  `ng_shared.c::ng_getCharIndexAtPoint`, which never clamped its target line:
  Ruffle's `find_line_index_by_y` returns `Err(max_line)` past the end, so a
  click below the text lands on the *final* line. The field's box is 197px tall
  for two lines of text, so six of its clicks sit in that empty region. §3's
  claim that "the four show the same single symptom ... so they are one fix,
  not four" was right about the symptom and wrong about the count: it was two
  fixes, one per VM.

**One thing the triage got right that was worth the caution.** §5 called this
"one mechanism ... AVM1's `edittext_focus_selection` family already does this,
so the layout query exists to copy". The AVM1 query existed but was not
reusable (different layout model, different text storage), so the AVM2 side is
a fresh port of Ruffle rather than a copy of `action.c`. The *value* of the
AVM1 side turned out to be different: it is the regression oracle. 17 AVM1
text canaries pin the shared `ng_shared.c` change.

**Two details that only the corpus could have told us.**

- An empty line still resolves. Ruffle's layout gives it a box with an empty
  text range, so `font.evaluate` never fires and the result stays at the box's
  start — that is what puts `textbox_click`'s caret at 97 and 98 on two
  consecutive empty lines. Returning "no box → caret at end of text" (the
  literal reading of `screen_position_to_index`'s `None`) collapsed both to
  123 and, because the test only traces on *change*, desynchronised the whole
  remaining transcript. A 36-line diff from one boundary case.
- `edittext_mouse_selection`'s double/triple clicks are driven by explicit
  `index` fields in `input.json` (47 of its 83 `MouseDown`s carry 1, 2 or 3),
  so no time/distance click-index inference was needed. Worth recording
  because the opposite would have been a determinism hazard: Ruffle's real
  rule is a 500 ms + 2px window against a wall clock we do not have.

**Regression evidence.** 60+ tests locally, zero changes: all 17 AVM1
`edittext_*` / `selection*` / `text_blocks_clicks` canaries (`ng_shared.c` is
shared AVM1 layout code — `edittext_place_caret`, `edittext_drag_select`,
`edittext_focus_selection`, `edittext_align/scroll/hscroll/leading/margins`),
the 19-test AVM2 edittext/textfield input set, and the four `from_shumway`
hit-test/mask tests verified **byte-identical against a stashed session-start
build** rather than against the results JSON — the JSON's `matching_lines` is
too coarse to distinguish "same failure" from "different failure of the same
size", and three tests in the `ruffle_matched` bucket looked like regressions
under the coarse check and were not.

### Closeout — tranches 8, 6, 4, 5, 7 — `803055ca5` / `5231abf0c` / `5f48fecd7` / `bbefcf376`

All five remaining tranches shipped in one session, one CI run,
`30397635331` (graphics/full, success, all 34 jobs). **+7 effective,
exactly the number predicted going in**: +6 for tranches 4/5/6/8 against
the plan's +9, plus +1 from tranche 7, which the plan had deferred. Corpus
effective 3883 → 3890 / 4420; the status histogram moved only
`output_mismatch 529 → 522` / `pass 3643 → 3650`, with `ruffle_matched`
(240), `runtime_error` (7) and `recomp_fail` (1) all flat and no
`compile_fail` / `segfault` / `timeout` bucket in the run. The seven flips
are exactly the seven named targets — no riders in either direction. No tranche's *mechanism* fell short: the two missing tests were
both scoping errors made at triage time, and both had already been paid for
or belong to another VM. Details per tranche below; the reconciliation of
all 36 scoped tests is §8.

Order shipped was by ascending risk (8 → 6 → 4+5 → 7), not by the plan's
yield ranking, because 4 and 5 both edit the same input path and had to be
verified against each other.

#### Tranche 8 — `803055ca5` · **+1 vs +1**

`from_shumway/mouse/start_drag_lock`. Ruffle's `Sprite.startDrag` only
*records* the drag; `Player::update_drag` moves the object, and it runs at
the top of mouse-event handling and at the end of each frame — never inline
from `startDrag`. We called `update_drag` from `do_start_drag`, so
`startDrag(true)` inside a mouseDown handler snapped the object to the
cursor before the handler's next statement. The test's own source comment
("in FP x and y will update in about 70-100ms") is the spec. Also mirrors
`stop_drag`'s own `update_drag` call, which exists for the
`startDrag(mc); stopDrag();`-in-one-go case.

#### Tranche 6 — `5231abf0c` · **+1 vs +2**

`avm2/textfield_event` (0/66 → pass), first try. The span's `url` was
already parsed from `<a href>`; the Press arm just never consulted it.
Ruffle resolves the clicked index to a span, and a non-empty `url` goes to
`open_url`, whose `event:` branch dispatches `TextEvent("link",
bubbles=true, cancelable=false)`. One structural detail matters: the
selectable gate lives inside `handle_click`, and the link lookup sits
*outside* it — a non-selectable field still opens links.

**The missing +1 is the third instance of the same triage error.** §3 filed
`text/links_in_scrolled_text` as this tranche's rider on the strength of its
symptom (a click on an `<a>` doesn't fire). It is an **AVM1** test —
`asfunction:callback` — exactly like tranche 3's
`text_caret_placement_translated_bounds`. Twice now, a rider grouped by
symptom crossed a VM boundary. AVM1 already has the `asfunction` path; its
real gap is that `ng_shared.c::ng_getCharIndexAtPoint` splits lines on
`\r`/`\n` only — **no word wrap** — and ignores `scroll`. Instrumented, the
click at (210, 263) resolves to char 337 when the anchor run is at 707..710:
the field is 273px wide with 14 wrapped paragraphs and `scroll = 100`, so
the index is off by the entire wrapping. Fixing it needs a wrap-aware line
enumerator in `ng_shared.c` (the segmentation exists inside
`ng_wrap_count_lines` / `ng_computeScrollMixedFont` but neither emits line
*start offsets*) plus the vertical scroll offset. Left open — it is an AVM1
text-layout job, not a `TextEvent` job.

#### Tranche 4 — `5f48fecd7` · **+2 vs +4**

`focus_events_mouse_focusable` (110/112) and `focus_events_mouse_basic`
(30/260). Three defects in `update_focus_on_press`, all from the same
misreading — that focus-on-press is a search for something focusable:

1. We walked up to the nearest mouse-focusable ancestor and used it as both
   the candidate *and* the event's `relatedObject`. Ruffle uses the
   **pressed object itself**; the pick already propagates to the parent when
   a child is not a valid target, so the walk is redundant *and* wrong.
2. We gated the `mouseFocusChange` on the focus actually moving. Ruffle
   gates on `old != pressed`. That is what makes the event fire on the Stage
   with `relatedObject` set and `stage.focus` still `null` — the filter to
   something focusable (`new.filter(is_focusable_by_mouse)`) happens *after*
   the event, not before it.
3. `preventDefault()` was ignored.

Plus `is_focusable_by_mouse`, which read only an explicitly assigned
`tabEnabled` where Ruffle's is `is_action_script_3() && tab_enabled()` —
and `tab_enabled` carries the per-type default.

**The shortfall is bookkeeping, not a miss.** Bucket D's other two tests,
`focus_events_key_basic` and `tab_ordering_stage_tab_children`, had already
flipped as tranche 1's riders (§6, tranche 1) — they are counted there. The
reachable yield here was +2 the moment tranche 1 landed, and the
post-tranche-3 sweep quoted in §7 recorded exactly that (it lists only the
two remaining tests at their unchanged line counts). **A prediction is stale
the moment an earlier tranche collects one of its tests; the arc total is
right, the per-tranche number is not.**

#### Tranche 5 — `5f48fecd7` · **+2 vs +2**

`ime_linux_dead_keys` (0/10) and `edittext_ime_focus_lost` (0/9). The
harness had emitted `IME_PREEDIT`/`IME_COMMIT` all along and the runtime
had the enum values — nothing parsed or routed them. The port is
`edit_text.rs::ime` plus `ensure_ime_{started,finished,committed}`: a
preedit is live uncommitted text that shows and counts towards
`text`/`length` but fires no `textInput`; only a Commit, or losing focus
with a composition open, turns it into real input. The focus-loss commit
hangs off `set_focus` **before** the focusOut dispatch, matching Ruffle's
`on_focus_changed` → `call_focus_handler` order.

**Where the triage was wrong.** §5 specified "a composition-active flag that
swallows key events". No such flag exists anywhere in Ruffle. What actually
suppresses the dead-key `Unknown` releases — and the `Char('a')` release
that an IME commit stands in for — is a plain bookkeeping rule in
`input.rs`: **a KeyUp is dropped unless a KeyDown claimed the same
(physical key, location).** Its own comment says "Ignore spurious KeyUp
events that may happen e.g. during IME", but it is not IME state; it is
symmetric key accounting that IME merely exposes. Guessing the flag would
have produced a mechanism that passes these two tests and diverges on every
unpaired key event elsewhere. `avm2/asymmetric_key_events` — the test built
specifically around unpaired key events — is the canary that proves the
real rule, and it stayed green.

Modelled with the Flash keyCode rather than a winit `PhysicalKey`, which is
1:1 for every key the corpus exercises ('a'/'A' both 65/KeyA, `"`/`'` both
222/Quote, unmapped 0/Unknown on both sides).

#### Tranche 7 — `bbefcf376` · **+1 vs a deferral**

The plan deferred this ("LARGE, worst yield-per-effort in the arc") and the
closeout brief allowed building it only if a reading showed the triage had
oversized it. It had. **The LARGE label was read off
`tab_ordering_arrows`'s 998-line `output.txt` — that file is the acceptance
table, not the work.** The test is ~60 declarative stages × 4 directions
driven by one algorithm, and the algorithm —
`focus_tracker.rs::NavigationOrdering::key` — is **~90 lines of rectangle
arithmetic in one file**, no new subsystem. Sizing a task by its test's line
count is the same mistake in the opposite direction from §0's truncation
caveat: there, a 2-line JSON diff hid a 173-line test; here, a 998-line
transcript hid 90 lines of code.

`focus_events_key_navigation` (12/53) flipped, including its cancel branch.
`tab_ordering_arrows` did **not**, and is left open — but CI puts it at
**645/998 matching lines, up from 1**, and every remaining diff is the same
non-navigation cause (below). That number is the evidence the algorithm
itself is right.

**The finding that came out of it, and it is the arc's most reusable.**
Making the navigation keys agree required **snapping highlight bounds to
whole twips**. Ruffle's bounds are `Rectangle<Twips>` — integers — and ours
were doubles. The keys compare rectangle edges with exact `<=`, and the
"Size vs distance behind" stage puts two objects' `y_max` EXACTLY on the
origin's: a sprite scaled to `height = 12` over 10px of content lands at
12.0000005px and flips the comparison, focusing an object Flash excludes.
That one snap moved the first navigation divergence from line 132 to line
634, and the test from 1 to 645 matching lines.

This is the **third** appearance of the same lesson in this arc — after
tranche 1's `Twips::INVALID` (invalid bounds are a sentinel, not the origin)
and tranche 2's `local_mouse` snap (localX/localY are always an exact twip
count). **Ruffle's geometry is integer twips, and the quantization is
load-bearing, not cosmetic. Any time a port compares Ruffle coordinates for
equality or ordering, quantize first.**

What still blocks `tab_ordering_arrows` is the same root cause one layer
out: the **DisplayObject property getters** return unquantized geometry
(`h=20.999999046325684` where Flash prints `21`), and the test's own
mirroring arithmetic is built on those getters, so positions drift a twip
(`dx=-10.050000000000011` for `-10`). Quantizing `width`/`height`/`x`/`y`
corpus-wide is a change with blast radius far beyond this arc; recorded here
as the one thing that would close bucket E.

### Regression evidence — closeout

Sweeps were run per tranche and then once cleanly over the union: **64 AVM2
tests** after tranches 4+5+6+8 and **28 more** after tranche 7 — every
`focus_*`, `tab_ordering_*`, `mouse_*`, `mouseevent_*`, `edittext_*`,
`textfield_*` and `key_input_*` test, plus `mouse_children` (192/192),
`loader_noninteractive_try_click_root`, and the link canaries
`verify_method_info_{oob,duplicate}`. Load-bearing greens:
`asymmetric_key_events` (the KeyUp rule) and `tab_ordering_automatic_
advanced` (the test built by bisecting coordinates to pin the 6y+x order —
the one most exposed to the twips snap).

Every failure in both sweeps was pre-existing and verified so, not assumed:
`textfield_input_events` and `mouse_pick_loader_avm1` by **byte-diffing the
actual output against the CI baseline's**, `verify_method_info_*` against
their recorded `output_mismatch`, and `tab_ordering_properties` by the
stronger argument that it ships no `input.json`, so none of this session's
code paths execute in it at all.

**One process failure worth recording.** Mid-sweep source edits produced a
phantom regression: `mouse_pick_button_mode` came back FAIL while
`avm2_text.c` was being edited under a running sweep, and passed on a clean
re-run. `verify_output.py` rebuilds the runtime per test, so **a canary
sweep and a source edit cannot overlap** — the sweep grades whatever the
tree happens to contain at each test's build. The tranche-4 sweep was
discarded and re-run clean for this reason.

---

## 7. Commits

| Tranche | Commit | CI | Yield |
|---|---|---|---|
| triage | `f410cc9f3` | — (docs only) | — |
| 1 | `9263f71a0` | `30381234241` graphics/full, success | **+10** (pred. 7) |
| 2 | `786d765ee` | `30389013458` graphics/full, success (with 3) | **+5** (pred. 5) |
| 3 | `b27909297` | `30389013458` graphics/full, success | **+7** (pred. 7) |
| 8 | `803055ca5` | `30397635331` graphics/full, success | **+1** (pred. 1) |
| 6 | `5231abf0c` | `30397635331` graphics/full, success | **+1** (pred. 2) |
| 4+5 | `5f48fecd7` | `30397635331` graphics/full, success | **+4** (pred. 6; 4 was +2 not +4) |
| 7 | `bbefcf376` | `30397635331` graphics/full, success | **+1** (was deferred) |

**Arc total: +29** against a predicted +30 for tranches 1–8. The single
missing test is `text/links_in_scrolled_text`, which is not an AVM2 test at
all (§6, closeout, tranche 6).

**Remaining after tranche 3**: tranche 4 (focus event model, +4) → 5 (IME,
+2) → 6 (`TextEvent.LINK`, +2) → 7 (arrow-key directional focus, +2, LARGE)
→ 8 (`startDrag(lockCenter)`, +1, trivial). A post-tranche-3 sweep confirms
none of their tests moved as a side effect: `focus_events_mouse_focusable`
110/112, `focus_events_mouse_basic` 30/260, `focus_events_key_navigation`
12/53, `tab_ordering_arrows` 1/998, `textfield_event` 0/66,
`ime_linux_dead_keys` 0/10, `edittext_ime_focus_lost` 0/9 — all unchanged,
so those predictions stand as written. All five shipped in the closeout
session below.

---

## 8. Final scoreboard — all 36 scoped tests reconciled

Every test the §0 census found, and where it ended up. **29 shipped, 2 left
open with a named blocker, 5 dispositioned out at triage.**

### Shipped (29)

| Test | Bucket | Tranche | Before |
|---|---|---|---|
| `mouseevent_stagexy` | A | 1 | 1/35 |
| `mouseevent_valueof_tostring` | A | 1 | 24/28 |
| `mouseevent_constr` | A | 1 | 62/66 |
| `focusrect_focuslost` | B | 1 | 7/9 |
| `focusrect_property` | C | 1 | 104/110 |
| `tab_ordering_stage_tab_children_remove_root` | C | 1 | 3/5 |
| `tab_ordering_tabbable` | C | 1 | 45/47 |
| `mouse_wheel_events` | C | 1 | 33/36 |
| `focus_events_key_basic` | D | 1 (rider) | 33/132 |
| `tab_ordering_stage_tab_children` | D | 1 (rider) | 15/32 |
| `mouse_pick_masking` | F | 2 | 0/7 |
| `mouse_pick_dobj_mask` | F | 2 | 2/4 |
| `mouse_pick_non_interactive_dobj_mask` | F | 2 | 0/3 |
| `mouse_pick_non_interactive_bitmap_mask` | F | 2 | 2/4 |
| `mouse_pick_text` | F | 2 | 4/8 |
| `textbox_click` | G | 3 | 1/37 |
| `edittext_mouse_selection` | G | 3 | 334/363 |
| `selection` | G | 3 | 229/239 |
| `text/text_caret_placement_align` | G rider | 3 | 189/248 |
| `text/text_caret_placement_leading` | G rider | 3 | 183/244 |
| `text/text_caret_placement_scroll` | G rider | 3 | 81/108 |
| `text/text_caret_placement_translated_bounds` | G rider | 3 (AVM1) | 134/140 |
| `focus_events_mouse_focusable` | D | 4 | 110/112 |
| `focus_events_mouse_basic` | D | 4 | 30/260 |
| `ime_linux_dead_keys` | B | 5 | 0/10 |
| `edittext_ime_focus_lost` | B | 5 | 0/9 |
| `textfield_event` | H | 6 | 0/66 |
| `focus_events_key_navigation` | E | 7 | 12/53 |
| `from_shumway/mouse/start_drag_lock` | I rider | 8 | 2/3 |

### Left open with a named blocker (2)

| Test | Bucket | Blocker |
|---|---|---|
| `text/links_in_scrolled_text` | H rider | **AVM1, not AVM2.** `ng_getCharIndexAtPoint` has no word wrap and ignores `scroll`; needs a wrap-aware line enumerator in `ng_shared.c`. Instrumented: resolves char 337 for an anchor at 707..710. |
| `tab_ordering_arrows` | E | **DisplayObject property getters return unquantized geometry.** Navigation itself is correct — CI `30397635331` puts it at **645/998, up from 1**; every residual diff is a printed `width`/`height`/`x`/`y`, or the test's own arithmetic drifting a twip off one. Needs corpus-wide twips quantization of those getters. |

### Dispositioned out at triage (5) — unchanged verdicts

| Test | Bucket | Why |
|---|---|---|
| `focus_events_mixed_avm_edittext` | J | Dual-VM: needs AVM1 handlers and AVM2 `FocusEvent`s interleaved in one player with a shared focus tracker. `feature-priority-map.md` arc 8. |
| `selection_onsetfocus_mixed_avm` | J | Dual-VM |
| `mouse_pick_avm1_root` | J | Dual-VM |
| `mouse_pick_loader_avm1` | J | Dual-VM |
| `tab_ordering_properties` | K | Load-bearing part is "builtin display classes are not sealed" — an AVM2 object-model question with corpus-wide blast radius, not an input question. |

### Predicted vs actual, per tranche

| Tranche | Predicted | Actual | Delta explained by |
|---|---|---|---|
| 1 | +7 | **+10** | Two bucket-D tests collected as riders; `highlight_bounds` was worth two tests, not one |
| 2 | +5 | **+5** | — |
| 3 | +7 | **+7** | — |
| 4 | +4 | **+2** | Its other two tests were tranche 1's riders — already counted |
| 5 | +2 | **+2** | — |
| 6 | +2 | **+1** | Its rider is an AVM1 test |
| 7 | +2 (deferred) | **+1** | Built after all; `tab_ordering_arrows` blocked on getter quantization |
| 8 | +1 | **+1** | — |
| **Total** | **+30** | **+29** | one test, and it is not AVM2 |

### What the arc says about triage

Three of the four per-tranche misses trace to **one** habit: grouping tests
by *symptom* rather than by *which VM or mechanism owns them*. It cost a
rider in tranche 3 (`text_caret_placement_translated_bounds`), a rider in
tranche 6 (`links_in_scrolled_text`), and it is why tranche 4's number went
stale. The fourth (tranche 7's LARGE) was the mirror-image error: sizing
work by its **test's** line count. Both are cheap to avoid — read what the
test asserts and which VM's API it calls before assigning it to a bucket,
and re-check a tranche's prediction whenever an earlier one lands.

Against that, the arc's *mechanism* predictions were near-perfect: every
tranche whose targets it owned outright landed exactly on its number, and
every fix in the arc came from reading Ruffle's source rather than inferring
from a diff. The one place inference was used instead — tranche 5's
"composition-active flag that swallows key events" — described a mechanism
that does not exist.
