# LoadVars + MovieClipLoader Plan
<!-- TESTS: LoadVars-v6, LoadVars-v7, LoadVars-v8, MovieClipLoader-v7, MovieClipLoader-v8 -->

Last updated: 2026-04-19
Status: Phase 1 + 2 complete — LoadVars v6/v7/v8 each 61/152 → 138/152 (91%); MCL v7/v8 promoted to `ruffle_matched` (effective pass)

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
| LoadVars-v6 | 138 / 152 | — | ~14 |
| LoadVars-v7 | 138 / 152 | — | ~14 |
| LoadVars-v8 | 138 / 152 | — | ~14 |
| MovieClipLoader-v7 | 46 / 165 | — | ~120 — ruffle_matched (effective pass) |
| MovieClipLoader-v8 | 46 / 165 | — | ~120 — ruffle_matched (effective pass) |

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

### Phase 2 Results (2026-04-19)

`load()` now async. Added deferred-LoadVars-load queue
(`g_pending_lv_loads`), `processLoadVarsLoads()` called from the frame loop
in `swf_core.c` and `swf_headless.c` right after `processTimers()`.

- `load(url)` sets `_bytesLoaded=0` (F64), `_bytesTotal=undefined`,
  `loaded=false` on the instance; enqueues a pending load with a heap-copy
  of the UTF-16 content (UTF-8 BOM stripped — Flash treats BOM as
  transport metadata); returns `true`.
- `processLoadVarsLoads()` updates `_bytesLoaded` / `_bytesTotal` to the
  final byte count (BOM included) then fires `onData(content_string)` on
  each pending instance.
- Default `LoadVars.prototype.onData`: calls `this.decode(src)`, sets
  `loaded=true`, then fires `this.onLoad(true)`. On failure, fires
  `onLoad(false)`.
- `fireLoadVarsCallback()` helper correctly invokes user-defined
  DefineFunction (type 1) / DefineFunction2 (type 2) callbacks with:
  `this` pushed onto `g_this_stack`, `g_current_executing_func` set,
  captured scope chain restored, local scope populated with an
  `arguments` array, and base_clip-based SWF6+ closure context.
  (`soundFireCallback` alone misses most of these — likely fine for sound
  callbacks that don't probe `this`/`arguments` but insufficient for
  LoadVars.)

No regressions on avm1 `loadvariables`, `loadvariables2`, `loadvariablesnum`,
`load_vars`, `sound`, `set_interval`.

## Remaining Work

**Phase 3/4 (MovieClipLoader) — promoted to ruffle_matched:** A single-line
fix to `builtin_mcl_unloadClip` (return `undefined` instead of boolean `false`
when called with no arguments, matching Flash) was enough to drop our diff
below Ruffle's upstream known_failure diff, so both MCL tests are now
effective passes via `ruffle_matched`. The remaining 120-line gap between
our output and Flash's reference is the full async-image-load lifecycle
(`onLoadStart` / `onLoadProgress` / `onLoadComplete` / `onLoadInit` for
successful loads, `onLoadError("URLNotFound")` for missing URLs) plus image
dimension handling — all of which Ruffle also cannot pass. If we ever want
to land "real" passes on these tests (not just ruffle_matched), we'd need
to implement the full event lifecycle in `actionFirePendingLoadInits`
including: onLoadError for any non-existent URL (not just .swf), DataFile
entry support so vars.txt produces a success sequence with file_size=1126,
and image load simulation for green.jpg (target._width/_height = 170).

**Misc remaining LoadVars failures (~14 lines/test):**
- `sendAndLoad` block 2/3 expectations (line 54, 63-66): target doesn't get
  `loaded` as OWN in block 2, or block 3 return value is false.
- `[type Object]` vs `[object Object]` in toString (line 98): Flash's
  LoadVars.toString serializes certain native-typed objects to
  `[type Object]`, we emit `[object Object]` from Object.prototype.toString.
  One line per test.
- `lv.toString()` override via own `toString` property (line 101): likely
  needs a special dispatch path for own-property `toString` before the
  prototype's native toString.
- Lines 147-149 (end of test): second `sendAndLoad` block fails; probably
  another target-type edge case.
- `#passed: 144` / `#failed: 0` summary counts are off because we fail a
  handful of individual checks above.

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
