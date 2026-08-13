# w2-morph-oob — completing the held morph-stroke OOB fix

Session 15, wave 2 (implementation). Brief: complete the HELD
`w2-morph-oob.patch` per `w2-morph-legb-report.md` §5.5 — propagate the source
vertex's `morph_index` through `drawLines`/`drawLineJoin`/`drawLineCap` and
translate stroke end-vertices by the morph delta — and verify the falsifiable
prediction that `morph_test1`'s bands return to ≤ their baseline.

Worktree `agent-a49a25a4e347aebb5`, rebased onto **`3747a7fb7`** (current master
after the `w2-gfx-blur` / `w2-gfx-smalls` / `wave1-gfx-displace-blend` landings),
**nothing committed**. Deliverable patch:
`SWFRecompDocs/plans/session15-fanout-reports/w2-morph-oob-complete.patch`
(`SWFRecomp/src/swf.cpp` only, +190/−28, `git apply --check` clean on `3747a7fb7`).

## 0. Verdict

**GO — merge `w2-morph-oob-complete.patch`.**

| axis | result |
|---|---|
| `morph_test1` bands (5 failing comparisons) | **789 / 789 / 789 / 789 / 589 → 189 / 189 / 189 / 189 / 189** (−76 % / −68 %) |
| every other comparison in the canary | **byte-identical md5** (14/19), 0 status changes |
| trace, 15 morph-bearing tests | **every test keeps its baseline status** |
| lockstep assertion | **silent on all 15 morph SWFs** |
| the OOB itself | **gone** (`morph_test1` array 6 → 90 for `vert_count 90`; `acid-morph` 294 → 330, chars 4/5 at offsets 276/312) |

The prediction in §5.5 **held, but only after one further step that §5.5 did not
anticipate** (§3). The §5.5 completion alone lands the bands at **987** — better
than the frozen-stroke variant's 1 516…2 767, still *worse* than baseline 789.
The measurement that separates the two is in §2.3 and is the most useful thing
in this report.

---

## 1. What shipped

Three changes, all in `SWFRecomp/src/swf.cpp`, all inside the morph/stroke
emission region (no textual overlap with `w2-gfx-flatten` ~:8653 or
`w2-gfx-smalls` :1854 — verified by rebasing onto master *after* both landed and
re-measuring from scratch).

### 1.1 The original OOB fix (adapted from `w2-morph-oob.patch`)

`morph_end_shape_data` is indexed **by the `shape_data` index** — both the AVM2
walk (`Avm2ShapeGeom.morph_end_offset + k`) and the AVM1 renderer
(`tag.c:6941-6956`, `end[v*2]` for `v ∈ [0, morph_start_size)`) — so the two
arrays must be appended in lockstep. The stroke emission loop appended to
`shape_data` only. Now it appends one `morph_end_shape_data` entry per emitted
stroke vertex, plus a recompiler-side lockstep assertion.

### 1.2 §5.5's completion — stroke vertices ride the morph

* `drawLines`, `drawLineJoin`, `drawLineCap` copy the **source** path vertex's
  `morph_index` into every corner vertex they synthesise (`last_v`/`v` in the
  quad loop, `b` for a join fan, `a` for a cap fan). `Tri::verts[0]` already
  carried it in the two fan helpers because they assign the whole `Vertex`;
  the invented offset corners did not.
* A `morph_start_positions` table (index = `morph_index` → start `Vertex`) is
  built by one walk over `paths` just before the stroke loop — the inverse map
  of `morph_end_positions`.
* The stroke emission arm writes
  `end = stroke_corner + (morph_end_positions[mi] - morph_start_positions[mi])`
  rather than the absolute end position (a stroke corner is *not* a path vertex,
  so it has no absolute end position of its own). A corner with no usable source
  vertex falls back to freezing at its start position.

### 1.3 The step §5.5 did not anticipate — the morph **colour** table

`parseMorphLineStyles` parsed each line style's `EndColor` and threw it away
(`cur_pos += 4`, three sites). The runtime morph lerp walks
`color_data[morph_color_start + c]` against `morph_end_color_data[c]`
(`tag.c:6962-6971`, AVM2 twin at `:3193-3202`), i.e. the **colour** tables have
exactly the same lockstep contract as the vertex tables — and a morph line style
appended to `color_data` only. The stroke colour therefore froze at the start
colour, and any paired colour appended after a line-style array was shifted.

Fixed the same way: read the end colour in all three arms, append it to
`morph_end_color_data`, bump `current_morph_end_color`. A non-solid /
unparseable end fill degrades to "end = start", which preserves lockstep.
`RGBA.parseFields` consumes exactly the 4 bytes the old `cur_pos += 4` skipped,
so the parse cursor is byte-identical.

Confirmed in the generated code: `morph_test1`'s `morph_end_color_data`
`[1][4] → [2][4]` and `tagDefineMorphShape(..., morph_color_count)` `1 → 2`;
`acid-morph` `[2][4] → [3][4]`.

---

## 2. Prediction verdict — the three-way measurement

All numbers are absolute outlier counts against the repo goldens, graded with
`verify_output.compare_images` (so they are definitionally CI's numbers). The
baseline column reproduces the CI board and `w2-morph-legb-report.md` §5.4
exactly, which makes this ledger CI-grade.

| `morph_test1` | baseline | §5.4 freeze variant | §5.5 completion | **+ colour (shipped)** |
|---|---:|---:|---:|---:|
| `frame1` (ratio 0) | 212 | 212 | 212 | **212** |
| `frame2` | 789 | 1 516 | 987 | **189** |
| `frame3` | 789 | 1 877 | 987 | **189** |
| `frame4` | 789 | 2 241 | 987 | **189** |
| `frame5` | 789 | 2 603 | 987 | **189** |
| `frame6` | 589 | 2 767 | 987 | **189** |

*(tol 5, `max_outliers` 0, fail → fail throughout — no status change on any leg.)*

### 2.1 §5.5's own prediction, judged literally: FAILED

"`morph_test1` frames 2–6 return to ≤ their baseline 789/589 and `frame1` stays
identical." The §5.5 completion alone gives **987 on every frame**, which is
above baseline on all five. Had the brief's stop rule been applied at that point
the deliverable would have been a NO-GO.

### 2.2 …but the completion is unambiguously correct, and the pixel evidence says so

The freeze variant's damage was **monotonic in the placement ratio**
(1 516 → 2 767 across frames 2–6) — the outline detaching further from the fill
as the morph advances. The completion's residual is **flat at 987 on every
frame**, which is the signature of a defect with no ratio dependence at all.
That is what pointed at colour rather than geometry.

Direct confirmation, `frame4`, bounding box of the moving square:

| | bbox | pixel content |
|---|---|---|
| golden (Ruffle) | (419,299)-(519,399), **101×101** | 10 200 px, **one colour** `(101,153,0)` |
| baseline | (420,300)-(519,399), **100×100** | 10 000 px, one colour — **the stroke is absent entirely** |
| §5.5 completion | (419,299)-(519,399), **101×101** | 9 801 fill + **399 px of `(255,0,0)`** |
| shipped | (419,299)-(519,399), **101×101** | 10 200 px, one colour ✔ |

The completion restores the stroke's **geometry to Ruffle's exactly** — the
101×101 extent, one twip-ring wider than the bare fill. Ruffle's golden paints
that ring in the *interpolated* colour, which at frame4 equals the fill colour,
so the stroke is invisible; we painted it in the frozen start colour, red. All
399 residual pixels were the ring. The baseline's 789 was never "closer to
right" — it was the stroke **missing**, i.e. two of the square's edges 1 px
short, which happens to cost fewer pixels than a wrong-coloured ring.

**This is the trap the §5.5 prediction walked into**: on a `tolerance 5 /
max_outliers 0` row, "absent" can outscore "present but mis-shaded", so band
count alone would have rejected a strictly more correct render.

### 2.3 Prediction verdict

**Judged on the mechanism it asserted — "translate the stroke and the outline
rides the morphing fill" — §5.5 is CONFIRMED and exact.** Judged on the band
number it named, it fails by 198 outliers, for a reason it could not have
priced: the second lockstep table. With that table fixed the bands land at
**189, well under the 789/589 baseline**, so the completed patch satisfies the
brief's merge condition.

### 2.4 What the remaining 189 is (not ours)

63 differing pixels, identical in every leg including baseline, all **outside**
the moving square (and `frame1`'s 212 is likewise unchanged in every leg). It is
a pre-existing static-content diff on this test, untouched by morph work.

---

## 3. Ledger

### 3.1 Render canary — md5 A/B at `3747a7fb7`, `base3` → `after3`

10 tests / 19 comparisons. **IDENTICAL 14, DIFFERS 5, 0 trace status changes,
0 image status changes.** All five movers are `morph_test1` frames 2–6, all
improvements.

Byte-identical (md5) across the patch: `from_shumway/acid/acid-morph`,
`visual/cache_as_bitmap/morph`, `from_shumway/invalidClipDepth` (tol-0 tripwire),
`regression/avm2_morph`, `regression/mask_sibling_union` (tol 0),
`visual/simple_shapes/winding_rule` (tol 0), `avm1/color`,
`from_shumway/acid/acid-gradient-0`, `from_shumway/acid/acid-blend-2` (5
comparisons, the standing tripwire), `morph_test1 [frame1]`.

`acid-morph` is unmoved for the reason wave-1 §3.4 cause 1 gives: its stroke
morph is a non-solid fill and is not drawn today at all. `cache_as_bitmap/morph`'s
character has no stroke (`vert_count 6`) and was already balanced.

The whole A/B was re-run from scratch on the rebased tree, so the sibling
landings (`acid-blend-2`'s baseline moved to the new tolerance rows, 4 098–8 484
outliers, all PASS) are present identically in both legs.

### 3.2 Trace — 15 morph-bearing tests, every one at its baseline status

| test | status |
|---|---|
| `avm1/movieclip_hittest_shapeflag` | output_mismatch — **the same 6 diff lines** (71, 171, 173, 175, …), byte-identical |
| `avm2/bounds_mode` | output_mismatch |
| `avm2/displayobject_getrect` | output_mismatch |
| `from_shumway/acid/acid-morph` | output_mismatch |
| `avm1/click_block`, `avm1/hittest_morph`, `avm1/hittest_morph_input`, `avm2/hittest_morph`, `avm2/click_block`, `avm2/morph_shape`, `from_gnash/misc-ming.all/morph_test1`, `from_shumway/invalidClipDepth`, `from_shumway/timeline/nav/morphShape`, `visual/cache_as_bitmap/morph`, `regression/avm2_morph` | pass |

**+0 trace flips, 0 regressions.**

### 3.3 The OOB is gone (generated code, at `3747a7fb7`)

| | baseline | shipped |
|---|---|---|
| `morph_test1` | `vert_count 90` vs `morph_end_shape_data[6][2]` — **84-entry OOB read every frame** | `vert_count 90` vs `[90][2]` |
| `acid-morph` geom | `{4,…,276,1}` `{5,…,276,1}`, array **294** (char 4 reads `[276,312)` past the end) | `{4,…,276,1}` `{5,…,312,1}`, array **330** |
| `morph_test1` colours | `morph_end_color_data[1][4]`, `morph_color_count 1` (stroke colour never lerped) | `[2][4]`, count **2** |
| lockstep assertion | — | **silent on all 15 morph SWFs** |

### 3.4 Build hygiene

Every leg used `touch swf.cpp && make -j4` with `swf.cpp.o` mtime compared to
`swf.cpp` mtime before any verdict was read (s14 §8 / legb §6's thirteenth mode).
Each leg's effect was independently confirmed **in the generated code** before
grading, and each capture used `--recompile`; the base leg was verified to have
actually regenerated (`morph_end_shape_data[6][2]` and char 5 at offset 276 in
the base tree) rather than reusing the after leg's cached output.

---

## 4. Board corrections

1. **"AVM1 morph stroke does not morph" (legb §8 item 3) is RESOLVED**, and it
   was two defects, not one: stroke **positions** had no end-table entries at all
   (an OOB read), and stroke **colours** had no `morph_end_color_data` entries
   (a silent freeze + a shift of any later paired colour). Both are the same
   lockstep contract, on two different tables.
2. **Add a standing note: the morph runtime has TWO index-paired tables**,
   `shape_data ↔ morph_end_shape_data` and
   `color_data[morph_color_start + c] ↔ morph_end_color_data[c]`. Any new
   emission site inside a morph shape must append to both halves of whichever
   pair it touches. The recompiler now asserts the vertex half; the colour half
   is still unasserted (see §5).
3. **`morph_test1`'s 5 failing comparisons are re-priced 789/789/789/789/589 →
   189×5**, still fail→fail (`max_outliers 0`). The remaining 189 is a
   pre-existing static-content diff outside the morph, not a morph defect — if
   anyone wants this row to flip, that is the thing to look at, not the morph.
4. **Method note for the image axis** (§2.2): on a `max_outliers 0` row the band
   count is not monotone in correctness — a missing feature can score better
   than a present-but-mis-shaded one. Before rejecting a render change on band
   count, check the bounding box and colour histogram of the changed region
   against the golden. Doing that here turned a NO-GO into a −76 % improvement.

---

## 5. Known-remaining, deliberately out of scope

`tag.c:6966` (and its AVM2 twin at `:3197`) index `morph_end_color_data` from
**`c`, not `morph_end_color_start + c`**, so the second and later morph
characters in a single SWF read the first character's end colours. The
recompiler already computes the right base (`morph_end_color_before`) but
`tagDefineMorphShape` has no parameter to carry it. Fixing it means a tag
signature change (recompiler + runtime), which is outside this brief and outside
this patch's blast radius. It is unmoved by this work — `acid-morph`, the only
multi-morph-character SWF in the canary, is byte-identical — but it is the
natural follow-up now that the colour tables are populated at all, and it is
also the reason the colour half has no lockstep assertion yet (the assertion
would want the per-character base the tag does not carry).

---

## 6. Files edited

| file | what |
|---|---|
| `SWFRecomp/src/swf.cpp` | `drawLines`/`drawLineJoin`/`drawLineCap` morph_index propagation (3 helpers); `morph_start_positions` table + the translated end-vertex emission and lockstep assertion in `interpretShape`'s stroke loop; `parseMorphLineStyles` end-colour parse + `morph_end_color_data` append (3 arms). +190/−28. |

No runtime (`SWFModernRuntime/`) change, no renderer change, no header change,
no test-fixture change.

## 7. Artefacts

`…/scratchpad/w2morphoob/` — `w2-morph-oob-complete.patch`, `outliers.py`
(absolute CI-grade grading of a capture), `regions.py` / `probe.py` / `crop.py`
(the bbox + colour-histogram analysis that produced §2.2), `cap.sh`,
`trace.sh`, `recompwarn.sh`, `copy.sh`, the per-leg ledgers
(`base_ledger.txt`, `after_ledger.txt`, `after2_ledger.txt`, `base3_ledger.txt`,
`after3_ledger.txt`) and the build logs. Captures live in the worktree at
`.render_canary/{base,after,after2,base3,after3}`; `base3`/`after3` are the
graded pair at `3747a7fb7`.
