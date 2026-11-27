# w2-lowq-land LOCAL ORACLE REQUESTS (s30 coordinator, 2026-11-27)

## 1. `adv_flags/` — which EditText flag gates the DefineFont2 advance ceil

FP32 LNX LOW, 1 tick, `--screen` (and draw(), identical). Ink starts per row (first 9 glyphs):
**all 8 rows = `13, 21, 28, 36, 44, 51, 59, 67, 79` = `ours_ceil_on.png`** (ceil OFF gives 13, 20, 27, …).
None of WordWrap / NoSelect / HasTextColor / variable name / gnash flags / Multiline / WordWrap+Multiline switches
the rule: FP32 ceils every one. Both this font and `morph_test1`'s are DefineFont2 flags `0xa4` (SmallText).
So `morph_test1`'s xtrace field not ceiling is NOT an EditText flag; remaining candidates: the field's transform /
scale, script-set (`text +=`) vs initial text, line count, or the frame of capture. Cross-check w1-rm-avm1-gnash
request 2 (`w1-local-oracles/w1-rm-avm1-gnash/`): `textWidth` ceils per glyph for SmallText fonts only.
`SWF_TF_LOW_ADV_CEIL` stays default OFF until the morph_test1 switch is found.

## 2. `screen/` — the priced losses, graded against FP32 LOW

FP32 LNX `--screen` == draw() (0–3 ch) on all six; WIN draw() captures for host check. Channels |Δ| > t, scored by
`scratchpad lowq_score.py` (before = HEAD `92f7d5e8a`, after = + w2-lowq-land patch, same box, `--recompile`):

| row | WIN vs LNX | t | before→FP32 | after→FP32 | golden→FP32 | verdict |
|---|---|---|---|---|---|---|
| `visual/filters/bevel` | 46 243 (host-dep.) | 0/16/64 | 271 053 / 24 418 / 8 905 | 265 632 / 22 493 / 8 681 | 290 427 / 31 270 / 10 062 | Flash-ward (vs LNX); no swap (WIN ≠ LNX) |
| `visual/filters/glow` | 1 598 | 0/16/64 | 29 504 / 20 896 / 7 383 | 28 735 / 19 985 / 7 158 | 32 857 / 24 604 / 8 666 | Flash-ward; no swap |
| `visual/filters/drop_shadow_angles` | 176 | 0/16/64 | 60 477 / 38 239 / 10 498 | 58 783 / 36 151 / 9 976 | 71 386 / 48 339 / 13 857 | Flash-ward; no swap |
| `visual/simple_shapes/overlaps` | 0 | 0/64 | 1 091 / 762 | 747 / 532 | 1 795 / 1 254 | Flash-ward; **flash_fixes swap** |
| `from_shumway/acid/acid-scale` | 0 | 0/64 | 1 690 / 845 | **1 850 / 925** | 11 240 / 5 620 | **away (+160)**: tie rule, priced; **flash_fixes swap** |
| `text/style_changes_in_html` | 2 | 0/16/64 | 23 938 / 4 348 / 2 174 | **24 390 / 5 252 / 2 626** | 24 446 / 5 802 / 2 901 | **away (+904 t16)**: field-local pen rule, priced; golden ≈ FP32-distance, no swap value |

All six rows were already failing at the s30 baseline: no pass is lost. Net: the patch is Flash-ward (probe df3
−6 897, df2 −3 612, blend rows −3 224, morph_test1 frames) against two priced Flash-away moves (acid-scale +160,
style_changes_in_html +904 at t16). The pen rule needs a scope that excludes style_changes_in_html's case (lead).
