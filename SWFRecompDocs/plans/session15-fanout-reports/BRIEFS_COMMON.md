# Session 15 — dual-axis fan-out #7 — common brief (all agents READ THIS FIRST)

## Baseline (verify before implementing anything)
- HEAD at session start: `42a324cef` on `master`.
- Grading CI run: `31647430265` at `bf585e448` (graphics / categories=full / images=true).
- Trace baseline: **4269/4443 effective**. Pixel baseline: **310/569 (54.5%)**.
- Boards: trace = `SWFRecompDocs/plans/polish-sweep-arc.md` §15.3;
  pixels = `SWFRecompDocs/plans/graphics-fanout-playbook.md` §13.
- Session-14 reports (prior diagnosis of record): `SWFRecompDocs/plans/session14-fanout-reports/`.

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
   `SWFRecompDocs/plans/session15-fanout-reports/` and ALSO try to copy them to the main
   tree at `/home/robert/CC/SWFRecomp-CC/SWFRecompDocs/plans/session15-fanout-reports/`;
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
