# ABC Verifier Static Type Lattice — Arc Scoping

Status: **scoped, not started** (2026-07-31)
Origin: `SWFRecompDocs/plans/polish-sweep-arc.md` §8.7 ("Taken and
deliberately NOT taken").
Scope: recompiler only (`SWFRecomp/src/abc/abc_verifier.cpp`). No runtime
changes are required for the yield; one optional runtime robustness fix is
listed separately.

---

## 0. TL;DR

- **Design decision: option (a).** Default every operand we cannot infer to
  a distinct `Unknown` and **never** throw on it. Throw only where the type
  is *affirmatively known and known-wrong*. avmplus can use the opposite
  rule ("not provably typed ⇒ throw") only because its lattice is
  *complete*; ours will never be, so the two rules are not the same rule.
- **Predicted yield: +2 tests** — `avm2/verify_typecheck` (currently
  `runtime_error`, a hard fatal that suppresses all output) and
  `avm2/rtqname_not_namespace` (currently 9/12 `output_mismatch`).
  `avm2/scope_optimizations` is **not** reachable by this arc; it needs
  static *early binding of `findpropstrict` against a typed scope stack*,
  which is a codegen change, not a verifier check. Explicitly deferred.
- **Biggest risk: a false positive turns a whole method body into a
  throwing stub**, because `abc_emit.cpp:2905` lowers `verified == false`
  to `avm2_verify_error_body(act, ...)`. It is not a one-line trace diff;
  it deletes a method. The corpus exposure is 102,907 `getslot`/`setslot`
  ops across 2,076 of 4,473 SWFs.
- **The mitigation is empirical and cheap**: the Stage-1 predicates were
  measured against the whole corpus *before* writing this doc, and the
  `1051` predicate fires exactly **once** in 4,473 SWFs — on
  `verify_typecheck` itself. Stage 0 makes that measurement a permanent,
  repeatable, report-only mode.
- **A linear walk with "reset everything to Unknown at every branch/switch/
  exception target" is sufficient for all six errors these two tests need.**
  No dataflow fixpoint, no merge lattice, no termination proof. That is the
  single biggest risk reduction available and it costs nothing in yield.

---

## 1. Current verifier architecture

`SWFRecomp/src/abc/abc_verifier.cpp` (2000 lines), entry point
`verifyMethodBody(abc, body_index, out, err)` → `bool`. Three phases:

**Phase 1 — reachability walk + translation** (`translateOp`, line 542).
A worklist over raw bytecode offsets; each reached op is translated into
the resolved `IrOp` (`abc_ir.hpp`) and recorded in a `states[]` byte map
(`OpStart` / `OpStartNonJumpable` / `OpContinue`). Constant-pool range
checks, `#1011` illegal opcode, `#1021` bad branch target, `#1113`
newactivation-without-flag, `#1124` hasnext2 register conflict, and the
whole `#1032` cpool family live here.

**Phase 2 — resolution.** Reached ops are compacted into `out.ops`; the
exception table is resolved to op-index ranges (`#1054`); branch offsets
are rewritten to absolute op indices (`#1021`).

**Phase 3 — the abstract interpretation that already exists** (the last
~140 lines). This is where a lattice attaches. Today it is
**depth-only**:

```cpp
struct SimEntry { u32 idx; s32 stack; s32 scope; };
std::vector<s32> stack_at(out.ops.size(), -1);
std::vector<s32> scope_at(out.ops.size(), -1);
std::vector<SimEntry> sim_list;   // LIFO worklist
```

- Seeds: op 0 at `(stack 0, scope 0)`, plus every **active** exception
  handler target at `(stack 1, scope 0)`.
- Per op: `stackEffect(op, abc, pops, pushes, scope_delta)` (line 1247)
  gives the depth delta, including the lazy-multiname extra pops.
- Checks: `#1024` underflow, `#1023` overflow vs `max_stack`, `#1018`/
  `#1017` scope under/overflow, `#1019` `getscopeobject` out of bounds,
  `#1020` fall-off-the-end.
- **Merge handling: visit-once + equality assertion.** The first time an
  op is reached, its `(stack, scope)` depths are recorded; every later
  arrival must *match exactly*, else `#1030` / `#1031`. This is correct
  for depths (avmplus requires them to agree) but is **not** a lattice
  join — there is no notion of "combine and re-analyse".

Per-body failure is not fatal to the build. `swf.cpp:6238` records
`bodies[bi].verified` and `bodies[bi].verify_error`;
`abc_emit.cpp:2905` emits the failing body as

```c
avm2_verify_error_body(act, "Error #NNNN: ...");
```

which `avm2_ops.c:120` turns into a **catchable** `VerifyError` at the
method's first call — exactly avmplus's lazy per-method verification
semantics, and exactly what `verify_typecheck`'s and
`rtqname_not_namespace`'s `try { this.methodN(); } catch (e:Error)` needs.
`avm2_error.c` parses the `"Error #NNNN: "` prefix back out for
`e.errorID`, and `e.name` is `VerifyError`.

**Therefore: this whole arc is recompiler-side. No runtime work is needed
to make the errors observable.**

### 1.1 What already exists that we should reuse, not rebuild

`abc_emit.cpp` already carries **two** prototype static-type walkers, both
production-tested:

| Thing | Where | What it gives us |
|---|---|---|
| `AbcTypeModel` | `abc_emit.cpp:1928` | `nameToInst` / `nameCount` (ambiguity guard), `typeMnToInst`, `m2c` (method → declaring class + is-instance), `isSealed`, `children`, `findUniqueSlot`, and **`slotCountOf(inst)`** |
| `slotCountOf` / `inheritedBase` | `abc_emit.cpp:1992–2024` | cumulative ivtable `slot_count`, numbered **identically to `avm2_class.c`**, returning **`-1` when any ancestor is a non-ABC native class** — i.e. it already implements exactly the conservative "we don't know, so don't claim" rule this arc needs |
| `TK`/`TV` coerce-elision lattice | `abc_emit.cpp:1922`, driver ~2540–2810 | a linear-walk static type per stack slot / local with `TK_UNK` bottom, and **"type is cleared at every branch-target merge (join = unknown)"** |
| `scoutStaticTypes` | `abc_emit.cpp:3257` | env-gated read-only diagnostic walk with `AV_UNK/AV_INST/AV_CLS/AV_SCOPE` and a CSV report — the template for Stage 0's report-only mode |
| `irStackEffect` | `abc_emit.cpp:1826` | a second copy of `stackEffect` |

The `TK`/`TV` lattice is *already shipping* and is already used to elide
coercions where provably safe. Its "reset at branch target" rule is the
same rule Stage 1 wants. `slotCountOf`'s numbering is cross-checked in
production by `-DAVM2_SLOT_VERIFY`.

**Refactor note:** `stackEffect` (verifier) and `irStackEffect` (emitter)
are duplicates, and the emitter has a *third* partial copy inside
`scoutStaticTypes`. Stage 1 should promote one copy plus `AbcTypeModel`
into a shared header (`include/abc/abc_typemodel.hpp`) rather than adding
a fourth.

---

## 2. The oracle

### 2.1 Ruffle

Ruffle implements all three checks, and **none of the three tests is
`known_failure`** — the `.toml`s are bare `num_frames = 1`, in both
`~/CC/ruffle/tests/tests/swfs/avm2/*/test.toml` and our mirror. Ruffle
passes all three; the expected outputs are Flash-Player-derived.

The checks live in `core/src/avm2/optimizer/type_aware.rs` (2417 lines),
which despite the directory name is a **mandatory** pass, not an
optimization — it is where Ruffle raises `1023/1024/1026/1030/1031/1035/
1051/1058/1068`.

| Check | Site | Rule |
|---|---|---|
| `#1058` lookupswitch | `type_aware.rs:2150` | `if value.class.is_none_or(\|c\| !c.is_builtin_int()) → make_error_1058(.., "int")` |
| `#1058` RTQName ns | `type_aware.rs:390` (`pop_for_multiname`) | pops lazy name first, then lazy ns; `if value.class.is_none_or(\|c\| c != namespace_class) → make_error_1058(.., "Namespace")` |
| `#1051` / `#1026` getslot | `type_aware.rs:1458` | `stack_value.vtable_and_class()` is `None` (class absent **or** an interface) → `1051`; else `vtable.slot_class(slot_id)` is `None` → `1026(slot_id + 1, slot_count, class)` |
| `#1051` / `#1026` setslot | `type_aware.rs:1489` | same, on the *base* (popped second) |

Ruffle's lattice value is `OptValue { class: Option<Class>, contains_valid_integer,
contains_valid_unsigned, not_null, constant_value }`. Its merge
(`merged_with`, `type_aware.rs:118`) is: equal classes ⇒ that class; one
side a null constant ⇒ the other's class (unless non-null-able); both
numeric ⇒ `Number`; otherwise **walk both superclass chains for a common
superclass**; no common superclass ⇒ `None`.

**The critical divergence we must make:** Ruffle uses **one** bottom.
`class: None` means both "the `*` type" and "we lost track", and both
throw `1051`. Ruffle can afford that because its lattice models every op.
Ours will not, so we must split that bottom in two (§4).

### 2.2 avmplus / the ABC spec

avmplus's `Verifier` carries a full `FrameState` of `Value { Traits* traits; ... }`
per stack slot, per local and per scope slot, with real block-merge
(`FrameState::merge`). The relevant primitives:

- `peekType(REQUIRED, n)` compares `Traits*` by **pointer identity** and
  raises `kIllegalOperandTypeError` (`#1058`, `"Illegal operand type: %1
  must be %2."`) on mismatch. `*` is `traits == NULL`, which is not
  `NAMESPACE_TYPE`, hence a `coerce_a`'d real `Namespace` fails. Used for
  the `lookupswitch` index (`INT_TYPE`) and the RTQName/RTQNameL runtime
  namespace operand (`NAMESPACE_TYPE`).
- `checkEarlySlotBinding(traits)` raises `kIllegalEarlyBindingError`
  (`#1051`, `"Illegal early binding access to %1."`) when the base has no
  usable traits.
- `checkSlot(traits, i)` raises `#1026` `"Slot %1 exceeds slotCount=%2 of %3."`
  Slot numbers in the message are **1-based** (Ruffle re-adds `+1`; our IR
  is 0-based, see `abc_ir.hpp`).

This is the "throw when the operand is not PROVABLY typed" rule §8.7
warned about. It is safe **for avmplus** because avmplus's inference is
total: for avmplus, "not provably typed" and "provably `*`" are the same
set. They are not the same set for us. See §4.

---

## 3. What each test needs, opcode by opcode

Dumps below are from `./SWFRecomp/build/SWFRecomp --dump-abc <test.swf>`,
which prints the resolved IR (`GetSlot`/`SetSlot` indices already 0-based).

### 3.1 `avm2/verify_typecheck` — expected `1058 / 1051 / 1026 / 1026`

Current status **`runtime_error`, exit 1, 0 lines**:
`AVM2 fatal: GetSlot 1 out of range (slot_count 0)` from
`avm2_ops.c:1992`. The fatal kills the process before *any* trace is
flushed, so all four lines are lost.

The constructor (`method[5]`) is four `try { this.methodN(); } catch (e:Error)
{ trace(e.errorID); }` blocks. Each error therefore comes from a *different
method body*, and each body independently becomes a throwing stub.

| # | Body | IR | What the lattice must derive | Error |
|---|---|---|---|---|
| 1 | `method[1]` | `GetLocal r0; PushScope; PushDouble dbl[1]=3.4; LookupSwitch` | `PushDouble ⇒ Class(Number)` | `LookupSwitch` operand affirmatively non-`int` ⇒ **`#1058`** |
| 2 | `method[2]` | `... NewObject pairs=0; CoerceA; GetSlot slot=0` | `NewObject ⇒ Class(Object)`; `CoerceA` on an affirmative input ⇒ `Any` | base is affirmatively `*` ⇒ **`#1051`** |
| 3 | `method[3]` | `FindPropStrict mn[19] SlotClass; GetPropertyStatic mn[19]; Construct args=0; PushInt 4; SetSlot slot=1` | `FindPropStrict`+`GetPropertyStatic` of an ABC-defined class name ⇒ `ClassOf(SlotClass)`; `Construct` on `ClassOf(C)` ⇒ `Class(C)` | `slotCountOf(SlotClass) == 1`, `slot0 == 1 >= 1` ⇒ **`#1026`** ("Slot 2 exceeds slotCount=1 of SlotClass") |
| 4 | `method[4]` | same as 3 with `GetSlot slot=1` | same | **`#1026`** |

`class[0] SlotClass extends Object sealed` with a single `slot slot : int
(slot_id 0)` — so `inheritedBase(Object) == 0`, one auto-assigned slot,
`slotCountOf == 1`. All four bodies are **straight-line** — zero branch
targets, zero merges.

Note `method[2]` *without* the `CoerceA` would be `#1026` (Object has 0
slots), not `#1051`. Distinguishing them is precisely what "affirmatively
`*`" buys, and it cannot be done at runtime — the runtime value is an
`Object` either way.

### 3.2 `avm2/rtqname_not_namespace` — 9/12, case 3 missing

Current actual line 10 is `undefined` where `Failed (expected)` is
expected. Cases 1 and 2 already pass, but **at runtime**: `avm2_ops.c:1624`
(`key_from_ns_value`) throws a catchable `VerifyError #1058` when the
popped namespace operand is not a `Namespace`. Case 3's operand *is* a
real `Namespace` at runtime, so the runtime check cannot fire; only the
static type is wrong.

| # | Body | IR (abridged) | What the lattice must derive | Error |
|---|---|---|---|---|
| 1 | `method[1]` | `... GetLocal r1; NewObject pairs=0; GetPropertySlow mn[16] {rt-ns}::hello` | `NewObject ⇒ Class(Object)` | ns operand affirmatively ≠ `Namespace` ⇒ **`#1058`** (moves from runtime to verify time; **output unchanged**) |
| 2 | `method[2]` | `... NewObject; PushString "hello"; ConvertS; GetPropertySlow mn[15] {rt-ns}::{rt-name}` | pop lazy **name** first (`ConvertS ⇒ Class(String)`), then ns (`Class(Object)`) | **`#1058`** (also moves to verify time; output unchanged) |
| 3 | `method[3]` | `FindPropStrict mn[17] Namespace; PushString ""; ConstructProp mn[17] args=1; Coerce mn[17] Namespace; SetLocal r1; ... GetLocal r1; CoerceA; PushString "hello"; ConvertS; GetPropertySlow mn[15] {rt-ns}::{rt-name}` | `Coerce mn ⇒ Class(Namespace)` via a **builtin-name table**; `SetLocal`/`GetLocal` carry it; `CoerceA` on an affirmative input ⇒ `Any` | ns operand affirmatively `*` ≠ `Namespace` ⇒ **`#1058`** — **this is the missing line** |

All three bodies are straight-line. The pop order matters: lazy **name**
is popped before lazy **ns** (see `pop_for_multiname` and our own
`stackEffect` lazy accounting).

### 3.3 `avm2/scope_optimizations` — NOT in scope

Current 3/4: `With coerce:` traces `0`, expected `[class field]`.

```
17: FindPropStrict mn[6] Subclass
18: ConstructProp mn[6] Subclass, args=0
19: Coerce mn[8] Superclass          <-- static type narrowed to Superclass
20: PushScope
21: FindPropStrict mn[16] trace
22: FindPropStrict mn[4] field       <-- must MISS the scope object
23: GetPropertyStatic mn[4] field
```

`Subclass` declares `slot field : int`; `Superclass` does not. Flash
resolves `findpropstrict field` against the **static** type of the scope
entry, so after the `Coerce` the scope object is `Superclass`, `field` is
not found there, and the lookup falls through to the global scope and
finds the *class* `field` (`[class field]`). We do the scope walk
dynamically, where the object is a real `Subclass` either way, so we find
the slot and print `0`.

Fixing this is **not** a verify-time *check*; it is verify-time **early
binding** that changes which object a name resolves to, i.e. it changes
emitted code (`FindPropStrict` would have to be statically lowered to
`GetGlobalScope`/`FindDef`). That is a semantics-changing optimization
across all `findpropstrict` sites — a far larger and far riskier arc than
error-raising. It is a natural *follow-on* once the lattice exists, but it
must be scoped and canaried separately. **Deferred; not counted in the
yield.**

---

## 4. The conservative direction — settled

**Rule: (a). Default unknown operands to a distinct `Unknown` that never
throws. Throw only on affirmatively-known-wrong types.**

### 4.1 Why (b) is wrong here even though avmplus does it

avmplus's rule and ours would be the same rule only if our inference were
total. Three independent arguments:

1. **Soundness direction.** avmplus's lattice models every op, so
   `traits == NULL` genuinely means "the value's static type is `*`".
   Ours will model a few dozen ops out of ~160. For us, "no class" is
   overwhelmingly "we didn't look", not "the type is `*`". Reusing one
   bottom for both would report a *property of our implementation* as a
   *property of the program*.
2. **Blast radius.** A false positive is not a wrong trace line; it
   replaces an entire method body with `avm2_verify_error_body`. Corpus
   census (measured, §5): **102,907 `getslot`/`setslot` ops in 2,076 of
   4,473 SWFs**, 641 `lookupswitch` in 332 files, 244 RTQName/RTQNameL in
   42 files, across 95,946 method bodies. Under (b), every one of those
   102,907 sites is a candidate spurious `#1051`.
3. **The corpus is the specification.** 3,933 tests pass today. Any
   lattice that throws on a currently-passing test is wrong *by
   definition*, regardless of what avmplus does — because avmplus does not
   throw on them either, and it is our inference, not the program, that
   would have changed. This is the same discipline the existing
   `slotCountOf` already follows (returns `-1` rather than guessing).

The cost of (a) is **false negatives**: errors avmplus raises that we
miss. A false negative is *exactly current behaviour*. That asymmetry is
the whole argument.

### 4.2 The lattice

```
Value := Unknown | Any | Class(C) | ClassOf(C)
```

- **`Unknown`** — "our inference does not model this". Bottom for
  *decision purposes*. Never triggers any check.
- **`Any`** — affirmatively the `*` type. Produced only where the ABC
  spec guarantees `*`: `CoerceA` **whose input was itself affirmative**.
  (Restricting `Any` to affirmative inputs costs nothing — both tests
  reach it that way — and prevents `Unknown` from laundering itself into
  a throwing state.)
- **`Class(C)`** — affirmatively an instance of `C`. `C` is either an
  ABC-defined instance index or one of a small builtin-name set.
- **`ClassOf(C)`** — affirmatively the *class object* for `C`; only used
  so `Construct` can produce `Class(C)`.

**Merge rule (Stage 1): `Unknown`.** At every branch target, switch
target and exception handler target, reset the entire stack, all locals
and the scope stack to `Unknown`. This is the rule the shipping
`TK`/`TV` lattice in `abc_emit.cpp` already uses ("type is cleared at
every branch-target merge (join = unknown)"). It is not a join in the
lattice-theoretic sense; it is a *bail*. It requires no fixpoint, no
worklist re-entry, no termination argument, and it cannot be unsound in
the throwing direction.

If a later stage ever wants real merges, the rule must be
**`Unknown` is absorbing**: `Unknown ⊔ X = Unknown` (the opposite of
Ruffle's `None`, which is `Any`-like and throws). `Any ⊔ Class(C) = Any`;
`Class(C) ⊔ Class(D)` = common ABC superclass, or `Number` for two
numerics, else `Unknown`. Plus an iteration cap that, if hit, disables all
checks for that body. **Stage 1 does not need any of this.**

### 4.3 Predicate table (Stage 1)

| Op | Predicate | Error |
|---|---|---|
| `LookupSwitch` | operand is `Class(C)` and `C` is not `int` | `#1058` `Illegal operand type: <C> must be int.` |
| `GetPropertySlow`/`SetPropertySlow`/... with a lazy-ns multiname | ns operand (popped **after** the lazy name) is `Any`, or `Class(C)` with `C != Namespace` | `#1058` `... must be Namespace.` |
| `GetSlot` / `SetSlot` | base is `Any` | `#1051` `Illegal early binding access to *.` |
| `GetSlot` / `SetSlot` | base is `Class(C)`, `C` is an **ABC-defined, sealed, non-interface, name-unambiguous** instance, `slotCountOf(C) >= 0`, and `slot0 >= slotCountOf(C)` | `#1026` `Slot <slot0+1> exceeds slotCount=<n> of <C>.` |

Everything not listed: no check. In particular **`Unknown` never
throws**, `ClassOf(C)` never throws, and a `Class(C)` naming a builtin or
a class whose ancestry leaves the ABC (`slotCountOf < 0`) never throws
`#1026`.

### 4.4 Ops modelled in Stage 1 (the whole list)

Producing: `PushInt/PushByte/PushShort ⇒ Class(int)`, `PushUint ⇒
Class(uint)`, `PushDouble/PushNaN ⇒ Class(Number)`, `PushString/ConvertS/
CoerceS ⇒ Class(String)`, `PushTrue/PushFalse/CoerceB ⇒ Class(Boolean)`,
`PushNamespace ⇒ Class(Namespace)`, `NewObject ⇒ Class(Object)`,
`NewArray ⇒ Class(Array)`, `NewFunction ⇒ Class(Function)`,
`CoerceI ⇒ Class(int)`, `CoerceU ⇒ Class(uint)`, `CoerceD ⇒ Class(Number)`,
`Coerce mn ⇒ Class(resolve(mn))` or `Unknown`,
`CoerceA ⇒ Any` iff input affirmative else `Unknown`,
`ConstructProp mn ⇒ Class(resolve(mn))` or `Unknown`,
`Construct` on `ClassOf(C) ⇒ Class(C)` else `Unknown`,
`FindPropStrict`/`FindProperty` ⇒ `Unknown` (**not** a scope type —
deliberately weaker than `scoutStaticTypes`'s `AV_SCOPE`),
`GetPropertyStatic mn` on `Unknown` ⇒ `ClassOf(resolve(mn))` **only** when
the immediately preceding op was `FindPropStrict` with the same multiname
and that multiname names an ABC-defined class, else `Unknown`.

Propagating: `GetLocal`/`SetLocal` (locals array), `Dup`, `Swap`, `Pop`.

Seeds: **all locals `Unknown`**, including `local 0`. (Typing `this` and
the declared parameter types, as `scoutStaticTypes` does, is a Stage-2
option; Stage 1 does not need it and every additional affirmative type is
additional risk.)

Everything else: consume `pops` operands, push `pushes` × `Unknown`, using
the *existing* `stackEffect`.

`resolve(mn)` = `AbcTypeModel::typeMnToInst` for ABC classes, plus a fixed
builtin-name table `{Object, int, uint, Number, String, Boolean,
Namespace, Function, Array, Class}` matched on a public-namespace QName,
and **only when `nameCount[name] == 1`** so a user class shadowing a
builtin name resolves to neither.

---

## 5. Measured corpus exposure (already collected)

Method: `--dump-abc` over every `test.swf` under
`ruffle-tests/tests/swfs` (4,473 files, ~10 min single-threaded), then
opcode census of the printed IR.

```
files=4473   method bodies=95946
getslot/setslot   102907 ops   in 2076 files
lookupswitch         641 ops   in  332 files
RTQName/RTQNameL     244 ops   in   42 files
```

**Op immediately preceding `LookupSwitch`** (641 sites):

| count | preceding op |
|---|---|
| 344 | `Kill` |
| 173 | `CallPropVoid` |
| 79 | `SetLocal` |
| 21 | `Pop` |
| 9 | `IfFalse` |
| 8 | `Throw` |
| 4 | `SetPropertyStatic` |
| 1 | `PushInt` |
| **1** | **`PushDouble`** ← `verify_typecheck` |
| 1 | `InitProperty` |

ASC's switch idiom is a comparison chain that `pushint`s a case index in
each arm and jumps to a common `kill; lookupswitch`, so the discriminant
arrives **at a merge point** in essentially every real switch. Under the
Stage-1 reset-at-target rule those are all `Unknown` ⇒ skipped. The single
`PushDouble` site is the test.

**Op immediately preceding `GetSlot`** (57,850 sites):

| count | preceding op |
|---|---|
| 30350 | `GetScopeObject` |
| 26954 | `GetGlobalScope` |
| 517 | `GetLocal` |
| 25 | `Dup` |
| 1 | `AsTypeLate` |
| **1** | **`CoerceA`** ← `verify_typecheck` |
| **1** | **`Construct`** ← `verify_typecheck` |
| 1 | `NewCatch` |

`GetScopeObject`/`GetGlobalScope` (99.1% of sites) are activation, catch
and global scope objects — `Unknown` under Stage 1 ⇒ skipped.

**`CoerceA` immediately preceding `GetSlot`, whole corpus: exactly one
occurrence, in `ruffle-tests/tests/swfs/avm2/verify_typecheck/test.swf`.**

`SetSlot` bases (approximate 2-deep provenance, 45k sites) are dominated
by `GetGlobalScope` (20,603) and `GetScopeObject` (9,098); the largest
affirmatively-typeable group is `ConstructProp` (1,164 sites), almost all
naming *builtin* classes (`BitmapData`, `ByteArray`, ...) which
`typeMnToInst` resolves to `-1` ⇒ `Unknown`. This group is the one place
Stage 1 will genuinely evaluate the `#1026` predicate on real code, and it
is exactly what Stage 0's report-only sweep exists to audit.

---

## 6. Predicted yield

| Test | Suite | Now | After | Δ |
|---|---|---|---|---|
| `verify_typecheck` | avm2 | `runtime_error` (0/4 lines, fatal) | **pass** | +1 |
| `rtqname_not_namespace` | avm2 | `output_mismatch` 9/12 | **pass** | +1 |
| `scope_optimizations` | avm2 | `output_mismatch` 3/4 | unchanged | 0 |

**Total: +2.** Baseline for the diff: `results_graphics.json` at
`2ab0c01be` — avm2 1052/1224 pass, corpus 3933/4473.

A corpus-wide scan of every failing test's expected/actual output for
`1026|1051|1058|VerifyError|Illegal operand type|slotCount` finds no other
candidates: the other hits are `static_length` (`.length` on error
classes), `verify_exception_target_two_jumps` (`#1030` vs our `#1024` —
a merge-order bug in the *depth* pass, unrelated), `verify_illegal_opcode`,
`verify_method_info_duplicate`, `verify_method_info_oob` (all
`method_info`/opcode-table checks, separate arcs), and
`from_gnash/MovieClip-v8` (AVM1).

**This is a thin arc for the infrastructure it builds.** Say so up front
when prioritising it. Its real value is the shared `AbcTypeModel` header
and the report-only harness, which the scope-early-binding work, the
`#1030` merge-order fix, and further slot-specialisation levers all want.

---

## 7. Risk list

| # | Risk | Severity | Mitigation |
|---|---|---|---|
| R1 | Spurious `#1051`/`#1026`/`#1058` deletes a whole method body (`avm2_verify_error_body`) | **critical** | Stage 0 report-only sweep over all 4,473 SWFs before any check is armed; a check ships only when its sweep names *only* the intended tests |
| R2 | `Unknown` laundered into `Any` by `CoerceA`, then throws `#1051` | high | `CoerceA` produces `Any` **only** from an affirmative input; `Unknown` in ⇒ `Unknown` out |
| R3 | `slotCountOf` disagrees with `avm2_class.c` numbering ⇒ spurious `#1026` | high | `slotCountOf` already returns `-1` on any non-ABC ancestor and is cross-checked in production by `-DAVM2_SLOT_VERIFY`; additionally require sealed, non-interface, `nameCount == 1`; Stage 0 sweep |
| R4 | Class-name resolution collides (user class named `Namespace`/`Object`) | medium | `nameCount[name] == 1` guard; builtin table only for public-ns QNames |
| R5 | Real-world `lookupswitch` discriminants classified non-`int` | medium | reset-at-target makes every merged discriminant `Unknown`; measured: 1 non-`int` site corpus-wide, and it is the test |
| R6 | Error **ordering** changes: a body with both a type error and a depth error reports the wrong one | medium | run the type pass **after** the existing depth pass succeeds, as a separate walk; report the type error with the **lowest op index**. Existing behaviour is then bit-identical for every body with no type error |
| R7 | The new pass perturbs `computed_max_stack` / `computed_max_scope` or the IR | medium | new pass is read-only over `out.ops`; it must not write `out` |
| R8 | Cases 1 & 2 of `rtqname_not_namespace` move from a runtime throw to a verify-time throw and the trace changes | low | verified from the dump: the surrounding `trace` calls are in the *constructor*, not in `method1`/`method2`, so the observable output is identical. Keep `avm2_ops.c:1624` as the runtime safety net for `Unknown` operands |
| R9 | Verify-time throw in a **script init** or **class init** cascades | low | avmplus is lazy too, and a bad init is a bad init; but the Stage 0 sweep must report the *method kind*, and any hit on an init in a passing test is a hard stop |
| R10 | Analysis cost on 95,946 bodies | low | linear, no fixpoint; the existing `--dump-abc` full-corpus pass runs in ~10 min including SWF decompression |
| R11 | Fourth copy of `stackEffect` drifts | low | promote to a shared header in Stage 1 (§1.1) |

---

## 8. Staged plan

### Stage 0 — report-only harness (no behaviour change) **[do this first]**

1. Promote `AbcTypeModel` + one `stackEffect` into
   `SWFRecomp/include/abc/abc_typemodel.hpp`; make `abc_emit.cpp` use it
   (pure refactor; corpus must be byte-identical).
2. Add the Stage-1 lattice walk to `abc_verifier.cpp` as a **separate
   pass after** phase 3, gated by an env var (mirror
   `SWF_SCOUT_TYPES`, e.g. `SWF_VERIFY_TYPES=<csv>`), that **records**
   every predicate hit — file, method display name, method kind
   (script init / class init / ctor / method), op index, error code,
   inferred type — and **returns success regardless**.
3. Sweep all 4,473 SWFs. **Exit criterion: the CSV names exactly
   `verify_typecheck` (4 rows) and `rtqname_not_namespace` (3 rows) and
   nothing else.** Every other row is a bug in the lattice, not a bug in
   the corpus, and must be driven to zero by *weakening* inference
   (more `Unknown`), never by adding an exception list.
4. Optional, independent: convert the two `avm2_fatal` calls at
   `avm2_ops.c:1992` / `:2009` into a catchable `VerifyError #1026`.
   This does **not** add a pass on its own (`verify_typecheck` would read
   `1026/1026/1026` against `1058/1051/1026/1026`), but it turns a
   process-killing fatal into a graceful failure and is worth doing for
   robustness. Canary it separately — it changes game behaviour on any
   title that currently dies there.

### Stage 1 — arm the checks

Arm them **one predicate at a time**, each with its own commit and its own
CI run, in ascending order of blast radius:

1. **`#1058` RTQName/RTQNameL namespace** (42 files exposed) — lands
   `rtqname_not_namespace` (9/12 → 12/12).
2. **`#1058` lookupswitch** (332 files) — lands `verify_typecheck` line 1.
3. **`#1051` getslot/setslot on affirmative `*`** (1 site corpus-wide) —
   lands `verify_typecheck` line 2.
4. **`#1026` slot index past `slotCountOf`** (2,076 files) — lands
   `verify_typecheck` lines 3–4, and completes the test.

Per-commit canary (local, `--test=` only): `verify_typecheck`,
`rtqname_not_namespace`, `scope_optimizations`, `verify_stack`,
`verify_illegal_opcode`, `verification`, `construct_interface`,
`method_without_body`, `cpool_index_invalid_bytecode_{1,2,3}`, plus a
stash-diff sweep including the `regression` suite. Then CI
`mode=graphics`, `categories=full` (this touches AVM2 recompiler
emission — see CLAUDE.md).

Watch in CI: `runtime_error` 2 → 1, `recomp_fail` 1 → 1,
`ruffle_matched` 244 → 244, `output_mismatch` 292 → 290. A rise in
`output_mismatch` or any new `runtime_error` means a spurious
`VerifyError` deleted a body — revert the predicate, do not patch it.

### Stage 2 — optional hardening (no yield)

Real merges (`Unknown`-absorbing, iteration-capped), `this`/parameter
seeding, scope-stack typing. Only worth doing if Stage 3 is on the board.
Each addition of affirmative typing must re-run the Stage 0 sweep.

### Stage 3 — `scope_optimizations` (separate arc)

Static early binding of `findpropstrict` against a typed scope stack.
Changes emitted code, not just errors. Needs its own scoping doc, its own
risk analysis, and a much larger canary — it can silently change which
object a name resolves to in every AVM2 title we run.

---

## 9. Reproduction commands

```bash
# Dump the resolved IR of a test (0-based slot indices, resolved branch targets)
./SWFRecomp/build/SWFRecomp --dump-abc ruffle-tests/tests/swfs/avm2/verify_typecheck/test.swf

# The three tests, one at a time (never run a full suite locally)
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 \
        --test=verify_typecheck --diff --verbose
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 \
        --test=rtqname_not_namespace --diff --verbose
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 \
        --test=scope_optimizations --diff --verbose

# Corpus opcode census (the numbers in §5)
find ruffle-tests/tests/swfs -name test.swf | while read f; do
  ./SWFRecomp/build/SWFRecomp --dump-abc "$f" 2>/dev/null
done | grep -cE '^ *[0-9]+: (GetSlot|SetSlot) '
```

## 10. Key file references

- `SWFRecomp/src/abc/abc_verifier.cpp` — `verifyMethodBody`; phase 3
  depth simulation at the tail (`SimEntry`, `stack_at`, `scope_at`);
  `stackEffect` at line 1247; `fail`/`failFilled` at lines 40/52.
- `SWFRecomp/include/abc/abc_verifier.hpp` — states the lattice is
  "deliberately NOT here"; update that comment when Stage 1 lands.
- `SWFRecomp/include/abc/abc_ir.hpp` — `IrOpcode`, `IrOp`, `VerifyError`;
  documents the 0-based slot rewrite and the `GetLex` split.
- `SWFRecomp/src/abc/abc_emit.cpp` — `irStackEffect` (1826),
  `AbcTypeModel` (1928), `slotCountOf` (2007), the `TK`/`TV` coerce
  lattice and its branch-target reset (~2540–2810), `scoutStaticTypes`
  (3257), the `!body.verified` stub emission (2905).
- `SWFRecomp/src/swf.cpp:6226–6260` — the per-body verify driver.
- `SWFModernRuntime/src/avm2/avm2_ops.c:120` — `avm2_verify_error_body`;
  `:1624` `key_from_ns_value` runtime `#1058`; `:1992`/`:2009` the
  `getslot`/`setslot` fatals.
- `SWFModernRuntime/src/avm2/avm2_error.c:551–587` — the avmplus message
  table (`#1026`, `#1051`, `#1058` wording).
- `~/CC/ruffle/core/src/avm2/optimizer/type_aware.rs` — `OptValue` (36),
  `merged_with` (118), `pop_for_multiname` (386), `GetSlot`/`SetSlot`
  (1458/1489), `LookupSwitch` (2145).
- `~/CC/ruffle/core/src/avm2/verify.rs` — Ruffle's structural verifier
  (the model our phases 1–2 were built from).
