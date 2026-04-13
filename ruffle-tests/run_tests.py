#!/usr/bin/env python3
"""Run SWFRecomp against all Ruffle AVM1 test SWFs and report results."""

import os
import subprocess
import sys
from pathlib import Path
from collections import Counter

SCRIPT_DIR = Path(__file__).parent
TESTS_DIR = SCRIPT_DIR / "tests" / "swfs" / "avm1"
RECOMP = SCRIPT_DIR.parent / "SWFRecomp" / "build" / "SWFRecomp"
CONFIG = SCRIPT_DIR / "_shared" / "config.toml"

SKIP = {"__framework__"}

# Directories that the recursive walker must not descend into.
DISCOVERY_SKIP_DIRS = {
    "__framework__",
    "_investigation",
    "_image-test-output",
    "_results",
    "RecompiledScripts",
    "RecompiledTags",
}


def discover_tests(tests_dir):
    """Walk tests_dir recursively and return a sorted list of relative test
    names (posix-style). A directory is a test iff it contains test.swf.
    Stops descending once a test is found (tests don't nest)."""
    results = []

    def _walk(current):
        if (current / "test.swf").exists():
            rel = current.relative_to(tests_dir).as_posix()
            if rel and rel != ".":
                results.append(rel)
            return
        try:
            children = sorted(current.iterdir())
        except (NotADirectoryError, PermissionError):
            return
        for child in children:
            if not child.is_dir():
                continue
            if child.name in DISCOVERY_SKIP_DIRS or child.name in SKIP:
                continue
            _walk(child)

    _walk(tests_dir)
    return sorted(results)


def main():
    global TESTS_DIR

    # Support --tests-dir=DIR to override test directory
    for arg in sys.argv[1:]:
        if arg.startswith("--tests-dir="):
            TESTS_DIR = Path(arg.split("=", 1)[1]).resolve()

    if not RECOMP.exists():
        print(f"Recompiler not found at {RECOMP}")
        sys.exit(1)

    if not TESTS_DIR.is_dir():
        print(f"Tests directory not found: {TESTS_DIR}")
        print("Run download_tests.sh first.")
        sys.exit(1)

    tests = discover_tests(TESTS_DIR)

    passed = []
    failed = []
    errors = Counter()

    for name in tests:
        test_dir = TESTS_DIR / name
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
