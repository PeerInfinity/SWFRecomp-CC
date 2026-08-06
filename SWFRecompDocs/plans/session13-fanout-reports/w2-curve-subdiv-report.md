# w2-curve-subdiv — adaptive quadratic-curve subdivision

Session 13, wave 2 (implementation). Brief: `wave1-gfx-blend2.md` §6.
Worktree `agent-ae069176b0f039386`, baseline `10931d62e`, **nothing committed**.
Deliverables: `w2-curve-subdiv.patch` (3 hunks, one file, `SWFRecomp/src/swf.cpp`)
and this report. Raw ledgers: `ledger_batch1.txt`, `ledger_batch2.txt`;
blast-radius scan: `scan.json`.

**Headline**

1. **STEP 0 IS A SPLIT VERDICT.** At `num_passes = 32`, `output.15` flips
   exactly as wave 1 predicted (**fail 141 → pass 118**). **`output.26` does
   not move at all** — same gating pixel, same 127, while its immediate
   neighbours in the same column *do* improve. Wave 1's attribution of *both*
   stray pixels to chord flattening is **half right**; pixel B has a different
   owner (§3), and should be struck from the expected-flip ledger.
2. **7 flips measured, 0 regressions, at full CI fidelity.** Not the predicted
   2: `acid-blend-2 output.15` **plus six `from_shumway/timeline/timeline_loop`
   comparisons** that the board classes as `hairline_edge_drift` near-passes.
   All 67 graded comparisons reproduce CI's recorded numbers exactly in the
   BEFORE leg (**zero local-vs-CI mismatches**), so these are CI's numbers.
3. **The `hairline_edge_drift` cluster is NOT uniformly the unfixable
   lavapipe-AA gap.** A curve-flattening slice lives inside it and 6 of its
   comparisons flipped here. Playbook §"standing facts" #3 needs a caveat.
4. **`lroundf` is REFUTED and was dropped from the patch** (§4). It is the more
   *correct* operation and it measurably **costs** headroom on every
   acid-blend-2 comparison, including turning `output.26` from 1 outlier into 2.
5. **The standing render canary is blind to this change** — zero of its 21
   tests contain a curve this patch refines, so an all-IDENTICAL canary there
   would have been false-negative mode 10, not a clean bill. The grading set
   was rebuilt from a corpus-wide curve scan (§5), which doubles as the
   blast-radius map: **70 of 381 image-comparison tests / 126 comparisons /
   45 of them currently PASSING** — dominated by **embedded-font glyph
   outlines**, not by the circles and ellipses the brief expected. **All 45
   passing comparisons were graded; none moved status.**

---

## 1. Step 0 — falsification (the gate)

`SWFRecomp/src/swf.cpp:8120` `num_passes = 6` → `32`, cmake rebuild in the
worktree, `--recompile`, local Dawn render.

| comparison | budget | BEFORE | STEP 0 (N=32) | verdict |
|---|---|---:|---:|---|
| `output.10` | tol 130 / 0 out | 128 | **118** | pass → pass, band improves |
| `output.15` | tol 135 / 0 out | **141 (1 out) FAIL** | **118 (0 out) PASS** | **FLIP** |
| `output.20` | tol 130 / 0 out | 124 | **120** | pass → pass, band improves |
| `output.26` | tol 120 / 0 out | **127 (1 out) FAIL** | **127 (1 out) FAIL** | **NO MOVEMENT** |
| `output.40` | tol 160 / 0 out | 135 | 135 | tripwire holds |

Instrument fidelity, re-verified independently of wave 1: my local BEFORE
render of `output.15` and `output.26` is **byte-identical to the CI actual**
from `origin/ruffle-image-results` (`1bc5e0e91`, index generated
`2026-08-06T10:26:33Z`, totals `286/568` — the `1f8396f57` baseline run).
`>0 diffs = 0, max 0` on both 550×400 frames.

**Mechanism CONFIRMED for pixel A, REFUTED for pixel B.**

## 2. Step 1 — the shipped change

```
SWFRecomp/src/swf.cpp:8120   fixed `num_passes = 6` -> adaptive, morph-gated
SWFRecomp/src/swf.cpp:8497   comment only (morph end-edge loop: why it stays 6)
SWFRecomp/src/swf.cpp:9502   comment only (addCurvedEdge: why the cast stays)
```

Max deviation of a quadratic from its chord is
`|control − (current + anchor)/2| / 2`, attained at `t = 0.5`; equal-parameter
subdivision into `N` pieces scales it by `1/N²`. So `N = ceil(sqrt(dev/tol))`
with `tol = 1 twip` (0.05 px at 1:1; Ruffle's lyon tolerance is 0.1 px, so this
is the conservative side of parity), clamped `[6, 64]`.

Two deliberate deviations from the brief:

- **Clamp is `[6, 64]`, not `[2, 64]`** (coordinator's constraint): the patch
  only ever *refines*. A `[2, …]` floor would drop small curves to 2–3 chords —
  a second, unmeasured blast radius on top of the first.
- **The brief's `sqrt(d/(8·tol))` is the lyon form**, whose `d` is
  `|P0 − 2P1 + P2|` = 4× the deviation as the brief defines it. Using the two
  together would have loosened the tolerance by √2 for no reason. The shipped
  form is the direct solve.

**Morph shapes are gated out, and that is load-bearing, not caution.** The
brief's file map calls `swf.cpp:8126` "the morph counterpart (same call)". It
is not: the morph **end** shape is flattened by a **separate inline loop** at
`swf.cpp:8497` with its own hard-coded `passes = 6`, and start/end vertices are
paired **by index** (`morph_index` → `morph_end_positions[i]`). An adaptive
count on the start shape alone desynchronises that pairing; an adaptive count
on *both* desynchronises it too, since a morph's start and end curves have
different geometry by construction and would land on different `N`. Fixed 6 on
both sides is the only self-consistent option short of a two-pass parse.
(Confirmed empirically: `from_gnash/misc-ming.all/*`, 756 curves each, refine
exactly 4 — the non-morph ones.)

acid-blend-2's 24 quadratics resolve to `N ∈ {6×8, 14×2, 15×14}`. The
big-ellipse curves carry `dev = 222.7 twips` (an 11 px sagitta on the raw
quadratic); at the old fixed 6 that leaves `222.7/36 = 6.2 twips = 0.31 px` of
inscribed error — exactly wave 1 §3.1's measured 0.12–0.38 px band on that
ellipse. The sub-pixel fit and the code agree to the twip. At `N = 15` the
residual is 0.99 twips.

## 3. Pixel B (`output.26 (153,282)`) — a different defect, spun out

At `N = 32` the neighbouring rows move and the gating row does not:

| row | BEFORE ours / Ruffle (R channel) | N=32 ours | Δ |
|---|---|---|---|
| y=281 | 221 / 114 (d=107) | 221 | none |
| **y=282** | **229 / 102 (d=127)** | **229** | **none** |
| y=283 | 219 / 102 (d=117) | **168** (d=78) | −39 |
| y=284 | 229 / 127 (d=102) | **203** (d=76) | −26 |

A pixel insensitive to chord count while its neighbours are sensitive sits **on
a curve joint** — the polyline passes exactly through the true curve there at
every `N`. So the residual is a **vertex-position** error, not a flattening
error: our left edge is ~0.8 px inside Ruffle's across five rows (x=153
coverage 0.13 vs 0.75, x=154 coverage 0.82 vs 1.00) at a place where our
geometry is exact by construction.

Candidates, in the order I would test them: placement-matrix / integer-twip
quantisation of a scaled-up shape (`ruffle-geometry-is-integer-twips` — a
1-twip definition-space error becomes `s` twips on screen at placement scale
`s`, and 0.8 px = 16 twips implies `s ≈ 16`), or a fill-rule/edge-rule
difference at the leftmost extremum. **Not this brief's lane, not scheduled.**

## 4. `lroundf` — implemented, measured, REFUTED, removed

Implemented as briefed (in `addCurvedEdge` and, for morph start/end parity, in
the end-edge loop), then measured on acid-blend-2:

| comparison | budget | BEFORE | adaptive only | adaptive + `lroundf` |
|---|---|---:|---:|---:|
| `output.10` | 130 | 128 | 128 | 127 |
| `output.15` | 135 | 141 FAIL | **118 PASS** | 127 PASS (**−9 headroom**) |
| `output.20` | 130 | 124 | 120 | 127 (**3 units from failing**) |
| `output.26` | 120 | 127, **1** outlier | 127, **1** outlier | 127, **2** outliers |
| `output.40` | 160 | 135 | 135 | 135 |

Rounding is unambiguously the more correct operation — truncation is `floor()`
for the positive coordinates shapes are stored in, i.e. a systematic −0.5 twip
bias in x and y on every interior curve vertex. But that bias is 0.025 px, well
below anything adjudicable from first principles, and on the **only comparison
set gradeable at CI fidelity** it costs headroom on three of five comparisons
and adds an outlier to the fourth. `output.20` at 127/130 would be a new
tripwire we do not currently have.

The patch therefore **keeps the truncating cast**, with a comment recording
that this is deliberate. Revisiting it needs its own wave and its own
instrument — it is a corpus-wide half-twip translation and acid-blend-2 is too
small a sample to judge it in either direction. What this *does* settle is that
it must not ride inside a curve-count patch: the two effects are separable and
a mixed ledger could not attribute a regression.

## 5. Blast radius — measured, not estimated

The standing canary turned out to be the wrong instrument, so the grading set
was built from a **corpus-wide scan**: for each of the 381 tests owning an
image comparison, copy `test.swf` into a temp dir (never writing into the main
tree), run the recompiler with a temporary `SWFRECOMP_CURVE_DEBUG` fprintf, and
histogram the computed `N`. ~12 min, zero compiles. (`scan.json`; the debug
fprintf is NOT in the delivered patch.)

```
tests scanned                                    381   (1 timeout)
tests whose SWF contains ANY DefineShape quad      94
tests where at least one curve is REFINED (N>6)    70
image comparisons in those tests                  126   (45 PASSING, 81 failing)
```

**81 % of the corpus's shape geometry does not change at all**, and the 19 %
that does is not where the brief expected it:

- **The biggest movers are embedded-font glyph outlines**, not ellipses.
  `fonts/embed_matching/fallback_preferences` 6571 curves / 4871 refined /
  +28 667 vertices; `visual/fonts/duplicate_font` +9122;
  `text/auto_size/{height,return,width}` +5242 each;
  `visual/edittext/edittext_caret_empty` +3951 across **12 passing
  comparisons**. `swf.cpp:2475` (the stbtt *device*-font path, out of scope per
  the brief) is a different code path — **embedded** `DefineFont` glyphs are
  ordinary shape records that go through the edge parser I changed.
  **And they all render byte-identically anyway** (§6) — glyphs are scaled down
  so far that a 1-twip refinement in EM space is invisible. The refinement is
  pure cost there; see §8 for the tuning follow-up.
- **Zero curves at all** in every `visual/simple_shapes/gradients/*`,
  `winding_rule`, `avm1/color`, `from_shumway/gradient`, `acid-gradient-0/1`,
  `acid-color`, `acid-big`, `clipping`, `visual/drawing_api/*`,
  `avm1/movieclip_begin_gradient_fill`, `avm2/displayobject_mask`. Runtime
  drawing-API curves (`curveTo`) are flattened in `SWFModernRuntime`, untouched
  here.
- **`visual/blend_modes/*` all have 33 curves and refine NONE** (`dev ≤ 36
  twips`). Nothing in this patch can reach those rows — an independent
  confirmation of wave 1 §4's cap.

## 6. Delta ledger (the grading result)

Two capture batches, `render_canary.py capture` before/after with a full cmake
rebuild of the recompiler between legs and `--recompile` on both.
**67 comparisons / 33 tests. Every BEFORE number equals CI's recorded number —
zero local-vs-CI fidelity mismatches — so this table is CI-grade, not A/B.**

### 6.1 Flips (7)

| comparison | before | after | check |
|---|---:|---:|---|
| `from_shumway/acid/acid-blend-2 [output.15]` | fail, 1 out, max 141 | **pass, 0 out, max 118** | tol 135 / 0 |
| `from_shumway/timeline/timeline_loop [output.02]` | fail, 83 out, max 79 | **pass, 41 out, max 70** | near-pass 13 |
| `… [output.06]` | fail, 108 out, max 79 | **pass, 61 out, max 70** | near-pass 18 |
| `… [output.07]` | fail, 83 out | **pass, 41 out** | near-pass 13 |
| `… [output.11]` | fail, 108 out | **pass, 61 out** | near-pass 18 |
| `… [output.15]` | fail, 108 out | **pass, 61 out** | near-pass 18 |
| `… [output.16]` | fail, 108 out | **pass, 61 out** | near-pass 18 |

`timeline_loop` was **not** on anyone's flip list. Its SWF has 8 curves, all
refined (`maxN = 11`). It is an unpredicted rider and the most interesting
result in this report — see §7.

### 6.2 Regressions: **NONE**

All 45 currently-passing comparisons in refined tests were graded (23 in batch
1, 22 in batch 2). Every one still passes. Notable holds:

| comparison | check | before | after |
|---|---|---:|---:|
| `acid-blend-2 [output.40]` **(the tripwire)** | tol 160 / 0 out | max 135 | **max 135, md5 changed** |
| `acid-blend-2 [output.10]` | tol 130 / 0 out | max 128 | max 128 |
| `acid-blend-2 [output.20]` | tol 130 / 0 out | max 124 | **max 120** (headroom 6 → 10) |
| `acid-clip [output]` | tol 150 / 0 out | max 144 | **max 128** (headroom 6 → 22) |
| `edittext_caret_empty [output.01…12]` | tol 128 / 0 out | max 95 | **IDENTICAL** ×12 |
| `text/auto_size/width` | tol 0 / 18 out | 18 out | **IDENTICAL** |
| `acid-textfield-scroll` | tol 128 / 600 out | 552 out | **IDENTICAL** |
| `acid-chars`, `acid-clip-3` ×2, `swf_9/10_too_big` | tol 0/1, 0 out | max 0 | **IDENTICAL** |
| `from_shumway/acid/acid [output.01…16]` | tol 0, 9 100–13 000 out | 8 669–12 347 | −0…−18 each, all pass |

### 6.3 Band moves without a status change

| comparison | before | after | note |
|---|---:|---:|---|
| `from_shumway/doubleAndRegister` | 54 out | **32 out (−41 %)** | hairline near-pass, still fails |
| `from_shumway/acid/acid-clip-2` | 2881 out | 2831 out | passes (budget 3000) |
| `from_shumway/acid/acid` ×14 | — | −2…−18 out each | passes |
| `from_shumway/timeline/timeline_loop [output.12]` | 68 265 out | **68 360 out (+95, +0.14 %)** | already `f_` band, different mechanism (`unrelated_content`) |
| `from_shumway/acid/acid-video [output.01]` | 14 169 out | **14 192 out (+23)** | passes, budget 20 000 |

The only two worsenings in 67 comparisons are +0.14 % and +0.16 % on rows with
huge budgets. Neither is near a threshold.

### 6.4 Trace canary: **clean**

All 33 tests kept their trace status (`pass` ×31, `ruffle_matched` ×2 —
`flash_text_TextField2`, `acid-text-x`, both unchanged). The five dedicated
bounds/hit-test canaries were chosen *because* their SWFs contain refined
curves — `avm1/movieclip_hittest` (24 refined), `avm2/displayobject_hittestpoint`
(8), `avm2/displayobject_hittestobject` (8), `avm2/button_bounds` (49),
`avm2/sprite_with_frames` (177). All still pass.

Why the trace exposure is smaller than the brief feared: the raw curve is
*also* emitted untouched via `emitPath(3.0/4.0, …)`, so the runtime hit-test
path never sees the flattening. The real exposure is bounds —
`SWF::processShape` derives `shape.min/max` **from the flattened vertices**, so
refinement can grow a bounding box by up to the old sagitta (≈5 twips on the
worst curve measured). `button_bounds` is the direct test of that and it holds.

### 6.5 Controls

`avm1/color`, `avm1/edittext_tag_indent`, `visual/simple_shapes/winding_rule`,
`regression/mask_sibling_union`, `from_shumway/acid/acid-gradient-0`: all
**byte-IDENTICAL**, confirming the change is confined to curve flattening.

### 6.6 md5 movement (the "which canaries changed" enumeration)

34 of 67 comparisons changed md5; **every one is in a test the scan predicted
would change, and no test the scan predicted would NOT change moved a byte.**

- `acid-blend-2` ×5, `acid-clip`, `doubleAndRegister`, `timeline_loop` ×7,
  `acid` ×16, `acid-clip-2`, `acid-small` ×2, `acid-video`.
- IDENTICAL despite thousands of refined curves: the entire text/font family —
  `edittext_caret_empty` ×12, `auto_size/{width,height,return}`,
  `match_style`, `fallback_preferences`, `visual/fonts/glyph`, `acid-text-2`,
  `acid-text-x`, `flash_text_TextField2`, `acid-chars`, `acid-textfield-scroll`.

## 7. The `hairline_edge_drift` finding (read this one)

`graphics-fanout-playbook.md` §"standing facts" #3 says the cluster "owns
almost all near-passes (the lavapipe-AA gap, mostly unfixable)". Wave 1 §5
suspected that framing might be wrong. **It is partly wrong, and now
measurably so:** 6 `timeline_loop` comparisons sitting in that cluster at
`a_epsilon` (excess 13–18) flipped on a recompiler-side geometry change, with
max-diff dropping 79 → 70 as well.

But the cluster does **not** move as a whole. Of the hairline members whose
SWFs contain refined curves and that I graded:

| member | excess | result |
|---|---:|---|
| `timeline_loop` ×6 | 13–18 | **flipped** |
| `from_shumway/doubleAndRegister` | 54 | 54 → 32 outliers, still fails |
| `fonts/embed_matching/match_style` | 12 | IDENTICAL |
| `text/auto_size/height` | 12 | IDENTICAL |
| `text/auto_size/return` | 18 | IDENTICAL |
| `visual/fonts/glyph` | 6 | IDENTICAL |
| `from_shumway/acid/acid-text-x` | 6 | IDENTICAL |
| `fonts/embed_matching/fallback_preferences` | 156 | IDENTICAL |
| `avm2/sprite_with_frames` | 920 | IDENTICAL |

So the correct statement is: **`hairline_edge_drift` contains at least two
mechanisms — a text/glyph-rendering one that is insensitive to shape geometry,
and a shape-outline one that is not.** The right splitter is not the near-pass
band; it is "does this test's SWF carry a large-deviation `DefineShape`
quadratic". `scan.json` is that splitter for the whole corpus and is worth
keeping for the next session's board.

Members of the cluster with refined curves that I did **not** grade (each a
small unpriced upside, all text-shaped so probably inert):
`from_shumway/acid/acid-text-6`, `acid-text-escape`, `acid-mask` ×3,
`visual/fonts/duplicate_font`, `from_gnash/misc-ming.all/{morph_test1 ×6,
BeginBitmapFill, Video-EmbedSquareTest}`, `visual/filters/glow_with_alpha_strength`.

## 8. Costs

Generated-source size (recompiler only, `.c` + `.h` bytes, temp dir):

| test | before | after | Δ |
|---|---:|---:|---:|
| `fonts/embed_matching/fallback_preferences` | 6.01 MB | 9.48 MB | **+58 %** |
| `visual/fonts/duplicate_font` | 1.24 MB | 2.32 MB | **+88 %** |
| `visual/edittext/edittext_caret_empty` | 0.56 MB | 1.03 MB | **+83 %** |
| `text/auto_size/height` | 1.72 MB | 2.35 MB | +36 % |
| `avm2/away3d_advanced_shallow_water_demo` | 67.1 MB | 68.1 MB | +1.4 % |
| `from_shumway/acid/acid-blend-2` | 88.16 MB | 88.18 MB | +0.02 % |

The largest `draws.c` in the corpus (acid-blend-2, 88 MB) grows by 0.02 %, so
the giant-function gcc ICE risk is essentially unchanged; the big *relative*
growth is on small font files. Per-file gcc timeout is 300 s and the slowest
affected test compiled in ~106 s before. `visual/simple_shapes/heavy_tesselation`
— the test that once tripped the recompile timeout — has **zero** curves and is
unaffected.

**Tuning follow-up (not done here):** the ~+80 % on font tests buys nothing —
every one of them renders byte-identically. A tolerance expressed in *definition*
twips is far too tight in glyph EM space (a 12 pt glyph is scaled by ~0.23, so
1 twip of glyph space ≈ 0.01 px on screen). Skipping refinement for
`DefineFont` glyph shapes, or scaling `tol` by the font's EM size, would
recover the whole cost with zero measured pixel change. Worth a follow-up if
CI compile time matters; it does not change any result in this report.

## 9. Expected CI movement, with the uncertainty stated

**High confidence (measured at CI fidelity, before-leg reproduces CI exactly):**

| comparison | expectation |
|---|---|
| `from_shumway/acid/acid-blend-2 [output.15]` | fail → **pass** |
| `from_shumway/timeline/timeline_loop [output.02/.06/.07/.11/.15/.16]` | fail → **pass** ×6 |
| `from_shumway/acid/acid-blend-2 [output.40]` (tripwire) | pass → pass, max 135 unchanged |
| all 45 currently-passing comparisons in refined tests | pass → pass (all graded) |
| `from_shumway/acid/acid-blend-2 [output.26]` | fail → fail (**strike from the ledger**, §3) |

**Net expectation: +7 pixel comparisons, 286 → 293 of 567.**

**Residual uncertainty:**

1. **59 failing comparisons in refined tests were not individually graded.**
   They cannot regress a *status* (already failing), but they can move bands in
   either direction. In the 22 I did grade, moves were −41 % (best) to +0.16 %
   (worst).
2. **CI is lavapipe, local is Dawn.** For every comparison in this report the
   BEFORE leg reproduced CI's recorded outliers and max-diff exactly, which is
   the strongest available evidence that the two agree on these tests — but it
   is evidence, not proof, for the AFTER leg. The two flips with the least
   margin are `timeline_loop [output.02/.07]` at 41 outliers against a 70
   budget; that is 29 outliers of slack, comfortably above any plausible
   renderer delta.
3. **Trace axis:** 33 tests held. The corpus-wide trace exposure is bounds-only
   (§6.4) and bounds can only *grow* toward the true curve extremum, by ≤5 twips
   on the worst curve measured. A `getBounds` assertion with twip-exact
   expectations on a curved shape could in principle move; I found no such test
   among the bounds/hit-test tests that carry curves.
4. **One unpriced non-local mechanism.** `swf.cpp:8905/8973` uses
   `shape.min/max` for hole/nesting detection (`compareArea` sort, then a
   **strict** containment test `test_shape.min.x < candidate.min.x && …`). A
   bounds change of a few twips could in principle flip a strict inequality
   where an inner contour touches its outer contour's extremum, which would
   present as a fill/hole inversion rather than an edge shift. Nothing like
   that appeared in 67 comparisons, but it is the mechanism most capable of a
   surprising, non-local regression, and it is the first thing to look at if CI
   shows a `same_geometry_wrong_fill` regression on a curved shape.

## 10. Merge notes for the coordinator

- **Merge this patch FIRST, or grade it in CI with revert readiness.** It
  invalidates every `Recompiled*` cache in the corpus: merging it requires a
  full recompile, and any wave-2 patch merged after it must re-run its own
  canary against the post-merge tree, not the pre-merge one.
- **The patch does not stack-conflict.** Its three hunks are at
  `swf.cpp:8120 / 8497 / 9546`; the sibling wave-2 edits are at ~3551 (video
  tags) and ~4862 (tag_init writer). `git apply` was exercised twice cleanly
  during this work.
- **The standing render canary cannot validate this patch** (§5). If you re-run
  it post-merge, expect IDENTICAL on all 21 tests — that is the correct result,
  not a false negative, and it is *not* evidence the patch is inert. Use
  `grade_tests.txt` / `grade_tests2.txt` (in the scratchpad) instead.
- **Docs to update at closeout:**
  - `graphics-fanout-playbook.md` §"standing facts" #3 — add the §7 caveat:
    `hairline_edge_drift` is at least two mechanisms, and the splitter is
    "does the SWF carry a large-deviation `DefineShape` quadratic", not the
    near-pass band.
  - `wave1-gfx-blend2.md` §2 / §6 ledger — pixel B is **not** curve flattening;
    strike `output.26` from the expected flips and record §3's spun-out lead.
  - `feature-priority-map.md` — fixed-6-chord flattening: **landed**, +7; the
    `hairline_edge_drift` slice hanging off it is *partly* realised (6 of the
    ~25 curve-bearing members), the rest is text-family and inert.
  - Memory-note candidate: *"a near-pass edge drift is not automatically an AA
    gap — but neither is a whole cluster one mechanism; fit the sub-pixel edge
    AND check whether the SWF even has curves before attributing either."*
- **Not touched, as instructed:** the bitmap-fill U-pinning lead
  (`acid-bitmap-fill` stripes, wave 1 §8) and the §7 blue-channel AA dissent.
