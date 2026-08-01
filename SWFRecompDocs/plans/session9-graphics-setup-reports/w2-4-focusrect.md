# w2-4 — Focus-rect highlight phase error (wave-2 YIELD slot)

Session 9 graphics-setup fan-out, wave-2 agent 4. Isolated worktree off
`master` @ `f56b898d9`. Patch:
`scratchpad/patches/w2-4-focusrect.patch` (3 files, runtime-only, no commits).

Rider taken from `w1b-pixel-triage-tooling.md` §4 — "focus-rect highlight state,
10–11 comparisons". **Outcome: 11 comparisons fixed to pixel-identical locally**,
1 of the 11 candidates ruled out (it is a second, unrelated bug), and all 62
adjacent already-green comparisons verified unchanged.

---

## 0. Mandatory pre-checks

| Check | Result |
|---|---|
| `avm1/_investigation/ACCEPTED_DIFFS.md` | no hit for `focusrect` / `focus_highlight` / `focus_rect` |
| `RUFFLE_VS_FLASH_DIFFERENCES.md` | no hit |
| `RUFFLE_COMPAT_TWEAKS.md` | no hit |
| `FLASH_BUGS_REPLICATED.md` | no hit |
| `ruffle-tests/ignored_tests.txt` | no hit |
| `test.toml` `known_failure` on every target | none (also `known_failure: false` on every row of the image JSONs) |

Nothing in the target set is dispositioned; no target dropped.

Baseline re-verified from `_results/image_results_graphics.json` +
`results_graphics.json` on master (both stamped
`git_sha 375373786d2d491b520dca4d4e5ce510df219d1c`, `incomplete: false`). Trace
status of every target is `pass` at baseline, so no target is a
`ruffle_matched` trap.

---

## 1. Root cause — it is three bugs, not one

Wave-1 read the pixels correctly (a 3px ring, `[0,−153,+204]` = `#FF66CC` vs
`#FFFF00`, `ink_iou = 1.00`) and correctly called it a *state/phase* error. It is
actually three independent state errors that share one pixel signature, because
there is only one thing a focus highlight can get wrong.

Ruffle's model (`core/src/focus_tracker.rs`) is the oracle for all three:

* `Highlight` is a **cached tri-state** — `Inactive` / `ActiveHidden` /
  `ActiveVisible`.
* It is recomputed **only** by `update_highlight()`, which runs from
  `set_internal` *when the focused object actually changed*, and unconditionally
  at the tail of `cycle()` (Tab). Nothing else recomputes it — in particular a
  `stageFocusRect` / `focusRect` / `_focusrect` write does **not**.
* It is reset to `Inactive` by `Player::should_reset_highlight` (left
  mouse-down always; for SWF < 9 also move / right / up).
* `render_highlight` (called from `Stage::render_viewport`, *after* the stage
  tree) consults only `highlight().is_visible()` and then recomputes the
  **bounds** fresh via `highlight_bounds()`.

### Bug 1 — AVM1: the visibility decision was re-derived every frame

`action.c::actionGetFocusRectInfo` re-walked `mc->focusrect` up the parent chain
on every rendered frame and bailed when it found `false`. That gets the "bounds
are fresh" half right and the "visibility is cached" half wrong: setting
`clip._focusrect = false` with no intervening focus change hid a highlight that
Flash and Ruffle both keep drawing.

`g_highlight_state` (0/1/2, already maintained by `actionUpdateHighlightState`
at exactly Ruffle's two call sites) already held the correct cached answer; the
render path just wasn't trusting it — it accepted `>= 1` (i.e. `ActiveHidden`
too) and then re-derived the rest.

*Owns:* `focus_highlight_move` `output.05`.

### Bug 2 — AVM1: buttons were highlighted by their **current state**, not their hit area

Ruffle `Avm1Button::highlight_bounds` is a one-liner that explains itself:

> Buttons are always highlighted using their hit bounds. […] their bounds
> usually change on hover (children are swapped out), which would cause the
> automatic tab order to change during tabbing.

We used `resolveMCDisplayList` + `ng_localBoundsOfDL`, i.e. the button's
**currently displayed state's** display list. Decoding
`focus_highlight_avm1_button/test.swf` makes the consequence exact — five
`DefineButton2`s and one sprite, all placed at (50,50):

| tab stop | char | records | hit-area bounds | up-state bounds | expected ring | ours (before) |
|---|---|---|---|---|---|---|
| `button1` | 6 | *(none at all)* | — | — | none | none ✓ |
| `button2` | 7 | HIT=shape1 | 10×10 | *(empty)* | 45,45–54,54 | none ✗ |
| `button3` | 8 | HIT=1 DOWN=2 OVER=3 UP=4 | 10×10 | 40×40 | 45,45–54,54 | 30,30–69,69 ✗ |
| `button4` | 9 | DOWN=2 OVER=3 UP=4 | *(no hit)* | 40×40 | none | 30,30–69,69 ✗ |
| `button5` | 10 | HIT=1,2,3,4 | 40×40 | *(empty)* | 30,30–69,69 | none ✗ |
| `clip6` | 11 (sprite) | — | — | 40×40 | 30,30–69,69 | 30,30–69,69 ✓ |

Exactly the observed `[none, none, big, big, none, big]` vs expected
`[none, small, small, none, big, big]` — and exactly the excess counts wave-1
measured (`output.03` = 1056 channels = 528 px = the 444-px big ring drawn plus
the 84-px small ring missing).

The recompiler's existing hit-record ranking ("prefer filled; on a tie keep the
LAST") already lands on the right shape for `button5` (all four records are
filled, last = shape4 = the 40×40 union), so no recompiler change was needed.

*Owns:* `focus_highlight_avm1_button` `output.02` `.03` `.04` `.05`.

### Bug 3 — AVM2: the focus highlight was never implemented at all

`actionGetFocusRectInfo` keys off `g_focused_mc`, an **AVM1** `MovieClip*`, so it
returns 0 for every AVM2 movie; and `avm2_render_walk` had no highlight step.
AVM2 content therefore drew *no* focus ring, ever.

That is why `avm2/focusrect` scores exactly 6/12: the six comparisons where
Flash draws nothing pass by accident. Walking the test's six stages against
Ruffle's rules reproduces the split exactly:

| stage | `stageFocusRect` | `clip1.focusRect` | a (clip1) | b (clip2) |
|---|---|---|---|---|
| 1 | true | null | ring ✗ | ring ✗ |
| 2 | false | null | none ✓ | none ✓ |
| 3 | true | false | none ✓ | ring ✗ |
| 4 | false | true | ring ✗ | none ✓ |
| 5 | true | null | ring ✗ | ring ✗ |
| 6 | false | null | none ✓ | none ✓ |

All the *inputs* were already present and correct on the AVM2 side —
`g_stage_focus_rect`, the per-object `focus_rect_set` / `focus_rect_val`, and
`obj_highlight_bounds` (which already implements Ruffle's SimpleButton hit-area
special case, and already keys invalid bounds at `Twips::INVALID`). Only the
cached `Highlight` state machine and the draw call were missing.

*Owns:* `avm2/focusrect` `output.01a .01b .03b .04a .05a .05b`.

---

## 2. The fix

Three files, all runtime (`SWFModernRuntime`), no recompiler change — so the
copied `SWFRecomp/build` was valid and `--recompile` was not required.

**`SWFModernRuntime/src/actionmodern/action.c`** — `actionGetFocusRectInfo`:
* Trust the cached state: `if (g_highlight_state != 2) return 0;` and delete the
  per-frame `_focusrect` parent-chain walk (`actionUpdateHighlightState` still
  owns that walk, at the two Ruffle-equivalent call sites).
* Before falling back to the display-list bounds, ask
  `ng_getButtonHighlightBounds` for the focused object's char id. A button with
  a hit area uses those bounds; a button *without* one draws no highlight at
  all; a non-button falls through unchanged.

**`SWFModernRuntime/src/libswf/tag.c`** — new
`ng_getButtonHighlightBounds(char_id, …)` next to `ng_getButtonHitCharId`. Uses
the existing `resolve_hit_shape` (which already follows nested buttons) +
`ng_getCharBoundsForRatio`, applies the hit record's own placement matrix, and
returns a tri-state (`1` button-with-bounds / `-1` button-without /
`0` not-a-button) so the caller can tell "no hit area" apart from "not a button".

**`SWFModernRuntime/src/avm2/avm2_display.c`** — the missing state machine:
* `g_avm2_highlight` (0/1/2) + `avm2_update_highlight()` = Ruffle
  `calculate_highlight`, with `obj_is_highlightable` / `obj_is_highlight_enabled`
  mirroring the per-type overrides (Stage → false, root MovieClip → false,
  TextField → false, else `focusRect ?? stageFocusRect`; the `version() >= 6` arm
  is unconditional because AVM2 is SWF 9+), and the degenerate-bounds →
  `ActiveHidden` rule.
* Called at the tail of `set_focus` (whose existing early-return on an unchanged
  focus *is* the "stageFocusRect write with no focus change doesn't repaint"
  semantics) and unconditionally after `input_handle_tab`'s
  `focus_change_by_key`, matching `cycle()`.
* `g_avm2_highlight = 0` on left mouse-down (`should_reset_highlight`).
* `avm2_render_highlight()` in `avm2_render_walk`, **after** the tree walk and
  before `renderer_close_pass` — mirroring `render_viewport`'s
  render-then-highlight order — drawing the four 3px yellow world-twips rects
  through identity transform slot 0.

---

## 3. LEDGER — comparisons expected to flip `fail → pass` on the next `images=true` CI run

Verification bar: local pixel *grading* is invalid (local Dawn ≠ CI lavapipe), so
each row is **"my actual PNG, captured verdict-independently with
`SWF_KEEP_BUILD_DIR`, decoded and compared against the in-repo expected PNG"**.
Every row came back **byte-identical to expected** (`diffpx=0, maxdiff=0`) — not
merely "ring in the right place". That is stronger than the bar asked for, which
is why confidence is high across the board; the residual risk is purely
lavapipe-vs-Dawn rasterisation of axis-aligned solid rects, the least
AA-sensitive primitive there is.

| # | suite / test | comparison | baseline | baseline excess | after (local) | confidence |
|---|---|---|---|---|---|---|
| 1 | `avm2/focusrect` | `output.01a` | fail | 408 | identical to expected | **high** |
| 2 | `avm2/focusrect` | `output.01b` | fail | 408 | identical | **high** |
| 3 | `avm2/focusrect` | `output.03b` | fail | 408 | identical | **high** |
| 4 | `avm2/focusrect` | `output.04a` | fail | 408 | identical | **high** |
| 5 | `avm2/focusrect` | `output.05a` | fail | 408 | identical | **high** |
| 6 | `avm2/focusrect` | `output.05b` | fail | 408 | identical | **high** |
| 7 | `visual/focus_highlight/focus_highlight_avm1_button` | `output.02` | fail | 168 | identical | **high** |
| 8 | `…/focus_highlight_avm1_button` | `output.03` | fail | 1056 | identical | **high** |
| 9 | `…/focus_highlight_avm1_button` | `output.04` | fail | 888 | identical | **high** |
| 10 | `…/focus_highlight_avm1_button` | `output.05` | fail | 888 | identical | **high** |
| 11 | `visual/focus_highlight/focus_highlight_move` | `output.05` | fail | 648 | identical | **high** |

**Expected yield: +11 image comparisons** (`avm2` 6, `visual` 5). No trace-side
movement expected anywhere — see §5.

---

## 4. Investigated but NOT fixed

### `visual/focus_highlight/focus_highlight_avm2_button_bounds` (`output`)

Wave-1's "plausibly the same bug, making 11". It is **half** the same bug, and it
will **not flip**.

Expected image = 2100 black + 316 magenta (`#FF00FF`, the `SimpleButton`'s
`upState` 20×20 shape) + 84 yellow (the ring, sized to the 10×10 `hitTestState`
— Ruffle's SimpleButton highlight-bounds rule).

* Before: no ring **and** no magenta → 800 excess channels
  (316 px × 2 channels + 84 px × 2 channels = 800 exactly — the arithmetic
  confirms both were missing).
* After: the ring is present and **pixel-exact** (`20,20–29,29`, n=84 — the
  hit-state bounds, confirming `obj_highlight_bounds`' SimpleButton branch was
  already right). Magenta still absent; our render is 2416 black + 84 yellow.
* Residual: **632 excess channels** — still `fail`.

The remaining defect is unrelated to focus: an AVM2 `SimpleButton`'s state
children (`upState` etc.) are not in the object's `render_list`, so
`avm2_render_node` never draws them. That is an AVM2 SimpleButton *rendering*
gap, not a focus-sequence gap, and it is probably multi-comparison (cf.
`visual/cache_as_bitmap/avm2_button` 4692, `…/avm2_button_state` 10353,
`visual/avm2_button_scroll_rect` 28851 — all `fail`, all SimpleButton-shaped).
Out of scope for one slot, and shipping a speculative render-list change here
would have violated the "don't ship a speculative fix" instruction.

Flag for whoever takes the AVM2 button-render arc: this comparison's excess drops
800 → 632 with this patch, so it will read as "improved but still failing" in the
next image diff. That is expected, not a regression.

### `visual/focus_highlight/focus_highlight_render` (6 comparisons)

Wave-1 already excluded it ("a *different* mechanism — hairline AA"). Confirmed:
after the patch its six renders are **md5-identical to before** (§5b), and its
ring geometry already matched expected on 01/02/04 both before and after. It does
not move and must not be counted as this rider's yield.

---

## 5. Canary results

### 5a. Trace canary (`--mode=graphics --diff`) — every touched test

| test | baseline trace | after |
|---|---|---|
| `avm2/focusrect` | pass | pass |
| `avm2/focus_root_movie` | pass | pass |
| `avm2/focus_stage` | pass | pass |
| `avm2/focusrect_focuslost` | pass | pass |
| `avm1/focusrect_swf5`, `focusrect_swf6` | pass | pass |
| `avm1/focusrect_mouse_swf8`, `focusrect_mouse_swf9` | pass | pass |
| `avm1/focusrect_focuslost` | pass | pass |
| `visual/focus_highlight/*` (all 6) | pass | pass |
| `visual/edittext/edittext_caret_empty` | pass | pass |

Byte-identical trace on every one.

### 5b. Render blast-radius canary — 62 already-green comparisons

Wave-1 flagged 21 adjacent green comparisons; the real adjacency is **62** once
the `avm1/focusrect_*` family (which wave-1's avm2+visual-only scan missed) is
included. Method: decode my actual PNG, compare against the in-repo expected PNG.
**All 62 came back `diffpx=0, maxdiff=0`.**

| test | green comparisons | after |
|---|---|---|
| `avm2/focusrect` (the 6 that already passed) | 6 | 6 identical |
| `avm2/focus_root_movie` | 1 | identical |
| `avm2/focus_stage` | 1 | identical |
| `avm2/focusrect_focuslost` | 1 | identical |
| `avm1/focusrect_swf5` | 12 | 12 identical |
| `avm1/focusrect_swf6` | 12 | 12 identical |
| `avm1/focusrect_mouse_swf8` | 8 | 8 identical |
| `avm1/focusrect_mouse_swf9` | 8 | 8 identical |
| `avm1/focusrect_focuslost` | 1 | identical |
| `visual/focus_highlight/focus_highlight_basic` | 9 | 9 identical |
| `visual/focus_highlight/focus_highlight_empty_clip` | 1 | identical |
| `…/focus_highlight_avm1_button` (the 2 that passed) | 2 | identical |
| `…/focus_highlight_move` (the 4 that passed) | 4 | identical |
| **total** | **62** | **62 identical** |

The three AVM2 siblings mattered most — they are precisely "could the new
highlight draw a ring where Flash draws none?". `focus_root_movie`
(`stage.focus = root`, `root.focusRect = true`) exercises the `is_root` override,
`focus_stage` (`stage.focus = stage`) the Stage override, and
`focusrect_focuslost` the `FocusLost → reset_focus → Inactive` path. All three
still render no ring, matching expected exactly.

`focusrect_mouse_swf8` vs `_swf9` is the other good pair: identical content,
different SWF version, and the version-dependent `should_reset_highlight` rule
is the only thing that separates their expected images (swf8 loses the highlight
on move/right-up, swf9 keeps it). Both still match.

For the two adjacent tests whose expected-PNG grading is inconclusive (they fail
on CI for unrelated reasons), an explicit **stash-diff A/B on my own renderer**
was run instead — `git stash`, re-run, md5-compare:

| test | comparisons | before vs after |
|---|---|---|
| `visual/focus_highlight/focus_highlight_render` | 6 | **all md5-SAME** |
| `visual/edittext/edittext_caret_empty` | 12 | **all md5-SAME** |

### 5c. AVM2 focus/tab trace batch (side-effect canary)

This batch exists because `avm2_update_highlight` runs in **NO_GRAPHICS builds
too** (it hangs off `set_focus`, not off the render path), and it calls
`obj_highlight_bounds`, which calls `avm2_text_apply_pending_bounds` — a function
with side effects (it flushes a TextField's lazy autosize bounds). It is safe by
construction — `set_focus` already calls `avm2_text_apply_pending_bounds(ctx,
new_focus)` on the same object two lines earlier, so the second call is
idempotent — but "safe by construction" is not a measurement.

25 AVM2 focus/tab trace tests, run at `-P 2`, each compared against its
`results_graphics.json` baseline status. **Zero movement — 25/25 match.**

| test | baseline | local after | verdict |
|---|---|---|---|
| `edittext_focus_selection` | pass | pass | = |
| `edittext_ime_focus_lost` | pass | pass | = |
| `edittext_tab_stops` | **ruffle_matched** | fail | = (see note) |
| `focus_events_code` | pass | pass | = |
| `focus_events_key_basic` | pass | pass | = |
| `focus_events_key_navigation` | pass | pass | = |
| `focus_events_key_same_object` | pass | pass | = |
| `focus_events_mixed_avm_edittext` | **output_mismatch** | fail | = |
| `focus_events_mixed_key_mouse` | pass | pass | = |
| `focus_events_mouse_basic` | pass | pass | = |
| `focus_events_mouse_focusable` | pass | pass | = |
| `focus_events_mouse_same_object` | pass | pass | = |
| `focus_remove` | pass | pass | = |
| `focusrect_property` | pass | pass | = |
| `selection_onsetfocus_mixed_avm` | **output_mismatch** | fail | = |
| `tab_ordering_arrows` | pass | pass | = |
| `tab_ordering_automatic_advanced` | pass | pass | = |
| `tab_ordering_automatic_basic` | pass | pass | = |
| `tab_ordering_children` | pass | pass | = |
| `tab_ordering_custom_basic` | pass | pass | = |
| `tab_ordering_properties` | **output_mismatch** | fail | = |
| `tab_ordering_stage_tab_children` | pass | pass | = |
| `tab_ordering_stage_tab_children_remove_root` | pass | pass | = |
| `tab_ordering_tabbable` | pass | pass | = |
| `textfield_focusin_event` | pass | pass | = |

Note on reading the table: `edittext_tab_stops` is `ruffle_matched` at baseline,
which the local runner reports as `Pass: 0` — that is a *match*, not a
regression (the `ruffle-matched-trap` lesson). The other three "fail" rows are
`output_mismatch` at baseline and stay failing, unchanged. The four
non-`pass` rows are exactly the four non-`pass` baselines: no test moved in
either direction.

`tab_ordering_arrows` is the one that mattered here — 998 lines of declarative
navigation stages and by far the heaviest consumer of `obj_highlight_bounds`,
the function `avm2_update_highlight` newly calls. It is unchanged.

### 5d. `regression` suite spot-check

`regression/avm2_simplebutton_click` — the only focus/button-adjacent test in the
hand-written suite — still passes (`--mode=graphics --diff`).

---

## 6. Notes for the merge / CI step

* Runtime-only (`SWFModernRuntime/{actionmodern/action.c, libswf/tag.c,
  avm2/avm2_display.c}`). No `SWFRecomp/` change, so no cmake rebuild and no
  `--recompile` needed by downstream agents merging this.
* `mode`: the AVM1 arm lives in `actionGetFocusRectInfo`, which is
  `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` — compiled in the
  no-graphics build too, even though its only consumer is the graphics renderer.
  The AVM2 render hook is `OFFSCREEN_RENDER`/browser-only, but
  `avm2_update_highlight` is unconditional. Nothing here changes trace output in
  either mode, so `graphics` remains the right per-change mode; the weekly
  no-graphics canary covers the rest.
* `images=true` is required to observe the +11. Under the standing
  `images=false` default this patch is invisible in CI.
* No disposition-doc updates are warranted: nothing here is an accepted diff, a
  Ruffle-vs-Flash divergence, or a compat tweak — all three fixes move us *onto*
  documented Ruffle/Flash behaviour, with Ruffle's source as the oracle.
