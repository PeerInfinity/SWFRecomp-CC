# wave1-gfx-button — AVM2 SimpleButton state-children never render

Session-10 wave-1 (READ-ONLY diagnosis). Baseline = `feb8882b0` (session-9
closeout, image run `30701749687`, `results_graphics.json` +
`image_results_graphics.json` both `incomplete: false`).
Local repro: native `--mode=graphics` (Dawn at `~/CC/dawn-install`), PNGs
exported with `--images --image-out-dir`. **No local pixel *grading* was done**
(lavapipe ≠ Dawn, playbook §6) — every claim below is either a colour-histogram
of my own render (structure, not tolerance) or the CI-recorded excess.

---

## 0. Mandatory pre-checks

| Doc | Hit for `avm2_button` / `SimpleButton` / `button_scroll_rect` |
|---|---|
| `avm1/_investigation/ACCEPTED_DIFFS.md` | none |
| `RUFFLE_VS_FLASH_DIFFERENCES.md` | none |
| `RUFFLE_COMPAT_TWEAKS.md` | none |
| `FLASH_BUGS_REPLICATED.md` | none |
| `ruffle-tests/ignored_tests.txt` | none |
| `known_failure` in the image JSONs | `false` on every row below |

Nothing in the target set is dispositioned.

---

## 1. (a) Full blocked-test enumeration

### 1a-i. How the set was derived (not by name)

Name matching is unreliable here (`from_shumway/button2` is *not* a
SimpleButton; `visual/definefont4` carries the string `SimpleButton` in an
unused constant pool). I scanned **every failing image comparison in every
`image_results_graphics.json`**, decompressed each `test.swf`, walked the tag
stream, and kept the rows that are AVM2 (`FileAttributes` AS3 bit **or**
`DoABC`) **and** contain `DefineButton2` (tag 34) **or** the literal
`SimpleButton`. That yields 10 comparisons / 7 tests; I then rendered each
locally and read the colour histogram to separate real blockage from
coincidence.

### 1a-ii. IMAGE axis — the verdict table

| # | suite / test | cmp | excess (CI) | local render | verdict |
|---|---|---|---|---|---|
| 1 | `visual/focus_highlight/focus_highlight_avm2_button_bounds` | `output` | 632 | 2416 black + 84 yellow; **0 magenta** | **BLOCKED — pure**. Missing = 316 px `#FF00FF` upState. 316 × 2 differing channels = **632, exact** |
| 2 | `visual/cache_as_bitmap/avm2_button` | `output` | 4692 | blue 7739 + white 7655; **0 green** | **BLOCKED — pure**. Missing = 2132 px `#00FF00`; 2132 × 2 = 4264, + 428 AA-edge channels |
| 3 | `from_shumway/button1` | `output.1` | 145920 | **220000/220000 px pure white** | **BLOCKED — pure**. Missing = 48640 px `#0066CC`; 48640 × 3 = **145920, exact** |
| 4 | `from_shumway/button1` | `output.2` | 97280 | pure white | **BLOCKED — needs state tracking too**. Missing = 48640 px `#99FF00` (OVER); 48640 × 2 = **97280, exact** |
| 5 | `from_shumway/button1` | `output.3` | 97280 | pure white | **BLOCKED — needs state tracking** (DOWN, `#FF0099`); exact |
| 6 | `from_shumway/button1` | `output.4` | 97280 | pure white | **BLOCKED — needs state tracking** (OVER again); exact |
| 7 | `visual/avm2_button_scroll_rect` | `output` | 28851 | **200×200 pure white** | **BLOCKED but double-blocked** — also needs scrollRect clip+offset (see §4) |
| 8 | `from_shumway/bitmapbuttons` | `output` | 618042 | 204740 white + 1752 near-white | **BLOCKED but double-blocked** — also needs bitmap-fill shapes in the AVM2 shape path |
| 9 | `visual/cache_as_bitmap/avm2_button_state` | `output` | 10353 | shape **is** drawn | **NOT this bug** — see below |
| 10 | `visual/definefont4` | `output` | 16086 | — | **NOT this bug** — no button in the SWF; trace also `output_mismatch` |

**Correction to session 9's guess:** `cache_as_bitmap/avm2_button_state` was
listed in the playbook as "likely shared". It is not. I mapped its pixels: the
parallelogram **is rendered**, but (a) displaced ~6 px horizontally and
(b) filled `(0,96,96)` where Flash has `(200,96,96)` — G and B match exactly,
only R is lost. That is the `content_displaced` + blend-mode slice, a different
owner. Drop it from this arc.

Adjacent-but-different: `from_shumway/button2` (`output.2/.3/.4`, 95634 each)
has **no** `DefineButton2` and no `SimpleButton` — it is Sprite-based with
MouseEvent listeners. Its `output.1` passes and 2–4 fail with the *up* colour
still on screen, i.e. the script-driven swap never happens. Separate rider.

**Net image-axis blocked set: 8 comparisons / 5 tests**, of which
**6 comparisons / 3 tests are cleanly winnable** (#1, #2, #3 with render only;
#4, #5, #6 with render + state tracking).

### 1a-iii. TRACE axis — the honest answer is ZERO

The brief anticipated trace-graded bounds assertions unblocking. They will not,
because **the bounds path is already fixed**: `bounds_with_transform`
(`avm2_display.c:754-766`) has had a SimpleButton arm since before session 9 —
it reads `ext->btn_up` explicitly *because* the state child is not in
`render_list`. Evidence:

* Every one of the 8 blocked comparisons is `trace_status: pass` at baseline.
* `avm2/button_bounds` — **pass**. `avm2/button_hittest` — **pass**.
* `visual/avm2_button_scroll_rect/output.txt` = `frame 1: (x=0, y=0, w=100,
  h=100)` ×2 — **trace passes** while the image is 100 % blank.
* The whole `simplebutton_*` family (17 tests) is pass except three, and none
  of those three is bounds-shaped: `button_nested_frame_simple`
  (`output_mismatch`), `simplebutton_childevents_multichild`
  (`output_mismatch`), `simplebutton_soundtransform` (`output_mismatch`),
  `simplebutton_childevents_script_order` (`ruffle_matched`).

**Predicted trace yield of this arc: 0.** Trace is a *risk* axis here, not a
yield axis. Say so in the wave-2 ledger so the fix is not mis-scored.

---

## 2. (b) The exact drop point

The state children are **constructed correctly and parented correctly**. They
are simply **not in `render_list`, and nothing else ever walks them.**

**Construction is fine** — `button_create_state()`
`SWFModernRuntime/src/avm2/avm2_display.c:10186-10275`. For a single-record
state it returns the child itself after
```c
cext->parent = button;
mark_attached(ctx, cext, button);      // :10245-10246
```
`mark_attached` (`:1368`) only flips `walk_clean` / orphan bookkeeping — it
**never inserts into a render list** (`render_list_insert` is only reached from
`replace_at_depth` / `add_child`, and `button_create_state` calls neither for
the single-record case; the multi-record case calls `replace_at_depth` into the
**wrapper's** list, not the button's). A SimpleButton is deliberately *not* a
container (`is_container` → `doc_class`, `:85-89`), so `ext->render_len` on a
button is **always 0**.

**The drop:**

> `SWFModernRuntime/src/avm2/avm2_display.c:14341` `avm2_render_node()` — its
> only descent is
> `:14370-14371  for (uint32_t i = 0; i < ext->render_len; i++)
>                    avm2_render_node(ctx, ext->render_list[i], &world, alpha);`
> There is **no SimpleButton arm**, so `btn_up` / `btn_over` / `btn_down` are
> never reached and nothing of the button is ever drawn.

Three sibling walks have the identical hole (all four must be fixed together or
CPU/GPU/BitmapData outputs diverge):

| walk | file:line | purpose |
|---|---|---|
| `avm2_render_node` | `avm2_display.c:14341`, loop `:14370` | **GPU / offscreen Dawn — the graded one** |
| `avm2_cpu_walk` | `avm2_display.c:13768`, loop `:13819` | CPU dump twin (`AVM2_CPU_DUMP`) |
| BitmapData.draw walk | `avm2_bitmap.c:2121` | `BitmapData.draw(container)` |
| `render_apply_text_bounds` | `avm2_display.c:2987`, loop `:2997` | lazy autosize flush for a TextField inside a state |

Contrast — walks that **already have** the button arm and therefore work today:
`bounds_with_transform` `:754-766`, `run_mouse_pick` `:11541-11551`,
`obj_highlight_bounds`/per-node px bounds `:12329-12370`,
`construct_frame_obj` `:2169`, `run_frame_scripts` `:2343-2369`,
`dispatch_added_to_stage_recursive` `:1065`. That asymmetry is the whole bug:
**everything except painting knows about `btn_*`.**

**Second, smaller defect — there is no current-state variable at all.**
`Avm2DisplayObjectExt` (`SWFModernRuntime/include/avm2/avm2_globals.h:573-580`)
has `btn_up/btn_over/btn_down/btn_hit`, `btn_states_created`, `btn_weird_order`
— and **no `btn_state`**. Every consumer hardcodes Up:
* `bounds_with_transform:760` — `Avm2Object* state = ext->btn_up;` with the
  comment *"Trace runs never leave the Up state."*
* `btn_state_set:10404` — `int is_cur_state = (off == offsetof(..., btn_up));`
* `update_mouse_state` (`:12052-12172`) dispatches `rollOver`/`rollOut`/
  `mouseDown`/`mouseUp`/`click`/`releaseOutside` and **never touches any button
  state**.

That is why `button1 output.2/.3/.4` need a second piece.

Repro command used:
```bash
DAWN_INSTALL=~/CC/dawn-install python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/from_shumway --test=button1 \
  --mode=graphics --images --image-out-dir=<dir>
# -> all 4 PNGs are 220000/220000 pure white
```

---

## 3. (c) Ruffle's model, in 5 lines

(`~/CC/ruffle/core/src/display_object/avm2_button.rs`)

1. `Avm2ButtonData` holds `up_state/over_state/down_state/hit_area` **plus**
   `state: Cell<ButtonState>` (`:54-75`, init `ButtonState::Up` at `:127`).
2. A SimpleButton is **not** a container and has **no render list**;
   `render_self` (`:569-576`) is literally
   `if let Some(state) = self.get_state_child(self.0.state.get().into())
    { state.pre_render(context); state.render(context); }` — the current state
   child only, **never** the hit area, **no** Up fallback when the state child
   is `None`.
3. `set_state` (`:279-288`) is the swap: `invalidate_cached_bitmap()`, store the
   new state, `set_parent(None)` on **all** state children, then
   `set_parent(Some(self))` on the new current one. It never moves anything into
   a render list.
4. State transitions come from `event_dispatch` (`:736-743`):
   `RollOver→Over`, `RollOut→Up`, `Press→Down`, `Release→Over`,
   `DragOut→Over`, `DragOver→Down`, `ReleaseOutside→Up`, `MouseUpInside→Up`;
   plus a forced `→Up` on removal from stage (`:388`) and after
   `construct_frame` (`:525`, `:533`).
5. `bounds_with_transform` / `render_bounds_with_transform` / `hit_test_shape`
   (`:609-660`) all read `get_state_child(state)` — i.e. bounds follow the
   *current* state, not Up; and `highlight_bounds` is the documented exception
   that uses the **hit area** (already implemented on our side — that is why the
   yellow ring in test #1 is already pixel-exact).

**Takeaway for wave 2: do NOT put state children into `render_list`.** Ruffle
does not, and our passing trace tests depend on it — `simplebutton_structure`,
`simplebutton_childshuffle`, `simplebutton_childprops`, `simplebutton_multi_
children` all assert `numChildren` / `getChildAt` / `parent` semantics through a
**non-container** button. Adding a walk arm is both the faithful port and the
low-risk one.

---

## 4. (d) Implementation-ready fix plan

### Fix A — render the current-state child (the whole of the yield)

*Effort: ~1.5 h. Runtime-only (`SWFModernRuntime/`), no recompiler change ⇒ no
cmake rebuild, no `--recompile` for downstream agents.*

1. **New helper**, next to `bounds_with_transform`'s existing arm
   (`avm2_display.c`, just above `:754`):
   ```c
   // Ruffle avm2_button.rs get_state_child(state): the child painted for the
   // button's CURRENT state. NULL when that state has no records — Ruffle does
   // not fall back to Up, and never paints the hit area.
   static Avm2Object* button_state_child(Avm2DisplayObjectExt* ext);
   ```
   Phase 1 body: `return ext->btn_up;` (matches today's bounds behaviour
   exactly, so Fix A alone is a strict superset of current semantics).
2. **Four call sites**, each immediately *before* the existing
   `for (… ext->render_len …)` loop (a button's loop is always empty, so
   ordering is academic — put it before, mirroring Ruffle's
   `render_self`-then-children):
   * `avm2_display.c:14370` (`avm2_render_node`) → `avm2_render_node(ctx, st,
     &world, alpha)`
   * `avm2_display.c:13819` (`avm2_cpu_walk`) → `avm2_cpu_walk(ctx, st, &world,
     alpha, fb, fbw, fbh)`
   * `avm2_bitmap.c:2121` (BitmapData.draw) → recurse with the same composed
     `wa..wty`/`alpha`
   * `avm2_display.c:2997` (`render_apply_text_bounds`) → recurse
3. **Guard**: only when `ext` actually has states (`ext->btn_states_created ||
   ext->btn_up != NULL`); cost on non-buttons is one NULL test.
4. Do **not** touch `render_list`, `is_container`, `numChildren`, or
   `set_on_parent_field`.

**Gotcha wave 2 must not trip on:** in
`focus_highlight_avm2_button_bounds/Test.as` the *same* `Shape` is assigned to
`upState`, `downState` **and** `overState`. `btn_state_set` (`:10393-10452`)
nulls `vext->parent` on each later assignment, so after the ctor the shape's
`parent` is **NULL** even though `btn_up` still points at it. **Key the render
off `ext->btn_*`, never off the child's `parent`.** Also note
`simplebutton_init` (`:10472-10495`) writes the four fields *raw*, bypassing
`btn_state_set` entirely — same conclusion.

### Fix B — track the current state (unlocks 3 more comparisons)

*Effort: ~2 h. Only take it if the wave-2 slot has room after Fix A is measured.*

1. Add `uint8_t btn_state;` (0=Up, 1=Over, 2=Down) to `Avm2DisplayObjectExt`
   next to `btn_weird_order` (`avm2_globals.h:578`).
2. `button_state_child()` switches on it; `NULL` if that state has no child
   (Ruffle semantics — no Up fallback).
3. `avm2_set_button_state(ctx, obj, s)` = Ruffle `set_state` (`:279-288`): store
   + reparent. Hook it in `update_mouse_state` (`avm2_display.c:12052-12172`) at
   the six existing dispatch points, using Ruffle's `:736-743` table. The picked
   target for a SimpleButton is the button itself (`run_mouse_pick`
   `:11541-11551`), so no ancestor walk is needed.
4. Force `→Up` on removed-from-stage (`:1076` region) and after
   `button_construct_states`.
5. Flip `bounds_with_transform:760` and `btn_state_set:10404`'s `is_cur_state`
   to consult `btn_state` — this is where the trace risk lives (§Risk).

### Explicitly OUT of scope

* `avm2_button_scroll_rect` (#7). Its script is
  `this.button.scrollRect = new Rectangle(10, 10, 100, 100)`
  (`RecompiledABC/abc0_methods.c:8-14`). The AVM2 render walk has **no clipping
  of any kind** — `has_scroll_rect` is read only by `bounds_with_transform:722`,
  and `renderer_begin_clip`/`end_clip` appear nowhere in `src/avm2/`. Fix A will
  make this test draw the button **unclipped and unoffset**; the excess will
  *change*, plausibly upward. It is already `fail`, so this is not a regression,
  but **call it out in the ledger as expected churn** (same courtesy session 9
  extended to test #1).
* `from_shumway/bitmapbuttons` (#8). DefineButton2 over
  DefineBitsJPEG/Lossless shapes; needs bitmap-fill shape rendering in the AVM2
  shape path as well. Fix A alone will not flip it.
* `cache_as_bitmap/avm2_button_state` (#9) and `visual/definefont4` (#10) —
  different owners, remove from this arc's board.
* `from_shumway/button2` — Sprite + MouseEvent, different owner.

### Predicted yield

| axis | Fix A only | Fix A + Fix B |
|---|---|---|
| image comparisons | **+3** (#1 `focus_highlight_avm2_button_bounds`, #2 `cache_as_bitmap/avm2_button`, #3 `button1 output.1`) | **+6** (adds `button1 output.2/.3/.4`) |
| trace tests | **0** | **0** |
| churn (still-fail, excess moves) | #7, #8 | #7, #8 |

Confidence, by the excess arithmetic (all measured against the CI-recorded
`excess_outliers`, not against a local grade):

* #1 — **high**. 316 missing magenta px × 2 channels = 632 = the exact recorded
  excess. Nothing else is wrong with that image.
* #3/#4/#5/#6 — **high**. 48640 px × 3 (or ×2) = 145920 / 97280, all four exact,
  and my render is *literally* 220000/220000 white — there is nothing else to
  get wrong.
* #2 — **medium-high**. 2132 green px × 2 = 4264 of the 4692 excess; the residual
  428 is AA edging on a `tolerance = 1, max_outliers = 0` comparison, so the
  flip depends on our AA matching Ruffle's on that shape.

### Risk to currently-passing work

* **Image axis: zero.** I ran the same AVM2+button scan over every
  **passing** image comparison in every suite: **no passing comparison contains
  an AVM2 button.** Nothing can regress on pixels.
* **AVM1 buttons: untouchable.** Entirely separate machinery —
  `libswf/tag.c` composes a persistent `obj->sprite_display_list` per button
  object (`compose_children`'s `CHAR_TYPE_BUTTON` branch `:5967-6010`, driven by
  `ch->button_state_funcs[obj->button_state]`) and paints it at `:3133` /
  `:3316`. Fix A/B touch no AVM1 file.
* **Focus tests: safe.** `obj_highlight_bounds`' SimpleButton branch already
  uses the **hit area** (Ruffle `highlight_bounds`), which Fix B does not touch;
  the ring in #1 is already pixel-exact today.
* **Fix A trace risk: narrow.** Two of the four sites are trace-visible —
  `BitmapData.draw` (a `draw()` of a container holding a button would newly
  include the button's pixels; correct per Ruffle, and no corpus test currently
  does it) and `render_apply_text_bounds` (a TextField inside a button state
  would newly get its lazy autosize flushed). Both are strictly *more* correct.
* **Fix B trace risk: real but bounded.** It changes `bounds_with_transform` and
  `is_cur_state` under hover. Only 4 AVM2 tests drive mouse input at a button:
  `avm2/mouse_pick_button_mode` (pass), `regression/avm2_simplebutton_click`
  (pass), `from_shumway/button1` (pass), `from_shumway/button2` (pass). All four
  must be in the canary.

### Canary list (wave 2 must run all of these)

*Render canary* — `ruffle-tests/render_canary.py capture/compare`, standing set
`render_canary_tests.txt`, **md5 equality only**, plus these adds:

| group | tests |
|---|---|
| the arc itself (expect DIFFERS) | `visual/focus_highlight/focus_highlight_avm2_button_bounds`, `visual/cache_as_bitmap/avm2_button`, `from_shumway/button1` (4 cmp), `visual/avm2_button_scroll_rect`, `from_shumway/bitmapbuttons` |
| must be md5-IDENTICAL | `visual/cache_as_bitmap/avm2_button_state`, `from_shumway/button2` (4 cmp), `from_shumway/button3` (4 cmp, AVM1 — proves no AVM1 spill), `visual/focus_highlight/focus_highlight_avm1_button` (6 cmp), `visual/focus_highlight/focus_highlight_move`, `visual/focus_highlight/focus_highlight_basic`, `avm2/focusrect` (12 cmp), `avm2/focus_root_movie`, `avm2/focus_stage`, `avm2/focusrect_focuslost` |

*Trace canary* (`--mode=graphics --diff`, byte-identical expected) — the 17
`avm2/simplebutton_*` + `avm2/button_*` tests, specifically:
`simplebutton_structure`, `simplebutton_childshuffle`, `simplebutton_childprops`,
`simplebutton_multi_children`, `simplebutton_childevents`,
`simplebutton_childevents_nested`, `simplebutton_childevents_sprite`,
`simplebutton_constr`, `simplebutton_constr_params`,
`simplebutton_constr_childevents`, `simplebutton_added_to_stage`,
`simplebutton_symbolclass`, `simplebutton_mouseenabled`, `button_bounds`,
`button_hittest`, `button_nested_frame`, `goto_button_nested_framescript`,
`mouse_pick_button_mode`, `timeline/swf_9_frame_script_button_order`
— **plus `regression/avm2_simplebutton_click`** (standing rule: every canary
includes the `regression` suite).

Baselines to compare against are in each suite's
`_results/results_graphics.json` @ `feb8882b0`; remember the
`ruffle_matched`-trap (`simplebutton_childevents_script_order` and
`timeline/frame_script_button_order` report `Pass: 0` locally at baseline — that
is a *match*, not a regression).

### CI

Runtime-only ⇒ `mode=graphics`, `categories=all`. **`images=true` is required to
observe any of this** — under the standing `images=false` default the entire
patch is invisible in CI.
