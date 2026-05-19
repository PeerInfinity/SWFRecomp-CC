# PrototypeEventListeners Plan
<!-- TESTS: misc-ming.all/PrototypeEventListeners -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproduction at the current `master` SHA)

<!-- PLAN_META
id: PROTOTYPEEVENTLISTENERS_PLAN
status: pending
phases:
  - id: 1
    name: "Prototype-level mouse/key event handlers (MovieClip.prototype.onMouseDown, etc.)"
    status: pending
  - id: 2
    name: "_global.onMouseDown / _global.onKeyDown firing"
    status: pending
  - id: 3
    name: "Mouse/Key broadcaster dispatch to MovieClip-prototype listeners"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac)."
related:
  - id: MOUSE_EVENTS_PLAN
    reason: "AVM1 plan (complete). Covers instance-level mouse handlers. This Gnash test exercises *prototype-level* handlers — a different code path."
  - id: MOUSE_EVENTS_ADVANCED_PLAN
    reason: "AVM1 plan (complete). 7 tests. May overlap with prototype dispatch."
blockers: []
status_note: |
  Substantial feature work per SUBTESTS_NEWLY_VISIBLE_TRIAGE.
  Test installs onMouseDown handler on `MovieClip.prototype` and
  on `_global` — both expected to fire when the mouse is clicked
  anywhere. Our Mouse/Key broadcaster doesn't walk the
  MovieClip.prototype chain or _global for prototype-defined
  handlers.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-ming.all/PrototypeEventListeners | 1/32 | 3.1% | output_mismatch |

## Failure surface

Expected output enumerates `onMouseDown` firings across multiple
listeners installed via:

```
MovieClip.prototype.onMouseDown = function() { ... };
_global.onMouseDown = function() { ... };
clip1.onMouseDown = ...;  // explicit instance
clip2.onMouseDown = ...;
Dejagnu.onMouseDown = ...;
Dejagnu.instance1.onMouseDown = ...;
```

Expected: `_level0.clip2.onMouseDown`, `_level0.clip1.onMouseDown`,
`_global.onMouseDown`, `_level0.Dejagnu.instance1.onMouseDown`,
`_level0.Dejagnu.onMouseDown` — all five fire per click.

Actual: zero fire. We emit `countMC == 0` instead of the expected
sequence of handler-fired traces.

## Approach

The basic mouse-event infrastructure works (AVM1 mouse tests all
pass), but the broadcaster dispatch doesn't reach handlers attached
at:

1. **MovieClip.prototype level.** Every MovieClip instance should
   inherit-and-fire `onMouseDown` from `MovieClip.prototype` (when
   set on the prototype). Verify whether our broadcaster
   `dispatch_mouse_event` walks the receiver's `__proto__` chain.

2. **_global level.** Flash also fires `_global.onMouseDown` once
   per click. Likely just need to add `_global` to the
   broadcaster's listener set at registration time.

3. **Dejagnu (a child MovieClip).** The test's child Dejagnu
   MovieClip and its `instance1` child both have onMouseDown
   handlers. Our broadcaster may only walk root MCs, not nested.

The 14-character expected `_level0.clip2.onMouseDown` traces are
emitted from inside the handler via `trace("..." + this);` — so
the bug is upstream: we never invoke the handler at all.

## Recommended fix order

1. **Phase 1 diagnosis.** Add tracing to `dispatch_mouse_event`
   (or equivalent) and run the test. Identify which path filters
   out prototype/global/nested listeners. Estimate: 1-2 hours.
2. **Phase 1 fix: prototype-chain walk.** Estimate: 2-3 hours.
3. **Phase 2 fix: _global listener registration.** Estimate:
   1 hour.
4. **Phase 3 fix: nested MC listener inclusion.** Estimate: 1-2
   hours.

Total estimate: 5-8 hours, 1-2 sessions. Test will jump from 3%
to most-of-the-way once dispatch reaches the handlers.

## Promotion plumbing

`known_failure = true` + `output.ruffle.txt` sidecar. Currently
at 1/32 — Ruffle likely diverges similarly given prototype-event
dispatch is implementation-defined; check subset-match eligibility
during Phase 1 diagnosis.
