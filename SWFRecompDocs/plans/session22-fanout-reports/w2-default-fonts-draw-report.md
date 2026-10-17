# w2-default-fonts-draw: test.toml default fonts for zero-glyph device text, the CAB slot fix, and draw() clipRect/mask (s22 wave 2, cloud)

**NEW FILES:**
- `SWFRecompDocs/plans/session22-fanout-reports/w2-default-fonts-draw-report.md` (this report)
- `SWFRecompDocs/plans/session22-fanout-reports/w2-default-fonts-draw.patch` =
  `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md ruffle-tests/tests/swfs/from_shumway/avm1/ignored_tests.txt`.
  `git apply --check -R` passes on the branch head. No new source files and no new fixture dirs. Every edit sits in an
  existing TU, so nothing changes in `verify_output.py`, CMake or the Emscripten source lists.

**Box / provenance.** `SETUP_STATUS`: apt, Pillow and Dawn all OK (lavapipe). Base = `origin/master` `5dee7a4b4`. Corpus
`avm1 avm2 visual from_shumway fonts text from_gnash` was downloaded at upstream Ruffle **`45366370e`** (the coordinator's sync
SHA). BEFORE legs ran in a clean `git worktree` of `origin/master` on the same box (hard-linked corpus, same recompiler build
config). AFTER legs ran on this branch.
**Cloud↔CI fidelity is PROVEN on all four headline rows.** My BEFORE renders are md5-identical to CI's actual PNGs on
`origin/ruffle-image-results`: `avm2/bitmapdata_draw` `11521f6bc131`, `avm2/bitmapdata_draw_masks` `7fbd4c5e3461`,
`from_shumway/avm1/text-bind` `05f37d7c5bde`, `visual/cache_as_bitmap/text` `8d824305cdb3`. Every absolute verdict below is
therefore CI-grade.

---

## 1. Verdicts and priced flips

| # | item | verdict | flips (pixel axis) | evidence |
|---:|---|---|---:|---|
| 1 | AVM1 zero-glyph synth resolves `[fonts.*]` / `[default_fonts]`, with the correct face upem | **GO, LANDED** | `from_shumway/avm1/text-bind` | 2498 → **583 / 600** @tol64, 1919 → **64 / 100** @tol128. **Margin: 17 channels @64** (36 @128) |
| 2 | CAB root-sprite slot repoint no longer blanks its EditText children | **GO, LANDED** | `visual/cache_as_bitmap/text` | 6681 → **1200 / 1500** @tol128 (margin 300), 10233 → 11049 / 12000 @tol0 (margin 951). Before, it passed tol0 *because the text was blank* |
| 3 | AVM2 `draw()` honours the source's `mask` | **GO, LANDED** | `avm2/bitmapdata_draw_masks` | 2700 → **0 / 0** @tol0. Byte-exact |
| 4 | AVM2 `[default_fonts]` rows + `draw()` clipRect | **GO, LANDED (band only)** | 0 | `avm2/bitmapdata_draw`: 37 079 → **1725 / 1500** @tol64, 24 578 → 761 / 600 @tol128, 39 803 → **5013 / 5200** @tol0 ✓. It is still FAIL: 2 of 3 checks |
| 5 | the remaining uniform ~1 px text baseline in `bitmapdata_draw` | **HOLD: not a bug in our Ruffle port** | (+1 if ruled) | the golden is a **Flash capture**, and Ruffle's own model puts the baseline exactly where we do. See §3 |

**Net priced: +3 pixel flips** (text-bind, cache_as_bitmap/text, bitmapdata_draw_masks). **0 trace moves.**

### Per-test before/after (same box, clean origin/master vs this patch, `--mode=graphics --images --recompile`)

Every test with a `[default_fonts]` or `[fonts.*]` section in the downloaded corpus (19), plus `bitmapdata_draw_masks`:

| test | trace before | trace after | pixel before | pixel after |
|---|---|---|---|---|
| `avm2/bitmapdata_draw` | pass | pass | fail t0:39803/5200 t64:37079/1500 t128:24578/600 | **fail t0:5013/5200 ✓ t64:1725/1500 t128:761/600** |
| `avm2/bitmapdata_draw_masks` | pass | pass | fail t0:2700/0 | **PASS t0:0/0** |
| `avm2/bitmapdata_drawwithquality` | pass | pass | (subtest images ungraded) | (ungraded) |
| `avm2/edittext_device_transform_layout` | ruffle_matched 268/288 | ruffle_matched 268/288 | - | - |
| `fonts/device_font_glyph_fallback` | pass 36/36 | pass 36/36 | - | - |
| `fonts/device_font_kerning` | pass 4/4 | pass 4/4 | pass 0/0 | pass 0/0 |
| `fonts/device_font_list` | pass 64/64 | pass 64/64 | - | - |
| `fonts/device_font_name_case` | output_mismatch 1/13 | output_mismatch 1/13 | - | - |
| `fonts/device_font_no_ink` | ruffle_matched 4/18 | ruffle_matched 4/18 | pass 0/0 | pass 0/0 |
| `from_gnash/actionscript.all/TextField-v6` | output_mismatch 467/545 | same | - | - |
| `from_gnash/actionscript.all/TextField-v7` | output_mismatch 476/570 | same | - | - |
| `from_gnash/actionscript.all/TextField-v8` | output_mismatch 478/571 | same | - | - |
| `from_gnash/misc-mtasc.all/TextFieldTest` | ruffle_matched 7/8 | same | - | - |
| `from_shumway/avm1/text-bind` | pass | pass | fail t128:1919/100 t64:2498/600 | **PASS t128:64/100 t64:583/600** |
| `visual/cache_as_bitmap/text` | pass | pass | fail t0:10233/12000 t128:6681/1500 | **PASS t0:11049/12000 t128:1200/1500** |
| `visual/edittext/edittext_device_transform_basic` | pass 24/24 | pass 24/24 | - | - |
| `visual/edittext/edittext_device_transform_metrics` | ruffle_matched 32/40 | same | - | - |
| `visual/edittext/edittext_device_transform_negative` | ruffle_matched 79/120 | same | fail t0:1122/160 t128:1032/30 | identical |
| `visual/fonts/device-font` | pass | pass | pass 0/3 | pass 0/3 |
| `visual/fonts/leading_device_font` | pass | pass | pass 0/0 | pass 0/0 |

Trace lines did not move on any of them. (The gnash `TextField-v*` SWFs carry no DefineFont, so the recompiler synth never
fires there. Their `[default_fonts]` has no effect on our side.)

### Regression suite (BEFORE vs AFTER, both modes)

`avm1_parent_child_text`, `avm2_bitmapdata_draw_textfield`, `avm2_graphics_runtime`, `avm2_parent_child_render`,
`avm2_parent_child_static_text`, `avm2_static_text`, `avm2_timeline_text`, `mask_nested_intersect`, `mask_sibling_union`: all
**pass → pass** under `--mode=graphics --images`, and all **pass → pass** in no-graphics. Image statuses are unchanged (pass /
skip). The canary below carries 6 regression members md5-identical.

### Render canary (`render_canary.py`, 63 standing members, `--recompile`, -P 2)

`compare before after`: **105 / 105 comparisons IDENTICAL, 0 DIFFERS, 0 trace or image status changes.** The only MISSING rows
are the 3 members I appended (absent from the pre-edit `before` label by construction). Their BEFORE md5s are the CI-identical
ones above. AFTER: `bitmapdata_draw_masks` `767475ffffba`, `text-bind` `de1c208b913a`, `cache_as_bitmap/text` `9c45ad0dab31`.

---

## 2. EXPECTED-FLIP LEDGER (check CI against this)

**Pixel axis (image_results_graphics.json), fail → pass:**
- `from_shumway/avm1/text-bind` (583 / 600 @64: **thin**, 17 channels)
- `visual/cache_as_bitmap/text` (1200 / 1500 @128)
- `avm2/bitmapdata_draw_masks` (0 / 0 @0)

**Pixel axis, band only (stays fail):** `avm2/bitmapdata_draw` 37 079 → 1725 @64 (outliers move, verdict doesn't).

**Trace axis:** **no expected moves.** Every trace row in the table above is line-identical. Any trace move in CI is a
regression of this patch.

**Everything else on the pixel axis must be md5-stable.** The changed code only fires on (a) a zero-glyph DefineFont2/3 in a
test whose `test.toml` resolves its name to a declared face, (b) an AVM2 device-list miss in a test that declares
`[default_fonts]`, (c) an AVM1 TextField under a cacheAsBitmap root sprite whose snap is non-zero, (d) AVM2 `draw()` with a
clipRect argument or a masked node in the source subtree, and (e) a masker child inside a drawn container, which is now skipped
as content, per Ruffle `skip_masks`.

---

## 3. Mechanism and patch scope (owner `file:line` on this branch)

1. **Recompiler: device-font resolution** (`SWFRecomp/src/abc/abc_devicefont.cpp`, new `resolveTestDeviceFontPath` at EOF,
   declared in `include/abc/abc_devicefont.hpp`). This ports Ruffle `html/layout.rs:560-625` + `library.rs:460 default_font`
   restricted to the test harness. A `DefaultFont::from_name` name (`_sans`, `_serif`, `_typewriter`, and the three Japanese
   ones, `font.rs:102`) goes straight to its `[default_fonts]` list. Any other name first tries a `[fonts.*]` family
   (case-insensitive, Ruffle `FontMap::find` style ladder), then maps Times New Roman → serif, Arial → sans,
   Consolas / Courier / Courier New / NSimSun → typewriter, `Ming` / `明` → japanese_mincho, anything else → sans. The list then
   resolves exact-style first, then compatible style. Returns `""` when nothing resolves, and the caller keeps the bundled Noto.
   So **no test without a matching `test.toml` changes**.
2. **AVM1 synth** (`SWFRecomp/src/swf.cpp`, zero-glyph block ~2643 and fallback loop ~2701, plus helpers `loadTestDeviceFace` /
   `faceUnitsPerEm` ~151-185). The resolved face supplies metrics, advances and outlines. The scale is `swf_em / upem`, with upem
   recovered exactly from `stbtt_ScaleForMappingEmToPixels` (so the 1000-upem bundled Noto stays `swf_em / 1000.0f`
   bit-for-bit; the canary confirms it). The non-synth `SWFRECOMP_DEVICE_FONT_FALLBACK` path keeps `g_device_font`.
3. **AVM2 `[default_fonts]`** (`abc_devicefont.cpp` `collectDefaultFontAliases` + the row loop in `emitDeviceFonts`). Each list
   is emitted as extra device rows named `_sans` / `_serif` / … that **share the declared face's arrays** (no data
   duplication). The runtime (`avm2_text.c` `find_default_font_row` ~2720, called from `resolve_font` ~2838) maps the FIRST
   untrimmed name of a list that missed (layout.rs:604) to its DefaultFont alias and runs the existing ladder probe. It applies
   to **device fields only**: an embedFonts field whose name matched nothing still draws nothing (Flash; `no_font_found` stays
   green). With no `[default_fonts]` the table is byte-identical to before.
4. **CAB slot** (`tag.c` `compute_mc_world_xform` ~7505, comment above `cab_snap_world` ~3214; `action.c`
   `actionIterateTextFieldGlyphs` ~29341). **The w1 premise was half wrong.** `compute_mc_world_xform` does read the dynamic slot
   past the CPU table, but the reader that blanked `cache_as_bitmap/text` is the **AVM1 TextField glyph walk**. It composes a
   field's world position from each timeline-placed parent's `transform_id`, and for the CAB root that is the dynamic slot
   (garbage: the fields landed at y = −107 / −620). Both readers now resolve a ROOT entry through `ng_get_original_transform_id`.
   `opaque_background` keeps its 3856 → 4: the slot repoint itself is untouched, and the canary's
   `visual/cache_as_bitmap/*` members are md5-identical.
   *Snapped vs pre-snap origin, measured:* resolving the text through the snapped matrix scores 1380 @128, and through the
   pre-snap matrix 1200. Ruffle device text runs its own `EditTextPixelSnapping`, so I took the better one. The code comment
   records both numbers.
5. **AVM2 `draw()` clipRect** (`avm2_bitmap.c` `bd_clip_begin` / `bd_clip_end` ~2595, `bd_draw` ~2628). The translation-only
   BitmapData blit uses Ruffle's CPU region rule (`operations.rs:1416`: floor the origin, ceil the size). Every other source
   (shape / Sprite, TextField, affine BitmapData, the alpha/erase Bitmap blit) uses snapshot → draw → restore outside, with
   pixel-centre coverage of the destination-space rect. The rect is NOT transformed by the matrix (`operations.rs:1487`).
6. **AVM2 `draw()` source mask** (`avm2_bitmap.c` `bd_draw_masked` + `bd_l2g_matrix` ~2363-2470). Ruffle
   `apply_standard_mask_and_scroll`: the masker renders under `world · global_to_local(node) · local_to_global(mask)`, and the
   draw ROOT drops its own term because apply_transform is off. So a mask that is not in the drawn subtree keeps its OWN matrix
   in draw space. The node draws as usual, then pixels outside the mask's coverage are lerped back to the snapshot. Maskers
   met as children of the drawn subtree are skipped as content (Ruffle `skip_masks`).
   Known limits: coverage is the mask's raster alpha, so a mask filled with alpha 0 hides everything (Ruffle's stencil
   ignores fill alpha). Masks are applied by snapshot, so one temp buffer pair per masked node per draw.

Self-localization: every runtime edit is a new `static` helper or a guarded block. `abc_devicefont.cpp` edits are new
functions plus the table row loop. The only overlap with siblings is **`abc_devicefont.cpp`** (w2-glyph-subunit edits the
outline emit ~126/~169, which I don't touch) and **`avm2_bitmap.c` `bd_draw`** (w2-draw-bigcap-aa edits the CPU raster AA,
which I don't touch).

---

## 4. Refutations / corrections

1. **`text-bind` ACCEPTED_DIFFS entry: REFUTED and retired** (patch deletes the entry, its summary-table row and a
   cross-reference; it also updates the stale pointer in `from_shumway/avm1/ignored_tests.txt`. Nothing to remove from
   `ignored_tests.txt`).
2. **w1 "CAB: `compute_mc_world_xform` drops the repoint" is the wrong reader** (§3.4). The fix that flips the row is in
   `action.c`'s TextField walk. `compute_mc_world_xform` got the same treatment because it has the same OOB read.
3. **The `bitmapdata_draw` 1-px baseline is not a port bug (HOLD).** Ruffle's own model gives the same baseline we do:
   GUTTER 40 + `ascent(240)` = (int)(784·240/1024) = 183 twips, so 11.15 px. That follows from `font_like.rs:99`
   baseline = ascent, `layout.rs:348` baseline_adjustment = max_ascent, `edit_text.rs:778` layout_to_local translate by
   GUTTER, and `font_face.rs:108` ascender = hhea 784, since the test font has OS/2 v2, no USE_TYPO_METRICS.
   The golden is a **Flash Player capture**. Upstream `02a16f8af` "Make it not depend on the default font" (Kamil Jarosz)
   added `NotoSans.ttf` + `fonts.conf`, i.e. a fontconfig-pinned Flash run.
   The residual is consistent with **Flash rounding the device ascent UP to a whole pixel**. Measured ink-centroid offset
   (golden − ours), against the ceil prediction:

   | size | ceil predicts | measured |
   |---:|---:|---|
   | 12 | +0.81 px | +0.81 / +0.92 (bitmapdata_draw stage / bitmap) |
   | 42 | +0.84 px | +0.79 (text-bind) |
   | 29 | +0.80 px | +0.62 / +0.73 (cache_as_bitmap/text) |

   All three are Flash-captured goldens, across both VMs. I did **not** ship a shift. It would move AVM2 device-text
   `getLineMetrics` / `textHeight` traces if done in layout, and Ruffle-captured goldens (no `fonts.conf`) want Ruffle's
   unrounded baseline. Completion mechanism: oracle request 1 below, then a ruling. If Flash rounds, landing it in
   layout + AVM1 `textfield_glyph_render_cb` would flip `bitmapdata_draw` (w1 projected 6 @64 / 0 @128 with a +1 px shift) and
   widen text-bind's 17-channel margin.
   Outlier split today (@64): bitmap-drawn text 723, stage text 699, circles 195, clipped ellipse 108. Our CPU draw text is
   also unantialiased, which is w2-draw-bigcap-aa's lane.

---

## 5. Not finished / HOLD (each with its completion mechanism)

- **`avm2/bitmapdata_draw` flip**: HOLD on the Flash baseline rule (§4.3). Mechanism: LOCAL ORACLE REQUEST 1 + 2.
- **No corpus test pins `draw()` clipRect for BitmapData / TextField sources**: only the shape-source arm is graded (the
  `bitmapdata_draw` ellipse, 35 120 → 108). No AS3 compiler or external oracle in the cloud, so the fixture is LOCAL ORACLE
  REQUEST 3 (spec below), to land under `regression/` with an oracle-made `output.txt`.
- `avm2/bitmapdata_drawwithquality` uses `[default_fonts]` too, but its images live in subtests that `verify_output.py`
  does not grade. Unpriced.

## 6. New unclaimed leads

- **Flash device-text baseline = ceil(ascent px)?** (§4.3) This is cross-VM, and if true it is worth a trace audit of every
  device-font `getLineMetrics` row against `output.txt`: Flash's own reported ascent would be integral. The cheapest check is
  `fonts/device_font_*` and `avm2/edittext_device_transform_layout` `output.txt` ascent lines.
- **The AVM1 TextField glyph walk is translation-only** (`action.c` ~29306 comment) and reads parents' rows directly. Nested
  parents' dynamic slots are excluded only because the walk requires `display_list` membership. A scaled CAB / filtered root
  sprite would still misplace text.
- **The draw() mask uses raster alpha, not a stencil**: an alpha-0 mask fill blanks the drawn node (Ruffle draws it). Cheap
  follow-up: rasterize the mask with forced alpha 1.

## LOCAL ORACLE REQUESTS

1. **Flash (fontconfig-pinned like the golden) or the Flash-captured `output.txt` of any device-font test: `getLineMetrics(0)`
   for a 12 px Times New Roman field resolved to this test's NotoSans (upem 1024, hhea 784/−247/170).** Is `ascent` 9.15 or
   10? This decides the §4.3 rule.
2. **Ruffle exporter, `avm2/bitmapdata_draw/test.swf`, frame 1, rendered PNG.** It confirms that Ruffle itself sits 1 px high
   vs the golden (expected: yes, same model) and shows how Ruffle stays inside 1500 @64 (AA'd CPU-path text?).
3. **Fixture for `regression/avm2_bitmapdata_draw_cliprect`** (AS3; compile + Flash/Ruffle `output.txt`): a 40×40 opaque
   white `BitmapData` target; `draw(src, new Matrix(1,0,0,1,5,5), null, null, new Rectangle(10.5, 10, 15, 12.5))` for each
   of (a) a 20×20 red BitmapData, (b) the same under `Matrix(2,0,0,2,0,0)`, (c) a red Sprite rect, (d) a TextField
   "MMMM" (device, `[default_fonts]`). Trace `getPixel32` at the rect's four inside / outside corners plus (10,10), (25,22),
   (26,23). That pins both the region rule (floor / ceil) and the pixel-centre rule.
