# LoadBitmapTest Plan
<!-- TESTS: misc-ming.all/loading/LoadBitmapTest -->

Last updated: 2026-05-19 (RESOLVED → ruffle_matched. The decisive
fix was Phase 3a: loadBitmap now derives the result's `__proto__`
from the receiver object's `prototype` property when called as a
method of a plain object. Phases 1/2/3b were re-classified as
Flash-vs-Ruffle divergences — Ruffle fails the same lines, so the
test auto-promotes via subset-match. See "Resolution" below.)

<!-- PLAN_META
id: LOADBITMAPTEST_PLAN
status: complete
phases:
  - id: 1
    name: "f.transparent default value (false vs true) for loaded bitmaps"
    status: wont_fix
  - id: 2
    name: "near(f, 85, 85, 0x000000) — pixel value Flash expects mismatch but we match"
    status: wont_fix
  - id: 3
    name: "Detached BitmapData / nonexistent identifiers: __proto__ undefined, typeof undefined"
    status: complete
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

## Resolution (2026-05-19) → ruffle_matched

The test resolves to the `fp11` variant (`output.fp11.txt`, highest
`player_options.version` in `test.toml`). Pre-fix our diff against
expected was `{4, 9, 11, 12}`; Ruffle's diff (`output.fp11.ruffle.txt`)
is `{4, 9, 12}`. Line 11 (`c.__proto__ == undefined`) was the only
ours-only diff blocking subset-match promotion — lines 4/9/12 are all
Flash-vs-Ruffle divergences that Ruffle fails too.

**Fix (Phase 3a) — `bitmapDataLoadBitmap` in `action.c`.** Gnash's
`LoadBitmapTest.c` aliases the static method onto a plain object and
calls it as a method:

```js
o = {};
o.func = flash.display.BitmapData.loadBitmap;
backup = flash.display.BitmapData;
c = o.func('img1');               // c.__proto__ should be undefined
o.prototype = backup.prototype;
e = o.func('img1');               // e.__proto__ should be backup.prototype
```

Flash sets the loaded bitmap's `__proto__` to **`thisObj.prototype`**,
where `thisObj` is the receiver of the call — not a hardcoded
`BitmapData.prototype`. For `c` the receiver `o` has no `prototype`
property yet, so `c.__proto__` is undefined; for `e` it is
`backup.prototype`.

`bitmapDataLoadBitmap` previously always set `__proto__` to
`g_bitmapdata_prototype`. It now:
- recognises the genuine static call by pointer-comparing `this_obj`
  against `g_bitmapdata_ctor_own_props` (the BitmapData constructor's
  `own_props` bag, which our method dispatch passes as `this` for
  `BitmapData.loadBitmap(...)`) — keeps the default prototype;
- when called as a method of any other plain object
  (`g_call_this_type == ACTION_STACK_VALUE_OBJECT`), reads that
  object's `prototype` own-property and uses it as `__proto__`,
  leaving `__proto__` unset when it is absent/undefined.

The bare-call case (`d = func('img1')`, `this_obj == NULL`) keeps the
default prototype unchanged — `d` stays an object both before and
after (Ruffle agrees, line 12 stays a shared diff).

**Phases 1 / 2 / 3b — won't fix (Flash-vs-Ruffle divergences).**
- Line 4 (`f.transparent == false`): Ruffle returns `true` too.
- Line 9 (`near(f,85,85,0x000000)`): Flash's JPEG decoder produces a
  slightly off-black sample; we and Ruffle both return clean black
  and "pass" where Flash expects FAILED.
- Line 12 (`typeof(d) == 'undefined'`): `d` is an object in both
  Ruffle and our runtime.
All three are inside Ruffle's diff set, so they do not block
subset-match promotion.

No regressions: 6-test BitmapData battery (`bitmap_data`,
`bitmap_data_colortransform`, `bitmap_data_compare`,
`bitmapdata_channels`, `bitmap_filters`,
`bitmapdata_applyfilter_colormatrix`) all PASS — the change is inert
for the static-call path every other test uses.
