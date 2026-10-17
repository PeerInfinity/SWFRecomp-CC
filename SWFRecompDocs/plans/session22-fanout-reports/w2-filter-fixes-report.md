# w2-filter-fixes — session 22, wave 2 (cloud, implementation)

Slot `w2-filter-fixes`, branch `fanout/w2-filter-fixes`, base `origin/master` `c2ace7d40`.
Corpus: `download_tests.sh avm1 avm2 visual from_shumway fonts text` from upstream Ruffle master
`45366370e` (= the coordinator's sync). Box: cloud lavapipe, `SETUP_STATUS` all OK.

**Files delivered**
- NEW `SWFRecompDocs/plans/session22-fanout-reports/w2-filter-fixes-report.md` (this file)
- NEW `SWFRecompDocs/plans/session22-fanout-reports/w2-filter-fixes.patch`
  (`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py
  ruffle-tests/render_canary_tests.txt SWFRecompDocs/plans/graphics-fanout-playbook.md`;
  regenerated after the last edit; `git apply --check -R` OK on the branch, `git apply --check`
  OK on clean `c2ace7d40`).
- No new source files, no new fixture dirs. `verify_output.py` is unchanged.
- Modified: `SWFRecomp/src/swf.cpp`, `SWFModernRuntime/src/libswf/tag.c`,
  `SWFModernRuntime/src/avm2/avm2_display.c`, `SWFModernRuntime/src/rendering/render_webgpu.c`,
  `SWFModernRuntime/include/libswf/tag.h`, `SWFModernRuntime/include/rendering/{render_webgpu.h,renderer.h}`,
  `ruffle-tests/render_canary_tests.txt` (EOF append), `SWFRecompDocs/plans/graphics-fanout-playbook.md`
  (§17 disposition struck).

---

## 0. Verdict: GO, +3 pixel flips, 0 regressions, 0 trace moves

| test (comparison) | BEFORE (clean origin/master) | AFTER (this patch) | margin after |
|---|---|---|---|
| `visual/filters/any_blur_scales_with_screen` (output) | FAIL, 4884 outliers (tol 2, max 0), max diff 255 | **PASS**, 0 outliers, max diff **1** | tol 2: 1 LSB headroom |
| `visual/cache_as_bitmap/cab_mask_filters` (output) | FAIL, 612 outliers (tol 4, max 0), max diff 255 | **PASS**, 0 outliers, max diff **3** | tol 4: 1 LSB headroom |
| `from_shumway/acid/acid-filter-2` (output, 2 checks) | FAIL: tol 5 → 5084 / 2500; tol 20 → 2986 / 0; max diff 64 | **PASS**: tol 5 → **2012 / 2500**; tol 20 → 0 / 0; max diff **15** | 488 outliers on the tol-5 check; 5 LSB on tol 20 |

Trace status of all three: pass → pass (graphics and no-graphics).

**Fidelity: CI-grade.** The BEFORE PNG of all three rows is byte-identical to CI's actual PNG on
`origin/ruffle-image-results` (md5 `dd43794c…`, `0ffd6864…`, `84c9d240…`), so these grades are
what CI will compute, not just an A/B.

### EXPECTED-FLIP LEDGER (for the coordinator's CI check)

- **Pixel axis (images run): fail → pass**
  - `visual/filters/any_blur_scales_with_screen` `output`
  - `visual/cache_as_bitmap/cab_mask_filters` `output`
  - `from_shumway/acid/acid-filter-2` `output`
- **Trace axis: no expected moves.** All 144 tests kept their trace status in both legs.
- Any other pixel or trace move is unexpected: 206 / 209 comparisons are md5-identical.

---

## 1. What the patch does (prototype → production)

It productionizes `w1-offstage-filter-prototype.patch`, the diagnosis of record in
`w1-offstage-filter-report.md` §1.1–1.3. The rendered output is byte-identical to the prototype's on
all three flip rows (same md5 class and the same max diffs as reported in w1). The padded filter layer
(w1 §1.4) is **not** implemented (HOLD until stroke parity). The pad-hack measurement patch is
**not** included.

### 1.1 PlaceObject3 `Visible` (SWF ≥ 11)
- `swf.cpp` root arm (~4510) and DefineSprite arm (~6007): the arms used to skip the Visible
  byte. They now read it and emit `tagSetVisible(app_context, depth, v)` after the placement, only
  when `header.version >= 11` (Ruffle `display_object.rs:2592`).
- `tag.c` `tagSetVisible` (new, next to `tagSetCacheAsBitmap`) sets `display_list[depth].as_hidden`.
  That is the flag AS `_visible` drives, and a fresh placement resets it (`tag.c:~12019`).
- `tag.c` `tagRerenderFrame` now has the same `clip_depth == 0 && as_hidden` skip that `tagShowFrame`
  has. This loop produces every graded final capture.

### 1.2 Compose-into-offscreen primitive (`render_webgpu.c`)
- `compose_layer_pipeline` is the `compose_pipeline` twin with **sample count 1 and no
  depth-stencil, by design**: its target `filter_tex_b` is the single-sample, stencil-less filter
  texture. A comment at the creation site and in the struct says it is not a stand-in for
  `MSAA_SAMPLES`. Every MSAA-target pipeline still uses `MSAA_SAMPLES`. The pipeline is released in
  `render_webgpu_free`.
- `render_webgpu_compose_filter_to_layer` composes into `filter_tex_b` over a transparent clear,
  then copies the result to `filter_tex_a`. `filter_tex_b` was already the blur's own scratch, so
  this adds no new aliasing hazard with the blend-mode backdrop.
- `renderer_compose_filter_to_layer` macro, with a `((void)0)` NO_GRAPHICS arm.

### 1.3 Non-final composed filters in a chain (AVM1 tag route + AVM2 `.filters`)
- `tag.c` `build_filter_chain`: the "EXPRESSIBILITY GATE" loop (it collapsed chains with a
  compositeSource / inner / knockout non-final member to their first filter) is **deleted**.
  Every type 1–4 chain is rendered as-is, and the comment is rewritten.
- `tag.c` `render_filtered_object` loop: a non-final glow / shadow / bevel snapshots the layer
  as its source, blurs at strength 1 with no colorize, then `compose_chain_entry_to_layer` (new
  static helper) composes it into the layer. It uses the same flag decoding, nearest-offset rounding
  and A3 cxform as the final-filter path. The `colorize` shortcut is no longer reachable from either
  route, so both call sites pass `0`.
- `avm2_display.c` `avm2_render_filtered`: `chained = (n > 1)`. Draw-source shortcuts are off and
  the source is snapshotted for the LAST filter inside the loop. Non-final composed filters go
  through the new `avm2_filter_one_in_place` (static helper above `avm2_render_filtered`). This
  closes s16's "AVM2 `.filters` loop composites the crisp object / drops a non-final
  compositeSource" defect. No AVM2 image row has such a chain, so it is correctness-only today.

### 1.4 AVM2 alpha-mask arm
- `avm2_render_alpha_masked`: after the masker layer is drawn (filters suppressed, since the filter
  ping-pong cannot be re-entered), the masker's OWN filter list runs in place on the layer
  (`avm2_filter_layer_in_place`) before it is snapshotted as the mask, as in Ruffle's
  `m.render_with_options`. The stale "completion mechanism: compose-into-offscreen pipeline"
  comment is rewritten.

### 1.5 Removed from the prototype
- Both A/B switches, `getenv("SWF_NO_CHAIN_LAYER")` (tag.c ×2, avm2_display.c ×1) and
  `getenv("SWF_NO_MASK_FILTERS")`. `git diff | grep getenv` finds nothing.
- The prototype's `do { … } while (0)` in-place helper is rewritten with early returns.

### Sibling localisation
- `swf.cpp`: only the PlaceObject3 Visible parse/emit lines. No stroke/fill geometry (that is
  `w2-float-verts`'s area).
- `tag.c`: `build_filter_chain` tail, the new static `compose_chain_entry_to_layer` above
  `render_filtered_object`, the chain loop, one line in `tagRerenderFrame`, and `tagSetVisible`.
  `compute_mc_world_xform` and `cab_snap_world` (w2-default-fonts-draw) are not touched.
- `avm2_display.c`: new static helpers directly above `avm2_render_filtered`, plus edits inside
  `avm2_render_filtered` and `avm2_render_alpha_masked` only.

---

## 2. Evidence

### 2.1 md5 A/B (render_canary, `--recompile` on both legs, cloud lavapipe)
The set is the union of:
- the w1 A/B set, reconstructed by a SWF scan: every image test whose SWF has a PlaceObject3
  filter list, a PlaceObject3 `HasVisible`, a `Filter`/`filters` string or a `_visible` string,
  plus the 4 trace-only chain tests `avm2/{bevel,drop_shadow,glow}_filter` and
  `from_shumway/avm1/filters`. That is 101 tests. w1 had 102; the scan list was not archived, and
  the one-row gap is scan noise, since the standing set covers the regression rows.
- the **full standing canary set** (`render_canary_tests.txt`, all tiers, 61 tests).

Union: **144 tests / 209 comparisons**. BEFORE = clean `origin/master` `c2ace7d40` with the recompiler
built at that SHA. AFTER = this patch with the recompiler rebuilt.

```
IDENTICAL 206   DIFFERS 3   APPEARED 0  VANISHED 0  NO_RENDER 0
from_shumway/acid/acid-filter-2            fail -> pass  bbox (21,20)-(319,200)
visual/cache_as_bitmap/cab_mask_filters    fail -> pass  bbox (23,3)-(74,37)
visual/filters/any_blur_scales_with_screen fail -> pass  bbox (100,10)-(151,61)
TRACE STATUS CHANGES: (none)
```

So the `tagRerenderFrame` `as_hidden` skip moves no AS-hidden capture in the standing set or the
filter / `_visible` set, beyond the ledger row.

### 2.2 Regression suite
- All 8 `regression/` image rows in the set are md5-IDENTICAL with trace unchanged:
  `avm2_graphics_runtime`, `avm2_morph`, `avm2_parent_child_render`,
  `avm2_timeline_{gradients,solid,stroke_gradient}`, `mask_nested_intersect`, `mask_sibling_union`.
- `regression/avm1_display_prop_coercion` (the only regression SWF with a `_visible` string) PASSES in
  both no-graphics and graphics mode.
- No new fixture. Each new behaviour has a corpus image test whose golden comes from outside
  SWFRecomp (the three ledger rows).

### 2.3 Mode parity (tag.c is shared)
No-graphics, `--recompile`: `any_blur_scales_with_screen`, `cab_mask_filters`, `acid-filter-2`
and `from_shumway/acid/acid` (the only other SWF with a PO3 `HasVisible`) all PASS. That shows
`tagSetVisible` links and the NO_GRAPHICS `renderer_compose_filter_to_layer` is a no-op.

### 2.4 Canary list
The three flips are appended at EOF of `render_canary_tests.txt` under a new `# tier=2` header
(one comparison each; `acid-filter-2` has two checks on one comparison).
`load_test_list(..., '2')` parses them. Before this, no standing member saw PO3 Visible,
alpha-mask filters or a composed non-final chain.

### 2.5 Docs
In `graphics-fanout-playbook.md` §17 ("Image-axis dispositions added this session"), the s16
`any_blur_scales_with_screen` "Won't-fix (Ruffle divergence)" entry is struck through, with a
one-line pointer to this report. The §17 narrative sentence that referenced it got a parenthetical
"struck in s22".

---

## 3. Residuals and risks (none block the ledger)

- **AS read-back of PO3 Visible.** `tagSetVisible` sets the render flag (`as_hidden`) only. An AS
  `_visible` / AVM2 `visible` read of a PO3-hidden object still returns `true`. No corpus test
  reads it (only 2 SWFs in every downloaded category carry PO3 `HasVisible`, and both pass trace).
  Completion mechanism: if a trace row ever needs it, mirror the value into the MC's `_visible` at
  placement.
- **Masker descendants' filters** are still suppressed in the AVM2 alpha arm. Only the masker's
  own list runs. No corpus row needs more.
- **Displacement maps** in a masker list are skipped (they need the object rect).
- **Fragility**: `cab_mask_filters` and `any_blur` each pass with 1 LSB of headroom. Any
  render-wide AA change (for example, sibling `w2-float-verts` stroke geometry) can re-fail them.
  The canary tier-2 entries will show it.

## 4. Not done (by brief)
- Padded / object-sized filter layer (w1 §1.4): **HOLD**. Completion mechanism: fund it after
  `w1-stroke-staircase` / `w2-float-verts` land and bring `drop_shadow_angles` to roughly ≤ 600
  outliers. The design is in w1 §1.4.
- `w1-offstage-filter-padhack.patch`: a measurement tool, not landed.

## New unclaimed leads
- **L1** (from w1, still open): audit the other s16 "Ruffle renders nothing" image dispositions
  for SWF-level visibility (PO3 `Visible`, `_visible`) before they are believed.
- **L2**: PO3 Visible → AS-visible read-back (see §3), if a trace row ever needs it.
- w1's L2/L3/L4 (`bitmapdata_draw_filters`, `applyfilter_destpoint_edges`, the
  `tagRerenderFrame`/`tagShowFrame` loop drift audit) are unchanged and unclaimed.

## LOCAL ORACLE REQUESTS

none
