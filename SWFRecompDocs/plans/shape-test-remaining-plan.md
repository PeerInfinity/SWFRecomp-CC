# `from_gnash/misc-ming.all/shape_test` Remaining Issues — Plan

**Document Version:** 1.0

**Created:** 2026-05-14

**Status:** Partially OBSOLETE — the tessellation issues (Phases 1–2) are now
solved by the libtess2 migration. See the status banner below.

> **STATUS UPDATE 2026-06-02 — read before using Phases 1–2.**
>
> **Phase 2 ("Split self-touching closed polygons before earcut") is
> SUPERSEDED.** Plain-shape fills no longer use earcut — they route through
> libtess2 with the SWF even-odd rule (`80c87edc0`, extended `a0e5d431d`), which
> cuts self-touching / partially-overlapping sub-loops natively, so the manual
> pre-split this phase proposes is no longer needed. **shape_test's C-shape
> notches now render as white holes matching Ruffle** (confirmed in
> `PROGRESS.md` #6). Phase 1 ("auto-close one-sided fill") similarly no longer
> needs the earcut-specific handling.
>
> The **remaining** shape_test diff is the depth-4 Place-conflict for the 2nd
> green clip (Phase 3 territory) plus the gnash-vs-Ruffle oracle disagreement —
> NOT tessellation. (Phase 3 "Refuse PlaceObject Place on occupied depth" is
> also affected by the later `b8ced0c60` PlaceObject occupied-depth *replace*
> change — re-validate this phase's premise against current behavior before
> acting on it.)
>
> Canonical current state: `tools/divergence/PROGRESS.md` follow-up **#6** and
> the `tessellation-libtess2-migration` auto-memory.

Follow-up to `shape-hole-detection-plan.md` (Phases A–C, landed
`992c37d6`/`54053b79`/`e2dc404e`). The hole-detection plan named
`shape_test` as its driver, but only addressed *one* of the test's
several rendering bugs. This plan covers the four remaining defects
visible in `output.actual.png` vs `output.ruffle.png`.

## Table of contents

1. [Test layout reminder](#test-layout-reminder)
2. [What Phase A/B/C fixed](#what-phase-abc-fixed)
3. [Issue inventory](#issue-inventory)
4. [Phase 1 — Auto-close paths with one-sided fill](#phase-1--auto-close-paths-with-one-sided-fill)
5. [Phase 2 — Split self-touching closed polygons before earcut](#phase-2--split-self-touching-closed-polygons-before-earcut)
6. [Phase 3 — Refuse PlaceObject Place on occupied depth](#phase-3--refuse-placeobject-place-on-occupied-depth)
7. [Phase 4 — Fix `this.passed++` on prototype methods](#phase-4--fix-thispassed-on-prototype-methods)
8. [Sequencing & risk](#sequencing--risk)

---

## Test layout reminder

Source: `~/CC/gnash/testsuite/misc-ming.all/shape_test.c`.

Frame 1 placements:
- `dejagnuclip` at depth 1 (xtrace TextField bound to `_root._trace_text`).
- `sh1` (red square) at depth 3.
- `sh2` (black square) at depth 4.
- 18 `check_equals` calls on shapes-as-MovieClips semantics.
- `add_actions(mo, "_root.totals(); stop();")` at end.

Frame 2 placements (4 movieclip sprites, each containing one C-shape):

| Sprite | Shape | Position | Fill style | Path closed? |
|---|---|---|---|---|
| 7  | 6  | (80, 120)  | `setLeftFillStyle` GREEN  | no  |
| 9  | 8  | (200, 120) | `setLeftFillStyle` GREEN  | no  |
| 11 | 10 | (80, 200)  | `setLeftFillStyle` RED    | yes |
| 13 | 12 | (200, 200) | `setRightFillStyle` RED   | yes |

Each sprite is placed via `SWFMovie_add` (Ming auto-assigns depths
starting from where the explicit `setDepth` left off — 4, 5, 6, 7).
Confirmed via `swfmill swf2xml`: PlaceObject2 tags at depths 4 (sh2 +
sprite 7), 5, 6, 7, all with `replace="0"`.

## What Phase A/B/C fixed

- Shape 10 / shape 12 (closed C-shapes) now emit fill triangles (12
  fill verts each, vs 0 before). Visible: middle-row C-shapes are
  now colored red instead of outline-only.
- shape_test outlier count: 38268 → 35849.
- No regressions across the regression battery.

Phase A/B/C did **not** touch:
- non-closed paths (shapes 6, 8),
- triangulation of self-touching closed polygons (shapes 10, 12 emit
  fills but the geometry is wrong),
- display-list / depth conflict handling (sh2 vs sprite 7),
- the AS-runtime bug behind the stale on-screen counter.

## Issue inventory

| # | Symptom | Root cause | Layer |
|---|---|---|---|
| 1 | shapes 6, 8 render as outline only (sprites 7, 9 should be filled green) | `interpretShape` only emits `Shape`s for self-closed paths or Johnson cycles; a single non-closed path with one-sided fill produces no `Shape` | recompiler |
| 2 | shapes 10, 12 fill as "rectangle with triangular notch" (sprites 11, 13 should be C-shaped) | path is a 10-vertex polygon that self-touches at (20,10); earcut triangulates the merged polygon, not the SWF-fill region | recompiler |
| 3 | `sh2` (black square) missing | recompiler-emitted `tagPlaceObject2` at occupied depth 4 silently replaces sh2 with sprite 7; Ruffle's `instantiate_child` refuses placement on an occupied depth | runtime |
| 4 | on-screen counter stuck at `#passed: 1` (trace stdout is correctly 18) | `this.passed++` inside a prototype method (`TestState.prototype.pass`) only persists the first increment | runtime |

Independent failures — each phase is shippable on its own. After all
four phases land, `shape_test` should match Ruffle pixel-by-pixel
(modulo the existing `tolerance = 50` in test.toml).

---

## Phase 1 — Auto-close paths with one-sided fill

### Symptom and root cause

`shape_test.c:127–141` builds `sh` (shape 6) via:

```c
SWFShape_setLineStyle(sh, 1, 0, 0, 0, 255);
SWFShape_setLeftFillStyle(sh, GREEN);
SWFShape_movePenTo(sh, 20, 10);
SWFShape_drawLineTo(sh, 40, 10); /* 1 */
...
SWFShape_drawLineTo(sh, 20, 30); /* 9 */
// NO drawLineTo back to (20, 10) — path is OPEN.
```

Recompiled `draws.c` for shape 6: 204 stroke verts at color 0x66
(black), **zero fill verts**. Shape 8 is identical.

In `SWFRecomp/src/swf.cpp::interpretShape` (≈ line 7547):

```cpp
for (size_t i = 0; i < paths.size(); ++i) {
    if (paths[i].self_closed) {
        // build Shape, run processShape + Phase A flip + emit fill verts
    }
}
// then Johnson cycle resolver (which requires multi-path cycles)
```

A path with `self_closed == false` enters neither branch when it doesn't
form a cycle with other paths. Its strokes still emit (stroke pass at
line 7853 iterates `paths`, not `shapes`), but no `Shape` ⇒ no fill.

### Reference behavior

Ruffle's `swf` crate parses the same SWF data and runs path
tessellation in `core/render/src/tessellator.rs`. For a path with a
non-zero `fill_style_0` / `_1` that hasn't returned to its origin,
Ruffle implicitly closes the contour for fill purposes (the stroke
remains open). The SWF spec §3.6 is ambiguous about this — Flash
Player's behavior is the de-facto standard, and Flash auto-closes too.

### Approach

Two viable angles:

**Option A — Synthetic closure at `interpretShape` path-loop time.**
Just before the self-closed check, if a path has `!self_closed` AND
either `fill_styles[0] != 0` OR `fill_styles[1] != 0`, append a
synthetic vertex equal to `verts[0]` (closing the loop) and set
`self_closed = true`. The path then enters the existing self-closed
branch and Phase A/B handle the rest.

```cpp
for (size_t i = 0; i < paths.size(); ++i) {
    if (!paths[i].self_closed &&
        (paths[i].fill_styles[0] != 0 || paths[i].fill_styles[1] != 0) &&
        paths[i].verts.size() >= 2 &&
        !(paths[i].verts.back().x == paths[i].verts[0].x &&
          paths[i].verts.back().y == paths[i].verts[0].y))
    {
        paths[i].verts.push_back(paths[i].verts[0]);
        paths[i].self_closed = true;
    }
    // existing self-closed branch follows
}
```

This is the minimum-invasive change. Strokes still emit from `paths`
unchanged, so the stroke pass at 7853 keeps the original open polyline
(it skips the duplicate closing edge since the last edge is from `[N-1]`
to `[N]` where `[N] == [0]`, indistinguishable from a real closure
edge in stroke terms).

Wait — actually stroke pass DOES emit the synthetic edge. We'd need to
either (a) skip the closing edge in the stroke pass, or (b) clone the
path's verts into the new `Shape` only and leave `paths[i].verts`
untouched. Option (b) is cleaner.

**Option B — Construct `Shape` directly from the open path.**
Build a `Shape` from the open path's verts WITHOUT modifying the
path. earcut handles open polygons by treating the input vertex list
as a closed loop (it doesn't require an explicit duplicate
last-vertex). The stroke pass remains untouched.

```cpp
if (paths[i].self_closed ||
    (paths[i].fill_styles[0] != 0 || paths[i].fill_styles[1] != 0))
{
    shapes.push_back(Shape());
    // ...copy verts as today...
    if (!paths[i].self_closed) {
        // mark as synthetically closed for downstream — Phase A flip
        // still applies, processShape's signed_area still works on
        // the open vertex list (CROSS is computed on consecutive
        // pairs incl. the wrap-around at end of polygon).
    }
}
```

This avoids touching `paths[i].verts` and keeps strokes unchanged.

**Recommended: Option B.** Reasons:
- No risk of breaking the stroke pass.
- `processShape`'s `signed_area` already wraps via `point.x = shape.verts[0].x; signed_area += CROSS(last_point, point)` at line 8074–8076 — it treats the polygon as closed regardless of whether the last vertex equals the first.
- earcut's input format is "list of contours each as a vertex sequence", with implicit closure between last and first vertex of each contour.

### Verification

- Re-render `shape_test`. Sprites 7 (top-left), 9 (top-right) should
  show as green C-shapes.
- Regression battery from Phase A's plan: must not regress.
- New driver: a minimal test SWF with one open `drawLineTo` path plus
  a `setLeftFillStyle` — synthesize via Ming or write by hand. The
  fill should appear after this phase.

### Risks

- **R1.1 — False fills.** An open path with a non-zero fill might be
  *intentionally* open (some SWF authoring tools emit "stroke-only
  paths" with stale fill style state). Auto-closing fills them in
  spuriously. Mitigation: gate on `fill_styles[0]` OR `[1]` non-zero
  AND `verts.size() >= 3` (a single line segment with fill is
  definitely degenerate, skip it).
- **R1.2 — Self-touching after closure.** If an open path that ends
  near (but not at) the start has its closure edge cross another part
  of the path, we create a self-intersecting polygon. Phase 2 (below)
  handles self-touching. For truly self-*intersecting* polygons,
  earcut's behavior is undefined — out of scope here.

---

## Phase 2 — Split self-touching closed polygons before earcut

### Symptom and root cause

`shape_test.c:196–213` builds shape 10 via 10 `drawLineTo` calls that
visit (20,10) **three times**: vertices 0, 4, and 10. Edges:

```
0  (20,10)
1  (40,10)
2  (40,40)
3  (20,40)
4  (20,10)   ← same as vertex 0
5  (10,10)
6  (10,20)
7  (30,20)
8  (30,30)
9  (20,30)
10 (20,10)   ← same as vertex 0 & 4 (closes the path)
```

After Phase A, this path enters `interpretShape` as a self-closed
path, produces a `Shape` with 10 vertices (after dedup) — the path
self-touches at (20,10) between vertices 3→4 and 9→10.

The 10-vertex polygon, fed to earcut as a single contour, is
*topologically* a figure-8 / pinched polygon. earcut's output is
deterministic but not what SWF's even-odd fill rule prescribes.
Visually we get "rectangle with a triangular notch" — earcut picks one
diagonal across the pinch and triangulates the rest naively.

### Reference behavior

Ruffle's tessellator splits self-touching paths at the touch point.
The two sub-loops are tessellated independently and their fills
composited via the active fill rule. See
`ruffle/render/src/tessellator.rs::ShapeBuilder::add_path` and
`shape_utils.rs::DistilledShape`.

For shape 10's vertex sequence, splitting at (20,10) produces:

```
Sub-path A: (20,10) (40,10) (40,40) (20,40) (20,10)  — 5 verts, rectangle on right
Sub-path B: (20,10) (10,10) (10,20) (30,20) (30,30) (20,30) (20,10)  — 7 verts, "P"-shape on left+inside
```

Both share the touch vertex (20,10). Under left-fill / even-odd, the
union of the two sub-paths' interiors is the C-shape that Ruffle
renders.

### Approach

Split at self-touch in `interpretShape` after building the `Shape`'s
vertex list but before adding it to `shapes`:

```cpp
// After the for-loop that copies paths[i].verts into shapes.back().verts:
std::vector<Shape>& shape = shapes.back();
for (size_t k = 1; k < shape.verts.size() - 1; ++k) {
    for (size_t m = k + 1; m < shape.verts.size(); ++m) {
        if (shape.verts[k] == shape.verts[m]) {
            // Split: extract verts[k..m] as a sub-path, leave verts[0..k] + verts[m..end] as the outer.
            // Push the extracted sub-path as a new Shape.
            // Restart the search from the modified outer.
            ...
        }
    }
}
```

This is O(N²) per shape, but N is small (typical glyph paths have <
50 verts). The split path becomes a separate `Shape` that goes through
the same Phase A/B/C containment logic — same `inner_fill`,
spatial-containment-determines-hole-vs-fill. After Phase 2, the
containment pass naturally handles nested sub-loops.

**Variant — only split when the closed path has at least one repeated
interior vertex.** Skip the split entirely for non-self-touching
shapes (the vast majority) to keep recompile time predictable.

### Verification

- `shape_test`: middle-row C-shapes should render as proper Cs (not
  notched rectangles).
- Glyph regression: glyphs with self-touching paths exist (`A`'s
  crossbar touches both legs at the intersection). Spot-check
  `edittext_*` tests to confirm no regression.
- Outlier-count check on `shape_test`, `place_object_test`, and any
  test with non-rectangular fills.

### Risks

- **R2.1 — Detection precision.** Vertex equality currently dedups
  consecutive duplicates (`verts.back() == paths[i].verts[k]` skip at
  line 7558). After dedup, only *non-consecutive* repeats remain —
  which is exactly the self-touch case. Good.
- **R2.2 — Multi-touch paths.** A path may self-touch at multiple
  points. The split loop needs to handle this iteratively (each split
  produces sub-paths that may themselves self-touch). Bounded by
  `verts.size()` iterations max.
- **R2.3 — Earcut hole assignment.** After splitting, each sub-path
  becomes its own `Shape`. The Phase B containment pass decides which
  is a fill and which is a hole. For shape 10's two sub-paths neither
  contains the other (they share only the touch point), so both
  render as same-fill positive fills — the union covers the C-shape.
  ✓ Matches expected.

---

## Phase 3 — Refuse PlaceObject Place on occupied depth

### Symptom and root cause

`swfmill swf2xml` confirms both placements have `replace="0"` (the
"Place" variant, not "Move"/"Modify"):

```xml
<PlaceObject2 replace="0" depth="4" objectID="5" name="sh2"/>   <!-- frame 1 -->
<PlaceObject2 replace="0" depth="4" objectID="7"/>              <!-- frame 2 -->
```

Our runtime (`SWFModernRuntime/src/libswf/tag.c::tagPlaceObject2` /
`SWFModernRuntime/src/libswf/tag_stubs.c` for the OFFSCREEN_RENDER
build path) treats a Place at an occupied depth as a *replace* — the
existing display object at that depth is overwritten by the new one.

Ruffle's `core/src/display_object/movie_clip.rs::instantiate_child`
(line 1410) does the opposite:

```rust
fn instantiate_child(self, ...) -> Option<DisplayObject<'gc>> {
    if self.has_child_at_depth(depth) {
        context.avm_warning(&format!("Failed to place object at depth {depth}."));
        return None;
    }
    ...
}
```

`PlaceObjectAction::Place` is **rejected** if the depth is already
occupied. Only `Replace` or `Modify` actually modify an existing
child.

### Approach

In our `tagPlaceObject2` (graphics-native and graphics-WASM both —
this is depth-keyed display list logic, suite-wide):

1. Before instantiating the new display-list entry, check if
   `app_context->display_list[depth]` already has a live entry
   (`char_id != 0`).
2. If occupied AND the `PlaceObject2` has neither the Move flag nor a
   replace-id (`replace="0"` with no Move): log a warning and return
   without modifying the display list.
3. Otherwise proceed as today.

This is a one-site change but it touches a high-traffic code path —
every PlaceObject2 in every SWF flows through this. Need careful
verification.

### Verification

- `shape_test`: bottom-right black square should appear; top row
  should drop from 2 outlined shapes to 1 green C (sprite 7 fails to
  place, sprite 9 remains).
- Combined with Phase 1, the top green C should render filled.
- Full regression battery — this changes display-list semantics so any
  test using PlaceObject2 in a way that relied on implicit replace
  will be affected. Identify by running ~~the full suite~~ a broad
  per-test sweep including:
  - `avm1/clip_events`, `avm1/issue_1104` (clip event tests, multi-place)
  - `from_gnash/misc-ming.all/place_object_test` (PlaceObject2 driver)
  - `from_gnash/misc-ming.all/replace_sprites1test`
  - Any test in `_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` that
    mentions placement.

### Risks

- **R3.1 — Existing tests rely on replace-by-Place.** Some
  recompiler-emitted code or some SWF in the corpus may depend on the
  current "Place silently replaces" semantics. Mitigation: per-test
  diff after the change; if regressions appear, audit whether the
  affected SWF actually uses Move/Replace flags but we mis-parse, or
  the test is legitimately affected.
- **R3.2 — Frame-1 vs frame-2 ordering.** sh2 (frame 1) is placed
  first; sprite 7 (frame 2) comes second. The check naturally works:
  by frame 2, depth 4 is occupied, so sprite 7 fails. But if a test
  does Place-then-Remove-then-Place at the same depth across frames,
  the second Place should succeed because RemoveObject2 cleared the
  depth. Verify RemoveObject2 correctly clears `display_list[depth]`
  so the next Place isn't blocked.
- **R3.3 — Recompiler tag emission.** The recompiler's
  `tagPlaceObject2` codegen passes a Place/Modify/Replace
  discriminator argument. Verify we're reading the SWF tag's flag
  bits correctly and emitting the discriminator faithfully. If not,
  Phase 3's runtime check fires on the wrong tags.

---

## Phase 4 — Fix `this.passed++` on prototype methods

### Symptom and root cause

Our stdout trace shows all 18 PASSED lines correctly — every
`TestState.prototype.pass` call ran `trace('PASSED: ...')`. But the
on-screen TextField (bound to `_root._trace_text`) shows
`#passed: 1, #failed: 0, #total tests run: 1`.

`printtotals` runs at the end-of-frame `_root.totals()` call and emits
three `note()` calls. Each `note()` calls `_root.xtrace(msg)` which
appends to `_root._trace_text`. If `printtotals` shows `#passed: 1`,
then **at the moment `printtotals` ran**, `this.passed` was 1, not
18.

`pass()` does:
```javascript
this.passed++;
var msg = 'PASSED: '+why;
// _root.xtrace(msg) commented out  — only trace, no _trace_text
trace(msg);
```

`trace(msg)` writes 18 lines to stdout (correct). `this.passed++`
should mutate `_root.runtest.passed` from 0 → 18 over 18 calls.

Hypothesis: our AS-runtime mishandles `this.<member>++` (or
`this.<member> = this.<member> + 1`) when `this` is bound to a
prototype-instance object. First call works because the property gets
*added* to the instance via the SetMember path; subsequent calls
either:
- (a) re-read a stale value (0) from the prototype chain instead of
  the instance,
- (b) write to a different scope (e.g. local var named `passed`
  shadowing the member),
- (c) the postfix `++` evaluates correctly but `this` rebinds between
  read and write.

### Approach

1. **Repro in isolation.** Write a minimal SWF (via MTASC or
   hand-crafted bytecode) that does:
   ```javascript
   function Foo() {}
   Foo.prototype.bump = function() { this.n++; trace(this.n); };
   var f = new Foo();
   f.n = 0;
   f.bump(); f.bump(); f.bump();
   // Expected trace: 1, 2, 3
   ```
   Run with `verify_output.py --test=...` and capture actual trace.

2. **Bisect the failure mode.** From the minimal repro, determine
   which step is broken:
   - Is `this.n` read correctly each call? (instrument with
     `trace(this.n + " before ++")`)
   - Is the write reaching `f.n`? (check `f.n` after each call)
   - Does the same bug appear without prototype (assign `bump` as a
     direct member)?
   - Does the same bug appear with `this.n = this.n + 1` instead of
     `this.n++`?

3. **Trace into `actionSetMember` / `actionGetMember`.** Once the
   minimal repro is identified, instrument the corresponding handlers
   in `SWFModernRuntime/src/actionmodern/action.c`. The bug is likely
   in either:
   - `actionIncrement` (or whatever opcode handles postfix++ on a
     member) — fails to write back after computing the new value.
   - `actionGetMember` — returns a prototype-chain value when it
     should return the instance's own value (if any).
   - The way `this` is set up for prototype-method invocation —
     if `this` rebinds per-call instead of pointing to the original
     instance.

4. **Fix and verify.** Patch the broken site, re-run the minimal
   repro, then `shape_test`. Run the regression battery (especially
   tests that exercise `new Class(); instance.method()` patterns —
   `register_class_return_value`, `register_and_init_order`,
   `register_class_test2`, `as2_super_*`).

### Verification

- Minimal `Foo().bump()` repro: trace `1, 2, 3`.
- `shape_test`: on-screen counter reads `#passed: 18`.
- Regression battery, focusing on prototype-method tests.

### Risks

- **R4.1 — Misdiagnosis.** The bug might not be `this.passed++`
  specifically. Could be `_root.runtest` resolving differently between
  call sites, could be a scoping issue with `var c = this.passed;`
  inside `testcount`. The minimal-repro step is *the* gate — don't
  ship a fix without a clean repro that the fix specifically targets.
- **R4.2 — Widespread regression.** Touching `actionIncrement` or
  `actionSetMember` affects every AS program. Mitigation: regression
  battery before commit, plus prototype-heavy test focus.

---

## Sequencing & risk

| Phase | LOC | Layer | Risk | Driver test | Order recommendation |
|---|---|---|---|---|---|
| 1 | ~30 | recompiler | low | shape_test top row green | 1st — smallest blast radius, isolated path-construction logic |
| 2 | ~80 | recompiler | medium | shape_test middle row C | 2nd — depends on Phase 1 only for the green Cs (Phase 2 fixes red Cs independently) |
| 3 | ~30 | runtime | medium-high | shape_test sh2 visible | 3rd — broad runtime change, ship after recompiler phases stabilize |
| 4 | ~100? | runtime | high | shape_test counter | 4th — needs minimal-repro investigation before code |

Phases 1 and 2 are recompiler-only and can ship together if Phase 2's
investigation produces a clean implementation. Phases 3 and 4 are
both runtime-side but unrelated — independent commits.

Final state after all four phases: `shape_test` should pass image
comparison within the `tolerance = 50` in test.toml, restoring it to
trace-PASS + image-PASS. The four phases together should also fix
parallel symptoms in other tests:

- **Phase 1**: every test with an open-stroked-fill path (Drawing API
  tests where `lineTo` chains are unclosed).
- **Phase 2**: glyphs like `A`, `H`, `R` that self-touch at edge
  intersections.
- **Phase 3**: tests in `from_gnash` and `from_shumway` that exercise
  PlaceObject2 Place-on-occupied semantics. May surface regressions —
  see R3.1.
- **Phase 4**: every test that uses dejagnu's on-screen xtrace
  display — currently masked since the trace-stdout pass succeeds
  but the on-screen counter is wrong; the image comparison hides this
  as a "text differs" outlier blob.
