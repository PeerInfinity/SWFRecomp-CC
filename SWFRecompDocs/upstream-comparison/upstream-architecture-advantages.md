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

**Our deficiency:** We look up properties by raw string with `strcmp`/hashing.
Native callgrind profiling (2026, `scripts/profile_game_native.sh`) measured **~67%
of instruction count in property-name lookup**. This was independently identified as
our top AVM1-side performance lever before we ever saw their implementation.

**Actionable:** Yes — the highest-value idea to port (as a design, not code). Their
master is now a working reference: compile-time ID assignment in the recompiler,
runtime intern table for dynamic names, IDs as rbtree keys. Currently deprioritized
because our user-facing bottleneck is GPU upload, not AVM1 — but if native/headless
throughput ever matters (batch procgen validation, server-side use), this is the fix.

## 2. Ordered property storage (red-black tree) vs linear array

**Their design:** rbtree keyed by string ID — O(log n) lookup/insert/delete.

**Our deficiency:** Linear `properties` array — O(n) scan per access, O(n²)-ish
patterns for property-heavy objects (arrays used as dictionaries, large config
objects, per-tile game state). Compounds with #1: we pay a string compare *per
scanned entry*.

**Actionable:** Yes, and only worth doing together with #1 (integer keys make the
tree cheap). Same caveat on priority.

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

**Actionable:** Partially. The *cycle collector* could be adopted single-threaded
(between frames) without any locking. The *stack-integrated refcounting* idea could
be retrofitted into our PUSH/POP macros, though auditing 75K lines of existing
pop-then-use patterns makes it a major project. The concurrent/locked form is
structural (and undesirable in browser WASM).

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
demonstrates the invariant worth enforcing.

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
| 1 | String-ID interning | **Yes** — ~67% native instr. in name lookup | Yes (top candidate) |
| 2 | rbtree properties | Yes — O(n) scans | Yes (with #1) |
| 3 | app_context instantiability | Barely (see thread-safety analysis) | Deliberately declined |
| 4 | GC + stack-integrated refcounts | Yes — cycle leaks, recurring manual-refcount bugs | Partially (single-threaded cycle collector) |
| 5 | AS2 prelude stdlib | Partly — semantics-by-construction | Pattern only, for net-new surface |
| 6 | Single calling convention | **Yes** — recurring arg-marshalling bug class | Yes (internal consolidation) |
| 7 | Uniform runtime tessellation | Partly — our morph/glyph paths still earcut | Trade-off |
| 8 | Small modular codebase | Yes — monolith risk (duplicate-site bugs) | Mechanical split possible |
| 9 | SDL3 platform layer | No (for current targets) | No |
