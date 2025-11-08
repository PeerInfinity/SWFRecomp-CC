#!/usr/bin/env python3
"""
Validation script for define_function2_swf_7

Tests the DEFINE_FUNCTION2 opcode (0x8E).
Expected output: "Function defined"

This test validates that the DEFINE_FUNCTION2 opcode can successfully define
a function with register-based parameters without errors. The function body
parsing and calling is not yet fully implemented, so we only verify that the
function definition completes successfully.
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

    Expected: The string "Function defined" printed to console,
    indicating that DEFINE_FUNCTION2 successfully created a function
    with register-based parameters.
    """
    return validate_single_output(output, "Function defined", "function_definition")


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
