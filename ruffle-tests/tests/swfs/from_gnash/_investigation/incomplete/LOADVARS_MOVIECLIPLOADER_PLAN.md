# LoadVars + MovieClipLoader Plan
<!-- TESTS: LoadVars-v6, LoadVars-v7, LoadVars-v8, MovieClipLoader-v7, MovieClipLoader-v8 -->

Last updated: 2026-04-17
Status: NOT STARTED — 5 tests, ~40%-28% line match

---

## Overview

Two AS2 loading classes share infrastructure for network I/O and progress
event dispatch:

- `LoadVars` — loads URL-encoded name/value pairs from a URL into an object.
- `MovieClipLoader` — loads an external SWF into a target MovieClip and
  emits `onLoadStart`, `onLoadProgress`, `onLoadComplete`, `onLoadInit`,
  `onLoadError` events.

Our trace-only test harness doesn't perform real HTTP. For these tests to
match Flash's output, we need to stub the network layer and emit the same
event sequence and payloads.

## Current Line Match

| Test | Match | Expected | Diffs |
|------|-------|----------|-------|
| LoadVars-v6 | 61 / 152 | — | ~91 |
| LoadVars-v7 | 61 / 152 | — | ~91 |
| LoadVars-v8 | 61 / 152 | — | ~91 |
| MovieClipLoader-v7 | 46 / 165 | — | ~119 |
| MovieClipLoader-v8 | 46 / 165 | — | ~119 |

## Root Cause

Tests call `load()` and then rely on events firing. Our stubs return
`false`/`undefined` and never fire events, so all subsequent check lines
fail.

## Approach

Tests don't need *real* HTTP — the Gnash test suite runs entirely offline,
using local files and expected outputs crafted to match Flash's behavior
when the network call **fails**. Inspect `output.txt` to see whether each
test expects success (data available) or failure (onLoadError fires).

Two sub-cases:

### Case A — tests check synchronous state
Some LoadVars lines check `typeof(lv.foo)`, `lv.toString()`, etc. without
any `onData` callback. Those only need the class surface (properties,
`addRequestHeader`, `getBytesLoaded`, etc.) and should pass without
touching the network.

### Case B — tests check event ordering
The `load()` call must schedule async callbacks that fire on subsequent
frames. We need a deterministic "load-failed" pipeline:
1. `load()` returns true (or false if URL invalid).
2. Next tick: `onLoadStart` fires (for MCL).
3. Next tick: `onLoadError` fires with `"URLNotFound"`.

This matches the behavior Flash exhibits when the URL is unreachable, which
is what Gnash's CI assumes.

## Phases

### Phase 1 — LoadVars static state
- Register `load`, `send`, `sendAndLoad`, `decode`, `addRequestHeader`,
  `getBytesLoaded`, `getBytesTotal`, `onData`, `onLoad` on
  `LoadVars.prototype` as own properties.
- `toString()` returns URL-encoded `name=value&...` of the object's own props.
- `decode("a=1&b=2")` splits and assigns own properties.
- Expected impact: ~40 lines per LoadVars test.

### Phase 2 — LoadVars async failure path
- `load(url)` schedules a one-tick-deferred `onData(undefined)` call, which
  then triggers `onLoad(false)`.
- Use the existing setInterval/timer infrastructure to defer by one tick.
- Expected impact: ~30 lines per LoadVars test.

### Phase 3 — MovieClipLoader static state
- `new MovieClipLoader()` creates an object with `addListener`,
  `removeListener`, `getProgress`, `loadClip`, `unloadClip`,
  `getBytesLoaded`, `getBytesTotal` as own methods.
- Listener array: store on the MCL instance.
- Expected impact: ~40 lines per MCL test.

### Phase 4 — MovieClipLoader async failure path
- `loadClip(url, target)` schedules the `onLoadStart` then `onLoadError`
  sequence.
- Listener dispatch order: MCL listeners are called in addListener order.
- Expected impact: ~70 lines per MCL test.

### Phase 5 — Success path (optional)
If any test expects successful load (check `output.txt`), we'd need a
minimal local-file loader. Probably out of scope — document under
`ACCEPTED_DIFFS.md` if applicable.

## Implementation Notes

- The "one-tick-deferred" callback mechanism can reuse the timer
  infrastructure (`setInterval(cb, 0)` fires once per tick).
- Event dispatch helpers already exist for AsBroadcaster — MCL listeners
  should use the same pattern.
- The `getURL` opcode handles general HTTP; these two classes just layer
  event dispatch on top.

## Success Criteria

- LoadVars-v6/v7/v8 cross 85% line match.
- MovieClipLoader-v7/v8 cross 85% line match or promote to `ruffle_matched`.
- No regression on avm1 `loadvariables`, `load_vars`, `movieclip_loader_*`
  tests.

## Risk / Effort Estimate

- Phase 1/3 (static state): ~2 days each, straightforward.
- Phase 2/4 (async failure path): ~2 days; needs careful frame ordering.
- Total: ~1-1.5 weeks of focused work.

## Related

- `GNASH_FEATURE_PLAN.md` section 18 (these rows — this plan supersedes)
- Existing setInterval/timer infra: see `MEMORY.md` Timer System entry
- AsBroadcaster listener pattern: already wired for Stage/Mouse/Key
