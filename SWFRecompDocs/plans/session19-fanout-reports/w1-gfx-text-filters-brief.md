# w1-gfx-text-filters: wave-1 pixel diagnosis of text, fonts, filters and colour

Read `BRIEFS_COMMON.md` and `SWFRecompDocs/plans/graphics-fanout-playbook.md` (§1-7 and §17) first.
This is read-only work with no source edits. Deliverable:
`SWFRecompDocs/plans/session19-fanout-reports/w1-gfx-text-filters-report.md`. Scratch dir: `<scratchpad>/w1-gfx-text-filters/`.

Same render rules as every pixel brief: CI PNGs under `<scratchpad>/image-results/` for verdicts,
local `--mode=graphics --images` only for A/Bs, and a throwaway worktree for any source prototype.

## Your board (playbook §17 leads; re-verify against the fresh board)
**Text / fonts:**
- **Device fonts have no outline source** (`abc_devicefont.cpp`). `stb_truetype` is already
  linked, so the arc is "emit contours". Size it: which comparisons need device-font outlines
  (`fonts/embed_matching/*` shows png_unavailable, so render those locally), and what is the
  smallest slice?
- `visual/text/auto_size/{height,return}`: 3 outliers from passing on a shared mechanism.
- `avm2/edittext_get_char_index_at_point` (22 849) and `avm2/edittext_get_line_index_at_point`
  (18 403), both same_geometry_wrong_fill.
- `from_shumway/acid/acid-text` (7 683), `acid-text-6` (12, near-pass), and `acid-text-4`/`acid-textfield`
  (row_banded, KF).
- `from_shumway/{hardwrap,stylesheet,flash_text_TextField}` missing_element (KF).
- `edittext_border_filters`: HOLD (an EditText is never drawn by `render_single_object`, so
  PlaceObject3 filters on a DefineEditText are a structural no-op). Price the completion.
- `fonts/glyph`'s last pixel is the libtess2-CDT-vs-lyon straight-edge tie. Price it or refute it.
- `from_gnash/misc-ming.all/morph_test1` ×6 is reportedly status-bar text ("- xtrace enabled").
  w1-gfx-geometry confirms it; you price the text side.

**Filters / colour / blend:**
- The AVM2 `.filters` loop gets compositeSource wrong AND drops a non-final compositeSource.
  Both are live defects found in s18 (`session18-fanout-reports/w2-gfx-filter-chain-report.md`).
  Which comparisons do they move?
- `from_shumway/acid/acid-color-0` (17 383), `avm2/bitmapdata_draw_filters` (global_color_shift, KF),
  `avm2/blend_shader_luma_lighten` (1 237, BACKEND), `avm2/displayobject_opaque_background`
  (localized_region), `from_shumway/captions`.
- The filters family residual is source-silhouette drift × kernel area (s18: arithmetically
  unflippable at max_outliers 0-18). Don't re-derive it; only say if something changed.

Siblings: w1-gfx-geometry (curves, strokes, fills, bitmaps, pixelSnapping), w1-gfx-stage3d,
w1-drift (geom_transform/displayobject_z/draw_cab_quality/copypixels), trace agents (w1-avm2 owns
the TRACE side of the textline/textblock tests).
