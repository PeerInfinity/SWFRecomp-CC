# Five diagnosed-but-unfixed AVM2 singles — evidence pack

Diagnosis only. No source edited, nothing committed. All line numbers are at
working-tree HEAD (`a9055f5e3` + the 4 dirty files listed in git status).

Baseline statuses read from `origin/ruffle-test-results:ruffle-tests/tests/swfs/{avm2,from_avmplus}/_results/results_graphics.json`
(sha `2ab0c01be`, CI 30673203712).

| test | baseline | verdict |
|---|---|---|
| `avm2/supercalls_weird` | output_mismatch | **BLOCKED** — two causes, second is a real feature (class-side super chain) |
| `avm2/activation_class` | output_mismatch | **READY** — one model change, precedent already in tree |
| `from_avmplus/ecma3/Statements/e12_10` | output_mismatch | **READY** (narrow variant) / blocked if done Ruffle's way |
| `from_avmplus/ecma3/ObjectObjects/hasOwnProperty` | output_mismatch | **READY** — one line of the ten, one namespace move |
| `avm2/getouterscope_two_classobjects` | output_mismatch | **READY (cause A)** + **READY-ish (cause B)** — and the documented cause was wrong |

---

## Correction that applies to two of the five

`SWFRecompDocs/plans/polish-sweep-arc.md` §5.5 and §8.7 both attribute
`getouterscope_two_classobjects` (and `scope_optimizations`) to "the MultinameL
scope-walk gap, shared with `scopes_dont_cache/order-1,2`". **That is stale.**

- The MultinameL findprop path shipped in session 6 and is complete end-to-end:
  emitter `SWFRecomp/src/abc/abc_emit.cpp:1247-1252` → `avm2_op_findproperty_dyn`
  (`SWFModernRuntime/src/avm2/avm2_ops.c:2714`) → `findproperty_scope_walk_named`
  (`avm2_ops.c:2135`) → `scope_defines_named` (`avm2_ops.c:2104`) →
  `avm2_vtable_find_mn_named` (`SWFModernRuntime/src/avm2/avm2_class.c:477`).
- `scopes_dont_cache/order-1` and `order-2` **pass** in the baseline.
- `getouterscope_two_classobjects` and `scope_optimizations` contain **zero**
  MultinameL ops (`grep -rn "rt-name"` over their `RecompiledABC/` is empty).
  Every findprop in them is a static `Multiname` (0x09) with an ns-set, which
  `avm2_vtable_find_mn` (`avm2_class.c:411`) already handles via `avm2_mn_match`
  (`avm2_class.c:204-219`).

So there is no shared MultinameL work item left. §5.5/§8.7 should be amended.

---

## Correction that applies to `supercalls_weird`'s stated trap

§8.7 says the #1035 throw site "is shared with the condition
`array_access_interpreter` pins, so it is exactly the brief's *never widen a
condition* trap." The comment in the code says the same
(`avm2_ops.c:3078-3079`: *"avmplus VerifyError 1035 (catchable) —
array_access_interpreter probes JIT-vs-interpreter behavior with an illegal
super op"*).

**That attribution is wrong.** `avm2/array_access_interpreter` contains no
`callsuper`/`getsuper`/`setsuper` at all — only two `ConstructSuper`s
(`ruffle-tests/tests/swfs/avm2/array_access_interpreter/RecompiledABC/abc0_methods.c:159`
and `:357`), and `avm2_op_constructsuper` (`avm2_ops.c:3272`) returns early on
`bound_class == NULL` **before** reaching `super_class_of`. That test's expected
`code 1081` comes from `GetPropertySlow mn[17] {ns-set 3}::{rt-name}`
(`abc0_methods.c:222`) — a non-public ns-set read off a dynamic Array — i.e.
`getproperty_common`'s `dynamic && !mn_public` arm at `avm2_ops.c:632-663`, a
completely different site.

Conclusion: the `super_class_of` #1035 condition is **not** pinned by
`array_access_interpreter`. It is still worth not widening it, but for the
reason given under §1 below, not this one.

---

# 1. `avm2/supercalls_weird` — BLOCKED (two causes)

### Current diff

```
$ python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 \
      --test=supercalls_weird --diff --verbose
[1/1] supercalls_weird... MISMATCH
  stderr: AVM2 uncaught error: VerifyError: Error #1035: Illegal super expression found in method.
-    1  true
+    1  (nothing)
-    2  [object Object]
+    2  <end of actual>
```

Test SWF has no `.as` source upstream (hand-built ABC). The program, read off
`ruffle-tests/tests/swfs/avm2/supercalls_weird/RecompiledABC/abc0_methods.c`:

- **method[0] (the SCRIPT INIT)**, `abc0_methods.c:19-28`:
  ```
  2:  FindPropStrict mn[13] trace
  3:  GetLocal r0                                  // the script GLOBAL object
  4:  PushString "Tests"
  5:  CallSuper mn[15] http://adobe.com/AS3/2006/builtin::hasOwnProperty, args=1
  6:  CallPropVoid trace
  ```
  i.e. `trace(super.AS3::hasOwnProperty("Tests"))` executed on the script global
  **before** `InitProperty Tests` at op 39. Expected `true` — the class trait
  `Tests` already exists as a *slot* on the global, so `hasOwnProperty` is true
  from global-object creation.
- **method[1] `Tests/superCallTest`**, `abc0_methods.c:114-121`: a **STATIC**
  method (class-trait table `abc0_tables.c:99-102` = `{ kind 1 Method,
  name_mn 10 = public::superCallTest, disp 3, method 1 }`), doing
  `trace(super.prototype)` on the `Tests` **class object**. Expected
  `[object Object]`.

### Root cause A — script init has no bound superclass (line 1)

`avm2_ops.c:3075-3085`:

```c
static Avm2Class* super_class_of(Avm2Activation* act)
{
	if (act->bound_class == NULL || act->bound_class->super_class == NULL)
	{
		avm2_throw_error(act->ctx, act->ctx->builtins.verify_error_class,
		                 "Error #1035: Illegal super expression found in method.");
	}
	return act->bound_class->super_class;
}
```

Script inits are invoked with `bound_class = NULL`:
`avm2_globals.c:143-146` (`avm2_script_ensure_init`) →
`avm2_call_method_ref(file->ctx, &ref, NULL /* bound_class */, NULL /* outer */, ...)`.
`SWFModernRuntime/include/avm2/avm2_abc.h:629` documents the field as
`// defining class (ConstructSuper); NULL for scripts`.

**What avmplus/Ruffle bind — answered.** Ruffle mints a synthetic per-script
`global` class whose **base is `Object`** and hands it to the script init as its
bound class:

- `~/CC/ruffle/core/src/avm2/globals/global_scope.rs` `create_class()`:
  `Class::custom_new(QName(public, "global"), Some(class_defs().object), Some(init_method), traits, mc)`,
  then `set_attributes(ClassAttributes::FINAL)`.
- `~/CC/ruffle/core/src/avm2/script.rs:613` builds it, `:630`
  `let script_init_assoc = MethodAssociation::classbound(global_class, true);`
  `:631` `init_method.associate(activation, script_init_assoc)?;`
  (`classbound` at `core/src/avm2/method.rs:504`).

So a script init's `super` is **`Object`**, and `super.AS3::hasOwnProperty` is
`Object`'s AS3 method. Ruffle passes this test (its `test.toml` is
`num_frames = 1`, no `known_failure`) — the §8.7 note that Ruffle also throws
#1035 is incorrect; `bound_superclass_object: None` at
`core/src/avm2/activation.rs:139/163` is `from_nothing`/`from_domain`, not the
script-init path.

We already have the class: `ctx->builtins.global_class`, created at
`avm2_globals.c:3351-3357` with `gc->super_class = b->object_class`, and every
script global is stamped with it at `avm2_main.c:170-171`. `Object`'s ivtable
carries a public `hasOwnProperty` (`avm2_globals.c:3374-3375`,
`object_as3_has_own_property`), and `avm2_propkey_matches`
(`avm2_class.c:97-116`) folds the AS3 builtin ns onto public, so the mn[15]
lookup in `avm2_op_callsuper` (`avm2_ops.c:3100`) will hit it.

**Fix design A (recommended, zero blast radius):** special-case inside
`super_class_of` rather than changing `bound_class`.

```c
static Avm2Class* super_class_of(Avm2Activation* act)
{
	if (act->bound_class == NULL)
	{
		// A SCRIPT INIT's `this` is the script global, whose class is the
		// synthetic `global` class with base Object (Ruffle
		// globals/global_scope.rs create_class + script.rs:630
		// MethodAssociation::classbound(global_class, true)). avm2/supercalls_weird
		// calls super.AS3::hasOwnProperty on it.
		if (act->this_val.kind == AVM2_VALUE_OBJECT
		    && act->this_val.u.obj != NULL
		    && act->this_val.u.obj->cls == act->ctx->builtins.global_class)
		{
			return act->ctx->builtins.object_class;
		}
	}
	if (act->bound_class == NULL || act->bound_class->super_class == NULL) { ...1035... }
	return act->bound_class->super_class;
}
```

**Why NOT the "faithful" variant** (pass `ctx->builtins.global_class` as
`bound_class` at `avm2_globals.c:145`): `avm2_callstack_push`
(`avm2_error.c:89`) stores it, and `avm2_callstack_frame_name`
(`avm2_error.c:112-163`) prints `global$init()` *only* on the `bound_class ==
NULL` fallthrough (`avm2_error.c:162`). With a non-NULL bound class it would
print `global/<anonymous>()` and break the pinned frame text in
`avm2/error_stack_trace/output.txt:3,8,15` and ~20 lines of
`avm2/primitive_valueOf/output.txt`. Doable (two extra lines teaching
`avm2_callstack_frame_name` and `avm2_class.c:1025-1030` /
`avm2_function.c:29-32` about `global_class`), but strictly more risk for the
same result.

### Root cause B — static-method `super` resolves on the wrong side (line 2) — **the blocker**

`superCallTest` is a class (static) trait, so its entry is built by
`avm2_vtable_add_traits(ctx, cvt, file, cd->class_traits, ..., cls, scope)`
(`avm2_class.c:1337`) with `e.defining_class = cls` (`avm2_class.c:603`). When
called, `act->bound_class == Tests`. Then:

```c
// avm2_ops.c:3186-3193
Avm2Value avm2_op_getsuper(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx)
{
	Avm2Class* super = super_class_of(act);          // -> MovieClip
	...
	return getsuper_common(act, recv, super,
	       avm2_vtable_find_mn(&super->ivtable, act->file->data, mn_idx), ...);
}
```

`super->ivtable` is `MovieClip`'s **instance** vtable, which has no `prototype`
→ `getsuper_common` throws #1069 (`avm2_ops.c:3142-3145`). avmplus resolves a
static method's `super` against the base **class traits** (`MovieClip$` →
… → `ClassClosure`), where `prototype` lives — hence the expected
`[object Object]` (`Tests.prototype`).

Our `Avm2Class` has no ctraits twin: `super_class` is the instance chain only,
and the class object's static vtable is a bare `Avm2VTable* cvt`
(`avm2_class.c:1336-1338`) with no parent link. Implementing this means a
class-side super chain: for a static frame (detectable as
`act->this_val.u.obj->kind == AVM2_OBJ_CLASS &&
act->this_val.u.obj->class_ref == act->bound_class`), the super lookup must walk
`bound_class->super_class->class_object->vtable`, then
`ctx->builtins.class_class->ivtable`, then `object_class->ivtable`. That is a
new mechanism touching all five super ops (`avm2_op_callsuper` `:3087`,
`avm2_op_getsuper` `:3186`, `avm2_op_setsuper` `:3196`, and the two `_dyn`
forms `:3212`/`:3224`).

### Risk / blast radius

- Fix A alone: `super_class_of` is reached only from the five super ops. The
  new arm fires only when `bound_class == NULL` **and** the receiver's class is
  the singleton `global_class` — today that combination always throws. Nothing
  can regress; it can only turn a throw into a dispatch. It does *not* widen the
  condition `array_access_interpreter` needs (that test never reaches this site,
  see the correction above).
- Fix A alone does **not** land the test: line 2 then fails with #1069.
- Fix B is a genuine feature with a wider surface (`class_supercalls_errors`
  passes today and exercises setsuper leniency — it is the canary).

### Verdict

**BLOCKED.** Cause A is fully evidenced and mechanical (≈8 lines, ready to
implement on its own if someone wants the mechanism in tree), but the test needs
cause B too. Size cause B as its own item: *"static-method `super` = class-side
traits chain"*. Canaries for A: `avm2/error_stack_trace`, `avm2/primitive_valueOf`
(both already `output_mismatch` — check they do not get *worse*),
`avm2/array_access_interpreter` (pass), `avm2/class_supercalls_errors` (pass),
`avm2/method_without_body` (pass).

---

# 2. `avm2/activation_class` — READY

### Current diff

```
     1  trace([activation object])
-    2  Threw error, code 1069
+    2  Threw error, code 1006
     3  [activation object].AS3::hasOwnProperty:
-    4  Threw error, code 1069
+    4  Threw error, code 1081
     5  [activation object].dynamicProp = 3
-    6  Threw error, code 1056
+    6  <end of actual>
```

### What the test asserts (three probes on ONE receiver)

From `ruffle-tests/tests/swfs/avm2/activation_class/RecompiledABC/abc0_methods.c`,
method[2] `Test/Test`. `NewActivation` at op 5 (`:144`), `PushScope` at op 8, so
`GetScopeObject 1` is the activation object.

1. ops 12-14 (`:163-171`): `trace(activationObj)` → the String coercion looks up
   `toString` → **#1069**.
2. ops 39-42 (`:246-257`): `trace(activationObj.AS3::hasOwnProperty)` → missing
   property READ → **#1069**.
3. ops 67-69 (`:332-340`): `activationObj.dynamicProp = 3` → **#1056**.

### The single model that produces all three

The activation object must be an instance of a **synthetic class that is SEALED
+ FINAL, has NO superclass and NO prototype**. Then:

- rule 1 and rule 2 are the same rule — a missing property read on a *sealed*
  receiver is #1069 (`getproperty_common`, `avm2_ops.c:632-663`: `dynamic` is
  false, so the format picks `"1069"`);
- rule 3 is the sealed-write rule — #1056 (`setproperty_miss`,
  `avm2_ops.c:1083` / `:1400` / `:1715`).

Ruffle confirms exactly this shape:
`~/CC/ruffle/core/src/avm2/class.rs:910-946` `Class::for_activation` →
`ClassData::empty(name)` (no base class), `attributes =
ClassAttributes::FINAL | ClassAttributes::SEALED`, traits = the body traits,
name = the method's pool name in the public ns; and
`core/src/avm2/activation.rs:1786-1798` `op_new_activation` →
`ScriptObject::custom_object(gc, activation_class, None /* no proto */,
activation_class.vtable())`. The class is minted once per method at verify time
(`core/src/avm2/verify.rs:528-543 create_activation_class`).

### Why we currently produce 1006 / 1081 / nothing

`avm2_ops.c:3353-3367`:

```c
Avm2Value avm2_op_newactivation(Avm2Activation* act, uint32_t method_index)
{
	...
	Avm2Object* obj = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, vt->slot_count + 1);
	obj->cls = ctx->builtins.object_class;      // <-- DYNAMIC, and inherits Object
	obj->vtable = vt;
	...
}
```

- `obj->cls = object_class`, which is not `AVM2_CLASS_FLAG_SEALED`, so
  `avm2_object_is_dynamic` (`avm2_ops.c:160-169`) returns 1 →
  probe 2 takes the `dynamic` branch of `getproperty_common` → **1081**;
  probe 3 succeeds silently → **no output**.
- `obj->proto` is left NULL and `avm2_value_vtable` (`avm2_class.c:1552-1566`)
  returns `obj->vtable` (the activation's own) rather than falling back to
  `cls->ivtable`, so `toString` resolves to nothing, the coercion gets
  `undefined` and calls it → **1006**.

### Fix design (precedent is already in the tree)

`avm2_op_newcatch` (`avm2_ops.c:3369-3412`) already implements the identical
model for the catch scope object, complete with the comment at `:3401-3403`
(*"avmplus gives the catch scope a synthetic SEALED class named after the catch
variable, with no prototype"*) and the flags at `:3407-3408`
(`AVM2_CLASS_FLAG_SEALED | AVM2_CLASS_FLAG_FINAL | AVM2_CLASS_FLAG_SYNTH_CATCH`).
`avm2/catch_scope_slot` pins the resulting `#1069: Property toString not found
on e` (see its `output.txt` line 6), and `avm2/catch_class` pins the
`AS3::hasOwnProperty` → #1069 half (referenced in the comment at
`avm2_ops.c:639-641`).

Do the same in `avm2_op_newactivation`:

1. Mint a synthetic class: `name = ` the method's `debug_name`
   (`act->file->data->methods[method_index].debug_name`, public ns — Ruffle uses
   the pool method name), `super_class = NULL`, `prototype_obj = NULL`,
   `flags = AVM2_CLASS_FLAG_SEALED | AVM2_CLASS_FLAG_FINAL`.
2. `obj->cls = <that class>` instead of `ctx->builtins.object_class`.
   Leave `obj->vtable = vt` and `obj->proto = NULL` as they are.
3. **Cache it per method**, not per call. `newactivation` runs on every call of
   every method with `NEED_ACTIVATION`, so a per-call `avm2_alloc` would be a hot
   allocation. Add `Avm2Class** activation_classes;` to `Avm2AbcFileRt`
   (`SWFModernRuntime/include/avm2/avm2_abc.h`, next to `Avm2Class** classes;`)
   sized `data->method_count`, zeroed in `avm2_abc_load`
   (`avm2_main.c:154-156` is the model), filled lazily on first
   `newactivation`. This mirrors Ruffle (one class per method, made at verify
   time) and sidesteps the GC-ownership question entirely — do **not** set
   `AVM2_CLASS_FLAG_SYNTH_CATCH`, since `avm2_gc.c:633-636` would then free a
   shared class when any one activation object dies.
   (The per-call *vtable* stays per-call and keeps `no_index = 1`; it is freed by
   `avm2_gc.c:624-629` as today.)

### Risk / blast radius

- Activation objects are created by every function with captured locals, so this
  touches a lot of code paths — but only through the sealed/dynamic predicate.
  Captured locals are accessed by `getslot`/`setslot` (`avm2_op_getslot` /
  `avm2_op_setslot`), which never consult `object_is_dynamic`. Name-based access
  from a nested closure goes through the activation's own `vt`, which is
  unchanged.
- The scope walk (`scope_defines_mn`, `avm2_ops.c:2070`) only asks "does this
  vtable have the trait" — no throw path.
- The one real behaviour change: any code that *writes a new dynamic property
  onto an activation object* now throws #1056. ABC never emits that (the
  verifier requires declared body traits), and `activation_class` is the test
  asserting it must throw.
- `class_name_of` in error messages will now say the method name instead of
  `Object` for activation receivers — matches avmplus.

### Verdict

**READY.** One mechanism, one site, direct precedent 40 lines below it in the
same file. Canaries: `avm2/catch_scope_slot`, `avm2/catch_class`,
`avm2/array_access_interpreter` (uses `newactivation` at
`abc0_methods.c:146`/`:344` and reads a slot off it — must stay `pass`),
`avm2/method_association`, plus a broad AVM2 + `regression` sweep because
`newactivation` is common.

---

# 3. `from_avmplus/ecma3/Statements/e12_10` — READY (narrow variant)

### Current diff

```
-  var x; with (7) x = valueOf(); typeof x; PASSED!
+  var x; with (7) x = valueOf(); typeof x; FAILED! expected: number got: object
```

Source (`.../ecma3/Statements/e12_10/Test.as`): `var x; with(7) x = valueOf();`
then asserts `typeof x == "number"`.

Emitted (`.../e12_10/RecompiledABC/abc0_methods.c:59-66`):

```c
// 20: PushWith
sp--; lscope[scope_n].obj = avm2_op_pushscope(act, stk[sp]); lscope[scope_n].is_with = 1; scope_n++;
// 22: FindPropStrict mn[47] {ns-set 1}::valueOf
... avm2_op_findpropstrict_ic(act, lscope, scope_n, 47, 1, 0, &__fc) ...
// 23: CallProperty mn[47] {ns-set 1}::valueOf, args=0
... avm2_op_callproperty_ic(act, stk[sp], 47, &stk[sp + 1], 0, &__ic) ...
```

### Root cause

`avm2_op_pushscope` (`avm2_ops.c:2024-2043`) already boxes a primitive scope,
but the box **drops the primitive value**:

```c
Avm2Object* box = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 1);
box->cls   = avm2_value_class(ctx, v);      // Number
box->vtable = &box->cls->ivtable;
box->proto  = box->cls->prototype_obj;
return box;                                  // 7 is gone
```

So `findpropstrict valueOf` correctly finds `Number`'s ivtable entry, but
`callproperty` passes the **box object** as `this`. `number_value_of`
(`avm2_number.c:87-90`) is `return act->this_val;` → an object → `typeof
"object"`.

`Avm2ScopeEntry` is `{ Avm2Object* obj; uint8_t is_with; }`
(`SWFModernRuntime/include/avm2/avm2_class.h:183-187`); Ruffle's scope entry
holds a `Value` and `with(7)` keeps the integer, so `valueOf` is called with
`this = 7`.

### What reads scope entries (the "widen the struct" cost)

If you widen `Avm2ScopeEntry.obj` to an `Avm2Value`, all of these change:

| reader | where |
|---|---|
| `PushScope`/`PushWith` emission | `SWFRecomp/src/abc/abc_emit.cpp` (`lscope[scope_n].obj = avm2_op_pushscope(...)`) |
| **`GetScopeObject` emission** — reads `.obj` in emitted C directly | e.g. `activation_class/RecompiledABC/abc0_methods.c:20`, `:168`, `:251` |
| `scope_defines_mn` / `scope_defines_named` | `avm2_ops.c:2070`, `:2104` |
| `findproperty_scope_walk*` (4 variants) | `avm2_ops.c:2135`, `:2193`, `:2227`, `:2640` |
| `avm2_op_getglobalscope` / `avm2_op_getouterscope` | `avm2_ops.c:2045`, `:2059` (both return `Avm2Object*`) |
| `avm2_scope_capture` + `Avm2ScopeChain` | `avm2_class.h:190-196` |
| `avm2_op_newclass` / `avm2_op_newfunction` capture | `avm2_ops.c:3230+`, `:3341` |
| ~20 op signatures taking `const Avm2ScopeEntry*` | `include/avm2/avm2_ops.h:36,38,80,84,144,148,185,190,196,216,220,225,335,338,390,392` |

That is the "recompiler+runtime change" §6.6 flagged, and it is real.

### Fix design (smallest correct change — a *transparent* box, not a widened entry)

Keep `Avm2ScopeEntry.obj` as `Avm2Object*`. Make the box carry its primitive and
unwrap it wherever the box would become a **receiver**:

1. In `avm2_op_pushscope` (`avm2_ops.c:2038-2042`), mark the box and store the
   value. `avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 1)` already allocates one
   slot, and slots are GC-traced, so `box->slots[1] = v;` (slot indices are
   1-based here — see `avm2_slots_init_defaults`, `avm2_class.c:919-926`) needs
   **no struct change and no new GC root**. Add `uint8_t is_prim_box;` in the
   existing padding after `Avm2Object.kind` / `is_prototype`
   (`include/avm2/avm2_object.h:71-79` — that padding is already documented as
   free real estate).
2. Add one helper next to `value_is_null_like` (`avm2_ops.c:150`):
   ```c
   static Avm2Value unbox_scope_prim(Avm2Value v)
   {
       if (v.kind == AVM2_VALUE_OBJECT && v.u.obj != NULL && v.u.obj->is_prim_box)
           return v.u.obj->slots[1];
       return v;
   }
   ```
3. Apply it to `recv` at the top of the get/set/call property entry points:
   `avm2_op_getproperty_static*` / `_dyn`, `avm2_op_setproperty_static*` /
   `_dyn`, `avm2_op_callproperty*` / `_dyn` / `_lex`. Resolution on the
   primitive already works (`avm2_value_vtable` → class ivtable,
   `avm2_value_proto` → class prototype; `avm2_class.c:1552-1576`), so this is
   pure receiver substitution.

**Identity semantics.** The box is created *only* by `avm2_op_pushscope` and is
reachable only from `lscope`/`Avm2ScopeChain`, so unboxing at those sites cannot
be observed anywhere else. The one path that still leaks the box is
`GetScopeObject n` on a with-scope, which the recompiler emits as
`avm2_object_value(lscope[n].obj)` inline. If a test ever needs
`with(7) { ... getscopeobject ... }` to see `7`, change that one emission to a
runtime call `avm2_op_getscopeobject(lscope, n)` returning an unboxed
`Avm2Value` — one emitter line plus one 3-line runtime helper. **None of the
five tests needs it**, and `avm2/findprop_global_prototype` (which pushes the
number 4 as its global scope, per the comment at `avm2_ops.c:2036`) passes
today and stays on the resolution path, not the receiver path.

### Risk / blast radius

Small and well-bounded: three op families gain one predicate on `recv`; the flag
can only be set by `pushscope`. Worst case is a missed unwrap site (a `with` on
a primitive that reads a *property* rather than calling a method), which is the
same class of bug as today, not a new one.

Cost: ~25 lines, runtime only, **no recompiler change** in the narrow variant.
The full Ruffle-shaped `Avm2ScopeEntry`-as-`Value` rewrite remains available but
is a multi-file arc and is not needed for this test.

### Verdict

**READY** in the narrow variant. Canaries: `avm2/findprop_global_prototype`
(pass), `avm2/scope_optimizations` (already `output_mismatch`),
`from_avmplus/ecma3/Statements/e12_10_1`, plus the AVM1-adjacent `with` tests in
the `regression` suite.

---

# 4. `from_avmplus/ecma3/ObjectObjects/hasOwnProperty` — READY

### Current diff — **one line of ten**

```
     1  String.prototype.hasOwnProperty("split") PASSED!
-    2  str.hasOwnProperty("split") PASSED!
+    2  str.hasOwnProperty("split") FAILED! expected: false got: true
     3  Array.prototype.hasOwnProperty("pop") PASSED!
     4  Number.prototype.hasOwnProperty("toPrecision") PASSED!
     5  Date.prototype.hasOwnProperty("getTime") PASSED!
       ... (rows 6-10 all PASSED)
```

The ten assertions (`.../ecma3/ObjectObjects/hasOwnProperty/Test.as`) are:
five `X.prototype.hasOwnProperty(<method>)` → true, `String.prototype
.hasOwnProperty("random")` → false, `Object.prototype.hasOwnProperty
("constructor")` → true, `Object.prototype.hasOwnProperty("getTime")` → false,
`myobj.hasOwnProperty("constructor")` → false — **all nine already pass**. The
only failure is `var str = new String("JScript"); str.hasOwnProperty("split")`
→ must be **false**.

### Root cause

The machinery is already correct. `avm2_has_own_public_property`
(`avm2_ops.c:4155-4178`) deliberately uses the STRICT public finder:

```c
	// STRICT publicness: hasOwnProperty must not see AS3-namespace traits
	// (hasownproperty_namespaces).
	const Avm2VTable* vt = avm2_value_vtable(ctx, recv);
	if (avm2_vtable_find_public(vt, name, name_len) != NULL) return 1;
```

`avm2_vtable_find_public` (`avm2_class.c:443-475`) tests
`avm2_propkey_is_public` (`avm2_class.c:68-73`) = kind public **and empty URI**.

The problem is the *entries*, not the finder: `String`'s instance methods are
registered with a **public** key. `avm2_builtin_add_method_n`
(`avm2_globals.c:383-397`) does `e.key = builtin_key("", name);`, and
`avm2_string.c:643-658` registers all sixteen (`charAt`, `charCodeAt`, `concat`,
`indexOf`, `lastIndexOf`, `localeCompare`, `slice`, `split`, `substr`,
`substring`, `toLowerCase`, `toLocaleLowerCase`, `toUpperCase`,
`toLocaleUpperCase`, `toString`, `valueOf`) through it. avmplus puts every one
of them in the **AS3 namespace**, with only the `String.prototype` copies
public.

### Fix design

Add an AS3-keyed registrar next to the existing one and switch `avm2_string.c`
to it:

```c
// avm2_globals.c, beside avm2_builtin_add_method_n (:383)
void avm2_builtin_add_method_as3(Avm2Context* ctx, Avm2Class* cls,
                                 const char* name, Avm2MethodFn fn)
{
	... same as avm2_builtin_add_method_n, except:
	e.key = builtin_key("http://adobe.com/AS3/2006/builtin", name);
}
```

`AS3_NS` is already the constant at `avm2_class.c:59`.

Dispatch is unaffected: `avm2_propkey_matches` (`avm2_class.c:104-106`) folds
AS3 ↔ public in **both directions**, so `"abc".split(",")` at a public call site
still resolves to the AS3-keyed entry, and an explicit `AS3::split` site
resolves too. Only the STRICT finders change behaviour, and there are exactly
three callers of `avm2_vtable_find_public` in the tree
(`avm2_ops.c:4166` = `hasOwnProperty`; `avm2_flixel.c:236` and `:1060` = the
Flixel intrinsic fingerprint gate, which looks up Flixel class members, not
String's).

**Scope the change to `String` only for this test.** `Array`, `Number`, `Date`
and `RegExp` have the same avmplus-side namespace shape, but no test in the
corpus asserts it and moving them all at once widens the canary set for no
graded gain. Note this leaves the strictly-public `length` getter on `String`
alone (`avm2_builtin_add_getter`, `avm2_globals.c:407+`), which is correct —
avmplus has `String::length` in the public ns.

This is a *much* narrower job than §6.6's framing ("moving that surface is
[[avm2-es3-prototype-surface]]'s job"): the prototype surface is already
complete (rows 1, 3, 4, 5, 6, 7 all pass), so only the *instance-side* namespace
of one class has to move.

### Risk / blast radius

- Every String method call in the corpus goes through `avm2_propkey_matches`,
  which already unifies the two namespaces — this is the same fold that makes
  `Object`'s AS3 methods work today (`avm2_globals.c:3373` comment: *"Instance-side
  mirrors (AS3 namespace methods surface publicly here)"*).
- Watch for anything that reads String members through a strict-public path:
  `describeType`, `propertyIsEnumerable` (`avm2_globals.c:671`), for-in
  enumeration. Enumeration walks dyn-props, not the vtable, so it is unaffected.
- `avm2/hasownproperty_namespaces` (pass) is the direct canary and only gets
  *more* consistent.

### Verdict

**READY.** Canaries: `avm2/hasownproperty_namespaces`,
`from_avmplus/ecma3/ObjectObjects/isPrototypeOf`, the whole
`from_avmplus/ecma3/StringObjects/` + `as3/Types/String/` directories, and
`avm2/primitive_toString` / `avm2/primitive_valueOf`.

---

# 5. `avm2/getouterscope_two_classobjects` — TWO CAUSES, both separable

`test.toml` is `num_frames = 1` + `known_failure = true`, and the same is true
upstream (`~/CC/ruffle/tests/tests/swfs/avm2/getouterscope_two_classobjects/test.toml`).
**Ruffle is not the oracle here** — `output.ruffle.txt` ends `true/true/true/true`
where Flash's `output.txt` ends `50/50/50/50`. Grade against `output.txt`.

### Current diff

```
-    1  null
+    1  undefined
     2..9  50 70 50 70 50 70 50 70        (all match)
-   10..13 50 50 50 50
+   10..13 <end of actual>
  stderr: AVM2 uncaught error: ReferenceError: Error #1065: Variable field is not defined.
```

Nine of thirteen lines are produced; the abort is on line 10.

### Trace-site map (from `.../RecompiledABC/abc0_methods.c`, method[12] `Test/Test`)

| line | op | site |
|---|---|---|
| 1 | op 9 (`:464`) | `trace(Class1)` |
| 2 / 3 | ops 12 / 16 (`:470`, `:478`) | `slot1.staticFunc()` / `slot2.staticFunc()` |
| 4 / 5 | ops 27 / 30 (`:500`, `:506`) | `r1.instanceFunc()` / `r2.instanceFunc()` |
| 6 / 7 | ops 36 / 42 (`:518`, `:530`) | `slot1.staticFunc.call(null)` / `slot2....` |
| 8 / 9 | ops 47 / 52 (`:540`, `:550`) | `r1.instanceFunc.AS3::call(null)` / `r2....` |
| **10-13** | **op 57** (`:560`) | `callStaticFunc(r1, r2)` → method[11], which uses **`CallStatic`** four times |

So lines 6-9 (the `Function.call` path through `bind_method_entry`) already
work. The failure is entirely inside method[11] `Test/callStaticFunc`
(`abc0_methods.c:388-436`), whose four calls are
`avm2_op_callstatic(act, 7, ...)` ×2 and `avm2_op_callstatic(act, 6, ...)` ×2
(`:409`, `:417`, `:425`, `:433`).

### Cause A — a Class trait's slot must default to `null`, not `undefined` (line 1)

`Class1` is a **class trait** on script 1
(`.../RecompiledABC/abc0_tables.c`, `abc0_s1_t[] = { { 4, 4, 1, 0, 1, ... } }` —
kind 4 = Class, name mn[4] = public `Class1`). Script 1's init is method[5]
(`abc0_methods.c:128-205`); it runs `NewClass class[1] Class1` **twice** (ops 13
and 28) and `InitProperty` into `slot1` / `slot2` — it **never** assigns the
`Class1` trait slot. So `Class1` is read at its declared default, forever.

avmplus/Ruffle give a class-trait slot the default `null`:
`~/CC/ruffle/core/src/avm2/vtable.rs:625` — `TraitKind::Class { .. } => Value::Null`.

We give `undefined`. `avm2_vtable_add_traits` handles kind 4 in the same arm as
Slot/Function/Const (`avm2_class.c:606-661`); an ABC class trait carries
`type_mn == 0`, so the meta has no type and `slot_default_for`
(`avm2_class.c:828-856`) falls through every branch to
`return avm2_undefined();` (`:855`).

**Fix:** carry the "class trait" bit onto the slot meta (an
`is_class_trait` byte on `Avm2SlotMeta`, set at `avm2_class.c:608` alongside
`e.is_const = (t->kind == 6 || t->kind == 4)` at `:619`) and return
`avm2_null()` for it at the top of `slot_default_for`. Also make
`slot_needs_realization` (`avm2_class.c:864`) leave it templatable — `null` is
not a traced pointer, so the existing template path (`avm2_class.c:901-909`)
handles it without a patch entry.

Blast radius: only reachable when a class trait's slot is read *before* the
defining script assigns it. Normally `findpropstrict ClassName` triggers the
lazy script init (`avm2_globals.c:255`), which assigns it — so almost nothing
observes this. Low risk, ~5 lines.

### Cause B — `callstatic` must use the method's OWN captured scope, not the caller's (lines 10-13)

`avm2_ops.c:3066-3072`:

```c
Avm2Value avm2_op_callstatic(Avm2Activation* act, uint32_t method_index, Avm2Value recv,
                             const Avm2Value* args, uint32_t argc)
{
	const Avm2AbcMethodData* m = &act->file->data->methods[method_index];
	Avm2MethodRef ref = { m->fn, act->file, m->debug_name, method_index };
	return avm2_call_method_ref(act->ctx, &ref, NULL, act->outer, recv, args, argc);
}
```

`act->outer` is the **caller's** scope chain. `Class1/staticFunc` (method[7]) and
`Class1/instanceFunc` (method[6]) both do
`FindPropStrict mn[31] {ns-set 3}::field` (`abc0_methods.c:224-225`, `:251-252`),
which must resolve through the `ClassWithField` instance that method[5] pushed
as a scope before `newclass` (op 7 for the 50-instance, op 22 for the
70-instance). Called from `Test/callStaticFunc`, `act->outer` is `Test`'s chain,
which has no `ClassWithField` instance → **#1065 `Variable field is not defined`**.
`mn[31]` is a static `Multiname` (0x09) with ns-set 3 = `{ public, AS3, "",
Class1-private, Class1-protected, ... }`; the namespace matching is fine, the
scope chain is not.

**What Flash does, and why the expected output is `50 50 50 50`:** avmplus
`callstatic` dispatches through the `MethodEnv` that the `MethodInfo` was bound
to, and a `MethodInfo` gets exactly **one** `MethodEnv` — the one from its
*first* binding. Both `staticFunc` and `instanceFunc` were first bound by the
**first** `NewClass class[1]`, i.e. the class object whose captured scope holds
the `ClassWithField(50)` instance. Hence all four calls print `50`, including
the two made through the `slot2` / `r2` (70) objects. That is precisely the
weirdness the test exists to pin, and it is the correct fix rule.

**Fix design:** give each `(file, method_index)` a first-binding record and use
it in `callstatic`.

1. Add `Avm2MethodEnv { Avm2Class* defining_class; Avm2ScopeChain* scope; }`
   (or just two parallel arrays) to `Avm2AbcFileRt`
   (`include/avm2/avm2_abc.h:610-620`), sized `data->method_count`, zeroed in
   `avm2_abc_load` (`avm2_main.c:151-161`).
2. Stamp it, if unset, wherever a method is installed into a vtable — the
   Method/Getter/Setter arm of `avm2_vtable_add_traits`
   (`avm2_class.c:663-720`, where `ref` is built and `e.method_scope = scope` /
   `e.defining_class = defining_class` are set at `:603-604`). First writer
   wins — that is the whole semantic.
3. `avm2_op_callstatic` uses the record when present, falling back to
   `NULL, act->outer` when absent (methods never installed in a vtable):
   ```c
   const Avm2MethodEnv* env = &act->file->method_envs[method_index];
   return avm2_call_method_ref(act->ctx, &ref,
                               env->scope != NULL ? env->defining_class : NULL,
                               env->scope != NULL ? env->scope : act->outer,
                               recv, args, argc);
   ```

Blast radius is **tiny and measurable**: `avm2_op_callstatic` is emitted in
exactly three tests in the whole corpus —
`avm2/getouterscope_two_classobjects`, `avm2/method_association`
(baseline `output_mismatch`; expects `1107 / 1107 / 1034 / Passed / Passed` and
is the sibling test for this exact rule) and
`from_avmplus/regress/bug_498979` (baseline `pass`). Nothing else in the tree
calls it.

### Verdict

**Cause A: READY** (~5 lines, `avm2_class.c`). **Cause B: READY**, slightly
larger (~30 lines across `avm2_abc.h`, `avm2_main.c`, `avm2_class.c`,
`avm2_ops.c`) but with a three-test blast radius that can be verified
exhaustively. Both are needed to land the test. Neither has anything to do with
MultinameL. Canaries: `avm2/method_association`,
`from_avmplus/regress/bug_498979`, `avm2/scope_optimizations`,
`avm2/scopes_dont_cache/order-1` + `order-2`.

Note for whoever takes cause B: `avm2_class.c:1366` (`file->classes[class_idx] =
cls;`) keeps only the **last** class object when one class trait is
`NewClass`'d twice, and `avm2_ops.c:2498` / `:2562` read that array for the
`findprop_ownstatic` caches. That is a separate latent hazard in the same test
(it did not fire here because those sites are not on this path), worth a comment
but not part of this fix.

---

## Suggested doc amendments (not made)

`SWFRecompDocs/plans/polish-sweep-arc.md`:

- §5.5 bullet 1: `getouterscope_two_classobjects` and `scope_optimizations` are
  **not** MultinameL cases; `scopes_dont_cache/order-{1,2}` pass since session 6.
- §8.7 bullet 2 (`supercalls_weird`): the shared-condition trap with
  `array_access_interpreter` does not exist (that test has no super op); the real
  blocker is a second cause — static-method `super` needs a class-side traits
  chain. Also, Ruffle **passes** this test.
- §8.7 bullet 3 (`getouterscope_two_classobjects`): the second cause is
  `avm2_op_callstatic` ignoring the method's first-bound scope, not a
  MultinameL gap.
- §6.6 bullet 1 (`ecma3/ObjectObjects/hasOwnProperty`): nine of ten rows already
  pass; the remaining work is moving **String's instance methods** to the AS3
  ns, not the whole ES3 prototype surface.
