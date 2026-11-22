#!/usr/bin/env python3
"""avm1_attached_clip_color: Color.setRGB on attachMovie'd SPRITE clips must
tint their rendered content (and their attached descendants).

Pins (2026-11-22, N tile-colour slice): N tints ~900 attached `tileMC` clips
with `new Color(tileMC).setRGB(0x797A88)`. mcSyncColorToDisplayObj wrote the
colour onto the clip's standalone display entry, but render_attached_child
(and the OFFSCREEN capture pass) composed its sprite_display_list with a NULL
parent colour, so the tint never rendered (tiles stayed the raw #333).

Clips (40x40 px squares, sprite 10 = dark grey #333333, 11 = white):
  a  root-attached grey, setRGB(0x797A88)               -> blue-grey
  p  root-attached grey with an attached white child k at (0,45); setRGB(0xC08000)
     on p -> both p and k orange (the tint composes down)
  c  root-attached grey, untinted (control)
N's own case (attach into a createEmptyMovieClip buffer) is not here: the
OFFSCREEN capture draws root-attached clips only (non-root attaches are a
browser-WASM render path), so it is verified in the browser against N.
Trace: getRGB of each. Expected image + trace: Ruffle exporter --frames 3.
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

def shape3(sid, wpx, hpx, rgba):
    """DefineShape3 rect (0,0)-(w,h) px, solid RGBA fill, no lines."""
    W, H = wpx * 20, hpx * 20
    body = struct.pack("<H", sid) + rect(0, W, 0, H)
    body += bytes([1, 0x00]) + bytes(rgba) + bytes([0])
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
    return tag(32, body + w.bytes())

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

NEWOBJ = b"\x40"
def setrgb(path_code, rgb):
    return push(rgb, 1) + path_code + push(1, "Color") + NEWOBJ + push("setRGB") + CALLM + POP
def getrgb(path_code):
    return push(0) + path_code + push(1, "Color") + NEWOBJ + push("getRGB") + CALLM
def v(n): return push(n) + GETVAR
def attach_on(target_code, link, name, depth):
    return push(depth, name, link, 3) + target_code + push("attachMovie") + CALLM + POP

defs = (shape3(1, 40, 40, (0x33, 0x33, 0x33, 255)) + shape3(2, 40, 40, (255, 255, 255, 255))
        + sprite(10, [place2(1, 1)]) + sprite(11, [place2(1, 2)])
        + export(10, "grey") + export(11, "white"))
f1 = (attach("grey", "a", 1) + setp("a", "_x", 10) + setp("a", "_y", 10)
      + attach("grey", "p", 3) + setp("p", "_x", 110) + setp("p", "_y", 10)
      + attach_on(v("p"), "white", "k", 1)
      + push("p") + GETVAR + push("k") + GETMEM + push("_y", 45) + SETMEM
      + attach("grey", "c", 4) + setp("c", "_x", 160) + setp("c", "_y", 10)
      + setrgb(v("a"), 0x797A88)
      + setrgb(v("p"), 0xC08000))
def tr():
    c = push("rgb a=") + getrgb(v("a")) + ADD2
    c += push(" p=") + ADD2 + getrgb(v("p")) + ADD2
    c += push(" k=") + ADD2 + getrgb(push("p") + GETVAR + push("k") + GETMEM) + ADD2
    c += push(" c=") + ADD2 + getrgb(v("c")) + ADD2
    return c + TRACE
root = [doaction(f1 + tr()), doaction(b""), doaction(tr() + STOP)]
body = (tag(69, struct.pack("<I", 0)) + tag(9, b"\xff\xff\xff") + defs
        + b"".join(f + SHOW for f in root) + tag(0, b""))
hdr = rect(0, 210 * 20, 0, 110 * 20) + struct.pack("<HH", 30 << 8, len(root))
out = sys.argv[1] if len(sys.argv) > 1 else str(HERE / "test.swf")
open(out, "wb").write(b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(hdr) + len(body)) + hdr + body)
