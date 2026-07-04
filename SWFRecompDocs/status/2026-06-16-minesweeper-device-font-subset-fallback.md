# Minesweeper — device-font EditTexts garbled (partial embedded font) — FIXED

**Date:** 2026-06-16
**Game:** flasharchive/Minesweeper (browser-WASM graphics / graphics-native)
**Bucket:** headless-diagnosable (reproduces in the OFFSCREEN divergence harness;
fix is CI-observable in `--mode=graphics`).
**Commit:** `9c922628c`

## Symptom

On Minesweeper's difficulty-select title screen (frame 5), the static device-font
labels rendered garbled:

- `Difficulty:` → `ii`
- `Enter your name:` → `ner r ne`
- name field default `anonymous` → blank

The bomb art, the "Mine // sweeper / by rastyle.com // studios / v // 1.2" title,
and the Start button all rendered correctly.

## Root cause (diagnosis was clean, not guessed)

The trace matches Ruffle byte-for-byte (only a sub-pixel `_y=-5` vs `-4.3` on a
component label) — so this is purely a **render** issue, not AVM1 logic.

The three garbled labels are **DefineEditText** (not static DefineText) with baked
initial text. All reference **embedded font 57 "Arial"**, which carries only a
**23-glyph subset** — exactly the glyphs the static title needs:
` -./0123456789Meinprsvw`. They are **device-font** fields (`UseOutlines = False`,
HTML `FACE="Arial"`), which in Flash/Ruffle render with the host system Arial
(full coverage).

Our `textfield_glyph_render_cb` looked the field's glyphs up in font 57 and
**silently skipped every missing glyph** (`ng_font_find_glyph < 0 → continue`).
Projecting the strings through font 57's code table reproduces the exact garble:

```
"Difficulty:"      -> "·i··i······"   (== "ii")
"Enter your name:" -> "·n·er ···r n··e·" (== "ner r ne")
"Mine // sweeper"  -> "Mine // sweeper" (full coverage, renders fine)
```

The recompiler's **Phase-A device-font synthesis** (see
`plans/completed/device-font-rendering-plan.md`) already fills a full ASCII glyph set from
the bundled NotoSans for **zero-glyph** named fonts — and this SWF *has* one:
font 3 `_sans` got 95 synthesized glyphs at glyph_base 0. But Phase A is gated on
`num_entries == 0`; font 57 has 23 glyphs, so it was skipped. Nothing routed the
device-font fields away from their partial embedded font.

(The runtime built-in Noto Sans fallback carries advances/metrics only — no
outlines — so it can't draw anything; it's not a usable glyph source.)

## Fix

`actionIterateTextFieldGlyphs` (action.c): after resolving the field's `font_id`,
if the field is a **device font** (`embedFonts == false`) **and** its embedded
font's name is not a `_` device alias, re-point `font_id` at a synthesized
device-font alias via the new `ng_find_device_fallback_font()`
(ng_shared.c / tag.h) — prefers `_sans`, then `_serif`, `_typewriter`; requires
`has_metrics && glyph_count > 0`. Returns -1 when the SWF declares no such font
(then nothing changes).

Untouched:
- Device-alias fields (name starts with `_`) already point at the synthesized
  set — no redirect.
- Embedded-font fields (`embedFonts == true`, e.g. the bomb counter `999` on
  font 57) keep their real outlines.

## Verification

- Divergence harness (OFFSCREEN, `--skip-ruffle`): all three labels render their
  full text; trace unchanged (still the lone sub-pixel `_y` diff).
- Browser-WASM (`smoke_demo.py`): labels render correctly; only console error is
  the benign `rando_bridge.js` 404.
- Shared OFFSCREEN-compiled render path → graphics CI dispatched as a
  no-regression check (run 27632050005).

## Generality

This fixes device-font text for **any** SWF that (a) declares a `_sans`/`_serif`/
`_typewriter` font (very common for AS2 / FUIComponent content) and (b) points a
device-font field at a partial embedded font. It does **not** add a universal
runtime fallback — a SWF with device-font fields but no synthesized `_sans` font
still has no outline source (that would be Phase B/C of the device-font plan:
bake Noto Sans ASCII outlines into the runtime).

## Open follow-up — FUIComponent radio-button labels still grey bars

The three difficulty radio buttons ("Easy (40 mines)", "Medium (70 mines)",
"Tough (100 mines)") render as a uniform **`0x808080` grey bar** instead of their
labels. This is a **separate** issue from the font subset:

- The radio label is an FLabel `labelField` = DefineEditText char 4 (font 3
  `_sans`), nested in the attached `fLabel_mc` sprite; its text is set via AS
  (`labelField.text = " Easy (40 mines)"`, from the component's `on(initialize)`
  clip event → `setLabel`).
- Instrumenting `actionIterateTextFieldGlyphs` shows the rendered `labelField`
  has text **`" "` (a single space)** — the AS-assigned label never reached the
  rendered wrapper (likely a wrapper-vs-display_obj mismatch; the AS ran, since
  the trace matches Ruffle).
- The grey bar is **not** the label text (only a space renders), **not** a
  textfield background/border (only the `anonymous` box draws one), and **not** a
  world-positioned top-level shape. It is `0x808080` ≈ black-at-50%-alpha, exactly
  at the labelField position, label-height (~12px), and the **same fixed width**
  across all three buttons (so it is a skin element, not proportional to the
  label). Source not yet pinned — candidates: a nested radio-skin shape
  (`frb_states`/`frb_frame`) or a cxform'd overlay whose `_visible=false` /
  clip isn't honored.

Next session: trace which display object draws the `0x808080` bar (broaden the
nested `render_display_list` shape diag and map the local transform to screen via
the composed matrix), and find why the FLabel `labelField` wrapper that AS writes
to is not the one rendered.
