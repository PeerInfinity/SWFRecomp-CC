# TextSnapshotTest Plan
<!-- TESTS: misc-ming.all/TextSnapshotTest -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproduction at the current `master` SHA)

<!-- PLAN_META
id: TEXTSNAPSHOTTEST_PLAN
status: pending
phases:
  - id: 1
    name: "setSelected(start, end, true) records selection in internal state"
    status: pending
  - id: 2
    name: "getSelected(start, end) reads back the selected range"
    status: pending
  - id: 3
    name: "getSelectedText() returns concatenated text from selected ranges"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac)."
related:
  - id: TEXTSNAPSHOT_PLAN
    reason: "AVM1 plan (complete) — 112/112 PASS. Covers TextSnapshot construction + basic methods. This Gnash test exercises setSelected/getSelected/getSelectedText specifically, which were partially-implemented in AVM1 work."
  - id: GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN
    reason: "AVM1 plan (complete) — TextSnapshot ctor."
blockers: []
status_note: |
  AVM1 TextSnapshot work landed `hitTestTextNearPos`, `getSelected`,
  `getSelectedText`, `getCount` stubs (per CURRENT_STATUS 2026-04-12
  entry). The Gnash test exposes that `setSelected → getSelected`
  round-trip is non-functional (selection isn't actually being
  recorded). Need to actually wire up the selection storage, not
  just return-stub-values.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-ming.all/TextSnapshotTest | 49/132 | 37.1% | output_mismatch |

## Failure surface

After `setSelected(start, end, true)` calls, the test expects:

```
- PASSED: ts.getSelectedText()  ==  ' textZweites TextfeldSome' [TextSnapshotTest.c:159]
+ FAILED: expected: ' textZweites TextfeldSome' obtained:
- PASSED: ts.getSelected(1, 9)  ==  true [TextSnapshotTest.c:164]
+ FAILED: expected: true obtained: false
- PASSED: ts.getSelected(-4, 10)  ==  true [TextSnapshotTest.c:165]
+ FAILED: expected: true obtained: false
```

`getSelected` always returns false; `getSelectedText` returns empty.
The AVM1-work-era stub returns "" / 0 / false unconditionally; the
test exercises real round-trip behavior.

## Approach

Implement actual selection storage on TextSnapshot:

1. **Selection state.** Each TextSnapshot tracks which character
   ranges are selected. Simplest model: a bit per char (BitSet-style)
   indexed by absolute char offset across all child TextField glyphs.

2. **setSelected(start, end, [selected])** — sets the bits.
   Negative `start` should clamp to 0; out-of-range `end` clamps to
   the total char count. The flag arg defaults to `true`.

3. **getSelected(start, end)** — returns true iff *any* char in
   [start, end] is selected. Note the Gnash test asserts true
   for `getSelected(-4, 10)` even when the actual selected range
   starts at index 1 — so the predicate is "overlaps any selected
   range", not "fully contained in".

4. **getSelectedText([includeLineEndings])** — concatenates the
   chars at selected positions. `includeLineEndings=true` inserts
   `\n` between TextField boundaries; false (default) just
   concatenates without separators.

## Recommended fix order

1. **Phase 1 (storage + setSelected)** — small addition to the
   TextSnapshot native struct. Estimate: 1-2 hours.
2. **Phase 2 (getSelected)** — bitset overlap query. Estimate:
   30 min.
3. **Phase 3 (getSelectedText)** — walk + concat. Estimate: 1-2
   hours, including the includeLineEndings flag.

Total estimate: 3-5 hours, 1-2 sessions. Plausible single-session
landing.

## Promotion plumbing

`known_failure = true` + `output.ruffle.txt` sidecar.
