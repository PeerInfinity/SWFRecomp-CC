#!/usr/bin/env python3
"""avm1_many_defs_registry: definition registries past their old fixed caps.

Pins (s26 w1-runtime-robustness): after be31edbfd made the EditText / shape /
morph registries growable, the runtime still kept these per-definition tables
in fixed arrays that SILENTLY dropped every entry past the cap:

  ng_shared.c  ng_button_ids          64   -> typeof/_width of a late button
  ng_shared.c  ng_fonts               32   -> textWidth of a late embedded font
  ng_shared.c  ng_video_ids           32   -> a late Video instance
  ng_shared.c  g_sound_metadata      128   -> Sound.duration of a late sound
  ng_shared.c  ng_exported_symbols  1024   -> attachMovie of a late linkage name
  registered_class.c                 128   -> Object.registerClass on the 130th symbol
  tag.c        g_bitmap_defs         128   -> BitmapData.loadBitmap of a late bitmap
  tag.c        sprite_label_store    256   -> gotoAndStop(label) on a late sprite
  tag.c        g_init_action_done    512   -> #initclip of a sprite id >= 512
                                              re-runs on every frame revisit

One SWF crosses each cap by a small margin; each trace line reads the LAST
definition (a few lines also read the first, as a control). The root plays
frame 1 -> 2 -> back to 1 -> 2 so the init-action guard is exercised.
Expected output must come from the Ruffle exporter (--frames 6); see the
s26 w1-runtime-robustness report, LOCAL ORACLE REQUESTS.
"""
import pathlib, struct, sys, zlib
HERE = pathlib.Path(__file__).resolve().parent

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
CALLM, CALLF, NEWOBJ, TYPEOF, INCR, BITOR = b"\x52", b"\x3d", b"\x40", b"\x44", b"\x50", b"\x60"
SHOW = tag(1, b"")
def doaction(a): return tag(12, a + b"\0")
def jump(off): return b"\x99" + struct.pack("<Hh", 2, off)
def if_(off): return b"\x9d" + struct.pack("<Hh", 2, off)
def gotoframe(i): return b"\x81" + struct.pack("<HH", 2, i)
def v(n): return push(n) + GETVAR
def g(code, prop): return code + push(prop) + GETMEM
def callm(obj_code, meth, *args):
    return push(*reversed(args), len(args)) + obj_code + push(meth) + CALLM
def place_named(depth, cid, name):
    return tag(26, bytes([0x22]) + struct.pack("<HH", depth, cid) + s(name))
def sprite(sid, frames):
    return tag(39, struct.pack("<HH", sid, len(frames)) + b"".join(f + SHOW for f in frames) + tag(0, b""))

def shape_rect(sid, wpx, hpx):
    W, H = wpx * 20, hpx * 20
    b = struct.pack("<H", sid) + rect(0, W, 0, H)
    b += bytes([1, 0x00, 0, 120, 0, 0])
    b += square_records(W, H, 1)
    return tag(2, b)

def square_records(W, H, fillbits):
    w = BW(); w.u(fillbits, 4); w.u(0, 4)
    nb = 16
    w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(1, 1)  # fs1, moveto
    w.u(nb, 5); w.sb(0, nb); w.sb(0, nb)
    w.u(1, fillbits)
    def edge(dx, dy):
        w.u(1, 1); w.u(1, 1); w.u(nb - 2, 4)
        if dy == 0: w.u(0, 1); w.u(0, 1); w.sb(dx, nb)
        else: w.u(0, 1); w.u(1, 1); w.sb(dy, nb)
    edge(W, 0); edge(0, H); edge(-W, 0); edge(0, -H)
    w.u(0, 6)
    return w.bytes()

def button2(bid, shape_id):
    rec = bytes([0x0F]) + struct.pack("<HH", shape_id, 1) + b"\x00" + b"\x00"
    return tag(34, struct.pack("<HBH", bid, 0, 0) + rec + b"\x00")

def font2(fid, name, adv):
    glyph = square_records(400, 600, 1)      # one 'A' glyph, EM 1024 space
    offsets = struct.pack("<HH", 4, 4 + len(glyph))   # glyph offset, code table offset
    b = struct.pack("<HBB", fid, 0x80 | 0x04, 0) + bytes([len(name)]) + name.encode()
    b += struct.pack("<H", 1) + offsets + glyph + struct.pack("<H", 65)
    b += struct.pack("<hhh", 900, 200, 0) + struct.pack("<h", adv)
    b += rect(0, 400, -600, 0) + struct.pack("<H", 0)
    return tag(48, b, force_long=True)

def edittext_font(cid, fid, text):
    b = struct.pack("<H", cid) + rect(0, 4000, 0, 600)
    b += bytes([0x80 | 0x04 | 0x01, 0x10 | 0x01]) + struct.pack("<HH", fid, 400)
    b += bytes([0, 0, 0, 255]) + s("") + s(text)
    return tag(37, b)

def sound(sid, nsamples):
    return tag(14, struct.pack("<HBI", sid, 0x34, nsamples) + bytes([128]) * nsamples, force_long=True)

def bitmap(cid, w, h):
    px = bytes([255, 0, 128, 0]) * (w * h)
    return tag(20, struct.pack("<HBHH", cid, 5, w, h) + zlib.compress(px), force_long=True)

def video(cid, w, h):
    return tag(60, struct.pack("<HHHHBB", cid, 0, w, h, 0, 2))

def exports(pairs):
    b = struct.pack("<H", len(pairs)) + b"".join(struct.pack("<H", c) + s(n) for c, n in pairs)
    return tag(56, b, force_long=True)

N_BTN, N_FONT, N_SND, N_BMP, N_VID, N_LBL, N_EXP, N_CLS = 70, 40, 130, 130, 40, 260, 1030, 130
defs = b""; cid = 1
SHAPE = cid; defs += shape_rect(SHAPE, 10, 10); cid += 1
btn = []
for i in range(N_BTN): defs += button2(cid, SHAPE); btn.append(cid); cid += 1
fonts = []
for i in range(N_FONT): defs += font2(cid, "F%d" % (i + 1), 512 if i else 256); fonts.append(cid); cid += 1
TF1 = cid; defs += edittext_font(TF1, fonts[0], "AAAA"); cid += 1
TFN = cid; defs += edittext_font(TFN, fonts[-1], "AAAA"); cid += 1
snds = []
for i in range(N_SND):
    defs += sound(cid, 2205 if i == N_SND - 1 else (1102 if i == 0 else 2)); snds.append(cid); cid += 1
bmps = []
for i in range(N_BMP):
    defs += bitmap(cid, 3 if i == N_BMP - 1 else 1, 2 if i == N_BMP - 1 else 1); bmps.append(cid); cid += 1
vids = []
for i in range(N_VID): defs += video(cid, 64 + i, 48); vids.append(cid); cid += 1
lbls = []
for i in range(N_LBL):
    defs += sprite(cid, [b"", tag(43, s("M")), tag(43, s("L"))]); lbls.append(cid); cid += 1
EXP = cid; defs += sprite(EXP, [b""]); cid += 1
clss = []
for i in range(N_CLS): defs += sprite(cid, [b""]); clss.append(cid); cid += 1
INIT = cid; defs += sprite(INIT, [b""]); cid += 1
assert INIT >= 512
defs += exports([(snds[0], "snd1"), (snds[-1], "snd%d" % N_SND), (bmps[0], "bmp1"),
                 (bmps[-1], "bmp%d" % N_BMP), (lbls[0], "lbl1"), (lbls[-1], "lbl%d" % N_LBL)]
                + [(c, "cls%d" % i) for i, c in enumerate(clss)]    # before the exp
                + [(EXP, "exp%d" % i) for i in range(N_EXP)])       # flood (cap 1024)
# #initclip for sprite INIT: _global.ic = (_global.ic | 0) + 1
init_code = (v("_global") + push("ic") + v("_global") + push("ic") + GETMEM + push(0) + BITOR
             + INCR + SETMEM)
defs += tag(59, struct.pack("<H", INIT) + init_code + b"\0")

def line(*parts):
    c = push(parts[0])
    for p in parts[1:]:
        c += (push(p) if isinstance(p, str) else p) + ADD2
    return c + TRACE

place = (place_named(10, btn[0], "btn1") + place_named(11, btn[-1], "btnN")
         + place_named(12, TF1, "tf1") + place_named(13, TFN, "tfN")
         + place_named(14, vids[0], "vid1") + place_named(15, vids[-1], "vidN"))

# frame 2 probes (second visit only)
probe = b""
probe += line("btn1 typeof=", v("btn1") + TYPEOF, " w=", g(v("btn1"), "_width"))
probe += line("btnN typeof=", v("btnN") + TYPEOF, " w=", g(v("btnN"), "_width"))
probe += line("font1 tw=", g(v("tf1"), "textWidth"), " fontN tw=", g(v("tfN"), "textWidth"))
probe += line("vid1 typeof=", v("vid1") + TYPEOF, " w=", g(v("vid1"), "_width"))
probe += line("vidN typeof=", v("vidN") + TYPEOF, " w=", g(v("vidN"), "_width"))
for nm, var in (("snd1", "s1"), ("snd%d" % N_SND, "sN")):
    probe += push(var, 0, "Sound") + NEWOBJ + SETVAR
    probe += callm(v(var), "attachSound", nm) + POP
probe += line("snd1 dur=", g(v("s1"), "duration"), " sndN dur=", g(v("sN"), "duration"))
probe += callm(v("_root"), "attachMovie", "exp0", "e0", 50) + POP
probe += callm(v("_root"), "attachMovie", "exp%d" % (N_EXP - 1), "eN", 51) + POP
probe += line("exp0 typeof=", v("e0") + TYPEOF, " expN typeof=", v("eN") + TYPEOF)
# function C() {}; C.prototype.k = "cls"; Object.registerClass("expI", C) for I < N_CLS
probe += b"\x9b" + struct.pack("<H", len(s("C")) + 4) + s("C") + struct.pack("<HH", 0, 0)
probe += g(v("C"), "prototype") + push("k", "cls") + SETMEM
for i in range(N_CLS):
    probe += v("C") + push("cls%d" % i, 2) + v("Object") + push("registerClass") + CALLM + POP
probe += callm(v("_root"), "attachMovie", "cls0", "c0", 52) + POP
probe += callm(v("_root"), "attachMovie", "cls%d" % (N_CLS - 1), "cN", 53) + POP
probe += line("cls0 k=", g(v("c0"), "k"), " clsN k=", g(v("cN"), "k"))
bd = g(g(v("flash"), "display"), "BitmapData")
for nm, var in (("bmp1", "b1"), ("bmp%d" % N_BMP, "bN")):
    probe += push(var) + callm(bd, "loadBitmap", nm) + SETVAR
probe += line("bmp1 ", g(v("b1"), "width"), "x", g(v("b1"), "height"),
              " bmpN ", g(v("bN"), "width"), "x", g(v("bN"), "height"))
for nm, var, d in (("lbl1", "l1", 54), ("lbl%d" % N_LBL, "lN", 55)):
    probe += callm(v("_root"), "attachMovie", nm, var, d) + POP
    probe += callm(v(var), "gotoAndStop", "L") + POP
probe += line("lbl1 cf=", g(v("l1"), "_currentframe"), " lblN cf=", g(v("lN"), "_currentframe"))
probe += line("init ic=", g(v("_global"), "ic"))
probe += STOP

then_blk = push("p", 1) + SETVAR + gotoframe(0) + PLAY
then_blk += jump(len(probe))
f2 = v("p") + if_(len(then_blk)) + then_blk + probe
root = [place + doaction(line("f1 ic=", g(v("_global"), "ic"))), doaction(f2)]
body = (tag(69, struct.pack("<I", 0)) + tag(9, b"\xff\xff\xff") + defs
        + b"".join(f + SHOW for f in root) + tag(0, b""))
hdr = rect(0, 400 * 20, 0, 300 * 20) + struct.pack("<HH", 30 << 8, len(root))
out = sys.argv[1] if len(sys.argv) > 1 else str(HERE / "test.swf")
open(out, "wb").write(b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(hdr) + len(body)) + hdr + body)
