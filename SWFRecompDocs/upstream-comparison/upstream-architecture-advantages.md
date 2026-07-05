# Advantages of the Upstream Architecture

**Living document.** Last updated: July 4, 2026 (upstream master `4e7c773` /
`b17653d`, the merged objects-and-functions architecture).

What upstream's design does better than ours, with emphasis on problems **we
demonstrably still carry that their architecture solves** — this document therefore
also serves as the list of "issues in downstream that upstream has already fixed."
Each entry notes whether the advantage is *actionable* for us (an idea we could
adopt inside our architecture) or *structural* (inseparable from their foundation).

The flip side is [`downstream-architecture-advantages.md`](downstream-architecture-advantages.md).

---

## 1. String-ID interning for property lookup — **our #1 measured deficiency**

**Their design:** Every property name is interned to an integer ID at recompile time
(`initial_strings`, per-SWF string tables) with runtime support for dynamic string
IDs (`d30e783`, `c6a9e71`). Property lookup compares integers.

**Our deficiency:** We look up properties by raw string. The initial callgrind
profile (June 2026, Doodle Jump) measured **~67% of instruction count in
property-name lookup** — independently identifying interning as our top AVM1-side
lever before we ever saw their implementation. Two mitigations have since landed
*inside* our architecture (property fold-hash gate `537951f4f`, per-object hash
index `e13388a18`; −49% instructions on DJ, both CI-clean) plus resolution caches
and ASCII fast-paths, so the live residual is the **query-hashing + UTF-8↔UTF-16
conversion complex, ~40% of N's no-graphics profile** (name_fold_hash ~13%,
findPropertySlot ~8%, conversions/malloc ~15%). Full interning eliminates that
residual class.

**Actionable:** Yes — the highest-value idea to port (as a design, not code). Their
master is now a working reference: compile-time ID assignment in the recompiler,
runtime intern table for dynamic names, IDs as rbtree keys. A contained first stage
was already planned (`SWFRecompDocs/plans/wasm-game-performance-step3-string-interning.md`);
the full plan is `SWFRecompDocs/plans/string-id-interning-plan.md`. Caveat on
user-visible payoff: the profiled games are currently GPU-bound or frame-capped,
so this buys CPU%/battery and headless throughput first, wall-clock FPS only on
CPU-bound titles.

## 2. Ordered property storage (red-black tree) vs linear array

**Their design:** rbtree keyed by string ID — O(log n) lookup/insert/delete.

**Our deficiency (largely mitigated June 2026):** Linear `properties` array. The
raw O(n) strcmp scan is gone — properties now carry a precomputed case-folded
`name_hash`, scans are hash-gated, and objects with ≥12 properties get a lazy
open-addressing hash index (`findPropertySlot`, `object.c:196`). What remains is
the per-lookup query hashing and UTF conversion (see #1).

**Caveat found in the July 2026 survey:** rbtree iteration is *id order*, but AVM1
`for..in` must enumerate in insertion order (reverse, via LIFO push) — our tests
and real content depend on it. Upstream hasn't hit this only because their
`ActionEnumerate` is currently unimplemented (body commented out). Our adoption
path (see `plans/string-id-interning-plan.md`) therefore keys *comparison* by id
but keeps the insertion-ordered array as storage.

**Actionable:** Comparison-by-id yes (Stage 3 of the interning plan); the tree
itself no.

## 3. All state in `app_context` — instantiability and re-entrancy

**Their design:** No globals; every engine function receives `SWFAppContext*`. The
final pre-merge commit (`8821df3`) finished pulling remaining state back in.

**Our deficiency:** 455 `g_`-prefixed globals (measured July 2026); one movie per
process/module instance; no in-process create/destroy/reset; `loadMovie` of external
recompiled SWFs into a shared stage is architecturally blocked.

**Actionable:** Technically yes, practically no — see
[`2026-07-thread-safety-benefits.md`](2026-07-thread-safety-benefits.md) for why the
practical benefit is near zero for our deployment model and the cost is a ~10×-scale
version of their Phase 0 refactor. Verdict there: revisit only when a concrete
product goal (shared-stage `loadMovie`, in-process multi-instance) appears, and then
incrementally.

## 4. Systematic memory management: GC + stack-integrated refcounting

**Their design:**
- Refcounting is woven into the stack macros themselves — `PUSH_OBJ()` retains,
  `POP()` releases. Correctness by construction rather than by discipline.
- A concurrent collector (dedicated free thread, Johnson's-algorithm cycle
  detection, per-object read-write locks) reclaims reference cycles.

**Our deficiencies:**
- Reference cycles leak permanently (`a.b = b; b.a = a`). No observed user-facing
  problem yet, but it is a real defect for hours-long sessions.
- Our retain/release is manual discipline spread across 75K lines, and it has
  historically produced real bugs — heap use-after-free / OOB in graphics mode
  (case-v5/v6, fixed 2026-05-30 via ASAN), assorted leak fixes throughout the log.
  Every new code path re-exposes the risk; theirs centralizes it.

**Actionable:** Partially, and now measured. The July 2026 ownership survey
found our refcounts are *advisory* (ARRAY/FUNCTION property values, timers, and
this/scope stacks are borrowed by design), so refcount-trusting detectors
(Bacon-Rajan trial deletion, upstream's neighbor-walking design) are unsafe for
us; the safe shape is a root-traced mark-sweep backstop. The plan's Stages 0–2
executed 2026-07-04 (`700e02a3a`, `a38bbe7ea`, `9b2aa048b`): the two
deterministic leaks are fixed (Minesweeper clip-churn −41% live objects; 1,348
detached `dynamic_props` → 0), and the measurements produced the decisive
diagnosis — **the dominant residual leak is acyclic script temporaries whose
allocating +1 is never consumed** (stack, var_map, and scopes are all borrowed,
so release chains stop at refcount 1; N leaks ~12 objects + 12 arrays per
frame, linear). That is exactly the problem upstream's *stack-integrated
refcounting* (`PUSH_OBJ` retains / `POP` releases) solves by construction — a
genuine validation of their design. Our answer — the Stage 3 **root-traced
mark-sweep collector — shipped default-on 2026-07-04** (`bac8b31e8` +
`427f0abb1`): single-threaded, between-frames, reachability-only liveness,
real free at cadence 60, `SWF_GC=0` opt-out. Acceptance met: N title demo over
3000 ticks went from 59,736 objects + 55,483 arrays (linear growth) to ~3,709 +
254 flat, byte-identical output, both CI modes green. The floating refs remain
load-bearing for the refcount fast path and must not be "fixed" site-locally;
any new C-side object stash must be rooted or scrubbed (see the root-set rules
memory). **This advantage is now substantially neutralized** — we have
GC-grade reclamation without threads, locks, or WASM costs; what remains
upstream-only is the promptness of stack-integrated refcounting (they reclaim
at pop; we reclaim within ~60 ticks). **Plan + results:**
`plans/memory-reclamation-plan.md`, `plans/memory-reclamation-results-2026-07-04.md`.

## 5. Standard library in ActionScript (AS2Runtime prelude)

**Their design:** Built-in classes are written in AS2, compiled by their MTASC fork
into a prelude SWF, recompiled ahead of the user's SWF (`DoInitAction`,
`__Packages`, `ASSetPropFlags`). Only opcodes and true native surface stay in C.

**Advantages over our all-in-C approach:**
- **Correct semantics by construction** — a class defined in AS2 automatically gets
  real prototype wiring, real closures, correct enumerability, correct
  `constructor`/`__proto__` relationships, because it goes through the same machinery
  as user code. In C we must hand-replicate each of those (and we have had bugs in
  exactly that replication — e.g. property-flag and prototype-identity details).
- **Drastically less C surface** — their runtime core stays ~1.5K lines + focused
  native modules while class breadth grows in `.as` files.
- **Contributor accessibility** — adding `String.prototype.split` in AS2 is a
  20-line patch anyone who knows ActionScript can write; in our C it means stack
  macros, ActionVar tags, and refcount discipline.
- **Iteration speed** — stdlib changes don't recompile the C runtime.

**Structural for them, but the *pattern* is partially actionable for us:** we already
use injected-AS for instrumentation (livetest harness, DJ/N loaders). Implementing
*new* leaf classes in interpreted-and-recompiled AS2 over our C core is conceivable.
In practice our stdlib is already built and test-validated, so the win would apply
mainly to net-new surface. Note the counter-case in the downstream doc: some Flash
behaviors (native re-entry budgets, deliberate UB replication) *cannot* be expressed
at the AS2 level.

## 6. One calling convention — the bug class we keep re-fixing

**Their design:** A small closed set of function ABIs (`FUNC_TYPE_1/2/3`), with the
type-3 custom ABI (`action_runtime_func(SWFAppContext*, u32 num_args)`) reading
arguments directly off the stack. Every call site dispatches uniformly.

**Our deficiency, with receipts:** Our function dispatch grew ad hoc (type-1 simple
functions vs type-2 register functions vs native builtins vs virtual-property
helpers), and argument marshalling has been a **recurring bug source**:
- type-1 calls via `super()`/`super.method()`/`__resolve`/array-element pushed args
  in *reverse* in 6 dispatchers (`bcacc3f70` — swapped Minesweeper's
  `setSize(w,h)`);
- type-1 virtual getter/setter helpers pushed args wrong / failed to pad to
  `param_count` (`63f7af229` — one variant *ate the caller's eval stack*);
- type-1 `this`-binding missed for MC method calls (cont. 38);
- `actionNewObject` clamped >16 args and stranded operands (corrupting the next
  opcode).

Each fix was small; the class of bug exists because the convention isn't singular.

**Actionable:** Yes, as internal consolidation — funnel all our dispatch paths
through one arg-marshalling helper. No upstream code needed; their design just
demonstrates the invariant worth enforcing. **Planned:**
`plans/function-dispatch-consolidation-plan.md` (July 2026). The survey behind it
counted ~129 raw invocation points across ~38 dispatchers, and its Stage 0
(completed 2026-07-04) **confirmed and fixed three more live instances** of the
bug class: ExternalInterface type-1 args pushed in reverse (`d8abc5c0a`),
event-handler type-1 args never pushed — `onSetFocus(oldFocus)` lost its
argument (`9a8c6dce3`), and setInterval callbacks running under the caller's SWF
version instead of their own (`60070d96a`). Seven shipped bugs from one
structural cause and counting.

## 7. Runtime-side tessellation (libtess2)

**Their design:** Shapes are tessellated at runtime (`triangulation.c`, libtess2,
`TESS_WINDING_ODD`), one path for all geometry.

**Our split:** libtess2 at *recompile time* for static shapes (better startup cost:
work done once, offline) but separate runtime paths for dynamic geometry (drawing
API, morph shapes) — and morphs + embedded-font glyphs still use earcut (see
`tessellation-libtess2-migration` notes). Their single-path model avoids that
inconsistency; our offline model avoids runtime cost. Genuine trade-off, not a pure
win — but their uniformity is the cleaner shape.

(Independent convergence on libtess2 itself is mutual validation — both projects
replaced their original tessellators with it in 2026.)

## 8. Codebase tractability

Their runtime core is small (~1.5K-line `action.c` + focused `runtime_api/` modules:
Array, BitmapData, ColorTransform, Function, MovieClip, Number, Object, Sound,
String_recomp, Toml, toplevel), reviewable, and cheap to onboard into. Our
`action.c` is a 75K-line monolith that works but concentrates risk: long compile
times, merge-conflict surface, "two implementations of removeMovieClip ~15K lines
apart" class of hazards (a real bug we hit — fixes must be mirrored at both sites).

**Actionable:** In principle we could split `action.c` mechanically into modules.
Churn vs. benefit has so far argued no; worth reconsidering if compile time or
duplicate-site bugs worsen.

## 9. Platform layer via SDL3

Mature, maintained windowing/input/audio/GPU abstraction with platforms (consoles,
mobile) we'd have to hand-port to. Our Dawn/WebGPU + emscripten stack is better for
*our* targets (headless CI, browser, pixel-exact offscreen capture) but is bespoke.
If native desktop/console distribution ever became a goal, their layer is the
better starting point. Structural.

## 10. Miscellaneous smaller wins

- **Recompiler string deduplication + per-function output streams** — cleaner
  generated code; our generated C is more repetitive.
- **`ENSURE_SIZE`-style growth macros with context-tracked heap** — uniform buffer
  growth discipline.
- **Deliberate pre-merge hygiene** — upstream held a PR open ~4 months to finish
  consolidation before merging; the discipline itself is an asset.

---

## Summary table

| # | Advantage | Solves a problem we measurably have? | Actionable for us? |
|---|-----------|--------------------------------------|--------------------|
| 1 | String-ID interning | **Yes** — name-lookup complex was 67%, still ~40% after landed mitigations | Yes (top candidate) |
| 2 | rbtree properties | Yes — O(n) scans | Yes (with #1) |
| 3 | app_context instantiability | Barely (see thread-safety analysis) | Deliberately declined |
| 4 | GC + stack-integrated refcounts | **Neutralized 2026-07-04** — our root-traced collector shipped default-on; residual gap = reclamation promptness only | Done (differently) |
| 5 | AS2 prelude stdlib | Partly — semantics-by-construction | Pattern only, for net-new surface |
| 6 | Single calling convention | **Yes** — recurring arg-marshalling bug class | Yes (internal consolidation) |
| 7 | Uniform runtime tessellation | Partly — our morph/glyph paths still earcut | Trade-off |
| 8 | Small modular codebase | Yes — monolith risk (duplicate-site bugs) | Mechanical split possible |
| 9 | SDL3 platform layer | No (for current targets) | No |
