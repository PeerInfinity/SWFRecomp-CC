# `avm2/supercalls_weird` — session-8 diagnosis + implementation plan

Diagnosis only. Nothing edited, nothing built, nothing dispatched. All line
numbers are at HEAD `1c7c23761` (clean tree).

**Verdict: GO.** Session 7 called this BLOCKED. That verdict is now stale: the
"class-side super chain" it sized as a new mechanism is, in Ruffle's model,
**a single constant** (`Class`), not a chain walk. The whole test is 3 small
edits in one file (`SWFModernRuntime/src/avm2/avm2_ops.c`), ~20 lines, and a
whole-corpus ABC sweep proves the blast radius is **one op site in one test**.

---

## 1. Status at HEAD (re-run, not inherited)

```
$ python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 \
      --test=supercalls_weird --diff --verbose
[1/1] supercalls_weird... MISMATCH [r=0.00s c=13.39s x=0.01s]
  stderr: AVM2 uncaught error: VerifyError: Error #1035: Illegal super expression found in method.
-    1  true
+    1  VerifyError: Error #1035: Illegal super expression found in method.
-    2  [object Object]
+    2  	at global$init()
```

Baseline in `ruffle-tests/tests/swfs/avm2/_results/results_graphics.json`:
`output_mismatch`. **Note the diff has changed since session 7** — the actual
side used to be empty; the uncaught-error tracing that landed bundled in
`5d3f09c47` now prints the error + frame into the trace stream. Same root
cause, different-looking diff.

`test.toml` is `num_frames = 1` — **no `known_failure`**, so Ruffle passes this
test and IS a valid oracle here. (The §8.7 note claiming Ruffle also throws
#1035 is wrong; session 7 already corrected it.)

---

## 2. The program (from `--dump-abc`)

`./SWFRecomp/build/SWFRecomp --dump-abc ruffle-tests/tests/swfs/avm2/supercalls_weird/test.swf`

```
class[0] Tests extends flash.display::MovieClip sealed
  instance init: method[2], class init: method[3]
  class traits:
    method superCallTest -> method[1] (disp_id 3) final
script[0] init: method[0]
  class Tests -> class[0] (slot_id 1)
```

There are exactly **three** super-op sites in the file:

| # | site | method | op | receiver | must bind to | expected result |
|---|---|---|---|---|---|---|
| 1 | SCRIPT INIT | `method[0]` op 5 | `CallSuper mn[15] AS3::hasOwnProperty, args=1` | `loc[0]` = the script global | **`Object`** (base of the synthetic `global` class) | `true` |
| 2 | STATIC method `Tests.superCallTest` | `method[1]` op 4 | `GetSuper mn[12] {ns-set 2}::prototype` | result of `FindPropStrict {ns-set 2}::prototype` = the `Tests` **class object** | **`Class`** (base of every c_class) | `Tests.prototype` → `[object Object]` |
| 3 | CLASS INIT (cinit) | `method[3]` op 3 | `ConstructSuper args=0` | `loc[0]` = the `Tests` class object | `Class` (or, today, `MovieClip`) | no-op either way |

Control flow: script init traces line 1 → `NewClass Tests` (runs cinit
`method[3]`) → root `Tests` instance is constructed → `method[2]` op 6
`CallPropVoid superCallTest` on the class object → line 2.

Today site 1 throws #1035 and aborts everything, so sites 2 and 3 have **never
executed** in our runtime.

---

## 3. What "class-side super chain" actually means (the session-7 over-estimate)

Session 7 predicted a chain walk:
`bound_class->super_class->class_object->vtable`, then
`class_class->ivtable`, then `object_class->ivtable`. **Ruffle does not do
that**, and neither does avmplus in any way that matters here.

`~/CC/ruffle/core/src/avm2/class.rs:530-534` (`Class::class_from_abc_index`,
which builds the **c_class** for every ABC class):

```rust
let mut class = ClassData::empty(c_name);      // c_name = "Tests$"
class.super_class = Some(class_class);         // <- ALWAYS `Class`, flat
class.attributes = Cell::new(ClassAttributes::FINAL);
```

Same at `class.rs:317-322` for the synthetic Vector c_class. So:

- a c_class's superclass is **`Class`**, unconditionally — never the base
  class's c_class. Static traits are *not* inherited in AS3, and Ruffle's model
  encodes exactly that.
- a static method / class init is `MethodAssociation`-bound to the c_class, so
  `activation.bound_superclass_object()` is `Class`'s ClassObject, and
  `op_get_super` (`activation.rs:1448-1470`) resolves against **`Class`'s
  instance vtable** — where the `prototype` getter lives.

Our runtime already has all of this:

- `ctx->builtins.class_class` = `avm2_builtin_class(ctx, "", "Class", b->object_class)`
  (`SWFModernRuntime/src/avm2/avm2_globals.c:3432`).
- `avm2_builtin_add_getter(ctx, b->class_class, "prototype", class_get_prototype)`
  (`avm2_globals.c:3481`) → `class_class->ivtable` carries `prototype`.
- Every class object is stamped `cobj->cls = ctx->builtins.class_class`
  (`SWFModernRuntime/src/avm2/avm2_class.c:1364`), with `cobj->vtable = cvt`
  holding only that class's own static traits (`avm2_class.c:1357-1362`).
- `class_get_prototype` (`avm2_globals.c:820-829`) returns
  `this->class_ref->prototype_obj` for an `AVM2_OBJ_CLASS` receiver — exactly
  `Tests.prototype`.

So the "class-side super chain" is one constant: `ctx->builtins.class_class`.

**Useful side fact (bounds the risk of edit C below):** `class_class` is created
at `avm2_globals.c:3432`, but `Object`'s three ivtable methods
(`hasOwnProperty`, `isPrototypeOf`, `propertyIsEnumerable`) are only registered
at `avm2_globals.c:3471-3476` — *after*. `avm2_builtin_class` copies the super
ivtable **at creation time** (`avm2_globals.c:340-351`). Therefore
`class_class->ivtable` contains **exactly one entry: `prototype`**.

---

## 4. Root causes, confirmed against the current tree

### Cause A — script init has no bound class (line 1)

`avm2_ops.c:3143-3153` (session 7 quoted `:3075`; it has moved):

```c
static Avm2Class* super_class_of(Avm2Activation* act)
{
	if (act->bound_class == NULL || act->bound_class->super_class == NULL)
	{
		// avmplus VerifyError 1035 (catchable) — array_access_interpreter
		// probes JIT-vs-interpreter behavior with an illegal super op.
		avm2_throw_error(act->ctx, act->ctx->builtins.verify_error_class,
		                 "Error #1035: Illegal super expression found in method.");
	}
	return act->bound_class->super_class;
}
```

Script inits are called with `bound_class = NULL`
(`avm2_globals.c:143-146`, `avm2_script_ensure_init`). Ruffle instead binds them
to a synthetic per-script `global` class whose base is `Object`
(`~/CC/ruffle/core/src/avm2/globals/global_scope.rs` `create_class()`;
`script.rs:630` `MethodAssociation::classbound(global_class, true)`).

We already have the class: `ctx->builtins.global_class`, `super_class =
object_class` (`avm2_globals.c:3446-3455`), and every script global is stamped
with it (`avm2_main.c:196-197`).

**The code comment at the throw site is factually wrong** and should be fixed
while we're there: `avm2/array_access_interpreter` has **no**
get/set/callsuper at all — its only super op is a `ConstructSuper` in its
script init, which returns early at `avm2_op_constructsuper`'s
`bound_class == NULL` guard (`avm2_ops.c:3341-3350`) *before* `super_class_of`
is reached. Verified by the whole-corpus sweep in §6. (Session 7 said the same;
re-confirmed here from the ABC, not from the doc.)

### Cause B — static-method super resolves on the instance side (line 2)

`superCallTest` is a class trait, so its vtable entry is built by
`avm2_vtable_add_traits(ctx, cvt, file, cd->class_traits, ..., cls, scope)`
(`avm2_class.c:1359-1360`) with `e.defining_class = cls`. When
`method[2]` calls `Tests.superCallTest()`, `callproperty_common` dispatches with
`bound_class = Tests` and `this = the Tests class object`. `super_class_of`
returns `MovieClip`, and `avm2_op_getsuper` (`avm2_ops.c:3254-3263`) looks
`prototype` up in `MovieClip->ivtable` — not there → `avm2_throw_1069`.

The same detection applies to the class initializer: `avm2_class.c:1376-1377`
calls cinit with `bound_class = cls`, `this = cobj`.

### Cause C (NEW — session 7 missed this) — `FindPropStrict prototype` fails first

Fixing A and B is **not enough**. `method[1]` op 3 is
`FindPropStrict mn[12] {ns-set 2}::prototype`, which runs *before* the
`GetSuper`. The scope walk uses `scope_defines_mn` (`avm2_ops.c:2114-2129`):

```c
if (!se->is_with)
{
	return avm2_vtable_find_mn(se->obj->vtable, act->file->data, mn_idx) != NULL;
}
```

For the `Tests` class object, `se->obj->vtable` is `cvt` — only
`superCallTest`. `prototype` lives on `class_class->ivtable`, which the scope
walk never consults. The domain has no `prototype`, and
`findproperty_global_proto` (`avm2_ops.c:2320-2346`) only scans *dynamic* props
on the global's proto chain. Result: `findproperty_impl` (`:2362-2373`) falls
through to `avm2_throw_1065` — **"prototype is not defined"**, a new failure
mode replacing the old one.

The precedent for the fix is already in the tree, 1800 lines up, in
`resolve_key` (`avm2_ops.c:289-298`):

```c
if (e == NULL && recv.kind == AVM2_VALUE_OBJECT
    && recv.u.obj->kind == AVM2_OBJ_CLASS
    && ctx->builtins.class_class != NULL)
{
	// Class objects carry their static traits; Class's own instance
	// members (the `prototype` getter) come from Class's ivtable.
	e = avm2_vtable_find(&ctx->builtins.class_class->ivtable, key);
}
```

The scope walk simply never got the same treatment.

---

## 5. Implementation plan

**One file: `SWFModernRuntime/src/avm2/avm2_ops.c`. No recompiler change.**
(The emitter already produces the right ops.)

### Edit 1 — `super_class_of`, `avm2_ops.c:3143-3153`

```c
// Is this frame CLASS-SIDE (a static method or a class initializer)? Its
// receiver is the bound class's own class object. Ruffle models these as
// methods of the c_class, whose superclass is ALWAYS `Class` — flat, never
// the base class's c_class (class.rs:530-534 `class.super_class =
// Some(class_class)`), because AS3 does not inherit static traits.
static int frame_is_class_side(const Avm2Activation* act)
{
	return act->bound_class != NULL
	    && act->this_val.kind == AVM2_VALUE_OBJECT
	    && act->this_val.u.obj != NULL
	    && act->this_val.u.obj->kind == AVM2_OBJ_CLASS
	    && act->this_val.u.obj->class_ref == act->bound_class;
}

// Super dispatch: resolve on the bound class's SUPERCLASS vtable.
static Avm2Class* super_class_of(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->bound_class == NULL)
	{
		// A SCRIPT INIT is bound to the synthetic `global` class, whose base
		// is Object (Ruffle globals/global_scope.rs create_class + script.rs
		// :630 MethodAssociation::classbound(global_class, true)).
		// avm2/supercalls_weird calls super.AS3::hasOwnProperty on it.
		if (act->this_val.kind == AVM2_VALUE_OBJECT
		    && act->this_val.u.obj != NULL
		    && act->this_val.u.obj->cls == ctx->builtins.global_class)
		{
			return ctx->builtins.object_class;
		}
	}
	else if (frame_is_class_side(act))
	{
		return ctx->builtins.class_class;
	}
	if (act->bound_class == NULL || act->bound_class->super_class == NULL)
	{
		// avmplus VerifyError 1035 (catchable). NOTE: contrary to the old
		// comment here, avm2/array_access_interpreter does NOT pin this
		// condition — it has no get/set/callsuper at all, and its script-init
		// ConstructSuper returns early in avm2_op_constructsuper before
		// reaching this function.
		avm2_throw_error(ctx, ctx->builtins.verify_error_class,
		                 "Error #1035: Illegal super expression found in method.");
	}
	return act->bound_class->super_class;
}
```

Deliberately **inside** `super_class_of`, not by changing the `bound_class`
argument at `avm2_globals.c:145`. Two reasons, both load-bearing:

1. `avm2_callstack_frame_name` (`avm2_error.c:112-163`) prints `global$init()`
   only on the `bound_class == NULL` fallthrough. A non-NULL bound class would
   rewrite pinned frame text in `avm2/error_stack_trace/output.txt` and
   ~20 lines of `avm2/primitive_valueOf/output.txt`.
2. `avm2_op_constructsuper`'s `bound_class == NULL` early return
   (`avm2_ops.c:3341-3350`) is what keeps `avm2/array_access_interpreter`
   passing. Changing `bound_class` would silently disarm it.

### Edit 2 — class-object fallback in the scope walk, `avm2_ops.c:2114-2129`

```c
static int scope_defines_mn(Avm2Activation* act, const Avm2ScopeEntry* se, uint32_t mn_idx)
{
	if (se->obj == NULL) return 0;
	if (!se->is_with)
	{
		if (avm2_vtable_find_mn(se->obj->vtable, act->file->data, mn_idx) != NULL)
		{
			return 1;
		}
		// Same fallback resolve_key already applies (see the AVM2_OBJ_CLASS
		// arm there): a class object's own vtable holds only its static
		// traits; `Class`'s instance members (the `prototype` getter) come
		// from class_class->ivtable. A class object sits on the scope chain
		// of every one of its methods, so `prototype` unqualified inside a
		// static method must find it there.
		if (se->obj->kind == AVM2_OBJ_CLASS && act->ctx->builtins.class_class != NULL)
		{
			return avm2_vtable_find_mn(&act->ctx->builtins.class_class->ivtable,
			                           act->file->data, mn_idx) != NULL;
		}
		return 0;
	}
	...unchanged...
}
```

### Edit 3 (symmetry, optional) — same fallback in `scope_defines_named`, `avm2_ops.c:2148-2156`

The MultinameL twin. No corpus consumer (`super[expr]` / `this[expr]` never
targets `prototype` in the corpus), but leaving the two halves inconsistent is
how the next `_dyn`-shaped bug gets written. Uses
`avm2_vtable_find_mn_named(&class_class->ivtable, ...)`.

### Not needed

- **No** per-class c_class object, no cvt inheritance copy, no new field on
  `Avm2Class`. (An earlier idea — copying `class_class->ivtable` into every
  `cvt` — is worse: it costs memory per class in every game, and it collides
  with the known "re-registering an inherited member APPENDS, doesn't replace"
  trap, since `avm2_vtable_find` is first-match-wins and inherited entries
  would then shadow a class's own same-named static trait.)
- **No** change to `avm2_op_constructsuper`. Site 3 (the cinit's
  `ConstructSuper`) becomes a no-op either way: with edit 1 it resolves to
  `Class`, whose `instance_init.fn == NULL && instance_init.file == NULL`, and
  `avm2_call_method_ref` (`avm2_class.c:1032-1039`) treats that as "builtin stub
  with no native body — deliberate no-op". Without edit 1 it resolves to
  `MovieClip`, an identical stub. Neither has a `native_super_init`
  (only `avm2_array.c:1203` sets one).

---

## 6. Blast radius — measured, not estimated

I disassembled **every SWF in the corpus** with `--dump-abc` (4943 files:
4473 `test.swf` + 470 child/loader SWFs), segmented per `DoABC` tag, and
cross-referenced each method index against that tag's *class traits*,
*class init* and *script init* tables.
Script: `.../scratchpad/sweep3.py`.

```
('avm2/array_access_interpreter/test.swf', 'tag0', (get/set/call static:[], script:[],
                                                    constructsuper static:[], script:[0]))
('avm2/supercalls_weird/test.swf',        'tag0', (get/set/call static:[1], script:[0],
                                                    constructsuper static:[3], script:[]))
HITS 2  swfs 4943
```

- **`supercalls_weird` is the only test in the entire corpus with a
  get/set/callsuper in a class-side frame or in a script init.** Edits 1's two
  new arms are unreachable from every other test — they can only convert a
  throw into a dispatch.
- `array_access_interpreter`'s single hit is the script-init `ConstructSuper`
  already handled by the early return; edit 1 does not move it. This
  definitively closes out the §8.7 "shared condition" misattribution — from the
  bytecode, not from a doc.

For **edit 2**, the exposed surface is bounded twice over:
- `class_class->ivtable` holds exactly one entry, `prototype` (see §3), so only
  that one name can newly resolve on a class-object scope entry.
- A grep of every emitted op comment in the corpus for a findprop of
  `prototype`:
  ```
  $ grep -rh "FindProp\(Strict\)\? mn\[[0-9]*\].*prototype" --include=*_methods.c .
      1  // 3: FindPropStrict mn[12] {ns-set 2}::prototype     <- supercalls_weird
      1  // 6: FindPropStrict mn[2672] private::prototypeFactory  <- visual/definefont4
      1  // 2: FindPropStrict mn[2672] private::prototypeFactory
  ```
  **One op site in the whole corpus**, and it is the one we are fixing.
  (`prototypeFactory` is a different name and a private ns — no match.)

Residual (not corpus-visible): the flasharchive / glaiel games. Same two
bounds apply — a bare `prototype` findprop inside a class method, or a super op
in a static method. Both are vanishingly rare in compiled AS3 (ASC emits
`ClassName.prototype`, a `getproperty`, not a findprop).

### False-positive analysis for `frame_is_class_side`

The predicate is `this` is an `AVM2_OBJ_CLASS` **and** `class_ref ==
bound_class`. To trip it wrongly you would need an *instance* method containing
a super op, invoked with `this` set to its own declaring class's class object —
reachable only via something like `C.prototype.m.call(C)`, and AS3 does not put
class methods on prototypes. The sweep above shows every other super op in the
corpus lives in an instance method reached with an instance receiver.

---

## 7. Predicted output, line by line

| line | mechanism | value |
|---|---|---|
| 1 | edit 1 arm 1 → `super = Object`. `avm2_vtable_find_mn(&object_class->ivtable, mn[15])`: mn[15] is `QName(ns[16] = package "http://adobe.com/AS3/2006/builtin", "hasOwnProperty")`; `avm2_propkey_matches` (`avm2_class.c:96-116`) folds the AS3 builtin URI onto public via `key_ns_is_public`, so it hits the `AVM2_PROP_METHOD` entry registered at `avm2_globals.c:3471`. `object_as3_has_own_property` → `object_proto_has_own_property` → `avm2_has_own_public_property` (`avm2_ops.c:4261`) → `avm2_value_vtable` returns the script global's own `vtable` (`avm2_main.c:202-206`, built from the script traits, which include the `Tests` **class trait, slot 1**) → `avm2_vtable_find_public("Tests")` hits. The trait exists from global construction, long before op 39's `InitProperty`. | `true` |
| 2 | edit 2 → `FindPropStrict {ns-set 2}::prototype` finds the `Tests` class object at `lscope[0]`. edit 1 arm 2 → `super = Class`; `avm2_vtable_find_mn(&class_class->ivtable, mn[12])` hits the `prototype` getter (ns-set 2 contains `package`, so it matches the public key). `getsuper_common` → `resolved_get` → `class_get_prototype` with `this` = the class object → `Tests.prototype_obj`. `trace` coerces it: the prototype object is `AVM2_OBJ_SCRIPT` with `cls = object_class` (`avm2_class.c:1230-1231`) and no own `toString`, so the proto chain lands on `Object.prototype.toString` = `object_proto_to_string`, general branch, `avm2_value_class` → `object_class` → `tagged_class_string("object", "Object")`. | `[object Object]` |

**Prediction: the test flips to `pass` (2/2 lines). Yield +1.**

Confidence: high on line 1 (every hop verified in source), high-but-not-
certain on line 2 — three hops there have never executed in our runtime
(cinit `ConstructSuper`, `Tests.superCallTest()` dispatch, `class_get_prototype`
off a super entry). See §8.

---

## 8. Risks / things the implementer must actually check

1. **Line 2 is a first-execution path.** Sites 2 and 3 have never run, because
   site 1 aborts the movie. After edit 1 alone, expect the diff to move to a
   *different* error (most likely `#1065 prototype is not defined`, or `#1069`
   if I've misread the scope walk). That is the checkpoint that says edit 2 is
   needed and correctly placed — do edit 1 first and look at the intermediate
   diff, don't apply all three blind.
2. **Order matters in edit 1.** The class-side arm must be an `else if` on
   `bound_class != NULL`; a `frame_is_class_side` that dereferences a NULL
   `bound_class` would fire on script inits (whose `this` is a script object,
   not a class object — but don't rely on that).
3. **Do not "improve" edit 1 into passing `global_class` as the script init's
   `bound_class`.** It breaks `error_stack_trace` / `primitive_valueOf` frame
   text and disarms `array_access_interpreter`'s constructsuper guard. Both
   documented in §5.
4. **Fix the stale comment** at the #1035 throw site in the same commit — it is
   the source of the §8.7 misattribution and will mislead the next reader.
   Also amend `SWFRecompDocs/plans/polish-sweep-arc.md` §8.7 and the session-7
   report's "BLOCKED / class-side super chain is a new mechanism" sizing.
5. `class_class->ivtable` containing only `prototype` is a *consequence of
   initialization order* (`avm2_globals.c:3432` before `:3471`). If someone
   later moves Object's method registration above `class_class`'s creation,
   edit 2's surface silently grows to `hasOwnProperty` / `isPrototypeOf` /
   `propertyIsEnumerable`. Worth a one-line comment at the fallback.
6. Shared machine: any FLOAT mismatch or slow-compile timeout in a parallel
   canary batch is presumed false — re-run that test sequentially before
   believing it.

---

## 9. Canary list

Run local, `--mode=graphics` where cheap, stash-diff style (compare against the
same tests' ACTUAL output at HEAD, not against `results_graphics.json` alone —
`ruffle_matched` reads as FAIL in the runner).

**Target**
- `avm2/supercalls_weird` — `output_mismatch` → expect `pass`.

**Tier 1 — the five session-7 named canaries (all still valid)**
| test | baseline | why |
|---|---|---|
| `avm2/array_access_interpreter` | **pass** | the constructsuper early-return; must not move |
| `avm2/class_supercalls_errors` | **pass** | setsuper leniency (`setsuper_common`) |
| `avm2/method_without_body` | **pass** | `avm2_call_method_ref` NULL-fn path (#1001) |
| `avm2/error_stack_trace` | `output_mismatch` | pinned `global$init()` frame text — must not get *worse* |
| `avm2/primitive_valueOf` | `output_mismatch` | ~20 lines of pinned frame text — must not get *worse* |

**Tier 2 — every corpus test with any get/set/callsuper (instance side)**
`avm2/`: `astypelate` (pass), `class_supercalls_mismatched` (pass),
`es4_inheritance` (pass), `es4_interfaces` (pass),
`es4_protected_inheritance` (pass), `eventdispatcher_tostring` (pass),
`freestanding_superclass` (**ruffle_matched** — reads as FAIL in the runner,
do not report a flip), `instanceof` (pass), `interface_namespaces` (pass),
`istype` (pass), `istypelate` (pass), `sub_super_same_field`
(**output_mismatch** — already failing), `super_get_call` (pass),
`supercall_two_classobjects` (pass), `virtual_properties` (pass),
`bitmap_subclass` (pass).

`from_avmplus/`: `as3/Definitions/Super/SuperProps` (pass),
`as3/Definitions/Super/SuperInForLoop` (pass — the `super[expr]` `_dyn` path,
the one edit 3 touches), `as3/Definitions/Super/SuperRuntimeError` (pass),
`as3/Definitions/Classes/Ext/AccStatMethSubClassMethSuper` (pass — despite the
name, the sweep confirms its supers are instance-side),
`as3/Array/bug_535446` (ruffle_matched), `as3/Array/length_mods`
(ruffle_matched).

`regression/`: `avm2_timeline_gradients`, `avm2_timeline_solid`,
`avm2_timeline_stroke_gradient` — **always include the `regression` suite**;
read a flipped test's README before calling it a regression.

**Tier 3 — scope-walk canaries for edit 2** (findprop ordering is the thing
edit 2 perturbs): `avm2/scopes_dont_cache/order-1`, `.../order-2`,
`avm2/getouterscope_two_classobjects` (now **pass**), `avm2/scope_optimizations`,
`avm2/activation_class` (now **pass**).

**CI**: this touches AVM2 runtime emission-adjacent code → `mode=graphics`,
`categories=full`, `images=false`.

---

## 10. Corrections this session makes to the record

1. §8.7 / session-7's "class-side super chain is a new mechanism touching all
   five super ops" → **wrong sizing**. Ruffle's c_class superclass is the flat
   constant `Class`; no chain, no walk, no new struct. One `else if`.
2. Session 7's cause list was **incomplete**: it missed cause C
   (`FindPropStrict prototype` fails in the scope walk before `GetSuper` ever
   runs). A/B alone would have produced a new failure, not a pass — which is
   probably why "Fix A is ready but doesn't land the test" felt like the end of
   the road.
3. The §8.7 `array_access_interpreter` misattribution is now closed from the
   bytecode of all 4943 corpus SWFs, not from reading one test.
4. The HEAD diff for this test no longer matches the one in the session-7
   report (uncaught-error tracing landed in between).
