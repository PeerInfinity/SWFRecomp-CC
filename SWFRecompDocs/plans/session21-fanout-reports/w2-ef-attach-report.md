# w2-ef-attach — onClipEvent(enterFrame) inside attachMovie'd clips (session 21, wave 2)

**New files. Stage these by name; `git add -u` drops them:**
- `ruffle-tests/tests/swfs/regression/avm1_attach_clipevent_enterframe/create_test_swf.py`
- `ruffle-tests/tests/swfs/regression/avm1_attach_clipevent_enterframe/output.txt` (the Ruffle exporter's trace log)
- `ruffle-tests/tests/swfs/regression/avm1_attach_clipevent_enterframe/test.swf`
- `ruffle-tests/tests/swfs/regression/avm1_attach_clipevent_enterframe/test.toml` (`num_frames = 5`)

Patch: `w2-ef-attach.patch` (`git diff --binary` with the four new files intent-added, so `git apply`
creates them too). Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ad05d983604e31032`.

## Verdict: **GO**. Priced flips: 0 corpus rows, +1 regression row

- **`regression/avm1_attach_clipevent_enterframe`** (new): MISMATCH → PASS in **both** no-graphics and
  `--mode=graphics`. Before the fix both modes printed only `f1..f5`, with zero `ef` lines, for the
  root attach AND the non-root attach.
- **Corpus yield is 0, and by construction.** A tag-level scan of all 5032 FWS/CWS corpus SWFs
  (ZWS: 70, all AVM2/LZMA fixtures except `avm1/movieclip_state_values`) finds **no test directory** that
  has both an `attachMovie` reference and a clip action with the EnterFrame bit. It finds 17 SWFs
  with EF clip actions, and none of them references attachMovie. The only co-occurrences are the
  `_swfbridge/livetest/dj_*` Doodle Jump harnesses, which are not a corpus suite. This matches
  w2-px-c's finding. Every new code path is gated on `g_any_clip_ef_placed` plus a DisplayObject
  flag that only `ng_attachMovie` sets, so the change is inert for the whole corpus. The value is
  real-content correctness (Doodle Jump-style games built on `attachMovie` + `onClipEvent`) and native
  parity with the browser build, which already has a pass for this.

## Mechanism (premise check)

The brief's premise holds, but the w2-px-c probe was aimed at the wrong code. Those four browser gates
were never reachable natively:

1. `ng_attachMovie` (tag_stubs.c) gives the attached clip a **standalone heap `DisplayObject`** that
   lives in no display-list array. Root attaches are never registered anywhere. A non-root attach
   gets a *copy* entry in the parent's list, but that copy is never `sprite_initialized`, so the walk
   skips it and does not recurse. Frame 0 runs into that struct's `sprite_display_list`, and the
   attach-init drain (`process_sprite_needs_init_public`) correctly sets the child's
   `sprite_initialized = 1` and attaches its clip actions. Probe: `_root.a.inner` resolves and `lib`'s
   frame script runs, so instantiation is fine.
2. Three per-tick passes, however, walk **only the root `display_list`**:
   - `upgrade_sprite_initialized` (1→2): the child stays at 1 forever.
   - `dispatch_enterframe_clip_actions` (gather needs ≥2): never fires.
   - `hasClipEnterFrameHandlers`: in a 1-frame-root movie the past-last-frame loop quits at once.
3. The browser build already has `upgrade_attached_clip_initialized` and
   `dispatch_attached_clip_enterframe`. Un-gating them natively cannot work, for two reasons. First,
   the native `tagShowFrame` takes the `NO_GRAPHICS||OFFSCREEN` branch, so the `!NO_GRAPHICS&&!OFFSCREEN`
   gate at ~7432 is dead code. Second, in swf_core.c's past-last-frame branch the dispatch is a
   direct `dispatch_enterframe_clip_actions(display_list…)` call, not `tagFlushPendingEnterFrame`.
   The browser passes also recognise "standalone" by "not inside the root display_list". Natively that
   would also match every nested timeline clip, whose `display_obj` points into a sprite list, and it
   would double-fire.

## Patch scope (runtime, both CI modes; browser behaviour unchanged)

- `include/libswf/swf.h`: new trailing `DisplayObject.attach_standalone` field.
- `tag_stubs.c::ng_attachMovie`: set `attach_standalone = 1` on the calloc'd display_obj (one line).
  Clone (`duplicateMovieClip`) standalone structs are deliberately **not** flagged, because their root
  registration shares the child list and is already walked.
- `tag.c`, next to `gather_clip_ef_entries`:
  - `collect_attached_standalone()` (native only): scans `child_mc_cache` for live MCs whose display_obj
    is flagged. It skips `INT_MIN` / `avm1_removed` MCs and **dedups by dobj**, so two aliasing MCs
    cannot double-fire. Static scratch holds 4096 entries and is consumed before any handler runs.
  - `ng_upgrade_attached_standalone_initialized()`: promotes 1→2 in the flagged lists. It is called at
    the **tick boundary** in swf_core.c and swf.c, right after `g_tick_count++`. That gives the same
    "init tick fires LOAD, not enterFrame" model as timeline clips, and it also covers attaches made
    while the root is stopped or past its last frame, where no `tagShowFrame` runs. It is a no-op in the
    browser build.
  - `dispatch_enterframe_clip_actions` → `_impl(…, include_attached)`. The public signature is
    unchanged (`include_attached = 0`). The new `dispatch_root_enterframe_clip_actions()` gathers the
    root list **plus** every flagged list into the **same flat list** before the place_seq DESC sort,
    so ordering interleaves like Ruffle's global exec list. The oracle confirms this: `ef b`, the newer
    clip, fires before `ef a`. The overflow fallback also recurses over the attached lists.
    `tagFlushPendingEnterFrame` and swf_core.c's past-last-frame site now call the root variant. In the
    browser, `include_attached` is ignored and the existing `dispatch_attached_clip_enterframe` stays.
  - `hasClipEnterFrameHandlers`: also checks the flagged lists (native).
- `ruffle-tests/tests/swfs/regression/README.md`: a new Contents row.
- Mode parity: swf.c and swf_core.c get the identical tick-boundary call. Everything runs through
  shared tag.c code under `NO_GRAPHICS || OFFSCREEN_RENDER`.
- Sibling overlap: none. The new tag.c code sits at ~5220 (clip-EF dispatch) and ~13240
  (`hasClipEnterFrameHandlers`), away from cacheAsBitmap / EditText filters / compose_children, and it
  does not touch action.c scope resolution. The swf.h field is trailing (after `filter_chain`).

## Evidence / tests run (sequential, `SWFRECOMP_COMPILE_TIMEOUT=2400`, worktree copies, `--recompile` on first use)

| test | no-graphics after | graphics after | baseline (graphics results) |
|---|---|---|---|
| regression/avm1_attach_clipevent_enterframe | PASS (before: MISMATCH) | PASS (before: MISMATCH) | new |
| avm1/netstream_play_flv_screen (clip actions + attachMovie) | PASS | PASS (trace; image fail is the pre-existing `blank_render` board row) | pass |
| avm1/movieclip_invalid_get_bounds_6 / _7 (clip actions in sprite + attachMovie) | PASS / PASS | PASS / PASS | pass |
| from_gnash misc-ming.all/register_class/registerClassTest2 (clip actions + attachMovie) | RUFFLE_MATCHED | RUFFLE_MATCHED | ruffle_matched (unchanged) |
| avm1/clip_events, placeobject_all_event_flags, target_clip_removed, issue_2870 (EF clip actions) | PASS ×4 | PASS ×4 | pass |
| avm1/attach_movie, remove_movie_clip | PASS ×2 | PASS ×2 | pass |
| misc-ming duplicate_movie_clip_test, action_execution_order_test4 | RUFFLE_MATCHED ×2 | RUFFLE_MATCHED ×2 | ruffle_matched (unchanged) |
| misc-ming opcode_guard_test, timeline_var_test, event_handler_scope_test | PASS ×3 | PASS ×3 | pass |
| regression: avm1_child_timeline_{advance,frame1_stop,holder_stop,loop}, enterframe_type1_args, root_enterframe_cross_swf_version, mc_event_{type1_args,cross_swf_version}, mc_method_v5_caller_gate, onconstruct_{type1_args,cross_swf_version}, onload_type1_args, onunload_{type1_args,type1_local_frame} | PASS ×15 | PASS ×15 | pass |

Status moves: **none**, except the new regression row. The oracle is the Ruffle exporter
(`~/CC/ruffle/target/release/exporter -f 5 --trace-log`). That binary predates the session-start pull;
nothing in this area moved upstream. The browser (Emscripten) build was **not** compiled locally. In
that build the new code compiles to `(void)include_attached` plus an empty
`ng_upgrade_attached_standalone_initialized`, and all statics and helpers sit under the native `#if`.
The coordinator's wasm-link CI step is the check.

## Refutations

- **"Removing the four browser gates should fix it" → refuted.** The gates are dead code natively (see
  point 3 of the mechanism), and the browser's "standalone" test would double-fire natively.
- **"Only root attaches are affected" → refuted.** The fixture's non-root attach (`h.attachMovie`
  into a createEmptyMovieClip holder) failed identically before the fix, because the parent-list
  registration copy is never `sprite_initialized`.

## New unclaimed leads

1. **AS2 `onEnterFrame` on a nested child of an attachMovie'd clip** (e.g. `a.inner.onEnterFrame = f`)
   probably never fires natively. `enterframe_eligible` is armed only by
   `set_enterframe_eligible_recursive(display_list…)` (root walk) and by `advance_sprite_frames`, and
   neither walks standalone lists. I did not probe it or fix it (out of scope). The same
   `collect_attached_standalone` helper would feed a fix. It needs a Ruffle-oracle fixture.
2. **Timeline sprites placed after the root's last frame / while the root is stopped** are never
   promoted 1→2 natively, because `upgrade_sprite_initialized` runs only inside `tagShowFrame`. My
   attached-list promotion moved to the tick boundary for this reason. The root list still has the gap.
   Unmeasured.
3. The **non-root attach registration copy** in the parent's `sprite_display_list` shares the child's
   list pointer, which goes stale if the child list is later reallocated. This is pre-existing and
   inert for dispatch now (it is never initialized), but anything else that walks it reads a stale
   pointer.
