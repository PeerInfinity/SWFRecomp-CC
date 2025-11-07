#!/usr/bin/env python3
"""
Validation script for set_target2_swf_4

Tests the SET_TARGET2 opcode (0x20) - stack-based context switching.
Expected output: SetTarget2 log messages followed by trace outputs.
"""
import sys
import json

def validate_output(output):
    """
    Validate test output.

    Expected output:
    // SetTarget2: mySprite
    In mySprite
    // SetTarget2: (main)
    Back to main
    // SetTarget2: nested/path
    In nested path
    // SetTarget2: (main)
    Final main
    """
    lines = [line.strip() for line in output.strip().split('\n') if line.strip()]

    results = []

    # Test Case 1: Set target to mySprite
    if len(lines) > 0:
        expected = "// SetTarget2: mySprite"
        actual = lines[0] if lines else ""
        results.append({
            "name": "set_target_mySprite",
            "passed": actual == expected,
            "expected": expected,
            "actual": actual
        })

    if len(lines) > 1:
        expected = "In mySprite"
        actual = lines[1] if len(lines) > 1 else ""
        results.append({
            "name": "trace_in_mySprite",
            "passed": actual == expected,
            "expected": expected,
            "actual": actual
        })

    # Test Case 2: Return to main
    if len(lines) > 2:
        expected = "// SetTarget2: (main)"
        actual = lines[2] if len(lines) > 2 else ""
        results.append({
            "name": "set_target_main_1",
            "passed": actual == expected,
            "expected": expected,
            "actual": actual
        })

    if len(lines) > 3:
        expected = "Back to main"
        actual = lines[3] if len(lines) > 3 else ""
        results.append({
            "name": "trace_back_to_main",
            "passed": actual == expected,
            "expected": expected,
            "actual": actual
        })

    # Test Case 3: Set target to nested path
    if len(lines) > 4:
        expected = "// SetTarget2: nested/path"
        actual = lines[4] if len(lines) > 4 else ""
        results.append({
            "name": "set_target_nested",
            "passed": actual == expected,
            "expected": expected,
            "actual": actual
        })

    if len(lines) > 5:
        expected = "In nested path"
        actual = lines[5] if len(lines) > 5 else ""
        results.append({
            "name": "trace_in_nested",
            "passed": actual == expected,
            "expected": expected,
            "actual": actual
        })

    # Test Case 4: Return to main again
    if len(lines) > 6:
        expected = "// SetTarget2: (main)"
        actual = lines[6] if len(lines) > 6 else ""
        results.append({
            "name": "set_target_main_2",
            "passed": actual == expected,
            "expected": expected,
            "actual": actual
        })

    if len(lines) > 7:
        expected = "Final main"
        actual = lines[7] if len(lines) > 7 else ""
        results.append({
            "name": "trace_final_main",
            "passed": actual == expected,
            "expected": expected,
            "actual": actual
        })

    # Overall pass = all sub-tests passed
    overall_passed = all(r["passed"] for r in results) if results else False

    return {
        "passed": overall_passed,
        "sub_tests": results
    }


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
