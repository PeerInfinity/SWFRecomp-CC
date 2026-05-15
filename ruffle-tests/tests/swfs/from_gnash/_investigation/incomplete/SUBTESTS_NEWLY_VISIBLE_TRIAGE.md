# Triage: Newly-Visible `[subtests]` Tests
<!-- TESTS: Date-v5..v8, MovieClip-v6/v7/v8, Object-v5..v8, TextField-v6/v7/v8, Function-v5..v8, Stage-v6/v7/v8, XMLNode-v5..v8, XML-v5..v8, getvariable-v5..v8, setProperty-v5..v8, ops-v5/v6/v7, array-v6/v7/v8, argstest-v6/v7/v8, NetConnection-v6/v7/v8, Transform-v8, TextFormat-v8, flash-v8, Global-v5, BitmapDataDraw, GradientFillTest, PrototypeEventListeners, TextSnapshotTest, action_order/{PlaceAndRemove,action_execution_order_test,action_execution_order_extend_test}, loading/LoadBitmapTest, matrix_accuracy_test1, movieclip_destruction_test3, action_execution_order_test12, misc-swfmill.all/{registers,trace-as2/arguments} -->

<!-- PLAN_META
id: SUBTESTS_NEWLY_VISIBLE_TRIAGE
status: in_progress
phases:
  - id: 1
    name: "Tier A — near-passing (≥95% line match); land cheap fixes / ignored_tests promotions"
    status: in_progress
  - id: 2
    name: "Tier B — close (85-95%); split out per-family plans"
    status: not_started
  - id: 3
    name: "Tier C — mid (75-85%); identify shared root causes across families"
    status: not_started
  - id: 4
    name: "Tier D — deeper (50-75%); document scope before committing"
    status: not_started
  - id: 5
    name: "Tier E — shallow (<50%); decide accept-vs-investigate per test"
    status: not_started
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Shipped 2026-05-14 (commit 39b797ac, plan complete/SUBTESTS_HARNESS_PLAN.md). Discovery now resolves expected-output filename per-test."
blockers: []
-->

Last updated: 2026-05-15 (Tier B Object-v5 **landed RM** via three runtime fixes: toLocaleString delegation, broken __proto__ primitive-coercion bypass, ASSetPropFlags prototype hiding. Object-v6/v7/v8 still output_mismatch with widespread divergences. Tier A Date-vN RM (earlier this session).)

## 2026-05-15 — Tier B Object-v5 → ruffle_matched (+1 effective, pending CI)

Three runtime fixes in `SWFModernRuntime/src/actionmodern/action.c` flipped
`Object-v5` from `output_mismatch 137/145` to `ruffle_matched 142/145`
(diff 3 ⊆ ruffle 7):

1. **`Object.prototype.toLocaleString(1)` delegates to `this.toString()` with
   no args** (Object.as:641). Previously `g_object_toLocaleString_func.simple_func
   = builtin_object_toString` — a delegation hack that returned `"[object Object]"`
   directly, bypassing user toString overrides AND leaking the pushed args
   onto the stack (the dispatcher pushes `num_args` items but the C builtin
   pops 0, so `obj.toLocaleString(1)` ended up concatenating `1` + the bogus
   `"[object Object]"` into `"1[object Object]"`). Fix: intercept
   `toLocaleString` in the OBJECT-receiver dispatch in `actionCallMethod`
   *before* method lookup; if the resolved method's `simple_func` matches
   `builtin_object_toString`, free args (no leak), re-issue
   `actionCallMethod` recursively with `num_args=0` for `"toString"` so the
   user override (if any) runs with proper `arguments=[]` / `this=obj` setup.

2. **Broken `__proto__` skips own `toString` during implicit primitive
   coercion** (Object.as:875/883). When `nothing.__proto__ = undefined` and
   `nothing.toString = function() { return "toString"; }`, Flash's `Add2`
   stringification returns `""` in SWF<7 (or `"undefined"` in SWF7+) — it
   does NOT call the own toString. Fix: detect explicit
   `__proto__ in {undefined, null}` early in both `convertString`'s OBJECT
   branch and `actionAdd2`'s string-concat path (both `a` and `b` operands).
   When detected, skip the `objectCallToString` lookup entirely and emit
   the broken-proto fallback string. The check uses `getProperty(_, "__proto__", 9)`
   so it fires only when `__proto__` was *explicitly* assigned undefined/null
   (not for objects that simply never had `__proto__` set — those keep
   `"[object Object]"`).

3. **`ASSetPropFlags(func, null, 8193)` hides `func.prototype`** (Object.as:947/956).
   Bit `0x2000` of `flash_flags` hides at every version mask SWF5-8
   (`0x7480 / 0x7500 / 0x7000 / 0x6000` all include `0x2000`). Our impl
   stored function prototypes on `ASFunction.prototype_obj` (separate
   field), so ASSetPropFlags-iteration over `func->own_props` never
   touched the prototype slot. Two-part fix:
   - In `actionASSetPropFlags_func2`'s FUNCTION branch, when `apply_all`
     and `func->prototype_obj != NULL`, mirror the prototype value into
     `func->own_props["prototype"]` so the apply loop sets `flash_flags`
     on it.
   - In `actionGetMember`'s FUNCTION+`"prototype"` path, consult
     `findPropertyRaw(func->own_props, "prototype", 9)`'s `flash_flags`
     via `isPropertyHiddenAtVersion()` *before* the existing addProperty-
     getter / non-object-stored / lazy-create paths; on hit, push
     `undefined` and return.

**Test results post-fix (local, pending CI):**
- `Object-v5`: output_mismatch 137/145 → **ruffle_matched** 142/145 (diff 3 ⊆ ruffle 7)
- `Object-v6`: 282/333 → 286/333 (still output_mismatch; v6/v7/v8 share extra divergences)
- `Object-v7`: 295/333 → 299/333
- `Object-v8`: 295/333 → 299/333

**Regression battery (clean, no graphics):** 27-test AVM1 lifecycle/scope/
super/closure battery (closure_scope, as2_super_and_this_v6/v8,
extends_chain, register_class_return_value, on_construct,
funky_function_calls, enumerate, parse_int, typeof, primitive_type_globals,
constructor_function, define_function2_preload, add_property, watch,
function_as_function, function_base_clip, goto_methods,
swf5_to_6_cross_call, swf5_no_closure, assetnative, assetnative_ids,
set_interval, tell_target, execution_order2, goto_rewind3,
loadvars_tostring) — 27/27 PASS. 23-test Gnash actionscript.all battery
(ASnative-v5/v6, Boolean-v5, Date-v5/v8, Inheritance-v5/v8, case-v5/v6,
Number-v5, delete-v5/v6, array-v5/v6, Global-v5..v8, enumerate-v6/v7/v8,
Object-v5/v6) — Object-v5 RM, Object-v6/array-v5/v6 unchanged
output_mismatch (same line counts as baseline). Earlier `__constructor__`
Tier B fix (`a017c0f6`, 2026-05-15) preserved. AVM1 `date` test still
6289/6335 (unchanged from baseline).

**Why not full PASS:** Residual Object-v5 diff set is {7, 142, 143}.
- Line 7 (`typeof(Object.__proto__) == 'undefined'`): Ruffle-shared
  divergence — Ruffle also fails this against Flash's expected output,
  so it's in our ⊆ ruffle subset.
- Line 142 (`typeof(o) == "undefined"` after `delete o`): Ruffle-shared
  (we report typeof = "object" for a no-longer-defined name; Ruffle
  same).
- Line 143/144 (`#passed/#failed` summary lines): mismatch because our
  count rose to 139 passed but the Gnash expected captures 142 (Flash's
  count). Won't fix per `ACCEPTED_DIFFS.md` Category 1 pattern.

Object-v6/v7/v8 have widespread divergences out of scope for Tier B
(addProperty/watch counter mismatches, deep watch() machinery, +SWF6
addProperty hidden-inherited-setter — same residual the earlier
__constructor__ fix didn't reach).

## 2026-05-15 (earlier) — Tier B Object-vN: __constructor__ on new Object() (+8 lines)

Single targeted fix in `SWFModernRuntime/src/actionmodern/action.c`: new
objects created via `new Object()` (both the `NewObject` opcode at
`actionNewObject` and the `NewMethod` opcode at `actionNewMethod`)
now set `__constructor__` to the Object constructor function as an
**own property** with `PROPERTY_FLAGS_DONTENUM` + `flash_flags=0x80`
(hidden in SWF5 via the existing FLASH_HIDE_MASK 0x7480 → 0x80 hit; not
hidden in SWF6+ via mask 0x7500 → 0x80 miss). This matches Flash's
documented `__constructor__` behavior: gnash actionscript.all/Object.as
lines 151/154/156/176 (`check(obj.__constructor__ == undefined)` then
`ASSetPropFlags(obj, null, 8, 128+1)` then `check(obj.__constructor__ == Object)`
in SWF5; direct `check(obj.__constructor__ == Object)` and
`check(obj.hasOwnProperty('__constructor__'))` in SWF6+).

Shared helper: `ensureObjectConstructor()` hoists the lazy-init pattern
from inside the GetVariable("Object") `_CMP_BUILTIN_NAME` branch to file
scope, so both `actionGetVariable("Object")` and `actionNewObject` /
`actionNewMethod` return the same Object constructor function pointer.
Forward declarations for `registerGeomMethod` added near the helper.

**Test results post-fix (local):**
- Object-v5: 128 → 130 PASSED lines (135 → 137 matching) — still output_mismatch (5 ours-only diffs remain: 7, 83, 94, 95, 119, 122 — `Object.__proto__` SWF5 visibility, `Object.prototype.toLocaleString(1)` calling toString, primitive conversion with `__proto__=undefined`, `TestO.prototype` ASSetPropFlags 8193 hiding)
- Object-v6: 272 → 274 PASSED lines (279 → 281 matching)
- Object-v7: 285 → 287 PASSED lines (292 → 294 matching)
- Object-v8: 285 → 287 PASSED lines (292 → 294 matching)

**Regression battery (clean):** 10-test AVM1 lifecycle/scope battery
(closure_scope, as2_super_and_this_v6, extends_chain, register_class_return_value,
on_construct, funky_function_calls, enumerate, parse_int, typeof,
primitive_type_globals) all PASS. 10-test Gnash prototype/inheritance battery
(ASnative-v5/v6, Boolean-v5, case-v5/v6, delete-v5/v6, Inheritance-v5/v6,
Number-v5) all effective-pass. Date-v5..v8 still RUFFLE_MATCHED (the Tier A
fix from earlier this session is preserved). Global-v5/v6/v7 + Inheritance-v7/v8
all effective-pass.

**Why not full ruffle_matched promotion:** Object-v5 ruffle-diff set is
{7, 38, 46, 120, 121, 134, 139, 142}; ours-only is {83, 94, 95, 119, 122}.
These 5 require:
- Line 83 (toLocaleString(1) == "toString0"): toLocaleString should call
  toString **with no args** (not pass through args). Our impl probably
  inherits to `[object Object]` instead of calling Object.prototype.toString.
- Lines 94/95 (`"string + " + nothing == "string + "` after
  `nothing.__proto__ = undefined`): primitive conversion when `__proto__`
  is undefined should return empty string (SWF<7), not call own toString.
- Lines 119/122 (`TestO.prototype == undefined` after
  `ASSetPropFlags(TestO, null, 8193)`): need to honor flash_flags hiding
  on the FUNCTION+"prototype" GetMember path (currently reads via
  prototype_obj, bypassing flash_flags). Bit 0x2000 hides in SWF≤8.

Object-v6/v7/v8 have additional widespread divergences (addProperty/watch
counter mismatches reporting "65" instead of "1", `[type Function]`
toString regression from the Date-vN fix, and the deep watch() machinery)
that are out of scope for a quick Tier B sweep.



## 2026-05-15 — Tier A Date-v5..v8 landed (+4 effective, pending CI)

Three runtime fixes flipped all four Date tests from `output_mismatch` →
`ruffle_matched`:

1. **`new Date(undefined)` → treat as `new Date()`** (`date.c`,
   `actionDateConstruct` + `builtin_date_constructor`). Both functions
   now scan `args[]` and truncate `arg_count` at the first
   `ACTION_STACK_VALUE_UNDEFINED`. Matches Ruffle's argument-collection
   loop (`avm1/globals/date.rs::method()` breaks at first
   `Value::Undefined`) and the test source comment "Constructor with
   first arg == undefined also sets current localtime". Fixes line 93
   (`d2.valueOf() >= d.valueOf()`) on all four versions.

2. **Strict string-to-number for Date construction** (`date.c`,
   `date_arg_to_double`). Changed `varToDoubleSimple` (lenient `strtod`
   accepting "1234X" → 1234) to `varToDoubleSWF(app_context, v,
   EFFECTIVE_SWF_VERSION())` (strict — entire string must parse, else
   NaN). Matches Ruffle's `coerce_to_f64` / `string_to_f64` path. Fixes
   line 122 (`new Date("1234X").valueOf().toString() == "NaN"`).

3. **`Function.toLocaleString()` returns `"[type Function]"`**
   (`action.c`, FUNCTION-receiver arm in `actionCallMethod` around line
   60316). Previously `Date.toLocaleString()` walked the prototype chain
   to `Object.prototype.toLocaleString` → `builtin_object_toString`,
   which returns `"[object Object]"` unconditionally. Added a combined
   case for `toString` and `toLocaleString` that returns `"[type
   Function]"` by default (and honors an own_props override if
   present, with `toLocaleString` falling back to `toString` on
   own_props). Matches Ruffle, which aliases `Function.prototype.toLocaleString`
   to `Function.prototype.toString`. Fixes line 108 (`Date.toLocaleString()
   == Date.toString()`).

**Test results post-fix (local):**
- `Date-v5`: output_mismatch 305/315 → **ruffle_matched** (diff 7 ⊆ ruffle 10)
- `Date-v6`: output_mismatch 348/357 → **ruffle_matched** (diff 6 ⊆ ruffle 6)
- `Date-v7`: output_mismatch 349/357 → **ruffle_matched**
- `Date-v8`: output_mismatch 349/357 → **ruffle_matched**

Residual diffs vs `output.txt` are all in Ruffle's diff set too:
mock-date-time-driven `d.valueOf() > 1175385600000.0` failure
(Apr 2007 threshold vs our 2001 seed), the 3-line "pp known to fail"
int32 overflow lines (precision differs slightly between our and
Ruffle's path but both at same indices), and the summary counts.

**Regression battery (clean):** 12-test AVM1 prototype/scope/Date
battery (`closure_scope`, `as2_super_and_this_v6`, `extends_chain`,
`register_class_return_value`, `primitive_type_globals`, `enumerate`,
`parse_int`, `typeof`, `function_base_clip`, `constructor_function`,
`define_function2_preload`, `funky_function_calls`) all PASS. AVM1
`date` test unchanged (still 6289/6335 matching, same pre-existing
mismatches — none of the 3 fixes affect its diff set).

**ops-v5/v6/v7 (Tier A RM):** Already `ruffle_matched` via
`ruffle_subset_match` (diff 7 ⊆ ruffle 9/11). Inspection confirmed all
7 residual diff lines are Ruffle-vs-Flash divergences: `! (z == NaN)`,
`x != y` reflexivity, `_root == o` MC-equality, unsigned 32-bit shift
result (`y == -1` vs `4294967295`), etc. No action needed — the tests
already contribute to effective_pass; documenting per the plan was
sufficient.

## Status: IN PROGRESS — Tier A Date-vN complete; ops-vN are pre-RM

This doc inventories the 49 newly-discoverable `output_mismatch` tests
that appeared in CI `eb8206f8` (run `25896064893`, no-graphics) after
`SUBTESTS_HARNESS` shipped. They're grouped by line-match tier so we
can pick the cheap wins first and decide which deserve dedicated plans.

Out of 66 newly-visible tests across the four Gnash sub-suites, results
broke down as:

- **2 PASS**: `Global-v5` (actionscript.all), `misc-swfmill.all/trace-as2/arguments`.
- **8 ruffle_matched**: `ops-v5/v6/v7` (97.3% lines), `setProperty-v5/v6/v7/v8` (5.8% lines — RM because our diff is a subset of Ruffle's, not because we're close), `BitmapDataDraw` (55.4%).
- **49 output_mismatch**: triaged below.

`Global-v5` (PASS) and `BitmapDataDraw` (RM) mean some of these tests
*already* work end-to-end with no code changes — they were simply
hidden from our results. Expect a similar pattern across some of the
Tier A/B mismatches: the SWF runs cleanly, line diffs are tiny, and
the test is one Ruffle-vs-Flash quirk or one tiny bug from PASS.

## Source data

All numbers from `ruffle-tests/tests/swfs/from_gnash/{suite}/_results/results.json`
at commit `eb8206f8`. Per-test breakdown follows the tier tables.
The actionable signal for each tier is in the **"Next move"** line.

## Tier A — near-passing (≥95% line match), N=7 — **DONE**

| Test | Suite | Lines | % | Status |
|------|-------|------:|--:|--------|
| `Date-v7` | actionscript.all | 349/357 | 97.8% | **RM** (2026-05-15) |
| `Date-v8` | actionscript.all | 349/357 | 97.8% | **RM** (2026-05-15) |
| `Date-v6` | actionscript.all | 348/357 | 97.5% | **RM** (2026-05-15) |
| `ops-v5` | actionscript.all | 253/260 | 97.3% | RM (pre-existing) |
| `ops-v6` | actionscript.all | 253/260 | 97.3% | RM (pre-existing) |
| `ops-v7` | actionscript.all | 255/262 | 97.3% | RM (pre-existing) |
| `Date-v5` | actionscript.all | 305/315 | 96.8% | **RM** (2026-05-15) |

**All 7 Tier A tests now effective-pass.** Date-vN landed via the three
runtime fixes documented above (+4 effective, pending CI). ops-vN were
already auto-promoted via `ruffle_subset_match`; residual 7-line diff
is Ruffle-vs-Flash divergences (NaN compares, MC-equality, unsigned
shift), no action needed.

## Tier B — close (85-95%), N=9 — **Object-v5 DONE (RM 2026-05-15)**

| Test | Suite | Lines | % | Status |
|------|-------|------:|--:|--------|
| `array-v6` | actionscript.all | 604/644 | 93.8% | output_mismatch |
| `Object-v5` | actionscript.all | 142/145 | 97.9% | **RM** (2026-05-15) |
| `array-v7` | actionscript.all | 585/654 | 89.4% | output_mismatch |
| `array-v8` | actionscript.all | 585/654 | 89.4% | output_mismatch |
| `flash-v8` | actionscript.all | 36/41 | 87.8% | output_mismatch |
| `Object-v7` | actionscript.all | 299/333 | 89.8% | output_mismatch (+5 from Tier B) |
| `Object-v8` | actionscript.all | 299/333 | 89.8% | output_mismatch (+5 from Tier B) |
| `Object-v6` | actionscript.all | 286/333 | 85.9% | output_mismatch (+5 from Tier B) |
| `Function-v5` | actionscript.all | 135/158 | 85.4% | output_mismatch |
| `action_order/action_execution_order_test` | misc-ming.all | 16/19 | 84.2% | output_mismatch |
| `misc-swfmill.all/registers` | misc-swfmill.all | 30/36 | 83.3% | output_mismatch |

**Next move.** `array-v6/v7/v8` are likely the same shape as
`incomplete/ARRAY_V5_PLAN.md` covers for v5 — read the diffs and add a
cross-version section to that plan (don't open a new plan). `Object-v5`
vs `Object-v7/v8` is a meaningful gap: v5 close to passing suggests a
v5-specific path is solid and the v7/v8 paths share a different
divergence; worth splitting along that line.

## Tier C — mid (75-85%), N=21

| Test | Suite | Lines | % |
|------|-------|------:|--:|
| `Stage-v6` | actionscript.all | 54/64 | 84.4% |
| `Stage-v7` | actionscript.all | 54/64 | 84.4% |
| `Stage-v8` | actionscript.all | 54/64 | 84.4% |
| `XMLNode-v5` | actionscript.all | 174/207 | 84.1% |
| `XMLNode-v6` | actionscript.all | 174/207 | 84.1% |
| `XMLNode-v7` | actionscript.all | 174/207 | 84.1% |
| `XMLNode-v8` | actionscript.all | 174/207 | 84.1% |
| `Object-v6` | actionscript.all | 279/333 | 83.8% |
| `MovieClip-v6` | actionscript.all | 777/936 | 83.0% |
| `MovieClip-v7` | actionscript.all | 798/969 | 82.4% |
| `MovieClip-v8` | actionscript.all | 885/1087 | 81.4% |
| `getvariable-v7` | actionscript.all | 49/64 | 76.6% |
| `getvariable-v8` | actionscript.all | 49/64 | 76.6% |
| `getvariable-v5` | actionscript.all | 44/58 | 75.9% |
| `Function-v7` | actionscript.all | 205/272 | 75.4% |
| `Function-v8` | actionscript.all | 205/272 | 75.4% |
| `getvariable-v6` | actionscript.all | 48/64 | 75.0% |
| `loading/LoadBitmapTest` | misc-ming.all | 13/17 | 76.5% |

(plus `TextFormat-v8`, `TextField-v6/v7/v8` straddling the 73-74% line — see Tier D)

**Next move.** Several Tier C families show byte-identical line counts
across versions (Stage-v6/v7/v8 all 54/64, XMLNode-v5..v8 all 174/207).
That's a tell: the diff is one underlying issue shared across versions.
Read one diff per family, fix once. For `MovieClip-vN` (777-885 lines
matching out of 936-1087 expected — i.e. 150-200 mismatched per
version): probably a small handful of MC methods missing per version.
Compare against `complete/GNASH_FEATURE_PLAN.md`'s historical MovieClip-v5
notes (the v5 variant already shipped before SUBTESTS_HARNESS).

## Tier D — deeper (50-75%), N=11

| Test | Suite | Lines | % |
|------|-------|------:|--:|
| `TextFormat-v8` | actionscript.all | 128/172 | 74.4% |
| `TextField-v6` | actionscript.all | 404/545 | 74.1% |
| `TextField-v8` | actionscript.all | 416/571 | 72.9% |
| `TextField-v7` | actionscript.all | 414/570 | 72.6% |
| `Transform-v8` | actionscript.all | 71/101 | 70.3% |
| `Function-v6` | actionscript.all | 181/271 | 66.8% |
| `XML-v5` | actionscript.all | 281/449 | 62.6% |
| `XML-v8` | actionscript.all | 288/465 | 61.9% |
| `NetConnection-v7` | actionscript.all | 75/126 | 59.5% |
| `NetConnection-v8` | actionscript.all | 75/126 | 59.5% |
| `XML-v6` | actionscript.all | 288/486 | 59.3% |
| `XML-v7` | actionscript.all | 288/486 | 59.3% |
| `NetConnection-v6` | actionscript.all | 71/126 | 56.3% |
| `matrix_accuracy_test1` | misc-swfc.all | 10/18 | 55.6% |

**Next move.** These need scope before committing. `NetConnection-vN`
is mostly a stubs question (we have a stub but it likely doesn't
implement most members); decide accept-via-ignored_tests vs. full impl.
`XML-vN` and `XMLNode-vN` together are ~10 tests and likely share an
XML parser / DOM gap — combined plan, not per-version. `matrix_accuracy_test1`
diffs (see results JSON) look like a known fixed-point precision issue
(`_x: -107374182.4` vs `1073741824` — a sign/scale bug in twips→pixel
conversion); narrow target.

## Tier E — shallow (<50%), N=8

| Test | Suite | Lines | % |
|------|-------|------:|--:|
| `GradientFillTest` | misc-ming.all | 119/278 | 42.8% |
| `action_execution_order_test12` | misc-swfc.all | 9/22 | 40.9% |
| `TextSnapshotTest` | misc-ming.all | 49/132 | 37.1% |
| `movieclip_destruction_test3` | misc-swfc.all | 5/18 | 27.8% |
| `action_order/action_execution_order_extend_test` | misc-ming.all | 8/32 | 25.0% |
| `action_order/PlaceAndRemove` | misc-ming.all | 15/96 | 15.6% |
| `PrototypeEventListeners` | misc-ming.all | 1/32 | 3.1% |
| `argstest-v6` | actionscript.all | 44/2192 | 2.0% |
| `argstest-v7` | actionscript.all | 46/2061 | 2.2% |
| `argstest-v8` | actionscript.all | 46/2434 | 1.9% |

**Next move.** `argstest-v6/v7/v8` (2000+ expected lines, <50 matching)
strongly suggests an early-bailout / segfault that aborts the test
before most assertions run. Look for crash signature in CI logs; one
fix here unlocks ~6500 expected lines across the three. `GradientFillTest`
has dedicated plans already in `complete/CPU_GRADIENT_RASTERIZER_PLAN.md`
and `complete/WITH_SCOPE_GRADIENT_FILL_PLAN.md` — the 42.8% reflects
real feature gaps documented there. `PrototypeEventListeners` (1/32) is
almost certainly a crash too. The `action_order/*` cluster overlaps
with the existing `incomplete/MISC_MING_SWFC_PLAN.md` action-execution
tracking; check there first.

## Cross-cutting observations

### Some "ruffle_matched" tests have very low line-match

`setProperty-v5/v6/v7/v8` all show 3/52 lines matched but
`ruffle_matched` status with `ours_diff_count=ruffle_diff_count=49`.
Translation: 49 lines diverge for both us and Ruffle (against Flash),
and our 49-line diff is a subset of Ruffle's 49-line diff. This isn't
"we're close to passing" — it's "Ruffle disagrees with Flash on
basically the whole test, and so do we, identically". Likely candidates
for `RUFFLE_VS_FLASH_DIFFERENCES.md` or `ACCEPTED_DIFFS.md` rather than
fix targets.

### Per-family version cohorts

Many test families have versions with byte-identical line counts:

- `XMLNode-v5/v6/v7/v8`: all 174/207
- `Stage-v6/v7/v8`: all 54/64
- `setProperty-v5/v6/v7/v8`: all 3/52
- `XML-v6/v7`: both 288/486; `XML-v8` 288/465

That tells us the underlying bytecode / harness is version-agnostic for
those tests — version differences are mostly in player-version-gated
features that don't fire here. Fixing one version of each family fixes
all of them.

### What previous failure inventories underrepresented

Before SUBTESTS_HARNESS, `FAILING_TESTS_BY_FEATURE.md` listed e.g.
"MovieClip (1 failing / 1 total)" — implying we'd nailed the whole
feature. Actually only `MovieClip-v5` was discoverable. The post-CI
regenerated FAILING_TESTS_BY_FEATURE.md now shows the full version
cohort and should be the reference for prioritization going forward.

## Recommended attack order

1. **Date-v5/v6/v7/v8 (Tier A)** — likely single shared diff, four tests off the board. Probably <1 hour.
2. **ops-v5/v6/v7 (Tier A, RM)** — read the 7-line diff, decide ACCEPTED vs. fix. Either way clears the line item.
3. **Object-v5 alone (Tier B)** — close enough to pick off; reading the diff also informs the broader Object-vN cluster.
4. **array-v6/v7/v8 (Tier B)** — extend `incomplete/ARRAY_V5_PLAN.md`, don't open new plan.
5. **XMLNode-v5..v8 + XML-v5..v8 (Tier C + D)** — combined plan; shared root cause likely.
6. **MovieClip-v6/v7/v8 (Tier C)** — substantial work; compare against historical MovieClip-v5 fix notes in `complete/GNASH_FEATURE_PLAN.md`.
7. **argstest-v6/v7/v8 (Tier E)** — crash investigation; potentially unlocks 6500 lines.
8. **Everything else** — case-by-case as effort permits, or punt to ACCEPTED_DIFFS if Ruffle-vs-Flash quirks dominate.

## Out of Scope

- Regressions introduced this CI (`placeobject_occupied_depth`,
  `loop/loop_test10`, `RegisterClassTest4`) — those are unrelated to
  SUBTESTS_HARNESS; track in suite CURRENT_STATUS files.
- Image comparison subtests (`[image_comparisons.subtests.…]` if any) —
  out of scope per `complete/SUBTESTS_HARNESS_PLAN.md`.
- Runtime player-version override (Option B in SUBTESTS_HARNESS_PLAN);
  if any per-fp-version diffs become recurring blockers we can
  reconsider.
