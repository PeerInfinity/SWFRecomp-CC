# RWK base-compute perf arc — status & A/B log

Session 2026-07-19 (prompt: `SWFRecompDocs/prompts/avm2-rwk-base-compute-profile.md`).
Precedent/format: `SEEDLING_AB_STATUS.md`. All rig numbers: Windows Chrome,
real GPU (intel gen-9), driven from WSL via python.exe + Playwright
(`WINDOWS_PLAYWRIGHT_FROM_WSL.md`); metric `__swfPerf.cpu` gameplay p50
unless noted. All native numbers: solo -O2 no-graphics build, RWK plan_k
TAS (`_rwk_tas`), TZ=NPT-5:45.

## Headline

**Lever 1 (findpropstrict scope-hit inline cache, commit `8caf10e4e`):**

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
