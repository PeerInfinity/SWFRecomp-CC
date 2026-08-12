# wave1-gfx-bitmapfill — bitmap-fill "U-pinning": mechanism found, brief label refuted

**Session 14, wave 1, PIXEL axis. Read-only diagnosis.**
Baseline: CI run `31130292354` at `fb36ba110` (graphics / full / images=true),
results merged at `e62ab7471`; failing PNGs on `origin/ruffle-image-results`
(`ff5502cb8`). Repo HEAD during this work: `0a99be1a9`. No source edited, no
commits, no stash.

---

## 0. Headline (five lines)

1. **The mechanism is real, the label is wrong.** It is not U-pinning and not a
   clamp-vs-repeat sampler bug: **the repeating-bitmap-fill tile period is the
   *padded texture-array-layer* size, not the bitmap's own size** — both axes,
   `render_webgpu.c:142` (`let actual = padded - vec2f(1.0);`).
2. **The padding is inflated by the test's own golden PNG.** `verify_output.py`
   bundles `output.expected.png` as a loadable data file; `getDataFilesMaxImageDims`
   reports 800×600; that raises `dynamic_bitmap_max_{w,h}`; that raises the shared
   layer to 801×601 — so a 512×512 Lena tiles every 800×600 texels with transparent
   gaps. Verified in the running binary with gdb (`ctx->bitmap_highest_w == 800`).
3. **`acid-bitmap-fill` FLIPS.** Local render is **byte-identical to the CI actual**
   (md5 `aa61028d…`) ⇒ local grading is CI-grade here. A zero-source-edit emulation
   of the fix passes: `100 361 excess → 0` (tol 12: 67 937/70 000; tol 128: 297/300).
4. **`acid-bitmap-draw_quality_{high,low}` is a different defect and must be split
   out** (confirms wave1-board-audit §6.1): flat-white `blank_render`, AVM2;
   `bd_draw` and `doc_add_child` both run, but `render_webgpu_draw_bitmap_quad_scaled`
   is **never called**. Same SWF for both halves; `_low` is `known_failure`.
5. **Blast radius is one comparison.** A full-corpus SWF scan (4 478 SWFs, incl. all
   62 LZMA ones) finds exactly **two** movies with a repeating bitmap fill:
   `acid-bitmap-fill` (graded, fails) and `from_gnash/misc-ming.all/BitmapDataDraw`
   (no `image_comparisons`, ungraded). Everything else is clipped-only and provably
   unchanged by the proposed patch.

**GO** — small, provable, +1 flip with a measured (thin) margin.

---

## 1. What the pictures actually show

### 1.1 `from_shumway/acid/acid-bitmap-fill` — `diffuse_mixed`, 100 361 excess, 800×600

Eight panels, each a shape filled with the same 512×512 JPEG (DefineBits id 1)
under a different fill matrix. Overall ink bounding boxes are **identical** to the
golden (row runs `31-172 / 195-336 / 362-566`, col runs `23-182 / 221-573` in both) —
so this is **not** wholesale misplacement and **not** a geometry defect.

Inside the tiled panels the content is drawn at the **right size** but with
**transparent gaps** on a **larger pitch**:

```
panel row2/col1 (inv_mat 5, scale 2.4253 × 1.6631), exact-background mask runs:
  columns: content @27 len 62,  gap 35, content @124 …   → period 97 px, duty 0.639
  rows:    content     len 43,  gap  7,  …               → period 50 px, duty 0.860
```

Converting through the fill matrix (px per bitmap texel = scale/20):

| quantity | measured px | texels | predicted by |
|---|---:|---:|---|
| content width | 62 | **512** | the bitmap's real width ✓ |
| content height | 43 | **512** | the bitmap's real height ✓ |
| tile period X | 97 | **800** | padded layer width − 1 |
| tile period Y | 50 | **600** | padded layer height − 1 |

The golden's own periods (autocorrelation) are **62 × 43** — i.e. exactly the
content size, exactly what Ruffle produces. So: *content correct, period wrong.*

A rotated panel (inv_mat 2) shows the same defect as diagonal blank bands, and the
two panels whose matrices scale the bitmap to ≥ the panel size (inv_mat 0/3/4, and
the one `0x41` clipped fill) render correctly — they never reach a wrap.

### 1.2 `acid-bitmap-draw_quality_high` / `_low` — NOT this mechanism

`output.actual.png` is **one colour** (65 536/65 536 px pure white); the golden has
985 colours and 70.9 % ink. Both halves are the **same SWF** (md5
`b03d9b4baa13…`) and produce the **same actual** (md5 `8fd01bb0…`) — the only
difference is `test.toml` quality. Fixing a sampling period cannot flip a flat
frame. Diagnosed separately in §6.

---

## 2. Root cause, exactly

### 2.1 The shader tiles on the padded layer

`SWFModernRuntime/src/rendering/render_webgpu.c`

* **vertex**, lines 138–143:
  ```wgsl
  } else if ((out.v_style_type & 0xF0u) == 0x40u) {
    let inv_pos = inv_mats[style_upper] * pos;      // → BITMAP TEXELS
    let sizes = bitmap_sizes[out.v_style_id];
    let padded = vec2f(f32(sizes.x), f32(sizes.y)); // layer dims, NOT bitmap dims
    let actual = padded - vec2f(1.0);               // ← the bug
    out.v_args = vec4f(inv_pos.x / padded.x, inv_pos.y / padded.y,
                       actual.x / padded.x, actual.y / padded.y);
  ```
* **fragment**, lines 264–268:
  ```wgsl
  } else if (in.v_style_type == 0x40u || in.v_style_type == 0x42u) {
    let bm_ratio = max(in.v_args.zw, vec2f(0.001));
    color = textureSampleLevel(bitmap_tex, bitmap_samp,
              fract(in.v_args.xy / bm_ratio) * bm_ratio, i32(in.v_style_id), 0.0);
  ```
  ⇒ repeat period = `padded − 1` **texels**.

`actual = padded − 1` is only correct under the *assumption* that every layer is
exactly one bitmap plus one edge-clamp column — which `render_webgpu_upload_bitmap`
(lines 2895–2938) guarantees **only when the bitmap is the largest thing in the
texture array**. All layers share one size (`WGPUExtent3D{bw, bh, layers}`,
line 1235); a smaller bitmap is written into `[0..width] × [0..height]` and the rest
of the layer is left `calloc`'d **transparent** (line 2903–2919), while
`bitmap_sizes` deliberately records the **padded** dims (lines 2932–2936, with a
comment saying so).

So: **any movie whose repeating-fill bitmap is smaller than the array-layer padding
tiles with transparent gaps of (padded − 1 − bitmap) texels per axis.**

### 2.2 Why the padding is 801 × 601 for a 512 × 512 bitmap

`RecompiledTags/constants.h` says `BITMAP_HIGHEST_W/H = 512`, but gdb on the live
binary at `render_webgpu_upload_bitmap` (args `width=512 height=512`) reads
`ctx->bitmap_highest_w = 800`, `ctx->bitmap_highest_h = 600`:

```
(gdb) x/8dg $rdi     # ctx
0x…980:  width|height = 800|600     stage_scale = 1.0f
0x…990:  stage_to_ndc ptr           bitmap_count = 1
0x…9a0:  bitmap_highest_w = 800     bitmap_highest_h = 600
```

Chain (all lines in the main tree):

1. `ruffle-tests/verify_output.py::find_data_files` (line 1871) bundles **every**
   sibling file that is not in `skip_names`/`skip_suffixes` — and `.png` is in
   neither, so **`output.expected.png` becomes a runtime data file**.
2. `generate_data_registry` (line 1912, image detection at line 1958) puts it in
   `g_data_image_files`, so `getDataFilesMaxImageDims` `stbi_info`s the **golden**
   and returns **800×600** (confirmed in the generated
   `build/data_registry.c`: `{ "output.expected.png", …, 400049 }`).
3. `SWFModernRuntime/src/libswf/swf.c:1644-1652` raises
   `ctx->dynamic_bitmap_max_{w,h}` to 800×600.
4. `render_webgpu.c:1219-1230` sizes the array layer to
   `max(bitmap_highest+1, dynamic_bitmap_max+1)` = **801×601** and *writes that back*
   into `ctx->bitmap_highest_{w,h}`.
5. `render_webgpu_upload_bitmap` stores `bitmap_sizes = {801, 601}` ⇒ period 800×600.

**The golden image is contaminating the render it is used to grade.** It also
inflates VRAM everywhere: `(bitmap_count + 64)` layers × `801×601×4 B` ≈ 125 MB for
this test instead of ≈ 68 MB, and proportionally worse for tests with 900×900
goldens.

### 2.3 Two smaller divergences found alongside (NOT scoped here)

* **Non-smoothed fills use the wrong filter.** One sampler for all bitmaps,
  `magFilter = minFilter = Nearest` (line 1252). Ruffle picks per fill:
  `get_sampler(is_repeating, is_smoothed)` (`render/wgpu/src/bitmaps.rs:151`) →
  linear for `0x40/0x41`, nearest for `0x42/0x43`. We are nearest for **all** four.
* **Clipped fills stop clamping after one texel.** `0x41/0x43` rely on hardware
  `ClampToEdge` at the *layer* edge, but the layer only carries a `+1` edge-clamp
  column; beyond that the padding is transparent, where Flash/Ruffle clamp the
  bitmap's edge pixels forever. Only visible when a clipped fill's shape overruns
  its bitmap by more than one texel.

Both are separate, riskier items. See §5.4.

---

## 3. Ruffle comparison (`~/CC/ruffle`)

| | Ruffle | us |
|---|---|---|
| texture | one `texture_2d` **per bitmap** (`render/wgpu/src/mesh.rs:188`) | one shared `texture_2d_array`, all layers padded to the largest |
| UV | `swf_bitmap_to_gl_matrix` (`render/src/tessellator.rs:356-383`) normalises the inverted fill matrix by **the bitmap's own** `bitmap_width/height` (`a *= 20.0/bitmap_width`, `c /= bitmap_width`) | `inv_pos / padded_layer` |
| repeat | hardware `AddressMode::Repeat` (`bitmaps.rs:51-59`) | manual `fract()` with a **padded** period |
| clamp | hardware `AddressMode::ClampToEdge` (`bitmaps.rs:65-73`) | `ClampToEdge` on a mostly-transparent padded layer |
| filter | `repeat_linear` / `repeat_nearest` / `clamp_linear` / `clamp_nearest` chosen by `is_smoothed` | always `Nearest` |

**Precise divergence:** `render_webgpu.c:142` (`actual = padded - 1`) +
`render_webgpu.c:2932-2936` (`bitmap_sizes` stores padded, not content). Ruffle's
equivalent quantity is unambiguously the bitmap's own size.

---

## 4. Measured proof of the fix (CI-grade, zero source edits)

**CI-fidelity check first.** Local `--mode=graphics` render of
`from_shumway/acid/acid-bitmap-fill` is **byte-identical** to the published CI
actual:

```
aa61028d9af1dff2f78be9e1442eeb77  local build/output.png
aa61028d9af1dff2f78be9e1442eeb77  ruffle-image-results/…/acid-bitmap-fill/output.actual.png
```

⇒ per the standing rule, local grading is CI-grade **for this test**.

**Emulation of the fix without touching any source:** copy the test dir minus
`output.expected.png` (so nothing inflates `dynamic_bitmap_max`; the layer becomes
513×513 and `padded − 1 = 512` = the true bitmap size — i.e. *exactly* what the
proposed patch computes, and bit-identical to it because the sampler is `Nearest`,
so the fetched texel is `floor(fract(inv/512)·512)` either way).

Graded with `verify_output.compare_images` and the real `test.toml` ladder:

| leg | verdict | tol 12 (≤70 000) | tol 32 (≤20 000) | tol 64 (≤6 000) | tol 128 (≤300) | excess |
|---|---|---:|---:|---:|---:|---:|
| BEFORE (reproduces CI exactly) | FAIL | — | — | — | 100 661 | **100 361** |
| AFTER (period = bitmap size) | **PASS** | **67 937** ✓ | 21 428 | 6 261 | **297** ✓ | **0** |

Two of the four checks pass and the ladder is "any check passes", so the flip is
real — but **both passing margins are thin (3 % and 1 %)**. Report it as a flip with
a named risk, not as a comfortable one. Mitigation if it lands short on CI: §5.4's
smoothed-fill linear sampler is the obvious headroom lever (Ruffle uses linear here;
we point-sample an 8× minification).

---

## 5. Implementation-ready plan

### 5.1 Data-model change (`bitmap_sizes` → 4 u32 per layer)

Store **content** dims *and* **padded** dims per layer:
`{content_w, content_h, padded_w, padded_h}`.

| file | line(s) | edit |
|---|---|---|
| `SWFModernRuntime/src/rendering/render_webgpu.c` | 812 | `HALLOC(4 * sizeof(u32) * ctx->bitmap_count)` |
| " | 1102-1104 | `bitmap_sizes_buffer` size → `4 * sizeof(u32) * total_bmp_slots` |
| " | 2932-2936 | static path: store `{width, height, bw, bh}` (was `{bw, bh}`) |
| " | 2946-2948 | `finalize_bitmaps` upload size → `4 * sizeof(u32) * bitmap_count` |
| " | 2405-2409 | `draw_bitmap_quad_scaled`: store `{src_w, src_h, bw, bh}` |
| " | 2544-2547 | `draw_bitmap_tris`: store **`{bw-1, bh-1, bw, bh}`** — this path *pre-tiles* the whole layer, so `bw-1` keeps it byte-identical (see §5.3) |
| `SWFModernRuntime/include/rendering/render_webgpu.h` | 30 (`u32* bitmap_sizes`) | comment: 4 u32 per layer |

`bitmap_sizes` is declared `array<vec2u>` in WGSL (line 96) → change to
`array<vec4u>` (std430 stride 16 B, matches the C layout).

### 5.2 Shader change — formulated so **non-repeating fills are bit-identical**

Vertex (replaces lines 139-143):

```wgsl
  } else if ((out.v_style_type & 0xF0u) == 0x40u) {
    let inv_pos = inv_mats[style_upper] * pos;
    let s = bitmap_sizes[out.v_style_id];
    let content = vec2f(f32(s.x), f32(s.y));   // the bitmap's OWN texels
    let padded  = vec2f(f32(s.z), f32(s.w));   // the shared layer's texels
    if ((out.v_style_type & 0x1u) == 0u) {     // 0x40 / 0x42 — repeating
      out.v_args = vec4f(inv_pos.xy / content, content / padded);
    } else {                                   // 0x41 / 0x43 — clipped
      out.v_args = vec4f(inv_pos.x / padded.x, inv_pos.y / padded.y, 1.0, 1.0);
    }
```

Fragment (replaces lines 264-268):

```wgsl
  } else if (in.v_style_type == 0x40u || in.v_style_type == 0x42u) {
    color = textureSampleLevel(bitmap_tex, bitmap_samp,
              fract(in.v_args.xy) * in.v_args.zw, i32(in.v_style_id), 0.0);
  } else if (in.v_style_type == 0x41u || in.v_style_type == 0x43u) {
    color = textureSampleLevel(bitmap_tex, bitmap_samp,
              in.v_args.xy, i32(in.v_style_id), 0.0);      // UNCHANGED expression
```

Why the branch (rather than the algebraically-equivalent `v_args.xy * v_args.zw`
for the clipped case): `(inv/c)·(c/p)` is not bit-identical to `inv/p`, and under
`Nearest` a 1-ULP wobble can flip `floor()` on an exact texel boundary. Keeping the
clipped arm's arithmetic character-for-character identical makes the patch
**provably a no-op for every non-repeating bitmap fill in the corpus**.

No bind-group change is needed: `bitmap_sizes` is read only in the vertex stage
(`bg0_entries[0..3].visibility = WGPUShaderStage_Vertex`, line 1307) and stays that
way.

**MSAA invariant:** no pipeline descriptor is touched; `MSAA_SAMPLES` is untouched.

### 5.3 Why `draw_bitmap_tris` gets `{bw-1, bh-1, …}`

`render_webgpu_draw_bitmap_tris` (line 2493, the AVM1/AVM2 `beginBitmapFill` path)
already **pre-tiles** the source across the whole padded layer (`sx = x % src_w`,
lines 2517-2527) and relies on the current `padded − 1` period. Setting its content
to `{bw-1, bh-1}` reproduces today's period exactly ⇒ byte-identical output for
`avm2/graphics_bitmap_fill`, `avm2/graphics_bitmaps`,
`from_gnash/misc-ming.all/BeginBitmapFill`, etc.

*Optional follow-up (do NOT bundle):* stop pre-tiling, upload only `src_w × src_h`,
set content `{src_w, src_h}`. That removes the wrap seam every `bw-1` texels and
cuts the per-draw upload from `801×601` to `src²`, but it also requires the clipped
arm to clamp to `content` (§2.3), so it is a second patch with its own A/B.

### 5.4 Deliberately out of scope

* **Smoothed → linear sampler.** Correct per Ruffle, but it needs a second sampler
  + a second bind group (or a `select` on two samplers) and would move *every*
  bitmap draw in the corpus. Keep as the named headroom lever if `acid-bitmap-fill`
  lands short on CI.
* **Clipped-fill clamp beyond +1 texel.** Real divergence, no graded victim found.
* **Harness hygiene** (`verify_output.py::find_data_files`): exclude
  `*.expected.png` from the data registry — or at least from `g_data_image_files`.
  It is the *upstream* cause here and it inflates VRAM for the whole corpus, but it
  is **not** a substitute for the renderer fix (a real SWF with two differently
  sized bitmaps is still broken), and shipping it alone would be "fixing the harness
  to pass the test". Under `Nearest` sampling it provably changes nothing else
  (clipped UV = `inv/padded` on a `padded`-wide texture ⇒ `floor(inv)`, padding-
  independent). Ship it as a separate hygiene commit if wanted.

---

## 6. `acid-bitmap-draw_quality_*` — refuted as this cluster, re-owned

Confirms and extends `wave1-board-audit.md` §6.1.

* Both halves are the **same SWF**; `_low` is upstream `known_failure` ⇒ **max +1
  flip from the pair, not +2**.
* Actual is flat white (1 colour / 65 536 px). Local render is **byte-identical to
  CI** (`8fd01bb0…`) ⇒ locally diagnosable at CI fidelity.
* ABC string pool: `BitmapData` · `flash.geom:Matrix` · `translate` · `draw` ·
  `Bitmap` · `addChild`. AVM2, no embedded bitmap characters.
* gdb on the live binary:
  * `bd_draw` **is** called, and recurses into `bd_draw_shape_walk` (twice) ⇒
    `BitmapData.draw` runs.
  * `doc_add_child` **is** called once ⇒ the `Bitmap` is added.
  * `render_webgpu_draw_bitmap_quad_scaled` is **never called** ⇒ nothing is blitted.
* ⇒ The failure is **downstream of `BitmapData.draw`, inside AVM2 Bitmap display**.
  Two candidate gates in `avm2_render_bitmap` (`avm2_display.c:14713-14728`):
  `ext->bitmap_data == NULL` (Bitmap ctor not storing its `bitmapData` argument on
  this construction path) or the size gate
  `bd->width > context->dynamic_bitmap_max_w` — note this SWF has **no** embedded
  bitmaps, so `bitmap_highest = 0` and `dynamic_bitmap_max = max(stage, 256) = 256`
  (`avm2_display.c:15745-15751`); a `BitmapData` wider than 256 is silently
  dropped. Next step is one `printf` in that function — cheap.
* **Price it as its own lead: +1 max, MED effort, `blank_render` cluster.**

`from_shumway/acid/acid-bitmapData-copyPixels` (53 760, board-audit's proposed
"missing fourth member") is **also not this lane**: our render paints one extra
solid red ≈128×128 block plus two displaced 16×16 blocks inside the diff bbox
`x 32-255 / y 32-255`. That is a `copyPixels` sourceRect/destPoint clipping defect
(a copy that should be clipped to a small rect covering a large region), reached
through the `0x41` quad path, which the patch above leaves bit-identical. Separate
owner.

---

## 7. Sibling sweep — the blast radius is one comparison

Method: a SHAPE-record fill-style parser over **every** `test.swf` in
`ruffle-tests/tests/swfs` (4 478 SWFs; all 62 LZMA-compressed ones decoded on a
second pass; **0 parse errors**), extracting fill types `0x40-0x43`, cross-referenced
against `ruffle-image-results/index.json`.

**Movies with a repeating bitmap fill (`0x40`/`0x42`) — 2 in the whole corpus:**

| test | fills | image status |
|---|---|---|
| `from_shumway/acid/acid-bitmap-fill` | `0x40` × 1 (char 1) | **FAIL, 100 361 excess, `d_moderate`** |
| `from_gnash/misc-ming.all/BitmapDataDraw` | `0x40` × 1 (char 8) | **no `image_comparisons` in `test.toml`, no golden ⇒ ungraded** |

**Movies with clipped-only bitmap fills (`0x41`/`0x43`) — 16**, all provably
untouched by §5.2 (identical arithmetic): `avm1/click_block`, `avm2/click_block`,
`avm1/issue_2084`, `avm1/netstream_play_flv_screen`, `avm2/pixelbender_dithering`,
`from_gnash/misc-swfmill.all/missing_bitmap`, `from_gnash/misc-ming.all/{VarAndCharClashTest,loading/loadMovieTest}`,
`from_shumway/{bitmapbuttons,avm1/mouse-transparency}`,
`from_shumway/acid/{acid-bitmap-fill-2,acid-blend,acid-blend-2,acid-large,acid-color-0}`,
`_swfbridge/livetest/n_loader/native_run`.

Note in particular that `acid-blend-2 output.15/26` — which board-audit §6.1 hoped
would get "route-A relief" from this fix — uses `0x43` **clipped** fills only. This
patch **cannot** move them. That expectation is refuted.

**Dispositions checked:** no `ACCEPTED_DIFFS` / `RUFFLE_VS_FLASH_DIFFERENCES` /
`ignored_tests.txt` entry (hard or soft) covers `acid-bitmap-fill`,
`acid-bitmap-draw_quality_*` or `acid-bitmapData-copyPixels`.

---

## 8. Expected-flip ledger, canaries, verification

**Ledger (one line):**

| comparison | before | expected after |
|---|---:|---|
| `from_shumway/acid/acid-bitmap-fill [output]` | fail, 100 361 excess (`d_moderate`) | **PASS** (measured locally at CI fidelity; margins 67 937/70 000 and 297/300) |

Everything else: **byte-identical**. A DIFFERS anywhere else is a bug in the patch,
not a rider.

**md5 canary (`ruffle-tests/render_canary.py`):**

```bash
python3 ruffle-tests/render_canary.py capture --label before   # BEFORE the patch
# … apply patch, cmake/rebuild …
python3 ruffle-tests/render_canary.py capture --label after
python3 ruffle-tests/render_canary.py compare before after     # expect 37/37 IDENTICAL
```

The standing set (`render_canary_tests.txt`, 20 tests / 37 comparisons) already
covers the bitmap quad path via `avm1/bitmap_data_fillrect`. **Add these bitmap-fill
tests for this patch** (all must be IDENTICAL; only `acid-bitmap-fill` may DIFFER):

```
from_shumway/acid/acid-bitmap-fill       # the ONLY permitted DIFFERS
from_shumway/acid/acid-bitmap-fill-2     # 0x41 clipped, currently PASSING — top regression risk
from_shumway/acid/acid-color-0           # 0x41 clipped
from_shumway/acid/acid-blend-2           # 0x43 clipped, a_epsilon — 1 channel from passing
from_shumway/bitmapbuttons               # 0x43 clipped ×9
avm2/graphics_bitmap_fill                # beginBitmapFill → draw_bitmap_tris
avm2/graphics_bitmaps                    # beginBitmapFill → draw_bitmap_tris
from_gnash/misc-ming.all/BeginBitmapFill # beginBitmapFill, b_tiny — 794 excess
avm2/bitmapdata_draw                     # quad path
avm1/bitmap_data_copypixels              # quad path
avm2/bitmap_pixelsnapping                # quad path
```

**Trace canaries:** the patch is renderer-only (WGSL + `bitmap_sizes` plumbing) and
cannot reach the AVM; trace diffs ride along in every `render_canary.py` capture, so
a clean canary run is also the trace check. Belt-and-braces, run the stash-diff
sweep on `from_shumway/acid/*` + `regression` if the implementer touches anything
outside `render_webgpu.c`.

**Files a wave-2 implementer edits:**

1. `SWFModernRuntime/src/rendering/render_webgpu.c` — WGSL (96, 139-143, 264-268)
   + `bitmap_sizes` sizing/writes (812, 1102-1104, 2405-2409, 2544-2547,
   2932-2936, 2946-2948).
2. `SWFModernRuntime/include/rendering/render_webgpu.h` — comment on
   `u32* bitmap_sizes` (4 u32/layer).
3. *(optional, separate commit)* `ruffle-tests/verify_output.py` —
   `find_data_files` / `generate_data_registry`: keep `*.expected.png` out of
   `g_data_image_files`.

Do **not** edit `SWFRecomp/build_wasm_avm2/**/render_webgpu.c` or
`SWFRecomp/build_graphics_host/render_webgpu.c` — those are build-artifact copies.
`SWFModernRuntime/src/flashbang/flashbang.c` (legacy SDL_GPU backend) carries the
same `bitmap_highest + 1` padding model and would need the same treatment if it is
ever revived; it is not on the graded path.

**Rebuild note:** this is runtime-only, so a worktree may copy `SWFRecomp/build`
from the main tree; test-dir copies still need `--recompile` on first use.

---

## 9. Provenance / reproduction

* Image results: `git archive origin/ruffle-image-results` @ `ff5502cb8` (force-pushed
  = exactly run `31130292354`). Goldens read from the gitignored test dirs.
* Local runs: `python3 ruffle-tests/verify_output.py --tests-dir=<scratch copy>
  --test=acid/acid-bitmap-fill --mode=graphics --images --recompile`, scratch copies
  under `…/scratchpad/gfx-bitmapfill/tests{,2,3}`, build dirs preserved with
  `SWF_KEEP_BUILD_DIR` (the offscreen build always writes `output.png` there).
* gdb probes were **read-only** (`break` + register/memory reads on an unmodified
  binary). No probe edits were made anywhere.
