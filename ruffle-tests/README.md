# Ruffle AVM1 Test Suite

Test SWFs from the [ruffle-rs/ruffle](https://github.com/ruffle-rs/ruffle) AVM1 test suite, used for regression testing of the SWFRecomp pipeline.

## Setup

Download the test SWFs (requires `gh` CLI):

```bash
./download_tests.sh
```

## Scripts

- **`run_tests.py`** — Run SWFRecomp against all test SWFs, report parse success/failure rates
- **`verify_output.py`** — Full pipeline: recompile, compile with runtime, run, and compare trace output against expected `output.txt`
- **`download_tests.sh`** — Download/update test SWFs from the Ruffle repository

## Usage

```bash
# Test recompiler parsing
python3 run_tests.py

# Verify runtime output (first 50 tests)
python3 verify_output.py --limit=50 -v --diff

# Verify a single test
python3 verify_output.py --test=trace -v --diff
```
