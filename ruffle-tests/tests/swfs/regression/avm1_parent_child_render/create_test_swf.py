#!/usr/bin/env python3
"""Build child.swf and test.swf for regression/avm1_parent_child_render.

WHAT THIS PINS DOWN
-------------------
A loaded child movie's SHAPES are indexed by movie-LOCAL offsets into the
recompiler's per-movie geometry arrays:

    tagDefineShape(app_context, CHAR_TYPE_SHAPE, CHARID(id), vert_offset, ...)
    ng_record_char_path(CHARID(id), path_offset, path_size)

`vert_offset` indexes the emitting movie's own `shape_data` and `path_offset`
its own `path_data`, but every reader used the MAIN movie's arrays: the GPU
vertex buffer is uploaded once from the root's `shape_data`
(render_webgpu.c create_buffers_and_upload) and shape_hit_test.c read the
`path_data` symbol directly. A child's shape therefore drew the ROOT's
triangles at that index -- and, on the CPU, hit-tested against the root's
outline.

THE SHAPE
---------
    parent test.swf  (AVM1, SWF8, MTASC + spliced tags, 200x200 stage)
        sprite "ctl"    RED  square  px (20,20)-(80,80)     <- CONTROL
        holder          createEmptyMovieClip, loadMovie("child.swf")
    child.swf        (AVM1, SWF6, hand-built, 200x200 stage)
        sprite "sub"    BLUE square  px (120,20)-(180,80)   <- DISCRIMINATOR

Both movies define exactly ONE shape, so both sit at vertex offset 0 and path
offset 0 of their own arrays -- the collision that makes the wrong-array read
land on real, in-bounds, deterministic geometry rather than on garbage. The
two squares occupy DISJOINT x ranges, so a hit test that read the wrong
outline answers every probe backwards:

    probe                              master   fixed
    ctl.hitTest(50,50,true)            true     true    (control: unmoved)
    ctl.hitTest(150,50,true)           false    false   (control: unmoved)
    holder.hitTest(50,50,true)         TRUE     false   (reads the root's square)
    holder.hitTest(150,50,true)        FALSE    true    (its own square)
    holder.hitTest(150,50,false)       true     true    (bbox: Character bounds,
                                                         never an array index)

The bounding-box row is the third control: character bounds are stored as
values on the dictionary entry, not as an index into a per-movie array, so
they were always right. It separates "the child is placed and reachable"
(already true) from "the child's geometry is readable" (this slice).

The PIXEL half is graded by [image_comparisons.output] against a Ruffle
golden: master renders the red square only, the fix renders red AND blue.

Regenerate:  python3 create_test_swf.py
Golden:      ~/CC/ruffle/target/release/exporter test.swf output.expected.png -s
"""
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
T = 20   # twips per pixel


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


def matrix_scale_translate(scale, tx, ty):
    """MATRIX with a uniform scale (FIXED 16.16) and a twips translation."""
    b = Bits()
    fx = int(round(scale * 65536.0))
    nb = max(sbits_needed(fx), 1)
    b.u(1, 1)            # HasScale
    b.u(nb, 5)
    b.s(fx, nb)
    b.s(fx, nb)
    b.u(0, 1)            # HasRotate
    ntb = max(sbits_needed(tx, ty), 1)
    b.u(ntb, 5)
    b.s(tx, ntb)
    b.s(ty, ntb)
    return b.bytes()


def define_shape_gradient(shape_id, x0, y0, x1, y1, rgb):
    """DefineShape (tag 2): one rectangle filled with a LINEAR GRADIENT whose
    two stops are the same colour.

    Flat on purpose. The point of the row is the INDEX, not the ramp: a
    gradient fill's style word carries one number that the shader uses as both
    a ramp row and an inverse-matrix slot, and a loaded child's number is
    movie-local. With identical stops the rendered colour is exact at
    tolerance 0 and says which movie's ramp was sampled, with no dependence on
    ramp interpolation or sub-pixel gradient placement."""
    body = bytearray()
    body += struct.pack('<H', shape_id)
    body += rect(x0, x1, y0, y1)
    body.append(1)                  # FillStyleCount = 1
    body.append(0x10)               # linear gradient
    # The gradient square is -16384..16384 twips; map it onto the box.
    body += matrix_scale_translate((x1 - x0) / 32768.0,
                                   (x0 + x1) // 2, (y0 + y1) // 2)
    body.append(2)                  # SpreadMode 0 | InterpolationMode 0 | 2 stops
    body.append(0)
    body += bytes(rgb)
    body.append(255)
    body += bytes(rgb)
    body.append(0)                  # LineStyleCount = 0

    b = Bits()
    b.u(1, 4)                       # NumFillBits = 1
    b.u(0, 4)                       # NumLineBits = 0
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


def place_object2(depth, char_id, name=None):
    """PlaceObject2 (tag 26), identity matrix, optional instance name."""
    flags = 0x02 | 0x04             # HasCharacter | HasMatrix
    if name:
        flags |= 0x20               # HasName
    body = bytearray()
    body.append(flags)
    body += struct.pack('<H', depth)
    body += struct.pack('<H', char_id)
    body += MATRIX_IDENTITY
    if name:
        body += name.encode('ascii') + b'\x00'
    return tag(26, bytes(body))


def define_sprite(sprite_id, inner_tags):
    """DefineSprite (tag 39): one frame holding `inner_tags`."""
    body = struct.pack('<HH', sprite_id, 1) + inner_tags + tag(1, b'') + tag(0, b'')
    return tag(39, body)


# ---- child.swf ----------------------------------------------------------

CHILD_SHAPE_ID = 1
CHILD_SPRITE_ID = 2
CHILD_GRAD_ID = 3
CHILD_RGB = (0, 0, 255)             # blue
CHILD_BOX = (120, 20, 180, 80)      # px
CHILD_GRAD_RGB = (255, 0, 255)      # magenta
CHILD_GRAD_BOX = (120, 120, 180, 180)


def build_child(path):
    x0, y0, x1, y1 = CHILD_BOX
    tags = b''
    gx0, gy0, gx1, gy1 = CHILD_GRAD_BOX
    tags += define_shape(CHILD_SHAPE_ID, x0 * T, y0 * T, x1 * T, y1 * T, CHILD_RGB)
    tags += define_shape_gradient(CHILD_GRAD_ID, gx0 * T, gy0 * T, gx1 * T,
                                  gy1 * T, CHILD_GRAD_RGB)
    tags += define_sprite(CHILD_SPRITE_ID,
                          place_object2(1, CHILD_SHAPE_ID)
                          + place_object2(2, CHILD_GRAD_ID))
    # Depth 3, not 1: our runtime still shares ONE display list between the
    # parent and a loaded child (the Route 1 sub-arc), so a child that places
    # at the parent's depth 1 collides with `ctl` and is dropped outright
    # ("Failed to place object at depth 1"). The collision is a real defect,
    # tracked separately; this test is about geometry INDICES, so it keeps the
    # two movies on distinct depths rather than blocking on it.
    tags += place_object2(3, CHILD_SPRITE_ID, name='sub')
    tags += tag(1, b'')                     # ShowFrame
    tags += tag(0, b'')                     # End

    stage = rect(0, 200 * T, 0, 200 * T)
    body = stage + struct.pack('<H', 24 << 8) + struct.pack('<H', 1) + tags
    data = b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body
    path.write_bytes(data)
    print('Created %s (%d bytes, blue %s)' % (path, len(data), CHILD_BOX))


# ---- test.swf (MTASC + spliced shape) -----------------------------------

PARENT_SHAPE_ID = 900               # far from anything MTASC emits
PARENT_SPRITE_ID = 901
PARENT_GRAD_ID = 902
PARENT_RGB = (255, 0, 0)            # red
PARENT_BOX = (20, 20, 80, 80)       # px
PARENT_GRAD_RGB = (0, 128, 0)       # green
PARENT_GRAD_BOX = (20, 120, 80, 180)


def read_swf(path):
    raw = path.read_bytes()
    sig, version = raw[:3], raw[3]
    body = raw[8:]
    if sig == b'CWS':
        import zlib
        body = zlib.decompress(body)
    elif sig != b'FWS':
        raise SystemExit('%s: unsupported signature %r' % (path, sig))
    nbits = body[0] >> 3
    rect_len = (5 + 4 * nbits + 7) // 8
    prefix = body[:rect_len + 4]        # RECT + frame rate + frame count
    return version, prefix, body[rect_len + 4:]


def splice_before_first_showframe(path, extra):
    """Insert `extra` immediately before the first ShowFrame (tag 1).

    The placement has to be INSIDE frame 1, so this cannot use the
    insert-before-End splice that avm1_parent_child_bitmap uses for its
    definition-only tags.
    """
    version, prefix, tag_bytes = read_swf(path)
    pos = 0
    while pos + 2 <= len(tag_bytes):
        code_len = struct.unpack('<H', tag_bytes[pos:pos + 2])[0]
        code, length = code_len >> 6, code_len & 0x3F
        hdr = 2
        if length == 0x3F:
            length = struct.unpack('<I', tag_bytes[pos + 2:pos + 6])[0]
            hdr = 6
        if code == 1:
            break
        if code == 0:
            raise SystemExit('%s: no ShowFrame tag' % path)
        pos += hdr + length
    else:
        raise SystemExit('%s: ran off the end looking for ShowFrame' % path)

    body = prefix + tag_bytes[:pos] + extra + tag_bytes[pos:]
    path.write_bytes(b'FWS' + struct.pack('<BI', version, 8 + len(body)) + body)


def build_parent(path):
    mtasc = Path.home() / 'CC' / 'mtasc' / 'bin' / 'mtasc'
    std = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std'
    std8 = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std8'
    cmd = [str(mtasc), '-cp', str(std), '-cp', str(std8), '-main',
           '-header', '200:200:30', 'Parent.as', '-swf', path.name,
           '-version', '8']
    print('$ ' + ' '.join(cmd))
    subprocess.run(cmd, cwd=str(HERE), check=True)

    x0, y0, x1, y1 = PARENT_BOX
    extra = b''
    extra += tag(9, bytes((255, 255, 255)))      # SetBackgroundColor white
    gx0, gy0, gx1, gy1 = PARENT_GRAD_BOX
    extra += define_shape(PARENT_SHAPE_ID, x0 * T, y0 * T, x1 * T, y1 * T,
                          PARENT_RGB)
    extra += define_shape_gradient(PARENT_GRAD_ID, gx0 * T, gy0 * T, gx1 * T,
                                   gy1 * T, PARENT_GRAD_RGB)
    extra += define_sprite(PARENT_SPRITE_ID,
                           place_object2(1, PARENT_SHAPE_ID)
                           + place_object2(2, PARENT_GRAD_ID))
    extra += place_object2(1, PARENT_SPRITE_ID, name='ctl')
    splice_before_first_showframe(path, extra)
    print('Created %s (%d bytes, red %s spliced in)'
          % (path, path.stat().st_size, PARENT_BOX))


if __name__ == '__main__':
    build_child(HERE / 'child.swf')
    try:
        build_parent(HERE / 'test.swf')
    except FileNotFoundError:
        print('MTASC not found; test.swf left as-is', file=sys.stderr)
