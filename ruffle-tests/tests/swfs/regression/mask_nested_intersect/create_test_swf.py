#!/usr/bin/env python3
"""Build test.swf for mask_nested_intersect.

Authored by session 11 (`session11-fanout-reports/w2-masks-defectA`, section
"Regression tests"), held back until the nesting work existed; dropped in by
session 14's `gfx-stencil` patch, which is the change it pins.

Pins **nested mask INTERSECTION semantics**: a root clip mask whose maskee is
a sprite that itself contains a clip mask.

    root   depth 1: shape M1 = rect   (0,0)-(120,120)  clipDepth = 2
           depth 2: sprite S                            <- masked by M1
    sprite depth 1: shape M2 = rect (60,60)-(180,180)  clipDepth = 2
           depth 2: shape G  = rect   (0,0)-(200,200) GREEN   <- masked by M2

Correct (Ruffle exporter, `output.expected.png`): green ONLY in M1 n M2 =
(60,60)-(120,120) — exactly 3600 green / 36400 white pixels, TWO colours,
no anti-aliasing anywhere.

  * at HEAD (one stencil value for every mask): green over M1 u M2 = 25200 px
  * with the defect-A per-mask-reference fix:   green over M2      = 14400 px
  * only an increment/decrement mask STACK (mask-write pipeline
    `compare = Equal @ depth-1, passOp = IncrementClamp`, mask-clear pipeline
    `compare = Equal @ depth, passOp = DecrementClamp` + a screen-covering
    decrement draw in end_clip) reaches the golden's 3600 px.

So this test DISCRIMINATES between the three stencil models, which is why it
is the pin for the increment/decrement work: a per-mask-reference fix alone
still leaves 10800 outlier channels.

`clipDepth` is a PlaceObject2 field with NO ActionScript equivalent, so MTASC
and mxmlc cannot author this movie; the whole file is emitted as raw SWF tag
bytes. Every shape is an axis-aligned rectangle on integer pixel boundaries,
so neither Ruffle's exporter nor our MSAA produces partial coverage on any
edge and the test is gradeable at `tolerance = 0` — same construction as
`mask_sibling_union`.

Regenerate:  python3 create_test_swf.py
Golden:      ~/CC/ruffle/target/release/exporter test.swf output.expected.png -s
             (the ONLY legal provenance for a regression-suite golden: an
             oracle outside SWFRecomp — playbook §7)
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



def define_sprite(sprite_id, inner_tags):
    """DefineSprite (tag 39) with a single frame of control tags."""
    body = struct.pack('<HH', sprite_id, 1) + inner_tags + tag(1, b'') + tag(0, b'')
    return tag(39, body)


T = 20   # twips per pixel

inner = place_object2(1, 2, clip_depth=2) + place_object2(2, 3)

tags = b''
tags += tag(9, bytes((255, 255, 255)))                                       # white bg
tags += define_shape(1,  0 * T,  0 * T, 120 * T, 120 * T, (0, 0, 0))         # M1
tags += define_shape(2, 60 * T, 60 * T, 180 * T, 180 * T, (0, 0, 0))         # M2
tags += define_shape(3,  0 * T,  0 * T, 200 * T, 200 * T, (0, 160, 0))       # G
tags += define_sprite(4, inner)
tags += place_object2(1, 1, clip_depth=2)
tags += place_object2(2, 4)
tags += do_action_trace('mask_nested_intersect')
tags += tag(1, b'')                                                          # ShowFrame
tags += tag(0, b'')                                                          # End

stage = rect(0, 200 * T, 0, 200 * T)
body = stage + struct.pack('<H', 24 << 8) + struct.pack('<H', 1) + tags
data = b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body

with open('test.swf', 'wb') as fh:
    fh.write(data)
print('Created test.swf (%d bytes)' % len(data))
