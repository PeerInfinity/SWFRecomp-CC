# Cloud Environment Setup

This document describes how to set up a fresh cloud environment (Ubuntu x86_64) to build
the recompiler and run Ruffle AVM1 tests locally.

## Prerequisites

The following tools must be present. On Ubuntu 24.04 they are all available in the standard
package repos:

```
gcc       >= 13      (tested: 13.3.0)
cmake     >= 3.28    (tested: 3.28.3)
python3   >= 3.11    (tested: 3.11.14, uses only stdlib — no pip deps)
git
make
```

Install with:

```bash
sudo apt-get install -y gcc cmake python3 git make
```

No Python packages beyond the standard library are required.

## Step 1 — Build the Recompiler

The `SWFRecomp/build/` directory does not exist in a fresh checkout and must be created.

```bash
# From the project root (SWFRecomp-CC/)
mkdir -p SWFRecomp/build
cd SWFRecomp/build
cmake ..
make -j$(nproc)
cd ../..
```

This produces `SWFRecomp/build/SWFRecomp`, the binary used by `verify_output.py`.
The build takes under two minutes on a 16-core machine.

## Step 2 — Download Test SWFs

The Ruffle test SWFs are **not** stored in this repository. They are fetched from the
upstream `ruffle-rs/ruffle` GitHub repo via sparse git checkout (~60 MB):

```bash
cd ruffle-tests
bash download_tests.sh
cd ..
```

This populates `ruffle-tests/<test_name>/` directories, each containing `test.swf`,
`output.txt`, and `test.toml`. Expect ~620 test directories when complete.

The script is idempotent. Re-running it skips directories that already exist (use
`--clean` to force a fresh download).

## Step 3 — Verify the Pipeline

Run a single test end-to-end to confirm the build and runtime are working:

```bash
python3 ruffle-tests/verify_output.py --test=add --diff --verbose
```

Expected output:

```
[1/1] add... PASS

============================================================
Total tests:     1
Pass:            1 (100.0%)
Fail:            0
```

If the test passes, the environment is fully operational.

## Subsequent Sessions

Steps 1 and 2 only need to be done once per environment. In later sessions:

- **Rebuild after source changes:**
  ```bash
  cd SWFRecomp/build && make -j$(nproc) && cd ../..
  ```

- **Run a test:**
  ```bash
  python3 ruffle-tests/verify_output.py --test=TEST_NAME --diff --verbose
  ```

- **Run several tests at once:**
  ```bash
  python3 ruffle-tests/verify_output.py --test=test1 --test=test2 --diff --verbose
  ```

- **Do not run the full suite locally.** Commit and push, then trigger the
  "Ruffle AVM1 Tests" GitHub Actions workflow (see `SESSION_START_GUIDE.md`).

## How `verify_output.py` Works

For each test the script:

1. Runs `SWFRecomp/build/SWFRecomp` on `test.swf` to generate C under
   `ruffle-tests/<test_name>/RecompiledScripts/` and `RecompiledTags/`.
2. Compiles the generated C together with `SWFModernRuntime` sources using `gcc`
   (`-DNO_GRAPHICS`, `-std=c17`, `-O2`) into a temporary native binary.
3. Executes the binary and filters out runtime boilerplate lines.
4. Compares the filtered output line-by-line against `output.txt`.

No emscripten / WASM toolchain is required for the Ruffle tests — native gcc is enough.

## Troubleshooting

| Symptom | Likely cause | Fix |
|---------|-------------|-----|
| `SWFRecomp: No such file or directory` | Build not done | Run Step 1 |
| `No test directories found` | SWFs not downloaded | Run Step 2 |
| `cmake` fails | CMake too old or missing | `apt-get install cmake` |
| `recompile timeout` | Low memory limit | ulimit set to 4 GB in script; should be fine with ≥ 8 GB RAM |
| Compile error in test C | Runtime/recompiler mismatch | Rebuild recompiler after pulling latest code |
