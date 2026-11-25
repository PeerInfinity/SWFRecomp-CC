**Text edit tail (S–M): AVM1 restrict/onChanged and setNewTextFormat leading/margins; AVM2 selection-rect tint.**

Record: `session27-fanout-reports/w2b-avm1-text-edit-report.md` (§"open": a `restrict`-filtered keystroke fires no
onChanged in our runtime — Flash may fire it as it does for a maxChars drop; `tf_snf` parks only size/font — does
Flash also keep the existing text's `leading`/margins/`letterSpacing` under setNewTextFormat?), and
`w2-avm2-text-tail-report.md` §3 (AVM2 selection rect: we tint it with the field's full concatenated cx; Ruffle draws
it untinted; a fixture was written at `session27-fanout-reports/w2-avm2-text-tail-fixtures/avm2_edittext_selection_cxform/`
but it needs an ADDED_TO_STAGE setup to work as a Flash capture, and has no SWF or golden).

Task:
1. Build three fixtures ready for a FLASH capture (the coordinator runs them; Flash typing via `--type` works, mouse
   does not): (a) AVM1 restrict + onChanged under typed keys that restrict drops; (b) AVM1 setNewTextFormat with
   leading/leftMargin/rightMargin/indent/letterSpacing changes then typed text, tracing getTextFormat per run; (c) the
   AVM2 selection-cxform fixture reworked to select text programmatically after ADDED_TO_STAGE (stage.focus +
   setSelection), as an image test. Ship SWFs + build scripts in `w1-text-edit-tail-fixtures/`.
2. For each, write down our current output and Ruffle's (read Ruffle source), and prototype the change for each of the
   two possible Flash answers, so wave 2 can land whichever Flash picks.
3. Gate the prototypes on the avm1/avm2 edittext/textfield rows + `regression` text fixtures.
