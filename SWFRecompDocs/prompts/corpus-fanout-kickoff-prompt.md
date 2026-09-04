# Corpus fan-out: remaining trace and graphics test failures

You are the **coordinator** for a Ruffle-test corpus fan-out wave. The method is
the standing one and is already written down — [[parallel-fanout-wave-pattern]]
and [[graphics-fanout-playbook]] (subagents in worktrees, serial merge, CI,
results merge, closeout). **Follow those; do not re-derive them, and do not
implement the slices yourself.** Subagents go on Opus
([[fable-budget-delegate-to-opus]]).

**Baseline — `master` at `8f94d048f`:**
- Trace: **4373 effective (graphics) / 4374 (no-graphics), 4498 graded**; results
  commits `f00041501` (graphics) and `53141b979` (no-graphics).
- Pixels: **364/572 (63.6%)** at `659153865`
  (`SWFRecompDocs/plans/graphics-image-baseline.md`).

**Read the baseline off `origin/ruffle-test-results` yourself and diff against
those commits — never quote a number forward from a brief or closeout.** The
graphics total is intermittent-dependent by ±1 at the same code, and a
`corpus_status_diff.py` intersection is not the corpus total; both mechanisms are
in [[ci-baseline-must-be-read-fresh]].

## Start here, before any triage

**1. Fresh test download.** `bash ruffle-tests/download_tests.sh` (add category
names to narrow it; `ALL_CATEGORIES` is in the script). **Never pass `--clean`
locally — it removes existing test directories and would wipe `_investigation/`
and `_results/`**, which are this project's own work and are not recoverable
from upstream. The suite tracks upstream `master` unpinned, so expect drift:
a changed expected-line total or a new test dir is upstream movement, not a
regression ([[ruffle-test-download-sync]]).

**2. Update `~/CC/ruffle`, keeping our edits.** It is **119 commits behind**
upstream and its working tree is **dirty with changes we added** — currently
`exporter/{Cargo.toml,src/cli.rs,src/exporter.rs,src/lib.rs,src/main.rs}`,
`core/src/tag_utils.rs`, `render/wgpu/Cargo.toml` and `Cargo.lock`. Those are
ours and **must survive**. `git pull --ff-only` will refuse against a dirty tree,
so: save them first (`git -C ~/CC/ruffle diff > <patch>`, plus `git diff
--staged` if anything is staged — the memory notes there have been staged edits
in `exporter/`), then pull, then re-apply and **verify the re-apply actually
succeeded** rather than assuming. If a hunk conflicts against 119 commits of
drift, stop and report it — do not resolve it by dropping our change.

That clone is the tool for inspecting upstream behaviour; the user prefers it
over `gh api`/GitHub. Note it can *lag the downloaded tests*, so when local
Ruffle source seems to contradict a freshly downloaded `output.txt`, pull first
and check `raw.githubusercontent.com/.../master/...` before concluding.

## The work

Remaining trace and graphics failures. Both axes are open; pick the boards from
the current failure inventory rather than from any older arc doc's §-list, since
the corpus has moved. Useful standing context: `runtime-error` is the cheapest
triage axis; check `ACCEPTED_DIFFS.md` / `RUFFLE_VS_FLASH_DIFFERENCES.md` /
`RUFFLE_COMPAT_TWEAKS.md` / `FLASH_BUGS_REPLICATED.md` **before** implementing
anything, since a "failure" may already be an adjudicated permanent diff
([[triage-check-accepted-diffs-first]]); and a pass→`ruffle_matched` move on a
known_failure is a regression, not a win ([[ruffle-matched-hides-regression]]).

## Housekeeping you should know about

- **`.claude/worktrees/` is empty by design.** 64 stale agent worktrees (19 GB)
  were audited and reclaimed on 2026-09-04 — adjudication in
  `SWFRecompDocs/status/worktree-unlanded-work-audit-2026-09-04.md`. Your wave
  will create its own; **clean them up at closeout** so this does not recur.
- **Never merge `t5-iso-v1`.** It reads as "+2 ahead of master" but is a
  subtractive A/B bisect variant (2 insertions / 39 deletions) that strips
  `URLRequestHeader`, which master has in full. Landing it is a regression.
- `git stash` is shared across this repo's worktrees — use patch files
  (`git diff -- <dir> > p.patch; git apply -R p.patch`) for byte-identity checks.
- Pattern kills are guard-denied, as is a `pgrep`/`ps` harvest piped into `kill`;
  use literal PIDs ([[pkill-f-self-match]]).
- CI: dispatch the two modes **serially** — overlapping combine-results jobs can
  clobber each other's stem — and if `gh run watch` dies (it has, from four
  distinct causes across five slices), the zero-quota fallback is documented in
  `.claude/pipeline-handoff.md`.

**Report to the user**, not to the session that launched you — it is stopping and
will not be supervising this wave.
