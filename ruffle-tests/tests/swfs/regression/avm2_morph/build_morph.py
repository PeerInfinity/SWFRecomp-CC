#!/usr/bin/env python3
"""Splice a hand-authored DefineMorphShape + 3 PlaceObject2 into an mxmlc SWF.

The morph is a solid rectangle (shape-local px): left=10 top=10 bottom=40; right
edge grows 50px (start) -> 90px (end). Solid fill morphs RED (start) -> BLUE
(end). It is placed at depths 1/2/3 with ratios 0 / 32768 / 65535 and vertical
translate 0 / 100 / 200 px. See Main.as for the getPixel gate.
"""
import sys, zlib, struct

MORPH_ID = 0x0100  # 256 — well above any mxmlc-assigned id (there are none)

# ---- bit writer (MSB-first, SWF convention) ------------------------------
class Bits:
    def __init__(self):
        self.acc = 0; self.n = 0; self.out = bytearray()
    def u(self, val, bits):
        for i in range(bits - 1, -1, -1):
            self.acc = (self.acc << 1) | ((val >> i) & 1); self.n += 1
            if self.n == 8:
                self.out.append(self.acc); self.acc = 0; self.n = 0
    def s(self, val, bits):
        if val < 0: val = (1 << bits) + val
        self.u(val, bits)
    def align(self):
        if self.n: self.out.append(self.acc << (8 - self.n)); self.acc = 0; self.n = 0
    def bytes(self):
        self.align(); return bytes(self.out)

def sbits_needed(*vals):
    m = 1
    for v in vals:
        b = v.bit_length() + 1 if v >= 0 else (~v).bit_length() + 1
        m = max(m, b)
    return m

def rect(xmin, xmax, ymin, ymax):
    nb = 0
    for v in (xmin, xmax, ymin, ymax):
        nb = max(nb, sbits_needed(v))
    b = Bits(); b.u(nb, 5)
    for v in (xmin, xmax, ymin, ymax): b.s(v, nb)
    return b.bytes()

def rgba(r, g, b_, a): return bytes((r, g, b_, a))

def shape_records(moves, edges, num_fill_bits, fill0):
    """moves=(dx,dy) initial MoveTo; edges=list of (dx,dy) straight lines.
    fill0: fill style index to set (0 to omit)."""
    b = Bits()
    b.u(num_fill_bits, 4)   # NumFillBits
    b.u(0, 4)               # NumLineBits
    # StyleChangeRecord: MoveTo (+ FillStyle0 when fill0 != 0)
    b.u(0, 1)               # TypeFlag=0 (non-edge)
    b.u(0, 1)               # StateNewStyles
    b.u(0, 1)               # StateLineStyle
    b.u(0, 1)               # StateFillStyle1
    b.u(1 if fill0 else 0, 1)  # StateFillStyle0
    b.u(1, 1)               # StateMoveTo
    mb = sbits_needed(moves[0], moves[1])
    b.u(mb, 5); b.s(moves[0], mb); b.s(moves[1], mb)
    if fill0:
        b.u(fill0, num_fill_bits)
    # StraightEdgeRecords (general lines)
    for (dx, dy) in edges:
        nb = sbits_needed(dx, dy)
        if nb < 2: nb = 2
        b.u(1, 1)           # TypeFlag=1 (edge)
        b.u(1, 1)           # StraightFlag=1
        b.u(nb - 2, 4)      # NumBits
        b.u(1, 1)           # GeneralLineFlag=1
        b.s(dx, nb); b.s(dy, nb)
    # EndShapeRecord: 6 zero bits
    b.u(0, 6)
    return b.bytes()

def define_morph_shape():
    T = 20  # twips per px
    # shape-local twips
    L, R0, R1, TOP, BOT = 10*T, 50*T, 90*T, 10*T, 40*T
    start_bounds = rect(L, R0, TOP, BOT)
    end_bounds   = rect(L, R1, TOP, BOT)
    # Fill styles: 1 solid, start RED end BLUE, opaque.
    fs = bytearray()
    fs.append(1)                       # FillStyleCount
    fs.append(0x00)                    # FillStyleType solid
    fs += rgba(255, 0, 0, 255)         # StartColor red
    fs += rgba(0, 0, 255, 255)         # EndColor blue
    # Line styles: none
    ls = bytes((0,))
    # Start edges: rect L,TOP -> R0,TOP -> R0,BOT -> L,BOT -> close
    start_edges = shape_records(
        (L, TOP),
        [(R0 - L, 0), (0, BOT - TOP), (-(R0 - L), 0), (0, -(BOT - TOP))],
        num_fill_bits=1, fill0=1)
    # End edges: rect L,TOP -> R1,TOP -> R1,BOT -> L,BOT -> close (no styles)
    end_edges = shape_records(
        (L, TOP),
        [(R1 - L, 0), (0, BOT - TOP), (-(R1 - L), 0), (0, -(BOT - TOP))],
        num_fill_bits=0, fill0=0)
    body = bytearray()
    body += struct.pack('<H', MORPH_ID)
    body += start_bounds
    body += end_bounds
    offset = len(fs) + len(ls) + len(start_edges)  # bytes after Offset -> EndEdges
    body += struct.pack('<I', offset)
    body += fs
    body += ls
    body += start_edges
    body += end_edges
    return tag(46, bytes(body))

def matrix_translate(tx, ty):
    b = Bits()
    b.u(0, 1)  # HasScale
    b.u(0, 1)  # HasRotate
    nb = sbits_needed(tx, ty)
    b.u(nb, 5); b.s(tx, nb); b.s(ty, nb)
    return b.bytes()

def place_object2(depth, char_id, ratio, tx, ty):
    flags = (1 << 4) | (1 << 2) | (1 << 1)  # HasRatio | HasMatrix | HasCharacter
    body = bytearray()
    body.append(flags)
    body += struct.pack('<H', depth)
    body += struct.pack('<H', char_id)
    body += matrix_translate(tx, ty)
    body += struct.pack('<H', ratio)
    return tag(26, bytes(body))

def tag(code, data):
    n = len(data)
    if n < 0x3f:
        return struct.pack('<H', (code << 6) | n) + data
    return struct.pack('<H', (code << 6) | 0x3f) + struct.pack('<I', n) + data

# ---- read base SWF, splice, write out ------------------------------------
def read_swf(path):
    raw = open(path, 'rb').read()
    sig = raw[:3]
    if sig == b'CWS':
        body = zlib.decompress(raw[8:])
    elif sig == b'FWS':
        body = raw[8:]
    else:
        raise SystemExit("unsupported SWF signature %r" % sig)
    version = raw[3]
    return version, body

def parse_after_header(body):
    # FrameSize RECT
    nb = body[0] >> 3
    total_bits = 5 + 4 * nb
    rect_len = (total_bits + 7) // 8
    pos = rect_len + 2 + 2  # + FrameRate + FrameCount
    header = body[:pos]
    return header, pos

def iter_tags(body, pos):
    tags = []
    while pos < len(body):
        (rh,) = struct.unpack_from('<H', body, pos); pos += 2
        code = rh >> 6; length = rh & 0x3f
        if length == 0x3f:
            (length,) = struct.unpack_from('<I', body, pos); pos += 4
        data = body[pos:pos + length]; pos += length
        tags.append((code, data))
        if code == 0:  # End
            break
    return tags

def main():
    inp, outp = sys.argv[1], sys.argv[2]
    version, body = read_swf(inp)
    header, pos = parse_after_header(body)
    tags = iter_tags(body, pos)

    morph_tags = [define_morph_shape(),
                  place_object2(1, MORPH_ID, 0,     0,   0),
                  place_object2(2, MORPH_ID, 32768, 0, 100 * 20),
                  place_object2(3, MORPH_ID, 65535, 0, 200 * 20)]

    out_tags = bytearray()
    inserted = False
    for (code, data) in tags:
        if code == 1 and not inserted:  # first ShowFrame — insert morphs before it
            for mt in morph_tags:
                out_tags += mt
            inserted = True
        out_tags += tag(code, data)
    if not inserted:
        raise SystemExit("no ShowFrame found in base SWF")

    new_body = header + bytes(out_tags)
    file_len = 8 + len(new_body)
    out = b'FWS' + bytes((version,)) + struct.pack('<I', file_len) + new_body
    open(outp, 'wb').write(out)
    print("morph id=%d, %d tags, %d bytes" % (MORPH_ID, len(tags) + len(morph_tags), file_len))

if __name__ == '__main__':
    main()
