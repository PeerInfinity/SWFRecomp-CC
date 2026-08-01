# Session 8 · wave 2 · target A — AVM2 `transformed_by_script` gate

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a2e46834e05bf2c2c`
Base: HEAD `1c7c23761`. Patch: `.../scratchpad/wave2/tbs.patch` (2 files, +40 −1).
Nothing committed, nothing pushed, no CI dispatched.

Target B (root-class bindings) NOT taken, per brief.

---

## 1. What changed

Runtime only — no recompiler change. Two files.

**`SWFModernRuntime/include/avm2/avm2_globals.h`** (+6)
* New `uint8_t transformed_by_script;` in `Avm2DisplayObjectExt`, next to the
  other flag bytes (after `running_construct_frame`). The struct is
  zero-initialised at alloc, so no init change was needed.

**`SWFModernRuntime/src/avm2/avm2_display.c`** (+34 −1)

* **Helper** `static inline void mark_transformed_by_script(Avm2DisplayObjectExt*)`
  placed just above `set_rotation_internal` (after `clamp_fixed16`), so every
  set site — the earliest of which is at line 530 — can see it. NULL-tolerant.
* **The one read site / gate**, `apply_place_object`: `if (ext->transformed_by_script) return;`
  immediately after the existing `ext == NULL` guard. Early-return is equivalent
  to Ruffle's `if !flag { … }`: the body has no effects outside the gated region,
  and `name`/`clip_depth` are applied by `instantiate_child` *after* the call, matching
  Ruffle's "purposely omitted" comment. All **eight** of our
  `apply_place_object` callers (`instantiate_child` :1727, `run_place_op` ×2,
  the goto pre-range Modify, the rewind arm, the forward-goto Replace arm, the
  trailing-mods loop) are timeline-apply paths and correspond to Ruffle's five
  gated callers — no caller needs an exemption.
* **Ten set sites**, one line each:

  | # | site | note |
  |---|---|---|
  | 1 | `do_set_x` | inside the `ext != NULL && argc > 0` guard |
  | 2 | `do_set_y` | ditto |
  | 3 | `set_rotation_internal` | first line — **before** the NaN early-return, matching Ruffle `display_object.rs:511` |
  | 4 | `set_scale_x_internal` | first line |
  | 5 | `set_scale_y_internal` | first line |
  | 6 | `do_set_alpha` | inside the guard |
  | 7 | `transform_set_matrix` (`Transform.matrix=`) | after the `ext` null-check |
  | 8 | `transform_set_color_transform` (`Transform.colorTransform=`) | after the `ext` null-check |
  | 9/10 | `set_width_height`, the `ext->edittext != NULL` arm | before its `return`; Ruffle `edit_text.rs:2651/:2667` |

  `.scaleX`/`.scaleY`/`.rotation`/`.width`/`.height` on a non-EditText all reach
  3/4/5 transitively (`do_set_*` and `set_width_height`'s tail are their only
  callers — verified by grep, no timeline code calls the internals; the timeline
  writes `ext->mtx_*` through the separate `apply_place_matrix`).

**Confirmed trap respected:** `do_set_transform` (`DisplayObject.transform = …`,
now :9914) writes `mtx_*` directly and was left **unmarked**, mirroring Ruffle
`avm2/globals/flash/display/display_object.rs:810`. Both `Transform` setters
carry a comment naming the asymmetry so it does not get "fixed" later.

**Deliberately NOT widened** (Ruffle non-set-sites): `visible`, `filters`,
`mask`, `blendMode`, `cacheAsBitmap`, `scrollRect`, `z`/`scaleZ`, and
`base.set_matrix` itself.

**Patch 4 deferred** per the brief: Ruffle `container.rs:1038` also marks the
*displaced* `prev_child` in `replace_at_depth`. Not needed by the target and it
widens into `place_object_replace*`; left as a separate parity item.

Setter-registration audit: `add_getset(… "x"/"y"/"scaleX"/"scaleY"/"rotation"/
"width"/"height"/"alpha"/"transform" …)` exists exactly once, on `DisplayObject`
(`avm2_display.c:12906-12919`). TextField/Sprite/etc. inherit it, so there is no
second setter path that could write a transform without marking. (Hits in
`avm2_filters.c` / `avm2_pixelbender.c` / `avm2_text.c:6988` are filter and
ShaderInput objects, not display objects.)

## 2. Per-test ledger (before → after)

Baseline column = CI `_results/results_graphics.json`, `git_sha 375373786`
(session-7 closeout). "after" = local `--mode=no-graphics` single-test runs in
this worktree, 52 canaries + the target.

### Target

| test | before | after |
|---|---|---|
| `avm2/issue_8630_placeremoveplace_scriptremove` | `output_mismatch` 15/16 | **`pass` 16/16** |

Re-verified the 15/16 baseline in this worktree *before* editing (row 16 only:
`E: 0` / `A: 2.75`), then the identical invocation after → `PASS`. So the flip is
measured, not inferred.

### Canaries — 52 run, **0 regressions**

48 `PASS`, 1 `ruffle_matched`, 3 `output_mismatch`; every non-pass matches its
baseline status **and** its baseline diff size exactly.

| test | baseline | after |
|---|---|---|
| **Tier 1 — measured blast-radius population (all 9 at-risk passers + the sibling)** | | |
| `avm2/issue_8630_placeremoveplace` | pass | PASS |
| `avm2/filter_rewind` | pass | PASS |
| `avm2/place_object_replace_2` | pass | PASS |
| `avm2/loaderinfo_properties` | pass | PASS |
| `avm2/displayobject_width` | pass | PASS |
| `avm2/displayobject_height` | pass | PASS |
| `avm2/instantiation_on_enter_frame` | pass | PASS |
| `avm2/instantiation_on_enterframe_gotoandstop` | pass | PASS |
| `avm2/displayobject_colortransform_nested` | pass | PASS |
| `avm2/displayobject_set_matrix_nested` | pass | PASS |
| `fonts/embed_matching/fallback_preferences` | pass | PASS |
| `from_shumway/timeline/nav/matrix` | pass | PASS |
| `from_shumway/timeline/nav/colorTransform` | pass | PASS |
| `from_shumway/timeline/nav/ratio` | pass | PASS |
| `from_shumway/timeline/nav/ratio2` | pass | PASS |
| `from_shumway/timeline/nav/morphShape` | pass | PASS |
| `avm2/bounds_mode` | output_mismatch 253/269 | MISMATCH **253/269 (identical)** |
| `from_shumway/acid/acid-morph` | output_mismatch 4/6 | MISMATCH **4/6 (identical)** |
| **Tier 2 — setter side (the 10 write sites; flag must be inert)** | | |
| `avm2/displayobject_x` / `_y` / `_alpha` | pass | PASS ×3 |
| `avm2/nan_scale` | pass | PASS |
| `avm2/displayobject_invalid_floats` | pass | PASS |
| `avm2/edittext_width_height` / `edittext_autosize` / `edittext_align` | pass | PASS ×3 |
| `avm2/flash_media_video_setter` | pass | PASS |
| `avm2/displayobject_transform` | output_mismatch 67/89 | MISMATCH **67/89 (identical)** |
| `avm2/blend_transform` | ruffle_matched | RUFFLE_MATCHED |
| **Tier 3 — timeline / goto / place-remove net** | | |
| `avm2/place_object_same_depth_frame` / `place_object_replace` / `place_multiple` | pass | PASS ×3 |
| `avm2/movieclip_goto_overwrite` / `goto_methods` / `remove_dobj` | pass | PASS ×3 |
| `avm2/movieclip_displayevents_timeline` | pass | PASS |
| `avm2/displayobjectcontainer_timelineinstance` | pass | PASS |
| `avm2/displayobjectcontainer_removechild_timelinemanip_remove1` | pass | PASS |
| `from_shumway/timeline/Timeline3` / `4` / `8` / `9` / `timeline_loop` | pass | PASS ×5 |
| **Tier 4 — `regression` suite (mandatory)** | | |
| `regression/avm2_goto_catchup_scale` | pass | PASS |
| `regression/avm2_timeline_solid` / `_gradients` / `_stroke_gradient` / `_text` | pass | PASS ×4 |
| `regression/avm2_morph` | pass | PASS |
| `regression/avm2_simplebutton_click` | pass | PASS |
| `regression/avm2_static_text` | pass | PASS |
| **Silence assertion** | | |
| `avm2/away3d_advanced_shallow_water_demo` | pass, 0/0 lines | PASS (still silent) |

Notes on the three predicted behaviour changes from the brief's §A.5:
* *"a morph's `ratio` freezes once script touches the clip"* — `acid-morph` and
  `from_shumway/timeline/nav/{ratio,ratio2,morphShape}` and `regression/avm2_morph`
  are all unmoved. No corpus test does script-transform + timeline-ratio on the
  same object.
* *"filters stop being re-applied on rewind for script-moved clips"* —
  `filter_rewind` still passes; its clips are not script-transformed.
* *"`visible` from PlaceObject3 stops applying"* — no canary moved.

Regression-suite README audit: greped every
`ruffle-tests/tests/swfs/regression/*/README.md` for rewind/place/transform.
Three files hit (`avm2_findprop_this_resolution`, `avm2_simplebutton_click`,
`avm2_slot_default_template`) and none of them pins timeline-over-script
transform behaviour — the matches are incidental prose ("the only place in the
corpus…", "`bounds_with_transform`"). **No regression-suite README needs updating.**

## 3. Predicted CI delta

**+1**, `mode=graphics`, `categories=all`, `images=false`.

* avm2: 1068 → 1069 pass; `output_mismatch` 128 → 127; effective 1095 → 1096.
* All other suites: no change predicted.
* Confidence high: the target flip is measured locally, and the brief's measured
  17-test blast-radius population (plus 35 more timeline/setter/regression tests)
  was run at exactly the same statuses and diff sizes. As always, an
  in-isolation ledger is a **lower** bound — cross-patch synergy with the other
  wave-2 patches could add more.

## 4. Deviations from the brief

1. **Eight `apply_place_object` callers, not five.** The brief inherited Ruffle's
   caller count; ours has three extra goto-path calls (:2785 pre-range Modify,
   :2848 rewind, :2857 forward Replace, plus the :2889 trailing-mods loop). All
   are timeline applies that Ruffle routes through the same gated function, so
   the single gate still covers them and no caller needed an exemption. Verified
   by reading each one.
2. **Line numbers shifted** vs. the brief (the brief's numbers were pre-patch and
   are all still correct as anchors; e.g. the gate site read `:1640` and landed
   at `:1656` after the helper was inserted above).
3. **Test corpus had to be copied into the worktree.** Upstream test dirs are
   untracked, so only `regression/` existed here. I copied the 45 needed test
   dirs' *source* files (no `Recompiled*` caches) from the main checkout; nothing
   was written back to the main tree. `git status` in the worktree shows only the
   two modified source files — the copies are gitignored.
4. **Baseline for canaries taken from CI `results_graphics.json`, not a stash
   run.** All 52 canaries were run once, patched; 48 passed outright, so only the
   4 non-passing ones needed a baseline comparison, and for those I compared both
   *status* and *diff size* (`matching_lines`/`expected_lines`) against the CI
   baseline — all four identical. This avoided ~50 redundant baseline compiles on
   a machine shared with ~6 agents. The one test whose baseline I *did* re-run
   locally is the target itself.
5. No float-mismatch or slow-compile false failures were observed, so no
   sequential re-runs were needed.

## 5. Suggested commit message

```
avm2: gate PlaceObject re-application on transformed_by_script

Port Ruffle's DisplayObjectFlags::TRANSFORMED_BY_SCRIPT to the AVM2
display list. Once ActionScript writes a transform attribute to a
display object, timeline PlaceObject tags stop applying to it — Ruffle
display_object.rs:2514, "PlaceObject tags only apply if this object has
not been dynamically moved by AS code."

One new sticky uint8_t on Avm2DisplayObjectExt (never cleared), one
early-return gate wrapping the whole body of apply_place_object, and the
ten AVM2-reachable set sites: x, y, rotation, scaleX, scaleY, alpha,
Transform.matrix=, Transform.colorTransform=, and EditText width/height.
width/height on non-EditText objects reach the flag transitively through
set_scale_{x,y}_internal, exactly as Ruffle's TDisplayObject::set_width
does.

Deliberately NOT set: DisplayObject.transform = ..., which writes the
matrix directly and never touches the flag in Ruffle either (only the
Transform object's own setters do). Also not set: visible, filters,
mask, blendMode, cacheAsBitmap, scrollRect.

Fixes avm2/issue_8630_placeremoveplace_scriptremove row 16: a child that
survives a gotoAndStop rewind, whose x the script had zeroed, was being
stomped back to its placement matrix. 15/16 -> 16/16.

Deferred as a separate parity item: Ruffle container.rs:1038 also marks
the displaced prev_child in replace_at_depth.

Canaries (52, local, no regressions): the full measured blast-radius
population (issue_8630 x2, filter_rewind, from_shumway timeline/nav
matrix/colorTransform/ratio/ratio2/morphShape, place_object_replace_2,
loaderinfo_properties, displayobject_width/height,
instantiation_on_enter_frame{,_gotoandstop},
displayobject_{colortransform,set_matrix}_nested,
fonts/embed_matching/fallback_preferences), the setter-side set, the
timeline/goto net, the regression suite's eight AVM2 timeline tests, and
the away3d_advanced_shallow_water_demo silence assertion. bounds_mode,
acid-morph, displayobject_transform and blend_transform stay at their
baseline statuses with byte-identical diff sizes.

Co-Authored-By: Claude Fable 5 <noreply@anthropic.com>
Claude-Session: https://claude.ai/code/session_01TQjLqdJcGxSfyAFAhSECvA
```

## 6. Artifacts

* Patch: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/fc353b12-21e0-448b-a078-5acd5f22bb2e/scratchpad/wave2/tbs.patch`
* Per-test logs + `summary.txt`: `…/scratchpad/wave2/patched/`
* Canary list / runner: `…/scratchpad/wave2/tbs/`
