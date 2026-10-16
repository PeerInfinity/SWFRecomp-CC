# Session 22: corpus fan-out (dual-axis #14), common brief. ALL WORKERS READ THIS FIRST.

**Session mode: CLOUD-FIRST (user directive, 2026-10-16).** Every step that can run in the cloud
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
history, so `git -C /root/ruffle diff 0dacba55f 45366370e -- <path>` and `git log` work). The
coordinator synced its local copy to **`45366370e`** (2026-10-16); s21 had synced to `0dacba55f`.
Read source with `grep`/`sed`; do not build Ruffle (it takes far too long on 4 CPUs).

**No Ruffle exporter oracle in the cloud.** If your diagnosis needs a fresh Ruffle exporter run (a
trace or a render from current Ruffle), write the exact request in a `## LOCAL ORACLE REQUESTS`
section of your report (SWF path, frames, what you need from it). The coordinator runs it locally
and archives the output for the wave-2 worker. Do not block on it: finish everything else.

## Baseline — read fresh at session start 2026-10-16 (verify before implementing anything)

- **Code**: nothing corpus-relevant landed since s21 except the AVM2 Seedling leak fixes
  `c6be20a88` + `4c450f076` (freeing scratch buffers; E4X node collector). Later commits are the
  in-browser recompiler page and a license file.
- **Trace baseline: 4476 effective / 4551 graded** (graphics/full run on `4c450f076`, results
  `846adcc6b`, 2026-10-03). No-graphics weekly at `8b69f982f` (results merged into master at session
  start) is per-test identical in code terms; its extra fails are upstream drift (below).
  Read numbers with `python3 scripts/corpus_status_diff.py <old_ref> <new_ref> --stem results_graphics`.
  **Never quote a total from a brief or closeout; read it.**
- **Pixel baseline: 433 / 587** (images run `36515003936` at `02df69d28`, 2026-09-29). Nothing
  render-relevant landed since. Board of record: `wave0-image-board.md` (this dir), regenerated
  2026-10-16 from `origin/ruffle-image-results` with `scripts/image_triage.py`.
- **Trace board**: `wave0-trace-inventory.txt` (this dir): all 75 failing graphics rows with
  match/expected/actual line counts and flags (IGN, ACC/RVF/TWK/FBR, KF, RTXT, and `UP<ADM>` =
  the test's files changed upstream since the s21 sync). Upstream file list:
  `wave0-upstream-drift-namestatus.txt` (`0dacba55f..45366370e`: 98 added, 84 modified, 25 deleted
  files under `tests/tests/swfs`).
- **Upstream drift already visible in CI**: `avm1/point`, `avm1/rectangle`,
  gnash `Rectangle-v8` (graphics, 10-03) and also `avm1/matrix`, `avm1/context_menu`,
  `avm1/context_menu_item`, gnash `Matrix-v6..v8` (no-graphics weekly, 10-11) went pass → fail
  because upstream **rewrote the tests** (`expected_lines` 175→329, 745→617→629, 171→810, …). They
  are drift, not code regressions, and they are the session's cheapest re-flips.
- Prior boards: trace `SWFRecompDocs/plans/polish-sweep-arc.md` **§22.5**, pixels
  `SWFRecompDocs/plans/graphics-fanout-playbook.md` **§20** ("Left on the board (session 22)").
  Prior diagnosis of record: `SWFRecompDocs/plans/session21-fanout-reports/` (and s20/s19/…).
  **Read the prior report for your family before starting, and grep the arc doc and playbook for a
  STRIKE / CAPPED / NO-GO on your family.** (`blend_modes` is CAPPED since s11; s20 funded a struck
  cluster by mistake.)

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

1. Write `SWFRecompDocs/plans/session22-fanout-reports/<your-slug>-report.md`.
2. Wave 1 (diagnosis): source edits are allowed only as a measured PROTOTYPE; deliver it as
   `<your-slug>-prototype.patch` (`git diff origin/master -- <source dirs>`) and then revert the
   source files so your commit holds only files under `session22-fanout-reports/`.
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
