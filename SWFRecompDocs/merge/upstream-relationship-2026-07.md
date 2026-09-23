# SWFRecomp-CC ↔ Upstream: Relationship Reassessment

**Date:** July 2, 2026
**Author:** PeerInfinity / Claude (SWFRecomp-CC)
**Audience:** This document is written to be shared — it is both SWFRecomp-CC's internal
decision record and a starting point for a conversation with LittleCube about how the
two projects should relate going forward.

**Supersedes:** [`upstream-downstream-merge-plan-2024-12.md`](upstream-downstream-merge-plan-2024-12.md)
(now historical). Ongoing upstream tracking continues in `upstream/MERGE-ANALYSIS.md`.

---

## 1. What just happened

On July 2, 2026, the objects-and-functions PRs were merged into the upstream master
branches:

- **SWFRecomp/SWFRecomp** — PR #4 squash-merged as `4e7c773` (59 commits)
- **SWFRecomp/SWFModernRuntime** — PR #3 squash-merged as `b17653d` (93 commits)

Upstream master now contains the complete new architecture: red-black-tree property
storage, string-ID interning (compile-time + dynamic), concurrent GC with cycle
detection, `app_context` threading throughout, the hybrid C + AS2 prelude-SWF standard
library (AS2Runtime + MTASC), SDL3 GPU rendering with libtess2 triangulation, input,
bitmaps, ColorTransform, and the beginnings of Sound and DefineFont2.

Every merge plan SWFRecomp-CC has written since December 2025 was structured around
"wait for this merge, then decide." The wait is over, so this document is the decision.

---

## 2. Where the two projects are today

Both projects descend from the same October 2025 codebase and share the same core
design: **recompile SWF bytecode to C, run it natively or as WASM.** Since then they
have optimized for different things, and both have succeeded at what they optimized for.

### Upstream (SWFRecomp org)

A clean, deliberate re-architecture built for the long term:

- Thread-safe by construction — all state in `SWFAppContext`, no globals
- Concurrent GC with cycle detection (Johnson's algorithm, dedicated free thread,
  per-object read-write locks)
- Red-black-tree properties + string-ID interning — property lookup does not do
  string comparison
- Standard library written in ActionScript 2 (AS2Runtime), compiled by a forked MTASC
  into a prelude SWF — class implementations live in the language they implement
- SDL3 GPU renderer, libtess2 tessellation, minimp3 audio
- Now moving toward full-game recompilation (RecompTemplate, RhythmPlanets)

### SWFRecomp-CC (this fork)

A maximal-behavioral-parity implementation, grown test-first against three emulator
test suites:

- **~75,000-line AVM1 runtime** (`SWFModernRuntime/src/actionmodern/action.c`) covering
  essentially the full AVM1 opcode set plus the built-in class library in C
- **Test results:** 704 Ruffle AVM1 tests at 96.7% filtered pass rate; Gnash and
  Shumway suites (335 + 139 tests, majority passing); 158 hand-written trace tests and
  59 graphics tests, all passing; full-suite CI on every change
- **Complete games run end-to-end:** Minesweeper, Tetris, N (Metanet), Riddle School,
  and others — playable in the browser
- **Own graphics stack:** native offscreen rendering via Dawn/WebGPU plus a
  browser-WASM WebGPU path (not SDL3), with pixel-level comparison against real Flash
  Player output as the oracle
- Full text pipeline (DefineFont2/3, device fonts, EditText including editable fields),
  audio (minimp3 + web output), input, timers, XML, and the long tail of AVM1
  semantics: `super` dispatch, `__resolve`, virtual properties (`addProperty`)
  re-entry limits, soft references, `removeMovieClip`/`onUnload` deferral,
  clip-event ordering, goto catch-up semantics, and many replicated Flash Player bugs

The architectures underneath are now very different: SWFRecomp-CC kept the original
globals-based calling convention (`action*(stack, sp)`), linear-array object
properties, raw-string property lookup, and plain refcounting — because changing those
was never on the critical path to passing the next test.

---

## 3. Why a code-level merge no longer makes sense (in either direction)

We went through the December 2025 merge plan item by item against today's code.
The conclusion: **every planned code transfer is either already independently built,
superseded, or architecturally impossible.**

### Downstream (upstream → SWFRecomp-CC)

| Planned item (Dec 2025) | Status July 2026 |
|---|---|
| **Phase 0: adopt `app_context` / stack-in-context convention** | Cost has grown ~10× since the plan was written (`action.c` went from 6.8K to 75K lines). The benefit was "easier future code merges" — and there is no longer a code-merge path to ease. Dropped. |
| **Phase 2: font/text system** | SWFRecomp-CC independently built a far larger text pipeline. Upstream's glyph rendering also targets SDL3, which we don't use. Moot. |
| `297c920` false-hole recompiler fix | Equivalent guard already present (our `swf.cpp` checks `final_outer_candidates.empty()`), and our shape pipeline has since been rewritten around a directed-edge model + libtess2. Moot. |
| Sound / audio | SWFRecomp-CC already has minimp3 audio with native and web output. Moot. |
| **Phase 3: heap reconciliation, memory fixes** | Our heap/memory stack diverged long ago and is stable under ASAN plus 1000+ CI tests per run. Moot. |

### Upstream (SWFRecomp-CC → upstream)

| Planned item (Dec 2025, revised Mar 2026) | Status July 2026 |
|---|---|
| Port our `object.h`/`object.c` | Declared dead in March 2026; now locked in — master's rbtree/string-ID/GC object system is the foundation. |
| Port our `action.c` opcode implementations | Same. 75K lines written against our object model, stack macros, and display-list internals cannot be transplanted onto a different object system, string model, and GC. Porting is a rewrite, not a merge. |
| Contribute tests and semantics knowledge | **Still fully viable — this is where the real value is.** See §5. |

### The one upstream idea we may adopt — as an idea, not code

**String-ID interning + rbtree properties.** Our native profiling initially found ~67%
of instruction count in property-name lookup; hash-gating/indexing work landed in June
2026 cut that roughly in half, and the residual name-handling complex (~40% on N's
headless profile) is what full interning would eliminate. Upstream master is now a
working reference implementation of the interning design. If/when we do this work we
would implement it inside our own architecture rather than port code — but it is a
genuine case of upstream having already solved a problem we will eventually face.
(Full staged plan: `SWFRecompDocs/plans/string-id-interning-plan.md`, July 2026. The
survey behind it also found two gaps in upstream's implementation worth flagging back:
no SWF<7 case-insensitive lookup, and id-ordered rbtree iteration vs AVM1's
insertion-ordered for-in — see the warnings doc.)

(Worth noting the reverse also happened: both projects independently chose libtess2 to
replace their original tessellation — upstream at runtime, we at recompile time. When
two forks converge on the same third-party solution from different directions, that's
good evidence for the choice.)

---

## 4. Proposed relationship: permanent friendly fork with knowledge exchange

We propose treating the two projects as **complementary implementations of the same
idea, exchanging knowledge rather than code**:

- **Upstream** is the architecture project: clean foundations, thread safety, GC,
  the AS2-prelude standard library. It will get to behavioral completeness on its own
  timeline, on much better bones.
- **SWFRecomp-CC** is the semantics project: it has already paid the cost of
  discovering what AVM1 *actually does* — the undocumented edge cases, the Flash Player
  bugs that content depends on, the execution-ordering rules — and has the test
  infrastructure to prove conformance.

The exchange, concretely:

**From SWFRecomp-CC to upstream** (see §5): tests, documented AVM1 semantics,
edge-case warnings, and targeted bug reports/PRs written against upstream's own
architecture.

**From upstream to SWFRecomp-CC:** design reference (string interning, GC, arena
ideas), plus continued tracking. We keep local clones of the upstream repos under
`upstream/` and periodically update `upstream/MERGE-ANALYSIS.md` with what's changed —
this has been cheap and useful, and continues unchanged.

What we are explicitly **not** planning: re-architecting SWFRecomp-CC onto upstream's
foundations, or asking upstream to absorb our runtime. Nine months of parity work sits
on our current architecture; rebuilding it would regress a 96.7% pass rate for a very
long time in exchange for cleanliness we can get incrementally where it matters.

---

## 5. What SWFRecomp-CC can offer upstream, concretely

These are on the table now, in roughly ascending order of effort:

### 5.1 Investigation docs (free — already written)

Hundreds of hard-won AVM1 findings, documented with test names, diffs, and decisions:

- `ACCEPTED_DIFFS.md` — cases where expected output is platform UB, internally
  inconsistent, or unreplicable Flash quirks (i.e., *don't burn time chasing these*)
- `RUFFLE_VS_FLASH_DIFFERENCES.md` — where Ruffle's expected output reflects Ruffle's
  own behavior rather than Flash's
- `FLASH_BUGS_REPLICATED.md` — real Flash Player bugs that content (and Ruffle) depend
  on, which a correct-seeming implementation will get "wrong"
- `RUFFLE_COMPAT_TWEAKS.md` — underspecified behaviors and the pragmatic choices that
  match real-world expectations

### 5.2 Edge-case early warnings (cheap — a conversation)

Upstream's recent commits show it entering territory we have detailed maps of.
Examples of traps we already hit and solved:

- **`super`** (the `super-var` branch is fighting this now): dispatch is depth-based
  along the prototype chain, not simple parent-call; argument-push order for simple
  (type-1) functions called via `super()` differs from the intuitive implementation;
  SWF5 vs SWF6+ closure capture differs.
- **`removeMovieClip`**: removal is *deferred* (clip survives at a shifted depth) when
  the clip or any descendant has `onUnload`; user variables on a removed clip's name
  must survive removal.
- **Virtual properties (`addProperty`)**: SWF7+ enforces a re-entry budget of 65
  getter+setter invocations *combined per entry*, not a simple recursion limit.
- **Timeline/goto semantics**: `gotoAndStop` catch-up executes skipped frames with
  suppressed `stop()`s; clips placed during catch-up must not advance on their
  placement tick; a stopped clip's reported `_currentframe` must be synced on manual
  navigation. Getting execution order right here is where most full-game bugs live.
- **Determinism for testing**: seeding `Math.random` and `Date.getTime` per-test
  (matching Ruffle's `--deterministic` mode) makes full-suite runs byte-identical —
  invaluable once test counts grow.

### 5.3 Tests (moderate effort — high value)

- Our 158 hand-written trace tests + 59 graphics tests are architecture-independent
  (SWF in, expected output out) and could be contributed directly or cherry-picked.
- The bigger offer: the **Ruffle-test harness approach**. Running Ruffle's 700+ AVM1
  trace tests (plus the Gnash and Shumway suites) against a recompiler, with per-test
  expected output, an ignore list for known-unfixable diffs, and CI that reports
  pass→fail regressions by name, is the single thing that most accelerated
  SWFRecomp-CC's correctness. We're happy to help set up the same for upstream when
  its opcode coverage makes it worthwhile.

### 5.4 Targeted PRs against upstream's architecture (ongoing, opportunistic)

Where our test knowledge identifies a concrete behavioral bug in upstream's
implementation, small fixes written in upstream's own idiom (rbtree, string IDs,
app_context) — semantics ported by rewriting, never by copying incompatible code.

---

## 6. Open questions for LittleCube — ANSWERED (July 2026)

LittleCube replied shortly after this document was shared. Answers recorded inline:

1. **Does the friendly-fork framing match your view?**
   > *"yeah that's fine, whatever you guys think will be most productive"*
   — **Confirmed.** The friendly-fork + knowledge-exchange model in §4 is now the
   working arrangement.
2. **What's most useful to you first** — the investigation docs (§5.1), the edge-case
   maps (§5.2), tests (§5.3)?
   > *"whatever information you have about flash features that games will expect to
   > behave in a particular way, that are not obvious to implement/normally undefined
   > behavior"*
   — That is the §5.2 edge-case category. **Deliverable:**
   [`../upstream-comparison/warnings-for-upstream.md`](../upstream-comparison/warnings-for-upstream.md)
   (the trap map: super, removeMovieClip lifecycle, addProperty re-entry budget,
   goto catch-up ordering, Flash-bugs-on-purpose, etc.), backed by the four
   classification docs in `ruffle-tests/tests/swfs/avm1/_investigation/`. It grows
   as upstream tracking shows new territory being entered.
3. **Test infrastructure**: *"it's not urgent, up to you"* — deferred; revisit when
   upstream opcode coverage makes suite runs meaningful.
4. **Reporting channel**: *"probably issues, and then discussion follows in discord"*
   (GitHub issues tracked by a Discord bot). — **Policy:** behavioral findings about
   upstream get filed as GitHub issues on the relevant SWFRecomp org repo;
   follow-up discussion happens on Discord.
5. **RhythmPlanets** (game-debugging notes offer): no specific response; standing
   offer remains open.

---

## Appendix: divergence facts (July 2, 2026)

| | Upstream master | SWFRecomp-CC |
|---|---|---|
| Runtime `action.c` | ~1.5K lines core + runtime_api modules | ~75K lines |
| Object properties | Red-black tree, string-ID keys | Linear array, raw-string keys |
| Memory | Concurrent GC, cycle detection, per-object locks | Refcounting, arena/heap, ASAN-validated |
| State | All in `SWFAppContext` (thread-safe) | Globals + context mix |
| Std library | AS2 prelude SWF (AS2Runtime + MTASC fork) | All in C |
| Renderer | SDL3 GPU | Dawn/WebGPU offscreen + browser-WASM WebGPU |
| Tessellation | libtess2 (runtime) | libtess2 (recompile-time) |
| Tests | 56 test dirs | 704 Ruffle AVM1 (96.7% filtered) + Gnash/Shumway suites + 217 hand-written |
| Fork point | — | SWFRecomp `bc761f4` (Oct 10, 2025), SWFModernRuntime `267553d` (Oct 7, 2025) |

Upstream tracking history and per-update commit logs: `upstream/MERGE-ANALYSIS.md`
(local-only, gitignored). Historical merge planning: this directory.

---

## 7. Status check — September 22, 2026

Eleven weeks in. What the arrangement produced, what it didn't, and what changed
on each side. (Tracking detail: `upstream/MERGE-ANALYSIS.md` §"September 22, 2026".)

### 7.1 Delivery record

| Item | Sent | Response |
|---|---|---|
| This document | Jul 2, Discord | Jul 4: friendly fork confirmed; answers recorded in §6 |
| `upstream-comparison/README.md` + the four analyses | Jul 4, Discord | — |
| [`warnings-for-upstream.md`](../upstream-comparison/warnings-for-upstream.md) (the §5.2 deliverable) | Jul 4, Discord, with the pointer that §4 (timeline/goto) is the RhythmPlanets-relevant part | Jul 4: *"awesome, tyvm"* |
| [`plans/avm2-support-plan.md`](../plans/avm2-support-plan.md) §4 architecture sketch, with a specific ask for a reaction on the value/vtable layout (§4.2) before our Stage 2 locked it in | Jul 10, Discord | Jul 10: *"very cool, i'll read the doc later on and respond"*; Jul 12: *"no pressure either way, i'm caught up in some other stuff atm"*. **No reaction received**; Stage 2 locked in on Jul 11 (AVM2 went from nothing to over half the avm2 corpus in a day). |

Not yet used: the **GitHub-issues channel** agreed in §6.4. Zero issues have been
filed on the org repos since July — not because nothing was found, but because
upstream did not enter any new AVM1 territory (see 7.2), so there was nothing
behavioral to report against *their* code. Two small candidates now exist (a
`trace()` string leak upstream acknowledges in its own commit message, and a
string-literal escaper that misses cases real SWFs contain); they are logged in
the tracking file to be filed.

### 7.2 Upstream since July

**Master has not moved in any SWFRecomp org repo since the July 3 squash merges.**
All new work is on a `mavlink` branch (runtime 15 commits, recompiler 3,
AS2Runtime 2; Aug 18 → Sep 8): SWFRecomp as a **simulation front-end for ArduPilot
SITL over MAVLink** — UDP/TCP sockets (Linux + Windows), vendored MAVLink headers,
yyjson, and `recompSITL*` natives exposed to AS2 through the prelude. Engine-level
deltas are minor: the `Duplicate` opcode implemented, scope objects reused instead
of re-allocated per call, the free thread now sleeps when idle, a renderer
multisample fix. The abandoned `super-var` branch that the warnings doc's §1
originally addressed is dead; `super` shipped in master via PR #3.

Reading: upstream's near-term direction is **not** games or AVM1 breadth. That
lowers the immediate value of the AVM1 trap map to them and raises the value of
the things that *do* overlap — deterministic testing, the socket/serialization
semantics (our net/socket arc, AMF0, `LocalConnection`, `XMLSocket`) and the
platform-abstraction lessons from the WASM build. Nothing about the friendly-fork
verdict changes.

### 7.3 SWFRecomp-CC since July

The §2 description of this fork — "the AVM1 semantics project" — is now too
narrow. Since July 2:

- **AVM2 (ActionScript 3) runtime** built from scratch under
  `SWFModernRuntime/src/avm2/` (a separate module tree, not a second `action.c`),
  from the July 10 plan: Ruffle's verifier/optimizer design as the AOT front-end,
  interned multinames, slot/vtable lowering. Playable AVM2 games include Seedling,
  Robot Wants Kitty and sequels, Elephant Quest, Snailiad, and a 235-title Flixel
  survey.
- **Full upstream corpus mirrored** (2026-07-24): 14 categories, no AVM filter,
  including the 1,574 Tamarin acceptance tests (`from_avmplus`).
- **Pass rates, CI of Sep 22, 2026 (graphics mode, effective = pass + ruffle_matched):**

  | Suite | Effective |
  |---|---|
  | avm1 | 721 / 736 |
  | avm2 | 1255 / 1278 |
  | from_avmplus | 1570 / 1574 |
  | from_gnash (5 sub-suites) | 375 / 403 |
  | from_shumway (incl. avm1) | 225 / 229 |
  | nine small categories | 210 / 217 |
  | **Upstream corpus total** | **4356 / 4437 (98.2%)** |
  | our own `regression` suite | 96 / 96 |

- **Function-dispatch consolidation completed** (2026-07-17): every call path
  runs through one `invokeFunctionValue()` core; the legacy dispatchers are
  deleted. Upstream advantage #6 in the comparison doc is neutralized.
- **In-browser recompiler** (`docs/recompiler/`, the recompiler itself compiled
  to WASM; live since February) gained AVM2 support, and the demo gallery on
  GitHub Pages now includes AVM2 titles.
- **Net/socket arc**: AMF0/AMF3, `NetConnection.call`, `SharedObject`,
  `LocalConnection` as a real wire channel, `XMLSocket`/`Socket` replay.

Runtime `action.c` is ~79.8K lines (was ~75K); the AVM2 tree is another ~93K across 36 files.

### 7.4 What the July offers (§5) look like now

- **§5.1 investigation docs / §5.2 warnings** — delivered and acknowledged. The
  warnings doc was refreshed in September with the post-July AVM1 findings and a
  new AVM2 section (kept short; upstream has no AVM2 yet).
- **§5.3 tests** — still deferred at LittleCube's request; nothing has changed
  that would make suite runs meaningful for upstream yet (no `Enumerate`, no
  text pipeline).
- **§5.4 targeted PRs** — none warranted; see 7.1 for the two issue candidates.
- **§3 "the one upstream idea we may adopt" (string-ID interning)** — still
  planned, not started (`plans/string-id-interning-plan.md`). The June 2026
  mitigations plus the GPU-bound profiles of the games we run kept it below the
  line. AVM2 was built with interned multinames from day one, so the idea *was*
  adopted — on the new VM, not retrofitted onto AVM1.

### 7.5 Repository map (corrected)

The READMEs in this repo still described a pre-July world (a "fork that
regularly syncs with upstream", live-demo links into the org's frozen docs site,
PR-vehicle forks presented as live). Corrected September 22, 2026:

| Repository | Role today |
|---|---|
| `PeerInfinity/SWFRecomp-CC` (this repo) | The living fork. All work happens here, on `master`. |
| `SWFRecomp/SWFRecomp`, `SWFRecomp/SWFModernRuntime` | Upstream; tracked read-only in `upstream/` (gitignored clones), never merged. |
| `SWFRecomp/AS2Runtime`, `SWFRecomp/mtasc` | Upstream's AS2 prelude stdlib and the MTASC fork that compiles it. Tracked for design reference only; we use stock MTASC at `~/CC/mtasc` for test authoring. |
| `SWFRecomp/RecompTemplate`, `SWFRecomp/RhythmPlanets*` | Upstream's game-recompilation template and first game target (idle since May/June). |
| `SWFRecomp/libtess2` | Upstream's tessellator fork. We vendor libtess2 independently (recompile-time). |
| `PeerInfinity/SWFRecomp`, `PeerInfinity/SWFModernRuntime` | **Historical.** The forks that carried the `wasm-support` branches (2025) and then hosted LittleCube's `feature/objects-and-functions` PR branches. Last push Jul 3, 2026. Their commit history is the only unsquashed record of PRs #3/#4. Not used for anything current. |
| `SWFRecomp/SWFRecompDocs` | **Frozen** (Nov 5, 2025). The docs were flattened into this repo's `SWFRecompDocs/` on Nov 5, 2025 and have been maintained there since. |
