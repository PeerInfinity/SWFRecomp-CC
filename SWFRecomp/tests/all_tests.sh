#!/bin/bash

# Updated test script that works with the new testing system
# Skips old tests that don't have test.swf and don't have a generation script

readarray -t arr < test_vecs.txt

pids=()

num_tests=$((0))
num_passed=$((0))
num_skipped=$((0))

# First, identify which tests can be run
declare -a runnable_tests
declare -a skipped_tests

for i in $(seq 0 $((${#arr[@]} - 1)))
do
	dir="$(echo ${arr[i]} | head -n1 | awk '{print $1;}')"

	# Check if test.swf exists OR if there's a generation script
	if [ -f "$dir/test.swf" ] || [ -f "$dir/create_test_swf.py" ] || [ -f "$dir/generate_swf.py" ] || [ -f "$dir/make_test.py" ] || [ -f "$dir/create_swf.py" ]; then
		runnable_tests+=("$i")
	else
		skipped_tests+=("$i")
		echo "SKIPPING: $dir (no test.swf and no generation script)"
		num_skipped=$((num_skipped + 1))
	fi
done

echo ""
echo "Running ${#runnable_tests[@]} tests (${num_skipped} skipped)"
echo ""

# Build all runnable tests in parallel using the new build system
for idx in "${runnable_tests[@]}"
do
	dir="$(echo ${arr[idx]} | head -n1 | awk '{print $1;}')"
	test_name="$(basename $dir)"

	# Use the new build_test.sh script
	bash -c "cd .. && ./scripts/build_test.sh $test_name native > /dev/null 2>&1" &
	pids+=("$!")
	num_tests=$((num_tests + 1))
done

# Wait for builds to complete and run tests
for i in $(seq 0 $((${#runnable_tests[@]} - 1)))
do
	idx="${runnable_tests[i]}"

	wait ${pids[i]}
	build_status=$?

	dir="$(echo ${arr[idx]} | head -n1 | awk '{print $1;}')"
	test_name="$(basename $dir)"
	expected="$(echo ${arr[idx]} | cut -d' ' -f2- | sed 's/^"\(.*\)"$/\1/')"

	echo "Testing: $test_name"

	# Check if build succeeded
	if [ $build_status -ne 0 ]; then
		echo "  BUILD FAILED"
		echo ""
		continue
	fi

	# Run the test using the new build output location
	if [ -f "$dir/build/native/$test_name" ]; then
		# Filter out all runtime messages, keep only trace output
		result=$("$dir/build/native/$test_name" 2>&1 | grep -v "SWF Runtime Loaded" | grep -v "=== SWF" | grep -v "\[Frame" | grep -v "\[Tag\]" | grep -v "^$" | head -n1)

		echo "  Expected: \`$expected'"
		echo "  Actual:   \`$result'"
		echo ""

		if [[ "$result" == "$expected" ]]; then
			echo "  PASSED"
			num_passed=$((num_passed + 1))
		else
			echo "  FAILED"
		fi
	else
		echo "  EXECUTABLE NOT FOUND: $dir/build/native/$test_name"
	fi

	echo ""
done

echo "========================================"
echo "Results: Passed $num_passed/$num_tests tests"
echo "Skipped: $num_skipped tests (old system, missing SWF files)"
echo ""
