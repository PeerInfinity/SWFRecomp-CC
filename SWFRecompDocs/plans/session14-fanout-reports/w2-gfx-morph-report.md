# w2-gfx-morph — the morph family, measured

Session 14, wave 2 (implementation). Brief: `wave1-board-audit.md` §6.4 + §7 P1
("Morph curve subdivision, +7 candidates, MED") and `wave1-gfx-curvejoint.md`
§4.2 (scale-aware flattening tolerance, +0–1). Worktree
`agent-a3b01760b5d476323`, baseline `0a99be1a9`, **nothing committed**.
Deliverables: **`wave2/w2-gfx-morph.patch`** (leg A, recommended),
**`wave2/w2-gfx-morph-legb.patch`** (leg B, measured, **NOT recommended as it
stands** — §5.3), and this report.

**Headline**

1. **P1 IS REFUTED AT STEP 0, AND ALL SEVEN CANDIDATES ARE DEAD.** Neither
   named beneficiary contains a single quadratic in its morph shapes.
   `from_gnash/misc-ming.all/morph_test1`'s two morph characters are
   `MLLLL` / `MLLLL` and an empty shape; `visual/cache_as_bitmap/morph`'s is
   `MLLLL` / `MLLLL`. **They are squares.** No chord count, adaptive or
   otherwise, can move a pixel in either test, and both were measured
   byte-identical under the patch that this report ships (§4.3). The board row
   "extending adaptive subdivision to morph shapes is a 7-comparison lead"
   should be **struck**.
2. **A real morph defect was found in the same code and fixed instead.** Our
   runtime lerps start-shape vertices against end-shape positions **by index**,
   and the two streams do **not** emit the same number of vertices: SWF allows a
   `StraightEdgeRecord` to pair with a `CurvedEdgeRecord` (1 vertex against 6)
   and allows unpaired `StyleChangeRecord`s. **9 of the corpus's 20 morph tests
   carry a desynchronised morph shape today** (§3.2), including every morph
   whose end shape is round.
3. The fix is a pre-pass that pairs the two streams the way Ruffle's
   `lerp_edges` does, then hands both parsers a shared per-record vertex count.
   That shared count is also what **unlocks adaptive subdivision for morphs** —
   the thing s13 gated out — so the briefed mechanism ships after all, just not
   where the board expected it.
4. Blast radius is exactly enumerable and was graded end to end: **20 tests
   corpus-wide contain a `DefineMorphShape`** (4478 SWFs scanned), 9 carry a
   desynchronised morph, 11 are predicted and measured byte-identical.
5. **Both legs move the scoreboard by zero.** Leg A is a correctness fix with no
   pixel or trace consequence today (§4.3 — and *why* it has none is itself a
   finding: the only pixel-bearing desynchronised test is insensitive to morph
   end positions at its graded frame). Leg B, the briefed scale-aware tolerance,
   flips nothing and moves its one named flip candidate **backwards** for a
   reason worth writing down (§5.3). Zero regressions in either leg; the
   tripwire, s13's flipped members and the dispositioned tie pair are all
   byte-identical.

---

## 1. Instruments

Built in the scratchpad (`…/scratchpad/gfx-morph/`), no source edits:

| file | what |
|---|---|
| `morphscan.py` | parses `DefineMorphShape`/`2` (incl. the morph fill/line style arrays that `wave1-gfx-curvejoint`'s `swfquad.py` bailed on) and reports **both** edge streams: record-type sequence + per-curve chord deviation |
| `corpus_morph_scan.py` / `.json` | all 4478 test SWFs × {morph tag count, per-stream curve count, max dev, type-sequence mismatch} |
| `merge_sim.py` / `.txt` | simulates the shipped pairing merge per character: vertex totals before/after and the resulting chord counts |
| `legb_model.py` / `.json` | leg B: which tests change under a scale-aware tolerance, and their residual sagitta before/after |

`wave1-gfx-curvejoint.md`'s `corpus_curve_scan.json` reports `morph_n = 0` for
every test in the corpus. That is a **tool artefact**, not a fact: its scanner
raises `name 'skip_morph_fill_styles' is not defined` on every morph tag and
records zero curves. The morph columns of that file must not be read as data.

---

## 2. Step 0 — the P1 refutation

`wave1-board-audit.md` §6.4 named seven comparisons —
`from_gnash/misc-ming.all/morph_test1 frame1…frame6` (excess 212 / 789 ×4 / 589)
and `visual/cache_as_bitmap/morph output` (excess 2 832) — as "exactly the
population s13's curve-subdiv gated out". The premise is that those tests
contain morph curves. They do not.

| test | morph char | StartEdges | EndEdges | quadratics |
|---|---|---|---|---|
| `from_gnash/misc-ming.all/morph_test1` | 4 | `MLLLL` | `MLLLL` | **0** |
| | 7 | *(empty shape)* | *(empty)* | **0** |
| `visual/cache_as_bitmap/morph` | 1 | `MLLLL` | `MLLLL` | **0** |

(`M` = StyleChangeRecord, `L` = StraightEdgeRecord, `C` = CurvedEdgeRecord.)

Both are four-sided polygons morphing to four-sided polygons. `num_passes` is
never consulted for either character, at any tolerance, so the entire briefed
mechanism is a no-op on all seven comparisons. This is confirmed twice over:
by the SWF scan above, and empirically — under the patch this report ships,
both tests render **byte-identical md5** (§4.3).

What those seven comparisons actually are:

- `morph_test1` frames 2–6 are the *same* diff (ink IoU 0.974, 2.3 % of the
  expected ink missing, 0.3 % of ours extra, max diff 255, zero shift). A
  square whose interpolated size/position is slightly wrong — a morph **ratio /
  interpolation** question, not a flattening one. Frame 1 differs (excess 212,
  ink IoU 0.9999).
- `cache_as_bitmap/morph` is **max diff 1** over 2 832 channels with ink IoU
  1.00 against a 0-outlier budget: a one-unit AA tie on the edges of a square.
  Geometry cannot reach it; it is an amplitude row, not a position row.

**Board correction.** P1 should be struck and replaced with two much smaller
rows: "morph interpolated-geometry offset (`morph_test1`, 6 cmps, mechanism
unknown, needs its own probe)" and "`cache_as_bitmap/morph`: 1-unit AA tie,
cap it".

### 2.1 What `morph_test1`'s seven-comparison diff actually is (measured)

Pixel-differencing the CI actual against the golden (`probe_diff.py`,
`probe_morph_test1.py`):

| frame | differing px | where |
|---|---:|---|
| frame1 | **210** | **100 % inside the label text band** (`y ≤ 12`): ours `(0,0,0)`, expected `(255,0,0)`. A text-colour row. |
| frame2–6 | **263** each | 63 px (24 %) in the same text band; the remaining **200 px are the right and bottom 1-pixel edges of a 100×100 filled square** (ours `(255,255,255)`, expected `(0,255,0)`, bbox `x[699,799] y[499,599]` in frame 6) |

Ink bounding boxes are **identical** to the golden in all six frames
(`d = (0,0,0,0)`), so nothing is displaced or mis-sized. 200 = 100 + 100 is a
one-pixel edge-inclusion difference on a filled rectangle — the integer-twip /
fill-edge family — and the rest is text colour. **No part of this test's diff is
reachable from curve flattening**, which is consistent with it having no curves.

## 3. What is actually wrong with our morph shapes

### 3.1 The model, and where it breaks

We flatten the **start** shape into vertices, flatten the **end** shape into a
parallel array, and the runtime lerps them **by index**
(`swf.cpp` ~9203: `morph_end_positions[t.verts[j].morph_index]`, with a
"fall back to the start position" arm when the index is out of range). That is
a legitimate model — a quadratic is affine in its control points, so lerping
two curves' points at matched `t` equals evaluating the lerped curve at `t`,
which is exactly what Ruffle's `lerp_edges` produces — **provided each edge pair
emits the same number of vertices at the same parameters on both sides.**

It does not, for two reasons:

1. **A `StraightEdgeRecord` may pair with a `CurvedEdgeRecord`.** SWF allows it
   and Flash generates it constantly (a polygon morphing into a rounded shape).
   Ruffle handles it by promoting the straight edge to a degenerate quadratic
   with `control = pen + delta/2`
   (`~/CC/ruffle core/src/display_object/morph_shape.rs:545-590`). We emitted
   **1** vertex for the straight side and **6** for the curved one, so every
   vertex after the first such pair is matched against the wrong partner.
2. **`StyleChangeRecord`s need not pair.** Ruffle explicitly walks one side
   alone when only that side has one ("*StyleChangeRecord move_to can appear in
   both start and end records, and not necessarily in matching pairs*",
   `morph_shape.rs:283`). We pushed a vertex on the start side for any new
   `Path` and on the end side for any `MoveTo`, independently.

### 3.2 How much of the corpus this affects

`corpus_morph_scan.py` over all **4 478** test SWFs: **20 tests** contain a
`DefineMorphShape`/`DefineMorphShape2`. Of those, **9 carry at least one
desynchronised morph character** (start and end vertex totals disagree):

| test | char | start verts | end verts | why |
|---|---|---:|---:|---|
| `avm1/click_block` | 8 | 22 | 101 | 16 straight↔curve pairs |
| `avm2/click_block` | 8 | 22 | 101 | same SWF |
| `avm2/morph_shape` | 1 | 19 | 99 | 16 straight↔curve pairs |
| `avm1/movieclip_hittest_shapeflag` | 27 | 19 | 59 | 8 straight↔curve |
| | 41 | 1 424 | 1 429 | style-change asymmetry |
| `avm2/displayobject_getrect` | 2 | 3 316 | 3 298 | doubled `MoveTo` on the start side |
| `from_shumway/acid/acid-morph` | 1 | 13 | 53 | 8 straight↔curve |
| `from_shumway/timeline/nav/morphShape` | 1 | 12 | 52 | 8 straight↔curve |
| `avm1/hittest_morph_input` | 1 | 10 | 9 | start-only `MoveTo` |
| `from_shumway/invalidClipDepth` | 161 | 5 | 4 | end stream has no leading `MoveTo` |

The other 11 morph tests are already balanced and are predicted — and measured —
byte-identical.

### 3.3 The fix

A pre-pass reads **both** streams before either is parsed (the tag's `Offset`
field gives the EndEdges position directly, so no speculative walk is needed),
pairs the records exactly as Ruffle does, and hands each parser a per-record
vertex count:

* an edge pair emits `N` vertices on both sides — `1` for straight↔straight, and
  `max(N(dev_start), N(dev_end))` when either side is curved, with
  `N(dev) = clamp(ceil(sqrt(dev / 1 twip)), 6, 64)`, the same rule the
  plain-shape arm has used since s13;
* a straight edge paired with a curve is subdivided into those same `N` chords.
  Because a degenerate quadratic (`control = midpoint`) evaluates to plain
  linear interpolation, subdividing the segment uniformly reproduces Flash's
  promotion exactly;
* a start-only `StyleChangeRecord` makes the end side emit a copy of its own
  pen; an end-only one moves the end pen and emits nothing.

Anything unrecognised (a `StateNewStyles` record, a truncated stream, a zero
`Offset`) discards the plan and restores the historical fixed-6 behaviour, and a
post-hoc assertion prints a warning if the two totals still disagree.

**This is what makes the briefed adaptive subdivision possible for morphs.**
s13 gated morphs out because "an adaptive count on *both* desynchronises the
pairing, since a morph's start and end curves have different geometry and would
land on different `N`" — true of two independent counts, but not of one shared
count computed from both.

## 4. Leg A ledger — morph edge pairing (19 tests, all of them)

Legs: `morph_before` (baseline `0a99be1a9`) → `legA`. Both captured with
`--recompile` and a verified-non-stale recompiler (§8). Every test in the corpus
containing a `DefineMorphShape` is in the set.

### 4.1 The patch does what it claims (verified in the generated code)

| check | result |
|---|---|
| pairing assertion (`morph shape N vertex pairing mismatch`) | **0 warnings across all 19 tests** — the pre-pass and the real parse agree everywhere, and every start vertex now has an end partner |
| `acid/acid-morph` `morph_end_shape_data` | **45 → 294** entries (char 1's 12 straight edges now subdivide with their curved partners at `N ∈ {10, 12, 13}`) |
| other warnings | unchanged; `movieclip_hittest_shapeflag`'s 2 johnson cycle-cap warnings are **pre-existing** — `constructEdges` builds two nodes per **Path**, not per vertex, so the cycle graph is untouched by vertex counts |

### 4.2 Trace: **zero movement**

All 19 tests kept their status: 15 `pass`, 4 `output_mismatch`
(`movieclip_hittest_shapeflag`, `bounds_mode`, `displayobject_getrect`,
`acid-morph` — the same four as at baseline, with the same diffs).

### 4.3 Pixels: **zero movement, and that is the headline**

All 10 image comparisons in the set are **byte-identical md5** before and after:

| comparison | before = after | note |
|---|---|---|
| `morph_test1 [frame1…frame6]` | 212 / 789 ×4 / 589 outliers | predicted identical (no morph curves, balanced streams) |
| `cache_as_bitmap/morph [output]` | 2 832 outliers, max 1 | predicted identical (same) |
| `acid/acid-morph [output]` | **4 308 / 2 600 budget, max 255** | **NOT predicted identical** — see below |
| `invalidClipDepth [output]` | **pass**, tolerance 0 | desynchronised at baseline; the tolerance-0 canary **holds** |
| `regression/avm2_morph [output]` | skip (no golden) | — |

`acid/acid-morph` is the only pixel-bearing comparison whose morph data this
patch changes, and its render did not move by one byte even though
`morph_end_shape_data` grew 6.5×. Because the start outline is unchanged (the
new vertices are collinear points on the same polygon), a byte-identical render
means **the end positions are not reaching the rasteriser for the graded frame**
— the interpolation is running at ratio ≈ 0 there, or on a different object.
The tag stream places a ratio of 63 276/65 535 at the last frame, so this is a
ratio-plumbing question downstream of the recompiler, not a geometry one.

**Net leg A: +0 comparisons, +0 trace, 0 regressions.** It is a correctness fix
with no scoreboard movement today: it removes a data defect that would otherwise
silently corrupt any morph the moment the ratio path is fixed, and it is a
prerequisite for the path-command half in §6.

## 5. Leg B — scale-aware flattening tolerance

Implemented as `wave1-gfx-curvejoint.md` §4.2 specifies: a pre-pass over the tag
stream records, per character, the largest static placement scale it is ever
composed at (propagated through `DefineSprite` nesting, floored at 1.0), and the
plain-shape arm divides the tolerance by it —
`tol_effective = 1 twip / max_static_scale[char_id]`.

### 5.1 The changed set is nine tests, computed exactly

`legb_model.py` reproduces the shipped rule in Python over all 60 corpus tests
that contain a `DefineShape` quadratic, and reports every curve whose `N`
changes. Because the scale is floored at 1.0, **every other test in the corpus
is bit-identical by construction**.

| test | curves changed | max scale | worst residual before → after | comparisons |
|---|---:|---:|---|---|
| `from_shumway/acid/acid-mask` | 166 / 229 | 7.54 | 0.333 → **0.050** px | 3 fail (excess 9 458–12 080) |
| `visual/simple_shapes/strokes/scale` | 8 / 8 | 20.00 | 0.227 → **0.048** px | 1 fail (66 243, `extra_element`) |
| `from_shumway/acid/acid-scale` | 8 / 8 | 7.27 | 0.217 → **0.046** px | **1 fail (excess 302, `b_tiny`)** |
| `from_shumway/acid/acid-video` | 93 / 361 | 4.39 | 0.190 → 0.050 px | 2 fail (`no_render`), 1 pass |
| `from_shumway/acid/acid-clip` | 13 / 123 | 2.68 | 0.127 → 0.049 px | 1 **pass** |
| `from_shumway/acid/acid` | 8 / 8 | 2.88 | 0.124 → 0.047 px | 16 **pass** |
| `visual/cache_as_bitmap/scroll_rect_scaled` | 8 / 8 | 2.00 | 0.098 → 0.046 px | 1 fail (40 946) |
| `from_shumway/acid/acid-bitmap-draw_quality_high` | 1 / 248 | 1.03 | 0.051 → 0.049 px | 1 fail (194 784, `blank_render`) |
| `from_shumway/acid/acid-bitmap-draw_quality_low` | 1 / 248 | 1.03 | 0.051 → 0.049 px | Ruffle `known_failure` |

One MSAA quantum is 0.25 px, so only `acid-mask` clears a quantum of movement;
`acid-scale` (the wave-1 flip candidate, excess 302) moves 0.17 px. **18
currently-passing comparisons are inside the changed set** (`acid` ×16,
`acid-clip`, `acid-video [output.01]`) and are the real risk this leg carries.

### 5.2 Leg B ledger — measured

Legs: `after_a` (= the baseline binary; leg A is provably inert on every test
here, none of which contains a `DefineMorphShape`) → `legB`. 15 tests, 40
comparisons, both captured with `--recompile` and a verified-non-stale binary.
**Every "before" number reproduces the CI board exactly** (`acid-mask` 12 096 −
16 = 12 080 excess, `acid-scale` 302, `strokes/scale` 66 243, `timeline_loop`
41/61, `acid-blend-2 output.40` max 135), so this table is CI-grade.

**Status changes: NONE — 0 flips, 0 regressions.** 24 comparisons moved md5.

| comparison | before | after | verdict |
|---|---:|---:|---|
| `acid-mask [output.01]` | 12 096 out | **12 040** | fail → fail, −56 |
| `acid-mask [output.05]` | 10 937 | **10 924** | fail → fail, −13 |
| `acid-mask [output.10]` | 9 474 | **9 473** | fail → fail, −1 |
| `visual/simple_shapes/strokes/scale` | 66 243 | **66 051** | fail → fail, −192 |
| `cache_as_bitmap/scroll_rect_scaled` | 41 846 | **41 818** | fail → fail, −28 |
| `acid-video [output.01]` | 14 192 / 20 000 | **14 002** | pass → pass, −190 |
| **`acid-scale [output]`** | **302 / 0** | **342** | **fail → fail, +40 — the wrong way** |
| `acid-clip [output]` | 0 outliers | 0 outliers | pass → pass (only `diff_channels` 7 013 → 7 015) |
| `acid [output.01…16]` (16 **passing**) | 8 659–12 347 | −14…+4 each | pass → pass, largest budget headroom 1 000+ |
| `acid-bitmap-draw_quality_{high,low}` | 194 784 | identical | the single refined curve is invisible |

Canaries, all held byte-identical:

| canary | result |
|---|---|
| **tripwire `acid-blend-2 [output.40]`** | **max diff 135, 0 outliers — IDENTICAL** ✔ (and `output.10/15/20/26` identical too, `output.26` still 1 outlier / 127) |
| s13's six flipped `timeline_loop` members | **all still passing**, 41/61 outliers unchanged ✔ |
| dispositioned tie pair `simple_shapes/masks` + `masks_equal_clipdepth` | **byte-identical, 2 624 outliers, no movement** ✔ (neither is in the changed set — their characters are placed at scale 1.0) |
| `winding_rule`, `regression/mask_sibling_union` | identical ✔ |
| trace, all 15 tests | unchanged ✔ |

### 5.3 Verdict on leg B: **measured, and I recommend NOT merging it as it stands**

1. **It flips nothing.** `acid-scale`, wave 1's "only real flip candidate", has
   `max_outliers = 0`: it needs a *pixel-exact* render, not 0.17 px less
   sagitta. No amount of flattening reaches that.
2. **It moves `acid-scale` the wrong way (302 → 342).** That is the informative
   result, and it has a mechanism: Ruffle's lyon tolerance is **0.1 px in screen
   space**, ours is now **0.05 px in screen space** — half of it. At
   `acid-scale`'s scale the shipped residual goes 0.217 px → 0.046 px, i.e. it
   **crosses over** Ruffle's own ~0.1 px error instead of converging on it. Being
   more accurate than the reference costs outliers against a reference-derived
   golden.
3. Everything else it does is a sub-1 % band move on rows that are thousands of
   outliers from their thresholds.

**The tunable follow-up, priced:** set the scale-aware tolerance to **2 twips /
scale (= 0.1 px on screen), matching Ruffle's lyon tolerance exactly**, instead
of 1. That is a one-constant change on top of this patch and is the version most
likely to *reduce* `acid-scale` rather than raise it. It was not measured here
(each leg is a ~15-minute recompiler rebuild plus a capture) and should be
measured before anyone ships a scale-aware tolerance at all.

The leg is delivered as a **separate patch** (`w2-gfx-morph-legb.patch`) so the
coordinator can take leg A without it.

## 6. The half of the morph defect this patch does NOT fix (fully specified)

Morph shapes carry a **second** index-paired stream: the raw path-command list
used by vector hit testing. `emitPath` buffers the start shape's commands into
`morph_start_buf`; the end shape's go into `morph_end_geo_buf`; and the emitter
(`swf.cpp` ~9516) walks the start buffer and attaches **one** end entry (`cmd 9`)
to each geometric command. `SWFModernRuntime/src/libswf/shape_hit_test.c:493-570`
then lerps each command against its `cmd 9` partner at the placement ratio —
which is exactly Ruffle's record-level model, and correct by construction.

It desynchronises for the same reason the vertex stream did, and this patch does
**not** change it (a start `LineTo` is one entry, its paired end `CurveTo` is
two). Fixing it is the mirror image of §3.3 and needs the same plan that is now
computed:

* when a start straight edge is paired with an end curve, emit the start command
  as `{3, midpoint}` + `{4, anchor}` instead of `{2, anchor}`;
* when a start curve is paired with an end straight edge, emit the end geo as
  `{3, midpoint}` + `{4, anchor}`;
* synthesise / suppress `{5, pen}` for unpaired `StyleChangeRecord`s exactly as
  the vertex stream now does.

**Named beneficiary: `avm1/movieclip_hittest_shapeflag`** — a trace near-pass at
6 diff lines, every one of them a `hitTest(x, y, true)` shape-flag query
returning `false` where `true` is expected, on a SWF whose morph characters 27
and 41 are both desynchronised (§3.2). It is ~40 lines on top of this patch and
should be its own leg so the ledger stays attributable.

`avm2/displayobject_getrect` is **not** a candidate: it aborts at trace line 3 on
`TypeError: Error #2007: Parameter targetCoordinateSpace must be non-null`, an
AVM2 runtime gap that hides every bounds value behind it. Its morph bounds only
start to matter once that is fixed.

## 7. Board corrections

1. **Strike P1 ("Morph curve subdivision, +7 candidates").** Its two named
   beneficiaries have no morph curves at all (§2). The residual rows are a text
   band + a 1-px fill edge (`morph_test1`) and a 1-unit AA tie
   (`cache_as_bitmap/morph`); neither is a geometry lead.
2. **`wave1-gfx-curvejoint.md`'s `corpus_curve_scan.json` has no usable morph
   data.** Its scanner throws on every `DefineMorphShape` tag
   (`skip_morph_fill_styles` undefined) and silently records `morph_n = 0`
   corpus-wide. Any conclusion drawn from those columns is unsupported;
   `corpus_morph_scan.json` replaces them.
3. **Add: "morph edge-record pairing" as a *closed* item** (this patch) and
   **"morph path-command pairing"** as its open half (§6, `+1` trace candidate on
   `avm1/movieclip_hittest_shapeflag`, ~40 lines).
4. `hairline_edge_drift`'s "morph family, 7 rows" sub-cluster in §6.4 should be
   re-labelled: those 7 rows are **text + fill-edge rows that happen to sit in
   SWFs containing a morph shape**, and the morph shape is not what fails in
   them.

## 8. A new false-negative mode for the canary docstring (cost: one whole leg)

`render_canary.py`'s mode 1 is "a `SWFRecomp/` change is inert without a cmake
rebuild AND `--recompile`". This session hit a **twelfth** mode that survives
doing both:

> **A long parallel build that is still running when you edit a source file will
> finish writing that file's `.o` with an mtime NEWER than your edit.** `make`
> then reports `[100%] Built target SWFRecomp` and links the **stale** object.
> Every downstream capture is a second copy of the baseline, and it looks
> exactly like "my change is inert".

`swf.cpp` is a 15-minute compile on a contended machine; the baseline `make`
read it at 13:58, the edits landed at 14:10, the `.o` was written at 14:13, and
the leg-A `make` at 14:36 did nothing. The first capture taken "after" the change
was byte-identical everywhere.

**Cheap check, worth making standard:** after rebuilding for a recompiler A/B,
confirm the object actually contains the change —

```bash
nm -C SWFRecomp/build/CMakeFiles/SWFRecomp.dir/src/swf.cpp.o | grep <yourNewSymbol>
```

— or `touch` the edited source before `make`. An `ls -la` of the binary is not
enough: the link timestamp is fine, it is the object that is stale.

## 9. CI fidelity of this ledger

Every absolute number below was reproduced locally at baseline and matches the
CI record in `origin/ruffle-image-results` @ `ff5502cb8` exactly:

| comparison | CI board | local baseline |
|---|---|---|
| `morph_test1 frame1 … frame6` | 212 / 789 / 789 / 789 / 789 / 589 outliers | **identical** |
| `acid/acid-morph [output]` | 4 308 outliers / 2 600 budget, max 255 | **identical** |
| `cache_as_bitmap/morph [output]` | 2 832 outliers, max 1 | **identical** |
| `invalidClipDepth [output]` | pass (tolerance 0) | **identical** |

So local grading of the morph family is CI-grade, per the standing requirement.

## 10. Files edited

| file | what |
|---|---|
| `SWFRecomp/src/swf.cpp` | leg A: `MorphEdgeRec` + `scanMorphEdgeStream` + `morphChordCount` (new, above `interpretShape`); capture of the morph `Offset` field; the edge-pairing pre-pass and merge; `pushStraightEdge` / `pushEndStraight` (both straight-edge arms refactored, bit-identical at `n = 1`); the morph arm of `num_passes`; the end-loop chord count, pre-synth, MoveTo suppression, tail synth and the pairing assertion. Leg B: `computeStaticPlacementScales` (new, next to `parseMatrix`), its call at the top of `parseAllTags`, and the scale-divided tolerance in the plain-shape arm. |
| `SWFRecomp/include/swf.hpp` | leg B: `static_placement_scale` map + the method declaration |

No runtime (`SWFModernRuntime/`) change; no renderer change; the `(s32)`
truncating cast and the global 1-twip tolerance constant are untouched, as
instructed.

## 11. Artefacts

`…/scratchpad/gfx-morph/` — `morphscan.py`, `corpus_morph_scan.py|.json`,
`merge_sim.py|.txt`, `legb_model.py|.json`, `probe_recomp.sh`,
`probe_diff.py`, `probe_morph_test1.py`, `ledger.py`, the capture labels under
`canary/`, and `apply_legb.py` (the leg-B application script, kept because it
documents the exact anchors).

## 12. Merge notes

* **`w2-gfx-morph.patch` (leg A)** — one file, `SWFRecomp/src/swf.cpp`. Invalidates
  every `Recompiled*` cache corpus-wide (it changes shape emission), so it needs a
  full recompile in CI like s13's curve patch did, even though its measured pixel
  and trace delta is zero. It does not stack-conflict with anything outside
  `interpretShape`. Merge it for the correctness (no morph in the corpus is
  index-desynchronised any more, and the pre-pass asserts it), not for a number.
* **`w2-gfx-morph-legb.patch` (leg B)** — applies **on top of** leg A; touches
  `swf.cpp` + `swf.hpp`. **Recommendation: hold.** Re-measure at 2 twips/scale
  first (§5.3). If it is taken as-is, the ledger above is the complete list of
  what moves and nothing changes status.
* Both were graded with the recompiler rebuilt **and verified non-stale**
  (§8) — the first attempt at leg A was not, and cost a full capture cycle.

## 13. Trace-axis due diligence

* Leg A's blast radius is exactly the 20 SWFs in the corpus with a
  `DefineMorphShape`; **all 19 graded ones were run** (trace + images) and none
  moved. The 20th is `_swfbridge/livetest/n_loader/native_run`, a demo, not a
  graded test.
* Leg B's blast radius was computed exactly (scale floored at 1.0 ⇒ anything
  never scaled up is bit-identical): 9 tests corpus-wide, all 9 run.
* **The `regression` suite is untouched by both legs**: its only morph test
  (`regression/avm2_morph`) is byte-identical under leg A, and a scan of all
  **71** regression SWFs finds **zero** whose chord counts change under leg B
  (`legb_regression_scan.py`). `regression/mask_sibling_union` was additionally
  run in both legs and is byte-identical.
* `from_shumway/acid/acid-morph` (the trace near-pass at gap 2 the brief asked
  about) is **unmoved**: its 2 diff lines are lines 3 and 4 of a 6-line
  `true/false` trace, and they do not depend on morph flattening — the render is
  byte-identical under leg A, so nothing the recompiler emits for that shape
  reached either the pixels or the trace.

**Working-tree state:** the worktree has **both** legs applied (that is the state
leg B was graded in). `w2-gfx-morph.patch` is leg A against `0a99be1a9`;
`w2-gfx-morph-legb.patch` is the leg-B increment on top of it. Nothing is
committed, nothing was stashed, and no file outside `SWFRecomp/` and `wave2/`
was touched.
