# w1-avm1-filters-complete: AVM1 filters, the authored + runtime leftovers

**NEW FILES (this branch, all under `session25-fanout-reports/`):**
- `w1-avm1-filters-complete-report.md` (this report)
- `w1-avm1-filters-complete-prototype.patch`: the measured prototype, `git diff origin/master -- SWFRecomp/src SWFModernRuntime`
  (5 files, +339/−21). The source tree on this branch is reverted.
- `w1-avm1-filters-complete-probe/` (evidence, NOT fixtures):
  - `mkdyn.py`: a hand AVM1 assembler (helpers copied from s23 `mkprobe.py`). `CASES=ABD python3 -I mkdyn.py out.swf`.
    Cases A–G are listed in §3. Default `CASES=ABCDEG`. F (GradientGlow) is opt-in (`WITH_GRADIENT=1` or `CASES=...F`).
  - `dyn_ABCDEG.swf` and `dyn_ABD.swf` (force-added, 3.4 KB and 1.5 KB), with `*.before.png` / `*.after.png` and
    `*.predicted_flash.txt`. The predicted traces are my reading of Flash semantics, **not** an oracle.
  - `l1_nested_filters.{before,after}.png`: the s24 L1 probe (`session24-fanout-reports/w1-avm1-tail-probe/mkl1.py`)
    rendered on both legs.
  - `scan_nested_filters_any.py`: the s24 scanner with the "more than 1 filter or a non-simple filter" gate removed. It
    lists every SWF with ANY sprite-nested PlaceObject3 filter list.
  - `sweep.sh`, `sweep.before.txt`, `sweep.after.txt`: the 27-row A/B sweep (§4).

**Environment:**
- Base: origin/master `ca14fe02`.
- `download_tests.sh` 2026-11-22, upstream Ruffle `3ac8dcb07`.
- Categories: avm1 visual from_shumway avm2 from_gnash timeline swf text import_assets audio fonts mixed_avm stage3d. The
  extra categories were downloaded for the nested-filter scan only.
- `SETUP_STATUS`: apt / Pillow / Dawn all OK. Graphics runs use lavapipe.
- **Fidelity:** my render of `from_shumway/bitmapbuttons` is md5 `a806ccf6`, byte-identical to CI's actual on
  `origin/ruffle-image-results`. So local graphics grading is CI-grade on this box.

---

## 0. Verdicts and priced flips

**Corpus yield: 0 flips on either axis, for every item.** This is a game-visibility family.
- No image-graded row shows a sprite-nested multi/CM filter list, a runtime ColorMatrix / Convolution / DisplacementMap
  filter, a filtered `attachBitmap` root, a filtered dynamic clip under `Color`, or a visible gradient filter.
- The scans and greps that establish this are in §4.
- The prototype is **md5- and status-identical on all 27 swept rows** (§4).

| # | board item | verdict | price | measured |
|---|---|---|---|---|
| 1 | recompiler keeps only the FIRST simple filter of a DefineSprite PlaceObject3 list | **GO** (prototype) | S | the probe's nested row is now pixel-identical to its root twin; +4 trace lines on the probe |
| 2 | the `filters` getter for authored filters resolves ROOT depth only | **premise half-refuted; fixed by #1's 2-line getter change** | XS | see §2 |
| 3a | runtime ColorMatrixFilter, **placed** clip (root + nested) | **GO** (prototype) | S | B: (255,0,0)→(128,0,0). D: [Glow, CM]→ box blue, halo red |
| 3b | runtime ColorMatrixFilter, **dynamic** clip | **HOLD → folds into #5** (same channel) | (in #5) | C still red after the patch |
| 3c | runtime ConvolutionFilter | **NO-GO for a Ruffle-golden fixture** (Ruffle does not render it) | M–L shader | — |
| 3d | runtime DisplacementMapFilter (AVM1) | **HOLD-M** (reuse the AVM2 pass; no row) | M | — |
| 4 | a dynamic filter root's `attachBitmap` bitmaps are not in the filter layer | **GO** (prototype) | S | A: no halo → blue halo (69,69,255) |
| 4b | …its text fields and attached timeline children | HOLD-M | M | — |
| 5 | "the dynamic-clip colour transform is not applied to filter output" | **premise REFUTED as scoped**: the cxform is not applied to dynamic Drawing-API clips at ALL, filtered or not | M | G (no filter, `setRGB` green) stays red on both legs |
| 6 | gradient filters keep a single-colour approximation | **HOLD**: Ruffle does not render GradientGlow/GradientBevel at all, so there is no Ruffle oracle; a Flash oracle is needed | M–L | — |

**Recommendation for wave 2:** land the prototype (items 1+2+3a+4) as ONE patch. It is S in total, and the
`regression/` fixtures from LOCAL ORACLE REQUESTS #1/#2 are its guard. Fund #5 (+3b) separately as an M arc. It is the
dynclip R3 lead and is more game-visible than any filter item: `Color` on any `createEmptyMovieClip` drawing is a no-op today.

---

## 1. Item 1: the recompiler's sprite arm (GO, measured)

**Mechanism (confirms s24 §2):**
- `SWFRecomp/src/swf.cpp`'s DefineSprite PlaceObject3 arm (≈6085–6250 on master) keeps only the first simple filter, in
  scalar `tagSetFilter` form.
- It `cur_pos += 80`s past ColorMatrix, and it never emits the `tagBeginFilterList`/`tagAdd*` list the root arm emits
  (≈5123).
- The runtime list store `g_filter_lists[32]` (`tag.c` ≈13780) is keyed by **depth only**. A nested depth 2 would
  collide with root depth 2 in the very probe that shows the bug.

**Prototype (in the patch):**
- `swf.cpp`, new `static emitSpriteFilterList()` (next to `faceUnitsPerEm`). It re-parses the raw filter-list bytes,
  remembered as `sp_filter_list_start`, and emits the root arm's exact `tagAdd*` encodings into
  `{ static FilterListData _sflN; tagBeginFilterListAt(app_context, depth, &_sflN); … tagEndFilterList(…); }`.
  - It uses one static per placement **site**: no heap allocation per placement, no collision with the root table, and
    every instance of the sprite shares the same immutable authored list.
  - It needs no change to the 400-line parse switch except the ColorMatrix arm. That arm now folds the CM into the
    placement cxform exactly as the root arm does (`cxform_id = sp_cm_cxform_id`).
- `tag.c`: new `tagBeginFilterListAt()`. The "list being built" becomes a pointer (`g_current_filter_list`) instead of
  an index into the table, so `tagAdd*` works on either store. `tagBeginFilterList` behaviour is unchanged.
  Declared in `tag.h`.
  - Both are compiled unconditionally in `tag.c`, so all three builds link the symbol. No-graphics was verified (§4).
- `action.c` getter (`filters` arm of the MovieClip property getter, ≈59600): it reads `entry->filter_chain` first, and
  falls back to the by-depth table.

**Measured: the s24 L1 probe** (`mkl1.py`, 3 ticks, graphics):

| | trace vs `l1_nested_filters.predicted_flash.txt` (12 lines) | render |
|---|---|---|
| before | 4 lines differ: `outer.two n=1` (want 2), `1.blurX=undefined` (want 7), `outer.cm n=0` (want 1), `matrix.length=undefined` (want 20) | nested `two` has blur only (no shadow); nested `cm` is not darkened |
| after | **0 diff** (both modes) | the nested row (y 0–160) is **pixel-identical** to the root row (y 160–320) (`ImageChops.difference(...).getbbox() == None`) |

- md5: `da3c79b6` (before) → `5afbad14` (after).
- The prediction is from s24, not an oracle. Ruffle's getter reads the display object's own list, so it should agree.
  LOCAL ORACLE REQUEST #2 settles it.

**Corpus reach:** `scan_nested_filters_any.py` over all 13 downloaded categories found **4 SWFs** with any sprite-nested
PlaceObject3 filter list:
- `visual/filters/blur_scales_with_screen` [Blur]
- `visual/cache_as_bitmap/contains_grown_filter` [Glow]
- `from_shumway/bitmapbuttons` [Glow]
- `avm2/filter_rewind`: **3 nested ColorMatrix lists**. s24 did not scan avm2. This is a trace-only row, and its status
  is unchanged.

All 4 are md5- and status-identical before/after (§4). That is the predicted outcome: a single simple filter already
rendered through the scalar path, and a 1-entry chain renders identically.

**Side bugs found (not fixed; leads):**
- **Root arm: ColorMatrix REPLACES the placement cxform** (`swf.cpp` ≈4786: `cxform_id = color_matrix_cxform_id`, under a
  comment that says "compose with existing"). With several CMs, the last one wins. A PlaceObject3 with a ColorTransform
  AND a CM loses the transform.
  - The sprite-arm prototype mirrors this for parity.
  - Fix: compose at recompile time (emit `cx ∘ CM₂ ∘ CM₁`). XS. No corpus row has both.
- **Sprite arm: GradientGlow/GradientBevel scalar quality mask is `& 0x1F`** where the root uses `& 0x0F`. So onTop leaks
  into the pass count. The new list path uses `0x0F`; the scalar path still has the bug. XS.

## 2. Item 2: the getter "ROOT depth only" (premise half-refuted)

- s24 already showed that a nested **single** simple filter reads back correctly through `ng_getObjFilterData` (the
  entry's own scalar `filter_*`).
- What was broken was every nested list that is longer than 1, or that contains CM/Convolution/gradient members. Item 1
  never put those lists anywhere the getter could reach.
- With #1 in place, the fix is the two-line `entry->filter_chain`-first read. For root entries `filter_chain` IS the
  by-depth slot, so it is identical there.
- The getter's ExtFilterData fallback is now dead for nested entries. Leave it.

## 3. Items 3–6: the runtime (`mc.filters = [...]`) side

**Probe** (`mkdyn.py`, 550×400, SWF8, 1 frame; the before render is clean master):

| case | setup | before (master) | after (prototype) | Flash/Ruffle expectation |
|---|---|---|---|---|
| A | `createEmptyMovieClip` + `attachBitmap(BitmapData 60×40 red)` + `[Glow(0x0000FF,1,10,10,3,1)]` | bitmap, **no halo** | blue halo (69,69,255) | blue halo |
| B | timeline sprite `p` + `[ColorMatrix(halve RGB)]` | (255,0,0) | **(128,0,0)** | (127 or 128,0,0) |
| C | dynamic Drawing-API rect + `[ColorMatrix(swap R/B)]` | red | red (**not covered**, #3b) | blue |
| D | timeline sprite `q` + `[Glow(blue), ColorMatrix(swap R/B)]` | red box, blue halo | **blue box, red halo** (255,144,144) | CM after glow recolours both: blue box, red halo |
| E | dynamic rect + black Glow + `new Color(ee).setRGB(0x00FF00)` | red box, black halo | unchanged (#5) | green box, green halo |
| G | dynamic rect, NO filter, `setRGB(0x00FF00)` | **red** | red | green. Proves #5 is not a filter bug |
| F | (opt-in) sprite `r` + GradientGlow [white→blue→red] outer | red single-colour halo | same | Flash: a ramp. **Ruffle: no filter at all** (§3.4) |

Traces (A 1 / B 20 / C 0 / D.n 2 / D.0.blurX 10 / D.1.matrix.n 20 / E 1) match on BOTH legs: the runtime getter was
already right.

md5s:

| SWF | before | after |
|---|---|---|
| `dyn_ABCDEG` | `25379720` | `c64ba335` |
| `dyn_ABD` | `6e613af6` | `e355d9b8` |

### 3.1 Item 3a: runtime ColorMatrix on a placed clip (GO, measured)

**Mechanism:**
- Ruffle runs a CM as a filter pass over the cached bitmap (`render/wgpu/shaders/filter/color_matrix.wgsl`): unpremultiply,
  4×5 matrix, clamp, premultiply. The object's colour transform comes afterwards (`render_base`).
- Our cxform is the same straight-RGBA 4×5 shape (column-major 4×4 + add/255). So a CM **composes into the cxform**:
  effective = `cx ∘ CM`.
- That is exact for a CM-only list and for CMs after every other filter. A CM *before* a glow is approximated (the glow
  colour is not CM'd, which is correct; the source is CM'd, which is correct; only the clamp ordering differs).

**Prototype:**
- `action.c`:
  - `avm1LowerFilterObject` gains `case 6`, which keeps a type-6 entry with `cm_matrix` from `.matrix`.
  - `avm1ApplyRuntimeFiltersToEntry` mirrors the scalars from the **first non-CM** entry, which is `build_filter_chain`'s
    own `scalar_idx` rule. A CM-only list leaves `filter_type = 0` with the chain linked.
  - `avm1McHasRuntimeFilters` ignores CM-only lists, so a CM-only dynamic clip makes no filter root and does not lose its
    group alpha.
- `tag.c`:
  - `obj_runtime_cm()` composes the CMs of a **runtime** list only (`fl->depth == (size_t)-1`, the MC-owned list).
    Authored CMs are already in the recompiled cxform and are not applied twice. `visual/filters/color_matrix` is md5-identical.
  - The fold sits at the four cxform resolution points:
    1. the two root "runtime cxform" loops, via the new `root_entry_runtime_cxform()`, which mints a slot like
       `cx_overridden`;
    2. `root_seed_cxform`, so a sprite's children inherit `cx∘CM`. The base is read from the entry's ORIGINAL baked id
       through the new `cxform_original_id()`, because the root loop has already re-pointed it;
    3. `compose_children`'s own-cxform block, for nested placed clips, which also mints a slot;
    4. `filtered_object_cxform`, for **post-filter** CMs only (`suffix = 1`): the filter's own colour goes through them,
       which gives D's red halo.
- **Limitation:** the combination "authored cxform + runtime filter + post-filter CM" on a ROOT LEAF loses the authored
  cxform on the filter colour only. `filtered_object_cxform_base` cannot see a re-pointed slot; the existing A3 rule.
  This has no row.

### 3.2 Item 3b + item 5: the dynamic-clip colour channel (premise refuted as scoped; HOLD-M, one arc)

- `fillDrawingInfos` (`action.c` ≈32021) sets `info->cxform_id = 0` for every Drawing-API leaf. Only `_alpha` is folded,
  into the fill/line alphas.
- `Color.setRGB/setTransform` on a dynamic clip writes `mc->cx_*` (`colorSetRGB` ≈12210), and nothing reads it at render.
- Probe G (no filter) proves it. This is s23 dynclip **R3**, and it is broader than filters.

**Completion mechanism (M, ≈120 lines, `tag.c` + `action.c`):**
1. In `apply_dynamic_mc_transforms`, mint a per-tick cxform slot for every dynamic MC whose `cx_*` (composed over
   dynamic ancestors, the R3 chain) or runtime CM is non-identity. Store it in a new trailing `MovieClip::dynamic_cxform_slot`.
2. Make `fillDrawingInfos` and `actionIterateAttachedBitmaps` use it. Stop folding `_alpha` into fill alpha when the slot
   carries it, or keep both but never double-apply.
3. For a filter root: pass the root's `cx∘CM` into `render_filtered_core`'s `src` arm as `obj_cx`, so filter colours get
   it (the A3 rule). The leaves drawn by `src->draw` must then use the root-relative slot (cx below the root only), the
   same as `g_dyn_alpha_root` does for alpha.
- Slot budget: 256 dynamic cxform slots per tick (`render_webgpu.c`). Mint only for non-identity.
- **Rows:** none in the corpus. Probe cases C/E/G are the guard (LOCAL ORACLE REQUEST #1b).

### 3.3 Item 4: attached bitmaps in a dynamic filter root (GO, measured); text/attached children (HOLD-M)

**Prototype:**
- `action.c` gains:
  - `actionIterateDynamicSubtreeBitmaps(root, cb, ud)`, declared in `action.h`. The root's own `_alpha` is excluded: it
    is the group alpha of the blit.
  - `dynSubtreeHasDrawings` also counts bitmaps.
  - A claim flag set by `actionSetDynamicFilterRootHook(cb≠NULL)` and consumed by the next `actionIterateAttachedBitmaps`.
    That pass then skips bitmaps under a filter root.
- `tag.c`: `dyn_filter_root_draw` draws the subtree's bitmaps after its vectors, the same order as the global passes.
- The claim is scoped to the two root loops that install the hook. Any other caller of `actionIterateAttachedBitmaps`
  behaves as before.

**Not covered (M):**
- `createTextField` fields under a dynamic filter root. The text walk is separate (`actionIterateTextFields` +
  glyph pass). It needs the same subtree filter and a claim.
- attachMovie'd timeline children. They are `display_obj != NULL`, so `dynFilterRootOf` stops at them and they render
  through `compose_children`. They need the root's filter capture around their `compose` render. M–L.

### 3.4 Items 3c / 6: Convolution and gradient filters. NO Ruffle oracle exists

- `render/wgpu/src/filters.rs` (`3ac8dcb07`, the `filter =>` arm of `apply_filter`): **GradientGlowFilter,
  GradientBevelFilter and ConvolutionFilter are unimplemented.** Ruffle warns once and returns `None`, and the source
  passes through unfiltered.
- So a Ruffle-exporter golden of any such case shows NO effect. Our approximations do render something:
  - authored Convolution renders as a blur (`swf.cpp` case 5);
  - gradients render as a single-colour glow/bevel.
  - Our approximations would therefore *fail* a Ruffle golden while still not being Flash.
- Under the Flash-over-Ruffle rule, a fixture needs a **Flash** render. This brief's "Ruffle-exporter golden" premise
  does not hold for these two items.
- The corpus never shows one visibly: `any_blur_scales_with_screen` carries GradientGlow/GradientBevel PlaceObject3
  filters, but those cells are hidden (PlaceObject3 Visible).
- **Mechanism, if a Flash oracle ever exists:**
  - gradient: a 256-entry RGBA ramp LUT, sampled by the blurred (and, for bevel, the highlight−shadow difference) alpha
    in the glow/bevel compose shader. Both routes (authored list + runtime) already carry `grad_*` in `FilterListEntry`.
    M–L.
  - Convolution: an N×M kernel pass over the padded filter layer, with divisor, bias, clamp, preserveAlpha, default
    colour. M.
- **Lead:** decide whether the authored "Convolution as blur" approximation should simply be dropped. It matches
  neither Flash nor Ruffle.

### 3.5 Item 3d: AVM1 runtime DisplacementMapFilter (HOLD-M)

- `avm1FilterTypeOf` only knows protos 1–8, so a DM object is dropped at assignment. A PlaceObject3 cannot author a DM
  (there is no SWF filter id for it).
- The GPU pass exists: `render_webgpu_run_displacement`, driven by `avm2_display.c` ≈20051, a port of Ruffle's
  `displacement_map.rs`.
- **Mechanism:**
  - a DM proto slot;
  - trailing `FilterListEntry` fields (the map BitmapData's pixels/size, mapPoint, components, scale, mode, colour/alpha);
  - a DM arm in `render_filtered_core` that runs the pass over the layer.
- M. No corpus row. Ruffle implements it, so a Ruffle golden IS a valid oracle here.

## 4. Sweeps (all graphics; same box; before = clean `ca14fe02`)

**Argued scope:**
- The recompiler change only alters SWFs with sprite-nested PlaceObject3 filter lists. The scan found exactly 4.
- The getter change only alters entries whose `filter_chain` is an authored nested list: the same 4.
- The runtime changes only alter movies that assign `filters` (CM lowering / filter-root bitmaps) or have a runtime CM.
- `cxform_original_id` equals `cxform_id` unless the CM path re-pointed the entry.

**27-row A/B** (`sweep.sh`, `-P 2`, `--recompile`):
- the 4 scan rows;
- `regression/avm1_runtime_filters` and 3 `avm1_parent_child_*`;
- 8 `visual/filters/*` including `color_matrix`, `empty_child_filter_bounds` and `avm1_convolution_initialization`;
- `cache_as_bitmap/{cab_mask_filters,color_transform,nested_color_transform}`;
- `edittext_border_filters`, `acid-filter-2`, `from_shumway/avm1/filters`;
- `avm1/{bitmap_filters,bitmapdata_applyfilter_colormatrix,movieclip_state_values,native_objects_swf8}`;
- `MovieClip-v7`/`-v8`.

```
diff <(normalised before) <(normalised after)  ->  ALL 27 ROWS IDENTICAL (status + actual-PNG md5 + diff-line count)
```

- `MovieClip-v7/-v8` are `ruffle_matched` on both legs, which is their baseline status.
- `bitmapbuttons` fails on both legs. md5 `a806ccf6` = the CI actual, so this is pre-existing (618042 outliers).
- **No-graphics parity:** `l1_nested_filters`, `dyn_ABCDEG`, `avm1/bitmap_filters`, `from_shumway/avm1/filters` and
  `avm2/filter_rewind` all PASS without `--mode=graphics` with the patch.
- **Regression suite:** `avm1_runtime_filters` (md5 `328e97cf`, its golden-passing render) and the three
  `avm1_parent_child_*` rows are in the sweep, all identical.
- **Not run:** the full `render_canary_tests.txt` capture. The change class is gated as argued above, and the 27 rows
  cover every filter/cxform route the patch touches. **Wave 2 must run the canary** before landing (playbook rule).

## 5. Wave-2 patch scope (if funded)

- Files:
  - `SWFRecomp/src/swf.cpp`: `emitSpriteFilterList` + 4 small sprite-arm edits.
  - `SWFModernRuntime/src/libswf/tag.c`:
    - `tagBeginFilterListAt` and the pointer refactor;
    - `obj_runtime_cm`, `cx_set_identity`, `cxform_original_id`, `root_entry_runtime_cxform`;
    - wrappers `root_seed_cxform` / `filtered_object_cxform` over renamed `*_base`;
    - the `compose_children` own-cxform fold;
    - `dyn_filter_root_draw`.
  - `SWFModernRuntime/src/actionmodern/action.c`:
    - `avm1LowerFilterObject` case 6;
    - `avm1ApplyRuntimeFiltersToEntry`, `avm1McHasRuntimeFilters`;
    - the bitmap iterator + claim flag;
    - the `filters` getter.
  - `tag.h`, `action.h`: one prototype each.
  - Nothing touches the button/mouse dispatch the `n-play-game` session owns.
- Needs `--recompile` on the filter rows.
- Fixtures, once the oracles return:
  - `regression/avm1_nested_po3_filters` (`mkl1.py`, 3 ticks + image);
  - `regression/avm1_runtime_filters_cm_bitmap` (`CASES=ABD`). Append both to `render_canary_tests.txt`.
- **Expected-flip ledger: none in the corpus.** The two new fixtures pass after and fail before.

## New unclaimed leads

1. **Dynamic-clip colour transform is never rendered** (§3.2; dynclip R3). `Color.setRGB` on any `createEmptyMovieClip`
   drawing is a no-op in graphics builds. M. Game-visible, probably more so than any filter item. It also completes
   runtime CM on dynamic clips (#3b).
2. **Root PlaceObject3 ColorMatrix replaces the placement ColorTransform, and only the last of several CMs is kept**
   (`swf.cpp` ≈4786). XS, recompile-time compose.
3. **Sprite-arm gradient filter quality mask `& 0x1F`** (root uses `& 0x0F`). XS.
4. **Authored ConvolutionFilter renders as a blur:** neither Flash (a real convolution) nor Ruffle (pass-through). Decide
   whether to drop it to pass-through (matches Ruffle goldens) or implement it (Flash).
5. **AVM1 runtime DisplacementMapFilter is dropped at assignment** (§3.5). M, and a Ruffle oracle is valid.

## LOCAL ORACLE REQUESTS

The Ruffle exporter (`exporter -s -f <frames> --trace-log out.txt in.swf out.png`) on each of the following.

1. **`w1-avm1-filters-complete-probe/dyn_ABD.swf`** (550×400, 1 frame; regenerate with
   `CASES=ABD python3 -I mkdyn.py dyn_ABD.swf`): render + trace.
   - Expected trace (`dyn_ABD.predicted_flash.txt`): `A 1`, `B 20`, `D.n 2`, `D.0.blurX 10`, `D.1.matrix.n 20`.
   - Compare the render with `dyn_ABD.after.png` (md5 `e355d9b8`). Check:
     - A: blue halo around the bitmap;
     - B: (127|128,0,0);
     - D: blue box with a RED halo.
   - Use: the golden for `regression/avm1_runtime_filters_cm_bitmap`, which guards the wave-2 patch.
   - 1b (optional, the #5 arc's guard): the same for `CASES=CEG python3 -I mkdyn.py dyn_CEG.swf`. Expected: C blue; E green box
     with a green halo; G solid green.
2. **`session24-fanout-reports/w1-avm1-tail-probe/mkl1.py` → `l1_nested_filters.swf`** (550×400, SWF8): trace for 3
   ticks, plus a 1-frame render. This is s24's request #1, still unrun.
   - Expected: `l1_nested_filters.predicted_flash.txt` (12 lines). The render should match `l1_nested_filters.after.png`
     (md5 `5afbad14`): the nested row is identical to the root row.
   - Use: the golden for `regression/avm1_nested_po3_filters`.
3. **Not requested:** any GradientGlow/GradientBevel/Convolution case (`WITH_GRADIENT=1`). Ruffle's wgpu renderer does not
   render those filters, so its output is not a Flash oracle (§3.4).
