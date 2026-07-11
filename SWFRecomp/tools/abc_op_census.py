#!/usr/bin/env python3
"""Static IR-opcode census over an avm2 test suite (parse-only — safe to run
locally on the whole corpus, like abc_corpus_sweep.py).

For every test dir with a test.swf, runs `SWFRecomp --dump-abc` and records
the set of resolved-IR opcodes (abc_ir.hpp mnemonics) the SWF's method
bodies use. Emits:

  - per-op summary: how many tests use the op, how many tests it BLOCKS
    (i.e. the test uses it and it is not in the --implemented set)
  - the pass-ceiling of the --implemented set: tests whose entire static op
    surface is covered (a necessary, not sufficient, condition to pass —
    builtins/coercions can still be missing)
  - a greedy unlock order: repeatedly add the op that unblocks the most
    tests (looking only at tests blocked by <= --horizon missing ops)

Usage:
  python3 SWFRecomp/tools/abc_op_census.py \
      [--tests-dir ruffle-tests/tests/swfs/avm2] \
      [--implemented op1,op2,... | --implemented-file FILE] \
      [--json OUT.json] [--horizon 8]

The default --implemented set is Stage 2's 21-op hello_world surface
(see SWFRecomp/src/abc/abc_emit.cpp emitOp).
"""

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

TOOLS_DIR = Path(__file__).resolve().parent
PROJECT_ROOT = TOOLS_DIR.parent.parent
RECOMP_BIN = PROJECT_ROOT / "SWFRecomp" / "build" / "SWFRecomp"
IR_HPP = PROJECT_ROOT / "SWFRecomp" / "include" / "abc" / "abc_ir.hpp"

# Stage 2 (hello_world) emitter surface — keep in sync with abc_emit.cpp.
STAGE2_OPS = {
    "CallProperty", "CallPropVoid", "CoerceA", "ConstructProp",
    "ConstructSuper", "DebugFile", "DebugLine", "FindPropStrict", "GetLocal",
    "GetPropertyStatic", "GetScopeObject", "InitProperty", "NewClass", "Nop",
    "Pop", "PopScope", "PushInt", "PushScope", "PushString", "ReturnValue",
    "ReturnVoid", "SetLocal",
}


def known_ops():
    """Parse the IrOpcode enum out of abc_ir.hpp."""
    ops = set()
    in_enum = False
    for line in IR_HPP.read_text().splitlines():
        if "enum class IrOpcode" in line:
            in_enum = True
            continue
        if in_enum:
            if line.strip().startswith("}"):
                break
            m = re.match(r"\s*([A-Za-z0-9]+),", line)
            if m:
                ops.add(m.group(1))
    return ops


OP_LINE = re.compile(r"^\s+\d+: ([A-Za-z0-9]+)")


def census_test(swf, valid_ops):
    try:
        proc = subprocess.run(
            [str(RECOMP_BIN), "--dump-abc", str(swf)],
            capture_output=True, text=True, timeout=60, errors="replace")
    except subprocess.TimeoutExpired:
        return None, "dump timeout"
    if proc.returncode != 0:
        return None, f"dump exit {proc.returncode}"
    used = set()
    for line in proc.stdout.splitlines():
        m = OP_LINE.match(line)
        if m and m.group(1) in valid_ops:
            used.add(m.group(1))
    return used, None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--tests-dir", default="ruffle-tests/tests/swfs/avm2")
    ap.add_argument("--implemented", default=None,
                    help="comma-separated op list (default: Stage-2 surface)")
    ap.add_argument("--implemented-file", default=None)
    ap.add_argument("--json", default=None)
    ap.add_argument("--horizon", type=int, default=8,
                    help="greedy unlock: only count tests missing <= N ops")
    ap.add_argument("--filter", default=None,
                    help="only tests whose name matches this regex")
    args = ap.parse_args()

    if args.implemented_file:
        implemented = set(Path(args.implemented_file).read_text().split())
    elif args.implemented:
        implemented = set(args.implemented.split(","))
    else:
        implemented = set(STAGE2_OPS)

    valid_ops = known_ops()
    tests_dir = (PROJECT_ROOT / args.tests_dir).resolve() \
        if not Path(args.tests_dir).is_absolute() else Path(args.tests_dir)

    name_re = re.compile(args.filter) if args.filter else None
    per_test = {}
    errors = {}
    dirs = sorted(d for d in tests_dir.iterdir()
                  if d.is_dir() and (d / "test.swf").exists()
                  and not d.name.startswith("_"))
    for i, d in enumerate(dirs):
        if name_re and not name_re.search(d.name):
            continue
        used, err = census_test(d / "test.swf", valid_ops)
        if err:
            errors[d.name] = err
        else:
            per_test[d.name] = sorted(used)
        if (i + 1) % 200 == 0:
            print(f"  ...{i + 1}/{len(dirs)}", file=sys.stderr)

    # Per-op counts.
    use_count = {}
    block_count = {}
    for name, used in per_test.items():
        missing = set(used) - implemented
        for op in used:
            use_count[op] = use_count.get(op, 0) + 1
        for op in missing:
            block_count[op] = block_count.get(op, 0) + 1

    covered = sorted(n for n, u in per_test.items() if not set(u) - implemented)

    print(f"\n{len(per_test)} tests censused, {len(errors)} dump errors")
    print(f"implemented set: {len(implemented)} ops")
    print(f"statically covered (op-surface ceiling): {len(covered)} tests")

    print("\nTop blocking ops (op: #tests using it that are blocked / #tests using it):")
    for op in sorted(block_count, key=lambda o: -block_count[o])[:40]:
        print(f"  {op:24s} {block_count[op]:5d} / {use_count.get(op, 0)}")

    # Greedy unlock order over near-horizon tests.
    print(f"\nGreedy unlock order (tests missing <= {args.horizon} ops):")
    impl = set(implemented)
    remaining = {n: set(u) - impl for n, u in per_test.items() if set(u) - impl}
    for step in range(30):
        gains = {}
        for n, miss in remaining.items():
            if 0 < len(miss) <= args.horizon:
                for op in miss:
                    gains[op] = gains.get(op, 0) + 1
        if not gains:
            break
        best = max(gains, key=lambda o: (gains[o], o))
        impl.add(best)
        newly = [n for n, miss in remaining.items() if miss == {best}]
        for n in list(remaining):
            remaining[n].discard(best)
            if not remaining[n]:
                del remaining[n]
        ceiling = len(per_test) - len(remaining)
        print(f"  +{best:22s} unlocks {len(newly):4d} more (ceiling {ceiling})")

    if args.json:
        Path(args.json).write_text(json.dumps({
            "implemented": sorted(implemented if not impl else implemented),
            "per_test": per_test,
            "errors": errors,
            "covered": covered,
        }, indent=1))
        print(f"\nwrote {args.json}")


if __name__ == "__main__":
    main()
