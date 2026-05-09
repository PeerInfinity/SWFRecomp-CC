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

| Test | NO_GRAPHICS | `--headless` (post-fix) | Notes |
|---|---|---|---|
| `add` | pass | pass | trivial trace, sanity check |
| `tell_target_invalid` | pass | pass | failed-SetTarget semantics |
| `clip_events` | pass | pass | clip_action LOAD / ENTER_FRAME |
| `edittext_default_format` | pass | pass | was a regression in 2026-03-18 baseline; fixed |
| `button_key_events` | pass | pass | was a regression in 2026-03-18 baseline; fixed |
| `goto_rewind3` | pass | pass | backward-goto display-list protection |
| `register_and_init_order` | pass | **FAIL** | output_mismatch starting around line 153 |
| `unload` | pass | pass | pending-removal / depth shift |
| `bitmap_data_colortransform` | pass | pass | image_comparison; renderer path |

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

## Use during Phase 1

After `--mode=graphics` is wired up, re-run the same 9 tests under the new
mode. Expected pass rates:

- 8/9 if `swf.c`'s frame loop has roughly the same semantics as
  `swf_headless.c` for these specific scenarios.
- Lower if the goto/sprite/event handling in `swf.c` is more divergent
  than expected — most likely candidates to fail are `tell_target_invalid`,
  `clip_events`, `goto_rewind3`, `unload` (all exercise display-list
  semantics that `swf.c` may handle differently from `swf_headless.c`).

The single `register_and_init_order` regression in `--headless` is the
diagnostic case described above.
