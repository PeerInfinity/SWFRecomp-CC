#!/usr/bin/env python3
"""
Validation script for target_path_swf_5

Tests the TARGET_PATH opcode (0x45).
Expected output:
- Empty string from targetPath(42)
- Message "targetPath(42) test complete"
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
    - Empty string from targetPath(42) (filtered out as empty line)
    - "targetPath(42) test complete"

    Note: parse_output filters empty lines, so we only expect one non-empty line.
    The fact that we get only the completion message (and not some other output)
    indirectly validates that targetPath(42) returned an empty string.
    """
    lines = parse_output(output)

    results = []

    # Test: We should get exactly one line - the completion message
    # This indirectly validates that targetPath(42) returned empty string
    # (which becomes an empty line that gets filtered)
    expected = "targetPath(42) test complete"

    if len(lines) != 1:
        results.append(make_result(
            "output_count",
            False,
            "1 line (empty targetPath result filtered out)",
            f"{len(lines)} lines",
            f"Expected exactly 1 non-empty line, got {len(lines)}: {lines}"
        ))
    else:
        results.append(make_result(
            "output_count",
            True,
            "1 line",
            "1 line"
        ))

    actual = lines[0] if len(lines) > 0 else None
    results.append(make_result(
        "completion_message",
        actual == expected,
        expected,
        actual if actual is not None else "<missing>"
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
