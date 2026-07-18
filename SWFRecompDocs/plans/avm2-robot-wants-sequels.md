# AVM2 — Robot Wants sequels bring-up (Puppy, Fishy, Ice Cream)

Status: **STAGES 1–3 DONE for ALL THREE GAMES (2026-07-18).** Census clean,
all three boot to their title menus and are **playable headless with zero
uncaught errors**, on **exactly one runtime fix** (`flash.net.LocalConnection`).
Remaining: stage 4 (Ruffle render parity spot-check) and stage 5 (browser
demos) for each game.

Session prompt: `SWFRecompDocs/prompts/avm2-robot-wants-sequels.md`.
Template followed: `SWFRecompDocs/plans/avm2-robot-wants-kitty.md`.

## Headline

The RWK playbook's prediction held: same engine family, so **sponsor-shell
friction, not engine cliffs**. The friction ranking in the prompt was
accurate in kind but much cheaper in cost than budgeted — the single
blocker was a missing `flash.net` class, not a site-lock stand-off.

| Game | SWF ver | ABC | verify_fails | New ops | Runtime fixes | Menu | Gameplay |
|---|---|---|---|---|---|---|---|
| Puppy | 9 | 2 tags / 1578 bodies | 0 | 0 | **none** | ✅ | ✅ |
| Fishy | 10 | 3 tags / 1241 bodies | 0 | 0 | LocalConnection | ✅ | ✅ |
| Ice Cream | **10** (not 11) | 3 tags / 1370 bodies | 0 | 0 | LocalConnection | ✅ | ✅ |

## 1. Census (2026-07-18)

**Opcode surface: zero risk.** `abc_op_census.py` over all three plus RWK as
the baseline. Ops used by a sequel but not by RWK: Puppy 10, Fishy 5,
Ice Cream 7 — **every one already implemented** in `abc_emit.cpp`
(`ConvertS`, `DecrementI`, `DeleteProperty`, `GetPropertySlow`, `In`,
`NewFunction`, `NextName`, `PushUndefined`, `SetPropertySlow`, `TypeOf`,
`GetSuper`, `SetSuper`, `PushUint`). The "first v10+ AVM2 games" concern
(prompt friction #4) was a non-issue: **SWF version bumps brought no new op
or verifier surface at all.** Ice Cream is v10, not v11 as the prompt said.

**Sponsor chains (friction #1): all dead, same mechanism as RWK.** Every
game hardcodes `xplor.Version.v = "Plain"`, and every GameShedAchievement /
MyKong / Kongregate / MD5 call site is gated on `v == "Gameshed"` / `"Kong"`
/ `"Hamumu"`. No boot-time network I/O in any of the three. This is why the
stage-2 budget ("most of the first session") was never spent.

- Puppy: nothing live at all. Even `xplor.Network` is never constructed
  (unlike RWK, where it is live in WinState).
- Fishy: `SWFStats.Log.View()` fires at boot (fire-and-forget beacon,
  gates nothing); `xplor.Network` constructed unconditionally at TitleState.
- Ice Cream: `xplor.Network` constructed unconditionally at TitleState.

Both `Network` ctors only read `LoaderInfo.parameters` flashvars and do no
I/O — they need `parameters` to be a non-null Object, which it already is.

**Flixel (friction #3):** Puppy is 2.21 (same as RWK); Fishy and Ice Cream
are **2.35**. The delta is additive and tiny: `FlxPreloader` + `FlxMonitor`
added, `FlxEmitter` *removed* (none of the three ships a particle emitter).
No `FlxTilemap` variants anywhere. **Fishy's water/swim is not an engine
feature** — `xplor.Water` is a plain game class that builds a second
ordinary `FlxTilemap` layer; buoyancy is game code. Ice Cream uses three
tilemap layers via the same `loadMap` path. So: paths, not cliffs, exactly
as predicted.

**Tag inventory:** all three report `Tag type 87 not implemented`
(DefineBinaryData) and Fishy/Ice Cream also `Tag type 255` (obfuscator
metadata). Neither is load-bearing — all three run correctly regardless.

**Decompile quality (for future work, NOT a runtime concern):** Puppy is the
mangled one (127 of 131 `xplor/` filenames are `§'9§`-style, 2,856
`§§push`/`§§goto` markers). Fishy and Ice Cream have **readable class and
method names** — only 1 mangled file each (the obfuscator's domain-check
class). All three are control-flow obfuscated, so the decompiled `.as` is
structurally unreliable; read ABC for semantics. `org/flixel/**` decompiles
cleanly in every game.

## 2. Site-lock — the one real blocker, and it was a missing class (friction #2)

Both Fishy and Ice Cream run a SecureSWF-style gate as the **very first
instruction of the preloader**, before `super()` and before `className` is
set:

```as3
// xplor/Preloader.as
if(!§_-21§.§package§.§_-0§(this)) { return; }   // silent death: blank stage
className = "xplor.Xplor";
```

The gate itself:

```as3
var _loc2_:String = new LocalConnection().domain;   // NOT loaderInfo.url
if(_loc2_ == "localhost") { param1.stage.removeChildAt(0); return false; }
if(§var §.length == 0) { return true; }             // §var § is EMPTY
// ...whitelist loop, else removeChildAt(0); return false
```

**The whitelist array is empty in both games**, so this is an
anti-local-copy stub, not a real site-lock: any domain other than
`"localhost"` passes. There is nothing to spoof and no stance to take —
`flash.net.LocalConnection` simply **did not exist** in our runtime, so
both games died with `ReferenceError: Error #1065: Variable LocalConnection
is not defined` before Flixel ever started. Fishy's failure mode is worth
noting: it produced **no output whatsoever** and the test harness reported
PASS against an empty `output.txt`. A silent blank-stage boot death looks
identical to success unless you dump frames.

The prompt's suggested `GAME_SWF_URL` mechanism **does exist** (as a
build-time `-DSWF_URL` define in `verify_output.py`, feeding
`loaderInfo.url`) but was not the fix — it is how you *choose* the domain
once the class exists.

**Stance taken: implement the class faithfully, spoof nothing, patch no
SWF.** `LocalConnection.domain` now mirrors Ruffle's
`LocalConnections::get_domain` (`core/src/local_connection.rs`) exactly:

| SWF URL | domain |
|---|---|
| `file:///test.swf` | `localhost` |
| `http://www.maxgames.com/games/test.swf` | `www.maxgames.com` |
| `https://user:pw@armorgames.com:8080/a.swf` | `armorgames.com` |
| `http://192.168.1.5/test.swf` | `localhost` (IP literal) |
| `http://[::1]/test.swf` | `localhost` (IP literal) |
| `notaurl` | `unknown` |

Note AVM2 uses the **exact host**, not AVM1's superdomain. All six rows
verified against our build; the `file://` row is verified byte-identical to
Ruffle. `connect`/`send`/`close`/`allowDomain`/`allowInsecureDomain` are
no-ops (there is no IPC layer); `isPerUser` returns true.

Consequence for demos: the browser demos must be built with an http
`SWF_URL`, or the games blank-stage themselves. `build_wasm_avm2.sh`
currently hardcodes `-DSWF_URL="file:///test.swf"` — **stage 5 must
override it for Fishy and Ice Cream.**

**Graded by** new regression test
`ruffle-tests/tests/swfs/regression/avm2_localconnection_domain` (mxmlc,
`-omit-trace-statements=false`; expectations captured from Ruffle's
exporter, byte-identical). The game is not the oracle.

## 3. Headless bring-up + gameplay (stages 2–3)

All three: recompile ~3 s, build ~2 min at `-O0`, then 300 ticks to menu and
~780 ticks of scripted gameplay. **Zero uncaught errors in every run.**

- **Puppy** — title menu renders complete (title art, 6 buttons, robot,
  puppy, the "Play Robot Wants Kitty!" cross-promo, credits). Clicking
  New Game boots PlayState (game traces its own `guys: 109 / guys2: 14`
  entity census); tilemap, player, enemy, HUD clock, powerup bar, and
  `SetHelp` FlxText all render; scripted arrow-key input drives the player
  and scrolls the camera.
- **Fishy** — Armor Games splash + 7-button menu; underwater PlayState with
  water tilemap layer, fishbowl goal, crate/hazard tiles, HUD.
- **Ice Cream** — menu with the Normal/difficulty selector; outdoor
  PlayState with parallax sky/cloud layers, sun, terrain, hearts HUD,
  10-slot powerup bar.

**FlxText renders correctly everywhere** — the RWK-2 `bd_draw(TextField)`
glyph rasterization carried over to all three games for free, which is the
single biggest reason these bring-ups were cheap.

### Memory (friction #5 adjacent — a real stage-5 risk)

`AVM2_HEAP_STATS` peak allocated over a boot + gameplay run:

| Game | Peak | vs 1984 MB wasm arena |
|---|---|---|
| Puppy | **330 MB** | comfortable |
| RWK (baseline) | 1409 MB | OOMs after ~6–7 min |
| Fishy | **1577 MB** | thin |
| Ice Cream | **1770 MB** | **~214 MB headroom — likely to OOM early** |

OOM count 0 natively (4 GB arena), but this is the known
`FlxTilemap.arrayToCSV` transient-string garbage (strings are only
collected between ticks), scaled by map size and layer count — Ice Cream
runs three tilemap layers. **Stage 5 for Ice Cream (and probably Fishy)
should not be attempted before measuring in-browser**; the collectable-
strings / eden-arena follow-up already filed for RWK is the real fix.
Puppy's browser demo is unaffected.

## 4. Remaining work

1. **Stage 4 — render parity** vs Ruffle exports, per game. Use the RWK-1
   gotcha: Ruffle's AVM2 `getTimer` is **wall-clock**, so Flixel pacing
   drifts nondeterministically; always **state-align via an offset scan**
   before computing MAD. Input-scripted oracle via `RUFFLE_INPUT_FILE`
   (RWK-2's local exporter patch). Fishy is 60 fps in its SWF header vs
   Puppy/Ice Cream's 30 — expect a different drift rate.
2. **Stage 5 — browser demos** `docs2/examples/avm2/{rwp,rwf,rwic}/` via
   `deploy_wasm_avm2.sh` with `DEMO_SWF`/`DEMO_DESC`, plus catalog entries.
   **Two blockers to clear first:** the `SWF_URL` override above (Fishy,
   Ice Cream), and the heap headroom above (Ice Cream, likely Fishy).
3. Readiness note to `~/CC/Archipelago-CC/NewDocs/plans/
   seedling-swfrecomp-task-split.md` once all three demos are live
   (per the prompt's out-of-scope section — injection configs are their
   side's work).

## 5. Rules carried over (unchanged)

- The game is never the oracle — runtime fixes graded by a regression test.
- AVM2 work stays in `src/avm2/` + `SWFRecomp/src/abc/`; never touch AVM1.
- Full pipeline on runtime change: BOTH CI modes, zero pass→fail.
- Demo-only commits skip CI (`ci-only-when-observable`).
