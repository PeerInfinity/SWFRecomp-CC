# AVM2 — Robot Wants sequels bring-up (Puppy, Fishy, Ice Cream)

Status: **ALL FIVE STAGES DONE for ALL THREE GAMES (2026-07-18).** Census
clean, all three are **playable headless with zero uncaught errors**, menus
match Ruffle (MAD 2.334 / 0.001 / 0.200), and **all three browser demos are
LIVE** — on **exactly one runtime fix** (`flash.net.LocalConnection`).
Open follow-ups (§6): Ice Cream / Fishy PlayState is unmeasured in-browser
(probe-click limitation) and their wasm heap headroom is thin; gameplay-level
parity was not done (menus only).

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
hardcoded `-DSWF_URL="file:///test.swf"`; it is now a `SWF_URL` env
override with the same default, so Fishy and Ice Cream build with
`SWF_URL="http://www.maxgames.com/test.swf"` and every other demo is
unaffected.

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

## 4. Stage 4 — Ruffle render parity (DONE, all three)

Menu frames, **state-aligned by offset scan** (mandatory: Ruffle's AVM2
`getTimer` is wall-clock, so Flixel pacing drifts — see the RWK-1 gotcha).
Our tick 299 aligned against a 700-frame Ruffle export:

| Game | Aligned oracle frame | MAD | px differing (>8) | Residual |
|---|---|---|---|---|
| Puppy | 660 (2.2x drift) | 2.334 | 5.74% | animated promo box + puppy sprite phase |
| Fishy | 310 | **0.001** | **0.00%** | none — pixel-perfect |
| Ice Cream | 512 | 0.200 | 0.45% | ice-cream-on-UFO bob phase |

All residuals are the documented pacing-artifact class, confirmed by diff
mask: for Puppy, rows 0-179 (title art, every button and label, credits) are
**0.00% differing** and the entire diff is confined to the two animated
decorations; Ice Cream's whole diff is a 64x54 px box around the bobbing
ice-cream cone — the direct analogue of RWK's documented kitty-UFO artifact.
Ruffle's trace output matches ours exactly. Note the drift rate really does
vary per game as predicted (Puppy 2.2x, Fishy ~1.04x), so **never reuse a
tick offset across games**.

Ruffle's own exporter renders Fishy and Ice Cream fine from `file://`,
i.e. Ruffle does not hit the domain gate the way a naive `file://` build of
ours would — do not take "Ruffle rendered it" as evidence the gate is inert.

## 5. Stage 5 — browser demos

`SWF_URL` is now an env override in `build_wasm_avm2.sh` (it was a hardcoded
`file:///test.swf`), which is what lets Fishy and Ice Cream boot in-browser:
build them with `SWF_URL="http://www.maxgames.com/test.swf"`. The default is
unchanged, so every other demo builds byte-identically.

**All three demos are LIVE**, each with a catalog entry and a side-by-side
Ruffle A/B page:

| Demo | URL | wasm | SWF_URL |
|---|---|---|---|
| `rwp` | `demo.html?test=avm2/rwp` | 12 MB | default `file://` (no gate) |
| `rwf` | `demo.html?test=avm2/rwf` | 11 MB | `http://www.maxgames.com/test.swf` |
| `rwic` | `demo.html?test=avm2/rwic` | 12 MB | `http://www.maxgames.com/test.swf` |

Headed-Chrome probe on each (`tools/browser-test/probe.py`, real WebGPU —
functional only, never perf): module loads, `Run SWF` clicks, all canvas
snapshots captured, **full title menu renders, zero page errors**. The one
console error in every run is the expected `rando_bridge.js` 404 HEAD probe
(per RWK-3). Mouse tracking is confirmed live in-browser — hovering
Ice Cream's "New Game" highlights it.

Probe defaults are too short for these demos: pass
`--screenshot-timeout-ms 40000 --load-timeout-ms 60000` or the initial
`#btn-run` click times out at 8 s on a 12 MB wasm.

**GOTCHA — `probe.py --click/--move` coordinates are CSS pixels of the
displayed canvas, not the game's internal 640x480 space.** The canvas
renders at 779x585 here (scale ~1.217), so the menu button at internal
(320,176) must be clicked at CSS (389,214). Clicking the internal
coordinate lands short and silently does nothing. (Headless `input.json`
event files are the opposite — those ARE in internal coordinates.)

## 6. Remaining work

1. **RESOLVED 2026-07-18 (RW-demo perf session, Windows rig):** both
   **rwf and rwic reached PlayState in-browser** via real press-release
   clicks (Playwright at human speed on the real-GPU rig) — in-game HUD,
   timer, inventory all live; ~60 s of gameplay each with no OOM and no
   fatal errors. Pre-GC-fix frame cost: rwic ~27 ms/frame (~28 fps,
   basically fine), rwf ~51 ms (~18 fps); rwp ~160 ms (~6 fps) and rwk
   ~446 ms (~2 fps) were the bad ones — root cause was the GC gross-byte
   watermark × Flixel quadtree churn, fixed by the adaptive watermark
   (commit fd5931661; see SWFRecompDocs/prompts/avm2-gc-collector-cost.md
   for the measured cost model + tier-2 handoff). Raw distributions:
   /mnt/c/playwright/rw_perf_2026-07-18/*.json.
   Original text (context for the heap worry, now largely cleared):
   the heap
   question below is still open, not cleared. `probe.py`'s synthetic click
   correctly hovers the button but never fires it: Flixel's `FlxButton`
   needs the press and the release sampled on separate ticks, and
   Playwright's down/up land in a single event-loop turn. A real human
   click works (RWK-3 verified the live-mouse path), so this is probe
   tooling, not a demo defect — but it means **no browser gameplay claim
   should be made for these two until someone clicks through by hand or the
   probe grows a click-hold duration.**
   The heap risk it would settle: against the 1984 MB wasm arena, Ice Cream
   peaks at 1770 MB natively and Fishy at 1577 MB, versus RWK's 1409 MB
   which already OOMs in-browser after ~6-7 min. Menus are demonstrably
   fine; PlayState is the suspected cliff. Collectable strings / eden arena
   is the real fix and is runtime-wide, not sequel-scoped.
2. Gameplay-parity spot-checks (stage 4 was menu-only here) via the
   `RUFFLE_INPUT_FILE` input-scripted oracle (RWK-2's local exporter patch).
   Gotcha carried over: Flixel calls `FlxG.keys.reset()` on every state
   switch, so keys pressed during a fade are wiped — press only once the
   target state is live.
3. Readiness note to `~/CC/Archipelago-CC/NewDocs/plans/
   seedling-swfrecomp-task-split.md` now that all three demos are live
   (per the prompt's out-of-scope section — injection configs are their
   side's work).

## 6b. Perf update 2026-07-19 — base-compute lever 1 landed (helps all RW games)

The RWK base-compute session (`SWFRecompDocs/prompts/
avm2-rwk-base-compute-profile.md`, log `tools/divergence/perf/
RWK_AB_STATUS.md`) landed the findpropstrict scope-hit inline cache
(`8caf10e4e`): RWK gameplay 219→165 ms p50 on the rig (1.33x), native 1.54x.
The lever is Flixel-shape-generic (unqualified member reads + own-class
statics), so rwp/rwf/rwic and the sequels inherit it for free — the rig
per-game fps scoreboard should be re-measured whenever the next lever
lands. Remaining lever map in RWK_AB_STATUS.md; Ruffle gameplay anchor
6.4 ms/frame.

## 5. Rules carried over (unchanged)

- The game is never the oracle — runtime fixes graded by a regression test.
- AVM2 work stays in `src/avm2/` + `SWFRecomp/src/abc/`; never touch AVM1.
- Full pipeline on runtime change: BOTH CI modes, zero pass→fail.
- Demo-only commits skip CI (`ci-only-when-observable`).
