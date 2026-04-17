---
description: Drive the Ruffle test pipeline one step at a time (commit → push → trigger → wait → merge → analyze).
---

# Pipeline driver

Arguments: `$ARGUMENTS`

Drive the Ruffle test workflow loop. State is persisted in `.pipeline-state` (JSON) at the repo root so the pipeline survives across `/pipeline` invocations. The state file is gitignored.

## State file

Path: `.pipeline-state`

Shape (compact JSON, one line):

```json
{"stage":"idle","auto":false,"run_id":null,"branch":null}
```

- `stage` — one of: `idle`, `committed`, `pushed`, `running`, `merging`, `analyzing`, `done`
- `auto` — boolean. When `true`, after finishing a stage, immediately run the next stage instead of stopping. The only stage that never auto-advances is `pushed → running` — the workflow takes ~10 min and should be polled manually (or watched explicitly).
- `run_id` — GitHub Actions run ID captured at trigger time, or `null`
- `branch` — branch name captured at push time, or `null`

If `.pipeline-state` doesn't exist, treat it as `{"stage":"idle","auto":false,"run_id":null,"branch":null}` and create it.

Always read the state file with the Read tool at the start of every invocation, and write it back (compact, one line) with the Write tool whenever you change a field. Preserve `auto` across resets.

## Subcommands

Parse the first token of `$ARGUMENTS`:

- empty or `next` → **advance one stage** (see below)
- `status` → print the state file contents and a one-line description of the current stage. Stop.
- `auto on` / `auto off` → set `auto` to true/false, save state. Stop.
- `reset` → overwrite state with `{"stage":"idle","auto":<preserved>,"run_id":null,"branch":null}`. Stop.

If the arg is anything else, print the usage and stop.

## Advancing one stage

Read state. Dispatch on `stage`:

### idle → commit
1. Check `git status` and `git diff` (staged + unstaged). If there's nothing to commit, skip straight to setting `stage=committed` and proceed (or stop, per auto).
2. Otherwise, follow the repo's normal commit conventions (see recent `git log`). Stage relevant files (avoid `git add -A`). Create the commit with the standard Co-Authored-By trailer.
3. On success, set `stage=committed`. If `auto`, continue to the next stage. Otherwise stop with: `Committed. Run /pipeline next to push (or /pipeline auto on to chain).`

### committed → push
1. Run `git rev-parse --abbrev-ref HEAD` to capture the current branch into `state.branch`.
2. Run `git push` (add `-u origin <branch>` if the branch has no upstream).
3. On success, set `stage=pushed`, save `branch`. If `auto`, continue. Otherwise stop.

### pushed → trigger workflow
1. Run `gh workflow run ruffle-tests.yml --ref <state.branch>`. Default inputs (categories=all, limit=0, parallel=30) are fine; don't pass `-f` flags unless the user asked for different inputs.
2. Briefly wait (e.g. `sleep 3`) then query the run ID: `gh run list --workflow=ruffle-tests.yml --branch=<state.branch> --limit=1 --json databaseId,status,createdAt`. Take the first entry's `databaseId`. Double-check its `createdAt` is within the last ~30 seconds so you don't pick up a stale run.
3. Save `run_id`, set `stage=running`. Report the run URL (`gh run view <run_id> --json url -q .url`). **Never auto-advance past this point** — the run takes ~10 min. Always stop here regardless of `auto`, telling the user: `Workflow running. Run /pipeline next to check status.`

### running → check workflow / wait
1. Query: `gh run view <run_id> --json status,conclusion,url -q '.status+" "+(.conclusion//"")+" "+.url'`.
2. If `status` is not `completed`:
   - In manual mode: report current status and URL, stop. Do not advance.
   - In `auto` mode: run `gh run watch <run_id> --exit-status` with a ~9 minute Bash timeout (`timeout: 540000`). If it returns, re-check status via `gh run view`. If still not completed (timed out), stop and ask the user to run `/pipeline next` again.
3. If `status=completed` and `conclusion=success` (or `failure` — still advance, user will want to see results either way): set `stage=merging`. If `auto`, continue to the merge stage. Otherwise stop and tell the user: `Workflow finished (conclusion: <X>). Run /pipeline next to merge the test results.`
4. If `conclusion` is `cancelled` or other non-terminal-but-completed state: report it and leave stage at `running` so the user can decide what to do.

### merging → merge test results
The workflow force-pushes results to `origin/ruffle-test-results`. Merge that branch into the current branch automatically — this replaces the manual `./CC/scripts/interactive-branch-merge.sh` step.

1. Record the current HEAD: `git rev-parse HEAD` → `pre_merge_sha`. Keep this in-memory for the analyze step (no need to persist to state).
2. `git fetch origin ruffle-test-results`
3. `git merge origin/ruffle-test-results --no-edit`
   - If the merge succeeds (clean or with an auto-generated merge commit): proceed.
   - If it reports "Already up to date": that's fine — no new results to merge. Note this and proceed; there won't be a diff to analyze.
   - If it reports a conflict: **stop**. Do not attempt to resolve automatically. Run `git merge --abort` to leave the tree clean, set `stage=merging` (unchanged), and tell the user: `Merge conflict in test results — resolve manually, commit, then /pipeline next to analyze.` In auto mode, a conflict also breaks the chain.
4. On success, set `stage=analyzing`. If `auto`, continue to the analyze stage. Otherwise stop.

### analyzing → analyze
1. Diff test results against `pre_merge_sha` (from the merging step). If that SHA isn't available in-memory (e.g. the user ran `/pipeline next` in a fresh session after manual conflict resolution), fall back to `git diff HEAD~1 -- 'ruffle-tests/tests/swfs/*/results.json'`, or a wider range if `git log --oneline -5` shows multiple recent merges.
2. Summarize: per suite (avm1, from_gnash, from_shumway), how many tests moved pass↔fail. Call out any **regressions** (pass→fail) by name — those are the important ones.
3. Also glance at `ruffle-tests/tests/swfs/{avm1,from_gnash,from_shumway}/_investigation/CURRENT_STATUS.md` if it exists and may be affected by the regressions.
4. Set `stage=done`. Report findings. Tell the user: `Analysis complete. Run /pipeline next to start a new cycle.`

### done → idle
If the user runs `/pipeline next` from `done`, just reset to `idle` and proceed with the `idle → commit` behavior (convenient for chaining cycles).

## Error handling

If any shell command fails, leave the stage field unchanged, report the error, and stop. Don't silently advance. In `auto` mode, a failure breaks the chain — do NOT keep going.

## First run

If `.pipeline-state` doesn't exist, create it with the default shape above before doing anything else, then proceed with `idle → commit`.

## Gitignore

`.pipeline-state` must be gitignored. If you ever notice it's being tracked by git, add it to `.gitignore` before proceeding.
