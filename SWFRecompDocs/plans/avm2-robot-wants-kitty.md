# AVM2 next game — Robot Wants Kitty (Flixel) bring-up plan

Status: **DRAFT sketch** (2026-07-16, census done, stages proposed). Follows the
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

- **RWK-1 — headless bring-up**: recompile + link + run headless (both build
  modes compile); clear the boot/sponsor error chain; reach the menu state with
  zero uncaught errors. Divergence-harness-first per `wasm-game-debugging`;
  Ruffle oracle frames via the exporter (free, per `avm2-stage13-browser.md`
  §4). Grade: menu renders in AVM2_CPU_DUMP with sane MAD vs oracle + any
  upstream avm2 trace tests fixed along the way + zero CI regressions.
- **RWK-2 — render parity + gameplay**: tilemap/sprites/FlxText pixel parity
  vs oracle; keyboard gameplay headless (jump, shoot, collect kitty on level 1).
- **RWK-3 — browser demo**: deploy via `deploy_wasm_avm2.sh`, live keyboard
  (13c infra), audio if the parallel session has landed, docs2 demo listing.
- **RWK-4 (later, optional)**: FlxSave localStorage persistence, Kong variant,
  sequels (robotpuppy/robotfishy) as cheap engine-regression checks.

Estimate: Seedling Stage 12 took ~5 sessions from a far weaker runtime; RWK
starts with everything built. Guess 2–3 sessions to browser-playable.

## 4. Rules carried over

Game is never the oracle — every runtime fix must be graded by an upstream avm2
trace test or a new `regression/` test (custom tests go in
`ruffle-tests/tests/swfs/regression/`, MTASC won't do AS3 — use
`~/CC/flex-sdk/bin/mxmlc`). Zero pass→fail in both CI modes per stage. AVM2
work stays in `src/avm2/` + `SWFRecomp/src/abc/`; never touch `action.c`.
