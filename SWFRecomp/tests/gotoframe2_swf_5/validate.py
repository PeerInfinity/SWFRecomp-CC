#!/usr/bin/env python3
"""
Validation script for gotoframe2_swf_5

Tests the GOTO_FRAME2 opcode (stack-based frame navigation).
Tests:
1. Basic numeric frame
2. String label
3. Negative frame (edge case)
4. Target path with numeric frame
5. Target path with label

Note: Scene bias feature (for multi-scene Flash movies) is implemented
but not tested as it requires more complex SWF generation.
"""
import sys
import json
import os

sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    """
    Validate test output for comprehensive GotoFrame2 testing.
    """
    lines = parse_output(output)

    results = []

    # Test 1: Numeric frame navigation (frame 2, play=0)
    if len(lines) > 0:
        actual = lines[0].lower()
        results.append(make_result(
            "numeric_frame",
            "gotoframe2" in actual and "frame 2" in actual and "play=0" in actual,
            "GotoFrame2: frame 2 (play=0)",
            lines[0]
        ))

    # Test 1 trace
    if len(lines) > 1:
        results.append(make_result(
            "trace_after_numeric",
            lines[1] == "After numeric frame",
            "After numeric frame",
            lines[1]
        ))

    # Test 2: Label navigation (scene2, play=1)
    if len(lines) > 2:
        actual = lines[2].lower()
        results.append(make_result(
            "label_frame",
            "gotoframe2" in actual and "scene2" in actual and "play=1" in actual,
            "GotoFrame2: label 'scene2' (play=1)",
            lines[2]
        ))

    # Test 2 trace
    if len(lines) > 3:
        results.append(make_result(
            "trace_after_label",
            lines[3] == "After label",
            "After label",
            lines[3]
        ))

    # Test 3: Negative frame (should be clamped to 0)
    if len(lines) > 4:
        actual = lines[4].lower()
        results.append(make_result(
            "negative_frame",
            "gotoframe2" in actual and "frame 0" in actual and "play=0" in actual,
            "GotoFrame2: frame 0 (play=0) [negative clamped]",
            lines[4]
        ))

    # Test 3 trace
    if len(lines) > 5:
        results.append(make_result(
            "trace_after_negative",
            lines[5] == "After negative frame",
            "After negative frame",
            lines[5]
        ))

    # Test 4: Target path with numeric frame (/MovieClip:3)
    if len(lines) > 6:
        actual = lines[6].lower()
        results.append(make_result(
            "target_path_numeric",
            "gotoframe2" in actual and "target" in actual and "movieclip" in actual and "frame 3" in actual,
            "GotoFrame2: target '/MovieClip', frame 3 (play=0)",
            lines[6]
        ))

    # Test 4 trace
    if len(lines) > 7:
        results.append(make_result(
            "trace_after_target_numeric",
            lines[7] == "After target path numeric",
            "After target path numeric",
            lines[7]
        ))

    # Test 5: Target path with label (/MovieClip:myLabel)
    if len(lines) > 8:
        actual = lines[8].lower()
        results.append(make_result(
            "target_path_label",
            "gotoframe2" in actual and "target" in actual and "movieclip" in actual and "mylabel" in actual and "play=1" in actual,
            "GotoFrame2: target '/MovieClip', label 'myLabel' (play=1)",
            lines[8]
        ))

    # Test 5 trace
    if len(lines) > 9:
        results.append(make_result(
            "trace_after_target_label",
            lines[9] == "After target path label",
            "After target path label",
            lines[9]
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
