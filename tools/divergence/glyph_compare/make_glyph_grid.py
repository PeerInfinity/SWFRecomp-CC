#!/usr/bin/env python3
"""Build a minimal SWF showing every glyph of one embedded font in a grid.

Each glyph is drawn once via a DefineText style+glyph record at a grid cell.
Rendering the result with BOTH the Ruffle exporter and SWFRecomp and diffing
isolates per-glyph tessellation differences (see compare_both.py).

Usage:
    python3 make_glyph_grid.py <input.swf> <fontID> <out.swf> [--cols N] [--height TWIPS]

Example (Tetris title font is fontID 12, 42 glyphs):
    python3 make_glyph_grid.py ~/CC/flasharchive/Tetris.swf 12 /tmp/glyphs.swf
"""
import argparse
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import swf_lib as S


def build(input_swf: Path, font_id: int, cols: int, text_height: int) -> bytes:
    data = S.decompress(input_swf.read_bytes())
    font_tag = S.find_tag_by_id(data, S.FONT_TAGS, font_id)
    if font_tag is None:
        raise SystemExit(f"font id {font_id} not found")
    fid, ng = S.font2_num_glyphs(font_tag)
    rows = (ng + cols - 1) // cols
    cellw = text_height + 300
    cellh = int(text_height * 1.6) + 200
    x0, y0 = 200, text_height + 300
    glyphbits = max(1, (ng - 1).bit_length())
    advbits = 10

    # DefineText body
    body = bytearray()
    body += struct.pack('<H', 900)                       # text char id
    body += S.rect(0, cols * cellw + x0, 0, rows * cellh + y0)
    body += S.matrix_translate(0, 0)
    body.append(glyphbits)
    body.append(advbits)
    for g in range(ng):
        col, row = g % cols, g // cols
        x, y = x0 + col * cellw, y0 + row * cellh
        body.append(0x80 | 0x08 | 0x04 | 0x02 | 0x01)    # style: font,color,yoff,xoff
        body += struct.pack('<H', font_id)
        body += bytes([0, 0, 0])                         # RGB black
        body += struct.pack('<h', x)
        body += struct.pack('<h', y)
        body += struct.pack('<H', text_height)
        body.append(0x01)                                # 1-glyph record
        gb = S.Bits()
        gb.w(g, glyphbits)
        gb.w(0, advbits)
        body += gb.bytes()
    body.append(0x00)

    tags = bytearray()
    tags += S.set_background_color(255, 255, 255)
    tags += font_tag
    tags += S.tag(S.DEFINE_TEXT, bytes(body))
    tags += S.place_object2(1, 900)
    tags += S.show_frame()
    tags += S.end_tag()
    frame = S.rect(0, cols * cellw + x0 + 200, 0, rows * cellh + y0 + 200)
    return S.wrap_swf(frame, bytes(tags)), ng


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input_swf", type=Path)
    ap.add_argument("font_id", type=int)
    ap.add_argument("out_swf", type=Path)
    ap.add_argument("--cols", type=int, default=7)
    ap.add_argument("--height", type=int, default=800, help="text height in twips")
    args = ap.parse_args()
    swf, ng = build(args.input_swf, args.font_id, args.cols, args.height)
    args.out_swf.write_bytes(swf)
    print(f"wrote {args.out_swf} ({len(swf)} bytes); font {args.font_id} = {ng} glyphs, "
          f"grid {args.cols}x{(ng + args.cols - 1)//args.cols}")


if __name__ == "__main__":
    main()
