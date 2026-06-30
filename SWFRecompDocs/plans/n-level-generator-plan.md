# N level generator — plan

Date: 2026-06-30. Goal: a JavaScript generator that emits **solvable** levels for
the recompiled Flash game **N** (Metanet, momentum side-platformer), feeding them
into the working N substrate (`ruffle-tests/tests/swfs/_swfbridge/livetest/n_loader/`,
status doc `2026-06-30-n-substrate-investigation.md`). Levels are 31×23 tile grids
with a switch→door goal and optional gold; the host configures a level over
`__swfBridge` and is notified on completion.

Language: **JavaScript** (per user; also matches all prior art below).

---

## 1. Prior art (surveyed 2026-06-30)

### Archipelago-CC has a mature, all-JS, substrate-agnostic procgen framework
`~/CC/Archipelago-CC/frontend/modules/` — NOT DJ-specific. Structure:
- **Shared core (reusable, game-agnostic):** `shared/procgen/substrateRegistry.js`
  (the registry/dispatch + entry interface), `forwardSimulator.js` (deterministic
  rules.json reachability walk + sphere logging), `pathsAndObstaclesCompiler.js`
  (access-rules + obstacle-paths → Rule Builder JSON), `spatialPrimitives.js` /
  `adapterPrimitives.js` (tile-grid geometry). Driver:
  `frontend/procgenPipeline/procgenPipelineEngine.js`.
- **Bounce Demo substrate (N's closest sibling):** `frontend/modules/bounceDemo/`
  — `generator.js` (~2000 lines, generate-and-test), `physics.js`/`gameCore.js`
  (the `step()` engine), `canJump.js` (conservative forward-query reachability
  sampler), `deriveRules.js`/`verifyObstacles.js` (ability→access verifier),
  `bounceDemoLibrary.js` + `bounceProcgenParams.js` (registry entry + hooks),
  `level.js` (level schema). Plus a JS-canvas renderer (`game/main.js`) and a
  real-DJ-SWF renderer (`djReal/`, the SWFRecomp/Ruffle path — the analog of our
  n_loader).
- **The pattern Bounce uses** = exactly the one I sketched: *generate-and-test
  with solvability-by-construction*. `generateLevel` PROPOSES geometry for a
  target requirement and the SAME `deriveRules` verifier the pipeline uses must
  confirm every pickup + the exit derives the intended minimal item-sets, no
  defects; failed proposals retry with a perturbed seed. Gate geometry is derived
  from physics (e.g. "spring gap 380–440px: plain apex 169 fails, spring 484
  clears"). canJump.js is a *conservative* sampler (under-claims reachability).

### SWFRecomp-CC side (already ours)
- The N substrate works on both runtimes (load level + detect completion,
  byte-identical Ruffle vs SWFRecomp; `__swfBridge` EI contract verified). This
  gives us a **real-N oracle** (Ruffle, ~15s, batchable) + the decoded
  level/object/tile/demo formats (status doc).
- Reusable JS encoders: `n_loader/n_host_mock.js::buildWalkLevel()` (the only N
  level builder so far) and DJ's `dj_loader/dj_swf_bridge.js::encodeLevel()`
  (pattern for compact encoding + coordinate mapping).

### Integration shape (from `swfrecomp-substrate-converged.md`)
A recompiled-SWF game plugs in as a substrate via `__swfBridge` =
`{ configure(payload), pollItems(items), sendLocation(flashName) }`, sharing one
`flashSubstratePanel` + `flash:loadRegion` event (routed by `gameId` in the
payload). **Mode 1** = opaque fixed-content minigame (registry entry, NO
build-time hooks) — our current N substrate is essentially this. **Mode 2** =
procgen-rendered content — the entry gains `generateRegionCore`, `placeFromItems`,
`extractPathsAndObstacles`, `serializeWorld`/`deserializeWorld`, and the sidecar
carries procedural tile data. **The level generator IS Mode 2.**

---

## 2. The key insight: N has a dual oracle

Bounce verifies generated levels against its OWN JS `physics.js` (because the JS
canvas renderer is one of its runtimes, calibrated to real DJ). N has something
better: a fast, exact **real-N oracle** (Ruffle headless, already wired through
`__swfBridge` + the demo-replay path). So N's generate-and-test can use:
- a **coarse JS movement model** for *generation* (lay geometry within reachable
  envelopes) and fast pre-filtering, and
- **real N via Ruffle** as the *authoritative acceptance gate* (play the level
  with its candidate demo; accept only on `N_COMPLETE`).

This means the JS model need NOT faithfully reimplement N's swept-circle/tile
collision — it only needs to be **conservative** (under-claim what's reachable) so
accepted levels almost always pass real N; Ruffle rejections calibrate it. Same
principle as canJump.js, but with the real game as final judge.

---

## 3. The hard problem (why this isn't just "emit a string")

N is a momentum platformer (`GRAV=0.15`, ground `maxspeed=5`, air accel `0.1`,
variable-height jump `jumpGrav=0.025` while held up to `max_jump_time=30`,
`terminal_vel=r*0.9`, wall-slide/wall-jump, `BOUNCE/FRICTION` constants — all
decoded). A random tile scatter is essentially never completable. So the generator
must (a) lay geometry the ninja can physically traverse spawn→switch→door, and
(b) produce a **solving demo** (N's bit-packed input replay) to *prove* it
headlessly. The reliable way to get both at once is **construction-by-simulation**:
drive a ghost along an input plan through the coarse model, stamp tiles under its
path, place switch+door on the path; the input plan IS the demo.

We do NOT reimplement N's full collision. Instead derive **motion envelopes** from
the known constants (max run distance/tick, jump apex height, max gap width
clearable mid-jump, wall-jump reach) and build geometry within them — exactly how
Bounce derived its gap sizes. Ruffle confirms.

---

## 4. Architecture decision (needs user sign-off — see §8)

**Recommended: build the N procgen *core* as a portable, self-contained JS module
in SWFRecomp-CC, verified against the real-N Ruffle oracle, structured to drop into
Archipelago-CC's substrate registry later (a mechanical wrapper).**

Rationale:
- The hard, novel work (N physics envelopes, momentum reachability, tile-geometry
  construction, level encoder, demo synthesis) is **repo-independent** and best
  iterated against the real-N oracle that already lives in `n_loader/`.
- Avoids premature coupling to framework internals that are **actively being
  refactored** (`substrate-agnostic-engine-refactor.md` in flight) — integrating
  now means churning against a moving target.
- Keeps commits in the user's authorized repo (SWFRecomp-CC) during the hard part.
- The registry wrapper (`generateRegionCore`/`placeFromItems`/`extract…`/
  `serialize…`) is thin and added once the core is proven (Phase 4).

Alternatives (decision is the user's):
- **A — framework-native now:** build N directly as a Mode-2 substrate in
  Archipelago-CC, copying Bounce's module. Pro: full AP pipeline/panel/playback
  immediately, single home. Con: cross-repo, must adopt the whole framework + its
  test infra up front, moving-target refactor.
- **B — standalone forever:** never integrate; N generator stays a SWFRecomp-CC
  tool. Pro: simplest. Con: no AP randomizer logic (spheres, item placement) — N
  becomes a level toy, not an Archipelago substrate.
- Recommended **hybrid** = A's destination via B's fast iteration path.

Bridge convergence: our MVP uses `__swfConfig`/`__swfSendExit`; the framework uses
`configure`/`pollItems`/`sendLocation`. Align N's bridge to the framework names as
part of Phase 4 (keep the simple names working as aliases meanwhile).

---

## 5. Module breakdown (the portable N procgen core, all JS)

Proposed home: `ruffle-tests/tests/swfs/_swfbridge/livetest/n_loader/gen/` (or a
sibling `n_gen/`), ES modules, no framework deps in P0–P3.

1. **`nLevel.js` — model + encoder/decoder.** A `Level` = 31×23 tile grid (enum:
   empty/full/the 32 slope-family states) + typed objects (`player`, `exit{door,
   switch}`, `gold[]`, enemies…). `encode(level) → "mapStr|objStr"` (column-major
   X-outer/Y-inner, `char=state+48`, objects `type^p,p…` joined `!`); `decode(str)
   → Level`; cell↔pixel helpers (`cell(mx,my)→(mx*24+36, my*24+36)`). Generalizes
   `buildWalkLevel()`.
2. **`nMotion.js` — physics envelopes + ghost step.** Constants from the status
   doc; derived envelopes: run-distance/tick, jump apex height, max clearable gap
   (run+jump), wall-jump reach. A coarse `step(state, input)` (point/AABB on the
   tile grid using envelopes, NOT N's true collision) for the ghost. Conservative.
3. **`nReach.js` — reachability oracle.** Forward-sampling à la canJump.js over
   `nMotion.step`: from spawn, which tiles/objects are reachable under base
   movement. For v1 a single-sphere "is switch reachable, then door reachable from
   switch, is each gold reachable". (Multi-sphere item logic only when locked
   doors are introduced — Phase 5.)
4. **`nGenerate.js` — construction-by-simulation.** Drive a ghost along an input
   plan through `nMotion`; stamp floor/walls under its path; place switch+door on
   the path (switch before door), scatter gold near it. Difficulty knobs:
   segment count, gap sizes, jump frequency, enemy density, gold count, seeded RNG
   (seed drives generation only — no runtime RNG, matching the framework). Emits
   `{ level, demo, meta }` where the input plan IS the demo (bit-packed).
5. **`nDemo.js` — demo (de)serialization.** Encode an input-plan array to N's
   format (`"<tickCount>:<e0>|<e1>…"`, 4 bits/tick L/R/J/JTRIG, 7/entry). Already
   prototyped (the `35791394` "hold right" constant).
6. **`nVerify.js` — Ruffle acceptance gate.** Batch-play candidate `{level, demo}`
   through real N via `__swfBridge` on Ruffle, grep `N_COMPLETE`. Extend the host
   mock + loader to a **queue**: configure level 1, await `__swfSendExit`,
   configure level 2… in one page (turns ~15s/level into ~1–2s amortized). Accept
   only verified levels; rejections feed back to widen `nMotion` margins.
7. **`nApMap.js` (Phase 4+) — AP mapping.** gold → AP *locations* (`sendLocation`),
   exit door → region *goal/exit* (`sendExit`). Optional item-gating via N's
   **lockable doors** (TESTDOOR type 9 has `isLocked`/`doorI`/`doorJ`; editor also
   lists LOCKDOOR) — an AP "key" opens a door, giving N genuine multi-sphere logic.

---

## 6. Mapping to the framework hooks (Phase 4, mechanical)

When wrapping the core as an Archipelago-CC Mode-2 substrate (template: copy
`bounceDemoLibrary.js`):
- `generateRegionCore(input)` → `nGenerate` (one 31×23 region per call).
- `placeFromItems`/`placeFromRules` → place gold/switch/door (+ locked doors for
  rule-gating) per AP requirement.
- `extractPathsAndObstacles` → `nReach` results as access rules + obstacle paths
  into `pathsAndObstaclesCompiler`.
- `serializeWorld`/`deserializeWorld` → tile grid + objects + AP location map
  to/from the sidecar; the sidecar's level string flows to the SWF via
  `configure`.
- Reuse `forwardSimulator`/`pathsAndObstaclesCompiler`/`spatialPrimitives` as-is.

---

## 7. Phasing (each phase verified before the next)

- **P0 — encoder + golden round-trip. ✅ DONE (2026-06-30).** `gen/nLevel.js`
  (Level model + encode/decode + cell↔pixel) + `gen/extract_builtin_levels.mjs`
  → `gen/builtin_levels.json` (all 150 built-in levels; **gitignored — N is not
  open source**, regenerate locally). `gen/golden_roundtrip.test.mjs`:
  encode(decode(s)) byte-identical for all 150.
- **P1 — flat/trivial generator end-to-end. ✅ DONE (2026-06-30).** First proved
  the **batch-verify queue** on Ruffle: SWF re-loads a fresh level after each
  completion in one page session (NLoader.as re-arm; `n_swf_bridge.js`
  `configureQueue`; `__N_DONE__` sentinel). Then `gen/nGenerate.js` (seeded flat
  walk-right levels: floor + spawn→switch→door + gold + hold-right demo) +
  `gen/nVerify.js` (the authoritative gate). `node gen/nVerify.js 6 1` → **6/6
  complete on real N**. NLoader `finishLevel()` advances the queue on
  `N_COMPLETE`/`N_FAIL` (per-level `LEVEL_MAX` budget) so a bad level never
  stalls a batch (verified good→timeout→good).
- **P2 — jumps & gaps.** `nMotion` envelopes + `nReach`; generate levels with
  height changes and reachable gaps; construction emits the jump demo; Ruffle
  gates. This is where the coarse model + real-N verifier earn their keep.
- **P3 — hazards & variety.** Enemies (drone/mine/turret/thwomp/floorguard),
  bounce blocks, launch pads, one-way platforms — placed off the critical path or
  as survivable obstacles; verify the demo still completes.
- **P4 — framework integration.** Wrap the core in the Archipelago-CC registry
  (Mode 2); converge the bridge to `configure`/`pollItems`/`sendLocation`.
- **P5 — AP item-gating (locked doors).** Multi-sphere logic via N's lockable
  doors + key items; full randomizer semantics.

---

## 8. Open decisions for the user

1. **Home / integration depth** (§4): hybrid (recommended), framework-native now
   (A), or standalone (B)?
2. **Verification stance:** real-N-Ruffle-as-oracle (recommended) vs. invest early
   in a high-fidelity JS N-physics model (closer to Bounce's approach, more work).
3. **AP logic ambition for v1:** simple (gold=locations, exit=goal, base movement,
   single sphere) vs. introduce locked-door key-gating (multi-sphere) sooner.
4. **Bridge naming:** keep `__swfConfig`/`__swfSendExit` for now and alias to the
   framework's `configure`/`sendLocation` at P4, or converge immediately?

## 9. Risks
- **Motion-envelope fidelity** (P2+): mitigated by construction (lay tiles where
  the ghost is) + conservative margins + Ruffle as ground truth; widen on reject.
- **Variable-height jump & wall-jump** are the trickiest envelopes; defer to P2/P3
  and lean on verification.
- **Framework churn** (`substrate-agnostic-engine-refactor`): mitigated by keeping
  the core portable until P4.
- **Batch-verify throughput:** the queue design keeps Ruffle practical; if needed,
  a calibrated JS model pre-filters before the Ruffle gate.

## 10. Testing
- P0 golden round-trip against every built-in N level (format proof).
- Unit tests for `nMotion` envelopes vs. hand-checked jump arcs.
- Per-level Ruffle acceptance (the authoritative gate) + a small committed corpus
  of generated levels with their verified demos as regression fixtures.
