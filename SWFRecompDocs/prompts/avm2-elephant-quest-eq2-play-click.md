# Session prompt — Elephant Quest EQ-2: drive past the Play-gated preloader (click injection)

**Objective:** advance EQ's native boot past its current autonomous ceiling — the
frame1 **preloader, healthy, awaiting a Play-button CLICK** — by **injecting a mouse
click on `preloader.playB`** so `startIt → play() → frame3 (new Shell(); shell.init())`
runs, reaching the intro/title chain. This is a **drive** gap, **not a bug** (every
`preloader.*` `addEventListener` succeeds, zero #1010). It is **trace-gradeable and
independent of rendering** — the parallel render track (gap #10) is already complete
(shapes T1–T6 + Graphics T4 + native EditText + static DefineText all render).

**Read first (source of truth — confirm, don't trust; grep symbols, lines shift):**
1. `SWFRecompDocs/plans/avm2-elephant-quest.md` — **§ "Gap 9"** (the Play-CLICK gate,
   the current ceiling) + **§6** (next-session sizing). Note §6 is partly stale (it
   predates EQ-0/EQ-1 shipping — gap #1 tolerant-verify and the native build are DONE).
2. `[[avm2-elephant-quest-bringup]]` — EQ-0/EQ-1 RESULT: the native build recipe
   (`-O0` no-graphics, one-file-at-a-time, no OOM, ~300 ticks/~1 s, no watchdog) + the
   `AVM2_CPU_DUMP`/`AVM2_MAX_TICKS`/event-file drive mechanism.
3. `[[avm2-rwk2-text-gameplay]]` + `ruffle-tests/_rwk_tas/{README.md,rwk_drive.py}` —
   the input-scripted native drive + `RUFFLE_INPUT_FILE` Ruffle oracle (the TAS pattern
   to copy; RWK proved this pipeline for **keyboard**).
4. `~/CC/jpexs/output/elephantquest/scripts/ElephantQuest_fla/MainTimeline.as` — the
   preloader logic (grounded below).

## Bake in — don't re-derive (grounded 2026-07-22; confirm — the EQ-0 lesson)

- **The exact gate (`MainTimeline.as`, confirmed).** `addFrameScript(0,frame1,2,frame3)`;
  `frame1()` `stop()`s + calls `preloadIt()` which registers the `preload` ENTER_FRAME
  and adds CLICK listeners to `preloader.{playB,agButton,itemsToBuy}`. `preload` (line
  64): when `bytesLoaded >= bytesTotal` → `removeEventListener(ENTER_FRAME)`,
  `preloader.playB.addEventListener(CLICK, startIt)`, `playB.visible = true`. `startIt`
  (line 147): removes the listeners, **`play()`** → frame3 `new Shell(); shell.init()`.
  So the click must land on **`preloader.playB`** — a clip nested `root → preloader →
  playB` — AFTER the load gate flips it visible.
- **The injection pipeline ALREADY EXISTS (RWK drove keyboard through it).** The native
  binary takes an **events-file arg**; `verify_output.run_binary(build_dir,
  event_file=…)` passes it. Line format (from `preprocess_input_json`,
  `verify_output.py:483`): `WAIT` (one per frame), `MOUSE_MOVE x y`,
  `MOUSE_DOWN_LEFT x y idx`, `MOUSE_UP_LEFT x y`. The AVM2 input parser is
  `avm2_display.c:6782+` (`IN_MOUSE_DOWN`/`IN_MOUSE_UP`/`IN_MOUSE_MOVE`, the
  `MOUSE_DOWN_LEFT ` sscanf at `:6937`); hit-test `point_in_self` (`:7028`) + the
  child walk (`:7077`, `:7107`); MouseEvent CLICK constants + dispatch in
  `avm2_events.c:1343+`. Author the events-file directly (TAS style) **or** an
  `input.json` (`[{"type":"Wait"},…,{"type":"MouseMove","pos":[x,y]},
  {"type":"MouseDown","pos":[x,y],"btn":"Left","index":0},{"type":"MouseUp",…}]`) →
  `preprocess_input_json`. Emit the SAME plan as a Ruffle-test `input.json` for the
  `RUFFLE_INPUT_FILE` oracle (mirror `rwk_drive.compile_ruffle_json`).
- **Native EQ build recipe (EQ-1, no OOM — do NOT rediscover).** `-O0` no-graphics;
  `compile_native` compiles files one-at-a-time so the 209 MB `draws.c` never coexists
  with `abc0_methods.c` (peak ~3.3 GB; **run under `ulimit -v 8388608`**). Persistent
  build via `tools/divergence/run_swfrecomp.py` OR a ~20-line driver calling
  `vo.compile_native(mode="no-graphics")` + `vo.run_binary(event_file=…)` with env
  `AVM2_MAX_TICKS` + (optional) `AVM2_CPU_DUMP=<prefix>`. **If the build threatens OOM,
  STOP and record the sizing — do NOT re-crash WSL** (the `-O2`+concurrency path is what
  crashed; `-O0` alone is safe).

## The three unknowns — RESOLVE FIRST (confirm, don't theorize — the EQ-0 lesson)

1. **Does the load gate flip in a native build?** All EQ content is embedded, so
   `stage.loaderInfo.bytesLoaded`/`bytesTotal` should report equal — but **verify how
   the AVM2 runtime reports loaderInfo bytes** (it may return 0/0 or need N ENTER_FRAME
   ticks). If `playB.visible` never becomes true, that's the first fix (make embedded
   loaderInfo report `bytesLoaded == bytesTotal`). Instrument with a trace or a frame
   dump of the preloader.
2. **`playB` stage coordinates.** The click must hit `playB`'s on-stage bounds =
   `preloader` placement matrix × `playB`'s matrix within the preloader clip. Mine it
   from the recompiled timeline tables (`abc_timeline` place ops for the preloader
   sprite + its `playB` child) or the jpexs FLA, **or** drive Ruffle with a trial click
   and read the coords it accepts. Don't guess — dump the resolved stage bounds.
3. **Does the AVM2 mouse pipeline dispatch `"click"` to a NESTED timeline button?** RWK
   proved keyboard end-to-end; **mouse-down/up → hit-test → `click` dispatch on a
   nested `addEventListener(CLICK)` target is the unproven leg** and is the likely real
   work. Confirm `point_in_self` + the child walk descend into `preloader → playB`, and
   that a down+up pair on the same target dispatches `click` (Ruffle semantics). If it
   doesn't route, that hit-test/dispatch fix IS the deliverable (+ a regression test).

## Legs

1. **Investigation build.** Native `-O0` no-graphics EQ build (EQ-1 recipe, monitored).
   Confirm unknown #1 (load gate) and #2 (playB coords) via trace/`AVM2_CPU_DUMP`.
2. **Inject + route the click.** Author the events-file (`WAIT × N` past the load gate,
   then `MOUSE_MOVE` + `MOUSE_DOWN_LEFT` + `MOUSE_UP_LEFT` at playB coords), run with
   `AVM2_MAX_TICKS`. Confirm `startIt` fires → `play()` → frame3 `Shell.init`. If the
   click doesn't route (unknown #3), fix the AVM2 mouse hit-test / `click` dispatch to a
   nested timeline button — the reusable win — and gate it with a `regression/` test
   (a tiny AS3 nested button + injected click → traces the handler).
3. **Grade (trace-first).** Boot advances past frame1: `Shell.init`/frame3 traces
   appear (was silent at the preloader before). Optional Ruffle front-half oracle via
   `RUFFLE_INPUT_FILE` with the same click (CPU-dump-vs-export MAD up to the title — the
   oracle is valid to the first world-map frame; see `[[ruffle-oracle-nullnav-perf-watchdog]]`).

## Scope & next gate

- **Scope EQ-2 to Play → intro/title.** The **New Game** click hits the unguarded
  `agi.hideAGILogin()` → **#1010** (gap #3) — that needs a synthetic no-op `agi` shell
  and is **EQ-2.5** (`avm2-elephant-quest.md` gap #3; the title menu is reachable
  *without* agi). Don't pull it into this leg unless Play→title lands with time to spare.

## Guardrails (binding)

- **OOM discipline:** the EQ build is THE heavy compile. Use the EQ-1 recipe
  (one-file-at-a-time, `ulimit -v 8388608`, monitor); if it threatens OOM, stop and
  record sizing. **Never run full suites locally** (`.claude/CLAUDE.md`) — single tests
  only; suites via CI.
- **Grounded:** confirm the three unknowns before building the click plan; grep symbols
  (lines shift). Frame dumps / traces over silence (blank/no-op scores PASS vs empty
  output — `[[avm2-localconnection-silent-blank-stage]]`).
- **Any runtime change** (loaderInfo bytes, mouse hit-test, `click` dispatch) → a
  `regression/` test + ship via `.claude/pipeline-handoff.md` (autonomous commit/push/CI
  authorized). This leg is trace-gradeable → **no-graphics** CI unless a render path
  changes. Commit to `master`, stage by name, standard trailer.
- **Deliverables:** update `avm2-elephant-quest.md` (gap #9 → resolved-or-progressed +
  §6 next step), refresh `[[avm2-elephant-quest-bringup]]`; if the click-to-nested-button
  hit-test/dispatch fix lands, document it as a reusable capability (+ its regression
  test) — it unblocks every AVM2 button-driven game, not just EQ.
