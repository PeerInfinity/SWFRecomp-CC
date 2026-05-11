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
- **Smoke-set-near misses.** `unload` is the only smoke failure still
  outstanding (`tell_target_invalid` was unlocked by the 2026-05-10
  `actionStop`/`actionGotoFrame` widening). Detailed `unload` diagnosis
  in the Phase 2 results doc.

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
