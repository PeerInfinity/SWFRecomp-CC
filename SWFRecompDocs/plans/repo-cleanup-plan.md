# Repo cleanup plan: make SWFRecomp-CC presentable to the Ruffle team

**Agreed:** 2026-11-28, discussion session with Robert (launched by `s30-coordinator`). Base commit `3e60edbaf`.
**Rules for every slice:** forward-only (no history rewrite, no force-push). Commit straight to `master`. Stage
files by name. One slice per session. A slice that moves paths runs only while no fan-out or ladder session is using
the shared tree. Never run full suites locally; CI is needed only for slices that touch CI or the runtime.

## 1. Inventory at agreement time (facts the decisions rest on)

- The repo is **public**: 14.6k tracked files, 323 MB pack. Slicing the history won't shrink the clone (history
  stays), and that's accepted.
- The GitHub root has 32 tracked entries, 14 of them loose generated or dead files:
  - `RUFFLE_*.md` ×6 is rewritten by CI on every run (`scripts/ci/publish_results.sh`,
    `scripts/generate_results_index.py`, `ruffle-tests.yml`);
  - `opcode-index{.md,.json,-plain.md}` and `feature-index{,-plain}.md` were last regenerated 2026-02 by `test.yml`,
    whose last run failed 2026-02-24;
  - `demo-list.md` dates from 2026-02 (`scripts/generate_demo_list.py`);
  - `md-files.json` and `repository-data.json` date from 2025-11 and nothing reads them (`md-files.json` is only
    read by `CC/scripts`);
  - `CC/` holds 2025 prompt-generation scripts;
  - `local_swf_batch/` holds `Snake.swf` and a README.
- `README.md` describes the project and its upstream relationship well. It opens by apologising for broken links and
  has **no quickstart** (build, run one test, headline results).
- `SWFRecompDocs/` has 5,317 tracked files:
  - 4,477 (4 MB) are `plans/session{7..30}-fanout-reports/`;
  - `SWFRecompDocs/README.md` is from 2025 (it links a dead `swfrecomp.github.io` demo and doesn't mention
    `PROJECT_STATE.md`);
  - its root holds 2025 parallel-opcode guides and a `.patch` file;
  - `prompts/` has 211 session briefs; `status/` (114 files) and `deprecated/` (29) are dated logs.
- References into the fan-out reports from outside them:
  - 148 tracked files, of which 113 are provenance docstrings in `regression/*/create_test_swf.py`;
  - the rest are code comments and docs; the only functional one is `ruffle-tests/recompiler_ab_sweep.sh`;
  - 14 memories.
  - The coordinator tooling (`coord-tools/`: `land_branch.sh`, `allrows.py`, `watch_reports.sh`,
    `status_moves*.py`) is **copied into each session's report dir** instead of living at a stable path.
- Dead code inside components: `SWFModernRuntime/test_*.c` and `Makefile.test*` (2025-11),
  `SWFRecomp/tests-wip/` (2025-11).
- Data dumps: `tools/divergence/perf/` holds 19.8 MB of profiler dumps. The vendored SDL3 test assets are third-party
  and stay.
- Branches and worktrees:
  - 293 local branches, **290 already merged into master**;
  - 9 remote branches besides `master` and `ruffle-test-results`;
  - 8 old worktrees beside the repo, plus 1 prunable one in the scratchpad.
- No Flash binaries are tracked. `docs2/` holds only the OSS mp3 demo (the non-OSS games are untracked).

## 2. Decisions (Robert, 2026-11-28)

| # | Decision | Ruling |
|---|---|---|
| D1 | Audience | **Browse the code and run one test.** README: what the project is, headline results against Flash/Ruffle, a code map. `GETTING_STARTED.md`: build the recompiler and runtime and run one Ruffle test, checked on a fresh clone. |
| D2 | Internal history | **Move it to a new public sibling repo, `SWFRecomp-CC-history`** (working name). Old locations get a one-line pointer stub. Citations get rewritten mechanically to links or `SWFRecomp-CC-history:<path>`. |
| D3 | Future fan-out reports | **Written to the history repo.** The main repo gets code plus the durable state docs only (`PROJECT_STATE.md`, `NO_GO_REGISTER.md`, playbooks, arcs). |
| D4 | Agent files (`CLAUDE.md`, `.claude/`) | **Keep them at the root and say so in the README:** the project is developed with Claude Code sessions, and `CLAUDE.md` is the agent manual. |
| D5 | Dead files | **Delete them.** The plan lists each one (§3, S3). The slice re-checks references before each delete. Git history keeps them. |
| D6 | Branches and worktrees | **Prune the merged local branches and the old worktrees** (check each worktree for uncommitted work first). Review the remote branches one at a time with Robert. |
| D7 | Rename `master` → `main` | **No.** Ruffle itself uses `master` (`ruffle-rs/ruffle`, checked 2026-11-28). A rename touches 43 workflows and scripts, `CLAUDE.md`, the pipeline handoff, memories, every worktree and cloud env, and the Pages config, and gives the audience nothing. Recorded in `NO_GO_REGISTER.md` by S1. |
| D8 | Side projects | **Decided in S2** (2026-11-28): per-path rulings D8a–D8l below. Finished-game one-offs, reports and provenance captures go to the history repo; the perf dumps are deleted; everything that tests or drives code still here stays. Executed by S2b. |
| D9 | Order | Structural moves first, so the docs written later point at final paths. The prune is independent. |
| D10 | SWF files in git (S2, 2026-11-28) | **The SWFs already tracked stay in both repos** (no history purge, and the history repo is not deleted and re-created). **No more `git add -f`:** a SWF is tracked only when a `.gitignore` allow rule covers it. Robert wants to review the tracked SWFs in detail first (slice S7). Until S7 rules, `tools/coord/COORDINATOR_BRIEF_TEMPLATE.md:80` ("`git add -f` the `.swf` fixtures") is left unchanged; no fan-out is planned before then. The history repo got a `.gitignore` (`*.swf`, build outputs, Flash binaries; `7879606`). |
| D11 | Sibling repos `seedling-wasm` and `swfrecomp-browser` (Robert, 2026-11-28) | **Both join the cleanup.** Rulings and slices are in §10. In short: rebuild the vanilla Seedling now; swfrecomp-browser release 4 waits for Archipelago-CC's p4h; one docs discussion covers both repos; no history shed; protect p4h's worktrees and branches; leave the old `PeerInfinity/SWFRecomp` and `SWFModernRuntime` forks as they are. |

### D8 side-project rulings (S2, Robert, 2026-11-28)

The inventory was taken at `d81f64081`. Counts are tracked files. "Refs" are other tracked files naming the path. Rule
behind every ruling: **anything that tests or drives code still in this repo stays**; finished-game one-offs, reports
and provenance captures go to the history repo (as S1 did); raw data dumps are deleted (git history keeps them).

| # | Path | Size | Ruling |
|---|---|---|---|
| D8a | `ruffle-tests/_eq_tas/`, `ruffle-tests/_rwk_tas/` (TAS scripts, EQ/RWK bring-ups DONE) | 20 files, 62 KB | **History repo.** No CI or test consumer; 5 refs, 2 memories. |
| D8b | `tools/divergence/game_drive/`: the 15 `minesweeper_*` and 3 `pacman_*` probes (finished games) | 18 files | **History repo.** The harness (`tetris_compare.py`, `n_drive_compare.py`, `n_click_probe.py`, `smoke_demo.py`, `dbg_capture.py`, `death_verify.py`, `dj_smoke.py`, `ready_probe.py`, `tetris_*`, README) **stays**: it is live and the game-debugging guide names it. Re-word the README's file list. |
| D8c | `SWFRecompDocs/games/` (flasharchive build results, game search; 2026-05 snapshot) | 2 files, 26 KB | **History repo.** Re-cite in `guides/wasm-game-debugging-session-guide.md`. |
| D8d | N work: `SWFRecompDocs/plans/n-*.md` (18 ladder reports + the 3 CANCELLED procgen plans `n-level-generator-plan.md`, `n-portals-plan.md`, `n-physics-js-reimplementation-plan.md`), `n-stroke-snap-captures/`, `n-join-disc-captures/`, `n-exec-order-sibling-fixture/`, `n-levels-5plus-hairline-fixture/` | 140 files, 1.35 MB | **History repo, all of it.** The captures are provenance only: the regression fixtures built from them carry their own goldens. Live N state stays in memory `n-play-game` (the pixel ladder is PARKED, not cancelled). Edit `NO_GO_REGISTER.md`'s procgen row ("existing code and docs stay in place" → the docs moved to the history repo; code stays). |
| D8e | `SWFRecompDocs/plans/flash-oracle-captures/` | 12 files, 103 KB | **History repo.** Provenance for regression goldens (cited by a `tag.c` comment and 2 regression `test.toml`/`create_test_swf.py`). New oracle captures belong with the fixture they grade, not here. |
| D8f | `tools/divergence/perf/` raw dumps: 5 `seedling_profile_*.json`, 4 `*.cpuprofile`, `seedling_static_type_scout.csv`, `inst_slot_census_2026-07-15.txt`, 2 `ti_2026-07-20_*.png` | 13 files, 19.5 MB | **Delete** (not moved: they would add 19.5 MB to a second public repo, and they are stale; `NO_GO_REGISTER` already requires a fresh profile of HEAD to reopen anything). Their conclusions live in `SEEDLING_AB_STATUS.md` / `RWK_AB_STATUS.md` and memories. Citations become "deleted in `<sha>`; recover with `git checkout <sha>^ -- <path>`". The rig (`*_win.py`, `*.mjs`, the small A/B CSVs and `results.txt`), the status docs and `WINDOWS_PLAYWRIGHT_FROM_WSL.md` (cited by `CLAUDE.md`) **stay**. |
| D8g | `tools/divergence/ARCHIVE.md` (125 KB session log) | 1 file | **History repo.** `PROGRESS.md` (169 KB) **stays** while sessions still append to it. |
| D8h | `ruffle-tests/tests/swfs/_rando/` (Archipelago `Rando` builtin tests) | 35 files, 70 KB | **Stays.** It tests runtime code that stays (`WITH_AP`); Archipelago-CC consumes it. |
| D8i | `ruffle-tests/tests/swfs/_swfbridge/livetest/` (10 harnesses: DJ, N, RWK, Seedling, SharedObject hook, toy browser) | 113 files, 755 KB | **Stays.** Live; `run_image_tests.py` excludes it by name. |
| D8j | `docs/injector/` + `demos/{ruffle-inject,ruffle-editor,runtime-swf}/` | 57 files, 2.9 MB | **Stays.** A live Pages demo (`docs/index.html` links it); `demos/` is its source. If S4 finds it broken, it becomes an S3-style delete plus link removal. |
| D8k | `docs/examples.staging/` | 5 files, 55 KB | **Delete in S3** (dead since 2026-02, no refs). |
| D8l | `SWFRecomp/wasm_recompiler_demo` | 0 tracked | **Nothing to do.** Only old `PHASE{1,2}_*.md` plans mention it. |

Arc docs for Seedling, EQ, Snailiad, Archipelago and DJ in `plans/` stay (S1 ruling: arcs stay).

### What moves to the history repo (S1)

- **Moves:**
  - `SWFRecompDocs/plans/session*-fanout-reports/` and `session9-graphics-setup-reports/`
  - `SWFRecompDocs/plans/completed/`
  - `SWFRecompDocs/prompts/`
  - `SWFRecompDocs/deprecated/`
  - the dated logs in `SWFRecompDocs/status/` (S1 decides file by file whether one is a log or current reference)
- **Stays:**
  - `PROJECT_STATE.md`, `NO_GO_REGISTER.md`
  - the playbooks and arcs in `plans/` (`polish-sweep-arc.md`, `graphics-fanout-playbook.md`, …)
  - `guides/`, `specs/`, `reference/`, `merge/`, `upstream-comparison/`
- **Waits for S2:** the N capture and fixture dirs under `plans/` (`n-*-captures`, `n-*-fixture`), `flash-oracle-captures`
  and `tools/divergence/perf/`. Each is either a side project or history.

## 3. Slices (one per session; run in order unless noted)

**S1: history repo split.**
- Create the public `SWFRecomp-CC-history` repo and clone it at `~/CC/SWFRecomp-CC-history`.
- Copy the §2 "moves" set into it at the **same relative paths**, so citations stay greppable, and commit it there.
- In the main repo, remove the set and leave a `README.md` stub in each top-level moved dir that links the new location.
- Promote the coordinator tooling to `tools/coord/` (newest copy from `SWFRecomp-CC-history:SWFRecompDocs/plans/session30-fanout-reports/coord-tools/`) and
  repoint `recompiler_ab_sweep.sh`.
- Rewrite the citations in tracked files with a mechanical sed to `SWFRecomp-CC-history:<path>`, and do the same in
  the 14 memories.
- Update the fan-out machinery for D3: the coordinator brief template, `graphics-fanout-playbook.md` /
  `polish-sweep-arc.md` §"reports", `scripts/fanout_cloud_worker.sh`, and memories `session-launch-protocol`,
  `parallel-fanout-wave-pattern`, `cloud-session-launch-cli`.
- Add D7 to `NO_GO_REGISTER.md`.
- **Done:** both repos pushed. `git grep 'fanout-reports'` in the main repo hits only `SWFRecomp-CC-history:` citations
  and the stubs. `tools/coord/land_branch.sh --help` runs. A dry-read of the coordinator brief template points only at
  history-repo paths.
- CI: one `graphics`/`all` run. No functional change is expected; it proves the stubs and moves broke nothing in the
  build.

**S2: side-project inventory and decision (discussion session).**
- Inventory every candidate side project with size, references, liveness and dependencies:
  - game drivers and TAS plans: `ruffle-tests/_eq_tas`, `ruffle-tests/_rwk_tas`, `tools/divergence/game_drive`;
  - the Archipelago randomizer: `ruffle-tests/tests/swfs/_rando`;
  - N game work: captures, fixtures, docs. The procgen arc is CANCELLED, so it is inventoried only, never resumed;
  - the Seedling and perf data and tooling: `tools/divergence/perf`;
  - `_swfbridge`, `docs/injector`, `docs/examples.staging`, `SWFRecomp/wasm_recompiler_demo`, and anything else Robert
    names.
- For each, Robert chooses: stays, its own repo, or the history repo.
- Append the rulings to this plan as §2 D8a… and add an execution slice (S2b) if anything moves.
- **Done:** the rulings and the S2b slice line are committed to this file.

**S2b: side-project extraction (ruled in S2, §2 D8a–D8l).** Same mechanics as S1. Copy the D8a–D8e and D8g paths into
`SWFRecomp-CC-history` at the same relative paths and commit there. `git rm` them here, with one stub per moved
top-level dir (or a single `SWFRecompDocs/plans/n-work.md` stub for the D8d set, as S1 did for the report dirs).
`git rm` the 13 D8f dumps; no copy. Rewrite citations in tracked files and memories (`SWFRecomp-CC-history:<path>`, or
the D8f recovery-sha form), and edit the `NO_GO_REGISTER.md` procgen row. Trim the `game_drive` README. Check the
worktrees for untracked copies before calling it done (memory `fanout-worktree-residue-self-archives`). Run it only
while the tree is quiet. CI isn't needed: no CI, test or Pages path moves (comments only), but run `apply_flash_fixes.py
--check` and one `regression` test whose docstring was rewritten. **Done:** both repos pushed; `git grep` for each
moved path hits only stubs and `SWFRecomp-CC-history:` citations; `git grep` for each D8f filename hits only recovery
citations; `du -sh tools/divergence/perf` is under 1 MB.

`.gitignore` checks (S2, 2026-11-28):
- No root `.gitignore` rule names a moved or deleted path, so none needs editing.
- `SWFRecomp-CC-history` has no `.gitignore`, so copy with `git ls-files`, never `cp -r`. The moved dirs hold 26
  ignored, untracked files: 25 probe-generated `test.swf`/`.pyc` in `n-stroke-snap-captures` and `n-join-disc-captures`,
  and `_rwk_tas/__pycache__`. Like S1's residue, they go to `~/CC/SWFRecomp-CC-local-residue/s2b-moved-untracked/` and
  never into the history repo.
- `n-exec-order-sibling-fixture/test.swf` is tracked despite the global `*.swf` rule (force-added in `4e66127cc`). The
  history repo now ignores `*.swf` (`7879606`), so per D10 S2b adds an allow rule for that path to the history repo's
  `.gitignore` instead of `git add -f`, and the `cmp` check includes it.
- `game_drive` stays, along with its local-only, ignored `Minesweeper.swf`, `Tetris.swf` and `compare_out/`. Those are
  non-OSS game binaries and outputs, and they must never be copied out with the minesweeper probes.

**S3: root declutter and dead files.**
- Move `RUFFLE_*.md` to `ruffle-tests/results/`, changing `publish_results.sh`, `generate_results_index.py` and
  `ruffle-tests.yml`. Check the results-branch merge flow and the memories that name those files.
- Delete, after a fresh `git grep` for each:
  - `md-files.json`, `repository-data.json`, `CC/`, `local_swf_batch/`;
  - `SWFModernRuntime/test_string_id_optimization.c`, `test_string_id_simple.c`, `test_string_variables.c`,
    `test_string_vars.c`, `test_variables_simple.c`, `Makefile.test*`;
  - `SWFRecomp/tests-wip/`;
  - `.github/workflows/test.yml`, plus the opcode and feature index files and their generators
    (`scripts/generate_opcode_markdown.py`, `scripts/test-and-document.py`, `scripts/build_opcode_index.py`) unless
    the grep shows a live consumer. `docs/opcode-index.json` is checked too.
- Decide `demo-list.md` (regenerate into `docs/`, or delete) and `all-tests.yml` / `deploy-pages-build.yml` (no runs
  since 2026-02 and 2026-04).
- Move the 2025 guides at the `SWFRecompDocs/` root (`parallel-opcode-*`, `opcode-instance-prompt-template.md`,
  `probing-trace-log.patch`, …) to the history repo.
- **Done:** the GitHub root lists only real directories plus `README.md`, `LICENSE`, `THIRD_PARTY_NOTICES.md`,
  `CLAUDE.md`, `.claude`, `.github`, `.gitignore` (plus `GETTING_STARTED.md` after S4). A full CI run publishes the
  result tables at the new path, and the results-branch merge is clean.

**S4: README and GETTING_STARTED.**
- Rewrite `README.md`: what it is (no broken-links apology), headline results with the date and a link to
  `PROJECT_STATE.md`, a code map, the Flash-oracle goal, how the project relates to Ruffle, live demos, and D4's note
  about agent files.
- Write `GETTING_STARTED.md`: prerequisites, build the recompiler and runtime, `download_tests.sh`, run one test with
  `verify_output.py --test=…` in each mode, and where results and CI live.
- Check it by following it **on a fresh clone in a cloud session**, word for word. Fix every step that fails.
- Refresh the component READMEs (`SWFRecomp/README.md`, `SWFModernRuntime/README.md`, `ruffle-tests/README.md`) so
  they agree.
- **Done:** a cloud session following GETTING_STARTED passes one AVM1 and one AVM2 test from a fresh clone. Its log is
  linked from the commit.

**S5: docs entry point and ARCHITECTURE.**
- Rewrite `SWFRecompDocs/README.md` as an index: current docs (state, guides, specs, reference) and a link to the
  history repo.
- Write `SWFRecompDocs/ARCHITECTURE.md` for Ruffle developers: the pipeline (SWF → C → native/WASM), the runtime
  layout (`action.c`, the AVM2 tree, `swf.c` vs `swf_core.c`, render), the test harness and oracle, and the main
  differences from Ruffle's design.
- Mark the stale `ruffle-tests/tests/swfs/_investigation/OVERVIEW.md` headline numbers as superseded by
  `PROJECT_STATE.md`.
- **Done:** every link in both docs resolves (checked with a link script). The README links ARCHITECTURE.

**S6: branch and worktree prune (independent; any time no session is running).**
- For each of the 8 worktrees, check `git -C <wt> status` and check for commits not reachable from master. Report
  anything unlanded before removing it, then `git worktree remove` and `git worktree prune`.
- Delete the 290 merged local branches with `git branch -d`. `-d` refuses unmerged branches, so it is safe; the 3
  unmerged ones (`seedling-wasm-leak` and the rest) are listed for Robert.
- **D11 exception:** leave `SWFRecomp-CC-p4h` and `SWFRecomp-CC-p4h-rc1` (Archipelago-CC's p4h build trees) and `seedling-wasm-leak` alone until an Archipelago-CC session says which ones it still needs.
- Review the remote branches with Robert one at a time (`claude/*` cloud-worker branches, `lowq-fixes`, `t5-iso-v1`).
  Keep `ruffle-test-results` and `ruffle-image-results`.
- **Done:** `git worktree list` shows only the main tree, plus any worktree Archipelago-CC still needs (D11). `git branch` lists master plus the branches Robert chose to
  keep. The remote branch list matches his rulings.

**S7: SWF review and whitelist (discussion with Robert, then execution; ruled in D10).**
- Robert reviews the tracked SWFs path by path. At S2 (2026-11-28) there were 586 in the main repo:
  - 389 in `regression/` (322 of 347 dirs have a generator);
  - the rest in `docs/examples`, `_rando`, the divergence gates and tracer, `demos/`, `docs/injector` and `docs/recompiler`.
  - 5 of them were force-added outside any allow rule: `tools/flash-oracle/capture/{PinStub,CaptureWrapper}.swf`,
    `tools/flash-oracle/probes/tick_avm{1,2}/`, `SWFRecompDocs/plans/n-exec-order-sibling-fixture/test.swf` (the last
    one moves in S2b).
  - The history repo has 190, all fan-out fixture and probe SWFs (2026-11-21..27, 43 commits; the largest is 174 KB,
    910 KB in total).
  - No game SWFs and no Flash binaries are tracked.
- Origin, for the record: the 8 allow rules were each added by an agent session inside a feature commit, with a stated
  reason (2026-02-06 … 2026-09-02). The force-adds are a fan-out habit: seen in s27 worker reports, written into the s30
  coordinator brief (`638d02461`), and carried into `tools/coord/COORDINATOR_BRIEF_TEMPLATE.md:80` by S1.
- Then: give every SWF that is kept an allow rule. Untrack (forward-only `git rm --cached`) any that Robert rules out.
  Replace the template's `git add -f` line with the ruled procedure.
- **Done:** `git ls-files -ci --exclude-standard` is empty in both repos, and no brief, template or playbook tells a
  session to `git add -f` a SWF.

## 4. Risks

- **Peer collisions.** Moves in the shared tree during a fan-out repeat the s29 index-sweep hazard (memory
  `shared-index-commit-sweeps-peer-hunks`). S1, S2b and S3 run only while the tree is quiet.
- **Stale paths in briefs and memories.** Old briefs keep citing moved paths. Mitigations: the same relative layout
  in the history repo, the stubs, and the `SWFRecomp-CC-history:` citation prefix. Memories naming moved paths are
  updated in the same slice.
- **The fan-out machinery breaks silently.** If S1 misses a template or worker script, the next fan-out writes reports
  into the main repo again. The S1 done-line includes the dry-read of the brief template, and the next coordinator
  brief must cite `tools/coord/`.
- **CI publish path (S3).** Moving `RUFFLE_*.md` changes the results-branch merge. The memory
  `ci-results-branch-checkout-clobbers-unbacked-stems` shows how that flow fails. Verify with a full run and read
  the published files fresh.
- **GETTING_STARTED rots.** It is only as good as its last fresh-clone check. Re-run S4's check when the build
  changes.
- **Deleting by accident.** Each delete re-greps first. History keeps everything, so a mistaken delete is recoverable
  with `git checkout <sha> -- <path>`.
- **Clone size is unchanged.** The 323 MB pack stays, because no history rewrite is allowed. Accepted.

## 5. Out of scope

Rewriting history, shrinking the pack, renaming `master` (D7), vendored third-party libraries (SDL3 and the rest), and
the CANCELLED N procgen arc (S2 inventories its files only).

## 6. S1 closeout (2026-11-28, session `cleanup-s1-history-split`)

**Done.** History repo **`PeerInfinity/SWFRecomp-CC-history`** (public, default branch `master`, checkout
`~/CC/SWFRecomp-CC-history`), import commit `65eca06`. Main repo: `b2151adb1` (tools/coord), `49a663a5b` (removal +
stubs), `d81f64081` (citations + D3 machinery + D7), and this closeout commit. The tree was quiet: no SWFRecomp peer
session busy, no commits after `f92da554c`.

### What moved (4,861 tracked files, `git ls-files -s` byte-identical in both repos before the `git rm`)

| Path | Files |
|---|---|
| `plans/session{7..30}-fanout-reports/` + `session9-graphics-setup-reports/` | 4,477 |
| `prompts/` | 211 |
| `status/` | 114 |
| `plans/completed/` | 30 |
| `deprecated/` | 29 |

No binaries other than images, `.swf` fixtures and 2 `.ttf` (no ELF/PE, no Flash projector; everything was already
public in the main repo). 55 untracked/ignored files that sat in the moved dirs (50 built `.swf`, `__pycache__`) are in
neither repo: they were moved to `~/CC/SWFRecomp-CC-local-residue/s1-moved-untracked/` (same relative paths).

### The `status/` split: all 114 are logs, so the whole directory moved

Read file by file. None is current reference: every file is a dated record of one session or slice.
- 77 `YYYY-MM-DD-*.md` session logs (2025-11 heap/string work, the 2026-05/06 Doodle Jump, Snake, Tetris,
  Minesweeper, Riddle School and glaiel game-debugging logs, `2026-09-02-bitmap-texture-pools.md`).
- 26 undated slice closeouts, each with a `Date`/`Baseline`/`Brief` header: the multi-SWF arc slices
  (`child-*`, `per-movie-*`, `avm2-child-*`, `avm1-mcl-holder-totalframes`), the emission-mode slices
  (`avm2-try-helper-emission`, `avm2-tu-split-emission`, `avm2-dead-payload-skip`, `emission-mode-residuals`), the
  browser slices (`browser-*`), `bitmap-pool-layer-cap`, `seedling-collide-hotloop`, `avm2-observation-hooks`,
  `worktree-unlanded-work-audit-2026-09-04` + `worktree-rescue-2026-09-04/`.
- 2025 snapshots: `project-status.md` (last updated 2025-10), `OPCODE_CORRECTIONS_SUMMARY.md`,
  `o1heap-integration-investigation.md`, the four `experiment-0N-*-results.md`, and the old `README.md`.

Their current content already lives in the state docs and memories. Code comments and fixtures cite them as
provenance, and those citations were rewritten.

### Deviations from §3 S1

1. **One stub for the 24 report dirs**, `SWFRecompDocs/plans/fanout-reports.md`, not a `README.md` in each. 24
   placeholder dirs in `plans/` would undo the declutter. `prompts/`, `status/`, `deprecated/` and `plans/completed/`
   each got a `README.md` stub. `plans/README.md` now says finished plans go to the history repo.
2. **Memories: 87, not about 14.** The §1 count covered only fan-out-report citations. All 87 were rewritten with the
   same script (plus 4 bare `status/`/`prompts/` cites and one `[[../../…]]` link), after a backup copy was made.
3. **No functional dependency on a moved path.** `ruffle-tests/recompiler_ab_sweep.sh` only cites reports in comments,
   so "repoint" was a citation rewrite. The only code that reads a moved dir is the dead
   `scripts/build_opcode_index.py` (reads `SWFRecompDocs/prompts`, prints an error and continues if it is missing);
   S3 deletes it. `ruffle-tests/flash_fixes/fixes.json` `evidence` strings are free text with no consumer.
   `apply_flash_fixes.py --check` was run after the rewrite.
4. **Rewrite scope.** `d81f64081` touches 226 files: 221 from the main rewrite pass, a second pass for bare
   `status/x.md` / `prompts/x.md` mentions, and the D3/D7 edits. The changes are comments, docstrings, README/toml prose and markdown links only, with
   no code (every changed non-markdown line was checked to be a comment or docstring). Markdown links that resolved
   into a moved dir became `https://github.com/PeerInfinity/SWFRecomp-CC-history/{blob,tree}/master/…` URLs; local
   absolute paths became `~/CC/SWFRecomp-CC-history/…`. These were skipped, because S3 deletes them: `CC/`,
   `md-files.json`, `repository-data.json`, `opcode-index.json`, `docs/opcode-index.json` and
   `scripts/build_opcode_index.py`.
5. **The done-line grep.** `git grep 'fanout-reports'` also hits text that is not a moved path: the plan's own §1/§2
   descriptions (globs), and the D3 procedure text that names the generic `sessionN-fanout-reports/` path (playbook
   §5a, arc §31.5, `tools/coord/`, `fanout_cloud_worker.sh`). No concrete moved path is cited without the
   `SWFRecomp-CC-history` prefix.
6. **coord-tools.** The s30 copy is a superset of s26–s29 (allrows/status_moves* are blob-identical across copies;
   `land_branch.sh` exists only in s29/s30, identical); no tool existed only in an older copy. Changes:
   - `watch_reports.sh` takes `REPORT_DIR` instead of the hardcoded `session30` path;
   - `land_branch.sh` got `--help`, argument checks and a scratch-dir guard;
   - **new** `archive_branch.sh` copies a fanout branch's NEW/CHANGED report blobs into the history checkout, and is
     the closeout "cmp every blob" check before pruning;
   - **new** `COORDINATOR_BRIEF_TEMPLATE.md` (from the s30 brief) and `templates/_w{1,2}_header.txt`.
7. **D3 delivery shape (a design call; the plan didn't specify it).** A cloud session can push only to the repo it was
   launched on. Workers therefore clone the history repo read-only (`git clone --depth 1`), and they still deliver on
   `fanout/<slug>` in the MAIN repo, at the history-repo path. That branch is never merged. The coordinator lands the
   code with `land_branch.sh` and copies the report 1:1 with `archive_branch.sh`. `fanout_cloud_worker.sh` now warns
   when a prompt cites a session dir without naming the history repo, or when the history checkout is unpushed.
   **Untested end to end**: no fan-out ran in S1, so the first s31 worker is its proof. Check its first `get_run_log`
   for the clone.
8. **Ladder prompts and status closeouts go to the history repo too** (`SWFRecompDocs/prompts/`, `status/` there).
   This follows from D2 moving those dirs. Memory `session-launch-protocol` says so.
9. D7 is in `NO_GO_REGISTER.md` §1c.

### CI

`gh workflow run ruffle-tests.yml -f mode=graphics -f categories=all` at `d81f64081`: run `46165163125`.
**Green, results `97df6c0d2`.** Against the previous graphics results `a72b5c8a8` (run `46111106971`), graded with
`tools/coord/status_moves.py` / `allrows.py`, which is also their first smoke run from the new path: **0 status moves** on the
4,922-row intersection, so no pass→fail. 4,926 rows: 4,763 pass + 131 rm + 32 mm. The 4 new rows are upstream drift.
Ruffle migrated its SharedObject tests to the SWF runner on 2026-11-28 (`76660b186`, `d9d7154f0`, `624119354`):
`avm1/shared_object_self_ref` passes, while `avm1/shared_object`, `avm1/shared_object_localhost_network` and
`avm2/shared_object` are output_mismatch. These three are new rows for the next corpus session's drift slot.

### Next slice

**S2: side-project inventory and decision** (a discussion session with Robert; see §3 S2). Nothing in S1 blocks it. The
N capture/fixture dirs under `plans/`, `flash-oracle-captures` and `tools/divergence/perf/` are untouched and wait for
S2. S6 (prune) is independent and can run any time no session is active. The 8 worktrees may hold untracked copies of
moved paths; check them against the history checkout, not master (memory `fanout-worktree-residue-self-archives`).

## 7. S2 closeout (2026-11-28, discussion session `cleanup-s2-side-projects`)

**Done:** Robert ruled on every candidate (§2 D8a–D8l) and on the SWF question (§2 D10). This session moved and deleted
nothing in the main repo. It made one change in the history repo, the `.gitignore` (`7879606`).
- **Brief deltas:**
  - The perf dumps are **deleted**, not moved (D8f). There are 13 of them, 19.5 MB; S2's first estimate was 17.9 MB.
  - "Keep SWFs out of the repos" became D10, which is about how SWFs get tracked rather than which ones are tracked.
  - New slice S7.
  - The N procgen row in `NO_GO_REGISTER.md` ("docs stay in place") needs an edit in S2b.
- **Next slice: S2b** (execution; run it only while the tree is quiet). S3–S6 are unchanged. S7 (SWF review) needs
  Robert, and must run before the next fan-out or the template line in D10 must be changed first.

## 8. S2b closeout (2026-11-28, session `cleanup-s2b-extraction`)

**Done.** History repo import `bd3f5f8`. Main repo: `db8023b5e` (moves, stubs, D8f deletes, path citations) and this
commit (D8f recovery citations + closeout). The tree was quiet: no commits after `dc0915012`, no fan-out, ladder or
cleanup session committing here (the busy peers were the launcher and non-SWFRecomp sessions).

### What moved (193 tracked files; `git ls-files -s` mode+blob+path identical in both repos, plus `cmp` of every file, before the `git rm`)

| Ruling | Path | Files |
|---|---|---|
| D8a | `ruffle-tests/_eq_tas/`, `ruffle-tests/_rwk_tas/` | 5 + 15 |
| D8b | `tools/divergence/game_drive/{minesweeper_*,pacman_*}` (15 + 3) | 18 |
| D8c | `SWFRecompDocs/games/` | 2 |
| D8d | `SWFRecompDocs/plans/n-*` (21 docs + 4 capture/fixture dirs) | 140 |
| D8e | `SWFRecompDocs/plans/flash-oracle-captures/` | 12 |
| D8g | `tools/divergence/ARCHIVE.md` | 1 |

- The history repo's `.gitignore` got a D10 allow rule for `SWFRecompDocs/plans/n-exec-order-sibling-fixture/test.swf`
  (no `git add -f`). The copy was made with `git ls-files | tar`, so the 26 ignored probe `test.swf`/`.pyc` files and
  `game_drive`'s `Minesweeper.swf`, `Tetris.swf` and `compare_out/` never left this machine.
- Stubs: `ruffle-tests/{_eq_tas,_rwk_tas}/README.md`, `SWFRecompDocs/games/README.md`,
  `plans/flash-oracle-captures/README.md`, `plans/n-work.md` (the whole D8d set) and a pointer at
  `tools/divergence/ARCHIVE.md`. The `game_drive` README got a "Files" list of what stays plus a moved-probes line.
- Untracked residue: 27 files (the 26 above plus `game_drive/__pycache__/minesweeper_capture.cpython-312.pyc`) went to
  `~/CC/SWFRecomp-CC-local-residue/s2b-moved-untracked/`.

### Deleted (D8f, not copied)

The 13 dumps in `tools/divergence/perf` (19.5 MB): 5 `seedling_profile_*.json`, 4 `*.cpuprofile`
(`seedling_c4_2026-09-14/{demo-load,p4d-boot}`, `seedling_hotloop_2026-09-16/{on,off}-k544`),
`seedling_static_type_scout.csv`, `inst_slot_census_2026-07-15.txt`, 2 `ti_2026-07-20_*.png`. Recover any one with
`git checkout db8023b5e^ -- <path>`. `du -sh tools/divergence/perf` = 392 KB.

### Citations

- 37 tracked files rewritten to `SWFRecomp-CC-history:<path>` (comments, docstrings and prose only; the 7 code files
  changed comment lines only): bare forms like `n-stroke-snap-report.md`, `_eq_tas/…`, `flash-oracle-captures/…` and
  the probe filenames in `PROGRESS.md` were expanded to the full path. `plans/README.md`'s three procgen links became
  GitHub URLs. `NO_GO_REGISTER.md`'s procgen row now reads "code stays; the docs moved to the history repo".
  `guides/wasm-game-debugging-session-guide.md` cites the history copy of `FLASHARCHIVE_BUILD_RESULTS.md` as a 2026-05
  snapshot.
- D8f: 4 tracked files and 3 memories carry `deleted in db8023b5e; recover with git checkout db8023b5e^ -- <path>`.
- Memories: 21 changed in all (moved-path citations via the same script, plus the 3 D8f ones; backup taken first). One command line in
  `avm2-eq-init2-gotoframe-hotspot` got a local path (`~/CC/SWFRecomp-CC-history/…`) instead of the citation prefix,
  so the command still runs.

### Deviations and notes

1. **No live consumer of a moved path.** Every hit outside the moved set was a comment, docstring or doc. The perf rig
   (`analyze.mjs`, `probe.mjs`, `qtbucket.py`) reads `.cpuprofile` files by argument, not the deleted ones, so it still
   works on a fresh profile.
2. **`ARCHIVE.md` got a file stub at its own path** rather than a directory stub (it is a single file).
3. **Worktrees:** none of the 7 live worktrees holds untracked files under a moved or deleted path. The 8th
   (`…/wt-browser`) is gone and marked prunable; S6 prunes it.
4. **Done-line greps:** moved paths hit only stubs, `SWFRecomp-CC-history:` citations, history-repo URLs and this plan's
   own §1/§2/§3 text. D8f filenames hit only recovery citations and this plan.
5. **Checks:** `apply_flash_fixes.py --check` exit 0, no STALE rows. `regression/avm1_exec_order_sibling_interleave`
   (docstring rewritten) passes. No CI: comments only.
6. `tools/coord/COORDINATOR_BRIEF_TEMPLATE.md:80` left unchanged (S7, D10).

### Next slice

**S3: root declutter and dead files** (§3 S3; run it only while the tree is quiet; it needs a full CI run). S6 is
independent. S7 (SWF review with Robert) still has to precede the next fan-out.

## 9. S3 closeout (2026-11-28, session `cleanup-s3-root-declutter`)

**Done.** Main repo `7393244a4` (moves, deletes, CI publish path, citations) and `d387fcee5` (recovery citations for
the deleted files), plus this closeout. History repo import `2d2f63f`. The tree was quiet: no commits after
`825773464`; the busy peers were the launcher and non-SWFRecomp sessions. The GitHub root is now `.claude`, `.github`,
`.gitignore`, `CLAUDE.md`, `LICENSE`, `README.md`, `THIRD_PARTY_NOTICES.md` and the real directories (`SWFModernRuntime`,
`SWFRecomp`, `SWFRecompDocs`, `demos`, `docs`, `docs2`, `ruffle-tests`, `scripts`, `tools`).

### Result tables moved to `ruffle-tests/results/`

- `RUFFLE_RESULTS{,_FILTERED,_GRAPHICS,_GRAPHICS_FILTERED}.md` and `RUFFLE_COMPARISON{,_FILTERED}.md` were `git mv`'d
  there. `generate_results_index.py` and `generate_ruffle_comparison.py` write there; links are now relative to that
  dir (`../ignored_tests.txt`, `../tests/swfs/<suite>/_results/…`). `publish_results.sh` stages the new path, and the
  upload-artifact path in `ruffle-tests.yml` changed. `weekly-no-graphics.yml` calls `ruffle-tests.yml`, so it needed
  no edit. New `ruffle-tests/results/README.md`. The pipeline handoff's merge step now says root `RUFFLE_*.md` must not
  come back.
- **The merge flow (a brief delta for §3 S3 and §4).** The first design (master deletes the root copies and CI writes
  the new path) **conflicted**. It was replayed in a scratch worktree with a sed'd `publish_results.sh` (fetch and
  push stubbed) and a plain `git merge`. Git's rename detection reads the branch's "delete root + add new path" as a
  rename (71–75 % similar), so the merge hit rename/delete. `git merge -X no-renames` (ort, git 2.43) did not avoid
  it; only `-s recursive -X no-renames` did. The landed design needs no special merge:
  - master makes a pure rename (content unchanged);
  - `publish_results.sh` `git rm`s the four CI-generated root copies on the branch, so the branch's first publish is
    the same rename;
  - `RUFFLE_COMPARISON*` are deliberately left alone on the branch. CI never regenerates them, and deleting them there
    made master's rename of them a rename/delete conflict. The branch keeps two stale, untouched root copies, which is
    harmless: they never change, so a merge never brings them back.
  Two rounds of publish → plain merge in the replay were clean, with 0 root `RUFFLE_*` files. Residual risk: a publish
  from a run dispatched at a pre-S3 ref would re-add root copies, and a plain merge would bring them back silently.
  The handoff's post-merge check covers it, and the next current-layout publish deletes them from the branch.
- `RUFFLE_COMPARISON*.md` is a 2026-05-09 snapshot, run by hand, and the README says so. It was moved, not
  regenerated: regenerating it needs a synced local corpus with the Ruffle `output.ruffle.txt` sidecars.

### Deleted (git history keeps them; recover with `git checkout 7393244a4^ -- <path>`)

| Path | Grep result |
|---|---|
| `md-files.json`, `repository-data.json`, `CC/` (2025 prompt scripts + `CC/docs`) | Only read by `CC/scripts` |
| `local_swf_batch/{README.md,.gitkeep}` | **Live dir, tracked files dead.** It is `build_swf_batch.sh`'s default input (also in `guides/building-docs2-demos.md`). The directory stays as an untracked local working dir: `.gitignore` now ignores all of `/local_swf_batch/`, and the README's two facts moved into the script header. Robert's local `Snake.swf` there is untouched. |
| `SWFModernRuntime/test_*.c` (5), `Makefile.test*` (4) | Only the component README (rewritten) |
| `SWFRecomp/tests-wip/` (8) | none |
| `docs/examples.staging/` (5, D8k) | none. Pages redeployed: see CI. |
| `.github/workflows/test.yml` **and `all-tests.yml`** | `all-tests.yml` was `test.yml`'s only caller (no runs since 2026-02). Without `test.yml` it cannot run, so it went too. The `ruffle-tests.yml` comment that names it was updated. |
| root `opcode-index{.json,.md,-plain.md}`, `feature-index{,-plain}.md`, `scripts/{build_opcode_index,generate_opcode_markdown,test-and-document}.py` | Only `test.yml`, `CC/`, and the `guides/adding-graphics-tests.md` steps (rewritten as "retired"). **Kept:** `docs/opcode-index.json`, because `docs/index.html` and `docs2/index.html` fetch it. It is now a frozen 2026-03 snapshot. The copy step in `generate_examples_index.sh` is left in place (it no-ops) with a comment. |
| `demo-list.md` + `scripts/generate_demo_list.py` | Nothing read it. It duplicated the Pages catalog, so it was deleted rather than regenerated. |
| `SWFRecompDocs/docs/` (144 files, 2.8 MB of 2025 example WASM builds) | **Not in the brief.** Dead build output, superseded by the root `docs/` Pages site. Deleted rather than moved (the D8f precedent: no build output in the history repo). `reference/wasm-build-process.md`'s commands now target `../docs/examples`. |

### Moved to the history repo (11 files, `git ls-files -s` identical + `cmp` before the `git rm`)

`SWFRecompDocs/{opcode-categorization,opcode-instance-prompt-template,parallel-opcode-experiments,parallel-opcode-implementation-guide,parallel-opcode-implementation-guide-v1,complete-implementation-guide,failing-test-fix-guide}.md`
are the 2025 opcode-campaign guides and prompts. `planning/` (2 files) holds the app_context plan, marked OBSOLETE since
2025-12-20. `ruffle-probing-trace-log.md` + `probing-trace-log.patch` are superseded by
`reference/ruffle-local-patches{.md,.patch}`, which vendors that patch. These were copied with `git ls-files | tar`, not
`cp -r`. Citations were rewritten in 7 `SWFRecomp/tests/*/README|STATUS` files, `reference/ruffle-local-patches.md` and
the merge plan. No stubs: these are single files, and none is cited by a live doc, brief or memory.

**Kept at the `SWFRecompDocs/` root:** `README.md` (S5 rewrites it; its one link to the deleted `docs/` was fixed),
`BACKLOG.md` (live: entries from 2026-09, cited by the playbooks), and `scripts/` (`check_style.py` for upstream merges,
the markdown fixer; tooling, not a one-off).

### Workflows kept

`deploy-pages-build.yml` ("Deploy GitHub Pages (with SWF build)") stays. It is maintained (runner pin 2026-11-21,
bundle smoke 2026-09-02), and `plans/graphics-image-baseline.md` documents it as a dispatch target. It has no runs since
2026-04 only because `deploy-pages.yml` is the default.

### Memories

`graphics_native_workflow`, `corpus-denominator-double-counts-nested` and `ci-results-branch-checkout-clobbers-unbacked-stems`
now name the new path. The last one also gained the path-move trap. `repo-cleanup-for-ruffle-team` and its MEMORY.md line
were updated. No memory cited a moved or deleted doc.

### CI

| Run | Mode | SHA | Result | Merge | Status moves (`corpus_status_diff.py`, read fresh off the merged JSONs) |
|---|---|---|---|---|---|
| `46170120039` | graphics, `all` | `d387fcee5` | green, published `63ccc2516` | plain merge clean, 0 root `RUFFLE_*` | **0** on 4,926 rows (4,763 pass + 131 rm + 32 mm), so no pass→fail |
| `46173190962` | no-graphics, `all` | `494d7c7e0` | green, published `cb2c3a814` | plain merge clean, 0 root `RUFFLE_*` | **0** on 4,922 rows (4,760 + 131 + 31) |

- The no-graphics leg was dispatched because `weekly-no-graphics.yml` publishes through the same `publish_results.sh`.
- Every link in the four published tables resolves from `ruffle-tests/results/`.
- After both publishes the branch tracks only the two stale `RUFFLE_COMPARISON*` root copies, as designed.
- Pages: `deploy-pages.yml` run `46170122511`. The Deploy step ran (success). `examples.staging/` now returns 404, and
  `opcode-index.json` is still served.

### Next slice

**S4: README and GETTING_STARTED** (§3 S4; it needs a fresh-clone cloud check). The S4 README should link
`ruffle-tests/results/RUFFLE_RESULTS_GRAPHICS.md` for headline numbers. S5 owns the `SWFRecompDocs/README.md` rewrite
(it still lists 2025 content). S6 is independent. S7 (SWF review) must still precede the next fan-out, and
`tools/coord/COORDINATOR_BRIEF_TEMPLATE.md:80` is untouched.

## 10. Sibling repos: seedling-wasm and swfrecomp-browser (D11, Robert, 2026-11-28)

Ruled in discussion session `repo-cleanup-discussion` while S3 ran. Recorded here after S3's closeout landed.

**Facts (2026-11-28):**
- `PeerInfinity/seedling-wasm` is PUBLIC. It holds 4 builds in a 146 MB tree:
  - `seedling_original` (the vanilla demo, role `demo`), on SWFRecomp-CC `344c85a` from 2026-10-19;
  - `p4g` (the default, `344c85a`);
  - `p4h` (the candidate, `746c39489`);
  - `p4d` (the control).
- Archipelago-CC consumes seedling-wasm as a submodule. It gates the repo with
  `scripts/procgen/check-seedling-wasm-pins.mjs` and generates the README build table with
  `scripts/procgen/seedling-wasm-readme.mjs --write`.
- Its history was shed once (orphan commit and force-push, 2026-09-14), under its own `docs/history.md` policy.
- `PeerInfinity/swfrecomp-browser` is PUBLIC: one release of the in-browser recompiler page (release 3, `344c85a`,
  2026-10-19, 25 MB). This repo's `tools/browser-release/make_release.py` writes it.
- Archipelago-CC consumes swfrecomp-browser as a submodule as well. It **pins its `source.commit` against the
  recompiler of the shipped Seedling build.**
- Archipelago-CC is setting up p4h on `746c39489` (seedling-wasm branches `p4h-main` and `p4h-rc1`, 2026-11-22).
- `dawn-prebuilt` calls itself disposable, but `ruffle-tests.yml`, `build-dawn.yml` and `cloud_env_setup.sh` use it,
  so it stays.

**Rulings:**

| # | Ruling |
|---|---|
| D11a | **Rebuild only the vanilla `seedling_original`** on the latest SWFRecomp-CC, from its own SWF bytes (`~/CC/seedling_original_build/Seedling_original_r1.swf`, md5 `a543c03a…`): no mxmlc, no inject. Commit to seedling-wasm only (the build dir, the `builds.json` entry and the README table row). Run Archipelago-CC's pins check and README generator READ-ONLY to produce and check them. An Archipelago-CC session gets a note asking it to bump the submodule under its own gates. The bot builds are not rebuilt here. |
| D11b | **swfrecomp-browser release 4 waits** until Archipelago-CC makes p4h the default. Then it is built on the recompiler commit Archipelago ships (`746c39489`, or newer if p4h is rebuilt), so the pin holds. |
| D11c | **Docs: discuss first.** Robert thinks the seedling-wasm docs might be fine as they are. One discussion covers seedling-wasm and swfrecomp-browser. Suggested so far: one line in the swfrecomp-browser README linking SWFRecomp-CC's live Pages copy. |
| D11d | **No history shed for seedling-wasm.** Prune its stale branch `p4f-rebuild` (2026-10-04). Keep `p4h-main` and `p4h-rc1`. |
| D11e | **Protect p4h's things:** the SWFRecomp-CC worktrees `SWFRecomp-CC-p4h` and `SWFRecomp-CC-p4h-rc1`, and the seedling-wasm branches `p4h-main` and `p4h-rc1`. S6 asks an Archipelago-CC session before touching any of them. |
| D11f | **Leave the old forks `PeerInfinity/SWFRecomp` and `PeerInfinity/SWFModernRuntime` as they are.** No archive flag, no pointer README. |

**Slices:**
- **R1: vanilla Seedling rebuild (D11a, D11d), next.**
  - Build in a fresh detached worktree at the current `master` HEAD, under `flock /tmp/swfrecomp-cpu.lock`, with -j4
    / `EMCC_CORES=4`.
  - Recipe: `FRESH=1 build_wasm_avm2.sh` with the defaults, then `deploy_wasm_avm2.sh`. The recipe is in the
    `seedling_original` `builtFrom` field.
  - Smoke-test it in a browser: it boots, the title appears, ▶ Start reaches gameplay. SwiftShader in WSL is fine for
    function; take no perf numbers there.
  - Commit and push to seedling-wasm. Delete `p4f-rebuild` there.
  - Leave the Archipelago-CC note.
  - **Done:** seedling-wasm `main` carries the rebuilt `seedling_original` with a matching `builds.json` entry. The
    pins check passes, run read-only against the updated submodule checkout. The smoke test is recorded. The handoff
    note is delivered.
- **R2: swfrecomp-browser release 4 (D11b), gated on Archipelago-CC making p4h the default.**
  - `make_release.py --rebuild` at the shipped recompiler commit.
  - **Done:** release 4 is pushed, `release.json`'s `source.commit` equals the shipped Seedling build's recompiler,
    the Pages page loads and recompiles one example, and Archipelago-CC has been told.
- **R3: docs discussion for seedling-wasm and swfrecomp-browser (D11c), after R1.** A discussion with Robert. Rulings
  are appended here; an edit slice follows only if he rules one.

### R1 closeout (2026-11-28, session `cleanup-r1-vanilla-seedling`)

**Done except the branch prune.** seedling-wasm `main` = **`ecc5eaf`** (from `a335206`). It carries `seedling_original`
rebuilt on SWFRecomp-CC **`8e6ef0c354e96553813ed28cb56ceae85e3e1fe0`**, with its `builds.json` entry and README row.
The other three builds are untouched.

- **Build:** a detached worktree at `8e6ef0c35`, now removed.
  - Recompiled the same SWF bytes (md5 `a543c03a…` verified) into
    `~/CC/seedling_original_build/recompiled_orig_r5`, using the r4 config shape.
  - The counts are **708 classes, 3759 methods, 3649 bodies, 0 verify failures, 491 SymbolClass bindings**. They equal
    every earlier build, and the recompiler log is line-identical to r4's.
  - `diff -rq` against r4 moves only `abc_timeline.c`, `draws.c`, `draws.h` and `tagMain.c`.
  - Then `FRESH=1 build_wasm_avm2.sh` with the defaults, under the flock with `EMCC_CORES=4` and emcc 5.0.0: 7m06s.
    The script compiles serially, so there is no `-j` to cap. Then `deploy_wasm_avm2.sh` with `DEMO_SWF`.
- **Payload md5s:**

  | file | md5 | bytes |
  |---|---|---|
  | `seedling_original.wasm` | `b125136a89eb215a2284c2ab98aaddae` | 36,189,620 (+196,715) |
  | `seedling_original.js` | `d92c4afc12e0ddc88298a9501c08c964` | 155,665 |
  | `game.html` | `1c22f10c…`, byte-identical | 3,643 |
  | `swf_bridge_avm2.js` | `9fbbf1bb…`, byte-identical | 4,725 |
- **Smoke test.** Headless Chromium 1243 on SwiftShader-Vulkan, the deployed `game.html`, a real click on ▶ Start:
  - the runtime is ready at 0.5 s;
  - the title screen renders and was screenshotted (its `Level:` block came at 79 s);
  - a key press reaches the overworld (the third `Level:` block at 93.7 s, P-Pos 80,128): house, player and opening
    dialog;
  - 0 WebGPU errors, 0 pageerrors, `__swfGpu` `{lost:0, stalls:1}`, and only the shim's own bridge line.

  Screenshots, log and script are in `~/CC/seedling_original_build/recompiled_orig_r5/smoke/`. No perf numbers.
- **Archipelago-CC's tools were run read-only.** They ran in a `git clone --shared` in the scratchpad at Archipelago
  `origin/main` `b4f4093` (GitHub `main` at the time), with the submodule path holding the seedling-wasm commit.
  - `seedling-wasm-readme.mjs --write` regenerated the row, and `--check` then reported OK.
  - `check-seedling-wasm-pins.mjs` reported **ALL PASS — 4 pinned builds, four views in agreement**.
  - Nothing was written to `~/CC/Archipelago-CC`. Its local `main` is 1209 commits behind `origin/main`, so check
    against `origin/main`.
- **Finding: the vanilla build now carries the SharedObject host hook.** The new runtime exports `avm2_so_flush_all`
  and `avm2_so_reload`, the hook p4h declares as `sosave`. `game.html` sets no `Module.swfSharedObjectHost`, so saves
  stay memory-only. `capabilities` stays `[]` because nothing drives a demo. Declaring `sosave` is Archipelago's call.
- **NOT DONE: deleting `p4f-rebuild`.** The auto-mode classifier denied `git push origin --delete p4f-rebuild`.
  - The branch is fully merged into `main` (`2de3163`), and no tracked Archipelago-CC file names it.
  - Robert can run that command, or approve it for a later session.
  - `p4h-main` and `p4h-rc1` are untouched (D11e).
- **Archipelago-CC handoff note:** seedling-wasm `main` moved `a335206` → `ecc5eaf`. Only `seedling_original` changed:
  - its `.wasm` and `.js`, its `builds.json` entry (md5s, bytes, `source.recompiler` = `8e6ef0c35…`, a new `builtFrom`
    paragraph) and its README row;
  - payload md5s: wasm `b125136a89eb215a2284c2ab98aaddae`, js `d92c4afc12e0ddc88298a9501c08c964`;
  - p4d, p4g and p4h are byte-identical.

  To do in Archipelago-CC:
  - bump the `frontend/modules/flashPanel/wasm` gitlink to `ecc5eaf` in its own commit;
  - run `check-seedling-wasm-pins.mjs` and `seedling-wasm-readme.mjs --check` (both green here);
  - price the bump with `check-seedling-full-tier-owed.mjs`. The demo's payload md5 moved, so the manifest-prose
    exemption does not apply by its letter, although no build an instrument drives moved;
  - decide whether the demo should declare `sosave`.

  The swfrecomp-browser pin is unaffected: it pins the default build's recompiler, and that is still p4g on `344c85a`.
- **Next:** R3 (the docs discussion) is unblocked. R2 still waits for p4h to become the default.

## 11. S4 closeout (2026-11-28, session `cleanup-s4-readme-getting-started`)

**Done.** Main repo `beb2daeee` (README, GETTING_STARTED draft, Ruffle attribution), `d62ed2bd0` (fixes from the
first two checks, component READMEs) and the closeout commit (bare-image fixes, check record, this section). History
repo `882fdf0` holds the three check reports at
`SWFRecomp-CC-history:SWFRecompDocs/plans/repo-cleanup-s4-checks/`.

### What changed

- **`README.md` rewritten:** what the project is (no broken-links apology); the FP32 goal with Ruffle's corpus as the
  instrument and `tools/flash-oracle/` as the oracle; dated headline results; live demos (gallery, in-browser
  recompiler, Seedling play page, swfrecomp-browser); a code map; the Ruffle and upstream-SWFRecomp relationships;
  the D4 note (`CLAUDE.md` is the agent manual; the session record is in the history repo).
- **Headline numbers, read fresh** (`corpus_status_diff.py 63ccc2516 WORKTREE`, 0 moves): 4,927 graded rows, 4,763
  pass, 131 rm, 33 failing. The published tables mix two runs, and the README says so: the five classic suites come
  from `46170120039` (`d387fcee5`), and from_avmplus + misc from the 2026-11-28 `full` run `46111106971`
  (`3dfab1277`). Only cleanup commits lie between them. Pixels: 564/701 (s30 `images=true`, 2026-11-27), from
  `PROJECT_STATE.md`.
- **`GETTING_STARTED.md` (new):** prerequisites, the recompiler build, `download_tests.sh avm1 avm2`, AVM1 `add` and
  AVM2 `hello_world` with `verify_output.py`, optional graphics mode (prebuilt Dawn or `build_dawn.sh`), where
  results and CI live, and a dated "last fresh-clone check" table.
- **Component READMEs rewritten** (`SWFRecomp/`, `SWFModernRuntime/`, `ruffle-tests/`). Gone: the 2025 quick starts
  (`git clone PeerInfinity/SWFRecomp`), the dead `swfrecomp.github.io` demo links, the 2025 feature tables and the
  "Ruffle AVM1 only" framing. They now carry source maps that match the tree, the three build modes, and the harness
  layout and statuses. `ruffle-tests/tests/swfs/_investigation/ENVIRONMENT_SETUP.md` (2026-02, stale paths) got a
  "superseded by GETTING_STARTED" banner.

### Deviation: Ruffle attribution (a brief delta, flag for Robert)

The README draft said "we copy no Ruffle code". That is **false**: about 30 runtime files (`avm2/` ×23,
`actionmodern/` ×3, `libswf/` ×2, `rendering/` ×1, `SWFRecomp/src/abc/` ×1) carry functions marked as ports of
Ruffle source. Examples: `f64_to_string`, the avmplus qsort, ByteArray, BitmapData, timers, the h263 deblock.
`THIRD_PARTY_NOTICES.md` had no Ruffle row. S4 added one, plus Ruffle's MIT text at
`SWFModernRuntime/third_party/ruffle/LICENSE-MIT.txt` (Ruffle is MIT OR Apache-2.0; we chose MIT to match `LICENSE`).
The README now says plainly that behaviours were ported. This is docs only, but it is a licensing statement, so
**Robert should confirm the MIT choice and the wording.** A per-file audit (which functions, which Ruffle commit) was
not done.

### The fresh-clone check (plan §3 S4 done-line)

| # | Session | Where | Guide | No-graphics `add` / `hello_world` | Graphics |
|---|---|---|---|---|---|
| 1 | `session_018CoDi3TqLnVixMvHy4vGuF` | cloud default env | `beb2daeee` | PASS / PASS | not run |
| 2 | `session_018CoDi6uNaspruPSt4SUSiF` | "SWFRecomp fan-out" env (Dawn preinstalled; used via `DAWN_INSTALL`) | `beb2daeee` | PASS / PASS | PASS / PASS |
| 3 | `session_018CoDi6ryUHMjHL2SEUoTxh` | **bare `ubuntu:24.04` Docker image** (92 packages at start) inside a Full-network cloud session | `d62ed2bd0` | PASS / PASS | PASS / PASS (Dawn downloaded per §6.2) |

- Checks 1 and 2 passed verbatim, but their images had preinstalled `-dev` packages. Check 2 traced the closure:
  **`zlib1g-dev` was a missing prerequisite**. The runtime links `-lz`, and the recompiler bundles its own zlib, so
  the build hid it. CI's ubuntu-24.04 runner image has it too. Check 3 ran with `zlib1g-dev`, `ca-certificates` and
  `curl` added, on a truly bare image, and needed no workaround.
- Other fixes from the checks: real first-run times (AVM1 about 40–45 s, AVM2 about 60–73 s, graphics about 50 s);
  the one expected GCC `-Wstringop-overflow` warning at `SWFRecomp/src/swf.cpp:292` (a false positive: `m` is
  `double[4][5]` and `sizeof(m)` is 160); the real expected output; the `flash-fix APPLIED` lines and the
  found/installed count; Dawn's `../dawn-install` vs the tarball MANIFEST's `~/CC`; Pillow through apt (PEP 668); a
  single "drop `sudo` if root" note; disk (about 350 MB, plus about 1 GB of apt packages).
- Not fixed (code or harness wording, outside a docs slice):
  - the `-Wstringop-overflow` false positive itself;
  - `download_tests.sh` printing its summary block twice;
  - `verify_output.py`'s missing-Dawn error, which names neither `DAWN_INSTALL` nor the prebuilt.
- The prebuilt Dawn download was NOT blocked in check 3. The 2026-09-28 classifier denial (memory
  `cloud-session-launch-cli`) did not recur when the task was a documented setup step.
- The delivery branches `fanout/s4-check-{nographics,graphics,bare}` are left on origin. Their reports are archived
  in the history repo, so S6 may delete them.

### No CI

Docs only. No code, CI or Pages path changed.

### Next slice

**S5: docs entry point and ARCHITECTURE** (§3 S5). `README.md` links `SWFRecompDocs/README.md`, which still lists 2025
content; S5 rewrites it and must add the ARCHITECTURE link to the README. Also open for Robert: confirm the Ruffle
attribution above. S6 is independent; S7 must still precede the next fan-out.

## 12. Ruffle attribution and first-build fixes (D12, Robert, 2026-11-28)

Ruled after S4 found Ruffle ports that nobody had credited (§11).

- **D12a:** Ruffle-derived code is used **under MIT** (Ruffle is MIT OR Apache-2.0). S4's README paragraph,
  `THIRD_PARTY_NOTICES.md` row and `SWFModernRuntime/third_party/ruffle/LICENSE-MIT.txt` stand.
- **D12b:** a **per-file attribution audit (slice A1) runs before S5**, because ARCHITECTURE describes the same code.
- **D12c:** A1 also fixes S4's three first-build defects:
  - the GCC `-Wstringop-overflow` false positive at `SWFRecomp/src/swf.cpp:292`;
  - `download_tests.sh` printing its summary twice;
  - `verify_output.py`'s missing-Dawn error not naming `DAWN_INSTALL`.

**A1: Ruffle attribution audit and first-build fixes.**
- Find every function or block ported from, or closely modelled on, Ruffle code. Don't rely only on the comments that
  say "port": also look for Ruffle-derived tables, constants and algorithms (e.g. `git grep -i ruffle` in
  `SWFModernRuntime/` and `SWFRecomp/src/`, then read each hit).
- Make every ported function's comment cite its Ruffle source file path. Add a commit ref where one is known.
- Add an attribution table, file → Ruffle source, to `THIRD_PARTY_NOTICES.md` or to
  `SWFModernRuntime/third_party/ruffle/README.md`.
- Comments and docs only for the attribution. The three D12c fixes are minimal code changes.
- **Done:** every ported function names its Ruffle source, and the table exists. The three D12c fixes are landed. A
  per-change graphics CI run passes with no pass→fail. Closeout as §12 "A1 closeout". Next slice line: S5.
