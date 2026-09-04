# SWFRecomp-CC Project Instructions

## Git Workflow

This repo is trunk-based: commit directly to `master`. Do NOT create a branch
before committing, even when default Git guidance says to branch first when on
the default branch.

**Autonomous commit / push / CI is authorized** (standing approval — you do NOT
need to ask first). When a task is finished, blocked, or paused with meaningful
progress, run the pipeline end-to-end per `.claude/pipeline-handoff.md`: stage
the relevant files by name (never `git add -A`), commit with the standard
`Co-Authored-By` trailer, push to `master`, trigger the `ruffle-tests.yml`
workflow in the matching mode, wait for completion with `gh run watch`, merge the
`ruffle-test-results` branch, and report any regressions. End commit messages
with the project's standard trailer. Use the `.pipeline-state` file (gitignored)
to make the pipeline resumable across sessions.

- **CI mode** (`.claude/pipeline-handoff.md` §"Build mode"): `graphics` is the
  per-change default (production frame loop). Dispatch `no-graphics` per-change
  ONLY when the change touches no-graphics-only code (`swf_core.c`,
  `tag_stubs.c`, `#ifdef NO_GRAPHICS` arms without `|| OFFSCREEN_RENDER`);
  otherwise the weekly `weekly-no-graphics.yml` canary covers it. When in
  doubt for shared runtime code, run both.
- **CI categories**: `all` (classic five suites) is the per-change default;
  use `categories=full` (adds from_avmplus + the misc group, ~+73% tests)
  when the change touches AVM2 runtime/recompiler emission. Weekly canary
  runs `full`.
  Policy: `ruffle-tests/tests/swfs/_investigation/FULL_SUITE_IMPORT_AUDIT.md`
  §"Which tests run when".
- **CI images** (`.claude/pipeline-handoff.md` §"`images`"): `images=false`
  is the per-change default and must stay that way — `images=true` is a
  deliberate render-baseline run (publishes `image_results_graphics.json`
  and force-pushes failing PNGs to the `ruffle-image-results` branch).
  Image comparisons never gate trace pass/fail. Baseline:
  `SWFRecompDocs/plans/graphics-image-baseline.md`.
- **GitHub Pages deploy is authorized** (standing approval, added 2026-09-02):
  after changing `docs/` or the in-browser recompiler
  (`docs/recompiler/`, `SWFRecomp/scripts/deploy_wasm_demo.sh`,
  `SWFRecomp/wasm_wrappers/bundle/`), dispatch
  `gh workflow run deploy-pages.yml --ref master` and watch it. The workflow
  builds `SWFRecomp.wasm` and the runtime-snapshot build bundle at deploy time
  (never commit those — they are gitignored). `-f dry_run=true` runs every build
  step but skips the upload; use it to validate workflow changes first.
- Never rewrite published git history (no force-push / filter-repo), even to
  purge large files that were committed by mistake; untrack them going forward.
- Still ask before anything genuinely irreversible or out of scope (force-pushing
  over others' work, rewriting published history, deleting branches, etc.).
- A failing-but-completed CI run is a result to report, not a blocker — surface
  regressions (pass→fail) by name.

## Current Focus: Ruffle AVM1 Test Suite

We are improving the pass rate on the Ruffle AVM1 test suite (ActionScript 1/2 trace tests).

**Key docs to read at session start:**
- `ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md` — architecture, how to run tests, infrastructure (all suites)
- `ruffle-tests/tests/swfs/_investigation/OVERVIEW.md` — cross-suite summary (avm1, gnash, shumway)
- Per-suite status: `ruffle-tests/tests/swfs/{suite}/_investigation/CURRENT_STATUS.md`
- For debugging full games (flasharchive/glaiel): `SWFRecompDocs/guides/wasm-game-debugging-session-guide.md` — divergence-harness-first workflow, headless-vs-browser task triage, tools, session-prompt template

**Quick test commands:**
```bash
# Run a single Ruffle test locally (default: NO_GRAPHICS / swf_core.c)
python3 ruffle-tests/verify_output.py --test=TEST_NAME --diff --verbose

# Run against the --mode=graphics native build (swf.c + offscreen Dawn).
# Mode parity as of 2026-09-04: per-test results are identical to no-graphics
# across all suites EXCEPT ONE — `from_gnash/misc-swfc.all/gotoFrameFromInterval2`
# is `output_mismatch` under graphics and `ruffle_matched` under no-graphics.
# That gap is stable, not a flake: identical on both sides of five consecutive
# slice diffs. It is filed in BACKLOG; treat "parity" as 1-test-short rather
# than complete. (The old "case-v6 CI flake" was 3 real heap bugs, fixed
# 2026-05-28 in d905efdb1 — that one IS closed.)
# Graphics is also the per-change CI mode (see Git Workflow above). See
# SWFRecompDocs/plans/graphics-native-test-mode-*.md for the plan,
# playbook, and full-suite baseline.
# Local Dawn install required at ~/CC/dawn-install (or set DAWN_INSTALL env var).
python3 ruffle-tests/verify_output.py --test=TEST_NAME --mode=graphics --diff

# CI dispatch (graphics modes auto-build Dawn on cache miss; ~30 min the
# first time, ~6 min on subsequent runs):
gh workflow run ruffle-tests.yml --ref master -f mode=graphics -f single_test=TEST_NAME
# NOTE: `single_test` resolves the bare name against `tests/swfs/avm1` ONLY —
# the workflow passes no `--tests-dir` and verify_output.py defaults there. A
# name from any other suite "fails" on path lookup, which is NOT a verdict on
# the test. Verified 2026-09-04 after a session nearly read one as confirmation.
```

**IMPORTANT: Do NOT run full test suites locally.** Never run `all_tests.sh`, `verify_output.py` without `--test`, or any command that runs all tests on this machine. Only run individual tests locally with `--test=TEST_NAME`. To run the full suite, commit and trigger CI yourself via the pipeline (`.claude/pipeline-handoff.md`) — autonomous CI is authorized (see Git Workflow above).

## Project Structure

- `SWFRecomp/` — Recompiler: converts SWF bytecode to C (`src/action/action.cpp` is the main bytecode→C translator)
- `SWFModernRuntime/` — Runtime: executes the generated C (`src/actionmodern/action.c` is ~50K lines, the core runtime)
- `ruffle-tests/` — Ruffle test suites (since 2026-07-24 the FULL upstream corpus is mirrored, no AVM filtering; see `tests/swfs/_investigation/FULL_SUITE_IMPORT_AUDIT.md`):
  - `tests/swfs/avm1/` — ~720 AVM1 tests from Ruffle (100% filtered pass rate)
  - `tests/swfs/avm2/` — ~1220 AVM2 tests from Ruffle
  - `tests/swfs/from_avmplus/` — 1574 AVM2 tests (Adobe Tamarin acceptance: ecma3/as3/e4x/regress)
  - `tests/swfs/from_gnash/` — 404 tests from Gnash (5 sub-suites)
  - `tests/swfs/from_shumway/` — 229 tests from Shumway (AVM1 + AVM2, unfiltered)
  - nine small categories (`timeline`, `text`, `swf`, `import_assets`, `audio`, `fonts`, `visual`, `mixed_avm`, `stage3d`) — ~215 tests, CI `misc` group
  - `tests/swfs/regression/` — hand-written by this project, never downloaded; fully git-tracked. Run with `--tests-dir=ruffle-tests/tests/swfs/regression`. New custom tests go here, NOT in the upstream mirrors above (see that suite's `README.md`).
- `SWFRecomp/tests/` — Old hand-written test suite (158 trace tests + 59 graphics tests, all passing)
- `SWFRecomp/scripts/` — Build scripts (build_test.sh, deploy_example.sh, etc.)
- `scripts/` — Test result processing scripts (diff, markdown generation)

## Two Test Systems

1. **Ruffle tests** (`ruffle-tests/tests/swfs/avm1/`): 641 tests from Ruffle project. Shared runner `verify_output.py`. Expected output in `output.txt` per test. Results in `results.json`. CI via GitHub Actions workflow (manual dispatch).

2. **Old tests** (`SWFRecomp/tests/`): 115 hand-written tests. Per-test `validate.py` validators. Runner is `all_tests.sh`. Results in `test_results.json`. Run locally only.

## Browser Performance Measurement (standing capability — don't rediscover)

- **WSL/WSLg Chrome is SwiftShader (software rendering). NEVER use it for
  performance numbers or frame-rate A/Bs** — every "gap" it shows is an
  artifact. It's fine for functional/rendering-correctness probes.
- **Real-GPU browser perf is measured FROM WSL by driving Windows Chrome via
  WSL interop**: call `python.exe` (the Windows Python has Playwright;
  `python3` is Linux and doesn't), keep scripts + outputs on the Windows disk
  at `C:\playwright\` (= `/mnt/c/playwright/`, use `wslpath -w`), serve docs2
  from WSL (`python3 -m http.server 8010` → `http://localhost:8010/`).
  Full recipe, driver scripts, and the three interop gotchas:
  `tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`.

## Critical Runtime Architecture Notes

- `ASObject` and `ASFunction` are **different structs** — never cast one to the other. Functions have `prototype_obj` and `own_props` fields; objects have a `properties` array. Code that handles both types must check the ActionVar type tag first.
- Stack is a byte buffer with PUSH/POP macros. String values store a pointer (not inline data) at offset +16.
- Type system: `ActionVar` with type tag (`ACTION_STACK_VALUE_STRING=0, F32=1, NULL=2, UNDEFINED=3, BOOLEAN=5, F64=6, OBJECT=11, ARRAY=12, FUNCTION=13, MOVIECLIP=14`)
- Scope resolution: WITH scope chain → global variables → undefined
- `emsdk_env.sh` is at `SWFRecomp-CC/emsdk/emsdk_env.sh`
- Build scripts are under `SWFRecomp/scripts/`, NOT project root `scripts/`
- If running locally, the Ruffle source repository is available at `~/CC/ruffle`
- **Test determinism**: `Math.random` and `Date.getTime()` are seeded per-test via the `MOCK_DATE_TIME` macro that `verify_output.py` defines on every gcc invocation (default `981152406000` ms = 2001-02-03 04:05:06 NPT, matching Ruffle's `--deterministic` mode; per-test override via `mock_date_time` in `test.toml`). `math.c::GenerateRandomNumber` uses `MOCK_DATE_TIME * 1000` µs as the avmplus RNG seed. Two CI runs at the same SHA produce byte-identical results across all suites — if results "fluctuate," look for an actual bug, not RNG variance.
- MTASC (ActionScript 2 compiler) is at `~/CC/mtasc/`. Binary: `~/CC/mtasc/bin/mtasc`. Requires `-cp ~/CC/mtasc/ocaml/mtasc/std` for the standard library. Example: `~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -main -header 200:150:30 Test.as -swf test.swf -version 8`

## Documenting Accepted Diffs and Ruffle/Flash Differences

Three investigation docs track cases where test diffs are permanent or intentional:

- `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md` — Tests where some output lines will **never match** due to platform UB, inconsistent expected output, Flash quirks we can't replicate, or Flash UB we intentionally don't replicate. Each entry documents the category, example diff, explanation, and decision.
- `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` — Tests where our implementation **matches Flash's actual behavior** but disagrees with Ruffle's expected output (i.e., the Ruffle test expectation reflects Ruffle's own behavior, not Flash's).
- `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_COMPAT_TWEAKS.md` — Pragmatic implementation choices made specifically to match Ruffle's expected test output, where the "correct" behavior is unclear or unspecified (e.g., +1 pixel on text field bounds).
- `ruffle-tests/tests/swfs/avm1/_investigation/FLASH_BUGS_REPLICATED.md` — Known Flash Player bugs that we deliberately replicate. Both Flash and Ruffle exhibit the same buggy behavior, and our implementation matches both (e.g., colorTransform aMult-only no-op).

**When to update these docs:**
- If you discover a test diff that cannot be fixed because it depends on C undefined behavior, platform-specific results, or internally inconsistent expected output → add it to `ACCEPTED_DIFFS.md` under the appropriate category.
- If you discover a test diff where our output matches Flash's documented/known behavior but Ruffle's expected output reflects Ruffle's own divergent implementation → add it to `RUFFLE_VS_FLASH_DIFFERENCES.md`.
- If you make an arbitrary implementation choice (not clearly documented in Flash specs) specifically to match Ruffle's expected output → add it to `RUFFLE_COMPAT_TWEAKS.md`.
- If you deliberately replicate a documented Flash Player bug to match both Flash and Ruffle behavior → add it to `FLASH_BUGS_REPLICATED.md`.
- Always include: test name, example diff, explanation of why it's unfixable/intentional, and the decision.
- Update the summary table in `ACCEPTED_DIFFS.md` when adding new entries.
- When adding a test to `ACCEPTED_DIFFS.md`, also add it to `ruffle-tests/ignored_tests.txt` so it is excluded from filtered results.
