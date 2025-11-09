#!/usr/bin/env python3
"""
Validation script for wait_for_frame_swf_3

Tests the WAIT_FOR_FRAME opcode (0x8A) with comprehensive edge cases.
Expected output:
  1. "Frame 0 loaded" - WaitForFrame(0) succeeds, frame exists
  2. "Skip count 0" - WaitForFrame(200, skip=0) with non-existent frame but skip count 0
  3. "Frame 1 loaded" - WaitForFrame(1) succeeds, last frame exists
  4. "Continued" - Final output after all tests
"""
import sys
import json
import os

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    """
    Validate test output.

    Expected:
      Line 1: "Frame 0 loaded" (frame 0 exists and is loaded)
      Line 2: "Skip count 0" (skip count 0 doesn't skip even if frame doesn't exist)
      Line 3: "Frame 1 loaded" (frame 1 exists - last frame)
      Line 4: "Continued" (after all tests)
    """
    lines = parse_output(output)

    results = []

    # Test 1: Frame 0 loaded (frame exists)
    expected_1 = "Frame 0 loaded"
    actual_1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "frame_0_exists",
        actual_1 == expected_1,
        expected_1,
        actual_1
    ))

    # Test 2: Skip count 0 (should not skip even if frame doesn't exist)
    expected_2 = "Skip count 0"
    actual_2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "skip_count_0",
        actual_2 == expected_2,
        expected_2,
        actual_2
    ))

    # Test 3: Frame 1 loaded (boundary - last frame)
    expected_3 = "Frame 1 loaded"
    actual_3 = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "frame_1_boundary",
        actual_3 == expected_3,
        expected_3,
        actual_3
    ))

    # Test 4: Continued (after all tests)
    expected_4 = "Continued"
    actual_4 = lines[3] if len(lines) > 3 else ""
    results.append(make_result(
        "continued_after_tests",
        actual_4 == expected_4,
        expected_4,
        actual_4
    ))

    # Ensure no extra output (should not print "Frame 100 loaded", "Skip test 1", "Skip test 2")
    if len(lines) > 4:
        results.append(make_result(
            "no_extra_output",
            False,
            "4 lines",
            f"{len(lines)} lines",
            "Extra output detected - skip logic may be broken"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
