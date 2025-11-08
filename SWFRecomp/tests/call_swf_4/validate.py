#!/usr/bin/env python3
"""
Validation script for call_swf_4

Tests the CALL opcode (0x9E).
Expected output:
  Line 1: // Call frame 2
  Line 2: continued

The test demonstrates that:
1. CALL opcode pops a frame identifier from the stack
2. The simplified implementation logs the call
3. Execution continues after the call
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
      Line 1: // Call frame 2
      Line 2: continued
    """
    lines = parse_output(output)

    results = []

    # Validation 1: Check first line (call log)
    expected_call = "// Call frame 2"
    actual_call = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "call_log",
        actual_call == expected_call,
        expected_call,
        actual_call
    ))

    # Validation 2: Check second line (continuation)
    expected_continued = "continued"
    actual_continued = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "execution_continued",
        actual_continued == expected_continued,
        expected_continued,
        actual_continued
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
