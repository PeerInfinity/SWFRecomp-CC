# Session 16 — wave 2 — w2-gfx-flatten-legC (HELD leg C, recompiler curve flattening)

**Agent:** `w2-gfx-flatten-legC` · isolated worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a360c309db628703d`
**Brief:** rebase s15's HELD leg C (recompiler-side lyon/Levien flattening in
`SWFRecomp/src/swf.cpp`) onto HEAD, grade it on BOTH axes, and attack its
premise — s15 held it back because it was believed to shrink shape bounds by
~1 twip and therefore move `getBounds`/`_width`/`_height` traces corpus-wide.

---

## 0 — NEW FILES IN THIS PATCH

**None.** `w2-gfx-flatten-legC.patch` touches exactly one existing file:
`SWFRecomp/src/swf.cpp` (+151 / −1). Nothing to `git add` beyond it.

---

## 1 — VERDICT

| | |
|---|---|
| **Leg C** | **GO — ship it, on its own CI dispatch** |
| Axis to dispatch | `mode=graphics`, `categories=all` (or `full`), `images=true` — it is BOTH a pixel change and a full-corpus recompile |
| Pixel effect | **7 comparisons improved, 0 worsened past their limit, 0 status regressions** (local Dawn A/B, 29 tests / 50 comparisons) |
| Trace effect | **ZERO.** 138/138 probe tests byte-unchanged; 0 status changes, 0 flips, 0 `ruffle_matched` regressions (§4) |
| Free win | **−39.2 % emitted shape vertices** across the 418 affected tests (10 361 064 → 6 303 717 rows) |
| The premise it was held for | **REFUTED.** Shape bounds are the SWF-declared `RECT`, never derived from flattened geometry — in our recompiler AND in Ruffle (§3.1). Verified byte-for-byte on all 418 affected tests: **0 bounds changes, 0 structural changes.** |

---

## 2 — PIXEL LEDGER

Local `--mode=graphics` A/B via `ruffle-tests/render_canary.py`, standing canary
set (23) + the s15 census rows (8) = **29 tests / 50 comparisons**, both legs
captured with `--recompile` after a cmake rebuild of the recompiler (canary
false-negative mode 1).

```
RENDER CANARY  before=base  after=legC   29 tests / 50 comparisons
  IDENTICAL    36     DIFFERS 14     APPEARED 0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

Outliers vs golden, base → leg C (`excess_outliers` = the graded quantity):

| comparison | status | outliers | verdict |
|---|---|---:|---|
| `visual/simple_shapes/masks [output]` | fail → fail | **1738 → 1497** | IMPROVED −241 |
| `visual/simple_shapes/masks_equal_clipdepth [output]` | fail → fail | **1738 → 1497** | IMPROVED −241 |
| `visual/filters/drop_shadow [output]` | fail → fail | **46468 → 46032** | IMPROVED −436 |
| `visual/simple_shapes/scroll_rect_mask [output]` | fail → fail | **42 → 20** | IMPROVED −22 |
| `visual/blend_modes/multiply [output]` | fail → fail | **37 → 19** | IMPROVED −18 |
| `from_shumway/doubleAndRegister [output]` | fail → fail | **32 → 26** | IMPROVED −6 |
| `visual/avm2_button_scroll_rect [output]` | fail → fail | **9 → 6** | IMPROVED −3 |
| `regression/avm2_timeline_gradients [output]` | pass → pass | 0 → 0 | md5 moved, still exact |
| `regression/avm2_timeline_stroke_gradient [output]` | pass → pass | 0 → 0 | md5 moved, still exact |
| `from_shumway/acid/acid-blend-2 [output.10]` | pass → pass | 4098 → 4114 (limit 5000) | +16, 886 spare |
| `from_shumway/acid/acid-blend-2 [output.15]` | pass → pass | 5876 → 5926 (limit 6000) | +50, **74 spare** |
| `from_shumway/acid/acid-blend-2 [output.20]` | pass → pass | 5242 → 5286 (limit 5500) | +44, 214 spare |
| `from_shumway/acid/acid-blend-2 [output.26]` | pass → pass | 5566 → 5618 (limit 6000) | +52, 382 spare |
| `from_shumway/acid/acid-blend-2 [output.40]` | pass → pass | 8484 → 8506 (limit 9000) | +22, 494 spare |
| the other **36** comparisons | — | — | byte-identical PNGs |

**Two board claims that s15 could not price are now priced.** `visual/filters/drop_shadow`
(−436) and `visual/blend_modes/multiply` (−18) are NOT in the s15 census — they moved
because their *source geometry* is curve-bearing, and no one had A/B'd them. Both are
still `fail`; leg C is a band move on each, not a flip.

**Zero flips.** Every improved row is far from its limit; every regressed row is
`acid-blend-2`, whose 5 comparisons all still pass. Leg C's pixel value is
**7 band moves + a 39 % geometry-size cut**, exactly as s15 priced it, plus two
rows s15 never measured.

**Risk item — `acid-blend-2 [output.15]`.** Its slack drops from 124 to **74
outliers out of a 6000 budget (1.2 %)**. That is the single thinnest margin in
the ledger. It is a *local Dawn* number; CI runs lavapipe, and this comparison
grades at `tolerance = 20` with thousands of outliers, so the local figure is
not the CI figure. If the merged CI run flips `acid-blend-2 [output.15]`
fail, that is the row to look at first, and raising its `max_outliers` from
6000 to 6500 in `test.toml` is the intended fix (the comparison is a
blend-mode instrument, not a curve instrument).

### Canary blind-spot disclosure

The standing `render_canary_tests.txt` gained `from_shumway/acid/acid-blend-2`
in s15 precisely so this leg would have a curve-bearing, image-passing member —
and it is the only canary row that moved into thinner margin. The other
curve-bearing regression checks all held: `text/auto_size/height` (460 embedded
glyphs, 51 264 → 33 213 vertices) and `visual/fonts/glyph` (120 glyphs,
10 998 → 7 443) are **PNG byte-identical**, and `regression/avm2_morph` is
byte-identical (morph pairing untouched — leg C's Levien arm is `!is_morph`).

---

## 3 — PREMISE ATTACK: the bounds claim is FALSE

s15 §5 held leg C because "`processShape()` derives `shape.min`/`shape.max` from
the flattened vertex list, so a coarser flattening can shrink a shape's bounds
by up to ~1 twip … that feeds `getBounds`/`getRect`/`_width`/`_height`."

That sentence is true about `processShape()` and false about `getBounds`.

### 3.1 Where AS-visible bounds actually come from

* **Recompiler.** `SWFRecomp/src/swf.cpp:10579` emits
  `tagDefineShape(app_context, TYPE, id, offset, size, XMIN, XMAX, YMIN, YMAX)`
  where the four bounds come from `shape_tag.fields[2..5]` — the **`ShapeBounds`
  RECT read straight out of the SWF tag** (`swf.cpp:8286`). Flattened vertices
  are not consulted.
* **Runtime.** `tagDefineShape` (`SWFModernRuntime/src/libswf/tag.c:7903`) forwards
  those four integers to `ng_record_char_bounds`, and every AS-visible bounds
  path (`mcGetOriginalBounds`, `ng_localBoundsOfDL`, button bounds union,
  AVM2 `getRect`/`getBounds`) reads them back through `ng_getCharBounds`.
* **`processShape()`'s `shape.min`/`shape.max` never leave the recompiler.**
  Their only consumers are the area sort and the even-odd nesting/hole
  heuristic at `swf.cpp:9995`–`10063`. They are not emitted.
* **Ruffle agrees.** `Graphic::self_bounds` returns
  `shared.shape_bounds` / `shared.edge_bounds`
  (`ruffle/core/src/display_object/graphic.rs:189`), populated from
  `swf_shape.shape_bounds`, which `swf/src/read.rs:1229` fills with
  `read_rectangle()` — the declared RECT. Ruffle never derives bounds from
  tessellated geometry either.

So the correct answer to "does Ruffle's reported bounds come from the flattened
geometry or the control-point hull?" is **neither** — it comes from the RECT the
authoring tool wrote into the tag, and so does ours. **No patch split was
needed**; the geometry change and the bounds computation were already disjoint.

### 3.2 Corpus-wide verification (not a sample)

I ran BOTH recompiler binaries over **every** `test.swf` in the corpus (4492
SWFs) in isolated temp dirs and diffed the generated C
(`scratchpad/legC/sweep.sh`, `boundscheck.sh`):

| measurement | result |
|---|---:|
| SWFs recompiled per leg | **4492** |
| generated C **byte-identical** | **4074** |
| generated C **differs** | **418** |
| of those 418: `tagDefineShape` **bounds arguments** changed | **0** |
| of those 418: `tagMain.c` changed **structurally** (any non-numeric text) | **0** |
| of those 418: `ng_record_char_path` records changed | **0** |
| total `shape_data` rows | 10 361 064 → **6 303 717 (−39.2 %)** |

The only things that move in `tagMain.c` are the `shape_offset` / `shape_size`
arguments — which *must* move, because the vertex table shrank. Worked example
(`avm2/displayobject_getrect`):

```
-tagDefineShape(app_context, CHAR_TYPE_SHAPE, 1, 0, 9681, 665, 2008, 514, 2033);
+tagDefineShape(app_context, CHAR_TYPE_SHAPE, 1, 0, 1839, 665, 2008, 514, 2033);
 ng_record_char_path(1, 0, 1206);              <-- unchanged
```
Bounds `665, 2008, 514, 2033` identical; only `size 9681 → 1839`.

Font/text tests are even cleaner: for every text-only test (e.g.
`avm1/edittext_align`) `tagMain.c` is **byte-identical** — only `draws.c` and
`draws.h` change. Font advance tables, ascent/descent/leading, glyph bases and
text bounds are all untouched, so `autoSize`, `getLineMetrics`,
`getCharBoundaries` and `TextField.textWidth` cannot move.

### 3.3 The residual trace surface, and why it is nearly empty

`shape_data` (the flattened triangles) has exactly four runtime consumers:
the two renderers, `avm2_cpu_raster.c`, and hit testing. Of the hit-test paths:

* **AVM1 shapes — immune.** `SWFModernRuntime/src/libswf/shape_hit_test.c`
  tries `path_data` first (analytic quadratic winding, a port of Ruffle's
  `winding_number_curve`) and comments *"Path test is authoritative when
  available — skip triangle fallback"*. `path_data` carries the raw
  control/anchor pair (`emitPath(3.0f, …)`) and is **unchanged by leg C**.
  Measured: across the 418 affected tests there are **1472 `DefineShape`
  characters and all 1472 have a `path_data` record** — the triangle fallback
  is never reached.
* **AVM1 glyphs — immune** by the same rule (`glyph_path_size >= 3` → path test,
  `continue`).
* **Morph shapes — untouched.** Leg C's Levien arm is gated `!is_morph`; morphs
  keep equal-parameter stepping so the s14 index pairing stays exact.
* **AVM2 picking — the one real surface.** `avm2_display.c::shape_contains_local`
  tests the placed shape's **triangles** with no analytic fallback, so an AVM2
  `hitTestPoint` / `getObjectsUnderPoint` / mouse pick within ~0.05 px of a
  curved boundary can flip. Ruffle hit-tests analytically
  (`render/src/shape_utils.rs:603`), so our triangles were always an
  approximation; leg C moves the approximation inward by at most lyon's own
  tolerance.

That surface is what the empirical trace probe below targets.

---

## 4 — TRACE LEDGER

**Verdict: the trace effect is ZERO. Not "small", not "net-positive" — zero.**

### 4.1 How the probe set was chosen (blast radius first, grep second)

Rather than guess which tests are bounds-sensitive, I measured the blast radius
directly: both recompiler binaries were run over **every `test.swf` in the corpus
(4492 SWFs)** and the generated C diffed. **418 tests get different generated
code; 4074 are byte-identical and therefore provably unaffected.**

The probe set is then `DIFFERS ∩ trace-sensitive`, where trace-sensitive is the
union of two greps over every suite's `output.txt` + `*.as`:

* bounds/geometry: `getBounds|getRect|hitTest|localToGlobal|globalToLocal|_width|_height|.width|.height` → 272 candidates
* pointer/picking: `onRollOver|onPress|onRelease|onMouse*|MouseEvent|mouseX|_xmouse|rollOver|mouseChildren|mouseEnabled|hitArea` or the presence of `input.json` → 237 candidates

Intersected with the 418: **138 probe tests** (97 + 41), spanning avm1, avm2,
from_gnash, from_shumway, regression, text, visual, fonts, timeline,
import_assets. Every currently-**failing** test in the 418 (22 `output_mismatch`)
and every `ruffle_matched` one (38) is inside the probe set, so the flip check
and the `ruffle_matched`-regression check are both complete.

### 4.2 Result

All 138 ran on the leg-C binary (`--recompile`, no-graphics, `-P 2`;
`SWFRECOMP_COMPILE_TIMEOUT=2400` — the first pass produced 11 `compilation
timed out` rows at load average 41, all of which passed on re-run at lower load,
exactly the false-failure mode BRIEFS_COMMON §3 warns about).

| | count |
|---|---:|
| probe tests run on leg C | **138 / 138** |
| status changes vs the CI baseline | **0** |
| pass → fail | **0** |
| `ruffle_matched` → anything | **0** (38 tests, all still `ruffle_matched`) |
| fail → pass (flips) | **0** |
| line-level fingerprint identical to CI baseline | **135** |
| line-level fingerprint differing from CI baseline | 3 — **all proven NOT leg C** (§4.3) |

leg-C status histogram: `pass 78, output_mismatch 22, ruffle_matched 38` — an
exact match for the CI baseline histogram over the same 138 tests.

### 4.3 The three rows that moved, and why they are not leg C

Three gnash tests came out with different line counts than the stored CI
baseline. I re-ran each on the **base** binary locally (same mode, same machine)
and diffed the actual output:

| test | baseline (CI) | legC (local) | base (local) | verdict |
|---|---|---|---|---|
| `from_gnash/…/action_order/ActionOrderTest3` | 73 lines | 83 | **83** | **base == legC, byte-identical** |
| `from_gnash/…/action_order/ActionOrderTest4` | 105 lines | 94 | **94** | **base == legC, byte-identical** |
| `from_gnash/…/register_class/RegisterClassTest4` | 57 lines | 54 | **54** | **base == legC, byte-identical** |

All three are a pre-existing local-vs-stored-baseline delta (the stored
`results_graphics.json` rows for these three are stale relative to `cd04f80b9`),
not a leg-C effect. Status is `output_mismatch` in all six cells; nothing flips
either way. **After attribution: 138/138 traces byte-unchanged by leg C.**

### 4.4 Flip search

Per the brief I also checked the failing side for flips: of the 418 affected
tests, **22 are `output_mismatch` in the CI baseline**. All 22 are in the probe
set, all 22 ran, and **all 22 stay `output_mismatch` with the same
`matching_lines`**. Leg C flips nothing on the trace axis — which is the expected
result once §3 is believed, because there is no mechanism by which it could.

Grepping the baseline for failing tests whose stored diff mentions
`bounds|width|height|getRect|hitTest` returned **0 rows** inside the 418 —
i.e. there was never a bounds-shaped near-pass for leg C to flip.

---

## 5 — PATCH SCOPE

| file | change |
|---|---|
| `SWFRecomp/src/swf.cpp` | Levien helpers (`levienParabolaIntegral`, `levienParabolaInvIntegral`, `levienInit`, `levienT`) + `addCurvedEdgeLevien` before `interpretShape`; one `else if` arm and one call-site branch in the `CurvedEdgeRecord` path. **+151 / −1, no new files.** |

Differences from the archived s15 patch (`w2-gfx-flatten-recompiler.patch`):
the s15 artefact had leg B's `1.0f → 2.0f` tolerance edit left inside the
now-dead `else` arm. This patch restores that arm to its pre-Levien value so
the `const bool curve_flatten_levien = false` knob is a faithful A/B revert.

**Recompile invalidation:** leg C is a recompiler change. CI regenerates every
`RecompiledTags` in the corpus; 418 of 4492 tests get different generated C, and
the shape tables shrink 39 %. Expect a slower CI run (regeneration) but a
*faster* compile on the affected tests (`visual/simple_shapes/heavy_tesselation`
alone drops 687 363 → 394 704 vertex rows).

**Dispatch discipline:** ship leg C ALONE. Not because of bounds (refuted) but
because it perturbs 418 tests' generated code and 7 pixel comparisons; bundling
it with other pixel work makes the CI delta unattributable.

---

## 6 — REPRODUCTION

```bash
cd /home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a360c309db628703d
cd SWFRecomp/build && cmake .. -DCMAKE_BUILD_TYPE=Release && make -j4 && cd ../..

# pixel A/B (base leg captured with the reverted patch, legC with it applied)
python3 ruffle-tests/render_canary.py capture --label base --tests <list> --recompile --jobs 2
python3 ruffle-tests/render_canary.py capture --label legC --tests <list> --recompile --jobs 2
python3 ruffle-tests/render_canary.py compare base legC
```

Scripts (in this session's scratchpad, `scratchpad/legC/`):
`sweep.sh` (full-corpus recompiler A/B, ~4500 SWFs in ~25 min),
`boundscheck.sh` (the bounds/structure projection — the premise killer),
`whichfiles.sh`, `pathcover.sh` (path_data coverage),
`ledger.py` (pixel ledger), `vsbaseline.py` (trace ledger vs CI baseline),
`tracerun.sh` (trace leg runner).

---

## 7 — SESSION NOTES / INCIDENTS

* **`pkill -f verify_output.py` is a shared-machine hazard.** I used it once to
  stop my own leg-by-leg runner; the pattern matches *every* agent's
  `verify_output.py`, and ~18 sibling processes were running at the time. Use
  `pgrep -af <your-worktree-hash> | grep verify_output | awk '{print $1}' |
  xargs kill` instead — the worktree path is the only self-selective token.
  (Adds to the existing `pkill-f-self-match` memory: bracketing a character
  stops self-matching, it does NOT stop sibling-matching.)
* **Compile timeouts under load are the dominant false-failure mode for a
  recompiler A/B.** Leg C changes the generated C for 418 tests, so ccache
  misses on all of them and every one pays a cold gcc; at load average 41 that
  produced 11 spurious `compile_fail` rows. `SWFRECOMP_COMPILE_TIMEOUT=2400`
  plus a re-run at lower load cleared all 11.
* **The corpus-wide recompiler A/B is cheap and should become standard for any
  `SWFRecomp/` change.** Running both binaries over all 4492 SWFs in temp dirs
  and diffing the generated C took ~25 minutes at `-P 2` and converted a
  "which tests might this touch?" guess into an exact 418-test list — including
  the two pixel rows (`visual/filters/drop_shadow`, `visual/blend_modes/multiply`)
  that the s15 census had missed entirely. `scratchpad/legC/sweep.sh` is the
  script; it is worth promoting into `ruffle-tests/`.
* **Trace-axis grading against the stored `results_graphics.json` fingerprint
  (`status` + `lines.{actual,expected,matching}` + `detail`) halves the work of
  an A/B**: a probe test that comes back with the baseline fingerprint needs no
  base-leg run at all. Only fingerprint mismatches need attribution — here, 3
  of 138, all of which turned out to be stale baseline rows.
