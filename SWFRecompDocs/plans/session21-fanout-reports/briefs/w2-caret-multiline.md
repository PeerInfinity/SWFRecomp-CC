# w2-caret-multiline — draw the EditText caret (wave 2, worktree, graphics)

Target: `visual/edittext/edittext_caret_multiline` ×6 comparisons. Diagnosis of record: `session20-fanout-reports/w2-gfx-text-smalls-report.md` lead **L2** (~line 451): each comparison's whole residual is a missing 1×20 px solid black caret at `x = 2 → 22 → 42` (ticks 1-3, char index) and `y = 2-21 → 22-41 → 42-61` (ticks 4-6, line index). The test is AVM2 (CWS v41), so the caret belongs next to the AVM2 EditText text/selection drawing (`avm2_render_underlines`, selection-highlight code near `avm2_text.c:3926`), **NOT** `avm2_render_textbox`'s border arm. Ruffle: `core/src/display_object/edit_text.rs` (caret render, blink phase — check whether Ruffle's exporter draws it unconditionally or on a blink timer; the goldens show it present).

Attack the premise first: confirm the caret is the only residual on all 6 at HEAD, and check which OTHER corpus comparisons would start drawing a caret (every focused EditText in any graphics test!) — that blast radius is the real risk. Grep the goldens of focused-EditText tests (`edittext_caret_empty` passes today — why does it have no caret? find the gate that distinguishes them) and include them in your canary. AVM1 EditText focus rows too, if the path is shared.

Siblings: w2-devicefont-a1 is in the recompiler + glyph raster; stay out of glyph code.
Deliverables: `SWFRecompDocs/plans/session21-fanout-reports/w2-caret-multiline-report.md` + `SWFRecompDocs/plans/session21-fanout-reports/w2-caret-multiline.patch`.
