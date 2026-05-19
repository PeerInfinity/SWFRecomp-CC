# LoadBitmapTest Plan
<!-- TESTS: misc-ming.all/loading/LoadBitmapTest -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproduction at the current `master` SHA)

<!-- PLAN_META
id: LOADBITMAPTEST_PLAN
status: pending
phases:
  - id: 1
    name: "f.transparent default value (false vs true) for loaded bitmaps"
    status: pending
  - id: 2
    name: "near(f, 85, 85, 0x000000) — pixel value Flash expects mismatch but we match"
    status: pending
  - id: 3
    name: "Detached BitmapData / nonexistent identifiers: __proto__ undefined, typeof undefined"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac)."
related:
  - id: LOADBITMAP_PLAN
    reason: "AVM1 plan (complete). Covers BitmapData.loadBitmap basic functionality. This Gnash test exercises edge cases — transparent flag, missing identifiers."
  - id: BITMAP_DATA_PLAN
    reason: "AVM1 plan (complete). Covers BitmapData lifecycle."
blockers: []
status_note: |
  Small test (~17 expected lines). Mostly works (~76% line match)
  but a few edge cases on the transparent default and the
  detached-BitmapData proto chain.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-ming.all/loading/LoadBitmapTest | 13/17 | 76.5% | output_mismatch |

## Failure surface

```
- PASSED: f.transparent  ==  false [LoadBitmapTest.c:120]
+ FAILED: expected: false obtained: true

- FAILED: near(f, 85, 85, 0x000000) [LoadBitmapTest.c:127]
+ PASSED: near(f, 85, 85, 0x000000)            <- we PASS, expected FAILED

- PASSED: c.__proto__  ==  undefined [LoadBitmapTest.c:158]
+ FAILED: expected: undefined obtained: [object Object]

- PASSED: typeof(d)  ==  'undefined' [LoadBitmapTest.c:159]
+ FAILED: expected: 'undefined' obtained: object
```

Four issues, three failures and one "we pass where expected fails":

### A. `f.transparent == false` (Phase 1)

After `BitmapData.loadBitmap(jpegId)`, `transparent` should be
`false` (JPEGs don't have an alpha channel). We default new
BitmapData to `transparent=true`. Need to read the source image
format (JPEG vs PNG-with-alpha vs PNG-without) and set
`transparent` accordingly at loadBitmap time.

### B. `near(f, 85, 85, 0x000000)` PASS-where-expected-FAILED (Phase 2)

We are *more correct* than Flash here — Flash returns a slightly
off-from-black value at that sample point (JPEG decoder artifact?),
test expects FAILED. We return clean 0x000000 and PASS.

Either:
- Add a "near is too tight" coercion to match Flash's JPEG decoder
  artifacts (bad idea — we'd be replicating a JPEG decoder bug)
- Verify Ruffle also passes here; if so, subset-match-eligible
  candidate.

### C. `c.__proto__ == undefined` after BitmapData on nonexistent
identifier (Phase 3a)

`var c = BitmapData.loadBitmap("nonexistent")` should return
something with `__proto__ == undefined` (probably a detached/
broken BitmapData). We return a regular BitmapData with full
proto chain. Need to mark failed-load BitmapData objects with
cleared __proto__.

### D. `typeof(d) == 'undefined'` (Phase 3b)

Similar — `var d = ...` for some specific construction returns
undefined in Flash, object in ours.

## Recommended fix order

1. **Phase 1 (transparent default)** — read image format at
   loadBitmap time and set `transparent` per-format. Estimate:
   1 hour.
2. **Phase 3a + 3b (failed-load proto)** — investigate which
   loadBitmap argument types Flash treats as "fail completely"
   (return undefined / broken proto). Estimate: 1-2 hours.
3. **Phase 2 (PASS-where-FAILED)** — diff against ruffle.txt; if
   Ruffle also fails (matches expected), no action — we're a
   subset-violation. If Ruffle also passes, we and Ruffle are both
   subset-eligible. Estimate: 30 min.

Total estimate: 2-4 hours, 1 session. Strong PASS / ruffle_matched
candidate.

## Promotion plumbing

`known_failure = true` + `output.ruffle.txt`. 76% line match —
close to threshold. Phases 1+3 should clear the test.
