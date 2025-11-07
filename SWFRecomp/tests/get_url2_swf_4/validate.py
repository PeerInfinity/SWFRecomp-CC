#!/usr/bin/env python3
"""
Validation script for get_url2_swf_4

Tests the GET_URL2 opcode (0x9A).
Expected output: 5 trace statements from the test cases
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
    - Test 1: "URL load requested"
    - Test 2: "Loading variables"
    - Test 3: "Posting data"
    - Test 4: "Loading movie"
    - Test 5: "Opening page"
    """
    lines = parse_output(output)

    # Filter out debug lines starting with "//"
    lines = [line for line in lines if not line.startswith("//")]

    expected_outputs = [
        "URL load requested",
        "Loading variables",
        "Posting data",
        "Loading movie",
        "Opening page"
    ]

    test_names = [
        "test_1_url_new_window",
        "test_2_get_variables",
        "test_3_post_request",
        "test_4_load_movie_sprite",
        "test_5_dynamic_url"
    ]

    results = []

    for i, (expected, test_name) in enumerate(zip(expected_outputs, test_names)):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(
            test_name,
            actual == expected,
            expected,
            actual
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
