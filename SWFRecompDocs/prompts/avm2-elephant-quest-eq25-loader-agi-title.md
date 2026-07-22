# Session prompt — Elephant Quest EQ-2.5: clear the `new Loader()` #1065 wall → reach the intro/title

**Objective:** advance EQ's native boot from its current ceiling — **frame3
`new Shell(); shell.init()`, aborting at `new Loader()` #1065 inside `agi.init`
BEFORE `startIntro()`** — to the **intro → title (MainMenu)** by adding a minimal
`flash.display.Loader` stub (and, as far as the title needs it, the `agi` no-op
shell). This is the direct follow-on to EQ-2 (the Play click now routes and boot
reaches frame3; commit `8a39a6797`). It is **trace/tree-gradeable and independent
of rendering** — the render track (gap #10) is complete.

**Read first (source of truth — confirm, don't trust; grep symbols, lines shift):**
1. `SWFRecompDocs/plans/avm2-elephant-quest.md` — **§ "Gap 3"** (Loader + agi,
   the current wall, UPDATED for EQ-2.5) + **§ "Gap 9"** (EQ-2, RESOLVED) + §7
   stage list (EQ-2 done, EQ-2.5 next).
2. `[[avm2-elephant-quest-bringup]]` — EQ-2 RESULT (the SimpleButton hit-test fix,
   `AVM2_DUMP_TREE` tooling, the three-unknowns method) + the native build recipe.
3. `ruffle-tests/_eq_tas/{README.md,eq_drive.py,play_click_events.txt}` — the
   committed native drive: recompile / build (`-O0` no-graphics, one-file-at-a-time
   under `ulimit`, monitored) / run with `AVM2_DUMP_TREE=1`; the confirmed Play
   click. **After a runtime change, rebuild here and re-run the Play click.**
4. `~/CC/jpexs/output/elephantquest/scripts/{Shell.as,AGIStuff.as}` +
   `ElephantQuest_fla/MainTimeline.as` — the boot chain (grounded below).

## Bake in — don't re-derive (grounded 2026-07-22; confirm — the EQ-0 lesson)

- **The exact wall (confirmed).** `startIt → play() → frame3 `new Shell();
  shell.init()``. `Shell.init` (`Shell.as`): `Vault.init(); Key.initialize;
  addChild(this.agi); this.agi.init(); this.startIntro();` — where `this.agi =
  new AGIStuff()`. `AGIStuff.init → initAGI()` (`AGIStuff.as:179`):
  `Security.allowDomain/allowInsecureDomain` (both **already stubbed**,
  `avm2_globals.c:1387`), then **`this.loader = new Loader()`** (ctor,
  `AGIStuff.as:56`) → `loader.contentLoaderInfo.addEventListener(COMPLETE,
  loadComplete)` → `loader.load(urlRequest)`. **`flash.display.Loader` is the ONLY
  missing class** — deferred at `avm2_display.c:3136`; `URLRequest`/`URLLoader`
  already exist (`avm2_globals.c:1610/1646`). So `new Loader()` throws **#1065
  "Loader is not defined"**, unwinding `Shell.init` **before `startIntro()`** → no
  intro, no title. Empirically confirmed (EQ-2): the Play click reaches frame3 then
  emits `#1065 Loader` (+ a downstream `#1009 agButton`).
- **The Loader stub shape (primary deliverable).** `new Loader()` non-throwing; a
  `contentLoaderInfo` getter returning an **EventDispatcher** (so
  `addEventListener(COMPLETE, …)` is a real no-op registration); `load(req)` a
  no-op (the `COMPLETE` never fires → `AGIStuff.agi` stays undefined, which only
  bites later at New Game — see below, not on the Play→title path). This alone
  should let `Shell.init` proceed to `startIntro()` → `new Intro(); addChild(intro);
  Vault.playSong("BossBattle")` → the menu chain. **`flash.display.Loader` is a
  genuinely reusable capability** (any game loading a secondary SWF / API shim).
  Do **not** implement real runtime SWF loading.
- **`agi` no-op shell (only as far as the title needs it).** `AGIStuff.agi` (the
  inner field) is set in `loadComplete` = `param1.currentTarget.content`
  (`AGIStuff.as:278`) — the loaded AGI.swf's content. Most `agi.*` uses are
  `if(this.agi)`-guarded; the **unguarded** ones bite only at **New Game**
  (`hideAGILogin → this.agi.hideLoginStatus()`, `AGIStuff.as:62`). Method surface
  if you go there: `hideLoginStatus/showLoginStatus/initAGUI/retrieveUserData/
  submitUserData/showScoreboardSubmit/showScoreboardList/showGameShareList/
  showGameShareNavi`. Cleanest: have the Loader stub dispatch a **synthetic
  `COMPLETE`** whose `content` is a no-op MovieClip-like shell (so `loadComplete`
  runs and `agi` becomes that shell). **Confirm the intro/title path does NOT need
  `agi` first** (it should be guarded) before building the shell — it may be pure
  EQ-2.5b / New-Game scope.
- **Native EQ build recipe (unchanged, monitored).** `ruffle-tests/_eq_tas/
  eq_drive.py`: `recompile` (ulimit 4GB inside, ~15s) → `ulimit -v 8388608; …
  build` (`-O0` no-graphics, one-file-at-a-time; peak ~3.3 GB; cold ~4 min,
  ccache-warm ~90s) → `AVM2_DUMP_TREE=1 … run play_click_events.txt 25`. **If the
  build threatens OOM, STOP and record sizing — do NOT re-crash WSL** (`-O0` alone
  is safe; the `-O2`+concurrency path is what crashed).

## The unknowns — RESOLVE FIRST (confirm, don't theorize — the EQ-0 lesson)

1. **Does the Loader stub actually clear the wall?** After adding it, rebuild and
   re-run the Play click: `#1065 Loader` should be gone and the tree/trace should
   show `Shell.init` proceeding to `startIntro()`. Instrument with the tree dump
   (does an `Intro` child appear under root/Shell?) — silence scores PASS vs empty
   ([[avm2-localconnection-silent-blank-stage]]).
2. **What does `new Intro()` / the menu chain hit next?** `Intro` is an obfuscated
   timeline class (`betz` `§§push` junk — read the ABC, not the `.as`). Drive
   past the Loader stub with the tree dump and **catalog whatever walls appear**
   (Intro timeline construction, `Vault.playSong` audio, `MainMenu`). Rank cheap →
   expensive; fix or stub the thin tail, exactly like EQ-1's `#1065 ContextMenuItem`.
3. **Is `agi` on the Play→title path at all?** Grep the intro→`startMenu`→
   `MainMenu` chain for **unguarded** `agi.*`. If none, the `agi` shell is pure
   EQ-2.5b (New Game) and the title lands with just the Loader stub. If the menu
   reads `agi`, build the synthetic-COMPLETE no-op shell.

## Legs

1. **Loader stub + rebuild.** Add a minimal `flash.display.Loader`
   (ctor / `contentLoaderInfo` EventDispatcher / `load` no-op; optionally
   `content` + synthetic `COMPLETE`). Rebuild EQ (`_eq_tas` recipe, monitored),
   re-run the Play click, confirm unknown #1.
2. **Drive to the title, catalog + clear the tail.** Extend the tick count, drive
   Play → intro → title; fix/stub each wall (unknown #2). Frame/tree-prove the
   title (an `Intro`/`MainMenu` child under root, or its traces).
3. **Grade (trace/tree-first).** The title (MainMenu) is reachable: `startIntro`/
   `Intro`/`MainMenu` traces or the tree shows the menu. Optional Ruffle front-half
   oracle via `RUFFLE_LOCAL_FETCH_DIR` (served AGI.swf) + `RUFFLE_INPUT_FILE`
   (same Play click) — valid boot→menu→…→first world-map frame
   ([[avm2-rwk2-text-gameplay]], [[ruffle-oracle-nullnav-perf-watchdog]]).

## Scope & next gate

- **Scope EQ-2.5 to Play → intro/title (MainMenu).** The **New Game** click is the
  next step (agi no-op shell for `hideAGILogin` #1010 → story → `init2()`
  world-map build). Pull New Game in **only if the title lands with time to spare**;
  otherwise it is **EQ-3** (`avm2-elephant-quest.md` §7 — the heavy synchronous
  DOOR-build, `getDefinitionByName`, the beat-Ruffle moment).

## Guardrails (binding)

- **OOM discipline:** the EQ build is THE heavy compile. Use the `_eq_tas` recipe
  (one-file-at-a-time, `ulimit -v 8388608`, monitor); if it threatens OOM, stop and
  record sizing. **Never run full suites locally** — single tests only; suites via CI.
- **Grounded:** confirm each wall via trace/tree dumps before stubbing; grep symbols
  (lines shift). Frame dumps / traces over silence.
- **Any runtime change** (the `Loader` stub, an `agi` shell, any wall fix) → a
  `regression/` test (mxmlc → `regression/`, [[custom-tests-live-in-regression-suite]];
  e.g. `new Loader()` + `contentLoaderInfo.addEventListener` + `load()` → asserts no
  #1065, and if synthetic-COMPLETE lands, the handler fires) + ship via
  `.claude/pipeline-handoff.md` (autonomous commit/push/CI authorized). This leg is
  trace-gradeable → **no-graphics** CI unless a render path changes. Commit to
  `master`, stage by name, standard trailer.
- **Deliverables:** update `avm2-elephant-quest.md` (gap #3 → progressed; §7 EQ-2.5
  status) + `[[avm2-elephant-quest-bringup]]`; document the `flash.display.Loader`
  stub as a reusable capability (+ its regression test).
