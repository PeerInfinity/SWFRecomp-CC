# Arc: builtin prototypes as typed instances of their class

Session prompt for the next (Opus) session. Design pass done on Fable
2026-07-25; the mechanism decisions below are prescribed — execute them,
don't re-derive them. Where a slice says "read the test first", that is
load-bearing: the member tests define the exact expected strings.

## Goal

~8–11 `from_avmplus` tests (plus likely mechanism-overshoot surplus; see
Guardrails). #1 on `SWFRecompDocs/plans/feature-priority-map.md`. Subsumes
the old "sealed builtin prototypes (#1037)" item.

avmplus builds each builtin class's `prototype` as an *instance of that
class* carrying the class's default primitive value; we build every
prototype as a plain `Object`. Observable failures:

- `Boolean.prototype.valueOf()` → `true` (want `false`);
  `String(Boolean.prototype)` → want `"false"`
- `Array.prototype.length` → `undefined` (want `0`);
  `Object.prototype.toString.call(Array.prototype)` → `[object Object]`
  (want `[object Array]`)
- `String(Object.constructor.prototype)` → `[object Class]`
  (want `[object Object]`)
- Assigning to a builtin prototype *method trait* should throw #1037
  (the 2 Array #1037 tests)

Member tests (from `.pipeline-state`, all under
`ruffle-tests/tests/swfs/from_avmplus/ecma3/`):
`Array/e15_4_4`, `Boolean/{e15_6_3_1, e15_6_3_1_3, e15_6_4__1}`,
`ObjectObjects/{e15_2_3_rt, e15_2_3_1_rt}`, `String/{e15_5_2, e15_5_4}`,
`FunctionObjects/{e15_3_4_rt, e15_3_4__1_rt, ecall_1}`,
`Exceptions/{number_002_rt, string_002_rt}`, `Array/e15_4_1_1` + sibling
(#1037), `Date/e15_9_5`.

## Architecture facts (verified 2026-07-25, at fc9a9bdf4)

- **Two prototype construction sites**, both set `proto->cls =
  object_class`:
  - builtins: `avm2_globals.c:256-266` (`avm2_builtin_class`)
  - ABC user classes: `avm2_class.c:1036-1052` (`class_setup_prototype`)
- **Classification**: `Object.prototype.toString` generic branch
  (`avm2_globals.c:459`) prints the name of `avm2_value_class(v)`, which
  for objects is just `obj->cls` (`avm2_class.c:1279`). Tagging
  `proto->cls = cls` is what flips `[object Object]` → `[object Array]`.
- **Dispatch**: objects without an own vtable dispatch through
  `obj->cls->ivtable` (`avm2_value_class.c` / `avm2_value_vtable`,
  `avm2_class.c:1294`), and resolve order is **vtable traits → own
  dynamic → proto chain** (`avm2_ops.c:221`). So cls-tagging a prototype
  REROUTES method lookup on the prototype through the class ivtable —
  this is both the mechanism for #1037 (assigning to a method trait) and
  the crash hazard (native methods called with a prototype receiver).
- **Sealing**: `object_is_dynamic()` (`avm2_ops.c:141-149`) is
  `!(obj->cls->flags & AVM2_CLASS_FLAG_SEALED)`. Boolean/int/uint (and
  most builtins) are SEALED|FINAL. In avmplus, prototypes are dynamic
  even when their class is sealed — ES3 tests assign new props to
  builtin prototypes constantly, and our own bootstrap does too.
- **Receiver-guard precedent already in-tree** (this is the established
  pattern — copy it, don't invent):
  - `avm2_number.c:92-119` — `number_proto_to_string/value_of` treat a
    non-numeric receiver as `0` (comment explains the recursion death).
  - `avm2_string.c:575-589` — `string_proto_to_string` treats a
    non-string receiver as `""`.
  - Boolean has NO guard: `avm2_number.c:575-578` registers the
    *coercing* class methods (`boolean_value_of` = coerce receiver →
    object coerces to `true`) directly on the prototype. That is the
    `Boolean.prototype.valueOf() → true` bug.
- Array ivtable methods already guard on `kind == AVM2_OBJ_ARRAY`
  (`avm2_array.c:20`); ES3-compat functions are dynamic props on
  `Array.prototype` (`avm2_array.c:1101-1103`).

## Prescribed approach — four independent slices, in this order

Each slice: read the member tests' `Test.as` + current diff FIRST, land,
scoped-guard locally, then move on. Commit per slice or in pairs.

### Slice 1 — Boolean receiver-guarded proto shims (no retyping; safest)

Add `boolean_proto_to_string/value_of` following the Number pattern
exactly: boolean receiver → passthrough; anything else → `false`.
Register those on `Boolean.prototype` instead of the coercing class
methods. Expected: `Boolean/e15_6_3_1`, `e15_6_3_1_3`, probably
`e15_6_4__1`.

### Slice 2 — `Class.prototype` stringification

`class_proto_to_string` (`avm2_globals.c:603-620`): the non-class-object
receiver branch prints `[object Class]`; avmplus wants
`String(Object.constructor.prototype)` → `[object Object]`. Read
`ObjectObjects/e15_2_3_rt` + `e15_2_3_1_rt` for the exact expected
strings before choosing between hardcoding `[object Object]` and
classifying via `avm2_value_class`.

### Slice 3 — `Array.prototype` is a real empty array + `is_prototype` bit

The mechanism slice. Two parts:

1. Add an `is_prototype : 1` bit to `Avm2Object`; `object_is_dynamic()`
   returns true when set (prototypes stay dynamic regardless of class
   sealing). Set it at BOTH construction sites (harmless for user
   classes since their cls stays `object_class` — see Out of scope).
2. In `avm2_builtin_class` (or a post-hoc fixup for Array only), allocate
   `Array.prototype` as a genuine empty array instance
   (`AVM2_OBJ_ARRAY`, `cls = array_class`, is_prototype set, proto →
   `Object.prototype`). Keep the existing dynamic-prop ES3 layer on it.

Consequences to verify (these ARE the test assertions):
- `Array.prototype.length` → 0 (real storage, real length getter).
- Classification → `[object Array]`.
- SetProperty on an ivtable METHOD trait of the prototype (e.g.
  `Array.prototype.sort = x`) now resolves the trait first → must throw
  #1037. Read the two #1037 tests (`Array/e15_4_1_1` + sibling) to
  confirm which write produces it and that our setproperty path already
  throws #1037 on method-trait assignment (the static-const arc touched
  the adjacent read-only path; gate the OPCODE path only, never
  `avm2_object_set_dynamic` — bootstrap writes must stay ungated,
  see memory `avm2-static-const-readonly-dynprop`).
- New-name writes (`Array.prototype.foo = f`) must still succeed via the
  is_prototype bit. The ES3 suite does this everywhere — a scoped
  `--tests-dir .../ecma3/Array` guard catches a mistake immediately.

### Slice 4 — String/Number/Function/Date prototype classification (only if tests demand)

`String/{e15_5_2, e15_5_4}`, `FunctionObjects/{e15_3_4_rt, e15_3_4__1_rt,
ecall_1}`, `Exceptions/{number_002_rt, string_002_rt}`, `Date/e15_9_5`.
Read each diff first — some may already be fixed by slices 1–3 (e.g. the
Exceptions pair may only need the guarded shims' outputs). If one needs
`String.prototype`/`Number.prototype` cls-tagged, do it per-class and run
the re-entrancy audit below for that class before committing. Do NOT
blanket-tag all builtins in one change.

## Hazards — read before slice 3/4

1. **Self-coercion recursion** (memory
   `avm2-prototype-toString-self-coercion`, and it has bitten before —
   d90353066 shipped a crash this way). Once `proto->cls = cls`, ANY
   coercion of the prototype resolves `valueOf`/`toString` through the
   class ivtable. Audit that class's ivtable `toString`/`valueOf`/
   `toLocaleString` (and anything calling `this_number`/`this_string`-
   style coercers) for a prototype receiver: the guard must return the
   class default primitive (`0`, `""`, `false`), never coerce `this`.
2. **Native methods with a prototype receiver**: cls-tagging reroutes
   ALL method lookups on the prototype through the ivtable. For Array
   this is safe only because the prototype becomes a real array (slice
   3). For any other class you tag, check its native methods tolerate
   the receiver (Array-style kind guards, or a real-instance prototype).
3. **Dispatch-order shadowing**: dynamic-prop shims on a prototype are
   SHADOWED by ivtable traits once the prototype is cls-tagged (vtable
   resolves first). If you tag a class whose prototype carries guarded
   shims (Number, String, Boolean after slice 1), the guard must move
   into (or also exist in) the ivtable method, or the shim becomes dead
   and the coercing class method wins — recursion returns.

## Guardrails / process

- **Mechanism overshoot sweep** (memory
  `shared-mechanism-fixes-overshoot-estimates`): before CI, grep every
  failing test's `Test.as` for other users of the mechanism —
  `prototype\.(valueOf|toString)`, `toString\.call\(.*prototype`,
  `prototype\.length`, `prototype instanceof`, `#1037` — across
  `from_avmplus` AND `avm2` suites. That regex pass found every surplus
  flip last session before CI did.
- **Local testing**: single tests only
  (`python3 ruffle-tests/verify_output.py --test=NAME --diff`), plus
  scoped directory guards via `--tests-dir` pointed at a suite
  SUBDIRECTORY (e.g. `.../from_avmplus/ecma3/Array`, `.../ecma3/Boolean`,
  `.../ecma3/ObjectObjects`). NEVER a full-suite local run.
- **CI**: per `.claude/pipeline-handoff.md` — graphics mode,
  `categories=full` (this is AVM2 runtime emission). One `gh run watch`
  at a time; `pgrep -af "gh run watch"` before starting another. Analyze
  with `scripts/corpus_status_diff.py <sha> WORKTREE --per-suite`; diff
  the crash-bucket histogram, not just pass counts (baseline at
  fc9a9bdf4: segfault 3 / timeout 4 / runtime_error 21 / compile_fail 1).
- Docs: update `feature-priority-map.md` DONE line +
  `from_avmplus/_investigation/CURRENT_STATUS.md` + `.pipeline-state`
  after CI confirms.

## Out of scope

- Retyping ABC **user-class** prototypes (`class_setup_prototype`).
  avmplus does type them, but no in-scope test demands it and the blast
  radius (every user SWF) is large. Leave `cls = object_class` there;
  note it in the plan doc if a test surfaces later.
- `as3/RuntimeErrors` (13 tests, 0% match) — explicitly rejected; worst
  yield/effort on the board. Only harvest #1037 as a side effect if it
  happens to be in there.
- `as3/Vector` (next arc, needs a root-cause investigation — leave for a
  Fable session) and `ecma3/JSON` whitespace (the arc after).
