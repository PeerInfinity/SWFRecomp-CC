# RWK base-compute perf arc — status & A/B log

Sessions 2026-07-19 (lever 1: `avm2-rwk-base-compute-profile.md`; lever 2:
`avm2-rwk-property-read-endgame.md`; levers 3+4:
`avm2-rwk-store-and-statics.md`; lever 5: `avm2-rwk-typed-values.md`).
Precedent/format: `SEEDLING_AB_STATUS.md`. All rig numbers: Windows Chrome,
real GPU (intel gen-9), driven from WSL via python.exe + Playwright
(`WINDOWS_PLAYWRIGHT_FROM_WSL.md`); metric `__swfPerf.cpu` gameplay p50
unless noted. All native numbers: solo -O2 no-graphics build, RWK plan_k
TAS (`_rwk_tas`), TZ=NPT-5:45.

## Headline — lever 5 (typed-value emission: compare→branch fusion + inline fast arms, 2026-07-19)

Session prompt `SWFRecompDocs/prompts/avm2-rwk-typed-values.md`, commit
`a35afa7b8`. Target: the ~26% coerce/compare cluster the post-lever-3+4
profile named (to_number 4.67 + to_class 2.79 + to_type_mn 2.75 + to_boolean
2.36 + to_primitive 2.09, abstract_eq 3.64 + abstract_lt 3.19,
xml_abstract_eq 2.57) — every branch, compare and arithmetic op round-tripped
a boxed Avm2Value through generic dispatch, then coerced.

| measurement | before (`20e22c605`) | after | win |
|---|---|---|---|
| native Ir, 600 ticks GC=0 (callgrind) | 46.34B | 40.28B | **-13.1% (1.15x)** |
| native user-s, 2900 ticks GC=0 (8 interleaved rounds) | 25.06 mean (r2-8) | 23.51 mean | ~1.07x; median paired ratio 1.10 |
| rig gameplay all-frames mean (5 interleaved rounds, median) | 83.8 ms (75.2–99.1) | **74.7 ms** (66.9–78.2) | **1.12x** |
| rig gameplay cpu p50 (median of rounds) | 77.9 ms (74.1–98.0) | **72.3 ms** (60.8–76.3) | **1.16x** |
| rig gameplay cpu p95 (median of rounds) | 115.4 ms (96.3–124.6) | 94.6 ms (87.9–109.7) | 1.10x |
| rig frames > 250 ms (total over 5 rounds) | 3 | 3 | unchanged — GC collects, not this lever |

Rig paired per-round ratios (base/after) — **after wins mean_all and p50 in
5 of 5 rounds**; the only sub-1.0 cell anywhere is r1's p95:

| rnd | mean_all | p50 | p95 |
|---|---|---|---|
| r1 | 1.082x | 1.065x | 0.962x |
| r2 | 1.142x | 1.158x | 1.309x |
| r3 | 1.124x | 1.219x | 1.096x |
| r4 | 1.267x | 1.284x | 1.317x |
| r5 | 1.122x | 1.072x | 1.089x |

(Regime mostly tight — base p50 74.1–78.7 for four rounds, r4 alone at 98.0
with its after arm rising too, so ±15% rather than the ±30% bimodal
sessions. Both A/B demos deployed under fresh names `rwk_tv_base` /
`rwk_tv_after`, FRESH=1 full rebuilds both sides — the `rwk_ap` reference
demo was not touched. Raw JSONs: `/mnt/c/playwright/rw_tv_ab/`.)

**The design decision that matters: runtime-checked, NOT type-gated.** The
Step-0 census (new `SWF_CENSUS_TYPEDOPS=<csv>` hook in `analyzeSlotSpec`,
reporting the operand static types the lattice already computes — 3,395 rows
over RWK) found only **31% of fused compare sites have BOTH operands
statically numeric**, and 68% of branches a statically-Boolean operand. A
compile-time-gated lever — what the session prompt's levers B/C/D sketched —
would have captured just that slice. So the fast arms are not gated on the
lattice at all: each helper in `avm2_ops.h` is exactly equivalent to the op
it shortcuts FOR ALL INPUTS (the fast arm decides only the kinds it can
decide locally; every other kind falls through to the same generic
implementation). Coverage is 100% of sites for one predictable branch, and
the census's role became sizing/justification rather than gating.

- **Compare→branch fusion** (recompiler, structural — no types involved).
  The ABC verifier already splits every compare-and-branch bytecode
  (`iflt`/`ifnlt`/`ifeq`/...) into a comparison op immediately followed by
  IfTrue/IfFalse (`abc_verifier.cpp`), so the pair is the dominant branch
  shape: census says **562/834 compares (67%) are branch-adjacent**. Fusing
  emits one `sp -= 2; if (avm2_op_lessthan_test(act, stk[sp], stk[sp+1]))
  goto op_N;`, removing both the `avm2_bool()` boxing and the
  `avm2_coerce_to_boolean()` that read it straight back. RWK: **489 fused**
  (not fused when the branch is itself a branch target, or in methods with
  active exception bookkeeping) + **785 standalone branches** on the boolean
  fast arm.
- **Numeric fast arms** for subtract/multiply/divide/increment/decrement/not.
- **XML-probe guard in `abstract_eq`** (runtime). The E4X arms ran five ext
  probes on EVERY abstract equality — 2.57% of total Ir in a game with zero
  E4X. The object-kind gate is exact, not heuristic: every probe tests
  `kind == AVM2_VALUE_OBJECT` first, so `avm2_xml_abstract_eq(a,b)` needs `a`
  to be an object, the mirrored call needs `b`, and the QName arm needs both;
  the asymmetric cases the Ruffle ordering comment protects (empty XMLList ==
  undefined) keep one object operand and still enter.
- **Numeric fast path in `abstract_lt`**, equally exact
  (`coerce_to_primitive` is the identity on non-objects; two numbers are
  never both strings).

**`add` was tried and REVERTED — the verify build caught it.** A both-numeric
`add` arm looks equivalent by the same argument, but `avm2_op_add_values`
already has an int+int arm returning an **INTEGER-kind** value, which the
naive arm flattened to NUMBER — an observable kind difference.
`-DAVM2_ARITH_VERIFY` aborted within 1200 ticks. `add` keeps the generic op.

**Verification:** `-DAVM2_ARITH_VERIFY` (new — every specialized arm also
runs the generic op and aborts on divergence) clean over 1200 ticks
default-GC, 800 ticks GC=0 and 400 ticks GC-stress, zero aborts; RWK trace
AND all **600 CPU-dump frames byte-identical** to a clean-worktree HEAD
baseline (trace `64bdde47…`, frames `653ecf8e…` on both sides); new
regression test `regression/avm2_typed_value_ops` (mxmlc + Ruffle exporter
oracle) pins NaN branch pairs, signed zero, int/uint/Number width promotion,
the add-concat gate, every `coerce_to_boolean` rule and unary-on-non-numbers.

**Ir vs wall-clock, honestly:** -13.1% Ir bought only ~1.07x native user-s —
the instructions removed are cheap and well-predicted (a call + a switch)
while the remaining work is memory-bound, so native time under-reflects the
count. The rig read slightly BETTER than native user-s (1.12x mean / 1.16x
p50), the usual wasm amplification of instruction-count wins, but nowhere
near the Ir ratio. Treat this lever as a genuine ~1.1x, not a 1.15x.

**Post-lever profile (40.28B Ir):** `coerce_to_boolean`, `abstract_lt` and
`xml_abstract_eq` have left the top-25 entirely; `coerce_to_number` 4.67 →
1.19, `abstract_eq` 3.64 → 2.48. `blend_over` is now #1 at 6.82% (pure pixel
work; wasm runs the SIMD spans). **The largest addressable cluster is now
alloc/ctor: `slots_init_defaults` 4.76 + `setup_locals` 4.10 +
`o1heapAllocate` 2.58 = 11.4%** — the session prompt's lever E, unbuilt.
Sketch: `slots_init_defaults` is a per-element loop that could become a
per-class precomputed default-slot image + memcpy, but ONLY for slots whose
default is a non-pointer kind — a template holding a string/object pointer
would be an un-traced GC root (see [[avm2-collectable-strings]]).
`setup_locals` recomputes a per-call `unchecked` flag from method-static data
every call; that is a pure per-method memo.

## Headline — GC tier 2 (collector per-object cost: bitmap + epochs + lazy sweep, 2026-07-19)

Session prompt `SWFRecompDocs/prompts/avm2-gc-collector-cost.md`. The base-compute
arc took RWK gameplay to 69 ms/frame while the GC pause stayed put, so the
collect became ~30-40% of wall-clock. Three levers, each measured on its own
with the new per-collect phase timer (`AVM2_GC_TIME=1`, now permanent in
avm2_gc.c), RWK plan_k TAS, 600 ticks, solo -O2 native:

| build | pause | snap | strsnap | trace | sweep | strsweep |
|---|---|---|---|---|---|---|
| HEAD `a2e4758fb` (re-baseline) | **73 ms** | 36.5 | 2.1 | 11.2 | 21.8 | 1.2 |
| + lever 1 arena bitmap | 55.5 | 19.8 | 2.1 | 10.1 | 22.0 | 1.1 |
| + lever 2 epoch marks | 40 | **0.02** | 2.2 | 11.5 | 24.4 | 1.2 |
| + lever 3 lazy sweep | **21-25** | 0.02 | 2.5 | 15.5 | 2.6 | 1.5 |

**3.2x smaller stop-the-world pause** (73 → ~23 ms native; the 5x wasm
multiplier puts the browser hitch at ~365 → ~115 ms). The residual sweep work
is amortized at ~2-3 ms/tick over the ~11 ticks after each collect.

- **Lever 1 — arena membership bitmap.** The conservative ext scan's
  "does a census object start here?" test was a binary search over a sorted
  snapshot REBUILT (walk + qsort) every collect — half the pause at a 284k
  census. Replaced by 1 bit per allocation-alignment cell of the o1heap arena,
  set on enroll / cleared on sweep (16 MB for the 4 GB native arena, calloc'd
  so pages materialize only where objects live). New `heap_arena_base/span/
  alignment()` accessors; HEAD's snapshot path survives as the fallback for
  HEAP_PASSTHROUGH (sanitizer) builds, which have no arena.
- **Lever 2 — epoch marks.** `gc_mark` widened uint8 → uint32 **into padding
  that was already there** (sizeof and every offset unchanged, verified native
  AND wasm32 — no FRESH rebuild needed): bit 0 = pinned, bits 1.. = mark epoch.
  Bumping the epoch whitens the entire census in O(1), so the clear walk is
  gone; pins moved to their own append-only array to seed the worklist.
  `avm2_gc_is_marked()` replaces the one external `gc_mark & 1` reader
  (the display orphan prune).
- **Lever 3 — lazy sweep.** Marking stays atomic between ticks; the sweep runs
  from a resumable cursor at `AVM2_GC_SWEEP_BUDGET` census entries per tick
  (default 25 000 ≈ 2 ms; 0 = eager, the A/B kill switch, forced under
  `AVM2_GC_STRESS`). Objects allocated during a sweep enroll in a nursery and
  are born black, so the cursor never meets them; the nursery splices back when
  the cursor finishes, and no mark can start before that. Safety valve: below
  1/8 arena headroom the sweep runs eagerly (rwic lives at ~96% of its arena —
  an allocation failure is fatal, a long pause is not).

**Rig (Windows real-GPU Chrome, 5 interleaved rounds, RWK gameplay window):**

| metric | base (HEAD) | after | |
|---|---|---|---|
| frames > 250 ms per round | **6** (463–820 ms each) | **0** | the collect hitch is gone |
| mean cost over ALL gameplay frames | 103.5 ms | **81.6 ms** | **1.27x** |
| cpu p50 (median frame) | 72.7 ms | 83.1 ms | 0.95x — the trade |
| cpu max | 820 ms | 155 ms | |

Same picture on the other two rig games (3 interleaved rounds each, all-frames
mean / total >250 ms frames): **rwp 64.8 → 54.8 ms, 14 stalls → 0**;
**seedling 26.0 → 22.7 ms, 1 stall → 0** — the low-churn control improved too,
so no game pays for this.

The p50 REGRESSION is the lever working as designed: ~2-3 ms/tick of native
sweep (×5 in wasm) moved out of the half-second freeze and into the ~11 ticks
that follow it. Judge this lever on the all-frames mean and the stall count,
not p50 — and note the rig is bimodal ±30%, so only the paired per-round
comparisons above count (base p50 alone ranged 68–95 across rounds).

Open tuning knob: the budget (25 000 entries/tick) empties the census in ~11 of
the ~35 ticks between collects. A smaller budget would spread the same work
thinner (lower p50, longer sweep window) — untested; 25 000 was chosen for
3x margin against the sweep failing to finish before the next collect is due.

**Verification (native):** traces byte-identical to HEAD at 600 and 1200 ticks
across normal / stress / GC=0; **600 CPU-dump frames byte-identical**; collect
cadence, census size, swept counts and total-alloc all identical to HEAD
(47 collects / 1200 ticks either way — retention unchanged, the lazy sweep
always finishes well inside the interval); maxRSS 1212 MB → 1209 MB; the three
`avm2_gc_*` regression tests pass in all three GC modes.

## Headline — levers 3+4 (own-class-static bake + store-path slot spec, 2026-07-19)

**Three levers in one commit** (each independently toggleable at recompile
time):

- **Lever A — find→own-class-static bake** (`SWF_NO_FIND_STATIC=1` off):
  adjacent `findpropstrict(mn); getproperty(mn)` of a static Slot/Const of
  the ENCLOSING class (old-ASC's unqualified-static-read shape AND mxmlc's
  `getlex` lowering) fuses into `avm2_op_getlex_ownstatic` — a per-site
  guarded cache (ctx + outer-chain identity + `this`-vtable identity,
  populated only when the full walk lands on the expected class object,
  `file->classes[i]->class_object`) + a bare static-slot read
  (`computeStaticSlotIndex` cvt mirror). Non-adjacent consumers (static
  stores) get `avm2_op_findprop_ownstatic` (guarded find only). Soundness
  is RUNTIME-guarded — cross-file subclass shadowing / native-ancestor
  traits fall back to the exact full walk; the compile gate is the
  find→this preamble gate + ns-aware `staticSlotForMn` + NOT
  `chainDefinesMn`. RWK: 131 fused + 20 standalone (findpropstrict_ic
  sites 2,739 → 2,588).
- **Lever B — store-path slot spec + store-coerce elision**
  (`SWF_NO_SET_SLOT=1` off): SetPropertyStatic/InitProperty whose receiver
  is `this` (directly or via a find→this-substituted find) or a
  statically-typed ABC instance, under the GET-lever gate list (sealed,
  ns-aware chainDefinesMn, unique slot, no subclass redeclare, exact ABC
  index, const only via init) → `avm2_op_setproperty_slot` (declared-type
  coerce proven a value no-op — Step-4 rules + new TK_NULL: null literal →
  class/String targets) or `_slot_c` (coerce kept, compile-time type mn).
  Null receivers route through the full generic path for the exact throw.
  New `-DAVM2_SET_VERIFY` resolves + cross-checks slot AND coerced value
  BEFORE the single store. RWK: 837 sites (452 elided + 385 coercing);
  initproperty sites 1,044 → 449 — the FlxQuadTree/FlxList ctor churn was
  initproperty with NO IC doing a full resolve per store.
- **Blit identity-self-copy skip** (avm2_bitmap.c): the Step-0 gate tally
  (blit branch counters, 600t) showed spans engaged for ~64% of pixels and
  ONE uncovered branch at ~36%: a full-frame 320×240 src==dst copyPixels,
  ~1/tick, ALL identity (src rect == dst rect, zero offset) — Flixel's
  buffer ritual. Pure-copy + transparent-dest + same-rect self-copies are
  provable no-ops → skipped outright (blend/opaque arms keep the legacy
  per-pixel path).

| measurement | before (2c6461be2) | after | win |
|---|---|---|---|
| native Ir, 600 ticks GC=0 (callgrind) | 73.19B | 46.23B | **-36.8% (1.58x)** |
| native user-s, 2900 ticks GC=0 (interleaved ×3) | 28.29 mean | 19.94 mean | **1.42x** |
| — decomposition (toggle builds, same rotation) | | B-only 1.305x, A-only 1.122x | compound |
| rig gameplay cpu p50 (6 interleaved rounds, median) | 108.1 ms (94.8–109.2) | **68.95 ms** (67.2–71.8) | **1.57x** |
| rig gameplay cpu p95 (median of rounds) | 125.3 ms | 84.1 ms | **1.49x** |

(Rig regime was tight this session — base 106.9–109.2 for rounds 2–6, no
bimodal swing; paired p50 ratios 1.37–1.62. rAF interval p95 129→89 ms
tracks it. Raw JSONs: `/mnt/c/playwright/rw_static_ab/`.)

**Verification:** `-DAVM2_FIND_VERIFY -DAVM2_SLOT_VERIFY -DAVM2_SET_VERIFY
-DAVM2_COERCE_VERIFY` build clean over 1200 ticks default-GC + 800 ticks
GC=0 (zero aborts, **zero fallback engagements**); traces + 600 CPU-dump
frames byte-identical to the post-lever-2 dumps across normal/stress/GC=0;
regression test `regression/avm2_static_and_store_slots` (mxmlc + Ruffle
exporter oracle; README documents the pre-existing early-binding
divergence: Ruffle/avmplus verifier-bind lexical statics, our dynamic walk
lets a subclass instance trait shadow — the lever preserves our semantics).

**Post-lever-3+4 profile (46.23B Ir):** blend_over 5.95% (pure pixel work,
now #1 — untouched, wasm runs the SIMD spans), **coerce cluster ~15%**
(to_number 4.68 + to_class 2.79 + to_type_mn 2.76 + to_boolean 2.36 +
to_primitive 2.10), getproperty IC-hit residue 8.9 (getproperty_static_ic
4.64 + resolved_get 4.30), slots_init_defaults 4.14 + setup_locals 3.58 +
o1heapAllocate 2.25 (alloc/ctor), abstract_eq/lt 6.85, xml_abstract_eq
2.57. Name-resolution residue mostly gone: findpropstrict_ic -86%,
mn_match -83%, vtable_find_mn -80%, setproperty_impl -99.7%. Next levers
by size: coerce cluster (typed-Number arithmetic spec / coerce memo on the
remaining paths), alloc/ctor (slots_init_defaults + setup_locals),
getproperty IC residue, tier-2 GC. Also: Seedling gained 541 fused static
reads + 2,152 slot stores, rwp 108 + 552 (unmeasured on their rigs).

## Headline — lever 2 (find→this compile-time resolution, 2026-07-19)

**The Step-0 census answered WHY Seedling's GET levers missed Flixel:**
Flixel-era ASC compiles unqualified own-member reads as
`findpropstrict(mn); getproperty(mn)` — NOT `getlocal0; getproperty` — so
only 60 `this`-receiver GET sites existed in all of RWK (Seedling's mxmlc
emits getlocal0 → 5,039 sites). The GET residue and the find-IC overhead
were the SAME miss. Census (temp tool kept: `SWF_CENSUS_PROPREAD=<path>` in
abc_emit.cpp): of 6,082 find sites, 37% resolve at compile time to a unique
own instance SLOT, and in the hot FlxQuadTree cluster (m484/486/482/487)
**63.5% own-slot + 24.7% own-class-static + 8.6% getlex**.

**The lever (recompiler; runtime byte-identical outside verify builds):**
when the enclosing instance method has the canonical GetLocal0+PushScope
preamble as its ONLY scope ops (no with/activation/active exceptions/branch
into the preamble, local 0 never rewritten) and the site multiname matches a
declared instance trait of the enclosing class (ns-set aware, mirroring
avm2_mn_match — native ancestors can only under-approve), the scope walk
provably hits `this` at its first probe → emit `loc[0]` push
(`avm2_op_findprop_this`, an identity move; -DAVM2_FIND_VERIFY cross-checks
vs the full resolve). The find result is tagged `this`/typed, so the
following GetPropertyStatic slot-specializes through the existing lever-A
machinery. `SWF_NO_FIND_THIS=1` is the A/B toggle.

Coverage: RWK 3,343/6,082 find sites substituted; this-slot getprops
308 → **1,981**; getproperty_static_ic sites 5,439 → 3,766. Also:
rwp 2,794 find-this sites, **Seedling 3,376** (its "GET-spec exhausted"
verdict never saw these — they were classified recv_scope), rwk_ap 3,343;
rwf/rwic only 4 each (newer compiler, already getlocal0).

| measurement | before (8caf10e4e) | after | win |
|---|---|---|---|
| native Ir, 600 ticks GC=0 (callgrind) | 91.69B | 73.19B | **-20.2% (1.25x)** |
| native user-s, 2900 ticks GC=0 (interleaved ×3) | 36.30 mean (36.27/35.80/36.84) | 30.44 mean (28.42/31.76/31.15) | **1.19x** |
| rig gameplay cpu p50 (6 interleaved rounds, median) | 130.1 ms (123.8–135.1) | 104.6 ms (99.5–104.9) | **1.24x** |
| rig gameplay cpu p95 (median of rounds) | 149.2 ms | 123.8 ms | 1.21x |

(This session's regime measured lighter than the 164.6 ms recorded after
lever 1 — RWK click-driven gameplay is bimodal ±30%; the interleaved
same-session ratio is the honest lever-2 number. After-side p50 was
remarkably stable: 99.5–104.9 across all six rounds. Raw JSONs:
`/mnt/c/playwright/rw_findthis_ab/`.)

**Verification:** `-DAVM2_FIND_VERIFY -DAVM2_SLOT_VERIFY` build clean over
1200 TAS ticks (zero aborts across 3,343 substituted + 1,981 slot sites);
traces + 600 CPU-dump frames byte-identical before/after in
normal/stress/GC=0 AND identical to the prior session's post-lever-1 dumps;
regression test `regression/avm2_findprop_this_resolution` (mxmlc pins the
resolution semantics; the old-ASC pattern itself is exercised by upstream
avm2 tests es4_protected_inheritance + class_supercalls_errors and the
games). Known pre-existing gap documented in that test's README: the
runtime conflates same-uri private namespaces (mxmlc emits empty-uri
privates), so Base/Sub private shadowing reads the subclass slot — Flash
keeps privates distinct; unrelated to this lever.

**Post-lever-2 profile (after, 73.19B Ir):** getproperty_static_ic 6.0%
(was 9.5), resolved_get 5.15% (was 7.9), findpropstrict_ic 4.11% (was
8.75); name-resolution residue mn_match 3.99 + vtable_find_mn 3.90 +
propkey_matches 2.34 + mn_name 2.08 (remaining find/IC sites: getlex +
own-class statics + rare-vtable misses); coerce cluster ~10.9%
(to_class 3.39 + to_number 3.34 + to_type_mn 3.20 + class_for_mn 1.69);
SET ~6.3%; blit 7.2% (blend_over 3.76 + bd_copy_pixels 3.42);
slots_init_defaults 2.62 + setup_locals 2.26. Next levers by size:
COERCE/store path (D), remaining find residue for own-class statics
(class-object bake), SET slot spec, blit SIMD check (E), tier-2 GC.

## Lever 1 (findpropstrict scope-hit inline cache, commit `8caf10e4e`)

| measurement | before | after | win |
|---|---|---|---|
| native GC=0 TAS 2900 ticks (user-s, interleaved 3x) | 55.9 | 36.3 | **1.54x** |
| native Ir, 600 ticks GC=0 (callgrind) | 146.4B | 91.7B | **-37.4%** |
| rig gameplay cpu p50 (7 interleaved rounds) | 219.5 ms | 164.6 ms | **1.33x** |
| rig rAF frame-time p95 | 260.9 ms | 175.8 ms | **1.48x** |
| rig frames under 33 ms vsync | ~54% | ~64% | +10 pp |

Honest anchors: **Ruffle plays the same SWF's gameplay at 6.4 ms p50**
(5.3 tick + 1.0 render, measured this session — the first real Ruffle
*gameplay* number; the old 5.5 ms was menu). We are still ~26x off; 30 fps
(33 ms) needs ~5x more. This is a multi-session arc like Seedling's
280→47 ms.

## Build-flag check (ruled OUT)

`ABC_OPT=-O2`/`-O3` on the giant generated ABC TUs: gameplay medians
noise-identical to `-O1` (O1 341.5 / O2 380.8 / O3 376.5 ms medians, within
the ±30% state-dependent spread; wasm sizes near-identical). **The wasm
multiplier is not a compile-flag artifact.** Raw: `/mnt/c/playwright/rw_o2ab/`.

## The profile that named the lever

Real-GPU CDP self-time (25 s @200 µs, 33.9k samples, symbolicated
`--profiling-funcs` build, heavy gameplay ~340 ms/frame, 99.2% of samples
in wasm — raw `/mnt/c/playwright/rwk_prof_2026-07-18.json`):

- #1 `avm2_vtable_find_mn` 10.3% — **85% of its hits under
  `scope_defines_mn` ← `avm2_op_findpropstrict_ic`** (call-tree attribution)
- findpropstrict cluster total (walk + matching + memcmp) ≈ 25-30%
- qsort cluster (`wrapper_cmp`/`sift`/`trinkle`) ≈ 6.5% = `gc_collect`'s
  census sort (tier-2 collector territory; absent at GC=0)

Native callgrind agreed (600 ticks GC=0, before): `avm2_vtable_find_mn`
13.4% + `mn_match` 8.7% + `propkey_matches` 6.2% + `scope_defines_mn` 5.0%
+ `findpropstrict_ic` 4.4% + `memcmp` 4.3% + `findproperty_scope_walk` 3.7%.

Root cause: the findpropstrict IC cached only DOMAIN hits. RWK (Flixel)
issues ~267k findpropstricts/tick and ~95% resolve via the SCOPE WALK —
unqualified own-member reads hit at `lscope[0]` (66%) and own-class statics
(`FlxQuadTree._l` etc. in the per-frame quadtree rebuild) hit the class
object on the outer chain (29%). Every such call re-ran 2+ full
`vtable_find_mn` + multiname memcmps.

## The fix (runtime-only, `avm2_ops.c` + `avm2_ops.h`)

Per-site cache of the scope-walk **hit location** (see commit message of
`8caf10e4e` for the full guard argument):
- kind 2: hit at `lscope[0]`, `scope_n==1` → replay returns the CURRENT
  activation's `lscope[0].obj` under vtable-identity + non-with guards
  (the hit entry is the walk's first probe — no prefix assumptions).
- kind 1: outer-chain hit → replay returns the fixed hit object under
  outer-chain pointer identity (chains are never freed) + local guards.
- Never cached: with-tainted prefixes, local hits at `scope_n>1`,
  activation-preamble methods (their per-call vtables fail the guard —
  by design; they were the residual 2.0M slow calls).

Coverage (600-tick TAS): 158.4M/160.4M calls replay (98.7%) —
l0 103.8M + outer 46.3M + domain 8.3M.

**Verification:** `-DAVM2_FIND_VERIFY` (every IC result cross-checked vs
full resolve) clean over 1200 ticks; traces + 1800 CPU-dump frames
byte-identical across normal/stress/GC=0; both CI modes: every suite
"No changes detected" (zero pass→fail, zero line drift). avm2 823/1215
unchanged.

## Post-lever profile (native callgrind, 600 ticks GC=0, after — the next-lever map)

Total 91.7B Ir. Top clusters:

| % | cluster |
|---|---|
| ~23% | **GET/property-read residue**: `getproperty_static_ic` 9.5 + `resolved_get` 7.9 + `vt_index_get` 1.2 + `value_vtable` 1.6 + remaining `vtable_find_mn`/`mn_match` — the IC-hit path itself (Seedling's known endgame; lever = compile-time slot specialization for non-`this` receivers, recompiler work) |
| ~10.7% | **COERCE/type-check**: `coerce_to_class` 2.8 + `coerce_to_number` 2.7 + `coerce_to_type_mn` 2.6 + `class_for_mn` 1.4 + `coerce_to_boolean` 1.2 |
| 8.75% | `avm2_op_findpropstrict_ic` self — now ~50 instr/call of guard+call overhead at 158M calls/600 ticks; lever = recompiler-inlined guard fast path (drop the call) |
| ~5% | SET: `setproperty_resolved` 2.8 + `setproperty_impl` 2.25 |
| ~4.5% | alloc/construction: `slots_init_defaults` 2.1 + `o1heapAllocate` 1.1 + `setup_locals` 1.8 |
| ~5.7% | CPU blit: `blend_over` 3.0 + `bd_copy_pixels` 2.7 (Seedling's SIMD blit landed — check whether RWK's path uses it) |
| ~2.65% | `avm2_mn_name` — uncached name extraction on remaining slow paths |

GC-on adds only ~8% Ir natively (msort census sort 2.1 + gc_collect 1.8 +
memcpy share) — adaptive watermark holds; further GC wins are the tier-2
collector prompt (`avm2-gc-collector-cost.md`).

Suspect-list postmortem (from the session prompt): #2 findproperty was
right (as the SCOPE side, not domain); #1 alloc/ctor-churn is real but only
~5% native (the churn's cost is mostly GC census, i.e. tier-2); #3 quadtree
IC polymorphism did not materialize (callproperty_ic only ~1%).

## Post-lever wasm CDP profile (2026-07-19, HEAD 8caf10e4e)

Real GPU, 31.3k samples, heavy gameplay. **`__swfPerf.cpu` p50 in the
profiled heavy regime: 340 → 171 ms (~2.0x).** Bucket split: wasm 95.6%,
idle+program 4.1%, JS glue 0.22%. Shape mirrors the native post-lever map
(getproperty_static_ic 9.05% wasm vs 9.5% native; resolved_get 6.9 vs 7.9;
findpropstrict_ic 5.75 vs 8.75; vtable_find_mn 10.27→2.68 pre→post).

**Wasm-vs-native multiplier VERDICT (suspect #4): intrinsic,
roughly-uniform per-instruction overhead of the same hot clusters — NOT a
boundary/glue/GC/ASYNCIFY tax** (no distinct native or JS hotspot exists).
Cutting it means cutting instructions on the shared hotpath, not chasing a
wasm-specific fix.

Caller attribution highlights (full table in the scratchpad text file +
raw JSON): `resolved_get` 89% under the getproperty IC-HIT path (the slot
lever's target); `setproperty_resolved` 67% under `op_initproperty`
(constructor-time stores) with `coerce_to_type_mn` 49% on the store path;
hot sites concentrate in abc0_m484/m486/m482/m487 (Flixel quadtree/update).
GC census-qsort cluster ≈8.8% in default mode (tier-2).

**BUILD GOTCHA (cost a debugging cycle):** 8caf10e4e grew `Avm2FindCache`,
which generated ABC TUs instantiate BY VALUE; incremental wasm builds that
reuse pre-commit .o files (the incremental logic ignores header deps) ship
a silently ABI-broken wasm — boots to menu, heap-corrupts on first input
("Error #1006: addKey is not a function"), and profiles deceptively clean
(96% idle). After any widely-included-struct change: FRESH=1 full rebuild.
Also: WebGPU canvas screenshots read back blank on this rig — gate on
`__swfPerf.cpu`, not pixels.

## Artifacts

- Profiles: `/mnt/c/playwright/rwk_prof_2026-07-18.json` (pre),
  `rwk_prof_postlever_2026-07-19.json` (post); native callgrind outs +
  annotations in session scratchpad (`callgrind.rwk.gc0.600{,.after1b}`,
  `annot_gc0_before.txt`).
- A/B raw: `/mnt/c/playwright/rw_scope_ab/` (base2/after2 r1-7 + analyzer +
  screenshots), `/mnt/c/playwright/rw_o2ab/` (flag check + Ruffle gameplay).
- Working rig driver (boot-reliable): `/mnt/c/playwright/rw_scope_ab/rw_ab.py`
  (goto → poll `Module.calledRun` → runSwf; the old rw_perf.py hangs at
  button-enable on this rig).
