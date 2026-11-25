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
