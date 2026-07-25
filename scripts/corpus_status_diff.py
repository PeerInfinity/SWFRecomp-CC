#!/usr/bin/env python3
"""Corpus-wide CI result diff: status histogram, on the intersection.

`scripts/diff_ruffle_results.py` compares two results JSON files for one
suite. This compares the WHOLE corpus between two git refs, and exists
because three separate mistakes have each been made at least once when
reading a CI run by hand:

1. **Transition-only diffing hides new crashes.** A test that was already
   failing and starts segfaulting crosses no pass/fail line, so a
   transitions-only report calls it "zero regressions". One change
   introduced 12 new segfaults that way. This prints the full status
   histogram and flags any rise in segfault/timeout/runtime_error/
   compile_fail.

2. **Shard recovery is not yield.** When one endpoint lost a shard to the
   apt/Vulkan flake, its tests are *absent*, not failing — and reappear in
   the other run looking like wins. Once inflated a true +101 to ~238. All
   comparisons here are over `set(old) & set(new)`; keys missing from the
   baseline are reported separately as ungraded.

3. **The corpus denominator is 4414, not 4463.** Three nested `_results`
   dirs live inside their parents and would be counted twice. They are
   excluded below.

Usage:
    scripts/corpus_status_diff.py <old_ref> <new_ref> [--stem results_graphics]

`<new_ref>` may be the literal WORKTREE to read the working tree instead of
a commit — the normal case right after merging `ruffle-test-results`.

    scripts/corpus_status_diff.py 14b57c476 WORKTREE
"""

import argparse
import collections
import json
import pathlib
import subprocess
import sys

# Nested result dirs already contained in a parent suite's results file.
# Counting these again is what produced the wrong 4463 corpus total.
NESTED = {
    "from_shumway/avm1",
    "from_shumway/timeline",
    "from_gnash/misc-ming.all/displaylist_depths",
}

CRASH_STATUSES = ("segfault", "timeout", "runtime_error", "compile_fail")
EFFECTIVE = ("pass", "ruffle_matched")

REPO = pathlib.Path(__file__).resolve().parent.parent


def git(*args):
    return subprocess.run(["git", *args], cwd=REPO,
                          capture_output=True, text=True).stdout


def result_paths(ref, stem):
    listing = git("ls-tree", "-r", "--name-only",
                  "HEAD" if ref == "WORKTREE" else ref)
    return [p for p in listing.splitlines()
            if p.endswith(f"_results/{stem}.json")]


def load(ref, path):
    if ref == "WORKTREE":
        return json.loads((REPO / path).read_text())
    blob = git("show", f"{ref}:{path}")
    return json.loads(blob) if blob.strip() else {"tests": []}


def suite_of(path):
    return path.split("/_results/")[0].replace("ruffle-tests/tests/swfs/", "")


def is_effective(entry):
    return entry["status"] in EFFECTIVE


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("old_ref")
    ap.add_argument("new_ref", help="git ref, or WORKTREE for the working tree")
    ap.add_argument("--stem", default="results_graphics",
                    help="results file stem (graphics -> results_graphics, "
                         "no-graphics -> results); default: results_graphics")
    ap.add_argument("--per-suite", action="store_true",
                    help="also print a per-suite effective-pass table")
    args = ap.parse_args()

    paths = sorted(set(result_paths(args.old_ref, args.stem))
                   | set(result_paths(args.new_ref, args.stem)))
    if not paths:
        sys.exit(f"no */_results/{args.stem}.json found at either ref")

    hist_old, hist_new = collections.Counter(), collections.Counter()
    regressions, gains, moves, ungraded, per_suite = [], [], [], [], []
    flagged = []
    total = 0

    for path in paths:
        suite = suite_of(path)
        if suite in NESTED:
            continue
        old_doc = load(args.old_ref, path)
        new_doc = load(args.new_ref, path)
        # The workflow labels a short run in metadata (and fails the job).
        # Trust that over inference: it names the shard count, which absence
        # alone cannot.
        for ref, doc in ((args.old_ref, old_doc), (args.new_ref, new_doc)):
            meta = doc.get("metadata") or {}
            if meta.get("incomplete"):
                flagged.append(
                    f"{suite} @ {ref}: {meta.get('shards', '?')}/"
                    f"{meta.get('expected_shards', '?')} shards"
                    + (f", {meta['interrupted_shards']} interrupted"
                       if meta.get("interrupted_shards") else ""))
        old = {t["test"]: t for t in old_doc.get("tests", [])}
        new = {t["test"]: t for t in new_doc.get("tests", [])}
        shared = old.keys() & new.keys()
        if old.keys() - new.keys():
            ungraded.append((suite, len(old.keys() - new.keys())))

        a = b = 0
        for name in sorted(shared):
            o, n = old[name], new[name]
            hist_old[o["status"]] += 1
            hist_new[n["status"]] += 1
            a += is_effective(o)
            b += is_effective(n)
            if is_effective(o) and not is_effective(n):
                regressions.append(f"{suite}/{name}: {o['status']} -> {n['status']}")
            elif not is_effective(o) and is_effective(n):
                gains.append(f"{suite}/{name}")
            elif o["status"] != n["status"]:
                moves.append(f"{suite}/{name}: {o['status']} -> {n['status']}")
        total += len(shared)
        if a != b:
            per_suite.append((suite, a, b))

    print(f"=== intersection: {total} tests "
          f"({args.old_ref} -> {args.new_ref}, {args.stem}) ===\n")
    if flagged:
        print("!! INCOMPLETE RUN — metadata.incomplete is set on:")
        for item in flagged:
            print(f"     {item}")
        print("   Comparisons below are on the intersection and are still "
              "valid,\n   but any absolute total from the flagged side is "
              "short. Say so\n   when reporting, and name the ungraded "
              "tests.\n")
    print("STATUS HISTOGRAM")
    for status in sorted(set(hist_old) | set(hist_new)):
        delta = hist_new[status] - hist_old[status]
        flag = "   <-- REGRESSION TO CHASE" if (
            status in CRASH_STATUSES and delta > 0) else ""
        print(f"  {status:16} {hist_old[status]:5} -> {hist_new[status]:5} "
              f"({delta:+d}){flag}")

    eff_old = sum(hist_old[s] for s in EFFECTIVE)
    eff_new = sum(hist_new[s] for s in EFFECTIVE)
    print(f"\n  {'effective':16} {eff_old:5} -> {eff_new:5} ({eff_new - eff_old:+d})")

    if args.per_suite and per_suite:
        print("\nPER-SUITE (only suites that moved)")
        for suite, a, b in per_suite:
            print(f"  {suite:34} {a:5} -> {b:5} ({b - a:+d})")

    print(f"\nGAINS (fail -> effective): {len(gains)}")
    print(f"REGRESSIONS (effective -> fail): {len(regressions)}")
    for r in regressions:
        print("  " + r)
    print(f"\nOTHER STATUS MOVES (failing on both sides): {len(moves)}")
    for m in moves[:40]:
        print("  " + m)
    if len(moves) > 40:
        print(f"  ... and {len(moves) - 40} more")

    if ungraded:
        print("\nUNGRADED — present in the baseline, absent now (lost shard?):")
        for suite, count in ungraded:
            print(f"  {suite}: {count}")
        print("  These are NOT regressions. If the *new* run is the short one,"
              "\n  say so when reporting: those tests went ungraded.")

    return 1 if regressions else 0


if __name__ == "__main__":
    sys.exit(main())
