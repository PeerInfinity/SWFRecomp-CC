#!/usr/bin/env python3
"""
Validation script for constant_pool_large_swf_5

Tests large constant pool (300 strings) with push type 9 (16-bit indices).
Expected output: str_000, str_255, str_256, str_299
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
    str_000
    str_255
    str_256
    str_299
    """
    lines = parse_output(output)

    expected = ["str_000", "str_255", "str_256", "str_299"]
    results = []

    # Check we have exactly 4 lines
    if len(lines) != 4:
        results.append(make_result(
            "output_count",
            False,
            "4 lines",
            f"{len(lines)} lines",
            f"Expected 4 output lines, got {len(lines)}"
        ))
        while len(lines) < 4:
            lines.append("")
    else:
        results.append(make_result("output_count", True, "4 lines", "4 lines"))

    # Check each output line
    test_names = ["index_0", "index_255", "index_256_16bit", "index_299"]
    for i, (name, exp) in enumerate(zip(test_names, expected)):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(name, actual == exp, exp, actual))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
