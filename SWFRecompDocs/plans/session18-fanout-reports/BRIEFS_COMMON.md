# Session 18 — corpus fan-out (dual-axis #10) — common brief (all agents READ THIS FIRST)

## Baseline (verify before implementing anything)
- HEAD at session start: `8f68a5fea` on `master`.
- Trace baseline: results commits `f00041501` (graphics, run `33902348100`) and `53141b979`
  (no-graphics, run `33906033322`), both already merged into master. Read numbers with
  `python3 scripts/corpus_status_diff.py <old> WORKTREE --per-suite` — never quote a total
  from a brief. Graphics effective is **4373 ±1** over 4498 graded (the ±1 is
  `from_shumway/as3-loader/bug1157243/empty`, a load-sensitive intermittent — NOT yield).
- Pixel baseline: **364/572 (63.6%)** at `659153865`, images run `33857494837`
  (`SWFRecompDocs/plans/graphics-image-baseline.md`). Failing PNGs: extract of
  `origin/ruffle-image-results` at `<scratchpad>/image-results/` (read-only, shared).
- Boards of record for THIS session (fresh, generated from the baseline runs):
  - trace: `SWFRecompDocs/plans/session18-fanout-reports/wave0-trace-inventory.txt`
    (every failing test with expected/matching lines and disposition flags:
    IGN = ignored_tests.txt, ACCEPTED/RUFFLE_V/FLASH_BU = disposition docs, KF =
    upstream `known_failure = true`, approx = test.toml approximations).
  - pixels: `SWFRecompDocs/plans/session18-fanout-reports/wave0-image-board.md`
    (`scripts/image_triage.py` mechanism clusters; JSON at `<scratchpad>/image_triage.json`).
- Prior boards (context, the corpus has moved since): trace
  `SWFRecompDocs/plans/polish-sweep-arc.md` §18.4; pixels
  `SWFRecompDocs/plans/graphics-fanout-playbook.md` §16. Prior diagnosis of record:
  `SWFRecompDocs/plans/session17-fanout-reports/` (and s16/s15). Read the report for your
  lead's family before starting — do not re-diagnose what it already proved.
- Since s17 the Multi-SWF arc (11 slices, 2026-09-03/04) landed: loaded child movies now
  re-base char ids in the recompiler, advance, loop and render. Closeouts in
  `SWFRecompDocs/status/`. `BACKLOG` §Multi-SWF lists its leftovers.
- Deliverables go under `SWFRecompDocs/plans/session18-fanout-reports/` (worktree copy AND
  main-tree copy at `/home/robert/CC/SWFRecomp-CC/SWFRecompDocs/plans/session18-fanout-reports/`).
- Scratchpad root: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/`
  — create a PRIVATE subdirectory named after your agent label and keep everything in it.
- Upstream Ruffle source for behaviour questions: `~/CC/ruffle` (freshly pulled to
  `1636c7806`, 2026-09-04; carries our local exporter edits — leave those alone). Prefer it
  over `gh api`/GitHub.
- The local test tree was synced from upstream master at session start (no `--clean`).
  Never run `download_tests.sh --clean` — it wipes `_investigation/` and `_results/`.
- Model note: you run on Opus; be efficient — no full suites, no idle polling loops.

## Standing rules (all agents)
1. **ATTACK YOUR OWN BRIEF'S PREMISES.** Wave-1 pricing historically survives ~50% on
   magnitude; mechanism claims are sometimes flat wrong. A well-evidenced refutation is a
   first-class deliverable, not a failure. Attack your PRICING too: a diff-line lead is not
   a flip lead — say which rows are limited by a DIFFERENT mechanism.
2. **Check dispositions BEFORE treating a diff as fixable**:
   `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md`,
   `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md`
   (same dir), `ruffle-tests/ignored_tests.txt` and per-suite `ignored_tests.txt`. The
   inventory's flags are a hint, not the check — grep the docs for your test names.
   For pixels: image-axis disposition entries in the playbook and the board's
   "DISPOSITIONED" section.
3. **`known_failure = true` in `test.toml` means Ruffle ITSELF fails the test**; `output.txt`
   is Flash's. Fixing toward `output.txt` is legitimate, but a `pass -> ruffle_matched`
   move on such a test is a REGRESSION (we drifted to Ruffle's wrong output). Check
   `output.ruffle.txt` where present.
4. **The machine is SHARED** (~8 agents concurrently). Cap any parallel test batch at `-P 2`.
   `export SWFRECOMP_COMPILE_TIMEOUT=2400` before ANY test batch — mandatory. Float
   mismatches and compile timeouts under load are FALSE failures — re-run sequentially
   before believing any failure. Always pass `--verbose`.
5. **NEVER run full suites.** Single tests only:
   `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/<suite> --test=NAME [--mode=graphics] --diff --verbose`.
   Bare names resolve against `avm1` ONLY. The CI grading mode is `--mode=graphics`
   (needs `~/CC/dawn-install`); no-graphics parity is complete except
   `from_gnash/misc-swfc.all/gotoFrameFromInterval2`, so no-graphics is fine for trace
   triage. Stay inside your assigned test families.
6. **No commits, no pushes.** Wave-1 agents: NO source edits in the main tree (scratchpad
   scripts fine). Wave-2 agents: edits only in YOUR worktree.
7. If you receive a SendMessage that doesn't match your brief, reply "not my brief" and
   ignore it.
8. If you start a detached/background sweep, do NOT end your turn saying "I'll resume when
   it fires" — you will never be re-invoked. Poll actively (captured PID + `kill -0`) and
   finalize.
9. **Pattern kills are DENIED by a global hook** (`pkill -f`, `killall`, `xargs kill`,
   any kill fed from `ps`/`pgrep`). Capture PIDs at launch (`cmd & p=$!`) and `kill $p`.
   `pgrep -f <shared tool name>` also matches SIBLINGS' processes — never harvest it.
10. Deliverable = a report file named in your brief. Wave-2 also delivers a patch
    (`git diff > file`). Write deliverables inside your worktree under
    `SWFRecompDocs/plans/session18-fanout-reports/` and ALSO copy them to the main tree;
    if the isolation guard blocks the copy, state the worktree path prominently in your
    final message.
11. Report format: lead with GO/NO-GO verdicts and priced flips (test names), then
    mechanism, evidence, refutations, and (wave-2) exact patch scope + tests run. Every
    HOLD/NO-GO must name its completion mechanism. Close with a "new unclaimed leads"
    section.
12. Upstream drift: a changed expected-line total or a test dir that is on disk but absent
    from `_results/results_graphics.json` is upstream movement, not a regression. Name it.

## Wave-2 (worktree) additional rules
- Fresh worktrees lack `SWFRecomp/build` — build the recompiler yourself
  (`cd SWFRecomp && mkdir -p build && cd build && cmake .. && cmake --build . -j4`). Copying the
  main tree's build is valid ONLY for runtime-only patches.
- **NEVER `git stash`** — `refs/stash` is SHARED across worktrees. Use `git diff` +
  `git apply -R` for A/B legs.
- Never point `--tests-dir` at the main tree. `cp -r` the test dirs you need into your
  worktree's canonical suite path, and pass `--recompile` on FIRST use of each copied dir
  (canary dirs too).
- Graphics agents: canary = `ruffle-tests/render_canary.py` capture/compare over
  `render_canary_tests.txt` (`--timeout 5400` under load); local Dawn is byte-deterministic,
  so the bar is md5 identity; never compare a local render against a golden PNG as a
  verdict (an A/B "identical on both sides" IS valid). New pipelines in `render_webgpu.c`
  must use `MSAA_SAMPLES`, never literal 4.
- Self-localize your edits (wrapper functions, trailing struct fields, `static` symbols) —
  your brief lists which files sibling agents are editing; avoid textual overlap.
- **New files**: list them at the TOP of your report (the coordinator stages by name).
  A new `.h` must be added to `verify_output.py`'s explicit source list, CMakeLists and
  the Emscripten build, or live inside an existing TU.
- Run your headline tests + the relevant canary set before delivering; state per-test
  before/after in the report. ALWAYS include a `regression`-suite check
  (`--tests-dir=ruffle-tests/tests/swfs/regression`) for anything near your change; read a
  flipped regression test's README before calling it a regression.
- Detach background work with `setsid nohup`; namespace scratch files by agent.
