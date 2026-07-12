# Session prompt — AVM2 Stage 8: input harness + input bridge

> **COMPLETE 2026-07-12 (commit `ee2107860`).** ~42/71 input.json candidates
> pass (was 0). Harness injection wired to the AVM2 build; flash.events
> Mouse/Keyboard/Focus/TextEvent + mouse hit-test/dispatch + drag + focus
> manager + tab order + TextField editing landed. 29 misses triaged in
> `avm2/_investigation/STAGE8_CANDIDATES.txt` (masks, Loader, SimpleButton
> highlight geometry, IME, HTML link events, real-shape hit-test). Details in
> the `avm2-stage8-input` memory + `CURRENT_STATUS.md`. Next: Stage 9 (minimal
> AVM2 render path) — draft below.


You are implementing **Stage 8** of the AVM2 Seedling-directed plan
(`SWFRecompDocs/plans/avm2-seedling-plan.md`): the interactive-test input
harness and the AVM2 input→event bridge. This unlocks the **74 input.json
tests** (keyboard/mouse/focus), including the 16 text-family tests that were
excluded from Stage 6, and is the bridge design for real platform input in
native/browser builds later.

Read the plan first, then `avm2/_investigation/CURRENT_STATUS.md`, then the
memories `avm2-stage7-bitmapdata` / `avm2-stage6-text` / `avm2_stage5_display`
(display tick + event dispatch), then skim the seams below.

Stage 7 landed at (see `git log` for the Stage-7 commit). CI baseline: **see
CURRENT_STATUS.md** (Stage-7 no-graphics run). Zero regressions expected.

## Goal

Grade by the input.json test family. **Generate the candidate list at session
start** (there is no pre-baked file yet):
```bash
# failing, non-ignored avm2 tests that ship an input.json
find ruffle-tests/tests/swfs/avm2 -name input.json -printf '%h\n' \
  | sed 's#.*/##' | sort > /tmp/avm2_input_tests.txt
```
Cross-reference against the latest CI `results.json` to keep only the ones
currently failing, and drop upstream-ignored ones. Write the survivors to
`avm2/_investigation/STAGE8_CANDIDATES.txt` with a header (Stage-3..7
convention). Exit: **a strong majority of the input.json family passing
(propose a number from the candidate count, e.g. >=50 of ~74)**; every miss
triaged; zero pass->fail regressions anywhere.

## Code seams (what exists today)

- `ruffle-tests/verify_output.py` — **`preprocess_input_json` (line ~445)
  already parses Ruffle's input.json** into a line-based event stream for the
  AVM1 path (MouseDown/KeyDown/Wait, scale_factor handling; the Numpad quirk
  at line ~70). Check whether the AVM2 build path (`is_avm2`, ~line 1654)
  wires the same injected-event file into the generated `main.c` — if not,
  extend it. Event kinds to cover (Ruffle
  `tests/framework/src/runner/automation.rs` AutomatedEvent → PlayerEvent):
  MouseMove/MouseDown/MouseUp, KeyDown/KeyUp, TextInput{codepoint}, Wait,
  SetClipboardText. `Wait` advances one frame/tick; the harness injects the
  events scheduled before each Wait, then ticks.
- `SWFModernRuntime/src/avm2/avm2_events.c` — the real flash.events dispatch
  (3-phase capture/target/bubble, EventDispatcher, the FP broadcast registry).
  KeyboardEvent/MouseEvent/FocusEvent are new Event SUBCLASSES: add their
  classes (with the extra getters: keyCode/charCode/ctrlKey/shiftKey/keyLocation
  for KeyboardEvent; localX/localY/stageX/stageY/buttonDown/delta/relatedObject
  for MouseEvent; relatedObject/shiftKey/keyCode for FocusEvent) and construct
  + dispatch them from the injected input.
- `SWFModernRuntime/src/avm2/avm2_display.c` — `runSWF_avm2` drives the 5-phase
  tick; `ctx->stage` + real `stage.focus` tracking exist (Stage 6). Mouse
  events hit-test the display tree to find the target (mouseEnabled/
  mouseChildren gating — Stage-5 flags are on the display ext); keyboard events
  go to stage.focus (or the stage). Focus changes (Tab / setFocus) fire
  FocusEvent and update stage.focus. The tick loop must drain injected input at
  the right phase (Ruffle processes input at frame boundaries).
- `flash.ui.Keyboard` / `flash.ui.Mouse` constant classes (key codes:
  Keyboard.TAB=9, ENTER=13, SPACE=32, arrows 37-40, A-Z, etc.; Mouse.hide/show
  no-ops) — new builtin classes. Key-name → keyCode mapping mirrors Ruffle's
  `web_to_ruffle_key_code` / the KeyCode enum.
- TextField editing (the 16 text-family tests): typed TextInput/KeyDown edits
  the focused TextField's text/caret/selection — the Stage-6 EditText engine
  (`avm2_text.c`) has the text store + selection index tracking; wire keystroke
  handling (insert/backspace/arrows/selection) into it.

## Suggested tranche order

1. **Harness**: extend verify_output's input.json injection to the AVM2 build
   (reuse preprocess_input_json; feed events into the generated main loop with
   Wait=tick). Prove one simple mouse or key test runs end-to-end.
2. **Constants + event classes**: Keyboard/Mouse, KeyboardEvent/MouseEvent/
   FocusEvent classes + the key-name→keyCode table.
3. **Mouse**: hit-test target resolution, mouseDown/Up/Move/click/rollOver/
   rollOut dispatch with mouseEnabled/mouseChildren gating; buttonMode/
   useHandCursor where traced.
4. **Keyboard + focus**: keyDown/keyUp to stage.focus; Tab focus traversal
   (tabEnabled/tabIndex/tabChildren), setFocus/FocusEvent.
5. **Text editing**: the 16 text-family tests over the Stage-6 EditText engine.
6. Triage the misses; refresh STAGE8_CANDIDATES.txt; record the CI baseline.

## Constraints & conventions (unchanged)

- Trunk-based; commit directly to `master`; autonomous commit/push/CI
  authorized (CLAUDE.md). Standard trailer. Full pipeline per
  `.claude/pipeline-handoff.md` at the end (no-graphics mode); confirm zero
  pass->fail across ALL suites and wasm-link-smoke green.
- Conflict boundary: own `SWFRecomp/src/abc/`, `SWFModernRuntime/{src,include}/
  avm2/`, `RecompiledABC/`, and the input-harness parts of verify_output.py.
- Do NOT run the full avm2 suite locally. Single tests:
  `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`.
- Honest-failure property everywhere: unimplemented paths abort with a named
  message, never silently mis-execute.

## Gotchas carried from earlier stages

- REBUILD the recompiler after any SWFRecomp change (`cd SWFRecomp/build &&
  make -j8`); verify_output only rebuilds the runtime side.
- Debug loop: `python3 ruffle-tests/build_test_debug.py --test=NAME
  --tests-dir=...` builds a persistent binary; verify_output HIDES stderr, so
  uncaught-error messages (1065 missing class etc.) are only visible on the
  debug binary's stderr. Crashes that print one empty line = an uncaught 1065
  for a class touched at script init — stub constructible classes first.
- vtable accessor OVERRIDES must replace in place (`add_getset` in
  avm2_display.c). Builtin accessor stack frames read "get x"/"set x".
- Broadcast lists snapshot length before iterating (avm2_events.c); mouse/key
  listeners registered during dispatch wait for the next event.
- Expected outputs embed FP's exact float formatting — use avm2_format_number;
  check test.toml `[approximations]` before chasing 1-ulp diffs.

## End-of-session bookkeeping

- Stage-8 landing note in `avm2-seedling-plan.md` §2.
- Update `avm2/_investigation/CURRENT_STATUS.md` (new CI baseline, what landed,
  misses triaged).
- New `avm2-stage8-input` memory (harness format + input-dispatch gotchas);
  update `seedling-avm2-readiness` progress.
- If partial, refresh THIS prompt with precise "resume here" state; if complete,
  mark it COMPLETE at the top and draft the Stage-9 prompt (minimal AVM2 render
  path — next per the Seedling plan; remember the Stage-7 asset-table
  compression finding).
