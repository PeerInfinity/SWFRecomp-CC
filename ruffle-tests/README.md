# Ruffle AVM1 Test Suite

Test SWFs from the [ruffle-rs/ruffle](https://github.com/ruffle-rs/ruffle) AVM1 test suite, used for regression testing of the SWFRecomp pipeline.

## Setup

Download the test SWFs (requires `git`):

```bash
./download_tests.sh
```

This uses a sparse checkout to download only the AVM1 test subtree from the Ruffle repository, rather than the entire codebase.

## Scripts

- **`download_tests.sh`** — Download/update test SWFs from the Ruffle repository
- **`run_tests.py`** — Run SWFRecomp against all test SWFs, report parse success/failure rates
- **`verify_output.py`** — Full pipeline: recompile, compile with runtime, run, and compare trace output against expected `output.txt`

## Usage

```bash
# Test recompiler parsing
python3 run_tests.py

# Verify runtime output (first 50 tests)
python3 verify_output.py --limit=50 -v --diff

# Verify a single test
python3 verify_output.py --test=trace -v --diff

# Save results as JSON (used by CI)
python3 verify_output.py --json=results.json
```

## CI

The `Ruffle AVM1 Tests` GitHub Actions workflow can be triggered manually from the Actions tab. It downloads the test SWFs, builds SWFRecomp, runs the full verification suite, and uploads the JSON results as an artifact. An optional `limit` parameter controls how many tests to run (default: all).
