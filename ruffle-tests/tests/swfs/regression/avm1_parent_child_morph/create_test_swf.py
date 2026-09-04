#!/usr/bin/env python3
"""Build child.swf and test.swf for regression/avm1_parent_child_morph.

WHAT THIS PINS DOWN
-------------------
A loaded child movie's MORPH SHAPE (DefineMorphShape) carries FOUR
movie-local offsets, each into a different per-movie array, and three of them
were read against the MAIN movie's:

    tagDefineMorphShape(app_context, CHARID(id),
                        shape_offset,            -> shape_data   (START verts)
                        shape_size,
                        morph_end_offset,        -> morph_end_shape_data
                        morph_color_start,       -> color_data   (START colours)
                        morph_color_count,
                        morph_end_color_start,   -> morph_end_color_data
                        ...)
    ng_record_morph_path(CHARID(id), path_offset, path_size)  -> path_data

Slice 7 re-based `shape_offset` and combined shape_data; the other three were
left deliberately un-re-based so they stayed consistent with each other. So a
loaded child's morph drew the ROOT's end vertices, lerped towards the ROOT's
end colour, WROTE its interpolated colour into the ROOT's colour slot, and
hit-tested against the ROOT's interleaved path run --
`ng_record_morph_path` did not record the defining movie's path table at all,
unlike its `ng_record_char_path` twin.

THE SHAPE
---------
    parent test.swf  (AVM1, SWF8, MTASC + spliced tags, 200x200 stage)
        sprite "ctl"  RED  morph, placed at ratio 65535   <- CONTROL
                      start px (20,20)-(80,180)  end px (20,20)-(80,80)
        holder        createEmptyMovieClip, loadMovie("child.swf")
    child.swf        (AVM1, SWF6, hand-built, 200x200 stage)
        sprite "sub"  BLUE morph, placed at ratio 65535   <- DISCRIMINATOR
                      start px (120,20)-(180,180) end px (120,20)-(180,80)

Each movie defines exactly ONE morph, so both sit at end-vertex offset 0,
colour index 0, end-colour index 0 and path offset 0 of their own arrays --
the collision that makes a wrong-array read land on real, in-bounds,
deterministic data.  The two morphs occupy DISJOINT x ranges and their START
and END rectangles occupy disjoint Y ranges, so the probes discriminate in
both directions:

    probe                              master   fixed
    ctl.hitTest(50,50,true)            true     true   (control: END rect)
    ctl.hitTest(50,150,true)           false    false  (control: inside the
                                                        START box, outside the
                                                        END rectangle)
    ctl.hitTest(150,50,true)           false    false  (control)
    sub.hitTest(50,50,true)            false*   false
    sub.hitTest(150,50,true)           FALSE    true   (its own)
    sub.hitTest(150,150,true)          false    false
    sub.hitTest(150,50,false)          true     true   (bbox: the morph's START
                                                        bounds, held as VALUES
                                                        on the dictionary entry,
                                                        never an array index)

    * master reaches the root's path run but the bounding-box fast reject in
      front of the outline walk uses the CHILD's own (correct) start bounds, so
      the x=50 probe never gets to compare against the root's rectangle. The
      150 row is the one that discriminates, and the pixels are where the rest
      of the arm is graded.

The trace half therefore moves one row (`chd:end:150` false->true) in BOTH
build modes; the image half moves 14400 pixels.

Both movies use the SAME colour for the morph's start and end, on purpose:
the row's point is which movie's colour SLOT is read and written, not ramp
fidelity, and identical endpoints make the rendered colour exact at tolerance
0 with no dependence on the lerp.  A wrong `morph_color_start` is still fully
visible because it is the WRITE target: the child would push its interpolated
blue into the ROOT's colour slot and turn the parent's square blue too.

Ratio 65535 is deliberate: at t = 1 the interpolated geometry is EXACTLY the
end vertices and the interpolated colour EXACTLY the end colour, so the render
lands on integer pixel edges and the image comparison holds at tolerance 0
with no dependence on how either rasteriser rounds a mid-ratio lerp.

Each morph is placed exactly ONCE. Our runtime lerps a morph's vertices into
the character's own vertex range (tag.c, renderer_update_vertices at
ch->morph_start_offset), so two instances of one morph character at different
ratios would overwrite each other -- a separate, pre-existing defect that has
nothing to do with per-movie tables.

Regenerate:  python3 create_test_swf.py
Golden:      RUFFLE_LOCAL_FETCH_DIR=<dir with armorgames.com/child.swf> \
             ~/CC/ruffle/target/release/exporter test.swf output.expected.png \
                 -s --skipframes 5 -f 1
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


def shape_records(move, edges, num_fill_bits, fill0):
    """SHAPE body: NumFillBits/NumLineBits, one StyleChangeRecord (MoveTo, and
    FillStyle0 when fill0 != 0), then straight edges, then EndShapeRecord.

    EndEdges pass num_fill_bits=0/fill0=0: a morph's END shape carries no style
    information of its own (the fill styles are the MORPHFILLSTYLEARRAY's END
    halves). Same shape as regression/avm2_morph's build_morph.py.
    """
    b = Bits()
    b.u(num_fill_bits, 4)
    b.u(0, 4)
    b.u(0, 1)                       # TypeFlag = 0 (non-edge)
    b.u(0, 1)                       # StateNewStyles
    b.u(0, 1)                       # StateLineStyle
    b.u(0, 1)                       # StateFillStyle1
    b.u(1 if fill0 else 0, 1)       # StateFillStyle0
    b.u(1, 1)                       # StateMoveTo
    mb = sbits_needed(move[0], move[1])
    b.u(mb, 5)
    b.s(move[0], mb)
    b.s(move[1], mb)
    if fill0:
        b.u(fill0, num_fill_bits)
    for dx, dy in edges:
        nb = max(sbits_needed(dx, dy), 2)
        b.u(1, 1)                   # TypeFlag = 1 (edge)
        b.u(1, 1)                   # StraightFlag = 1
        b.u(nb - 2, 4)
        b.u(1, 1)                   # GeneralLineFlag = 1
        b.s(dx, nb)
        b.s(dy, nb)
    b.u(0, 6)                       # EndShapeRecord
    return b.bytes()


def box_edges(x0, y0, x1, y1):
    w, h = x1 - x0, y1 - y0
    return [(w, 0), (0, h), (-w, 0), (0, -h)]


def define_morph_shape(morph_id, start_px, end_px, rgb):
    """DefineMorphShape (tag 46): one solid-filled rectangle morphing from
    `start_px` to `end_px`. Same colour at both ends -- see the module
    docstring."""
    sx0, sy0, sx1, sy1 = [v * T for v in start_px]
    ex0, ey0, ex1, ey1 = [v * T for v in end_px]

    fs = bytearray()
    fs.append(1)                    # FillStyleCount
    fs.append(0x00)                 # solid
    fs += bytes(rgb) + bytes((255,))    # StartColor RGBA
    fs += bytes(rgb) + bytes((255,))    # EndColor RGBA
    ls = bytes((0,))                # LineStyleCount

    start_edges = shape_records((sx0, sy0), box_edges(sx0, sy0, sx1, sy1),
                                num_fill_bits=1, fill0=1)
    end_edges = shape_records((ex0, ey0), box_edges(ex0, ey0, ex1, ey1),
                              num_fill_bits=0, fill0=0)

    body = bytearray()
    body += struct.pack('<H', morph_id)
    body += rect(sx0, sx1, sy0, sy1)        # StartBounds
    body += rect(ex0, ex1, ey0, ey1)        # EndBounds
    body += struct.pack('<I', len(fs) + len(ls) + len(start_edges))
    body += fs
    body += ls
    body += start_edges
    body += end_edges
    return tag(46, bytes(body))


def place_object2(depth, char_id, name=None, ratio=None):
    """PlaceObject2 (tag 26), identity matrix, optional ratio + name."""
    flags = 0x02 | 0x04             # HasCharacter | HasMatrix
    if ratio is not None:
        flags |= 0x10               # HasRatio
    if name:
        flags |= 0x20               # HasName
    body = bytearray()
    body.append(flags)
    body += struct.pack('<H', depth)
    body += struct.pack('<H', char_id)
    body += MATRIX_IDENTITY
    if ratio is not None:
        body += struct.pack('<H', ratio)
    if name:
        body += name.encode('ascii') + b'\x00'
    return tag(26, bytes(body))


def define_sprite(sprite_id, inner_tags):
    """DefineSprite (tag 39): one frame holding `inner_tags`."""
    body = struct.pack('<HH', sprite_id, 1) + inner_tags + tag(1, b'') + tag(0, b'')
    return tag(39, body)


RATIO_END = 65535       # pure END geometry and END colour: no lerp rounding


# ---- child.swf ----------------------------------------------------------

CHILD_MORPH_ID = 1
CHILD_SPRITE_ID = 2
CHILD_RGB = (0, 0, 255)                   # blue
# The START rectangle deliberately CONTAINS the END one. hitTest's
# bounding-box fast-reject uses ng_getCharBounds, which is the morph's START
# bounds and does not follow the ratio (a separate, pre-existing gap), so a
# start box that did not contain the end box would reject every probe before
# the outline walk ran. Containment also gives the ":start" rows for free: a
# point inside the START box but outside the END rectangle passes the AABB and
# must then MISS.
CHILD_START = (120, 20, 180, 180)         # px
CHILD_END = (120, 20, 180, 80)            # px


def build_child(path):
    tags = b''
    tags += define_morph_shape(CHILD_MORPH_ID, CHILD_START, CHILD_END, CHILD_RGB)
    tags += define_sprite(CHILD_SPRITE_ID,
                          place_object2(1, CHILD_MORPH_ID, ratio=RATIO_END))
    # Depth 3, not 1: our runtime still shares ONE display list between the
    # parent and a loaded child (the Route 1 sub-arc), so a child that places
    # at the parent's depth 1 collides with `ctl` and is dropped outright.
    tags += place_object2(3, CHILD_SPRITE_ID, name='sub')
    tags += tag(1, b'')                     # ShowFrame
    tags += tag(0, b'')                     # End

    stage = rect(0, 200 * T, 0, 200 * T)
    body = stage + struct.pack('<H', 24 << 8) + struct.pack('<H', 1) + tags
    data = b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body
    path.write_bytes(data)
    print('Created %s (%d bytes, blue morph end %s)' % (path, len(data), CHILD_END))


# ---- test.swf (MTASC + spliced tags) ------------------------------------

PARENT_MORPH_ID = 920               # far from anything MTASC emits
PARENT_SPRITE_ID = 921
PARENT_RGB = (255, 0, 0)            # red
PARENT_START = (20, 20, 80, 180)    # px (contains END; see CHILD_START)
PARENT_END = (20, 20, 80, 80)       # px


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
    """Insert `extra` immediately before the first ShowFrame (tag 1)."""
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

    extra = b''
    extra += tag(9, bytes((255, 255, 255)))      # SetBackgroundColor white
    extra += define_morph_shape(PARENT_MORPH_ID, PARENT_START, PARENT_END,
                                PARENT_RGB)
    extra += define_sprite(PARENT_SPRITE_ID,
                           place_object2(1, PARENT_MORPH_ID, ratio=RATIO_END))
    extra += place_object2(1, PARENT_SPRITE_ID, name='ctl')
    splice_before_first_showframe(path, extra)
    print('Created %s (%d bytes, red morph end %s spliced in)'
          % (path, path.stat().st_size, PARENT_END))


if __name__ == '__main__':
    build_child(HERE / 'child.swf')
    try:
        build_parent(HERE / 'test.swf')
    except FileNotFoundError:
        print('MTASC not found; test.swf left as-is', file=sys.stderr)
