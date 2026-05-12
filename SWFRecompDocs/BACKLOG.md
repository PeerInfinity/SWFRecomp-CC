# Backlog

Known issues, deferred work, and bugs noted but not yet exercised by a
failing test. Add an entry when you find something worth coming back
to but not worth fixing right now. Remove it when fixed (or when it
turns out to be irrelevant).

**One line per item.** Subsystem heading + bullet with short title,
file:line if applicable, 1-2 sentences body. Date of entry in
parentheses at the end. Sort within each section by date (newest
first).

## What does NOT belong here

- **Parity gaps between graphics-native and NO_GRAPHICS.** CI already
  produces `_results/results_graphics_diff.md` per suite, which lists
  every test that flipped status. Use those during a session; don't
  mirror them here. (This is why the envisioned
  `_investigation/swf_c_parity_backlog.md` never got built.)
- **Test-output divergences with a documented explanation.** Those go
  in `ACCEPTED_DIFFS.md` / `RUFFLE_VS_FLASH_DIFFERENCES.md` /
  `RUFFLE_COMPAT_TWEAKS.md` / `FLASH_BUGS_REPLICATED.md`.
- **In-flight work.** Use a plan doc under `SWFRecompDocs/plans/` for
  anything you're actively designing/executing on.

## Runtime — frame loop / exit gates

- **Image-capture machinery only in `swf_headless.c`.** Blocks Phase
  3 step 1 of `plans/graphics-native-test-mode-plan.md` (switching
  `run_image_tests.py` to `--mode=graphics`). `swf.c` has no
  capture path; graphics-mode image tests produce no PNG. The
  `-DHEADLESS_RENDER_ENABLED` define already plumbs through
  `verify_output.py` for graphics-mode image tests with
  `[image_comparisons]` (see `verify_output.py:1592`), so the test
  runner needs no changes — the gap is purely runtime-side.

  **Recommended approach:** extract the capture state machine into
  a new shared file `SWFModernRuntime/src/libswf/capture.c` (+
  `include/libswf/capture.h`) used by both `swf_headless.c` and
  `swf.c`. Duplicating in `swf.c` would create a sync-burden until
  Phase 3 step 3 deletes `swf_headless.c`.

  **What to extract** (all currently in `swf_headless.c`,
  self-contained — no entanglement with the frame loop):

  | Symbol | Lines | Public? |
  |---|---|---|
  | `MAX_CAPTURES`, `CaptureType`, `CaptureEntry` | 642-655 | header |
  | `g_captures[]`, `g_capture_count`, `g_capture_output_dir`, `g_has_last_frame_capture`, `g_fscommand_capture_idx`, `g_fscommand_pending` | 657-664, 738 | static to capture.c |
  | `parse_capture_triggers()` | 666-712 | public |
  | `save_capture(CaptureEntry*)` | 714-735 | static |
  | `headless_has_pending_captures()` | 741-747 | public (already extern-used by `tag.c:2654`) |
  | `headless_on_fscommand_capture()` | 753-766 | public (already extern-used by `action.c:27663, 40094`) |
  | `capture_tick_pre_frame(tick_count)` *(new wrapper)* | new — extract logic from `swf_headless.c:904-919` | public |
  | `capture_tick_after_events(tick_count, app_context)` *(new wrapper)* | new — extract logic from `swf_headless.c:1249-1264` | public |
  | `capture_tick_post_frame(tick_count)` *(new wrapper)* | new — extract logic from `swf_headless.c:1267-1281` | public |
  | `capture_save_last_frame()` *(new wrapper)* | new — extract logic from `swf_headless.c:1332-1339` | public |

  The four `capture_tick_*` wrappers exist so the frame loops just
  call one named function each — keeps both consumers simple and
  prevents drift. Rename `headless_*` → `capture_*` in the extracted
  API for consistency; keep legacy aliases if simpler.

  **Five integration points in `swf.c`** (line numbers from
  `6cca03fd`; verify before editing — Phase 2 churn was high):

  1. **`swfStart` prologue** — after `renderer_init` (~line 999), call
     `parse_capture_triggers()` once. Mirrors `swf_headless.c:777`.
  2. **Pre-frame capture request** — top of the `OFFSCREEN_RENDER`
     tick loop, before `frame_funcs[current_frame](app_context)` is
     called (~line 380-540 area, after the natural-wrap-cleanup
     block and before frame-func invocation). Call
     `capture_tick_pre_frame(tick_count)`. Mirrors
     `swf_headless.c:904-919`.
  3. **Post-events re-render** — inside the `#ifdef OFFSCREEN_RENDER`
     block after `input_events_pump_tick` and the goto-catch-up loop,
     before deferred-load processing (~line 720-722). Call
     `capture_tick_after_events(tick_count, app_context)`. Mirrors
     `swf_headless.c:1249-1264`.
  4. **Post-frame save** — same area, right after (3). Call
     `capture_tick_post_frame(tick_count)`. Mirrors
     `swf_headless.c:1267-1281`.
  5. **End-of-loop last_frame save** — after the main tick loop exits
     and before `renderer_free(app_context, context)` (~line 1054).
     Call `capture_save_last_frame()`. Mirrors
     `swf_headless.c:1332-1339`.

  **Two gate widenings outside the frame loop:**

  - `action.c:27661, 40094` — `fscommand("capture")` is gated
    `#ifdef HEADLESS_GRAPHICS`. Widen to
    `#if defined(HEADLESS_GRAPHICS) || defined(OFFSCREEN_RENDER)`.
  - `tag.c:2654` — `headless_has_pending_captures()` call is gated
    `#ifdef HEADLESS_RENDER_ENABLED`. `verify_output.py` already
    sets this for graphics-mode image tests, so the gate likely
    already passes — verify the symbol resolves to the new
    `capture.c` once swf_headless.c's definition is removed (or
    rename to `capture_has_pending()` and update the call site).

  **Subtle: `last_frame` readback semantics.** swf_headless.c relies
  on the readback buffer holding the most-recent rendered frame at
  end-of-loop. `swf.c`'s tick path doesn't call `tagShowFrame`
  directly — rendering is driven by the recompiler-emitted
  `tagShowFrame` at the end of each frame's tag stream
  (`frame_funcs[current_frame]`). After the last `frame_funcs[]`
  invocation, the renderer state should match `swf_headless.c`'s
  post-tagShowFrame state, but worth confirming: if the
  `OFFSCREEN_RENDER` quit-gate exits *before* a final frame_func
  runs, the readback buffer may hold a stale frame. Add a guarded
  `renderer_request_capture(context)` before the final-frame save
  if so, or accept that last_frame captures need at least one
  rendered frame to have occurred.

  **Validation:**
  - Build + smoke-run a single graphics-mode image test
    (`bitmap_data_colortransform`) — expect "image:output PASS".
  - Run all 31 image tests in `--mode=graphics-headless-legacy`,
    confirm no regression vs prior baseline (this should be a
    pure refactor of the legacy path).
  - Run all 31 image tests in `--mode=graphics`, confirm pixel
    parity vs the legacy baseline.
  - Trace-suite CI (no image tests) should be unaffected — verify
    via the standard no-graphics pipeline-handoff.

  Once parity holds across all 31: flip `run_image_tests.py:84`
  from `--headless` to `--mode=graphics` (Phase 3 step 1 unblocks),
  then move CI to option A (Phase 3 step 2), and the 1-month clock
  on swf_headless.c deletion (Phase 3 step 3) starts.
  (2026-05-12)
- **`swf_core.c` root-stopped exit gate ignores long-lived
  subsystems.** `swf_core.c:1433-1454` breaks the loop when
  `is_playing=0` and no playing sprites/timers/enter-frame handlers/
  events/pending-MCL, but does *not* consult `hasActiveNetStreams()`,
  `hasPlayingSounds()`, or `hasClipEnterFrameHandlers()` the way the
  quit-swf gate at `swf_core.c:1056-1065` does. Currently masks bugs
  (early exit silently terminates the subsystem before it can
  produce wrong output) rather than breaking tests; uncovered while
  diagnosing `avm1/netstream_seek_flv` (2026-05-11) — see playbook
  gotcha #15 for the symptom signature.

## Deferred test failures

- **`from_gnash/actionscript.all/case-v6` CI-only flake.** Passes
  locally after follow-up #4's wrap-back undo but CI ends with exit
  code -6 ("output matches"). Same CI-environment category as
  `avm1/native_objects_swf6`. Don't chase locally; needs a separate
  CI-environment investigation. (2026-05-11)
- **`from_gnash/misc-ming.all/place_and_remove_object_insane_test`
  15/19 in graphics-native vs 19/19 NO_GRAPHICS.** Same diff appears
  in `--mode=graphics-headless-legacy`, so the bug is in shared code
  (tag.c or `#ifdef NO_GRAPHICS`-gated tag handling), not swf.c.
  Defer to a tag.c-focused session. (2026-05-11)
