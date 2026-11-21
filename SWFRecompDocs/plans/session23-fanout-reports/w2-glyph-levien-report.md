# w2-glyph-levien: device-font glyph synth, Levien flattening + float vertices (session 23 wave 2)

**New files:**
- `SWFRecompDocs/plans/session23-fanout-reports/w2-glyph-levien-report.md` (this report)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-glyph-levien.patch`

**Patch:** `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`.
Base is `origin/master` `aa219e57` (it contains `7e2a045c1`, mechanism A + line pitch). It touches 2 files:
- `SWFRecomp/src/swf.cpp`
- `ruffle-tests/render_canary_tests.txt` (3 members appended at EOF)

It does not touch the runtime, the `tag.c` hunk, `verify_output.py` or any fixture. It is proven with `git apply --check -R` on the branch.

**Box:** `SETUP_STATUS` all OK; Dawn on lavapipe. The upstream corpus is from `download_tests.sh visual avm1 avm2 from_gnash from_shumway text fonts`
(Ruffle master on 2026-11-21, the `0ddd12b6a` era; 2923 tests installed). Every run used `--mode=graphics --recompile`.

## Verdict: GO. 7 pixel flips, 0 pass→fail, 0 trace-status changes, exactly the brief's ledger

| test | before (master) | after | budget | verdict |
|---|---:|---:|---:|---|
| `visual/filters/glow` | 3 | **0** | 0 | **FLIP** |
| `visual/filters/glow_without_composite_source` | 3 | **0** | 0 | **FLIP** |
| `visual/filters/drop_shadow` | 3 | **0** | 0 | **FLIP** |
| `visual/filters/bevel_inner` | 42 | **18** | 18 | **FLIP** (zero headroom) |
| `visual/filters/bevel_outer` | 42 | **18** | 18 | **FLIP** (zero headroom) |
| `visual/filters/bevel_full` | 42 | **18** | 18 | **FLIP** (zero headroom) |
| `visual/filters/glow_with_alpha_strength` | 42 | **18** | 18 | **FLIP** (zero headroom) |

**The 4 zero-headroom rows:** `bevel_inner`, `bevel_outer`, `bevel_full` and `glow_with_alpha_strength` land at exactly **18/18**. That is
6 pixels × 3 channels of Ruffle-side sub-snap ties, w1-filter-label §3. They pass, but any later 1-pixel move in the zero-glyph `_sans`
labels fails them again. `bevel_inner` is now a canary member (below), so such a move shows up as an md5 change.

### Fidelity (CI-grade)

The before-renders of all 7 headline rows are **byte-identical** (decoded-RGBA md5) to CI's actual PNGs on `origin/ruffle-image-results`.
That ref is `35f66723a`, written by images run **`38995363802`** (s22 final). The s23 baseline run `44922638965` had **not** force-pushed that
branch when I fetched it, so I compared against `38995363802`.

| row | CI actual = local before |
|---|---|
| glow | 5f815768 |
| glow_without_composite_source | 3693aec3 |
| drop_shadow | 0f8c13df |
| bevel_inner | 390d3848 |
| bevel_outer | 45abf19c |
| bevel_full | 185879de |
| glow_with_alpha_strength | 13b5129f |

The CI images predate `7e2a045c1`. These rows are md5-identical under A (w1-glyph-precision measured that, and I re-confirmed it here),
so the comparison holds on current master.

## EXPECTED-FLIP LEDGER (the coordinator checks CI against this)

**Pixel axis, fail → pass:**
- `visual/filters/glow`
- `visual/filters/glow_without_composite_source`
- `visual/filters/drop_shadow`
- `visual/filters/bevel_inner`
- `visual/filters/bevel_outer`
- `visual/filters/bevel_full`
- `visual/filters/glow_with_alpha_strength`

**Pixel axis, md5 moves on passing rows** (expected; none should fail):

| row | check | before | after | note |
|---|---|---:|---:|---|
| `from_shumway/avm1/text-bind` | t64 | 592/600 | **587/600** | headroom 8 → 13 |
| `from_shumway/avm1/text-bind` | t128 | 80/100 | **85/100** | headroom 20 → 15 |
| `visual/cache_as_bitmap/text` | t128 | 1200/1500 | **1257/1500** | headroom 243 |
| `visual/cache_as_bitmap/text` | t0 | 11055/12000 | 11058/12000 | |
| `visual/cache_as_bitmap/edittext_scroll` | `output.01` | 2/5 | **0/5** | headroom regained |

`edittext_scroll` `output.02` stays 0/5, md5-identical.

**Pixel axis, md5 moves on failing rows** (still failing; both move toward golden):
- `visual/filters/bevel`: 744 → **738** (budget 6)
- `visual/text/String_path_variable_button`: 1002 → **999** (budget 12)

**Trace axis:** no change. All 85 sweep tests keep their trace status. The 34 trace-only zero-glyph tests stay at 30 pass,
2 ruffle_matched (`bounds_mode`, `getobjectsunderpoint`) and 2 output_mismatch (mixed-AVM). Every status agrees with
`origin/ruffle-test-results` (`b3b80ea9`) wherever that ref has the row.

**Everything else: md5-identical** (proof of completeness below).

## 1. The change (owner `SWFRecomp/src/swf.cpp`)

1. **Code motion.** The Levien block (`LEVIEN_TOL_TWIPS`, `LevienParams`, `levienParabolaIntegral`/`InvIntegral`, `levienInit`, `levienT`) and its
   comment header move from just before `addCurvedEdgeLevien` to the top of `namespace SWFRecomp`. Nothing else in the block changes; one comment
   line now names the glyph synth as a second user.
2. **Glyph loop** (zero-glyph synth plus the env-gated device-font fallback):
   - Contour points are `std::array<double,2>` holding the exact `verts * ttf_scale` value. They are no longer truncated with `(Coord)`.
   - Quads are flattened with `levienInit(p0, c, p1, 0.1f)` in `font_units/20` (via `(float)((double)u/20.0)`, as `Twips::to_pixels`). The
     start point is `verts[v-1]`, the previous outline point in font units. Each sample is scaled by `20·ttf_scale`. This replaces the fixed 6
     equal steps.
   - Contour vertices are `lround` plus `fx_frac`/`fy_frac` via `vertexFrac`, then `tessellateContours(..., /*keep_float=*/true)`.
   - Triangles are emitted as `x + fx_frac/VERTEX_FRAC_SCALE` (16384).
   - The cubic branch (CFF faces only; Noto is TrueType, so never hit) keeps 8 equal steps, now unquantized.
   - Path data (`emitGP`, used for hit testing) is unchanged.
3. **Deleted:** both measurement toggles (`SWFRECOMP_GLYPH_FLOAT`, `SWFRECOMP_GLYPH_LEVIEN`). I wrote the prototype's odd
   `glyph_prev_fu_*` for-increment as a plain `verts[v-1]` read; it reads the same point. The quad branch's unused `x0`/`y0` are removed.
   The `keep_float` doc comment no longer claims "glyph outlines keep the historical integer round trip".

I did not re-apply the prototype's `tag.c` hunk; `7e2a045c1` supersedes it.

## 2. Sweep and scope proof

**Sweep.** I scanned every `test.swf` in the 7 downloaded categories:
- named DefineFont2/3 with 0 glyphs: **48 tests** (14 image-graded, 34 trace-only);
- image-graded `DefineEditText` without a zero-glyph font: **37 tests**.

That is the report's 51 image-graded tests, plus the 34 trace-only ones, so 85 tests in all. Both legs ran on this box against the same
runtime, with only the recompiler binary swapped (before = `origin/master` build, after = patch build). 93 image comparisons were graded with
`verify_output.compare_images`:
- 81 are md5-identical;
- 12 moved: the ledger above.

**Generated-C proof over the whole corpus.** Both recompiler binaries ran on all **2923** `test.swf` in the 7 categories. Each binary sat next to
`SWFRecomp/assets/`: the synth finds `NotoSans.ttf` relative to the executable, so a binary copied elsewhere silently skips it.
- `RecompiledTags`/`RecompiledScripts` differ in exactly **48** tests.
- That set equals the zero-glyph set (both set differences are empty).
- The other **2875** are byte-identical.

The runtime is untouched, so a test with identical generated C renders identically.

**Canary.** 6 of the 90 standing canary members are in the changed set, and all 6 were rendered A/B in the sweep:
- `text-bind` and `cache_as_bitmap/text` (ledger moves);
- `edittext_scroll` (`.01` moves, `.02` identical);
- `bevel_inner`, `drop_shadow`, `glow` (ledger flips).

The other 84 members (78 corpus members plus the 6 `regression/` members) have identical generated C. The `regression/` suite has no
zero-glyph font (scanned). I did not run the full `render_canary.py` capture: on an unchanged runtime with identical generated C its md5
verdict is already determined.

**Regression suite.** `regression/avm1_parent_child_text` (AVM1 EditText) passes after the change in graphics mode (0 outliers) and in
no-graphics mode.

**Mode parity.** I touched no `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arm. The patch changes only glyph triangle data; no-graphics trace
is unaffected, as the regression fixture shows.

## 3. Attribution of the prototype's wrong-way moves (task 3)

The prototype under A+B moved four rows away from golden: `acid-text` 5019→5040, `place_object_test` +63, `shape_test` +42 and
`br_at_start` +3. **B contributes exactly 0 to each.**
- None of the four SWFs has a zero-glyph font (scan), and their generated C is byte-identical under this patch.
- Their after-renders are md5-identical to master:

| row | master (before) = after | md5 |
|---|---:|---|
| `shape_test` | 15994 | b1a76afc |
| `place_object_test` | 38238 | 2f3669eb |
| `acid-text` | 3429 | d1b8101e |
| `br_at_start` | 1672 | ce2deb10 |

**The moves came from the prototype's A hunk running without the line-pitch hunk.** Master's number plus the pitch hunk's measured move
(w1-glyph-precision §1: −1959, −3699, −2012) reproduces the prototype's A+B numbers exactly:

| row | master + pitch move | = prototype A+B |
|---|---|---:|
| `shape_test` | 15994 + 1959 | **17953** |
| `place_object_test` | 38238 + 3699 | **41937** |
| `br_at_start` | 1672 + 2012 | **3684** |

`acid-text` was only measured with both hunks, so it cannot be split the same way. It is equally untouched by B: md5-identical, and no
zero-glyph font.

On master with A and the pitch, these rows sit toward golden, and B leaves them there.

## 4. Headroom (task 4): no HOLD

| row | check | after | budget | headroom |
|---|---|---:|---:|---:|
| `from_shumway/avm1/text-bind` | t64 | 587 | 600 | 13 |
| `from_shumway/avm1/text-bind` | t128 | 85 | 100 | 15 |
| `visual/cache_as_bitmap/text` | t128 | 1257 | 1500 | 243 |
| `visual/cache_as_bitmap/text` | t0 | 11058 | 12000 | 942 |

All pass. `text-bind` is still the tightest device-font row, and it is already a canary member.

## 5. Canary members appended (task 5)

Appended at EOF of `ruffle-tests/render_canary_tests.txt`, in the file's `suite/test  # comment` format, under a `# tier=1` marker:
- `visual/filters/bevel_inner`
- `visual/simple_shapes/text_field_mask`
- `from_shumway/acid/acid-text-escape`

All three pass on master + patch:
- `bevel_inner` 18/18;
- `text_field_mask` and `acid-text-escape` 0/0 (flipped by `7e2a045c1`, md5-identical under this patch).

## 6. Lead 2 priced (embedded DefineFont glyphs, `abc_devicefont.cpp`): **0 flips. REFUTED: neither has the integer round trip**

- **Embedded DefineFont2/3 glyphs (AVM1 and AVM2 timeline).** These go through the shape pipeline. `addCurvedEdgeLevien` flattens at
  `LEVIEN_TOL_TWIPS` = 2 twips (lyon 0.1 px at scale 1) and keeps the sub-twip remainder in `fx_frac`/`fy_frac`. The shape tessellator is
  called with `keep_float = true` (`swf.cpp` `tessellateContours(g.contours, winding_rule, tris, true)`).
  - The "historical integer round trip" comment was about this synth only, which is why I rewrote it.
- **AVM2 device-font emitter `abc/abc_devicefont.cpp`.** `OutlineSink` truncates TTF points with `(int32_t)`, which is Ruffle's own
  `GlyphToDrawing` `x as i32`, and a no-op on integer TTF units. It flattens quads with `glyphLevienInit(..., GLYPH_LEVIEN_TOL = 2.0)` in raw
  font units, and the flattened points stay f32 and unrounded.
  - Levien's chord count is scale-invariant when the tolerance scales with the geometry. `scale` ∝ s, the parabola parameters are invariant
    and `is_linear` is homogeneous, so 2.0 in font units gives the same schedule as this patch's 0.1 in `font_units/20`, up to f32 rounding of
    sample points.
- Nothing is left to port on either path. Lead 2 is closed.

## Not finished / HOLDs

None. Items carried forward:
1. **The 6 residual bevel pixels** (w1-filter-label §3, lead 1): bit-exact lyon fill flattening order. It buys headroom only on the 4
   zero-headroom rows. Completion mechanism: replicate lyon's event-queue downward swap of each quad, then re-measure the same 4 rows.
2. **The zero-glyph synth's cubic branch** still uses equal steps. It is unreachable with the shipped TrueType Noto. If a CFF `[fonts.*]` face
   is ever configured, port lyon's cubic flattening there.

## New unclaimed leads

- None new. (Lead 3 of w1-filter-label, selection and caret metrics after A, was folded into `7e2a045c1`.)

## LOCAL ORACLE REQUESTS

None. All headline verdicts were graded on renders md5-identical to CI.
