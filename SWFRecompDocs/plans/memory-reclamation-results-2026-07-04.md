# Memory Reclamation — Stage 0/1 Measurements & Stage 2 Verdict

**Date:** 2026-07-04 (updated same-session as fixes landed)
**Plan:** [memory-reclamation-plan.md](memory-reclamation-plan.md)
**Commits:** Stage 0 instrumentation `700e02a3a`, Stage 1a `<sha>`, Stage 1b `<sha>`

## Methodology

Native no-graphics `MAX_FRAMES` builds via `profile_game_native.sh --build-only`,
run with `SWF_MEM_REPORT=1` (Stage 0 instrumentation: live/total counters +
intrusive live lists + classifier in `object.c`). Deterministic:
`MOCK_DATE_TIME=981152406000`, scripted input via `input_events.txt` files
(scratchpad `ms_input.txt` = menu→Start→15 cell clicks; `dj_input.txt` =
5 menu clicks + alternating arrow-key bursts; N runs uninstrumented attract
mode). Byte-identity gate: game stdout compared before/after each fix.

## Baseline (Stage 0, pre-fix, commit 700e02a3a)

| Workload | Frames | Live obj | Live arr | Notes |
|---|---|---|---|---|
| N title demo (no input) | 600 | 31,416 | 27,173 | dprops: 924 att / 0 det |
| N title demo | 3000 | 59,736 | 55,481 | **+11.8 obj + 11.8 arr per frame, linear**; arrays freed over whole run: 2 |
| Minesweeper menu idle | 600 & 3000 | 650 | 176 | flat — menu alone doesn't leak |
| Minesweeper menu→game+clicks | 3000† | 3,255 | 2,538 | **1,348 detached dprops**; 1,328 arrays held as obj props |
| Doodle Jump title idle | 600→3000 | 611→1,211 | 34 | +0.25 obj/frame |
| Doodle Jump menu clicks+keys | 3000 | 1,252 | 63 | 32 detached dprops |

† Minesweeper run terminates early at a **pre-existing** `heap_alloc(442368)`
OOM → `exit(1)` (see Discovered bugs below); pre/post runs die at the same
deterministic point, so deltas are comparable.

## After Stage 1a (dprops release on detach)

| Workload | Live obj | Δ vs baseline | Detached dprops | Notes |
|---|---|---|---|---|
| Minesweeper menu→game | 1,908 | **−41%** | 1,348 → **0** | frees 1,704→3,056; stdout byte-identical |
| Doodle Jump clicks | 1,220 | −2.6% | 32 → **0** | stdout byte-identical |
| N title demo | 59,736 | 0 | 0 → 0 | N's leak is not clip removal — unchanged, as expected |

Stage 1a also exposed the Stage 1b class: Minesweeper's arrays went from
1,328 "held-as-obj-prop" to orphaned (owners freed, spines still live).

## After Stage 1b (ARRAY property values balanced)

Byte-identical stdout on all three games; 17-test array/removal smoke set
green; ASAN clean (see gate below).

**Reclamation delta: ≈0 — and this is the measurement that decides Stage 2.**

| Workload | Live arr post-1a | Live arr post-1b | Arrays freed post-1b |
|---|---|---|---|
| N title demo | 55,481 | 55,483 | **0** (was 2 pre-1b) |
| Minesweeper menu→game | 2,542 | 2,542 | **0** |
| Doodle Jump clicks | 63 | 63 | 0 |

Why: a script-created array starts at refcount 1 (the allocating reference,
which nothing ever consumes — fact 1 below). Post-1b a property store adds
+1 (count 2); the owner's death releases −1 (count 1) — the spine still
leaks. Pre-1b, `deleteProperty` released the *borrowed* ref (count 1 → 0),
which is why N freed 2 arrays before and 0 after: that reclamation was the
unsafe transfer-semantics accident (free-on-delete of a possibly-shared
array = the latent UAF this fix removes).

So Stage 1b is a **correctness + Stage-3-precondition** change, not a leak
fix: it removes the shared-array delete UAF, makes ARRAY handling symmetric
with OBJECT in all five functions, and gives the future sweep a consistent
teardown. The plan's Finding B.2 ("every obj.list = [...] leaks the spine")
is real, but its cause is the floating allocating reference, not the missing
retain/release arms — no per-container balancing can fix it.

## Stage 2 verdict: **Stage 3 stays live — the collector is needed.**

Residual growth after both fixes is NOT ≈0:

- **N title demo: ~11.8 objects + 11.8 arrays leaked per frame, linear**
  (59,736 obj / 55,483 arr live after 3000 frames). These are frame-script
  temporaries: created, used, discarded — unreachable but pinned by the
  floating allocating reference. Hours-long sessions grow without bound.
- **Minesweeper after board play: 1,901 plain objects + 2,542 arrays live**
  (down from 3,255 obj pre-1a, but the board data hanging off freed dprops —
  arrays at count ≥1, nested objects at count ≥1 — stays).
- Doodle Jump: mild (+0.25 obj/frame idle) but same shape.

The dominant leak class is **unreachable-but-refcounted garbage** — not the
two deterministic classes and not cycles. Refcounts cannot reclaim it while
stack/var_map/scope references are borrowed (making them exact is the
rejected alternative: it would require retain/release on every var store,
stack op, and scope push — the "full audit" the plan already scoped out).
A **root-traced mark-sweep backstop (plan Stage 3) is the only fix that
covers it**: liveness = reachability, so floating refcounts are irrelevant
by construction. The same sweep also covers true cycles, which this session
confirms exist but are third-order.

Priority note: N is the worst real workload measured (~350 obj+arr/sec at
30fps ≈ a few MB/hour of small objects — slow but unbounded). The collector
matters most for the long-running browser demos (N attract mode runs
indefinitely on docs pages).

## Verification gates (both fixes)

- Byte-identical game stdout pre/post each fix (N, Minesweeper, DJ). ✔
- Local smoke sets: 14 removal/load tests (1a), 17 array+removal tests (1b),
  plus graphics-mode `unload` single test. All pass. ✔
- ASAN (HEAP_PASSTHROUGH sanitizer builds, 3000-frame game runs,
  detect_leaks=0): Doodle Jump clean post-1a; all three games post-1b —
  see session log. The one hit was the pre-existing textfield init_text UAF
  (fixed, `09c353f58`).
- Full CI both modes at each landed commit — results recorded in
  session/pipeline log; zero pass→fail regressions required.

## Ownership-model facts established this session (load-bearing for Stage 3)

1. **The allocating +1 is a floating reference for script-created values.**
   Stack pushes/pops, `var_map` stores, and scope captures are all borrowed;
   nothing ever consumes the initial refcount=1 of an object/array created by
   script (`{}`, `[]`, `new X`). Consequently a property-stored object sits at
   count 2 and its owner's death only drops it to 1 — **per-container release
   chains reclaim exactly one level** unless the value was only ever held by
   the dying container. This is why N's per-frame temporaries (~12 obj + 12
   arr per frame, created and discarded by frame scripts) are untouched by
   Stages 1a/1b: they are unreachable-but-refcounted garbage. They are
   exactly what a root-traced mark-sweep (Stage 3) collects, and exactly what
   trial-deletion/refcount-trusting collectors would mishandle (plan Finding A).
2. **dynamic_props ownership normalized (Stage 1a):** 27 of 44 attach sites
   paired the alloc with an immediate `retainObject` (born at count 2; the
   convention dates to the first dprops commit `56ef4af54` and had no matching
   release anywhere). Removed — the MC pointer field now uniformly owns the
   single allocating reference.
3. **Releases must be deferred to the tick boundary.** Borrowed references to
   a clip's dprops live in `g_this_stack` (SWF6+ type-1 method calls bind
   `this` = the dprops object), WITH-scope chain entries, and self-targeted
   loadMovie mid-handler. `actionDeferDpropsRelease` queues; the frame loops
   drain at tick start where the VM is quiescent.
4. **deleteProperty's ARRAY arm was releasing a borrowed reference** (a latent
   UAF whenever one array was stored under two properties, since the second
   holder dangled). Stage 1b's retain-on-store makes that arm balanced.
5. **Pre-audit result:** only 3 `releaseArray` call sites existed
   (releaseArray recursion, setArrayElement overwrite, deleteProperty), none
   manually compensating for the borrowed convention → the balancing change
   cannot double-release. No direct `refcount` manipulation outside object.c.

## CI note: `global_proto_decls` failure-mode shift (not a regression)

The Stage 0+1a CI runs (both modes 638/710 passing, **zero pass→fail**)
showed already-failing `global_proto_decls` change no-graphics status
output_mismatch → segfault (graphics already segfaulted before). Root cause:
the test redeclares global constructors and exercises **pre-existing UAFs**
— ASAN on the *pre-session* runtime hits the identical
`actionSetMember` stale-`ASProperty*` write (a virtual setter that adds
properties to its own object moves `properties[]` under the caller's
pointer). Stage 0's struct-size change merely relocated where that UB lands.
Fixed the confirmed stale-write (re-resolve the slot after
`invokeVirtualSetter`); the test still fails on a second pre-existing UAF
(`retainObject` on a prototype object freed by an overwrite-release —
follow-up material, same family as making prototype ownership explicit).

## Discovered pre-existing bugs (out of scope, repro preserved)

- **Doodle Jump native SEGV on click hit-test:** clicking certain stage
  coordinates crashes `sprite_content_bounds_twips` (tag.c:6182, bogus child
  in DL walk) via `actionMouseClickFocus` → `mc_get_pixel_aabb_ng`. Reproduces
  on clean HEAD (pre-instrumentation). Repro: scratchpad `dj_sweep.txt` input
  on the profile-no-graphics build.
- **attachMovie sprite_display_list growth invalidates aliased
  DisplayObject pointers (CI modes) — UAF + the OOM, one root cause.**
  ASAN (post-1b run, board workload): `aq_dispatch_register_ctor`
  (tag.c:7131) reads `prc->display_obj->constructor_invoked` inside a
  442,368-byte block (= 512 × 864B DisplayObject sprite list) that
  `ng_attachMovie` (tag_stubs.c:728 grow block, `NO_GRAPHICS/OFFSCREEN/
  HEADLESS`-gated) freed mid-drain when the FRadioButton ctor attached
  children at swf_depth ≈16386 — which also HCALLOCs a ~16400-entry ≈14 MB
  replacement per grow. Consequences: (1) queued register-ctor entries and
  `mc->display_obj` pointers into the old buffer dangle (ASAN UAF read +
  write of `constructor_invoked`); (2) the root display_list registration
  entry keeps the stale buffer pointer (same aliasing the browser-WASM fix
  `e86241173`-era comment describes — browser-WASM sidesteps by skipping the
  registration entirely); (3) repeated ≈14 MB grow/free churn exhausts the
  1 GB o1heap arena → `heap_alloc(442368) failed` → `exit(1)` ends the
  board workload early. Pre-existing (Phase 5 comment even notes
  "realloc-staleness risk is no worse than before"); untouched by this
  session's changes. Proper fix = pointer fixup (translate aliased
  entry/buffer pointers on grow) or ownership refactor — needs its own
  session. Repro: `ms_input.txt` board workload under the scratchpad
  `asan_build_run.sh` (HEAP_PASSTHROUGH) build.
