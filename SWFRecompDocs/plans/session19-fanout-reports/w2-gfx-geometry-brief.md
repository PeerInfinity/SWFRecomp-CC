# w2-gfx-geometry: curve bounds, drawRoundRect, LINESTYLE2 caps/joins

Read `BRIEFS_COMMON.md` (wave-2 section included), then `w1-gfx-geometry-report.md`. That report is
your diagnosis of record and its numbers were measured locally (it cross-checked local Dawn against
the CI board on every row it could). Re-verify before/after yourself. Worktree agent: nothing
commits, you deliver patches. **Deliver separate patch files per item** so they can land as
separate commits.

## Scope
**G1 (+1 flip, `w2-gfx-geometry-1-curvebounds.patch`).** `avm2/displayobject_getbounds_shape`
19 086 → 3 716 PASS (limit 3 800). AVM2 `curveTo` folds the raw CONTROL POINT into shape bounds,
where Ruffle folds the curve's extrema (`quadratic_curve_bounds`). **The margin is thin** (residual
is stroke ties), so state the measured number, and if it lands above the limit, say so rather than
calling it a flip. Trace risk named by the report: `avm2/displayobject_getrect` (already failing
11/16 — must not move) and `bounds_mode` (clean today).

**G2 (0 flips alone, big band moves, `-2-roundrect.patch`).** `Graphics.drawRoundRect` and
`drawRoundRectComplex` currently draw a plain rect. The report ported Ruffle's
`draw_round_rect_internal` and measured `graphics_simple_shapes` 230 → 154,
`graphics_gradients` 469 → 349, `graphics_bitmaps` 1057 → 959, `acid-shapes` −660. Only 5 corpus
SWFs call it. Land it for the band moves and the correctness; do not claim flips.

**G3 (unmeasured, mechanism-matched, `-3-linestyle2.patch`).** LINESTYLE2 caps/joins: exactly 5
corpus SWFs declare non-round styles. Flip candidates: `visual/simple_shapes/layers` (23 channels,
11 px, all "Ruffle inks a corner we leave empty" = square cap / miter) and
`blend_across_masks_issue_24549` (6 channels, our round cap overshoots a butt cap).
**`visual/simple_shapes/acid-small` passes today WITH the wrong styles and is your tripwire** — if
it moves, you have changed more than the declared styles.

**G4, optional and only if the above are done and verified (`-4-evenodd.patch`).** The report's top
new lead: Ruffle keeps ONE even-odd fill across `lineStyle()` changes, while we flush the path per
style, so overlapping subpaths stop cancelling. That owns 152 of `graphics_simple_shapes`' 154
remaining channels. It is a real fill-rule change with a wide blast radius — treat it as a probe,
and deliver a HOLD with evidence if it is not clean.

## Explicitly OUT of scope (refuted or reassigned — do not revisit)
- **`blend_modes` ×12: NO-GO.** s18's "integer-twip truncation in `addCurvedEdgeLevien`" completion
  mechanism is refuted — with float vertices, add goes 5 → 6 and multiply 16 → 13, and the failing
  pixels MOVE to a new set of the same size (a 1-sample edge-tie population). Do not fund the
  recompiler A/B sweep.
- **`bitmapbuttons`: HOLD**, and not a `0x43`/pool/shader bug — `swf.cpp:10709` marks every
  bitmap-filled shape `renderable = 0` so the AVM2 walk skips it. Feature slice, not this one.
- **`bd_copy_pixels`/`bd_threshold` rect clamping**: reassigned to **w2-bitmapdata**, which already
  owns that function. Do not touch `avm2_bitmap.c`.
- `morph_test1` is text (handed to the text agent); `captions` is text, not round-rect.

## Required checks
- Headlines both ways with `--mode=graphics --images`; CI PNGs in `<scratchpad>/image-results/` are
  the absolute verdict, local renders are for A/Bs.
- G1: the AVM2 bounds/getRect families on BOTH axes (a bounds change moves traces too).
- G2/G3: the shapes/strokes families (`visual/simple_shapes/*`, `avm2/graphics_*`,
  `from_shumway/acid/*`), with `acid-small` as the tripwire.
- The **render canary** for every patch, plus the `regression` suite.

Siblings: **w2-bitmapdata** owns `avm2_bitmap.c`; **w2-gfx-text** owns `avm2_text.c` and
`abc_timeline.cpp`. Name the files and functions you touched in your final message.
