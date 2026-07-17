# Session prompt — AVM2 raw-alloc reclamation (fix the residual ~39.5 KB/tick leak)

You are fixing the **residual AVM2 memory leak left after collectable strings**
(commit `c0e0b3493`, memory `avm2-collectable-strings`). With the object AND
string censuses dead flat, RWK gameplay still grows **~39.5 KB/tick**
(≈71 MB/min at 30 fps in the browser) — so long manual playthroughs still
eventually OOM, just later. The leak is **raw `avm2_alloc` churn**: allocations
that are neither census objects nor census strings. `heap_free` exists at only
~8 sites runtime-wide; everything else is allocate-and-abandon.

Read first: memories `avm2-collectable-strings` (the escape-surface map + the
measurement methodology), `avm2-stage11-gc` (sweep semantics you must not
regress — especially the "scope chains are shared, never freed" note, see
Verify-first below), and `ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`.

## Measured baseline (2026-07-16, commit `c0e0b3493`)

RWK native, plan_k gameplay TAS (menu → click → PlayState → full descent):
- allocated @1560 ticks = 129 MB; @3000 ticks = 192.6 MB → **39.5 KB/tick**
- object census flat (~85.6k live), string census flat (14,948 live) at both
  checkpoints → the growth is 100% census-invisible raw allocs.
- Menu-only is FLAT — the leak is PlayState-gameplay-path specific.

**Reproduction recipe** (a ready build may survive from the prior session at
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/d9a7df7b-cd94-41a5-9844-c7e15253c58d/scratchpad/`
— `rwk_build2/test_run` + `rwk_events.txt`; verify it predates no runtime
change before reusing, else rebuild):

```bash
# Build: game SWF as a fake test dir, keep the build
mkdir -p $SCR/games/rwk && cp ~/CC/newgrounds/529817_max_robotkitty.swf $SCR/games/rwk/test.swf
echo -n > $SCR/games/rwk/output.txt && echo 'num_frames = 1' > $SCR/games/rwk/test.toml
KEEP_BUILD_DIR=$SCR/rwk_build python3 ruffle-tests/verify_output_keep.py --test=rwk --tests-dir=$SCR/games
# Events: compile plan_k via ruffle-tests/_rwk_tas/rwk_drive.py helpers (see
# that README; the prior session's compiled rwk_events.txt is reusable as-is).
# Measure (TZ=NPT-5:45):
AVM2_MAX_TICKS=1560 AVM2_HEAP_STATS=1 ./test_run rwk_events.txt   # note "Allocated:"
AVM2_MAX_TICKS=3000 AVM2_HEAP_STATS=1 ./test_run rwk_events.txt   # delta/1440 = per-tick
```

## The suspects (full 171-site audit, 2026-07-16, line numbers at `c0e0b3493`)

Priority-ranked; (1) is very likely dominant — the Flixel HUD rewrites
score/FPS text every frame:

1. **EditText relayout tree leak** — `et_relayout` (avm2_text.c:3335) does
   `et->layout = layout` at :3363, abandoning the ENTIRE previous layout tree
   (LLayout :3275, lines array :2832, per-line boxes :2672, per-box char_end
   :2723) plus per-call scratch (`units` UTF-16 :3300, autosize `probe` — a
   second full tree — :3353). Called from ~15 setters; a per-frame `text=`
   write leaks a full tree every tick. `et->layout` is single-owner (assigned
   only at :3363) → free-old-tree-on-rebuild is safe; also free units/probe.
   CAVEAT: confirm no caller caches an `et_layout()` pointer across a
   mutating setter.
2. **Closure scope-chain leak** — `avm2_op_newfunction` (avm2_ops.c:2466) →
   `avm2_scope_capture` (avm2_class.c:707) allocates Avm2ScopeChain :711 +
   entries :716 into `fnobj->fn_scope`; `free_innards` (avm2_gc.c) never
   frees fn_scope, so every per-frame `function(){}` / comparator leaks its
   chain even after the closure is swept. **VERIFY-FIRST (UAF risk):** the
   stage-11 memory says "scope chains — shared across closures; NEVER freed".
   The audit claims scope_capture always allocates fresh (unaliased). Resolve
   this definitively before freeing: check every fn_scope assignment site,
   `method_scope` in vtables, cls->scope/iscope, and whether an activation's
   outer chain can alias a swept closure's chain. If ANY aliasing exists,
   refcount or skip this item — over-retain, never free shared.
3. **DynProp tombstone growth** — `avm2_object_delete_dynamic`
   (avm2_object.c:125) tombstones (`dead=1`, stays linked); the set path
   (:90) skips dead nodes, so delete→re-add on a LIVE long-lived object
   (FlxG singletons, pooled sprites) allocates a fresh node + name string
   every cycle and grows the chain unboundedly. Fix: resurrect a matching
   dead node on re-add (safe); freeing on delete needs the enumeration-cursor
   check (`dyn_enum_pos`, avm2_object.c:414/433 — the tombstone exists FOR
   in-flight enumerators, don't break that semantic).
4. **Activation/catch vtable+class leaks** — `avm2_op_newactivation`
   (avm2_ops.c:2482) allocates a fresh Avm2VTable per activation;
   `avm2_op_newcatch` (:2507 vtable, :2529 Avm2Class) per typed-catch entry.
   `free_innards` never frees `o->vtable`. Per-call in hot paths. Freeing
   vtables at sweep is only safe for these per-object vtables — most objects
   share `&cls->ivtable` (do NOT free that!): distinguish ownership (e.g. an
   `owns_vtable` flag set at the two alloc sites).
5. **Per-call scratch (free-at-return, easy wins)** — sort scratch
   (avm2_array.c:881/882/907, avm2_vector.c:1197 — per-tick if Flixel sorts
   groups); BitmapData.draw(TextField) glyph path (`gl` avm2_text.c:3517
   never freed by its caller avm2_bitmap.c:1765; `units` :3473; xs/ys/cx/cdir
   avm2_bitmap.c:1804-1807 — per-tick when the HUD is blitted); plus the
   long tail of B-class scratch (JSON/AMF/regexp/bytearray/e4x builders) —
   fix opportunistically, they're per-call bounded unless hot.

NOT the leak (audited): number→string formatting (stack buffers + census
strings); capacity-doubling element arrays (warmup-bounded; old buffers
are single-owner and can be freed-after-memcpy as a bonus, but they don't
produce steady-state growth); load-time class/vtable/ABC setup.

## Method — measure, fix, attribute, repeat

1. Fix suspect (1) first, remeasure the 1560→3000 delta, and record the
   attribution. Then (5)'s per-tick items, then (3)/(4), then (2) only after
   the aliasing question is settled. Don't fix blind — each fix's measured
   share goes in the session memory.
2. Every free you add must state WHY the allocation is unaliased at that
   point (single-owner proof). When in doubt, don't free — this codebase's
   rule is over-retain, never dangle.
3. Freeing at GC sweep time goes in `free_innards`/ext hooks; freeing at
   scope exit goes at the alloc site's function end. Remember collects run
   only BETWEEN ticks — a mid-tick `heap_free` of true scratch is fine (it's
   not GC-observed memory), but never free anything a Value/census structure
   can still reach.

## Grading (same bar as collectable strings — over-verify)

- **AVM2_GC_STRESS=1 locally** on an avm2 sample + the two
  `avm2_gc_string_*` regression tests + RWK plan_k gameplay: traces must stay
  byte-identical (normal / stress / AVM2_GC=0), no crashes. ASAN +
  `-DHEAP_PASSTHROUGH` if anything smells (the stage-11 diagnosis recipe).
- **Soak target:** RWK gameplay 1560→3000 ticks allocated delta ≈ **flat**
  (< a few KB/tick; record before/after per-tick numbers in the memory).
  Also re-check Seedling menu stays flat and the boot spike stays ~129 MB.
- Consider a regression test if a fix has a trace-visible failure mode
  (e.g. tombstone resurrection changing for-in order — Flash order semantics
  must hold; see array_shift/sort memories for the policy precedents).
- **BOTH CI modes + a no-graphics avm2_gc=1 stress dispatch, zero pass→fail**
  (the strings session precedent: stress run first, it found nothing only
  because local stress was thorough).
- After it lands: **FRESH=1** rebuild + redeploy the three AVM2 wasm demos
  (rwk, seedling, seedling_teleport_ap) + restage Archipelago-CC's
  seedling_teleport_ap (recipe in `avm2-collectable-strings` memory; FRESH=1
  is mandatory only if struct layouts change — plain .c fixes just need the
  incremental rebuild, but verify which applies).

## Boundaries

- Core runtime only (`SWFModernRuntime/src/avm2/`); do NOT touch AVM1.
- Don't regress stage-11 object-sweep or collectable-strings semantics
  (collect-between-ticks; over-retain on mark-OOM; string census invariants).
- E4X nodes stay immortal (making them collectable is a separate project).
- The `Avm2DynProp.name` → `const Avm2String*` pointer refactor (review
  follow-up in `avm2-collectable-strings`) pairs naturally with item (3) —
  optional, only if it stays low-risk.

Finish per `.claude/pipeline-handoff.md`; update the avm2 suite
`CURRENT_STATUS.md`; write a session memory with per-fix leak attribution and
the final KB-per-tick number.
