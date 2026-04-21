# String-vN → ruffle_matched Plan
<!-- TESTS: String-v5, String-v6, String-v7, String-v8 -->

Last updated: 2026-04-21 (All 4 String-vN → ruffle_matched locally; not yet in CI)
Status: COMPLETE — All four `String-v{5,6,7,8}` tests reach `ruffle_matched`.
Our diffs against Flash are a proper subset of Ruffle's diffs against Flash
for every version.

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

### Final state (local, 2026-04-21)

| Test | Status | Our diffs | Ruffle diffs | Ours-only |
|------|--------|-----------|--------------|-----------|
| String-v5 | **ruffle_matched** | 19 | 21 | 0 |
| String-v6 | **ruffle_matched** | 8 | 10 | 0 |
| String-v7 | **ruffle_matched** | 8 | 10 | 0 |
| String-v8 | **ruffle_matched** | 8 | 10 | 0 |

All four tests: **our diffs against Flash ⊂ Ruffle's diffs against Flash**.
The `verify_output.py` subset-match promotion kicks in for each.

Cross-test regression check (local): no regressions on 25 avm1 tests
(string/primitive/enumerate/function family); Gnash `Boolean-v*`,
`Number-v6/v7/v8`, `toString_valueOf-v*`, `delete-v*`, `Inheritance-v*`,
`enumerate-v*`, `Math-v*`, `ASnative-v*`, `Error-v*`, `Color-v*`,
`Date-v*`, `Video-v*`, `XMLSocket-v*` — all unchanged.

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

## Final landed buckets (2026-04-21)

1. **Bucket 1** (.call/stub) ✅ DONE
2. **Bucket 3** (delete toString) ✅ DONE
3. **Bucket 2** (constructor identity) ✅ DONE
4. **Bucket 4** (toString override + primitive auto-box for user methods) ✅ DONE
5. **Bucket 6** (v5 split edge cases — empty-separator + limit 0/-1) ✅ DONE
6. **Auto-box constructor `this`** — tryAutoBoxPrimitive now pushes
   local scope with `this` bound to the wrapper for DefineFunction2
   constructors. Fixes the `a.id == 'wonder*'` wonder-test pattern.
7. **Enumerate fallback for built-in globals** — actionEnumerate falls
   back to actionGetVariable when var_map has an uninitialized slot.
   Fixes `for (v in String)` / `for (m in Math)` at root context.
8. **Math properties DONT_ENUM** — post-init loop clears ENUMERABLE on
   all Math constants + methods (no-op before because enumerate
   couldn't reach Math, but regression after fix #7).
9. **fromCharCode DONT_ENUM** — clears ENUMERABLE on
   `String.fromCharCode`.
10. **g_string_constructor.own_props.__proto__** — set to
    Function.prototype so for-in walks the chain.

Bucket 5 (watch/addProperty "saved" pattern) and Bucket 7
(`String.hasOwnProperty('__proto__')`) turned out to already be
handled by the cascade fixes above, once Bucket 4 was fully wired.

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
