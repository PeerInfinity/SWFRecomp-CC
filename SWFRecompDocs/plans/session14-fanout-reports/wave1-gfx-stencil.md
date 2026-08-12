# wave-1 `gfx-stencil` — Equal/IncrementClamp stencil intersection

Session 14, wave 1, **READ-ONLY**. No source, doc or test file in the repo was
modified except this report. All probe work was PNG analysis plus three
single-test `--mode=graphics --images` runs against **copies** of the test dirs
in the scratchpad (`--tests-dir` never pointed at the main tree; `--recompile`
on first use). Local Dawn at `~/CC/dawn-install`.

Baseline: run `31130292354` at `fb36ba110` (graphics/full/images=true), pixels
301/567. HEAD `0a99be1a9` (one ungraded AVM2-runtime commit since; it does not
touch any renderer or display-walk file).

---

## 0. Headline — five results

1. **The mechanism is confirmed and is a two-headed defect, not one.** Our mask
   write is `Always`/`Replace` at a monotonically-allocated reference
   (`render_webgpu.c:1449-1452`, `2158-2172`, `2620-2635`). A nested mask
   therefore (a) does **not** intersect its parent — it tests its own full
   silhouette — and (b) **punches a hole** in the parent, because `Replace`
   overwrites the parent's reference inside the overlap and `restore_clip`
   restores only the *reference*, never the texels. `avm2/displayobject_scrollrect`
   shows both halves in one image (§3.1).

2. **Pricing correction accepted and sharpened.** The coordinator is right that
   `regression/mask_nested_intersect` is not in the graded suite — it is an
   s11-authored generator script (`session11-fanout-reports/w2-masks-r2-mask_nested_intersect.py`)
   that was never dropped in; the `regression` suite has exactly one mask test
   (`mask_sibling_union`). It contributes **0 CI comparisons**. Two graded
   beneficiaries remain — but they are worth **7 comparisons, not 2**.

3. **I price this lead HIGHER than board-audit does: 7 flips, not "1 flip + 6
   band moves".** Board-audit priced `cache_as_bitmap/masks` as "tolerance 0, a
   flip needs exactness". That is a misreading of its `test.toml`: the test has
   **three checks** (`tol 10/max 3200`, `tol 64/max 350`, `tol 128/max 0`) and
   the reported `tolerance: 128` in the results JSON is just the tightest
   *failing* one. `output.07` is the **empirical existence proof**: on frame 7
   the third row happens to render correctly today and the frame **passes** with
   2520/3200 and 246/350. Per-band channel measurements (§3.2) predict every one
   of `.01`–`.06` lands inside all three budgets, tightest at `.04` with 94
   channels (3%) of headroom.

4. **Local Dawn is byte-identical to the CI actual on every one of the 7
   beneficiary comparisons** (md5, §3.3). Wave 2 may grade *absolute* local
   numbers on these tests — not just the A/B delta. That is the single most
   useful thing in this report for the implementer.

5. **REFUTATION — `cab_mask_alpha` / `cab_mask_filters` / `cab_mask_transform`
   are NOT riders** (board-audit §6.2 guessed they were). In those tests Ruffle
   clips each colour block to 10–20% of its area while we apply **zero**
   clipping (§4.2). An intersection fix cannot move a mask that never reaches
   the stencil at all. They are a separate unowned bucket: `.mask` between two
   `cacheAsBitmap` Sprites. Cheap discriminator: they must be **md5-IDENTICAL**
   in wave 2's A/B; a move there means this classification was wrong.

**Go / no-go: GO**, with the risk fence in §7. The renderer diff is ~120 lines;
the mandatory *hygiene* in the three `tag.c` walks is what carries the real
regression risk, and it is the part most likely to be skipped.

---

## 1. What our stencil model is today, file:line

`SWFModernRuntime/src/rendering/render_webgpu.c`, everything below re-read at
HEAD.

| phase | site | state |
|---|---|---|
| pipeline: normal draw | `1418-1443` | `compare = Always`, `passOp = Keep`, `stencilWriteMask = 0x00`, colour ALL |
| pipeline: mask write | `1449-1465` | `compare = **Always**`, `passOp = **Replace**`, `writeMask 0xFF`, colour NONE |
| pipeline: mask test | `1467-1478` | `compare = Equal`, `passOp = Keep`, `writeMask 0x00`, colour ALL |
| pipeline: mask clear | — | **does not exist** |
| pass open | `1965-1986` | `stencilLoadOp = Clear`, `stencilClearValue = 0`; `mask_ref = 0`, `mask_ref_next = 0` (`1977-1978`) — the ONLY stencil reset in a pass |
| reference allocator | `2158-2172` | `alloc_mask_ref()` — monotonic 1..255, with a full-screen `Always/Replace @ 0` rewrite on wraparound |
| `begin_clip_mask` | `2620-2635` | `mask_capture_depth++`; if outer, `mask_ref = alloc_mask_ref()`; bind write @ `mask_ref` |
| `end_clip_mask` | `2637-2647` | bind test @ `mask_ref` |
| `end_clip` | `2649-2658` | `mask_ref = 0`; `restore_draw_pipeline()` |
| `clip_ref` / `restore_clip` | `2673-2685` | return / assign `mask_ref`, then `restore_draw_pipeline()` |
| pipeline-clobber recovery | `2133-2145` `restore_draw_pipeline` | `mask_ref ? test @ mask_ref : render_pipeline` — every clobber site routes through it |
| composite / filter refs | `4035`, `4362`, `4441` | all `SetStencilReference(ctx->mask_ref)` — already single-sourced |
| offscreen park | `4098-4186` | parks `{mask_ref, mask_capture_depth}` on an 8-deep stack, zeroes both; the offscreen pass owns its own CLEARED stencil |

Context fields: `render_webgpu.h:174-186`. The `NO_GRAPHICS` arm of
`renderer.h:87-91` no-ops all five entry points — there is exactly one real
renderer to change.

### 1.1 The two consequences, stated exactly

Let mask **A** be open at reference `a` over region `A`, and mask **B** open
inside it at reference `b` over region `B`.

* **No intersection.** `B`'s write is `Always`, so every texel of `B` — inside
  *or outside* `A` — becomes `b`. Content drawn at `b` paints all of `B`, when
  Flash paints `A ∩ B`.
* **Hole in the parent.** The texels of `A ∩ B` now hold `b`, not `a`.
  `restore_clip(a)` (`2679-2685`) restores the *reference*, so later siblings
  test `== a` and **fail** throughout `A ∩ B`. The s13 maskC report called this
  out (`w2-gfx-maskC-report.md` §4.1, "`restore_clip` puts the parent's
  reference back but cannot repair the texels the child overwrote").

Both halves are visible simultaneously in `displayobject_scrollrect` (§3.1).

### 1.2 Walk-side bookkeeping today

All three `tag.c` display loops and the AVM2 walk track **one scalar**
`active_clip_depth`, not a stack (Ruffle keeps
`clip_depth_stack: Vec<(Depth, DisplayObject)>`,
`core/src/display_object/container.rs:553-593`):

| walk | site | pops before pushing a second range? |
|---|---|---|
| `render_display_list` | `tag.c:3463-3470`, `3528-3558`, `3667-3671` | **NO** — `3533/3541/3549` `begin_clip_mask` with `active_clip_depth` possibly still >0 |
| `tagRerenderFrame` | `tag.c:5810-5898` | **NO** (`5833/5839`) |
| `tagShowFrame` | `tag.c:6750-6899` | **NO** (`6794/6802`) |
| `avm2_render_node` | `avm2_display.c:15609-15647` | **YES** — `15632-15636` already restores first |

Under `Replace` an unpopped second push was harmless (the new `begin` simply
reassigned `mask_ref`, and `end_clip` zeroed it). **Under a counting model it
leaks a level for the rest of the frame.** This is the single highest-risk item
in the whole change and it is invisible in the renderer diff. See §5.2.

Other push/pop pairs that inherit the new semantics: `avm1_mask_push`
(`tag.c:3199-3208`, paired with `restore_clip`), the EditText field-bounds clip
(`tag.c:4987-4992` → `5408-5410`), `masked_drawing_render_cb`
(`tag.c:5568-5576`), the AVM2 EditText glyph clip
(`avm2_display.c:15342-15373`), `avm2_push_clip_mask`
(`avm2_display.c:15436-15448`) and `avm2_push_scroll_rect_mask`
(`avm2_display.c:15464-15480`).

---

## 2. Ruffle's model, file:line

`~/CC/ruffle`, current master.

**Pipelines — `render/wgpu/src/pipelines.rs:376-414`**, four `MaskState` arms,
all `read_mask = write_mask = !0`:

| MaskState | compare | passOp | colour |
|---|---|---|---|
| `NoMask` | `Always` | `Keep` | ALL |
| `DrawMaskStencil` | **`Equal`** | **`IncrementClamp`** | empty |
| `DrawMaskedContent` | `Equal` | `Keep` | ALL |
| `ClearMaskStencil` | **`Equal`** | **`DecrementClamp`** | empty |

**Sequencing — `render/wgpu/src/surface/commands.rs:399-433`** (references set
in `commands.rs:59-68` / `surface.rs:316-325`):

```
push_mask()      : num_masks += 1;  state = DrawMaskStencil;   ref = num_masks - 1
activate_mask()  :                  state = DrawMaskedContent; ref = num_masks
deactivate_mask():                  state = ClearMaskStencil;  ref = num_masks
pop_mask()       : num_masks -= 1;  ref = num_masks; state = num_masks ? DrawMaskedContent : NoMask
```

**Drivers.** `core/src/display_object.rs:1206-1270`
(`apply_standard_mask_and_scroll`) and
`core/src/display_object/container.rs:553-593` (`render_children`).
Both push, draw the mask geometry, activate, draw content, **deactivate, draw
the mask geometry AGAIN**, pop. The second draw is what the `DecrementClamp`
pipeline consumes.

**The exact divergence, in one line:**

> `render_webgpu.c:1450-1451` is `Always`/`Replace` where
> `ruffle/render/wgpu/src/pipelines.rs:392-393` is `Equal`/`IncrementClamp`,
> and we have no counterpart at all to `pipelines.rs:411-412`'s
> `Equal`/`DecrementClamp` + `display_object.rs:1256-1269`'s replay.

### 2.1 Two properties of the Equal model that are load-bearing and non-obvious

1. **It intersects for free.** `Equal(num_masks-1)` means the inner mask can
   only raise texels that already carry the enclosing mask's value. That IS the
   intersection; no geometry algebra is needed.
2. **It is idempotent under self-overlapping mask geometry.** A second triangle
   of the *same* mask finds `stencil == num_masks ≠ num_masks-1`, fails the
   compare, and `failOp = Keep` leaves it alone. So a masker whose subtree
   draws overlapping shapes — which ours does routinely, since
   `draw_mc_mask_geometry` (`tag.c`, mask defect B) draws *all* applicable
   masker kinds and `render_display_list` recursion draws a whole subtree —
   cannot double-increment itself into a hole. **This kills the obvious
   objection to Increment.** Same argument applies to the decrement.

---

## 3. Beneficiary verification

### 3.1 `avm2/displayobject_scrollrect` — 12 382, the clean pin test

`Test.as`: `circle.scrollRect = Rectangle(50,60,50,100)`; child
`scrollChild.scrollRect = Rectangle(100,100,60,70)` inside it; sibling
`normalChild` (green) also inside. `tolerance = 0`, `max_outliers = 0`,
`quality = "low"` ⇒ `MSAA_SAMPLES = 1`.

CI actual vs repo golden, recomputed from the PNGs (never from the published
`.difference.png`):

```
mismatching px 6191   (= 12382 excess CHANNELS — the results JSON counts channels)
bbox (92,80)-(182,196)                      == exactly the CHILD crop region
  5672 px  actual (0,0,255)  expected (255,255,255)   blue outside the PARENT crop
   519 px  actual (0,0,255)  expected (0,255,0)       green sibling punched out

colour histograms
  actual   white 206628 | blue 9833 | magenta 3539 | green    0
  expected white 212300 | blue 3642 | magenta 3539 | green  519

blue(expected) ⊆ blue(actual):  expected-not-actual = 0 px,  actual-not-expected = 6191 px
bbox blue actual (54,64)-(182,196)      bbox blue expected (54,64)-(114,177)
```

This is the two-headed defect, measured:

* the 5672 are head (a) — the child crop tests its own full rectangle instead
  of `parent ∩ child`; the expected blue is *exactly* the subset our blue would
  become under intersection (0 pixels of expected blue are missing from ours);
* the 519 are head (b) — the child's `Replace` overwrote the parent's reference,
  so the green sibling drawn afterwards at the parent's restored reference fails
  the stencil test everywhere it would have been visible. Our actual contains
  **zero** green pixels anywhere on the stage; the golden has exactly 519, all
  inside the child crop.

**The magenta parent content matches the golden to 0 pixels (3539 = 3539).**
That is the strongest single fact in this report: our rasterisation of the
crop-rect stencil edges is already Ruffle-exact under this test's transform, so
the intersection boundary is not a new source of error.

**Predicted post-fix residual: 0 → FLIP.** Its trace is `output_mismatch`
(localToGlobal/hitTest, unrelated), which does **not** gate the image axis — 3
comparisons in the merged results already pass on the image axis with a
non-`pass` trace.

### 3.2 `visual/cache_as_bitmap/masks` — 6 live comparisons, and why they flip

The recompiled `RecompiledTags` on disk are stale (Aug 1 vs an Aug 6 SWF), so I
parsed the SWF and the DoABC directly. Structure: three groups of two circles
(`circles_2` d3, `circles_1` d15, `circles_3` d27; all `PlaceObject3` with
`bitmapCache = 1`), two masker squares (`square_1` d1, `square_2` d41), two
decorative dashed outlines (d39, d43). **No `clipDepth` anywhere** — all masking
is AS3. `frame1` does:

```
circles_2.mask = square_1                       -> row 1: mask only
circles_1.scrollRect = Rectangle(0,0,130,100)   -> row 2: scrollRect only
circles_3.mask = square_2                       -> row 3: mask AND scrollRect
circles_3.scrollRect = Rectangle(0,0,130,100)
```
plus an `ENTER_FRAME` that scrolls `circles_1`/`circles_3` by +100 per frame and
moves `circles_2` by −100. Row 3 is Ruffle's *"this mask is applied in addition
to a mask defined with `DisplayObject.mask`"* case
(`display_object.rs:1216-1229`) — i.e. the intersection case, verbatim.

Measured per-row (y-bands 0-130 / 130-265 / 265-400), CI actual vs golden:

| frame | row 1 (mask only) | row 2 (scrollRect only) | row 3 (mask **∩** scrollRect) |
|---|---|---|---|
| | `>10 / >64 / >128` | `>10 / >64 / >128` | `>10 / >64 / >128` |
| `.01` | 319 / 13 / 0 | 1384 / 128 / **0** | 3136 / 1851 / **1690** |
| `.02` | 270 / 28 / 0 | 1355 / 133 / **0** | 4186 / 2913 / **2701** |
| `.03` | 273 / 21 / 0 | 1364 / 134 / **0** | 3594 / 2345 / **2170** |
| `.04` | 320 / 14 / 0 | 1393 / 128 / **0** | 3259 / 1938 / **1777** |
| `.05` | 265 / 12 / 0 | 1354 / 124 / **0** | 3157 / 1915 / **1769** |
| `.06` |  69 /  5 / 0 | 1278 / 127 / **0** | 1993 /  841 /  **709** |
| `.07` |   0 /  0 / 0 | 1260 / 123 / **0** | **1260 / 123 / 0** ← already correct |

Rows 1 and 2 are correct today; **all** of the `>128` excess lives in row 3, and
row 3's geometry is identical in kind to row 2's. Visually (crops in
`<scratch>/gfx-stencil/cab_masks_row{2,3}.png`): row 2's circles are clipped to
`x ∈ [225,324]` in both ours and the golden; row 3's are clipped to the same
window in the golden and **not clipped at all** in ours — because the
`scrollRect` crop (130 px wide, ≈ the content bbox, so a visual no-op on its
own) is pushed *after* the `.mask` stencil and `Replace`s it.

The three checks are `tol 10 / max 3200`, `tol 64 / max 350`, `tol 128 / max 0`.
Substituting row 2's residual for row 3 (which `.07` shows is exactly what a
correct row 3 produces — 1260/123 in both rows):

| cmp | now `>10 / >64 / >128` | predicted | headroom on `>10` (3200) | on `>64` (350) | verdict |
|---|---|---|---:|---:|---|
| `.01` | 4839 / 1992 / 1690 | **3087 / 269 / 0** | 113 | 81 | **PASS** |
| `.02` | 5811 / 3074 / 2701 | **2980 / 294 / 0** | 220 | 56 | **PASS** |
| `.03` | 5231 / 2500 / 2170 | **3001 / 289 / 0** | 199 | 61 | **PASS** |
| `.04` | 4972 / 2080 / 1777 | **3106 / 270 / 0** | 94 | 80 | **PASS** |
| `.05` | 4776 / 2051 / 1769 | **2973 / 260 / 0** | 227 | 90 | **PASS** |
| `.06` | 3340 /  973 /  709 | **2625 / 259 / 0** | 575 | 91 | **PASS** |
| `.07` | 2520 /  246 /    0 | unchanged | 680 | 104 | pass (must hold) |

The residual that survives in every row is the dashed-rectangle stroke
(`test.toml` carries a literal `# FIXME Wrong stroke width.`): our dashes are
`(0,0,0)`, the golden's are `(63,63,63)`-family — 63 < 128, so it never touches
the tightest check, and it is the same in rows 2 and 3.

**Predicted: 6 flips, tightest margin 3 %.** Call these "flips at 3 % margin",
not "band moves" — but do not be surprised by one falling short.

### 3.3 CI fidelity — local Dawn is byte-identical to CI on all 7

Ran both tests from scratchpad copies (`--mode=graphics --images --recompile`):

```
avm2/displayobject_scrollrect        local excess 12382  == CI 12382, mean 3.588
                                     md5 local == md5 CI actual   b8294e888b24
visual/cache_as_bitmap/masks .01-.06 local excess 1690/2701/2170/1777/1769/709 == CI
                                     md5 local == md5 CI actual for ALL SIX
                                     .07 local pass 0
```

Per the playbook's CI-fidelity rule, **local grading is CI-grade for these seven
comparisons**. Wave 2 can iterate to an absolute number instead of guessing from
an A/B delta. (`ruffle-tests/verify_output.py --image-out-dir` writes failures
only; `SWF_KEEP_BUILD_DIR=<dir>` gets you `output.NN.png` for the passing ones.)

---

## 4. Sweep for further beneficiaries

Method: every comparison in the merged `image_results_graphics.json` whose test
or comparison name matches `mask|clip|scroll` (56 rows), plus the `extra_element`
and `unrelated_content` clusters of a freshly regenerated
`scripts/image_triage.py` board over run `31130292354`. PNG-level colour-pair
and bbox analysis on each candidate.

### 4.1 Result: no further beneficiaries

| comparison | excess | verdict |
|---|---:|---|
| `visual/cache_as_bitmap/oversize/swf_{9,10}_masks` | 119 943 ×2 | whole 300×200 frame is our red vs golden white/blue — the swf-version size gate, not masking |
| `visual/cache_as_bitmap/scroll_rect`, `scroll_rect_scaled` | 18 378 / 40 946 | AVM1 `scrollRect` (still an inert `extra_props[]` stub) — the *other* named lead |
| `visual/simple_shapes/scroll_rect_mask` | 11 310 | `offset_translation`, `dx=dy=8` — AVM1 `scrollRect` translate |
| `avm2/bitmapdata_draw_masks` | 5 850 | `avm2_cpu_raster.c` has no mask code at all (grep: 0 hits) |
| `from_shumway/acid/acid-mask [.01/.05/.10]` | 12 080 / 10 921 / 9 458 | `known_failure`, classifier says `hairline_edge_drift` |
| `from_shumway/MaskTest-2` | 7 162 | `known_failure`; diff is text AA in a 218×28 strip |
| `visual/blend_modes/shader_as_mask` | 5 548 | `known_failure`, PixelBender |
| `avm2/mouse_pick_non_interactive_bitmap_mask` | 625 | one 25×25 quadrant, all-or-nothing — a Bitmap used as masker, unimplemented |
| `visual/simple_shapes/masks`, `masks_equal_clipdepth` | 2 624 ×2 | **HARD-dispositioned** rasteriser tie (ACCEPTED_DIFFS, s12 §4) |
| `from_shumway/MaskTest` (17), `avm2/displayobject_mask` (8), `visual/avm2_button_scroll_rect` (9), `avm2/mouse_pick_*_dobj_mask` (24 ×2) | | `a_epsilon` single-pixel edge ties; could flip on *any* edge change, in either direction |

### 4.2 REFUTATION — `cab_mask_alpha` / `cab_mask_filters` / `cab_mask_transform`

Board-audit §6.2 lists these as "likely riders on the same change". They are
not. Colour histograms:

```
cab_mask_alpha (80x40)   expected  white 2498 | (136,136,136) 63 | yellow 62 | magenta 62 ...
                         actual    red 320 | (68,68,68) 320 | green 320 | (136,136,136) 320 ...
cab_mask_transform(40x40)expected  white 1249 | ... 31 | 30 | 30
                         actual    160 | 160 | 160 | 160  (nine colours, full blocks)
```

Ruffle clips each colour block to 10–20 % of its area; **we clip nothing at
all**. An intersection fix cannot narrow a mask that never entered the stencil.
The SWFs are Flex-compiled AVM2 and their app ABC carries
`cacheAsBitmap` + `mask` together — i.e. Ruffle's `RenderMask::Alpha` arm
(`display_object.rs:1979-1986`, taken only when *both* objects are bitmap-cached)
and, on our side, a `.mask` that is not reaching `avm2_render_node`'s
`ext->mask` block at all. **Separate unowned bucket**; worth its own wave-1
brief next session. Discriminator for wave 2: `cab_mask_transform` must be
**md5-IDENTICAL** across the A/B.

### 4.3 The un-graded third beneficiary

`regression/mask_nested_intersect` exists only as
`SWFRecompDocs/plans/session11-fanout-reports/w2-masks-r2-mask_nested_intersect.py`
(a raw SWF-tag emitter; `clipDepth` has no ActionScript equivalent so MTASC
cannot author it). The `regression` suite contains exactly one mask test,
`mask_sibling_union`. **0 CI comparisons today — do not price it.**

It is nevertheless the *right* pin for this change and should ship **with** the
patch: root `M1 = (0,0)-(120,120) clipDepth 2` masking a sprite that contains
`M2 = (60,60)-(180,180) clipDepth 2` over a full-stage green rect. Its docstring
already states the three-way discrimination — union 25 200 px green today,
14 400 px under a per-mask-reference fix, **3 600 px only under increment/
decrement**. All shapes are axis-aligned on integer pixel boundaries so it is
gradeable at `tolerance = 0` regardless of MSAA. Golden must come from the
oracle outside SWFRecomp (playbook §7): `~/CC/ruffle/target/release/exporter
test.swf output.expected.png -s`, which **is built** (`Jul 22`), exactly as
`mask_sibling_union` was produced. It adds +1 graded comparison that this
session can then claim.

---

## 5. Implementation plan

### 5.1 Renderer — `render_webgpu.c` / `render_webgpu.h`

**Redefine `ctx->mask_ref` as the nesting LEVEL (Ruffle's `num_masks`).** This
is the trick that keeps the diff small: `clip_ref()` already returns it and
`restore_clip(n)` already takes it, and under Ruffle's model the stencil
reference *is* the nesting depth — so every one of the 20 existing call sites
keeps working unchanged, and the three composite/filter
`SetStencilReference(ctx->mask_ref)` sites (`4035`, `4362`, `4441`) need no edit.

| # | site | change |
|---|---|---|
| 1 | `1449-1452` `stencil_write_pipeline` | `compare = Always` → **`Equal`**; `passOp = Replace` → **`IncrementClamp`**. Keep `failOp = depthFailOp = Keep`, `stencilWriteMask = 0xFF`, colour NONE. |
| 2 | `1467-1478` `stencil_test_pipeline` | unchanged (`Equal`/`Keep`, write 0x00, colour ALL) |
| 3 | **new**, beside `1478` | `stencil_clear_pipeline`: `compare = Equal`, `passOp = **DecrementClamp**`, `stencilWriteMask = 0xFF`, `colorWriteMask = 0` (or `fragment = NULL`). **`multisample.count = MSAA_SAMPLES`** — never a literal 4 (standing invariant; pipeline creation fails loudly at count 1). |
| 4 | **new**, ~30 lines | a full-screen **NDC** quad shader + pipeline for the decrement draw, modelled verbatim on the existing composite path (`3506-3577` for the pipeline, `blend_shader_wgsl_head`'s `@builtin(vertex_index)` vertex stage at `3715-3728` for the geometry). **Do NOT reuse `render_webgpu_draw_rect`** for this: it goes through the dynamic vertex/colour staging (capacity checks at `2083-2084`, silently `return`s when `MAX_DYNAMIC_RECTS`/`MAX_DYNAMIC_VERTICES` are exhausted — a skipped decrement corrupts the stencil for the rest of the frame) and it depends on the arbitrary stage transform that `renderer_upload_stage_transform` may have installed. An NDC quad has neither problem and needs no transform slot. |
| 5 | `2158-2172` `alloc_mask_ref` | **delete.** `IncrementClamp` saturates at 255 by construction; keep a `if (ctx->mask_ref < 255) ctx->mask_ref++;` guard plus a debug assert. The wraparound full-screen `Always/Replace @ 0` rewrite goes with it. Also delete `mask_ref_next` from the header (`render_webgpu.h:181`) and its reset at `1978`. |
| 6 | `2620-2635` `begin_clip_mask` | keep the `mask_capture_depth++ > 0` early-out verbatim; then `ctx->mask_ref++`; bind `stencil_write_pipeline`; `SetStencilReference(ctx->mask_ref - 1)`. |
| 7 | `2637-2647` `end_clip_mask` | unchanged in shape: bind `stencil_test_pipeline`; `SetStencilReference(ctx->mask_ref)`. (This is Ruffle's `activate_mask`.) |
| 8 | `2649-2658` `end_clip` | keep the `mask_capture_depth > 0` early-out; then **pop exactly one level**: `render_webgpu_restore_clip(ctx, ctx->mask_ref ? ctx->mask_ref - 1 : 0)`. |
| 9 | `2679-2685` `restore_clip(ref)` | keep the `mask_capture_depth > 0` early-out. Then, **while `ctx->mask_ref > ref`**: bind `stencil_clear_pipeline`; `SetStencilReference(ctx->mask_ref)`; draw the NDC quad; `ctx->mask_ref--`. Finish with `restore_draw_pipeline(ctx)`. Defensive: `if (ref > ctx->mask_ref) return;` — every existing caller restores monotonically downward (verified: `tag.c:3469/3667/3670/5895/6148/6870`, `avm2_display.c:15622/15633/15646/15652/15654`), so a raise is a bug, not a case. |
| 10 | `2133-2145` `restore_draw_pipeline` | unchanged. |
| 11 | `4098-4186` offscreen park/unpark | unchanged in code; **update the comment** — the parked value is now a level, and the offscreen pass's own `stencilClearValue = 0` matches the parked-to-0 level exactly. |
| 12 | `render_webgpu.h:174-186` | rewrite the block comment; drop `mask_ref_next`; add the new pipeline handle. |

**Why a full-screen decrement rather than Ruffle's geometry replay.** Ruffle
re-draws the masker (`display_object.rs:1256-1269`, `container.rs:568-570`); we
would have to plumb "re-draw this masker" through five different push sites
(`tag.c` ×3 + `avm1_mask_push` + `avm2_push_clip_mask`) and keep the geometry
alive across them. The full-screen decrement is exactly equivalent because
`Equal(num_masks)` selects precisely the texels the innermost mask raised —
that invariant holds as long as pops are LIFO, which §5.2 enforces. It is one
extra draw call per pop (busiest graded frame: `from_shumway/invalidClipDepth`
at 257 masks — but those are one *per frame*, so ~1 extra draw/frame there).

### 5.2 Walk hygiene — MANDATORY, ships in the same patch

Without this the renderer change **leaks a stencil level** and clips the rest of
the frame. Three sites, all in `tag.c`, all one shape:

```
if (obj->clip_depth > 0) {
        if (active_clip_depth > 0)                    /* NEW: pop before push */
                renderer_restore_clip(context, pre_clip_ref);
        else
                pre_clip_ref = renderer_clip_ref(context);
        renderer_begin_clip_mask(context);  ...  renderer_end_clip_mask(context);
        active_clip_depth = obj->clip_depth;
}
```

* `tag.c:3528-3558` (`render_display_list`) — `pre_clip_ref` already exists at `3463`.
* `tag.c:5833-5852` (`tagRerenderFrame`) — introduce `pre_clip_ref` at the top of
  the loop and convert `5819` / `5898`'s `renderer_end_clip` to
  `renderer_restore_clip(context, pre_clip_ref)`.
* `tag.c:6794-6816` (`tagShowFrame`) — same, converting `6757` / `6898`.

`avm2_display.c:15630-15639` **already does this**; leave it alone.

This is exactly the shape `avm2_render_node` uses and it is *behaviour-preserving
under the old model too* (a pop-then-push under `Always/Replace` is
byte-identical to a bare push) — so the whole hygiene edit can be A/B'd against
HEAD **before** the renderer change and must come out md5-IDENTICAL everywhere.
**Do that as a separate first leg**; it isolates the two risks.

Two more conversions in the same spirit, both improvements, both behaviour
changes worth isolating:

* `tag.c:4987-4992` / `5408-5410` (EditText field-bounds clip) and
  `tag.c:5568-5576` (`masked_drawing_render_cb`): replace the bare
  `renderer_end_clip` with a saved `renderer_clip_ref` / `renderer_restore_clip`
  pair. Today `end_clip` **drops** any enclosing clip; with §5.1 item 8 it pops
  one level instead, which is already correct — the explicit pair just makes it
  unmistakable and survives future edits.
* `avm2_display.c:15354` — `if (has_clip && context->mask_ref != 0) has_clip = 0;`
  is the s12 workaround for exactly this defect ("*Proper nesting needs a stencil
  stack, which is a renderer change and out of scope here*"). **Leave it in place
  for this patch** and remove it in a follow-up: dropping it turns every AVM2
  EditText inside a live clip range from unclipped to clipped, which is a
  ~66-comparison text-family delta that must not ride on top of the stencil
  change. Note the removal in the code comment so the debt is visible.

### 5.3 Interaction with the s13 defect-B and defect-C patches

Both compose cleanly; neither is fought.

* **Defect B** (AVM1 `setMask`, `w2-gfx-maskB-report.md`) uses
  `avm1_mask_push` → `renderer_clip_ref` / `renderer_restore_clip`
  (`tag.c:3199-3208` + `3667`, `5895`, `6148`, `6870`). Under the new model that
  push/pop becomes an intersecting nested mask, which is what Ruffle does. Its
  hard coupling — "`clip_depth = 0` retirement and masker suppression must stay
  together" (report §6.1) — is in `action.c`'s `avm1_mask_pair()` and is
  untouched. `avm1/mask_reapply` remains the mandatory gate.
* **Defect C** (AVM2 `scrollRect`, `w2-gfx-maskC-report.md`) pushes the crop
  *after* the `DisplayObject.mask` **specifically because** "our flat Replace
  stencil cannot intersect two masks … so the inner one wins — putting it in
  Ruffle's order makes scrollRect the winner"
  (`avm2_display.c:15533-15538`). That ordering is **also Ruffle's order**
  (`display_object.rs:1216-1229`), so once intersection works the comment's
  rationale changes but **not a line of the code**. Update the comment; leave
  the order. Its LIFO restore at `15651-15654` is already correct.
* The one place worth re-reading: `avm2_push_scroll_rect_mask`'s documented
  "degenerate rect (`w` or `h` == 0) hides the subtree". Under Increment that is
  still true and still correct (no texel reaches `num_masks`).

### 5.4 MSAA

`render_webgpu.c` compiles with `MSAA_SAMPLES` = 4 by default and 1 for
`quality = "low"` goldens (`verify_output.py` passes `-DMSAA_SAMPLES=1`). The
depth-stencil texture is created at `sampleCount = MSAA_SAMPLES` (`1284`).
Increment/decrement are per-sample, so intersection is exact at both counts.
**The new clear pipeline must use `rpd.multisample.count = MSAA_SAMPLES`** —
never a literal 4 (standing invariant, s11). Both beneficiaries render at
`MSAA_SAMPLES = 1` (`displayobject_scrollrect` and `cache_as_bitmap/masks` both
declare `quality`; the former `"low"`, the latter `"high"`) — so **test both
arms**; `cache_as_bitmap/masks` is the 4-sample one and it is where the
3 %-margin flips live.

### 5.5 Files a wave-2 implementer edits

```
SWFModernRuntime/src/rendering/render_webgpu.c     ~120 lines (§5.1)
SWFModernRuntime/include/rendering/render_webgpu.h ~8 lines   (field + comment)
SWFModernRuntime/src/libswf/tag.c                  ~25 lines  (§5.2, 5 sites)
SWFModernRuntime/src/avm2/avm2_display.c           comment-only (§5.3)
ruffle-tests/tests/swfs/regression/mask_nested_intersect/{create_test_swf.py,
    test.swf, test.toml, output.txt, output.expected.png}   (§4.3, new test)
ruffle-tests/render_canary_tests.txt               +1 line (the new test)
```

**No `SWFRecomp/` change** — so no cmake rebuild in the worktree, and the
stale-recompiler false-negative (canary false-positive mode 1) cannot bite.
Runtime-only ⇒ the patch **cannot move a trace**; a trace status change in the
canary means something is wrong, not something is working.

---

## 6. Expected-flip ledger

| comparison | baseline | predicted | confidence |
|---|---:|---|---|
| `avm2/displayobject_scrollrect [output]` | 12 382 | **0 — FLIP** | HIGH (golden blue is exactly a subset of ours; parent crop already 0-error) |
| `visual/cache_as_bitmap/masks [output.01]` | 1 690 | **0 — FLIP** (3087/3200) | MED-HIGH |
| `… [output.02]` | 2 701 | **0 — FLIP** (2980/3200) | MED-HIGH |
| `… [output.03]` | 2 170 | **0 — FLIP** (3001/3200) | MED-HIGH |
| `… [output.04]` | 1 777 | **0 — FLIP** (3106/3200, 3 % margin) | MED |
| `… [output.05]` | 1 769 | **0 — FLIP** (2973/3200) | MED-HIGH |
| `… [output.06]` |   709 | **0 — FLIP** (2625/3200) | HIGH |
| `regression/mask_nested_intersect [output]` | not in suite | **new, PASS** if shipped with the patch | HIGH (axis-aligned, AA-free, tol 0) |
| `visual/cache_as_bitmap/masks [output.07]` | pass | pass (**must hold**) | its row 3 is already correct; the fix must be a no-op there |
| `visual/simple_shapes/masks`, `masks_equal_clipdepth` | 2 624 ×2 | unchanged (sibling ranges, not nested) | HARD-dispositioned; any move needs an explanation |
| `avm2/{displayobject_mask, mouse_pick_*_dobj_mask}`, `from_shumway/MaskTest`, `visual/avm2_button_scroll_rect` | 8 / 24 / 17 / 9 | unchanged or ±few px | `a_epsilon`; a free flip is possible, a free regression too |
| `cab_mask_{alpha,filters,transform,triangle}` | 4644/4968/2340/5080 | **unchanged** (§4.2 refutation) | if they move, the classification was wrong |

**Honest headline: +7 flips (of which 6 carry a 3–18 % margin), +1 if the new
regression test ships, 0 predicted regressions.** That is the largest single
pixel lead currently priced on the board. It is *not* the "1 firm + up to 6 band
moves" of board-audit §6.2 P4 — the difference is entirely the `output.07`
existence proof, which board-audit did not have.

---

## 7. Risk fence — the canary a wave-2 agent must satisfy

Two legs, deliberately: **leg A = §5.2 hygiene only** (must be
md5-IDENTICAL everywhere — if it is not, stop and find out why before touching
the renderer); **leg B = full patch**.

`ruffle-tests/render_canary.py capture/compare`, `-P 2`, `--recompile` on first
use in the worktree, `DAWN_INSTALL=~/CC/dawn-install`.

```
# --- standing set (20 tests / 37 cmps) -------------------------------------
ruffle-tests/render_canary_tests.txt

# --- MUST NOT MOVE: the fragile passes (in risk order) ---------------------
from_shumway/acid/acid-clip-2            2881/3000 outliers — the most fragile pass in the corpus
from_shumway/invalidClipDepth            257 clip ranges, tol 0 / max_out 0 — the pop-before-push canary
from_shumway/acid/acid-clip              tol 150, pass 0
from_shumway/acid/acid-clip-3            2 cmps, tol 0
from_shumway/clipping                    tol 2
from_shumway/MaskTest-3                  pass 0 — TRACE must stay ruffle_matched (known_failure)
avm1/mask_reapply                        clipDepth + setMask, tol 1 — defect B's hard gate
avm2/mask_reapply                        s12 flip
avm1/movieclip_setmask, avm1/mask_with_drawing
regression/mask_sibling_union            the one locally-gradeable mask golden, tol 0
avm2/blend_scroll                        scrollRect control
visual/focus_highlight/focus_highlight_empty_clip
visual/simple_shapes/masks, masks_equal_clipdepth   must stay EXACTLY 2624 (HARD-dispositioned)

# --- EditText blast radius (the field-bounds clip is a mask push/pop) ------
avm1/edittext_tag_indent
visual/edittext/edittext_border_transform            6 cmps
visual/cache_as_bitmap/edittext_scroll, edittext_hscroll
from_shumway/acid/acid-textfield-scroll              552/600 outliers — tight
text/auto_size/return                                AVM2 glyph stencil clip

# --- filter / blend blast radius (composite pipelines read mask_ref) ------
visual/filters/drop_shadow, visual/filters/blur_quality
visual/blend_modes/multiply, visual/blend_modes/add
avm2/blend_multiply_alpha

# --- a_epsilon tripwires (a ±1px move here is signal, not noise) ----------
avm2/displayobject_mask (8), from_shumway/MaskTest (17),
visual/avm2_button_scroll_rect (9), avm2/mouse_pick_dobj_mask (24)

# --- classification discriminator (MUST be md5-IDENTICAL) ----------------
visual/cache_as_bitmap/cab_mask_transform            §4.2 refutation

# --- expected-to-move ledger ---------------------------------------------
avm2/displayobject_scrollrect
visual/cache_as_bitmap/masks                          .01-.06 move, .07 MUST NOT
regression/mask_nested_intersect                      new
```

Trace canaries (runtime-only patch ⇒ all must be unchanged; run the
`regression` suite leg in the default NO_GRAPHICS mode too, since `tag.c` is
shared): `regression/mask_sibling_union`, `avm2/mouse_pick_masking`,
`from_shumway/timeline/nav/clipDepth`, `avm2/edittext_scrollh`,
`from_shumway/MaskTest-3` (must stay `ruffle_matched` — a move to `pass` on a
`known_failure` is the `ruffle-matched-hides-regression` trap in reverse).

Additional gates:

1. **Both MSAA arms.** `cache_as_bitmap/masks` is `quality = "high"` (4 samples);
   `displayobject_scrollrect` is `"low"` (1 sample). A pipeline created with a
   literal 4 fails loudly at 1 — but a *semantic* MSAA bug will only show on one
   arm.
2. **Absolute local numbers are quotable** for the 7 beneficiary comparisons
   (§3.3, md5-verified against CI actual) and for the s11/s12/s13 list
   (`simple_shapes/masks*`, `text_field_mask`, `acid-clip-2`, `mask_reapply`).
   **Not** for `acid-clip` or `from_shumway/clipping`.
3. **Balance audit before running anything**: every `begin_clip_mask` must reach
   exactly one pop on every path. Check for an `if (...) continue;` between
   `avm1_mask_push` and its `renderer_restore_clip` in all three loops
   (`tag.c:3667`, `5895`, `6870`) — under `Replace` an unbalanced pair was
   self-healing at the next `end_clip`; under a counter it is not.
4. **Ship the pin test.** `mask_nested_intersect` with a
   `~/CC/ruffle/target/release/exporter` golden. Without it, nothing in the
   repo pins intersection semantics and the next refactor silently un-does this.
5. Report the outcome as **flips**, and if any of `.01`–`.06` lands 100–300
   channels over the `tol 10` budget, say so — that is the predicted failure
   mode, not a surprise.

---

## 8. Traps

1. **`regression/mask_nested_intersect` is not graded.** Do not put it in a
   flip ledger unless you actually add the directory + golden in the same patch.
2. **`cache_as_bitmap/masks` is not a `tolerance = 0` test.** The results JSON
   reports the tightest *failing* check; the toml has three. Pricing it off the
   JSON alone loses the whole flip case.
3. **`RecompiledTags`/`RecompiledABC` on disk can be older than `test.swf`**
   (`cache_as_bitmap/masks`: Aug 1 vs Aug 6) and describes a *different movie* —
   the on-disk `tagMain.c` shows a 1-frame timeline for a test with 7 frame
   triggers. Parse the SWF, or `--recompile` first.
4. **Never trust the published `.difference.png`** (×4-brightened, alpha-mangled)
   and pass `alpha_only=False` to `getbbox()` on Pillow ≥9.2.
5. **`renderer_draw_rect` silently no-ops when the dynamic staging is full**
   (`render_webgpu.c:2083-2084`). Using it for the decrement makes stencil
   corruption a *capacity* bug. Use an NDC quad.
6. **Do not "fix" the double-increment you think overlapping mask geometry will
   cause.** `Equal` + `failOp = Keep` already makes the write idempotent (§2.1);
   adding a guard would break intersection.
7. **The `avm2_display.c:15354` EditText guard is not dead code to clean up in
   this patch** — removing it moves ~66 text comparisons. Separate change.
8. Local Dawn ≠ CI lavapipe **in general**; it *is* byte-identical for these
   seven (§3.3), which is a per-test finding and must be re-verified, not
   assumed, for any test you add to the grading set.

---

## Appendix — reproduction

```bash
export DAWN_INSTALL=~/CC/dawn-install
S=<scratch>/gfx-stencil
mkdir -p $S/tests/avm2 $S/tests/visual/cache_as_bitmap
cp -r ruffle-tests/tests/swfs/avm2/displayobject_scrollrect          $S/tests/avm2/
cp -r ruffle-tests/tests/swfs/visual/cache_as_bitmap/masks           $S/tests/visual/cache_as_bitmap/

python3 ruffle-tests/verify_output.py --tests-dir=$S/tests/avm2 \
    --test=displayobject_scrollrect --mode=graphics --images --recompile \
    --image-out-dir=$S/local-imgs --json $S/scrollrect.json
SWF_KEEP_BUILD_DIR=$S/keep python3 ruffle-tests/verify_output.py \
    --tests-dir=$S/tests/visual --test=cache_as_bitmap/masks \
    --mode=graphics --images --recompile --json $S/cabmasks.json   # $S/keep/output.NN.png

git fetch origin ruffle-image-results
git archive FETCH_HEAD | tar -x -C $S/image-results        # CI actual PNGs
md5sum $S/local-imgs/avm2/displayobject_scrollrect/output.actual.png \
       $S/image-results/images/avm2/displayobject_scrollrect/output.actual.png
```

Board regenerated for the sweep:
`python3 scripts/image_triage.py --images-dir $S/image-results --jobs 2 --out $S/board.json --markdown $S/board.md`
(263 failing comparisons at `fb36ba110`; `cache_as_bitmap/masks` is board rank #1,
`displayobject_scrollrect` sits in `extra_element`).
