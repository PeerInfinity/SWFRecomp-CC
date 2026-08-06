# w2-caret — `edittext_caret_empty` ×12 recovery (session 11, wave 2)

**Result: +12 image-comparison flips, 0 regressions.**
`visual/edittext/edittext_caret_empty` output.01–.12 go
`fail (84 / 72 / 57 outlier channels, limit 0)` → **`pass (0 outliers)`**, and the
prediction is **CI-predictive**: the local Dawn render of that test at the pin was
**byte-identical (md5 `16bca994…`)** to the CI lavapipe actual on
`origin/ruffle-image-results`, for all 12 comparisons.

Pin: `bed9d894b`. Worktree: `.claude/worktrees/agent-a15af035694635b9c`.
Test dirs copied from the main tree; main tree never written to, no commits, no CI.

---

## 1. What shipped — three pieces, exactly as briefed, plus two the brief didn't have

| # | piece | file | status |
|---|---|---|---|
| 1 | Corner middle-path: `line_rect = 1` → `0` in the **embedded-font** branch only | `tag.c:4581` | as briefed |
| 2 | Un-gate the caret renderer for OFFSCREEN | `tag.c` ×3 guards | as briefed |
| 3 | Focus must yield a collapsed-selection caret | `action.c` producer | as briefed, via Ruffle's real predicate |
| 4 | **An empty text field never reached the glyph renderer at all** | `action.c:26890` | **not in the brief — the actual blocker** |
| 5 | **Caret geometry + draw-outside-the-mask** | `tag.c` caret block | **not in the brief — required for 12/12** |

### 1.1 Piece 4 — the blocker wave-1 didn't see

`actionIterateTextFieldGlyphs` bailed on the very first check:

```c
if (text_var->str_size == 0) continue;      // action.c, old line 26890
```

Every field in `edittext_caret_empty` is empty, so the field never reached
`textfield_glyph_render_cb` — un-gating the caret renderer alone could not have
worked (wave-1 measured exactly that: "excess stayed 48"). Focused **editable**
empty fields are now routed through with a zero-length synthesised run carrying
the tag's `align`, and `textfield_glyph_render_cb` synthesises the matching
single empty paragraph (`par_count == 0` → one line box). That paragraph is what
gives the caret its x: for empty text the draw loop never runs, so `x_pos` is
still `base_x + par_x_offset[0]` — precisely Ruffle's caret position.

This matters because the 12 fields differ **only** in align / margins / indent:
`align 0/1/2/3` × `leftMargin 0|100` × `rightMargin 0|100` × `indent 0|100`
(chars 2–13, `RecompiledTags/tagMain.c:55-66`). Without the synthesised
paragraph, `par_count` is 0, `par_x_offset` is never applied, and all 12 carets
land at the left gutter — 3 of 12 would have flipped, not 12.

Predicted vs measured caret x (px), all 12 exact:

| cmp | field | align / lm / rm / indent | predicted x | golden x |
|---|---|---|---|---|
| .01 | char2 | left | 7 | 7 |
| .02 | char3 | left (fh 180) | 52 | 52 |
| .03 | char4 | left (fh 100) | 97 | 97 |
| .04 | char5 | center | 160 | 160 |
| .05 | char6 | right | 43 | 43 |
| .06 | char7 | left, lm 5px | 57 | 57 |
| .07 | char8 | right, rm 5px | 128 | 128 |
| .08 | char9 | center, rm 5px | 157.5 → snap 157 | 157 |
| .09 | char10 | justify, lm 5, rm 5 | 12 | 12 |
| .10 | char11 | left, lm 5, rm 5, ind 5 | 62 | 62 |
| .11 | char12 | right, lm 5, rm 5, ind 5 | 128 | 128 |
| .12 | char13 | center, lm 5, rm 5, ind 5 | 162.5 → snap 162 | 162 |

### 1.2 Piece 3 — the predicate, not a forced 0

Wave-1 asked for Ruffle's predicate rather than `caret_char = 0`. Ported from
`edit_text.rs::visible_selection` (L1059) + `focus_tracker.rs::update_edittext_selection`
(L236-247):

* AVM1 key/programmatic focus sets `TextSelection::for_range(0, text_length)` —
  our runtime already models that as `g_tf_select_all`.
* A **non-collapsed** selection renders as a highlight, never a caret.
* A **collapsed** selection renders as a bare caret, but only while focused **and
  editable** (`!EditTextFlag::READ_ONLY`, surfaced here as `type == "input"`;
  new helper `tf_is_editable`).
* On an empty field `for_range(0, 0)` **is** collapsed ⇒ caret at 0. That is the
  whole of `edittext_caret_empty`.

Deliberately **not** touched: `g_selection_begin/caret/end` on Tab focus. Ruffle
sets a real `[0, len]` selection there, but our `Selection.getCaretIndex()`
compat (0/0/0 after programmatic `setFocus`, `-1` after Tab) is load-bearing on
the trace axis. Deriving the caret from `g_tf_select_all` gets the pixels right
with **zero** AS-visible state change — the trace axis is provably untouched.

Side effect, Ruffle-correct: a *range* selection no longer also draws a caret
(browser-WASM only; previously we drew both).

### 1.3 Piece 5 — caret geometry

Three things were wrong in the (browser-only, untested) caret block:

* **Height** was `baseline_fh` (the em height). Ruffle: `let caret_height =
  ascent + descent;` (`edit_text.rs:1277`), scaled to the line's font height.
  `ng_font_get_metrics`'s `descent` out-param was being passed `NULL`.
* **Pixel snapping.** `EditTextPixelSnapping::apply` for quality ≥ medium does
  `(tx + Twips::new(2)).trunc_to_pixel()` on x and y. Without it, `.08` and `.12`
  land on a half-pixel and render as two 50 %-covered grey columns.
* **Clipping.** The caret was drawn *inside* the field's gutter-inset stencil
  mask. Ruffle explicitly defers it (`EditTextRenderState::draw_caret_command`,
  "We have to draw the caret outside of the text mask"). It is not cosmetic: a
  right-aligned empty field puts the caret exactly **on** the mask's right edge,
  so `.05 / .07 / .11` would have rendered nothing at all. The draw now happens
  after `renderer_end_clip`.

### 1.4 Piece 1 — corner, confirmed exactly as wave-1 measured

`line_rect = 0` in the `else if (info->has_matrix)` (embedded-font) branch only.
The device branch is untouched, so `border_transform .01/.02/.03/.05` keep their
flips and `.04/.06` each improve by 1 — the measured numbers below match wave-1's
prediction to the digit.

---

## 2. Per-comparison ledger

`before` = CI graphics baseline (`results_graphics.json`, run at `c4496a4c8`,
which is source-identical to the pin — `bed9d894b` adds only docs).
`after` = local `--mode=graphics` Dawn render of this worktree.
`md5-vs-CI` = local-after PNG vs the CI actual exported to
`origin/ruffle-image-results` (which exists only for comparisons that FAILED at
baseline). **30 of the failing comparisons in the canary set are byte-identical
local↔CI**, which is what licenses reading the local numbers as CI predictions.

### 2.1 The target — +12

| comparison | before | after | flip | CI-predictive |
|---|---|---|---|---|
| `visual/edittext/edittext_caret_empty output.01` | fail / 84 | **pass / 0** | ✅ | **yes** (baseline md5 identical) |
| … `output.02` | fail / 72 | **pass / 0** | ✅ | yes |
| … `output.03` | fail / 57 | **pass / 0** | ✅ | yes |
| … `output.04` – `output.12` (×9) | fail / 84 | **pass / 0** | ✅ ×9 | yes |

Residual after the fix is 0 outliers at tolerance 128, `max_diff 95` — the border
corner, which we now draw solid black against the golden's AA'd `(95,95,95)`.
`|0−95| = 95 ≤ 128`. That is the pre-s10 state, restored deliberately.

### 2.2 Everything else that moved (5 comparisons, 0 flips lost)

| comparison | before | after | reading |
|---|---|---|---|
| `visual/edittext/edittext_border_transform output.04` | fail / 52 (tol 128, lim 20) | fail / **51** | improves by 1, exactly as wave-1 predicted |
| … `output.06` | fail / 45 | fail / **44** | improves by 1 |
| `visual/cache_as_bitmap/edittext_selection output.03` | fail / 399 (tol 0, lim 8) | fail / **373** | **improves by 26** — the golden's caret bar at x=74 y=3..31 is now drawn (we paint it black, golden is magenta `(204,0,204)`, and ours starts one row higher) |
| `visual/edittext/edittext_border_filters output` | fail / 827 (tol 32, lim 17) | fail / **827** | **wash** — 3 corner px flip white→black; golden is `(96,96,96)`/`(151,151,151)`, both sides outliers at tol 32 |
| `visual/edittext/edittext_negative_bounds output` | fail / 717 (tol 128, lim 0) | fail / **720** | **−3 channels**: one corner px at (170,110) where the golden is white. Already failing by 717; no flip either way. The only place the corner change costs anything. |

### 2.3 Canaries — all green

**Absolute verdict held (`pass` → `pass`) on every comparison that passed at
baseline. Zero pass→fail anywhere. Zero trace-status moves.**

* `edittext_border_transform` **.01 / .02 / .03 / .05 — still pass** (the 3–4
  s10 flips are not at risk; the device branch was not touched).
* `edittext_selection_leading` **×12 — all still pass**, including `.09` and
  `.11` which sit *exactly* on their `max_outliers = 36` budget (36 → 36).
* `avm1/focusrect_swf5` ×12 — pass, byte-identical.
* `visual/focus_highlight/*` — `_basic` ×9, `_move` ×5, `_avm1_button` ×6,
  `_avm2_button_bounds`, `_empty_clip` all pass; `_render` ×6 unchanged
  (fail/2127, 2115, 4371, 2127, 2178, 2495 — all **byte-identical to CI**).
* `visual/cache_as_bitmap/edittext_{scroll,hscroll}` — byte-identical;
  `oversize/swf_{9,10}_too_big` — still pass (standing CAB canary).
* `avm2/edittext_{always_show_selection, autosize_height_dynamic,
  getcharboundaries}` — unchanged.
* `edittext_device_transform_{basic,metrics,negative}` were **already**
  `output_mismatch` at the CI baseline; unchanged. `_small_rotation` still
  passes at 11/11 on its budget; `_small_shear` byte-identical.
* Standing `render_canary_tests.txt` (both tiers, 20 tests): **every PNG
  byte-identical** — `avm1/{color,bitmap_data_fillrect,mask_with_drawing,
  movieclip_setmask,edittext_tag_indent,bitmapdata_applyfilter_colormatrix}`,
  `avm2/blend_multiply_alpha`, `visual/simple_shapes/{winding_rule,masks,
  gradients}`, `visual/filters/{drop_shadow,color_matrix}`,
  `visual/blend_modes/multiply`, `visual/cache_as_bitmap/shape_changed`,
  `from_shumway/{timeline/timeline_as2_5,acid/acid-gradient-0}`,
  `regression/{avm2_timeline_gradients,avm2_timeline_stroke_gradient,avm2_morph}`.
* **Batch 2** — I enumerated *every* graded test in the corpus that carries an
  `input.json` (i.e. can move keyboard focus) plus every graded test whose SWF
  references `setFocus`/`setSelection`/`caretIndex`, then ran the ones the main
  set missed. See §2.4.

Raw ledger: `scratchpad/w2caret/ledger.txt` (regenerate with `ledger.py`).

### 2.4 Batch-2 result — 13 tests, 58 comparisons, **100 % unmoved**

Every one of the 32 corpus-wide graded tests with an `input.json` is now covered
(19 in the main set, 13 here). Batch 2 result: **not one PNG moved.**

| test | comparisons | result |
|---|---|---|
| `avm2/focusrect` | 12 | all pass/0, unchanged |
| `avm2/focusrect_focuslost` | 1 | pass/0 |
| `avm1/focusrect_swf6` | 12 | all pass/0 |
| `avm1/focusrect_mouse_swf8` | 8 | all pass/0 |
| `avm1/focusrect_mouse_swf9` | 8 | all pass/0 |
| `avm1/focusrect_focuslost` | 1 | pass/0 |
| `avm1/mouse_events_visible_enabled` | 1 | fail/3614 → **byte-identical to CI** |
| `avm1/frame_size_translated_{negative,positive}` | 2 | pass/1 → pass/1 |
| `from_shumway/button1` | 4 | all pass/0 |
| `from_shumway/button2` | 4 | 1 pass, 3 fail/95634 → **byte-identical to CI** |
| `from_shumway/button3` | 4 | pass/3489 → pass/3489 (on-budget, held) |
| `from_shumway/3_joystick` | 1 | fail/70634 → **byte-identical to CI** |

**Totals across both batches: 68 tests, 181 image comparisons graded,
17 moved (12 flips + 3 improvements + 1 wash + 1 −3), 0 regressions,
0 trace-status moves.**

---

## 3. Files touched, and the exact `tag.c` hunks (for the coordinator)

A sibling is editing `tag.c` mask / pipeline code. My hunks, by **pre-image**
line number, are all inside two static functions and touch **no** mask, clip,
pipeline, blend, or transform-slot machinery except one statement reorder:

`SWFModernRuntime/src/libswf/tag.c` (+59 / −11):

| pre-image lines | function | what |
|---|---|---|
| `4581` | `textfield_render_cb` | `line_rect = 1;` → `line_rect = 0;` + comment (embedded-font box branch) |
| `4653` (after) | `textfield_render_cb` | comment only, above the existing `if (!plain) line_rect = 0;` |
| `4707–4709` | `textfield_glyph_render_cb` | add `s16 descent`, pass it to `ng_font_get_metrics` (was `NULL`) |
| `4858` (after) | `textfield_glyph_render_cb` | new `if (par_count == 0) { … }` empty-paragraph synthesis |
| `5005–5008` | `textfield_glyph_render_cb` | guard `#if !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` → `#ifndef NO_GRAPHICS` + comment |
| `5050` | `textfield_glyph_render_cb` | same guard change |
| `5110–5133` | `textfield_glyph_render_cb` | **the one reorder**: the caret draw moves from *before* to *after* the existing `if (has_clip) renderer_end_clip(context);`, and its guard changes. `renderer_end_clip` itself is unmodified — only its position relative to the caret block. |

`SWFModernRuntime/src/actionmodern/action.c` (+86 / −35):

| pre-image lines | what |
|---|---|
| `26751` (before `actionIterateTextFieldGlyphs`) | new `static int tf_is_editable(ASObject*)` |
| `26887–26932` | empty-text branch: `continue` → route focused editable empty fields through; the existing non-empty path becomes an `else` (re-indent only, no logic change) |
| `27012–27033` | caret + selection predicate rewrite |

**Merge risk assessment: low.** No shared symbol is added to a header; both new
statics are file-local. The only cross-cutting edit is the `renderer_end_clip`
reorder inside `textfield_glyph_render_cb` — if a sibling also edits that
function's clip handling, that hunk is the one to hand-merge. Nothing else in
`tag.c` is near the mask/pipeline code.

---

## 4. Known residuals and follow-up leads

1. **`cache_as_bitmap/edittext_selection output.03` (373, limit 8).** We now draw
   the caret Ruffle draws, but in **black** rather than the field's magenta, and
   one row too tall at the top. Ruffle colours the caret with the *layout box's*
   run colour (`lbox.as_renderable_text(...) → color`); we use the field-level
   `info->text_color`. Cheap to fix (carry `cur_color` at the caret index); worth
   ~26 more channels but nowhere near the limit-8 budget, so it flips nothing on
   its own. Same mechanism will apply to `edittext_hscroll output.01`, whose
   golden also has a magenta caret (that field stayed byte-identical here, so it
   is not focused/editable in our run — a separate lead).
2. **`edittext_negative_bounds` −3 channels.** One embedded-font box whose golden
   has an *open* bottom-right corner even though `draw_text_box`'s strip is
   closed — Ruffle's own doc comment hedges with "*usually*". Worth 3 channels on
   a comparison already failing by 717; not chased.
3. **Dynamic (`createTextField`) empty fields still get no caret.** The new
   routing requires `ng_textfield_idx >= 0` (a static `DefineEditText`), because
   the tag's `align` comes from `ng_getTextFieldAlign(idx)`. Browser-WASM only;
   no corpus coverage; status quo preserved deliberately (relaxing it would need
   an align default and a fresh canary pass).
4. **The horizontal-scroll block (`tag.c:4901`) stays browser-gated.** Un-gating
   it would move glyph positions for long-text focused fields in CI. The caret
   is drawn at the unscrolled position, consistently with the glyphs. Left alone
   on purpose.

## 5. Method notes worth keeping

* **The CI baseline board is a complete "before" leg.** `results_graphics.json`
  carries per-comparison `stats.outliers/tolerance/max_outliers`, and
  `origin/ruffle-image-results` carries the actual PNG for every *failing*
  comparison. Grade local-after against those two and you need **no local
  before-leg render at all** — provided you also check md5 identity on the
  unrelated comparisons to prove local Dawn ≡ CI lavapipe for that corner of the
  corpus. That halved this session's wall clock (one 2 400 s capture, not two).
* **Enumerate the blast radius mechanically, not by memory.** `grep -rl
  image_comparisons --include=test.toml` ∩ `has input.json` is the exact set of
  graded tests that can move keyboard focus — 32 tests, corpus-wide. That is a
  reusable recipe for any focus/input-shaped render change.
* **`--image-out-dir` exports only failures.** A run that flips everything to
  pass exports *nothing*, which reads identically to "the run did not happen".
  Grade off `SWF_KEEP_BUILD_DIR` (what `render_canary.py` does) or `--verbose`.
