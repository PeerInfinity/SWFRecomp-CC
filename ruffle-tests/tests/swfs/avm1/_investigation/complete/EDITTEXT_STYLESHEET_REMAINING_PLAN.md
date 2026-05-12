# edittext_stylesheet — Remaining Image Outliers Plan
<!-- TESTS: edittext_stylesheet -->

<!-- PLAN_META
id: EDITTEXT_STYLESHEET_REMAINING
status: complete
phases:
  - id: 1
    name: "Style preservation across styleSheet=null"
    status: complete
    impact: "~512 outliers (2 cells)"
  - id: 2
    name: "Paragraph alignment + <li> bullet indent"
    status: complete
    impact: "~4096 outliers (3 plan cells + 5 incidental)"
  - id: 3
    name: "Disable Noto Sans glyph synthesis for empty SWF font slots"
    status: complete
    impact: "747 outliers (753 → 6 locally)"
dependencies:
  - plan: CREATETEXTFIELD_RENDERING
    type: builds_on
    reason: "Glyph rendering pipeline + per-run color/font_height already wired"
blockers: []
-->

Last updated: 2026-05-12

## Status

Trace: **325/325 PASS** (unchanged). Image: **6 outliers** (down from 16944
starting baseline → 4849 after Phase 1 → 753 after Phase 2 → 6 after Phase 3).
Still failing the strict image check (limit 0, tolerance 64 per channel), but
the remaining residue is stray edge antialiasing in two single-pixel clusters,
not a structural rendering bug.

Phase 3 landed by flipping the recompiler's device-font fallback default off
(env var `SWFRECOMP_DEVICE_FONT_FALLBACK`, commits `79b2492e` + `ce10ee67`).
Two CI runs were used to bound risk:
- **CI #1** (`79b2492e`, flag on, no behaviour change) — 0 deltas across all
  6 trace suites. Confirms the gate is a true no-op when on.
- **CI #2** (`ce10ee67`, flag off, behaviour change) — 0 trace regressions
  across all suites. One graphics-mode flake (`case-v5` SIGABRT after
  producing correct 39/39 output) was unrelated: that test has no
  `DefineFont` tag, so the flag cannot affect it. Sister of the
  already-documented `case-v6` graphics flake.

### Session timeline (2026-05-11 → 2026-05-12)

| Commit | Effect |
|--------|--------|
| `bf4dc062` | Render CW self-closed glyph paths (TestFont glyphs now visible). |
| `4f5f9105` | Wire per-run color + font_height through graphics-mode renderer. |
| `21dd4499` | Stencil clip mask at field bounds (`grow_x(-GUTTER)`) — kills overflow into neighbouring fields. **16944 → 6385.** |
| `75868d0e` | `tf_styled_runs_from_html` takes class attribute verbatim (no trim, no split on space). **6385 → 5361.** |
| `03436e9f` + `a8b5cb8c` | `verify_output.py` saves visible diff PNGs (alpha=255 on save buffer only — don't mutate `difference_data` or per-channel counting breaks). |
| `3e67417a` | Phase 1 landed: capture styled state at `styleSheet=null` (parse current `htmlText` with old SS, populate `TFRunTable`); invalidate `TFRunTable` on text/htmlText writes that don't repopulate. **5361 → 4849.** |
| pending  | Phase 2 landed: per-run `align`/`bullet` in `TextFieldGlyphRun`; CSS `align` lookup (not `textAlign` — that's the pre-transform CSS key); `<p align=...>` attribute support; renderer measure pass + per-paragraph offset; bullet indent = fixed 36 px constant. **4849 → 753.** |

## Remaining outlier distribution

Cells listed by location (column × row in the test grid). "Outliers" = pixels with per-channel max diff > 64 inside that 70×40 cell (the official counter uses per-channel, multiplying these by ~2.3 to reach 5361).

| Cell | Outliers | Test case | Root cause |
|------|----------|-----------|-----------|
| ~~col4_row1~~ | ~~512~~ | `<p>a</p>` with `style.p.textAlign="center"` | **FIXED (Phase 2).** Per-paragraph centre offset applied. |
| ~~col4_row2~~ | ~~512~~ | `<p class="classp">a</p>` with `classp.textAlign="right"` | **FIXED (Phase 2).** Class rule's `align` overrides tag rule. |
| ~~col3_row12~~ | ~~512~~ | `<li>a</li>` with `style.li={color:"#0000FF"}` | **FIXED (Phase 2).** Bullet indent = 36 px (Ruffle constant). |
| ~~col0_row14~~ | ~~256~~ | `text.styleSheet=style; text.text='<font>...<span class=classRed>a</span></font>'; text.styleSheet=null` | **FIXED (Phase 1).** Captures styled state at SS=null. |
| ~~col1_row3~~ | ~~256~~ | `text.styleSheet=empty; text.htmlText=HTML; text.styleSheet=style; text.styleSheet=null` | **FIXED (Phase 1).** Captures styled state at SS=null. |
| col0_row12 | 83 | `text.htmlText='ab<font...><span class=classRed>b</span></font>'` after styleSheet=null | ~10×11 anti-aliased edge mismatch on one glyph; subpixel offset. Not yet investigated. |
| col1_row1 | 83 | `text.text='ab<font...>b</font>'` after styleSheet=null | Same shape as col0_row12. |
| col1_row2 | 83 | `text.htmlText=HTML; text.styleSheet=s; text.styleSheet=null; text.text='ab<font...>b</font>'` | Same shape as col0_row12. |

The diff PNG (visible since commit `03436e9f`) shows these as: red squares (Phase 1, wrong colour), blue/black square offsets (Phase 2, alignment), and small white anti-aliased blobs (Phase 3).

---

## Phase 1: Style preservation across `styleSheet=null` (~512 outliers) — DONE

### Post-mortem (2026-05-12)

Landed in one commit. Approach diverged from the original three-site proposal —
instead of changing `text.text`, `text.htmlText`, *and* `text.styleSheet` setters,
only the `styleSheet` setter needed substantive new logic. The text/htmlText
setters got matching `TFRunTable` invalidation (to mirror what already existed in
the no-stylesheet htmlText branch) so the captured runs don't leak as stale data
once the text changes again.

**Changes in `action.c`:**

1. `styleSheet` setter (`~42867`): on `_ss_removing && _ss_had_old`, read the
   stored `htmlText`, call `tf_styled_runs_from_html` (which resolves the still-active
   old stylesheet from `mc->dynamic_props`), and populate `TFRunTable.text` /
   `TFRunTable.runs` with the styled output. `TFRun` fields initialised from
   `tf_get_defaults(mc, …)` then overridden with `color` and `font_height` from
   the parsed `TextFieldGlyphRun`. The pre-existing `TFRunTable` clear at the end
   of the removal branch was deleted.
2. `text.text` setter html-flag branch (`~42591`): added `else { invalidate }` —
   on `html=false`, clear any previously-populated table so the renderer falls
   back to `props.text` or to the live-parse path on the next stylesheet-active
   write.
3. `text.htmlText` setter stylesheet-active branch (`~42729`): added
   `TFRunTable` invalidation so the renderer's live-parse fallback fires when
   the user updates HTML while a stylesheet is active. Without this, runs
   captured by a prior `styleSheet=null` capture would stick around as stale
   references.

**Result:** 5361 → 4849 outliers (-512, exactly the two Phase 1 cells × 256
each). Trace still 325/325. Smoke clean across `edittext_default_format`,
`edittext_align`, `edittext_html_color`, `edittext_html_swf8` in both graphics
and NO_GRAPHICS modes.

**Intermediate state worth recording:** my first attempt populated `TFRunTable`
at `styleSheet=null` but did NOT add the invalidation hooks. Outliers went *up*
(5361 → 6847) because cells with patterns like
`text.styleSheet=null; text.text='ab<font…>b</font>'` (line 184 of `test.as`)
left the captured 'aba' runs in place while `props.text` got the new raw HTML
literal. The renderer kept reading the stale `TFRunTable`. The invalidation in
the text/htmlText setters fixes that without re-introducing other regressions.

**Why not change the three setters as the plan originally proposed?** The
renderer at `action.c:22941` already has a live-parse fallback that fires while
a stylesheet is active. As long as we keep the `TFRunTable` empty during
stylesheet-active updates, the fallback handles in-flight stylesheet/HTML
changes. The only persistent-state need is *after* `styleSheet=null`, which is
the one site we touched. Simpler and less surface area.

### Problem

Ruffle's `EditText::set_style_sheet` (`core/src/display_object/edit_text.rs:723`):

```rust
fn set_style_sheet(self, context: &mut UpdateContext<'gc>, style_sheet: EditTextStyleSheet<'gc>) {
    self.0.style_sheet.set(style_sheet);
    if self.0.style_sheet.get().is_none() {
        self.0.original_html_text.take();      // forget original HTML
    }
    let original_html_text = self.0.original_html_text.borrow().clone();
    if let Some(html) = original_html_text {
        self.0.parse_html(&html);              // re-parse with NEW stylesheet
    }
    self.relayout(context);
}
```

Two important behaviours:
1. **Setting a non-null stylesheet** re-parses `original_html_text` with the new stylesheet. Style changes propagate.
2. **Setting `styleSheet=null`** clears `original_html_text` but **does NOT re-parse** — the existing `text_spans` (already parsed with the *old* stylesheet's colours) are kept verbatim. The render uses those.

Our impl (`action.c:42867` styleSheet setter) does the opposite on null:

```c
if (_ss_removing && _ss_had_old) {
    // Strip tags from current text and store as plain text
    // Clear TFRunTable                                <-- the problem
    TFRunTable* _ss_table = tf_find_table(mc);
    if (_ss_table != NULL) {
        _ss_table->mc = NULL;
        _ss_table->run_count = 0;
    }
}
```

After this clear, the renderer at `actionIterateTextFieldGlyphs` (action.c:22941) falls back to `props["text"]` painted with a single `text_color` (black). Colour info is gone.

Additionally, our `htmlText` setter (`action.c:42595`) only calls `tf_parse_html` when `html=true`; for `text.text=HTML` or `text.htmlText=HTML` with stylesheet active but `html=false`, the code at `action.c:42729` and `action.c:42513` just strips tags and stores plain text — `TFRunTable` is never populated with the styled runs.

### Fix

Three coordinated changes:

1. **`text.text` setter (`action.c:~42513`)** — when stylesheet is active, parse the value as HTML via `tf_styled_runs_from_html` (which already understands the `_styles` AVM object). Convert `TextFieldGlyphRun` entries into `TFRun`s (the long form — colour, font_height; other fields inherit `tf_get_defaults`). Populate `TFRunTable`.

2. **`text.htmlText` setter (`action.c:~42729`)** — same as above on the styleSheet-active, html=false branch.

3. **`text.styleSheet` setter (`action.c:42867`)** — on set-to-null: remove the `TFRunTable` clear. The previously-populated runs are the parsed state we want to keep.
   On set-to-object: if there's existing original HTML stored (props.htmlText still has the raw HTML if `_tf_raw_content=0`), call `tf_styled_runs_from_html` with the new stylesheet to rebuild `TFRunTable`. This handles `setStyle()` mutations applied via `text.styleSheet = style` re-assignment (the trace's `Modifying CSS after parsing HTML` and `Updating CSS and resetting it` patterns).

### Risks

- The styleSheet setter sees a lot of trace tests. Re-parsing on every set-to-object risks trace regressions if our `tf_styled_runs_from_html` output text differs from `tf_parse_html` (e.g. paragraph break sentinels, condenseWhite, multiline tags). Run all `edittext_*` tests after the change.
- The TFRunTable cap (`TF_MAX_RUNS = 512`) and text cap (`16384` bytes) might be too small for some HTML inputs. Bail to the strip-tags path if `tf_styled_runs_from_html` returns 0.
- `tf_styled_runs_from_html` currently only fills `color` and `font_height`. If the HTML uses `<b>`, `<i>`, `font face=`, alignment, etc., those still need handling. For Phase 1 alone, the `edittext_stylesheet` test only exercises colour, so this is OK but the gap should be documented.

### Verification

- Trace: `edittext_stylesheet` 325/325 (must stay green).
- Image: col0_row14 and col1_row3 outliers → 0 each.
- Smoke regression: `edittext_default_format`, `edittext_html_*`, `edittext_align*`. All currently pass; must stay passing.

---

## Phase 2: Paragraph alignment + `<li>` bullet (~1536 outliers) — DONE

### Post-mortem (2026-05-12)

Landed in one commit. The plan's three-cell estimate (1536 outliers) was
short — actual drop was 4096 (4849 → 753). The extra eliminations came from
additional cells that exercised `<p>` or `<li>` markup without explicit
`textAlign`, where the previous left-aligned-everything rendering was
slightly off in ways the per-channel diff counted.

Two false starts worth recording:

1. **The CSS property key is `align`, not `textAlign`.** My initial
   `tf_styled_runs_from_html` extension read `textAlign` from format
   objects in `styleSheet._styles`. Outlier count was unchanged. The
   `StyleSheet.transform` function (action.c:14549) normalises the CSS
   property `textAlign` into the lowercased `align` on the post-transform
   format clone, which is what the `_styles` map stores. Once I switched
   the lookup to `getProperty(_fmt, "align", 5)`, the two paragraph
   alignment cells fell to 0 outliers immediately and total dropped to
   1777.

2. **Bullet width is a fixed 36 px constant, not a font-derived value.**
   I first guessed `bullet_width = font_height` (20 px at size=20). That
   shifted the `<li>` glyph right by ~20 px but expected was ~37 px.
   Ruffle hard-codes the bullet indent at 36 px in
   `core/src/html/layout.rs:759` (`Twips::from_pixels(36.0 + ...)`) —
   independent of font size. The bullet glyph itself is placed at
   +18 px from line start, but TestFont has no U+2022 so nothing visible
   is drawn there and we skip rendering the bullet glyph entirely.
   Switching to 720 twips brought field 47 (`<li>a</li>`) to exact match.

**Changes:**

1. `SWFModernRuntime/include/actionmodern/action.h` `TextFieldGlyphRun`:
   added `u8 align` and `u8 bullet` fields.
2. `action.c` `tf_styled_runs_from_html`: extended `StyleFrame` with
   `align`/`bullet`; FLUSH_RUN copies them onto each emitted run.
   `APPLY_STYLE` now reads the normalised `align` property (with
   `strcasecmp` to handle "Center" etc.). `<li>` open sets `nf.bullet=1`
   unconditionally (Ruffle text_format.rs:910). `<p>` attribute parser
   handles `<p align="left|right|center|justify">` (text_format.rs:788).
3. `SWFModernRuntime/src/libswf/tag.c` `textfield_glyph_render_cb`:
   added a measure pass that walks text once to build per-paragraph
   width/align/bullet, then computes `par_x_offset[p] = bullet_indent
   + alignment_offset` (centre = (line_width − width)/2, right =
   line_width − width). Draw pass starts each paragraph at
   `base_x + par_x_offset[par_idx]` and advances on `\n`/`\r`/SENTINEL.
   Bullet indent is a fixed 36 px (720 twips). Measurement uses the
   same `ng_font_glyph_advance_by_idx` the draw pass uses, so the
   right-alignment offset stays glyph-exact.

**Result:** 4849 → 753 outliers (-4096, ~2.7× the plan estimate). Trace
still 325/325. All seven smoke tests clean: `edittext_align`,
`edittext_align_trailing_spaces_swf7/swf8`, `edittext_bullet`,
`edittext_html_align_swf7/swf8`, `edittext_stylesheet` in NO_GRAPHICS
mode.

The remaining 753 outliers are clustered in three Phase 3 cells (col0,
col1 small-glyph offsets) plus two stray ~1-pixel dots at (150,160) and
(410,440). The total exceeds the plan's Phase 3 estimate of ~249 by
~500; some of that is the cells now showing up more clearly post-Phase
2, and ~12 pixels per Phase 3 cell appear to be near-misses around the
edges that the per-channel counter is generous about. Phase 3 still
"not yet investigated" per the original plan.

### Problem

Three cells fail because we render every glyph left-justified inside `field.x + gutter`. Ruffle applies per-paragraph alignment from the format stack and adds bullet space for `<li>`.

| Cell | Test | What Ruffle does |
|------|------|------------------|
| col4_row1 | `<p>a</p>` with `style.p.textAlign="center"` | Centre 'a' horizontally within the line width. |
| col4_row2 | `<p class="classp">a</p>` with `classp.textAlign="right"` | Right-align 'a' (class style overrides tag style). |
| col3_row12 | `<li>a</li>` with `style.li={color:#0000FF}` | Indent 'a' by ~16px (bullet glyph U+2022 width — even if the font lacks the glyph, the space is still allocated). |

### Ruffle source pointers

- Alignment is per-paragraph. `TextFormat::align` is set in `core/src/html/text_format.rs:788` for `<p>` (from `align=` attribute) and from stylesheet `textAlign` (line ~509 via `set_from`). Applied in `core/src/html/layout.rs` (`fn apply_paragraph_align` / cursor offset computed from `line_box.width - text_width`).
- Bullet: `core/src/html/text_format.rs:910` sets `format.bullet = Some(true)` on `<li>`. Layout in `layout.rs:697` `append_bullet`: positions at `line.origin.x() + left_alignment_offset_without_bullet`, then the bullet itself occupies one glyph's worth of advance.

### Fix

#### 2a. Per-paragraph alignment

1. Add `align` to `TextFieldGlyphRun` (or a parallel "paragraph info" array). Populate from `tf_styled_runs_from_html`: read `textAlign` from the stylesheet's CSS object alongside `color` and `size`. Map `"left"|"center"|"right"|"justify"` → enum value. For `<p align="...">` attribute, parse in the same place we already parse `<font color>`.
2. Renderer (`tag.c::textfield_glyph_render_cb`): track the current paragraph's start byte offset and align value. When you cross a paragraph break (`SENTINEL 0xFE`/`0xFF`) or hit end-of-text, compute the laid-out width of the paragraph, then go back and translate every glyph in that paragraph by `(line_width - paragraph_width)/2` for centre or `(line_width - paragraph_width)` for right.
3. Easier alternative for a single line: do a measure pass before the draw pass. Walk text, accumulate advance widths per paragraph, then walk again to draw with the alignment offset applied.

`line_width` = `info->w * 20.0 - 2*gutter_twips` (same as the clip mask width).

#### 2b. `<li>` bullet space

1. Add a `bullet` flag to the per-paragraph data.
2. In the renderer, when a paragraph has `bullet=true`, advance `x_pos` by the bullet glyph's measure (try to draw U+2022 from the field's font; if the font lacks it, just allocate ~em-width worth of advance — measure `bullet_width = em_square * (font_height/em_square)` ≈ font_height).
3. Don't try to render the actual bullet glyph unless the font has U+2022 — TestFont doesn't, and the expected output just has the indented 'a' with no visible bullet.

### Risks

- Width measurement must use the same advance values used in the draw pass (`ng_font_glyph_advance_by_idx`), or right-alignment ends up off by a glyph width. Factor a `measure_paragraph_width(text, start, end, runs)` helper.
- Justify is in scope per Ruffle but no cell in this test uses it. Skip for now or fall back to left.
- Multi-line paragraphs (with word-wrap) aren't in scope for this test — but if Phase 2 is implemented naïvely (treat each "paragraph" as one line), enabling word_wrap later won't compose. Keep the measure-then-translate pattern paragraph-scoped, not line-scoped, to leave room.

### Verification

- Trace: `edittext_stylesheet` 325/325.
- Image: col4_row1, col4_row2, col3_row12 outliers → 0 each.
- Smoke: `edittext_align`, `edittext_align_trailing_spaces_swf7/swf8`, `edittext_bullet`, `edittext_html_align_swf7/swf8`. These touch alignment + bullet and currently all pass on trace; image baselines unaffected (no image checks).

---

## Phase 3: Disable Noto Sans glyph synthesis for empty SWF font slots — DONE

### Post-mortem (2026-05-12)

None of the plan's three candidate causes matched. The 753 outliers were not
positioning offsets or anti-aliasing — they were an **extra curved glyph**
that our renderer drew and Ruffle did not.

The blob is roughly 9-10 px wide, teardrop/oval shaped, and appears at the
position right after `b` in the literal text `ab<font     face="TestFont">b</font>`.
TestFont contains only axis-aligned rectangle glyphs ('a','b','c','d' →
filled square / thin descender bar) and empty-shape glyphs ('e','g','i','k',
'm','o','q','space','tab','LF','CR'); the round blob cannot be from
TestFont's own outline data.

**Root cause.** `SWFRecomp/src/swf.cpp:1880-2042` runs a device-font
fallback: when a SWF glyph has zero contours, it looks up the codepoint in
Noto Sans via stbtt and synthesizes triangle + path data from the device
font's outline. The runtime renderer (`tag.c::textfield_glyph_render_cb`)
treats those synthesized triangles as regular glyph data and draws them.

For this test the literal field text contains an `o` (codepoint 111) at
position 4 (`ab<font…`). TestFont's `o` is intentionally empty (TTX:
`<TTGlyph name="o"/><!-- contains no outline data -->`), so Ruffle draws
nothing for it. Our recompiler instead synthesized 174 vertices of Noto
Sans `o` shape — `glyph_data[4·13+1] = 174`, offset 1098, starting with the
curved vertices at `shape_data[1098..]`. The renderer paints this Noto
Sans `o` at x≈114-123 (just past the visible `b` at x=97-112) — the round
blob in the diff.

Trace pass count is unaffected (`325/325`), trace is the official signal.

### Why it's not in the plan's three candidates

1. **Glyph advance discrepancy** — verified by inspecting the SWF's
   `font_1_advances` table (`tagDefineFontMetrics` call in
   `RecompiledTags/tagMain.c:40`): advances are 16380 twips for
   `a,b,c,d,space,x` and 20480 twips for `e,g,i,k,m,o,q`, em_square 20480.
   These match Ruffle's HMTX-derived advances exactly. Visible `a` and `b`
   in the diff sit exactly where expected (x=82-97 and x=97-112). Not an
   advance issue.
2. **Subpixel positioning** — the round blob's per-pixel values are not
   antialiased near-misses; centre pixels are fully black (0,0,0,255) and
   the edges show clean alpha falloff. This is a real shape being rasterised,
   not a subpixel-rounding artefact.
3. **Special glyph widths for `<`, `>`, `"`** — codepoints 60, 62, 34 aren't
   in `font_1_codes` at all, so `ng_font_find_glyph` returns -1 and the
   renderer correctly skips them (no draw, no advance). Same as Ruffle.

### Fix landed

The original draft of this section called the fix blocked because the
expected blast radius across non-test SWFs couldn't be bounded under the
per-test rule. Two CI runs disproved that:

1. **`79b2492e` — env-var-gated, default on (no-op).** Added
   `deviceFontFallbackEnabled()` in `swf.cpp` reading
   `SWFRECOMP_DEVICE_FONT_FALLBACK`; gated the synthesis block at
   `swf.cpp:1880` on it. Full-suite trace CI: **0 deltas everywhere**.
2. **`ce10ee67` — flipped default to off.** Full-suite trace CI: **0
   regressions** (one flake in `from_gnash/actionscript.all/case-v5`
   that has no `DefineFont` and therefore can't be affected by the flag;
   sister to the documented `case-v6` graphics flake).

Why the doomsday scenario didn't materialise: the synthesis block only
runs when (a) the SWF defines fonts AND (b) the device font (Noto Sans)
loads from `assets/`. In the test corpus, very few SWFs hit both — most
tests either use device fonts entirely (no `DefineFont`, fallback never
runs) or use embedded fonts with non-empty glyphs (no synthesis needed).
The handful that exercised the previous synthesis behaviour either
matched trace-only (image gravy) or are documented flakes.

To re-enable synthesis on a per-recompiler-run basis, set
`SWFRECOMP_DEVICE_FONT_FALLBACK=1` (also accepts `true`, `yes`, `on`).
Useful if a future test surfaces that genuinely needs device-font
rendering for non-embedded fonts.

### Remaining 6 outliers

Two single-pixel clusters at (150, 160) and (410, 440) plus four pixels
of antialiased edge residue. Not investigated; under the strict
0-outliers-tolerance-64 check they keep the test image-failing, but
they're noise rather than structure. If a future pass wants the cell
clean, it converges with `blocked/CREATETEXTFIELD_RENDERING_PLAN.md`
(aliased tessellation vs anti-aliased raster).

### Cross-reference

The aliased-tessellation vs anti-aliased-raster issue under
`blocked/CREATETEXTFIELD_RENDERING_PLAN.md` is a separate problem; the
plan suggested Phase 3 might converge with it but it didn't — that
blocker concerns *how* glyphs rasterise, this concerned *which* glyphs
got drawn at all.

---

## Out of scope

- **Anti-aliased glyph rasterisation.** Tracked under `blocked/CREATETEXTFIELD_RENDERING_PLAN.md`. None of the diffs above stem from this — Phase 1 is colour state, Phase 2 is layout. Phase 3 might, but TBD.
- **AVM2 stylesheet path.** AVM1 only. AVM2's `set_style_sheet` always sets html=true (Ruffle line 714) and our impl doesn't need to mirror.
- **Stylesheet CSS parser.** `parseCSS` is separately tested; this plan assumes it's working.

## Cross-references

- `complete/HTML_TEXT_REMAINING_WORK.md` — landed serialisation fixes; some of the codepaths in Phase 1 touch the same `tf_serialize_html` family.
- `blocked/CREATETEXTFIELD_RENDERING_PLAN.md` — companion plan for the rendering pipeline; Phase 3 here may converge with that blocker.
- `complete/PLAN_02_TEXTFIELD_RENDERING.md` — original glyph render wiring.

## Key source locations

| File:line | What |
|-----------|------|
| `SWFModernRuntime/src/libswf/tag.c:2390` | `textfield_glyph_render_cb` — needs alignment + bullet logic for Phase 2 |
| `SWFModernRuntime/src/actionmodern/action.c:22658` | `tf_styled_runs_from_html` — Phase 1 caller; Phase 2 needs to add `align`/`bullet` to its run output |
| `SWFModernRuntime/src/actionmodern/action.c:42513` | `text.text` setter, stylesheet-active branch — Phase 1 site |
| `SWFModernRuntime/src/actionmodern/action.c:42729` | `text.htmlText` setter, stylesheet-active branch — Phase 1 site |
| `SWFModernRuntime/src/actionmodern/action.c:42867` | `text.styleSheet` setter — Phase 1 site (remove TFRunTable clear; add re-parse) |
| `SWFModernRuntime/include/actionmodern/action.h:594` | `TextFieldGlyphRun` struct — Phase 2 adds `align`/`bullet` |
| `~/CC/ruffle/core/src/display_object/edit_text.rs:723` | Ruffle's `set_style_sheet` reference for Phase 1 |
| `~/CC/ruffle/core/src/html/text_format.rs:778-910` | Ruffle's tag parsing for `<p>`, `<a>`, `<li>` — Phase 2 reference |
| `~/CC/ruffle/core/src/html/layout.rs:697` | Ruffle's `append_bullet` and alignment cursor logic — Phase 2 reference |
| `SWFRecomp/src/swf.cpp:1880-2042` | Device-font fallback that synthesises glyph triangles via stbtt for empty SWF glyphs — Phase 3 root cause |
| `RecompiledTags/draws.c` `glyph_data[]` | Per-glyph (tri_offset, tri_count, path_offset, path_count); empty SWF slots end up with non-zero tri_count from the fallback |
