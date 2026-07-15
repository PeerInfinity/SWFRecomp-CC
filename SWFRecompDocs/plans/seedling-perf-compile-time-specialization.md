# Seedling perf — Phase: compile-time type specialization (the recompiler's real lever)

**Status:** Step 0/1 DONE (gate GREEN). **Step 2 DONE 2026-07-14 — this.field
slot specialization shipped: ~3-4 ms / 7-9% real-GPU win, the first gain past the
IC plateau; full-suite verify-mode CI proves it byte-identical + slot-correct.**
**Step 3 is the next launch point** (the two LARGER get levers — see below). The
prior arc (runtime resolver hashing + inline caches) reached parity with Ruffle
(~47 ms) and plateaued; Step 2 took Seedling to **~43.6 ms**. See
[[seedling-perf-hotpath-is-property-lookup]] for the IC arc,
[[seedling-perf-compile-time-specialization]] for this one.

## Step 2 DONE (2026-07-14) — `this.field` slot specialization

Recompiler emits a bare `recv.u.obj->slots[K]` load for `GetPropertyStatic` sites
proven to be `this.field` on a SLOT/CONST trait — skips the IC call + vtable
identity + count guard + `resolved_get` dispatch even an IC HIT pays. **5039 sites
in Seedling.** Real-GPU interleaved A/B (Intel Gen9): after **43.6 ms** vs before
46.6 ms = **3.0 ms (6.4%); 4.0 ms (8.6%) ex-outlier** — 3/4 rounds a clean
3.3-5.0 ms, first change past the ±10% noise floor since the IC plateau.
- Code: `abc_emit.cpp` `AbcTypeModel` + `analyzeSlotSpec` (is_this provenance bit,
  stack-only so no branch merge leaks it); runtime `avm2_op_getproperty_slot`
  (avm2_ops.h/.c). K mirrors `avm2_class.c` numbering exactly (`inheritedBase`
  seed + sequential auto-assign, honoring explicit `slot_or_disp_id`).
- **Sound gate:** `this` (local0 never written) + sealed class + full ABC chain to
  Object + name UNIQUE in chain + NO subclass redeclares the name
  (`subclassRedeclares`, the descendant check — the verify build caught the
  sub/super same-field bug that motivated it).
- **Validation infra (reuse for Step 3):** `-DAVM2_SLOT_VERIFY` (avm2_ops.c) makes
  every specialized read cross-check its compile-time index vs the runtime resolve
  and abort on mismatch; `verify_output.py` reads `SWFRECOMP_EXTRA_DEFINES`; CI has
  an `extra_defines` input. Full-suite verify-mode CI (commit a3767a79a): **avm2
  829 held, matched 102,546 = byte-identical baseline, zero mismatches.**
- Commits: `ab236e611` (impl), `fe1b9e062` (subclass fix), `a3767a79a` (CI input).
- A/B rig: `SWF_NO_SLOT_SPEC=1` env recompiles the IC-only baseline; build both
  with `EMCC_CFLAGS=--profiling-funcs` as `seedling` / `seedling_before`, deploy,
  interleave via `tools/divergence/perf/ab_interleave.sh` (in scratchpad — copy
  into perf/ if reused). Windows rig per [[windows-playwright-from-wsl]].

## Step 3 lever A DONE (2026-07-14) — getlex-global domain inline cache (~4 ms / ~11%)

The FindProperty/FindPropStrict domain resolution is now per-call-site inline-
cached. `getlex ClassName`/`getlex FP` is emitted as `FindPropStrict(mn) +
GetPropertyStatic(mn)`; the FindPropStrict cost is the scope walk + the
`avm2_domain_find`. The new `avm2_op_findpropstrict_ic` (avm2_ops.c) **always
re-runs the scope walk** (exact semantics; scope varies per activation) but
**caches the DOMAIN hit keyed on ctx identity** — sound because the domain is
append-only with stable object identity and `avm2_domain_find` returns the
first match, so a non-NULL hit is permanently valid for a ctx. When the method
is **with-free** (`scope_stable`, recompiler-proved: no PushWith ⟹ every scope
lookup is trait/vtable-based ⟹ the scope-walk hit/miss is invariant across
activations at a fixed site), a populated domain cache also **skips the scope
walk** — the largest saving. Only domain hits are cached; a scope hit or the
dynamic global-proto fallback always takes the slow path.

- **18,419 cached find sites in Seedling, ALL strict + scope_stable** (FlashPunk
  is with-free) — far broader than Step-2's 5,039 slot sites.
- **Real-GPU interleaved A/B (Intel Gen9, 6 rounds, `seedling` vs
  `seedling_before` built `SWF_NO_FIND_IC=1`): 34.4 ms after vs ~39 ms before =
  ~4-4.5 ms (~11%)** (all-6 median 4.6 ms/11.7%; settled r3-6 mean 4.1 ms/10.5%;
  all-6 mean 7.5 ms/17.8% incl. baseline warmup drift). The IC side is
  rock-stable **34.4 ± 0.29 ms** every round; noise is all on the un-cached
  baseline. Cumulative arc: ~47 → Step-2 ~43.6 → **~34.4 ms ≈ 29 fps**,
  essentially the 30 fps / 33.3 ms target.
- **Code:** runtime `avm2_op_findpropstrict_ic` + `Avm2FindCache`
  (avm2_ops.c/.h); `findproperty_impl` split into `findproperty_scope_walk` /
  `findproperty_domain_find` / `findproperty_global_proto` / `findproperty_resolve`
  helpers shared with the plain op. Recompiler `abc_emit.cpp`: emits the ic form
  (block-scoped `static Avm2FindCache __fc`) for all static-multiname
  FindProperty/FindPropStrict; `BodyCtx.scope_stable` = no PushWith;
  `SWF_NO_FIND_IC=1` A/B toggle.
- **Validation infra (reuse for lever B):** `-DAVM2_FIND_VERIFY` (avm2_ops.c)
  cross-checks every ic return against the full uncached `findproperty_resolve`
  and aborts on mismatch; `verify_output.py`/CI take `SWFRECOMP_EXTRA_DEFINES` /
  `extra_defines`. **Full-suite verify CI (run 29374729764,
  `-DAVM2_FIND_VERIFY`): avm2 829 held, 102,546 lines matched, ZERO mismatch
  aborts — the IC + scope-skip is sound across the whole suite.** Normal
  no-graphics CI (run 29374737324): avm2 829→829, mismatched 47323→47323
  (byte-identical, zero pass→fail). Commit `dad415990`.

## Step 3 lever B DONE (2026-07-14) — class-static slot (~2-3 ms / ~6-8%)

The getlex result (a compile-time-known Class object) now feeds a direct
static-slot read: `FP.staticField` on a getlex-known class emits
`avm2_op_getproperty_slot(classobj, K)`. **Recompiler-only** — reuses the
Step-2 runtime op + `-DAVM2_SLOT_VERIFY` (the verify path's `resolve_mn`
resolves the class object's static traits off its cvt, cross-checking K
exactly). `analyzeSlotSpec` is now a unified forward abstract-interp tagging
each operand-stack slot `{is_this, fp_mn, cls}`: `GetLocal 0`→is_this (lever A),
`FindPropStrict(mn)`→fp_mn, `GetPropertyStatic(mn)` on an fp_mn==mn slot naming a
UNIQUE user class → tags the result `cls=C` (the getlex read itself is NOT
specialized), and `GetPropertyStatic(static)` on a `cls=C` slot → static-slot
read. `computeStaticSlotIndex` mirrors the runtime cvt (avm2_class.c ~1025): a
FRESH vtable from slot_count 0 (statics NOT inherited, no super seed) over the
class's own static traits, honoring explicit slot_or_disp_id; emits only for
Slot/Const (uniqueness-guarded). Class object is a singleton, statics aren't
inherited/overridden → the index is exact, no subclass concern.

- **1,432 class-static sites in Seedling** (this-field held at 5,039, proving the
  unified refactor preserved lever A). `SWF_NO_STATIC_SLOT` disables lever B only.
- **Real-GPU A/B (Intel Gen9, 6 rounds, both-levers vs `SWF_NO_STATIC_SLOT`):
  32.6 ms after vs ~35.5 before = ~2-3 ms (~6-8%)** (median 2.9/8.2%; drop-max
  mean 2.5/7.2%; all-6 mean 2.2/6.1%). Noisier run (both sides ~2.5 ms stdev) —
  a near-noise-floor but real win, consistent with 1,432 sites vs lever A's
  18,419. Render byte-identical. **Cumulative: ~47 → Step-2 ~43.6 → lever A
  ~34.4 → lever B ~32.6 ms ≈ 30-31 fps — PAST the 30 fps / 33.3 ms target.**
- Validation: full-suite `-DAVM2_SLOT_VERIFY` CI (covers BOTH this-field +
  class-static): <FILL after CI>.
- **NEXT (Step 4 tail):** coercion elision (bucket C ~4.5 ms — elide the
  `coerce_*` the verifier proves redundant); then monomorphic devirtualization
  (needs CHA — FlashPunk methods aren't `final`).

## Step 3 plan (as executed)

Step-1 scout weights (of GET execution, the dominant property op ~15.7% of frame):
this-slot ~23% (DONE), **getlex-global ~32%**, **class-static slot ~22%**. Step 2
took the smallest of the three; Step 3 is the bigger two, which compose.

**Lever A — getlex-global domain IC (~32%, the single biggest).** `getlex FP` /
`getlex ClassName` is emitted as `FindPropStrict(mn) + GetPropertyStatic(mn)`; the
cost is the FindPropStrict **`avm2_domain_find`** scan (avm2_ops.c
`avm2_op_findproperty` / `avm2_op_finddef` at line 1710/1852). For a definitely-
defined global class/singleton the resolved definition object is STABLE (the
domain is append-only, the class defined once) → add a **per-call-site domain
inline cache**: cache the resolved def object keyed on domain/ctx identity, replay
on hit, skip the scan. This is the "different-shape" IC the IC arc flagged. Same
`Avm2InlineCache`-style pattern; AVM2-only → simple no-graphics CI. Recompiler:
detect `FindPropStrict`+`GetPropertyStatic` of the same static QName (the getlex
pattern the verifier already produces) and emit a cached finddef.

**Lever B — class-static slot (~22%).** After lever A resolves the Class object,
`FP.staticField` reads a STATIC slot off it. Class (static) traits carry EXPLICIT
`slot_or_disp_id` (unlike instance auto-assign — I saw 1,2,3… in abc0_tables.c), so
the compile-time index is trivial and exact. Extend `AbcTypeModel` to a CLASSOBJ
receiver: when the receiver is a compile-time-known Class (the getlex result, i.e.
the `recv_classobj` case the Step-1 scout counts), and the accessed name is a
static slot trait, emit `classobj->slots[K]`. Reuse the `avm2_op_getproperty_slot`
runtime op + `-DAVM2_SLOT_VERIFY` validation as-is. Landmine: the class-object
vtable (`cvt`, avm2_class.c ~line 1027) numbers static slots per-class fresh — mirror
that (simpler than instance: explicit ids, no inheritance seed for statics).

**Do lever A first** (bigger, self-contained), measure A/B, then B (composes on
A's cached class object). Coercion elision (bucket C ~4.5 ms) is the Step-4 tail.

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

## Step 0 FINDINGS (2026-07-14) — the ~8.5% idle is NOT recoverable headroom

Analyzed the real-GPU CDP profiles (`prof_callset_ic.json`, `prof_approachA.json`,
current 47 ms state) with a run-length breakdown of the `(idle)` node:
- **idle 6.3%, program 2.5%, gc 0.1%** (≈ the plan's ~8.5% bucket). **GC is
  negligible** — not a mid-frame collector stall.
- Idle sits in **one contiguous ~3.3 ms run per frame** (median 3324 µs, 91–93%
  of idle time is in runs > 2 ms, **0% in sub-0.5 ms mid-frame gaps**, max ~7–13 ms).
  ~444 idle runs over ~22 s ≈ one per frame → this is the **between-frame browser
  gap** (present / compositing / rAF handoff), not our CPU and not a stall.
- **Delivered period (~48–53 ms) ≈ frame CPU (~47 ms)** → no rAF-throttle slack;
  we are CPU-bound on the AVM tick.
- (Contrast: the older 62 ms profile showed 22% idle in huge runs incl. a 114 ms
  warmup stall — that was measurement-window warmup, gone in the clean 47 ms runs.)

**Verdict: the true compute budget is NOT below 47 ms.** The ~3 ms idle is browser
overhead that overlaps nothing of ours. The arithmetic holds: still need to cut
**~14 ms** from the ~47 ms CPU tick. **GREEN to proceed.**

## Step 1 FINDINGS (2026-07-14) — static-type coverage GATE: GREEN (with a reframe)

Built a read-only scout (`SWF_SCOUT_TYPES=<csv>` env-gate in `abc_emit.cpp`;
lightweight forward abstract-interpretation over each verified body, tracking a
static type per stack slot/local, classifying every static property op). **Ran on
Seedling's ABC → `tools/divergence/perf/seedling_static_type_scout.csv`.**
Validation: scout visited **exactly 25738 get / 2922 set / 4765 call** sites —
byte-exact match to the emitter's own site counts → stack alignment held across all
3626 bodies. Weighted three ways (self-time, inclusive-time, unweighted) — GET is
robust across all three. (Self-time is a proxy: the property cost lands in the
runtime callee, not method self-time; inclusive over-weights frame drivers. GET's
~85% resolvable holds under all three, so the go/no-go is safe.)

**GET (25738 sites; the dominant property op — `resolved_get` 8.1% +
`getproperty_static_ic` 7.6% ≈ 15.7% of frame): ~77–90% is compile-time-resolvable.**
Self-weighted share:
| lever | share | mechanism (compile-time constant an interpreter can't precompute) |
|---|---|---|
| **getlex-global** (recv_scope, 70% class-like) | **~32%** | `getlex FP`/`ClassName` → fixed global/domain slot; bake resolved pointer → kills `avm2_domain_find`/`findproperty` scan |
| **this / typed-local slot** (slot_sealed) | **~23%** | sealed ABC class + slot trait → `recv.u.obj->slots[N]` direct (the plan's original lever) |
| **class-static slot** (recv_classobj) | **~22%** | `FP.width`/`Draw._target` on compile-time-known Class → static slot[N] |
| bare-name scope (recv_scope, 30%) | ~13% | scope-chain lookup — harder (with-scope/activation) |
| recv_unknown (native flash.geom-typed etc.) | ~9% | receiver is a runtime/native class (Matrix/Point) — no ABC slot layout; separate lever |
| accessor/method-as-prop | ~2% | getter/setter — not a direct slot |

**THE REFRAME: the plan assumed the lever was `this.slot` (~23%). The scout shows
the two LARGER get levers are (1) `getlex`-global resolution (~32%) and (2)
class-static slot access (~22%).** All three are compile-time constants. The single
biggest one — resolving `getlex ClassName` to a baked global pointer — is exactly
the findproperty/domain lever the prior arc flagged as "different shape"; at
COMPILE time it collapses to a constant. Evidence from the hottest game method
**m676 = FlashPunk `Image.render`**: 36/56 gets are slot_sealed on `Image`
(`_matrix`,`scale*`,`origin*`,`_buffer`,`angle`,`blend`,`smooth`); the misses are
native `_matrix.a/.tx`/`point.x` (flash.geom, no ABC layout) and `getlex FP/Draw`.

**SET (2922): weaker — ~50% resolvable (incl-weighted); self-weighted only ~7%**
(m676's hot writes are native `_matrix.a/b/c/d/tx/ty`). Lower priority.

**CALL (4765): ~31–35% resolvable via class-static/getlex; devirtualization is
~0** — FlashPunk methods aren't `final`, so monomorphic-call baking needs class-
hierarchy analysis (CHA), not just local type. Defer devirt.

**Rough ms math:** GET-read ~15.7% (~7.4 ms) × ~85% resolvable → up to ~6 ms of
overhead removable (direct slot skips ic-call + vtable identity + count check +
`resolved_get` switch; keeps the load, so realistically ~3–4 ms). getlex/find
~6.3% (~3 ms) mostly addressable. Plus bucket C coercion elision (~4.5 ms partial).
Plausibly reaches the ~14 ms target. **GATE = GREEN.**

**Landmine confirmed in the ABC structs:** `AbcInstance.is_sealed` gives sealed
directly; trait `kind` gives Slot/Const vs Getter/Setter/Method; `super_name`
walks the chain. The verifier does **NOT** track an abstract type stack today — so
Step 2 must thread static receiver type through the IR itself (the scout's
abstract-interp is the seed for that pass). **Compile-time slot index still MUST
equal runtime `e->slot_index`** (unverified — do this first in Step 2).

**Step 2 recommendation:** prototype on **m676** (`Image.render`, the #1 game
method). Start with the **this/typed-local slot** lever (smallest blast radius,
clearest correctness) to validate the slot-index-match invariant and measure a real
A/B, THEN tackle the larger getlex-global + class-static levers.

## Suggested fresh-session launch prompt (Step 3)

> Continue the Seedling compile-time type-specialization arc — Step 3. Steps 0-2
> are DONE: `this.field` slot specialization shipped (~3-4 ms / 7-9% real-GPU win,
> byte-identical + slot-correct across the full avm2 suite). READ FIRST:
> SWFRecompDocs/plans/seedling-perf-compile-time-specialization.md (esp. the
> "Step 2 DONE" + "Step 3" sections) and memory
> [[seedling-perf-compile-time-specialization]]. Do Step 3 lever A first — the
> getlex-global domain inline cache (`getlex ClassName` = FindPropStrict +
> GetPropertyStatic; cache the resolved `avm2_op_finddef`/`avm2_domain_find` def
> object per site keyed on domain identity, skip the scan). Reuse the Step-2
> validation infra: `-DAVM2_SLOT_VERIFY`-style guard, the `SWF_NO_SLOT_SPEC`-style
> A/B baseline toggle, `tools/divergence/perf/ab_interleave.sh`, and full-suite
> verify-mode CI (`extra_defines` input). Measure a real interleaved A/B and keep
> avm2 at 829 byte-identical before shipping. Then lever B (class-static slot).
