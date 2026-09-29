# w2-edittext-filters — session 21, wave 2 (cloud session): EditText through the filter pipeline

Cloud worker `w2-edittext-filters`, branch `fanout/edittext-filters`, based on master `730e5b22a`.
It continues the local WIP (`w2-edittext-filters-WIP.patch`, "p12") that stopped before its canary ran.

**Files delivered (all on the branch):**
- Source: `SWFModernRuntime/include/actionmodern/action.h`, `SWFModernRuntime/src/actionmodern/action.c`,
  `SWFModernRuntime/src/libswf/tag.c`, `ruffle-tests/render_canary_tests.txt` (EOF append). **No new source files.**
- `SWFRecompDocs/plans/session21-fanout-reports/w2-edittext-filters.patch` (**new file**), equal to
  `git diff origin/master -- SWFModernRuntime SWFRecomp ruffle-tests/render_canary_tests.txt`.
- `SWFRecompDocs/plans/session21-fanout-reports/w2-edittext-filters-report.md` (**new file**, this report).

---

## 0. Verdict

**GO. +6 pixel flips, 0 status regressions (pixel or trace), caret rows md5-identical.**

Measured in the cloud container (Dawn on mesa lavapipe, `--mode=graphics`). Before = clean master
`730e5b22a`; after = this patch. Numbers are outliers against each comparison's `test.toml` budget.
Every applicable check must pass (c61f6ebe5), and each of these comparisons has exactly one check.

| comparison | budget (tol / max_outliers) | before | WIP p12 | **after** |
|---|---|---:|---:|---:|
| `visual/cache_as_bitmap/edittext_hscroll` .01 | 0 / 0 | 96 fail | 0 | **0 PASS** |
| `visual/cache_as_bitmap/edittext_hscroll` .02 | 0 / 0 | 0 pass | 0 | 0 pass (md5-identical) |
| `visual/cache_as_bitmap/edittext_selection` .01 | 0 / 8 | 366 fail | 0 | **0 PASS** |
| `visual/cache_as_bitmap/edittext_selection` .02 | 0 / 8 | 315 fail | 0 | **0 PASS** |
| `visual/cache_as_bitmap/edittext_selection` .03 | 0 / 8 | 373 fail | 0 | **0 PASS** |
| `visual/edittext/edittext_border_filters` | 32 / 17 | 821 fail | 0 | **0 PASS** (max diff 32 = tolerance) |
| `visual/cache_as_bitmap/edittext_scroll` .01 | 0 / 5 | 566 fail | 719 (worse) | **0 PASS** |
| `visual/cache_as_bitmap/edittext_scroll` .02 | 0 / 5 | 570 fail | 717 (worse) | **6 fail** (2 pixels; see §3) |

- **Selection .02/.03 were not open.** The WIP status table gives p12 as 30 / 171 on those rows. In
  this container, p12 as delivered already scores 0 / 0, and master reproduces the local base
  (366/315/373, 96, 566/570, 821) to the digit. The 30 / 171 figures were most likely carried over
  from the WIP's `a1` column: p12 added the per-glyph whole-twip advance (§1.3), which is what
  closes those two rows.
- **edittext_scroll is no longer worse; it improves.** The WIP took it from 566/570 to 719/717.
  With this patch it goes to 0 / 6 (§3).
- The graded CI run should confirm the flips on CI's lavapipe. `border_filters` sits exactly at
  its tolerance (max diff 32, tolerance 32), and `edittext_scroll .02` misses by one aliased pixel.
  Both are **tier 2** canary members (§5).

---

## 1. Mechanism (patch scope)

The patch is runtime-only, graphics paths only (the one exception is §1.2's accessor).

### 1.1 Filtered root EditText rides `render_filtered_object` (the WIP route, verified, kept as is)

Ruffle treats a non-empty filter list as an implied cacheAsBitmap on any display object
(`display_object.rs recheck_cache_as_bitmap`). An EditText placed with PlaceObject3 filters
therefore renders its box and glyphs into the cache, and the filters run over that.

Our EditText paint is not a DisplayObject draw. It comes from the per-depth text iterators
(`tf_draw_at_root_depth`) or from the orphan walk. So `render_filtered_object` filtered an empty
layer: this is s18's "structural no-op" HOLD.

What the patch does:
- `tag_root_edittext_is_filtered(obj)` names the root entries that reach the filter branch.
  These are EditText entries with `filter_type != 0` that are not clip-depth and not Alpha/Erase.
- In both root loops (`tagShowFrame`, `tagRerenderFrame`), such an entry skips
  `tf_draw_at_root_depth`, and `otf_walk_dl` skips it.
- `render_filtered_root_entry` publishes the entry (`g_tf_filter_obj`/depth). While that is
  published, `render_single_object` paints that one field into whatever pass is current:
  - through the wrapper window (`tf_draw_at_root_depth`) if the field has a wrapper;
  - otherwise through `actionEmitOrphanRootTextField`, a single-entry version of the orphan walk.

  So the field lands in the offscreen capture, and again in the framebuffer for
  `draw_source_{before,after}`.

**Branch-order audit.** I checked the loop branches that run before the filter branch.

- `char_id == 0` never qualifies.
- A live setMask masker and an `as_hidden` entry both `continue` before the filter branch.
  Skipping `tf_draw_at_root_depth` for them is still safe: the text iterators themselves skip a
  live masker (`actionAvm1IsLiveMasker`) and an invisible wrapper (`!mc->visible`). Master
  therefore drew nothing for those entries either.
- A filtered EditText inside a sprite is unchanged: still drawn unfiltered by the REST pass.

### 1.2 Author-set vertical `TextField.scroll` is now rendered (new; fixes the edittext_scroll worsening)

Diagnosis is in §3. The pieces:

- `ng_get_textfield_view_scroll_lines(mc)` in `action.c` exports the existing
  `tf_view_scroll_lines`, which gives `scroll - 1` (0 for an unscrolled field). It is the vertical
  twin of `ng_get_textfield_view_hscroll_px`, and like that one it is compiled in all modes.
- In `textfield_glyph_render_cb`, a wrapper-backed field (`info->mc`) has its baseline raised by
  `hidden_lines × (font_height + leading)`. That is this layout's own newline pitch.
- Lines above the view are laid out but not drawn. The golden shows no descenders of line
  `scroll - 1` peeking under the top gutter.
- The caret and selection derive from `y_pos`, so they move with the text. For every field whose
  `scroll` is ≤ 1, the rendering is byte-identical.

### 1.3 Ruffle's per-glyph advance (the WIP's whole-twip rule, plus the device-font pixel rounding)

Ruffle `font_like.rs FontLike::evaluate` computes each glyph's advance as follows (verified
against upstream source):

- Every font: `Twips::new((advance * scale) as i32)`, i.e. truncated to a whole twip per glyph.
  The WIP had this part.
- `FontType::Device` only: additionally `round_to_pixel`, i.e. `f64::round` of the pixel value.
  This part is **new**.

An EditText without UseOutlines resolves to a device font (`edit_text.rs font_type()`).

- `TextFieldGlyphInfo` gains a trailing `int device_font`. The static-field wrapper path sets it
  from the DefineEditText flags (`!(flags & 0x0080)`), and so does the orphan path. Dynamic
  (`createTextField`) fields keep 0, i.e. the embedded-font rule. See lead L3.
- `tf_glyph_advance_twips(adv, scale, device_font)` is used at all four advance sites: the
  paragraph width (alignment), the caret offset, the selection box x, and the pen.

Measured effect of the rounding alone (a subset capture with vs without it, §4):
- `edittext_scroll` .01 154 → 0 and .02 145 → 6;
- the bevel/glow family's device-font labels, −723 each on four rows;
- `text-bind` −16;
- `String_path_variable_button` +3 (fail→fail, 999/12).

---

## 2. Canary (md5 bar)

`render_canary.py`, run over the WIP's 100-test list
(`w2-edittext-filters-WIP-canary-list.txt`, 163 comparisons) with `-P 2`. The before leg was
captured with `--recompile` on clean master. The after leg is runtime-only (no recompiler change).

**Result: IDENTICAL 128, DIFFERS 35, 0 appeared/vanished/no-render. Trace status changes: none.
Image status changes: exactly the 6 target flips.**

- **Caret rows:** `edittext_caret_empty` (12 comparisons) and `edittext_caret_multiline`
  (6 comparisons) are **md5-identical**. So are `edittext_border_transform` ×6,
  `fonts/device-font` and `fonts/leading_device_font`.
- **Determinism:** 14 tests were captured twice at the same SHA (a split before leg), and all
  14 were md5-identical.

Every one of the 35 differing comparisons is EditText text. There are four groups.

**Targets (8 comparisons):** see §0.

**Pass→pass, max diff falls (3 comparisons), all advance rule:**

| comparison | outliers | max diff |
|---|---|---|
| `avm1/edittext_tag_indent` | 0 → 0 | 64 → 1 |
| `visual/fonts/leading_define_font` | 0 → 0 | 64 → 31 |
| `visual/edittext/edittext_negative_bounds` | 0 → 0 | 64 → 64 (fewer diff channels) |

**Fail→fail, better (19 comparisons):**

| comparison | outliers before → after |
|---|---|
| gnash `Video-EmbedSquareTest` | 186 → 15 |
| gnash `morph_test1` frame2..6 (each) | 186 → 15 |
| gnash `place_object_test` | 42 873 → 41 844 |
| shumway `acid-text` | 5 307 → 5 022 |
| shumway `acid-text-escape` | 184 → 112 |
| shumway `text-bind` | 2 510 → 2 498 |
| `text/br_at_start` | 3 691 → 3 683 |
| `text/style_changes_in_html` | 25 102 → 25 024 |
| `filters/bevel` | 3 613 → 3 091 |
| `filters/bevel_full` | 1 881 → 1 158 |
| `filters/bevel_inner` | 1 741 → 1 018 |
| `filters/bevel_outer` | 2 173 → 1 450 |
| `filters/glow_with_alpha_strength` | 1 846 → 1 123 |
| `filters/drop_shadow`, `glow`, `glow_without_composite_source` (each) | −60 |

**Fail→fail, worse (5 comparisons), all small and far from their budgets:**

| comparison | outliers before → after | budget |
|---|---|---|
| gnash `BeginBitmapFill` | 900 → 936 | 100 |
| gnash `shape_test` | 16 047 → 16 068 | 0 |
| gnash `morph_test1` frame1 | 213 → 216 | 0 |
| shumway `acid-color-0` | 17 386 → 17 388 | 3 |
| `text/String_path_variable_button` | 996 → 999 | 12 |

Each worse row's diff bbox is a thin, text-height strip:

| comparison | bbox |
|---|---|
| gnash rows | (30..117, 2..11) status-bar text, and (40..90, 154..161) on `BeginBitmapFill` |
| `acid-color-0` | (549..692, 137..159), 14 channels |
| `String_path_variable_button` | (252..290, 129..136), 12 channels |

Mechanism: the advance rule moves a glyph by up to a pixel. These rows already fail by far more
than that, with glyph shapes that differ from Ruffle's (e.g. the gnash status-bar text), so the
move is noise on top of a much larger unrelated diff. No `max_diff` moved on any of them.

---

## 3. The edittext_scroll worsening, explained by mechanism

`visual/cache_as_bitmap/edittext_scroll` has no actions at all. It has one DefineEditText named
`text` ("Test text\nLine 2\nLine 3", multiline, UseOutlines off, so a device font), placed with a
PlaceObject3 DropShadow. `input.json` moves the mouse to (5, 5) and sends two wheel notches of −1.
The goldens show "Line 2" (.01) and "Line 3" (.02), each with a magenta shadow.

1. **Master draws neither the scroll nor the filter.** It shows "Test text" in both frames with no
   shadow: 566 / 570 outliers.
2. **The scroll state itself was already correct.** I instrumented `actionDispatchMouseWheel`.
   The wrapper exists and is hit at (5, 5), and `scroll` goes 1 → 2 → 3 with `maxscroll` = 3.
3. **The unfixed downstream defect: vertical `scroll` was never rendered.** `TextFieldGlyphInfo`
   carried `hscroll` (s21 w2-px-c) but nothing for vertical scroll. The glyph painter always drew
   from line 1. That holds for every AVM1 field, filter or no filter.
4. **Why p12 looked worse.** p12 routes the field through the filter correctly, so a magenta
   shadow now appears. But the shadow sits under the wrong (unscrolled) glyphs, so every shadow
   pixel is a new mismatch against a golden that has other glyphs there: 719 / 717.
   **So the WIP's worsening was a correct fix exposing an unfixed defect, not an error in the
   filter route.**
5. **Proof by completion.** Adding §1.2 alone takes the row to 292 / 253. Hiding the lines above
   the view takes it to 154 / 145. At that point the text and the shadow line up with the golden,
   and the residual is glyph x-positions. Adding the device-font pixel rounding (§1.3) gives
   **0 / 6**.
6. **The last 6 channels of .02** are 2 pixels at (29, 7) and (30, 8): one black glyph-edge pixel
   of "Line 3" and its shadow copy. This is at `quality = "low"` (aliased rasterization), so it is
   a single-sample coverage tie, not layout. It is not fixable within this family. Budget is 5;
   the row misses by 1.

---

## 4. Tests run

- **Canary:** §2.
  - Full before (100) and after2 (100) legs.
  - A 29-test subset capture ("exp") isolating the device-font rounding. Its PNGs are
    md5-identical to the final build's, which proves the final refactor (an explicit parameter
    instead of a file-static) is behavior-neutral.
- **Trace, `--mode=graphics`, final code:** results are identical to master in every row.
  - `avm1/edittext_scroll` 54/54, `avm1/edittext_hscroll` 27/27, `avm1/bitmap_filters` 548/548
  - `avm1/edittext_onscroller`: ruffle_matched 6/14 (same as master's `results_graphics.json`)
  - `text/links_in_scrolled_text` 1/1, `text/text_caret_placement_scroll` 108/108,
    `text/text_caret_placement_align` 248/248
- **No-graphics compile + trace (v1 of the patch):** `avm1/edittext_scroll` pass,
  `avm1/edittext_onscroller` ruffle_matched 6/14 (unchanged).
- **Regression suite (`--tests-dir=ruffle-tests/tests/swfs/regression`, graphics):**
  - `avm1_parent_child_text`, `avm1_parent_child_render`, `mask_nested_intersect`: pass, 0 outliers.
  - The canary also covered the six regression render rows: md5-identical.
- **Not run:** a CI images run. The flips are local lavapipe A/B only; never grade against a golden
  absolutely.

## 5. Canary coverage added

`render_canary_tests.txt` EOF append, **tier 2**:
- `visual/edittext/edittext_border_filters`: PO3 filter lists on DefineEditText, 6 placements,
  2 fields.
- `visual/cache_as_bitmap/edittext_scroll`: wheel-scrolled field + DropShadow, 2 comparisons.
  It is the only corpus image row with a vertically scrolled AVM1 field.

Promote both to tier 1 once a graded run confirms. `edittext_hscroll` and `edittext_selection`
are already members. Their s21 w2-px-c comments ("stays failing on the EditText DropShadow") are
now stale; I left the other agent's comment text alone.

---

## 6. New unclaimed leads

- **L1: filtered EditText inside a sprite.** `compose_children`/`render_display_list` still draw
  a nested filtered EditText unfiltered, through the REST window. It is the same mechanism one
  level down. No corpus row was identified; scan PlaceObject3-with-filters of an EditText char
  inside a DefineSprite.
- **L2: script-set `filters` on an AVM1 TextField.** This goes through `obj->filter_type` only if
  the AS setter writes the root entry. Not verified; no corpus row seen in the canary set.
- **L3: device-font rounding for dynamic fields.** `createTextField` fields (`ng_textfield_idx == -2`)
  keep `device_font = 0`. Ruffle keys this on `embedFonts == false`, which is the default for
  those fields. Wiring it means reading the AS `embedFonts` property in the wrapper path. It moves
  every `createTextField` text row, so it needs its own A/B.
- **L4: the vertical scroll pitch is `font_height + leading`.** That is exact for this painter's
  own layout, but this painter lays out only at hard newlines (no soft wrap). A word-wrapped field
  scrolled by script would scroll by the right pitch over the wrong line breaks. It is the same
  underlying gap as any wrapped-field render row.
- **L5: `edittext_scroll .02`, 1 over budget** on a single aliased glyph-edge pixel at low
  quality. Re-check on the graded CI run before spending anything.
