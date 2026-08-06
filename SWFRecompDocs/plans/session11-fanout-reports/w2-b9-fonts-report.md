# w2-b9-fonts — implementation report (session 11, wave 2)

Agent: `w2-b9-fonts`. Base HEAD `b4c983ea4`. Worktree
`.claude/worktrees/agent-aa9df5ab6ba44236a`. **No commits, no pushes.**
Spec: `wave1-trace-b8b-b9.md` §"Lead B9" + §"Adjacent … device-font layout
scale".

Deliverables in this directory:
* `w2-b9-fonts.patch` — B9 proper (device-font TTF plumbing).
* `w2-b9-fonts-rider.patch` — the `device_font_scale_x` rider. **Applies on
  top of** `w2-b9-fonts.patch` (its `avm2_text.c` hunks carry patch-1 context
  lines). Touches exactly one file.

---

## Result: +3 pass, +2 ruffle_matched, 0 regressions

| Test | HEAD | after `w2-b9-fonts` | after `+ rider` |
|---|---|---|---|
| `fonts/device_font_kerning` | mismatch 0/4 | **PASS** | **PASS** |
| `fonts/device_font_glyph_fallback` | mismatch 29/36 | **PASS** | **PASS** |
| `fonts/device_font_list` | mismatch 6/64 | **PASS** | **PASS** |
| `visual/edittext/edittext_device_transform_basic` | mismatch 12/24 | mismatch 18/24 | **PASS** |
| `visual/edittext/edittext_device_transform_metrics` | mismatch 20/40 | mismatch 28/40 | **RUFFLE_MATCHED** |
| `visual/edittext/edittext_device_transform_negative` | mismatch 60/120 | mismatch 74/120 | **RUFFLE_MATCHED** |
| `avm2/edittext_device_transform_layout` | mismatch 160/288 | mismatch 206/288 | mismatch 236/288 |

(`x/y` = matching lines / expected lines, the corpus convention. HEAD column is
the wave-1 census, re-confirmed locally for the fonts trio and for `basic`.)

Against the predicted ceiling of +7: **+3 real passes and +2 effective
passes.** `metrics`, `negative` and `layout` are all `known_failure = true`
upstream — Ruffle itself does not produce the Flash expectation, so
`ruffle_matched` is the ceiling for them; two of the three now hit it exactly.
`layout` does not (see "Residual" below). This is the wave-1 report's one
mis-sizing: it costed those four as full flips without checking
`known_failure`.

---

## Patch 1 — `w2-b9-fonts.patch` (B9 proper)

### Files touched
| File | Δ | What |
|---|---|---|
| `SWFRecomp/src/abc/abc_devicefont.cpp` | **new**, ~360 lines | test.toml → device-face tables |
| `SWFRecomp/include/abc/abc_devicefont.hpp` | **new**, 30 lines | one exported symbol |
| `SWFRecomp/CMakeLists.txt` | +1 | source list |
| `SWFRecomp/src/abc/abc_timeline.cpp` | +14 / −4 | one call site + advance widening |
| `SWFModernRuntime/include/avm2/avm2_abc.h` | +21 / −2 | `Avm2FontData` kern/fallback fields, advance widening, 2 externs |
| `SWFModernRuntime/src/avm2/avm2_text.c` | +142 / −22 | device registry, font-list match, per-glyph fallback, kerning |

**`ruffle-tests/verify_output.py` is NOT touched.** The spec proposed
harness→recompiler CLI flags; but the recompiler already runs with
`cwd = test_dir` and already links toml++, so it reads `./test.toml` directly.
That removes the merge collision with the two sibling agents editing
`verify_output.py` at zero cost — the parse is wrapped in `try/catch` and a
missing or invalid `test.toml` yields an empty table.

### What it does
1. **Recompiler** (`abc_devicefont.cpp`) parses `[fonts.KEY] {family, path,
   bold, italic}` and `[font_sorts.KEY] {family, bold, italic, sort=[keys]}`,
   loads each TTF with the already-vendored stb_truetype, and emits
   `avm2_generated_device_fonts[]` + `avm2_generated_device_font_count` into
   `RecompiledABC/abc_timeline.c` — **main movie only**, since device fonts are
   player-level state and a symbol-prefixed child recompile would duplicate the
   symbol. Per face: em square, ascent/descent/leading, the whole BMP cmap as
   codes+advances, `kern` pairs (in character codes), and the font_sorts chain
   as indices into the same table.
2. **Runtime** (`avm2_text.c`) gains `find_device_font` (case-insensitive, the
   FontQuery tuple), `find_device_font_list` (comma split + trim, first hit
   wins for the whole span), `resolve_glyph_units` (main face then the sort
   chain, returning the RESOLVING face so *its* em square scales the advance —
   Ruffle `scale = height / resolution.font.scale()`), `kerning_units`, and
   `kerning_enabled` (device faces kern unconditionally, `font.rs:889`).
   Kerning is peeked only inside the current run, so it never crosses a
   box/span boundary, matching `Font::evaluate`.

### Both spec gotchas were real
* **GPOS vs `kern`.** Used `stbtt_GetKerningTable` (the `kern` table,
  horizontal, format 0) instead of `stbtt_GetGlyphKernAdvance`, which prefers
  GPOS. `device_font_kerning/TestFont.ttf` carries **both** a `kern` table and
  a GPOS lookup, so the wrong call would have been silent here and wrong
  elsewhere.
* **hhea → OS/2 ladder.** Implemented ttf_parser's exact ladder
  (`lib.rs:1499-1585`) over a hand-rolled table-directory reader, because stb
  exposes neither `unitsPerEm` nor `fsSelection`. Both arms matter, and the
  *primary* one is the one the report did not name: every corpus TestFont sets
  **OS/2 v4 + `fsSelection` bit 7 (USE_TYPO_METRICS)**, so typo metrics win
  outright. `device_font_list/TestFontB` has `hhea 666/−200` but
  `typo 800/−200`, and only the typo pair reproduces the expected output. The
  `hhea == 0 → typo → usWin` fallback arm the report flagged also fires, on
  `device_font_kerning/TestFont` and `device_font_list/TestFontA`.

### One extra defect found — required for `device_font_list`
`Avm2FontData.advances` was `int16_t` and `abc_timeline.cpp` read the SWF
ADVANCETABLE as `(int16_t) body.u16()`. **The SWF advance table is UNSIGNED
u16** (Ruffle `swf/src/read.rs:1079`; `swf::Glyph::advance: u16`). A upem-1000
face with a 1600-unit advance, embedded at em 20480, lands on exactly 32768 and
was stored as `-32768` — `device_font_list`'s `EmbeddedTestFontA` measured
−32 px instead of 32. Widened to `int32_t` (struct field, generated array,
`noto_advances`). This accounts for **8 of that test's 16 missing lines and is
an *embedded*-font bug, not a device-font one**; it is latent for any DefineFont
face with an advance ≥ 32768.

### Acceptance arithmetic (all reproduced by actual output)
* kerning: 4×1000 + (1000 − 500 + 500) = 5000 units = 5 em × size 10 = **50** —
  and it only lands on 50 because the `kerning = false` field kerns too.
* fallback: 500/1000 × 10 = ascent **5**, descent **5**; char0 w **10**;
  char1 x **12** via the TestFontB sort entry.
* list: 1600/1000 × 20 = **32** (TestFontA), 1500/1000 × 20 = **30**
  (TestFontB).

### Risk gating
With no `[fonts.*]` declared, the device table is empty,
`find_device_font_list` returns NULL on its first probe, and `resolve_font`
reaches the same `noto_device_font` it reached before — byte-identical for the
4400+ tests that declare nothing. Only 17 test.tomls in the corpus declare
`[fonts.*]`.

---

## Patch 2 — `w2-b9-fonts-rider.patch` (device-font layout scale)

One file, `SWFModernRuntime/src/avm2/avm2_text.c` (+95 / −8).

`et_device_font_scale_x()` walks the parent chain (stopping at the Stage, per
`display_object.rs:1493`) accumulating the 2×2 block and returns `m.d / m.a`,
gated on `et->device_font`. Applied at the Ruffle call sites:

| Ruffle | ours |
|---|---|
| `relayout` → `local_width_to_layout_width(bounds.width())` | `et_relayout` content width |
| `relayout` → `layout_width_to_local_width(text_size.width())` | `et_relayout` autosize width |
| `line_metrics` → `layout_to_local_matrix * bounds` | `txt_get_line_metrics` x + width |
| `char_boundaries` → `layout_to_local_matrix * bounds` | `txt_get_char_boundaries` x_min/x_max |
| `measure_text` → `layout_to_local_matrix * text_size` | `txt_get_text_width` |

Layout-space x rounds **ties-to-even into an int32 before** the gutter is
added, matching `render/src/matrix.rs:301` (`round_to_i32`) — the
integer-twips rule.

`Avm2EditTextExt` gains an `owner` back-edge, set at its single allocation
site, so the ext can reach its DisplayObject's matrix. Pure back pointer: the
object owns the ext, so it is never a GC root and never keeps anything alive.

Deliberately **not** touched: `getCharIndexAtPoint`. Ruffle routes it through
`local_to_layout`, but its own expected output is scale-invariant and we
already match it; touching it would move us *off* `output.ruffle.txt`.
Also **not** touched: the relayout trigger set. Ruffle's `EditText::set_matrix`
does *not* relayout, so a scale change after the last text mutation leaves the
layout as-is and only the read paths rescale — our eager-relayout-on-mutation
model already reproduces that ordering.

The whole rider is the identity when `a == d`, i.e. for every uniformly-scaled
field in the corpus.

---

## Canaries — all run with BOTH patches applied, all PASS

| Canary | Why it was chosen | Result |
|---|---|---|
| `avm2/edittext_getcharboundaries` | the rider's main read path | PASS (also PASS in `--mode=graphics`) |
| `avm2/edittext_getlinemetrics` | the rider's other read path | PASS |
| `avm2/edittext_autosize` | the rider's `layout_width_to_local_width` arm | PASS |
| `avm2/edittext_bounds_scale` | scaled EditText bounds — worst case for `d/a` | PASS |
| `avm2/bitmapdata_draw` | declares Noto Sans as a device font | PASS |
| `visual/fonts/device-font` | declares Tinos regular+bold (OS/2 v3, no USE_TYPO) | PASS |
| `visual/fonts/leading_device_font` | declares TestFontGap0/Gap100 (line-gap probe) | PASS (also PASS in `--mode=graphics`) |
| `from_shumway/avm1/text-bind` | declares Noto Sans; AVM1 path | PASS |

`avm2/bitmapdata_draw` and the two `visual/fonts/*` have EMPTY expected trace —
they are image-axis tests, so their PASS proves only "no crash, no trace
regression".

## Mode parity and the pixel axis

Both modes were run on the fonts trio, `edittext_device_transform_basic`,
`edittext_getcharboundaries` and `visual/fonts/leading_device_font`. **Identical
trace status in every case, no asterisks.**

**No pixel movement at all.** The wave-1 report predicted image-comparison
churn once real metrics landed. It does not happen, because the generated
device rows carry NULL outline pointers by design (device glyph *outlines* are
still T3, `wave1-gfx-text-phase.md §A.3`), so device text still paints nothing
and only its measurement changed. Measured against the `c4496a4c8` baseline
`image_results_graphics.json`, outlier counts are byte-identical:

| Test | baseline outliers / max_diff | with both patches |
|---|---|---|
| `fonts/device_font_kerning` | 1680 / 255 | 1680 / 255 |
| `visual/edittext/edittext_device_transform_basic` | 2400 / 255 | 2400 / 255 |
| `visual/fonts/leading_device_font` | 12978 / 255 | 12978 / 255 |

---

## Residual: why `edittext_device_transform_layout` does not flip

After both patches it is 236/288, with **32 lines left against
`output.ruffle.txt`** — i.e. 32 lines short of `ruffle_matched`. All 32 sit in
the `autoSize=center` / `autoSize=right` groups and all have this shape:

```
ruffle    0: (x=22, y=2, w=8, h=10)
ours      0: (x=2,  y=2, w=8, h=10)
```

Cause: our layout→local conversion adds only `GUTTER`, while Ruffle's
`layout_to_local_matrix` translates by `bounds.x_min + GUTTER`
(`edit_text.rs:774-790`). After an autosize-center relayout the field's
`bounds.x_min` becomes 20, so every char x is 20 twips short. This is a
**pre-existing gap unrelated to B9** (it reproduces at scale 1) and closing it
moves `getCharBoundaries`/`getLineMetrics` for every AVM2 EditText whose bounds
rect has a non-zero `x_min` — a blast radius that does not belong in this
batch. Clean, fully-specified follow-up worth ~1 effective pass.

A second, smaller residual: the `Text align, align=right` rows expect `x=41.95`
where we emit `42` — a right-margin rounding difference, also pre-existing and
outside B9.

---

## Merge risks

1. **`verify_output.py` is untouched** — deliberately, so there is zero
   collision with the two sibling agents editing it.
2. **`SWFRecomp/src/abc/abc_timeline.cpp`** is shared with the B8b agent (the
   wave-1 report predicted this). My edits there are three small, well-separated
   hunks: one `#include`, one `emitDeviceFonts(out)` call immediately after the
   `avm2_generated_font_count` line, and the `int16_t → int32_t` advance
   widening in `FontDef` plus its two uses. B8b adds *frame* arrays in a
   different emit region. Expect a trivial merge; sequence B9 first if in doubt.
3. **`SWFRecomp/CMakeLists.txt`** gains one source line next to
   `abc_timeline.cpp`. It is the only build-system source list in the repo that
   names `abc_timeline.cpp` (checked).
4. **`Avm2FontData` grew six trailing fields.** Every existing initializer —
   the generated `avm2_generated_fonts[]`, per-movie child tables, and the
   static `noto_device_font` — supplies fewer initializers than the struct has
   fields, and C zero-fills the rest, so no other emitter needed changing. But
   **any sibling adding a field to `Avm2FontData` must append after mine**, or
   the generated positional initializers shift.
5. The recompiler is touched → **every local verification needs `--recompile`**
   and all cached `RecompiledABC/` under the mirrored suites is stale.
6. Suggested CI for the merged batch: `graphics`, `categories=full` (AVM2
   runtime + recompiler emission — standing policy), `images=false`.

## Dispositions

None of the seven targets appears in `ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md` or
`FLASH_BUGS_REPLICATED.md`, and none is in an `ignored_tests.txt` except
`avm2/edittext_device_transform_layout` (filtered-only; the unfiltered 4424
denominator still counts it). **No disposition doc needs updating** — nothing
here is an accepted diff; `metrics`/`negative` reaching `ruffle_matched` is the
ordinary upstream-`known_failure` outcome the harness already models.

---

## Raw run log

```
                                        no-graphics        graphics
fonts/device_font_kerning               PASS               PASS  (image 1680, = baseline)
fonts/device_font_glyph_fallback        PASS               PASS
fonts/device_font_list                  PASS               PASS
visual/.../device_transform_basic       PASS               PASS  (image 2400, = baseline)
visual/.../device_transform_metrics     RUFFLE_MATCHED     -
visual/.../device_transform_negative    RUFFLE_MATCHED     -
avm2/edittext_device_transform_layout   MISMATCH 236/288   -
avm2/edittext_getcharboundaries         PASS               PASS
avm2/edittext_getlinemetrics            PASS               -
avm2/edittext_autosize                  PASS               -
avm2/edittext_bounds_scale              PASS               -
avm2/bitmapdata_draw                    PASS               -
visual/fonts/device-font                PASS               -
visual/fonts/leading_device_font        PASS               PASS  (image 12978, = baseline)
from_shumway/avm1/text-bind             PASS               -
```
