# wave-2 `w2-phase-cxform` — implementation report

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a5161c94aed953e3c`
(branch `master`, base `b007ee50d`). **No commits, no pushes.** Runtime-only —
`SWFRecomp/build` was copied from the main tree and never rebuilt.
Patch: `<scratch>/w2-phase-cxform.patch` (5 files, ~975 diff lines).

All four fixes landed as separate hunks in separate functions; each can be
dropped independently (see "Merge risks / how to drop one" at the end).

Baselines below are the merged CI board at `feb8882b0` (run `30701749687`),
read out of `ruffle-tests/tests/swfs/*/_results/image_results_graphics.json`.
"after" numbers are LOCAL Dawn — used only for pass/fail verdicts against the
test's own tolerance, never graded numerically against CI's lavapipe outputs
(and the one place that mattered, `timeline_loop`, was A/B'd locally instead —
see Fix 1).

---

## Fix 1 — defer the end-of-movie wrap-back promotion by one tick

**Files:** `SWFModernRuntime/src/libswf/swf.c` (4 hunks, all `OFFSCREEN_RENDER`).

**Mechanism.** The Phase-4 promotion (`swf.c:1150`) turned the natural
end-of-movie wrap into a script goto by setting `goto_from_action = 1`, and the
catch-up loop 20 lines below then executed `frame_funcs[0]` *inside the same
tick* — before `capture_tick_after_events` / `capture_tick_post_frame`. So the
movie's last frame was never displayed and every later capture was one tick
early (`simple_loop_test` rendered with period 3 where Flash/Ruffle have 4).

The promotion exists for the `survives_rewind` cleanup semantics, not to
re-run the frame early. The fix hands the cleanup half to the top of the *next*
tick (`g_pending_natural_wrap_promote`, consumed right after
`current_frame = next_frame`), where it mirrors the catch-up loop's
`target <= original_frame` arm with target 0 — `ng_display_clear_after` →
`actionRewindCleanup` → `g_natural_wrap_cleanup_pending = 1` →
`catch_up_backward = 1` — and lets that tick's own `frame_funcs[0]` be the
replay. A close-out half after the frame func resets `catch_up_backward` and
runs `ng_display_cleanup_unplaced_after`, with a safety net later in the tick
in case the frame-func gate declined to run. The light wrap path at the end of
the tick is suppressed while a promotion is pending (it would clear the display
list the deferred half still needs).

Side benefit: the promotion no longer fires on the run's LAST tick (there is no
next tick to consume it), which is the same protection `_wrap_is_last_tick`
already gave the light path.

### Ledger

| comparison | CI baseline | after (local) | verdict |
|---|---|---|---|
| `from_gnash/misc-ming.all/loop/simple_loop_test` `frame1` | fail 242 out | fail 242 | unchanged (hairline) |
| … `frame2` | fail 483 | fail 483 | unchanged (hairline) |
| … `frame3` | fail 21600 | fail 724 | **phase fixed**, hairline residue |
| … `frame4` | fail 7442 | **pass 0** | **FLIP** |
| … `frame5` | fail 7683 | fail 242 | **phase fixed**, hairline residue |
| … `frame6` | fail 14400 | fail 483 | **phase fixed**, hairline residue |
| … `frame7` | fail 14702 | fail 724 | **phase fixed**, hairline residue |
| `from_shumway/timeline/timeline_loop` `output.*` | 7 fail | identical A/B | **not this mechanism** |

**Honest count: +1 flip, not the +5 wave-1 predicted.** The period is now
correct (`RGB / blank / R / RG / RGB` matching Ruffle exactly — `frame4`, the
blank tick, is byte-exact), but frames 1/2/3/5/6/7 all land in the same
242-per-shape hairline pixel-snapping class that already dispositioned
`frame1`/`frame2`. Wave-1 counted those as flips; they are not, at tolerance 1 /
max_outliers 0. What the fix buys is that the residual is now *only* the
hairline class instead of a whole-frame phase error (21600 → 724 etc.), so the
test becomes a clean single-mechanism candidate for the snapping work.

`timeline_loop` was explicitly A/B'd locally (stash the fix, re-render): the
seven comparisons are **byte-identical before and after**, so it is untouched
by this fix. Its CI-vs-local outlier gap (83 vs 726 on `output.02`) is the
documented local-Dawn-vs-lavapipe difference, not a regression.

### Mandatory gate
`from_gnash/misc-ming.all/place_and_remove_object_insane_test` — the test the
Phase-4 block exists for, and the last strict no-graphics/graphics parity gap —
**still passes** (trace, run standalone with the fix in).

---

## Fix 2 — AVM1 EditText box: world matrix + device-font cull

**Files:** `SWFModernRuntime/include/actionmodern/action.h`
(`TextFieldRenderInfo` + 4 new fields), `.../actionmodern/action.c`
(`actionIterateTextFields` + two new statics), `.../libswf/tag.c`
(`textfield_render_cb`).

**Mechanism (three bugs, one family).**

1. The box was drawn through **transform slot 0 (identity)** with only the
   parent-chain *translations* summed and the field's **unscaled** local
   `mc->width/height`. `_xscale` / `_yscale` / `_rotation` and any ancestor
   `transform.matrix` were discarded outright. Now `actionIterateTextFields`
   computes the field's full world matrix (`tf_world_matrix`, the same local ×
   parent-chain composition `mc_get_local_mouse` already used) and ships it on
   the info struct; `textfield_render_cb` allocates a GPU transform slot for it
   and emits the box in **field-local twips** through that slot.
2. **Ruffle's device-font transform cull** (`edit_text.rs:2698-2702`,
   `ALLOWED_SHEAR = 0.006`) was missing: a field that is not `embedFonts` is
   not rendered at all when its transform is rotated, sheared or reflected.
   Ported as `tf_transform_positive_scale_only` and applied to the box path.
3. Two rasterisation details, both found by pixel-dumping the expected PNGs:
   * Flash's extra right/bottom edge pixel is a **device** pixel (it comes from
     the border polyline), not a local one, and it applies to the **border
     only** — the background is exactly `bounds`. It is now added after
     dividing by the matrix's per-axis scale, and mapped through the inverse
     matrix so a reflection grows on the local −x/−y side and a 90° rotation
     swaps which local axis grows.
   * Ruffle's border is an **open polyline**, so the screen bottom-right corner
     pixel is not drawn. Reproduced for the plain positive-scale case (the only
     case where local and screen bottom-right coincide).

### Ledger

| comparison | CI baseline (out/limit) | after (local) | verdict |
|---|---|---|---|
| `visual/edittext/edittext_border_transform` `output.01` | fail 375/0 | **pass 0** | **FLIP** |
| … `output.02` | fail 2034/0 | **pass 0** | **FLIP** |
| … `output.03` | fail 1717/0 | **pass 0** | **FLIP** |
| … `output.04` | fail 524/20 | fail, excess 52 | improved ~10× |
| … `output.05` | fail 2822/20 | **pass** (0 over tol) | **FLIP** |
| … `output.06` | fail 2544/20 | fail, excess 45 | improved ~50× |

A **fourth** mechanism was added after the first canary pass: device-font
fields take Ruffle's `draw_device_text_box` (`edit_text.rs` ~2845) — the bounds
are transformed, then their axis-aligned SCREEN bbox is pixel-snapped and drawn
upright, so a device-font box never rotates or shears with the matrix, even for
the small rotations that survive the cull. It bought `edittext_border_basic`
2004 → 1227 and `_background_basic` 2072 → 1902; see the canary section for the
one margin it did not close.

**+4 flips** (wave-1 predicted up to 6). `output.04`/`.06` are the
`embedFonts = true` border ticks: the rotated/sheared boxes are now
geometrically correct (diamond, parallelograms, right sizes, `max_diff` down
from 255 to 207) and the residual is **renderer-level AA parity on a rotated
1-px line** — Ruffle draws them with `draw_line_rect` line primitives (a 45°
band rasterises 3 px wide with AA), we draw filled quads (2 px). That is an AA
arc, not a sweep item.

Riders (`edittext_border_basic`, `_background_basic`, both `_scale2`,
`edittext_gutter`, `edittext_border_filters`,
`edittext_device_transform_small_shear`) are in the canary; results below.
`edittext_device_transform_small_rotation` (**already passing on CI**, so a
pass→fail risk from the cull) was checked standalone and still passes.

---

## Fix 3 — colour-transform composition, both VMs

### 3a AVM1 — `compose_children` composed instead of inherited
**File:** `SWFModernRuntime/src/libswf/tag.c`.

`compose_children` had exactly two states: *inherit the parent's slot* or *use
the child's own slot* — never *compose*. So a static PlaceObject cxform on an
intermediate sprite was dropped one level down, and a parent `_alpha`
**replaced** rather than multiplied a child's static alpha. The already-correct
`compose_cxform20` (Ruffle's rule, `out.mult = outer.mult × inner.mult`,
`out.add = outer.mult × inner.add + outer.add`) was sitting unused two hundred
lines away with a TODO comment explaining that the parent's slot "lives GPU-side
so its values can't be read back here" — so the fix threads the parent's
**values** (`const float parent_cx[20]`) down the recursion next to the existing
`parent_composed[16]`, alongside its slot id.

Also fixed: a child's own **static** `obj->cxform_id` is now read (previously
only ever consulted at the root call sites), root call sites seed from
`root_seed_cxform`, and the two TODO comments are gone.

**Slot economy** (deliberate, and it is why this is safe on real content): there
are only 256 dynamic cxform slots per tick (`render_webgpu.c` ~1095). The code
mints a slot only when *both* sides have a transform; a child with no cxform of
its own **inherits the parent's slot id** exactly as before, and a child under
no parent cxform keeps its baked slot. A fade on a container with 50 children
still costs one slot, not fifty.

### 3b AVM2 — RGB colour transform never reached the renderer
**File:** `SWFModernRuntime/src/avm2/avm2_display.c`.

`transform.colorTransform` stored `cx_rm/gm/bm` + `cx_ra/ga/ba/aa` correctly and
the getter read them back, but **nothing on the render path consumed them**: the
walk propagated `double parent_alpha` only, and all five cxform writers
hard-coded `mult = (1,1,1,alpha), add = 0`. `avm2_render_node` now maintains a
full concatenated `Avm2Cx` (published in `g_avm2_cur_cx`, reset per walk) and
every writer allocates from it through one shared `avm2_alloc_cx_slot()`, which
returns slot 0 (identity) when the whole chain is neutral — so the common case
still costs nothing. The GPU already supported it (`apply_cxform` is a full
mat4 multiply + vec4 add).

**Not changed:** the CPU twin `avm2_cpu_walk` / `avm2_cpu_raster_*` still takes
an alpha scalar. Graphics-mode image tests only use the GPU path; headless
`BitmapData.draw` parity remains a follow-up.

### Ledger

| comparison | CI baseline | after (local) | verdict |
|---|---|---|---|
| `visual/cache_as_bitmap/nested_color_transform` `output` | fail 24192/0 | **pass 0** | **FLIP** (3a) |
| `visual/cache_as_bitmap/color_transform` `output` | fail 169500/0 | **pass 0** | **FLIP** (3a) |
| `avm2/displayobject_colortransform_nested` `output.1` | fail 7500/0 | **pass 0** | **FLIP** (3b) |
| … `output.2` | fail 7500/0 | **pass 0** | **FLIP** (3b) |
| … `output.3` | fail 7500/0 | **pass 0** | **FLIP** (3b) |

**+5 flips**, exactly the wave-1 prediction. All five are tolerance-0 uniform
fills and land byte-exact.

Stretch target `cache_as_bitmap/nested_rotation` (the *matrix* twin) is in the
canary — result below; it was never expected to move from a cxform change.

---

## Fix 4 — attached-bitmap transform

**Files:** `action.h` (`AttachedBitmapInfo` + `xform_slot`, `alpha`),
`action.c` (`actionIterateAttachedBitmaps`), `tag.c`
(`attached_bitmap_render_cb`).

Every attached / loaded bitmap on a dynamic MC was drawn with `transform_id = 0`
and `cxform_id = 0`, positioned by baking `mc->x/y` into the quad's twips — so
`_xscale`, `_yscale`, `_rotation`, `transform.matrix` and `_alpha` were all
discarded. The machinery already existed: `apply_dynamic_mc_transforms` builds
`mc->dynamic_xform_slot` per tick (and handles negative scale correctly). The
callback now draws at the **local origin** through that slot, plus an alpha
cxform slot. MCs with `as_set_flags == 0` get slot 0 and keep the old
stage-space path byte-for-byte, so nothing that passes today can move.

### Ledger

| comparison | CI baseline | after (local) | verdict |
|---|---|---|---|
| `visual/scale_rotation_cache` `output.15` | fail 118784/0 | **pass 0** | **FLIP** |
| … `output.25` | fail 118784/0 | **pass 0** | **FLIP** |
| … `output.35` | fail 118784/0 | **pass 0** | **FLIP** |
| … `output.5` | pass | **pass 0** | held |

**+3 flips**, exactly the wave-1 prediction.

---

## Totals

| fix | predicted | landed |
|---|---|---|
| 1 timeline loop phase | 5 | **1** (+4 comparisons reduced to the hairline class) |
| 2 edittext_border_transform | ≤6 | **4** |
| 3 cxform composition | 5 (+1 stretch) | **5** |
| 4 attached-bitmap transform | 3 | **3** |
| | | **13 flips** |

---

## Canary

`render_canary.py` two-leg md5 A/B, **47 tests / 83 comparisons**, `-P 2`,
graphics mode, local Dawn. The set is the full standing
`ruffle-tests/render_canary_tests.txt` (all 20, both tiers) **plus** every
family this patch touches: the loop/timeline family
(`simple_loop_test`, `timeline_loop`, `Timeline3`, `Timeline4`,
`timeline_as2_1`, `text-bind`, `default_names`,
`place_and_remove_object_insane_test`), the whole EditText box family
(9 tests), the cxform targets, and the attachBitmap / image-loadMovie family
(`bitmap_data_colortransform`, `_copypixels`, `_perlinnoise`,
`_pixeldissolve_image`, `bmd_draw_with_msaa_issue_10579`,
`scale_rotation_cache`). Legs: `before` = HEAD with all five files reverted,
`after` = the patch. Both captured with identical sources (no mid-capture
edits).

```
RENDER CANARY  before=before  after=after   47 tests / 83 comparisons
  IDENTICAL    57
  DIFFERS      26
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
```

### Trace axis — clean
**Zero** trace-status changes and zero trace-text differences across all 47
tests, including `place_and_remove_object_insane_test`, `avm1/default_names`,
`from_shumway/avm1/text-bind` and `from_shumway/timeline/timeline_as2_1` — the
four tests the Phase-4 block's comments name as its reason for existing.

### Pixel axis — 13 flips, **zero regressions**

Every one of the 26 `DIFFERS` is inside a family this patch targets, and every
comparison that stayed `fail` got **strictly closer** to its golden:

| test | cmp | before → after | outliers before → after |
|---|---|---|---|
| `avm2/displayobject_colortransform_nested` | `output.1/.2/.3` | fail → **pass** ×3 | 7500 → 0 |
| `visual/cache_as_bitmap/color_transform` | `output` | fail → **pass** | 169500 → 0 |
| `visual/cache_as_bitmap/nested_color_transform` | `output` | fail → **pass** | 24192 → 0 |
| `visual/scale_rotation_cache` | `output.15/.25/.35` | fail → **pass** ×3 | 118784 → 0 |
| `visual/edittext/edittext_border_transform` | `output.01` | fail → **pass** | 375 → 0 |
| … | `output.02` | fail → **pass** | 2034 → 0 |
| … | `output.03` | fail → **pass** | 1717 → 0 |
| … | `output.05` | fail → **pass** | 2890 → 136 |
| `from_gnash/…/simple_loop_test` | `frame4` | fail → **pass** | 7442 → 0 |
| `from_gnash/…/simple_loop_test` | `frame3` | fail → fail | 21600 → **724** |
| … | `frame5` | fail → fail | 7683 → **242** |
| … | `frame6` | fail → fail | 14400 → **483** |
| … | `frame7` | fail → fail | 14702 → **724** |
| `visual/edittext/edittext_border_transform` | `output.04` | fail → fail | 655 → **241** |
| … | `output.06` | fail → fail | 2683 → **293** |
| `visual/edittext/edittext_device_transform_small_shear` | `output` | fail → fail | 1744 → **88** |
| `visual/edittext/edittext_border_basic` | `output` | fail → fail | 2046 → **1227** |
| `visual/edittext/edittext_border_basic_scale2` | `output` | fail → fail | 6858 → **6072** |
| `visual/edittext/edittext_background_basic` | `output` | fail → fail | 2269 → **1902** |
| `visual/edittext/edittext_background_basic_scale2` | `output` | fail → fail | 8652 → **7741** |
| `visual/edittext/edittext_border_filters` | `output` | fail → fail | 868 → **863** |

(The last seven rows' post numbers come from the `after2` leg — an 11-test
re-capture of the EditText family after the device-font box refinement
described below. Everything else in `after2` is byte-identical to `after`.)

**IDENTICAL and holding:** every mask test, every gradient test, every filter
and blend test, `avm1/color`, `avm1/bitmap_data_fillrect`,
`avm1/focusrect_swf5` (12 cmps), `avm2/blend_multiply_alpha`,
`from_shumway/timeline/timeline_as2_5` (7 cmps),
`from_shumway/acid/acid-gradient-0`, both `regression/avm2_timeline_*`
gradients, `regression/avm2_morph`, `visual/cache_as_bitmap/shape_changed`,
the whole attachBitmap family (`bitmap_data_colortransform`, `_copypixels`,
`_perlinnoise`, `_pixeldissolve_image`, `bmd_draw_with_msaa_issue_10579`),
`from_shumway/timeline/{timeline_loop, Timeline3, Timeline4}`,
`avm1/edittext_tag_indent` (a CI-passing tier-1 EditText canary — 240 outliers
before and after), `visual/edittext/edittext_gutter` (8580 both legs).

### One margin to watch: `edittext_device_transform_small_rotation`
The only comparison whose *pixels* moved while its status did **not**:
`pass → pass`, 0 → **11 outliers against a `max_outliers = 11` budget**. It is
exactly at its limit.

Diagnosed rather than left as a number: the test has **11 device-font fields**
and the 11 differing pixels are **one per field** — the bottom-right corner
pixel of each border, which Ruffle's *device* box draws and its *embedded* box
(the open `draw_line_rect` polyline) does not. These are solid-magenta,
fully-deterministic geometry pixels, not anti-aliasing, so lavapipe will report
the same 11 and the test will still pass on CI.

I did try to close it: `textfield_render_cb` now implements Ruffle's
`draw_device_text_box` (axis-aligned pixel-snapped screen bbox instead of the
matrix-transformed box) for device-font fields, which is the correct mechanism
and improved `edittext_border_basic` 2004 → 1227 and `background_basic`
2072 → 1902 as a bonus. But the corner itself cannot be closed both ways at
once: `edittext_border_transform`'s goldens (also device-font) have the corner
**open**, and closing it costs `output.01`/`.03` their tolerance-0 passes.
Traded 1 pixel × 11 fields of margin on a still-passing test for 3 exact flips.
If the coordinator would rather protect the margin, the one-line revert is
`line_rect = 0` in the `device_box` branch of `textfield_render_cb` — that
costs `edittext_border_transform` `output.01`/`.02`/`.03` (−3 flips).

### Ship / no-ship

| fix | canary verdict | ship? |
|---|---|---|
| 1 loop-phase (`swf.c`) | +1 flip, 4 comparisons improved 20–30×, zero trace changes, gate test passes | **SHIP** |
| 2 edittext box (`action.h`/`action.c`/`tag.c`) | +4 flips, 7 more improved, one 11/11 margin (analysed above) | **SHIP** |
| 3 cxform (`tag.c` + `avm2_display.c`) | +5 flips, all byte-exact, nothing else moved | **SHIP** |
| 4 attached-bitmap (`action.h`/`action.c`/`tag.c`) | +3 flips byte-exact, whole attachBitmap family IDENTICAL | **SHIP** |

No fix needs to be dropped.

---

## Merge risks / how to drop one

The four hunks are disjoint:

* **Fix 1** — `swf.c` only, all four hunks `#ifdef OFFSCREEN_RENDER`. Highest
  blast radius of the four (production frame loop, every looping root).
  Drop = revert `swf.c`.
* **Fix 2** — `action.h` `TextFieldRenderInfo`, `actionIterateTextFields`,
  `textfield_render_cb`. The orphan-DefineEditText producer
  (`otf_emit_textfield`) zero-inits the struct, so `has_matrix == 0` keeps its
  old stage-space path untouched. Drop = revert those three sites.
* **Fix 3** — `compose_children` + call sites in `tag.c`, and the
  `Avm2Cx`/`avm2_alloc_cx_slot` block in `avm2_display.c`. The two halves are
  independent of each other and of everything else.
* **Fix 4** — `AttachedBitmapInfo`, `actionIterateAttachedBitmaps`,
  `attached_bitmap_render_cb`. Gated on `xform_slot != 0`, i.e. on
  `mc->as_set_flags != 0`; identity MCs take the unchanged branch.

Standing risks worth calling out to the coordinator:

1. **Fix 1 is a frame-loop change.** The canary covers the loop/timeline family
   and the gate test, but the full-corpus CI run is the real check — watch
   `from_gnash/misc-ming.all/*loop*`, `from_shumway/timeline/*`,
   `avm1/default_names`, `from_shumway/avm1/text-bind`.
2. **Fix 2's device-font cull removes fields from the render.** Any AVM1 test
   with a rotated/sheared non-`embedFonts` TextField that *currently* passes by
   drawing it will flip to fail. `edittext_device_transform_small_rotation`
   (the closest such test, and CI-passing) was checked and holds.
3. **Fix 3a changes which cxform slot a nested entry renders with**, i.e. it
   touches every nested clip with a tint or an `_alpha`. The slot-economy
   branch keeps the allocation count identical to before in the common cases;
   if a dense scene ever does exhaust the 256-slot pool, the fallback leaves
   `obj->cxform_id` untouched (old behaviour), it does not crash.
4. **Fix 3b widens the AVM2 cxform slot from alpha-only to full.** Any AVM2
   content that sets `colorTransform` RGB now actually tints. That is the fix,
   but it is a visible change to previously-neutral renders.
5. Neither `avm2_cpu_walk` nor `avm2_cpu_raster_*` was widened — headless
   `BitmapData.draw` still applies alpha only. Known, deliberate, out of scope.
