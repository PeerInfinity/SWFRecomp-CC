#!/usr/bin/env python3
"""Build child.swf and test.swf for regression/avm1_parent_child_text.

WHAT THIS PINS DOWN
-------------------
A loaded child movie's STATIC TEXT (DefineFont2 + DefineText) is indexed by
movie-LOCAL offsets into four different per-movie arrays, and every one of them
was read against the MAIN movie's:

    tagDefineText(app_context, CHARID(id), text_start, text_size,
                  transform_start, cxform_id, ...)

  * `text_start`      indexes the emitting movie's `text_data`,
  * each `text_data` ROW is a glyph index into that movie's `glyph_data`,
  * each `glyph_data` row is a VERTEX offset into that movie's `shape_data`,
  * `transform_start` is the first of one baked glyph-positioning matrix per
    glyph in that movie's `transform_data`,
  * `cxform_id` is the text COLOUR, as a slot in that movie's `cxform_data`.

So a loaded child's static text drew the ROOT's glyph outlines, at the ROOT's
glyph positions, in the ROOT's text colour -- and hit-tested against the root's
glyph triangles.

THE SHAPE
---------
    parent test.swf  (AVM1, SWF8, MTASC + spliced tags, 200x200 stage)
        sprite "ctl"    RED  glyph 'P'  px (20,20)-(80,80)    <- CONTROL
        holder          createEmptyMovieClip, loadMovie("child.swf")
    child.swf        (AVM1, SWF6, hand-built, 200x200 stage)
        sprite "sub"    BLUE glyph 'C'  px (120,20)-(180,80)  <- DISCRIMINATOR

Each movie defines exactly ONE font with exactly ONE glyph and exactly ONE
DefineText, so both sit at text index 0, glyph index 0, vertex offset 0 and
transform slot 0 of their own arrays -- the collision that makes the
wrong-array read land on real, in-bounds, deterministic data rather than on
garbage.  The glyph is a filled square, and the two squares occupy DISJOINT x
ranges, so a hit test that read the wrong movie's outline-and-position answers
both probes backwards:

    probe                              master   fixed
    ctl.hitTest(50,50,true)            true     true    (control: unmoved)
    ctl.hitTest(150,50,true)           false    false   (control: unmoved)
    sub.hitTest(50,50,true)            false*   false
    sub.hitTest(150,50,true)           FALSE    true    (its own)
    sub.hitTest(150,50,false)          true     true    (bbox: Character bounds,
                                                         never an array index)

    * master answers this one right for the wrong reason, exactly as
      avm1_parent_child_render's shape row does: `transform_start` 0 reads the
      ROOT's transform_data row 0, which is not where the parent's glyph sits,
      so the child's glyph lands nowhere and BOTH x probes miss. Fixing only
      the glyph outline and not the position would leave this row a wrong
      `false`; the 150 row is what discriminates.

The TextSnapshot rows grade a different array on the same index: `text_data`
carries glyph indices and `text_char_codes` carries the Unicode code point for
the same row, so getText() reads the row `text_start` names.  The parent's
glyph is code 'P' and the child's is 'C' -- master reports 'P' for both,
because `text_start` 0 is the ROOT's row 0.

The trace half therefore moves two rows (`chd:glyph:150` false->true and
`chd:snap` P->C) in BOTH build modes; the image half moves 7200 pixels.

The PIXEL half grades the two arrays a trace cannot see: the glyph OUTLINE
(shape_data, via glyph_data) and the text COLOUR (cxform_data, via cxform_id).
Master renders one red square; the fix renders red AND blue.

Regenerate:  python3 create_test_swf.py
Golden:      ~/CC/ruffle/target/release/exporter test.swf output.expected.png -s
             (with RUFFLE_LOCAL_FETCH_DIR set to this directory, or the
             NullNavigator drops child.swf silently)
"""
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
T = 20      # twips per pixel
EM = 1024   # DefineFont2 EM square


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


def rect_shaperecords(x0, y0, x1, y1):
    """SHAPERECORDS for one solid rectangle, fill style 1, no line style.

    Shared by DefineShape bodies and DefineFont2 GLYPH shapes -- a glyph SHAPE
    is exactly this with no id, no bounds and no style arrays in front of it.
    """
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
    return b.bytes()


def define_font2(font_id, name, char_code):
    """DefineFont2 (tag 48): ONE glyph, a filled square filling the EM box
    ABOVE the baseline (SWF glyph space is y-down with the baseline at 0).

    No layout section: without an advance table the recompiler emits no
    tagDefineFontGlyphBase, and static text does not need one -- DefineText
    names glyphs by index, not by character code. The code table is still
    written because text_char_codes (TextSnapshot) is read from it.
    """
    glyph = rect_shaperecords(0, -EM, EM, 0)
    body = bytearray()
    body += struct.pack('<H', font_id)
    body.append(0x04)               # Flags: WideCodes only (no layout, narrow offsets)
    body.append(0)                  # LanguageCode
    body.append(len(name))
    body += name.encode('ascii')
    body += struct.pack('<H', 1)    # NumGlyphs = 1
    # OffsetTable[1] + CodeTableOffset, both UI16 from the start of OffsetTable
    off_table_len = 2 * 2
    body += struct.pack('<H', off_table_len)                 # glyph 0
    body += struct.pack('<H', off_table_len + len(glyph))    # code table
    body += glyph
    body += struct.pack('<H', char_code)                     # wide code table
    return tag(48, bytes(body))


def define_text(text_id, font_id, x_twips, y_twips, height_twips, rgb,
                bounds):
    """DefineText (tag 11): one text record, one glyph, at an absolute pen
    position. RGB (no alpha) -- DefineText2 would be tag 33."""
    body = bytearray()
    body += struct.pack('<H', text_id)
    body += rect(*bounds)
    body += MATRIX_IDENTITY
    body.append(4)                  # GlyphBits
    body.append(8)                  # AdvanceBits
    # TextRecord: HasFont | HasColor | HasYOffset | HasXOffset
    body.append(0x80 | 0x08 | 0x04 | 0x02 | 0x01)
    body += struct.pack('<H', font_id)
    body += bytes(rgb)
    body += struct.pack('<hh', x_twips, y_twips)
    body += struct.pack('<H', height_twips)
    body.append(1)                  # GlyphCount
    b = Bits()
    b.u(0, 4)                       # GlyphIndex 0
    b.s(0, 8)                       # GlyphAdvance 0
    body += b.bytes()
    body.append(0)                  # end of text records
    return tag(11, bytes(body))


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


def text_box(px_x0, px_y0):
    """Twips (xmin, xmax, ymin, ymax) of a 60x60 px glyph box at px_x0/px_y0,
    plus the pen position that puts it there. The glyph fills the EM box above
    the baseline, so the pen sits at the BOTTOM-left corner."""
    h = 60
    x0, y0 = px_x0 * T, px_y0 * T
    x1, y1 = (px_x0 + h) * T, (px_y0 + h) * T
    return (x0, x1, y0, y1), x0, y1


TEXT_HEIGHT = 60 * T                # 1024 glyph units -> 1200 twips -> 60 px


# ---- child.swf ----------------------------------------------------------

CHILD_FONT_ID = 1
CHILD_TEXT_ID = 2
CHILD_SPRITE_ID = 3
CHILD_RGB = (0, 0, 255)             # blue
CHILD_PX = (120, 20)
CHILD_CODE = ord('C')


def build_child(path):
    bounds, pen_x, pen_y = text_box(*CHILD_PX)
    tags = b''
    tags += define_font2(CHILD_FONT_ID, 'ChildFont', CHILD_CODE)
    tags += define_text(CHILD_TEXT_ID, CHILD_FONT_ID, pen_x, pen_y,
                        TEXT_HEIGHT, CHILD_RGB, bounds)
    tags += define_sprite(CHILD_SPRITE_ID, place_object2(1, CHILD_TEXT_ID))
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
    print('Created %s (%d bytes, blue glyph at px %s)' % (path, len(data), CHILD_PX))


# ---- test.swf (MTASC + spliced tags) ------------------------------------

PARENT_FONT_ID = 910                # far from anything MTASC emits
PARENT_TEXT_ID = 911
PARENT_SPRITE_ID = 912
PARENT_RGB = (255, 0, 0)            # red
PARENT_PX = (20, 20)
PARENT_CODE = ord('P')


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

    bounds, pen_x, pen_y = text_box(*PARENT_PX)
    extra = b''
    extra += tag(9, bytes((255, 255, 255)))      # SetBackgroundColor white
    extra += define_font2(PARENT_FONT_ID, 'ParentFont', PARENT_CODE)
    extra += define_text(PARENT_TEXT_ID, PARENT_FONT_ID, pen_x, pen_y,
                         TEXT_HEIGHT, PARENT_RGB, bounds)
    extra += define_sprite(PARENT_SPRITE_ID, place_object2(1, PARENT_TEXT_ID))
    extra += place_object2(1, PARENT_SPRITE_ID, name='ctl')
    splice_before_first_showframe(path, extra)
    print('Created %s (%d bytes, red glyph at px %s spliced in)'
          % (path, path.stat().st_size, PARENT_PX))


if __name__ == '__main__':
    build_child(HERE / 'child.swf')
    try:
        build_parent(HERE / 'test.swf')
    except FileNotFoundError:
        print('MTASC not found; test.swf left as-is', file=sys.stderr)
