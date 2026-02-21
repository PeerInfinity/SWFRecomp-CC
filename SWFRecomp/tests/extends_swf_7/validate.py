#!/usr/bin/env python3
"""
Validation script for extends_swf_7

Tests the EXTENDS opcode (0x69) which sets up prototype-based inheritance
between constructor functions in ActionScript 2.0.

Expected output:
  EXTENDS test started
  Step 1: Creating constructors
  Step 2: Calling EXTENDS
  Step 3: Checking constructor property
  false
  Step 4: Checking __proto__ property
  true
  EXTENDS completed successfully
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

    Expected lines in order:
      0: "EXTENDS test started"
      1: "Step 1: Creating constructors"
      2: "Step 2: Calling EXTENDS"
      3: "Step 3: Checking constructor property"
      4: "false"  (SWF7 traces booleans as "true"/"false")
      5: "Step 4: Checking __proto__ property"
      6: "true"
      7: "EXTENDS completed successfully"
    """
    lines = parse_output(output)

    expected_lines = [
        "EXTENDS test started",
        "Step 1: Creating constructors",
        "Step 2: Calling EXTENDS",
        "Step 3: Checking constructor property",
        "false",  # Constructor property comparison fails (SWF7 traces booleans as "true"/"false")
        "Step 4: Checking __proto__ property",
        "true",  # Prototype chain works (SWF7 traces booleans as "true"/"false")
        "EXTENDS completed successfully"
    ]

    if len(lines) < len(expected_lines):
        return make_validation_result([
            make_result(
                "extends_output_count",
                False,
                f"{len(expected_lines)} lines",
                f"{len(lines)} lines",
                f"Expected {len(expected_lines)} output lines, got {len(lines)}"
            )
        ])

    results = []

    # Check each expected line
    test_names = [
        "test_started",
        "step1_creating_constructors",
        "step2_calling_extends",
        "step3_checking_constructor",
        "constructor_check_result",
        "step4_checking_proto",
        "proto_check_result",
        "test_completed"
    ]

    for i, (test_name, expected) in enumerate(zip(test_names, expected_lines)):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(
            test_name,
            actual == expected,
            expected,
            actual
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
