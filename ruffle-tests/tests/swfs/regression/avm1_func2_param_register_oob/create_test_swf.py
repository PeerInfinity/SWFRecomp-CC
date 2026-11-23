#!/usr/bin/env python3
"""avm1_func2_param_register_oob: DefineFunction2 parameter register >= RegisterCount.

Pins (s26 w2-robustness-land): the recompiler sizes a func2_* C function's
local `ActionVar regs[]` from RegisterCount, the preload registers and the
registers the BODY uses, but bound each register parameter with
`regs[<param register>] = args[i]` unconditionally. A malformed (hand-made /
obfuscated) DefineFunction2 whose parameter register is past RegisterCount
wrote past the C array: `*** stack smashing detected ***` (runtime_error).
Ruffle ignores the write (avm1/function.rs binds register params through
Activation::set_local_register, a no-op past local_registers), so the
parameter is simply unbound; the recompiler now emits nothing for it.

    function f(a /* r1 */, b /* r3, RegisterCount = 3 */) {
        trace(r1); trace(typeof b); trace(r2); }
    f(7, 8); trace("done");

Expected output from the Ruffle exporter (LOCAL ORACLE REQUEST).
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
def push_reg(r): return b"\x96" + struct.pack("<H", 2) + bytes([4, r])
body = push_reg(1) + TRACE + push("b") + GETVAR + TYPEOF + TRACE + push_reg(2) + TRACE
hdr = s("f") + struct.pack("<HBH", 2, 3, 0)          # 2 params, RegisterCount 3, no flags
hdr += bytes([1]) + s("a") + bytes([3]) + s("b")     # a -> r1, b -> r3 (malformed: >= RegisterCount)
hdr += struct.pack("<H", len(body))
a = b"\x8e" + struct.pack("<H", len(hdr)) + hdr + body
a += callf("f", 7, 8) + POP + push("done") + TRACE + STOP
write_swf(doaction(a) + SHOW, 1)
