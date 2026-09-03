# A loaded child SWF's timeline never advanced past its first frame

**Date:** 2026-09-03 · **Arc:** Multi-SWF (loaded children), slice 5
**Baseline:** `128828002` · **Brief:** `SWFRecompDocs/prompts/child-timeline-advance-prompt.md`
**Predecessor:** `SWFRecompDocs/status/child-embedded-asset-lookup.md`

Loaded children now advance, loop and stop. Three regression fixtures assert
the *sequence* with negative controls in both directions, and one of them exists
because writing them turned up a second defect that the fix itself would have
introduced.

## 1. What the freeze actually was — the brief's framing is half right

The brief's symptom is exact: `actionFirePendingDirectLoads` runs the child's
`child_frame_0` and nothing calls `child_frame_1`. Reproduced from a clean
baseline before any change, with a 5-frame child whose every frame carries a
`DoAction trace`:

```
c1
t1 cf:1 tf:5 ax:10 b:undefined z:undefined
t2 cf:1 tf:5 ax:10 b:undefined z:undefined
...
```

One `c1`, then seven identical rows. `tf:5` is already right (the loader writes
`mc->totalframes`), which is exactly what makes the freeze quiet: the movie
*reports* five frames and plays one.

**Where the brief is wrong: the machinery to advance a loaded movie already
existed, was already wired into both main loops, and already covered clip
targets.** `g_level_advance` / `actionAdvancePlayingLevels` (`action.c`) is a
per-tick child-movie playhead with the full per-movie context swap — SWF
version, `_global` group, `movie_id`, `g_active_transform_data`, display list —
already written and corpus-tested. And `MovieClipLoader.loadClip`'s Phase 2
(`actionFirePendingLoadInits`) registers **any** target with it:

```c
if (loads[i].target != NULL && loads[i].entry->frame_count > 1 ...)
    actionRegisterLevelAdvance(loads[i].target, loads[i].entry);
```

The direct-`loadMovie` path had the same call one `&&` narrower:

```c
if (loads[i].is_level && entry->frame_count > 1 ...)
```

So the freeze was never "loaded children don't advance". It was
**`mc.loadMovie("x.swf")` doesn't advance, while
`new MovieClipLoader().loadClip("x.swf", mc)` does** — one gate, on one of the
two loader paths. `from_shumway/avm1/moviecliploader` has graded a 2-frame
loadee's "loadee frame 2" through the MCL path this whole time.

This also corrects the arc's standing hazard note (memory
`loaded-child-timeline-stuck-frame-0`) and the BACKLOG entry, both of which
read as though no loaded child ever advanced.

**Also confirmed as stated:** `MovieEntry` (`swf.h:463`) carries no playhead and
no play state — checked, the struct is frame_funcs/init_func/counts/pointers
only. That reading was right, and §2 below says why it should stay that way.

## 2. The rulings

### 2.1 Who owns the playhead

Split, deliberately, and each half sits where the code that writes it already
looks:

| state | home | why |
|---|---|---|
| play / stop | the holder `DisplayObject`'s `sprite_is_playing` | it is *already* the field every stop/play route writes |
| frame cursor | the advance-table entry | it belongs to the LOAD, not to the movie or the clip |
| display list | the holder `DisplayObject`'s `sprite_display_list` | the loaded movie's children are the clip's children |

**Not `MovieEntry`.** `MovieEntry` is the immutable *program*: the same entry
can be loaded into two holders, and `getMovieEntryAt` hands the same pointer to
every caller. A playhead on it would be shared between independent loads.

**Not the sprite playhead's DRIVER, `advance_sprite_frames` — and this is the
brief's "hope, not a finding", answered.** It cannot reach a loaded movie, for
three independent reasons, each of which alone is fatal:

1. It walks `display_list[]` and dispatches on
   `dictionary[obj->char_id].type == CHAR_TYPE_SPRITE`. A `createEmptyMovieClip`
   holder has **no display-list entry and no `display_obj` at all** — measured,
   not inferred:
   ```
   PROBE fire: mc=holder is_level=0 fc=5 dobj=(nil) sdl=(nil) smax=0 depth=1
   PROBE after: dl1.char=1001 dl1.name=a
   ```
   (the child's own placement landed in the ROOT's display list at depth 1).
   A `_levelN` target is not in a display list either.
2. Its frame call (`CALL_FRAME`) carries none of the per-movie context a child
   frame needs — SWF version, `_global` group, `movie_id`,
   `g_active_transform_data`. Those four swaps are the whole reason
   `actionAdvancePlayingLevels` exists.
3. The frame funcs would have to hang off `dictionary[char_id]`, which every
   instance of that character shares. A timeline-placed holder would overwrite
   the frame funcs of its own siblings.

**But its STATE is reused, and that is where the real reuse is.** Using
`sprite_is_playing` on the holder means neither `stop()` needed new routing:

- **inside the movie**: the frame call sets `g_current_sprite_obj` to the
  holder, so `actionStop`'s existing `ng_isInsideSprite()` arm writes
  `sprite_is_playing` there instead of falling through to the ROOT's
  `is_playing` (which the loader was defensively save/restoring — i.e.
  *discarding* the child's stop);
- **from the parent**: `holder.stop()` already lands on
  `((DisplayObject*)mc->display_obj)->sprite_is_playing` — that is the
  "attached clip" arm at `action.c:69470` (`mc.stop()`; its `mc.play()`
  twin is at `:69381`), written for `attachMovie` targets
  whose `display_obj` is a standalone struct. A loaded holder now has exactly
  that shape, so the arm fires without being touched. Before this slice it fell
  through to `actionStop` and **stopped the ROOT**.

### 2.2 Looping and stop()

**Ruffle is unambiguous.** `MovieClip::replace_with_movie`
(`core/src/display_object/movie_clip.rs:371`) — the function all four AVM1/AVM2
load paths funnel into — swaps the clip's shared data for the loaded movie,
sets `total_frames` to the movie's frame count, sets `MovieClipFlags::PLAYING`
and parks `current_frame` at 0. `determine_next_frame` (`:1340`) then answers
`NextFrame::First` — wrap to frame 1 — for any clip with more than one loaded
frame and an End tag, which every SWF *file* has. So a loaded movie plays and
loops unless stopped, and the holder's `_totalframes` / `gotoAndStop` are the
loaded movie's.

**The existing per-sprite loop-back does not apply, and the reason is the
interesting part.** `advance_sprite_frames`'s wrap clears the sprite's own
display list and rebuilds frame 0, with survivors decided against the
recompiler's per-`DefineSprite` placement table. A loaded movie has no such
table (it is a movie root, not a `DefineSprite`) — but that is not the blocker.
The blocker is that **a clip-target child's placements were in the parent's
global display list**, so any wrap-back clear would take the parent's children
with it. Looping was not implementable until the child owned a display list.

So the fix does that, generalising a block that already existed for levels:

```c
-		if (loads[i].is_level) {
+		{
 			DisplayObject* dobj = mc->display_obj ? ... : NULL;
 			// lazily attach a display_obj + private sprite_display_list
```

Every loaded movie now gets its holder's own list, which is both the
precondition for the wrap and a fix in its own right — the level branch's own
comment records the bug it was added for
(`avm1/swf5_xml_event_handler_context`'s child placing at a depth the parent
already occupies, producing `Warning: Failed to place object at depth 1.`);
clip targets had the identical exposure and no protection.

The wrap itself (`childMovieLoopBackClear`) frees nested sprite lists and zeroes
the child's own STATIC-range entries, the same shape as the sprite backward-goto
clear. Dynamic-range entries (swf depth >= 16384: `attachMovie`,
`duplicateMovieClip`, `createEmptyMovieClip`) survive, which is the rule the
root's `ng_display_clear_after`, the sprite loop-back's
`ng_loopback_entry_survives` and Ruffle's `run_goto` all apply. It refuses to
run when the holder has no private list, so such a target parks on its last
frame rather than clearing something that is not its.

Two simplifications against the sprite loop-back, both deliberate and neither
observable today: it fires no `onUnload` for the entries it clears (neither
does the ROOT's `ng_display_clear_after`, which is the closer analogue for a
movie root's own wrap), and it does not call `actionInvalidateCachedMovieClip`
for their names. The second is measured rather than assumed: the `advance`
fixture's `t9 z:undefined` row reads a clip placed by frame 5 and removed by
the wrap, and it resolves to undefined without the invalidation, because the
name lookup walks the holder's private list and finds `char_id == 0`.

**Scope of looping — the deliberate asymmetry.** `loops=1` is passed by the
direct-`loadMovie` clip path only. `_levelN` and MovieClipLoader targets keep
the one-shot behaviour they have always had (they do pick up the two shared
driver changes listed in §2.3). This is not because a level should
not loop — in Ruffle it plainly should, it is a MovieClip like any other — but
because turning it on is a *separate*, corpus-visible change to paths that
already work: `hasPlayingLevels()` would go permanently true for
`avm1/unloadmovienum`'s 10-frame level and `mcl_unloadclip`'s 10-frame MCL
target, holding the player alive to `max_ticks` and re-running frames the
corpus has never seen re-run. It is the shape of change this arc keeps warning
about (a corpus-wide behaviour move to fix a narrower bug), and it belongs in
its own slice with its own measurement. Recorded as a follow-up in §7.

### 2.3 Scope: AVM1 `loadMovie` vs AVM2 `Loader.load`

**AVM1 only.** Both AVM1 loader paths advance — direct
`loadMovie`/`loadMovieNum` (`actionFirePendingDirectLoads`) and
`MovieClipLoader.loadClip` (`actionFirePendingLoadInits`) — including the
`_levelN` targets that share the driver. Looping is the direct clip path only
(§2.2).

**What the `_levelN` / MCL paths DID change, since they share the driver**, and
both are behaviour changes rather than pure additions:

- **`armed`**: no load runs two of the movie's frames on its load tick any
  more. The loader calls `frame_funcs[0]` and the driver runs in the *same*
  tick, immediately after it, so every target used to take a double step on
  load. Flash gives a loaded movie one frame per tick from the start.
- **`sprite_is_playing` is now consulted.** A target whose holder has a
  `DisplayObject` freezes when that flag is 0 (and the loader sets it to 1 at
  load, before frame 1, so nothing starts stopped by accident). A target with
  no `DisplayObject` — which is every MCL clip target, since Phase 2 allocates
  none — is treated as always playing, i.e. exactly its old behaviour.

**AVM2 `Loader.load` was already not frozen and is untouched.** An AVM1 movie
loaded by an AVM2 `Loader` runs on a third playhead, `g_avm1u2` /
`avm1UnderAvm2RunFrame` (`action.c`, `#ifdef SWF_AVM2`), which already loops —
`mixed_avm/avm2_loads_avm1_doabc` grades frames 1,2,1 across four ticks. An
AVM2 child's own timeline is driven by the AVM2 display list, not by this
table. So there is no AVM2 half of this defect to write down beyond the note
that `g_avm1u2` is a fourth copy of the same context swap and is a candidate
for consolidation with this table.

**What AVM1 still does NOT have** (all pre-existing, none introduced here):

- **`holder.gotoAndStop(n)` does not target the loaded movie's frames.**
  `ng_gotoFrameCurrentSprite` and `ng_gotoFrameByMC` both require
  `dictionary[obj->char_id].type == CHAR_TYPE_SPRITE`, and a loaded holder's
  `char_id` is 0. `stop()`/`play()` work because they need no character;
  `goto` needs the frame table, which for a loaded movie is on the
  `MovieEntry`. The advance entry is where a `goto` would land — it already
  owns the cursor — but wiring the two `ng_goto*` entry points to it is a
  separate change.
- **Browser-WASM has no child-movie driver at all.** `swf.c`'s
  `actionAdvancePlayingLevels` call sits inside `#ifdef OFFSCREEN_RENDER`, so
  the in-page build never advances a loaded movie, on any path. Nothing in CI
  grades it. This slice does not change that either way.
- **A movie with trailing tags after its last ShowFrame** ("dangling frame")
  loops here where Ruffle runs it once. `MovieEntry` carries no `has_end_tag` /
  `loaded_frames` distinction, which is the same information `sprite_has_end_tag`
  carries for sprites.

## 3. The second defect — found by writing the fixtures, not by the corpus

Marking the holder PLAYING is required (`replace_with_movie` sets the flag
unconditionally, so a holder sprite that was stopped before the load must start
playing). The natural place to say it is next to the playhead registration —
and **registration runs after the movie's `frame_funcs[0]`**. A movie whose own
first frame calls `stop()` — the preloader shape, and the commonest real
stopped-loaded-movie there is — would have that stop overwritten and play on.

Written that way first, then caught by inspection and fixed by hoisting the
mark ahead of `frame_funcs[0]` in **both** loader paths.

The same trap already has a precedent in this runtime, which is some evidence
it is a real class rather than a one-off: `ng_promote_attached_playheads`
(`swf_core.c:1229`) exists so an `attachMovie`'d clip is promoted to "active"
only "after the deferred attach-init drain (inside the root frame func) so a
clip's frame-1 `this.stop()` has applied before it is ever advanced". Same
shape, different playhead.

It is now graded by its own fixture with the over-correction as the negative
control:

| state | output |
|---|---|
| correct | `S1`, then `cf:1 b:undefined` on every tick |
| mark at registration time (the bug) | `S2`, `S3`, `cf` climbs to 3, `b:movieclip`, then wraps and prints `S1` again |
| whole slice reverted | identical to correct — a frozen child and a correctly stopped one look the same |

That last row is why this fixture needed a sibling: it guards against the fix
over-running, not against the baseline. `avm1_child_timeline_advance` is the one
that discriminates against the baseline.

## 4. The last-frame trap — the brief named it, and it is bigger than `quit_swf`

`generate_child_movie_file` strips `quit_swf = 1;` from a child's frames. The
brief asked what else a child's last frame does now that children reach it.
**It carries the root loop-back**, and the harness does not strip that
(`SWFRecomp/src/swf.cpp:851` and the identical `:1185`):

```c
if (!manual_next_frame && is_playing && !g_tag_skip_mode)
{
	next_frame = 0;
	manual_next_frame = 1;
}
```

`next_frame` and `manual_next_frame` are the **main movie's** globals. Before
this slice no loaded child ever reached its last frame, so this never fired;
the moment children advance, an unguarded child rewinds the PARENT's timeline
at the end of every pass — and with looping, on every pass.

Fixed in the runtime rather than the harness, by save/restoring the pair around
every child frame call (the driver, the direct-load `frame_funcs[0]`, and MCL
Phase 2's `frame_funcs[0]`). The runtime is the right owner: it covers children
that reach the runtime by any route, including the browser build and any future
generator, where a harness substitution covers only what `verify_output.py`
emits. The `frame_funcs[0]` sites are unreachable for this today (frame 0 is a
movie's last frame only when the movie has one frame, and a one-frame movie
emits `quit_swf = 1` instead) — they are guarded anyway so the three call sites
cannot drift apart.

## 5. The evidence — three fixtures, five measured states

Per the brief's §3: the corpus cannot show this slice's yield, so the fixtures
*are* the evidence. All three assert per-tick sequences, not end states.

### `regression/avm1_child_timeline_advance`

5-frame child. Frame 1 places `a` at x=10 and traces; frame 2 moves it to 20
and places `b`; frame 3 moves it to 30 and `RemoveObject2`s `b`; frame 4 traces
and `stop()`s; frame 5 places `z` and traces. The parent samples every tick and
calls `holder.play()` at t7.

```
c1
t1 cf:1 tf:5 ax:10 b:undefined z:undefined     <- one frame per tick, not two
c2
t2 cf:2 tf:5 ax:20 b:movieclip z:undefined     <- frame 2's Modify AND place ran
c3
t3 cf:3 tf:5 ax:30 b:undefined z:undefined     <- frame 3's RemoveObject2 ran
c4
t4 cf:4 tf:5 ax:30 b:undefined z:undefined     <- the child's own stop()
t5..t7 identical                                <- and it HOLDS; no c5
play
c5
t8 cf:5 tf:5 ax:30 b:undefined z:movieclip     <- holder.play() resumed it
c1
t9 cf:1 tf:5 ax:10 b:undefined z:undefined     <- wrapped; the wrap CLEARED z
...through to t12 cf:4, stopped again
```

Every row is load-bearing. A playhead that jumped to the last frame passes an
end-state test and fails `t1`; one that ran all five frames in a tick fails
`t2`; a `_currentframe` that moved without running tags fails `ax`/`b`; a
missed `stop()` fails `t5`; a wrap that reset a counter without re-running
frame 1's tags fails `t9`'s `ax:10` and `z:undefined`.

### `regression/avm1_child_timeline_loop`

3-frame child, no `stop()`. `cf` cycles 1,2,3,1,2,3,1,2 with `ax` returning to
10 on each wrap; the parent calls `holder.stop()` at t8 and the last three rows
are frozen at `cf:2`.

### `regression/avm1_child_timeline_frame1_stop`

§3 above.

### Negative controls, all four run

| control | fixture | result |
|---|---|---|
| whole slice reverted | `advance` | `c1` alone; `cf:1 ax:10` on all 12 rows |
| whole slice reverted | `loop` | `L1` alone; `cf:1 ax:10` on all 11 rows |
| whole slice reverted | `frame1_stop` | **passes** — documented in the fixture; it is not the baseline discriminator |
| mark hoisted back to registration | `frame1_stop` | `S2`/`S3` appear, `cf` reaches 3, `b:movieclip` |

## 6. Do the existing multi-SWF fixtures still mean what they said?

Two of the five were written around the freeze. Re-checked individually, and
**the meaning of one changed**:

| fixture | still means what it said? |
|---|---|
| `avm1_parent_child_modify_place` | **The reason for its shape is now obsolete.** Its child places and Modifies in ONE frame explicitly because "a loaded child never reaches its frame 2"; that constraint is gone. What it *asserts* — the transform-table lookup and the char-id-0 sentinel — is untouched and still passes, so the test is unchanged and correct; only its docstring's rationale is now historical. Left as-is deliberately: same-frame place+Modify is a real shape worth pinning, and rewriting it to cross frames would re-point a test that guards a different bug. Its `create_test_swf.py` and README row now carry a pointer here. |
| `avm2_parent_child_symbol_stride` | Unaffected — an AVM2 `Loader.load` child, driven by the AVM2 display list, not this table. Its 3-frame child's `totalFrames` row reads a table, not a playhead. |
| `avm1_parent_child_bitmap` | 1-frame child; nothing to advance. |
| `avm1_parent_child_sprite_meta` | 1-frame child. |
| `avm1_parent_as3_child_payload` | 1-frame child. |

The predecessor's blind-spot claim holds and is now quantified: **of the ~440
child SWFs in the corpus, 21 have more than one frame**, and of those only a
handful are loaded into an AVM1 clip target. That is why the freeze survived
four slices.

## 7. What is left of the arc

- **Per-movie render tables — a loaded child movie does not render at all.**
  Unchanged and now unblocked: this slice was the gate. See the predecessor's
  §3 and the BACKLOG entry.
- **`_levelN` and MovieClipLoader targets do not loop.** §2.2. One-line switch
  in `actionRegisterChildMovieAdvance`; the work is the measurement.
- **`holder.gotoAndStop(n)` does not target the loaded movie's frames.** §2.3.
- **Browser-WASM never advances a loaded movie.** §2.3.
- **Four copies of the per-movie context swap** now exist
  (`actionFirePendingDirectLoads`, `actionAdvancePlayingLevels`,
  `actionFirePendingLoadInits` Phase 2, `avm1UnderAvm2RunFrame`). Each was
  duplicated deliberately to keep arcs from perturbing each other; with a fifth
  reason to touch them appearing per slice, consolidation is now worth costing.
- **A second load into the same holder does not clear the first movie's
  children.** Ruffle's `replace_with_movie` resets the clip's container
  outright ("Children and AVM data will NOT be kept across the load
  boundary"); our loader reuses an existing `sprite_display_list` as-is.
  Pre-existing for `_levelN` and unchanged in kind for clips (before this slice
  a second clip load piled onto the parent's GLOBAL list instead, which is
  wrong differently). `childMovieLoopBackClear` is the routine it would call;
  the work is measuring `avm1/loadmovie_replace_root` and the three
  `mcl_replace_root_*` tests.
- **`flashbang_upload_bitmap`'s fix is unverified.** Unchanged.
- **The constant-vs-`dictionary_capacity` divergence.** Unchanged.
