# s27 w1-drift: upstream drift `3e98d9ba6..1e604fa87`

**New files:** `w1-drift-report.md` (this file), `w1-drift-prototype.patch` (1 file, 1 line of code + comment).

Upstream at download: **`1e604fa87`** (re-checked at the end of the session: still no newer commits). Downloaded:
`avm2 from_shumway avm1 visual timeline swf mixed_avm import_assets from_gnash text fonts audio stage3d`.
Base `origin/master` `c40b6560` (docs-only past `ae7f50cb`; contains wave-0 `d70f2c0aa`). Baseline results: still
**`df7729df2`**. Wave-0's run had not published when I started or when I finished.

## Verdicts (lead)

| Row | Verdict | Before → after | Notes |
|---|---|---|---|
| `avm2/pixelbender_dithering` (image, Flash golden) | **GO, landable prototype** | **34301 → 9413** outliers (limit 32500) = fail → **pass** (+1 pixel row) | 1-line change in `avm2_cpu_raster.c::bmp_sample`. Sweep-clean (below). |
| `from_shumway/.../bitmapdata-clone` (image, Flash golden) | pass, no action | 0 outliers @ tol 77, max_diff **77**: zero headroom | Quality-invariant (low/high md5-identical). |
| `avm2/allow_networking` (trace) | pass, no action | expected lines **72 → 75**, still pass | `none`-mode SecurityError (`50f28249e`) is ungradeable here: **NO-GO** (completion mechanism below). |
| JPEG high-quality re-render `d87764213` | **no row moves** | — | Only touches the two rows above (quality `low → high`). Both are md5-invariant across quality. No limit changed in that commit. |
| `3bbda49f5`, `cbd7e19b6`, `0c7a84f61`, `1e604fa87` | **no riders** | — | All four are pure refactors with identical semantics (details below). |

**Next-CI pre-labels from drift alone** (for reading the interim run against `df7729df2`):
- `avm2/allow_networking`: trace `expected_lines` 72 → 75 (`matching` 75), status stays `pass`. This is the only drift
  move. CI's `df7729df2` download predates `bc2d4aedc`, so its expected file was the 72-line one.
- **No pixel move from drift.** `df7729df2` already graded both Flash goldens:
  - `pixelbender_dithering`: limit 32500 / tol 1, 34301 outliers.
  - `bitmapdata-clone`: tol 77, max_diff 77.
  So `5128d3943` and `7facc1fcc` are already in the baseline. `d87764213` (quality) cannot move either row: my
  `pixelbender_dithering` render at quality=high is byte-identical to CI's actual PNG (md5 `22e81119…`), and
  `bitmapdata-clone` renders md5-identical (`668f2b39…`) at low and high.
- No denominator change: no test was added or removed upstream. `allow_networking` only gained a subtest block.
- If my prototype lands: `pixelbender_dithering` pixel fail → pass (+1, 593 → 594 on the `df7729df2` read).

## 1. `pixelbender_dithering`: mechanism and prototype

**Fidelity proof.** My local before-render is byte-identical to CI's `ruffle-image-results` actual
(`22e8111985e028f2f73fe558cd5cba23`), so local grading is CI-grade for this row.

**Pipeline.**
- The SWF holds one DefineBitsJPEG3: 900×600, 4:2:0.
- One DefineShape fills it with a **non-smoothed clipped bitmap (0x43)**. Matrix: x scale 1.42222, **y scale exactly
  1.5**, ty = −80. The scene is 1280×900.
- `BitmapData.draw(mcScene)` goes through the **CPU rasterizer** (`avm2_cpu_raster_shape`, the s26 `1aef9cc7b` bitmap-fill
  arm), not the GPU shader. I confirmed this first by editing the WGSL: no effect.
- A ShaderFilter then applies a 4×4 ordered dither. The thresholds I recovered from our own output: `v ≥ 40 + 16·k`
  → 255.

**Region diagnosis.** The diff is diffuse over the whole picture: no edge band, and alpha is never involved. The
mismatch distance |input − threshold| is broad, with many flips 20–100 levels from the threshold. That points to
geometry (the wrong source row), not colour rounding. A row-wise check confirms it:
- Our dumped shader input differs from an exact nearest-neighbour resample of the decoded JPEG on **222 of 720 rows,
  exactly every third row**. Those are the rows where the pixel centre maps exactly onto a texel boundary
  ((y + 80.5)/1.5 is an integer).
- `bmp_sample` deliberately resolves those ties **downward** (`floor(v − 1e-6)`). s26 chose that against the old
  **Ruffle** golden (8614 vs 20153: Ruffle's GPU nearest sampler rounds these ties down).
- **Flash resolves them upward** (plain floor of the exact coordinate).

Python model, stb decode + nearest, dithered and graded against the Flash PNG:

| model | outliers |
|---|---|
| ties-down (= ours today, reproduces our actual exactly) | 34299 |
| exact floor / ties-up | **9412** |
| offset scan, x ∈ {0.4, 0.5, 0.6}, y ∈ [0.30, 0.75] | best 9412 at x = 0.5 (any y in [0.5, 0.75]); next best 13629 |

Measured in the real build (graphics, CI-grade):

| `bmp_sample` nearest | outliers |
|---|---|
| `floor(u − 1e-6)` (today) | 34301 |
| `floor(u)` exact | 9416 |
| **`floor(u + 1e-6)` (prototype)** | **9413** |

**Residual 9413.** This is JPEG decode noise near the dither thresholds. With libjpeg-turbo (PIL) decoding the same
model scores 9036, so a closer-to-Flash decoder would buy about 4%. It is not needed: the row passes with 3.5×
headroom.

**Prototype** (`w1-drift-prototype.patch`): `SWFModernRuntime/src/avm2/avm2_cpu_raster.c::bmp_sample`, nearest arm only.
- `floor(u - 1e-6), floor(v - 1e-6)` → `floor(u + 1e-6), floor(v + 1e-6)`.
- The comment is rewritten with the Flash-golden numbers.
- The smoothed (bilinear) arm and the GPU path are untouched. Touches no `action.c` / `tag.c` / `swf.c` / `ng_shared.c`
  function.

**Reach (static proof).** `bmp_sample` runs only on bitmap fills of timeline shapes in `avm2_cpu_raster_shape`. Its
callers are:
- AVM2 `BitmapData.draw` (`avm2_bitmap.c`);
- AVM1 draw (`action.c`);
- `avm2_cpu_walk`, used only for the blendShader backdrop and the `AVM2_CPU_DUMP` debug dump.

`avm2_cpu_raster_tris` (dynamic `beginBitmapFill`) sets `R.bmp = NULL`, so it never reaches the change.

I scanned every downloaded SWF for DefineShape1–4 fill styles 0x42/0x43. That covers avm1, avm2, from_shumway, from_gnash,
visual, timeline, swf, mixed_avm, import_assets, text, fonts, audio, stage3d and regression. from_avmplus was skipped:
it is ABC-only, with no DefineShape. **Exactly 10 SWFs** have such a fill:
- **With `draw` and an image:** `avm2/pixelbender_dithering`, `avm1/netstream_play_flv_screen`.
- **No `draw`, with an image:** `from_shumway/acid/acid-blend`, `acid-blend-2`, `bitmapbuttons`;
  `regression/avm1_jpeg3_alpha_bitmap`, `avm1_parent_child_bitmap_fill`, `bitmap_pool_layer_cap`.
- **No `draw`, no image:** `avm1/click_block`, `from_shumway/avm1/mouse-transparency`. Trace-only, so pixels can't
  move them.

None of the 10 contains `blendShader`.

**Sweep (graphics, A/B md5 of every actual PNG; both legs on this box).** The only change is the target. 14 of 15 rows
are md5-identical before and after:

| row | status (both legs) | md5 |
|---|---|---|
| `avm2/pixelbender_dithering` | **FAIL 34301 → PASS 9413** | `22e81119…` → `2a3abab2…` |
| `avm1/netstream_play_flv_screen` | PASS 0 | = |
| `from_shumway/acid/acid-blend` | PASS 5/348 | = |
| `from_shumway/acid/acid-blend-2` (5 imgs) | PASS | = (all 5) |
| `from_shumway/bitmapbuttons` | FAIL 52 (= baseline) | = |
| `regression/avm1_jpeg3_alpha_bitmap` | PASS | = |
| `regression/avm1_parent_child_bitmap_fill` | PASS | = |
| `regression/bitmap_pool_layer_cap` | PASS | = |
| `regression/avm2_bitmapdata_draw_textfield` | PASS (trace) | — |
| `avm2/bitmapdata_draw` | FAIL 753/600 (= baseline) | = |
| `avm2/pixelbender_images` | PASS | = |
| `avm2/pixelbender_effect_twirl` | PASS | = |
| `from_shumway/.../bitmapdata-clone` | PASS (max 77) | = |
| `from_shumway/acid/acid-bitmap-draw_quality_high` | PASS | = |
| `from_shumway/acid/acid-bitmapData-draw` | PASS | = |

**No-graphics leg** (after): `pixelbender_dithering` and `netstream_play_flv_screen` traces both PASS. The change is
pixel-only, and no-graphics does not grade images.

**CI mode for landing:** graphics/`all` covers it. The file is shared AVM2 runtime code, but the change can only alter
pixels.

**Refuted premise.** s26's ties-to-lower was "measured" against a Ruffle-made golden. It is exactly the
Flash-vs-Ruffle trap: Ruffle's limit of 32500 sits just above Ruffle's own score with the same tie rule. Our prototype
beats Ruffle against Flash by about 3.5×.

## 2. `bitmapdata-clone` (`7facc1fcc` + `d87764213`)

- **Before and after: PASS**, 0 outliers at tol 77, max_diff **77**. Against the old Ruffle golden our max is 3, so our
  JPEG decode is Ruffle-like. Upstream measured Ruffle at "up to 77 levels" from Flash, and we sit exactly on the
  tolerance.
- **Risk:** any JPEG-decode change that pushes one logo channel past 77 flips this row to fail. It is quality-invariant
  (md5-identical at low and high), so `d87764213` moves nothing.
- **Lead (not priced):** decoder fidelity to Flash (IJG ISLOW + fancy upsampling vs stb). On the dithering JPEG,
  libjpeg-turbo is about 4% closer to Flash than stb. I did not get a clean 1:1 logo placement to measure the clone
  logo region directly; my alpha-composited fit failed.

## 3. `allow_networking` (`bc2d4aedc` / `50f28249e`)

- The harness grades the **first** subtest, `all` (`resolve_expected_filename`; the variants carry no version). Our
  output matches the new 75-line `output.all.txt`: **PASS**.
- `50f28249e` makes `SharedObject.getLocal` throw `SecurityError #2146` when `allowNetworking == none`. Ruffle's
  `output.none.txt` is Flash's output; `none` is `known_failure` in Ruffle only because of the SWF URL.
- **NO-GO for a prototype:** the runtime has no allowNetworking mode, and `verify_output.py` never runs the `none`
  subtest, so any implementation would be unmeasurable.
- **Completion mechanism:** harness support for running each `[subtests.X].player_options.allow_networking` variant as
  its own graded row, plus a runtime flag (compile define). Then gate `SharedObject.getLocal` and the other
  Navigator/Socket/LocalConnection checks the test exercises on `none`. The error text already exists in
  `avm2_error.c:1094`. Scope is M, for 2 rows (`allow_networking`, `local_connection_allow_networking`) whose `none`
  variants are currently invisible.

## 4. Behaviour-only commits

- **`3bbda49f5`** (AVM1 `parse_level_id`): `match digits.get(0) { Some(45) => … }` → `strip_prefix(b'-')`. 45 is
  `'-'`, so it is **semantically identical**. `_level-1` → −1 (no such level → undefined), and `_level+1` → 0 (`'+'`
  stops parsing, level 0), both before and after. Ours (`action.c` path resolver, the `parse_level` arm near line
  22892) matches: optional `'-'`, then digits, stopping at the first non-digit. The only divergence is digit-string
  overflow: Ruffle wraps, while our `int` accumulate is signed-overflow UB. No corpus row exercises it, so it is not
  worth a change.
- **`cbd7e19b6`** (AVM2 rollOut/rollOver): pure extraction into `dispatch_roll_events`. Order is unchanged: mouseOut,
  then LCA, then rollOut chain; rollOver chain, then mouseOver. No rider.
- **`0c7a84f61`** (escaped HTML push): removes a UTF-8 re-validation that cannot fail. No behaviour change.
- **`1e604fa87`** (shape path/style zip): `get_unchecked(i)` → `zip`. Same pairs, same order. It re-states "paths
  drawn in order of style id", which is consistent with wave-0 `d70f2c0aa`. No rider.
- Not looked at (no `tests/` or mirrored behaviour): `4f19836dc` (CI retry), `49a668466` (TODO removal),
  `530c76650`/`96e7e60b3`/`ba2560983` (dependency bumps).

## 5. Rider sweep over neighbours (brief item 3)

- `pixelbender_*`: all trace rows pass at baseline. Image rows `pixelbender_images` and `effect_twirl` are md5-identical
  under the prototype. The others have no 0x42/0x43 fill, so they can't reach the change.
- `bitmapdata_clone` / `bitmapdata-*` / `acid-bitmap*`: see §1 and §2. Unchanged.
- `shared_object*`: `shared_object_get_local_error`, `shared_object_no_root` and `from_shumway/flash_net_SharedObject`
  (ruffle_matched) are untouched by the drift. `50f28249e` only fires under `allowNetworking = none`, which we never
  run.
- `jpeg*`: `jpeg_loader_context`, `loader_jpegxr*` and `bitmapdata_encode_jpeg_visual` are untouched by the drift; no
  `tests/` change.
- AVM1 `_level` rows: `from_shumway/avm1/levels` passes, and the `target_paths` family is covered by the parse_level
  arm. The drift doesn't change semantics (§4).

## New unclaimed leads

1. **JPEG decoder fidelity to Flash.** stb_image differs from libjpeg-turbo by up to 3 levels on 7% of channels. On
   the dithering JPEG, libjpeg-turbo is about 4% closer to Flash. `bitmapdata-clone` sits at max_diff 77 = tol 77 with
   no headroom. A Flash-faithful decode (IJG ISLOW IDCT + h2v2 fancy upsampling + IJG YCbCr tables) would harden both
   Flash-golden rows. Price: M. Rows: 0 flips today; it is insurance.
2. **Other ties-down assumptions tuned against Ruffle goldens.** A grep of other nearest/sample code for `- 1e-6`-style
   tie biases is worth a look whenever a Flash golden appears for them. `avm2_bitmap.c`'s "General affine CPU raster"
   uses `floor()` on back-projection and was tuned to Ruffle's GPU quad.
3. **allowNetworking subtests** (§3): makes 2 Flash-correct `none` variants gradable.

## LOCAL ORACLE REQUESTS

- **(Flash oracle session, optional)** Real Flash trace of `_level-1`, `_level+1`, `_level-0`, `_flash2` and
  `_level99999999999` in AVM1 (SWF 6 and 8). This confirms the `'+'` → level 0 and overflow behaviour shared by Ruffle
  and us. Nothing blocks on it.
- **(Flash oracle session, optional)** Flash capture of a 0x43 fill at 1.5× y scale drawn **on stage** (GPU path,
  `render_webgpu.c` nearest sampler), to learn whether the on-screen path also needs the ties-up rule. My WGSL
  texel-snap experiment produced no change on this test only because the test goes through the CPU path. It is
  untested on a direct-render row.
