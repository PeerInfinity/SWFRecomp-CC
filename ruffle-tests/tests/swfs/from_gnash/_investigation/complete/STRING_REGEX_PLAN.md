# String Regex Support Plan
<!-- TESTS: String-v5, String-v6, String-v7, String-v8 -->

Last updated: 2026-05-08
Status: COMPLETE/DEFERRED — all four `String-vN` tests are now `ruffle_matched`
(effective pass) per `from_gnash/actionscript.all/_results/results.json`. Native
regex support was not implemented — the non-regex String-wrapper-dispatch fix
(commit d05bbd56) was sufficient because the AVM1 corpus contains zero regex
usage. Plan moved from `blocked/` to `complete/` 2026-05-08; the rationale
below remains valid as a historical record.

---

## Why this plan is shelved

This plan originally called for implementing a native AS2 regex engine
(RegExp, `match`/`replace`/`search`, split with regex separator) on the
assumption that the Gnash String-vN tests' ~100-line-per-test diff was
mostly regex-related. An audit on 2026-04-21 (after the non-regex
String-wrapper dispatch fix landed — see commit d05bbd56) showed all
three premises were wrong:

1. **No test SWF uses regex.** Scanned all ~870 SWFs under
   `ruffle-tests/tests/swfs/avm1`, `from_gnash`, `from_shumway`: zero
   occurrences of `RegExp` in the SWF bytecode, zero `.match()` /
   `.replace()` method-call strings. All regex tests in Ruffle's tree
   live under `avm2/` (AS3), which this recompiler does not target.

2. **MTASC can't even compile regex.** `/pattern/flags` literals fail
   to parse (`parse error Unexpected /`). Explicit `new RegExp(...)`
   fails with `Unknown class RegExp` — no RegExp in MTASC's stdlib.
   The plan's working assumption that MTASC compiled `/p/g` to
   `new RegExp("p", "g")` was incorrect.

3. **Remaining String-vN diffs are not regex.** After the wrapper
   dispatch fix, the ~19 "ours-only" lines per test (ours fails,
   Ruffle passes) break down into five non-regex buckets:
   `Function.prototype.call` on String stubs (238, 239),
   `String.prototype.constructor` identity (293, 294),
   `delete Object.prototype.toString` (338, 339),
   `String.prototype.toString` override respected by wrappers
   (356, 357, 364), and `Object.prototype.watch` / addProperty
   data-binding (365–374).

See `incomplete/STRING_VN_RUFFLE_MATCH_PLAN.md` for the follow-up work
actually targeting String-vN → ruffle_matched.

## If regex ever becomes useful

Hypothetical triggers: shipping an AS2 regex engine would matter if
(a) a new AS2-authored test dependency starts using regex, (b) upstream
Gnash gets an inlined-Dejagnu String test that exercises it, or (c) we
start running AVM2 suites (which would need an AS3 regex, not AS2).
Until then, this is deferred work with no test-score ROI.

The plan sketch below is preserved for reference; none of it is on the
critical path.

---

## Original plan sketch (reference only)

Two options were evaluated:

- **Option A** — PCRE2 / ONIGURUMA dependency. Rejected: licensing
  and build overhead.
- **Option B** — Minimal in-house NFA engine (~500–800 lines of C),
  AS2-compatible subset (literals, `.`, `^`, `$`, `[]`, classes,
  quantifiers, `|`, groups, backrefs). Would include lazy compile on
  first `exec`/`match`/`replace`/`search`.
- **Option C** — `tiny-regex-c` / `tre`. Rejected: tiny-regex-c lacks
  groups; tre has a GNU-style build.

Phases if implemented:

1. RegExp object + `exec` + `test`.
2. `String.prototype.search` / `match` / `replace` (string and function
   replacement forms).
3. `split` with regex separator.
4. Non-regex String gaps (`fromCharCode` high-codepoint, `charAt`
   boundary, Unicode case tables).
