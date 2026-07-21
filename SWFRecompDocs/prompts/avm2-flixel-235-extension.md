# Session prompt — extend the Flixel collision intrinsic to the 2.35 titles (RWF / RWIC)

**Objective:** RWF sits at 30.8 ms — nominally under 33 but with no margin;
the user wants a **comfortable** margin, and chose this extension over
re-measuring. RWIC (18.3 ms) gets faster as a side effect. The intrinsic
([[avm2-flixel-native-intrinsic]], `SWFModernRuntime/src/avm2/avm2_flixel.c`)
already exists and clears RWK/RWP by 2.8x; this session's work is
**verification, not performance engineering**: prove the 2.35 titles'
obfuscated collision bytecode is semantically served by the native
implementation, and bake per-title constants only on that proof.

Read first: [[avm2-fingerprint-gate-holes-closed]] (the 2.35 recon — no
`NewFunction` in their quadtree, but RWF `d2cd8bafd2ca5111` ≠ RWIC
`c15fc34addfdc947`, i.e. **per-title control-flow obfuscation** the
normalizer does not and SHOULD not cancel), [[avm2-intrinsic-fingerprint-gate]]
(current constants: FlxQuadTree `2c1994f2e30e0642`, FlxList `6e5f899d35ae5140`;
probe methodology; `scratchpad/gen_probes.py` may be gone — it was scratchpad;
the memory records how to rebuild it), [[avm2-flixel-native-intrinsic]]
(architecture, kill switches, LAZY engagement gotcha).

Per-title baked constants are **compatible with the objective**: the table is
a recompiler-internal verified whitelist, not user-facing config. What is NOT
acceptable is baking a constant without the evidence chain below.

## §0 — Audits before design (half a day, order matters)

1. **The lone-FlxList hazard (safety, do first).** The recon checked RWF/RWIC
   *FlxQuadTree* fingerprints only. FlxList is a 20-line class with no
   opaque-ns or closure content — it may hash **identical to 2.21** on the
   2.35 titles and already carry `intrinsic_id=2` in a fresh RWF/RWIC
   recompile today. Dump fingerprints + stamps for both titles
   (`SWFRECOMP_DUMP_FINGERPRINTS=1`, fresh recompiles — the shipped
   `~/CC/*_build` dirs may be STALE, see the gotcha in
   [[avm2-fingerprint-gate-holes-closed]]). If FlxList matches while
   FlxQuadTree falls back: decide and implement **coupling semantics** — the
   native FlxList was designed as C structs internal to the native quadtree
   ([[avm2-flixel-native-intrinsic]]); a lone native FlxList under an AS3
   FlxQuadTree was never validated. Either prove that pairing safe or make
   intrinsic installation all-or-nothing for a coupled class set. If it
   already engages on the deployed RWF/RWIC wasm, say so loudly — it means
   the 30.8/18.3 scoreboard numbers were partially intrinsified already.
2. **Upstream ground truth.** Confirm each title's Flixel version from the
   decompiled `FlxG.as` version constants
   (`/home/robert/CC/jpexs/output/{robotfishy,icecream}/scripts/org/flixel/`),
   then clone upstream Flixel (github.com/AdamAtomic/flixel) and locate the
   2.21-line and 2.35-line source of FlxQuadTree/FlxList — anchor by diffing
   candidate revisions against RWK's clean 418-line decompile (known-good
   semantics for the shipped native impl). Then diff upstream 2.21 → 2.35 for
   these two classes ONLY. Outcomes:
   - **Semantically identical** → the shipped native impl is the correct
     target for all four titles; the rest of the session is bytecode-level.
   - **Differs** → enumerate every observable difference (callback order,
     property read/write set, return values, member layout). Small variant →
     extend `avm2_flixel.c` behind a distinct intrinsic id; large → refuse
     the extension and report. Do not paper over a source-level difference
     with "the A/B passed".

## §1 — Bytecode verification (the heart of the session)

Diff the pool-resolved normalized streams (`SWFRECOMP_FP_DISASM=1`) per
method: RWF vs RWK, RWIC vs RWK, RWF vs RWIC. Classify every difference:

- **(a) Incidental encoding the normalizer provably could cancel.** Extend
  the normalizer ONLY with a probe per the branch-offset precedent (a probe
  that fails under the old rule, passes under the new, and demonstrably
  cannot mask a semantic change). **Any normalizer change re-bakes ALL
  constants** → re-run the §3 verification suite of
  `SWFRecompDocs/prompts/avm2-fingerprint-gate-holes.md` (RWK==RWP,
  determinism, output-neutrality, perturbation) before proceeding.
- **(b) Obfuscator control-flow transforms** (block reordering, opaque
  predicates, jump threading). **Do NOT normalize these away** — a
  normalizer that cancels control flow is a normalizer that matches wrong
  code. Instead: verify semantic equivalence per method by hand/disassembly
  (the methods are small — 2.21's largest is ~200 instructions) and bake a
  **per-title constant** for the verified body.
- **(c) Genuine 2.35 source differences** — must reconcile with the §0.2
  upstream diff. Anything observable lands in the §0.2 variant-or-refuse
  decision; nothing in class (c) may be waved through on A/B evidence alone.

The deliverable of §1 is a written per-method table: RWK-vs-title verdict,
class (a)/(b)/(c), evidence. That table is what licenses the baked constants.

## §2 — Behavioral oracle (the RWK-TAS pattern, no Ruffle needed)

Same-binary A/B — intrinsic arm vs `AVM2_NO_INTRINSICS=1` (native) — with
scripted input and `AVM2_CPU_DUMP`: **byte-identical frames**, non-vacuous
(engagement is LAZY at first `FlxU.collide`; check native call counts, a
boot-only check sees nothing).

- Input plans for RWF/RWIC don't exist yet. The `_rwk_tas` event format via
  `./test_run <events>` should be game-agnostic — verify, then script:
  click-through (both titles stage through two intermediate states, ~45 s,
  click at (0.5, 0.5)) into a live level with entities colliding on screen,
  ≥1000 gameplay ticks per title. State-prove the frames show gameplay
  (the title-screen trap has now cost this arc five sessions).
- Native wall-clock A/B while the harness is warm: default GC, equal ticks,
  ≥3 interleaved rounds, median. **GC=0 is INVALID for wall-clock**
  ([[avm2-native-ab-recipe-gc0-invalid]]).

## §3 — Ship + rig

1. Per-title fallback proof: flip one raw body byte in the SWF → marker 0,
   game runs its own code (recipe in [[avm2-intrinsic-fingerprint-gate]]).
2. Pipeline (`.claude/pipeline-handoff.md`): no-graphics CI; expect 0 delta
   (any `avm2_flixel.c` variant is exercised only by Flixel titles, but the
   recompiler change is sweep-visible).
3. **FRESH wasm rebuilds** (`build_wasm_avm2.sh`; staged wasm rots) +
   redeploys for `docs2/examples/avm2/{rwf,rwic}` — and for rwk/rwp too if
   any normalizer change re-baked their constants.
4. Rig scoreboard: quiet machine (no concurrent native jobs), drain-polling
   `pb_ours_win.py`/`pb_analyze.py` (NOT ti_*), ≥5 interleaved rounds,
   state-proven phases, bad-frame filter AFTER the phase cut, mean<p50 as
   the early-gate tell. Report RWF and RWIC intrinsic vs fallback arms
   (`-DAVM2_FORCE_NO_INTRINSICS=1` builds the fallback arm from the SAME
   recompiled code — wasm has no getenv). **Success = RWF comfortably under
   33 ms** — report the number and the margin plainly, no "borderline".
5. **Honest-sizing clause:** RWF's quadtree share has never been measured
   (the 70.84% is RWK-only; RWIC runs the same code at 18.3 ms, so the share
   varies wildly with workload). Optional cheap pre-check: per-title
   `--toggle-collect` with `abcmap.py`-derived entry points. Non-gating —
   but if the share is small and the rig barely moves, that is the finding;
   report it, don't spin.

## §4 — Deliverables

1. The per-method verification table (§1) in `RWK_AB_STATUS.md` (or a
   sibling doc if it outgrows a section) + the new constants with their
   evidence chain.
2. Updated [[avm2-intrinsic-fingerprint-gate]] constants table; memory write
   for the outcome + the lone-FlxList coupling ruling (whatever it is, the
   2.35-and-beyond precedent is set here).
3. Final playability scoreboard row update: with RWF at margin, the corpus
   is 5-of-5 — say it if true, and state the RWF number that backs it.

## Method rules (binding)

- Never normalize control flow; per-title constants are the honest currency
  for obfuscated bodies.
- Any normalizer change → full holes-prompt §3 re-verification before any
  new baking.
- Ir is not time; rig verdicts only from same-session interleaved arms.
- Fresh recompiles only — shipped `*_build` dirs are stale-prone.
- No local full suites; suite runs via CI. Commit to master, stage by name,
  standard trailer.

## Budget note (delegation)

Fable-led. Opus subagents: fresh recompiles + fingerprint dumps, disasm
extraction, input-plan scripting, rig and CI runs. Fable: the §0.1 coupling
ruling, every §1 classification and equivalence verdict, the §0.2
variant-or-refuse decision, and the final margin call.
