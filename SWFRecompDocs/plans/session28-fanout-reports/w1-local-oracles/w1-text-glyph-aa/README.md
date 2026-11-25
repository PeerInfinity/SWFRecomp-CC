# w1-text-glyph-aa local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX, HIGH)

## Request 1: Flash captures of the rows the ¼-px glyph snap moves pass → fail

`sweep_goldens.py --direct` (pinned, one settled grab per test), PNGs in `png/`, grades vs the CORPUS golden in the
`*.direct.json` files:

| row | Flash vs corpus golden | note |
|---|---|---|
| `regression/avm1_long_text_layout` | 135 px / max 65 | |
| `visual/filters/bevel` | 134 888 px | golden not Flash (or capture tick/quality differs) |
| `visual/filters/glow` | 19 543 px | same |
| `visual/filters/drop_shadow` | 22 101 px | same |
| `visual/filters/glow_with_alpha_strength` | 145 526 px | same |
| `visual/cache_as_bitmap/edittext_scroll` .01/.02 | 423 / 421 px | **one static grab for both triggers** (direct mode) |
| `visual/text/String_path_variable_button` | no capture | untestable in direct mode |
| `from_gnash/misc-ming.all/morph_test1` frame1–6 | 20k / 600 px | **one static grab stands in for every frame** — only the last-frame comparison is meaningful |

Grade only the text-glyph regions, ours before/after the prototype vs these PNGs.

## Request 2: rotated border hairline weight

`avm1_edittext_rotated_borders/` (generator `create_test_swf.py`, built here): five bordered EMPTY embedded-font
EditTexts, 70×55 px box, rotated 15/30/45/60° at (1300,300)/(3300,300)/(5300,300)/(1300,2300) twips and sheared c=0.5
at (3300,2300); stage 300×200. Captures: `flash.draw.png` (draw() wrapper) and `flash.direct-pinned.png`
(direct pinned; 242 px / max 16 vs draw()).

## Harness re-run with the fixed pin stub (s28 `flash-oracle-harness`, 2026-11-25)

The pin stub never applied `quality = "low"` (it set `_global._quality`), so the Request-1 captures of the
AVM1 `quality = "low"` rows below were really at HIGH. They were re-captured with the fixed stub (same
`sweep_goldens.py --direct`): `png/<row>__<comp>.direct.newstub.png` + `<row>.direct.newstub.json`.
`avm1_long_text_layout` (quality high) and `avm1_edittext_rotated_borders` (no quality) are unaffected.

| row | old (HIGH) vs golden | new (LOW) vs golden | verdict change |
|---|---|---|---|
| `visual/filters/bevel` | 134 888 px | 118 027 px | none: still not Flash |
| `visual/filters/glow` | 19 543 px | 15 448 px | none |
| `visual/filters/drop_shadow` | 22 101 px | 18 137 px | none |
| `visual/filters/glow_with_alpha_strength` | 145 526 px | 134 231 px | none |
| `visual/cache_as_bitmap/edittext_scroll` .01/.02 | 423 / 421 px | 423 / 421 px (capture identical) | none |
| `visual/text/String_path_variable_button` | no capture | 778 px / max 153 | now captured (the old "untestable in direct mode" did not reproduce) |
| `from_gnash/misc-ming.all/morph_test1` frame6 | ~600 px | 325 px (frames 1–5 still ~20k: one static grab) | none (closer) |

Grading the text-glyph regions: use the `.newstub` PNGs for these rows.

