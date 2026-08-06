#!/usr/bin/env python3
"""Build test.swf for mask_sibling_union.

Pins **per-mask stencil isolation**: two SIBLING timeline clip masks in one
frame, whose maskees each cover the whole stage and therefore overlap the
other mask's region.

    depth 1: shape A = rect   (0,0)-(100,100)  clipDepth = 2   -> masks depth 2
    depth 2: shape B = rect   (0,0)-(200,200)  BLUE            <- masked by A
    depth 3: shape C = rect (100,100)-(200,200) clipDepth = 4  -> masks depth 4
    depth 4: shape D = rect   (0,0)-(200,200)  RED             <- masked by C

Correct (and what Ruffle's exporter produces, `output.expected.png`): a blue
top-left quadrant, a red bottom-right quadrant, white elsewhere — exactly
20000 white / 10000 blue / 10000 red pixels, THREE distinct colours.

Before the defect-A fix (render_webgpu.c: the stencil is cleared once per
render PASS and every mask wrote the same hard-coded reference value 1), the
stencil held `1` over A u C by the time D drew, so D's stencil test passed
over the union and red painted the blue quadrant as well — a 10000-pixel,
colour-exact signature.

`clipDepth` is a PlaceObject2 field with NO ActionScript equivalent, so MTASC
and mxmlc cannot author this movie; the whole file is emitted as raw SWF tag
bytes. Every shape is an axis-aligned rectangle on integer pixel boundaries,
deliberately: neither Ruffle's exporter nor our unconditional 4x MSAA produces
any partial coverage on such an edge, so unlike the upstream
`visual/simple_shapes/masks` twins (whose goldens were exported with
`quality = "low"`, i.e. anti-aliasing OFF, against our 4x MSAA) this test is
gradeable at `tolerance = 0` today.

Regenerate:  python3 create_test_swf.py
Golden:      ~/CC/ruffle/target/release/exporter test.swf output.expected.png -s
"""
import struct


# ---- bit writer (MSB-first, SWF convention) ------------------------------
class Bits:
    def __init__(self):
        self.acc = 0
        self.n = 0
        self.out = bytearray()

    def u(self, val, bits):
        for i in range(bits - 1, -1, -1):
            self.acc = (self.acc << 1) | ((val >> i) & 1)
            self.n += 1
            if self.n == 8:
                self.out.append(self.acc)
                self.acc = 0
                self.n = 0

    def s(self, val, bits):
        if val < 0:
            val = (1 << bits) + val
        self.u(val, bits)

    def bytes(self):
        if self.n:
            self.out.append(self.acc << (8 - self.n))
            self.acc = 0
            self.n = 0
        return bytes(self.out)


def sbits_needed(*vals):
    m = 1
    for v in vals:
        m = max(m, v.bit_length() + 1 if v >= 0 else (~v).bit_length() + 1)
    return m


def rect(xmin, xmax, ymin, ymax):
    nb = max(sbits_needed(v) for v in (xmin, xmax, ymin, ymax))
    b = Bits()
    b.u(nb, 5)
    for v in (xmin, xmax, ymin, ymax):
        b.s(v, nb)
    return b.bytes()


def tag(code, data):
    n = len(data)
    if n < 0x3F:
        return struct.pack('<H', (code << 6) | n) + data
    return struct.pack('<H', (code << 6) | 0x3F) + struct.pack('<I', n) + data


MATRIX_IDENTITY = bytes([0x00])   # HasScale=0, HasRotate=0, NTranslateBits=0


def define_shape(shape_id, x0, y0, x1, y1, rgb):
    """DefineShape (tag 2): one solid-filled rectangle. Coordinates in TWIPS."""
    body = bytearray()
    body += struct.pack('<H', shape_id)
    body += rect(x0, x1, y0, y1)
    body.append(1)                  # FillStyleCount = 1
    body.append(0x00)               # FILLSTYLE type 0x00 = solid
    body += bytes(rgb)              # RGB
    body.append(0)                  # LineStyleCount = 0

    b = Bits()
    b.u(1, 4)                       # NumFillBits = 1
    b.u(0, 4)                       # NumLineBits = 0
    # STYLECHANGERECORD: MoveTo(x0,y0) + FillStyle0 = 1
    b.u(0, 1)                       # TypeFlag = 0 (non-edge)
    b.u(0, 1)                       # StateNewStyles
    b.u(0, 1)                       # StateLineStyle
    b.u(0, 1)                       # StateFillStyle1
    b.u(1, 1)                       # StateFillStyle0
    b.u(1, 1)                       # StateMoveTo
    nb = sbits_needed(x0, y0)
    b.u(nb, 5)
    b.s(x0, nb)
    b.s(y0, nb)
    b.u(1, 1)                       # FillStyle0 index = 1
    w, h = x1 - x0, y1 - y0
    for dx, dy in ((w, 0), (0, h), (-w, 0), (0, -h)):
        n2 = max(sbits_needed(dx, dy), 2)
        b.u(1, 1)                   # TypeFlag = 1 (edge)
        b.u(1, 1)                   # StraightFlag = 1
        b.u(n2 - 2, 4)              # NumBits
        b.u(1, 1)                   # GeneralLineFlag = 1
        b.s(dx, n2)
        b.s(dy, n2)
    b.u(0, 6)                       # EndShapeRecord
    body += b.bytes()
    return tag(2, bytes(body))


def place_object2(depth, char_id, clip_depth=0):
    """PlaceObject2 (tag 26), identity matrix, optional ClipDepth."""
    flags = 0x02 | 0x04             # HasCharacter | HasMatrix
    if clip_depth:
        flags |= 0x40               # HasClipDepth
    body = bytearray()
    body.append(flags)
    body += struct.pack('<H', depth)
    body += struct.pack('<H', char_id)
    body += MATRIX_IDENTITY
    if clip_depth:
        body += struct.pack('<H', clip_depth)
    return tag(26, bytes(body))


def do_action_trace(msg):
    """DoAction (tag 12): trace(msg); END."""
    item = b'\x00' + msg.encode('utf-8') + b'\x00'
    acts = struct.pack('<BH', 0x96, len(item)) + item + b'\x26' + b'\x00'
    return tag(12, acts)


T = 20   # twips per pixel

tags = b''
tags += tag(9, bytes((255, 255, 255)))                    # SetBackgroundColor white
tags += define_shape(1,   0 * T,   0 * T, 100 * T, 100 * T, (0, 0, 0))      # A mask
tags += define_shape(2,   0 * T,   0 * T, 200 * T, 200 * T, (0, 0, 255))    # B blue
tags += define_shape(3, 100 * T, 100 * T, 200 * T, 200 * T, (0, 0, 0))      # C mask
tags += define_shape(4,   0 * T,   0 * T, 200 * T, 200 * T, (255, 0, 0))    # D red
tags += place_object2(1, 1, clip_depth=2)
tags += place_object2(2, 2)
tags += place_object2(3, 3, clip_depth=4)
tags += place_object2(4, 4)
tags += do_action_trace('mask_sibling_union')
tags += tag(1, b'')                                       # ShowFrame
tags += tag(0, b'')                                       # End

stage = rect(0, 200 * T, 0, 200 * T)
body = stage + struct.pack('<H', 24 << 8) + struct.pack('<H', 1) + tags
data = b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body

with open('test.swf', 'wb') as fh:
    fh.write(data)
print('Created test.swf (%d bytes)' % len(data))
