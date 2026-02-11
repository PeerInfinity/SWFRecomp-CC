#!/usr/bin/env python3
"""Run SWFRecomp against all Ruffle AVM1 test SWFs and report results."""

import os
import subprocess
import sys
from pathlib import Path
from collections import Counter

SCRIPT_DIR = Path(__file__).parent
RECOMP = SCRIPT_DIR.parent / "SWFRecomp" / "build" / "SWFRecomp"
CONFIG = SCRIPT_DIR / "_shared" / "config.toml"

SKIP = {"_shared", "__framework__"}

def main():
    if not RECOMP.exists():
        print(f"Recompiler not found at {RECOMP}")
        sys.exit(1)

    tests = sorted(
        d.name for d in SCRIPT_DIR.iterdir()
        if d.is_dir() and d.name not in SKIP and (d / "test.swf").exists()
    )

    passed = []
    failed = []
    errors = Counter()

    for name in tests:
        test_dir = SCRIPT_DIR / name
        try:
            result = subprocess.run(
                ["bash", "-c", "ulimit -v 4194304; exec \"$@\"", "--",
                 str(RECOMP), str(CONFIG)],
                cwd=str(test_dir),
                capture_output=True,
                text=True,
                timeout=30,
            )
        except subprocess.TimeoutExpired:
            failed.append(name)
            errors["timeout"] += 1
            continue

        if result.returncode == 0:
            passed.append(name)
        else:
            failed.append(name)
            combined = result.stdout + result.stderr
            # Categorize the error
            for line in combined.splitlines():
                if "Undefined push type:" in line:
                    errors[line.strip()] += 1
                    break
                elif "Constant pool index" in line:
                    errors["Constant pool index out of range"] += 1
                    break
                elif "Unimplemented action" in line:
                    errors[line.strip()] += 1
                    break
                elif "Tag type" in line and "not implemented" in line:
                    errors[line.strip()] += 1
                    break
            else:
                if result.returncode == -11 or result.returncode == 139:
                    errors["segfault"] += 1
                else:
                    errors[f"unknown (rc={result.returncode})"] += 1

    print(f"\nTotal: {len(tests)}")
    print(f"Pass:  {len(passed)} ({100*len(passed)/len(tests):.1f}%)")
    print(f"Fail:  {len(failed)}")
    print(f"\nFailure breakdown:")
    for reason, count in errors.most_common():
        print(f"  {count:4d}  {reason}")

    if "--list-pass" in sys.argv:
        print(f"\nPassing tests:")
        for name in passed:
            print(f"  {name}")

    if "--list-fail" in sys.argv:
        print(f"\nFailing tests:")
        for name in failed:
            print(f"  {name}")

if __name__ == "__main__":
    main()
