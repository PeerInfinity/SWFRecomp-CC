# w2b-lowq-text LOCAL ORACLE REQUESTS — FP32 answers (s30 coordinator, 2026-11-27)

FP32 LNX LOW, 1 tick, `--screen` (draw() identical). SWFs rebuilt locally with the slot's generators.

## 1. `swfver_ceil_probe/` — `fp32_v{5,6,7,8}.lnx.low.png`

Ink starts, first 6 glyphs, rows r0 / r1 / r2 / r3:
- **v5, v6: fractional** (r0 13, 20, 27, 34, 42, 48), = ours (master and patch) except glyph 5 (FP32 42, ours 41).
- **v7, v8: CEIL** (r0 13, 21, 28, 36, 44, 51) = ours with the patch.
- **r2 / r3 (SmallText bit CLEARED) are identical to r0 / r1 at every version.** SmallText does NOT gate the LOW
  render advance ceil (unlike the `textWidth` metric: w1-rm-avm1-gnash request 2).
- Verdict: edge = **SWF 7** (`SWF_TF_LOW_ADV_CEIL_MINVER` default 7 is right); no SmallText AND.
- Residue: r1 (morph_test1's xtrace field) differs from ours after the 3rd glyph at every version (FP32 v7
  17, 26, 33, 39, 44, 52; ours 17, 26, 33, 39, 42, 44): a separate glyph/kerning lead.

## 2. `ypen_scope_probe/` — `fp32.lnx.low.png`

Ink bands (top, bottom): FP32 (12,38) (52,78) (92,118) (130,152) (170,192) = **ours MASTER exactly**; the patch moves
the three DF3 rows (plain, HTML, no-align-zones) 1 px down. **The em-1024 gate is REFUTED**: DF3 fields at an even+.5 y
keep the LOCAL y in Flash, whether plain, HTML or zoneless. `style_changes_in_html` field 5 (world y in FP32) differs
by something this probe does not vary (candidates: the field's own y vs a parent offset, autoSize, multiple fields
sharing a run, leading). Landed with `SWF_TF_LOW_PEN_LOCAL_Y` default = local y for every font (master behaviour);
`=0` gives the slot's em-only rule. `style_changes_in_html` stays priced (+904 at t16 vs FP32).
