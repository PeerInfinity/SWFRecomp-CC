#!/usr/bin/env python3
"""
Validation script for trace_swf_4

Tests the TRACE opcode (0x26).
Expected output: "sup from SWF 4"

This test validates that the TRACE opcode correctly outputs a string to the console.
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

    Expected: The string "sup from SWF 4" printed to console
    """
    return validate_single_output(output, "sup from SWF 4", "trace_output")


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
