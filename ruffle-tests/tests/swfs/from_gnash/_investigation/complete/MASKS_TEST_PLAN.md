# masks_test Plan
<!-- TESTS: misc-ming.all/masks_test -->

Last updated: **2026-09-18 (s20) — CLOSED at `ruffle_matched`.**

> **CLOSING NOTE (s20).** This plan's entire premise was wrong, in two
> independent ways, and it is kept only as a record of that.
>
> 1. **Phase 1 was never needed.** The plan calls for "synthetic input
>    infrastructure (auto-keypress)" — a `verify_output.py` change. The test
>    never needed it: `masks_test/input.json` **exists** and drives all four
>    `- Press any key to continue -` gates. The `related:` note below asserting
>    "masks_test specifically does NOT have input.json" is false and was
>    probably false when written.
> 2. **The real blockers were runtime bugs.** s19 fixed `actionNextFrame`'s
>    deferred-goto arm on a stopped root; s20 fixed a one-line AVM1 `hitTest`
>    bounding-box arity bug (we skipped MASKER clips on the bounds arity, but
>    Ruffle only skips them on the SHAPE arity). That closed the row.
>
> The 28/175 baseline in the table below is four months stale — the row went
> 28 → 124/175 (s17-s19) → `ruffle_matched` (s20).
>
> Full account: `SWFRecompDocs/plans/session20-fanout-reports/w2-masks-hittest-report.md`.

<!-- PLAN_META
id: MASKS_TEST_PLAN
status: complete
phases:
  - id: 1
    name: "Synthetic input infrastructure: auto-keypress for tests with 'Press any key' prompt"
    status: cancelled  # never needed: masks_test/input.json exists
  - id: 2
    name: "Once input infrastructure lands: re-baseline masks_test against post-keypress expected output"
    status: cancelled  # superseded: closed by runtime fixes in s19+s20
dependencies: []
related:
  - id: INPUT_EVENTS_PLAN
    reason: "AVM1 input events plan (complete) covers explicit input.json. masks_test specifically does NOT have input.json — needs a synthetic-default approach."
blockers:
  - reason: "Phase 1 is infrastructure work (verify_output.py change), not a runtime fix. Could go in parallel with any other plan but must land before Phase 2 can be tested."
status_note: |
  Test stops at "Press any key to continue" then waits forever
  (no input.json exists). All AVM1 input-driven tests provide
  input.json; this Gnash test was authored against a runner that
  auto-injects keystrokes. Need verifier infrastructure to either
  auto-generate input.json when a test detects "Press any key" or
  add a CLI flag injecting default keypress.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-ming.all/masks_test | 28/175 | 16.0% | output_mismatch |

## Failure surface (from REMAINING_TAIL_TRIAGE)

Output stops at:

```
Placed staticmc2 (red), ... DisplayObjects
Placed dynamicmc2 (blue), ... DisplayObjects
 - Press any key to continue -
<end of actual>
```

The test waits for a keyboard event before continuing into the
mask assertions. **No `input.json` exists in the test directory**.
In Flash this would block forever — Gnash's testrunner apparently
auto-injects a default keypress.

## Approach

Phase 1 — infrastructure work (NOT a runtime fix):

Two options:

1. **Auto-generate input.json** at test build time when the
   expected `output.txt` contains a "Press any key to continue"
   prompt. `verify_output.py` would scan `output.txt` for the
   sentinel string and synthesize an input.json with a single
   keypress event scheduled at a frame past the prompt.

2. **CLI flag**. Add `--auto-keypress` to `verify_output.py` that
   injects a keypress at frame N (e.g. the last frame before
   `quit_swf`). Per-test opt-in via test.toml.

Option 1 is more invasive but covers any future "Press any key"
test. Option 2 is contained but needs per-test config.

Phase 2 — after Phase 1: re-run masks_test, see what the
post-keypress assertions look like. Almost certainly more bugs
underneath (it's a mask test, after all). Re-baseline and
characterize.

## Recommended fix order

1. **Phase 1** — infrastructure decision + implementation. Estimate:
   2-3 hours (mostly in `verify_output.py`).
2. **Phase 2** — re-baseline. Probably 30 minutes to discover the
   post-keypress diff size, then a follow-up plan to address the
   mask-specific assertions (estimate unknown without seeing them).

Phase 1 should be paired with confirming that no other tests
silently depend on the absence of input infrastructure — i.e.
make sure introducing auto-keypress doesn't regress tests that
expect no input.

## Promotion plumbing

Test has `known_failure = true` + `output.ruffle.txt` sidecar.
Without Phase 1 there's no way to even reach the mask assertions,
so promotion is gated on Phase 1.
