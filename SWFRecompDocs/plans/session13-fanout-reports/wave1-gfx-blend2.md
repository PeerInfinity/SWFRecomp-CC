# wave1-gfx-blend2 — acid-blend-2's two stray pixels

Session 13, wave 1 (read-only diagnosis). Baseline: CI run `31090651530`
(`mode=graphics categories=full images=true`) at `1f8396f57`, pixels
**286/567**. Brief origin: `graphics-fanout-playbook.md` §11 lead 3 —
"acid-blend-2 B-channel halving in the blend composite (evidence the capped
blend_modes rows hide a real bug)". Mid-flight the coordinator relayed the
board-audit agent's refutation of that premise; this report is the pivoted
version.

**Bottom line:**

1. **The audit's characterisation is CONFIRMED, independently and to the
   pixel.** `output.15` → one pixel at `(374,203)`, d=141 vs a 135 budget;
   `output.26` → one pixel at `(153,282)`, d=127 vs a 120 budget. I reproduced
   both locally and verified the local render is **byte-identical to the CI
   actual** (maxdiff 0 over both 550×400 frames), so this is not a
   lavapipe-vs-Dawn artefact.
2. **The capped `visual/blend_modes/*` rows stay capped**, and I can now give
   the cap a *proof* rather than an inference: 14 of the 17 tests compile with
   `-DMSAA_SAMPLES=1`, so partial coverage does not exist in them at all, and
   their outlier pixels are the **same set in every mode, shifted in both
   directions** — shared geometry, not blend math (§4).
3. **The mechanism of both stray pixels is identified and it is not blend at
   all**: `SWFRecomp/src/swf.cpp:8120` flattens **every** SWF quadratic curve
   into a fixed **6 chords**, at recompile time, in shape-definition twips,
   with no reference to on-screen size — and truncates each vertex with a
   `(s32)` cast. Inscribed chords put our filled region *inside* the true
   curve by a sagitta that is **zero at chord joints and maximal at chord
   midpoints**, which is exactly why the failures are isolated single pixels.
   Measured: 0.00 px inset at a joint, 0.62–0.69 px at the two stray pixels,
   0.12–0.38 px on a large ellipse in the same frame (§3).
4. **Flip margin is one MSAA sample.** Pixel A needs ≥ 0.030 more coverage,
   pixel B needs ≥ 0.162; the 4×MSAA quantum is 0.25. Closing the flattening
   gap by ~0.6 px converts both. **2 flips**, and the lever is a
   recompiler-side constant that plausibly reaches the whole
   `hairline_edge_drift` cluster (§5–§6).
5. One dissent from the audit, recorded for adjudication (§7): the
   blue-channel anomaly **is** real on the antialiased bands — I have a
   decisive three-point fit — but it is **off the critical path and worth 0
   comparisons**, so the audit's *conclusion* stands even though its
   whole-image per-channel ratio test could not have detected the effect.

---

## 1. Independent confirmation of the audit

`from_shumway/acid/acid-blend-2/test.toml` gives each comparison **two OR-ed
checks** — the comparison passes if *either* passes. Both CI and local:

| cmp | check A (tol / max_out) | ours | check B (tol / max_out) | ours | verdict |
|---|---|---:|---|---:|---|
| output.10 | 20 / 5000 | 7 021 | 130 / 0 | **0** | pass |
| output.15 | 20 / 6000 | 16 491 | 135 / 0 | **1** | fail |
| output.20 | 20 / 5500 | ~7 k | 130 / 0 | **0** | pass |
| output.26 | 20 / 6000 | 13 900 | 120 / 0 | **1** | fail |
| output.40 | 20 / 9000 | — | 40 / 1500 · 160 / 0 | **0** | pass |

```
python3 ruffle-tests/verify_output.py --test=acid-blend-2 \
  --tests-dir=ruffle-tests/tests/swfs/from_shumway/acid --mode=graphics \
  --images --image-out-dir=<scratch>/local-img -v
  [image:output.15] FAIL  1 outliers exceed limit of 0, max difference 141
  [image:output.26] FAIL  1 outliers exceed limit of 0, max difference 127
```

`local vs CI actual: >0 diffs = 0, max 0` on both frames (CI PNGs from
`origin/ruffle-image-results` @ `7421f2983`, 2026-08-06 06:23Z — provenance
matches the baseline run). **Local Dawn is a full-fidelity instrument for this
test**, not merely an A/B probe; wave 2 can grade its own work locally.

Two notes the audit did not have:

- Because the checks are OR-ed there are **two independent flip routes**.
  Route B (one pixel) is the cheap one. Route A would require dropping 16 491 →
  ≤ 6 000, which is owned by an unrelated defect: the 2048×1536
  `DefineBitsJPEG2` fill renders as horizontal stripes crushed into a ~70 px
  column (output.15) / is absent entirely (output.26). That is a bitmap-fill
  UV/matrix bug sharing a signature with `acid/acid-bitmap-fill` (100 661
  outliers) and `acid-bitmap-draw_quality_{high,low}` (194 784 each) — a
  separate, larger lead, out of this brief's lane (§8).
- **`output.40` passes with max difference 135 against a `tol 160 / 0`
  check — 25 units of headroom.** Any geometry change must re-check it; it is
  the regression risk of §6, not a bystander.

---

## 2. The two pixels, and exactly how much they need

**Pixel A — `output.15 (374,203)`.** Boundary between the difference-blend
result (green `51,153,51`) and the backdrop (red `255,0,51`).

```
          x=372        x=373        x=374          x=375
ours      (51,153,51)  (51,153,51)  (255,  0,51)   (255,0,51)
Ruffle    (51,153,51)  (51,153,51)  (114,105,51)   (255,0,51)
```

Only R gates: |255−114| = 141 > 135. We need R ≤ 249, i.e. green coverage
**≥ 0.0294**. One 4×MSAA sample is 0.25 → R = 204 → d = 90. **Any single
sample landing inside flips it.** (G: |0−105| = 105 < 135 already; B: 51 = 51.)

**Pixel B — `output.26 (153,282)`.** Left edge of the big ellipse against the
white stage.

```
          x=152          x=153            x=154
ours      (255,255,255)  (229,235,242)    (89,178,229)
Ruffle    (255,255,255)  (102,140,178)    (51,102,153)
```

Again only R gates: |229−102| = 127 > 120. We need R ≤ 222, i.e. ink coverage
**≥ 0.162**; we have 0.127. (G: 95 < 120; B: 64 < 120.)

---

## 3. Mechanism: fixed 6-chord curve flattening, inscribed

### 3.1 Sub-pixel edge measurement

Recovering the sub-pixel edge position from the partial-coverage values
(coverage `m = (R − R_inside)/(R_outside − R_inside)`, accumulated across all
partial pixels in the row):

| edge | our edge x | Ruffle edge x | Δ (ours inset by) |
|---|---:|---:|---:|
| pixel A boundary, y=202 | 373.25 | 373.878 | **0.63** |
| pixel A boundary, y=203 | 374.00 | 374.69 | **0.69** |
| pixel A boundary, y=204 | 374.75 | 375.377 | **0.63** |
| pixel B boundary, y=282 | 153.873 | 153.25 | **0.62** |
| big ellipse left edge, output.15 y=300 | 131.75 | 131.373 | 0.38 |
| big ellipse right edge, output.15 y=300 | 218.50 | 218.618 | 0.12 |
| **red circle vs white, output.15 y=196 x=363** | ours `(255,127,153)` | Ruffle `(254,127,153)` | **0.00** |

Two things fall out immediately:

- **It is not a global transform offset.** A control edge in the *same frame*
  matches Ruffle to better than 0.01 px, and the big ellipse is inset on the
  left *and* on the right (a translation could not do that; it is a width
  difference: ours 86.75 px, Ruffle 87.245 px).
- **It is not a random rasteriser tie.** The offset is stable across three
  consecutive rows to ±0.03 px, and its sign is always the same: **our filled
  region is inside Ruffle's.**

Our coverages are exact multiples of ¼ (4×MSAA); Ruffle's are continuous
(0.186, 0.814, 0.064, 0.309, 0.623 …), so Ruffle's rasteriser resolves finer
than four samples. That amplifies the consequence of the offset but is not its
cause — a 0.63 px inset is 2.5 MSAA quanta.

### 3.2 The code

`SWFRecomp/src/swf.cpp:8120` (shape parsing, per `CurvedEdgeRecord`):

```cpp
u32 num_passes = 6;
...
addCurvedEdge(current_path, current, control, anchor, num_passes, ...);
```

and `SWF::addCurvedEdge` (`swf.cpp:9502`):

```cpp
for (u32 i = 1; i <= passes; ++i) {
    float t = (float) i / passes;  float u = 1.0f - t;
    s32 x = (s32) (u*u*current.x + 2*u*t*control.x + t*t*anchor.x);   // truncation
    s32 y = (s32) (u*u*current.y + 2*u*t*control.y + t*t*anchor.y);
    ...
}
```

Three compounding problems:

1. **Fixed 6 chords per quadratic**, chosen once at recompile time in
   shape-definition twips. It does not know the shape's size and cannot know
   the placement scale (one shape may be placed at many scales).
2. **The chords are inscribed.** For an arc of radius `r` spanning angle `θ`,
   the maximum chord deviation is `≈ r·θ² / (8N²)` = `r·θ²/288` at N = 6 —
   **always inward**, **zero at the joints, maximal at the chord midpoints**.
   That periodic-along-the-arc profile is precisely the observed pattern:
   0.00 px at the control edge (a joint), 0.62–0.69 px at the two stray pixels
   (mid-chord), 0.12–0.38 px elsewhere on the big ellipse.
3. **`(s32)` truncates** rather than rounds, adding a further ≤ 1 twip
   (0.05 px) bias toward −x/−y on every generated vertex.

Sanity arithmetic on this SWF: the big ellipse is ~281 px across in definition
space (r ≈ 2810 twips). Authored as 45° quadratics (θ² = 0.617) the sagitta is
`2810·0.617/288` = **6.0 twips = 0.30 px** — squarely in the measured 0.12–0.38
band. Authored as 90° quadrants it would be 1.2 px. The two stray pixels sit on
smaller circles placed with a scale-up, which is why their mid-chord inset lands
at 0.6–0.7 px.

**This is a recompiler defect, not a renderer defect**, which is why every
runtime-side hypothesis (the composite, the MSAA resolve, the layer alpha, the
backdrop copy) fitted badly and this one fits everything.

### 3.3 What was ruled out

- **A blend-composite error**: the control edge in the same frame is exact, and
  pixel B's edge is on a *non-blended* object.
- **A stage/placement transform offset**: refuted by the control edge and by the
  bidirectional inset on one ellipse.
- **A rasteriser sample-point tie**: refuted by the offset being stable and
  single-signed across rows; a tie is ±1 quantum and random in sign (compare
  §4, where genuine ties *are* what we see).
- **Integer-twip quantisation** (`ruffle-geometry-is-integer-twips`): 0.63 px =
  12.6 twips, an order of magnitude too large. The `(s32)` truncation is a real
  but second-order contributor.

---

## 4. The blend_modes cap — confirmed, now with a proof

Keeping this section as instructed, rewritten as confirmation.

**(a) The family cannot express the failure mode at all.** 14 of 17
`visual/blend_modes/*` tests declare `quality = "low"`:

```
add lighten screen subtract multiply darken difference invert overlay hardlight
alpha_no_layer erase_no_layer layer_alpha layer_erase          → quality = "low"
overlay_onto_stage  shader_as_mask  shader_without_shader      → quality = "high"
```

`verify_output.py:2014-2035, 2483-2488` maps `low` → `-DMSAA_SAMPLES=1`
(matching `ruffle/render/src/quality.rs`). At one sample there is no partial
coverage anywhere, so no coverage-weighting defect — real or imagined — can
manifest. `from_shumway/acid/acid-blend` is also `quality = "low"`. Of the three
high-quality members, `overlay_onto_stage` **passes** (33 894 / 40 000),
`shader_without_shader` **passes** (0 / 0), and `shader_as_mask` is PixelBender
`BlendType::Shader`, out of scope since s10 §9.

**(b) Their residual pixels are geometry ties.** The failing set is *identical
across every mode* — `(243,46) (365,72) (364,74) (274,92) (156,132) (157,135)
(383,138) (394,173) (258,197) (337,239) (148,240) (365,289) (364,291) (391,348)
(156,349) (196,353) (349,353) (191,355) (405,363)` — 18–20 of them per mode, all
the same locations. A blend-math defect would expose a different set per mode;
shared geometry would not. And the shift is **bidirectional**:

```
(243,46)  ours [130 125 125]   Ruffle [130 130 125]   → our edge 1 px LEFT
(383,138) ours [ 29  29 226]   Ruffle [ 29 226 226]   → our edge 1 px RIGHT
```

Single-sample rasterisation of hard-edged content, ±1 px, both directions =
fill-rule tie. Note the contrast with §3: the acid-blend-2 inset is
**single-signed and sub-pixel-stable**; these are **two-signed and whole-pixel**.
Different mechanisms, and only the first is fixable.

**Verdict: the s11 cap is correct and should stay. `graphics-fanout-playbook.md`
§11 lead 3 should be struck.** No blend-composite change moves any of those
rows.

---

## 5. Corpus reach of the §3 mechanism

The flattening inset is not specific to blend, to acid, or to this suite — it
applies to **every curved SWF shape in the corpus**, with a magnitude that grows
with the arc's radius × angle² and with the placement scale. That makes it a
candidate owner of the `hairline_edge_drift` cluster, which
`graphics-fanout-playbook.md` §"standing facts" #3 says *owns almost all
near-passes* and has until now been written off as "the lavapipe-AA gap, mostly
unfixable". **That framing may be wrong**: an AA gap and a systematically
inscribed outline look identical in a near-pass histogram, and only the
sub-pixel edge fit distinguishes them.

Concretely in this brief's lane: acid-blend-2 ×2 comparisons. Speculatively, a
large slice of the near-pass band. Wave 2 should measure before promising.

---

## 6. Wave-2 brief

**Owner:** recompiler (`SWFRecomp/`), not the runtime. Nothing in
`render_webgpu.c` needs to change, and the standing `MSAA_SAMPLES`-never-4
invariant is therefore not in play (mention it only if the agent ends up in
render code anyway).

**Files / pins**

| what | file:line |
|---|---|
| the constant | `SWFRecomp/src/swf.cpp:8120` (`u32 num_passes = 6;`) |
| the subdivider + truncating cast | `SWFRecomp/src/swf.cpp:9502-9525` (`SWF::addCurvedEdge`) |
| morph counterpart (same call) | `swf.cpp:8126`, `is_morph` arm |
| glyph path flattening (SEPARATE, do not touch in the same patch) | `swf.cpp:2475` (quad, 6) and `swf.cpp:2516` (cubic, 8) — stbtt device-font path |

**Step 0 — cheapest possible confirmation (≈ 1 build, ~20 min).** Hard-code
`num_passes = 32`, `--recompile` acid-blend-2, re-render locally, and check the
two pixels. Prediction: both drop under budget and the test's `image_status`
goes fail → pass on output.15 and output.26. If they do not move, the §3
diagnosis is wrong and everything below is void — stop and report that; a
refutation here is worth as much as the fix.

**Step 1 — the real change.** Replace the constant with an adaptive count:

- deviation of a quadratic from its chord is
  `d = |control − (current + anchor)/2| / 2` (twips);
- `N = ceil(sqrt(d / (8·tol)))`, clamped to `[2, 64]`;
- `tol` in twips. Ruffle's tessellator (lyon) uses a 0.1 px flatten tolerance;
  1 twip (0.05 px at 1:1) is a good conservative target and still bounds a 4×
  up-scale at 0.2 px.
- change `(s32)` to `lroundf` in `addCurvedEdge` (both x and y). This is a
  separate, smaller correction — land it in the same patch but call it out in
  the ledger so a canary move can be attributed.

**Costs and risks to state up front**

- **Recompiler change ⇒ every test must `--recompile`** and a manual `cmake`
  build is required (`parallel-triage` memory: a recompiler change invalidates
  the cached `Recompiled*` trees; float/long-compile failures under `-P` are
  false).
- **`shape_data` grows.** N goes from 6 to ~10–20 on large arcs. Check the
  generated array sizes on the biggest shape tests and watch for the
  giant-function gcc ICE (`recompiler-giant-function-gcc-ice`).
- **Blast radius is the whole corpus**, both axes. Trace output is unaffected
  (geometry only), but `getBounds`-style tests read vertex extents — grep for
  tests asserting bounds of curved shapes before assuming trace is inert.
- **`output.40` of acid-blend-2 passes at max difference 135 vs a 160 budget.**
  It is the nearest thing to a tripwire in this test; it must be in the ledger.

**Canary set** (`ruffle-tests/render_canary.py capture --label before` FIRST —
before touching the recompiler, and note the canary rebuilds from source so the
`before` leg must be captured on a clean tree):

```
from_shumway/acid/acid-blend-2                # 5 cmps — the target AND the tripwire (output.40)
from_shumway/acid/acid-gradient-0             # tier 1, curved + gradient
visual/simple_shapes/winding_rule             # tier 1, tessellation/winding — highest risk row
avm1/color                                    # tier 1, flat fills, must stay IDENTICAL
regression/avm2_timeline_gradients            # tier 1, repo golden
regression/avm2_timeline_stroke_gradient      # tier 1, strokes on curves
regression/mask_sibling_union                 # tier 1, exact at tol 0
visual/cache_as_bitmap/shape_changed          # tier 1
from_shumway/timeline/timeline_as2_5          # tier 1, 7 cmps
avm1/edittext_tag_indent                      # tier 1, text — must be IDENTICAL (glyph path untouched)
```

Expected verdict: **IDENTICAL on every flat-fill and text row** (proof the change
is confined to curve flattening), DIFFERS on curved-shape rows, and an
`image_status` fail → pass on `acid-blend-2 output.15` and `output.26`.

**Expected-flip ledger for the CI run**

| comparison | expectation |
|---|---|
| `from_shumway/acid/acid-blend-2 output.15` | fail → **pass** (1 → 0 outliers at tol 135) |
| `from_shumway/acid/acid-blend-2 output.26` | fail → **pass** (1 → 0 outliers at tol 120) |
| `from_shumway/acid/acid-blend-2 output.10/.20/.40` | pass → pass (**tripwire**: .40 has 25 units of headroom) |
| the `hairline_edge_drift` near-pass band | unquantified upside — measure, do not promise |

**Sizing:** step 0 ~20 min, step 1 ~1 h of code, then a full `--recompile`
rebuild and the canary. One wave, with the caveat that the corpus-wide rebuild
makes it the *slowest* wave-2 item to validate — schedule it first.

---

## 7. Dissent on the record: the blue-channel effect is real but irrelevant

The audit concludes "no channel is scaled" from whole-image per-channel
actual/expected ratios (1.03/0.98/0.99 and 1.05/1.01/1.02). Those ratios are the
right instrument for a *global* channel scaling and correctly reject it — but
they are averaged over 220 000 pixels and cannot see an effect confined to a few
hundred antialiased pixels. On the antialiased band itself the effect is real,
and the fit is decisive rather than suggestive:

On the green/red boundary the layer colour is `s = (204,153,102)` and the
backdrop `d = (255,0,51)`. Indexing our AA pixels by coverage `m` recovered from
R:

| m | ours | correct `d(1−m)+m·|d−s|` | `src.a≡1` model `|d − m·s|` |
|---:|---|---|---|
| 0.25 | (204, 38, **26**) | (204, 38.2, **51**) | (204, 38.2, **25.5**) ✅ |
| 0.50 | (153, 76, **0**) | (153, 76.5, **51**) | (153, 76.5, **0**) ✅ |
| 0.75 | (102, 115, **25**) | (102, 114.8, **51**) | (102, 114.8, **25.5**) ✅ |

No convex mixture of two colours that both carry `B = 51` can produce `B = 0`;
solving the composite for the unknown `src.a` at that pixel gives exactly 1. So
the complex-blend composite **does** behave as if the layer were fully opaque at
partially-covered pixels. It presents as "blue only" because R and G are
algebraically identical in the buggy and correct models whenever `d ≥ s` in that
channel — it is a channel-blind bug with a channel-specific symptom, which is
why a per-channel ratio test is the wrong lens for it.

**But the audit's conclusion is right and mine was wrong**: this defect is not
what gates either comparison (both gating pixels have coverage 0 or near-0,
where the model makes no difference), and §4 shows it cannot reach the capped
rows either. Its corpus value today is **0 comparisons**. Recommendation: record
it as a known-wrong mechanism in the render notes, do **not** schedule it, and
delete the "may re-open the capped blend_modes rows" claim from the board — the
cap is safe for a completely different reason than anyone assumed.

---

## 8. Adjacent lead spun out (not this brief's lane)

The 2048×1536 `DefineBitsJPEG2` fill in acid-blend-2 renders as horizontal
stripes crushed into a ~70 px column (output.15) and is absent in output.26 —
constant colour per row is the signature of a **U coordinate pinned to a single
texture column** while V varies. The bitmap itself uploads fine
(`defineBitmap(0, 12582912, 2048, 1536, 7)`, byte count matches 2048·1536·4
exactly). Siblings with the same signature: `acid/acid-bitmap-fill` (100 661
outliers), `acid-bitmap-draw_quality_{high,low}` (194 784 each);
`acid-bitmap-fill-2` and `acid-bitmaps` pass, so it is fill-matrix-shaped, not
"bitmaps are broken". Also worth a look in that lane:
`MAX_DYNAMIC_BITMAPS = 64` (`render_webgpu.c:1076/1219`) makes this test request
a **~819 MB** bitmap texture array.

## 9. Dispositions checked

`avm1/_investigation/{ACCEPTED_DIFFS,RUFFLE_VS_FLASH_DIFFERENCES,RUFFLE_COMPAT_TWEAKS,FLASH_BUGS_REPLICATED}.md`
and `ignored_tests.txt` — no entry for `acid-blend*` or `visual/blend_modes/*`.
Per the hard/soft split (`graphics-fanout-playbook.md` §3) a trace disposition
would not excuse a pixel failure anyway; both acid-blend-2 comparisons are
pixel-axis only (the test passes on trace).

## 10. Docs to update at closeout

- `graphics-fanout-playbook.md` §11 lead 3 — strike; replace with "capped rows
  are MSAA-off geometry ties (proved w1-blend2); acid-blend-2's 2 pixels are
  curve-flattening inset, owner `SWFRecomp/src/swf.cpp:8120`."
- `feature-priority-map.md` — remove the "acid-blend-2 B-halving may re-open"
  qualifier from the blend entry; add **fixed-6-chord curve flattening** as a
  new lead with the `hairline_edge_drift` cluster hanging off it.
- Consider a memory note: *near-pass edge drift is not automatically an AA gap —
  fit the sub-pixel edge position before writing it off as unfixable.*
