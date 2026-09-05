# w2-avm1-function — wave 2 (session 18): gnash `Function-v6/-v7/-v8`

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ae699268626606b03` (base `8f68a5fea`).
No commits, no pushes. Runtime-only patch; `SWFRecomp/build` copied from the main tree (valid per
wave-2 rules). All runs `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--diff --verbose`, `xargs -P 2` for the
main sweep (shared machine) and `-P 4` for the final legs (machine idle). No-graphics unless a row
says graphics.

## NEW files (coordinator stages these by name)

- `SWFRecompDocs/plans/session18-fanout-reports/w2-avm1-function.patch`
- `SWFRecompDocs/plans/session18-fanout-reports/w2-avm1-function-report.md`

No new source files, no new `.h` — so no CMakeLists / Emscripten / `verify_output.py` source-list
edit is required.

## Files touched by the patch

| File | Region |
|---|---|
| `SWFModernRuntime/include/actionmodern/object.h` | one new `#define PROPERTY_FLAG_PERM_DONTENUM 0x40`, next to the existing `PROPERTY_FLAG_PERM_READONLY 0x80` (0x40 was unused) |
| `SWFModernRuntime/src/actionmodern/action.c` | `builtin_wrapper_valueOf`; `setupArgumentsProps`; three ARRAY for-in walkers; new `static applyGlobalFunctionProtoLink` (placed immediately after `getFunctionProto`); one call each in `actionDefineFunction` / `actionDefineFunction2` |

108 insertions / 5 deletions, 2 files. Sibling-safe: no textual overlap with w2-avm1-hitarea
(`action.c` mouse-pick / virtual-property regions) or w2-avm1-goto (`swf.c`).

---

## 1. Verdict — GO, headline delivered

All three sub-mechanisms landed. **`Function-v6` `output_mismatch` (263/271) → `pass` (271/271)**,
and `-v7` / `-v8` (which carry the identical 8-line diff set) flip with it.

**Priced: +3 pass** — `from_gnash/actionscript.all/Function-v6`, `-v7`, `-v8`.

Plus **two unpriced side gains** discovered by the canary A/B, both strict moves toward Flash on
tests that stay `ruffle_matched`:

- `from_gnash/actionscript.all/Function-v5` +1 matching line (`stringInstance.__proto__ != undefined`
  now PASSED; the `arguments` for-in text also moves to Flash's), `#passed 135 → 136`
- `from_gnash/actionscript.all/String-v6` +1 matching line (367 → 368 of 377; same check at
  `String.as:1091`), `#passed 363 → 364`, still a strict subset of Ruffle's diff set

These three tests are `known_failure = true` with per-FP-version ruffle sidecars whose diff sets are
NOT a superset of ours, so `ruffle_matched` was never the reachable target for `Function-v6/7/8` —
Flash parity (`pass`) is, and that is what landed. **No `pass -> ruffle_matched` drift anywhere**
(the standing `ruffle-matched-trap` check): every canary that was `pass` is still `pass`, and the
two tests that changed output moved *away* from Ruffle and *toward* Flash.

---

## 2. Mechanism — three fixes, each confirmed by a purpose-built probe

Probe SWF built with MTASC (`-version 6`) and run through `verify_output.py` as a scratch
`regression` test; source + all legs in
`<scratch>/w2-avm1-function/probe/`. The probe was removed from the worktree before the
regression-suite sweep.

### F1 — the `arguments` object must have *permanently* zero enumerable properties

`gnash Function.as:487-500`:

```as
var a = arguments;
for (var props in a) { propRecorder.push(props.toString()); }
check_equals(propRecorder.length, 0);          // line 121 — we already passed this
ASSetPropFlags(a, null, 6, 1);                 // set DontDelete|ReadOnly, CLEAR DontEnum
for (var props in a) { propRecorder.push(props.toString()); }
check_equals(propRecorder.length, 5);          // Flash: obtained 0.  Ours: obtained 2.
```

`callee`/`caller` were **already** created `PROPERTY_FLAGS_DONTENUM` (`setupArgumentsProps`,
`action.c:8319`). The two entries we leaked came from the test's own
`ASSetPropFlags(a, null, 6, 1)`: `actionASSetPropFlags_func2` maps flash flag `1` onto
`PROPERTY_FLAG_ENUMERABLE` and duly *un-hides* them. Flash keeps them hidden regardless — the
arguments object exposes nothing to `for-in` before or after.

Fix: a new `PROPERTY_FLAG_PERM_DONTENUM` (0x40), outside the 0x01-0x04 window `ASSetPropFlags`
writes, set on the arguments object's `__proto__` / `callee` / `caller`, and honoured by the three
ARRAY for-in walkers (`arguments` is an `ASArray`, so only those walkers can reach these slots).
Deliberately **not** honoured by the OBJECT / MOVIECLIP walkers — nothing else sets the bit, and the
blast radius stays inside arguments objects.

Probe: `C1 before 0`, `C2 after 0 []`. `C3`/`C4` confirm `arguments.callee`/`.caller` still read as
`function` and `arguments.length` is still right; `C5` confirms a 2-argument call still enumerates
its two indices (`2 [1,0]`).

### F2 — a SWF-defined function's `__proto__` is `_global.Function.prototype` at CREATION time

`gnash Function.as:1059-1089`:

```as
_global.Function = function() { this.a = "string"; };
o = { p:"hi" };
_global.Function.prototype = o;
uf = function() {};
check(uf.p === "hi");                                   // line 256
check(uf.__proto__ === _global.Function.prototype);     // line 257
```

Our FUNCTION `GetMember` arm synthesises a **virtual** `__proto__` from the per-version
`getFunctionProto()` singleton (`action.c:54782`), which never observes a replaced `_global.Function`.
The `ASnative(1,0)` path (`action.c:7335-7357`) already does Flash's creation-time wiring; the
`DefineFunction` / `DefineFunction2` paths did not.

Fix: new `static applyGlobalFunctionProtoLink()`, called once from each of
`actionDefineFunction` / `actionDefineFunction2`. It materialises a real own `__proto__` slot
**only** when all of the following hold, so it is a strict no-op for every ordinary movie:

- `_global.Function` currently resolves to a `FUNCTION`;
- `funcPrototypeVar()` of it is an `OBJECT`;
- and that object is **neither** `g_function_proto_legacy` **nor** `g_function_proto_modern`
  (i.e. `_global.Function` really was replaced).

When it fires, the pre-existing `getPropertyWithPrototype(func->own_props, …)` walk in the FUNCTION
`GetMember` arm delivers both `uf.__proto__` and inherited members (`uf.p`) with no further change.

Probe: `D0 default uf proto eq Fnproto true`, `D0b typeof uf0.call function / uf0.apply function`
(untouched default path), `D1 uf.p hi`, `D2 true`, `D3 uf.prototype.constructor eq uf true`;
`D4`/`D5` after restoring `_global.Function` are back to the default answers.

Deliberate narrowing, recorded as a known divergence: Flash also stores a **non-object**
`_global.Function.prototype` (`Function.as:1046` sets it to `8`; our ASnative path reproduces that).
We skip that case for SWF-defined functions, because storing `8` as `__proto__` would leave the
function with no lookup chain at all and nothing in the corpus observes it. If a later test does,
drop the `protov.type != ACTION_STACK_VALUE_OBJECT` early return.

### F3 — `String.prototype == undefined` was TRUE; `__proto__` was never the problem

This is the line the brief flagged as riskiest. It is **not** a `__proto__` bug at all.

Probe on the unpatched tree:

```
typeof s = object                 typeof s.__proto__ = object
p != undefined  -> false          p == undefined -> true
p == String.prototype -> true     p.constructor == String -> true
String.prototype.valueOf()  typeof undefined
String.prototype.toString() = "[object Object]"
Object.prototype == undefined -> false   Array.prototype  == undefined -> false
Number.prototype == undefined -> true    Boolean.prototype == undefined -> true
```

`__proto__` resolves perfectly. The failure is in `actionEquals2`: for `<object> == undefined` it
converts the object side with `objectToPrimitive`; `builtin_wrapper_valueOf` returns
`ACTION_STACK_VALUE_UNDEFINED` for a receiver with no boxed `valueOf_value` — which is exactly what
`String.prototype` / `Number.prototype` / `Boolean.prototype` are — and the `a.type == b.type`
`UNDEFINED == UNDEFINED → true` arm then fires. Line 82 (`stringInstance.__proto__ ==
String.prototype`) "passed" for the wrong reason: **both sides collapsed to `undefined`**. That is
exactly the internal inconsistency wave-1 noticed but could not explain.

The sibling `builtin_prim_wrapper_toString` already carries the correct fallback (`"[object
Object]"`); `builtin_wrapper_valueOf` did not. Ruffle has the identical gap and documents it —
`~/CC/ruffle/core/src/avm1/globals/string.rs::to_string_value_of` returns `Value::Undefined` under a
`//TODO: This normally falls back to '[object Object]' or '[type Function]'` — which is why Ruffle
fails this line too.

Fix: when there is no boxed value, `builtin_wrapper_valueOf` returns **`this`** (mirroring
`builtin_object_valueOf`, including its `g_this_stack` type-tag preservation) instead of `undefined`.
That reaches Flash's observable answers through machinery that already exists: `actionEquals2`'s
"converted value is still an object ⇒ false" arm, and string concat's non-primitive → `toString`
fallback (`String.prototype + ""` now yields `"[object Object]"`, matching
`String.prototype.toString()`, where it used to yield `"undefined"`).

Boxed receivers are untouched — probe `A5 boxed valueOf [xy] typeof string`, `A6 boxed toString
[xy]`, `A7 boxed concat [xy!]`, `A8 num valueOf 7 concat [8]`, `A9 bool valueOf true`,
`B4 Object5 valueOf 5 typeof number`.

### Why all 8 lines had to land together

`from_gnash/actionscript.all/*-vN` tests score on exact parity, so any single fix left the test at
`output_mismatch`. The 8 diff lines are 3 real check flips plus 3 text-only rows plus the 2 derived
Dejagnu totals:

| lines (v6) | before | after (== Flash) | fix |
|---|---|---|---|
| 81 | `FAILED: stringInstance.__proto__ != undefined` | `PASSED` | F3 |
| 122 | `expected: 5 obtained: 2` | `expected: 5 obtained: 0` | F1 |
| 123-124 | `obtained: callee` / `obtained: caller` | `obtained: ` / `obtained: ` | F1 |
| 256 | `FAILED: uf.p === "hi"` | `PASSED` | F2 |
| 257 | `FAILED: uf.__proto__ === _global.Function.prototype` | `PASSED` | F2 |
| 269-270 | `#passed: 253` / `#failed: 10` | `#passed: 256` / `#failed: 7` | derived |

F1's rows stay `FAILED` in Flash too (Flash gets 0, gnash expects 5); only the `obtained:` text
changes. +3 passes → `#passed` 253 → 256 and `#failed` 10 → 7, exactly the expected values.

---

## 3. Per-test before / after — headline

| test | mode | before (baseline `results_graphics.json` @ `8f68a5fea`) | after |
|---|---|---|---|
| `from_gnash/actionscript.all/Function-v6` | no-graphics | `output_mismatch` 263/271 | **`pass` 271/271** |
| `from_gnash/actionscript.all/Function-v7` | no-graphics | `output_mismatch` 264/272 | **`pass` 272/272** |
| `from_gnash/actionscript.all/Function-v8` | no-graphics | `output_mismatch` 264/272 | **`pass` 272/272** |
| `from_gnash/actionscript.all/Function-v6` | **graphics** (local Dawn) | `output_mismatch` | **`pass`** |

Mode parity holds for the change: the graphics leg agrees with no-graphics on all four graphics
canaries below.

---

## 4. Canary ledger

131 single-test runs across four suites (every test copied into the worktree's canonical suite path,
`--recompile` on first use). **124 rows byte-status-unchanged, 3 intended flips, 0 regressions.**

### Suite roll-up

| suite | tests run | unchanged | flips | regressions |
|---|---|---|---|---|
| `from_gnash/actionscript.all` | 12 | 9 | 3 | 0 |
| `avm1` | 25 (21 + 4 SWF-less, see note) | 21 | 0 | 0 |
| `from_shumway/avm1` | 5 | 5 | 0 | 0 |
| `regression` (whole suite) | 91 | 91 | 0 | 0 |

### `from_gnash/actionscript.all`

| test | before | after |
|---|---|---|
| `Function-v6` / `-v7` / `-v8` | `output_mismatch` | **`pass`** (intended flip) |
| `Function-v5` | `ruffle_matched` 144/158 | `ruffle_matched`, **+1 Flash-matching line** (see §1) |
| `String-v6` | `ruffle_matched` 367/377 | `ruffle_matched` **368/377**, still ⊆ ruffle |
| `Boolean-v6` | `pass` 38/38 | `pass` |
| `Number-v6` | `pass` 239/239 | `pass` |
| `Global-v7` | `pass` 182/182 | `pass` |
| `Date-v6` | `ruffle_matched` | `ruffle_matched`, actual output **byte-identical** |
| `Global-v6` | `ruffle_matched` | `ruffle_matched`, **byte-identical** |
| `Inheritance-v6` | `ruffle_matched` | `ruffle_matched`, **byte-identical** |
| `Object-v6` | `ruffle_matched` | `ruffle_matched`, **byte-identical** |

`Boolean-v6` and `Number-v6` are the direct blast-radius probes for F3 (their prototypes are exactly
the unboxed receivers whose `valueOf` changed) — both still `pass` at full line count.

### `avm1` (all `pass` before and after unless noted)

`arguments`, `array_enumerate`, `boxed_primitives`, `coerce_to_primitive_resolve`, `enumerate`,
`function_as_function`, `globals_swf6`, `globals_swf8`, `native_objects_swf8`,
`new_object_enumerate`, `new_object_wrap`, `object_constructor`, `object_function`,
`object_properties`, `object_prototypes`, `object_string_coerce_swf6`, `prototype_enumerate`,
`prototype_properties`, `string_coercion`, `string_methods` — all `pass` → `pass`.
`native_objects_swf6` `output_mismatch` → `output_mismatch`, **actual output byte-identical**.

**Note (not a regression):** `external_interface`, `global_instance_decls`, `global_proto_decls`,
`global_proto_decls_delete` report `RECOMP_FAIL` — those four dirs are git-tracked for their
`output.flash.txt` only; `test.swf` is downloaded and is absent in a fresh worktree
(`SWF file 'test.swf' not found`). Pure worktree artefact, verified by `ls`.

### `from_shumway/avm1`

`callee`, `lookup`, `nativeinheritance`, `operations`, `scope` — all `pass` → `pass`.
(`callee` and `nativeinheritance` are the direct F1/F2 probes in that suite.)

### `regression` (whole suite, 91 tests)

All 91 `pass` → `pass`. No flipped test, so no README needed to be read.

### Exact-output A/B for every non-`pass` canary

`--save-actual` on both legs (`git diff` + `git apply -R` for the "before" leg — never `git stash`,
per the shared-`refs/stash` rule):

| test | before vs after |
|---|---|
| `avm1/native_objects_swf6` | identical |
| `from_gnash/.../Date-v6` | identical |
| `from_gnash/.../Global-v6` | identical |
| `from_gnash/.../Inheritance-v6` | identical |
| `from_gnash/.../Object-v6` | identical |
| `from_gnash/.../Function-v5` | 4 lines changed — all toward Flash (§1) |
| `from_gnash/.../String-v6` | 2 lines changed — all toward Flash (§1) |

Scored against `output.txt` (Flash) rather than status alone:
`Function-v5` 141 → 142 matching of 158; `String-v6` 367 → 368 of 377 and still a strict subset of
`output.ruffle.txt`'s diff set (so its `ruffle_matched` verdict is safe, not accidental).

### Graphics mode (CI's grading mode, local Dawn)

| test | result |
|---|---|
| `from_gnash/actionscript.all/Function-v6` | **`pass`** |
| `from_gnash/actionscript.all/String-v6` | `ruffle_matched` (matches its no-graphics verdict) |
| `avm1/arguments` | `pass` |
| `avm1/boxed_primitives` | `pass` |

---

## 5. Refutations of the wave-1 pricing / mechanism

**Pricing: upheld.** +3, one identical 8-line diff set on all three tests — and `Function-v6/7/8`
reach `pass`, not merely fewer diff lines. Wave-1's magnitude estimate survived intact; it also
*under*-counted, missing the two `Function-v5` / `String-v6` line gains F3 brings along.

**Mechanism F1: refuted in substance.** Wave-1 wrote "we expose `callee` and `caller` to for-in.
Fix = `DontEnum` on those two." They were *already* `DontEnum` (`action.c:8319`). A `DontEnum` patch
would have been a literal no-op. The real fact is that the test *itself* clears `DontEnum` via
`ASSetPropFlags(a, null, 6, 1)` and Flash ignores that request for the arguments object — so the fix
is a new permanent-hide bit, not a flag change.

**Mechanism F3: refuted, and relocated.** Wave-1: "needs a real read of the `__proto__` accessor on
a String instance, not a guess", and called line 82 "internally inconsistent". `__proto__` reads
correctly in every respect (`typeof` object, `== String.prototype`, `.constructor == String`). The
bug is in `builtin_wrapper_valueOf` / `actionEquals2` — a different subsystem from the one the brief
named — and the "inconsistency" is fully explained: line 82 passed only because *both* operands
degenerated to `undefined`. Wave-1's risk read was right for the wrong reason: the fix does have
corpus-wide reach (it changes every `==`/`!=` against an unboxed String/Number/Boolean prototype and
every string coercion of one), just not through the `__proto__` path it named.

**Mechanism F2: upheld, with one correction.** Wave-1 said a user function's `__proto__` "must be
`_global.Function.prototype`". True, but the binding is **creation-time**, not lookup-time — the
same test later sets `_global.Function` to `8`, then `{}`, then `function(){}`, and a lookup-time
implementation would retro-actively re-point every already-defined function (including Dejagnu's own
`check` / `totals`) at each of those in turn. The patch captures at creation.

**Attacking my own pricing.** The +3 is a genuine flip set, not a diff-line reduction: all three
reach `pass` in both modes. The residual risk is not in the pricing but in F3's blast radius, which
is corpus-wide by construction. That is what the 131-row ledger is for — and the two rows it *did*
move both moved toward Flash. What the ledger does **not** cover: AVM2 suites (`avm2`,
`from_avmplus`) and the misc group. `builtin_wrapper_valueOf` is AVM1-only
(`SWFModernRuntime/src/actionmodern/action.c`, reached only from AVM1 `objectToPrimitive` /
CallMethod), and `PROPERTY_FLAG_PERM_DONTENUM` is set at exactly one site, so AVM2 exposure should be
nil — but the honest statement is "argued, not measured". A `categories=all` graphics dispatch is the
right gate; `categories=full` is not required (no AVM2 runtime/recompiler emission changed).

---

## 6. New unclaimed leads

1. **`arguments` index enumeration order.** Probe `C5`: a 2-argument call enumerates `[1,0]`, i.e.
   descending. Flash's order for arguments indices is unverified — no corpus test covers it
   (`Function.as` only ever calls the probe function with zero arguments). Cheap to settle with a
   one-line gnash-style fixture if anyone needs `for..in` over `arguments` to be right.
2. **`Number.prototype` / `Boolean.prototype` `valueOf` fallback is now `this`, not `"[object
   Object]"`.** Ruffle's TODO says Flash returns the *string* `"[object Object]"` (and `"[type
   Function]"` for functions). Returning `this` reproduces every currently-observable answer
   (equality, concat) because the callers fall back to `toString`, but `String.prototype ==
   "[object Object]"` would still be `false` for us and `true` in Flash. No corpus test discriminates;
   if one appears, the fix is to return the string from `builtin_wrapper_valueOf` directly.
3. **Flash's non-object `_global.Function.prototype` for SWF-defined functions** (see §2 F2's
   deliberate narrowing) — the `ASnative(1,0)` path stores `8`; `DefineFunction*` skips it.
4. **`Function-v5` is now 16 raw diff lines from Flash (was 17) and still `ruffle_matched`.** Its
   remaining gap is a different family from `-v6/-v7/-v8` (SWF5 has no closures / no
   `Function.prototype` participation), so it is a separate slice, not a rider on this one.
5. **`ASSetPropFlags` on an ARRAY reaches `arr->props` only.** The auto-create arm for index names
   already exists, but `arguments`' numeric slots and `length` are never given metadata entries, so
   `ASSetPropFlags(arguments, null, 2, 0)` (DontDelete) is silently a no-op for them. Untested by
   anything; noted while reading the function.

---

## 7. Reproduction

```bash
# headline (no-graphics)
export SWFRECOMP_COMPILE_TIMEOUT=2400
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/from_gnash/actionscript.all \
  --test=Function-v6 --diff --verbose          # -> PASS

# CI grading mode
export DAWN_INSTALL=/home/robert/CC/dawn-install     # required in a worktree
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/from_gnash/actionscript.all \
  --test=Function-v6 --mode=graphics --diff --verbose   # -> PASS
```

Scratch artefacts (probe source, all 131 canary logs, both A/B legs, scoring scripts):
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w2-avm1-function/`
