# Session 15 — wave 2 — w2-gfx-flatten (pixel board **P2**, curve flattening)

**Agent:** `w2-gfx-flatten` · isolated worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a12c1885e86d10a03`
**Brief:** P2 from `wave1-gfx-board.md` — "our recompile-time quadratic flattening
(`SWFRecomp/src/swf.cpp:8653`) is strictly finer than lyon's, so curved boundaries sit
~0.6 px OUTSIDE Ruffle's". Priced 4–9 flips + ≥12 band moves.

---

## VERDICTS (lead with these)

| leg | what it changes | verdict | flips | band moves |
|---|---|---|---|---|
| **R — runtime lyon/Levien port** (`avm2_display.c`, `action.c`, new `curve_flatten.h`) | drawing-API flattening | **GO — SHIP** | **+3 PROVEN** | 4 |
| **C — recompiler lyon/Levien port** (`swf.cpp`) | DefineShape / font flattening | **CONDITIONAL** (see risk) | 0 | 6 |
| **B — recompiler tolerance 1→2 twips** (`swf.cpp`) | " | superseded by C | 0 | 6 |
| **A — recompiler 6-chord floor removal** (`swf.cpp`) | " | **REFUTED — inert** | 0 | 1 (−1 channel) |

**Proven flips (leg R, reproduced locally at `--mode=graphics`, tolerance 0):**
`avm2/displayobject_mask [output]` 8→**0**, `avm2/loader_events [output]` 16→**0**,
`avm2/loader_loadbytes_events [output]` 16→**0**.

**Two board claims are refuted (details in §2):**

1. **P2's owner file is wrong for 9 of the 13 census comparisons.** They have
   `u32 shape_data[1][4] = {0}` — the recompiler's flattener never runs for them.
   Their curves come from the **runtime drawing API**, flattened by a four-bucket
   flatness ladder (`1 / 4 / 8 / 16` segments) in `avm2_display.c:7694`,
   `action.c:28336` and `action.c:27667`. That ladder — not `swf.cpp:8653` — is the
   real P2 mechanism, and it is where all the flips are.
2. **The "~0.6 px" magnitude is an order of magnitude too large.** Both flatteners
   inscribe chords, so the largest possible ours-vs-Ruffle gap is bounded by lyon's own
   tolerance, 0.1 px, and measures 0.02–0.06 px in practice (§2.3). P2 cannot own the
   0.62 px mean edge offset on `simple_shapes/masks`, nor `acid-blend-2 [output.26]`'s
   coverage 0.13-vs-0.75 edge column (P9). Those need a different owner.

---

## 1 — Instrument validation (local Dawn reproduces the CI grade on this family)

Every number below is a local `--mode=graphics` render against the test's
`output.expected.png`, harvested with `ruffle-tests/render_canary.py`. That is normally
*not* a grade (playbook: local Dawn ≠ CI lavapipe) — but on this family it is, and here
is the proof. Local baseline vs CI run `31647430265`:

| comparison | CI excess | local base | |
|---|---:|---:|---|
| `avm2/displayobject_mask [output]` | 8 | 8 | ✅ |
| `visual/avm2_button_scroll_rect [output]` | 9 | 9 | ✅ |
| `avm2/loader_events [output]` | 16 | 16 | ✅ |
| `avm2/loader_loadbytes_events [output]` | 16 | 16 | ✅ |
| `from_shumway/MaskTest [output]` | 17 | 17 | ✅ |
| `avm2/mouse_pick_dobj_mask [output]` | 24 | 24 | ✅ |
| `avm2/mouse_pick_non_interactive_dobj_mask [output]` | 24 | 24 | ✅ |
| `from_shumway/doubleAndRegister [output]` | 32 | 32 | ✅ |
| `visual/simple_shapes/scroll_rect_mask [output]` | 42 | 42 | ✅ |
| `visual/drawing_api/fills_and_lines [output]` | 104 | 104 | ✅ |
| `avm2/graphics_simple_shapes [output]` | 252 | 252 | ✅ |
| `visual/simple_shapes/masks [output]` | 1738 | 1738 | ✅ |
| `visual/simple_shapes/masks_equal_clipdepth [output]` | 1738 | 1738 | ✅ |
| `visual/fonts/glyph [output]` | 6 | 6 | ✅ |
| `from_shumway/acid/acid-blend-2 [output.26]` | 1 outlier | 1 outlier | ✅ |
| `text/auto_size/height [output]` | 12 | 15 | ~ |
| `avm2/displayobject_hittestpoint_boundary [output]` | 76 | 976 | ✗ (quality=high, AA) |

15 of 17 exact. So a local flip on this family is a CI flip, and a local band move is a
CI band move. The two exceptions are the only `quality = "high"` / text-AA rows.

---

## 2 — Mechanism: the census splits into two disjoint families

### 2.1 The split (measured, not inferred)

`RecompiledTags/draws.c` carries the recompiler's flattened vertices as
`u32 shape_data[N][4]`. `N == 1` means the table is the empty placeholder — the
recompiler emitted **no shape geometry at all** for that SWF, so
`SWFRecomp/src/swf.cpp:8653` cannot possibly affect its render.

| comparison | `shape_data` rows (base) | family |
|---|---:|---|
| `avm2/displayobject_mask` | **1 (empty)** | **R — runtime** |
| `avm2/loader_events` | **1 (empty)** | **R** |
| `avm2/loader_loadbytes_events` | **1 (empty)** | **R** |
| `from_shumway/MaskTest` | **1 (empty)** | **R** |
| `avm2/mouse_pick_dobj_mask` | **1 (empty)** | **R** |
| `avm2/mouse_pick_non_interactive_dobj_mask` | **1 (empty)** | **R** |
| `avm2/displayobject_hittestpoint_boundary` | **1 (empty)** | **R** |
| `visual/drawing_api/fills_and_lines` | **1 (empty)** | **R** |
| `avm2/graphics_simple_shapes` | **1 (empty)** | **R** |
| `visual/avm2_button_scroll_rect` | 282 | S — recompiler |
| `visual/simple_shapes/scroll_rect_mask` | 318 | S |
| `from_shumway/acid/acid-blend-2` | 852 | S |
| `from_shumway/doubleAndRegister` | 2841 | S |
| `visual/fonts/glyph` | 10998 | S |
| `text/auto_size/height` | 51264 | S |
| `visual/simple_shapes/masks` (+`_equal_clipdepth`) | 9444 | S |

**9 of the 13 priced census comparisons are family R.** `displayobject_mask` — the
board's flagship "four-fold-symmetric sagitta signature" — is family R. Its whole
geometry is `circle.graphics.drawCircle(50, 50, 40)` executed at runtime.

Confound check: no family-S test's `RecompiledScripts`/`RecompiledABC` mentions
`curveTo` / `drawCircle` / `drawEllipse` / `drawRoundRect`, so the two legs never
overlap on a single comparison.

### 2.2 The runtime ladder, and why it biases outward

All three runtime sites pick a chord count from the squared distance between the control
point and the chord midpoint, in pixels:

```c
int segs = flat < 0.25f ? 1 : flat < 4.0f ? 4 : flat < 25.0f ? 8 : 16;
```

`Graphics.drawCircle` emits 8 quadratic arcs of 45° with the control point at
`r / cos(π/8)`; for `r = 40 px` each arc has `flat ≈ 39` → the ladder saturates at
**16 chords per arc, 128 for the circle**. lyon at `DEFAULT_TOLERANCE = 0.1 px` emits
**6 per arc, 48 for the circle**.

The 8-arc quadratic decomposition itself bulges ~0.31 % **outside** the true circle at
each arc midpoint. Finer chords track that bulge faithfully; lyon's coarser chords cut
it off. So *ours is wider than Ruffle's, and wider than the true circle*.

Scanline simulation of `displayobject_mask` (`scratchpad/circlescan.py`), row `y = 10`,
sample at `y = 10.5`:

| polygon | crossings | filled span |
|---|---|---|
| ours (bucketed, 128 verts) | `43.424 … 56.576` | **x 43..56** |
| lyon (48 verts) | `43.679 … 56.321` | **x 44..55** |
| true circle | `43.695 … 56.305` | x 44..55 |

The rendered PNGs match the simulation exactly: our render fills `43..56` on that row,
Ruffle's expected PNG fills `44..55`, and the four differing pixels are precisely
`(43,10) (56,10) (10,43) (10,56)` — the ends of the tangent row and tangent column.
Every other row is byte-identical. Mechanism proven end-to-end before a line was
changed.

### 2.3 Why the "~0.6 px" figure cannot be flattening

Max radial error of the inscribed polygon (`scratchpad/lyonsim2.py`), circular arcs:

| R (px) | arc | lyon (tol 0.1) | ours base (floor 6, 1 twip) | ours (floor 1, 2 twips) |
|---:|---:|---:|---:|---:|
| 20 | 90° | 0.0408 | 0.0189 | 0.0345 |
| 39.5 | 90° | 0.0447 | 0.0181 | 0.0373 |
| 80 | 45° | 0.0837 | 0.0355 | 0.0809 |
| 160 | 30° | 0.0806 | 0.0418 | 0.0794 |

Both are inscribed, so the gap between them is bounded by lyon's own tolerance
(0.1 px) and is 0.02–0.06 px in practice. A 0.62 px mean edge offset is ~10× that
ceiling. The `simple_shapes/masks` pair's offset — whose two fitted edges also have
**different slope** (−0.8314 vs −0.8404, a ~1 % scale difference) — is a
transform/scale defect, not a flattening one. Leg C does move it (1738 → 1497,
−14 %), consistent with flattening being a *component* of that row, not its owner.
Likewise `acid-blend-2 [output.26]`'s single outlier (coverage 0.13 vs 0.75 ⇒ ~0.6 px
edge shift) survives every leg unchanged: **P9 is not a P2 rider.**

### 2.4 Why the tolerance knob ≈ the full lyon port, and the floor knob ≈ nothing

Chord counts, circular arcs (`scratchpad/lyonsim.py`):

| R (px) | arc | lyon | ours base (floor 6, 1 twip) | floor 1, 1 twip (**leg A**) | floor 6, 2 twips (**leg B**) |
|---:|---:|---:|---:|---:|---:|
| 5 | 45° | 2 | 6 | 3 | 6 |
| 10 | 45° | 3 | 6 | 4 | 6 |
| 20 | 90° | 9 | 12 | 12 | 9 |
| 39.5 | 90° | 12 | 17 | 17 | 12 |
| 80 | 45° | 8 | 12 | 12 | 8 |
| 160 | 90° | 23 | 34 | 34 | 24 |

`ceil(sqrt(dev_twips / 2))` reproduces lyon's count essentially exactly. The 6-chord
floor only binds when `dev < 36 twips (1.8 px)`, i.e. on curves too small to move a
pixel — hence leg A's −1 channel on the whole probe set. **That is the refutation of
"the floor is the dominant term".**

---

## 3 — Per-leg, per-test results

All values are `diff_channels` (= `outliers` at these tests' `tolerance = 0`), local
`--mode=graphics`. `PNG-MOVED` = md5 of our render changed.

### 3.1 Family R — leg R (runtime lyon/Levien port)

| comparison | base | leg R | move |
|---|---:|---:|---|
| `avm2/displayobject_mask [output]` | 8 | **0** | **FLIP fail→pass** |
| `avm2/loader_events [output]` | 16 | **0** | **FLIP fail→pass** |
| `avm2/loader_loadbytes_events [output]` | 16 | **0** | **FLIP fail→pass** |
| `avm2/mouse_pick_dobj_mask [output]` | 24 | 6 | band −18 |
| `avm2/mouse_pick_non_interactive_dobj_mask [output]` | 24 | 6 | band −18 |
| `from_shumway/MaskTest [output]` | 17 | 7 | band −10 |
| `avm2/graphics_simple_shapes [output]` | 252 | 240 | band −12 |
| `avm2/displayobject_hittestpoint_boundary [output]` | 976 | 976 | unchanged (`quality=high`; CI grades it 76) |
| `visual/drawing_api/fills_and_lines [output]` | 104 outl | 104 outl | **md5 identical** — every curve there is already sub-tolerance |

Net on family R: **3 flips, 4 band moves, 0 regressions.**

### 3.2 Family S — legs A / B / C (recompiler)

| comparison | base | leg A (floor 1) | leg B (tol 2 tw) | leg C (lyon port) |
|---|---:|---:|---:|---:|
| `visual/avm2_button_scroll_rect [output]` | 9 | 9 | **3** | 6 |
| `visual/simple_shapes/scroll_rect_mask [output]` | 42 | 42 | **16** | 20 |
| `from_shumway/doubleAndRegister [output]` | 32 | 32 | 38 ⚠ | **26** |
| `visual/simple_shapes/masks [output]` | 1738 | 1737 | 1605 | **1497** |
| `visual/simple_shapes/masks_equal_clipdepth [output]` | 1738 | 1737 | 1605 | **1497** |
| `text/auto_size/height [output]` | 15 | 15 | 15 | 15 |
| `visual/fonts/glyph [output]` | 6 | 6 | 6 | 6 |
| `from_shumway/acid/acid-blend-2 [output.26]` outliers | 1 | 1 | 1 | 1 |
| `from_shumway/acid/acid-blend-2 [output.10/.15/.20/.40]` | pass | pass | pass | pass |

Sum over the three near-pass rows (`avm2_button_scroll_rect` + `scroll_rect_mask` +
`doubleAndRegister`): base **83** → leg B **57** → leg C **52**.
**No leg flips anything in family S.** Leg B alone makes `doubleAndRegister` worse
(32→38); leg C fixes that and is the only leg that is a faithful port, so leg C is the
one to keep if any recompiler leg ships.

Emitted vertex counts (`shape_data` rows) — proof the recompiler change took effect,
and a free size win:

| test | base | leg A | leg B | leg C |
|---|---:|---:|---:|---:|
| `visual/simple_shapes/masks` | 9444 | 9216 | 7239 | **5844** (−38 %) |
| `text/auto_size/height` | 51264 | 48780 | 33213 | **33213** (−35 %) |
| `visual/fonts/glyph` | 10998 | 10749 | 8355 | **7443** (−32 %) |
| `from_shumway/doubleAndRegister` | 2841 | 2841 | 2124 | **2016** (−29 %) |
| `visual/avm2_button_scroll_rect` | 282 | 282 | 186 | **186** (−34 %) |
| `visual/simple_shapes/scroll_rect_mask` | 318 | 318 | 222 | **222** (−30 %) |
| `from_shumway/acid/acid-blend-2` | 852 | 852 | 660 | **636** (−25 %) |

---

## 4 — Render canary

`ruffle-tests/flatten_canary.txt` (11 tests), captured clean-tree vs combined patch,
both with `--recompile` after a cmake rebuild of the recompiler (false-negative mode 1).

```
RENDER CANARY  before=canBefore  after=canAfter   11 tests / 11 comparisons
  IDENTICAL    11
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

**Read this honestly: that result is weaker than it looks.** I counted the quadratics
in each canary test's regenerated `draws.c` (`path_data` rows tagged `3.0f`) and
**all 11 canary tests contain zero quadratics** — the standing canary set has no
curve-bearing member with a passing image comparison. So 11/11 IDENTICAL proves the
patch does not perturb straight-edge, text-layout, bitmap, gradient, blend or mask
compositing, and nothing else. (`regression/avm2_morph` byte-identical does confirm the
morph pairing is untouched.)

The real curve-bearing regression evidence comes from the probe sets instead:

| curve-bearing regression check | result |
|---|---|
| `text/auto_size/height [output]` — 460 embedded glyphs, 51 264 → 33 213 vertices | **PNG byte-identical**, all legs |
| `visual/fonts/glyph [output]` — 120 glyphs, 10 998 → 7 443 vertices | **PNG byte-identical**, all legs |
| `from_shumway/acid/acid-blend-2 [output.10/.15/.20/.40]` — passing comparisons, 852 → 636 vertices | **still pass, 0 outliers**, all legs (channel drift +2…+26 within tolerance) |
| `visual/drawing_api/fills_and_lines [output]` (leg R) | **PNG byte-identical** |
| trace status, every test in every leg | **no change** (`render_canary.py compare` reports `TRACE STATUS CHANGES: (none)` for base→legR and base→legC) |
| image status, every test in every leg | **no regression**; only the 3 leg-R `fail → pass` flips |

**Follow-up owed to the playbook:** the standing `render_canary_tests.txt` should gain a
curve-bearing, image-passing member. `from_shumway/acid/acid-blend-2` (5 comparisons,
4 of them passing, 636 flattened vertices) is the obvious candidate and is the one this
session actually used as the curve canary.

---

## 5 — Patch scope, and the note the coordinator asked for

### Files

| file | leg | lines |
|---|---|---|
| `SWFModernRuntime/include/curve_flatten.h` | R | **new**, ~120, header-only `static inline` |
| `SWFModernRuntime/src/avm2/avm2_display.c` | R | 1 include + 1 block (`gfx` path build, ~7694) |
| `SWFModernRuntime/src/actionmodern/action.c` | R | 1 include + 2 blocks (`drawingFinalizePath` ~28336, `drawingCmdWindingHitTest` ~27667) |
| `SWFRecomp/src/swf.cpp` | A/B/C | Levien helpers + `addCurvedEdgeLevien` before `interpretShape`; one `else if` arm and one call-site branch in the CurvedEdgeRecord path |

Deliverable patches, in this directory:

* `w2-gfx-flatten-floor.patch` — leg A alone (refuted; kept for the record)
* `w2-gfx-flatten-tolerance.patch` — leg B alone (superseded by C)
* `w2-gfx-flatten-runtime.patch` — **leg R, the shippable one** (runtime only)
* `w2-gfx-flatten-recompiler.patch` — leg C (recompiler only)
* `w2-gfx-flatten-combined.patch` — R + C

Leg A/B/C are mutually exclusive edits of the same block; the shipped `swf.cpp`
carries a `const bool curve_flatten_levien = true;` knob so the pre-Levien arm stays
in the file for future A/B.

### Recompile invalidation

* **Leg R is runtime-only.** No `RecompiledScripts` / `RecompiledTags` invalidation, no
  cmake rebuild of the recompiler needed by CI, ccache still hits on everything else.
* **Leg C is a recompiler change and invalidates every generated shape table in the
  corpus.** CI regenerates everything; expect a slower run and a `shape_data` size
  drop of 25–38 % on curve-heavy SWFs.

### Trace-side effects (asked for explicitly)

* **Leg R — low but non-zero.** `drawingCmdWindingHitTest` was changed in lockstep with
  `drawingFinalizePath` (their comment requires it), so fill and hit test still agree.
  A `hitTest`/`hitTestPoint` on a point within ~0.05 px of a drawing-API curve boundary
  can change. Drawing-API *bounds* are unaffected: they come from `draw_union_point()`
  on the control/anchor points, not from flattened vertices.
* **Leg C — real, and the reason it is CONDITIONAL.** `processShape()` derives
  `shape.min` / `shape.max` from the flattened vertex list, so a coarser flattening can
  shrink a shape's bounds by up to ~1 twip (0.05 px) wherever the extreme point is
  mid-curve rather than an anchor. That feeds `getBounds` / `getRect` /
  `_width` / `_height` trace output. **Leg C must be dispatched with the trace suites,
  not just `images=true`.** Morph shapes are untouched (they keep equal-parameter
  stepping so the index pairing from s14 stays exact — `regression/avm2_morph` is
  byte-identical in the canary).

### Recommendation

1. **Ship leg R now.** 3 proven flips, 4 band moves, zero measured regressions, no
   recompile invalidation, trivially revertable.
2. **Hold leg C for a run that is already regenerating the corpus.** It buys 0 flips
   and 6 band moves (incl. the designated `simple_shapes/masks` instrument, −14 %),
   plus a 25–38 % shape-table shrink, but its blast radius is every shape in the corpus
   and it can move `getBounds` traces. Worth a dedicated `mode=graphics categories=all`
   dispatch on its own, never bundled with other pixel work.
3. **Re-price the board.** P2's remaining family-S band moves are real but flipless;
   the 0.62 px `simple_shapes/masks` offset and P9's `acid-blend-2 [output.26]` need a
   new owner (transform/scale, not flattening).

---

## 6 — Reproduction

```bash
# worktree
cd /home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a12c1885e86d10a03
cd SWFRecomp/build && cmake .. -DCMAKE_BUILD_TYPE=Release && make -j4 && cd ../..

# probe sets (families are disjoint; see §2.1)
python3 ruffle-tests/render_canary.py capture --label base \
        --tests ruffle-tests/flatten_probe_tests.txt --recompile --jobs 2
python3 ruffle-tests/render_canary.py capture --label legR \
        --tests ruffle-tests/flatten_probe_R.txt --recompile --jobs 2
python3 ruffle-tests/render_canary.py capture --label legC \
        --tests ruffle-tests/flatten_probe_S.txt --recompile --jobs 2
```

Analysis scripts live in this session's scratchpad
(`lyonsim.py`, `lyonsim2.py`, `circlescan.py`, `pixdiff.py`, `rowspan.py`,
`summarize.py`); `circlescan.py` is the one that predicts both renders exactly and is
worth keeping.
