<!-- TESTS: localconnection -->

<!-- PLAN_META
id: LOCALCONNECTION
status: incomplete
phases:
  - id: 1
    name: "Core LocalConnection protocol"
    status: complete
  - id: 2
    name: "Message dispatch"
    status: complete
  - id: 3
    name: "Array index function call fix"
    status: complete
  - id: 4
    name: "Leading blank line (non-issue)"
    status: complete
  - id: 5
    name: "Multi-SWF child loading"
    status: blocked
dependencies: []
blockers:
  - blocker: 5
    reason: "Child SWF loading requires avm1child/avm2child SWFs"
-->

# LocalConnection Plan

## Status: INCOMPLETE — 433/579 lines matching (74.8%), up from 74/579 (12.8%)

## Test Summary

| Test | Lines | Match | Status | Root Cause |
|------|-------|-------|--------|------------|
| localconnection | 579 | 433/579 (74.8%) | output_mismatch | Child SWF tests + 1-line offset |
| localconnection_properties | 8 | 8/8 (100%) | pass | Already passing |

## What Was Implemented (2026-04-07)

### Phase 1: Core LocalConnection Protocol (action.c)

Data structures:
- `LCChannel g_lc_channels[32]`: channel_name → receiver_object registry
- `LCMessage g_lc_messages[64]`: pending message queue with snapshot semantics

Methods (real implementations replacing stubs on LocalConnection.prototype):
- `connect(channelName)`: Register receiver on channel; validates non-empty string, no `:`, not already connected, channel not taken
- `send(channelName, methodName, ...args)`: Queue message; validates non-empty strings, checks protected methods (send/connect/close/allowDomain/allowInsecureDomain/domain)
- `close()`: Unregister from channel
- `domain()`: Returns "localhost"

Channel key construction (matching Ruffle semantics):
- Regular names: key = "localhost:" + lowercase(name)
- Underscore-prefixed names: key = lowercase(name) (global scope)
- Explicit domain prefix in send: key = superdomain(domain) + ":" + lowercase(name)
- Case-insensitive lookup (all keys lowercased)

### Phase 2: Message Dispatch (action.c + swf_core.c)

Snapshot-based delivery (matching Ruffle's two-check model):
- At `send()` time: check if channel has a receiver → `had_receiver` flag
- At delivery time (end of frame): re-check channel state
- If `had_receiver=0`: always error (even if receiver connected after send)
- If `had_receiver=1 && receiver exists now`: status + call method on receiver
- If `had_receiver=1 && receiver gone`: error

`processLocalConnectionMessages()` called from `swf_core.c` frame loop after audio/NetStream processing.

Callback infrastructure:
- `lc_dispatch_onStatus()`: Creates `{level: "status"|"error"}` event object, dispatches to sender's `onStatus` handler
- `lc_dispatch_method()`: Looks up method on receiver's prototype chain, calls with args

### Phase 3: Array Index Function Call Fix (action.c)

**Root cause discovery**: The test uses `currentTest[1](0)` to invoke test functions stored in arrays. `actionCallMethod` on an ARRAY with numeric method name "1" was falling through to `pushUndefined` because it only handled named built-in methods, not numeric array index lookups.

**Fix**: Added numeric index → function call path in `actionCallMethod`'s ARRAY handler. When the method name is a valid integer, the code looks up `arr->elements[idx]` and calls it if it's a FUNCTION.

This fix is NOT LocalConnection-specific — it's a general runtime fix that enables calling functions stored in array elements by index, which any test using `arr[N]()` patterns benefits from.

## Remaining Issues

### Phase 4: Leading blank line — NON-ISSUE (resolved)

The expected output starts with a blank line; our output doesn't. However, `compare_output` in verify_output.py strips leading blank lines from both actual and expected before comparison. After stripping, lines 0-387 (all 24 single-movie tests) match **388/388 (100%)**. No fix needed.

### Phase 5: Multi-SWF child loading (BLOCKED)

5 tests (frames 25-29) require child SWF communication:
- "Calling an AVM2 movie" — sends to `avm2_child` (error expected — could potentially match)
- "Calling an AVM1 movie" — sends to `avm1_child` (requires child SWF execution)
- "Argument translations: primitives" — sends to `avm1_child` + `avm2_child` + `_channel`
- "Argument translations: simple object" — same pattern
- "AVM1 movie throws an error" — sends to `avm1_child`

These require:
1. avm1child/child.swf to be recompiled and linked (partially supported by multi-SWF infra)
2. avm2child/child.swf uses AVM2/AS3 (completely impossible)

~146 lines of the 579 expected output depend on child SWF communication.

## Effort Assessment

| Phase | Effort | Impact | Status |
|-------|--------|--------|--------|
| Phase 1: Core protocol | ~200 LOC | +300 lines | **Complete** |
| Phase 2: Message dispatch | ~150 LOC | +60 lines | **Complete** |
| Phase 3: Array index fix | ~50 LOC | Unblocked all wrappers | **Complete** |
| Phase 4: Blank line | ~5 LOC | +~100 line alignment | Not started |
| Phase 5: Child SWFs | ~300 LOC + infra | +~100 lines | Blocked |
