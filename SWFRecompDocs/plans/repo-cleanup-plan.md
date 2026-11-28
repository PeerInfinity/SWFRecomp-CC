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
| D8 | Side projects | **To be decided.** Robert wants some side projects moved out of the main repo. Which ones, and where they go, needs investigation and discussion: slice S2. |
| D9 | Order | Structural moves first, so the docs written later point at final paths. The prune is independent. |

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
- Promote the coordinator tooling to `tools/coord/` (newest copy from `session30-fanout-reports/coord-tools/`) and
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

**S2b: side-project extraction (only if S2 rules any moves).** Same mechanics as S1: copy at the same relative paths,
leave stubs, rewrite citations, and run CI if test fixtures or tooling paths move. **Done:** S2's per-project rulings
are executed, and `git grep` for each moved path hits only stubs and citations.

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
- Review the remote branches with Robert one at a time (`claude/*` cloud-worker branches, `lowq-fixes`, `t5-iso-v1`).
  Keep `ruffle-test-results` and `ruffle-image-results`.
- **Done:** `git worktree list` shows only the main tree. `git branch` lists master plus the branches Robert chose to
  keep. The remote branch list matches his rulings.

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
