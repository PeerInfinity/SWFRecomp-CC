#!/usr/bin/env python3
"""
Validation script for ActionCallMethod (0x52) test

This script validates the output of the call_method test.
Currently validates basic structure since full function/object system
implementation is required for complete testing.

Expected test cases:
1. Call simple method (returns property value)
2. Call method with arguments (adds two numbers)
3. Method accessing this.x and this.y
4. Call non-existent method (returns undefined)
"""

import sys
import json

def validate_output(output_lines):
    """
    Validate test output.

    Args:
        output_lines: List of output lines from the test

    Returns:
        dict with validation results
    """
    results = {
        "passed": True,
        "test_cases": [],
        "errors": []
    }

    # Expected outputs for each test case
    expected_outputs = [
        ("Test 1: Simple method", "10"),  # obj.getValue() returns this.value (10)
        ("Test 2: Method with args", "8"),  # obj.add(5, 3) returns 8
        ("Test 3: Method accessing this", "15"),  # obj.sum() returns this.x + this.y (5 + 10)
        ("Test 4: Non-existent method", "undefined"),  # Should always be undefined
    ]

    # Validate each test case
    for i, (test_name, expected) in enumerate(expected_outputs):
        if i < len(output_lines):
            actual = output_lines[i].strip()
            passed = actual == expected

            results["test_cases"].append({
                "name": test_name,
                "expected": expected,
                "actual": actual,
                "passed": passed
            })

            if not passed:
                results["passed"] = False
                results["errors"].append(f"{test_name}: expected '{expected}', got '{actual}'")
        else:
            results["test_cases"].append({
                "name": test_name,
                "expected": expected,
                "actual": None,
                "passed": False
            })
            results["passed"] = False
            results["errors"].append(f"{test_name}: no output (missing line {i+1})")

    return results

def main():
    if len(sys.argv) != 2:
        print("Usage: validate.py <output_file>", file=sys.stderr)
        sys.exit(1)

    output_file = sys.argv[1]

    try:
        with open(output_file, 'r') as f:
            output_lines = [line.strip() for line in f.readlines() if line.strip()]
    except FileNotFoundError:
        print(json.dumps({
            "passed": False,
            "test_cases": [],
            "errors": [f"Output file not found: {output_file}"]
        }))
        sys.exit(1)

    results = validate_output(output_lines)

    # Print results as JSON
    print(json.dumps(results, indent=2))

    # Exit with appropriate code
    sys.exit(0 if results["passed"] else 1)

if __name__ == "__main__":
    main()
