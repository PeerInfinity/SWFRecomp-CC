# w2-gfx-fill-smalls — **2 pixel flips landed + one 98 % band move**, and the
# wave-1 mechanism for A4 is **REFUTED** (the bug was not a blend, it was a
# missing walk arm)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a7aba3614168acef8`
Patch: `SWFRecompDocs/plans/session18-fanout-reports/w2-gfx-fill-smalls.patch`
Scratch (private): `<scratchpad>/w2-gfx-fill-smalls/`
Baseline: `8f68a5fea`; image baseline read fresh from
`ruffle-tests/tests/swfs/avm2/_results/image_results_graphics.json`
(run `33857494837`, sha `659153865`) — every "before" number below was also
re-measured locally and matched the CI JSON exactly.

## NEW FILES

**None.** All three changes live inside existing translation units, so there is
nothing to add to `verify_output.py`'s explicit source list, CMakeLists or the
Emscripten build. Deliverables (this report + the patch) are the only new files.

---

## 1. Headline ledger — measured, `--mode=graphics --images`

| # | test | before (local = CI) | after | verdict |
|---|---|---:|---:|---|
| **A2** | `avm2/edittext_always_show_selection` | 432 outliers, max diff 43 | **0, max diff 0** | **FLIP — image PASS** |
| **A4** | `avm2/bitmapdata_draw_self_via_graphic` | 7 500 outliers, max diff 23 | **0, max diff 0** | **FLIP — image PASS** |
| **B2** | `avm2/graphics_draw_path` | 204 outliers, max diff 255 | **4, max diff 255** | 98 % band move; **NOT** a flip (tol 0 / max_outliers 0) |

Both flips are **byte-exact** (`max_diff 0`, `diff_channels 0`) — the renders now
match the repo goldens pixel for pixel, not merely inside tolerance.

Trace axis unchanged on all three: `pass`, `pass`, `ruffle_matched` (51/101
matching lines both sides). `graphics_draw_path` is `known_failure = true`
upstream and carries a suite-local trace ignore, so its trace verdict is
`ruffle_matched` before and after — **no `pass -> ruffle_matched` drift**.

Net corpus effect: **+2 image rows** on the pixel board (364 → 366 of 572,
63.6 % → 64.0 %). **Zero trace movement** — image comparisons never gate
trace pass/fail, so the CI trace totals are untouched by design.

---

## 2. What each fix actually was

### A2 — one mis-transcribed constant (`avm2_text.c`)

```c
-	*out_color = focused ? 0x000000u : 0x808080u;
+	*out_color = focused ? 0x000000u : 0x555555u;
```

Confirmed exactly as w1 priced it. Ruffle `edit_text.rs:1192` uses
`Color::GRAY`, and `swf/src/types/color.rs:34` defines
`GRAY = from_rgb(0x555555, 255)`. The comment four lines above our line already
named the constant. `0x808080` appears **once** in the entire runtime, so there
was no second site. 432 → 0.

### A4 — **REFUTATION**: `BitmapData.draw` was not mis-blending, it was drawing *nothing* (`avm2_bitmap.c`)

w1 diagnosed "src-over does not accumulate destination alpha
(`aOut = as + ad(1−as)`)". **That is wrong twice over:**

1. `blend_over()` (`avm2_bitmap.c:109`) has *always* accumulated destination
   alpha — its fourth line is literally `a = CA(src) + CA(dest)*(255-sa)/255`.
   Nothing needed fixing there.
2. The measured "before" image is **uniformly 195 across the whole 100×100
   bitmap**, including the 50×50 overlap. I dumped every differing pair from the
   exported actual PNG: `expected (172,172,172) / ours (195,195,195) ×2500`, and
   `(10,10)`, `(25,75)`, `(75,25)` — all *outside* the overlap — are 195 too.
   195 is the un-drawn fill composited over white
   (`premul(0xA0A0A0A0) = 100`, `100 + 255·(1 − 160/255) = 195`).
   **The `draw()` call wrote zero pixels.** w1's arithmetic happens to land on
   195 as well, because it dropped the colour term along with the alpha term —
   the two hypotheses are numerically indistinguishable from the count alone,
   which is exactly why the actual PNG had to be read.

Root cause: `bd_draw_shape_walk()` — the recursion `BitmapData.draw(<container>)`
uses — has arms for morph shapes, shapes, EditText, StaticText, runtime
Graphics and SimpleButton state children, but **no arm for `ext->is_bitmap`**.
Its stage-side twin `avm2_cpu_walk()` (`avm2_display.c:16723`) has had that arm
all along. So a `Bitmap` nested inside the drawn subtree was silently skipped.
(The *bare* `draw(<Bitmap>)` form works — `bd_draw` unwraps it at `:2335` — which
is why the four passing `bitmapdata_draw_*` rows never caught this.)

Fix: `bd_draw_bitmap_node()`, a BitmapData-targeted mirror of
`avm2_cpu_composite_bitmap` (inverse dest→src affine sampling at pixel centres,
1 px = 20 twips), plus one `if (ext->is_bitmap)` arm at the head of the walk's
chain. Two supporting details that w1's pricing did **not** contain and without
which the row does **not** flip:

* **Self-draw snapshot.** The test draws a BitmapData onto *itself* offset by
  (50,50). Ruffle renders the source into its own texture before compositing, so
  the walk must sample a snapshot; blitting in place would feed already-written
  pixels back in on any overlap where the source region trails the destination.
* **Rounding, not truncation** (`blend_over_round`). `blend_over` is the
  byte-exact twin of Ruffle's *CPU* `operate_ex`, which truncates
  `dest·(1−srcA)`. `draw()` of a display object is a *wgpu* draw: f32 math
  rounded back to `rgba8unorm`. Here `160·95/255 = 59.6` — truncating gives
  destination alpha 219 and a final screen value of **173**, rounding gives 220
  and Ruffle's **172**. At tolerance 0 that one LSB is the whole flip. A naive
  "just call blend_over" implementation would have moved 7 500 outliers to
  7 500 outliers. `blend_over_round` is used **only** on this new path; every
  copyPixels/merge/threshold path keeps `blend_over` untouched.

### B2 — `drawPath` dropped the whole path on a NaN coordinate (`avm2_display.c`)

Confirmed. `gfx_decode_path`'s `_GRDPT` fed NaN straight into the pen commands
and on into the tessellator, which produced nothing for the *entire* fill.
Ruffle stores each coordinate as `Twips::from_pixels(v)`, whose `as i32` cast
maps NaN to 0 (the same Rust rule `clamp_fixed16` already models at
`avm2_display.c:615`), so only the first subpath goes degenerate and the
trailing 10×10 square still draws. One new `_GRDNUM` macro inside
`gfx_decode_path`; nothing else in that function moved, so it does not collide
with w2-gfx-strokes' edits to `gfx_stroke_join` / `gfx_build_stroke` /
point quantisation in the same file.

**Residual is 4 outlier channels, not w1's predicted 6**: two pixels, `(2,47)`
and `(2,77)`, expected red, ours cyan and yellow — a 1-sample rasteriser tie on
a diagonal in the `smokeTest` zigzag at `quality = "low"`. Verified by dumping
every differing pixel of the after PNG. Everything in the NaN column is now
exact.

---

## 3. Canary ledger

### Render canary — `render_canary.py`, md5 identity, **29/29 tests, 61/61 PNGs IDENTICAL**

```
compare before  after    29 tests / 52 comparisons   IDENTICAL 52  DIFFERS 0
compare before2 after2    5 tests /  9 comparisons   IDENTICAL  9  DIFFERS 0
   TRACE STATUS CHANGES: (none)      IMAGE STATUS CHANGES: (none)
```

The set is split into two A/B pairs for an honest reason. The first `before`
capture (full 29-member standing set, `-P 1`, 5 170 s under load ~30) was still
running when the patch reached the worktree at ~17:09, so its **last two rows**
(`regression/avm2_morph`, `from_shumway/acid/acid-blend-2`) were compiled from
patched sources and their "before" PNGs are not trustworthy. Rather than paper
over it, those two plus the three other tail members that the first `after`
capture had not covered were re-run as a clean pair: `before2` from `tree_pre`
(a scratch tree with the three files restored from `git show HEAD:`), `after2`
from the patched tree. Both legs, both pairs: no PNG moved.

**No row was expected to differ** and none did. The brief anticipated "rows that
draw with BitmapData.draw alpha" moving — there are none in the standing set,
which is a canary gap, not a null result (see §5).

### Trace + image canaries — 28 avm2 rows, `--mode=graphics --images`

Trace: **28/28 PASS**. Every image outlier count is **byte-identical to the CI
baseline** (`image_results_graphics.json`, run `33857494837`):

| test | CI baseline | local after |
|---|---:|---:|
| `bitmapdata_draw` | 24 585 (tol 128 / limit 600) | 24 585 |
| `bitmapdata_draw_alpha_erase` | 0 | 0 |
| `bitmapdata_draw_colortransform` | 0 | 0 |
| `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 0 |
| `bitmapdata_draw_filters` | 14 400 | 14 400 |
| `bitmapdata_draw_masks` | 5 850 | 5 850 |
| `bitmapdata_draw_rotation` | 348 | 348 |
| `bitmapdata_draw_stage` | 0 | 0 |
| `graphics_bad_direct_commands` | 0 | 0 |
| `graphics_bitmap_fill` | 64 (limit 60) | 64 |
| `graphics_bitmaps` | 1 058 (limit 4 000) | 1 058 |
| `graphics_direct_commands` | 587 (limit 300) | 587 |
| `graphics_draw_triangles` | 1 812 | 1 812 |
| `graphics_gradients` | 299 | 299 |
| `graphics_gradients_nulls` | 0 | 0 |
| `graphics_simple_shapes` | 240 | 240 |

Trace-only members, all PASS: `bitmapdata_drawwithquality`, `graphics_path`,
`graphics_round_rects`, and nine EditText rows (`edittext_align`, `_autosize`,
`_default_format`, `_focus_selection`, `_font_size`, `_getlinemetrics`,
`_html`, `_mouse_selection`, `_selected_text`) — the two selection rows are the
nearest guards A2 has and neither moved.

### `regression` suite

Targeted first: `avm1_parent_child_bitmap`, `avm1_parent_child_bitmap_fill`,
`avm2_bitmapdata_draw_textfield`, `avm2_graphics_runtime`,
`avm2_timeline_gradients`, `avm2_timeline_stroke_gradient` — **6/6 PASS**,
images 0 outliers (`avm2_graphics_runtime` has no expected PNG → SKIP, as on CI).
Four more regression rows come along inside the render canary
(`mask_sibling_union`, `mask_nested_intersect`, `avm2_timeline_gradients`,
`avm2_timeline_stroke_gradient`, `avm2_morph`) — all md5-identical.

Then the **whole suite**, `--mode=graphics`, sharded 4× on the (by then idle)
machine: **89/89 PASS, 0 fail** (shards 23 + 22 + 22 + 22). No trace or image
row moved anywhere in `regression/`.

---

## 4. Patch scope

| file | change |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_text.c` | one constant + 3 comment lines (A2) |
| `SWFModernRuntime/src/avm2/avm2_bitmap.c` | 3 new `static` functions (`bd_scale_premul`, `blend_over_round`, `bd_draw_bitmap_node`, +115 lines) and one arm in `bd_draw_shape_walk` (A4) |
| `SWFModernRuntime/src/avm2/avm2_display.c` | `_GRDNUM` macro inside `gfx_decode_path` (+13 lines) (B2) |

136 insertions, 4 deletions. Runtime-only — no recompiler change, so
`--recompile` was not required and copying the main tree's `SWFRecomp/build`
was valid. All three files compile clean under
`gcc -fsyntax-only -Wall -Wextra`.

Self-localisation vs the sibling map: the `avm2_bitmap.c` additions sit in their
own block immediately before the `draw` banner comment (w2-avm2-new-smalls edits
`copyPixels`/`applyFilter`, elsewhere in the file); the `avm2_display.c` edit is
confined to `gfx_decode_path` (w2-gfx-strokes owns `gfx_stroke_join` /
`gfx_build_stroke`, w2-gfx-avm2-blend owns the render walk, w2-avm2-stage owns
the Stage region); the `avm2_text.c` edit is the single line the brief named.

---

## 5. Refutations and honest caveats

1. **A4's stated mechanism is refuted** (§2). The fix is ~10× the LOC w1 priced
   and needed two facts w1 did not have (self-draw snapshot; GPU rounding). The
   *flip* was correctly priced; the *mechanism* was not. Anyone reusing w1's
   "BitmapData.draw does not accumulate destination alpha" line for another row
   (e.g. C5 `bitmapdata_draw_masks`, C6 `copyPixels`) should re-derive it.
2. **B2's residual is 4 channels, not 6.** Slightly better than priced, and
   still not a flip: `graphics_draw_path` has `tolerance 0 / max_outliers 0` and
   is trace-`ruffle_matched` + suite-ignored, so the 98 % band move buys pixel
   board movement only when the 1-sample diagonal tie is also fixed.
3. **`blend_over` was left alone deliberately.** Making the CPU blend round
   globally would touch `copyPixels`, `merge`, `threshold`, `pixelDissolve` and
   the glyph rasterisers — several of which are byte-exact against Ruffle's
   *truncating* CPU path today. The rounding is scoped to the one path that
   emulates a GPU draw. If a future session finds other ±1 residuals on
   GPU-emulating CPU paths, this is the seam.
4. **The canary has no member that exercises any of the three fixes.** No
   standing canary row draws a nested Bitmap through `BitmapData.draw`, renders
   an EditText *selection*, or calls `drawPath`. "29/29 identical" therefore
   proves *no collateral damage*; it proves nothing about the fixes themselves —
   those are carried by the three headline rows plus the 28-row trace/image
   batch. w1 flagged the EditText-selection gap; the other two are new. All
   three candidate additions are CI-passing after this patch and would be
   tier 1: `avm2/bitmapdata_draw_self_via_graphic`,
   `avm2/edittext_always_show_selection` (both now image-PASS at tol 0) and, for
   drawPath coverage, `avm2/graphics_draw_triangles` or `graphics_path`.
5. **Contamination disclosed, not hidden**: two canary rows in the first
   `before` leg were built from patched sources (§3) and were re-run cleanly.
6. **Not taken, per brief**: A3 (filter cxform) and B1 (recompiler
   `opaqueBackground`) belong to w2-gfx-filter-chain; I did not touch
   `tag.c`, `avm2_render_filtered`, or `SWFRecomp/src/swf.cpp`.
7. **Disposition check (rule 2)**: none of the three targets appears in
   `ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`,
   `RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md` or the global
   `ignored_tests.txt`. `graphics_draw_path` carries an
   `avm2/ignored_tests.txt` entry, but as *upstream `known_failure`* (Ruffle
   itself fails it), which the file's own header says is not an accepted diff.
   No disposition doc needs updating for this patch — nothing here is a
   compat tweak or an accepted diff; all three are plain bugs fixed toward the
   Flash/Ruffle goldens.

---

## 6. New unclaimed leads

* **`bd_draw_shape_walk` is still missing arms `avm2_cpu_walk` has.** Now that
  the Bitmap arm exists, the two walks differ in one more way: `avm2_cpu_walk`
  applies `edittext` and `statictext` as **independent `if`s** on top of the
  shape arm, while `bd_draw_shape_walk` chains all of them in one `else if`
  ladder. A node carrying both a shape and a text field renders text on the
  stage but not through `BitmapData.draw`. Cheap to align; no corpus row is
  known to need it (which is why it is a lead, not a fix).
* **`BitmapData.draw` still ignores the source's `blendMode` and
  `colorTransform` for shape/Bitmap subtree sources** (the walk takes neither).
  `bitmapdata_draw_masks` (5 850, w1's C5) needs the `.mask` too. All three are
  the same walk and could be one slice.
* **`drawPath` still does not saturate infinities.** Ruffle's `as i32` maps
  `±inf` to `i32::MIN/MAX`; we now map NaN to 0 but pass ±inf through to the
  tessellator. No corpus row exercises it — worth two lines the next time this
  function is opened.
* **The `graphics_draw_path` 2-pixel residual is a `quality = "low"` 1-sample
  diagonal tie**, the same *class* as the shared 9-pixel 45° tie
  w2-gfx-blend-tie is prototyping. If that agent's world-matrix work lands,
  re-measure this row: 4 → 0 would flip it (and it is `known_failure` upstream,
  so a flip here is a genuine "we beat Ruffle" row).
* **±1 LSB from truncating CPU blends on GPU-emulating paths.** §5.3. A survey
  of which `blend_over` call sites emulate a wgpu draw (rounding) versus
  Ruffle's CPU `operate_ex` (truncating) would price the class; A4 is proof that
  at tolerance 0 the distinction decides flips.
