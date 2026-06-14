# glyph_compare — isolated per-asset Ruffle vs SWFRecomp diffing

Tooling to extract a single asset (one embedded font's glyphs, one DefineShape,
or to inspect DefineText) out of a real SWF, wrap it in a minimal SWF, and
render it with **both** the Ruffle exporter and SWFRecomp for a pixel diff.

This was built to localize the `#18b` "missing e/r nub" bug in the Tetris title
and it **disproved** the original diagnosis: the 42 embedded-font glyphs render
**byte-identical** to Ruffle, and the actual bug is in `DefineShape 26` (the
vector "tetris" logo), not font glyphs. See `tools/divergence/PROGRESS.md` #18b.

## Prerequisites
- Ruffle exporter: `cd ~/CC/ruffle && cargo +nightly build --release -p exporter`
  (binary at `~/CC/ruffle/target/release/exporter`).
- Built `SWFRecomp` + local Dawn (same as the divergence harness / graphics mode).

## Tools

- **`make_glyph_grid.py <swf> <fontID> <out.swf>`** — minimal SWF showing every
  glyph of an embedded font in a grid (one DefineText, one glyph per cell).
- **`extract_shape.py <swf> <out.swf> <shapeID...> [--recolor R,G,B ...] [--bg R,G,B]`**
  — pull DefineShape(s) into a minimal SWF; `--recolor` repaints each solid fill
  style a distinct color to reveal per-fill-style assignment.
- **`decode_definetexts.py <swf>`** — print every DefineText's font + glyph index
  sequence (proves what text each one renders).
- **`compare_both.py <test.swf> [out_dir] [--crop x0,y0,x1,y1]`** — render with
  Ruffle + SWFRecomp, print diff bbox/extrema (`None` == byte-identical), write
  `side_by_side.png` and magnified `crop_{ruffle,swfrecomp}.png`.
- **`swf_lib.py`** — shared minimal SWF read/write primitives (stdlib only).

## Reproduce the #18b findings

```bash
cd ~/CC/SWFRecomp-CC
G=tools/divergence/glyph_compare
T=~/CC/flasharchive/Tetris.swf

# 1. Font glyphs are NOT the bug — all 42 byte-identical (DIFF bbox=None):
python3 $G/make_glyph_grid.py $T 12 /tmp/glyphs.swf
python3 $G/compare_both.py /tmp/glyphs.swf

# 2. The title is DefineShape 26 (a vector logo), and IT differs at the e/r nubs:
python3 $G/extract_shape.py $T /tmp/shape.swf 26 --bg 221,238,255
python3 $G/compare_both.py /tmp/shape.swf          # DIFF bbox over the e/r nubs

# 3. Recolor to see the missing nubs are fill-style-1 (Ruffle fills, we carve):
python3 $G/extract_shape.py $T /tmp/recolor.swf 26 --recolor 255,0,0 0,180,0 --bg 255,255,255
python3 $G/compare_both.py /tmp/recolor.swf

# 4. No DefineText spells "tetris" (title is a shape, not text):
python3 $G/decode_definetexts.py $T
```

Glyph→char map for the Tetris title font (font 12, from the grid, reading
left-to-right top-to-bottom): index 0=space, 1=`,` 2=`-` 3=`.` 4-13=`0`..`9`,
14=`:` 15=`?` 16-41 = `a b c d e F g h i j k l m n o p q R s t u v w x y z`.
So e.g. DefineText 13 glyphs `[27,30,16,19,24,29,22]` = `l o a d i n g`.
