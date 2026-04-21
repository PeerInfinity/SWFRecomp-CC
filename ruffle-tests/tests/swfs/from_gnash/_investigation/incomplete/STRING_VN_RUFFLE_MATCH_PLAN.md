# String-vN → ruffle_matched Plan
<!-- TESTS: String-v5, String-v6, String-v7, String-v8 -->

Last updated: 2026-04-21 (Buckets 1–4 landed locally; not yet in CI)
Status: IN PROGRESS — Buckets 1, 2, 3, 4 applied. None of the 4 tests reached
`ruffle_matched` yet; v6 is closest (1 ours-only line beyond Ruffle's diffs).

---

## Goal

Push all four `String-vN` tests from `output_mismatch` to `ruffle_matched`
(+4 effective passes). Each test carries `known_failure = true` with an
`output.ruffle.txt`, so our diffs against Flash's `output.txt` need only
be a subset of Ruffle's diffs — we don't need to match Flash exactly.

## Current state (CI run 24744332558, commit d05bbd56)

| Test | Status | Lines | Ruffle diffs | Our diffs | Ours-only (to close) |
|------|--------|-------|--------------|-----------|---------------------|
| String-v5 | output_mismatch | 314/358 | 21 | 38 | 26 |
| String-v6 | output_mismatch | 351/377 | 10 | 24 | 16 |
| String-v7 | output_mismatch | 348/377 | 10 | 27 | 19 |
| String-v8 | output_mismatch | 348/377 | 10 | 27 | 19 |

"Ours-only" = lines where we fail but Ruffle passes. Closing these is
sufficient for ruffle_matched.

### After Buckets 1–4 applied (local, 2026-04-21)

| Test | Status | Our diffs | Δ vs baseline | Ruffle diffs | Ours-only |
|------|--------|-----------|---------------|--------------|-----------|
| String-v5 | output_mismatch | 27 | −11 | 21 | ~6 |
| String-v6 | output_mismatch | 11 | −13 | 10 | ~1 |
| String-v7 | output_mismatch | 21 | −6  | 10 | ~11 |
| String-v8 | output_mismatch | 21 | −6  | 10 | ~11 |

`ruffle_matched` requires our diffs to be a **proper subset** of Ruffle's
diffs against Flash's `output.txt`. We're not there on any of the four
yet, but v6 is 1 line away (Bucket 5 territory: `saved1.value !==
saved3.value`, line 371).

Cross-test regression check (local): no regressions on avm1
`string_coercion`, `string_methods`, `coerce_to_object_monkeypatch`,
`primitive_type_globals`, `string_methods_swfv5`, `boxed_primitives`;
Gnash `Boolean-v*`, `Number-v6/v7/v8`, `toString_valueOf-v*`,
`delete-v*`, `Inheritance-v*` unchanged. `Number-v5` improved by 2
lines (still output_mismatch).

## Why not regex

The original plan (`blocked/STRING_REGEX_PLAN.md`) assumed ~100 of the
remaining diffs per test were regex-related. An audit on 2026-04-21
showed zero test SWFs across `avm1`, `from_gnash`, and `from_shumway`
contain `RegExp` in their bytecode, and MTASC does not support regex
literals or ship a `RegExp` stdlib class. Regex work would yield no
test-score improvement.

## Work buckets

Each bucket is shared across v6/v7/v8 (same line numbers), and most
apply to v5 too with minor version-specific quirks. Listed in
rough-increasing order of implementation effort; impact is per-test
line count, so multiply by 4 for total Gnash delta.

### Bucket 1 — Function.prototype.call on String stub methods

Lines: v6/v7/v8 238, 239. (v5 — Ruffle also fails, not ours-only.)

```
a.slice.call(a, -5, -3) == "vw"             // line 238
String.prototype.slice.call(a, -5, -3) == "vw"  // line 239
```

`a.slice` is the `builtin_stub_method` on String.prototype. `.call(a, ...)`
invokes the stub with `this=a`. Our earlier `actionCallMethod` patch
only redirects stubs via direct method calls; the `Function.prototype.call`
path goes through a different code site and doesn't trigger the
string-primitive dispatch.

**Fix sketch:** In the builtin `Function.prototype.call` / `apply`
implementation, detect when the callee is `builtin_stub_method` and
when the passed `thisArg` is a NATIVE_STRING wrapper or any object
with a toString. Coerce to primitive string, dispatch via
`callStringPrimitiveMethod` using the function's name (stored on
`ASFunction.name`).

**Effort:** ~1 hour. Same pattern as my earlier patch, different site.
**Impact:** +2 lines on v6/v7/v8 each. Possibly helps Array too.

### Bucket 2 — String.prototype.constructor identity

Lines: v5 263/264, v6/v7/v8 293/294.

```
String.prototype.constructor == String
stringInstance.__proto__.constructor == String
```

`String.prototype.constructor` should point back to the `String`
constructor function. Probably our prototype object either lacks a
`constructor` slot or points to a different ASFunction instance than
the one `GetVariable "String"` resolves to.

**Fix sketch:** When building `g_string_constructor.prototype_obj`, set
`constructor` to a reference that compares `==` with whatever
`GetVariable "String"` returns. Likely a single-pointer-unification
issue similar to the Array constructor unification fix from 2026-04-04.

**Effort:** ~1–2 hours. Need to trace the pointer equality semantics
and ensure the ASFunction stored matches the one returned by
`actionGetVariable("String")`.
**Impact:** +2 lines each test.

### Bucket 3 — delete Object.prototype.toString

Lines: v5 305/306, v6/v7/v8 338/339.

```
!delete Object.prototype.toString   // line N
delete Object.prototype.toString    // line N+1
```

The test likely does something like:
```as
!delete Object.prototype.toString;  // first attempt — DONTDELETE flag
delete Object.prototype.toString;   // second attempt after flag cleared
```

Currently we either always succeed or always fail; the expected
behavior depends on ASSetPropFlags visibility mask state.

**Fix sketch:** Make sure Object.prototype.toString is registered with
the right default flags (DONTDELETE in SWF5, deletable in SWF6+, or
vice-versa — need to check Ruffle). Also verify `actionDelete2` honors
the DONTDELETE flag for built-in prototype properties.

**Effort:** ~2 hours. Small, local; mostly a flag audit.
**Impact:** +2 lines each test.

### Bucket 4 — String.prototype.toString override respected by wrappers

Lines: v5 323/330, v6/v7/v8 356/357/364.

```as
String.prototype.toString = function() { return "toString"; };
a = new String("xxx");
check_equals(a.toString(), "toString");   // FAILS — we return ""
```

Our `objectCallToString` for NATIVE_STRING wrappers (and the
`prim_wrapper_toString` in `g_ctors[...]`) likely hardcodes returning
`valueOf_value` instead of walking the prototype chain for an
overridden `toString`. The override lives on String.prototype and
should win over the built-in.

**Fix sketch:** In the wrapper-toString path, first do a
`getPropertyWithPrototype(obj, "toString", 8)` lookup. If found and
it's a user-defined function (not `builtin_prim_wrapper_toString`),
invoke it via the full method-dispatch machinery. Only fall back to
returning `valueOf_value` when the lookup resolves to the built-in.

**Effort:** ~2 hours. Care needed to avoid infinite recursion
(toString → valueOf → toString).
**Impact:** +3 lines each test.

### Bucket 5 — `watch` / addProperty data-binding "saved" pattern

Lines: v5 349–355, v6/v7/v8 365–374. Largest bucket.

```
saved1.value == 'object'  / 'string'       // lines 365–369
saved2.value !== saved3.value              // lines 370–371
a.id == 'wonder1' / 'wonder2' / 'wonder3'  // lines 372–374
```

The test presumably installs a getter or a `watch()` callback that
captures old values into `saved1`, `saved2`, `saved3`. `a.id` likely
goes through an addProperty setter whose body assigns from its input
to the external saver — the values end up undefined because either the
setter runs without its argument or `Object.prototype.watch` isn't
installed.

**Fix sketch:** Need to inspect the test source via SWF disassembly to
see exactly what pattern it's using. Likely culprits:
(a) `Object.prototype.watch(prop, fn)` not implemented (we currently
register it as a stub); (b) addProperty setter not invoked correctly
when the assignment happens inside a method; (c) setter's `arguments[0]`
or `this` binding wrong.

**Effort:** ~4–8 hours. First step is a disassembly to nail down the
exact AS2 pattern. May turn out to be two smaller sub-buckets once
understood.
**Impact:** +7 lines on v5, +10 on v6/v7/v8.

### Bucket 6 — v5-only split edge cases

Lines: v5 135–138, 143, 145, 172–174, 181–183.

These are `ar.length == 1` / `g.length == 1` assertions that we return
0 for, on SWF5 split calls that pass for Ruffle. The tests do not use
regex (SWF5 can't), so these are SWF5-specific split semantics we
don't yet match — likely empty-separator or missing-separator edge
cases specific to SWF5.

**Fix sketch:** Extract the exact split calls from String.as lines
478–618 via SWF disassembly, replicate in a minimal test, compare
against Ruffle behavior.

**Effort:** ~3 hours. Isolation + small change.
**Impact:** +12 lines on v5 only (half of v5's ours-only total).

### Bucket 7 — v5-only `String.hasOwnProperty('__proto__')` (line 333)

Minor. Expected PASSED, we presumably output FAILED because
`hasOwnProperty` on a function checks the wrong props set. One-liner
if we trace it; otherwise a small own_props registration miss.

**Effort:** ~30 minutes.
**Impact:** +1 line on v5 only.

## Recommended order

Sort by impact ÷ effort, weighted toward easy shared fixes first:

1. **Bucket 1** (.call/stub) — 1h × +8 lines total (v6/v7/v8). ✅ DONE
2. **Bucket 3** (delete toString) — 2h × +8 lines total (all 4). ✅ DONE
3. **Bucket 2** (constructor identity) — 1–2h × +8 lines total. ✅ DONE
4. **Bucket 4** (toString override) — 2h × +12 lines total. ✅ DONE
5. **Bucket 7** (hasOwnProperty __proto__) — 30min × +1 line v5.
6. **Bucket 6** (v5 split edge cases) — 3h × +12 lines v5.
7. **Bucket 5** (watch/addProperty saved) — 4–8h × +37 lines total.

After 1–4, v6/v7/v8 close from 16/19/19 ours-only lines down to
~1/11/11. v6 is 1 line away from ruffle_matched (Bucket 5 line 371
`saved2.value !== saved3.value`). v7/v8 still need more work — Bucket 5
remains the big ticket for them. The gap between v6 and v7/v8 (10 more
ours-only lines) maps to lines 356/357/364 (`a.toString()`) and
365–374 (`saved*.value` + `a.id`) which behave differently in
SWF7+ — likely a cascade from a single upstream difference in test
setup.

For v5, Buckets 6 + 7 clear the v5-unique items (~13 lines); Bucket 5
clears the last 7. So v5 also needs Bucket 5.

## Implementation notes (landed)

### Bucket 1 — `.call`/`.apply` on String stub methods
`actionCallMethod` FUNCTION handler: when the callee is
`builtin_stub_method` and `thisArg` is a String wrapper or
string-coercible object, coerce to UTF-16 and dispatch via
`callStringPrimitiveMethod` using `func->name`. SWF6+ only
(Function.prototype.call was introduced in SWF6 — SWF5 gnash test
expects undefined for this pattern). Mirror for `.apply` with
array/array-like args.

### Bucket 3 — DontDelete on Object.prototype methods
Switched all Object.prototype methods (watch/unwatch/addProperty/
valueOf/toString/hasOwnProperty/isPrototypeOf/isPropertyEnumerable/
toLocaleString, plus the `constructor` placeholder) from `setProperty`
(which defaults to ENUMERABLE|WRITABLE|CONFIGURABLE) to
`setPropertyWithFlags` with ENUMERABLE|WRITABLE only. Matches Ruffle's
PROTO_DECLS which use `DONT_ENUM | DONT_DELETE`.

### Bucket 2 — `String.prototype.constructor == String`
`getObjectPrototype` aside, the real issue was that
`actionGetVariable("String")` at root context was falling through to a
separate lazy static (`g_string_constructor`) with its own
`prototype_obj`, while `new String()` and `getPrimitiveWrapperProto`
used `&g_ctors[2].prototype_obj`. Bucket 2's fix: share `prototype_obj`
between the two — at lazy-init time, `g_string_constructor.prototype_obj
= getPropertyWithPrototype(global_object, "String").prototype_obj`.
Also set `constructor = &g_string_constructor` on the shared prototype
so `String.prototype.constructor == String` holds at root context.

### Bucket 4 — primitive-string method dispatch via user override
`actionCallMethod` STRING-type path: before falling through to
`callStringPrimitiveMethod`, look up `method_name` on
`getPrimitiveWrapperProto(STRING)`. If found and it's **not** one of
the built-in wrappers (`builtin_stub_method`,
`builtin_prim_wrapper_toString`, `builtin_wrapper_valueOf`), build a
minimal String wrapper (native_type=NATIVE_STRING, __proto__=
String.prototype, valueOf_value=primitive, length) and re-dispatch via
`actionCallMethod` so the OBJECT-type path handles invocation through
the full scope-chain/base_clip machinery.

## Success criteria

- String-v5/v6/v7/v8 all → `ruffle_matched` (+4 effective passes).
- Cross-test regression: no drop on `avm1` string_*, `toString_valueOf-v*`,
  `Number-v*`, `Boolean-v*`, `Color-v*`, `TextFormat-v*`,
  `primitive_type_globals`, `coerce_to_object_monkeypatch`.

## Risk / fallback

If Bucket 5 turns out to rely on `watch()` with heavy semantics we
don't want to implement, stop after Buckets 1–4 and accept v6/v7/v8
with smaller ours-only sets as a stepping stone. Document the residual
as near-passing in `GNASH_NEAR_PASSING_PLAN.md`.
