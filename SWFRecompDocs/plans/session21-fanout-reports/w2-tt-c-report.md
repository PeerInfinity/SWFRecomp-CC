# w2-tt-c: AVM1 single topmost roll pick (`avm1/hitarea_remove_owner_drag`)

**New files: none.** The deliverable is `w2-tt-c.patch` only. It touches one file,
`SWFModernRuntime/src/actionmodern/action.c`, with +58 lines and no deletions. It is a runtime-only
change.

## Verdict

**GO. +1: `avm1/hitarea_remove_owner_drag` goes from `output_mismatch` to `pass` (graphics mode, local).**

Local runs showed no regressions:
- 16 of 16 observable canaries hold their status (all graphics mode).
- The 4 `ruffle_matched` KF rows give byte-identical raw output before and after the patch.

Suggested CI: `mode=graphics`, `categories=all`. The change is in shared runtime code (not
NO_GRAPHICS-only) and does not touch AVM2 emission.

## Re-verification at HEAD (835d9f539)

- Before the patch the headline gave 11 actual lines against 10 expected. Our output was exactly
  `output.txt` plus one spurious `rollover Z` at line 3. This matches the w1 report §6.
- The row is not in any disposition doc or ignore list. It is not `known_failure`. There is no
  STRIKE on the family in `polish-sweep-arc.md`.

## Mechanism and patch

Ruffle picks roll targets with `mouse_pick_avm1` (`movie_clip.rs:2994`). It returns **one**
button-mode clip per pick: the first hit in render order.
- An ancestor is returned before its children.
- Among siblings, the higher depth comes first.
- Non-button-mode clips do not occlude.

`actionDispatchMCMouseMove` decided `now_inside` for each clip independently. At (100,100) both
btnZ (depth 1) and btnRm (depth 2) therefore rolled over.

The patch adds three `static` helpers just above `actionDispatchMCMouseMove` and changes 2 lines
inside it:
- `ng_roll_pick_candidate(mc)`: a sprite clip with an own button handler
  (`actionMCHasButtonHandlers`). DefineButton wrappers (`is_button_mc`) and text fields are
  excluded.
- `ng_roll_pick_order_cmp(a,b)`: a render-order key.
  - It walks both parent chains to the first divergent level and compares `depth` there.
  - An ancestor ranks above its descendants.
  - This replaces `ng_hit_order_cmp`, which the w1 report showed is wrong across parents.
- `ng_roll_pick_topmost(mx,my)`:
  - It runs after `mc_hit_area_pick_begin`, so hitArea resolution, masking and mid-pick removal
    are already applied.
  - It considers visible candidates whose `mc_hit_pixel_aabb_ng` contains the point, excluding
    any removed mid-pick.
  - It returns the topmost one.
- In the dispatch loop, candidates get `now_inside = (mc == roll_picked)`. Clips that are not
  candidates keep their old per-clip test. The existing button-mode-ancestor `continue` is
  unchanged.

## Tests run (all `--mode=graphics --recompile`, sequential, test dirs copied into the worktree)

| test | baseline (results_graphics @ s21 baseline) | after patch |
|---|---|---|
| avm1/hitarea_remove_owner_drag | output_mismatch 2/10 (reproduced locally at HEAD) | **pass** |
| gnash misc-ming ButtonEventsTest (KF) | ruffle_matched | ruffle_matched, raw output md5-identical A/B |
| gnash misc-ming DragDropTest (KF) | ruffle_matched | ruffle_matched, raw output md5-identical A/B |
| gnash misc-ming DefineTextTest (KF) | ruffle_matched | ruffle_matched, raw output md5-identical A/B |
| gnash misc-ming ButtonPropertiesTest (KF) | ruffle_matched | ruffle_matched, raw output md5-identical A/B |
| avm1/drag_over_from_outside | pass | pass |
| avm1/hitarea_sweep | pass | pass |
| avm1/focus_mouse_rollout | pass | pass |
| avm1/tab_ordering_events_mouse | pass | pass |
| avm1/hitarea_lazy_getter | pass | pass |
| gnash misc-ming ResolveEventsTest | pass | pass |
| avm1/hitarea_remove_sibling | pass | pass |
| avm1/mouse_hover_events_while_dragging | pass | pass |
| from_shumway/avm1/hitarea | pass | pass |
| avm1/drag_over_without_startdrag | pass | pass |
| avm1/hittest_morph_input | pass | pass |
| gnash misc-ming RollOverOutTest | pass | pass |
| regression/avm2_simplebutton_click (regression-suite check) | pass | pass |

How the A/B was done:
- Both legs used `--save-actual`.
- The baseline leg ran from the same worktree with `git apply -R` applied. The patch was
  re-applied afterwards.
- Logs and actuals: `<scratchpad>/w2-tt-c/{after,afterB,before}/`.

## Canary scoping: which rows can observe the change

The w1 report counted about 60 rows with mouse input. I narrowed that set by argument rather than
running all of them.

`actionDispatchMCMouseMove` has only four visible effects, all AS calls: `onRollOver`,
`onRollOut`, `onDragOver` and `onDragOut`. The fields it writes (`mc_mouse_inside`,
`g_mouse_hovered_mc`) are read only by the tab/focus hover code. That code also becomes visible
only through `onRollOver`/`onRollOut` calls.

So a test can observe the change only if the SWF contains one of those four handler-name strings.
The method:
- Take all 95 corpus rows whose `input.json` contains `MouseMove`, across all suites including
  `regression`.
- Decompress every `.swf` in each row's directory, including loaded children.
- Grep for `on(RollOver|RollOut|DragOver|DragOut)`. The script is `<scratchpad>/w2-tt-c/swfstr.py`
  and its output is `mm_swfstr.txt`.
- **17 rows contain one** (the table above, less the regression row). All 17 were run.

**The other 78 were excluded because they contain no such string.** This covers:
- the w1-named `edittext_onscroller` and gnash `PrototypeEventListeners` / `key_event_test`;
- `from_shumway/avm1/nested-button` and `rollover` (these use DefineButton `on(...)` actions,
  which go through tag.c's separate hover machine);
- `from_shumway/avm1/mouse-transparency`;
- every AVM2 row (`actionDispatchMCMouseMove` walks only AVM1 `child_mc_cache`).

`regression/avm2_simplebutton_click` was the only regression-suite mouse row. It was run anyway
and holds `pass`.

One residual gap: a handler name built at runtime from string concatenation would slip past the
grep. No such row is known.

## Refutations and pricing notes

- The w1 recipe held. The drag clip (depth 3, `onPress`) is topmost during the drag, and that does
  no harm because rollover is gated on the button being up. The `dt:` lines come from
  `ng_update_drag_droptarget`, which the patch leaves untouched.
- The w1 report said "~55-62 mouse canaries". The observable set is 17. The rest cannot see the
  change.

## Out of scope (unchanged, candidate leads)

- **DefineButtons and selectable EditTexts do not occlude sprite clips in this pick.** Ruffle's
  render-order walk returns them too. A DefineButton above a button-mode sprite would suppress the
  sprite's rollover in Ruffle but not here. No corpus row observes this. Completion mechanism: add
  `is_button_mc` / interactive-TextField occluders to `ng_roll_pick_topmost`, using a real button
  hit test.
- **`actionDispatchMCPress` / `actionDispatchMCRelease` still fire on every containing clip.**
  Press has the same single-pick bug. The same helper, `ng_roll_pick_topmost`, would complete it.
  It needs its own canary set: rows with `onPress`/`onRelease` strings, which is a much larger set.
- **Clip-depth masks (`clip_depth > 0`) inside the pick walk are not modelled.**
- **tag.c `ng_update_button_states`** is DefineButton's independent hover machine.

## New unclaimed leads

- Press/release single pick (above). It is the natural next slice and reuses this patch's helpers.
