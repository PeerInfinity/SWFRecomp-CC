#!/usr/bin/env python3
"""
Validation script for get_time_swf_5

Tests the GET_TIME opcode (0x34).
Expected output: Two time values in milliseconds since runtime start
- Both values should be >= 0
- Both values should be < 5000ms (reasonable upper bound for quick test)
- Second value should be >= first value (time only moves forward)
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
    - Line 0: "Time (ms): " (label)
    - Line 1: First time value (ms)
    - Line 2: Second time value (ms)

    Validation:
    - Both time values should be >= 0
    - Both time values should be < 5000 (5 seconds - very generous for a quick test)
    - Second time >= first time (monotonic)
    """
    lines = parse_output(output)

    results = []

    # Check we have enough lines
    if len(lines) < 3:
        return make_validation_result([
            make_result(
                "output_format",
                False,
                "At least 3 lines (label + 2 time values)",
                f"Got {len(lines)} lines",
                "Insufficient output lines"
            )
        ])

    # Line 0 should be the label
    if lines[0] != "Time (ms):":
        results.append(make_result(
            "label",
            False,
            "Time (ms):",
            lines[0],
            "Label mismatch"
        ))
    else:
        results.append(make_result(
            "label",
            True,
            "Time (ms):",
            lines[0]
        ))

    # Parse first time value
    try:
        time1 = float(lines[1])
        time1_valid = 0 <= time1 < 5000
        results.append(make_result(
            "time1_range",
            time1_valid,
            "[0, 5000)",
            f"{time1}",
            None if time1_valid else "Time value out of expected range"
        ))
    except (ValueError, IndexError):
        results.append(make_result(
            "time1_range",
            False,
            "[0, 5000)",
            lines[1] if len(lines) > 1 else "missing",
            "Could not parse as number"
        ))
        time1 = None

    # Parse second time value
    try:
        time2 = float(lines[2])
        time2_valid = 0 <= time2 < 5000
        results.append(make_result(
            "time2_range",
            time2_valid,
            "[0, 5000)",
            f"{time2}",
            None if time2_valid else "Time value out of expected range"
        ))
    except (ValueError, IndexError):
        results.append(make_result(
            "time2_range",
            False,
            "[0, 5000)",
            lines[2] if len(lines) > 2 else "missing",
            "Could not parse as number"
        ))
        time2 = None

    # Check monotonicity (time2 >= time1)
    if time1 is not None and time2 is not None:
        monotonic = time2 >= time1
        results.append(make_result(
            "monotonic",
            monotonic,
            f"time2 ({time2}) >= time1 ({time1})",
            f"time2={time2}, time1={time1}",
            None if monotonic else "Time moved backwards"
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
