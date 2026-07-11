# Session prompt — AVM2 Stage 3: tranche 1 (pure-language tests)

**STATUS: COMPLETE (2026-07-11).** 152/166 tranche-1 candidates pass
locally; every miss triaged (see
`ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md` and the
Stage-3 landing note in `SWFRecompDocs/plans/avm2-support-plan.md` §5).
Static census ceiling 61 → 1069 tests. Next session: Stage 4 (tranche 2 —
Vector/ApplyType is the biggest unlock at 80 censused tests, then JSON,
RegExp, proto edge cases).

You are implementing **Stage 3** of `SWFRecompDocs/plans/avm2-support-plan.md`.
Read that plan first (§4 architecture, §5 stages), then
`ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`, then skim the
Stage-2 code you are extending:

- `SWFRecomp/src/abc/abc_emit.cpp` (the C emitter — you will rework its body
  emission) and `SWFRecomp/include/abc/abc_ir.hpp` (the IR you consume; its
  header documents translation rules + divergences from Ruffle).
- `SWFModernRuntime/include/avm2/avm2_abc.h` (the emitter↔runtime contract),
  then the other `include/avm2/*.h` and `src/avm2/*.c` (~1,400 lines total —
  read them all; they are small by design).

Stage 2 landed at `0fec4fbe6` (+ `40e98bb42` CI, `03c86381d` AS3-bit gate).
CI baseline: **avm2 8/1198** (hello_world, duplicate_defs, eager_init,
lazyinit, nonconflicting_declarations, slot_disp_id_shared_numbering, swf8,
symbolclass_invalid_utf8); 1163 fail with a named unimplemented-op abort;
0 compile failures; zero AVM1 regressions.

## Goal

Plan §5 Stage 3 exit: **≥80 of the ~90 tranche-1 pure-language tests
passing; every miss triaged.** Tranche 1 = operators/bitwise, coercion,
int/uint/Number/Boolean, strings, arrays, OOP (inheritance, interfaces,
virtual properties, `super`), functions/closures, try/catch.

Candidate list (166 names, name-pattern superset of the ~90):
`ruffle-tests/tests/swfs/avm2/_investigation/TRANCHE1_CANDIDATES.txt`.

## Prepared data — use it to sequence the work

**Static opcode census** (new tool, parse-only, safe to run locally on the
whole corpus):

```
python3 SWFRecomp/tools/abc_op_census.py            # vs Stage-2 op set
python3 SWFRecomp/tools/abc_op_census.py --implemented op1,op2,...  # what-if
```

2026-07-10 run against the Stage-2 surface (22 ops): static op-surface
ceiling 61 tests (we pass 8 → even "covered" tests mostly fail on missing
builtins/coercions, not opcodes). Top blockers by test count:
SetPropertyStatic 653, Debug 650 (no-op), Add 603, Dup 567, Jump 482,
SetSlot 396, PushNull 396, PushTrue 394, NewFunction 387, IfTrue 345,
PushFalse 335, GetSlot 334, Kill 320, NewActivation 307, Swap 286,
Coerce 277, IfFalse 258, GetPropertyFast 249, GetGlobalScope 245,
PushDouble 242, PushUndefined 234, NewArray 222, LessThan 206, NewCatch 185,
FindProperty 183, Call 169, Equals 165, Construct 144, HasNext2 136,
NewObject 129. Implementing roughly those 30 raises the static ceiling to
~551 tests — the op set is NOT the long pole; **coercion/builtin semantics
are**. The census's greedy-unlock output gives a finer order.

**48 statically-covered-but-failing non-ignored tests** (need zero new
opcodes — only builtins/semantics; good early wins among them:
`class_to_string`, `object_to_string`, `string_length`, `unescape`,
`array_constr`, `namespace_constr_args`, `slots_force_autoassigned`,
`hasownproperty_namespaces`, `doabc_is_eager`, `documentclass`. Most of the
rest are display/timeline — Stage 5, don't chase them.)

## Deliverables (suggested order — commit at each observable checkpoint)

1. **Emitter: real control flow FIRST.** The Stage-2 trick of truncating a
   body after the first unsupported op is only sound because no branch op is
   emitted. Before implementing ANY of IfTrue/IfFalse/Jump/LookupSwitch you
   must switch to full-body emission: emit `op_N:` labels for every op that
   is a branch target (IrOp.target / switch_targets; exception target_op
   too), emit ALL ops of a body, and keep the unimplemented-op abort inline
   (no truncation) so partially-supported bodies still compile. Watch out:
   a label directly before `}` needs a trailing `;`.
2. **Emitter: the tranche-1 op set** (census order above). Notes:
   - PushDouble/PushUint need the doubles/uints pools emitted into
     `Avm2AbcFileData` (ints pool too for completeness — PushInt is already
     resolved to an immediate by the verifier).
   - GetPropertyFast/SetPropertyFast/GetPropertySlow/SetPropertySlow: lazy
     name popped from the stack (Fast = public-ns index-ish path per
     abc_ir.hpp; port semantics from Ruffle activation dispatch).
   - Dup/Swap/Pop are pure stack moves; Kill sets a local to undefined.
   - Debug is a no-op (like DebugFile/DebugLine).
   - HasNext2 mutates two locals (object + index registers) — see Ruffle.
3. **Runtime: coercion matrix + operators** (`avm2_value.c`): port
   `coerce_to_{number,i32,u32,string,object}` and `abstract_eq/lt` +
   Add's ECMA string/number split from Ruffle `value.rs` / `op` impls.
   **Number-to-string parity matters everywhere** — implement value.rs's
   MAX_PRECISION decimal/exponent formatting (the current `%.15g` stub will
   fail dozens of trace comparisons).
4. **Runtime: functions/closures/activation**: NewFunction (closure over the
   current scope chain), NewActivation (activation object for methods with
   METHOD_NEED_ACTIVATION), Call (call a function value with explicit
   receiver), `arguments`/rest per method flags (function_call_* tests),
   Function.prototype `call`/`apply`. GetSlot/SetSlot address the
   *innermost scope object* semantics used with activations — check Ruffle.
5. **Runtime: OOP completion**: getters/setters (PROP_GETTER/SETTER dispatch
   in avm2_ops.c is currently a fatal), interfaces (implements checking is
   mostly a no-op for trace tests, but `is`/`as`/istypelate need the
   interface list), GetSuper/SetSuper/CallSuper, proto-chain reads for
   dynamic classes, IsType/AsType/InstanceOf/TypeOf, Construct (new on a
   function value), NewObject/NewArray literals.
6. **Runtime: builtins** (`avm2_globals.c`, playerglobal-shaped): flesh out
   Object (toString/hasOwnProperty/…), Class, Function, String + methods,
   Number/int/uint/Boolean wrappers (constructors, toString/toFixed/
   toPrecision/toExponential), Array (the census shows array_* is the
   biggest single family — sort/splice/slice/join/…, avmplus sort quirks),
   Math if cheap, toplevel functions (isNaN, parseInt/parseFloat, escape/
   unescape, encodeURI family), and the Error class family.
7. **Typed exceptions**: Throw + exception-table dispatch. Tables are
   already emitted as data (`Avm2AbcException`, op-index ranges). Use the
   `setjmp`/`longjmp` pattern per plan §4.4 (g_exception_state precedent in
   the AVM1 runtime — but implement it in src/avm2/, not action.c!). Typed
   catch matching by class; NewCatch creates the catch-scope object
   (catch_scope_slot test). Error messages: port EXACT strings from Ruffle
   `error.rs` — many tests assert them.
8. **GC**: Stage 2 left every AVM2 allocation census-invisible/immortal
   (documented in avm2_object.c / avm2GcMarkRoots). Tranche-1 tests create
   real garbage (closures, strings, arrays in loops) but runs are short
   (MAX_FRAMES small), so immortality is still *correct*, just wasteful.
   Keep it unless something OOMs; if you do enroll AVM2 objects, follow the
   memory-reclamation rules (every C-side stash rooted or scrubbed) and the
   existing g_avm2_gc_mark_roots hook.

## Constraints & conventions (unchanged from Stage 2)

- Trunk-based; commit directly to `master`; autonomous commit/push/CI
  authorized (CLAUDE.md). Standard trailer.
- **Conflict boundary**: this work owns `SWFRecomp/src/abc/`,
  `SWFRecomp/include/abc/`, `SWFModernRuntime/{src,include}/avm2/`,
  `RecompiledABC/` emit paths. Do NOT touch
  `SWFModernRuntime/src/actionmodern/action.c` (concurrent AVM1 sessions).
  verify_output.py / ruffle-tests.yml already handle avm2 — you should not
  need to edit them this stage.
- **Zero AVM1 behavior change**; full pipeline (no-graphics CI) per
  `.claude/pipeline-handoff.md` at the end; confirm no pass→fail across
  avm1/gnash/shumway/regression and that `wasm-link-smoke` stays green.
- Do NOT run the full avm2 suite locally — single tests via
  `verify_output.py --test=NAME --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`;
  full suite via CI. The census tool and `--dump-abc` ARE local-safe.
- Keep the honest-failure property: any op/path you don't implement must
  still abort with a clear named message, never silently mis-execute.

## Stage-2 gotchas you must not trip over

- **DoABC emission is gated on the FileAttributes AS3 bit** (`03c86381d`):
  a DoABC in an AVM1 SWF is inert (gnash mixed-bytecode-as2 regressed when
  it wasn't). Don't weaken that gate.
- The avm2 build is selected by `RecompiledABC/` existing → verify_output
  adds `-DSWF_AVM2` + `src/avm2/*.c`; `main.c` dispatches to `runSWF_avm2`.
  If you add a new src/avm2/*.c file, add it to the list in
  verify_output.py `compile_native` (the one avm2-related edit you may
  need there).
- Dynamic-prop lookup matches by NAME ONLY (namespace ignored) — fine so
  far; `hasownproperty_namespaces` / `interface_namespaces` will force you
  to do this properly. Vtable lookup is a linear scan — fine at this scale.
- Trait slot_ids: 0 = auto-assign (next free); explicit ids reserve; an
  override keeps the parent's slot index (`slot_disp_id_shared_numbering`
  and `slots_force_autoassigned` exercise this).
- `Avm2Value` must stay 16 bytes (static assert in avm2_value.c).
- trace() joins args with a single space; output is plain stdout;
  boilerplate filter passes `^=== SWF Execution` / `^SWF Runtime Loaded`.
- Frame ticking is a Stage-5 stub: the root's frame-0 script runs once on
  tick 0 (avm2_main.c). Timeline tests (movieclip_*, goto_*) are NOT
  tranche 1 — don't fix them here, don't regress the stub either.
- The 9 corpus SWFs that fail verification are intentional (see
  CURRENT_STATUS Stage-1 table); their bodies emit VerifyError stubs. Some
  `verify_*` tests EXPECT specific VerifyError behavior at runtime — those
  become reachable once typed exceptions exist; check expected output
  before "fixing" anything there.

## Exit criteria

- ≥80 of the ~90 tranche-1 tests passing in CI (use TRANCHE1_CANDIDATES.txt
  ∩ tranche-1 categories as the denominator; report the exact list).
- Every remaining tranche-1 miss triaged (missing builtin vs. semantics gap
  vs. belongs-to-later-tranche), noted in CURRENT_STATUS.md.
- Zero pass→fail regressions in all AVM1 suites; avm2 suite shows no
  new shard-killing crashes; wasm-link-smoke green.
- Re-run `abc_op_census.py` with the new op set and record the new static
  ceiling in CURRENT_STATUS.md.

## End-of-session bookkeeping

- Stage-3 landing note in `SWFRecompDocs/plans/avm2-support-plan.md` §5
  (commits, op coverage, pass count, what's deferred).
- Update `ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`.
- Update the `avm2-as3-direction` memory (Stage 3 status, next stage).
- If partial, refresh THIS prompt with precise "resume here" state; if
  complete, mark it COMPLETE at the top (Stage-1/2 convention).
