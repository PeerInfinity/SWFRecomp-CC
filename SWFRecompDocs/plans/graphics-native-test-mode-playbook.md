# Graphics-Native Test Mode — Phase 2 Playbook

How to keep increasing the `--mode=graphics` pass rate across the full
Ruffle test suites (~1100 tests across `avm1`, `from_gnash/*`,
`from_shumway`, `from_shumway/avm1`). Focused on the workflow + gotchas
that actually came up while flipping 5 of 9 smoke tests. See
`graphics-native-test-mode-plan.md` for goals and
`graphics-native-test-mode-phase2-results-2026-05-09.md` for what's
already been done.

## Setup: get a full-suite baseline

Before triaging individual failures, get a per-suite pass-rate snapshot
under `--mode=graphics`. Two options:

**Option A — CI (recommended).** The `ruffle-tests.yml` workflow has
`mode` and `single_test` inputs:

- `mode=no-graphics` (default) — existing behavior, unchanged
- `mode=graphics` — runs the new full-graphics-native build
- `mode=graphics-headless-legacy` — runs `swf_headless.c` + offscreen Dawn
- `single_test=NAME` — runs just one test (any mode), auto-uses the
  single-runner job

**One-time prerequisite:** Both graphics modes need a prebuilt Dawn
binary in the GitHub Actions cache. Run the `build-dawn.yml` workflow
once to populate it (~30 minutes). After that, a weekly cron keeps the
cache warm so it doesn't evict. If `ruffle-tests.yml` runs in graphics
mode and the cache is missing, it fails with a clear error pointing at
`gh workflow run build-dawn.yml`.

```bash
# One-time (and after editing scripts/build_dawn.sh, e.g. to bump DAWN_REF):
gh workflow run build-dawn.yml
gh run watch  # ~30 min
```

Trigger:
```bash
gh workflow run ruffle-tests.yml --ref master \
  -f mode=graphics -f categories=avm1 -f parallel=10
# or single test:
gh workflow run ruffle-tests.yml --ref master \
  -f mode=graphics -f single_test=tell_target_invalid
```

**Option B — local full-suite run.** Each test takes ~5–10s (ccache
warm), so a full suite is ~10–30 min, all suites together ~1.5–3 hours.

```bash
python3 ruffle-tests/verify_output.py --mode=graphics
# or for a single suite:
python3 ruffle-tests/verify_output.py --mode=graphics --tests-dir=ruffle-tests/tests/swfs/avm1
```

CLAUDE.md says NOT to run full suites in normal sessions — use CI
unless you specifically need local timing or are iterating without
push access.

## How to find tests to work on

Once you have `_results/results_graphics.json` for a suite, prioritize.
Most-bang-for-buck order:

1. **Tests that pass in NO_GRAPHICS but fail in `--mode=graphics`** —
   these are the parity gaps. Filter by comparing the two JSONs.
2. **Tests with `compile_fail` or `runtime_segfault`** — structural
   blockers, often shared by many other failing tests.
3. **Tests with `output_mismatch` and a high `matching_lines /
   expected_lines` ratio** — close to passing, usually one missing
   structural piece. These are where the smoke set spent its time.
4. **Tests with low matching ratio** — likely need many fixes; defer
   until the easy wins are gone.

Then look for **clusters**: 50 EditText tests failing the same way
usually means one EditText-related fix unlocks all of them. Reading the
diff for two or three tests in the cluster will reveal the shared root
cause.

## The loop (per test)

1. **Diff it.**

   ```bash
   python3 ruffle-tests/verify_output.py --test=NAME --mode=graphics --diff
   ```

   First line of divergence usually points at what's missing.

2. **Bisect via the legacy mode.**

   ```bash
   python3 ruffle-tests/verify_output.py --test=NAME --mode=graphics-headless-legacy --diff
   ```

   - Passes there but fails in graphics-native → bug is in `swf.c`'s
     frame loop or in a recently-widened gate. **Most common case.**
   - Fails in both → shared-code bug in `tag.c` / `action.c` /
     `action_queue.c`. Rarer; investigate with NO_GRAPHICS as control.

3. **Find what's missing.** Three things are usually missing:

   a. **A NO_GRAPHICS-only global** referenced by widened code →
      add definition to `graphics_stubs.c` (always-active group), or to
      `swf.c` if it's frame-loop state.

   b. **A NO_GRAPHICS-only function body** in `tag.c` or `action.c` →
      check if its `#ifdef NO_GRAPHICS` gate still needs widening
      (most are widened, but some call sites or single-statement guards
      remain).

   c. **A call site missing from `swf.c`'s main loop** — this is the
      sneaky one. The frame loop in `swf_core.c` invokes things
      explicitly that the recompiler-emitted `tagShowFrame` doesn't
      cover: `advance_sprite_frames`, `g_enterframe_flush_pending = 1`,
      `actionFinalizePendingRemovals`, `input_events_pump_tick`, etc.
      Each is a one-line call but at the right point in the loop.

4. **Apply the fix, re-baseline locally.** Don't just fix — re-run the
   smoke set (it's fast and catches obvious regressions):

   ```bash
   for t in add tell_target_invalid clip_events edittext_default_format \
            button_key_events goto_rewind3 register_and_init_order \
            unload bitmap_data_colortransform; do
     out=$(python3 ruffle-tests/verify_output.py --test="$t" --mode=graphics --diff 2>&1)
     pass=$(echo "$out" | grep -E "^Pass:" | head -1 | awk '{print $2}')
     fail=$(echo "$out" | grep -E "^Fail:" | head -1 | awk '{print $2}')
     printf "%-35s pass=%s fail=%s\n" "$t" "$pass" "$fail"
   done
   ```

   Plus run the test you were targeting and a handful of others from
   its cluster.

5. **Verify legacy modes unchanged.** After any `tag.c` / `action.c`
   gate change, sanity-check that NO_GRAPHICS and legacy headless
   didn't regress:

   ```bash
   python3 ruffle-tests/verify_output.py --test=NAME --diff                          # NO_GRAPHICS
   python3 ruffle-tests/verify_output.py --test=NAME --mode=graphics-headless-legacy --diff
   ```

   For a structural change (gate widening, new call site), pick 2–3
   tests in the suite and run all three modes.

6. **Commit.** Per-fix commits with a clear "what flipped" line in the
   message. After several fixes, push and let CI run the full suites
   for a real delta.

## Decision framework: widen vs port vs stub

| Situation | Action |
|---|---|
| `swf_core.c` defines a global (`int foo = 0;`), graphics-native references it | Add `int foo = 0;` to `swf.c` if frame-loop state, or to `graphics_stubs.c` (always-active group) if shared state |
| `tag.c` / `action.c` defines a function under `#ifdef NO_GRAPHICS`, graphics-native needs it | Widen the gate to `#if defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` |
| Function body would semantically work in graphics-native (same display-list / globals) | Widen — preferred |
| Function depends on swf_core.c-specific state we don't want to drag in | Port body to `swf.c` (Phase 3 collapses the duplication) |
| `swf_core.c`'s main loop calls function X between frame_func and the next iteration | Add same call to `swf.c`'s main loop at the equivalent point |
| Symbol only needed for tests but not real graphics use | Add stub in `graphics_stubs.c`, document with TODO/Phase 3 note |

## Gotchas (the actual mistakes I made)

1. **`replace_all` rewrites your compatibility shim.** When renaming
   `HEADLESS_GRAPHICS` → `OFFSCREEN_RENDER`, the shim
   `#if defined(HEADLESS_GRAPHICS) && !defined(OFFSCREEN_RENDER)` becomes
   `#if defined(OFFSCREEN_RENDER) && !defined(OFFSCREEN_RENDER)` — always
   false. Fix the shim manually after the bulk rename.

2. **Don't make up `AQ_KIND_*` values.** They're an enum in
   `actionmodern/action_queue.h` (not `1`, `2` etc. — the real values
   are `AQ_KIND_CLIP_INIT = 4`, `AQ_KIND_REGISTER_CTOR = 6`, ...).
   Always `#include <actionmodern/action_queue.h>`.

3. **Drain/dispatch placement matters.** `input_events_pump_tick` must
   run AFTER `frame_func` (so listeners are registered);
   `process_sprite_needs_init` must run BEFORE `advance_sprite_frames`
   (so MCs exist when sprite frame_funcs first run);
   `tagFlushPendingEnterFrame` is called from recompiler code but only
   fires if `g_enterframe_flush_pending = 1` was set BEFORE `frame_func`.
   Get the order wrong and the test compiles + links + runs but
   silently produces wrong output.

4. **Widening surfaces dependency cascades.** Widening a gate around
   function F often surfaces undefined references to G that F calls.
   Widen G's gate too. May cascade 2–3 deep before settling.

5. **Multi-definition errors after widening.** If `graphics_stubs.c`
   was providing a stub of what `tag.c` (now widened) defines, link
   fails. Gate the stub on `#ifndef OFFSCREEN_RENDER` so only wasm
   graphics still sees the stub. Common offenders:
   `g_active_transform_data`, `g_settarget_*`, `actionGetFocusRectInfo`,
   `g_current_sprite_obj`.

6. **Implicit-int conflicts after widening.** If function F is called
   without an explicit declaration at one site (gated out before
   widening) and declared explicitly at another (still gated), the
   first call gets an implicit `int()` decl that conflicts with the
   later real decl. Fix: add `extern <real signature>;` near the first
   call site.

7. **Always clean up debug scaffolding before commit.** I temporarily
   patched `verify_output.py` to dump full link stderr, and
   temporarily added `fprintf(stderr, ...)` to `tag.c` /
   `graphics_stubs.c` to trace function entry. **Both got committed
   accidentally in early iterations.** Revert these before `git add`.

8. **`results_headless.json` and `results_graphics.json` get
   overwritten by per-test runs.** They show up dirty in git status
   after smoke runs; revert / delete before committing other changes:

   ```bash
   git checkout -- ruffle-tests/tests/swfs/avm1/_results/results_headless.json
   rm -f ruffle-tests/tests/swfs/avm1/_results/results_graphics.json
   ```

9. **Loosening loop-exit gates surfaces sprite over-execution.** When
   you make `tagMain`'s loop continue past `quit_swf` (e.g. to let a
   sprite frame_func that lives on a non-zero frame get a chance to
   run), tests that previously passed because the loop exited early
   may now over-execute: sprites with `sprite_is_playing=1` keep
   firing their scripts until `MAX_FRAMES`, producing extra trailing
   trace lines that break expected-output match. Symptom in the diff:
   `lines: matching=N, expected=N` (perfect match) but `actual_lines >
   expected_lines` and `status=output_mismatch`. Cluster from commit
   `ab614b80`: `create_empty_movie_clip`, `form_loader_encoding_1`,
   `issue_2084`, `loadmovie_replace_root`, `textfield_cache_as_bitmap`
   (avm1) plus 2 fuzz tests in `from_shumway` flipped from
   `ruffle_matched` → `output_mismatch`. The right fix is figuring out
   why those sprites should have stopped (often: the `actionStop` call
   from a sprite script is hitting graphics-native's `is_playing = 0`
   fallthrough instead of `ng_stopCurrentSprite()`); the wrong fix is
   tightening the loop-exit gate so the over-execution gets cut off.

10. **`swf.c`'s `next_frame = 0` wrap re-runs frame 0 forever in test
    mode.** `swf.c`'s pre-`f1b087ec` `else if (is_playing) { next_frame
    += 1; if (next_frame >= g_frame_count) next_frame = 0; }` is
    correct for real playback (SWFs loop by default) but wrong in
    test mode: the recompiler already emits its own natural-wrap as
    `manual_next_frame=1; next_frame=0` at end of the last frame,
    paired with `quit_swf=1`. Auto-wrapping on top re-runs
    `frame_funcs[0]` every tick whenever something else keeps the
    loop alive — a playing child sprite, a pending MCL load, a
    pending direct loadMovie, an onEnterFrame handler, etc. Symptom
    in the diff: the actual output is the expected output repeated
    in N cycles, where N = `MAX_FRAMES` divided by the number of
    expected lines (e.g. a 1-frame test that expects 8 trace lines
    produces 6 × 8 = 48 lines at `num_ticks = 6`). Fix: gate the
    wrap on `#ifndef OFFSCREEN_RENDER`. The existing `current_frame
    < g_frame_count` guard at the frame-func call prevents OOB once
    `next_frame` advances past the count. Commit `f1b087ec` unlocked
    the full loadmovie cluster, the cross-version closure cluster
    (`swf5_to_6_cross_call`, `swf6_to_5_cross_call`,
    `register_class_swf6`, `cross_movie_root`, `lock_root`), and 4
    of the 5 sprite-over-execution regressions from `ab614b80` —
    `+51 raw pass` total.

11. **Missing pending-load drain calls cause silent loadMovie
    failures.** `swf.c` historically did not call
    `actionFirePendingDirectLoads`, `actionPromotePendingMCLLoads`, or
    `actionFirePendingLoadInits`, so any test that called `loadMovie`
    / `loadMovieNum` / `MovieClipLoader.loadClip` ran the root frame
    that issued the call but never fired the child's `init+frame0`.
    Symptom: a test that traces something before the load and
    something inside the child's frame_0 produces only the
    pre-load trace lines. Mirrors `swf_core.c` lines ~1282-1345.
    Whenever you add a new pending-load mechanism, make sure to call
    its drain function from both `swf.c` (graphics-native) and
    `swf_core.c` (NO_GRAPHICS) and gate the `tagMain` exit condition
    on the corresponding pending-load count.

12. **`swf.c`'s post-quit drain loop dispatches `onEnterFrame`.**
    `swf.c` ends `tagMain` with a `while (!renderer_poll())` loop
    that calls `set_enterframe_eligible_recursive`,
    `actionDispatchEnterFrameHandlers`,
    `actionDispatchRootVarMapEnterFrame`, and `tagShowFrame`. In
    browser/emscripten mode this is correct — the SWF stays alive
    past its timeline end and keeps firing handlers until the user
    closes the window. In OFFSCREEN_RENDER (test mode) it's wrong:
    `swf_core.c` has no equivalent, and the drain fires up to
    `MAX_FRAMES` extra `onEnterFrame` dispatches after `quit_swf` is
    set. Each call to `actionDispatchEnterFrameHandlers` also marks
    dynamic MCs eligible at the end, so the drain self-perpetuates
    once any dynamic MC has an `onEnterFrame`. Symptom: a single
    expected trace line repeats N times where N ≈ MAX_FRAMES (e.g.
    `create_empty_movie_clip`'s `mc2.onEnterFrame` → 2× "correct!"
    instead of 1×). Fix: gate the post-quit drain loop on
    `#ifndef OFFSCREEN_RENDER`. **But also** add the matching
    `actionMarkDynamicMCsEnterFrameEligible()` call inside the main
    loop (swf_core.c does this at line ~1100, swf.c didn't) —
    otherwise dynamic MCs never get their flag set and skipping the
    drain produces 0× "correct!" instead of 1×. The two changes are
    a pair; commit `0fcfe324` did both together.

13. **`#ifndef NO_GRAPHICS` is wrong for any "wasm-graphics only"
    code path.** This gate evaluates true for *both* wasm-graphics
    (`!NO_GRAPHICS && !OFFSCREEN_RENDER`) AND graphics-native
    (`!NO_GRAPHICS && OFFSCREEN_RENDER`). So a block intended to
    select between "NO_GRAPHICS" and "browser graphics" actually
    routes graphics-native through the browser-graphics arm — often
    the wrong choice, because graphics-native shares semantics with
    NO_GRAPHICS far more than with wasm-graphics. Four real bugs
    from this pattern, two from `be795aae` / `b7f11901` (silent
    behavioral divergence) and two from `e0568fe7` (gated arm is a
    *stub*, silently drops the opcode entirely):

    - **`actionGetVariable`'s display-list-by-name lookup**: the
      `#ifndef NO_GRAPHICS` arm called `findDisplayObjectByName`
      (strcmp, case-sensitive) where the `#else` arm called
      `ng_findDisplayEntryByName` (swf_name_match, case-insensitive
      in SWF<=6) plus a pending_removal MC check. In SWF6, scripts
      that depend on case-insensitive name resolution (`Button.prototype.hasOwnProperty(...)`,
      `clip5._x` after `clip5` enters pending_removal, etc.) silently
      diverged: NO_GRAPHICS passed, graphics-native fell through to
      `_global` instead of finding the instance.

    - **`actionSetTarget`'s display-list-by-name fallback**: same
      strcmp lookup, but the result was stashed on `targeted_sprite`
      — which is only consumed in the `!NO_GRAPHICS && !OFFSCREEN_RENDER`
      arms of `actionStop` / `actionPlay` / `actionGotoFrame`. In
      graphics-native the assignment was a dead write and the
      function returned, swallowing the lookup and preventing the
      downstream `getMovieClipByTarget` + var_map fallback from
      running.

    - **`actionCloneSprite` (opcode 0x24)**: the `#ifndef NO_GRAPHICS`
      arm called `cloneMovieClip(source_name, target_name, depth)` —
      a literal empty-body stub. The `#else` arm had the full real
      implementation using `ng_cloneSprite` / `ng_cloneSpriteFromMC`
      / `child_mc_cache`. Graphics-native silently dropped every
      opcode-form `duplicateMovieClip(target, name, depth)` the
      recompiler emitted. Method-form `mc.duplicateMovieClip(...)`
      worked because it routes through `actionCallMethod`'s
      MOVIECLIP arm directly, bypassing this opcode.

    - **`actionRemoveSprite` (opcode 0x25)**: the `#ifndef NO_GRAPHICS`
      arm was a `#ifdef DEBUG printf(...)`. The `#else` arm had the
      full real implementation (focus clearing, unload-handler
      queue, depth shifting, dynamic_props teardown, var_map
      cleanup). Opcode-form `removeMovieClip(name)` was silently
      dropped in graphics-native.

    **Rule of thumb**: if a `#ifndef NO_GRAPHICS` block touches
    `findDisplayObjectByName`, `targeted_sprite`, or any other symbol
    keyed to wasm-graphics-only state, tighten the gate to
    `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)`. Conversely,
    if a block is generic "do something display-related,"
    `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` is the
    right way to share it between NO_GRAPHICS and graphics-native.

    **Stronger rule**: if the gated arm is a stub (empty function,
    `(void)` casts, `#ifdef DEBUG printf`, or a comment that says
    "would..." / "TODO" / "not yet implemented") and the `#else`
    arm has working code, you're definitely looking at this gotcha.
    `e0568fe7` was two of those in one commit, +19 raw pass.

    Symptom of the bug: NO_GRAPHICS passes, `--mode=graphics-headless-legacy`
    also passes (uses `swf_headless.c`, which is gated as
    `HEADLESS_GRAPHICS` and goes through the NO_GRAPHICS-style arms),
    `--mode=graphics` fails. The bisect via `graphics-headless-legacy`
    workflow in step 2 of the per-test loop is exactly the right tool
    to detect this — when graphics-headless-legacy passes but
    graphics fails, suspect a misgated `#ifndef NO_GRAPHICS`.

    Net **+31 raw pass** from finding and fixing four instances of
    this across two commits (`be795aae` +12, `e0568fe7` +19). Worth
    grepping `grep -n '#ifndef NO_GRAPHICS' SWFModernRuntime/src/actionmodern/action.c`
    when stuck on a graphics-native-only divergence; not every hit
    is a bug, but every hit is worth a 30-second audit. As of
    `e0568fe7`, the remaining bare `#ifndef NO_GRAPHICS` hits in
    `action.c` are all audited-clean: declarations of
    `targeted_sprite` / `findDisplayObjectByName`, harmless dead
    writes (`targeted_sprite = NULL` resets), or thin pass-through
    calls whose underlying symbol exists in both modes (e.g.
    `actionStopSounds` → `tagStopAllSounds`, defined in both
    `audio.c` and `tag_stubs.c`). Audit the next session's hits
    fresh — code shifts.

14. **`swf.c`'s main loop is structurally a subset of `swf_core.c`'s.**
    `swf.c` was originally written as the browser frame loop —
    `swf_core.c`'s test-mode infrastructure (goto catch-up,
    pending-load drains, dynamic-MC enter-frame eligibility, etc.)
    got bolted on incrementally. When a test passes in NO_GRAPHICS
    + `graphics-headless-legacy` (both go through `swf_core.c` /
    `swf_headless.c`) but fails in `--mode=graphics`, *and* gotcha
    #13's `#ifndef NO_GRAPHICS` arm misgate isn't the cause, look
    next at `swf.c`'s main loop for a missing block that
    `swf_core.c` has. Walk `swf_core.c`'s main loop top-to-bottom
    and compare each block against `swf.c` for the affected
    test-state transition. Recent landings of this kind:

    - `f1b087ec` — drop test-mode `next_frame = 0` natural wrap.
    - `0fcfe324` — `actionMarkDynamicMCsEnterFrameEligible()` per
      tick + skip post-quit drain loop.
    - `3a54d056` — outer goto catch-up `while (goto_from_action &&
      manual_next_frame)` block. Without this, scripts that defer
      a root goto via `ng_executeGotoTagsOnly` (sets the deferred
      state but doesn't run `funcs[target]`) leave the deferred
      state hanging — `manual_next_frame` gets cleared at
      end-of-tick and `is_playing=0` from gotoAndStop means the
      next tick's frame-func check fails, so the target frame's
      DoAction never fires. Symptom: trace output is missing the
      target frame's lines but otherwise matches up to the goto.
      Key test: `avm1/goto_frame_number` (2/3 → 3/3),
      `avm1/unload_nested_child` (4/5 → 5/5),
      `from_gnash/misc-ming.all/goto_frame_test` (7/15 → 9/15
      ruffle_matched). +2 raw pass net.

    - **(2026-05-11 #2)** — `root_movieclip.currentframe =
      (int)current_frame + 1;` right after `current_frame =
      next_frame;` in the OFFSCREEN_RENDER block at the top of each
      tick. `swf_core.c` syncs the 1-indexed AS-visible
      `_currentframe` on both branches of its end-of-iteration
      block (manual-goto line ~1425, natural-advance line ~1431);
      `swf.c` never did, so pure natural advance never touched
      `_currentframe` and scripts on frame N read whatever value
      the last explicit goto left behind. Symptom: an early
      `gotoAndPlay(K)` sets `_currentframe=K`, then a no-op
      `gotoAndStop(0)` later on a different frame traces K instead
      of the actual current frame. Key test:
      `avm1/goto_frame2` (39/44 → 44/44),
      `from_gnash/misc-ming.all/goto_frame_test` (now full ruffle
      match), `from_gnash/misc-ming.all/get_frame_number_test`
      (full pass). Look for tests that exercise `_currentframe`
      after natural frame advance with no intervening goto.

    - **(2026-05-11 #3 — loop-exit gate)** — Add `g_event_pos >=
      g_event_count` (extern'd from `input_events.c`) to swf.c's
      OFFSCREEN_RENDER loop-exit guard at the top of `tagMain`.
      Both `swf_core.c` (line ~1056) and `swf_headless.c` (line
      ~1023) gate exit on `!(g_events && g_event_pos <
      g_event_count)`. When the root frame_0 sets `quit_swf=1`
      *and* `gotoAndStop` stops the sprite, every other "stay
      alive" predicate returns false; without the event gate,
      swf.c exits before `input_events_pump_tick` can deliver the
      queued `MouseMove`. Key test: `avm1/hittest_morph_input`
      (0/1 → 1/1; expected "hovering" trace was empty because
      onRollOver's MouseMove never fired). Look for tests with
      `input.json`, `num_frames` small, and an empty actual output
      — that's the signature.

    - **(2026-05-11 #3 — natural-wrap cleanup)** — Port the
      `if (!goto_from_action && next_frame < current_frame)`
      invalidate/clear block from swf_core.c (line ~1395) into
      swf.c's `if (manual_next_frame)` arm, gated on
      `#ifdef OFFSCREEN_RENDER`. swf_core.c's version is bare
      `#ifdef NO_GRAPHICS` because that file is only ever compiled
      in NO_GRAPHICS — semantically the cleanup is needed in any
      mode that runs the recompiler-emitted natural wrap-back
      (`next_frame=0; manual_next_frame=1` at end of the last
      frame). Without it, display entries placed at frames > 0
      survive the wrap; when frame 0 re-runs, tagPlaceObject2
      sees the depth occupied and treats the placement as a
      modify rather than a fresh placement, so auto-instance
      counter increments are skipped. Key test:
      `avm1/default_names` (42/52 → 52/52; second-iteration
      auto-instance names short by 5 due to 5 stale-depth
      modifies that should have been fresh placements). Look for
      tests whose actual output drifts numerically from expected
      after a natural wrap-back.

    - **(2026-05-11 #3 — per-tick deferred-roll flush)** — Add
      `actionFlushDeferredRollEvents(app_context)` between
      `actionDrainActionQueueByKind(AQ_KIND_SCRIPT)` and
      `input_events_pump_tick` in swf.c's OFFSCREEN_RENDER block.
      `swf_core.c` (line ~1105) and `swf_headless.c` (line ~1062)
      both have it. `Selection.setFocus` from frame scripts queues
      virtual rollOver/rollOut on the focused MC; the shared
      `input_events_pump_tick` (input_events.c:387) flushes
      between events but does *nothing* when no input.json is
      loaded, so on tests without input events the queue stays
      full forever and the rolls never fire. **Biggest cluster
      unlock of the session**: `avm1/selection_handlers`
      (19/27 → 27/27) plus seven other input/focus regression
      tests that all share this dependency:
      `clip_event_propagation_order` (5/17 → 17/17),
      `tab_ordering_events` (131/150 → 150/150),
      `tab_ordering_events_mouse` (5/65 → 65/65),
      `focusrect_swf6` (4/42 → 42/42), `key_isToggled` (3/9 → 9/9),
      `root_button_mode` (0/10 → 10/10), `text_blocks_clicks`
      (0/4 → 4/4). Look for clusters where focus/keyboard/tab
      tests pass in NO_GRAPHICS + graphics-headless-legacy but
      fail in graphics — they often share the per-tick flush
      dependency.

    Companion class — **swf.c top-of-tick blocks that re-fire
    events `input_events_pump_tick` already dispatched**:

    - **(2026-05-11 #2)** — Gate the entire "Per-frame AS2 input
      dispatch" block (lines ~315-462 + trailing
      `mouse.clicked/released = 0` clear) on `#ifndef
      OFFSCREEN_RENDER`. The block exists for the browser-callback
      model (JS event → set flag → top of next tick processes
      flag). In OFFSCREEN_RENDER, `input_events_pump_tick`
      dispatches each event synchronously AND sets
      `mouse.clicked=1` — that flag then survives end-of-tick
      because the clear at line ~464 runs BEFORE the pump on the
      same tick, not after. Next tick's top re-fires the same
      MouseDown. Same shape for keyboard. `swf_core.c` has no such
      block — input_events_pump_tick is the only event source.
      Key test: `avm1/click_block` (5/6 → 5/5;
      duplicate last "Clicked at"), `avm1/removed_clip_halts_script`
      (5/19 → 19/19; same root cause cascading into
      pending-removal logic). Look for tests where the last
      input event in the file is duplicated, or where a
      handler's state machine looks like it stepped one event too
      far. **General principle**: any swf.c block that re-reads
      browser-callback state at top-of-tick is redundant in
      OFFSCREEN_RENDER and should be gated off — input is purely
      file-driven there.

    **Heuristic**: if you find a non-trivial block in `swf_core.c`'s
    main loop that has no counterpart in `swf.c`, it's a candidate
    for porting. The `OFFSCREEN_RENDER` define means most of the
    test-mode machinery can be shared verbatim; the parts that
    can't are usually around real-time input pumping (which `swf.c`
    has its own logic for at the top of each tick). Match the
    placement against `swf_core.c`: if it's after frame-func and
    before timers in `swf_core.c`, put it in the same relative
    position in `swf.c`. **Inverse heuristic**: if you find a
    non-trivial block in `swf.c`'s top-of-tick that has no
    counterpart in `swf_core.c`, suspect a browser-callback
    leftover that double-dispatches under OFFSCREEN_RENDER —
    gate it on `#ifndef OFFSCREEN_RENDER`.

## Useful commands

```bash
# Find canonical impl of a function (NO_GRAPHICS arm)
grep -n "^void FUNC\|^int FUNC\|^static.*FUNC" \
  SWFModernRuntime/src/libswf/*.c SWFModernRuntime/src/actionmodern/*.c

# Find conditional context around a line in a file
awk 'NR<=LINE && /^#if|^#elif|^#else|^#endif/{print NR":"$0}' FILE

# Capture full link error (one-time debug patch — REVERT BEFORE COMMIT)
# In verify_output.py around the compile_fail handler, add:
#   import os; open(f"/tmp/_compile_err_{name.replace('/','_')}.txt", "w").write(err)

# Find all call sites of a function
grep -rn "FUNC(" SWFModernRuntime/src/

# See where a global is defined vs declared
grep -rn "^int GLOBAL\|^extern int GLOBAL" SWFModernRuntime/src/ SWFModernRuntime/include/

# Compare a suite's NO_GRAPHICS vs graphics results to find the parity gaps
python3 -c "
import json
ng = {t['test']: t for t in json.load(open('ruffle-tests/tests/swfs/avm1/_results/results.json'))['tests']}
g  = {t['test']: t for t in json.load(open('ruffle-tests/tests/swfs/avm1/_results/results_graphics.json'))['tests']}
gaps = [n for n in ng if ng[n].get('status')=='pass' and g.get(n,{}).get('status')!='pass']
print(f'{len(gaps)} parity gaps')
for n in gaps[:20]: print(' ', n)
"
```

## Picking what to work on next

When you have a per-suite `_results/results_graphics.json`, the most
productive moves are usually:

- **Cluster mining.** If 30 EditText tests share the same first-line
  divergence, one fix likely unlocks 25+ of them. Look for shared
  diff prefixes.
- **Compile/segfault first.** A compile_fail test isn't going to start
  passing without code changes; find out which symbol is missing and
  it's likely shared by many other tests.
- **Smoke-set-near misses.** `unload` is still the only smoke failure
  outstanding (`tell_target_invalid` was unlocked by the 2026-05-10
  `actionStop`/`actionGotoFrame` widening; the loadmovie / cross-call
  clusters and most of the sprite-over-execution regressions were
  unlocked by the 2026-05-11 `next_frame`-no-wrap + pending-load drain
  commit `f1b087ec`). Detailed `unload` diagnosis in the Phase 2
  results doc.

## When you're stuck

Subtle semantic failures (test runs end-to-end, most output matches,
a few lines diverge in unclear ways) take longer per test than
structural ones. If you've spent more than ~30 min on a single subtle
test and aren't converging:

- Read the recompiled scripts under `RecompiledScripts/script_N.c`
  to understand what the test actually does (the `actionTrace` /
  `actionGotoFrame` / `actionStop` calls are usually readable).
- Add `fprintf(stderr, ...)` to the suspect handler to trace when and
  how it's called. Remember to revert before commit.
- Compare against `--mode=graphics-headless-legacy` and read the
  trace under that mode to see where the divergence first appears.

Don't sink hours on one subtle test. Commit what you have (even
"failure shifted to later line" is progress) and pick a different
test that has a structural cause. **Structural fixes unlock multiple
tests at once; subtle fixes unlock just themselves.**
