#!/usr/bin/env python3
"""
Validation script for with_swf_5

Tests the WITH opcode (0x94).

Expected behavior:
  var obj = {x: 10, y: 20};
  with (obj) {
    trace(x); // Should output: 10 (looks up obj.x via scope chain)
    trace(y); // Should output: 20 (looks up obj.y via scope chain)
  }

Expected output:
  10
  20
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

    Expected: Two lines with values 10 and 20
    """
    lines = parse_output(output)

    results = []

    # Check we have exactly 2 lines of output
    if len(lines) < 2:
        return make_validation_result([
            make_result(
                "output_count",
                False,
                "2 lines",
                f"{len(lines)} lines",
                "Expected 2 trace outputs"
            )
        ])

    # Check first output (x property)
    results.append(make_result(
        "with_property_x",
        lines[0] == "10",
        "10",
        lines[0]
    ))

    # Check second output (y property)
    results.append(make_result(
        "with_property_y",
        lines[1] == "20",
        "20",
        lines[1]
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
