# w2-avm2-stage — wave 2: Stage scale factor, displayState/FullScreenEvent, native stack frame (+3)

Read `BRIEFS_COMMON.md` (incl. wave-2 rules) and `SIBLING_FILE_MAP.md`, then the diagnosis of
record: `w1-trace-display-report.md` §2 L4, L5, L6 (and L8's shared half), §5. Isolated worktree.

## Scope
1. **L4 `avm2/stage_scale_factor` 6/12 → pass:** the harness already passes
   `-DVIEWPORT_SCALE_FACTOR=2.0`; `stage_get_contents_scale_factor` is stubbed to 1 — return the
   real factor. Second half: Ruffle's `Stage::local_to_global_matrix → IDENTITY`. The pixel half of
   this test (1.9M outliers) is w1-gfx-smalls' — say whether your change moves it (render one
   `--mode=graphics --images` A/B).
2. **L5 `avm2/stage_display_state` 0/6 → pass (~40 lines):** `FullScreenEvent` constants
   (`FULL_SCREEN`, `FULL_SCREEN_INTERACTIVE_ACCEPTED`…), a `displayState` setter that applies
   Ruffle's `FullScreen → FullScreenInteractive` rewrite and dispatches `FullScreenEvent` on the
   Stage. `builtin_class_impl` is NOT idempotent — grep the class tables before registering.
3. **L6 `avm2/event_handler_exception` 5/11 → `ruffle_matched` (7/11 vs `output.ruffle.txt`,
   ~3 lines):** the one missing native frame `dispatchEventInternal()` in the uncaught-error stack
   trace. This is known_failure upstream: grade with `--expected-suffix=ruffle`; `pass` is not
   reachable. Do NOT edit `addFrameScript` (L8 is w2-avm2-new-smalls'), but if your stack-frame
   change moves `movieclip_addframescript_error`, report it.

Files: `avm2_display.c` Stage region, `avm2_globals.c` (class/constants), the events dispatch /
uncaught-error trace printer. Siblings own `avm2_display.c`'s MovieClip/addFrameScript, orphan,
Vector3D and flash.ui regions — self-localize.

## Verification
Headline: the 3 tests. Canaries: `avm2/stage_*` passing tests (all), `avm2/*scale*`,
`avm2/event_*`/`avm2/dispatch*`/`avm2/uncaught*`/`avm2/error_*` passing tests (sample 10 —
the stack-trace printer is shared), `avm2/fullscreen*` if any, and the `regression` suite's AVM2
stage/event tests. Byte-identical `--diff` before/after. Run 3 in `--mode=graphics` (the scale
factor is render-adjacent). `-P 2`, compile timeout 2400, `--recompile` on first use.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-stage.patch` + `w2-avm2-stage-report.md`
(NEW files first; ledger; refutations; unclaimed leads). Copy to the main tree if allowed.
Runtime-only → copying `SWFRecomp/build` is valid.
