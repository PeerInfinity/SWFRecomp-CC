**LOW EditText residues from w2-lowq-land, against the FP32 answers (S–M).**

Base: master `a18a0e033` or newer (w2-lowq-land LANDED). Read `w2-lowq-land-report.md` (§1, §1.3, §7) and
`w1-local-oracles/w2-lowq-land/README.md` (both requests answered).

1. **The DefineFont2 advance ceil gate.** FP32 ceils advances on all 8 EditText-flag variants of the probe (no flag
   gates it). Both the probe font and `morph_test1`'s font are DefineFont2 `0xa4` (SmallText). w1-rm-avm1-gnash's FP32
   probe found `textWidth` ceils per glyph for SmallText fonts only. Yet FP32's `morph_test1` xtrace field does NOT
   ceil. Find the switch. Candidates: field transform/scale, script-set (`text +=`) vs initial text, autoSize, line
   count, the font size vs the em, the capture frame. Build an FP32-checkable probe that splits these and put it in
   LOCAL ORACLE REQUESTS; with the answer, enable `SWF_TF_LOW_ADV_CEIL` under the real gate. Ledger it: df2 probe,
   `BeginBitmapFill`, `morph_test1` frames 2–6, and the LOW text canary rows.
2. **Scope the field-local pen rule** so `text/style_changes_in_html` stops moving away from Flash (+904 channels at
   t16 vs FP32 LOW, `w1-local-oracles/w2-lowq-land/screen/text_style_changes_in_html.lnx.low.png`; WIN == LNX ±2).
   Compare the FP32 capture with ours per glyph run: is it HTML spans / multiple TextFormat runs, a different
   leading, or the pen origin per run?
3. **(Optional, M) the LOW glyph chord rule** (w2-lowq-land §1.3: chords win at 12 px, lose at ≥ 36 px, device
   tolerance ≈ 0.25–0.5 px). It is a recompiler change: rebuild + `--recompile`. Land it only if it is Flash-ward on the
   FP32 probes and moves no Flash-golden pass.
Gate: the w2-lowq-land 148-row LOW gate (`w2-lowq-land-fixtures/ledger/`) + the two `regression/lowq_glyph_probe_*`
rows. Graphics mode (render-only).
