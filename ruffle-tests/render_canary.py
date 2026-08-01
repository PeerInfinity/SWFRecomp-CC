#!/usr/bin/env python3
"""Local render canary — our-render-BEFORE vs our-render-AFTER, byte-exact.

A/B regression check for graphics work. Renders a small standing set of tests
with the native `--mode=graphics` build, keeps every actual PNG (pass or fail),
and md5-compares two captures. Trace output and both status axes come along
for free, so a render canary also catches trace regressions.

Two-phase by design — a render run is compile-bound, so stash-per-iteration
would rebuild BOTH legs on every iteration:

    ruffle-tests/render_canary.py capture --label before      # once, pre-edit
    ...edit render code, iterate...
    ruffle-tests/render_canary.py capture --label after
    ruffle-tests/render_canary.py compare before after

`before` is captured once per session and reused across many `after` captures.
Exit status is non-zero when anything moved, so `compare` drops straight into a
pre-handoff check.

Mechanism (all of it already existed in verify_output.py; this script is a
driver, it changes nothing):
  * `SWF_KEEP_BUILD_DIR=DIR` makes verify_output.py keep its build dir instead
    of using a TemporaryDirectory, and the actual render lands there as
    `<cmp>.png` — one per `[image_comparisons.NAME]` entry, written
    VERDICT-INDEPENDENTLY (`--image-out-dir` exports only failures; `--verbose`
    copies into the test dir, which dirties the tracked `regression/` suite).
  * Rendering is enabled by the PRESENCE of `[image_comparisons]` in test.toml
    (which sets -DHEADLESS_RENDER_ENABLED), NOT by the presence of an expected
    PNG. Expected PNGs are irrelevant to a canary — `skip`-status tests render
    fine and are valid canary targets.
  * Local Dawn is byte-identical run-to-run (w1c: 17/17 PNGs, cold and warm,
    sequential and under -P 2). So the bar is md5 equality with NO epsilon.
    Channel stats are a secondary tier, computed only when something DIFFERS,
    via `verify_output.compare_images` so they are definitionally identical to
    CI's.

===========================================================================
FALSE-POSITIVE / FALSE-NEGATIVE MODES  (verbatim from w1c §6 — read before
believing any result)
===========================================================================

The canary is our-render-before vs our-render-after on ONE machine with ONE
renderer. It is never a grade. Local Dawn is not pixel-identical to CI's
lavapipe — `bitmapdata_copypixels` passes on CI while showing ~25k tolerance-0
outlier channels locally. Never claim a pass/fail from a local render against
an expected PNG. The canary answers only "did my change move the pixels, and
where" — CI answers "are the pixels right".

 1. **Stale recompiler output — the silent false NEGATIVE.** A change in
    `SWFRecomp/` (the recompiler) does **not** take effect unless you (a)
    rebuild the recompiler binary with cmake, and (b) pass `--recompile`,
    because `RecompiledScripts/` is cached inside each test directory.
    Without both, the canary reports `IDENTICAL` for every test and you
    conclude your change was inert. Runtime (`SWFModernRuntime/`) changes need
    neither — compilation always re-runs and ccache is content-keyed, so an
    edited `.c` misses the cache and rebuilds.
 2. **A stash-mode `before` leg overwrites `RecompiledScripts/`.** If you use
    `--stash` with a recompiler change, *both* legs must be captured with
    `--recompile`, or the second leg silently reuses the first leg's
    generated C.
 3. **Never edit sources mid-capture.** A capture leg that straddles an edit
    mixes builds across tests and produces uninterpretable diffs. Same rule as
    the trace sweep.
 4. **Never share a `SWF_KEEP_BUILD_DIR` between concurrent runs.** They
    clobber each other's sources and PNGs. One directory per (test, label).
 5. **`-P 2` is the validated fan-out** (clean across four concurrent pairs;
    three A/B pairs straddled the sequential/concurrent boundary and stayed
    byte-identical). `-P 4` only on a machine you own. Do not go higher — the
    trace-side sweep's float-formatting and long-compile timeout false
    positives show up at `-P 6-8`, and the machine is usually shared.
 6. **`--verbose` writes actual/difference PNGs into the test directory.**
    Harmless for the gitignored upstream mirrors, but it dirties the working
    tree for the fully-tracked `regression/` suite, and it races between two
    runs of the same test. Use `SWF_KEEP_BUILD_DIR`; never `--verbose`, in a
    canary.
 7. **The image verdict is not on stdout.** It exists only in the `--json`
    report. A run whose console says `Pass: 1 (100.0%)` tells you the *trace*
    matched; the pixels may be entirely wrong. Always read the JSON.
 8. **`NO_RENDER` is not a canary failure.** ~40 avm2 tests (Stage3D/AGAL,
    PixelBender, JPEG-XR decode, NetStream video) render nothing at all. They
    are real gaps in the graded baseline, but as canaries they are inert —
    nothing to compare. Keep them out of the standing set.
 9. **A Tier-2 `DIFFERS` is not automatically a regression.** Those tests
    already fail against their expected PNG; a pixel move there may be the fix
    working. Read the stats and the difference PNG; if the change was meant to
    touch that family, `DIFFERS` is the *expected* outcome.
10. **`IDENTICAL` everywhere after a change you believe is live is a red flag,
    not a clean bill.** Check mode 1 first, then check that the canary set
    actually covers the family you touched (filters, morph, and visual-suite
    masks have **no** CI-passing representative — they are Tier-2-only).

Mode 1 is the headline: if you changed anything under `SWFRecomp/`, rebuild the
recompiler with cmake AND pass `--recompile`, or the canary is measuring
nothing. This script prints a reminder banner whenever it captures without
`--recompile`.

Corollaries this script implements:
  * `IDENTICAL` on a test the change was MEANT to affect is as much a finding
    as `DIFFERS` on one it was not — hence `--expect-differs PATTERN`, which
    asserts the blast radius in BOTH directions.
  * `NO_RENDER` (mode 8) is reported but does not gate the exit status.
  * An 11th mode, found while validating this script: md5 is a bound on the
    FILE, not on the pixels. A `DIFFERS` whose secondary stats report
    `diff_channels 0` means the PNG was re-encoded (different encoder or
    settings) while every pixel matched — a build/toolchain change, not a
    render change. The report calls that out explicitly. It still gates, since
    a canary should never silently swallow an unexplained byte move.
"""

from __future__ import annotations

import argparse
import concurrent.futures
import fnmatch
import hashlib
import json
import os
import shutil
import subprocess
import sys
import threading
import time
from datetime import datetime, timezone
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
PROJECT_ROOT = SCRIPT_DIR.parent
SWFS_DIR = SCRIPT_DIR / "tests" / "swfs"
VERIFY = SCRIPT_DIR / "verify_output.py"
DEFAULT_LIST = SCRIPT_DIR / "render_canary_tests.txt"
DEFAULT_OUT = PROJECT_ROOT / ".render_canary"

JOBS_DEFAULT = 2
JOBS_CAP = 4          # w1c §4: -P 2 validated, -P 4 ceiling, never higher
TIMEOUT_DEFAULT = 900

_print_lock = threading.Lock()


def log(msg):
    with _print_lock:
        print(msg, flush=True)


# --------------------------------------------------------------------------
# test list
# --------------------------------------------------------------------------

def load_test_list(path, tier="all"):
    """Parse a canary list file into ordered `suite/test` strings.

    Format: one `suite/test` per line, `#` comments, blank lines ignored.
    A comment line containing `tier=N` switches the tier of everything after
    it, so `--tier 1|2` can filter without a second file.
    """
    tests, seen, cur = [], set(), "1"
    for raw in Path(path).read_text(encoding="utf-8").splitlines():
        line = raw.strip()
        if not line:
            continue
        if line.startswith("#"):
            if "tier=" in line:
                cur = line.split("tier=", 1)[1].strip().split()[0].strip(":,)")
            continue
        name = line.split("#", 1)[0].strip()
        if not name:
            continue
        if tier not in ("all", cur):
            continue
        if name not in seen:
            seen.add(name)
            tests.append(name)
    return tests


def split_test(name):
    """`visual/simple_shapes/masks` -> ('visual', 'simple_shapes/masks')."""
    suite, _, rest = name.partition("/")
    if not rest:
        raise ValueError(f"test must be 'suite/name', got {name!r}")
    return suite, rest


def resolve_dawn_install():
    """Return a DAWN_INSTALL override, or None to leave the env alone.

    verify_output.py defaults DAWN_INSTALL to `<repo-parent>/dawn-install`,
    which is wrong when the repo is a git worktree (its parent is
    `.claude/worktrees/`). Fall back to the canonical `~/CC/dawn-install`.
    """
    if os.environ.get("DAWN_INSTALL"):
        return None
    default = PROJECT_ROOT.parent / "dawn-install" / "lib" / "libwebgpu_dawn.a"
    if default.exists():
        return None
    fallback = Path.home() / "CC" / "dawn-install"
    if (fallback / "lib" / "libwebgpu_dawn.a").exists():
        return str(fallback)
    return None


def git_info():
    def run(args):
        try:
            return subprocess.run(args, cwd=str(PROJECT_ROOT), capture_output=True,
                                  text=True, timeout=30).stdout.strip()
        except Exception:
            return ""
    return {
        "sha": run(["git", "rev-parse", "HEAD"]),
        "dirty_files": [l[3:] for l in run(["git", "status", "--porcelain"]).splitlines()],
    }


# --------------------------------------------------------------------------
# capture
# --------------------------------------------------------------------------

def capture_one(name, label_dir, args, dawn):
    """Run one test under SWF_KEEP_BUILD_DIR and harvest its artifacts.

    Layout (one build dir per (test, label) — false-positive mode 4):
        <label_dir>/<suite>/<test>/_build/     transient, deleted after harvest
        <label_dir>/<suite>/<test>/<cmp>.png   the actual renders
        <label_dir>/<suite>/<test>/result.json verify_output --json report
        <label_dir>/<suite>/<test>/trace.txt   filtered actual trace text
        <label_dir>/<suite>/<test>/console.txt stdout+stderr (incl. --diff)
        <label_dir>/<suite>/<test>/meta.json   canary-side summary
    """
    suite, test = split_test(name)
    tests_dir = SWFS_DIR / suite
    out = label_dir / suite / test
    build = out / "_build"
    if out.exists():
        shutil.rmtree(out)
    build.mkdir(parents=True)

    cmd = [sys.executable, str(VERIFY),
           f"--tests-dir={tests_dir}",
           f"--test={test}",
           "--mode=graphics",
           "--images",              # mode 7: stats block only exists with this
           "--diff",                # trace diff into console.txt, free
           f"--json={out / 'result.json'}",
           f"--save-actual={out / 'trace.txt'}"]
    if args.recompile:
        cmd.append("--recompile")

    env = dict(os.environ)
    env["SWF_KEEP_BUILD_DIR"] = str(build)
    if dawn:
        env["DAWN_INSTALL"] = dawn

    t0 = time.monotonic()
    try:
        proc = subprocess.run(cmd, cwd=str(PROJECT_ROOT), env=env,
                              capture_output=True, text=True,
                              timeout=args.timeout)
        rc, console = proc.returncode, proc.stdout + proc.stderr
    except subprocess.TimeoutExpired as exc:
        rc = -9
        console = (exc.stdout or "") + (exc.stderr or "") + \
                  f"\n[render_canary] TIMEOUT after {args.timeout}s\n"
    wall = round(time.monotonic() - t0, 2)

    (out / "console.txt").write_text(console, encoding="utf-8", errors="replace")

    # Harvest the actuals. `<cmp>.difference.png` is verify_output's
    # actual-vs-EXPECTED diff — not our axis, and it exists only for some
    # verdicts, so it would make the capture verdict-dependent. Dropped.
    pngs = {}
    if build.is_dir():
        for png in sorted(build.glob("*.png")):
            if png.name.endswith(".difference.png"):
                continue
            shutil.move(str(png), str(out / png.name))
            pngs[png.stem] = md5(out / png.name)
    shutil.rmtree(build, ignore_errors=True)

    meta = {"test": name, "suite": suite, "exit_code": rc, "wall": wall,
            "png_md5": pngs}
    meta.update(read_result(out / "result.json"))
    (out / "meta.json").write_text(json.dumps(meta, indent=1), encoding="utf-8")

    log(f"  [{meta['trace_status'] or 'NO_RESULT':>15}] {name:<45} "
        f"{len(pngs):>2} png  {wall:>7.2f}s")
    return meta


def read_result(result_json):
    """Pull the trace status, declared comparisons and phase timings out of a
    verify_output --json report. Missing/garbled -> empty, never raises."""
    empty = {"trace_status": None, "image_status": {}, "declared_cmps": [],
             "phases": {}, "duration": None}
    try:
        data = json.loads(Path(result_json).read_text(encoding="utf-8"))
        entry = data["tests"][0]
    except Exception:
        return empty
    ic = entry.get("image_comparisons") or {}
    return {
        "trace_status": entry.get("status"),
        "image_status": {k: v.get("status") for k, v in ic.items()},
        "image_stats": {k: v.get("stats") for k, v in ic.items()},
        "declared_cmps": sorted(ic.keys()),
        "phases": entry.get("phases", {}),
        "duration": entry.get("duration"),
    }


def md5(path):
    h = hashlib.md5()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def cmd_capture(args):
    tests = collect_tests(args)
    if not tests:
        print("No tests selected.", file=sys.stderr)
        return 2

    out_root = Path(args.out).resolve()
    label_dir = out_root / args.label
    if label_dir.exists():
        if not args.force:
            print(f"Label dir already exists: {label_dir}\n"
                  f"Pass --force to overwrite, or pick another --label.",
                  file=sys.stderr)
            return 2
        shutil.rmtree(label_dir)
    label_dir.mkdir(parents=True)

    jobs = max(1, min(args.jobs, JOBS_CAP))
    dawn = resolve_dawn_install()

    print(f"RENDER CANARY capture  label={args.label}  {len(tests)} tests  "
          f"-P {jobs}  ->  {label_dir}")
    if dawn:
        print(f"  DAWN_INSTALL={dawn}  (repo-parent default not present)")
    if not args.recompile:
        print("  NOTE: --recompile NOT set. A SWFRecomp/ (recompiler) change is"
              " INERT without a\n"
              "        cmake rebuild AND --recompile — the canary would report"
              " IDENTICAL for\n"
              "        every test (false-negative mode 1). Runtime-only changes"
              " are fine.")
    print()

    t0 = time.monotonic()
    metas = []
    if jobs == 1:
        for name in tests:
            metas.append(capture_one(name, label_dir, args, dawn))
    else:
        with concurrent.futures.ThreadPoolExecutor(max_workers=jobs) as pool:
            futs = {pool.submit(capture_one, n, label_dir, args, dawn): n
                    for n in tests}
            for fut in concurrent.futures.as_completed(futs):
                try:
                    metas.append(fut.result())
                except Exception as exc:                      # pragma: no cover
                    log(f"  [ERROR] {futs[fut]}: {type(exc).__name__}: {exc}")
                    metas.append({"test": futs[fut], "error": str(exc),
                                  "png_md5": {}, "trace_status": None,
                                  "image_status": {}, "declared_cmps": []})
    wall = time.monotonic() - t0

    metas.sort(key=lambda m: m["test"])
    manifest = {
        "label": args.label,
        "created": datetime.now(timezone.utc).isoformat(),
        "mode": "graphics",
        "jobs": jobs,
        "recompile": bool(args.recompile),
        "tests": [m["test"] for m in metas],
        "wall_seconds": round(wall, 2),
        "git": git_info(),
        "results": metas,
    }
    (label_dir / "manifest.json").write_text(json.dumps(manifest, indent=1),
                                             encoding="utf-8")

    npng = sum(len(m.get("png_md5", {})) for m in metas)
    bad = [m["test"] for m in metas if m.get("exit_code") not in (0, None)]
    print(f"\n  {len(metas)} tests, {npng} PNGs captured in {wall:.1f}s "
          f"({wall / max(1, len(metas)):.1f}s/test)")
    if bad:
        print(f"  runner exit != 0 on {len(bad)}: {', '.join(bad)}")
    print(f"  manifest: {label_dir / 'manifest.json'}")
    return 0


def collect_tests(args):
    if args.test:
        return list(dict.fromkeys(args.test))
    return load_test_list(args.tests or DEFAULT_LIST, args.tier)


# --------------------------------------------------------------------------
# compare
# --------------------------------------------------------------------------

IDENTICAL, DIFFERS, APPEARED, VANISHED, NO_RENDER = (
    "IDENTICAL", "DIFFERS", "APPEARED", "VANISHED", "NO_RENDER")


def load_label(out_root, label):
    d = Path(out_root).resolve() / label
    mf = d / "manifest.json"
    if not mf.is_file():
        raise SystemExit(f"No capture labelled {label!r} under {out_root} "
                         f"(expected {mf})")
    data = json.loads(mf.read_text(encoding="utf-8"))
    return d, data, {m["test"]: m for m in data["results"]}


def pixel_stats(before_png, after_png, work_dir, cmp_name):
    """Channel stats + changed-pixel bbox for a DIFFERS pair.

    Stats come from `verify_output.compare_images` so they are definitionally
    the same numbers CI reports (diff_channels / mean_diff / max_diff). The
    before-leg PNG is the reference. Also leaves `<cmp>.before.png`,
    `<cmp>.after.png` and `<cmp>.after.difference.png` in `work_dir` for
    eyeballing — compare_images writes the difference next to its first arg.
    """
    work_dir.mkdir(parents=True, exist_ok=True)
    b = work_dir / f"{cmp_name}.before.png"
    a = work_dir / f"{cmp_name}.after.png"
    shutil.copy2(before_png, b)
    shutil.copy2(after_png, a)

    sys.path.insert(0, str(SCRIPT_DIR))
    import verify_output                              # noqa: E402
    _, message, max_diff, stats = verify_output.compare_images(
        a, b, [{"tolerance": 0, "max_outliers": 0}])
    stats = dict(stats or {})
    stats["message"] = message
    stats.setdefault("max_diff", max_diff)

    try:
        from PIL import Image, ImageChops
        diff = ImageChops.difference(Image.open(a).convert("RGBA"),
                                     Image.open(b).convert("RGBA"))
        # Pillow >= 9.2 defaults getbbox() to alpha_only=True on RGBA, which
        # would silently report "no change" for any pure-RGB move (alpha is
        # usually identical). Force all four channels.
        try:
            bbox = diff.getbbox(alpha_only=False)
        except TypeError:                       # Pillow < 9.2
            bbox = diff.getbbox()
        stats["bbox"] = list(bbox) if bbox else None
    except Exception:
        stats["bbox"] = None
    return stats


def read_text(p):
    try:
        return Path(p).read_bytes()
    except Exception:
        return b""


def cmd_compare(args):
    out_root = Path(args.out).resolve()
    a_dir, a_mf, a_res = load_label(out_root, args.before)
    b_dir, b_mf, b_res = load_label(out_root, args.after)

    work_root = out_root / "_compare" / f"{args.before}__{args.after}"
    if work_root.exists():
        shutil.rmtree(work_root)

    tests = sorted(set(a_res) | set(b_res))
    rows, trace_changes, image_changes, missing = [], [], [], []

    for name in tests:
        ma, mb = a_res.get(name), b_res.get(name)
        if ma is None or mb is None:
            missing.append((name, "before" if ma is None else "after"))
            continue
        suite, test = split_test(name)
        a_test, b_test = a_dir / suite / test, b_dir / suite / test

        # trace: filtered actual output, byte-compare, plus the runner verdict
        ta, tb = read_text(a_test / "trace.txt"), read_text(b_test / "trace.txt")
        trace_same = ta == tb
        if not trace_same or ma.get("trace_status") != mb.get("trace_status"):
            trace_changes.append((name, ma.get("trace_status"),
                                  mb.get("trace_status"), trace_same))

        cmps = sorted(set(ma.get("png_md5", {})) | set(mb.get("png_md5", {}))
                      | set(ma.get("declared_cmps", []))
                      | set(mb.get("declared_cmps", [])))
        for cmp_name in cmps:
            ha = ma.get("png_md5", {}).get(cmp_name)
            hb = mb.get("png_md5", {}).get(cmp_name)
            if ha is None and hb is None:
                verdict, stats = NO_RENDER, None
            elif ha is None:
                verdict, stats = APPEARED, None
            elif hb is None:
                verdict, stats = VANISHED, None
            elif ha == hb:
                verdict, stats = IDENTICAL, None
            else:
                verdict = DIFFERS
                stats = pixel_stats(a_test / f"{cmp_name}.png",
                                    b_test / f"{cmp_name}.png",
                                    work_root / suite / test, cmp_name)
            sa = (ma.get("image_status") or {}).get(cmp_name)
            sb = (mb.get("image_status") or {}).get(cmp_name)
            if sa != sb:
                image_changes.append((name, cmp_name, sa, sb))
            rows.append({"test": name, "comparison": cmp_name,
                         "verdict": verdict, "stats": stats,
                         "image_status_before": sa, "image_status_after": sb,
                         "trace_identical": trace_same,
                         "trace_status_before": ma.get("trace_status"),
                         "trace_status_after": mb.get("trace_status")})

    # ---- blast-radius assertion -----------------------------------------
    expect_violations = []
    if args.expect_differs:
        for r in rows:
            if r["verdict"] == NO_RENDER:
                continue
            key, keyc = r["test"], f"{r['test']}:{r['comparison']}"
            want = any(fnmatch.fnmatch(key, p) or fnmatch.fnmatch(keyc, p)
                       for p in args.expect_differs)
            if want and r["verdict"] == IDENTICAL:
                expect_violations.append((keyc, "expected DIFFERS, got IDENTICAL"))
            elif not want and r["verdict"] != IDENTICAL:
                expect_violations.append((keyc, f"outside blast radius, got {r['verdict']}"))

    # ---- report ----------------------------------------------------------
    counts = {k: 0 for k in (IDENTICAL, DIFFERS, APPEARED, VANISHED, NO_RENDER)}
    for r in rows:
        counts[r["verdict"]] += 1

    print(f"RENDER CANARY  before={args.before}  after={args.after}   "
          f"{len(tests)} tests / {len(rows)} comparisons\n")
    print(f"  IDENTICAL  {counts[IDENTICAL]:>4}")
    print(f"  DIFFERS    {counts[DIFFERS]:>4}")
    print(f"  APPEARED   {counts[APPEARED]:>4}   VANISHED {counts[VANISHED]}   "
          f"NO_RENDER {counts[NO_RENDER]}")
    if missing:
        print(f"  MISSING    {len(missing):>4}   (test absent from one label)")

    changed = [r for r in rows if r["verdict"] in (DIFFERS, APPEARED, VANISHED)]
    if changed:
        print("\n  DIFFERS:")
        for r in changed:
            s = r["stats"] or {}
            print(f"    {r['test']}  {r['comparison']}   [{r['verdict']}]")
            if s:
                bbox = s.get("bbox")
                bbox_s = (f"bbox ({bbox[0]},{bbox[1]})-({bbox[2]},{bbox[3]})"
                          if bbox else "bbox -")
                print(f"        diff_channels {s.get('diff_channels')}/"
                      f"{s.get('total_channels')}  mean {s.get('mean_diff')}  "
                      f"max {s.get('max_diff')}   {bbox_s}")
                if s.get("error"):
                    print(f"        !! stats unavailable: {s['error']} "
                          f"({s.get('message')})")
                elif not s.get("diff_channels"):
                    print("        !! PNG BYTES differ but every PIXEL matches"
                          " — a re-encode (different encoder/settings), not a"
                          " render change.")
            print(f"        image status: {r['image_status_before']} -> "
                  f"{r['image_status_after']}    trace: "
                  f"{r['trace_status_before']} -> {r['trace_status_after']}")
    if counts[NO_RENDER] and args.verbose:
        print("\n  NO_RENDER (declared but nothing rendered in either leg — "
              "inert, does not gate):")
        for r in rows:
            if r["verdict"] == NO_RENDER:
                print(f"    {r['test']}  {r['comparison']}")

    print("\n  TRACE STATUS CHANGES:" if trace_changes
          else "\n  TRACE STATUS CHANGES: (none)")
    for name, sa, sb, same in trace_changes:
        note = "" if same else "   (trace text differs)"
        print(f"    {name}   {sa} -> {sb}{note}")

    print("  IMAGE STATUS CHANGES:" if image_changes
          else "  IMAGE STATUS CHANGES: (none)")
    for name, cmp_name, sa, sb in image_changes:
        print(f"    {name}  {cmp_name}   {sa} -> {sb}        <-- REVIEW")

    for name, which in missing:
        print(f"  MISSING: {name} absent from label {which!r}")

    if args.expect_differs:
        print("\n  BLAST RADIUS (--expect-differs "
              f"{' '.join(args.expect_differs)}):")
        if expect_violations:
            for key, why in expect_violations:
                print(f"    {key}: {why}")
        else:
            print("    as expected")

    if changed:
        print(f"\n  before/after PNGs + difference PNGs: {work_root}")

    if args.json:
        Path(args.json).write_text(json.dumps({
            "before": args.before, "after": args.after,
            "before_manifest": {k: a_mf[k] for k in
                                ("created", "git", "recompile") if k in a_mf},
            "after_manifest": {k: b_mf[k] for k in
                               ("created", "git", "recompile") if k in b_mf},
            "counts": counts, "comparisons": rows,
            "trace_changes": trace_changes, "image_status_changes": image_changes,
            "missing": missing, "expect_violations": expect_violations,
        }, indent=1), encoding="utf-8")
        print(f"  json: {args.json}")

    # NO_RENDER is inert (false-positive mode 8) and does not gate.
    # --expect-differs replaces the pixel axis of the gate (a DIFFERS inside
    # the declared radius is the POINT), but the trace axis still gates: a
    # blast-radius pattern is about pixels and says nothing about traces.
    if args.expect_differs:
        return 1 if (expect_violations or trace_changes or missing) else 0
    return 1 if (changed or trace_changes or missing) else 0


# --------------------------------------------------------------------------
# one-shot stash wrapper  (EXPERIMENTAL — see false-negative mode 2)
# --------------------------------------------------------------------------

def cmd_run(args):
    """capture after -> git stash the listed paths -> capture before -> pop.

    Convenience only, and deliberately NOT the default: it forces a full
    rebuild of both legs. Use the two-phase flow for anything iterative.
    """
    paths = [str(p) for p in args.stash]
    if not paths:
        print("run --stash needs at least one path", file=sys.stderr)
        return 2
    if not args.recompile:
        print("WARNING: stash mode without --recompile. If any stashed path is\n"
              "         under SWFRecomp/, the before leg silently reuses the\n"
              "         after leg's RecompiledScripts/ (false-negative mode 2).")

    after = argparse.Namespace(**vars(args))
    after.label = args.after_label
    rc = cmd_capture(after)
    if rc:
        return rc

    stashed = False
    try:
        r = subprocess.run(["git", "stash", "push", "-m",
                            "render_canary before-leg", "--"] + paths,
                           cwd=str(PROJECT_ROOT), capture_output=True, text=True)
        print(r.stdout.strip() or r.stderr.strip())
        if r.returncode:
            print("git stash push failed; aborting", file=sys.stderr)
            return 2
        if "No local changes" in (r.stdout or ""):
            print("Nothing was stashed — the two legs would be identical.",
                  file=sys.stderr)
            return 2
        stashed = True
        before = argparse.Namespace(**vars(args))
        before.label = args.before_label
        rc = cmd_capture(before)
    finally:
        if stashed:
            r = subprocess.run(["git", "stash", "pop"], cwd=str(PROJECT_ROOT),
                               capture_output=True, text=True)
            print(r.stdout.strip() or r.stderr.strip())
            if r.returncode:
                print("!! git stash pop FAILED — your changes are still in the "
                      "stash. Recover with `git stash list` / `git stash pop`.",
                      file=sys.stderr)
                return 2
    if rc:
        return rc
    cmp_args = argparse.Namespace(**vars(args))
    cmp_args.before, cmp_args.after = args.before_label, args.after_label
    return cmd_compare(cmp_args)


# --------------------------------------------------------------------------

def main(argv=None):
    p = argparse.ArgumentParser(
        prog="render_canary.py",
        description=__doc__.split("=====")[0].strip(),
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="Read the module docstring for the 10 false-positive / "
               "false-negative modes before believing any result.")
    sub = p.add_subparsers(dest="command", required=True)

    def common(sp):
        sp.add_argument("--out", default=str(DEFAULT_OUT),
                        help=f"capture root (default {DEFAULT_OUT})")

    cap = sub.add_parser("capture", help="render the canary set into a label")
    common(cap)
    cap.add_argument("--label", required=True, help="capture name, e.g. before")
    cap.add_argument("--tests", help=f"list file (default {DEFAULT_LIST})")
    cap.add_argument("--test", action="append", default=[], metavar="SUITE/NAME",
                     help="explicit test (repeatable); overrides --tests")
    cap.add_argument("--tier", choices=["1", "2", "all"], default="all")
    cap.add_argument("--jobs", "-P", type=int, default=JOBS_DEFAULT,
                     help=f"parallel tests (default {JOBS_DEFAULT}, cap {JOBS_CAP})")
    cap.add_argument("--recompile", action="store_true",
                     help="forward --recompile to verify_output.py — REQUIRED "
                          "for any SWFRecomp/ change (mode 1)")
    cap.add_argument("--timeout", type=int, default=TIMEOUT_DEFAULT)
    cap.add_argument("--force", action="store_true", help="overwrite the label")
    cap.set_defaults(func=cmd_capture)

    cmp_ = sub.add_parser("compare", help="md5-compare two labels")
    common(cmp_)
    cmp_.add_argument("labels", nargs="*", metavar="BEFORE AFTER")
    cmp_.add_argument("--before")
    cmp_.add_argument("--after")
    cmp_.add_argument("--json", help="write the machine-readable report here")
    cmp_.add_argument("--expect-differs", action="append", default=[],
                      metavar="PATTERN",
                      help="fnmatch on 'suite/test' or 'suite/test:cmp'; "
                           "asserts the blast radius in BOTH directions")
    cmp_.add_argument("--verbose", action="store_true")
    cmp_.set_defaults(func=cmd_compare)

    run = sub.add_parser("run", help="one-shot stash wrapper (EXPERIMENTAL)")
    common(run)
    run.add_argument("--stash", nargs="+", default=[], metavar="PATH",
                     help="paths to stash for the before leg")
    run.add_argument("--before-label", default="stash_before")
    run.add_argument("--after-label", default="stash_after")
    run.add_argument("--tests")
    run.add_argument("--test", action="append", default=[])
    run.add_argument("--tier", choices=["1", "2", "all"], default="all")
    run.add_argument("--jobs", "-P", type=int, default=JOBS_DEFAULT)
    run.add_argument("--recompile", action="store_true")
    run.add_argument("--timeout", type=int, default=TIMEOUT_DEFAULT)
    run.add_argument("--force", action="store_true")
    run.add_argument("--json")
    run.add_argument("--expect-differs", action="append", default=[])
    run.add_argument("--verbose", action="store_true")
    run.set_defaults(func=cmd_run)

    args = p.parse_args(argv)

    if args.command == "compare":
        labels = list(args.labels)
        if args.before is None and labels:
            args.before = labels.pop(0)
        if args.after is None and labels:
            args.after = labels.pop(0)
        if not args.before or not args.after or labels:
            p.error("compare takes exactly two labels "
                    "(positional, or --before/--after)")

    return args.func(args)


if __name__ == "__main__":
    sys.exit(main())
