#!/bin/bash

# SWFRecomp Test Suite Runner
# New test system with per-test validation and JSON results
# See: SWFRecompDocs/plans/test-system-redesign-plan.md

# Colors for output (if terminal supports it)
if [[ -t 1 ]]; then
    GREEN='\033[0;32m'
    RED='\033[0;31m'
    YELLOW='\033[0;33m'
    BLUE='\033[0;34m'
    NC='\033[0m' # No Color
else
    GREEN=''
    RED=''
    YELLOW=''
    BLUE=''
    NC=''
fi

# Configuration
RESULTS_FILE="test_results.json"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_SCRIPT="../scripts/build_test.sh"
CLEAN_FLAG=""
RETEST_FLAG=""
BUILD_FLAG=""
MAX_TESTS=""

# Check for --clean, --retest, --build, and --max-tests flags
for arg in "$@"; do
    if [ "$arg" = "--clean" ]; then
        CLEAN_FLAG="--clean"
    elif [ "$arg" = "--retest" ]; then
        RETEST_FLAG="--retest"
    elif [ "$arg" = "--build" ]; then
        BUILD_FLAG="--build"
    elif [[ "$arg" =~ ^--max-tests=([0-9]+)$ ]]; then
        MAX_TESTS="${BASH_REMATCH[1]}"
    fi
done

# Counters
total_tests=0
passed_tests=0
failed_tests=0
skipped_tests=0
total_sub_tests=0
passed_sub_tests=0
failed_sub_tests=0

# Arrays to track results
declare -a failed_test_names
declare -a failed_test_messages

# Timing
start_time=$(date +%s%3N)
total_build_time=0
total_run_time=0

# ==============================================================================
# Helper Functions
# ==============================================================================

log_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

log_success() {
    echo -e "${GREEN}[PASS]${NC} $1"
}

log_error() {
    echo -e "${RED}[FAIL]${NC} $1"
}

log_warning() {
    echo -e "${YELLOW}[SKIP]${NC} $1"
}

# Parse JSON field using Python (more reliable than jq for our needs)
parse_json_field() {
    local json_file="$1"
    local field_path="$2"
    python3 -c "import json, sys; data=json.load(open('$json_file')); print(data$field_path)" 2>/dev/null || echo ""
}

# Parse JSON array using Python
parse_json_array() {
    local json_file="$1"
    local field_path="$2"
    python3 -c "import json; data=json.load(open('$json_file')); print(' '.join(data$field_path))" 2>/dev/null || echo ""
}

# Filter test output to remove runtime messages
filter_output() {
    grep -a -v "SWF Runtime Loaded" | \
    grep -a -v "=== SWF" | \
    grep -a -v "\[Frame" | \
    grep -a -v "\[Tag\]" | \
    grep -a -v "\[DEBUG" | \
    grep -a -v "\[HEAP" | \
    grep -a -v "^$" || true
}

# Filter test output but preserve empty lines (for tests that need them)
filter_output_preserve_empty() {
    grep -a -v "SWF Runtime Loaded" | \
    grep -a -v "=== SWF" | \
    grep -a -v "\[Frame" | \
    grep -a -v "\[Tag\]" | \
    grep -a -v "\[DEBUG" | \
    grep -a -v "\[HEAP" || true
}

# Initialize results JSON file
init_results_file() {
    local tests_to_run=("$@")

    # If no previous results exist, create fresh file
    if [[ ! -f "$RESULTS_FILE" ]]; then
        cat > "$RESULTS_FILE" <<EOF
{
  "timestamp": "$(date -u +%Y-%m-%dT%H:%M:%SZ)",
  "summary": {
    "total_tests": 0,
    "passed": 0,
    "failed": 0,
    "skipped": 0,
    "total_sub_tests": 0,
    "passed_sub_tests": 0,
    "failed_sub_tests": 0
  },
  "tests": []
}
EOF
        return
    fi

    # Preserve previous results, removing only tests we're about to run
    local timestamp=$(date -u +%Y-%m-%dT%H:%M:%SZ)
    python3 - "$RESULTS_FILE" "$timestamp" "${tests_to_run[@]}" <<'EOF'
import json
import sys

results_file = sys.argv[1]
timestamp = sys.argv[2]
tests_to_run = sys.argv[3:]  # All remaining args are test names

# Read existing results
try:
    with open(results_file, 'r') as f:
        data = json.load(f)
except:
    # If file is corrupted, start fresh
    data = {"tests": []}

# Keep only tests that are NOT being run this time
preserved_tests = []
for test in data.get('tests', []):
    if test['name'] not in tests_to_run:
        preserved_tests.append(test)

# Create new structure with preserved tests
new_data = {
    "timestamp": timestamp,
    "summary": {
        "total_tests": 0,
        "passed": 0,
        "failed": 0,
        "skipped": 0,
        "total_sub_tests": 0,
        "passed_sub_tests": 0,
        "failed_sub_tests": 0
    },
    "tests": preserved_tests
}

# Write back
with open(results_file, 'w') as f:
    json.dump(new_data, f, indent=2)
EOF
}

# Add test result to JSON file
add_test_result() {
    local test_name="$1"

    # Read stdin into variable
    local input_json=$(cat)

    # Write to temp file to pass to Python
    local temp_input=$(mktemp)
    echo "$input_json" > "$temp_input"

    # Use Python to append test result to JSON array
    python3 - "$RESULTS_FILE" "$temp_input" <<'EOF'
import json
import sys

results_file = sys.argv[1]
input_file = sys.argv[2]

# Read new test result from file
with open(input_file, 'r') as f:
    test_result = json.load(f)

# Read existing results
with open(results_file, 'r') as f:
    data = json.load(f)

# Append to tests array
data['tests'].append(test_result)

# Write back
with open(results_file, 'w') as f:
    json.dump(data, f, indent=2)
EOF

    rm -f "$temp_input"
}

# Update summary in results file
update_summary() {
    python3 <<EOF
import json

with open('$RESULTS_FILE', 'r') as f:
    data = json.load(f)

# Calculate totals from ALL tests in the file (preserved + newly run)
all_tests = data.get('tests', [])
total_tests = len(all_tests)
passed_tests = sum(1 for t in all_tests if t.get('passed', False))
failed_tests = sum(1 for t in all_tests if not t.get('passed', True))
skipped_tests = 0  # We don't preserve skipped status

# Calculate sub-test totals
total_sub_tests = 0
passed_sub_tests = 0
failed_sub_tests = 0

for test in all_tests:
    for sub_test in test.get('sub_tests', []):
        total_sub_tests += 1
        if sub_test.get('passed', False):
            passed_sub_tests += 1
        else:
            failed_sub_tests += 1

data['summary'] = {
    "total_tests": total_tests,
    "passed": passed_tests,
    "failed": failed_tests,
    "skipped": skipped_tests,
    "total_sub_tests": total_sub_tests,
    "passed_sub_tests": passed_sub_tests,
    "failed_sub_tests": failed_sub_tests
}

with open('$RESULTS_FILE', 'w') as f:
    json.dump(data, f, indent=2)
EOF
}

# ==============================================================================
# Test Discovery
# ==============================================================================

get_failed_tests_from_previous_run() {
    # Get list of failed tests from previous test_results.json
    if [[ ! -f "$RESULTS_FILE" ]]; then
        echo ""
        return
    fi

    python3 -c '
import json
import sys

try:
    with open("'"$RESULTS_FILE"'", "r") as f:
        data = json.load(f)

    failed_tests = []
    for test in data.get("tests", []):
        if not test.get("passed", False):
            failed_tests.append(test["name"])

    print(" ".join(failed_tests))
except Exception:
    # If we cant read the file, return empty
    pass
' 2>/dev/null || echo ""
}

discover_tests() {
    local specified_tests=("$@")

    local test_dirs=()

    # Filter out --clean, --retest, --build, and --max-tests flags from specified tests
    local filtered_tests=()
    for test in "${specified_tests[@]}"; do
        if [[ "$test" != "--clean" && "$test" != "--retest" && "$test" != "--build" && ! "$test" =~ ^--max-tests= ]]; then
            filtered_tests+=("$test")
        fi
    done

    # If --retest flag is set, only run previously failed tests
    if [[ -n "$RETEST_FLAG" ]]; then
        local failed_tests_str=$(get_failed_tests_from_previous_run)
        local failed_tests=($failed_tests_str)
        if [[ ${#failed_tests[@]} -eq 0 ]]; then
            # Return empty - this will be handled in run_all_tests
            echo ""
            return
        fi
        test_dirs=("${failed_tests[@]}")
    # If tests were specified, use those
    elif [[ ${#filtered_tests[@]} -gt 0 ]]; then
        test_dirs=("${filtered_tests[@]}")
    else
        # Otherwise, discover all tests
        # Find all directories with test_info.json
        for dir in "$SCRIPT_DIR"/*/; do
            if [[ -d "$dir" && "$dir" != */templates/ && "$dir" != */build/ ]]; then
                local test_name=$(basename "$dir")
                if [[ -f "$dir/test_info.json" ]]; then
                    test_dirs+=("$test_name")
                fi
            fi
        done
    fi

    echo "${test_dirs[@]}"
}

# ==============================================================================
# Test Validation
# ==============================================================================

validate_test_setup() {
    local test_name="$1"
    local test_dir="$SCRIPT_DIR/$test_name"

    # Check for test_info.json
    if [[ ! -f "$test_dir/test_info.json" ]]; then
        return 1
    fi

    # Check for validate.py
    if [[ ! -f "$test_dir/validate.py" ]]; then
        return 2
    fi

    # Check for executable bit on validate.py
    if [[ ! -x "$test_dir/validate.py" ]]; then
        chmod +x "$test_dir/validate.py" 2>/dev/null || true
    fi

    return 0
}

# ==============================================================================
# Build Test
# ==============================================================================

build_test() {
    local test_name="$1"
    local build_start=$(date +%s%3N)

    cd "$SCRIPT_DIR/.."
    ./scripts/build_test.sh "$test_name" native $CLEAN_FLAG > /dev/null 2>&1
    local build_status=$?

    local build_end=$(date +%s%3N)
    local build_time=$((build_end - build_start))

    cd "$SCRIPT_DIR"

    echo "$build_status $build_time"
}

# ==============================================================================
# Run Test
# ==============================================================================

run_test() {
    local test_name="$1"
    local test_dir="$SCRIPT_DIR/$test_name"
    local executable="$test_dir/build/native/$test_name"

    if [[ ! -f "$executable" ]]; then
        return 1
    fi

    local run_start=$(date +%s%3N)

    # Check if test needs to preserve empty lines
    local preserve_empty=$(parse_json_field "$test_dir/test_info.json" "['execution']['preserve_empty_lines']" 2>/dev/null || echo "false")

    # Run test and capture output, filter runtime messages
    local output
    if [[ "$preserve_empty" == "True" || "$preserve_empty" == "true" ]]; then
        output=$("$executable" 2>&1 | filter_output_preserve_empty)
    else
        output=$("$executable" 2>&1 | filter_output)
    fi

    local run_end=$(date +%s%3N)
    local run_time=$((run_end - run_start))

    # Pass output to validation script
    local validation_json=$(echo "$output" | "$test_dir/validate.py" 2>/dev/null)

    if [[ -z "$validation_json" ]]; then
        # Validation script failed
        validation_json='{
            "passed": false,
            "sub_tests": [{
                "name": "validation_error",
                "passed": false,
                "expected": "valid JSON",
                "actual": "validation script failed",
                "message": "validate.py did not produce valid JSON output"
            }]
        }'
    fi

    echo "$validation_json|$run_time"
}

# ==============================================================================
# Process Test Result
# ==============================================================================

process_test_result() {
    local test_name="$1"
    local test_dir="$SCRIPT_DIR/$test_name"
    local validation_json="$2"
    local build_time="$3"
    local run_time="$4"

    # Parse validation results
    local passed=$(echo "$validation_json" | python3 -c "import json, sys; data=json.load(sys.stdin); print('true' if data.get('passed', False) else 'false')")

    # Parse opcodes from test_info.json
    local opcodes=$(parse_json_array "$test_dir/test_info.json" "['opcodes']['tested']")

    # Count sub-tests
    local sub_test_count=$(echo "$validation_json" | python3 -c "import json, sys; data=json.load(sys.stdin); print(len(data.get('sub_tests', [])))")
    local sub_test_passed=$(echo "$validation_json" | python3 -c "import json, sys; data=json.load(sys.stdin); print(sum(1 for t in data.get('sub_tests', []) if t.get('passed', False)))")

    # Update counters
    total_tests=$((total_tests + 1))
    total_sub_tests=$((total_sub_tests + sub_test_count))
    passed_sub_tests=$((passed_sub_tests + sub_test_passed))
    failed_sub_tests=$((failed_sub_tests + sub_test_count - sub_test_passed))

    if [[ "$passed" == "true" ]]; then
        passed_tests=$((passed_tests + 1))
        log_success "$test_name"
    else
        failed_tests=$((failed_tests + 1))
        log_error "$test_name"
        failed_test_names+=("$test_name")

        # Extract first failure message
        local failure_msg=$(echo "$validation_json" | python3 -c "import json, sys; data=json.load(sys.stdin); failed=[t for t in data.get('sub_tests',[]) if not t.get('passed',False)]; print(failed[0].get('message', f\"expected '{failed[0].get('expected','')}' but got '{failed[0].get('actual','')}'\" if failed else 'unknown error'))" 2>/dev/null || echo "unknown error")
        failed_test_messages+=("$failure_msg")
    fi

    # Build complete test result JSON
    # Convert bash boolean to Python boolean
    local passed_py="True"
    if [[ "$passed" != "true" ]]; then
        passed_py="False"
    fi

    # Convert opcodes to JSON array safely
    local opcodes_json=$(echo "$opcodes" | python3 -c "import sys, json; words=sys.stdin.read().strip().split(); print(json.dumps(words) if words else '[]')" 2>/dev/null || echo "[]")

    # Build test result by merging validation JSON with metadata
    # Use temporary files to safely pass JSON data
    local temp_validation=$(mktemp)
    local temp_opcodes=$(mktemp)
    echo "$validation_json" > "$temp_validation"
    echo "$opcodes_json" > "$temp_opcodes"

    local test_result=$(python3 - "$test_name" "$passed_py" "$build_time" "$run_time" "$temp_validation" "$temp_opcodes" <<'EOF'
import json
import sys

test_name = sys.argv[1]
passed = sys.argv[2] == "True"
build_time = int(sys.argv[3])
run_time = int(sys.argv[4])
temp_validation = sys.argv[5]
temp_opcodes = sys.argv[6]

# Read validation JSON from file
with open(temp_validation, "r") as f:
    validation_data = json.load(f)

# Read opcodes JSON from file
with open(temp_opcodes, "r") as f:
    opcodes_tested = json.load(f)

# Build complete test data
test_data = {
    "name": test_name,
    "passed": passed,
    "build_time_ms": build_time,
    "execution_time_ms": run_time,
    "opcodes_tested": opcodes_tested
}
test_data.update(validation_data)

print(json.dumps(test_data))
EOF
)
    local python_status=$?

    rm -f "$temp_validation" "$temp_opcodes"

    # Check if Python script failed
    if [[ $python_status -ne 0 || -z "$test_result" ]]; then
        echo "[ERROR] Failed to build test result JSON for $test_name" >&2
        test_result='{"name":"'$test_name'","passed":false,"error":"Failed to build result JSON"}'
    fi

    # Add to results file
    echo "$test_result" | add_test_result "$test_name"

    total_build_time=$((total_build_time + build_time))
    total_run_time=$((total_run_time + run_time))
}

# ==============================================================================
# Main Test Loop
# ==============================================================================

run_all_tests() {
    local specified_tests=("$@")

    # Discover tests BEFORE initializing results (so we can read previous failures)
    # Pass specified tests if any
    local test_dirs=($(discover_tests "${specified_tests[@]}"))

    # Now initialize the results file (preserving results for tests not being run)
    log_info "Initializing test results..."
    init_results_file "${test_dirs[@]}"

    if [[ ${#test_dirs[@]} -eq 0 ]]; then
        if [[ -n "$RETEST_FLAG" ]]; then
            log_info "No failed tests found in previous run"
        else
            log_warning "No tests found with test_info.json"
        fi
        return
    fi

    # Log appropriate message
    if [[ -n "$RETEST_FLAG" ]]; then
        log_info "Retest mode: Running ${#test_dirs[@]} previously failed test(s)"
    elif [[ ${#specified_tests[@]} -gt 0 ]]; then
        log_info "Running ${#test_dirs[@]} specified test(s)"
    else
        log_info "Discovered ${#test_dirs[@]} tests"
    fi

    # Handle --build flag (build SWFRecomp if needed)
    if [[ -n "$BUILD_FLAG" ]]; then
        log_info "Build mode enabled - ensuring SWFRecomp is built"

        # Get the SWFRecomp root directory (parent of tests directory)
        SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
        SWFRECOMP_BUILD="${SWFRECOMP_ROOT}/build"
        SWFRECOMP_EXE="${SWFRECOMP_BUILD}/SWFRecomp"

        # Check if SWFRecomp executable exists
        if [[ ! -f "$SWFRECOMP_EXE" ]]; then
            log_info "SWFRecomp not built, building now..."

            # Create build directory if it doesn't exist
            if [[ ! -d "$SWFRECOMP_BUILD" ]]; then
                mkdir -p "$SWFRECOMP_BUILD"
            fi

            cd "$SWFRECOMP_BUILD"

            # Run cmake if CMakeCache.txt doesn't exist
            if [[ ! -f "CMakeCache.txt" ]]; then
                log_info "Running CMake configuration..."
                cmake .. > /dev/null 2>&1
                if [[ $? -ne 0 ]]; then
                    log_error "CMake configuration failed"
                    exit 1
                fi
            fi

            # Build SWFRecomp
            log_info "Compiling SWFRecomp..."
            make -j > /dev/null 2>&1

            if [[ $? -ne 0 ]]; then
                log_error "Failed to build SWFRecomp"
                exit 1
            fi

            log_info "✅ SWFRecomp built successfully"
            cd "$SCRIPT_DIR"
        else
            log_info "✅ SWFRecomp already built"
        fi
    fi

    # Handle --clean flag (rebuild SWFRecomp with clean)
    if [[ -n "$CLEAN_FLAG" ]]; then
        log_info "Clean mode enabled - will regenerate all files from SWF sources"
        log_info "Rebuilding SWFRecomp with clean..."

        # Get the SWFRecomp root directory (parent of tests directory)
        SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
        SWFRECOMP_BUILD="${SWFRECOMP_ROOT}/build"

        # Create build directory if it doesn't exist
        if [[ ! -d "$SWFRECOMP_BUILD" ]]; then
            log_info "Build directory doesn't exist, creating it..."
            mkdir -p "$SWFRECOMP_BUILD"
            cd "$SWFRECOMP_BUILD"

            log_info "Running CMake configuration..."
            cmake .. > /dev/null 2>&1
            if [[ $? -ne 0 ]]; then
                log_error "CMake configuration failed"
                exit 1
            fi
        else
            cd "$SWFRECOMP_BUILD"
            make clean > /dev/null 2>&1
        fi

        # Build SWFRecomp
        make -j > /dev/null 2>&1

        if [[ $? -ne 0 ]]; then
            log_error "Failed to rebuild SWFRecomp"
            exit 1
        fi

        log_info "✅ SWFRecomp rebuilt successfully"
        cd "$SCRIPT_DIR"
    fi
    echo ""

    # Run each test
    local tests_run=0
    for test_name in "${test_dirs[@]}"; do
        # Check if we've hit the max test limit
        if [[ -n "$MAX_TESTS" && $tests_run -ge $MAX_TESTS ]]; then
            log_info "Reached maximum test limit ($MAX_TESTS tests)"
            break
        fi

        local test_dir="$SCRIPT_DIR/$test_name"

        # Validate test setup
        validate_test_setup "$test_name"
        local validation_status=$?

        if [[ $validation_status -eq 1 ]]; then
            log_warning "$test_name (missing test_info.json)"
            skipped_tests=$((skipped_tests + 1))
            continue
        elif [[ $validation_status -eq 2 ]]; then
            log_warning "$test_name (missing validate.py)"
            skipped_tests=$((skipped_tests + 1))
            continue
        fi

        # Build test
        local build_result=($(build_test "$test_name"))
        local build_status=${build_result[0]}
        local build_time=${build_result[1]}

        if [[ $build_status -ne 0 ]]; then
            log_error "$test_name (build failed)"
            total_tests=$((total_tests + 1))
            failed_tests=$((failed_tests + 1))
            failed_test_names+=("$test_name")
            failed_test_messages+=("Build failed")

            # Add failed build to results
            local test_result='{
                "name": "'$test_name'",
                "passed": false,
                "build_time_ms": '$build_time',
                "execution_time_ms": 0,
                "opcodes_tested": [],
                "sub_tests": [{
                    "name": "build",
                    "passed": false,
                    "expected": "successful build",
                    "actual": "build failed",
                    "message": "Test failed to build"
                }]
            }'
            echo "$test_result" | add_test_result "$test_name"
            total_build_time=$((total_build_time + build_time))
            continue
        fi

        # Run test and validate
        local run_result=$(run_test "$test_name")
        if [[ $? -ne 0 ]]; then
            log_error "$test_name (executable not found)"
            total_tests=$((total_tests + 1))
            failed_tests=$((failed_tests + 1))
            failed_test_names+=("$test_name")
            failed_test_messages+=("Executable not found")
            continue
        fi

        local validation_json="${run_result%|*}"
        local run_time="${run_result##*|}"

        # Process results
        process_test_result "$test_name" "$validation_json" "$build_time" "$run_time"

        # Increment tests_run counter
        tests_run=$((tests_run + 1))
    done

    # Update summary
    update_summary
}

# ==============================================================================
# Print Summary
# ==============================================================================

print_summary() {
    local end_time=$(date +%s%3N)
    local total_time=$((end_time - start_time))
    local total_time_sec=$(echo "scale=1; $total_time / 1000" | bc)
    local build_time_sec=$(echo "scale=1; $total_build_time / 1000" | bc)
    local run_time_sec=$(echo "scale=1; $total_run_time / 1000" | bc)

    echo ""
    echo "========================================"
    echo "  SWFRecomp Test Suite Results"
    echo "========================================"
    echo "Timestamp: $(date '+%Y-%m-%d %H:%M:%S')"
    echo ""

    # Test counts
    if [[ $failed_tests -eq 0 ]]; then
        echo -e "Tests:     ${GREEN}$passed_tests / $total_tests passed${NC}"
    else
        echo -e "Tests:     ${RED}$passed_tests / $total_tests passed${NC} ($failed_tests failed)"
    fi

    if [[ $skipped_tests -gt 0 ]]; then
        echo -e "           ${YELLOW}$skipped_tests skipped${NC}"
    fi

    # Sub-test counts
    if [[ $failed_sub_tests -eq 0 ]]; then
        echo -e "Sub-tests: ${GREEN}$passed_sub_tests / $total_sub_tests passed${NC}"
    else
        echo -e "Sub-tests: ${RED}$passed_sub_tests / $total_sub_tests passed${NC} ($failed_sub_tests failed)"
    fi

    # Timing
    echo ""
    echo "Time:      ${total_time_sec}s total (build: ${build_time_sec}s, run: ${run_time_sec}s)"

    # Failed tests detail
    if [[ $failed_tests -gt 0 ]]; then
        echo ""
        echo "FAILED TESTS:"
        for i in "${!failed_test_names[@]}"; do
            echo -e "  ${RED}[$((i + 1))]${NC} ${failed_test_names[$i]}"
            echo "      ${failed_test_messages[$i]}"
        done
    fi

    echo ""
    echo "Results saved to: $RESULTS_FILE"
    echo "========================================"
    echo ""
}

# ==============================================================================
# Main Entry Point
# ==============================================================================

main() {
    echo ""
    echo "========================================"
    echo "  SWFRecomp Test Suite"
    echo "========================================"
    echo ""

    run_all_tests "$@"
    print_summary

    # Exit with error if any tests failed
    if [[ $failed_tests -gt 0 ]]; then
        exit 1
    fi
}

main "$@"
