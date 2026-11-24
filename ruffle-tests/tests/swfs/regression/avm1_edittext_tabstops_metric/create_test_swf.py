#!/usr/bin/env python3
"""avm1_edittext_tabstops_metric: TextField.textWidth with TABs, and the painter
with explicit TextFormat.tabStops (s27 n-levels-5plus).

Default stops (no tabStops): Flash Player 32 = multiples of
T = 2 * (ascent + descent) (each truncated to whole twips at the run size)
counted from the field's left EDGE (text origin + 2 px gutter); textWidth is
the laid-out width truncated to whole px. ng_shared.c used Ruffle's 2.7 * size
from the text origin (d=59 b=64 c=39 vs Flash d=45 b=93 c=24).
Explicit tabStops: from the TEXT origin; a tab past the last stop does not
advance the pen (painter: tag.c tf_tab_stop).

Font: the 'A' square font of avm1_edittext_tab_render (advance 512/1024,
ascent 900, descent 200).
Golden: Flash Player 32 oracle (trace + image, tick 1).
Regenerate: python3 create_test_swf.py
"""
# ---- shared fixture helpers (s26 w2-robustness-land) ----
import pathlib, struct, sys, zlib
HERE = pathlib.Path(sys.argv[0]).resolve().parent

def tag(code, body, force_long=False):
    if len(body) < 0x3F and not force_long:
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

def rect(x0, x1, y0, y1, nb=16):
    w = BW(); w.u(nb, 5)
    for v in (x0, x1, y0, y1): w.sb(v, nb)
    return w.bytes()

def matrix_t(tx, ty):            # translate-only MATRIX (twips)
    w = BW(); w.u(0, 1); w.u(0, 1); w.u(16, 5); w.sb(tx, 16); w.sb(ty, 16)
    return w.bytes()

def cxform_mult(rm, gm, bm):     # CXFORM (no alpha) with mult terms only, 8.8
    w = BW(); w.u(0, 1); w.u(1, 1); w.u(10, 4)
    for v in (rm, gm, bm): w.sb(v, 10)
    return w.bytes()

def s(x): return x.encode() + b"\0"

def push(*items):
    b = b""
    for it in items:
        if it is None: b += b"\x03"
        elif isinstance(it, bool): b += b"\x05" + bytes([1 if it else 0])
        elif isinstance(it, str): b += b"\x00" + s(it)
        elif isinstance(it, int): b += b"\x07" + struct.pack("<i", it)
    return b"\x96" + struct.pack("<H", len(b)) + b

GETVAR, SETVAR, GETMEM, SETMEM, ADD2, TRACE, STOP, PLAY, POP = (
    b"\x1c", b"\x1d", b"\x4e", b"\x4f", b"\x47", b"\x26", b"\x07", b"\x06", b"\x17")
CALLM, CALLF, NEWOBJ, TYPEOF, RETURN = b"\x52", b"\x3d", b"\x40", b"\x44", b"\x3e"
SHOW = tag(1, b"")
def doaction(a): return tag(12, a + b"\0")
def v(n): return push(n) + GETVAR
def g(code, prop): return code + push(prop) + GETMEM
def callm(obj_code, meth, *args):
    return push(*reversed(args), len(args)) + obj_code + push(meth) + CALLM
def callf(name, *args):
    return push(*reversed(args), len(args), name) + CALLF
def line(*parts):
    c = push(parts[0]) if isinstance(parts[0], str) else parts[0]
    for p in parts[1:]:
        c += (push(p) if isinstance(p, str) else p) + ADD2
    return c + TRACE

def square_records(W, H, fillbits=1, x0=0, y0=0):
    w = BW(); w.u(fillbits, 4); w.u(0, 4)
    nb = 16
    w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(1, 1)  # fs1, moveto
    w.u(nb, 5); w.sb(x0, nb); w.sb(y0, nb)
    w.u(1, fillbits)
    def edge(dx, dy):
        w.u(1, 1); w.u(1, 1); w.u(nb - 2, 4)
        if dy == 0: w.u(0, 1); w.u(0, 1); w.sb(dx, nb)
        else: w.u(0, 1); w.u(1, 1); w.sb(dy, nb)
    edge(W, 0); edge(0, H); edge(-W, 0); edge(0, -H)
    w.u(0, 6)
    return w.bytes()

def shape_rect(sid, wpx, hpx, rgb):
    W, H = wpx * 20, hpx * 20
    b = struct.pack("<H", sid) + rect(0, W, 0, H)
    b += bytes([1, 0x00]) + bytes(rgb) + b"\x00"   # 1 solid fill, 0 line styles
    b += square_records(W, H, 1)
    return tag(2, b)

def sprite(sid, frames):
    return tag(39, struct.pack("<HH", sid, len(frames)) + b"".join(f + SHOW for f in frames) + tag(0, b""), force_long=True)

def write_swf(defs_and_frames, nframes, w=200, h=150, version=8, bg=b"\xff\xff\xff"):
    body = tag(69, struct.pack("<I", 0)) + tag(9, bg) + defs_and_frames + tag(0, b"")
    hdr = rect(0, w * 20, 0, h * 20) + struct.pack("<HH", 30 << 8, nframes)
    out = sys.argv[1] if len(sys.argv) > 1 else str(HERE / "test.swf")
    open(out, "wb").write(b"FWS" + bytes([version]) + struct.pack("<I", 8 + len(hdr) + len(body)) + hdr + body)

def cxformwa_mult(rm, gm, bm, am):   # CXFORMWITHALPHA, mult terms only (8.8)
    w = BW(); w.u(0, 1); w.u(1, 1); w.u(10, 4)
    for x in (rm, gm, bm, am): w.sb(x, 10)
    return w.bytes()

def place2(flags, depth, cid=None, mat=None, cx=None, name=None):
    b = bytes([flags]) + struct.pack("<H", depth)
    if cid is not None: b += struct.pack("<H", cid)
    if mat is not None: b += mat
    if cx is not None: b += cx
    if name is not None: b += s(name)
    return tag(26, b)

# ---- fixture ----
def glyph_square_fs1(W, H, x0, y0):
    """Glyph SHAPE: one W x H square at (x0, y0), filled on its RIGHT side
    (FillStyle1) along the clockwise (y-down) contour, the Flash convention."""
    w = BW(); w.u(1, 4); w.u(0, 4)
    nb = 16
    w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(0, 1); w.u(1, 1)  # fs1, moveto
    w.u(nb, 5); w.sb(x0, nb); w.sb(y0, nb)
    w.u(1, 1)                                          # FillStyle1 = 1
    def edge(dx, dy):
        w.u(1, 1); w.u(1, 1); w.u(nb - 2, 4)
        if dy == 0: w.u(0, 1); w.u(0, 1); w.sb(dx, nb)
        else: w.u(0, 1); w.u(1, 1); w.sb(dy, nb)
    edge(W, 0); edge(0, H); edge(-W, 0); edge(0, -H)
    w.u(0, 6)
    return w.bytes()

def font2(fid, name):
    glyph = glyph_square_fs1(400, 600, 0, -600)        # 'A'
    empty = bytes([0x10, 0x00])                        # numFill=1 numLine=0, EndShape
    glyphs = [empty, empty, glyph]                     # ' ', '-', 'A' (ascending codes)
    off = 2 * (len(glyphs) + 1)
    offs = []
    for gl in glyphs:
        offs.append(off); off += len(gl)
    table = b"".join(struct.pack("<H", o) for o in offs) + struct.pack("<H", off)
    b = struct.pack("<HBB", fid, 0x80 | 0x04, 1) + bytes([len(name)]) + name.encode()
    b += struct.pack("<H", len(glyphs)) + table + b"".join(glyphs)
    b += struct.pack("<HHH", 32, 45, 65)                       # code table, ASCENDING
    b += struct.pack("<hhh", 900, 200, 0) + struct.pack("<hhh", 512, 512, 512)
    b += rect(0, 0, 0, 0) + rect(0, 0, 0, 0) + rect(0, 400, -600, 0) + struct.pack("<H", 0)
    return tag(48, b, force_long=True)

def edittext(cid, fid, w, h, text, align=0, lm=0, indent=0, size=200, wrap=0):
    b = struct.pack("<H", cid) + rect(0, w * 20, 0, h * 20)
    # text, WORDWRAP, multiline, ro, color, font | layout, noselect, border, outlines
    b += bytes([0x80 | (0x40 if wrap else 0) | 0x20 | 0x08 | 0x04 | 0x01, 0x20 | 0x10 | 0x08 | 0x01])
    b += struct.pack("<HH", fid, size)
    b += bytes([0, 0, 0, 255])                           # black
    b += bytes([align]) + struct.pack("<HHhh", lm * 20, 0, indent * 20, 0)
    b += s("") + s(text)
    return tag(37, b, force_long=True)


INITARRAY = b"\x42"
defs = font2(1, "F")
defs += edittext(2, 1, 100, 50, "A\tA\r\tAA\r\t\tA\rAAAAAA\tA")
defs += edittext(3, 1, 130, 50, "\tA\r\t\tA", size=400)
defs += edittext(4, 1, 100, 30, "\tA\rAAAA", align=2)
defs += edittext(5, 1, 100, 20, "\tA\t\tA")
defs += edittext(6, 1, 100, 20, "AAAAAAAA\tA")
defs += edittext(7, 1, 100, 20, "\tA\tA", lm=10)
defs += edittext(8, 1, 100, 20, "A\tA\tA\tA\tA")
defs += edittext(9, 1, 100, 20, "\tA\tA", indent=10)
defs += edittext(10, 1, 100, 20, "\tA\tA", lm=10)
f1 = b""
for i, (cid, nm, x, y) in enumerate([(2, "d", 10, 10), (3, "b", 120, 10), (4, "c", 10, 80),
                                     (5, "s", 120, 70), (6, "e", 120, 95), (7, "m", 10, 115),
                                     (8, "w", 120, 120), (9, "n", 10, 135), (10, "q", 120, 135)]):
    f1 += place2(0x02 | 0x04 | 0x20, i + 1, cid=cid, mat=matrix_t(x * 20, y * 20), name=nm)

def set_stops(field, *stops):
    c = push("tf") + push(0, "TextFormat") + NEWOBJ + SETVAR
    c += v("tf") + push("tabStops") + push(*reversed(stops), len(stops)) + INITARRAY + SETMEM
    c += v("tf") + push(1) + v(field) + push("setTextFormat") + CALLM + POP
    return c

probe = set_stops("s", 15, 40) + set_stops("e", 15) + set_stops("q", 15, 40)
for nm in ("d", "b", "c", "s", "e", "m", "w", "n", "q"):
    probe += line(nm + " textWidth=", g(v(nm), "textWidth"))
f1 += doaction(probe + STOP)
write_swf(defs + f1 + SHOW, 1, w=260, h=160)
