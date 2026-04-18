# ASnative Class Implementation Plan
<!-- TESTS: ASnative-v5, ASnative-v6, ASnative-v7, ASnative-v8 -->

Last updated: 2026-04-17
Status: **COMPLETE** — all 4 ASnative-v5/v6/v7/v8 tests now ruffle_matched (effective pass).
  - Before: 22-24% line match, 58-86 diffs vs Flash.
  - After: our diffs are a strict subset of Ruffle's `output.ruffle.txt` diffs vs Flash.

Landed fixes:
- ASnative class 103 (Date) dispatcher wired to existing `date.c` methods via Ruffle's index scheme — 0-20 for local getters/setters, 128-143 for UTC variants, 256 for constructor, 257 for Date.UTC. See `actionDateGetASnativeMethod` in `SWFModernRuntime/src/actionmodern/date.c`.
- ASnative(103, 256) returns a bare ASFunction with `prototype_obj = NULL` so `new f()` produces a plain object (no Date.prototype chain). Matches Ruffle `FunctionObject::table_native`.
- ASnative class 200 (Math) index remap: Flash's order (0=abs, 1=min, 2=max, 3=sin, 4=cos, 5=atan2, 6=tan, 7=exp, 8=log, 9=sqrt, 10=round, 11=random, 12=floor, 13=ceil, 14=atan, 15=asin, 16=acos, 17=pow) differs from internal `g_math_funcs[]` order. Remap table added in `builtin_asnative` class 200 branch.
- ASnative class 100 indexes 2 (parseInt) and 3 (parseFloat): standalone advanced_func implementations added in `action.c`. Previously NULL placeholders relied on the name-dispatch path, which only runs when invoked by name.

---

## Overview

`ASnative(class_id, method_id)` returns a Flash-native builtin by numeric ID.
Gnash's ASnative tests exercise Date, Number, and String natives that we have
not yet mapped. Each failing line of output corresponds to one unmapped
method, so progress is measured per-method.

## Current Line Match

| Test | Match | Notes |
|------|-------|-------|
| ASnative-v5 | 26/107 (24.3%) | Date.UTC, encoding natives, Math.sin/cos/tan missing |
| ASnative-v6 | 24/110 (21.8%) | +SWF6-only (Number wrapper, String.fromCharCode) |
| ASnative-v7 | 24/110 (21.8%) | (same as v6) |
| ASnative-v8 | 24/110 (21.8%) | (same as v6) |

## ASnative Class IDs in Scope

From the Gnash test source (`ASnative.as`) and Flash docs. The "*" column
tracks current dispatcher coverage:

| ID | Class / Function | Methods | Status |
|----|------------------|---------|--------|
| 100 | Object (global) | 0..17 — typeOf, ASSetPropFlags, trace, updateAfterEvent, setInterval, etc. | Partially done |
| 101 | Object.prototype | 0..7 — hasOwnProperty, isPropertyEnumerable, toString, valueOf, watch, unwatch | Done |
| 102 | (reserved) | — | n/a |
| 103 | Date | 0..31 — get/setFullYear, Month, Date, Day, Hours, Minutes, Seconds, Milliseconds, Time, TimezoneOffset, UTC variants, toString, getYear, setYear | **MISSING** (0 of ~32) |
| 104 | Error | 0..1 — constructor, toString | Done |
| 105 | Boolean | 0..1 — toString, valueOf | Done |
| 106 | Number | 0..3 — toString(radix), valueOf, toFixed, toPrecision, toExponential | **Partially done** (no toFixed/toPrecision/toExponential) |
| 107 | parseInt / parseFloat / isNaN / isFinite / encode/decode | 0..5 | Partially done (some wiring missing) |
| 108 | AsBroadcaster | 0..3 — addListener, removeListener, broadcastMessage, initialize | Done |
| 110 | System.setClipboard | 0 | Simple — add |
| 250 | String.prototype | 0..13 — charAt, charCodeAt, concat, indexOf, lastIndexOf, slice, split, substr, substring, toLowerCase, toUpperCase, toString, valueOf | Partially done |
| 251 | Array.prototype | 0..13 — push, pop, concat, join, reverse, shift, unshift, slice, splice, sort, sortOn, toString | Done (via array plan) |
| 252 | String (global) | 0..1 — fromCharCode, String | **Partially done** (fromCharCode may be gated) |
| 253 | Math | 0..17 — abs, acos, asin, atan, atan2, ceil, cos, exp, floor, log, max, min, pow, random, round, sin, sqrt, tan | Done |

## Root Cause of Failures

`ASnative.as` does things like:
```as
a = ASnative(250, 4);   // String.prototype.indexOf
d = Date.prototype;
d.a = ASnative(103, 0); // Date.prototype.getFullYear
check_equals(d.a(), d.getFullYear());
```

The method is retrieved by ID and then called on an object of the right
native type. If we return `undefined` for a given `(class_id, method_id)`,
the call fails with `obtained: ""` (empty string) or `obtained: undefined`.

The test exposes our dispatcher gaps, not arithmetic or logic bugs. Fixing
an ASnative mapping typically also fixes the corresponding
`d.getFullYear()` path in other tests — high leverage.

## Phases

### Phase 1 — Date class (ASnative 103, ~32 methods)
- `getFullYear`, `getYear`, `getMonth`, `getDate`, `getDay`, `getHours`,
  `getMinutes`, `getSeconds`, `getMilliseconds`, `getTime`, `getTimezoneOffset`,
  `toString` and UTC variants, plus `setYear`, `setFullYear`, `setMonth`, `setDate`,
  `setHours`, `setMinutes`, `setSeconds`, `setMilliseconds`, `setTime`, UTC setters.
- `Date.UTC` and `Date()` constructor.
- Backing store: a single `double` holding milliseconds since epoch on the ASObject
  (native_type = NATIVE_DATE).
- Suggested impl: new helpers in `action.c`, register via `ASNATIVE_REGISTER(103, N, func)`.
- Expected impact: ~30 lines per test (ASnative-v5/6/7/8 all exercise Date.a()==Date.method()).

### Phase 2 — Number toFixed / toPrecision / toExponential (ASnative 106, ids 2/3/4)
- Standard ECMAScript conversion with Flash's dtoa rounding quirks.
- Backing: any F32/F64 primitive or `new Number(x)` wrapper.
- Expected impact: ~3 lines per v6/v7/v8 test (also improves Number-v6/v7/v8 diffs).

### Phase 3 — String static (ASnative 252) and prototype gaps (ASnative 250)
- Register `String.fromCharCode` under (252, 1) — handles SWF5 quirks (char > 255 wrapping).
- Audit (250, 0..13) for any missing entries by diffing against Gnash's test.
- Expected impact: ~5 lines per test.

### Phase 4 — Object / globals (ASnative 100/107)
- `ASSetPropFlags`, `updateAfterEvent`, `setInterval`, `clearInterval`, `getTimer`,
  `trace` via ASnative IDs (some already work via direct name, but ASnative
  tests take the lookup path).
- Expected impact: ~10 lines per test.

## Implementation Notes

- ASnative dispatcher lives in `action.c`; grep for `actionGetASnative` or
  `ASNATIVE`. Returned `ASFunction*` must have `function_type=2` with
  `advanced_func` set so it can read `this`.
- Date needs a new NATIVE_DATE branch in `new Date()` constructor path. Store
  `double ms_since_epoch` in a named property (e.g. `"__date_ms__"`) or a new
  `ASObject::native_value` field.
- Timezone handling: use `localtime_r` and `gmtime_r` from the C runtime.
  The test's non-UTC assertions compare our output to what the test harness
  machine also reports via `d.getFullYear()` etc., so any consistent TZ
  implementation passes.

## Success Criteria

- ASnative-v5/v6/v7/v8 each cross 85% line-match threshold (required for
  `ruffle_matched` promotion if marked `known_failure` upstream; otherwise
  needed to pass).
- No regressions on `avm1/date_*`, `avm1/number_*`, `avm1/string_*` tests.

## Related

- `FAILING_TESTS_BY_FEATURE.md` — ASnative category
- `GNASH_FEATURE_PLAN.md` section 10 (this plan supersedes that section)
- `ACCEPTED_DIFFS.md` — remaining Date/tz quirks that can't be replicated
  exactly should go here
