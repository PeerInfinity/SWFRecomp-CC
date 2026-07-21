# AVM2 corpus expansion — Elephant Quest bring-up plan

**Status: INVESTIGATION / GAP-MAP (2026-07-21).** First corpus title beyond the
five hand-picked games, and the first target **Ruffle cannot play** — and we now
know *why*: with AGI.swf served, Ruffle runs boot → menu → story → "loading world
map" → `init2()` builds the level, then its **15 s AVM2 script watchdog
terminates the ~18 s synchronous world-map build** and the game freezes (§2). It
is a **Ruffle performance cliff, not a missing feature** — every hypothesized
`init2()` API gap executes fine in Ruffle. That makes EQ a strong beat-Ruffle
target (our AOT runtime has no interpreter watchdog; §3). This session is
diagnosis only: it does **not** get the game running — our recompile is blocked
at gap #1 (a one-body obfuscator decoy) and the native build is OOM-risky (§5).
Next-session recommendation in §6.

Target: `~/CC/newgrounds/566862_ElephantQuest_Public2_secu.swf`
(jmtb02 / Jimp, ArmorGames, 2011). Decompile at
`~/CC/jpexs/output/elephantquest/scripts/` (221 `.as`, readable class names).

---

## 1. Recon (confirmed this session)

- 3.7 MB CWS, **SWF v10**, 800×500 @ 30 fps, **3 root frames**, single DoABC
  (262 KB). `--check-abc`: **1 abc tag, 1310 method bodies, verify_fails = 1**
  (that one fail = gap #1 below). Decompressed length 4.3 MB.
- **All content embedded** (495 DefineSprites, 30 sounds, JPEG3 + Lossless2,
  DefineFont). No ImportAssets, no DefineBinaryData. So "fails to load content"
  is **not** missing level files — the 47 levels are embedded classes.
- **Custom jmtb02 engine — NOT Flixel, NOT FlashPunk.** Package layout:
  - `john/*` — engine helpers: `Anim`, `Key`, `Math2`, `SoundBox`, `Text2`,
    `TileObject`, `HandyCam` (camera), `Emit`, `Activator`, `Logger`, `AS2`
    (a `navigateToURL`/getURL shim).
  - `betz/*` — `Base64` + `Compressor` (save-blob codec) **and the control-flow
    obfuscator** (the `§§push(x); if(37 == 34){return;}` junk that wraps every
    method, plus a decoy opcode — see gap #1).
  - default package — game classes: `Shell` (state machine), `Game` (43 KB main
    controller), `MainMenu`, `Intro`, `Story`, `MapMenu`/`MapPlace`/`MiniMap`
    (world map), `Level0..Level46` (47 embedded level classes), `Vault` (54 KB —
    save/data), `Elephant`, `Enemy`/`Wooly`/`Bear`/… (entities), `UpgradeTree`,
    `GunSystem`, `AGIStuff`/`AGIcon` (ArmorGames API), `LoadingThing`.
  - `SWFStats/*` — swfstats.com telemetry; `com/adobe/serialization/json` — JSON.
- The collision/arrayToCSV/quadtree intrinsics from the Flixel corpus **do not
  transfer** (different engine). Perf is unknown and out of scope this session.

---

## 2. Ruffle-failure diagnosis — it is an ENGINE gap, not a network wait

The prompt hypothesis was that "fails to load world map content" might be an
environmental network expectation (stub AGI.swf/trackers → oracle restored). The
decompile **rules that out**. The New-Game → world-map path is fully synchronous
and embedded:

1. `MainTimeline.frame3` → `new Shell(); shell.init()`. `Shell.init()` →
   `Vault.init()` + `agi.init()` (fire-and-forget AGI.swf load) + `startIntro()`.
2. Intro → `loadMenuFromIntro` → `startMenu()` (title = `MainMenu`).
3. **New Game** → `MainMenu` → `Shell.startStoryFromMenu()` → (no save) →
   `startStory()` (Story cutscene) → `startGame()` → `new Game(); game.init()`.
4. `Game.init()` (`Game.as:227`) adds the embedded **`LoadingThing`** MovieClip
   (the "loading world map" screen, `[Embed]` symbol1079) and registers
   `loadPing` on ENTER_FRAME. On the **next frame** `loadPing` removes itself and
   calls **`init2()`**, which **synchronously** builds the level: `uiPanel`,
   `elephant`, the level via **`getDefinitionByName("Level"+n) as Class`**
   (`Game.as:720`), crosshair, camera — then removes `LoadingThing`.

**Nothing in that path awaits an external load.** Evidence:
- `AGIStuff` (`AGIStuff.as:189`) loads `http://cache.armorgames.com/assets/agi/
  AGI.swf` with a **COMPLETE-only** listener (no IOError path). `this.agi` is
  assigned only in `loadComplete` (`AGIStuff.as:278`), *after* AGI.swf finishes.
  **CORRECTION (Ruffle repro):** most `agi` uses are guarded `if(this.agi)`, but
  **`hideAGILogin()` is NOT** (`AGIStuff.as:62-70` → `this.agi.hideLoginStatus()`
  unguarded) — and it is the **first statement the New Game button runs**
  (`MainMenu.clicky`, `playB` case → `this.shell.agi.hideAGILogin()`). So the New
  Game path **hard-depends on `agi` being a defined object** (i.e. on AGI.swf
  having loaded). `loggedIn` defaults `true`; the real save is `Vault`/
  SharedObject, not AGI.
- The `_secu` **sitelock is inert**: `MainTimeline.frame1` parses
  `stage.loaderInfo.url` only to `trace("DOMAIN = …")` and put "Playing at
  &lt;domain&gt;" in the right-click menu (`MainTimeline.as:123-132`). No
  whitelist, no `navigateToURL` redirect, no stop. Matches the sibling-games
  empty-stub finding — `-DSWF_URL` just needs a parseable URL.
- `SWFStats.Log`/`LogRequest` fire a `tracker.swfstats.com` beacon
  (fire-and-forget URLLoader) that gates nothing.

**There are TWO distinct failures, and the Ruffle repro found the first one
masks the second:**

- **Failure 1 (proximate, environmental) — reproduced.** Under the exporter's
  **`NullNavigatorBackend`** (no `.with_navigator`, `exporter/src/exporter.rs`),
  AGI.swf never loads, so `agi` is `undefined`, and the **first line of the New
  Game handler** throws at the click (export frame ~429):
  ```
  ERROR ruffle_core::avm2: Error dispatching event "click":
  TypeError: Error #1010: A term is undefined and has no properties.
  (accessing field: hideLoginStatus)
  ```
  The handler unwinds **before** `fadeToBlack.play()`/`extras.play()` start the
  Story→`init2()`, so **the loading-world-map screen never even appears** — the
  menu just stays. This is environmental (missing AGI.swf), **stubbable**, and
  the *only* ERROR in the run.
- **Failure 2 (the user's actual report) — REPRODUCED: a Ruffle AVM2
  performance/watchdog failure, NOT a feature gap and NOT network.** Re-run with
  the real AGI.swf served locally (see repro below) so `agi` is defined: Ruffle
  clears Failure 1 and runs the **whole** chain — menu → story cutscene
  ("Click to Continue") → fade-to-black "loading world map" → **`init2()` builds
  the level** (traces `DOOR 0`…`DOOR 999`, `key3`) → the world map **renders**
  ("Area 5", "400/400 HP", "25,293 XP", "Level 1", HUD). **All the hypothesized
  `init2()` API gaps WORK in Ruffle** — `getDefinitionByName("Level"+n)`,
  filters, and the `betz`/adobe-JSON save deserialization all execute fine. Then
  Ruffle **freezes**: the synchronous world-map construction takes ~18 s of CPU,
  exceeding Ruffle's **15 s `max_execution_duration` script watchdog**
  (`core/src/player.rs`, release default), which terminates the frame handler:
  ```
  ERROR ruffle_core::avm2: Error dispatching event "enterFrame":
  RustError("A script in this movie has taken too long to execute and has
  been terminated.")
  ```
  Confirmed frozen: **210 byte-identical frames** after onset, no player/enemies/
  animation, clicks dead. The watchdog measures CPU time *inside one script
  invocation* (independent of frame pacing / headless), so **real-browser Ruffle
  hits the same wall** — faithful, not an exporter artifact.

**Repro (patched exporter — patches env-gated, in the `~/CC/ruffle` reference
repo, NOT SWFRecomp):** a tracing subscriber (`exporter/src/main.rs`, `RUST_LOG`)
+ a minimal file-serving navigator (`exporter/src/local_navigator.rs`, gated on
`RUFFLE_LOCAL_FETCH_DIR`, maps `http(s)://host/path` → `$DIR/host/path`, polled
once/frame, no reqwest/tokio). Serve the real AGI.swf (HTTP 200, 141 KB, CWS v12)
at `fetchroot/cache.armorgames.com/assets/agi/AGI.swf`, set
`RUFFLE_MOVIE_URL=http://armorgames.com/566862_ElephantQuest.swf` (so `DOMAIN =
armorgames.com` and the AGI absolute-URL fetch + Security stubs resolve), drive
Play → New Game → 9× click-to-continue. This **`RUFFLE_LOCAL_FETCH_DIR`
local-navigator is a reusable oracle capability** for any game needing external
assets. (Optional follow-up: raise `max_execution_duration` to confirm the world
map fully populates given unlimited time — the HUD data already indicates a
finite, legitimate build, not an infinite loop.)

---

## 3. Oracle ruling (FINAL)

The failure is a **Ruffle performance cliff, not a feature cliff** (§2). This
gives us *more* oracle coverage than feared, and a bounded boundary:

- **Full oracle with an AGI stub: boot → menu → story → "loading world map" →
  `init2()` DOOR-build traces → the FIRST rendered world-map frame.** Everything
  up to and including the first world-map render is byte/pixel-checkable against
  a Ruffle export (CPU-dump-vs-export MAD, `RUFFLE_LOCAL_FETCH_DIR` navigator +
  `RUFFLE_MOVIE_URL`). This covers the entire non-gameplay front half of the game.
- **Instruments-only past the first world-map frame.** Ruffle's watchdog kills it
  there, so **live gameplay has no Ruffle oracle** — graded by authored tests +
  internal consistency + the decompiled semantics.
- **The boundary is Ruffle's 15 s script watchdog**, i.e. a perf limit, not a
  missing API. So — unlike a feature cliff — the same content is *fully defined*
  AS3 that Ruffle executes correctly right up to the timeout; we are not flying
  past unimplemented behavior, just past where Ruffle runs out of time.

**Strategic payoff (the headline):** EQ is the first corpus title where **Ruffle
literally cannot reach gameplay** — its interpreter is too slow to finish the
world-map construction within its own watchdog (and even without the watchdog,
~18 s/build is unplayable). Our AOT-compiled runtime (native/wasm, operand stack
as C locals) has no interpreter watchdog and should finish `init2()` in a small
fraction of that. **If our pipeline builds the world map and runs gameplay, we
have concretely beaten Ruffle on a real title it cannot play** —
[[swfrecomp-purpose-beat-ruffle-perf]] validated on new ground. This makes EQ a
higher-value target than the rwf/rwic titles (which Ruffle merely renders blank).

---

## 4. Our bring-up state

- **`--check-abc`: 1310 bodies, verify_fails = 1** —
  `body=1309 method="" code=1011 msg="unknown ABC opcode 0xf4"`. Cheap + safe
  (11 MB RSS). This is gap #1.
- **Full recompile / native build: NOT ATTEMPTED** — blocked by gap #1 (the ABC
  parse aborts for the whole file, §gap-1) and deferred for OOM safety (§5).
  **No frame dumps yet.** (Per [[avm2-localconnection-silent-blank-stage]] we do
  not claim any boot state we have not dump-proven — and we have proven none.)

---

## 5. Gap list — ranked cheap → expensive

### Gap 1 — [BLOCKING · cheap-moderate recompiler] Tolerant per-body verify (quarantine the decoy body)

- **What:** body 1309 (the *last* body) contains **unknown opcode `0xf4`**.
  `0xf4` is undefined in AVM2 (real debug ops stop at `0xf3` Timestamp), so it is
  a **`betz` obfuscator decoy** in a dead body. Ruffle verifies **lazily per
  method** and never executes this body, so it never chokes. Our recompiler
  decodes/verifies **all** bodies AOT: the throw at
  `abc_parser.cpp:830` propagates to `parseAbc` which returns **`false` for the
  entire ABC** (`abc_parser.cpp:584`) — **all 1310 bodies fail to recompile.**
- **Why it's the gateway:** nothing else can be tested until the ABC recompiles.
- **Fix-shape (cheap, localized):** the structural parse already succeeds —
  `readMethodBody` stores each body's code as an **isolated, length-delimited**
  byte vector (`body.code`, `code_len` at `abc_parser.cpp:481-490`), so the byte
  stream never desyncs. Move opcode-decode failure to a **per-body catch**:
  quarantine the offending body (emit a stub that throws `VerifyError` at runtime
  if ever invoked) instead of aborting the file. This mirrors Ruffle's lazy
  per-method model. **Grade** with a new `regression/` test: a hand-built ABC
  (mxmlc/asasm, or a crafted DoABC) with one junk-opcode body plus N good ones —
  assert the good bodies run and the game reaches boot; the quarantined body only
  throws if called. ([[custom-tests-live-in-regression-suite]])
- **Risk:** verify only found **one** decoy, but other rarely-verified bodies
  could hide more; the quarantine model makes that a non-event (each is isolated)
  rather than a whack-a-mole.

### Gap 2 — [low-risk · confirm at build] `getDefinitionByName("Level"+n)` dynamic class resolution

- Levels resolve via `getDefinitionByName("Level"+n) as Class` (`Game.as:720`)
  for the 47 embedded `Level0..46` classes. **Ruffle executes this fine** (§2 —
  it traces the DOOR build), so it is valid AS3 our runtime must also handle;
  `getDefinitionByName` **exists** in our runtime (`avm2_globals.c`). Only the
  depth for **string-built** class names + `as Class` construction is untested on
  this corpus — confirm at `init2()`, but no longer a prime failure suspect.

### Gap 2b — [our advantage, watch · perf/memory] `init2()` is a heavy synchronous build

- `init2()` synchronously constructs the world-map level: the DOOR-build alone
  traces `DOOR 0`…`DOOR 999` and takes **~18 s in Ruffle's interpreter** (which
  is *why* Ruffle times out, §2). This is a **finite, legitimate** build (the HUD
  renders real data), not a loop bug. For our AOT runtime it should be fast — but
  it is the one spot to watch for (a) native OOM against the 512 MB arena
  (gap #6 — 1000 doors + level objects) and (b) any accidental super-linear cost.
  Not a blocker; our speed here is precisely the beat-Ruffle win (§3).

### Gap 3 — [BLOCKING New Game · stub, moderate] `agi` must be a DEFINED no-op object

- **Revised from "let the load fail" — that is wrong.** The New Game handler's
  first line is the **unguarded** `this.shell.agi.hideAGILogin()` →
  `this.agi.hideLoginStatus()` (§2). If AGI.swf does not load, `agi` is
  `undefined` and New Game throws #1010 — this is **exactly Ruffle's Failure 1**,
  and it will bite our runtime identically. Letting `Loader.load` fail silently
  does **not** work: the game hard-requires `agi` to be a defined object.
- **Fix-shape (stub, don't implement AGI):** make `AGIStuff.agi` resolve to a
  synthetic **no-op AGI shell** — a MovieClip-like object exposing no-op
  `hideLoginStatus`/`showLoginStatus`/`init`/`initAGUI`/`retrieveUserData`/
  `submitUserData`/`showScoreboardSubmit`/`showScoreboardList`/`showGameShareList`/
  `showGameShareNavi`. Cleanest: intercept the AGI.swf `Loader.load` and dispatch
  a synthetic `COMPLETE` whose `content` is this stub (so `loadComplete` runs
  normally), OR native-seed `agi`. Do **not** implement real runtime SWF loading
  or the ArmorGames API. Grade with an authored regression test (a tiny AS3 SWF
  that calls an unguarded method on a Loader-content object).
- This is the runtime analog of §2's stub-AGI Ruffle re-run; both sides need the
  same thing to get past New Game.

### Gap 4 — [stub · cheap] `SharedObject.getLocal("eleRPG0")` / `"swfstats"`

- Save. New-game path only needs `getLocal` to return an empty store so
  `Vault.isThereALoadGame()` is false (save-deser via `betz.Base64`/`Compressor`/
  adobe-JSON is `fromLoad`-gated and **not** on the new-game path). SharedObject
  exists from the RWK/sequels FlxSave work; confirm empty-store boot.

### Gap 5 — [stub · cheap] SWFStats beacon + `AS2.getURL`/`navigateToURL`

- `URLLoader.load(tracker.swfstats.com…)` (fire-and-forget) and
  `navigateToURL` (user-click store/walkthrough links) must not throw. Expected
  already-fine per the sequels.

### Gap 6 — [watch, don't fix · sizing] native build memory / single-TU OOM

- The 262 KB DoABC → **1310 bodies** is ~1.6× RWK's body count; the generated C
  is a huge single translation unit. **Running the full build concurrently with
  other heavy work OOM-crashed this 16 GB WSL box this session.** The build must
  use the large-TU compile lever (`verify_output.py` has the flags:
  `SWFRECOMP_EXTRA_DEFINES`, split/large-TU handling ~lines 2016-2075) and be run
  **alone with memory monitoring**. 512 MB arena is the default; a native OOM is
  a finding to record, not fix today.

### Gap 7 — [low risk · note] betz control-flow obfuscation

- The `§§push`/`if(37==34)` junk wraps every method; the decompiled `.as` is
  structurally unreliable — **read the ABC for semantics** (same as the sequels'
  obfuscated builds). `flash.desktop.*` appears only as a wildcard import (no
  real `NativeApplication` use expected); do not chase it.

---

## 6. Next-session recommendation (honestly sized)

**Recommend: fix gap #1, then attempt the first monitored native build — one
session, gated on the build not OOMing.**

1. Implement gap #1 (tolerant per-body verify / quarantine) + its regression
   test. This is a contained recompiler change and is the gateway to everything.
   Ship via `.claude/pipeline-handoff.md` (no-graphics; +graphics only if render
   paths change — they won't). ~½ session.
2. With the ABC recompiling, run the **native build ALONE, memory-monitored**,
   using the large-TU lever. Then `AVM2_CPU_DUMP` frame dumps of preloader →
   title → New Game → `init2()`. Catalog whatever `init2()` hits (gap #2/#3
   first). ~½ session — **but** if the build threatens OOM, stop and record the
   sizing rather than re-crash WSL; the split-TU / arena question then becomes
   its own sized task.
3. To reach the world map (EQ-2), add gap #3 (the `agi` no-op stub) — the
   unguarded `hideAGILogin` #1010 blocks New Game on our side exactly as it did
   Ruffle. Then the DOOR-build/world-map render is gradeable against a Ruffle
   export (§3).
4. Beyond the first world-map frame (live gameplay — the beat-Ruffle moment,
   EQ-2.5) is **further sessions** — this is a full custom engine (`john/*` + 47
   levels + `GunSystem`/`UpgradeTree`), not a known-engine reskin, so expect more
   surface than the Flixel sequels needed.

The Ruffle oracle **is** available up to the first world-map frame via the new
`RUFFLE_LOCAL_FETCH_DIR` local navigator (§2, left in `~/CC/ruffle`, env-gated) +
a served AGI.swf — use it for front-half parity. Only live gameplay past the
watchdog freeze is instruments-only. No stub-*server* or `ruffle_desktop` build
is needed; the exporter + local navigator already do it.

---

## 7. The Seedling procedure applied to Elephant Quest

The bring-up follows the **census-driven, dependency-ordered, test-first**
method that took the runtime through Seedling (`avm2-support-plan.md` phase 1,
`avm2-seedling-plan.md` phase 2): census the game's needs → build each missing
feature as its own stage graded by an **upstream Ruffle avm2 trace-test family +
full-CI zero-regression** → open the game for debugging only once its supporting
stages are test-green → drive it divergence-harness-first with frame dumps vs a
Ruffle oracle. The four Seedling safeguards carry over verbatim: **the game is
the integration check, never the oracle**; supporting features go green in tests
*before* the game is opened; the render path stays a real render-tree consumer;
GC enrollment is mandatory before extended play.

**Two adaptations EQ forces (it is a custom engine Ruffle cannot play):**

- **(A) No upstream family for custom-engine gaps → author regression tests.**
  Seedling's grading backbone was "every feature has an upstream avm2 trace
  family." EQ's hand-rolled `john/*` engine may need flash.* surface the corpus
  doesn't cover; for those we **author the test** (`~/CC/flex-sdk/bin/mxmlc` →
  `ruffle-tests/tests/swfs/regression/`, [[custom-tests-live-in-regression-suite]])
  so the test — not EQ — is still the oracle.
- **(B) The Ruffle frame-oracle ends at Ruffle's watchdog (the first world-map
  frame), not at New Game.** With an AGI stub, the Seedling CPU-dump-vs-export
  MAD method (`AVM2_CPU_DUMP`, exporter with `RUFFLE_LOCAL_FETCH_DIR` +
  `RUFFLE_MOVIE_URL`) is valid **all the way through boot → menu → story →
  loading → the first rendered world-map frame** (§3) — far more coverage than
  feared. **Only live gameplay past that frame is instruments-only** — graded by
  authored tests + internal consistency + the decompiled semantics. The boundary
  is Ruffle's 15 s perf watchdog, so up to it Ruffle runs the *exact* AS3 we do.

In our favor: the runtime is now mature (5 shipped AS3 games, Stages 1-13 + GC),
so — like the RW sequels, which found **zero** new opcodes at SWF v10
([[avm2-rw-sequels-bringup]]) — EQ's census should show mostly-covered ops
(1309/1310 bodies already verify clean) and a thin gap tail. The genuinely new
category is **recompiler robustness** (gap #1's tolerant-verify), which Seedling
never exercised.

**EQ stages (dependency-ordered, each test-graded):**

- **EQ-0 — tolerant verify (gap #1).** Quarantine the `0xf4`-decoy body so the
  ABC recompiles. Recompiler change + a hand-built regression ABC (one
  junk-opcode body + N good ones). *Prerequisite for everything; grades on the
  new regression test + CI zero-regression.* Prime the census the moment this
  lands: `abc_op_census.py` over EQ **plus a shipped game as baseline in the same
  tests-dir** (the baseline diff is the signal, not the default "blocked" report,
  per [[avm2-rw-sequels-bringup]]).
- **EQ-1 — native boot → title (Ruffle-oracle window).** Memory-monitored native
  build (large-TU lever, §gap-6, run alone). Clear the missing-class /
  unimplemented-op error chain to the title menu, each fix backed by an upstream
  family or a new regression test (the Seedling session-1/2 pattern). Grade
  preloader→intro→title with CPU-dump vs a Ruffle export (oracle still valid
  here).
- **EQ-2 — New Game → world map (still Ruffle-oracle'd).** Requires gap #3 (the
  `agi` no-op stub) to clear the unguarded `hideAGILogin` #1010, exactly as
  Ruffle needed AGI.swf. Then drive New Game → story → `init2()`; confirm
  `getDefinitionByName("Level"+n)` (gap #2), `SharedObject` empty-store (gap #4),
  and the heavy DOOR-build (gap #2b) all complete natively. **Grade the first
  world-map frame against a Ruffle export (oracle valid to here).** Watch native
  heap on the DOOR-build (gap #6).
- **EQ-2.5 — the beat-Ruffle moment (instruments-only).** Drive *past* the
  world-map frame where Ruffle's watchdog freezes. If our runtime keeps rendering
  live gameplay (player/enemies/animation) where Ruffle shows 210 frozen frames,
  EQ is the first title we play that Ruffle cannot. Frame-dump-proven; no oracle.
- **EQ-3+ — gameplay depth.** Levels/combat/upgrades/world-map fidelity; then GC
  soak before extended play; perf/footprint later and separate (out of scope
  now — the intrinsics don't transfer, §1).

Reusable procedural artifacts (all already in-tree): `--check-abc` +
`abc_op_census.py` (census), `AVM2_CPU_DUMP` + `AVM2_MAX_TICKS` (deep-drive
without rebuild), the patched Ruffle exporter (`RUFFLE_MOVIE_URL`/
`RUFFLE_INPUT_FILE`, EQ: valid only pre-New-Game), per-suite `CURRENT_STATUS.md`
+ `STAGEn_CANDIDATES.txt` tracking, `mxmlc` + `regression/` for authored tests,
and the `.claude/pipeline-handoff.md` CI gate.

---

## Appendix — reproduction commands

```bash
# Cheap, safe recompile triage (11 MB RSS):
SWFRecomp/build/SWFRecomp --check-abc \
  ~/CC/newgrounds/566862_ElephantQuest_Public2_secu.swf
#   → status=VERIFY_FAIL abc_tags=1 bodies=1310 verify_fails=1
#     body=1309 "unknown ABC opcode 0xf4"

# Decompile (already done → ~/CC/jpexs/output/elephantquest/):
java -jar ~/CC/jpexs/ffdec-cli.jar -export script \
  ~/CC/jpexs/output/elephantquest \
  ~/CC/newgrounds/566862_ElephantQuest_Public2_secu.swf

# Ruffle repro — Failure 1 (NullNav): Play → New Game → #1010 at the click.
# Ruffle repro — Failure 2 (AGI served → the user's failure): the watchdog freeze.
#   Patched exporter (env-gated, in ~/CC/ruffle): tracing subscriber + a
#   RUFFLE_LOCAL_FETCH_DIR file-serving navigator. Serve the real AGI.swf, then:
SWF=~/CC/newgrounds/566862_ElephantQuest_Public2_secu.swf
RUST_LOG=info \
RUFFLE_INPUT_FILE=.../input4_play_newgame_story.json \
RUFFLE_LOCAL_FETCH_DIR=.../fetchroot \
RUFFLE_MOVIE_URL="http://armorgames.com/566862_ElephantQuest.swf" \
  ~/CC/ruffle/target/release/exporter "$SWF" phaseE/ --frames 850 --graphics gl -s 2> log.txt
#   → traces DOOR 0..999, renders the world map, then:
#     ERROR ruffle_core::avm2: enterFrame: "...taken too long to execute..."
# Artifacts (frames + logs): scratchpad/eq_ruffle/{keyframes,phaseE,fetchroot}/
# run ALONE (concurrency OOM-crashed WSL).
```
