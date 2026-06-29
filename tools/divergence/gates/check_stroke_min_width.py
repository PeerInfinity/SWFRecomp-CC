#!/usr/bin/env python3
"""Image regression gate for Flash's minimum 1px on-screen stroke width.

Renders gates/stroke_min_width.swf through run_swfrecomp.py and asserts that all
four stroke rows are present, including the `lineStyle(0)` hairline (row 1) and
the two strokes on clips scaled to 25% (rows 3-4). Before the fix, the hairline
row vanished entirely (half-width 0) and the scaled rows thinned below 1px;
Ruffle floors every stroke to 1 on-screen pixel (width.max(1.0/scale)).

The gate counts horizontal "stroke bands" (runs of image rows that contain
non-background pixels) rather than diffing pixels, so it is robust to
anti-aliasing differences. Expected: exactly 4 bands.

Usage:
  python3 tools/divergence/gates/check_stroke_min_width.py
Exit 0 + "GATE-GREEN" on pass; non-zero + reason on fail.
"""
import subprocess
import sys
import tempfile
from pathlib import Path

from PIL import Image

HERE = Path(__file__).resolve().parent
REPO = HERE.parent.parent.parent
SWF = HERE / "stroke_min_width.swf"
EXPECTED_BANDS = 4


def main() -> int:
    out_dir = Path(tempfile.mkdtemp(prefix="stroke_min_gate_"))
    cmd = [
        sys.executable,
        str(HERE.parent / "run_swfrecomp.py"),
        str(SWF),
        str(out_dir),
        "--frames", "2",
        "--recompile",
    ]
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode != 0:
        print("run_swfrecomp.py failed:\n" + r.stdout + r.stderr, file=sys.stderr)
        return 2

    pngs = sorted(out_dir.glob("build/F*.png"))
    if not pngs:
        print(f"no render PNG produced in {out_dir}/build", file=sys.stderr)
        return 2

    img = Image.open(pngs[0]).convert("RGB")
    w, h = img.size
    px = img.load()

    # A row is "inked" if it has any pixel far enough from the light-grey/white
    # background. The strokes are black/red/blue/green — all clearly non-bg.
    def inked(y: int) -> bool:
        n = 0
        for x in range(w):
            r_, g_, b_ = px[x, y]
            # background is near-white (>= ~235 on every channel)
            if min(r_, g_, b_) < 200:
                n += 1
        return n >= 5  # a real stroke spans many px; ignore stray AA specks

    bands = 0
    prev = False
    for y in range(h):
        cur = inked(y)
        if cur and not prev:
            bands += 1
        prev = cur

    if bands != EXPECTED_BANDS:
        print(f"FAIL: expected {EXPECTED_BANDS} stroke bands, found {bands}.\n"
              f"  (hairline lineStyle(0) row or a scaled-down stroke likely "
              f"vanished — regression of the min-1px stroke-width fix.)\n"
              f"  render: {pngs[0]}", file=sys.stderr)
        return 1

    print("GATE-GREEN")
    return 0


if __name__ == "__main__":
    sys.exit(main())
