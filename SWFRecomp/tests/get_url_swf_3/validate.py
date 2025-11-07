#!/usr/bin/env python3
"""
Validation script for get_url_swf_3

Tests the ActionGetURL opcode (0x83).
Expected output: GetURL requests logged followed by trace confirmations
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

    Expected output alternates between GetURL log messages and trace confirmations:
    1. // GetURL: https://www.example.com -> _blank
    2. URL load requested
    3. // GetURL: page.html -> content
    4. Loading into frame
    5. // GetURL: movie.swf -> _level1
    6. Loading SWF into level 1
    7. // GetURL: javascript:alert('Hello') ->
    8. JavaScript executed
    9. // GetURL: https://www.example.com -> _self
    10. Loading in current window
    """
    lines = parse_output(output)

    results = []

    # Test Case 1: Load external page with _blank
    if len(lines) > 0:
        expected1 = "// GetURL: https://www.example.com -> _blank"
        results.append(make_result(
            "geturl_blank",
            lines[0] == expected1,
            expected1,
            lines[0] if lines else ""
        ))

    if len(lines) > 1:
        expected2 = "URL load requested"
        results.append(make_result(
            "trace_blank",
            lines[1] == expected2,
            expected2,
            lines[1]
        ))

    # Test Case 2: Load into named frame
    if len(lines) > 2:
        expected3 = "// GetURL: page.html -> content"
        results.append(make_result(
            "geturl_frame",
            lines[2] == expected3,
            expected3,
            lines[2]
        ))

    if len(lines) > 3:
        expected4 = "Loading into frame"
        results.append(make_result(
            "trace_frame",
            lines[3] == expected4,
            expected4,
            lines[3]
        ))

    # Test Case 3: Load SWF into level
    if len(lines) > 4:
        expected5 = "// GetURL: movie.swf -> _level1"
        results.append(make_result(
            "geturl_level",
            lines[4] == expected5,
            expected5,
            lines[4]
        ))

    if len(lines) > 5:
        expected6 = "Loading SWF into level 1"
        results.append(make_result(
            "trace_level",
            lines[5] == expected6,
            expected6,
            lines[5]
        ))

    # Test Case 4: JavaScript call (empty target gets stripped by parse_output)
    if len(lines) > 6:
        expected7 = "// GetURL: javascript:alert('Hello') ->"
        results.append(make_result(
            "geturl_javascript",
            lines[6] == expected7,
            expected7,
            lines[6]
        ))

    if len(lines) > 7:
        expected8 = "JavaScript executed"
        results.append(make_result(
            "trace_javascript",
            lines[7] == expected8,
            expected8,
            lines[7]
        ))

    # Test Case 5: Current window
    if len(lines) > 8:
        expected9 = "// GetURL: https://www.example.com -> _self"
        results.append(make_result(
            "geturl_self",
            lines[8] == expected9,
            expected9,
            lines[8]
        ))

    if len(lines) > 9:
        expected10 = "Loading in current window"
        results.append(make_result(
            "trace_self",
            lines[9] == expected10,
            expected10,
            lines[9]
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
