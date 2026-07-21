# RWK base-compute perf arc — status & A/B log

Sessions 2026-07-19 (lever 1: `avm2-rwk-base-compute-profile.md`; lever 2:
`avm2-rwk-property-read-endgame.md`; levers 3+4:
`avm2-rwk-store-and-statics.md`; lever 5: `avm2-rwk-typed-values.md`).
Precedent/format: `SEEDLING_AB_STATUS.md`. All rig numbers: Windows Chrome,
real GPU (intel gen-9), driven from WSL via python.exe + Playwright
(`WINDOWS_PLAYWRIGHT_FROM_WSL.md`); metric `__swfPerf.cpu` gameplay p50
unless noted. All native numbers: solo -O2 no-graphics build, RWK plan_k
TAS (`_rwk_tas`), TZ=NPT-5:45.

## ★ SESSION 2026-07-20d — extend the collision intrinsic to the 2.35 titles (RWF / RWIC)

Prompt `SWFRecompDocs/prompts/avm2-flixel-235-extension.md`. Extends the native
`org.flixel` collision intrinsic (lever 7, below) from the two Flixel-2.21
titles to the two Flixel-2.35 titles. **Verification-led**: prove the 2.35
obfuscated collision bytecode is semantically served by the native impl, bake
per-title constants only on that proof, then validate with the same-binary
frame oracle and the rig.

### §0.1 — the lone-FlxList hazard: STRUCTURALLY IMPOSSIBLE (no code change)

Fresh recompiles (post-bake) stamp, per title:

| Title | FlxQuadTree fp / id | FlxList fp / id |
|---|---|---|
| RWK (2.21) | `2c1994f2e30e0642` / 1 | `6e5f899d35ae5140` / 2 |
| RWP (2.21) | `2c1994f2e30e0642` / 1 | `6e5f899d35ae5140` / 2 |
| RWF (2.35) | `d2cd8bafd2ca5111` / 3 | `83ed6120348d3ae2` / 2 |
| RWIC (2.35)| `c15fc34addfdc947` / 3 | `a76edf059e8264ca` / 2 |

Before this session, ALL FOUR of the 2.35 fingerprints stamped id=0 — so the
deployed RWF (30.8 ms) / RWIC (18.3 ms) scoreboard numbers were **pure AS3, not
partially intrinsified**. Critically, RWF/RWIC FlxList do NOT hash to the 2.21
constant (`83ed…`/`a76e…` ≠ `6e5f…`) — the feared "lone FlxList matches while
FlxQuadTree falls back" never occurred.

And it *cannot* occur by construction: `intrinsic_id==2` (FlxList) performs **no
class substitution** — it only sets the `g_flxlist_verified` certificate and
releases a parked quadtree. The native `FlxQTList` C structs are allocated
*exclusively* by `install_quadtree`'s native methods. FlxQuadTree (id 1 or 3)
refuses/parks until FlxList is certified. So native FlxList and native
FlxQuadTree install together or not at all — a native FlxList can never exist
under an AS3 quadtree. **Ruling: the coupling is all-or-nothing; no change
needed. This is the 2.35-and-beyond precedent.**

### §0.2 — upstream ground truth (clean AdamAtomic/flixel source)

Versions confirmed from each title's decompiled `FlxG.as`: RWF/RWIC = 2.35,
RWK/RWP = 2.21. Anchored upstream revisions by the `LIBRARY_MINOR_VERSION`
constant: 2.21 = commit `a2c4d98`, 2.35 = `c5c8369` (FlxQuadTree/FlxList
unchanged across the whole 2.35 commit window). Upstream 2.21 matches RWK's
418-line decompile method-for-method (the native impl's verified target).

Diff of the two classes, **2.21 → 2.35**:
- **FlxList: BYTE-IDENTICAL.** One native FlxList C struct serves all four
  titles; only obfuscation differs.
- **FlxQuadTree: exactly ONE genuine change, in the constructor.** The fixed
  `public static const MIN:Number = 48` was replaced by a computed
  `protected static var _min:uint`, set once by the ROOT as
  `_min = (width + height) / (2 * FlxU.quadTreeDivisions)` and reused by every
  child (it is static); `_canSubdivide = (width > _min) || (height > _min)`.
  All FIVE other methods (`add`, `addObject`, `addToList`, `overlap`,
  `overlapNode`) are byte-identical between 2.21 and 2.35. `quadTreeDivisions`
  defaults to 3 and neither game overrides it (both call `setWorldBounds`
  without the 5th arg), so the divisor is a fixed 6.

Outcome: a **small variant** (§0.2 decision) — a distinct native id (3) that
computes `_min` dynamically. Because coarser/finer subdivision changes tree
depth → traversal → collision-callback order, the fixed-48 impl would diverge
on the frame oracle; the faithful 2.35 variant is both correct AND necessary.

### §1 — per-method bytecode verification table (what licenses the constants)

Every method verified semantically equivalent to clean upstream 2.35 by folding
the per-title opaque predicates (JPEXS decompile, cross-checked against raw
AVM2 p-code exported with FFDec where the structured output was unsound). The
obfuscation is per-title control flow — **not normalized away** (a normalizer
that cancels control flow would match wrong code); instead each obfuscated body
gets its own baked constant.

| Method | RWF | RWIC | Class | Evidence |
|---|---|---|---|---|
| FlxList ctor | ≡ | ≡ | (b) | opaque-pred fold → `super(); object=null; next=null` (2.21≡2.35 source) |
| FlxQuadTree ctor | ≡ | ≡ | **(c)** + (b) | the `_min` change; `_min` root-only, `_canSubdivide=w>_min\|\|h>_min` match clean 2.35 |
| FlxQuadTree.add | ≡ | ≡ | (b) | p-code fold; member-loop null/exists guard, solid→addObject vs group→add |
| FlxQuadTree.addToList | ≡ | ≡ | (b) | p-code fold; A/B head-relink (`_tailB.object!=null` — decompiler artifact cleared) |
| FlxQuadTree.addObject | ≡ | ≡ | (b) | fold w/ operand-order proof; identical containment nw→sw→ne→se, partial nw→ne→se→sw |
| FlxQuadTree.overlap | ≡ | ≡ | (b) | FFDec p-code fold; result-OR accumulation, BothLists split, nw→ne→se→sw recursion |
| FlxQuadTree.overlapNode | ≡ | ≡ | (b) | p-code fold; 9-term short-circuit AABB reject + `_oc(_o,co)` callback order |

Class key: (a) incidental encoding the normalizer cancels — **none found**;
(b) obfuscator control-flow transform, per-title baked constant; (c) genuine
2.35 source difference (the ctor `_min`), served by native id 3.

### Baked constants (evidence chain above) — SWFRecomp/src/abc/abc_emit.cpp

    { 0xd2cd8bafd2ca5111, 3, "org.flixel::FlxQuadTree (Flixel 2.35, RWF)" }
    { 0xc15fc34addfdc947, 3, "org.flixel::FlxQuadTree (Flixel 2.35, RWIC)" }
    { 0x83ed6120348d3ae2, 2, "org.flixel.data::FlxList (Flixel 2.35, RWF)" }
    { 0xa76edf059e8264ca, 2, "org.flixel.data::FlxList (Flixel 2.35, RWIC)" }

Fresh recompiles stamp exactly 2 classes per title (211/229/141/268 total
classes; zero false positives). No normalizer change was made → the 2.21
constants and RWK/RWP stamps are untouched (verified: id 1/2 unchanged).

### §3.1 — per-title fallback proof (fail-safe)

Decompressed each CWS SWF, flipped ONE byte inside the FlxQuadTree method body,
re-emitted as FWS, recompiled:
- **RWF:** FlxQuadTree fp `d2cd…` → `0000000000000000` (body no longer decodes →
  poisoned to 0 → no match), intrinsic 3 → **0**; FlxList untouched (`83ed…`, id 2).
- **RWIC:** FlxQuadTree fp `c15f…` → `e35e7675c840bc98` (decodes but hashes
  differently), intrinsic 3 → **0**; FlxList untouched (`a76e…`, id 2).

Both fail-safe modes demonstrated (undecodable→0, and decodable-but-different).
A one-byte difference in the gated body drops the marker and the game's own
compiled AS3 runs.

### §2 — same-binary frame oracle (intrinsic vs AVM2_NO_INTRINSICS, native)

Scripted gameplay, 2500 ticks, `AVM2_CPU_DUMP` frames diffed between arms:
- **RWF: 2500/2500 frames byte-identical.** Non-vacuous (`FLIXEL_STATS
  variant=2.35 ctor=146796 add=35738 addObject=2510701 overlap=200597
  overlapNode=382270`); fallback arm emitted no stats line (install skipped —
  correct control). Native wall-clock 1.19x (median of 4 interleaved).
- **RWIC: 2500/2500 byte-identical.** Non-vacuous (overlap=132882,
  addObject=270123); fallback control correct. Native wall-clock 1.09x.

Byte-identical frames prove the dynamic-`_min` variant reproduces the game's own
subdivision + traversal + callback order exactly (a wrong `_min` → different tree
→ different callback order → divergence). Gotcha resolved: the blank-stage trap
is the LocalConnection site-lock — build/run with
`SWF_URL=http://www.maxgames.com/test.swf` (localhost blanks the stage). Event
coords are STAGE PIXELS, not normalized.

### §3.2 — CI: no-graphics, run 29795479062, **green, 0 regressions** across all
10 suites ("No changes detected"). The recompiler bake is sweep-visible but the
2.35 variant touches only Flixel titles, absent from the suites → 0 delta.

### §3.4 — RIG SCOREBOARD (real-GPU Windows Chrome intel gen-9, 5 interleaved rounds, state-proven)

Arms from the SAME recompiled game code: `rwf`/`rwic` have the intrinsic;
`rwf_noint`/`rwic_noint` are built `-DAVM2_FORCE_NO_INTRINSICS=1` (the game's own
AS3 quadtree; wasm has no getenv). Distinctness proven: `FlxQuadTree/*$native`
symbols present in the intrinsic wasm, dead-stripped from `_noint`.

| title | arm | round-mean median | p50 | %>33ms | p95 | 30 fps? |
|---|---|---|---|---|---|---|
| **RWF** | **intrinsic** | 22.8 | **21.6** | **1.4%** | 28.5 | **YES** (11.4 ms margin) |
| RWF | fallback (own AS3) | 30.6 | 29.0 | 17.6% | 38.4 | marginal (p95 breaches) |
| **RWIC**| **intrinsic** | 15.6 | **14.7** | **0.5%** | 20.9 | **YES** (18.3 ms margin) |
| RWIC | fallback (own AS3) | 17.2 | 16.1 | 0.5% | 22.5 | yes |

**HEADLINE: RWF intrinsic gameplay p50 = 21.6 ms — 11.4 ms under the 33 ms
budget, comfortably (not borderline): only 1.4% of frames breach 33 ms and even
p95 is under. Intrinsic 1.34x faster at p50, over-budget share 17.6% → 1.4%.**
RWIC 14.7 ms p50 (1.10x; lighter quadtree share, per the honest-sizing clause
§3.5 — RWIC's collision is a smaller slice of its frame than RWF's). Raw:
`/mnt/c/playwright/pb_intr/`.

### Scoreboard: with RWF at margin, the corpus is **5-of-5 clearing 30 fps**
(Seedling ✓ RWIC ✓ RWF ✓ RWK ✓ RWP ✓).

## ★ SESSION 2026-07-20c — native intrinsic org.flixel collision classes (lever 7)

Prompt `SWFRecompDocs/prompts/avm2-flixel-native-collision-intrinsic.md`. Builds
the lever the 2026-07-20b gate priced at ~24.1 ms. **Shipped.** Native
wall-clock **2.593x**; rig verdict in §5 below.

### §1 CORRECTION — the corpus does NOT share one quadtree

`RWK_AB_STATUS.md:180` (previous session) claimed all four Robot Wants titles
ship byte-identical quadtree source, and that "one substitution covers the whole
corpus". **Both halves are wrong.** Settled with source diff + ABC bytecode:

| title | `FlxQuadTree.as` | Flixel | obfuscated? |
|---|---|---|---|
| RWK | 418 lines | 2.21 | no |
| RWP | 418 lines, **byte-identical to RWK** | 2.21 | namespace labels only |
| RWF | 2838 lines | 2.35 | **yes** — control-flow flattening |
| RWIC | 2694 lines | 2.35 | **yes**, different seed |

RWF/RWIC decompile with `§§push`/`§§goto`/opaque predicates and their
`FlxList.as` differ *from each other*, so no single 2.35 constant could ever
cover them. **The 2.21 pair is exactly the two unplayable titles**, so scoping
this session to 2.21 costs nothing that mattered.

Semantic audit re-verified at HEAD: `FlxQuadTree` referenced only by `FlxU.as`
and itself, `FlxList` only by `FlxQuadTree` and itself, zero `extends` of either
in any title, `FlxU.roundingError` assigned exactly once (1e-7) and never
mutated.

### §2 The fingerprint gate — pool-normalized, not raw bytes

**Raw method-body bytes are the wrong hash.** ABC embeds constant-pool
*indices*, so identical source in two SWFs produces different bytes — one baked
constant per game, i.e. exactly the per-game setting the objective forbids. The
fingerprint therefore hashes *resolved content* (FNV-1a 64 over `abc_emit.cpp`):

- multiname / string / int / uint / double / namespace operands → resolved
  content, never the index;
- **branch and `lookupswitch` offsets → instruction-index deltas**, not byte
  deltas — cancels the varint-width artifact while preserving branch topology;
- private / protected / static-protected namespace **labels** → fixed token
  (kind and member local name still hashed) — RWP's obfuscator rewrites these
  to tokens like `"20"`;
- exception table `from`/`to`/`target` as instruction indices + resolved
  `type_name` and `variable_name`;
- any body that fails to decode → 0 → **never matches** (fail safe).

| title | `org.flixel::FlxQuadTree` | `org.flixel.data::FlxList` | markers of 141 classes |
|---|---|---|---|
| **RWK** | `b7af5a5f4dc54f98` | `6e5f899d35ae5140` | **2** |
| **RWP** | `b7af5a5f4dc54f98` | `6e5f899d35ae5140` | **2** |
| RWF | `b92b57112bab6136` | `83ed6120348d3ae2` | 0 — falls back |
| RWIC | `54fdfca6aedb7a83` | `a76edf059e8264ca` | 0 — falls back |

One constant covers both 2.21 titles despite different pools *and* obfuscated
namespaces: a library-signature table, not a per-game setting.

**Why RWK and RWP first disagreed** (worth recording — it cost a diagnosis
cycle): raw-byte hashing split them even though the classes are the same
program. Cause was threefold — RWP's obfuscated namespace labels, plus branch
byte-offsets shifted purely because RWK's *larger constant pool* widens U30
varints (bodies 731 vs 699 bytes etc.). Disassembly proved 1069 instructions on
both sides in identical order. **Falsified along the way:** debug opcodes were
not involved.

**Branch topology is provably still load-bearing.** Probe: shift every resolved
branch target by one instruction → exactly the 46 RWK classes containing
branches changed fingerprint, exactly the 95 without were unchanged. Zero false
positives, zero false negatives. This matters because the tempting cheap fix —
dropping offsets entirely — would let `if (a) X else Y` and `if (a) Y else X`
hash alike, and that is precisely the substitution the gate exists to refuse.

**⚠ SUPERSEDED 2026-07-20 (`ad4ee3754`): both holes below are now CLOSED** —
(1) by first-seen-ordinal canonicalization of opaque namespaces, (2) by
recursive normalized closure-body + signature hashing (depth-capped,
fail-safe). Constants re-baked (FlxQuadTree `2c1994f2e30e0642`; FlxList
unchanged), RWK==RWP re-verified, emitted output byte-neutral, probe evidence
per hole. See `SWFRecompDocs/prompts/avm2-fingerprint-gate-holes.md` §3 for
the verification suite and the memory `avm2-fingerprint-gate-holes-closed`.
The text below is retained as the historical record of the gap:

**Residual risk, on the record and NOT closed:**
1. Two members with the same local name in two *different* private namespaces of
   one class now collide (AS3 gives a class one protected + one static-protected
   ns, so realistic exposure is private namespaces only).
2. `hashMethodRef` (`NewFunction`/`CallStatic`) hashes only the callee's **debug
   name**, never its body — and obfuscated SWFs frequently blank those names. A
   class whose behavior lives inside a closure could match on an unchanged outer
   body. `FlxQuadTree` contains no `NewFunction` (disassembly-confirmed), so
   neither affects the baked constants — **but both must be closed before
   intrinsifying any closure-building class.**

### §3 The implementation — only the ROOT stays an AS3 object

`SWFModernRuntime/src/avm2/avm2_flixel.c` (~950 lines), order-identical to the
418-line 2.21 source, every C function tagged with its AS3 line numbers.

The root `FlxQuadTree` must stay an `Avm2Object` (`FlxU.quadTree` is a typed
static holding it); its `native_ext` carries the C tree + a per-root bump arena.
**Every child node and every `FlxList` node is a pure C struct** — licensed by
the audit (`_nw/_ne/_se/_sw` and `_headA/_tailA/_headB/_tailB` are `protected`,
never subclassed, never escape). That is what removes the ~2410 object births
per tick rather than only the dispatch. `FlxObject` stays fully AS3, read
through cached vtable slot indices, so the callback-visible surface is
unchanged — as the ~24.1 ms estimate already assumed.

Mechanism corrections vs the session prompt, both load-bearing:
- **The native signal is `ref.file == NULL`, NOT `fn == NULL`.** `fn==NULL,
  file!=NULL` is a *fatal* "method with no body"; leaving a stale `file` makes
  dispatch index `method_index` into the game's own method table.
- **`native_construct` is the wrong hook** — it short-circuits object allocation
  entirely (`avm2_class.c:1174-1177`). Correct hook is overriding
  `cls->instance_init` plus `native_ext_size`/`native_init`.
- `avm2_vtable_append` has no dedup and lookups are first-match-wins, so
  overrides must mutate entries **in place**.
- Install is **two-phase** (resolve every target, then commit). A first cut
  could patch `overlap`, fail on `add`, and return 0 with a half-patched vtable
  whose native `overlap` returns false — silently killing collision instead of
  falling back.

GC: precise ext tracer walks the C tree marking `FlxQTList.object` edges (the
conservative blob scan cannot follow into arena chunks); free hook releases the
arena on sweep; the `_o`/`_oc` statics became C globals and are marked as roots.

Kill switch `AVM2_NO_INTRINSICS=1` skips installation, so one binary provides
both A/B arms and a live escape hatch.

### §4 Validation ladder

**Rung 1 — TAS oracle: PASS, and non-vacuous.** plan_k, 1560 ticks, one binary,
intrinsic arm vs `AVM2_NO_INTRINSICS=1`. **All 1560 `AVM2_CPU_DUMP` frames
byte-identical** (sha256), trace identical, exit 0 both. Instrumented counters:
native **ctor 11555, add 23112, overlap 17976 = 52,643 calls** in the intrinsic
arm, zero in fallback. (RWK's stdout is only a boot banner, so the *frames* are
the oracle; the trace half carries almost no signal.)

**Rung 2 — fallback proof: PASS, strong form.** Raw SWF byte perturbation, not a
table edit. `FlxQuadTree.addToList`'s body found at SWF offset `0xc2b82` via its
`method_body_info` prefix; one byte at `0xc2b8b` `0x80`→`0x86` turns
`coerce FlxList` into `astype FlxList` on a provably-dead local. Fingerprint
`b7af5a5f4dc54f98` → `1af342200a397356`, `intrinsic=1` → **0**; FlxList
untouched stayed at 2. The perturbed build printed no install message and its
1560 frames are byte-identical to the *unperturbed fallback* frames — the
perturbation was inert while still flipping the gate.

**Rung 3 — native wall-clock A/B: 2.593x.** Default GC (GC=0 is invalid for
wall-clock), 1560 equal ticks, strictly interleaved, 5 rounds, same binary.

| round | intrinsic | fallback | speedup |
|---|---|---|---|
| 1 | 14.48 s | 35.68 s | 2.464x |
| 2 | 13.69 s | 35.42 s | 2.587x |
| 3 | 13.76 s | 35.48 s | 2.579x |
| 4 | 13.55 s | 36.45 s | 2.689x |
| 5 | 14.20 s | 36.47 s | 2.568x |
| **median** | **13.76 s** | **35.68 s** | **2.593x** |

Spreads do not overlap. Per-tick 8.82 ms vs 22.87 ms. **RWK needs 1.85x.**

**This is the arc's third Ir→wall-clock conversion attempt and the first that
converted** (lever 5: −13.1% Ir → ~1.1x; lever 6: −5.16% → nothing resolvable).
The gate's stated reason for expecting this one to convert — the removed work is
pointer-chasing with plausibly higher-than-average CPI, unlike the cheap
predictable instructions levers 5/6 removed — held up.

**Rung 4 — RWP: PASS, and a free second oracle.** RWP ships the same 2.21
quadtree; the recompiler stamps the same markers (class 26 → id 1, class 48 →
id 2), install confirmed (all four FlxRect slots resolved, ctor 6146 / add 12292
/ overlap 9560 over 1200 ticks). Built an RWP TAS (click New Game, then
right/left/jump cycles) and attested the stage live three ways (frame variety,
visual inspection of title→in-level→scrolled-room, and the robot *resting on*
platforms = tile collision through the quadtree). **All 1200 frames
byte-identical between arms** — a free oracle on RWP's own geometry and object
mix that RWK's plan never touched. *Gotcha recorded:* the intrinsic installs
**lazily at the first `FlxU.collide`, not at boot** (class link is lazy), so any
boot-only engagement check sees nothing and would wrongly call it dead.

### §5 RIG SCOREBOARD — both unplayable 2.21 titles now clear 30 fps

Fresh HEAD wasm for every arm (`build_wasm_avm2.sh`, staged wasm rots on runtime
change — each redeploy md5-checked build→docs2). Real-GPU Windows Chrome from
WSL, drain-polled `__swfPerf.cpu`, state-proven phases, **5 interleaved rounds
on a quiet machine** (the rig waited out the concurrent native jobs — none
overlapped these rounds). Raw: `/mnt/c/playwright/qt_2026-07-20/`.

The A/B arms come from the **same recompiled game code**: `rwk` has the intrinsic
engaged; `rwk_qtbase` is built `-DAVM2_FORCE_NO_INTRINSICS=1` so the game's own
AS3 quadtree runs (wasm has no env for the `AVM2_NO_INTRINSICS` switch). Proven
distinct: `FlxQuadTree/overlap$native` is present in the `rwk` wasm and absent —
dead-stripped — from `rwk_qtbase`.

| arm | mean | p50 | %>33ms | p95 | stalls>250 | 30 fps? |
|---|---|---|---|---|---|---|
| **RWK intrinsic** | **21.6** | 20.3 | **1.3%** | 29.5 | 0 | **YES** (was 61.1) |
| RWK fallback (own AS3) | 60.8 | 58.4 | 100% | 88.2 | 0 | no — the control |
| **RWP intrinsic** | **22.5** | 21.3 | **1.7%** | 28.0 | 0 | **YES** (was 47.5) |
| RWF (2.35, no intrinsic) | 20.6 | 12.3 | 9.0% | 35.5 | 10 | falls back; re-measures well |

Median across 5 rounds of each round's mean; RWK spread 19.5–25.8, RWP 21.7–23.5.

**The verdict, against the 24.1 ms prediction: the lever BEAT it.** RWK landed at
**21.6 ms**, under the predicted 24.1. **RWK same-session speedup 2.82x**
(fallback 60.8 → intrinsic 21.6), against the 1.85x the bar required. The gate's
counterfactual method, which failed twice on wall-clock (levers 5/6), converted
here and slightly *under*-predicted the win — consistent with its own argument
that the removed work is high-CPI pointer-chasing.

**One fingerprint-gated intrinsic makes both 2.21 titles playable, generically —
no per-game setting.** The scoreboard now reads: Seedling ✓, RWIC ✓, RWF
borderline, **RWK ✓ (new), RWP ✓ (new)**. Four of five titles clear 30 fps; the
fifth (RWF) is 2.35 and falls back correctly.

Two honest side-notes:
- **The 20b RWK absolute was NOT badly contaminated after all.** Its 61.1 ms
  carried a self-owned caveat that a concurrent callgrind job might have
  inflated it; this quiet-machine fallback arm reads 60.8 ms — essentially
  identical, so 61.1 stands.
- **RWF re-measures clearly better than 20b's borderline 30.8 ms/22%.** At 20.6
  mean / 12.3 p50 / 9.0% over it is comfortably inside the bar on p50, though 10
  frames >250 ms (level-gen churn, not the quadtree — RWF doesn't run the
  intrinsic) drag the mean above p50. 20b flagged RWF as the one call a quieter
  re-run could move; it moved.


Prompt `SWFRecompDocs/prompts/avm2-playability-scoreboard-and-quadtree-gate.md`.
Measurement + gate decision; **no lever shipped, by design**. Objective is
**30 fps = 33 ms**, not parity with Ruffle. Raw: `/mnt/c/playwright/pb_2026-07-20/`
(rig), session scratchpad (callgrind). All five demos were **recompiled and
rebuilt FRESH at HEAD** first — every deployed wasm predated lever 5.

### §1 The scoreboard — 5 titles, same day, same rig, 5 interleaved rounds, state-proven

| title | ours mean | ours p50 | ours %>33ms | Ruffle mean | Ruffle %>33ms | 30 fps? |
|---|---|---|---|---|---|---|
| Seedling | **18.4** | 16.9 | **0.5%** | 36.9 | 77.3% | **YES (ours only)** — we win ~2.0x |
| RWIC | **18.3** | 16.3 | **0.8%** | *Ruffle renders nothing* | — | **YES** |
| RWF | 30.8 | 28.6 | ~22% | *Ruffle renders nothing* | — | **BORDERLINE** |
| RWP | 47.5 | 44.7 | 100% | 41.7 | 99.1% | **NO — neither engine** |
| RWK | 61.1 | 56.4 | 100% | 54.9 | 100% | **NO — neither engine** |

**Two of five titles already clear 30 fps; a third is on the line.** The
pipeline already "just works" for part of the corpus — the remaining problem is
narrower than the arc assumed. Zero frames >250 ms in any of our arms (tier-2
GC holding).

- **We run two titles Ruffle cannot.** `rwf_ruffle` and `rwic_ruffle` load the
  SWF, tick at ~60 fps for 90 s, and **never draw a single shape**
  (`__rufflePerfDraws` stays 0, stage solid black). Byte-identical SWFs are
  served to both engines, so this is Ruffle's own failure. Their "0.3-0.5 ms
  frames" are the cost of rendering nothing — **never quote them as a Ruffle win.**
- RWK/RWP: Ruffle is ahead in 5/5 paired rounds (~1.11x / ~1.14x on mean) but
  the round spreads overlap heavily. A small consistent edge, not a defensible
  ranking — and **moot**, since both engines are at ~100% of frames over budget.
- RWF's `%>33ms` sits ON the line and swings 10%→65% on a small mean shift.
  Read it as "borderline", never as a percentage.

**Two measurement bugs found and fixed — both the title-screen trap in new
clothes.** (1) `__swfPerf.cpu` is a **120-slot circular** buffer and Ruffle's
rings ~600, both SHORTER than a 30 s window, so a single end-of-window read
silently mixes in menu frames; both drivers now drain-poll. (2) RWIC/RWF stage
through two cheap intermediate states and take ~45 s to reach a live level; the
tell for the early-gate bug was **mean < p50**. Note `__swfPerf` marks
level-generation stalls `bad`, so the bad-frame filter must run AFTER the
phase cut or it deletes the marker being looked for.

⚠ **Caveat I own:** part of this rig run overlapped a native callgrind job on
the same machine, so the ABSOLUTES may be inflated (a single smoke run of RWK
under heavier concurrent load read 94.7 ms p50 vs 56.4 here). All arms were
interleaved under the same conditions, so **paired comparisons and the
far-from-the-line verdicts (Seedling, RWIC) are sound**; RWF's borderline call
is the one a quieter re-run could move.

### §2 Fresh HEAD native profile (the first since post-lever-1)

600t plan_k TAS, state-attested (tick 599 dumped: live PlayState, not a menu).
GC=0 **38.012B Ir** — bit-identical to the recorded post-lever-6 figure, as
expected since no runtime code changed since `93299b884`. Default GC 39.577B;
**the collector is now only 3.95% of Ir** (tier-2 landed). Menu prefix = 5.8%.
Ranked GC=0 leaders: `blend_over` 7.23, `getproperty_static_ic` 5.64,
`resolved_get` 5.23, **`abc0_m484` (FlxQuadTree.addObject) 4.71**,
`setup_locals` 3.58, `coerce_to_class` 3.40, `coerce_to_type_mn` 3.36,
`o1heapAllocate` 2.74, **`abc0_m486` (FlxQuadTree.overlap) 2.72**.

**The widely-quoted "property GET 28.4%" is retired** — it was extrapolation
from the post-lever-1 profile. At HEAD the GET cluster is ~11%.

### §3 THE GATE — the quadtree is 70.84% of the frame

**Method (reusable).** ABC method IDs were *derived*, not guessed: parse the
emitted `abc0_tables.c` pools + class/trait arrays to map `abc0_mNNN` → AS3
(`scratchpad/abcmap.py`, `mapnames.py` — two independent implementations that
agree). **m482 ctor, m483 add, m484 addObject, m485 addToList, m486 overlap,
m487 overlapNode = `org.flixel::FlxQuadTree`; m593 = `FlxList` ctor.** Gotcha:
the emitted string/namespace/multiname pools already contain their index-0
sentinel — prepending a placeholder shifts every name by one and yields
plausible garbage.

**Attribution instrument: `--toggle-collect`** entered at `m483`/`m486`, the
only two entry points that never nest (both called solely from
`FlxU.overlap`/`collide`). Every descendant Ir is counted in caller context
exactly once, with no attribution model. Validated: `blend_over` = **0 Ir**
inside the region. **Two instruments were tried and DISCARDED — record them so
nobody re-derives them:** proportional flow propagation smears through the
single `avm2_call_method_ref` dispatcher (it assigned the software blitter
w=0.54); callgrind edge-*inclusive* costs suffer cycle inflation (reports
`m486`-inclusive as 85B against a 38B run). Also: `--toggle-collect` is a
**toggle, not a nesting counter** — seeding it on `m482` anti-collects every
nested `new FlxQuadTree`.

**Result: the Flixel collision-quadtree subsystem is 70.84% of total Ir
(26.926B / 38.012B), 75.22% of gameplay-only Ir.** Split:

| | Ir | % of run | % of QT |
|---|---|---|---|
| (i) allocation + constructor execution — poolable | 7.078B | **18.62%** | 26.3% |
| (ii) insert/traverse/overlap logic — NOT poolable | 19.848B | **52.21%** | 73.7% |

Component breakdown of the region: property GET 17.10% of QT · AS3 method
bodies 16.38 · coerce 14.46 · call/dispatch+locals 14.06 · arithmetic/equality
9.25 · **allocator+object birth 9.21** · name resolution 9.70 · property SET
3.91 · collision callbacks 2.29. Concentration: **54% of all `o1heapAllocate`
Ir in the whole program runs inside FlxQuadTree constructors**; 38% of
`setup_locals`. The non-quadtree remainder (29.16%) is almost entirely blit —
**the RWK frame is quadtree + blit and very little else.**

Structure (`xplor/PlayState.as:394-402`): **9 tree rebuilds + 14 traversals per
tick**, every tree discarded (`collide` builds once and traverses twice, for the
X then Y solve). Cross-checks with the lever-6 census (2410 nodes/tick).

#### GATE VERDICT: **PASSES — but pooling is NOT the lever that passes it**

RWK needs **1.85x** (mean 61.1 → 33 ms). Counterfactuals, Ir share as proxy:

| scenario | Ir removed | frame | vs 33 ms |
|---|---|---|---|
| **entire subsystem free** | 70.84% | **17.8 ms** | **passes** |
| pooling, generous (all of bucket (i)) | 18.62% | 49.7 ms | fails |
| **pooling, honest** (allocator + object birth only) | 6.52% | 57.1 ms | **fails** |
| order-identical AS3 reimplementation | ~39.2% | 37.1 ms | **misses** |
| **order-identical NATIVE reimplementation** | ~60.5% | **24.1 ms** | **passes** |

**Pooling is dead on arithmetic, structurally.** Only 9.21% of the region is
allocation at all (`o1heapAllocate` is 3.43% of it); the rest is the AVM2 cost
of *executing* the algorithm. And a recycled node is not a free node — the
ctor body is dominated by the **parent-list copy loops** and ~12 field stores
that any `recycle()` must still run (later Flixel's own `recycle()` does
exactly this). This re-confirms [[avm2-alloc-arc-ruled-out]] from a new angle.

**Do not build the pooled instrument of §4.** Its prize is now known in
advance — which is precisely what levers 5 and 6 lacked.

#### Corpus check + the validation tension

- ~~**All four Robot Wants titles ship the IDENTICAL unpooled quadtree**~~ — zero
  `recycle`/`_cachedTreesHead` in RWK's 2.21 or the sequels' 2.35 (both predate
  the Flixel version that added pooling). So the hoped-for "sequels are faster
  because they pool" natural experiment **does not exist**, ~~and one substitution
  covers the whole corpus.~~
  > ⛔ **CORRECTED 2026-07-20c — see SESSION 2026-07-20c §1.** The "unpooled"
  > half stands. The "identical" half is **wrong**: RWK/RWP ship Flixel 2.21
  > (418 lines, byte-identical to each other) while RWF/RWIC ship a materially
  > different 2.35 *and are control-flow obfuscated with different per-title
  > seeds*. One substitution covers the 2.21 pair only — which is fine, because
  > that pair is exactly the two unplayable titles.
- **The cheap oracle only validates the worthless lever.** `_rwk_tas` proves
  byte-identical trace + frames, but `overlapNode` invokes the collision
  callback in node-list order and those callbacks **mutate positions** — so any
  change to tree *shape* changes the frames even when correct. Pooling and an
  order-identical reimplementation are TAS-validatable; an algorithm change
  (spatial hash, skip-tree-for-small-N) has a bigger prize but **forfeits the
  oracle** and needs a weaker one.
- **Semantic-risk audit for the two classes, verified not assumed:** zero
  `extends` of either class in any of the four titles; every
  `describeType`/`getQualifiedClassName`/`getDefinitionByName` site is in
  dead-linked `mx.*` Flex code and none targets them; `FlxList` never escapes
  `FlxQuadTree`. Residual risk that does NOT go away: the callback still reads
  `.x/.width/.exists/.solid` off real AS3 `FlxObject`s, so some AVM2 property
  access survives any native implementation — the 60.5% row above is an
  estimate with that already discounted, not a ceiling.

### §5 DIRECTION CALL

1. **Two of five titles are already playable** (Seedling, RWIC), RWF is on the
   line, RWK and RWP are not — and Ruffle misses 30 fps on every title it can
   render. This is a **workload** problem, not a competitive one.
2. **The split:** the wasteful *algorithm* is the game's (9 rebuilds/tick,
   discarded); the *cost per operation* is ours (property GET + coerce +
   dispatch + name resolution = 55% of the region). RWK's frame is both,
   multiplicatively. Six levers have attacked the second factor (~2.9x
   compute); nobody has attacked the first.
3. **Next investment: form (b), native intrinsic `org.flixel` collision
   classes — and it should NOT be gated behind (a).** The prompt gates (b) on
   semantic risk; for these two classes that risk is audited and tame, while
   the arithmetic says **(a) alone lands at ~37 ms and misses the bar, and only
   (b) reaches it (~24 ms)**. Fingerprint the class and **fall back to the
   game's own code on any mismatch** — non-negotiable, and cheap here because
   all four titles share byte-identical source.
4. **Deferred, deliberately:** the lever-7 runtime work (form (c)). At 70.84%
   quadtree, generic runtime levers are attacking the same instructions from a
   worse angle.

**Ir is not time.** Every counterfactual above is an instruction-count proxy;
this arc has twice failed to convert Ir to wall-clock (lever 5: −13.1% Ir →
~1.1x; lever 6: −5.16% → nothing resolvable). Two things argue this case
converts better — the removed work is pointer-chasing (property GET, vtable
walks), plausibly *higher* CPI than average, unlike levers 5/6 which removed
cheap predictable instructions; and native runs the **scalar** blit, so the
quadtree's share of the *wasm* frame is if anything higher. Validate any build
on wall-clock, never on Ir.

**Open, NOT answered here:** why RWK (61.1) is 3.3x RWIC (18.3) on identical
quadtree code — static collide/overlap call-site counts *invert* the ordering
(RWIC 16 sites, RWK 9), so the driver is dynamic (live object counts, map size).
**The 70.84% is measured for RWK only; do not transfer it.** A per-title
toggle-collect run settles it cheaply. Also unbuilt: the symbolicated
(`--profiling-funcs`) wasm CDP profile at HEAD — `build_wasm_avm2.sh` has no
such flag, so it needs its own FRESH build.

## ⛔ VERDICT 2026-07-20 — the "11x Ruffle gap" never existed. Arc goal changed.

Session prompt `SWFRecompDocs/prompts/avm2-title-inversion-diagnosis.md`
(diagnosis, no lever shipped). Raw: `/mnt/c/playwright/ti_2026-07-20/`;
drivers `ti_rwk_ruffle.py` (corrected Ruffle) + `ti_perf.py` + `rw_ab.py`.
**Everything below supersedes the "Ruffle plays this at 6.4 ms" anchor quoted
in the lever-1 section and in every session prompt written from this doc.**

### Step 0 — the old anchor was the title screen. Proven, not inferred.

`/mnt/c/playwright/rw_perf_2026-07-18/rwk_ruffle_final.png` — the screenshot
saved by the very run that produced the 6.4 ms figure — **is the Robot Wants
Kitty title screen**, buttons and all. The driver (`rw_perf_ruffle.py`) only
ever centre-clicked (320,240) *for keyboard focus*; that is dead space, and it
was a single-turn `mouse.click()`, which Flixel's `FlxButton` ignores (it needs
press and release on separate ticks). Both "phases" sampled the same menu —
hence the impossible +3% menu→"gameplay" delta that triggered this session.

Corrected driver `ti_rwk_ruffle.py`: real press/hold/release at the "Play Game"
button (CSS (200,311); the Ruffle page pins the stage 1:1 at 640x480, so no
1.217 scale correction applies there — that factor is our `demo.html` canvas
only), plus **state attestation**: `__rufflePerfDraws` p50 goes 1 → 65, and
`rwk_ac_after_ruffle_final.png` shows the live PlayState (tilemap, robot, cat,
enemies, HUD clock). Every round below is state-proven; no phase is labelled
from hope.

### The corrected table — same day, same rig, same drivers, 5 interleaved rounds

| title | ours | Ruffle | verdict |
|---|---|---|---|
| RWK (Flixel 2.21) | **107.1 ms** p50 (105.7–109.5) | **82.5 ms** p50 (82.3–83.7) | **we lose 1.30x** |
| Seedling (FlashPunk) | **30.5 ms** mean (29.6–30.7) | **46.2 ms** mean (46.1–46.8) | **we win 1.51x** |

Round-to-round spread is remarkably tight on both sides (Ruffle RWK spans
1.4 ms across five rounds), so these are not noise-limited. Effective tick rate
agrees independently with frame CPU: ours ~9 fps (`__swfPerf.interval` p50
110 ms) vs Ruffle ~11 fps (rAF p50 88 ms, and Ruffle ticks once per rAF).
Capped vs `perfbench=1` uncapped is a no-op on both titles (RWK 107.1→106.9,
Seedling 30.1→30.5), so no figure here is frame-limiter-bound.

**Controls run:**
- Ruffle on the plain un-AP-injected 716528-byte SWF: **83.1 ms** vs 82.5 ms on
  the injected one. The injection is not what makes Ruffle slow.
- Our 2026-07-15 `seedling_msimd` build re-measured today: **37.4 ms**, i.e.
  *worse* than today's 30.5. So our Seedling progress is real and there is no
  regression — but see below.

### So: how much of the claimed 11x survives? **None of it.**

The gap is **1.30x**, and the cross-title swing that motivated the session is
**~2.0x**, not ~30x. There is no structural inversion to explain — a 2x spread
between two engines' workload mixes is ordinary, and well inside what single
levers in this arc have already moved.

**Both headline anchors were unreliable, in opposite directions.** The RWK
6.4 ms was a title screen. And the Seedling **16.5 ms** on record does not
reproduce: Ruffle's Seedling side reproduces exactly (46.2 today vs ~46 on
record), while ours measures 30.5 — and the older build measures *worse*, so it
is not a regression. The 16.5 ms figure was a lighter scene or a different
filter, and "2.8x faster than Ruffle" should be read as **1.51x** until someone
re-derives it. `swfrecomp-purpose-beat-ruffle-perf` needs both numbers fixed.

### Step 1 — object birth/death is NOT the next arc (falsified)

Sized from the post-lever-1 CDP profile (`rwk_prof_postlever_2026-07-19.json`,
31,338 samples), with call-tree ancestry rather than name-guessing:

| cluster member | % self |
|---|---|
| GC census sort (`wrapper_cmp`/`sift`/`trinkle`/`cycle`/`__qsort_r`) | 7.88 |
| constructor path (`setup_locals`, `slots_init_defaults`, `class_construct`, …) | 4.44 |
| allocator (`o1heapAllocate`/`heap_alloc`/`heap_free`/`avm2_alloc`) | 1.72 |
| GC mark/trace/sweep driver (`gc_collect`, `mark_value`) | 1.05 |
| **cluster total** | **15.09** |

But that profile predates tier-2 GC and lever 6, **both of which already
harvested this cluster**: tier-2's arena bitmap deleted the census sort
outright (snap 36.5 ms → 0.02 ms per collect — the whole 7.88% row), and lever 6
cut `slots_init_defaults` −92%. Re-deriving leaves **~6% at current HEAD**;
the most current native figure agrees (post-lever-6 Ir, GC=0: `setup_locals`
3.58 + `o1heapAllocate` 2.74 + `slots_init_defaults` 0.42 = **6.74%**).

Counterfactual ceiling if allocation were *free*: **<1.10x**. And this arc has
repeatedly failed to convert Ir into wall-clock (lever 5: −13.1% Ir → ~1.07x;
lever 6: −5.16% Ir → no resolvable wall-clock change at all). **A
nursery/bump-allocator + generational collector is not the next arc** — it
targets ~6% of the frame for at most 1.1x, and it would fight the conservative
ext scan, the arena bitmap membership test and the pinned/immortal surfaces for
that. Ruling it out is the point of this session.

~~For scale, the largest remaining cluster in the same profile is **property GET
at 28.4%** (`getproperty_static_ic` 8.82, `resolved_get` 6.78, `value_vtable`
3.43, `vtable_find_mn` 2.56, …) — ~5x the allocator opportunity, and the thing
six levers have already been chipping at.~~ **RETRACTED 2026-07-20b — this was
extrapolation from the post-lever-1 profile. The fresh HEAD profile puts the GET
cluster at ~11%, and the real headline is the quadtree at 70.84%. See the
session section at the top of this file.**

### What the arc's question becomes

Not "why do we lose 11x to Ruffle" — we lose 1.30x. The real finding is that
**Ruffle only manages ~11 fps on RWK gameplay on this rig either**. Both
engines miss 30 fps (33 ms) by a wide margin: Ruffle by 2.5x, us by 3.2x. So
the goal is **RWK's own frame budget**, not parity with Ruffle — and beating
Ruffle on RWK now needs 1.3x, which is one good lever, not a multi-session arc.

Open items this session deliberately did NOT chase: profiling Ruffle's own
frame to see where *its* 82 ms goes (never done; would say whether 33 ms is
even reachable for this title in wasm), and re-deriving the Seedling 16.5 ms.

## ⚠ Native measurement recipe — CORRECTED 2026-07-19 (read before A/B'ing)

**The recipe used by levers 1-5 — "native user-s, 2900 ticks GC=0, interleaved
×3" — is INVALID for wall-clock comparison, and every session prompt written
from this doc has inherited it. Do not reuse it.**

At `AVM2_GC=0` the run ends when the 4 GB arena is exhausted, NOT at
`AVM2_MAX_TICKS`. On the alloc/ctor session's builds that happened at **845
ticks (base) vs 702 ticks (inline-slots arm)** — identical at 2900 / 2000 /
1560 tick caps, because the cap is never reached. A GC=0 wall-clock A/B
therefore measures *time to exhaust the heap* with the two arms doing
**unequal amounts of work**, and any lever that changes allocation size or
rate reads as a large fake win (or loss). The lever-1..5 GC=0 wall-clock
figures should be read as indicative only; their Ir figures are unaffected.

Use instead:

- **Wall-clock: DEFAULT GC at equal tick counts** (2900 ticks completes, exit
  0, both arms doing identical work). Interleave arms strictly, ≥3 rounds,
  and report the MEDIAN — an idle-machine assumption is not safe here, single
  rounds have shown ±8 s contention outliers.
- **Ir / callgrind: GC=0 but only at ≤600 ticks**, which is below both arms'
  OOM points, so the comparison is over identical work. This is the reliable
  per-lever attribution — prefer it to wall-clock decomposition, which at
  2-round granularity has been smaller than the noise floor.
- **Any lever touching allocation shape must also report `AVM2_HEAP_STATS=1`
  live "Allocated:" + maxRSS**, not just speed. The inline-slots lever below
  was ruled out on exactly this axis after looking fine on Ir.

## Headline — lever 6 (alloc/ctor: slot-default template + setup_locals memset, 2026-07-19)

Session prompt `SWFRecompDocs/prompts/avm2-rwk-alloc-ctor.md`, commit
`93299b884`. Target: the 11.4% alloc/ctor cluster lever 5's profile named
(`slots_init_defaults` 4.76 + `setup_locals` 4.10 + `o1heapAllocate` 2.58).
**Two of the three levers ship; the third was implemented, measured and
reverted.**

| measurement | base (`7ed9519d2`) | after (`93299b884`) | |
|---|---|---|---|
| native Ir, 600 ticks GC=0 (callgrind) | 40.081B | **38.012B** | **−5.16%** |
| — `avm2_slots_init_defaults` | 1,956M (4.88%) | **159M (0.42%)** | **−92%** |
| — `avm2_setup_locals` | 1,653M (4.12%) | 1,359M (3.58%) | −18% |
| native user-s, 2900 ticks DEFAULT GC (4 interleaved rounds, median) | 89.52 s | 90.00 s | **no measurable difference** |
| live heap @1560t (`AVM2_HEAP_STATS`) | 138 MB | 139 MB | +0.06% |
| maxRSS | 1,206,904 KB | 1,206,764 KB | unchanged |

**Read the wall-clock row honestly.** Base spanned 79.7–95.3 s and after
74.3–106.4 s across four rounds — the distributions overlap almost entirely, so
there is NO resolvable native wall-clock effect. The Ir win is real and
deterministic (callgrind counts instructions; it has no noise floor); it simply
did not convert into measurable native time. This is the lever-5 lesson harder:
−13.1% Ir bought ~1.07x there, and −5.16% is below what this machine resolves
in single-digit rounds.

**Step-0 census** (`SWF_CENSUS_ALLOC`, temp tool, not committed), plan_k TAS,
1560 ticks: **12.7M constructions / 97.4M slot inits**, categorized by what the
slot's default actually is —

| category | slot inits | share |
|---|---|---|
| type-declared default (`slot_type_default`) | 96,726,836 | **100.00%** |
| non-pointer constant | 796 | ~0% |
| pointer constant (string / namespace) | 314 | ~0% |
| function-trait closure | **0** | 0% |

The non-`td` categories total **1,250 inits over the whole run, all at boot**
(identical absolute counts at 600 and 1560 ticks). FlxList (8.15M ctors × 2
slots) + FlxQuadTree (3.76M × 21) are **93.7% of constructions**, the latter
alone 81% of slot-init work — and every one of those inits ran `avm2_mn_name`
plus a chain of up to five `memcmp`s to re-derive a constant like "int → 0".

- **Lever B — per-class slot-default template** (the win). Built lazily per
  vtable on first construction: a precomputed image of every NON-POINTER
  default, so construction becomes a `memcpy` plus a patch loop over only the
  slots needing per-object realization. **GC HAZARD RULE: the template never
  holds a STRING or OBJECT pointer** — it is plain malloc'd memory the collector
  neither traces nor sweeps, so a pointer parked there is an untraced root (see
  [[avm2-collectable-strings]]). Realization is decided on the META, never by
  computing the value, because computing a function-trait or namespace default
  ALLOCATES and must happen per object, not per class; a result-kind check
  backstops it. String constants are provably static-pool/immortal and *could*
  be templated, but at 314 boot-only inits there is no upside to weakening the
  invariant, so they stay in the patch loop and "no pointers, ever" stays
  absolute. "What does this slot default to" is factored into one
  `slot_default_for()` shared by the builder and the reference path, so
  equivalence is structural, not asserted. Skipped for `no_index`
  (newactivation/newcatch) vtables, which would build and discard a template
  per call.
- **Lever A' — `setup_locals` fill via `memset`.** The prompt and this doc both
  claimed the function "recomputes an `unchecked` flag from method-static data
  EVERY call". **Measured: `unchecked_probe_iters = 0`** — the loop is gated on
  `md->is_function`, false for every hot method, so it exits before its first
  iteration and the proposed per-method memo would have optimized away nothing.
  The real cost is the fill: 50.7M calls / 1560 ticks × ~3.9 locals = 197M
  scalar 16-byte stores, and `avm2_undefined()` is `{0,0,{0}}` — all 16 bytes
  zero — so it is byte-exactly a `memset`.
- **Lever C — inline slots — RULED OUT.** Carving the slot array out of the
  object's own o1heap block killed one alloc + one free per construction
  (`o1heapAllocate` 2.60% → 1.48%, −489M Ir) but grew the live heap **22%
  (138 → 169 MB)** and cut GC=0 arena headroom ~17%. Cause: o1heap sizes every
  allocation as `roundUpToPowerOf2(amount + O1HEAP_ALIGNMENT)` with ALIGNMENT
  32, and `sizeof(Avm2Object)` is **208** → a 256-byte fragment with only 16
  bytes of slack, so combining crosses a power of two for every class with more
  than one slot: **FlxList 320 → 512, FlxQuadTree 768 → 1024**. It only pays
  above ~57 slots, i.e. on classes with negligible construction volume — a
  bin-gated variant would retain ~none of the win. Rejected for a 1.2%-of-Ir
  gain given rwic runs at ~96% of its arena. Recorded as a comment on
  `avm2_object_alloc`, where the next person would start re-deriving it. **Do
  not retry without shrinking `Avm2Object` or changing o1heap's size classes.**

**Rig (Windows real-GPU Chrome, 5 interleaved rounds, RWK gameplay window).**
Run as a REGRESSION CHECK, not a win-proof — a ~5% Ir effect is below this
rig's resolution (known bimodal ±15-30%), and 5 rounds cannot resolve it:

| metric | base median (range) | after median (range) | paired median |
|---|---|---|---|
| all-frames mean | 102.0 (94.6–115.3) | 100.2 (96.6–109.0) | 1.057x |
| cpu p50 | 71.0 (68.9–87.4) | 71.6 (68.3–81.6) | 1.009x |
| cpu p95 | 104.0 (98.0–112.5) | 97.4 (89.4–109.8) | ~1.03x |
| frames > 250 ms (5-round total) | 48 | 48 | unchanged |

After favoured in **3/5 rounds** on mean_all and p50, 4/5 on p95; r4 and r5 went
the other way with after's whole distribution shifted up. **Within-arm spread
exceeds the between-arm difference on both headline metrics.** Verdict: **no
regression, stall count identical, and a possible small win consistent with the
Ir reduction — not resolvable at this round count.** Raw JSONs:
`/mnt/c/playwright/rw_alloc_ab/`.

**Verification:** RWK trace AND all **600 CPU-dump frames byte-identical** to
HEAD across default / `AVM2_GC=0` / `AVM2_GC_STRESS=1` — hashes `64bdde47…` and
`653ecf8e…`, i.e. **the same values this doc records for lever 5**, so this is
identity with committed HEAD rather than base-vs-after self-consistency. New
`-DAVM2_SLOTTPL_VERIFY` re-runs the reference loop against the templated image
on EVERY construction: clean over 1200 ticks default-GC and 400 ticks
GC-stress. New regression test `regression/avm2_slot_default_template` (mxmlc +
Ruffle exporter oracle) pins the declared-type defaults, the string-constant
patch path, the int-slot truncating coercion, per-object identity of realized
slots, non-aliasing of the shared image, subclass shadowing, and 50 repeat
constructions. Both CI modes + a verify-defines CI stacking `AVM2_SLOTTPL_VERIFY`
onto the existing family: zero pass→fail; regression suite 56 → **57 at 100%**.

**Post-lever-6 profile (38.01B Ir).** `slots_init_defaults` has left the top-25
entirely. blend_over 7.23% (pure pixel work, still #1, wasm runs the SIMD
spans), getproperty_static_ic 5.64 + resolved_get 5.23 (the IC-hit residue —
the recompiler endgame), setup_locals 3.58, coerce_to_class 3.40 +
coerce_to_type_mn 3.36, memcpy 2.79 (the template's own copy, plus blit),
o1heapAllocate 2.74, abstract_eq 2.63, bd_copy_pixels 2.58, mn_name 1.87.
Next levers by size: the getproperty IC-hit residue (~10.9%, recompiler work),
the remaining coerce cluster (~6.8%), GC trace pause (~15 ms, generational —
separate session), and `AVM2_GC_SWEEP_BUDGET` tuning (untried, pure config).

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
  `avm2_coerce_to_boolean()` that read it straight back.
  RWK emitted-site counts (grep the generated `RecompiledABC` — the two
  figures measure DIFFERENT things, so quote them together): **909 total
  compare sites using a `_test` inline = 489 FUSED (the `if (...) goto`
  form) + 420 non-fused** (still the inline, just boxed back into an
  Avm2Value — a compare is not fused when the branch is itself a branch
  target, or in methods with active exception bookkeeping). Plus **785
  standalone branches** on the boolean fast arm.
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

**Cross-title spot-checks (the lever is recompiler-WIDE).** Same base/after
commits, FRESH=1 rebuilds, 3 interleaved rounds each, demos deployed under
non-clobbering `*_tv_{base,after}` names:

| title | fused / total compare sites | `to_boolean_fast` | all-frames mean | p50 | stalls |
|---|---|---|---|---|---|
| RWK (5 rounds) | 489 / 909 | 785 | 83.8 → 74.7 ms (**1.12x**) | 77.9 → 72.3 (**1.16x**) | 3 → 3 |
| Seedling (3 rounds) | — / 1870 | 2439 | 26.2 → 16.5 ms (**1.54x**) | 27.4 → 15.9 (**1.76x**) | 0 → 0 |
| RWP (3 rounds) | — / 1382 | 9810 | 50.0 → 43.0 ms (**1.15x**) | 48.4 → 41.9 (**1.14x**) | 0 → 0 |

**Every round of every title favours the after side on mean and p50** (5/5,
3/3, 3/3); stall counts unchanged everywhere. Seedling is the standout — it
never got re-measured after silently gaining the lever-2/3 sites, and it has
2x RWK's compare-site density. But read its headline as "comfortably
positive, somewhere between 1.11x and 1.79x" rather than a hard 1.76x: its
AFTER side is the stable one (p50 15.6–16.0 across rounds) while its BASE
side is noisy (17.6–28.6), so the round-to-round paired ratios span
1.107–1.788. RWP lands next to RWK at ~1.15x.

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

~~Honest anchors: **Ruffle plays the same SWF's gameplay at 6.4 ms p50**
(5.3 tick + 1.0 render, measured this session — the first real Ruffle
*gameplay* number; the old 5.5 ms was menu). We are still ~26x off; 30 fps
(33 ms) needs ~5x more. This is a multi-session arc like Seedling's
280→47 ms.~~

**RETRACTED 2026-07-20 — this 6.4 ms was ALSO the menu**, exactly like the
5.5 ms it claimed to correct; the run's own screenshot shows the title screen.
Real Ruffle RWK gameplay is **82.5 ms**. See the verdict section at the top of
this file.

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
