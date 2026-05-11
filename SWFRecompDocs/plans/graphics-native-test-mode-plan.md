# Graphics-Native Test Mode — Project Plan

## Overview

Add a third compile/run mode for the Ruffle test suites that exercises the **full graphics-mode runtime** (`swf.c` + `tag.c` + `graphics_stubs.c`) natively, using offscreen Dawn rendering. Today the test suites only exercise NO_GRAPHICS (`swf_core.c`) and HEADLESS_GRAPHICS (`swf_headless.c`, a NO_GRAPHICS-style frame loop with rendering hooks). Neither path validates the actual graphics-mode frame loop that runs in browsers.

The new mode lets us run the same ~1100 tests across all suites against the production graphics path and surface parity gaps systematically. As `swf.c` reaches feature parity with `swf_core.c`, HEADLESS_GRAPHICS becomes redundant — its retirement is an explicit end-state goal of this plan.

**Status**: Planning
**Created**: 2026-05-09
**Target Completion**: TBD (multi-phase; Phase 1 should be a few days)

---

## Goals

### Primary

1. **New `--graphics-native` mode in `verify_output.py`** that compiles tests against `swf.c` + `tag.c` + `graphics_stubs.c` + `render_webgpu.c` (offscreen) + audio native stubs, and runs them headlessly to produce trace and (where applicable) image output.
2. **Decouple offscreen rendering from frame-loop choice.** Today `HEADLESS_GRAPHICS` means *both* "use `swf_headless.c` frame loop" *and* "render offscreen via Dawn." Split these so the new mode can use offscreen rendering without inheriting the headless frame loop.
3. **CI integration.** A new shard in the Ruffle workflow (or a flag on the existing one) runs the suite in graphics-native mode and produces a parallel results file (`results_graphics.json` or similar) so we can track pass-rate delta vs NO_GRAPHICS over time.
4. **Close `swf.c` parity gaps surfaced by the suite** — primarily the goto-catch-up machinery that currently lives only in `swf_core.c` / `swf_headless.c`. This is already an in-flight workstream; the new mode gives it a measurable signal.

### Secondary

5. **Image-comparison test migration path.** `run_image_tests.py` currently uses `--headless`. Once graphics-native is stable, it should switch to the new mode (image tests then validate the actual production rendering path).
6. **Per-suite pass-rate visibility.** Each results-diff file should show NO_GRAPHICS pass / graphics-native pass / delta.

### End-state goal (post-parity)

7. **Retire `HEADLESS_GRAPHICS` and `swf_headless.c`.** Once `swf.c` reaches `swf_core.c` parity and graphics-native is matching or beating `--headless` on every suite, delete `swf_headless.c` (1343 lines) and the `HEADLESS_GRAPHICS` define. `--headless` becomes an alias for `--graphics-native`. This eliminates a near-duplicate of `swf_core.c` that has to be kept in sync with every NO_GRAPHICS frame-loop change.

### Non-Goals

- **Replacing NO_GRAPHICS mode for trace tests.** NO_GRAPHICS will remain the default for trace-only test runs — it's faster to compile, has no Dawn dependency, and is the path most developers run locally. Graphics-native is additive coverage.
- **Browser-side validation.** The new mode runs natively against Dawn. Validating browser-specific behavior (real `emscripten_sleep` cadence, JS-driven input) is out of scope; that's what the demo deployments are for.
- **Audio output validation.** Audio in the new mode uses the existing native stubs (`audio_output_*` no-ops). Validating actual audio playback semantics is a separate effort.

---

## Probe Findings (already verified)

Three probes ran on 2026-05-09 to validate feasibility before writing this plan. Results:

### Probe 1: Native compile of full-graphics sources

All sources except `render_webgpu.c` compile cleanly with native gcc (no `-DNO_GRAPHICS`, no `-DHEADLESS_GRAPHICS`, no `__EMSCRIPTEN__`):

| Source | Native compile |
|---|---|
| `swf.c` | ✅ |
| `tag.c` | ✅ |
| `graphics_stubs.c` | ✅ |
| `ng_shared.c` | ✅ (one minor implicit-decl warning) |
| `hit_test.c`, `shape_hit_test.c`, `tag_stubs.c` | ✅ |
| `audio.c`, `audio_output_web.c` | ✅ (native stubs in `#else` branch) |
| `render_webgpu.c` | ❌ — needs `SDL3/SDL.h` in its non-headless non-emscripten branch |

The `render_webgpu.c` failure is not a real blocker: that file already has a working `#ifdef HEADLESS_GRAPHICS` branch that does Dawn-only offscreen rendering with no SDL dependency. The new mode just needs to use that branch.

### Probe 2: Structural diff `swf.c` vs `swf_headless.c`

- `swf_headless.c` (1343 lines) is a fork of `swf_core.c` (1470 lines) with rendering hooks bolted in. It carries the full goto-catch-up machinery (`ng_executeGotoCatchUp`, `ng_executeGotoTagsOnly`, the 3-phase deferred-script ordering, etc.).
- `swf.c` (391 lines) is a much simpler frame loop. **It does not have the goto-catch-up logic** — gotos just set `next_frame` and the loop falls through. This is the load-bearing parity gap.
- `swf.c` adds (vs `swf_core.c`): per-frame mouse dispatch, keyboard transition scan, text-input ring drain, IME compose/commit, focus highlight, deferred roll-event flush. For trace tests with no synthetic input these are all no-ops.

### Probe 3: Native `main.c` wrapper

`wasm_wrappers/main.c`'s `#ifndef __EMSCRIPTEN__` branch is production-ready. It calls `swfStart(&app_context)` directly. The conditional that populates rendering fields uses `!defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)` — this already covers a hypothetical full-graphics-native build (NO_GRAPHICS undefined → first clause true). No changes needed here.

---

## Current State

### Three runtime mode triples today

| Mode | Frame loop | Renderer | Used by |
|---|---|---|---|
| NO_GRAPHICS | `swf_core.c` | none | default `verify_output.py`; `build_test.sh` no flag |
| HEADLESS_GRAPHICS | `swf_headless.c` (NO_GRAPHICS-style + render hooks) | `render_webgpu.c` (Dawn offscreen) | `verify_output.py --headless`; `build_test.sh --headless`; `run_image_tests.py` |
| GRAPHICS (full) | `swf.c` (browser frame loop) | `render_webgpu.c` (WebGPU via emscripten) | `build_test.sh --graphics` (WASM only) |

### Defines used today

| Define | Meaning today | Set in |
|---|---|---|
| `NO_GRAPHICS` | "Use `swf_core.c`; no rendering at all" | NO_GRAPHICS, HEADLESS_GRAPHICS |
| `HEADLESS_GRAPHICS` | "Use `swf_headless.c`; render offscreen via Dawn" | HEADLESS_GRAPHICS only |
| `USE_WEBGPU` | "Compile in WebGPU/Dawn rendering paths" | HEADLESS_GRAPHICS, GRAPHICS |
| `__EMSCRIPTEN__` | toolchain-defined | GRAPHICS (browser only) |

The overload: `HEADLESS_GRAPHICS` controls *both* frame loop and renderer mode in `render_webgpu.c`. We need to split it.

---

## Proposed Design

### 1. New define: `OFFSCREEN_RENDER`

Introduce one define that means **"the renderer should run headlessly via Dawn — no SDL window, no JS canvas."** Set whenever rendering is offscreen, regardless of frame loop.

| Mode | NO_GRAPHICS | HEADLESS_GRAPHICS | OFFSCREEN_RENDER | Frame loop | Renderer path |
|---|---|---|---|---|---|
| NO_GRAPHICS | ✓ | | | `swf_core.c` | (none) |
| HEADLESS_GRAPHICS *(legacy)* | ✓ | ✓ | ✓ | `swf_headless.c` | offscreen Dawn |
| **GRAPHICS-NATIVE *(new)*** | | | ✓ | `swf.c` | offscreen Dawn |
| GRAPHICS *(browser)* | | | | `swf.c` | WebGPU via JS |

Edits:
- `render_webgpu.c`: replace `#ifdef HEADLESS_GRAPHICS` guards in renderer paths with `#ifdef OFFSCREEN_RENDER`. The HEADLESS_GRAPHICS path becomes a superset (still defines `OFFSCREEN_RENDER`), so no behavior change for existing modes.
- `swf.c` / `tag.c`: no changes — their existing `!defined(HEADLESS_GRAPHICS)` guards already work.
- `swf_headless.c`: no changes — still gated on `HEADLESS_GRAPHICS`.

### 2. CLI flag structure: orthogonal target + mode

Today `build_test.sh --graphics` implicitly *forces* the target to wasm — the "wasm vs native" axis is tangled with the "graphics vs no-graphics" axis. Decouple them:

| Axis | Values |
|---|---|
| `TARGET` (positional, build_test.sh only) | `native` \| `wasm` |
| `--mode=...` flag | `no-graphics` (default) \| `graphics` \| `graphics-headless-legacy` |

`verify_output.py` is always native, so it just takes `--mode=`.

Mapping from today's flags:

| Today | After rename |
|---|---|
| `build_test.sh foo wasm --graphics` | `build_test.sh foo wasm --mode=graphics` |
| `build_test.sh foo native --headless` | `build_test.sh foo native --mode=graphics-headless-legacy` |
| `build_test.sh foo native` (default) | `build_test.sh foo native --mode=no-graphics` *(or omit; default)* |
| *(doesn't exist)* | `build_test.sh foo native --mode=graphics` ← **the new mode** |
| `verify_output.py --test=X` (default) | `verify_output.py --test=X --mode=no-graphics` *(or omit)* |
| `verify_output.py --test=X --headless` | `verify_output.py --test=X --mode=graphics-headless-legacy` |
| *(doesn't exist)* | `verify_output.py --test=X --mode=graphics` ← **the new mode** |

The legacy mode name (`graphics-headless-legacy`) is deliberately ugly — it's a flag we want to delete in Phase 3, and the name should remind everyone of that.

### 3. `verify_output.py` source list for `--mode=graphics`

```python
# Sketch — see verify_output.py:1369 (compile_native) and :1573 (mode_defines)
if mode == "graphics":
    core_sources.append("src/libswf/swf.c")
    core_sources.append("src/libswf/tag.c")           # already shared
    core_sources.append("src/libswf/graphics_stubs.c")
    core_sources.append("src/audio/audio.c")
    core_sources.append("src/audio/audio_output_web.c")  # native stubs branch
    core_sources.append("src/rendering/render_webgpu.c")
    mode_defines = ["-DUSE_WEBGPU", "-DOFFSCREEN_RENDER", "-DNDEBUG"]
    mode_includes = [<dawn + rendering paths, same as headless>]
    mode_libs    = [<libwebgpu_dawn.a, -lstdc++, -lpthread, -ldl>]
elif mode == "graphics-headless-legacy":
    # existing HEADLESS branch; add -DOFFSCREEN_RENDER alongside -DHEADLESS_GRAPHICS
    ...
else:  # mode == "no-graphics"
    # existing NO_GRAPHICS branch
    ...
```

Backward-compat note: the old `--headless` flag should keep working as an alias for `--mode=graphics-headless-legacy` for the duration of Phase 1–2 to avoid breaking external scripts and CI configs. Removed in Phase 3.

Output JSON:
- New default path: `_results/results_graphics.json`
- Or: a single `results.json` with a per-test field indicating which mode was used (cleaner for diff tooling but breaks existing readers — defer).

### 4. `swf.c` parity backport

This is the real engineering work. The minimal set of `swf_core.c`-only behaviors that need to land in `swf.c` for tests to pass at parity rates:

1. **Goto catch-up machinery.** `ng_executeGotoCatchUp`, `ng_executeGotoTagsOnly`, plus the 3-phase deferred-script ordering (`g_sprite_init_filter_active` etc., per memory notes). This is the largest item — many Ruffle tests exercise gotos.
2. **Deferred root goto / play flags.** `g_deferred_goto_play`, `g_deferred_root_goto`.
3. **Sprite preservation during root loop-back.** Currently lives in `tagPlaceObject2`'s NO_GRAPHICS gate.
4. **Pending-removal finalize / unload semantics.** Per memory: `actionFinalizePendingRemovals` is called at frame start in NO_GRAPHICS; need same hook in `swf.c`.

Most of these symbols already exist in `tag.c` (shared). The work in `swf.c` is structural — mirroring the catch-up control flow. Recent commits (`Compile tag_stubs.c in graphics builds; un-gate dependent action.c blocks`, etc.) have already started this.

### 5. CI integration

Two options for the workflow:

**Option A (recommended):** Add a `mode` matrix dimension to `ruffle-tests.yml` with values `no-graphics` and `graphics-native`. The existing 30-shard parallelism becomes 60-shard total (or shrink shard count per mode to keep total cost flat). Each mode produces its own results JSON; the "Generate diff report" step diffs each independently.

**Option B (cheaper):** Keep the existing workflow as-is, add a manual-dispatch `mode` input that selects which mode to run. Operator triggers each mode separately.

Start with B to validate end-to-end, then move to A once the new mode is stable.

### 6. Build script parity

`build_test.sh` adopts the same `--mode=...` flag (see section 2). The new `--mode=graphics` invocation works for both `native` and `wasm` targets — for native, it's the new offscreen-Dawn build; for wasm, it's the existing browser graphics build (replacing today's `--graphics`).

---

## Implementation Phases

### Phase 0 — Repair `--headless` (already done, 2026-05-09)

`swf_headless.c` had drifted from `swf_core.c`: three globals (`g_force_quit`, `g_natural_wrap_cleanup_pending`, `g_goto_inlined_in_caller_frame`) were referenced from shared sources but never defined in the headless build. CI doesn't run `--headless` so the breakage was latent. Fixed by adding the three definitions to `swf_headless.c`. Smoke baseline captured in `graphics-native-test-mode-baseline-2026-05-09.md`.

### Phase 1 — Wire up the mode (no parity work) — DONE except step 3

Goal: the new mode compiles, links, runs tests, and produces a results file. Pass rate may be terrible — that's fine. We just need the signal.

1. ✅ Introduce `OFFSCREEN_RENDER` define. Edit `render_webgpu.c` to add it as an alias-or-replacement for `HEADLESS_GRAPHICS` in renderer guards. Verify the legacy headless path still works (no functional change).
2. ✅ Adopt `--mode={no-graphics|graphics|graphics-headless-legacy}` in `verify_output.py`. Wire `--mode=graphics` to the new source list + defines from section 3. Keep `--headless` working as an alias for `--mode=graphics-headless-legacy` (deprecation warning fine).
3. ⏸ Adopt the same `--mode=` flag in `build_test.sh`. Keep `--graphics` and `--headless` as deprecated aliases through Phase 2. *(Deferred — `verify_output.py --mode=graphics --test=NAME` covers local debugging; `build_test.sh` integration is just convenience.)*
4. ✅ Run the AVM1 suite locally on 5–10 representative tests — captured in `graphics-native-test-mode-baseline-2026-05-09.md` (smoke set: 9 tests).
5. ✅ Wire CI option B: `mode` + `single_test` workflow_dispatch inputs. Dawn build is auto-cached via a separate `build-dawn.yml` workflow (see `.github/workflows/build-dawn.yml`). Single-test verified end-to-end on 2026-05-09.

**Exit criteria:** mode compiles, runs end-to-end, baseline pass rate captured for all suites. Likely much lower than NO_GRAPHICS — this is the triage backlog.

### Phase 2 — Close `swf.c` parity gaps — IN PROGRESS

Goal: graphics-native pass rate approaches NO_GRAPHICS pass rate.

**Status (2026-05-10):** **817/1125 pass (72.6%).** Pre-session smoke now 8/9 — `unload` remains the only smoke failure (documented partial in `graphics-native-test-mode-phase2-results-2026-05-09.md`).

**Session-of-2026-05-10 commits (in order):**
- `fff977ec` — Frame-loop parity (`is_playing || manual_next_frame` gate on `funcs[current_frame]`, `processTimers`, `root_movieclip` init). Unblocked the full `from_gnash/actionscript.all` 0/190 cluster.
- `ebaa7506` — `dictionary` / `display_list` switched from `malloc` to `HCALLOC` so `grow_ptr`'s `HALLOC`+`FREE` pair works. Resolved the "SIGSEGV (output matches)" cluster (47 → 1 in avm1, also unblocked misc-mtasc 0/9 → 7/9 and misc-ming +34).

**Per-suite delta (2026-05-09 → 2026-05-10):**

| Suite | NO_GRAPHICS | 2026-05-09 graphics | 2026-05-10 graphics | Δ session | Effective pass |
|---|---|---|---|---|---|
| avm1 | 605/648 | 463 | **510** (78.3%) | **+47** | 521/651 |
| from_gnash/actionscript.all | 126/190 | 0 | **125** (65.8%) | **+125** | 186/190 |
| from_gnash/misc-ming.all | 66/102 | 9 | **43** (42.2%) | **+34** | 57/102 |
| from_gnash/misc-mtasc.all | 7/9 | 0 | **7** (77.8%) | **+7** | 8/9 |
| from_gnash/misc-swfc.all | 8/16 | 5 | 6 (37.5%) | +1 | 11/16 |
| from_gnash/misc-swfmill.all | 17/18 | 16 | 17 (94.4%) | +1 | 18/18 |
| from_shumway | 73/92 | 47 | 52 (56.5%) | +5 | 57/92 |
| from_shumway/avm1 | 46/47 | 33 | 37 (78.7%) | +4 | 38/47 |
| **TOTAL** | **948/1122** | **573** | **797 (70.8%)** | **+224** | **896/1125 (79.6%)** |

**Workflow + tooling changes this session** (don't directly affect pass rate but matter for the next session):
- `784bb3ae` — CI commit step inherits from `origin/ruffle-test-results` so trace and graphics runs don't clobber each other when force-pushed.
- `b3f2cb8e` — Per-mode `.md` generators: `filter_results.py` derives output stem; `generate_ruffle_results_markdown.py --scan` walks all three modes (trace / graphics / headless) producing matching `.md` + `_regressions.md`; `generate_results_index.py` emits parallel `RUFFLE_RESULTS_{,GRAPHICS,HEADLESS}{,_FILTERED}.md`.
- `ea65de7f` — Workflow auto-builds Dawn on cache miss in `setup-parallel` (~30 min penalty, then cached); ccache `--max-size` reduced 1G → 200M (was forcing eviction of the smaller Dawn cache via the 10 GiB per-repo cap); end-of-workflow step prunes old ccache entries via `gh cache delete`.
- `7767c265` — Commit step deletes untracked `*_previous.json` files before switching to `ruffle-test-results` so the checkout doesn't fail on add/add conflicts.

This is iterative. For each suite:
1. Diff graphics-native results vs NO_GRAPHICS results. Tests passing in NO_GRAPHICS but failing in graphics-native are the parity bug list.
2. Bisect: does the test also pass in `--mode=graphics-headless-legacy`? If yes → bug is in `swf.c` frame loop. If no → bug is in shared `tag.c`/`action.c` paths and likely a pre-existing issue.
3. Backport the missing logic from `swf_core.c` to `swf.c`. Largest structural items now done; the remaining ~52 effective-pass gap is per-test long-tail, no dominant cluster left. See `graphics-native-test-mode-playbook.md` for the cluster-mining workflow.

**Next-session starting point:** the long-tail in `avm1` (128 output_mismatch tests) and `from_gnash/misc-ming.all` (~50 failures) is the largest remaining pool. Use each suite's `results_graphics_diff.md` and `results_graphics_regressions.md` (now generated by every CI run) to find clusters. The two outstanding smoke failures (`tell_target_invalid`, `unload`) already have detailed diagnoses in `graphics-native-test-mode-phase2-results-2026-05-09.md`.

#### 2026-05-10 follow-up — `quit_swf` premature-exit fix (commit `ab614b80`)

Replaced `tagMain`'s `while (!quit_swf)` with the `swf_core.c`-style
exit condition (only break when `quit_swf` AND no playing sprites /
timers / sounds / netstreams / enterframe handlers). Previously the
loop exited as soon as the recompiler-emitted `quit_swf = 1` fired at
the end of the last root frame, abandoning any sprite that hadn't
finished its own timeline.

Net **+2 raw pass / -2 effective**: 797/1125 → 799/1125 (71.0%);
896/1125 effective → 894/1125 (79.5%).

**8 unlocks** (newly passing) in `avm1`:
`bad_placeobject_clipaction`, `drag_drop`, `mouse_pos` (8/665 →
665/665), `mouse_pos_with_scale_factor`, `slash_syntax`,
`target_clip_swf5`, `target_clip_swf6`, `tell_target` (0/37 →
37/37). Plus `native_objects_swf6` lifted from segfault → almost-
passing (114/115); `localconnection`, `sound_duration_position_props`,
`movieclip_state_values` improved by 30–48 lines each; -998 mismatched
lines total in `avm1`.

**Regressions to investigate next session:**
- 5 newly-failing in `avm1` show "X/X lines matching" but the test
  status is `output_mismatch` — extra trailing lines from sprite
  over-execution (the longer loop lets sprites loop until
  `MAX_FRAMES`). Tests: `create_empty_movie_clip`,
  `form_loader_encoding_1`, `issue_2084`, `loadmovie_replace_root`,
  `textfield_cache_as_bitmap`.
- 2 `avm1` tests: `output_mismatch` → `runtime_error`
  (`movieclip_invalid_get_bounds_6/7` — line counts 4/10 → 2/10).
- 4 `ruffle_matched` → `output_mismatch` regressions (line counts
  unchanged): `form_loader_encoding_4`, `movieclip_library_state_values`
  in `avm1`; 2 fuzz tests in `from_shumway`.
- 1 newly-failing in `actionscript.all`: `case-v5` (39/39 lines but
  status went pass → `runtime_error`).

**Cluster left on the table:** `call`, `function_base_clip`,
`swf{5,6}_to_{6,5}_cross_call`, `register_class_swf6`,
`cross_movie_root` and similar still produce empty/near-empty output.
Root cause is `actionStop` semantics — when a sprite's frame-0 init
script calls `actionStop`, graphics-native falls through to
`is_playing = 0` (stops the root) instead of the modern
`ng_isInsideSprite()` / `ng_stopCurrentSprite()` path used in
NO_GRAPHICS. Naive widening triggered an infinite-loop regression in
`function_base_clip` (`script_1`'s `this.gotoAndStop(2)` re-enters
`actionStop` from root context unboundedly). Detail + abandoned-attempt
notes in `graphics-native-test-mode-phase2-results-2026-05-09.md`.

#### 2026-05-10 follow-up — `actionStop`/`Play`/`GotoFrame` widening (commits `e527f410`, `f8745996`)

Widened the modern `ng_isInsideSprite()` / `ng_stopCurrentSprite()` /
`ng_gotoFrameByMC()` arm of `actionStop` / `actionPlay` /
`actionGotoFrame` from `#else NO_GRAPHICS` to `defined(NO_GRAPHICS) ||
defined(OFFSCREEN_RENDER)`. The legacy `targeted_sprite` arm is now
gated to `!NO_GRAPHICS && !OFFSCREEN_RENDER` — i.e. browser-WASM
graphics only, where it was actually live.

The `function_base_clip` infinite loop traced to `actionGotoFrame`,
not `actionStop`: `this.gotoAndStop(2)` on a non-root MC compiles to
`actionGotoFrame2` → `actionGotoFrame`. Pre-widening, graphics-native
took the `targeted_sprite == NULL` arm and fell through to the
root-goto fallback, which called `ng_executeGotoCatchUp` inline — and
the catch-up re-ran the current frame's `DoAction`, re-entering the
same `gotoAndStop` call, infinitely. The widening routes non-root
`actionGotoFrame` through `ng_gotoFrameByMC` instead.

Second commit (`f8745996`) handles `actionGotoFrame`'s
"sprite-script + `g_settarget_explicit_root`" sub-branch in
OFFSCREEN_RENDER: that branch defers via `g_deferred_root_goto = 1`
which `swf_core.c` consumes but `swf.c` never reads. Without the
fix, `issue_9885` regressed (script_1 was re-executed by the
recompiler-emitted last-frame wrap-back). Resolution: in
OFFSCREEN_RENDER, take the inline-catch-up branch (matches the OLD
fallthrough behavior).

Net **+18 raw pass**: 799 → 817 / 1125 (72.6%).
Per-suite delta vs the post-`ab614b80` baseline:

| Suite | Pre | Post | Δ |
|---|---:|---:|---:|
| `avm1` | 513 | 524 | +11 |
| `from_gnash/actionscript.all` | 124 | 125 | +1 |
| `from_gnash/misc-ming.all` | 43 | 47 | +4 |
| `from_shumway` | 52 | 53 | +1 |
| `from_shumway/avm1` | 37 | 38 | +1 |

Notable `avm1` unlocks: `call` (0/63 → pass), `function_base_clip`
(0/8 → pass), `goto_frame` (3/12 → pass), `goto_label` (3/17 → pass),
`button_keypress` (1/3 → pass), `tell_target_invalid` (5/6 → pass),
`tell_target_invalid_swf6` (4/5 → pass), `execution_order1/2/4`,
`target_clip_removed`. Plus `movieclip_hittest_shapeflag` 193/338 →
329/338 and several other partial improvements.

The 5 sprite-over-execution regressions from `ab614b80` and the 4
ruffle_matched → output_mismatch regressions are still present —
they're a separate root cause (sprite stops via actionStop need to
work inside the sprite's own scope; this widening *should* help once
the sprite-init path queues actionStop to fire on the right
`g_current_sprite_obj`).

Remaining cluster targets (still failing in graphics-native, separate
root causes): `swf5_to_6_cross_call`, `swf6_to_5_cross_call`,
`register_class_swf6`, `cross_movie_root`, `lock_root`.

**Exit criteria:** graphics-native pass rate within 2% of NO_GRAPHICS on every suite, OR remaining gaps documented in `_investigation/` as "expected divergence."

### Phase 3 — Migrate image tests + retire HEADLESS_GRAPHICS

Goal: one rendering path instead of two.

1. Switch `run_image_tests.py` from `--mode=graphics-headless-legacy` to `--mode=graphics`. Verify image-comparison results don't regress.
2. Move CI to option A (parallel matrix). The legacy mode is no longer the primary rendering CI path.
3. Once the legacy mode has zero unique callers and graphics-native is matching it on every suite for ≥1 month: delete `swf_headless.c`, remove `HEADLESS_GRAPHICS` from `render_webgpu.c` / `audio_output_web.c` / `swf.c` / build scripts, drop the `--mode=graphics-headless-legacy` value (and the deprecated `--headless` alias).

**Exit criteria:** `swf_headless.c` deleted, `HEADLESS_GRAPHICS` removed from the codebase.

---

## Validation Plan

For Phase 1:
- Re-run the smoke set from `graphics-native-test-mode-baseline-2026-05-09.md` under `--mode=graphics` and compare against the captured `--headless` and NO_GRAPHICS columns. Expected: 8/9 pass if `swf.c`'s frame loop is roughly equivalent to `swf_headless.c` for these scenarios; the single `register_and_init_order` regression in the headless column is the bisection diagnostic (passes there → bug is in `swf.c`'s frame loop and self-fixing in Phase 3; fails there too → bug is in shared code).
- Diff `--mode=graphics` and `--mode=graphics-headless-legacy` output for the image-comparison test (`bitmap_data_colortransform`). Pixel parity is expected since the renderer is unchanged; any divergence indicates `swf.c` is driving rendering differently than `swf_headless.c`.

For Phase 2:
- After each `swf.c` parity backport, re-run the suite in graphics-native mode. Track delta on the full results JSON.
- Maintain a `swf_c_parity_backlog.md` in `ruffle-tests/tests/swfs/_investigation/` listing tests that pass in NO_GRAPHICS but fail in graphics-native, grouped by suspected root cause.

For Phase 3:
- Before deleting `swf_headless.c`, run `run_image_tests.py --graphics-native` and confirm pixel parity vs `--headless` baseline on every image-comparison test.

---

## Risks & Open Questions

1. **`swf.c` frame-loop semantics may diverge from `swf_core.c` in subtle ways beyond goto catch-up.** Probe 2 only listed structural differences; behavioral differences (e.g. the order in which mouse dispatch interleaves with frame execution) may surface bugs that don't affect either browser graphics or NO_GRAPHICS in isolation but do affect the new combined path. Mitigation: bisect via `--headless` (Phase 2 step 2) to localize.
2. **Compile time / CI cost.** Full-graphics builds pull in Dawn, audio, more sources. Per-test compile may rise from ~10s to ~30s. ccache helps. If unacceptable, consider running graphics-native on a smaller test subset in CI rather than the full suite.
3. **Renderer determinism.** Image tests rely on Dawn producing identical pixels run-to-run. `--headless` already validates this works; graphics-native uses the same Dawn library, so should be fine — but worth confirming on the first image test run.
4. **Resolved by section 2 rename.** Old: `build_test.sh --graphics` implied wasm. New: `--mode=graphics` is target-orthogonal; the wasm-vs-native axis lives in the existing TARGET positional. Old `--graphics` and `--headless` flags retained as deprecated aliases through Phase 2, removed in Phase 3.
5. **Order of Phase 2 backports.** Backporting goto catch-up to `swf.c` is the biggest item but also the riskiest — it's a large amount of code that has to interleave correctly with `swf.c`'s simpler frame loop. Worth a separate design pass before starting.

---

## Files Touched (estimated)

### Phase 1
- `SWFModernRuntime/src/rendering/render_webgpu.c` — add `OFFSCREEN_RENDER` guard alongside `HEADLESS_GRAPHICS`
- `ruffle-tests/verify_output.py` — new `--graphics-native` mode in arg parser + `compile_native`
- `SWFRecomp/scripts/build_test.sh` — new `--graphics-native` flag
- `.github/workflows/ruffle-tests.yml` — manual-dispatch mode input

### Phase 2
- `SWFModernRuntime/src/libswf/swf.c` — backport goto catch-up + deferred goto + pending-removal hooks
- Possibly small edits in `SWFModernRuntime/src/libswf/tag.c` for symbols that need to be visible to both frame loops

### Phase 3
- Delete `SWFModernRuntime/src/libswf/swf_headless.c`
- Remove `HEADLESS_GRAPHICS` from build scripts, verify_output.py, render_webgpu.c, audio_output_web.c, swf.c, etc.
- Update `run_image_tests.py` to use `--graphics-native`
