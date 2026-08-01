#!/usr/bin/env python3
"""Mechanism clustering + ranking for failing image comparisons — the graphics board.

This is the pixel-side analog of the trace corpus's near-pass list, and it exists
because of one measured lesson:

    RANK BY MECHANISM FIRST, NOT BY NEAR-PASS.

    `hairline_edge_drift` owns 35 of the 44 near-pass (band a/b) failures and
    zero of the moderate-or-worse ones, and it is mostly the lavapipe-vs-Flash
    antialiasing gap — i.e. the least fixable cluster in the corpus. A session
    that sorts the failing set by "how close is it to the tolerance budget" walks
    straight into it. The clustering key is what makes the middle of the board
    readable: the head of the board is `same_geometry_wrong_fill` (geometry
    correct, pixel values wrong) — blend-mode math, Shumway acid composites,
    focus highlight — which sits in c_small/d_moderate, not in the epsilon band.

What it does: joins every FAILING comparison in the per-suite
`_results/image_results_<stem>.json` files to its rendered `<cmp>.actual.png`
(from a checkout of the `ruffle-image-results` branch) and its in-repo
`<cmp>.expected.png`, computes purely-visual features, assigns a mechanism
cluster, flags dispositioned targets, and ranks the result per (test, cluster).

It deliberately does NOT use the published `<cmp>.difference.png`: that file is
alpha-mangled and RGB-brightened x4 (`verify_output.py` ~L459-471), so it is a
viewer aid, not data. The difference is recomputed here from actual+expected.

Local-only tool: it needs numpy + Pillow, the image-results checkout, and the
downloaded expected PNGs, and it runs once per image baseline. `build_image_report.py`
runs inside CI on every images run and must stay dependency-light — that is why
this is a separate file, not a mode of that one.

Typical session (one command after merging an `images=true` run):

    git fetch origin ruffle-image-results
    git worktree add .image-results origin/ruffle-image-results
    python3 scripts/image_triage.py                # ~24 s at --jobs 4

Other entry points:

    python3 scripts/image_triage.py --cluster same_geometry_wrong_fill
    python3 scripts/image_triage.py --test avm2/focusrect      # dump every feature
    python3 scripts/image_triage.py --from-json image_triage.json --top 40

The funnel this sits in the middle of:
    scripts/image_status_diff.py   did anything move since the last baseline?
 -> scripts/image_triage.py        what KIND of wrong is it, what do I fix first?
 -> ruffle-tests/triage_image_tests.py   is this one fixable, or is it the MSAA gap?
"""

import argparse
import json
import math
import os
import re
import sys
from collections import Counter, defaultdict
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

import numpy as np
from PIL import Image

Image.MAX_IMAGE_PIXELS = None

PROJECT_ROOT = Path(__file__).resolve().parent.parent
DEFAULT_SWFS = PROJECT_ROOT / "ruffle-tests" / "tests" / "swfs"

sys.path.insert(0, str(PROJECT_ROOT / "scripts"))
from build_image_report import near_miss_band, NESTED_SUITES   # noqa: E402
from image_baseline_report import family_of                    # noqa: E402

# Where a `ruffle-image-results` checkout is looked for, in order. Either the
# branch root (containing `images/`) or the `images/` dir itself is accepted.
IMAGES_DIR_CANDIDATES = (
    "$IMAGE_RESULTS_DIR",
    PROJECT_ROOT / ".image-results",
    PROJECT_ROOT / "image-results",
    PROJECT_ROOT.parent / "ruffle-image-results",
)

SIG = 16          # per-channel difference that counts as "structurally different"
INK = 24          # distance from an image's own modal colour that counts as ink

# How near-pass the comparison is: 1.0 = a handful of channels over budget.
# Keys are `build_image_report.near_miss_band()` labels — one definition of the
# bands, imported rather than re-derived.
BAND_PROX = {
    "a_epsilon (<=100 channels over)": 1.00,
    "b_tiny (<0.1% of channels)": 0.85,
    "c_small (0.1-1%)": 0.60,
    "d_moderate (1-10%)": 0.35,
    "e_large (10-50%)": 0.15,
    "f_catastrophic (>=50%)": 0.05,
    "no_render": 0.0, "size_mismatch": 0.0, "unknown": 0.2,
}

# Tractability prior per mechanism: how likely one change flips the comparison.
# These are hypotheses stated openly so a later session can move them with
# evidence, not hidden weights.
CLUSTER_PRIOR = {
    "global_color_shift": 1.00,      # a uniform tint = one multiply/one constant
    "offset_translation": 1.00,      # a coordinate off by N
    "alpha_channel_only": 0.90,      # premultiply / background alpha convention
    "halo_penumbra": 0.90,           # filter kernel radius / falloff constant
    "same_geometry_wrong_fill": 0.80,  # colour & compositing math, geometry OK
    "missing_element": 0.60,
    "extra_element": 0.60,
    "extra_ink_on_empty": 0.60,
    "row_banded": 0.55,
    "localized_region": 0.55,
    "content_displaced": 0.50,       # layout / transform
    "diffuse_mixed": 0.40,
    "whole_frame_wrong": 0.35,
    "blank_render": 0.30,            # usually an unimplemented backend
    "hairline_edge_drift": 0.25,     # mostly the lavapipe-vs-Flash AA gap
    "unrelated_content": 0.15,
    "no_render": 0.0,
    "png_unavailable": 0.0,
    "size_mismatch": 0.0,
}

# Two families are unimplemented-backend shaped, not bug shaped: no single fix
# in them flips one comparison, so they are ranked but flagged.
BACKEND_FAMILIES = {"Stage3D / AGAL / shaders", "Video / NetStream"}

# Comparisons excluded from ranking outright (no fix to rank).
UNRANKABLE_CLUSTERS = ("no_render", "png_unavailable", "size_mismatch")


# ---------------------------------------------------------------- features


def modal(x_key):
    vals, counts = np.unique(x_key, return_counts=True)
    i = int(counts.argmax())
    return int(vals[i]), float(counts[i]) / x_key.size, int(vals.size)


def key_of(img):
    v = img.astype(np.uint32)
    return (v[..., 0] << 24) | (v[..., 1] << 16) | (v[..., 2] << 8) | v[..., 3]


def dilate(mask, r=2):
    """Box dilation, done separably: 2*(2r+1) rolls instead of (2r+1)^2."""
    out = mask.copy()
    for d in range(-r, r + 1):
        if d:
            out |= np.roll(mask, d, 0)
    tmp = out.copy()
    for d in range(-r, r + 1):
        if d:
            out |= np.roll(tmp, d, 1)
    return out


def erode(mask):
    out = mask.copy()
    for dy in (-1, 0, 1):
        for dx in (-1, 0, 1):
            if dx or dy:
                out &= np.roll(np.roll(mask, dy, 0), dx, 1)
    return out


def edges_of(gray, thr=24):
    """Cheap morphological gradient: local 3x3 max-min over a grayscale plane."""
    g = gray.astype(np.int16)
    mx = g.copy()
    mn = g.copy()
    for dy in (-1, 0, 1):
        for dx in (-1, 0, 1):
            s = np.roll(np.roll(g, dy, 0), dx, 1)
            mx = np.maximum(mx, s)
            mn = np.minimum(mn, s)
    return (mx - mn) > thr


def best_shift(ga, ge, maxshift=8, ds=2):
    """Does translating our render by a few px collapse the difference?

    Searched on a 2x-downsampled luminance plane, so the reported shift is in
    downsampled units (multiply by `ds` for pixels). Returns
    (dy, dx, count_at_best, count_at_zero).
    """
    a = ga[::ds, ::ds].astype(np.int16)
    e = ge[::ds, ::ds].astype(np.int16)
    h, w = a.shape
    m = max(1, maxshift // ds)
    if h <= 2 * m + 2 or w <= 2 * m + 2:
        return 0, 0, 0, 0
    base = None
    best = None
    for dy in range(-m, m + 1):
        for dx in range(-m, m + 1):
            ac = a[m + dy:h - m + dy, m + dx:w - m + dx]
            ec = e[m:h - m, m:w - m]
            c = int((np.abs(ac - ec) > SIG).sum())
            if dy == 0 and dx == 0:
                base = c
            if best is None or c < best[2]:
                best = (dy, dx, c)
    return best[0] * ds, best[1] * ds, best[2], base


def bands_of(rows):
    """Contiguous True runs in a 1-D boolean row profile -> list of heights."""
    out = []
    run = 0
    for v in rows:
        if v:
            run += 1
        elif run:
            out.append(run)
            run = 0
    if run:
        out.append(run)
    return out


def features(actual_path, expected_path):
    A = np.asarray(Image.open(actual_path).convert("RGBA"), dtype=np.uint8)
    E = np.asarray(Image.open(expected_path).convert("RGBA"), dtype=np.uint8)
    if A.shape != E.shape:
        return {"error": "size_mismatch",
                "actual_size": list(A.shape[:2]), "expected_size": list(E.shape[:2])}

    Ai, Ei = A.astype(np.int16), E.astype(np.int16)
    D = np.abs(Ai - Ei)
    Drgb = D[..., :3].max(axis=2)
    Dall = D.max(axis=2)
    Da = D[..., 3]
    n = Dall.size

    mask_any = Dall > 0
    mask_sig = Dall > SIG
    f = {
        "h": int(A.shape[0]), "w": int(A.shape[1]),
        "sig_frac": float(mask_sig.mean()),
        "any_frac": float(mask_any.mean()),
        "rgb_max": int(Drgb.max()), "alpha_max": int(Da.max()),
        "alpha_only": bool(Drgb.max() <= SIG and Da.max() > SIG),
        "rgb_only": bool(Da.max() <= 1 and Drgb.max() > SIG),
    }

    ka, ke = key_of(A), key_of(E)
    ma, fa, na = modal(ka)
    me, fe, ne = modal(ke)
    f.update(modal_frac_actual=fa, modal_frac_expected=fe,
             ncolors_actual=na, ncolors_expected=ne,
             modal_actual=ma, modal_expected=me,
             same_modal=bool(ma == me))

    bg_a = np.array([(ma >> 24) & 255, (ma >> 16) & 255, (ma >> 8) & 255, ma & 255],
                    dtype=np.int16)
    bg_e = np.array([(me >> 24) & 255, (me >> 16) & 255, (me >> 8) & 255, me & 255],
                    dtype=np.int16)
    ink_a = np.abs(Ai - bg_a).max(axis=2) > INK
    ink_e = np.abs(Ei - bg_e).max(axis=2) > INK
    ia, ie = int(ink_a.sum()), int(ink_e.sum())
    inter = int((ink_a & ink_e).sum())
    union = int((ink_a | ink_e).sum())
    f.update(ink_frac_actual=ia / n, ink_frac_expected=ie / n,
             ink_iou=(inter / union if union else 1.0),
             missing_ink_frac=((ie - inter) / ie if ie else 0.0),
             extra_ink_frac=((ia - inter) / ia if ia else 0.0))

    # Signed difference on differing pixels: a uniform tint has tiny variance.
    if mask_any.any():
        sd = (Ai - Ei)[mask_any]
        f["signed_mean"] = [round(float(x), 2) for x in sd.mean(axis=0)]
        f["signed_std"] = [round(float(x), 2) for x in sd.std(axis=0)]
        f["uniform_shift"] = bool(max(f["signed_std"]) < 4.0
                                  and max(abs(v) for v in f["signed_mean"]) >= 1.0)
    else:
        f["signed_mean"] = f["signed_std"] = [0, 0, 0, 0]
        f["uniform_shift"] = False

    # Bounding box / compactness of the structural difference.
    if mask_sig.any():
        ys, xs = np.nonzero(mask_sig)
        y0, y1, x0, x1 = int(ys.min()), int(ys.max()), int(xs.min()), int(xs.max())
        bh, bw = y1 - y0 + 1, x1 - x0 + 1
        f.update(bbox=[y0, x0, y1, x1],
                 bbox_frac=(bh * bw) / n,
                 bbox_density=float(mask_sig[y0:y1 + 1, x0:x1 + 1].mean()))
        rows = mask_sig.any(axis=1)
        bands = bands_of(rows)
        f.update(diff_row_frac=float(rows.mean()), n_bands=len(bands),
                 band_heights=bands[:40],
                 median_band=float(np.median(bands)) if bands else 0.0)
    else:
        f.update(bbox=None, bbox_frac=0.0, bbox_density=0.0,
                 diff_row_frac=0.0, n_bands=0, band_heights=[], median_band=0.0)

    # Edge containment: is the structural difference just an outline?
    ga = (Ai[..., :3].mean(axis=2)).astype(np.int16)
    ge = (Ei[..., :3].mean(axis=2)).astype(np.int16)
    raw_edges = edges_of(ge) | edges_of(ga)
    ed = dilate(raw_edges, r=2)
    if mask_sig.any():
        s = mask_sig.sum()
        f["edge_containment"] = float((mask_sig & ed).sum() / s)
        # Wider ring: a blur/glow/shadow radius error puts the difference NEAR
        # an edge but not ON it, which r=2 containment cannot see.
        f["halo_containment"] = float((mask_sig & dilate(raw_edges, r=8)).sum() / s)
        # Thickness: 1px hairline drift does not survive a 3x3 erosion;
        # a displaced or repainted region does.
        f["erode_survival"] = float(erode(mask_sig).sum() / s)
    else:
        f["edge_containment"] = f["halo_containment"] = 1.0
        f["erode_survival"] = 0.0

    # Translation probe (skipped when there is nothing structural to align).
    if mask_sig.any() and f["sig_frac"] > 1e-5:
        dy, dx, cb, c0 = best_shift(ga, ge)
        f.update(shift_dy=dy, shift_dx=dx, shift_best=cb, shift_zero=c0,
                 shift_gain=(1 - cb / c0) if c0 else 0.0)
    else:
        f.update(shift_dy=0, shift_dx=0, shift_best=0, shift_zero=0, shift_gain=0.0)
    return f


# ---------------------------------------------------------------- classify


def classify(row, f):
    """Mechanism cluster. First match wins; the order IS the diagnosis."""
    if row.get("reason") == "no_render":
        return "no_render", "no actual PNG produced"
    if f.get("error") == "size_mismatch":
        return "size_mismatch", f"{f['actual_size']} vs {f['expected_size']}"

    fa, fe = f["modal_frac_actual"], f["modal_frac_expected"]

    miss, extra, iou = f["missing_ink_frac"], f["extra_ink_frac"], f["ink_iou"]

    # 1. We rendered (almost) nothing where content belongs.
    if f["ink_frac_actual"] < 0.002 and f["ink_frac_expected"] > 0.01:
        sub = "flat" if fa > 0.995 else "near-flat"
        return "blank_render", (f"actual is {sub} ({fa:.3f} one colour), "
                                f"expected has {f['ink_frac_expected']:.1%} ink")
    # 2. We rendered something onto a frame that should be (almost) empty.
    if f["ink_frac_expected"] < 0.002 and f["ink_frac_actual"] > 0.01:
        return "extra_ink_on_empty", f"actual ink {f['ink_frac_actual']:.1%}, expected ~0"
    # 3. Alpha channel only.
    if f["alpha_only"]:
        return "alpha_channel_only", f"rgb_max={f['rgb_max']} alpha_max={f['alpha_max']}"
    # 4. Uniform tint over the whole frame.
    if f["uniform_shift"] and f["any_frac"] > 0.25:
        return "global_color_shift", (f"signed mean {f['signed_mean']} "
                                      f"std {f['signed_std']}")
    # 5. Translation: shifting our whole render collapses the difference.
    if f["shift_gain"] >= 0.55 and (f["shift_dy"], f["shift_dx"]) != (0, 0):
        return "offset_translation", (f"dy={f['shift_dy']} dx={f['shift_dx']} "
                                      f"removes {f['shift_gain']:.0%} of the diff")
    # 6. Hairline: 1px-thin, edge-hugging, geometry otherwise identical. This is
    #    what lavapipe-vs-Ruffle antialiasing looks like. The erosion test is
    #    what keeps re-laid-out text (also all-edges) out of this bucket.
    if (f["edge_containment"] >= 0.90 and f["erode_survival"] < 0.12
            and iou > 0.90 and miss < 0.10 and extra < 0.10):
        return "hairline_edge_drift", (f"{f['edge_containment']:.0%} on edges, "
                                       f"{f['erode_survival']:.0%} survives erosion, "
                                       f"ink IoU {iou:.2f}")
    # 7. Same ink, repainted interior: geometry agrees, pixels do not.
    if iou > 0.85 and miss < 0.15 and extra < 0.15 and f["erode_survival"] >= 0.25:
        return "same_geometry_wrong_fill", (f"ink IoU {iou:.2f}, "
                                            f"{f['sig_frac']:.1%} of pixels repainted")
    # 8. Halo: the difference rings the edges rather than sitting on them —
    #    a blur/glow/shadow radius or falloff error.
    if f["halo_containment"] >= 0.92 and f["edge_containment"] < 0.80:
        return "halo_penumbra", (f"{f['halo_containment']:.0%} within 8px of an "
                                 f"edge but only {f['edge_containment']:.0%} on one")
    # 9. Almost nothing in common: we draw a picture, just not this one.
    if iou < 0.12 and f["ink_frac_actual"] > 0.02 and f["ink_frac_expected"] > 0.02:
        return "unrelated_content", (f"ink IoU {iou:.2f} with {f['ink_frac_actual']:.0%}"
                                     f"/{f['ink_frac_expected']:.0%} ink on each side")
    # 10. Same content, different place: both sides have ink the other lacks.
    if miss > 0.30 and extra > 0.30:
        return "content_displaced", (f"{miss:.0%} of expected ink missing AND "
                                     f"{extra:.0%} of ours unexpected")
    # 11. Content present in expected, absent in ours (partial).
    if miss > 0.40 and extra < 0.25:
        return "missing_element", f"{miss:.0%} of expected ink absent from our render"
    # 12. Content we draw that should not be there (partial).
    if extra > 0.40 and miss < 0.25:
        return "extra_element", f"{extra:.0%} of our ink not present in expected"
    # 13. Confined to a few horizontal bands of glyph height.
    if (f["n_bands"] and f["n_bands"] <= 24 and 3 <= f["median_band"] <= 40
            and f["diff_row_frac"] < 0.6 and f["sig_frac"] < 0.25):
        return "row_banded", (f"{f['n_bands']} bands, median height "
                              f"{f['median_band']:.0f}px, "
                              f"{f['diff_row_frac']:.0%} of rows")
    # 14. Compact blob.
    if f["bbox_frac"] < 0.15 and f["bbox_density"] > 0.05:
        return "localized_region", (f"bbox {f['bbox_frac']:.1%} of frame, "
                                    f"density {f['bbox_density']:.0%}")
    # 15. Whole frame wrong.
    if f["sig_frac"] >= 0.35:
        return "whole_frame_wrong", f"{f['sig_frac']:.0%} of pixels structurally differ"
    return "diffuse_mixed", (f"sig {f['sig_frac']:.1%}, ink IoU {iou:.2f}, "
                             f"edge {f['edge_containment']:.0%}, "
                             f"halo {f['halo_containment']:.0%}")


# ---------------------------------------------------------------- dispositions

# Docs that disposition a diff as permanent/intentional, with the suite prefixes
# an UNQUALIFIED name in them applies to. A name written `suite/path/test` in a
# doc matches across suites regardless of scope; a bare name only matches inside
# its own doc's scope, so avm1's `### \`date\`` cannot silently disposition some
# other suite's test that happens to share a basename.
DISPOSITION_DOCS = [
    ("ACCEPTED_DIFFS (avm1)", "avm1/_investigation/ACCEPTED_DIFFS.md", ("avm1",)),
    ("RUFFLE_VS_FLASH (avm1)",
     "avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md", ("avm1",)),
    ("ACCEPTED_DIFFS (from_gnash)",
     "from_gnash/_investigation/ACCEPTED_DIFFS.md", ("from_gnash",)),
]

_NAME_RE = re.compile(r"`([A-Za-z0-9][\w./-]{2,})`")
_HEADING_RE = re.compile(r"^#{2,4}\s+(.*)$")
_TESTLINE_RE = re.compile(r"^\s*\*\*Tests?:?\*\*\s*(.*)$", re.IGNORECASE)
# Does an entry disposition the IMAGE axis, or only the trace axis? Most entries
# in these docs are about diff LINES and say nothing about pixels; excluding a
# test's image comparison on the strength of a trace-axis entry would silently
# delete real graphics work from the board. Note `pixel` is deliberately absent —
# `bitmap_data_thorough/pixelDissolve` is a trace-axis entry whose body is full
# of "dest pixel positions".
_IMAGE_AXIS_RE = re.compile(
    r"\bimages?\b|\boutliers?\b|\bpx\b|\bMSAA\b|\.png\b|\bantialias", re.IGNORECASE)
# Explicit override, because the keyword heuristic cannot read negations ("has
# no [image_comparisons] block" contains "image"). Put one of these in an entry
# body to state the axis outright — and to state its SCOPE, which a per-test
# match cannot otherwise express:
#     <!-- image-axis: none -->               trace-axis entry, keep on the board
#     <!-- image-axis: frames 1-2 only -->    partial: the scope is printed
_AXIS_OVERRIDE_RE = re.compile(r"<!--\s*image-axis:\s*(.*?)\s*-->", re.IGNORECASE)
_AXIS_NONE = {"none", "no", "false", "trace", "trace-only", "trace-axis"}


def scan_disposition_doc(path):
    """{name: {"subject": str, "image_axis": bool}} for one disposition doc.

    Three shapes carry an entry subject in these docs, and nothing else does:
      `### \\`name\\` — why`   entry headings   (body = up to the next heading)
      `**Test:** \\`name\\``   RUFFLE_VS_FLASH entry bodies
      `| \\`name\\` | … |`      the summary tables at the end of ACCEPTED_DIFFS
                              (the row itself is the body)
    Prose backticks are deliberately NOT scanned: they name APIs and neighbours,
    not subjects, and would disposition half the corpus.
    """
    out = {}
    if not path.exists():
        return out

    def record(names, subject, body):
        m = _AXIS_OVERRIDE_RE.search(body)
        scope = None
        if m:
            scope = m.group(1)
            img = scope.lower() not in _AXIS_NONE
        else:
            img = bool(_IMAGE_AXIS_RE.search(body))
        for name in names:
            # First subject wins: entry headings come before the summary tables
            # in these docs, and the heading is the readable one.
            e = out.setdefault(name, {"subject": subject.strip(),
                                      "image_axis": False, "scope": None,
                                      "explicit": False})
            if e["explicit"]:
                continue          # an explicit marker is authoritative
            e["image_axis"] = e["image_axis"] or img
            if m:
                e["image_axis"], e["explicit"], e["scope"] = img, True, scope

    cur_names, cur_subject, cur_body = [], "", []
    for line in path.read_text(errors="replace").splitlines():
        m = _HEADING_RE.match(line)
        if m:
            if cur_names:
                record(cur_names, cur_subject, "\n".join(cur_body))
            cur_subject = m.group(1)
            cur_names = _NAME_RE.findall(cur_subject)
            cur_body = [cur_subject]
            continue
        m = _TESTLINE_RE.match(line)
        if m:
            extra = _NAME_RE.findall(m.group(1))
            cur_names = list(dict.fromkeys(cur_names + extra))
        if line.startswith("|") and line.count("|") >= 2 and "`" in line.split("|")[1]:
            record(_NAME_RE.findall(line.split("|")[1]), line.split("|")[1], line)
        cur_body.append(line)
    if cur_names:
        record(cur_names, cur_subject, "\n".join(cur_body))
    return out


def load_ignored(swfs_root, ruffle_root):
    """(global set, {suite: suite-local set}) — the two lists filter_results.py unions.

    They are NOT the same kind of statement and this tool keeps them apart:

    * `ruffle-tests/ignored_tests.txt` is the project's global disposition list —
      CLAUDE.md requires a test added to ACCEPTED_DIFFS to be added here too.
    * A suite-local list (`avm2/ignored_tests.txt` et al) is TRACE-axis triage.
      avm2's says so in its own header: "seeded 2026-07-10 … before any AVM2
      implementation exists … re-triage each bucket as support grows". 113 of its
      entries have failing image comparisons — stage3d, blend, bitmapdata,
      graphics — i.e. the pixel corpus itself. Treating that as an image
      disposition would delete most of the board.
    """
    def read(p):
        if not p.exists():
            return set()
        return {ln.strip() for ln in p.read_text().splitlines()
                if ln.strip() and not ln.strip().startswith("#")}

    glob_set = read(ruffle_root / "ignored_tests.txt")
    per_suite = {}
    for p in sorted(swfs_root.rglob("ignored_tests.txt")):
        per_suite[p.parent.relative_to(swfs_root).as_posix()] = read(p)
    return glob_set, per_suite


class Dispositions:
    """Every source that says "this diff is expected", resolved per comparison.

    Returns a (label, confidence, hard) triple. `hard` rows are excluded from the
    board; soft rows are flagged and kept, because a trace-axis statement says
    nothing about the pixels — image comparisons never gate trace pass/fail.
    """

    def __init__(self, swfs_root, ruffle_root):
        self.docs = []
        for label, rel, scope in DISPOSITION_DOCS:
            self.docs.append((label, scope, scan_disposition_doc(swfs_root / rel)))
        self.ignored_global, self.ignored_suite = load_ignored(swfs_root, ruffle_root)

    def _suite_ignored(self, suite):
        names = set()
        for s, extra in self.ignored_suite.items():
            if s and (suite == s or suite.startswith(s + "/")):
                names |= extra
        return names

    @staticmethod
    def _scope_covers(scope, comparison):
        """Does an `<!-- image-axis: frames 1-2 only -->` scope cover this frame?

        -> True/False, or None when the scope is not a frame range (then the
        whole test stays dispositioned and the scope is only printed).
        """
        if not scope or not comparison:
            return None
        nums = re.findall(r"\d+", scope)
        m = re.fullmatch(r"frame(\d+)", comparison.strip())
        if not nums or "frame" not in scope.lower() or not m:
            return None
        n = int(m.group(1))
        if re.search(r"\d+\s*[-–]\s*\d+", scope):
            lo, hi = int(nums[0]), int(nums[1])
            return lo <= n <= hi
        return n in {int(x) for x in nums}

    def lookup(self, suite, test, comparison=None):
        """-> (label, confidence, hard); (None, None, False) when undispositioned.

        `confidence` is "exact" or "basename" — a basename match across suites is
        a HEURISTIC (ignored_tests.txt is applied per suite by filter_results.py,
        so a same-named test in another suite is not necessarily ignored) and is
        printed as such rather than as a fact.
        """
        qualified = f"{suite}/{test}"
        base = test.split("/")[-1]
        for label, scope, names in self.docs:
            in_scope = any(suite == s or suite.startswith(s + "/") for s in scope)
            hit, conf = None, "exact"
            if qualified in names:                 # `suite/path/test` in the doc
                hit = names[qualified]
            elif test in names or base in names:
                hit = names.get(test) or names[base]
                # Out of the doc's own suite scope this is a NAME collision as
                # much as a match — same trap as a cross-suite ignored_tests hit.
                conf = "exact" if in_scope else "basename"
            if hit is not None:
                covers = self._scope_covers(hit.get("scope"), comparison)
                if covers is False:
                    # The entry explicitly does NOT cover this frame — it is live
                    # work, not a disposition. (`from_gnash simple_loop_test` is
                    # accepted for frames 1-2 and a timeline-phase bug in 3-7.)
                    return None, None, False
                if not hit["image_axis"]:
                    axis = " [TRACE-AXIS ENTRY, kept on the board]"
                elif hit.get("scope") and covers is None:
                    axis = f"  [image-axis SCOPE: {hit['scope']} — verify per comparison]"
                elif hit.get("scope"):
                    axis = f"  [in scope: {hit['scope']}]"
                else:
                    axis = ""
                return (f"{label}: {hit['subject']}"[:170] + axis, conf,
                        hit["image_axis"])
        if test in self.ignored_global:
            return "ignored_tests.txt (global)", "exact", True
        if base in self.ignored_global:
            return "ignored_tests.txt (global)", "basename", True
        sig = self._suite_ignored(suite)
        if test in sig or base in sig:
            return ("suite ignored_tests.txt (TRACE-axis triage, kept on the board)",
                    "exact" if test in sig else "basename", False)
        return None, None, False


# ---------------------------------------------------------------- driver


def load_rows(swfs_root, stem):
    """Every comparison in every per-suite image report, minus nested duplicates.

    `from_shumway/avm1` lives inside `from_shumway`, whose own run already graded
    those tests — summing both double-counts them, the pixel-side version of the
    4414-vs-4463 trace denominator.
    """
    rows = []
    reports = 0
    for p in sorted(swfs_root.rglob(f"_results/image_results_{stem}.json")):
        rep = json.loads(p.read_text())
        suite = rep["metadata"]["suite"]
        if suite in NESTED_SUITES:
            continue
        reports += 1
        for r in rep["results"]:
            r["_git_sha"] = rep["metadata"].get("git_sha")
            r["_timestamp"] = rep["metadata"].get("timestamp")
            r["_incomplete"] = rep["metadata"].get("incomplete", False)
            rows.append(r)
    if not rows:
        sys.exit(f"no image_results_{stem}.json under {swfs_root} — merge an "
                 f"images=true CI run first (see .claude/pipeline-handoff.md)")
    return rows, reports


def resolve_images_dir(arg):
    """Accept the branch root or its `images/` subdir; search the conventions."""
    cands = []
    if arg:
        cands = [Path(arg)]
    else:
        for c in IMAGES_DIR_CANDIDATES:
            if isinstance(c, str) and c.startswith("$"):
                env = os.environ.get(c[1:])
                if env:
                    cands.append(Path(env))
            else:
                cands.append(Path(c))
    for c in cands:
        if (c / "images").is_dir():
            return c / "images"
        if c.is_dir() and c.name == "images":
            return c
    tried = "\n  ".join(str(c) for c in cands)
    sys.exit(
        "no ruffle-image-results checkout found. Tried:\n  " + tried +
        "\n\nFetch one with:\n"
        "  git fetch origin ruffle-image-results\n"
        "  git worktree add .image-results origin/ruffle-image-results\n"
        "or pass --images-dir DIR.")


def work(job):
    row, actual, expected = job
    a, e = Path(actual), Path(expected)
    if not a.exists() or not e.exists():
        f = {"error": "missing_png",
             "have_actual": a.exists(), "have_expected": e.exists()}
    else:
        try:
            f = features(a, e)
        except Exception as exc:                      # noqa: BLE001
            f = {"error": f"{type(exc).__name__}: {exc}"}
    if f.get("error") == "missing_png" and row.get("reason") != "no_render":
        cluster, why = "png_unavailable", str(f)
    else:
        cluster, why = classify(row, f)
    keep = ("suite", "test", "comparison", "trace_status", "known_failure",
            "reason", "max_diff", "outliers", "max_outliers", "excess_outliers",
            "total_channels", "diff_channels", "mean_diff", "width", "height",
            "_git_sha")
    return {**{k: row.get(k) for k in keep},
            "cluster": cluster, "why": why,
            "actual_png": str(a), "expected_png": str(e),
            "features": f}


def extract(rows, images_root, swfs_root, jobs, progress=True):
    jobs_list = [
        (r,
         str(images_root / r["suite"] / r["test"] / f"{r['comparison']}.actual.png"),
         str(swfs_root / r["suite"] / r["test"] / f"{r['comparison']}.expected.png"))
        for r in rows
    ]
    out = []
    if jobs <= 1:
        for i, j in enumerate(jobs_list):
            out.append(work(j))
        return out
    with ProcessPoolExecutor(max_workers=jobs) as ex:
        for i, res in enumerate(ex.map(work, jobs_list, chunksize=2)):
            out.append(res)
            if progress and i % 25 == 0:
                print(f"  {i}/{len(jobs_list)}", file=sys.stderr, flush=True)
    return out


# ---------------------------------------------------------------- ranking


def score(r):
    prox = BAND_PROX.get(r["band"], 0.2)
    prior = CLUSTER_PRIOR.get(r["cluster"], 0.4)
    return prior * math.log2(1 + r["fanout"]) * (0.40 + 0.60 * prox)


def annotate(rows, disp):
    """Band, family, disposition, fanout and score, in place."""
    for r in rows:
        r["band"] = near_miss_band(r)
        r["family"] = family_of(r["suite"], r["test"])
        label, conf, hard = disp.lookup(r["suite"], r["test"], r["comparison"])
        r["dispositioned"] = label if hard else None
        r["soft_disposition"] = label if (label and not hard) else None
        r["disposition_match"] = conf
    fan = Counter((r["cluster"], r["family"]) for r in rows)
    fan_tests = defaultdict(set)
    for r in rows:
        fan_tests[(r["cluster"], r["family"])].add((r["suite"], r["test"]))
    for r in rows:
        r["fanout"] = fan[(r["cluster"], r["family"])]
        r["fanout_tests"] = len(fan_tests[(r["cluster"], r["family"])])
        r["score"] = round(score(r), 3)
    return rows


def live_rows(rows):
    """Rankable: not dispositioned, not a Ruffle known_failure, has a mechanism."""
    return [r for r in rows
            if not r["dispositioned"] and not r.get("known_failure")
            and r["cluster"] not in UNRANKABLE_CLUSTERS]


def group_board(live):
    """One row per (test, cluster): a fix lands on a test, not on a frame.

    Without the roll-up `from_shumway/acid`'s 16 frames own the top of the board.
    The group score credits the extra comparisons one fix would flip.
    """
    groups = defaultdict(list)
    for r in live:
        groups[(r["suite"], r["test"], r["cluster"])].append(r)
    board = []
    for (s, t, c), v in groups.items():
        best = max(v, key=lambda r: r["score"])
        board.append({
            "suite": s, "test": t, "cluster": c, "cmps": len(v),
            "family": best["family"], "fanout": best["fanout"],
            "fanout_tests": best["fanout_tests"],
            "band": min(v, key=lambda r: BAND_PROX.get(r["band"], 1))["band"],
            "excess": min((r.get("excess_outliers") or 0) for r in v),
            "backend": best["family"] in BACKEND_FAMILIES,
            "soft_disposition": next((r["soft_disposition"] for r in v
                                      if r["soft_disposition"]), None),
            "score": round(best["score"] * (1 + 0.25 * math.log2(len(v))), 3),
        })
    board.sort(key=lambda r: (-r["score"], r["excess"]))
    return board


def frame_phase_suspects(rows):
    """A test whose own frames disagree about the mechanism.

    "We drew nothing" next to "we drew something extra" inside one test is a
    timeline-phase off-by-one, not N independent rendering bugs.
    """
    per_test = defaultdict(list)
    for r in rows:
        per_test[(r["suite"], r["test"])].append(r)
    out = []
    for k, v in per_test.items():
        cs = {r["cluster"] for r in v}
        if len(v) >= 3 and ({"blank_render", "extra_element"} <= cs
                            or {"blank_render", "extra_ink_on_empty"} <= cs
                            or len(cs) >= 4):
            out.append((k, len(v), sorted(cs)))
    return sorted(out)


def stale_dispositions(all_rows, failing_keys, disp):
    """Dispositioned tests that are NOT in the failing set.

    Reported rather than silently dropped: a disposition whose comparison now
    PASSES (or that has no `[image_comparisons]` block at all) is a stale entry
    in ACCEPTED_DIFFS on the image axis, and worth a one-line note there.
    """
    by_test = defaultdict(list)
    for r in all_rows:
        by_test[(r["suite"], r["test"])].append(r)
    out = []
    for key, rs in sorted(by_test.items()):
        if any((r["suite"], r["test"], r["comparison"]) in failing_keys for r in rs):
            continue
        label, conf, hard = disp.lookup(*key)
        if not (label and hard):
            continue
        st = Counter(r["status"] for r in rs)
        out.append((key, dict(st), label, conf))
    return out


# ---------------------------------------------------------------- reporting


def band_short(b):
    return b.split(" ")[0]


def emit_text(rows, board, live, args, meta, phase, stale, out=sys.stdout):
    p = lambda *a: print(*a, file=out)                       # noqa: E731
    p(f"=== image triage: {len(rows)} failing comparisons "
      f"({meta['reports']} suites, stem={args.stem}, git_sha={meta['git_sha']}) ===")
    if meta["incomplete"]:
        p("!! at least one suite report is metadata.incomplete — a shard was lost; "
          "counts are a FLOOR")

    p("\n== CLUSTER TOTALS ==")
    cl = Counter(r["cluster"] for r in rows)
    for c, n in cl.most_common():
        tests = len({(r["suite"], r["test"]) for r in rows if r["cluster"] == c})
        near = sum(1 for r in rows if r["cluster"] == c
                   and BAND_PROX.get(r["band"], 0) >= 0.85)
        fams = Counter(r["family"] for r in rows if r["cluster"] == c)
        top = ", ".join(f"{k.split(':')[0].split(' (')[0]} {v}"
                        for k, v in fams.most_common(3))
        p(f"{n:5} cmps / {tests:3} tests / near {near:3}  {c:26} "
          f"prior={CLUSTER_PRIOR.get(c, 0.4):.2f}  | {top}")

    p("\n== CLUSTER x BAND ==")
    bands = [b for b in BAND_PROX if b != "unknown"]
    p(f"{'cluster':26} " + " ".join(f"{band_short(b):>6}" for b in bands))
    for c, _ in cl.most_common():
        cnt = Counter(r["band"] for r in rows if r["cluster"] == c)
        p(f"{c:26} " + " ".join(f"{cnt[b]:>6}" for b in bands))

    p(f"\n== FRAME-PHASE SUSPECTS ({len(phase)}) — a test whose own frames "
      f"disagree about the mechanism ==")
    p("   listed even when DISPOSITIONED: a disposition is written about one "
      "mechanism, and a phase")
    p("   mismatch across frames is usually not the mechanism it describes "
      "(see from_gnash simple_loop_test).")
    for (s, t), n, cs in phase:
        d = " [dispositioned by name — check the entry's scope]" if any(
            r["dispositioned"] for r in rows
            if (r["suite"], r["test"]) == (s, t)) else ""
        p(f"  {s}/{t}  {n} cmps: {', '.join(cs)}{d}")

    p(f"\n== TOP {args.top} TESTS (of {len(board)} live test x cluster rows, "
      f"{len(live)} comparisons; {len(rows) - len(live)} excluded as "
      f"dispositioned / known_failure / no_render) ==")
    p("   ranked by MECHANISM x fanout x band-proximity — near-pass alone would "
      "put the unfixable AA cluster on top")
    p(f"{'#':>3} {'score':>5} {'cmp':>3} {'fanT':>4} {'suite/test':52} "
      f"{'cluster':24} {'band':10} excess")
    for i, r in enumerate(board[:args.top], 1):
        name = f"{r['suite']}/{r['test']}"
        p(f"{i:>3} {r['score']:>5.2f} {r['cmps']:>3} {r['fanout_tests']:>4} "
          f"{name[:52]:52} {r['cluster'][:24]:24} "
          f"{band_short(r['band']):10} {r['excess']}"
          f"{' [BACKEND]' if r['backend'] else ''}"
          f"{' [trace-ign]' if r['soft_disposition'] else ''}")

    p("\n== TOP GROUPS (cluster x family, live comparisons only) ==")
    g = Counter((r["cluster"], r["family"]) for r in live)
    gs = defaultdict(float)
    for r in live:
        gs[(r["cluster"], r["family"])] += r["score"]
    for (c, fm), n in sorted(g.items(), key=lambda kv: -gs[kv[0]])[:15]:
        near = sum(1 for r in live if (r["cluster"], r["family"]) == (c, fm)
                   and BAND_PROX.get(r["band"], 0) >= 0.6)
        flag = "  [BACKEND]" if fm in BACKEND_FAMILIES else ""
        p(f"  {n:4} cmps  (near {near:3})  {c:26} x  {fm}{flag}")

    dis = [r for r in rows if r["dispositioned"]]
    p(f"\n== DISPOSITIONED FAILING COMPARISONS ({len(dis)}) — excluded from the "
      f"board ==")
    for r in sorted(dis, key=lambda r: (r["suite"], r["test"], r["comparison"])):
        heur = "  (matched by basename — VERIFY)" if r["disposition_match"] == "basename" else ""
        p(f"  {r['suite']}/{r['test']} [{r['comparison']}]  {r['cluster']}"
          f"  <- {r['dispositioned']}{heur}")

    soft = [r for r in rows if r["soft_disposition"]]
    if soft:
        by_suite = Counter(r["suite"] for r in soft)
        p(f"\n== TRACE-AXIS FLAGS ({len(soft)}) — KEPT on the board ==")
        p("   a suite-local ignored_tests.txt entry (or a trace-axis ACCEPTED_DIFFS "
          "entry) says nothing")
        p("   about the pixels: image comparisons never gate trace pass/fail. "
          "Marked [trace-ign] above.")
        p("   " + ", ".join(f"{s} {n}" for s, n in by_suite.most_common()))

    if stale:
        p(f"\n== DISPOSITIONED BUT NOT FAILING ({len(stale)}) — the entry is stale "
          f"on the image axis; worth a one-line note in its doc ==")
        for (s, t), st, label, conf in stale:
            heur = " (basename)" if conf == "basename" else ""
            p(f"  {s}/{t}  {dict(st)}  <- {label}{heur}")

    kf = [r for r in rows if r.get("known_failure")]
    p(f"\n== RUFFLE known_failure ({len(kf)}) — Ruffle is NOT the oracle here, "
      f"matching its expected PNG is not a goal ==")
    for r in sorted(kf, key=lambda r: (r["suite"], r["test"], r["comparison"])):
        p(f"  {r['suite']}/{r['test']} [{r['comparison']}]  {r['cluster']}")


def emit_markdown(rows, board, live, args, meta, phase, stale, path):
    L = []
    A = L.append
    A("# Image triage board")
    A("")
    A(f"`scripts/image_triage.py --stem {args.stem}` over {len(rows)} failing "
      f"comparisons from the image run at `{meta['git_sha']}` "
      f"({meta['timestamp']}).")
    A("")
    A("Ranked by **mechanism** first. Near-pass ranking alone aims at "
      "`hairline_edge_drift`, which is mostly the lavapipe-vs-Flash antialiasing "
      "gap — the least fixable cluster in the corpus.")
    A("")
    A("## Clusters")
    A("")
    A("| cluster | cmps | tests | near-pass | prior | example tests |")
    A("|---|---:|---:|---:|---:|---|")
    cl = Counter(r["cluster"] for r in rows)
    for c, n in cl.most_common():
        members = [r for r in rows if r["cluster"] == c]
        tests = sorted({f"{r['suite']}/{r['test']}" for r in members})
        near = sum(1 for r in members if BAND_PROX.get(r["band"], 0) >= 0.85)
        # Examples ordered by score, so the biggest family in the cluster leads
        # rather than whatever sorts first alphabetically.
        by_score = {}
        for r in sorted(members, key=lambda r: -r["score"]):
            by_score.setdefault(f"{r['suite']}/{r['test']}", None)
        ex = ", ".join(f"`{t}`" for t in list(by_score)[:4])
        A(f"| `{c}` | {n} | {len(tests)} | {near} | "
          f"{CLUSTER_PRIOR.get(c, 0.4):.2f} | {ex} |")
    A(f"| **total** | **{len(rows)}** | | "
      f"**{sum(1 for r in rows if BAND_PROX.get(r['band'], 0) >= 0.85)}** | | |")
    A("")
    A("## Cluster x band")
    A("")
    A("```")
    bands = [b for b in BAND_PROX if b != "unknown"]
    A(f"{'cluster':26} " + " ".join(f"{band_short(b):>6}" for b in bands))
    for c, _ in cl.most_common():
        cnt = Counter(r["band"] for r in rows if r["cluster"] == c)
        A(f"{c:26} " + " ".join(f"{cnt[b]:>6}" for b in bands))
    A("```")
    A("")
    A(f"## Top {args.top} (of {len(board)} live test x cluster rows, "
      f"{len(live)} comparisons)")
    A("")
    A("| # | score | cmps | fan(tests) | suite/test | cluster | band | excess |")
    A("|---:|---:|---:|---:|---|---|---|---:|")
    for i, r in enumerate(board[:args.top], 1):
        flag = (" **[BACKEND]**" if r["backend"] else "") + \
               (" *[trace-ign]*" if r["soft_disposition"] else "")
        A(f"| {i} | {r['score']:.2f} | {r['cmps']} | {r['fanout_tests']} | "
          f"`{r['suite']}/{r['test']}` | {r['cluster']} | "
          f"{band_short(r['band'])} | {r['excess']}{flag} |")
    A("")
    A("## Top groups (cluster x family, live comparisons only)")
    A("")
    A("| cmps | near-pass | cluster x family |")
    A("|---:|---:|---|")
    g = Counter((r["cluster"], r["family"]) for r in live)
    gs = defaultdict(float)
    for r in live:
        gs[(r["cluster"], r["family"])] += r["score"]
    for (c, fm), n in sorted(g.items(), key=lambda kv: -gs[kv[0]])[:15]:
        near = sum(1 for r in live if (r["cluster"], r["family"]) == (c, fm)
                   and BAND_PROX.get(r["band"], 0) >= 0.6)
        flag = " **[BACKEND]**" if fm in BACKEND_FAMILIES else ""
        A(f"| {n} | {near} | `{c}` x {fm}{flag} |")
    A("")
    if phase:
        A("## Frame-phase suspects")
        A("")
        A("A test whose own frames disagree about the mechanism — "
          "a timeline-phase off-by-one, not N independent rendering bugs. "
          "Listed even when dispositioned: a disposition is written about one "
          "mechanism, and a phase mismatch is usually not that mechanism.")
        A("")
        for (s, t), n, cs in phase:
            A(f"- `{s}/{t}` — {n} cmps: {', '.join(cs)}")
        A("")
    dis = [r for r in rows if r["dispositioned"]]
    A(f"## Dispositioned failing comparisons ({len(dis)}) — excluded from the board")
    A("")
    A("| comparison | cluster | disposition |")
    A("|---|---|---|")
    for r in sorted(dis, key=lambda r: (r["suite"], r["test"], r["comparison"])):
        heur = " (matched by basename — VERIFY)" if r["disposition_match"] == "basename" else ""
        A(f"| `{r['suite']}/{r['test']} [{r['comparison']}]` | {r['cluster']} | "
          f"{r['dispositioned']}{heur} |")
    A("")
    soft = [r for r in rows if r["soft_disposition"]]
    if soft:
        by_suite = Counter(r["suite"] for r in soft)
        A(f"## Trace-axis flags ({len(soft)}) — kept on the board")
        A("")
        A("A suite-local `ignored_tests.txt` entry (or a trace-axis ACCEPTED_DIFFS "
          "entry) says nothing about the pixels: image comparisons never gate trace "
          "pass/fail. Marked `[trace-ign]` in the board above.")
        A("")
        A("| suite | comparisons |")
        A("|---|---:|")
        for s, n in by_suite.most_common():
            A(f"| `{s}` | {n} |")
        A("")
    if stale:
        A(f"## Dispositioned but not failing ({len(stale)})")
        A("")
        A("The entry is stale on the image axis — it passes, or it has no "
          "`[image_comparisons]` block at all. Worth a one-line note in its doc.")
        A("")
        for (s, t), st, label, conf in stale:
            A(f"- `{s}/{t}` — {st} — {label}{' (basename)' if conf == 'basename' else ''}")
        A("")
    kf = [r for r in rows if r.get("known_failure")]
    A(f"## Ruffle `known_failure` ({len(kf)})")
    A("")
    A("Ruffle is not the oracle on these; matching its expected PNG is not a goal.")
    A("")
    for r in sorted(kf, key=lambda r: (r["suite"], r["test"], r["comparison"])):
        A(f"- `{r['suite']}/{r['test']} [{r['comparison']}]` — {r['cluster']}")
    A("")
    Path(path).write_text("\n".join(L))


def emit_explain(rows, sel):
    """--test SUITE/TEST: every feature of every comparison of one test."""
    hits = [r for r in rows
            if f"{r['suite']}/{r['test']}" == sel or r["test"] == sel
            or r["test"].split("/")[-1] == sel]
    if not hits:
        sys.exit(f"no FAILING comparison matches {sel!r}")
    for r in sorted(hits, key=lambda r: r["comparison"]):
        print(f"\n=== {r['suite']}/{r['test']} [{r['comparison']}] ===")
        print(f"  cluster   {r['cluster']}  ({r['why']})")
        print(f"  band      {near_miss_band(r)}   family {family_of(r['suite'], r['test'])}")
        print(f"  reason    {r['reason']}   known_failure={r['known_failure']}   "
              f"trace={r['trace_status']}")
        print(f"  outliers  {r['outliers']} / budget {r['max_outliers']} "
              f"-> excess {r['excess_outliers']}   max_diff {r['max_diff']}")
        print(f"  actual    {r['actual_png']}")
        print(f"  expected  {r['expected_png']}")
        for k, v in sorted(r["features"].items()):
            if isinstance(v, float):
                v = round(v, 4)
            print(f"    {k:22} {v}")


# ---------------------------------------------------------------- main


def main():
    ap = argparse.ArgumentParser(
        description=__doc__.split("\n\n")[0],
        epilog="Rank by MECHANISM first: near-pass ranking alone aims at the "
               "unfixable lavapipe-AA cluster (hairline_edge_drift owns 35 of "
               "44 near-passes and zero moderate-or-worse failures).",
        formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--images-dir", help="checkout/extract of the ruffle-image-results "
                    "branch (its root, or its images/ subdir). Default: "
                    "$IMAGE_RESULTS_DIR, ./.image-results, ./image-results, "
                    "../ruffle-image-results")
    ap.add_argument("--swfs-dir", default=str(DEFAULT_SWFS),
                    help="test tree holding _results/*.json and the expected PNGs "
                         "(default: this checkout's ruffle-tests/tests/swfs)")
    ap.add_argument("--docs-dir",
                    help="test tree holding the disposition docs and "
                         "ignored_tests.txt (default: --swfs-dir). Split them "
                         "when grading a merged run from a working branch.")
    ap.add_argument("--stem", default="graphics",
                    help="read image_results_<stem>.json (default: graphics)")
    ap.add_argument("--jobs", type=int, default=4, help="worker processes (default 4)")
    ap.add_argument("--out", default="image_triage.json",
                    help="row JSON (default image_triage.json; '' to skip)")
    ap.add_argument("--markdown", default="image_triage.md",
                    help="markdown board (default image_triage.md; '' to skip)")
    ap.add_argument("--top", type=int, default=25,
                    help="board rows to print (default 25)")
    ap.add_argument("--cluster", help="print only this cluster's members, then exit")
    ap.add_argument("--test", help="explain one test: dump every feature of every "
                                   "one of its failing comparisons, then exit")
    ap.add_argument("--from-json", help="reuse a previous --out instead of "
                                        "recomputing the features")
    ap.add_argument("--limit", type=int, help="debug: only the first N comparisons")
    args = ap.parse_args()

    swfs_root = Path(args.swfs_dir).resolve()
    docs_root = Path(args.docs_dir).resolve() if args.docs_dir else swfs_root
    disp = Dispositions(docs_root, docs_root.parent.parent)

    all_rows, reports = load_rows(swfs_root, args.stem)
    failing = [r for r in all_rows if r["status"] == "fail"]
    meta = {
        "reports": reports,
        "git_sha": (failing or all_rows)[0].get("_git_sha"),
        "timestamp": (failing or all_rows)[0].get("_timestamp"),
        "incomplete": any(r.get("_incomplete") for r in all_rows),
    }

    if args.from_json:
        rows = json.loads(Path(args.from_json).read_text())
    else:
        images_root = resolve_images_dir(args.images_dir)
        sel = failing
        if args.test:
            sel = [r for r in failing
                   if f"{r['suite']}/{r['test']}" == args.test
                   or r["test"] == args.test
                   or r["test"].split("/")[-1] == args.test]
        if args.limit:
            sel = sel[:args.limit]
        print(f"{len(sel)} failing comparisons; actual PNGs from {images_root}",
              file=sys.stderr)
        rows = extract(sel, images_root, swfs_root, args.jobs,
                       progress=not (args.test or args.cluster))

    if args.test:
        emit_explain(rows, args.test)
        return 0

    annotate(rows, disp)

    if args.cluster:
        members = [r for r in rows if r["cluster"] == args.cluster]
        if not members:
            sys.exit(f"no comparison in cluster {args.cluster!r}; have: "
                     + ", ".join(sorted({r['cluster'] for r in rows})))
        members.sort(key=lambda r: (r.get("excess_outliers") or 0))
        print(f"== {args.cluster}: {len(members)} comparisons ==")
        for r in members:
            d = (f"  <- {r['dispositioned'] or r['soft_disposition']}"
                 if (r["dispositioned"] or r["soft_disposition"]) else "")
            print(f"{(r.get('excess_outliers') or 0):>9}  "
                  f"{band_short(r['band']):10} "
                  f"{r['suite']}/{r['test']} [{r['comparison']}]  {r['why']}{d}")
        return 0

    live = live_rows(rows)
    board = group_board(live)
    phase = frame_phase_suspects(rows)
    failing_keys = {(r["suite"], r["test"], r["comparison"]) for r in rows}
    stale = stale_dispositions(all_rows, failing_keys, disp)

    emit_text(rows, board, live, args, meta, phase, stale)

    if args.out:
        Path(args.out).write_text(json.dumps(rows, indent=1))
        print(f"\nwrote {args.out}", file=sys.stderr)
    if args.markdown:
        emit_markdown(rows, board, live, args, meta, phase, stale, args.markdown)
        print(f"wrote {args.markdown}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main() or 0)
