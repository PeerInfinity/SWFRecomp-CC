# w1-pixel-text: pixel axis, text rows (session 25, wave 1)

**New files (both under `session25-fanout-reports/`):** `w1-pixel-text-report.md` (this file) and
`w1-pixel-text-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp`, 109 lines; sources reverted on
the branch). There are no new source files and no new fixtures.

**Environment:** cloud box, `SETUP_STATUS` all OK (apt, Pillow, Dawn on lavapipe). Base `origin/master` `ca14fe02`.
Tests come from upstream Ruffle master at download time (categories `from_shumway visual text fonts avm1 avm2`). A
blobless Ruffle clone made in the same hour is at **`3ac8dcb07`**, which is the current upstream named in the brief. No
row below is in the `bcac30c19..3ac8dcb07` drift list.

**CI fidelity, proven on every row.** For all 13 rows (14 comparisons), the before render is **md5-identical** to CI's
actual PNG on `origin/ruffle-image-results` (images run `44986836161`). Every outlier count reproduces the baseline JSON
exactly. All numbers below are CI-grade.

---

## Verdicts (lead)

| group | row | mechanism | owner | verdict | before → after (CI-grade) |
|---|---|---|---|---|---|
| **A** | `visual/edittext/edittext_device_transform_basic` (embedded) | **layout→local transform**: the device-font `scale(d/a, 1)` is never applied at render | `avm2_display.c` `avm2_render_text` | **GO, prototyped** | t128 1020 → **12** (limit 14), t0 1032 → 24 (limit 90): **fail → pass** |
| **A** | `visual/edittext/edittext_device_transform_negative` | same | same | **GO, prototyped** | t128 1032 → **24** (limit 30): **fail → pass** (trace stays `ruffle_matched`) |
| **B** | `visual/edittext/edittext_gutter` | **clip**: an inverted gutter mask on fields < 4 px wide, plus the zero-width border strip | `avm2_display.c` `avm2_render_text` + `avm2_render_textbox` | **GO, prototyped** | 1014 → **0** (limit 0, tol 128): **fail → pass** |
| C | `from_shumway/acid/acid-text` | **layout**: DefineFont3 kerning table never emitted or applied on the AVM1/timeline EditText path | `SWFRecomp/src/swf.cpp` (~2776, ~3056: kerning skipped) + AVM1 advance loop | **HOLD, M-priced, likely +1** | 3429 (tol 0); not prototyped |
| D | `visual/text/String_path_variable_button` | **binding** (not raster): a variable-bound EditText inside a DefineButton2 record never binds | `action.c` `actionTryBindTextFieldVariable` / button record instantiation | **HOLD, M** (collides with `n-play-game`'s button code) | 999 (tol 0, limit 12); shows "Broken", golden "Working" |
| E | `visual/fonts/font_lookup_as3` | **font resolution conflict**: Ruffle-rendered golden vs Flash's `no_font_found` | `avm2_text.c` `resolve_font` | **NO-GO** (disposition: `RUFFLE_VS_FLASH_DIFFERENCES`) | 11592 (tol 1, limit 72) |
| F | `from_shumway/hardwrap`, `stylesheet`, `captions`, `flash_text_TextField` (all KF) | **glyph source**: device-font text (`_sans`, Times, Arial) with no `with_default_font`; the goldens are Flash on Windows system fonts | n/a | **NO-GO** | Ruffle renders these the same as us (blank glyphs) |
| G | `acid-text-4`, `acid-text-5`, `acid-textfield` (all KF, tol 0) | **glyph raster**: Flash's advanced (CSM/FlashType) anti-aliasing at tol 0 | n/a | **NO-GO** | ours vs Ruffle's own render: 435 / **0** / 6463 channels; Ruffle fails them too |
| — | `visual/static_text_offstage` 9600, `acid-color-0` 17323 | unchanged from s24 (§3c AVM1 `BitmapData.draw` timeline arm; JPEG3 alpha + premultiplied sampling) | bitmap slot | not re-diagnosed (s24 report stands) | — |

**Priced flips for wave 2: +3 certain** (`edittext_device_transform_basic`, `edittext_device_transform_negative`,
`edittext_gutter`). All three are measured CI-grade with 0 trace moves and a firing-probe-backed sweep (below). There is one
further **likely +1** (`acid-text`, kerning, M) that should be measured before it is funded.

Zero-headroom rows are **md5-identical**: `text-bind`, `fallback_preferences` and `edittext_border_filters` (still 0/17).

---

## A. Device-font text under a non-uniform scale (`edittext_device_transform_basic`, `_negative`)

- **Golden:** a device-font field (`embedFonts = false`, `[fonts.test_font]` registered as a device face) at
  `scaleX = 2, scaleY = 1` draws its glyphs **unscaled**. At `scaleX = 1, scaleY = 2` it draws them **2× in both axes**.
  Device glyphs scale uniformly by the concatenated y scale. Ours applied the full field matrix, so the glyphs came out
  stretched 2× horizontally in row 2 and 2× vertically only in row 3 (the two L-shaped diff blocks at (110..136, 52..124)).
- **Ruffle:** `edit_text.rs:792-815`. `device_font_scale_x = m.d / m.a` over `local_to_global_matrix`, and
  `layout_to_local_matrix = translate(bounds.x_min + GUTTER - hscroll, …) * scale(device_font_scale_x, 1)`. Glyphs, and
  everything else drawn inside the `transform_stack.push(layout_to_local)` at `:2766`, go through it. The box and the mask
  do not.
- **Ours:** `avm2_text.c` already ports the **layout** half (`et_device_font_scale_x` ~3871, `local_w_to_layout_w`,
  `layout_x_to_local_x`), which is why the traces pass. The **render** half was missing: `avm2_render_text` drew the
  collected placements under the plain field `world`.
- **Prototype:** new `avm2_edittext_device_layout_sx(ctx, obj, &off_x)` in `avm2_text.c` returns `scale_x` (1 for
  embedded fields) and the layout x origin. When `scale_x != 1`, `avm2_render_text` builds
  `gworld = world · T(off_x,0) · S(sx,1) · T(-off_x,0)` and allocates its own transform slot through `avm2_text_slots`. It
  draws the glyphs and the underlines with `gworld`. The box, the clip rect, the selection and the caret stay on `world`,
  as in Ruffle.
- **Residual after the patch:** only the box bottom-right corner pixels. Embedded box: golden 111 vs ours 64 (tol-0 only).
  Device box: golden 0 vs ours 255, which gives 12 / 24 channels at tol 128, inside the limits of 14 / 30. **Do not chase
  those corners:** the device-box BR corner is deliberately dropped for `visual/fonts/leading_device_font` (s21 w2-px-d;
  `avm2_render_textbox` comment), whose golden is blank there. The two goldens disagree, and the test limits absorb it.
- Reflected device fields in `_negative` are still culled (Ruffle `render_self:2720`), which is unchanged and matches.

## B. Narrow-field clip and the zero-width border (`edittext_gutter`)

- **Golden:** fields of width 0..8 px holding one glyph each. Ours drew the glyph **unclipped** for widths 0..3, as thick
  black bars across the neighbouring fields (1008 of the 1014 outlier channels).
- **Ruffle:** `edit_text.rs:2757` `mask_bounds = bounds.grow_x(-GUTTER)`, then `create_box_from_rectangle`. `grow_x`
  does **not** normalise (`rectangle.rs:169`), so a field narrower than `2*GUTTER` (80 tw = 4 px) gives an **inverted**
  rect that `create_box_from_rectangle` draws reflected, covering `[x_max, x_min]`. A width of exactly 4 px gives an empty
  mask.
- **Ours:** `has_clip = (n > 0 && clip[2] > 0 && clip[3] > 0)` dropped the mask for every non-positive width and drew the
  glyphs unclipped.
- **Prototype hunk 1:** normalise a negative clip width (`x += w; w = -w`). If the width is 0 or the height is ≤ 0, skip
  the glyph draw (`clip_empty`). Result: 1014 → **6**.
- **Prototype hunk 2:** the last 6 channels are the two width-0 fields. Our border inked row `y+h`; the golden stops at
  `y+h-1`. A zero-width box degenerates the `[0,1,2,3,0]` LineStrip into a single vertical segment drawn down and back
  up. A line segment inks its start pixel but not its end pixel, so the only ink is one column over rows `y..y+h-1`. The
  `bw == 0 && bh > 0` arm in `avm2_render_textbox`'s axis-aligned `draw_text_box` branch draws exactly that. Result: 6 →
  **0** (max diff 128, the antialiased top and bottom rows of wider fields, under tol 128).

## Sweep (md5 / firing-probe)

- **Firing probe.** A temporary env-gated probe was added to each changed branch (`dev_sx`, `clip ≤ 0`, `bw0`), and the
  after-leg was run over every **image-graded AS3 test that mentions TextField / flash.text** (98 tests across
  `avm2`, `visual`, `fonts`, `text`, `from_shumway`) plus every other graded row under `visual/edittext`,
  `visual/fonts`, `text` and the AVM2 `*text*` rows (18 more, mostly AVM1). That is **116 tests**. A branch fired in
  **only the 3 headline tests**. Every other test runs byte-identical code, apart from one non-firing compare. Every probe
  run produced an image verdict, so there are no build-failure false negatives.
- **md5 A/B** (`render_canary` capture/compare, clean `origin/master` → patch) over a control set of 14 tests / 26
  comparisons: the 3 headliners, `device_transform_small_rotation`, `device_transform_small_shear`,
  `edittext_border_filters`, `fallback_preferences`, `text-bind`, `leading_device_font`,
  `edittext_autosize_height_dynamic`, `edittext_selection_leading`, `acid-text` and `acid-textfield`.
  (`device_transform_metrics` has no image comparison.) Result: **22 IDENTICAL, 4 DIFFER**. The 4 are exactly the ledger:
  the 3 flips plus the ignored `freetype__output` twin of `_basic`. Trace status changes: **none**.
- **regression suite:** `avm2_bitmapdata_draw_textfield`, `avm2_parent_child_static_text`, `avm2_static_text`,
  `avm2_timeline_text` and `avm1_parent_child_text` all PASS in graphics mode.
- **Mode parity:** no `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arm is touched. `avm2_text.c` only gains a function.
  `edittext_device_transform_basic` passes no-graphics trace.

### EXPECTED-FLIP LEDGER (for wave 2 / coordinator)

| axis | test | before → after | expected CI move |
|---|---|---|---|
| pixel | `visual/edittext/edittext_device_transform_basic` `embedded__output` | 1020/14 @t128, 1032/90 @t0 → **12**, 24 | **fail → pass** |
| pixel | `visual/edittext/edittext_device_transform_basic` `freetype__output` | ignored → ignored (render moves) | none (ignored) |
| pixel | `visual/edittext/edittext_device_transform_negative` | 1032/30 @t128 → **24** | **fail → pass** |
| pixel | `visual/edittext/edittext_gutter` | 1014/0 @t128 → **0** | **fail → pass** |
| trace | none | — | none |

**Canary:** append `visual/edittext/edittext_gutter` (tier 1 once it passes; it sees the clip/border hunks) and
`visual/edittext/edittext_device_transform_basic` (sees the device layout transform). No current member fires either
branch, as the probe shows.

**Wave-2 patch scope:** `SWFModernRuntime/src/avm2/avm2_display.c` (`avm2_render_text`: `gworld` slot + clip
normalisation / `clip_empty`; `avm2_render_textbox`: `bw == 0` arm; one prototype declaration), and
`SWFModernRuntime/src/avm2/avm2_text.c` (`avm2_edittext_device_layout_sx`, placed just above
`avm2_edittext_collect_glyphs`). No `tag.c`/`action.c` (AVM1) code is touched, so there is no overlap with
`n-play-game`. Cleanup: declare the new function in the same block as `avm2_edittext_collect_glyphs`, or in a header,
instead of the prototype's local extern. The `gworld` slot also allocates an unused cx slot through `avm2_text_slots`;
either pass the existing `cxid` or add a transform-only helper. The AVM1 twin of the inverted-mask case
(`tag.c textfield_glyph_render_cb`) was not checked, and no graded AVM1 row needs it.

---

## C. `acid-text`: kerning on the timeline EditText path (HOLD, M, likely +1)

- `acid-text` is an AS3-flagged SWF with **no DoABC**. Its three DefineEditText fields render through the **AVM1/timeline
  text path**: a probe in `avm2_text.c char_advance` never fired. Ruffle passes this row at tol 0 (not KF).
- All 3429 diff channels are ≥ 128 (aliased, quality low): whole glyphs sit at different pixels. Ink-column census, field
  1 (Tahoma 30 px): the golden's `W` and `o` **touch** (78..117 is one run), while ours are separate (W 78..102, o
  105..119). Every later glyph is 2–3 px right. Field 2 (MetaBold) does the same at `Wo`. Each shift starts **right after
  a kerning pair** (`Wo` −1520/20480 em ≈ −2.2 px at 30 px; MetaBold `Wo` −600, `r d` −400, …).
- The HTML sets `kerning="1"` (SWF 21, so ≥ 8). Ruffle `font_like.rs:109-118` adds the DefineFont3 kerning pair to the
  advance **before** scaling when `params.kerning` is set. Our recompiler **skips** the DefineFont2/3 kerning table on the
  AVM1 font emit (`SWFRecomp/src/swf.cpp` ~2776 and ~3056, "Skip any remaining data (bounds table, kerning, etc.)"), and
  the AVM1 layout has no kerning term. Run `kerning` is tracked only for htmlText/getTextFormat serialisation
  (`action.c` ~28042). The AVM2 path has it (`avm2_text.c kerning_units`, fed by the ABC device-font emitter only).
- **Completion mechanism:**
  1. Emit `(left_code, right_code, adjustment)` per font in `swf.cpp`, as a trailing table on the runtime font record.
  2. Add `kerning_units` to the advance in the AVM1 glyph loop **and** in its measurement/wrap twins (`textWidth`,
     autosize, word wrap), gated on the run's `kerning` flag. Ruffle applies kerning to device faces regardless; the AVM1
     device path has no kern table, so that is moot.
  3. `--recompile` sweep over every graded AVM1 EditText row with `kerning="1"` HTML, plus a **trace** sweep on
     `textWidth`/`getCharBoundaries` rows: this changes AVM1 layout widths, so trace risk is real.
- **Price:** M (~80–120 LOC across recompiler and runtime). The flip is likely but **unmeasured**: the tol-0 raster on
  this path is already exact elsewhere (s23 `acid-text-escape` passes at tol 0), but field 3 (`Hello`/`World` in two `<p>`)
  also differs and was not attributed. Measure before funding.

## D. `String_path_variable_button`: a bound text field inside a button (HOLD, M)

- The golden reads "Working" and ours reads "Broken". This is a **behaviour** gap, not raster. DoAction:
  `GetVariable("_level0").instance1.Text1 = "Working"` (SetMember). `instance1` is the auto-name of an **unnamed** sprite
  (PlaceObject2 without a name). The sprite holds DefineButton2 id 5, whose up-state record is DefineEditText id 4 with
  variable `Text1` and initial text "Broken".
- Ours: `actionTryBindTextFieldVariable` (`action.c` ~23505) binds only text fields that exist as MovieClips. A button
  state record's EditText is not instantiated as a bindable object, so the variable write never reaches the rendered
  text. Not yet established: whether `_level0.instance1` resolves at all (auto-name `instance%u` exists in
  `tag.c:11301/11884`). A one-line trace probe would settle it.
- **Completion mechanism:** instantiate button-record EditTexts as text objects parented for binding (Flash binds to the
  button's parent clip), then route `actionTryBindTextFieldVariable` to them. **Collides with `n-play-game`** (AVM1 button
  code in `tag.c`/`action.c`), so it should be scheduled after that lands. 1 row, tol 0 / 12; the text uses `_typewriter`
  under `with_default_font`, so glyph exactness after the fix is also unmeasured.

## E. `font_lookup_as3`: NO-GO (Flash vs Ruffle conflict)

- The 4 failing fields (column 2, rows 1–4: `embedFonts = true` with `format.font = ""`) draw nothing in ours. The golden
  draws them in Noto Sans.
- The runtime face name is **`Times New Roman`**, not empty (probe: `TextFormat.font = ""` leaves the default face). So
  this is exactly the `fonts/embed_matching/no_font_found` mechanism: an embedded field naming a face the SWF does not
  embed. **Flash's** `no_font_found` golden is blank, and Ruffle marks its own fallback `known_failure` there ("we
  intentionally fall back"). We pass it.
- `font_lookup_as3`'s golden is **Ruffle-rendered**: Noto glyph shapes under `with_default_font`, where Flash would show
  Times. It encodes Ruffle's fallback, `"Times New Roman" → DefaultFont::Serif` (`html/layout.rs:604-626`).
- Matching it would trade a Flash-correct pass for a Ruffle match, which the user ruling forbids. An empty-name-only tweak
  was measured and does nothing (the name is not empty). **Disposition:** add to `RUFFLE_VS_FLASH_DIFFERENCES.md`
  (pixel). Completion mechanism: none, unless a Flash render of this SWF shows Flash falls back too.

## F. Device-font rows: NO-GO

`hardwrap` (`_sans`, DefineFont3 with 0 glyphs), `stylesheet`, `captions` (no fonts in the SWF) and
`flash_text_TextField` are all **known_failure**. Their goldens are Flash on Windows system faces (Arial, Times). None
sets `with_default_font`, so Ruffle's own render has no glyphs: `hardwrap`, `stylesheet` and `flash_text_TextField` are
md5-identical to `output.ruffle.png`. `captions` is closer to the golden than Ruffle (6528 vs 11607 channels): we draw
the black boxes and underlines, Ruffle draws nothing. Completion mechanism: bundling Windows system fonts plus Flash's
device-text rasteriser. Not fundable.

## G. Tol-0 KF raster rows: NO-GO

`acid-text-4` (51678), `acid-text-5` (422241) and `acid-textfield` (15754) are all `tolerance = 0` and Ruffle
`known_failure` (issues 12121/12122/12123). Our render matches Ruffle's to **435 / 0 / 6463** channels (>3), and Ruffle
misses the golden by 34779 / 205863 / 13915. The deficit is Flash's advanced anti-alias rasteriser (CSMTextSettings
FlashType + subpixel grid fit) at tol 0. `acid-text-5` additionally shows a scrolled/clipped field ("ABCI" vs "XYZ")
that Ruffle reproduces identically to us. Completion mechanism: a FlashType/ADF glyph rasteriser. Not fundable.

---

## Refutations

1. **"These are all glyph-raster rows":** refuted. A and B are a transform and a clip (both pure layout-to-render
   plumbing, +3), C is layout (kerning), D is variable binding, and E is a font-resolution policy conflict. Only F and G
   are raster.
2. **"`font_lookup_as3` is an embedded-name lookup bug":** refuted. The face is `Times New Roman`, and the golden encodes
   Ruffle's documented known-failure fallback.
3. **"`device_transform` needs the device-font metrics work":** refuted. The metrics half was already ported (traces
   pass). Only the render transform was missing.
4. **"`edittext_gutter` is the gutter inset arithmetic":** partly refuted. The inset is right; the bug is the inverted
   mask (Ruffle `grow_x` does not normalise) plus a degenerate border strip.

## New unclaimed leads

1. **DefineFont2/3 kerning on the AVM1/timeline EditText path** (C): recompiler emit + AVM1 advance term. Likely flips
   `acid-text`; trace risk on `textWidth`. Also correctness for any AVM1 game using `kerning="1"` embedded text.
2. **Bindable EditText inside button records** (D): after `n-play-game`.
3. AVM1 twin of the inverted gutter mask (`tag.c textfield_glyph_render_cb`): no graded row.
4. `RUFFLE_VS_FLASH_DIFFERENCES` entry for `font_lookup_as3` (E), plus an image-axis disposition for the F/G KF rows
   (device system fonts; FlashType raster), so they stop being re-diagnosed.

## LOCAL ORACLE REQUESTS

None required. Optional, for lead C: a Ruffle exporter render of `from_shumway/acid/acid-text/test.swf` (1 frame) to
confirm Ruffle's own PNG is md5-identical to the golden, which would mean kerning plus our raster is sufficient.
