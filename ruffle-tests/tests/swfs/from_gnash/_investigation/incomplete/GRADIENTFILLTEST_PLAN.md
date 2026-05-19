# GradientFillTest Plan
<!-- TESTS: misc-ming.all/GradientFillTest -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproduction at the current `master` SHA)

<!-- PLAN_META
id: GRADIENTFILLTEST_PLAN
status: pending
phases:
  - id: 1
    name: "Gradient color sampling precision — off-by-small-amount across all sample points"
    status: pending
  - id: 2
    name: "Linear vs radial gradient interpolation modes"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac)."
related:
  - id: CPU_GRADIENT_RASTERIZER_PLAN
    reason: "AVM1 plan (complete) — covers most gradient rendering precision. The Gnash test's color values differ slightly from ours despite that work."
  - id: DRAWING_API_RENDERING_PLAN
    reason: "AVM1 plan (complete) — gradient outliers reduced 80-86%. This Gnash test likely runs into the residual after that fix landed."
blockers: []
status_note: |
  Test exercises beginGradientFill with multiple stop arrangements
  and samples pixel colors via BitmapData.getPixel after rendering.
  Our pixel values are off by very small amounts (8d→d0 hex = 13
  decimal, b→d = 2 decimal, 7f→81 = 2 decimal) across all sample
  points — consistent low-bit drift suggests gamma-correction,
  sRGB-vs-linear, or stop-position interpolation precision issue.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-ming.all/GradientFillTest | 119/278 | 42.8% | output_mismatch |

## Failure surface

The test renders multiple beginGradientFill configurations and
samples pixel colors at fixed grid points via BitmapData.getPixel.
Sampled colors are systematically off by small amounts:

```
- 0xb0bff,0xb0bff,0xb0bff,0x7f7fff,0x7f7fff,0x7f7fff,0xf4f4ff,0xf4f4ff,0xf4f4ff
+ 0xd0dff,0xd0dff,0xd0dff,0x8181ff,0x8181ff,0x8181ff,0xf5f5ff,0xf5f5ff,0xf5f5ff

- 0xff,0x5a5aff,0xfffdff,0x5a5aff,0xffffff,0xff59ff,0xffffff,0xff59ff,0xff00ff
+ 0xff,0x5e5eff,0xfff9ff,0x5e5eff,0xfff9ff,0xff56ff,0xfff9ff,0xff56ff,0xff00ff
```

The off-by-small-amount pattern is uniform (low byte ± few units)
which is the classic signature of:
- sRGB vs linear-RGB interpolation mismatch
- Per-stop color quantization (gradient ramp baked at insufficient
  precision)
- Off-by-half-pixel sample offset

## Approach

1. **Phase 1 diagnosis.** Look at the AVM1 movieclip_begin_gradient_fill
   pre-fix (the one that reduced outliers 86%) and check whether the
   same ramp-precision work applies to the SWF DefineShape gradient
   path used by GradientFillTest (the test uses Drawing-API
   `beginGradientFill`, which is one of the two gradient paths).

   The AVM1 fix three bugs:
   (a) focal type upgrade applied to linear gradients — verify
       we're not applying it to GradientFillTest's linear stops
   (b) varToDouble garbage for string args — irrelevant here
   (c) linearRGB ramp stored in sRGB — possible if the test mixes
       linear and sRGB gradients

2. **Phase 2.** If Phase 1 doesn't account for the residual, look
   at the radial-gradient block (sample points 26-onward in the
   diff show different drift pattern from the linear block at 16-25),
   suggesting radial-mode interpolation might use a slightly
   different precision.

Estimate: 2-3 hours diagnosis + 1-2 hours fix.

## Promotion plumbing

Test has `known_failure = true` + `output.ruffle.txt`. At 43%
line-match, substantial work needed. Diff against
`output.ruffle.txt` is worth checking — Ruffle's CPU gradient
rasterizer is the reference but may itself diverge from Flash on
this specific test, which would make us subset-eligible.
