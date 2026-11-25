#!/usr/bin/env python3
"""gradientTransform stage-offset fixtures (LOCAL ORACLE REQUESTS #2).

Rewrites ONLY the header RECT of from_shumway/gradientTransform so the root's
xmin/ymin (twips) = -off while width/height stay 2026 x 506 twips. Content
edges sit at -10/10/30/1990/2010 twips, so the device edge positions become
(edge + off)/20 px. Run from the repo root after download_tests.sh from_shumway.
"""
import pathlib, zlib, shutil
here = pathlib.Path(__file__).resolve().parent
src = pathlib.Path.cwd() / "ruffle-tests/tests/swfs/from_shumway/gradientTransform"
d = (src / "test.swf").read_bytes()
assert d[:1] == b"C"
body = zlib.decompress(d[8:])
nb = body[0] >> 3
rect_bytes = (5 + 4 * nb + 7) // 8
def rect(xmin, xmax, ymin, ymax, n=16):
    bits = f"{n:05b}" + "".join(f"{v & ((1 << n) - 1):0{n}b}" for v in (xmin, xmax, ymin, ymax))
    bits += "0" * (-len(bits) % 8)
    return bytes(int(bits[i:i + 8], 2) for i in range(0, len(bits), 8))
for off in (0, 5, 10, 13, 15):
    nb_body = rect(-off, 2026 - off, -off, 506 - off) + body[rect_bytes:]
    out = bytearray(b"FWS" + d[3:4]) + (8 + len(nb_body)).to_bytes(4, "little") + nb_body
    dst = here / "out" / f"gradientTransform_off{off}"
    dst.mkdir(parents=True, exist_ok=True)
    (dst / "test.swf").write_bytes(bytes(out))
    shutil.copy(src / "test.toml", dst / "test.toml")
    print(dst, "xmin=ymin=", -off, "twips")
