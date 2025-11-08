#!/usr/bin/env python3
"""
Validation script for enumerate2_swf_6

Tests the ENUMERATE2 opcode (0x55).

Expected output:
- Three property names from {a: 1, b: 2, c: 3} enumerated in reverse order: c, b, a
- undefined (the enumeration terminator)
- Done (completion message)
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

    Expected output (in order):
    1. c (third property)
    2. b (second property)
    3. a (first property)
    4. undefined (terminator)
    5. Done (completion message)
    """
    lines = parse_output(output)

    results = []

    # Check we have at least 5 lines of output
    if len(lines) < 5:
        return make_validation_result([
            make_result(
                "output_count",
                False,
                "5 lines",
                f"{len(lines)} lines",
                "Expected 5 lines of output (c, b, a, undefined, Done)"
            )
        ])

    # Validate each expected output
    results.append(make_result("property_c", lines[0] == "c", "c", lines[0]))
    results.append(make_result("property_b", lines[1] == "b", "b", lines[1]))
    results.append(make_result("property_a", lines[2] == "a", "a", lines[2]))
    results.append(make_result("terminator", lines[3] == "undefined", "undefined", lines[3]))
    results.append(make_result("completion", lines[4] == "Done", "Done", lines[4]))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
