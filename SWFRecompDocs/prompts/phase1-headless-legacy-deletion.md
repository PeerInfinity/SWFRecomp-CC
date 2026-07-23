# Session prompt: delete the `graphics-headless-legacy` mode (Phase 1)

Paste everything below this line into a fresh session.

---

Execute **Phase 1 of `SWFRecompDocs/plans/mode-consolidation-plan.md`**: delete
the `graphics-headless-legacy` test mode (`swf_headless.c` + the
`HEADLESS_GRAPHICS` define) end-to-end. Read that plan section first. The mode
has had zero callers since 2026-05-12; `no-graphics` and `graphics` are the two
surviving modes and their behavior must be **completely unchanged** by this
work — this is a pure deletion/simplification, not a refactor.

## Key fact for gate reduction

Headless-legacy builds defined **both** `NO_GRAPHICS` and `HEADLESS_GRAPHICS`
(plus `USE_WEBGPU`). After this change `HEADLESS_GRAPHICS` is never defined, so
reduce every preprocessor condition by substituting
`defined(HEADLESS_GRAPHICS)` → false:

| Pattern (as found) | Becomes |
|---|---|
| `!defined(NO_GRAPHICS) \|\| defined(HEADLESS_GRAPHICS)` | `#ifndef NO_GRAPHICS` |
| `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER) && !defined(HEADLESS_GRAPHICS)` (any order) | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` |
| `defined(HEADLESS_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | `#ifdef OFFSCREEN_RENDER` |
| `defined(NO_GRAPHICS) \|\| defined(HEADLESS_GRAPHICS)` (± `\|\| OFFSCREEN_RENDER`) | drop the HEADLESS term |
| `!defined(OFFSCREEN_RENDER) && !defined(HEADLESS_GRAPHICS)` | `#ifndef OFFSCREEN_RENDER` |
| `!defined(HEADLESS_GRAPHICS)` alone | gate is always true — remove the `#if`/`#endif` pair, keep the body |
| `#ifdef HEADLESS_GRAPHICS` alone | delete the whole block |

Preserve surrounding `#else`/`#elif` structure carefully — several sites are
three-way (no-graphics / graphics-native / browser-WASM) and the browser-WASM
arm must keep exactly the code it has today. Also update `#endif // ...`
trailer comments that mention the removed terms.

## Inventory (2026-07-23, `grep -rn HEADLESS_GRAPHICS`, vendor/ excluded)

Runtime sources (~90 refs):
- `SWFModernRuntime/src/libswf/tag.c` — 52
- `SWFModernRuntime/src/libswf/tag_stubs.c` — 14
- `SWFModernRuntime/src/libswf/swf_headless.c` — **delete the file** (and any
  build references to it)
- `SWFModernRuntime/src/actionmodern/action.c` — 4 (lines ~26842/27194 pair,
  ~33214, ~46156)
- `SWFModernRuntime/src/libswf/swf.c` — 3, `graphics_stubs.c` — 3,
  `shape_hit_test.c` — 1, `ng_shared.c` — 1
- `SWFModernRuntime/src/rendering/render_webgpu.c` — 3, `render_stub.c` — 1
- Headers: `include/rendering/render_webgpu.h` (2), `include/libswf/tag.h` (2),
  `include/rendering/renderer.h`, `include/libswf/swf.h`,
  `include/libswf/capture.h` (1 each)
- `SWFRecomp/wasm_wrappers/main.c` — 1
- `SWFModernRuntime/CMakeLists.txt` — 9 (drop the `option(HEADLESS_GRAPHICS)`
  and its branch)

Tooling / CI:
- `ruffle-tests/verify_output.py` AND `ruffle-tests/verify_output_keep.py` —
  these are deliberately kept as near-twins (~5 line diff); apply identical
  edits to both. Remove the `graphics-headless-legacy` mode branch (source
  list, `-DHEADLESS_GRAPHICS` defines, `results_headless` stem). The
  deprecated `--headless` flag must **error out** with a message pointing to
  `--mode=graphics` — do NOT silently remap it (results files differ).
- `SWFRecomp/scripts/build_test.sh` — remove the `--headless` branch and usage
  text.
- `.github/workflows/ruffle-tests.yml` — 11 refs: mode input description,
  `graphics-headless-legacy` cases in the baseline/stem `case` statements.
- `scripts/generate_ruffle_results_markdown.py` (8),
  `ruffle-tests/filter_results.py` (3), `scripts/generate_results_index.py`
  (2) — remove the headless stem handling.

Stale result files — `git rm` all 9:
- `ruffle-tests/tests/swfs/avm1/_results/results_headless{.json,.md,_filtered.json,_filtered.md,_regressions.md}`
- `ruffle-tests/tests/swfs/from_shumway/timeline/_results/results_headless{.json,.md}`
- `ruffle-tests/tests/swfs/from_gnash/misc-ming.all/displaylist_depths/_results/results_headless{.json,.md}`

Docs:
- `SWFRecompDocs/plans/graphics-native-test-mode-plan.md` — mark Phase 3
  (headless retirement) complete with today's date.
- Sweep `ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md` and
  `SWFRecompDocs/plans/graphics-native-test-mode-playbook.md` for `--headless`
  / headless-legacy instructions; update or annotate as historical.
- Do NOT rewrite historical status docs under `SWFRecompDocs/status/` — leave
  them as records.

## Constraints

- Do not change any condition's meaning for the surviving modes. If a
  reduction is ambiguous at some site, stop and re-derive from the table; if
  still ambiguous, leave that site intact and flag it in your report rather
  than guessing.
- Do not touch `NO_GRAPHICS`/`OFFSCREEN_RENDER` gates that don't mention
  `HEADLESS_GRAPHICS`.
- `SWFModernRuntime/vendor/` is out of scope.
- **Never run full test suites locally** (CLAUDE.md rule) — single tests only.

## Verification

1. `grep -rn HEADLESS_GRAPHICS` over the repo returns only historical docs
   (`SWFRecompDocs/status/`, plan history sections) — no code, build scripts,
   or CI.
2. `grep -rn -- --headless` similarly clean (the new error message in the two
   verify scripts is the only code hit).
3. Local single tests in BOTH surviving modes:
   - `python3 ruffle-tests/verify_output.py --test=SOME_BASIC_AVM1_TEST --diff`
   - same with `--mode=graphics` (needs Dawn at `~/CC/dawn-install`)
   - plus one from_gnash misc-ming.all test in both modes via that suite's
     `--tests-dir`.
   - confirm `--headless` now errors with the pointer message.
4. Run the full pipeline per `.claude/pipeline-handoff.md` (autonomous
   commit/push/CI is authorized): commit (stage files by name, standard
   trailer), push to master, dispatch `ruffle-tests.yml` in **both** modes
   (`no-graphics` and `graphics` — this change touches shared build config;
   the old dual-mode policy is still in force for this commit), `gh run watch`
   both, merge the `ruffle-test-results` branch, and report regressions by
   name. Expected result: **zero** pass/fail changes in either mode. Any
   regression means a gate was mis-reduced — fix or revert before finishing.

Known pre-existing failures, not yours: `place_and_remove_object_insane_test`
fails in graphics mode only, and `case-v6` can flake in graphics CI.
