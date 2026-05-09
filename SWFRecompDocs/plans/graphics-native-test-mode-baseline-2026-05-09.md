# Graphics-Native Test Mode — Smoke Baseline (2026-05-09)

Baseline snapshot for the 9 representative AVM1 tests selected for Phase 1
validation. Captured before any code changes for the new `--mode=graphics`
mode. NO_GRAPHICS column comes from the CI run on commit `b1237cc26e` (run
ID 25611618054). `--headless` column comes from local re-runs on the same
commit, after a 3-line fix to `swf_headless.c` (see "Headless link fix"
below) — the previous state of that file failed to link due to drift.

## Smoke set

Chosen for representative coverage of: arithmetic, SetTarget semantics,
clip events / sprite init, EditText, buttons, goto-rewind display-list
preservation, registerClass / OOP, MovieClip unload semantics, and
image-comparison rendering.

| Test | NO_GRAPHICS | `--mode=graphics-headless-legacy` (post-fix) | `--mode=graphics` (Phase 1 stubs) | Notes |
|---|---|---|---|---|
| `add` | pass | pass | **pass** | trivial trace, sanity check |
| `tell_target_invalid` | pass | pass | fail | output_mismatch — failed-SetTarget semantics |
| `clip_events` | pass | pass | fail | output_mismatch on frame 1 |
| `edittext_default_format` | pass | pass | fail | output_mismatch — text format read fails |
| `button_key_events` | pass | pass | fail | output_mismatch |
| `goto_rewind3` | pass | pass | fail | output_mismatch on gotoAndPlay |
| `register_and_init_order` | pass | **FAIL** | fail | output_mismatch — fails in both headless and graphics-native (shared-code bug) |
| `unload` | pass | pass | fail | output_mismatch — clip4/clip5 references |
| `bitmap_data_colortransform` | pass | pass | **pass** | image_comparison; pure renderer path |

**Single regression: `register_and_init_order`.** This is the test to
watch when bisecting Phase 2 failures. If `--mode=graphics` *also* fails
this test, the bug is in shared code (action.c / tag.c / registered_class.c).
If `--mode=graphics` *passes* it, the bug is specifically in
`swf_headless.c`'s frame loop — and since that file is slated for Phase 3
deletion, the bug is moot.

## Headless link fix

Before this baseline could be captured, `--headless` had to be repaired.
Three globals were defined in `swf_core.c` (and in `graphics_stubs.c` for
the wasm `--graphics` path) but never mirrored into `swf_headless.c`:

| Symbol | Used by |
|---|---|
| `g_force_quit` | `action.c` (2 sites) |
| `g_natural_wrap_cleanup_pending` | `action_queue.c` (4 sites), `tag.c` (2 sites) |
| `g_goto_inlined_in_caller_frame` | `swf_headless.c:985` (its own catch-up) |

Fix: 3 lines added near the existing global block in `swf_headless.c`,
initialized to 0. CI does not run `--headless` (only the result-file paths
are referenced in the workflow), so this had been latent for a while —
which corroborates the planning doc's case for Phase 3 retirement of
`HEADLESS_GRAPHICS` / `swf_headless.c`.

## Pass-rate context

For comparison vs the prior local `--headless` baseline:

| Date | Suite | Pass / Total | Pass rate |
|---|---|---|---|
| 2026-03-18 | avm1 (full suite) | 468 / 621 | 75.4% |
| 2026-05-09 | avm1 (smoke, 9 tests) | 8 / 9 | 88.9% |
| 2026-05-09 | avm1 (full NO_GRAPHICS, CI) | 605 / 648 | 93.4% |

Many of the 2026-03-18 regressions were `tagDefineText` signature drift
("too few arguments to function 'tagDefineText'") in EditText tests. The
recent un-gating commits (`af09e11d`, `7ef76589`, `73164afc`) appear to
have closed those gaps; the smoke set's two former-regressions
(`edittext_default_format`, `button_key_events`) both pass now.

## Phase 1 results (2026-05-09)

`--mode=graphics` wired up and run on the smoke set. **2/9 pass** (`add`,
`bitmap_data_colortransform`). The 7 failures are all `output_mismatch` —
none are compile-fails or timeouts, which means the runtime is functioning
end-to-end. The remaining gap is semantic.

Bisection signal vs `--mode=graphics-headless-legacy`:

- `register_and_init_order`: fails in both modes → **shared-code bug**
  (likely the no-op `ng_queue_placement_clip_events` Phase 1 stub means
  attachMovie/sprite-placement clip events don't fire, breaking
  registerClass init ordering).
- `tell_target_invalid`, `clip_events`, `edittext_default_format`,
  `button_key_events`, `goto_rewind3`, `unload`: pass in headless, fail in
  graphics-native → bug specifically in `swf.c`'s frame loop or in the
  Phase 1 stubs in `graphics_stubs.c`. These are the Phase 2 backlog.

Most likely root causes from the Phase 1 stub set:

| Stub | Likely test impact |
|---|---|
| `exec_sprite_frame` (no context-switch) | `tell_target_invalid`, `clip_events`, sprite-script tests |
| `ng_queue_placement_clip_events` (no-op) | `clip_events`, `register_and_init_order` |
| `process_sprite_needs_init_public` (no-op) | sprite init tests |
| `g_active_transform_data = NULL` | nothing in single-SWF tests |
| `swf.c` lacks goto catch-up | `goto_rewind3`, `tell_target_invalid` |
| `swf.c` lacks pending-removal finalize | `unload` |
