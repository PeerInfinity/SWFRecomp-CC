# Arc: builtin prototypes as typed instances of their class — **DONE**

Landed 2026-07-25 on Opus. **CI `30171938941` (graphics, `categories=full`):
+24 from_avmplus, 0 regressions, crash histogram flat** (segfault 3 /
timeout 4 / runtime_error 21 / compile_fail 1). Predicted 8–11.

Commits: `cc4a7eece` (slices 1–4), `e4d1e78f6` (Date), plus the
`avm2_array_proto_index` follow-up that repaired 11 avm2-suite regressions
CI `30170620108` caught.

from_avmplus 1431 → **1455/1574 (92.4%)**; corpus 3733 → **3757/4414**.

## What landed

- **`is_prototype` bit** on `Avm2Object`, set at both construction sites
  (`avm2_builtin_class`, `class_setup_prototype`). `object_is_dynamic()`
  honours it ahead of the class flags, so prototypes stay dynamic even
  when their class is SEALED.
- **`Array.prototype` is a genuine empty Array**, retyped in place
  (`AVM2_OBJ_ARRAY`, `cls = array_class`, fresh `Avm2ArrayExt`).
  `Array.prototype.length` → 0; `Object.prototype.toString.call()` →
  `[object Array]`.
- **Array's public `toString` method trait removed.** avmplus keeps
  Array's ES3 methods AS3-namespaced with a public prototype function
  alongside, so the public name is shadowable.
- **`Date.prototype` is a Date instance** (time value NaN). Unlike Array
  and Boolean, Date's ES3 methods really are public traits in avmplus,
  which is what makes `Date.prototype.valueOf = x` throw `#1037`.
- **Boolean prototype shims** (`boolean_proto_{to_string,value_of}`)
  instead of the coercing class methods, which read an object receiver as
  `true`.
- **`class_proto_to_string`** classifies a non-class-object receiver by
  its actual class instead of printing a blanket `[object Class]`.
- **`#1004` incompatible-receiver** for `Number/int/uint/String/Boolean`
  prototype `toString`/`valueOf`: the lenient "reads as the class default"
  behaviour is correct only for the prototype ITSELF.

## Two traps this arc discovered — read before typing another prototype

1. **Typed prototype ⇒ ivtable traits shadow the ES3 prototype
   functions.** `Cls.prototype.method.length` then reads the *trait's*
   arity, and `avm2_builtin_add_method` left that 0 — two instant
   regressions (`Array.prototype.join.length`, `.slice.length`). New
   `avm2_builtin_add_method_n` carries the arity; Array and Date use it.
   Any future typed prototype must do the same.
2. **`Array.prototype[3] = x` lands in ELEMENT storage**, not in a dynamic
   prop named `"3"`. Three separate hole-resolution paths looked only for
   the dyn prop, which cost 11 avm2-suite tests (`array_push`,
   `array_holes`, … , `function_call_via_apply`) in CI `30170620108`.
   They are now one exported `avm2_array_proto_index` that checks element
   storage *and* dyn props on every prototype in the chain.

The self-coercion hazard the plan warned about (memory
`avm2-prototype-toString-self-coercion`) did NOT bite: Array's prototype
became a real array (so `array_to_string` sees a valid ext) and Date's
carries a NaN time value. No crash-bucket movement in either CI run.

## Design-pass guesses that the tests contradicted

- `ecma3/Array/e15_4_1_1` is **not** a `#1037` test. It expects
  `arr.toString = Object.prototype.toString` to SUCCEED on an instance.
  Our public `toString` trait was what broke it.
- `ecma3/Array/e15_4_4` likewise requires `Array.prototype.toString = …`
  to land and the assigned function to win the next call.
- `String/{e15_5_2, e15_5_4}` and `FunctionObjects/{e15_3_4_rt,
  e15_3_4__1_rt, ecall_1}` were already passing at `fc9a9bdf4` — the plan
  listed them from the STALE no-graphics `results.json`.

## Overshoot (the usual, per `shared-mechanism-fixes-overshoot-estimates`)

Beyond the named members: `ecma3/Array/{e15_4_1, e15_4_2_1_3, e15_4_2_3}`,
`ecma3/Boolean/e15_6_4`, `ecma3/Number/{e15_7_4_2_2_rt, e15_7_4_2_4}`,
`ecma3/Exceptions/{number_001_rt, string_001_rt}`,
`ecma3/Expressions/e11_1_4`.

## Still open

- **`as3/Array/insertremove`** (1 test, was already failing at
  `fc9a9bdf4`). With a typed `Array.prototype`, `insertAt`/`removeAt`
  shift holes in a way that disagrees with prototype-supplied indices —
  the test sets `Array.prototype[5]`/`[8]`, then checks a hole-y array
  after shifting. It passed in CI `30170620108` (when hole lookups saw
  *nothing* on the prototype) and fails now, so the fix belongs in
  insertAt/removeAt's hole shifting, not in the lookup.
- Retyping ABC **user-class** prototypes (`class_setup_prototype` still
  leaves `cls = object_class`). avmplus does type them; no in-scope test
  demands it and the blast radius is every user SWF.
- Deliberately untouched: `String.prototype`/`Number.prototype` are still
  plain Objects. Nothing in the corpus demanded their classification, and
  the `#1004` guards cover the observable behaviour without exposing
  those prototypes to ivtable rerouting.
