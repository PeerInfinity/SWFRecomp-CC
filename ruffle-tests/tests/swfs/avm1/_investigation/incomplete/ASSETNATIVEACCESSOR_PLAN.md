# ASSetNativeAccessor + ConvolutionFilter Plan

<!-- TESTS: assetnativeaccessor, assetnativeaccessor_ids -->

<!-- PLAN_META
id: ASSETNATIVEACCESSOR
status: pending
phases:
  - id: 1
    name: "Implement ASSetNativeAccessor builtin (paired ASnative getter/setter binding)"
    status: pending
  - id: 2
    name: "ConvolutionFilter (class 1109) ASnative dispatch table"
    status: pending
  - id: 3
    name: "Verification battery"
    status: pending
dependencies: []
blockers: []
-->

## Problem

CI snapshot at `c5994ec1` (2026-05-05) shows 2 new filtered failures —
the only filtered failures in the AVM1 suite. Both are upstream-added
tests for the `ASSetNativeAccessor` builtin and the
ConvolutionFilter (class 1109) `ASnative` dispatch.

| Test | Status | Notes |
|------|--------|-------|
| `assetnativeaccessor` | output_mismatch | exercises the same comma-separated, version-prefixed binding scheme as `assetnative`, but installs paired `addProperty` getter/setter pairs instead of plain functions |
| `assetnativeaccessor_ids` | output_mismatch | smaller variant — checks that the `ASnative` indices used by the accessors are correct |

`ASSetNative` was implemented during 2026-05-04 sessions, which fixed
`assetnative` (81/81 PASS) and `assetnative_ids` (10/10 PASS) and
side-promoted Gnash `Global-v6/v7/v8`. The accessor variant was
intentionally deferred because it depends on (a) virtual-property
infrastructure already present (addProperty / getter / setter), (b) a
known calling convention that is not yet wired up.

## Reference behavior

`ASSetNativeAccessor(target, major, props, minor=0)`:

- Splits `props` (after `toString` coercion) on `,`. Strips an optional
  leading version-flag digit (`'1'`, `'6'`, `'7'`, `'8'`, `'9'`, or
  `"10"`) on each name (same as `ASSetNative`).
- For each non-empty name at position `i`:
  - getter = `ASnative(major, minor + 2*i)`
  - setter = `ASnative(major, minor + 2*i + 1)`
  - bind the pair via `addProperty(name, getter, setter)` on `target`
- Empty-name slots still consume an index (i.e. position counter
  increments per comma).
- Version-gating mirrors `ASSetNative`: name prefix `'7'` means the
  accessor is only "active" under SWF 7+. Under lower SWF versions, the
  name is still installed but the accessor is bound to a value rather
  than a getter/setter pair (the same three-way split documented in
  `assetnative`).

`ASnative(class_id, index)` for class 1109 (ConvolutionFilter):

- Read `assetnativeaccessor.swf`'s expected output to enumerate which
  indices need real ConvolutionFilter property accessors. Based on the
  Flash 8 ConvolutionFilter API, expect getters/setters for:
  `matrix`, `matrixX`, `matrixY`, `divisor`, `bias`, `preserveAlpha`,
  `clamp`, `color`, `alpha`. Plus possibly `quality`.
- Each accessor reads/writes a corresponding field on the underlying
  filter object (which is constructed via `new ConvolutionFilter(...)`).
- Pre-existing AVM1 ConvolutionFilter constructor lives in
  `SWFModernRuntime/src/actionmodern/action.c` somewhere in the
  filter-class registry; verify that the ASnative indices used by
  `assetnativeaccessor` match the property layout already present in
  our ConvolutionFilter implementation.

## Phase 1 — `ASSetNativeAccessor` builtin

Implement in the same file/region as `ASSetNative`
(`SWFModernRuntime/src/actionmodern/action.c`, search for
`builtin_assetnative`). Reuse the comma-split + version-flag-prefix
logic; the only behavior delta is the bind step:

```c
// inside the per-name loop:
ASFunction* getter_fn = lookupASNative(major, minor + 2 * position);
ASFunction* setter_fn = lookupASNative(major, minor + 2 * position + 1);
addProperty(target, name, name_len, getter_fn, setter_fn);  // existing helper
```

Where `lookupASNative(class_id, index)` is whichever helper
`builtin_asnative` already uses to resolve `ASnative(c, i)` —
factor it out if not yet shared.

Version-gating sub-cases (matching `ASSetNative`):
- own exists → overwrite with addProperty(getter, setter)
- own absent + inherited → install with the inherited value
- own absent + nothing inherited → install with no-op getter/setter
  (or undefined sentinel)

## Phase 2 — ConvolutionFilter ASnative dispatch

Determine the `(major, minor)` pair the test uses (likely
`(1109, 0)`). Wire up `ASnative(1109, N)` to return a function that
reads/writes the Nth ConvolutionFilter property when invoked on a
ConvolutionFilter instance.

Two implementation styles, pick whichever matches existing native
classes:

(a) **Static table.** Define `g_convolution_filter_native_funcs[]`
indexed by minor; each entry is a pair (getter_fn, setter_fn). When
`ASnative(1109, idx)` fires, return the table entry.

(b) **Dispatcher function.** Single C function that branches on the
minor index, reading/writing the underlying filter struct.

(a) is cleaner if other native classes use the same shape; (b) is
shorter. Look at how `Color`, `Math`, or `flash.geom.Point` handle
ASnative dispatch to pick the matching style.

## Phase 3 — Verification battery

**Required-pass guardrail (must not regress):**

- AVM1: `assetnative` (81/81), `assetnative_ids` (10/10), `asnative_asnew` (34/34 + 34/34), all 9 filter constructor tests (`bitmap_filters`, `displacementmapfilter_*`, plus the existing ConvolutionFilter test path), `add_property`, `watch`, `watch_textfield`.
- Gnash: `Global-v6` (RM), `Global-v7` (PASS), `Global-v8` (PASS), `Number-v6/v7/v8`, `ASnative-v5..v8`.

**Target tests:**

- `assetnativeaccessor` flips MISMATCH → PASS (or RM if Flash-vs-Ruffle disagrees on a sub-line).
- `assetnativeaccessor_ids` flips MISMATCH → PASS.

## Alternative path: defer via `ignored_tests.txt`

If implementation is non-trivial relative to other higher-impact
work, add both tests to `ruffle-tests/ignored_tests.txt`:

```
# assetnativeaccessor* — deferred; needs ASSetNativeAccessor + ConvolutionFilter ASnative dispatch
# Tracked in avm1/_investigation/incomplete/ASSETNATIVEACCESSOR_PLAN.md
assetnativeaccessor
assetnativeaccessor_ids
```

…and document in `ACCEPTED_DIFFS.md` under a new "Implementation
deferred" category. This restores 100% filtered pass rate without
implementation work, at the cost of leaving the feature unimplemented.

## Estimated session budget

- Phase 1: 1–2 hours (clone the comma-split logic from
  `builtin_assetnative`, swap in the addProperty bind path, run the
  AVM1 + Gnash batteries).
- Phase 2: 2–4 hours (depends on whether ConvolutionFilter
  property storage is already field-backed or needs an internal
  struct addition).
- Phase 3: 30 min.

Total: 4–6 hours.

## Why this is the right shape

`ASSetNative` and `ASSetNativeAccessor` share the same comma-split
infrastructure and version-flag prefix conventions; the per-name
binding step is the only delta. Phase 1 reuses 90%+ of the existing
`builtin_assetnative` code, so the implementation cost is small. The
real work is Phase 2 (ConvolutionFilter native indices), which is
ConvolutionFilter-specific and decoupled from the ASSetNativeAccessor
mechanism.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `complete/ASNATIVE_ASNEW_PLAN.md` | ASnative/ASnew implementation. ASSetNativeAccessor depends on ASnative dispatch. |
| `from_gnash/_investigation/CURRENT_STATUS.md` "ASSetNative implementation" | Describes ASSetNative; this plan is its accessor-pair sibling. |
| `complete/BITMAP_FILTERS_PLAN.md` | Bitmap filter infrastructure. ConvolutionFilter is one of the filter classes. |
