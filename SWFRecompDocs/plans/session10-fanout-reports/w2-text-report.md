# w2-text — AVM2 TextField box, selection, vertex budget, font fallback

Wave-2 implementation of the `gfx-text-phase` text slice (Briefs **W2-A** = T1+T2
and **W2-B** = T4+T5). Runtime-only, three files, no recompiler change.
Deliverable patch: `w2-text.patch` (663 lines, 3 files).

Worktree: `.claude/worktrees/agent-a7c61d3e3fe4e703d`. **No commits, no pushes.**
T3 (device-font glyph outlines) was explicitly NOT taken, per the brief.

---

## 1. Headline

| axis | before | after |
|---|---|---|
| image comparisons **fail → pass** | — | **14** |
| image comparisons improved but still failing | — | 4 |
| image comparisons regressed | — | **0** |
| canary comparisons unchanged (`IDENTICAL`) | — | 43 / 61 |
| trace status changes | — | **0 real** (3 explained below) |

The local before-leg reproduced the **CI image baseline outlier count exactly**
on all 23 in-scope comparisons (18335, 20015, 8436, 43095, 1440, 16497, 121914,
2269, 8652 …), so the after-leg numbers below are predictive of CI, not a local
grading.

---

## 2. Per-tranche ledger

### T1 — AVM2 TextField background + border  (`avm2_display.c`, `avm2_text.c`)

`avm2_render_text` now draws the box before the glyphs, mirroring Ruffle
`edit_text.rs:2704-2733` and choosing `draw_text_box` (:2930-2958) vs
`draw_device_text_box` (:2845-2910) on `is_device_font()`. New renderer-only
accessors `avm2_text_box_info` / `avm2_text_is_device_font` export the four
already-wired EditText fields.

Key implementation decisions (all Ruffle-sourced, all commented in the patch):

* **The box is emitted in STAGE twips through transform slot 0** (the
  recompiler's identity matrix, `swf.cpp:659`), *not* through the field's
  transform slot. Reason: Ruffle's border width is deliberately never
  transformed (`render/src/lines.rs`: *"the thickness and line caps should not
  be transformed"*). Rotation/shear still land because the four corner points
  are transformed by hand.
* **`EditTextPixelSnapping` (high quality) is ported verbatim** —
  `tx = trunc_to_pixel(tx + 2 twips)`, `a = round_ties_even(a - 0.35)` — with
  the two `x_snap`/`y_snap` predicates evaluated *before* either branch mutates
  `a..d` (Ruffle does the same; evaluating them lazily is a bug). Every
  box-bearing target test declares `quality = "high"`; the one `quality = "low"`
  test (`edittext_always_show_selection`) has no snapping-sensitive box.
* **Border footprint was measured off the expected PNGs, not derived.** A GPU
  1px line strip rasterises to crisp whole-pixel edges; for a `w x h` box at
  `(x,y)` the ink is rows `y` and `y+h` over columns `x..x+w`, and columns `x`
  and `x+w` over rows `y..y+h` — i.e. `w+1` by `h+1` including all four corners.
  My first attempt dropped the bottom-right corner (it is antialiased to
  `0x6F6F6F` in `edittext_selection_leading`, which read as "absent"); that cost
  exactly 14 outlier pixels on `edittext_autosize_height_dynamic` and the fix
  took it to 0. **Lesson: read the corner's actual value, not just "is it
  black".**
* **Ruffle's device-font transform cull is now implemented**
  (`edit_text.rs:2690-2702`): a device-font EditText is not rendered at all when
  `|b|,|c| >= 0.006` or `a <= 0` or `d <= 0`.

### T2 — selection highlight + inverted selected glyphs  (`avm2_text.c`)

* New `avm2_edittext_collect_selection` returns per-line selection rectangles in
  field-local twips, clipped to the line and covering the line's leading only
  when the selection continues past it (`edit_text.rs:1131-1196`). Colour is
  `BLACK` when focused, `GRAY` otherwise.
* `et_visible_selection` ports `visible_selection()` (`edit_text.rs:1059`):
  caret ⇒ needs focus + editable; range ⇒ needs focus **or**
  `alwaysShowSelection`. Focus is read through a new
  `avm2_display_object_has_focus()` exported from `avm2_display.c`.
* `avm2_edittext_collect_glyphs` now stamps selected glyphs `0xFFFFFF`
  (Ruffle pushes `ColorTransform::IDENTITY` over the selected run — *"Set text
  color to white"*, `:1259-1268`). Because this lives in the shared collector,
  the **CPU rasteriser gets the inverted glyphs for free**.
* Selection rects draw through the field's world-transform slot (they *are*
  transformed by the field matrix, unlike the border), between the box and the
  glyphs — Ruffle's exact paint order.

### T5 — dynamic vertex budget  (`render_webgpu.c`, `avm2_display.c`)

* `MAX_DYNAMIC_VERTICES` 32768 → **262144**, `MAX_DYNAMIC_RECTS` 1024 → **4096**.
  Cost: the dynamic vertex staging mirror and its GPU region grow 0.5 MB → 4 MB,
  colour region 16 KB → 64 KB. (`prev_dyn_vtx` is `__EMSCRIPTEN__`-only and
  grows likewise in the browser build.)
* `avm2_render_glyphs` batches a field's glyph triangles into **one
  `renderer_draw_tris` per colour run** instead of one per glyph. Identical
  vertices in identical order, so no pixel change for content that already fit;
  ~20× fewer rect slots and draw calls. Signature changed to take a pre-allocated
  `(xid, cxid)` pair; slot allocation was factored into `avm2_text_slots` and is
  still performed **only when there is something to draw**, so slot numbering is
  unchanged for all existing content (this is why 43 canary comparisons are
  byte-identical).

### T4 — embedded-font fallback chain  (`avm2_text.c`)

`resolve_font` now ports `FontMap::find` (`library.rs:761-830`) exactly:
exact → (bold XOR italic ? bold-italic, regular, the-other : (bold-italic only)
regular, then bold, then italic, then (regular only) bold-italic) → device.
Factored the exact probe into `find_embedded_font`; first table entry wins,
matching Ruffle's `or_insert` registration semantics.

---

## 3. Comparison ledger (local, before → after; before == CI baseline)

**Flipped to pass (14):**

| comparison | before | after |
|---|---|---|
| `avm2/edittext_autosize_height_dynamic` output | fail 16497 | **pass 0** |
| `visual/edittext/edittext_selection_font_size` output | fail 18175 | **pass 0** |
| `visual/edittext/edittext_selection_leading` output.01 | fail 18335 | **pass 0** |
| … output.02 | fail 18335 | **pass 0** |
| … output.03 | fail 20015 | **pass 0** |
| … output.04 | fail 21563 | **pass 0** |
| … output.05 | fail 18335 | **pass 0** |
| … output.06 | fail 18335 | **pass 0** |
| … output.07 | fail 20975 | **pass 0** |
| … output.08 | fail 22843 | **pass 0** |
| … output.09 | fail 18215 | **pass 36** (== its upstream `max_outliers`) |
| … output.10 | fail 18191 | **pass 0** |
| … output.11 | fail 19151 | **pass 36** (== its upstream `max_outliers`) |
| … output.12 | fail 20367 | **pass 0** |

`output.09` / `.11` land exactly on the upstream allowance carrying the note
*"White selected text should always be rendered on top"* — Ruffle's own
compositing imperfection, so 36 is the floor there, not a shortfall.

**Improved, still failing (4):**

| comparison | before | after | residual cause |
|---|---|---|---|
| `fonts/embed_matching/fallback_preferences` | 121914 | **62241** | all 20 rows now render (was 4.2); residual is glyph *raster weight* — our ink is uniformly ~25% heavier than Ruffle's in every row, including the four rows that were already correct before this patch. Tolerance is 3 / limit 0, so it needs the glyph-AA arc, not this one. |
| `visual/fonts/font_lookup_as3` | 43095 | **40584** | T4 half landed; the device-font half is T3. |
| `avm2/edittext_always_show_selection` | 1440, max 255 | **432, max 43** | selection now drawn; max_diff 255 → 43 means only sub-tolerance edge pixels remain. |
| `visual/edittext/edittext_gutter` | 8436 | **3576** | box now drawn; residual is glyph raster weight. |

**Regressions: none.** No comparison's outlier count increased anywhere.

---

## 4. Canary results

`render_canary.py` before/after over the **full standing
`render_canary_tests.txt` list plus the 14 text-slice targets/riders**
(34 tests, 61→64 PNGs):

```
IDENTICAL    43
DIFFERS      18      (all Text-family; 14 fail->pass, 4 improved)
APPEARED      3      VANISHED 0   NO_RENDER 0
```

**The vertex-cap raise changed nothing it should not have.** All 43
`IDENTICAL` comparisons cover shapes, masks, gradients, filters, blend modes,
bitmaps, morph, cacheAsBitmap, timeline and the AVM1 text path — i.e. every
family that shares the dynamic budget. A pure cap raise is inert for
<74-glyph content, and glyph batching preserved draw order, so no md5 moved
outside the text slice. Every one of the 18 `DIFFERS` is a test this patch was
meant to touch, and each was diffed and accounted for above.

**The 3 `APPEARED` are before-leg artefacts, not new renders:**

* `visual/edittext/edittext_background_basic` and `_scale2` — `compile_fail` in
  the before leg at 301.8 s / 302.6 s, i.e. the 300 s gcc timeout under an
  8-agent-shared machine (the known long-compile false-fail). Their after-leg
  outlier counts are **2269 and 8652 — byte-identical to the CI baseline**, so
  they are unchanged AVM1 tests, not regressions.
* `regression/avm2_timeline_gradients` — `NO_RESULT` in the before leg (runner
  exit != 0), `pass` / 0 outliers after. Same flake class.

**Trace canary:** every canary test `pass → pass`. Plus, run separately:

* regression suite text tests — `avm2_static_text`, `avm2_timeline_text`,
  `avm2_bitmapdata_draw_textfield`, `avm2_agi_shell`: **4/4 pass**.
* font-fallback risk set (T4 changes which face resolves, and face metrics feed
  `getLineMetrics` / `textWidth` / `getCharBoundaries`) —
  `fonts/embed_matching/no_font_found` **pass**, `avm2/edittext_getlinemetrics`
  **pass**, `avm2/edittext_format_empty_font` **pass**, `avm2/edittext_font_size`
  **pass**, `avm2/edittext_getcharboundaries` **pass**,
  `avm2/edittext_getcharboundaries_missing_embedded_font` **ruffle_matched** —
  which is its CI baseline status, not a regression (checked against
  `avm2/_results/results_graphics.json`).

---

## 5. Merge risks / notes for the integrator

1. **Transform slot 0 must be identity.** The box path draws through it, same as
   the session-9 focus highlight and the AVM1 textfield box. Verified: the
   recompiler emits the identity matrix at transform id 0 (`SWFRecomp/src/swf.cpp:659`).
2. **`avm2_render_glyphs` changed signature** (`const Mat*, double` →
   `uint32_t xid, uint32_t cxid`). Both call sites in `avm2_display.c` are
   updated. The `avm2_bitmap.c` CPU path does not call it.
3. **Memory:** +3.5 MB dynamic vertex staging + 3.5 MB GPU buffer per renderer
   context; in the browser build `prev_dyn_vtx` doubles that. If the AVM2 memory
   footprint arc cares, 262144 was chosen as the smallest power of two that fits
   `fallback_preferences`' ~200k-vertex page with headroom; the batching change
   is what makes the *rect* budget non-binding.
4. **Not done, deliberately (follow-ups):**
   * The CPU rasteriser (`avm2_bitmap.c` / `avm2_cpu_raster_text`) still draws
     neither the box nor the selection fill. It *does* get the inverted glyph
     colours for free. `visual/cache_as_bitmap/edittext_selection` (×3) is
     therefore `IDENTICAL` and still failing — one small port away.
   * No glyph mask. Ruffle clips glyphs and the selection to
     `bounds.grow_x(-GUTTER)`; we do not, so a selection wider than the field
     would bleed. No target test exercises it.
   * T3 (device-font outlines) untouched, per the brief.
5. **CI**: this is graphics-mode runtime code touching a path every graphics
   test exercises. Recommend `mode=graphics`, and an `images=true` baseline run
   to bank the 14 flips — expect the closeout to also show the four improved-but-
   failing comparisons moving.
