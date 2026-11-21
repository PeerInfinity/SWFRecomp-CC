# w2-array-vector-args: Array/Vector argument semantics (session 23, wave 2, slot S5 of w1-drift-avm2)

**New files:** `w2-array-vector-args-report.md` (this), `w2-array-vector-args.patch`
(`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`;
3 files, +341/−52, runtime only: `avm2_array.c`, `avm2_vector.c`, `avm2_globals.h`). No new source files,
no new fixture dirs, no recompiler change, no `verify_output.py` / canary-list change.

Box: cloud, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Base `origin/master` = `68c0808a`
(carries `ca9c46595` and the other s23 landings). Tests downloaded at upstream **`aa9f62a70`**
(= `0ddd12b6a` + 1 visual commit, same as w1-drift-avm2). Flash oracle: **avmplus source**
(`github.com/adobe/avmplus`, sparse clone of `core/`): `Array.as` (ctor, `_join`), `ArrayClass.cpp`
(`generic_sort`, `ArraySort` ctor), `Vector.as` / `VectorImpl.as` (`sort`, `join`), `VectorClass-impl.h`.
Every rule below is read from that source, not inferred from the expected output.

---

## 0. Headline: GO — 5 of 5 rows flip to Flash-exact `pass`, both modes

The brief priced "2–3 full passes, rest partial". Measured: **all five pass**, status `pass`
(Flash-exact, not `ruffle_matched`), in graphics AND no-graphics.

| Row | KF | CI (`44922638965`) | before (clean `68c0808a`, this box) g / n | after g / n |
|---|---|---|---|---|
| `avm2/array_join_reentrant` | — | output_mismatch 58/68 | 58/68 / 58/68 | **pass 68/68** / **pass 68/68** |
| `avm2/vector_join_reentrant` | kf | output_mismatch 10/96 | 10/96 / 10/96 | **pass 96/96** / **pass 96/96** |
| `avm2/array_sort_arguments` | kf | output_mismatch 42/442 | 42/442 / 42/442 | **pass 442/442** / **pass 442/442** |
| `avm2/vector_sort_arguments` | kf | output_mismatch 1/355 | 1/355 / 1/355 | **pass 355/355** / **pass 355/355** |
| `avm2/array_constructor` | — | output_mismatch 21/234 | 21/234 / 21/234 | **pass 234/234** / **pass 234/234** |

Before legs are byte-for-byte CI's numbers, so local grading is CI-grade for these rows. The three
`known_failure` rows go fail → **pass** (Flash-exact; their Ruffle sidecars differ from Flash only in
frame names / the NUMERIC #1034, which we now match on the Flash side). No pixel axis: none of the five
has `[image_comparisons]`.

### EXPECTED-FLIP LEDGER (coordinator: check CI against this)

**Trace axis, both `graphics` and `no-graphics`, category `all`/`full` (avm2 suite):**

| Test | CI before | expected after |
|---|---|---|
| `avm2/array_join_reentrant` | output_mismatch | **pass** |
| `avm2/vector_join_reentrant` | output_mismatch | **pass** |
| `avm2/array_sort_arguments` | output_mismatch | **pass** |
| `avm2/vector_sort_arguments` | output_mismatch | **pass** |
| `avm2/array_constructor` | output_mismatch | **pass** |

(Do not confuse with `avm1/array_constructor`, a different test.)

**Pixel axis:** no expected moves. **Any other status move is a regression of this patch.**

Net: trace **+5 effective** (+5 pass) per mode; pixels ±0.

---

## 1. Mechanism and patch scope (owner `file:line` on the patched tree)

### 1a. Array.join length snapshot — `avm2_array.c` `array_join_inner` / `array_join`
avmplus `Array.as _join`: `s = String(sep)` FIRST, then `n = uint(o.length)` ONCE, then `o[i]` for every
`i < n` (`x != null ? out += x`). Ours iterated `i < ext->dense_len`, re-read live, so a reentrant
`toString` that pushed extended the output and one that popped/shifted/truncated shortened it. Now:
separator stringified, then length snapshot, then `avm2_array_get` + prototype hole resolution per index
(which also stops silently dropping sparse indices past `dense_len`). `sealed_generic_read` moved after the
separator (Flash reads `length`/`o[0]` after `String(sep)`). Guard: a length above `0x1000000` falls back to
walking dense storage only (FP would build a multi-GB separator string and die; no corpus row near it).
`Array.toString` shares the inner loop.

### 1b. Vector.join — `avm2_vector.c` `vec_join_inner` / `vec_join`
`VectorImpl.as join`: `limit = length` once, then `s += this[i]`, a typed range-checked read. So a pop/
shift/`length = 0` mid-join throws **RangeError #1125** at the first missing index ("The index 3 is out of
range 3."), and a push does not extend the output. Implemented as a live bound check against the snapshot.
The frame is renamed for the whole join (`Vector$object/http://adobe.com/AS3/2006/builtin::join()`), since
the Noisy `toString` that throws runs underneath it. `vec_push`'s two #1126 sites rename their frame to
`Vector$<spec>/http://adobe.com/AS3/2006/builtin::push()` (only at the throw; pushes are hot).

### 1c. Sort argument decode — `avm2_array.c` `avm2_sort_decode_args` (shared with Vector)
avmplus `ArrayClass::generic_sort`:
- arg0 an **object** → `coerce(arg0, Function)`: a non-Function object (including a CLASS like `Number`, which
  we used to accept as a comparator) is `#1034 … to Function`; then arg1, if present, must be a Number
  (`isNumberOrFloat`, no valueOf) else `#1034 … to Number`; options = `AvmCore::integer(arg1)` (ToInt32).
- arg0 a **Number** → options = ToInt32(arg0); every further argument ignored (`sort(16, {})` sorts).
- anything else (string, boolean, null, undefined) → `#1034 … to Function`.
- No argument ever has valueOf/toString called (the old path called `noisy.valueOf`).
Error-value spelling (`avm2_sort_arg_error_str`, avmplus `atomToErrorString`): `"str"`, `Name$` for a class,
`Function`, `[]@addr` for any Array, `ns::Name@addr` otherwise, primitives as ToString.
The old `argc > 1` branch took `args[0]` as the comparator unconditionally — fixed by the same decode.

### 1d. NUMERIC non-number #1034 — `avm2_sort_numeric_check` (called from `sort_apply`, `vec_sort_impl`)
avmplus `ArraySort::ArraySort`: when the compare is numeric (NUMERIC option, no comparator; DESCENDING too,
via `altCmpFunc`), the element read loop runs from the **last index down** and throws
`#1034 cannot convert <v> to Number` for the first element that is not a Number and whose `Number(v)` is NaN
— before anything moves. Not version-gated. This is the row the KF notes call "Sorting strings with NUMERIC
doesn't throw TypeError #1034 like in Flash Player" (Ruffle's gap; Flash behaviour). Implemented before any
allocation (a throw would otherwise leak the item arrays), interleaved in reverse exactly like avmplus.
`sortOn` is untouched (its NUMERIC goes through `FieldCompare`, which has no such check in avmplus).

### 1e. Frames — renamed at the sites, no `avm2_error.c` edit (sibling `w2-stack-trace-names` owns formatting)
- `Array.sort` (AS3 trait): own frame renamed to `Array/http://adobe.com/AS3/2006/builtin::sort`, plus a pushed
  native `Array$/_sort` frame for the duration (so a throwing comparator reports both, as in FP).
  `Array.prototype.sort` now gets its own wrapper (`array_sort_proto`) with no AS3-trait frame.
- `Vector.sort` (AS3 trait): `Vector$<spec>/http://adobe.com/AS3/2006/builtin::sort` + `Vector.<T>$/_sort`
  (`Vector.<*>`, `Vector.<int>`, `Vector.<uint>`, `Vector.<Number>`; reference-typed applications such as
  `Vector.<String>` are `Vector$object` / `Vector.<*>$` because they extend `Vector.<*>` — pinned by the row).
  Spec found by walking `cls->super_class` (`vec_spec_index`). Frame-name strings are static tables.
- Every rename saves/restores `call_depth` (the `convert_framed` idiom from `avm2_number.c`).

### 1f. Vector.sort arity #1063 — `vec_sort`
`AS3 function sort(comparefn)` has one parameter and no default: any other count is
`ArgumentError #1063: Argument count mismatch on Vector$int/http://adobe.com/AS3/2006/builtin::sort(). Expected 1, got N.`
raised by the CALL, so our own frame is popped first and `Function/…::apply()` is the top frame (as pinned).
`Vector.prototype.sort` (ES3 function, lenient) gets its own wrapper (`vec_sort_proto`) with no arity check;
it forwards `[comparefn]` like `VectorImpl.as`, so `undefined` there is #1034 to Function (Flash-correct).

### 1g. Array constructor — `avm2_array.c` `array_init_ctor_args` / `array_construct`
playerglobal's constructor is AS3 (`Array.as:56`): `if (n == 1 && args[0] is Number) { ulen:uint = dlen;
if (ulen != dlen) Error.throwError(RangeError, 1005, dlen); length = ulen; } else { length = n; this[i] = args[i]… }`.
- An `Array()` native frame is pushed for the duration of both the direct construct/call and
  `super(...)`-from-subclass init; the #1005 path additionally pushes `Error$/throwError` (existing helper).
- ToUint32 via `avm2_coerce_to_u32` (the old `(uint32_t) d` cast was UB for −1/1e10/±Inf).
- `length = …` is a **virtual** write: when the receiver's vtable `length` setter is NOT our native one (a
  subclass `override set length`), it is invoked through `avm2_set_public_property` (once, with `ulen` or
  `n`, elements still unset), so the override traces and can throw, under `Array()` / `ArraySubN()`.
  Plain Arrays and non-overriding subclasses keep the old direct path (so sealed-subclass semantics,
  `bug_654807_swf12/13`, are untouched — both still pass).

---

## 2. Regression, neighbour sweep and canary

### Neighbour sweep (graphics, after-leg; compared row-by-row to CI run `44922638965`)
- **Set A (by brief):** every `avm2/array_*` and `avm2/vector_*` row (76 besides the five), every
  `from_avmplus/ecma3/Array/*` (51) and `from_avmplus/as3/Vector/*` (60) = **187 rows**: status AND
  matching/expected line counts **identical to CI on all 187** (184 pass, 3 ruffle_matched:
  `array_access_oob_interpreter`, `array_sort_swf10_64bit`, `vector_indexing_cutoffs`, all already so on CI).
- **Set B (by argument):** every avm2/from_avmplus test whose `.as` calls `sort(` or declares `extends Array`
  outside set A, plus all of `from_avmplus/as3/Array/*` = **50 rows** (incl. `error_1034_debug_string`,
  `bug_654807_swf12/13`, `bug_535446`, `length_mods`, `regress_524122_swf10/11`, the JSON/AMF/describeType
  sorters): **identical to CI on all 50** (44 pass, 5 ruffle_matched, 1 output_mismatch `amf_xmllist` 4/12 —
  all unchanged).
- After the final leak fix (§1d placement), the 24 sort-touching rows plus the five headliners (g+n) were
  re-run: all unchanged/pass.
Because every after-leg equals CI's numbers exactly, no per-row before-leg was needed for the sweep (a patch
effect would have to cancel an independent master drift row-for-row to hide).

### Regression suite (`--tests-dir=ruffle-tests/tests/swfs/regression`, graphics)
`avm2_array_growth_bounded` 5/5, `avm2_gc_string_concat_reclaim` 10/10, `avm2_gc_string_survives_collect`
9/9, `avm2_json_roundtrip_bounded` 13/13, `array_element_type1_args` 7/7, `array_method_type1_args` 7/7,
`sort_comparator_captured_scope` 2/2, `sort_comparator_type1_args` 5/5: **all pass**. No new fixture: every
new behaviour is pinned by a corpus row with a Flash-generated `output.txt` (the five headliners).

### Graphics canary
`render_canary.py capture` before (clean `68c0808a`) vs after (patch), standing list, 95 tests:
**150 / 150 PNGs IDENTICAL (md5), 0 DIFFERS, no trace or image status change.** No canary member added:
the change class is trace-only (no render path touched).

---

## 3. Refutations / corrections to the brief

- Brief locations `avm2_array.c:1242` / `avm2_vector.c:1275` are the **registration** lines, not the loops;
  the live re-read was `array_join_inner` (`i < ext->dense_len`) and `vec_join_inner` (`i < ext->length`).
- "native frames `Error$/throwError()` + `Array()`" was right, but the rest of array_constructor's diff (the
  `set length(...)` trace lines and the four "setter throws" blocks) is the **virtual `length =`** in the AS3
  constructor, not frames.
- "Vector `sort()` arity" applies only to the AS3 trait; the prototype function is lenient.
- Pricing: the brief expected partials; all five reach full `pass`.

## 4. Not finished / residual risk

- Nothing in scope left. Known deliberate deviations kept (unchanged behaviour, no corpus row): Array `_join`
  uses `out += x` (ToPrimitive, valueOf first) where we call ToString; `Vector.join(undefined)` should
  stringify to `"null"` separators in FP (we use `","`); `Array.toLocaleString` still walks `dense_len` live.
  Completion mechanism: a regression fixture with a Flash/Ruffle-exporter oracle (below), then a 3-line change each.
- Behavioural widening worth CI attention (all Flash-correct per avmplus, no corpus row moved): a class
  object passed to `Array.sort` is now #1034 instead of a comparator; NUMERIC sorts of arrays containing
  `undefined`/holes/non-numeric strings now throw #1034 (avmplus `ArraySort` ctor, unconditional).

## New unclaimed leads

- `avm2_sort_arg_error_str` is a near-complete avmplus `atomToErrorString`; `avm2/error_1034_debug_string`
  (ruffle_matched 11/30) wants exactly this spelling at the generic coerce site (`avm2_coerce_to_class`
  in `avm2_class.c` has no `[]@` / `Name$` / `Function` / `MC{…}` forms). Owner: whoever takes
  `avm2_class.c` coerce messages; could reuse this helper.
- The `Vector$<spec>/http://adobe.com/AS3/2006/builtin::<m>()` spelling is applied only to join/sort/push.
  Every other Vector AS3 method still prints `__AS3__.vec::Vector.<T>/m()`. A general fix belongs in the
  frame formatter (`w2-stack-trace-names`' file); `VEC_SPEC_FRAMES` + `vec_spec_index` show the mapping.

## LOCAL ORACLE REQUESTS

Optional (only for the §4 deliberate deviations, not needed for this patch): a Ruffle-exporter or Flash run
of a 10-line AS3 movie tracing `[1,{valueOf:function(){return 5},toString:function(){return "x"}}].join()`,
`Vector.<int>([1,2]).join(undefined)` and `var a:Array=[]; a[5000000]=1; a.join().length`.
