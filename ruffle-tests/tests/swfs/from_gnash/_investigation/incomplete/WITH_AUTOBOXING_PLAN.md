# With Auto-Boxing Plan
<!-- TESTS: with-v5, with-v6, with-v7, with-v8 -->

Last updated: 2026-04-17
Status: NOT STARTED — 4 tests, ~21-43% line match

---

## Overview

Flash's `with(primitive)` block auto-boxes primitive numbers, strings, and
booleans to their wrapper-object prototypes, so property reads inside the
block resolve against `Number.prototype`, `String.prototype`, or
`Boolean.prototype`. Our `actionWith` opcode handler currently accepts only
OBJECT/ARRAY/MOVIECLIP scope objects and falls through to undefined for
primitives.

## Current Line Match

| Test | Match | Expected | Diffs |
|------|-------|----------|-------|
| with-v5 | 21 / 49 (42.9%) | — | 28 |
| with-v6 | 23 / 107 (21.5%) | — | ~84 |
| with-v7 | 23 / 107 (21.5%) | — | ~84 |
| with-v8 | 23 / 107 (21.5%) | — | ~84 |

## Test Behavior

```as
var s = "hello";
with(s) {
    trace(length);       // expected: 5 (via String.prototype.length getter)
    trace(charAt(0));    // expected: "h" (via String.prototype.charAt)
}

var n = 3.14;
with(n) {
    trace(toString(2)); // expected: "11.00100011110101110000101000111101011100..."
}
```

Our impl: the `with` scope stores only ASObject pointers; a number/string
has no ASObject so the scope push stores `NULL` and all resolutions fall
through to the global scope. Hence the vast majority of lines fail.

## Approach

Extend the WITH scope representation to carry a *synthetic* boxed object
when the operand is a primitive:

1. In `actionWith`, if the operand is F32/F64/BOOLEAN/STRING, look up the
   appropriate wrapper prototype via `getPrimitiveWrapperProto(type)` (already
   exists — used by primitive auto-boxing in GetMember).
2. Push the wrapper prototype onto the scope chain with a new flag
   `scope_is_primitive_box[]` (parallel to `scope_is_with[]` and
   `scope_mc[]`). The flag tells GetVariable lookups to route through the
   prototype chain and also to auto-invoke `valueOf` / toString-style
   accessors.
3. In `actionGetVariable` WITH-scope path, if `scope_is_primitive_box`, look
   up the property on `wrapper_prototype`; if FUNCTION, bind `this` to the
   primitive value for invocation.

## Phases

### Phase 1 — String primitive box
- Implement for String type only first — easier to verify against
  String.prototype.charAt, concat, indexOf, substring.
- Expected impact: ~15 lines in with-v5 (SWF5 only has String/Number primitives
  in with).

### Phase 2 — Number primitive box
- Same mechanism; prototype lookup → Number.prototype.
- `toString(radix)` returns radix conversion.
- Expected impact: ~10 lines per test.

### Phase 3 — Boolean primitive box (SWF6+)
- `Boolean.prototype.toString` / `valueOf`.
- Small — SWF5 has no Boolean wrapper.

### Phase 4 — with over non-box values (null, undefined)
- `with(null)` / `with(undefined)` — behavior varies by SWF version:
  - SWF5/6: treat as empty scope (no-op)
  - SWF7+: throw TypeError per ECMAScript, but Flash just emits trace and
    no-ops
- Small impact, mostly prevents regressions.

### Phase 5 — Method dispatch binding `this`
- Inside `with(s)`, a call like `charAt(0)` must dispatch String.prototype.charAt
  with `this = s`. Requires storing the original primitive value in the
  scope entry so `actionCallFunction` can retrieve and bind it.
- Needed for all non-getter method lines.

## Implementation Notes

- Scope chain infrastructure: `scope_chain[]` (ASObject), `scope_is_with[]`
  (bool), `scope_mc[]` (MovieClip). Add `scope_prim_value[]` (ActionVar) to
  capture the primitive for `this` binding.
- The primitive auto-boxing logic for GetMember (already shipped) is the
  same pattern at a different scope layer — can share `getPrimitiveWrapperProto`.

## Success Criteria

- with-v5 crosses 80% line match.
- with-v6/v7/v8 cross 70% line match.
- No regression on avm1 `with_*` tests or `string_coercion`, `mutable_this`.

## Risk / Effort Estimate

- Medium complexity — scope chain is well-trodden code, but primitive
  binding across opcode boundaries is subtle.
- Effort: ~3-5 days.
- Risk: propagating `this` through nested function calls inside `with` may
  require threading extra context through `actionCallFunction`.

## Related

- `GNASH_FEATURE_PLAN.md` section 11 (this plan supersedes)
- `MEMORY.md` "Primitive auto-boxing in GetMember" — shares the wrapper
  prototype lookup
- `getPrimitiveWrapperProto` helper in `action.c`
