# s21 w2-px-d: AVM2 device-font border corner (lead D2)

**New files: none.** `w2-px-d.patch` modifies:
- `SWFModernRuntime/src/avm2/avm2_display.c`: only the border block of `avm2_render_textbox`'s
  `draw_device_text_box` arm (`flags & 4u`).
- `ruffle-tests/render_canary_tests.txt`: moves my s21 `leading_device_font` member from tier 2 to a tier-1
  block at EOF.

The patch is against master `a37ee1266` (391aba282+). Worktree:
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a5b2168e1b262bfde` (no commits).

## Verdict: GO, +1 comparison

| Comparison | before → after (local Dawn, graphics) |
|---|---|
| `visual/fonts/leading_device_font` [output] | **18 outliers, max 191 → 0 outliers, max diff 0 (byte-exact vs golden), PASS** (tolerance 128, max_outliers 0) |

## The named check came out 0

The flag is 0 for both calibration rows, so this was the small fix, not the bigger one.
- `avm2/edittext_autosize_height_dynamic` (Test.as:71) and `visual/edittext/edittext_selection_leading`
  (Test.as:44) both set `embedFonts = true`.
- The AVM2 `embedFonts` setter (`avm2_text.c:4452`) sets `et->device_font = 0`, and `avm2_text_box_info` raises
  `flags & 4u` only on `et->device_font` (`avm2_text.c:8325`).
- So both rows are drawn by the **draw_text_box** LineStrip arm, which already carries its own measured
  partial corner (`corner_ext = dtw/2`, unchanged). The device arm's copy of that rule was calibrated on goldens
  this arm never renders.

There is no path by which an embedded field takes the device branch. The completion mechanism of the "flag 1"
case does not arise.

## Mechanism

Ruffle's `draw_device_text_box` (edit_text.rs ~2878–2909) draws four separate `draw_line` calls. After
draw_line's +HALF_PX:
- top: (x_min, y_min+½) → (x_max, y_min+½)
- bottom: (x_min, y_max+½) → (x_max, y_max+½)
- left: (x_min+½, y_min) → (x_min+½, y_max)
- right: (x_max+½, y_min) → (x_max+½, y_max)

No segment reaches the pixel (x_max, y_max), so the BR corner is empty. TL, TR and BL are inked. The golden shows
exactly this on all 6 fields: it is binary 0/255, and BR = 255. The AVM1 twin (`tag.c` device_box,
`line_rect = 1`) already drops that corner.

The patch ends the bottom rect at `w` and the right rect at `h` in both MSAA arms. It deletes the
`corner_dev = dtw/2` (MSAA) / `dtw` (aliased) extension and rewrites the comment to record where the old
calibration came from.

## Canary: every AVM2 EditText border image row + the standing set, md5 A/B

`render_canary.py compare d_before d_after` covers **70 tests and 130 comparisons: 129 IDENTICAL, 1 DIFFERS
(leading_device_font, fail → pass), 0 trace status changes**. The DIFFERS row changes exactly 18 channels, all
inside bbox (50,80)–(155,181), i.e. the 6 corner pixels.

Covered beyond the standing set (all md5-identical):
- AVM2/embedded border rows: `edittext_autosize_height_dynamic`, `edittext_selection_leading`,
  `edittext_caret_multiline`, `edittext_caret_empty`, `edittext_border_transform` (all 6), `avm2/edittext_autosize_align`,
  `edittext_autosize_lazy_bounds_visual`, `edittext_get_char_index_at_point`, `edittext_get_line_index_at_point`,
  `edittext_gutter`, `edittext_justify`, `edittext_selection_font_size`, `edittext_underline` (quality low),
  `visual/fonts/advance_u16`, `leading_define_font`, `leading_embedded_font`, `visual/layout/line_vertical_align`.
- The other device-font bordered rows: `fonts/device_font_kerning`, `fonts/device_font_no_ink` and
  `from_shumway/flash_text_TextField` (quality low, so the aliased arm) are identical. In each, the BR corner is
  off-stage or not drawn by this arm. **leading_device_font is the only corpus row that sees this corner**, which
  is why I promoted it to tier 1.
- The regression suite has no bordered EditText rows. Its standing canary members are all identical.

## New unclaimed leads

- None from this slot. The aliased (`MSAA_SAMPLES == 1`) device arm now also drops the corner, following Ruffle's
  line geometry. No quality-low device-font golden with a visible BR corner exists to confirm it.
  `flash_text_TextField` is the only quality-low device row, and it cannot see the corner.
