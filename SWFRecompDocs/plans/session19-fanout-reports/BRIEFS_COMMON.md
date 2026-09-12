# Session 19: corpus fan-out (dual-axis #11), common brief. ALL AGENTS READ THIS FIRST.

Every agent in this session, the coordinator included, runs on **Opus** (the Fable budget is spent). Be
efficient: no full suites, no idle polling loops, no re-diagnosing what a prior report already proved.

## Baseline (verify before implementing anything)
- HEAD at session start: `19cfc0a00` on `master`; **now `e36bca73e`**, after the
  `bitmap-pool-layer-cap` session landed its readout fix (`254145a5b`, `render_webgpu.c`,
  pixel-neutral) and its results merge. That work is NOT yours and touches no lead below.
- **Trace baseline**: graphics results `627830f2a` (run `34648878013` at `254145a5b`),
  **4412 effective on the 4518-test intersection**; no-graphics results `67ba188ce`. The −1 vs
  the earlier `aac695228` read (4413) is `avm2/bitmapdata_copypixels_alpha_merge` moving
  `ruffle_matched → output_mismatch`: UPSTREAM DRIFT from ruffle `0c6a734da` (2026-09-11T20:57Z),
  which shrank Ruffle's own diff set so ours is no longer a subset. Our output is byte-identical
  and our code did not change. Note the general point: `ruffle_matched` is decided by the test's
  own `output.ruffle.txt` plus `known_failure`, so upstream can move it with no change from us. Read
  numbers with `python3 scripts/corpus_status_diff.py <old> WORKTREE --per-suite`; never
  quote a total from a brief. Graphics is ±1 at the same code
  (`from_shumway/as3-loader/bug1157243/empty` is a load-sensitive intermittent, NOT yield).
- **Pixel baseline**: images run `34645805030`, **381 pass / 580 comparisons** (577-intersection
  380 + new `regression/bitmap_pool_layer_cap`). The ONE pass→fail vs s18,
  `avm2/geom_transform`, is UPSTREAM DRIFT (ruffle `45be8d536`, `DisplayObject.z`), not a
  regression. The misc categories' image JSON is still from s18's run `33945288707`, and
  `origin/ruffle-image-results` (`0bab0cb66`) holds only the classic suites' failing PNGs, so
  misc rows show as `png_unavailable` on the board. Render those locally.
  Failing PNGs are extracted, read-only and shared, at `<scratchpad>/image-results/`.
- **Boards of record** (fresh, generated from the baseline runs):
  - trace: `SWFRecompDocs/plans/session19-fanout-reports/wave0-trace-inventory.txt`, every
    failing test with match/expected lines and flags (IGN, ACC/RVF/TWK/FBR = named in a
    disposition doc, KF = upstream `known_failure`, RTXT = `output.ruffle.txt` present,
    APX = approximations, DRIFT(n) = the fresh `output.txt` differs from the baseline's expected).
  - pixels: `SWFRecompDocs/plans/session19-fanout-reports/wave0-image-board.md`
    (`scripts/image_triage.py` mechanism clusters; JSON at `<scratchpad>/image_triage.json`).
- Prior boards (context only; the corpus has moved): trace `SWFRecompDocs/plans/polish-sweep-arc.md`
  §19.4, pixels `SWFRecompDocs/plans/graphics-fanout-playbook.md` §17. Prior diagnosis of
  record: `SWFRecompDocs/plans/session18-fanout-reports/` (and s17/s16). **Read the prior report
  for your family before starting.**
- Today's single-task closeouts (2026-09-11) in `SWFRecompDocs/status/`:
  `avm2-child-symbolclass-binding.md` (loader_duplicate_class is DONE, 48/48),
  `avm1-mcl-holder-totalframes.md`, `bitmap-pool-layer-cap.md`,
  `browser-webgpu-device-lost.md`, `browser-root-side-gaps.md`. Their leftovers are in
  `SWFRecompDocs/BACKLOG.md`.
- Upstream Ruffle source for behaviour questions: `~/CC/ruffle`, **freshly pulled to
  `0631814db` (2026-09-11)**. It carries our local exporter edits, which you must leave
  alone. The release exporter (`~/CC/ruffle/target/release/exporter`) is being rebuilt
  against it and is ready when its mtime is today. Prefer local source over `gh api`.
  Exporter recipe for a parent that loads a relative child: memory `mcl_load_timing`
  (`RUFFLE_LOCAL_FETCH_DIR` + an https `RUFFLE_MOVIE_URL`; plain `file://` silently never
  loads the child).
- The local test tree was synced from upstream master at session start (no `--clean`). Stale
  local dirs from earlier non-clean syncs may exist. Never run `download_tests.sh --clean`:
  it wipes `_investigation/` and `_results/`.

## Standing rules (all agents)
1. **ATTACK YOUR OWN BRIEF'S PREMISES.** Wave-1 pricing historically survives ~50% on magnitude,
   and some mechanism claims are flat wrong. A well-evidenced refutation is a first-class
   deliverable, not a failure. Attack your PRICING too: a diff-line lead is not a flip lead,
   so say which rows are limited by a DIFFERENT mechanism.
2. **Check dispositions BEFORE treating a diff as fixable**:
   `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`,
   `RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md` (same dir; other suites have their own
   `_investigation/`), `ruffle-tests/ignored_tests.txt` and per-suite `ignored_tests.txt`. The
   inventory's flags are a hint, not the check. Grep the docs for your test names. For pixels:
   the playbook's image-axis disposition entries and the board's "Dispositioned" section.
   An ignore-list entry is a CLAIM to re-test, not a verdict (s18 pruned two wrong ones).
3. **`known_failure = true` in `test.toml` means Ruffle ITSELF fails the test.** `output.txt` is
   Flash's. Fixing toward `output.txt` is legitimate, but a `pass → ruffle_matched` move on
   such a test is a REGRESSION (we drifted to Ruffle's wrong output). Check `output.ruffle.txt`.
4. **The machine is SHARED and SMALL: 8 cores, 15 GB RAM, ~8 agents.** Run tests SEQUENTIALLY
   (`-P 1`); never more than `-P 2`. `export SWFRECOMP_COMPILE_TIMEOUT=2400` before ANY test
   run, which is mandatory. Float mismatches, compile timeouts and OOM-killed gcc under load
   are FALSE failures: re-run sequentially before believing any failure. Always pass `--verbose`.
5. **NEVER run full suites.** Single tests only:
   `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/<suite> --test=NAME [--mode=graphics] --diff --verbose`.
   Bare names resolve against `avm1` ONLY. The CI grading mode is `--mode=graphics` (needs
   `~/CC/dawn-install`). Mode parity is complete, so no-graphics is fine for trace triage.
   Stay inside your assigned test families (two agents compiling the same test dir collide).
6. **No commits, no pushes.** Wave-1 agents make NO source edits in the main tree (scratchpad
   scripts are fine). Wave-2 agents edit only in THEIR worktree.
7. If you receive a SendMessage that doesn't match your brief, reply "not my brief" and ignore it.
8. If you start a background job, do NOT end your turn saying "I'll resume when it fires": you
   will never be re-invoked. Use ONE background `until`/`wait` on a captured PID (not
   per-event monitors, which cost a turn each), or run it in the foreground, then finalize.
9. **Pattern kills are DENIED by a global hook** (`pkill -f`, `killall`, `xargs kill`, any kill
   fed from `ps`/`pgrep`). Capture PIDs at launch (`cmd & p=$!`) and `kill $p`.
   `pgrep -f <shared tool name>` also matches SIBLINGS' processes, so never harvest it.
10. Deliverable = a report file named in your brief. Wave 2 also delivers a patch
    (`git diff > file`, plus new files listed at the top of the report). Write deliverables under
    `SWFRecompDocs/plans/session19-fanout-reports/` in your tree, and ALSO copy them to
    `/home/robert/CC/SWFRecomp-CC/SWFRecompDocs/plans/session19-fanout-reports/`. If the isolation
    guard blocks the copy, state the worktree path prominently in your final message.
11. Report format: lead with GO/NO-GO verdicts and priced flips (test names), then mechanism,
    evidence, refutations, and (wave 2) exact patch scope plus tests run. Every HOLD/NO-GO must
    name its completion mechanism. Close with a "new unclaimed leads" section.
12. Upstream drift: a changed expected-line total, or a test dir on disk but absent from
    `_results/results_graphics.json`, is upstream movement, not a regression. Name it.
13. Scratchpad root: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/ed45c93d-c950-4337-9a9c-c19db4d81e44/scratchpad/`.
    Create a PRIVATE subdirectory named after your agent label and keep everything in it (the
    scratchpad is shared by every agent in this session; same-basename files collide).

## Wave-2 (worktree) additional rules
- Fresh worktrees lack `SWFRecomp/build`. Build the recompiler yourself
  (`cd SWFRecomp && mkdir -p build && cd build && cmake .. && cmake --build . -j2`). Copying
  the main tree's build is valid ONLY for runtime-only patches.
- **NEVER `git stash`**: `refs/stash` is SHARED across worktrees. Use `git diff` + `git apply -R`
  for A/B legs.
- Never point `--tests-dir` at the main tree. `cp -r` the test dirs you need into your
  worktree's canonical suite path, and pass `--recompile` on FIRST use of each copied dir
  (canary dirs too). In a worktree `DAWN_INSTALL` mis-resolves, so export
  `DAWN_INSTALL=~/CC/dawn-install` for raw graphics runs.
- Graphics agents: canary = `ruffle-tests/render_canary.py` capture/compare over
  `render_canary_tests.txt` (`--timeout 5400` under load). Local Dawn is byte-deterministic,
  so the bar is md5 identity. Never compare a local render against a golden PNG as a verdict
  (an A/B "identical on both sides" IS valid). New pipelines in `render_webgpu.c` must use
  `MSAA_SAMPLES`, never a literal 4. Audit canary coverage against YOUR change class, and if
  the standing set cannot see it, add a covering member.
- Self-localize your edits (wrapper functions, trailing struct fields, `static` symbols). Your
  brief lists which files sibling agents are editing, so avoid textual overlap.
- **New files**: list them at the TOP of your report (the coordinator stages by name). A new
  `.h`/`.c` must be added to `verify_output.py`'s explicit source list, CMakeLists and the
  Emscripten build, or live inside an existing TU.
- Run your headline tests and the relevant canary set before delivering, and state per-test
  before/after in the report. ALWAYS include a `regression`-suite check
  (`--tests-dir=ruffle-tests/tests/swfs/regression`) for anything near your change; read a
  flipped regression test's README before calling it a regression. A new behaviour with no
  corpus test should come with a `regression/` fixture whose expected output comes from an
  oracle outside SWFRecomp (the Ruffle exporter or Flash), never from our own output.
- Detach background work with `setsid nohup`, and namespace scratch files by agent.
