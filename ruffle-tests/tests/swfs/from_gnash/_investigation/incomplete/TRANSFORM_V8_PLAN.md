# Transform-v8 Investigation Plan
<!-- TESTS: Transform-v8 -->

Last updated: 2026-05-20 (Phases 4 + 6 landed → Transform-v8 promoted
to `ruffle_matched`. Our diff against `output.fp10.txt` is now a
strict subset of Ruffle's, so the test auto-promotes. Phases 1/2/3/5
remain pending but are shared diffs with Ruffle — they no longer
block effective pass.)

<!-- PLAN_META
id: TRANSFORM_V8_PLAN
status: in_progress
phases:
  - id: 1
    name: "colorTransform multiplier coercion (alphaMultiplier=-128, etc.)"
    status: pending
  - id: 2
    name: "Standalone Transform object: matrix/colorTransform/pixelBounds return undefined"
    status: pending
  - id: 3
    name: "mc.transform = T propagates back to mc._xscale/_yscale/_rotation"
    status: pending
  - id: 4
    name: "transform.matrix resolves after `delete mc` (instance-name fallback)"
    status: completed
  - id: 5
    name: "concatenatedMatrix computation"
    status: pending
  - id: 6
    name: "Matrix toString float precision (exact-matrix cache)"
    status: completed
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac); Transform-v8 became visible at that point."
related:
  - id: MATRIX_TEST_SKEW_PLAN
    reason: "Phase 6 (matrix toString float drift) is the same root cause as the misc-ming `matrix_test` (complete/MATRIX_TEST_SKEW_PLAN.md): we round-trip via xscale/yscale/rotation and lose precision. Apply the same skew-field fix here."
  - id: MOVIECLIP_VN_PLAN
    reason: "Phase 4 (transform.matrix after swapDepths) interacts with the soft/hard reference cluster in MOVIECLIP_VN Phase 6."
blockers: []
status_note: |
  Singleton test; failure surface small (~18 failures over 95
  assertions, 85% line-match). Half the failures collapse to two
  root causes (multiplier coercion, standalone-Transform-returns-
  default). Strong ruffle_matched candidate.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| Transform-v8 | 86/101 | 85.1% | output_mismatch |

After Phases 4 + 6 (2026-05-20, pending CI): **`ruffle_matched`** (91/101
line-match, #passed 89). Our diff against `output.fp10.txt` is
`{27,30,31,33,35,37,62,63,64}` ⊆ Ruffle's `{27,30,31,33,35,37,62,63,64}`
— exact subset, so `verify_output.py::ruffle_subset_match` promotes it.
The 9 residual diffs are all Phases 1/2/3 (colorTransform multiplier
coercion, `flash.geom.* = undefined` getter null-out, `mc.transform = T`
back-propagation) — Ruffle fails the same lines, so they're effective
pass and no longer block promotion.

### Fixes landed (2026-05-20)

- **Phase 6 — exact-matrix cache (Transform.as:199/200/210).** Reading
  `mc.transform.matrix` back after `transform.matrix = new Matrix(...)`
  recomposed from `xscale`/`yscale`/`rotation`/`skew`, losing ~4e-8 of
  precision (`a=3` → `a=2.99999996073879`). Added `exact_m_a..d` +
  `has_exact_matrix` + an `exact_m_{xs,ys,rot,skew}` snapshot to
  `struct MovieClip` (`action.h`). `transformMatrixSetter` stores the
  assigned a/b/c/d **rounded through f32** (Flash stores DisplayObject
  matrices at f32 precision — `(float)0.3 = 0.300000011920929`, matching
  Transform.as:210's expected output) and snapshots the decomposed
  scale/rotation/skew. `getLocalMatrixForMC` returns the exact a/b/c/d
  while the live xscale/yscale/rotation/skew still bit-match the
  snapshot; any later `_xscale`/`_yscale`/`_rotation` setter writes a
  different value, the snapshot stops matching, and the getter
  self-invalidates back to recomposition — no setter-site changes
  needed.

- **Phase 4 — `delete` keeps clip instance-name bindings
  (Transform.as:152/158).** AS-created clips (`createEmptyMovieClip` /
  `duplicateMovieClip` / `attachMovie`) are not in the `ng_display`
  list — they live only in `child_mc_cache`, and the bare name resolves
  via the `var_map` / `dynamic_props` binding. `delete mc` cleared both,
  so `mc` became permanently unresolvable; Flash keeps movie-clip
  instance-name bindings out of the variable namespace's reach
  (`delete <liveClip>` returns false and does nothing). `actionDelete2`
  now skips the deletion (and pushes `false`) when the named variable
  currently holds a live (`!avm1_removed && !pending_removal &&
  depth != INT_MIN`) clip whose own name matches the variable name
  (`swf_name_match`). Scoped to `delete` of a clip-named variable — does
  not touch general variable resolution. (Lines 152 + 158 share this
  single root cause — `_root.removeMovieClip(mc)` at Transform.as:156 is
  a no-op because removeMovieClip ignores its argument and tries to
  remove `_root`.)

  *First attempt* added a broad `child_mc_cache` fallback to
  `actionGetVariable` instead; CI surfaced 3 regressions
  (`avm1/global_swf6_7_8`, `avm1/string_paths_other`,
  `misc-ming.all/displaylist_depths_test9`) where a bare name
  over-resolved to a root child. Reverted in favour of the narrow
  `actionDelete2` guard above.

## Test source

Gnash testsuite/actionscript.all/Transform.as. Tests the
flash.geom.Transform class: matrix get/set, colorTransform get/set,
pixelBounds, concatenatedMatrix, and the propagation between an MC
and its `mc.transform`.

## Failure clusters

### A. colorTransform multiplier coercion (Phase 1)

Lines: 27, 30.

```
- FAILED: expected: "(redMultiplier=1, greenMultiplier=1, blueMultiplier=1, alphaMultiplier=-128, ...)" obtained: (... alphaMultiplier=-126, ...) [./Transform.as:93]
- FAILED: expected: "(redMultiplier=0, greenMultiplier=-128, blueMultiplier=-128, alphaMultiplier=-128, redOffset=-32768, greenOffset=-32768, ...)" obtained: (redMultiplier=0, greenMultiplier=-59, blueMultiplier=64, alphaMultiplier=-98, redOffset=-22962, ...)
```

Setting colorTransform multiplier/offset fields with large or
fractional values should:
- Floor-truncate to int8 for multipliers (range -128..127)
- Floor-truncate to int16 for offsets (-32768..32767)
- Clamp on overflow (the expected `-128` for an out-of-range input)

Our truncation is wrong (-126 vs -128 suggests we drop the fractional
part but get the rounding mode wrong) AND we mismatch on the
`-128, -128, -128` "all-multipliers-clamped" case (we get
`-59, 64, -98`, suggesting different ops on different channels —
possibly we read the input multipliers in the wrong order).

### B. Standalone Transform returns undefined for component getters (Phase 2)

Lines: 31, 33, 35, 37.

```
- PASSED: t.matrix == undefined [./Transform.as:110]
+ FAILED: expected: undefined obtained: (a=1, b=0, c=0, d=1, tx=0, ty=0)
- PASSED: t.colorTransform == undefined [./Transform.as:113]
+ FAILED: expected: undefined obtained: (redMultiplier=1, ...)
- PASSED: t.pixelBounds == undefined [./Transform.as:116]
+ FAILED: expected: undefined obtained: (x=0, y=0, w=0, h=0)
```

A Transform constructed without an MC argument has no underlying
DisplayObject. Its `matrix`, `colorTransform`, `pixelBounds` getters
should return undefined. We return identity / clean default values.

Fix: track whether the Transform is "bound" (has a `display_obj_ref`)
and return undefined from the getters when unbound.

### C. mc.transform = T back-propagation (Phase 3)

Lines: 62, 63, 64.

```
- PASSED: mc2._xscale == 100 [./Transform.as:175]
+ FAILED: expected: 100 obtained: 200
- PASSED: mc2._rotation == 1.5 [./Transform.as:177]
+ FAILED: expected: 1.5 obtained: 0
```

After `mc.transform = transformObject`, the MC's `_xscale`,
`_yscale`, `_rotation` should be derived from the assigned matrix
(decompose matrix → scale/rotation). We leave the old values
unchanged.

### D. mc.transform.matrix after swapDepths (Phase 4)

Lines: 49, 52.

```
- PASSED: mc.transform.matrix.toString() == trans.matrix.toString() [./Transform.as:152]
+ FAILED: expected: trans.matrix.toString() obtained: undefined
- PASSED: Math.round(mc.transform.matrix.b * 10000) == 262 [./Transform.as:158]
+ FAILED: expected: 262 obtained: NaN
```

After `mc.swapDepths(mc2)`, `mc.transform.matrix` should refer to
whatever MC is now at mc's original slot. We return undefined,
suggesting the Transform's display_object reference was severed by
the swap.

### E. concatenatedMatrix (Phase 5)

Lines: 74, 75, 76 (already FAILED on both sides — both expected and
actual fail; check if our diff is subset of Ruffle's).

```
  FAILED: nearly_equal(conc1.transform.concatenatedMatrix, 1, 0, 0, 1, 39.75, 2)
```

We don't compute `concatenatedMatrix` (the matrix accumulated from
root → this MC). Both expected and actual fail on these lines, so
this is likely already Ruffle-matched and counts as effective pass.
Verify diff overlap before doing work.

### F. Matrix toString float precision (Phase 6)

Lines: 70, 71, 73.

```
- PASSED: mc.transform.matrix.toString() == "(a=3, b=0.5, c=0.5, d=2, tx=0, ty=1)"
+ FAILED: ... obtained: (a=2.99999996073879, b=0.499999994913854, c=0.500000019451254, d=2.00000007157344, ...)
```

Float drift on round-trip through xscale/yscale/rotation
decomposition. Same root cause as `matrix_test` in misc-ming
(plan complete: `MATRIX_TEST_SKEW_PLAN.md`). Apply the same skew-
field-on-MovieClip fix to preserve the assigned matrix without
re-deriving via decompose/recompose.

## Recommended fix order

1. **Phase 2 (standalone Transform → undefined)** — simple flag,
   resolves 4 failures. Estimate: 30 min.
2. **Phase 1 (multiplier/offset clamping)** — diagnose the
   wrong-truncation pattern (probably bad signed→unsigned cast).
   Estimate: 1-2 hours.
3. **Phase 6 (matrix float precision)** — apply MATRIX_TEST_SKEW
   pattern. Estimate: 1-2 hours (the work is partly already done in
   the AVM1 codebase if MATRIX_TEST_SKEW_PLAN reused that).
4. **Phase 3 (back-propagation to _xscale/_yscale/_rotation)** —
   matrix decompose on assignment. Estimate: 1-2 hours.
5. **Phase 4 (swapDepths preserves Transform binding)** — small
   ref-update fix. Estimate: 1 hour.
6. **Phase 5 (concatenatedMatrix)** — verify it's ACCEPTED_DIFFS-
   eligible first; if so, document. If not, ~3 hours. Estimate:
   30 min decision + maybe 3 hours fix.

Total estimate: 4-9 hours, 1-3 sessions.

## Promotion plumbing

`known_failure = true` + `output.fp9-18.ruffle.txt` sidecar. At 85%
line-match, only need ~10 lines fixed before subset-match promotes.
