# ruffle-tests: the test harness

This directory runs SWFRecomp-CC against the test corpus of the [Ruffle](https://github.com/ruffle-rs/ruffle) project
(`tests/tests/swfs/` upstream): Ruffle's own AVM1 and AVM2 tests plus the ones Ruffle imported from Gnash, Shumway and
Adobe's Tamarin (avmplus). Each test is a `test.swf`, its expected trace output `output.txt`, and often a `test.toml`
(frame count, options, image comparisons). Our target is Flash Player 32, so goldens that a real FP32 capture shows to
be wrong are corrected (see `flash_fixes/` below).

Setup and a first run: [`../GETTING_STARTED.md`](../GETTING_STARTED.md).

## Layout

| Path | What | In git? |
|---|---|---|
| `tests/swfs/<suite>/` | The upstream suites: `avm1`, `avm2`, `from_avmplus`, `from_gnash/*`, `from_shumway`, and nine small ones (`visual`, `timeline`, `text`, `swf`, `import_assets`, `audio`, `fonts`, `mixed_avm`, `stage3d`) | **No**: fetched by `download_tests.sh`. Only each suite's `_results/` and `_investigation/` (and a few harness files) are tracked |
| `tests/swfs/regression/` | This project's own fixtures (most goldens are FP32 captures). New hand-written tests go here, never into the upstream mirrors ([`README`](tests/swfs/regression/README.md)) | Yes |
| `tests/swfs/<suite>/_results/` | Per-test results from CI: `results_graphics.json` / `results.json` (no-graphics), with Markdown summaries and diffs | Yes, written by CI |
| `tests/swfs/<suite>/_investigation/` | Per-suite status and analysis notes | Yes |
| `results/` | Cross-suite tables, e.g. [`RUFFLE_RESULTS_GRAPHICS.md`](results/RUFFLE_RESULTS_GRAPHICS.md) | Yes, written by CI |
| `flash_fixes/` | Goldens corrected to real FP32 output, re-applied after every download ([`README`](flash_fixes/README.md)) | Yes |
| `ignored_tests.txt` | Tests excluded from the `_FILTERED` tables, each with its reason | Yes |
| `tests/swfs/_rando/`, `tests/swfs/_swfbridge/` | Tests and live harnesses for host integrations (the Archipelago randomizer build, the browser bridge) | Yes |

## Scripts

| Script | What |
|---|---|
| `download_tests.sh [suite…]` | Sparse-checks-out the upstream suites (default `avm1`), installs them under `tests/swfs/`, then runs `apply_flash_fixes.py`. `--clean` re-downloads; `--clean-cache` removes generated C only |
| `verify_output.py` | The harness: recompile → compile with the runtime → run → compare. `--test=NAME` (repeatable), `--tests-dir=…/<suite>`, `--mode=no-graphics\|graphics`, `--diff`, `--verbose`, `--images` (pixel comparisons, needs Pillow), `--asan`. `--help` lists the rest |
| `apply_flash_fixes.py [--check]` | Applies or checks the `flash_fixes/` manifest |
| `run_image_tests.py`, `triage_image_tests.py`, `render_canary.py` | Image-comparison tooling for graphics mode |
| `run_tests.py` | Recompile-only smoke test (does the recompiler accept every SWF?) |
| `filter_results.py`, `swf_is_avm2.py`, `build_test_debug.py` | Helpers |

## Running tests

```bash
# one AVM1 test (the default suite is avm1)
python3 ruffle-tests/verify_output.py --test=add --diff --verbose

# a test in another suite
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=hello_world --diff

# graphics mode (needs Dawn; see GETTING_STARTED §6)
python3 ruffle-tests/verify_output.py --test=add --mode=graphics --diff
```

Run single tests locally. The full corpus (more than 4,900 tests) is run by CI: the `Ruffle Tests` workflow
(`.github/workflows/ruffle-tests.yml`, manual dispatch) shards it across 30 runners and publishes the results to the
`ruffle-test-results` branch, which is merged into `master`.

## Statuses

`pass` means the trace output matches `output.txt` exactly. `ruffle_matched` applies to tests that Ruffle itself marks as a
known failure: every remaining difference is one that Ruffle's own output (`output.ruffle.txt`) also has. It is counted
as "effective" but is not a Flash pass. Everything else (`output_mismatch`, `runtime_error`, `segfault`, `timeout`, `compile_fail`, …) is a failure.
Image comparisons are reported separately and never change a test's status.

Where to look before calling a difference a bug: `ignored_tests.txt` and `tests/swfs/avm1/_investigation/`
(`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md`).
Development notes for this harness: [`SESSION_START_GUIDE.md`](tests/swfs/_investigation/SESSION_START_GUIDE.md).
