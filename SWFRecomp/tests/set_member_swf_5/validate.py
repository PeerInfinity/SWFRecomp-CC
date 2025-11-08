#!/usr/bin/env python3
"""
Validation script for set_member_swf_5

Tests the SET_MEMBER opcode (0x4F).
Expected output: 42

Test sequence:
1. Create empty object
2. Set property obj.x = 42
3. Get property obj.x
4. Trace the value
"""
import sys
import json
import os

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import validate_single_output


def validate_output(output):
    """
    Validate test output.

    Expected: 42
    """
    return validate_single_output(output, "42", "set_property_and_get")


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
