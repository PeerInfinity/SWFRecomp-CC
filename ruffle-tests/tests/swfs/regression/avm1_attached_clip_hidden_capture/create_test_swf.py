#!/usr/bin/env python3
"""avm1_attached_clip_hidden_capture: a root-attached clip with _visible=false
must not appear in a graphics-native captured image.

Pins (2026-11-22, N gold-residue slice): tagRerenderFrame, the OFFSCREEN
per-tick image-capture render, drew every root-attached (child_mc_cache) clip
without checking mc->visible. tagShowFrame's pass skips hidden clips inside
render_attached_child, so only captured PNGs were wrong. Found while
fixturing N's gold coin (its COLLECTED timeline ends with
`this._visible = false` and then loops back to the frame-1 coin shape: the
hidden coin reappeared in every capture). Trace output was always correct.
Only the image comparison sees the bug, and image comparisons do not gate
pass/fail.

Clips (all attached to _root, 40x40 px squares):
  a  red, 3-frame timeline: f1 draws the square, f3 runs
     `this._visible=false`, then loops (coin-like). Hidden from root f3 on.
  b  blue, hidden on attach, re-shown on root f2 (must be drawn).
  c  green, never hidden (control).
Expected image (root f6): b and c only. Trace: Ruffle exporter --frames 6.
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

defs = (shape3(1, 40, 40, (255, 0, 0, 255)) + shape3(2, 40, 40, (0, 0, 255, 255))
        + shape3(3, 40, 40, (0, 160, 0, 255))
        + sprite(10, [place2(1, 1), b"", doaction(push("this") + GETVAR + push("_visible", False) + SETMEM)])
        + sprite(11, [place2(1, 2)]) + sprite(12, [place2(1, 3)])
        + export(10, "red") + export(11, "blue") + export(12, "green"))
f1 = (attach("red", "a", 1) + setp("a", "_x", 20) + setp("a", "_y", 30)
      + attach("blue", "b", 2) + setp("b", "_x", 80) + setp("b", "_y", 30) + setp("b", "_visible", False)
      + attach("green", "c", 3) + setp("c", "_x", 140) + setp("c", "_y", 30))
root = [doaction(f1 + trace_state("r1")),
        doaction(setp("b", "_visible", True) + trace_state("r2"))]
root += [doaction(trace_state("r%d" % i)) for i in range(3, 6)]
root += [doaction(trace_state("r6") + STOP)]
body = (tag(69, struct.pack("<I", 0)) + tag(9, b"\xff\xff\xff") + defs
        + b"".join(f + SHOW for f in root) + tag(0, b""))
hdr = rect(0, 200 * 20, 0, 100 * 20) + struct.pack("<HH", 30 << 8, len(root))
out = sys.argv[1] if len(sys.argv) > 1 else str(HERE / "test.swf")
open(out, "wb").write(b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(hdr) + len(body)) + hdr + body)
