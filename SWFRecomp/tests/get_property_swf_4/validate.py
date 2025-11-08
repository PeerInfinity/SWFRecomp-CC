#!/usr/bin/env python3
"""
Validation script for get_property_swf_4

Tests the GET_PROPERTY opcode (0x22) which retrieves MovieClip properties by numeric index.

Expected output:
- Line 1: 100 (_xscale, property index 2)
- Line 2: 100 (_yscale, property index 3)
- Line 3: 1 (_visible, property index 7)
- Line 4: 100 (_alpha, property index 6)
- Line 5: 0 (_x, property index 0)
- Line 6: 0 (_y, property index 1)
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

    Expected: Six property values from _root MovieClip
    """
    lines = parse_output(output)

    # Expected values for each property test
    expected_values = [
        ("100", "xscale_property"),
        ("100", "yscale_property"),
        ("1", "visible_property"),
        ("100", "alpha_property"),
        ("0", "x_property"),
        ("0", "y_property")
    ]

    results = []

    # Validate each output line
    for i, (expected, test_name) in enumerate(expected_values):
        if i < len(lines):
            actual = lines[i]
            passed = actual == expected
            results.append(make_result(test_name, passed, expected, actual))
        else:
            results.append(make_result(
                test_name,
                False,
                expected,
                "missing",
                f"Output line {i+1} is missing"
            ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
