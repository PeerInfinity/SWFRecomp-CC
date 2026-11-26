#!/usr/bin/env python3
"""Join/cap probe (s28 n-join-disc). Open polylines, DefineShape1 (round caps+joins).
usage: probe2.py SPEC.json OUTDIR
SPEC = {"w","h","items":[{"lw":twips,"start":[x,y],"edges":[[dx,dy],...],"m":[a,b,c,d,tx,ty]}]}
(all twips; the path's local origin is the probed point)."""
import json, struct, sys, pathlib
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent.parent / "n-stroke-snap-captures"))
from probe import tag, BW, rect, matrix, place2

def shape(sid, it):
    lw = it["lw"]; sx, sy = it["start"]
    xs = [sx]; ys = [sy]; x, y = sx, sy
    for dx, dy in it["edges"]:
        x += dx; y += dy; xs.append(x); ys.append(y)
    pad = lw + 40
    b = struct.pack("<H", sid) + rect(min(xs) - pad, max(xs) + pad, min(ys) - pad, max(ys) + pad)
    b += bytes([0]) + bytes([1]) + struct.pack("<H", lw) + bytes([0, 0, 0])
    w = BW(); w.u(0, 4); w.u(1, 4)
    nb = 20
    w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1)   # stylechange: lineStyle + moveTo
    w.u(nb, 5); w.sb(sx, nb); w.sb(sy, nb)
    w.u(1, 1)
    for dx, dy in it["edges"]:
        w.u(1, 1); w.u(1, 1); w.u(17 - 2, 4)
        if dx != 0 and dy != 0: w.u(1, 1); w.sb(dx, 17); w.sb(dy, 17)
        elif dy == 0: w.u(0, 1); w.u(0, 1); w.sb(dx, 17)
        else: w.u(0, 1); w.u(1, 1); w.sb(dy, 17)
    w.u(0, 6)
    b += w.bytes()
    return tag(2, b, force_long=True)

def build(spec, out):
    out = pathlib.Path(out); out.mkdir(parents=True, exist_ok=True)
    defs = b""; frame = b""
    for i, it in enumerate(spec["items"]):
        defs += shape(100 + i, it)
        frame += place2(i + 1, 100 + i, matrix(*it["m"]))
    body = tag(69, struct.pack("<I", 0)) + tag(9, b"\xff\xff\xff") + defs + frame + tag(1, b"") + tag(0, b"")
    hdr = rect(0, spec["w"] * 20, 0, spec["h"] * 20, 16) + struct.pack("<HH", 30 << 8, 1)
    (out / "test.swf").write_bytes(b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(hdr) + len(body)) + hdr + body)
    (out / "layout.json").write_text(json.dumps(spec))
    (out / "test.toml").write_text("num_frames = 1\n")

if __name__ == "__main__":
    build(json.load(open(sys.argv[1])), sys.argv[2])
