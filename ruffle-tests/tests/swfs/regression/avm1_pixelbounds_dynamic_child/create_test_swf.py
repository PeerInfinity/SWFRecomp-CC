#!/usr/bin/env python3
"""avm1_pixelbounds_dynamic_child: Transform.pixelBounds unions a dynamic child.

Pins (s26 w1-runtime-robustness): transformPixelBoundsGetter (action.c) unions
each createEmptyMovieClip child's bounds by re-entering getBounds(mc) through
actionCallMethod. It stored the arg count 1 with
`VAL(float, &one.data.numeric_value) = 1.0f` and pushVar read the u64 member:
the strict-aliasing shape gcc -O2 drops (s25 w2-avm1-with-scope), so the call
ran as getBounds() with NO target space and folded the child's LOCAL box
(0..10) into the parent's world box. Expected output from the Ruffle exporter.

    var m = _root.createEmptyMovieClip("m", 1);
    var c = m.createEmptyMovieClip("c", 1);
    c.beginFill(0xFF0000); square 10x10; c.endFill(); c._x = 50; c._y = 20;
    trace(m.transform.pixelBounds);
"""
import pathlib, struct, sys
HERE = pathlib.Path(__file__).resolve().parent
def tag(code, body):
    if len(body) < 0x3F: return struct.pack("<H", (code << 6) | len(body)) + body
    return struct.pack("<HI", (code << 6) | 0x3F, len(body)) + body
def rect(x0, x1, y0, y1, nb=16):
    bits = []
    def u(v, n): bits.extend((v >> i) & 1 for i in range(n - 1, -1, -1))
    u(nb, 5)
    for v in (x0, x1, y0, y1): u(v & ((1 << nb) - 1), nb)
    bits += [0] * ((-len(bits)) % 8)
    return bytes(int("".join(map(str, bits[i:i + 8])), 2) for i in range(0, len(bits), 8))
def s(x): return x.encode() + b"\0"
def push(*items):
    b = b""
    for it in items:
        if isinstance(it, str): b += b"\x00" + s(it)
        elif isinstance(it, int): b += b"\x07" + struct.pack("<i", it)
    return b"\x96" + struct.pack("<H", len(b)) + b
GETVAR, SETVAR, GETMEM, SETMEM, TRACE, POP, CALLM, STOP = (
    b"\x1c", b"\x1d", b"\x4e", b"\x4f", b"\x26", b"\x17", b"\x52", b"\x07")
def v(n): return push(n) + GETVAR
def callm(obj, meth, *args): return push(*reversed(args), len(args)) + obj + push(meth) + CALLM
a = push("m") + callm(v("_root"), "createEmptyMovieClip", "m", 1) + SETVAR
a += push("c") + callm(v("m"), "createEmptyMovieClip", "c", 1) + SETVAR
a += callm(v("c"), "beginFill", 0xFF0000) + POP
a += callm(v("c"), "moveTo", 0, 0) + POP
for x, y in ((10, 0), (10, 10), (0, 10), (0, 0)): a += callm(v("c"), "lineTo", x, y) + POP
a += callm(v("c"), "endFill") + POP
a += v("c") + push("_x", 50) + SETMEM + v("c") + push("_y", 20) + SETMEM
a += v("m") + push("transform") + GETMEM + push("pixelBounds") + GETMEM + TRACE
a += STOP
body = tag(69, struct.pack("<I", 0)) + tag(9, b"\xff\xff\xff") + tag(12, a + b"\0") + tag(1, b"") + tag(0, b"")
hdr = rect(0, 200 * 20, 0, 100 * 20) + struct.pack("<HH", 30 << 8, 1)
out = sys.argv[1] if len(sys.argv) > 1 else str(HERE / "test.swf")
open(out, "wb").write(b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(hdr) + len(body)) + hdr + body)
