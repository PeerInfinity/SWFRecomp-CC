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
    11. // GetURL:  -> _blank (empty URL edge case)
    12. Empty URL test
    13. // GetURL: https://www.example.com -> (empty target edge case)
    14. Empty target test
    15. // GetURL: file:///path/to/file.html -> _self
    16. File protocol test
    17. // GetURL: app.swf -> _level5
    18. Level 5 test
    19. // GetURL: https://example.com/page?foo=bar&baz=qux#anchor -> _top
    20. Special chars test
    21. // GetURL: ../parent/page.html -> contentFrame
    22. Relative URL test
    23. // GetURL: https://www.example.com/page -> _parent
    24. Parent frame test
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

    # Test Case 6: Empty URL
    if len(lines) > 10:
        expected11 = "// GetURL:  -> _blank"
        results.append(make_result(
            "geturl_empty_url",
            lines[10] == expected11,
            expected11,
            lines[10]
        ))

    if len(lines) > 11:
        expected12 = "Empty URL test"
        results.append(make_result(
            "trace_empty_url",
            lines[11] == expected12,
            expected12,
            lines[11]
        ))

    # Test Case 7: Empty target
    if len(lines) > 12:
        expected13 = "// GetURL: https://www.example.com ->"
        results.append(make_result(
            "geturl_empty_target",
            lines[12] == expected13,
            expected13,
            lines[12]
        ))

    if len(lines) > 13:
        expected14 = "Empty target test"
        results.append(make_result(
            "trace_empty_target",
            lines[13] == expected14,
            expected14,
            lines[13]
        ))

    # Test Case 8: File protocol
    if len(lines) > 14:
        expected15 = "// GetURL: file:///path/to/file.html -> _self"
        results.append(make_result(
            "geturl_file_protocol",
            lines[14] == expected15,
            expected15,
            lines[14]
        ))

    if len(lines) > 15:
        expected16 = "File protocol test"
        results.append(make_result(
            "trace_file_protocol",
            lines[15] == expected16,
            expected16,
            lines[15]
        ))

    # Test Case 9: Level 5
    if len(lines) > 16:
        expected17 = "// GetURL: app.swf -> _level5"
        results.append(make_result(
            "geturl_level5",
            lines[16] == expected17,
            expected17,
            lines[16]
        ))

    if len(lines) > 17:
        expected18 = "Level 5 test"
        results.append(make_result(
            "trace_level5",
            lines[17] == expected18,
            expected18,
            lines[17]
        ))

    # Test Case 10: Special characters in URL
    if len(lines) > 18:
        expected19 = "// GetURL: https://example.com/page?foo=bar&baz=qux#anchor -> _top"
        results.append(make_result(
            "geturl_special_chars",
            lines[18] == expected19,
            expected19,
            lines[18]
        ))

    if len(lines) > 19:
        expected20 = "Special chars test"
        results.append(make_result(
            "trace_special_chars",
            lines[19] == expected20,
            expected20,
            lines[19]
        ))

    # Test Case 11: Relative URL
    if len(lines) > 20:
        expected21 = "// GetURL: ../parent/page.html -> contentFrame"
        results.append(make_result(
            "geturl_relative",
            lines[20] == expected21,
            expected21,
            lines[20]
        ))

    if len(lines) > 21:
        expected22 = "Relative URL test"
        results.append(make_result(
            "trace_relative",
            lines[21] == expected22,
            expected22,
            lines[21]
        ))

    # Test Case 12: Parent frame
    if len(lines) > 22:
        expected23 = "// GetURL: https://www.example.com/page -> _parent"
        results.append(make_result(
            "geturl_parent",
            lines[22] == expected23,
            expected23,
            lines[22]
        ))

    if len(lines) > 23:
        expected24 = "Parent frame test"
        results.append(make_result(
            "trace_parent",
            lines[23] == expected24,
            expected24,
            lines[23]
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
