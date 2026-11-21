# w2-stage3d-text — Stage3D render-to-texture + fragment budget + AVM2 default-font advances

Session 23 wave 2 (implementation). Branch `fanout/w2-stage3d-text`, based on `origin/master` `e36c2483`.

**New files:** none in source. Deliverables only:
`SWFRecompDocs/plans/session23-fanout-reports/w2-stage3d-text-report.md`,
`SWFRecompDocs/plans/session23-fanout-reports/w2-stage3d-text.patch`.

**Patch scope** (`w2-stage3d-text.patch` = `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`, checked with `git apply --check -R`):

| file | change |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_stage3d.c` | render-to-texture (RTT), `S3D_FRAG_BUDGET` 12 M → 48 M |
| `SWFModernRuntime/src/avm2/avm2_text.c` | the `with_default_font` device fallback now lays out with the real Noto Sans TTF row (it used the baked DefineFont3 table) |
| `ruffle-tests/render_canary_tests.txt` | appended `avm2/stage3d_texture` at EOF (tier 1) |

No recompiler changes, no `swf_core.c`/`tag_stubs.c`/`NO_GRAPHICS` arms, and no new `.c`/`.h` files.

---

## Verdicts (lead)

| # | Item | Verdict | Measured, before → after (clean master vs patch, same box) |
|---|---|---|---|
| 1 | RTT + 48 M budget | **GO, landed** | `stage3d_texture` 204781 → 2786 (RTT and budget alone); `stage3d_bitmap` 135407 → 48 (budget alone) |
| 2 | Text residual on both rows | **GO, landed. The brief's hypothesis is REFUTED; the real cause was different** | `stage3d_texture` 2786 → **2 (PASS, limit 117)**; `stage3d_bitmap` 48 → **0 (PASS, limit 24)** |
| 3 | Wide sweep (47 graphics rows, 23 no-graphics trace rows, 37 regression rows, 86-test canary) | **clean** | only the 5 ledger rows move, and none gets worse; 0 trace changes in either mode |
| 4 | Fidelity | **proven** | the before md5s of both headline rows equal CI's actual PNGs from images run **`38995363802`** (`origin/ruffle-image-results` `35f66723`): `stage3d_texture` `ec71600f…`, `stage3d_bitmap` `2fac284c…` |

Priced flips: **+2 pixel** (`avm2/stage3d_texture`, `avm2/stage3d_bitmap`). Trace: 0.

## EXPECTED-FLIP LEDGER (for CI)

**Pixel axis (graphics images run):**

| test | CI before | expected after |
|---|---|---|
| `avm2/stage3d_texture` | fail 204781 / 117 | **PASS** (2 outliers, max diff 15) |
| `avm2/stage3d_bitmap` | fail 135407 / 24 | **PASS** (0 outliers, max diff 2) |
| `visual/fonts/font_lookup_as3` | fail 19560 / 72 | fail **11592** (a band improvement, still failing) |
| `avm2/away3d_advanced_shallow_water_demo` | fail 1326849 | fail 1326765 (band, −84) |
| `avm2/stage3d_fractal` | fail (local 1104123; CI's last JSON shows 1099377 at `c1fa89bc2`) | fail, local 1104108 (band, −15) |

All other image rows must stay md5-identical. That includes the 27-row Stage3D set and
`stage3d_texture_bytearray_compressed_alpha`. That row is 8192/66 on BOTH legs locally: upstream drift `5021d0ed7`,
owned by the drift slots, and not booked here.

**Trace axis:** no changes expected in either mode. All 23 `with_default_font` rows gave identical status and line
counts before and after, in graphics and in no-graphics.

---

## 1. Render-to-texture + budget (`avm2_stage3d.c`)

I landed the w1-pixel-misc §3a prototype and hardened it in four places the prototype did not cover:

- **`setRenderToTexture`**: parks the back buffer in new trailing `S3dBackend` fields (`rtt_tex`, `rtt_layer`,
  `bb_*`). It allocates an RTT surface at the texture's size with the sample count `antiAlias` rounded down to
  {1,2,4}, seeds it from the texels (LoadOp::Load), and turns depth/stencil on per `enableDepthAndStencil`. This
  follows Ruffle `render/wgpu/src/context3d/mod.rs:773-863`.
- **`setRenderToBackBuffer`** (new; this was `s3d_noop`), **`configureBackBuffer`** and **`present`** resolve the
  surface into the texel store with `s3d_rtt_end`. The resolve uses the same per-sample quantise + floor-mean as
  `s3d_present`, keeps alpha, and then restores the back buffer.
- **Hardening 1, `present` while RTT is open.** Ruffle's `present()` ends with `set_render_to_back_buffer`
  (mod.rs:1249). The prototype would have resolved a texture-sized colour buffer into the back-buffer-sized `front`,
  which overflows the heap whenever the texture is larger. `present` now ends RTT first.
- **Hardening 2, a frame ending mid-RTT.** `avm2_stage3d_front_buffer` (the composite hook) used `be->w/h`, which
  are the texture's dims during RTT, to index `front`, so it read out of bounds. It now uses the parked `bb_w/bb_h`.
- **Hardening 3, GC.** `rtt_tex` points into a texture's ext, but `S3dBackend` is a side allocation the conservative
  ext scan cannot see. A trailing `Avm2Object* rtt_obj` on `Avm2Context3DExt` is now the GC-visible edge.
- **Hardening 4, leak.** The context's ext-free hook now calls `s3d_rtt_end(ctx, be, 0)`, which frees the RTT
  surface and restores `bb_*` without resolving, so the parked back buffer is freed too.
- **`S3D_FRAG_BUDGET` 48 M.** The comment block records why. At 12 M the budget latched mid-run and froze both rows'
  frames; 24 M still leaves `stage3d_texture` at 14933. away3d run time is unchanged: x = 9.07 s before, 9.23 / 8.87 s
  after, well inside the 30 s wall.

## 2. The text residual: hypothesis refuted, real mechanism found

**Brief's hypothesis:** AVM2 TextField layout does not round device advances to whole pixels. **Refuted.**
`avm2_text.c::char_advance` is already a line-for-line port of Ruffle `font_like.rs::evaluate` for
`FontType::Device`: `round_to_pixel(Twips((adv*scale) as i32))` plus `round_to_pixel_ties_even(letter_spacing)`,
with the `spaced > 0` guard. Upstream `0ddd12b6a` has the same rule.

**Real mechanism: the font DATA, not the rule.** Both rows set `with_default_font = true`. Ruffle registers its
bundled `core/assets/notosans.subset.ttf.gz` (raw deflate) as a `FontFace` (`player.rs:3139`). Its numbers come from
the TTF itself (`font_face.rs`): em 1000, hhea ascent 1069, descent 293, line gap 0, hmtx advances, and kerning only
from a `kern` table. This file has none (only GPOS), so there is **no kerning**. Our layout used the baked
`noto_device_font` table instead. That table came from a Flash DefineFont3 embedding: em 20480, advances quantised
to 10 units. The quantisation is enough to push a glyph onto the other side of a pixel boundary:

- `':'`: TTF 268/1000 → at 9 px (180 tw) that is 48 tw → **2 px**. Baked 6030/20480 → 52 tw → **3 px**.
- `stage3d_bitmap`'s label is `_sans` 9 px bold, `"… - FPS: 0"`, so the final `0` sat 1 px right. An ASCII dump
  shows identical glyph bitmaps at x+1; those 16 px were the whole 48-outlier residual.

The recompiler ALREADY emits the real TTF as the NULL-named device row (`abc_devicefont.cpp
appendDefaultFontOutlines`, from `SWFRecomp/assets/NotoSans.ttf`). I verified that file is byte-identical
(md5 `994ff225…`) to Ruffle's decompressed subset, with all 1527 cmap advances equal. It carries exactly
`{em 1000, 1069, 293, 0}`, real advances, `kerns.clear()`, and the same codepoint list as the baked table. Before
this patch it was used only for glyph SHAPES ("Advances and leading stay baked", D1-2).

**Fix** (`resolve_font`, final fallback): when the field is a device field and that row exists, `f.data` = that row,
so layout and shapes come from one face. The now-unused `noto_default_font_metrics` table is deleted. The metrics
change from 21893/6000 on em 20480 to 1069/293 on em 1000, which differ by <0.001 em. Font-data `leading` is never
read by layout; only `TextFormat.leading` is.

**Blast radius, argued and then measured.** The row is emitted only when `test.toml` has
`[player_options] with_default_font = true` (`abc_devicefont.cpp:690`). Without it, `default_font_outline()` is NULL
and the code path is byte-identical to before. So the text half can move exactly the tests that set it:
**23 locally** (11 avm2, 1 fonts, 11 visual). Upstream has 29; the other 6 are avm1 and never reach `avm2_text.c`.
I swept all 23 on both axes.

**Recompiler:** no emission change needed (the row already exists), so there is nothing to coordinate with
`w2-glyph-levien`, which changes glyph SHAPES in `swf.cpp`. If that sibling changes `abc_devicefont.cpp`'s
NULL-named row (codes, metrics), it now feeds AVM2 layout under `with_default_font` too.

## 3. Sweeps (all local, same box, clean `origin/master` vs patch)

**Graphics, 47 rows** = 23 `with_default_font` rows ∪ the 27 image-graded Stage3D rows (`avm2/stage3d_*` +
`stage3d/*`; 3 rows are in both sets). Rows that moved (everything else: status, line counts, image message and md5
all identical):

| test | before | after | md5 |
|---|---|---|---|
| `avm2/stage3d_texture` | FAIL 204781 / 117 | **PASS 2 / 117** | differs |
| `avm2/stage3d_bitmap` | FAIL 135407 / 24 | **PASS 0 / 24** | differs |
| `visual/fonts/font_lookup_as3` | FAIL 19560 / 72 | FAIL 11592 / 72 | differs |
| `avm2/away3d_advanced_shallow_water_demo` | FAIL 1326849 | FAIL 1326765 | differs |
| `avm2/stage3d_fractal` | FAIL 1104123 | FAIL 1104108 | differs |

Unchanged rows of note:
- `stage3d_blend` 5064/5200, `stage3d_rotating_cube` 244/250, `stage3d_stencil` 0, `stage3d_sampler` 50, and the
  `program_constants_bytearray_*` rows at 3523: all identical md5.
- The visual `bevel*`/`glow*`/`drop_shadow` rows: identical md5 (their text is AVM1 or embedded).
- `visual/cache_as_bitmap/edittext_scroll` and `fonts/embed_matching/no_font_found`: identical md5.

**No-graphics trace, the 23 `with_default_font` rows.** These include `edittext_at_point_methods_basic` (16/16),
`edittext_mouse_selection` (363/363), `edittext_scrollh` (10/10), `edittext_getcharboundaries_missing_embedded_font`
(ruffle_matched 4/7) and `edittext_event_link_case_insensitive` (output_mismatch 0/1; absent from the last CI JSON,
so it is new upstream). All are **identical** before and after. The graphics trace for the same rows is also
identical, so the textWidth / getCharBoundaries / getLineMetrics readers did not move.

**Regression suite**: all 37 `regression/avm2_*` fixtures in graphics: **identical** status and md5.

**Render canary** (`render_canary.py capture --tier all`, 86 tests / 141 comparisons; avm1 and from_shumway were
downloaded for it): **IDENTICAL 141, DIFFERS 0**, no trace or image status changes. The standing set could not see
this change class (no RTT member, no `with_default_font` AVM2 member), so I appended `avm2/stage3d_texture` at EOF.
After md5 `ecfa2cb2…` is deterministic across 3 runs.

## 4. Fidelity

The before renders of `avm2/stage3d_texture` (`ec71600f58cd1069dcd2af96b914957a`) and `avm2/stage3d_bitmap`
(`2fac284c6438f2e52891c7ec3ec5cdd9`) are byte-identical to `origin/ruffle-image-results` (`35f66723`, images run
`38995363802`). Local grading is therefore CI-grade for both headline rows.

## Drift noted (not booked)

- `avm2/stage3d_texture_bytearray_compressed_alpha`: 8192/66 on both legs. This is upstream `5021d0ed7` (drift slots).
- `avm2/stage3d_fractal`: local before is 1104123 vs CI JSON 1099377, but that JSON is from `c1fa89bc2` against the
  older upstream, so this is upstream or tolerance movement. The fresh baseline run will settle it.
- `visual/cache_as_bitmap/edittext_scroll` output.02 passes locally (0/5) vs CI fail 6/5 at `c1fa89bc2`. It is
  identical before and after my patch, so it is not mine; the fresh baseline will show it.

Tests were downloaded from upstream master on 2026-11-21. `download_tests.sh` does not print the SHA; current HEAD is
`aa9f62a70`, and both headline `test.toml`s are identical to `0ddd12b6a`'s.

## Refutations

1. **"AVM2 does not round device advances to whole pixels"**: refuted (§2). The rule was already exact; the font
   table was wrong.
2. **"Glyphs after the first few drift cumulatively"**: on `stage3d_bitmap` the drift is a single glyph advance
   (`':'`). Any "cumulative" drift on longer lines is each mis-rounded glyph adding its own pixel.

## Not finished / completion mechanisms

Nothing in scope is left open. CI confirmation is the coordinator's graphics images run against the ledger above.

## New unclaimed leads

1. **`visual/fonts/font_lookup_as3`** 19560 → 11592: the remaining residual is not this mechanism (unmeasured; likely
   named-device or embedded lookups in the same SWF). It is now a cheaper row to diagnose.
2. **AVM1 parity check:** AVM1's `swf.cpp` zero-glyph synthesis already seeds from `NotoSans.ttf`. Its advances
   should be confirmed to be TTF advances, not baked ones, for the 6 avm1 `with_default_font` rows (sibling
   `w2-glyph-levien` owns `swf.cpp`).
3. **The baked `noto_device_font`** (DefineFont3 advances) still serves device fields in tests WITHOUT
   `with_default_font`. In Ruffle such fields have no device font at all, so those numbers (textWidth etc.) are an
   approximation of nothing. Worth a dedicated trace look; no row is priced here.

## LOCAL ORACLE REQUESTS

None.
