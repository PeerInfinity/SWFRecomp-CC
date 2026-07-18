# Session prompt — Robot Wants sequels bring-up (Puppy, Fishy, Ice Cream)

Status: **STAGES 1–3 DONE FOR ALL THREE GAMES (2026-07-18).** Census clean
(0 verify_fails, 0 new ops, no v10 surface); all three boot to their title
menus and are playable headless with zero uncaught errors, on **one runtime
fix total** — `flash.net.LocalConnection` (Fishy/Ice Cream gate boot on
`new LocalConnection().domain`; the class was simply missing, and the
"site-lock" turned out to be an anti-local-copy stub with an EMPTY
whitelist, so nothing needed spoofing). Remaining per game: **stage 4
(Ruffle render parity) and stage 5 (browser demo)**. Full detail, including
two stage-5 blockers (SWF_URL override; Ice Cream's 1770 MB heap peak vs the
1984 MB wasm arena), is in `SWFRecompDocs/plans/avm2-robot-wants-sequels.md`
— read that first, it is now the source of truth.

You are bringing up the **three Robot Wants sequels** on the AVM2 runtime and
shipping each as a browser demo, following the proven RWK playbook: census →
headless bring-up → render parity vs a Ruffle oracle → browser demo page.
Same engine family (AS3/Flixel, `xplor.` package, BitmapData-blit rendering),
so most of the runtime surface is already exercised by RWK — expect
sponsor-shell friction, not engine cliffs.

Read first: `SWFRecompDocs/plans/avm2-robot-wants-kitty.md` (THE template —
census method §1, friction ranking §2, stage pattern §3), memories
`avm2-rwk1-robotkitty-bringup` / `avm2-rwk2-text-gameplay` /
`avm2-rwk3-browser-demo`, and
`SWFRecompDocs/guides/wasm-game-debugging-session-guide.md`
(divergence-harness-first). Cross-game context (read-only):
`~/CC/Archipelago-CC/NewDocs/plans/robot-wants-archipelago.md` — the four-game
multiworld design with per-game powerup/world stats.

## The games (work in this order)

| Game | SWF (in `~/CC/newgrounds/`) | SWF ver | World | Notes |
|---|---|---|---|---|
| Robot Wants Puppy | `536088_robotpuppy_max.swf` (1.8M) | 9 (AS3) | 83×118 | closest to RWK; JPEXS decompile has MANGLED names (§'9§ etc.) — read bytecode/behavior, not identifiers |
| Robot Wants Fishy | `546416_robotfishy_locallock.swf` (2.5M) | 10 | 130×112 | **`locallock` = expect a site-lock check** (see below); swim mechanics |
| Robot Wants Ice Cream | `549120_icecream_maxgames.swf` (2.0M) | 11 | 130×120 | largest powerup set (11) |

Puppy first: same SWF version as RWK, no lock, smallest world. Fishy second
(the site-lock stance gets decided once, on the game that forces it). Ice
Cream third.

## Per-game pipeline (the RWK stages, compressed)

1. **Census** (cheap, do all three up front in one pass): `--check-abc`
   (verify_fails must be 0), `abc_op_census.py` vs the implemented-op set
   (Fishy/IceCream are our first v10+ AVM2 games — flag any new ops), tag
   inventory (bitmaps/sounds/binaries/fonts), quick JPEXS/decompile skim for
   the sponsor boot chain and `flash.*` imports outside RWK's set.
2. **Headless bring-up**: recompile, run native, clear the boot/sponsor error
   chain (GameShedAchievement/MD5 URLLoader POSTs, sponsor shells,
   `navigateToURL` — all must fail/timeout gracefully offline, the RWK-1 /
   Seedling-s1 class). Gate: menu reachable, zero uncaught errors.
3. **Gameplay probe**: scripted inputs (the `RUFFLE_INPUT_FILE` oracle recipe
   from RWK-2) — start a game, move/jump/collect, zero uncaught errors over a
   few hundred ticks. Memory sanity: `AVM2_HEAP_STATS` per-tick delta should
   be RWK-like (~1 KB/tick class), live census sawtooth peaks flat.
4. **Render parity spot-check** vs a Ruffle export of the same SWF,
   state-aligned NOT tick-aligned (Ruffle AVM2 `getTimer` is WALL-CLOCK —
   the RWK-1 gotcha; offset-scan alignment). Target: RWK-2-class MAD with
   explainable artifact diffs only.
5. **Browser demo**: `deploy_wasm_avm2.sh` with DEMO_SWF/DEMO_DESC, dirs
   `docs2/examples/avm2/rwp/`, `rwf/`, `rwic/` (matching the `rwk` naming),
   catalog entries. Verify live keys/mouse/audio like RWK-3 (WSL headed
   Chrome renders this family fine — functional checks only; any perf number
   goes through the Windows rig per CLAUDE.md).

## Known friction, ranked (from the RWK experience + census deltas)

1. **Sponsor boot chains** — three different sponsors (Max Games ×2,
   locallock build, GameShed achievements). Same failure class RWK-1 cleared;
   budget most of the first session here.
2. **Site-lock (Fishy, possibly Ice Cream)** — if the game gates on
   `LoaderInfo.url`, the runtime already has a URL-spoof mechanism
   (`GAME_SWF_URL`, used for Seedling's NG preloader domain gate — verify
   current name/behavior in the runtime before relying on it). Stance:
   prefer the env-gated spoof; document what the lock checks in the session
   memory. Do NOT patch the SWF.
3. **New Flixel surface** — sequels likely run later Flixel versions than
   RWK's. Watch FlxTilemap auto-tile variants, water/swim rendering (Fishy),
   emitters. Same BitmapData model though — expect paths, not cliffs.
4. **SWF v10/v11 recompiler surface** — first AVM2 games above v9. Any new
   op or tag variant found in census gets triaged before bring-up starts.
5. **FlxSave persistence** — in-process only (no localStorage .sol); fine for
   demos, still a known follow-up, don't fix here.

## Rules carried over (RWK plan §5, unchanged)

- **The game is never the oracle** — every runtime fix is graded by an
  upstream avm2 trace test or a new `ruffle-tests/tests/swfs/regression/`
  test (mxmlc with `-omit-trace-statements=false`, NOT mtasc).
- AVM2 work stays in `src/avm2/` + `SWFRecomp/src/abc/`; never touch AVM1.
- Full pipeline per `.claude/pipeline-handoff.md` whenever runtime/recompiler
  code changes: BOTH CI modes, zero pass→fail. Demo-only commits skip CI
  (`ci-only-when-observable`).
- Commit per milestone (per game is natural); update this doc's Status
  header so a follow-on session resumes cleanly.

## Explicitly OUT of scope

- **AP handoff pages.** No injected SWFs and no `games/*.json` configs exist
  yet for the sequels (checked 2026-07-19: Archipelago-CC has only
  robotkitty + seedling). Injection configs are flash-ap-api/Archipelago-CC
  work (Puppy's mangled names make config-writing THEIR hard problem, not
  ours). When all three demos are up, add a readiness note to the task-split
  doc (`~/CC/Archipelago-CC/NewDocs/plans/seedling-swfrecomp-task-split.md`,
  left UNCOMMITTED there) so their side can schedule injection; the
  `rwk_ap` prompt (`avm2-rwk-ap-handoff.md`) is the reusable recipe once
  injected SWFs exist.
- TAS/completion runs, FlxSave localStorage, Kong variants of any game.

## Budget note (delegation)

Opus-led. The playbook is proven and stages 1/2/3/5 are mechanical for an
engine we already run. Escalate to Fable per-divergence: a v10+ op/verifier
gap, a Flixel rendering path that doesn't reduce to existing bd_draw/
copyPixels semantics, or any fix that touches GC/dispatch invariants. If a
single game turns into a multi-fix debugging arc (RWK-2 class), stop, write
the divergence list to this doc, and let the user decide Fable vs continue.

Finish per `.claude/pipeline-handoff.md`; update the avm2 suite
`CURRENT_STATUS.md`; write a session memory per completed game (census
deltas, sponsor-chain fixes, lock stance, demo path, parity numbers).
