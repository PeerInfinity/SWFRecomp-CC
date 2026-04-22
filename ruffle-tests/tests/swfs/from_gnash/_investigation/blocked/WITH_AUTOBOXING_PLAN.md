# With Auto-Boxing Plan — Reassessed
<!-- TESTS: with-v5, with-v6, with-v7, with-v8 -->

Last updated: 2026-04-21
Status: BLOCKED (moved from incomplete) — primitive auto-boxing is already
effectively working; the remaining diffs are driven by unrelated features.

---

## Findings on 2026-04-21

The plan was scoped around primitive auto-boxing in `with(n)`,
`with("str")`, `with(bool)`. Re-running with-v5/v6/v7/v8 and comparing our
output line-by-line against `output.txt` and `output.ruffle.txt` shows that
the primitive auto-boxing behaviour this plan targeted is **already
effectively producing the expected lines**:

| Assertion (with.as:NNN) | Our output | Expected | Ruffle |
|-------------------------|-----------|----------|--------|
| checkpoint == 3   (L141) | PASSED | PASSED | PASSED |
| Number.prototype.checkpoint == 'three' (L142) | PASSED | PASSED | PASSED |
| checkpoint == 4   (L145) | PASSED | PASSED | PASSED |
| String.prototype.checkpoint == 'four'  (L146) | PASSED | PASSED | PASSED |
| (empty `with(_root)`, `with(null)`, `with(undefined)` lines) | match | match | match |

Current implementation status in `action.c`:
- **STRING with-scope** — already boxes into a transient ASObject with a
  `valueOf` returning the raw string and a `length` property.
- **Number/F32/F64 with-scope** — pushes a `NULL` scope entry; `__proto__.x = y`
  inside the block falls through to `Object.prototype`, and the Number /
  String / Boolean prototypes inherit from `Object.prototype`, so the test's
  `Number.prototype.checkpoint == 'three'` assertion still sees
  `'three'` via the ordinary prototype chain. The observable output matches.
- **BOOLEAN with-scope** — same "null scope + Object.prototype fallback"
  path. No diff-line impact on this test.
- **`with(null)` / `with(undefined)`** — already emits the
  `Error: A 'with' action failed...` trace line, matching both Flash and
  Ruffle.

**Conclusion:** implementing proper Number.prototype / Boolean.prototype
backing scopes would not change any currently-diffing line in with-v6/v7/v8.
The observable diffs come from a completely different set of features.

---

## Current status

| Test | Match | Expected | Status |
|------|-------|----------|--------|
| with-v5 | 7 / 49 raw, diffs ⊆ Ruffle | 49 | **ruffle_matched** |
| with-v6 | 23 / 107 raw | 107 | **output_mismatch** (our diffs ⊄ Ruffle's) |
| with-v7 | 23 / 107 raw | 107 | **output_mismatch** |
| with-v8 | 23 / 107 raw | 107 | **output_mismatch** |

The raw match number for v6/v7/v8 is misleading — most of our content is
correct but shifted by extra diagnostic lines (see Root Cause A).

## Why with-v5 passes but v6/v7/v8 don't

The test source uses `#if OUTPUT_VERSION > 5` to guard the `setTarget`
section (with.as:246-404) and the `with(movieclip)` ASSetPropFlags section
(with.as:514-544). SWF5 skips both, so the v5 test exercises only the
scope-chain and primitive-auto-boxing behaviour — which we get right — and
ends up ruffle_matched.

v6/v7/v8 additionally exercise `setTarget` with object-path arguments and
ASSetPropFlags with READONLY enforcement inside `with(mc) { ... }`.
Those are the real remaining blockers.

## Root causes of remaining diffs (v6/v7/v8)

### A. `setTarget('o.t')` does not resolve dotted object paths (primary)

Flash and Ruffle resolve `setTarget('o.t')` / `setTarget('o:t')` / `setTarget('o2.o.t')`
by walking the argument as a path of property lookups starting from the
current context: find property `o` on timeline/globals, then `.t` on that
object. If the final value is a MovieClip, it becomes the target.

Our `setTarget` only tries display list lookup and `getMovieClipByTarget`
(which parses `/clip1/clip2`-style timeline paths). It does not walk
Object property chains. Result: 8 `setTarget` calls at
`with.as:354/358/362/368/372/377/382/394` all fall through to "Target not
found" and emit a `Target not found: Target="..." Base="_level0"` diagnostic
line.

**Diff-line impact** (per test, v6/v7/v8 each):
- 6 extra `Target not found: ...` lines that Ruffle does NOT emit.
  Ruffle emits 3 (for `../o:t`, `o2.o`, `o2.o.p.t`) — same-path tests we
  also fail.
- 8 `_target` assertions that should PASS but FAIL-with-empty-obtained.

Fixing this requires extending `actionSetTarget` (and `actionSetTarget2`) to
resolve dotted/colon object paths through ordinary property lookup. See
`action.c:44670-44742`.

### B. ASSetPropFlags READONLY not enforced in `with(mc)` assignment

`ASSetPropFlags(mc, "nooverride", 4, 1)` sets flag 4 = clear
`PROPERTY_FLAG_WRITABLE`. Inside `with(mc) { nooverride = "nooverrideUpdated"; }`,
Flash silently rejects the assignment because the target property is
non-writable on `mc.dynamic_props`; the value stays `"nooverride"`.

Our `actionSetVariable` WITH-scope path writes through to `mc->dynamic_props`
without consulting the property's flag bits, so the assignment sticks.

**Diff-line impact** (per test):
- with.as:531 `check_equals(nooverride, "nooverride")` — FAIL (obtained `nooverrideUpdated`).
- with.as:539 `check_equals(mc.nooverride, 'nooverride')` — FAIL (obtained `nooverrideUpdated`).

Fix scope: WITH-scope assignment to a MovieClip should look up the
existing property in `mc->dynamic_props`, check `PROPERTY_FLAG_WRITABLE`,
and silently no-op when clear.

### C. Child MC name resolution after `child = "rootChild"` assignment

`with.as:523` does `child = "rootChild"` inside `with(mc)` on a MovieClip
that has a real child named `child`. Flash: the string is stored on `_root`
(since `child` is a real child, not an own property in `mc.dynamic_props`).
Our impl: we set a string on the MC-level variable lookup, shadowing the
child entry in a way that makes `with.as:543 check_equals(child, "rootChild")`
fail.

Also `with.as:533 check_equals(child._target, "/mc/child")` FAILS because
our `child._target` is empty rather than `/mc/child`. Ruffle also fails
this check but with a different obtained value — so this does not cost us
ruffle_matched by itself.

**Diff-line impact** (v6/v7/v8 each):
- with.as:543 `check_equals(child, "rootChild")` — FAIL
  (obtained `_level0.mc.child`, Ruffle obtained empty). The difference in
  obtained string means our diff is NOT a subset of Ruffle's on this line.

### D. `withs` deep nesting — Flash hard-limits to 13 levels

`with.as:568-625` builds 18 levels of `with()` and checks
`withs == "abcdefghijklm"` (13 characters). Flash silently stops opening
WITH scopes past level 13. We open all 18. Ruffle also opens all 18. So
this diff line is present in both our and Ruffle's output (same `obtained`
value), and it doesn't cost us ruffle_matched.

---

## To reach ruffle_matched on v6/v7/v8

**Minimum surface area:** fix Root Cause A and B. Root Cause C's diff line
has a different `obtained` value than Ruffle's, so we need to match Ruffle
(empty obtained) OR pass the check outright.

Rough effort:
- A (dotted object path in setTarget): ~2 days — need to reuse
  `getPropertyWithPrototype` + dot/colon split similar to `actionDelete2`
  dot-path handling.
- B (READONLY in WITH assignment): ~1 day — narrow fix in WITH-scope
  branch of `actionSetVariable` / `setVariableWithValue`.
- C (child assignment): investigation needed — our `_level0.mc.child`
  stringification differs from Ruffle's empty; may be a by-product of A.

## Blockers

The remaining work is **not primitive auto-boxing**. It spans three
unrelated features (SetTarget dotted-path resolution, ASSetPropFlags
READONLY enforcement, child MC name-vs-string resolution). Each is a
substantive feature in its own right.

Moving this plan to `blocked/` because:
1. Its original scope (primitive auto-boxing) is effectively complete.
2. The identified work items belong in three separate plans, each
   addressing a non-WITH feature.

## Suggested follow-up plans

- `SETTARGET_OBJECT_PATH_PLAN.md` — extend `actionSetTarget` to resolve
  dotted/colon object paths via property lookup. Would help with-v6/v7/v8
  most (~14 line diffs each).
- `ASSETPROPFLAGS_WITH_READONLY_PLAN.md` — enforce WRITABLE flag in
  WITH-scope assignment (~2 line diffs each).

## Related / Superseded references

- `GNASH_FEATURE_PLAN.md` section 11 (primitive auto-boxing) — effectively
  resolved.
- `MEMORY.md` "Primitive auto-boxing in GetMember" — the same auto-boxing
  mechanism the plan tried to extend to WITH is already working via
  Object.prototype inheritance.
- `getPrimitiveWrapperProto` helper in `action.c` — no longer needed for WITH
  scopes (the prototype chain already covers the test's assertions).
