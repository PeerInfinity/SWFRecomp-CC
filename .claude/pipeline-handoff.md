# Pipeline Handoff

When a task ends — finished, blocked, or paused with progress — run the Ruffle test pipeline to commit, push, trigger CI, wait for completion, merge results, and report regressions. Follow this doc end-to-end. Don't stop partway unless you hit an error or merge conflict.

## Build mode

The `ruffle-tests.yml` workflow accepts a `mode` input:

- `graphics` (**per-change default** since 2026-07-23) — full graphics-native run with offscreen Dawn rendering, i.e. the production frame loop (`swf.c`). Durations depend far more on `categories` than on Dawn — see the table in §"running → wait for completion". Result files: `results_graphics.json`, `results_graphics_diff.md`.
- `no-graphics` — trace-only run (`swf_core.c`). ~10 min. Result files: `results.json`, `results_diff.md`. Runs weekly via `weekly-no-graphics.yml` (Sundays 08:00 UTC). Dispatch it per-change ONLY when the change touches no-graphics-only code: `swf_core.c`, `tag_stubs.c`, or `#ifdef NO_GRAPHICS` arms that lack `|| OFFSCREEN_RENDER`. When in doubt for shared runtime code, run both.

All modes push results to the same branch (`ruffle-test-results`) — only the filenames differ. Rationale + reversion criterion: `SWFRecompDocs/plans/mode-consolidation-plan.md` Phase 2 (if the weekly canary ever catches a divergence graphics missed, restore dual per-change runs). Note when reading a red graphics run: the apt/Vulkan shard flakes (see `graphics-ci-aptget-flaky-shards` memory) need triage before being called regressions. (The old `case-v6` flake no longer exists — it was 3 real heap bugs, fixed 2026-05-28 in `d905efdb1`; a case-v6 failure today is a genuine regression.)

### `images` — the image-comparison instrument (opt-in, default off)

`-f images=true` (graphics mode only) turns on a **separate instrument** that
does not affect trace pass/fail. **Leave it off for the per-change pipeline**:
it exists for deliberate render-baseline runs, and with it off every verify
command line, results file and published artifact is exactly what it was.

What it adds:

- `verify_output.py --images` asserts Pillow rather than degrading silently
  (a dedicated preflight step fails the shard job, because the verify calls
  themselves are `|| true`) and records per-comparison magnitude stats.
- `--image-out-dir` exports the actual + difference PNG of **failing**
  comparisons only.
- `scripts/build_image_report.py` writes per-suite
  `_results/image_results_graphics.json`, published on `ruffle-test-results`
  alongside the trace results.
- `scripts/ci/publish_images.sh` force-pushes the failing PNGs plus an
  `index.md` to **`ruffle-image-results`** as a single commit per run. That
  branch is rebuilt from scratch every time — never merge it into master.

Caveats: image comparisons already run in every graphics shard regardless of
this input (they are gated on `mode`); the input controls the *instrument*
around them. Renders are graded on CI's lavapipe software Vulkan — local Dawn
renders are not pixel-identical to it and are advisory only. Baseline and
interpretation: `SWFRecompDocs/plans/graphics-image-baseline.md`.

### WASM link is now CI-observable

Every `ruffle-tests.yml` dispatch (any mode / any `parallel` / with or without `single_test`) also runs a **`wasm-link-smoke`** job that compiles+links one trace-WASM demo (`swf_core.c` path) and one browser-WASM graphics demo (`swf.c` path). A runtime change that breaks either WASM link turns the run red as its own named job. So the old manual smoke ritual (from the `wasm-build-modes-rot-without-ci` memory) is **no longer needed to catch link/compile breakage** — CI catches it. Still run a manual browser smoke for **behavioural** checks (rendering, interactivity), which this job deliberately does NOT do (compile+link only, no execution).

### `single_test` runs no longer publish (2026-07-26)

`-f single_test=NAME` now runs in its own lean **`Single test`** job that builds, runs the one test, and uploads the result JSON as an artifact — it does **not** touch `ruffle-test-results`. Previously it satisfied the publish guard and force-pushed a whole results tree rebuilt from the *master checkout*, so dispatching one before pushing a results merge reverted the branch to its pre-merge state (run `30186909756`). The old "push the merge before dispatching a single-test verify" ordering rule is therefore obsolete. Read the verdict from the `Verify single test` log step.

**A baseline is a COMMIT to diff against, never a number to quote.** The graphics corpus total is intermittent-dependent by ±1 at the same code: `from_shumway/as3-loader/bug1157243/empty` is load-sensitive (early return before the first trace — the `heap_init` 4 GB reserve failing on a loaded 30-way runner), and two graphics runs at identical code gave effective 4371 (`9925cac7c`) and 4372 (`91c7c99f1`) over the same 4497 graded. Separately, `corpus_status_diff.py` reports over the INTERSECTION, so its effective line is not the corpus total whenever a fixture has landed since. Read the baseline off `origin/ruffle-test-results` each time and diff; a number carried forward from a brief or closeout is wrong roughly half the time. See memory `ci-baseline-must-be-read-fresh`.

**`single_test` resolves the bare name against `tests/swfs/avm1` ONLY.** The workflow's `Single test` step passes no `--tests-dir`, and `verify_output.py` defaults `TESTS_DIR` to `tests/swfs/avm1` (:671). Downloading every category makes a `from_gnash` / `from_avmplus` / misc test *present on disk*, but it does not make its bare name **resolve** — the run fails on path lookup and that is **not a verdict on the test**. A slice dispatched one for a `from_shumway` test and nearly read the failure as confirmation of a regression it was investigating (2026-09-04). Until the workflow grows a `tests_dir` input, verify a non-avm1 test locally with `--tests-dir`, or read it out of a full-corpus run. Two behavior notes: it downloads **every** category, and in `mode=graphics` it requires a warm Dawn cache — on a miss it fails fast telling you to run `build-dawn.yml`, rather than building Dawn inline for ~30 min.

### The publish gate is computed, not enumerated (2026-09-02)

Which runs may force-push their numbers to `ruffle-test-results` is decided by
`scripts/ci/publish_gate.py` (step `publish_gate` in `combine-results`), and
both publish steps — results and failing images — are gated on its single
output. It is **fail-closed**: an input whose value differs from the default
declared in `ruffle-tests.yml` blocks publishing unless its name is in that
script's `PUBLISH_SAFE` set (`mode`, `categories`, `parallel`, `images` — the
four that cannot change what a binary does or what a number means).

So **a run that sets any other input publishes nothing**: `extra_defines`,
`swf_gc`, `avm2_gc`, `try_helper`, `tu_split`, `skip_avm1_payload`,
`single_test` — and now also `limit`, which used to publish a TRUNCATED tree
over the baseline. Read such a run's verdict from its log and its uploaded
artifact; never wait for it on the branch.

Adding a new input needs no edit here and no edit to the guard: it is guarded
the moment it is declared. `python3 scripts/ci/publish_gate.py --self-test`
checks the parser and the decision table against the real workflow file.

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
1. `gh workflow run ruffle-tests.yml --ref <branch> -f mode=graphics` — graphics is the per-change mode and the workflow default; pass the flag anyway for explicitness. Dispatch `mode=no-graphics` instead/additionally only per the §"Build mode" rules. Categories: `all` (the default, the classic five suites) for AVM1-side changes; add `-f categories=full` (the complete corpus: all + from_avmplus + the misc group) when the change touches AVM2 runtime/recompiler emission or shared code where AVM2 behavior could shift — see `ruffle-tests/tests/swfs/_investigation/FULL_SUITE_IMPORT_AUDIT.md` §"Which tests run when". Other default inputs (limit=0, parallel=30) are fine unless the user asked for something else.
2. `sleep 3`, then `gh run list --workflow=ruffle-tests.yml --branch=<branch> --limit=1 --json databaseId,status,createdAt`. Take the first entry's `databaseId` as `run_id`. Sanity-check its `createdAt` is within the last ~30 seconds (so you don't pick up a stale run).
3. Save `run_id`, set `stage=running`. Also record the mode you triggered (in-memory; the analyze step needs it to pick the right diff file). Report the run URL: `gh run view <run_id> --json url -q .url`.
4. **Locally sync the Ruffle tests to upstream master** while the workflow runs: `./ruffle-tests/download_tests.sh <categories>` (NO `--clean`). CI re-downloads the tests fresh from `ruffle-rs` master on every run, but the local copy is whatever was last synced — so a stale local tree drifts from what CI actually graded. That drift shows up as **phantom regressions**: a test "passes locally but fails in CI" (or vice versa) purely because upstream changed its `output.txt` (line totals shift, e.g. `17/17 → 16/22`) or added/removed tests — NOT because of your code change. Syncing now means any local re-run (and the analyze step's reasoning) compares against the same test set CI used. Run the categories your run covered — they must match the dispatch:

- `categories=avm1` → `avm1`
- `categories=all` → `avm1 avm2 from_shumway from_gnash`
- `categories=full` → `avm1 avm2 from_avmplus from_shumway from_gnash` plus the nine misc categories (`timeline text swf import_assets audio fonts visual mixed_avm stage3d`)

`./ruffle-tests/download_tests.sh` with no arguments syncs `avm1` only, so always pass the list explicitly. (`--help` prints the accepted names.) (Don't commit the synced test files unless that's the explicit task — the sync is a local consistency step.) Fall through.

### running → wait for completion

**You MUST run `gh run watch` here. Don't skip this step. Don't replace it with Monitor, a polling loop, `sleep`, or anything else.** The tool is specifically designed for this — it blocks until the workflow finishes, which is exactly what this stage needs.

**Exception — the watcher DIED through no fault of yours.** The rule above is about not *choosing* a polling loop; it is not a demand that you resurrect a watcher that cannot survive. Three watcher deaths across three slices (2026-09-03/04): GitHub's **secondary** rate limit killed one while `gh api rate_limit` still reported ~4,800 core requests remaining, and the **OOM killer** took two more under memory pressure from another arc's browser measurements. When the watcher dies for one of those reasons, use one of these and say which:

- **Preferred, costs zero API quota:** poll `git fetch origin ruffle-test-results` and read the run id out of the publish commit message. Note the no-graphics publish commit is titled plain `Update Ruffle test results` with **no** `(mode=...)` suffix.
- A ~150-second `gh run view --json status` loop — much smaller RSS than the watcher and roughly 1/50th the API calls.

Both are *fallbacks after a death*, never a first choice, and neither may run **alongside** a live watcher: one slice tripped the secondary limit doing exactly that, which is the case the prohibition above exists for.

1. Run `gh run watch <run_id> --exit-status` via the Bash tool with `timeout: 600000` (10 minutes, the max). Foreground or background is fine; the command itself does the waiting.
2. When it returns, re-check: `gh run view <run_id> --json status,conclusion -q '.status+" "+(.conclusion//"")'`.
   - `completed success` or `completed failure` → advance (the user wants to see results either way). Set `stage=merging`. Fall through.
     - **A red run has two meanings now.** Since 2026-07-25 the `Combine Results` job fails when any shard is missing, so `completed failure` can mean "a shard was lost", not "tests regressed". Check that job's log for `::error::INCOMPLETE RUN`. The results still publish and carry `metadata.incomplete=true`, and `corpus_status_diff.py` prints a banner naming the short suites — but do not quote an absolute corpus total from a flagged run. Recover with `gh run rerun <run_id> --failed`.
   - `completed cancelled` (or other completed-but-non-terminal state) → report and stop at `stage=running`.
   - Not yet completed (Bash timed out at 10 min) → **`kill <PIDs>` first** — the concurrent-watcher guard's deny message prints the offending PIDs, so kill those literal numbers — then re-run `gh run watch` with the same parameters. (Do NOT use `pkill -f "gh run watch"`: the `block-pattern-kill.sh` PreToolUse guard has denied pattern kills since 2026-08-16, so the pattern form documented here until 2026-09-04 could not be executed at all. A kill by literal PID passes. Harvesting PIDs from `pgrep`/`ps` into a kill is also denied — read them off the guard's own message.) A timed-out Bash call is not dead — the harness moves it to the background, where it keeps polling; re-invoking without killing it stacks watchers. `gh run watch` polls every ~3s and each poll fetches the full job list, so on a 30-shard run each live watcher costs ~1,200 requests/hour against the **5,000/hr GitHub API quota that is shared by every tool and agent in the session**. Three stacked watchers exhausted it on run `30134726316` and 403'd every `gh` call for 17 minutes. For the same reason, don't interleave `gh run view --json jobs` status polls with an active watcher. (If the quota is already gone: `gh api rate_limit --jq .resources.core` gives the reset epoch — wait it out, the CI run itself is unaffected.) **Expected durations** (measured, not estimated — the corpus nearly doubled with the 2026-07-24 full-suite import, so older figures in this doc were wrong):

| Dispatch | Wall clock | Notes |
|---|---|---|
| `categories=all`, graphics, Dawn cache hit | ~10-15 min | the classic five suites |
| `categories=full`, graphics, Dawn cache hit | **~33 min** | measured on run `30134726316`: 6 min Setup + ~26 min of 30-wide sharding. This is *test volume*, not a Dawn rebuild — do not mistake it for a cache miss |
| any graphics mode, Dawn cache **miss** | add ~25 min | a rebuild is triggered when `scripts/build_dawn.sh`'s hash changes |
| `no-graphics` | ~10 min | |

So plan for up to **two** `gh run watch` calls for `categories=all`, and up to **four** for `categories=full` (or `full` + a Dawn rebuild), before declaring it stuck.

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
   Read those for the per-test pass/fail delta — but they are **not sufficient on their own**; see step 2.

2. **Run `scripts/corpus_status_diff.py <pre_merge_sha> WORKTREE --per-suite`.** It does everything in this step for you — histogram, intersection, per-suite deltas, ungraded-shard detection — and exits non-zero if anything regressed. Use `--stem results` for a no-graphics run. The rest of this step explains *why* it does what it does; read it before hand-rolling an alternative.

   **Diff the STATUS HISTOGRAM, not just pass→fail transitions.** A `_diff.md` shows tests that crossed the pass/fail line. A test that was *already failing* and starts **segfaulting** crosses no line and appears nowhere — that is how a change once introduced 12 new segfaults while the diff honestly reported "zero regressions". Compare `collections.Counter(t['status'] for t in results['tests'])` between the two commits and treat any rise in `segfault` / `timeout` / `runtime_error` / `compile_fail` as a regression to chase, even at a constant effective-pass count.

   **Compare on the INTERSECTION of tests present in both runs.** If either endpoint lost a shard to the apt/Vulkan flake, the missing tests reappear in the other run and a naive diff scores every one of them as "newly passing". Bucket keys missing from the baseline separately as *shard recovery* — never as yield — and say how many tests went ungraded. A per-suite `total` that moved between runs (e.g. 1522 vs 1574) is the tell.

   **The corpus denominator is 4414, not 4463.** Three nested `_results` dirs are already inside their parents and must not be added again: `from_shumway/avm1`, `from_shumway/timeline`, `from_gnash/misc-ming.all/displaylist_depths`. Sum top-level leaf suites only.

3. **Cover every suite the dispatch actually ran** — 19 top-level leaf suites exist, not the three this doc used to list. For `categories=full` that is: `avm1`, `avm2`, `from_avmplus`, `from_shumway`, the five `from_gnash/*`, `regression`, and the nine misc categories (`timeline`, `text`, `swf`, `import_assets`, `audio`, `fonts`, `visual`, `mixed_avm`, `stage3d`). Summarize each; call out **regressions** by name — those are the load-bearing signal. Omitting `avm2` / `from_avmplus` would have hidden the entire yield of the AVM2 arcs. **Before blaming your change for any single-test regression, rule out upstream drift** (you synced the tests in the trigger stage): if the reported delta is a line-total shift (`N/N → M/K` with a changed denominator) or an added/removed test, re-run that test locally (`verify_output.py --test=<name> --diff`) against the now-synced tree. If it passes locally, the CI "regression" is upstream having changed that test's `output.txt`, not your code — note it as drift and don't chase it.
4. If any suite's `_investigation/CURRENT_STATUS.md` is affected, skim it for context and update it with the confirmed numbers.
5. Set `stage=done`. Report findings in the final message, naming the mode that ran and the run ID.

## Error handling

Any shell failure: leave `stage` unchanged, report the error, stop. Don't silently advance. Don't retry without thinking about why it failed.

## Gitignore

`.pipeline-state` must be gitignored. If it's tracked, add it to `.gitignore` before proceeding.
