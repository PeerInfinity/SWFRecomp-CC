# w2-harness-subtests: image instrument honours `ignore = true` and `[subtests]`, plus a report-only "matches output.ruffle.png" bucket (session 23, wave 2)

**New files:** `w2-harness-subtests-report.md` (this file) and `w2-harness-subtests.patch`.
No new source files and no new fixture dirs.

**Patch scope** (`git diff origin/master -- SWFModernRuntime ruffle-tests/verify_output.py
ruffle-tests/render_canary_tests.txt ruffle-tests/run_image_tests.py scripts/build_image_report.py
scripts/image_status_diff.py scripts/generate_image_dashboard.py scripts/image_baseline_report.py`;
`git apply --check -R` passes on the branch). **The `scripts/` files are in the patch on purpose.** The brief's path list
leaves out `scripts/`, but the instrument cannot work without the report side.

Box: cloud, `SETUP_STATUS` all OK (apt, Pillow, Dawn). Base `origin/master` `d4a3a3a0`. Tests were downloaded for
every category at **Ruffle upstream `aa9f62a70`** (master on 2026-11-21 at run time). That is newer than the s23
sync point `0ddd12b6a`, so CI will also pull whatever upstream master is when it is dispatched.

**CI fidelity is proven.** My *before* renders of `avm2/bitmap_pixelsnapping`, `avm2/graphics_draw_path`,
`avm2/graphics_gradients` and `visual/cache_as_bitmap/avm1_color` are md5-identical to CI's actual PNGs on
`origin/ruffle-image-results` `42820aae`. For example, `graphics_draw_path` is `07d7ce1c…` in both and `avm1_color` is
`74228586…` in both. Rebuilding the image reports with the **old** `build_image_report.py` on this box over master's
committed `results_graphics.json` reproduces master's committed `image_results_graphics.json` byte-for-byte (outside
`metadata`) in all 12 suites. So the predicted delta below is CI-grade.

---

## Verdict (lead)

**GO. This is a grading-instrument change: zero renders and zero trace verdicts move, except for one runtime
line.** That line aliases `drawWithQuality` to `bd_draw`, and it changes exactly two corpus SWFs: a constant-pool
scan of every `test.swf` (CWS and ZWS) finds only `bitmapdata_drawwithquality` and `bitmapdata_draw_cab_quality`.

| Axis | Predicted move on the next images run (vs master's image JSONs, run `44930669727`) |
|---|---|
| **Trace** | **0 moves.** Measured per test below: every affected test's trace status and line stats are identical before and after. |
| **Pixel denominator** | `build_image_report` TOTAL **610 → 612 (+2)** |
| **Pixel numerator** | **523 → 525 (+2)**: the two new `bitmapdata_drawwithquality` rows pass. Both depend on the alias; without it they fail at 47381 and 47426 outliers. |
| **Pixel fails** | **84 → 84**: −1 `avm2/bitmap_pixelsnapping` (moves to ignored), +1 new `visual/edittext/edittext_device_transform_basic [embedded__output]` (fail) |
| **Ignored (new total, out of the denominator)** | **6** |
| **`ruffle_matched_fail` (new, report-only)** | **9**, still fails |
| **Band move** | `avm2/bitmapdata_draw_cab_quality`, fail→fail, excess **2320 → 2640 (+14%)**. The alias makes this test actually draw, which exposes a separate gap (see "New unclaimed leads"). |

---

## 1. What changed

### `ruffle-tests/verify_output.py`

This lands the w1-pixel-misc §4 prototype, with four corrections made here.

1. **Top-level `ignore = true`.** Every comparison is still rendered and compared, but recorded as
   `status: "ignored"` with `would_pass` and `ignored_upstream: "ignore = true"`.
2. **≥2 `[subtests]`.** Each subtest is deep-merged with the top level (`_deep_merge` = Ruffle's
   `merge_into_subtest`) and yields one comparison per merged `image_comparisons` entry:
   - the key is `<subtest>__<cmp>`, with `png_name = <cmp>`, so the golden is `<cmp>.expected.png`;
   - `msaa` comes from the merged `with_renderer.quality`, using the same mapping as `get_msaa_samples`;
   - `subtest` and `png_name` are also echoed into the JSON row;
   - a `device_font_renderer = "freetype"` subtest is marked `ignored_upstream`, because Ruffle's default build does not run it.
3. **Per-subtest MSAA.** Any comparison whose `msaa` differs from the main build is captured by a rebuilt and re-run
   `variant_msaa<N>` (`MSAA_OVERRIDE`), and the main run's `CAPTURE_TRIGGERS` skip it. In the corpus this applies only
   to `bitmapdata_drawwithquality` `high__output.high`: the main build is MSAA 1 because `get_msaa_samples`'s regex
   matches the low subtest first.
4. **Correction 1: `known_failure` comes from the subtest's own flag** (or the per-comparison flag), not from the merged
   top level. A top-level `known_failure` never marks image comparisons on non-subtest tests, because it is the trace's
   flag. Propagating it would flag `fonts/device_font_no_ink [embedded__output]` for the trace's sake only.
5. **Correction 2 (new): version-keyed subtests are canonical-variant only.** `from_gnash/misc-ming.all/GradientFillTest`
   has `fp9` and `fp10` subtests that differ only in `player_options.version`. We build once and cannot emulate the
   version, so grading both would book one render twice. Only the highest-version variant is graded (first on ties),
   which is the same variant `resolve_expected_filename()` grades on the trace side (H1, `ca9c46595`). The others are
   recorded as ignored with the reason `player version 9 variant not emulated (canonical-variant mode grades fp10)`.
   Version-less subtest sets all tie at −1, so all of them are graded. This is the consistency the brief asked for:
   the trace grades one canonical variant, and the images grade every merged subtest except where the subtests differ
   only by version, in which case they grade that same canonical variant.
6. **Correction 3: ignored rows that bail early.** An ignored comparison with no expected PNG or no render is set to
   `ignored` as well, so it can never fall back into the graded denominator as a skip or fail.
7. **H3, report-only.** For a comparison that **fails** and is `known_failure`, where `<png_name>.ruffle.png` exists,
   the actual PNG is copied to `<cmp>.vs_ruffle.png` and graded against the sidecar with the same checks. The result is
   recorded as `ruffle_match: bool` and `ruffle_max_diff`. **Correction 4:** the copy and its difference PNG are deleted
   afterwards, because `render_canary.py` harvests every `*.png` in the build dir. Status and denominator are untouched.

### `scripts/build_image_report.py`

- Rows carry `subtest`, `png_name`, `ignored_upstream`, `would_pass`, `ruffle_match` and `ruffle_max_diff` when present.
- A censused ignored comparison with no record becomes `ignored`, not `skip`.
- `comparisons` and `pass_rate` exclude ignored rows. The new totals are `ignored` and `ruffle_matched_fail`.
- The `--audit` check uses `png_name`, and the console lines print both new totals.

### `scripts/image_status_diff.py`

Two new handlers, so neither case is booked as a loss plus a gain:

- **`[subtests]` rename pairing.** A GONE `(s,t,c)` is paired with its single graded NEW `(s,t,X__c)`; the reverse
  direction is handled too. The pair is classified like any intersection row and labelled `[c -> X__c, renamed]`.
  Ignored siblings are listed as split-offs.
- **`IGNORED MOVES`.** Any move into or out of `ignored` goes to a separate list and is never a gain or a regression
  (exit code 0).

It also prints `RUFFLE-MATCHED FAILS old -> new`, and the header counts renamed pairs.

### Other scripts

- `scripts/generate_image_dashboard.py`: the denominator excludes ignored rows, and goldens resolve through `png_name`.
- `scripts/image_baseline_report.py`: ignored rows are dropped from the corpus totals.
- `ruffle-tests/run_image_tests.py`: goldens resolve through `png_name` (a local tool, for consistency).

### Runtime and canary

- **`SWFModernRuntime/src/avm2/avm2_bitmap.c:4087`**: `drawWithQuality` now maps to `bd_draw` instead of `bd_noop`.
  The 7th argument (quality) is ignored, consistent with the s22 ruling that Flash anti-aliases `draw()` at LOW too.
- **`ruffle-tests/render_canary_tests.txt`**: appended `avm2/bitmapdata_drawwithquality` (tier 1) and
  `avm2/bitmapdata_draw_cab_quality` (tier 2). The standing set could not see this change class.

---

## 2. Per-test before/after (graphics `--images`, clean `origin/master` vs patch, same box)

**Trace verdict is unchanged for every row** (status and `lines` identical).

| test | trace (before = after) | image before | image after |
|---|---|---|---|
| `avm2/bitmap_pixelsnapping` | pass | `output` fail 3831/0 | `output` **ignored** (3831/0, would_pass false) |
| `avm2/bitmapdata_drawwithquality` | pass | *(not graded)* | `low__output.low` **pass 3152/3200**; `high__output.high` **pass 3197/3204**. With the harness change but without the alias: fail 47381 / 47426. |
| `fonts/device_font_kerning` | pass | `output` pass 0/0 | `embedded__output` pass 0/0; `freetype__output` ignored (would pass) |
| `fonts/device_font_no_ink` | ruffle_matched | `output` pass 0/0 | `embedded__output` pass; `freetype__output` ignored |
| `visual/fonts/leading_device_font` | pass | `output` pass 0/0 (tol 128) | `embedded__output` pass 0/0; `freetype__output` ignored (tol 215) |
| `visual/edittext/edittext_device_transform_basic` | pass | *(not graded)* | `embedded__output` **fail 1020/14** (2 checks); `freetype__output` ignored (also known_failure) |
| `from_gnash/misc-ming.all/GradientFillTest` | output_mismatch | `output` pass 936/1070 | `fp10__output` pass 936/1070; `fp9__output` ignored |
| `avm2/graphics_draw_path` | ruffle_matched | fail 664 | fail 664, **`ruffle_match: true`** (max_diff 0) |
| `visual/cache_as_bitmap/avm1_color` | pass | fail 1200 | fail 1200, **`ruffle_match: true`** |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest` | pass | fail 1782 | fail 1782, **`ruffle_match: true`** (max_diff 1) |
| `from_shumway/hardwrap` | pass | fail 3099 | fail 3099, **`ruffle_match: true`** |
| `from_shumway/gradientTransform` | pass | fail 9 | fail 9, `ruffle_match: false` (max_diff 18) |
| `avm2/{bitmapdata_applyfilter_destpoint_edges, bitmapdata_draw_filters, graphics_draw_triangles, graphics_gradients, graphics_simple_shapes, sprite_with_frames, stage3d_fractal}`, `visual/{blend_modes/shader_as_mask, simple_shapes/strokes/scale}` | unchanged | fail | fail, identical, plus `ruffle_match: false` |
| `avm1/edittext_tag_indent`, `fonts/embed_matching/no_font_found`, `visual/cache_as_bitmap/oversize/swf_{9,10}_too_big`, `visual/video/vp6_inter_frames` (15 cmps) | unchanged | pass | pass, byte-identical. These are known_failure rows that pass, so no sidecar compare runs. |

`graphics_simple_shapes`, `graphics_gradients` and `sprite_with_frames` stay `ruffle_match: false` against the
sidecar. That matches w1-drift-avm2 §1b (their old residue remains).

**Ordinary image tests: entries are byte-identical** in the `--json` output, ignoring only `duration` and `phases`.
Thirteen were checked: `avm1/{bitmap_data_colortransform, bitmap_data_pixeldissolve_image,
define_font_glyph_table_overlap, focusrect_swf5 (12 cmps)}`, `avm2/{bitmapdata_copychannel, bitmapdata_draw_rotation,
displayobject_blendmode}` and `visual/{avm2_button_scroll_rect, blend_modes/hardlight, cache_as_bitmap/bitmap_changed
(3), cache_as_bitmap/edittext_hscroll (2)}`, plus every failing known_failure row above. Those rows differ only by the
new `ruffle_match`/`ruffle_max_diff` fields.

A final leg re-run after the last edits (early-ignored and vs_ruffle cleanup) reproduced the "after" JSON byte-for-byte
for 9 of these tests.

**No-graphics spot check** (shared TU `avm2_bitmap.c`): `bitmapdata_drawwithquality` and `bitmapdata_draw_cab_quality`
both pass on the trace, the same as master's no-graphics `results.json`.

**`py_compile`**: `verify_output.py`, `build_image_report.py`, `image_status_diff.py`, `generate_image_dashboard.py`,
`image_baseline_report.py` and `run_image_tests.py` all compile.

## 3. Regression suite and render canary

- **`regression` suite (graphics `--images`).** `avm1_parent_child_render`, `avm2_parent_child_render`,
  `mask_nested_intersect`, `avm2_bitmapdata_draw_textfield` (the draw() path) and `avm2_timeline_gradients` all have
  trace pass→pass and image JSON identical.
- **Render canary.** The full standing set plus the 2 appended members (98 tests, `-P 4`) gave **149 IDENTICAL, 1 DIFFERS,
  6 APPEARED, 2 VANISHED, 0 NO_RENDER**. There were no trace status changes. All of these are in the ledger:
  - **DIFFERS `avm2/bitmapdata_draw_cab_quality`**: the alias makes it draw. Image fail→fail, 2400 → 2720 outliers
    (budget 80). Before, the bottom bitmap was plain black. After, the triangle is drawn **magenta where Flash has
    blue**: `ColorTransform(0,1,1)` is not applied on a Shape/Sprite source (see leads).
  - **APPEARED/VANISHED** are the subtest renames: `device_font_kerning` and `leading_device_font` lose `output` and
    gain `embedded__output` + `freetype__output`; `bitmapdata_drawwithquality` gains `low__output.low` and
    `high__output.high`. **The renamed PNGs are md5-identical to the old `output.png`** (`a60be153…`, `ee55501d…`), so
    the renders are unchanged.

## 4. EXPECTED-FLIP LEDGER

Read this against the next `images=true` run (any mode/categories that include the suites). Baseline is master's
image JSONs (run `44930669727`, `bc91565ce`).

**Trace axis: no moves.** Any trace move on these tests is not this patch:
`bitmap_pixelsnapping`, `bitmapdata_drawwithquality`, `bitmapdata_draw_cab_quality`, `device_font_kerning`,
`device_font_no_ink`, `leading_device_font`, `edittext_device_transform_basic`, `GradientFillTest`.

**Pixel axis, exact delta** (this is the actual `scripts/image_status_diff.py` output on predicted JSONs, rebuilt with
the new code over master's `results_graphics.json` patched with my measured entries):

```
=== intersection: 605 comparisons + 4 renamed ([subtests] split) ===
STATUS HISTOGRAM   fail 84 -> 83 (-1)   ignored 0 -> 1 (+1)   pass 522 -> 522   skip 3 -> 3
GAINS 0   REGRESSIONS 0   BAND MOVES 0            (exit 0)
IGNORED MOVES: 1
  avm2/bitmap_pixelsnapping [output]: fail -> ignored (would_pass=False)
RENAMED ([subtests] split): 4
  fonts/device_font_kerning [output] -> [embedded__output]  pass -> pass
  fonts/device_font_no_ink [output] -> [embedded__output]  pass -> pass
  from_gnash/misc-ming.all/GradientFillTest [output] -> [fp10__output]  pass -> pass
  visual/fonts/leading_device_font [output] -> [embedded__output]  pass -> pass
  + split-offs (ignored): device_font_kerning, device_font_no_ink, leading_device_font [freetype__output];
    GradientFillTest [fp9__output]
RUFFLE-MATCHED FAILS (report-only; still fails): 0 -> 9
NEW: 4
  avm2/bitmapdata_drawwithquality [high__output.high]  pass
  avm2/bitmapdata_drawwithquality [low__output.low]  pass
  visual/edittext/edittext_device_transform_basic [embedded__output]  fail
  visual/edittext/edittext_device_transform_basic [freetype__output]  ignored
GONE: 0
```

**Plus one render move that the dry run cannot show** (it is a real render change from the alias):
`avm2/bitmapdata_draw_cab_quality [output]` will appear under BAND MOVES as worsened, excess 2320 → 2640, d_moderate →
d_moderate. This is expected, not a regression.

**Per-suite report headers** (`pass/comparisons`, pass_rate, ignored, ruffle_matched_fail):

| suite | before | after |
|---|---|---|
| `avm2` | 101/128, 78.9% | **103/129, 79.8%**, ignored 1, rmf 1 (`graphics_draw_path`) |
| `visual` | 221/240, 92.1% | **221/241, 91.7%**, ignored 2, rmf 1 (`cache_as_bitmap/avm1_color`) |
| `fonts` | 5/5 | 5/5, ignored 2 |
| `from_gnash/misc-ming.all` | 13/18 | 13/18, ignored 1, rmf 2 (`Video-EmbedSquareTest`, `shape_test`) |
| `from_shumway` | 95/123 | 95/123, rmf 5 (`MaskTest-2`, `acid/acid-shapes-testing`, `flash_text_TextField`, `hardwrap`, `stylesheet`) |
| others | unchanged | unchanged, 0 / 0 |

`build_image_report` TOTAL goes from `523/610 pass, 84 fail, 3 skip` to `525/612 pass, 84 fail, 3 skip, 6 ignored,
9 ruffle-matched fail`. (That TOTAL includes the nested `from_shumway/avm1` row, as it always has; the dashboard and
`image_baseline_report` exclude it.)

**How the `ruffle_matched_fail` 9 were derived.**
- Measured live in verify_output: `graphics_draw_path`, `avm1_color`, `Video-EmbedSquareTest`, `hardwrap`.
- The other 5 come from CI's own actual PNGs on `ruffle-image-results`, graded against each sidecar with the
  comparison's checks: `MaskTest-2`, `acid-shapes-testing`, `flash_text_TextField`, `stylesheet` and `shape_test` are
  true at max_diff 0.
- All other known_failure + sidecar fails are false: the 7 avm2 rows above, `shader_as_mask`, `strokes/scale`,
  `acid-mask`×3, `acid-stroke-0`, `acid-text-4`, `acid-text-5`, `acid-textfield`, `captions`, `gradientTransform`,
  `BeginBitmapFill`, `place_object_test`.

This goes beyond the brief's expected two. These are still FAILS under the Flash-over-Ruffle ruling.

### Is `image_status_diff.py` sensible on these rows? Yes, after this patch

- **Before this patch** the run would have printed 4 GONE (`… [output] was pass`) and 10 NEW. Ignored rows would have
  shown as `fail -> ignored` under STATUS/REASON CHANGES, and a future `pass -> ignored` would have been booked as a
  **REGRESSION** with exit 1.
- **After this patch:** renames pair and are compared through the rename; ignored moves have their own list and are
  never gains or losses. The reverse direction (diffing across a revert of this patch) pairs symmetrically: verified
  4 RENAMED, 0 NEW.
- **If the coordinator diffs with an older copy of the script:** read the 4 GONE `[output]` rows against their
  `embedded__output` / `fp10__output` NEW rows as the same comparison, and `bitmap_pixelsnapping` fail→ignored as a
  denominator move only.

---

## 5. Refutations and corrections to the w1 premises

- **w1-pixel-misc's census "5 subtest comparisons across 3 tests" undercounts.** It counted only comparisons written
  *inside* `[subtests]`. Under Ruffle's merge, top-level comparisons are inherited by every subtest. That adds
  `fonts/device_font_kerning` and `fonts/device_font_no_ink` (renames, plus 2 freetype ignores), and, outside w1's
  categories, `from_gnash/misc-ming.all/GradientFillTest` (version split, handled by correction 2). The **net
  denominator is unchanged at +2**, because all three are renames plus ignored rows.
- **The prototype's `merged.get("known_failure")`** would have flagged `device_font_no_ink [embedded__output]` as
  known_failure from the trace-level flag. That is corrected (§1, item 4).
- **The prototype would grade `GradientFillTest` fp9 and fp10 from one render**: +1 denominator and +1 numerator that
  no render earned. That is corrected (§1, item 5).
- **H3 expected only `graphics_draw_path` and `avm1_color`** (that brief's scope was avm2/visual). Corpus-wide the
  count is **9**.
- **The `drawWithQuality` alias is not render-neutral outside drawwithquality.** It worsens `bitmapdata_draw_cab_quality`
  (fail→fail). It is still in the patch, as the brief asked, and is ledgered above. It can be split off
  (`avm2_bitmap.c` is the only runtime hunk), but then the two drawwithquality rows land as NEW **fails**
  (47381 / 47426) instead of passes, so the numerator would be +0 instead of +2.

## 6. Not finished / caveats

- **No CI run from this slot.** The coordinator grades it; the ledger above is the prediction.
- **Upstream drift risk.** The prediction is at upstream `aa9f62a70`. A CI dispatch pulls upstream master at that
  time, so a further toml change to any row above is drift, not this patch.
- **`edittext_device_transform_basic [embedded__output]` fails at 1020/14** (2 checks: tolerance 0 / 90 outliers and
  tolerance 128 / 14). It is a NEW graded fail, not a regression: the row was never graded before. It is a
  device-font transform render residual, owned by the text/glyph slots.

## New unclaimed leads

- **Shape/Sprite-source `BitmapData.draw()` ignores `colorTransform` (arg 2) and `blendMode` (arg 3).**
  `avm2_bitmap.c` `bd_draw` → the `shape_src` branch (~2805) calls `bd_draw_shape_walk` without `has_cxform/rm..ao` or
  `blend_mode`, while the TextField and BitmapData branches honour both. Evidence: `bitmapdata_draw_cab_quality` draws
  `(255,0,255)` where Flash has `ColorTransform(0,1,1)` → `(0,0,255)` with `difference` over black. A fix would likely
  bring that row near its budget (80); it was not priced here.
- `bitmapdata_drawwithquality` passes near its limits (48 and 7 outliers of headroom). It is now in the canary.

## LOCAL ORACLE REQUESTS

None.
