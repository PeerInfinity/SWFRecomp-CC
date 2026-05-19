# EmbeddedFontTest Plan
<!-- TESTS: misc-ming.all/EmbeddedFontTest -->

Last updated: 2026-05-19 (graduated from REMAINING_TAIL_TRIAGE
"EmbeddedFontTest" entry, originally clustered with DrawingApiTest
as "graphics precision")

<!-- PLAN_META
id: EMBEDDEDFONTTEST_PLAN
status: pending
phases:
  - id: 1
    name: "Diagnose: identify which assertions are FP-precision vs feature gaps"
    status: pending
  - id: 2
    name: "DefineFont3 / DefineFontAlignZones tag support (if needed)"
    status: pending
  - id: 3
    name: "Glyph advance / kerning FP precision (round-trip through float)"
    status: pending
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
