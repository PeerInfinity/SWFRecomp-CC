#!/usr/bin/env python3
"""
Validation script for throw_swf_7

Tests the THROW opcode (0x2A).
Expected output:
1. "Before throw" - traces before exception
2. "[Uncaught exception: Error message]" - exception handler output
3. Should NOT see "After throw"

This test validates that:
- ActionThrow properly pops value from stack
- Exception terminates execution (code after throw doesn't run)
- Uncaught exceptions are properly reported
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
    - Line 1: "Before throw"
    - Line 2: "[Uncaught exception: Error message]"
    - Should NOT contain: "After throw"
    """
    lines = parse_output(output)
    results = []
    
    # Check that we see the trace before throw
    before_throw_ok = len(lines) > 0 and lines[0] == "Before throw"
    results.append(make_result(
        "trace_before_throw",
        before_throw_ok,
        "Before throw",
        lines[0] if len(lines) > 0 else "(no output)"
    ))
    
    # Check that we see the uncaught exception message
    exception_ok = len(lines) > 1 and "[Uncaught exception: Error message]" in lines[1]
    results.append(make_result(
        "uncaught_exception",
        exception_ok,
        "[Uncaught exception: Error message]",
        lines[1] if len(lines) > 1 else "(no output)"
    ))
    
    # Check that code after throw did NOT execute
    after_throw_text = "After throw"
    execution_stopped = after_throw_text not in output
    results.append(make_result(
        "execution_stopped_after_throw",
        execution_stopped,
        f"Should NOT contain: {after_throw_text}",
        "OK - text not found" if execution_stopped else f"FAIL - found: {after_throw_text}"
    ))
    
    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
