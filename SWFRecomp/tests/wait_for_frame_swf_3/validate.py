#!/usr/bin/env python3
"""
Validation script for wait_for_frame_swf_3

Tests the WAIT_FOR_FRAME opcode (0x8A).

In non-streaming SWFs, all frames are considered loaded (matching Ruffle/Flash).
WaitForFrame clamps the frame number to totalframes, so min(frame, totalframes)
is always <= frames_loaded. Only frames > 16000 are not loaded.

Expected output (7 lines - all frames considered loaded):
  1. "Frame 0 loaded"     - WaitForFrame(0): loaded
  2. "Frame 100 loaded"   - WaitForFrame(100): loaded (clamped to totalframes)
  3. "Skip count 0"       - WaitForFrame(200, skip=0): skip count 0, always traces
  4. "Frame 1 loaded"     - WaitForFrame(1): loaded
  5. "Skip test 1"        - WaitForFrame(300, skip=2): loaded, no skip
  6. "Skip test 2"        - (second trace from test 5, not skipped)
  7. "Continued"          - Final output
"""
import sys
import json
import os

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    lines = parse_output(output)

    expected = [
        ("frame_0", "Frame 0 loaded"),
        ("frame_100", "Frame 100 loaded"),
        ("skip_count_0", "Skip count 0"),
        ("frame_1", "Frame 1 loaded"),
        ("skip_test_2", "Skip test 2"),
        ("skip_test_1", "Skip test 1"),
        ("continued", "Continued"),
    ]

    results = []
    for i, (name, exp) in enumerate(expected):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(name, actual == exp, exp, actual))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
