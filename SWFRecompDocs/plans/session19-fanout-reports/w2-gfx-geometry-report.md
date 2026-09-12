# w2-gfx-geometry — wave-2 implementation: curve bounds, drawRoundRect, LINESTYLE2 caps/joins

> **ADDENDUM (post-landing).** The grading run `34657699925` at `f48c532bf` showed
> `visual/edittext/edittext_caret_empty` ×11 going pass → fail, provisionally attributed to my
> LINESTYLE2 patch. It is **UPSTREAM DRIFT, not a regression**: ruffle `0fa6a04af` (2026-09-06)
> tightened that test's tolerance 128 → 64 and changed no golden, while our render is byte-identical
> at the session base `e36bca73e` and at current master. No fix patch is delivered. Full evidence,
> the 12-comparison ledger, a re-verification of my three flips at master, and the handoff for the
> real (pre-existing) EditText-border gap:
> **`w2-gfx-geometry-4-caret-adjudication.md`**.

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a27b4023df67469a5` (base `e36bca73e`).
No commits, no pushes. Everything below was measured in that worktree with the locally built
recompiler, local Dawn, `--mode=graphics --images`, `SWFRECOMP_COMPILE_TIMEOUT=2400`, never more
than two test processes at once. Scratch: `<scratch>/w2-gfx-geometry/`.

## Deliverables (three independent patches, apply in order)

| # | patch | files touched |
|---|---|---|
| 1 | `w2-gfx-geometry-1-curvebounds.patch` | `SWFModernRuntime/src/avm2/avm2_display.c` (new static `draw_union_quad`, `gfx_curve_to`) |
| 2 | `w2-gfx-geometry-2-roundrect.patch` | `SWFModernRuntime/src/avm2/avm2_display.c` (new statics `GFX_UCP`, `gfx_emit_round_rect`, `gfx_draw_round_rect`; `gfx_draw_round_rect_complex`; the `drawRoundRect` registration) |
| 3 | `w2-gfx-geometry-3-linestyle2.patch` | `SWFRecomp/include/swf.hpp`, `SWFRecomp/src/swf.cpp` (`parseLineStyles`, `drawLineJoin`, `drawLineCap`, `SWF::drawLines` + its one call site), `ruffle-tests/render_canary_tests.txt` |

**No new files.** Nothing is added to `verify_output.py`'s source list, CMakeLists or the Emscripten
build. Patches 1 and 2 are runtime-only; patch 3 requires a recompiler rebuild **and** `--recompile`.

Each patch was verified to apply cleanly in sequence onto `e36bca73e` and to reproduce the final
tree byte-for-byte (`git apply -R` the combined diff, re-apply 1 then 2 then 3, `diff` the result).

---

## 1. Verdicts and priced flips

| item | comparison | before → after | verdict |
|---|---|---|---|
| **G1** | `avm2/displayobject_getbounds_shape` [output] | 19 086 → **3 716, PASS** (limit 3 800) | **GO — FLIP, margin 84 channels** |
| G1 | `avm2/displayobject_getrect` [trace] | 11/16 → 11/16 | unchanged (still `output_mismatch`) |
| G1 | `avm2/bounds_mode` [trace] | `ruffle_matched` 263/269 → identical | unchanged |
| **G2** | `avm2/graphics_simple_shapes` | 230 → **154** | GO, no flip (−33 %) |
| G2 | `avm2/graphics_gradients` | 469 → **349** | GO, no flip (−26 %) |
| G2 | `avm2/graphics_bitmaps` | 1 057 → **959**, PASS → PASS | GO, margin gained |
| G2 | `avm2/graphics_draw_path` | 4 → 4 | unchanged |
| **G3** | `visual/blend_across_masks_issue_24549` | 6 → **0, PASS** | **GO — FLIP** |
| G3 | `visual/simple_shapes/layers` | 23 → 23, PNG **byte-identical** | **w1's flip prediction REFUTED (§4)** |
| G3 | `from_shumway/acid/acid-small` (tripwire) | 25 989 / 25 959 → **byte-identical md5** | tripwire GREEN |
| G3 | `from_shumway/gradientTransform` (KF) | 9 → 9, byte-identical | unchanged |
| — | `visual/drawing_api/fills_and_lines` | 4 → 4 | unchanged |
| **G4** | even-odd single fill across `lineStyle` | — | **HOLD, and w1's mechanism is half wrong (§5)** |

**Priced flips delivered: 2, both measured, both on the image axis** —
`avm2/displayobject_getbounds_shape` (patch 1) and `visual/blend_across_masks_issue_24549`
(patch 3). Patch 2 delivers 0 flips but three band moves and the correctness of a previously
unimplemented API.

The brief priced G3 at two flip candidates. One of the two is refuted on evidence (§4), so the
honest count for patch 3 is **one** flip.

---

## 2. G1 — curve bounds fold the extrema, not the control point

`avm2_display.c::gfx_curve_to` called `draw_union_stroke()` on the raw CONTROL point and then on
the anchor. Ruffle's `Drawing::add_command` → `stretch_bounds` → `shape_utils::quadratic_curve_bounds`
solves for the quadratic's own turning parameter `t = (from − ctrl)/(from − 2·ctrl + anchor)`
(clamped to 0..1) and folds the point AT that parameter; the control point only decides whether the
axis is examined at all. Both of Ruffle's boxes come from the same routine — `shape_bounds` with the
stroke width, `edge_bounds` with `Twips::ZERO` — which is what the new `draw_union_quad` reproduces
(`draw_union_shape_tw` ± half-width, `draw_union_edge_tw` raw).

Independent confirmation before any code was written, straight from the CI PNGs
(`<scratch>/image-results/.../displayobject_getbounds_shape/output.actual.png`): the SWF draws its
own `getBounds` rectangle, ours spans `x 30..249` (clipped by the 250-px stage) `y 30..369`,
Ruffle's `x 30..203` `y 30..370`. The 46-px right band is the control-point overshoot.

**Margin is thin: 3 716 against a limit of 3 800, 84 channels.** The residual is stroke-outline ties
along the squiggle (round-join fan resolution / curve flattening), a different mechanism. If a later
change moves those ties the row can fall back out; it is not a padded pass.

Left deliberately untouched (they are separate, unmeasured changes):
- `gfx_cubic_curve_to` still unions both control points. Ruffle uses lyon's tight `cubic_curve_bounds`.
- The AVM1 twin in `action.c` (`drawingUpdateBounds`) also unions the control point but uses FULL
  thickness per side on purpose (validated Flash divergence). **Do not fold the two.**

---

## 3. G2 — `drawRoundRect` / `drawRoundRectComplex` were a plain rect

`gfx_draw_rect` was registered for `drawRoundRect` and `drawRoundRectComplex` forwarded to it, so
every corner radius in the corpus was silently dropped. Patch 2 ports Ruffle's
`draw_round_rect_internal` verbatim: the five-entry `UNIT_CIRCLE_POINTS` table (including Ruffle's
own asymmetric `0.4142…` / `6.12e-17` literals), the start at the MIDDLE of the bottom-right ellipse,
the four straight sides as `LineTo`s that degenerate when the radii eat the side, and `radius.min(half)`
clamping per corner. `drawRoundRect` halves its single ellipse size into a per-corner pair and
mirrors a NaN `ellipseHeight` onto `ellipseWidth`; `drawRoundRectComplex` passes each radius in as
both the width and the height of its corner ellipse.

The AABB is still unioned from the two rectangle corners rather than walked per command. That is
exact, not an approximation: `ucp[0].x == ucp[4].y == 1`, so each corner ellipse's extreme point sits
exactly on the rectangle edge.

Only five corpus SWFs call either method (`graphics_bitmaps`, `graphics_gradients`,
`graphics_simple_shapes`, `from_shumway/acid/acid-shapes`, `from_shumway/captions`), so the blast
radius is tiny and fully measured above. `graphics_bitmaps` stays PASS with 98 channels more margin.

---

## 4. G3 — LINESTYLE2 caps/joins, and why `layers` is refuted

### What patch 3 does
`parseLineStyles`'s DefineShape4 arm already read StartCapStyle/JoinStyle/EndCapStyle/MiterLimitFactor
and threw them away. It now records them on `LineStyle` (defaults 0/0/0/3.0, i.e. the historical
round-everything geometry for every pre-v4 shape and for MORPHLINESTYLE2, which is deliberately left
unwired). `SWF::drawLines` takes the `LineStyle` instead of a bare width and hands the codes to:

- `drawLineCap`: `1` (none) emits nothing, as lyon's `LineCap::Butt` does; `2` (square) extrudes the
  two offset corners by half the width along the outward tangent; `0` keeps the round fan.
- `drawLineJoin`: `1` (bevel) is the flat chord between the two offset corners; `2` (miter) computes
  lyon's miter normal `m = (n0 + n1)/(1 + n0·n1)` (length `1/cos(θ/2)`) in half-width units, applies
  it when `|m| ≤ 2·miter_limit` (lyon `miter_limit_is_exceeded`) and `miter_limit ≥ 1.0`
  (`StrokeOptions::MINIMUM_MITER_LIMIT`, below which Ruffle itself drops to Bevel), and otherwise
  falls back to the bevel chord; `0` keeps the round fan.

The one deliberate divergence from lyon: where lyon's `MiterClip` would draw a CLIPPED wedge, we draw
the bevel chord. They differ only on corners sharper than the limit, and the corpus scan below shows
no SWF that declares a miter join has one. Documented in the patch comment.

For `join_style == 0` / `cap_style == 0` the emitted vertices are bit-for-bit what the old code
emitted (same `start_angle`/`end_angle`, same 5-midpoint fan, same rounding), which the canary
confirms (§6).

### Corpus scan, re-run fresh
`ls2scan.py` (w1's scanner, re-run today against the current tree) still finds **exactly five** SWFs
with a non-round LINESTYLE2 word, and a `[W2PROBE]` instrumentation build gave the styles that
actually reach `drawLines`:

| test | declared styles | styles ACTUALLY stroked | after |
|---|---|---|---|
| `visual/simple_shapes/layers` | 17 + 26, square cap + miter, limit 1.0 | **5 paths, all `w=200 sc=0 ec=0 join=0`** | byte-identical |
| `visual/blend_across_masks_issue_24549` | 9, cap none, round join | 1 path, `w=40 sc=1 ec=1 join=0` | **6 → 0, PASS** |
| `from_shumway/acid/acid-small` | 4, miter + mixed caps | 29 paths, `w=20`, miter, caps 0/1 | byte-identical |
| `from_shumway/gradientTransform` (KF) | 1, square caps + miter | 2 paths, `w=20 sc=2 ec=2 join=2` | byte-identical |
| `from_shumway/timeline/Timeline8` | 12, bevel | — | no image comparison |

### REFUTATION: `layers` is not a cap/join row
w1 priced `visual/simple_shapes/layers` as a flip candidate because its style array declares 41
square-cap/miter-join entries with `miterLimit 1.0`. It does — **and not one of them is attached to a
path we stroke.** The probe shows the five stroked paths all select the LAST entry of their array,
which is `width 200, startCap round, join round`. Honouring the parsed styles is therefore provably
inert there: the generated `RecompiledTags/draws.c` is byte-identical with and without patch 3 (477
vertices both ways, `diff -q` clean), and so is the rendered PNG (md5 `5a22b6e4…` both legs).

`layers`' 23-channel residual has a different owner. Worth someone's time: the fact that all five
stroked paths pick the final style entry while 43 styles are declared smells like a line-style index
or STYLECHANGERECORD-tracking question in `interpretShape` — but the render is 23/880 000 channels
off, so if it is a bug it is a very quiet one. Listed as an unclaimed lead (§7).

### Tripwire: GREEN
`from_shumway/acid/acid-small` passes today *with* the wrong (round) styles and was the mandatory
tripwire. With patch 3 its miter joins and mixed caps ARE honoured (the probe proves the styles reach
`drawLines`), and both comparisons come back **byte-identical** — `output.01` 25 989 outliers,
`output.05` 25 959, md5 `ca12fb06…` / `b1060b25…` on both legs. Same for `gradientTransform`. The
reason is scale: those strokes are 20 twips wide, so half-width is 10 twips = 0.5 px, and a miter tip
at 14 twips or a square-cap extension of 10 twips does not change a single resolved sample.

That is the useful calibration for anyone pricing cap/join work later: **the style only becomes
visible above roughly a 2-px stroke.** `blend_across_masks_issue_24549` flips because its butt cap
REMOVES a half-disc that a 40-twip round cap was painting past the line end, which is a coverage
change, not a sub-pixel one.

---

## 5. G4 — HOLD, and w1's lead 1 is half wrong

w1's top new lead was "Ruffle keeps ONE even-odd fill across `lineStyle()` changes, while we flush
the path per style **and tessellate nonzero**". The second half is **wrong**: our AVM2 Graphics fill
is already even-odd. `Avm2GraphicsExt.cur_winding` is initialised to 0 (`avm2_display.c:8411`),
`gfx_finalize_path` copies it to `Avm2GfxPath.winding` and passes
`path->winding ? TESS_WINDING_NONZERO : TESS_WINDING_ODD` to libtess2, and only `drawPath` /
`GraphicsPath.winding` ever set it to 1 — exactly Ruffle's `Drawing::new` default plus its
`set_fill_rule` override.

So the defect is precisely one thing: `gfx_line_style` calls `gfx_finalize_path()`, which closes the
FILL as well as the line. Ruffle's `set_line_style` closes only the line (pushing it to
`pending_lines` while a fill is open); the fill survives until `new_fill`/`beginFill`/`endFill`, and
the pending lines are flushed AFTER it, which also fixes fill-vs-stroke z-order.

**Completion mechanism** (not attempted here — it is a restructure, not a tweak): split
`Avm2GraphicsExt`'s single `cmds` buffer into a fill-scoped command buffer that survives
`lineStyle()` and a per-style stroke run, so one `Avm2GfxPath` can carry one even-odd fill plus a
list of stroke runs with different styles. Until then, overlapping subpaths drawn under one
`beginFill` across a `lineStyle()` change cannot cancel, which is what leaves the round-rect ∩ circle
overlap red in `graphics_simple_shapes` (152 of its remaining 154 channels). The AVM1 twin in
`action.c` has the same split and should be checked in the same pass.

---

## 6. Canary, regression suite and other required checks

### Canary coverage audit (and what patch 3 adds)
The standing 29-member set was **structurally blind to all three change classes**: no member reads
`getBounds`/`getRect` off a runtime `Graphics`, no member calls `drawRoundRect`, and not one of the
five SWFs that declare a non-round LINESTYLE2 word was in the list. Patch 3 therefore adds five
covering members to `render_canary_tests.txt` (tier 1: `avm2/graphics_bitmaps`,
`from_shumway/acid/acid-small`; tier 2: `avm2/displayobject_getbounds_shape`,
`avm2/graphics_simple_shapes`, `visual/simple_shapes/layers`), with the rationale in the file.

### Render canary — `before` (clean `e36bca73e`) vs `after` (all three patches)
Both legs captured with `--recompile -P 2` over the **original 29-member list** (extracted with
`git show HEAD:ruffle-tests/render_canary_tests.txt`, so the list change in patch 3 cannot skew the
comparison):

```
  IDENTICAL    61
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

**Zero DIFFERS rows, so there are no DIFFERS verdicts to adjudicate.** Per false-negative mode 10
that is a red flag unless the change is proved live and the set proved blind, so both:
- *Live*: `blend_across_masks_issue_24549` flips 6 → 0 in this same worktree with these same flags;
  `layers`' `RecompiledTags/draws.c` is regenerated on every `--recompile`; the `[W2PROBE]` build
  shows the parsed style words reaching `drawLines`; and the `after` leg's canary test dirs carry
  `RecompiledTags` written at 16:02 by the 15:55 patched binary (mode 1 cleared).
- *Blind*: no member of the original set calls `drawRoundRect`, reads `getBounds`/`getRect` off a
  runtime `Graphics`, or is one of the five SWFs with a non-round LINESTYLE2 word. It CAN see the
  round/default stroke path, and 61/61 IDENTICAL is exactly the assertion patch 3 needs — for
  `join_style == 0` / `cap_style == 0` the geometry must be bit-for-bit unchanged, and it is.

The five new canary members were A/B'd by hand instead (§1): `graphics_bitmaps` 1 057 → 959 PASS,
`acid-small` md5-identical, `layers` md5-identical, `getbounds_shape` 19 086 → 3 716 PASS,
`graphics_simple_shapes` 230 → 154.

### `regression` suite
Eight members run with `--mode=graphics --images --recompile` (no `--verbose`: the suite is
git-tracked). **8/8 pass, all image checks pass or skip, identical to the CI baseline at `254145a5b`:**

| test | trace | image |
|---|---|---|
| `avm2_graphics_runtime` | pass | skip (no expected PNG) |
| `avm2_timeline_solid` | pass | skip |
| `avm2_morph` | pass | skip |
| `avm2_bitmapdata_draw_textfield` | pass | (no comparison) |
| `avm2_timeline_gradients` | pass | pass, 0 outliers |
| `avm2_timeline_stroke_gradient` | pass | pass, 0 outliers |
| `mask_sibling_union` | pass | pass, 0 outliers, max diff 0 |
| `mask_nested_intersect` | pass | pass, 0 outliers, max diff 0 |

`avm2_graphics_runtime` is the one that matters for patches 1 and 2 — it is the repo's own AVM2
runtime-`Graphics` fixture and it stays green. Note it has no expected PNG, so it is a trace-only
guard there; that is a standing gap, not something this patch introduced.

### Trace axis
`avm2/displayobject_getrect` (11/16, `output_mismatch`) and `avm2/bounds_mode` (`ruffle_matched`,
263/269) were run on the AFTER leg and are line-for-line identical to the CI baseline. No trace row
moves in either direction from any of the three patches.

### Risks
1. **G1's 84-channel margin.** `displayobject_getbounds_shape` passes at 3 716 against 3 800. The
   residual is a stroke-tie population; any later stroke-fan or flattening change can re-deal it.
2. **G3's bevel-instead-of-miter-clip divergence** is unexercised in today's corpus (no declared
   miter join meets its limit) but will diverge from Ruffle the day one does.
3. **Patch 3 is a recompiler change**: it needs a cmake rebuild AND `--recompile`, and CI's
   `RecompiledScripts` caches invalidate on binary mtime, which the workflow already handles.
4. Patch 2 changes the emitted command stream for `drawRoundRect`, so any SWF that calls it gets
   more vertices; `graphics_bitmaps` (the only passing caller) gained margin rather than losing it.

---

## 7. New unclaimed leads

1. **`layers` declares 43 line styles and strokes 5 paths, all with the LAST entry.** If that is a
   line-style-index bug in `interpretShape`'s STYLECHANGERECORD handling rather than a faithful
   reading of the SWF, it is the owner of that row's 23 channels — and of any other multi-style
   DefineShape4. Cheap to probe: the `[W2PROBE]` two-line instrumentation in this report's §4.
2. **Cap/join style is invisible below ~2 px of stroke width** (measured, §4). Any future pricing of
   stroke-style work should weight rows by stroke width first; four of the corpus' five non-round
   SWFs are 1-px strokes and can never move.
3. **`gfx_cubic_curve_to` bounds** still union both control points (§2); Ruffle uses lyon's tight
   cubic box. Same shape of fix as patch 1, no corpus row prices it.
4. **MORPHLINESTYLE2 cap/join words are parsed and still discarded** — patch 3 deliberately wires only
   the non-morph arm, to keep morph rows bit-stable. One extra assignment block would close it, but
   it needs its own measurement against the morph family.
5. **`drawCircle`/`drawEllipse` do not go through `draw_round_rect_internal`.** Ruffle implements
   `drawCircle` as a round rect with `radius` corners; we have a separate four-arc emitter. Worth an
   A/B now that the round-rect path exists — `graphics_gradients`' 349 remaining channels are all in a
   stroked `drawEllipse`, although w1 attributed those to radial-REPEAT gradient SAMPLING, not geometry.
6. The `graphics_gradients` residual (349 ch, ours `(66,4,193)` vs `(88,32,200)`) is a radial
   `SpreadMethod.REPEAT` **stroke fill** sampling bug, unchanged by patch 2 — still unowned.
