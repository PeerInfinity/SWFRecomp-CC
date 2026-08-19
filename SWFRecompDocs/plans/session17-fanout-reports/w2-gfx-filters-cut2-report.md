# w2-gfx-filters-cut2 — session 17, wave 2 (PIXEL axis)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-abda62ea3dca0b91b`
Base `88ebde665`. Grading baseline: CI run `31877239992` at `aeebf9ede`
(`origin/ruffle-image-results` index generated 2026-08-15).
Brief of record: s16 `w2-gfx-filters-report.md` §8.6 ("remaining filters upside:
the displacement trio") + `wave1-gfx-filters.md` §5 trap 1 / §6 cut 2.
No commits, no pushes, no main-tree source edits.

---

## 0. NEW FILES CREATED BY THIS PATCH — **NONE**

`w2-gfx-filters-cut2.patch` touches seven **tracked** files, creates none, and
deletes none. The coordinator can stage by name:

| file | + / − | what |
|---|---|---|
| `SWFModernRuntime/include/avm2/avm2_filters.h` | +9 | `Avm2FilterVal.map_bitmap` (held by identity, like `shader`) |
| `SWFModernRuntime/src/avm2/avm2_filters.c` | +13 | populate it, GC-mark it, null it for tag filters |
| `SWFModernRuntime/include/rendering/render_webgpu.h` | +33 | 7 trailing `WebGPURenderContext` fields + one prototype |
| `SWFModernRuntime/include/rendering/renderer.h` | +3 | `renderer_run_displacement` (WebGPU arm + `((void)0)` twin) |
| `SWFModernRuntime/src/rendering/render_stub.c` | +1 | no-GPU twin |
| `SWFModernRuntime/src/rendering/render_webgpu.c` | +360 | `displace_wgsl`, lazy pipeline, map upload, the pass, release |
| `SWFModernRuntime/src/avm2/avm2_display.c` | +102 | object screen rect + the displacement arm in the cut-1 loop |

**521 inserted, 0 deleted.** Runtime-only — no `SWFRecomp/` change, so no
recompiler rebuild and no `--recompile` needed on merge.

---

## 1. Verdicts

| item | verdict | measured |
|---|---|---|
| **Cut 2 — GPU `DisplacementMapFilter` on the `.filters` render arm** | **GO, ship** | **+2 flips, both at 0 outliers**: `displacement_map_through_filters` 27 565 → **0** (max 2 vs tol 4); `displacement_map_scales_with_screen` 99 353 → **0** (max 1 vs tol 4) |
| **`visual/filters/displacement_map` (the brief's loosest-budget target)** | **NO-GO as a flip — and the reason is NOT displacement** | 123 378 → **20 655** (−83.3 %), but the **no-map control tile is byte-unchanged at 2 956** (§4.2). Every displaced tile now sits on that same floor. Completion mechanism: fix `TestImage`'s own edge rendering, not the filter |
| **`visual/cache_as_bitmap/cab_mask_filters` "if it falls out"** | **NO — it does not fall out** | 4 968 → **4 968**, byte-unchanged. It is filters on a **masker**, which cut 1 deliberately suppresses (`g_avm2_mask_capture == 0`); cut 3(b) owns it |
| **`visual/filters/blur_scales_with_screen` "only if the same plumbing fixes it"** | **NO — say so, as the brief asked** | 30 810 max 40 → **30 810 max 40**, byte-unchanged. It is the AVM1 **tag** route inside a `DefineSprite` (s16's `tag.c` arm), shares no code with the uniform plumbing |
| **Trap 1 ("object-sized FilterSource binds only for displacement")** | **CONFIRMED, and it is the whole cut** | the object screen rect as a uniform + rect-local wrap/clamp is what takes two rows to **zero**; the stage-sized machinery underneath is untouched |
| **Canary / collateral** | **ZERO regressions, both axes** | canary 16 tests / 20 comparisons: **20 IDENTICAL, 0 DIFFERS**, 0 APPEARED / 0 VANISHED / 0 NO_RENDER, no trace status changes (§6). Family sweep on top of that: 4/4 remaining CI-passing `visual/filters` rows still pass, 13/13 `avm2/*filter*` trace rows still pass (§6.1) |

**Net priced for the merge batch: +2 comparisons, both at 0 outliers locally,
0 regressions.**

### Refutations

1. **The brief's implicit "+3 (the displacement trio)" is +2.** `displacement_map`
   is blocked by a defect that has nothing to do with displacement: its
   *first* tile has `new DisplacementMapFilter()` with **no map bitmap**, so no
   filter runs at all, and that tile is **2 956 outliers before and 2 956 after**
   — the exact per-tile floor the other six tiles now sit on. The map bitmap
   itself is fine (the unfiltered 200×200 gradient the test also puts on stage
   is **0 outliers, max 2**).
2. **`cab_mask_filters` does not fall out of cut 2.** Wave-1 already put it in
   cut 3; this measurement confirms it at byte level.
3. **`blur_scales_with_screen` is not reachable from this plumbing.** Named
   explicitly because the brief asked for a yes/no.
4. **Filters cut 1's `quality == 0` skip would have silently deleted the entire
   kind.** AS3 `DisplacementMapFilter` has no `quality` property, so
   `Avm2FilterVal.quality` is 0 for every one of them. The displacement arm has
   to be checked *before* the shared gate. This is the trap that costs a build
   cycle if you port the kind list naively.

---

## 2. What shipped

### 2.1 The map has to survive the AS → native conversion (`avm2_filters.{h,c}`)

`Avm2FilterVal` deliberately drops `mapBitmap` because the AS round trip must
read back `null` (Ruffle does the same). But the render arm — unlike
`BitmapData.applyFilter`, which has the AS filter object in hand — only ever
sees the stored `Avm2FilterVal`. So the map is now kept **by identity**, exactly
like `ShaderFilter`'s `shader`:

* `Avm2FilterVal.map_bitmap` (new trailing field in the displacement block);
* set in `avm2_filter_from_object`'s `AVM2_FILTER_DISPLACEMENT_MAP` case;
* **`avm2_filter_to_object` is untouched** — it still writes `mapBitmap = null`,
  so nothing script-visible changes (proved by `avm2/displacement_map_filter`
  and `avm2/displayobject_filters` in the canary);
* marked in `avm2_filter_gc_mark` for that kind — the map is a GC root for
  exactly as long as the DisplayObject keeps the filter;
* explicitly nulled in `avm2_filter_from_tag` (no SWF tag filter is a
  displacement) so the mark is always well-formed.

### 2.2 The shader is rect-local (`render_webgpu.c`, `displace_wgsl`)

Ruffle's `FilterSource` for a filtered DisplayObject is its **cache texture**,
sized to the object's render bounds under the stage view matrix
(`display_object.rs::render_base` → `BitmapCache::update`), and
`Stage::render_viewport` pushes the view matrix *first*, so those bounds are
already in device pixels — the same space as our stage-sized offscreen layer.
Every rect-relative rule in `displacement_map.wgsl` is therefore defined on the
OBJECT:

| ruffle | our port |
|---|---|
| `source_pos = uv * source_size` | `local = frag_pixel − rect_origin` |
| `map_uv = (source_pos − offset)/viewscale/map_size` | identical, on `local` |
| `displaced_uv = displaced / source_size` | `/ rect_size` |
| `out_of_bounds` on `displaced_uv` | identical |
| source sampler = **repeat + linear** over the whole texture | **manual bilinear with explicit wrap inside the rect** (`textureLoad`, no sampler) |
| target = fresh transparent texture of the source size | fragments outside the rect return `vec4f(0)` |

The manual tap is the point of the cut: an address mode can only wrap the whole
texture, and our texture is the **stage**. Its arithmetic is deliberately the
same as the CPU twin `avm2_bitmap.c::dm_sample_repeat` / `bd_displace_source_region`
(s15) — nearest+ClampToEdge on the map, the neutral `vec4(0.5) = 127.5` (half a
level, not 128) outside the map, channels read as stored (premultiplied both
sides). That twin is already CI-graded on *the same content* through
`visual/filters/displacement_map_through_applyFilter`, which is the byte-for-byte
`applyFilter` sibling of `displacement_map_through_filters`.

Every fetch is `textureLoad`, so there is no uniformity requirement and the
early `return` for out-of-rect fragments is legal.

Resources are **lazy** (`displace_resources_created`): a movie with no
displacement filter allocates no pipeline and no map texture. The map texture is
pinned to `RGBA8Unorm` (not `surface_format`) so the upload's byte order is the
channel order the shader reads, and it is only recreated when the map's
dimensions change.

### 2.3 `MSAA_SAMPLES` invariant

The new pipeline is `multisample.count = 1`, **not** a literal 4 and not
`MSAA_SAMPLES` — because the ping-pong targets `filter_tex_a`/`filter_tex_b` are
single-sampled by construction (`ensure_filter_resources`), exactly like the
neighbouring `blur_pipeline`. `MSAA_SAMPLES` belongs to the *offscreen capture*
pass that produced them (`filter_msaa_texture`, pre-existing code, already uses
the macro). `git diff | grep -c 'MSAA'` = **1**, and it is the comment saying so.
Wave-1 §5 trap 5 ("engaged by cut 2") is therefore **discharged, not violated**:
the invariant is that a new pipeline must never hard-code 4 *when it renders into
an MSAA target*; this one does not render into one.

### 2.4 The object screen rect (`avm2_display.c`)

`avm2_filter_screen_rect()` takes the world-twips AABB from the existing
`bounds_with_transform()` (the same function `opaqueBackground` uses) and pushes
its four corners through `app->stage_to_ndc`, then NDC → target pixels. Going
through the projection rather than multiplying by `stage_scale` is deliberate:
`stage_to_ndc` already carries the ShowAll fit **and** the centring offset that
`wasm_wrappers/main.c` bakes in for a `viewport_dimensions` test, so the rect is
right on a letterboxed target without a second copy of that arithmetic. That is
what makes `displacement_map_scales_with_screen` (800×400 viewport over a
400×200 movie, `viewscale` 2) land at **max diff 1**.

Origin is rounded to the nearest texel (`floorf(x + 0.5f)`) because the shader
addresses the layer with `textureLoad`. Ruffle's cache texture starts at a
possibly-fractional `bounds.x_min`; ours can only start on a texel boundary, so
an object at a fractional stage position is up to half a pixel off. **Every**
displacement row in the corpus places its objects at integer coordinates, where
the two agree exactly — stated here as the one known approximation.

`avm2_run_displacement_filter()` then recomputes the node's own world matrix
(`mat_mul(parent_world, ext_matrix(ext))` — `avm2_render_filtered` is called
*before* `avm2_render_node` applies it), reads the map off
`avm2_bitmapdata_ext_of(f->map_bitmap)`, and hands the renderer the rect, the
map pixels, `map_point` (stage px, as the AS property is), `scale_x/y`,
`viewscale = app->stage_scale`, the channel selectors and the mode.

### 2.5 Where it hooks

Two lines in the existing cut-1 filter loop plus one clause in
`avm2_filter_renderable`. The displacement clause is FIRST and returns
`f->map_bitmap.kind == AVM2_VALUE_OBJECT` — no map means no pass, which is
`displacement_map.rs::apply`'s `filter.map_bitmap.clone()?` — and it must sit
above the shared `quality == 0` gate (§1.4). Composition is unchanged: a
displacement is not a shadow/glow/bevel, so cut 1's `legacy` branch already
takes it, i.e. the plain `renderer_composite_filtered` blit-back.

The pass runs `filter_tex_a → filter_tex_b` and then copies back with
`wgpuCommandEncoderCopyTextureToTexture`, so the ping-pong invariant ("the layer
always ends up in `filter_tex_a`") holds and a displacement **chains** with
blur/glow in the same `.filters` list. Both textures already carry
`CopySrc|CopyDst`, and the copy is encoded with the main pass suspended — the
same slot `render_webgpu_snapshot_filter_source` uses.

---

## 3. Per-comparison ledger

`--mode=graphics --images --diff --verbose`, local Dawn, `SWFRECOMP_COMPILE_TIMEOUT=2400`.
BEFORE = CI run `31877239992` (`origin/ruffle-image-results/index.json`).

| comparison | BEFORE (CI) | AFTER (local) | budget | verdict |
|---|---:|---:|---|---|
| `visual/filters/displacement_map_through_filters [output]` | fail 27 565, max 255 | **pass 0, max 2** | tol 4 / 0 | **FLIP** |
| `visual/filters/displacement_map_scales_with_screen [output]` | fail 99 353, max 255 | **pass 0, max 1** | tol 4 / 0 | **FLIP** |
| `visual/filters/displacement_map [output]` | fail 123 378, max 254 | fail **20 655**, max 254 | tol 32 / 160 | −83.3 %, **no flip** (§4) |
| `visual/filters/displacement_map_through_applyFilter [output]` | pass | **pass 0, max 2** | tol 4 / 0 | **no regression** (CPU twin) |
| `visual/cache_as_bitmap/cab_mask_filters [output]` | fail 4 968, max 255 | fail 4 968, max 255 | tol — / 0 | **byte-unchanged** |
| `visual/filters/blur_scales_with_screen [output]` | fail 30 810, max 40 | fail 30 810, max 40 | tol 2 / 0 | **byte-unchanged** |

**Local == CI for this family, verified rather than assumed.** A pre-patch run
of `displacement_map` in this worktree produced `123378 outliers … max
difference 254` — the CI number **to the digit** — and a per-tile diff of the CI
`output.actual.png` against the golden reproduces our own per-tile split
exactly (§4.2 BEFORE column). See §5 for the byte-level check on the two rows
that flipped.

---

## 4. Why `displacement_map` does not flip — measured, not argued

### 4.1 The test

Seven `TestImage` sprites on a 500×1000 stage, one per displacement
configuration, **plus** the 200×200 radial-gradient `BitmapData` the test also
`addChild`s at (0, 0) as an ordinary unfiltered `Bitmap` — that BitmapData *is*
the map. Tile 1's filter is `new DisplacementMapFilter()` with **no arguments**:
no map, so no pass runs, in Ruffle or here.

### 4.2 Per-tile attribution (tolerance 32, the test's own)

| region | BEFORE (CI actual) | AFTER (local) |
|---|---:|---:|
| the unfiltered 200×200 gradient = **the map itself** | **0** (max 2) | **0** (max 2) |
| t1 `DisplacementMapFilter()` — **no map, no pass: the control** | **2 956** | **2 956** |
| t2 CLAMP, R→x B→y, 30/−30 | 18 442 | 3 777 |
| t3 WRAP, B→x G→y, −30/30 | 26 521 | 2 665 |
| t4 COLOR, R→x R→y, 15/−15, mapPoint(50,20), 0xFF0000@0.5 | 14 798 | 3 031 |
| t5 IGNORE, B→x G→y, 50/50, mapPoint(−10,−10) | 31 777 | 2 250 |
| t6 CLAMP, componentX **0**, R→y, −30/30 | 14 610 | 3 480 |
| t7 WRAP, R→x, componentY **0**, −30/30 | 14 274 | 2 496 |
| **total** | **123 378** | **20 655** |

Three things fall out of that table:

1. **The map is exact** (0 outliers on the unfiltered copy), so nothing in the
   residual is a `BitmapData.draw`/gradient problem.
2. **The control tile is byte-unchanged**, and every displaced tile has dropped
   to that control's magnitude. All four modes, both `component*` = 0 cases, and
   a non-zero `mapPoint` are therefore correct to within the pre-existing
   per-tile floor.
3. That floor is a `TestImage` **content** defect. It is **not** a whole-pixel
   translation: a ±2 px shift search over tile 1 is minimised at (0, 0) —
   1 181 with a 3 px border trimmed, against 2 659 / 3 922 at ±1 px in x and
   2 753 at +1 px in y. The diff is ~1 000 pixels scattered over a 207×185 box
   on colour boundaries (e.g. `(199,199,199)` where the golden has
   `(255,255,153)`), i.e. sub-pixel edge placement on a detailed drawing —
   the `hairline_edge_drift` family.

**Completion mechanism for this row:** whatever fixes `TestImage`'s edge
placement. At `max_outliers = 160` against a 7 × ~2 900 floor, no amount of
displacement work can reach it, and the cheapest way to see the row move again
is to re-measure tile 1 in isolation.

---

## 5. CI-grade proof for the two flips (s13 rule)

The brief's s13 rule ("if you get to 0 outliers locally, prove CI-grade by
comparing your before-leg PNG to the CI actual PNG"). I reverted the patch with
`git apply -R`, re-rendered all three rows with `SWF_KEEP_BUILD_DIR`, and
md5'd them against `origin/ruffle-image-results`:

| row | local BEFORE render (this worktree, Dawn) | CI actual PNG (`ruffle-image-results`, lavapipe) | |
|---|---|---|---|
| `displacement_map_through_filters` | `361f05bc185d84f3b4a3c55ce810cf76` | `361f05bc185d84f3b4a3c55ce810cf76` | **identical** |
| `displacement_map_scales_with_screen` | `651266e6c04d5db8968039a1cde5032e` | `651266e6c04d5db8968039a1cde5032e` | **identical** |
| `displacement_map` | `9ea21f0d8bc44f0175ecbfc52508d488` | `9ea21f0d8bc44f0175ecbfc52508d488` | **identical** |

**Byte-identical, not merely equal in outlier count.** Local Dawn and CI
lavapipe agree to the byte on all three of these movies, so the AFTER numbers
(0 outliers, max 2 and max 1) are a CI *prediction*, not just a local A/B.
Playbook §6's "never grade a local render against a golden" is honoured — the
grading is still CI's; what this table licenses is the claim that the two rows
land the same way there.

(That is a property of these movies, not of the machine: they are `Bitmap`
blits and a filter pass over them, with no tessellated hairline anywhere, which
is exactly the class where the two backends do not drift.)

---

## 6. Canary

`ruffle-tests/w2filt2_canary.py` (a renamed copy of `render_canary.py` — see
Appendix B) over a **16-test / 20-comparison risk-targeted subset**, `-P 2`,
`--recompile`, `SWFRECOMP_COMPILE_TIMEOUT=2400`, patch reverted with
`git apply -R` for the `before` leg and re-applied afterwards:

```
RENDER CANARY  before=before  after=after   16 tests / 20 comparisons

  IDENTICAL    20
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0

  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

| member | cmps | why it is in the set | before→after |
|---|---:|---|---|
| `visual/filters/glow_pass_scaling` | 1 | tier 1; the set's AVM2 `.filters` member — the arm I edited | md5 identical |
| `visual/cache_as_bitmap/masks` | 7 | nearest passing AVM2 neighbour of the filter arm | md5 identical ×7 |
| `visual/filters/drop_shadow`, `visual/filters/color_matrix` | 2 | the AVM1 **tag** filter route (`tag.c::render_filtered_object`) | md5 identical |
| `avm1/bitmapdata_applyfilter_colormatrix` | 1 | the CPU `applyFilter` route the new `Avm2FilterVal` field also crosses | md5 identical |
| `avm2/blend_multiply_alpha` | 1 | **the other user of `filter_tex_a`/`filter_tex_b`** — the ping-pong my new pass writes and copies back | md5 identical |
| `avm2/displacement_map_filter`, `avm2/displayobject_filters` | 0 png | trace-only; **the only script-observable surface of the new `map_bitmap` field** (the `.filters` round trip, `mapBitmap` must still read back `null`) | trace identical |
| `avm1/{color, bitmap_data_fillrect, mask_with_drawing, movieclip_setmask}` | 4 | baseline shape / bitmap / mask coverage | md5 identical |
| `visual/cache_as_bitmap/shape_changed` | 1 | cacheAsBitmap | md5 identical |
| `regression/{avm2_timeline_gradients, mask_sibling_union, mask_nested_intersect}` | 3 | standing `regression/` ×3 policy | md5 identical |

Plus, graded by hand outside the canary (§3): `displacement_map_through_applyFilter`
(the CPU displacement twin, still **pass 0 / max 2**), `cab_mask_filters` and
`blur_scales_with_screen` (both byte-unchanged).

**Set-size disclosure.** The standing 20-test set was trimmed to 16 because the
machine was at load average 29–33 from ~10 concurrent agents and AVM2 members
were costing 500–600 s each; the full set × 2 legs would not have finished.
Dropped: `avm1/focusrect_swf5` (12 cmps), `visual/simple_shapes/{winding_rule,
masks, gradients}`, `from_shumway/{timeline/timeline_as2_5,
acid/acid-gradient-0, acid/acid-blend-2}`, `visual/blend_modes/multiply`,
`regression/{avm2_morph, avm2_timeline_stroke_gradient}`. **None of them can
reach this patch**: no AVM2 movie among them sets a `DisplacementMapFilter`, and
the only non-displacement code the patch touches is (a) 7 trailing
`WebGPURenderContext` fields, (b) one clause in `avm2_filter_renderable` that
returns early only for kind 9, and (c) a struct field that
`avm2_filter_to_object` never reads. `blend_multiply_alpha` is the member that
covers the one shared *resource*, and it is identical.

**Blind-spot disclosure (s15 rule).** Before this session the standing set had
**no DisplacementMapFilter member at all**, in either the render or the
`applyFilter` route, so it was structurally blind to this change class. I added
`avm2/displacement_map_filter`, `avm2/displayobject_filters` and
`visual/filters/displacement_map_through_applyFilter` to my own subset and
graded the three render rows directly instead. **Recommended standing addition
for `render_canary_tests.txt`: `visual/filters/displacement_map_through_filters`
as a tier-1 member** — with this patch it is 0 outliers / max 2 against its
golden, and it is the only corpus test that exercises the object-rect uniform
path end to end. I have deliberately NOT edited `render_canary_tests.txt` in
this patch: `w2-tooling-hygiene` owns that file this session.

### 6.1 Family sweep (the brief's "all currently-passing `visual/filters/*` and `avm2/*filter*` rows")

Graded with the harness on top of the patch, `--mode=graphics --images --diff --verbose --recompile`:

**`visual/filters/*` — every row the CI baseline has PASSING:**

| row | after the patch |
|---|---|
| `blur_quality [output]` | **pass** 0 outliers, max 6 (tol 6) |
| `blur_fractional [output]` | **pass** 0 outliers, max 5 (tol 5) |
| `blur_pass_scaling [output]` | **pass** 0 outliers, max 3 (tol 3) |
| `avm1_convolution_initialization` | **pass** (trace) |
| `glow_pass_scaling [output]` | **pass**, md5 identical to the before leg (canary) |
| `displacement_map_through_applyFilter [output]` | **pass** 0 outliers, max 2 |

All six unchanged; the three on-budget blur rows s16 flagged (`max 6 vs tol 6`,
`max 5 vs tol 5`, `max 3 vs tol 3`) sit exactly where s16 left them, so this
patch does not consume any of their slack.

**`avm2/*filter*` — the filter round trip, i.e. the only script-observable
surface of the new `Avm2FilterVal.map_bitmap` field:**

13/13 **pass** on the trace axis: `bevel_filter`, `blur_filter`,
`color_matrix_filter`, `convolution_filter`, `drop_shadow_filter`, `glow_filter`,
`gradient_bevel_filter`, `gradient_glow_filter`, `checkfilter`,
`filters_array_holes`, `filter_rewind`, `bitmapdata_filter_sourcerect`,
`bitmapdata_draw_filters` — plus `displacement_map_filter` and
`displayobject_filters` in the canary (trace md5 identical). **`mapBitmap` still
reads back `null`**, which is the property the new field could have broken and
the reason this sweep exists.

Their two image comparisons are also unmoved: `bitmapdata_draw_filters [output]`
fail **14 400**, max 255 — the CI baseline number to the digit — and
`bitmapdata_filter_sourcerect [output]` **pass** 1 603 outliers against a 1 700
budget (on-budget, but unreachable by this patch: no `DisplayObject.filters` and
no displacement filter anywhere in it).

**Zero regressions on either axis across the whole filters family.**

---

## 7. Merge notes for the coordinator

* Stage by name: `SWFModernRuntime/include/avm2/avm2_filters.h`,
  `SWFModernRuntime/src/avm2/avm2_filters.c`,
  `SWFModernRuntime/include/rendering/render_webgpu.h`,
  `SWFModernRuntime/include/rendering/renderer.h`,
  `SWFModernRuntime/src/rendering/render_stub.c`,
  `SWFModernRuntime/src/rendering/render_webgpu.c`,
  `SWFModernRuntime/src/avm2/avm2_display.c`. **No new files.**
* Runtime-only ⇒ no `SWFRecomp/` rebuild, no `--recompile` on merge.
* CI mode `graphics`, categories `all` is sufficient (no recompiler or AVM2
  emission change). `no-graphics` **cannot** move: every renderer entry point is
  `((void)0)` under the non-WebGPU arm and `render_stub.c` has the twin, and the
  only non-render change (`Avm2FilterVal.map_bitmap`) is never read back into AS.
* An `images=true` run is what grades the two flips.
* Declare in the ledger: `displacement_map_through_filters` fail→**pass**,
  `displacement_map_scales_with_screen` fail→**pass**,
  `displacement_map` 123 378 → **20 655** (band, will not flip),
  everything else byte-unchanged.
* **Order note:** cut 2 is independent of every other s17 patch. It shares
  `avm2_display.c` with `w2-gfx-drawgraphicsdata` (`gfx_draw_graphics_data`,
  ~:8819), `w2-gfx-cab-pixelsnap` (`compose_children`) and `w2-crossvm-legE`
  (the mouse-pick walk); cut 2's edits are the filter block at ~:16150-16450
  only, so the three should apply in any order.

---

## 8. Board corrections requested

1. `graphics-fanout-playbook.md` §15 "filters **cut 2** (the displacement trio,
   the only place trap 1 binds)" → **cut 2 is DONE and worth 2, not 3**.
   `displacement_map` is a `hairline_edge_drift` row wearing a filter costume;
   move it out of the filters family and into whatever owns `TestImage`'s edge
   placement (§4).
2. s16 report §8.6's remaining-upside list loses the displacement trio and keeps
   `cab_mask_filters` (4 968, cut 3(b) — **measured** untouched here),
   `blur_scales_with_screen`'s 30 810 (AVM1 sprite-tag route, **measured**
   untouched here), `acid-filter`'s 482, and the fourteen AVM1-route accuracy
   rows.
3. New standing trap for the filters family, alongside s16's three
   (`strength` must be forced to 1 / `impotent()` is blur-only / the `quality == 0`
   skip is ours): **`quality` does not exist on `DisplacementMapFilter`**, so any
   shared "skip when quality == 0" gate deletes the whole kind. Same class of
   bug as the `strength` one, same symptom (the filter silently does nothing).
4. Wave-1 §5 trap 5 (`MSAA_SAMPLES` "engaged by cut 2") is **discharged**: the
   displacement pass renders into the single-sampled ping-pong, so
   `multisample.count = 1` is correct and the macro must NOT be used there (§2.3).

---

## Appendix A — reproduce

```bash
export SWFRECOMP_COMPILE_TIMEOUT=2400 DAWN_INSTALL=$HOME/CC/dawn-install
python3 ruffle-tests/verify_output.py \
    --tests-dir=<worktree>/ruffle-tests/tests/swfs/visual \
    --test=filters/displacement_map_through_filters \
    --mode=graphics --images --diff --verbose --recompile
```

Per-tile attribution driver (throwaway):
`<scratchpad>/w2filt2/tiles.py ACTUAL.png EXPECTED.png 32`;
whole-pixel shift search: `<scratchpad>/w2filt2/shift.py`.

## Appendix B — harness notes for the next agent

* **`--recompile` on first use of every copied dir, canaries included** — three
  of my rows came back `COMPILE_FAIL … collect2: error: ld returned 1 exit
  status` purely from a stale `Recompiled*` cache in a `cp -r`'d dir. The
  underlying error is invisible in the harness output (only the last stderr line
  is reported); re-linking the kept build dir by hand shows
  `undefined reference to avm2_generated_symbol_class_frames` /
  `avm2_generated_abc_lazy`, i.e. exactly the s16 signature. `SWF_KEEP_BUILD_DIR`
  + a manual `gcc *.o` is the two-minute way to see it.
* A `setsid nohup script &` does **not** give you the script's PID in `$!` — you
  get the wrapper, which exits immediately, so an `until kill -0 $!` waiter fires
  at once. Read the real PID out of `pgrep -f <your script name>` afterwards.
* I did **not** `pkill -f` anything (s16 incident). The one process I had to stop
  was selected by PID from `ps -eo pid,cmd | grep <my worktree hash>`.
* Untracked scaffolding left in the worktree and NOT part of the patch:
  `ruffle-tests/w2filt2_canary.py` (a renamed copy of `render_canary.py` so a
  sibling's pattern-kill cannot take my captures down) and `.render_canary/`.
  Delete both if they survive.
