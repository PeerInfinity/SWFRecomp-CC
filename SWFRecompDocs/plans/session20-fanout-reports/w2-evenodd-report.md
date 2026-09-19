# w2-evenodd — ONE even-odd fill across `lineStyle()` (session 20, wave 2)

## NEW FILES (stage these BY NAME — `git add -u` will drop them)

```
SWFRecompDocs/plans/session20-fanout-reports/w2-evenodd-1-avm2-fill-span.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-evenodd-2-canary.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-evenodd-report.md
```

No new **source** files. The two patches touch two existing tracked files:

| patch | file | why separate |
|---|---|---|
| `w2-evenodd-1-avm2-fill-span.patch` | `SWFModernRuntime/src/avm2/avm2_display.c` | the fix |
| `w2-evenodd-2-canary.patch` | `ruffle-tests/render_canary_tests.txt` | the always-conflicting shared file; apply with `--3way` |

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-af1a58b16a866b0c9`
(branched from `master` at `4b05de6ef`). Deliverables also copied to the main
tree's `SWFRecompDocs/plans/session20-fanout-reports/`.

---

## 1. Verdicts, up front

| item | verdict |
|---|---|
| **AVM2 fix (patch 1)** | **GO** — landed, verified, zero collateral movement |
| `avm2/graphics_simple_shapes [output]` | **BAND, NOT FLIP.** 154 → **2** outlier channels (−152, −98.7 %). Still FAILS: `tolerance = 1`, `max_outliers = 0`, and the 2 residual channels are one pixel at `max_diff 255`. |
| `visual/drawing_api/drawing_order [output]` | **REFUTED** — different mechanism, **zero** channels moved (see §5.1) |
| AVM1 twin (`action.c`) | **REFUTED as "the same defect"**, and **NOT attempted**. AVM1 already keeps one fill across `lineStyle`; it has the *complementary* bug. Priced in §5.2. |
| priced FLIPS from this patch | **none.** Honest answer: this is a −152-channel band move on one comparison. |
| regressions | none. 7/7 `regression` tests green, 10/10 AVM2 graphics trace tests unchanged, 9/9 other canary comparisons byte-identical. |

**The s19 diagnosis was right on the mechanism and right on the "152 of 154"
arithmetic — and wrong by omission on the pricing.** Nobody had checked whether
closing 152 of 154 channels gets the comparison under its budget. It does not:
`max_outliers` is 0, so 2 outliers fail exactly as loudly as 154. This is the
same shape as s19's device-font arc, and it is the single most important
sentence in this report.

---

## 2. Premise audit (what I verified before writing code)

Three inherited claims; all three checked against the corpus and the oracle.

**(a) "152 of `graphics_simple_shapes`' 154 remaining channels." — TRUE, exactly.**
The comparison differs in 77 pixels, each in exactly 2 channels (154 = 77 × 2).
Decomposed by colour pair against the CI golden:

| pixels | ours | expected | owner |
|---|---|---|---|
| 44 | red fill | white | even-odd cancellation missing (roundRect ∩ circle lens) |
| 32 | red fill | blue stroke | fill/stroke **z-order**: Ruffle paints deferred strokes after the fill |
| **76 = 152 ch** | | | **this patch** |
| 1 | green stroke | red fill | ellipse stroke **inner edge**, one sample — NOT this patch (§4) |

Both halves of the 152 are the same defect: `gfx_line_style` closing the fill
also forced the roundRect's blue stroke into a path that the circle's later
fill path then painted over.

**(b) "The defect is `gfx_line_style` calling `gfx_finalize_path`." — TRUE**, and
s19's `w2-gfx-geometry` §5 refinement is also correct: our AVM2 fill is already
even-odd (`Avm2GraphicsExt.cur_winding = 0`, `TESS_WINDING_ODD`), so the winding
rule was never the problem. The problem was purely that one function closed both
the fill and the stroke.

**(c) "The fix shape is to split `gfx_finalize_path` into a stroke-flush and a
fill-flush." — HALF right, and the missing half is what makes it correct.**
A stroke/fill split alone gets the even-odd hole (44 px) but *inverts* the
z-order on the other 32: if `lineStyle` emits its stroke path immediately, that
stroke lands in `paths` **before** the fill that is still open, and the fill then
covers it. Ruffle does not do that. `Drawing::set_line_style`
(`core/src/drawing.rs:168`) pushes the closed line into **`pending_lines`** while
`current_fill.is_some()`, and `new_fill` (`:120`) emits
`current_fill` → `pending_lines.drain(..)` → `current_line`, in that order.
`register_or_replace` (`:240`) does the same for the not-yet-committed state.
So the deferral list is not an optimisation — it *is* the z-order rule, and
dropping it would have traded 44 channels for 32 in the wrong direction.

**(d) Corpus scope of the change.** Before implementing I scanned every `.as`
source in every suite for a `lineStyle` / `lineGradientStyle` / `lineBitmapStyle`
call between a `begin*Fill` and its `endFill`
(`<scratchpad>/w2-evenodd/scan_fillspan.py`). **Exactly one test qualifies:
`avm2/graphics_simple_shapes`.** (Three other files matched the crude line-based
scan and were hand-cleared: `bitmapdata_draw` / `bitmapdata_drawwithquality` put
the `lineStyle` on a *fresh, fill-less* `Sprite`, and `displayobject_getrect`
calls `lineStyle` with zero pen commands since `beginFill`, which is a no-op
run.) That is the ceiling on this patch's corpus reach, and it was worth knowing
before spending the slot.

---

## 3. Patch 1 — mechanism and exact scope

`SWFModernRuntime/src/avm2/avm2_display.c`, +200 / −48, all inside the
`Avm2GraphicsExt` / `gfx_*` region (≈ lines 8290–10400) plus two one-line
touches at 14596 and the `gfx_finalize_path` call sites. **No overlap with
`w2-gfx-text-smalls`**: I confirmed lines 18630–18665 (`avm2_render_textbox`'s
border arm, `corner_missing` + the four `avm2_border_rect` calls) contain no
`gfx_` symbol at all, and I edited nothing in that function. `avm2_render_graphics`
(≈18249) is untouched except that it still calls `gfx_finalize_path`.

### New state on `Avm2GraphicsExt`
```c
uint32_t stroke_start;              // index into cmds[] where the CURRENT line run begins
Avm2GfxPath* pend; uint32_t pend_count, pend_cap;   // Ruffle's pending_lines
```

### New / changed functions
| symbol | what |
|---|---|
| `gfx_flatten_cmds(g, from, to, seed, sx, sy, …)` | **new**; the contour flattener lifted verbatim out of `gfx_finalize_path` and given a `[from, to)` window plus an optional leading `MoveTo(cursor)` seed (Ruffle seeds each fresh `DrawingLine` with `MoveTo(self.cursor)`). Curve start points are still read at the *absolute* index `cmds[i-1]`, which for `i == from > 0` is that same cursor. |
| `gfx_push_path` / `gfx_push_pend` | **new**; zeroed append to `paths` / `pend`. |
| `gfx_snapshot_line(g, path)` | **new**; the line-style snapshot (including the owning `lsty.bmp_px` copy) lifted out of `gfx_finalize_path`. |
| `gfx_flush_stroke_run(g, to_pending)` | **new**; Ruffle `set_line_style`. Builds a **stroke-only** path from `cmds[stroke_start, cmd_count)`, sends it to `pend` when a fill is open and to `paths` otherwise, and advances `stroke_start`. **Does not touch `cmd_count`** — that is the whole fix. |
| `gfx_finalize_path(g)` | **rewritten**; Ruffle `new_fill`. Emits the ONE fill path over the whole `cmds` buffer, then drains `pend` into `paths` in order, then flushes the current run. The fill path no longer carries a stroke. |
| `gfx_reset(g)` | frees `pend`, clears `stroke_start`. |

### Every `gfx_finalize_path` call site, and the decision for each
| site | Ruffle equivalent | decision |
|---|---|---|
| `gfx_line_style` (~9212) | `set_line_style` | → `gfx_flush_stroke_run(g, cur_fill != 0)` **[the fix]** |
| `gfx_line_bitmap_style` | `set_line_fill_style` → `set_line_style` | → `gfx_flush_stroke_run` |
| `gfx_line_gradient_style` | `set_line_fill_style` → `set_line_style` | → `gfx_flush_stroke_run` |
| `gfx_line_fill_style` (lineShaderStyle stub) | Ruffle `stub_method`s it — touches nothing | → `gfx_flush_stroke_run` + keep our clear-the-stroke convention (breaking the fill here would be strictly *further* from Ruffle) |
| `gfx_apply_stroke_carrier` (GraphicsStroke) | `set_line_style` | → `gfx_flush_stroke_run` |
| `gfx_begin_fill` / `gfx_begin_gradient_fill` / `gfx_begin_bitmap_fill` | `new_fill` | **unchanged** (full flush) |
| `gfx_end_fill` | `set_fill_style(None)` → `new_fill` | **unchanged** |
| `drawPath` ×2 (~10155/10158) | `set_fill_rule(Some)` / `set_fill_rule(None)`, both → `new_fill` | **unchanged** |
| `drawGraphicsData` GraphicsPath ×2, fill carriers ×1 | `new_fill` | **unchanged** |
| hit test (~14540) | `Drawing::hit_test` also tests the pending subpath | **unchanged** — and now strictly *more* correct: the even-odd hole is genuinely absent from the triangles, which is what `draw_command_fill_hit_test(commands, rule, point)` reports |
| `avm2_graphics_cpu_composite` (~8944) | `register_or_replace` | **unchanged** (destructive commit is pre-existing) |
| `avm2_render_graphics` (~18254) | `register_or_replace` | **unchanged** |
| `gfx_clear` → `gfx_reset` | `Drawing::clear` | now also clears `pend` + `stroke_start` |
| `gfx_new_fill_path` (drawTriangles) | — | **unchanged**, see "known residual" below |

### Worked trace — `graphics_simple_shapes`
```
beginFill(red)                  cur_fill=1
drawRect(5,5,15,20)             cmds[0..5)
lineStyle(2,blue)               flush run [0,5): cur_line==0 -> nothing; stroke_start=5
drawRoundRect(30,5,15,20,10)    cmds[5..21)
lineStyle()                     flush run [5,21) with BLUE -> pend[0]; stroke_start=21; cur_line=0
drawCircle(50,15,10)            cmds[21..31)
lineStyle(4,green)              flush run [21,31): cur_line==0 -> nothing; stroke_start=31
drawEllipse(70,5,10,20)         cmds[31..41)
endFill()                       fill over cmds[0..41) EVEN-ODD  -> paths[0]
                                drain pend                      -> paths[1] (blue roundRect stroke)
                                flush run [31,41)               -> paths[2] (green ellipse stroke)
```
`paths = [red even-odd fill][blue stroke][green stroke]`, drawn in array order,
fill-then-stroke per path, in both `avm2_render_graphics` (GPU) and
`avm2_graphics_cpu_composite` (CPU). That is Ruffle's order exactly, and it is
why the 32 z-order channels close along with the 44 even-odd ones.

### Known residuals I deliberately did NOT change (each is pre-existing)
* `gfx_begin_fill` does not re-seed a `MoveTo(cursor)` the way Ruffle's
  `new_fill` does (the AVM1 twin `drawingBeginNewFill` does). The
  `moveTo; beginFill; lineTo` idiom therefore still loses its first vertex.
  Unrelated to this change class; perturbing it here would have muddied the A/B.
* `drawTriangles` (`gfx_new_fill_path`) pushes straight into `paths` without a
  finalize, so a `drawTriangles` issued while stroke runs are pending would land
  *before* them. No corpus test does that; the alternative is a behaviour change
  with no test to justify it.
* A `lineStyle` change in the **middle** of a subpath closes its stroke run to
  the *run's* first point rather than to Ruffle's `fill_start`. All four style
  changes in the only test that exercises this land exactly on a `moveTo`
  boundary, where the two rules coincide. Documented in the code comment.

---

## 4. Per-comparison before / after, and the 1 residual pixel

### `avm2/graphics_simple_shapes [output]`  (550 × 400, tolerance 1, max_outliers 0)
| | outlier channels | pixels | max_diff |
|---|---|---|---|
| CI baseline (run `34666689502` @ `d8da5a18c`) | 154 | 77 | 255 |
| local `before` leg (clean `4b05de6ef`) | **154** | 77 | 255 |
| local `after` leg (patch 1) | **2** | **1** | 255 |

The local `before` render reproduces the CI row *exactly* — same count, same
bbox, same colour-pair histogram — so the local A/B is measuring the same defect
CI grades. (Stated as corroboration, not as a verdict: a local render is never a
grade.)

**The residual is one pixel, `(76, 8)`, and it is NOT this change class.**
Row 8 of the ellipse reads `RRR` for us and `RRRR` for Ruffle: our 4-px green
ellipse stroke covers one extra sample on its **inner** edge. Mechanism:
* Our `drawEllipse` control points are *identical* to Ruffle's — our
  `kct = 1/cos(π/8)` construction yields `(1.0, 0.41421356)` for the first
  octant, which is `UNIT_CIRCLE_POINTS[1]` to the last digit. The geometry is
  right; the **flattening** is what differs.
* We flatten the *centerline* at `CURVE_FLATTEN_TOLERANCE = 0.1` (lyon's
  `FillOptions::DEFAULT_TOLERANCE`) and then offset the chords. lyon's *stroke*
  tessellator controls error on the **offset** curve. Measured at the disputed
  sample: distance to the true ellipse 2.0653 px, distance to our 25-vertex
  flattened polyline 2.0141 px, half-width 2.0 px — i.e. we are 0.014 px from
  the coverage threshold, entirely inside the chord-sag budget.
* **Falsification test run**: rebuilt with `CURVE_FLATTEN_TOLERANCE = 0.002`.
  The `(76,8)` pixel flips to red as predicted — **and the comparison gets
  worse, 2 → 24 channels**, because the finer fill polygon now overshoots
  Ruffle's on 9 other pixels. So the standing 0.1 is the tuned optimum for the
  fill boundary and the correct fix is a separate stroke-side error model, not a
  tolerance knob. (Diagnostic only; reverted, not in the patch.)

### Other comparisons — local A/B, `render_canary.py compare before after`
```
RENDER CANARY  before=before  after=after   10 tests / 10 comparisons
  IDENTICAL     9
  DIFFERS       1
  APPEARED      0   VANISHED 0   NO_RENDER 0
  DIFFERS:
    avm2/graphics_simple_shapes  output   [DIFFERS]
        diff_channels 152/880000  mean 0.044  max 255   bbox (40,7)-(46,23)
        image status: fail -> fail    trace: pass -> pass
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```
The 9 IDENTICAL: `avm2/graphics_bitmaps`, `avm2/graphics_draw_path`,
`avm2/graphics_draw_triangles`, `avm2/displayobject_getbounds_shape`,
`visual/drawing_api/{drawing_order,fills_and_lines,cursor}`,
`visual/simple_shapes/{layers,winding_rule}`.
Plus a second A/B on the newly added member: `regression/avm2_graphics_runtime`
**IDENTICAL**, trace pass → pass.

**This is not a blind-canary zero.** `avm2/graphics_bitmaps` is a tier-1,
CI-passing member that changes the fill style four times with no `lineStyle`
*and* the stroke style five times with no fill open — it drives both
`gfx_flush_stroke_run(to_pending = 0)` and the `begin*Fill` full flush, and
`IDENTICAL` there is exactly the assertion the patch needs. The set proved live
on `graphics_simple_shapes` in the same pair of legs.

### Trace side — every AVM2 test that touches runtime `Graphics`
`--mode=graphics --recompile`, one at a time:
`graphics_direct_commands`, `graphics_bitmap_fill`, `graphics_gradients`,
`displayobject_getrect`, `bitmapdata_draw`, `displayobject_getbounds_shape`,
`graphics_draw_triangles`, `graphics_bitmaps`, `graphics_simple_shapes` — **all
pass**. `graphics_draw_path` is `ruffle_matched` **in both legs** (the canary
reports it as `ruffle_matched` before and after), i.e. unchanged from baseline.

### `regression` suite — `--tests-dir=ruffle-tests/tests/swfs/regression --mode=graphics`
`avm2_graphics_runtime`, `avm2_parent_child_static_text`, `avm2_simplebutton_click`,
`avm2_morph`, `avm2_timeline_gradients`, `avm2_timeline_stroke_gradient`,
`avm2_parent_child_render` — **7 / 7 pass**. (`--verbose` writes
`output.actual.png` / `output.difference.png` into the tracked suite; removed
before producing the patch — the tree is clean apart from the two intended files.)

---

## 5. Refutations

### 5.1 `visual/drawing_api/drawing_order` is **not** this mechanism — it has no fill at all
The brief calls it "plausibly the same mechanism". It is not, and the
`same_geometry_wrong_fill` cluster label grouped it by pixel *fingerprint*, not
by cause. Two facts:

1. **It is an AVM1 test.** Its SWF carries `DoAction` (tag 12) and no `DoABC`
   (tag 82), so it never reaches `avm2_display.c`. My patch leaves it
   **byte-identical** (canary `IDENTICAL`; 6658 channels before, 6658 after).
2. **It contains no `beginFill`.** Decompiled from the recompiler's own output
   (`RecompiledScripts/script_0.c` + `script_defs.c`), the whole test is:
   ```
   _root.lineStyle(5, 0x00FF00); _root.lineTo(500, 500);
   this.attachMovie("mc", "mc", 3);  mc._x = 250; mc._y = 250;
   mc.lineStyle(5, 0x0000FF); mc.moveTo(250, -250); mc.lineTo(-250, 250);
   ```
   Two strokes and an attached library clip. It is a **z-order-of-drawings**
   test, not a fill test.

What it *actually* shows (coarse ASCII of ours vs the golden, both 500 × 500):
the golden has a full-stage green diagonal and a full-stage blue diagonal,
visible outside the attached clip's red box; we render **no green line at all**
and only a single 20 × 20 block of blue at the stage origin. Two distinct
defects, both newly named here:

* **The root clip's bare-name drawing calls are dropped.** `lineStyle` / `lineTo`
  at root scope compile to `actionCallFunction` (not `actionCallMethod`, not a
  `with`-scope dispatch). `action.c` routes drawing-API calls to a `DrawingState`
  from the `CallMethod` handler (~73660) and from the WITH-scope handler
  (~62300) — there is no base-clip arm for a bare `CallFunction`, so the root's
  green diagonal is never recorded. Worth ~1074 of the 6658 channels.
* **An attached clip's runtime drawing ignores the clip's `_x` / `_y`.** The blue
  line is drawn from `(250,-250)` to `(-250,250)` in *stage* space instead of in
  `mc`'s space after `mc._x = mc._y = 250`; the only part of that segment inside
  the 0..500 stage is the corner at the origin, which is precisely the one block
  we render. Worth ~1080 channels of missing blue plus the ~1148 red-over-blue
  channels (the line should be under the box in the middle and visible outside
  it).

Neither is fixable in `avm2_display.c`. Handed off in §6.

### 5.2 AVM1 has the **complementary** bug, not the same one — and I did not fix it
The brief asks whether AVM1 shares this code. **It does not** — `action.c`'s
`DrawingState` / `drawingFinalizePath` is an independent implementation. And it
does **not** have this defect: `drawingBeginNewLineStyle` (`action.c:30567`)
opens with

```c
if (ds->has_fill || ds->has_gradient || ds->has_bitmap_fill) return;
```

so on the AVM1 side the fill **already** survives a `lineStyle()` change. The
existing comment says so explicitly ("Restricted to the no-fill case on purpose…
our DrawPath carries one fill AND one line style, so splitting there would cut
the fill polygon in half"). AVM1's bug is the mirror image: with a fill open, a
`lineStyle` change is **silently discarded for the stroke**, so every stroke
recorded since the `beginFill` takes the *last* style, and there is no
pending-lines deferral either, so fill/stroke z-order is wrong the same way ours
was.

**Priced separately, as the brief asks:**
* **Corpus value: near zero at flip granularity, and unmeasured at band
  granularity.** My corpus scan found no AVM1/`from_gnash`/`from_shumway` `.as`
  source with a `lineStyle` inside a fill span, and the row the brief nominated
  as the AVM1 beneficiary (`drawing_order`) turns out to have no fill (§5.1).
  Most AVM1 suites ship `.swf` only, so the scan is a lower bound — but there is
  currently **no identified failing comparison that this fix would move.**
* **Cost: high.** The same restructure, but into a function that additionally
  owns `stroke_poly` / `stroke_contours` ownership transfer, a lazy stroke
  rebuild keyed on `stroke_built_half_w`, a hit-test twin
  (`drawingCmdWindingHitTest`, kept "in lockstep"), a **64-`DrawPath`-per-MC cap**
  in `fillDrawingInfos` that *silently truncates* (so extra paths can DROP
  geometry — the existing comment warns about exactly this), and two separate
  call-site copies of the drawing dispatch (~62300 and ~73660).
* **Verdict: HOLD.** Completion mechanism: a corpus row that provably needs it.
  Re-run `<scratchpad>/w2-evenodd/scan_fillspan.py` over the AVM1 suites once
  sources exist, or find a failing comparison whose diff is per-style strokes
  under a fill; until then this is a restructure with a real truncation hazard
  and no measured beneficiary.

### 5.3 The "just split the function" shape would have half-fixed it
Recorded in §2(c): a stroke/fill split without the `pending_lines` deferral gets
the 44 even-odd channels and **inverts** the 32 z-order channels. Anyone
re-deriving this from the s19 note alone would have shipped that.

---

## 6. New unclaimed leads

1. **`visual/drawing_api/drawing_order`, AVM1 root-clip bare-name drawing calls
   (~1074 ch).** `_root.lineStyle(...)` / `_root.lineTo(...)` compile to
   `actionCallFunction`; `action.c` has drawing-API arms for `CallMethod` and for
   WITH-scope names, but none for a bare `CallFunction` against the base clip, so
   the root's own drawing is silently dropped. Evidence: §5.1, from the
   recompiler's own generated C. Cheap, well-localised, and likely affects any
   AVM1 content that draws on `_root` without a `with`.
2. **`visual/drawing_api/drawing_order`, attached-clip drawing ignores `_x`/`_y`
   (~1080 + ~1148 ch).** `mc.lineTo` geometry renders in stage space, not in the
   clip's space after `mc._x = mc._y = 250`. Same test, independent defect.
   Together with lead 1 this owns the bulk of that row's 6658 channels — but note
   `tolerance = 0`, so it is a band lead until both are closed *and* the
   antialiased line edges match.
3. **Stroke-side flattening error model (the last 2 channels of
   `graphics_simple_shapes`, and probably the standing `hairline_edge_drift`
   cluster).** We flatten the *centerline* at lyon's **fill** tolerance and offset
   the chords; lyon's stroke tessellator bounds the error on the **offset**
   curve. Measured gap at the one disputed sample: 0.014 px. Proven live by the
   `CURVE_FLATTEN_TOLERANCE = 0.002` experiment, which fixes that pixel and
   breaks 9 others — so a global tolerance change is the *wrong* fix and a
   per-side stroke tolerance is the right one. This is the only thing between
   `graphics_simple_shapes` and a flip, and it plausibly touches far more rows
   than that one test.
4. **`gfx_begin_fill` lacks Ruffle's `MoveTo(cursor)` re-seed** (`new_fill`
   re-opens `current_fill` *and* `current_line` at the cursor). The AVM1 twin
   `drawingBeginNewFill` does it; the AVM2 one does not, so
   `moveTo; beginFill; lineTo` loses its first vertex. No corpus test currently
   isolates it. A 2-line fix plus a `regression/` fixture off the Ruffle exporter.
5. **Ruffle's degenerate `drawEllipse` sides.** `draw_round_rect_internal` emits
   four zero-length `LineTo` commands between the quadrant arcs when the roundrect
   degenerates to an ellipse, i.e. Ruffle's ellipse contour carries 4 duplicate
   vertices that ours does not. Harmless for the fill; unverified whether lyon's
   stroker emits anything at them. Noted for whoever takes lead 3.

---

## 7. Reproduction

```bash
# A/B (both legs --recompile, -P 2, --timeout 5400)
python3 ruffle-tests/render_canary.py capture --label before --recompile -P 2 \
  --test avm2/graphics_simple_shapes --test avm2/graphics_bitmaps \
  --test avm2/graphics_draw_path --test avm2/graphics_draw_triangles \
  --test avm2/displayobject_getbounds_shape --test visual/drawing_api/drawing_order \
  --test visual/drawing_api/fills_and_lines --test visual/drawing_api/cursor \
  --test visual/simple_shapes/layers --test visual/simple_shapes/winding_rule
git apply SWFRecompDocs/plans/session20-fanout-reports/w2-evenodd-1-avm2-fill-span.patch
python3 ruffle-tests/render_canary.py capture --label after  --recompile -P 2 <same --test list>
python3 ruffle-tests/render_canary.py compare before after
```
Scratch (scripts + logs + PNGs):
`<scratchpad>/w2-evenodd/` — `scan_fillspan.py` (corpus fill-span scan),
`imgdiff.py` / `ascii.py` / `coarse.py` (pixel forensics),
`ellipse_probe.py` (the 0.014 px flattening measurement),
`before.log` / `after.log` / `diag.log` / `regr_after.log` / `avm2_after.log`.

## 8. Recommended CI dispatch
`mode=graphics`, `categories=all`, `images=false` for the trace gate (the change
is AVM2 runtime display code, not recompiler emission; `categories=full` is
defensible but the scan in §2(d) shows the reachable surface is one test).
The −152-channel move is only *visible* on an `images=true` run — book it there,
and expect `avm2/graphics_simple_shapes` to stay in the failing list either way.
