#!/usr/bin/env python3
"""
Validation script for enumerate_swf_4

Tests the ENUMERATE opcode (0x46).
Expected output: property names "a", "b", "c" in some order, followed by completion message
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
    Validate test output for ENUMERATE opcode.

    Expected output:
      a
      b
      c
      Enumeration test complete

    Property names may appear in any order (enumeration order is implementation-defined).
    """
    lines = parse_output(output)

    if len(lines) < 4:
        return make_validation_result([
            make_result(
                "output_count",
                False,
                "4 lines",
                f"{len(lines)} lines",
                "Expected 3 property names + completion message"
            )
        ])

    results = []

    # Check that first 3 lines are the property names (in any order)
    property_names = set(lines[0:3])
    expected_properties = {"a", "b", "c"}

    properties_match = property_names == expected_properties
    results.append(make_result(
        "property_names",
        properties_match,
        "a, b, c (any order)",
        ", ".join(sorted(property_names)),
        None if properties_match else f"Missing: {expected_properties - property_names}, Extra: {property_names - expected_properties}"
    ))

    # Check completion message
    expected_completion = "Enumeration test complete"
    actual_completion = lines[3] if len(lines) > 3 else ""

    results.append(make_result(
        "completion_message",
        actual_completion == expected_completion,
        expected_completion,
        actual_completion
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
