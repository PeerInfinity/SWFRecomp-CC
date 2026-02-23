#!/usr/bin/env python3
"""
Validation script for get_url_swf_3

Tests the ActionGetURL opcode (0x83).
Expected output: Trace confirmations after each GetURL call.
The GetURL calls themselves are C comments in generated code and produce no output.
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

    Each GetURL call is followed by a trace confirmation.
    The GetURL opcode itself produces no output (it's a navigation action),
    so we only validate the trace messages.
    """
    lines = parse_output(output)

    results = []

    expected_traces = [
        ("trace_blank", "URL load requested"),
        ("trace_frame", "Loading into frame"),
        ("trace_level", "Loading SWF into level 1"),
        ("trace_javascript", "JavaScript executed"),
        ("trace_self", "Loading in current window"),
        ("trace_empty_url", "Empty URL test"),
        ("trace_empty_target", "Empty target test"),
        ("trace_file_protocol", "File protocol test"),
        ("trace_level5", "Level 5 test"),
        ("trace_special_chars", "Special chars test"),
        ("trace_relative", "Relative URL test"),
        ("trace_parent", "Parent frame test"),
    ]

    if len(lines) < len(expected_traces):
        return make_validation_result([
            make_result(
                "output_line_count",
                False,
                str(len(expected_traces)),
                str(len(lines)),
                f"Expected {len(expected_traces)} lines of output, got {len(lines)}"
            )
        ])

    for i, (test_name, expected_line) in enumerate(expected_traces):
        results.append(make_result(
            test_name,
            lines[i] == expected_line,
            expected_line,
            lines[i] if i < len(lines) else "(missing)"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
