#!/usr/bin/env python3
"""
Validation script for call_swf_4

Tests the CALL opcode (0x9E).
Expected output:
  Line: continued

The test demonstrates that:
1. CALL opcode pops a frame identifier from the stack
2. ActionCall now actually executes frames (not just logging)
3. Since frame 2 doesn't exist, CALL does nothing (per spec)
4. Execution continues after the CALL
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
      Line: continued

    Note: ActionCall now actually executes frames. Since frame 2 doesn't exist
    in this single-frame SWF, ActionCall does nothing (per spec), and execution
    continues directly to the TRACE statement.
    """
    lines = parse_output(output)

    # Filter out system/runtime messages to get actual trace output
    filtered_lines = [
        line for line in lines
        if not line.startswith('SWF Runtime') and
           not line.startswith('===') and
           not line.startswith('[Frame') and
           not line.startswith('[Tag]')
    ]

    results = []

    # Validation: Check that execution continues after CALL
    expected_continued = "continued"
    actual_continued = filtered_lines[0] if len(filtered_lines) > 0 else ""
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
