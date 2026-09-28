# w2-noto-d1 — `with_default_font` outlines (lead D1)

**NEW FILES: none.** There are two patches, both against master `12733c3f0`, and they stack:
- `w2-noto-d1.patch`: **outlines only, no metric change** (the gate the brief asked for). It touches
  `SWFRecomp/src/abc/abc_devicefont.cpp` and `SWFModernRuntime/src/avm2/avm2_text.c`.
- `w2-noto-d1-2-metrics.patch`: applies on top of the first and touches `avm2_text.c` only. It gives
  **device fields in `with_default_font` tests only** Noto's true ascent and descent. This one needs your
  decision, because it is a metric change. It is priced below and its trace rows are measured unchanged.

**Worktree.** The isolation guard refused `git -C <main> worktree add`, so I could not create the requested
`w2-noto-d1` worktree. Instead I fast-forwarded my own worktree (`.claude/worktrees/agent-a984e8c2cb85bc74d`)
to master `12733c3f0`. Before doing that I confirmed that my A1 and cap patches were in `a3e7d2858`, then
dropped their uncommitted copies. Nothing was committed.

## Verdicts

| item | verdict | flips |
|---|---|---|
| D1 outlines only (`w2-noto-d1.patch`) | **GO** | 0 flips; big band moves (table below) |
| D1-2 scoped real Noto ascent/descent (`-2-metrics`) | **GO if you accept a metric change scoped to `with_default_font` device fields** | **`avm2/bitmapdata_applyfilter_colormatrix` 7419 → 0 (FLIP)**; `avm2/bitmapdata_applyfilter_blur` 28871 → 0 (its image-axis ACCEPTED_DIFFS entry can then be retired, which is a second pixel pass) |
| The filters rows (`bevel_inner`, `bevel_outer`, `bevel_full`, `glow_with_alpha_strength`) | **REFUTED as a D1 target** | 0. These are AVM1 SWFs. Their missing labels are *embedded* static text, not the default font (§3) |
| `stage3d_texture`, `stage3d_fractal`, `stage3d_bitmap` | text now draws, rows do not move meaningfully | 0. Stage3D phase B (textures) owns them |

## 1. Mechanism

- **Recompiler.** When `[player_options] with_default_font = true`, `emitDeviceFonts` appends
  `SWFRecomp/assets/NotoSans.ttf` (byte-identical to Ruffle's bundled subset). It goes through the A1 emitter
  (same truncate, Levien 2.0 flattening and rounding) as a **NULL-named row** at the end of the device table.
  - `find_device_font` skips NULL names, so no by-name lookup can resolve to it and no layout number changes.
  - It is appended after all `[fonts.*]` rows, so `font_sorts` indices are unchanged.
  - **Size cap.** Codepoints are limited to the runtime's baked `noto_codes[]` list (115 glyphs, mirrored in
    `DEFAULT_FONT_CODES`, with a "keep in sync" note). The layout can only place those glyphs, so emitting
    more would never be drawn. That is about 37 KB of generated C per `with_default_font` test.
  - The font path search is the same as `swf.cpp`'s `loadDeviceFont`.
- **Runtime** (`resolve_font`'s final fallback). This is the baked metrics-only `noto_device_font` path. It
  now sets `f.outline` to that NULL-named row. That is the same shapes-only borrow A1b uses: advances, kerning
  and line metrics still come from the baked face.
  - **Device fields only.** An `embedFonts` field whose name misses also lands here. Flash draws nothing for
    those: `fonts/embed_matching/no_font_found` is a `known_failure` whose Flash golden is blank.
  - Ungated, the borrow moved that row **0 → 22626 (pass → fail on a KF row, i.e. drifting onto Ruffle's
    known-wrong output)**. Gated, it stays md5-identical to base.
  - The cost of the gate: `visual/fonts/font_lookup_as3`, whose golden is Ruffle's own fallback, lands at
    19704 instead of 12240. It fails its budget of 72 either way.
- **D1-2.** The baked face's 21931/5973 per 20480 em came from a Flash DefineFont3 embedding. Real Noto hhea
  is 1069/293 per 1000, which is 21893/6000 on the baked em. `swf.cpp`'s AVM1 zero-glyph synthesis already
  uses exactly those numbers. With the outlines drawn, the colormatrix and blur residual is **only** the text
  baseline, one twip off, which lands on pixel centres. D1-2 changes ascent and descent only, and only when
  the field is a device field **and** the NULL-named row exists (that is, the test sets `with_default_font`).
  Advances and leading stay baked.

## 2. Measurements (local Dawn, graphics mode, `--recompile`, `-P 2`, `SWFRECOMP_COMPILE_TIMEOUT=2400`)

| comparison | budget | base (master) | D1 outlines | D1 + D1-2 |
|---|---|---:|---:|---:|
| `avm2/bitmapdata_applyfilter_colormatrix` | tol 2 / 0 | 7419 | 269 | **0 PASS** (max diff 1) |
| `avm2/bitmapdata_applyfilter_blur` (dispositioned) | 0 | 28871 | 619 | **0** (max diff 2) |
| `visual/fonts/font_lookup_as3` | tol 1 / 72 | 34632 | 19704 | 19584 |
| `fonts/embed_matching/no_font_found` (KF) | 0 | 0 PASS | 0 PASS (md5 = base) | 0 PASS (md5 = base) |
| `avm2/stage3d_texture` | 117 | 206968 | 205066 | 204784 |
| `avm2/stage3d_fractal` | 100 | 1101100 | 1099470 | 1099378 |
| `avm2/stage3d_bitmap` | 24 | 136586 | 135413 | 135413 |

The colormatrix residual under D1 alone was all in the three text rows (y 90–99, 310–319, 530–539), with
2 px per glyph on the top edge. That is the baseline offset D1-2 removes.

**Trace gate.** Every AVM2 `with_default_font` trace row was run after both patches, and each status equals
the CI baseline (`_results/results_graphics.json`):

| test | status after both patches | matching lines |
|---|---|---|
| `edittext_at_point_methods_basic` | pass | 16/16 |
| `edittext_mouse_selection` | pass | 363/363 |
| `edittext_scrollh` | pass | 10/10 |
| `edittext_getcharboundaries_missing_embedded_font` | ruffle_matched | 4/7 (embed field, so D1 and D1-2 do not apply) |

All image rows in the table above also keep trace = pass. The AVM1 `with_default_font` rows (`device_font_spacing`, `gettextextent`,
`edittext_drag_select`, `edittext_hscroll`, `text_format_get_text_extent_undefined_width`, the filters rows)
cannot move: their generated C is byte-identical, and the runtime change is AVM2-only.

**Generated-C A/B** (old vs new recompiler, byte for byte, over 97 tests: standing canary, text regression
fixtures, every `[fonts.*]` test and every `with_default_font` test):
- Only the 12 AVM2 `with_default_font` tests differ, and only in `RecompiledABC/abc_timeline.c`.
- The one exception, `away3d_advanced_shallow_water_demo`, also differs in `RecompiledTags/draws.c`. That is
  **pre-existing nondeterminism**: base against base differs in the same file.

Every other test, including all regression fixtures, is byte-identical. The runtime arm is inert when no
NULL-named row exists. `regression/avm2_bitmapdata_draw_textfield` and `avm2_timeline_text` pass under
graphics mode with both patches applied.

The w2-filters-snap prototype was **not stacked**. None of the rows D1 moves are AVM1 filter rows (§3), so
stacking it would add nothing to this pricing.

## 3. Refutation: the filters rows' missing labels are not the default font

`visual/filters/bevel_inner`, `bevel_outer`, `bevel_full` and `glow_with_alpha_strength` are **AVM1 SWFs**
(v15). Their `_sans` EditText labels ("Alpha", "0.25", "0.5", "0.75") **already render**, because
`swf.cpp`'s zero-glyph synthesis draws them from Noto.

What is missing is "50%", "100%" and "200%". Those are **DefineText static text in font 10, `_sans_v`**, a
DefineFont3 that **embeds all 12 of its glyphs**. The vertical "Strength", in the same font, *does* render.
Placement tree:

| sprite | depth 0 | depth 1 | depth 2 |
|---|---|---|---|
| 13 ("Strength") | char 10 (the font itself) | text 11 | text 12 |
| 19, 22, 25 (the digits) | text 17 / 20 / 23 | text 18 / 21 / 24 | — |

So each digit text sits at **depth 0**, and the only text that renders sits at depth ≥ 1. **Lead F1:** check
whether AVM1 sprite placements at depth 0 are dropped. It lives in `tag.c` / display-list territory
(w2-px-a/b), not the font emitter. The w1-filters-snap estimate (≈ 4 230 channels, ≈ 74 %) stays with this
different owner.

## New unclaimed leads

- **F1**: the AVM1 depth-0 static-text placement above. It covers the four filters rows' label residual.
- **D1-2 follow-up**: if D1-2 lands, retire the `avm2/bitmapdata_applyfilter_blur` image-axis entry in
  `avm1/_investigation/ACCEPTED_DIFFS.md`. Its stated residual is the default-font text, and it is now 0.
- **D1-3**: `font_lookup_as3`'s remaining 19.6k channels come from the embed-miss rows (Ruffle draws its
  fallback, Flash draws nothing, and the goldens disagree: `no_font_found` versus this row) plus the real
  advances. Out of budget either way. No action.
- **Stage3D text rows**: text now draws, but the rows are owned by Stage3D phase B (texture upload/sampling).
  D1 has done its part.
- **Determinism**: `away3d_advanced_shallow_water_demo`'s `RecompiledTags/draws.c` differs between two runs
  of the same recompiler binary. That is a recompiler nondeterminism bug that nobody tracks yet.
