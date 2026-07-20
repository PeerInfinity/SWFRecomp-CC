# Session prompt — native intrinsic org.flixel collision classes (FlxQuadTree + FlxList)

**Objective:** playability — **30 fps = 33 ms** per title, generic pipeline, no
per-game settings. Scoreboard 2026-07-20 (fresh HEAD builds, real-GPU rig):
Seedling 18.4 ✓, RWIC 18.3 ✓, RWF 30.8 borderline, **RWP 47.5 ✗, RWK 61.1 ✗**.
RWK needs **1.85x**. The Flixel collision quadtree is **70.84% of RWK's Ir**,
and the gate arithmetic already priced every form of attack: pooling 57.1 ms
FAIL, order-identical AS3 rewrite 37.1 ms MISSES, **order-identical NATIVE
reimplementation ~24.1 ms PASSES**. This session builds that native intrinsic.
The direction call, method, and all numbers: `tools/divergence/perf/RWK_AB_STATUS.md`
§§1-5 of "SESSION 2026-07-20b" (read it first, top to bottom).

Memories: [[avm2-quadtree-is-71pct-pooling-dead]],
[[avm2-quadtree-attribution-method]], [[avm2-playability-scoreboard-2026-07-20]],
[[avm2-native-ab-recipe-gc0-invalid]], [[windows-playwright-from-wsl]].

**Do NOT build pooling. Do NOT resume generic lever-7 runtime work.** Both are
explicitly ruled out in the direction call.

## §0 — Corpus reality check (10 minutes, do before designing anything)

`RWK_AB_STATUS.md:180` claims all four Robot Wants titles share byte-identical
quadtree source. **The decompiles contradict this**: RWK/RWP
`FlxQuadTree.as` = 418 lines (Flixel 2.21), RWF/RWIC ≈ 2700-2838 lines (2.35).
Settle it with bytecode, not prose: hash the raw ABC method bodies of the
collision classes in all four SWFs (bodies are available at recompile time;
`tools/divergence/perf/abcmap.py <RecompiledABC-dir> 0` maps `abc0_mNNN` →
qualified names — at the 2026-07-20 RWK build: m482 ctor, m483 add,
m484 addObject, m485 addToList, m486 overlap, m487 overlapNode = FlxQuadTree;
m593 = FlxList ctor. Re-derive at HEAD, never guess; the pools already carry
their index-0 sentinel).

Expected outcome: one fingerprint for the 2.21 pair (RWK+RWP — **exactly the
two unplayable titles**), a different one for 2.35 (RWF/RWIC — already at/near
30 fps). **Scope this session to 2.21 semantics.** 2.35 titles fall back to
their own code, which is fine — extending coverage is a later, separate
verification job, not a reason to widen this session.

## §1 — Design shape (recommended; deviate only with reason)

Reference source (semantics ground truth, order-identical is the contract):
- `/home/robert/CC/jpexs/output/robotkitty/scripts/org/flixel/FlxQuadTree.as` (418 lines)
- `/home/robert/CC/jpexs/output/robotkitty/scripts/org/flixel/data/FlxList.as` (20 lines)
- Call structure: `xplor/PlayState.as:394-402` — 9 tree rebuilds + 14
  traversals/tick via `FlxU.collide`/`overlap`; `collide` builds once,
  traverses twice (X then Y solve).

**Fingerprint at recompile time, substitute at class-link time, keep the
fallback compiled:**
1. In the emitter (`SWFRecomp/src/abc/abc_emit.cpp` — methods table at
   ~3172-3330), hash each ABC method body. When a class's full method-body
   set + trait layout matches the known 2.21 collision-class fingerprint, emit
   an intrinsic marker on the class into the tables. **Still emit the normal
   `abc0_mNNN` bodies** — they are the fallback and the A/B arm.
2. At runtime class link, when the marker is present, install the native
   implementation using the mechanism that already exists for builtins:
   `cls->native_construct` / `native_ext_size` / `native_init`
   (`include/avm2/avm2_class.h:135-143`; precedents `avm2_globals.c:1803`,
   `avm2_array.c:1057`, `avm2_bytearray.c:1272`) and override the vtable
   `ref.fn` for the hot methods (trait loop, `avm2_class.c:470-545`;
   construct hook fires at `avm2_class.c:1178-1180`). `Avm2MethodFn.fn == NULL`
   is already the sanctioned native signal (`avm2_abc.h:101`).
3. Gate with an env kill switch (`AVM2_NO_INTRINSICS=1` → skip installation).
   Same binary then provides both A/B arms and a live escape hatch.

**Fallback on any mismatch is NON-NEGOTIABLE**: no marker → the game's own
compiled code runs, untouched. A silent substitution with different semantics
poisons the "just works" premise.

Semantic contract (audited 2026-07-20, verify nothing changed): zero
subclassing of either class in any title, no reflection targets them, FlxList
never escapes FlxQuadTree. **Order-identity is the hard requirement**:
`overlapNode` invokes the collision callback in node-list order and callbacks
mutate positions, so any change to tree shape or iteration order changes the
game. Internally the native impl may use plain C node structures (FlxList
never escapes; check whether FlxQuadTree instances escape `FlxU` before
assuming the same for them), but every AS3-visible behavior — callback order,
`.x/.width/.exists/.solid` reads off real FlxObjects (which stay AS3 property
GETs; the ~24 ms estimate already discounts that), return values — must match
the decompiled source line for line.

## §2 — Validation ladder (in order; do not skip rungs)

1. **TAS oracle** (`ruffle-tests/_rwk_tas/`, plan_k): byte-identical trace +
   CPU-dump frames vs the fallback arm (`AVM2_NO_INTRINSICS=1`) of the SAME
   build. An order-identical implementation keeps this oracle valid; if it
   diverges, the implementation is wrong — fix it, don't relax the oracle.
2. **Fallback proof**: perturb one body byte in a scratch recompile → marker
   must not emit, game must run its own code, TAS still passes.
3. **Native wall-clock A/B**: default GC, equal ticks, strictly interleaved,
   ≥3 rounds, median. **GC=0 is INVALID for wall-clock** (arms OOM at unequal
   tick counts); GC=0 ≤600t only for the callgrind Ir check. Ir is not time —
   this arc failed that conversion twice (lever 5: −13.1% Ir → ~1.1x; lever 6:
   −5.16% → nothing). The 24.1 ms figure is a *prediction to test*, not a result.
4. **RWP**: recompile RWP, confirm the fingerprint matches and the intrinsic
   engages; smoke-run it (no RWP TAS exists — visual/frames sanity only).
5. **Rig scoreboard**: rebuild wasm **FRESH** (`SWFRecomp/scripts/build_wasm_avm2.sh`;
   staged wasm rots on runtime change), redeploy `docs2/examples/avm2/rwk/`
   (+ rwp), then the drain-polling drivers `pb_ours_win.py`/`pb_analyze.py`
   (NOT the ti_* ones), ≥5 interleaved rounds, state-proven phases, **no
   concurrent native jobs on the machine** (the 2026-07-20 absolutes were
   contaminated by a parallel callgrind). Success = **RWK mean ≤33 ms**;
   report RWP; re-measure RWF cleanly while the rig is quiet (its borderline
   call is the one the contamination could have moved).

## §3 — Deliverables

1. The intrinsic + fingerprint gate + kill switch, shipped via the pipeline
   (`.claude/pipeline-handoff.md`): no-graphics CI (runtime + recompiler
   change, no render path), FRESH demo redeploys for every touched title.
2. RWK_AB_STATUS.md session section: fingerprint table (per title), TAS/
   fallback/wall-clock/rig results, and the verdict vs the 24.1 ms prediction —
   including honestly if it misses (that would be the third failed Ir→wall
   conversion and itself a major finding about the counterfactual method).
3. Memory writes: outcome + any gotcha in the fingerprint/link mechanism.
4. **Cheap side quest, only if the rig session leaves room**: per-title
   `--toggle-collect` on RWP (and RWIC) to settle why RWK is 3.3x RWIC on the
   same code — the 70.84% is RWK-only and must not be transferred.

## Method rules (binding)

- Rig: real-GPU Windows Chrome from WSL (`WINDOWS_PLAYWRIGHT_FROM_WSL.md`);
  same-session ratios only; prove every phase's state (screenshot + in-frame
  quantity). `rwf_ruffle`/`rwic_ruffle` are DEAD ARMS (Ruffle draws nothing);
  perf rings are short circular buffers — **drain-poll**, never read once at
  window end.
- Native A/B: default GC + equal ticks for wall-clock; GC=0 ≤600t for Ir.
- Verify-defines CI runs publish NOTHING ([[ci-verify-run-results-clobber]]).
- Commit direct to master; stage files by name; standard trailer.

## Budget note (delegation)

Fable-led. Opus subagents: the mechanical C port of the 418-line class, TAS
and rig runs, RWP/RWF recompiles. Fable: the fingerprint/link design, the
order-identity semantic edge cases, and every verdict.
