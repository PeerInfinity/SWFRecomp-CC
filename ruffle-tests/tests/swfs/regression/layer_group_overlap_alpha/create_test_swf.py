#!/usr/bin/env python3
"""Regenerate test.swf (+ the analytic output.expected.png) for
layer_group_overlap_{alpha,erase} (s25 w2-avm2-layer-groups, lead L5).

Pins down: an ALPHA (11) / ERASE (12) child inside a LAYER (2) group is
applied to the child's OWN composite, not per draw (ruffle
render/wgpu/src/surface.rs nearest_layer + shaders/blend/{alpha,erase}.wgsl:
the child renders into its own layer, then `dst *= child.a` /
`dst *= 1 - child.a`, discarding where child.a == 0).

Static timeline, no scripts (no compiler needed), SWF 10, 200x150, white:
  root depth 1 = sprite 4, PlaceObject3 blend = layer
    sprite 4 depth 1 = shape 1, opaque red rect (20,20)-(180,130)
    sprite 4 depth 2 = sprite 3, PlaceObject3 blend = alpha | erase
      sprite 3 = two 60x60 blue squares at 50%-alpha (A = 128), at (50,40)
                 and (80,60): they overlap on (80,60)-(110,100).
Every edge is on a whole pixel, so there is no AA ambiguity.

Expected (ruffle model, 8-bit): one square a = 128/255; the overlap composite
a = 1 - (1 - a)^2 (normal-over inside the child layer).
  alpha: dst *= a       -> red at 0.502 (single) / 0.752 (overlap)
  erase: dst *= 1 - a   -> red at 0.498 (single) / 0.248 (overlap)
The per-draw model gives a^2 = 0.252 on the ALPHA overlap (wrong) and
(1 - a)^2 = 0.248 on the ERASE overlap (equal to the exact model: per-draw
erase is exact for normal-blended children). The golden written here is
ANALYTIC; a Ruffle-exporter render is requested in the s25
w2-avm2-layer-groups report (LOCAL ORACLE REQUESTS) to replace it.

Variant `inadd` (directory layer_group_in_add_alpha, limit 2 of the s25
per-draw model): the same LAYER sprite 4 is placed inside sprite 5, which the
root places with blend = add on a BLACK stage. The LAYER now sits inside the
ADD offscreen (offscreen_depth 1), where it used to draw as NORMAL with its
ALPHA child dropped (a solid red rect). Over black, add shows the group
unchanged: red at 1.0 / 0.502 / 0.752 on (0,0,0).

Variant `avm2` (directory avm2_layer_group_overlap_alpha): the `alpha` SWF
with FileAttributes.ActionScript3 set and a minimal DoABC (one script,
init = getlocal0 / pushscope / returnvoid, no classes), so the same
placements go through avm2_display.c's blend arm. Same golden as `alpha`.

Usage: create_test_swf.py [alpha|erase|inadd|avm2]   (default: directory suffix)
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

def shape3(sid, x, y, wpx, hpx, rgba):
    """DefineShape3 rect in px, solid RGBA fill, no lines."""
    X, Y, W, H = x * 20, y * 20, wpx * 20, hpx * 20
    body = struct.pack("<H", sid) + rect(X, X + W, Y, Y + H)
    body += bytes([1, 0x00]) + bytes(rgba) + bytes([0])
    w = BW(); w.u(1, 4); w.u(0, 4)
    nb = 15
    # StyleChange: moveTo + fillStyle0 = 1 (CW winding in y-down)
    w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(1, 1)
    w.u(nb, 5); w.sb(X, nb); w.sb(Y, nb)
    w.u(1, 1)
    def edge(dx, dy):
        w.u(1, 1); w.u(1, 1); w.u(nb - 2, 4)
        if dy == 0: w.u(0, 1); w.u(0, 1); w.sb(dx, nb)
        else: w.u(0, 1); w.u(1, 1); w.sb(dy, nb)
    edge(W, 0); edge(0, H); edge(-W, 0); edge(0, -H)
    w.u(0, 6)
    body += w.bytes()
    return tag(32, body)

def place2(depth, cid):
    return tag(26, bytes([0x02]) + struct.pack("<HH", depth, cid))

def place3(depth, cid, blend):
    # PlaceObject3: flags1 = HasCharacter (0x02), flags2 = HasBlendMode (0x02)
    return tag(70, bytes([0x02, 0x02]) + struct.pack("<HH", depth, cid) + bytes([blend]))

def sprite(sid, tags):
    return tag(39, struct.pack("<HH", sid, 1) + b"".join(tags) + tag(1, b"") + tag(0, b""))

def build(mode):
    child_blend = {"alpha": 11, "erase": 12, "inadd": 11, "avm2": 11}[mode]
    bg = (0, 0, 0) if mode == "inadd" else (255, 255, 255)
    t = [tag(69, bytes([0x08 if mode == "avm2" else 0, 0, 0, 0])), tag(9, bytes(bg))]
    if mode == "avm2":
        abc = (struct.pack("<HH", 16, 46) + bytes(7) + bytes([1, 0, 0, 0, 0])
               + bytes([0]) + bytes([0]) + bytes([1, 0, 0])
               + bytes([1, 0, 1, 1, 0, 1, 3, 0xD0, 0x30, 0x47, 0, 0]))
        t.append(tag(82, struct.pack("<I", 1) + b"\0" + abc))
    t.append(shape3(1, 20, 20, 160, 110, (255, 0, 0, 255)))
    t.append(shape3(2, 0, 0, 60, 60, (0, 0, 255, 128)))
    # sprite 3: the two squares, offset by PlaceObject2 matrices
    def place_at(depth, cid, x, y):
        w = BW(); w.u(0, 1); w.u(0, 1); w.u(15, 5); w.sb(x * 20, 15); w.sb(y * 20, 15)
        return tag(26, bytes([0x06]) + struct.pack("<HH", depth, cid) + w.bytes())
    t.append(sprite(3, [place_at(1, 2, 50, 40), place_at(2, 2, 80, 60)]))
    t.append(sprite(4, [place2(1, 1), place3(2, 3, child_blend)]))
    if mode == "inadd":
        t.append(sprite(5, [place3(1, 4, 2)]))
        t.append(place3(1, 5, 8))
    else:
        t.append(place3(1, 4, 2))
    t.append(tag(1, b"")); t.append(tag(0, b""))
    body = rect(0, 200 * 20, 0, 150 * 20) + struct.pack("<BBH", 0, 30, 1) + b"".join(t)
    return b"FWS" + bytes([10]) + struct.pack("<I", 8 + len(body)) + body

def golden(mode):
    from PIL import Image
    a = 128 / 255.0
    one, two = (1 - a, (1 - a) ** 2) if mode == "erase" else (a, 1 - (1 - a) ** 2)
    bg = 0 if mode == "inadd" else 255
    img = Image.new("RGBA", (200, 150), (bg, bg, bg, 255))
    px = img.load()
    def inside(x, y, x0, y0, w, h): return x0 <= x < x0 + w and y0 <= y < y0 + h
    for y in range(150):
        for x in range(200):
            if not inside(x, y, 20, 20, 160, 110): continue
            n = inside(x, y, 50, 40, 60, 60) + inside(x, y, 80, 60, 60, 60)
            k = 1.0 if n == 0 else (one if n == 1 else two)
            if mode == "inadd":                # premultiplied red added to black
                px[x, y] = (round(255 * k), 0, 0, 255)
            else:                              # red at coverage k over white
                g = round(255 * (1 - k))
                px[x, y] = (255, g, g, 255)
    return img

if __name__ == "__main__":
    DIRS = {"alpha": "layer_group_overlap_alpha", "erase": "layer_group_overlap_erase",
            "inadd": "layer_group_in_add_alpha", "avm2": "avm2_layer_group_overlap_alpha"}
    mode = sys.argv[1] if len(sys.argv) > 1 else {v: k for k, v in DIRS.items()}[HERE.name]
    out = HERE.parent / DIRS[mode]
    out.mkdir(exist_ok=True)
    (out / "test.swf").write_bytes(build(mode))
    golden(mode).save(out / "output.expected.png")
