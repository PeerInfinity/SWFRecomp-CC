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

    # Define test cases
    test_cases = [
        ("set_target_mySprite", "// SetTarget2: mySprite", 0),
        ("trace_in_mySprite", "In mySprite", 1),
        ("set_target_main_1", "// SetTarget2: (main)", 2),
        ("trace_back_to_main", "Back to main", 3),
        ("set_target_nested", "// SetTarget2: nested/path", 4),
        ("trace_in_nested", "In nested path", 5),
        ("set_target_main_2", "// SetTarget2: (main)", 6),
        ("trace_final_main", "Final main", 7),
    ]

    results = []
    for name, expected, line_idx in test_cases:
        actual = lines[line_idx] if line_idx < len(lines) else ""
        results.append({
            "name": name,
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
