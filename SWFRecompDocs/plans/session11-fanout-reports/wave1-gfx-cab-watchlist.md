# wave-1 `gfx-cab-watchlist` — the s10 worsened band + the cacheAsBitmap real-cache slice

Session 11, wave 1, **READ-ONLY on the main tree**. All experiments ran in a
throwaway worktree (`scratchpad/wt-cab`, removed at the end). No source edits,
no commits, no CI.

Provenance: board regenerated from `origin/ruffle-image-results` (force-pushed
to the s10 closeout run **30713776612 @ `c4496a4c8`**, 346 failing comparisons).
Band moves from `scripts/image_status_diff.py b7317667d 64d1f266b`
(feb8882b0 → c4496a4c8). Local Dawn legs reproduced the CI outlier counts
**exactly** on every test used below (84/72/57, 61404, 44823/44599/42031,
59137/69060/72114), so the local A/Bs are predictive, not indicative.

**Trap found and worked around:** a single-test `--images` run does NOT rewrite
the per-suite `image_results_graphics.json` rows for the test it ran — it
re-serialises the *previous* numbers. Two of my A/B legs read as "no change"
from the JSON while the exported PNGs showed the change. **Grade local A/B legs
off the exported `*.actual.png`, never off `image_results_graphics.json`.**
(Same family as `ci-single-test-run-clobbers-results`; worth a playbook line.)

---

## 0. The complete worsened band (22 comparisons, not 15)

The brief listed three items. The full `image_status_diff` worsened list is:

| comparisons | test | s9 → s10 excess | owner (this report) |
|---|---|---|---|
| ×12 | `visual/edittext/edittext_caret_empty` | 48/36/21 → 84/72/57 | **§1 — re-balance, exact one-liner, zero cost** |
| ×1 | `from_gnash/misc-ming.all/place_object_test` | 35451 → 61404 | **§2 — keep the trade** |
| ×7 | `visual/cache_as_bitmap/masks` | ~40–45k → ~59–72k | **§3 — keep the trade** |
| ×1 | `avm2/bitmapdata_draw_masks` | 10050 → 12150 | §3, same mechanism |
| ×1 | `visual/avm2_button_scroll_rect` | 28851 → 34590 | §3, same mechanism (already noted in s10 §9) |

None of the five tests appears in `ignored_tests.txt`, `ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md` or
`FLASH_BUGS_REPLICATED.md`.

---

## 1. `edittext_caret_empty` ×12 — **REFUTED framing; RE-BALANCE, cost = 0**

### 1.1 What the brief said, and why it is wrong

> "hairline excess rose 48→84 from the s10 device-box corner-pixel trade
> (EditText device-box **now draws** its bottom-right corner)"

**REFUTED, sign-inverted.** The s10 device box does **not** draw the corner and
must not. The 12 new outliers are the corner that the s10 change stopped
drawing on the *other* branch — the **embedded-font** box. And the recorded
revert lever (`line_rect = 0` in the `device_box` branch, −3 flips) is aimed at
the wrong branch entirely: it costs the three flips and recovers nothing.

### 1.2 Measured diff (tolerance 128, `max_outliers = 0`)

`output.01` differs in exactly 28 px / 84 channels:

* **16 px** — a vertical black caret bar at `x=7, y=7..22` inside the focused
  field. Golden has it, we draw white. (`.02` = 12 px at `x=52`, `.03` = 7 px at
  `x=97` — the fields have different font sizes, so the bar height varies.)
  **This is the whole s9 baseline (48/36/21).**
* **12 px** — one per field, at the **bottom-right corner** of each of the 12
  EditText borders: golden `(95,95,95)`, ours `(255,255,255)`.
  `|255−95| = 160 > 128` ⇒ outlier. **This is the entire s10 delta (+36 ch).**

Before s10 we drew that corner solid black: `|0−95| = 95 ≤ 128` ⇒ **not** an
outlier. So the corner was never "right", it was merely inside tolerance.

### 1.3 Root cause — Ruffle has TWO box painters and we conflated them

`~/CC/ruffle/core/src/display_object/edit_text.rs::render_self` L2722-2732:

```rust
if self.is_device_font() { self.draw_device_text_box(...) }
else                     { self.draw_text_box(...) }
```

* `draw_device_text_box` (L2845) emits **four separate `draw_line` calls** with
  hand-rolled half-pixel extents. Union = `[x_min..x_max]×[y_min..y_max]`
  **minus** `(x_max, y_max)`. The bottom-right corner is genuinely absent.
* `draw_text_box` (L2930) emits **one `draw_line_rect`** — a *closed*
  strip, `descriptors.rs: indices_line_rect = [0,1,2,3,0]`. Ruffle's own doc
  comment on that function says it outright: *"the bottom-right corner of the
  border is **NOT** missing (usually)"*. The corner is drawn (at ~63 % coverage
  after AA, hence the golden's `95`).

Golden evidence, both device-vs-embedded in the same corpus:

* `edittext_border_transform output.01` (key `1` ⇒ `embedFonts = false` ⇒ device)
  — golden box rows 5..17 × cols 5..17, top row `5..17` full, **bottom row
  `5..16`**, right col `5..16`. Corner **open**, 441 pure-magenta px, zero AA.
* `edittext_caret_empty` — SWF tag dump: every `DefineEditText` has
  `UseOutlines = 1` (`f2 = 0x09 / 0x29`, bit 0). **Embedded font ⇒ closed
  corner.** Our `embedFonts` property is seeded from exactly that flag
  (`action.c:22182`, `22433`, mask `0x0080`).

### 1.4 The bug in our code

`SWFModernRuntime/src/libswf/tag.c::textfield_render_cb`
(decl **4504**, the branch at **4560/4581**):

```c
int device_box = (info->has_matrix && info->device_font);
if (device_box) { ...; line_rect = 1; }          // 4560  CORRECT (open)
else if (info->has_matrix) { ...; line_rect = 1; }  // 4581  WRONG (must be closed)
```

`line_rect = 1` is the open-polyline draw (bottom rect `w - bl`, right rect
`h - 2*bt`, corner dropped) at **4661-4666**. s10 set it on **both** branches;
Ruffle only opens the device one.

### 1.5 Exact change + measured effect

**`tag.c:4583` — `line_rect = 1;` → `line_rect = 0;` in the `else if
(info->has_matrix)` (embedded-font) branch only.**
The trailing `if (!plain) line_rect = 0;` (**4653**) becomes dead there;
harmless, but worth a comment update.

Measured in-worktree (PNG-graded, Dawn):

| comparison | before | after | note |
|---|---|---|---|
| `edittext_caret_empty output.01/.04…12` | 84 | **48** | corner recovered |
| … `output.02` | 72 | **36** | |
| … `output.03` | 57 | **21** | |
| `edittext_border_transform output.01/.02/.03/.05` | pass | **pass** | device branch untouched — **the 3–4 flips are NOT at risk** |
| … `output.04` (embedded) | 52 outliers | **51** | improves by 1 |
| … `output.06` (embedded) | 45 outliers | **44** | improves by 1 |

Control leg: closing the **device** corner as well (the brief's lever) breaks
`border_transform .01` and `.03` — 3 outliers each, tolerance 0 → **fail**.
Confirms the s10 report's cost estimate *for that branch* and confirms the
branch split is the right discriminator.

**Verdict: RE-BALANCE. One character. 0 flips on its own, 0 regressions,
and it un-blocks the 12-flip caret item below.**

### 1.6 Follow-on: the caret is a 12-flip wave-2 item

With the corner fixed, the *entire* residual on all 12 comparisons is the
missing caret bar. Draw it correctly ⇒ excess 0 ⇒ **12 flips**.

The renderer already exists and is **deliberately gated off**:

* `tag.c:5116-5127` draws the bar; the block is wrapped in
  `#if !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` with the comment
  *"OFFSCREEN / headless CI captures must stay caret-free … would otherwise add
  a caret bar and diverge from Ruffle's baseline"*. **That premise is refuted:
  Ruffle's own goldens for this test contain the caret.** Same gate at
  `tag.c:5008-5011` for the tracking variables.
* Un-gating alone is **not** sufficient — measured: excess stayed 48. The
  producer feeds `info.caret_char = (mc == g_focused_mc && g_selection_caret >= 0)
  ? g_selection_caret : -1` (`action.c:27014`), and `actionAdvanceTabFocus`
  (`action.c:72995`, wired to Tab at `input_events.c:332/341`) sets
  `g_focused_mc` but leaves `g_selection_caret = -1` (it sets
  `g_tf_select_all = 1` instead, `action.c` ~73106). For an **empty** field
  select-all *is* a collapsed caret at index 0.

**Wave-2 brief (predicted +12, all tolerance 128 / limit 0):**
1. `tag.c:4583` `line_rect = 0` (§1.5).
2. Drop `&& !defined(OFFSCREEN_RENDER)` from the two caret guards
   (`tag.c:5008`, `tag.c:5116`).
3. Make Tab-focus of a text field yield a caret index: when the focused field's
   selection is collapsed (incl. select-all on empty text), `caret_char = 0`.
   Ruffle's predicate is `visible_selection()` = focused **and** editable for a
   bare caret (`edit_text.rs:1059`) — port that, do not just force 0.
4. **Canary risk is real and wide:** any CI test that focuses a text field will
   now grow a 1-px bar. Mandatory canary set below (§5).

---

## 2. `place_object_test` +73 % — **KEEP THE TRADE (and my own first bisect was wrong)**

### 2.1 Bisect

Local Dawn, one comparison, tolerance 50, `known_failure = true` at *both* test
and comparison level:

| ref | excess | |
|---|---|---|
| `feb8882b0` (s9 baseline) | **35451** | == CI baseline |
| `98ba131be` (s10 w2-text) | **61404** | ← **regression enters here** |
| `86a3200b4` (s10 w2-blend) | 61404 | |
| `b4c983ea4` (HEAD) | **61404** | == CI |

**Self-refutation recorded:** I first attributed this to the w2-blend commit
(it was the first ref I tested after s9) and even ran a targeted revert of the
nested-blend arm in `render_display_list` — no effect. Widening the bisect to
the intermediate commits put it two commits earlier. *Bisect to the commit
before reverting hunks.*

Two other suspects were **refuted by direct experiment**:
* the s10 **loop-phase** fix (`swf.c` `g_pending_natural_wrap_promote`) —
  reverted to the old `goto_from_action = 1` form: **byte-identical, 61404**.
* the s10 **AVM2 cxform** fix — n/a (this test is AVM1, no DoABC).

### 2.2 Root cause — a silent draw-budget overflow used to hide our own bug

Confirmed by a one-line probe at HEAD: restoring
`SWFModernRuntime/src/rendering/render_webgpu.c:980-981`

```c
#define MAX_DYNAMIC_RECTS 4096      // was 1024
#define MAX_DYNAMIC_VERTICES 262144 // was 32768
```

to their pre-s10 values takes the excess straight back to **35451**.

The visible difference is entirely in the gnash *xtrace* text field
(rows 38..119); the shapes are byte-identical between s9 and s10. Before the
raise, our AVM1 dynamic TextField ran out of dynamic vertices after ~3 lines
and the glyph run was **silently truncated mid-line** (the s9 render's third
line stops at `x=31`). After the raise all ~9 lines draw.

So the "improvement" the raise removed was an artifact: we were closer to the
golden only because a renderer budget was quietly dropping our own excess ink.

### 2.3 Verdict

**KEEP.** The budget raise is correct and paid for itself elsewhere
(`fonts/embed_matching/fallback_preferences` 121914 → 62241 etc.). Reverting it
would re-break those and re-introduce a silent truncation.

The *real* defect this exposed, and it is not new: our AVM1 dynamic TextField
renders ~9 long trace lines where the Flash golden shows **6 short** ones
(golden max row-ink 287 vs our 380, golden lines end by x≈100, ours reach
x≈611). That is an AVM1 text-content/field-clipping divergence, pre-existing,
on a test Ruffle itself does not pass (`known_failure = true` on both axes).
**Low priority; do not chase it from the pixel board.**

**Standing lesson for the playbook:** a renderer capacity raise is a *silent
correctness change*. Any future `MAX_DYNAMIC_*` / slot-pool raise should be
A/B'd on the image axis, because tests that were "passing by truncation" will
move.

---

## 3. `cache_as_bitmap/masks` ×7 (+ `bitmapdata_draw_masks`, `avm2_button_scroll_rect`) — **KEEP THE TRADE**

### 3.1 Bisect + isolation

| ref | `masks .01 / .03` |
|---|---|
| `feb8882b0` (s9) | 44823 / 42031 |
| `86a3200b4` (w2-blend) | **44823 / 42031** — blend is innocent |
| `b4c983ea4` (HEAD) | **59137 / 72114** — == CI |
| HEAD with `avm2_display.c` reverted to `8186c2a24` | **44823 / 42031** |

So the owner is exactly the **AVM2 colour-transform propagation** half of
`c4496a4c8` (fix 3b) in `SWFModernRuntime/src/avm2/avm2_display.c`
(`avm2_cx_of_ext` / `avm2_cx_compose` / `avm2_alloc_cx_slot`, ~14159-14235;
`avm2_render_node` widened at 14884-14896).

### 3.2 Root cause — the fix is CORRECT; the mask debt is what grew

Instrumented `avm2_alloc_cx_slot` (diag build, 144 allocations, pool 263 — **no
exhaustion**, so the slot-economy hypothesis is refuted). Every allocation looks
like:

```
mult 0.000 0.000 0.000 1.000   add 1.000 0.000 1.000 0.000    (→ magenta)
mult 0.000 0.000 0.000 1.000   add 0.000 1.000 1.000 0.000    (→ cyan)
```

i.e. `ColorTransform`s that *replace* a shape's colour. Before s10 the AVM2 walk
was alpha-only, so those shapes rendered in their authored fill — **white on a
white stage, i.e. invisible**. Now they render in their correct colours. Colour
histograms confirm: at `86a3200b4` `masks output.03` contains only blue+black;
at HEAD it contains blue + green + cyan + yellow + red, and the golden contains
cyan + green.

Because AVM2 `.mask` is not plumbed into the render walk at all
(`wave1-gfx-masks` defect D), all that newly-correct colour lands *outside* the
mask and the excess metric grows. Identical pattern, identical cause, for
`avm2/bitmapdata_draw_masks` (+21 %) and `visual/avm2_button_scroll_rect`
(+20 %) — the latter already flagged in playbook §9 as "excess GREW now that the
button draws".

### 3.3 Verdict

**KEEP. Not a regression — mask-arc debt made visible.** These 9 comparisons
are pure `extra_element` and belong to the AVM2 mask / T7 arc
(`session10-fanout-reports/wave1-gfx-masks.md`). The excess number on them is
**not a progress signal** until masks land, and it will keep climbing every time
AVM2 rendering gets more correct. Recommend the coordinator mark the
`cache_as_bitmap/masks` + `bitmapdata_draw_masks` + `avm2_button_scroll_rect`
rows as *mask-blocked* in the ledger so the next `image_status_diff` does not
re-raise them as a watchlist item.

---

## 4. PART 2 — the cacheAsBitmap REAL-CACHE slice: **NO-GO standalone, and it is paired with the wrong arc**

### 4.1 The seven comparisons, re-scoped

s10's `wave1-gfx-cab-misc` §"A. Genuine CAB mechanism" listed 7 and recommended
*"pair with the Filters arc"*. Two of its premises no longer hold.

| cmp | test | SWF ver / VM | what it actually needs |
|---|---|---|---|
| 1 | `cab_mask_alpha` | 41 / **AVM2** | AVM2 `.mask` plumbing → alpha mask |
| 2 | `cab_mask_transform` | 41 / **AVM2** | same |
| 3 | `cab_mask_triangle` | 41 / **AVM2** | same |
| 4 | `cab_mask_filters` | 41 / **AVM2** | same **+ filters** |
| 5 | `oversize/swf_9_masks` | 9 + DoABC / **AVM2** | same + swf≤9 size gate |
| 6 | `oversize/swf_10_masks` | 12 + DoABC / **AVM2** | same + swf>9 size gate |
| 7 | `contains_grown_filter` | 15, **no DoABC → AVM1** | **filters only; no cache, no mask** |

All four `cab_mask_*` are `maskee.mask = mask` on AS3 `DisplayObject`s; both
`oversize/*_masks` are `bg.mask = test` in `Test.as`. **6 of 7 are AVM2
`.mask`.** `get_render_mask` (`display_object.rs:1979`) returns
`RenderMask::Alpha` only when **both** maskee and masker are
`is_bitmap_cached()`; otherwise `Stencil`. We currently render **neither** —
the AVM2 walk reads no `mask`/`clip_depth`/`scroll_rect` at all.

### 4.2 Refutation 1 — the blocking arc is MASKS, not FILTERS

s10's recommendation to pair the cache with the Filters arc is **REFUTED**.
Only 1 of the 7 (`contains_grown_filter`) is filter-shaped and it needs no
cache; 1 more (`cab_mask_filters`) needs filters *in addition to* masks. The
binding prerequisite for 6/7 is **AVM2 mask plumbing** (wave1-gfx-masks defect
D + the T7 arc). A "cacheAsBitmap agent" launched without it produces zero
flips.

### 4.3 Refutation 2 — "needs an offscreen render target" is already paid

`wave1-gfx-cab-misc` costed this as an arc partly because of "offscreen render
target, per-object surface allocation". That was written **before** w2-blend
landed. The scaffold now exists and is exercised every frame:

```
renderer_suspend_pass / renderer_capture_backdrop / renderer_begin_offscreen_pass
renderer_end_offscreen_pass / renderer_resume_pass / renderer_composite_blend
renderer_composite_filtered(ctx, ox, oy, tr,tg,tb,ta)
```
(`SWFModernRuntime/include/rendering/renderer.h:48-57`, used at
`tag.c` render_display_list / tagShowFrame / tagRerenderFrame.)

An alpha mask is "render maskee to layer A, render masker to layer B, composite
A with `A.rgb * B.a`" — one extra composite mode on machinery that already
suspends/resumes a pass with its own MSAA depth-stencil. **The offscreen cost is
sunk; the remaining CAB-specific work is small.**

### 4.4 The size gates (unchanged, and cheap)

`~/CC/ruffle/core/src/display_object.rs::BitmapCache::update` L163-186:

```rust
let acceptable_size = if swf_version > 9 {
    actual_width < 8191 && actual_height < 8191 && actual_width*actual_height < 16777215
} else {
    actual_width < 2880 && actual_height < 2880
};
```
measured on the **device-pixel** surface (post-stage-scale, post-filter-growth).
Confirmed. `oversize/swf_9_too_big` and `swf_10_too_big` pass today **for the
right reason** (we never cache ⇒ we always produce the uncached/stencil answer).
The gate is ~6 lines and **must ship in the same change as the alpha-mask path**
or those two flip pass→fail. Keep them as the standing CAB canary.

### 4.5 GO / NO-GO

* **NO-GO** as a standalone wave-2 agent, in this session or the next, until
  AVM2 `.mask` reaches the render walk. Yield without it: **0**.
* **GO as a rider on the AVM2 mask/T7 arc**, sized at roughly one extra agent-day
  on top of it: (a) alpha-mask composite variant of the existing offscreen pass,
  (b) the `is_bitmap_cached()` predicate on both maskee and masker,
  (c) the two size gates. Yield **6** (`cab_mask_alpha/transform/triangle`,
  `oversize/swf_{9,10}_masks`, and `cab_mask_filters` once filters land),
  with `swf_{9,10}_too_big` as the guard.
* **RE-FILE `contains_grown_filter`** out of the CAB slice entirely. It is
  AVM1, `PlaceObject3` + filter on a **nested sprite** (2 `DefineSprite`s, no
  DoABC), 200×200, tolerance 5. We draw the 40×40 blue square with **zero**
  glow pixels (our ink bbox 80..119, golden 63..136, 4408 ink px vs our 1600) —
  i.e. the filter is not being applied at all through the sprite container, not
  a texture-growth clipping problem. `renderer_composite_filtered` already
  takes an `(ox, oy)` growth offset. This is a **1-comparison filters/AVM1
  single**, plausibly cheap, and independent of everything above.

---

## 5. Canary sets

**For the §1.5 corner one-liner** (embedded-font EditText boxes; narrow):
`visual/edittext/edittext_border_transform` (all 6),
`visual/edittext/edittext_caret_empty` (all 12),
`visual/edittext/edittext_border_basic`, `_border_basic_scale2`,
`edittext_background_basic`, `_background_basic_scale2`, `edittext_gutter`,
`edittext_border_filters`, `edittext_device_transform_{basic,negative,small_shear,small_rotation}`
(the last is at 11/11 on its budget — check it explicitly),
`avm2/edittext_autosize_height_dynamic`, `visual/edittext/edittext_selection_leading`.

**For the §1.6 caret un-gate** (wide — every focused text field in the corpus):
the above **plus** `visual/focus_highlight/*`, `avm1/edittext_*`,
`avm2/edittext_always_show_selection`, `avm2/edittext_getcharboundaries`,
`visual/cache_as_bitmap/edittext_{scroll,hscroll,selection}` (`hscroll
[output.01]`'s golden already contains a **magenta caret bar** we do not draw —
this fix may move it), plus the full standing `render_canary_tests.txt`, plus
the trace-side stash-diff sweep including the `regression` suite.

**Standing CAB canary** (must stay `pass`, max_diff 0):
`visual/cache_as_bitmap/oversize/swf_9_too_big`, `…/swf_10_too_big`.

**Do NOT canary on** `cache_as_bitmap/masks`, `avm2/bitmapdata_draw_masks`,
`visual/avm2_button_scroll_rect` for anything AVM2-render-correctness shaped —
their excess rises when we get *more* correct (§3).

---

## 6. Verdict table

| claim | verdict |
|---|---|
| `caret_empty` regressed because the **device** box now draws its corner | **REFUTED** — the device box does not and must not draw it; the **embedded** box stopped drawing it |
| `line_rect = 0` in the `device_box` branch is the revert lever (−3 flips) | **CONFIRMED as costed, but wrong branch** — measured: breaks `border_transform .01/.03` and recovers nothing |
| A middle path exists that keeps the 3–4 flips *and* recovers `caret_empty` | **CONFIRMED** — `line_rect = 0` in the *embedded* branch; measured 84→48 with `border_transform .01/.02/.03/.05` still passing and `.04/.06` −1 outlier |
| `caret_empty` can be flipped (×12) | **CONFIRMED as reachable** — corner + un-gate the existing caret renderer + a caret index on Tab focus |
| `place_object_test` regressed from the phase fix | **REFUTED** — loop-phase revert is byte-identical |
| `place_object_test` regressed from the blend commit | **REFUTED** (my own first call) — enters at `98ba131be`, the w2-text vertex-budget raise |
| `place_object_test` is a keep-the-trade | **CONFIRMED** — the budget raise removed a silent truncation that was accidentally hiding our own excess ink |
| `cache_as_bitmap/masks` regressed from cxform composition | **CONFIRMED** — isolated to `avm2_display.c` by file-level revert |
| …and it is a bug | **REFUTED** — the cxform fix is correct; previously white-on-white shapes now render, and the missing AVM2 mask lets them spill |
| the cab slice is 7 comparisons needing a real cache | **PARTLY REFUTED** — 6 need AVM2 masks first; the 7th (`contains_grown_filter`) needs neither cache nor mask |
| the cab slice pairs with the Filters arc | **REFUTED** — it pairs with the AVM2 **mask/T7** arc |
| the cab slice needs an offscreen render target built from scratch | **REFUTED** — w2-blend already shipped the suspend/offscreen/resume/composite scaffold |
| land the size gates with the cache or `swf_{9,10}_too_big` regress | **CONFIRMED** — they pass today for the right reason; gate is ~6 lines |
