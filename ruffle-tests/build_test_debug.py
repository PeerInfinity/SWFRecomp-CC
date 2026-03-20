#!/usr/bin/env python3
"""Build a single test binary and preserve it for debugging.

Usage:
    python3 ruffle-tests/build_test_debug.py --test=TEST_NAME [--tests-dir=DIR] [--output-dir=DIR]

Builds the test into a persistent directory instead of a temp dir.
The binary can then be run directly, attached to with gdb, etc.
"""

import sys
import os
import shutil
import argparse
from pathlib import Path

# Setup paths like verify_output.py does
SCRIPT_DIR = Path(__file__).resolve().parent
PROJECT_ROOT = SCRIPT_DIR.parent
sys.path.insert(0, str(SCRIPT_DIR))

# Import functions from verify_output.py
exec_globals = {"__name__": "not_main", "__file__": str(SCRIPT_DIR / "verify_output.py")}
exec(compile((SCRIPT_DIR / "verify_output.py").read_text(), str(SCRIPT_DIR / "verify_output.py"), "exec"), exec_globals)

compile_native = exec_globals["compile_native"]
get_num_frames = exec_globals["get_num_frames"]
find_child_swfs = exec_globals["find_child_swfs"]

def main():
    parser = argparse.ArgumentParser(description="Build a test binary for debugging")
    parser.add_argument("--test", required=True, help="Test name")
    parser.add_argument("--tests-dir", default=str(SCRIPT_DIR / "tests/swfs/avm1"), help="Tests directory")
    parser.add_argument("--output-dir", default=None, help="Output directory (default: /tmp/swf_debug_TEST)")
    args = parser.parse_args()

    test_dir = Path(args.tests_dir) / args.test
    if not test_dir.exists():
        print(f"Error: test directory not found: {test_dir}")
        sys.exit(1)

    output_dir = Path(args.output_dir) if args.output_dir else Path(f"/tmp/swf_debug_{args.test}")
    if output_dir.exists():
        shutil.rmtree(output_dir)
    output_dir.mkdir(parents=True)

    num_frames = get_num_frames(test_dir, 0, has_input=False)
    print(f"Building {args.test} ({num_frames} frames) -> {output_dir}")

    ok, err = compile_native(test_dir, num_frames, output_dir)
    if not ok:
        print(f"Compilation failed:\n{err}")
        sys.exit(1)

    binary = output_dir / "test_run"
    if binary.exists():
        print(f"\nBinary: {binary}")
        print(f"Run:    TZ='NPT-5:45' {binary}")
        print(f"Debug:  TZ='NPT-5:45' timeout 10 {binary} 2>/dev/null | wc -l")
        print(f"GDB:    TZ='NPT-5:45' gdb {binary}")
    else:
        print("Binary not found after compilation!")
        print("Files in output dir:")
        for f in sorted(output_dir.iterdir()):
            print(f"  {f.name}")
        sys.exit(1)

if __name__ == "__main__":
    main()
