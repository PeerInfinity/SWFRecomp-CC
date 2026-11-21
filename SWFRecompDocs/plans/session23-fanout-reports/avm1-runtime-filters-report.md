# avm1-runtime-filters: AVM1 runtime `mc.filters = [...]` now renders

**NEW FILES (this branch):**
- `SWFRecompDocs/plans/session23-fanout-reports/avm1-runtime-filters-report.md` (this report)
- `SWFRecompDocs/plans/session23-fanout-reports/avm1-runtime-filters.patch` (apply this to master)
- `SWFRecompDocs/plans/session23-fanout-reports/avm1-runtime-filters-probe/` (evidence only, NOT a fixture):
  - `mkprobe.py`: a hand AVM1 assembler (MTASC is not in the cloud). `python3 mkprobe.py probe.swf`.
  - `probe.swf` (force-added: `*.swf` is gitignored), `probe.after.png` (our render, md5 `328e97cf`)
  - `empty_child_filter_bounds.before.png` (md5 `e77a38d4` = CI actual) and `.after.png` (md5 `18c037dd`)

No new runtime files (no new TU). No fixture dir. No `verify_output.py` change. One canary-list change:
`ruffle-tests/render_canary_tests.txt` gets `visual/filters/empty_child_filter_bounds` appended at EOF.

Base: origin/master `bed2dfc0`. Corpus: `download_tests.sh` on 2026-11-21. Ruffle source read at `0ddd12b6a`.

---

## 0. Verdict: GO. 1 pixel flip, 0 trace flips, 0 regressions on either axis

### EXPECTED-FLIP LEDGER (the coordinator checks CI against this)

| axis | test | before (CI-grade, this box) | after (predicted CI) |
|---|---|---|---|
| pixel | `visual/filters/empty_child_filter_bounds` | FAIL 24876 outliers, max 76 | **PASS 0 outliers, max diff 1** (tolerance 1) |
| trace | `from_gnash/actionscript.all/MovieClip-v8` | output_mismatch, 1024 passed / 53 failed checks | **still output_mismatch** (no flip), 1034 / 43: +10 checks, 0 lost |
| trace | (no other row moves) | | |

- Fidelity is CI-grade. My clean-master before render of the headline is byte-identical to CI's actual on
  `origin/ruffle-image-results` (`a53053e8`): md5 `e77a38d4` == `e77a38d4`. So the after verdict (0 outliers) is a CI prediction,
  not just an A/B.
- `MovieClip-v8` is `known_failure = true` and stays a mismatch in both legs. The +10 are real-Flash `check` lines
  (gnash `MovieClip.as:1142-1199`, the `_root.filters` contract) that now pass. No line that passed before fails now.
- **No-graphics:** the setter is shared code. All 34 AVM1 rows whose SWF names `filters` have identical status
  before and after (§5).

## 1. Diagnosis (confirms the dynclip report §4)

- Before this patch, the AVM1 `filters` setter (`action.c`) only stored the array in `mc->dynamic_props`.
- The renderer reads only `filter_type` / `filter_chain` on a display entry, and only `tagSetFilter` ever wrote those.
  So `clip.filters = [...]` was a silent no-op on every clip.
- A `createEmptyMovieClip` / Drawing-API clip has no display entry at all, so it had nothing to carry a filter.

**Premise attacks:**
- **"Placed and dynamic need different routes": confirmed.** A placed clip mirrors the lowered list onto its entry
  (the existing `render_filtered_object`). A dynamic subtree needs a new source for the filter layer.
- **"Group alpha is the overlap residue": confirmed.** With the subtree drawn into one layer and blitted once at `_alpha`,
  the overlap matches the golden (0 outliers).
- **"The empty glowing child must contribute no bounds": moot for us.** Our filter layer is stage-sized or padded, never
  bounds-sized. The muzzle has no geometry, so it draws nothing; it is also nested inside a filtered root, so it renders
  unfiltered inside the outer capture. Ruffle `68dcb8931` fixes a bounds computation we do not have.

**Two pre-existing bugs found and fixed along the way:**
- **`DropShadowFilter` ctor argument order was wrong.**
  - Ours read strength/quality/inner/knockout from args 9/6/7/8. Flash docs and Ruffle `drop_shadow_filter.rs:103-113`
    use 6/7/8/9.
  - Effect: a 9-argument `new DropShadowFilter(8,45,0,1,4,4,1,1,false)` became an **inner** shadow. My probe showed it
    as an inner, offset-inverted shadow before the fix.
  - No corpus test passes more than 6 args, so there is no trace movement.
- **`BevelFilter` ctor ignored `type` (args[10])** and always stored `"inner"`. It now follows Ruffle
  `bevel_filter.rs:164`: `"inner"`/`"outer"`/`"full"`, anything else becomes `"full"`, and an absent arg keeps `"inner"`.

**Getter contract, found by the canary trace diff (the first after-leg lost 5 `MovieClip-v8` lines):**
- The generic `dynamic_props` lookup in GetMember answered a stored `filters` array **by reference**. The cloning getter
  below it was effectively dead.
- Real Flash (the gnash expected output) requires:
  - a fresh array per read (`tmp1[0] !== tmp2[0]`, and `.push` on the result does not persist);
  - non-filter elements dropped (`[5,4,3]` reads back as length 0; `[Blur,"boh!",Conv]` as length 2);
  - an array-like plain object accepted (`fake` with `length` 3 reads back as 3);
  - a non-object value (`34`, `""`) clearing the list.
- These are Ruffle `movie_clip.rs` `set_filters` / `filters` semantics, now implemented (§2). That turned −5 into +10.

## 2. The patch (7 runtime files, +610 / −26, runtime only; +9 canary-list lines)

### `action.c`
- **`avm1LowerFilterObject`**: identifies the filter class by walking `__proto__` to `g_filter_protos_by_type`. It lowers
  the object into a `FilterListEntry` in the same layout swf.cpp emits for PlaceObject3. That layout has:
  - radians for angle;
  - 0..1 colours with Ruffle's `(a*255) as u8` alpha;
  - glow/shadow flags: bit0 compositeSource, bit1 knockout, bit2 inner;
  - bevel flags: bit0 onTop, bit1 composite, bit2 knockout, bit3 inner;
  - clamps: blur 0..255, quality 0..15, strength 0..255.

  Coverage by filter type:

  | filter type | how it is rendered |
  |---|---|
  | Blur, DropShadow, Glow, Bevel | exactly |
  | GradientGlow | as a glow, using the last colour (the recompiler's own PlaceObject3 approximation) |
  | GradientBevel | as a bevel, first colour = shadow, last = highlight (same) |
  | Convolution, ColorMatrix, DisplacementMap | not rendered (documented, §6) |
- **`avm1SetRuntimeFilters`**: re-lowers into a per-MC `FilterListData` (new trailing field `MovieClip::as_filters`,
  malloc'd once; MCs are immortal). It mirrors the list onto the clip's display entry when the clip has one:
  - `display_obj`, or for non-AS-created clips `resolveMCDisplayEntry`;
  - an AS-created clip is never name-resolved to a timeline entry.

  Mirroring sets the scalar `filter_*` from entry 0 plus `filter_chain`, exactly the pair `tagSetFilter` and
  `tagBeginFilterList` write. An empty list clears both, which also replaces SWF-authored filters, as Ruffle does.
- **Setter** (Ruffle `set_filters`):
  - An Array, or a plain object's own property values, is walked and the filter elements are `filterClone`d into a
    snapshot array. Non-filters are dropped.
  - A non-object value gives an empty snapshot.
  - The snapshot is stored for the getter and lowered for the renderer.
- **Getter**: the `dynamic_props` fast path now skips a stored `filters` array, so the existing cloning getter answers it.
- **Dynamic subtree support:**
  - `dynFilterRootOf` returns the outermost dynamic ancestor-or-self that has runtime filters.
  - `actionIterateDrawings` skips every clip at or below a filter root, while a hook is installed and
    `g_avm1_runtime_filter_mcs > 0`. It calls the hook once, at the root's position in the walk, and only when the subtree
    has geometry (`dynSubtreeHasDrawings`).
  - `actionIterateDynamicSubtreeDrawings` draws the subtree with alpha **relative to the root**: `g_dyn_alpha_root` stops
    the per-leaf `_alpha` fold at the root.
  - `actionDynamicFilterGroupAlpha` returns the root's `_alpha` times its dynamic ancestors' `_alpha`.
- **The two filter ctor fixes** (§1).

### `tag.c`
- `render_filtered_object` becomes a wrapper around `render_filtered_core(app, obj, const FilteredSource* src)`.
  With `src == NULL` every branch is the old code. With a source:
  - the chain comes from the runtime list;
  - the layer is always padded (the subtree's world is not tracked);
  - the capture and the crisp-source draws call `src->draw`;
  - with **group alpha < 1**, every filter, the last one included, composes into the layer (`to_layer`, no shadow
    pre-shift). The layer is then blitted once with `renderer_composite_filtered_alpha`.
- `dyn_filter_root_cb` / `dyn_filter_root_draw` form the hook. It is installed only around the two root-loop
  `actionIterateDrawings` calls. Inside another capture or a mask it draws the subtree unfiltered, the same rule as nested
  PlaceObject3 filters.

### Renderer
- `render_webgpu.c`: `composite_wgsl` multiplies the sample by `params.offset_and_mode.w` when it is > 0. That field was
  previously always 0 ("unused"), and the multiply is by 1.0 then, so it is bit-exact for every existing caller, including
  `blend_layer_shader`, whose params are permanently zero.
- New `render_webgpu_composite_filtered_alpha`, plus its stub in `render_stub.c` and macros in `renderer.h`/`render_webgpu.h`
  for both graphics and null.
- No new pipeline, and no MSAA literal.

### Self-localization
- `MovieClip` gets one trailing field.
- The new code sits in its own blocks: after `filterClone`, around `dynMcChainAlpha`/`actionIterateDrawings`, in the
  `filters` setter/getter arms, in the two ctor arms, at `render_filtered_object`, and next to `drawing_render_cb`.
- No `swf_core.c` / `tag_stubs.c` / `#ifdef NO_GRAPHICS` arm is touched.

## 3. Fidelity (CI-grade)

| row | my before md5 (clean `bed2dfc0`) | CI actual md5 (`origin/ruffle-image-results` `a53053e8`) | verdict |
|---|---|---|---|
| `visual/filters/empty_child_filter_bounds` | `e77a38d4` | `e77a38d4` | identical: CI-grade |

## 4. Headline before/after (same box, graphics)

| test | before | after | md5 |
|---|---|---|---|
| `visual/filters/empty_child_filter_bounds` | FAIL 24876 / limit 0, max 76 | **PASS 0 / limit 0, max diff 1** | `e77a38d4` → `18c037dd` |

## 5. Sweeps

### Render canary A/B
- Command: `render_canary.py capture/compare`, `-P 2`, `--timeout 5400`. Before = clean master via `git apply -R` on the
  same box.
- Set: 190 tests / 195 PNGs.
  - The standing `render_canary_tests.txt` members (99).
  - Every `visual/filters/*` (24) and `visual/cache_as_bitmap/*` row.
  - Every AVM1 trace row whose SWF constant pool names `filters` (34, across avm1 / from_gnash / from_shumway / visual).
  - Every `regression/avm1_*` row, plus the regression rows whose SWFs draw or name filters (avm2_parent_child_render,
    avm2_graphics_runtime, …).
- The 28 avm2/fonts/text members were first missing locally. They were downloaded and re-captured; the merged label is
  `afterM`.

```
before vs afterM (first after-leg):  IDENTICAL 194   DIFFERS 1   APPEARED/VANISHED/NO_RENDER 0
  DIFFERS: visual/filters/empty_child_filter_bounds  (image fail->pass, trace pass->pass)
before vs after3 (FINAL code, 82 rows: all trace rows + all visual/filters + visual/cache_as_bitmap):
  IDENTICAL 60   DIFFERS 1 (the headline)   TRACE STATUS CHANGES: MovieClip-v8 mismatch->mismatch (+10 checks)
```

- The final code changed only the `action.c` setter/getter after `afterM`, so the 108 rows outside `after3`'s 82 are
  unaffected by that delta: they do not assign `filters`.
- `visual/cache_as_bitmap/oversize` is `compile_fail` in both legs. One intermediate run showed `recomp_fail`, an artifact
  of a run I killed. It is `compile_fail` again in `after3`.

### AVM1 `filters` trace rows, both modes
Per-row status, no-graphics, before → after (34 rows). **All identical**:

- **PASS:** assetnativeaccessor_ids, bitmap_data, bitmap_filters, bitmapdata_applyfilter_colormatrix,
  clone_sprite_edittext(_dynamic), displacementmapfilter_mappoint_throw_error, globals_swf6/7/8, movieclip_default_state,
  movieclip_state_values, native_double_construct, native_objects_swf7/8, native_subclasses, textfield_props_swf6/7/8,
  flash-v8, from_shumway/avm1/filters, visual/filters/avm1_convolution_initialization, empty_child_filter_bounds (trace).
- **RUFFLE_MATCHED:** bitmapdata_custom_rectangle, movieclip_library_state_values, textfield_props_swf5,
  MovieClip-v5/6/7.
- **MISMATCH (pre-existing, unchanged):** global_instance_decls, globals_monkeypatch, globals_swf5, native_objects_swf6,
  MovieClip-v8.

Graphics mode: the same rows sit inside the canary set above. Trace text is byte-identical except `MovieClip-v8`
(+10 checks, 0 new FAILED lines).

### Regression suite
All `regression/avm1_*` rows (18) and the drawing/filter-related regression rows are in the canary set: md5- and
status-identical.

### Probe (`avm1-runtime-filters-probe/probe.swf`, 550×300, 1 frame; render `probe.after.png`)

| case | setup | our after render | trace |
|---|---|---|---|
| A | placed timeline sprite `p`, `p.filters = [GlowFilter(0x0000FF,1,10,10,3,1)]` | blue glow around the red box (it was a plain box) | `A 1` |
| B | `arr=[BlurFilter(2,2,1)]; q.filters=arr; arr[0].blurX=arr[0].blurY=40` | slight blur 2 (the snapshot), not 40 | `B 2` |
| C | `r.filters=[DropShadow]; r.filters=null` | no shadow | `C 0` |
| D | dynamic `dd` (2 overlapping Drawing-API children), `_alpha 50`, `DropShadow(8,45,…)` | shadow bottom-right; overlap uniform (group alpha); shadow at 50 % | — |
| E | dynamic `ee`, `BevelFilter(5,45,0xFFFFFF,1,0,1,6,6,2,1)` | dark bevel edge bottom-right (white highlight on white bg) | — |

The traces are my reading of Flash/Ruffle semantics, not an oracle (see LOCAL ORACLE REQUESTS).

## 6. Not finished / limitations (each with its completion mechanism)
- **ColorMatrix / Convolution / DisplacementMap runtime filters are not rendered.**
  - PlaceObject3 folds ColorMatrix into the cxform and approximates Convolution as a blur. Neither has a runtime consumer.
  - Mechanism: a CM arm that composes the matrix into the entry's `cx_*` override (placed clips) or the group blit
    (dynamic). No corpus row today.
- **Gradient filters use the recompiler's single-colour approximations**, the same as SWF-authored ones. Mechanism: a
  real gradient-ramp compose shader, which would serve both routes.
- **Dynamic subtree content other than Drawing-API paths** is not in the filter layer: `attachBitmap` bitmaps, text fields,
  attached timeline children. Mechanism: call `actionIterateAttachedBitmaps` (and the text walk) with the same
  root filter inside `dyn_filter_root_draw`.
- **Dynamic-clip colour transform** (`Color`/`cx_*` on a dynamic clip) is not applied to the filter output. That is lead R3
  of the dynclip report and pre-existing.
- **Nested filter roots** render unfiltered inside the outer capture: the same rule as nested PlaceObject3 filters.
- **A placed timeline sprite with BOTH timeline content and Drawing-API content** gets two filter layers (entry +
  drawings) instead of one. No corpus row has this.
- **attachMovie clips' standalone `display_obj`:** the lowered chain is mirrored onto it, but whether the root loops send
  that struct through `render_filtered_object` was not measured (no corpus row).
- **Regression fixture:** none added. Its expected PNG/trace need an oracle outside SWFRecomp (below). Once returned, add
  `regression/avm1_runtime_filters` (probe.swf + oracle `output.expected.png` + `output.txt`) and append it to the canary.

## New unclaimed leads
- **L1: the AVM1 `filters` getter for SWF-authored filters only resolves ROOT-depth entries** (`ng_objRootDepth`), so a
  PlaceObject3-filtered clip nested in a sprite reads back `[]`. Trace-only, no corpus row measured.
- **L2: `MovieClip-v8` still has 43 failing checks.** The `filters` block is now clean apart from the 1194
  `ch.toString()` check (Array-ctor override path); price the rest separately.

## LOCAL ORACLE REQUESTS
1. **Ruffle exporter render (1 frame) + trace** of
   `SWFRecompDocs/plans/session23-fanout-reports/avm1-runtime-filters-probe/probe.swf` (550×300).
   - Expected trace (Flash semantics): `A 1`, `B 2`, `C 0`.
   - Compare the render with `probe.after.png` (md5 `328e97cf`). Especially check D's group-alpha overlap and shadow
     direction, and E's bevel.
   - Use: the expected output for a `regression/avm1_runtime_filters` fixture (+ canary member).
