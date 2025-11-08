#!/usr/bin/env python3
"""
Validation script for get_property_swf_4

Tests the GET_PROPERTY opcode (0x22) which retrieves MovieClip properties by numeric index.

Expected output for all 22 properties (indices 0-21):
- 0: _x = 0
- 1: _y = 0
- 2: _xscale = 100
- 3: _yscale = 100
- 4: _currentframe = 1
- 5: _totalframes = 1
- 6: _alpha = 100
- 7: _visible = 1
- 8: _width = 550
- 9: _height = 400
- 10: _rotation = 0
- 11: _target = "_root"
- 12: _framesloaded = 1
- 13: _name = "_root"
- 14: _droptarget = "" (empty string)
- 15: _url = "" (empty string)
- 16: _highquality = 1
- 17: _focusrect = 1
- 18: _soundbuftime = 5
- 19: _quality = 2
- 20: _xmouse = 0
- 21: _ymouse = 0
"""
import sys
import json
import os

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import parse_output, make_result, make_validation_result


def parse_output_preserving_empty_lines(output):
    """
    Parse output but preserve empty lines (for empty string properties).
    Removes only the non-output header/footer lines.
    """
    # Split into lines
    all_lines = output.strip().split('\n')

    # Filter out known header/footer lines but keep empty lines
    filtered_lines = []
    started_output = False
    for line in all_lines:
        stripped = line.strip()
        # Skip header/footer lines
        if ("SWF Runtime" in stripped or
            "===" in stripped or
            "[Frame" in stripped or
            "[Tag]" in stripped):
            continue

        # Once we see non-empty content, we've started the actual output
        if not started_output and stripped:
            started_output = True

        # After output has started, preserve all lines (including empty ones)
        if started_output:
            filtered_lines.append(stripped)

    return filtered_lines


def validate_output(output):
    """
    Validate test output for all 22 MovieClip properties.
    """
    lines = parse_output_preserving_empty_lines(output)

    # Expected values for all 22 properties
    # Format: (expected_value, test_name, property_description)
    expected_values = [
        ("0", "x_property", "Property 0: _x"),
        ("0", "y_property", "Property 1: _y"),
        ("100", "xscale_property", "Property 2: _xscale"),
        ("100", "yscale_property", "Property 3: _yscale"),
        ("1", "currentframe_property", "Property 4: _currentframe"),
        ("1", "totalframes_property", "Property 5: _totalframes"),
        ("100", "alpha_property", "Property 6: _alpha"),
        ("1", "visible_property", "Property 7: _visible"),
        ("550", "width_property", "Property 8: _width"),
        ("400", "height_property", "Property 9: _height"),
        ("0", "rotation_property", "Property 10: _rotation"),
        ("_root", "target_property", "Property 11: _target"),
        ("1", "framesloaded_property", "Property 12: _framesloaded"),
        ("_root", "name_property", "Property 13: _name"),
        ("", "droptarget_property", "Property 14: _droptarget"),
        ("", "url_property", "Property 15: _url"),
        ("1", "highquality_property", "Property 16: _highquality"),
        ("1", "focusrect_property", "Property 17: _focusrect"),
        ("5", "soundbuftime_property", "Property 18: _soundbuftime"),
        ("2", "quality_property", "Property 19: _quality"),
        ("0", "xmouse_property", "Property 20: _xmouse"),
        ("0", "ymouse_property", "Property 21: _ymouse"),
    ]

    results = []

    # Validate each output line
    for i, (expected, test_name, description) in enumerate(expected_values):
        if i < len(lines):
            actual = lines[i]
            passed = actual == expected
            results.append(make_result(test_name, passed, expected, actual))
        else:
            results.append(make_result(
                test_name,
                False,
                expected,
                "missing",
                f"{description} output is missing"
            ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
