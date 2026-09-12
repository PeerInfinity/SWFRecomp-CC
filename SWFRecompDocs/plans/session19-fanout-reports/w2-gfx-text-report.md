# w2-gfx-text — wave-2 implementation: at-point probes, glyph offset order, auto_size border corner

Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a275fac2f5148a572` at `e36bca73e`.
No commits, no pushes. Scratch: `<scratchpad>/w2-gfx-text/`.

## 0. Deliverables

| patch | files touched | new files |
|---|---|---|
| `w2-gfx-text-1-atpoint.patch` | `SWFModernRuntime/src/avm2/avm2_text.c` | none |
| `w2-gfx-text-2-glyphorder.patch` | `SWFRecomp/src/abc/abc_timeline.cpp` | none |
| `w2-gfx-text-3-autosize.patch` | `SWFModernRuntime/src/avm2/avm2_display.c`, `ruffle-tests/render_canary_tests.txt` | none |

No new source files, so no `verify_output.py` / CMake / Emscripten source-list edits are needed.
The three patches are disjoint by file and apply in any order.
`-3` also adds ONE line (plus its comment block) to the standing render-canary set — see §5.

## 1. Verdict board

| # | verdict | comparison | before | after | limit |
|---|---|---|---:|---:|---:|
| **G1** | **GO, landed, +2** | `avm2/edittext_get_line_index_at_point` | 18 403 | **0 PASS** | 0 |
| | | `avm2/edittext_get_char_index_at_point` | 22 849 | **0 PASS** | 0 |
| **G2** | **GO, landed, +1** | `avm1/define_font_glyph_table_order` | 180 | **0 PASS** | 4 |
| | A/B (required) | `avm1/define_font_glyph_table_overlap` | 0 PASS | **0 PASS** (byte-identical) | 4 |
| **G3** | **GO, landed, +2** | `text/auto_size/height` | 6 | **3 PASS** | 3 |
| | | `text/auto_size/return` | 21 | **6 PASS** | 18 |
| | A/B (required) | `text/auto_size/width` | 0 PASS | **0 PASS** (byte-identical) | 18 |

**+5 pixel flips, as priced.** Every "before" number reproduced the CI baseline
(`34645805030`) EXACTLY on local Dawn — 18 403 / 22 849 / 180 / 6 / 21 / 0 — so local render is
not a confound for this family.

**Three of the brief's mechanism claims were incomplete or backwards** (§2.1, §4). The flip count
survived; the LOC estimate did not (~20 priced, ~85 delivered).

---

## 2. G1 (+2) — the at-point probes, and THREE defects the diagnosis missed

The w1 report's leading claim is correct but is **one of four** defects. Adding only `+ leading`
takes the line map from 18 403 to 8 148 and the char map from 22 849 to 17 464 — both still FAIL.

### 2.1 Refutations

**(a) `getLineIndexAtPoint` also omits Flash's +1 px x translation.** Ruffle applies it in BOTH
bindings (`avm2/globals/flash/text/text_field.rs:1610` and **`:1633`** — "No idea why FP does this
weird 1px translation..."); we applied it only in the char probe. It shifts the x bounds test, so
every field gets a **full-height 1-px column band at each of its left and right edges**. In the
baseline line map those are columns 11, 108, 123, 220, 235, 332 carrying 288/288/238/238/251/251
differing pixels — **~1 554 of the 8 466, i.e. 18 %, and the ONLY column-shaped error in the map**.
The w1 report's "no column-only diffs at all" was measured on the CHAR map, which already had the
+1; it does not transfer. Confirmed against the golden: t1 (x = 10, w = 100) has its first coloured
column at stage x = 11 (local x = 1 = `bounds.x_min + GUTTER - 1`), not 12.

**(b) `+ leading` on a LINEAR scan is not Ruffle's answer.** Ruffle runs the comparator through
Rust's `slice::binary_search_by`, and `bounds.extent_y() + leading <= y` is **non-monotonic** as soon
as a line carries negative or shrinking leading — its band can end before the next line begins, or
overlap it. The probe *sequence* is then observable. After (a) + leading the line map still had
3 492 differing pixels, and **100 % of them sat in exactly three fields**: t1
(`<textformat leading='-10'>`), t7 (`leading='-70'`) and t10 (`leading='0'`, then 5, then 15).
Worked example, t1 (layout px): lines L0(0,20,+2) L1(22,30,+2) L2(54,20,+2) L3(64,20,+2); at y = 70
a linear scan returns 2 (L2's band reaches 76), while Rust's binary search probes mid = 2 (Equal),
then mid = 3 (Equal) and returns **3** — which is what the golden shows. Same for t7 (the search
**skips line 1 entirely**, golden goes line 0 → line 2) and t10 (line 0/1 boundary at layout 20, not
22). Porting `core::slice::binary_search_by` verbatim into `et_line_at_y` took the line map to
**0 outliers**.
*Corollary:* this also refutes a tempting read of the same data — that our `LLine.leading` is wrong
because it `max()`es in the trailing newline's span. It is not; our `lc_newspan`/`lc_newline` are
already `newspan`/`newline` verbatim. The residual was the search, not the datum.

**(c) The char probe is missing the justified-space stretch rule.** `LayoutLine::char_x_bounds`
(`html/layout.rs:1052`) extends a **box-final** char's x bounds to the next box's start, "because
the character is stretched" in justified text. `txt_get_char_boundaries` already implements this
(it has the identical `box->end == index + 1` block); the at-point loop did not. After (a) + (b) the
char map's last 6 336 outliers were **entirely in t13**, `<p align='justify'>a a a aaaa</p>`, where
we returned −1 for both stretched SPACE characters. With the rule: **0 outliers**.

### 2.2 Patch scope (`-1`, avm2_text.c, +82/−44)

* New `et_line_index_at_point()` — the bounds test + layout-y mapping + line pick, shared by both
  probes exactly as Ruffle's `char_index_at_point` **delegates** to `line_index_at_point`
  (`edit_text.rs:2351`). This is also what gives the char probe the vertical scroll term it lacked
  (the second w1 defect, t9's `scrollV = 3`).
* `txt_get_line_index_at_point` gains `+ 1.0` on x.
* `et_line_at_y` becomes the verbatim binary search (new helper `et_line_cmp_y`). It is also used by
  `avm2_text_index_at_local` (mouse caret placement), where Ruffle calls the same
  `find_line_index_by_y` (`edit_text.rs:1609`) — so that path gets the same correction. For
  `line_count <= 1` the new code is provably identical to the old scan.
* The char loop gains the justified-stretch clause.

### 2.3 Tests run (all AFTER; the family passes in the trace baseline, so PASS = no regression)

`edittext_at_point_methods_basic`, `edittext_get_line_index_of_char`,
`edittext_autosize_lazy_bounds_{props,vs_relayout}`, `edittext_autosize_height_dynamic` (image, 0/0),
`edittext_leading`, `edittext_line_methods`, `edittext_line_metrics`, `edittext_getlinemetrics`,
`edittext_mouse_selection`, `edittext_focus_selection`, `edittext_selected_text`,
`edittext_getcharboundaries`, `edittext_getcharboundaries_scroll`, `edittext_bullet`,
`edittext_align`, `edittext_scrollh`, `edittext_bottom_scroll_v_basic`, `edittext_input_control`,
`edittext_paragraph_methods`, `edittext_tag_indent` (image, 0/0) — **20/20 PASS**, plus the two
headliners. Five of these were also captured BEFORE and are unchanged.

---

## 3. G2 (+1) — the glyph offset table is not required to be sorted

`abc_timeline.cpp:1532` took `g1 = glyph_offsets[i + 1]` and `continue`d when `g1 <= g0`, dropping
glyphs 0 and 2 of the deliberately out-of-order table `[29, 10, 64, 48]`. Ruffle seeks to each
offset with no end bound at all (`swf/src/read.rs:1050`), and `parseGlyphShape` already stops at the
EndShapeRecord, so `g1` is only a safety bound.

**Patch (`-2`, +37/−4):** compute `offsets_sorted` once; when sorted, the expression is *literally*
the old one (so the blast radius outside out-of-order fonts is nil **by construction**, not by
testing); otherwise `g1` = the smallest offset strictly greater than `g0`, falling back to
`code_table_off` / the tag end. Kept O(n²) only on the unsorted branch.

**Corpus rescan (independent re-verification of the w1 claim).** Ran `fontorder.py` over **3 155
SWFs** — every `*.swf` under avm1, avm2, visual, text, fonts, from_shumway, from_gnash, timeline,
swf, mixed_avm, regression, stage3d, audio, import_assets (the w1 scan covered 2 848). Exactly
**two** carry a non-monotonic table: `define_font_glyph_table_order` and
`define_font_glyph_table_overlap`. (Note the w1 report calls the second one
`define_font_glyph_table_order_overlap`; the directory is `define_font_glyph_table_overlap`.)

**The required `_overlap` A/B passes byte-identically** (0 outliers, max difference 0) even though
its offsets `[10, 29, 29, 29]` now make glyphs 1 and 2 parse where they were previously skipped —
they resolve to the same shape, which is what Ruffle renders too.

**Font-family canaries** (all with `--recompile` against the rebuilt recompiler):
`visual/fonts/{advance_u16,leading_define_font,leading_embedded_font,duplicate_font}` PASS,
`fonts/device_font_kerning` PASS 0/0, `avm2/{font_hasglyphs,font_embedded,font_enumeratefonts}` PASS,
`avm1/device_font_spacing` PASS. `visual/fonts/glyph` is 3/0 — its standing baseline (w1 §9, s18),
unchanged. `fonts/embed_name_lookup` still MISMATCHes; it is a baseline failure
(inventory: `86/242`) and its SWF has a sorted table, so G2 provably cannot touch it — no BEFORE leg
was run for it. `fonts/embed_matching` is a *directory of sub-tests*, not a test; my invocation was
wrong, not the code (`SWF file 'test.swf' not found`).

---

## 4. G3 (+2) — the border-corner rule was BACKWARDS, and it is a quality-dependent rule

### 4.1 Two refutations before the fix

* **`text/auto_size/width` does NOT "pass at exactly its 18-outlier limit".** It passes at
  **0 of 18** — full headroom. (Verified locally and in the baseline image JSON.)
* **The existing `frac_bottom` heuristic is not merely "unmeasured for fractional width"; it is
  inverted.** I instrumented `avm2_render_textbox` to dump every box's geometry. Writing
  `f = frac(by + bh)` in device pixels:

  | comparison | box (px) | f | golden BR corner | old code | new code |
  |---|---|---:|---|---|---|
  | `auto_size/height` | 250 × 204 @ (25,25) | 0 | **missing** | drawn ✗ | missing ✓ |
  | `auto_size/return` #1 | 75 × 103 @ (25,25) | 0 | **missing** | drawn ✗ | missing ✓ |
  | `auto_size/return` #2 | 75 × 103 @ (200,25) | 0 | **missing** | drawn ✗ | missing ✓ |
  | `auto_size/return` #3 | 75 × 29.25 @ (375,25) | 0.25 | **present** | missing ✗ | present ✓ |
  | `auto_size/return` #4 | 150 × 75 @ (25,200) | 0 | **missing** | drawn ✗ | missing ✓ |
  | `auto_size/return` #5 | 150 × 75 @ (200,200) | 0 | **missing** | drawn ✗ | missing ✓ |
  | `auto_size/width` ×6 | 210 × 77.75 @ (30,30)… | 0.75 | **missing** | missing ✓ | missing ✓ |

  So the corner survives only for **f in (0, 0.5)** — not "whenever the extent is fractional".
  That is the hardware line rule at the shared BR vertex: the right edge's segment ENDS inside that
  pixel without leaving its diamond, so the pixel is inked only when the bottom edge's segment
  leaves the diamond on its way left, i.e. only when the bottom edge passes strictly BELOW the
  pixel centre. All seven rows above were read directly off the goldens' bottom-row and
  right-column runs, not inferred.

### 4.2 Patch scope (`-3`, avm2_display.c +24/−17, plus the canary list)

`frac_bottom` → `corner_missing`, computed by the measured rule **inside `#if MSAA_SAMPLES == 1`
only**. On an MSAA build the old expression is kept verbatim, because there both antialiased
segments cover the corner — that is what `avm2/edittext_autosize_height_dynamic` (quality = high,
36 × 44 at the origin, all four corners inked) pins, and it stays byte-identical. Since
`verify_output.py::get_msaa_samples` maps `quality = "low"` → 1 and everything else → 4, this makes
the change an exact `StageQuality::Low` predicate: **no default-quality field can move.** The stale
paragraph of the old comment (which claimed the "all four corners" reading fails on fractional
boxes) is rewritten.

Residuals after the fix are glyph pixels only: `height` 1 px (limit 1), `return` 3 px (limit 6).

### 4.3 Tests run

`text/auto_size/{height,return,width}` (above), and the `visual/edittext` family:
`edittext_border_basic`, `edittext_border_basic_scale2`, `edittext_background_basic`,
`edittext_background_basic_scale2`, `edittext_bounds_vs_position`, `edittext_justify`,
`edittext_negative_bounds`, `edittext_selection_font_size`, `edittext_selection_leading` (12 cmps),
`edittext_underline` (12/16), `edittext_underline_scale2` (12/16), `edittext_device_transform_basic`,
`edittext_device_transform_metrics` (ruffle_matched) — **all at their baseline numbers**.
`edittext_border_transform` reproduces the baseline exactly (01/02/03/05 PASS 0, **04 = 51/20 and
06 = 44/20 FAIL — identical to the baseline JSON**). `edittext_gutter` 1032/0 — baseline.

---

## 5. Canary audit and the covering member

The standing set's only EditText-border member, `visual/edittext/edittext_border_transform`, is
`quality = "high"` → MSAA_SAMPLES 4 → it exercises the arm G3 does **not** change. The set therefore
could not see G3 at all. Per the wave-2 rule I added a covering member to
`ruffle-tests/render_canary_tests.txt` (in patch `-3`): **`text/auto_size/width`** — six autosized
210 × 77.75 bordered fields at `quality = "low"`, CI-PASSING at 0 of 18 outliers, i.e. a tier-1
member with an absolute verdict and full headroom.

**Canary result (`render_canary.py capture before|after` + `compare`, `-P 2 --recompile
--timeout 5400`, 30 tests / 62 comparisons, both legs in this worktree):**

```
  IDENTICAL    62
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

The BEFORE leg reverted all three patches **and rebuilt the recompiler** (mode 1: a `SWFRecomp/`
change needs both `--recompile` and a rebuilt binary, else the leg is stale-cache fiction). Both
legs carry the new member, so `text/auto_size/width` is byte-identical across the A/B — which is
also what the rule predicts (its `f = 0.75` lands on `corner_missing` in both the old and the new
expression).

**Regression suite** (`--tests-dir=ruffle-tests/tests/swfs/regression --mode=graphics --recompile`):
`avm1_parent_child_text`, `avm2_bitmapdata_draw_textfield`, `avm2_parent_child_static_text`,
`avm2_static_text`, `avm2_timeline_text`, `avm2_timeline_gradients`,
`avm2_timeline_stroke_gradient`, `mask_sibling_union`, `mask_nested_intersect`, `avm2_morph` —
**10/10 PASS** (`avm2_morph`'s image SKIPs, as it always does: no expected PNG).

**Final combined-state confirmation** (all three patches applied, recompiler rebuilt, every test
`--recompile`d): line-index 0/0 PASS, char-index 0/0 PASS, glyph-order 0/4 PASS, glyph-overlap 0/4
PASS, `auto_size/height` 3/3 PASS, `auto_size/return` 6/18 PASS, `auto_size/width` 0/18 PASS.

### 5.1 TEXTUAL CONFLICT WARNING for the coordinator

`ruffle-tests/render_canary_tests.txt` **already carries uncommitted session-19 additions from the
sibling `w2-gfx-geometry`** in the main tree (five members: `avm2/graphics_bitmaps`,
`from_shumway/acid/acid-small`, `avm2/displayobject_getbounds_shape`,
`avm2/graphics_simple_shapes`, `visual/simple_shapes/layers`, under a "SESSION 19 ADDITIONS" header).
My hunk inserts at the END of the tier-1 block (original line ~97); theirs APPENDS after the
original line 122. The two hunks are ~24 lines apart, well beyond `git apply`'s 3-line context, so
both apply cleanly in either order — but stage the file once, with both, and do not let one patch
overwrite the other.

---

## 6. New unclaimed leads

1. **`visual/edittext/edittext_caret_empty` is failing 11 of its 12 comparisons locally
   (36 outliers each, max difference 95) and the s18 image JSON records 12/12 PASS.** I A/B'd it
   with all three patches reverted: **byte-identical**, so this is NOT mine. The diff is the twelve
   fields' **bottom-right border corners**: the golden has an antialiased grey `(95,95,95)`, we
   paint solid `(0,0,0)`. Mechanism: on the MSAA arm we emit the border as four solid
   `avm2_border_rect`s, so the corner gets full coverage where Ruffle's antialiased `line_rect`
   leaves ~63 %. Either upstream drift since s18's run `33945288707` or a regression from a later
   session — worth a `corpus_status_diff` read. A principled fix is to give the MSAA arm a
   partial-coverage corner rather than a solid one.
2. **`visual/edittext/edittext_caret_multiline` is absent from the s18 image JSON entirely** (new
   upstream test). It renders 6 comparisons locally, all FAIL at 60 outliers / max 255. Unclaimed.
3. **The `+1 px` x translation and the `find_line_index_by_y` binary search are AVM2-only here.**
   If the AVM1 route has an at-point/caret equivalent (`tag.c` / `action.c`), it will carry the same
   two defects; nothing in the corpus currently grades it.
4. **`txt_get_char_boundaries` approximates Ruffle's justified stretch as `next_box->x`**, whereas
   Ruffle uses `next_box.char_x_bounds(position + 1).0`. Identical whenever the next box starts at
   `position + 1` (always, in practice). I kept the approximation in the at-point loop for
   consistency; a corpus case that separates them has not been found.

---

## 7. Reproduction

```bash
S=<scratchpad>/w2-gfx-text
export SWFRECOMP_COMPILE_TIMEOUT=2400 DAWN_INSTALL=~/CC/dawn-install
$S/run.sh avm2 edittext_get_line_index_at_point after --images --image-out-dir=$S/imgs
$S/run.sh avm1 define_font_glyph_table_order g2after --images --image-out-dir=$S/imgs --recompile
$S/run.sh text auto_size/return g3after --images --image-out-dir=$S/imgs
python3 $S/cmp2.py  exp.png act.png     # per-field residual, line-index map
python3 $S/cmp3.py  exp.png act.png     # per-field residual, char-index map (2x render)
python3 $S/trans.py exp.png act.png OX OY W H COL   # per-column line-index transitions
python3 $S/edges.py exp.png act.png X Y W H ...     # border bottom-row / right-col runs
python3 $S/pix.py   exp.png act.png     # every differing pixel + ASCII context
bash $S/scan.sh                         # non-monotonic glyph offset tables, 3155 SWFs
```
Temporary instrumentation used for §4.1 (a `SWF_BORDER_DEBUG=<file>` dump of every box's
`bx/by/bw/bh/dtw/dsc`) was removed before the patch was cut; `git diff` carries no debug code.
