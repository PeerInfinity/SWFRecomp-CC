# w2-gfx-strokes — round joins/caps in the runtime stroke builders + drawing-API twip truncation

*Session 18 corpus fan-out, wave 2. Worktree `agent-a94c5b045d127d9d5`, base `8f68a5fea`.
Diagnosis of record: `w1-gfx-smalls-report.md` §2 (mechanism A) and §3 B.*

## VERDICT — GO, with one priced row refuted on magnitude

**3 pixel flips land, 0 regressions, 0 trace changes anywhere.**

| priced target | brief's price | measured | verdict |
|---|---|---|---|
| `avm2/graphics_bitmap_fill` | 64 → ≤60 outliers | 64 FAIL → **PASS** (max diff 100 → 51) | **GO — flip** |
| `avm2/mouse_pick_dobj_mask` | 2 px → flip | 6 FAIL → **PASS, byte-exact** | **GO — flip** |
| `avm2/mouse_pick_non_interactive_dobj_mask` | 2 px → flip | 6 FAIL → **PASS, byte-exact** | **GO — flip** |
| `visual/drawing_api/fills_and_lines` | 104 → 0 | 104 → **4**, still FAIL | **REFUTED on magnitude** — 96 % of the residual is gone, but `max_outliers = 0` means no flip |

**Unpriced yield the brief did not claim** (all large, none a flip on its own):

| test | before | after | reduction |
|---|---|---|---|
| `avm2/graphics_draw_path` | 204 | **4** | −98 % |
| `avm1/movieclip_begin_gradient_fill` | 672 (max diff 255) | **132** (max diff 209) | −80 % |
| `avm2/displayobject_getbounds_shape` | 22 290 | **19 086** | −14 % |
| `avm2/graphics_simple_shapes` | 240 | 230 | −4 % |
| `from_shumway/acid/acid-shapes` | 42 012 | 41 577 | −1 % |

## NEW FILES

*(none — every edit lands in an existing TU. Nothing to add to `verify_output.py`'s
explicit source list, `CMakeLists.txt` or the Emscripten build.)*

Deliverables (worktree `SWFRecompDocs/plans/session18-fanout-reports/`, copied to the main
tree): `w2-gfx-strokes.patch`, `w2-gfx-strokes-report.md`.

## 1. Files touched

| file | region | change |
|---|---|---|
| `SWFModernRuntime/include/actionmodern/action.h` | trailing fields of `DrawPath` and `DrawingState` | `line_joints` / `line_caps` / `line_miter` |
| `SWFModernRuntime/src/actionmodern/action.c` | `drawingAddCmd`; new `drawing_arc_segments` / `drawing_stroke_extra_verts` / `drawing_emit_round_join` / `drawing_emit_stroke_cap`; `drawing_emit_stroke_join`; `drawingBuildStroke`; new `drawingParseLineJoinCaps`; `drawingBeginNewLineStyle`; the two AVM1 `lineStyle` opcode arms; `drawingFinalizePath` | twip quantization, round join/cap fans, style plumbing |
| `SWFModernRuntime/src/avm2/avm2_display.c` | `Avm2GfxPath` / `Avm2GraphicsExt` struct tails; `gfx_quantize_twips` + `gfx_add_cmd`; new `gfx_arc_segments` / `gfx_stroke_extra_verts` / `gfx_emit_round_join` / `gfx_stroke_cap`; `gfx_stroke_join`; `gfx_build_stroke`; new `gfx_caps_code` / `gfx_joints_code`; `gfx_line_style`; `gfx_apply_stroke_carrier`; `gfx_finalize_path`; `gfx_reset` | same, AVM2 side |

524 insertions / 71 deletions. Every AVM2 edit is inside the `gfx_*` drawing region or the
two `Avm2Gfx*` struct tails — no textual overlap with any sibling's region in
`SIBLING_FILE_MAP.md` (the `addFrameScript`, Stage, MovieClip, Mouse, Vector3D, sound and
loader regions are untouched). Runtime-only, so the main tree's `SWFRecomp/build` was
copied rather than rebuilt.

## 2. Mechanism

### A. Round joins and round caps (the default everywhere)

`w1-gfx-smalls-report.md` §2 is confirmed and the fix follows its shape: the *recompiler*
already emits round joins/caps for DefineShape strokes, and only the two **runtime**
builders were miter/bevel + butt. Both now carry the join/cap style on the path.

Defaults verified against Ruffle rather than assumed — the three entry points disagree:

| entry point | Ruffle source | caps | joints | miter limit |
|---|---|---|---|---|
| AVM1 `MovieClip.lineStyle` | `avm1/globals/movie_clip.rs:352-375` | args[5], **default Round** | args[6], **default Round** | args[7], else 3 |
| AS3 `Graphics.lineStyle` | `avm2/globals/flash/display/graphics.rs:313-337,373-386` | args[5], **default Round** | args[6], **default Round** | args[7], else 3 |
| AS3 `GraphicsStroke` | same file `:1531-1568`; ctor defaults | property `caps`, ctor default **"none"** (butt) | property `joints`, ctor default **"round"** | property `miterLimit`, default 3 |

Anything that is not `"none"`/`"square"` (caps) or `"miter"`/`"bevel"` (joints) — `null` and
`undefined` included — is Round, exactly as `caps_to_cap_style` / `joints_to_join_style` do
it. That is why the style has to travel on the path instead of being hard-coded in the
builder: `graphics_bitmap_fill` strokes one rect through `GraphicsStroke` (butt caps) and
one through `lineStyle` (round caps) in the same frame.

**The fan is not "a fine arc" — it reproduces lyon's segment count.** Ruffle tessellates
runtime strokes with lyon's `StrokeTessellator` at `StrokeOptions::DEFAULT_TOLERANCE`
(0.1 px) / render scale. `lyon_tessellation-1.0.15/src/stroke.rs`:

```
circle_flattening_step(r, tol) = 2 * acos((r - tol) / r)        (:2749)
num_segments     = ceil(|sweep| / step)                          (:2003, :2489)
num_subdivisions = round(log2(num_segments))                     (:2004, :2490)
tessellate_arc bisects the sweep num_subdivisions times          (:2612)
```

so the ACTUAL count is `2 ^ round(log2(ceil(|sweep| / step)))` — a power of two, not the raw
ceiling — and the fan vertices sit on the exact circle of radius r about the join vertex.
Getting this wrong in the *finer* direction is not conservative: lyon's chords are
**inscribed**, so a finer fan hugs the true circle, which lies strictly OUTSIDE lyon's
polygon. Our helpers reproduce the formula with tol = 2 twips (0.1 px at scale 1) and a
64-segment ceiling. Cross-checked standalone (`<scratch>/w2-gfx-strokes/geom.c`, `geom2.c`,
built and run):

```
segs(r = 50 tw = 2.5 px, sweep = pi/2) = 4    lyon: ceil(1.5708/0.5676)=3 -> round(log2 3)=2 -> 4
segs(r = 50 tw,          sweep = pi)   = 8    lyon: ceil(3.1416/0.5676)=6 -> round(log2 6)=3 -> 8
segs(r = 2550 tw,        sweep = pi)   = 32
```

and the emitted fans verified to land on the circle to the last digit (all `|Q-V|` = 50.000
twips at half-width 2.5 px, both for a 90° join and for a semicircular cap).

A round CAP is two quarter sweeps in lyon (`tessellate_round_cap` subdivides from
`|diff| = pi/2` and emits the arc twice), so a semicircular cap is `2 * segs(pi/2)` segments
— **not** `segs(pi)`. Implemented that way.

Two incidental improvements fall out, both relevant to `w1-gfx-smalls-report.md` §6 lead 2:

* the sweep is `atan2(cross(o0,o1), dot(o0,o1))` — the signed short way round — so the new
  runtime code has **no ±π wrap bug**. (The recompiler's `drawLineJoin` still uses `min`/`max`
  of two absolute angles and still fans the long way round when the two segment angles
  straddle π. Untouched here; still an open lead.)
* the miter limit is now honoured as a *value* (`cos_half * limit > 1`) instead of the
  hard-coded 4, and a limit below lyon's `MINIMUM_MITER_LIMIT` (1.0) degrades to bevel the
  way Ruffle's tessellator does.

### B. Twip truncation of drawing-API points

`swf/src/types/twips.rs:102` — `Twips::from_pixels(p) = (p * 20.0) as i32`, truncation
toward zero. Ruffle's runtime `Drawing` stores every pen command as a `Point<Twips>`, and
`render/src/tessellator.rs:386` converts back with `point.x.to_pixels() as f32` before
handing the path to lyon, so Ruffle's tessellator provably never sees a sub-twip
coordinate; `graphics.rs::draw_round_rect_internal` (which `drawCircle` / `drawEllipse` /
`drawRoundRect` funnel through) builds every anchor and control with `Point::from_pixels`.

Both runtimes now quantize at the same place — command-record time (`drawingAddCmd` /
`gfx_add_cmd`) — and both coercion paths were widened to `double` first so the truncation
sees the full-precision value rather than a float-rounded one. AVM1 **does** share the
mechanism (same Ruffle `Drawing`), so it is quantized too; the AVM1 quantization is what
takes `movieclip_begin_gradient_fill`'s max diff from 255 to 209 alongside the join win.

Deliberately NOT quantized: the bounds accumulators (`drawingUpdateBounds`,
`draw_union_stroke`). They already funnel through `twips_from_pixels`, and our AVM1 bounds
rule (full thickness per side, not half) is a separate known divergence — folding
quantization into it would have mixed two mechanisms into one A/B.

## 3. Per-comparison before/after

Method: two graded legs run **concurrently** against two source trees — `after` is this
worktree, `before` is a scratch copy of it (`<scratch>/w2-gfx-strokes/btree`) whose three
touched files were restored from `HEAD` and byte-verified with `diff` against
`git show HEAD:<path>`. Same test dirs, same local Dawn, `--mode=graphics --images`, one job
per leg. Absolute outlier counts are local-Dawn numbers and are NOT a CI grade — but see the
calibration note below.

**28 tests, 0 trace-status changes, 9 image rows moved, 19 byte-identical.**

### Moved (all in the improving direction)

| comparison | tol / max_out | before | after | verdict |
|---|---|---|---|---|
| `avm2/graphics_bitmap_fill` [output] | 5 / 60 | 64 outliers, max diff 100 — FAIL | **PASS**, max diff 51 | **FLIP** |
| `avm2/mouse_pick_dobj_mask` [output] | 1 / 0 | 6 outliers, max diff 255 — FAIL | **PASS**, 0 outliers, max diff 0 | **FLIP** (byte-exact) |
| `avm2/mouse_pick_non_interactive_dobj_mask` [output] | 1 / 0 | 6 outliers, max diff 255 — FAIL | **PASS**, 0 outliers, max diff 0 | **FLIP** (byte-exact) |
| `visual/drawing_api/fills_and_lines` [output] | 2 / 0 | 104 outliers | 4 outliers | improved, still FAIL |
| `avm2/graphics_draw_path` [output] | 0 / 0 | 204 outliers | 4 outliers | improved, still FAIL |
| `avm1/movieclip_begin_gradient_fill` [output] | 6 / 0 | 672 outliers, max diff 255 | 132 outliers, max diff 209 | improved, still FAIL |
| `avm2/displayobject_getbounds_shape` [output] | ? / 3800 | 22 290 outliers | 19 086 outliers | improved, still FAIL |
| `avm2/graphics_simple_shapes` [output] | 0 / 0 | 240 outliers | 230 outliers | improved, still FAIL |
| `from_shumway/acid/acid-shapes` [output] | 0 / 0 | 42 012 outliers | 41 577 outliers | improved, still FAIL |

### Byte-identical (19) — the no-regression evidence

`avm1/duplicate_movie_clip_drawing`, `avm1/hittest_winding_rule`, `avm1/mask_with_drawing`
(PASS→PASS, 0 outliers), `avm1/movieclip_hittest`, `avm2/graphics_bad_direct_commands`
(PASS), `avm2/graphics_direct_commands` (587, unchanged), `avm2/graphics_path`,
`avm2/graphics_round_rects`, `avm2/mouse_pick_button_mode`, `avm2/mouse_pick_masking`,
`avm2/mouse_pick_text`, `from_shumway/doubleAndRegister` (26, unchanged),
`visual/drawing_api/cursor` (**PASS at tolerance 0, held**),
`visual/drawing_api/drawing_order` (6664, unchanged),
`visual/drawing_api/gradient_focal_point` (60, unchanged), and the four `regression`
fixtures `avm1_parent_child_render`, `avm2_graphics_runtime` (skip),
`avm2_timeline_stroke_gradient`, `mask_sibling_union` — all PASS→PASS.

### Local/CI calibration (incidental, worth recording)

Every before-leg number that has a CI board entry matched it **exactly**:
`graphics_bitmap_fill` 64, `mouse_pick_dobj_mask` 6, `mouse_pick_non_interactive_dobj_mask` 6,
`fills_and_lines` 104, `graphics_draw_path` 204, `graphics_simple_shapes` 240,
`drawing_order` 6664, `gradient_focal_point` 60, `doubleAndRegister` 26,
`movieclip_begin_gradient_fill` 672, `displayobject_getbounds_shape` 22 290,
`acid-shapes` 42 012, `graphics_direct_commands` 587. For **this family** local Dawn and CI
lavapipe agree channel-for-channel, so the moves above can be read as grade changes and not
only as directions. That is a statement about these rows, not a general licence — the
canary's warning about `bitmapdata_copypixels` still stands for other families.

## 4. Canary ledger

### Render canary (`ruffle-tests/render_canary.py`)

```
RENDER CANARY  before=before  after=after   10 tests / 16 comparisons
  IDENTICAL    16
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

**md5 identity on 16/16 comparisons** — no test in the canary set uses a runtime stroke or
the drawing API, and none moved, which is exactly the predicted result.

Set: trimmed to the ten standing-set members the graded legs do NOT already cover with full
image stats (`<scratch>/w2-gfx-strokes/canary_tests.txt`) — `avm1/color`,
`avm1/movieclip_setmask`, `avm1/bitmap_data_fillrect`, `avm2/blend_multiply_alpha`,
`visual/simple_shapes/winding_rule`, `visual/cache_as_bitmap/shape_changed`,
`from_shumway/timeline/timeline_as2_5`, `from_shumway/acid/acid-gradient-0`,
`regression/avm2_timeline_gradients`, `regression/mask_nested_intersect`. The standing-set
members that DO exercise this change — `avm1/mask_with_drawing`,
`regression/avm2_timeline_stroke_gradient`, `regression/mask_sibling_union` — are in the
graded legs instead, where per-comparison outliers are strictly more informative than md5;
all three are PASS→PASS with identical stats. The trim is stated rather than glossed: it was
a deliberate call against a shared machine at load average ~30.

### Trace canary

The graded legs are trace runs as well: **28/28 tests, zero trace-status changes.** That
includes every hit-test reader in the brief — `avm2/mouse_pick_dobj_mask`,
`mouse_pick_non_interactive_dobj_mask`, `mouse_pick_masking`, `mouse_pick_button_mode`,
`mouse_pick_text`, `avm1/movieclip_hittest`, `avm1/hittest_winding_rule` — all
byte-identical trace output despite the geometry moving by up to 0.05 px. `graphics_draw_path`
was `ruffle_matched` before and after (no `pass → ruffle_matched` drift).

### `regression` suite

Four render fixtures run in the legs (`avm1_parent_child_render`, `avm2_graphics_runtime`,
`avm2_timeline_stroke_gradient`, `mask_sibling_union`) plus two more in the canary
(`avm2_timeline_gradients`, `mask_nested_intersect`): **all six unchanged, all PASS/skip.**
No regression test flipped, so no README needed reading.

### Known small divergences left in place (deliberate)

* **Miter limit is not clamped or `Fixed8`-quantized.** Ruffle's AVM1 `lineStyle` clamps
  `args[7]` to `0..255` and stores `Fixed8::from_f64(limit)` (1/256 steps); we keep the raw
  float. The threshold moves by <0.4 %, no corpus test passes an explicit
  `joints = "miter"`, and adding it after the legs had started would have invalidated the A/B.
* **Past the miter limit we bevel; lyon MITER-CLIPS.** `tessellation::LineJoin::MiterClip`
  truncates the spike at the limit distance instead of collapsing to the bevel chord. Same
  reasoning: unexercised, and it is the *non-default* join.

## 5. Refutations

1. **`fills_and_lines` 104 → 0 is REFUTED on magnitude.** w1 found "100 % of the residual is
   this mechanism"; that is true of the *clusters* — every one of the seven it named is gone
   — but the row lands at **4** residual channels, not 0, and `max_outliers = 0` means it
   still fails. A 96 % reduction is not a flip. The remaining 4 channels are a different
   mechanism and need their own diagnosis (lead 6 below).
2. **`from_shumway/doubleAndRegister` is NOT a runtime-stroke row.** w1 §2 listed it under
   "same mechanism present but does not flip", calling it "plausibly a full flip" once the
   round-end question was settled. It is **26 outliers before and 26 after — bit-identical**.
   Its green stadium is a DefineShape stroke, so it goes through the *recompiler's*
   `drawLineJoin`/`drawLineCap`, which were already round and which this patch does not
   touch. Anyone pricing that row must price it against `SWFRecomp/src/swf.cpp`, not the
   runtime — and the live sub-question there is the fan resolution and the ±π wrap (leads 2
   and 3), not "round vs miter".
3. **Round caps did NOT regress `visual/drawing_api/cursor`.** This was the sharpest risk in
   the change: `cursor` passes at `tolerance = 0, max_outliers = 0` *today*, with butt caps,
   and its open red diagonal and green vertical are exactly what a round cap extends. It is
   **byte-identical** across the A/B. (Mechanically: its strokes are hairlines, and lyon's
   `tessellate_round_cap` early-returns when `radius < tolerance`; at our nominal 0.5 px
   half-width the two-segment quarter fan lands inside the same pixels the butt cap did.)
4. **A round join/cap is NOT "just tessellate the arc finely".** The obvious implementation —
   subdivide until the sagitta is under a tenth of a pixel — is *systematically wrong in the
   direction that costs pixels*, because lyon's chords are inscribed and a finer fan
   therefore covers MORE than Ruffle's. The count has to be lyon's own
   `2 ^ round(log2(ceil(|sweep| / step)))`, which for a 5 px stroke at a 90° corner is
   **4** segments, not "enough for 0.1 px".
5. **A round CAP is not `segs(pi)`** but `2 * segs(pi/2)`. At half-width 2.5 px both happen
   to be 8; the formulas diverge as soon as `ceil()` and `round(log2())` land in different
   buckets.
6. **`LineStyle::allow_close` is inert in Ruffle.** Both AVM1 and AS3 `lineStyle` end with
   `.with_allow_close(false)`, which looks like it should suppress the closing segment of a
   stroked sub-path. `grep -rn allow_close` over the whole Ruffle tree finds the flag defined
   at `swf/src/types.rs:836` and set in three call sites — **and read nowhere**.
   `DrawPath::Stroke.is_closed` comes from `core/src/drawing.rs` instead (`cursor ==
   fill_start`, or unconditionally true with a fill open, in which case a `LineTo(fill_start)`
   is appended). Our existing `_DR_CONTOUR_NEEDS_CLOSE` / `_DR_CONTOUR_EXPLICIT_CLOSED` pair
   already implements exactly that rule, so no change was needed — but "Ruffle sets
   allow_close(false), so runtime strokes are never closed" is a plausible-sounding claim
   that is simply false.

### A self-inflicted bug worth recording, because its signature is misleading

While wiring mechanism B I dropped `c->type = type;` from `gfx_add_cmd`. The symptom was NOT
"the drawing is slightly off": every AVM2 pen command inherited a stale `type` from the
recycled command slot, so `gfx_finalize_path` mis-classified move/line/curve, the fill
tessellation produced nothing, and `mouse_pick_dobj_mask` came back with **both hit-test
lines flipped to `target=null` and 9 741 outlier channels**. I lost a long stretch hunting a
subtle quantization interaction, on the reasoning that a 0.05 px geometry change cannot break
a hit test 20 px from the edge — the reasoning was right and the premise was wrong. For the
next agent editing `gfx_add_cmd` / `drawingAddCmd`: when a drawing-API change produces a
*categorical* failure (geometry absent, hit test dead) rather than a sub-pixel one, suspect
the command record, not the coordinates.

## 6. New unclaimed leads

1. **`LINESTYLE2` join/cap style is still parsed and thrown away.** Re-verified:
   `SWFRecomp/src/swf.cpp:7564` and `:8004` read `join_style`, the `EndCapStyle` byte and
   (for `join_style == 2`) the `MiterLimitFactor`, and the last even carries the comment
   "Miter limit parsed and ignored for now". Nothing downstream consumes any of them;
   `drawLineJoin`/`drawLineCap` are unconditionally round. This work made the *runtime*
   honour the style, so the recompiler is now the only place where a declared `miter`/`bevel`
   join or a `square`/`none` cap is silently discarded. The runtime's new
   `drawing_emit_stroke_join` / `drawing_emit_stroke_cap` take the style as a parameter and
   lift into `swf.cpp` almost verbatim (it works in whole twips and pushes `Tri`s, so only
   the vertex sink changes). Still **unpriced** — pricing needs a corpus grep for
   DefineShape4 line styles with a non-default `JoinStyle`/`CapStyle`.
2. **The recompiler's `drawLineJoin` still fans the long way round across ±π.**
   `SWFRecomp/src/swf.cpp:11404-11406` takes `start_angle = min(angle_a_b, angle_b_c)` /
   `end_angle = max(...)` from two `atan2` results with no wrap handling, so a join whose two
   segment angles straddle π sweeps `2π − θ` and paints a disc where a wedge belongs. The
   runtime no longer has this bug, so the two builders now disagree. **`doubleAndRegister`
   (26 channels, tol 0) is the priced probe** — refutation 2 above shows it is a
   recompiler-side row, and its residual is at the rounded ends of a stadium shape, in both
   directions.
3. **The recompiler's fan resolution is a fixed `num_midpoints = 5`.** Now that the runtime
   reproduces lyon's `2 ^ round(log2(ceil(|sweep| / step)))` exactly, the fixed 5 is
   measurably wrong in both directions: too coarse for a thick stroke (lyon uses 32 segments
   over π at half-width 127 px) and too fine for a hairline (2 over π/2 at half-width 0.5 px).
   `drawing_arc_segments` in `action.c` is a drop-in. Rides along with lead 2 on the same
   rows.
4. **A single-point sub-path draws nothing for us.** lyon emits an "empty round cap" (a full
   disc) for a sub-path that is only a `moveTo`
   (`lyon_tessellation/src/stroke.rs::tessellate_empty_round_cap`), and an empty square cap
   for `caps = "square"`. Both runtime builders skip a 1-point contour outright. A
   `moveTo(x,y)` with a live `lineStyle` and no `lineTo` should paint a dot and paints
   nothing. Unpriced; a one-contour special case in the same function.
5. **A 2-point FILLED contour is capped by us and closed by Ruffle.** Our
   `_DR_CONTOUR_NEEDS_CLOSE` / `_GNEEDCLOSE` require `>= 3` points before auto-closing a
   filled contour, so a 2-point one falls through to the new open-polyline arm and gets two
   end caps. Ruffle closes *any* pending line when a fill is open (`core/src/drawing.rs:280-288`,
   unconditional `LineTo(fill_start)`), which for 2 points means a degenerate closed path with
   joins and no caps. At most one half-disc per end on a degenerate stroke; noted rather than
   fixed because the `>= 3` guard also governs the fill auto-close rule.
6. **The two 4-channel residuals are the cheapest rows left in this family.**
   `visual/drawing_api/fills_and_lines` (104 → **4**, tol 2 / max_out 0) and
   `avm2/graphics_draw_path` (204 → **4**, tol 0 / max_out 0) are both one mechanism away from
   flipping and both now sit at four channels. They are the natural rider for whoever picks
   up stroke work next: two flips for one diagnosis, and the diagnosis is cheap because the
   surviving pixels are few enough to dump individually.
7. **`avm2/displayobject_getbounds_shape` moved 22 290 → 19 086 without being priced.** A
   14 % move on a 22 k-channel row means runtime strokes are a real but minority component of
   it; the other 86 % is a separate, much larger mechanism that nobody has named. Worth a
   cluster pass — it is the biggest row this change touched at all.
8. **`ACCEPTED_DIFFS.md` (avm1) line 873 is now doubly stale.** w1 already flagged that the
   `movieclip_begin_gradient_fill` entry describes a 1266-px gradient ramp/banding gap while
   the row was at 672 and join-dominated. It is now at **132 channels with max diff 209**, so
   both the magnitude and the named mechanism in that entry are wrong. Re-scoping it needs a
   fresh look at what the remaining 132 actually are — plausibly the ramp at last.
