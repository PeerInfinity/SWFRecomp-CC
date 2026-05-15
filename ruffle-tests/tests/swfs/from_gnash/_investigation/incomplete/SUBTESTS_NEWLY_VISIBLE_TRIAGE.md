# Triage: Newly-Visible `[subtests]` Tests
<!-- TESTS: Date-v5..v8, MovieClip-v6/v7/v8, Object-v5..v8, TextField-v6/v7/v8, Function-v5..v8, Stage-v6/v7/v8, XMLNode-v5..v8, XML-v5..v8, getvariable-v5..v8, setProperty-v5..v8, ops-v5/v6/v7, array-v6/v7/v8, argstest-v6/v7/v8, NetConnection-v6/v7/v8, Transform-v8, TextFormat-v8, flash-v8, Global-v5, BitmapDataDraw, GradientFillTest, PrototypeEventListeners, TextSnapshotTest, action_order/{PlaceAndRemove,action_execution_order_test,action_execution_order_extend_test}, loading/LoadBitmapTest, matrix_accuracy_test1, movieclip_destruction_test3, action_execution_order_test12, misc-swfmill.all/{registers,trace-as2/arguments} -->

<!-- PLAN_META
id: SUBTESTS_NEWLY_VISIBLE_TRIAGE
status: not_started
phases:
  - id: 1
    name: "Tier A — near-passing (≥95% line match); land cheap fixes / ignored_tests promotions"
    status: not_started
  - id: 2
    name: "Tier B — close (85-95%); split out per-family plans"
    status: not_started
  - id: 3
    name: "Tier C — mid (75-85%); identify shared root causes across families"
    status: not_started
  - id: 4
    name: "Tier D — deeper (50-75%); document scope before committing"
    status: not_started
  - id: 5
    name: "Tier E — shallow (<50%); decide accept-vs-investigate per test"
    status: not_started
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Shipped 2026-05-14 (commit 39b797ac, plan complete/SUBTESTS_HARNESS_PLAN.md). Discovery now resolves expected-output filename per-test."
blockers: []
-->

Last updated: 2026-05-15

## Status: NOT STARTED — triage doc only

This doc inventories the 49 newly-discoverable `output_mismatch` tests
that appeared in CI `eb8206f8` (run `25896064893`, no-graphics) after
`SUBTESTS_HARNESS` shipped. They're grouped by line-match tier so we
can pick the cheap wins first and decide which deserve dedicated plans.

Out of 66 newly-visible tests across the four Gnash sub-suites, results
broke down as:

- **2 PASS**: `Global-v5` (actionscript.all), `misc-swfmill.all/trace-as2/arguments`.
- **8 ruffle_matched**: `ops-v5/v6/v7` (97.3% lines), `setProperty-v5/v6/v7/v8` (5.8% lines — RM because our diff is a subset of Ruffle's, not because we're close), `BitmapDataDraw` (55.4%).
- **49 output_mismatch**: triaged below.

`Global-v5` (PASS) and `BitmapDataDraw` (RM) mean some of these tests
*already* work end-to-end with no code changes — they were simply
hidden from our results. Expect a similar pattern across some of the
Tier A/B mismatches: the SWF runs cleanly, line diffs are tiny, and
the test is one Ruffle-vs-Flash quirk or one tiny bug from PASS.

## Source data

All numbers from `ruffle-tests/tests/swfs/from_gnash/{suite}/_results/results.json`
at commit `eb8206f8`. Per-test breakdown follows the tier tables.
The actionable signal for each tier is in the **"Next move"** line.

## Tier A — near-passing (≥95% line match), N=7

| Test | Suite | Lines | % |
|------|-------|------:|--:|
| `Date-v7` | actionscript.all | 349/357 | 97.8% |
| `Date-v8` | actionscript.all | 349/357 | 97.8% |
| `Date-v6` | actionscript.all | 348/357 | 97.5% |
| `ops-v5` | actionscript.all | 253/260 | 97.3% (RM) |
| `ops-v6` | actionscript.all | 253/260 | 97.3% (RM) |
| `ops-v7` | actionscript.all | 255/262 | 97.3% (RM) |
| `Date-v5` | actionscript.all | 305/315 | 96.8% |

**Next move.** `Date-v5..v8` look like one or two shared diff lines per
version (and the per-version delta is small — 8 lines on v6/v7/v8, 10
on v5). Read the diff once, fix the shared cause, and likely flip all
four to PASS. The `ops-vN` trio is already ruffle_matched; reading the
7-line diff against Ruffle's `output.ruffle.txt` would tell us if the
remaining lines are Ruffle-vs-Flash quirks (→ ACCEPTED_DIFFS) or our
own bug. If diffs are Ruffle-side, ignored_tests promotion is the
cheapest landing.

## Tier B — close (85-95%), N=9

| Test | Suite | Lines | % |
|------|-------|------:|--:|
| `array-v6` | actionscript.all | 604/644 | 93.8% |
| `Object-v5` | actionscript.all | 135/145 | 93.1% |
| `array-v7` | actionscript.all | 585/654 | 89.4% |
| `array-v8` | actionscript.all | 585/654 | 89.4% |
| `flash-v8` | actionscript.all | 36/41 | 87.8% |
| `Object-v7` | actionscript.all | 292/333 | 87.7% |
| `Object-v8` | actionscript.all | 292/333 | 87.7% |
| `Function-v5` | actionscript.all | 135/158 | 85.4% |
| `action_order/action_execution_order_test` | misc-ming.all | 16/19 | 84.2% |
| `misc-swfmill.all/registers` | misc-swfmill.all | 30/36 | 83.3% |

**Next move.** `array-v6/v7/v8` are likely the same shape as
`incomplete/ARRAY_V5_PLAN.md` covers for v5 — read the diffs and add a
cross-version section to that plan (don't open a new plan). `Object-v5`
vs `Object-v7/v8` is a meaningful gap: v5 close to passing suggests a
v5-specific path is solid and the v7/v8 paths share a different
divergence; worth splitting along that line.

## Tier C — mid (75-85%), N=21

| Test | Suite | Lines | % |
|------|-------|------:|--:|
| `Stage-v6` | actionscript.all | 54/64 | 84.4% |
| `Stage-v7` | actionscript.all | 54/64 | 84.4% |
| `Stage-v8` | actionscript.all | 54/64 | 84.4% |
| `XMLNode-v5` | actionscript.all | 174/207 | 84.1% |
| `XMLNode-v6` | actionscript.all | 174/207 | 84.1% |
| `XMLNode-v7` | actionscript.all | 174/207 | 84.1% |
| `XMLNode-v8` | actionscript.all | 174/207 | 84.1% |
| `Object-v6` | actionscript.all | 279/333 | 83.8% |
| `MovieClip-v6` | actionscript.all | 777/936 | 83.0% |
| `MovieClip-v7` | actionscript.all | 798/969 | 82.4% |
| `MovieClip-v8` | actionscript.all | 885/1087 | 81.4% |
| `getvariable-v7` | actionscript.all | 49/64 | 76.6% |
| `getvariable-v8` | actionscript.all | 49/64 | 76.6% |
| `getvariable-v5` | actionscript.all | 44/58 | 75.9% |
| `Function-v7` | actionscript.all | 205/272 | 75.4% |
| `Function-v8` | actionscript.all | 205/272 | 75.4% |
| `getvariable-v6` | actionscript.all | 48/64 | 75.0% |
| `loading/LoadBitmapTest` | misc-ming.all | 13/17 | 76.5% |

(plus `TextFormat-v8`, `TextField-v6/v7/v8` straddling the 73-74% line — see Tier D)

**Next move.** Several Tier C families show byte-identical line counts
across versions (Stage-v6/v7/v8 all 54/64, XMLNode-v5..v8 all 174/207).
That's a tell: the diff is one underlying issue shared across versions.
Read one diff per family, fix once. For `MovieClip-vN` (777-885 lines
matching out of 936-1087 expected — i.e. 150-200 mismatched per
version): probably a small handful of MC methods missing per version.
Compare against `complete/GNASH_FEATURE_PLAN.md`'s historical MovieClip-v5
notes (the v5 variant already shipped before SUBTESTS_HARNESS).

## Tier D — deeper (50-75%), N=11

| Test | Suite | Lines | % |
|------|-------|------:|--:|
| `TextFormat-v8` | actionscript.all | 128/172 | 74.4% |
| `TextField-v6` | actionscript.all | 404/545 | 74.1% |
| `TextField-v8` | actionscript.all | 416/571 | 72.9% |
| `TextField-v7` | actionscript.all | 414/570 | 72.6% |
| `Transform-v8` | actionscript.all | 71/101 | 70.3% |
| `Function-v6` | actionscript.all | 181/271 | 66.8% |
| `XML-v5` | actionscript.all | 281/449 | 62.6% |
| `XML-v8` | actionscript.all | 288/465 | 61.9% |
| `NetConnection-v7` | actionscript.all | 75/126 | 59.5% |
| `NetConnection-v8` | actionscript.all | 75/126 | 59.5% |
| `XML-v6` | actionscript.all | 288/486 | 59.3% |
| `XML-v7` | actionscript.all | 288/486 | 59.3% |
| `NetConnection-v6` | actionscript.all | 71/126 | 56.3% |
| `matrix_accuracy_test1` | misc-swfc.all | 10/18 | 55.6% |

**Next move.** These need scope before committing. `NetConnection-vN`
is mostly a stubs question (we have a stub but it likely doesn't
implement most members); decide accept-via-ignored_tests vs. full impl.
`XML-vN` and `XMLNode-vN` together are ~10 tests and likely share an
XML parser / DOM gap — combined plan, not per-version. `matrix_accuracy_test1`
diffs (see results JSON) look like a known fixed-point precision issue
(`_x: -107374182.4` vs `1073741824` — a sign/scale bug in twips→pixel
conversion); narrow target.

## Tier E — shallow (<50%), N=8

| Test | Suite | Lines | % |
|------|-------|------:|--:|
| `GradientFillTest` | misc-ming.all | 119/278 | 42.8% |
| `action_execution_order_test12` | misc-swfc.all | 9/22 | 40.9% |
| `TextSnapshotTest` | misc-ming.all | 49/132 | 37.1% |
| `movieclip_destruction_test3` | misc-swfc.all | 5/18 | 27.8% |
| `action_order/action_execution_order_extend_test` | misc-ming.all | 8/32 | 25.0% |
| `action_order/PlaceAndRemove` | misc-ming.all | 15/96 | 15.6% |
| `PrototypeEventListeners` | misc-ming.all | 1/32 | 3.1% |
| `argstest-v6` | actionscript.all | 44/2192 | 2.0% |
| `argstest-v7` | actionscript.all | 46/2061 | 2.2% |
| `argstest-v8` | actionscript.all | 46/2434 | 1.9% |

**Next move.** `argstest-v6/v7/v8` (2000+ expected lines, <50 matching)
strongly suggests an early-bailout / segfault that aborts the test
before most assertions run. Look for crash signature in CI logs; one
fix here unlocks ~6500 expected lines across the three. `GradientFillTest`
has dedicated plans already in `complete/CPU_GRADIENT_RASTERIZER_PLAN.md`
and `complete/WITH_SCOPE_GRADIENT_FILL_PLAN.md` — the 42.8% reflects
real feature gaps documented there. `PrototypeEventListeners` (1/32) is
almost certainly a crash too. The `action_order/*` cluster overlaps
with the existing `incomplete/MISC_MING_SWFC_PLAN.md` action-execution
tracking; check there first.

## Cross-cutting observations

### Some "ruffle_matched" tests have very low line-match

`setProperty-v5/v6/v7/v8` all show 3/52 lines matched but
`ruffle_matched` status with `ours_diff_count=ruffle_diff_count=49`.
Translation: 49 lines diverge for both us and Ruffle (against Flash),
and our 49-line diff is a subset of Ruffle's 49-line diff. This isn't
"we're close to passing" — it's "Ruffle disagrees with Flash on
basically the whole test, and so do we, identically". Likely candidates
for `RUFFLE_VS_FLASH_DIFFERENCES.md` or `ACCEPTED_DIFFS.md` rather than
fix targets.

### Per-family version cohorts

Many test families have versions with byte-identical line counts:

- `XMLNode-v5/v6/v7/v8`: all 174/207
- `Stage-v6/v7/v8`: all 54/64
- `setProperty-v5/v6/v7/v8`: all 3/52
- `XML-v6/v7`: both 288/486; `XML-v8` 288/465

That tells us the underlying bytecode / harness is version-agnostic for
those tests — version differences are mostly in player-version-gated
features that don't fire here. Fixing one version of each family fixes
all of them.

### What previous failure inventories underrepresented

Before SUBTESTS_HARNESS, `FAILING_TESTS_BY_FEATURE.md` listed e.g.
"MovieClip (1 failing / 1 total)" — implying we'd nailed the whole
feature. Actually only `MovieClip-v5` was discoverable. The post-CI
regenerated FAILING_TESTS_BY_FEATURE.md now shows the full version
cohort and should be the reference for prioritization going forward.

## Recommended attack order

1. **Date-v5/v6/v7/v8 (Tier A)** — likely single shared diff, four tests off the board. Probably <1 hour.
2. **ops-v5/v6/v7 (Tier A, RM)** — read the 7-line diff, decide ACCEPTED vs. fix. Either way clears the line item.
3. **Object-v5 alone (Tier B)** — close enough to pick off; reading the diff also informs the broader Object-vN cluster.
4. **array-v6/v7/v8 (Tier B)** — extend `incomplete/ARRAY_V5_PLAN.md`, don't open new plan.
5. **XMLNode-v5..v8 + XML-v5..v8 (Tier C + D)** — combined plan; shared root cause likely.
6. **MovieClip-v6/v7/v8 (Tier C)** — substantial work; compare against historical MovieClip-v5 fix notes in `complete/GNASH_FEATURE_PLAN.md`.
7. **argstest-v6/v7/v8 (Tier E)** — crash investigation; potentially unlocks 6500 lines.
8. **Everything else** — case-by-case as effort permits, or punt to ACCEPTED_DIFFS if Ruffle-vs-Flash quirks dominate.

## Out of Scope

- Regressions introduced this CI (`placeobject_occupied_depth`,
  `loop/loop_test10`, `RegisterClassTest4`) — those are unrelated to
  SUBTESTS_HARNESS; track in suite CURRENT_STATUS files.
- Image comparison subtests (`[image_comparisons.subtests.…]` if any) —
  out of scope per `complete/SUBTESTS_HARNESS_PLAN.md`.
- Runtime player-version override (Option B in SUBTESTS_HARNESS_PLAN);
  if any per-fp-version diffs become recurring blockers we can
  reconsider.
