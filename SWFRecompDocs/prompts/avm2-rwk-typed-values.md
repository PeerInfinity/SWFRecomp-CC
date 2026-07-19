# Session prompt — RWK typed-value emission (coerce + compare + boxed-dispatch cluster)

Fifth compute leg of the RWK perf arc. Read
`tools/divergence/perf/RWK_AB_STATUS.md` FIRST (A/B log, profiles, method).
State after the property levers (`a2e4758fb`) + GC tier-2 (`bf4f45671`):
rig all-frames gameplay mean 81.6 ms, >250 ms stalls ZERO, GC pause ~23 ms
native / trace-dominated. Ruffle anchor 6.4 ms. The wall is back to pure
compute, and the post-lever-3+4 callgrind map (46.23B Ir, GC=0) names one
coherent cluster ≈ **25% of all Ir**:

- **coerce ~15%**: to_number 4.68 + to_class 2.79 + to_type_mn 2.76 +
  to_boolean 2.36 + to_primitive 2.10
- **abstract_eq/lt 6.85% + xml_abstract_eq 2.57%** (comparison dispatch)
- plus the boxed arithmetic entry points feeding them (op_add etc.)

These are all the same disease: every branch, compare, and arithmetic op
round-trips boxed Avm2Values through generic dispatch, then coerces. The
slot levers made typed reads/writes cheap; the values BETWEEN them are
still fully dynamic.

## Prep data (2026-07-19, current recompiled RWK + runtime)

- Emitted op counts (RecompiledABC): `avm2_coerce_to_boolean` **1,326**
  (every iffalse/iftrue funnels through it), `avm2_op_add` 625,
  `avm2_op_equals` 419, lessthan 223, subtract 221, multiply 175,
  greaterthan 152, increment 83, ge/le ~91, strictequals 24; 2,207
  `avm2_integer(` + 3,102 `avm2_object_value(` boxing sites.
- **Cheap confirmed win:** `avm2_abstract_eq` (avm2_value.c, "E4X arms
  come first") unconditionally calls `avm2_xml_abstract_eq(ctx,a,b,..)`
  AND `(ctx,b,a,..)` on EVERY abstract equality — 2.57% of total Ir in a
  game with zero E4X. A kind pre-check (only call when an operand can be
  XML/XMLList/QName-ish — object-kind test before the probe) should
  recover most of it, runtime-only. Mind the Ruffle ordering comment
  (empty XMLList == undefined: the guard must not skip cases where ONE
  operand is XML-ish and the other is undefined/primitive).
- Seedling's `coerce_to_class` memo is ALREADY SHIPPED runtime-wide
  ([[seedling-coerce-class-memo]] memory) — RWK's to_class 2.79% is
  post-memo residue; don't rebuild that lever, find what misses it.
- Seedling's "typed-Number arithmetic spec" was scouted (~2-4% there) but
  NEVER BUILT; in RWK the same cluster is ~25%. The type lattice it needs
  already exists: `analyzeSlotSpec`'s forward abstract-interp
  (per-stack-slot static types, extended with null literals in lever 3+4)
  — slot reads are now typed, so operand types ARE available at compare/
  arith/branch sites.
- Also on the map, second priority: **alloc/ctor ~10%**
  (slots_init_defaults 4.14 + setup_locals 3.58 + o1heapAllocate 2.25) —
  both _defaults and _locals are per-element loops that could become
  per-class/per-method precomputed template images + memcpy.

## Step 0 — census before code (arc law)

Extend/reuse the abc_emit census tooling (`SWF_CENSUS_PROPREAD` pattern):
for every compare / iffalse-iftrue / add / sub / mul / inc-dec site,
classify the operands' static types from the existing lattice
(Number-Number, int-int, Boolean, mixed/unknown, possibly-String for add)
and weight by the hot methods (m484/486/482/487 + the post-lever-3+4
callgrind annotations). The build decision per lever is its hot-weighted
coverage number, not the site count.

## Levers (gate each on census; one at a time; A/B each alone)

A. **XML-probe guard in abstract_eq** (runtime, ~1 hour, do it first as
   the warm-up): kind gate before the two xml_abstract_eq probes.
   Bar: traces byte-identical everywhere INCLUDING the E4X suites (the
   avm2 upstream tests cover XML == extensively — they are the oracle).
B. **Typed branches**: iffalse/iftrue where the operand is statically
   Boolean (or a compare result) → direct test, no
   avm2_coerce_to_boolean call. 1,326 sites; likely the widest lever.
C. **Typed comparisons**: lt/gt/le/ge/equals where BOTH operands are
   statically Number/int → direct double/int compare.
   SEMANTICS LANDMINES (each needs a regression test):
   - NaN: abstract_lt returns UNDEFINED → both `if (a<b)` and `if (a>=b)`
     branch FALSE on NaN. A naive C `<`/`>=` pair gets `>=` wrong. Mirror
     the exact branch-op semantics (iflt vs ifnlt are different ops!).
   - -0 == +0; int/uint mixed widths promote to double; equals on
     Number-vs-int must match abstract_eq's numeric path.
D. **Typed arithmetic**: add/subtract/multiply/increment where operands
   are statically Number/int → direct double math, boxing only the
   result (or feeding a typed store/compare directly where adjacent).
   `add` is the dangerous one (String concat / dynamic dispatch): gate
   add STRICTLY on both-sides-numeric-typed; sub/mul/inc are
   numeric-only by spec and safer.
E. (second cluster, if census+time allow) **ctor templates**:
   slots_init_defaults → per-class precomputed default-slot image
   (memcpy + patch), setup_locals → per-method template. Pure runtime
   restructuring, no semantics; measure before building — o1heapAllocate
   2.25% is NOT addressable here (that's tier-2 lever 4 / generational).

Verify pattern for B/C/D: `-DAVM2_ARITH_VERIFY` — every specialized
compare/branch/arith ALSO runs the generic path and aborts on divergence
(the FIND/SLOT/SET/COERCE precedent; run the all-verify-defines CI on top
of both normal modes).

## Method rules (the arc's, binding)

- Native first: callgrind Ir (600t GC=0) + user-s (2900t ×3 interleaved)
  size each lever; coverage counters, not intuition; plan_k TAS workload
  (recipe in RWK_AB_STATUS; TZ=NPT-5:45).
- Rig A/B: `rw_ab.py` driver, `__swfPerf.cpu`, ≥5 interleaved rounds,
  same-session ratios only. POST-GC-TIER2 NOTE: lazy sweep amortizes 2-3
  ms/tick into frames — judge on all-frames mean + p50 + stall count
  TOGETHER (the p50-alone trap is documented in RWK_AB_STATUS).
- Include Seedling + rwp rig spot-checks: B/C/D are recompiler-wide and
  Seedling has never been re-measured since it silently gained the
  lever-2/3 sites — one before/after there closes that loop.
- Regression tests in `regression/` for every semantic edge shipped
  (NaN branch pairs, add-concat gate, -0, uint promotion); the game is
  never the oracle.
- ABI TRAP: struct-by-value changes in generated TUs → FRESH=1
  everywhere; re-probe padding claims per change (the gc_mark u8→u32
  padding fit was verified, not assumed — same standard).
- Finish per `.claude/pipeline-handoff.md`: both CI modes + verify-CI,
  zero pass→fail (avm2 823/1215 baseline; regression 55 at 100%), all 7
  demos FRESH-redeployed on recompiler/runtime change, Archipelago-CC
  flashPanel restaged, RWK_AB_STATUS updated (same table format),
  session memory written.

## Budget note (delegation)

Fable-led. Opus subagents: rebuilds, TAS/callgrind legs, rig rounds, CI
watching. Fable: census reading, lattice/gate design, the NaN/concat
semantics arguments, every specialized-op emission decision.
