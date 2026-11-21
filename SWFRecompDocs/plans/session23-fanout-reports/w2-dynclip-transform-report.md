# w2-dynclip-transform: AVM1 nested dynamic-clip transform/alpha inheritance

**NEW FILES (this branch):**
- `SWFRecompDocs/plans/session23-fanout-reports/w2-dynclip-transform-report.md` (this report)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-dynclip-transform.patch` (apply this to master)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-dynclip-transform-probe/`. These are evidence only, not fixtures:
  - `mkprobe.py`: a hand AVM1 assembler, since MTASC is not in the cloud.
  - `nest3.swf`, `nest3.before.png`, `nest3.after.png`
  - `nofilters.swf`, `nofilters.after.png`
  - `*.swf` is gitignored, so these were force-added.

No new runtime files. No fixture dirs, no `verify_output.py` change and no canary-list change (see §5 for why).

Base: origin/master `22a3613a`. Upstream corpus: `download_tests.sh` on 2026-11-21. Upstream master was `aa9f62a70` at the time.

---

## 0. Verdict: GO (transform + alpha). 0 flips. Headline 72840 → 24876 outliers, 0 regressions

### EXPECTED-FLIP LEDGER (the coordinator checks CI against this)

| axis | test | before (CI-grade) | after (predicted CI) |
|---|---|---|---|
| pixel | `visual/filters/empty_child_filter_bounds` | FAIL 72840/0, max 255 | **FAIL 24876/0, max 76** (no flip; it improves) |
| trace | (none) | | |

- **No pass→fail and no fail→pass on either axis.** Every other row in the A/B is md5-identical.
- If CI shows `empty_child_filter_bounds` with an outlier count other than 24876, the cause is not this patch's geometry. It is
  byte-deterministic here and the before-leg is CI-identical (§2).
- **The headline cannot flip from this slot.** The residue is the `filters = [BlurFilter]` on the AS-created clip.
  - AVM1 runtime `mc.filters = [...]` **never reaches any renderer** (§4).
  - That missing feature owns both the blur fringe and the group-alpha overlap. Priced in §4.

## 1. Diagnosis: the rule that breaks, and its owner

Owner, before the patch: the Drawing-API render route for AS-created clips.
- `SWFModernRuntime/src/actionmodern/action.c` `actionIterateDrawings` (≈32001) is a **flat** walk of `child_mc_cache`.
- It calls `fillDrawingInfos` (≈31601) on each clip using **only that clip's own** AS state:
  - Matrix: `mc->dynamic_xform_slot`, built by `tag.c apply_dynamic_mc_transforms` (≈3070) from `apply_as_transform(mc)`
    alone, and **only** when `mc->as_set_flags != 0`. Otherwise it falls back to `last_transform_id` (= slot 0, identity).
  - Alpha: `mc->alpha`, and only when `mc->as_set_flags & 32`.
- The code says so itself (tag.c comment, now updated): *"Limitation: only world-space-equals-local-space cases work right now
  (parent chain is identity)… Tracked in DYNAMIC_MC_DRAWING_TRANSFORM_PLAN."*

**The rule that breaks: a Drawing-API clip inherits nothing from any ancestor.** That covers position, scale, rotation and `_alpha`.

**Premise attack** (the brief framed it as "properties set AFTER children are drawn"):
- **Ordering: refuted.** In `test.as`, `_x/_y/_xscale/_yscale` are set **before** the parts are created. Only `_alpha` and `filters`
  come after. The render reads live state every tick, so ordering is irrelevant. Probe case B (props set after drawing) and case A
  (props set before) fail identically on master and are both fixed by the patch.
- **Nesting depth: refuted as the cause; any depth ≥ 1 below a transformed non-root ancestor breaks.** Probe case A is depth 3
  (`a > b > c`) and composes exactly after the patch.
- **The Drawing-API route: confirmed.** It is the only route involved. `attachBitmap` on a dynamic clip shares `dynamic_xform_slot`,
  so it inherits the fix for free.
  - Placed or attached children of a placed parent go through `compose_children`, which already composes.
  - Not in this route and not fixed: a dynamic child of a **placed** (timeline) transformed sprite. The chain deliberately stops at
    `display_obj != NULL`. See leads.
- **The `filterz` A/B** (padded-filter §5 recipe, `probe/nofilters.swf`): master renders the identical one black shape. After the
  patch, both clips are at x=60/320, 2× scale, 40 % alpha, with the overlap darker (per-leaf alpha). That is Flash's no-filter rendering.

Probe matrix (`probe/mkprobe.py` → `nest3.swf`). Geometry is analytic, checked by colour-class bounding boxes:

| case | setup | master | patch | analytic |
|---|---|---|---|---|
| A | depth 3: `a(_x50,_y20,_xscale200,_alpha50) > b(_x10,_y10) > c` red 50×50 | opaque red at (0,40)-(49,49), half hidden under B | (255,127,127) box (70,30)-(169,79) | x 70..170, y 30..80, 50 % red |
| B | depth 2: `d > e` blue 100×40, then `d._x300,_y150,_yscale50,_alpha50` set AFTER drawing | opaque blue (0,0)-(99,39) | (127,127,255) box (300,150)-(399,169) | x 300..400, y 150..170 |
| C | control: untransformed parent, `g._x400,_y20` green 30×30 | (400,20)-(429,49) | identical | (old path, unchanged) |
| D | hairline `lineStyle(0)` 400×200 on `h(_x100,_y150,25 %) > k` | 1 px box at origin | 1 px box at (100,150)-(200,200) | 1 px min stroke in world |

## 2. Fidelity (CI-grade)

`origin/ruffle-image-results` is at run `44922638965`.

| row | my before md5 (`22a3613a`) | CI actual md5 | verdict |
|---|---|---|---|
| `visual/filters/empty_child_filter_bounds` | `99cd8a25` | `99cd8a25` | identical: CI-grade |
| `avm1/netstream_play_flv_screen` | `7dc6ff78` | `7dc6ff78` | identical (and unchanged after) |

## 3. The patch (3 files, +103 / −7 lines, runtime only)

1. `SWFModernRuntime/src/libswf/tag.c`. Three new `static` helpers sit above `apply_dynamic_mc_transforms`:
   - `dyn_mc_dynamic_parent`
   - `dyn_mc_chain_has_xform`
   - `dyn_mc_compose_parent_chain`

   In `apply_dynamic_mc_transforms`:
   - A dynamic clip now gets a slot when it **or any dynamic ancestor** has spatial AS flags.
   - The slot is `ancestors ∘ local`. The walk stops at `_root`, a placed/attached ancestor (`display_obj != NULL`) or a removed one,
     and is bounded at 64 levels.
   - A clip with no flags and no transformed ancestor still `continue`s, exactly as before.
   - A clip with flags and no transformed ancestor builds the identical matrix (the compose loop does not run).
2. `SWFModernRuntime/src/actionmodern/action.c`. New `static dynMcChainAlpha`. `fillDrawingInfos` multiplies the dynamic
   ancestors' AS `_alpha` into the flat fill/stroke alpha, only for `mc->display_obj == NULL` (no double-apply with
   `compose_children`). This is per-leaf alpha: Flash's rule when no ancestor is layer-composited.
3. **OOB fix** (pre-existing, but this patch would have widened it). `fillDrawingInfos`' hairline-stroke min-width code read
   `transform_data[info->transform_id]`, and for `dynamic_xform_slot` that index is a GPU-only slot **past the end of the CPU array**.
   - This was documented as "long-standing exposure" in the code comment.
   - The patch slots more clips, so it would have hit more often.
   - Fix: `apply_dynamic_mc_transforms` stashes the composed a/b/c/d in a new **trailing** `MovieClip` field
     `float dyn_xform_lin[4]` (`action.h`, end of struct). `fillDrawingInfos` reads that whenever `dynamic_xform_slot != 0`.
   - On the A/B set this moved nothing, including root-level AS-scaled stroked clips. Probe D shows it is correct for nested ones.

Self-localization:
- Edits are in `apply_dynamic_mc_transforms` (tag.c ≈3020–3115) and `fillDrawingInfos` (action.c ≈31600–31730), plus a trailing
  struct field.
- No sibling region is touched: video props, devicefont, XML/AMF.
- No new TU and no `#ifdef NO_GRAPHICS` arm. `tag.c` helpers live inside the existing `!NO_GRAPHICS || OFFSCREEN_RENDER` guard.

## 4. Headline residue priced: AVM1 runtime `filters` are never rendered (lead R1)

- After the patch, `empty_child_filter_bounds` geometry is exact:
  - Edges at x=80/120…
  - Interior 153 vs golden 154 (inside tolerance 1).
- The remaining 24876 outliers are exactly:
  1. The **overlap** region: ours 92 (per-leaf 40 %, twice) vs golden 154 (group alpha, since the filter forces a cached bitmap).
  2. The **blur fringe** around every edge.
- Mechanism: the AVM1 `filters` setter (`action.c` ≈54352) only stores the array in `mc->dynamic_props` for the getter.
  - Nothing in `tag.c` or `rendering/` reads it.
  - `filter_type` on a display entry is only ever set by the SWF-authored `tagSetFilter`.
  - So AS2 `clip.filters = [...]` is a no-op on **every** clip, placed or dynamic. A dynamic clip also has no display entry
    to carry a filter.
- **Corpus price: 1 pixel row.** I swept every image-graded test in visual/avm1/from_gnash/from_shumway/regression/timeline/text/fonts
  for an AVM1 SWF (no DoABC) whose bytes name `filters` plus a filter class. Only `empty_child_filter_bounds` matched.
- Game-visible (AS2 games use glow/drop-shadow at runtime), but corpus-thin.
- Completion mechanism: a dedicated slot.
  1. Lower the AS filter array to the entry's filter list: placed clips via `display_obj`. For dynamic clips, render the dynamic
     subtree into the existing filtered-layer capture path with group alpha.
  2. Then `empty_child_filter_bounds` needs the empty-child glow to contribute no bounds (the test's actual subject).

## 5. Per-test before/after and sweeps (clean `22a3613a` worktree vs patch, same box, graphics)

### Headline
| test | before | after | md5 |
|---|---|---|---|
| `visual/filters/empty_child_filter_bounds` | FAIL 72840/0, max 255 | FAIL 24876/0, max 76 | `99cd8a25` → moves (expected) |

### Render canary A/B: `render_canary.py capture/compare`, `-P 2`, `--timeout 5400`
- Set: all standing `render_canary_tests.txt` members (99), plus every image-graded test whose SWF contains
  `createEmptyMovieClip|duplicateMovieClip|attachMovie|attachBitmap|beginFill|lineTo` across
  visual/avm1/from_gnash/from_shumway/regression/timeline/text/swf/mixed_avm.
  - That second group is 15 rows, including `avm1/mask_with_drawing`, `avm1/movieclip_{begin_gradient_fill,line_gradient_style}`,
    `from_gnash/misc-ming.all/BeginBitmapFill`, `from_shumway/{doubleAndRegister,flash_geom_ColorTransform}`,
    `visual/{scale_rotation_cache,scroll_rect_culling,static_text_offstage,blend_modes/masked_layer_cached_children}` and
    `regression/avm1_parent_child_{bitmap_fill,morph,render,text}`.
  - **111 tests / 169 PNGs** in total.
```
IDENTICAL 168   DIFFERS 1   APPEARED/VANISHED/NO_RENDER 0
DIFFERS: visual/filters/empty_child_filter_bounds  (image fail->fail, trace pass->pass)
TRACE STATUS CHANGES: (none)    IMAGE STATUS CHANGES: (none)
```
- The standing set's AVM1 image members never see a transformed dynamic parent. The only corpus row that does is the headline, which
  is not a canary member: it fails, so it gives no pass-guard.
- I did **not** append a canary member, because no passing row covers the change class. A canary of a failing row only guards md5.
  The coordinator may append `visual/filters/empty_child_filter_bounds` for md5 tracking.

### AVM1 trace rows reading `_width/_height/getBounds/localToGlobal/hitTest` on dynamic clips (after patch, both modes)
- Rows: `bitmap_data_pixeldissolve_image duplicate_movie_clip_drawing edittext_autosize edittext_width_height hittest_lockroot
  issue_2030 movieclip_default_state movieclip_getbounds movieclip_state_values nan_scale netstream_play_flv_screen`.
- **graphics:** all 11 trace PASS.
  - `bitmap_data_pixeldissolve_image` image PASS.
  - `netstream_play_flv_screen` image FAIL 44751, **pre-existing**: md5 `7dc6ff78` = before = CI actual.
- **no-graphics:** all 11 PASS.
- By construction the patch cannot move a trace. Every changed line is on a render-only route:
  - `fillDrawingInfos` callers are all in tag.c render code.
  - `apply_dynamic_mc_transforms` is graphics-only.
  - The new struct field is write-only outside render code.

### Regression suite (`--tests-dir=ruffle-tests/tests/swfs/regression`, graphics, after)
- Image rows: `mask_nested_intersect`, `mask_sibling_union` and `bitmap_pool_layer_cap` PASS 0/0.
- Trace rows: `avm1_display_prop_coercion`, `avm1_parent_child_bitmap`, `avm1_parent_child_modify_place`, `avm1_parent_child_sprite_meta`
  and `avm1_attach_clipevent_enterframe` PASS.
- The 4 `avm1_parent_child_*` image fixtures in the canary set are md5-identical (above).
- **No new fixture.** The fixed behaviour needs an oracle outside SWFRecomp.
  - The one corpus row is failure-masked by filters.
  - The probe SWFs have only analytic expectations, so they cannot be fixtures.
  - See LOCAL ORACLE REQUESTS.

### Mode parity
- No `swf_core.c`, `tag_stubs.c` or `#ifdef NO_GRAPHICS` arm is touched.
- The struct field is shared: no-graphics builds and runs it (11/11 trace above).

## 6. Not finished
- **Headline flip.** HOLD on lead R1 (§4), the AVM1 runtime-filters render feature. Completion mechanism: a dedicated slot.
- **Regression fixture.** It needs a Ruffle/Flash render of `probe/nofilters.swf` or `probe/nest3.swf` (LOCAL ORACLE REQUESTS).
  - Once that exists, add `regression/avm1_dynclip_parent_chain` (SWF + `output.expected.png` from the oracle) and make it a canary member.
  - That is the guard this change class lacks.

## New unclaimed leads
- **R1: AVM1 `mc.filters = [...]` is never rendered** (§4). 1 corpus pixel row (`empty_child_filter_bounds`). Game-visible.
- **R2: dynamic child of a PLACED transformed ancestor.** The chain stops at `display_obj != NULL`, so drawing-API clips created inside
  a timeline sprite still render in that sprite's local space, ignoring its matrix, `_alpha` and cxform.
  - No corpus image row was found exercising it (the A/B set is clean).
  - Completion: seed the chain with the placed ancestor's composed world matrix from `compose_children`'s per-tick slots.
- **R3: dynamic ancestors' `_visible` and Color/cxform are not inherited** either. `actionIterateDrawings` checks only `mc->visible`,
  and `cx_*` of dynamic clips are not folded. Same route, same fix shape; no corpus row measured.

## LOCAL ORACLE REQUESTS
1. **Ruffle exporter render, 1 frame**, of `SWFRecompDocs/plans/session23-fanout-reports/w2-dynclip-transform-probe/nofilters.swf`.
   - This is the corpus `empty_child_filter_bounds/test.swf` with its one `filters\0` constant patched to `filterz\0`.
   - Expected, if Flash/Ruffle per-leaf alpha holds: our `nofilters.after.png`, i.e. two 2×-scaled 40 % shapes with darker overlaps.
   - Use: the expected PNG for a `regression/avm1_dynclip_parent_chain` fixture.
2. Optional: the same for `probe/nest3.swf` (550×250, 1 frame; cases A–D in §1). It covers depth 3, set-after-draw and the hairline arm.
