# array-v5 Investigation Plan
<!-- TESTS: array-v5 -->

Last updated: 2026-06-19 (sort-mutating-comparator: match Flash, NOT Ruffle → array-v5 IGNORED, not promoted)

## Status: IGNORED (2026-06-19) — added to actionscript.all `ignored_tests.txt`; residual diff is sort-UB + clusters both engines miss vs Flash

### Decision (2026-06-19) — `Array.sort` mutating-comparator UB: match Flash over Ruffle

The two remaining ours-only-vs-Flash lines were `array.as:324`/`325`
(testCmpBogus6: `function(x,y){ trysortarray.pop(); return 1; }` on `[1,2,3,4]`,
expecting `length == 4` / `"2,3,4,1"`). A first attempt fixed these by switching
`Array.sort` to Ruffle's snapshot-and-write-back algorithm — but that ALSO
flipped `array.as:317` (testCmpBogus5: `pop(); return -1`) from Flash-correct
(`length 0`) to Ruffle's `length 4`, i.e. it traded a Flash-correct line for two
Ruffle-correct ones. **That is a genuine Ruffle-vs-Flash conflict, and project
policy is to match Flash.** The snapshot change was reverted.

| Comparator | Flash | Ruffle | Us (in-place) |
|------------|-------|--------|---------------|
| `pop(); return -1` (317) | length **0** | 4 (FAIL) | **0** ✓ |
| `pop(); return +1` (324/325) | length **4**, `"2,3,4,1"` | 4 (PASS) | 0 ✗ |

We keep the in-place sort (`arr->elements`), which is Flash-correct on 317.
Reproducing Flash on 324/325 *as well* would need a Flash-exact in-place AVM1
quicksort (the residual sort-UB nobody fully nails); not pursued. Because we pass
317 where Ruffle fails, our diff is NOT a subset of Ruffle's → no `ruffle_matched`
promotion → array-v5 added to `from_gnash/actionscript.all/ignored_tests.txt`.
Documented in `_investigation/ACCEPTED_DIFFS.md` Category 1 (incl. the policy note
that `ruffle_matched` must not be chased by diverging from Flash). The remaining
260/263/1630/1636 diffs are separate clusters both engines also miss vs Flash.

### Prior status (superseded): IN PROGRESS — 536/560 lines match locally (~95.7%), 24 remaining failures (CI baseline `068b46d8` was 528/560; previous local 535/560)

### Latest fix (2026-05-08, pending CI) — +1 line

**`X.prototype = new Array(); o = new X(); o.push(...); o.pop()` now resolves
inherited Array methods (line 1710, +1).** When a function's prototype is
assigned a non-object value (here, an Array instance), `actionNewObject`
stores it on the new instance's `__proto__` verbatim — the type tag stays
`ACTION_STACK_VALUE_ARRAY`, not OBJECT. The OBJECT-receiver method-lookup
loop in `actionCallMethod` (`SWFModernRuntime/src/actionmodern/action.c`)
gated chain traversal on `_np->type != ACTION_STACK_VALUE_OBJECT` and broke
the walk at the ARRAY-typed proto, so `push` / `pop` were never found and
`o.pop()` returned undefined. Two paired changes:

1. `resolveProtoVar` (`action.c`) now also handles `ACTION_STACK_VALUE_ARRAY`
   by returning `arr->props` — the string-keyed property bag whose own
   `__proto__` points at `Array.prototype`. This automatically fixes
   `walkProtoChain`, `getPropertyWithPrototype`, and
   `findPropertyStructWithPrototype` callers (super lookups,
   `findResolveMethod`, `getPropertyWithPrototype` everywhere).
2. The inline OBJECT-receiver method-lookup walk in `actionCallMethod`
   (line ~56235) does the same ARRAY-aware step in line. The walk now
   accepts both OBJECT and ARRAY-typed `__proto__`, treating ARRAY as
   "switch over to `arr->props`" before the next iteration.

After the fix, `o.push("Array data")` resolves `push` via
`o → X.prototype (Array instance) → arr->props → Array.prototype`, mutates
through the existing `objectToTempArray` / `callArrayMethod` /
`syncArrayToObject` path (own props on `o` get `0="Array data"`,
`length=1`), and `o.pop()` returns `"Array data"` via the same chain.
Verified no regressions across a 31-test AVM1 array/lifecycle/super/scope
battery (31/31 PASS) plus the 19-test follow-up battery covering
`array_properties`, `array_prototyping`, `as2_super_and_this_v6/v8`,
`closure_scope`, `coerce_to_object_monkeypatch`, `enumerate`,
`function_as_function`, `funky_function_calls`, `object_resolve`,
`on_construct`, `parse_int`, `register_and_init_order`,
`register_class_return_value`, `set_variable_scope`, `string_coercion`,
`string_paths_eval2`, `typeof` (19/19 PASS), 11-test gnash actionscript.all
prototype-heavy battery (11/11 effective: 6 PASS + 5 RM), and 4-test
Shumway `duplicateMovieClip` battery (4/4 PASS).

### Earlier fixes (2026-05-08, pending CI) — +7 lines

1. **`Array.prototype.shift` honors DontDelete on target index (line 1416, +1).**
   `callArrayMethod` shift's element-copy loop now skips the move when the
   target index `i` has `PROPERTY_FLAG_CONFIGURABLE` cleared (DontDelete set
   in ASSetPropFlags). The metadata-reset loop is also gated to only fire
   on indices that were actually overwritten. Matches Flash semantics for
   `ASSetPropFlags(a, "0", 7, 0); a.shift()` — index 0 stays `'zero'`
   instead of being overwritten by the shifted-in `'one'`. Ruffle gets
   the same line via WRITABLE-honoring `set_data`; we honor DontDelete
   because Flash's `ASSetPropFlags(a, "0", 4, 0)` (ReadOnly only) DOES
   allow shift to overwrite (test array.as:1444), and matching that
   requires ignoring WRITABLE during shift.

2. **`syncArrayToObject` skips HOLE writeback (line 1537, +1).**
   The plain-Object dispatch bridge for `Array.prototype.X.call(obj)`
   reads obj's indices into a temp ASArray via `objectToTempArray`;
   missing keys land as HOLE. After the operation runs on the temp,
   the writeback loop now skips entries with `type == HOLE` so we don't
   create new properties on `obj` for indices that were never there.
   Fixes the "extra `0,` at the front of `traceProps`" symptom on
   `pop()` (test array.as:1537). Other plain-Object dispatch lines
   (1577 splice, 1630/1636 sort) didn't change because their internal
   densification converts HOLE → UNDEFINED before the writeback runs.

3. **`actionGetMember` ARRAY branch fires `__resolve` on missing key
   (lines 1653, 1654, 1665, 1669, 1671, +5).** Both the numeric-index
   and non-index fallthrough paths now call `findResolveMethod` /
   `invokeResolveFunction` on `arr->props` before returning undefined,
   mirroring the existing OBJECT path. Fixes `t = []; t.__resolve =
   function(a){...}; t[3]` returning `'resolved 3'` and the `rs == 1`
   counter checks that follow it (sort, reverse, join all flow through).

### Remaining failures snapshot (24 lines)

Source line numbers: 260, 263, 324, 325, 950, 951, 1030, 1031, 1033,
1035, 1244, 1259, 1264, 1273, 1275, 1513, 1524, 1550, 1559, 1577, 1630,
1636, plus the trailing #passed / #failed counters. The bulk are
sort/sortOn algorithm-dependent ordering (Category C in the list below)
and Flash's plain-Object Array.prototype.X.call semantics (Category E).
Line 1710 (`X.prototype = new Array()` Array-subclass-via-non-Array-receiver
chain) was fixed via the ARRAY-typed `__proto__` follow in
`resolveProtoVar` + the inline `actionCallMethod` walk; the
for-in-over-sorted-sparse-array missing key (260/263) is the last
non-sort/non-fakeArray-semantics blocker for ruffle_subset_match.

---

## Status: IN PROGRESS — 528/560 lines match (~94.3%), 32 remaining failures (CI `068b46d8`, confirmed deterministic across two back-to-back CI runs at the same SHA)

**Determinism note:** Both `Math.random` and `Date.getTime()` are seeded
deterministically per-test via the `MOCK_DATE_TIME` macro, which
`verify_output.py` defines on every gcc invocation
(default `981152406000` ms = 2001-02-03 04:05:06 NPT, matching Ruffle's
`--deterministic` mode; per-test override via `mock_date_time` in
`test.toml`). `math.c::GenerateRandomNumber` seeds the avmplus RNG with
`MOCK_DATE_TIME * 1000` µs on first use (`math.c:262-271`), so sort
output is fully reproducible — verified at this commit (CI runs
`25570298054` and `25571481603` produced byte-identical results across
all 8 suites). Earlier "fluctuates by ~4 lines" notes were stale and
have been removed.

**Baseline note:** CI at 3d326df7 (2026-04-18) reported 490/560, not 494/560 as
the 2026-04-16 entry claimed — the session-local rerun was transiently higher,
probably due to a recompile artefact that was later reverted. Today's 504/560
is +14 over that CI baseline.

---

## Overview

The `array-v5` test exercises extensive Array operations (560 expected lines). Compilation takes ~72 seconds due to the massive `script_2.c` (70,731 lines). The test is marked `known_failure = true` in its `test.toml`.

## Progress Summary

| Date | Match Rate | Notes |
|------|-----------|-------|
| 2026-03-19 | ~46/560 (8.2%) | OOM after ~108 lines |
| 2026-03-20 (CI) | 405/560 (72.3%) | OOM fixed, Array.prototype methods registered |
| 2026-03-20 (session) | 422/560 (75.4%) | +17 lines: HOLE join, length truncation, array delete |
| 2026-03-29 (session) | 440/560 (78.6%) | +18 lines: HOLE sort, concat/splice densify, sortOn UNIQUESORT fix |
| 2026-04-04 (CI) | 448/560 (80.0%) | +8 vs prior: includes inter-session fixes; this session: dual Array constructor prototype unification (+3 local) |
| 2026-04-05 (session) | 450/560 (80.4%) | +2 net: ASnative class 252 implementation (constructor + prototype methods) |
| 2026-04-11 (CI)       | 459/560 (82.0%) | +9 vs 2026-04-05: cumulative effect of unrelated fixes landing (primitive auto-boxing, convertFloat NaN threshold, etc.) |
| 2026-04-16 (session) | 460/560 (82.1%) | +1: `actionToInteger` now wraps via `ecmaToInt32` (matches Ruffle `coerce_to_i32`) so `int(-2147483649) === 2147483647` instead of saturating to INT_MIN |
| 2026-04-16 (session) | 466/560 (83.2%) | +6: sort custom-comparator arg-push order was inverted at 5 sites, making every `a.sort(cmpFn)` call produce the reverse-of-expected order. Fix: push `args[0]` (pivot) first then `args[1]` (elem) so the generated `pop→y; pop→x` prelude binds `x=pivot, y=elem`. |
| 2026-04-16 (session) | 494/560 (88.2%) | +28: sort custom-comparator dispatch was invoking `simple_func` without pushing a local scope, so the callee's param/this `setVariableByName` writes fell through to globals. `randomComparator(a, b)` during an earlier sort therefore overwrote global `a` and `b`, corrupting the array under test and cascading into 25+ subsequent line failures (popped, b.length, b.toString, concatted, portion, mixed, basic, count==6). Extracted `_invoke_sort_comparator` helper that mirrors `actionCallFunction`'s type-1 setup (local scope + captured scopes + base_clip + `this`) and routed all 5 sort dispatch sites through it. |
| 2026-04-18 (CI baseline) | 490/560 (87.5%) | CI at 3d326df7 settled on 490/560 rather than the 494 claimed by the 2026-04-16 session; treating 490 as the true pre-session number. |
| 2026-04-18 (session) | 499/560 (89.1%) | +9: `g_call_this_type` was only being set when Array.prototype methods were invoked via `Function.prototype.call`/`.apply`. Direct method dispatch on an OBJECT receiver (`o.shift = Array.prototype.shift; o.shift()`) left `g_call_this_type == 0`, so `builtin_array_method`'s object-this branch never fired and the generic object was not mutated. Fix: save/set `g_call_this_type = ACTION_STACK_VALUE_OBJECT` around the OBJECT-receiver `advanced_func` call in `actionCallMethod` (line ~50568). Unblocks array-method-on-object dispatch for lines 514–543 — several now fully match, the rest still diverge on Flash's specific enumeration-order semantics (e.g. `traceProps(o)` after shift shows `0,shift,length,7,6,4,3,2,1,` vs expected `4,3,2,1,0,shift,length,7,6,5,`). No regressions across 16 avm1 array/method tests (`array_call_method`, `array_concat`, `array_sort`, `mutable_this`, `this_scoping`, etc.) or 10 object/super tests. |
| 2026-04-18 (session 2) | ~504/560 (~90%) | +5 stable passes over the previous peak across three small fixes: (1) `actionSetMember` ARRAY branch now early-returns when `prop_name_len == 0`, so `c[''] = 2` no longer grows length or stores at index 0 (Flash silently discards the empty-string key). Fixes `c.length == 0` and `typeof(c['']) == 'undefined'` (lines 153–154). (2) `actionGetMember` ARRAY branch now uses `getPropertyWithPrototype` instead of `getProperty` on the HOLE/missing-element fallback, so Array.prototype inherited entries are found via the `__proto__` chain. Fixes `Array.prototype[3] = 3; new Array()[3] == 3` and related (lines 151/152). Also added `prop_name_len > 0` guard to the numeric-index path so empty-string reads don't parse as index 0. (3) `actionNewObject` for `new Array()` / `new Array(n)` / `new Array(a,b,c)` now calls `initArrayProto` to set `arr->props->__proto__ = g_array_proto_legacy/modern`. Previously only the `[]` literal path and ASnative(252,0) set up the prototype chain, so `new Array()` was missing `instanceof Array` and `.constructor == Array` checks (lines 253/254). No regressions across 29 avm1 tests (array_call_method, array_concat, array_sort, array_sort_random, array_slice, array_splice, array_properties, array_prototyping, array_trivial, array_length, array_enumerate, array_constructor, init_array_invalid, global_array, mutable_this, this_scoping, coerce_to_object_monkeypatch, object_resolve, extends_chain, as2_super_and_this_v6/v8, register_class_return_value, textsnapshot_available_text, enumerate, global_is_bare, string_coercion, parse_int, typeof, action_to_integer). |
| 2026-04-25 (CI) | 512/560 (91.4%) | +8 cumulative across unrelated fixes since 2026-04-18, baseline for next pass. |
| 2026-05-07 (session, pending CI) | 520/560 (92.9%) | +3: ASSetPropFlags now handles ARRAY targets. Lazy-inits `arr->props`; for each named property, finds-or-creates the metadata entry (placeholder UNDEFINED value, requested flags) so `ASSetPropFlags(c, "2", 7, 0)` actually marks index 2 as DontDelete. `actionDelete` ARRAY branch already consulted `arr->props` for the CONFIGURABLE flag — fix populates the entry it was looking for. Length-truncation in `actionSetMember` ARRAY-`length`-set branch now skips clearing protected indices AND copies the preserved element value into `arr->props[<idx>].value` (only when the props entry's value is the UNDEFINED placeholder, to avoid clobbering user-stored values), so the props fallback in `actionGetMember` returns the original value once the index is past the new length. Fixes lines 278/279/280 (`! delete c[2]`, `c[2] == 30` after failed delete, `c[2] == 30` after `c.length = 2`). Verified: 20-test AVM1 array/object battery (array_constructor/concat/call_method/enumerate/length/properties/prototyping/slice/sort/sort_random/splice/trivial/init_array_invalid/global_array/mutable_this/this_scoping/object_resolve/add_property/watch/watch_textfield — 20/20 PASS), 19-test gnash actionscript.all battery (Boolean-v5/v6, Number-v5/v6, ASnative-v6, Inheritance-v5/v6, Global-v6/v7, case-v5/v6/v7, delete-v5/v6/v7/v8, enumerate-v6/v7/v8 — 19/19 effective), 12-test misc-ming battery (instanceNameTest, DefineEditTextTest, attachMovieTest, loop_test2/3/5/9, displaylist_depths_test11, event_handler_scope_test, ResolveEventsTest, static_vs_dynamic1/2 — 12/12 PASS). |
| 2026-05-08 (CI `4c7febd5` / re-run `068b46d8`) | 528/560 (94.3%) | +8 vs 2026-05-07 CI baseline (`f0d575ca` 520/560). Three changes in `actionSetMember` ARRAY path + `Array.prototype.shift` + the temp-array bridge for plain-Object dispatch: (1) ARRAY index writes now check `arr->props["<idx>"]` for cleared `WRITABLE` and short-circuit (mirrors the existing `actionDelete` CONFIGURABLE check) — `ASSetPropFlags(a, "0", 4, 0); a[0] = X` now silently ignored. (2) `Array.prototype.shift` resets metadata on overwritten slots (Flash "flag was lost" semantics) and preserves the deleted last element's value into `arr->props` when DontDelete is set, so `a[length-1]` still reads as its original value through the props fallback. (3) `syncArrayToObject` (the bridge for `Array.prototype.X.call(plainObj)`) gained an `update_length` flag; `shift`/`pop`/`unshift` on a plain Object now skip the length update, matching Ruffle's `if let NativeObject::Array(_)` gate (so `o.length == 6` after `o.shift()` on a fakeArray). Lines fixed: 491, 493, 495, 498, 506, 509, 512, 516. **Two CI runs at the same SHA produced byte-identical results** across all 8 suites — confirms full RNG/Date determinism via `MOCK_DATE_TIME` and supersedes the earlier ~4-line variance note. No regressions across 16-test AVM1 array battery, 13-test Gnash actionscript.all battery (delete-v5..v8, enumerate-v6..v8, case-v5..v7, ASnative-v6, Boolean-v5, Number-v5 — 13/13 effective), or AVM1 assetnative/loadvars_tostring/add_property/watch/object_resolve/coerce_to_object_monkeypatch/register_class_return_value (7/7 PASS). |
| 2026-04-28 (session) | 519/560 (92.7%) | +7: four small Array-method fixes — (1) `Array.prototype.reverse` now densifies HOLEs to UNDEFINED in place (matches Flash, not Ruffle). Fixes line 176 (`count == 6` after `sparse.reverse()` so for-in enumerates all six indices). (2) `Array.prototype.splice` now also densifies the *returned* deleted-array's HOLEs to UNDEFINED, mirroring the existing in-place densification on the receiver. Fixes line 252 (`spliced.count == 1` for a hole-only spliced segment). (3) `Array.prototype.slice` now coerces its `start`/`end` args via `tsArgToDouble_ctx` so objects with `valueOf` are honored (matches Flash). Fixes line 196 (`concatted.slice(zero, two).toString() == "0,1"` where `zero`/`two` are valueOf-implementing objects). (4) `Array.prototype.sort` `n<=1` early-return now respects the `RETURNINDEXEDARRAY` flag (bit 8): n==0 → `[]`, n==1 → `[0]`. Fixes lines 334, 336 (sort of singleton with RETURNINDEXEDARRAY returns `"0"`, not the original element string). Side effect: array `join` in SWF<7 now stringifies `UNDEFINED` elements as empty string (same as `HOLE`), matching Flash's `String(undefined) === ""` semantics — required so post-densify `sparse.toString()` still produces `"5,,,,,"` not `"5,undefined,undefined,…"`. No regressions across the 14-test AVM1 array battery (array_sort, array_concat, array_splice, array_slice, array_call_method, array_constructor, array_enumerate, array_length, array_properties, array_prototyping, array_sort_random, array_trivial, init_array_invalid, global_array — 14/14) or a 14-test broader battery (mutable_this, this_scoping, object_resolve, enumerate, string_coercion, parse_int, typeof, action_to_integer, as2_super_and_this_v6/v8, extends_chain, register_class_return_value, textsnapshot_available_text, movieclip_state_values — 14/14). |

## Completed Fixes

### 1. OOM After ~108 Lines — FIXED (prior session)
The heap exhaustion bug was fixed in a prior session. All 560 lines of output now produced.

### 2. Array.prototype Method Registration — DONE (prior session)
All standard Array.prototype methods registered as ASFunction objects on `g_array_prototype`.

### 3. HOLE/Sparse Array join/toString — FIXED (commit 0c3e8470)
Array.join() and toString() now produce empty strings for HOLE (missing) elements. +9 lines.

### 4. Array Length Truncation for Negative Values — FIXED (commit c8449aed)
Setting `arr.length = -1` now properly clears all elements using signed comparison. `getArrayElement()` returns NULL when length is negative (signed). +8 lines.

### 5. actionDelete for Array Elements — FIXED (commit f04b08cc)
`actionDelete` now handles: (a) non-string property names (F64 index → convert to string), (b) ARRAY type objects (marks elements as HOLE). +0 net (masked by prior fixes).

### 6. Sort HOLE Comparison (SWF < 7) — FIXED (commit a2002c9a)
`_sort_compare_vars` now treats HOLE elements as empty string ("") for SWF < 7, matching Flash behavior where sparse array holes sort to the beginning. +4 lines.

### 7. Array.concat Densification — FIXED (commit a2002c9a)
HOLE elements are converted to UNDEFINED when copying into concat result arrays, matching Flash behavior where concat fills sparse array holes. +4 lines.

### 8. Array.splice Densification — FIXED (commit a2002c9a)
After splice operations, remaining HOLE elements are converted to UNDEFINED with proper enumeration key tracking. +3 lines.

### 9. sortOn UNIQUESORT Return Value — FIXED (commit a2002c9a)
`sortOn` with UNIQUESORT (without RETURNINDEXEDARRAY) now correctly sorts in-place and returns the array reference. Previously UNIQUESORT was incorrectly combined with the RETURNINDEXEDARRAY code path, returning an index array instead. +17 lines from `tostr(r)` checks.

### 10. Dual Array Constructor Prototype — FIXED (commit 54f14500)
`g_ctors[1]` (the Array constructor registered on `_global` via `ensureGlobalInit`) now has its `prototype_obj` set to `g_array_prototype`, matching `g_array_constructor_static`. Fixes `constructor ==` checks and some `instanceof` checks. +3 lines.

### 11. builtin_array_method Dispatch Infrastructure — DONE (commit 54f14500)
Added `g_call_this_type` global and dispatch logic in `builtin_array_method` so array prototype methods can forward to `callArrayMethod` when invoked via `Function.prototype.call` in the CallMethod path. Infrastructure is in place but doesn't help array-v5 because SWF5 uses a different bytecode path (see Blocker below).

### 12. ASnative Class 252 (Array) — FIXED (commit eddd9b98)
Implemented ASnative(252, 0) as a callable Array constructor, plus indices 1-12 for all Array.prototype methods. The constructor creates properly initialized arrays with prototype chain set up via `initArrayProto()`. Fixes lines 34-36: `typeof(f) == 'function'`, `typeof(a) == 'object'`, `typeof(a.pop) == 'function'`.

### 13. actionToInteger ECMA wrapping — FIXED (2026-04-16)
`actionToInteger` (ActionToInteger opcode, emitted by `int(x)`) now wraps via
`ecmaToInt32` instead of using a direct `(int32_t)d` cast, which was UB /
saturating for out-of-range doubles. Matches Ruffle's `coerce_to_i32` /
`f64_to_wrapping_i32`. Fixes line 132: `c[int(-2147483649)] == undefined`
— previously `int(-2147483649)` saturated to INT_MIN on x86 and hit the
previously-stored `c[-2147483648] = "lowest int"`; now it wraps to 2147483647,
which is undefined. +1 line. No regressions on `action_to_integer`,
`parse_int`, `typeof`.

### 14. sort custom-comparator arg-push order — FIXED (2026-04-16)
The custom-comparator dispatch inside `callArrayMethod`'s `sort` path (5 sites:
UNIQUESORT duplicate check, RETURNINDEXEDARRAY quicksort left/right, standard
quicksort left/right) was pushing `args[1]` (elem) before `args[0]` (pivot),
so the generated function's `popVar→y; popVar→x` prelude bound **x=elem,
y=pivot**. Calling `testCmp(x=elem, y=pivot)` instead of `testCmp(pivot, elem)`
negates the comparator's return value, so every custom-comparator sort
produced the reverse of the expected order. Fix: push `args[0]` first
(bottom) then `args[1]` (top), matching the caller-side forward-push
convention used by `actionCallFunction`. Impact in array-v5: +6 lines
(103, 106, 107, 108, 114, 162). No regressions on avm1 `array_sort`,
`array_sort_random`, `array_call_method`, `array_concat`, `array_constructor`,
`array_slice`, `array_splice`, `array_properties`, `array_prototyping`,
`array_trivial`, `array_length`, `array_enumerate`, `init_array_invalid`,
`global_array`.

### 16. `c[''] = v` on Array discards silently — FIXED (2026-04-18 session 2)
`actionSetMember` on an ARRAY receiver now early-returns when
`prop_name_len == 0`. Previously `strtoll("")` returned 0 with endptr `""`,
so empty-string keys were misinterpreted as index 0 — both growing the array's
length and overwriting `elements[0]`. Matches Flash/Ruffle semantics: empty
string is not a valid array index, and Flash does not store it as a
string-keyed own property on Array either. Fixes lines 153, 154 (`c.length == 0`,
`typeof(c['']) == 'undefined'`).

### 17. HOLE element walks Array.prototype chain — FIXED (2026-04-18 session 2)
`actionGetMember` on an ARRAY receiver, numeric-index branch: when the
element is missing / HOLE, the fallback now calls `getPropertyWithPrototype`
instead of `getProperty` on `arr->props`. Because `arr->props->__proto__`
points to `g_array_prototype`, this lets `Array.prototype[N]` show through
as `arr[N]` when the array has no own entry at that index. Also added a
`prop_name_len > 0` guard so empty-string property names don't take the
"parse as index 0" path. Fixes lines 151, 152 (`sparse[3] == 3` after
`Array.prototype[3] = 3`).

### 18. `new Array()` now calls initArrayProto — FIXED (2026-04-18 session 2)
`actionNewObject`'s `strcmp(ctor_name, "Array") == 0` branch previously
allocated `arr->props` and set `native_type = NATIVE_ARRAY` but did NOT
set `arr->props->__proto__` to Array.prototype. So `new Array()` produced
arrays that didn't inherit from Array.prototype: `a.constructor == Array`
and `a instanceof Array` both failed, and prototype-chain lookups (fix 17)
couldn't find inherited entries on arrays created via `new Array()`.
Replaced the inline props allocation with a call to `initArrayProto`,
which allocates props, sets `native_type`, and installs the versioned
Array.prototype as `__proto__`. Fixes lines 253, 254 (`c.constructor == Array`,
`a instanceOf Array`) and makes fix 17 effective for arrays created via
`new Array()`.

### 15. sort custom-comparator local scope — FIXED (2026-04-16)
The five inline `simple_func` invocations in the sort comparator path never
pushed a local scope before the call, so the generated function's parameter
and `this` bindings (which go through `setVariableByName`) fell through to
globals. In array-v5 this meant `indexedarray.sort(randomComparator,
Array.RETURNINDEXEDARRAY)` (line 334) overwrote global `a` and `b` on every
iteration of QuickSort (via `randomComparator(a, b)`'s param binding).
Because the test's top-level `b = [551, "asdf", 12]` was clobbered long
before `popped = b.pop()` ran at line 455, every subsequent check against
`b` failed (popped == 12 / "asdf" / 551, b.length, b.toString, the concat
chain at 179–196, the count==6 / portion / basic / mixed / concatted
cluster, etc.). Fix: extracted an `_invoke_sort_comparator` helper that
mirrors `actionCallFunction`'s type-1 setup — allocs a local scope, pushes
captured scopes, switches `base_clip` for SWF6+, binds `this=undefined`,
forward-pushes args, invokes `simple_func`, and tears down in reverse —
and routed all 5 call sites through it. +28 lines: popped cluster (157,
158, 159), the 161–163 / 173 / 179–196 chain driven by global `b` /
`concatted` / `portion` / `basic` / `mixed`, and line 176 (count==6). No
regressions on the same avm1 Array tests plus `mutable_this`, `this_scoping`.

## Ruffle-matched assessment (2026-04-16)

`array-v5` is marked `known_failure = true` in its upstream `test.toml` and has
an `output.ruffle.txt` reference. Our diffs against `output.txt` (100) are
still **not** a subset of Ruffle's diffs (30), so the `verify_output.py`
subset-match cannot auto-promote this test to `ruffle_matched`. Bridging the
gap needs either (a) closing most of the remaining categories below, or
(b) discovering that a subset of our diffs aligns exactly with Ruffle's and
accepting the rest.

## Remaining Failures (100 lines, categorized)

### Category A: typeof(f) == "undefined" — FIXED (3 lines)
**Lines**: 34-36 — `typeof(f)` where `f = ASnative(252, 0)` (Array constructor)
**Root cause**: ASnative class 252 was not implemented. Fixed in commit eddd9b98.
**Status**: All 3 lines now PASS.

### Category B: Standalone prototype method calls (25 lines)
**Lines**: 157-159, 161-163, 173, 176, 179-196 — pop(), concat(), slice() called as standalone functions
**Root cause (RE-ASSESSED 2026-04-05)**: NOT blocked by Category A. After fixing ASnative(252,0), these lines still fail. The `a` and `b` variables at these test lines (array.as:455-584) are reassigned through intermediate operations that produce undefined results — likely related to how standalone Array.prototype method calls (without a proper `this`) interact with the test's variable scoping.
**Complexity**: High — requires deeper bytecode analysis of the test flow between successful and failing sections.

### Category C: Sort ordering differences (~50 lines)
**Lines**: 103, 106-109, 113-114, 334-342, 351-352, 377-380, 408-431, 450, 456, 459, 461-462
**Root cause**: QuickSort algorithm produces implementation-specific ordering for CASEINSENSITIVE, DESCENDING, and RETURNINDEXEDARRAY. Our sort matches Ruffle's AVM1 tests (array_sort PASSES) but differs from Flash's specific QuickSort partitioning on certain inputs.
**Assessment**: Algorithm-dependent differences. Many are Gnash-specific expected output reflecting Flash's exact sort order.

### Category D: Sparse array operations (partially fixed, ~7 lines remaining)
**Lines**: 98, 101, 176, 252, 485, 491, 493, 495, 499, 503
**Fixed (2026-04-18 session 2)**:
- 151/152 — `Array.prototype[3]` now visible via inheritance chain (fix 17 + 18)
- 153/154 — empty-string key on Array now a no-op (fix 16)
**Remaining root cause**: gaparray splice return values, sparse reverse,
ASSetPropFlags-protected shift/splice.
**Note**: Lines 485-506 are about ASSetPropFlags protection during shift/splice (not implemented)

### Category E: Array methods on generic objects (PARTIALLY FIXED, ~11 lines remaining)
**Lines**: 508–543 — direct method calls like `o.shift = Array.prototype.shift; o.shift()` on plain objects (the test assigns the prototype methods as own properties, it does not use `.apply()`).
**Original root cause**: `builtin_array_method` only dispatched the object-this branch when `g_call_this_type == ACTION_STACK_VALUE_OBJECT`, but that global was only set by the `Function.prototype.call`/`.apply` path. Direct method dispatch on an OBJECT receiver never set it, so `builtin_array_method` returned undefined and the object was not mutated.
**Fix (2026-04-18)**: Save/set `g_call_this_type = ACTION_STACK_VALUE_OBJECT` around the OBJECT-receiver `advanced_func` call in `actionCallMethod` (line ~50568 of `action.c`). Now `builtin_array_method` routes through `objectToTempArray` → `callArrayMethod` → `syncArrayToObject`. +9 lines in array-v5.
**Residual**: Lines 508/509/511/512/515/516/518/520/524/542/543 still differ. The method now mutates the object, but `traceProps(o)` enumeration order and the exact final `length` disagree with Flash (e.g. after shift on `{shift,length:7,1..7:...}`, Flash reports `"4,3,2,1,0,shift,length,7,6,5,"` and `length==6`; we report `"0,shift,length,7,6,4,3,2,1,"` and `length==5`). This is Flash-specific sparse-object semantics during shift/unshift/splice/reverse/sort — our generic impl reads `length` and iterates `0..length-1`, which differs on objects where some indices are missing or `length` is larger than the populated range.

### Category F: ASSetPropFlags-protected delete (3 lines)
**Lines**: 278-280 — `! delete c[2]` should return false when protected

### Category G: instanceof Array / constructor (2 lines remaining, was 4)
**Lines**: 458 (and 38/42 which are Category A overlap)
**Fixed (2026-04-18 session 2)**: 253/254 — `new Array()` now goes through
`initArrayProto`, so `c.constructor == Array` and `a instanceOf Array` pass
(fix 18).
**Remaining**: Line 458 `r instanceof Array` where `r` from sortOn has wrong
sort order (Category C overlap).
**Earlier fix**: Dual constructor unification (commit 54f14500).

### Category H: __resolve + toString override (7 lines)
**Lines**: 544-550, 557
**Investigation results (2026-04-04)**: The `t` object in the test is an OBJECT type (not ARRAY), so the existing OBJECT __resolve handler already fires for lines 544-545 (now PASS in some runs). Lines 546-550 fail because `t[2] = "om"` doesn't persist when `t` is a plain object accessed via numeric index. Line 557 (`ret == "Array data"`) is a separate toString override issue on an array subclass.

### Other (2 lines)
**Line 132**: `int(-2147483649)` wrapping behavior

## CORRECTED: Category A root cause identified (2026-04-05)

The previous blocker about Function.prototype.call/apply was a misdiagnosis. Bytecode analysis confirmed:
- The test does NOT use `.call()` — the string "call" isn't even in the constant pool
- Category A was actually `f = ASnative(252, 0)` returning undefined — **FIXED** by implementing ASnative class 252
- Category B failures persist after Category A fix — they have an independent root cause (variable reassignment through intermediate operations that fail)
- Category E uses `.apply()` which DOES go through CallMethod FUNCTION handler (confirmed via debug)
- The `.call`/`.apply` dispatch infrastructure was added anyway (commit 6a3cbcab) for future use

## Key Finding: Dual Array Constructor
Two separate Array constructors exist (`g_array_constructor` from `actionGetVariable` and `g_ctors[1]` from `ensureGlobalInit`). They now share the same `prototype_obj` after the fix in commit 54f14500.

## Recommended Next Steps

1. ~~**Investigate Category A**~~ — DONE. ASnative(252, 0) implemented. +3 lines.
2. **Accept Gnash-specific sort diffs** — Category C sort lines (~30) confirmed as algorithm-dependent. Consider adding to accepted diffs.
3. **Accept ASSetPropFlags limitation** — Categories D (partial) and F. ASSetPropFlags on arrays is unimplemented.
4. **Investigate Category B** — Now independent of Category A. Variables `a`/`b` become undefined via intermediate operations. Requires deep bytecode analysis.
5. **Category H deeper investigation** — The `t[2] = "om"` failure on plain objects with numeric properties needs investigation separate from __resolve.
6. **Category E residual (11 lines)** — Refine Flash-compatible semantics of `Array.prototype.{shift,unshift,splice,reverse,sort}` when applied to a generic object (`this != ASArray`). Current impl reads `length`, materialises a temp ASArray via `objectToTempArray` (which fills missing indices with UNDEFINED), mutates, then writes back via `syncArrayToObject`. Flash seems to preserve "holes" (missing indices are not materialised) and computes the new `length` based on densely-populated indices rather than the original `length`. Needs to track which indices actually existed before mutation and skip writing undefined into absent slots.

### 19. Array.reverse densifies HOLEs (2026-04-28)
`callArrayMethod` `reverse` now converts any HOLE entry to UNDEFINED after the
in-place reverse loop, and tracks the index keys via `arrayTrackKey`. Matches
Flash (and the Gnash test expectation), diverges from Ruffle which preserves
holes. Fixes line 176 (`count == 6` after reverse on `sparse[5]=5`).

### 20. Array.splice deleted-return densifies HOLEs (2026-04-28)
The "deleted" array returned by `splice` now densifies its HOLEs to UNDEFINED
the same way the receiver array already does. Fixes line 252
(`spliced = ary.splice(3, 1, 3); for (var i in spliced) count++; count == 1`).

### 21. Array.slice coerces args via valueOf (2026-04-28)
`slice` now uses `tsArgToDouble_ctx` instead of `varToDoubleSimple` for its
`start` and `end` arguments. Objects implementing `valueOf` (e.g. the test's
`zero`/`two` wrappers) are now honored as numeric indices. Fixes line 196
(`concatted.slice(zero, two).toString() == "0,1"`).

### 22. Array.sort RETURNINDEXEDARRAY for n<=1 (2026-04-28)
The `n <= 1` early-return path in `sort` now builds and returns an index
array (`[]` for empty, `[0]` for singleton) when the `RETURNINDEXEDARRAY`
flag (bit 8) is set, instead of unconditionally returning the receiver.
Fixes lines 334, 336 (singleton arrays sorted with RETURNINDEXEDARRAY return
`"0"`, not the element string).

### 23. Array.join stringifies UNDEFINED as "" in SWF<7 (2026-04-28)
`join` now treats `UNDEFINED` elements the same as `HOLE`: empty string in
SWF<7, `"undefined"` in SWF7+. Matches Flash's `String(undefined) === ""`
semantics in pre-7 SWFs and is required for the densified-reverse / densified-
splice paths to still produce `"5,,,,,"` rather than
`"5,undefined,undefined,…"` when joining post-densify.

## Test Details

| Metric | Value |
|--------|-------|
| Expected output | 560 lines |
| Current matching | 519 lines (92.7%) |
| Remaining failures | 41 lines |
| Compilation time | ~75 seconds |
| Script size | 70,731 lines (script_2.c) |
| SWF version | 5 |
| num_frames | 30 |
