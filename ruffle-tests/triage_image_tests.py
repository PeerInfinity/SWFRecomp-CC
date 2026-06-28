#!/usr/bin/env python3
"""Triage image-test divergences: which are *fixable* SWFRecomp bugs vs
*inherent* MSAA-vs-Flash-rasterizer gaps.

Why this exists
---------------
The committed ``<cmp>.ruffle.png`` files are Ruffle's own render, often captured
at ``quality="low"`` (1x MSAA = no antialiasing) and only present for
``known_failure`` tests. Comparing our 4x render against a 1x reference shows
spurious 1px "off-by-one" edge lines that are NOT bugs.

The authoritative oracle is ``<cmp>.expected.png`` — captured from real Flash
Player (its in-SWF assertions report "passed", which only a correct player
produces). To decide whether a divergence from Flash is *our* fault, we render
the Ruffle reference *ourselves* via the exporter at its default (High = 4x), so
it is apples-to-apples with our 4x output, and compare three ways:

    us-vs-Flash   : our render            vs expected.png (Flash oracle)
    us-vs-Ruffle  : our render            vs freshly-rendered Ruffle (4x)
    Ruffle-vs-Flash: freshly-rendered Ruffle vs expected.png

Verdicts
--------
  CLEAN       us already matches Flash.
  A-INHERENT  us == Ruffle (byte-ish identical), both differ from Flash.
              The GPU-MSAA-vs-Flash-analytic-rasterizer gap (abutting-edge
              seams, hairline coverage). Ruffle can't fix it either ->
              ACCEPTED_DIFFS candidate.
  B-FIXABLE   Ruffle matches Flash closely but we don't -> a real SWFRecomp
              bug; the correct output is demonstrably achievable.
  OTHER       we differ from both and Ruffle also differs from Flash; read
              the numbers (may be partially fixable, or a structural bug).

Caveats flagged automatically:
  - REF? : the Ruffle reference looks unreliable for this comparison
           (huge us-vs-Ruffle while us-vs-Flash is tiny) — typically a test
           that loads an external image the exporter can't fetch, or a
           frame/interaction the headless exporter renders differently.

Usage
-----
    python3 ruffle-tests/triage_image_tests.py                       # full sweep
    python3 ruffle-tests/triage_image_tests.py avm1/movieclip_setmask  # one test
    RUFFLE_EXPORTER=/path/to/exporter python3 ... triage_image_tests.py

Requires numpy + Pillow and the Ruffle exporter
(``cd ~/CC/ruffle && cargo build --release -p exporter``).
"""
import os, re, sys, glob, tempfile, subprocess, importlib.util
from collections import Counter

import numpy as np
from PIL import Image

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
TESTS = os.path.join(SCRIPT_DIR, "tests", "swfs")
EXPORTER = os.environ.get(
    "RUFFLE_EXPORTER", os.path.expanduser("~/CC/ruffle/target/release/exporter"))

# A diff under this many changed pixels (channel-sum > 30) counts as "matches".
MATCH_PX = 50


def parse_toml(test_dir):
    toml = open(os.path.join(test_dir, "test.toml")).read()
    names = re.findall(r'\[image_comparisons\.([A-Za-z0-9_]+)\]', toml)
    nf = re.search(r'num_frames\s*=\s*(\d+)', toml)
    nt = re.search(r'num_ticks\s*=\s*(\d+)', toml)
    frames = int(nf.group(1)) if nf else (int(nt.group(1)) if nt else 1)
    trig = {}
    for n in names:
        m = re.search(rf'\[image_comparisons\.{n}\](.*?)(?:\n\[|\Z)', toml, re.S)
        block = m.group(1) if m else ""
        t = re.search(r'trigger\s*=\s*"?(\w+)"?', block)
        trig[n] = t.group(1) if t else "last_frame"
    return names, trig, max(frames, 1)


def load(p):
    return np.asarray(Image.open(p).convert("RGB"), int)


def dstat(a, b):
    if a is None or b is None or a.shape != b.shape:
        return None
    d = np.abs(a - b).sum(2)
    return int((d > 30).sum()), round(float(d.mean()), 3)


def render_ruffle(swf, nframes, outdir):
    if not os.path.exists(EXPORTER):
        return {}
    if nframes <= 1:
        out = os.path.join(outdir, "r.png")
        subprocess.run([EXPORTER, "--silent", swf, out], capture_output=True)
        return {1: out} if os.path.exists(out) else {}
    subprocess.run([EXPORTER, "--silent", "--frames", str(nframes), swf, outdir],
                   capture_output=True)
    res = {}
    for f in glob.glob(os.path.join(outdir, "*.png")):
        m = re.search(r'(\d+)\.png$', f)
        if m:
            res[int(m.group(1)) + 1] = f       # exporter frames are 0-based
    return res


def classify(uvf, uvr, rvf):
    small = lambda s: s is not None and s[0] <= MATCH_PX
    big = lambda s: s is None or s[0] > MATCH_PX
    ref_bad = (uvf is not None and uvf[0] <= MATCH_PX * 4
               and uvr is not None and uvr[0] > 5000)
    if small(uvf):
        return "CLEAN", ref_bad
    if small(uvr) and big(rvf):
        return "A-INHERENT", ref_bad
    if big(uvr) and small(rvf):
        return "B-FIXABLE", ref_bad
    # partial-fixable heuristic: Ruffle markedly closer to Flash than we are
    if (rvf is not None and uvf is not None and uvr is not None
            and rvf[0] * 3 < uvf[0] and uvr[0] > MATCH_PX and not ref_bad):
        return "B-FIXABLE?", ref_bad
    return "OTHER", ref_bad


def triage_one(rel, verbose=True):
    test_dir = os.path.join(TESTS, rel)
    swf = os.path.join(test_dir, "test.swf")
    names, trig, nframes = parse_toml(test_dir)
    out = []
    with tempfile.TemporaryDirectory() as td:
        rframes = render_ruffle(swf, nframes, td)
        for n in names:
            t = trig[n]
            fidx = (max(rframes) if (t == "last_frame" or not t.isdigit())
                    else int(t)) if rframes else None
            rp = rframes.get(fidx) if rframes else None
            ap = os.path.join(test_dir, f"{n}.actual.png")
            ep = os.path.join(test_dir, f"{n}.expected.png")
            if not (os.path.exists(ap) and os.path.exists(ep)):
                out.append((rel, n, "NOIMG", None, None, None, False)); continue
            A, E = load(ap), load(ep)
            R = load(rp) if rp and os.path.exists(rp) else None
            uvf, uvr, rvf = dstat(A, E), dstat(A, R), dstat(R, E)
            v, ref_bad = classify(uvf, uvr, rvf)
            out.append((rel, n, v, uvf, uvr, rvf, ref_bad))
    if verbose:
        for rel, n, v, uvf, uvr, rvf, rb in out:
            print(f"  [{n}] {v}{' (REF?)' if rb else ''}")
            print(f"        us-vs-Flash : {uvf}")
            print(f"        us-vs-Ruffle: {uvr}")
            print(f"        Ruffle-Flash: {rvf}")
    return out


def discover():
    spec = importlib.util.spec_from_file_location(
        "rit", os.path.join(SCRIPT_DIR, "run_image_tests.py"))
    rit = importlib.util.module_from_spec(spec); spec.loader.exec_module(rit)
    return rit.discover_image_tests()


def sweep():
    rows = []
    for rel in discover():
        try:
            rows += triage_one(rel, verbose=False)
        except Exception as e:
            rows.append((rel, "-", "ERR", str(e), None, None, False))
    order = {"B-FIXABLE": 0, "B-FIXABLE?": 1, "OTHER": 2, "A-INHERENT": 3,
             "CLEAN": 4, "NOIMG": 5, "ERR": 6}
    rows.sort(key=lambda r: (order.get(r[2], 9), -(r[3][0] if r[3] else 0)))
    f = lambda s: f"{s[0]:>6}/{s[1]:.2f}" if s else "   -  "
    print(f"{'verdict':<11} {'us-Flash':>12} {'us-Ruffle':>12} {'Ruffle-Flash':>13}  test [cmp]")
    print("-" * 96)
    for rel, n, v, uvf, uvr, rvf, rb in rows:
        tag = v + (" REF?" if rb else "")
        print(f"{tag:<11} {f(uvf):>12} {f(uvr):>12} {f(rvf):>13}  {rel} [{n}]")
    print("-" * 96)
    print("SUMMARY:", dict(Counter(r[2] for r in rows)))


if __name__ == "__main__":
    if not os.path.exists(EXPORTER):
        print(f"WARNING: Ruffle exporter not found at {EXPORTER}\n"
              "  build: cd ~/CC/ruffle && cargo build --release -p exporter",
              file=sys.stderr)
    if len(sys.argv) > 1:
        print(f"== {sys.argv[1]} ==")
        triage_one(sys.argv[1])
    else:
        sweep()
