# Memory Reclamation — Leak Fixes + Cycle Collector Plan

**Created:** July 4, 2026
**Status:** Stages 0–2 DONE (2026-07-04). Stage 0 instrumentation `700e02a3a`;
Stage 1a dprops release `a38bbe7ea` (Minesweeper churn: −41% live objects,
1,348 detached dprops → 0); Stage 1b ARRAY balancing landed as a
correctness/consistency fix — measured reclamation ≈0 because the allocating
reference floats (see results doc). **Stage 2 verdict: residual growth is NOT
≈0 (N leaks ~12 obj + 12 arr per frame, linear) → Stage 3 collector stays
live and is the only fix for the dominant class (unreachable-but-refcounted
temporaries).** Numbers, gates, and ownership facts:
[memory-reclamation-results-2026-07-04.md](memory-reclamation-results-2026-07-04.md).
**Origin:** upstream-comparison advantage #4 ("our refcounting leaks cycles").
Scoped as "cycle collector" going in; the July 4 ownership survey of
`object.c`/`action.c` broadened it — two *deterministic* leak classes were found
that likely dominate cycles in practice, and a structural fact was found that
dictates the collector's design.

---

## 1. What the ownership survey established

### 1.1 The ownership model (current)

- Exactly **two refcounted types**: `ASObject` (`object.h:71`) and `ASArray`
  (`object.h:214`), plain-`malloc`'d in `allocObject` (`object.c:284`) /
  `allocArray` (`object.c:1166`).
- **`ASFunction` is immortal** — no refcount, never freed on success paths.
  Functions (and their `prototype_obj`, `own_props`, retained
  `captured_scope[]`) are permanent roots by construction.
- **MovieClips** are registry-managed (`child_mc_cache`), not refcounted;
  `MOVIECLIP`-typed values inside objects are borrowed and may dangle at dead
  clips (`depth==INT_MIN`) — a collector must never dereference them.
- **No global registry of live objects** and no allocation counters — objects
  are reachable only through the graph. Any sweep needs new tracking.
- **Destruction is pure reclamation** — no finalizers, nothing
  script-observable. Deferring collection to between-frames is
  behavior-invisible by construction (the survey confirmed `onUnload` etc. are
  display-lifecycle, not object teardown).

### 1.2 Finding A — refcounts are advisory, not exact (design-critical)

Retain discipline is deliberately asymmetric:

- `setProperty` retains **OBJECT values only** — properties holding **ARRAY**
  or **FUNCTION** values are borrowed (`object.c:651, 719, 760`), and
  `releaseObject` at zero recurses into OBJECT values only (`object.c:391-395`).
- `setArrayElement` retains OBJECT **and** ARRAY (`object.c:1393`) — arrays are
  symmetric, objects are not.
- `g_this_stack`, `scope_chain[]`, timer entries (`timer.c:36-41` — **no
  retain/release anywhere in timer.c**), getters/setters: all borrowed.

**Consequence:** any cycle-detection algorithm that *trusts refcounts* —
Bacon-Rajan trial deletion, or upstream's Johnson-based neighbor-walking
collector — is **unsafe here**: an object kept alive only by a borrowed edge
has a count that under-represents its liveness, and trial deletion would free
live objects. The safe shape for us is a **root-traced mark-sweep backstop**
(liveness = reachability, refcounts ignored for the collection decision),
keeping refcounting as the prompt-reclamation fast path. This is also why we
cannot simply copy upstream's design even conceptually.

### 1.3 Finding B — two deterministic leaks that are not cycles

1. **`mc->dynamic_props` is detached by raw `NULL`, never released**
   (`action.c:23044, 23076, 23130, 23176`). Every MovieClip removal leaks the
   clip's entire AS property object. Games churn clips constantly (particles,
   attachMovie UI, duplicateMovieClip) — this is almost certainly the largest
   real leak in hours-long sessions, and it needs no collector to fix.
2. **Arrays stored as object properties are never released** (the Finding-A
   asymmetry): `allocArray`'s initial refcount=1 is never balanced when the
   owning object dies. Every `obj.list = [...]` leaks the array's spine.

Cycles (`a.b=b; b.a=a` — both edges retained OBJECT properties) are real but
third in line behind these.

## 2. Staged plan

### Stage 0 — instrument, then decide (small; do first)

Add cheap allocation tracking at the two chokepoints (`allocObject`,
`allocArray`) and the two release-at-zero blocks (`object.c:427, 1288`):
live-count + total-alloc/total-free counters, plus an **intrusive doubly-linked
all-objects list** (two pointer fields per object — this doubles as the sweep
infrastructure for Stage 3). Expose via the existing perf-HUD pattern
(browser) and an env-gated stderr dump at exit (native).

Measure on long runs: N title demo (5+ min), Minesweeper difficulty screen +
games, DJ. Output: leak rate per class — instrument a one-off tagged build to
attribute leaked objects to (a) detached `dynamic_props`, (b) unreleased
property arrays, (c) cyclic clusters (everything else). **This decides how much
of Stages 1–3 is worth doing.**

### Stage 1 — fix the deterministic leaks (no collector needed)

1. **Release `dynamic_props` on detach** at the four NULL-assignment sites.
   Ownership is clean: the MC holds the allocating reference; other holders
   (if any) have their own retains, so `releaseObject` (not free) is correct.
   Traps to respect: the finalize/pending-removal ordering
   (`actionFinalizePendingRemovals` semantics), soft-ref re-resolution, and
   the user-vars-survive-removal rule (that's `var_map`, not `dynamic_props`
   — verify no path reads a detached `dynamic_props` afterwards).
2. **Balance ARRAY property values** — retain on store, release on
   overwrite/delete/destroy, mirroring the existing OBJECT arms in the same
   five functions (`setProperty`, `setPropertyWithFlags`, `deleteProperty`,
   `releaseObject`, plus the overwrite path). **Audit first**: any site that
   manually compensates for the borrowed convention (e.g. releases an array it
   stored) would double-release after this change — grep every
   `releaseArray` call site against stores. FUNCTION values stay borrowed
   (functions are immortal; retaining is meaningless until that changes).

Both are shared-runtime changes → full CI both modes; plus ASAN runs of the
game set (the survey's asymmetries are exactly where double-free bugs would
hide). Success metric: Stage 0 counters go flat on clip-churn workloads.

### Stage 2 — decide whether a collector is still needed

Re-run Stage 0 measurements. If residual growth is ≈0 on real games, **stop
here** — a collector for leak classes nobody hits is maintenance burden. The
`a.b=b; b.a=a` pattern in game code is the thing to look for (the tagged-build
attribution shows it as cyclic clusters).

### Stage 3 — root-traced mark-sweep backstop (only if Stage 2 says so)

Single-threaded, stop-the-world, run **between frames** at a low cadence
(e.g. every N seconds or every M allocations), where the VM is quiescent —
eval stack, `scope_chain`, `g_this_stack` are empty, which collapses the root
set to a manageable list:

- `global_object`; `root_movieclip.dynamic_props` + every live
  `child_mc_cache[i]->dynamic_props`;
- all `ASFunction`s (immortal): `captured_scope[]`, `prototype_obj`,
  `own_props` — reachable via `function_registry` **plus** anonymous
  functions, which the registry deliberately excludes (`action.c:56902`) →
  functions need their own all-functions list (same intrusive-list trick, or
  make anonymous functions collectible later);
- subsystem-held borrowed refs that would otherwise be invisible: **timer
  entries** (`TimerEntry.func/object/extra_args`), watch callbacks, pending
  LoadVars/XML/MovieClipLoader/Sound callbacks, Selection focus, the
  interval/listener singletons. (These are borrowed *by design* today — for
  the collector they are roots; the alternative, making them retained, is a
  bigger behavioral change.)
- Trace: OBJECT/ARRAY-typed `ActionVar`s in properties, elements,
  `arr->props`, `interfaces[]`; skip MOVIECLIP/FUNCTION-typed values
  (non-owning; functions traced from the function list instead).
- Sweep the intrusive list from Stage 0; free unmarked via the existing
  destroy paths *minus* recursion (sweep handles reachability; use a
  cycle-safe teardown that doesn't re-release swept neighbors — the standard
  two-pass: first neutralize outgoing refs of all doomed objects, then free).

Missed-root risk is the whole game: a forgotten root frees live objects and
manifests as UAF. Mitigations: ASAN game runs as a required gate; a paranoid
mode (env flag) that quarantines swept objects (poison + delay free) for
soak-testing; roll out behind a default-off flag, enable in CI first.

### Explicitly out of scope

- Making refcounts exact everywhere (Stage 1.2 fixes the one load-bearing
  asymmetry; a full audit is only worth it if Stage 3 never lands).
- Collecting `ASFunction`s (immortality is fine at current scales; revisit if
  Stage 0 shows function-heavy churn, e.g. per-frame closures in some game).
- Anything concurrent. Upstream's free-thread design solves a problem we don't
  have and costs WASM compatibility we do need.

## 3. Verification protocol

- Full CI both modes per stage (shared runtime); zero pass→fail.
- ASAN runs of the game set per stage (this plan's changes are exactly the
  UAF-shaped kind; `graphics-sigabrt-real-heap-bugs` playbook applies).
- Stage 0 counters are the acceptance metric for Stages 1/3 (flat live-count
  on clip-churn + cyclic workloads).
- Byte-identical trace outputs expected throughout (destruction is
  unobservable); any output diff = a bug, full stop.

## 4. Risks

| Risk | Mitigation |
|---|---|
| Double-release after balancing ARRAY properties (sites compensating today) | Pre-audit all `releaseArray` call sites vs stores; ASAN gate |
| Releasing `dynamic_props` that something still reads post-detach | Audit the four sites' consumers; soft-ref/finalize traps listed in Stage 1 |
| Collector frees a live object (missed root) | Quarantine/poison soak mode; default-off flag; ASAN; CI-first rollout |
| Intrusive list overhead | Two pointers/object + O(1) link/unlink; measure with the perf harness (expect noise) |
| Building a collector nobody needs | Stage 2 gate: real-game measurements decide |

## 5. When to execute

Stage 0 + Stage 1 are a good single session with immediate, measurable payoff
(the `dynamic_props` leak fix helps every long-running game today). Stages 2–3
are strictly measurement-gated. Independent of the interning and dispatch
plans (different files' hot paths), so it can interleave freely.
