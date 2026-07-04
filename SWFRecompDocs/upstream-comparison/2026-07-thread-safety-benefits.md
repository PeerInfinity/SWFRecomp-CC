# What Would Thread Safety Practically Buy This Repo?

**Date:** July 4, 2026
**Question:** If we implemented the features required for thread safety in
SWFRecomp-CC (upstream's `app_context` state model, per-object locks, concurrent GC),
what would the practical benefits be?

**Answer in one line:** Much less than the phrase suggests — "thread safety" bundles
three separable capabilities, only one of them (instantiability) has real value for
us, and the outcomes it enables are mostly already obtained through process- and
WASM-module-level isolation.

---

## 1. Unbundling the term

Upstream's design provides three distinct things that tend to get lumped together:

1. **Instantiability** — no globals; all engine state lives in `SWFAppContext`.
   Enables two independent movie instances in one process, and clean
   create/destroy/reset of an instance.
2. **True multithreading** — per-object read-write locks; work can run concurrently.
3. **Concurrent GC with cycle detection** — a dedicated free thread collects
   reference cycles.

These have very different value for this repo and should be evaluated separately.

---

## 2. Multithreading proper: near-zero benefit

- **AVM1 is single-threaded by specification.** Script execution, timeline
  advancement, and display-list mutation are one strictly ordered sequence. Our
  entire test-parity result (96.7% filtered on 704 Ruffle AVM1 tests as of July
  2026) rests on preserving that exact ordering. There is no VM-level parallelism to
  extract.
- **Our measured bottlenecks are not CPU-thread-limited.** Browser performance is
  GPU-bound (writeBuffer/present backpressure on the profiled titles; see
  `browser-perf-is-writebuffer-not-avm1-walks`, commits `079c0fefe`, `485cab115`,
  `fee8f23f7`); native/headless is property-name-lookup-bound (67% initially,
  ~40% residual after the June 2026 hash-gate/hash-index work). Threads fix neither.
- **Threads are a liability on our primary target.** Browser-WASM pthreads require
  SharedArrayBuffer + COOP/COEP headers, heavier builds, and complicate audio and
  rendering. Upstream's GC free thread would be a cost for us in the browser, not a
  feature.

## 3. Instantiability: real benefits, mostly already obtained

This is the part with genuine value. Assessed against how we actually deploy:

| Desired outcome | Does contextification enable it? | Do we already have it another way? |
|---|---|---|
| Two movies on one web page | Yes | **Yes** — each recompiled game is its own WASM module; each instantiation gets its own linear memory. Globals are per-instance already. |
| Two movies in one native process | Yes | Processes are cheap; nothing currently needs in-process. |
| `loadMovie` of an external recompiled SWF into a parent stage | Partially — also needs recompiler symbol namespacing | **No** — this is the one genuinely blocked scenario. Blocking zero current work. |
| Library embedding with create/destroy/reset (Archipelago substrate) | Yes, more elegantly | Mostly — module re-instantiation gives fresh state today. |
| Save states (snapshot/restore for procgen harnesses) | Yes, more cleanly | **Yes** — browser: copy WASM linear memory (globals live inside it); native: `fork()`. Neither touches `action.c`. |

## 4. Cycle-collecting GC: modest and separable

Our refcounting leaks reference cycles (`a.b = b; b.a = a`). Irrelevant for trace
tests; a slow leak for hours-long game sessions — but no observed problem yet (the
clip leaks we did fix, e.g. N's `instanceN` creep, were display-list bookkeeping
bugs, not refcount cycles). If cycle leaks ever surface, a **single-threaded** cycle
collector run between frames fixes them without any locking apparatus. GC is
orthogonal to thread safety.

## 5. The cost, measured (July 4, 2026)

- **455** `g_`-prefixed globals defined in the runtime sources (47 exported through
  headers, including load-bearing ones: `g_current_context`, `g_event_this_mc`, the
  `this`-override machinery).
- **208** function declarations in `action.h` alone would change signature, plus
  hundreds of static helpers inside the ~75K-line `action.c` that touch globals
  freely.
- Recompiler code generation (`action.cpp`, `swf.cpp`) would need to thread a
  context through every generated call; all tests recompile; both build modes
  (NO_GRAPHICS and graphics) plus browser WASM affected.

This is upstream's "Phase 0" refactor at roughly 10× the size at which they did it,
against a codebase whose principal asset is behavioral parity that depends on exact
preservation. The transformation is largely mechanical and CI could verify
byte-identical output — but the churn is enormous, and since the friendly-fork
decision (July 2026) there is no merge-friction payoff on the other side.

## 6. Bottom line

Staying globals-based costs us exactly one thing: **one process (or WASM module
instance) can host only one movie** — and process/module isolation has made that
cost zero in practice. The refactor becomes worth revisiting only if a concrete
product goal appears:

- real `loadMovie` of external recompiled SWFs into a shared stage,
- a single native binary hosting many games in-process (arcade launcher),
- an embedding consumer needing many in-process instances.

Even then, prefer the incremental version — contextify only the state the feature
touches, or compose at the module/process level first — over a wholesale
`app_context` migration.
