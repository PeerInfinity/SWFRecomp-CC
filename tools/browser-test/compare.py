#!/usr/bin/env python3
"""Diff helpers for browser-WASM probe outputs.

Diagnostic-only: prints a report, returns rc=0 on a clean compare and rc=1
on any divergence. Used standalone or imported by future assertion runners
(Phase 3+). Pixel comparison reuses `verify_output.compare_images` so the
browser harness and `ruffle-tests/` stay aligned.

Trace usage:
    python3 tools/browser-test/compare.py traces a.txt b.txt
    python3 tools/browser-test/compare.py traces a.txt b.txt --filter-startup

Image usage:
    python3 tools/browser-test/compare.py images a.png b.png
    python3 tools/browser-test/compare.py images a.png b.png \\
        --tolerance 8 --max-outliers 1000
"""
import argparse
import re
import sys
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[2]
# Reuse the existing Ruffle-style image comparison so this harness and
# verify_output.py never drift on diff semantics.
sys.path.insert(0, str(REPO_ROOT / "ruffle-tests"))
try:
    import verify_output as vo
except ImportError as e:
    vo = None
    _vo_import_err = e


# Startup-noise patterns common to browser-WASM trace dumps. Kept in sync with
# the divergence harness's NOISE_PATTERNS where they overlap.
NOISE_PATTERNS = [
    re.compile(r"^SWF Runtime Loaded"),
    re.compile(r"^\[HEAP\]"),
    re.compile(r" \$version="),
    # Emscripten startup banner that prints in dev builds; not part of any trace.
    re.compile(r"^pre-main prep time:"),
    re.compile(r"^Aborted\("),
]


def filter_trace(text: str, drop_startup: bool = True) -> list[str]:
    out = []
    for line in text.splitlines():
        if not line.strip():
            continue
        if drop_startup and any(p.search(line) for p in NOISE_PATTERNS):
            continue
        out.append(line)
    return out


def first_trace_divergence(a_lines, b_lines):
    """(index, a_line, b_line) of first differing line, or (-1, '', '')."""
    n = max(len(a_lines), len(b_lines))
    for i in range(n):
        a = a_lines[i] if i < len(a_lines) else "<EOF>"
        b = b_lines[i] if i < len(b_lines) else "<EOF>"
        if a != b:
            return i, a, b
    return -1, "", ""


def cmd_traces(args) -> int:
    a_text = Path(args.a).read_text()
    b_text = Path(args.b).read_text()
    a = filter_trace(a_text, drop_startup=not args.no_filter)
    b = filter_trace(b_text, drop_startup=not args.no_filter)

    print(f"a: {args.a}  ({len(a)} filtered lines)")
    print(f"b: {args.b}  ({len(b)} filtered lines)")
    idx, la, lb = first_trace_divergence(a, b)
    if idx < 0:
        print("MATCH — all filtered lines identical")
        return 0
    print(f"DIVERGE at filtered line {idx}:")
    print(f"  a: {la}")
    print(f"  b: {lb}")
    ctx_start = max(0, idx - 3)
    if ctx_start < idx:
        print(f"  context (filtered lines {ctx_start}-{idx - 1}):")
        for j in range(ctx_start, idx):
            print(f"     {j}: {a[j]}")
    return 1


def cmd_images(args) -> int:
    if vo is None:
        print(f"error: could not import verify_output: {_vo_import_err}",
              file=sys.stderr)
        return 2
    a = Path(args.a)
    b = Path(args.b)
    if not a.exists():
        print(f"error: {a} does not exist", file=sys.stderr)
        return 2
    if not b.exists():
        print(f"error: {b} does not exist", file=sys.stderr)
        return 2
    checks = [{"tolerance": args.tolerance, "max_outliers": args.max_outliers}]
    passed, msg, max_diff = vo.compare_images(a, b, checks)
    print(f"a:         {a}")
    print(f"b:         {b}")
    print(f"tolerance: {args.tolerance}  max_outliers: {args.max_outliers}")
    print(f"max_diff:  {max_diff}")
    print(f"result:    {'MATCH' if passed else 'DIVERGE'} — {msg}")
    return 0 if passed else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0],
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)

    ap_traces = sub.add_parser("traces", help="Diff two trace.txt files.")
    ap_traces.add_argument("a", type=Path)
    ap_traces.add_argument("b", type=Path)
    ap_traces.add_argument("--no-filter", action="store_true",
                           help="Don't drop startup-noise lines before comparing.")
    ap_traces.set_defaults(func=cmd_traces)

    ap_imgs = sub.add_parser("images", help="Diff two PNG files (Ruffle algorithm).")
    ap_imgs.add_argument("a", type=Path)
    ap_imgs.add_argument("b", type=Path)
    ap_imgs.add_argument("--tolerance", type=int, default=0)
    ap_imgs.add_argument("--max-outliers", type=int, default=0)
    ap_imgs.set_defaults(func=cmd_images)

    args = ap.parse_args()
    sys.exit(args.func(args))


if __name__ == "__main__":
    main()
