# Function-Dispatch Consolidation — Plan

**Created:** July 4, 2026
**Status:** Planned, not started.
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

### Stage 2 — migrate the accessor family

`invokePropertyGetter` / `invokePropertySetter` / `invokeResolveFunction`
become thin adapters over the core (fixed 0/1-arg shapes, flags matching their
current ritual). These are already funnels with ~30+ callers, so three
rewrites cover a large call population. Key regression suites: the
virtual-property tests (`virtual_property_special_recursion_*`), addProperty
setters (`init_object_order`), `object_resolve`.

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
- Perf sanity: the helper adds one call frame + flag checks on hot call paths
  — run `profile_game_native.sh` on N before/after Stage 3 to confirm no
  measurable regression (expect noise-level; if not, inline the core with
  `static inline` + always_inline).

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
