# s26 wave 2 — `w2-text-cx-jpeg3` report (acid-color-0 chain steps 1–2)

**New files** (all in this commit):
- `SWFRecompDocs/plans/session26-fanout-reports/w2-text-cx-jpeg3-report.md` (this report)
- `SWFRecompDocs/plans/session26-fanout-reports/w2-text-cx-jpeg3.patch` (the deliverable patch, `git apply --check -R` verified)
- `SWFRecompDocs/plans/session26-fanout-reports/w2-text-cx-jpeg3-sweep.txt` (the 166-test A/B list)
- `SWFRecompDocs/plans/session26-fanout-reports/w2-text-cx-jpeg3-fixtures/*.png` (OUR renders of the new fixtures and acid-color-0, before/after; reference only, not goldens)
- `ruffle-tests/tests/swfs/regression/avm1_edittext_placed_cxform/{create_test_swf.py,test.swf,test.toml,output.txt}`
- `ruffle-tests/tests/swfs/regression/avm1_edittext_placed_cxform_script/{README.md,test.swf,test.toml,output.txt}`
- `ruffle-tests/tests/swfs/regression/avm1_jpeg3_alpha_bitmap/{create_test_swf.py,test.swf,test.toml,output.txt}`

Box: cloud, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Base `origin/master` = `b4a81ebf3`. Upstream corpus
downloaded from Ruffle master; my blobless Ruffle clone taken minutes later is at **`3e98d9ba6`**.
**Fidelity:** my clean-master render of `acid-color-0` is md5 **`f97ed470…`**, byte-identical to CI's actual PNG on
`origin/ruffle-image-results`; the before-count (17 315) matches the baseline exactly. Local grading is CI-grade for this row.

## Verdicts

| # | item | verdict | measured (`from_shumway/acid/acid-color-0`, tol 3 / limit 3) |
|---|---|---|---|
| 1 | Colour transform on AVM1/timeline EditText (box, border, text, run colours; field + every ancestor) | **LANDED (GO, correctness, game-visible)** | 17 315 → **677** |
| 2 | DefineBitsJPEG3/4 colour is premultiplied: clamp to alpha + un-premultiply at emit | **LANDED (GO, Flash-correct)** | 677 → **314** |
| 3 | Premultiplied texture sampling for timeline bitmaps (renderer-wide) | **PRICED, NOT LANDED** (needs renderer-wide sweep) | stand-in measured 314 → **116** |
| 4 | Integer-twip centring (`misalignment / 2` on Twips) | **PRICED, NOT LANDED** (touches every centred field) | 314 → **308** (−6) |

**No flip is expected and none is claimed.** acid-color-0 stays a band: 17 315 → 314 is −98 %, limit 3. Floor with
steps 3+4 is ≈110. The 0 → +0 flip is the point of the brief ("correctness work"): a tinted EditText was drawn
untinted in every AVM1 game. That is a common Flash idiom (a coloured HUD, a fading/tinted score box).

## 1. Step 1: EditText colour transform (`action.c`, `tag.c`, `swf.c`, `action.h`)

**Mechanism.** `TextFieldRenderInfo` and `TextFieldGlyphInfo` carry literal 24-bit RGB. `textfield_render_cb` and
`textfield_glyph_render_cb` (`tag.c`) draw with cxform slot 0. So no PlaceObject CXFORM and no `Color` override
on the field or any ancestor ever reached the text. This is the s23 diagnosis, unchanged.

**Fix (the s23 prototype ported, with its hacks removed):**
- `action.c` new statics next to `actionHasTextFieldAtDepth`: `tf_entry_cx`, `tf_cx_push_entry`, `tf_cx_reset`,
  `tf_cx_for_mc`, `tf_cx_rgb`, plus the exported `actionTextFieldCxSetApp`. They compose the RGB diag mult + add of
  the field's own display entry and every ancestor's, outermost first. Each entry contributes its runtime override
  (`cx_overridden` → `cx_*`) or its baked PlaceObject slot.
- They are applied on the CPU in `actionIterateTextFields` (background, border), `actionIterateTextFieldGlyphs`
  (text colour, run colours: both single-run arms and the run table), `otf_emit_textfield` (the same four), and
  `otf_walk_dl`. The orphan walk carries the running cx down the sprite recursion with save/restore
  (`OTF_CX_SAVE/RESTORE`) and includes the field entry's OWN cx. `actionIterateOrphanTextFields` and
  `actionEmitOrphanRootTextField` (the filtered-root route) reset around their walk.
- **Not the prototype's `g_proto_tf_app` hack.** `swfStart` (`swf.c`, one line after the `cxform_data` copy) calls
  `actionTextFieldCxSetApp(app_context)`. The table is read through `app_context->cxform_data`, which is the
  combined table once a child movie is linked.
- **Slot correctness fix over the prototype.** `compose_children` re-points `obj->cxform_id` to an INHERITED parent
  slot or a minted GPU-only slot while the tick's overrides are live, and the per-depth text window runs inside that
  render walk. Reading `obj->cxform_id` there would apply a parent's cx twice, or silently drop it (slot ≥ baked).
  New `tag.c` export **`tag_entry_baked_cxform_id`**, a wrapper over the existing static `cxform_original_id`,
  returns the entry's own baked id. It is self-localized: a new function placed after `cxform_original_id`, with
  no other `tag.c` line touched.
- **Alpha is deliberately untouched.** `_alpha` / cx alpha already reach text by the existing group-alpha routes.
  Folding alpha here would apply it twice.
- Filter interaction checked: `render_filtered_core` applies `obj_cx` only to the filter's own colours (shadow /
  glow / bevel). It does not apply it to the source content, so the source must carry the cx itself. The sweep below
  includes every filters × EditText row (bevel*, glow*, drop_shadow, edittext_border_filters): all md5-identical.
- NO_GRAPHICS: the helpers sit under `#ifndef NO_GRAPHICS` with an identity stub for `tf_cx_for_mc`, and
  `tf_cx_rgb` is identity when nothing is composed. Verified: the no-graphics build compiles and passes
  (`regression/avm1_edittext_placed_cxform_script`, `avm2/bitmapdata_constructor_from_timeline`). No
  `swf_core.c` / `tag_stubs.c` change.

Functions touched, for `n-pixel-pass` / sibling collision checks:
- `action.c`: `actionIterateTextFields`, `actionIterateTextFieldGlyphs`, `otf_emit_textfield`, `otf_walk_dl`,
  `actionIterateOrphanTextFields`, `actionEmitOrphanRootTextField`, plus the new statics above.
- `tag.c`: new `tag_entry_baked_cxform_id` only.
- `swf.c`: `swfStart`, one line.
- `rasterizeMovieClipToBitmap` (w2-tail-bitmap-draw's) is **not touched**. Note: AVM1 `BitmapData.draw` of an
  EditText under a cx does not go through these iterators. That is a lead, below.

## 2. Step 2: JPEG3/4 un-premultiply at emit (`SWFRecomp/src/swf.cpp`, DefineBitsJPEG3/4 arm)

DefineBitsJPEG3/4 with a JPEG alpha plane carries **premultiplied** colour. Ruffle (`render/src/utils.rs`
`decode_define_bits_jpeg`, re-read at `3e98d9ba6`) clamps each channel to alpha ("Flash Player clamps color to the
alpha value") and hands the renderer premultiplied RGBA. Our AVM1/timeline bitmap table is STRAIGHT alpha (the
renderer premultiplies), so the raw JPEG colour was premultiplied twice. The fix clamps to `a`, maps `a == 0` to 0,
and for `0 < a < 255` sets `c = (c*255 + a/2)/a`. That is the s24 formula; the s24 `SWFRECOMP_JPEG3_DILATE`
experiment is NOT included.

Only the `have_alpha` (true-JPEG content) branch changes. PNG/GIF-in-JPEG3 and DefineBitsJPEG2 are untouched.
The **AVM2** symbol-bitmap path (`avm2_bitmap.c` `bd_seed_embedded`, `Avm2MovieTables`) is a separate table that is
already treated as premultiplied. It is unaffected. That is why the AVM2 JPEG3 rows below are md5-identical even
though their timeline bitmap table changed.

**Generated-code A/B (recompiler change, done first).** A tag scan of every downloaded SWF (all categories except
`from_avmplus`, plus `regression`) finds DefineBitsJPEG3/4: 8 SWFs, 7 of them with a JPEG alpha plane (all with
partial alpha). The recompiler before vs after on each:

| SWF | DefineBitsJPEG3/4 alpha | files changed in generated code |
|---|---|---|
| `avm1/clone_sprite_types` | no alpha plane | **0** (byte-identical) |
| `avm2/bitmapdata_constructor_from_timeline` | 1 873 partial | 1 (bitmap table only) |
| `avm2/pixelbender_dithering` | 698 partial | 1 (bitmap table only) |
| `from_shumway/acid/acid-color-0` | 19 284 partial | 1 (bitmap table only) |
| `from_shumway/bitmapbuttons` | 13 188 partial | 1 (bitmap table only) |
| `from_shumway/avm2/flash/display/bitmapdata/bitmapdata-clone` | 2 206 partial | 1 (bitmap table only) |
| `from_shumway/avm1/mouse-transparency` | 2 206 partial | 1 (bitmap table only) |
| `from_shumway/as3-loader/events/loader-events` (`child.swf`) | partial | (child; covered by the run below) |

Every other SWF has no JPEG3/4 tag, so its generated code is byte-identical by construction: the only edited
branch is inside that tag's arm.

## 3. A/B results (clean `origin/master` vs this patch, same box, `--mode=graphics --recompile`)

**Sweep set (166 tests, `w2-text-cx-jpeg3-sweep.txt`)** = the standing canary set (133) ∪ every image-graded
SWF with a DefineEditText and no DoABC (35: avm1, gnash, shumway acid/text-bind, `text/*`, `visual/edittext/*`,
cache_as_bitmap text, filters bevel*/glow*/drop_shadow, focus_highlight, text_field_mask,
String_path_variable_button) ∪ every JPEG3/4 SWF above ∪ 12 `regression/` rows near the change
(`avm1_attached_clip_color`, `avm1_dynclip_color_transform`, `avm1_parent_child_{bitmap,bitmap_fill,text}`,
`avm1_placed_drawing_color`, `avm1_runtime_filters_cm_bitmap`, `avm2_bitmapdata_draw_textfield`,
`avm2_parent_child_static_text`, `avm2_static_text`, `avm2_timeline_text`, `bitmap_pool_layer_cap`).
A string scan for AVM1 script colour transforms on text (`createTextField`/`TextField` + `setRGB` /
`setTransform` / `colorTransform`) over every image-graded SWF finds no AVM1 row (one AVM2 hit, `away3d_*`, which
is not this path).

`render_canary.py compare before after`: **237 comparisons: 236 IDENTICAL, 1 DIFFERS** (`acid-color-0`, intended).
**Trace status changes: none. Image status changes: none.**

### Per-test before/after (headline rows)

| test | trace before → after | image before → after | md5 before → after |
|---|---|---|---|
| `from_shumway/acid/acid-color-0` | pass → pass | fail 17 315 → fail **314** (limit 3) | `f97ed470` (= CI) → `6a530176` |
| `avm2/bitmapdata_constructor_from_timeline` | pass → pass | (no image) | — |
| `avm2/pixelbender_dithering` | pass → pass | fail 1 297 344 → identical | `3153e740` → `3153e740` |
| `from_shumway/bitmapbuttons` | pass → pass | fail 618 042 → identical | `a806ccf6` → `a806ccf6` |
| `from_shumway/avm2/.../bitmapdata-clone` | pass → pass | pass → pass | `668f2b39` → `668f2b39` |
| `from_shumway/avm1/mouse-transparency` | pass → pass | (no image) | — |
| `from_shumway/as3-loader/events/loader-events` (KF) | ruffle_matched → ruffle_matched (16/36) | (no image) | — |
| `avm1/clone_sprite_types` | pass → pass | (no image) | — |
| 35 EditText-no-ABC image rows | unchanged | all md5-identical | — |
| `regression/avm1_edittext_placed_cxform` (NEW) | pass (empty trace) | skip (golden pending) | `532e1366` → `59ef456c` |
| `regression/avm1_edittext_placed_cxform_script` (NEW) | pass → pass (3/3) | skip (golden pending) | `532e1366` → `59ef456c` |
| `regression/avm1_jpeg3_alpha_bitmap` (NEW) | pass (empty trace) | skip (golden pending) | `b2739620` → `899df57f` |

Per-step attribution on acid-color-0: step 1 alone 17 315 → 677; + step 2 → 314. Residual census of the 314
(pixels > tol 3): Firefox-logo tiles (0,3) 83 px max 30 and (1,3) 79 px max 30, i.e. the JPEG3 alpha fringe that
step 3 addresses; "Hello" glyph edges (6,1)/(6,2) 5 px. The s24 ring-edge (4,2) pixels are no longer above
tolerance.

**New fixtures, checked by colour value (ours, after).** Both fixture variants give these exact values:
- `s1` box (0,255,255), text and border (0,255,0).
- `f2` box (255,0,128), text and border (0,0,128).
- `s3` (nested, order-sensitive) box (255,128,0), text and border (0,128,0).

Before the fix: white boxes, black text, and green text on `f2` (untinted).

JPEG3 fixture after: top-row composite `(a, 0, 255−a)` within ±1 (e.g. x=32: (128,0,127)). Before: double-premultiplied,
e.g. x=32: (64,0,127).

### Regression-suite check

12 `regression/` rows near the change: all md5-identical, trace unchanged. Three of them are standing canary
members. New fixtures as above.

## 4. Steps 3 and 4: priced, not landed

- **Step 3, premultiplied sampling for timeline bitmaps** (`render_webgpu.c`: every `bitmap_pool*` sampled
  through `bitmap_samp_linear` is STRAIGHT; Ruffle samples premultiplied). Stand-in measured on top of this
  patch: give `a == 0` texels their neighbours' un-premultiplied mean at emit (env-gated, reverted).
  **314 → 116.** The exact fix is renderer-wide: upload premultiplied texels, then un-premultiply → cx →
  re-premultiply in the bitmap fragment path. It moves every smoothed bitmap with alpha edges (lossless2 too),
  so it needs a full image-row sweep plus an images CI run. **Price: M.** Completion mechanism: a bitmap-slot
  arc with the renderer-wide sweep (every image row whose SWF has a DefineBitsLossless2 / JPEG3 / AVM2
  BitmapData with partial alpha drawn smoothed).
- **Step 4, integer-twip centring** (`tag.c` `textfield_glyph_render_cb`, `par_x_offset`:
  `remaining * 0.5f` → Ruffle's `Twips` integer `misalignment / 2`, `html/layout.rs:325-331`). Experiment
  (`(float)(((s32)lrintf(remaining)) / 2)`, reverted): **314 → 308.** Price S, but it touches every centred
  field in the corpus. Completion mechanism: land with a sweep of every image row that has a centred EditText
  (align=center in the DefineEditText layout or a TextFormat `align = "center"`). Cheap to fund alongside any
  text-layout slot. It is not worth the sweep on its own for 6 channels of a band.
- **Floor** with 3+4 ≈ 110 (logo fringe residual from straight-vs-premultiplied bilinear plus ~5 glyph-edge
  pixels) against limit 3. **acid-color-0 never flips on this chain.** Disposition stays "band".

## 5. Refutations / premise checks

1. **"Every JPEG3 row moves."** Refuted for the AVM2 rows. AVM2 BitmapData symbols come from a separate,
   already-premultiplied table (`bd_seed_embedded`). Only the AVM1/timeline bitmap table changed, and only
   acid-color-0 draws a partial-alpha JPEG3 through the timeline in a graded comparison. `bitmapbuttons`' JPEG3
   is in a timeline bitmap-FILL shape that is currently invisible (s26 w1-pixel-tail §2). **Rider for
   `w2-tail-bitmap-draw`:** once its `shape_renderable` hunk makes those fills draw, they draw with THIS
   patch's un-premultiplied colour (Flash-correct). A/B `bitmapbuttons` with both patches applied, not either
   alone.
2. **The s23 prototype was only partly correct.** It read `obj->cxform_id` directly, which inside the render walk
   can be an inherited parent slot (double-applies the parent cx) or a GPU-only minted slot (drops it). It also
   skipped the field entry's own cx on the orphan path. Both are fixed here. The nested-order fixture row `s3`
   pins the first.
3. **The "alpha is handled elsewhere" premise was kept, not re-proved.** The new code never touches alpha, so it
   cannot double-apply it. Every text row in the sweep is md5-identical, but I did not separately confirm that
   any of them carries a text `_alpha`.

## 6. EXPECTED-FLIP LEDGER (for CI grading)

**Trace axis:** no expected change anywhere. `regression/avm1_edittext_placed_cxform_script` is a NEW row
(pass, 3 lines). `regression/avm1_edittext_placed_cxform` and `regression/avm1_jpeg3_alpha_bitmap` are NEW rows
(pass, empty trace).

**Pixel axis:**

| test | expected CI change |
|---|---|
| `from_shumway/acid/acid-color-0` | fail → fail, outliers **17 315 → 314** (band improvement, max diff stays 255) |
| `regression/avm1_edittext_placed_cxform` | NEW row, image **skip** until the golden lands (then expected pass) |
| `regression/avm1_edittext_placed_cxform_script` | NEW row, image **skip** until the golden lands (then expected pass) |
| `regression/avm1_jpeg3_alpha_bitmap` | NEW row, image **skip** until the golden lands (then expected pass at tol 3) |

Any other pixel or trace movement is NOT from this patch. Exception: `bitmapbuttons` when combined with
`w2-tail-bitmap-draw` (see §5.1).

## 7. Patch scope

`w2-text-cx-jpeg3.patch` = `git diff --binary origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt ruffle-tests/tests/swfs/regression/README.md <3 new fixture dirs>`
(`verify_output.py` unchanged). Contents:
- `SWFModernRuntime/src/actionmodern/action.c` (+149/−14)
- `SWFModernRuntime/include/actionmodern/action.h` (+3, the `actionTextFieldCxSetApp` decl)
- `SWFModernRuntime/src/libswf/tag.c` (+9, `tag_entry_baked_cxform_id`)
- `SWFModernRuntime/src/libswf/swf.c` (+1)
- `SWFRecomp/src/swf.cpp` (+25/−5, JPEG3/4 arm only; no overlap with `shape_renderable` or `PlaceCmCompose`)
- `render_canary_tests.txt`: appended at EOF (tier 2) `from_shumway/acid/acid-color-0`,
  `regression/avm1_edittext_placed_cxform_script` and `regression/avm1_jpeg3_alpha_bitmap`. The standing set had
  no member for either change class.
- `regression/README.md`: three table rows.
- The three fixture dirs.

No new `.c`/`.h` files, so the build lists are unchanged. Recompiler change: CI must recompile, so run the
graphics leg with fresh recompilation (the usual CI path).

## 8. Not finished / completion mechanisms

- **Fixture goldens.** Pending the Ruffle exporter (below). Until then the three image comparisons are `skip`.
  Completion: the coordinator runs the oracle requests and commits `output.expected.png`. If Ruffle's border or
  glyph AA differs at tolerance 2, loosen `max_outliers` rather than the tolerance. The colours are exact by
  construction.
- Steps 3 and 4: §4.

## New unclaimed leads

1. **AVM1 `BitmapData.draw` of a tinted EditText.** `rasterizeMovieClipToBitmap` does not go through the text
   iterators, so a `draw()` capture of a cx'd field still takes untinted colours, if it draws text at all.
   Owner: `w2-tail-bitmap-draw`'s timeline arm. Unpriced, no corpus row known.
2. **Entry-less dynamic parents.** A `Color.setRGB` on a `createEmptyMovieClip` parent of a `createTextField`
   child: `tf_cx_for_mc` composes display-ENTRY transforms only. A clip with no entry contributes via `mc->cx_*`
   only if `mcSyncColorToDisplayObj` found an entry. Folding `mc->cx_*` for entry-less ancestors (guarding the
   zero-initialized-mult case the same way `mcSyncAlphaToDisplayObj` does) closes it. Price S. The corpus has no
   graded row (string scan above), so a fixture would come first.
3. **Root `Color` (`g_root_cx_*`) on text.** It is not composed (root has no entry). Same family, same price.
4. **AVM2 twin (`avm2_render_textbox`, cx slot 0 for the box).** Still latent (s24 census: no graded row).

## LOCAL ORACLE REQUESTS

Ruffle exporter (`0ddd12b6a` or later), default (HIGH) quality, which matches the fixtures' `with_renderer`
(no `quality = "low"`):

1. `ruffle-tests/tests/swfs/regression/avm1_edittext_placed_cxform/test.swf`: `exporter -s -f 1 --trace-log out.txt test.swf output.expected.png`.
   Need the PNG (commit as `output.expected.png`) and confirmation that the trace is empty.
2. `ruffle-tests/tests/swfs/regression/avm1_edittext_placed_cxform_script/test.swf`: `-f 1`. Need the PNG and the
   trace, which must be `s1.f=II`, `f2=II`, `s3.s.f=II`. If it differs, `output.txt` is wrong, not the runtime.
   Expect the PNG byte-identical to request 1 (same display list).
3. `ruffle-tests/tests/swfs/regression/avm1_jpeg3_alpha_bitmap/test.swf`: `-f 1`. Need the PNG. The expected top
   row is `(a, 0, 255−a)` over blue with a = 4·column (Ruffle's jpeg-decoder may differ from stb_image by ±1–2,
   hence tol 3). The bottom-left must be pure blue (alpha 0 with white colour: the clamp).
