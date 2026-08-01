#!/usr/bin/env python3
"""Build the per-suite image-comparison report from a run's trace results.

The image verdicts already ride inside each suite's `results_<stem>.json`, one
`image_comparisons` block per test entry (verify_output.py records them there;
they never gate the trace pass/fail — see the
`image-comparisons-dont-gate-passfail` note). This script lifts them out into a
dedicated, flat instrument:

    ruffle-tests/tests/swfs/<suite>/_results/image_results_<stem>.json

and — with --index-dir — an index for the `ruffle-image-results` branch.

The reconciliation step is the point. A test that carries `[image_comparisons]`
in its test.toml but crashed, timed out, or never ran produces NO image record
at all (verify_output bails before the comparison block). Reading only the
results JSON would silently under-count the corpus. So the census comes from
test.toml, and every censused comparison with no record is emitted as an
explicit `skip` with a reason rather than being absent.

Usage:
    python3 scripts/build_image_report.py --stem=results_graphics
    python3 scripts/build_image_report.py --stem=results_graphics \
        --index-dir=/tmp/imgbranch --png-dir=/tmp/imgbranch/images
"""

import argparse
import json
import os
import sys
from collections import Counter, defaultdict
from datetime import datetime, timezone
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent
SWFS_ROOT = PROJECT_ROOT / "ruffle-tests" / "tests" / "swfs"

sys.path.insert(0, str(PROJECT_ROOT / "ruffle-tests"))
from verify_output import parse_image_comparisons  # noqa: E402

# Suite directories that carry their own _results/. Mirrors the *_DIR env vars
# in .github/workflows/ruffle-tests.yml. Nested entries (from_shumway/avm1,
# from_gnash/*) are listed explicitly because their parents are suites too.
SUITES = [
    "avm1", "avm2", "from_avmplus",
    "timeline", "text", "swf", "import_assets", "audio", "fonts", "visual",
    "mixed_avm", "stage3d", "regression",
    "from_shumway", "from_shumway/avm1",
    "from_gnash/misc-swfmill.all", "from_gnash/actionscript.all",
    "from_gnash/misc-mtasc.all", "from_gnash/misc-ming.all",
    "from_gnash/misc-swfc.all",
]

# Suites whose test tree is physically INSIDE another suite's tree. The parent
# suite's own run walks recursively, so it already grades these tests (as
# `avm1/text-bind` etc.) and the nested suite's results are a duplicate view of
# the same comparisons, not additional ones. They keep their own _results dir
# because the workflow gives them their own shard tag — but a corpus roll-up
# that sums both double-counts them. Same trap as the 4414-vs-4463 trace
# denominator. image_baseline_report.py excludes these from its totals; the
# census here deliberately does NOT skip them, so the parent's rows carry full
# stats instead of landing in the un-binnable "uncensused" path.
NESTED_SUITES = {"from_shumway/avm1"}

SKIP_DIRS = {"_investigation", "_results", "_image-test-output", "__pycache__",
             "__framework__"}


def census_suite(suite):
    """{test_name: {cmp_name: config}} for every test.toml under `suite`."""
    root = SWFS_ROOT / suite
    if not root.is_dir():
        return {}
    out = {}
    for toml in root.rglob("test.toml"):
        d = toml.parent
        if any(part in SKIP_DIRS or part.startswith("_") for part in
               d.relative_to(root).parts):
            continue
        cmps = parse_image_comparisons(d)
        if cmps:
            out[d.relative_to(root).as_posix()] = cmps
    return out


def run_provenance():
    """CI run identity, for the `metadata` block. Empty when run locally.

    Sourced from the automatic GitHub Actions environment (`GITHUB_RUN_ID` and
    friends are set in EVERY step, so no workflow edit is needed), falling back
    to the explicit `RUN_URL` the images steps already export. These JSONs only
    change when an `images=true` run merges, so "which run produced this" is the
    first question any later diff asks — see scripts/image_status_diff.py.
    """
    run_id = os.environ.get("GITHUB_RUN_ID")
    server = os.environ.get("GITHUB_SERVER_URL", "https://github.com")
    repo = os.environ.get("GITHUB_REPOSITORY")
    url = os.environ.get("RUN_URL")
    if not url and run_id and repo:
        url = f"{server}/{repo}/actions/runs/{run_id}"
    out = {}
    if run_id:
        out["run_id"] = run_id
    if url:
        out["run_url"] = url
    if os.environ.get("GITHUB_RUN_ATTEMPT"):
        out["run_attempt"] = os.environ["GITHUB_RUN_ATTEMPT"]
    return out


def classify_absence(trace_status):
    """Why a censused comparison produced no record."""
    if trace_status is None:
        return "test_not_run"
    if trace_status in ("segfault", "timeout", "runtime_error"):
        return f"test_{trace_status}"
    if trace_status in ("compile_fail", "recomp_fail"):
        return f"test_{trace_status}"
    # Trace ran to completion but no image verdict landed: either Pillow was
    # missing (silent degradation — what --images now refuses to do) or the
    # run was not in graphics mode.
    return "no_image_verdict"


def build_suite(suite, stem):
    results_path = SWFS_ROOT / suite / "_results" / f"{stem}.json"
    if not results_path.exists():
        return None
    data = json.loads(results_path.read_text())
    by_test = {t["test"]: t for t in data.get("tests", [])}

    census = census_suite(suite)
    rows = []
    seen = set()

    for test, cmps in sorted(census.items()):
        entry = by_test.get(test)
        trace_status = entry.get("status") if entry else None
        recorded = (entry or {}).get("image_comparisons") or {}
        for cmp_name in sorted(cmps):
            seen.add((test, cmp_name))
            r = recorded.get(cmp_name)
            row = {
                "suite": suite,
                "test": test,
                "comparison": cmp_name,
                "trace_status": trace_status,
                "known_failure": bool(cmps[cmp_name].get("known_failure")),
            }
            if r is None:
                row.update(status="skip", reason=classify_absence(trace_status),
                           message="no image comparison recorded for this run")
            else:
                row["status"] = r.get("status", "unknown")
                row["message"] = r.get("message", "")
                if "reason" in r:
                    row["reason"] = r["reason"]
                elif row["status"] == "fail":
                    row["reason"] = "pixel_mismatch"
                elif row["status"] == "skip":
                    # Records written before verify_output carried a machine-
                    # readable reason (anything published pre-2026-07-30).
                    row["reason"] = ("no_expected_image"
                                     if "No expected image" in r.get("message", "")
                                     else "unknown")
                if r.get("known_failure"):
                    row["known_failure"] = True
                if "max_diff" in r:
                    row["max_diff"] = r["max_diff"]
                if r.get("expected_source"):
                    row["expected_source"] = r["expected_source"]
                for k, v in (r.get("stats") or {}).items():
                    if k != "max_diff":
                        row[k] = v
            rows.append(row)

    # Anything recorded but not censused (a test.toml that changed between the
    # run and now, or a TOML 1.1 parse failure in the census). Keep it rather
    # than drop it, flagged so the count discrepancy is visible.
    for test, entry in by_test.items():
        for cmp_name, r in (entry.get("image_comparisons") or {}).items():
            if (test, cmp_name) in seen:
                continue
            rows.append({
                "suite": suite, "test": test, "comparison": cmp_name,
                "trace_status": entry.get("status"),
                "status": r.get("status", "unknown"),
                "message": r.get("message", ""),
                "max_diff": r.get("max_diff"),
                "known_failure": bool(r.get("known_failure")),
                "reason": r.get("reason", "not_in_census"),
                "uncensused": True,
            })

    totals = Counter()
    for row in rows:
        totals[row["status"]] += 1
        if row["status"] == "fail" and row.get("reason") == "no_render":
            totals["no_render"] += 1
        if row["status"] == "fail" and row.get("known_failure"):
            totals["fail_known_failure"] += 1

    return {
        "metadata": {
            "timestamp": datetime.now(timezone.utc).isoformat(),
            "suite": suite,
            "stem": stem,
            "git_sha": data.get("metadata", {}).get("git_sha"),
            "source": f"{stem}.json",
            "incomplete": data.get("metadata", {}).get("incomplete", False),
            # Which CI run produced this file. Without it a stale side can be
            # named by SHA but not linked, and these JSONs only change when an
            # `images=true` run merges — so the run is the thing you actually
            # want to open. scripts/image_status_diff.py prints them.
            **run_provenance(),
        },
        "tests_with_comparisons": len(census),
        "comparisons": len(rows),
        "pass": totals["pass"],
        "fail": totals["fail"],
        "skip": totals["skip"],
        "no_render": totals["no_render"],
        "fail_known_failure": totals["fail_known_failure"],
        "pass_rate": (round(100 * totals["pass"] / len(rows), 1) if rows else 0),
        "results": rows,
    }


def near_miss_band(row):
    """Coarse magnitude bucket for a failing comparison.

    Binned on `excess_outliers` — channels past the test's OWN budget — not on
    raw difference, because every tolerance here was recorded against real
    Flash output and differs per test. A test allowed 50k outliers that hits
    50,001 is a near-miss; one allowed 0 that hits 300k is not.
    """
    if row.get("reason") == "no_render":
        return "no_render"
    if row.get("reason") == "size_mismatch":
        return "size_mismatch"
    excess = row.get("excess_outliers")
    total = row.get("total_channels")
    if excess is None or not total:
        return "unknown"
    frac = excess / total
    if excess <= 100:
        return "a_epsilon (<=100 channels over)"
    if frac < 0.001:
        return "b_tiny (<0.1% of channels)"
    if frac < 0.01:
        return "c_small (0.1-1%)"
    if frac < 0.10:
        return "d_moderate (1-10%)"
    if frac < 0.50:
        return "e_large (10-50%)"
    return "f_catastrophic (>=50%)"


def write_index(all_suites, index_dir, png_dir):
    index_dir = Path(index_dir)
    index_dir.mkdir(parents=True, exist_ok=True)
    png_root = Path(png_dir) if png_dir else None

    fails = []
    for rep in all_suites:
        for row in rep["results"]:
            if row["status"] != "fail":
                continue
            files = []
            if png_root:
                d = png_root / row["suite"] / row["test"]
                for kind in ("actual", "difference"):
                    p = d / f"{row['comparison']}.{kind}.png"
                    if p.exists():
                        files.append(p.relative_to(Path(index_dir)).as_posix()
                                     if str(p).startswith(str(index_dir))
                                     else p.as_posix())
            row = dict(row, files=files, band=near_miss_band(row))
            fails.append(row)

    fails.sort(key=lambda r: (-(r.get("excess_outliers") or 0), r["suite"], r["test"]))

    totals = Counter()
    per_suite = defaultdict(Counter)
    for rep in all_suites:
        for k in ("comparisons", "pass", "fail", "skip", "no_render"):
            totals[k] += rep[k]
            per_suite[rep["metadata"]["suite"]][k] += rep[k]
    bands = Counter(r["band"] for r in fails)

    (index_dir / "index.json").write_text(json.dumps({
        "generated": datetime.now(timezone.utc).isoformat(),
        "totals": dict(totals),
        "per_suite": {k: dict(v) for k, v in sorted(per_suite.items())},
        "bands": dict(sorted(bands.items())),
        "failures": fails,
    }, indent=2))

    L = []
    L.append("# Ruffle image-comparison failures")
    L.append("")
    L.append(f"Generated: {datetime.now(timezone.utc).isoformat()}  ")
    L.append(f"Run: {os.environ.get('RUN_URL', '(local)')}  ")
    L.append(f"Commit: `{os.environ.get('GITHUB_SHA', '(local)')[:12]}`")
    L.append("")
    L.append("Only FAILING comparisons are published here. Passing renders are "
             "not saved. Each run force-pushes a single commit — this branch "
             "has no history by design.")
    L.append("")
    L.append(f"**{totals['fail']} failing** of {totals['comparisons']} "
             f"comparisons ({totals['pass']} pass, {totals['skip']} skip, "
             f"{totals['no_render']} produced no render).")
    L.append("")
    L.append("## Magnitude bands")
    L.append("")
    L.append("| band | failures |")
    L.append("|---|---:|")
    for b, n in sorted(bands.items()):
        L.append(f"| {b} | {n} |")
    L.append("")
    L.append("## Failures")
    L.append("")
    L.append("| suite | test | cmp | outliers / budget | excess | max_diff | band | files |")
    L.append("|---|---|---|---:|---:|---:|---|---|")
    for r in fails:
        o = r.get("outliers")
        b = r.get("max_outliers")
        budget = f"{o} / {b}" if o is not None else "—"
        links = " ".join(f"[{Path(f).stem.split('.')[-1]}]({f})" for f in r["files"]) or "—"
        L.append(f"| {r['suite']} | {r['test']} | {r['comparison']} | {budget} | "
                 f"{r.get('excess_outliers', '—')} | {r.get('max_diff', '—')} | "
                 f"{r['band']} | {links} |")
    L.append("")
    (index_dir / "index.md").write_text("\n".join(L) + "\n")
    print(f"Wrote index for {len(fails)} failing comparisons to {index_dir}")


def audit_expectations():
    """Is every censused comparison's expected PNG present IN-REPO?

    verify_output.py falls back to a local upstream Ruffle checkout
    (~/CC/ruffle) for a missing `<cmp>.expected.png`. That path does not exist
    on CI, so a comparison resolving only through it grades locally and skips
    in CI — a silent hole in the baseline. This audit is deliberately blind to
    the fallback: it checks the test directory and nothing else, which is
    exactly what CI sees.

    Returns the list of (suite, test, cmp) with no in-repo expected image.
    """
    missing = []
    total = 0
    for suite in SUITES:
        for test, cmps in sorted(census_suite(suite).items()):
            for cmp_name in sorted(cmps):
                total += 1
                if not (SWFS_ROOT / suite / test / f"{cmp_name}.expected.png").exists():
                    missing.append((suite, test, cmp_name))
    print(f"[audit] {total - len(missing)}/{total} comparisons have an in-repo "
          f"expected PNG")
    if missing:
        print(f"::warning::{len(missing)} image comparison(s) have no in-repo "
              f"expected PNG and will be recorded as skip/no_expected_image:")
        for suite, test, cmp_name in missing:
            print(f"  {suite}/{test} [{cmp_name}]")
    return missing


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--audit", action="store_true",
                    help="Only audit in-repo expected-PNG coverage, then exit")
    ap.add_argument("--stem", default="results_graphics",
                    help="Trace results stem to lift image verdicts out of")
    ap.add_argument("--index-dir", help="Write index.md/index.json here (images branch root)")
    ap.add_argument("--png-dir", help="Collected failing PNGs, for the index's file links")
    ap.add_argument("--no-write-per-suite", action="store_true",
                    help="Skip writing _results/image_results_<stem>.json")
    ap.add_argument("--suites-file",
                    help="Restrict to the suites listed one-per-line in this file. "
                         "CI passes the list the combine step actually wrote this "
                         "run, so a categories=avm1 dispatch does not rebuild "
                         "other suites' image results from a stale checkout.")
    args = ap.parse_args()

    suites = SUITES
    if args.suites_file:
        path = Path(args.suites_file)
        if not path.exists():
            print(f"::error::--suites-file {path} not found; refusing to fall "
                  f"back to every suite (that would republish image results "
                  f"derived from a stale checkout).", file=sys.stderr)
            return 1
        wanted = {ln.strip() for ln in path.read_text().splitlines() if ln.strip()}
        suites = [s for s in SUITES if s in wanted]
        unknown = wanted - set(SUITES)
        if unknown:
            print(f"::warning::--suites-file lists unknown suites: {sorted(unknown)}")
        print(f"Restricted to {len(suites)} suite(s) written by this run.")

    if args.audit:
        audit_expectations()
        return

    out_stem ="image_results_graphics" if args.stem == "results_graphics" \
        else f"image_{args.stem}"

    reports = []
    for suite in suites:
        rep = build_suite(suite, args.stem)
        if rep is None:
            continue
        if rep["comparisons"] == 0:
            continue
        reports.append(rep)
        if not args.no_write_per_suite:
            out = SWFS_ROOT / suite / "_results" / f"{out_stem}.json"
            out.parent.mkdir(parents=True, exist_ok=True)
            out.write_text(json.dumps(rep, indent=2))
        print(f"{suite}: {rep['pass']}/{rep['comparisons']} image comparisons pass "
              f"({rep['fail']} fail, {rep['skip']} skip, {rep['no_render']} no-render)")

    tot = Counter()
    for rep in reports:
        for k in ("comparisons", "pass", "fail", "skip", "no_render"):
            tot[k] += rep[k]
    print(f"TOTAL: {tot['pass']}/{tot['comparisons']} pass, {tot['fail']} fail, "
          f"{tot['skip']} skip, {tot['no_render']} no-render")

    if args.index_dir:
        write_index(reports, args.index_dir, args.png_dir)
    return 0


if __name__ == "__main__":
    sys.exit(main() or 0)
