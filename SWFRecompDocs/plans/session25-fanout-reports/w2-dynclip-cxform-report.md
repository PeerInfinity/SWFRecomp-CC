# s25 w2-dynclip-cxform: dynamic-clip colour transform + runtime ColorMatrix on dynamic clips

**Verdict: GO, landed as a patch.** `Color.setRGB` / `Color.setTransform` / `transform.colorTransform` and a runtime
`ColorMatrixFilter` now render on AVM1 `createEmptyMovieClip` Drawing-API clips and attached bitmaps in graphics builds,
concatenated over dynamic ancestors, and they reach a dynamic filter root's glow/shadow colour (A3 rule). The new fixture
`regression/avm1_dynclip_color_transform` is **pixel-exact against the Ruffle exporter golden (0 outliers, max diff 0)**.
The render canary (113 tests, 172 comparisons) is **171 md5-identical**. The 1 DIFFERS is the new member (fail → pass). The
17-row colour sweep is md5-identical outside this ledger. **No corpus row flips.** No corpus row combines a dynamic clip with
a colour transform and an image comparison (see §4), so this is a game-visible fix with a guard fixture, not yield.

## NEW files

- `ruffle-tests/tests/swfs/regression/avm1_dynclip_color_transform/{create_test_swf.py,test.swf,test.toml,output.txt,output.expected.png}`
  - `output.expected.png` is the coordinator's `w1-avm1-filters-complete-oracle/dyn_CEG.ruffle-0ddd12b6a.png`, byte-copied.
  - `output.txt` is `dyn_CEG.ruffle-0ddd12b6a.txt`.
  - `test.swf` is byte-identical to `CASES=CEG mkdyn.py`; the generator now defaults to `CEG`.
- `SWFRecompDocs/plans/session25-fanout-reports/w2-dynclip-cxform-probe/`: the probe `mkdyn2.py`, `dynclip2.swf` and
  before/after PNGs for it and for dyn_CEG. These are evidence only; nothing is graded on them.
- `w2-dynclip-cxform.patch` (generated with `git diff --binary` so the fixture PNG/SWF apply; `git apply --check -R` OK) and this report.

Modified files: `SWFModernRuntime/include/actionmodern/action.h`, `SWFModernRuntime/src/actionmodern/action.c`,
`SWFModernRuntime/src/libswf/tag.c` and `ruffle-tests/render_canary_tests.txt` (covering member appended at EOF, tier 1).
No new `.c`/`.h` files and no recompiler change.

## EXPECTED-FLIP LEDGER (for the coordinator's CI check)

| test | trace axis | pixel axis |
|---|---|---|
| `regression/avm1_dynclip_color_transform` (NEW) | pass (2 lines: `C 0`, `E 1`; identical on both legs and in no-graphics) | **NEW row: fail → pass** (before 30 620 outliers, max 255; after 0 outliers, max 0) |
| everything else | 0 moves expected | 0 moves expected (canary 171/171 identical, sweep 15/15 identical) |

If CI shows any other pixel or trace move, it is not explained by this patch. The likeliest cause would be a corpus row with
a tinted dynamic clip that my grep missed: it only scanned SWFs whose `test.toml` has `[image_comparisons]`.

## 1. Mechanism (owner `file:line`, origin/master `d08236ee`)

- **Writers work:** `colorSetRGB` (`action.c` ≈12210), `colorSetTransform` (≈12100) and the `transform.colorTransform`
  setter all write `mc->cx_*` on a dynamic clip. `ng_getColorTransform(name)` misses, because the clip has no display
  entry, so they fall back to the MC struct.
- **Nothing read them at render:**
  - `fillDrawingInfos` (`action.c` ≈32021) hard-coded `info->cxform_id = 0` for every Drawing-API leaf.
  - `apply_dynamic_mc_transforms` (`tag.c` 3145) minted only per-tick **matrix** slots.
  - `attached_bitmap_render_cb` minted an alpha-only cxform.
  - A dynamic filter root (`dyn_filter_root_cb` → `render_filtered_core` with a `FilteredSource`) never set `have_obj_cx`,
    so its glow / shadow colour skipped the clip's colour transform.
- **Why `_alpha` worked and the full cxform didn't:** `_alpha` has a bespoke route. `fillDrawingInfos` folds `mc->alpha`
  (when `as_set_flags & 32`) into the flat fill and line alphas. `dynMcChainAlpha` adds the dynamic ancestors' alpha, and
  `actionDynamicFilterGroupAlpha` supplies the group alpha of a filter root. Nothing equivalent existed for RGB mult or
  add.
- **Nested dynamic children:** they had neither channel. Probe H (parent tinted with `setTransform`, red child) rendered
  red before the patch.
- **Attached clips** (`attachMovie`): these have a `display_obj`, so `mcSyncColorToDisplayObj` plus the root/compose
  `cx_overridden` loops already tint their timeline content. They are out of this channel and unchanged. Drawing-API
  content inside an attached or placed clip is still cxform 0 (see Leads).
- **Runtime CM on a dynamic clip (item 3b):** `avm1LowerFilterObject` drops type 6, so a CM-only list never even made a
  filter root. Nothing composed it.

## 2. The `dyn_CEG` oracle: Ruffle matches Flash on every case (the census premise is refuted)

The census "mismatch" (red 14 400, green 10 384, blue 4 800) is **not** a Ruffle deviation. `mkdyn.py` always places the
three timeline sprites `p`, `q` and `r` (red 80×60 = 4 800 px each, at (200,40), (200,180), (360,180)). With `CASES=CEG`
none of them gets a filter, so they account for the red 14 400 exactly. Per case, from bounding boxes in the PNG:

| case | where | Ruffle | Flash semantics | match |
|---|---|---|---|---|
| C, dynamic rect + `[CM swap R/B]` | (360,40) | blue 4 800 px | blue (CM applies to the clip's content) | ✔ Ruffle does **not** skip runtime CM on a dynamic clip |
| E, dynamic rect + `[Glow black]` + `setRGB(0x00FF00)` | (40,180) | green box + green glow ramp (opaque ring + (47..243,255,47..243) falloff) | cx applies to the filter output too | ✔ |
| G, dynamic rect + `setRGB(0x00FF00)` | (200,300) | green 4 800 px | green (`setRGB` tints Drawing-API content) | ✔ |

Green 10 384 = E box 4 800 + G 4 800 + E's opaque glow ring 784. Because Ruffle matches Flash on all three cases, `dyn_CEG`
was used directly as the golden. **No new oracle was needed for the fixture.**

Before the patch our render was all six boxes red with a black glow (red 28 800 px, black 784).

## 3. Patch (exact scope)

`action.h`:
- `MovieClip` gains trailing fields `dynamic_cxform_slot`, `dyn_cx[20]`, `dyn_cm_flags`, `dyn_cm[20]` and `dyn_cm_post[20]`.
  MCs are calloc'd, so a zero value means none.
- `AttachedBitmapInfo` gains trailing fields `cxform_slot` and `cxform`.

`action.c`:
- **New `avm1DynClipCaptureCM(mc, arr)`**, called from `avm1SetRuntimeFilters` (one added line). It walks the setter's
  snapshot, converts each `ColorMatrixFilter.matrix` (row-major 4×5) to the 20-float cxform layout, and composes them in
  list order into `dyn_cm`. It also composes `dyn_cm_post`, the CMs after the first non-CM member. It does **not** touch
  `avm1LowerFilterObject` or `avm1McHasRuntimeFilters`, so a CM-only list still makes no filter root.
- `fillDrawingInfos`: `info->cxform_id = mc->dynamic_cxform_slot` (was `0`). This is 0 for placed clips and for untinted
  dynamic clips.
- `actionIterateAttachedBitmaps` fills the two new info fields.

`tag.c`:
- New static helpers before `apply_dynamic_mc_transforms`:
  - `dyn_mc_local_cxform`: local = cx ∘ CM. The **alpha multiplier is pinned at 1**, so `_alpha` keeps its existing route
    and is never applied twice.
  - `dyn_cx_is_identity`.
  - `dyn_mc_world_cxform`: composes over `dyn_mc_dynamic_parent`, the same chain as the matrix.
- `apply_dynamic_mc_transforms`: resets `dynamic_cxform_slot` every tick. It mints a slot only for a dynamic clip that has
  drawings or a bitmap and a non-identity world cx. It does this before the identity-matrix `continue`, from the existing
  per-tick cxform allocator (`g_next_dynamic_cxform_slot`, already reset before this call in both `tagShowFrame` and
  `tagRerenderFrame`).
- `attached_bitmap_render_cb`: draws through the slot. With `_alpha` < 100 it mints `slot ∘ alpha` (output-alpha row
  scaled) instead of the alpha-only slot.
- `FilteredSource` gains trailing fields `have_cx` and `cx[20]`.
  - `render_filtered_core` (src arm, one line) adopts them as `obj_cx`.
  - `dyn_filter_root_cb` (one line) fills them with the root's world cx, using `dyn_cm_post` for the root itself. This is
    the A3 rule the placed-entry route already uses: the leaves carry cx∘CM_all through their slots, and the filter colour
    takes cx∘CM_post.

Ordering follows Ruffle `display_object.rs` `render_base` (filters on the cached bitmap, colour transform after).
Effective = cx ∘ CM_n ∘ … ∘ CM_1, which is the same model the w1 prototype uses for placed clips.

## 4. Evidence

All runs are on the same box (cloud lavapipe), `--mode=graphics`. "Before" is clean origin/master (`git apply -R` of the
patch); "after" is this patch.

### Headline and colour sweep (md5 of the actual PNG, before → after)

| row | before | after | status |
|---|---|---|---|
| regression/avm1_dynclip_color_transform | `2533e377` FAIL 30 620 outliers, max 255 | `04608032` **PASS 0 / max 0** | **flip (new row)** |
| probe `dynclip2` (not graded; moved out of the suite) | `c4b9e56f` | `9b137995` | H/I/J red→blue/cyan/green; K/L (255,127,127)→(127,127,255)/(127,255,127) |
| regression/avm1_parent_child_{bitmap_fill,morph,render,text}, avm1_runtime_filters | — | — | identical, all PASS |
| visual/cache_as_bitmap/{avm1_color, color_transform, nested_color_transform, bitmap_changed (3 cmps), cab_mask_transform} | — | — | identical (avm1_color FAIL 1 200 both legs, pre-existing) |
| avm1/{bitmap_data_colortransform, bitmapdata_applyfilter_colormatrix, color, netstream_play_flv_screen} | — | — | identical (netstream FAIL both legs, pre-existing, sibling slot) |
| from_shumway/flash_geom_ColorTransform | — | — | identical PASS |

### Corpus grep

I decompressed every SWF whose `test.toml` has `[image_comparisons]` and searched for `setRGB`, `setTransform`,
`colorTransform`, `ColorMatrixFilter` and `createEmptyMovieClip`. Suites scanned: avm1, avm2, visual, from_shumway,
from_gnash, fonts, text and regression. Only 4 AVM1 rows combine a colour API with `createEmptyMovieClip`, and all 4 are in
the sweep and md5-identical. They tint BitmapData or timeline clips, not dynamic drawings.

### Probe `dynclip2`

The probe checks the paths the golden does not cover:

| case | setup | after |
|---|---|---|
| H | nested dynamic child under a `setTransform`-blue parent | blue |
| I | `transform.colorTransform = new ColorTransform(0,0,0,1,0,255,255,0)` | cyan |
| J | `attachBitmap` + `setRGB` | green |
| K | `_alpha 50` + `setRGB(blue)` | (127,127,255): alpha applied **once** |
| L | bitmap + `_alpha 50` + `setRGB(green)` | (127,255,127) |

### Render canary

`ruffle-tests/render_canary.py`, full list plus the new EOF member: **113 tests / 172 comparisons, IDENTICAL 171,
DIFFERS 1** (the new member, image fail→pass, trace pass→pass). No trace status changes. Capture time is 1 102 s per leg.

### Regression suite and mode parity

- `avm1_dynclip_color_transform` and `avm1_runtime_filters` PASS in **no-graphics** mode too (trace only).
- `swf_core.c`, `tag_stubs.c` and the `NO_GRAPHICS` arms are untouched. The action.c CM capture is shared code but has no
  trace effect.

### Not verified

- **Fidelity:** the new row has no CI actual PNG yet, so I could not do the byte-identity fidelity check. Its pass is an
  exact golden match (max diff 0), so CI-grade fidelity is very likely but unproven.
- **Browser (Emscripten) build:** not compiled (no emsdk in the cloud). The change adds only struct fields and code inside
  the existing `!NO_GRAPHICS || OFFSCREEN_RENDER` block of `tag.c`. CI's `deploy-pages` dry run would cover it.

## 5. Sibling overlap (`w2-avm1-filters`, the w1 prototype); not landed at my base `d08236ee`

- **`action.c` `actionIterateAttachedBitmaps` / the sibling's new `fillAttachedBitmapInfo` (MERGE NOTE, REQUIRED):**
  the sibling's `actionIterateDynamicSubtreeBitmaps` fills `AttachedBitmapInfo` through its own
  `fillAttachedBitmapInfo` on an uninitialised stack struct. If both land, add these two lines to `fillAttachedBitmapInfo`:
  ```c
  info->cxform_slot = mc->dynamic_cxform_slot;
  info->cxform = mc->dynamic_cxform_slot != 0 ? mc->dyn_cx : NULL;
  ```
  Without them `attached_bitmap_render_cb` reads garbage `cxform` and `cxform_slot`. My hunk in
  `actionIterateAttachedBitmaps` sits 6 lines below the sibling's `claimed` line, in a separate hunk.
  - The sibling's subtree bitmap pass sets `info.alpha = 100` for the root (group alpha). With my fields, a tinted root's
    bitmap inside its filter layer carries the root cx, which is the A3 rule and is correct.
- **`tag.c` `dyn_filter_root_cb`:** my one line follows `src.group_alpha`. The sibling edits the adjacent
  `dyn_filter_root_draw` (forward decl plus a bitmap call), in a different hunk with nearby context. Expect at most fuzz.
- **`avm1SetRuntimeFilters`:** I add one call line, and my new function sits just above its comment. The sibling edits
  `avm1LowerFilterObject`, `avm1McHasRuntimeFilters` and `avm1ApplyRuntimeFiltersToEntry`. They do not overlap, and the
  two compose:
  - the sibling lowers CM to type-6 entries and folds them for **placed** clips (`obj_runtime_cm`);
  - mine handles **dynamic** clips from the AS snapshot.
  - Their `avm1McHasRuntimeFilters` ignores type 6, so a CM-only dynamic list still makes no filter root, as on master.
- I did **not** touch `cxform_original_id`, `root_seed_cxform`, `filtered_object_cxform`, `compose_children` or
  `build_filter_chain`.

`n-play-game`: no button or mouse code touched. The functions I touched in `tag.c`/`action.c` are all named in §3.

## 6. Limitations (each with its completion mechanism)

- **Dynamic children of a PLACED or attached ancestor** do not inherit the ancestor's colour transform. The chain stops at
  `display_obj != NULL`, the same limit the matrix chain has (DYNAMIC_MC_DRAWING_TRANSFORM_PLAN).
  - Mechanism: seed `dyn_mc_world_cxform` with the anchor entry's composed cxform (its `cxform_id` slot after
    `compose_children`). This needs the cxform pass to run before `apply_dynamic_mc_transforms`, which is a reorder. S.
- **Drawing-API content of a placed or attached clip** (`mc->display_obj != NULL`) still draws with cxform 0.
  - Mechanism: in `fillDrawingInfos`, use `((DisplayObject*)mc->display_obj)->cxform_id` when the entry is
    `cx_overridden` or `has_cxform`. S, but it can move corpus pixels, so it needs a canary and corpus check.
- **`_root`'s own Color** (`g_root_cx_*`) is not folded into dynamic clips under `_root`. Same mechanism as the first
  limitation, with `_root` as the anchor.
- **`setTransform` with `aa` < 100 on a dynamic clip** (alpha via cxform without `_alpha`'s flag 32) is still not
  rendered on drawings. This is pre-existing: the fold keys on flag 32, and my slot pins the alpha mult at 1 to avoid
  double application.
  - Mechanism: carry `cx_aa` in the slot when `!(as_set_flags & 32)`. Trivial, but untested against an oracle.
- **Alpha OFFSET concatenation** (`ab` ≠ 0 under a parent alpha mult) is approximate. The fold multiplies, then the slot
  adds. No row exercises it.
- **CM placed before a glow on a dynamic filter root** is approximated: the glow is fed CM-transformed source. This is the
  same approximation as the w1 prototype's placed-clip rule.

## New unclaimed leads

1. Colour transform for Drawing-API content of placed or attached clips (the second limitation above). It is game-visible
   wherever a timeline sprite with a placement or `Color` tint also carries script drawings.
2. Dynamic-under-placed colour and matrix inheritance (the first limitation above), as one arc with the
   DYNAMIC_MC_DRAWING_TRANSFORM_PLAN matrix limitation.

## LOCAL ORACLE REQUESTS

1. **Optional (confirmation only, not blocking):** Ruffle exporter render (1 frame) of
   `SWFRecompDocs/plans/session25-fanout-reports/w2-dynclip-cxform-probe/dynclip2.swf`.
   - Expected, sampled at each box centre:

     | case | box at | expected |
     |---|---|---|
     | H | (40,40) | (0,0,255) |
     | I | (200,40) | (0,255,255) |
     | J | (360,40) | (0,255,0) |
     | K | (40,200) | ≈(127,127,255) |
     | L | (200,200) | ≈(127,255,127) |

   - If it matches `dynclip2.after.png`, it can become a second fixture (`regression/avm1_dynclip_color_transform_nested`)
     covering the nested, `transform.colorTransform`, bitmap and alpha paths.
