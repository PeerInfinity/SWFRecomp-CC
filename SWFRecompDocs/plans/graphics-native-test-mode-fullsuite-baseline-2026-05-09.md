# Graphics-Native Full-Suite Baseline (2026-05-09)

> **Update 2026-05-10:** This baseline is the pre-session-of-2026-05-10
> snapshot. The numbers below are now stale (graphics-native moved from
> 573/1122 → 797/1125 in one session). See the **2026-05-10** sections
> at the bottom of this doc and `graphics-native-test-mode-plan.md` for
> the current state. Kept for historical comparison.

First full-suite CI run of `--mode=graphics` after Phase 2's structural
backports landed. Run ID: 25616804905, parallel=10, completed in ~19
minutes. Results live at `origin/ruffle-test-results` as
`results_graphics.json` per suite.

## Per-suite pass rates

| Suite | NO_GRAPHICS | `--mode=graphics` | Δ |
|---|---|---|---|
| `avm1` | 605/648 (93.4%) | **463/648 (71.5%)** | −142 |
| `from_gnash/actionscript.all` | 126/190 (66.3%) | **0/190 (0.0%)** | −126 |
| `from_gnash/misc-ming.all` | 66/102 (64.7%) | 9/102 (8.8%) | −57 |
| `from_gnash/misc-mtasc.all` | 7/9 (77.8%) | **0/9 (0.0%)** | −7 |
| `from_gnash/misc-swfc.all` | 8/16 (50.0%) | 5/16 (31.2%) | −3 |
| `from_gnash/misc-swfmill.all` | 17/18 (94.4%) | 16/18 (88.9%) | −1 |
| `from_shumway` (flat) | 73/92 (79.3%) | 47/92 (51.1%) | −26 |
| `from_shumway/avm1` | 46/47 (97.9%) | 33/47 (70.2%) | −13 |
| **TOTAL** | **948/1122 (84.5%)** | **573/1122 (51.1%)** | **−375** |

## Cluster analysis

### `from_gnash/actionscript.all` — 0/190, all `output_mismatch`

Every test fails the same way. Sample diffs:

- `ASnative-v5`: actual=59, expected=107 lines
- `ASnative-v6`: actual=59, expected=110 lines
- `Accessibility-v5`: actual=59, expected=15 lines

The **constant `actual=59`** across tests with wildly different expected
outputs (107, 110, 15 lines) is the smoking gun: tests are emitting a
fixed boilerplate prefix and then nothing else. Likely a shared init
crash or early-return in the test harness setup that all 190 tests
hit. Investigating one test should fix all of them.

**Highest-impact fix on the board.** A single root-cause fix here
likely converts ~100 tests to pass (the 126 NO_GRAPHICS-passing
subset).

### `from_gnash/misc-mtasc.all` — 0/9, all `runtime_segfault`

All 9 tests crash. One annotation: `enum: SIGSEGV (output matches)` —
the test produced correct output and *then* segfaulted, suggesting an
exit-time / cleanup bug. Likely shared with other crash-at-exit tests.

### `from_gnash/misc-ming.all` — 9/102, 83 mismatch + 7 segfault

Mix. The 7 segfaults (e.g. `ButtonEventsTest`) are probably the same
exit-time crash as `misc-mtasc`. The 83 mismatches likely include
multiple clusters; need to look at first-line-divergence to group.

### `avm1` — 463/648, 142 below NO_GRAPHICS

The biggest absolute pool of "tests that work in NO_GRAPHICS but fail
in graphics-native." This is where most of the per-test triage work
will happen after the high-impact clusters above are addressed. Many
tests probably share root causes too — cluster mining recommended.

### `from_shumway` and `from_shumway/avm1` — 51% / 70%

Mid-tier. 26 + 13 = 39 parity gaps. Likely a mix of a few small
clusters plus per-test issues.

### `from_gnash/misc-swfmill.all` — 16/18, only −1 from NO_GRAPHICS

Closest to parity. The single regressing test would be a quick
investigation.

## Recommended Phase 2 ordering

Apply the playbook's "compile/segfault first, then cluster mining":

1. **Fix the `actionscript.all` shared init issue.** Pick any test in
   that suite, look at the first `actual=59` lines (the boilerplate
   prefix everyone produces), then run the same test in NO_GRAPHICS to
   see what's missing after line 59. Whatever produces the divergence
   on line 60 is the shared root cause. Estimated unlock: ~100 tests.

2. **Fix the segfault cluster.** Pick one segfault from `misc-mtasc.all`
   or `from_gnash/misc-ming.all`. Run under gdb or with debug build to
   get a stack trace. The "(output matches)" annotation on `enum`
   suggests the crash is in shutdown — start by checking `swfStart`'s
   teardown path in `swf.c` for missing nulls / double-frees.
   Estimated unlock: ~10–20 tests across suites.

3. **Cluster-mine `avm1`.** With the two high-impact clusters above
   resolved, the avm1 suite's 142-test gap is the next big pool. Use
   the parity-gap query from the playbook to extract names; sort by
   first-line-divergence to find clusters.

4. **Subtle smoke failures last.** The two outstanding smoke failures
   from Phase 2 (`tell_target_invalid`, `unload`) will likely still be
   subtle even after the above. Pick them up after the structural
   work has stabilized the larger pools.

## Reproducibility

All data fetchable from the `ruffle-test-results` branch:

```bash
git fetch origin ruffle-test-results
for suite_path in $(git ls-tree origin/ruffle-test-results -r --name-only \
    | grep results_graphics.json); do
  echo "=== $suite_path ==="
  git show "origin/ruffle-test-results:$suite_path" \
    | python3 -c 'import json,sys; d=json.load(sys.stdin); print(f"{d[\"pass\"]}/{d[\"total\"]} ({d[\"pass_rate\"]}%)")'
done
```

To re-run the same baseline:

```bash
gh workflow run ruffle-tests.yml --ref master \
  -f mode=graphics -f categories=all -f parallel=10
```

---

## 2026-05-10 update: post-session re-baseline

Two commits landed this session, each unblocking a single structural
cluster:

| Commit | Cluster | Per-suite effect |
|---|---|---|
| `fff977ec` | `from_gnash/actionscript.all` 0/190 (Dejagnu setInterval stuck on frame 0) | +125 actionscript.all; smaller bumps on other Dejagnu-using suites |
| `ebaa7506` | "SIGSEGV (output matches)" cluster (shutdown crash from `malloc`'d display_list passed to `heap_free`) | avm1: 47 segfaults → 1; misc-mtasc 0 → 7; misc-ming +34 |

### Per-suite delta

| Suite | NO_GRAPHICS | 2026-05-09 graphics | 2026-05-10 graphics | Δ | Effective pass |
|---|---|---|---|---|---|
| avm1 | 605/648 (93.4%) | 463 (71.5%) | **510 (78.3%)** | **+47** | 521/651 |
| from_gnash/actionscript.all | 126/190 | 0 | **125 (65.8%)** | **+125** | 186/190 |
| from_gnash/misc-ming.all | 66/102 | 9 | **43 (42.2%)** | **+34** | 57/102 |
| from_gnash/misc-mtasc.all | 7/9 | 0 | **7 (77.8%)** | **+7** | 8/9 |
| from_gnash/misc-swfc.all | 8/16 | 5 | 6 (37.5%) | +1 | 11/16 |
| from_gnash/misc-swfmill.all | 17/18 | 16 | 17 (94.4%) | +1 | 18/18 |
| from_shumway | 73/92 | 47 | 52 (56.5%) | +5 | 57/92 |
| from_shumway/avm1 | 46/47 | 33 | 37 (78.7%) | +4 | 38/47 |
| **TOTAL** | **948/1122 (84.5%)** | **573 (51.1%)** | **797 (70.8%)** | **+224** | **896/1125 (79.6%)** |

### Cluster status

- **actionscript.all 0/190**: fully resolved by `fff977ec` (now at
  NO_GRAPHICS parity 125 vs 126; effective pass 186/190).
- **SIGSEGV (output matches) cluster**: fully resolved by `ebaa7506`
  (avm1 segfaults 47 → 1; misc-mtasc full NO_GRAPHICS parity).
- **misc-ming long tail**: +34 from session, but still 50+ failures.
  Mix of segfaults (resolved) and output_mismatches (long tail).
- **avm1 long tail**: 128 output_mismatch + 1 segfault + 1 timeout.
  No dominant cluster — per-test triage from here.

### What's left

- ~52 tests separate the current 896 effective pass from the 948
  NO_GRAPHICS baseline. No structural cluster left; this is cluster-
  mining territory (see `graphics-native-test-mode-playbook.md`).
- Two smoke failures still subtle: `tell_target_invalid`, `unload`
  (diagnoses in `graphics-native-test-mode-phase2-results-2026-05-09.md`).

### Reproducibility

Latest CI run: 25640191347 (mode=graphics, parallel=30, ~6 min). Cache
state after `ea65de7f`: Dawn auto-builds on miss; ccache capped at
200M; old caches pruned at end of each run.
