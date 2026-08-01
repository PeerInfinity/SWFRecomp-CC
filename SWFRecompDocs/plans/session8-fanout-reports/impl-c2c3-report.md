# Session 8 — wave 2, clusters C2 + C3

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-aaaa8697ea15755a8`
(branch `master` @ `1c7c23761`, no commits made).
Patch: `scratchpad/wave2/c2c3.patch` (11 files, +355/−27).

**Ledger: 7 of 8 targets flipped to `pass` (C2 5/5, C3 2/3).**
Every flip verified locally with `--mode=graphics --recompile`.

| # | target | suite | baseline | now |
|---|---|---|---|---|
| 1 | `avm2/flash/geom/matrix3d/Matrix3DClass` | from_shumway | output_mismatch (51/56) | **pass** |
| 2 | `superinterface_call` | avm2 | output_mismatch (15/20) | **pass** |
| 3 | `as3/RuntimeErrors/Error1115NotAConstructor/v10` | from_avmplus | output_mismatch (0/3) | **pass** |
| 4 | `string_relational_compare` | avm1 | output_mismatch (3/4) | **pass** |
| 5 | `native_objects_swf6` | avm1 | output_mismatch (114/115) | **pass** |
| 6 | `verify_method_info_oob` | avm2 | output_mismatch (0/1) | **pass** |
| 7 | `verify_exception_target_two_jumps` | avm2 | output_mismatch (0/1) | **pass** |
| 8 | `verify_method_info_duplicate` | avm2 | output_mismatch (0/2) | still fail (1/2) — see C3.3 |

---

## C2 — five singles, five files, all taken

### C2.1 `Matrix3D.appendRotation/prependRotation` ignored `pivotPoint`
`SWFModernRuntime/src/avm2/avm2_stage3d.c` `matrix3d_xform`, the `kind == 2`
arm. It read arg 0 (degrees) and arg 1 (axis) and never read arg 2. Added the
pivot term: with Flash's row-vector convention the rotation about `p` is
`v' = v·R + (p − p·R)`, i.e. fill `t[12..14]` after building `R`. All five
failing rows were the pivot-dependent assertions; the test now passes 56/56.

**Correction to the triage:** its canary note says "all 20 corpus call sites use
the 2-argument form". That is wrong — `avm2/stage3d_rotating_cube` and
`avm2/stage3d_program_constants_bytearray_{be,le}` all pass a third argument.
Blast radius is still nil because that argument is `const pivot:Vector3D = new
Vector3D()` (the origin, so the added term is zero); all three were run and
still pass.

### C2.2 `superinterface_call` — a frozen NULL in the interface cache
Not an identity mismatch (the triage's hypothesis). `resolve_interfaces`
(`avm2_class.c`) allocated `cls->interfaces` once and returned early ever after
(`if (cls->interfaces != NULL) return;`), so an interface that is not yet in the
domain when its implementor's `newclass` runs is cached as **NULL forever**.
ASC emits `Concrete` before `BaseInterface` in the same script, so
`Concrete implements BaseInterface` was invisible and
`var launder: BaseInterface = concrete` threw #1034.

Fix mirrors `avm2_class_for_mn`'s documented policy — *cache only non-NULL
answers*: zero the array on allocation and re-resolve the NULL entries on each
call.

Second half, needed for the flip: the interface-namespace method aliases
(`add_iface_aliases_from`) are installed at newclass time off that same list, so
a late-resolving interface never got them and the coercion then succeeded only
to die with `#1069 Property base_interface not found`. `resolve_interfaces` now
installs the aliases for any interface it resolves late (skipped when `cls` is
itself an interface, matching the existing call-site guard).

### C2.3 `Error1115NotAConstructor/v10` — a version gate *and* a mode gate
avmplus reports `new <non-constructor>()` as **#1115** instead of #1007 only
when three things hold (Ruffle `value.rs Value::construct_prop`):
root SWF version < 11, **the name resolved to a Slot/ConstSlot trait**, and
**the executing method is in "interpreter mode"**.

The last one is not optional, and it is where the first attempt broke a passing
test: a naive `swf_version < 11` gate flipped `avm2/construct_errors_swf10`
(SWF 10, expects #1007 ×4) on its fourth row. Ruffle's `is_interpreted` is set
for **class initializers and script initializers only** (`method.rs`), and the
Error1115 test constructs at script top level while construct_errors_swf10
constructs inside a normal method.

The recompiler already knows this: `BodyCtx::interp_mode` in `abc_emit.cpp`
(added for the index fast path) is exactly avmplus's interpreter-mode set. So
`ConstructProp` inside such a body now emits the new
`avm2_op_constructprop_init`, which applies the slot+version gate; every other
body keeps `avm2_op_constructprop` unchanged. At SWF ≥ 11 the new op delegates
immediately, so nothing changes for the modern corpus.

### C2.4 `avm1/string_relational_compare` — code units vs code points
`action.c::u16_cmp` compared raw UTF-16 units, so every surrogate pair sorted
below U+E000..U+FFFF. AVM1 strings are UTF-8 in Flash and its relational
operators compare those bytes = code-point order. Rewrote `u16_cmp` to decode
at the first differing unit (`u16_decode_codepoint` was already there). Of its
8 callers, 4 are equality tests (unaffected by definition) and 4 are the
relational ops this fixes.

### C2.5 `avm1/native_objects_swf6` — the `TextField` global is SWF7+
`new TextField()` must be `new undefined()` at SWF 6 (Flash and Ruffle agree;
the swf7/swf8 siblings want a real native instance and already pass). Gated the
global on a new `TEXTFIELD_CTOR_MIN_SWF_VERSION 7` at **four** sites, not the
one the triage named — the `_global` registration, the duplicate `REG_FUNC`,
the builtin variable-resolution fast path, and `actionNewObject`'s `ctor_name`
strcmp chain (this last one is what actually served the test; the first three
alone changed nothing). TextField *instances* and `TextField.prototype` are
untouched — only the global name is gated. A corpus scan found exactly one
SWF ≤ 6 test that mentions `TextField`: this one.

---

## C3 — the recompiler's file-level ABC error path

### C3.1 the plumbing
`SWFRecomp/src/swf.cpp` dropped the whole DoABC tag on a `parseAbc` /
`validateAbcFile` failure, so the SWF built with no AVM2 entry point at all and
traced nothing. avmplus instead raises a catchable VerifyError at load and
leaves the file's definitions missing. Now:

- `AbcError` carries the avmplus code + filled message (`player_code`,
  `player_text`); the two throws in the method-body loop of `abc_parser.cpp`
  supply **#1027 `Method_info N exceeds method_count=M.`** and
  **#1121 `Method Test/hello() has a duplicate method body.`**. The #1121 text
  needs a *declaring-trait* name, since ASC leaves `method_info.name` empty —
  added `methodDisplayName()`, which searches instance traits, then class
  (static) traits (`Class$/x()`), then the initializers (`Class()` / `Class$()`).
- `parseAbc` gained an optional `AbcLoadError*` out-param; a failure with no
  known avmplus spelling defaults to **#1107 "The ABC data is corrupt…"**.
- `AbcEmitter::emitAbcLoadError()` emits a structurally minimal one-script ABC
  whose script initializer is an *unverified* body. That reuses the existing
  per-body mechanism verbatim: the emitter writes `avm2_verify_error_body(...)`,
  and the runtime's load-time eager init of each file's last script throws it.
  No new runtime contract.
- `validateAbcFile` failures route the same way, using `verr.message`.

### C3.2 the per-body verifier: #1030 vs #1024
`verify_exception_target_two_jumps` is a different site in the same family. The
CFG walk in `abc_verifier.cpp` seeded its LIFO worklist with entry 0 *and* every
catch target, so the catch body was simulated first and hit its own downstream
#1024 before normal flow ever branched into it. avmplus verifies in offset
order, so the catch entry state (depth 1) is already on record when the
`iffalse` arrives with depth 2 → `#1030 Stack depth is unbalanced. 1 != 2.`

Fix: record catch-target entry states up front, keep a separate `simulated`
marker, walk normal flow first and defer the handler bodies to a second list.
Message operands now read (recorded, incoming), which is avmplus's order.

### C3.3 what is NOT taken: the `#1065` follow-on
`verify_method_info_duplicate` wants two lines; we produce the first exactly and
not the second (`ReferenceError: Error #1065: Variable Test is not defined.`).
It would come from the root SymbolClass binding `char 0 → "Test"` failing to
resolve, where `avm2_display_build_stage` currently falls back to MovieClip
silently.

**Deliberately not done, and the reason is a trap.** The two tests are
*structurally identical* from our side — same `{ 0, "Test" }` binding, same
generated registry — but Flash grades them differently: `verify_method_info_oob`
expects the VerifyError **alone**, `verify_method_info_duplicate` expects the
VerifyError **plus** #1065. Any rule that emits #1065 for a missing root class
flips oob from `pass` to `ruffle_matched` (its `output.ruffle.txt` is
#1027 + #1065) while winning duplicate — net effective 0 on this pair, at the
cost of a corpus-wide behaviour change (every SymbolClass whose defining script
aborted would start printing an extra line) that cannot be canaried locally.
Left alone: current shape is +2 with zero risk; the alternative is +2 with real
risk.

### C3.4 mandatory C3 canary — CLEAN
`SWFRecomp --check-abc` over **all 4473 corpus `test.swf`** (`-P 3`, output in
`scratchpad/abccheck.txt` / `abccheck2.txt`), before and after:

```
NO_ABC 1445   OK 3015   PARSE_FAIL 2   VERIFY_FAIL 11     (identical both runs)
```

The two `PARSE_FAIL`s are exactly the two intended tests — **no other ABC in the
corpus reaches the file-level error path**, so nothing else starts throwing.
Row-by-row diff of the two sweeps: **2 rows changed**, both intended —
`verify_exception_target_two_jumps` #1024 → #1030, and `avm2/json_errors`
#1031 "2 != 1" → "1 != 2" (operand order only; that test does not grade the
text and was re-run: still `pass`).

---

## Canaries run (all `--mode=graphics --recompile`, ≤ `-P 2`)

41-test sweep + a 15-test final re-run on the finished patch. Raw output:
`scratchpad/canary_out.txt`, `scratchpad/final_out.txt`.

- **3D / Matrix3D:** `matrix3d`, `matrix3d_invert`, `matrix3d_compose`,
  `stage3d_rotating_cube`, `stage3d_program_constants_bytearray_be`,
  `stage3d_texture`, `utils3d`, `from_shumway/flash_geom_ColorTransform` — all pass.
- **Interfaces:** `astypelate`, `istypelate`, `instanceof`, `es4_interfaces`,
  `interface_namespaces`, `eventdispatcher_dispatchevent_indirect`,
  `vector_concat`, `from_shumway/as3-interfaces`, `avm1/interface_implements_op`
  — all pass.
- **SWF < 11 / #1115:** `construct_errors_swf10` (**caught a real regression**,
  see C2.3 — passes with the final gate), `swf8`, `doabc_is_eager`,
  `parse_float_swf10`, `uncaught_error_basic`,
  `Error1115NotAConstructor/v11` — all pass.
- **Verify family:** `verify_illegal_opcode`, `verify_stack`, `verification`,
  `verify_jump_to_middle_of_op`, `verify_dxns_without_flag`,
  `cpool_index_invalid_bytecode_{1,2,3}`, `json_errors`,
  `regression/avm2_tolerant_verify_quarantine` — all pass.
- **AVM1:** `native_objects_swf7`, `native_objects_swf8`, `array_sort`,
  `string_methods_swfv5` — pass. `from_gnash/actionscript.all/{String,ops}-v6`
  — still `ruffle_matched` (effective pass), unchanged.
- Already-failing at baseline and unchanged: `avm2/all_classes/errors/swf9`,
  `all_classes/errors/swf10`, `all_classes/display/swf10` (all `output_mismatch`
  before this patch too — not regressions).

Note: the worktree has no test SWFs (they are gitignored), so canary test
directories were rsync'd in from the main tree minus `Recompiled*`; the main
tree was never written to.

---

## Predicted CI delta

**+7** (`pass`), all outside any other wave-2 agent's files. No status moves in
the other direction were observed locally.

The recompiler-side changes make the emission differ for every body that is a
class/script initializer containing a `ConstructProp` (one call spelled
`avm2_op_constructprop_init`), plus the two ABCs that now emit a stub tag
instead of nothing — so **CI must run `categories=full`** (and `mode=graphics`,
`images=false`).

## Suggested commit message

```
polish sweep s8 wave 2: Matrix3D pivot, late interfaces, #1115 gate, ABC load errors (+7)

C2 — five independent singles:
- avm2_stage3d.c: appendRotation/prependRotation now honour their third
  argument (pivotPoint); the kind==2 arm never read it, so every
  pivot-dependent row of from_shumway Matrix3DClass failed.
- avm2_class.c: resolve_interfaces froze a NULL when an interface was not yet
  in the domain at its implementor's newclass (ASC emits the implementor
  first), making `implements X` invisible forever. Cache only non-NULL answers
  and install the interface-namespace aliases for any interface that resolves
  late. Fixes avm2/superinterface_call's #1034 and the #1069 behind it.
- avm2_ops.c + abc_emit.cpp: SWF<11 constructprop on a non-constructible SLOT
  reports #1115, not #1007 — but only inside a class/script initializer, the
  only bodies avmplus runs in interpreter mode. Emitted as a distinct
  avm2_op_constructprop_init off the existing BodyCtx::interp_mode, so
  avm2/construct_errors_swf10 keeps its #1007s.
- action.c: u16_cmp compares by code point, not UTF-16 code unit — AVM1 stores
  strings as UTF-8 and Flash's relational operators compare those bytes.
- action.c: the `TextField` global constructor exists from SWF 7 only.

C3 — the recompiler dropped a DoABC tag whose ABC failed to parse or validate,
swallowing an error avmplus reports as a catchable VerifyError at load. It now
emits a one-script stub whose initializer throws it, reusing the per-body
avm2_verify_error_body mechanism. AbcError carries the avmplus code/message
(#1027, #1121 with the declaring-trait name; #1107 as the fallback). The
verifier also records catch-target entry states before walking normal flow, so
a depth conflict at a handler target reports #1030 rather than the handler
body's downstream #1024.

--check-abc over all 4473 corpus SWFs is unchanged except the two intended
PARSE_FAILs and two intended message rows.

Tests: from_shumway Matrix3DClass, avm2/superinterface_call,
from_avmplus Error1115NotAConstructor/v10, avm1/string_relational_compare,
avm1/native_objects_swf6, avm2/verify_method_info_oob,
avm2/verify_exception_target_two_jumps.
```
