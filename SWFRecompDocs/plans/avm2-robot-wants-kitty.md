# AVM2 next game — Robot Wants Kitty (Flixel) bring-up plan

Status: **RWK-2 DONE (2026-07-16)** — both levers landed. **Lever 1
(`BitmapData.draw(TextField)` CPU glyph rasterization)**: the recompiler now
parses DefineFont2/3 glyph shapes into flattened contour outlines
(`abc_timeline.cpp` → `Avm2FontData.glyph_pts/...`), and `bd_draw` rasterizes
TextField sources through the Stage-6 layout engine (glyph collection in
`avm2_text.c::avm2_edittext_collect_glyphs`, non-zero-winding scanline fill +
draw-matrix/cxform/blend composition in `avm2_bitmap.c::bd_draw_textfield`).
Graded by new regression test **`avm2_bitmapdata_draw_textfield`** (mxmlc +
DejaVu embed; drawn/solid-color/matrix-shift/cxform assertions; PASS both
modes; Ruffle-verified expectations). RWK menu MAD collapsed **5.53 → 0.765**
(3.11% → 0.69% px) vs the oracle; the only residual is the kitty-UFO
oscillation phase (documented pacing artifact) — every text row is
pixel-exact. Seedling smoke clean (recompile + 300 frames, zero errors,
world unchanged). **Lever 2 (headless gameplay)**: menu click → PlayState
boots (this exposed and fixed a REAL blocker: FlxTilemap.arrayToCSV's
quadratic string concat OOM'd the 1 GB native heap at PlayState boot —
strings are not GC'd; native 64-bit arena now 4 GB, `heap.c`; collectable
strings stay the long-term fix). Keyboard input drives the player; tilemap,
sprites, HUD clock, SetHelp FlxText all render in-game. **State-aligned
gameplay frame vs a Ruffle oracle running the SAME scripted input: MAD 1.68,
1.47% px — every diff is an entity patrol/animation phase** (wall-clock
pacing artifact); tiles + player + text pixel-exact. Byte-identical-to-Ruffle
Flixel physics verified by standalone probes (motion, FlxU.collide, tilemap
preCollide). New reusable tooling: **input-scripted oracle** (local
`~/CC/ruffle` exporter patch honoring `RUFFLE_INPUT_FILE`, Ruffle-test
input.json format — keys/mouse now replayable under the exporter; gotcha:
Flixel resets keys on state switch, press only after PlayState starts) +
scratch TAS driver/tracker (`rwk_drive.py`/`rwk_track.py`, recipes in the
`avm2-rwk2-text-gameplay` memory). Kitty-collection TAS handed to RWK-3:
descent legs to the JUMP powerup proven individually; full chain needs
alien-phase timing (aliens patrol at 20 px/s, deterministic per run).

Previous: **RWK-1 DONE (2026-07-16)** — headless bring-up complete, far faster
than budgeted: the injected SWF recompiles (2 abc tags, 812 bodies, 0 verify
fails) + links + runs in BOTH build modes; the boot chain needed exactly ONE
runtime fix (`flash.net.SharedObjectFlushStatus` constants, avm2_amf.c — FlxSave
compares `flush()` against `FLUSHED`; graded by new regression test
`avm2_sharedobject_flushstatus`); the game reaches the **TitleState menu with
zero uncaught errors** (visually confirmed via `AVM2_CPU_DUMP`: MaxGames splash
→ ROBOT WANTS KITTY title + tilemap + buttons + robot/kitty sprites). The
Newgrounds `529817_max` variant has `Version.v="Plain"`, so the feared
GameShedAchievement/Kong sponsor chain (§2 item 1) is compiled in but never
invoked — no URLLoader/site-lock friction at all. Bridge no-op verified
stronger than the Seedling precedent: injected-vs-plain over 300 frames is
byte-identical on stdout/stderr AND on all 300 CPU-dumped frames. Ruffle-oracle
menu comparison (state-aligned): **MAD 5.53, 3.11% px differ, all in the lower
half** — everything attributable to the ONE render gap: **FlxText draws
nothing** (`BitmapData.draw(TextField)` is a silent no-op in `bd_draw`;
probe: Ruffle rasterizes glyphs, we return zero pixels). Divergence list +
RWK-2 levers in the `avm2-rwk1-robotkitty-bringup` memory. (Older context:
2026-07-16 census below; ExternalInterface DONE same day — see §4, the
`avm2-external-interface-swfbridge` memory. Audio output also landed,
so RWK gets FlxSound for free). Follows the
Seedling playbook (`avm2-seedling-plan.md`, Stage 12/13 pattern): census → graded
bring-up → render parity vs Ruffle oracle → browser demo. Chosen because it is
tile-based, small, and — the strategic point — it is **Flixel**, the other big
AS3 indie engine (Seedling proved FlashPunk). FlashPunk + Flixel together cover
a large share of the Flash indie catalog, and both use the same
BitmapData-blit rendering model our AVM2 render path was built for.

## 1. Census (2026-07-16)

**Copies found** (~716 KB each, differ by only a few bytes — sponsor variants):
- `/home/robert/CC/newgrounds/529817_max_robotkitty.swf` ← start here
- `/home/robert/CC/kongregate/robotkitty_kong.swf` (Kong API variant)
- JPEXS decompile: `~/CC/jpexs/output/robotkitty/scripts/` (full readable source)
- Sequels for later: `robotpuppy`, `robotfishy` (same engine; robotfishy copy is
  named `locallock` — expect site-lock checks in the family).

**SWF**: v9, zlib, 640×480 @ 30fps, 2 frames, 1 DoABC, 794 bodies,
`--check-abc` verify_fails=0.

**Ops**: `abc_op_census.py` vs the 128-op implemented set (E4X_OPS.txt) —
**zero blocking ops**. Language side is done, same as Seedling was.

**Tags**: 37 DefineBitsLossless2, 32 DefineSound, 1 DefineBinaryData,
1 DefineFont3 (+AlignZones/FontName), 84 SymbolClass bindings, 1 ExportAssets.
~6x smaller asset table than Seedling (284 bitmaps / 116 binaries / 88 sounds).
No asset-size problem.

**Engine**: `org.flixel` — FlxGame/FlxState/FlxSprite/FlxTilemap/FlxText/
FlxSound/FlxSave/FlxEmitter/FlxButton/FlxQuadTree. Embed wrappers are the same
Flex machinery Seedling used: `mx.core.BitmapAsset/SoundAsset/ByteArrayAsset`
(+ `FontAsset` — the one wrapper Seedling didn't exercise). Game code in
`xplor/` package; extras: `GameShedAchievement.as` + `MD5.as` (sponsor
achievement POSTs over URLLoader).

**flash.* imports** (from decompiled source): display Bitmap(Data)/Sprite/
Loader/LoaderInfo/Stage(ScaleMode/Align), geom Point/Rectangle/Matrix/
(Color)Transform, text TextField/TextFormat/Font/AntiAliasType/GridFitType,
media Sound/SoundChannel/SoundTransform, net URLRequest/URLLoader/URLVariables/
navigateToURL/SharedObject(FlxSave), events Keyboard/Mouse/Event, ui.Mouse,
utils ByteArray/getTimer/getQualifiedClassName/getDefinitionByName,
system.Security, accessibility.AccessibilityProperties. **Every one of these
already exists by name in `src/avm2/`** (grep-verified) — depth untested, but
there is no missing-class cliff.

## 2. Expected friction (ranked)

1. **Sponsor/API boot chain** — GameShedAchievement (URLLoader POST + MD5),
   Newgrounds/Kong shells, `navigateToURL`. Must fail/timeout gracefully
   offline, exactly like Seedling's NG preloader chain (Stage 12 s1 cleared
   five such errors). Likely the bulk of session 1.
2. **FlxText / FontAsset** — Flixel renders text by drawing a TextField into a
   BitmapData buffer. FlashPunk's Text does the same and works, but RWK adds
   the `mx.core.FontAsset` embed wrapper + DefineFont3 glyph source for
   `bd.draw(textField)`. First genuinely new surface candidate.
3. **FlxTilemap** — pure BitmapData copyPixels blitting off an auto-tile sheet;
   should ride the existing path. Levels: only 1 DefineBinaryData, so maps are
   likely CSV strings in code or embedded PNGs (Flixel supports both) — check
   the decompile, don't assume.
4. **Site-lock** — the family has `locallock` variants; if RWK checks
   `LoaderInfo.url`, decide a stance (spoofable url on our LoaderInfo).
5. **FlxSave persistence** — our SharedObject is in-process only; saves won't
   survive a browser reload. Fine for first-playable; flag as follow-up
   (localStorage-backed .sol).

Audio rides the parallel audio-output session
(`prompts/avm2-audio-output.md`) — FlxSound sits on Sound/SoundChannel, so RWK
gets sound for free once that lands.

## 3. Proposed stages

- **RWK-1 — headless bring-up** ✅ DONE 2026-07-16 (see Status header):
  recompile + link + run headless (both build
  modes compile); clear the boot/sponsor error chain; reach the menu state with
  zero uncaught errors. Divergence-harness-first per `wasm-game-debugging`;
  Ruffle oracle frames via the exporter (free, per `avm2-stage13-browser.md`
  §4). Grade: menu renders in AVM2_CPU_DUMP with sane MAD vs oracle + any
  upstream avm2 trace tests fixed along the way + zero CI regressions.
- **RWK-2 — render parity + gameplay**: tilemap/sprites/FlxText pixel parity
  vs oracle; keyboard gameplay headless (jump, shoot, collect kitty on level 1).
  Lever #1 (from RWK-1): `BitmapData.draw(TextField)` rasterization (FlxText —
  every button label/credit line; probe recipe in the RWK-1 memory). Note the
  Ruffle-exporter pacing artifact: AVM2 `getTimer` in Ruffle is WALL-CLOCK, so
  Flixel's variable timestep desyncs frame indices vs our deterministic 33.3ms
  tick — compare state-aligned (offset scan), not index-aligned.
- **RWK-3 — browser demo**: deploy via `deploy_wasm_avm2.sh`, live keyboard
  (13c infra), audio if the parallel session has landed, docs2 demo listing.
- **RWK-4 (later, optional)**: FlxSave localStorage persistence, Kong variant,
  sequels (robotpuppy/robotfishy) as cheap engine-regression checks.

Estimate: Seedling Stage 12 took ~5 sessions from a far weaker runtime; RWK
starts with everything built. Guess 2–3 sessions to browser-playable.

## 4. AP integration — the injection experiments already exist (checked 2026-07-16)

RWK has no source, so the AP layer uses **bytecode injection** (Approach A of
`avm2-seedling-ap-integration.md`) — and that experiment is already done and
deployed on the Ruffle/Flash side, in Archipelago-CC:

- **Toolchain**: `~/CC/flash-ap-api/` — `inject.py` (DoABC injection with
  eager-init flags + DefineSprite/SymbolClass/PlaceObject2 to put the bridge on
  stage; runtime-agnostic, it rewrites SWF bytes pre-load) and
  `src/BridgeGeneric.as`, a **config-driven generic bridge**: EI callbacks
  `wireCheck`/`configure`/`readState`, an onEnterFrame path-walker
  (getDefinitionByName-based reads like FlxG.state → defaultGroup →
  Player.x/y), `stateChanged`/`getItemQueue` outbound, `applyItem`, and
  invocations (`new_instance`/`path_write`/`remove_last_child`). No per-game
  AS3 needed.
- **RWK is already configured**:
  `~/CC/Archipelago-CC/frontend/modules/flashPanel/swf/robotkitty_injected.swf`
  + `games/robotkitty.json` (player path reads, 10 power items, ap_locations,
  and a working teleport that constructs a fresh `xplor.PlayState` from the
  title screen then path-writes Player.x/y). Tile-map data:
  `flash-ap-api/tools/output/robotkitty_tilemap.json`. Docs:
  `Archipelago-CC/NewDocs/plans/{robot-wants-archipelago,kitty-flashpanel-setup,
  robot-wants-kitty-validator,robot-wants-kitty-playbot}.md` — including a
  four-game "Robot Wants" multiworld design (Kitty/Puppy/Fishy/Ice Cream, all
  Flixel AS3).
- **Verified today**: `SWFRecomp --check-abc robotkitty_injected.swf` →
  status=OK, abc_tags=2 (original + bridge), 812 bodies, 0 verify fails. Our
  front-end consumes the injected SWF as-is.
- **Consequences for this plan**: do the RWK-1..3 bring-up on the **injected**
  SWF from the start — `BridgeGeneric` gates everything on
  `ExternalInterface.available` and no-ops gracefully, so it costs nothing when
  the shim isn't loaded (verify this no-op holds in RWK-1). **UPDATE
  2026-07-16 (same day): `flash.external.ExternalInterface` is DONE** —
  `avm2_external.c` + `swf_bridge_avm2.js` shim + livetests, with the injected
  *Seedling* already round-tripping the full BridgeGeneric contract in a real
  browser (memory `avm2-external-interface-swfbridge`; packaged handoff at
  `docs2/examples/avm2/seedling_teleport_ap/`). So for RWK the AP layer needs
  ZERO new runtime features on paper: EI + the existing `robotkitty.json`
  should light up the flashPanel integration with no new AS3. The no-shim
  no-op check (headless trace byte-identical injected-vs-plain) is the same
  verification the Seedling EI session already ran — replicate it for RWK.
- Historical note: the injection work targeted Basilisk+Flash because Seedling
  was unplayably slow under Ruffle — the exact performance gap our runtime was
  built to close (we now beat Ruffle ~1.4x). Our runtime is the intended
  consumer of these artifacts.

## 5. Rules carried over

Game is never the oracle — every runtime fix must be graded by an upstream avm2
trace test or a new `regression/` test (custom tests go in
`ruffle-tests/tests/swfs/regression/`, MTASC won't do AS3 — use
`~/CC/flex-sdk/bin/mxmlc`). Zero pass→fail in both CI modes per stage. AVM2
work stays in `src/avm2/` + `SWFRecomp/src/abc/`; never touch `action.c`.
