# EmbeddedFontTest Plan
<!-- TESTS: misc-ming.all/EmbeddedFontTest -->

Last updated: 2026-05-23 (RESOLVED → `ruffle_matched`. Root cause was
not graphics precision or missing tag parsing — it was a missing
matrix-linear-part multiply on the DefineEditText bounds offset in
the textfield `_x`/`_y` getters. Our diff against `output.txt` was
{6,7,13,14,20,21,24,27,28,31,34,35,38,41,42,45,48,49,52,55,56,59,
62,63,66,69,70,74,76,77,81,83,84,85,86} — Ruffle's was the same
without the ours-only 24/31/38/45/52/59/74/81 cluster. After the fix
those 8 lines flip to PASSED and our diff is {6,7,13,14,20,21,27,28,
34,35,41,42,48,49,55,56,62,63,66,69,70,76,77,83,84,85,86} ⊆ Ruffle's
— auto-promotes. See "Fix landed" below.)

Last updated: 2026-05-19 (graduated from REMAINING_TAIL_TRIAGE
"EmbeddedFontTest" entry, originally clustered with DrawingApiTest
as "graphics precision")

<!-- PLAN_META
id: EMBEDDEDFONTTEST_PLAN
status: complete
phases:
  - id: 1
    name: "Diagnose: identify which assertions are FP-precision vs feature gaps"
    status: completed
  - id: 2
    name: "Apply placement-matrix linear part to textfield bounds offset in _x/_y getters"
    status: completed
  - id: 3
    name: "Glyph advance / kerning FP precision (round-trip through float)"
    status: not_actionable (shared with Ruffle, inside Ruffle's diff set)
dependencies: []
related:
  - id: TEXTFORMAT_V8_PLAN
    reason: "Phase 2 of TEXTFORMAT_V8 covers similar font-metric precision (ascent/descent/width). EmbeddedFontTest may share root cause."
  - id: DEVICE_FONT_RENDERING_PLAN
    reason: "AVM1 plan (complete) — device font infrastructure. EmbeddedFontTest uses *embedded* fonts (DefineFont tags), not device — so the AVM1 work may not transfer directly."
blockers: []
status_note: |
  REMAINING_TAIL_TRIAGE clustered this with DrawingApiTest as
  "graphics precision (float/double round-trip)". May overlap with
  `attachMovieLoopingTest`'s 15.0000001716614 pattern. Specific
  failing lines need fresh diagnosis to separate "embedded-font
  tag parsing incomplete" from "glyph-metric float drift".
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-ming.all/EmbeddedFontTest | 51/87 | 58.6% | output_mismatch |

After fix (2026-05-23, pending CI): **`ruffle_matched`**.

## Fix landed (2026-05-23)

Two parallel changes in
`SWFModernRuntime/src/actionmodern/action.c::actionGetMember` MOVIECLIP
arm: the `_x`/`_y` getters were adding the DefineEditText `bounds_xmin`/
`bounds_ymin` offset directly to the placement matrix's tx/ty, ignoring
the placement's linear-part scale. Flash treats `_x`/`_y` of a TextField
as the bounds origin point transformed to parent space, so the local-twips
bounds offset must be multiplied by the matrix's linear part before being
added.

Test source: `SWFDisplayItem_moveTo(it, 50, y) + SWFDisplayItem_scale(it,
16, 1)` for tf3..tf7. Ming's `setBounds(80, 16)` emits DefineEditText with
bounds `(-40, 1640, -40, 360)` twips (-2 px padding on min). For tf3:
- Pre-fix: `_x = tx/20 + bxmin/20 = 50 + (-2) = 48`. Expected 18.
- Post-fix: `_x = (m00*bxmin + m01*bymin + tx) / 20 = (16*(-40) + 0 + 1000) / 20 = 18`. ✓

Mirrors Flash's local→parent transform applied to the bounds origin. For
the simple case (no rotation/skew, m01=m10=0), the formula collapses to
`tx/20 + m00*bxmin/20`. The fix uses the full m00/m01 (for `_x`) and m10/m11
(for `_y`) for correctness under arbitrary placement matrices.

Two clusters of 8 ours-only diff lines clear together: tf4-tf9 `_x = 18/34`
(scale 16x and 8x) and tf11/tf12 `_y = 322/404` (scale 4y/8y). The remaining
~27 lines (textWidth measurements, tf10._x precision) are Ruffle-shared
(glyph-metric divergence from Flash's bundled font — both we and Ruffle
substitute a different font in headless mode).

Verified no regressions: 20-test AVM1 TextField/MC battery (textfield_props_*,
clone_sprite_edittext*, edittext_default_format, movieclip_state_values,
movieclip_setmask, display_object_properties, transform, as_transformed_flag,
movieclip_create_text_field, etc.) all PASS. 5-test misc-ming text battery
(DefineEditTextTest, DefineEditTextVariableNameTest*, DefineTextTest,
EmbeddedFontTest) all effective-pass.

## Approach

The test loads SWFs that embed custom fonts via DefineFont/DefineFont2/
DefineFont3 tags + DefineFontAlignZones, then renders text using
those fonts and asserts on `textWidth`, `textHeight`, character
advance, kerning offsets.

Three possible root causes for the residual 36 lines:

1. **DefineFont3 / DefineFontAlignZones not fully parsed.** Newer
   font tags carry alignment zones for high-quality rendering. If
   we skip them, character positions drift. Diagnostic: enable
   verbose recompiler logging and grep for unhandled tag warnings.

2. **Float round-trip pattern.** As with `attachMovieLoopingTest`'s
   `15.0000001716614 vs 15.0`, our internal twips-to-pixels
   conversion takes a round-trip through float that Flash does in
   double. Verify by checking specific failing-line numeric values
   against twips-exact representations.

3. **Glyph table interpretation.** DefineFont glyph table format
   varies between v1/v2/v3 (different bit-encodings). A subtle bug
   in v2 parsing produces correct glyphs but slightly wrong advance
   widths.

## Recommended fix order

1. **Phase 1 (diagnose)** — run `verify_output.py --test=EmbeddedFontTest
   --diff --verbose` and categorize each failing assertion. 1-2 hours.
2. **Phase 2 OR 3** — based on Phase 1 diagnosis. Estimate: 2-4
   hours.

Total estimate: 3-6 hours, 1-2 sessions.

## Promotion plumbing

Test has `known_failure = true` + `output.ruffle.txt` sidecar.
Subset-match auto-promotes if our diff lands inside Ruffle's.
Diagnosis Phase 1 should also include a diff against
`output.ruffle.txt` to determine if we're already subset-eligible
without code changes.
