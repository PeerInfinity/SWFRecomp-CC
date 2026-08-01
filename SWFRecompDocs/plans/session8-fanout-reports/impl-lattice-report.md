# ABC verifier static type lattice — implementation report (session 8, wave 2)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a1c3e50c26d32ba40`
Base: `1c7c23761` (master). Not committed, not pushed, no CI dispatched.
Patch: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/fc353b12-21e0-448b-a078-5acd5f22bb2e/scratchpad/wave2/lattice.patch`

Implemented exactly per `SWFRecompDocs/plans/abc-verifier-type-lattice-arc.md`:
option (a), Unknown-never-throws, linear walk with reset-to-Unknown at every
branch/switch/exception target, the four predicates of §4.3, the op model of
§4.4, the staged plan of §8, plus the §8 step-4 runtime robustness fix.

---

## 1. What landed

### Stage 0 step 1 — shared header (pure refactor)

New `SWFRecomp/include/abc/abc_typemodel.hpp` (678 lines) holds, moved verbatim:

- `enum TK` / `struct TV` and `struct AbcTypeModel` (was `abc_emit.cpp:1918-2371`)
- one `stackEffect(op, abc, pops, pushes, scope_delta)` (was
  `abc_verifier.cpp:1244-1426`), now `inline`

`abc_emit.cpp`'s `irStackEffect` is now a five-line wrapper that discards the
scope delta, so the emitter's second copy (and the third partial copy inside
`scoutStaticTypes`, which calls the wrapper) are gone. `abc_verifier.cpp` and
`abc_emit.cpp` both include the header.

One deliberate semantic addition: the shared `stackEffect` carries the
`op.arg1 < abc.pool.multinames.size()` guard the *emitter's* copy already had
and the verifier's did not. In the verifier this is unreachable (the cpool
range checks in phase 1 run first), so it is a no-op there.

**Byte-identity check.** The main tree carries `RecompiledABC/` caches emitted
by the pre-change binary at HEAD. Diffing them against this worktree's freshly
emitted output:

```
avm2/bitmap_data                    IDENTICAL
avm2/vector3d                       IDENTICAL
avm2/stage3d_texture                IDENTICAL
avm2/flash_media_video_constructor  IDENTICAL
avm2/stage3d_raytrace               IDENTICAL
avm2/scope_optimizations            IDENTICAL
avm2/construct_interface            IDENTICAL
avm2/verification                   IDENTICAL
avm2/verify_typecheck               DIFFERS  (intended: 4 bodies -> verify stubs)
avm2/rtqname_not_namespace          DIFFERS  (intended: 3 bodies -> verify stubs)
```

### Stage 0 step 2 + Stage 1 — the lattice pass

In `abc_verifier.cpp`, a **separate read-only walk that runs only after the
depth pass has succeeded** (risk R6: a body with both a depth and a type fault
still reports the depth one, and every body with no type fault is bit-identical
to before; risk R7: the pass never writes `out`).

- Values: `Unknown | Any | Class(C) | ClassOf(C)`; `Class` carries either an
  ABC instance index or one of ten builtin ids.
- Merge rule: none. `reset[]` marks op 0, every `Jump`/`IfTrue`/`IfFalse`/
  `LookupSwitch` target, every switch case target, every active exception
  handler target, and every op whose predecessor is a terminator; at each,
  stack and locals go to all-Unknown. A `broken` flag forces the same reset
  after any unreachable op, and a self-check resets whenever the modelled stack
  depth disagrees with the depth pass's `stack_at[i]`.
- `stack_at` was hoisted out of the phase-3 block so the type pass can use it
  as both the reachability map and the authoritative depth.
- Predicates (§4.3), all four armed:
  - `LookupSwitch` operand is `Class(C)`, `C != int` → **#1058** `... must be int.`
  - lazy-ns multiname's ns operand is `Any`, or `Class(C)` with `C` not
    Namespace → **#1058** `... must be Namespace.` The ns operand's depth is
    `pops - 2` for every family with an object operand and `pops - 1` for
    `find*`; both were read off `abc_emit.cpp`'s own `_rtns`/`_rtns_l`
    lowerings (`[obj, ns, name]` / `[obj, ns, name, value]`), not guessed.
  - `GetSlot`/`SetSlot` base is `Any` → **#1051**
  - base is `Class(C)`, `C` ABC-defined + sealed + non-interface +
    name-unambiguous, `slotCountOf(C) >= 0`, `slot0 >= slotCountOf(C)` →
    **#1026** `Slot n exceeds slotCount=m of C.`
- Op model exactly §4.4. `CoerceA` yields `Any` **only** from an affirmative
  input (risk R2). `FindPropStrict`/`FindProperty` stay Unknown.
  `GetPropertyStatic` yields `ClassOf(C)` only in the `getlex` idiom
  (immediately preceded by `FindPropStrict` with the *same* multiname naming an
  ABC class). All locals seed to Unknown including local 0.
- `latResolveTypeMn` requires `nameCount[name] == 1` for an ABC class and
  `nameCount[name] == 0` + a public-namespace QName for a builtin (risk R4).
- `SWF_VERIFY_TYPES=<csv>` makes the whole pass **report-only**: every hit is
  appended (swf path, method display name, method kind, body index, op index,
  error code, inferred type, detail) and verification still returns success.
  `abc_tool.cpp` sets the swf-path column via a new
  `setVerifierSourceLabel()`.
- Cost control: the walk is skipped entirely unless the body contains a
  `LookupSwitch`, a `GetSlot`/`SetSlot`, or a lazy-ns multiname op, and the
  `AbcTypeModel` is cached per `AbcFile`. The cache is dropped in
  `validateAbcFile()`, which both drivers call exactly once per `AbcFile`
  immediately before their body loop — `AbcFile` is a stack local in both, so
  its *address* is recycled between DoABC tags and is not a safe identity.

### §8 step 4 — runtime fatal → catchable

`SWFModernRuntime/src/avm2/avm2_ops.c`: the two `avm2_fatal` calls in
`avm2_op_getslot` / `avm2_op_setslot` are now one shared
`throw_slot_out_of_range()` that raises a catchable
`VerifyError "Error #1026: Slot %u exceeds slotCount=%u of %s."`. Slot arrays
carry an unused element 0, so the avmplus-visible slotCount is
`obj->slot_count - 1`.

Also updated: `abc_verifier.hpp`'s "the type lattice is deliberately NOT here"
comment (the arc doc asks for this explicitly), and a status block at the top
of the arc doc.

---

## 2. Stage-0 sweep vs the exit criterion

`SWF_VERIFY_TYPES` report-only mode over **every** `test.swf` under
`ruffle-tests/tests/swfs`, 4 parallel workers, one worker CSV per process:

```
rows: 7
avm2/rtqname_not_namespace  Test/method1  method  body 1  op  9  1058  Object      ns operand statically Object
avm2/rtqname_not_namespace  Test/method2  method  body 2  op 11  1058  Object      ns operand statically Object
avm2/rtqname_not_namespace  Test/method3  method  body 3  op 17  1058  *           ns operand statically *
avm2/verify_typecheck       Test/method1  method  body 1  op  3  1058  Number      lookupswitch index statically Number
avm2/verify_typecheck       Test/method2  method  body 2  op  4  1051  *           early-bound slot access through `*`
avm2/verify_typecheck       Test/method3  method  body 3  op  6  1026  SlotClass   slot 2 exceeds slotCount=1
avm2/verify_typecheck       Test/method4  method  body 4  op  5  1026  SlotClass   slot 2 exceeds slotCount=1
```

**Exit criterion MET, on the first run.** Exactly `verify_typecheck` (4 rows)
and `rtqname_not_namespace` (3 rows), nothing else. No predicate needed
weakening, no exception list exists. All seven rows are `method` kind — zero
hits on a script init or class init (risk R9's hard stop did not trigger).

Coverage was proven separately with an armed control pass that captured the
`ABC-CHECK` summary for every file:

```
files reported: 4473    files on disk: 4473    bodies: 92529
  3013 status=OK   1445 status=NO_ABC   13 status=VERIFY_FAIL   2 status=PARSE_FAIL
```

All 13 `VERIFY_FAIL` files are the corpus's intentional verify-error tests
(`verify_illegal_opcode`, `verify_stack`, `verify_dxns_without_flag`,
`verify_jump_to_middle_of_op`, `verify_exception_target_two_jumps`,
`json_errors`, `verification`, `cpool_index_invalid_bytecode_{1,2,3}`,
`regression/avm2_tolerant_verify_quarantine`) **plus** the two targets. Not one
other corpus SWF changed verification outcome — i.e. zero method bodies were
turned into throwing stubs anywhere else (risk R1 clear).

---

## 3. Canary ledger

Baselines are `_results/results_graphics.json` in the main tree at HEAD; "after"
is a local `--recompile` run in this worktree.

### Targets

| test | before | after |
|---|---|---|
| `avm2/verify_typecheck` | `runtime_error`, 0/4 lines (`AVM2 fatal: GetSlot 1 out of range`) | **PASS** |
| `avm2/rtqname_not_namespace` | `output_mismatch` 9/12 | **PASS** |

### Arc-doc §8 per-commit canary list

| test | before | after |
|---|---|---|
| `avm2/scope_optimizations` | `output_mismatch` 3/4 | `output_mismatch` 3/4 — **unchanged**, same single diff (`[class field]` vs `0`) |
| `avm2/verify_stack` | pass | PASS |
| `avm2/verify_illegal_opcode` | pass | PASS |
| `avm2/verification` | pass | PASS |
| `avm2/construct_interface` | pass | PASS |
| `avm2/method_without_body` | pass | PASS |
| `avm2/cpool_index_invalid_bytecode_1` | pass | PASS |
| `avm2/cpool_index_invalid_bytecode_2` | pass | PASS |
| `avm2/cpool_index_invalid_bytecode_3` | pass | PASS |

### `regression` suite (full, 70 tests, -P 2)

**70/70 PASS**, baseline 70/70 pass. Zero flips.

### Exposure-heavy canary (content-selected, all `pass` at baseline)

Selected by an opcode census (`--dump-abc`) over all 2,803 avm2 +
from_avmplus SWFs: the top getslot/setslot files, the top `lookupswitch` files,
and the top `ConstructProp` files (the doc's §5 "one place Stage 1 genuinely
evaluates #1026 on real code").

| test | slots / switch / cprop | before | after |
|---|---|---|---|
| `from_avmplus/ecma3/GlobalObject/e15_1_2_3_1` | 593 slots | pass | PASS |
| `from_avmplus/ecma3/String/e15_5_4_4_4_rt` | 489 slots | pass | PASS |
| `from_avmplus/ecma3/GlobalObject/e15_1_2_2_1` | 421 slots | pass | PASS |
| `from_avmplus/as3/Definitions/Function/functionReturnTypes` | 397 slots | pass | PASS |
| `from_avmplus/as3/Vector/vectorIndexRangeExceptions` | 388 slots | pass | PASS |
| `from_avmplus/as3/ByteArray/ByteArray` | 386 slots | pass | PASS |
| `from_avmplus/as3/ByteArray/ByteArrayLzma` | 379 slots | pass | PASS |
| `avm2/stage3d_raytrace` | 50 switch | pass | PASS |
| `from_avmplus/ecma3/ObjectObjects/e15_2_1_1_rt` | 15 switch | pass | PASS |
| `from_avmplus/regress/bug_420755` | 10 switch | pass | PASS |
| `from_avmplus/ecma3/String/e15_5_4_8_1_rt` | 9 switch | pass | PASS |
| `from_avmplus/as3/Types/Conversions/ImplicitConversionsString` | 8 switch | pass | PASS |
| `from_avmplus/ecma3/String/e15_5_4_6_2_rt` | 7 switch | pass | PASS |
| `from_avmplus/as3/Definitions/Classes/Ext/ExtPublicClassPriv` | 6 switch | pass | PASS |
| `avm2/away3d_advanced_shallow_water_demo` | 696 cprop | pass | see note |
| `avm2/vector3d` | 187 cprop | pass | PASS |
| `avm2/flash_media_video_constructor` | 118 cprop | pass | PASS |
| `avm2/stage3d_texture` | 111 cprop | pass | PASS |
| `avm2/stage3d_agal_upload_errors` | 105 cprop | pass | PASS |
| `avm2/bitmap_data` | 104 cprop | pass | PASS |
| `avm2/stage3d_program_constants_bytearray_be` | 98 cprop | pass | PASS |

Note on `away3d_advanced_shallow_water_demo`: the first (parallel) run reported
`COMPILE_FAIL` at `c=302.29s`, i.e. it hit `verify_output.py`'s 300s
`compile_timeout` exactly, on a machine at load average 22 (five other agents).
Its CI baseline compile is 83s. Re-run result below. **This is the known
shared-machine LONG-COMPILE false positive, not a code fault** — the change
cannot affect codegen for a body with no type error, and this SWF produced zero
rows in the Stage-0 sweep.

**Sequential re-run with `SWFRECOMP_COMPILE_TIMEOUT=1500`:
`away3d_advanced_shallow_water_demo... PASS [r=5.24s c=382.90s x=8.30s]`.**
False positive confirmed; the ledger entry is pass → PASS. Net exposure canary
result: **21/21 PASS**.

### `runtime_error` blast radius of the `avm2_ops.c` change

Corpus-wide there are exactly two `runtime_error` tests at baseline:
`avm2/verify_typecheck` (fixed by this arc, and it no longer reaches the op at
all) and `from_avmplus/regress/bug_483783`. The latter was re-run with the new
runtime and is unchanged — it dies on `heap_alloc(76398) failed - out of
memory`, unrelated. Since the fatal only ever fired where the process already
died, the fatal→catchable conversion has **zero** corpus delta and is pure
robustness.

---

## 4. Predicted CI delta (`mode=graphics`, `categories=full`)

| metric | before | after |
|---|---|---|
| `runtime_error` | 2 | 1 |
| `output_mismatch` | 292 | 290 |
| `ruffle_matched` | 244 | 244 |
| `recomp_fail` | 1 | 1 |
| avm2 pass | +2 | |

Corpus: 4153/4424 → **4155/4424**.

Watch item per the arc doc: any rise in `output_mismatch` or any *new*
`runtime_error` means a spurious `VerifyError` deleted a body — the instruction
is to revert the predicate, not patch it. The Stage-0 sweep says that cannot
happen on this corpus (it names 2 files out of 4,473), but the sweep only sees
files we have.

---

## 5. Deviations from the scoping doc

1. **`stackEffect` gained a multiname bounds guard** when it became shared
   (the emitter's copy already had it; the verifier's did not). Unreachable in
   the verifier. Keeps one copy usable from both.
2. **The `AbcTypeModel` cache is invalidated in `validateAbcFile()`** rather
   than at an explicit driver call site. The doc did not address the cache; the
   subtlety is that `AbcFile` is a stack local in both drivers, so pointer
   identity alone is unsafe across DoABC tags. `validateAbcFile` is the one
   function both drivers call exactly once per `AbcFile`.
3. **`#1058` on a lazy-ns op declines to fire when the resolved class is an ABC
   class whose local name is literally `Namespace`.** The doc's predicate is
   "`Class(C)` with `C != Namespace`"; a user class named `Namespace` is
   indistinguishable from the builtin to us, so we decline to decide rather
   than throw. Strictly weaker; zero corpus effect (no such class exists).
4. **`Kill`/`IncLocal`/`DecLocal`/`HasNext2` clear the locals they write.**
   Not in §4.4's list, but §4.4's fall-through ("everything else: consume pops,
   push pushes × Unknown") would have left a *stale affirmative* type in a
   local those ops overwrite — the one way the fall-through rule is unsound in
   the throwing direction. Strictly weaker.
5. **A `broken` flag + a stack-depth self-check force extra resets** beyond the
   doc's target set (after unreachable ops, and on any disagreement with
   `stack_at`). Strictly weaker; belt and braces.
6. Added a status block to the arc doc itself, and updated
   `abc_verifier.hpp`'s "deliberately NOT here" comment as the doc §10 asks.

None of the deviations makes any predicate fire more often; all five code
deviations make the lattice *more* conservative.

---

## 6. Suggested commit message

```
avm2: static type lattice in the ABC verifier (#1058/#1051/#1026)

Adds the second verifier pass scoped in
SWFRecompDocs/plans/abc-verifier-type-lattice-arc.md: a linear walk over the
resolved IR with a four-value lattice (Unknown / Any / Class(C) / ClassOf(C))
that raises the avmplus type errors the existing depth pass cannot see.

The design decision is option (a): Unknown NEVER throws. avmplus's opposite
rule ("not provably typed => throw") is only safe for avmplus because its
lattice is total; ours models a few dozen ops out of ~160, so for us "no class"
means "we didn't look", not "the type is *". Conflating them would report a
property of the recompiler as a property of the program — and a false positive
here is not a wrong trace line, it replaces a whole method body with
avm2_verify_error_body(). There is no merge lattice either: the stack and all
locals reset to Unknown at every branch, switch and exception target, the same
bail abc_emit.cpp's shipping TK/TV coerce-elision walk already uses.

Predicates armed (all four of the doc's §4.3):
  #1058  lookupswitch discriminant that is affirmatively not int
  #1058  RTQName/RTQNameL namespace operand that is affirmatively not Namespace
  #1051  getslot/setslot base that is affirmatively `*`
  #1026  slot index past a sealed ABC class's slotCountOf()

Also promotes AbcTypeModel, the TK/TV lattice and ONE stackEffect into the new
shared include/abc/abc_typemodel.hpp (there were three copies of the stack
effect table); irStackEffect is now a wrapper. Emission is byte-identical.

SWF_VERIFY_TYPES=<csv> runs the whole pass report-only, which is how the
predicates were audited: over all 4473 corpus SWFs (92529 bodies) the CSV names
exactly verify_typecheck (4 rows) and rtqname_not_namespace (3 rows) and
nothing else, and no other file changes verification outcome.

Separately, avm2_op_getslot/avm2_op_setslot's out-of-range avm2_fatal becomes a
catchable VerifyError #1026 (throw_slot_out_of_range). The fatal killed the
process before any buffered trace was flushed; it only ever fired where we were
already dying, so this has no corpus delta and is pure robustness.

avm2/verify_typecheck runtime_error -> pass, avm2/rtqname_not_namespace 9/12 ->
pass. avm2/scope_optimizations stays 3/4: it needs static early BINDING of
findpropstrict against a typed scope stack, which changes emitted code, not
just errors — deferred to its own arc (doc §3.3, Stage 3).

Canaries: regression suite 70/70, the doc's nine-test verify canary list
unchanged, and 21 content-selected exposure-heavy tests (top getslot/setslot,
lookupswitch and ConstructProp files in avm2 + from_avmplus) all still pass.

Co-Authored-By: Claude Fable 5 <noreply@anthropic.com>
Claude-Session: https://claude.ai/code/session_01TQjLqdJcGxSfyAFAhSECvA
```

CI to run on merge: `mode=graphics`, `categories=full` (this touches AVM2
recompiler emission), `images=false`.
