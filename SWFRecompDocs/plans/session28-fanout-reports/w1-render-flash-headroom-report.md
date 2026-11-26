# s28 wave 1: `w1-render-flash-headroom`: quality model + gnash shape headroom vs Flash

Cloud worker, 2026-11-25. Base `origin/master` `d5f9726d`. Ruffle upstream at download time: `c2f7d24b7`.
Graphics mode on lavapipe. **CI fidelity was proven on all three failing rows:** our clean-master *before* render is
md5-identical to CI's actual PNG on `ruffle-image-results` (`a455a4077`) for `gradientTransform`, `place_object_test`
and `shape_test`. So the absolute numbers below are CI-grade.

**New files** (all under `session28-fanout-reports/`):
- `w1-render-flash-headroom-report.md` (this file).
- `w1-render-flash-headroom-prototype.patch`: the MSAA-1 tie-bias prototype, `render_webgpu.c` only. It is reverted
  in the tree.
- `w1-render-flash-headroom-fixtures/make_fixtures.py` and `make_gt_offsets.py`: generators for the Flash oracle
  requests. Their built SWFs are under `…-fixtures/out/`.
- `w1-render-flash-headroom-gate-ledger.txt` and `w1-render-flash-headroom-canary-compare.log`: the prototype's A/B
  gate, with a per-row Flash-reference grading.

## Verdicts (lead)

| # | Item | Verdict | Flips |
|---|---|---|---|
| 1 | Harness renders at the golden's quality (HIGH) for `gradientTransform` / `acid-color` | **NO-GO (refuted)** | `gradientTransform` gets **worse**: 9 → 1767 outliers. `acid-color` frame1 is md5-identical low vs high and passes either way |
| 2 | `gradientTransform` 9-px miss = "our low AA vs a HIGH golden" | **REFUTED.** Our LOW render *is* Flash-HIGH-like: 3 px over tol, all in the bevel's 45° corner pixels | none cheap. Completion mechanism: Flash's HIGH edge snap (oracle request #2) |
| 3 | Brief's pricing "our miss vs Flash root ≈ 5984 / 1437 px" | **REFUTED (mis-read column).** Those are *golden*≠Flash. **Ours≠Flash root is 16 342 / 8 384 px** (tol 50, px count) | — |
| 4 | Thin-stroke tie rule at LOW quality (Flash paints a hairline at integer x into pixel x; we paint x−1) | **Rule confirmed Flash-ward, but the global prototype is NO-GO.** Hand to sibling `n-stroke-snap` (it owns the stroke rule). Prototype: `shape_test` 8 384 → **5 895**, `place_object_test` 16 342 → 15 881 vs Flash; gate: 29 closer / 6 farther vs Flash, **36 pass→fail** vs (Ruffle) goldens | no flips. A stroke-only version is the wave-2 shape (§3) |
| 5 | **Duplicate-depth PlaceObject (SWF ≤ 5/6?): Flash keeps BOTH objects; the newcomer goes BEHIND.** We and Ruffle refuse the newcomer with "Failed to place object" | **HOLD on a Flash oracle (#1); then GO (M).** Proven for SWF 5 by the Flash root capture's own xtrace window (`#passed: 7`) | pixels: `place_object_test` −~5.5k px, `shape_test` −1.8k px. Trace: `place_object_test` RM→pass (gnash, SWF 5). Candidates if the rule also holds at SWF 6: `place_object_test2`, `path_format_test` (both RM, and their goldens differ from Ruffle **only** by the warning lines) |
| 6 | Unclosed fill paths (gnash `shape_test` shapes 6/8): Flash leaks the open fill across to the next shape's edge | **HOLD (needs the Flash fixture)** | `shape_test` −~3.1k px (bar 2 320 + sprite-9 interior 783) |

**Net for the deferred flash_fixes swaps** (golden → Flash ROOT capture once our miss is < ~1k px):
- **`shape_test`** reaches the threshold only with #4 + #5 + #6 all landed: 8 384 → 5 895 → ~4.1k → **~1.0k**. The
  residual is the xtrace text band (986 px, glyph raster). It is a coin-flip at the 1k line, not a lead.
- **`place_object_test`** does not reach it. After #4 + #5 the squares are fixed and the xtrace *content* matches
  Flash. What remains is ~7 lines of xtrace glyph raster, estimated ~1.5–2k px from shape_test's 986 px for 4 lines.
- So: **no swap is in reach this session without text-raster work.** #5 is worth doing for its own sake (a Flash
  display-list rule, plus a trace RM→pass).

## 1. Quality model (task 1)

**Plumbing.** `test.toml` `[player_options] with_renderer = { quality = "low" }` →
`verify_output.py:get_msaa_samples()` (`:2640`, low→1, everything else→4). It is emitted as `-DMSAA_SAMPLES=1` only
when ≠ 4 (`:3168`). The runtime uses it for the MSAA colour target sample count (`render_webgpu.c:50-62`) and for
the MSAA-gated border corner rule (`tag.c:7862`). Nothing else keys off quality. `[subtests]` variants go through
`_quality_to_msaa` (`:278`).

**Ruffle honours it.** `tests/framework/src/options/player.rs:33-35` →
`player_builder.with_quality(render_options.quality())`, and `StageQuality::Low.sample_count() == 1`
(`render/src/quality.rs`). So our harness mirrors the Ruffle runner exactly. `gradientTransform` is upstream
`known_failure`: Ruffle's own `.ruffle.png` at low misses the Flash golden (3 px, max 23).

**`gradientTransform` measured** (tol 3; "outliers" = Ruffle's per-channel count; px = pixels over tol):

| render | px over tol 3 vs golden (= Flash HIGH, exact) | runner outliers | max |
|---|---:|---:|---:|
| ours, quality low (CI today) | **3** | 9 | 11 |
| ours, quality **high** (toml edited) | **589** | 1 767 | 20 |
| Ruffle `.ruffle.png` (low) | 3 | — | 23 |

Mechanism. The shape is two 1-px gradient bevel rings. Their edges sit at −10/10/30/1990/2010 twips, and the stage
RECT is xmin = ymin = −13 twips, so after the stage translation every edge lands at a **x.15 px** device position.
- Our MSAA-4 render honestly AA's every ring edge 15/85.
- Our MSAA-1 render point-samples at pixel centres, which puts each ring solidly into one pixel.
- **Flash at HIGH draws the rings hard**, identical to our LOW render on 2 494 of 2 525 pixels.

So Flash HIGH did not anti-alias these axis-aligned 0.15-px-offset edges. It rounded them to whole pixels (or
rounded the root's fractional stage translation). It did anti-alias the diagonal corner joins: golden (0,23) = 149
lies between the ring colours 136 and 173.

The 3 residual px are exactly those diagonal corner pixels: (0,23), (99,23), (100,24). Ours point-samples them.
- Fixing them inside our LOW mode is not principled.
- Flash's actual model, which the oracle must pin, is "snap axis-aligned edges/vertices to the pixel grid, then 4×4
  AA". That model would give hard rings *and* AA'd diagonals.

**This ties to the sibling `n-stroke-snap` rule** ("hairline/1-px strokes SOLID on pixel `floor(edge)`"). The
gradientTransform evidence says Flash also snaps axis-aligned **fill** edges (round-to-nearest: 0.15→0, 99.15→99,
24.15→24). That is in scope for n-stroke-snap's pinning, and I'm flagging it to them via this report.

**Harness option priced:**
- (A) Render at the golden's quality (HIGH) for the 2 rows the s27 `--quality high` sweep found (the whole
  mismatch population: `gradientTransform`, `acid-color` frame1). `gradientTransform` 9 → 1767 outliers, a strictly
  worse fail. `acid-color` frame1 is md5-identical at low and high (`593d5051…`, axis-aligned content; it passes at
  max diff 2 today, so the brief's "same" premise is stale).
- (B) Keep `test.toml` quality. **(B).** No harness change: the golden/toml mismatch costs us nothing, because our
  LOW AA already sits closer to Flash HIGH than our HIGH AA does.

## 2. gnash `place_object_test` / `shape_test` vs the Flash ROOT captures (task 2)

Flash captures: `session27-fanout-reports/golden-provenance/from_gnash__misc-ming.all__{test}__output.direct-pinned.png`.
Both are an AVM1 root at test.toml quality LOW (the pin stub carries `_quality`, flash-oracle README §quality).
Region split uses 3-px-linked components of |Δ| > 50 (`regions.py`, scratch).

**Important context:** our clean-master `shape_test` render is **byte-identical to Ruffle's own
`output.ruffle.png`** (0 px over tol 50, max diff 0). `place_object_test` is 1 649 px from Ruffle's output (xtrace
text). Every residual below is therefore a **Ruffle≠Flash** difference that we inherited, not a regression of ours.

### shape_test (8 384 px vs Flash)

| region | px | cause |
|---|---:|---|
| 4 stroked squares/L outlines (rows 2–3) | 2 489 | **tie rule** (§4): Flash paints the 1-twip hairline centred on x=100 into pixel 100; ours into 99 (stroke quad [99.5,100.5], pixel centre exactly on the edge, top-left rule). Fixed by the prototype: all four outline regions go to 0 |
| top-left green L (100–160 × 140–200) | 1 800 | **duplicate depth** (§5): sprite 7 is placed at depth 4 over `sh2` (the black square). Flash shows both; we refuse sprite 7 |
| green bar 160–220 + inside sprite 9 | 2 320 + 783 | **unclosed fill path** (§6): shapes 6 and 8 end at (400,600), never closing back to (400,200). Rows local 200–600 have an odd crossing count. Flash fills from sprite 7's last edge (abs x=160) across to sprite 9's first edge (x=220), and also fills sprite 9's would-be hole column. We (and Ruffle) close the path implicitly |
| xtrace text band (rows 0–60) | 986 | glyph raster of the same text (content identical: `#passed: 18`) |

### place_object_test (16 342 px vs Flash)

The test's own trace says what Flash does:

> *Placed red shape sh1 and black shape sh2 at the same depth 3. Should both be visible, red on top.*
> *Placed red sprite mc1 and black sprite mc2 at the same depth 4. Should both be visible, black on top.*

The Flash root capture shows exactly that, and its xtrace window reads **`#passed: 7`**. Ours and Ruffle's read
`FAILED: expected: sh2 obtained: _level0 … #failed: 3` and draw one square of each pair.

| region | px | cause |
|---|---:|---|
| square pair 1 (0–90 × 220–310) | 2 761 | duplicate depth: `sh2` (black) refused |
| square pair 2 (100–190 × 220–280) | 2 760 | duplicate depth: `mc1` (red) refused |
| xtrace text (several bands, ~6k) | ~7.4k | different **content** (FAILED vs PASSED lines), then glyph raster |
| stroke offsets | 461 | tie rule (prototype) |

**Stacking order from the SWF:**
- Shapes: `sh1` (red, char 4) is placed first, then `sh2` (black, char 5) at depth 3, and the red stays on top.
- Sprites: `mc2` (black, char 7) is placed first, then `mc1` (red, char 6) at depth 4, and the black stays on top.

Both pairs agree: **the newcomer is inserted BEHIND the existing occupant, and both stay.**

`shape_test` is consistent with this. Sprite 7 goes behind `sh2` at depth 4, and they are disjoint, so both are
visible.

## 3. Gate (task 3): MSAA-1 tie-bias prototype

The patch is `stage_upload_tiebias()` in `render_webgpu.c`. It wraps the two `stage_to_ndc` uploads,
`render_webgpu_upload_stage_transform` and the pass-open upload. At `MSAA_SAMPLES == 1` it adds +1/256 device px to
the NDC translation in x and in y-down. The effect is that exact pixel-centre ties resolve bottom-right instead of
top-left. Non-tie samples cannot move: all geometry is on a 1/20-px grid ≫ 1/256.

At MSAA 4 the function is the original `wgpuQueueWriteBuffer`. So every non-low row is byte-identical **by
construction** (it is preprocessor-dead code), and the gate only needs the low-quality rows.

Gate set: every `quality = "low"` member of `render_canary_tests.txt` (80), plus every low gnash image row
(`BeginBitmapFill`, `morph_test1`, `place_object_test`, `shape_test`, misc-swfmill `background`, `missing_bitmap`),
plus `gradientTransform`.

Gate size: 85 tests, 112 comparisons, A/B md5. Full ledger: `w1-render-flash-headroom-gate-ledger.txt`. Raw compare
output: `…-canary-compare.log`.

**Result: 45 comparisons DIFFER, and 36 of them go pass → fail against their (mostly Ruffle-made) goldens.** No
comparison goes fail → pass. Traces are unchanged everywhere. As a global rule the prototype is a **NO-GO**.

The same 45 comparisons graded against the best available **Flash** reference (a Flash-verdict golden, a flash_fixes
golden, or the s27 archive capture; px ≠ Flash at tol 0): **29 closer to Flash, 6 farther, 5 equal**, and 5 have no
Flash reference (filters/stage3d, untestable).

| row | vs Flash before → after |
|---|---|
| `avm2/graphics_draw_path` (flash_fixes golden) | **387 → 126** |
| `morph_test1` frame1 / frame6 | 201 → **1** / 320 → 124 |
| `misc-ming shape_test` | 8 804 → 6 315 |
| `acid-text` | 6 174 → 5 348 |
| `visual/simple_shapes/overlaps` | 626 → 473 |
| blend_modes ×4 | −160 … −515 each |
| *farther:* `simple_shapes/gradients/gradients` | 80 294 → 80 575 |
| *farther:* `drawing_api/fills_and_lines` | 59 875 → 60 126 |
| *farther:* `drop_shadow_angles` | +72 |
| *farther:* `masks` | +7 |
| *farther:* `gradientTransform` | 17 → 19 |
| *farther:* `graphics_simple_shapes` | 79 → 80 |

Reading:
- The tie direction is Flash-ward for **strokes**. The biggest wins are all stroke rows, matching `n-stroke-snap`'s
  "solid on `floor(edge)`".
- Biasing **every** primitive is too coarse. Gradient fills and filters drift because a +1/256 px shift also moves
  gradient sampling and filter sources off exact texel ties.
- The rule belongs on stroke geometry only, which is what n-stroke-snap is building.
- Caveat: the archive refs for low-quality rows are s27 wrapper or root captures at test.toml quality, which
  golden-provenance treats as Flash-at-that-quality. Several of the "closer" deltas are small next to the absolute
  miss.

**Disposition:** do not land the tie-bias. Hand the ledger to `n-stroke-snap` as a corpus price for "strokes on
`floor(edge)` at MSAA 1". The stroke-only version should keep the wins above without the 36 pass→fail moves; most of
those moves are fills, gradients and filters. Any Ruffle-golden row that a stroke-only rule still moves is a priced
Flash-over-Ruffle loss (RvF).

## 4. Refutations

- **"gradientTransform's 9 px is our quality=low AA vs a HIGH golden."** False. Our HIGH render is 196× worse
  (589 px vs 3 px). Flash HIGH does not AA these edges.
- **"acid-color frame1 (same)."** It passes today (max diff 2) and is md5-identical at low and high. Nothing to do.
- **"Our miss vs the Flash root captures is ~5984 / ~1437 px."** That is the *golden*-vs-Flash column of
  golden-provenance row 138/139. Ours vs the Flash root is **16 342 / 8 384** (17 540 / 8 804 there at a different
  count convention). The deferred-swap threshold (< ~1k) is therefore ~8–16× away, not ~1.5–6×.
- **"Prototype stroke joins/caps, hairlines, fill rule, twip snap."** Joins and caps contribute **0 px** here:
  - every outline region is fully explained by the tie rule;
  - "fill rule" is really the *unclosed-path* semantics (§6), not even-odd vs non-zero;
  - the dominant term is a **display-list** rule (§5), which is not a renderer issue at all.

## 5. Mechanism owners (for wave 2)

- **Duplicate depth (§5):** `SWFModernRuntime/src/libswf/tag.c` `tagPlaceObject2`. The Phase-3 refusal is at
  `tag.c:~12665-12690` (`printf("Warning: Failed to place object at depth …")`). The display list is
  `display_list[depth]`, one slot per depth. Keeping two objects at one depth needs a secondary "under" chain per
  depth slot (render + hit-test + `getDepth` + name lookup + remove semantics), or a depth-key remap (fractional
  sub-depth behind). **Size M–L.** The rule must be SWF-version gated if oracle #1 shows SWF ≥ 7 (or ≥ 8) refuses.
  `avm1/placeobject_occupied_depth` (SWF 15) has a golden that shows refusal + warning: "Instantiated ID 3" prints
  once, so the depth-1 char-3 Place was not instantiated.
- **Tie rule / snap (§4, §1):** sibling `n-stroke-snap` (local). My prototype is the LOW-quality special case of their
  `floor(edge)` hairline rule. Theirs generalises to MSAA 4, scale and non-integer edges. Use their implementation,
  not this patch.
- **Unclosed fill paths (§6):** recompiler fill tessellation (`SWFRecomp/src/swf.cpp`, implicit path close). Flash's
  global scanline leak (the fill stays "on" until another edge on the same scanline, across objects) is not
  expressible in a per-shape triangle tessellation. Pin it in Flash before pricing. Corpus blast radius is probably
  tiny (gnash shape tests).

## New unclaimed leads

1. **Trace RM→pass via duplicate depth:** `from_gnash/misc-ming.all/place_object_test` (SWF 5; Flash proven by its
   own xtrace capture). Candidates `place_object_test2`, `path_format_test` (SWF 6) differ from the golden only by
   `Warning: Failed to place object at depth N` lines that Flash did not print. Corpus sweep of root-timeline
   occupied-depth Places (`occ.py`, scratch): exactly these 4 gnash rows + `avm1/placeobject_occupied_depth` (SWF 15)
   + 2 shumway fuzz rows (SWF 11/13, already graded on the refusal warning).
2. **Flash HIGH snaps axis-aligned fill edges** (gradientTransform: 0.15-px-offset rings rendered hard, diagonals
   AA'd). Feed this to `n-stroke-snap`'s pinning. It may also explain other near-Flash HIGH rows with fractional
   stage RECTs.
3. `shape_test` 986 px / `place_object_test` ~1.5–2k px of xtrace glyph raster is what blocks both deferred
   swaps once 4–6 land. It is a DefineEditText with embedded "Bitstream Vera Sans" at LOW. Text-raster family.

## LOCAL ORACLE REQUESTS

1. **FLASH: occupied-depth rule vs SWF version** (trace + image, direct pinned, 30 ticks).
   `python3 SWFRecompDocs/plans/session28-fanout-reports/w1-render-flash-headroom-fixtures/make_fixtures.py`
   builds `out/place_object_test_v{5,6,7,8,10}` and `out/placeobject_occupied_depth_v{5,6,7,8,15}` (header version
   byte patched only; SWFs are also committed under `out/`).
   - For `place_object_test_v*`: does the xtrace window say `#passed: 7`, and are both squares of each pair visible?
   - For `placeobject_occupied_depth_v*` (trace): how many `Instantiated ID 3` lines, and are the
     `Warning: Failed to place object` lines printed?
   - Also please run the unmodified `from_gnash/misc-ming.all/place_object_test2` and `path_format_test` traces
     (direct): do they print `Warning: Failed to place object at depth N`?
2. **FLASH: edge snap at HIGH** (image, direct pinned, quality **high**, 1 tick):
   `make_gt_offsets.py` builds `out/gradientTransform_off{0,5,10,13,15}`. These are `gradientTransform` with only
   the header RECT moved (xmin = ymin = −off twips; the edges land at (edge+off)/20 px, i.e. offset fractions
   .5/.75/.0/.15/.25). Are the rings hard at every offset (snap) or AA'd at .5/.25/.75? That pins the rounding mode.
   Note: off13 == the corpus SWF (RECT re-encoded at 16 bits).
3. **(Deferred, no fixture built) FLASH: unclosed fill path.** The corpus `shape_test` capture already shows the
   leak. Pinning its rule (does the open fill stop at the next edge of ANY object on the scanline?) needs a fixture
   with one unclosed shape alone and one beside a second shape. Build it only if the coordinator wants §6 priced.
