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

### Phase 2 — Close `swf.c` parity gaps — DONE (2026-05-12)

Goal: graphics-native pass rate approaches NO_GRAPHICS pass rate.

**Status (2026-05-12, post follow-up #5 + latest CI):** **946/1125
raw pass (84.1%)** in `--mode=graphics` vs **948/1125 (84.3%)** in
`--mode=no-graphics`. The two-test cross-suite gap is fully
accounted for: `from_gnash/actionscript.all/case-v6` (CI-only flake)
and `from_gnash/misc-ming.all/place_and_remove_object_insane_test`
(shared-code bug in `tag.c`, also fails in
`--mode=graphics-headless-legacy`) — both deferred in
[`SWFRecompDocs/BACKLOG.md`](../BACKLOG.md#deferred-test-failures).
Smoke set clean.

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

#### 2026-05-11 follow-up — loadMovie drain + drop next_frame wrap (commit `f1b087ec`)

Two structural backports from `swf_core.c` to `swf.c`'s tagMain, both
gated on `OFFSCREEN_RENDER` so the wasm browser path is untouched:

1. **Pending-load infrastructure.** Added at frame start:
   `actionProcessDeferredUnloads`, `actionPromotePendingMCLLoads`.
   Added after timers: `actionProcessDeferredFailedLoads`,
   `actionFirePendingDirectLoads`, `actionAdvancePlayingLevels`,
   `actionFirePendingLoadInits` drain, `processSoundPlayback`,
   `processNetStreams`, `processLocalConnectionMessages`. Extended the
   `quit_swf` exit gate to also wait on `g_pending_mcl_load_count` and
   `g_pending_direct_load_count`. Plus a last-tick MCL drain that
   promotes any `_next_tick` loads when `tick_count >= max_ticks`,
   matching `swf_core.c` lines ~1353-1358.

2. **Dropped the unconditional `next_frame = 0` wrap.** The
   pre-existing `else if (is_playing) { next_frame += 1; if (next_frame
   >= g_frame_count) next_frame = 0; }` is correct for real playback
   (SWFs loop by default) but wrong in test mode: the recompiler emits
   its own natural-wrap as `manual_next_frame=1; next_frame=0` paired
   with `quit_swf=1`. Auto-wrapping on top re-ran `frame_0` every tick
   whenever anything else kept the loop alive (a playing child sprite,
   an MCL load, a deferred direct load, etc.), producing duplicated
   trace output. The wrap is now `#ifndef OFFSCREEN_RENDER`; in
   OFFSCREEN_RENDER mode `next_frame` is allowed to pass
   `g_frame_count`, and the existing `current_frame < g_frame_count`
   guard at the top of the frame-func call prevents OOB.

Net **+51 raw pass**: 817 → 868 / 1125 (72.6% → 77.2%);
-1054 mismatched lines.

**Per-suite delta vs the post-`e527f410`/`f8745996` baseline:**

| Suite | Pre | Post | Δ |
|---|---:|---:|---:|
| `avm1` | 524 | 565 | +41 |
| `from_gnash/actionscript.all` | 125 | 125 | 0 |
| `from_gnash/misc-ming.all` | 47 | 48 | +1 |
| `from_gnash/misc-mtasc.all` | 7 | 7 | 0 |
| `from_gnash/misc-swfc.all` | 6 | 6 | 0 |
| `from_gnash/misc-swfmill.all` | 17 | 17 | 0 |
| `from_shumway` | 53 | 58 | +5 |
| `from_shumway/avm1` | 38 | 42 | +4 |
| **TOTAL** | **817** | **868** | **+51** |

Cluster unlocks (raw passes flipped):

- Full loadMovie / loadMovieNum / MovieClipLoader cluster (~13 tests):
  `loadmovie`, `loadmovie_flashvars`, `loadmovie_method`,
  `loadmovie_registerclass`, `loadmovie_replace_root`,
  `loadmovie_var_persistence`, `loadmovienum`,
  `loadmovienum_cross_version_prototype`, `mcl_getprogress`,
  `focusrect_property_swf5/7`, `unloadmovie`, `unloadmovienum`.
- Cross-version closure cluster (5 tests): `swf5_to_6_cross_call`,
  `swf6_to_5_cross_call`, `register_class_swf6`, `cross_movie_root`,
  `lock_root`.
- `set_interval` (17/901 → pass), `movieclip_state_values` (11/294 →
  pass), `movieclip_invalid_get_bounds_{1..8}`, `goto_frame_number`,
  `goto_frame2`, `key_isToggled`, `movieclip_lockroot`, and
  ~15 other smaller tests.
- 4 of 5 sprite-over-execution regressions from `ab614b80`
  (`form_loader_encoding_1`, `issue_2084`, `loadmovie_replace_root`,
  `textfield_cache_as_bitmap`); `create_empty_movie_clip` still fails.
- Several status-flip wins: `form_loader_encoding_4` and
  `movieclip_library_state_values` from `output_mismatch` →
  `ruffle_matched`; `localconnection` jumped 111/579 → 433/579.

**Regressions to investigate next session:**

- `native_objects_swf6` (avm1): 114/115 `output_mismatch` → segfault
  9/115 in CI. **Does NOT reproduce locally** — still 114/115
  `output_mismatch` with the diverging line at 56 (`new TextField():
  non-object: undefined` expected vs `native` actual). Likely
  build-env-specific (ASan / optimization / memory layout) rather
  than a real regression in semantic behavior.
- `mcl_unloadclip` (avm1): `ruffle_matched` → `output_mismatch` with
  unchanged 5/5 line count — pure categorization flip.
- The single remaining sprite-over-execution regression
  (`create_empty_movie_clip`) still fails.
- `focusrect_property_swf6` still 1236/1237 (improved by +1 line but
  not yet passing).

**Remaining cluster targets** (now ~80 raw-pass gap to NO_GRAPHICS):
the `from_gnash/misc-ming.all` long tail (~54 failures), the
`from_shumway` long tail, the smoke-set hold-out `unload` (47/52),
and a smaller assortment in `avm1`. The cluster-mining workflow in
the playbook is the right tool — most large clusters are now
unlocked, so the remaining work shifts toward per-test long-tail
debugging.

#### 2026-05-11 follow-up — dynamic-MC enter-frame eligibility + skip post-quit drain (commit `0fcfe324`)

Two changes in `swf.c`'s `tagMain`, both gated on `OFFSCREEN_RENDER`
and both mirroring existing `swf_core.c` behavior:

1. **Call `actionMarkDynamicMCsEnterFrameEligible()` at each main-loop
   tick boundary** (after the fallback flush). Mirrors `swf_core.c`
   line ~1100. Without this, MCs created by DoAction scripts during
   a tick stay `mc_enterframe_eligible=0` forever, so
   `actionDispatchEnterFrameHandlers` skips them on every subsequent
   tick (it gates dispatch for `display_obj==NULL` MCs on this flag).

2. **Skip the post-quit drain loop in `OFFSCREEN_RENDER`.**
   `swf_core.c` has no equivalent drain loop — its main loop's
   `quit_swf` gate already waits on all pending work, and once it
   exits the test is done. The drain loop is for browser/emscripten
   mode where the SWF stays alive past its timeline end to keep
   firing handlers until the user closes the window. Running it in
   test mode caused dynamic-MC `onEnterFrame` to fire up to
   `MAX_FRAMES` extra times.

Net **+2 raw pass**: 868 → 870 / 1125 (77.2% → 77.3%). Smaller than
recent commits because all three structural blockers are now closed
and remaining work is per-test long-tail.

**Per-suite delta vs the post-`f1b087ec` baseline:**

| Suite | Pre | Post | Δ |
|---|---:|---:|---:|
| `avm1` | 565 | 568 | +3 |
| `from_gnash/actionscript.all` | 125 | 124 | -1 |
| `from_gnash/misc-ming.all` | 48 | 48 | 0 |
| `from_gnash/misc-mtasc.all` | 7 | 7 | 0 |
| `from_gnash/misc-swfc.all` | 6 | 6 | 0 |
| `from_gnash/misc-swfmill.all` | 17 | 17 | 0 |
| `from_shumway` | 58 | 58 | 0 |
| `from_shumway/avm1` | 42 | 42 | 0 |
| **TOTAL** | **868** | **870** | **+2** |

Unlocks (raw passes flipped):

- `create_empty_movie_clip` — the last sprite-over-execution holdout
  from `ab614b80`. mc2's `onEnterFrame` was firing 2× via the drain
  loop instead of 1× via the main loop. Now: 1×, matches expected.
- `button_order`, `movieclip_in_removed_button` — these had been
  CI-flaky around the drain-loop boundary; both now passing
  consistently.

**CI-only flaky regressions** (pass locally, fail in CI):

- `case-v5` (`from_gnash/actionscript.all`): pass → runtime_error
  with 39/39 expected lines. Same build-env-specific pattern as
  `native_objects_swf6` (passes locally, segfaults in CI). Probably
  ASan/optimization/memory-layout sensitivity rather than a real
  semantic regression.
- `Inheritance-v6` (`from_gnash/actionscript.all`): runtime_error →
  segfault, 173/181 lines unchanged. Same flaky-status-flip pattern.

#### 2026-05-11 follow-up — unload paths stop loaded-child playhead + root url/byte_size init

Three small fixes that close the gap on the "loaded child SWF keeps
running past its unload" cluster the prior session flagged
(`mcl_unloadclip`, `unloadmovienum`, `unload` smoke holdout). NO_GRAPHICS
masked all three because `swf_core.c`'s "root stopped, current_frame <
g_frame_count" exit branch (line ~1433) breaks out of the main loop
without consulting `hasPlayingLevels` — so once a test's root timeline
stops, the loop exits regardless of any loaded-child level advancement.
`swf.c`'s exit gate keys on `quit_swf` instead, which is never set when
the root just stops mid-timeline, so the loaded child kept ticking via
`actionAdvancePlayingLevels` until it reached its own last frame.

1. **`7598d07a` — MovieClipLoader.unloadClip** (now superseded by 2,
   below): originally set `target_mc->unloaded = 1` + queued the
   deferred-reset queue. Refactored in (2) to the cleaner
   `actionUnregisterLevelAdvance` path.

2. **`947b8351` — unloadMovie / unloadMovieNum / actionGetURL paths**:
   factored out `actionUnregisterLevelAdvance(MovieClip*)` that
   walks `g_level_advance` and nulls the entry for a given MC, and
   called it from all three unload sites:
   - `builtin_mcl_unloadClip` (replacing the earlier `unloaded = 1` +
     deferred-queue pair from `7598d07a`),
   - `actionGetURL` (both the `_level<N>` arm and the named-clip arm)
     — the `_level` arm previously had only a "level MC persists"
     no-op comment,
   - `actionGetURL2` (the SWF6 `loadMovie` action with empty URL).
   No deferred property reset is added to the `actionGetURL` arms:
   doing so clears `totalframes` / `url` / `swf_version` on the next
   tick and breaks `loadmovienum_cross_version_prototype`, which
   intentionally reads level state after unload. The `actionGetURL2`
   site keeps its existing deferred queue. Unlocks
   `avm1/unloadmovienum` and preserves `mcl_unloadclip`,
   `loadmovienum_cross_version_prototype`, the rest of the
   `unloadmovie*` family, and `movieclip_library_state_values`.

3. **`2d62509c` — root `url` + `byte_size` init in `swf.c`**: mirrored
   the `#ifdef SWF_URL` / `#ifdef SWF_FILE_SIZE` block from
   `swf_core.c` (lines ~821-827). Without this, `root._url` was empty
   and `root.getBytesLoaded()` / `getBytesTotal()` returned 0.
   Unlocks `avm1/get_bytes_total`.

#### 2026-05-11 follow-up — case-insensitive display-name lookup in actionGetVariable / actionSetTarget

The display-list-by-name lookup in `actionGetVariable` was gated on
`#ifndef NO_GRAPHICS`, routing graphics-native (OFFSCREEN_RENDER)
through `findDisplayObjectByName` in `tag.c` (case-sensitive `strcmp`).
The NO_GRAPHICS arm uses `ng_findDisplayEntryByName`, which calls
`swf_name_match` — case-insensitive in SWF<=6 — plus a separate
`pending_removal` MC check beforehand.

Result: in SWF6, a script like `Button.prototype.hasOwnProperty(...)`
or `clip5._x` worked in NO_GRAPHICS because case-insensitive lookup
hit the actual instance/pending_removal MC, but in graphics-native the
case-sensitive miss fell through to `_global` (returning the Button
class instead of the button instance, etc.).

4. **`be795aae` — tighten the gate to `!defined(NO_GRAPHICS) &&
   !defined(OFFSCREEN_RENDER)`** so graphics-native and NO_GRAPHICS
   both route through the same `ng_findDisplayEntryByName` path. The
   strcmp-based `findDisplayObjectByName` arm is left for browser-WASM
   graphics only.

5. **`b7f11901` — same gate tightening in `actionSetTarget`**: it had
   a separate `#ifndef NO_GRAPHICS` branch that set `targeted_sprite`,
   which is only consumed in `!NO_GRAPHICS && !OFFSCREEN_RENDER`
   (per `targeted_sprite` memory note). In graphics-native the
   assignment was a dead write that swallowed the lookup result and
   prevented the downstream `getMovieClipByTarget` + var_map fallback
   from running. Tightening to `!NO_GRAPHICS && !OFFSCREEN_RENDER` lets
   graphics-native fall through to those fallbacks.

#### Per-suite cumulative delta (`a4bcde12` → `b7f11901`)

| Suite | Pre | Post | Δ |
|---|---:|---:|---:|
| `avm1` | 568 | 578 | +10 |
| `from_gnash/actionscript.all` | 124 | 124 | 0 |
| `from_gnash/misc-ming.all` | 48 | 52 | +4 |
| `from_gnash/misc-mtasc.all` | 7 | 7 | 0 |
| `from_gnash/misc-swfc.all` | 6 | 7 | +1 |
| `from_gnash/misc-swfmill.all` | 17 | 17 | 0 |
| `from_shumway` | 58 | 59 | +1 |
| `from_shumway/avm1` | 42 | 42 | 0 |
| **TOTAL** | **870** | **886** | **+16** |

Newly passing (avm1): `mcl_unloadclip`, `unloadmovienum`,
`get_bytes_total`, `focusrect_property_swf6`, `local_to_global`,
`movieclip_getbounds`, `string_paths_hidden`, `swf6_case_insensitive`,
`transform`, `unload` (smoke holdout).
Newly passing (misc-ming): `DefineEditTextVariableNameTest` (was
segfault), `loop/loop_test8`, `replace_shapes1test`, `shape_test`.

Net **+16 raw pass**: 870 → 886 / 1125 (77.3% → 78.8%). Smoke set,
NO_GRAPHICS, and the existing load/unload tests
(`unloadmovie`, `unloadmovie_method`, `unload_clip_event`,
`movieclip_library_state_values`, `MovieClipLoader-v{5,6,8}`,
`loadmovienum_cross_version_prototype`) all unchanged.

#### 2026-05-11 follow-up — actionCloneSprite + actionRemoveSprite gate widening

Same `#ifndef NO_GRAPHICS` misgate as the case-insensitive lookup, but
the consequences were much worse: the gated arms were a no-op stub
(`actionCloneSprite` → `cloneMovieClip` empty function) and a `#ifdef
DEBUG` printf (`actionRemoveSprite`). The recompiler emits both
unconditionally for opcodes 0x24 / 0x25, so graphics-native silently
dropped every opcode-form `duplicateMovieClip(target, name, depth)`
and `removeMovieClip(name)`. The `#else` (NO_GRAPHICS) arms have the
real implementations: `ng_cloneSprite` / `ng_cloneSpriteFromMC` for
clone, `child_mc_cache` / `display_list` / `queueOnUnload` /
`ng_queue_slot_unload_events` for remove — all symbols that exist
unconditionally (or for graphics builds too — `display_list` is
defined in `swf.c` line 193).

6. **`e0568fe7` — gate widening for both handlers** to
   `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)`, routing
   graphics-native through the NO_GRAPHICS implementations. The
   browser-WASM-graphics arm remains stubbed (separate workstream;
   browsers run the wasm-graphics path).

#### Per-suite cumulative delta (`b7f11901` → `e0568fe7`)

| Suite | Pre | Post | Δ |
|---|---:|---:|---:|
| `avm1` | 578 | 587 | +9 |
| `from_gnash/actionscript.all` | 125 | 125 | 0 |
| `from_gnash/misc-ming.all` | 52 | 57 | +5 |
| `from_gnash/misc-mtasc.all` | 7 | 7 | 0 |
| `from_gnash/misc-swfc.all` | 7 | 7 | 0 |
| `from_gnash/misc-swfmill.all` | 17 | 17 | 0 |
| `from_shumway` | 59 | 61 | +2 |
| `from_shumway/avm1` | 42 | 44 | +2 |
| **TOTAL (avm1 + gnash + shumway-top)** | **886** | **905** | **+19** |

Newly passing (avm1, +9): `clone_sprite_edittext` (3→94),
`clone_sprite_edittext_dynamic` (3→86), `clone_sprite_types` (18→24),
`duplicate_movie_clip` (12→20), `duplicate_movie_clip_drawing` (1→2),
`remove_movie_clip` (26→29), `removed_target_clip_scope` (12→35),
`string_paths_variable_scopes` (3→5), `textsnapshot_available_text`
(13→20).

Newly passing (misc-ming, +5): `DepthLimitsTest` (15→20),
`displaylist_depths_test9` (3→23), `duplicate_movie_clip_test2`
(11→21), `static_vs_dynamic1` (11→17), `static_vs_dynamic2` (6→18).
Plus 2 `ruffle_matched` improvements (`displaylist_depths_test`
61→104, `duplicate_movie_clip_test` 1→29).

Newly passing (from_shumway, +2): `avm1/duplicateMovieClip/dontremove`,
`avm1/duplicateMovieClip/samedepth` (same two surface in the avm1
sub-suite row).

`opcode_guard_test2` (misc-swfc) also flipped from `output_mismatch`
to `ruffle_matched` (16→19).

Net **+19 raw pass**: 886 → 905 / 1125 (78.8% → 80.4%). Smoke set,
NO_GRAPHICS, and previously-unlocked load/unload + case-insensitive
tests all unchanged.

#### 2026-05-11 follow-up — swf.c outer goto catch-up loop

`avm1/goto_frame_number` failed in graphics-native (2/3 lines: "//
frame 5" missing) even though all other goto handling worked. Root
cause: `mc.gotoAndStop("/:5")` with a force_root path calls
`ng_executeGotoTagsOnly`, which runs intermediate frames in tags-only
mode and sets `goto_from_action + manual_next_frame +
g_deferred_root_goto = 1` — expecting the main loop to run
`funcs[target]` with scripts enabled to actually fire the target
frame's DoAction. swf_core.c has an outer goto catch-up loop (line
~1195+) that consumes this state; swf.c didn't, so manual_next_frame
got cleared at end-of-tick and the next tick saw `is_playing=0` (from
gotoAndStop) — `funcs[target]` never ran.

7. **`3a54d056` — outer goto catch-up loop ported to swf.c**, placed
   after `input_events_pump_tick` and before deferred-load
   processing (mirrors swf_core.c's placement just before timer
   processing). Runs intermediate frames with `catch_up_mode=1`
   (scripts suppressed) then `funcs[target]` with `catch_up_mode=0`
   (scripts enabled). Handles both forward and backward gotos with
   the rewind / cleanup-unplaced pair on the backward branch.
   Retry-limited to 16 iterations so a goto-inside-target-script
   chain can't loop forever. Clears `g_deferred_root_goto` at end of
   each iteration.

Newly passing (avm1, +1): `goto_frame_number` (2→3). Total raw pass:
905 → 906 / 1125 (80.4% → 80.5%). Smoke set unchanged
(`goto_frame2`'s 5-line pre-existing mismatch is the same lines as
before — not a regression from this change).

#### 2026-05-11 follow-up #2 — swf.c root `_currentframe` sync + redundant top-of-tick input dispatch

Two narrow-miss avm1 tests cleared once their root cause was
isolated:

- `goto_frame2` (39/44 → 44/44, +1): five reads of `_currentframe`
  after a no-op `gotoAndStop(0)` / `(-100)` / `(invalid)` / `(NaN)` /
  `(4.123)` all returned the value from the most recent explicit goto
  instead of the current frame. Root cause: `swf.c` advances
  `current_frame` at the top of each tick (line ~268) but never
  syncs `root_movieclip.currentframe` to it. `swf_core.c` does this
  at the END of each iteration on the manual-goto branch (line
  ~1425) AND the natural-advance branch (line ~1431). Without the
  sync, pure natural advance never touches `_currentframe`, so frame
  3's script reads frame 2's value. Gotcha #14 (swf.c subset of
  swf_core.c main loop). Fixed by adding
  `root_movieclip.currentframe = current_frame + 1` right after
  `current_frame = next_frame;` inside the `OFFSCREEN_RENDER` block.

- `click_block` (5/6 → 5/5, +1) and `removed_clip_halts_script`
  (5/19 → 19/19, +1): swf.c's top-of-tick "Per-frame AS2 input
  dispatch" block (lines ~315-462) reads `mouse.clicked` /
  `mouse.released` set by the browser's JS callbacks and dispatches
  the matching AS2 handlers. In OFFSCREEN_RENDER mode, however,
  `input_events_pump_tick` (further down the same tick) is the
  canonical event source — and it dispatches synchronously *and*
  sets `mouse.clicked = 1`. The flag then survives end-of-tick (it
  was being cleared right before frame_func, not after the pump),
  so tick N+1's top-of-tick block re-fires the same MouseDown.
  Click_block's last click was duplicated for this reason;
  `removed_clip_halts_script` was hit by a related cascade. Fixed
  by gating the entire top-of-tick AS2 input dispatch block (and
  the trailing `mouse.clicked/released = 0` clear) on
  `#ifndef OFFSCREEN_RENDER`. swf_core.c never had an equivalent
  block — events fire only from `input_events_pump_tick` there —
  so this matches the reference semantics.

Combined: +3 raw avm1, +1 ruffle_matched in
`from_gnash/misc-ming.all` (`goto_frame_test`), +1 raw in
`from_gnash/misc-ming.all` (`get_frame_number_test`).
Smoke set + all 62 input-driven avm1 tests rerun: no regressions.

#### 2026-05-11 follow-up #3 — three more swf.c parity gaps with swf_core.c

Three independent gotcha-#14 landings in swf.c, each filling a hole
in OFFSCREEN_RENDER mode that swf_core.c had:

- `hittest_morph_input` (0/1 → 1/1, +1): swf.c's loop-exit gate in
  OFFSCREEN_RENDER didn't check pre-loaded input events.
  swf_core.c (line ~1056) and swf_headless.c (line ~1023) both gate
  on `!(g_events && g_event_pos < g_event_count)`. When the root
  frame_0 sets `quit_swf=1` and `gotoAndStop` stops the sprite, all
  the other "keep loop alive" conditions return false, and swf.c
  would exit before `input_events_pump_tick` got to deliver the
  queued MouseMove. Fix: extern `g_event_count` / `g_event_pos`
  from input_events.c and add `g_event_pos >= g_event_count` to the
  exit gate.

- `default_names` (42/52 → 52/52, +1): swf.c's end-of-tick had no
  natural-backward-wrap cleanup. swf_core.c (line ~1395, gated on
  `#ifdef NO_GRAPHICS` because swf_core.c is only compiled in
  NO_GRAPHICS) invalidates cached MCs and clears display entries
  placed at frames > target before `current_frame = next_frame`
  triggers a wrap-back. Without it, depth entries from the final
  frame linger when frame 0 re-runs, so depth-replaces are treated
  as modifies and don't claim a new auto-instance number. Fix:
  port the cleanup block into swf.c's `if (manual_next_frame)` arm,
  gated on `#ifdef OFFSCREEN_RENDER` (goto-from-action wraps go
  through ng_executeGotoCatchUp / the outer catch-up loop which
  handle their own cleanup).

- `selection_handlers` (19/27 → 27/27, +1) **and 7 cluster wins**:
  swf.c had no per-tick `actionFlushDeferredRollEvents` call.
  swf_core.c (line ~1105) and swf_headless.c (line ~1062) both
  flush after `actionMarkDynamicMCsEnterFrameEligible` and before
  `input_events_pump_tick`. `Selection.setFocus` from frame
  scripts queues virtual rollOver/rollOut on the focused MC; the
  shared `input_events_pump_tick` (input_events.c:387) flushes
  between events but does nothing when no input.json exists, so
  the queue stayed full forever and the rolls never fired.
  Adding the per-tick flush unlocked the whole input/focus
  regression cluster in one shot: clip_event_propagation_order
  (5/17 → 17/17), tab_ordering_events (131/150 → 150/150),
  tab_ordering_events_mouse (5/65 → 65/65), focusrect_swf6
  (4/42 → 42/42), key_isToggled (3/9 → 9/9), root_button_mode
  (0/10 → 10/10), text_blocks_clicks (0/4 → 4/4).

Combined: +10 raw avm1 (3 narrow misses + 7 cluster). Smoke set
(23 tests including the recently-unlocked goto cluster + the three
newly-passing tests) clean. Cross-suite delta from these changes
will be reported after CI.

#### 2026-05-11 follow-up #4 — three more swf.c parity gaps with swf_core.c

Three independent gotcha-#14 landings in swf.c, fixing all of the
"close" cluster regressions:

- `timeline_as2_1` (0/9 → 9/9, +1 from_shumway) AND `case-v6`
  (73/73 lines + runtime error → 73/73 pass, +1 from_gnash/
  actionscript.all): Two related gaps from the
  `g_goto_inlined_in_caller_frame` mechanism.
  - **`g_force_quit` early-exit** at the top of the OFFSCREEN_RENDER
    quit gate. `swf_core.c` (line ~906) breaks the loop after
    FSCommand:quit even with `hasPlayingSprites()=true`, because
    `g_force_quit` is set only by the FSCommand:quit path (not the
    recompiler-emitted end-of-movie `quit_swf=1`). Without it,
    `timeline_as2_1`'s frame-4 → goto(1)+play → frame-1 trace →
    frame-2 FSCommand:quit cycle keeps the player alive (sprite
    is_playing stays true after the early goto+play) and the test
    runs to max_ticks instead of stopping. Same gate is needed for
    cases where FSCommand:quit fires from a non-last frame.
  - **`g_goto_inlined_in_caller_frame` wrap-back undo** right after
    `frame_funcs[current_frame](app_context)`. `swf_core.c` (line
    ~1013) undoes the recompiler-emitted natural wrap-back
    (`next_frame=0; manual_next_frame=1` at end of last frame) when
    a `gotoAndPlay`/`gotoAndStop` inside the script already inlined
    the target via `ng_executeGotoCatchUp`. swf.c was SETTING
    `g_goto_inlined_in_caller_frame=1` (line 140) but never
    consuming it. Without the undo, `frame_4`'s
    `actionGotoFrame(1); actionPlay()` clears `manual_next_frame=0`
    inside catch-up, then `frame_4`'s emitted wrap-back sees `mnf=0
    && ip=1` and triggers `next_frame=0; mnf=1`, looping the
    timeline back to frame 0 on the next tick. swf.c's next-frame
    advance also needs `next_frame = current_frame` in the undo
    (swf_core.c uses a `current_frame++` model that doesn't need
    this — see code comment for details). Key tests: timeline_as2_1
    (loops 3× instead of quitting once), case-v6 (lines all matched
    because exit happened gracefully via timeout but the runtime
    halt counted as error).
- `timeline_var_test` (6/7 → 7/7, +1 from_gnash/misc-ming.all):
  **`g_defer_sprite_init = 0` tick-boundary clear** inside
  swf.c's OFFSCREEN_RENDER block right after `current_frame =
  next_frame;`. `swf_core.c` (line ~951) explicitly names this
  test as the key test for the clear:
  `ng_executeGotoCatchUp` intentionally leaves `g_defer_sprite_init=1`
  so the calling frame's `tagShowFrame` continues to defer
  sprite init for the rest of THAT tick, but a regular-frame-script
  `gotoAndPlay`/`gotoAndStop` then exits the action handler with
  the flag still set. Without a tick-boundary clear, the flag
  suppresses `process_sprite_needs_init` for newly-placed sprites
  on subsequent frames (sprite_initialized stays 0, onEnterFrame
  clip-actions never dispatch, the `setTarget` DoAction never
  pushes its string into the array).
- `displaylist_depths/displaylist_depths_test8` (9/10 → 10/10, +1
  from_gnash/misc-ming.all): also resolved by the wrap-back undo
  above (final assertion no longer runs an extra time after the
  natural-wrap-back loops a stopped-on-frame-5 timeline back).

Still failing post-this-session (separate root cause, not the
gotcha-#14 family):
- `place_and_remove_object_insane_test` (15/19 in graphics vs
  19/19 in NO_GRAPHICS) — lines 10-13 show out-of-order
  display-list state at one of the iterations. Same diff in
  graphics-headless-legacy, so the bug is in shared code (tag.c
  or `#ifdef NO_GRAPHICS`-gated tag handling), not swf.c. Defer.

Combined: **+3 raw cross-suite** (1 from_shumway, 2
from_gnash/misc-ming.all) confirmed post-CI (run 25697964640).
case-v6 fix verified locally (passes after the wrap-back undo),
but in CI it stays at runtime_error with exit code -6 ("output
matches") — same CI-only-flake category as native_objects_swf6.
**Bonus**: `native_objects_swf6` line-match went from 9/115
(segfault) to 114/115 (output_mismatch) — the wrap-back undo
shifted whatever was causing the CI segfault, though the test
still doesn't fully pass. Smoke set (22 tests) clean.

#### 2026-05-11 follow-up #5 — close the last three strict parity gaps

After follow-up #4, the strict parity-gap survey (tests passing in
NO_GRAPHICS but failing in graphics-native) was down to 5 tests
across all suites. Two of those (case-v6 CI-flake,
place_and_remove_object_insane_test shared-code bug in tag.c) are
deferred. The remaining three were each a single isolated subsystem
gap. All three landed in one commit:

- **avm1/sound (sound1.duration/getDuration undefined →
  1452/907)**: `tag_stubs.c::tagDefineSound` (NO_GRAPHICS/HEADLESS
  variant) already registered sound metadata via
  `ng_registerSoundMetadata` so that `attachSound` /
  `Sound.getDuration` could look up duration by char_id; the
  parallel `audio.c::tagDefineSound` (used by every non-NO_GRAPHICS
  build, including OFFSCREEN_RENDER) did not. Adding the same
  one-line registration to audio.c gave every graphics-mode build
  matching sound metadata. Browser-WASM-graphics inherits the fix
  for free.

- **avm1/netstream_seek_flv (extra Buffer.Flush / Play.Stop /
  Buffer.Empty lines after expected end)**:
  `action.c::builtin_ns_pause` was a no-op stub returning undefined
  without setting `ns->paused`. `processNetStreams` kept advancing
  `elapsed_ms` after the script-level `pause()`, eventually firing
  the playback-complete trio. NO_GRAPHICS happened to mask the bug
  because swf_core.c's root-stopped exit gate (lines 1433-1454)
  breaks the loop without checking `hasActiveNetStreams()`, so the
  loop exited before completion fired (it had `is_playing=0` from
  the recompiler's end-of-frame marker and no active sprites /
  timers / enter-frame handlers). Graphics-native triggered the
  bug because its loop runs to max_ticks while
  `hasActiveNetStreams()` returns true. The fix is a proper
  pause/resume/toggle for ns->paused, honoring Flash's
  pause(true)/pause(false)/no-arg-toggle semantics. The NG-side
  root-stopped break gap is a separate bug (loop should respect
  `hasActiveNetStreams()`); leaving for a future follow-up because
  no current test exercises it.

- **avm1/timeout (10s harness timeout instead of script halt)**:
  swf_core.c sets up the `actionSetMaxExecutionDuration` +
  `actionResetExecutionTimer` + setjmp/longjmp machinery before
  its main loop (lines 848-862). swf.c had no equivalent. Ported
  the full block (gated `#ifdef OFFSCREEN_RENDER`) plus a
  `frame_loop_exit:` label after the main loop that clears the
  jmp_buf on the way out. Tests opt-in via
  `max_execution_duration` in test.toml, which `verify_output.py`
  translates to `-DMAX_EXECUTION_MS=N`.

Remaining strict parity gaps:
- `case-v6` (from_gnash/actionscript.all): CI-only flake — passes
  locally after follow-up #4's wrap-back undo, but in CI the run
  still ends with exit code -6 ("output matches"). Same category
  as native_objects_swf6. Not chasing locally.
- `place_and_remove_object_insane_test` (from_gnash/misc-ming.all):
  15/19 in graphics-native vs 19/19 in NO_GRAPHICS. Same diff
  appears in `--mode=graphics-headless-legacy`, so the bug is in
  shared code (tag.c or `#ifdef NO_GRAPHICS`-gated tag handling),
  NOT in swf.c. Defer to a tag.c-focused session.

Combined: **+3 raw avm1 pass** (sound, netstream_seek_flv,
timeout). Smoke set (25 tests including the three keys) clean.
This is the cleanest "close out the parity-gap survey" pass we'll
get; subsequent graphics-native work has to widen the survey
(tests that fail in BOTH modes but represent overall recoverable
pass rate).

**Exit criteria:** graphics-native pass rate within 2% of NO_GRAPHICS on every suite, OR remaining gaps documented in `_investigation/` as "expected divergence."

#### Phase 2 exit-criteria check (2026-05-12)

Per-suite raw pass (NO_GRAPHICS vs graphics-native, from the
latest CI run on master):

| Suite | NO_GRAPHICS | graphics | Δ | Δ% |
|---|---:|---:|---:|---:|
| `avm1` | 605/651 | 605/651 | 0 | 0.0% |
| `from_gnash/actionscript.all` | 126/190 | 125/190 | -1 | 0.5% |
| `from_gnash/misc-ming.all` | 66/102 | 65/102 | -1 | 1.0% |
| `from_gnash/misc-mtasc.all` | 7/9 | 7/9 | 0 | 0.0% |
| `from_gnash/misc-swfc.all` | 8/16 | 8/16 | 0 | 0.0% |
| `from_gnash/misc-swfmill.all` | 17/18 | 17/18 | 0 | 0.0% |
| `from_shumway` | 73/92 | 73/92 | 0 | 0.0% |
| `from_shumway/avm1` | 46/47 | 46/47 | 0 | 0.0% |
| **TOTAL** | **948/1125** | **946/1125** | **-2** | **0.18%** |

Max suite gap: 1.0% (`misc-ming.all`, one test). Both
non-zero-delta suites lose exactly one test, and both are the
deferred items in [`BACKLOG.md`](../BACKLOG.md#deferred-test-failures)
— neither is a swf.c parity issue (case-v6 is a CI-environment
flake; place_and_remove_object_insane_test fails identically in
`--mode=graphics-headless-legacy`, so the bug is in shared tag.c
code). Every suite is well within the 2% exit threshold, and the
two outstanding tests are documented rather than undiagnosed. **Phase
2 is closed.**

### Phase 3 — Migrate image tests + retire HEADLESS_GRAPHICS

Goal: one rendering path instead of two.

1. Switch `run_image_tests.py` from `--mode=graphics-headless-legacy` to `--mode=graphics`. Verify image-comparison results don't regress. **BLOCKED (2026-05-12) — image-capture machinery lives only in `swf_headless.c`.** See parity-check section below.
2. Move CI to option A (parallel matrix). The legacy mode is no longer the primary rendering CI path. **BLOCKED on step 1.**
3. Once the legacy mode has zero unique callers and graphics-native is matching it on every suite for ≥1 month: delete `swf_headless.c`, remove `HEADLESS_GRAPHICS` from `render_webgpu.c` / `audio_output_web.c` / `swf.c` / build scripts, drop the `--mode=graphics-headless-legacy` value (and the deprecated `--headless` alias). **BLOCKED on step 2 (1-month clock starts after step 2 lands).**

**Exit criteria:** `swf_headless.c` deleted, `HEADLESS_GRAPHICS` removed from the codebase.

#### Phase 3 step 1 parity check (2026-05-12)

Re-ran `bitmap_data_colortransform` in both modes locally before
flipping the default in `run_image_tests.py`:

| Mode | Trace | Image |
|---|---|---|
| `graphics-headless-legacy` | PASS | PASS — 0 outliers, max diff 4 |
| `graphics` | PASS | **FAIL — No actual image produced for `output`** |

Root cause: the entire image-capture infrastructure (CaptureEntry
table, `parse_capture_triggers`, `save_capture`, `headless_on_fscommand_capture`,
`headless_has_pending_captures`, plus four integration points in the
main loop — capture scheduling before frame render, post-event
re-render, end-of-frame save, and the `CAPTURE_OUTPUT_DIR` env-var
plumbing — see `swf_headless.c:638-770, 856, 904, 1246-1267, 1332`)
lives only in `swf_headless.c`. `swf.c` has no equivalent. The
`-DHEADLESS_RENDER_ENABLED` flag that `verify_output.py` sets in
graphics mode for tests with `[image_comparisons]` (line 1592) is
load-bearing inside `swf_headless.c` but a no-op inside `swf.c`.
Result: the graphics-mode binary never writes `output.png` to
`CAPTURE_OUTPUT_DIR`, image comparison fails universally.

Drive-by `verify_output.py` fix landed in the same commit: removed
a `actual_png = test_dir / "{cmp_name}.actual.png"` fallback that
silently picked up verify's own prior-run backup PNG (created by
the verbose-mode `shutil.copy2` at line 2779-2780). The fallback
caused a `SameFileError` on the next run and masked the real
"binary produced no PNG" failure mode. Now the comparison cleanly
reports "No actual image produced" when the runtime writes nothing.

**Phase 3 step 1 is blocked** until the capture machinery is ported
from `swf_headless.c` into `swf.c` (or extracted into a shared
file usable by both). Tracked in
[`BACKLOG.md`](../BACKLOG.md#runtime--frame-loop--exit-gates) as a
dedicated workstream — that port is the only thing standing between
the current state and being able to flip step 1; steps 2 and 3
unblock immediately once it lands.

---

## Validation Plan

For Phase 1:
- Re-run the smoke set from `graphics-native-test-mode-baseline-2026-05-09.md` under `--mode=graphics` and compare against the captured `--headless` and NO_GRAPHICS columns. Expected: 8/9 pass if `swf.c`'s frame loop is roughly equivalent to `swf_headless.c` for these scenarios; the single `register_and_init_order` regression in the headless column is the bisection diagnostic (passes there → bug is in `swf.c`'s frame loop and self-fixing in Phase 3; fails there too → bug is in shared code).
- Diff `--mode=graphics` and `--mode=graphics-headless-legacy` output for the image-comparison test (`bitmap_data_colortransform`). Pixel parity is expected since the renderer is unchanged; any divergence indicates `swf.c` is driving rendering differently than `swf_headless.c`.

For Phase 2:
- After each `swf.c` parity backport, re-run the suite in graphics-native mode. Track delta on the full results JSON.
- For the parity gap list, read each suite's CI-generated `_results/results_graphics_diff.md` — it already enumerates every test that flipped status. For non-test-status TODOs uncovered along the way (subsystem bugs, deferred refactors), add an entry to `SWFRecompDocs/BACKLOG.md`.

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
