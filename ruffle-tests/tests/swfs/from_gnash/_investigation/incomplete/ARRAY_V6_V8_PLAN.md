# array-v6/v7/v8 Extension Plan
<!-- TESTS: array-v6, array-v7, array-v8 -->

Last updated: 2026-05-24 (Phase 2 landed → array-v6/v7/v8 each gained
+2 line matches via the `Array.prototype.join.apply(a)` /
`a.join.apply(a)` receiver fix. Tests stay output_mismatch; residual
diffs are Phase 3/4/5 work. SWF5 gate keeps `array-v5` unchanged so
its `apply(a) == undefined` expectation still passes. Also closes
Phase 1: `a.hasOwnProperty('length')` was actually already passing in
the baseline — the originally-documented failure wasn't reproducing.)

<!-- PLAN_META
id: ARRAY_V6_V8_PLAN
status: in_progress
phases:
  - id: 1
    name: "a.hasOwnProperty('length') — Array.length not registered as own prop"
    status: completed
    note: "Already passing in baseline as of 2026-05-24 reproduction — callArrayMethod's hasOwnProperty branch already short-circuits length to true. No code change needed."
  - id: 2
    name: "Array.prototype.join.apply(a) — apply with Array this loses receiver"
    status: completed
    note: "Landed 2026-05-24: Function.prototype.apply's type-2 branch in actionCallMethod now sets g_call_this_type before invoking advanced_func (mirroring the .call path). SWF5 gate (g_swf_version >= 6) preserves SWF5's documented undefined-return behaviour. +2 lines on each of array-v6/v7/v8 (passes 592→594 / 573→575 / 573→575)."
  - id: 3
    name: "Sparse-array hasOwnProperty for densified indices"
    status: pending
  - id: 4
    name: "sortOn(field, RETURNINDEXEDARRAY) length tracking + stability"
    status: pending
  - id: 5
    name: "splice/concat/sort edge cases newly visible at SWF6+"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac); array-v6/v7/v8 became visible at that point."
  - id: ARRAY_V5_PLAN
    reason: "Same Gnash test source (array.as) with `#if OUTPUT_VERSION > 5` gates revealing extra assertions. Fixes in ARRAY_V5_PLAN apply to v6/v7/v8; this doc covers only the v6+-specific extras."
related:
  - id: ARRAY_V5_PLAN
blockers: []
status_note: |
  All three (v6/v7/v8) share the same test source as array-v5 plus
  ~94 extra `OUTPUT_VERSION > 5` assertions. After ARRAY_V5_PLAN
  closes, expect v6/v7/v8 to inherit most of those wins; this plan
  enumerates the v6+-only residual.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| array-v5 | 536/560 | 95.7% | output_mismatch (ARRAY_V5_PLAN active) |
| array-v6 | 604/644 | 93.8% | output_mismatch |
| array-v7 | 585/654 | 89.4% | output_mismatch |
| array-v8 | 585/654 | 89.4% | output_mismatch |

## Test source

Gnash testsuite/actionscript.all/array.as. Same source as
array-v5; `#if OUTPUT_VERSION > 5` blocks expose ~94 assertions
that the v5 run doesn't see.

## v6+-only failure clusters

### A. a.hasOwnProperty('length') (Phase 1)

Line: 106 (`a.hasOwnProperty('length')`).

```
- PASSED: a.hasOwnProperty('length') [./array.as:106]
+ FAILED: a.hasOwnProperty('length')
```

Flash maintains `length` as an own property of every Array instance.
We are treating it as inherited / virtual. Fix likely interacts with
the existing ASArray vs `arr->props` length tracking; verify with
the AVM1 `array_properties` and `array_length` tests before
committing.

### B. Array.prototype.join.apply(a) loses receiver (Phase 2)

Lines: 156, 157.

```
- PASSED: Array.prototype.join.apply(a) == "9,8,7,551,200" [./array.as:156]
+ FAILED: expected: "9,8,7,551,200" obtained:
```

When invoking `Array.prototype.join.apply(a)`, the receiver `a`
should become `this` inside join. We are losing the receiver and
join sees an empty/different `this`. Likely the
`Function.prototype.apply` setup-this path doesn't route through
the array-method dispatch's `g_call_this_type` machinery (the same
machinery the 2026-04-18 array-v5 fix added for OBJECT receivers).

Shared root cause likely with [[FUNCTION_VN_PLAN]] Phase 2 (apply/call
this-binding). Fix once, both plans benefit.

### C. Sparse-array hasOwnProperty for densified indices (Phase 3)

Line: 246.

```
- PASSED: gaparray.hasOwnProperty('4') [./array.as:246]
+ FAILED: gaparray.hasOwnProperty('4')
```

Sparse arrays should track which indices are HOLE vs UNDEFINED vs
set. `hasOwnProperty('4')` on `gaparray = [...]; gaparray[15]=...;
gaparray[16]=...; gaparray[4]=...` should be true for the explicitly-
set index 4. We return false — probably the index 4 isn't being
recorded as "own" because the densification put it in the elements
array but not in `arr->props`.

### D. sortOn return + length tracking (Phase 4)

Lines: 260, 263, 324, 325.

```
- PASSED: tmp.length == '3' [./array.as:260]
+ FAILED: expected: '3' obtained: 2
- PASSED: trysortarray.length == 4 [./array.as:324]
+ FAILED: expected: 4 obtained: 0
```

After certain `sortOn` invocations, the resulting array's `length`
is wrong (off by one in some cases, zero in others). The sortOn
result-array population is mis-tracking length. Verify against
the AVM1 `array_sort` test before committing.

### E. splice/concat/sort edge cases (Phase 5)

Lines: 377, 378, 417, 418, 419, 420, plus more in the tail.

```
- PASSED: r.toString() == ",vi,ed,nano,emacs,Jedit" [./array.as:950]
+ FAILED: expected: ",vi,ed,nano,emacs,Jedit" obtained: 0
- PASSED: tolen(r) == "[0, 2, 2, 2, 4, 5, 5]" [./array.as:1030]
+ FAILED: expected: "[0, 2, 2, 2, 4, 5, 5]" obtained: []
```

The sort family at SWF6+ exercises additional features (custom
comparators with closures, sortOn with multi-field arrays). Many
look like residuals from the ARRAY_V5_PLAN sort work that didn't
land on v6+ variants. Re-run after ARRAY_V5_PLAN closes; remaining
residuals are likely SWF6+-specific edge cases (insertion-order
on plain Objects, sortOn with `Array.NUMERIC` flag combinations).

## Recommended fix order

1. **Phase 1 (length as own prop)** — small fix, regression risk
   on AVM1 array tests. Verify with `array_properties` /
   `array_length` battery. Estimate: 1-2 hours.
2. **Phase 2 (apply with Array receiver)** — coordinate with
   FUNCTION_VN Phase 2. Likely solves itself when Function plan
   lands. Estimate: shared; check after Function fix.
3. **Phase 3 (sparse hasOwnProperty)** — small fix, verify with
   AVM1 `array_enumerate`. Estimate: 1 hour.
4. **Phase 4 (sortOn length)** — diagnose, may share root with
   ARRAY_V5_PLAN remaining sortOn work. Estimate: 1-2 hours.
5. **Phase 5 (residual sort/splice/concat)** — wait until ARRAY_V5
   closes, then re-baseline. Estimate: variable.

Total estimate: 3-7 hours assuming FUNCTION_VN Phase 2 and ARRAY_V5
do most of the work. Could be much less.

## Promotion plumbing

`known_failure = true` + `output.fpN.ruffle.txt` sidecars. At 89-94%
line-match, close to threshold; could promote with just Phase 1+3
in some versions.
