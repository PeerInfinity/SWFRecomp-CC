# s26 w1-attached-button-dispatch: attached-clip button dispatch + the button-bound EditText row

Wave 1 (diagnosis, with a measured prototype). Cloud worker, base `origin/master` `ec07cc9e`. Setup: Dawn and apt
both OK (`SETUP_STATUS`). Tests were downloaded from upstream Ruffle master at session time (blobless clone HEAD
`3e98d9ba6`, the same hour). Categories: avm1, visual, from_gnash, from_shumway, timeline, text, swf,
import_assets, audio, fonts, mixed_avm.

**New files (all under `session26-fanout-reports/`):**
- `w1-attached-button-dispatch-report.md` (this file)
- `w1-attached-button-dispatch-prototype.patch`: `git diff --binary origin/master` over `SWFModernRuntime/` plus the
  new fixture `ruffle-tests/tests/swfs/regression/avm1_attached_clip_button_click/` (`create_test_swf.py`,
  `test.swf`, `input.json`, `output.txt`, `test.toml`) and one README row. It applies cleanly to `ec07cc9e`
  (`git apply --check`).

## Verdicts

| Item | Verdict | Corpus flips | Price |
|---|---|---|---|
| (a) attached-clip button dispatch in the CI modes | **GO** (behaviour fix and a new fixture) | **0.** No corpus row exercises it (refutation 1). Gains 1 new regression row. | S–M. The prototype is done; it needs a local N/browser check before landing (LOCAL ORACLE REQUESTS) |
| (b) `visual/text/String_path_variable_button` | **GO: 1 pixel flip** (999 → **3** outliers, limit 12; fidelity-proven) | +1 pixel | **S** (a 4-line change in `actionTryBindTextFieldVariable`) |
| `Color.getRGB/getTransform` undefined | **Not CI-visible.** Browser only, and narrower than the arc says | 0 | S (browser `getRGB` arm). Unmeasured here |
| browser `getBounds` → 6710886 | **Not CI-visible.** The whole computation is CI-modes-only | 0 | M (lift a ~380-line `#if`). Needs a browser check |

Both prototypes are in the one patch. Graded locally (graphics + no-graphics): no status change on any row listed in §Evidence
(§Evidence).

## (a) Attached-clip button dispatch

### Mechanism (owners)

- `tag.c` `ng_update_button_states`: walks only the root `display_list`. Its call to
  `ng_update_button_states_attached` (the child_mc_cache walk, written for N's menu) was compiled only under
  `!NO_GRAPHICS && !OFFSCREEN_RENDER`, i.e. browser only. The function body itself was compiled in OFFSCREEN too, but
  never called.
- `ng_attachMovie` (`tag_stubs.c` ~490) gives every attached clip a standalone heap `display_obj`
  (`attach_standalone`) that sits in no display-list array, so the root walk never reaches it. One exception: in the
  CI modes, a clip attached under a **timeline-placed or nested** parent also gets an alias entry
  (`attach_registration=1`) at `swf_depth` in the parent's `sprite_display_list` (`tag_stubs.c` ~751). That entry
  copies the child-list pointers.

### What the CI modes did before (measured on the fixture, both modes identical)

| clip | how it is attached | before (master) | prototype |
|---|---|---|---|
| `m` | `_root.attachMovie` | no events at all | rollOver/press/release/rollOut |
| `h.m2` | `h.attachMovie`, where `h = createEmptyMovieClip` | no events at all | all four |
| `c.m3` | `c.attachMovie`, `c` timeline-placed at 50% x scale, `m3._x = 100` | no events at the clip's real position. The root walk reaches it through the alias with transform slot 0 (identity), so it **hit-tests as if `m3._x` were 0** (stage x 50..100 instead of 100..150) | all four, at the right position |

Before the patch the whole fixture output was `attached`, and nothing else, in both modes.

### The prototype (functions touched; the local N session should note these)

`tag.c`:
1. **`ng_update_button_states`**: calls `ng_update_button_states_attached` in **all** modes (guard removed). The
   forward declaration is unguarded too.
2. **`ng_update_button_states_attached`**: moved out of the `#ifndef NO_GRAPHICS` block and compiled in all modes. It
   now takes the clip's world matrix from a new static helper, **`btn_attached_world_xform`**. In the graphics builds
   (browser + OFFSCREEN) that helper is the same `compute_mc_world_xform` × `apply_as_transform` composition as
   before, byte for byte. In NO_GRAPHICS there is no compose pass, so it calls the new action.c helper below.
   `g_btn_attached_walk = 1` (the "skip state-graphics repopulation" flag) is now set **only in browser-WASM**.
3. **`ng_update_button_states_in_dl`**, two hunks:
   - The sprite arm skips `attach_registration` alias entries (`if (obj->attach_registration) continue;`). The attached
     walk owns those clips, under their real transform. Without this skip, `c.m3` was walked twice per event with two
     different transforms, and its state flip-flopped (measured: rollOver/rollOut chatter, press lost).
   - Removed the `if (g_btn_attached_walk) _btn_action_ctx = &root_movieclip;` override. Button actions now run in the
     clip that holds the button, as in Flash and Ruffle (actions are queued on the button's parent), so `this` is
     `_level0.m`, not `_level0`. That override was the first workaround for N's menu. Its real cause was browser
     root-frame-1 functions storing `base_clip = NULL`, which `n-play-game` fixed at the source (`swf.c swfStart`,
     `8615da904`, `n-play-game-report.md` §4). With the override still in place, the fixture traced `_level0 press`
     for every clip (measured).
   - Comment refresh at the `g_btn_attached_walk` declaration.

`action.c`:
4. **New `actionMCStageMatrix16`** (next to `tf_world_matrix`): a 4×4 wrapper over `tf_world_matrix`, which is the
   MovieClip-property chain that `mc_get_local_mouse` and hitTest use. It is used only by the NO_GRAPHICS attached walk.

### Why the repopulation skip is now browser-only (measured)

Probe: the fixture SWF with distinct UP (red), OVER (green) and DOWN (blue) records, pixels sampled from OFFSCREEN
captures:

| tick | skip ON in CI (as the browser does) | skip OFF (prototype) |
|---|---|---|
| hover `m` | m red | m **green** |
| press `m` | m red | m **blue** |
| hover `m3` | m3 red | m3 **green** |
| press `m3` | m3 red | m3 **blue** |

The skip worked around browser `render_attached_child`'s compose pass only. OFFSCREEN repopulates correctly. Keeping
the skip in CI would also have taken state graphics away from the `c.m3` class, which master's alias path *did*
repopulate.

### Fixture `regression/avm1_attached_clip_button_click`

A hand-assembled SWF8 (generator in the patch), driven by `input.json` mouse injection. `verify_output.py` supports
`input.json` for the regression suite; `avm2_simplebutton_click` already uses it. Three attached copies of exported
sprite `menu` (one DefineButton2 whose four condition actions trace `this + " <event>"`), covering the three attach
classes above, each hovered, pressed, released and left. Before: `attached` only (both modes). After: 13/13 lines,
**PASS in both modes**. The expected output is hand-derived from Flash semantics. **Oracle pending** (LOCAL ORACLE
REQUESTS).

### Brief premises attacked

1. **"CI-visible": refuted for the corpus.** I scanned every AVM1-capable corpus SWF (all suites except avm2 and
   from_avmplus) for a DefineButton reachable from an exported symbol plus `attachMovie`/`duplicateMovieClip`.
   That found exactly 5 rows: `avm1/register_class`, `globals_monkeypatch`, `focus_remove`, `focus_visibility_change`
   and `from_gnash/misc-ming.all/attachMovieTest`. **None of them has an `input.json`**, and none of the 114
   `input.json` rows has a button inside an attached clip. The change is CI-*observable* only through new fixtures.
   Expected flips: **0**. I measured that the 5 rows keep their status in both modes (`globals_monkeypatch` diff is
   byte-identical before/after).
2. **"Never dispatch inside attachMovie'd clips": partly wrong.** Clips attached under a timeline parent were
   dispatched through the alias, at the wrong position. That is also why the alias skip has to land together with the
   port.
3. **"Port so native and browser share one path": done**, with two deliberate per-mode arms (world-matrix source in
   NO_GRAPHICS, and the repopulation skip in browser only). The browser behaviour change is the removal of the
   root-context override. It is browser-visible, and N must be re-checked locally.
4. The "NEXT-frame semantics / TAG-order attach tick" memory note concerns the attached-clip *timeline pump*. Hit
   dispatch runs per mouse event over `child_mc_cache`, so the note does not apply here.

### Known limitations (not fixed; no corpus row reaches them)

- **Overlap priority.** The root walk runs before the attached walk and claims `found_hover` first. An attached
  button that sits *above* a timeline button at the same point loses to it. Flash picks the attached one. Attached
  clips are also walked in `child_mc_cache` creation order, not depth order. Fix: one depth-interleaved pick
  (M–L). Browser-shared.
- **rollOut/rollOver order.** Transitions fire per button as each is visited. Moving from one button to another
  fires the new rollOver before the old rollOut whenever the new one is visited first. Ruffle fires the old rollOut
  first. The fixture's two hand-offs pass only because `m` precedes `m2`, and `m2` precedes `m3`, in visit order. I saw
  the inverse order in an intermediate run, when `m3` was still reached by the root walk. This probably applies to
  root buttons too (unverified).

## (b) `visual/text/String_path_variable_button`: GO, 1 pixel flip

- **Fidelity:** my before render is md5 **`d22fcf99…`**, byte-identical to `origin/ruffle-image-results`
  `images/visual/text/String_path_variable_button/output.actual.png`. Local grading on this row is CI-grade.
- **Probe** (the SWF plus one appended trace frame): `_level0.instance1` resolves, `_level0.instance1.Text1` =
  `Working` and `_name` = `instance1`. So s25's open question ("does `_level0.instance1` resolve at all") is answered
  yes. The write lands. The field just isn't bound to that clip.
- **Mechanism:** `action.c` `actionTryBindTextFieldVariable`, simple-name branch, binds on `tf_mc->parent`. For an
  EditText inside a DefineButton2 record (button 5 → EditText 4, var `Text1`), that parent is the **button** MC. Ruffle
  (`core/src/display_object/edit_text.rs` `try_bind_text_field_variable`, ~1412-1420) climbs past every AVM1-button
  parent: `while parent.as_avm1_button().is_some() { parent = parent.avm1_parent() }`.
- **Fix (in the patch):** the same climb, `while (simple_binding_mc->is_button_mc && simple_binding_mc->parent)`.
  Result: **PASS, 3 outliers (limit 12), max diff 153**; the render reads "Working". The s25 completion mechanism
  ("instantiate button-record EditTexts as text objects") was over-priced: they are already instantiated, only the
  bind scope was wrong. That is S, not M.
- **Blast radius:** I scanned the corpus for EditTexts inside button records. Only `nested_textfields_in_buttons` has
  a variable, `_parent._parent.helloworld`. That is a *path* variable, which takes the other branch and still passes
  in both modes. The `timeline/*` rows with button-record EditTexts have no variable. Also checked:
  `textfield_variable` and `string_paths_variable_{alias,scopes}` pass.
- **Not done (lead):** Ruffle resolves *path* variables relative to the same climbed parent. Ours resolves them with
  `actionGetVariable` in the current context. No corpus row depends on the difference today.

## The other two browser/native gaps

- **`Color.getRGB/getTransform` undefined: not CI-visible, and narrower than the arc says.** `colorGetTransform` and
  `colorGetRGB` (`action.c` ~12050 / ~12212) have real `#if NO_GRAPHICS || OFFSCREEN_RENDER` arms, so both CI modes
  are fine. `getTransform` now also has a browser arm (via `colorGetTargetMC`, entry cx, or the `cx_*` mirror). Only
  **browser `getRGB`** still hard-returns `undefined` (its `#else` arm). Fix: mirror getTransform's browser arm
  (`rb/gb/bb` from the same sources). S, browser-verify only. `avm1_attached_clip_color` is the browser check
  (`n-tile-color-hud-report.md` §104).
- **Browser `getBounds(_root)` → 6710886: not CI-visible.** In `action.c`'s getBounds/getRect method arm (~77276),
  the whole computation sits under `#if NO_GRAPHICS || OFFSCREEN_RENDER` (~77355-77737). The browser always falls to
  the empty-clip sentinel (134217728/20 = 6710886.4), so every browser `getBounds` returns it, not only N's.
  Fix: compile the block in the browser too. The browser has no `attach_registration` aliases, so check the arm's
  child-walk for attached children. M, browser-verify.

## Evidence (local, prototype applied; status vs s26 baseline `9277f3799` / `dffc41cf2`)

Graphics, all unchanged: avm1 `focus_visibility_change`, `focus_remove`, `register_class`,
`globals_monkeypatch` (output_mismatch, diff byte-identical before/after), `button_goto`, `mouse_events`,
`mouse_events_visible_enabled` (img 0/0), `root_button_mode`, `clip_event_propagation_order`, `string_paths_eval`,
`focus_mouse`, `unload_nested_child`, `button_properties_special_cases`, `click_block`,
`nested_textfields_in_buttons`, `textfield_variable`, `string_paths_variable_alias`, `string_paths_variable_scopes`;
from_gnash `attachMovieTest`, `button_test1`, `ButtonEventsTest`/`ButtonPropertiesTest`/`KeyEventOrder`
(ruffle_matched, unchanged); from_shumway `button1` (img 0), `button3` (img 3480/3500, = baseline), `nested-button`,
`mouse-transparency`; regression `avm1_attach_clipevent_enterframe`, all 11 `avm1_attached_clip_*`
(`_color` and `_hidden_capture` img 0), `avm1_closure_base_clip_root_frame`, `avm2_child_simplebutton`,
`avm2_simplebutton_click`.
No-graphics, all unchanged: the 5 attached-button rows, `button_goto`, `mouse_events`, `root_button_mode`,
`clip_event_propagation_order`, `nested-button`, `nested_textfields_in_buttons` and the regression attach family.
New: `avm1_attached_clip_button_click` PASS in both modes (before: 1/13 lines in both).
Not compiled in the cloud: the browser-WASM build (no emsdk). The browser-only hunks are the `g_btn_attached_walk`
guard and the removed override.

**Landing:** graphics `categories=all` is enough for CI; add a no-graphics leg, because `tag.c`'s NO_GRAPHICS arm
changes (`btn_attached_world_xform`). Expect 0 trace flips, +1 regression row and +1 pixel
(`String_path_variable_button`). A Pages deploy is needed only once the browser override removal is confirmed on N.

## New unclaimed leads

1. **OFFSCREEN doesn't render a clip attached under a `createEmptyMovieClip` holder** (`h.m2` in the fixture SWF):
   white where Ruffle should draw the red square. Reproduced on **clean master** (F0001 pixel at stage (250,100) is
   white, while `m`/`m3` are red). Its hit-testing and dispatch are right with the prototype. Probe SWF: fixture
   generator (render-only; no input needed). Probably `render_attached_child` and the attached depth pass skip a
   parent with no `sprite_display_list`. Pixel axis; no corpus row known.
2. Depth-interleaved button pick across the root walk and the attached walk (overlap priority, above).
3. rollOut-before-rollOver ordering across buttons (above). Check whether root buttons show it too.
4. Path-variable binding scope for button-child EditTexts (Ruffle resolves relative to the climbed parent).

## LOCAL ORACLE REQUESTS

1. **Fixture golden.** `regression/avm1_attached_clip_button_click` (apply the patch). The exporter can't click, so
   copy the dir into a Ruffle checkout as `tests/tests/swfs/avm1/attached_clip_button_click/` (with `input.json`,
   `test.toml` `num_frames = 1`) and run `cargo test -p tests -- attached_clip_button_click` (or the Ruffle desktop
   player by hand, hovering/clicking each red square). Need: the trace. Expected 13 lines as in `output.txt`. Watch
   two lines in particular: line 2 (`this` = `_level0.m`) and the rollOut/rollOver order at the hand-offs.
2. **N browser + native click re-check** (because the root-context override is removed). Apply the patch, then:
   (i) native `run_native.py n_click.swf native_run --frames 120 --input input_click.json`. With the patch, `on(release)` on
   "play game" should now fire natively, so the README's "native does nothing" note should flip. (ii) Browser:
   `n_click_probe.py` / a manual click on "play game" → select episode must still open (the base_clip fix should
   carry it).
3. Optional: an exporter render of the fixture SWF at frame 1, to confirm lead 1 (Ruffle draws `h.m2` red at
   (200..300, 50..150)): `exporter -s -f 1 test.swf out.png`.
