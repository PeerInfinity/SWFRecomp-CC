# s26 w2-loaded-shell-phase2: per-movie display lists, phases 2–5 (continuation of phase 1 `a6a696bf2`)

**Slot:** wave 2 (implementation) · **Branch:** `fanout/w2-loaded-shell-phase2`
**Code base:** origin/master `912672370` (phase 1 on master) · **Upstream Ruffle tests:** `3e98d9ba6`
**Box:** SETUP_STATUS all OK (apt, Pillow, Dawn/lavapipe).

## New files

Source patch: `w2-loaded-shell-phase2.patch` (the exact command is in §7).
It touches two files, `action.c` and `tag.c`, and nothing in `SWFRecomp/`, `verify_output.py` or `render_canary_tests.txt`.
Checked with `git apply --check -R` (§7).

New files:
- `ruffle-tests/tests/swfs/regression/_lib/avm1asm.py`: a small AVM1 SWF assembler shared by the fixtures. It has no
  `test.swf`, so test discovery skips it.
- `regression/avm1_loaded_bare_goto/`: `create_test_swf.py`, `test.swf`, `child.swf`, `child2.swf`, `child3.swf`,
  `test.toml`, `output.txt`.
- `regression/avm1_loaded_unload_shell/`: `create_test_swf.py`, `test.swf`, `child.swf`, `test.toml`, `output.txt`.
- `regression/avm1_remove_same_name_other_parent/`: `create_test_swf.py`, `test.swf`, `test.toml`, `output.txt`.
- `regression/avm1_loaded_shell_consumers/`: `create_test_swf.py`, `test.swf`, `child.swf`, `test.toml`, `output.txt`.
- `SWFRecompDocs/plans/session26-fanout-reports/w2-loaded-shell-phase2-parked/avm1_loaded_timeline_holder/`: the
  **parked** Phase-3 fixture (generator, SWFs, predicted golden). It is NOT in `regression/`, because Phase 3 is a HOLD
  (§4).
- This report and `w2-loaded-shell-phase2.patch`.

The `output.txt` goldens are **PREDICTED**. Each one is our post-fix output, hand-checked against the Flash/Ruffle rule
in the generator docstring. They need the oracle run listed under LOCAL ORACLE REQUESTS before landing.

## Verdicts

| item | verdict | corpus flips | fixture |
|---|---|---|---|
| **Phase 4 b1**: a bare `gotoAndStop`/`nextFrame`/`prevFrame`/numeric `GotoFrame2` in a loaded movie's own frame code | **GO**, landed in the patch | 0 | `avm1_loaded_bare_goto` 5/17 → pass, both modes |
| **Phase 4 b2**: the target frame's DoAction on a child goto issued by the movie itself | **GO** (self-issued gotos only; see the mechanism) | 0 | same fixture (the second `c2`) |
| **Phase 4 b3**: one-frame loaded movie goto | **GO** (hardening) | 0 | same fixture (`k` holder) |
| **Phase 5**: `unloadMovie`/`unloadClip`/getURL-unload on a shell holder clears the shell | **GO** | 0 | `avm1_loaded_unload_shell` 12/16 → pass (graphics), 10/16 → pass (no-graphics) |
| **Parent-blind `actionInvalidateCachedMovieClip`** (wave-1 lead 1) | **GO**: reproduced, then fixed | 0 | `avm1_remove_same_name_other_parent` 1/4 → pass, both modes |
| **Phase 2**: clip-event enterFrame over shells | **GO** | 0 | `avm1_loaded_shell_consumers` 0/21 → pass |
| **Phase 2**: for-in over a holder (`actionEnumerate` and `actionEnumerate2`) | **GO** | 0 | same fixture |
| **Phase 2**: slash/dot string paths through a holder (`resolveSlashPathToMC`) | **GO** | 0 | same fixture |
| Phase 2: button state + hit-test over shells | **HOLD** | 0 | none |
| Phase 2: text-field depth windows; Phase-3 nested-advance order | **HOLD**, untouched | 0 | none |
| **Phase 3**: timeline-placed holder (it has a `display_obj`) swaps its list in for frame 1 | **NO-GO as specified**: measured −2 rows | (−2) | parked |

**Net corpus yield: 0 rows.** That matches the wave-1 pricing ("no corpus row moves" for phases 2–5). What the patch
adds is four new `regression/` rows and four latent bugs closed.

`avm1/video_prototype_lazy_swf6_child` reads `output_mismatch 4 → pass` against the s26 baseline. That flip is phase 1's
(`a6a696bf2`), already on master. It is **not** this patch's yield, but this patch keeps it passing.

### Refutations of the brief's premises

1. **"A bare goto in a loaded movie reaches `actionGotoFrame` = the ROOT goto and rewinds the parent."** Refuted for both
   CI modes. In NG/OFFSCREEN, `actionGotoFrame` takes its
   `g_current_context != &root_movieclip → ng_gotoFrameByMC` branch, because the running context is the holder. For a
   dynamic holder, `ng_gotoFrameByMC` hits its "Dynamic MC: just update currentframe" arm (`tag_stubs.c:1214`) and
   returns. So the parent never moved: `p2..p10` print exactly once on clean master. The real bug is that **the goto is
   silently dropped**:
   - `gotoAndStop(2)` from the child's frame 3 leaves `h` on frame 3;
   - a bare `nextFrame()` neither moves nor stops the child, so `child2` keeps looping `d1 d2 d3`.

   `actionNextFrame`'s non-root context is a no-op the same way. The browser-WASM arm is unchanged and out of scope.
2. **"One-frame movie: `holder.gotoAndStop(1)` still falls to the root goto."** Refuted in CI modes, for the same
   `ng_gotoFrameByMC` dynamic-arm reason: the parent row `p5` is unaffected on master. It is kept as hardening. The
   name-keyed `ng_findDisplayEntryByName(mc->name)` inside `ng_gotoFrameByMC` could hit an unrelated same-named entry in
   whichever list is active.
3. **Parent-blind invalidation: real, but only observable through the clip's state.** The obvious fixture (two sprites
   each place `btn` at depth 1, one removes it) **passes on master** if you only read `typeof`/`_name`. The wrongly
   killed `s2.btn` is rebuilt lazily from `s2`'s display entry on the next lookup. The bug shows only when:
   - the surviving clip carries script state (`s2.btn.v = "keep"` reads `undefined`), AND
   - it was cached FIRST (the keeper is placed first, because child clips are built eagerly in placement order).

   The committed fixture has both.
4. **Phase 3 ("make both loaders swap into `display_obj`'s sprite list") is not S, and as specified it regresses two
   graded rows.** Measured: `avm1/swf5_to_6_cross_call` and `swf6_to_5_cross_call` go pass 29/29 → 13/29 (graphics).
   The cause is not the list itself. It is **synchronous cross-movie name resolution while a holder list is swapped in**:
   - the child's frame 1 calls `_root.onLoaded()`;
   - that parent callback runs `clip.f()`;
   - the root-arm `clip` lookup (`ng_findDisplayEntryByName` on the *active* list) now searches `clip`'s own list, so
     `clip.f` is undefined and the body never runs.

   This is exactly the pair the wave-1 report names as breaking under a list swap, and this is the measured reason.
   Reverted. See §4 for the completion mechanism.

## 1. Mechanism and patch scope (functions touched; siblings take note)

Everything is in `SWFModernRuntime/src/actionmodern/action.c` and `SWFModernRuntime/src/libswf/tag.c`. Nothing touches
`swf.c`, `swf_core.c`, `tag_stubs.c`, `ng_shared.c`, `SWFRecomp/`, the render paths, `render_attached_child`, or the
button walk / `ng_update_button_states*`. So there is no overlap with `w2-attached-holder-render`. All new code runs in
NG and OFFSCREEN alike. The `actionGotoFrame`, `actionNextFrame` and `actionPrevFrame` hooks are inside the existing
`#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` arms.

### `action.c`

**Phase 4:**
- **new** `actionChildMovieBareGoto(app, frame0, rel, play)`. It acts only when the running context IS the loaded
  movie's holder (`g_child_movie_advance_mc == g_current_context`), so a sprite's own frame code inside the movie, or a
  `tellTarget`, is never captured. It routes to `actionChildMovieGoto`. Every form stops (Ruffle
  `goto_frame(.., stop=true)`), except a `GotoFrame2` with play=1. It returns 1 even when nothing is tracked, so the
  root's playhead is never the fallback.
- `actionGotoFrame`, `actionNextFrame`, `actionPrevFrame` and `actionGotoFrame2` (numeric only): a one-line hook at the
  top of the NG/OFFSCREEN arm. A label `GotoFrame2` inside a child still resolves against the root's label table (HOLD,
  see below).
- `actionChildMovieGoto`:
  - (b3) With no advance entry, but `loaded_dl_shell` set, it is a handled no-op.
  - (b2) After the tags catch-up, when the goto came from the movie's own code (`_saved_child_mc == mc`), it re-runs
    `frame_funcs[target]` with `g_tag_skip_mode=1` inside `actionDrainSuppressEnter/Leave`. That queues the target
    frame's DoAction, and the movie's own outer frame drain runs it after the current script, under the same context
    swap. This mirrors swf.c's root goto, which leaves its target script to the caller's drain.
  - A goto issued from the parent (`holder.gotoAndStop` in a parent frame) keeps the phase-1 HOLD (DoAction suppressed).
    Draining there would run unrelated queued parent scripts under the child's context, and root scripts carry no
    context in the queue.
- `actionAdvancePlayingLevels`:
  - Before the frame call it publishes the running frame as the live cursor (`current_frame = e.current_frame + 1`,
    i.e. "shown").
  - The read-back carries a cursor a goto left behind (`e.current_frame = live - 1` before the `++`).
  - Without this, a goto from frame N measured from N−1, and the copy-out write-back clobbered it. That was the second
    half of the `h` pinned-at-3 symptom.

**Phase 5:**
- **new** `actionClearChildMovieShell(app, mc)`: swaps the shell in (`childDLSwapIn`, re-entrancy safe) and runs
  `tagRemoveObject2` on every occupied depth, so onUnload fires and the cached MovieClips invalidate. It is called right
  after `actionUnregisterLevelAdvance` at four sites:
  - global `unloadMovie` (in `actionGetURL`, the `mc != root` arm);
  - `builtin_mcl_unloadClip`;
  - `actionGetURL2`'s unload arm;
  - `actionCallMethod`'s `unloadMovie` arm.

  The `_levelN` `unloadMovieNum` arm is untouched (levels have no shell). This follows Ruffle `avm1_unload_movie` →
  `transform_to_unloaded_state` → `replace_with_movie(empty)`, which is synchronous for a non-root clip.

**Invalidation:**
- `actionInvalidateCachedMovieClip`: before the existing parent-preference loop, it looks for the clip bound to
  **exactly** the entry being removed (`c->display_obj == &display_list[swf_depth]` of the active list) and prefers
  that clip's parent. If none is found, the old behaviour stays: the phase-1 child-movie rule, then the first match.

**Phase 2:**
- **new** `actionHolderShellList(mc, &max)`: returns a holder's shell list with the LIVE max depth (the getMember shell
  arm's rule while the shell is the active list).
- `actionEnumerate` and `actionEnumerate2`: a shell arm before the name-keyed `ng_enumerateChildren(mc->name, …)`
  fallback. `ng_enumerateChildren` itself is not touched. It keys on a NAME in the root list and cannot address a
  holder.
- `resolveSlashPathToMC` (NG/OFFSCREEN arm): the `SLASH_PATH_SHELL_DESCEND` macro is applied at the start-MC init, the
  dynamic child-cache hop and the dynamic_props hop. A path through a dynamic holder now descends into its shell.
  `ng_findChildEntryDepth` is not touched: the resolver now finds the shell entry before that fallback is reached.

### `tag.c`

- `collect_attached_standalone`: a shell arm yielding `(loaded_dl_shell, holder)` for a live, non-unloaded holder with
  no `display_obj`. That one change feeds `ng_upgrade_attached_standalone_initialized`,
  `dispatch_enterframe_clip_actions_impl` (the flat place_seq-sorted gather) and `hasClipEnterFrameHandlers`.
- `dispatch_enterframe_clip_actions_impl`: the overflow-fallback liveness check accepts `loaded_dl_shell == ad[k]` as
  well as `display_obj == ad[k]`.

### Deliberately not done (each with its completion mechanism)

- **Phase 3 (timeline holder), HOLD.** It needs root-list name resolution that is immune to the active-list swap. A
  `ng_rootDisplayList()` accessor (the root's real list and max, saved by `childDLSwapIn` / the loaders' swaps) is
  needed, used by:
  - the `actionGetMemberImpl` root arm;
  - `ng_findDisplayEntryByName` when called for `mc == &root_movieclip`;
  - `resolveSlashPathToMC`'s `/` / `_root` init.

  After that, re-apply the parked loader hunks:
  - `actionFirePendingDirectLoads`: an `else if (!_did_swap && mc->display_obj)` arm after the `is_level` block;
  - `actionFirePendingLoadInits`: a `childDLSwapIn(target->display_obj)` when `_p2_shell == NULL` and the target is
    non-level.

  The gate is `avm1/swf{5_to_6,6_to_5}_cross_call` (must stay pass) plus the parked
  `avm1_loaded_timeline_holder` fixture (must go pass). Price: M, not S. **The same hazard exists today for phase-1
  shells**; see lead 1.
- **Phase 2, buttons and hit-test over shells**: HOLD. `w2-attached-holder-render` owns `ng_update_button_states*` and
  its pick order this wave. Mechanism: walk `collect_attached_standalone`'s new shell pairs in
  `ng_update_button_states_attached` and in `hit_test.c`'s attached pass, after that slot lands.
- **Text-field depth windows** (`actionSetTextFieldDepthWindow`) and **Phase-3 nested-advance order** for shells (the
  w1 HOLD (a)): untouched. Neither has a failing fixture; each needs an oracle trace first (see the oracle requests).
- **GotoFrame2 / GoToLabel by label inside a loaded movie**: still resolves through the root's label table. Mechanism:
  have `findFrameByLabel` consult `MovieEntry` labels when `actionChildMovieBareGoto` would fire.
- **b2 for parent-issued gotos** (`holder.gotoAndStop(n)` from the parent): DoAction is still suppressed. Mechanism: a
  context-capturing queue entry (`PendingSpriteScript`-style, with the child's version, globals and list), then queue
  it instead of suppressing.

## 2. Per-test before/after (clean origin/master vs this patch, same box)

| test | mode | before | after |
|---|---|---|---|
| `regression/avm1_loaded_bare_goto` | graphics | output_mismatch 5/17 | **pass** 17/17 |
| | no-graphics | output_mismatch 5/17 | **pass** 17/17 |
| `regression/avm1_loaded_unload_shell` | graphics | output_mismatch 12/16 | **pass** |
| | no-graphics | output_mismatch 10/16 | **pass** |
| `regression/avm1_remove_same_name_other_parent` | graphics | output_mismatch 1/4 | **pass** 4/4 |
| | no-graphics | output_mismatch 1/4 | **pass** 4/4 |
| `regression/avm1_loaded_shell_consumers` | graphics | output_mismatch 0/21 | **pass** 21/21 |
| | no-graphics | output_mismatch 0/21 | **pass** 21/21 |
| *(parked)* `avm1_loaded_timeline_holder` | graphics | output_mismatch 0/7 | 0/7 (Phase 3 reverted) |

`avm1_loaded_unload_shell`'s `num_frames` is 6, so both modes end on the same tick: no-graphics exits when the root
stops, graphics runs to `num_frames`. Before the fix the two modes also disagreed with each other (12 vs 10).

## 3. Gate (same as phase 1): every loaded-child row and the whole regression suite, both modes

The row set is a byte-scan of every SWF (zlib-inflated) in `avm1 from_gnash from_shumway regression` for
`loadMovie|loadClip|MovieClipLoader|unloadMovie|_level[1-9]`, plus every avm1 row that ships more than one SWF. That
gives **122 rows** (wave 1 counted 104; the regression suite has grown, and the four new fixtures are in it). Add the
whole `regression` suite and the union is **239 rows**.

The baseline is the committed s26 results (`_results/results_graphics.json` / `results.json`, from `9277f3799` /
`dffc41cf2`), compared on (status, matching_lines).

| set | mode | rows | result |
|---|---|---|---|
| loaded-child ∪ regression (first patch, *with* Phase 3) | graphics | 240 | 228 identical. **2 regressions: `avm1/swf5_to_6_cross_call`, `avm1/swf6_to_5_cross_call` pass → 13/29.** The rest is the phase-1 headline and new/unbaselined regression rows. Phase 3 reverted because of this. |
| avm1 loaded-child rows + the 4 new fixtures + `avm1_child_timeline_loop`, `avm1_parent_child_sprite_meta` (final patch) | graphics | 89 | **84 identical**; the other 5 are `video_prototype_lazy_swf6_child` (phase-1 flip, already on master) and the 4 new fixtures (pass, no baseline) |
| gnash + shumway loaded-child rows (first patch; Phase 3 cannot reach them, see below) | graphics | 18 | **18 identical** |
| whole regression suite (first patch) | graphics | 139 (this count includes the since-parked `avm1_loaded_timeline_holder`) | **139/139 pass**. Every pre-existing row is identical; the rows without a baseline (added after `9277f3799`, plus the new ones) pass |
| loaded-child ∪ regression (final patch) | no-graphics | 239 | **230 identical**. The 9 others: `video_prototype_lazy_swf6_child` (phase-1 flip, on master), the 4 new fixtures (pass), and 4 regression rows with no baseline (added after `dffc41cf2`; all pass). **Zero regressions.** `swf{5_to_6,6_to_5}_cross_call` are identical (pass) |
| whole regression suite (final patch) | graphics | 138 | **138/138 pass**: 130 identical to the baseline, and 8 rows without a baseline all pass (the 4 new ones and 4 added after `9277f3799`) |

The Phase-3 revert only removed code that ran for a timeline-placed (non-level) load target. The gnash/shumway
loaded-child rows were already identical with that code present, so removing it cannot move them. That is why the final
graphics re-gate was scoped to the avm1 loaded-child rows, where the regression was.

## 4. Graphics canary

`render_canary.py capture` was run before (clean origin/master) and after (this patch). It used a targeted 18-test set,
not the 268-member standing list, because the change class is loaded-movie and shell content:
- the 12 `avm1/` members of `render_canary_tests.txt`, including `netstream_play_flv_screen`, the one loaded-child
  canary member;
- `regression/avm1_parent_child_{render,text,morph,bitmap_fill}`, the corpus's whole shell-render surface (wave 1, §5);
- `regression/avm1_attached_clip_color` and `regression/avm1_dynclip_color_transform`.

Result: **36/36 comparisons md5-IDENTICAL**, 0 differ, 0 appeared/vanished, no trace or image status changes. No
render code was touched. Phase 5 changes what a shell holds after an unload, and no canary or image row unloads a
shell holder. I added no standing-set member: the parent-child goldens already cover shell rendering.

## 5. EXPECTED-FLIP LEDGER (for the coordinator's CI check)

**Trace axis:**
- New rows, absent from the baseline, expected `pass` in **both** modes:
  - `regression/avm1_loaded_bare_goto`
  - `regression/avm1_loaded_unload_shell`
  - `regression/avm1_remove_same_name_other_parent`
  - `regression/avm1_loaded_shell_consumers`

  These hold only if the oracle confirms the predicted goldens. If it does not, the golden changes and the row is
  re-measured.
- Corpus rows: **no flips from this patch.** `avm1/video_prototype_lazy_swf6_child` stays pass (phase 1, already on
  master).
- **Must stay put:** everything else, explicitly including `avm1/swf5_to_6_cross_call` and `avm1/swf6_to_5_cross_call`
  (pass), the phase-1 "rows that must stay put" list, and every row in the §3 set.

**Pixel axis:**
- No expected change.
- Phase 5 removes rendered content only for a holder that was `unloadMovie`'d, and no image row in the corpus does that
  to a shell holder. The four `avm1_parent_child_*` image fixtures are in the canary (§4).

## 6. New unclaimed leads

1. **The list-swap hazard exists for phase-1 shells too** (unmeasured by any row). While a loaded movie's frame runs, its
   shell IS `display_list`. A synchronous call from that frame into parent code (`_root.f()`) that resolves a ROOT
   timeline child by name (`_root.px`, or the root arm of `ng_findDisplayEntryByName`) searches the shell instead.
   - Dynamic holders mostly escape, because the child-cache fallback finds script-created clips.
   - A timeline-placed root child, looked up from a callback the child invokes, does not escape.

   The mechanism and fix are the same as the Phase-3 completion (a `ng_rootDisplayList()` accessor for root-arm
   lookups). Fixture first: the `swf5_to_6_cross_call` shape with a `createEmptyMovieClip` holder and a parent
   timeline clip.
2. **First-tick root-name leak.** `typeof _root.a` is `movieclip` on the first tick after a load and `undefined` after
   that. Here `a` is a child of the loaded movie, not of the root. The parent's own `_root.a` GetMember creates a stray
   MC named `a` with parent=root, via `findOrCreateMovieClip` in `actionGetMemberImpl` (backtrace, not line-pinned).
   Flash gives undefined. The row is left out of `avm1_loaded_shell_consumers` (documented in its docstring).
3. **The `_x`/`_y` getters are name-keyed on the active list.** Both the property-opcode getter
   (`actionGetProperty`, `case 0/1`) and the `actionGetMemberImpl` `_x`/`_y` arms read
   `ng_findDisplayEntryByName(mc->name)` first. So any clip whose name matches an entry in the active list reads THAT
   entry's transform. Measured in the parked Phase-3 fixture, and tied there to MovieClip identity aliasing: root's `x`
   and the loaded movie's `x` swap values tick to tick. A `display_obj`-match guard alone did not fix it, so it is
   reverted and not in the patch. Unpriced; fixture first (a nested sprite child named like a root clip, reading
   `_x`).

## LOCAL ORACLE REQUESTS

Ruffle exporter `--trace-log`, no timers. Each request is
`exporter -s -f <N> --trace-log out.txt test.swf out.png` in the fixture directory (the child SWFs sit next to
`test.swf`). Replace or confirm `output.txt`.

1. `regression/avm1_loaded_bare_goto`, **12 frames**. Check:
   - the parent `p2..p10` rows print once each;
   - `h` pins at 2 with a second `c2`;
   - `d1` is followed immediately by `d2` and `g` pins at 2;
   - `k` stays 1.

   Load timing relative to `p2` is our runtime's; the oracle decides it.
2. `regression/avm1_loaded_unload_shell`, **6 frames**. Check that `b:` (right after `h.unloadMovie()`) is already
   `undefined`, and that only `g`'s `c1`/`c2` continue afterwards.
3. `regression/avm1_remove_same_name_other_parent`, **5 frames**. Expected `v:keep` on every row from f2.
4. `regression/avm1_loaded_shell_consumers`, **7 frames**. Check:
   - `cx` once per tick, and its position relative to `t<N>`;
   - the **`in:` enumeration order**: `b,a,` is a prediction;
   - `sl:` for `eval("/h/b")` is `movieclip`.
5. *(parked; for the Phase-3 completion)*
   `SWFRecompDocs/plans/session26-fanout-reports/w2-loaded-shell-phase2-parked/avm1_loaded_timeline_holder`, **6
   frames**. Also run with a temporary `tx:<t.x._x> rx:<_root.x._x>` row (see the docstring), to settle lead 3.

## 7. Patch proof

`w2-loaded-shell-phase2.patch` is 50,710 bytes and covers 24 files: `action.c` and `tag.c`, plus 22 new fixture/lib
files, binary SWFs included via `--binary`. It was made AFTER the final source edit with:

    git diff --binary origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py \
        ruffle-tests/render_canary_tests.txt ruffle-tests/tests/swfs/regression/{_lib,avm1_loaded_bare_goto,\
        avm1_loaded_shell_consumers,avm1_loaded_unload_shell,avm1_remove_same_name_other_parent}

- `git apply --check -R` on the branch: OK.
- `git apply --check` on a clean `origin/master` worktree: OK.
- The source half is byte-identical to the patch the final graphics/no-graphics gates and the canary ran on.

Not included: the regression `README.md` "Contents" table rows for the four new fixtures. The README is outside the
patch path list; the coordinator can add one line each from the generator docstrings. The parked Phase-3 fixture is on
the branch but deliberately not in the patch.
