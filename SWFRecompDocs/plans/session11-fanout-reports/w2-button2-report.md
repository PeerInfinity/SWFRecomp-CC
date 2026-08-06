# w2-button2 — MovieClip `buttonMode` + `_up`/`_over`/`_down` frame labels

Session 11, wave 2. Worktree `agent-a133b50d42dbaee30`, baseline `b4c983ea4`.
Spec: `wave1-gfx-clipping.md` §3 (the `button2` section only; `scrollRect` and
`bitmapbuttons` were DEFERRED and are untouched).

**Result: the wave-1 prediction landed exactly. +3 image comparisons, all
byte-exact, zero regressions across 25 render-canary tests (50 PNGs) and 24
trace canaries.**

---

## 1. What was implemented

Ruffle's `MovieClip::event_dispatch` frame-label mechanism
(`~/CC/ruffle/core/src/display_object/movie_clip.rs:2903-2925`): a MovieClip
with `buttonMode = true` that carries `_up`/`_over`/`_down` frame labels
navigates to the matching frame (with `stop = true`) on every mouse state
change. We implemented this nowhere; `grep '_over'` over
`SWFModernRuntime/src/avm2/` returned zero hits at baseline.

Two hunks, both in `SWFModernRuntime/src/avm2/avm2_display.c`, 46 lines net:

1. **`label_to_frame_cstr()`** (new, next to `button_clip_state` at `:10545`) —
   the `const char*` twin of `label_to_frame` (`:6930`). The label table's
   `Avm2FrameLabelData.label` is a NUL-terminated `const char*`, so this is a
   plain `strcmp` loop; 0-based in, 1-based out, `-1` when absent.
2. **`button_clip_state_ex(ctx, obj, st, mc_states)`** — `button_clip_state`'s
   body moved into it. SimpleButton keeps the old `button_set_state` path and
   returns. Otherwise, when `mc_states` is set, a `movieclip_class` instance
   with `ext->button_mode` looks up `_up`/`_over`/`_down` and calls
   `mc_goto_frame(ctx, obj, f, /*stop=*/1)` (`:2944`).
   `button_clip_state()` survives as a one-line wrapper passing `mc_states = 1`,
   so **ten of the eleven call sites are textually unchanged**.

**The TRAP was handled.** Ruffle's MovieClip table has no `MouseUpInside` row
(SimpleButton's does). The single release-path site — `if (button == 0 && over
!= NULL) button_clip_state(ctx, over, BTN_ST_UP);`, baseline `:12331`, post-edit
`:12373` — is the one call converted to `button_clip_state_ex(..., BTN_ST_UP,
0)`. Left in, it would
have fired a spurious `_up` goto (and its frame scripts) between Press and
Release, and `output.4` would have shown `_up` instead of `_over`.

`is_button_mode` is ported as `ext->button_mode` alone: Ruffle's other arm
(`movie_clip.rs:2299-2320`) probes AVM1 clip handlers off `object1`, which AVM2
clips never have, so `forced_button_mode` is the whole condition for AVM2
content.

### Call-site table verified against Ruffle

All eleven `button_clip_state` sites in `update_mouse_state`, baseline line
numbers (post-edit in parentheses):

| our site | clip event | our state | Ruffle MovieClip label | reaches MC arm |
|---|---|---|---|---|
| `:12248` (`12287`) | DragOut | OVER | `_over` | yes |
| `:12250` (`12289`) | DragOver | DOWN | `_down` | yes |
| `:12254`, `:12267` (`12293`, `12306`) | RollOut | UP | `_up` | yes |
| `:12259`, `:12272` (`12298`, `12311`) | RollOver | OVER | `_over` | yes |
| `:12299` (`12338`) | Press | DOWN | `_down` | yes |
| **`:12331` (`12373`)** | **MouseUpInside** | UP | **(no row)** | **NO — `mc_states = 0`** |
| `:12340` (`12382`) | Release | OVER | `_over` | yes |
| `:12364` (`12406`) | ReleaseOutside | UP | `_up` | yes |
| `:12370` (`12412`) | RollOver | OVER | `_over` | yes |

---

## 2. Per-frame ledger — `from_shumway/button2`

Local Dawn, `--mode=graphics --images`, `~/CC/dawn-install`. **Grading is valid
as a CI prediction**: the baseline actual PNGs are md5-identical to the CI
lavapipe actuals on `origin/ruffle-image-results`
(`fe01e2d9cc29a4def2795df0429bc617` for `output.{2,3,4}.actual.png`, checked via
`git show`, branch never checked out). Wave 1's finding reconfirmed.

| comparison | outliers before | outliers after | max diff after | status | flip |
|---|---|---|---|---|---|
| `output.1` (`_up`) | 0 | 0 | 0 | pass → pass | — (already passing) |
| `output.2` (`_over`) | 95634 | **0** | **0** | fail → **pass** | **YES** |
| `output.3` (`_down`) | 95634 | **0** | **0** | fail → **pass** | **YES** |
| `output.4` (`_over`) | 95634 | **0** | **0** | fail → **pass** | **YES** |
| trace | pass | pass | — | pass → pass | — |

**+3 image comparisons, exactly as predicted (`95634 = 47817 × 2` on each
frame), and every flip is byte-exact (0 outliers at `tolerance = 0`), not a
near-pass.**

Structural cross-check of our post-fix renders:

```
output.1  fe01e2d9…   (unchanged from baseline — _up)
output.2  1debf2d2… ┐ identical to each other, as the goldens are
output.4  1debf2d2… ┘ (expected.2 md5 == expected.4 md5)
output.3  2771f870…   distinct — _down
```

i.e. the frame sequence our input pump produces is `_up, _over, _down, _over`,
matching the goldens' own 2==4, 3-distinct structure. (Our md5s differ from the
goldens' because of PNG encoder/metadata differences; the pixel comparison is
what is exact.)

Timing behaved as wave 1 predicted: `avm2_input_pump_tick` (`:12592`) consumes
one WAIT group per tick at the tick tail, before render, and `mc_goto_frame`
runs `run_goto` inline because `executing_frame_script` is 0 during the pump.

---

## 3. Canaries — all clean

### 3.1 Render canary (md5 A/B, `render_canary.py capture/compare`)

Standing `ruffle-tests/render_canary_tests.txt` (20 tests) **plus**
`from_shumway/button1`, `from_shumway/button2`, `from_shumway/button3`,
`visual/definefont4`, `visual/focus_highlight/focus_highlight_avm2_button_bounds`.
Both legs `-P 2 --recompile`.

```
25 tests / 50 comparisons
  IDENTICAL    47
  DIFFERS       3          <- from_shumway/button2 output.2/.3/.4 only
  APPEARED 0  VANISHED 0  NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: button2 output.2/.3/.4  fail -> pass
```

* `from_shumway/button1` — 4 comparisons, **all IDENTICAL** (the named canary).
* `from_shumway/button3` (AVM1) — 4 comparisons, **all IDENTICAL**.
* `visual/focus_highlight/focus_highlight_avm2_button_bounds` (the s10 w2-button
  win) — **IDENTICAL**.
* All masks / gradients / filters / blend / morph / cacheAsBitmap /
  `regression/` entries — **IDENTICAL**.
* `visual/definefont4` — `compile_fail`, "compilation timed out" at the 300 s
  cap, **in the BEFORE leg too** (`git_sha b4c983ea4`, unmodified source). Not
  caused by this change; it is the known long-compile false-fail under load
  (seven sibling agents, load average peaked at 21). Identical in both legs, so
  it carries no A/B signal either way.

### 3.2 Trace canary (`--mode=graphics`, s10 `w2-button-report.md` §5 ledger)

24 tests, every result identical to the documented s10 baseline:

| suite | tests | result |
|---|---|---|
| `avm2` | `button_bounds`, `button_hittest`, `button_nested_frame`, `goto_button_nested_framescript`, `mouse_pick_button_mode`, `mouse_over_while_dragging`, `simplebutton_added_to_stage`, `_childevents`, `_childevents_nested`, `_childevents_sprite`, `_childprops`, `_childshuffle`, `_constr`, `_constr_childevents`, `_constr_params`, `_mouseenabled`, `_multi_children`, `_structure`, `_symbolclass` | **19 PASS** |
| `avm2` | `simplebutton_childevents_script_order` | `RUFFLE_MATCHED` — **its baseline status**, not a regression |
| `timeline` | `swf_9_frame_script_button_order` | PASS |
| `timeline` | `frame_script_button_order` | `RUFFLE_MATCHED` — **its baseline status** |
| `regression` | `avm2_simplebutton_click` | PASS |
| `from_shumway` | `slider_component` | PASS |
| `from_shumway` | `button2` | PASS (trace unchanged) |

No `pass → ruffle_matched` transition anywhere (the known trap).

The three tests that were `output_mismatch` at the s10 baseline
(`button_nested_frame_simple`, `simplebutton_childevents_multichild`,
`simplebutton_soundtransform`) were not re-run — they are already failing, so
they cannot regress, and none carries the `_up`/`_over`/`_down` labels.

### 3.3 Regression surface — independently re-verified

Wave 1 measured "exactly ONE SWF corpus-wide has `_up`/`_over`/`_down` frame
labels". Re-checked from the generated timelines rather than the SWF binaries:

```
grep -rl '"_over"\|"_down"\|"_up"' --include=abc_timeline.c ruffle-tests/tests/swfs/
  -> ruffle-tests/tests/swfs/from_shumway/button2/RecompiledABC/abc_timeline.c
```

over the main tree's **2368** recompiled AVM2 timelines — one hit, the target.
`avm2/mouse_over_while_dragging` (a wave-1 loose-substring hit that does set
`buttonMode`) carries only a `"Test"` label. The new goto arm requires *both*
`buttonMode` and a matching label, so it cannot fire anywhere else in the corpus.

`update_mouse_state` is reachable only from `input_deliver` (`:12411`, `:12420`,
`:12428`) — there is no per-tick re-pick, so a stationary mouse cannot produce
repeated gotos.

---

## 4. Files touched

| file | hunks | lines |
|---|---|---|
| `SWFModernRuntime/src/avm2/avm2_display.c` | 2 | +46 / −4 |

Nothing else. No recompiler change, no header change, no test-data change, no
new file. Patch: `w2-button2.patch` (71 lines).

---

## 5. Merge risks

Several wave-2 siblings also touch `avm2_display.c`, so the edit was kept
deliberately narrow:

* **Hunk 1** replaces the 6-line body of `button_clip_state` at `:10545` (just
  after `button_set_state`) and inserts before it. Any sibling editing
  `button_set_state`, the `simplebutton_*` natives below, or `label_to_frame` at
  `:6930` will not overlap. A sibling that *also* rewrites `button_clip_state`
  would conflict — none was expected to (the SimpleButton work was session 10).
* **Hunk 2** is 2 changed lines + 3 comment lines inside `update_mouse_state`'s
  release path (baseline `:12331`, post-edit `:12373`). Contained entirely within the
  `changed_button` / release branch.
* **Line-number drift is the main hazard, not semantic conflict.** The two
  hunks are ~1800 lines apart and both anchor on distinctive text
  (`class_is_a(obj->cls, ctx->builtins.simple_button_class)` and the
  `MouseUpInside`/`player.rs:1777-1787` comment), so a 3-way merge should
  resolve cleanly.
* **`button_clip_state` keeps its exact old signature and semantics for
  SimpleButton**, so any sibling that adds a *new* call site to it inherits
  MovieClip handling automatically — which is the correct default. Only a
  sibling adding a `MouseUpInside`-equivalent site would need
  `button_clip_state_ex(..., 0)`; that is documented in the comment at the
  existing site.
* No shared global, no struct-layout change, no new header symbol — nothing
  that could interact with the masks / blend / scrollRect siblings.

## 6. Recommended CI

`mode=graphics`, `categories=full` (AVM2 runtime change), `images=false` for the
merge run. The +3 pixels only materialise in an `images=true` baseline run; the
trace side must show zero movement.
