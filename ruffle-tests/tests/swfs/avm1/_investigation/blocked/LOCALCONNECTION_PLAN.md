<!-- TESTS: localconnection -->
# LocalConnection Plan

## Status: BLOCKED — requires full IPC protocol implementation + multi-SWF child loading

## Test Summary

| Test | Lines | Match | Status | Root Cause |
|------|-------|-------|--------|------------|
| localconnection | 579 | 74/579 (13%) | output_mismatch | LocalConnection API is stub-only |

The 74 "matching" lines are all blank separator lines — zero actual functionality works.

## What the Test Does

Source: `~/CC/ruffle/tests/tests/swfs/avm1/localconnection/`

This is a comprehensive test of `LocalConnection`, Flash's inter-movie IPC mechanism.
The test:

1. Creates three `LocalConnection` instances: `receiver`, `custom` (a subclass via
   `CustomLocalConnection extends LocalConnection`), and `sender`
2. Loads two child SWFs: `avm2child/child.swf` into `_level2`, `avm1child/child.swf`
   into `_level3` — these are separate SWF movies that communicate via LocalConnection
3. Runs ~30 sub-tests across 300 frames, testing:
   - `connect(channelName)` — registers a receiver on a named channel (returns bool)
   - `send(channelName, methodName, ...args)` — sends a message to a channel (returns bool)
   - `close()` — disconnects from a channel
   - `onStatus` callback — fires with `{level: "status"}` or `{level: "error"}`
   - `domain()` — returns the connection domain string
   - Channel exclusivity (only one receiver per channel)
   - Argument serialization (primitives, objects, nested objects, arrays)
   - Cross-AVM communication (AVM1 ↔ AVM2 via LocalConnection)
   - Receiver method dispatch (calling arbitrary methods on the receiver object)
   - Error handling (sending to nonexistent channels, sending after close)
   - Timing (messages delivered on next frame, not synchronously)

## Current State of Implementation

The runtime has:
- `LocalConnection` constructor stub (creates object with `native_type = NATIVE_LOCALCONNECTION`)
- Prototype with stub methods: `connect`, `send`, `close`, `domain`, `isPerUser`
- These stubs do nothing — they don't maintain any state or dispatch any callbacks

## What Would Be Needed

### Phase 1: Core LocalConnection Protocol (~200 lines)

```
Data structures:
- Channel registry: maps channel_name → receiver_object
- Pending message queue: (channel, method_name, args[], sender_for_onStatus)
- Max channels: 32, max pending messages: 64

Methods:
- connect(channelName): register this object on channel, return true/false
- send(channelName, methodName, ...args): queue message, return true
- close(): unregister from channel
- domain(): return "localhost" (or configured domain)
```

### Phase 2: Message Dispatch (~100 lines)

Messages are delivered on the NEXT frame (not synchronously):
- After frame scripts execute, process pending message queue
- For each message: look up channel → find receiver → call methodName on receiver
- Fire `onStatus` on sender with `{level: "status"}` (success) or `{level: "error"}` (no receiver)
- Argument passing: args are passed directly (no AMF serialization needed for same-VM)

### Phase 3: Multi-SWF Child Loading (BLOCKER)

The test loads `avm1child/child.swf` and `avm2child/child.swf` into `_level3` and
`_level2`. These child SWFs contain their own LocalConnection receivers. Several
sub-tests verify cross-movie communication:
- Parent sends to child's channel
- Child sends to parent's channel
- AVM2 child communication (completely impossible — we only support AVM1)

The child SWF loading infrastructure (`actionGetURL` → `findMovieEntry`) requires
the child SWFs to be registered as `MovieEntry` records at compile time, which is
partially supported for multi-SWF tests. However:
- The avm2child is an AVM2/AS3 SWF — we cannot execute it at all
- The avm1child would need to be recompiled and linked into the test binary

### Phase 4: Advanced Features

- `allowDomain`/`allowInsecureDomain` security callbacks
- AMF-style argument serialization for cross-VM communication
- `isPerUser` property (per-user vs system-wide channels)

## Difficulty Assessment

**Not feasible** for full pass. The test has 579 expected lines spanning 30+ sub-tests.
Even implementing the core protocol (Phases 1-2) would only cover the single-movie
sub-tests. The multi-SWF and cross-AVM sub-tests (Phase 3) require child SWF loading
infrastructure that is partially blocked, and AVM2 execution which is completely impossible.

Rough line estimates if Phases 1-2 were implemented:
- ~200 of 579 lines might match (single-movie channel management + onStatus callbacks)
- The remaining ~380 lines involve child SWFs or advanced features

## Blockers

1. **Multi-SWF child loading**: avm1child/child.swf needs recompilation + linking
2. **AVM2 execution**: avm2child/child.swf is AS3 — completely impossible
3. **Message timing**: frame-boundary delivery semantics need integration with frame loop
4. **Large implementation surface**: ~300 lines of new code for partial coverage

## Recommendation

**Do not implement.** The effort-to-value ratio is very poor:
- ~300 lines of new code for Phase 1+2
- Would only increase match from 74/579 to ~200/579 (~35%)
- Still would not pass the test
- LocalConnection is rarely used in practice (niche IPC feature)
- Consider adding to `ignored_tests.txt` if the 13% match rate is acceptable
