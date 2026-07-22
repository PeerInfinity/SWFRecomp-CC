# AVM2 corpus expansion — Snailiad bring-up plan

**Status: NATIVE GAMEPLAY REACHED (2026-07-22, first session).** Boot →
preloader Play click → NG splash → title → menu → difficulty select → intro
→ Snail Town gameplay with movement — all frame-proven on the native -O0
no-graphics build via `AVM2_CPU_DUMP`, **zero runtime errors, zero code
changes needed**. Ruffle-oracle parity run pending. Target:
`~/CC/newgrounds/573352_Snailiad.swf` (Auriplane / Crystal Jacobs, Newgrounds
2011 — metroidvania). Method = the Seedling/EQ procedure (census → gap map →
staged bring-up graded by regression tests + CI zero-regression → game-last
debugging), see `avm2-elephant-quest.md` §7.

Decompile: `~/CC/jpexs/output/snailiad/scripts/` (802 `.as`, fully readable —
**no obfuscator**, unlike EQ/RW).

---

## 1. Recon (confirmed)

- 6.4 MB CWS, **SWF v10**, 800×480 @ 24 fps ("real" rate: game sets
  `FlxG.framerate = 120` at boot — stage frameRate 120), **2 root frames**,
  **2 DoABC tags** (Flex-style frame factory: abc0 = frame1 preloader,
  abc1 = frame2 main). Decompressed 9.66 MB. 251 SymbolClass bindings.
- `--check-abc`: **status=OK, 2 abc tags, 6967 bodies, verify_fails = 0.**
  No decoy opcodes, no tolerant-verify work needed (EQ gap #1 N/A).
- Full C-gen recompile: **clean, exit 0, 8.2 s, 403 MB peak.**
  - abc0: 45 classes / 678 methods / 568 bodies, 0 verify failures.
  - abc1: 770 classes / 7225 methods / 6399 bodies, 0 verify failures.
  - Output: 60 MB RecompiledABC (abc1_methods.c 29.7 MB, abc_timeline.c
    29.5 MB), 163 MB draws.c — inside the proven EQ -O0 envelope.
  - ⚠ One tag warning: `tag 32 (DefineShape3) failed: std::exception`
    (char id 37, 255 bytes, sits among the NewgroundsAPI FlashAd / Flex
    BusyCursor assets, NOT SymbolClass-bound → cosmetically irrelevant
    offline, but the parser exception is a latent bug worth a follow-up).
  - 2× "johnson cycle detection exceeded 4000 cycles" (known benign warning).
- **Engine: Flixel 2.3x (patched by the author) + the Flex framework.**
  - `org/flixel/*` — FlxQuadTree, FlxTilemap, FlxSave, FlxSound, FlxMonitor
    present; no FlxEmitter. `FlxTilemap.loadMap` is author-patched (6th
    layer-name arg) and is fed **ByteArrayAsset instances coerced to String**
    (AVM2 `coerce_s` → `ByteArray.toString()` must return the CSV text —
    runtime checkpoint).
  - `mx/*`, `spark/*`, `flashx/*` — the Flex framework is linked (compiled
    with the Flex SDK); the vast majority is **dead code** (script inits are
    lazy). Live mx surface = the `[Embed]` asset classes only:
    `mx.core.{BitmapAsset, SoundAsset, FontAsset, ByteArrayAsset}` (same
    machinery as Seedling).
  - `com/newgrounds/*` — Newgrounds API v1 (medals, saves, ads) + a
    `FlxNGPreloader`.
  - Game code: default package, ~380 classes (PlayState 992 lines, Player
    3001 lines, bosses/enemies/items). 4 FlxTilemap layers (sky/bg/fg/sp)
    loaded from embedded CSV text assets — **no arrayToCSV hot path**
    (maps are pre-authored, not generated).
- **Op census vs RWK baseline: 16 new ops, no wall.** `ApplyType`
  (Vector.<T>) + E4X ops (`GetDescendants`, `EscXElem`, `CheckFilter`) appear
  **only in dead Flex code** (zero `Vector.<` uses outside mx/spark/flashx);
  the rest (NewFunction, Get/SetSuper, In, TypeOf, PushWith, NextName,
  DeleteProperty, …) are long-implemented. Runtime has avm2_vector.c and the
  E4X engine anyway.
- **Assets all embedded**: PNG spritesheets (BitmapAsset), MP3 music + SFX
  (SoundAsset), one TTF `Snailplanes` font (FontAsset, embedAsCFF=false),
  config XML + 4 world-map CSVs as octet-stream ByteArrayAssets. No
  ImportAssets, no external loads for content.
- **Save**: `SaveData extends FlxSave` → `SharedObject.getLocal("Snailiad","/")`
  (supported). `Cipher`/`CipherInt` = XOR-table value obfuscation for the
  save blob, pure AS, no gap.
- **No trace() calls anywhere** → grading is frame-dump MAD vs the Ruffle
  oracle + instruments (RWK-2 method), not trace diffs.

## 2. Boot chain (fully mapped, EQ-shaped)

1. Frame1: `Preloader extends com.newgrounds.components.FlxNGPreloader`
   (MovieClip). ENTER_FRAME → `create()` → draws load bar →
   `API.connect(loaderInfo, "18670:nrJul9g0", key)`.
2. Load bar tracks `bytesLoaded/bytesTotal` → for us instantly 1.0 →
   **Play-button CLICK gate** (`autoPlay` stays false) — *identical to EQ-2;
   drive it with the native event-file mechanism (`input.json` →
   `preprocess_input_json`)*.
3. Click → `startGame()` → `nextFrame()` → `getDefinitionByName("main")` →
   `new main()` → addChild.
4. `main extends FlxGame`: `super(400, 240, PlayState, 2)` (400×240 ×2 zoom),
   `FlxG.framerate = 120`, `PauseLayer`, context menu (**ContextMenuItem
   used WITH `addEventListener` + `enabled` + `ContextMenu.hideBuiltInItems()`**
   — exercises more than EQ's no-op stub; verify it doesn't throw).
5. `PlayState.create()` → `goToMainMenu()` → STATE_SPLASH (`SplashLayer`,
   JayIsGames sponsor art) → STATE_MENU (title + `MainMenu`, keyboard-driven).

## 3. Sitelock / network ruling

- The "exclusive to Newgrounds" lock (`Preloader.fail`) fires **only** on
  `APIEvent.HOST_BLOCKED`, which requires an actual gateway HTTP response
  containing `deny_host`. Offline/no-network → never fires → `fail` stays
  false → boot proceeds. **Inert for us**, like EQ's SWFStats/AGI beacons.
- `API.isNewgrounds()` = `publisher_id == 1 || host contains ungrounded.net`;
  offline debugMode path sets `publisher_id = 1` → treated as "on Newgrounds".
- `API.connect` needs to not-throw: LoaderInfo.url/.loader/.parameters, Timer,
  URLLoader/URLRequest/URLRequestMethod/URLVariables (present in
  avm2_globals.c), Capabilities, Dictionary, Endian, RC4/BaseN (pure AS).
  Offline the gateway load just fails/times out → `API_CONNECTED(false)`,
  nothing gates on it.
- `API.unlockMedal` offline: `getMedal()` returns null → message + return.
  Safe. Medal popup (`createMedalPopup`) is display-only.
- FlashAd only instantiates on `ADS_APPROVED` (needs server) → never offline.

## 4. Oracle ruling (CONFIRMED 2026-07-22)

**Full oracle — boot AND gameplay.** Ruffle exporter (gl) replayed the same
`input3.json` via `RUFFLE_INPUT_FILE` for 1000 frames with zero errors (only
device-font + NativeMenuItem stub warnings) — no watchdog cliff, unlike EQ.
MAD alignment (offset scan for getTimer wall-clock drift):
- Title: **2.28** @ offset −40 (starfield/fade animation phase — Puppy-level).
- First gameplay frame (Snail Town): **0.261 — essentially pixel-identical.**
- Late gameplay: 18.8 raw, but visually the same scene with drifted
  player/camera + control-help fade phase — state misalignment, not a
  render gap. For strict comparisons, state-align on landmark frames.

## 5. Gap list (resolved 2026-07-22 — see §6)

1. ~~Tolerant verify~~ — N/A, 0 verify failures.
2. ~~ContextMenuItem.addEventListener + ContextMenu.hideBuiltInItems~~ —
   **already worked** (boot passes createContextMenu, no throw).
3. ~~ByteArrayAsset → String coercion~~ — **already worked** (tilemaps
   load and render; Configurable XML parses).
4. ~~com.newgrounds API offline~~ — **already worked** (full boot, 0 errors).
5. ~~FontAsset / embedded TTF `Snailplanes`~~ — **already worked** (menu +
   HUD text renders).
6. ~~Preloader Play-CLICK gate~~ — **driven** via native event injection.
7. **DefineShape3 char 37 parse exception** — offline-cosmetic only;
   latent tag-parser bug, file follow-up. [low, still open]
8. **Perf/memory watch**: `FlxG.framerate = 120`; world-load transient
   709 MB/tick, live 603 MB (browser-arena flag, §6); FlxQuadTree
   fingerprint-gate applicability unchecked. [open]

## 6. Native bring-up results (2026-07-22, session 1)

**The entire boot chain and gameplay work with ZERO runtime changes.**

- Build: `-O0` no-graphics via `vo.compile_native`, **475 s** wall
  (needs `SWFRECOMP_COMPILE_TIMEOUT=1800` — abc1_methods.c alone exceeds the
  300 s/file default), peak safely under the 8 GB ulimit guard.
- **GOTCHA — the game is completely MUTE**: no trace() calls, so a healthy
  run prints nothing and exits rc=0 ([[avm2-localconnection-silent-blank-stage]]
  lookalike). Distinguish health with `AVM2_CPU_DUMP` + `AVM2_HEAP_STATS`.
- Frame-proven chain (drivers in `scratchpad/snailiad_cgen/*.py`, event
  scripts via `preprocess_input_json`):
  1. Preloader renders (bg art + PLAY button) — tick ~9.
  2. Click Play (400,368) → NG tank splash (tick ~50) → title screen
     (tick ~450: logo, starfield, JayIsGames credit, NG panel, custom cursor).
  3. Click → main menu; Z → difficulty select (EASY/NORMAL, snail cursors,
     embedded pixel font renders); Z → intro cutscene ("ALL WAS PEACEFUL IN
     SNAIL TOWN...", ESC TO SKIP shown).
  4. ESC → gameplay in Snail Town: player snail, NPC, HUD hearts, minimap,
     area-name banner, control-help overlay. Hold RIGHT 60 ticks → snail
     moves, camera scrolls, tilemap collision correct.
- ContextMenuItem-with-listeners, ByteArrayAsset→String coercion, FontAsset
  TTF, NG API offline, FlxSave — **all already worked** (gaps #2-#5 closed
  by construction).
- Perf/memory numbers (native -O0, 1000 ticks in 29.5 s incl. frame dumps):
  - Heap live at exit **603 MB**, peak **769 MB**, OOM count 0 (4 GB arena).
  - **World-load tick (world map + 4 tilemap layers) grosses 709 MB in one
    tick** (tick 649) — FlxTilemap CSV split() string garbage, RWK-redux.
  - ⚠ **Browser flag**: live 603 MB exceeds the 512 MB wasm AVM2 arena
    ([[avm2-arraytocsv-intrinsic-and-arena-shrink]]) — the browser demo
    stage will need either the collectable-string GC to reclaim the load
    transient (likely sufficient: live-after-GC unknown yet) or a
    loadMap-parse intrinsic. Measure before sizing.

## 7. Next steps

1. ~~Ruffle oracle~~ — DONE, see §4.
2. Author a `regression/` trace-or-getPixel gate for the boot chain
   (mute game → getPixel/frame-hash gate, not trace).
3. `--mode=graphics` (Dawn) spot-check + CI both modes.
4. Browser demo stage (RWK-3 pattern): needs the §6 memory flag resolved,
   `SWF_URL` with an ungrounded.net/NG host if we want `isNewgrounds()`
   paths, wasm build + docs2 catalog entry.
5. Perf pass: `FlxG.framerate = 120` stage rate — confirm our tick pacing
   matches Flash/Ruffle timing semantics for FlxGame's elapsed-based step.
6. Low-prio: DefineShape3 char-37 parser exception (latent bug, offline-inert).

## Appendix — reproduction commands

```bash
# Cheap triage (instant):
SWFRecomp/build/SWFRecomp --check-abc ~/CC/newgrounds/573352_Snailiad.swf
#   → status=OK abc_tags=2 bodies=6967 verify_fails=0

# Decompile (done → ~/CC/jpexs/output/snailiad/):
java -jar ~/CC/jpexs/ffdec-cli.jar -export script \
  ~/CC/jpexs/output/snailiad ~/CC/newgrounds/573352_Snailiad.swf

# C-gen (8.2 s / 403 MB peak): dir with test.swf + _shared/config.toml, then
#   SWFRecomp config.toml

# Native probe (EQ-1 pattern): scratchpad/snailiad_cgen/native_driver.py
#   (vo.compile_native mode=no-graphics, AVM2_MAX_TICKS=300, 8 GB ulimit)
```
