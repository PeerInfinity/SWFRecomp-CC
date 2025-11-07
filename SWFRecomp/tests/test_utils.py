"""
Test Utilities for SWFRecomp Test Suite

This module provides common validation helpers used by test validation scripts.
Import this in your validate.py scripts to reduce code duplication.

Usage:
    import sys
    sys.path.insert(0, '..')
    from test_utils import *
"""

import re
import math


# ==============================================================================
# Output Parsing Helpers
# ==============================================================================

def parse_output(output):
    """
    Parse test output into clean lines.

    Args:
        output: Raw test output string

    Returns:
        List of non-empty, stripped lines
    """
    return [line.strip() for line in output.strip().split('\n') if line.strip()]


def parse_int(value, default=None):
    """
    Safely parse string to integer.

    Args:
        value: String to parse
        default: Value to return if parsing fails (default: None)

    Returns:
        Integer value or default
    """
    try:
        return int(value)
    except (ValueError, TypeError):
        return default


def parse_float(value, default=None):
    """
    Safely parse string to float.

    Args:
        value: String to parse
        default: Value to return if parsing fails (default: None)

    Returns:
        Float value or default
    """
    try:
        return float(value)
    except (ValueError, TypeError):
        return default


# ==============================================================================
# Validation Helpers
# ==============================================================================

def validate_exact(actual, expected):
    """
    Validate exact string match.

    Args:
        actual: Actual value (will be converted to string)
        expected: Expected value (will be converted to string)

    Returns:
        True if values match exactly
    """
    return str(actual) == str(expected)


def validate_float(actual, expected, rel_tol=1e-5, abs_tol=1e-8):
    """
    Validate float values with tolerance.

    Useful for comparing floating point values that may have slight
    precision differences.

    Args:
        actual: Actual value (string or float)
        expected: Expected value (string or float)
        rel_tol: Relative tolerance (default: 1e-5)
        abs_tol: Absolute tolerance (default: 1e-8)

    Returns:
        True if values are close within tolerance
    """
    try:
        actual_f = float(actual)
        expected_f = float(expected)
        return math.isclose(actual_f, expected_f, rel_tol=rel_tol, abs_tol=abs_tol)
    except (ValueError, TypeError):
        return False


def validate_range(actual, min_val, max_val, inclusive_min=True, inclusive_max=False):
    """
    Validate value is within range.

    Args:
        actual: Actual value (string or numeric)
        min_val: Minimum value
        max_val: Maximum value
        inclusive_min: Include min_val in range (default: True)
        inclusive_max: Include max_val in range (default: False)

    Returns:
        True if value is in range

    Example:
        validate_range(5, 0, 10)  # Check 5 is in [0, 10)
        validate_range(10, 0, 10, inclusive_max=True)  # Check 10 is in [0, 10]
    """
    try:
        value = float(actual)
        if inclusive_min and inclusive_max:
            return min_val <= value <= max_val
        elif inclusive_min:
            return min_val <= value < max_val
        elif inclusive_max:
            return min_val < value <= max_val
        else:
            return min_val < value < max_val
    except (ValueError, TypeError):
        return False


def validate_pattern(actual, pattern):
    """
    Validate string matches regex pattern.

    Args:
        actual: Actual value (string)
        pattern: Regular expression pattern

    Returns:
        True if pattern matches
    """
    return bool(re.match(pattern, str(actual)))


def validate_one_of(actual, valid_values):
    """
    Validate value is one of several valid options.

    Args:
        actual: Actual value
        valid_values: List/set of valid values

    Returns:
        True if actual is in valid_values
    """
    return actual in valid_values


# ==============================================================================
# Result Building Helpers
# ==============================================================================

def make_result(name, passed, expected, actual, message=None):
    """
    Create a standardized sub-test result dictionary.

    Args:
        name: Sub-test name
        passed: Boolean pass/fail
        expected: Expected value (string)
        actual: Actual value (string)
        message: Optional failure message

    Returns:
        Dictionary with standard result structure
    """
    result = {
        "name": name,
        "passed": passed,
        "expected": str(expected),
        "actual": str(actual)
    }
    if message:
        result["message"] = message
    return result


def make_validation_result(sub_tests):
    """
    Create complete validation result from sub-tests.

    Args:
        sub_tests: List of sub-test result dictionaries

    Returns:
        Complete validation result with overall pass/fail
    """
    return {
        "passed": all(test["passed"] for test in sub_tests),
        "sub_tests": sub_tests
    }


# ==============================================================================
# Common Validation Patterns
# ==============================================================================

def validate_single_output(output, expected, test_name="output"):
    """
    Validate test with single expected output.

    Args:
        output: Raw test output
        expected: Expected output value
        test_name: Name for the sub-test

    Returns:
        Complete validation result
    """
    lines = parse_output(output)
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(test_name, actual == expected, expected, actual)
    ])


def validate_multiple_outputs(output, expected_values, test_names=None):
    """
    Validate test with multiple expected outputs.

    Args:
        output: Raw test output
        expected_values: List of expected values (in order)
        test_names: Optional list of test names (default: "output_0", "output_1", ...)

    Returns:
        Complete validation result
    """
    lines = parse_output(output)
    results = []

    if test_names is None:
        test_names = [f"output_{i}" for i in range(len(expected_values))]

    for i, (expected, name) in enumerate(zip(expected_values, test_names)):
        actual = lines[i] if i < len(lines) else ""
        results.append(make_result(name, actual == expected, expected, actual))

    return make_validation_result(results)


def validate_integer_range(output, min_val, max_val, test_name="range_check"):
    """
    Validate single integer output is within range [min_val, max_val).

    Args:
        output: Raw test output
        min_val: Minimum value (inclusive)
        max_val: Maximum value (exclusive)
        test_name: Name for the sub-test

    Returns:
        Complete validation result
    """
    lines = parse_output(output)
    actual_str = lines[0] if lines else ""

    actual_int = parse_int(actual_str)
    if actual_int is None:
        return make_validation_result([
            make_result(
                test_name,
                False,
                f"[{min_val}, {max_val})",
                actual_str,
                "Could not parse as integer"
            )
        ])

    passed = min_val <= actual_int < max_val
    return make_validation_result([
        make_result(test_name, passed, f"[{min_val}, {max_val})", str(actual_int))
    ])


# ==============================================================================
# Debugging Helpers
# ==============================================================================

def debug_output(output, prefix="DEBUG"):
    """
    Print output with line numbers for debugging.

    Useful during test development to see what the test actually outputs.

    Args:
        output: Raw test output
        prefix: Prefix for debug lines
    """
    print(f"{prefix}: Raw output:", file=sys.stderr)
    for i, line in enumerate(output.split('\n')):
        print(f"{prefix}: Line {i}: {repr(line)}", file=sys.stderr)


# ==============================================================================
# Example Usage
# ==============================================================================

if __name__ == "__main__":
    # Example: Simple test validation
    test_output = "42\n"
    result = validate_single_output(test_output, "42", "simple_test")
    import json
    print(json.dumps(result, indent=2))

    # Example: Multi-output validation
    test_output = "42\n100\n"
    result = validate_multiple_outputs(
        test_output,
        ["42", "100"],
        ["first_value", "second_value"]
    )
    print(json.dumps(result, indent=2))

    # Example: Range validation
    test_output = "7\n"
    result = validate_integer_range(test_output, 0, 10, "random_test")
    print(json.dumps(result, indent=2))
