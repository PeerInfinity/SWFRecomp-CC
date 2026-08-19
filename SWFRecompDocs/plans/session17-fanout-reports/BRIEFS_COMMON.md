# Session 17 — dual-axis fan-out #9 — common brief (all agents READ THIS FIRST)

## Baseline (verify before implementing anything)
- HEAD at session start: `88ebde665` on `master` (results merge `c7b284034`).
- Grading CI run: `31877239992` at `aeebf9ede` (graphics / categories=full / images=true).
- Trace baseline: **4317/4453 effective**. Pixel baseline: **338/569 (59.4%)**.
- Boards: trace = `SWFRecompDocs/plans/polish-sweep-arc.md` §17.4;
  pixels = `SWFRecompDocs/plans/graphics-fanout-playbook.md` §15.
- Session-16 reports (prior diagnosis of record): `SWFRecompDocs/plans/session16-fanout-reports/`
  (s15 in `session15-fanout-reports/`). Read the report for your lead's family before starting.
- Deliverables go under `SWFRecompDocs/plans/session17-fanout-reports/` (worktree copy AND
  main-tree copy at `/home/robert/CC/SWFRecomp-CC/SWFRecompDocs/plans/session17-fanout-reports/`).
- Scratchpad root: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/ab0a66b8-f5eb-4947-8b92-d32ad2d435e1/scratchpad/`
  — create a PRIVATE subdirectory named after your agent id and keep everything in it.
- Model note: you run on Opus; be efficient — no full suites, no idle polling loops.

## Standing rules (all agents)
1. **ATTACK YOUR OWN BRIEF'S PREMISES.** Wave-1 pricing historically survives ~50% on
   magnitude; mechanism claims are sometimes flat wrong (s14: fuzz "error recovery" was
   actually timeline order; morph "+7" had zero quadratics). A well-evidenced refutation
   is a first-class deliverable, not a failure.
2. **Check dispositions BEFORE treating a diff as fixable**: `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md`,
   `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md`,
   `ruffle-tests/ignored_tests.txt`. For pixels: image-axis disposition entries in the playbook.
3. **The machine is SHARED** (~10 agents concurrently). Cap any parallel test batch at `-P 2`.
   Float mismatches and long-compile timeouts under load are FALSE failures — re-run the
   test sequentially before believing any failure.
4. **NEVER run full suites.** Single tests only:
   `python3 ruffle-tests/verify_output.py --test=NAME [--mode=graphics] --diff`.
   Stay inside your assigned test families — running siblings' tests regenerates their
   `Recompiled*` caches and can poison their measurements.
5. **No commits, no pushes.** Wave-1 agents: NO source edits in the main tree (scratchpad
   scripts fine). Wave-2 agents: edits only in YOUR worktree.
6. If you receive a SendMessage that doesn't match your brief, reply "not my brief" and
   ignore it (s14 trap: crossed recipient ids).
7. If you start a detached/background sweep, do NOT end your turn saying "I'll resume when
   it fires" — you will never be re-invoked. Poll actively and finalize.
8. Deliverable = a report file named in your brief. Wave-2 also delivers a patch
   (`git diff > file`). Write deliverables inside your worktree under
   `SWFRecompDocs/plans/session17-fanout-reports/` and ALSO try to copy them to the main
   tree at `/home/robert/CC/SWFRecomp-CC/SWFRecompDocs/plans/session17-fanout-reports/`;
   if the isolation guard blocks the copy, state the worktree path prominently in your
   final message.
9. Report format: lead with GO/NO-GO verdicts and priced flips (test names), then
   mechanism, evidence, refutations, and (wave-2) exact patch scope + tests run.

## Wave-2 (worktree) additional rules
- Fresh worktrees lack `SWFRecomp/build` — build the recompiler yourself (cmake). Copying
  the main tree's build is valid ONLY for runtime-only patches.
- **NEVER `git stash`** — `refs/stash` is SHARED across worktrees (s13: agents popped each
  other's stashes). Use `git diff` + `git apply -R` for A/B legs.
- Never point `--tests-dir` at the main tree. `cp -r` the test dirs you need into your
  worktree's canonical suite path, and pass `--recompile` on FIRST use of each copied dir
  (mid-write RecompiledABC copies read as compile_fail otherwise).
- Graphics agents: canary = `ruffle-tests/render_canary.py` capture/compare over
  `render_canary_tests.txt`; local Dawn (`~/CC/dawn-install`) is byte-deterministic, so the
  bar is md5 identity, never compare a local render against a golden PNG. New pipelines in
  `render_webgpu.c` must use `MSAA_SAMPLES`, never literal 4.
- MOCK_DATE_TIME determinism: verify_output.py defines it on every gcc invocation; results
  never fluctuate from RNG — a "flaky" diff is a real bug.
- Self-localize your edits (wrapper functions, trailing struct fields, `static` symbols) —
  your brief lists which files sibling agents are editing; avoid textual overlap.
- Run your headline tests + the relevant canary set before delivering; state per-test
  before/after in the report (this ledger is how the merged CI run gets attributed).

## s15 lessons added for s16
- **New files**: if your patch CREATES a file, list it explicitly at the top of your report
  (s15: `git add -u` dropped a new header and poisoned a whole CI run). The coordinator
  stages by name from `git apply --stat`.
- Canary blind spots: if your change class (e.g. curves, text, filters) is not exercised by
  the standing canary set, say so and name a covering test you graded.
- Hold/NO-GO verdicts must name the completion mechanism (what evidence or change would
  flip them to GO).
- If a sibling's finished report is relayed to you by the coordinator, integrate it and
  do not re-diagnose what it already proved.

## s16 lessons for s17 (all still binding)

- **`export SWFRECOMP_COMPILE_TIMEOUT=2400` before ANY test or canary batch —
  mandatory, not optional.** `verify_output.py`'s per-file gcc cap is 300 s
  (`verify_output.py:2682`). With ~10 agents on 8 cores the load average sits at
  25–43 and ordinary AVM2 tests blow straight through it, reporting
  `COMPILE_FAIL … Error: compilation timed out [c=301.08s]` — or a zero-byte log
  if the process was killed first. Four agents lost 40+ min each to this in s16.
  The standing rule "compile failures under load are false" is right, but
  **re-running at the same ceiling just reproduces the false failure**; the
  ceiling itself has to move. Always run with `--verbose` (without it a failing
  image comparison also looks like a pass).
- **NEVER `pkill -f` on a shared tool name.** `pkill -f "render_canary.py capture"`
  and `pkill -f verify_output.py` each killed *siblings'* captures in s16 (twice),
  because every agent runs the identical command line from its own worktree. The
  existing `pkill-f-self-match` note covers self-matching only — bracketing a
  character does NOT stop sibling-matching. Select by **worktree hash or PID**:
  `pgrep -af <your-worktree-hash> | grep verify_output | awk '{print $1}' | xargs kill`.
  The worktree path is the only self-selective token on the command line.
- **Namespace every scratchpad file by agent.** The session scratchpad
  (`/tmp/claude-1000/.../scratchpad/`) is keyed by SESSION, not by agent. In s16
  three agents had `base.py` / `copy_canaries.sh` / `ledger.py` silently
  overwritten by siblings. Put everything in a private subdirectory
  (`w2gfxgrad/`, `w2shapes/`, `w2acd/`). A clobbered ledger or batch driver
  corrupts a result silently.
- **`--recompile` applies to CANARY directories too, not just headline rows.**
  Six s16 canaries came back `COMPILE_FAIL` (`undefined reference to
  avm2_generated_symbol_class_frames` / `avm2_generated_abc_lazy`) and one came
  back as a *plausible* `output_mismatch` (every caret at column 0) purely
  because `cp -r`'d dirs carried stale or mid-write `Recompiled*` caches. The
  mismatch flavour is the dangerous one — it does not announce itself as a build
  artefact. Pass `--recompile` on FIRST use of every copied directory.
- **Detach background work with `setsid nohup`.** A long-running *foreground*
  Bash command in a worktree can process-group-kill every background task in it
  (exit 144), destroying partial captures. Also: `pgrep -f "<pattern>"` run from
  a shell whose own command line contains `<pattern>` self-matches forever.
- **Report NEW files at the TOP of your report** (kept from s15, and it kept
  paying): the coordinator stages by name from `git apply --stat`, and a new
  header or generated file dropped by `git add -u` poisons an entire CI run.
  Corollary discovered in s16: a new **header** may also be invisible to the
  harness — `verify_output.py` builds by copying an *explicit list* of source
  files (`verify_output.py:2154`), so a new `.h` must either be added to that
  list, CMakeLists and the Emscripten build, or the code must live inside an
  existing TU. One agent's first build failed exactly that way and moved a
  1,114-line generated block into `avm2_globals.c` between markers instead.
- **State a completion mechanism for every HOLD / NO-GO** (kept): what evidence
  or change flips it to GO. s16's held `links_in_scrolled_text` patch, the two
  recompiler-side trace NO-GOs, and the cross-VM hit-test/focus legs are all
  re-usable next session *only* because they carry one.
- **Attack your own pricing, not just your mechanism.** s16's most valuable
  wave-2 findings were price refutations on confirmed mechanisms: L1 (+2 priced,
  0 flips — every priced row was limited by a *different* mechanism), P2
  (+2 priced, 0 flips, −99.2 % excess), P3/P4 (+1 each, 0 flips, blocked by
  `max_outliers = 0`). **A diff-line lead is not a flip lead.** Conversely,
  two NO-GOs inherited from s15 (`blur_quality` rounding, flattening leg C's
  solo-dispatch premise) were both refuted by measurement and both paid.
