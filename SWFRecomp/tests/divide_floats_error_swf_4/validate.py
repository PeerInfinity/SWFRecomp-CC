#!/usr/bin/env python3
"""
Validation script for divide_floats_error_swf_4

Tests the DIVIDE opcode (0x0D) with various cases including:
- Basic division
- Floating point division
- Division by zero (Infinity)
- Negative division by zero (-Infinity)
- Zero divided by zero (NaN)
- Fractional division
"""
import sys
import json
import os
import math

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    """
    Validate test output.

    Expected outputs (in order) for SWF 4:
    1. 15 / 3 = 5
    2. 10 / 4 = 2.5
    3. 5 / 0 = #ERROR# (SWF 4 doesn't support Infinity)
    4. -5 / 0 = #ERROR#
    5. 0 / 0 = #ERROR# (SWF 4 doesn't support NaN)
    6. 1 / 3 = 0.333333...
    """
    lines = parse_output(output)
    results = []

    # Ensure we have at least 6 lines of output
    if len(lines) < 6:
        return make_validation_result([
            make_result(
                "output_count",
                False,
                "6 lines",
                f"{len(lines)} lines",
                "Expected 6 test outputs"
            )
        ])

    # Test Case 1: Basic Division (15 / 3 = 5)
    expected_1 = "5"
    actual_1 = lines[0]
    results.append(make_result(
        "basic_division_15_3",
        actual_1 == expected_1,
        expected_1,
        actual_1
    ))

    # Test Case 2: Floating Point Result (10 / 4 = 2.5)
    expected_2 = "2.5"
    actual_2 = lines[1]
    results.append(make_result(
        "float_division_10_4",
        actual_2 == expected_2,
        expected_2,
        actual_2
    ))

    # Test Case 3: Division by Zero (5 / 0 = #ERROR# in SWF 4)
    expected_3 = "#ERROR#"
    actual_3 = lines[2]
    results.append(make_result(
        "division_by_zero_5_0",
        actual_3 == expected_3,
        expected_3,
        actual_3
    ))

    # Test Case 4: Negative Division by Zero (-5 / 0 = #ERROR# in SWF 4)
    expected_4 = "#ERROR#"
    actual_4 = lines[3]
    results.append(make_result(
        "neg_division_by_zero_-5_0",
        actual_4 == expected_4,
        expected_4,
        actual_4
    ))

    # Test Case 5: Zero Divided by Zero (0 / 0 = #ERROR# in SWF 4)
    expected_5 = "#ERROR#"
    actual_5 = lines[4]
    results.append(make_result(
        "zero_divided_by_zero_0_0",
        actual_5 == expected_5,
        expected_5,
        actual_5
    ))

    # Test Case 6: Fractional Division (1 / 3 = 0.333333...)
    actual_6 = lines[5]
    # Parse as float and check if it's approximately 0.333333
    try:
        float_value = float(actual_6)
        expected_value = 1.0 / 3.0
        # Check if within a small tolerance (0.000001)
        is_close = abs(float_value - expected_value) < 0.000001
        results.append(make_result(
            "fractional_division_1_3",
            is_close,
            "0.333333",
            actual_6
        ))
    except ValueError:
        results.append(make_result(
            "fractional_division_1_3",
            False,
            "0.333333",
            actual_6,
            "Could not parse as float"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
