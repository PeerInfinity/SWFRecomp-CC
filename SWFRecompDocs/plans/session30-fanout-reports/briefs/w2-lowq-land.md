**Land the LOW tie rules A + C, settle the LOW glyph rule against the new FP32 glyph probe, and price the x-tie half (M).**
Source: `session30-fanout-reports/w1-lowq-residues-report.md` + `w1-lowq-residues-prototype.patch` + its fixtures/tools.
FP32 glyph probe: `session30-fanout-reports/w1-local-oracles/w1-lowq-residues/README.md` (df2 = DefineFont2, df3 =
DefineFont3; LNX/WIN/screen; 24–45 channels host noise, so grade with t ≥ 2 or vs LNX draw()).

1. **Land A** (TSNAP tie on the LOCAL device offset from the snapped parent; kill switch `SWF_LOWQ_TSNAP_LOCAL=0`):
   6 rows toward FP32 (layer_alpha/erase ×2 each, alpha/erase_no_layer), 0 status moves.
2. **Land C** (exact-centre y tie exclusive top / inclusive bottom, +1/256 px; text exempt; `SWF_LOWQ_TIE_EPS=0`):
   `visual/simple_shapes/gradients/gradients` fail → PASS (FP32 golden), morph_test1 frames 2–6 and acid-stroke-0
   toward FP32; **priced cost** +397 channels over the 14 FP32 `blend_modes/*` rows (all already failing? confirm: a
   Flash-golden PASS lost is a defect, not a price) and +39/+34 on the two regression twins. Try to remove the cost
   (is it the blend rows' curve edges, i.e. a different tie class?) before landing.
3. **The LOW glyph rule.** The coordinator's first read of the probe: FP32 text sits +2 px right of the slot's renders
   and predictions; aligned, the current GPU render (13 429 px > 2) beats every chord prediction (14 048–14 947). Find the
   +2 px (TextField gutter? probe layout in `tools/model.py`?), then re-score per size row and per x phase (.0/.25/.5/.75):
   pen tie (half-up vs rint), chords vs curves, the chord-deviation threshold by size, DF2 vs DF3. Implement the rule
   (recompiler `swf.cpp` glyph loop second tessellation + `tag.c` `textfield_glyph_render_cb` LOW arm) ONLY if it is
   Flash-ward on the probe AND on `place_object_test`, `morph_test1`, `shape_test`, `text_field_mask`, `BeginBitmapFill`.
   Rebuild the recompiler, `--recompile`. Add the probe as a `regression/` image row with the FP32 LNX golden.
4. **x half of the tie** (HOLD in w1): text-exempt version fixes `edittext_underline`; find `cache_as_bitmap/scroll_rect`'s
   96 (x = 229) before landing; morph_test1 frame1 → PASS is the prize.
5. Write the RvF entry for the layer-group ALPHA painted-0 rule (w1 §7(a); Flash erases where the child paints alpha 0,
   Ruffle's `discard` keeps it). Implementation (coverage channel/stencil for the child layer) only if M fits.
Gate: the w1 146-row LOW gate (ledger scripts in `w1-lowq-residues-fixtures/`), the render canary, `regression/`.
New pipelines use `MSAA_SAMPLES`. Siblings: w2-stroke-geometry-land (HIGH curve flattening; you stay LOW).
Name every function you touch.
