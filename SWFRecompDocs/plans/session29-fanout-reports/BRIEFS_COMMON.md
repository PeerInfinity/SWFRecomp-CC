# Session 29: corpus fan-out (dual-axis #21), common brief. ALL WORKERS READ THIS FIRST.

**Session mode: CLOUD-FIRST (user directive 2026-10-16, re-confirmed 2026-11-26 for s29).** Every step that can run in the cloud
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
`git clone --filter=blob:none https://github.com/ruffle-rs/ruffle /root/ruffle` (blobless keeps history, so `git -C
/root/ruffle diff c2f7d24b7 origin/master -- <path>` and `git log` work). The coordinator's local exporter oracle is
built at **`0ddd12b6a`** (s23 sync) and its Ruffle test runner is a Feb-2026 build. The s28 drift slot synced upstream to
**`c2f7d24b7`**; upstream is now **`31e07df77`** (2026-11-26): new rows `avm1/bitmapdata_palettemap_values`
(`745653790`+`e7e02dbec`) and `avm2/bitmapdata_palettemap_opaque` (`aa850487d`+`31e07df77`), `avm1/bitmap_data_thorough/paletteMap`
loses `known_failure` and its `output.ruffle.txt`, `9c6ab4945` is a Rust-only JPEG test. CI downloads upstream master on
every run, so the s29 baseline download may be newer still.
Read source with `grep`/`sed`; do not build Ruffle (it takes far too long on 4 CPUs).

**No Ruffle exporter oracle in the cloud.** If your diagnosis needs a fresh Ruffle exporter run, write the exact
request in a `## LOCAL ORACLE REQUESTS` section of your report (SWF path, frames, what you need from it). The
coordinator runs it locally and archives the output for the wave-2 worker. Do not block on it: finish everything else.
Exporter limits (measured s25): it **never fires `setTimeout`/`setInterval` callbacks**; it renders at **HIGH quality
only**; it rejects a zero/negative-width header RECT. It is a FALLBACK oracle now (below).

## A REAL FLASH ORACLE EXISTS (coordinator-run; first-choice oracle since s27)

The coordinator runs **real Flash Player 32** (debug projectors, Linux LNX 32,0,0,465 and Windows) locally via
`tools/flash-oracle/` (read its `README.md`: it is in the repo). The binaries never leave the coordinator's box, so you
cannot run it in the cloud.
- `run_trace.py`: traces. **AVM1 runs in DIRECT mode, pinned 1:1** (the default; a root stub loads the test into
  `_level0` once the window settles). `--wrapped` (AS3 wrapper, exact `num_frames` cut) changes `_root` and depths: it
  produced false "Flash refutes" verdicts in s27, so never use it for AVM1 `_root`/depth questions. XTest **typing** via
  `--type`; no mouse input.
- `run_image.py`: stage PNG via an AS3 `draw()` wrapper; **`--screen`** grabs the real screen, and is REQUIRED for
  non-LAYER blend modes (`draw()` mis-renders them). Direct runs are window-pinned (unpinned runs < 640 px wide were
  scaled). Flash renders at its default HIGH quality unless the SWF sets quality itself.
- **Flash is the first-choice oracle**: the exporter/runner are Ruffle, fallbacks only. Put Flash needs under
  `## LOCAL ORACLE REQUESTS` as "FLASH: <fixture dir or corpus test>, trace|image, frames, direct|screen, what to
  compare". Ship a built SWF (or a build script the coordinator can run locally) with every request. The coordinator
  runs them between waves and archives the outputs under `session29-fanout-reports/w1-local-oracles/`; wave-2 briefs
  name the archived goldens you must use. **A Flash golden overrules a Ruffle golden and any analytic derivation.**
- Traps measured so far: a synthetic square-glyph DefineFont2 fixture can be **Flash-invalid** (Flash drew no glyphs
  when the font's code table was not ascending), so a fixture with a font must be checked in Flash before its golden
  counts; the exporter's text-field border corners differ from Flash by 64 on the 4 corner pixels per box; FP9 ≠ FP10+
  (s27 booked gnash `test12` "Flash-ward" because we matched `output.fp9.txt`; FP32 prints `output.fp10.txt`). **Grade
  against FP32, never against an FP-version variant.**
- s28 traps: any pinned AVM1 quality=low capture from before 2026-11-25 was really HIGH (old stub); Flash TIMERS are
  wall-clock nondeterministic in tie/catch-up cases, so ask for several captures and grade with a bound check; ask for
  `--log-warnings` where the golden has `Warning:` lines. Max 4 parallel Linux captures, so keep requests tight.

## Flash fixes (`ruffle-tests/flash_fixes/`, 62 entries at s28 closeout)

Robert (2026-11-24): match Flash, not Ruffle; document every Ruffle≠Flash difference; store fixes for bad Ruffle goldens
and re-apply them after every download. `download_tests.sh` runs `apply_flash_fixes.py` at its end, so a fixed golden is
what you and CI grade against (the original is kept as `<file>.upstream`). Read `ruffle-tests/flash_fixes/README.md`.
- If your work proves a corpus golden ≠ FP32 (a coordinator-run capture), say so in your report as a **flash_fixes
  candidate**, with the capture. The coordinator adds entries; workers do not edit `fixes.json` unless the brief says so.
- Every Ruffle≠Flash difference you confirm gets an RvF entry
  (`ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`), append-only at EOF.
- s28's `trace-provenance` checked every failing and `ruffle_matched` TRACE golden against FP32
  (`session28-fanout-reports/trace-provenance.md`, plus its `trace-provenance/` captures). Read the rows for your family
  before asking for a new capture: many FP32 outputs already exist on master.

## Baseline — read fresh (verify before implementing anything)

- **s29 BASELINE (graphics, trace + pixels) = the s28 FINAL run `45878805896` at code `bfa47037b`, results `014124ed5`.**
  Coordinator's read at `014124ed5` (2026-11-26): trace **4827 effective / 4864 rows** (4642 pass + 185 `ruffle_matched`,
  **37 failing**); pixels **545 pass / 140 fail** (+6 ignored, 3 skip). **No-graphics: run `45878818309`, results
  `336b83183`** (4825 eff; mode diffs only `audio/aac` + `avm2/audio_computespectrum`). Everything after `bfa47037b` on
  master is docs/results. Failing lists: `s29-baseline-trace-failing.txt`, `s29-baseline-trace-rm.txt` and
  `s29-baseline-pixel-failing.txt` next to this file. Your *before* leg is always `origin/master`. Read with
  `python3 scripts/corpus_status_diff.py <old_ref> <new_ref> --stem results_graphics` and `scripts/image_status_diff.py`.
  **Never quote a total from a brief or closeout; read it.**
- **`ruffle_matched` is NOT a pass** (s28 trace-provenance): 139 of the 185 rm rows have FLASH goldens, so they are real
  gaps. A row is Flash-correct only at `pass`, or at rm where its golden is shown non-Flash.
- **Code since s27 closeout (s28 landed, `polish-sweep-arc.md` §29, playbook §27):** Flash thin-stroke snap (axis-aligned,
  u≤4/8/12, ¼-px width/position, fills never) + drawing-API snap (AVM1 trunc / AVM2 round) + closed-seam CAP rule and
  signed noScale width (n-join-disc); glyph ¼-px snap + border pen; Flash LOW quality model (sample point, reflect/repeat
  ×255/256, radial round(256t), opaqueBackground floor..ceil) + 37 FP32 golden swaps; Flash isotropic stroke width
  (timeline); drawTriangles culling; fractional shadow offset, glow quantisation, bevel fit; avmplus D2A number→string;
  ASnative major table, BitmapData kernels, MCL/form edges, gnash builtins, AVM2 prototypes (73 rm→pass); FP10 queued
  enterFrame of a removed clip; same-frame shape hitTest = stale last-render bounds; 4 deferred AVM1 queues + onUnload
  scope; newest-load-first, next-tick loaded goto scripts/loadClip, unloadMovie cancels a load; SWF5 occupied-depth
  keep-both (+ ErrorReporting warning kept); root onLoad via prototype; timer model (overdue once each in creation order,
  AVM2 getTimer +1 ms/call past 20); root GotoFrame inside onEnterFrame moves the playhead; browser root/attached gotos
  take the CI arms (`advance_attached_clip_frames` deleted).
- **The project state page** `SWFRecompDocs/plans/PROJECT_STATE.md` and **`NO_GO_REGISTER.md`** (every standing NO-GO with
  its reopen criterion, verdicts that fell, 12 UNSURE items) are new since s28. Read the register rows for your family.
- **Parallel local one-task sessions** (the N ladder and the browser ladder) may touch
  `tag.c`/`action.c`/`ng_shared.c`/`swf.c`/`render_webgpu.c`. Name every function you touch in those files.
- Boards of record: trace `SWFRecompDocs/plans/polish-sweep-arc.md` **§29.4**, pixels
  `SWFRecompDocs/plans/graphics-fanout-playbook.md` **§27** ("Left on the board (session 29)"). Prior diagnosis of
  record: `SWFRecompDocs/plans/session28-fanout-reports/` (and s27/s26/…). **Read the prior report for your family
  before starting, and grep the arc doc and playbook for a STRIKE / CAPPED / NO-GO on your family.**
- **Yield expectations.** The cheap wins are gone. A priced NO-GO with its completion mechanism is a full deliverable;
  do not stretch a lead to look like a flip, and do not pad a report. A Flash-correct change that loses a Ruffle-golden
  row is a priced loss to disposition (RvF), never a reason to keep the Ruffle behaviour.
- **Oracles.** Rows whose golden is a real Flash reference (upstream `pixelbender_dithering`, `bitmapdata-clone`, the 62
  `flash_fixes` entries, the 255 Flash-provenance image goldens in `session27-fanout-reports/golden-provenance.md`) are the
  only real Flash oracles for their paths: never regress them for a Ruffle match.

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

1. Write `SWFRecompDocs/plans/session29-fanout-reports/<your-slug>-report.md`.
2. Wave 1 (diagnosis): source edits are allowed only as a measured PROTOTYPE; deliver it as
   `<your-slug>-prototype.patch` (`git diff origin/master -- <source dirs>`) and then revert the
   source files so your commit holds only files under `session29-fanout-reports/`.
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
