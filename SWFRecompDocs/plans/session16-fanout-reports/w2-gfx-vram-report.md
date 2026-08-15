# w2-gfx-vram — VRAM clamp + per-fill bitmap smoothing (session 16, wave 2)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a7b703478aecc633f`
Base `cd04f80b9`. Brief of record: `wave1-gfx-vram.md`. Grading run for the
"CI" column: `31748059158` at `3db858cbc`.

---

## NEW FILES

**The patches create NO new source files.** Both edit two existing files only:

| file | patch |
|---|---|
| `SWFModernRuntime/src/rendering/render_webgpu.c` | A and B |
| `SWFModernRuntime/include/rendering/render_webgpu.h` | B only |

The only new files anywhere are the three deliverables, all under
`SWFRecompDocs/plans/session16-fanout-reports/`:
`w2-gfx-vram-report.md`, `w2-gfx-vram-clamp.patch`, `w2-gfx-vram-smooth.patch`.

**Stacking order:** `w2-gfx-vram-clamp.patch` (A) first, then
`w2-gfx-vram-smooth.patch` (B). The hunks are disjoint and apply in either
order; this is the order every measurement below used, and the order in which
both were regenerated from the tree (both are current as of this report).

Note for the coordinator: **B edits a header** (`render_webgpu.h`), which
`renderer.h` includes, so it invalidates `action.o` for every test. Nothing to
stage differently — just don't be surprised by the CI build time.

---

## 0. Headline

| item | verdict | flips |
|---|---|---|
| **A. VRAM clamp** (`BITMAP_ARRAY_HARD_LIMIT` = 1.5 GiB in `plan_dynamic_bitmaps`) | **GO — but only together with B** | 0 alone; **turns the corpus's only `no_render` into a 139 500-outlier `fail`** if shipped alone (measured, §3.6) |
| **B. Per-fill bitmap smoothing** | **GO** | **+1 with A: `from_shumway/acid/acid-large [output]` fail → PASS** |
| **A + B** | **GO — ship as one unit** | **+1 comparison**, zero regressions over 60 graded comparisons |
| B's briefed *mechanism* (recompiler "collapses all four fill types"; plumb the bit through bit 15 of `style_id`) | **REFUTED — no recompiler change is needed at all** | §1 |
| Global linear sampler | **DEAD** (wave 1); my per-fill form keeps `acid-blend` byte-identical, confirming it | — |

**Sampler-selection function (for w2-gfx-opaque):**
`render_webgpu_bitmap_fill_style_word(int repeat, int smooth)` —
a `static inline` in `SWFModernRuntime/include/rendering/render_webgpu.h`
returning the SWF fill-type byte (`0x40`/`0x41` smoothed, `0x42`/`0x43` not).
Every dynamic bitmap draw builds its vertex style word through it and the
fragment shader's sampler choice follows from that byte alone. An AVM2
`beginBitmapFill(bmp, matrix, repeat, smooth)` needs **no renderer change**:
`render_webgpu_draw_bitmap_tris` already takes `smooth` and now honours it —
just route the AS argument into the existing `DrawingRenderInfo.bitmap_smooth`
field (`tag.c:5678` already forwards it).

---

## 1. The briefed premise is wrong in a way that makes B *cheaper*

The brief said `SWFRecomp/src/swf.cpp:7625-7653` "collapses all four" bitmap
fill types, and proposed smuggling the smoothing bit through bit 15 of the low
half of `style_id`. **That reads the wrong thing.** Those four `case` labels
share a *parse body* (all four fill styles have identical wire layout: char id +
two matrices) — but `fill_styles[i].type` is assigned the **raw fill-type byte**
before the switch (`swf.cpp:7020` / `:7413`) and is emitted verbatim as the
vertex style type (`swf.cpp:10011` and `:10223`:
`u32 style_type_packed = (u32) fs.type;`, with only gradients ORing extra bits
in). The vertex shader already forwards the whole byte
(`out.v_style_type = in.style.x & 0xFFu`), and the fragment shader already
*branched* on all four values — it just mapped them to the same sampler.

Verified end to end on the real artefact, not by reading: recompiling
`acid-large` and grepping its emitted shape data —

```
$ grep -ohE ", 0x4[0-3], " ruffle-tests/.../acid-large/RecompiledTags/*.c | sort | uniq -c
      6 , 0x41,
```

`0x41` = clipped, **smoothed**. The bit was in the vertex buffer the whole time.

**Consequence: B is a runtime-only patch.** No `SWFRecomp/` edit, no
`--recompile`, no cmake step, and the canary's false-negative mode 1 does not
apply. I still built the recompiler in this worktree (clean cmake) so every
number below came from a self-contained tree.

### 1.1 Static blast-radius census (this is what makes B safe)

Old shader = "all four → Nearest". New shader = "`0x42`/`0x43` → Nearest via a
character-identical expression, `0x40`/`0x41` → Linear". So **only a draw whose
style byte is `0x40`/`0x41` in the new build can change any pixel.** I
recompiled **all 119 test directories** present in this worktree (the entire
standing canary set, the whole tracked `regression` suite, the acid family and
the bitmap families) and censused their emitted style bytes:

| test | bitmap-fill vertices emitted | affected by B? |
|---|---|---|
| `from_shumway/acid/acid-bitmap-fill` | 42 × `0x40`, 6 × `0x41` | **yes** |
| `from_shumway/acid/acid-bitmap-fill-2` | 6 × `0x41` | **yes** |
| `from_shumway/acid/acid-color-0` | 6 × `0x41` | **yes** |
| `from_shumway/acid/acid-large` | 6 × `0x41` | **yes** |
| `from_shumway/acid/acid-blend` | 6 × `0x43` | no (control) |
| `from_shumway/acid/acid-blend-2` | 6 × `0x43` | no (control) |
| **the other 113 test dirs** | **none at all** | no |

Plus the dynamic path: `beginBitmapFill` appears in exactly two image-bearing
tests in this corpus slice (`avm2/graphics_bitmap_fill`, `avm2/graphics_bitmaps`,
both already failing). The `attachBitmap` / `Bitmap` / video path
(`draw_bitmap_quad_scaled`) is switched from an implicit `0x41` to an explicit
`0x43`, i.e. it keeps Nearest — Flash's default for `Bitmap.smoothing` and
`attachBitmap` is `false`, so that is both correct and byte-neutral.

The measured canary agrees with this census exactly: 57/60 comparisons
IDENTICAL, and the 3 that moved are all in the census's "yes" column.

---

## 2. What the patches do

### A — `w2-gfx-vram-clamp.patch` (39 lines, one function)

`plan_dynamic_bitmaps()` gains `BITMAP_ARRAY_HARD_LIMIT = 1.5 GiB`, applied
**after** the existing `MAX_DYNAMIC_BITMAPS` floor — it is the only clamp
allowed to lower capacity below 64, because under-allocating layers costs
dropped dynamic draws while breaching lavapipe's 2 GiB
`maxMemoryAllocationSize` costs the entire frame. `acid-large`:
`1.5 GiB / 36.95 MB` = 41 affordable layers − 1 static = cap 40, array
1 588 578 292 B = 1.479 GiB → allocates. s15's `MAX_DYNAMIC_BITMAPS` budgeting
semantics are untouched, and s15's blur growth to 128 survives (2.45 MB layers
→ 626 layers of room, ≫ 128).

### B — `w2-gfx-vram-smooth.patch` (runtime only)

- `render_webgpu.h`: trailing struct field `bitmap_sampler_linear`; the
  `render_webgpu_bitmap_fill_style_word` inline helper.
- WGSL: `@group(2) @binding(4) var bitmap_samp_linear`, and both bitmap arms of
  `fs_main` pick `bitmap_samp_linear` for `0x40`/`0x41` and the *unchanged*
  expression through `bitmap_samp` for `0x42`/`0x43`.
- `create_textures`: a second sampler, same `ClampToEdge` addressing, Linear
  filtering. Group-2 BGL and bind group go 4 → 5 entries; released in
  `render_webgpu_free`.
- `draw_bitmap_tris`: the dead `(void)smooth;` is gone (its comment was also
  factually wrong — it claimed the sampler was "fixed at linear" when it was
  fixed at *nearest*); the style word is now
  `render_webgpu_bitmap_fill_style_word(repeat, smooth)`.
- `draw_bitmap_quad_scaled`: explicit `0x43` (was a bare `0x41` literal).

No new pipeline is created, so the `MSAA_SAMPLES` invariant is not in play
(`acid-large` runs `quality="low"` → `MSAA_SAMPLES=1`, confirmed in its gcc line).

---

## 3. Ledger — every graded comparison, before vs after

Method: `ruffle-tests/render_canary.py capture` on a 38-test / 60-comparison
list = **the entire standing canary set (22 tests / 37 comparisons)** plus the
covering acid set plus ~13 bitmap tests, captured once with both patches
reverted and once with both applied, then `compare before after`. Local
`--mode=graphics` is forced onto the same lavapipe ICD CI uses
(`verify_output.py:4113-4114`), and every "before" number below that has a CI
counterpart reproduces it **exactly** (`acid-blend` 101/348, `acid-bitmap-fill`
67 908/70 000, `acid-bitmap-fill-2` 8 689/9 000, `acid-color` 0 max 3 / max 2,
`acid-color-0` 34 323, `acid-large` `no_render`).

### 3.1 `render_canary.py compare before after`

```
RENDER CANARY  before=before  after=after   38 tests / 60 comparisons

  IDENTICAL    57
  DIFFERS       2
  APPEARED      1   VANISHED 0   NO_RENDER 0

  DIFFERS:
    from_shumway/acid/acid-bitmap-fill  output   [DIFFERS]
        diff_channels 340606/1920000  mean 0.5547  max 79   bbox (23,31)-(574,567)
        image status: pass -> pass    trace: pass -> pass
    from_shumway/acid/acid-color-0  output   [DIFFERS]
        diff_channels 14402/4194304  mean 0.0109  max 116   bbox (8,388)-(250,504)
        image status: fail -> fail    trace: pass -> pass
    from_shumway/acid/acid-large  output   [APPEARED]
        image status: fail -> pass    trace: pass -> pass

  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES:
    from_shumway/acid/acid-large  output   fail -> pass        <-- REVIEW
```

**All 37 standing-canary comparisons are md5-IDENTICAL.**

### 3.2 The rows that moved

| test / cmp | before | after | budget | verdict |
|---|---|---|---|---|
| `from_shumway/acid/acid-large [output]` | **`no_render`** (no PNG at all) | **0 outliers, max diff 3, mean 0.170** | tol 11, max_outliers 0 | **fail → PASS (+1)** — 0/0, and max 3 vs tol 11 is 3.7× headroom, not a knife edge |
| `from_shumway/acid/acid-bitmap-fill [output]` | 67 908 outliers, max 192 | **63 432**, max 193 | 70 000 @ tol 12 (+3 further checks) | pass → pass, **4 476 outliers of headroom recovered** (97.0 % → 90.6 % of budget) |
| `from_shumway/acid/acid-color-0 [output]` | 34 323, max 255 | **32 532**, max 255 | 3 | fail → fail, band gain 1 791 |

### 3.3 The rows that must NOT move — all IDENTICAL

| test / cmp | before = after | note |
|---|---|---|
| `acid/acid-bitmap-fill-2 [output]` | 8 689 / 9 000, max 30 | **96.5 % of budget — IDENTICAL, does not cross.** Its two `0x41` fills sit at a scale where linear and nearest land on the same texels |
| `acid/acid-blend [output]` | 101 / 348, max 255 | the `0x43` control that killed the global-linear leg — **holds exactly** |
| `acid/acid-blend-2 [output.10/.15/.20/.26/.40]` | 4098/5000, 5876/6000, 5242/5500, 5566/6000, 8484/9000 | canary member, 5/5 IDENTICAL |
| `acid/acid-color [output]`, `[frame1]` | 0/0 max 3, 0/0 max 2 | IDENTICAL |
| `acid/acid-gradient-0`, `timeline_as2_5` (7 cmps), `regression/mask_sibling_union`, `regression/mask_nested_intersect`, `regression/avm2_timeline_gradients`, `regression/avm2_timeline_stroke_gradient`, `regression/avm2_morph`, `visual/simple_shapes/{winding_rule,masks,gradients}`, `visual/filters/{drop_shadow,color_matrix}`, `visual/blend_modes/multiply`, `visual/cache_as_bitmap/shape_changed`, `avm1/{color,mask_with_drawing,movieclip_setmask,edittext_tag_indent,focusrect_swf5 ×12,bitmap_data_fillrect,bitmapdata_applyfilter_colormatrix}`, `avm2/blend_multiply_alpha` | all IDENTICAL | the rest of the standing canary |

### 3.4 The ~10 passing bitmap tests (md5)

| test | before = after | md5 |
|---|---|---|
| `avm1/bitmap_data_fillrect` | 0/0 max 0 | IDENTICAL |
| `avm1/bitmap_data_colortransform` | 0/0 max 4 | IDENTICAL |
| `avm1/bitmap_data_perlinnoise` | 0/0 max 0 | IDENTICAL |
| `avm1/bitmap_data_pixeldissolve_image` | 0/0 max 0 | IDENTICAL |
| `avm1/bitmapdata_applyfilter_colormatrix` | 0/0 max 1 | IDENTICAL |
| `avm2/bitmapdata_embedded` | 0/0 max 0 | IDENTICAL |
| `avm2/bitmapdata_fillrect` | 0/0 max 0 | IDENTICAL |
| `visual/bitmapdata_copypixels_with_alpha_oob` | 0/0 max 0 | IDENTICAL |
| `visual/cache_as_bitmap/shape_changed` | 0/0 max 0 | IDENTICAL |
| `avm2/bitmapdata_draw` (already failing) | 24 585 / 600 max 255 | IDENTICAL |
| `avm2/graphics_bitmap_fill` (already failing, `beginBitmapFill`) | 136 090 / 60 max 235 | IDENTICAL |
| `avm2/graphics_bitmaps` (already failing, `beginBitmapFill`) | 186 030 / 600 max 255 | IDENTICAL |

That the two `beginBitmapFill` tests are IDENTICAL means their AVM2 fills reach
`draw_bitmap_tris` with `smooth = 0` today — consistent with w2-gfx-opaque's
AVM2 routing still being the missing piece, and with the honouring of `smooth`
being inert until that lands.

### 3.5 Trace axis

- Canary: **0 trace status changes over all 38 tests**; the 11 tests that carry
  an expected trace have **byte-identical `trace.txt`** before vs after.
- Separately, in **`no-graphics` mode** (the axis where `render_webgpu.c` is not
  even compiled — `render_stub.c` is): `avm2/{bitmapdata_draw,
  bitmapdata_embedded, bitmapdata_fillrect, graphics_bitmap_fill,
  graphics_bitmaps}` → **5/5 PASS** with both patches applied. This also proves
  `render_stub.c` still compiles against the changed header.

### 3.6 A alone is a ledger trap — measured

Third leg, patch A applied and B reverted, `acid-large` only:

| leg | status | outliers | max diff | mean |
|---|---|---|---|---|
| baseline | `no_render` | — | — | — |
| **A only** | **fail** | **139 500** (excess 139 500) | 80 | 5.66 |
| A + B | **pass** | **0** | 3 | 0.170 |

Byte-for-byte wave 1's prediction. **If s16 ships A without B the pixel board
gains a new visible 139 500-outlier failure row and zero flips.** Ship both or
neither.

---

## 4. Attacking my own brief

1. **"Plumb the smoothing bit from the recompiler" — refuted.** The bit was
   already there; the fix is 100 % runtime. This removes the brief's whole
   "medium risk / recompiler rebuild / stale-cache false-negative" cost line,
   and it is why w2-gfx-opaque needs nothing from me beyond passing `smooth`.
2. **"acid-bitmap-fill-2 at 96.5 % of budget is the exposed row" — refuted, it
   does not move at all.** The exposed row was `acid-bitmap-fill` (97.0 %), and
   it moved the *right* way, gaining 4 476 outliers of headroom.
3. **The 1.5 GiB constant is not tuned to `acid-large`.** Wave 1's corpus audit
   put the runner-up at 840 MB, and my own 119-dir census found nothing else
   with a large atlas. It fires on exactly one test in the corpus.
4. **The canary's blind spot for B was real; it is now covered.** The standing
   set's only bitmap-*fill* member is `acid-blend-2` and its fill is `0x43`, so
   the standing set alone could never have seen a smoothed-fill regression. I
   ran the standing 22 **plus** the 4 census-identified smoothed-fill tests plus
   12 bitmap tests as one 38-test list; that combined list
   (`w2vram/full_list.txt`) is the covering set a future bitmap-sampler change
   should re-run. Worth considering `acid-bitmap-fill` as a standing member —
   it is the only CI-passing test with a `0x40` repeating smoothed fill.
5. **Not a disposition candidate.** `acid-large` passes at 0 outliers against a
   `max_outliers = 0` limit with max diff 3 vs tolerance 11.

## 5. NO-GO / deferred (restated with my evidence)

- **Option C, decoupled static/dynamic arrays — HELD.** Buys no flip that A does
  not; needs a WGSL + bind-group change and moves the padded dims the shader
  divides UVs by. Flips to GO if a browser title needs > 1.5 GiB of static
  atlas, or if AVM2's `dynamic_bitmap_max = bitmap_highest` rule is replaced by
  per-BitmapData sizing (which would also make C help AVM2 at all).
- **Option D, lazy/tiered layers — PARKED.** Corpus max dynamic-layer demand is
  1 of 64.
- **`Bitmap.smoothing` — open follow-up, not a NO-GO.**
  `draw_bitmap_quad_scaled` now asks for Nearest *explicitly* via
  `render_webgpu_bitmap_fill_style_word(0, 0)`. When someone wires AS3
  `Bitmap.smoothing` / AS2 `attachBitmap(..., smoothing)` through, that call
  site is the one line to change; the sampler machinery is already there.

## 6. Reproduction

```bash
WT=/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a7b703478aecc633f
cd $WT
git apply SWFRecompDocs/plans/session16-fanout-reports/w2-gfx-vram-clamp.patch
git apply SWFRecompDocs/plans/session16-fanout-reports/w2-gfx-vram-smooth.patch
export DAWN_INSTALL=$HOME/CC/dawn-install SWFRECOMP_COMPILE_TIMEOUT=2400
python3 ruffle-tests/render_canary.py capture --label after \
        --tests <scratch>/w2vram/full_list.txt -P 2 --force --timeout 2400
python3 ruffle-tests/render_canary.py compare before after
```

Style-byte census (no runtime build needed, ~1 s/test):

```bash
grep -ohE ", 0x4[0-3], " <test>/RecompiledTags/*.c | sort | uniq -c
```
