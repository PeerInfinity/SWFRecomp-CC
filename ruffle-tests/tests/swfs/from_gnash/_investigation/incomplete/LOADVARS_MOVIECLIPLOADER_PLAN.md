# LoadVars + MovieClipLoader Plan
<!-- TESTS: LoadVars-v6, LoadVars-v7, LoadVars-v8, MovieClipLoader-v7, MovieClipLoader-v8 -->

Last updated: 2026-04-19
Status: Phase 1 complete — LoadVars v6/v7/v8 each 61/152 → 97/152 (64%); MCL v7/v8 unchanged

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
| LoadVars-v6 | 97 / 152 | — | ~55 |
| LoadVars-v7 | 97 / 152 | — | ~55 |
| LoadVars-v8 | 97 / 152 | — | ~55 |
| MovieClipLoader-v7 | 46 / 165 | — | ~120 |
| MovieClipLoader-v8 | 46 / 165 | — | ~120 |

### Phase 1 Results (2026-04-19)

LoadVars prototype methods replaced from stubs to real implementations in
`SWFModernRuntime/src/actionmodern/action.c`:

- `decode(queryString)` — URL-decodes and assigns key=value pairs as own
  properties on the LoadVars instance. Returns boolean false when called with
  no argument (Gnash/Flash compatibility).
- `toString()` — URL-encodes own enumerable properties in LIFO
  (reverse-insertion) order, joined by '&'. Uses percent-encoding matching
  Flash's behavior (A-Z/a-z/0-9 preserved, all else %XX including space→%20).
- `getBytesLoaded()` / `getBytesTotal()` — return the instance's own
  `_bytesLoaded` / `_bytesTotal` F64 properties (undefined if not set).
- `sendAndLoad(url, target)` — sets `target.loaded=false`,
  `target._bytesLoaded=0`, `target._bytesTotal=0` as own properties; returns
  true for any non-Date OBJECT target, false otherwise (Date instances
  specifically excluded).

A `registerLoadVarsNative` helper factors out the repeated pattern of
allocating an ASFunction, setting up native own_props, registering with the
function registry, and installing on the prototype.

No regressions on avm1 `loadvariables`, `loadvariables2`, `loadvariablesnum`
(all still pass).

## Remaining Work

**Phase 2 (async load()) — est. ~30 lines/test of the 55 remaining diffs:**
`load()` currently fires onLoad synchronously. The test expects:
1. `load()` returns true and sets `_bytesLoaded=0`, `_bytesTotal=undefined`,
   `loaded=false` on the instance.
2. On the NEXT frame tick (before subsequent frame scripts):
   set `_bytesLoaded = _bytesTotal = content_length`, then fire
   `onData(content_string)`.
3. The default `onData` (installed on the prototype) should call
   `this.decode(src)` and `this.onLoad(true)`. The test overrides onData to
   check intermediate state, then calls decode + onLoad manually.

Requires: a deferred-LoadVars-dispatch queue, a `processLoadVarsLoads()`
called from `swf_core.c` between frame scripts and timers, and a default
`onData` implementation on `LoadVars.prototype`.

**Phase 3/4 (MovieClipLoader) — not started:** The 120-line MCL gap requires
`loadClip` to fire `onLoadError` async for non-existent URLs and
`onLoadStart` / `onLoadProgress` / `onLoadComplete` / `onLoadInit` for
successful loads. Shares infrastructure with Phase 2's async dispatcher.

**Misc remaining LoadVars failures (~10 lines/test):**
- `sendAndLoad` block 2/3 expectations (line 54, 63-66): target doesn't get
  `loaded` as OWN but does get it inherited; block 3 return value differs.
  Needs source inspection to understand exactly what the test passes.
- `[type Object]` vs `[object Object]` in toString (line 98): Flash's
  LoadVars.toString serializes certain native-typed objects to
  `[type Object]`, we emit `[object Object]` from Object.prototype.toString.
  One line per test.
- `lv.toString()` override via own `toString` property (line 101): needs the
  recompiler/runtime to invoke the instance-overridden toString instead of
  the prototype's.

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
