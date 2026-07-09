# Function-Dispatch Consolidation — Plan

**Created:** July 4, 2026
**Status:** Stage 0 COMPLETE (July 4, 2026) — see §4 Stage 0 results.
Stage 1 COMPLETE (July 8, 2026) — `invokeFunctionValue()` core + `InvokeOpts`
flags added and `invokeResolveFunction` wired to it (behavior-preserving); see the
Stage 1 landing note in §4.
Stage 2 COMPLETE (July 8, 2026) — the whole accessor family
(`invokePropertyGetter` / `invokePropertySetter` / `invokeResolveFunction`) are now
thin adapters over the core; see the Stage 2 landing note in §4.
Stage 3 IN PROGRESS (July 9, 2026) — 5 of `actionCallMethod`'s ~19 arms migrated
(`e4082f224`, `65d442f09`), one real TYPE1_ARG_ORDER bug found and fixed; the
remaining arms need new core capability (`arguments` object, closure-context
scope reset, ctor context). See the Stage 3 progress note in §4, then the
**Stage 3c design note** for the chosen shape (arm-owned `ClosureFrame` +
in-core `act_flags` activation) and the migration order. Stages 4–5 not started.
**Origin:** upstream-comparison advantage #6 (upstream has one calling convention;
we have ~38) and a four-times-shipped bug class. Survey of `action.c` (74,986
lines) + `timer.c` performed July 4, 2026; figures below are from that survey.

---

## 1. Motivation: this bug class keeps shipping

Four separate production bugs came from the same structural cause — every
dispatcher hand-rolls its own function-invocation ritual:

| Bug | Fix | What was wrong |
|---|---|---|
| Type-1 args pushed in REVERSE via super()/`__resolve`/array-element (swapped Minesweeper `setSize(w,h)`) | `bcacc3f70` | 6 dispatchers, each patched **inline** — no helper extracted |
| Type-1 virtual getter/setter missing arg-pad to `param_count` (one variant ate the caller's eval stack) | `63f7af229` | accessor helpers re-implement marshalling |
| Type-1 MC methods read the *caller's* `this` | cont.38 | missing `g_this_stack` push in one path |
| `actionNewObject` >16 args stranded operands, corrupting the next opcode | cont.30 | one-off marshalling with a silent cap |

The survey confirms the structure that produced them is intact:

- **~129 raw invocation points** (62 `simple_func` + 67 `advanced_func` calls)
  spread across **~38 distinct dispatcher functions**. No shared core.
- The `TYPE1_ARG_ORDER` fix exists as **32 duplicated forward-order push loops**
  (markers at `action.c:8209, 8626, 54723, 63521, 63640, 63726, 63843, 64750,
  65022`, …). Any new dispatcher can silently regress it.
- The type-1 pointer is stored as `void (*)(SWFAppContext*)` but **cast to
  `ActionVar (*)(SWFAppContext*)` at every one of the 62 call sites** — a
  duplicated ABI footgun.

### Suspected live bugs found by the survey (verify first — see Stage 0)

1. `actionEI_callInternalInterface` (`action.c:6313`) **still pushes type-1 args
   in reverse** — a site the bcacc3f70 sweep missed.
2. `mc_call_as2_handler_ng`'s type-1 arm (`~71798`) **pushes no args at all** —
   any type-1 event handler with declared parameters gets garbage/stack misuse.
3. Only **12 sites** call `switchToFunctionVersion`; all event/timer/
   LocalConnection/NetStream/NetConnection/ExternalInterface and several
   coercion dispatchers skip it → per-function SWF-version semantics are wrong
   on those paths.
4. LC/NS/NC and several coercion paths **skip captured-scope push** → closures
   invoked through them lose their scope chain.

These may be unreachable in practice (e.g. handlers rarely declare params;
internal EI interfaces may always be type-2 natives) — which is exactly why
Stage 0 verifies reachability before anything is "fixed".

## 2. Current state (survey summary)

**The correct ritual has ~11 steps**; no site performs all of them, and each
site includes a different subset: (1) `g_call_depth` guard, (2) `g_this_stack`
push, (3) super-context push/pop, (4) type-1 arg marshalling — *forward* order
+ pad to `param_count`, (5) type-2 registers alloc + args, (6) captured-scope
push/pop, (7) local scope frame + bind `"this"`, (8) `base_clip` /
`g_current_context` switch (SWF6+), (9) `switchToFunctionVersion` /restore,
(10) `g_event_this_mc` / `g_current_executing_func` save-restore, (11) return
value capture.

**Existing partial helpers** (none general):
- `call_function_with_this` (`action.c:73510`) — closest to a general
  dispatcher, but: void return, no type-1 pad, no version switch, no super
  context; exactly **one** caller (asfunction: links).
- `invokePropertyGetter`/`Setter`/`invokeResolveFunction` (`8091/8508/8393`) —
  shared for accessors only; each re-implements the ritual internally.
- `switchToFunctionVersion`/`restore` (`15559/15571`), `pushSuperContext`/`pop`
  (`432`) — correct primitives, inconsistently used.
- Subsystem-local rituals: `mc_call_as2_handler_ng` (all clip/button/key/focus
  events, ~33 call sites), `fireTimerCallback` (`timer.c:311`, two arms).

**Riskiest duplicated dispatchers:** `actionCallMethod` (~14 inline arms:
object/MC/super/array-proxy/`__resolve`/user-dispatch), `actionCallFunction`,
`actionNewObject`, `actionNewMethod`, `mc_call_as2_handler_ng`,
`call_function_with_this`, `actionEI_callInternalInterface`,
`fireTimerCallback`, the property accessors.

**ABI variants a unified core must handle:**
- type-2 `Function2Ptr(app_context, args, num_args, registers, this_obj)` —
  used by both native builtins and recompiled DefineFunction2;
- type-1 stack-marshalled `simple_func` with the **one canonical cast** living
  in the helper;
- both-pointers-NULL stub constructors (detected today by name at `8269`);
- pointer-identity-special-cased thunks (`builtin_stub_method`,
  `builtin_noop_func`, `builtin_array_method` compared by address at `15034`)
  — the helper must preserve identity checks or accept a pre-dispatch hook.

## 3. The critical constraint: today's inconsistencies are load-bearing

The 96.7% pass rate was achieved **with** these per-site differences. Some
omissions are bugs; others are (accidentally or deliberately) correct — e.g. an
event dispatcher that skips the super push may be matching Flash. Therefore:

> **The unified helper must be able to reproduce each site's current behavior
> exactly, via option flags — migration is behavior-preserving by default.
> Normalization (turning a skipped step on) is a separate, per-site, CI-gated
> decision with a test.**

This is the same "memoize the ladder, don't re-implement it" philosophy as the
interning plan's Stage 1.

## 4. Staged design

### Stage 0 — verify the suspected live bugs (small, immediate value)

For each of §1's four suspects: construct a minimal SWF (MTASC) that reaches
the path with a type-1 function taking ≥2 args (EI internal iface; clip event
handler with params; LC/NS/NC callback closure; version-sensitive behavior in
a timer callback). Outcome per case: *real bug* → fix inline now (small,
independent of consolidation, CI both modes) and keep the test; *unreachable*
→ document why at the site. This pays for the survey even if consolidation
stalls.

#### Stage 0 results (July 4, 2026) — 3 real bugs fixed, 1 suspect stale

Repro method: MTASC emits DefineFunction2 for SWF6+, so all four repros are
hand-assembled SWF bytecode (`create_test_swf.py` per test dir) that provably
contains plain `DefineFunction`. All four live as permanent, fully git-tracked
custom tests in **`ruffle-tests/tests/swfs/regression/`** — a suite
`download_tests.sh` never touches. (They originally sat in
`ruffle-tests/tests/swfs/avm1/` behind per-test `.gitignore` negations; Stage 3
moved them out, since that directory is a wipe-and-re-download mirror of
upstream. See the suite's `README.md`.)

1. **`actionEI_callInternalInterface` type-1 arm — REAL BUG, fixed
   `d8abc5c0a`.** Pushed args in REVERSE (missed by the bcacc3f70 sweep) and
   didn't pad/clamp to `param_count`. Repro output before fix: `a=two b=one`
   (swapped) and a 1-arg call bound the arg to the wrong param. Reachability:
   **native, not just browser** — the `external_interface` ruffle test harness
   (`test_harness.c`) and the browser EI glue both call it. Fix: forward
   order, clamp extras, pad missing with undefined (exactly `param_count`
   values pushed). Test: `ei_type1_args`.
2. **`mc_call_as2_handler_ng` type-1 arm — REAL BUG, fixed `9a8c6dce3`.**
   Pushed NO args ("event handlers are always type 2" was false) — a type-1
   handler with declared params lost the event's real argument and the
   prologue popped stale eval-stack slots. Repro: `onSetFocus(oldFocus)` via
   `Selection.setFocus` traced `old=undefined` instead of `old=null` /
   `old=_level0.t1`. Oracle: Ruffle `call_focus_handler`
   (`core/src/display_object/interactive.rs:640`) passes `[otherFocus]`,
   Null when none. Same forward+clamp+pad fix. Test: `mc_event_type1_args`.
3. **Missing `switchToFunctionVersion` — REAL BUG on the timer path, fixed
   `60070d96a`; other paths deferred to Stage 4.** Repro: v7 host
   `loadMovie`s a v6 child whose `setInterval` callback traces
   `"" + undefined` → printed `undefined` (v7 semantics) instead of `` (v6).
   Bonus symptom: the callback read `_global` from the wrong version-group
   global (legacy vs modern), so its `clearInterval(_global.iid)` no-op'd and
   the timer re-fired ~41×/tick forever. Fix: exported
   `actionSwitchToFunctionVersion`/`actionRestoreFunctionVersion` wrappers
   (action_internal.h) + both `fireTimerCallback` branches switch/restore.
   The event (`mc_call_as2_handler_ng`), EI, and coercion paths still skip
   the version switch — that normalization is Stage 4 work, now with a proven
   failure mode. Test: `timer_cross_swf_version`.
4. **LC/NS/NC captured-scope push — NOT A BUG (survey claim stale).**
   `lc_dispatch_onStatus` / `ns_dispatch_onStatus` / `nc_dispatch_onStatus`
   all restore the handler's captured scope chain in BOTH type-1 and type-2
   arms (verified by reading and behaviorally). A closure over a
   DefineFunction local used as `nc.onStatus` resolves its captured variable
   through `connect(null)`'s Connect.Success dispatch. Behavior-lock test:
   `nc_onstatus_closure` (guards Stage 4 migration of these dispatchers).

**New findings for Stage 4** (same bug class, discovered while verifying):
- The type-1 arms of `fireTimerCallback` (both forms) and of
  `lc/ns/nc_dispatch_onStatus` push args in forward order (correct) but do
  NOT clamp/pad to `param_count` — a type-1 timer callback declaring more
  params than the `setInterval` extra args pops stale eval-stack slots, and
  an onStatus handler declaring 0 params strands the event arg. Fix these
  during Stage 4 migration (or earlier if a game hits them).
- `actionEI_callInternalInterface` pushes the local scope BEFORE the captured
  scopes (every other dispatcher pushes captured first, local on top), so its
  `setVariableByName("this", ...)` lands in the topmost captured WITH scope
  when one exists. Normalize the ordering when migrating to the core helper.
- The `PUSH()` macro in action.h is a naked multi-statement macro (not
  do/while(0)) — an unbraced `else PUSH(...)` compiles but corrupts the
  stack. Worth wrapping when convenient; the new dispatch code braces it.

### Stage 1 — extract the core: `invokeFunctionValue()`

One function in `action.c` (near the existing primitives):

```c
typedef struct InvokeOpts {
    u16 flags;          // INV_THIS_STACK | INV_SUPER_CTX | INV_CAPTURED_SCOPE |
                        // INV_LOCAL_SCOPE | INV_BASE_CLIP | INV_VERSION_SWITCH |
                        // INV_EVENT_THIS_MC | INV_DEPTH_GUARD | ...
    u32 super_depth;    // when INV_SUPER_CTX
} InvokeOpts;

ActionVar invokeFunctionValue(SWFAppContext* app_context, ASFunction* func,
                              ActionVar* this_var, ActionVar* args, u32 num_args,
                              const InvokeOpts* opts);
```

- Contains the **single** type-1 cast, the **single** forward-order+pad
  marshalling loop, the **single** type-2 registers setup, NULL-stub handling,
  and symmetric teardown (scopes, super, version, this-stack) in one place.
- Flags default to "everything on" (the `actionCallMethod`-arm superset — the
  only family that currently does steps 2+3+6+7+8+9 together); migrated sites
  pass reduced flag sets that mirror their current behavior.
- Unit-level validation: temporarily wire ONE low-risk site (e.g.
  `invokeResolveFunction`) and run full CI both modes before any further
  migration.

#### Stage 1 landing note (July 8, 2026)

`invokeFunctionValue(app_context, func, this_var, args, num_args, opts)` added to
`action.c` — forward-declared beside the accessor family (`invokePropertyGetter`),
defined after the version-switch primitives (where `switchToFunctionVersion` /
`pushSuperContext` / `allocObject` / `pushVar` are in scope). It performs the
whole ritual gated by `InvokeOpts.flags`:
`INV_DEPTH_GUARD / THIS_STACK / SUPER_CTX / CAPTURED_SCOPE / LOCAL_SCOPE /
BIND_THIS / BASE_CLIP / VERSION_SWITCH / EVENT_THIS_MC / EXEC_FUNC`, plus two
opt-in legacy-quirk flags (`INV_FORCE_CAPTURED_WITH`, `INV_MC_THIS_NULL_PTR`).
It holds the **single** type-1 cast, the **single** forward-order + pad-to-
`param_count` type-1 marshalling loop, the type-2 register setup, and symmetric
teardown. `opts==NULL` defaults to the "everything reasonable on" superset.

First (and only, this stage) migrated site: `invokeResolveFunction`, now a thin
adapter passing `INV_DEPTH_GUARD | INV_CAPTURED_SCOPE | INV_FORCE_CAPTURED_WITH |
INV_LOCAL_SCOPE | INV_BIND_THIS | INV_BASE_CLIP`. The core normalizes two inert
details vs. the old hand-rolled body (captured-before-local scope order; type-1
arg pad to `param_count`) — neither can affect a `__resolve` body, whose local
scope only ever holds `"this"` and whose one declared param is the name string.
Local: `object_resolve`, `resolve_different_root`, `coerce_to_primitive_resolve`
pass in NO_GRAPHICS; `object_resolve` passes in `--mode=graphics`. Both-mode CI
run: see commit trailer.

### Stage 2 — migrate the accessor family

`invokePropertyGetter` / `invokePropertySetter` / `invokeResolveFunction`
become thin adapters over the core (fixed 0/1-arg shapes, flags matching their
current ritual). These are already funnels with ~30+ callers, so three
rewrites cover a large call population. Key regression suites: the
virtual-property tests (`virtual_property_special_recursion_*`), addProperty
setters (`init_object_order`), `object_resolve`.

#### Stage 2 landing note (July 8, 2026)

All three accessors are now thin adapters (**−181 lines net**). Two new core
flags were required, both discovered by diffing each site's ritual against the
core rather than assuming:

- `INV_RESET_THIS_DEPTH` — the setter *zeroes* `g_this_depth` for the call
  (it does not push `g_this_stack`), isolating nested method calls from the
  outer caller's `this` (the FLVPlayback `contentPath` → `createINCManager` fix).
- `INV_LOCAL_SCOPE_MC` — getter/setter set the local frame's `scope_mc = NULL`
  unconditionally; only `call_function_with_this` associates the receiver MC.
  Now opt-in (and in the `opts==NULL` superset).

The setter's MC-receiver path (`this_obj == NULL && g_event_this_mc != NULL`)
maps exactly onto the existing `INV_MC_THIS_NULL_PTR`: `this_var` carries the
MOVIECLIP tag for the scope binding while `advanced_func` still receives NULL,
so `preload_this` resolves the MC via `g_event_this_mc` — identical to passing
the old NULL `this_obj`.

Arg shapes: getter passes `num_args=0` (a Flash virtual getter takes no
arguments), so the core's type-1 loop pushes exactly `param_count` undefineds —
reproducing the old hand-rolled pad. Setter passes the value with
`num_args = value ? 1 : 0`, so a defensive NULL value pads every declared param
instead of dereferencing NULL.

Verified: `function_type` is always 1 or 2 with the matching pointer non-NULL for
every registered accessor (`addProperty` type-checks its args; builtin transform
accessors use `INIT_TRANSFORM_FUNC` → type 2 + `advanced_func`; every
`simple_func` assignment pairs with `function_type = 1`). So the core's strict
dispatch (which returns undefined instead of calling a NULL pointer) is safe
here, and it adds the NULL-stub handling the getter's old unconditional
`else`-branch lacked.

Local (NO_GRAPHICS): the full virtual-property/watch/resolve cluster + the four
Stage-0 permanent tests + `add_property`, `transform`, `color_transform`,
`matrix`, `color`, `bitmap_filters`, `as_transformed_flag` all hold baseline.
`watch_virtual_property` is `output_mismatch` **in the pre-existing CI baseline at
`c23831e4ba`**, not a Stage-2 regression. Graphics: `transform`,
`color_transform`, `matrix`, `bitmap_filters`, `init_object_order`,
`object_resolve`, `virtual_property_special_recursion_swf7` pass.

### Stage 3 — the mega-dispatchers, one arm at a time

`actionCallMethod`'s ~14 arms, then `actionCallFunction`, `actionNewObject`,
`actionNewMethod`, `invokeNativeSuperConstructor`. Rules:
- One arm (or small coherent group) per commit; full CI both modes per batch.
- Preserve pointer-identity special cases by checking **before** calling the
  core (they are dispatch decisions, not invocation steps).
- The super arms carry `INV_SUPER_CTX` + explicit depth — this centralizes the
  depth formulas' *application* (not their computation).
- Key suites: `as2_super_and_this_*`, `super_edge_cases`, `extends_chain`,
  `register_and_init_order`, `swf5_no_closure`, `swf5_to_6_cross_call`.

#### Stage 3 progress note (July 9, 2026) — 5 of ~19 arms migrated

Landed, each CI-green in **both** modes with every suite's delta at 0:

| Commit | Arms |
|---|---|
| `e4082f224` (3a) | `actionCallMethod`'s four **super** arms: the `arguments`-array `super()` proxy, the `arguments`-array `super.method()` proxy, and the two arms under the `SUPER`-typed receiver |
| `65d442f09` (3b) | the `.call`/`.apply`-via-`GetMember` arm (`g_getmember_call_target`) — **plus a real bug**, below |

**No new core flags were needed.** The existing set covered every arm, but only
because three ritual steps were deliberately left *outside* the core:

- `setVariableByName("this", ...)` — these arms bind `this` into the **enclosing**
  scope, not a fresh local frame, so `INV_LOCAL_SCOPE | INV_BIND_THIS` would not
  reproduce them.
- the bare `g_call_depth++/--` — `INV_DEPTH_GUARD` also adds a
  `g_max_call_depth` halt check that these arms never had.
- `g_current_executing_func` / `g_call_this_type` in the `.call` arm —
  `INV_EXEC_FUNC` additionally writes `g_prev_executing_func`, which that arm
  never did.

The arms' flag sets genuinely differ from one another and that asymmetry is
load-bearing (§3): e.g. the `arguments`-array `super()` proxy's type-1 branch
binds `this` to the super **object** even when a registerClass companion MC
exists, while the `SUPER`-receiver arms bind it to the **MC**. Reproduced, not
normalized. Type-2 arms with a companion MC map exactly onto
`INV_EVENT_THIS_MC | INV_MC_THIS_NULL_PTR`.

**Bug found and fixed (3b):** the `.call`/`.apply`-via-`GetMember` arm's type-1
branch pushed args in **reverse** order and never padded to `param_count`.
`f.call(null,"one","two")` on a plain `DefineFunction` bound `a="two", b="one"`;
the 1-arg form bound `a=undefined, b="only"` while the callee's prologue popped a
value off the **caller's** eval stack. A seventh instance of the class
`bcacc3f70` fixed in six dispatchers and Stage 0 fixed in
`actionEI_callInternalInterface` — it survived both sweeps. The core's single
forward+clamp+pad loop fixes it for free. Regression test:
`regression/fn_call_type1_args`.

Safety audit that made the pad/clamp adoption safe here: `param_count` is
accurate for **every** type-1 function reachable from these arms — recompiled
`DefineFunction` bodies pop exactly `param_count` (`action.c:56928`), and the
only five natives with a real `simple_func` are `toString`-shaped with
`param_count = 0` and no args. Separately, the `registers` parameter of a
recompiled `DefineFunction2` is **never read** (the generated body declares its
own local `regs[]`), so the core's `HCALLOC(register_count)`-or-NULL is safe
where arms previously passed a zeroed `ActionVar registers[256]` stack array.

**Perf gate: passed, but not via N.** `invokeFunctionValue` is *never executed*
in N — N's 691 script functions are 100% type-1 `DefineFunction`, it has zero
`DefineFunction2`, and it reaches none of the migrated arms (0 mentions in
`callgrind.out`). N is therefore a vacuous oracle for this stage. Worse, the
harness has **~13% run-to-run Ir variance on N with the identical binary**
(5,755,417,982 vs 6,506,572,041 on two `--run-only` invocations), so it cannot
resolve a small delta anyway — do not trust a single-run before/after on N.
Measured on **Minesweeper** instead, which does reach the `super.method()` arm:
`invokeFunctionValue` self cost is **12,117 Ir of 641,978,548 = 0.0019%**. No
`static inline` needed.

**Remaining ~14 arms need new core capability, not just new flags.** The object
/ MC / array / `__resolve` / `.call`-handler arms each perform steps the core has
no notion of. Design these before continuing:
- **`arguments` object construction** + `setupArgumentsProps` (respecting the
  DefineFunction2 preload/suppress flags) — the `.call`/`.apply` handlers and the
  object-method arm.
- **Closure-context switch**: save/clear/restore the *whole* scope chain
  (`scope_depth = 0`), `reResolveDeadBaseClip` + `actionSetCurrentContext` +
  `g_current_sprite_obj`, gated on `caller_ver >= 6`. This is the
  `actionCallFunction` shape; the empty-method-name arm shares it verbatim.
- **`pushCtorContext` / `popCtorContext`**, `g_override_this` /
  `g_override_this_set`, `g_c_function_this_obj`, and binding `"super"` as a
  named local.

**New Stage-4 leads (same bug class, outside Stage 3's scope):** two reverse-order
type-1 arg pushes remain — `lc_dispatch_method` (`action.c:2908`, LocalConnection
method dispatch) and `bdRectangleGetter` (`action.c:14365`, which pushes four
fixed `Rectangle` ctor args in reverse). Both also skip the `param_count`
clamp/pad.

#### Stage 3c design note (July 9, 2026) — the shape for the remaining ~14 arms

Written before any Stage-3c edit, per the "design first, don't calcify the wrong
abstraction into 14 call sites" rule. Survey basis: `actionCallFunction`
(`57832`–`60234`), the empty-method-name arm (`64044`–`64200`), the object-method
arms (`64565`–`64752`), the `__resolve` arm (`64764`+), the `.call`/`.apply`
builtin handlers (`65549`–`65733`), the array and string-primitive arms.

##### What actually varies (and what doesn't)

Three ritual steps recur with *genuinely different structure*, not different
booleans:

1. **The callee's named locals** — `this`, `arguments`, `super` bound on the
   fresh local-scope object, each gated by the callee's DefineFunction2
   preload/suppress bits. Needs `local_scope`, which only the core has.
2. **The closure frame** — save the *whole* scope chain, `scope_depth = 0`,
   `reResolveDeadBaseClip` + `actionSetCurrentContext` + `g_current_sprite_obj`,
   all gated on the **caller's** SWF version. Needs ~544 B of `MAX_SCOPE_DEPTH`
   save arrays.
3. **Constructor context** — `pushCtorContext(0)` / `popCtorContext` and
   `g_override_this` / `g_override_this_set` around the callee body.

##### The shape: one new core capability, one new *primitive beside* the core

Capability 1 goes **into** the core (it needs `local_scope`). Capability 2 goes
**beside** it as an arm-owned enter/leave pair. Capability 3 splits: the parts
that must straddle the callee body go into the core; the parts that are merely
*set immediately around it* stay outside.

```c
// (A) The caller-side frame a callee runs in. Storage is owned by the dispatch
//     ARM (its own stack), entered before invokeFunctionValue and left after.
typedef enum { CF_CTX_ONLY, CF_FULL } ClosureFrameMode;
typedef struct ClosureFrame {
    u32 saved_scope_depth;
    ASObject*  saved_chain[MAX_SCOPE_DEPTH];
    u8         saved_is_with[MAX_SCOPE_DEPTH];
    MovieClip* saved_mc[MAX_SCOPE_DEPTH];
    MovieClip* saved_ctx;
    DisplayObject* saved_sprite;
    u8 mode, active;
} ClosureFrame;
static void enterClosureFrame(SWFAppContext*, ClosureFrame*, ASFunction*,
                              ClosureFrameMode, int caller_ver);
static void leaveClosureFrame(SWFAppContext*, ClosureFrame*);

// (B) InvokeOpts grows: `flags` widened u16 -> u32, plus four fields. All new
//     fields are zero-default, so the five migrated sites are untouched.
typedef struct InvokeOpts {
    u32 flags;                 // + INV_CTOR_CTX
    u16 super_depth;
    u8  act_flags;             // INV_ACT_THIS | INV_ACT_ARGUMENTS | INV_ACT_SUPER
    u8  has_this_ptr;
    ActionVar* override_this;  // non-NULL -> g_override_this{,_set} for the call
    void* this_ptr;            // ABI receiver override (decoupled from this_var)
} InvokeOpts;
```

**Why `ClosureFrame` is arm-owned and not a core flag.** `MAX_SCOPE_DEPTH` is 32,
so the frame is 32×(8+1+8) + 16 ≈ 544 B. `g_max_call_depth` is 256. If the core
declared it unconditionally, every accessor invocation would carry it — up to
139 KB of C stack on a deep getter recursion, against a 64 KB emscripten stack
(memory `wasm-stack-overflow-64kb`), and the `virtual_property_recursion_*` tests
go deep on purpose. Only the two closure-shaped arms need it, and
`actionCallFunction` already pays exactly this cost on its own frame today — so
arm-owned storage is byte-for-byte neutral there and free everywhere else.

**Why the frame also fixes a latent gate bug.** The core's `INV_BASE_CLIP` reads
`g_swf_version >= 6` *after* `INV_VERSION_SWITCH` has already installed the
callee's version — i.e. it gates on the **callee's** version, while every real
arm gates on the **caller's**. No migrated site sets both flags (verified: all
eight `invokeFunctionValue` call sites pass explicit opts; the `opts==NULL`
superset that combines them is dead code), so this is latent, not live.
`enterClosureFrame` takes `caller_ver` explicitly and owns the context switch, so
the closure arms never touch `INV_BASE_CLIP`. Leave the flag's gate alone;
`gates/check_dispatch_funnel.py` (Stage 5) should reject any site that sets both.

##### Per-type rule table for `act_flags` (encoded inside the core)

`arguments` and `super` have no meaning for a type-1 body's flags word (type-1
has none), so the core interprets `act_flags` per `function_type`:

| `act_flags` bit | type 2 (DefineFunction2) | type 1 (DefineFunction) |
|---|---|---|
| `INV_ACT_THIS` | if `!preload_this && !suppress_this`: `setProperty(local,"this")` **and** push `g_this_stack` | push `g_this_stack` only (no scope binding) |
| `INV_ACT_ARGUMENTS` | if `!preload_args && !suppress_args`: `allocArray(n)` + `setupArgumentsProps` + `setProperty(local,"arguments")` | unconditional; `allocArray(max(n,1))` |
| `INV_ACT_SUPER` | always `setProperty(local,"super", …)`; value is `SUPER` when `!preload_super && !suppress_super && hasSuperContext()`, else undefined | no-op |

That table is read directly off `actionCallFunction` type-2 (`59924`–`59979`) and
type-1 (`60044`–`60071`), and off the object-method arm (`64597`–`64651`). The
`allocArray(n)` vs `allocArray(max(n,1))` split is preserved rather than
normalized — capacity only, but Stage 3 is behavior-preserving.

**Ordering hazard the core must own.** `setupArgumentsProps(…, caller_func)`
supplies `arguments.caller`. The core already captures
`prev_exec = g_current_executing_func` *before* `INV_EXEC_FUNC` overwrites it; the
activation builder must take that value as a parameter, never re-read the global.
Corollary: **an arm that wants `INV_ACT_ARGUMENTS` must let the core own the
exec-func swap** (`INV_EXEC_FUNC`) rather than doing it outside as 3b's `.call`
arm does — otherwise `arguments.caller` silently becomes the callee itself.

##### What deliberately stays OUTSIDE the core

Extending 3a/3b's judgement, with a reason for each rather than an assumption:

- **`g_c_function_this_obj`** (object-method type-2 arm, string-primitive arm).
  Read *only* from inside builtin bodies (`33494`, `33560`, `33602`, `34089`),
  never by a ritual step — so setting and restoring it around the core call is
  exactly equivalent to doing it inside, and it would cost a flag plus a value
  field for two sites.
- **`g_call_this_type`** — same argument; precedent set by 3b.
- **`g_call_depth++/--` bare** — `actionCallFunction` pre-checks
  `>= g_max_call_depth - 1`, halts, and pushes undefined itself.
  `INV_DEPTH_GUARD` would double-increment and uses a different bound.
- **`setVariableByName("this", …)`** — the 3a/3b arms bind into the *enclosing*
  scope, not a fresh local frame.
- **The `simple_func == NULL` converter branch** of `actionCallFunction` type-1
  (`Number` / `Boolean` / `String` called without `new`, `60109`–`60186`). That
  is a *dispatch decision*, like the `builtin_stub_method` /
  `builtin_noop_func` / `builtin_array_method` pointer-identity checks: it must
  be taken before the core is entered.

##### Migration order (one commit per step, full CI both modes per step)

1. **`actionCallFunction`, both branches.** Biggest single win; exercises all
   three capabilities at once and is the shape everything else reduces to.
2. **`actionCallMethod`'s empty-method-name arm.** Falls out of step 1: same
   `CF_FULL` frame, `act_flags = 0`, `override_this = undefined`,
   `INV_CTOR_CTX`. Note it gates the *entire* frame — captured scopes and local
   scope included — on `caller_ver >= 6`, so its SWF5 path passes neither
   `INV_CAPTURED_SCOPE` nor `INV_LOCAL_SCOPE`. The arm picks its flag set after
   reading `func->function_type`; the core stays version-agnostic.
3. **The object-method arms** (`om2`/`om1`): `CF_CTX_ONLY` frame,
   `act_flags = THIS|ARGUMENTS|SUPER` (type 2) / `ARGUMENTS` (type 1),
   `INV_SUPER_CTX` with `method_search_depth`, `INV_VERSION_SWITCH`.
4. **The `.call`/`.apply` builtin handlers**: `INV_FORCE_CAPTURED_WITH` (they
   force `is_with = 1` on captured scopes), `INV_ACT_ARGUMENTS` on the type-1
   branch only — the type-2 branch builds no `arguments` object today.
5. `__resolve` arm, array arm, string-primitive arm, MC arm.

##### Latent bugs this design will fix for free (same class, all unverified)

Found by diffing each arm's type-1 marshalling against the core's single
forward+clamp+pad loop. None is fixed speculatively; each falls out of its arm's
migration and wants a `regression/` test at that point:

- **empty-method-name arm** (`64150`): pushes `num_args` values, no clamp, no pad.
- **object-method type-1 arm** (`64719`): pushes `num_args` values, no clamp, no pad.
- **`.call`/`.apply` type-1 handler** (`65659`): pads to `param_count` but never
  **clamps** — extra args leak onto the caller's eval stack.

### Stage 4 — event/callback dispatchers + deliberate normalization

`mc_call_as2_handler_ng`, `fireTimerCallback`, `builtin_broadcaster_broadcastMessage`,
`fireMCLEvent`, `fireLoadVarsCallback`, `soundFireCallback`, LC/NS/NC
dispatchers, `actionEI_callInternalInterface`, `call_function_with_this`,
watch arms in `actionSetVariable`/`actionSetMember`, `_invoke_sort_comparator`,
coercion paths (`objectCallValueOf`/`ToString`/`toPrimitive`, `convertFloat`).
Two passes each: (a) behavior-preserving migration; (b) a **normalization
review** — should this path get version-switch / captured-scope / this-stack?
Each "yes" is its own commit with a targeted test (this is where §1's items 3
and 4 get properly fixed rather than patched).

### Stage 5 — lock it in

- Delete the then-dead 32 marshalling loops and per-site casts.
- Add a gate script (`gates/check_dispatch_funnel.py`, following the existing
  `gates/` pattern) that greps for raw `simple_func`/`advanced_func` calls
  outside `invokeFunctionValue` + an allowlist — new dispatchers must use the
  funnel or consciously register an exemption.

## 5. Verification protocol

- **Full CI, both modes, per stage** (shared runtime code). The suites are the
  behavior lock; zero pass→fail is the bar for behavior-preserving stages.
- Stage-0 tests become permanent regression tests.
- Watch the known-sensitive clusters per stage (listed inline above).
- Perf sanity: the helper adds one call frame + flag checks on hot call paths.
  **Do not use N for this** — it never executes `invokeFunctionValue` (100%
  type-1 functions, no `DefineFunction2`, reaches none of the migrated arms),
  and `profile_game_native.sh` shows ~13% run-to-run Ir variance on N with the
  *identical binary*, so a single before/after pair there is meaningless. Use
  **Minesweeper** (reaches the `super.method()` arm) and read the core's own
  `Ir` line out of `callgrind_annotate --threshold=100`, rather than comparing
  PROGRAM TOTALS across builds. Measured July 9, 2026: 0.0019% of total. Inline
  the core (`static inline` + always_inline) only if that share becomes material.

## 6. Risks

| Risk | Mitigation |
|---|---|
| A migrated site behaves differently despite matching flags | One-arm-per-commit granularity; both-modes CI per batch; instant bisect |
| Flags reproduce a bug we should have fixed (calcified inconsistency) | Stage 4's explicit normalization pass — skipping a step is a recorded decision, not an accident |
| Helper call overhead on hot paths | Measure at Stage 3; `static inline` fallback |
| Pointer-identity special cases silently lost | Identity checks stay at dispatch sites, before the core |
| 75K-line churn conflicts with other work (interning plan touches nearby code) | Sequence: dispatch Stages 0–2 are disjoint from interning Stage 1 (GetMember ladders); coordinate Stage 3 with interning Stage 2 since both touch `actionCallMethod`-adjacent paths |

## 7. When to execute

Stage 0 is small and worth doing soon — it either fixes real user-facing bugs
(EI, event-handler args) or documents safety. Stages 1–2 fit one focused
session; Stage 3 is the long tail and can proceed opportunistically arm-by-arm
between other work, since every step is independently shippable. Unlike the
interning plan there is no profiling gate — the payoff is bug-class
elimination, and it compounds with every future dispatcher we'd otherwise
hand-roll.
