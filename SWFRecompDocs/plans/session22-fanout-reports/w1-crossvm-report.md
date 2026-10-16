# w1-crossvm — session 22 wave 1: cross-VM focus / pick / load-tick arcs

New files on this branch (docs only, sources reverted):

    SWFRecompDocs/plans/session22-fanout-reports/w1-crossvm-report.md
    SWFRecompDocs/plans/session22-fanout-reports/w1-crossvm-prototype.patch   (measured prototype, NOT for merge as-is)

Setup: `SETUP_STATUS` all OK (apt, Pillow, Dawn). Upstream Ruffle corpus at **`45366370e`** (same as the
coordinator's sync). Categories downloaded: `avm2 mixed_avm from_shumway`, plus the eight small misc
categories (only to scan for scrollRect pick observers). Every run below is `--mode=graphics --verbose`
unless it says NG (no-graphics). "LCS" = matched lines by `difflib` sequence match against `output.txt`.
LCS runs higher than the inventory's index-based count (for example, `mouse_pick_loader_avm1` is 28/42 LCS
against 16/42 indexed).

The prototype is **env-gated** (`PROTO_*` variables), so each mechanism could be A/B'd on one binary. The
one exception is the scrollRect clip, which is unconditional. When no variable is set, the build is
origin/master plus that clip.

## 0. Verdicts and flip prices

| row | baseline (graphics) | verdict | flip | mechanisms needed |
|---|---|---|---|---|
| `avm2/mouse_pick_scroll_rect_loader` (NEW upstream) | fail (4 lines) | **GO** | **+1 pass** | S-clip |
| `avm2/mouse_pick_scroll_rect` (NEW upstream, same commit) | fail (24 lines) | **GO** | **+1 pass** | S-clip |
| `avm2/mouse_pick_scroll_rect_button` (NEW upstream, same commit) | fail (2 lines) | **GO** | **+1 pass** | S-clip |
| `avm2/mouse_pick_loader_avm1` | 28/42 LCS | **GO**. The standing NO-GO is refuted, and the prototype **PASSES in both modes**. | **+1 pass** | M-pick + M-btn + M-text + M-clickfocus |
| `mixed_avm/avm2_loads_avm1_events` (KF) | 22/26 LCS, output_mismatch | **GO toward Ruffle**: the prototype is **ruffle_matched in both modes** | **+1 effective** (ruffle_matched) | T-order + T-init |
| `avm2/focus_events_mixed_avm_edittext` | 5/49 LCS | **HOLD**. The pick slice moves it 5 → 31/49, but it does not flip. | 0 | M-pick + M-text + M-clickfocus (in the GO set) + F-bcast + F-slot + F-tab |
| `avm2/selection_onsetfocus_mixed_avm` | 0/5 (emits nothing) | **NO-GO** (s21's 4 mechanisms stand; nothing here touches them) | 0 | F-tab + F-slot + F-bcast + F-scope |
| `from_shumway/as3-loader/events/loader-events` (KF) | 15/36 LCS | **NO-GO (policy)**. The Ruffle target needs a Ruffle-only event that Flash does not fire (§4). | 0 | — |
| `mixed_avm/avm1_loads_avm2` | 3/7 | **NO-GO of record, re-confirmed**. It is the AVM1-parent → AVM2-child build and host arc. | 0 | session-sized |

**Wave-2 GO total: +4 pass + 1 ruffle_matched = +5 effective.** Three of the four passes are new
upstream rows (`387ea68a4`). They are **upstream additions, not drift re-flips**, so the coordinator
should book them as corpus growth that we also pass.

### Measured regression A/B for the full prototype (all `PROTO_*` on)

Every AVM1-under-AVM2 fixture in the corpus was found by scanning for an AS3 `test.swf` that has a sibling
AVM1 `.swf`, plus `avm2/localconnection`:

| test | CI 4c450f076 | prototype |
|---|---|---|
| `mixed_avm/avm2_loads_avm1` | pass | pass |
| `mixed_avm/avm2_loads_avm1_doabc` | pass | pass |
| `mixed_avm/avm2_loads_avm1_v9` | pass | pass (NG too) |
| `mixed_avm/avm2_loads_avm1_v10` | pass | pass |
| `mixed_avm/avm2_loads_avm1_loads_into_root` | pass | pass |
| `mixed_avm/avm2_loads_avm1_loads_avm2_doabc` | pass | pass |
| `avm2/mouse_pick_avm1_root` | pass | pass |
| `avm2/avm1movie_addcallback_call` | pass | pass |
| `avm2/localconnection` | pass | pass |
| `from_shumway/avm1movie` | ruffle_matched | ruffle_matched |
| `avm2/avm1_root` | output_mismatch | output_mismatch, **actual byte-identical** to base |
| `avm2/stage3d_raytrace`, `avm2/stage3d_texture` (contain the string `scrollRect` and use input) | pass | pass |
| `regression/avm2_simplebutton_click` (the regression suite's only `input.json` row) | pass | pass |

**Mode parity (NG):** `mouse_pick_loader_avm1` pass; `avm2_loads_avm1_events` ruffle_matched; the 3
`mouse_pick_scroll_rect*` rows pass; `avm2_loads_avm1_v9` pass.

**KF question (rule 3):** the `avm2_loads_avm1_events` move is output_mismatch → ruffle_matched. In this
sweep, no `pass` row moved. Note `avm2/loader_events_2` (KF, ruffle_matched in CI): the order changes are
gated on "an AVM1 child exists", so they do not touch that row or any other pure-AVM2 loader row. A fix toward
**`output.txt`** on either KF row is a different matter, see §4.

---

## 1. S-clip: scrollRect clips AVM2 mouse picking (upstream `387ea68a4`). GO, +3

Ruffle added `DisplayObject::global_in_scroll_rect` and calls it at the top of the `mouse_pick_avm2` paths
that walk children (`MovieClip`, `LoaderDisplay`, `Avm2Button`). If an object has a committed scrollRect and
the stage point maps outside it (through `global_to_local`, which includes the object's own scroll
translate), the result is `Miss`. A singular matrix is treated as outside, and `Rectangle::contains` is
inclusive on all four edges.

**Owner:** `avm2_display.c:14884 mouse_pick`. The check goes in two places:

- after the mask/maskee rejects and before the child walk (`:14947`, `Pk found_prop`), skipping the Stage;
- at the top of the SimpleButton arm.

EditText is not gated, which matches Ruffle. The prototype helper `pk_in_scroll_rect` uses the existing
`display_l2g_matrix` (`:4083`, already Ruffle's `local_to_global_matrix` with the own-scroll translate)
and the committed rect (`sr_committed`/`csr_*`). It is about 20 lines.

**Evidence:** all 3 new rows go fail → **pass** in graphics and in NG. The button row's partial pass at base
(2 of 5 lines already right) is a coincidence of the button's own hit bounds.

**Blast radius:** only a committed scrollRect changes the walk. A corpus scan found every `input.json` test
whose SWFs contain `scrollRect`. The scan covered avm2, mixed_avm, from_shumway, regression and the 8 misc
categories; avm1 and gnash are not affected, because this is AVM2-only. The scan found only the 3 new rows
plus the 2 stage3d rows, and both of those still pass. Drag-drop (`g_drag_drop_target = run_mouse_pick`)
goes through the same walk, but no corpus drop test uses scrollRect.

**Wave-2 scope:** `avm2_display.c` only, about 20 lines. This is the cheapest GO on the board and is
independent of everything else here.

## 2. `mouse_pick_loader_avm1`: claim (a) REFUTED; the real pick defect is on the AVM1 side. GO, +1

### 2.1 Claim (a) "the AVM1Movie wrapper answers clicks with its whole stage rect" is REFUTED as the cause

I removed the `point_in_self(wrapper)` OR at `avm2_display.c:14991` (env `PROTO_NO_WRAP`). The actual output
was **byte-identical**: same 14 diff lines. Instrumenting `actionAvm1ChildMousePick`
(`action.c:25597`) showed the real cause. At (290,90) and (350,125), where Flash answers `rect_mc` and
`Stage`, the AVM1 walk itself returns `CONTENT`. It does so because `_level1` (the child's level root) and
`instance1` (a timeline sprite whose shape is an L/ring) are both in `child_mc_cache`, and
`actionMCMouseInsidePick` (`action.c:76955`) is a **pixel AABB** test. The wrapper OR is redundant here,
because the AVM1 walk claims every point first. Dropping the OR alone flips nothing, as s21 said, but for a
different reason than s21 gave.

### 2.2 The four mechanisms and their line ownership (LCS out of 42)

| step | env | LCS | lines owned | owner |
|---|---|---|---|---|
| base | — | 28/42 | — | |
| **M-pick**: exact shape test for level roots and timeline sprites | `PROTO_PICK` | 34/42 | **6** (`rect_mc`/`Stage` ×3 blocks) | `action.c:25597` |
| **M-btn**: DefineButton2 under AVM2, both pick and dispatch, gated on the AVM2 pick | `+PROTO_BTN +PROTO_GATE` | 38/42 | **4** (`avm1 button clicked` ×4) | `action.c:25597`, `:25661`; `tag.c:5333` |
| **M-text**: an AVM1 input/selectable TextField is an AVM1 pick target | `+PROTO_TEXT` | 38/42 (2 wrong lines removed) | **2** | `action.c:25597` |
| **M-clickfocus**: AVM1 click-focus under AVM2, gated on the AVM2 pick | `+PROTO_FOCUS` | **42/42 PASS** | **4** (`input_txt.onSetFocus/onKillFocus` ×2) | `action.c:25661`, `:78513` |

All four are required. Leave out any one and the row stays failing. The mechanisms in detail:

- **M-pick.** For a clip that is a booted child's level root, or that owns a timeline `sprite_display_list`
  (and is not a text field), do not use the AABB. Instead, run the existing exact walk
  `ng_hitTestShapeFromDL` (`tag_stubs.c:2009`, the same walk AVM1 `hitTest(x,y,true)` uses) over the level
  root's display list, under that entry's `transform_data_ptr`. Drawing-API and attached clips keep the AABB
  path.
- **M-btn.** **Claim (b) is mis-stated.** The child's button is a **timeline `DefineButton2` with
  `on(release)`**, not a clip with an `onRelease` property. Under AVM2, nothing runs
  `ng_update_button_states` (`tag.c:5333`) on the child's display list, and `actionAvm1ChildMousePick`
  only knows about clips with `BUTTON_EVENT_METHODS`. The prototype:
  - **pick:** a pure geometric probe (`ng_proto_button_hit_at`, a copy of the hit arm of
    `ng_update_button_states_in_dl`) makes the pick return `BUTTON`, and the AVM2 side then dispatches
    nothing;
  - **dispatch:** `actionMouseAvm1ChildrenUnderAvm2` swaps the child's display list in, as
    `avm1UnderAvm2RunFrame` already does, and runs the state machine.

  The **gate** matters. Without it, the button fired in the `mouseChildren=false` blocks too (4 extra
  lines). Flash fires the AVM1 button only when the AVM2 pick resolves to the AVM1 object, so the prototype
  records `PICK_IS_AVM1(new_over)` in `update_mouse_state` (`avm2_display.c:15459`). When the pick is not
  AVM1, it feeds the button machine an off-stage point.
- **M-text.** Ruffle's `edit_text.rs::mouse_pick_avm1` returns the field itself, so the AVM2 side sees an
  AVM1 target and traces no `click`.
- **M-clickfocus.** Under AVM2, `actionMouseClickFocus` (`action.c:78513`) was never called. Calling it from
  the forwarded mouse-down was not enough on its own, for two reasons:
  1. Its "frontmost hit" scan of `child_mc_cache` (`:78521`) hits `_level1`'s AABB before `input_txt`. The
     prototype skips non-click-focusable clips in that scan. **Wave 2 must scope this to the AVM1-under-AVM2
     path.** It is env-gated in the prototype; pure AVM1 was not exercised with it.
  2. It needs the same AVM2-pick gate, so a click that AVM2 owns kills the AVM1 focus (`onKillFocus`) and
     never sets it.

Flip price: **+1** (`mouse_pick_loader_avm1`), and only with all four mechanisms.

## 3. `focus_events_mixed_avm_edittext` and `selection_onsetfocus_mixed_avm`: HOLD and NO-GO

The §2 prototype moves `focus_events` **5 → 31/49 LCS** (pick alone: 17; plus text: 19; plus click-focus:
31), and it does not move `selection_onsetfocus` (0/5). That row is Tab-only: four Tabs, then one empty
click. What is left in `focus_events` is s21's leg F plus one ordering rule:

- **F-bcast** (about 7 lines): `Selection.onSetFocus: undefined undefined` on every **AVM2-only** focus
  change. The AVM1 `Selection` broadcaster must hear AVM2 focus changes, with AVM2 objects mapped to null.
  Owner: `action.c` `selection_do_focus_change` is AVM1-only; the hook site is AVM2 `set_focus`.
- **F-slot** (about 6 lines): the AVM2 `mouseFocusChange` is dispatched **from the current focus**. When the
  focus holds an AVM1 object, no AVM2 `mouseFocusChange` fires. Clicking `buttonMc` after `input1_txt`
  gives Flash `onKillFocus` → `focusIn buttonMc`, with no `mouseFocusChange` before it. Moving from AVM2 to
  an AVM1 target gives `mouseFocusChange: null`, then the AVM1 events, then `focusOut`. We dispatch
  `mouseFocusChange: [object MovieClip]` and run the AVM1 kill after `focusIn`. This needs `g_stage_focus`
  to be able to hold "an AVM1 object". It is s21's (b).
- **F-tab** (about 9 lines): the tail after `KeyDown Tab`. AVM2 tab order has to descend into the AVM1Movie
  (`fill_tab_order`), and `keyFocusChange: null` has to fire for AVM1 targets.
- **F-scope** (only `selection_onsetfocus`): s21's `notify_system_listeners` root-scope quirk. It was not
  re-tested here; s21's oracle evidence stands.

**Completion mechanism:** `focus_events` = the §2 set + F-bcast + F-slot + F-tab; `selection_onsetfocus` =
F-tab + F-slot + F-bcast + F-scope. Both flip together, as one leg-F slot, after the §2 slot lands. The
price is +2, and the size is session-sized.

## 4. Load-tick rows (claim (d))

### 4.1 `avm2_loads_avm1_events` (KF): GO toward Ruffle, +1 ruffle_matched

The s20/s21 "rotation" diagnosis is right in outline, but the **mechanism is a tick-order fact s20 did not
name**. Ruffle's `player.rs::run_frame` runs:

1. `run_all_phases_avm2(context)`, which ends in `LoadManager::run_exit_frame`, i.e. loader init/complete;
2. then `Avm1::run_frame`;
3. then `LocalConnections::update_connections`;
4. then post-frame callbacks and the executor.

An AVM1 clip's `INITIALIZED` flag is set only in `run_frame_avm1`. `try_fire_loaderinfo_events` gates on
that flag (`movie_clip.rs:441`). So an AVM1 child's init/complete lands at the exit frame **after** its
first AVM1 frame.

We run the AVM1 tick at the **top** of `avm2_display_run_tick` (`avm2_display.c:3752`) and fire
init/complete one flush after boot. The prototype makes two changes:

- **T-order** (`PROTO_TICK2`): when an AVM1 child exists (latched per tick), the order becomes exit-frame
  loader flush → `avm1_child_tick` → LC delivery → fetch resolution. `avm2_loader_drain` (`:6565`) skips
  its own flush in this case.
- **T-init** (`PROTO_AVM1INIT`): `defer_flushes = 1` on the AVM1-child arm of `loader_deliver`
  (`:6442`).

**Neither change works alone, and the obvious version is wrong:**

- `PROTO_TICK` (the AVM1 tick moved to just after the `enterFrame` broadcast) fixes half of the row.
- T-init with the old LC position **regresses `avm2_loads_avm1_v9` and `_v10`** (pass → fail, last line
  missing). Their `complete` handler `send()`s over LocalConnection with `num_frames = 3`. The delivery then
  slips a tick, because our LC delivery runs **before** the drain, while Ruffle's runs **after** the exit
  frame. Proof: with `num_frames = 6`, v9 passes under T-init.
- T-order + T-init together: `avm2_loads_avm1_events` is **ruffle_matched**, and v9/v10 pass.

Gating T-order on `g_avm1_child_levels != 0` keeps the pure-AVM2 order, so `amf_array_serialization` and
every `loader_*` row are untouched. It also means LC delivery moves after the init flush only in mixed
movies. Ruffle's order is the same for every movie, so the gate is only a risk limiter. Widening it to all
movies is a separate, unmeasured lead.

**Toward `output.txt` (Flash):** Flash fires the first load's `open…complete` **after** `frame 1`. In the
sibling `avm2/loader_events_2` (KF), Flash spreads `open/progress` and `init/complete` across two
ticks. This is Flash's network-latency model. Ruffle does not emulate it, and every passing Loader row in
the corpus is insensitive to it. A Flash-ward fix would have to re-time every Loader row, so it risks
`pass → *` broadly. It also cannot produce Flash's line 14 (`child` traced by the **already-unloaded**
first child). **NO-GO.** The ceiling is ruffle_matched, which is what the prototype reaches.

### 4.2 `loader-events` (KF): NO-GO, because a Ruffle match means implementing a Ruffle-only event

`diff(ours, output.ruffle.txt)` matches s20 §4.2's three defects, and each one is confirmed in Ruffle
source:

- **(i) Root `httpStatus`.** Ruffle's `fire_init_and_complete_events` (`loaderinfo_object.rs:193`)
  dispatches `httpStatus` for any non-`from_bytes` Swf stream, **including the root movie's LoaderInfo**.
  We fire it only for `LI_KIND_LOADER && from_fetch` (`avm2_display.c:5420`). **But Flash's `output.txt`
  has no root `httpStatus`. At that slot Flash prints `root loader: progress 1293`.** So (i) is a
  **Ruffle-only behaviour that contradicts Flash.** Under the user's "Flash over Ruffle" ruling it should
  not be implemented to win a ruffle_matched. Corpus check: no other test listens for `httpStatus` on a
  root LoaderInfo (all 7 `HTTP_STATUS` listeners are on `contentLoaderInfo`). Implementing it therefore
  would not cost a pass. It would still knowingly encode a Ruffle divergence. **That is the user's call; I
  price it as NO-GO.**
- **(ii) Counter.** Ruffle's `post_instantiation` calls `set_default_instance_name` on the loaded root
  (`movie_clip.rs:2749`). Ours stays `null` (`loader_boot_child_swf`, `:6061`, never calls it). This costs
  5 lines vs Ruffle. **Flash's names differ again** (`instance4`/`instance2`, against Ruffle's
  `instance3`/`instance5`), so even (ii) is not Flash-exact.
- **(iii) Rotation.** The URL-loaded root's frame-1 script runs inline (`:6061` catch-up; the
  `construct_frame_obj` + `run_frame_scripts_obj` block). Ruffle runs it in the next tick's frame-script
  phase. The inline catch-up is pinned by `loader_loadbytes_events` (**from_bytes**), so a wave-2 split has
  to be by `from_bytes`. Unmeasured.

**Completion mechanism:** ruffle_matched needs (i)+(ii)+(iii), and (i) needs a user ruling. Toward Flash, it
needs the Flash network-latency model (child 2 completes **before** child 1 in Flash). That is session-sized.

### 4.3 `avm1_loads_avm2`: NO-GO of record, re-confirmed

The parent is AVM1 (DoAction only) and the child is AVM2 (DoABC). Lines 4–7 come from the AVM2 child. This
is the AVM1-parent → AVM2-child direction: link the AVM2 runtime into an AVM1 parent's build
(`verify_output.py` `is_avm2` gate, loader-arc §"The one thing CI caught") **and** host an AVM2 stage under
an AVM1 root. Nothing in this report touches it.

## 5. Refutations

1. **(a) "the wrapper's stage rect answers clicks" (`avm2_display.c:14961-14975` of record, now `:14991`)
   is REFUTED as the cause.** Removing it leaves the output byte-identical. The cause is the AVM1-side
   **AABB** pick of `_level1` and timeline sprites (`action.c:25597` → `actionMCMouseInsidePick`
   `:76955`).
2. **(b) "AVM1 button `onRelease` under AVM2 is missing" is mis-stated.** The fixture's button is a
   timeline `DefineButton2` with `on(release)`. The missing piece is the whole DefineButton state machine
   (and its pick) for the AVM1 child under AVM2, gated on the AVM2 pick.
3. **(c) The RVF flags are misapplied: CONFIRMED.** `RUFFLE_VS_FLASH_DIFFERENCES.md:523-524` only names both
   rows inside the `avm2/avm1_root` entry. Neither row has `known_failure` or an `output.ruffle.txt`, and
   neither is in an `ignored_tests.txt`. Drop the RVF flag from the inventory.
4. **(d) Load-tick: right in outline, wrong in mechanism.** It is not a "boot → next-drain rotation". It is
   Ruffle's `run_all_phases_avm2` → `Avm1::run_frame` → LC order, plus the `INITIALIZED` gate (§4.1). The
   naive +1-flush version regresses v9/v10.
5. **`loader-events`' "missing `httpStatus`" is a Ruffle-only event.** Flash prints `progress` there (§4.2).
6. **s21's "`mouse_pick_loader_avm1`: 3 mechanisms" is under-counted.** It takes 4 (pick, button, text
   target, click-focus) plus 2 pick-gates. It is still one slot.

## 6. Wave-2 slots I would fund

1. **`w2-scrollrect-pick` (S, `avm2_display.c` only), +3:** `avm2/mouse_pick_scroll_rect`,
   `avm2/mouse_pick_scroll_rect_loader`, `avm2/mouse_pick_scroll_rect_button`. Port `pk_in_scroll_rect` from
   the patch as is. Canary: the 2 stage3d rows and `regression/avm2_simplebutton_click`. This slot is
   independent of the others and could even ride with slot 2.
2. **`w2-crossvm-pick` (M, `action.c` AVM2 block + `tag.c` + 1 line in `avm2_display.c`), +1:**
   `avm2/mouse_pick_loader_avm1`. It also moves `focus_events_mixed_avm_edittext` 5 → 31/49 (diff-line
   only). Implement M-pick, M-btn, M-text and M-clickfocus without the env gates. Specific work:
   - Replace the `getenv` + `g_proto_app` shortcuts with a real `app_context` parameter.
   - Put the pick→AVM1 latch in a header-free seam, like the existing ones.
   - Scope the `actionMouseClickFocus` skip to `g_avm1_under_avm2_ready` callers. Factor a
     `mouse_click_focus_at(app, x, y)` and do not touch the AVM1-only scan.
   - Make the button probe recurse into sprites. The prototype checks only the top level, which is enough
     for the fixture.
   - Check `transform_data` vs `ng_entryTransformData` for child placement ids. The prototype used
     `app_context->transform_data`, as `ng_update_button_states_in_dl` does. It worked here; a child with
     transformed buttons may not.

   Required A/B: the 11-row table in §0, and any AVM1 pure-input button/focus rows near
   `actionMouseClickFocus` (`avm1/edittext_focus*`, `avm1/button_*`) in both modes.
3. **`w2-crossvm-loadtick` (S, `avm2_display.c` only), +1 ruffle_matched:**
   `mixed_avm/avm2_loads_avm1_events`. Implement T-order + T-init together, never T-init alone. Re-run the
   §0 table; v9/v10 are the tripwires. Optional stretch: measure T-order **ungated** (Ruffle's order is the
   same for every movie) on the `loader_*`/LC rows before widening it.
4. **Not funded:** leg F (`focus_events` + `selection_onsetfocus`, +2, session-sized; fund it **after**
   slot 2, since it builds on the AVM1 pick target and the gate). `loader-events` needs a user ruling on (i).
   `avm1_loads_avm2` is the build arc.

Slots 1 and 3 both edit `avm2_display.c`, in disjoint regions (`mouse_pick`, against `avm2_display_run_tick`
and the drain). Slot 2 adds one line in `update_mouse_state`. A single worker could take 1+3, or 1+2+3 (all
of it is in the prototype), for **+5 effective**.

## 7. New unclaimed leads

- **AVM1 click-focus scan by AABB, frontmost-by-cache-index** (`action.c:78521`). Under AVM2 it is broken by
  the level root. In pure AVM1, any big non-focusable clip created after a text field (higher cache index)
  would steal the click-focus scan from the field beneath it. That is latent and has no corpus observer
  found. Ruffle uses the real pick.
- **`actionMCMouseInsidePick` is AABB everywhere** (`action.c:76955`). It is also used for button-mode
  hover in pure AVM1 (`ng_roll_pick_candidate`). Ruffle's `mouse_pick_avm1` uses the shape test. A
  non-rectangular button-mode clip in pure AVM1 would mis-hover.
- **LC delivery position for pure AVM2.** Ruffle runs `update_connections` after the exit-frame loader
  events. We run it before them. It is gated out of the prototype, and its effect on pure-AVM2 rows is
  unmeasured.
- **Root LoaderInfo `progress` event (Flash).** Flash's `loader-events` shows the root LoaderInfo firing
  `progress 1293` between init and complete. Neither we nor Ruffle fire it. It would be a Flash-ward line,
  if any non-KF row ever grades it.

## LOCAL ORACLE REQUESTS

- Optional, for slot 3's confidence: run the Ruffle exporter on `mixed_avm/avm2_loads_avm1_v9` with
  `num_frames = 3` and a trace of `frame N` added. The goal is to confirm that Ruffle's `complete` lands in
  the same tick as the T-order model predicts. The fixture already passes under the prototype, so this is
  not blocking.
- Otherwise none. `selection_onsetfocus`'s scope-quirk oracle is s21's and is still valid.
