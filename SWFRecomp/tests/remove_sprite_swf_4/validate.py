#!/usr/bin/env python3
"""
Validation script for remove_sprite_swf_4

Comprehensive tests for the REMOVE_SPRITE opcode (0x25):
- Basic sprite removal
- Non-existent sprite (should not crash)
- Empty string (should handle gracefully)
- Special characters in sprite name
- Path notation (e.g., _root.sprite)
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

    Expected output:
    Line 0: "Test 1: Basic remove"
    Line 1: "Test 2: Non-existent"
    Line 2: "Test 3: Empty string"
    Line 3: "Test 4: Special chars"
    Line 4: "Test 5: Path notation"
    Line 5: "All tests completed"
    """
    lines = parse_output(output)

    results = []

    # Test 1: Basic sprite removal
    expected_line1 = "Test 1: Basic remove"
    actual_line1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "basic_remove",
        actual_line1 == expected_line1,
        expected_line1,
        actual_line1
    ))

    # Test 2: Non-existent sprite (should not crash)
    expected_line2 = "Test 2: Non-existent"
    actual_line2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "nonexistent_sprite",
        actual_line2 == expected_line2,
        expected_line2,
        actual_line2
    ))

    # Test 3: Empty string (should handle gracefully)
    expected_line3 = "Test 3: Empty string"
    actual_line3 = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "empty_string",
        actual_line3 == expected_line3,
        expected_line3,
        actual_line3
    ))

    # Test 4: Special characters
    expected_line4 = "Test 4: Special chars"
    actual_line4 = lines[3] if len(lines) > 3 else ""
    results.append(make_result(
        "special_chars",
        actual_line4 == expected_line4,
        expected_line4,
        actual_line4
    ))

    # Test 5: Path notation
    expected_line5 = "Test 5: Path notation"
    actual_line5 = lines[4] if len(lines) > 4 else ""
    results.append(make_result(
        "path_notation",
        actual_line5 == expected_line5,
        expected_line5,
        actual_line5
    ))

    # Final confirmation
    expected_final = "All tests completed"
    actual_final = lines[5] if len(lines) > 5 else ""
    results.append(make_result(
        "all_tests_completed",
        actual_final == expected_final,
        expected_final,
        actual_final
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
