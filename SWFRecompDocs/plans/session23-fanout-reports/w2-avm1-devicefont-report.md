# w2-avm1-devicefont: AVM1 `[fonts.*]` device-font registry (session 23, wave 2, slot F of w1-trace-tail)

**NEW files (repo):** this report and `w2-avm1-devicefont.patch`. No new source, header or fixture files.
**NEW generated file (recompiler output, not in git):** `RecompiledTags/device_fonts.c`. It is emitted only for an
AVM1 main movie whose `test.toml` declares at least one named device face. `verify_output.py` already copies every
`RecompiledTags/*.c`, so no harness, CMake or Emscripten source-list change is needed.

Box: cloud, Ubuntu 24.04, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Base: `origin/master` `823171358`.
Upstream test corpus downloaded at Ruffle master ≈ `aa9f62a70` (`0ddd12b6a` plus one commit; the only test it adds
is `visual/video/vp6_inter_frames`, which is irrelevant here).

## 0. Verdict and expected-flip ledger

**GO. Trace +1, pixels 0.**

| axis | test | before → after | modes |
|---|---|---|---|
| trace | `fonts/device_font_name_case` | output_mismatch → **pass** | graphics **and** no-graphics |
| pixels | (none) | every image row I swept is md5-identical | — |

No other row moves in either mode, in any sweep (§3).

**CI dispatch:** `fonts/` is in the **misc** group, so the flip is only visible with `categories=full`.
- The runtime change is in shared code (`ng_shared.c`, linked into every build), so run **graphics/full and
  no-graphics/full**.
- `images=false` is fine: no render path changed.

## 1. Mechanism

Before the patch:
- The `[fonts.*]` table was emitted only on the ABC path (`abc_timeline.cpp:2256` → `emitDeviceFonts`).
- The AVM1 runtime (no `src/avm2` linked) had no registry.
- `ng_resolveTextFormatFontId` returned 0 (the baked-in Noto) for any non-embedded name.
- As a result, every name in the test measured as the same face: `A=true, B=true` on all 12 lines.

### Recompiler

- `SWFRecomp/src/abc/abc_devicefont.cpp`: the toml parse in `emitDeviceFonts` moved verbatim into a static
  `collectDeviceFonts(faces, aliases)`. `emitDeviceFonts` is unchanged.
- New `emitAvm1DeviceFonts(out)` takes the same rows in the same order (faces, then the `[default_fonts]` aliases).
  - It skips the hidden, outline-only `with_default_font` Noto row, which no name can reach.
  - It emits a header-free C file holding `codes[]` and `advances[]` per face, plus a strong
    `ng_generated_register_device_fonts()` that calls `ng_register_device_font(name, bold, italic, em, ascent,
    descent, leading, codes, advances, n)` once per row.
  - It returns false and writes nothing when there is no named row.
- `SWFRecomp/src/recompilation.cpp`: after `finalizeAbcEmit()`, `if (!swf.is_as3 && !swf.isChildRecompile())`
  writes `RecompiledTags/device_fonts.c` when `emitAvm1DeviceFonts` returns true.
  - The registry is player-level state, so a child movie never emits it.
  - AVM2 keeps its own table.

### Runtime

`SWFModernRuntime/src/libswf/ng_shared.c` gains three things.

**1. A shared name-resolution helper for both VMs (header-free seam).**
- `ng_device_font_ladder(name, len, bold, italic, probe, ctx)` is Ruffle's `FontMap::find` style ladder.
- `ng_device_font_list(...)` does the comma split. It **trims only when the name is a list.** This is upstream
  `b8793d8a6` (2026-10-10, "Don't trim whitespace from single device font names"), which also re-goldened this
  test's two lines `leading space  TestFontA` and `trailing space TestFontA `.
  - `b8793d8a6` is inside the s22→s23 drift window `45366370e..0ddd12b6a`. That is why the w1 report's
    "comma-split, trim" no longer holds for a single name.
  - A first build with the old always-trim rule scored 10/12.
- `probe` is one exact `FontQuery`: case-insensitive, full-length, exact bold and italic. It returns a row index.

**2. An AVM1 device registry.**
- `ng_register_device_font` appends a metrics-only `ng_fonts` slot.
  - Its font ids are reserved: `0xFF00 + k`.
  - It has `is_builtin = 1`, so the glyph renderer draws nothing for it, exactly as for the baked Noto.
  - Two new trailing fields, `ext_codes` and `ext_advances`, point into the generated tables, so a full-BMP face is
    not truncated to `MAX_FONT_GLYPHS`.
  - The three glyph accessors (`ng_font_glyph_advance`, `ng_font_find_glyph`, `ng_font_glyph_advance_by_idx`) read
    through `NG_FONT_CODE` / `NG_FONT_ADV`. Both fall back to the inline tables when the pointers are NULL.
- `ng_generated_register_device_fonts()` is a **weak no-op** in `ng_shared.c`. It is called lazily on the first
  name resolution.
- **Without `device_fonts.c` the registry is empty and every path is the old code.** This covers every AVM2 build
  and every AVM1 test without named faces.

**3. A new fallback in `ng_resolveTextFormatFontId`.**
- Order: embedded lookup (unchanged), then the overflow path (unchanged), then **`ng_resolveDeviceFontId`**.
- A miss in the new step returns 0, the default device font (baked Noto).
- Every AVM1 measurement path already reads `_tf_fontId`, so no `action.c` edit was needed. This avoids the sibling
  `w2-tf-css`'s file entirely. The paths are `extractTextFieldParams` → `ng_computeTextWidth` / `TextHeight` /
  `Scroll`, autoSize and the html run sync.
- The measured advances are that face's own, with the existing device-mode per-glyph pixel rounding.

### AVM2 delegation

`SWFModernRuntime/src/avm2/avm2_text.c` now delegates to the shared helper:
- `find_device_font_ladder` and `find_device_font_list` call `ng_device_font_ladder` / `ng_device_font_list`, with
  `avm2_device_font_probe` wrapping the unchanged `find_device_font`.
- The now-unused local `is_ws` was removed.
- `find_device_font`, `find_default_font_row`, `default_font_outline` and `resolve_font` are untouched.

### Sibling notes

**`w2-stage3d-text` (AVM2 `avm2_text.c` advance rounding):**
- My hunks are confined to `avm2_text.c:~2700-2755`: the two lookup functions and `is_ws`.
- No advance, layout or rounding code is touched.
- The **one behaviour change for AVM2**: a *single* font name with leading or trailing whitespace no longer matches
  a trimmed face. This is Ruffle-current and Flash-correct per `b8793d8a6`.
- No AVM2 corpus row exercises it. All 17 AVM2 `[fonts.*]` rows are trace- and md5-identical (§3).

**`w2-tf-css`:** no `action.c` edit.

## 2. Generated-C proof (recompiler change)

I recompiled **1468 SWFs** from `ruffle-tests/tests/swfs/**` with the before and after binaries, each in a scratch
copy (`test.swf`, `test.toml` and fonts), and md5'd every file in `Recompiled{Tags,Scripts,ABC}/`.
- The set is every AVM1 `test.swf` across all downloaded suites, plus every AVM2 `test.swf` whose toml has
  `[fonts.*]`, `[font_sorts]`, `[default_fonts]` or `with_default_font`.
- Downloaded suites: avm1, avm2, fonts, text, visual, from_gnash, from_shumway, regression.
- 48 of those SWFs have a font toml.
- Every recompile returned rc 0.

**Exactly 7 SWFs changed, and each change is only the ADDED file `RecompiledTags/device_fonts.c`:**

`fonts/device_font_name_case`, `from_gnash/actionscript.all/TextField-v6`, `-v7`, `-v8`,
`from_gnash/misc-mtasc.all/TextFieldTest`, `from_shumway/avm1/text-bind`, `visual/cache_as_bitmap/text`.

- These are precisely the AVM1 SWFs whose toml declares a named `[fonts.*]` face.
- The six besides the headline declare `[fonts.noto_sans] family = "Noto Sans"` plus `[default_fonts]`.
- AVM1 tests that set only `with_default_font` get no file: the hidden row is skipped.
- All 23 AVM2 font-toml SWFs produce **byte-identical** `RecompiledABC/`, which proves the `collectDeviceFonts`
  refactor emits the same output.

## 3. Before/after (same box; before = clean `origin/master` + rebuilt recompiler, both legs `--recompile`)

### Headline + sibling sweep

40 tests: every downloaded row with a font toml in avm1, fonts, visual, avm2, gnash and shumway.

- **Graphics** used `render_canary.py capture`, so the PNG md5s and saved traces come along. Compare result:
  **23/23 PNGs IDENTICAL**. The only trace-text change is `device_font_name_case`.
- **No-graphics** used `verify_output.py` one test at a time. Status and diff-content md5 are identical on every
  row except the headline.

| test | graphics trace before → after | image cmps (md5 A/B) | no-graphics before → after |
|---|---|---|---|
| `fonts/device_font_name_case` | output_mismatch → **pass** | — | output_mismatch → **pass** |
| `fonts/device_font_glyph_fallback` | pass → pass | — | pass → pass |
| `fonts/device_font_kerning` | pass → pass | output:pass→pass (identical) | pass → pass |
| `fonts/device_font_list` | pass → pass | — | pass → pass |
| `fonts/device_font_no_ink` | ruffle_matched → ruffle_matched | output:pass→pass (identical) | ruffle_matched → ruffle_matched |
| `fonts/embed_matching/no_font_found` | pass → pass | output:pass→pass (identical) | pass → pass |
| `fonts/embed_matching/fallback_preferences` | pass → pass | output:pass→pass (identical) | pass → pass |
| `fonts/embed_matching/match_style` | pass → pass | output:pass→pass (identical) | pass → pass |
| `fonts/embed_name_lookup` | pass → pass | — | pass → pass |
| `avm1/device_font_spacing` | pass → pass | — | pass → pass |
| `avm1/edittext_asfunction_case_insensitive` | output_mismatch → output_mismatch (same text) | — | same |
| `avm1/edittext_drag_select` | pass → pass | — | pass → pass |
| `avm1/edittext_hscroll` | pass → pass | — | pass → pass |
| `avm1/gettextextent` | pass → pass | — | pass → pass |
| `avm1/text_format_get_text_extent_undefined_width` | pass → pass | — | pass → pass |
| `visual/text/String_path_variable_button` | pass → pass | output:fail→fail (identical) | pass → pass |
| `visual/filters/bevel` | pass → pass | output:fail→fail (identical) | pass → pass |
| `visual/filters/bevel_full` / `_inner` / `_outer` | pass → pass | pass→pass (identical) | pass → pass |
| `visual/filters/drop_shadow` / `glow` / `glow_with_alpha_strength` / `glow_without_composite_source` | pass → pass | pass→pass (identical) | pass → pass |
| `visual/cache_as_bitmap/text` *(gains device_fonts.c)* | pass → pass | output:pass→pass (identical) | pass → pass |
| `visual/cache_as_bitmap/edittext_scroll` | pass → pass | .01/.02 pass→pass (identical) | pass → pass |
| `from_gnash/actionscript.all/TextField-v6` / `-v7` / `-v8` *(gain device_fonts.c)* | output_mismatch → output_mismatch, **trace byte-identical** | — | same, diff md5 identical |
| `from_gnash/misc-mtasc.all/TextFieldTest` *(gains device_fonts.c)* | ruffle_matched → ruffle_matched, trace identical | — | same |
| `from_shumway/avm1/text-bind` *(gains device_fonts.c)* | pass → pass | output:pass→pass (identical) | pass → pass |
| `visual/edittext/edittext_device_transform_basic` | pass → pass | — | pass → pass |
| `visual/edittext/edittext_device_transform_metrics` | ruffle_matched → ruffle_matched | — | same |
| `visual/edittext/edittext_device_transform_negative` | ruffle_matched → ruffle_matched | output:fail→fail (identical) | same |
| `visual/fonts/device-font` | pass → pass | output:pass→pass (identical) | pass → pass |
| `visual/fonts/font_lookup_as3` | pass → pass | output:fail→fail (identical) | pass → pass |
| `visual/fonts/leading_device_font` | pass → pass | output:pass→pass (identical) | pass → pass |
| `avm2/edittext_device_transform_layout` | ruffle_matched → ruffle_matched | — | same |
| `avm2/bitmapdata_draw` | pass → pass | output:fail→fail (identical) | pass → pass |
| `avm2/bitmapdata_drawwithquality` | pass → pass | — | pass → pass |

**Why the six "Noto Sans" AVM1 rows don't move:** the declared `NotoSans.ttf` and the baked-in Noto (em 1000,
ascent 1069, descent 293) have the same ASCII advances. Routing `"Noto Sans"` / `_sans` / `_serif` names to the
declared face therefore measures the same. The only gain is non-ASCII coverage, which no row exercises.

**Rendering:** AVM1 device slots are metrics-only (`is_builtin = 1`), so no AVM1 glyph is drawn from a test face.
Every image row of the 7 changed-SWF tests is md5-identical; that is the "HOLD the render half" case by
construction. See leads below.

### Standing render canary

`render_canary_tests.txt`, 89 tests, 144 comparisons, `--recompile`, `-P 2`:
- **144/144 IDENTICAL**, 0 DIFFERS, 0 APPEARED or VANISHED.
- No trace-status or image-status change; all 23 saved traces are byte-identical.
- The canary already contains `fonts/device_font_kerning`, `visual/fonts/device-font`, `leading_device_font`,
  `visual/cache_as_bitmap/text` and `from_shumway/avm1/text-bind`, so it sees this change class. No member was added.

### Regression suite

6 text-adjacent fixtures: `avm1_parent_child_text`, `avm2_timeline_text`, `avm2_static_text`,
`avm2_parent_child_static_text`, `avm2_bitmapdata_draw_textfield`, `avm1_display_prop_coercion`.
- **No-graphics:** pass → pass for all six, A/B.
- **Graphics:** all six pass after the change. I did not run them in graphics on clean master; they have no font
  toml, so their generated C is unchanged (§2) and the registry stays empty.
- The canary's 6 `regression/` members are identical as well.
- **No new fixture:** the behaviour is covered by the upstream corpus row `fonts/device_font_name_case`.

## 4. Refutations / premise checks

- **Partly refuted:** the brief said "comma-split, *trim*, …". Since upstream `b8793d8a6` only list entries are
  trimmed. With the brief's rule the headline stays at 10/12.
- **Refuted:** "share `find_device_font_*` rather than copy" cannot be done by linking `avm2_text.c` into AVM1, because
  AVM1 builds never compile `src/avm2`. The shared copy now lives in `ng_shared.c`, which every build links.
- **Confirmed:** no `action.c` change was needed. `_tf_fontId` is the single seam.
- **Fidelity:** I made no absolute pixel claims; every pixel statement here is local A/B md5.

## 5. What is not done (each with its completion mechanism)

- **AVM1 device kerning.** The registry emits no `kern` pairs, so AVM1 never kerns a device face. Ruffle kerns only
  when `TextFormat.kerning` is true, and no AVM1 row needs it today. *Completion:* emit `kern_*` into
  `device_fonts.c` and apply it in `ng_computeTextWidth` when the run's kerning flag is set; this needs a fixture.
- **AVM1 DefaultFont-on-miss.** A miss resolves to the baked Noto (id 0), not to the `[default_fonts]` row for the
  first name (Ruffle `layout.rs:604-635`). The two are identical for every corpus row (they are all Noto Sans).
  *Completion:* port `find_default_font_row` onto the shared helper if a row ever declares a non-Noto default.
- **AVM1 device rendering from test faces.** Slots are metrics-only, so a TestFontA field draws nothing. This was
  already true with the baked Noto. *Completion:* a pixel slot to emit outlines into `device_fonts.c` and teach the
  `tag.c` glyph path a non-`glyph_data` outline source. No graded AVM1 image row needs it today.

## New unclaimed leads

- `getTextFormat().font` / htmlText FACE on the AVM1 **setTextFormat-only** path (`action.c:57671`) reads
  `ng_getFontName(_tf_fontId)`.
  - Before this patch it reported the baked `"Noto Sans"` for any device name.
  - It now reports the registry family's casing for a matched device face.
  - Ruffle reports the format's own string. This is not exercised by the corpus; it is `w2-tf-css`-adjacent.
- The recompiler's `styleLadder` (C++, used by `resolveTestDeviceFontPath`) is a third copy of the ladder. It is
  harmless, but a candidate to share if the ladder changes again.

## LOCAL ORACLE REQUESTS

None.
