# Pipeline Handoff

When a task ends — finished, blocked, or paused with progress — run the Ruffle test pipeline to commit, push, trigger CI, wait for completion, merge results, and report regressions. Follow this doc end-to-end. Don't stop partway unless you hit an error or merge conflict.

## Build mode

The `ruffle-tests.yml` workflow accepts a `mode` input. Match the mode to whatever the user's work targets:

- `no-graphics` (default) — trace-only run. ~10 min. Result files: `results.json`, `results_diff.md`.
- `graphics` — full graphics-native run with offscreen Dawn rendering. ~6 min on Dawn cache hit, ~30 min on cache miss (first run for a script_hash). Result files: `results_graphics.json`, `results_graphics_diff.md`.
- `graphics-headless-legacy` — older NO_GRAPHICS + HEADLESS_GRAPHICS hybrid. Result files: `results_headless.json`, `results_headless_diff.md`.

All modes push results to the same branch (`ruffle-test-results`) — only the filenames differ. Default to no-graphics unless the user's changes touch graphics code (renderer, video, tag-render paths, etc.) or the user asks otherwise.

## State file

Path: `.pipeline-state` (gitignored). Compact JSON, one line:

```json
{"stage":"idle","run_id":null,"branch":null}
```

- `stage` — `idle`, `committed`, `pushed`, `running`, `merging`, `analyzing`, or `done`
- `run_id` — GitHub Actions run ID, set at trigger time
- `branch` — branch name, set at push time

If the file doesn't exist, treat it as `{"stage":"idle","run_id":null,"branch":null}`. If it exists with `stage != idle` and `stage != done`, **resume from that stage** (useful if a prior session died mid-pipeline).

Read it with the Read tool at the start; write it back with the Write tool on every stage advance.

## Procedure

Dispatch by current `stage`. After each stage completes, fall through to the next; don't stop unless the stage instructions say so.

### idle → commit
1. Check `git status` and `git diff`. If nothing to commit, set `stage=committed` and fall through.
2. Otherwise stage relevant files by name (avoid `git add -A` — don't sweep secrets or build artifacts). Follow recent `git log` conventions for the message. Include the standard Co-Authored-By trailer.
3. Set `stage=committed`. Fall through.

### committed → push
1. `git rev-parse --abbrev-ref HEAD` → record as `branch`.
2. `git push` (add `-u origin <branch>` if no upstream).
3. Set `stage=pushed`, save `branch`. Fall through.

### pushed → trigger
1. `gh workflow run ruffle-tests.yml --ref <branch> [-f mode=<mode>]`. Add `-f mode=graphics` (or `-f mode=graphics-headless-legacy`) if the task targeted graphics rendering; default `mode=no-graphics` otherwise. Other default inputs (categories=all, limit=0, parallel=30) are fine unless the user asked for something else.
2. `sleep 3`, then `gh run list --workflow=ruffle-tests.yml --branch=<branch> --limit=1 --json databaseId,status,createdAt`. Take the first entry's `databaseId` as `run_id`. Sanity-check its `createdAt` is within the last ~30 seconds (so you don't pick up a stale run).
3. Save `run_id`, set `stage=running`. Also record the mode you triggered (in-memory; the analyze step needs it to pick the right diff file). Report the run URL: `gh run view <run_id> --json url -q .url`. Fall through.

### running → wait for completion

**You MUST run `gh run watch` here. Don't skip this step. Don't replace it with Monitor, a polling loop, `sleep`, or anything else.** The tool is specifically designed for this — it blocks until the workflow finishes, which is exactly what this stage needs.

1. Run `gh run watch <run_id> --exit-status` via the Bash tool with `timeout: 600000` (10 minutes, the max). Foreground or background is fine; the command itself does the waiting.
2. When it returns, re-check: `gh run view <run_id> --json status,conclusion -q '.status+" "+(.conclusion//"")'`.
   - `completed success` or `completed failure` → advance (the user wants to see results either way). Set `stage=merging`. Fall through.
   - `completed cancelled` (or other completed-but-non-terminal state) → report and stop at `stage=running`.
   - Not yet completed (Bash timed out at 10 min) → re-run `gh run watch` with the same parameters. No-graphics runs typically finish in ~10 min, so one or two calls is enough. Graphics runs finish in ~6 min on Dawn cache hit but can take up to ~30 min on cache miss (a Dawn rebuild is triggered when `scripts/build_dawn.sh`'s hash changes); plan for up to **four** consecutive `gh run watch` calls in that case before declaring it stuck.

### merging → merge test results
The workflow force-pushes results to `origin/ruffle-test-results`. Merge that branch into the current branch.

1. `git rev-parse HEAD` → keep as `pre_merge_sha` in-memory for the analyze step (no need to persist).
2. `git fetch origin ruffle-test-results`
3. `git merge origin/ruffle-test-results --no-edit`
   - Clean merge (or auto-generated merge commit): proceed.
   - `Already up to date`: fine, note it and proceed; no new results to diff.
   - Conflict: `git merge --abort`, leave `stage=merging`, tell the user `Merge conflict in test results — resolve manually, commit, then re-run the pipeline.` Stop.
4. Set `stage=analyzing`. Fall through.

### analyzing → analyze
1. Diff result JSONs against `pre_merge_sha`. Each suite maintains its own `_results/<stem>_diff.md` where `<stem>` matches the mode:
   - `no-graphics` → `results_diff.md`
   - `graphics` → `results_graphics_diff.md`
   - `graphics-headless-legacy` → `results_headless_diff.md`
   Read those — they already have the pass/fail delta table you need.
2. For each suite (avm1, from_gnash/*, from_shumway/*): summarize. Call out **regressions** (pass→fail) by name — those are the load-bearing signal.
3. If any suite's `_investigation/CURRENT_STATUS.md` is affected, skim it for context.
4. Set `stage=done`. Report findings in the final message, naming the mode that ran.

## Error handling

Any shell failure: leave `stage` unchanged, report the error, stop. Don't silently advance. Don't retry without thinking about why it failed.

## Gitignore

`.pipeline-state` must be gitignored. If it's tracked, add it to `.gitignore` before proceeding.
