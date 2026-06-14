#!/usr/bin/env python3
"""Extract one or more DefineShape tags into a minimal SWF for A/B rendering.

Optionally RECOLOR the shape's solid fill styles to distinct colors. This is
the key diagnostic for the #18b bug: recoloring DefineShape 26's two fills
(fill1->red, fill2->green) makes it obvious that the missing 'e'/'r' nubs are
fill-style-1 regions that Ruffle fills and SWFRecomp carves.

Usage:
    python3 extract_shape.py <input.swf> <out.swf> <shapeID> [shapeID ...]
                             [--recolor R,G,B R,G,B ...]   (one color per fill style index)
                             [--bg R,G,B]

Examples:
    # Tetris title logo, original colors:
    python3 extract_shape.py ~/CC/flasharchive/Tetris.swf /tmp/shape.swf 26 --bg 221,238,255
    # Recolored to expose fill assignment (fill1=red, fill2=green):
    python3 extract_shape.py ~/CC/flasharchive/Tetris.swf /tmp/recolor.swf 26 \
            --recolor 255,0,0 0,180,0 --bg 255,255,255
"""
import argparse
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import swf_lib as S


def recolor_shape_tag(tag_bytes: bytes, colors) -> bytes:
    """Patch the solid (type 0) fill styles of a DefineShape1/2/3 tag in place.

    `colors` is a list of (r,g,b); the i-th solid fill is set to colors[i]
    (clamped to the number provided). Only handles DefineShape1/2/3 with solid
    fills + the FILLSTYLEARRAY at the front (sufficient for logo-style shapes).
    """
    b = bytearray(tag_bytes)
    th = struct.unpack('<H', b[:2])[0]
    hs = 6 if (th & 0x3F) == 0x3F else 2
    q = hs + 2                                   # skip charID
    nb = (b[q] >> 3) & 0x1F
    q += (5 + nb * 4 + 7) // 8                   # skip bounds RECT
    nfs = b[q]
    q += 1
    for i in range(nfs):
        if b[q] != 0:                            # non-solid fill: stop (can't safely patch)
            break
        q += 1
        if i < len(colors):
            b[q], b[q + 1], b[q + 2] = colors[i]
        q += 3
    return bytes(b)


def build(input_swf, out_swf, shape_ids, recolor, bg):
    data = S.decompress(input_swf.read_bytes())
    tags = bytearray()
    tags += S.set_background_color(*bg)
    maxx = maxy = 0
    placements = []
    y_cursor = 200
    for cid in shape_ids:
        raw = S.find_tag_by_id(data, S.SHAPE_TAGS, cid)
        if raw is None:
            raise SystemExit(f"DefineShape id {cid} not found")
        if recolor:
            raw = recolor_shape_tag(raw, recolor)
        tags += raw
        placements.append((cid, 200, y_cursor))
        y_cursor += 1600
    for depth, (cid, tx, ty) in enumerate(placements, 1):
        tags += S.place_object2(depth, cid, tx, ty)
    tags += S.show_frame()
    tags += S.end_tag()
    frame = S.rect(0, 4000, 0, y_cursor + 400)
    out_swf.write_bytes(S.wrap_swf(frame, bytes(tags)))
    print(f"wrote {out_swf}; shapes {shape_ids}"
          + (f" recolored {recolor}" if recolor else ""))


def _rgb(s):
    return tuple(int(x) for x in s.split(','))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input_swf", type=Path)
    ap.add_argument("out_swf", type=Path)
    ap.add_argument("shape_ids", type=int, nargs="+")
    ap.add_argument("--recolor", type=_rgb, nargs="*", default=None,
                    help="one R,G,B per fill style index (e.g. 255,0,0 0,180,0)")
    ap.add_argument("--bg", type=_rgb, default=(255, 255, 255))
    args = ap.parse_args()
    build(args.input_swf, args.out_swf, args.shape_ids, args.recolor, args.bg)


if __name__ == "__main__":
    main()
