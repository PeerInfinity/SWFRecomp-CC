# w2-crossvm — session 22 wave 2: cross-VM pick / button / click-focus / load-tick (slots 1+2+3)

New files on this branch:

    SWFRecompDocs/plans/session22-fanout-reports/w2-crossvm-report.md
    SWFRecompDocs/plans/session22-fanout-reports/w2-crossvm.patch

No new source files and no new fixture dirs. Modified: `SWFModernRuntime/src/actionmodern/action.c`,
`SWFModernRuntime/src/avm2/avm2_display.c`, `SWFModernRuntime/src/libswf/tag.c`,
`ruffle-tests/render_canary_tests.txt` (3 members appended at EOF). There are no `SWFRecomp/` (recompiler)
changes, so `--recompile` is not needed.

The patch is `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py
ruffle-tests/render_canary_tests.txt`, 544 lines, base `10bdc4597`. It was regenerated after the final edit.
`git apply --check -R` passes on this branch, and a forward `git apply --check` passes on a clean
`origin/master` worktree.

Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Upstream Ruffle corpus at **`45366370e`**
(`git ls-remote` master = `45366370ed7d`, the same as the coordinator's sync). Categories downloaded: `avm2 mixed_avm
from_shumway avm1`, plus `visual text fonts` (for the canary only). `regression` is in git.

## 0. Verdicts and the EXPECTED-FLIP LEDGER

**GO, all three slots landed. +4 pass, +1 ruffle_matched = +5 effective, the same in both modes.**

| test | CI axis | before (origin/master) | after (this patch) | note |
|---|---|---|---|---|
| `avm2/mouse_pick_scroll_rect` | trace | output_mismatch | **pass** (27/27) | slot 1, new upstream row (`387ea68a4`) |
| `avm2/mouse_pick_scroll_rect_loader` | trace | output_mismatch | **pass** (5/5) | slot 1, new upstream row |
| `avm2/mouse_pick_scroll_rect_button` | trace | output_mismatch | **pass** (5/5) | slot 1, new upstream row |
| `avm2/mouse_pick_loader_avm1` | trace | output_mismatch (28/42 LCS) | **pass** (42/42) | slot 2 |
| `mixed_avm/avm2_loads_avm1_events` (KF) | trace | output_mismatch | **ruffle_matched** | slot 3. It does not move toward Flash's latency model (per the brief) |
| `avm2/focus_events_mixed_avm_edittext` | trace | output_mismatch 5/49 LCS | output_mismatch **31/49** | diff lines only, NOT a flip (leg F remains) |
| `from_shumway/avm1movie` (KF) | trace | ruffle_matched | ruffle_matched (status unchanged) | **actual text changes**, see §4.2 |
| every other row in the 145-row sweep | trace | — | **byte-identical actual** | both modes |
| pixel axis | image | — | **no expected movement** | 114 canary PNGs md5-identical (§3) |

Book the three `mouse_pick_scroll_rect*` rows as **corpus growth that we also pass**, not as drift re-flips (as the
w1 report noted). Pixel ledger: **none**. No changed path draws in any image-bearing row (§3).

## 1. Patch scope (owner `file:function`)

### Slot 1: S-clip (`avm2_display.c`)
- New `pk_in_scroll_rect` (Ruffle `DisplayObject::global_in_scroll_rect`). It applies only to a committed scrollRect and
  maps the point through `display_l2g_matrix`, which includes the object's own scroll translate. A singular
  matrix counts as outside, and the rect test is inclusive on all four edges.
- `mouse_pick` calls it at the top of the SimpleButton arm, and again after the mask/maskee rejects but before
  the child walk (skipping the Stage). EditText is not gated, which matches Ruffle. The code is the prototype's, verbatim.

### Slot 2: M-pick + M-btn + M-text + M-clickfocus (`action.c` AVM2 block, `tag.c`, `avm2_display.c`)
Every item on the w1 §6 slot-2 work list:
- **No `getenv`/`PROTO_*`/`g_proto_app`.** `actionAvm1ChildMousePick` now takes a real `SWFAppContext*`, and the
  AVM2 caller passes `ctx->app`.
- **Header-free pick→AVM1 latch.** `update_mouse_state` records `g_last_pick_avm1 = PICK_IS_AVM1(new_over)`
  (a file static in `avm2_display.c`). `avm1_child_mouse` passes it as a new 5th argument of
  `actionMouseAvm1ChildrenUnderAvm2`. Both sides declare the extern themselves, as the existing seams do. Every
  forwarded event runs `update_mouse_state` first, so the latch always belongs to the same event.
- **M-pick** (`actionAvm1ChildMousePick`). A level root, or a cached clip that owns a `sprite_display_list`
  (`avm1UnderAvm2IsTimelineClip`), no longer reports CONTENT from its AABB. The old level-root AABB fallback is
  replaced by the exact `ng_hitTestShapeFromDL` walk over each level root's list, under
  `getConcatMatrixForMC(root)`. That is the matrix AVM1 `hitTest(x, y, true)` uses (the prototype used a bare
  translate), and the fixture result is the same. Button-mode cached clips still answer by AABB, as before.
- **M-text.** A cached text field for which `mc_is_focusable_by_click` holds (SWF NoSelect bit clear, or
  dynamic `selectable != false`) returns `AVM1_CHILD_PICK_BUTTON`. This is Ruffle `edit_text.rs::mouse_pick_avm1`
  (`is_selectable()`). The prototype returned BUTTON for every text field; a non-selectable field now gives
  CONTENT, as in Ruffle.
- **M-btn pick.** New `tag.c` `ng_button_hit_in_dl` / `ng_button_hit_walk` is a pure geometric probe that **recurses
  into sprites** (a work-list item). Placements read `ng_entryTransformData(obj)` (a work-list item). Clip layers
  are skipped.
- **M-btn dispatch.** New `avm1UnderAvm2RunButtons` runs after every forwarded move/down/up. It swaps in each
  level's display list **and `g_active_transform_data`** (the same swap `avm1UnderAvm2RunFrame` does), so a
  button state change places its state children with the child's placement ids. The prototype also swapped
  it. The new `tag.c` wrapper `ng_update_button_states_in_level` runs the existing state machine with the level
  root as `parent_mc`. The prototype ran `ng_update_button_states`, which uses `root_movieclip`, but a button's
  timeline is the level. When the AVM2 pick is not AVM1, the machine sees an off-stage point (the gate).
- **`transform_data` vs `ng_entryTransformData` (work-list item), RESOLVED with a latent defect found.**
  Measured on `mouse_pick_loader_avm1`: the multi-SWF render tables are active, `ng_entryTransformData(obj) ==
  app_context->transform_data` (the combined table), and the placement id was re-based (`tid = 11`). But the
  **button hit-record transform id is NOT re-based** (`tagDefineButton` stores the defining movie's own id: 7,
  child base = 3). Both `ng_update_button_states_in_dl` and the prototype probe therefore read combined row 7 =
  **child row 4** instead of child row 7. Both rows are identity in this fixture, which is the only reason the
  prototype passed. Fix, scoped to AVM1-under-AVM2:
  - `ng_update_button_states_in_level` sets a file-static `g_btn_hit_td` = the child entry's own
    `transform_data_ptr`;
  - `ng_update_button_states_in_dl` indexes the hit record through it when it is set. It is NULL otherwise,
    which leaves the pure-AVM1 behaviour byte-identical;
  - the probe takes the same table as a parameter.
  The same latent defect exists for pure-AVM1 `loadMovie` children; see §6 leads.
- **M-clickfocus.** `actionMouseClickFocus` body factored into `static mouse_click_focus_at(app, mx, my,
  click_focusable_only)`. `actionMouseClickFocus` calls it with flag 0, so the pure-AVM1 scan is unchanged:
  same AABB, same frontmost-by-cache-index rule, same fallback. The AVM1-under-AVM2 mouse-down calls it with flag 1
  (skip non-click-focusable clips, so the level root's AABB stops shadowing `input_txt`). It passes the real
  point when the AVM2 pick is AVM1, and an off-stage point otherwise, so an AVM2-owned click only kills a
  mouse-focused AVM1 field. The call is placed between `actionDispatchMCMouseDown` and `actionDispatchMCPress`
  (swf_core.c's order).

### Slot 3: T-order + T-init TOGETHER (`avm2_display.c`)
- `avm2_display_run_tick` latches `mixed_avm1 = g_avm1_child_levels != 0` at the top of the tick. The tick
  order changes only when this is set. The AVM1 tick moves from the top to Ruffle `player.rs::run_frame`'s slot:
  exit-frame loader flush (`avm2_loader_run_exit_frame`), then `avm1_child_tick`, then LC delivery, then fetch
  resolution. The fetch loop was factored out of `avm2_loader_drain` as `avm2_loader_resolve_fetches`, and
  `avm2_loader_drain` is now exactly `run_exit_frame` + `resolve_fetches`, so the pure-AVM2 path is the same code
  in the same order.
- `loader_deliver`'s AVM1-child arm sets `lx->defer_flushes = 1` (Ruffle's `INITIALIZED` gate in
  `try_fire_loaderinfo_events`).
- T-init was never built alone (the brief's order). The tripwires `avm2_loads_avm1_v9` / `_v10` **pass** in both
  modes.

## 2. Per-test before/after (same box, clean `origin/master` worktree vs this branch)

A 145-row argued sweep was run on both trees, in **both modes**. It covers every `avm2/loader_*`, `mouse_pick_*`,
`localconnection*`, `*_mixed_avm*` row, all of `mixed_avm`, the w1 §0 table, `from_shumway` avm1movie/avm1timeline*/loader-events,
the regression suite's input and LC/loader rows, **every `avm1` test with an `input.json` (67)**, plus
`avm1/edittext_focus_selection`, `button_children/order/v5/v6`. "LCS" means matched lines vs `output.txt`.

**Result: in both graphics and NG, 138/145 rows have byte-identical actual output. The 7 that move are the 7 in
the §0 ledger. The NG A/B is row-for-row the same as graphics.** All 72 `avm1` rows are byte-identical in both
modes (71 pass, 1 ruffle_matched = `edittext_onscroller`, unchanged).

The w1 §0 11-row table, plus the tripwires (graphics; NG identical in status and in actual):

| test | before | after |
|---|---|---|
| `avm2/mouse_pick_scroll_rect` | output_mismatch | **pass** |
| `avm2/mouse_pick_scroll_rect_loader` | output_mismatch | **pass** |
| `avm2/mouse_pick_scroll_rect_button` | output_mismatch | **pass** |
| `avm2/mouse_pick_loader_avm1` | output_mismatch 28/42 | **pass** 42/42 |
| `mixed_avm/avm2_loads_avm1_events` (KF) | output_mismatch | **ruffle_matched** |
| `avm2/focus_events_mixed_avm_edittext` | output_mismatch 5/49 | output_mismatch 31/49 |
| `avm2/selection_onsetfocus_mixed_avm` | output_mismatch 0/5 | identical |
| `from_shumway/as3-loader/events/loader-events` (KF) | output_mismatch 15/36 | identical |
| `mixed_avm/avm1_loads_avm2` | output_mismatch 3/7 | identical |
| `mixed_avm/avm2_loads_avm1_v9` / `_v10` | pass / pass | pass / pass (identical) |
| `mixed_avm/avm2_loads_avm1`, `_doabc`, `_loads_into_root`, `_loads_avm2_doabc` | pass | identical |
| `avm2/mouse_pick_avm1_root`, `avm2/avm1movie_addcallback_call` | pass | identical |
| `avm2/localconnection`, `avm2/localconnection_send` | pass | identical |
| `avm2/avm1_root` | output_mismatch 14/58 | identical |
| `avm2/stage3d_raytrace`, `avm2/stage3d_texture` | pass | identical |
| `from_shumway/avm1movie` (KF) | ruffle_matched | ruffle_matched, **text differs** (§4.2) |

The rest of the AVM2 sweep, all byte-identical:
- `loader_*`, 27 rows: 23 pass, `loader_events_2` ruffle_matched (KF), and `loader_applicationDomain` /
  `loader_load` output_mismatch, unchanged;
- `mouse_pick_*` (masking, dobj_mask, bitmap masks, text, button_mode): pass;
- `focus_events_mouse_basic`, `focus_events_mixed_key_mouse`: pass;
- `netconnection_send_remote` and `netconnection_serialize_arrays`: unchanged;
- `from_shumway/avm1timeline1`/`2`: pass.

**Regression suite** (all pass before and after, actual identical, both modes): `avm2_simplebutton_click`
(the suite's only `input.json` row), `avm2_child_simplebutton`, `avm2_loader_stub`,
`avm2_localconnection_domain`, `avm1_mcl_load_tick`, `avm1_parent_as3_child_payload`,
`lc_method_type1_args`, `lc_onstatus_type1_args`.

Per-step A/B (graphics, headline rows, after each step as the brief asks):
- step 1: the 3 scrollRect rows pass;
- step 2: + `mouse_pick_loader_avm1` pass, `focus_events` 31/49, `mouse_pick_avm1_root` still pass;
- step 3: + `avm2_loads_avm1_events` ruffle_matched, v9/v10/LC pass, every other `mixed_avm` row unchanged.

The full sweep above is on the final patch.

## 3. Graphics canary

`render_canary.py capture` was run on both trees over the standing `render_canary_tests.txt` (61 tests, mode graphics,
lavapipe), plus an explicit leg for the rows nearest the change: `avm2/mouse_pick_dobj_mask`,
`avm1/focusrect_mouse_swf8`, `avm1/mouse_events_visible_enabled`, `avm2/loader_events`,
`avm2/loader_loadbytes_events`, `fonts/device_font_kerning`.

- Standing set: **IDENTICAL 101 / DIFFERS 0**. The one "APPEARED" row is `fonts/device_font_kerning`: the
  `fonts` category was not downloaded when the BEFORE leg ran. That is a harness artifact, not a change. It is
  md5-identical in the explicit leg.
- Explicit leg: **IDENTICAL 13 / DIFFERS 0**. No trace or image status changed.
- CI fidelity was not checked (no golden-PNG row is in my ledger). Only the A/B verdict is claimed.

**The canary cannot see most of this change class**: no `mixed_avm` test carries `[image_comparisons]`, so the
cross-VM pick, the AVM1-under-AVM2 DefineButton state machine and the mixed tick order have no image-bearing row
anywhere in the corpus. To cover the parts that do render, I **appended 3 tier-1 members at EOF**:
- `avm2/mouse_pick_dobj_mask` (AVM2 `mouse_pick` walk);
- `avm1/focusrect_mouse_swf8` (pure-AVM1 click focus via the factored `mouse_click_focus_at`);
- `avm2/loader_events` (the split loader drain).
All three pass their images locally and are absent from `wave0-image-board.md`.

## 4. Mechanism notes, refutations and risks

### 4.1 The prototype's `transform_data` question: half-refuted
The w1 report expected placement ids to be the risk. They are not: `ng_cache_transform` re-bases every placement
id onto the combined table, so `app_context->transform_data` and `ng_entryTransformData` agree whenever render
tables are active. The real defect is the **hit-record** id, which nothing re-bases (§1).

### 4.2 `from_shumway/avm1movie` (KF): a status-neutral text move, toward Ruffle
`num_ticks = 2`. Under T-init, the AVM1 child's `init`/`complete` now land after its first AVM1 frame, which is
beyond tick 2. Our output shrinks from 13 lines to 4, against Ruffle's `output.ruffle.txt` (which also has 4 lines
and no `init`/`complete`). The only difference left vs Ruffle is `_level1` against Ruffle's `_level-61440`, which
was already there before. Status stays ruffle_matched, and `ours_diff_count` = `ruffle_diff_count` = 12 in both
legs. Against Flash's `output.txt`, LCS drops 6 → 3, because Flash fires `init` before the AVM1 frame (its latency
model, w1 §4.1). Rule 3 accounting: this is **not** a pass→ruffle_matched move and costs no status, but it is a
diff-line move away from Flash on a KF row. It comes from the same T-init the brief funds. The coordinator should
expect it in CI.

### 4.3 Risk register
- `g_last_pick_avm1` and the mixed tick order are both behind `g_avm1_child_levels != 0`, so a pure-AVM2 movie
  runs the identical code path. A pure-AVM1 build compiles out the whole `#ifdef SWF_AVM2` block. The only shared
  code touched is:
  - `actionMouseClickFocus` → `mouse_click_focus_at(…, 0)`, a pure refactor; all 72 avm1 rows are identical in
    both modes;
  - `ng_update_button_states_in_dl`'s hit-record read, which is unchanged while `g_btn_hit_td == NULL`.
- No `swf_core.c` / `tag_stubs.c` / `#ifdef NO_GRAPHICS` arm was touched. The NG sweep was run anyway (identical).
- Drag-drop (`g_drag_drop_target = run_mouse_pick`) now honours the scrollRect clip too, as in Ruffle. No corpus
  drop test uses scrollRect (w1 scan).

## 5. Not done / out of scope (with completion mechanism)

- **Leg F** (`focus_events_mixed_avm_edittext` 31→49, `selection_onsetfocus_mixed_avm`), out of scope per the
  brief. Leads I confirmed while landing slot 2:
  - **F-slot.** `g_last_pick_avm1` is now the natural hook for "AVM2 focus holds an AVM1 object". The AVM2
    `update_focus_on_press` already special-cases `PICK_IS_AVM1`. Leg F needs that sentinel to be **storable**
    in `g_stage_focus`, so that `mouseFocusChange` is dispatched from the current focus (not at all when it is
    AVM1) and `focusOut` follows the AVM1 `onKillFocus`.
  - **F-bcast.** The AVM1 `Selection` broadcaster (`selection_do_focus_change`, `action.c`) is reachable from
    `mouse_click_focus_at`'s AVM1-under-AVM2 call, but nothing calls it for AVM2-only focus changes. The hook
    site is AVM2 `set_focus`, mapping AVM2 objects to null.
  - **F-tab.** `fill_tab_order` must descend into the AVM1Movie. Nothing in this patch touches Tab.
  - Completion: one leg-F slot (s21 (b) + w1 §3), priced +2. It builds on this patch's latch and the
    `mouse_click_focus_at(…, 1)` entry.
- **Ungated T-order** (Ruffle's order is the same for every movie): not measured. Gating keeps every
  pure-AVM2 `loader_*`/LC/netconnection row identical. Completion: build with `mixed_avm1 = 1` and A/B the
  27 `loader_*` + LC + `netconnection_*` + `amf_array_serialization` rows.
- **Root-LoaderInfo `httpStatus`**: deliberately NOT implemented (Ruffle-only; contradicts Flash), per the brief.

## 6. New unclaimed leads

- **Pure-AVM1 `loadMovie` children with a transformed button hit record.** `ng_update_button_states_in_dl`
  indexes `button_hit_transform_id` in the combined table without the defining movie's base, so a child-defined
  DefineButton whose hit record has a non-identity matrix hit-tests with the wrong row. Latent: there is no corpus
  observer, and the fix is a per-character "defining movie" record or a re-base in `tagDefineButton`. The
  under-AVM2 path is fixed here via `g_btn_hit_td`.
- The w1 leads still stand, untouched by this patch:
  - pure-AVM1 click-focus scan by AABB, frontmost-by-cache-index (`mouse_click_focus_at` flag 0);
  - `actionMCMouseInsidePick` is AABB for button-mode hover;
  - LC delivery position for pure AVM2;
  - the root LoaderInfo `progress` event (Flash).
- The AVM1-under-AVM2 DefineButton state machine now runs. Its **render** under AVM2 (do the over/down state
  children draw through the AVM1Movie?) has no image-bearing observer. A fixture would need an oracle (below).

## LOCAL ORACLE REQUESTS

- Optional, for confidence in the hit-record fix: the Ruffle exporter on a new fixture in which an AS3 parent
  Loader-loads an AVM1 child whose timeline DefineButton has a **scaled/translated hit record** (e.g. a hit shape
  placed at (+100, 0) inside the button). Click inside the transformed hit area and outside the untransformed one;
  `on(release)` traces. It needs AS3 + AS2 authoring, which the cloud box cannot do (no Flex/Animate). Not
  blocking: no corpus row grades it.
- Otherwise none. The w1 v9 tick-order request was not needed: v9/v10 pass under the final T-order + T-init.
