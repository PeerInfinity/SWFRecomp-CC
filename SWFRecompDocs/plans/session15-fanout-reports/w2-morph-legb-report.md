# w2-morph-legb — morph path-command pairing, leg B at 2 twips, and a live OOB read

Session 15, wave 2 (implementation). Brief: the two already-scoped items from
`session14-fanout-reports/w2-gfx-morph-report.md` — §6 ("the half of the morph
defect this patch does NOT fix") and §5.3 ("re-measure the scale-aware tolerance
at 2 twips") — plus the coordinator's mid-session rider from
`session15-fanout-reports/wave1-gfx-blur-morphratio.md` §3.4 cause 2 (an
out-of-bounds static-array read in the AVM2 morph tables).

Worktree `agent-a84b624a7e0ebb766`, baseline `42a324cef`, **nothing committed**.

## 0. Verdicts

| patch | item | verdict |
|---|---|---|
| `w2-morph-pairing.patch` | A — morph path-command pairing | **MERGE for correctness. +0 trace, +0 pixels, 0 regressions.** Its briefed flip is REFUTED (§2). |
| `w2-morph-legb2.patch` | B — scale-aware tolerance at 2 twips/scale | **NO-GO, and the s14 mechanism is REFUTED** (§4). `acid-scale` 302 → **344**, i.e. worse than baseline *and* worse than s14's 1-twip leg (342). |
| `w2-morph-oob.patch` | rider — AVM2/AVM1 `morph_end_offset` OOB read | **HOLD as written** (§5). The OOB is real, bigger than diagnosed, and the fix is confirmed; but freezing strokes at their start position costs `morph_test1` 5 image bands (789 → up to 2767, all fail→fail). The correct completion is specified in §5.5. |

All three patches are independent and stack in any order: applying
`w2-morph-oob` + `w2-morph-pairing` + `w2-morph-legb2` to a clean `42a324cef`
reproduces this worktree's `git diff` **byte-for-byte** (verified).

**Scoreboard movement: 0 trace flips, 0 pixel flips, 0 status regressions on
either axis, from any of the three.**

---

## 1. Headline

1. **Item A's brief prices a flip that is structurally impossible.** Two
   independent reasons, either one sufficient (§2).
2. **Item A is still a real fix and works** — the new assertion is silent across
   all 10 morph-bearing SWFs and the end stream now closes its own loop (§3).
3. **Leg B's re-parameterisation refutes s14 §5.3's mechanism.** "We are twice as
   accurate as lyon, so converge on it" predicts `acid-scale` improves at 2 twips.
   It gets *worse*. The real mechanism is that a `tolerance = 0` /
   `max_outliers = 0` comparison is not a *magnitude* row at all: any change to
   the chord count re-rolls which pixels miss, and Ruffle's lyon chords are at
   different parameters regardless of tolerance (§4.3).
4. **The rider's OOB is larger than wave-1 found and is not AVM2-only.** The same
   table is read by the **AVM1** renderer, and `from_gnash/misc-ming.all/morph_test1`
   declares `vert_count = 90` against a `morph_end_shape_data[6][2]` — an
   **84-entry** out-of-bounds read on every rendered frame (§5.2). Root cause
   located: the **stroke** emission loop (§5.1).

---

## 2. Item A — attacking the brief's premise first

The brief: "**Named beneficiary: `avm1/movieclip_hittest_shapeflag`** — a trace
near-pass at 6 diff lines, every one of them a `hitTest(x, y, true)` shape-flag
query, on a SWF whose morph characters 27 and 41 are both desynchronised … ~40
lines on top of this patch." Both halves of that inference fail.

### 2.1 Five of the six diff lines are not in a morph section

`output.txt`'s section banners: `// layers` at 65, `// text + dynamic text` at
155, `// morph shape` at 187, `// morph complex shape` at 290.

| diff line | section | expected → ours |
|---:|---|---|
| 71 | **layers** | `true` → `false` |
| 171, 173, 175, 177 | **text + dynamic text** | `true` → `false` (×4) |
| 296 | **morph complex shape** | `false` → `true` |

The morph ceiling on this test is **1 of 6 lines**, so a flip was arithmetically
impossible before any measurement.

The four text failures are one contiguous band — `hitTest(390,430)`,
`(290,450)`, `(190,480)`, `(650,430)`, all `y ∈ [430,480]` — while the same
section's `y ≈ 120`, `y ≈ 320` and `y ≈ 630` queries all pass. That is **one text
object's shape not being hit-testable**, not four defects.

### 2.2 Both morph sections hit-test at ratio 0

```
frame_8:            actionQueueScript(script_10)                   // "// morph shape"
                    tagPlaceObject2Ratio(app_context, 1, 29, 67, 0, 0, 8, 0)
sprite_29_frame_0:  tagPlaceObject2(app_context, 1, 27, 65, 0, 0, 0)     <-- no ratio

frame_12:           actionQueueScript(script_16)                   // "// morph complex shape"
                    tagPlaceObject2Ratio(app_context, 1, 43, 89, 0, 0, 12, 0)
sprite_43_frame_0:  tagPlaceObject2(app_context, 1, 41, 87, 0, 0, 0)     <-- no ratio
```

`tagPlaceObject2` sets `display_list[depth].ratio = 0`
(`SWFModernRuntime/src/libswf/tag.c:9095`); the ratio-bearing placements are in
the sprites' *later* frames, and
`grep -c "actionGoto\|actionNextFrame\|actionSetProperty"` over `script_10.c`
and `script_16.c` returns **0 / 0**, so neither sprite advances before the
queries run. `ng_hitTestMorphPath` therefore evaluates at `t = ratio/65535 = 0`
and **every `{9, …}` end entry is multiplied by zero.**

Item A rewrites only the end stream and its pairing. **Its named beneficiary
cannot see it.** Confirmed empirically: the diff is byte-identical, all six
lines, at a verified-non-stale build.

**Board correction.** Replace "morph path-command pairing: +1 trace candidate on
`avm1/movieclip_hittest_shapeflag`" with:
*"`movieclip_hittest_shapeflag`: 4 of 6 diff lines are one dynamic-text object's
shape hit test (`y ∈ [430,480]`), 1 is a `layers` query, 1 is a morph query
**evaluated at ratio 0**. No morph work can move this test."*

---

## 3. Item A — what it does, and the evidence it works

### 3.1 Mechanism

A morph carries **two** index-paired streams. s14 fixed the flattened-vertex
one. The second is the raw path-command list used by vector hit testing:
`emitPath` buffers the start shape's commands, the end shape's go into
`morph_end_geo_buf`, and the emitter attaches **one** end entry (`cmd 9`) per
geometric start command (`{5}` MoveTo, `{2}` LineTo, `{3}` control, `{4}` anchor).

It desynchronises for the same two reasons the vertex stream did:

* a start `LineTo` is **1** entry, its paired end `CurveTo` is **2**;
* `StyleChangeRecord`s need not pair — and the start side writes its `{5}` under
  a **stricter** condition than its vertex (a pure line-style change starts a
  `Path` but emits no path command), so the vertex plan's predicate cannot be
  reused. The patch computes a second one, `MorphEdgeRec::emits_path`.

The fix reuses s14's already-computed pairing and adds four parallel plan
arrays: promote a start straight edge paired with an end curve to
`{3, midpoint} + {4, anchor}`; promote the end straight edge in the mirror case;
synthesise one stand-in end entry per unpaired start command; suppress an
end-only `MoveTo`'s `{5}`. A quadratic whose control point is the segment
midpoint **is** the segment, so the promotion is geometry-preserving at ratio 0
and is exactly Ruffle's `lerp_edges` straight→curve promotion at ratio 1.
Plus a diagnostic mirroring s14's vertex assertion.

### 3.2 It demonstrably works

`avm1/movieclip_hittest_shapeflag`, char 27 (`ng_record_morph_path(27, …)`):

| | baseline | item A |
|---|---:|---:|
| path entries | 45 | 61 |
| straight edges written as `{2}` | 8 | 4 promoted to `{3,mid}+{4,anchor}` |
| end partners of the 2nd sub-path | restart mid-polygon at `(2255,4343)` | identical to the 1st sub-path, closing its own loop `(-4369,1745) … (-4369,1749)` |

The promoted controls are verifiable midpoints: start `LINETO(2875,1580)` from
pen `(2875,-2872)` becomes `CTRL(2875,-646) ANCH(2875,1580)`, and
`-646 = (-2872 + 1580)/2`. Char 41: 2844 → 2848 entries, with the end partners
shifting by one index from the first straight↔curve pair onward.

**Pairing assertion: 0 warnings across all 10 morph-bearing SWFs**
(`movieclip_hittest_shapeflag`, `avm1/click_block`, `avm2/morph_shape`,
`acid-morph`, `timeline/nav/morphShape`, `hittest_morph_input`,
`invalidClipDepth`, `displayobject_getrect`, `cache_as_bitmap/morph`,
`morph_test1`), i.e. every start geometric command now has exactly one end
partner corpus-wide.

### 3.3 Pixels: structurally unreachable, not merely unmoved

`path_data`, `ng_record_morph_path` and `ng_find_morph_path` are referenced by
**exactly one** translation unit in the runtime,
`SWFModernRuntime/src/libswf/shape_hit_test.c` (plus `extern` declarations in
`tag_stubs.c` and the storage in `ng_shared.c`). The renderer never reads them,
so item A cannot move a pixel by construction — a stronger statement than an
md5 canary over a finite set. The canary was run anyway and agrees (§7.1).

---

## 4. Item B — the scale-aware tolerance at 2 twips: NO-GO, mechanism refuted

### 4.1 What "2 twips" had to mean

s14 §5.3: "set the scale-aware tolerance to 2 twips / scale … instead of 1".
Read literally that is `tol = 2/scale` **including at scale 1**, which doubles
the tolerance for every unscaled curve in the corpus and coarsens hundreds of
currently-passing renders — a blast radius s14 never priced, and which destroys
the very property that made leg B measurable ("scales are floored at 1.0, so
every other test in the corpus is bit-identical by construction").

`w2-morph-legb2.patch` therefore implements

```
tol_twips = min(1, 2 / max_static_scale[char_id])
```

— the cap stays at the historical 1 twip and the divisor only engages past
**2×**. Every character never composed past 2× stays bit-identical to baseline
by construction, and scaled characters land at **0.1 px of screen-space
residual**, which is Ruffle's lyon tolerance exactly — the mechanism s14 named.

### 4.2 Measurement (CI-grade; every "before" reproduces the CI board exactly)

| comparison | scale | base | leg B2 | Δ | status |
|---|---:|---:|---:|---:|---|
| **`from_shumway/acid/acid-scale [output]`** | 7.27 | **302** / 0 | **344** | **+42** | fail → fail |
| `visual/simple_shapes/strokes/scale [output]` | 20.0 | 66 243 / 0 | 65 868 | −375 | fail → fail |
| `from_shumway/acid/acid-mask [output.01]` | 7.54 | 12 096 / 16 | 12 068 | −28 | fail → fail |
| `from_shumway/acid/acid-mask [output.05]` | 7.54 | 10 937 / 16 | 10 919 | −18 | fail → fail |
| `from_shumway/acid/acid-mask [output.10]` | 7.54 | 9 474 / 16 | 9 471 | −3 | fail → fail |
| `from_shumway/acid [output.01 … output.16]` (16 **passing**) | 2.88 | 8 659 – 12 347 | **byte-identical** | 0 | pass → pass |
| `visual/cache_as_bitmap/scroll_rect_scaled [output]` | 2.00 | — | **byte-identical** | 0 | pass → pass |
| tripwire `from_shumway/acid/acid-blend-2 [output.10/15/20/26/40]` | — | 0/0/0/1/0 | **byte-identical** ✔ | 0 | unchanged |

Baseline fidelity check against `origin/ruffle-image-results @ 01e9f2321`:
`acid-mask` 12 096 / 10 937 / 9 474, `acid-scale` 302, `strokes/scale` 66 243,
`acid-blend-2 output.26` 1 outlier / max 127, `acid` 8 659–12 347 — **all
reproduce exactly**, so this ledger is CI-grade.

**0 status changes, 0 flips, 0 regressions.**

Two blast-radius predictions made before the run and confirmed: `scroll_rect_scaled`
(scale exactly 2.00, so the `> 2.0` guard never fires) and
`acid-bitmap-draw_quality_{high,low}` (scale 1.03) are bit-identical under B2 —
both of which *did* move under s14's 1-twip leg. B2's changed set is strictly
smaller than B1's.

### 4.3 Verdict: NO-GO, and s14 §5.3's mechanism is refuted

s14 explained `acid-scale` 302 → 342 as "our residual **crosses over** Ruffle's
own ~0.1 px error; being more accurate than the reference costs outliers", and
predicted that 2 twips/scale "is the version most likely to *reduce* `acid-scale`".
Measured at a residual of ≈0.092 px — i.e. sitting just *under* lyon's 0.1 px
rather than at half of it — `acid-scale` goes to **344**, worse than baseline and
worse than the 1-twip leg.

The crossing-over model is therefore wrong. What `acid-scale` actually is:
`tolerance = 0`, `max_outliers = 0` — an **exact-match** comparison. Ruffle's
lyon emits chords at *its own* parameter values from a different subdivision
algorithm; matching its error *magnitude* does not put a single vertex in the
same place. Changing our chord count merely re-rolls which pixels miss, and the
outlier count is a near-arbitrary function of it (302 at N₁, 342 at N₂, 344 at
N₃). **No tolerance setting reaches this row; only reproducing lyon's
subdivision would.**

Everything else the leg does is a sub-1 % band move on rows thousands of
outliers from their thresholds.

**Recommendation: do not merge, and strike the scale-aware-tolerance row from
the board.** It has now been measured at two parameterisations, with the flip
candidate moving the wrong way both times, and the mechanism that motivated it
has been falsified. If anyone revisits flattening for `acid-scale`, the task is
"port lyon's subdivision", not "tune a constant".

---

## 5. Rider — the `morph_end_offset` out-of-bounds read

### 5.1 Root cause (this is the part wave-1 did not have)

`morph_end_shape_data` is indexed **by the `shape_data` index**: both the AVM2
walk (`Avm2ShapeGeom.morph_end_offset + k`) and the AVM1 renderer
(`tag.c:6929-6938`, `end[v*2]` for `v ∈ [0, morph_start_size)`) read entry *k* of
that character's start-vertex run, so the two arrays must be appended in
lockstep. `interpretShape` appends to `shape_data` from **three** sites, and only
one of them appends to `morph_end_shape_data`:

| site | appends `shape_data` | appends `morph_end_shape_data` |
|---|---|---|
| earcut fill loop (`swf.cpp` ~9753) — the morph path | yes | **yes** |
| libtess2 fill loop (~9967) — plain shapes / glyphs only | yes | n/a |
| **stroke loop (`drawLines`, ~10004) — runs for morphs too** | yes | **no** ← the bug |

A morph character with a stroke run therefore contributes *N* start vertices and
*0* end vertices, and everything downstream shifts.

### 5.2 It is bigger than diagnosed, and it is not AVM2-only

Wave-1 found the AVM2 case. Verified at baseline:

```
acid-morph, RecompiledABC/abc_timeline.c        float morph_end_shape_data[294][2]
{ 1, 1,   0, 276,   0, 1 }   morph, fill   -> 276 end verts
{ 2, 1, 276, 270,   0, 0 }   plain
{ 4, 1, 546,  36, 276, 1 }   morph, STROKE ->   0 end verts   <-- offset never advances
{ 5, 1, 582,  18, 276, 1 }   morph, fill   ->  18 end verts   <-- inherits char 4's offset
```
char 4 reads `[276, 312)` — 18 entries past the end, from char 5's data.

**The AVM1 side is worse.** `from_gnash/misc-ming.all/morph_test1`:

```
tagDefineMorphShape(app_context, 4, 15291, 90, 0, 97, 1, ...)   <-- vert_count = 90
float morph_end_shape_data[6][2]                                 <-- SIX entries
```

`tag.c:6929` walks `v ∈ [0, 90)` reading `end[v*2 + 0/1]`, so **84 vertices per
frame are lerped against out-of-bounds static memory** on every rendered frame of
an AVM1 morph that has a stroke. (The 6 valid entries are the fill's two
triangles; the other 84 are the stroke's.)

### 5.3 The fix, and that it works

Mirror the fill arm inside the stroke loop: for `is_morph`, append one
`morph_end_shape_data` entry per emitted stroke vertex and advance
`current_morph_end_vertex`; `drawLines`/`drawLineJoin`/`drawLineCap` synthesise
corner vertices and carry no `morph_index` (it default-initialises to `-1`,
`swf.hpp:46`), so a stroke vertex takes **its own start position** as its end
position — the same fallback the fill arm already uses. Plus the recompiler-side
lockstep assertion wave-1 asked for.

Confirmed in the generated code, exactly as predicted:

| | before | after |
|---|---|---|
| `acid-morph` geom | `{4,…,276,1}` `{5,…,276,1}`, array **294** | `{4,…,276,1}` `{5,…,**312**,1}`, array **330** |
| `morph_test1` | `vert_count 90`, array **6** | `vert_count 90`, array **90** |
| lockstep assertion | — | **silent on every morph SWF** |

### 5.4 …and it costs pixels, because freezing a stroke is the wrong direction

| comparison | base | rider | status |
|---|---:|---:|---|
| `morph_test1 [frame1]` (ratio 0) | 212 | **byte-identical** | fail → fail |
| `morph_test1 [frame2]` | 789 | 1 516 | fail → fail |
| `morph_test1 [frame3]` | 789 | 1 877 | fail → fail |
| `morph_test1 [frame4]` | 789 | 2 241 | fail → fail |
| `morph_test1 [frame5]` | 789 | 2 603 | fail → fail |
| `morph_test1 [frame6]` | 589 | 2 767 | fail → fail |
| `acid-morph [output]` | 4 308 / 2 600 | **byte-identical** | fail → fail |
| `visual/cache_as_bitmap/morph [output]` | 2 832, max 1 | **byte-identical** | fail → fail |
| tripwire `from_shumway/invalidClipDepth [output]` | pass, tol 0 | **byte-identical** ✔ | pass |
| `regression/avm2_morph [output]` | — | **byte-identical** | — |
| trace, all 13 morph tests | — | **unchanged** | — |

The `morph_test1` damage is monotonic in the placement ratio (frame1 ratio 0
identical; 1 516 → 2 767 across frames 2–6), which is the exact signature of
**"the fill morphs while the stroke stays frozen at ratio 0"** — the outline
detaches from the shape it outlines. Ruffle (which produced the goldens) morphs
the stroke, so moving away from it is a real regression in fidelity even though
no status changes. `acid-morph` is unmoved, confirming wave-1 §3.4 cause 1 (its
stroke morph is a non-solid fill and is not drawn today at all), and
`cache_as_bitmap/morph`'s char has no stroke (`vert_count 6`, array 6 — already
balanced).

### 5.5 The completion, fully specified (~15–20 lines, one build)

Do not freeze the stroke — **translate it**. Every generated stroke vertex is a
fixed offset from a *source path vertex* that does carry a `morph_index`:

1. `drawLines`, `drawLineJoin`, `drawLineCap` already receive the source
   `Vertex`es (`last_v`, `v`, `a/b/c`). Copy the source's `morph_index` into each
   `Tri` vertex they synthesise (all three helpers construct vertices, so all
   three need the one-liner).
2. Build a `morph_start_positions` vector alongside `morph_end_positions`
   (index = `morph_index` → start `Vertex`); it is a single walk over `paths`.
3. In the stroke emission arm, when `t.verts[j].morph_index >= 0`, write
   `end = t.verts[j] + (morph_end_positions[mi] - morph_start_positions[mi])`
   instead of `t.verts[j]`.

That makes the stroke ride the morphing outline (exact for a uniform-width
stroke; the residual is only the start/end *width* difference, which the AVM1
path does not interpolate today either). **Prediction to test: `morph_test1`
frames 2–6 return to ≤ their baseline 789/589 and `frame1` stays identical.**

**Recommendation: HOLD `w2-morph-oob.patch` for that completion.** The OOB is
real, is UB, and should not survive the session — but merging the freeze
variant trades one defect for a visible one on an already-failing test. If the
coordinator judges memory safety to outweigh a band regression on five
already-failing comparisons with **zero status changes**, the patch as delivered
is safe to merge and the completion becomes a follow-up rather than a
prerequisite.

---

## 6. Build hygiene (s14 §8's twelfth false-negative mode)

Every leg used `touch swf.cpp && make -j4` and was checked for a stale object
*before any verdict was read*:

| leg | `swf.cpp` | `swf.cpp.o` | binary |
|---|---|---|---|
| item A | 12:35 | 12:37 | 12:37 |
| baseline (revert) | 12:49 | 12:53 | 12:53 |
| all three | 13:10 | **13:13** | 13:13 |

and each leg's effect was independently confirmed *in the generated code* before
grading (path entry counts + midpoint controls for item A; the `Avm2ShapeGeom`
table and array length for the rider; the chord-count-driven md5 movement for
leg B).

**A thirteenth mode, hit and avoided this session:** `afterrun.sh` chains
`build.sh` then the captures, so a test run launched *in parallel* with that
script races the link step. A trace batch started 3 minutes into the build ran
against the **previous** binary; caught by `ls -la` on `swf.cpp.o` vs
`swf.cpp` (object 12:53 < source 13:10) and re-run after `Built target`. The
`nm`-the-object check from s14 §8 does not catch this one — there is no new
symbol — but the object-vs-source mtime comparison does. Recommend adding to
the canary docstring: *never launch a measurement concurrently with the build
it is supposed to measure; compare `.o` mtime to source mtime, not the binary's
link time.*

---

## 7. Ledger

### 7.1 Render canary — md5 A/B, `base` → `after` (all three patches)

The canary was reduced from the standing 22-test list to 13 (the list is in
`…/scratchpad/w2morphlegb/setS.txt`) because the machine ran at load 15–21 on 8
cores all session and three full captures were not affordable; the reduction
keeps every canary **family** either patch can reach (tol-0 repo goldens,
tessellation, masks, gradients, morph) and adds leg B's entire signal-carrying
changed set. Three captures were taken at each leg: `setS` (34 comparisons),
`morph` (3), `gnash` (6).

| capture | comparisons | byte-identical md5 | moved |
|---|---:|---:|---:|
| setS | 34 | **29** | 5 (all leg B, §4.2) |
| morph | 3 | **3** | 0 |
| gnash (`morph_test1`) | 6 | 1 | 5 (all rider, §5.4) |

Byte-identical across all three legs: `regression/avm2_morph`,
`regression/mask_sibling_union`, `regression/mask_nested_intersect`,
`visual/simple_shapes/winding_rule`, `avm1/color`, `avm1/mask_with_drawing`,
`from_shumway/acid/acid-gradient-0`, `acid-blend-2 [×5, the standing tripwire]`,
`acid [×16, all passing]`, `scroll_rect_scaled`, `acid-morph`,
`cache_as_bitmap/morph`, `invalidClipDepth [tol 0]`, `morph_test1 [frame1]`.

Attribution is unambiguous even though the legs were captured together: item A
cannot reach pixels at all (§3.3), leg B's code is in the **non-morph** arm of
`if (is_morph)` and only engages past scale 2, and the rider's code is in the
morph arm of the stroke loop. Every mover is a scaled non-morph shape (leg B) or
a stroked morph (rider); the two sets do not intersect.

### 7.2 Trace — 13 tests, every graded morph SWF in the corpus

Baseline → item A → all three, each with `--recompile` on a verified-non-stale
binary. **Every test kept its status at every leg:**

| test | all legs |
|---|---|
| `avm1/movieclip_hittest_shapeflag` | output_mismatch — **the same 6 lines, byte-identical** |
| `avm2/bounds_mode` | output_mismatch |
| `avm2/displayobject_getrect` | output_mismatch |
| `from_shumway/acid/acid-morph` | output_mismatch |
| `avm1/click_block`, `avm1/hittest_morph_input`, `avm2/click_block`, `avm2/morph_shape`, `from_gnash/misc-ming.all/morph_test1`, `from_shumway/invalidClipDepth`, `from_shumway/timeline/nav/morphShape`, `visual/cache_as_bitmap/morph`, `regression/avm2_morph` | pass |

**+0 trace, 0 regressions**, reproducing s14 leg A's disposition exactly.

---

## 8. Board corrections

1. **Strike "morph path-command pairing: +1 trace candidate on
   `avm1/movieclip_hittest_shapeflag` (~40 lines)".** The test's morph queries
   run at ratio 0 and 5 of its 6 diff lines are not morph queries at all (§2).
   Replace with the text-field row in §2.1.
2. **Strike the scale-aware flattening tolerance row entirely.** Measured at
   1 twip/scale (s14: `acid-scale` 302 → 342) and at 2 twips/scale (this
   session: 302 → **344**). The "we overshoot lyon's accuracy" mechanism is
   falsified; `acid-scale` is an exact-match row that only a port of lyon's
   subdivision can reach (§4.3).
3. **Add: "AVM1 morph stroke does not morph"** — new, and the reason the rider
   is on hold. `morph_end_shape_data` has no entries for stroke vertices at all
   today (they read out of bounds); §5.5 specifies the ~15–20-line fix, and
   `morph_test1`'s 5 failing comparisons (789/789/789/789/589, tol 5,
   `max_outliers` 0) are its named beneficiaries.
4. **`visual/cache_as_bitmap/scroll_rect_scaled` is no longer a leg-B changed-set
   member** and no longer appears in the CI failure index — s14's table lists it
   as a 41 846-outlier failure; it now passes. Any leg reusing s14 §5.1's table
   should re-derive it.
5. Wave-1's `morph_end_offset` finding is **confirmed and upgraded**: it is not
   AVM2-only, and its worst instance in the corpus is an 84-entry AVM1 read
   (§5.2).

---

## 9. Files edited

| file | patch | what |
|---|---|---|
| `SWFRecomp/src/swf.cpp` | `w2-morph-pairing` | `MorphEdgeRec::emits_path` + its two scanner arms; four path-plan arrays and their merge-loop population; the promotion in `pushStraightEdge` / `pushEndStraight`; end-side path pre-synth, MoveTo gate and tail synth; the path-pairing assertion. (+200 lines, all inside `interpretShape`'s morph arm.) |
| `SWFRecomp/src/swf.cpp` | `w2-morph-oob` | morph end-vertex emission inside the stroke loop + the start/end lockstep assertion. (+65 lines.) |
| `SWFRecomp/src/swf.cpp`, `SWFRecomp/include/swf.hpp` | `w2-morph-legb2` | s14's archived `computeStaticPlacementScales` verbatim, with the tolerance hunk re-parameterised to `min(1, 2/scale)`. |

No runtime (`SWFModernRuntime/`) change, no renderer change, and no textual
overlap with `w2-gfx-flatten` (`swf.cpp` ~:8653, the plain-shape `num_passes`
arm) or `w2-gfx-smalls` (`swf.cpp`:1854) — leg B2's only shared region is the
plain-shape tolerance constant, which is the same hunk `w2-gfx-flatten` edits;
if both land, that hunk needs a manual merge (and leg B2 is a NO-GO anyway).

## 10. Artefacts

`…/scratchpad/w2morphlegb/` — `setS.txt` (reduced canary list), `outliers.py`
(CI-grade absolute grading of any capture against the repo goldens), `ab.py`
(md5 + outlier A/B of two captures), `mklegb2.py` (re-parameterises the archived
s14 patch), `base_ledger.txt` / `after_ledger.txt`, `pathdump.py` +
`base_char27.txt` / `base_char41.txt` / `legA_char41.txt` (the morph path stream
before/after), `recompwarn.sh` (assertion sweep), the build logs, and the
capture logs. Captures live in the worktree at `.render_canary/{base,after,
base_morph,after_morph,base_gnash,after_gnash}`.

**Working-tree state:** all three patches applied (that is the state the ledger
was graded in). Nothing committed, nothing stashed, no file outside
`SWFRecomp/` and `SWFRecompDocs/plans/session15-fanout-reports/` touched.
