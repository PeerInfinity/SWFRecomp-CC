# Test System Redesign - Project Plan

## Overview
Redesign the SWFRecomp test system to support per-test validation logic, structured result reporting, and deterministic testing for non-deterministic operations like random number generation.

**Status**: Planning

**Created**: 2025-11-06

**Target Completion**: TBD

---

## Goals

### Primary Goals
1. **Per-test validation logic**: Each test contains its own Python script to evaluate test output and determine pass/fail
2. **Structured results**: Test results stored in JSON format with detailed pass/fail information for each test and sub-test
3. **Smart validation for non-deterministic tests**: `random_number_swf_4` validates that outputs are in correct ranges (deterministic seed support planned for future)
4. **Opcode metadata**: Each test documents which opcodes it tests

### Secondary Goals
5. **Better failure diagnostics**: Clear indication of what failed and why
6. **Machine-readable output**: JSON results can be consumed by documentation generators
7. **Extensible design**: Easy to add new tests with complex validation logic

### Non-Goals (Future Work)
- HTML report generation (may be added later via separate script)
- Test filtering by opcode (nice-to-have, not critical)
- CI/CD integration (separate effort)
- Performance benchmarking (separate concern)

---

## Current System Analysis

### Current Structure
```
tests/
├── all_tests.sh              # Main test runner
├── test_vecs.txt             # Static expected outputs
├── test.sh                   # Old test runner (unused)
└── <test_name>/
    ├── test.swf              # Pre-built SWF OR
    ├── create_test_swf.py    # SWF generator script
    ├── config.toml           # Recompiler config
    ├── main.c                # Test entrypoint
    └── build/                # Build output directory
```

### Current Workflow
1. `all_tests.sh` reads `test_vecs.txt` for test names and expected output
2. Builds each test using `../scripts/build_test.sh`
3. Runs compiled test and captures stdout
4. Compares output to static string from `test_vecs.txt`
5. Reports pass/fail based on exact string match

### Current Limitations
- **Static expectations**: Cannot handle non-deterministic output (random numbers)
- **No sub-test tracking**: Multi-part tests reported as single pass/fail
- **Limited validation**: Only exact string matching
- **No metadata**: Opcode information in README but not machine-readable
- **Poor failure diagnostics**: Just shows expected vs actual, no context

---

## New System Design

### Directory Structure
```
tests/
├── all_tests.sh              # New comprehensive test runner
├── test_results.json         # Generated test results
├── templates/                # Templates for new tests
│   ├── validate.py.template
│   └── test_info.json.template
└── <test_name>/
    ├── test.swf or create_test_swf.py
    ├── config.toml
    ├── main.c
    ├── test_info.json        # NEW: Test metadata
    ├── validate.py           # NEW: Test validation logic
    └── build/
```

### File Specifications

#### `test_info.json`
```json
{
  "metadata": {
    "name": "test_name_swf_N",
    "description": "Human-readable test description",
    "swf_version": 4
  },
  "opcodes": {
    "tested": ["PRIMARY_OPCODE"],
    "supporting": ["PUSH", "TRACE"]
  },
  "execution": {
    "type": "deterministic | range_validation"
  }
}
```

**Fields**:
- `metadata.name`: Test directory name (for validation)
- `metadata.description`: Brief description of what's being tested
- `metadata.swf_version`: SWF version used (4, 5, 6, 7, etc.)
- `opcodes.tested`: Primary opcodes this test validates
- `opcodes.supporting`: Opcodes used but not the focus of testing
- `execution.type`: "deterministic" or "range_validation" (for non-deterministic tests like random)

#### `validate.py`
```python
#!/usr/bin/env python3
"""
Validation script for <test_name>

This script receives test output and determines pass/fail status.
Returns JSON with structured results.
"""
import sys
import json

def validate_output(output, seed=None):
    """
    Validate test output and return structured results.

    Args:
        output: String containing test stdout

    Returns:
        dict with structure:
        {
            "passed": bool,  # Overall pass/fail
            "sub_tests": [
                {
                    "name": str,
                    "passed": bool,
                    "expected": str,
                    "actual": str,
                    "message": str  # Optional failure message
                }
            ]
        }
    """
    # Implementation here
    pass

if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
```

#### `test_results.json`
```json
{
  "timestamp": "2025-11-06T12:34:56Z",
  "summary": {
    "total_tests": 95,
    "passed": 93,
    "failed": 2,
    "skipped": 0,
    "total_sub_tests": 150,
    "passed_sub_tests": 148,
    "failed_sub_tests": 2
  },
  "tests": [
    {
      "name": "random_number_swf_4",
      "passed": true,
      "build_time_ms": 1234,
      "execution_time_ms": 45,
      "opcodes_tested": ["RANDOM_NUMBER"],
      "passed": true,
      "sub_tests": [
        {
          "name": "random(0)",
          "passed": true,
          "expected": "0",
          "actual": "0"
        },
        {
          "name": "random(10)_range",
          "passed": true,
          "expected": "[0, 10)",
          "actual": "7"
        },
        {
          "name": "random(100)_range",
          "passed": true,
          "expected": "[0, 100)",
          "actual": "42"
        }
      ]
    },
    {
      "name": "add_floats_swf_4",
      "passed": true,
      "build_time_ms": 1050,
      "execution_time_ms": 32,
      "opcodes_tested": ["ADD"],
      "passed": true,
      "sub_tests": [
        {
          "name": "add_1.5_1.25",
          "passed": true,
          "expected": "2.75",
          "actual": "2.75"
        }
      ]
    },
    {
      "name": "failing_test_example",
      "passed": false,
      "build_time_ms": 1100,
      "execution_time_ms": 28,
      "opcodes_tested": ["SOME_OP"],
      "passed": false,
      "sub_tests": [
        {
          "name": "test_case_1",
          "passed": false,
          "expected": "42",
          "actual": "43",
          "message": "Value mismatch: expected 42 but got 43"
        }
      ]
    }
  ]
}
```

### `all_tests.sh` Workflow

```
1. Initialize results JSON structure
2. Discover all test directories
3. For each test directory:
   a. Check if test_info.json exists
      - If not: SKIP with warning
   b. Parse test_info.json
   c. Check for validate.py
      - If not: SKIP with warning
   d. Build test using ../scripts/build_test.sh
      - Record build time
      - If build fails: Mark FAILED, continue to next test
   e. Execute test binary
      - Record execution time
      - Filter output (remove SWF runtime messages)
   f. Pass output to validate.py
      - Parse validation JSON
      - Record results
   g. Determine overall test pass/fail
4. Write complete results to test_results.json
5. Print summary to stdout:
   - Total tests, passed, failed
   - List of failed tests with brief error info
   - Execution time statistics
```

### stdout Summary Format
```
========================================
SWFRecomp Test Suite Results
========================================
Timestamp: 2025-11-06 12:34:56

Tests:     93 / 95 passed (2 failed, 0 skipped)
Sub-tests: 148 / 150 passed
Time:      45.2s total (build: 32.1s, run: 13.1s)

FAILED TESTS:
  [1] some_test_swf_4
      - Sub-test 'test_case_1' failed: expected "42" but got "43"

  [2] another_test_swf_5
      - Sub-test 'boundary_check' failed: value out of range

Results saved to: tests/test_results.json
========================================
```

---

## Implementation Plan

### Phase 1: Foundation (Templates & Infrastructure)
**Goal**: Create reusable templates and helper utilities

**Tasks**:
1. Create `templates/` directory
2. Write `templates/validate.py.template` with comprehensive documentation
3. Write `templates/test_info.json.template` with examples for both execution types
4. Write template README explaining how to create new tests
5. Create helper Python module `test_utils.py` for common validation tasks
   - String matching helpers
   - Range validation
   - Regex matching
   - JSON comparison utilities

**Deliverables**:
- `tests/templates/validate.py.template`
- `tests/templates/test_info.json.template`
- `tests/templates/README.md`
- `tests/test_utils.py`

### Phase 2: New Test Runner
**Goal**: Implement new `all_tests.sh` with full functionality

**Tasks**:
1. Write new `all_tests.sh` script
   - Test discovery
   - JSON parsing (using Python helper or `jq`)
   - Build orchestration
   - Output filtering
   - Results aggregation
   - Summary formatting
2. Implement proper error handling
3. Add timing measurements
4. Ensure graceful handling of missing files

**Deliverables**:
- `tests/all_tests.sh` (new version)
- Initial `test_results.json` structure

**Testing**:
- Run with no tests migrated (should skip all)
- Run with one test migrated (should run that one)

### Phase 3: Pilot Tests
**Goal**: Migrate 3 representative tests to validate design

**Test Selection**:
1. **Simple deterministic**: `add_floats_swf_4`
   - Single output value
   - Straightforward validation
   - Tests basic float arithmetic

2. **Multi-output deterministic**: `duplicate_swf_4`
   - Multiple trace outputs
   - Multiple sub-tests to validate
   - Tests stack manipulation

3. **Non-deterministic with range validation**: `random_number_swf_4`
   - Single SWF file (no modifications needed)
   - Range validation logic (e.g., random(10) must be in [0, 10))
   - Tests correctness without deterministic seeds

**Tasks per test**:
1. Create `test_info.json`
2. Create `validate.py`
3. For `random_number_swf_4`: Modify `create_test_swf.py` to use fixed seeds
4. Test manually
5. Document any issues or design improvements needed

**Deliverables**:
- `add_floats_swf_4/test_info.json`
- `add_floats_swf_4/validate.py`
- `duplicate_swf_4/test_info.json`
- `duplicate_swf_4/validate.py`
- `random_number_swf_4/test_info.json`
- `random_number_swf_4/validate.py`

**Validation**:
- Run `all_tests.sh` and verify:
  - All 3 tests execute correctly
  - JSON output is well-formed
  - Summary output is readable
  - Failed test reporting works (intentionally break a test to verify)

### Phase 4: Bulk Migration
**Goal**: Migrate all remaining tests

**Approach**:
- Group tests by complexity/similarity
- Use templates and scripts to semi-automate migration
- Prioritize tests used in active development

**Groups**:
1. **Simple arithmetic** (15-20 tests): ADD, SUBTRACT, MULTIPLY, etc.
2. **Comparison operators** (10-15 tests): LESS, GREATER, EQUALS, etc.
3. **String operations** (10-15 tests): String concatenation, length, etc.
4. **Stack operations** (5-10 tests): PUSH, POP, DUPLICATE, SWAP
5. **Control flow** (5-10 tests): JUMP, IF, IF_FALSE
6. **Bitwise operations** (5-10 tests): AND, OR, XOR, shifts
7. **Type conversions** (5-10 tests): TO_INTEGER, TO_STRING, etc.
8. **Functions and scope** (10-15 tests): CALL, RETURN, WITH, etc.
9. **Object operations** (5-10 tests): GET_MEMBER, SET_MEMBER, etc.
10. **Remaining/misc** (remaining tests)

**Process per group**:
1. Review tests in group for common patterns
2. Create validation helper if needed
3. Migrate tests
4. Run test suite to verify
5. Fix any issues

**Deliverables**:
- `test_info.json` and `validate.py` for all ~95 tests
- Updated test suite with all tests passing

### Phase 5: Cleanup & Documentation
**Goal**: Remove old system, document new system

**Tasks**:
1. Delete `test_vecs.txt`
2. Delete old `test.sh`
3. Update main `SWFRecomp/README.md` with testing instructions
4. Create `tests/README.md` with comprehensive documentation:
   - How to run tests
   - How to create new tests
   - How to interpret results
   - Validation script best practices
   - Examples of common validation patterns
5. Update any CI/CD scripts if they exist
6. Update contributor documentation

**Deliverables**:
- Removed: `test_vecs.txt`, `test.sh`
- Updated: `tests/README.md`
- Updated: Root-level documentation mentioning testing

---

## Technical Decisions

### Why Python for validation?
- **Flexibility**: Easy to implement complex validation logic (ranges, regex, JSON parsing)
- **Readability**: Clear, maintainable test validation code
- **Libraries**: Rich standard library for string processing, JSON, etc.
- **Consistency**: Already using Python for SWF generation scripts

### Why JSON for metadata?
- **Familiarity**: User is more familiar with JSON
- **Tooling**: Better tooling support (jq, Python json module, etc.)
- **Simplicity**: Simple structure doesn't require TOML's advanced features
- **Machine-readable**: Easy to parse in any language

### Why range validation instead of fixed seeds for random_number test?
- **Simplicity**: No runtime changes needed now
- **Adequate**: Validates RNG implementation works correctly (values in correct ranges)
- **Future-proof**: Can add deterministic seed support later when runtime is enhanced
- **Single SWF**: Avoids complexity of multiple SWF files or test variants

### Why JSON for results?
- **Structure**: Natural fit for hierarchical test results
- **Tooling**: Easy to parse, query (jq), and process
- **Future-proof**: Can be consumed by documentation generators, CI systems, etc.

---

## Risk Analysis

### Risks

| Risk | Likelihood | Impact | Mitigation |
|------|-----------|--------|------------|
| Migration takes longer than expected | Medium | Medium | Start with pilot tests to validate approach; use templates to speed up bulk migration |
| Complex tests difficult to validate | Low | Medium | Create rich helper library in test_utils.py; document patterns in templates |
| Test results too verbose | Low | Low | Design concise JSON structure; summary view hides details |
| Breaking existing workflows | Low | High | Old system not relied upon; clean break is acceptable |
| Validation scripts become inconsistent | Medium | Low | Use templates; code review validation scripts; provide clear examples |

### Dependencies
- Python 3 (already required for SWF generation)
- `jq` (optional, for JSON processing in shell script - can use Python instead)
- Existing build system (no changes required)

---

## Success Criteria

### Must Have
- [ ] All existing tests migrated to new system
- [ ] Test results saved to JSON with complete information
- [ ] Summary printed to stdout with pass/fail counts
- [ ] `random_number_swf_4` uses fixed seeds and validates correctly
- [ ] All test directories have `test_info.json` with opcode metadata
- [ ] Documentation explains how to create new tests

### Should Have
- [ ] Templates make creating new tests straightforward
- [ ] Helper utilities in `test_utils.py` reduce validation code duplication
- [ ] Failed tests show clear diagnostic information
- [ ] Test execution time under 2 minutes for full suite

### Nice to Have
- [ ] Colored output for pass/fail in summary
- [ ] Progress indicator during test execution
- [ ] Ability to run specific test or test pattern
- [ ] Parallel test execution

---

## Future Enhancements (Out of Scope)

1. **Deterministic Seed Support**: Add runtime seed control via environment variable or command-line argument
   - Modify `SWFModernRuntime/src/actionmodern/action.c` to accept seed from `SWF_RANDOM_SEED` env var
   - Update `random_number_swf_4` test to use specific seeds for deterministic testing
   - Enables regression detection for exact RNG output sequences
2. **HTML Report Generation**: Separate script reads JSON and generates HTML report
3. **Test Filtering**: `--opcode ADD` to run only tests testing specific opcodes
4. **Performance Tracking**: Track execution time trends over commits
5. **CI Integration**: GitHub Actions workflow to run tests automatically
6. **Coverage Analysis**: Track which opcodes lack test coverage
7. **Interactive Mode**: Prompt user for action on test failure
8. **Benchmarking**: Performance benchmarks for runtime operations

---

## Timeline Estimate

| Phase | Estimated Time | Notes |
|-------|---------------|-------|
| Phase 1: Foundation | 2-3 hours | Templates and utilities |
| Phase 2: Test Runner | 3-4 hours | Core script implementation |
| Phase 3: Pilot Tests | 2-3 hours | 3 tests + validation |
| Phase 4: Bulk Migration | 8-12 hours | ~90 tests to migrate |
| Phase 5: Cleanup | 1-2 hours | Documentation and cleanup |
| **Total** | **16-24 hours** | Depends on test complexity |

**Note**: Timeline assumes work is done iteratively with testing between phases.

---

## Questions & Decisions Log

| Date | Question | Decision | Rationale |
|------|----------|----------|-----------|
| 2025-11-06 | Validation language? | Python | Flexibility and consistency with existing scripts |
| 2025-11-06 | Metadata format? | JSON | User familiarity, good tooling support |
| 2025-11-06 | Seed implementation? | Fixed seeds in create_test_swf.py | Simplest approach, adequate for validation |
| 2025-11-06 | Backward compatibility? | Clean break | Old system not relied upon |
| 2025-11-06 | Test filtering by opcode? | Future enhancement | Nice to have, not critical |
| 2025-11-06 | Report format? | JSON + stdout summary | JSON for machines, summary for humans |

---

## Appendix: Example Implementations

### Example 1: Simple Deterministic Test

**test_info.json** for `add_floats_swf_4`:
```json
{
  "metadata": {
    "name": "add_floats_swf_4",
    "description": "Tests ADD opcode with floating point numbers",
    "swf_version": 4
  },
  "opcodes": {
    "tested": ["ADD"],
    "supporting": ["PUSH", "TRACE"]
  },
  "execution": {
    "type": "deterministic"
  }
}
```

**validate.py** for `add_floats_swf_4`:
```python
#!/usr/bin/env python3
import sys
import json

def validate_output(output):
    lines = [l.strip() for l in output.strip().split('\n') if l.strip()]

    # Expected: "2.75" (1.5 + 1.25)
    expected = "2.75"
    actual = lines[0] if lines else ""

    return {
        "passed": actual == expected,
        "sub_tests": [
            {
                "name": "add_1.5_1.25",
                "passed": actual == expected,
                "expected": expected,
                "actual": actual
            }
        ]
    }

if __name__ == "__main__":
    output = sys.stdin.read()
    print(json.dumps(validate_output(output), indent=2))
```

### Example 2: Range Validation Test

**test_info.json** for `random_number_swf_4`:
```json
{
  "metadata": {
    "name": "random_number_swf_4",
    "description": "Tests RANDOM_NUMBER opcode (0x30) with range validation",
    "swf_version": 4
  },
  "opcodes": {
    "tested": ["RANDOM_NUMBER"],
    "supporting": ["PUSH", "TRACE"]
  },
  "execution": {
    "type": "range_validation"
  }
}
```

**validate.py** for `random_number_swf_4`:
```python
#!/usr/bin/env python3
import sys
import json

def validate_output(output):
    lines = [l.strip() for l in output.strip().split('\n') if l.strip()]

    # Parse test outputs (format: "Test N - random(X):" followed by result)
    results = []
    i = 0

    # Test 1: random(0) should be 0
    if i + 1 < len(lines):
        actual = lines[i + 1]
        results.append({
            "name": "random(0)",
            "passed": actual == "0",
            "expected": "0",
            "actual": actual
        })
        i += 2

    # Test 2: random(1) should be 0
    if i + 1 < len(lines):
        actual = lines[i + 1]
        results.append({
            "name": "random(1)",
            "passed": actual == "0",
            "expected": "0",
            "actual": actual
        })
        i += 2

    # Test 3: random(10) should be in [0, 10)
    if i + 1 < len(lines):
        try:
            actual_val = int(lines[i + 1])
            passed = 0 <= actual_val < 10
            results.append({
                "name": "random(10)_range",
                "passed": passed,
                "expected": "[0, 10)",
                "actual": str(actual_val)
            })
        except ValueError:
            results.append({
                "name": "random(10)_range",
                "passed": False,
                "expected": "[0, 10)",
                "actual": lines[i + 1],
                "message": "Could not parse as integer"
            })
        i += 2

    # Test 4: random(100) should be in [0, 100)
    if i + 1 < len(lines):
        try:
            actual_val = int(lines[i + 1])
            passed = 0 <= actual_val < 100
            results.append({
                "name": "random(100)_range",
                "passed": passed,
                "expected": "[0, 100)",
                "actual": str(actual_val)
            })
        except ValueError:
            results.append({
                "name": "random(100)_range",
                "passed": False,
                "expected": "[0, 100)",
                "actual": lines[i + 1],
                "message": "Could not parse as integer"
            })
        i += 2

    # Test 5: random(1000) should be in [0, 1000)
    if i + 1 < len(lines):
        try:
            actual_val = int(lines[i + 1])
            passed = 0 <= actual_val < 1000
            results.append({
                "name": "random(1000)_range",
                "passed": passed,
                "expected": "[0, 1000)",
                "actual": str(actual_val)
            })
        except ValueError:
            results.append({
                "name": "random(1000)_range",
                "passed": False,
                "expected": "[0, 1000)",
                "actual": lines[i + 1],
                "message": "Could not parse as integer"
            })
        i += 2

    # Test 6: random(-5) should be 0
    if i + 1 < len(lines):
        actual = lines[i + 1]
        results.append({
            "name": "random(-5)_negative",
            "passed": actual == "0",
            "expected": "0",
            "actual": actual
        })

    overall_passed = all(r["passed"] for r in results)

    return {
        "passed": overall_passed,
        "sub_tests": results
    }

if __name__ == "__main__":
    output = sys.stdin.read()
    print(json.dumps(validate_output(output), indent=2))
```

### Example 3: Multi-output Test

**validate.py** for `duplicate_swf_4`:
```python
#!/usr/bin/env python3
import sys
import json

def validate_output(output):
    lines = [l.strip() for l in output.strip().split('\n') if l.strip()]

    # Test should output "84" after duplicating and adding stack values
    expected = "84"
    actual = lines[0] if lines else ""

    return {
        "passed": actual == expected,
        "sub_tests": [
            {
                "name": "duplicate_and_add",
                "passed": actual == expected,
                "expected": expected,
                "actual": actual,
                "message": "Tests that DUPLICATE correctly copies top stack value"
            }
        ]
    }

if __name__ == "__main__":
    output = sys.stdin.read()
    print(json.dumps(validate_output(output), indent=2))
```

---

## Notes
- This document is a living document and will be updated as implementation progresses
- Design decisions may change based on implementation discoveries
- Actual test migration order may vary based on priority and complexity
