# w2-devicefont-a1 — device-font outline emission (A1), landed and flipping `device-font`

**NEW FILES (stage by name; `git add -u` drops them):**
- `SWFRecomp/include/abc/abc_glyph_flatten.hpp`

Patch: `SWFRecompDocs/plans/session21-fanout-reports/w2-devicefont-a1.patch` (it is a `git diff` taken with the
new header marked intent-to-add, so `git apply` creates it). Worktree:
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a984e8c2cb85bc74d` (base `263427d08`).

## Verdicts

| item | verdict | priced flip |
|---|---|---|
| **A1 productionized** (device TTF outlines emitted by the recompiler) | **GO** | **`visual/fonts/device-font` [output]: 8205 → 0 outliers (budget 3), max diff 255 → 0.** That is a byte-exact match with Ruffle's golden. Pixel axis +1. Trace axis: 0 moved |
| **L3** (the "5 pixel-centre ties") | **REFUTED as a raster question: it was two prototype shortcuts in the recompiler** | closes along with A1 (see §2). No runtime/raster change |
| **L4** (`leading_device_font`'s last 6 px) | **NO-GO for this slot, re-owned.** They are the **EditText border's bottom-right corner pixel**, not glyphs | completion mechanism in §4 |
| Stage3D text rows (`stage3d_texture`, `stage3d_fractal`) | **unchanged (expected)** | they use `with_default_font` (Ruffle's bundled Noto), not `[fonts.*]`. `emitDeviceFonts` never sees them. Their generated C is **byte-identical** before and after. Completion mechanism in §5 |

## 1. What the patch does

- **`abc_devicefont.cpp`**: `loadFace` now emits each glyph's outline (`glyph_pts` / `glyph_pt_start` /
  `glyph_contour_ends` / `glyph_contour_start`, the same layout the embedded-font path uses) and
  `emitDeviceFonts` wires the arrays into the `Avm2FontData` row. The runtime needed **no change**:
  `avm2_render_glyphs` already draws a device face's own outlines with NonZero fill, which is Ruffle's
  TTF rule. It uses a new `OutlineSink` that follows Ruffle's `font_face.rs GlyphToDrawing`:
  - Every move/line point and every quadratic control and anchor is **truncated** (`x as i32`, `-y as i32`)
    **before** flattening.
  - Quadratics are flattened with lyon's Levien schedule at **`GLYPH_LEVIEN_TOL` = 2.0 font units**. Ruffle
    reads a device glyph's font units as twips and tessellates at scale 1 with `DEFAULT_TOLERANCE` 0.1 px,
    which is 2.0 units whatever the face's unitsPerEm is.
  - Flattened points are **rounded** to font units, the same as `parseGlyphShape` does.
  - Faces with no ink keep NULL outline pointers, so metrics-only behaviour is unchanged (`device_font_no_ink`
    is md5-identical).
- **Prototype shortcuts, and what happened to each:**
  1. The Levien block copied from `abc_timeline.cpp` is now **hoisted** into
     `include/abc/abc_glyph_flatten.hpp` (inline, header-only, so no build-list change). Both glyph pipelines
     share it, and `abc_timeline.cpp` loses its static copy. Embedded-glyph output is proven byte-identical (§3).
  2. The em-scaled tolerance `2.0*em/20480` was **wrong**. It is now the fixed 2.0 units.
  3. Flatten-then-truncate is now truncate-then-flatten-then-round.
  4. The 16-chord cubic arm is replaced by an 8-way cubic→quadratic split fed through the same Levien
     flattener. It only applies to CFF faces, and no corpus test declares one.
  5. The 0x2FF codepoint cap is **kept on purpose**, as a documented size control. A full-BMP face would
     otherwise bloat every test that declares it.
- **`avm2_text.c`**: one comment only. The `LFont.outline` A1b note said "abc_devicefont.cpp emits none", which
  is no longer true. No code change there, and it is far from the sibling's selection/caret region (~l.3926).
- **`render_canary_tests.txt`**: appends `visual/fonts/device-font` at EOF. The standing set had no
  `[fonts.*]` member, so it could not see this change class. The new member is byte-exact against its golden
  at tolerance 0.
- Cost: `device-font`'s generated `abc_timeline.c` goes 4.2 KB → 98 KB for two Tinos faces. s19's prototype
  was about +213 KB; the coarser, correct tolerance roughly halves it. Recompile time is unchanged in
  practice (the recomp phase is < 0.1 s).

## 2. L3: the 5 pixels were never a pixel-centre tie

I ran attribution A/Bs in the same tree on local Dawn (graphics), `visual/fonts/device-font`, budget 3. The ladder
from `6cf74920c` is in the base for all rows.

| outline build | outliers | max diff |
|---|---:|---:|
| HEAD (no outlines) | 8205 | 255 |
| s19 prototype semantics (tol 0.2 units, flatten → truncate) | **15** (s20's number, reproduced) | 255 |
| tol **2.0**, flatten → truncate | 6 | 255 |
| tol 0.2, flatten → **round** | 18 | 255 |
| **tol 2.0 + round (landed)** | **0** | **0** |

Both corrections are needed, and together they make our render byte-identical to Ruffle's `quality = "low"`
golden. The aliased fill rule was never involved. s20's framing ("pixel-centre ties on the 1-bit raster, compare
N5") was wrong: the residual was flattening geometry from two prototype shortcuts. Repeat runs are
md5-identical (`1c684cf1` twice).

## 3. Evidence and tests run (sequential, `-P ≤ 2`, `SWFRECOMP_COMPILE_TIMEOUT=2400`)

**Render canary** (`render_canary.py`, `--mode=graphics`, local Dawn, `--recompile`). Before = base binary,
after = patched binary:

| test | before | after | md5 |
|---|---|---|---|
| `visual/fonts/device-font` | 8205/3 | **0/3 PASS** | changed (the flip) |
| `visual/fonts/leading_device_font` | 12978/0 | 18/0 | changed (−99.86 %, still FAIL, see L4) |
| `fonts/device_font_kerning` | 0/0 pass | 0/0 pass | **identical** |
| `fonts/device_font_no_ink` (KF) | 0/0 | 0/0 | **identical** |
| `avm2/bitmapdata_draw` | 24578/600 | 24578/600 | **identical** |
| `visual/edittext/edittext_device_transform_negative` (KF) | 1017/30 | 1017/30 | **identical** |

**Trace axis**: every AVM2 `[fonts.*]` test was run after the patch, and every status equals the CI baseline
(`_results/results_graphics.json`):
- pass: `device-font`, `leading_device_font`, `device_font_kerning`, `device_font_glyph_fallback`,
  `device_font_list`, `bitmapdata_draw`, `bitmapdata_drawwithquality`, `edittext_device_transform_basic`
- ruffle_matched: `device_font_no_ink`, `avm2/edittext_device_transform_layout`,
  `edittext_device_transform_metrics`, `edittext_device_transform_negative`

Outlines do not touch metrics. The generated-C diff on `device_font_list` shows only the new arrays and the
four pointer slots.

**Generated-C A/B** (a stronger check than render md5 for a recompiler-only change). Both binaries were run
on the same SWFs and the full `Recompiled*` trees compared byte for byte:
- **Byte-identical:**
  - all 47 standing canary members;
  - the regression text fixtures (`avm2_static_text`, `avm2_timeline_text`, `avm2_parent_child_static_text`,
    `avm2_bitmapdata_draw_textfield`);
  - `leading_embedded_font`, `leading_define_font`, `visual/fonts/glyph`, `font_lookup_as3`,
    `bitmapdata_applyfilter_colormatrix`;
  - **`stage3d_texture`, `stage3d_fractal`**;
  - every AVM1 `[fonts.*]` test (`TextField-v6/7/8`, `TextFieldTest`, `text-bind`, `cache_as_bitmap/text`).
- **Differs only in `RecompiledABC/abc_timeline.c`:** exactly the 12 AVM2 `[fonts.*]` tests above.
- One trap, for whoever repeats this: `SWFRecomp` finds `assets/NotoSans.ttf` **relative to its own binary**.
  A base binary copied into a scratch dir silently drops AVM1 default-font synthesis and looks like a
  "DIFFERS". Keep A/B binaries under `SWFRecomp/<builddir>/`.

**Regression suite**: `regression/avm2_static_text` and `regression/avm2_timeline_text` PASS under
`--mode=graphics` on the patched build. Both exercise the hoisted flattener through the embedded path. No
regression fixture uses device fonts. None is needed here: the behaviour already has a corpus oracle
(`device-font`, a Ruffle golden).

## 4. L4: `leading_device_font`'s 18 channels are the border's bottom-right corner, not glyphs

The residual is the 6 pixels at `(50|102|154, 80|180)`, one per field. Each is the **bottom-right corner pixel of
the field's `border = true` box** (fields at x = 0/52/104, width 50; y = 0/100, height 80). Every other border
and glyph pixel matches. Ours is 64 (3/4 ink); the golden is 255 (no ink). Tolerance 128 and max diff 191, so
all 6 fail. None of the four outline variants in §2 moves this row (md5 `8b078ae3` in all of them).

Completion mechanism: it belongs to `avm2_render_textbox`'s bottom-right corner rule, s20 patch 2's
territory (outside this slot's file scope). The two quality-high goldens disagree. `edittext_border_transform`
wants a 3/4 corner (s20's LineStrip reasoning). This untransformed field at integer px wants an empty one.
The next step is to find what separates the two: transform present, the Ruffle version that generated each
golden (`git log` both PNGs), or line rasterization of a strip that ends exactly on a pixel centre. It is
`max_outliers 0`, so all 6 must go, and `edittext_border_transform` must be re-checked (it is a canary member).

## 5. Stage3D text rows: why A1 cannot reach them

`stage3d_texture` and `stage3d_fractal` declare `with_default_font = true`, which is Ruffle's bundled Noto
Sans. They declare no `[fonts.*]`. The runtime draws that fallback from the metrics-only baked
`noto_device_font` (`avm2_text.c`, DefineFont3-derived, em 20480, advances rounded to tens). **Completion
mechanism:** point the same emitter at `SWFRecomp/assets/NotoSans.ttf` (byte-identical to Ruffle's
`notosans.subset.ttf.gz`, per s19) whenever `with_default_font = true`. It could supply either the whole face,
or outlines only for the baked face so trace metrics are not disturbed.

This is not a free rider. The true Noto metrics (1069/1000 ascent; unrounded advances) differ from the baked
approximation, and about 20 trace-axis tests use `with_default_font` (`device_font_spacing`, `gettextextent`,
the at-point and scroll rows, ...). Price it as its own slot with a trace A/B over those rows. The outlines-only
variant avoids the trace risk.

## New unclaimed leads

- **D1: default-font outlines (§5).** It reaches `stage3d_texture`, `stage3d_fractal`, and the
  `bitmapdata_applyfilter_colormatrix` text (s19: 100 % of its 7419 channels). The recompiler emitter now
  exists and is correct; what remains is wiring and a trace-risk A/B.
- **D2: the L4 corner rule (§4).** One mechanism covers all 6 px of `leading_device_font`, and both goldens it
  must reconcile are named.
- **D3: stb_truetype floors implied on-curve midpoints; ttf_parser does not.** stbtt computes
  `(c0+c1)>>1`, which floors, while Ruffle's ttf_parser takes the f32 midpoint and then truncates toward zero.
  The two disagree by 1 font unit when a midpoint is a negative .5. No corpus row shows it today (`device-font`
  is byte-exact), but a face or size that lands on a pixel centre could. The fix is a small `glyf` point reader
  in `abc_devicefont.cpp` that computes midpoints the way ttf_parser does. Composites would stay on stbtt.
- **D4: the 0x2FF outline cap** is a size control, not parity. A device-font test using CJK or other
  higher-plane text would render blank. If one appears, emit only the glyphs whose codepoints appear in the
  SWF's string constant pool.

## Addendum: D4 regression check (the coordinator's question) → follow-up patch `w2-devicefont-a1-2-cap.patch`

This covers what a codepoint above U+02FF rendered BEFORE and AFTER patch 1, in an AVM2 device-font TextField:

| case | before patch 1 | after patch 1 | after patch 2 |
|---|---|---|---|
| no same-name embedded face | blank (metrics-only face) | blank (capped) | blank: no regression |
| face emits NO outline ≤ U+02FF | A1b borrow (if an embedded twin exists) | unchanged (`glyph_pts` stays NULL, borrow fires) | unchanged |
| **face has ink ≤ U+02FF AND the SWF embeds a same-name twin** | **drawn from the embedded twin** | **blank**: `fd->glyph_pts != NULL` switched the A1b borrow off | drawn from the twin again |

The third row is a real, narrow **regression** in patch 1. No corpus row exercises it:
`device_font_kerning` is the only borrow case and its text is ASCII.

The fix (runtime only, `avm2_text.c` `resolve_font` plus the matching `LFont` comment) removes the
`fd->glyph_pts == NULL` gate. An embedded same-name twin now always supplies the shapes, exactly as before
s21. The recompiler-emitted device outlines are used only when there is no twin, which is the case that flips
`device-font`. This makes every borrow case behave as it did before s21.

Verified with a graphics canary on this build; all four PNG md5s are identical to the patch-1 "after" capture:
`device-font` 0/3 `1c684cf1`, `device_font_kerning` 0/0 `a60be153` (also equal to pre-s21),
`edittext_device_transform_negative` 1017 `cb97662c`, `leading_device_font` 18 `8b078ae3`.

Patch 2 applies on top of patch 1 and touches only `SWFModernRuntime/src/avm2/avm2_text.c` (the LFont comment
near l.2540 and `resolve_font` near l.2730, both far from the caret/selection code).
