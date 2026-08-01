#!/usr/bin/env python3
"""Image-comparison result diff: status + band histograms, on the intersection.

The pixel-side analog of `scripts/corpus_status_diff.py`. Same argument shape,
same intersection-only discipline, same "print the whole histogram, not just the
transitions" rule, same exit-code convention. Three things make it a separate
script rather than a mode of the trace tool:

1. **The key is `(suite, test, comparison)`, not `test`.** One test carries many
   comparisons (`avm2/focusrect` alone has 12, six failing and six passing), so a
   test-level diff hides exactly the moves this tool exists to show.

2. **Most movement crosses no pass/fail line.** A comparison going from
   `c_small` to `f_catastrophic` is a real regression that a transitions-only
   report calls "zero regressions". `BAND MOVES` is the pixel analog of the trace
   tool's `OTHER STATUS MOVES`, and it is the common case, not the tail.

3. **The provenance trap is unique to images.** The per-suite image JSONs only
   change when an `images=true` run is merged, and `images=false` is the
   per-change default — so on master these files sit unchanged across dozens of
   commits. `image_status_diff.py A B` for two ordinary commits will happily
   compare a file to *itself* and print a clean zero-delta report that reads like
   "no regressions". The PROVENANCE banner exists to make that impossible: it
   names the `metadata.git_sha` each side's JSON was actually produced at, warns
   when that is not the ref you asked about, and refuses to diff at all when both
   sides are the same image run.

Bands are `build_image_report.near_miss_band` — imported, never re-derived, so
there is one definition of the magnitude bins. They bin on `excess_outliers`
(channels past the test's OWN budget), never on raw `outliers`: every tolerance
in the corpus was recorded against real Flash output by upstream and they differ
wildly, so only the excess is comparable across tests.

Usage:
    scripts/image_status_diff.py <old_ref> <new_ref> [--stem image_results_graphics]

`<old_ref>`/`<new_ref>` may each be a git ref, a directory holding a tree of
per-suite JSONs (e.g. an extracted CI artifact), or — for the new side — the
literal WORKTREE to read the working tree, which is the normal case right after
merging `ruffle-test-results`.

    scripts/image_status_diff.py d211b6feb WORKTREE
    scripts/image_status_diff.py d211b6feb /tmp/imgrun --per-suite
"""

import argparse
import collections
import json
import os
import pathlib
import subprocess
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "scripts"))
from build_image_report import near_miss_band  # noqa: E402

# Suite dirs physically inside another suite's tree: the parent's own run walks
# recursively and already graded these comparisons, so summing both
# double-counts them. Pixel-side version of the 4414-vs-4463 trace denominator;
# `build_image_report.NESTED_SUITES` names the same set.
NESTED = {"from_shumway/avm1"}

# A rise in any of these skip reasons is a crash the *pixel* verdict cannot see:
# the test never produced a render at all, so no comparison fails — it vanishes
# into `skip`. Same shape as the trace-side transition-diff-hides-new-crashes
# lesson, restated for pixels.
CRASH_SKIP_REASONS = ("test_segfault", "test_timeout", "test_runtime_error",
                      "test_compile_fail", "test_recomp_fail", "test_not_run")

# A rise here means we stopped producing an image at all for a comparison that
# did reach the comparator.
CRASH_FAIL_REASONS = ("no_render",)

MAX_LIST = 40


def git(*args):
    return subprocess.run(["git", *args], cwd=REPO,
                          capture_output=True, text=True).stdout


def git_ok(*args):
    return subprocess.run(["git", *args], cwd=REPO,
                          capture_output=True, text=True).returncode == 0


def is_dir_ref(ref):
    """A side is a directory input iff it names an existing directory.

    Deliberately not a syntactic test: `origin/master` and `HEAD~3` are refs,
    and a ref never happens to also be a directory in this repo's layout.
    """
    return os.path.isdir(ref)


def resolve_sha(ref):
    """Full SHA the ref names, or None for a directory input."""
    if is_dir_ref(ref):
        return None
    out = git("rev-parse", "HEAD" if ref == "WORKTREE" else ref).strip()
    return out or None


def result_paths(ref, stem):
    """Repo-relative paths of every per-suite image JSON at `ref`.

    Directory inputs are keyed the same way, so the two sides intersect on the
    suite regardless of which form each came in as.
    """
    if is_dir_ref(ref):
        root = pathlib.Path(ref)
        return sorted(p.relative_to(root).as_posix()
                      for p in root.rglob(f"_results/{stem}.json"))
    listing = git("ls-tree", "-r", "--name-only",
                  "HEAD" if ref == "WORKTREE" else ref)
    return [p for p in listing.splitlines()
            if p.endswith(f"_results/{stem}.json")]


def load(ref, path):
    if is_dir_ref(ref):
        p = pathlib.Path(ref) / path
        return json.loads(p.read_text()) if p.exists() else None
    if ref == "WORKTREE":
        p = REPO / path
        return json.loads(p.read_text()) if p.exists() else None
    blob = git("show", f"{ref}:{path}")
    return json.loads(blob) if blob.strip() else None


def suite_of(path):
    return path.split("/_results/")[0].replace("ruffle-tests/tests/swfs/", "")


def short_band(band):
    """`a_epsilon (<=100 channels over)` -> `a_epsilon`."""
    return band.split(" ", 1)[0]


def band_of(row):
    if row["status"] != "fail":
        return None
    return near_miss_band(row)


def rows_of(doc, suite):
    return {(suite, r["test"], r["comparison"]): r
            for r in (doc.get("results") or [])}


# --------------------------------------------------------------------------
# provenance
# --------------------------------------------------------------------------

def provenance(side_docs):
    """Collapse each suite's metadata into the distinct runs a side came from."""
    runs = collections.defaultdict(lambda: {"suites": [], "ts": [], "run_id": None,
                                            "run_url": None})
    incomplete = []
    for suite, doc in side_docs:
        meta = doc.get("metadata") or {}
        sha = meta.get("git_sha") or "(no git_sha)"
        rec = runs[sha]
        rec["suites"].append(suite)
        if meta.get("timestamp"):
            rec["ts"].append(meta["timestamp"])
        rec["run_id"] = rec["run_id"] or meta.get("run_id")
        rec["run_url"] = rec["run_url"] or meta.get("run_url")
        if meta.get("incomplete"):
            incomplete.append(f"{suite}: {meta.get('shards', '?')}/"
                              f"{meta.get('expected_shards', '?')} shards")
    return runs, incomplete


def print_side(label, ref, ref_sha, runs):
    short_ref = ref if len(ref) <= 22 else "…" + ref[-21:]
    for i, (sha, rec) in enumerate(sorted(runs.items(),
                                          key=lambda kv: -len(kv[1]["suites"]))):
        head = f"  {label:4} {short_ref:22}" if i == 0 else f"  {'':4} {'':22}"
        ts = min(rec["ts"])[:19] if rec["ts"] else "(no timestamp)"
        run = ""
        if rec["run_id"]:
            run = f"  (run {rec['run_id']})"
        elif rec["run_url"]:
            run = f"  ({rec['run_url']})"
        print(f"{head} json built at {sha[:9]}  {ts}{run}"
              f"   [{len(rec['suites'])} suite(s)]")
        if rec["run_url"] and rec["run_id"]:
            print(f"  {'':4} {'':22} {rec['run_url']}")
    if len(runs) > 1:
        print(f"  {'':4} {'':22} !! MIXED PROVENANCE — this side's suites come "
              f"from {len(runs)} different runs")
    # Stale-side check: the JSON describes the run at git_sha, not the code at
    # ref. Every results-branch merge commit trips this benignly (the run's code
    # commit is an ancestor); a git_sha that is NOT an ancestor is the real trap.
    if ref_sha:
        for sha in runs:
            if sha.startswith(ref_sha[:9]) or ref_sha.startswith(sha[:9]):
                continue
            contained = (len(sha) >= 7 and git_ok("cat-file", "-e", f"{sha}^{{commit}}")
                         and git_ok("merge-base", "--is-ancestor", sha, ref_sha))
            where = ("run's code IS an ancestor of the ref (normal for a "
                     "results-merge commit)" if contained
                     else "run's code is NOT an ancestor of the ref (normal if "
                          "the ref is a raw\n" + " " * 33 + "ruffle-test-results "
                          "commit, which branches off the results branch; a "
                          "real\n" + " " * 33 + "problem if you believed your "
                          "change was in this run)")
            print(f"  {'':4} {'':22} !! STALE SIDE: {label} ref {ref} resolves to "
                  f"{ref_sha[:9]} but the JSON was built at {sha[:9]}")
            print(f"  {'':4} {'':22}    {where}. Verdicts below describe the run "
                  f"at {sha[:9]}, NOT the code at {ref}.")


# --------------------------------------------------------------------------
# features (optional cluster diff)
# --------------------------------------------------------------------------

def load_features(path):
    doc = json.loads(pathlib.Path(path).read_text())
    rows = doc if isinstance(doc, list) else (doc.get("results") or doc.get("rows") or [])
    return {(r["suite"], r["test"], r["comparison"]): r.get("cluster", "unknown")
            for r in rows}


def print_feature_diff(spec):
    try:
        old_path, new_path = spec.split(",", 1)
    except ValueError:
        sys.exit("--features expects OLD.json,NEW.json")
    old, new = load_features(old_path), load_features(new_path)
    shared = old.keys() & new.keys()
    ho = collections.Counter(old[k] for k in shared)
    hn = collections.Counter(new[k] for k in shared)
    print(f"\nCLUSTER HISTOGRAM (image_triage features, "
          f"{len(shared)} shared comparisons)")
    for c in sorted(set(ho) | set(hn)):
        print(f"  {c:28} {ho[c]:5} -> {hn[c]:5} ({hn[c] - ho[c]:+d})")
    moves = [f"{s}/{t} [{c}]: {old[k]} -> {new[k]}"
             for k in sorted(shared) for (s, t, c) in [k] if old[k] != new[k]]
    print(f"\nCLUSTER MOVES: {len(moves)}")
    for m in moves[:MAX_LIST]:
        print("  " + m)
    if len(moves) > MAX_LIST:
        print(f"  ... and {len(moves) - MAX_LIST} more")


# --------------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("old_ref", help="git ref, or a directory of per-suite JSONs")
    ap.add_argument("new_ref", help="git ref, WORKTREE, or a directory")
    ap.add_argument("--stem", default="image_results_graphics",
                    help="image results stem (default: image_results_graphics)")
    ap.add_argument("--per-suite", action="store_true",
                    help="also print a per-suite pass table (only suites that moved)")
    ap.add_argument("--band-floor", type=float, default=0.05,
                    help="suppress same-band excess moves below this relative "
                         "change (default 0.05). lavapipe is deterministic so "
                         "any move is real, but tiny ones are noise to a reader")
    ap.add_argument("--features", metavar="OLD.json,NEW.json",
                    help="also diff mechanism clusters, from two image_triage.py "
                         "outputs")
    ap.add_argument("--max-list", type=int, default=MAX_LIST,
                    help=f"cap on each printed list (default {MAX_LIST})")
    args = ap.parse_args()
    cap = args.max_list

    old_paths = set(result_paths(args.old_ref, args.stem))
    new_paths = set(result_paths(args.new_ref, args.stem))
    if not (old_paths | new_paths):
        sys.exit(f"no */_results/{args.stem}.json found at either side")

    old_suites = {suite_of(p): p for p in old_paths if suite_of(p) not in NESTED}
    new_suites = {suite_of(p): p for p in new_paths if suite_of(p) not in NESTED}
    shared_suites = sorted(old_suites.keys() & new_suites.keys())

    old_docs, new_docs = [], []
    old_rows, new_rows = {}, {}
    for suite in shared_suites:
        o = load(args.old_ref, old_suites[suite])
        n = load(args.new_ref, new_suites[suite])
        if o is None or n is None:
            continue
        old_docs.append((suite, o))
        new_docs.append((suite, n))
        old_rows.update(rows_of(o, suite))
        new_rows.update(rows_of(n, suite))

    old_runs, old_incomplete = provenance(old_docs)
    new_runs, new_incomplete = provenance(new_docs)
    old_sha, new_sha = resolve_sha(args.old_ref), resolve_sha(args.new_ref)

    shared = sorted(old_rows.keys() & new_rows.keys())

    print(f"=== intersection: {len(shared)} comparisons "
          f"({args.old_ref} -> {args.new_ref}, {args.stem}) ===\n")

    print("PROVENANCE")
    print_side("old", args.old_ref, old_sha, old_runs)
    print_side("new", args.new_ref, new_sha, new_runs)

    if set(old_runs) == set(new_runs) and len(old_runs) == 1:
        print("\n!! BOTH SIDES ARE THE SAME IMAGE RUN — nothing to diff.")
        print("   The per-suite image JSONs only change when an `images=true` CI")
        print("   run is merged; `images=false` is the per-change default, so on")
        print("   master these files sit unchanged across dozens of commits.")
        print("   A zero-delta report here would NOT mean 'no regressions' — it")
        print("   would mean the two refs point at the same published run.")
        print("   Pick refs that straddle two images=true merges:")
        print("     git log --follow -- ruffle-tests/tests/swfs/visual/_results/"
              f"{args.stem}.json")
        return 2

    if old_incomplete or new_incomplete:
        print("\n!! INCOMPLETE RUN — metadata.incomplete is set on:")
        for label, items in (("old", old_incomplete), ("new", new_incomplete)):
            for item in items:
                print(f"     {label} {item}")
        print("   Comparisons below are on the intersection and are still valid,")
        print("   but any absolute total from the flagged side is short.")

    # ---------------- histograms ----------------
    hs_old, hs_new = collections.Counter(), collections.Counter()
    hb_old, hb_new = collections.Counter(), collections.Counter()
    hfr_old, hfr_new = collections.Counter(), collections.Counter()
    hsr_old, hsr_new = collections.Counter(), collections.Counter()
    per_suite = collections.defaultdict(lambda: [0, 0])

    gains, regressions = [], []
    band_moves, reason_moves, status_moves = [], [], []

    for key in shared:
        o, n = old_rows[key], new_rows[key]
        so, sn = o.get("status", "unknown"), n.get("status", "unknown")
        hs_old[so] += 1
        hs_new[sn] += 1
        bo, bn = band_of(o), band_of(n)
        if bo:
            hb_old[bo] += 1
        if bn:
            hb_new[bn] += 1
        if so == "fail":
            hfr_old[o.get("reason", "pixel_mismatch")] += 1
        if sn == "fail":
            hfr_new[n.get("reason", "pixel_mismatch")] += 1
        if so == "skip":
            hsr_old[o.get("reason", "unknown")] += 1
        if sn == "skip":
            hsr_new[n.get("reason", "unknown")] += 1
        per_suite[key[0]][0] += so == "pass"
        per_suite[key[0]][1] += sn == "pass"

        label = f"{key[0]}/{key[1]} [{key[2]}]"
        if so != "pass" and sn == "pass":
            gains.append(f"{label}: {so} -> pass")
        elif so == "pass" and sn != "pass":
            regressions.append(
                f"{label}: pass -> {sn}"
                + (f" ({n.get('reason', '')}, excess "
                   f"{n.get('excess_outliers', '?')})" if sn == "fail" else
                   f" ({n.get('reason', '')})"))
        elif so == "fail" and sn == "fail":
            eo, en = o.get("excess_outliers"), n.get("excess_outliers")
            if eo is None or en is None:
                if bo != bn:
                    band_moves.append((None, label, bo, bn, eo, en))
            else:
                rel = (en - eo) / max(abs(eo), 1)
                if bo != bn or abs(rel) >= args.band_floor:
                    band_moves.append((rel, label, bo, bn, eo, en))
            if o.get("reason") != n.get("reason"):
                reason_moves.append(f"{label}: reason "
                                    f"{o.get('reason')} -> {n.get('reason')}")
        elif so != sn:
            status_moves.append(f"{label}: {so} -> {sn}"
                                f" ({o.get('reason')} -> {n.get('reason')})")
        elif so == sn == "skip" and o.get("reason") != n.get("reason"):
            reason_moves.append(f"{label}: skip reason "
                                f"{o.get('reason')} -> {n.get('reason')}")

    def histogram(title, ho, hn, flag_keys=(), note=None):
        print(f"\n{title}")
        if note:
            print(f"  ({note})")
        if not (ho or hn):
            print("  (none)")
            return
        for k in sorted(set(ho) | set(hn)):
            d = hn[k] - ho[k]
            flag = ""
            if any(k.startswith(f) or k == f for f in flag_keys) and d > 0:
                flag = "   <-- FLAG: a rise here is a capture/crash regression"
            print(f"  {k:34} {ho[k]:5} -> {hn[k]:5} ({d:+d}){flag}")

    histogram("STATUS HISTOGRAM", hs_old, hs_new)
    histogram("BAND HISTOGRAM (failures, binned on excess_outliers)",
              hb_old, hb_new, flag_keys=("no_render",))
    histogram("FAIL-REASON HISTOGRAM", hfr_old, hfr_new,
              flag_keys=CRASH_FAIL_REASONS)
    histogram("SKIP-REASON HISTOGRAM", hsr_old, hsr_new,
              flag_keys=CRASH_SKIP_REASONS,
              note="a rise in test_segfault/test_timeout/test_recomp_fail is a "
                   "crash the pixel verdict cannot see")

    if args.per_suite:
        moved = [(s, a, b) for s, (a, b) in sorted(per_suite.items()) if a != b]
        if moved:
            print("\nPER-SUITE PASSES (only suites that moved)")
            for s, a, b in moved:
                print(f"  {s:34} {a:5} -> {b:5} ({b - a:+d})")

    print(f"\nGAINS (-> pass): {len(gains)}")
    for g in gains[:cap]:
        print("  " + g)
    if len(gains) > cap:
        print(f"  ... and {len(gains) - cap} more")

    print(f"\nREGRESSIONS (pass -> not pass): {len(regressions)}")
    for r in regressions:
        print("  " + r)

    improved = [m for m in band_moves if m[0] is not None and m[0] < 0]
    worsened = [m for m in band_moves if m[0] is not None and m[0] > 0]
    categorical = [m for m in band_moves if m[0] is None]
    print(f"\nBAND MOVES (failing on both sides): improved {len(improved)} / "
          f"worsened {len(worsened)} / band-only {len(categorical)}"
          f"   [floor {args.band_floor:.0%}]")
    ordered = categorical + sorted(
        improved + worsened, key=lambda m: -abs(m[0]))
    for rel, label, bo, bn, eo, en in ordered[:cap]:
        pct = "  (n/a)" if rel is None else f"  ({rel:+.0%})"
        print(f"  {label}  {short_band(bo)} -> {short_band(bn)}   "
              f"excess {eo if eo is not None else '—'} -> "
              f"{en if en is not None else '—'}{pct}")
    if len(ordered) > cap:
        print(f"  ... and {len(ordered) - cap} more")

    print(f"\nSTATUS/REASON CHANGES (fail<->skip, reason strings): "
          f"{len(status_moves) + len(reason_moves)}")
    for m in (status_moves + reason_moves)[:cap]:
        print("  " + m)
    if len(status_moves) + len(reason_moves) > cap:
        print(f"  ... and {len(status_moves) + len(reason_moves) - cap} more")

    new_only = sorted(new_rows.keys() - old_rows.keys())
    gone = sorted(old_rows.keys() - new_rows.keys())
    print(f"\nNEW (absent from baseline): {len(new_only)}")
    for s, t, c in new_only[:cap]:
        print(f"  {s}/{t} [{c}]  {new_rows[(s, t, c)].get('status')}")
    if len(new_only) > cap:
        print(f"  ... and {len(new_only) - cap} more")
    print(f"GONE (present in baseline, absent now): {len(gone)}")
    for s, t, c in gone[:cap]:
        print(f"  {s}/{t} [{c}]  was {old_rows[(s, t, c)].get('status')}")
    if len(gone) > cap:
        print(f"  ... and {len(gone) - cap} more")

    only_old = sorted(old_suites.keys() - new_suites.keys())
    only_new = sorted(new_suites.keys() - old_suites.keys())
    if only_old or only_new:
        print("\nUNGRADED — suites present at one side only (a categories="
              "restricted\n  dispatch, or a lost shard). NOT regressions:")
        for s in only_old:
            print(f"  old only: {s}")
        for s in only_new:
            print(f"  new only: {s}")

    if args.features:
        print_feature_diff(args.features)

    return 1 if regressions else 0


if __name__ == "__main__":
    sys.exit(main())
