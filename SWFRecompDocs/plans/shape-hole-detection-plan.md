# SWFRecomp Shape Hole-Detection Unification — Plan

**Document Version:** 1.0

**Created:** 2026-05-14

**Status:** ✅ Implemented (Phases A–C), then **largely SUPERSEDED** for plain
shapes by the libtess2 migration. See the status banner below.

> **STATUS UPDATE 2026-06-02 — read this before using the plan below.**
>
> This plan's Phases A–C **landed 2026-05-14** (`992c37d68` containment
> unification / `54053b79b` nesting-depth even-odd parity / `e2dc404e` drop
> dead `Shape::outer_fill`) — the original "Planned; no implementation yet"
> header was never updated.
>
> The spatial-containment hole classification those phases added has since been
> **superseded for plain (non-font, non-morph) `DefineShape/2/3/4` fills** by the
> **libtess2 tessellation migration** (`80c87edc0` even-odd prototype,
> `a0e5d431d` DefineShape4 non-zero + device-font glyphs). libtess2's
> even-odd / non-zero winding rules natively resolve multi-contour overlap,
> self-intersection, and holes — i.e. they directly realize what §"Reference
> behavior" below calls the *correct* approach (classify by spatial containment
> under the active fill rule), without the fragile earcut pre-classification.
> Plain-shape fills now route through `swf.cpp::tessellateContours()`; the old
> earcut + johnson-cycle + containment machinery this plan describes is **kept
> only for the `is_font` (embedded `DefineFont` glyphs) and `is_morph` paths**
> (morph needs per-vertex `morph_index` correspondence libtess2 can't preserve).
>
> Canonical current state: `tools/divergence/PROGRESS.md` follow-up **#6** and
> the `tessellation-libtess2-migration` auto-memory. The containment algorithm
> documented below remains accurate for the font/morph paths that still use it.

Driven by:

- **Font glyphs** rendering with their internal counters filled in
  (every `a`, `e`, `o`, `d`, `b`, `p`, `O`, `B`, `D`, `R`, `S`, `8` …
  shows up as a solid blob). Visible across every test that renders
  a TextField — `from_gnash/misc-ming.all/place_object_test`,
  `shape_test`, every dejagnu `_xtrace_win`, etc.
- **Non-font complex shapes** that should be filled but render as
  outlines only (driver case: the green C-shape inside
  `from_gnash/misc-ming.all/shape_test`'s sprites 7/9/11/13;
  204 stroke verts emitted, 0 fill verts).

Both symptoms trace to the same code in
`SWFRecomp/src/swf.cpp::interpretShape` — specifically the self-closed
path classification at lines 7572–7588 plus the hole-attachment pass at
lines 7698–7748. Today the two cases are handled by *opposite*
workarounds:

- **Fonts**: when one fill side is zero, *always* flip `fill_right` and
  emit as filled. Treats every glyph contour as solid → fills counters in.
- **Non-fonts**: when one fill side is zero, mark as `hole`. Then the
  later containment pass tries to attach the "hole" to a larger
  containing shape. If no container is found, the hole is silently
  dropped → C-shapes never render fills.

Neither workaround is correct. Flash, Ruffle, and the SWF spec all
classify outer vs hole by **spatial containment under the active fill
rule (even-odd or non-zero winding)**, not by which side of a single
path is non-zero.

---

## Table of contents

1. [Executive summary](#executive-summary)
2. [Symptoms that motivated this plan](#symptoms-that-motivated-this-plan)
3. [Reference behavior — Flash / Ruffle](#reference-behavior--flash--ruffle)
4. [Current state — SWFRecomp pipeline](#current-state--swfrecomp-pipeline)
5. [Gap analysis](#gap-analysis)
6. [Phase A — Defer outer/hole decision to the containment pass](#phase-a--defer-outerhole-decision-to-the-containment-pass)
7. [Phase B — Nesting-depth fill rule (even-odd & non-zero)](#phase-b--nesting-depth-fill-rule-even-odd--non-zero)
8. [Phase C — Optional: drop the `processShape` `fill_right` heuristic](#phase-c--optional-drop-the-processshape-fill_right-heuristic)
9. [Test strategy](#test-strategy)
10. [Risk register](#risk-register)
11. [Open questions](#open-questions)

---

## Executive summary

`interpretShape` builds a `std::vector<Shape>` from the SWF edge stream,
then triangulates each one with `fillShape` (which feeds
`mapbox::earcut`'s polygon+holes format). The fill/hole *role* of each
shape is decided at construction time in two places:

- **`processShape`** (line 8000) computes `signed_area`, sets
  `fill_right = signed_area < 0`, and writes
  `inner_fill = fill_styles[signed_area < 0]`.
- The block at lines 7572–7588 (and the analogous one for Johnson
  cycles at 7626 — both feed `processShape`) inspects the resulting
  `fill_styles[fill_right]` vs `fill_styles[!fill_right]`. When one side
  is zero and the other is non-zero, it forks: *font* → flip
  unconditionally, *non-font* → mark as hole.

Both forks are wrong. Hole/outer is a property of the shape's
**position in the nested-region hierarchy**, not of which fill side is
non-zero on any single path. The decision belongs to the containment
pass at line 7698 (which already does spatial sorting + point-in-shape
tests via `isInShape`), not to per-path inspection.

The fix is to:

- **Phase A.** Stop deciding outer/hole at construction time. Always
  build the shape with the non-zero side's fill style as `inner_fill`.
  Move the hole/outer determination entirely into the containment pass,
  removing the `is_font` fork. This restores the missing fills for
  C-shapes and analogous non-font cases.
- **Phase B.** Make the containment pass aware of nesting depth, with
  the active fill rule (even-odd by default; non-zero on the per-character
  `winding_nonzero` flag we already plumb through). A shape at even
  depth fills; at odd depth, it attaches as a hole to its immediate
  parent. This restores counters on glyphs with internal holes ('O',
  'B', '8', etc.) while keeping single-contour glyphs solid.
- **Phase C** (optional). Once Phase B is in, the `processShape`
  fill_right / signed_area heuristic is purely a fill-style picker
  (which of `fill_styles[0]` / `[1]` to read). Audit whether we can
  drop it or simplify it, since spatial containment now provides the
  semantic decision.

Phase A is sufficient to fix the C-shape regression. Phase B is required
to fix the visible font-glyph counter regression that affects every
rendered TextField. Phase C is cleanup.

---

## Symptoms that motivated this plan

### Symptom 1 — Font glyph counters filled in

Every TextField rendering shows letters with internal counters as solid
blobs:

- `from_gnash/misc-ming.all/place_object_test/output.actual.png`,
  trace line 2 (rendered at `y ≈ 19–24`). The string "Placed red shape
  sh1 and black shape sh2 at the same depth 3. Should both be visible,
  red on top." has `a`, `e`, `d`, `b`, `o`, `p`, `S`, `R` all rendered
  as solid silhouettes. Ruffle's `output.ruffle.png` for the same
  test, same y-range, shows the counters correctly.
- The same pattern appears in `output.actual.png` for every test that
  renders the dejagnu `_xtrace_win` (most `from_gnash/misc-ming.all/*`,
  `from_gnash/misc-swfc.all/*`).

Root cause: the `is_font` branch at line 7574 flips `fill_right` for
every self-closed path with one-sided fill. For glyphs like `o`, both
the outer ring AND the inner ring are self-closed paths with one-sided
fill. Both get flipped to "filled" and both emit fill triangles, so the
inner ring's "hole" region is opaquely painted.

### Symptom 2 — Non-font complex shapes drop their fills

`from_gnash/misc-ming.all/shape_test`'s sprites 7/9/11/13 each contain
a C-shape (shapes 6/8/10/12). The recompiled `shape_data` for shape 6
contains **204 stroke verts at color 0x66 (black), zero fill verts**.
By comparison, shape 4 (a rectangle in the same test) emits **6 fill
verts at color 0x61 + 84 stroke verts at color 0x62**. The C-shape's
fills are gone:

```
$ awk 'NR>=15117 && NR<=15320' RecompiledTags/draws.c \
    | grep -oP '0x[0-9A-F]+, 0x[0-9A-F]+ }' | sort | uniq -c
    204 0x80000000, 0x66 }
$ # vs shape 4:
    6 0x0, 0x61 }
    84 0x80000000, 0x62 }
```

Root cause: the `else` branch at line 7585 marks the C-shape's path as
`hole = true`, then the containment pass at line 7700 looks for a
containing outer shape. The C isn't inside any other shape, so the
"hole" is never attached, and the fill-triangulation pass at line 7755
skips it (`shape.hole == true` excludes it).

### Other affected tests

The same bug pattern likely affects (not yet verified individually):

- Every `from_gnash/misc-ming.all/*` and `from_gnash/misc-swfc.all/*`
  test that renders a dejagnu textfield. (Trace passes; image differs
  in the text region.)
- `avm1/edittext_*` tests rendered against the embedded font path.
- Any test with concave or holed non-font shapes.

---

## Reference behavior — Flash / Ruffle

Source: `ruffle/render/src/tessellator.rs` (path → triangulation),
`ruffle/render/src/lib.rs` (`FillRule` enum), Adobe SWF File Format
Specification §3.6 ("Drawing Shapes").

### SWF spec

A shape's interior is defined by edges plus fill styles on each side
(`fill_style_0` left, `fill_style_1` right of edge direction). Whether
any region is "inside" the shape is determined by the **active fill
rule** applied to the per-region net fill assignment:

- Default (DefineShape, DefineShape2, DefineShape3, most DefineShape4)
  uses the **even-odd** rule: a region is filled iff the closed-path
  loop count enclosing it is odd. Equivalently, count the times an
  outward ray from the region crosses any edge — odd → inside.
- DefineShape4 with the `UsesFillWindingRule` flag set uses the
  **non-zero** rule: sum signed crossings (CCW = +1, CW = −1); region
  is filled iff the sum is non-zero.

DefineFont, DefineFont2, DefineFont3 glyphs follow the same model
(they're just a list of shape records, no fill style choice — the
implicit fill style index is 1). Glyphs with holes ('O', 'B', '8') have
two contours; the outer is wound one way and the inner the other,
and the even-odd rule resolves the ring region as filled and the
center region as not filled.

### Ruffle's classification

Ruffle's tessellator (in `tessellator.rs::ShapeBuilder`) doesn't
classify each path as outer/hole at construction time. It feeds the
**raw path list with their fill_style_0/_1 assignments** to a
shape-builder pass that resolves per-region fill via a sweep-line
algorithm respecting the active fill rule. Holes don't need to be
explicitly identified: regions just have a net fill style after the
sweep.

We can't replicate that exact pipeline cheaply (it's a substantial
rewrite). What we *can* do is replicate its **semantic decision**
inside our earcut-based pipeline by promoting the spatial containment
pass we already have into the sole arbiter of outer-vs-hole, and by
honoring nesting parity instead of the per-path signed_area heuristic.

---

## Current state — SWFRecomp pipeline

Working from `SWFRecomp/src/swf.cpp::interpretShape`. Big-picture flow
(~1100 lines, line numbers from current master):

```
parse fill_styles, line_styles           (6995–6920)
parse edge records → paths[]              (6927–7534)
  ↓
constructEdges(paths, nodes)              (7545; 8058)
  ↓
for each self-closed path:                (7547–7589)
    push shape with verts copy
    processShape(shape, path.fill_styles) (calls 8000)
        signed_area, fill_right, inner_fill
    if fill on one side only:
        if is_font:    flip fill_right     ← BUG 1 (font holes)
        else:          shape.hole = true   ← BUG 2 (C-shape drop)
  ↓
johnson(nodes, …) → closed_paths          (7592–7597; 8247)
for each Johnson cycle:                   (7599–7629)
    push shape with verts copy
    processShape(shape, cycle[0].fill_styles)
  ↓
verify cycle fill consistency             (7631–7655)
mark shape.invalid for verts < 3          (7657–7663)
sort shapes by bbox area                  (7665–7696)
  ↓
for each shape marked hole:               (7698–7748)
    find largest containing shape
        bbox containment (7715)
        point-in-shape via isInShape (7724–7741)
    attach hole to its container          (7745–7746)
  ↓
for each shape !invalid, closed,           (7753–7821)
        inner_fill != 0, !hole:
    fillShape(shape, tris)                (calls 8267)
    emit fill triangles to shape_data
  ↓
for each path with line_style:            (7823–7854)
    drawLines(path, width)
    emit stroke triangles to shape_data
```

`processShape` (`swf.cpp:8000`) computes:

```cpp
shape.fill_right = (signed_area < 0);
shape.inner_fill = fill_styles[signed_area < 0];
```

so `inner_fill` is whichever of `fill_styles[0]` / `fill_styles[1]`
sits on the geometric "inside" implied by the winding direction
(`signed_area`). This works for paths where both sides are set
honestly, but for one-sided-fill paths it picks the wrong side roughly
half the time. The 7572–7588 fork is a hand-wavy correction:

```cpp
if (fill_styles[fill_right] == 0 && fill_styles[!fill_right] != 0)
{
    if (is_font) {
        fill_right = !fill_right;
        inner_fill = fill_styles[fill_right];   // ← font workaround
    } else {
        hole = true;                            // ← non-font workaround
        outer_fill = fill_styles[!fill_right];
    }
}
```

### Why both branches are wrong

- **Font branch.** "Flip so the path is filled" is correct *only when
  the path is the outer boundary of a region that has no enclosing
  parent.* For an `o` glyph the outer ring satisfies that, but the
  inner ring is enclosed by the outer ring and should resolve as a
  hole under even-odd. The branch doesn't look at containment, so it
  paints the inner ring solid too.

- **Non-font branch.** "Mark as hole" is correct *only when the path
  has a containing outer shape with the same fill_style.* For a
  standalone C-shape there's no container, the containment pass at
  7700–7748 leaves it un-attached, and the fill pass at 7755 skips it
  because `hole == true`. So a perfectly valid filled C-shape becomes
  invisible.

### What's already correct (don't regret)

- `isInShape` (line 7939) is a proper winding-number point-in-polygon
  test. We can rely on it.
- The containment pass already does the right *geometric* work: sort
  by bbox area descending, then bbox containment + per-vertex
  point-in-shape. It just only runs for shapes already flagged
  `hole == true`, and the "winning" candidate is the *smallest*
  containing shape (innermost parent) — which is exactly what
  even-odd nesting depth needs.
- `ng_record_char_winding` already records when a shape uses the
  non-zero fill rule (DefineShape4 + UsesFillWindingRule). The runtime
  consults it in `shape_hit_test.c::ng_uses_nonzero_winding` for
  hit-test purposes. The recompiler-side fill triangulation should
  use the same per-character flag.

### What's missing

- The classification decision happens too early.
- The containment pass operates only on hole-marked shapes; it has no
  pathway to demote an `inner_fill != 0` shape to a hole when it
  turns out to be nested inside a same-fill parent.
- Nothing computes nesting depth.
- The font fork bypasses containment entirely.

---

## Gap analysis

The recompiler conflates two different decisions:

1. **Which fill style does this path/region carry?**
   ("Use `fill_styles[0]` or `fill_styles[1]`?")
2. **Is this region rendered as a positive fill, or subtracted as a
   hole from its parent?**

Today, both decisions are coupled into the `processShape` +
7572–7588 block. The fix is to decouple:

- Decision 1 stays per-path / per-shape, derived from
  `fill_styles[0]` / `fill_styles[1]` and the winding direction
  (`signed_area`). The per-path inspection is unchanged; we keep
  picking the non-zero side as `inner_fill`.
- Decision 2 becomes a *global* spatial pass over the assembled
  shapes, using `isInShape` for containment and the active fill rule
  for parity.

After Phase B, no path-by-path "hole vs fill" determination remains.
Every shape enters the containment pass as a candidate filled region;
the pass demotes nested ones to holes attached to their immediate
parent.

---

## Phase A — Defer outer/hole decision to the containment pass

**Goal:** Stop marking any shape `hole = true` at construction time.
Always set `inner_fill = the non-zero fill side`. Let the existing
containment pass do the demotion. Removes the `is_font` branch.

**Scope:** `SWFRecomp/src/swf.cpp::interpretShape`, lines 7572–7588.
Plus the small follow-up: the hole-attachment pass at 7698–7748 must
now classify a shape as a hole whenever it finds itself spatially
contained by a same-fill parent. (For Phase A, "same-fill" means the
parent's `inner_fill` equals our `inner_fill` — i.e. the inner region
is the same color as the outer, which is the canonical "hole" pattern
both for `o` glyphs and for donut shapes.)

### Detailed changes

1. **Replace lines 7572–7588** in the self-closed-path branch with:

   ```cpp
   // Always set inner_fill from the non-zero side. Whether this
   // shape is rendered as a positive fill or as a hole of a parent
   // is decided by the containment pass below.
   if (paths[i].fill_styles[shapes.back().fill_right] == 0
       && paths[i].fill_styles[!shapes.back().fill_right] != 0)
   {
       shapes.back().fill_right = !shapes.back().fill_right;
       shapes.back().inner_fill =
           paths[i].fill_styles[shapes.back().fill_right];
   }
   // shapes.back().hole stays false; the containment pass may flip it.
   ```

2. **Extend the containment pass** (lines 7698–7748) to scan **all**
   shapes, not just `hole == true`. For each shape, look for its
   smallest spatial parent (same algorithm we already use — bbox
   containment + `isInShape` on representative vertex). If a parent
   exists with the same `inner_fill`, demote this shape: set
   `hole = true`, attach to parent's `holes`, copy parent's
   `outer_fill`.

   Concretely, this means renaming the current `if (shapes[i].hole)`
   gate to "always run", and adding a same-fill check inside the
   loop body. Pseudocode:

   ```cpp
   for (size_t i = 0; i < shapes.size(); ++i) {
       if (shapes[i].invalid) continue;
       Shape& candidate = shapes[i];

       // Find smallest containing shape, same algorithm as today.
       Shape* parent = find_smallest_container(candidate, shapes);
       if (parent == nullptr) continue;            // outermost, render as fill
       if (parent->inner_fill != candidate.inner_fill) continue;
       // (Different-color region inside an outer — render as its own fill.)

       candidate.hole = true;
       candidate.outer_fill = parent->inner_fill;
       parent->holes.push_back(&candidate);
   }
   ```

3. **Update the fill-emit gate** at line 7755. Today it's
   `!shapes[i].invalid && shapes[i].closed && shapes[i].inner_fill != 0 && !shapes[i].hole`,
   which stays unchanged — the new containment pass now sets `hole`
   for nested same-fill regions, so they correctly skip the positive
   fill loop and feed into their parent via `fillShape`'s
   `polygon` + `holes` input.

### Expected impact

- **C-shape regression** (`shape_test` sprites): the C-shape has no
  spatial parent, so Phase A keeps it as `hole = false` and emits
  its fill triangles. Fixed.
- **Font glyphs without holes** (`m`, `n`, `i`, `l`, …): each has a
  single self-closed path with no spatial parent → `hole` stays
  false → fills emit as today. Unchanged.
- **Font glyphs with holes** (`o`, `e`, `a`, …): the outer ring has
  no parent (renders filled); the inner ring is contained by the
  outer with the same fill_style → demoted to hole, attached to the
  outer, and `fillShape` will subtract it via earcut's
  polygon+holes input. Fixed.
- **Standalone holes (no enclosing shape)**: today they were
  silently dropped (marked `hole` but never attached). After Phase A
  they still never attach (no parent found), but `hole` is now
  false from the start, so they'd render as positive fills. This is
  the one behavioral change to watch for. In practice this case is
  exotic: SWF authors don't draw an isolated hole. If it does
  appear, the result (rendering as a filled region) is at worst a
  bounded visual artifact, not a regression in test correctness.

### Verification (per-test)

- `from_gnash/misc-ming.all/shape_test` — C-shapes inside sprites
  should now show green/red fills. Image outliers should drop
  substantially.
- `from_gnash/misc-ming.all/place_object_test` — trace TextField
  letters should now show counters. Image outliers in the trace text
  region should drop.
- Per-test rebuild + visual diff vs `output.ruffle.png` for each of
  the 5 tests with `output.ruffle.png` present.

### Regression-check battery (no full-suite run)

A representative set covering each shape kind we currently handle:

- Simple-shape sanity: `avm1/mask_with_drawing`, `avm1/color`,
  `avm1/bitmap_data_fillrect` (rectangles, no holes — must not regress).
- Stroked shapes: `avm1/movieclip_line_gradient_style` (lines only,
  no fills — must not regress).
- Drawing API: `avm1/movieclip_begin_gradient_fill` (radial fills).
- Multi-fill: `avm1/movieclip_setmask`.
- Morph: `from_gnash/misc-ming.all/morph_test1`.
- Embedded font: any `avm1/edittext_*` (e.g. `edittext_tag_indent`).

---

## Phase B — Nesting-depth fill rule (even-odd & non-zero)

Phase A handles same-fill nesting (the canonical "hole" pattern). It
doesn't yet handle:

- **Multi-level nesting** (a hole-in-a-hole pattern — rare but legal
  in SWF). Under even-odd, depth 0 fills, depth 1 holes, depth 2
  fills, depth 3 holes, …
- **Different-color nesting** (an inner shape with a different
  `inner_fill` than the outer). Today Phase A would render both
  positively, which is correct: the inner is *not* a hole, it's a
  smaller filled region painted on top. The render order
  (fill_style_list scan) handles z-order.

The general fill rule is *nesting parity*. Implement explicitly:

1. Compute each shape's nesting depth: count how many strictly-larger
   shapes contain it (using the same bbox + `isInShape` mechanism).
2. Use the per-character `winding_nonzero` flag (already plumbed by
   `ng_record_char_winding`) to choose the rule:
   - Even-odd (default): hole iff depth is odd.
   - Non-zero: hole iff cumulative signed winding around the region is
     zero. Implementation note: this requires per-path winding
     direction, which we already have via `signed_area` in
     `processShape`. Aggregate signed crossings over the chain of
     containing parents.
3. When demoting to hole, attach to the **immediate parent** (depth-1
   ancestor), not to the largest container.

For tests with depth ≤ 1 (i.e. the vast majority — glyphs and
simple-donut shapes), Phase B reduces to Phase A. For deeper nesting,
Phase B is necessary.

### Scope

- Add `u32 nesting_depth` to `Shape`.
- After the existing area sort (line 7696), compute depths in one
  pass: each shape's depth = `parent's depth + 1`, with parent =
  smallest container.
- In the demote loop, compute "is hole" from depth + winding rule.

### Verification

- `from_gnash/misc-ming.all/place_object_test` and similar dejagnu
  tests should now render `8`, `B`, `R`, and other deep-nested
  glyphs (where they appear in the trace text) correctly.
- Find or construct a test with nested fills explicitly (a 2-ring
  glyph or a custom DefineShape).

---

## Phase C — Optional: drop the `processShape` `fill_right` heuristic

After Phases A+B, the only role of `processShape`'s `signed_area →
fill_right` mapping is to pick which of `fill_styles[0]` /
`fill_styles[1]` to take as `inner_fill` for the path. That's
geometrically meaningful (winding direction implies inside-vs-outside
when both sides carry fill), but it's also redundant with the
containment pass for one-sided-fill paths.

Audit whether `signed_area` is still load-bearing once nesting depth
drives hole detection:

- Self-closed two-sided fills (both `fill_styles[0]` and `[1]`
  non-zero): paths separating two different filled regions. Today
  we render only one side; the other side would be its own `Shape`
  built from a separate path that closes around the other region.
  Containment is enough to determine which renders on top. Keeping
  the heuristic here is harmless.
- Self-closed one-sided fills: the heuristic chooses fill side
  based on winding; spatial containment is now authoritative. Keep
  the heuristic only as a fill-style-picker; remove the "mark as
  hole" coupling.

No behavior change expected. Pure cleanup.

---

## Test strategy

For each phase:

1. **Per-test verification.** Pick a small (≤ 8) set of representative
   tests known to exercise the code path. Rebuild fresh
   (`rm -rf RecompiledScripts RecompiledTags`), run with
   `--mode=graphics --verbose`. Visual diff against
   `output.expected.png` AND `output.ruffle.png` using
   `run_image_tests.py` (which now writes `*.ruffle.difference.png`).

2. **Filtered regression battery.** Run the existing image-test
   battery via `python3 ruffle-tests/run_image_tests.py` (graphics
   mode, 30s timeout per test). Compare `image_results.json` strict /
   tolerance / fail counts before and after.

3. **Trace regression battery.** Run a 20-test trace-only battery
   covering AVM1 lifecycle, scope, super, dejagnu trace, and
   drawing-API tests. These don't exercise the recompiler shape
   pipeline directly but verify nothing downstream regressed.

4. **CI sweep.** `gh workflow run ruffle-tests.yml -f mode=graphics`
   for full graphics-mode CI before declaring the phase done.

Per project convention: **never** run the full suite locally; rely on
the per-test loop and CI for full coverage. Single-test commands look
like:

```bash
rm -rf ruffle-tests/tests/swfs/from_gnash/misc-ming.all/shape_test/Recompiled{Scripts,Tags}
python3 ruffle-tests/verify_output.py \
    --tests-dir ruffle-tests/tests/swfs/from_gnash/misc-ming.all \
    --test=shape_test --mode=graphics --verbose
```

---

## Risk register

| # | Risk | Mitigation |
|---|------|------------|
| 1 | A standalone "hole" (no enclosing shape) that today renders as nothing flips to rendering as a filled region. | Visual inspection during Phase A verification. Likely rare; if it surfaces, add a per-test exception via the recompiler's `is_font` heuristic OR (better) a SWF-level signal. |
| 2 | Glyphs with multiple outer paths (e.g. `i` = dot + stem) treat the smaller path as a hole inside the larger. | Containment check requires *spatial* containment via `isInShape`, not just bbox containment. The dot and stem don't enclose each other, so this can't happen. Bbox-only would have been a problem; the existing per-vertex `isInShape` already guards against it. |
| 3 | Same-fill check at Phase A demotes a different-color nested fill to a hole, wiping it. | The `parent->inner_fill != candidate.inner_fill` continue (skip) handles this. Different-color regions stay as positive fills. |
| 4 | Morph shapes (`DefineMorphShape`) take a different path through `interpretShape` and might be miscompiled. | Morph shapes call `processShape` too. Phase A's logic is `inner_fill`-side oriented, identical for morph. Verify with `morph_test1` regression check. |
| 5 | Non-zero winding shapes (DefineShape4 + `UsesFillWindingRule`) need different logic from even-odd. | Phase A treats all shapes identically (same-fill containment). Phase B introduces the per-character winding flag and switches rule. Defer until Phase B. |
| 6 | The containment pass is `O(n²)` (every shape against every other), already; extending it to scan all shapes (not just holes) doesn't change asymptotic cost but raises the constant. For glyph-heavy SWFs (hundreds of glyphs per font, each with 1–3 contours), this could be a noticeable recompile-time slowdown. | Profile after Phase A. If material, add a bbox spatial index (R-tree from `<boost/geometry>` or hand-rolled grid bucket) for the bbox-prefilter; the per-vertex `isInShape` test stays the same. |
| 7 | `is_font` branch removal alters every glyph that today flips. Some glyphs may have relied on the flip producing the *correct* winding for `fillShape`'s `earcut` input (CCW outer vs CW hole). | After Phase A, glyphs without holes don't go through the flip at all (no spatial parent, no demotion). Glyphs with holes get explicit outer + hole(s) attachment, so `fillShape` builds the polygon array with the outer first and holes after, which is `earcut`'s expected layout regardless of source winding. |
| 8 | The recompiler runs at build time, so a buggy Phase A breaks every test until reverted. | Phase changes land behind a gate (e.g. env `SWFRECOMP_NEW_HOLE_DETECTION=1`) during development, then flip the default and remove the gate once CI is green. |

---

## Open questions

1. **Do we have an explicit non-zero-winding test in the suite today?**
   `ng_record_char_winding` is wired through the runtime for hit
   testing, but it's not obvious which test exercises it. Finding a
   driver is a precondition for confidently shipping Phase B.

2. **What does Ruffle do for a standalone hole (no enclosing shape)?**
   Worth a `grep` through `ruffle/render/src/tessellator.rs` and
   `ruffle/render/src/path.rs` to confirm the answer before deciding
   between "render as fill" and "drop silently" for the Phase A
   ambiguous case (Risk 1).

3. **Should Phase A retain a fallback for the `is_font` branch?** I
   propose removing it outright, since the new same-fill containment
   handles glyph holes correctly. But if specific tests rely on the
   flip behavior in a way the new pipeline doesn't replicate, we'd
   want a way to opt back in per-tag. (Likely unnecessary; flagged
   for vigilance during phase-A verification.)

4. **`fillShape`'s `earcut` invocation passes outer + holes as the
   same vertex array.** Today the holes are passed as additional
   contours after the outer. earcut accepts CW or CCW input
   transparently *within* a single contour, but it does require the
   outer to be the first contour. The current `processShape` doesn't
   guarantee winding orientation between outer and holes — does
   earcut handle the case where outer and hole have the same
   winding direction? Quick experiment: yes, earcut's earcut.hpp
   determines winding from the input polygon ordering, not the
   geometric direction, so passing `[outer, hole1, hole2]` works
   regardless of vertex order within each. Confirmed by inspection
   of the bundled `earcut.hpp`.

---

## Sequencing & estimated effort

| Phase | LOC | Recompiler-only? | Risk | Ship target |
|-------|-----|------------------|------|-------------|
| A     | ~60 | yes              | low  | first       |
| B     | ~80 | yes              | med  | follow-up   |
| C     | ~30 | yes              | trivial | optional |

Phase A is the high-value, low-risk landing — restores font glyph
counters and revives the C-shape fills. Phase B is needed for full
parity but is incremental on top of A. Phase C is cleanup.
