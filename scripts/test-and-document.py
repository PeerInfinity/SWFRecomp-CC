#!/usr/bin/env python3
"""
Run tests and update documentation.

This script runs the test suite and then regenerates the opcode documentation
with the latest test results.
"""

import argparse
import subprocess
import sys
from pathlib import Path

# Base directory
BASE_DIR = Path(__file__).parent.parent


def run_command(cmd, description, cwd=None):
    """Run a command and report results."""
    print("=" * 80)
    print(f"{description}")
    print("=" * 80)
    print(f"Running: {' '.join(cmd)}")
    print()

    try:
        result = subprocess.run(
            cmd,
            cwd=cwd,
            check=True,
            text=True,
            capture_output=False  # Show output in real-time
        )
        print()
        print(f"✓ {description} completed successfully")
        return True
    except subprocess.CalledProcessError as e:
        print()
        print(f"✗ {description} failed with exit code {e.returncode}")
        return False


def main():
    """Main execution flow."""
    # Parse command-line arguments
    parser = argparse.ArgumentParser(
        description="Run tests and update documentation"
    )
    parser.add_argument(
        '--clean',
        action='store_true',
        help='Clean generated files before building tests'
    )
    args = parser.parse_args()

    print("=" * 80)
    print("SWFRecomp Test and Documentation Generator")
    print("=" * 80)
    print()

    # Step 1: Run all tests
    tests_dir = BASE_DIR / "SWFRecomp/tests"
    all_tests_script = tests_dir / "all_tests.sh"

    if not all_tests_script.exists():
        print(f"✗ ERROR: Test script not found: {all_tests_script}")
        sys.exit(1)

    # Build command with optional --clean flag
    test_cmd = [str(all_tests_script)]
    if args.clean:
        test_cmd.append('--clean')

    success = run_command(
        test_cmd,
        "Running test suite",
        cwd=tests_dir
    )

    if not success:
        print()
        print("⚠ WARNING: Tests failed, but continuing with documentation generation...")
        print()

    # Step 2: Build opcode index
    build_script = BASE_DIR / "scripts/build_opcode_index.py"

    if not build_script.exists():
        print(f"✗ ERROR: Build script not found: {build_script}")
        sys.exit(1)

    success = run_command(
        [sys.executable, str(build_script)],
        "Building opcode index",
        cwd=BASE_DIR
    )

    if not success:
        print()
        print("✗ ERROR: Failed to build opcode index")
        sys.exit(1)

    # Step 3: Generate opcode markdown
    generate_script = BASE_DIR / "scripts/generate_opcode_markdown.py"

    if not generate_script.exists():
        print(f"✗ ERROR: Generate script not found: {generate_script}")
        sys.exit(1)

    success = run_command(
        [sys.executable, str(generate_script)],
        "Generating opcode markdown documentation",
        cwd=BASE_DIR
    )

    if not success:
        print()
        print("✗ ERROR: Failed to generate markdown documentation")
        sys.exit(1)

    # Done
    print()
    print("=" * 80)
    print("✓ All steps completed successfully!")
    print("=" * 80)
    print()
    print("Generated files:")
    print(f"  - {BASE_DIR / 'opcode-index.json'}")
    print(f"  - {BASE_DIR / 'opcode-index.md'}")
    print(f"  - {BASE_DIR / 'opcode-index-plain.md'}")
    print(f"  - {tests_dir / 'test_results.json'}")
    print()


if __name__ == '__main__':
    main()
