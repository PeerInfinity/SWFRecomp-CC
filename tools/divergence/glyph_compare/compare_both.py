#!/usr/bin/env python3
"""Render one SWF with BOTH the Ruffle exporter and SWFRecomp, then diff.

Reports the difference bounding box + extrema (None bbox == byte-identical) and
writes a side-by-side PNG plus a magnified crop of the diff region. This is the
per-asset A/B harness used to localize the #18b bug: it proved the 42 font
glyphs render byte-identical while DefineShape 26 differs only at the e/r nubs.

Usage:
    python3 compare_both.py <test.swf> [out_dir]

Requires the Ruffle exporter built at ~/CC/ruffle/target/release/exporter
(cd ~/CC/ruffle && cargo +nightly build --release -p exporter) and a built
SWFRecomp + local Dawn (same prerequisites as the divergence harness).
"""
import argparse
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
DIVERGENCE = HERE.parent
PROJECT_ROOT = DIVERGENCE.parent.parent
RUFFLE_EXPORTER = Path.home() / "CC" / "ruffle" / "target" / "release" / "exporter"
RUN_SWFRECOMP = DIVERGENCE / "run_swfrecomp.py"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("test_swf", type=Path)
    ap.add_argument("out_dir", type=Path, nargs="?", default=None)
    ap.add_argument("--crop", type=str, default=None,
                    help="x0,y0,x1,y1 region to magnify in the comparison")
    args = ap.parse_args()
    test_swf = args.test_swf.resolve()
    out = (args.out_dir or (HERE / "runs" / test_swf.stem)).resolve()
    out.mkdir(parents=True, exist_ok=True)

    if not RUFFLE_EXPORTER.exists():
        sys.exit(f"Ruffle exporter not built at {RUFFLE_EXPORTER}\n"
                 f"  cd ~/CC/ruffle && cargo +nightly build --release -p exporter")

    ruffle_png = out / "ruffle.png"
    subprocess.run([str(RUFFLE_EXPORTER), "-f", "1", "-s",
                    str(test_swf), str(ruffle_png)], check=True)

    sr_dir = out / "swfrecomp"
    subprocess.run(["python3", str(RUN_SWFRECOMP), str(test_swf), str(sr_dir),
                    "--frames", "1", "--recompile"], check=True,
                   cwd=str(PROJECT_ROOT))
    sr_png = sr_dir / "build" / "F0001.png"

    from PIL import Image, ImageChops
    a = Image.open(ruffle_png).convert("RGB")
    b = Image.open(sr_png).convert("RGB")
    if a.size != b.size:
        print(f"WARNING: size mismatch ruffle={a.size} swfrecomp={b.size}; resizing")
        b = b.resize(a.size)
    diff = ImageChops.difference(a, b)
    bbox = diff.getbbox()
    print(f"ruffle={ruffle_png}")
    print(f"swfrecomp={sr_png}")
    print(f"DIFF bbox={bbox} extrema={diff.getextrema()}"
          + ("  (BYTE-IDENTICAL)" if bbox is None else ""))

    # side-by-side
    sbs = Image.new("RGB", (a.width * 2 + 8, a.height), (200, 200, 200))
    sbs.paste(a, (0, 0))
    sbs.paste(b, (a.width + 8, 0))
    sbs.save(out / "side_by_side.png")
    print(f"side_by_side={out / 'side_by_side.png'}")

    region = bbox
    if args.crop:
        region = tuple(int(v) for v in args.crop.split(","))
    if region:
        x0, y0, x1, y1 = region
        pad = 6
        box = (max(0, x0 - pad), max(0, y0 - pad),
               min(a.width, x1 + pad), min(a.height, y1 + pad))
        scale = max(1, 480 // max(1, box[2] - box[0]))
        for name, im in (("ruffle", a), ("swfrecomp", b)):
            crop = im.crop(box)
            crop = crop.resize((crop.width * scale, crop.height * scale), Image.NEAREST)
            crop.save(out / f"crop_{name}.png")
        print(f"crops={out / 'crop_ruffle.png'} , {out / 'crop_swfrecomp.png'}")


if __name__ == "__main__":
    main()
