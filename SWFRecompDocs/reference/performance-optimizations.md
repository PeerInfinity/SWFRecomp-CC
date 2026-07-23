# Performance Optimizations — Reference

A catalog of every shipped performance optimization in SWFRecomp (recompiler)
and SWFModernRuntime (runtime), with mechanism, layer, measured impact, and
kill switches — plus the attempted-and-rejected list and the binding
measurement rules. Compiled 2026-07-20 at the close of the playability arc;
§3 (display-tree/timeline walks) added 2026-07-22 with the Elephant Quest
bring-up.

**Ruffle relationship:** which of these Ruffle already has, which it could
adopt, which its architecture forecloses, and which are AOT-only — see
[`performance-optimizations-vs-ruffle.md`](performance-optimizations-vs-ruffle.md)
(analysis session prompted by
[`../prompts/perf-optimizations-ruffle-applicability.md`](../prompts/perf-optimizations-ruffle-applicability.md)).

**Where the detailed records live:** per-lever A/B logs with full method are
`tools/divergence/perf/RWK_AB_STATUS.md` (RWK/AVM2 base-compute arc) and
`tools/divergence/perf/SEEDLING_AB_STATUS.md` (Seedling/AVM2 arc); AVM1-era
work is in dated docs under `SWFRecompDocs/status/`. This file is the index
and summary; the logs are the evidence.

**Bottom line (2026-07-20):** all five AVM2 demo titles clear 30 fps
(gameplay p50, real-GPU rig): Seedling 18.4 ms, RWIC 14.7, RWF 21.6,
RWK 21.6, RWP 22.5. Ruffle clears 30 fps on none of the titles it can
render. Seedling's arc alone went ~280 ms/frame → ~20 ms (~14x); RWK's went
~220 ms → 21.6 ms across seven levers plus the GC arc.

> **Reading impact numbers:** rig (browser) absolutes are only comparable
> within one session — every ratio below is a same-session interleaved A/B.
> "Ir" is native callgrind instruction count, a proxy that repeatedly failed
> to predict wall-clock (see §7).

---

## §1 AVM2 — property/name resolution, dispatch, and typed emission

The dominant theme of both AVM2 arcs: the AS3 semantics of *name resolution*
(scope walks, vtable searches, multiname matching, coercion) cost far more
than the game's own arithmetic. Layer legend: **[RT]** runtime
(`SWFModernRuntime/src/avm2/`), **[RC]** recompiler
(`SWFRecomp/src/abc/abc_emit.cpp` emit-time analysis), **[RC+RT]** both.

### Seedling arc (2026-07-14/15, `SEEDLING_AB_STATUS.md`)

| Optimization | Commit | Mechanism | Impact (same-session) |
|---|---|---|---|
| vtable name-hash index | `5fa736f1d` | [RT] lazy FNV-1a name-keyed hash on `Avm2VTable`; `find_mn` O(count)→O(1). Per-call activation vtables opt out (`no_index`) | 280 → 154 ms/frame (1.8x); `vtable_find_mn` 31.9%→5.3% |
| domain-find name hash | `0e1b25912` | [RT] same lazy hash on `Avm2Domain` | 154 → ~62 ms (2.5x); `domain_find` 14.9%→1.7% |
| getproperty inline cache + lazy class-name + printf-free ints | `c608083d4` | [RC+RT] per-site monomorphic IC on GetPropertyStatic (vtable identity + count guard → replay slot index); receiver class qname no longer snprintf'd on every slot write (throw-path only); integer stringification without printf | ~62 → ~47 ms — **Ruffle parity**; the lazy class-name was the largest single piece (~8 ms) |
| IC → callproperty + setproperty | `c7f9f5e26` | [RC+RT] same IC for CallProperty/CallPropVoid and SetPropertyStatic | ~1 ms (at noise floor; mechanism confirmed in profile) |
| `this.field` slot specialization | `ab236e611` (+`fe1b9e062` subclass-shadow fix; scout gate `d63ee098f`) | [RC] emit bare `slots[K]` reads for compile-time-proven `this.field` on slot traits; 5,039 sites. Bails if any subclass redeclares the field | ~3-4 ms (6.4-8.6%) |
| getlex-global domain IC | `dad415990` | [RT+RC] `findpropstrict_ic`: per-site cache of the DOMAIN hit; with-free methods also skip the scope walk | ~4-4.5 ms (~11%) |
| class-static slot specialization | `63cf3d5c9` | [RC] compile-time-known Class object + static slot index → direct slot read; 1,432 sites | ~2-3 ms (6-8%) — **arc crosses 30 fps here** |
| coercion elision | `3b5a6b925` | [RC] drop verifier-redundant `coerce_*`/`coerce_return`; 735 sites | sound + byte-identical, but ~1 ms = below noise (hot methods were already coerce-clean) |
| coerce-class memo | `e05a8fe0d` | [RT] memoize `avm2_class_for_mn` per (file, mn_idx) in `coerce_class_memo[]`; caches non-NULL only (names are transiently unresolvable during their own cinit) | ~6 ms (~12%) |
| blit SIMD | `8cc2f5440` | [RT] `bd_copy_pixels`/`bd_draw` dispatch whole rows as 4-px WASM-SIMD spans (`blend_over`/`copy_force_opaque`/memcpy); byte-exact via `(x*32897)>>23 == floor(x/255)`; `-msimd128` in `build_wasm_avm2.sh`; scalar fallback | ~1.4 ms (~6%), fastest in 11/11 paired rounds |
| Rectangle slot fast path | `88f6f4ad6` | [RT] `rect_to_xywh` reads `slots[1..4]` directly when `cls == g_rectangle_class` (was 4 multiname resolves per copyPixels, ~279/frame) | ~1.1 ms (~5%) |

### RWK arc — levers 1-7 (2026-07-18/20, `RWK_AB_STATUS.md`)

| Lever | Commit | Mechanism | Impact (authoritative measure) |
|---|---|---|---|
| 1 — findpropstrict scope-hit IC | `8caf10e4e` | [RT] cache the scope-walk *hit location* (local scope[0] under vtable-identity guards; outer-chain under pointer identity) — the prior IC cached only DOMAIN hits but ~95% of RWK finds resolve via the scope walk | rig p50 219.5→164.6 ms (1.33x); native Ir −37.4% |
| 2 — find→this compile-time resolution | `2c6461be2` | [RC] canonical-preamble methods whose find-site multiname matches a declared instance trait provably hit `this` → emit identity move; unlocked Flixel (its ASC emits `findpropstrict;getproperty` for own-member reads). Toggle `SWF_NO_FIND_THIS` | rig p50 130.1→104.6 ms (1.24x); Ir −20.2% |
| 3+4 — own-class-static bake + store-path slot spec + blit identity-skip | `a2e4758fb` | [RC] fuse `findpropstrict;getproperty` of enclosing-class statics (`getlex_ownstatic`); SetProperty/InitProperty on statically-typed receivers → direct slot store with coerce elided where provable; [RT] skip full-frame src==dst identity copyPixels. Toggles `SWF_NO_FIND_STATIC`, `SWF_NO_SET_SLOT` | rig p50 108.1→69.0 ms (1.57x); Ir −36.8% |
| 5 — typed-value emission | `a35afa7b8` | [RC+RT] compare→branch fusion (`if (lessthan_test(...)) goto` — no bool boxing) + runtime-KIND-checked numeric fast arms, exactly equivalent for ALL inputs (not type-gated; lattice gating would cover only 31% of sites) | rig ~1.12x mean / 1.16x p50 — **book as ~1.1x** despite Ir −13.1% |
| 6 — slot-default template + setup_locals memset | `93299b884` | [RT] per-class precomputed non-pointer slot-default image (construction = memcpy + patch loop; template may never hold a heap pointer — untraced-root hazard); locals fill via memset (undefined is all-zero) | Ir −5.16% (`slots_init_defaults` −92%) but **no measurable wall-clock change** — kept as a deterministic Ir win |
| 7 — native Flixel collision intrinsic | `2dc6e4fac` (2.21), `189285168` (2.35), gate hardening `ad4ee3754`, wasm kill switch `6a67062e5` | [RC+RT] pool-normalized FNV-1a fingerprint of ABC method bodies matches `org.flixel::FlxQuadTree`+`FlxList`; on exact match, class-link installs `avm2_flixel.c` (~950 lines, order-identical to source; only the root tree is an `Avm2Object` — children and list nodes are pure C structs). Any mismatch → game's own code (fail-safe). Per-title constants for the obfuscated 2.35 pair; id 3 variant for 2.35's dynamic `_min` | native wall-clock **2.59x**; rig RWK 60.8→21.6 ms (2.82x), RWP →22.5, RWF 29.0→21.6, RWIC 16.1→14.7. The arc's first Ir→wall prediction that converted (removed work was high-CPI pointer-chasing) |

Fingerprint gate details (constants, normalization rules, probe evidence,
closed holes): see the gate section of `RWK_AB_STATUS.md` and
`SWFRecomp/src/abc/abc_emit.cpp` comments. Both originally-documented gate
holes (same-kind opaque-namespace collision; closure refs hashed by debug
name) were **closed** in `ad4ee3754` (opaque-ns first-seen ordinals;
recursive normalized closure-body hashing, depth-capped, fail-safe).

## §2 AVM2 — garbage collection & memory management

| Optimization | Commit | Mechanism | Impact |
|---|---|---|---|
| Stage 11 mark-sweep GC | `b4db40f98`+`b5695059b` | [RT] `avm2_gc.c`: between-tick mark-sweep (VM quiescent at tick boundary); precise field tracing + conservative `native_ext` scan; per-module ext-free hooks; pinning for immortal class/prototype objects. `AVM2_GC_STRESS=1` (collect every tick) is a CI correctness gate | unbounded growth → bounded sawtooth (soak: 611 MB retained → ~flat) |
| collectable strings | `c0e0b3493` | [RT] `Avm2String` enrolled in the census (rodata pool entries self-exclude via zero `gc_flags`); byte-range marking (references may point into inline bytes) | RWK allocated @1560 ticks **1467 → 129 MB** (fixed the browser OOM class) |
| raw-alloc reclamation | `c9678c553` | [RT] free per-call scratch + grow-and-abandon buffers the census never saw (EditText layout trees, glyph/sort/floodFill scratch, tombstones, per-object activation vtables). `fn_scope` is PROVEN aliased — never freed | RWK churn 39.6 → 1.0 KB/tick (−97%); Seedling idle 161 → 9.5 KB/tick |
| weak orphan registry | `adec1e505` | [RT] constructed-unparented display objects no longer GC roots; dead orphans pruned post-mark (mirrors Ruffle's `DisplayObjectWeak`). Broadcast-listener registry stays deliberately STRONG for determinism | Seedling live census dead-flat (was +9.5 KB/tick) |
| adaptive GC watermark (tier 1) | `fd5931661` | [RT] collect cadence tracks *retention* (post-collect watermark = live bytes, clamped) + census-entry trigger, instead of gross-bytes-since-collect (RWK grossed 3.27 MB/tick → collected every 2 ticks) | RWK 1364 → 126 collects/3000t; GC CPU 82 → 15.1 s; Seedling holds 30 fps (its 400-793 ms spikes were collects) |
| tier-2 collector cost | `bf4f45671` | [RT] arena membership bitmap (O(1) census test, kills the per-collect qsort snapshot); epoch marks (O(1) whiten); lazy sweep (budgeted resumable cursor, nursery born-black during sweep, eager below 1/8 headroom) | pause 73 → ~23 ms; rig >250 ms stalls 6 → 0/round; all-frames mean 1.27x. **p50 rises by design** — judge on stalls + all-frames mean |
| `arrayToCSV` intrinsic + arena right-size | `a5c8f86ee` | [RC+RT] native `FlxTilemap.arrayToCSV` intrinsic (id 4, fingerprint-gated per title; grow-realloc buffer replaces O(n²) string-concat) kills the ~0.3-1.7 GB single-tick level-load transient; browser arenas shrink 1984 → 512 MB (AVM2) and 1024 → 256 MB (AVM1) — emscripten mmap commits the arena resident at init, so only the reservation size matters | worst-tick gross RWK 1397 → 118 MB; browser resident ~2117 → ~634 MB (−70%) at 44 fps, 0 stalls (the ~2.4x GC-cadence increase absorbed by tier-2). Plan: `SWFRecompDocs/plans/avm2-browser-footprint.md` |

AVM1 side: the 2026-07-04 reclamation arc (`700e02a3a`..`ee0805363`) gave
AVM1 its own default-on root-traced mark-sweep collector plus targeted leak
fixes — primarily a correctness/footprint effort; see the commit chain.

## §3 AVM2 — display tree & timeline walks

The only arc so far where we beat Ruffle by **algorithm** rather than by
constant factor: Ruffle runs the same walk we did, and its own watchdog kills
it on the title that motivated the work.

| Optimization | Commit | Mechanism | Impact |
|---|---|---|---|
| goto catch-up walk gate | `6fefd4552` | [RT] `avm2_display.c`: skip construct / frame-script catch-up on subtrees with no pending work. `walk_clean` per node (set only by a frame-script walk that found the node AND all children quiescent; cleared up the whole ancestor chain on creation, goto, playhead advance, queued script, re-parent), `dirty_kids` per container (skip the child loop outright; recounted exactly during the walk), a dirty-orphan candidate list + `in_orphan_list` + amortized orphan compaction, and `display_ext_fast` (skips `avm2_display_ext_of`'s `class_is_a` walk for nodes already known to be display objects) | Elephant Quest `init2()`: **>1000 s projected (never completed) → 6.2 s**, byte-identical trace; 1200 ticks of live gameplay in 8.0 s |

**The trap.** Every explicit AVM2 goto — including a *no-op* goto to the frame
you are already on — runs a full stage + orphan catch-up pass (Ruffle
`frame_lifecycle.rs::run_inner_goto_frame`; ours
`avm2_display_inner_goto_frame`). Any `new Clip(); addChild(c);
c.gotoAndStop(n)` build loop is therefore **O(n²)**. Elephant Quest's
`Level.initTiles` runs that loop a few thousand times.

**Where the cost actually was** (`AVM2_GOTO_PROF`, see §8): by tile ~4000 one
goto walked **60,952 nodes in ~35 ms** — but the *stage* subtree was small and
constant (~3.7k nodes). **94% of the nodes were the orphan list**, which grew
to **27,661 entries** and was scanned **three times per goto** (construct loop,
frame-script loop, `orphan_cleanup`); `orphan_add`'s linear membership scan was
quadratic in its own right. A stack sampler had already named the hot function
in a prior session and still pointed at the wrong input — see rule 7 in §7.

**Why "match Ruffle" was the wrong instinct.** Ruffle's `goto_frame` /
`no_op_goto` / `run_inner_goto_frame` do the same full walk (read, not assumed).
Ruffle survives on a ~20-40x smaller per-node constant and *still* takes ~18 s
here, which is exactly why its 15 s `max_execution_duration` watchdog aborts the
build. Aligning with the reference implementation would have capped us at
Ruffle's number; the gate is what clears it.

**Safety design.** `walk_clean` is zero-initialized, so any node nobody accounts
for is walked exactly as before — a missed *mark* is a bug, a missed *certify*
is only slower. The marks that are easy to miss: `run_frame_internal` advances
`current_frame++` **without** going through `run_goto` (that one broke the boot
until marked), and every site that gives a node a parent (10 of them —
re-parenting is the one thing the "stop at the first marked ancestor" shortcut
cannot see). Graded by `regression/avm2_goto_catchup_scale` (0.32 s with the
gate, harness TIMEOUT without — verified failing) and by full CI in **both**
modes: avm2 827/1215 and avm1 635/711 at a 0 delta, every other suite 0 delta.

**Known residual.** A dirty container still re-scans its whole render list to
find the one dirty child, so the child scan is O(n²) with a small constant
(~1.7 s of EQ's total; harmless there). Removing it needs an *ordered*
dirty-child structure, because frame-script execution order must stay
render-list order — a plain dirty list would reorder scripts.

## §4 AVM1 runtime & shared per-frame path

| Optimization | Commit(s) | Mechanism | Impact |
|---|---|---|---|
| property-name hash gate + per-object hash index | `537951f4f`, `e13388a18` (2026-06-01) | hash-gate `object.c` property-name compares, then a per-object hash index + hash-once proto walks | −35% then −49% total instructions on Doodle Jump |
| per-frame-walk MC resolution cache | `6308c4a03` | memoize resolved `MovieClip*` on the `DisplayObject`; hot walk sites revalidate the same predicate the resolver keys on. The 5 per-frame tree walks were ~59% of Minesweeper Ir (O(nodes × cache_size) string scans) | −38% Minesweeper tick cost |
| event-driven enterFrame-walk pruning | `5f2530446` | the two pure-recursion enterFrame walks maintained event-driven instead of re-walked per tick (a shelved full-tree-recompute variant cost ~10% in NO_GRAPHICS — see §6) | −14% further |
| N button-hover walk gate | `b3e45b9e2` | per-frame button-hover walk runs only on mouse-move | N-specific tick cost |
| syncVarToTextFields fast-reject | `ca31201a1` | unbound var writes skip the textfield scan | −19% Ir |
| ASCII fast path in name matching | `b7f1a1759` | `prop_name_match`/`swf_name_match` skip per-char UTF-8 decode for ASCII | leaf-cost cut under all walks |
| findOrCreateMovieClip cache-scan cut | `65b09ad64` | cheapen the child-MC cache scan (hottest function on N) | N tick cost |

## §5 Renderer / GPU

| Optimization | Commit | Mechanism | Impact |
|---|---|---|---|
| writeBuffer batching | `079c0fefe` | `render_webgpu.c`: per-frame CPU staging mirrors for dynamic vertex/color regions, flushed as ONE `writeBuffer` before submit (was one tiny call per dynamic shape, hundreds/frame at ~88% of browser frame CPU) | Minesweeper 12 → ~24 fps; pixel-identical |
| identical-geometry upload skip | `485cab115` | skip re-uploading byte-identical dynamic geometry | Minesweeper → 30 fps |
| fs_main fill-type specialization | `3d2ea1b5c` | per-fill-type fragment shader variants; solid fills do zero texture ops | pixel-identical (no measurable SwiftShader win; kept as real-GPU hygiene) |
| writeTexture sub-region upload | `4a3b0bdb2` | upload only the source sub-rect, not the full padded atlas layer (Seedling uploaded 11.49 MB/frame for 102 KB of data) | 110.8x less upload; present latency 11.45 → 0.68 ms; fps unchanged (upload was off the critical path) |

## §6 Attempted, rejected, or ruled out

Recorded dead ends are as load-bearing as the wins — several were killed by
arithmetic *before* being built, which is the arc's core method lesson.

| Candidate | Verdict |
|---|---|
| Flixel quadtree **pooling** | dead on arithmetic before building: only 9.21% of the quadtree region is allocation; a recycled node still runs the ctor's parent-list copies + ~12 stores. Honest counterfactual 57.1 ms vs the 33 ms bar |
| **inline slots** (object+slots in one alloc) | built, measured, REVERTED: −489M Ir but +22% live heap — o1heap power-of-2 binning (`Avm2Object`=208 B crosses bins). Don't retry without shrinking the object or changing size classes |
| **nursery/bump allocator, generational GC** | ruled out: birth/death ~6% of frame at HEAD (already harvested by tier-2 + lever 6); ceiling <1.10x |
| `add` numeric fast arm (lever 5) | REVERTED: int+int must return INTEGER kind; the arm flattened to NUMBER — observable. `add` stays generic |
| call devirtualization (Seedling step 5) | gated out pre-build: prize <1 ms (calls already IC'd; static calls never miss) |
| non-`this` instance-slot GET spec | gated out at census: top-5 GET drivers had 0 newly-specializable sites |
| `ABC_OPT=-O2/-O3` on generated TUs | noise-identical to -O1; the wasm multiplier is not a compile-flag artifact |
| AVM1 full-tree subtree-pruning recompute | shelved: the per-tick bottom-up recompute scanned to depth ~16,400 (attachMovie +16384 bias) → ~10% CI overhead; superseded by the event-driven re-port (§4) |

## §7 Measurement rules (binding — every A/B above followed these)

1. **Ir is not time.** Levers 5 and 6 turned −13.1% / −5.2% Ir into ~1.1x /
   nothing; lever 7 turned ~60% into 2.59x (high-CPI pointer-chasing).
   Wall-clock decides; Ir attributes.
2. **Rig numbers are same-session only.** Real-GPU Windows Chrome driven
   from WSL (`tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`);
   ≥3-5 strictly interleaved rounds, medians. WSL Chrome is SwiftShader —
   never for perf. Perf rings are short circular buffers — drain-poll.
3. **Prove the phase.** Title screens and menu frames have destroyed more
   sessions than any bug (the retracted "11x Ruffle gap"). State-attest
   every measured phase (screenshot + in-frame quantity).
4. **Native wall-clock uses default GC at equal ticks.** `AVM2_GC=0` runs
   end at arena exhaustion, not the tick cap → unequal work, fake wins.
   GC=0 is for Ir only, ≤600 ticks.
5. **Byte-identity is the correctness bar.** Every lever ships with a
   verify build (`-DAVM2_*_VERIFY` dual-run + abort) and/or a frame/trace
   oracle (TAS input, `AVM2_CPU_DUMP` sha256), plus full-suite CI in both
   normal and verify modes.
6. **A stack sampler names the function; only a counter names the growing
   input.** EQ's hotspot was sampled correctly in one session (gdb SIGINT →
   `run_frame_scripts_obj`) and still pointed at the wrong fix, because the
   growing input was the orphan list, not the tree the function walks. Before
   fixing an O(n²), instrument *which* n — an env-gated counter that splits the
   candidate inputs (§3's orphan-vs-stage node split) is cheap and decisive.
7. **FRESH=1 after any widely-included struct change** — incremental wasm
   builds ignore header deps and ship silently ABI-broken binaries; the
   `.o` cache also keys on mtime, not `-D` flags, so A/B toggle builds need
   fresh builds too.

## §8 Kill switches & toggles (quick reference)

| Toggle | Effect |
|---|---|
| `SWF_NO_FIND_THIS` / `SWF_NO_FIND_STATIC` / `SWF_NO_SET_SLOT` | recompile-time: disable levers 2 / 3A / 3B emission |
| `SWF_NO_BLIT_SIMD` | compile-time: scalar blit |
| `AVM2_NO_INTRINSICS=1` | env: skip native-intrinsic install (native builds) |
| `-DAVM2_FORCE_NO_INTRINSICS=1` | compile-time: same, for wasm (no getenv) |
| `AVM2_GC=0` / `AVM2_GC_STRESS=1` | env: GC off / collect every tick (correctness gate) |
| `AVM2_GC_ADAPTIVE=0`, `AVM2_GC_WATERMARK`, `AVM2_GC_MAX_ENROLL`, `AVM2_GC_SWEEP_BUDGET` | env: watermark/cadence/sweep-budget controls (tier 1/2) |
| `AVM2_HEAP_STATS=1`, `AVM2_GC_TIME=1` | env: live allocation / per-collect phase telemetry |
| `AVM2_NO_WALK_SKIP=1` | env: disable the goto catch-up walk gate (§3) — the A/B and bisect switch |
| `AVM2_GOTO_PROF=1` / `=2` | env: rolling `[GOTOSUM]` per 1000 gotos (wall time split, nodes walked, children scanned, orphan count) / per-goto `[GOTOPROF]` + `[FS]` lines |
| `-DAVM2_SLOT_VERIFY`, `-DAVM2_ARITH_VERIFY` | verify builds: dual-run old+new path, abort on divergence |
| `SWFRECOMP_DUMP_FINGERPRINTS`, `SWFRECOMP_FP_DISASM=1` | recompiler: fingerprint report / pool-resolved disassembly |

---

*Deliberately excluded:* the AVM1 dispatch-consolidation arc (2026-07-04..17)
— a correctness/refactor effort whose perf gate proved only no-regression
(unified core self-cost 0.0019% Ir); and measurement tooling (HUD, profiling
harnesses, scoreboard drivers), which is catalogued in
`tools/divergence/perf/`.
