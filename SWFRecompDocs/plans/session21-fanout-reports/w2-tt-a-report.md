# w2-tt-a: slot A from w1-trace-tail (SimpleButton empty states, orphan-first frame scripts, `has_end_tag`)

**New files:** none. The patch touches 3 existing files. Staging this report and `w2-tt-a.patch` is
up to the coordinator.

**Patch:** `SWFRecompDocs/plans/session21-fanout-reports/w2-tt-a.patch`. It is built on master
`835d9f539` and `git apply --check`s clean on the main tree. The worktree is
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w2-tt-a`, branch `s21-w2-tt-a`, and nothing is
committed.

## Verdict: +2 effective, 0 regressions in the canary set (graphics mode)

| test | baseline (results_graphics) | with patch (`--mode=graphics`) |
|---|---|---|
| `avm2/simplebutton_childevents_multichild` | output_mismatch 33/152 | **RUFFLE_MATCHED** |
| `timeline/missing_frame_scripts` | output_mismatch 12/22 | **PASS** 22/22 |

**CI:** this includes recompiler emission (`abc_timeline.cpp`), so dispatch
`mode=graphics categories=full`. The runtime hunks are `avm2_display.c` only (AVM2), so no
no-graphics-specific run is needed.

**Rule 3:** multichild is `known_failure`, and it moves toward Flash's `output.txt`. Every changed
line is an `instanceN` name where Flash and Ruffle already agree.

## Patch scope (3 files, +35/−10)

1. **`SWFModernRuntime/src/avm2/avm2_display.c` `button_create_state`: the `if (n == 0) return NULL;`
   line is removed.**
   - A state with no records now falls through to the existing wrapper path. That path builds an
     empty `Sprite`, and `button_construct_states` names it (the Ruffle
     `avm2_button.rs::create_state` + `fire_state_events` rule), so empty over/down/hit states
     consume `instanceN` numbers.
   - Side effect, also Ruffle-exact: `overState`/`downState`/`hitTestState` read back an empty
     Sprite, not `null`.
   - A button whose hit state is empty is now unpickable, because the pick's
     `btn_hit ?: btn_up` fallback no longer triggers. That matches Ruffle's
     `mouse_pick_avm2` (hit area only). `regression/avm2_simplebutton_click`, `button_hittest` and
     `mouse_pick_button_mode` all still pass.
2. **`avm2_display.c` `avm2_display_run_tick`: the FRAME_SCRIPTS phase now runs orphans before the
   stage.**
   - This matches our own Enter and Construct phases, and Ruffle's
     `frame_lifecycle.rs::run_all_phases_avm2`.
   - This is the S4 cause that was open for four sessions, diagnosed in `w1-trace-tail-report.md` §3.
3. **`has_end_tag` (S3):**
   - `abc_timeline.cpp`: `Timeline::has_end_tag` is set on `TAG_END` in `scanStream`, and the
     emitter appends a trailing `, 1` **only** for a timeline without an End tag.
   - `avm2_abc.h`: a trailing `uint8_t no_end_tag` on `Avm2TimelineData`. The sense is inverted on
     purpose: the zero default, and any stale `RecompiledABC` built before this field existed, keep
     today's looping behaviour.
   - `determine_next_frame`: returns `NEXT_FRAME_SAME` when `no_end_tag` is set, matching Ruffle
     `movie_clip.rs:1371`.

## Generated-C identity

The main-tree recompiler and the patched recompiler were each run on the same 9 SWFs, and the
outputs compared with `diff -r`:

- **7 are byte-identical:**
  - `avm2/orphan_movie_complex`
  - `avm2/simplebutton_childevents`
  - `avm2/displayobject_getrect`
  - `avm2/loader_load`, which includes a child SWF
  - `timeline/frame_script_cleanup`
  - `avm1/hitarea_sweep`
  - `from_gnash/misc-ming.all/masks_test`
- **2 differ by exactly one token**, the `, 1` on the End-less timeline:
  - `timeline/missing_frame_scripts` (char 13)
  - `avm2/displayobjectcontainer_stopallmovieclips_nonconstructed` (char 1, 5 frames)

A corpus scan of every `.swf` (including Loader children) found that these are the **only two**
AVM2-side multi-frame timelines without an End tag. The scanner decompresses CWS/ZWS and walks
DefineSprite bodies. The End-less timelines with one frame or fewer also gain `, 1`, but the
runtime rule there is already `SAME`, so that is a no-op for them.

## Canaries: all `--mode=graphics`, sequential, `--recompile` on first use in the worktree

**Every status matches baseline**, apart from the 2 headline flips. The 8 non-`pass` canaries were
also A/B'd on **raw output**: baseline = the patch minus its `avm2_display.c` hunks, same session.
**All 8 are byte-identical:**
- `simplebutton_childevents_script_order` (RM)
- `displayobjectcontainer_stopallmovieclips_nonconstructed` (RM)
- `loader_events_2` (RM)
- `loader_load` (MM)
- `timeline/frame_script_button_order` (RM)
- `swf_9_event_goto_frame_script` (RM)
- `swf_9_frame_script_dynamic_goto` (RM)
- `from_shumway/as3-loader/events/loader-events` (MM 5/36, still 7 ours-only)

**Results by group (66 canary tests plus the 2 headline tests):**
- **avm2 SimpleButton/button (21 besides the headline): all pass.**
  - `button_bounds`, `button_hittest`, `button_nested_frame`, `button_nested_frame_simple`,
    `goto_button_nested_framescript`, `mouse_pick_button_mode`
  - `simplebutton_added_to_stage`, `_childevents`, `_childevents_nested`, `_childevents_sprite`,
    `_childprops`, `_childshuffle`, `_constr`, `_constr_childevents`, `_constr_params`,
    `_mouseenabled`, `_multi_children`, `_soundtransform`, `_structure`, `_symbolclass`
  - `_childevents_script_order` stays RM, byte-identical.
- **avm2 orphan/loader/timeline-structure: all pass or unchanged.**
  - Pass: `orphan_movie_complex`, `orphan_movie_reorder`, `orphan_removeobject`, `goto_on_orphan`,
    `loader_events`, `loader_loadbytes_events`, `loaderinfo_events`, `loader_reuse`,
    `movieclip_frameconstruct_skipped`, `stage_framerate_nan`
  - Unchanged: `loader_events_2` (RM), `loader_load` (MM), `stopallmovieclips_nonconstructed` (RM)
- **timeline (the whole suite, 16 besides the headline): all pass or RM unchanged.**
  - Pass: `clip_action_no_key_code`, `frame_label_count_oom`, `frame_script_cleanup`, `2`, `3`,
    `_goto`, `_goto2`, `frame_script_construct`, `scene_count_oom`,
    `swf_9_frame_script_button_order`, `swf_9_frame_script_cleanup_goto`, `_goto2`,
    `swf_9_frame_script_dynamic_goto_2`
  - RM, byte-identical: `frame_script_button_order`, `swf_9_event_goto_frame_script`,
    `swf_9_frame_script_dynamic_goto`
- **regression (15, the AVM2 rows near the change): all pass.**
  - `avm2_agi_shell`, `avm2_child_simplebutton`, `avm2_goto_catchup_scale`, `avm2_loader_stub`,
    `avm2_morph`
  - `avm2_parent_child_render`, `_static_text`, `_symbol_stride`, `_symbolclass_domain`
  - `avm2_simplebutton_click`, `avm2_static_text`
  - `avm2_timeline_gradients`, `_solid`, `_stroke_gradient`, `_text`
- **Deliberately not run.** The other 18 `regression/avm2_*` rows were dropped mid-run, by
  stopping and relaunching the runner. They are GC, slot, typed-value, reflection,
  SharedObject/LocalConnection/ExternalInterface, embed/tolerant-verify, BitmapData-draw and
  graphics-runtime fixtures. None of them has a SimpleButton, an orphan-with-framescript or an
  End-less timeline.
- **Render canary.** No `render_canary.py` pass was run: no render code changed. The empty wrapper
  states draw nothing. CI's graphics run covers the rest.

## Notes for whoever lands it

- The worktree needs `SWFRecomp/build` rebuilt. That is done in this worktree, Release, matching
  main.
- A stale `RecompiledABC` without the new field is safe by construction: the zero default means
  "has End tag".
- Upstream alignment: `determine_next_frame` also has Ruffle's preload-chunk arm, which we do not
  model. Unchanged here.
- Follow-on lead (unclaimed): with orphans first in FRAME_SCRIPTS, Loader content and
  script-created unattached clips now run their frame scripts before the stage's every tick. The
  loader rows above are unchanged, but the next `categories=full` run is the real sweep; watch the
  `from_shumway/as3-loader` rows.
