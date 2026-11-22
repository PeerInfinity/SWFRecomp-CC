#!/usr/bin/env python3
"""avm1_many_chars_registry: character metadata past the old fixed-table caps.

Pins (2026-11-22, N tile-colour/HUD slice): ng_shared.c kept per-character
metadata in fixed arrays: 64 EditTexts, 256 shape bounds, 64 morph end bounds,
256 shape paths, 64 morph paths. Anything past a cap was silently DROPPED.
Metanet "N" defines 197 EditTexts, 291 shapes and 86 morphs, so its HUD fields
(char 985 / 1026, the time readout and the level name) never got a TextField
wrapper: no text was drawn, `_width` was 0, and for..in did not list them. Its
late morph (the time bar) and late shapes had no bounds either.

This SWF defines 70 EditTexts, 300 shapes and 70 morph shapes. Their sprites
place the LAST of each, and are attached to _root. The trace reads _width and
_height, for..in children, the bound variable text and hitTest. Expected output
is from the Ruffle exporter (--frames 2). Trace only: the fields use a device
font, which the exporter does not draw like we do.
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

def rect(x0, x1, y0, y1, nb=15):
    w = BW(); w.u(nb, 5)
    for v in (x0, x1, y0, y1): w.sb(v, nb)
    return w.bytes()

def s(x): return x.encode() + b"\0"

def push(*items):
    b = b""
    for it in items:
        if isinstance(it, bool): b += b"\x05" + bytes([1 if it else 0])
        elif isinstance(it, str): b += b"\x00" + s(it)
        elif isinstance(it, int): b += b"\x07" + struct.pack("<i", it)
    return b"\x96" + struct.pack("<H", len(b)) + b

GETVAR, GETMEM, SETMEM, ADD2, TRACE, STOP, POP, CALLM = (
    b"\x1c", b"\x4e", b"\x4f", b"\x47", b"\x26", b"\x07", b"\x17", b"\x52")
SHOW = tag(1, b"")

def doaction(a): return tag(12, a + b"\0")
def place2(depth, cid): return tag(26, bytes([0x02]) + struct.pack("<HH", depth, cid))
def sprite(sid, frames):
    return tag(39, struct.pack("<HH", sid, len(frames)) + b"".join(f + SHOW for f in frames) + tag(0, b""))
def export(cid, name): return tag(56, struct.pack("<HH", 1, cid) + s(name))
def setp(t, prop, val): return push(t) + GETVAR + push(prop, val) + SETMEM
def attach(link, name, depth):
    return push(depth, name, link, 3, "_root") + GETVAR + push("attachMovie") + CALLM + POP
def trace_state(lbl):
    c = push(lbl)
    for n in ("a", "b", "c"):
        c += push(" " + n + "=") + ADD2 + push(n) + GETVAR + push("_visible") + GETMEM + ADD2
    return c + push(" a.cf=") + ADD2 + push("a") + GETVAR + push("_currentframe") + GETMEM + ADD2 + TRACE


def shape_rect(sid, wpx, hpx, rgba, code=2):
    W, H = wpx * 20, hpx * 20
    b = struct.pack("<H", sid) + rect(0, W, 0, H)
    b += bytes([1, 0x00]) + (bytes(rgba[:3]) if code == 2 else bytes(rgba)) + bytes([0])
    w = BW(); w.u(1, 4); w.u(0, 4)
    nb = 15
    w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(1, 1)
    w.u(nb, 5); w.sb(0, nb); w.sb(0, nb)
    w.u(1, 1)
    def edge(dx, dy):
        w.u(1, 1); w.u(1, 1); w.u(nb - 2, 4)
        if dy == 0: w.u(0, 1); w.u(0, 1); w.sb(dx, nb)
        else: w.u(0, 1); w.u(1, 1); w.sb(dy, nb)
    edge(W, 0); edge(0, H); edge(-W, 0); edge(0, -H)
    w.u(0, 6)
    return tag(code, b + w.bytes())

def morph_rect(sid, w0, h0, w1, h1):
    """DefineMorphShape: a w0 x h0 px rect morphing to w1 x h1 px, solid fill."""
    def recs(W, H, styles):
        w = BW()
        if styles: w.u(1, 4); w.u(0, 4)
        else: w.u(0, 4); w.u(0, 4)
        nb = 15
        w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(1 if styles else 0, 1); w.u(1, 1)
        w.u(nb, 5); w.sb(0, nb); w.sb(0, nb)
        if styles: w.u(1, 1)
        def edge(dx, dy):
            w.u(1, 1); w.u(1, 1); w.u(nb - 2, 4)
            if dy == 0: w.u(0, 1); w.u(0, 1); w.sb(dx, nb)
            else: w.u(0, 1); w.u(1, 1); w.sb(dy, nb)
        edge(W, 0); edge(0, H); edge(-W, 0); edge(0, -H)
        w.u(0, 6)
        return w.bytes()
    W0, H0, W1, H1 = w0 * 20, h0 * 20, w1 * 20, h1 * 20
    fills = bytes([1, 0x00]) + bytes([200, 0, 0, 255]) + bytes([0, 0, 200, 255])
    lines = bytes([0])
    start = recs(W0, H0, True)
    end = recs(W1, H1, False)
    after_offset = fills + lines + start
    b = struct.pack("<H", sid) + rect(0, W0, 0, H0) + rect(0, W1, 0, H1)
    b += struct.pack("<I", len(after_offset)) + after_offset + end
    return tag(46, b)

def edittext(cid, w, h, var, init):
    b = struct.pack("<H", cid) + rect(0, w * 20, 0, h * 20)
    b += bytes([0x80 | 0x04, 0x10])            # HasText|HasTextColor ; NoSelect
    b += bytes([0, 0, 0, 255])
    b += s(var) + s(init)
    return tag(37, b)

N_TF, N_SH, N_MO = 70, 300, 70
defs = b""
cid = 1
for i in range(N_TF):                       # ids 1..70
    defs += edittext(cid, 40 + i, 20, "txt", "init%d" % i); cid += 1
for i in range(N_SH):                       # ids 71..370
    defs += shape_rect(cid, 10 + (i % 7), 10 + (i % 5), (0, 120, 0, 255)); cid += 1
for i in range(N_MO):                       # ids 371..440
    defs += morph_rect(cid, 10 + (i % 3), 20, 30, 10 + (i % 4)); cid += 1
LAST_TF, LAST_SH, LAST_MO = N_TF, N_TF + N_SH, N_TF + N_SH + N_MO
def place2u(depth, c): return tag(26, bytes([0x02]) + struct.pack("<HH", depth, c))
defs += (sprite(1000, [place2u(1, LAST_TF)]) + sprite(1001, [place2u(1, LAST_SH)])
         + sprite(1002, [place2u(1, LAST_MO)])
         + export(1000, "lastTF") + export(1001, "lastShape") + export(1002, "lastMorph"))
def v(n): return push(n) + GETVAR
def g(code, prop): return code + push(prop) + GETMEM
f1 = (attach("lastTF", "tf", 1) + setp("tf", "_x", 10) + setp("tf", "_y", 10)
      + attach("lastShape", "sh", 2) + setp("sh", "_x", 10) + setp("sh", "_y", 50)
      + attach("lastMorph", "mo", 3) + setp("mo", "_x", 60) + setp("mo", "_y", 50)
      + setp("tf", "txt", "BOUND"))
def tr(lbl):
    c = push(lbl + " tf.w=") + g(v("tf"), "_width") + ADD2
    c += push(" tf.h=") + ADD2 + g(v("tf"), "_height") + ADD2
    c += push(" sh.w=") + ADD2 + g(v("sh"), "_width") + ADD2
    c += push(" sh.h=") + ADD2 + g(v("sh"), "_height") + ADD2
    c += push(" mo.w=") + ADD2 + g(v("mo"), "_width") + ADD2
    c += push(" mo.h=") + ADD2 + g(v("mo"), "_height") + ADD2
    c += push(" hit=") + ADD2 + push(True, 60, 15, 3) + v("sh") + push("hitTest") + CALLM + ADD2
    return c + TRACE
def tr_child():
    # for (k in tf) if (typeof tf[k] == "object") trace(k + " text=" + tf[k].text)
    # (written out: the field is auto-named instance1, the only child)
    c = push("child text=") + g(g(v("tf"), "instance1"), "text") + ADD2
    c += push(" type=") + ADD2 + g(v("tf"), "instance1") + b"\x44" + ADD2   # TypeOf
    return c + TRACE
root = [doaction(f1 + tr("f1") + tr_child()), doaction(tr("f2") + tr_child() + STOP)]
body = (tag(69, struct.pack("<I", 0)) + tag(9, b"\xff\xff\xff") + defs
        + b"".join(f + SHOW for f in root) + tag(0, b""))
hdr = rect(0, 200 * 20, 0, 100 * 20) + struct.pack("<HH", 30 << 8, len(root))
out = sys.argv[1] if len(sys.argv) > 1 else str(HERE / "test.swf")
open(out, "wb").write(b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(hdr) + len(body)) + hdr + body)
