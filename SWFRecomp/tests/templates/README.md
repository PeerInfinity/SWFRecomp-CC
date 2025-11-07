# Test Templates

This directory contains templates for creating new tests in the SWFRecomp test suite.

## Quick Start

To create a new test:

1. Create your test directory: `mkdir tests/<test_name_swf_N>`
2. Copy templates:
   ```bash
   cp templates/test_info_deterministic.json tests/<test_name_swf_N>/test_info.json
   cp templates/validate.py.template tests/<test_name_swf_N>/validate.py
   chmod +x tests/<test_name_swf_N>/validate.py
   ```
3. Edit `test_info.json` with your test details
4. Implement validation logic in `validate.py`
5. Create your SWF file or generation script
6. Create `config.toml` and `main.c` as usual

## Files in This Directory

### `test_info.json.template`
Generic template with placeholders for all fields.

### `test_info_deterministic.json`
Example for tests with deterministic outputs (most common case).
Use this for tests where the output is always the same.

### `test_info_range_validation.json`
Example for tests with non-deterministic outputs (e.g., random number generation).
Use this when you need to validate that outputs fall within expected ranges.

### `validate.py.template`
Template validation script with:
- Comprehensive documentation
- Three example validation patterns (simple, multi-output, range)
- Proper JSON output structure
- Helper comments and TODOs

## Test Info JSON Format

### Required Fields

```json
{
  "metadata": {
    "name": "test_name_swf_N",           // Must match directory name
    "description": "What this test does", // Brief, human-readable
    "swf_version": 4                      // SWF version (4, 5, 6, 7, etc.)
  },
  "opcodes": {
    "tested": ["OPCODE"],                 // Primary opcode(s) being tested
    "supporting": ["PUSH", "TRACE"]       // Helper opcodes used in test
  },
  "execution": {
    "type": "deterministic"               // or "range_validation"
  }
}
```

### Execution Types

**`deterministic`**: Test produces the same output every time
- Use for: arithmetic, string ops, comparisons, stack ops, etc.
- Validation: exact string/value matching

**`range_validation`**: Test output varies but falls within expected ranges
- Use for: random number generation, non-deterministic operations
- Validation: range checks, property validation

## Validation Script Guide

### Basic Structure

Every `validate.py` must:
1. Read test output from stdin
2. Parse and validate the output
3. Return JSON with this structure:
   ```json
   {
     "passed": bool,
     "sub_tests": [
       {
         "name": "test_name",
         "passed": bool,
         "expected": "expected_value",
         "actual": "actual_value",
         "message": "optional error message"
       }
     ]
   }
   ```

### Pattern 1: Simple Single-Output Test

Use when test produces one output value:

```python
def validate_output(output):
    lines = [line.strip() for line in output.strip().split('\n') if line.strip()]

    expected = "42"
    actual = lines[0] if lines else ""

    return {
        "passed": actual == expected,
        "sub_tests": [
            {
                "name": "result",
                "passed": actual == expected,
                "expected": expected,
                "actual": actual
            }
        ]
    }
```

### Pattern 2: Multi-Output Test

Use when test produces multiple outputs to validate:

```python
def validate_output(output):
    lines = [line.strip() for line in output.strip().split('\n') if line.strip()]
    results = []

    # Check first output
    if len(lines) > 0:
        results.append({
            "name": "output_1",
            "passed": lines[0] == "42",
            "expected": "42",
            "actual": lines[0]
        })

    # Check second output
    if len(lines) > 1:
        results.append({
            "name": "output_2",
            "passed": lines[1] == "100",
            "expected": "100",
            "actual": lines[1]
        })

    return {
        "passed": all(r["passed"] for r in results),
        "sub_tests": results
    }
```

### Pattern 3: Range Validation

Use for non-deterministic tests:

```python
def validate_output(output):
    lines = [line.strip() for line in output.strip().split('\n') if line.strip()]
    results = []

    # Validate value is in range [0, 10)
    if len(lines) > 0:
        try:
            value = int(lines[0])
            passed = 0 <= value < 10
            results.append({
                "name": "range_check",
                "passed": passed,
                "expected": "[0, 10)",
                "actual": str(value)
            })
        except ValueError:
            results.append({
                "name": "range_check",
                "passed": False,
                "expected": "[0, 10)",
                "actual": lines[0],
                "message": "Could not parse as integer"
            })

    return {
        "passed": all(r["passed"] for r in results),
        "sub_tests": results
    }
```

### Pattern 4: Using Helper Utilities

The `test_utils.py` module provides common validation helpers:

```python
import sys
sys.path.insert(0, '..')
from test_utils import parse_output, validate_exact, validate_range, validate_float

def validate_output(output):
    lines = parse_output(output)

    return {
        "passed": validate_exact(lines[0], "42"),
        "sub_tests": [
            {
                "name": "result",
                "passed": validate_exact(lines[0], "42"),
                "expected": "42",
                "actual": lines[0]
            }
        ]
    }
```

## Common Validation Tasks

### Exact String Match
```python
passed = actual == expected
```

### Float Comparison (with tolerance)
```python
import math
passed = math.isclose(float(actual), float(expected), rel_tol=1e-5)
```

### Integer Range Check
```python
value = int(actual)
passed = min_val <= value < max_val
```

### Regex Pattern Match
```python
import re
passed = bool(re.match(pattern, actual))
```

### Multiple Possible Values
```python
passed = actual in ["value1", "value2", "value3"]
```

## Testing Your Validation Script

You can test your validation script manually:

```bash
# Build and run your test, pipe output to validation script
cd tests/<test_name>
../../scripts/build_test.sh <test_name> native
./build/native/<test_name> 2>&1 | ./validate.py
```

Expected output is JSON:
```json
{
  "passed": true,
  "sub_tests": [
    {
      "name": "test_name",
      "passed": true,
      "expected": "42",
      "actual": "42"
    }
  ]
}
```

## Tips and Best Practices

1. **Clear sub-test names**: Use descriptive names like `"add_1.5_1.25"` instead of `"test1"`

2. **Handle missing output**: Always check if lines exist before accessing them

3. **Helpful failure messages**: Add `"message"` field to explain why a test failed

4. **Parse carefully**: Handle both integer and float values appropriately

5. **Test edge cases**: Validate boundary conditions (zero, negative, overflow, etc.)

6. **Keep it simple**: Don't over-complicate validation logic

7. **Document assumptions**: Add comments explaining expected test behavior

8. **Error handling**: Use try-except for parsing operations that might fail

9. **Consistent formatting**: Use the patterns from the template

10. **Test your validator**: Run it manually before committing

## Example Tests

See the following tests for reference implementations:

- **Simple deterministic**: `add_floats_swf_4`
- **Multi-output**: `duplicate_swf_4`
- **Range validation**: `random_number_swf_4`

## Getting Help

- Review the project plan: `SWFRecompDocs/plans/test-system-redesign-plan.md`
- Look at existing test implementations in `tests/*/validate.py`
- Check the test utilities: `tests/test_utils.py`
