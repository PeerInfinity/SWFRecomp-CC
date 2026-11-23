# s26 w2-attached-holder-render: attached-clip render under a holder, button pick order, rollOut/rollOver order, button-EditText path binding

Wave 2 (implementation). Cloud worker, base `origin/master` `91267237`. `SETUP_STATUS`: apt OK, Pillow OK, Dawn OK.
Tests downloaded from upstream Ruffle master **`3e98d9ba6`** (categories avm1, visual, from_gnash, from_shumway;
`regression` is in git). Ruffle source read at the same SHA (blobless clone).

**New files:**
- `SWFRecompDocs/plans/session26-fanout-reports/w2-attached-holder-render-report.md` (this file)
- `SWFRecompDocs/plans/session26-fanout-reports/w2-attached-holder-render.patch`
- `ruffle-tests/tests/swfs/regression/avm1_attached_clip_holder_render/` (`create_test_swf.py`, `test.swf`,
  `test.toml`, `output.txt`, `output.expected.png`)
- `ruffle-tests/tests/swfs/regression/avm1_button_pick_order/` (`create_test_swf.py`, `test.swf`, `test.toml`,
  `input.json`, `output.txt`)
- `ruffle-tests/tests/swfs/regression/avm1_button_textfield_path_binding/` (`create_test_swf.py`, `test.swf`,
  `test.toml`, `output.txt`)

Modified: `SWFModernRuntime/src/libswf/tag.c`, `SWFModernRuntime/src/libswf/tag_stubs.c`,
`SWFModernRuntime/src/actionmodern/action.c`, `ruffle-tests/render_canary_tests.txt` (one member appended at EOF),
`ruffle-tests/tests/swfs/regression/README.md` (three rows).

The patch is `git diff --binary origin/master` over `SWFModernRuntime`, `ruffle-tests/render_canary_tests.txt`,
`ruffle-tests/tests/swfs/regression/README.md` and the three new fixture dirs. I generated it after the final edit and
checked it with `git apply --check -R`. `SWFRecomp/` and `verify_output.py` are unchanged, so no `--recompile` is needed.

## Verdicts

| Item | Verdict | Corpus flips | New rows |
|---|---|---|---|
| 1. OFFSCREEN doesn't draw a clip attached under a `createEmptyMovieClip` holder | **GO, landed** | **0** (no corpus image row reaches it; see the scan below) | `avm1_attached_clip_holder_render` pixel fail→**pass** (max diff 255 → **0**) |
| 2. Depth-interleaved button pick (root walk vs attached walk; attached depth order) | **GO, landed** | **0** | `avm1_button_pick_order` (shared with 3) |
| 3. rollOut-before-rollOver (attached **and root** buttons) | **GO, landed**. It was real for root buttons too | **0** | `avm1_button_pick_order` trace fail→**pass** (2/9 → 9/9) |
| 4. Path-variable binding scope for button-child EditTexts | **GO, landed** (button-parent case only) | **0** | `avm1_button_textfield_path_binding` trace fail→**pass** (2/4 → 4/4) |

All moves are new regression rows. There are **no corpus flips in either direction** on the 231-row sweep in either
mode, and the canary is md5-identical (158/158).

## EXPECTED-FLIP LEDGER (what the coordinator should see on CI)

| Test | Axis | Mode | Before (clean master) | After |
|---|---|---|---|---|
| `regression/avm1_attached_clip_holder_render` | trace | both | (new row) pass (`attached`) | pass |
| `regression/avm1_attached_clip_holder_render` | **pixel** | graphics | (new row) **fail**: 20000 outliers, max 255 | **pass**: 0 outliers, max 0 |
| `regression/avm1_button_pick_order` | trace | both | (new row) output_mismatch 2/9 | **pass** 9/9 |
| `regression/avm1_button_textfield_path_binding` | trace | both | (new row) output_mismatch 2/4 | **pass** 4/4 |

Nothing else should move. Any other pass→fail on CI is a regression from this patch. The rows to look at first are the
`input.json` mouse rows listed in §Evidence.

Pixel fidelity: the holder-render golden is the Ruffle exporter's frame 0. It is solid, pixel-aligned squares with no
AA, so it is exactly 25000 red + 95000 white pixels. My after render matches it with max diff 0 on lavapipe, so the
`tolerance = 1 / max_outliers = 0` bar is safe on CI. (This is a new row, so there was no CI PNG to prove fidelity
against. The 0-diff absolute match against an external oracle serves the same purpose.)

**CI mode:** `tag_stubs.c` is shared by both modes, and the button walk now runs a different algorithm in NO_GRAPHICS
too, so run **both** `graphics` and `no-graphics`, `categories=all`. Item 1 is `#ifdef OFFSCREEN_RENDER` only.

## 1. Attached clip under a holder: mechanism and fix

- **Owner:** `tag.c` `tagShowFrame` and `tagRerenderFrame`, the OFFSCREEN post-loop attached passes. Both had
  `if (mc->parent != &root_movieclip) continue;`, so they drew root-attached clips only. Nested attaches were drawn
  only through `ng_attachMovie`'s `attach_registration` alias (`tag_stubs.c` ~751), which is written **only when the
  parent has a `display_obj` with a `sprite_display_list`**. `h = createEmptyMovieClip()` has neither, so `h.m2` had
  no render route at all.
- **Fix:** a new static helper, `offscreen_attached_pass_member(mc)`. It returns true for root-attached clips. It also
  returns true for a nested clip whose parent has no aliasable `sprite_display_list` (`parent->display_obj == NULL`,
  or its `sprite_display_list == NULL`), as long as the chain is live (no `depth == INT_MIN`) and reaches `_root`.
  Aliased clips stay excluded, so nothing is drawn twice.
  - The helper is used at the 2 filter sites in `tagRerenderFrame` and the 1 site in `tagShowFrame`.
  - `tagRerenderFrame`'s inline draw now gives such a nested clip its world matrix, the same way
    `render_attached_child` does (`compute_mc_world_xform(parent)` × the clip's own AS transform), and skips it when an
    ancestor is hidden. Root-attached clips keep the old code path byte for byte. `compute_mc_world_xform` gets a
    forward declaration under `OFFSCREEN_RENDER`.
- Render order: the existing `attached_sort_render_order` key is the depth path from the stage, so `h.m2` sorts right
  after `h`.
- Phase 1's shell arm (`mc_content_dobj` / `loaded_dl_shell`) is untouched. The membership test reads
  `parent->display_obj`, exactly as `ng_attachMovie`'s alias condition does. A clip attached under a shell-only holder
  (no `display_obj`) is therefore now drawn by the post-loop pass, which is consistent with Flash. No corpus row was
  seen to exercise it (lead 3).
- **Corpus reach:** I decompressed every SWF in avm1, from_gnash, from_shumway, visual and regression and looked for
  `attachMovie` together with `createEmptyMovieClip`/`duplicateMovieClip`. Image-comparison rows found: only
  `avm1/netstream_play_flv_screen` (unchanged, in the sweep) and the new fixture. 20 trace rows were found; all are
  in the sweep and none moved.

## 2+3. Button pick: mechanism and fix

- **Owner:** `tag.c` `ng_update_button_states` → `ng_update_button_states_in_dl` (root) then
  `ng_update_button_states_attached` (`child_mc_cache` order). Hit-testing and the state machine ran in one pass:
  the first button to hit set `found_hover` and fired its transition at once. So:
  - (a) the root walk always beat the attached walk. Measured: timeline `T` won over attached `m` above it.
  - (b) attached clips won in creation order. Measured: `lo` (depth 3, attached first) beat `hi` (depth 5).
  - (c) the new rollOver fired before the old rollOut whenever the new button was visited first. That includes **root
    buttons**: the top-down walk visits depth 3 `Y` before depth 2 `X`. Measured: `Y rollOver` printed before
    `X rollOut`.
- Ruffle (`core/src/player.rs` `update_mouse_state`, ~1695-1717) pushes `RollOut{cur_over}` and then
  `RollOver{new_over}`, from one `mouse_pick`.
- **Fix:** `ng_update_button_states` now runs the same walks in three phases (`BTN_PHASE_*`, new statics next to
  `g_btn_hit_td`):
  1. **PICK.** No state change and no actions. Each walk unit (the root list, then each attached clip) offers its
     first hit: a DefineButton, or a button-mode sprite claim, exactly as the old gating decided. `btn_pick_offer`
     keeps the greatest render-order key. The key is the level prefix, then the AS depth of every enclosing clip (the
     root walk pushes the dl index − 16384 as it recurses, and attached units start from `btn_path_set_mc_chain`),
     then the entry's own depth. A descendant sorts above its ancestor.
  2. **LEAVE.** Every button except the winner is processed with `found_hover` forced, which is the old "something
     above was hit" path. All rollOut/dragOut/releaseOutside transitions fire here. A non-winning button-mode sprite
     no longer claims.
  3. **ENTER.** Only the winner is processed, with its real geometric hit test (this is safe if a LEAVE action moved
     or removed it). Its rollOver/press/release fires here.

  The function is re-entrant: it saves and restores the phase/path/winner state. `ng_update_button_states_in_level`
  (AVM1-under-AVM2) keeps the legacy single pass (`BTN_PHASE_LEGACY` = 0, the default).
- Cost: three walks per mouse event instead of one. They are hit tests over button entries only, so this was not
  measurable in the sweep.
- **Not changed:** AS-handler (`onRollOver` on MCs) dispatch through `actionDispatchMCMouseMove` / the AABB path. That
  path is separate and its order relative to DefineButton events is unchanged (lead 1).

## 4. Button-child EditText path binding

- Ruffle `edit_text.rs` `try_bind_text_field_variable` (~1412-1429) climbs past AVM1 buttons and then calls
  `resolve_variable_path(parent, path)`. Ours resolved the container with `actionGetVariable` in the **current**
  context. While a button's state function places its records, that context is the button clip
  (`ng_update_button_states_in_dl` sets `_btn_state_mc`), so `_parent.pv` bound one level too deep (`s.pv`).
- **Two sites, both fixed, both gated to "the field's parent is a button MC":**
  - `action.c` `actionTryBindTextFieldVariable`, path branch: the `actionGetVariable` runs with the context set to the
    climbed parent.
  - `tag_stubs.c` `ng_on_place_object2`, the legacy placement-time seeding (`actionInitTextFieldVariable`). It seeded
    the same path from the button context, so the first fix alone left `s.pv=P` behind. It now does the same climb.
- **Scope choice:** Ruffle resolves from the field's parent for *every* field, not only button children. I kept the
  change to the button case, which is the brief's scope and has the smallest blast radius. The non-button retry path
  (`actionUnboundTextFieldsPush` → re-bind in whatever context is current) can still resolve a relative path from the
  wrong clip (lead 2).
- Corpus: the only path variable inside a button record is `avm1/nested_textfields_in_buttons` (`_parent._parent.helloworld`).
  Its `output.txt` is empty and `num_ticks = 1`, so it checks only that the movie runs without crashing. It still passes.

## Evidence: per-test before/after (same box, clean `origin/master` vs this patch)

Headline rows:

| Test | Mode | Before | After |
|---|---|---|---|
| `regression/avm1_attached_clip_holder_render` | graphics | trace pass; **img fail 20000 outliers / max 255** (`h.m2` region white; `m`, `m3` exact) | trace pass; **img pass 0 / max 0** |
| `regression/avm1_attached_clip_holder_render` | no-graphics | pass | pass |
| `regression/avm1_button_pick_order` | graphics | output_mismatch 2/9 | **pass** 9/9 |
| `regression/avm1_button_pick_order` | no-graphics | output_mismatch 2/9 | **pass** 9/9 |
| `regression/avm1_button_textfield_path_binding` | graphics | output_mismatch 2/4 (`_root.pv=undefined`, `s.pv=P`) | **pass** 4/4 |
| `regression/avm1_button_textfield_path_binding` | no-graphics | output_mismatch 2/4 | **pass** 4/4 |
| `regression/avm1_attached_clip_button_click` | both | pass 13/13 | pass 13/13 |

`avm1_button_pick_order` before (both modes):
`_level0 T rollOver / _level0 T rollOut / _level0.lo L rollOver / _level0 X rollOver / _level0.lo L rollOut / _level0 Y rollOver / _level0 X rollOut / _level0 Y rollOut`.

**Sweep: 231 rows × 2 modes, before vs after, compared on (status, matching lines, full image stats).** Only the 3
headline rows moved (4 moves counting both modes; the holder row moved on pixels only). Everything else is identical
in both modes. The sweep had these parts:
- **Every `input.json` row with mouse input** in avm1, from_gnash, from_shumway, visual and regression (66):
  - avm1: `asfunction button_goto button_keypress button_properties_special_cases click_block clip_event_propagation_order drag_drop drag_over_from_outside drag_over_without_startdrag edittext_asfunction_case_insensitive edittext_drag_select edittext_onscroller edittext_place_caret focus_keyboard_press focus_mouse focus_mouse_focusable focus_mouse_rollout focusrect_mouse_swf8 focusrect_mouse_swf9 frame_size_translated_negative frame_size_translated_positive hitarea_lazy_getter hitarea_remove_owner_drag hitarea_remove_sibling hitarea_sweep hittest_morph_input key_isToggled mouse_events mouse_events_visible_enabled mouse_hover_events_while_dragging mouse_pos mouse_pos_with_scale_factor root_button_mode string_paths_eval tab_ordering_events_mouse text_blocks_clicks unload_nested_child`
  - from_gnash misc-ming.all: `ButtonEventsTest ButtonPropertiesTest DefineTextTest DragDropTest PrototypeEventListeners ResolveEventsTest RollOverOutTest key_event_test loading/loadMovieTest`
  - from_gnash misc-swfc.all: `button_test1`
  - from_shumway: `3_joystick ZeroClipboardTest avm1/hitarea avm1/mouse-transparency avm1/nested-button avm1/rollover button1 button2 button3 hittesting/mask-hit-test mouse/mouse_coords mouse/start_drag mouse/start_drag_lock slider_component`
  - visual: `cache_as_bitmap/edittext_scroll focus_highlight/focus_highlight_basic`
  - regression: `avm1_attached_clip_button_click`, `avm2_simplebutton_click`, plus the new `avm1_button_pick_order`
- **Text-variable binding:** avm1 `nested_textfields_in_buttons textfield_variable string_paths_variable_alias string_paths_variable_scopes`; from_gnash `DefineEditTextVariableNameTest` and `…Test2`; from_shumway `avm1/text-bind`; visual `text/String_path_variable_button`.
- **The attach + createEmptyMovieClip/duplicateMovieClip scan rows:**
  - avm1: `netstream_play_flv_screen empty_movieclip_can_attach_movies focus_remove focus_visibility_change globals_monkeypatch issue_3446 loadmovie_registerclass movieclip_invalid_get_bounds_6 movieclip_invalid_get_bounds_7 register_class register_class_swf6 string_paths_other attach_movie create_empty_movie_clip`
  - from_gnash: `MovieClip-v5..v8 DepthLimitsTest movieclip_destruction_test3 attachMovieTest attachMovieLoopingTest`
  - from_shumway: `avm1/duplicateMovieClip/duplicateMovieClip`
- **The whole `regression` suite**: 137 rows, which is the 134 existing rows plus my 3 fixtures. The fixtures were present in both legs.

Failing rows (unchanged before and after, in both modes): `avm1/globals_monkeypatch` output_mismatch (it is on the
baseline failing list), and from_gnash 11 of 20 failing. Those are the known `ruffle_matched`/failing gnash rows
(ButtonEventsTest etc.), and their matching-line counts are identical before and after.

**Render canary** (`render_canary.py capture` before/after over `render_canary_tests.txt`, `-P 3`): **132 tests /
158 comparisons IDENTICAL, 0 DIFFERS, 0 APPEARED/VANISHED, no trace or image status changes.** The 36 members in
avm2/fonts/text and the other categories I didn't download had `runner exit != 0` identically in both legs, because
their test dirs are not present here. My changes are in AVM1 attached-clip / DefineButton / EditText-binding code that
AVM2-only rows don't reach, but the canary did not cover those members. Covering member appended at EOF:
`regression/avm1_attached_clip_holder_render` (tier 1).

## Functions touched (for `n-pixel-pass`, `w2-loaded-shell-phase2`)

- `tag.c`:
  - **New statics:** `g_btn_phase`, `g_btn_path*`, `g_btn_pick_*`, `btn_path_push/pop`, `btn_pick_offer`,
    `btn_path_set_mc_chain`, `offscreen_attached_pass_member`, and a forward declaration of `compute_mc_world_xform`
    under OFFSCREEN.
  - **Edited:** `ng_update_button_states_in_dl` (sprite-claim arm, the two recursion sites, LEAVE/ENTER filters,
    `hit_now` + PICK early-out); `ng_update_button_states_attached` (per-unit PICK hover and path);
    `ng_update_button_states` (the three phases); `tagRerenderFrame` (attached pass filter + nested-clip world
    matrix); `tagShowFrame` (OFFSCREEN attached pass filter + comment).
  - **Not touched:** `render_attached_child`, `attached_sort_render_order`, `collect_attached_standalone`, and shell
    arms.
- `tag_stubs.c`: `ng_on_place_object2`, the text-field variable seeding block only. Sibling `w2-loaded-shell-phase2`
  edits `ng_findChildEntryDepth` in this file, a different function.
- `action.c`: `actionTryBindTextFieldVariable`, path branch only.

Browser-WASM was not compiled here (no emsdk). The pick/ordering change is shared code, so it applies to the browser
too, and N's menu is the browser check (LOCAL ORACLE REQUEST 3). Item 1's change is `OFFSCREEN_RENDER` only; the
browser already renders unaliased nested attaches through its own pass.

## Not finished / limitations (each with its completion mechanism)

- **The goldens for `avm1_button_pick_order` and `avm1_button_textfield_path_binding` are predicted from Ruffle source,
  not run.** Completion: LOCAL ORACLE REQUESTS 1–2. If Ruffle disagrees, fix `output.txt` and re-grade. The runtime
  change stands on Ruffle's source either way.
- Item 4 is gated to button parents. Generalising "resolve from the field's parent" to every field and to the retry
  queue is lead 2.
- Mouse-driven AS handlers (`onRollOver`/`onRollOut` on MCs, AABB dispatch) are not part of the unified pick. A
  DefineButton and a handler-MC hand-off can still order differently from Ruffle (lead 1).

## New unclaimed leads

1. **Unify the AS-handler MC dispatch (`actionDispatchMCMouseMove` / `actionDispatchMCPress`) with the DefineButton
   pick**, so that one `mouse_pick` decides both, as Ruffle's `InteractiveObject` pick does. Today a button-mode MC
   claim only blocks DefineButtons beneath it. M. The fixture pattern is `avm1_button_pick_order` plus an MC with
   `onRollOver`.
2. **EditText path-variable scope for non-button fields and the unbound retry queue** (`actionTryBindTextFieldVariable`
   path branch without the button gate, `actionUnboundTextFieldsPush` retry). Ruffle resolves from the field's parent.
   Ours uses the current context, which during a retry can be any clip. S–M. Needs a fixture where the retry fires from
   a different timeline.
3. **Clips attached under a loaded-movie shell holder** (`loaded_dl_shell`, no `display_obj`) are now drawn by the
   OFFSCREEN post-loop pass. No corpus row was seen. Worth a fixture once `w2-loaded-shell-phase2` lands.
4. **Drawing-API content of a holder paints over its attached children** (`actionIterateDrawings` runs after the
   attached passes). In Flash the holder's own drawing is under its children. This is pre-existing and not measured.
   S–M.

## LOCAL ORACLE REQUESTS

1. **`regression/avm1_button_pick_order` trace.** Copy the dir (with `input.json`) into Ruffle as
   `tests/tests/swfs/avm1/zz_s26_button_pick_order/` with `num_frames = 12` (11 input steps, consumed one per frame)
   and run Ruffle's test runner. Need: does it pass against the committed 9-line `output.txt`? Watch line 2
   (`_level0.m A rollOver`, the attached clip over timeline `T`), line 4 (`_level0.hi`, not `lo`) and lines 6–8 (the
   X→Y hand-off order).
2. **`regression/avm1_button_textfield_path_binding` trace.** No input is needed: `exporter -s -f 2 --trace-log out.txt
   test.swf out.png`. Expected: `_root.pv=P`, `s.pv=undefined`, `s.pv2=Q`, `_root.av=A`. Ruffle's runner at
   `num_frames = 2` works too.
3. **N browser + native click re-check** (the pick is now three-phase in shared code). Click "play game" → episode
   select must still open, and the H/S/Q/N menu hover/press must still fire in the browser.
