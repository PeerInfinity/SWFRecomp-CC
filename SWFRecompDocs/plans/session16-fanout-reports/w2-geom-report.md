# w2-geom — Session 16 wave-2 (L1 twip-quantised point transform · L2 flash.geom completion)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a70f0453712057ff4`
Patches (in the worktree, under `SWFRecompDocs/plans/session16-fanout-reports/`):

- `w2-geom-a.patch` — **Task A only** (L1), safe to merge on its own.
- `w2-geom.patch` — **A + B**, the full deliverable.

## NEW FILES CREATED BY THIS PATCH

**None.** Exactly two existing files are edited:

- `SWFModernRuntime/src/avm2/avm2_display.c`
- `SWFModernRuntime/src/avm2/avm2_stage3d.c`

`ruffle-tests/tests/swfs/avm2/ignored_tests.txt` was **NOT** edited, to keep the
merge clean for `w2-ignore-bucket` who owns that file.

> **Ignore-list hand-off (for the coordinator — `w2-ignore-bucket` has already
> merged its rewrite of this file, so this is a follow-up one-liner on master):**
> **`geom_transform` now PASSES** with this patch and its entry under the
> re-triaged image-comparison block should be **deleted**. `stage_scale_factor`,
> `displayobject_scrollrect` and `displayobject_hittestpoint_boundary` still
> fail (for the reasons in §2) and must stay — in particular
> `stage_scale_factor` is **NOT** flipped by the twip fix, contrary to
> `w2-ignore-bucket-report.md` §5's expectation, so its line must be kept.
> Either way this does not move the 4298/4443 counter: that metric is
> `pass + ruffle_matched` straight out of `results_graphics.json` and consults
> no ignore list; the list only affects the *filtered* markdown.

---

## 1. Verdicts up front

| task | brief price | verdict | flips |
|---|---|---|---|
| **L1** twip-quantise `localToGlobal`/`globalToLocal` | +1 / +2 / +4 | **LAND — but the pricing is REFUTED: 0 flips** | none |
| **L2** flash.geom completion | +1 / +2 / +4 | **GO — 3 flips** | `avm2/matrix`, `avm2/geom_transform`, `from_shumway/avm2/flash/geom/matrix3d/TransformBasics` |

Net measured: **+3 effective, 0 regressions** across a 50-test target+canary
sweep — all three flips from L2.

| flipped test | baseline | after |
|---|---|---|
| `avm2/matrix` | `output_mismatch`, 282/338 lines, `#1006 copyRowTo is not a function` | **pass** |
| `avm2/geom_transform` | `output_mismatch`, 21/74 lines, `#1009 (accessing field: rawData)` | **pass** |
| `from_shumway/avm2/flash/geom/matrix3d/TransformBasics` | `output_mismatch` | **pass** |

L1 is still worth merging: it is the *same* arithmetic rule `rect_union_xform()`
already uses two hundred lines above it, it is provably a move toward the oracle
(reproduced digit-for-digit offline, see §2), and it removes 8 of the 14 diff
lines in `displayobject_scrollrect`. It just cannot flip a test on its own,
because every row the brief priced for it is limited by a *different*
mechanism.

---

## 2. L1 — mechanism confirmed, pricing refuted

### The fix (4 effective lines, `avm2_display.c` `point_transform_native`)

Ruffle `render/src/matrix.rs impl Mul<Point<Twips>>`:

```rust
let out_x = Twips::new(round_to_i32(self.a * x + self.c * y).wrapping_add(self.tx.get()));
```

with `x`/`y` already whole twips (`Twips::from_pixels` = `(px * 20.0) as i32`,
i.e. **truncation**, not `.round()` as the brief said). We were doing the whole
product in `double` and adding the translation before any quantisation.

Replaced with the idiom already used by `rect_union_xform()`:

```c
float xt = (float) twips_from_pixels(x);
float yt = (float) twips_from_pixels(y);
double tx = round_twips_f32((float) ((float) m.a * xt + (float) m.c * yt)) + m.tx;
double ty = round_twips_f32((float) ((float) m.b * xt + (float) m.d * yt)) + m.ty;
```

`twips_from_pixels()` already truncates and already matches Rust's `as i32`
saturation/NaN rules, so no new helper was needed. **No new file, no new helper,
no struct field.**

### Offline verification (standalone C probe, before touching the tree)

Feeding `displayobject_scrollrect`'s two real matrices through the new
expression reproduces the Flash oracle exactly:

| call | expected (Flash) | probe |
|---|---|---|
| `circle.localToGlobal(10,20)` | `(x=55, y=76)` | `(55, 76)` |
| `circle.globalToLocal(10,20)` | `(x=-21.4, y=-21.4)` | `(-21.399999999999999, …)` → prints `-21.4` |
| `scrollChild.localToGlobal(10,20)` | `(x=149.7, y=180.6)` | `(149.69999999999999, 180.59999999999999)` |
| `scrollChild.globalToLocal(10,20)` | `(x=-52.25, y=-67.5)` | `(-52.25, -67.5)` |

Note the third row also silently vindicates leaving `mat_mul`'s `a/b/c/d` in
`double`: the `(float)` cast at the *use* site rounds the composed
`a = 1.7099998766183875` to `1.7099999189376831`, which is precisely the value
Flash prints for that concatenated matrix. Composing in f32 is therefore NOT
needed for the point path.

### Why the 5 priced rows do not flip (each attacked individually, at HEAD)

| row | brief's claim | measured reality |
|---|---|---|
| `avm2/displayobject_scrollrect` (19/33 match) | "plausibly a clean +1; every diff line is a localToGlobal/globalToLocal pair" | **False, and measured after the patch: 14 diff lines → 6.** The 8 L1 lines are now byte-exact. The surviving 6 are (a) the four `After 50ms delay` localToGlobal/globalToLocal lines, which need the *committed-at-render* scrollRect that `do_scrollrect_set`'s own comment says is deliberately unmodelled; (b) `scrollChild.transform.concatenatedMatrix` `tx/ty` `125,146` vs `54,64` — the same missing scroll-rect offset; (c) `hitTestPoint(400,400,true)` `true` vs `false`, again the scrollRect crop. **No flip.** (The "matrix already matches byte-for-byte" premise is also mis-stated but harmless: `b`/`c` differ by exactly +1 f32 ULP, and the test's `[approximations] max_relative = f32::EPSILON` tolerates that.) |
| `avm2/displayobject_hittestpoint_boundary` (47/65) | "partly this" | **Not an L1 row at all.** The test never calls localToGlobal. Its entire diff is one line-offset (expected starts with a blank line from `trace("")` that our actual side does not carry) plus 10+10 octagon-edge `hitTestPoint(…, true)` results that should be `false` — an edge-exclusivity rule in the shape hit test. |
| `avm2/bounds_mode` (253/269) | "one ULP, i.e. this mechanism" | **Not an L1 row at all** — diff-line count is 32 before AND after the patch. No localToGlobal anywhere. Its 16 diffs are 10 × `transform.pixelBounds` (a `0.75px` origin offset, and one row where Flash reports `(x=12,y=192,w=0,h=0)` against our `(10,190,530,140)`) and 6 × `scaleX`/`scaleY` ULPs from the `width=`/`height=` setter path (`3.0769230769230775` vs `3.076923076923077` = `200/65` computed two different ways). |
| `avm2/stage_scale_factor` (6/12) | "the localX/localY lines" | **Cannot pass, ever, in this harness.** Line 1 of its own fixture: "This test MUST be run under a (possibly simulated) display with a scale factor of 2"; 3 of the 6 diffs are `contentsScaleFactor: 2` vs `1`. The `localToGlobal(0,0)` line is a *zero* point, so quantisation is a no-op on it — it differs because Flash's Stage ignores its own matrix for localToGlobal, a separate rule. **No flip; do not un-ignore it.** |
| `avm2/matrix` (282/338) | "same class; also needs L2's copyRowTo" | **Zero ULP content.** The measured diff is exactly two things, both L2's: `createBox(2,3)` with the optional rotation omitted returns `(a=NaN,b=NaN,c=NaN,d=NaN)`, and `copyRowTo` is not a function (aborts, cascading the remaining 55 lines). |

**Refutation of record:** the L1 cluster as briefed is a *diff-line* lead, not a
*flip* lead. Nothing else in the corpus is localToGlobal-limited — a content
grep over `avm2`, `from_shumway`, `avm1`, `visual`, `text`, `timeline`,
`mixed_avm` for `localToGlobal|globalToLocal` returns only the rows above plus
AVM1 tests (different code path, `action.c`, untouched) and
`from_shumway/avm1movie` (already `ruffle_matched`).

**Completion mechanism for `displayobject_scrollrect`** (what would flip it):
a *committed* scroll rect latched at render/frame time (Ruffle's
`next_scroll_rect` → `scroll_rect`) plus `Matrix::translate(-x_min,-y_min)`
folded into `display_world_matrix()` for the object itself and each ancestor.
That is a real change to `Avm2DisplayObjectExt` + the frame loop, must be driven
by the frame loop (not the renderer) to hold no-graphics/graphics parity, and is
out of an XS brief's scope. Worth its own lead — it is 6 diff lines in
`scrollrect` plus the correct `hitTestPoint` crop.

---

## 3. L2 — flash.geom completion (GO, 3 flips)

Five distinct gaps, all confirmed by measured diffs at HEAD.

### 3.1 `Matrix.copyRowTo` / `Matrix.copyColumnTo` were never registered
Only the `…From` halves existed. Added both, ported from Ruffle
`core/src/avm2/globals/flash/geom/Matrix.as:57-71,97-111` (row2 → `(0,0,1)`,
column2 → `(tx,ty,1)`, out-of-range index leaves the vector untouched).

### 3.2 `Matrix.copyColumnFrom` was implemented as a real column copy — it isn't
Flash's `copyColumnFrom` **is literally `copyRowFrom`** (an FP bug Ruffle
replicates verbatim with the comment "For some reason these methods are
identical"). `avm2/matrix`'s oracle proves it:
`copyColumnFrom(1, <17,19,23>)` on `(2,3,5,7,11,13)` gives
`(a=17,b=17,c=19,d=19,tx=23,ty=23)` — the b/d/ty **row**, not the c/d column.
Our column implementation produced the wrong matrix. Now a one-line delegation.
*(This one was not in the brief — found by grading the fixture.)*

### 3.3 `Matrix.createBox`'s `rotation` argument is optional
`createBox(2, 3)` poisoned the whole matrix with `NaN` because rotation was read
with `matf_arg` (NaN when absent) instead of `matf_arg_def(…, 0.0)`.
`createGradientBox` right below it already had the default. *(Also not in the
brief.)*

### 3.4 `Transform.matrix` / `Transform.matrix3D` duality
Ported Ruffle's `has_matrix3d_stub` bit
(`core/src/avm2/globals/flash/geom/transform.rs`):

| assignment | effect |
|---|---|
| `.matrix = <Matrix>` | write the 2D matrix, **clear** the bit |
| `.matrix = null` | **set** the bit, leave the matrix alone (and do NOT mark transformed-by-script) |
| `.matrix3D = <Matrix3D>` | **set** the bit, collapse the 4×4 to `(a,b,c,d,tx,ty) = (raw0,raw1,raw4,raw5,Twips(raw12),Twips(raw13))` |
| `.matrix3D = null` | **clear** the bit, reset the matrix to IDENTITY (not to what it was) |

Getters return `null` when the bit disagrees with them; `matrix3D`'s getter
promotes the 2D matrix with `Matrix3D::from_matrix` (column-major, translation
in column 3). `DisplayObject.transform = other` copies the bit too (Ruffle's
`set_transform` reads the *base* matrix + the bit, bypassing the getter) — here
that is done by reading the source's `.matrix3D` when its `.matrix` reads null.

**Self-localisation:** the bit is a `dont_enum` dynamic property `__m3dstub` on
the *display* object — the same trick `perspectiveProjection`'s `Option` already
uses in this file — so **no field was added to `Avm2DisplayObjectExt`** and
nothing in `w2-all-classes-display`'s descriptor tables is touched.

`flash.geom.Matrix3D` is minted in `avm2_stage3d.c`, so two small exported
doors were added there (`avm2_geom_matrix3d_new` / `avm2_geom_matrix3d_read`),
placed immediately before `matrix3d_identity` and touching nothing else.

### 3.5 `Transform.getRelativeMatrix3D` + Error #2189
- `getRelativeMatrix3D(relativeTo)` registered: throws `#2007` on a null
  argument, returns `null` for a 2D object, an IDENTITY `Matrix3D` for a 3D one
  (Ruffle `transform.rs:426-443`).
- **`#2189`** — "A Matrix3D can not be assigned to more than one DisplayObject."
  This is an **FP rule Ruffle does not have**, but the graded oracle for
  `TransformBasics` is `output.txt` (Flash), and it expects the throw. A
  `dont_enum` `__m3downer` back-pointer on the `Matrix3D` instance implements
  it; re-assigning a `Matrix3D` to its *own* owner is allowed (which
  `geom_transform`'s `test3D` requires).
  Ruffle's own `output.ruffle.txt` for this test is doubly stale (it lacks
  `#2189` *and* returns `[object Matrix3D]` where current Ruffle source returns
  `null`), so `ruffle_matched` was never reachable here — full Flash parity is.

---

## 4. Per-test ledger

Baseline = merged CI run `31748059158` at `3db858cbc` (graphics / full).
"before" and "after" are local `--mode=graphics` runs in this worktree.

### 4.1 Targets

| test | baseline (CI) | before (local) | after (local) | verdict |
|---|---|---|---|---|
| `avm2/matrix` | output_mismatch 282/338 | 94 diff lines | **PASS, 0 diff lines** | **FLIP +1** |
| `avm2/geom_transform` | output_mismatch 21/74 | 100 diff lines | **PASS, 0 diff lines** | **FLIP +1** |
| `from_shumway/avm2/flash/geom/matrix3d/TransformBasics` | output_mismatch | 22 diff lines | **PASS, 0 diff lines** | **FLIP +1** |
| `avm2/displayobject_scrollrect` | output_mismatch 19/33 | 28 diff lines | output_mismatch, **12** diff lines | improved, no flip (L1) |
| `avm2/displayobject_hittestpoint_boundary` | output_mismatch 47/65 | 132 | 132 (identical) | unchanged — not an L1 row |
| `avm2/bounds_mode` | output_mismatch 253/269 | 32 | 32 (identical) | unchanged — not an L1 row |
| `avm2/stage_scale_factor` | output_mismatch 6/12 | 12 | 12 (identical) | unchanged — unfixable (needs a 2× display) |
| `avm2/displayobject_transform` | output_mismatch 67/89 | *false `compile_fail` under load* | output_mismatch, 44 diff lines (= 22 pairs = baseline) | unchanged, no regression |

`avm2/displayobject_transform` was priced as "the fourth row in the family" and
is **not** — it contains no `matrix3D`, `copyRowTo` or `createBox` use at all.
Its 22 missing lines are the quality-scaled `concatenatedMatrix` family
(`best/high/16x16/8x8/low/medium` TextField-vs-stage rows), an unrelated lead.

### 4.2 Full ledger (targets + canaries)

All 50 tests below were run locally in this worktree with
`verify_output.py --mode=graphics --diff`. **Result: 3 flips, 0 regressions.**

> **OOM caveat, and how it was handled.** The box was running ~10 agents at
> load 25-36 with 15 GB RAM; 17 of the 50 runs came back as an empty log
> ("Killed" — the OOM killer took gcc) or `compile_fail`. Every one of those was
> re-run strictly afterwards on an idle box with
> `SWFRECOMP_COMPILE_TIMEOUT=2400`, and **every one passed**. The table below is
> the re-run result. Treat a bare `compile_fail` on this box as noise, per the
> `verify-output-parallel-batching` note.

| test | baseline (CI) | after (local, graphics) | |
|---|---|---|---|
| `avm2/displayobject_scrollrect` | output_mismatch | output_mismatch | same |
| `avm2/displayobject_hittestpoint_boundary` | output_mismatch | output_mismatch | same |
| `avm2/bounds_mode` | output_mismatch | output_mismatch | same |
| `avm2/stage_scale_factor` | output_mismatch | output_mismatch | same |
| `avm2/matrix` | output_mismatch | pass | **FLIP** |
| `avm2/geom_transform` | output_mismatch | pass | **FLIP** |
| `avm2/displayobject_transform` | output_mismatch | output_mismatch | same |
| `from_shumway/avm2/flash/geom/matrix3d/TransformBasics` | output_mismatch | pass | **FLIP** |
| `avm2/button_bounds` | pass | pass | same |
| `avm2/button_hittest` | pass | pass | same |
| `avm2/displayobject_hittestpoint` | pass | pass | same |
| `avm2/displayobject_hittestpoint_root` | pass | pass | same |
| `avm2/displayobject_hittestobject` | pass | pass | same |
| `avm2/displayobjectcontainer_getobjectsunderpoint` | pass | pass | same |
| `avm2/edittext_autosize_lazy_bounds_interactions` | pass | pass | same |
| `avm2/edittext_autosize_lazy_bounds_props` | pass | pass | same |
| `avm2/empty_bounds` | pass | pass | same |
| `avm2/flash_media_video_constructor` | pass | pass | same |
| `avm2/flash_media_video_rotation_probe` | pass | pass | same |
| `avm2/hittest_morph` | pass | pass | same |
| `avm2/movieclip_drawrect` | pass | pass | same |
| `avm2/movieclip_hittest` | pass | pass | same |
| `avm2/shape_drawrect` | pass | pass | same |
| `avm2/tab_ordering_arrows` | pass | pass | same |
| `avm2/displayobject_invalid_floats` | pass | pass | same |
| `avm2/displayobject_invalid_props` | pass | pass | same |
| `avm2/displayobject_set_matrix_nested` | pass | pass | same |
| `avm2/mouseevent_stagexy` | pass | pass | same |
| `avm2/perspective_projection_basic` | pass | pass | same |
| `avm2/stage_overriden_setters` | pass | pass | same |
| `avm2/stage_properties2` | pass | pass | same |
| `avm2/displayobject_getrect` | output_mismatch | output_mismatch | same |
| `avm2/localconnection` | output_mismatch | output_mismatch | same |
| `avm2/all_classes/display/swf9` | output_mismatch | output_mismatch | same |
| `avm2/all_classes/display/swf10` | output_mismatch | output_mismatch | same |
| `avm2/all_classes/display/swf11` | output_mismatch | output_mismatch | same |
| `avm2/all_classes/display/swf12` | output_mismatch | output_mismatch | same |
| `avm2/all_classes/display/swf13` | output_mismatch | output_mismatch | same |
| `avm2/all_classes/display/swf30` | output_mismatch | output_mismatch | same |
| `avm2/matrix3d` | pass | pass | same |
| `avm2/matrix3d_copy_row` | pass | pass | same |
| `avm2/matrix3d_copy_column` | pass | pass | same |
| `avm2/matrix3d_compose` | pass | pass | same |
| `avm2/blend_transform` | ruffle_matched | ruffle_matched | same |
| `avm2/displayobject_colortransform_nested` | pass | pass | same |
| `avm2/edittext_device_transform_layout` | ruffle_matched | ruffle_matched | same |
| `from_shumway/stroke1` | pass | pass | same |
| `from_shumway/mouse/mouse_coords` | pass | pass | same |
| `from_shumway/avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | pass | pass | same |
| `from_shumway/avm1movie` | ruffle_matched | ruffle_matched | same |

**0 regressions. 3 flips.**


---

## 5. Files touched

| file | scope |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_display.c` | `point_transform_native` (L1); `geom_matrix_create_box`, `geom_matrix_copy_column_from`, new `matf_v3_put`/`geom_matrix_copy_row_to`/`geom_matrix_copy_column_to`, new `m3d_stub_get`/`m3d_stub_set`/`m3d_from_ext`/`m3d_to_ext`, `transform_get_matrix`, `transform_set_matrix`, `transform_get_matrix3d`, new `transform_set_matrix3d`/`transform_get_relative_matrix3d`, `do_set_transform`, and the two registration blocks (L2) |
| `SWFModernRuntime/src/avm2/avm2_stage3d.c` | two new exported functions only (`avm2_geom_matrix3d_new`, `avm2_geom_matrix3d_read`), inserted immediately above `matrix3d_identity` |

`transform_set_stub` is left in place (now unused) to keep the diff minimal;
the build uses no `-Wall`/`-Werror`.

**Sibling-overlap audit.** `w2-all-classes-display` owns the `dt_*` descriptor
tables in `avm2_globals.c` (untouched) and `avm2_display.c` generally. Every
edit here is inside a function named in the L1/L2 brief, or a brand-new `static`
inserted adjacent to one. No struct field, no header, no reformatting, no
descriptor table. The only cross-file symbols introduced are the two
`avm2_geom_matrix3d_*` doors in `avm2_stage3d.c`, declared `extern` at their
single point of use.

---

## 6. Residual leads this session produced (for the next board)

1. **Committed scroll rect** — `Ruffle next_scroll_rect → scroll_rect` latched
   per frame, plus `Matrix::translate(-x_min,-y_min)` in
   `display_world_matrix()` for self and each ancestor. Worth 6 diff lines and
   the `hitTestPoint` crop in `displayobject_scrollrect`; must be driven by the
   frame loop, not the renderer, for mode parity. Medium.
2. **`avm2/displayobject_hittestpoint_boundary`** is much closer than the board
   thinks: its 18 "missing" lines are one leading blank line (the fixture opens
   with `trace("")`; our actual side does not carry it — check whether the
   harness or the runtime eats it) plus a shape hit-test edge rule where a point
   exactly on an octagon vertex/edge must read `false`. Two independent small
   fixes, and the test flips. **Not** a geometry-quantisation row.
3. **`transform.pixelBounds`** (10 rows in `bounds_mode`) and the
   **quality-scaled `concatenatedMatrix`** family (22 rows in
   `displayobject_transform`, 5 rows in `bounds_mode`'s neighbours) are each a
   coherent single-mechanism cluster nobody owns yet.
4. **`width=` / `height=` setter ULPs** — `scaleX` reads `3.076923076923077`
   where Flash says `3.0769230769230775` (`200/65`). 6 rows in `bounds_mode`.
   These have no `[approximations]` cover, so they are real diffs.
5. **`Stage.localToGlobal` ignores the Stage's own matrix** in Flash
   (`stage_scale_factor` line 10). One-line rule, but that test still cannot
   pass (`contentsScaleFactor` needs a simulated 2× display), so it only pays if
   another test exercises it.
