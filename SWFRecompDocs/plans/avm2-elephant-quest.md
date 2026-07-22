# AVM2 corpus expansion — Elephant Quest bring-up plan

**Status: EQ-0 + EQ-1 DONE (2026-07-21).** EQ-0: tolerant verify was ALREADY
IMPLEMENTED (recompile UNBLOCKED). EQ-1: the native build **compiles, links, and
runs 300 ticks in ~1 s with no OOM**; frame dumps show frame1 executing (SWFStats
beacon + `DOMAIN = armorgames.com`), the first wall **`#1065 ContextMenuItem`**
(frame1:132) now **FIXED** (`flash.ui.ContextMenuItem` + `ContextMenu.customItems`
stubs in `avm2_text.c` + regression test `avm2_contextmenu_stub`). Boot rests at
the **frame1 preloader, healthy, awaiting a Play-button CLICK** — a *drive* gap;
the title menu is EQ-2 (click injection + intro/menu chain; §4, §5 gap #8).

The gap-#1 premise below was **stale**: `readOp` (the
`0xf4` throw site, `abc_parser.cpp:830`) is **never called by `parseAbc`** — only
by the verifier (`abc_verifier.cpp:1288`, which catches per-body and returns
false) and the emitter's fingerprint hashing (all try/catch-guarded). Per-body
verify with a runtime-throw quarantine stub (`avm2_verify_error_body`,
`abc_emit.cpp:2828`) has existed since **AVM2 Stage 2 (`0fec4fbe6`)**. The
diagnosis session never ran the recompile, so it mis-traced the throw to
`parseAbc` (`:584`). **Empirically proven (2026-07-21):** the full C-gen recompile
of Elephant Quest emits `parsed OK (221 classes, 1310 methods, 1310 bodies, 1
verify failure(s)); emitted AVM2 C` — **1310 body fns, exactly 1 quarantine stub
(body 1309, the `0xf4` decoy), no file abort**, 632 MB RSS / 18.5 s (well under
the 4 GB recompile ulimit). Locked in by regression test
`ruffle-tests/tests/swfs/regression/avm2_tolerant_verify_quarantine` (a
hex-patched 5-body SWF: `bodies=5 verify_fails=1 body=3 "unknown ABC opcode 0xf4"`
— same shape as EQ body 1309; good bodies trace, decoy never called). **EQ-0 was
docs + a test, zero recompiler source change.** EQ-1 (native build) is next.

**Original diagnosis (2026-07-21) below — corrected in place where stale.** First corpus title beyond the
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
- **Full recompile (C-gen): DONE 2026-07-21, SUCCEEDS** — `1310 bodies, 1 verify
  failure; emitted AVM2 C`, 632 MB RSS / 18.5 s. Gap #1 was never a real block
  (§gap-1). Output: `RecompiledABC/abc0_methods.c` (6.4 MB, 1310 body fns + 1
  quarantine stub), `RecompiledTags/draws.c` (**209 MB** — embedded assets),
  `abc_timeline.c` (12 MB). **The 209 MB `draws.c` + 6.4 MB single-TU
  `abc0_methods.c` are the gcc-OOM surface for EQ-1, not the recompile.**
- **Native build: EQ-1 DONE 2026-07-21 — BUILDS, LINKS, RUNS, no OOM.**
  no-graphics `-O0` (8 GB `ulimit -v` guard): recompile-cache + compile 36 s
  (ccache-warm; ~237 s cold), **300 ticks in ~1 s** (no interpreter watchdog — the
  beat-Ruffle premise holds). gcc compiles files one-at-a-time, so the 209 MB
  `draws.c` / 6.4 MB `abc0_methods.c` never OOM at `-O0`; peak ~3.3 GB.
- **Frame-proven boot state (`AVM2_CPU_DUMP`, 800×500 CPU composite):**
  frame1 executes fully — SWFStats beacon fires with the correct
  `armorgames.com` URL, `trace("DOMAIN = armorgames.com")` (matches the Ruffle
  oracle), then `SoundBox.initContextMenu`. **First wall (now FIXED): `#1065
  ContextMenuItem is not defined`** at `MainTimeline.frame1:132`, which aborted
  frame1 *before* `preloadIt()` → blank stage (all 120 ticks byte-identical
  `rgb(204,204,204)`). Added `flash.ui.ContextMenuItem` + `ContextMenu.customItems`
  stubs (`avm2_text.c`; `.contextMenu` setter already existed) → the #1065 is
  gone, zero errors, frame1 completes (initContextMenu → `preloadIt` → `stop`).
- **Current autonomous ceiling = the frame1 PRELOADER, healthy, awaiting a Play
  click.** `preloadIt` registers the `preload` ENTER_FRAME handler and all
  `preloader.{agButton,itemsToBuy,playB,bar,l}` addEventListener calls succeed
  (zero #1010 → the placed preloader clip + named children all exist). `preload`
  shows the Play button when loaded and gates advance on a **CLICK →
  `startIt` → `play()` → frame3 `new Shell(); shell.init()`** (MainTimeline:64-170).
  Headless has no click, so boot rests here — a **drive** gap, not a bug. The CPU
  dump renders blank gray (the timeline-placed preloader sprite does not
  composite in the AVM2 CPU-dump path — see gap #9). **No boot state past the
  preloader is claimed — none is dump-proven** ([[avm2-localconnection-silent-blank-stage]]).

---

## 5. Gap list — ranked cheap → expensive

### Gap 1 — [RESOLVED · was never a gap] Tolerant per-body verify (quarantine the decoy body)

- **RESOLVED 2026-07-21 (EQ-0). The premise was wrong — this already worked.**
  body 1309 (the *last* body) contains **unknown opcode `0xf4`** (undefined in
  AVM2; real debug ops stop at `0xf3`), a **`betz` obfuscator decoy** in a dead
  body. The claim that "the throw at `abc_parser.cpp:830` propagates to `parseAbc`
  returning false for the entire ABC" was **never verified** (the recompile was
  never run). It is **false**: `parseAbc` reads each body's code as an **opaque,
  length-delimited** byte vector (`readMethodBody`, `:481-490`) and **never calls
  `readOp`**. `readOp` (the `0xf4` throw at `:830`) runs only in (a) the verifier
  (`abc_verifier.cpp:1288`), which **catches the throw per-body** and returns
  `fail(1011, …)` → `verified=false`, and (b) the emitter's fingerprint hashing
  (all try/catch-guarded). The recompile driver (`swf.cpp`) already loops
  per-body: an unverified body just increments `verify_fails` and the emitter
  drops a **runtime-throw stub** `avm2_verify_error_body(act, "unknown ABC opcode
  0xf4")` (`abc_emit.cpp:2828`) — exactly Ruffle's lazy per-method model. This has
  been in place since **AVM2 Stage 2 (`0fec4fbe6`)**.
- **Empirical proof:** full C-gen recompile of EQ → `1310 bodies, 1 verify
  failure; emitted AVM2 C`; generated `abc0_methods.c` has **1310 body fns and
  exactly 1 `avm2_verify_error_body` stub** (body 1309). 632 MB RSS, 18.5 s.
- **Regression net:** `regression/avm2_tolerant_verify_quarantine` (mxmlc +
  `create_test_swf.py` hex-patch of one body's first op to `0xf4`; asserts the two
  good bodies trace and the file does not abort). Non-empty `output.txt` so a
  regression-to-abort fails loudly. ([[custom-tests-live-in-regression-suite]])
- **Robustness note (still true):** verify found **one** decoy, but the quarantine
  model makes any further hidden decoy a non-event — each bad body is isolated and
  stubbed, never a whack-a-mole or a whole-file abort.

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

### Gap 6 — [RESOLVED · no OOM at -O0] native build memory / single-TU

- **RESOLVED 2026-07-21 (EQ-1).** No OOM. `compile_native` compiles files
  **one-at-a-time** (`gcc -c src.name`), so the huge units never coexist: the
  209 MB `draws.c` (embedded-asset data arrays) and 6.4 MB `abc0_methods.c` (1310
  body fns) each fit at `-O0` with peak ~3.3 GB (8 GB `ulimit -v` guard, box has
  13 GB free). Cold build ~237 s; ccache-warm ~36 s. The C-gen recompile is a
  separate 632 MB / 18.5 s step (§4). **Do NOT retry the -O2 concurrent build that
  crashed WSL — `-O0` alone is the recipe.** Run ALONE (no concurrent heavy
  compiles) still holds. 512 MB arena default; not yet stressed (boot rests at
  the preloader, no world-map build reached).

### Gap 7 — [low risk · note] betz control-flow obfuscation

- The `§§push`/`if(37==34)` junk wraps every method; the decompiled `.as` is
  structurally unreliable — **read the ABC for semantics** (same as the sequels'
  obfuscated builds). `flash.desktop.*` appears only as a wildcard import (no
  real `NativeApplication` use expected); do not chase it.

### Gap 8 (was the frame1 wall) — [RESOLVED · cheap stub] `flash.ui.ContextMenuItem` + `ContextMenu.customItems`

- **RESOLVED 2026-07-21 (EQ-1).** `MainTimeline.frame1:132` →
  `SoundBox.initContextMenu` (`SoundBox.as:180`) builds a cosmetic right-click
  menu: `new ContextMenu()` (existed) → `hideBuiltInItems()` (existed) →
  **`new ContextMenuItem(caption)`** (MISSING → `#1065`) → `item.enabled = false`
  → `customItems.push(item)` (customItems MISSING) → `this.contextMenu = menu`
  (InteractiveObject setter already a no-op stub). The `#1065` aborted frame1
  **before `preloadIt()`** → blank stage. Fix: `flash.ui.ContextMenuItem`
  (no-op ctor + settable-noop `enabled`) + `ContextMenu.customItems` (fresh
  discardable Array) in `avm2_text.c`. Graded by `regression/avm2_contextmenu_stub`
  (mirrors the exact init path). Cosmetic — the menu is never read back headless.

### Gap 9 — [DRIVE, not a bug · EQ-2 gateway] preloader is Play-CLICK-gated

- **The current autonomous ceiling.** `MainTimeline` `addFrameScript(0,frame1,2,
  frame3)`; frame1 `stop()`s and `preloadIt()` registers the `preload`
  ENTER_FRAME. `preload` (MainTimeline:64) shows the Play button when
  `bytesLoaded >= bytesTotal` and gates advance on **CLICK → `startIt` →
  `play()` → frame3 `new Shell(); shell.init()`**. Headless has no click, so boot
  rests at frame1. **Not a bug** — every `preloader.{playB,agButton,itemsToBuy,
  bar,l}` access succeeds (zero #1010). To advance: inject a click via the native
  binary's **event-file arg** (`verify_output.run_binary(event_file=…)` ←
  `input.json` → `preprocess_input_json`, the RWK/TAS mechanism). Needs the
  Play-button stage coords + the load-complete gate. **EQ-2 first step.**

### Gap 10 — [render-path · T1+T2+T3+T5+T4+T6 + native TEXT SHIPPED · the AVM2 vector renderer] solid + stroke + gradient timeline shapes, morphshapes, script-drawn flash.display.Graphics, AND native timeline EditText render on GPU/Dawn AND headless CPU; getPixel gate live

- **Native timeline EditText DONE 2026-07-22 (`9ab376ded`) — the HUD text now
  renders.** `DefineEditText` / dynamic `TextField` composites on both sinks:
  `avm2_cpu_raster_text` (CPU, refactored from `bd_draw_textfield`'s glyph
  scanline) is dispatched from `avm2_cpu_walk` **and** `bd_draw_shape_walk`, and
  `avm2_render_text` (GPU) runtime-tessellates glyph outlines → `renderer_draw_tris`
  in `avm2_render_node`. So EQ's **HUD numbers/labels** ("400/400 HP", "25,293 XP",
  "Level 1", "Area 5") now paint — the last blank-render item of gap #10. Embedded
  fonts only (device-font / static `DefineText` deferred — see the plan's scope
  ruling; **confirm EQ's title/preloader static-text usage** before assuming it
  renders). getPixel-gated (`regression/avm2_timeline_text`). See
  `avm2-native-text-render-plan.md` §"RESULT".
- **T4 DONE 2026-07-21 — script-drawn UI now renders.** `flash.display.Graphics`
  runtime drawing (`beginFill`/`beginGradientFill`/`lineStyle`/`drawRect`/`drawCircle`/
  `moveTo`/`lineTo`/`curveTo`/`drawPath`/`drawTriangles`) is a real vector backend on
  both sinks: recorded → tessellated at runtime → `avm2_render_graphics` (GPU) +
  `avm2_graphics_cpu_composite` (CPU/`bd_draw`). So EQ's **script-drawn HUD/UI** (any
  `graphics.*` drawing) now paints, not just timeline `DefineShape`s. R2 dynamic
  gradient pool confirmed live. getPixel-gated (`regression/avm2_graphics_runtime`).
  See `avm2-vector-rendering-plan.md` §"T4 RESULT" + `[[avm2-graphics-t4-render]]`.


- **T1 DONE 2026-07-21 (`63ca22e39`).** The AVM2 render walk now paints
  **solid-fill `DefineShape` timeline content**: the recompiler emits a
  `char_id→(vert_offset,vert_count)` table (`avm2_generated_shape_geom[]`) into the
  AVM2 char tables, the ext caches it at place-time, and `avm2_render_shape`
  dispatches `renderer_draw_shape` beside the `is_bitmap` gate in
  `avm2_render_node`. **Risk R1 (the baked Y-flip) was a non-issue** — `shape_data`
  already stores shape-local Flash Y-down twips (the recompiler's `FRAME_HEIGHT-y`
  round-trip cancels), so AVM2 reuses the resident triangles directly; a solid
  timeline shape renders **upright at the correct stage position** under Dawn
  (`graphic_linkage`, char 22 @ 50,50px, frame-proven). See
  `avm2-vector-rendering-plan.md` §"T1 RESULT" + `[[avm2-shape-render-r1-noflip]]`.
- **Still blank on the headless CPU-dump (`AVM2_CPU_DUMP`) — that is T5.** T1 lands
  the **GPU/Dawn** sink only; `avm2_cpu_walk` stays bitmap-only until the ported
  `RASTER_TRI*` rasterizer (T5). And `BitmapData.draw` does not yet rasterize
  shapes (`bd_draw`, `avm2_bitmap.c:1951`), so the pixel-as-trace gate also waits
  for T5. **The EQ preloader now renders vector content on GPU; the headless
  frame-proof the EQ bring-up relies on stays blank until T5.**
- **T2+T3 DONE 2026-07-21 (this session).** Line strokes and gradient fills
  (linear/radial/focal + pad/reflect/repeat spreads) now render on the GPU/Dawn sink
  too — pure gate-relaxation, the `solid_only` flag became `renderable` (cleared only
  by bitmap fills). Authored probes (`avm2_timeline_stroke_gradient`,
  `avm2_timeline_gradients`) render pixel-identical to Ruffle `--graphics gl` exports;
  the radial falloff confirms the static-gradient inverse-matrix compute pass fires for
  AVM2. See `avm2-vector-rendering-plan.md` §"T2+T3 RESULT". **The change is purely
  additive** (it only *admits* previously-skipped stroke/gradient shapes; it cannot
  regress the solid rendering T1 already frame-proved), so EQ's preloader stroked
  outlines / bars and any title/HUD gradients now paint on GPU/Dawn by construction. A
  fresh EQ `--mode=graphics` re-dump was **deferred this session** — the isolated probes
  exercise the identical recompiler→runtime→shader→Dawn pipeline, and a local `-O0` EQ
  rebuild (209 MB `draws.c`, OOM-risky, §gap-6) is not worth the risk when it is the
  integration check, never the gate. Re-dump recipe is unchanged (§gap-6 / Appendix).
- **T5 DONE 2026-07-21 (this session) — the headless CPU-dump now composites
  shapes, and the `BitmapData.draw→getPixel` gate is live.** New
  `avm2_cpu_raster.c` (a Dawn-free triangle rasterizer over the resident
  `shape_data`, mirroring the WGSL shader) is dispatched in `avm2_cpu_walk`
  (Leg 1) and drives a `bd_draw` shape-source arm (Leg 2). Three `regression/`
  `getPixel` tests (`avm2_timeline_solid`, `avm2_timeline_stroke_gradient`,
  `avm2_timeline_gradients`) now gate **byte-exact vs the Ruffle exports in
  no-graphics** (solid/stroke/linear/radial/focal/reflect/repeat all match) —
  CPU == GPU == Ruffle. See `avm2-vector-rendering-plan.md` §"T5 RESULT".
  - **EQ preloader headless frame-proof: DEFERRED (documented).** The gap-#10
    fix is the *mechanism*, and `avm2_cpu_walk` now composites the same
    `shape_data`/gradient content the probes exercise byte-exactly — but no EQ
    binary exists locally and its `-O0` recompile (209 MB `draws.c`) is the known
    OOM-risk heavy compile (§gap-6). The headless dump will show the
    elephant/cityscape once an EQ binary is built; the authored probes carry
    correctness in the meantime (the same pipeline, isolated).
- **`Graphics` (T4) still blank by design; bitmap-fill timeline shapes deferred**
  — the `renderable` gate skips only bitmap-fill shapes (need a static bitmap
  atlas, `BITMAP_COUNT 0`). T4 (runtime `flash.display.Graphics`) is now the next
  tranche and inherits the T5 `getPixel` gate for free
  (`avm2-vector-rendering-plan.md` §"T4 sizing").

---

#### (historical) Gap 10 — the pre-T1 survey that scoped this track

- **Ruled (2026-07-21, planning session — see
  `SWFRecompDocs/plans/avm2-vector-rendering-plan.md`, the source of truth for this
  gap).** The blank `rgb(204,204,204)` is **not a CPU-dump quirk** — the entire AVM2
  render path is **Bitmap-blit only**. Both walks paint solely `ext->is_bitmap`
  nodes: the GPU/OFFSCREEN `avm2_render_node` (`avm2_display.c:7560-7576`, only
  `renderer_draw_bitmap_quad_scaled`) and the headless CPU-dump `avm2_cpu_walk`
  (`:7371-7388`). jmtb02's preloader is timeline-placed `DefineShape`/`DefineSprite`
  vector, so it renders nothing on **either** sink.
- **The stale "use the graphics/Dawn path" note is CORRECTED: Dawn is equally
  Bitmap-only for AVM2 today.** `avm2_render_node` (the Dawn walk) and `avm2_cpu_walk`
  (the CPU dump) are the *same* bitmap-gated recursion; switching sinks changes
  nothing. The real fix is the **AVM2 vector renderer track**.
- **Not a from-scratch rasterizer — a port.** The recompiler already tessellates
  every `DefineShape` for AVM2 SWFs (`interpretShape`, `swf.cpp:2213/7609` → the
  209 MB `draws.c`, §4) and the runtime already loads the triangles
  (`avm2_render_init` copies `context->shape_data`, `avm2_display.c:7603-7616`). The
  shared backend `renderer_draw_shape`/`draw_tris`/`draw_gradient_tris`
  (`render_webgpu.h:235-291`) is display-model-agnostic and AVM2 already drives its
  slot model for bitmaps. **The one missing link is a `char_id → (shape_offset,
  size)` map for AVM2** (the AVM1 `Character` dictionary is not linked into the AVM2
  runtime) plus the walk-side dispatch.
- **Plan:** tranched T1–T7 in `avm2-vector-rendering-plan.md`. **T1 (solid-fill
  timeline shapes) unblocks the frame1 preloader render on the GPU/Dawn sink;
  T5 (ported `RASTER_TRI*` CPU rasterizer) resolves the headless `AVM2_CPU_DUMP`
  render.** First-session prompt:
  `prompts/avm2-vector-render-t1-solid-timeline-shapes.md`. Highest-risk unknown is
  the baked `FRAME_HEIGHT-y` Y-flip in `shape_data` (Risk R1), front-loaded into T1.
- **This renderer is its own deliberately-scheduled track, PARALLEL to the EQ
  boot-chain** (EQ-2 click-injection / `agi` stub / `init2()` are trace-gradeable and
  do not need rendering). The two tracks meet only at frame-proofing: once T1 lands,
  EQ's preloader→title→world pixel oracle (§3) becomes usable.

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

- **EQ-0 — tolerant verify (gap #1). ✅ DONE 2026-07-21.** No recompiler change
  needed — the per-body quarantine already existed (§gap-1). Delivered: the
  empirical recompile proof + regression test
  `regression/avm2_tolerant_verify_quarantine` (hand-patched `0xf4` body) + this
  doc correction. Census (still TODO, cheap): `abc_op_census.py` over EQ **plus a
  shipped game as baseline in the same tests-dir** (the baseline diff is the
  signal, not the default "blocked" report, per [[avm2-rw-sequels-bringup]]).
- **EQ-1 — native boot. ✅ DONE 2026-07-21 (reached the preloader, not yet the
  title).** Build works, no OOM at `-O0` (§gap-6). Error chain cleared so far:
  `#1065 ContextMenuItem` → fixed (§gap-8, + `avm2_contextmenu_stub`). Autonomous
  boot rests at the **frame1 preloader** — the Play button is CLICK-gated
  (§gap-9), so reaching intro→title needs click injection (EQ-2). **The frame1
  preloader now RENDERS on the GPU/Dawn sink (gap #10 T1, 2026-07-21, `63ca22e39`):
  the blue elephant + trunk-to-bowler-hat + gray cityscape draw instead of blank
  `rgb(204,204,204)`** — frame-proven at ticks 3/6/8 under `--mode=graphics -O0`
  (no OOM, ~1.5 GB cc1 peak on the 209 MB `draws.c`). The **headless CPU-dump stays
  blank** (T5 ports the CPU shape rasterizer), so the CPU-dump-vs-Ruffle pixel
  oracle is still not usable — but the Dawn sink now is. Census still TODO (§EQ-0).
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
