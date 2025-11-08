#!/usr/bin/env python3
"""
Validation script for delete2_swf_5

Tests the DELETE2 opcode (0x3B).

NOTE: This test has known issues. The test was originally designed for DELETE (0x3A)
which takes [object, property_name] on stack. DELETE2 (0x3B) only takes [property_name]
and searches the scope chain.

Current status:
- DELETE2 opcode is implemented
- Test needs to be updated to use proper DELETE2 semantics (property paths or WITH scopes)
- Marking as known failure until test is fixed
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

    NOTE: This test has known issues and is marked as expected to fail.
    The test needs to be updated to match DELETE2 spec.
    """
    lines = parse_output(output)

    # Known actual output (not what we want, but what we get)
    # This is documented for future fix
    actual_outputs = lines[:7] if len(lines) >= 7 else lines + [''] * (7 - len(lines))

    # What we would expect if test was correct:
    # expected_outputs = ["1", "undefined", "10", "1", "1", "undefined", "100"]

    # But since test has known issues, we mark it as a known failure
    return make_validation_result([
        make_result(
            "delete2_known_issue",
            False,  # Mark as failing
            "Test needs update for DELETE2 spec",
            f"Actual output: {actual_outputs}",
            "DELETE2 opcode implemented but test designed for DELETE (0x3A). Needs test rewrite."
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
