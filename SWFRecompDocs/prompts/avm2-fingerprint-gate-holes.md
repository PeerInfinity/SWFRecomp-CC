# Session prompt — close the two fingerprint-gate holes

**Objective:** the native-intrinsic fingerprint gate
([[avm2-intrinsic-fingerprint-gate]], `SWFRecomp/src/abc/abc_emit.cpp`) has two
documented residual holes. Neither affects the shipped Flixel 2.21 constants,
but both must be closed **before** the next planned session extends the
intrinsic to the obfuscated Flixel 2.35 titles (RWF/RWIC) — obfuscated SWFs
blank debug names (hole 2's exact trigger) and rewrite namespaces (adjacent to
hole 1), and 2.35's quadtree cannot be assumed closure-free until disassembled.
This ordering also means every fingerprint constant is baked exactly once
against the final algorithm.

Read first: [[avm2-intrinsic-fingerprint-gate]] (the design, why raw bytes and
dropped branch offsets are both wrong, the probe methodology),
[[avm2-flixel-native-intrinsic]] (what consumes the gate; lazy engagement
gotcha), and the fingerprint block of `abc_emit.cpp` (~lines 84-620: hashing
at 97-235, disasm 237+, baked table ~548, `intrinsicIdForFingerprint` ~597).

**Scope: recompiler-side hashing only.** No runtime change, no new intrinsic,
no 2.35 work — that is the NEXT session. If a hole's fix seems to demand
runtime changes, stop and re-derive; it shouldn't.

## §1 — Hole 1: same-kind opaque-namespace collision

`hashPoolMultiname` (`abc_emit.cpp:197-218`, caveat comment 190-196): private /
protected / static-protected namespace labels are compiler-minted and unstable
across builds (RWK mints "org.flixel:FlxQuadTree" where RWP mints "20"), so the
label is dropped and only kind + member local name are hashed. Consequence: two
members with the **same local name in two different namespaces of the same
kind** now collide. AS3 mints one protected + one static-protected namespace
per class, so the realistic exposure is kind 0x05 (private) across compilation
units.

**Fix shape (recommended):** canonicalize opaque namespaces by **first-seen
ordinal within the hashed unit** — maintain a per-fingerprint map from
namespace-pool index → dense ordinal assigned in hash-stream encounter order,
and hash `kind + ordinal + local name`. Encounter order is deterministic
because the normalized instruction stream is deterministic, so it is stable
across builds with different pools (the same property the branch
instruction-index deltas exploit). Requirements:
- The ordinal map is scoped to ONE class fingerprint and reset between classes;
  two classes must not share state.
- Distinct pool indices whose namespaces are *identical* (same kind AND same
  label) must map to the SAME ordinal — obfuscators may duplicate pool entries.
  Conversely, do not merge same-kind-different-label entries; distinguishing
  those is the entire fix.
- PackageInternalNs (0x17) / ExplicitNamespace (0x19) stay hashed BY NAME
  (semantically load-bearing) — do not touch them.

## §2 — Hole 2: `hashMethodRef` never looks at the closure body

`abc_emit.cpp:220-227`: `NewFunction`/`CallStatic` operands hash only the
callee's **debug name**. Obfuscated SWFs frequently blank those names, so a
class whose behavior lives inside a closure can match on an unchanged outer
body while the closure differs.

**Fix shape (recommended):** hash the referenced method's **normalized body**
(the same pool-normalized walk used for the primary body — reuse it, do not
fork a second normalizer) plus its signature (param count, param types,
return type as resolved multinames), replacing the debug name. Requirements:
- **Recursion guard**: closures can contain further `NewFunction`s. Track an
  in-progress set; on a cycle or a depth cap, mix in a fixed marker rather
  than recursing. Deterministic across builds is the invariant.
- **Fail-safe propagates**: a referenced body that fails to decode, or a
  bodyless method, must poison the whole fingerprint to 0 (never-match) —
  same rule the primary body already follows (`abc_emit.cpp:93`).
- `hashClassRef` (`NewClass`, :230-235) is out of scope unless you find it
  load-bearing for a real class — note it either way in the writeup.

## §3 — Re-bake, probes, and proof (the deliverable is evidence, not code)

Both fixes change the hash function → **re-bake the two Flixel 2.21 constants**
in the known-intrinsic table (~:548) from a fresh RWK recompile, then verify,
in order:

1. **Cross-title stability holds**: RWK and RWP still produce the SAME new
   constants for FlxQuadTree + FlxList (this was the entire point of
   normalization; RWP's obfuscated namespaces make it the live test for §1's
   ordinal scheme). `SWFRECOMP_DUMP_FINGERPRINTS=2` per-component breakdown
   is the diff tool if they split.
2. **Probe hole 1 closed**: two bodies identical except that members with the
   same local name live in *different* private namespaces vs the *same* one
   must now fingerprint differently. Precedent for probe style: the
   branch-offset probe (shift every target by one instruction → exactly the
   46 branch-carrying RWK classes changed). Synthesize via ABC/pool edit of a
   small SWF if mxmlc can't be coaxed into the shape.
3. **Probe hole 2 closed**: two SWFs identical except a closure body differs,
   debug names blanked — old algorithm matches, new one must not. And the
   inverse stability probe: the same closure compiled in two pools (different
   indices, blanked names) must still match.
4. **Determinism probe**: recompile RWK twice; fingerprints byte-identical.
5. **Emitted-output neutrality**: after re-bake, a fresh RWK + RWP recompile
   emits `RecompiledABC/` **byte-identical** to before the change (same
   `intrinsic_id`s, same everything) — proving no redeploys are needed and
   the fix is invisible outside the gate. If anything differs, explain every
   byte or stop.
6. **Engagement unchanged**: RWK plan_k TAS green with the intrinsic engaging
   (non-vacuous — check the native call counts; engagement is LAZY at first
   `FlxU.collide`, a boot-only check sees nothing); RWP smoke.
7. **Perturbation still fails safe**: the raw-SWF byte-perturbation recipe
   from [[avm2-intrinsic-fingerprint-gate]] (RWK `addToList` body prefix
   `02 02 06 07 B1 01` at 0xc2b82) still zeroes the marker.

## §4 — Deliverables

1. The two fixes + re-baked constants, shipped via the pipeline
   (`.claude/pipeline-handoff.md`): **no-graphics CI** (recompiler-only
   change; the full-suite sweep doubles as the output-neutrality check at
   scale — expect 0 pass→fail, 0 fail→pass).
2. Update the caveat comments in `abc_emit.cpp` and the "TWO RESIDUAL HOLES"
   section of [[avm2-intrinsic-fingerprint-gate]] — they become the record of
   holes CLOSED, with the probe evidence. If a residual risk survives (e.g.
   the recursion depth cap), document it as the new known caveat, not
   silently.
3. Memory write: outcome + any new gotcha (especially anything learned about
   ordinal determinism or closure recursion that the 2.35 session must know).
4. Leave the 2.35 extension untouched — but if disassembly done for probe
   work happens to reveal whether 2.35's FlxQuadTree contains `NewFunction`,
   record that fact; it sizes the next session.

## Method rules (binding)

- Probe-driven, like the branch-offset decision: every claim of "closed" needs
  a probe that FAILED under the old algorithm and passes under the new one.
- Do not weaken anything that exists: branch/lookupswitch instruction-index
  deltas, the fail-safe zero, kind-byte hashing all stay. A fingerprint of 0
  must never match (`abc_emit.cpp:93`).
- Diagnostics: `SWFRECOMP_DUMP_FINGERPRINTS` (=1 report, =2/classname
  breakdown), `SWFRECOMP_FP_DISASM=1` pool-resolved disassembly.
- Recompiles are cheap (~5s scratch); full local test suites are FORBIDDEN —
  single tests locally, the suite via CI.
- Commit direct to master; stage by name; standard trailer.

## Budget note (delegation)

Fable-led. Opus subagents: probe SWF synthesis, the RWK/RWP recompile +
fingerprint-diff runs, TAS re-runs, CI shepherding. Fable: the ordinal-scheme
and recursion-guard design (determinism arguments), and the judgment on any
fingerprint split or output diff.
