# Session prompt: build the feature-priority map from the full Ruffle corpus

Paste everything below this line into a fresh session. **Opus is fine for
this session** — it is analysis/categorization-heavy; escalate to Fable only
if the empty-output driver investigation (step 1) turns into subtle runtime
debugging.

---

Build the **coverage-gap → feature-priority map** from the newly imported
full Ruffle test corpus. The corpus is the roadmap instrument: rank the
features we haven't implemented by how many tests they would unlock, so the
map decides what to build next (user direction 2026-07-23; import completed
2026-07-24, both-mode baselines merged at `eabb3b366`, zero regressions).

Read first:
- `ruffle-tests/tests/swfs/_investigation/FULL_SUITE_IMPORT_AUDIT.md` —
  what was imported, the CI selectors (`all` = classic five per-change
  default, `full` = complete corpus, `from_avmplus`/`misc` targeted),
  caveats (visual is mostly image-only; mixed_avm/stage3d are parked
  feature markers).
- `ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.json` —
  the per-test baseline (fields: status, lines.actual/expected/matching).
- `scripts/generate_failing_by_feature.py` — existing per-suite
  failing-by-feature generator (has avm1 + gnash configs; extend it).
- `ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md` — how the
  avm2 suite tracks its own gap list; from_avmplus needs the same.

## Baseline facts (2026-07-24, don't re-derive)

Full corpus, mode=graphics: **3211/4463 effective (71.9%)**; no-graphics is
identical except two pre-existing one-test divergences
(`from_gnash/misc-swfc.all/gotoFrameFromInterval2`, `visual/video/deblocking`
— documented in memory, not your problem this session).

**from_avmplus: 871/1574 effective (55.3%)** — 681 output_mismatch,
16 runtime_error, 3 timeout, 2 segfault, 1 compile_fail. Area × status:

| area | eff/total | mismatch | other-fail | note |
|---|---|---|---|---|
| ecma3 | 402/800 | 397 | 1 | 205 of the mismatches are EMPTY-actual |
| as3 | 410/509 | 93 | 6 | 42 empty-actual |
| **e4x** | **2/177** | 175 | 0 | near-total failure; 34 empty-actual |
| mops | 0/13 | 0 | 13 | all crash/error — Alchemy memory opcodes, likely unimplemented |
| recursion | 1/6 | 5 | 0 | |
| regress | 43/55 | 11 | 1 | |
| misc | 13/14 | 0 | 1 | |

Mismatch shape across the 681: **287 empty-actual (≤1 output line)**,
234 partial (50–90% lines match), **108 near-pass (≥90% match)**, 52
diverged. Upstream marks 74 from_avmplus tests `known_failure = true`
(even Ruffle fails them) — account for them in the map before ranking;
check how `verify_output.py` grades known_failure.

## Tasks, in order

1. **Crack the empty-actual pattern (287 tests) FIRST.** Signature:
   `ecma3/String/substr` prints one empty line then nothing (runs, no
   crash). avmplus tests share a compiled-in test-driver framework — the
   hypothesis is one shared startup/driver failure (a missing builtin the
   driver calls, a print-path issue) kills output wholesale. Run 3–5
   affected tests locally, capture actual stdout, and diagnose. One fix
   here may be worth hundreds of tests. Any fix: regression-guard with a
   CI `categories=from_avmplus -f mode=graphics` dispatch (autonomous CI
   is authorized; `.claude/pipeline-handoff.md`).
2. **Probe e4x (2/177).** Our runtime passes Ruffle's own avm2-suite E4X
   tests, so near-total failure against Tamarin's is surprising — sample a
   few, decide whether it's one systemic gap (e.g. the driver again, or a
   missing E4X entry point) or genuinely broad missing coverage.
3. **Build the map.** Extend `generate_failing_by_feature.py` with a
   `from_avmplus` config (auto-categorize by path — first two components,
   e.g. `ecma3/String`, works well) and generate
   `from_avmplus/_investigation/FAILING_TESTS_BY_FEATURE.md`. Then write
   the corpus-wide priority report (suggested:
   `SWFRecompDocs/plans/feature-priority-map.md`): every feature area
   ranked by unlockable test count, folding in the avm2 suite's ~360
   mismatches, the misc-category failures (text 5/11, fonts 3/6,
   mixed_avm 3/11, stage3d 1/5, import_assets 1/3, audio 3/5), and the
   from_shumway AVM2 half (74.7%). Separate "feature arcs" (build X,
   unlock N tests) from "polish" (near-pass quick wins). Pre-extracted
   lists — the 287 empty-actual tests, the 108 near-passes, and the 22
   non-mismatch failures — are in
   `ruffle-tests/tests/swfs/from_avmplus/_investigation/BASELINE_SEED_2026-07-24.md`.
4. **Seed `from_avmplus/_investigation/CURRENT_STATUS.md`** (mirror the
   avm2 suite's format) and close with a recommendation: top 3–5 arcs
   with expected test yield.

## Workflow rules

- NEVER run full suites locally — single tests only:
  `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_avmplus --test=ecma3/String/substr --diff`
  (test names are nested paths). Full-suite verification goes through CI
  (`gh workflow run ruffle-tests.yml --ref master -f mode=graphics -f categories=from_avmplus`).
- Commit directly to master, standard trailer, pipeline per
  `.claude/pipeline-handoff.md`. Runtime fixes that touch shared AVM2 code
  ⇒ `categories=full`.
- The Ruffle source oracle is at `~/CC/ruffle` (`git pull --ff-only`
  first); MTASC and test infra notes are in CLAUDE.md.
