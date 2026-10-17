# s22 wave 2 — `w2-glyph-subunit` report (slot W2-C of `w1-pixel-smalls-report.md` §2)

**New files: none.** Deliverables: this report and `w2-glyph-subunit.patch`
(`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`,
verified with `git apply --check -R`). Base: `origin/master` `bdf127c35`. Upstream Ruffle tests: master
`45366370e` (2026-10-16), categories `fonts visual avm2 text` + `avm1 from_shumway` (canary members).

## Verdict: **GO — +3 pixel flips, 0 regressions (trace or pixel), 0 trace-status changes**

| test | cmp | before (clean master) | after (patch) | verdict |
|---|---|---|---|---|
| `visual/fonts/glyph` | output | tol0 **3/0**, max 255, FAIL | tol0 **0/0**, max 0, **PASS** | flip |
| `fonts/embed_matching/match_style` | output | tol3 **3/0**, max 255, FAIL | tol3 **0/0**, max 0, **PASS** | flip |
| `fonts/embed_matching/fallback_preferences` | output | tol3 **24/6**, FAIL | tol3 **6/6**, **PASS AT THE LIMIT** (zero headroom) | flip, fragile |

Cloud fidelity: all three *before* renders are **byte-identical (decoded RGBA)** to CI's
`origin/ruffle-image-results` `output.actual.png` (md5 `6bf0926f…`, `ab742833…`, `a69685df…`), so these
are CI-grade absolute verdicts, not A/B only. Trace status on all three: pass → pass.

## EXPECTED-FLIP LEDGER (coordinator: check CI against this)

**Pixel axis (fail → pass):**
- `visual/fonts/glyph` `output` (3 → 0, tol 0)
- `fonts/embed_matching/match_style` `output` (3 → 0, tol 3)
- `fonts/embed_matching/fallback_preferences` `output` (24 → **6 of limit 6**, tol 3). Exactly at the limit: any
  ±1 outlier from a later glyph/text change flips it back. Now a canary member (below).

**Pixel axis, moves that do NOT change a verdict (expect these md5s to change on CI):**
- `text/auto_size/height` pass→pass, outliers 3/3 → **0/3** (gains headroom)
- `text/auto_size/return` pass→pass, 6/18 → **0/18**
- `visual/cache_as_bitmap/oversize/swf_9_masks`, `swf_10_masks` pass→pass, tol64 136/200 → **138/200** (+2,
  62 headroom left; tol128 0/0 unchanged; max diff 127 unchanged). The only move away from golden in the sweep.
- `visual/fonts/font_lookup_as3` fail→fail, 19584 → 19560 /72
- `avm2/stage3d_bitmap` 135413 → 135407, `avm2/stage3d_fractal` 1099378 → 1099377, `avm2/stage3d_texture`
  204784 → 204781 (all fail→fail; these draw TextField overlays)

**Trace axis: no change.** 127 pass + 7 `ruffle_matched` before and after, per test identical (134 tests).

## Mechanism and the landing representation

Owner: `abc_timeline.cpp` `parseGlyphShape` (DefineFont2/3 glyph SHAPEs) and `abc_devicefont.cpp`
`OutlineSink::quadTo`/`cubicTo` (test.toml device faces) `lround`ed every Levien-flattened point back to an
integer font unit. Ruffle never rounds: `render/src/tessellator.rs:387` hands lyon
`Point::new(x.to_pixels() as f32, y.to_pixels() as f32)` and lyon flattens in f32. At a 20480-em face and
~200 px text a 0.5-unit rounding is ~1/256 px, the lavapipe subpixel, which is what flipped the 3 rows
(diagnosis: w1-pixel-smalls report rows 9-11).

**Representation chosen: `float` point arrays** (not the prototype's ×8 fixed point). Why:
- It *is* Ruffle's representation (f32, unrounded); a ×8 or ×N fixed point still quantises (1/8 unit), just
  more finely, and needs a scale constant at every consumer.
- Every SWF/TTF endpoint is an integer well under 2^24, so f32 holds the unflattened points exactly; the
  emitter prints integral values as integers and the rest with 9 significant digits (round-trips any f32).
- **The runtime consumers need no code change.** `avm2_display.c:19016` (`avm2_render_glyphs`) and
  `avm2_bitmap.c:2032` (`glyph_raster_core`) already read `(double) fd->glyph_pts[...]`; only the field's
  type in `Avm2FontData` changes (`avm2_abc.h`: `const int32_t*` → `const float*`). `avm2_text.c:2682,2784,4310`
  only NULL-test the pointer. No other reader exists (`git grep glyph_pts`). So the two sibling-owned runtime
  files are untouched.
- The flattened sample is computed in f32 with lyon's own operation order (`QuadraticBezierSegment::sample`)
  via a new shared `glyphQuadSample` in `abc_glyph_flatten.hpp`, so both pipelines stay identical by
  construction. (Ruffle flattens in pixel space, x/20; we flatten in unit space. Mathematically scale
  invariant; the f32 difference is ~1e-7 relative, far below the raster grid.)
- The CFF-only `cubicTo` path (no corpus face uses it) keeps its double arithmetic and just drops the round.

Patch scope (all in the glyph-outline emission functions, per the sibling map):
- `SWFRecomp/include/abc/abc_glyph_flatten.hpp`: + `glyphQuadSample`, + `glyphEmitPts` (shared emitter).
- `SWFRecomp/src/abc/abc_timeline.cpp`: `FontDef::glyph_pts` → `std::vector<float>`; `parseGlyphShape` keeps f32
  points; `font_N_pts[]` emitted as `float`.
- `SWFRecomp/src/abc/abc_devicefont.cpp`: `DeviceFaceDef::glyph_pts` → float; `OutlineSink` (`cur`, `start`,
  `lineTo`, `quadTo`, `cubicTo`) keeps f32 points; `devfont_N_pts[]` emitted as `float`. The `[default_fonts]`
  emit and face loading (sibling `w2-default-fonts-draw`) are untouched; the only shared hunk is the two-line
  `devfont_N_pts` declaration in the table emitter.
- `SWFModernRuntime/include/avm2/avm2_abc.h`: `glyph_pts` type + comment.
- `ruffle-tests/render_canary_tests.txt`: + `fonts/embed_matching/fallback_preferences` (tier 1, EOF).
  `visual/edittext/edittext_border_filters`, the other row the brief asked to add, **is already a member**
  (s21 addition); not duplicated.

No `swf_core.c` / `tag_stubs.c` / `NO_GRAPHICS` arm touched. AVM1 glyphs (swf.cpp) are untouched, so AVM1
generated code is byte-identical (confirmed: every avm1 canary member md5-identical). Recompiler warning-free.
Generated tables grow (curve points print as e.g. `7475.77637f`); no compile-time change noticeable.

## Sweep (all `--mode=graphics --images --recompile`, `render_canary.py capture` before/after, same box)

134 tests / 150 comparisons = the standing canary (61 incl. the new member) ∪ an argued 80-test text sweep:
- every AVM2 test in `avm2 fonts text visual` that carries DefineFont2/3 or declares test.toml fonts AND has an
  image comparison (43 tests; a superset of the w1 report's 42-test text sweep for the AVM2 side; AVM1 text
  cannot move, see above);
- every AVM2 font-bearing trace test using `textWidth`/`textHeight`/`getCharBoundaries`/`getLineMetrics` (33);
- every AVM2 font-bearing trace test whose ABC names `draw`/`getPixel`/`hitTest` (5), the only way an outline
  could reach a trace.
Result: **139 IDENTICAL, 11 DIFFERS** (all listed in the ledger above), image pass 126 → 129, fail 22 → 19,
0 pass → fail, 0 trace changes. Metric tests are unaffected by construction (metrics come from advances and
ascent/descent, never from `glyph_pts`) and measured unchanged.

Standing canary (61 members, inside the 134): md5-identical except `fallback_preferences`, the new member
(a ledger row). Everything else the canary covers is untouched.

Regression suite: `regression/avm2_bitmapdata_draw_textfield` (draws a TextField through `glyph_raster_core`)
and `regression/avm2_timeline_text`: PASS in both `--mode=graphics` and no-graphics, `--recompile`. The canary's
`regression/*` members are md5-identical. No new fixture: the behaviour is covered by three upstream rows whose
expected output comes from Ruffle/Flash, so no in-repo oracle is needed.

## Refutations / premise checks
- Premise "the 3 rows are one mechanism": confirmed; the single change flips all three with nothing else.
- Premise "fallback_preferences passes at the limit 6/6": confirmed exactly (6/6) with the float representation,
  the same count the w1 ×8 prototype reported. Finer precision (f32 vs 1/8 unit) does not reduce it, so the
  remaining 6 outliers are most likely not glyph-point quantisation.

## Not finished / completion mechanisms
- Nothing in scope left. The AVM1 analogue (row 14 of the w1 report: `morph_test1` ×5 + `Video-EmbedSquareTest`,
  and `edittext_scroll .02`) lives in `swf.cpp`'s AVM1 glyph shapes and device-font synth, which siblings own;
  completion = the same "no rounding of flattened glyph points" change in the AVM1 glyph path (s23 slot).

## New unclaimed leads
- `fallback_preferences` 6 residual outliers at tol 3: probably not glyph quantisation (same count at ×8 and
  f32); next suspect is the fallback-face glyph placement (advance/pen rounding).
- `swf_9_masks`/`swf_10_masks` +2 tol-64 outliers: text inside an oversize cacheAsBitmap mask; harmless now
  (62 headroom) but the only sweep row that moved away from golden.

## LOCAL ORACLE REQUESTS
none
