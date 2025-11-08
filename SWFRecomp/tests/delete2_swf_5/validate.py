#!/usr/bin/env python3
"""
Validation script for delete2_swf_5

Tests the DELETE2 opcode (0x3B).
Expected output: 1 (DELETE2 returns true for non-existent properties per Flash spec)

DELETE2 is fully implemented:
- Searches scope chain for named property
- Deletes property if found in scope chain
- Returns false for var declarations (cannot delete)
- Returns true for non-existent properties (Flash behavior)
"""
import sys
import json
import os

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import make_result, make_validation_result


def validate_output(output):
    """
    Validate test output.

    Expected: "1" (DELETE2 returns true for non-existent properties)
    """
    # Filter out runtime debug messages
    filtered_lines = []
    for line in output.split('\n'):
        line = line.strip()
        # Skip runtime messages, frame markers, and empty lines
        if (line and
            'SWF Runtime' not in line and
            '===' not in line and
            not line.startswith('[Frame') and
            not line.startswith('[Tag')):
            filtered_lines.append(line)

    # Test: Delete non-existent property -> 1
    expected = "1"
    actual = filtered_lines[0] if filtered_lines else ""

    return make_validation_result([
        make_result(
            "delete_nonexistent",
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
