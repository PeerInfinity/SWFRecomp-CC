# Graphics-Native Test Mode — Phase 2 Playbook

How to make another failing Ruffle test pass under `--mode=graphics`.
Focused on the workflow + gotchas that actually came up; not a
comprehensive reference. See `graphics-native-test-mode-plan.md` for
goals and `graphics-native-test-mode-phase2-results-2026-05-09.md` for
what's already been done.

## The loop

1. **Pick a test.** Look at recent failure list (full-suite results JSON,
   or run the smoke set). Prefer tests that are CLOSE to passing —
   first-line-divergence ones are usually structural; many-line-mismatch
   ones may need bigger work.

2. **Diff it.** First line of divergence usually points at what's
   missing.

   ```
   python3 ruffle-tests/verify_output.py --test=NAME --mode=graphics --diff
   ```

   The output shows `-` (expected) vs `+` (actual) for the first ~6
   diverging lines.

3. **Bisect via the legacy mode.** Run the same test under
   `--mode=graphics-headless-legacy`:

   - Passes there but fails in graphics-native → bug is in `swf.c`'s
     frame loop or in a recently-widened gate. **Most common case.**
   - Fails in both → shared-code bug in `tag.c` / `action.c` /
     `action_queue.c`. Rarer; investigate with NO_GRAPHICS as control.

4. **Find what's missing.** Three things are usually missing:

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

5. **Apply the fix, re-baseline.** Don't just fix — re-run the smoke
   set to make sure no regressions:

   ```
   for t in add tell_target_invalid clip_events edittext_default_format \
            button_key_events goto_rewind3 register_and_init_order \
            unload bitmap_data_colortransform; do
     out=$(python3 ruffle-tests/verify_output.py --test="$t" --mode=graphics --diff 2>&1)
     pass=$(echo "$out" | grep -E "^Pass:" | head -1 | awk '{print $2}')
     fail=$(echo "$out" | grep -E "^Fail:" | head -1 | awk '{print $2}')
     printf "%-35s pass=%s fail=%s\n" "$t" "$pass" "$fail"
   done
   ```

6. **Verify legacy modes unchanged.** After any tag.c / action.c gate
   change, sanity-check:

   ```
   python3 ruffle-tests/verify_output.py --test=NAME --diff                          # NO_GRAPHICS
   python3 ruffle-tests/verify_output.py --test=NAME --mode=graphics-headless-legacy --diff
   ```

7. **Commit.** Per-fix commits with a clear "what flipped" line in the
   message.

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
   Widen G's gate too. May cascade 2-3 deep before settling.

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

   ```
   git checkout -- ruffle-tests/tests/swfs/avm1/_results/results_headless.json
   rm -f ruffle-tests/tests/swfs/avm1/_results/results_graphics.json
   ```

## Useful commands

```bash
# Find canonical impl of a function (NO_GRAPHICS arm)
grep -n "^void FUNC\|^int FUNC\|^static.*FUNC" SWFModernRuntime/src/libswf/*.c SWFModernRuntime/src/actionmodern/*.c

# Find conditional context around a line in a file
awk 'NR<=LINE && /^#if|^#elif|^#else|^#endif/{print NR":"$0}' FILE

# Capture full link error (one-time debug patch — REVERT BEFORE COMMIT)
# In verify_output.py around the compile_fail handler, add:
#   import os; open(f"/tmp/_compile_err_{name.replace('/','_')}.txt", "w").write(err)

# Find all call sites of a function
grep -rn "FUNC(" SWFModernRuntime/src/

# See where a global is defined vs declared
grep -rn "^int GLOBAL\|^extern int GLOBAL" SWFModernRuntime/src/ SWFModernRuntime/include/
```

## When you're stuck

The two failures we left in the smoke set (`tell_target_invalid` and
`unload`) are both subtle semantic issues, not structural gaps. If a
test you're working on falls into the same category — i.e., the test
runs end-to-end and most of the output matches but a few lines diverge
in subtle ways — it's worth:

- Reading the recompiled scripts under `RecompiledScripts/script_N.c`
  to understand what the test actually does (the `actionTrace` /
  `actionGotoFrame` / `actionStop` calls are usually readable).
- Adding `fprintf(stderr, ...)` to the suspect handler (e.g.,
  `actionStop`, `actionFinalizePendingRemovals`) to trace when and how
  it's called. Remember to revert before commit.
- Comparing against `--mode=graphics-headless-legacy` and reading the
  trace under that mode to see where the divergence first appears.

Don't sink hours on one subtle test if you're about to give up — commit
what you have (even partial progress can show up as "failure shifted to
later line"), and pick a different test that has a structural cause.
The structural ones unlock multiple tests at once; the subtle ones
unlock just themselves.
