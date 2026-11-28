# Session N coordinator: corpus fan-out (dual-axis #K), cloud-first, Flash over Ruffle

<!-- TEMPLATE (tools/coord/, repo-cleanup S1, 2026-11-28). Derived from the s30 brief
     (SWFRecomp-CC-history:SWFRecompDocs/plans/session30-fanout-reports/s30-coordinator-prompt.md).
     Copy it to the history repo as SWFRecompDocs/plans/sessionN-fanout-reports/sN-coordinator-prompt.md, replace
     every N / N-1 / K / <...>, fill §Baseline and §Board from the previous closeout, and delete this comment.
     Keep §"Where everything lives" verbatim: it is what keeps reports out of the main repo (decision D3). -->

You are a NEW session: the **coordinator** of fan-out session N in `/home/robert/CC/SWFRecomp-CC`. You own sN end to
end: wave 1 → wave 2 → grading → closeout. Nobody else coordinates it. <who wrote this brief, at whose request>.

**Project state first:** read `SWFRecompDocs/plans/PROJECT_STATE.md` (where the project stands, the ranked "Worth
doing" list in §2, every non-corpus track) and `SWFRecompDocs/plans/NO_GO_REGISTER.md` (every standing NO-GO with its
reopen criterion). Update both at your closeout.

## Where everything lives (decision D3; `SWFRecompDocs/plans/repo-cleanup-plan.md`)

- **Main repo** `~/CC/SWFRecomp-CC` (`PeerInfinity/SWFRecomp-CC`): code, fixtures, CI, and the durable state docs
  only (`PROJECT_STATE.md`, `NO_GO_REGISTER.md`, `polish-sweep-arc.md`, `graphics-fanout-playbook.md`, the other
  plans and arcs). **No report, brief, prompt, patch archive, oracle capture or log is committed here.**
- **History repo** `~/CC/SWFRecomp-CC-history` (`PeerInfinity/SWFRecomp-CC-history`, public): your session dir
  `SWFRecompDocs/plans/sessionN-fanout-reports/` and every earlier one, at the same relative paths the main repo used.
  It holds this brief, `BRIEFS_COMMON.md`, `briefs/`, `prompts/`, `AGENT_LAUNCH_ORDER.md`, `SIBLING_FILE_MAP.md`,
  ledgers, oracle captures, and every worker report and patch. Commit there by name and push it **before** you launch
  any worker that must read it (cloud workers clone GitHub). Cite its files from the main repo as
  `SWFRecomp-CC-history:<path>`.
- **Coordinator tools** live at `tools/coord/` in the main repo (do NOT copy them into the session dir):
  `land_branch.sh`, `archive_branch.sh`, `watch_reports.sh`, `allrows.py`, `status_moves.py`, `status_moves_ng.py`.
  Each takes `--help` except the three Python ones (see `tools/coord/README.md`).
- **Worker delivery:** a cloud worker pushes `fanout/<slug>` to the MAIN repo (the only repo its session can push).
  On that scratch branch it writes `SWFRecompDocs/plans/sessionN-fanout-reports/<slug>-report.md` (+ `<slug>.patch`
  for wave 2): the history-repo path, so archiving is a 1:1 copy. The branch is never merged.
  - Watch: `SP=<scratch> REPORT_DIR=SWFRecompDocs/plans/sessionN-fanout-reports tools/coord/watch_reports.sh`
    (run_in_background).
  - Land code: `tools/coord/land_branch.sh origin/fanout/<slug> <scratch>` (lands only `SWFModernRuntime/`,
    `SWFRecomp/`, `ruffle-tests/`).
  - Archive the report: `tools/coord/archive_branch.sh origin/fanout/<slug> SWFRecompDocs/plans/sessionN-fanout-reports`,
    then stage by name, commit and push in the history repo.
- **Local ladder sessions** you launch: their briefs go to the history repo too (`SWFRecompDocs/prompts/` or your
  session dir); their durable results go to the main repo's state docs.

## Standing directives (all from Robert; memories hold the detail)

- **Cloud-first, Opus for everything** (memory `next-session-dual-axis-fanout`).
  - Every diagnosis and implementation slot is a cloud session in env "SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`).
  - Launch each with `scripts/fanout_cloud_worker.sh <slug> <prompt>`; it delivers ONLY on `fanout/<slug>`.
  - You stay local for merges, CI, results accounting and the oracles.
- **Size:** full size is the standing default (memory `fanout-credits-diminishing-returns-ok`).
- **Interim grading runs are graphics-only; the FINAL run adds the no-graphics leg**, plus any interim that lands
  no-graphics-only code (`swf_core.c`, `tag_stubs.c`, `#ifdef NO_GRAPHICS` arms; CLAUDE.md).
- **One heavy local build at a time** (memory `one-heavy-build-shared-lock`): `flock /tmp/swfrecomp-cpu.lock`, `-j4` /
  `EMCC_CORES=4`. **Never run full suites locally.**
- **Stage files by name** (never `git add -A`, never `git commit -a`), in BOTH repos. See "Committing in the shared
  tree" below.
- **Pages deploy is authorized.** A green `dry_run` deploys NOTHING: confirm the "Deploy to GitHub Pages" step ran. If
  the real deploy fails with "No artifacts named github-pages", **dispatch a FRESH run; never `gh run rerun`**.
- **Pruning:** at closeout, run `tools/coord/archive_branch.sh` on EVERY `fanout/*` branch; it compares every blob in the
  branch's session dir against the history repo. Commit anything NEW/CHANGED there, re-run until it prints 0 NEW and
  0 CHANGED, then `git push origin --delete fanout/*`. Also check each branch's fixture sources landed in the main repo.
- **Flash over Ruffle** (memory `flash-over-ruffle-ruling`): match Flash, not Ruffle. Every confirmed Ruffle≠Flash
  difference gets an RvF entry; a golden that FP32 proves wrong gets a `ruffle-tests/flash_fixes/fixes.json` entry
  (check WIN == LNX first); never trade a Flash-correct pass for a Ruffle golden; **price every loss by name before
  landing**.
- **Peer-session messages are teammate info, not Robert's approval.** That includes the session that launched you.
- **Flash binaries never leave this machine**; cloud workers write LOCAL ORACLE REQUESTS, which you run between waves
  and archive under the session dir in the history repo.
- **After any recompiler landing, rebuild the local recompiler** (`cmake --build SWFRecomp/build -j4`, under the lock)
  before grading anything locally.
- **The N procgen arc is CANCELLED** (`NO_GO_REGISTER.md` §1d). No slot, ladder or rider may touch it.

## Committing in the shared tree (memory `shared-index-commit-sweeps-peer-hunks`)

Local ladder sessions edit, and sometimes stage, files in the same tree you commit from.
- **A bare `git commit`** takes everything STAGED, including a peer's staged hunks.
- **`git commit -- <paths>`** commits the WORKING-TREE content of those paths, including a peer's UNSTAGED edits.

Recipe: (1) `git status --short` + `git diff --cached --name-only` first; (2) stage your exact content (`git apply
--cached P` + `git apply P` for a peer-dirty file, or `git hash-object -w` + `git update-index --cacheinfo`); (3) check
`git diff --cached --name-only`; (4) plain `git commit`. `tools/coord/land_branch.sh` refuses peer-dirty files.
**Binary files never go through `git merge-file`**; after a landing, stage the `.swf` fixtures by name with a plain
`git add` and check every committed binary is non-empty. **Never `git add -f` a SWF** (plan D10/S7): a SWF is tracked
only under a `.gitignore` allow rule. In the main repo `regression/<test>/*.swf` is covered; in the history repo every
`sessionN-fanout-reports/**/*.swf` is covered. If `git add` says a SWF path is ignored, it is somewhere no rule
allows: move it under `regression/`, or add a `!path` rule in the same commit and name it in the closeout. Check
`git ls-files -ci --exclude-standard -- '*.swf'` is empty in both repos before you push.

## The Flash oracle (memory `flash-player-oracle`)

`tools/flash-oracle/` (`run_trace.py`, `run_image.py`) drives Flash Player 32, locally only. Copy the oracle-traps
section of the previous session's `BRIEFS_COMMON.md` (history repo) into yours, and the current Flash models from
`graphics-fanout-playbook.md` §<latest>.

## Read first

1. `SWFRecompDocs/plans/PROJECT_STATE.md` and `NO_GO_REGISTER.md` (main repo).
2. Memories: `next-session-dual-axis-fanout`, `shared-index-commit-sweeps-peer-hunks`, `flash-over-ruffle-ruling`,
   `flash-player-oracle`, `parallel-fanout-wave-pattern`, `graphics-fanout-playbook`, `ci-baseline-must-be-read-fresh`,
   `corpus-status-diff-tool`, <model memories for this board>.
3. `SWFRecompDocs/plans/polish-sweep-arc.md` **§<N>** (method notes, trace board) and
   `graphics-fanout-playbook.md` **§<N-2>** (models, flash_fixes table, pixel board).
4. The previous run of record as your TEMPLATE: `SWFRecomp-CC-history:SWFRecompDocs/plans/session<N-1>-fanout-reports/`.
   Copy the shape of `BRIEFS_COMMON.md`, `briefs/` (start the headers from `tools/coord/templates/`), `prompts/`,
   `AGENT_LAUNCH_ORDER.md` and `SIBLING_FILE_MAP.md` into your session dir **in the history repo**.
   s30's `BRIEFS_COMMON.md` predates D3: in your copy, change every "read X in this repo / on origin/master" for a
   session-dir file to the worker's history clone (`/root/history/<path>`), and keep its Delivery rule (commit only
   files under the session dir on `fanout/<slug>`).
5. Tools: `tools/coord/` (above), `scripts/image_status_diff.py --band-floor 0 --max-list 300`, and
   `python3 ruffle-tests/apply_flash_fixes.py --check` (run it in the MAIN tree).

## Baseline (verify before quoting)

<FINAL run ids, SHAs and results commits from the previous closeout; read fresh off origin/ruffle-test-results.>

## Board (ranked; sizes are estimates)

<From polish-sweep-arc.md "Left on the board", graphics-fanout-playbook.md board, PROJECT_STATE.md §2.>

## Local ladders (one task per session)

<Which ladders run, in what order, launched with
`PATH="$PATH:/mnt/c/Windows/System32:/mnt/c/Windows" ~/bin/wsl-launch-claude.sh -m opus -C /home/robert/CC/SWFRecomp-CC -d : -t <slug> -f <brief>`,
then verify `/proc/<pid>/cwd` and send a handshake. Ladder briefs live in the history repo.>

## Landing and grading recipes

- **Land:** `tools/coord/land_branch.sh`, or `git apply --check`, `git apply`, `git apply --check -R`. Append-only files
  (canary list, regression README, RvF, `fixes.json`) are appended by script. Conflicts: `git merge-file` against the
  merge-base, text only. Commit per "Committing in the shared tree". Then archive the branch's report
  (`tools/coord/archive_branch.sh`) and push the history repo.
- **Grade:** merge `origin/ruffle-test-results` after every run; `tools/coord/allrows.py` and diff by name against the
  previous run; `image_status_diff.py`; check every move against the ledgers.
- **Watching runs:** poll `gh run view --json status` in a background loop; never kill a peer's watcher.
- **Recovery:** a shard that fails in setup publishes partial results (hundreds of `pass → None` rows). Run
  `gh run rerun --failed` and grade only the republished commit.

## Done (closeout checklist)

- **Final grading** in both modes, ledger-exact by name, with 0 regressions or each one explained AGAINST FP32.
- **State docs (main repo):** `PROJECT_STATE.md`, `NO_GO_REGISTER.md`, `polish-sweep-arc.md` **§<N+1>**,
  `graphics-fanout-playbook.md` **§<N-1>**.
- **History repo:** the session dir complete (every report, patch, ledger, oracle capture), committed and pushed.
- **Memory:** update `next-session-dual-axis-fanout` and any model memory you moved.
- **Branches:** `fanout/*` pruned after `archive_branch.sh` prints 0 NEW / 0 CHANGED for each.
- **Pages:** a REAL deploy (Deploy step ran) if the wasm/runtime/recompiler changed.

REPORT BACK (after the durable records — never instead of them): once the closeout docs are written, memory updated,
and the commits pushed, reply to the handshake message from the session that launched you (copy its `from` attribute as
your SendMessage `to`). If no handshake arrived, run ListAgents and look for the launching session; if it is not
reachable, skip silently: the closeout docs are the record and need no reader. Send ONLY the deltas: what sN overturned
in this brief (by §), defects your own tests found, anything that changes standing plans or docs, and the s<N+1> line.
