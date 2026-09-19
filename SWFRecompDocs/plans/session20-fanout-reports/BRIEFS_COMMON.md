# Session 20: corpus fan-out (dual-axis #12), common brief. ALL AGENTS READ THIS FIRST.

Every agent in this session, the coordinator included, runs on **Opus** (the week's Fable
budget is spent). Be efficient: no full suites, no idle polling loops, no re-diagnosing what a
prior report already proved. The weekly / 5-hour Opus limits are the real risk this session.

## Baseline — read fresh at session start 2026-09-18 (verify before implementing anything)

- HEAD at session start: **`4b05de6ef`** on `master`, clean tree, no worktrees.
- The last thing to land was a **runtime perf lever**, not a corpus change: `2973513c4`
  inlined the AVM2 getproperty IC slot hit. Closeout `SWFRecompDocs/status/seedling-collide-hotloop.md`.
  It is NOT yours and touches no lead below.
- **Trace baseline: 4439 effective / 4527 graded** (98.06 %) — pass 4198, ruffle_matched 241,
  output_mismatch 87, runtime_error 1. **Identical in both modes** (graphics run `35163868554`,
  results `6c1329197`; no-graphics run `35166754380`, results `6bf7f3c30`; both already merged
  into master). Mode parity is complete, so no-graphics is fine for trace triage.
- **Pixel baseline: 393 pass / 587 comparisons** (191 fail, 3 skip), images run `34666689502`
  at `d8da5a18c` (2026-09-12). **That baseline predates six days of landed work**, so the
  first `images=true` grading run this session will show movement that is not ours. Price
  accordingly; never book a pixel move before the grading run attributes it.
- Numbers are read with `python3 scripts/corpus_status_diff.py <old_ref> WORKTREE --per-suite`
  (trace, `results_graphics`) and `python3 scripts/image_status_diff.py <old> <new>` (pixels,
  read its PROVENANCE banner). **Never quote a total from a brief or a closeout.** Graphics is
  ±1 at the same code (`from_shumway/as3-loader/bug1157243/empty` is a load-sensitive
  intermittent, NOT yield).

## Boards of record (fresh, generated from the baseline runs)

- **Trace**: `SWFRecompDocs/plans/session20-fanout-reports/wave0-trace-inventory.txt` — all 88
  failing rows with match/expected/actual line counts and flags (IGN, ACC/RVF/TWK/FBR = named
  in a disposition doc, KF = upstream `known_failure`, RTXT = `output.ruffle.txt` present).
- **Pixels**: `SWFRecompDocs/plans/session20-fanout-reports/wave0-image-board.md`
  (`scripts/image_triage.py` mechanism clusters; row JSON at `<scratchpad>/image_triage.json`;
  failing PNGs extracted read-only at `<scratchpad>/image-results/`).
- Prior boards, context only — the corpus has moved: trace `SWFRecompDocs/plans/polish-sweep-arc.md`
  §20.5, pixels `SWFRecompDocs/plans/graphics-fanout-playbook.md` §18. Prior diagnosis of
  record: `SWFRecompDocs/plans/session19-fanout-reports/` (and s18/s17). **Read the prior
  report for your family before starting.**
- Upstream Ruffle source for behaviour questions: `~/CC/ruffle`, **freshly pulled to
  `f2aaf0703` (2026-09-18)** from `0631814db`. It carries our local exporter/wgpu edits, all
  12 re-applied cleanly — **leave them alone**. Exporter recipe for a parent that loads a
  relative child: memory `mcl_load_timing` (`RUFFLE_LOCAL_FETCH_DIR` + an https
  `RUFFLE_MOVIE_URL`; a plain `file://` run silently never loads the child). Prefer reading
  local source over `gh api`.
- The local `avm1` test tree was re-synced from upstream master at session start (no
  `--clean`, no drift in `avm1`). The other suites are downloaded fresh by CI each run, so
  drift shows up there. Never run `download_tests.sh --clean`: it wipes `_investigation/`
  and `_results/`, which are this project's own work.

## Standing rules (all agents)

1. **ATTACK YOUR OWN BRIEF'S PREMISES.** Wave-1 refutation yield has been the single
   highest-value habit for six sessions running; s19's refutations killed two expensive arcs
   before they started. A well-evidenced refutation is a first-class deliverable, not a
   failure. Attack your PRICING too: a diff-line lead is not a flip lead — say which rows are
   limited by a DIFFERENT mechanism.
2. **Check dispositions BEFORE treating a diff as fixable**:
   `ruffle-tests/tests/swfs/avm1/_investigation/{ACCEPTED_DIFFS,RUFFLE_VS_FLASH_DIFFERENCES,RUFFLE_COMPAT_TWEAKS,FLASH_BUGS_REPLICATED}.md`
   (other suites have their own `_investigation/`), `ruffle-tests/ignored_tests.txt` and
   per-suite `ignored_tests.txt`. The inventory's flags are a hint, not the check — grep the
   docs for your test names. For pixels: the playbook's image-axis disposition entries and the
   board's "Dispositioned" section. **An ignore-list entry is a CLAIM to re-test, not a
   verdict** — s19 turned two "blocked" verdicts of record into flips because both were wrong.
3. **`known_failure = true` in `test.toml` means Ruffle ITSELF fails the test.** `output.txt`
   is Flash's. Fixing toward `output.txt` is legitimate, but a `pass → ruffle_matched` move on
   such a test is a **REGRESSION** (we drifted onto Ruffle's wrong output). Check
   `output.ruffle.txt`.
4. **`runtime_error` is the cheapest triage axis** — a crash names its own mechanism. If your
   family has one, start there.
5. **The machine is SHARED and SMALL: 8 cores, 15 GB RAM, ~8 agents.** Run tests SEQUENTIALLY
   (`-P 1`); never more than `-P 2`. **`export SWFRECOMP_COMPILE_TIMEOUT=2400` before ANY test
   run — mandatory.** Float mismatches, compile timeouts and OOM-killed gcc under load are
   FALSE failures: re-run sequentially on an idle box before believing any failure. Always
   pass `--verbose`.
6. **NEVER run full suites.** Single tests only:
   `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/<suite> --test=NAME [--mode=graphics] --diff --verbose`.
   Bare names resolve against `avm1` ONLY. The CI grading mode is `--mode=graphics` (needs
   `~/CC/dawn-install`). Stay inside your assigned test families — two agents compiling the
   same test dir collide.
7. **No commits, no pushes.** Wave-1 agents make NO source edits in the main tree (scratchpad
   scripts are fine). Wave-2 agents edit only in THEIR worktree.
8. If you receive a SendMessage that doesn't match your brief, reply **"not my brief"** and
   ignore it.
9. If you start a background job, do NOT end your turn saying "I'll resume when it fires": you
   will never be re-invoked. Use ONE background `until`/`wait` on a captured PID (not
   per-event monitors, which cost a turn each), or run it in the foreground, then finalize.
10. **Pattern kills are DENIED by a global hook** (`pkill -f`, `killall`, `xargs kill`, any
    kill fed from `ps`/`pgrep`), and they cross-kill siblings. Capture PIDs at launch
    (`cmd & p=$!`) and `kill $p`. `pgrep -f <shared tool name>` also matches SIBLINGS'
    processes, so never harvest it.
11. Deliverable = a report file named in your brief. Wave 2 also delivers a patch
    (`git diff > file`, **plus every new file listed at the TOP of the report** — the
    coordinator stages by name and `git add -u` silently drops new files). Write deliverables
    under `SWFRecompDocs/plans/session20-fanout-reports/` in your tree AND copy them to
    `/home/robert/CC/SWFRecomp-CC/SWFRecompDocs/plans/session20-fanout-reports/`. If the
    isolation guard blocks the copy, state the worktree path prominently in your final message.
12. Report format: lead with **GO/NO-GO verdicts and priced flips (test names)**, then
    mechanism, evidence, refutations, and (wave 2) exact patch scope plus tests run. **Every
    HOLD/NO-GO must name its completion mechanism.** Close with a "new unclaimed leads" section.
13. Upstream drift: a changed expected-line total, or a test dir on disk but absent from
    `_results/results_graphics.json`, is upstream movement, not a regression. Name it — never
    book drift as yield.
14. **A misc pass → fail whose `max_diff` is unchanged while only `outliers` moves is upstream
    `test.toml` tolerance drift until proven otherwise.** A real render regression moves
    `max_diff`.
15. Scratchpad root:
    `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/2a334c23-46d3-40fc-a8f1-a77489de0fb1/scratchpad/`.
    Create a **PRIVATE subdirectory named after your agent label** and keep everything in it —
    the scratchpad is shared by every agent this session and same-basename files collide.

## Wave-2 (worktree) additional rules

- Fresh worktrees lack `SWFRecomp/build`. Build the recompiler yourself
  (`cd SWFRecomp && mkdir -p build && cd build && cmake .. && cmake --build . -j2`). Copying
  the main tree's build is valid ONLY for runtime-only patches.
- **NEVER `git stash`**: `refs/stash` is SHARED across worktrees and two agents have popped
  each other's stashes. Use `git diff` + `git apply -R` for A/B legs.
- **Never point `--tests-dir` at the main tree.** `verify_output.py` rmtrees and regenerates
  `Recompiled*` caches *inside the shared test directory*, so agents cross-poison each other
  silently. `cp -r` the test dirs you need into your worktree's **canonical** suite path
  (`$WT/ruffle-tests/tests/swfs/<suite>/<test>`; an out-of-corpus path mislabels `suite_tag()`),
  and pass `--recompile` on FIRST use of each copied dir (canary dirs too). In a worktree
  `DAWN_INSTALL` mis-resolves — export `DAWN_INSTALL=~/CC/dawn-install` for raw graphics runs.
- Graphics agents: canary = `ruffle-tests/render_canary.py` capture/compare over
  `render_canary_tests.txt` (`--timeout 5400` under load). Local Dawn is byte-deterministic, so
  the bar is **md5 identity**. **Never grade a local render against a golden PNG** (an A/B
  "identical on both sides" IS valid). New pipelines in `render_webgpu.c` must use
  `MSAA_SAMPLES`, never a literal 4. Audit canary coverage against YOUR change class; if the
  standing set cannot see your change, add a covering member (`render_canary_tests.txt`
  conflicts every session — everyone appends at EOF; that is expected and resolved with
  `--3way`).
- Self-localize your edits (wrapper functions, trailing struct fields, `static` symbols). Your
  brief lists which files sibling agents are editing — avoid textual overlap.
- **New files**: a new `.h`/`.c` must be added to `verify_output.py`'s explicit source list,
  CMakeLists **and** the Emscripten build, or live inside an existing TU.
- Run your headline tests and the relevant canary set before delivering, and state per-test
  before/after in the report. **ALWAYS include a `regression`-suite check**
  (`--tests-dir=ruffle-tests/tests/swfs/regression`) for anything near your change; read a
  flipped regression test's README before calling it a regression. A new behaviour with no
  corpus test should come with a `regression/` fixture whose expected output comes from an
  oracle **outside SWFRecomp** (the Ruffle exporter or Flash), never from our own output.
- Detach background work with `setsid nohup`, and namespace scratch files by agent.
