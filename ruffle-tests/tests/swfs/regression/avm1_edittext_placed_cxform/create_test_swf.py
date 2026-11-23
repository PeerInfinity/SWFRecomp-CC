#!/usr/bin/env python3
"""avm1_edittext_placed_cxform: PlaceObject CXFORMs reach AVM1/timeline EditText.

Pins (s26 w2-text-cx-jpeg3, acid-color-0 chain step 1): TextFieldRenderInfo /
TextFieldGlyphInfo carried literal RGB and the renderer drew box + glyphs with
cxform slot 0, so no colour transform on an EditText or on any ancestor sprite
ever reached the text (from_shumway/acid/acid-color-0: green "ABC" and green
"Hello" box drew in their untransformed colours). Fixed by composing the
ancestor chain in action.c (tf_cx_for_mc / the orphan walk) and applying it to
background, border, text colour and every run colour.

Three placements of an embedded-font (one square "I" glyph, pixel-aligned at
FontHeight 1024 twips) bordered EditText, every cx built from 0/1 multipliers
and whole adds so the expected colours are exact:
  depth 1  sprite(ET black)  cx mult(0,1,1) add(0,255,0)
           bg white->(0,255,255) text/border black->(0,255,0)
  depth 2  ET (green text) placed DIRECTLY  cx mult(1,0,0) add(0,0,128)
           bg white->(255,0,128) text green / border black->(0,0,128)
  depth 3  outer sprite cx mult(1,1,0) add(0,128,0) holding
           inner sprite cx mult(1,0,0) add(0,0,255) holding ET (black)
           bg white->(255,0,255)->(255,128,0) text black->(0,0,255)->(0,128,0)
Alpha is identity everywhere (alpha already reached text before the fix).

Two SWFs from this generator (same content):
  test.swf          no script: the fields take the orphan-EditText walk
                    (otf_walk_dl), like acid-color-0
  ../avm1_edittext_placed_cxform_script/test.swf
                    a frame script names every field (instance names s1.f, f2,
                    s3.s.f) and traces its text, so they get TextField
                    MovieClip wrappers (actionIterateTextFields / ...Glyphs)

Expected PNG: Ruffle exporter 0ddd12b6a render (output.expected.png, landed
by s26 w2-edittext-border-cx). Its 9 TL/TR/BL border-corner pixels are 3/4
covered (Ruffle's Dx12-only emulate_line_rect); the corpus-golden rule we
render inks them solid, so test.toml budgets exactly those 19 channels.
"""
import pathlib, struct, sys

HERE = pathlib.Path(__file__).resolve().parent


def tag(code, body):
    if len(body) < 0x3F:
        return struct.pack("<H", (code << 6) | len(body)) + body
    return struct.pack("<HI", (code << 6) | 0x3F, len(body)) + body


class BW:
    def __init__(s): s.bits = []
    def u(s, v, n):
        for i in range(n - 1, -1, -1): s.bits.append((v >> i) & 1)
    def sb(s, v, n): s.u(v & ((1 << n) - 1), n)
    def bytes(s):
        b = s.bits + [0] * ((-len(s.bits)) % 8)
        return bytes(int("".join(map(str, b[i:i + 8])), 2) for i in range(0, len(b), 8))


def nbits_s(*vals):
    n = 1
    for v in vals:
        while not (-(1 << (n - 1)) <= v < (1 << (n - 1))): n += 1
    return n


def rect(x0, x1, y0, y1):
    nb = nbits_s(x0, x1, y0, y1)
    w = BW(); w.u(nb, 5)
    for v in (x0, x1, y0, y1): w.sb(v, nb)
    return w.bytes()


def matrix_translate(tx, ty):
    w = BW(); w.u(0, 1); w.u(0, 1)
    nb = nbits_s(tx, ty); w.u(nb, 5); w.sb(tx, nb); w.sb(ty, nb)
    return w.bytes()


def cxform(mult, add):
    """CXFORMWITHALPHA (PlaceObject2). mult in {0,1} -> 8.8 fixed 0 / 256;
    add whole; alpha identity (mult 256, add 0)."""
    m = [int(round(x * 256)) for x in mult] + [256]
    a = list(add) + [0]
    nb = nbits_s(*m, *a)
    w = BW(); w.u(1, 1); w.u(1, 1); w.u(nb, 4)
    for v in m: w.sb(v, nb)
    for v in a: w.sb(v, nb)
    return w.bytes()


def s(x): return x.encode() + b"\0"


def place2(depth, cid, tx, ty, cx=None, name=None):
    flags = 0x02 | 0x04  # HasCharacter | HasMatrix
    if cx is not None: flags |= 0x08
    if name is not None: flags |= 0x20
    b = bytes([flags]) + struct.pack("<HH", depth, cid) + matrix_translate(tx, ty)
    if cx is not None: b += cxform(*cx)
    if name is not None: b += s(name)
    return tag(26, b)


SHOW = tag(1, b"")


def sprite(sid, tags):
    return tag(39, struct.pack("<HH", sid, 1) + b"".join(tags) + SHOW + tag(0, b""))


def font2(fid):
    """DefineFont2, one glyph 'I': a filled square x 100..400, y -700..0 em
    units (1024 em). At FontHeight 1024 twips 1 em unit = 1 twip, so every
    edge sits on a whole pixel."""
    w = BW()
    w.u(1, 4); w.u(0, 4)                       # NumFillBits=1 NumLineBits=0
    # StyleChange: MoveTo + FillStyle1 (Flash glyph convention)
    # TypeFlag 0, NewStyles 0, LineStyle 0, FillStyle1 1, FillStyle0 0, MoveTo 1
    w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(0, 1); w.u(1, 1)
    nb = nbits_s(100, -700); w.u(nb, 5); w.sb(100, nb); w.sb(-700, nb)
    w.u(1, 1)                                  # FillStyle1 = 1
    def line(dx, dy):
        w.u(1, 1); w.u(1, 1)                   # edge, straight
        n = max(nbits_s(dx, dy), 2); w.u(n - 2, 4)
        if dx != 0 and dy != 0:
            w.u(1, 1); w.sb(dx, n); w.sb(dy, n)
        else:
            w.u(0, 1)
            if dx != 0: w.u(0, 1); w.sb(dx, n)
            else: w.u(1, 1); w.sb(dy, n)
    line(300, 0); line(0, 700); line(-300, 0); line(0, -700)
    w.u(0, 6)                                  # EndShape
    glyph = w.bytes()
    name = b"Sq"
    body = struct.pack("<H", fid) + bytes([0x80, 1, len(name)]) + name
    body += struct.pack("<H", 1)               # NumGlyphs
    # OffsetTable (1 entry) + CodeTableOffset, u16, relative to the table start
    body += struct.pack("<HH", 4, 4 + len(glyph)) + glyph
    body += bytes([ord("I")])                  # CodeTable (u8, no WideCodes)
    body += struct.pack("<HHh", 800, 200, 0)   # ascent, descent, leading
    body += struct.pack("<h", 500)             # advance
    body += rect(100, 400, -700, 0)            # bounds
    body += struct.pack("<H", 0)               # kerning count
    return tag(48, body)


def edittext(cid, fid, color, text):
    b = struct.pack("<H", cid) + rect(0, 1400, 0, 1100)
    b += bytes([0x80 | 0x04 | 0x01,            # HasText | HasTextColor | HasFont
                0x08 | 0x01 | 0x10 | 0x20])     # Border | UseOutlines | NoSelect | HasLayout
    b += struct.pack("<HH", fid, 1024)
    b += bytes(color) + b"\xff"
    b += bytes([0]) + struct.pack("<HHHh", 0, 0, 0, 0)   # layout: left, no margins
    b += s("")                                 # VariableName
    b += s(text)
    return tag(37, b)


def doaction(code): return tag(12, code + b"\0")


def push_str(*xs):
    b = b"".join(b"\x00" + s(x) for x in xs)
    return b"\x96" + struct.pack("<H", len(b)) + b


GETVAR, GETMEM, TRACE, ADD2 = b"\x1c", b"\x4e", b"\x26", b"\x47"


def trace_text(path):
    """trace(path + '=' + <path>.text)  with path like 's1.f'."""
    parts = path.split(".")
    code = push_str(path + "=") + push_str(parts[0]) + GETVAR
    for p in parts[1:]:
        code += push_str(p) + GETMEM
    code += push_str("text") + GETMEM + ADD2 + TRACE
    return code


def build(path, script):
    tags = []
    tags.append(tag(9, b"\xff\xff\xff"))       # SetBackgroundColor white
    tags.append(font2(1))
    tags.append(edittext(5, 1, (0, 0, 0), "II"))
    tags.append(edittext(6, 1, (0, 255, 0), "II"))
    tags.append(sprite(10, [place2(1, 5, 0, 0, name="f")]))
    tags.append(sprite(11, [place2(1, 10, 0, 0, cx=((1, 0, 0), (0, 0, 255)), name="s")]))
    tags.append(place2(1, 10, 200, 200, cx=((0, 1, 1), (0, 255, 0)), name="s1"))
    tags.append(place2(2, 6, 1800, 200, cx=((1, 0, 0), (0, 0, 128)), name="f2"))
    tags.append(place2(3, 11, 200, 1600, cx=((1, 1, 0), (0, 128, 0)), name="s3"))
    if script:
        tags.append(doaction(trace_text("s1.f") + trace_text("f2") + trace_text("s3.s.f")))
    tags.append(SHOW)
    tags.append(tag(0, b""))
    body = rect(0, 3600, 0, 3000) + struct.pack("<HH", 30 << 8, 1) + b"".join(tags)
    data = b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(body)) + body
    path.write_bytes(data)


if __name__ == "__main__":
    build(HERE / "test.swf", False)
    twin = HERE.parent / "avm1_edittext_placed_cxform_script"
    twin.mkdir(exist_ok=True)
    build(twin / "test.swf", True)
    print("wrote", HERE / "test.swf", twin / "test.swf")
