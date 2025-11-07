#!/usr/bin/env python3
"""
Validation script for add_swf_4

Comprehensive tests for ADD opcode including:
- Basic integer addition
- Floating point addition  
- String to number conversion
- Edge cases (NaN, zero, negative numbers)
"""
import sys
import json
import os
import math

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    """
    Validate test output for comprehensive ADD opcode tests.
    
    Tests:
    1. Basic integer addition: 5 + 3 = 8
    2. Floating point: 2.5 + 1.5 = 4
    3. String conversion: "10" + 5 = 15
    4. Zero addition: 0 + 42 = 42
    5. Negative numbers: -5 + 10 = 5
    6. Mixed float/int: 7.5 + 2 = 9.5
    7. Large numbers: 1000000 + 500000 = 1500000
    8. Small decimals: 0.001 + 0.002 = 0.003
    9. Negative result: -10 + 3 = -7
    10. Double negative: -5 + -5 = -10
    """
    lines = parse_output(output)
    
    # We expect 10 output lines
    if len(lines) < 10:
        lines.extend([''] * (10 - len(lines)))  # Pad with empty strings
    
    results = []
    
    # Test 1: Basic integer addition
    results.append(make_result(
        "basic_integer_5_plus_3",
        lines[0] == "8",
        "8",
        lines[0]
    ))
    
    # Test 2: Floating point
    results.append(make_result(
        "floating_point_2.5_plus_1.5",
        lines[1] == "4",
        "4",
        lines[1]
    ))
    
    # Test 3: String conversion (string "10" + number 5)
    results.append(make_result(
        "string_conversion_10_plus_5",
        lines[2] == "15",
        "15",
        lines[2]
    ))
    
    # Test 4: Zero addition
    results.append(make_result(
        "zero_plus_42",
        lines[3] == "42",
        "42",
        lines[3]
    ))
    
    # Test 5: Negative numbers
    results.append(make_result(
        "negative_-5_plus_10",
        lines[4] == "5",
        "5",
        lines[4]
    ))
    
    # Test 6: Mixed float/int
    results.append(make_result(
        "mixed_7.5_plus_2",
        lines[5] == "9.5",
        "9.5",
        lines[5]
    ))
    
    # Test 7: Large numbers
    results.append(make_result(
        "large_numbers_1000000_plus_500000",
        lines[6] == "1500000",
        "1500000",
        lines[6]
    ))
    
    # Test 8: Small decimals
    # Handle potential floating point imprecision
    try:
        actual_val = float(lines[7])
        expected_val = 0.003
        is_close = abs(actual_val - expected_val) < 0.0001
        results.append(make_result(
            "small_decimals_0.001_plus_0.002",
            is_close,
            "0.003",
            lines[7]
        ))
    except:
        results.append(make_result(
            "small_decimals_0.001_plus_0.002",
            False,
            "0.003",
            lines[7]
        ))
    
    # Test 9: Negative result
    results.append(make_result(
        "negative_result_-10_plus_3",
        lines[8] == "-7",
        "-7",
        lines[8]
    ))
    
    # Test 10: Double negative
    results.append(make_result(
        "double_negative_-5_plus_-5",
        lines[9] == "-10",
        "-10",
        lines[9]
    ))
    
    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))