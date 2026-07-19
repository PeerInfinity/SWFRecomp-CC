# Session prompt — RWK store path + own-class statics (levers 3+4 of the property arc)

Fourth leg of the RWK perf arc. Prior legs (read
`tools/divergence/perf/RWK_AB_STATUS.md` FIRST — it carries the full A/B
log, profiles, and method): GC adaptive watermark; find scope-hit IC
(`8caf10e4e`, 1.54x native); compile-time find→this resolution
(`2c6461be2`, 1.25x native Ir, rig p50 130→105 ms). Current state: rig
gameplay ~105 ms p50 vs Ruffle's 6.4 ms anchor and the 33 ms goal — this
session's job is the next honest 1.2-1.4x, one lever at a time.

Post-lever-2 native residue (73.19B Ir, callgrind 600t GC=0, table in
RWK_AB_STATUS): **coerce cluster ~10.9%** (to_class 3.39 + to_number 3.34
+ to_type_mn 3.20 + class_for_mn 1.69), **name-resolution residue ~12.3%**
(mn_match 3.99 + vtable_find_mn 3.90 + propkey_matches 2.34 + mn_name 2.08
— the REMAINING find/IC sites: getlex + own-class statics), **SET ~6.3%**,
blit ~7.2% (native-scalar-inflated), getproperty IC-hit residue ~11%
(6.0 + 5.15 — post-slot-spec floor), alloc/ctor ~4.9%.

## Prep data (2026-07-19, current recompiled RWK, post-lever-2)

Emitted-op census of `~/CC/rwk_build/recompiled/RecompiledABC`:
- `findprop_this` 3,343 (lever 2) vs **`findpropstrict_ic` 2,739 REMAINING**
  — last session's hot-cluster census said own-class STATICS are 24.7% of
  hot finds (getlex 8.6%). These remaining sites feed most of the 12.3%
  name-res residue.
- GET: `getproperty_slot` 1,981 / `getproperty_static_ic` 3,766.
- **SET is completely un-specialized**: `setproperty_static_ic` 677 +
  slow `setproperty` 774 + `initproperty` 1,044; there is NO set-slot op
  at all today (`setproperty_resolved` is runtime-internal). Last
  session's caller attribution: setproperty_resolved 67% under
  op_initproperty (constructor-time stores in the quadtree churn) with
  coerce_to_type_mn 49% of the store path.
- 727 emitted `coerce` sites (the Step-4 elision already prunes
  statically-proven no-ops; the hot cost is RUNTIME-internal coercion on
  the store path + to_number in arithmetic).
- Class objects are per-class singletons, pinned in the GC (avm2_gc.c
  clear pass seeds pins; they are never swept) → their pointers are
  stable for the life of the ctx. A per-site one-time cache of the
  enclosing class's class_object needs at most a ctx-identity guard
  (Seedling lever-A precedent).

## Step 0 — census before code (mandatory, three sessions proven)

1. Re-run `SWF_CENSUS_PROPREAD=<path>` (abc_emit.cpp, kept from lever 2;
   writes per-tag `.N` files) on RWK at HEAD: classify the 2,739
   remaining find sites — own-class static / getlex / other — and weight
   by the hot methods (m484/486/482/487 cluster + the post-lever-2
   callgrind annotations in the session scratchpad).
2. Extend the census to the STORE side: for every SetProperty/InitProperty
   site, can the receiver's static type + trait be resolved compile-time
   (this / typed instance / class-static), is it a SLOT (not
   getter/setter), is the declared slot TYPE statically satisfied by the
   operand (making the runtime coerce a provable no-op)? Count sites and
   weight by hot methods. InitProperty on a just-constructed known class
   is the churn path — expect it hot.
3. Blit gate: temp `-DAVM2_BLIT_COUNT` branch tally (the seedling-blit-simd
   Step-1 tool) on RWK gameplay — does Flixel's blit hit the SIMD span
   kernels (opaque-dest blend_over / raw copy), or a branch the spans
   don't cover? (Native Ir overstates blit — native builds run the scalar
   fallback; judge engagement + wasm CDP share, not native %.)

## Candidate levers — build ONE at a time, gate each on its census number

A. **find→class-static bake** (the direct lever-2 analog for the statics
   bucket): when the site multiname statically resolves to a declared
   STATIC trait of the ENCLOSING class (statics are not inherited — no
   subclass-shadowing concern; explicit slot_or_disp_id honored) and the
   method preamble qualifies (same gates as find→this), the scope walk
   provably hits the class object on the outer chain → emit a baked
   class-object reference (per-site one-time cache + ctx guard, or a
   direct `cls->class_object` handle if the generated code can reach the
   class struct), and let the following GetPropertyStatic slot-specialize
   through the existing lever-B static-slot machinery
   (`computeStaticSlotIndex` mirrors runtime cvt numbering — reuse it and
   its `-DAVM2_SLOT_VERIFY`). Kills both the find call AND the IC getprop
   for those sites. Prize: large share of name-res ~12.3% + part of
   getproperty_static_ic 6.0%.
B. **Store-path slot spec + store-coerce elision (lever D):** a new
   `avm2_op_setproperty_slot` / init variant for sites whose receiver
   type + slot index are compile-time constants (mirror the GET gate
   list: sealed, no subclass redeclare for instance receivers, exact
   runtime slot-index match, exclude getters/setters), PLUS compile-time
   elision of the declared-type coerce when the operand's static type
   provably satisfies it (reuse the Step-4 abstract-interp typing; the
   elide rules from `seedling-perf-compile-time-specialization` — exact
   primitive match, subtype-class allow, never Object/*/native). Needs a
   new `-DAVM2_SET_VERIFY` cross-check (store both ways is NOT an option —
   verify by resolving and comparing target slot + coerced value BEFORE
   the store). Prize: SET ~6.3% + coerce_to_type_mn 3.2% + a slice of
   to_class/class_for_mn.
C. **coerce_to_number residue** (3.34%): only if the census shows a
   statically-typed arithmetic pattern worth a recompiler bake
   (Seedling's never-built "typed-Number arithmetic spec"); otherwise
   note-and-skip.
D. **Blit**: only act on what the Step-0 tally shows (a missed branch →
   extend the span kernels under the same byte-exactness bar
   (`(x*32897)>>23` trick, `-DAVM2_BLIT_VERIFY`, 0-mismatch fuzz);
   engaged-and-hot → note the wasm share and move on).

GC stays out of scope (tier-2 prompt `avm2-gc-collector-cost.md`).

## Method rules (unchanged from the arc — deviate only with a reason)

- Native first: callgrind Ir (600t GC=0) + user-s (2900t, interleaved ×3)
  size each lever; coverage counters before intuition; the plan_k TAS is
  the workload (TZ=NPT-5:45; rebuild recipe in RWK_AB_STATUS).
- Rig A/B: real-GPU Windows Chrome via `python.exe` + Playwright
  (`WINDOWS_PLAYWRIGHT_FROM_WSL.md`); driver
  `/mnt/c/playwright/rw_scope_ab/rw_ab.py` (rw_perf.py hangs); metric
  `__swfPerf.cpu` gameplay p50, ≥5 interleaved rounds; RWK gameplay is
  bimodal ±30% — only same-session interleaved ratios are honest.
  WebGPU screenshots read back blank on this rig; gate on __swfPerf.
- Correctness bar per lever: dedicated verify build (existing
  `AVM2_FIND_VERIFY`/`AVM2_SLOT_VERIFY`, new `AVM2_SET_VERIFY`) clean over
  ≥1200 TAS ticks AND a full verify-defines CI run (the lever-2 session's
  precedent); traces + 600 CPU-dump frames byte-identical
  normal/stress/GC=0 and vs the post-lever-2 dumps; new semantics pinned
  by a regression test in `ruffle-tests/tests/swfs/regression/` (the game
  is never the oracle); both CI modes zero pass→fail (avm2 823/1215
  baseline).
- KNOWN GAP (do not "fix" in passing): the runtime conflates empty-uri
  private namespaces (Base/Sub private shadowing reads the subclass slot;
  Flash keeps them distinct) — documented in
  `regression/avm2_findprop_this_resolution`'s README. A static-slot SET
  lever must use the same ns-matching the GET levers use (mirror
  avm2_mn_match), not invent stricter matching that diverges from the
  runtime it must agree with.
- mxmlc cannot reproduce the old-ASC findprop patterns (lever-2 gotcha) —
  regression tests pin semantics; upstream avm2 tests + the games cover
  the pattern.
- ABI TRAP: any struct the generated TUs instantiate by value → FRESH=1
  full wasm rebuilds everywhere (incremental .o reuse ships a
  boots-then-corrupts wasm).
- Finish per `.claude/pipeline-handoff.md`: redeploy all AVM2 demos on a
  recompiler/runtime change (FRESH), restage Archipelago-CC flashPanel if
  a staged .c changed, update RWK_AB_STATUS.md (same table format), write
  the session memory. If time allows, one Seedling rig spot-check is
  worth recording (lever 2 gave it 3,376 new sites unmeasured; lever A/B
  here may add more).

## Budget note (delegation)

Fable-led. Opus subagents: rebuilds, TAS/callgrind runs, rig A/B legs,
CI watching. Fable: census interpretation, gate decisions, emitter/runtime
code, ns/slot-semantics arguments, reading distributions.
