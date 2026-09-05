# w2-gfx-text — wave 2: EditText render fixes (+4 pixel flips, 0 regressions)

Isolated worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a6cb97b3937d0d7d0`,
based on `master` @ `a90841295` (the worktree was created at `8f68a5fea`; I fast-forwarded it
to current master so the patch applies on top of the seven landed session patches — the patch
base IS `a90841295`). No commits, no pushes. Local Dawn at `~/CC/dawn-install`.
Scratch: `<scratchpad>/w2-gfx-text/`.

## NEW files

**None.** No new `.c`/`.h`; every edit is inside a file the build already compiles, so
`verify_output.py`'s source lists, CMakeLists and the Emscripten build need no change.
Deliverables only: `w2-gfx-text.patch`, `w2-gfx-text-report.md`.

---

## 0. Verdict board

| # | verdict | flips | comparison | before → after | files |
|---|---|---:|---|---|---|
| **G1** | **GO — LANDED** | **+1** | `visual/edittext/edittext_bounds_vs_position` | **519 → 0** outliers (byte-exact, `tolerance 0`) | `shape_hit_test.c`, `tag.h`, `action.c` |
| **G2** | **GO — LANDED** | **+1** | `visual/edittext/edittext_underline` | **1974 → 12** (limit 16, max diff 111 < tol 144) | `avm2_text.c`, `avm2_display.c` |
| **H1** | **GO — LANDED** (needed G2) | **+1** | `visual/edittext/edittext_underline_scale2` | **27672 → 12** (limit 16) | `avm2_display.c` |
| **A1b** | **GO — LANDED** | **+1** | `fonts/device_font_kerning` | **1680 → 0** (byte-exact, `tolerance 0`) | `avm2_text.c` |
| — | band move (not scored) | 0 | `visual/edittext/edittext_device_transform_negative` (`ruffle_matched`) | 2649 → 1017 | rider of A1b |

**Net: +4 pixel flips, 0 pixel regressions, 0 trace regressions.**
Premises attacked: **2 refuted** (§2.2 "both VMs", §4.3 "A1b is the entry point into A1"),
**2 confirmed** (§1, §3), **1 measured that the brief left as an assumption** (§3.1: the A/B
that shows G2 alone makes `scale2` *worse*).

### Patch scope (`w2-gfx-text.patch`, 5 files, +262/−36)

| file | region | item |
|---|---|---|
| `SWFModernRuntime/src/libswf/shape_hit_test.c` | `ng_getMatrixFromObj_render` (:42) | G1 — split into a `_tid` variant + a wrapper; **no behaviour change** to the existing symbol |
| `SWFModernRuntime/include/libswf/tag.h` | :438 | G1 — declare `ng_getMatrixFromObj_render_tid` |
| `SWFModernRuntime/src/actionmodern/action.c` | `getLocalMatrixForMC_render` (:9245) only | G1 — resolve the pre-compose id under `#ifndef NO_GRAPHICS` |
| `SWFModernRuntime/src/avm2/avm2_text.c` | `LFont` (+1 field), `resolve_font`, `avm2_edittext_collect_glyphs`, new `avm2_edittext_collect_underlines` | G2 + A1b |
| `SWFModernRuntime/src/avm2/avm2_display.c` | the EditText painter block only (`tw_*` helpers, `avm2_draw_border_line`, `avm2_render_textbox`, `avm2_render_text`) + 1 prototype | G2 + H1 |

**Sibling overlap check** (`SIBLING_FILE_MAP.md`): w2-gfx-fill-smalls also edits `avm2_text.c`
(:3859 GRAY constant) and `avm2_display.c`'s gfx `drawPath`; w2-gfx-avm2-blend edits
`avm2_display.c`'s render **walk**; w2-gfx-strokes edits `action.c`'s
`drawing_emit_stroke_*` (~:29516) and `avm2_display.c`'s `gfx_*` helpers (~:8176).
None of those regions is touched here — my `avm2_display.c` edits are confined to
`:17885-18300` (the EditText painter), my `action.c` edit to `:9245`, and my `avm2_text.c`
edits to the font-resolution and glyph/underline-collection functions.

**Disposition check (standing rule 2).** Grepped all four disposition docs plus
`ruffle-tests/ignored_tests.txt` and the per-suite lists for `edittext_bounds_vs_position`,
`edittext_underline`, `edittext_underline_scale2` and `device_font_kerning`: **no hits**. The
one text-family entry in `ACCEPTED_DIFFS.md` is `from_shumway/avm1/text-bind`, which I did not
touch. Neither underline test nor `device_font_kerning` is `known_failure`.

---

## 1. G1 — `edittext_bounds_vs_position` 519 → 0

w1's diagnosis is **confirmed verbatim**. `getLocalMatrixForMC_render` →
`ng_getMatrixFromObj_render` read `obj->transform_id` while `compose_children` had already
rewritten a *nested* entry's id to a dynamic GPU slot with no CPU-side `transform_data` row;
the garbage `d == 0` tripped `tf_transform_positive_scale_only` and dropped all six
sprite-nested fields.

Implemented as w1's **option (b), self-localised** — the shared accessor keeps its exact old
behaviour:

* `shape_hit_test.c`: split the body into a new `ng_getMatrixFromObj_render_tid(obj, tid, …)`
  that takes the transform-table ROW from the caller. `ng_getMatrixFromObj_render` is now a
  one-line wrapper passing `obj->transform_id` — **hit testing is bit-identical**, in
  NO_GRAPHICS as well as graphics.
* `tag.h`: declaration for the new entry point.
* `action.c` `getLocalMatrixForMC_render`: calls the `_tid` variant with
  `ng_get_original_transform_id(entry)` under `#ifndef NO_GRAPHICS`, with the old call in the
  `#else` arm. `ng_get_original_transform_id` lives inside tag.c's `#ifndef NO_GRAPHICS`
  region (`tag.c:2638` opens it), so the guard is required, and it makes the **NO_GRAPHICS
  build textually unchanged** — the strongest available statement about the trace axis.

**AS-visible surface is unchanged even in graphics mode.** `getLocalMatrixForMC_render`'s other
callers are `localToGlobal` / `globalToLocal` (`action.c:73082/73144`) and the concat helper at
`:9396`. `g_xform_override_count` is non-zero only *between* `compose_children` and
`xform_overrides_restore`, i.e. inside the render pass, where no ActionScript runs; outside it
`ng_get_original_transform_id` returns `obj->transform_id` and the two arms are the same
expression. The 89-test `regression` sweep and the AVM1 canaries below are the empirical half
of that argument.

---

## 2. G2 — underlines, and what the brief got wrong about "both VMs"

### 2.1 What landed
* `avm2_text.c`: new `avm2_edittext_collect_underlines(ctx, tf_obj, &out)` — the exact twin of
  the existing `avm2_edittext_collect_selection`. Returns `{x, y, w, 0xRRGGBB}` per **layout
  box** in field-local twips, with Ruffle's geometry (`edit_text.rs:1318-1329`):
  `y = ascent + line->descent / 2` (`ascent` at the box's own size, `descent` the LINE's max),
  `w = lbox.bounds().width()` (the box width, **not** the ink width), colour from the box's
  span. The bullet / empty / below-the-bottom culls match `render_layout_box` because the
  underline is drawn inside its `as_renderable_text` arm.
* `avm2_display.c`: `avm2_render_underlines()` maps each segment through the world matrix,
  applies `EditTextPixelSnapping` to the resulting translation (low-quality arm: round
  tx/ty to the device grid, leave the scale alone — both carriers are `quality = "low"`,
  i.e. `MSAA_SAMPLES == 1`), then draws through the SAME `emulate_line_as_rect` helper the
  rotated border already used (`avm2_draw_border_line`), so the 1-pixel thickness and the
  HALF_PX offsets are never transformed. Called from `avm2_render_text` **after** the glyphs
  and **inside** the field clip mask, which is Ruffle's order.

### 2.2 REFUTED: "both VMs: `TextFieldGlyphRun` gains an underline flag"
Both underline comparisons are the **same AVM2 SWF** (v41) at two viewports. I did **not**
touch `TextFieldGlyphRun`, `action.h`, `tag.c` or `render_webgpu.c`, and the flip is complete
without them. The AVM1 painter still draws no underline — that is real, but it has **zero
pixel carriers in the corpus today**, so paying for it would have meant editing the AVM1 glyph
painters (which every one of the 20 `visual/edittext` comparisons rides) for no scored move.
Filed as unclaimed lead §7.1. Actual cost of the AVM2-only route: ~120 LOC vs the brief's
"~80–150 across two VMs".

### 2.3 Residual (12 outliers, limit 16)
Both underline comparisons land on exactly **12 outlier channels**, max diff 111 (`underline`)
/ 213 (`scale2`), well inside `max_outliers 16`. That is 4 pixels; the two runs having the
identical count says the residual is one shared sub-pixel case (most likely a run-end column
where Ruffle's `len` rounds the other way), not per-viewport drift.

---

## 3. H1 — the AVM2 EditText box is now measured in DEVICE pixels

Confirmed as w1 diagnosed. `avm2_render_textbox` computed the whole box in **stage** twips with
literal `20.0` thicknesses; Ruffle seeds its `transform_stack` with the stage view matrix, so
its "1px" is one **device** pixel. At 1800×600 over a 900×300 stage our border was 2 device
pixels wide and the snapping grid was twice as coarse.

Ported s17's AVM1 fix (`tag.c:5378`, A3) to the AVM2 painter: `avm2_text_dscale()` /
`avm2_text_device_twip()` plus `tw_round_to_device_px` / `tw_trunc_to_device_px`, and every
literal `20.0` border thickness, the `frac_bottom` grid test, the `HALF_PX` offsets in
`avm2_draw_border_line`, and both snapping arms now work on that grid. **At `dscale == 1`
every expression reduces to the old one verbatim**, which is why all 20 `visual/edittext`
comparisons and both `*_basic_scale2` AVM1 twins came back byte-identical.

The high-quality arm also had to learn the scale conversion
(`nearbyint(ba*dsc - 0.35)/dsc`, `trunc_to_device_px(tx + 2/dsc)`) — again an identity at
`dscale == 1`, and the corpus has no default-quality AVM2 EditText at a mismatched viewport,
so nothing exercises it yet.

### 3.1 A/B probe: H1 is not optional, and G2 alone makes `scale2` WORSE
G2 and H1 had to land together (at 2× the underline itself would be drawn 2 device pixels
thick), so I measured the split directly: `avm2_text_dscale()` forced to `1.0`, everything
else identical, one rebuild of `edittext_underline_scale2`.

| leg | `edittext_underline_scale2` |
|---|---:|
| baseline (no G2, no H1) | 27672 fail |
| **G2 only** (`dscale ≡ 1`) | **27778 fail** |
| **G2 + H1** (shipped) | **12 pass** (limit 16) |

So G2 on its own is a small *regression* on this comparison (+106 outlier channels): the
underline gets painted, but two device pixels thick and half a device pixel off, which adds
more differing channels than the missing underline cost. This both confirms w1's H1 diagnosis
and refutes any reading in which the underline work alone would have moved the 2× row. The
probe was reverted; `git diff` carries no trace of it.

---

## 4. A1b — `fonts/device_font_kerning` 1680 → 0

### 4.1 What landed
`LFont` gains one field, `const Avm2FontData* outline`. In `resolve_font`'s device arm, when
the resolved `[fonts.*]` face has `glyph_pts == NULL` (abc_devicefont.cpp emits metrics,
advances and the TTF `kern` table but no contours) and the SWF **embeds** a face with the same
name + bold + italic that *does* have outlines, that embedded face is recorded as the outline
source. `avm2_edittext_collect_glyphs` then resolves the glyph index, the em-square scale and
the placement's `font` against the outline face.

**Nothing the layout reads changes.** Advances, kerning, ascent/descent, `getLineMetrics`,
`textWidth` and the box geometry all still come from the device face, and `is_device` stays 1
so `kerning_enabled` keeps Ruffle's "device fonts always kern" rule. The only difference is
that glyph shapes appear where the field used to render nothing — the change can only ADD ink,
and only on a field that is currently blank.

Result: **1680 → 0 outliers, byte-exact at `tolerance 0`.** Trace verdict unchanged (`pass`).

### 4.2 The brief's question answered: `device-font` / `leading_device_font` do NOT move
* `visual/fonts/device-font` **8205 → 8205**
* `visual/fonts/leading_device_font` **12978 → 12978**
* `visual/fonts/font_lookup_as3` 34632 → 34632 (a third source: Ruffle's bundled default font)

Neither SWF embeds the `[fonts.*]` face it asks for, so A1b's trigger never fires. They still
need real TTF contours.

### 4.3 REFUTED: "A1b is the recommended entry point into A1"
It is a **flip, not a foothold**. A1b works precisely because `device_font_kerning` embeds the
very TTF it then requests as a device font — a property none of the other A1 rows share. The
mechanism it adds (borrow outlines from a same-name embedded face) contributes **nothing** to
the remaining A1 rows, whose outlines exist only in the `[fonts.*]` TTF or in Ruffle's bundled
default font. A1 still costs exactly what it cost before: emit `stbtt_GetGlyphShape` contours
from `abc_devicefont.cpp` into the generated glyph tables. Treat A1b as closed and A1 as
untouched.

### 4.4 Unpriced rider
`visual/edittext/edittext_device_transform_negative` (`known_failure`, `ruffle_matched` — must
not be scored) went **2649 → 1017** outliers: a second SWF that embeds the face it asks for as
a device font, now drawing glyphs. Trace verdict unchanged. Useful telemetry for A1's band.

---

## 5. Ledgers

### 5.1 Pixel ledger — `visual` (31 tests, 57 comparisons), `--mode=graphics --images`
Baseline column is the CI image run `33857494837` @ `659153865`; **every non-flip row is
byte-identical to it.**

| comparison | before | after | verdict |
|---|---:|---:|---|
| `visual/edittext/edittext_bounds_vs_position [output]` | 519 fail | **0 pass** | **FLIP** |
| `visual/edittext/edittext_underline [output]` | 1974 fail | **12 pass** (lim 16) | **FLIP** |
| `visual/edittext/edittext_underline_scale2 [output]` | 27672 fail | **12 pass** (lim 16) | **FLIP** |
| `edittext_background_basic`, `_scale2` | 0 pass | 0 pass | unchanged |
| `edittext_border_basic`, `_scale2` | 0 pass | 0 pass | unchanged |
| `edittext_border_filters` | 827 fail | 827 fail | unchanged |
| `edittext_border_transform` .01–.06 | 0/0/0/51/0/44 | 0/0/0/51/0/44 | unchanged |
| `edittext_caret_empty` .01–.12 | 0 pass ×12 | 0 pass ×12 | unchanged |
| `edittext_device_transform_negative` (KF) | 2649 fail | 1017 fail | band move |
| `edittext_device_transform_small_rotation` | 11 pass | 11 pass | unchanged |
| `edittext_device_transform_small_shear` | 88 fail | 88 fail | unchanged |
| `edittext_gutter` | 1032 fail | 1032 fail | unchanged |
| `edittext_justify`, `_negative_bounds`, `_selection_font_size` | 0 pass | 0 pass | unchanged |
| `edittext_selection_leading` .01–.12 | 0×10, 36, 36 | identical | unchanged |
| `visual/fonts/*` (8 tests, 8 cmps) | 0/8205/3/34632/6/0/12978/0 | identical | unchanged |
| `visual/cache_as_bitmap/edittext_{hscroll,scroll,selection}` (7 cmps) | 96/960/566/570/366/6783/373 | identical | unchanged |
| `edittext_device_transform_basic` / `_metrics` (trace-only) | pass / ruffle_matched | pass / ruffle_matched | unchanged |

### 5.2 Pixel ledger — `fonts` (7 tests)

| comparison | before | after | verdict |
|---|---:|---:|---|
| `fonts/device_font_kerning [output]` | 1680 fail | **0 pass** | **FLIP** |
| `fonts/embed_matching/fallback_preferences` | 156 fail | 156 fail | unchanged |
| `fonts/embed_matching/match_style` | 12 fail | 12 fail | unchanged |
| `fonts/embed_matching/no_font_found` (KF) | 0 pass | 0 pass | unchanged |
| `fonts/device_font_glyph_fallback`, `device_font_list` (trace-only) | pass | pass | unchanged |
| `fonts/embed_name_lookup` (trace-only) | `output_mismatch` | `output_mismatch` | unchanged (pre-existing) |

### 5.3 Pixel ledger — `text` (11 tests)

| comparison | before | after | verdict |
|---|---:|---:|---|
| `text/auto_size/height` | 15 fail | 15 fail | unchanged |
| `text/auto_size/return` | 36 fail | 36 fail | unchanged |
| `text/auto_size/width` | 18 pass | 18 pass | unchanged |
| `text/br_at_start` | 3691 fail | 3691 fail | unchanged |
| `text/style_changes_in_html` | 25102 fail | 25102 fail | unchanged |
| 5 × `text_caret_placement_*` / `html_entity_parsing` (trace-only) | pass | pass | unchanged |
| `text/links_in_scrolled_text` (trace-only) | `output_mismatch` | `output_mismatch` | unchanged (pre-existing) |

`text/auto_size/width` is the row that s17's `MSAA_SAMPLES == 1` arm was tuned for; it stays at
its exact 18-outlier limit, which is the sharpest single check that H1's rewrite is an identity
at `dscale == 1`.

---

## 6. Canary ledgers

Everything below was run in the worktree with `--recompile` on first use,
`SWFRECOMP_COMPILE_TIMEOUT=2400`, `xargs -P 2`, `--mode=graphics` unless stated.
Baselines are the merged CI results already in the tree
(`<suite>/_results/results_graphics.json` for trace, `image_results_graphics.json` for
pixels; `results.json` for the no-graphics leg).

| canary set | tests | comparisons | result |
|---|---:|---:|---|
| `regression` suite, FULL (graphics) | **89** | incl. its image rows | **0 differing** from baseline |
| `avm1` — every `edittext_*`, `*hittest*`, `textfield_*` (graphics) | **73** | — | **0 differing** |
| `avm1` — NO_GRAPHICS leg (8 hit-test + 3 EditText) | **11** | — | **0 differing** |
| `avm2` — 14 `edittext_*` + `blend_multiply_alpha` | **15** | 5 image | **0 differing**, all 5 images byte-identical |
| `visual` (my families) | 31 | **57** | 3 FLIPS, 54 byte-identical, 0 regressions |
| `fonts` | 7 | 7 | 1 FLIP, 6 identical |
| `text` | 11 | 11 | 0 moves |
| render-canary rows, NON-text families (`avm1/color`, `bitmap_data_fillrect`, `mask_with_drawing`, `movieclip_setmask`, `bitmapdata_applyfilter_colormatrix`, `focusrect_swf5` ×12, `edittext_tag_indent`) | 7 | **18** | **all 18 byte-identical**, trace 0 differing |
| render-canary rows, `visual` (`filters/glow_pass_scaling`, `filters/drop_shadow`, `simple_shapes/winding_rule`, `simple_shapes/masks`, `cache_as_bitmap/masks` ×7, `cache_as_bitmap/shape_changed`) | 6 | **12** | **all 12 byte-identical** |

**Totals: 239 test runs, 105 image comparisons, 4 flips, 0 regressions of any kind.**

### 6.1 Deviation from the brief's canary instruction — stated plainly
The brief asks for `render_canary.py capture/compare` over the full 106-row standing set.
`render_canary.py` is a **two-leg** tool: it needs a pre-edit `before` capture, which I do not
have, so honouring it literally means 212 compile-bound test builds. Under the shared-machine
`-P 2` cap that was out of budget. What I ran instead is the **absolute** form of the same
check on 30 canary comparisons drawn from that file (the two blocks above), graded against the
CI baseline rather than against a local `before` — for a CI-passing row that is a strictly
stronger statement than md5 identity, and for the two CI-failing rows I included
(`filters/drop_shadow` 46032, `simple_shapes/masks` 181) the unchanged outlier count is the
same information md5 identity would have given. **Gap named:** the canary families I did not
cover at all are morph (`hittest_morph*` were covered on the trace axis only), stage3d, video
and the `from_shumway` timeline/acid rows. My patch touches no code any of those reach —
`avm2_render_text` / `avm2_render_textbox` / `avm2_edittext_collect_*` and the AVM1
`getLocalMatrixForMC_render` accessor — but that is an argument, not a measurement.

### 6.2 Harness artefacts encountered (not verdicts)
Four `avm1` dirs ship into a fresh worktree partially git-tracked and without `test.swf`
(`external_interface`, `global_instance_decls`, `global_proto_decls`,
`global_proto_decls_delete`) — first run gave `RECOMP_FAIL: SWF file 'test.swf' not found`,
and copying only `test.swf` then gave
`TypeError: unsupported operand type(s) for /: 'PosixPath' and 'NoneType'` because `output.txt`
was missing too. `cp -rf <maintree>/<dir>/. <worktree>/<dir>/` fixes both; all four then match
baseline. Worth adding to the sibling gotcha list: copy the **whole** dir, not just the SWF.

Two pre-existing non-`pass` baselines showed up inside my sets and are **not** regressions:
`fonts/embed_name_lookup` and `text/links_in_scrolled_text` are `output_mismatch` on both
sides.

`--verbose` writes `output.actual.png` / `output.difference.png` into the test dir, which
dirties the **tracked** `regression/` suite (render_canary.py's docstring warns about exactly
this). Cleaned with an explicit `-name "output.actual.png"` / `"output.difference.png"` delete —
do **not** glob `output.*.png`, it eats the tracked `output.expected.png` goldens.
The delivered worktree is clean apart from the five patched sources and the two deliverables.

---

## 7. New unclaimed leads

1. **AVM1 underlines are still never drawn.** `TextFieldGlyphRun` (`action.h:826-838`) has no
   `underline` field, so the flag `tf_parse_html` already tracks (`action.c:26498`) never
   reaches `tag.c`'s glyph callback or `render_webgpu.c`. No pixel carrier exists in the corpus
   today — it is a browser / real-content correctness gap, not a scored one. The AVM2 collector added
   here (`avm2_edittext_collect_underlines`) is the shape to copy: per-layout-box, box width,
   `ascent + max_descent/2`, one device pixel.
2. **`avm2_draw_border_line`'s rotated arm is now device-correct but has no test.** The only
   corpus rows that reach it (`edittext_border_transform` .04/.06, 51/44 outliers over a limit
   of 20) are at `dscale == 1`, so the `half`/`th` rewrite is unexercised. Those two rows are
   *also* still failing for an unrelated reason and are unclaimed.
3. **`visual/edittext/edittext_gutter` (1032 outliers, `tolerance 128`, limit 0)** is the
   largest remaining non-KF `visual/edittext` row and appears in nobody's brief.
4. **The 12-outlier underline residual** (§2.3) is identical at 1× and 2×, so it is a single
   deterministic sub-pixel rule — probably `len`'s rounding at a run end — and would make both
   comparisons byte-exact.
5. **`ng_getMatrixFromObj_render` is still one call site short of the `[child-xform-table]`
   rule** for its *other* callers. I fixed the EditText path only; w1's §7.3 audit of
   `shape_hit_test.c` hit tests taken while a frame is composing is still open, and the
   `_tid` entry point added here is the tool for it.
