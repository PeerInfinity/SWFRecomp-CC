#!/usr/bin/env python3
"""
Validation script for start_drag_swf_4

Tests the START_DRAG opcode (0x27) with comprehensive edge cases.
Expected output: Test cases demonstrating basic drag, lock center, constrained drag, and type conversions
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

    Expected outputs:
    - Test Case 1: "Drag started"
    - Test Case 2: "Before drag", "After drag"
    - Test Case 3: "Constrained drag started"
    - Test Case 4: "Numeric target" (type conversion: number to string)
    - Test Case 5: "String flags" (type conversion: strings to numbers for booleans)
    - Test Case 6: "String coordinates" (type conversion: strings to numbers for coordinates)
    - Test Case 7: "Empty target" (edge case: empty string)
    """
    lines = parse_output(output)

    results = []

    # Test Case 1: Basic drag
    if len(lines) >= 1:
        results.append(make_result(
            "basic_drag",
            lines[0] == "Drag started",
            "Drag started",
            lines[0] if len(lines) >= 1 else ""
        ))
    else:
        results.append(make_result(
            "basic_drag",
            False,
            "Drag started",
            "",
            "No output received"
        ))

    # Test Case 2: Lock center (Before drag)
    if len(lines) >= 2:
        results.append(make_result(
            "lock_center_before",
            lines[1] == "Before drag",
            "Before drag",
            lines[1]
        ))
    else:
        results.append(make_result(
            "lock_center_before",
            False,
            "Before drag",
            "",
            "Missing output line 2"
        ))

    # Test Case 2: Lock center (After drag)
    if len(lines) >= 3:
        results.append(make_result(
            "lock_center_after",
            lines[2] == "After drag",
            "After drag",
            lines[2]
        ))
    else:
        results.append(make_result(
            "lock_center_after",
            False,
            "After drag",
            "",
            "Missing output line 3"
        ))

    # Test Case 3: Constrained drag
    if len(lines) >= 4:
        results.append(make_result(
            "constrained_drag",
            lines[3] == "Constrained drag started",
            "Constrained drag started",
            lines[3]
        ))
    else:
        results.append(make_result(
            "constrained_drag",
            False,
            "Constrained drag started",
            "",
            "Missing output line 4"
        ))

    # Test Case 4: Numeric target (type conversion)
    if len(lines) >= 5:
        results.append(make_result(
            "type_conversion_numeric_target",
            lines[4] == "Numeric target",
            "Numeric target",
            lines[4]
        ))
    else:
        results.append(make_result(
            "type_conversion_numeric_target",
            False,
            "Numeric target",
            "",
            "Missing output line 5"
        ))

    # Test Case 5: String boolean flags (type conversion)
    if len(lines) >= 6:
        results.append(make_result(
            "type_conversion_string_flags",
            lines[5] == "String flags",
            "String flags",
            lines[5]
        ))
    else:
        results.append(make_result(
            "type_conversion_string_flags",
            False,
            "String flags",
            "",
            "Missing output line 6"
        ))

    # Test Case 6: String coordinates (type conversion)
    if len(lines) >= 7:
        results.append(make_result(
            "type_conversion_string_coords",
            lines[6] == "String coordinates",
            "String coordinates",
            lines[6]
        ))
    else:
        results.append(make_result(
            "type_conversion_string_coords",
            False,
            "String coordinates",
            "",
            "Missing output line 7"
        ))

    # Test Case 7: Empty target (edge case)
    if len(lines) >= 8:
        results.append(make_result(
            "edge_case_empty_target",
            lines[7] == "Empty target",
            "Empty target",
            lines[7]
        ))
    else:
        results.append(make_result(
            "edge_case_empty_target",
            False,
            "Empty target",
            "",
            "Missing output line 8"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
