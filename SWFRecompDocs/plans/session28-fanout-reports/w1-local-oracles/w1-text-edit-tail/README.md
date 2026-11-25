# w1-text-edit-tail local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX, direct pinned)

| request | file | result |
|---|---|---|
| 1 `avm1_edittext_restrict_onchanged` `--type X5Y --type-after ready` | `avm1_edittext_restrict_onchanged.flash32.txt` | == `candidate.ruffle_fire_delete.txt` byte for byte: Flash fires onChanged on a restrict-filtered key AND deletes the live selection (Ruffle's behaviour; ours = no fire) |
| 2 `avm1_set_new_text_format_paragraph` `--type E --type-after ready` | `avm1_set_new_text_format_paragraph.flash32.txt` | == `candidate.ruffle_defer.txt` byte for byte |
| 3 `avm2_edittext_selection_cxform` trace | `avm2_edittext_selection_cxform.trace.txt` | `focus=true`, `sel=1,4` (SWF works in Flash direct) |
| 3 image, tick 2, draw() and `--screen` | `avm2_edittext_selection_cxform.draw.png`, `.s.screen.png` | screen == draw() (0/0). **Flash TINTS the selection rect** with the field's colour transform: gap pixels on rows 44/74/104/134 equal `candidate.tinted_master.png` (ours today); `candidate.untinted_ruffle.png` is wrong. 651 px (>8) vs tinted vs 3759 vs untinted; the residual is glyph raster. RvF: Ruffle draws the rect untinted |
