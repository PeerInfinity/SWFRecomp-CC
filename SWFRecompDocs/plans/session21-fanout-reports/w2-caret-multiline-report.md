# s21 wave-2 — w2-caret-multiline report

**New files: NONE** (the patch only modifies tracked files). Deliverables:
`SWFRecompDocs/plans/session21-fanout-reports/w2-caret-multiline.patch` + this report.
Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a007a90196d9ee8c6`.

## Verdict: GO — +6 pixel comparisons, 0 moves elsewhere in a 48-comparison A/B

| test | comparison | before (HEAD) | after |
|---|---|---|---|
| `visual/edittext/edittext_caret_multiline` | output.01 | fail (60 ch, max 255) | **pass, 0 outliers, max diff 0** |
| | output.02 | fail (60 ch) | **pass, max diff 0** |
| | output.03 | fail (60 ch) | **pass, max diff 0** |
| | output.04 | fail (60 ch) | **pass, max diff 0** |
| | output.05 | fail (60 ch) | **pass, max diff 0** |
| | output.06 | fail (60 ch) | **pass, max diff 0** |

Priced flips: **6 comparisons, 1 test** (`edittext_caret_multiline`, trace already passing).
The local render matches the Ruffle goldens byte-for-byte (max difference 0 on all six). That is
a stronger result than a tolerance pass, but it is still a local render, so the coordinator's
images run is what grades it.

## Mechanism

The AVM2 EditText painter (`avm2_display.c::avm2_render_text`) had **no caret arm at all**.
`avm2_edittext_collect_selection` returned 0 for a collapsed selection with the comment "caret:
no background to fill", and nothing else drew one. The AVM1 painter (`tag.c`) has had a caret
since s10 (`edittext_caret_empty`), which is why that test passes and this one does not. The two
painters are separate, so the gate the brief asked me to find is not a predicate. The AVM2 path
simply lacked a caret renderer.

**There is a second gate, and it matters.** Even with a renderer in place, `et_visible_selection`
requires `et->sel_active`. That flag is left **cleared** on the born selection (on purpose, see
the comment at `avm2_text.c:2460-2466`) and **also by the TextControl Move*/Select* arms**
(`avm2_text.c:~10588-10607` never set it). This test sees no selection event at all. Tick 1 is
the born caret at index 0 (`new TextField()` is born with an empty text, so the caret sits at 0;
`tf.text =` does not move it, and Ruffle's `set_text` does not move it either). Ticks 2-6 are
TextControl `MoveRight`. So a renderer gated on `sel_active` would still draw nothing on any of
the six comparisons.

### Patch (runtime only, +116 LOC in two files, plus 11 lines of canary list)

1. `avm2_text.c`: new `avm2_edittext_collect_caret()`, placed next to
   `avm2_edittext_collect_selection`. It is a port of Ruffle `render_layout_box`
   (edit_text.rs:1237-1310):
   - walk every non-bullet text box, with the same below-the-field cull as the glyph walk;
   - the match window is `[start, end)`, or `end + 1` for the LAST box of a line (so the
     newline position and the end of the text land on that line). Our layout already emits
     zero-length boxes for empty lines (`lc_append_text(lc, end, end, …)`, :3193);
   - the last matching box wins, as Ruffle's `draw_caret_command` does when it is overwritten;
   - x = `char_end[i-1]` (the pen after glyph i-1), y = the box top, h = the box font's
     `ascent + descent`, and the colour is the box span's colour.
   - Visibility is Ruffle `visible_selection`'s caret arm: collapsed, focused and not read-only.
     It **does not require `sel_active`**, because AS3 selections are mandatory
     (edit_text.rs:308-312). The one real `selection = None` transition, an IME update with no
     cursor, is honoured (`ime_active && !sel_active` → no caret).
   - Blink: Ruffle's `blinks_now()` runs on wall-clock time, and the exporter captures well
     inside the first 500 ms "on" phase (every golden, all 7 including the ungraded output.07,
     shows the caret). So we draw it unconditionally, as the AVM1 twin already does.
2. `avm2_display.c`: new `static avm2_render_caret()`, a port of Ruffle `render_caret`
   (edit_text.rs:1330). The caret matrix is `world · translate · create_box_with_rotation(1,
   h, π/2, x, 0)`: its line direction is `(world.c·h, world.d·h)`, and x_snap tests `-world.a`
   / `-world.b`. Next come `EditTextPixelSnapping` (low: round ties even; else `trunc(t+2)` plus
   `round(v-0.35)` on the scale terms) and `ty -= HALF_PX`, then the existing
   `avm2_draw_border_line`, which is the `emulate_line_as_rect` port. I checked it by hand
   against `render/src/lines.rs` for the vertical case: column `[ax, ax+1px]`, rows
   `[ty_snapped, ty_snapped+h]`. The caret is drawn **after** `renderer_end_clip` ("draw the
   caret outside of the text mask"), through the identity slot, in the raw text colour at alpha 1
   (Ruffle pushes the DrawLine straight onto the command list, with no colour transform). It is
   also drawn when the field has zero glyphs/selection/underline, which covers an empty focused
   field.
3. `render_canary_tests.txt`: one member appended at EOF (tier 2, because it was CI-failing
   when added). Nothing in the standing set held a focused editable AVM2 field, so no member
   could see this change class.

Self-localized: two new functions, no struct change, no shared helper edited. It stays out of
`avm2_render_textbox`'s border arm and out of glyph code (sibling `w2-devicefont-a1`).

## Premise attacks

- **"The caret is the only residual on all 6": CONFIRMED.** A/B diff bboxes are exactly
  1×20 px at (2,2), (22,2), (42,2), (2,22), (2,42) and (22,42), 60 channels each. After the
  patch every comparison has max diff 0, so nothing else remains.
- **Brief/s20 geometry wording corrected.** The s20 report says "y = 2-21 → 22-41 → 42-61 at
  ticks 4-6". The goldens show tick 4 = (2, 22-41), tick 5 = (2, 42-61) and tick 6 =
  (22, 42-61). That is caret indices 0, 1, 2, 3, 4, 5, and the ungraded output.07 is index 6
  at (2, 62-81). The line index and char index both move within ticks 4-6. This is cosmetic;
  the mechanism is unchanged.
- **"`edittext_caret_empty` has no caret. Find the gate": REFUTED as framed.** It has a caret,
  drawn by the AVM1 `tag.c` painter (SWF v8). That is a different painter, not a gate.
- **Blast radius: every focused editable AS3 field now shows a caret.** I surveyed every corpus
  test that has `[image_comparisons]` and an AS3 `FileAttributes` flag. The tests with any
  focus, Tab, mouse or input signal are `avm2/focusrect`, `focusrect_focuslost`,
  `focus_stage`, `focus_root_movie`, `edittext_always_show_selection`, both `focus_highlight`
  tests, `edittext_selection_leading`, `edittext_selection_font_size`, `edittext_underline`,
  `edittext_get_{char,line}_index_at_point`, `fonts/device_font_kerning`, the mouse-pick tests
  and shumway `button1/2`/`3_joystick`/`flash_text_TextField`. Of these, only four ever focus
  a TextField: `edittext_always_show_selection`, `edittext_selection_{leading,font_size}` and
  this test. The first three focus a field with a **non-collapsed** `setSelection`, so the
  caret arm stays off. None of the focus/Tab/mouse rows focuses an editable AS3 TextField.
  (`visual/cache_as_bitmap/edittext_hscroll`, which shares this test's board cluster, is AVM1
  and uses a different painter.)
- **L6 tripwire** (`edittext_selection_leading` .09/.11 sits exactly at 36/36): md5-identical
  A/B, so it is untouched.

## Evidence / tests run (all `--mode=graphics`, sequential or `-P 2`, `SWFRECOMP_COMPILE_TIMEOUT=2400`)

- Render canary A/B (`render_canary.py capture before/after`, 10 tests / 48 comparisons, patch
  reversed with `git apply -R` for the before leg): **42 IDENTICAL (md5), 6 DIFFERS = the six
  target comparisons fail → pass. TRACE STATUS CHANGES: none.** Set:
  `edittext_caret_multiline`, `edittext_caret_empty` (AVM1 twin ×12),
  `avm2/edittext_always_show_selection`, `edittext_selection_leading` ×12,
  `edittext_selection_font_size`, `edittext_underline`, `avm2/edittext_get_char_index_at_point`,
  `text/auto_size/width`, `avm2/edittext_autosize_height_dynamic`, `avm2/focusrect` ×12.
- Regression suite: `regression/avm2_timeline_text` PASS and
  `regression/avm2_bitmapdata_draw_textfield` PASS. These are the only regression fixtures that
  hold an AVM2 TextField, and neither is focused.
- No regression fixture was added. The behaviour already has an oracle-graded corpus test (this
  one, with Ruffle goldens).
- I did not run the full standing canary (~80 tests). The change is gated to focused, editable,
  collapsed-selection AVM2 fields, and the survey above shows no standing member meets that.

## Risks / notes for the coordinator

- **Browser/games behaviour change.** Every focused AS3 input field (for example a game's
  name-entry box) now shows a steady caret. That is correct Ruffle/Flash behaviour, except that
  we do not blink it. Blink needs a wall-clock phase and a redraw request, and it is out of scope
  for the pixel axis because the goldens are captured in the "on" phase.
- `sel_active` is still the gate for the highlight and glyph-inversion paths, and the
  TextControl `Select*` arms still do not set it. So a keyboard `SelectAll`/`SelectRight` on an
  AS3 field never paints a highlight. I did not touch this: no graded test exercises it, and
  changing it would widen the blast radius. It is listed below as a lead.
- Merge: `render_canary_tests.txt` is appended at EOF, which is the expected `--3way` conflict.

## New unclaimed leads

- **L1: TextControl `Select*` (and `SelectAll`) on an AS3 field never sets `sel_active`**
  (`avm2_text.c` ~10593-10607), so a keyboard-extended selection never paints a highlight or
  inverts glyphs. Completion mechanism: set `sel_active = 1` in the select arm, or better,
  retire `sel_active` as a render gate in `et_visible_selection` in favour of the "mandatory
  selection + explicit None" model this patch uses for the caret. Needs a corpus search for an
  AS3 image test that shift-arrows or selects all (none was found in my survey's input.json
  scan, so it is unpriced).
- **L2: caret blink** for browser/wasm (a wall-clock phase with a 1 s cycle, reset on every
  selection change). This is a runtime UX item, not a pixel-axis item.
