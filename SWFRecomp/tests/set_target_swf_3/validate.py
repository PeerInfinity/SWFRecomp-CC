#!/usr/bin/env python3
"""
Validation script for set_target_swf_3

Tests the ActionSetTarget opcode (0x8B) comprehensively.
Tests:
1. Invalid target (non-existent sprite)
2. Empty string (return to main)
3. _root target
4. / target (root via slash)
5. Invalid nested path
6. Empty string again (return to main)
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

    Expected output for comprehensive edge case testing:
    1. SetTarget "mySprite" - not found (invalid target)
    2. SetTarget "" - return to main
    3. SetTarget "_root" - explicit root
    4. SetTarget "/" - root via slash
    5. SetTarget "invalid/nested/path" - not found (invalid nested path)
    6. SetTarget "" - return to main again
    """
    lines = parse_output(output)

    results = []

    # Test 1: Invalid target (should report "not found, context unchanged")
    expected_1 = "// SetTarget: mySprite (not found, context unchanged)"
    actual_1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "invalid_target_mySprite",
        actual_1 == expected_1,
        expected_1,
        actual_1
    ))

    # Test 2: Return to main (empty string)
    expected_2 = "// SetTarget: (main)"
    actual_2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "return_to_main",
        actual_2 == expected_2,
        expected_2,
        actual_2
    ))

    # Test 3: _root target
    expected_3 = "// SetTarget: _root"
    actual_3 = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "target_root",
        actual_3 == expected_3,
        expected_3,
        actual_3
    ))

    # Test 4: / target (root via slash)
    expected_4 = "// SetTarget: /"
    actual_4 = lines[3] if len(lines) > 3 else ""
    results.append(make_result(
        "target_slash",
        actual_4 == expected_4,
        expected_4,
        actual_4
    ))

    # Test 5: Invalid nested path
    expected_5 = "// SetTarget: invalid/nested/path (not found, context unchanged)"
    actual_5 = lines[4] if len(lines) > 4 else ""
    results.append(make_result(
        "invalid_nested_path",
        actual_5 == expected_5,
        expected_5,
        actual_5
    ))

    # Test 6: Return to main again
    expected_6 = "// SetTarget: (main)"
    actual_6 = lines[5] if len(lines) > 5 else ""
    results.append(make_result(
        "return_to_main_again",
        actual_6 == expected_6,
        expected_6,
        actual_6
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
