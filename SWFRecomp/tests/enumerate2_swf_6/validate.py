#!/usr/bin/env python3
"""
Validation script for enumerate2_swf_6

Tests the ENUMERATE2 opcode (0x55).

Expected output:
- Three property names from {a: 1, b: 2, c: 3} in any order
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

    Expected output (property order is implementation-defined):
    1-3. a, b, c (in any order)
    4. undefined (terminator)
    5. Done (completion message)
    """
    lines = parse_output(output)

    results = []

    if len(lines) < 5:
        return make_validation_result([
            make_result(
                "output_count",
                False,
                "5 lines",
                f"{len(lines)} lines",
                "Expected 5 lines of output (a/b/c in any order, undefined, Done)"
            )
        ])

    # Properties can be in any order
    prop_lines = set(lines[0:3])
    expected_props = {"a", "b", "c"}
    results.append(make_result(
        "property_names",
        prop_lines == expected_props,
        str(expected_props),
        str(prop_lines),
        "Enumerated property names should be {a, b, c}"
    ))
    results.append(make_result("terminator", lines[3] == "undefined", "undefined", lines[3]))
    results.append(make_result("completion", lines[4] == "Done", "Done", lines[4]))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
