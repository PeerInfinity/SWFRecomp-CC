# s25 wave 2 — `w2-avm2-layer-groups` (layer groups: AVM2 port + exact nested model)

**NEW FILES** (all under `ruffle-tests/tests/swfs/regression/`, each dir = `create_test_swf.py`, `test.swf`,
`test.toml`, `output.txt` (empty), `output.expected.png`):
- `avm2_layer_group_alpha/`, `avm2_layer_group_erase/` — AVM2 twins of upstream `visual/blend_modes/layer_{alpha,erase}`
  (golden = upstream's Ruffle golden, copied)
- `avm2_layer_group_overlap_alpha/` — AVM2 twin of the overlap fixture (analytic golden)
- `layer_group_overlap_alpha/`, `layer_group_overlap_erase/` — the brief's task-3 overlap fixture (AVM1; analytic golden)
- `layer_group_in_add_alpha/` — LAYER (with an overlapping ALPHA child) nested inside an ADD offscreen (AVM1; analytic golden)
- this report, and `w2-avm2-layer-groups.patch`

Box: cloud, Dawn on lavapipe (SETUP_STATUS all OK). Upstream tests from `download_tests.sh visual avm1 avm2
from_shumway fonts text` at session start; the Ruffle clone taken minutes later was `3ac8dcb07`. Base =
`origin/master` `2f7be1710` (includes `ee9ea8738`, the AVM1 per-draw model).

## Verdicts

| # | Verdict | Scope | Flips (graded corpus) |
|---|---|---|---|
| 1 | **GO, landed** | L4: AVM2 port of the three layer-group hooks (`avm2_display.c` `avm2_render_node` blend arm) | **0** (no graded row needs it, as the brief said). Proven on 2 new fixtures: FAIL 66744 / 66949 → PASS |
| 2 | **GO, landed** | L5: exact model. ALPHA/ERASE apply to the child's OWN composite through a nested child layer (LIFO stack of 4 texture sets swapped into `filter_tex_a/msaa/ds`), and a LAYER nested in a filter/blend offscreen is isolated the same way | **0** corpus flips (blast radius = 5 static rows, all md5-identical). Fixtures: overlap ALPHA 2400 → 0 outliers (max 0); LAYER-in-ADD 6000 → 0 (max 0) |
| 3 | **Refutation (partial)** of brief premise L5 "differs when the child's shapes overlap" | **ERASE** | Per-draw ERASE is **already exact** for normal-blended overlapping children: Π(1−aᵢ) = 1 − (composite a). Measured: `layer_group_overlap_erase` passes at max 0 on clean master. Only ALPHA (Πaᵢ ≠ 1−Π(1−aᵢ)) was wrong |
| 4 | **Canary clean** | 112 tests / 171 PNGs | **171/171 md5-IDENTICAL**, no trace or image status moves. `layer_alpha`/`layer_erase` stay PASS at max 2 / 3 (zero-headroom, unchanged) |

Priced yield: **+0 graded flips** (expected: the corpus's only LAYER/ALPHA/ERASE rows are single-shape children,
where per-draw == exact, and they already pass). Deliverable value is game-visible: AS3 `BlendMode.LAYER/ALPHA/ERASE`
now works on the AVM2 path, and both paths do overlapping ALPHA children and LAYER inside filter/blend layers correctly.

## 1. L4 — the AVM2 twin (`avm2_display.c`)

`avm2_render_node` blend arm (`avm2_display.c` ~20766-20822), self-localized: one new `static int
g_avm2_layer_group_depth` (next to `g_avm2_blend_wrapped`, ~20634). The three hooks from `ee9ea8738`, plus the
child-layer path (§2):
1. `blend_skip` = ALPHA/ERASE **and** `g_avm2_layer_group_depth == 0` (was: unconditional).
2. Layered arm: `g_avm2_layer_group_depth++/--` around the re-entrant render when `bm == 2`. LAYER (2) was already
   a trivial layered mode in `render_webgpu.c` after `ee9ea8738`, so mode 2 is now isolated on AVM2 too.
3. Non-layered arm: ALPHA/ERASE inside a group (and LAYER nested in an offscreen) try
   `renderer_begin_child_layer`; if that refuses, they fall back to per-draw `renderer_set_blend_mode(11/12)`,
   exactly like tag.c. A **filtered** LAYER node's filter offscreen is its group (depth++ around it).

**Fixture route (mxmlc is NOT in the cloud box; no AS3 compiler at all).** Every PlaceObject3 blend byte on an AVM2
timeline reaches the same arm as the AS3 setter (`set_blend_mode_name` → `blend_mode_id`,
`avm2_display.c:1994`). So `create_test_swf.py` takes upstream `layer_{alpha,erase}/test.swf` (static timeline,
no DoAction), sets FileAttributes.ActionScript3 and inserts a **hand-assembled minimal DoABC** (one script, init
= `getlocal0; pushscope; returnvoid`, no classes, 38 bytes). The DoABC is needed: the flag alone keeps the AVM1
entry point, because the recompiler picks AVM2 by emitted ABC. With the flag only, the before-leg measured PASS,
so the first attempt **did not** exercise AVM2. That's caught and fixed. Golden = upstream's Ruffle golden
(Ruffle renders a script-free timeline the same under both AVMs; confirmation is a local oracle request).

| test (graphics) | clean `origin/master` | this patch |
|---|---|---|
| `regression/avm2_layer_group_alpha` | **FAIL 66744 outliers, max 254** (= the AVM1 row's pre-`ee9ea873` numbers) | **PASS 0, max 2 (tol 2)** |
| `regression/avm2_layer_group_erase` | **FAIL 66949, max 255** | **PASS 0, max 3 (tol 3)** |
| `visual/blend_modes/masked_layer_cached_children` (the corpus's only runtime AVM2 `BlendMode.LAYER`) | PASS max 0 | **PASS max 0** (byte-exact vs golden; the cover rect is now really isolated under the stage mask) |

## 2. L5 — the exact model (`render_webgpu.c`)

Ruffle (`render/wgpu/src/surface.rs` ~236-243, `surface/commands.rs:216`): `blend()` opens a fresh surface per
blend-mode object; only `BlendMode::Layer` sets `LayerRef::Current`. ALPHA/ERASE are complex blends whose "parent"
is the nearest layer. `shaders/blend/alpha.wgsl`: `src.a > 0 ? (dst.rgb*src.a, dst.a*src.a) : discard`; erase:
`(dst*(1-src.a))`, same discard. So the child's subtree is composited **first** (normal-over inside its own
surface), then applied once.

**Mechanism.** Two new public functions, `render_webgpu_begin_child_layer` / `render_webgpu_end_child_layer`, with
`renderer_*` macros (graphics arm → real; flashbang arm → `(0)` / no-op) and `render_stub.c` stubs:
- `begin` (only when `offscreen_depth == 1 + open_levels`, no padded filter capture, stack < 4): ends the open
  offscreen pass, swaps `child_layers[level]` (lazily created tex / MSAA (`MSAA_SAMPLES`) / D24S8 set, same
  formats as `filter_tex_a`) into `filter_tex_a/view_a/msaa/ds`, and calls the existing
  `render_webgpu_begin_offscreen_pass`. That clears, bumps `offscreen_depth` and parks the clip. Returns 0 and
  touches nothing otherwise.
- `end(mode)`: `end_offscreen_pass`, swap back, resume the parent offscreen with colour `Load` and **stencil `Load`**,
  draw one fullscreen quad from the child texture with `child_layer_pipeline[k]`. That's 3 pipelines, all
  `MSAA_SAMPLES`, stencil-Equal at `mask_ref`, on `composite_pipeline_layout`, with their own tiny WGSL. ALPHA:
  colour+alpha `Zero/SrcAlpha`. ERASE: `Zero/OneMinusSrcAlpha`. Both run `fs_alpha_erase` (discard at `a <= 0`,
  as alpha/erase.wgsl). LAYER-in-offscreen: `One/OneMinusSrcAlpha` premultiplied over. Then it restores the draw
  pipeline and bind groups (same tail as `composite_blend`).
- `begin_offscreen_pass`'s `stencilStoreOp` Discard → **Store**, so a clip opened inside the group survives the
  child-layer break. That changes no pixel (canary 171/171), but it applies to every offscreen pass.
- Hardware blend vs Ruffle's replace-shader: `dst*src.a` per MSAA sample then resolve equals Ruffle's
  resolved-parent×a written to all samples (linear), up to rounding. The 3 analytic fixtures land at max 0.

**Callers.** `tag.c`, functions touched: `render_display_list` (nested blend arm: ALPHA/ERASE child layer first,
per-draw fallback; new LAYER-in-offscreen arm; and its per-entry `render_filtered_object` call: depth++ for a
filtered LAYER), `render_filtered_root_entry` (same depth++ for a filtered root LAYER entry). The two root loops are unchanged by this
patch. No button/mouse code (n-play-game is clear). `avm2_display.c`: `avm2_render_node` only.

| test (graphics) | clean `origin/master` | this patch |
|---|---|---|
| `regression/layer_group_overlap_alpha` | **FAIL 2400 outliers, max 128** (exactly the 30×40-px overlap × G,B) | **PASS 0, max 0** |
| `regression/layer_group_overlap_erase` | PASS 0, max 0 (per-draw erase is exact, §Verdict 3) | PASS 0, max 0 |
| `regression/layer_group_in_add_alpha` | **FAIL 6000, max 127** (LAYER not isolated in the ADD layer, ALPHA dropped) | **PASS 0, max 0** (one-level-only intermediate measured 1200; hence the 4-level stack) |
| `regression/avm2_layer_group_overlap_alpha` | **FAIL 12000, max 127** (AVM2: ALPHA dropped) | **PASS 0, max 0** |
| no-graphics compile/trace: `avm2_layer_group_alpha`, `layer_group_overlap_alpha` | — | PASS |

**Remaining limits (each with its completion mechanism):**
1. The LAYER entry's own cxform still multiplies each draw inside the group, not the composite (stated limit 4 of
   `w1-pixel-blend-mask`; same for every layered blend). Completion: render the group with an identity cxform and
   apply the entry's cxform in the composite (composite_wgsl params already carry a group alpha `w`). No corpus row.
2. Child layer refused, so per-draw fallback, inside a **padded** filter capture (`filter_pad != 0`, e.g. a blurred
   LAYER entry with an ALPHA child), at nesting > 4, or under an offscreen that is not on the stack (a
   filter/blend offscreen opened *inside* a child layer). Completion: give the padded set its own child sets (sizes
   differ), or make the child stack the general offscreen allocator (Ruffle's `TexturePool`).
3. Analytic goldens on 4 of 6 fixtures (LOCAL ORACLE REQUESTS #1). Pixel-aligned rects, so AA is not a factor.

## 3. Sweep

- **Render canary** (`render_canary.py`, standing set incl. `layer_alpha`/`layer_erase`): `before` = clean
  `origin/master` in a separate worktree (`/root/wt-before`, same downloaded tests, shared SWFRecomp build since
  this patch has no `SWFRecomp/` change), `after` = patch: **112 tests / 171 comparisons, 171 IDENTICAL, 0 DIFFERS,
  0 trace or image status changes.** The 3 new EOF members (below) capture PASS.
- **Every `visual/blend_modes/*`** (18, graphics, after): all PASS with the baseline's max_diff (add 2,
  alpha_no_layer 1, darken 2, difference 2, erase_no_layer 1, hardlight 3, invert 1, **layer_alpha 2**,
  **layer_erase 3**, lighten 2, masked_layer_cached_children 0, multiply 1, overlay 2, overlay_onto_stage 45/4ch,
  screen 2, shader_without_shader 0, subtract 2) and `shader_as_mask` FAIL 2100 (KF, = baseline).
- **Regression suite near the change**: every image-comparing regression row not in the canary
  (`avm1_parent_child_{bitmap_fill,morph,render,text}`, `avm2_parent_child_render`, `bitmap_pool_layer_cap`)
  PASS max 0. `avm2_timeline_solid` SKIP (no golden, unchanged). The 7 regression canary members are md5-identical.
- **Corpus blast radius** (PlaceObject3 blend byte scan + ABC string scan over every downloaded `test.swf`:
  visual, avm1, avm2, from_shumway, fonts, text). Static blend 2/11/12 appears only in `layer_alpha`,
  `layer_erase`, `alpha_no_layer`, `erase_no_layer`. Runtime `BlendMode.LAYER` appears only in
  `masked_layer_cached_children`. `visual/definefont4` and `avm2/away3d_advanced_shallow_water_demo` reference
  `BlendMode` with no `LAYER`, so the group depth stays 0 and they're unaffected. Not scanned: from_avmplus,
  from_gnash, misc categories (not downloaded; trace-only or script-free of BlendMode by the s25 w1 scan).
- Mode parity: no `swf_core.c` / `tag_stubs.c` / `NO_GRAPHICS` arm touched. No-graphics compiles the changed TUs
  (two tests above PASS). Browser build: `render_webgpu.c` uses only APIs already used in the file. Not
  built here (no emsdk in the cloud box).

## 4. Patch scope (`w2-avm2-layer-groups.patch`)

`SWFModernRuntime/src/rendering/render_webgpu.c` (+child-layer section before `pad_finish`, offscreen stencil
Store, free), `include/rendering/render_webgpu.h` (trailing fields `child_layers[4]`, `child_layer_pipeline[3]`,
`child_layer_open`, plus 2 prototypes), `include/rendering/renderer.h` (2 macros × 2 arms),
`src/rendering/render_stub.c` (2 stubs), `src/libswf/tag.c` (functions listed in §2), `src/avm2/avm2_display.c`
(§1), `ruffle-tests/render_canary_tests.txt` (+3 members at EOF), and the 6 new fixture dirs. No `SWFRecomp/` or
`verify_output.py` change. Siblings: no SIBLING_FILE_MAP.md was published. `tag.c` edits are inside the blend /
filter arms only.

## EXPECTED-FLIP LEDGER (for the coordinator's CI check)

- **Trace axis:** no moves. 6 new `regression` rows appear (`avm2_layer_group_alpha`, `avm2_layer_group_erase`,
  `avm2_layer_group_overlap_alpha`, `layer_group_overlap_alpha`, `layer_group_overlap_erase`,
  `layer_group_in_add_alpha`), all **pass** (empty `output.txt`, no traces). These are new rows, not flips.
- **Pixel axis (graded corpus):** **no moves.** Must-stay-pass watch: `visual/blend_modes/layer_alpha` (max 2 tol 2)
  and `layer_erase` (max 3 tol 3), zero-headroom, measured unchanged. `masked_layer_cached_children` stays max 0.
- **Pixel axis (new regression rows, images run):** all 6 PASS. avm2_layer_group_alpha max 2, avm2_layer_group_erase
  max 3, the other four max 0. Before this patch 5 of them would FAIL: 66744 / 66949 / 12000 / 2400 / 6000;
  `layer_group_overlap_erase` passes either way.

## New unclaimed leads

- **N1 (unverified hazard, S to check):** a **filtered** object *inside* any layered offscreen (LAYER/ADD/… group,
  `offscreen_depth == 1`) starts its filter offscreen through `begin_offscreen_pass`, which renders into the same
  `filter_tex_a` the open group lives in. `tag.c`'s nested filter gate only checks `g_filter_capture_depth`,
  which a blend layer does not raise. If it reproduces, the child-layer stack is the natural fix: wrap the filter
  capture in a swap. Fixture: this generator plus a PlaceObject3 BlurFilter on a child of sprite 4.
- **N2:** the stale `render_stub.c` lacks `render_webgpu_composite_blend` / `capture_backdrop` /
  `blend_mode_is_layered` (pre-existing; I only added my two). The ASAN stub harness would not link the blend
  arms. S.
- **N3:** limit 1 above (group cxform on the composite). Game-visible (`alpha` on a LAYER clip with overlapping
  children shows inner overlaps), no corpus row.

## LOCAL ORACLE REQUESTS

1. **Ruffle exporter renders (1 tick, quality low, as in each `test.toml`)** of
   `ruffle-tests/tests/swfs/regression/{layer_group_overlap_alpha,layer_group_overlap_erase,layer_group_in_add_alpha,avm2_layer_group_overlap_alpha}/test.swf`.
   Compare each to its analytic `output.expected.png` (tolerance 2). If they agree, keep the analytic golden or
   replace it with the Ruffle PNG. If they disagree, the Ruffle PNG is the golden of record, and the model needs a
   look (most likely spot: Ruffle's 8-bit child-layer rounding at a = 128/255).
2. **Ruffle exporter renders** of `regression/avm2_layer_group_{alpha,erase}/test.swf`. Confirm they match upstream's
   `visual/blend_modes/layer_{alpha,erase}/output.expected.png` (the golden copied here). That is the "AVM2 renders a
   script-free timeline identically" assumption.
3. (optional, game-visible) an mxmlc-built AS3 fixture that sets `blendMode = BlendMode.LAYER` / `ALPHA` from
   script, to cover the setter path end to end. The timeline fixtures reach the same render arm through
   `set_blend_mode_name`, so this only adds the setter's string → id mapping (already covered by
   `avm2/displayobject_blendmode`).
