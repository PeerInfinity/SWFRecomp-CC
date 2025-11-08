#!/usr/bin/env python3
"""
Validation script for gotoframe2_swf_5

Tests the GOTO_FRAME2 opcode (stack-based frame navigation).
Expected output: Messages showing frame navigation for both numeric frames and labels
"""
import sys
import json
import os

sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    """
    Validate test output.

    Expected:
    - GotoFrame2 message showing numeric frame navigation
    - Trace message "After GotoFrame2"
    - GotoFrame2 message showing label navigation
    - Trace message "After GotoFrame2 with label"
    """
    lines = parse_output(output)

    results = []

    # Test 1: Numeric frame navigation
    if len(lines) > 0:
        expected = "gotoframe2: frame 2"
        actual = lines[0].lower()
        results.append(make_result(
            "numeric_frame",
            "gotoframe2" in actual and "frame 2" in actual and "play=0" in actual,
            expected,
            lines[0]
        ))

    # Test 2: Trace after numeric goto
    if len(lines) > 1:
        results.append(make_result(
            "trace_after_numeric",
            lines[1] == "After GotoFrame2",
            "After GotoFrame2",
            lines[1] if len(lines) > 1 else ""
        ))

    # Test 3: Label frame navigation
    if len(lines) > 2:
        expected = "gotoframe2: label 'scene2'"
        actual = lines[2].lower()
        results.append(make_result(
            "label_frame",
            "gotoframe2" in actual and "scene2" in actual and "play=1" in actual,
            expected,
            lines[2] if len(lines) > 2 else ""
        ))

    # Test 4: Trace after label goto
    if len(lines) > 3:
        results.append(make_result(
            "trace_after_label",
            lines[3] == "After GotoFrame2 with label",
            "After GotoFrame2 with label",
            lines[3] if len(lines) > 3 else ""
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
