# Session 23: corpus fan-out (dual-axis #15), common brief. ALL WORKERS READ THIS FIRST.

**Session mode: CLOUD-FIRST (user directive 2026-10-16, re-confirmed 2026-11-21).** Every step that can run in the cloud
does, so the user's local machine stays idle. All wave-1 diagnosis slots and wave-2 implementation
slots are Claude Code **cloud sessions** in the "SWFRecomp fan-out" environment. The coordinator
stays local only to merge, dispatch CI, and run the few things that exist only locally (the Ruffle
exporter oracle, our local Ruffle exporter edits, a Windows real-GPU browser probe). Everyone runs
on **Opus**. Procedure of record: `SWFRecompDocs/plans/graphics-fanout-playbook.md` §5a.

Be efficient: no full suites, no idle polling, no re-diagnosing what a prior report already proved.
The weekly and 5-hour Opus limits are the real risk this session.

## Your box

You have the box to yourself: Ubuntu 24.04, 4 CPU, 15 GB RAM, root. The environment's setup script
already installed the apt deps, Pillow and the prebuilt Dawn (`/root/CC/dawn-install`, symlinked as
`/home/user/dawn-install` so `verify_output.py`'s default resolves). Check `cat $HOME/CC/SETUP_STATUS`
first; if Dawn or apt says FAILED, say so in your report and do no-graphics work only. **Never
download Dawn or other binaries yourself**: the setup script is the sanctioned path.

Graphics mode in the cloud runs Dawn on mesa **lavapipe**, the same rasterizer family CI grades on.
Local Dawn renders on the user's box are NOT CI-identical; yours may be. Before you trust an
absolute verdict against a golden PNG, prove fidelity on one row: your *before* render must be
byte-identical to CI's actual PNG for that row (`git fetch origin ruffle-image-results`; the branch
holds the failing actual PNGs from the last images run). If it is, local grading is CI-grade for
that row. Otherwise only A/B (before vs after, md5) is valid.

## Setup (every worker, in this order)

```bash
cd <repo root>                                 # the cloud clone of PeerInfinity/SWFRecomp-CC
git fetch origin && git checkout -B fanout/<your-slug> origin/master
cat $HOME/CC/SETUP_STATUS
(cd SWFRecomp && mkdir -p build && cd build && cmake .. >/dev/null && cmake --build . -j4)
ruffle-tests/download_tests.sh <only the categories you need>   # NEVER --clean
export SWFRECOMP_COMPILE_TIMEOUT=2400
```

Only the `regression` suite is in git; everything else comes from `download_tests.sh` (upstream
Ruffle master at the time you run it; note the upstream SHA it reports in your report).

**Ruffle source**: there is no `~/CC/ruffle` in the cloud. Clone it yourself:
`git clone --filter=blob:none https://github.com/ruffle-rs/ruffle /root/ruffle` (blobless keeps
history, so `git -C /root/ruffle diff 45366370e 0ddd12b6a -- <path>` and `git log` work). Session 22
synced to **`45366370e`** (2026-10-16); upstream master on 2026-11-21 is **`0ddd12b6a`** (297 commits later).
The coordinator's local Ruffle checkout and exporter oracle are still at `45366370e`.
Read source with `grep`/`sed`; do not build Ruffle (it takes far too long on 4 CPUs).

**No Ruffle exporter oracle in the cloud.** If your diagnosis needs a fresh Ruffle exporter run (a
trace or a render from current Ruffle), write the exact request in a `## LOCAL ORACLE REQUESTS`
section of your report (SWF path, frames, what you need from it). The coordinator runs it locally
and archives the output for the wave-2 worker. Do not block on it: finish everything else.

## Baseline — read fresh at session start 2026-11-21 (verify before implementing anything)

- **Code since s22's final grading run (`38cf9b1a0`)**: `aaf953dff` (new fixture
  `regression/avm1_closure_method_scope`), `c1fa89bc2` (AVM2 per-call activation vtables free the old
  entries array on growth, a leak fix), `0cb5464e5` (browser-only AudioWorklet), `08709f658` (CI runners pinned to
  `ubuntu-24.04`: `ubuntu-latest` moved to 26.04, which has no `swfmill` and a newer mesa). Nothing else
  corpus-relevant.
- **s22 final numbers** (do not quote forward; read them): trace **4502 eff / 4562** in both modes, per-test
  identical; pixels **490 / 587** (images run `38995363802`). Arc `polish-sweep-arc.md` §23, playbook §21.
- **Fresh baseline runs are in flight** at `08709f658` against upstream `0ddd12b6a`: graphics/full/images
  run `44922638965` and no-graphics/full run `44922646202`. Their results land on `origin/ruffle-test-results`
  (merged to master by the coordinator) and `origin/ruffle-image-results` (failing PNGs, force-pushed). If
  your branch's `_results` predate them, `git fetch origin ruffle-test-results ruffle-image-results` and read
  those refs. Read numbers with `python3 scripts/corpus_status_diff.py <old_ref> <new_ref> --stem results_graphics`.
  **Never quote a total from a brief or closeout; read it.**
- **Upstream drift 45366370e..0ddd12b6a**: `wave0-upstream-drift-namestatus.txt` (this dir): 397 added, 2178
  modified, 7 deleted files under `tests/tests/swfs`. 2095 of the modifications are one mechanical commit,
  `f0aa96e0c` "Use num_ticks instead of num_frames where equivalent"; `verify_output.py`'s `get_num_frames`
  already falls back to `num_ticks`. Drift pricing is owned by the `w1-drift-*` slots; everyone else, just
  re-verify your own rows live and name any drift you hit.
- Boards of record: trace `SWFRecompDocs/plans/polish-sweep-arc.md` **§23.4**, pixels
  `SWFRecompDocs/plans/graphics-fanout-playbook.md` **§21** ("Left on the board (session 23)").
  Prior diagnosis of record: `SWFRecompDocs/plans/session22-fanout-reports/` (and s21/s20/…). s22's pixel
  board file `session22-fanout-reports/wave0-image-board.md` is the 433-era board; the s22 final reports
  supersede it. **Read the prior report for your family before starting, and grep the arc doc and playbook
  for a STRIKE / CAPPED / NO-GO on your family.**

## Standing rules (all workers)

1. **ATTACK YOUR OWN BRIEF'S PREMISES.** Refutations have been the highest-value wave-1 output for
   eight sessions running. A well-evidenced refutation is a first-class deliverable. Attack your
   PRICING too: a diff-line lead is not a flip lead.
2. **Check dispositions BEFORE treating a diff as fixable**:
   `ruffle-tests/tests/swfs/avm1/_investigation/{ACCEPTED_DIFFS,RUFFLE_VS_FLASH_DIFFERENCES,RUFFLE_COMPAT_TWEAKS,FLASH_BUGS_REPLICATED}.md`
   (other suites have their own `_investigation/`), `ruffle-tests/ignored_tests.txt` and per-suite
   `ignored_tests.txt`. For pixels: the playbook's image-axis dispositions. **An ignore entry is a
   CLAIM to re-test, not a verdict.**
3. **Flash over Ruffle (user ruling).** `output.txt` is Flash's output. When Flash and Ruffle
   disagree, match FLASH; never trade a Flash-correct pass for a Ruffle match.
   `known_failure = true` in `test.toml` means Ruffle itself fails it, so a `pass → ruffle_matched`
   move on such a test is a **REGRESSION**. Check `output.ruffle.txt`. An "ours-only line" on a
   misaligned row must be checked by CONTENT against the same block in Flash's file.
4. **`runtime_error` is the cheapest triage axis**: a crash names its own mechanism.
5. **NEVER run full suites.** Single tests only, at most `-P 2`:
   `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/<suite> --test=NAME [--mode=graphics] --diff --verbose`.
   Bare names resolve against `avm1` ONLY. CI grades `--mode=graphics`. Always `--verbose`. A short
   argued sweep (≤ ~40 tests) is fine; scope by argument, not by volume.
6. **No pushes except your own `fanout/<your-slug>` branch.** Never push to master or any other
   branch (the user approved scratch-branch delivery for cloud workers only). Never force-push.
7. Background jobs: run in the foreground, or ONE `wait`/`until` on a captured PID. Never end your
   turn waiting on a job: nothing will re-invoke you.
8. Upstream drift: a changed expected-line total, or a test absent from `_results/results_graphics.json`,
   is upstream movement, not a regression. Name it; never book drift as yield. A pixel pass→fail
   whose `max_diff` is unchanged while only `outliers` moves is tolerance drift until proven otherwise.
9. Report format: lead with **GO/NO-GO verdicts and priced flips (test names)**, then mechanism
   (owner `file:line`), evidence, refutations, and (wave 2) exact patch scope plus per-test
   before/after. **Every HOLD/NO-GO names its completion mechanism.** Close with a
   "New unclaimed leads" section, then `## LOCAL ORACLE REQUESTS` (or "none").

## Delivery (every worker; the report on the branch is the ONLY deliverable that counts)

`get_run_log` truncates long messages, so the coordinator reads your BRANCH, not your chat.

1. Write `SWFRecompDocs/plans/session23-fanout-reports/<your-slug>-report.md`.
2. Wave 1 (diagnosis): source edits are allowed only as a measured PROTOTYPE; deliver it as
   `<your-slug>-prototype.patch` (`git diff origin/master -- <source dirs>`) and then revert the
   source files so your commit holds only files under `session23-fanout-reports/`.
   Wave 2 (implementation): commit your source changes AND
   `<your-slug>.patch` = `git diff origin/master -- <source dirs> ruffle-tests/render_canary_tests.txt`
   (plus any new fixture dirs). List every NEW file at the top of the report.
3. Delete stray generated files first: `output.actual.png`, `Recompiled*` dirs inside git-tracked
   test dirs, `_results/` edits (`git status --short` must show only your intended files).
4. `git add <files by name>` (never `-A`), commit, `git push -u origin fanout/<your-slug>`.
   A NO-GO pushes its report too. Push once at the end; an interim push of a partial report is fine
   if you are about to run something long.

## Wave-2 additional rules

- Build/run headline tests BEFORE (clean origin/master) and AFTER. Use `git diff > p.patch` +
  `git apply -R p.patch` for A/B legs (no stash needed, but no harm on your own box).
- Graphics canary: `ruffle-tests/render_canary.py` capture/compare over `render_canary_tests.txt`
  (`--timeout 5400`). Renders are byte-deterministic, so the bar is **md5 identity** outside your
  own ledger. New pipelines in `render_webgpu.c` must use `MSAA_SAMPLES`, never a literal 4. If the
  standing canary set cannot see your change class, append a covering member at EOF.
- **ALWAYS include a `regression`-suite check** near your change
  (`--tests-dir=ruffle-tests/tests/swfs/regression`). A new behaviour with no corpus test gets a
  `regression/` fixture whose expected output comes from an oracle OUTSIDE SWFRecomp (Ruffle exporter
  or Flash) — if you can't get one in the cloud, put it under LOCAL ORACLE REQUESTS.
- Self-localize edits (wrapper functions, trailing struct fields, `static` symbols); your brief
  lists which files siblings are editing. New `.c`/`.h` files must be added to `verify_output.py`'s
  source list, CMakeLists **and** the Emscripten build, or live inside an existing TU.
- Recompiler (`SWFRecomp/`) changes: rebuild and pass `--recompile` on the tests you run.
- Mode parity: if you touch `swf_core.c`, `tag_stubs.c`, or `#ifdef NO_GRAPHICS` arms, also run
  your headline tests without `--mode=graphics`.
