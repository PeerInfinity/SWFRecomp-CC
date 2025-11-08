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
    grep -v "SWF Runtime Loaded" | \
    grep -v "=== SWF" | \
    grep -v "\[Frame" | \
    grep -v "\[Tag\]" | \
    grep -v "\[DEBUG" | \
    grep -v "^$" || true
}

# Initialize results JSON file
init_results_file() {
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
}

# Add test result to JSON file
add_test_result() {
    local test_name="$1"
    local test_result_json="$2"

    # Use Python to append test result to JSON array
    python3 <<EOF
import json

# Read existing results
with open('$RESULTS_FILE', 'r') as f:
    data = json.load(f)

# Parse new test result
test_result = json.loads('''$test_result_json''')

# Append to tests array
data['tests'].append(test_result)

# Write back
with open('$RESULTS_FILE', 'w') as f:
    json.dump(data, f, indent=2)
EOF
}

# Update summary in results file
update_summary() {
    python3 <<EOF
import json

with open('$RESULTS_FILE', 'r') as f:
    data = json.load(f)

data['summary'] = {
    "total_tests": $total_tests,
    "passed": $passed_tests,
    "failed": $failed_tests,
    "skipped": $skipped_tests,
    "total_sub_tests": $total_sub_tests,
    "passed_sub_tests": $passed_sub_tests,
    "failed_sub_tests": $failed_sub_tests
}

with open('$RESULTS_FILE', 'w') as f:
    json.dump(data, f, indent=2)
EOF
}

# ==============================================================================
# Test Discovery
# ==============================================================================

discover_tests() {
    local specified_tests=("$@")

    local test_dirs=()

    # If tests were specified, use those
    if [[ ${#specified_tests[@]} -gt 0 ]]; then
        test_dirs=("${specified_tests[@]}")
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
    ./scripts/build_test.sh "$test_name" native > /dev/null 2>&1
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

    # Run test and capture output, filter runtime messages
    local output=$("$executable" 2>&1 | filter_output)

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

    local test_result=$(python3 <<EOF
import json
test_data = {
    "name": "$test_name",
    "passed": $passed_py,
    "build_time_ms": $build_time,
    "execution_time_ms": $run_time,
    "opcodes_tested": $(echo "$opcodes" | python3 -c "import sys; words=sys.stdin.read().strip().split(); print(json.dumps(words) if words else '[]')" 2>/dev/null || echo "[]")
}
validation_data = json.loads('''$validation_json''')
test_data.update(validation_data)
print(json.dumps(test_data))
EOF
)

    # Add to results file
    add_test_result "$test_name" "$test_result"

    total_build_time=$((total_build_time + build_time))
    total_run_time=$((total_run_time + run_time))
}

# ==============================================================================
# Main Test Loop
# ==============================================================================

run_all_tests() {
    local specified_tests=("$@")

    log_info "Initializing test results..."
    init_results_file

    # Discover tests (pass specified tests if any)
    local test_dirs=($(discover_tests "${specified_tests[@]}"))

    if [[ ${#test_dirs[@]} -eq 0 ]]; then
        log_warning "No tests found with test_info.json"
        return
    fi

    # Log appropriate message
    if [[ ${#specified_tests[@]} -gt 0 ]]; then
        log_info "Running ${#test_dirs[@]} specified test(s)"
    else
        log_info "Discovered ${#test_dirs[@]} tests"
    fi
    echo ""

    # Run each test
    for test_name in "${test_dirs[@]}"; do
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
            add_test_result "$test_name" "$test_result"
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
