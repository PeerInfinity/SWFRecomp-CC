#!/usr/bin/env python3
"""
Validation script for implements_op_swf_7

Tests the IMPLEMENTS_OP opcode (0x2C).
This is a smoke test to verify the opcode executes without crashing.

Expected output: "ImplementsOp executed"
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

    Expected: "ImplementsOp executed"
    This confirms that the ImplementsOp opcode executed without crashing.
    """
    return validate_single_output(output, "ImplementsOp executed", "implements_op_smoke_test")


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
