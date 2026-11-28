# tools/coord: fan-out coordinator tools

Stable home of the corpus fan-out coordinator's tools (repo-cleanup S1, 2026-11-28). Sessions 25–30 copied them into
each session's report dir; the last copy is `SWFRecomp-CC-history:SWFRecompDocs/plans/session30-fanout-reports/coord-tools/`.
Use these and don't copy them anymore. Fix a tool here, in one place.

**Where things go (decision D3):** fan-out reports, briefs, ledgers and oracle captures are committed to the public
history repo `PeerInfinity/SWFRecomp-CC-history` (checkout `~/CC/SWFRecomp-CC-history`) at
`SWFRecompDocs/plans/sessionN-fanout-reports/`. The main repo gets code, fixtures and the durable state docs only.
Start a coordinator brief from [`COORDINATOR_BRIEF_TEMPLATE.md`](COORDINATOR_BRIEF_TEMPLATE.md) and the worker
headers from [`templates/`](templates/).

| Tool | Use |
|---|---|
| `land_branch.sh <branch> <scratch>` | 3-way land a `fanout/<slug>` branch's `SWFModernRuntime/`, `SWFRecomp/`, `ruffle-tests/` changes into the shared tree: text via `git merge-file`, `fixes.json` as a JSON union, binaries copied. Refuses peer-dirty files. `--help`. |
| `archive_branch.sh [-n] <branch> <report dir>` | Copy the branch's report files (NEW or CHANGED blobs under `<report dir>`) into the history checkout (`$HISTORY`, default `../SWFRecomp-CC-history`). Also the closeout "cmp every blob" check before pruning `fanout/*`: prune when it prints 0 NEW / 0 CHANGED. `--help`. |
| `watch_reports.sh` | `SP=<scratch> REPORT_DIR=SWFRecompDocs/plans/sessionN-fanout-reports`, with `$SP/slugs` (one per line) and `$SP/delivered`. Exits printing the slug(s) whose `fanout/<slug>` carries a final report (not "interim", no placeholders, plus `<slug>.patch` for w2/w3). Run with `run_in_background`; re-launch after each delivery. `--help`. |
| `allrows.py <ref> <stem>` | Every `suite/test → status` of one results commit as JSON (stem `results_graphics` or `results`). |
| `status_moves.py <old_ref> <new_ref>` | Per-test status moves between two results commits (graphics stem `results_graphics.json`). `corpus_status_diff.py` prints only the histogram; this names the tests. |
| `status_moves_ng.py <old_ref> <new_ref>` | The same for the no-graphics stem (`results.json`). |

Delivery path: a cloud worker can push only to `PeerInfinity/SWFRecomp-CC`, so it writes its report on its scratch
branch `fanout/<slug>` at the history-repo path (`SWFRecompDocs/plans/sessionN-fanout-reports/<slug>-report.md`). The
branch is never merged: `land_branch.sh` lands the code and `archive_branch.sh` copies the report 1:1 into the
history repo. Workers read briefs by cloning the history repo (`templates/_w1_header.txt`).
