# String Regex Support Plan
<!-- TESTS: String-v5, String-v6, String-v7, String-v8 -->

Last updated: 2026-04-21
Status: IN PROGRESS — non-regex String-wrapper method dispatch landed (+71–88 lines per test). Regex itself still not implemented.

---

## Overview

The Gnash String tests (`String-vN`) exercise AS2 regex methods that we have
not implemented:

- `String.prototype.match(regex)` → returns Array of matches or null
- `String.prototype.replace(regex, replacement)` → returns string with
  replacements; replacement may be string (with `$&`, `$1`..`$9`, `$$` etc.) or function
- `String.prototype.search(regex)` → returns index of first match or -1
- `String.prototype.split(regex, limit)` → already implemented for string
  separators; needs regex separator support

Plus the accompanying `RegExp` constructor (but AS2 regex literals compile
via MTASC to `new RegExp(pattern, flags)` so most of the work is runtime-side).

## Current Line Match

| Test | Match | Expected | Diffs |
|------|-------|----------|-------|
| String-v5 | 314 / 358 | — | 44 |
| String-v6 | 351 / 377 | — | 26 |
| String-v7 | 348 / 377 | — | 29 |
| String-v8 | 348 / 377 | — | 29 |

## Fixes landed (2026-04-21, not yet in CI)

Initial investigation showed that most diffs were NOT regex-related —
they were String-wrapper method dispatch bugs. `new String("foo").charCodeAt(0)`
was returning `undefined` because `String.prototype.charCodeAt` is registered
as a placeholder stub (`builtin_stub_method` → returns `undefined`) so
that `hasOwnProperty('charCodeAt')` works. The real implementation lives
in `callStringPrimitiveMethod` and only ran when the receiver was a
primitive `STRING` value.

Three fixes in `SWFModernRuntime/src/actionmodern/action.c`:

1. **Stub dispatch to primitive method** (`actionCallMethod` OBJECT branch)
   — when the resolved method is `builtin_stub_method`, coerce `this` to
   a string (via `valueOf_value` for NATIVE_STRING wrappers, else
   `objectCallToString`) and dispatch through `callStringPrimitiveMethod`.
   `callStringPrimitiveMethod` returns 0 for unknown names, so the
   fallthrough is safe for non-string stubs.

2. **`stringArgToNumber` object coercion** — OBJECT/ARRAY/FUNCTION args
   now go through `varToDoubleSWF` (which calls `valueOf`), instead of
   returning NaN unconditionally. Fixes `a.indexOf("a", o) == 4` when `o`
   has `valueOf()` returning 4.

3. **`lastIndexOf` NaN-fromIndex → 0** — matches Ruffle's
   `n.coerce_to_i32(activation)` which saturates NaN to 0. Fixes
   `r.lastIndexOf("ghi", "rt") == -1`.

Impact per test:

| Test | Before | After | Δ |
|------|--------|-------|---|
| String-v5 | 243 / 358 | 314 / 358 | +71 |
| String-v6 | 263 / 377 | 351 / 377 | +88 |
| String-v7 | 260 / 377 | 348 / 377 | +88 |
| String-v8 | 260 / 377 | 348 / 377 | +88 |

No regressions on: `string_methods`, `string_methods_swfv5`,
`string_methods_negative_args`, `string_coercion`, `primitive_type_globals`,
`coerce_to_object_monkeypatch`, `coerce_to_primitive_resolve`,
`object_string_coerce_swf5/swf6`, `mutable_this`, `this_scoping`, `typeof`,
`delete-v7`, `enumerate-v7`, `TextFormat-v5/v7`, `Color-v7`,
`toString_valueOf-v5/v6/v7`, `Number-v5/v6/v7`, `Boolean-v7`.

Remaining diffs (~26–44 per test) are a mix of:
- Regex usage (`split(/regex/)`, `match`, `replace`, `search`) — the
  core of this plan.
- `String.prototype.slice.call(obj, ...)` / `a.slice.call(a, ...)` —
  Function.prototype.call path doesn't trigger the stub-dispatch fix.
- Prototype.toString override semantics (`String.prototype.toString = function(){return "toString"}` then `a.toString()` should return "toString" not empty).
- Edge cases in `split("")` and empty-separator paths.

## Root Cause

Our `actionCallMethod` dispatch for String methods intercepts `match`,
`replace`, `search` but returns `undefined`. The RegExp object itself
probably reaches runtime as a plain ASObject with `source` and `global`/`ignoreCase`
properties, but nothing consumes it.

## Approach

AS2 regex is a subset of JS/ECMAScript regex (Perl-compatible lite). Two
implementation choices:

### Option A — PCRE2 or ONIGURUMA dependency
- Pros: battle-tested, correct POSIX/Perl semantics
- Cons: adds a native dependency, licensing, larger build
- Not preferred given project scope

### Option B — Minimal in-house regex engine (recommended)
- Scope: literal chars, `.`, `^`, `$`, `[...]`, `[^...]`, `\d`, `\w`, `\s`,
  `\b`, `*`, `+`, `?`, `{m,n}`, `|`, `(...)`, `(?:...)`, backreferences
  `\1..\9`, escape `\.`, `\\`, `\n`, etc.
- Flags: `g`, `i`, `m` (the only ones AS2 uses).
- Backtracking NFA implementation; ~500-800 lines of C.
- Ruffle has a Rust regex bridge but we can't reuse it directly. The AS3
  RegExp is documented in livedocs and matches the subset above.
- Store pattern string + flags on the RegExp object; compile lazily on first
  `match`/`replace`/`search`/`exec` call.

### Option C — Link a pure-C regex library (e.g., tiny-regex-c, tre)
- `tiny-regex-c` is too limited (no groups).
- `tre` supports approximate matching but has a GNU-style build.
- Not preferred; Option B is faster to validate and ships no new
  dependencies.

## Phases

### Phase 1 — RegExp object + `exec`
- Parse pattern + flags into an internal NFA representation on construction.
- Implement `RegExp.prototype.exec(str)` returning an Array with match groups
  and `index`/`input` properties.
- Implement `RegExp.prototype.test(str)` returning Boolean.
- Unblocks a few direct-usage test lines.

### Phase 2 — String.prototype.search / match / replace (string and func)
- `search` = `regex.exec(this).index` or -1.
- `match(regex)` without `g` flag = `regex.exec(this)`; with `g` flag =
  array of match strings.
- `replace(regex, repl)` — repl can be string (with `$&`, `$1..$9`, `$$`) or
  function (called with match, groups..., offset, string).
- Biggest diff reduction — probably 70+ lines per test.

### Phase 3 — split with regex separator
- Walk input applying NFA to find separator positions; split at those.
- ~10 lines per test.

### Phase 4 — Non-regex String gaps
- `fromCharCode` SWF5 high-codepoint handling.
- `charAt`/`charCodeAt` boundary behavior (out-of-range → empty string / NaN).
- `toLowerCase`/`toUpperCase` Unicode coverage (we already have the case
  tables).
- ~10 lines per test, mostly independent of regex.

## Success Criteria

- String-v5/v6/v7/v8 cross 85% line match.
- No regression on `avm1/string_*` tests.
- `regexp`, `regexp_exec`, `regexp_match`, `regexp_replace` avm1 tests pass
  (if they exist — check upstream Ruffle test suite).

## Risk / Effort Estimate

- Option B engine: ~1 week of focused work.
- Test fixtures: small; runtime driven entirely by `output.txt` diffs.
- Risk: regex edge cases (greedy vs lazy, backreferences) — plan to accept
  platform-specific precision via `ACCEPTED_DIFFS.md` for pathological patterns.

## Related

- `GNASH_FEATURE_PLAN.md` section 12 (this plan supersedes that section)
- AS2 regex spec: Flash docs for `String.match` / `RegExp`
- MTASC behavior: compiles `/pattern/flags` literals to `new RegExp(p, f)`
