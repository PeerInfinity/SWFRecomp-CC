# w2-padded-filter: session 23, wave 2 (cloud, IMPLEMENTATION)

Slot `w2-padded-filter`, branch `fanout/w2-padded-filter`, base `origin/master` **`069b408f`** (includes
`7e2a045c1`). Corpus: `download_tests.sh visual avm1 avm2 fonts from_shumway text`, upstream Ruffle master on
2026-11-21 (the script prints no SHA; same day as w1's `0ddd12b6a`). `SETUP_STATUS`: apt, Pillow, Dawn all OK;
graphics runs use Dawn on lavapipe.

**New files:**
- `SWFRecompDocs/plans/session23-fanout-reports/w2-padded-filter-report.md` (this file)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-padded-filter.patch`
  - `= git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`
  - Proven with `git apply --check -R` on the branch.

No new source files and no new fixtures. The patch touches:
- `SWFModernRuntime/include/rendering/{render_webgpu.h,renderer.h}`
- `SWFModernRuntime/src/rendering/render_webgpu.c`
- `SWFModernRuntime/src/libswf/tag.c`
- `SWFModernRuntime/src/avm2/avm2_display.c`
- `ruffle-tests/render_canary_tests.txt` (2 members appended at EOF)

---

## 0. Verdict: GO, +2 pixel flips, 0 regressions

### EXPECTED-FLIP LEDGER (the coordinator checks CI against this)

| axis | test | expected CI move | local (CI-grade, see §2) |
|---|---|---|---|
| pixel | `visual/filters/drop_shadow_angles` | **fail → pass** | 549/0 max 51 → **0/0 max 1** |
| pixel | `visual/filters/displacement_map` | **fail → pass** | 408/72 max 127 → **24/72 max 101** |
| pixel | `visual/filters/displacement_map_scales_with_screen` | pass → pass (md5 moves) | 0/0 max 1 → 0/0 max 1 (83 ch ±1 LSB) |
| trace | none | no trace move in either mode | tag.c also builds in no-graphics; `renderer_set_filter_pad` is `((void)0)` there; the 2 headline rows trace-PASS in both modes |

Nothing else may move. Any other pixel md5 move in the A/B set (§3) is unexpected.

---

## 1. What landed (w1 §2.4 items 1–5)

1. **Prototype landed** on current master. The hunks applied cleanly over `7e2a045c1`.
   - The `SWF_FILTER_PAD` env override was removed.
   - All before-renders below were taken on `069b408f`.
2. **The AVM1 driver is gated.**
   - New `tag.c filter_capture_needs_pad`. Root entries are flagged by `render_filtered_root_entry` (`g_filter_root_entry`).
   - The device rect comes from `opaque_bg_local_bounds` × `ng_entryTransformData(obj)[ng_get_original_transform_id(obj)]` × `app_context->stage_to_ndc`, the same NDC→px mapping as `avm2_filter_screen_rect`.
   - **Pads unconditionally when the world is unknown**:
     - a nested entry (`compose_children` arm);
     - `_root` `as_set_flags`;
     - a root sprite/button whose MovieClip has AS-set transforms (its slot is stale; the compose loop builds the matrix on the stack);
     - no bounds.
3. **P is sized from the growth.**
   - `render_webgpu_set_filter_pad(ctx, double growth_px)`: P = ceil(growth/16)·16, clamped to [16, 128].
   - The growth is the **whole chain's** reach:
     - blur window × pass scale;
     - shadow/bevel distance;
     - gradient blur + distance;
     - convolution half-kernel;
     - (AVM2) displacement |scale|/2;
     - plus 2 px.
4. Re-ran the 118-test A/B, the standing canary and the regression suite (§3). **The bar is met exactly.**
5. Appended `visual/filters/drop_shadow_angles` and `visual/filters/displacement_map` at EOF of
   `render_canary_tests.txt`, under a `# tier=1 (CI-passing once w2-padded-filter lands)` block. Line format checked
   (`suite/test  # comment`).

### 1.1 Two changes beyond w1 §2.4. Both were found by this A/B; read these.

**(a) BUG in the w1 design once P varies: a shared padded-matrix buffer.**
- The prototype had one `pad_stage_buf`, written with `wgpuQueueWriteBuffer`.
- Queue writes are **frame-ordered, not encoder-ordered**. Two padded captures in one frame with *different* P therefore both
  render with the LAST matrix written.
- At fixed P=64 every write was identical, so w1 never saw it. With growth-sized P, the first full A/B regressed three CI-passing rows:

  | row | before → buggy build | ch, max diff |
  |---|---|---|
  | `glow_pass_scaling` | pass → fail | 17001 ch, max 255 |
  | `blur_pass_scaling` | pass → fail | 69147 ch, max 244 |
  | `displacement_map_through_filters` | pass → fail | 19020 ch, max 255 |

- **Fix:** one lazily created resource set **per P bucket** (`WebGPURenderContext.pad_sets[8]`, a trailing struct field). Each set has its own textures,
  `stage_buf` and `vertex_uniform_bg`. Within a bucket the matrix depends only on the stage matrix, which is frame-constant.
- Side benefit: mixed-P frames no longer reallocate textures every frame. The sets are also recreated on a stage resize (`w/h` check).
- After the fix all three rows are md5-identical to master.

**(b) Gate margin = reach of the filters BEFORE the last one**, not the whole grown rect.
- `bevel`'s bottom row of objects lies on-stage (device y ≤ 633.4 of 650). Only its glow's grown rect crossed, so the grown-rect gate padded it.
  The result was 37 ch of ±1 LSB churn, status unchanged.
- Argument: a filter's input is the object's layer, or for a chain, the layer grown by the filters before it.
  - A **single** filter over an on-stage object has no off-stage source pixel. Its off-stage halo is invisible, so the pad changes nothing but LSBs.
  - Displacement samples only inside the object's own rect (transparent outside), so its reach sizes P but never triggers it.
- The gate margin is therefore:

  | n | margin |
  |---|---|
  | n = 1 | 2 px AA (+1 px for the cacheAsBitmap snap on AVM1) |
  | n > 1 | `reach(chain[0..n-2])` + 2 px |

- The same rule applies in both drivers (`avm2_filter_reach_px(list, n-1, vs, 0)` / `filter_chain_reach_px(chain, n-1, vs)`).
  `bevel`, `bevel_inner`, `bevel_full` and `bevel_outer` are md5-identical to master again.

---

## 2. Fidelity (CI-grade)

`origin/ruffle-image-results` is still at `35f66723`, run **`38995363802`** (s22 final, pushed 2026-10-17). The s23
baseline images run `44922638965` had **not** force-pushed it at the time of my fetch.

| row | my before md5 (`069b408f`) | CI actual md5 | verdict |
|---|---|---|---|
| `drop_shadow_angles` | `4bbc9f48` | `4bbc9f48` | identical: CI-grade |
| `displacement_map` | `3e0b7c9f` | `3e0b7c9f` | identical: CI-grade |
| `bevel` | `af91e3f2` | `134c3e91` | differs: expected, `7e2a045c1` moved its "Knockout"/"Out" labels (744/6 now, 750/6 at s22) |

Both headline rows are CI-grade. Their after-grades (0/0 and 24/72) are CI predictions, not just A/B.

## 3. Per-test before/after (clean `069b408f` vs patch, same box, graphics)

| test | before | after | md5 |
|---|---|---|---|
| `visual/filters/drop_shadow_angles` | FAIL 549/0, max 51 | **PASS 0/0, max 1** | `4bbc9f48`→`dea17f00` (= w1 prototype and the s22 pad hack) |
| `visual/filters/displacement_map` | FAIL 408/72, max 127 | **PASS 24/72, max 101** | `3e0b7c9f`→`ad67ac9f` |
| `visual/filters/displacement_map_scales_with_screen` | PASS 0/0, max 1 | PASS 0/0, max 1 | moves (83 ch, max 1; w1 measured 3 ch at P=64) |
| `visual/filters/bevel` | FAIL 744/6 | FAIL 744/6 | identical (w1 prototype: 66 ch LSB) |
| `visual/filters/displacement_map_through_filters` | PASS | PASS | identical |
| `visual/filters/glow_pass_scaling` / `blur_pass_scaling` | PASS | PASS | identical |
| `visual/filters/empty_child_filter_bounds` | FAIL 72840/0 | FAIL 72840/0 | identical (§5) |

### A/B: `render_canary.py`, before = clean `069b408f` (git worktree), after = patch, `-P 2`
Set: all 87 standing `render_canary_tests.txt` members, plus every `visual/filters/*` and `visual/cache_as_bitmap/*` image test.
That is 118 tests / 175 PNGs, including the 6 `regression/` members.
```
IDENTICAL 172   DIFFERS 3   APPEARED/VANISHED/NO_RENDER 0
TRACE STATUS CHANGES: (none)
DIFFERS: displacement_map (fail->pass), drop_shadow_angles (fail->pass),
         displacement_map_scales_with_screen (pass->pass, 83 ch, max 1)
```
This is exactly the bar's allowed set, `{drop_shadow_angles, displacement_map, displacement_map_scales_with_screen}`.

### Regression suite
- The other 7 `regression/` image tests, not already in the set, were run as a separate A/B:
  `avm1_parent_child_{bitmap_fill,morph,render,text}`, `avm2_parent_child_render`, `avm2_timeline_solid`, `bitmap_pool_layer_cap`.
  Result: **7/7 IDENTICAL**, all pass.
- So all 13 regression image tests are md5-identical. No regression fixture uses filters.
- No new fixture: the behaviour is covered by the two corpus rows, which are now canary members.

### Mode parity
- `tag.c` also builds in no-graphics. The gate calls only no-op renderer macros there, and its fields exist on `FlashbangContext` too.
- `drop_shadow_angles` and `displacement_map` trace-PASS without `--mode=graphics`.

## 4. Cost / risk notes
- Extra GPU work applies **only** to edge-crossing (or unknown-world) filtered captures. The blur/ping-pong area grows by (1+2P/W)(1+2P/H).
- Memory: up to 8 lazily made padded sets, each 3 colour + 1 MSAA + 1 DS texture of (W+2P)×(H+2P). A typical frame uses 1–2 buckets.
- P is capped at 128. A chain whose reach exceeds 128 px gets a partial pad: still better than master, not exact.
- Unknown-world entries always pad. These are AVM1 nested filtered entries and filtered root sprites with AS-set transforms.
  - They see the ±1 LSB NDC-scale artifact w1 §1.4 predicted.
  - None of the 118 A/B rows moved from it, including `contains_grown_filter`, `blur_scales_with_screen` and `acid-filter-2`.
- Bounds come from `opaque_bg_local_bounds`. If that under-reports (e.g. drawing-API content on a root sprite), the gate stays off and the
  row keeps exactly master's behaviour. That is a missed flip, never a regression.

## 5. Lead N1 priced (`visual/filters/empty_child_filter_bounds`, 72840/0)
- **Not a filter or bounds defect.**
  - I patched the SWF's constant pool `filters\0` → `filterz\0`, which removes both `.filters` assignments (one occurrence; SWF 8, FWS).
  - Result: still **72840/0, the same render**: one unscaled, opaque black two-rect shape at the stage origin.
  - The golden has two 40%-alpha, 2x-scaled, blurred shapes at x=60 and x=320.
- So the defect is an AVM1 **dynamic-clip transform/alpha inheritance** gap.
  - The test calls `_root.createEmptyMovieClip(clip)`, then `clip.createEmptyMovieClip(part)` with drawing-API rects, then sets
    `clip._x/_y/_xscale/_yscale/_alpha` **after** the children are drawn.
  - The parent's properties never reach the grandchildren. Both clips' parts land at the same local coordinates.
- Owner: around `tag.c apply_dynamic_mc_transforms` and the dynamic-MC Drawing-API render route, not the filter path.
- Price: likely 1 pixel flip **only if** the blur on dynamic clips then also matches. Unmeasured. HOLD for a dynamic-clip slot.
- Completion mechanism: a wave-1 diagnosis of nested dynamic-clip world composition. The cheap A/B is the patched `filterz` SWF
  (recipe above; patch in Python, no compiler needed).

## 6. Not finished
- Nothing from §2.4 is open.
- The CI confirmation of the two flips is the coordinator's run: `graphics`, `categories=all`, `images=true` or a single-test check.
  - Note: `single_test` resolves bare names against avm1 only, so these visual rows need a categories run.

## New unclaimed leads
- **N1** as priced in §5: AVM1 nested dynamic-clip transform/alpha inheritance. Not filters.
- **Pad-cap residue:** chains with reach > 128 px are only partially padded. No corpus row measured needs more; raise
  `FILTER_PAD_MAX` if one appears.
- **Unknown-world AVM1 entries** (nested and AS-moved root sprites) pad unconditionally. If a future row shows ±1 LSB churn from it,
  compute the nested world (the `compose_children` parent matrix) and gate those too.

## LOCAL ORACLE REQUESTS
None new. w1's bevel y=305 request (w1 report §1.3) still stands and is unaffected by this patch: bevel is md5-identical.
