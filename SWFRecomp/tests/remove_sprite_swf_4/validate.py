#!/usr/bin/env python3
"""
Validation script for remove_sprite_swf_4

Tests the REMOVE_SPRITE opcode (0x25).
Expected output:
1. Remove a sprite and trace confirmation
2. Remove non-existent sprite (should not crash)
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

    Expected output:
    Line 1: "Sprite removed" - after removing mySprite
    Line 2: "Before remove" - before attempting to remove non-existent sprite
    Line 3: "After remove" - after attempting to remove non-existent sprite
    """
    lines = parse_output(output)

    results = []

    # Test 1: Basic sprite removal
    expected_line1 = "Sprite removed"
    actual_line1 = lines[0] if len(lines) > 0 else ""
    results.append(make_result(
        "basic_remove",
        actual_line1 == expected_line1,
        expected_line1,
        actual_line1
    ))

    # Test 2: Before removing non-existent sprite
    expected_line2 = "Before remove"
    actual_line2 = lines[1] if len(lines) > 1 else ""
    results.append(make_result(
        "before_nonexistent",
        actual_line2 == expected_line2,
        expected_line2,
        actual_line2
    ))

    # Test 3: After removing non-existent sprite (should not crash)
    expected_line3 = "After remove"
    actual_line3 = lines[2] if len(lines) > 2 else ""
    results.append(make_result(
        "after_nonexistent",
        actual_line3 == expected_line3,
        expected_line3,
        actual_line3
    ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
