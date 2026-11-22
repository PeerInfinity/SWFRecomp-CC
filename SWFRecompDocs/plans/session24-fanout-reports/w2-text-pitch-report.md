# w2-text-pitch: AVM1 EditText leading + per-run face + Fixed8 colour, and the root static-text riders (session 24, wave 2)

**New files (both under `session24-fanout-reports/`):** `w2-text-pitch-report.md` (this file) and `w2-text-pitch.patch`
(`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`,
generated last and checked with `git apply --check -R`). There are no new source files and no new fixture directories.

**Base:** `origin/master` at `f450a4626`. **Environment:** cloud box, `SETUP_STATUS` all OK (apt, Pillow, Dawn on lavapipe).
Tests come from upstream Ruffle master **`bcac30c19`**, the same commit as the s24 baseline. Categories downloaded:
`text avm1 from_shumway visual fonts`, plus `avm2` so the full standing canary could run.

**CI fidelity:** the before-leg (clean `origin/master`) PNGs are md5-identical to CI's actual PNGs on `origin/ruffle-image-results`
(baseline run `44965247383`) for all three failing headline rows: `br_at_start` `80ac920dcef2`, `style_changes_in_html` `1dfafdb6079a`,
`static_text_offstage` `9ac5b7aa1346`. So every absolute number below is CI-grade.

---

## Verdict

**GO: land the patch.** It gives +2 pixel flips with 0 trace moves, and every other rendered row in two A/B sweeps is md5-identical.

### EXPECTED-FLIP LEDGER (coordinator: check CI against this)

| axis | test | before → after (CI-grade) | expected CI move |
|---|---|---|---|
| pixel | `text/br_at_start` | 1672 outliers (limit 8, tol 128, max 255) → **4** (max 160) | **fail → pass** |
| pixel | `text/style_changes_in_html` | 24998 (limit 0, tol 0, max 103) → **0 (max 0)** | **fail → pass** |
| pixel | `from_shumway/avm1/text-bind` | t128 **85/100**, t64 **587/600**, max 155 → t128 **85/100**, t64 **587/600**, max 155. 2984 channels move by exactly 1 (diff_channels vs golden 6618 → 6610) | stays pass. **Outliers unchanged** |
| pixel | `visual/static_text_offstage` | 16016 (tol 2, limit 0) → **9600** | stays fail (band moves; rider) |
| trace | none | 0 trace status moves in any leg, in either mode | none |

The `static_text_offstage` 9600 that remains is exactly the two 40×40 squares of defect (c), AVM1 `BitmapData.draw` of timeline
content. That belongs to the bitmap slot and is unchanged from the w1 report.

---

## What landed (patch scope)

### 1. Leading carried in twips (report §2a)

- `TFRun` (`action.c` ~22717) gains a trailing **`s32 leading_tw`**. The brief asked for `s16`; `s32` means `px*20` can never
  overflow, so this is strictly neutral against the old `leading * 20` int arithmetic. A helper `tf_set_run_leading_px(r, px)`
  writes `leading` and `leading_tw` together.
- Every producer fills it:
  - `tf_get_defaults` stores the tag's exact twips (`def->leading_tw = leading_twips`; 533 for `br_at_start`).
  - The `<textformat leading=…>` parse arm, and the two `setTextFormat` run-writer arms in `actionCallMethod`
    (~74543, ~74601), call `tf_set_run_leading_px`.
  - All other TFRun producers copy whole structs (`*r = fmt_stack[fmt_sp]`, `tmp_runs` memcpy) or start from `memset` plus
    `tf_get_defaults`, so the field follows. I audited every `TFRun` local and every `.leading =` site.
- Both `_tf_leading` sync sites (`tfRebuildFromHtml` and the `htmlText` setter) now read `(double)first_run->leading_tw`. The
  prototype's `tf_run_leading_twips` "equals the truncated default" re-derivation is gone.
- `htmlText` serialisation still emits whole-pixel `LEADING="26"`, which matches Flash's integer TextFormat.leading.

### 2. Per-run embedded face + Fixed8 glyph colour (report §2b), as measured

- `TextFieldGlyphRun` (`action.h`) gains a trailing `u16 font_id` (0 means the field's font).
- The run-table producer in `actionIterateTextFieldGlyphs` resolves a different embedded face with
  `ng_findEmbeddedFontId(font_name, bold, italic)`. This applies only to embedded fields (flag 0x80).
- `font_id = 0` is set in **every** producer that shares the static buffers:
  - the `tf_styled_runs_from_html` `EMIT_RUN` macro, which fills `_tfg_runs` and `_ss_tfg_runs`;
  - `_tfg_runs[ri]`, `_tfg_runs[0]` ×2;
  - `otf_html_runs[ri]`, `otf_html_runs[0]`.
- In `tag.c`'s `textfield_glyph_render_cb`, the measure and draw passes resolve the run face through the cached
  `TF_RESOLVE_RUN_FONT` (font index, em, glyph base; it falls back to the field font). Cleanup against the prototype: the run's
  `font_id` is captured as `cur_fid` in the same "run covers pos" block that already picks `cur_fh`/`cur_color`. This replaces
  the prototype's post-advance `pos > byte_start` re-test, and the semantics are equivalent.
- The glyph colour is quantised the way Ruffle's `Fixed8::from_f32(c/255)` is (`font_like.rs:98`).

### 3. Optional riders: both landed, md5-neutral on sweep 2

- **(b) Per-instance root glyph slots.** A new `static compose_root_text_instance()` in `tag.c` is called from both root
  compose loops, `tagRerenderFrame` (OFFSCREEN) and `tagShowFrame`. The prototype only patched `tagRerenderFrame`, so
  `tagShowFrame`, browser-WASM's frame path, kept the shared-slot collapse. The helper allocates `ch->text_size` dynamic slots
  per instance, the same scheme as `compose_children`, and records `text_glyph_xform_base` through `text_glyph_overrides_push`.
  When the pool is full it falls back to the old in-place `renderer_compose_text_transforms`.
- **(a) Root static-text bounds cull, grown by the filter extent.** The helper puts the instance's `ng_getCharBounds` rect
  through the placement matrix, then grows it by `filter_chain_reach_px(build_filter_chain(obj), vs=1) × 20` twips. This
  replaces the prototype's `filter_type == 0` exemption. If the rect misses `[0,W·20]×[0,H·20]`, the instance goes on
  `g_text_culled` and `render_single_object` skips it. The cull is skipped when `_root` carries an AS transform. The cyan
  drop-shadow text in `static_text_offstage` is still kept, and the PNG is md5-identical to the prototype's exempt version.
- The helper sits inside the existing `#ifndef NO_GRAPHICS` region (just before `tagRerenderFrame`'s `#ifdef OFFSCREEN_RENDER`),
  so the browser-WASM `tagShowFrame` call links. `tag.c` passes `gcc -fsyntax-only` under `-DUSE_WEBGPU -DOFFSCREEN_RENDER`,
  `-DUSE_WEBGPU` (the browser-WASM define set) and `-DNO_GRAPHICS`. I could not run a real Emscripten build here (no emsdk in
  the cloud), so the deploy-pages / WASM leg is unverified beyond that syntax check.

### Not landed (per brief item 4)

The `SWFRECOMP_JPEG3_DILATE` and `TF_CENTER_TW` env-gated experiments are stripped. The JPEG3 premultiply `swf.cpp` hunk is
not in this patch: it is the bitmap slot's, and `acid-color-0` is md5-identical here. No `SWFRecomp/` change, so
`--recompile` is not needed.

### Sibling overlap

`w2-textformat-ctor` edits TextFormat construction in `action.c` (getTextExtent, native super()). This patch's `action.c`
hunks are the `TFRun` typedef, `tf_get_defaults`, the `<textformat>` parse arm, the two `_tf_leading` sync sites, the glyph-run
producers, and two one-line `r->leading` → `tf_set_run_leading_px` swaps in the `setTextFormat` run writer (~74543/~74601).
None of them is a TextFormat constructor or getTextExtent. If the two patches collide textually at the setTextFormat lines,
the resolution is mechanical: keep `tf_set_run_leading_px(r, (s16)v)`.

---

## Evidence

### Sweep A (report sweeps 1 + 2 rebuilt): 52 tests / 75 comparisons, `render_canary.py` A/B, md5

The w1 sweep lists were not persisted, so I rebuilt them with a tag scanner over the downloaded corpus:
- every image-graded non-ABC SWF with DefineEditText or a `createTextField`/`htmlText`/`TextFormat`/`textColor` string
  (31 tests);
- every image-graded SWF with DefineText/DefineText2, ABC included, which is wider than w1's non-ABC sweep 2 because the root
  compose is shared;
- every image-graded SWF with DefineBitsJPEG3/4, and the `bevel*` rows (19 tests);
- plus `acid-textfield`, `acid-text-escape` and five `regression/` text rows.

The two lists overlap, and the union is 52 tests.

Result: **71 IDENTICAL, 4 DIFFER**: `br_at_start`, `style_changes_in_html`, `text-bind` (max 1) and `static_text_offstage`.
All four are in the ledger. There were no trace status changes. A re-capture after the final code move (helper relocated for
WASM) is md5-identical to the first after-leg (75/75).

The rows that differ from the w1 counts (45/17) are the `avm2`/`from_gnash` rows that w1 downloaded and this slot's
categories exclude. The standing canary below covers the avm2 members.

### Standing canary (`render_canary_tests.txt` incl. the two new members): 104 tests / 162 comparisons

**159 IDENTICAL, 3 DIFFER**: `text-bind` (max 1, pass→pass), `br_at_start` (fail→pass), `style_changes_in_html` (fail→pass).
There were **no trace status changes**.

### `regression` suite

- **Graphics** (in sweep A, before and after): `avm1_parent_child_text`, `avm2_parent_child_static_text`, `avm2_static_text`,
  `avm2_timeline_text` and `avm2_bitmapdata_draw_textfield` all pass and are md5-identical. The canary's 7 regression members
  are also identical.
- **No-graphics**: `avm1_parent_child_text` passes.

### No-graphics trace (the leading hunk is shared `action.c`)

I ran 42 tests: every `avm1` leading / `edittext_html_*` / textformat / default_format / margins / bullet / tab_stops /
`html_text_img*` / stylesheet row, plus `text/br_at_start`, `text/style_changes_in_html` and `regression/avm1_parent_child_text`.
**40 pass.** The 2 that fail, `avm1/text_format_get_text_extent_own` and `avm1/text_format_prototype_lazy`, also fail on clean
`origin/master`. Both are upstream-drift rows the baseline already grades failing, and both belong to `w2-textformat-ctor`.
Graphics-mode trace for the swept rows comes from the canary (no moves). No `swf_core.c`, `tag_stubs.c` or `#ifdef NO_GRAPHICS`
arm is touched, so the graphics leg is enough per policy.

### Per-test before/after table (clean origin/master vs this patch, same box)

| test | before | after | image status | trace |
|---|---|---|---|---|
| `text/br_at_start` | 1672 / 8 (max 255) | 4 / 8 (max 160) | fail → **pass** | pass → pass (both modes) |
| `text/style_changes_in_html` | 24998 / 0 (max 103) | 0 / 0 (max 0) | fail → **pass** | pass → pass (both modes) |
| `from_shumway/avm1/text-bind` | t128 85/100, t64 587/600, max 155 | t128 85/100, t64 587/600, max 155 | pass → pass | pass → pass |
| `visual/static_text_offstage` | 16016 / 0 (tol 2) | 9600 / 0 | fail → fail | pass → pass |
| `from_shumway/acid/acid-color-0` | md5-identical | | unchanged | unchanged |

---

## Not finished / completion mechanisms

1. **`static_text_offstage` flip:** defect (c), AVM1 `BitmapData.draw` ignoring source-MC timeline content
   (`rasterizeMovieClipToBitmap`). This is the bitmap slot's.
2. **Per-line max ascent/descent over mixed faces/sizes:** this is unpriced correctness and no graded row needs it.
   Completion: per-line `max(ascent)`/`max(descent)` over the runs, as in `layout.rs:495-508`.
3. **Caret and selection x-advance still use the field font:** the caret-offset and selection-rect loops in
   `textfield_glyph_render_cb` walk glyphs with `font_idx` / `info->font_height`, not the per-run face or size. This is
   pre-existing (they already ignored per-run size). It only matters for a focused or selected multi-face embedded field, and
   no graded row has one. Completion: reuse `cur_fid`/`TF_RESOLVE_RUN_FONT` in those two loops.
4. **WASM build not compiled here** (no emsdk in the cloud). The CI deploy-pages dry run, or the next Pages deploy, is the
   check. The syntax-only compile under the browser define set is clean.
5. **The cull is root-only**, as in the prototype. Nested static text, cacheAsBitmap and `draw()` viewports cull against their
   own render target in Ruffle; they are not handled.

## New unclaimed leads

- Caret/selection per-run face (item 3 above).
- `tagShowFrame` and `tagRerenderFrame` duplicate the whole root compose loop. This rider had to patch both, and the
  prototype missed one. A shared root-compose helper would stop that class of miss.

## LOCAL ORACLE REQUESTS

None.
