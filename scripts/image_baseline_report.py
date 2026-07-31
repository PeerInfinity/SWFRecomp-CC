#!/usr/bin/env python3
"""Summarise the corpus-wide image baseline from the per-suite image results.

Reads every `_results/image_results_<stem>.json` that `build_image_report.py`
wrote and emits the markdown body of
`SWFRecompDocs/plans/graphics-image-baseline.md`: corpus + per-suite counts, an
outlier-magnitude histogram, and the top failure families.

    python3 scripts/image_baseline_report.py > /tmp/body.md
"""

import argparse
import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent
SWFS_ROOT = PROJECT_ROOT / "ruffle-tests" / "tests" / "swfs"

sys.path.insert(0, str(PROJECT_ROOT / "scripts"))
from build_image_report import near_miss_band, NESTED_SUITES  # noqa: E402

# Feature families, matched against "<suite>/<test>" lowercased, first hit
# wins. Ordered most-specific first: `bitmapfilter` must beat `bitmap`, and
# `netstream`/`video` must beat nothing else. A family is a hypothesis about
# which subsystem owns a cluster, not a verdict — the point is to make the
# clusters visible, not to assign blame.
FAMILIES = [
    ("Stage3D / AGAL / shaders", r"stage3d|agal|shader|pixelbender|pbj"),
    ("Video / NetStream", r"netstream|video|flv|h264|vp6"),
    ("Filters (blur/glow/drop-shadow/…)", r"filter|blur|glow|bevel|dropshadow|convolution|displacement"),
    ("Blend modes", r"blend"),
    ("Gradients", r"gradient|ramp"),
    ("Morph shapes / tweens", r"morph|tween"),
    ("Masks / clipping", r"\bmask|clip_depth|scrollrect|scroll_rect"),
    ("Text: embedded fonts / glyphs", r"font|glyph|devicetext|embedded"),
    ("Focus highlight / focus rect", r"focusrect|focus_highlight|focusrect"),
    ("Shumway acid render tests", r"^from_shumway/acid"),
    ("Buttons", r"button"),
    ("Text: EditText / layout / HTML",
     r"edittext|textfield|htmltext|stylesheet|textformat|auto_?size|wordwrap"
     r"|hardwrap|\btext\b|text-|caption|vertical_align|br_at_start"),
    ("BitmapData / drawing API", r"bitmap|draw|copypixels|floodfill|perlin|noise|threshold"),
    ("Strokes / line styles", r"line_?style|stroke|caps|joint|miter|hairline"),
    ("Shapes / fills / tessellation", r"shape|fill|tessel|curve|polygon|winding"),
    ("Scale-9 / transforms / matrices", r"scale9|scalegrid|matrix|transform|rotation|skew"),
    ("Color transforms", r"colortransform|color_transform|\bcolor\b|tint"),
    ("Display list / depth / visibility", r"depth|visible|removechild|addchild|displaylist|zsort"),
    ("Timeline / frames", r"frame|timeline|goto|play|stop"),
    ("Loader / external assets", r"loader|load_|import|jpeg|png|gif|swf_"),
]


def family_of(suite, test):
    key = f"{suite}/{test}".lower()
    for name, pat in FAMILIES:
        if re.search(pat, key):
            return name
    return "(unclassified)"


def load(stem):
    """Every per-suite image report EXCEPT the nested duplicates.

    `from_shumway/avm1` lives inside `from_shumway`, whose own run walks
    recursively and already graded those tests. Summing both double-counts
    them — the pixel-side version of the 4414-vs-4463 corpus denominator.
    """
    reports = []
    for p in sorted(SWFS_ROOT.rglob(f"_results/image_results_{stem}.json")):
        rep = json.loads(p.read_text())
        if rep["metadata"]["suite"] in NESTED_SUITES:
            print(f"skipping nested duplicate suite {rep['metadata']['suite']} "
                  f"({rep['comparisons']} comparisons already counted under its "
                  f"parent)", file=sys.stderr)
            continue
        reports.append(rep)
    return reports


def bar(n, total, width=28):
    if not total:
        return ""
    return "#" * max(1, round(width * n / total)) if n else ""


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--stem", default="graphics")
    args = ap.parse_args()

    reports = load(args.stem)
    if not reports:
        print(f"No image_results_{args.stem}.json found under {SWFS_ROOT}",
              file=sys.stderr)
        return 1

    rows = []
    for rep in reports:
        rows.extend(rep["results"])

    tot = Counter(r["status"] for r in rows)
    fails = [r for r in rows if r["status"] == "fail"]
    skips = [r for r in rows if r["status"] == "skip"]

    out = []
    A = out.append

    A("## Corpus-wide totals")
    A("")
    A(f"| metric | count | share |")
    A("|---|---:|---:|")
    n = len(rows)
    for label, k in (("comparisons", None), ("pass", "pass"),
                     ("fail", "fail"), ("skip", "skip")):
        c = n if k is None else tot[k]
        A(f"| {label} | {c} | {100*c/n:.1f}% |")
    nr = sum(1 for r in fails if r.get("reason") == "no_render")
    A(f"| — of which produced no render at all | {nr} | {100*nr/n:.1f}% |")
    kf = sum(1 for r in fails if r.get("known_failure"))
    A(f"| — failures Ruffle itself marks known_failure | {kf} | {100*kf/n:.1f}% |")
    A("")
    tests = {(r["suite"], r["test"]) for r in rows}
    ftests = {(r["suite"], r["test"]) for r in fails}
    A(f"{len(tests)} tests carry `[image_comparisons]`; {len(ftests)} have at "
      f"least one failing comparison.")
    A("")

    A("## Per suite")
    A("")
    A("| suite | comparisons | pass | fail | skip | no_render | pass rate |")
    A("|---|---:|---:|---:|---:|---:|---:|")
    for rep in sorted(reports, key=lambda r: -r["comparisons"]):
        A(f"| `{rep['metadata']['suite']}` | {rep['comparisons']} | {rep['pass']} "
          f"| {rep['fail']} | {rep['skip']} | {rep['no_render']} | "
          f"{rep['pass_rate']}% |")
    A(f"| **total** | **{n}** | **{tot['pass']}** | **{tot['fail']}** | "
      f"**{tot['skip']}** | **{nr}** | **{100*tot['pass']/n:.1f}%** |")
    A("")

    A("## Outlier-magnitude histogram")
    A("")
    A("Failures binned by `excess_outliers` — channels past the test's OWN "
      "`max_outliers` budget — as a fraction of the image's total channels "
      "(width x height x 4). Binning on excess rather than raw difference is "
      "what makes the bands comparable across tests: every tolerance in the "
      "corpus was recorded against real Flash output and they differ wildly.")
    A("")
    bands = Counter(near_miss_band(r) for r in fails)
    A("| band | failures | share of failures | |")
    A("|---|---:|---:|---|")
    for b in sorted(bands):
        c = bands[b]
        A(f"| {b} | {c} | {100*c/len(fails):.1f}% | `{bar(c, len(fails))}` |")
    A("")

    md = Counter()
    for r in fails:
        d = r.get("max_diff")
        if d is None:
            md["unknown"] += 1
        elif d == 0:
            md["0"] += 1
        elif d <= 2:
            md["1-2"] += 1
        elif d <= 8:
            md["3-8"] += 1
        elif d <= 32:
            md["9-32"] += 1
        elif d <= 128:
            md["33-128"] += 1
        else:
            md["129-255"] += 1
    A("Peak single-channel difference on the same failures (an orthogonal "
      "axis: a huge count of 1-LSB drifts and a handful of totally wrong "
      "pixels both fail, and they mean very different things):")
    A("")
    A("| max_diff | failures |")
    A("|---|---:|")
    for k in ("0", "1-2", "3-8", "9-32", "33-128", "129-255", "unknown"):
        if md[k]:
            A(f"| {k} | {md[k]} |")
    A("")

    A("## Failure families")
    A("")
    fam = Counter(family_of(r["suite"], r["test"]) for r in fails)
    famband = defaultdict(Counter)
    for r in fails:
        famband[family_of(r["suite"], r["test"])][near_miss_band(r)] += 1
    A("Clustered by test-name/feature keyword. A family is a hypothesis about "
      "which subsystem owns the cluster, not a diagnosis.")
    A("")
    A("| family | failures | near-miss (<=100 channels over) | catastrophic (>=50%) |")
    A("|---|---:|---:|---:|")
    for name, c in fam.most_common():
        nm = famband[name]["a_epsilon (<=100 channels over)"]
        cat = famband[name]["f_catastrophic (>=50%)"]
        A(f"| {name} | {c} | {nm} | {cat} |")
    A("")

    A("### Largest single failures")
    A("")
    A("| suite | test | cmp | outliers / budget | max_diff | band |")
    A("|---|---|---|---:|---:|---|")
    for r in sorted(fails, key=lambda r: -(r.get("excess_outliers") or 0))[:25]:
        A(f"| `{r['suite']}` | {r['test']} | {r['comparison']} | "
          f"{r.get('outliers','—')} / {r.get('max_outliers','—')} | "
          f"{r.get('max_diff','—')} | {near_miss_band(r)} |")
    A("")

    A("### Closest misses")
    A("")
    A("| suite | test | cmp | outliers / budget | max_diff |")
    A("|---|---|---|---:|---:|")
    near = [r for r in fails if r.get("excess_outliers") is not None]
    for r in sorted(near, key=lambda r: r["excess_outliers"])[:25]:
        A(f"| `{r['suite']}` | {r['test']} | {r['comparison']} | "
          f"{r.get('outliers')} / {r.get('max_outliers')} | {r.get('max_diff','—')} |")
    A("")

    if skips:
        A("## Skips")
        A("")
        A("| reason | count |")
        A("|---|---:|")
        for reason, c in Counter(r.get("reason", "unknown") for r in skips).most_common():
            A(f"| `{reason}` | {c} |")
        A("")
        A("| suite | test | cmp | reason | trace status |")
        A("|---|---|---|---|---|")
        for r in sorted(skips, key=lambda r: (r["suite"], r["test"])):
            A(f"| `{r['suite']}` | {r['test']} | {r['comparison']} | "
              f"`{r.get('reason','unknown')}` | {r.get('trace_status')} |")
        A("")

    src = Counter(r.get("expected_source", "unrecorded") for r in rows)
    A("## Expected-image provenance")
    A("")
    A("| source | comparisons |")
    A("|---|---:|")
    for k, c in src.most_common():
        A(f"| `{k}` | {c} |")
    A("")
    A("`upstream_checkout` means the expected PNG resolved only through the "
      "local `~/CC/ruffle` fallback, which does not exist on CI. Any nonzero "
      "count there is a hole in the CI baseline.")
    A("")

    print("\n".join(out))
    return 0


if __name__ == "__main__":
    sys.exit(main())
