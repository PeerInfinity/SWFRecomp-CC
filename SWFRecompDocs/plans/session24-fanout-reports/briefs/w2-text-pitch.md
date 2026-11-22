**Implement `w1-pixel-text` item 2 (+ optional item 3 riders) as a landable patch** (report `SWFRecompDocs/plans/session24-fanout-reports/w1-pixel-text-report.md`; start from `w1-pixel-text-prototype.patch`). Categories to download: `text avm1 from_shumway visual fonts`.

EXPECTED-FLIP LEDGER: pixel `text/br_at_start` (1672 → ≤ 8, limit 8) and `text/style_changes_in_html` (→ 0). `from_shumway/avm1/text-bind` moves at max diff 1 with UNCHANGED outliers (t64 587/600, t128 85/100) — report its outliers explicitly. 0 trace moves.

1. Leading (report §2a): carry twips leading in `TFRun` (a trailing `s16 leading_tw`) instead of the prototype's "equals truncated default" re-derivation; make every producer fill it.
2. Per-run embedded face + Fixed8 glyph colour (§2b) exactly as measured; zero `font_id` in every producer that shares `_tfg_runs` / `otf_html_runs`.
3. Optional riders, same slot, no flip: `visual/static_text_offstage` (a) root static-text bounds cull — grow by the filter extent rather than exempting filtered instances — and (b) per-instance root glyph slots (16016 → 9600 measured). Land them only if md5-neutral on the report's sweep 2.
4. Do NOT land the env-gated experiments (`SWFRECOMP_JPEG3_DILATE`, `TF_CENTER_TW`) or the JPEG3 premultiply `swf.cpp` hunk (that belongs to a bitmap slot later).
5. Append `text/style_changes_in_html` and `text/br_at_start` to `render_canary_tests.txt`; re-run the report's sweeps 1 and 2 (`render_canary.py` A/B, md5) and the regression text rows in both modes.
Sibling: `w2-textformat-ctor` edits TextFormat construction in `action.c` (getTextExtent, native super()); stay inside the run-table producers / `tf_get_defaults` / leading sync sites and `tag.c`'s glyph render callback.
