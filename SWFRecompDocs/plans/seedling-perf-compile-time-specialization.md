# Seedling perf — Phase: compile-time type specialization (the recompiler's real lever)

**Status:** PLANNED (2026-07-14). Launch point for a fresh session. The prior arc
(runtime resolver hashing + inline caches) reached **parity with Ruffle (~47 ms
ours / ~46 ms Ruffle)** and plateaued there — the last IC extension bought ~2%
(noise-floor). See [[seedling-perf-hotpath-is-property-lookup]] for that arc.

## Why this phase exists (the reframe)

**Matching Ruffle is insufficient.** The project exists because Ruffle can't run
Seedling at its intended frame rate. Target = **30 fps = 33.3 ms/frame**; we are at
**~47 ms**. We need to cut **~14 ms (~30%)**, not the ~1 ms an incremental IC buys.

Everything shipped so far (vtable hash, domain hash, getproperty/callproperty/
setproperty inline caches, lazy class-name) makes **runtime name resolution
faster** — an *interpreter-style* optimization. It's what Ruffle already does; we
just do it faster. That is exactly why it plateaus at parity.

**The project thesis — "recompile beats interpret" — only cashes out in the one
thing an interpreter cannot do: resolve at COMPILE time.** AS3 is statically
typed; the ABC verifier already knows the receiver's static type at a large
fraction of property/coerce sites. That is the untapped lever.

## Evidence — the frame budget (real-GPU CDP self-time, `prof_callset_ic.json`, ~47 ms; 1% ≈ 0.47 ms)

| bucket | % | ~ms | note |
|---|---|---|---|
| **A. name resolution / property lookup** | **46.7%** | **~21.9** | dominant; NOT irreducible for a recompiler |
| B. call/dispatch/setprop machinery | 10.0% | ~4.7 | partly compile-time-eliminable |
| C. type coercion / conversion | 9.7% | ~4.5 | much is statically redundant |
| G. other runtime (memcmp, misc) | 9.9% | ~4.6 | mostly feeds A (name compares) |
| idle / program / gc | 8.5% | ~4.0 | INVESTIGATE FIRST — throttle vs stall? |
| E. recompiled game method bodies | 8.3% | ~3.9 | actual game logic — ~irreducible |
| D. blit / render | 4.5% | ~2.1 | small (blit itself is cheap) |
| F. mem / alloc / gc | 2.4% | ~1.1 | small |

Fattest single items: `resolved_get` 8.5% + `getproperty_static_ic` 7.6% (~7.6 ms)
— the "property READ even after the IC hit." Irreducible for an interpreter;
**for us, when the receiver type is a sealed class and the property is a slot
trait, the slot index is a compile-time constant** → emit `recv.u.obj->slots[N]`
directly (no name, no vtable fetch, no IC check, no `resolved_get` switch).

**Target of the specialization pass: buckets A (~22 ms) + C (~4.5 ms) ≈ 56% of the
frame** — where Ruffle structurally cannot follow.

## Plan (de-risk before building)

**Step 0 (do FIRST, cheap): understand the 8.5% idle.** If part of it is rAF /
present pacing (throttle), our true compute budget is < 47 ms and the arithmetic
shifts. Confirm with `iv_perf.py` (delivered period `S.iv`) vs busy-time, and a
CDP trace of where the idle sits (between frames = pacing; mid-frame = stall/GC).

**Step 1 (read-only SCOUT — the green-light gate): static-type coverage.**
Instrument the emitter/verifier: at each `GetPropertyStatic`/`SetPropertyStatic`/
`CallProperty` site, how many have a statically-known receiver type that is a
sealed class with the accessed name resolving to a **slot** trait (not getter/
setter/method, not dynamic, not interface)? Weight by the profile's hot methods
(a few like `abc0_m676` dominate — coverage may concentrate nicely). Output: the
addressable fraction of the ~22 ms. This gate decides whether to build the pass.

**Step 2 (PROTOTYPE on the hottest method(s)):** thread the verifier's static
receiver type into the IR; emit direct slot access where provably safe. Keep the
null-receiver check (still throws). Measure a real interleaved before/after A/B
(same rig as the prior arc). Confirm byte-identical + no avm2 CI regression.

**Step 3 (generalize):** proper emitter pass for slot binding; then coercion
elision (bucket C — elide `coerce_*` the verifier proves redundant); then
monomorphic call devirtualization (bake the method pointer).

## Correctness landmines (why this is bigger than an IC)

Exclude / handle correctly: dynamic (non-sealed) classes; overridden methods;
getter/setter traits (not direct slots); interface-typed receivers; null/undefined
receivers (must still throw 1009/1010); `*`/Object static type (no info);
Vector/Array index access; proto-chain dynamics. The ABC verifier already computes
most of this (it's why Ruffle has slot fast paths) — the work is tracking static
receiver type through the IR and gating emission on provable safety.

## Where the code lives (fresh-session ramp-up)

- Recompiler emitter: `SWFRecomp/src/abc/abc_emit.cpp` (emit templates; where the
  IC `static Avm2InlineCache` blocks are emitted today — the specialization would
  replace the generic `avm2_op_*` call with a direct slot expr at eligible sites).
- IR + verifier: `SWFRecomp/src/abc/` (`abc_ir.*`, verifier/type-tracking).
- Runtime slot layout (what a compile-time slot index must match):
  `SWFModernRuntime/src/avm2/avm2_ops.c` `resolved_get`/`setproperty_resolved`
  (`AVM2_PROP_SLOT` → `recv.u.obj->slots[e->slot_index]`), `avm2_class.c` vtable/
  slot assignment. **The compile-time slot index MUST equal the runtime
  `e->slot_index`** — verify the recompiler's trait-slot numbering matches the
  runtime's vtable slot assignment exactly, or bake an indirection.
- Perf rig (measurement): `tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`,
  `SEEDLING_AB_STATUS.md`; scripts on `C:\playwright\` (`seedling_perf.py`,
  `cdp.py`, `iv_perf.py`). Interleave before/after; ±10% noise.
- Build/measure loop (EMITTER change — CI re-runs recompiler): rebuild
  `SWFRecomp/build`, re-recompile Seedling (`SWFRecomp/build/SWFRecomp config.toml`
  in `~/CC/seedling_teleport_build/recompiled/`), `build_wasm_avm2.sh seedling` +
  `deploy_wasm_avm2.sh seedling` with `EMCC_CFLAGS=--profiling-funcs`. Correctness:
  `gh workflow run ruffle-tests.yml --ref master -f mode=no-graphics` (avm2 must
  hold 829→829). Full pipeline per `.claude/pipeline-handoff.md`.

## Suggested fresh-session launch prompt

> Continue the Seedling perf arc — new phase: compile-time type specialization in
> the recompiler. READ FIRST: SWFRecompDocs/plans/seedling-perf-compile-time-
> specialization.md and memory [[seedling-perf-compile-time-specialization]] +
> [[seedling-perf-hotpath-is-property-lookup]]. Do Step 0 (understand the 8.5%
> idle) then Step 1 (the read-only static-type coverage scout) and report numbers
> before building anything.
