# s27 wave 2b: `w2b-group-alpha-triggers` (transparency-group alpha for filters, non-LAYER blends and alpha offsets)

**NEW FILES**
- `SWFRecompDocs/plans/session27-fanout-reports/w2b-group-alpha-triggers-report.md` (this report)
- `SWFRecompDocs/plans/session27-fanout-reports/w2b-group-alpha-triggers.patch` (the deliverable; `git apply --check -R` verified on the branch)
- 10 regression fixtures, each holding `create_test_swf.py`, `test.swf`, `test.toml`, an empty `output.txt` and `output.expected.png` (the **Flash Player 32** screen PNG):
  - `ruffle-tests/tests/swfs/regression/group_alpha_filter_cm/` and `avm2_group_alpha_filter_cm/`
  - `ruffle-tests/tests/swfs/regression/group_alpha_multiply/` and `avm2_group_alpha_multiply/`
  - `ruffle-tests/tests/swfs/regression/group_alpha_layer_aadd/` and `avm2_group_alpha_layer_aadd/`
  - `ruffle-tests/tests/swfs/regression/group_alpha_layer_inner/` and `avm2_group_alpha_layer_inner/`
  - `ruffle-tests/tests/swfs/regression/group_alpha_cab/` and `avm2_group_alpha_cab/`
- `SWFRecompDocs/plans/session27-fanout-reports/w2b-group-alpha-triggers-fixtures/`:
  - `mkprobes_w2b.py`;
  - `probes/*.swf`: 8 AVM1 probes and 8 AVM2 twins, all new Flash-oracle requests (see LOCAL ORACLE REQUESTS);
  - `probes/*.{before,after}.png`: our renders of those probes.

**Box:** cloud, Dawn on lavapipe, `SETUP_STATUS` all OK.
- Code base `origin/master` `94e2a7582`, which includes the landed `fb6fe4ba4`.
- Tests: `download_tests.sh visual avm1 avm2 from_shumway from_gnash` against upstream Ruffle master `1e604fa87`.
- Baseline results: `a0e485e5f` / image-results `db74e661d`.

**Fidelity:** 23 rows are in both my BEFORE capture and `origin/ruffle-image-results`. All 23 are **md5-IDENTICAL** to CI's
actual PNG, so local absolute verdicts are CI-grade.

## Verdict (lead)

| Item | Verdict | Graded corpus flips | Evidence |
|---|---|---|---|
| Filtered clip + alpha is one group (timeline, AVM1 + AVM2) | **GO, in the patch** | **0** | `group_alpha_filter_cm` + AVM2 twin: FAIL 3200 outliers / max 65 → **PASS, max 1** against the Flash PNG |
| Every non-NORMAL blend mode + alpha is one group | **GO, in the patch** | **0** | `group_alpha_multiply` + AVM2 twin: FAIL 3200 / 65 → **PASS, max 0** |
| Alpha OFFSET on a grouping clip (`a' = a·m + o` at the composite) | **GO, in the patch** | **0** | `group_alpha_layer_aadd` + AVM2 twin: FAIL 3200 / 64 → **PASS, max 1** |
| cacheAsBitmap + alpha stays per child | **kept per child** (no change) | 0 | `group_alpha_cab` + AVM2 twin pass at tolerance 2 before and after, md5-identical |
| Ancestor alpha above a LAYER (s27 landed model) | **confirmed by Flash**, now pinned by a fixture | 0 | `group_alpha_layer_inner` + AVM2 twin: PASS before and after, md5-identical |
| **Brief premise "this WILL move corpus rows"** | **REFUTED (measured)** | — | 0 of 330 corpus comparisons move (canary plus every filter/blend image row). Static and instrumented proof below |

**Priced yield:**
- **+0 graded corpus flips.**
- **+10 new regression rows**, all PASS against a real Flash oracle. 6 of them FAIL on clean master, so they would have caught
  this class of bug.
- **0 rows move away from any golden**, so there are no Flash-over-Ruffle losses to disposition.

## Mechanism and patch scope

**Flash's model** (Flash Player 32 captures, `w2-local-oracles/w2-layer-alpha-group/README.md`, pixel (80,50)):
- A clip with a filter list, or with any blend mode other than NORMAL, renders its subtree into a group.
- Its alpha row then applies **once** to the group.
- The alpha OFFSET is part of that row: `n3g_layer_aadd` gives (128,128,254), the blue at a' = 1 − 128/255.
- cacheAsBitmap alone does **not** group: `n3g_cab` gives (128,65,192), per child.

**The fix.** The `fb6fe4ba4` split model (strip the alpha from the subtree's colour transforms at compose, apply it at the group
composite) is generalized along three axes.

### 1. The alpha ROW `(m, o)` instead of the multiplier `m`

**`render_webgpu.c`:**
- `g_group_alpha_offset_pending`, the new `render_webgpu_set_group_alpha_row` and `take_group_alpha_row`.
  `take_group_alpha` is gone; `render_webgpu_set_group_alpha(ga)` is now `row(ga, 0)`.
- `group_alpha_row_params` replaces `group_alpha_params`. With o == 0 it writes the identical s27 params:
  `{0,0,0,m,0,0,0,0}`.
- `composite_wgsl` `fs_main` gains a mode z > 1.5: `a' = clamp(a·m + tint.a)` on the **unpremultiplied** group, with an
  empty texel staying empty.
  - The existing modes compute exactly as before: `raw * ga`, then tint or passthrough.
  - The canary proves it: 330/330 md5-identical, including every filter and every LAYER/ADD/SCREEN/SUBTRACT composite.
- **Aadd arithmetic:**
  - Our result is (128,128,255) at the overlap and (255,128,128) for the red-only region; Flash gives (128,128,254) and
    (255,128,128).
  - Flash's 254 is Flash rounding at the overlap only: its blue-only region reads (128,128,255).
  - That is max diff 1 at tolerance 1.

### 2. Every blend group consumes the row

**`render_webgpu.c`:**
- `render_webgpu_composite_blend`:
  - Trivial modes (LAYER/SCREEN/ADD/SUBTRACT) bind the row whenever it is active (it was LAYER only).
  - Complex modes get a new binding 3 (`GroupParams`, 32 bytes) in `blend_shader_bgl`. By default it binds the all-zero
    `blend_params_buf`, so nothing changes.
  - `blend_shader_wgsl_head` gains `group_row()`, which is applied to the "current" (src) sample before `compose()`.
- `render_webgpu_end_child_layer`: the LAYER child layer takes the row (offset included).

### 3. The filter layer is a group

**`render_webgpu.c`:**
- New `render_webgpu_composite_filtered_group`, which consumes the pending row.
- `composite_filtered_impl`'s body moved into a static `composite_filtered_params`, with byte-identical params for every
  existing caller.

**Headers and stub:** `render_webgpu.h`, `renderer.h` (both arms: `renderer_set_group_alpha_row`,
`renderer_composite_filtered_group`) and `render_stub.c` stubs.

### `tag.c` (AVM1 / timeline; every function touched)

- **The `g_lga[]` record** gains `go` (offset) and `orig_cx` (the entry's pre-split `cxform_id`).
- **New statics:** `lga_index`, `lga_set_for_entry` (replaces the removed `lga_for_entry`), `lga_blend_groups`,
  `obj_cm_folded`, `lga_fold_group`, `lga_group_mode` and `lga_entry_groups`.
- **`lga_split_entry`** now splits whenever `lga_entry_groups` is true. The row is `m ∈ (0,1]` and `o` (any sign), excluding
  `(1,0)`; colour→alpha terms still refuse. Both `[15]` and `[19]` are stripped. The cases:
  - **Filter-routed entry:** splits when there is no filtered ancestor. The previous "never a filtered LAYER" refusal is gone,
    because the filter layer is the group.
  - **LAYER:** as before, `< 2` blend ancestors deep.
  - **Folded-CM entry** (`obj_cm_folded`): an entry with a non-empty PlaceObject3 filter list that the recompiler folded whole
    into its cxform (`swf.cpp PlaceCmCompose`, not `::live`) and that is not filter-routed. `n3g_filter_cm` is exactly this.
    It is grouped like LAYER.
  - **Other blend modes** (3-10, 13, 14): only with no blend or filter ancestor **and**
    `renderer_blend_mode_is_layered(context, mode)` at compose. This mirrors the render arm's `offscreen_depth == 0` gate.
- **`lga_enter` / `lga_leave`** also count a folded-CM group as a blend ancestor.
- **`compose_children`:**
  - A FILTERED leaf SHAPE or MORPH_SHAPE now splits; its stripped slot is re-pointed.
  - The SPRITE arm is unchanged in code, but it now reaches the generalized split.
- **The two root compose loops (`tagShowFrame`, `tagRerenderFrame`):** a new `else if` arm splits a root FILTERED SHAPE or
  MORPH_SHAPE, seeded by `root_seed_cxform`.
- **`render_filtered_core`** (the composite call sites only, coordinated with sibling `w2-applyfilter-cm`, which edits its
  CM arms):
  - A timeline entry with a recorded row runs in the existing `group` mode: every composed filter composes INTO the layer.
  - The layer is then blitted with `renderer_set_group_alpha_row` + `renderer_composite_filtered_group`.
  - The filter's own colour (A3) takes the entry's ORIGINAL cxform (via `orig_cx`) minus the alpha row.
- **`render_display_list`** nested arms:
  - The layered-blend arm runs for `lga_group_mode(obj)`: 2 for a folded-CM group. It calls `lga_set_for_entry` before
    every mode's composite.
  - The child-layer arm also takes folded-CM groups, with `g_layer_group_depth` only for a real LAYER.
- **The `tagShowFrame` / `tagRerenderFrame` root render loops:** `blend_layered` and the composite use `lga_group_mode`, and
  `lga_set_for_entry` runs before every mode.

### `avm2_display.c` (AVM2; every function touched)

- **`avm2_lga_split`:** takes the whole concatenated row, including `parent_cx->add[3]` and `cx_aa`, and returns `go`.
  A forward declaration now sits above `avm2_render_filtered`.
- **`avm2_render_layer_group`:** gains a `go` out-parameter.
- **`avm2_render_node`:**
  - The `blend_layered` branch now groups **every** mode through `avm2_render_layer_group`.
  - The child-layer branch passes the row.
  - The `lga_own` strip also zeroes `own_cx.add[3]`.
- **`avm2_render_filtered`:**
  - **Real filters:** a split node strips its row, and the node's own alpha via `g_avm2_lga_strip`. Every non-blur filter
    composes in place (`avm2_filter_one_in_place`). The single-shadow pre-shift is off in group mode. The layer composites
    through `renderer_composite_filtered_group`.
  - **`n == 0`** (every filter impotent, for example the identity CM, or unsupported): with a row to split, the node renders
    into a LAYER-shaped group. That is the root layer when `is_layered(2)`, else a child layer. Otherwise it renders as
    before.

**Not touched:** `swf_core.c`, `tag_stubs.c`, `#ifdef NO_GRAPHICS` arms, the recompiler, `verify_output.py`. There are no new
`.c`/`.h` files. `render_webgpu.c` adds no new pipelines; the complex-blend bind group layout gained one uniform entry.

**Known limits (accepted, documented in code):**
- **A split with no group at render time.** A split entry whose render arm then fails to open a group draws with its alpha row
  dropped. This is the `fb6fe4ba4` class, extended: the compose guards would have to mispredict, for example for a non-LAYER
  blend inside an AVM1 alpha-mask offscreen. The canary and the instrumented sweep below show no corpus row reaches it.
- **Positive alpha offsets.** Empty group texels stay empty (a' is computed only where the group has coverage). Flash's
  behaviour on transparent texels inside a positive-offset group is not probed.
- **Not split:** a filtered static/EditText leaf and BUTTON entries (lead 1).

## Per-test before/after (clean `origin/master` vs patch, same box, `--mode=graphics`)

| Test | Before | After |
|---|---|---|
| `regression/group_alpha_filter_cm` (NEW) | FAIL 3200 outliers, max 65; overlap (127,63,191) | **PASS 0, max 1**; overlap (127,127,255) |
| `regression/avm2_group_alpha_filter_cm` (NEW) | FAIL 3200, max 65 | **PASS 0, max 1** |
| `regression/group_alpha_multiply` (NEW) | FAIL 3200, max 65; overlap (127,63,191) | **PASS 0, max 0**; overlap (128,128,255) |
| `regression/avm2_group_alpha_multiply` (NEW) | FAIL 3200, max 65 | **PASS 0, max 0** |
| `regression/group_alpha_layer_aadd` (NEW) | FAIL 3200, max 64; overlap (128,64,191) | **PASS 0, max 1**; overlap (128,128,255) |
| `regression/avm2_group_alpha_layer_aadd` (NEW) | FAIL 3200, max 64 | **PASS 0, max 1** |
| `regression/group_alpha_layer_inner` (NEW) | PASS 0, max 1 | PASS 0, max 1, md5-identical |
| `regression/avm2_group_alpha_layer_inner` (NEW) | PASS 0, max 1 | PASS 0, max 1, md5-identical |
| `regression/group_alpha_cab` (NEW, tol 2) | PASS 0, max 2 (would FAIL at tol 1: 1600 outliers) | PASS 0, max 2, md5-identical |
| `regression/avm2_group_alpha_cab` (NEW, tol 2) | PASS 0, max 2 | PASS 0, max 2, md5-identical |
| s27/s26/s25 layer-group fixtures | PASS | PASS, md5-identical. All are in the canary: `layer_group_{alpha_transparency, filtered_child, overlap_alpha, overlap_erase, in_add_alpha}`, `avm2_layer_group_{alpha, alpha_transparency, filtered_child, overlap_alpha, erase}` |

**Tolerances:**
- **1 on the grouped fixtures.** This is the s27 rule: Flash rounds 127.5 up while our unorm8 write gives 127. Grouped vs
  per-child differ by ≥ 64, so tolerance 1 cannot mask a regression.
- **2 on `cab`.** Flash's per-child cacheAsBitmap path itself reads (128,65,192), against (128,64,191) for its own NORMAL
  control. Ours is (127,63,191), so max diff 2, while grouping would show a diff of 64.

**No-graphics parity:** all 10 new fixtures pass without `--mode=graphics`. So do:
- regression `layer_group_alpha_transparency`, `layer_group_filtered_child`, `avm1_po3_color_matrix_live`,
  `avm1_nested_po3_filters` and `avm1_runtime_filters`;
- `avm1/movieclip_blend_mode_property`.

Only shared `tag.c` compose code runs there, and the `renderer_*` macros are no-ops.

## Render-canary and corpus sweep

**The set:**
- the standing `render_canary_tests.txt` (290 members);
- **every** downloaded image row whose SWF can reach the changed code: 166 rows, found by a static scan for PlaceObject3
  filter/blend/cacheAsBitmap flags in root or sprites, or script strings `filters`, `blendMode`, `*Filter`, `cacheAsBitmap`
  or `applyFilter`;
- the 10 new fixtures.

That is **255 tests / 336 comparisons**, BEFORE (clean master) vs AFTER.

**Result: 330/330 corpus comparisons md5-IDENTICAL.**
- The only 6 that differ are the new fixtures that flip fail → pass.
- Trace status changes: none.
- 5 font/text rows exit non-zero in both legs because `fonts/` and `text/` were not downloaded. They are missing, not
  regressions.

**Why the brief's "this WILL move corpus rows" premise fails (measured, two ways):**
1. **Static.** A PlaceObject3 walker reads the cxform alpha of every filter or blend placement in the 255 SWFs. **No corpus
   SWF** places a filtered or blended object with an alpha cxform. The only hits are this slot's fixtures and the two s27
   LAYER fixtures.
2. **Dynamic.** A temporary, since-removed build logged every successful split, in AVM1 `lga_split_entry` and AVM2
   `avm2_lga_split`, across all 154 non-fixture candidate rows.
   - **Exactly one row splits:** `avm2/stage3d_fractal`.
   - There, 6 TextFields at `alpha = 0.7` carry a default (black) DropShadow on a black stage.
   - Grouped and per-child are pixel-identical there by construction, and the row is md5-identical. Its image row is also
     `known_failure`.
   - **No AVM1 corpus row reaches any split.**

   So the corpus has no filter+alpha or blend+alpha overlap scene. The AVM1 dynamic-clip filter path already grouped
   (`FilteredSource.group_alpha`) and is unchanged.

**Moved rows: none, so nothing moves toward or away from a golden.** There are no priced Flash-over-Ruffle losses and no
RvF/image-axis dispositions to write.

**The standing canary cannot see this change class.** 10 covering members are appended at EOF of `render_canary_tests.txt`.

## EXPECTED-FLIP LEDGER (coordinator checks CI against this)

- **Trace axis:**
  - No moves on any existing row.
  - 10 NEW rows (`regression/{,avm2_}group_alpha_{filter_cm,multiply,layer_aadd,layer_inner,cab}`), all **PASS** in graphics
    and no-graphics. Their `output.txt` is empty: no scripts.
- **Pixel axis, graded corpus:** **no moves.** Every filter/blend image row in visual, avm1, avm2, from_shumway, from_gnash
  and regression is md5-identical, as is the whole standing canary.
- **Pixel axis, new regression rows:** all 10 **PASS** against their Flash PNG.
  - `filter_cm` ×2: max 1.
  - `multiply` ×2: max 0.
  - `layer_aadd` ×2: max 1.
  - `layer_inner` ×2: max 1.
  - `cab` ×2: max 2 at tolerance 2.
  - On clean master, 6 of them FAIL (filter_cm, multiply and layer_aadd, ×2).
- **Mode note:** no-graphics only matters for the trace axis, where there is no change. CI graphics is the grading leg.
- **Categories not downloaded here** (fonts, text, timeline, swf, mixed_avm, from_avmplus, import_assets, stage3d, audio):
  they cannot move unless they hold a filtered or blended object with an alpha row that is not 1. A CI run with
  `categories=full` and `images=true` would confirm. Expected: no moves.

## Refutations / premise checks

- **"Corpus rows will move"** is refuted above: there are no filter+alpha or blend+alpha overlap scenes in the corpus.
- **"The filter offscreen is already a group: apply the alpha at its composite"** holds for real filters. It is **not
  sufficient for the very probe that motivated it.**
  - `n3g_filter_cm` uses an identity ColorMatrixFilter.
  - AVM1: the recompiler folds it into the placement cxform (`PlaceCmCompose`), so no filter offscreen opens.
  - AVM2: `avm2_filter_renderable` drops it as impotent (`n == 0`).
  - Both needed a LAYER-shaped group for "a filter list with no renderable pass". Applying the alpha at the filter composite
    alone left the fixture at FAIL 3200 / 65; I measured that before adding the fold arm.
- **"Derive Flash's exact arithmetic from aadd (128,128,254)."** The 254 is **not** the formula.
  - Flash's own blue-only region in the same capture is (128,128,255), and its red-only region (255,128,128).
  - Both equal `a' = 1·a − 128/255` applied to the unpremultiplied group, then normal over.
  - The overlap's −1 in blue is Flash-internal rounding where the group composited blue over red. It is covered by
    tolerance 1, not modelled.
- **cacheAsBitmap.** Flash's per-child CAB rounds 1 higher in g and b than its own NORMAL control: (128,65,192) vs
  (128,64,191). That is a Flash bitmap-cache quantization detail, not grouping. The fixtures use tolerance 2.

## New unclaimed leads

1. **Filtered static text / EditText and BUTTON entries are not split** (no corpus row; per child as before).
   - **Completion:** add `CHAR_TYPE_TEXT` (static only, `ng_getCharTextfieldIdx < 0`) to the `compose_children` /
     root-loop filtered-leaf arms, and BUTTON to `lga_split_entry` in the BUTTON arms.
   - Needs a Flash probe (glow + 50% text) first. Priced S.
2. **AVM1 glow halo width.** In the probes, a GlowFilter with blur 8 / strength 2 on the n3 scene shows only a ~1-2 px halo,
   both before and after this patch (`probes/w2b_glow_a50.*.png`).
   - Ruffle and Flash should show a wider halo. This belongs to the kernel/blur owners (`w2-flash-filter-kernels`), not to
     grouping.
   - **Completion:** the Flash capture requested below decides it.
3. **Nested non-LAYER blend inside an offscreen** (a filter or LAYER ancestor) is still per draw, with the alpha per child. The
   compose guard keeps that consistent.
   - **Completion:** a child-layer arm for complex modes, which needs a backdrop texture of the parent offscreen. Priced M; no
     corpus row.

## LOCAL ORACLE REQUESTS

FLASH, image, `num_ticks = 1`, quality high, **`--screen`** (they include non-LAYER blends). The probes are in
`SWFRecompDocs/plans/session27-fanout-reports/w2b-group-alpha-triggers-fixtures/probes/`; ours are alongside as
`*.after.png` (patch) and `*.before.png` (master). They test the paths the five w2 probes do not reach. The grouped
prediction is what the patch renders.

| Probe (AVM1; `avm2_` twin alongside) | Question | Ours after, (80,50) / (30,30) |
|---|---|---|
| `w2b_glow_a50` | real GlowFilter (green, 8 px, strength 2) + 50%: does the halo show through the rects? | (127,127,255) / (255,127,127): grouped |
| `w2b_shadow_shape_a50` | root SHAPE + DropShadow (12 px at 45°) + 50%: shadow under the rect? | (255,127,127) / (255,127,127): grouped |
| `w2b_blur_a50` | BlurFilter 4 + 50% | (128,128,255) / (255,128,128) |
| `w2b_chain_a50` | [Blur 4, Glow] + 50% | (127,128,254) / (254,128,127) |
| `w2b_glow_inner` | 50% NORMAL parent above a glowing child: does the ancestor alpha group at the filter? | (127,127,255): grouped (the s27 `layer_inner` analogue) |
| `w2b_multiply_aadd` | MULTIPLY with alpha offset −128 | (128,128,255) |
| `w2b_filter_aadd` | glow with alpha offset −128 | (128,128,255) |
| `w2b_add_a50` | ADD + 50% (on white: control, should be all white) | white |

- **If Flash disagrees on `w2b_glow_inner`:** limit filter-entry splits to the entry's OWN alpha, the same XS change s27
  priced for `layer_inner`.
- **If Flash disagrees on a real-filter probe** (`glow` or `shadow` showing through): the filter path in `lga_entry_groups`
  is one line to revert. The folded-CM arm stays, because `n3g_filter_cm` is Flash-confirmed.
- **Goldens.** Each confirmed probe should become a regression fixture: copy the generator recipe from
  `group_alpha_filter_cm/create_test_swf.py`, with the Flash PNG as golden.
