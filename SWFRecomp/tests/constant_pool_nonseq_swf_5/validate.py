#!/usr/bin/env python3
"""
Validation script for constant_pool_nonseq_swf_5

Tests non-sequential access to constant pool indices.
Expected output: c, e, a, d, b (indices 2, 4, 0, 3, 1)
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

    Expected:
    c
    e
    a
    d
    b
    """
    lines = parse_output(output)

    expected = ["c", "e", "a", "d", "b"]
    results = []

    # Check we have exactly 5 lines
    if len(lines) != 5:
        results.append(make_result(
            "output_count",
            False,
            "5 lines",
            f"{len(lines)} lines",
            f"Expected 5 output lines, got {len(lines)}"
        ))
        while len(lines) < 5:
            lines.append("")
    else:
        results.append(make_result("output_count", True, "5 lines", "5 lines"))

    # Check each output line
    test_names = ["index_2", "index_4", "index_0", "index_3", "index_1"]
    for i, (name, exp) in enumerate(zip(test_names, expected)):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(name, actual == exp, exp, actual))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
