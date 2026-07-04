# Session prompt: Memory-reclamation Stage 3 — root-traced mark-sweep collector

Execute **Stage 3** of `SWFRecompDocs/plans/memory-reclamation-plan.md`. Read, in
order: that plan (§Stage 3 + §1 ownership model), the results doc
`memory-reclamation-results-2026-07-04.md` (Stage 0–2 numbers, ownership facts,
and the three documented pre-existing bugs), and the `memory-reclamation` /
`dispatch-stage0-verdicts` memory entries.

## What already exists (from Stages 0–2 — do not rebuild)

- Intrusive doubly-linked live lists on ASObject/ASArray + a mark byte
  (`700e02a3a`) — this is your sweep infrastructure.
- Alloc/free counters, `allocDynamicProps` attribution tag, `SWF_MEM_REPORT`
  env-gated classified end-of-run report, live-objects line in the browser HUD.
- The acceptance target, measured: **N title demo leaks ~12 objects + 12 arrays
  per frame, linear** — unreachable-but-refcounted temporaries whose allocating
  +1 nothing consumes. Success = that growth goes ~flat under the collector,
  with byte-identical output.

## Design constraints (non-negotiable, from the plan)

1. **Liveness = reachability only.** Ignore refcounts for the collection
   decision — they are advisory (borrowed edges everywhere). Equally: do NOT
   "fix" the floating +1 at allocation/consumption sites — those floating refs
   are load-bearing safety padding for the refcount fast path (documented in
   the results doc/memory).
2. **Run only between frames** (VM quiescent: eval stack, `scope_chain`,
   `g_this_stack` empty — assert this at collector entry, bail if not).
   Low cadence (every M allocations or N ticks; make it tunable).
3. **Root set** (plan §Stage 3 has the full list): `global_object`;
   `root_movieclip.dynamic_props` + every live `child_mc_cache[i]`'s dprops
   (skip invalidated: `depth==INT_MIN` / `avm1_removed`); ALL ASFunctions —
   `function_registry` excludes anonymous ones (`action.c:56902`), so add an
   all-functions intrusive list first (functions stay immortal this session);
   subsystem-held borrowed refs: timer entries, watch callbacks, pending
   LoadVars/XML/MovieClipLoader/Sound callbacks, Selection state, broadcaster
   singletons, `g_*_constructor`/`g_stub_ctors` prototypes, soft-ref table if
   it holds object refs, and anything Stage 0's report classifies as reachable
   that the trace misses (use the classifier to FIND missed roots: any swept
   object that a subsequent access trips on is a missed root — see rollout).
4. **Tracing rules:** follow OBJECT/ARRAY-typed ActionVars in properties,
   elements, `arr->props`, `interfaces[]`, `__proto__`-as-property. Do NOT
   trace MOVIECLIP-typed values (non-owning, may dangle — never dereference)
   or FUNCTION-typed values (functions traced from the all-functions list).
5. **Two-pass teardown** for the doomed set: first neutralize outgoing
   retained refs of all doomed objects (so releases don't cascade into other
   doomed/live objects), then free. Do not reuse the recursive destroy paths
   as-is on swept objects.

## Rollout discipline (this is where the risk lives)

A missed root = freeing a live object = UAF that may surface far away. Ship in
this order, each step gated before the next:

1. **Count-only mode**: mark + report what WOULD be swept (class breakdown via
   the Stage 0 attribution), sweep nothing. Sanity-check against known-live
   workloads: anything "sweepable" immediately after allocation on an active
   path = missed root. Iterate here until the would-sweep set looks right.
2. **Quarantine mode** (env-gated): "swept" objects are poisoned (type tag +
   pattern) and parked, freed only K collections later; any access to a
   poisoned object aborts loudly with the object's tag. Soak the game set
   (N 5+ min demo, Minesweeper menu→game→restart, DJ, Tetris) + ASAN.
3. **Real free**, still behind a default-off env/compile flag; enable for the
   CI dispatch; only make it default-on if both CI modes are green AND the
   soak set is clean AND stdout is byte-identical everywhere.

If step 1 or 2 reveals a root-set hole you cannot close cleanly this session,
STOP there and land count-only/quarantine as the deliverable with findings —
that is a successful session; a default-on collector with a known hole is not.

## Known pre-existing failures (do NOT chase, do NOT misattribute)

The results doc documents three pre-existing bugs with repros: (1) attachMovie
`sprite_display_list` realloc invalidating aliased DisplayObject pointers (+
the ~14 MB HCALLOC growth / Minesweeper native OOM) — separate session;
(2) DJ native SEGV in `sprite_content_bounds_twips` on certain clicks;
(3) the `global_proto_decls` UAF (fails before and after). If ASAN trips on
these during soak, verify against clean HEAD before attributing to the
collector. Only collector-caused failures block this session.

## Verification

- Byte-identical game stdout + trace outputs at every step (destruction is
  unobservable; ANY diff = bug).
- Full CI both modes with the collector ENABLED for the dispatch (shared
  runtime code); zero pass→fail.
- ASAN soak of the game set in quarantine mode and again with real free.
- **Acceptance metric:** N title demo live-object growth ~flat (from
  +12 obj + 12 arr per frame); Minesweeper/DJ flat; `SWF_MEM_REPORT` numbers
  recorded in the results doc alongside the Stage 0–2 table.

## Close-out

Update the plan Status line (Stage 3 outcome + final flag state),
`plans/README.md`, append collector numbers to the results doc, write a memory
entry (root-set inventory + any holes found + flag state), pipeline end-to-end,
`.pipeline-state` done.
