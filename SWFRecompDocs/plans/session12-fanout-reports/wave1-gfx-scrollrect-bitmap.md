# wave1-gfx-scrollrect-bitmap — scrollRect stencil + AVM2 static-bitmap upload

Session 12, wave 1, **READ-ONLY**. Baseline `f166e424e`; image board =
merged CI run **`31075033086`** at `6de650432` (257/566, 45.4 %).
`git status` clean for tracked files throughout (only the three pre-existing
untracked dirs). Local Dawn renders were verified **md5-identical** to the CI
lavapipe actuals for every test I re-rendered (acid-color, acid-image,
acid-big), so the numbers below are CI numbers.

---

## 0. Headline

| lead | s11 claim | verdict at HEAD | wave-2 flips |
|---|---|---|---|
| **1. scrollRect stencil** | "flips blocked behind MSAA" | **REFUTED — the blocker was fixed by s11's own `w2-quality-msaa` patch.** New blockers found, and the cluster is **dual-VM**: 3 of the 5 members are **AVM1**, which s11 never looked at | **+1** (`cache_as_bitmap/scroll_rect_scaled`), 2 large band moves |
| **2. AVM2 static-bitmap upload** | "`bitmapbuttons` blank; blocker = recompiler gate + missing `tagInit` upload; acid-image/color/big are downstream of it" | **PARTLY REFUTED.** The acid family is **not** blocked on the static-bitmap upload at all. It is blocked on a **2-line runtime size cap** (`dynamic_bitmap_max_{w,h}` sized to the *stage*, not to the bitmaps). Proven with the CPU-raster twin | **+4** (acid-color ×2, acid-image, acid-big) — CPU-verified against the goldens |

**The single most valuable finding is §3.2**: `avm2_render_init` sets
`dynamic_bitmap_max_{w,h} = max(stage_w, stage_h, 256)`, and
`avm2_render_bitmap` silently drops any BitmapData bigger than that. Every
Shumway acid bitmap is bigger than its stage. Relaxing the cap to
`app->bitmap_highest_{w,h}` costs **zero extra VRAM** (the texture array is
*already* allocated at `bitmap_highest+1`, `render_webgpu.c:1219-1230`) and I
have measured, via the env-gated CPU walk, that our pixels already match all
three goldens **inside tolerance with zero outliers**.

---

## 0.1 Mandatory pre-checks (dispositions)

| test | ACCEPTED_DIFFS | RUFFLE_VS_FLASH | COMPAT_TWEAKS | FLASH_BUGS | ignored_tests | known_failure |
|---|---|---|---|---|---|---|
| `visual/avm2_button_scroll_rect` | — | — | — | — | — | false |
| `avm2/displayobject_scrollrect` | — | — | — | — | **`avm2/ignored_tests.txt:47`** (TRACE axis only) | false |
| `visual/cache_as_bitmap/scroll_rect` | — | — | — | — | — | false |
| `visual/cache_as_bitmap/scroll_rect_scaled` | — | — | — | — | — | false |
| `visual/simple_shapes/scroll_rect_mask` | — | — | — | — | — | false |
| `from_shumway/bitmapbuttons` | — | — | — | — | — | false |
| `from_shumway/acid/acid-image` | — | — | — | — | — | false |
| `from_shumway/acid/acid-color` | — | — | — | — | — | false |
| `from_shumway/acid/acid-big` | — | — | — | — | — | false |

The one `ignored_tests.txt` hit is a **trace**-axis entry; per
`image_triage.py`'s own banner ("a suite-local ignored_tests.txt entry says
nothing about the pixels"), it does not disposition the image comparison.
Nothing in scope is image-dispositioned.

---

# 1. Lead 1 — scrollRect stencil

## 1.1 PREMISE ATTACKED: the s11 blocker no longer exists

`session11-fanout-reports/wave1-gfx-clipping.md` §2.4 declared the scrollRect
pixel yield "gated behind an antialiasing sample-count mismatch… a perfect
scrollRect implementation leaves `avm2_button_scroll_rect` at ~96 outliers and
still `fail`", and recommended filing MSAA as its own board lead (item 3 of its
§5 table).

**That lead was taken in the same session.** `w2-quality-msaa` landed at
`6de650432`: `MSAA_SAMPLES` macro in `render_webgpu.c`, and
`verify_output.py:2014-2035` parses `player_options.with_renderer.quality` and
emits `-DMSAA_SAMPLES=1` for `quality = "low"` (`:2483`). The wave-1 report was
written against `b4c983ea4` and never re-checked.

Measured at HEAD, on the CI actual for `visual/avm2_button_scroll_rect`:

| | s11 baseline (`c4496a4c8`) | HEAD (`6de650432`) |
|---|---|---|
| distinct colours in our render | 3+ (AA fringe) | **2** — `#FFFFFF`, `#0099CC` |
| outliers | 34590 | **34083** |

Our render is now **antialias-free**, exactly like the golden. So I re-ran s11's
own simulation (translate content by the scrollRect origin, clip to the
object-local window) on the HEAD actual:

```
simulated perfect clip vs golden:  4 differing px / 12 differing channels, max 255
window search over ox,oy in [20,26): best = 12 channels at (22,22), 100x100  (exact)
the 4 pixels: (48,24) (40,30) (30,40) (24,48) — ours white, golden #0099CC
```

**s11's "~96 residual" is stale by 8×.** The remaining 12 channels are four
symmetric arc-edge pixels in the circle's upper-left quadrant, at 1-sample
rasterisation — i.e. the *same* sub-pixel tie class that s11 used to CAP
`blend_modes` (playbook §10: "18-60 channels, sub-pixel rasterisation ties at
`max_outliers=0`"). They are **not** scrollRect-related: they sit well inside
the clip window, and the shift is exactly 200 twips = 10 px, so an integer
pixel shift and a real geometry translation rasterise identically.

**Consequence: `avm2_button_scroll_rect` band-moves 34083 → 12 and still
`fail`.** The blocker is no longer MSAA; it is now the rasterisation-tie cap.

## 1.2 SCOPE ATTACKED: the cluster is dual-VM and s11 saw only half of it

s11 scoped scrollRect as an AVM2-only, 2-test lead. The corpus says otherwise —
grepping the image board for `scroll_rect|scrollrect` at HEAD:

| suite | test | cmp | outliers | tol | max_out | quality | **VM** |
|---|---|---|---|---|---|---|---|
| visual | `avm2_button_scroll_rect` | output | 34083 | 0 | 0 | low | AVM2 |
| avm2 | `displayobject_scrollrect` | output | 202388 | 0 | 0 | low | AVM2 |
| visual | `cache_as_bitmap/scroll_rect` | output | 18378 | 1 | 0 | low | **AVM1** |
| visual | `cache_as_bitmap/scroll_rect_scaled` | output | 41902 | 64 | 900 | high | **AVM1** |
| visual | `simple_shapes/scroll_rect_mask` | output | 434284 | 0 | 0 | low | **AVM1** |

I proved the VM split by parsing the SWF tag stream (including sprite bodies —
the `DoAction` in `cache_as_bitmap/scroll_rect` is nested inside `DefineSprite`
id 4 and is invisible to a top-level scan):

* `cache_as_bitmap/scroll_rect` — `DoAction`, constant pool
  `["a","scrollRect","_height","_width","flash","geom","Rectangle"]` →
  `a.scrollRect = new flash.geom.Rectangle(100, 50, a._width, a._height)`.
* `cache_as_bitmap/scroll_rect_scaled` — `DoAction` →
  `outer.scrollRect = new flash.geom.Rectangle(10, 10, 100, 100)`.
* `simple_shapes/scroll_rect_mask` — `DoAction` → `circle.scrollRect =
  new Rectangle(10,10,100,100)` **plus** `clip.setMask(mask)`.

**AVM1 `MovieClip.scrollRect` is completely unimplemented.** The only hit in the
whole AVM1 runtime is `SWFModernRuntime/src/actionmodern/action.c:15723-15733`,
where `"scrollRect"` is one of ten `extra_props` installed on
`MovieClip.prototype` as an *enumerable undefined own property* — a plain
storage slot with no setter hook and no render consumer.
`grep -n "scroll_rect" SWFModernRuntime/src/{actionmodern,libswf}/*.c` → **zero**.

## 1.3 Mechanism, re-verified at HEAD (AVM2 side — s11's pins drifted)

| what | s11 pin | **HEAD pin** |
|---|---|---|
| `avm2_render_node` (reads none of `has_scroll_rect` / `mask` / `clip_depth`) | `avm2_display.c:14843-14894` | **`avm2_display.c:15098-15150`** |
| storage `has_scroll_rect` + `sr_{x,y}{min,max}` | `avm2_globals.h:510-514` | `avm2_globals.h:513` (unchanged) |
| getter / setter | `avm2_display.c:10052-10081` | **`:10250` / `:10267` / `:10279`** |
| only non-getter consumer (bounds override) | `:722-731` | **`:725`** |
| `grep begin_clip\|end_clip\|scissor` over `src/avm2/` | zero | **still zero** |

So the *code* claim stands verbatim: the AVM2 walk has no clipping of any kind.
The s11 §2.3 patch sketch is structurally still correct — only the line pins and
one caveat need updating.

**Caveat that IS now stale:** s11 §2.3 said "Single nesting level only… one
global `ref = 1` region". That was masks *defect A*, and **s11's `w2-masks-defectA`
patch fixed it**: `render_webgpu.c:2154-2168` now has `alloc_mask_ref()`
handing out per-mask stencil references (with a full-screen clear + wrap at
255), and `begin/end_clip_mask` (`:2616-2653`) carry a `mask_capture_depth`
so nested pairs are no-ops rather than corruption. A scrollRect clip may
therefore nest with a timeline mask; wave 2 does **not** need the "skip the
inner clip" hack s11 prescribed.

Reference pattern (unchanged, verified at HEAD): the EditText field clip trio
`renderer_begin_clip_mask → renderer_draw_rect → renderer_end_clip_mask` at
`SWFModernRuntime/src/libswf/tag.c:4743-4745` (also `:3310-3331`, `:5264-5266`,
`:5523-5541`).

## 1.4 Predicted flips, measured per member

I simulated a perfect scrollRect (content translated by `(-x, -y)`, clipped to a
`w × h` box at the object's local origin) against each golden, searching the
window origin and size around the analytic answer.

| test | today | simulated perfect clip | flip? |
|---|---|---|---|
| `visual/cache_as_bitmap/scroll_rect_scaled` | 41902 (tol 64, max_out 900) | **8 excess channels** at shift `(-20,-20)` | **YES** |
| `visual/avm2_button_scroll_rect` | 34083 (tol 0, max_out 0) | 12 channels / 4 px — arc rasterisation ties | no (−99.96 % band move) |
| `visual/cache_as_bitmap/scroll_rect` | 18378 (tol 1, max_out 0) | **890 channels** at shift `(-100,-50)`, window `(179,117)+150×144` | no |
| `avm2/displayobject_scrollrect` | 202388 (tol 0, max_out 0) | large improvement; skewed matrix + trace also `output_mismatch` | no |
| `visual/simple_shapes/scroll_rect_mask` | 434284 (tol 0, max_out 0) | our render fills the **entire** 550×400 stage (no white at all) vs a 200×200 golden — scrollRect *and* `setMask` both missing | no |

Arithmetic that pins `cache_as_bitmap/scroll_rect`'s geometry (worth recording,
it is the proof the mechanism is right): our cyan region is
`(179,117)-(328,260)` = exactly **150×144 = 21600 px**; the golden's is
`(179,117)-(228,210)` = exactly **50×94 = 4700 px**. `Rectangle(100, 50, 150, 144)`
clips a 150×144 content box to `x∈[100,150], y∈[50,144]` = **50×94**, drawn at
the object origin. Exact, both ways. The residual 890 channels are the test's
**red 1-px outline**, which is displaced by `(+1,+1)` and has 294 px where the
golden has 445 — a pre-existing `cache_as_bitmap` stroke defect, independent of
scrollRect.

## 1.5 Verdict on lead 1 — **CONDITIONAL GO, rescoped**

* The s11 blocker (MSAA) is **gone**. Refutation is yield.
* The replacement blockers are per-member and named above; none is arc-sized on
  its own, but **the yield is +1, not the +2 the board implies.**
* A wave-2 patch that does **only** the AVM2 sketch yields **0 flips**. The
  single flip lives on the **AVM1** side, which s11 never scoped and which is a
  larger job (new storage on the MovieClip struct, a `setMember`/`getMember`
  hook next to the existing `blendMode` pair at `action.c:49610` and `:53491`,
  and the clip trio in the tag.c display walk).
* Recommended wave-2 shape: **one agent, both VMs, ~2.5 h.** AVM2 first
  (structurally trivial, unlocks two large band moves and is correctness-
  positive for games), then AVM1 with `cache_as_bitmap/scroll_rect_scaled` as
  the graded target. If the coordinator wants a pixel-per-hour cut, this lead is
  **below** lead 2 and below the text/auto_size slice.

### Risk + canary
* Blast radius is thin on the AVM2 side (gated on `ext->has_scroll_rect`, which
  only the setter at `:10279` writes). On the AVM1 side the gate must be a new
  field, **not** the existing enumerable `extra_props` slot at
  `action.c:15726` — that slot is user-writable and several tests enumerate it.
* Must-stay-md5-IDENTICAL: `avm2/blend_scroll` (**name trap: this is
  `BitmapData.scroll`, not `scrollRect`**), `avm2/bitmap_subclass_properties`,
  `avm2/bitmapdata_copychannel`, `avm2/pixelbender_images`,
  `regression/avm2_timeline_gradients`, `regression/avm2_timeline_stroke_gradient`,
  `regression/mask_sibling_union`, `from_shumway/button1`, `from_shumway/MaskTest-2`,
  plus the standing `render_canary_tests.txt`.
* Expected-to-DIFFER ledger: the five rows in §1.4.
* Trace canary: `avm2/displayobject_scrollrect` (must stay `output_mismatch`,
  **not** regress — it is `known_failure = false` but trace-ignored),
  `avm2/button_bounds`, `avm2/button_hittest`, `avm2/stage_properties2`,
  and any AVM1 test that enumerates `MovieClip.prototype`
  (`for-in` order changes if a real property replaces the undefined slot).

---

# 2. Lead 2 — AVM2 static-bitmap upload: scoped, and the framing is wrong

## 2.1 The blank_render cluster, sized

`scripts/image_triage.py` at the HEAD baseline: **55 `blank_render`
comparisons**. Decomposition:

| sub-cluster | cmps | owner |
|---|---|---|
| Stage3D / AGAL | 26 | backend arc, not this lead |
| video (h264 / vp6 / h263 / netstream) | 8 | decoder arc |
| PixelBender | 3 | backend arc |
| fonts (`device-font`, `definefont4`) | 2 | B9 device-font arc |
| `cache_as_bitmap/oversize/swf_{9,10}_masks` | 2 | cacheAsBitmap arc |
| `acid-shapes`, `acid-gradient-2`, `gradientTransform`, `geom_transform`, `loader_jpegxr{,_alpha}`, `acid-bitmap-draw_quality_{high,low}` | 8 | unrelated |
| **AVM2 + embedded raster bitmaps** | **6** | **this lead** |

The six: `acid-color` ×2, `acid-image`, `acid-big`, `bitmapbuttons`,
`pixelbender_effect_twirl` (double-blocked by PixelBender).

## 2.2 REFUTATION: the acid family is not a static-bitmap-upload problem

s11 §4.3 named `acid-image`, `acid-color` ×2 and `acid-big` as downstream of the
"AVM2 static bitmap fills" tranche. **They have zero DefineShape tags.** SWF tag
scan:

| test | shapes | bitmap tags | SymbolClass |
|---|---|---|---|
| `acid-image` | **0** | `DefineBitsLossless` ×1 | `acid_image_fla.MainTimeline` |
| `acid-color` | **0** | `DefineBitsLossless2` ×1 | `Bitmap6` |
| `acid-big` | **0** | `JPEGTables` + `DefineBits` | `Bitmap2` |
| `bitmapbuttons` | 10 | `JPEGTables`, `DefineBits`, `DefineBitsLossless2` ×9, `DefineBitsLossless`, `DefineBitsJPEG3` | `bitmapbuttons_fla.btnplay_4` |

The three acid tests place a **bitmap character directly**, which the AVM2
timeline already handles: `avm2_display.c:1808` calls
`avm2_bitmap_seed_timeline` (`avm2_bitmap.c:2846-2874`), which sets
`ext->is_bitmap` and seeds a `BitmapData` from `avm2_generated_bitmaps` via
`bd_seed_embedded`. They render through `avm2_render_bitmap`
(`avm2_display.c:14493`) → `renderer_draw_bitmap_quad_scaled`, i.e. the
**dynamic** bitmap layer. `renderer_upload_bitmap` / `tagInit` are not on that
path at all.

## 2.3 The actual mechanism — a stage-sized cap on the dynamic bitmap layer

`avm2_render_init` (`SWFModernRuntime/src/avm2/avm2_display.c:15220-15229`):

```c
// Dynamic bitmap-layer dims. AVM2 has no static bitmaps (BITMAP_COUNT 0),
// so the dynamic layer is sized to dynamic_bitmap_max_{w,h}+1 ...
uint32_t maxdim = app->width > app->height ? app->width : app->height;
if (maxdim < 256) maxdim = 256;
context->dynamic_bitmap_max_w = maxdim;
context->dynamic_bitmap_max_h = maxdim;
```

and `avm2_render_bitmap` (`avm2_display.c:14503-14508`):

```c
// Honest failure: a BitmapData larger than the dynamic layer is skipped
// (blank) rather than corrupting the texture / crashing.
if (bd->width  > context->dynamic_bitmap_max_w
 || bd->height > context->dynamic_bitmap_max_h)
	return;
```

(duplicated as a second guard at `render_webgpu.c:2346`).

Measured, from each test's generated `RecompiledTags/constants.h`:

| test | stage | cap `max(w,h,256)` | `BITMAP_HIGHEST_W × H` | drawn? |
|---|---|---|---|---|
| `acid-color` | 550×400 | 550 | **1840 × 1840** | **NO** |
| `acid-image` | 512×512 | 512 | **861 × 737** | **NO** |
| `acid-big` | 512×512 | 512 | **2080 × 1100** | **NO** |
| `bitmapbuttons` | 590×350 | 590 | **680 × 400** | **NO** (and shape-fill blocked, §2.5) |
| `avm2/graphics_bitmaps` | 550×400 | 550 | 96 × 96 | not size-blocked — a `beginBitmapFill` gap |
| `avm2/graphics_bitmap_fill` | 500×375 | 500 | 74 × 74 | not size-blocked — same |

Note the comment is **provably stale**: `BITMAP_COUNT` is 1 for each acid test
and **12** for `bitmapbuttons`.

## 2.4 PROOF, and the predicted flips

The GPU walk has a CPU twin — `avm2_cpu_walk` (`avm2_display.c:14231`) →
`avm2_cpu_composite_bitmap` (`:14168`) — which is env-gated on `AVM2_CPU_DUMP`
and **carries no size guard**. That makes it a read-only probe for "would the
pixels be right if the guard let them through". I built each test with
`SWF_KEEP_BUILD_DIR` and ran `AVM2_CPU_DUMP=<prefix> ./test_run`, then compared
the final PPM to the repo golden at that test's own tolerance:

| test | cmp | tol | max_out | **CPU-twin outliers** | max diff | verdict |
|---|---|---|---|---|---|---|
| `from_shumway/acid/acid-color` | output | 3 | 0 | **0** | 3 | **PASS** |
| `from_shumway/acid/acid-color` | frame1 | 3 | 0 | **0** | 3 | **PASS** |
| `from_shumway/acid/acid-image` | output | 11 | 0 | **0** | 11 | **PASS** |
| `from_shumway/acid/acid-big` | output | 50 | 20 | **0** | 50 | **PASS** |

(acid-color's CPU dump is 15117 distinct colours in 550×400 — a full photographic
render — against a golden our GPU path currently answers with 3 flat colours.)

**Predicted wave-2 flips: +4 comparisons.** Confidence **high on the pixels,
medium on the transfer**: the residual risk is GPU-vs-CPU sampling parity, since
`render_webgpu_draw_bitmap_quad_scaled` uses Nearest + ClampToEdge on a padded
layer with `bitmap_sizes` UV normalisation, whereas `avm2_cpu_composite_bitmap`
is a separate implementation. The precedent is good (`avm2_cpu_raster.c` was
written to mirror the WGSL shader — see the `cpu-raster` premul-parity note),
and every one of the four has slack at the *pixel* level (max diff lands exactly
at tolerance, meaning Ruffle's own tolerances were tuned to a resampling gap of
this size).

## 2.5 The fix, and why it is nearly free

```c
/* avm2_display.c:15224-15229 — replace the stage-only cap */
uint32_t maxdim = app->width > app->height ? app->width : app->height;
if (maxdim < 256) maxdim = 256;
context->dynamic_bitmap_max_w = maxdim > app->bitmap_highest_w ? maxdim : app->bitmap_highest_w;
context->dynamic_bitmap_max_h = maxdim > app->bitmap_highest_h ? maxdim : app->bitmap_highest_h;
```

**Zero VRAM delta**, verified against `render_webgpu.c:1219-1230`:

```c
u32 bw = (ctx->bitmap_highest_w > 0 ? ctx->bitmap_highest_w + 1 : ctx->dynamic_bitmap_max_w + 1);
if (ctx->bitmap_count > 0) { if (ctx->dynamic_bitmap_max_w + 1 > bw) bw = ctx->dynamic_bitmap_max_w + 1; }
```

The array is already sized to `max(bitmap_highest+1, dynamic_max+1)`. Raising
`dynamic_max` to `bitmap_highest` cannot raise that maximum. When
`bitmap_count == 0`, `bitmap_highest` is 0 and the expression is unchanged. The
texture for `acid-color` is *already* `1841 × 1841 × 4 × (1 + MAX_DYNAMIC_BITMAPS 64)`
today — we allocate it and then refuse to draw into it.

Per-frame upload cost rises (the `(src+1)²` sub-region write at
`render_webgpu.c:2360-2380`: ~13.5 MB/frame for acid-color's 1840², ~9.2 MB for
acid-big's 2080×1100). Acceptable for 10–300-tick tests; **note it in the patch**
as a known cost for any game with a giant atlas, and consider gating the
relaxation on `OFFSCREEN_RENDER || !__EMSCRIPTEN__` if browser frame time
matters.

## 2.6 `bitmapbuttons` — s11's two blockers CONFIRMED at HEAD, and it is still a DEFER

Unlike the acid family, `bitmapbuttons` genuinely is the static-shape-bitmap-fill
case (10 `DefineShape`s, `8 of 10` with `renderable = 0` in
`RecompiledABC/abc_timeline.c:87-98`).

* **Blocker A (recompiler)** — `SWFRecomp/src/swf.cpp:9278-9280`
  (`if (fs.type >= FILL_BITMAP_REPEAT && !tris.empty()) shape_renderable = false;`),
  written at `:9369` / `:9388`; honoured by `resolve_shape_geom`
  (`avm2_display.c:446-467`, comment `:450` "bitmap-fill shapes stay deferred").
  **CONFIRMED, line-shifted from s11's `:9245-9251`.**
* **Blocker B (upload)** — `defineBitmap` / `finalizeBitmaps`
  (`tag.c:11743-11752`) live only in the generated `tagInit()`, whose sole
  callers are `swf.c:1689` and `swf_core.c:882`. `runSWF_avm2`
  (`avm2_main.c:496`) never calls it. **CONFIRMED.** Its `tagMain.c` emits all
  12 `defineBitmap(...)` calls today, so the cheapest shape is a recompiler
  split of `tagInitBitmaps()` out of `tagInit()` (the rest of `tagInit` is
  `tagDefineSprite`/`tagSetSpritePlacements`, AVM1 tables the AVM2 path must
  not touch), called from `avm2_render_init` **in emission order** — the layer
  index is a sequential `ctx->current_bitmap++` (`render_webgpu.c:2906`) and
  the recompiler baked that index into the vertex `style.y`.
* **Third blocker**: its 680×400 background also trips §2.3's size cap.

**Still DEFER for pixels.** `tolerance = 4` with `max_outliers = 0` against a
`DefineBitsJPEG3` photograph resampled 680×400 → 590×350 is not winnable; the
comparable *passing* AVM1 test `acid/acid-bitmap-fill-2` is allowed **9000**
outliers. Take the tranche for the mechanism (it unblocks AVM2 game content with
library bitmap fills), never for this comparison — and measure it on a
generous-tolerance target.

## 2.7 Verdict on lead 2 — **GO, rescoped and split**

| # | item | size | flips |
|---|---|---|---|
| **2a** | **Dynamic-bitmap size cap → `bitmap_highest`** (`avm2_display.c:15224-15229`) | **runtime-only, ~4 lines, 1 agent, ~1 h incl. canary** | **+4** |
| 2b | AVM2 static shape bitmap fills (recompiler gate + `tagInitBitmaps` emission + upload) | recompiler + runtime, arc-sized tranche | `bitmapbuttons` unlikely; unblocks library-bitmap game content |
| 2c | `Graphics.beginBitmapFill` on the AVM2 T4 path (`graphics_bitmaps`, `graphics_bitmap_fill`) | separate, unscoped | 2 candidates, unmeasured |

**2a is the highest pixel-per-hour item found in this wave and should be the
anchor patch.**

### Risk + canary for 2a
* The change only *admits* draws that are currently dropped; it cannot alter a
  bitmap already under the cap, and it cannot resize any texture (§2.5).
* Must-stay-md5-IDENTICAL: every AVM2 test whose `BITMAP_HIGHEST ≤ stage`
  — `avm2/graphics_bitmaps`, `avm2/graphics_bitmap_fill`,
  `avm2/bitmap_subclass_properties`, `avm2/bitmapdata_copychannel`,
  `avm2/bitmapdata_copypixels_blend_over`, `avm2/pixelbender_images`,
  `from_shumway/acid/acid-bitmap-fill-2` (AVM1, must be untouched — the change
  is inside `avm2_render_init`), plus the standing `render_canary_tests.txt`.
* Expected-to-DIFFER ledger: `acid-color` (output, frame1), `acid-image`,
  `acid-big`, `bitmapbuttons` (improves, still fails),
  `avm2/pixelbender_effect_twirl` (may improve, PixelBender-blocked).
* **Watch for `MAX_DYNAMIC_BITMAPS` exhaustion** (`render_webgpu.c:1076`, 64
  layers) and for `dynamic_bitmap_used >= capacity` early-returns
  (`:2345`, `:2497`) on any test that now admits many large bitmaps.
* Trace canary: none needed — the change is render-only and no test in scope
  has a trace dependency on it (all four acid tests already trace-`pass`).
* **CI**: invisible under the standing `images=false`. Any observing run needs
  `mode=graphics`, `categories=all`, **`images=true`**.

---

# 3. Methodology notes worth promoting to the playbook

1. **`AVM2_CPU_DUMP` is a read-only oracle for "is this a GPU-path bug or a
   data bug".** `avm2_cpu_walk` is a full CPU twin of `avm2_render_node` and
   skips most GPU-side guards. Build with `SWF_KEEP_BUILD_DIR=<dir>`, then
   `cd <dir> && AVM2_CPU_DUMP=<prefix> ./test_run` → `<prefix>NNN.ppm` per tick.
   Comparing that PPM to the golden turned a "two blockers, one in the
   recompiler, flip unlikely" deferral into a measured **+4**.
2. **Re-check a prior session's blocker claims against that same session's own
   wave-2 patches.** The playbook §10 line "scrollRect stencil (sketch ready,
   flips blocked)" was written after `w2-quality-msaa` had already removed the
   block it referred to.
3. **Parse nested `DefineSprite` bodies when classifying a test's VM.** Three
   of the five scrollRect tests are AVM1 and their `DoAction` is inside a
   sprite; a top-level tag histogram reports them as script-free.
4. **A `--test=` name grep on the image board is a cheap cluster-finder that
   `image_triage.py` does not give you** — the tool clusters by *visual*
   mechanism, so `scroll_rect` members scattered across `blank_render`,
   `extra_element` and `content_displaced` never group.
5. **The pkill self-match trap bit again** (`pkill -f "cache_as_bitmap.scroll_rect"`
   killed my own analysis heredoc). Bracket a character, per the standing note.
