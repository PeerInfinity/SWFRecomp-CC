# A loaded child SWF's timeline never advanced past its first frame

**Date:** 2026-09-03 · **Arc:** Multi-SWF (loaded children), slice 5
**Baseline:** `128828002` · **Brief:** `SWFRecompDocs/prompts/child-timeline-advance-prompt.md`
**Predecessor:** `SWFRecompDocs/status/child-embedded-asset-lookup.md`

**Landed:** a loaded movie advances one frame per tick, honours `stop()` from
inside itself and `stop()`/`play()` from the parent, and parks on its last
frame. Three regression fixtures assert the *sequence* with negative controls
in both directions.

**Not landed: looping.** It is measurably a facet of a larger missing thing —
a loaded movie does not own its display children — and the cheap route to
owning them is a corpus regression, measured twice. §2.2 has the numbers.

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

One `c1`, then identical rows forever. `tf:5` is already right (the loader
writes `mc->totalframes`), which is what makes the freeze quiet: the movie
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
no play state. That reading was right, and §2.1 says why it should stay that
way.

## 2. The rulings

### 2.1 Who owns the playhead

**The advance-table entry owns both the frame cursor and the play flag.** The
entry is the only thing that exists per *load*, which is the right granularity:

- **Not `MovieEntry`.** It is the immutable *program*. `getMovieEntryAt` hands
  the same pointer to every caller, and the same movie can be loaded into two
  holders; a playhead on it would be shared between independent loads.
- **Not the holder's `DisplayObject`** — and this is the ruling that cost the
  most to establish, because it is the one that looks obviously right. A clip
  target's holder is typically a `createEmptyMovieClip`, which has **no
  `DisplayObject` at all**. Measured, not inferred:
  ```
  PROBE fire: mc=holder is_level=0 fc=5 dobj=(nil) sdl=(nil) smax=0 depth=1
  PROBE after: dl1.char=1001 dl1.name=a
  ```
  (and the child's own placement landed in the ROOT's display list at depth 1).
  Giving the holder one is not a free fix: see §2.2, where the bare allocation
  alone regresses ten corpus tests.
- **Not the sprite playhead's DRIVER, `advance_sprite_frames` — the brief's
  "hope, not a finding", answered.** It cannot reach a loaded movie for three
  independent reasons, each fatal alone:
  1. it walks `display_list[]` and dispatches on
     `dictionary[obj->char_id].type == CHAR_TYPE_SPRITE`; neither a dynamic
     holder nor a `_levelN` target is in a display list at all;
  2. its frame call (`CALL_FRAME`) carries none of the per-movie context a
     child frame needs — SWF version, `_global` group, `movie_id`,
     `g_active_transform_data` — which is the entire reason
     `actionAdvancePlayingLevels` exists;
  3. the frame funcs would have to hang off `dictionary[char_id]`, shared by
     every instance of that character, so a timeline-placed holder would
     overwrite its own siblings' frame funcs.

Because the flag is not on any object the existing stop/play code already
writes, it is **routed to explicitly, at four sites**, each of which previously
fell through to the ROOT's `is_playing`:

| site | who calls it | what it did before |
|---|---|---|
| `actionStop` / `actionPlay` | the loaded movie's own frame script | fell through to the ROOT's `is_playing` — which the loaders save/restored around the child's frame call, i.e. the movie's `stop()` was **discarded** |
| the `stop` / `play` arms of `actionCallMethod` (both the NO_GRAPHICS/OFFSCREEN and the browser-WASM copy) | `holder.stop()` from the parent | fell through to `actionStop` and **stopped the ROOT** — a dynamic holder is missed by `ng_findDisplayEntryByName` and has no `display_obj`, so both of that arm's clip-specific branches missed it |

`actionChildMovieSetPlaying(mc, v)` returns 0 when `mc` has no loaded movie, so
every one of those sites falls through exactly as before when no child movie is
involved. `mc == NULL` means "the movie whose frame script is running", which
is how `actionStop`/`actionPlay` reach it (`g_child_movie_advance_mc`, set by
the driver and by both loaders around their `frame_funcs[]` calls).

### 2.2 Looping — not landed, and the reason is measured

**Ruffle is unambiguous about what should happen.**
`MovieClip::replace_with_movie` (`core/src/display_object/movie_clip.rs:371`) —
the function the load paths funnel into — swaps the clip's shared data for the
loaded movie, sets `total_frames` to the movie's frame count, sets
`MovieClipFlags::PLAYING` and parks `current_frame` at 0.
`determine_next_frame` (`:1340`) then answers `NextFrame::First` — wrap to
frame 1 — for any clip with more than one loaded frame and an End tag, which
every SWF *file* has. So a loaded movie plays and loops unless stopped.

**Why it is not here.** A wrap has to remove the movie's own display children
before re-running its frame 1; otherwise frame 1's `PlaceObject2` lands on an
occupied depth and the runtime *refuses and prints*
`Warning: Failed to place object at depth N.` (a graded line — the predecessor
established that). And a clip target's children are **interleaved with the
parent's in the global `display_list`**: nothing marks which of them the loaded
movie placed, so there is no set to clear.

The obvious fix is the one `_levelN` already has: give the holder its own
`DisplayObject` with a private `sprite_display_list` and swap to it around
every frame call. It was implemented, and it is **not** free. Measured by
bisecting it into two halves and running the affected corpus tests one at a
time:

| state | `movieclip_invalid_get_bounds_1..8` | `swf5_to_6_cross_call`, `swf6_to_5_cross_call` |
|---|---|---|
| baseline | pass | pass |
| holder gets a `DisplayObject`, **no** display-list swap | **fail** | pass |
| … plus the private display list, swapped in | **fail** | **fail** |

So ten corpus tests break, and the first row is the important one: **merely
allocating a `DisplayObject` for a dynamic holder is enough**, with no
display-list change at all. `mc->display_obj != NULL` is read at 48 sites in
`action.c` alone and is treated throughout as "this clip is a display object",
so handing one to a `createEmptyMovieClip` changes AVM1 behaviour well outside
this arc. `movieclip_invalid_get_bounds_1` loses one `Parent (7) …` row per
block — the one traced from a loaded movie's own `onEnterFrame` — and
`swf{5_to_6,6_to_5}_cross_call` lose the body of three trace blocks.

That is the same shape of finding the predecessor recorded for the renderer:
the cheap version of the change is a corpus-wide behaviour move made to fix a
narrow bug. **What looping actually needs is for a loaded movie to own its
display children**, which is the same missing per-movie abstraction as the
per-movie render tables — and note that a *shared* display list is also why a
clip-target child collides with the parent's depths today (the `_levelN`
branch's own comment records that bug:
`avm1/swf5_xml_event_handler_context`).

Two routes, for whoever takes it:

1. **Per-movie display-list ownership** — the honest one. Either make
   `mc->display_obj` safe to hand to a dynamic clip (find and fix what those
   ten tests actually read), or introduce a holder-side child list that is not
   `display_obj`.
2. **Tag the entries instead** — add `u8 placed_by_movie` to `DisplayObject`,
   written from `g_current_movie_id` at placement, and clear exactly those on
   wrap. Self-contained in the runtime, no harness change, and it parallels
   slice 3's `place_transform_data` ruling exactly (record *which movie* an
   entry came from). It buys the wrap only, not the depth collision.

Until then a loaded movie **parks on its last frame**, which is what a
`_levelN` load has always done, and the entry is kept rather than dropped so a
later `holder.play()` can still find the playhead.

### 2.3 Scope: AVM1 `loadMovie` vs AVM2 `Loader.load`

**AVM1 only.** Both AVM1 loader paths advance — direct
`loadMovie`/`loadMovieNum` (`actionFirePendingDirectLoads`) and
`MovieClipLoader.loadClip` (`actionFirePendingLoadInits`) — including the
`_levelN` targets that share the driver. All four stop/play routes (§2.1) are
AVM1.

**AVM2 `Loader.load` was already not frozen and is untouched.** An AVM1 movie
loaded by an AVM2 `Loader` runs on a third playhead, `g_avm1u2` /
`avm1UnderAvm2RunFrame` (`action.c`, `#ifdef SWF_AVM2`), which already loops —
`mixed_avm/avm2_loads_avm1_doabc` grades frames 1,2,1 across four ticks. An
AVM2 child's own timeline is driven by the AVM2 display list, not by this
table. So there is no AVM2 half of this defect beyond the note that `g_avm1u2`
is a fourth copy of the same context swap and a candidate for consolidation.

**What the `_levelN` / MCL paths changed**, since they share the driver — two
things, both narrower than they first look:

- **`playing` is now consulted for them too.** It is set to 1 at registration
  and can only be cleared by one of the four routes, so a level or MCL target
  behaves exactly as before unless something actually stops it — which is new
  and correct.
- **`armed` is NOT applied to them.** The loader calls `frame_funcs[0]` and the
  driver runs in the *same* tick right after it, so every target used to run
  **two** of the movie's frames on its load tick. Flash gives it one per tick,
  and clip targets of a direct `loadMovie` (which never advanced at all before)
  now get that. `_levelN` and MCL targets keep the double step, because
  removing it breaks `from_shumway/avm1/moviecliploader` — measured: that test
  has `num_frames = 3` and only reaches its loadee's `loadee frame 2` because
  of the double step. That is a real finding in its own right: **our MCL load
  completes a tick later than Flash's**, and the double step was compensating.
  Fixing the load timing is its own change; until then the asymmetry is
  deliberate and commented at the field.

**What AVM1 still does NOT have** (pre-existing, none introduced here):

- **Looping.** §2.2.
- **`holder.gotoAndStop(n)` does not target the loaded movie's frames.**
  `ng_gotoFrameCurrentSprite` and `ng_gotoFrameByMC` both require
  `dictionary[obj->char_id].type == CHAR_TYPE_SPRITE`, and a loaded holder has
  no character. `stop()`/`play()` work because they need none; `goto` needs the
  frame table, which for a loaded movie is on the `MovieEntry`. The advance
  entry is where a `goto` would land — it already owns the cursor.
- **Browser-WASM has no child-movie driver at all.** `swf.c`'s
  `actionAdvancePlayingLevels` call sits inside `#ifdef OFFSCREEN_RENDER`, so
  the in-page build never advances a loaded movie, on any path. Nothing in CI
  grades it. Unchanged either way by this slice.
- **A second load into the same holder does not clear the first movie's
  children.** Ruffle's `replace_with_movie` resets the container outright
  ("Children and AVM data will NOT be kept across the load boundary").
  Pre-existing.

## 3. Two more defects, both found by the fixtures

Neither is in the corpus's reach; both were found by writing sequence
assertions and reading what came back.

### 3.1 Marking the movie PLAYING after its frame 1 had already run

Registration is what creates the playhead, and the playhead starts playing.
The natural place to register is after `frame_funcs[0]` — where the old
`is_level` registration sat. But a movie whose own first frame calls `stop()`
— the preloader shape, and the commonest real stopped-loaded-movie there is —
then has that stop applied to a playhead that does not exist yet, and starts
playing when one appears.

Fixed by registering **before** `frame_funcs[0]` in both loader paths. Graded
by its own fixture with the over-correction as the negative control:

| state | output |
|---|---|
| correct | `S1`, then `cf:1 b:undefined` on every tick |
| registration moved back after frame 1 | `S2`, `S3` appear; `cf` climbs to 3; `b:movieclip` |
| whole slice reverted | identical to correct — a frozen movie and a correctly stopped one look the same |

That last row is why this fixture needs a sibling: it guards the fix against
over-running, and `avm1_child_timeline_advance` is what discriminates against
the baseline.

The same trap has a precedent in this runtime, which is some evidence it is a
class rather than a one-off: `ng_promote_attached_playheads`
(`swf_core.c:1229`) exists so an `attachMovie`'d clip is promoted to active
only "after the deferred attach-init drain … so a clip's frame-1 `this.stop()`
has applied before it is ever advanced".

### 3.2 The driver's copy-out write-back resurrected the stop it had just taken

`actionAdvancePlayingLevels` iterates by **copying** each entry into a local
`LevelAdvanceEntry e`, then compacting it back into the array. A `stop()`
inside the frame it just ran writes the LIVE array slot — and the write-back
then overwrote it with the stale `playing = 1`.

Symptom, exactly: `avm1_child_timeline_advance`'s movie stopped itself on frame
4 and frame 5 ran anyway. Caught the first time the fixture was run against the
finished code, not by inspection. Fixed by re-reading `playing` from the live
slot after the frame call.

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
at the end of every pass.

Fixed in the runtime rather than the harness, by save/restoring the pair around
every child frame call — the driver, the direct-load `frame_funcs[0]`, and MCL
Phase 2's `frame_funcs[0]`. The runtime is the right owner: it covers children
that reach it by any route, including the browser build and any future
generator, where a harness substitution covers only what `verify_output.py`
emits. The two `frame_funcs[0]` sites are unreachable for this today (frame 0
is a movie's last frame only when the movie has one frame, and a one-frame
movie emits `quit_swf = 1` instead); they are guarded anyway so the three sites
cannot drift.

## 5. The evidence — three fixtures, six measured states

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
t4 cf:4 tf:5 ax:30 b:undefined z:undefined     <- the movie's own stop()
t5..t7 identical                                <- and it HOLDS; no c5
play
c5
t8 cf:5 tf:5 ax:30 b:undefined z:movieclip     <- holder.play() resumed it
t9..t12 identical                               <- parks on the last frame (§2.2)
```

Every row is load-bearing. A playhead that jumped to the last frame passes an
end-state test and fails `t1`; one that ran all five frames in a tick fails
`t2`; a `_currentframe` that moved without running tags fails `ax`/`b`; a
missed `stop()` fails `t5`; a `play()` that did not reach the playhead fails
`t8`. The `t9..t12` rows are the park, and are a **lock on known-incomplete
behaviour**: when looping lands they must flip to `cf:1 ax:10`, deliberately.

### `regression/avm1_child_timeline_holder_stop`

6-frame child with no `stop()` of its own. The parent stops it at t3 and plays
it at t6, so `cf` reads 1, 2, 3, 3, 3, 3, 4, 5, 6, 6, 6. The frozen rows are
mid-movie with three frames still to run, so they cannot be confused with the
park; `ax` freezes with `cf`, so they cannot be confused with a counter that
stopped while the tags kept running.

### `regression/avm1_child_timeline_frame1_stop`

§3.1 above.

### Negative controls, all six run

| control | fixture | result |
|---|---|---|
| whole slice reverted (`128828002`) | `advance` | `c1` alone; `cf:1 ax:10` on all 12 rows |
| whole slice reverted | `holder_stop` | `L1` alone; `cf:1 ax:10` on all 11 rows |
| whole slice reverted | `frame1_stop` | **passes** — documented in the fixture; not the baseline discriminator |
| registration after frame 1 | `frame1_stop` | `S2`/`S3` appear, `cf` reaches 3 |
| holder gets a `DisplayObject` | `movieclip_invalid_get_bounds_1..8` | fail (§2.2) |
| … plus the private display list | `swf{5_to_6,6_to_5}_cross_call` | fail (§2.2) |

## 6. Do the existing multi-SWF fixtures still mean what they said?

Two of the five were written around the freeze. Re-checked individually, and
**the meaning of one changed**:

| fixture | still means what it said? |
|---|---|
| `avm1_parent_child_modify_place` | **The reason for its shape is now obsolete.** Its child places and Modifies in ONE frame explicitly because "a loaded child never reaches its frame 2"; that constraint is gone. What it *asserts* — the transform-table lookup and the char-id-0 sentinel — is untouched and still passes, so the test is unchanged and correct; only its docstring's rationale is historical. Left as-is deliberately: same-frame place+Modify is a real shape worth pinning, and rewriting it to cross frames would re-point a test that guards a different bug. Its `create_test_swf.py` and README row now carry a pointer here. |
| `avm2_parent_child_symbol_stride` | Unaffected — an AVM2 `Loader.load` child, driven by the AVM2 display list, not this table. |
| `avm1_parent_child_bitmap` | 1-frame child; nothing to advance. |
| `avm1_parent_child_sprite_meta` | 1-frame child. |
| `avm1_parent_as3_child_payload` | 1-frame child. |

The predecessor's blind-spot claim holds and is now quantified: **of the ~440
child SWFs in the corpus, 21 have more than one frame**, and only a handful of
those load into an AVM1 clip target. That is why the freeze survived four
slices.

## 7. Verification

1. **Three fixtures**, six measured states, §5.
2. **Local per-test sweep** of every corpus test that loads a child SWF plus
   the whole `regression` suite — 168 tests, one at a time, diffed against a
   baseline sweep of the same list at `128828002`. §8.
3. **`gcc -fsyntax-only -std=gnu17 -Wall -Werror=return-type -DNO_GRAPHICS`**
   over `action.c` with the harness's include set: no errors, no new warnings
   on any changed line. (`verify_output.py` compiles with `-w` and would show
   none of it.) No generated C changed — the recompiler is untouched — so the
   brief's emitted-C sweep does not apply.
4. **CI**, both modes: §9.

## 8. Local sweep

168 tests, run one at a time (never a whole suite locally), against a baseline
sweep of the same list at `128828002`: every corpus test that has a child SWF
sibling and loads it — the `loadmovie*` / `loadmovienum*` / `unloadmovie*` /
`mcl_*` / `load_cancel_*` / `register_class*` / `*cross_call` /
`movieclip_invalid_get_bounds_1..8` / `focusrect_property_swf[567]` /
`global_swf*` clusters, `from_gnash/misc-{ming,mtasc}.all`'s loaders,
`from_shumway/avm1/{levels,moviecliploader}` and `avm1movie`, all of
`mixed_avm` and `import_assets` — plus the whole `regression` suite.

```
88 canary tests   : 88/88 identical status to baseline (12 fail on both sides)
regression suite  : 80/80 pass (77 pre-existing + this slice's 3)
new failures      : 0
```

The twelve that fail on both sides are the suite's standing non-passes
(`globals_monkeypatch`, `load_cancel_via_unload{clip,movie}`,
`mcl_replace_root_swf7_to_swf{5,6}`, `movieclip_library_state_values`,
`from_gnash/misc-ming.all/{DragDropTest,loading/loadMovieTest}`,
`from_gnash/misc-mtasc.all/levels`, `from_shumway/avm1movie`,
`mixed_avm/{avm1_loads_avm2,avm2_loads_avm1_events}`).

This sweep is what caught §2.2's eleven-test regression — the first design's
CI run was cancelled and the design reworked before it finished.

## 9. CI

### The run that found the eleventh test

`mode=graphics`, `categories=full`, `images=false` at `86d4d6aac` — **success**,
run `33821303934`, complete (30/30 shards). It found exactly one regression the
local sweep could not, because the local sweep runs `no-graphics`:

```
=== intersection: 4487 tests (128828002 -> 86d4d6aac, results_graphics) ===
  output_mismatch    124 ->   125 (+1)
  pass              4127 ->  4126 (-1)
  effective         4362 ->  4361 (-1)
REGRESSIONS (effective -> fail): 1
  avm1/unloadmovie_method: pass -> output_mismatch
```

`mc.unloadMovie()` never called `actionUnregisterLevelAdvance`. It never needed
to: a clip target of a direct `loadMovie` was never registered for per-tick
advancement, so there was nothing to unregister. The other three unload entry
points (`unloadMovieNum`, `MovieClipLoader.unloadClip`, the `getURL` unload
path) all carry that call already, each with the same comment — the deferred
unload queue only flips `mc->unloaded` on the NEXT tick, so without an
immediate unregister the movie runs one more frame and reaches its terminal
`TEST FAILURE: I should be unloaded by now!` line. **Graphics-only** because in
`no-graphics` the main loop exits early on root stop and never gets there;
reproduced locally with `--mode=graphics` before the fix and verified after, in
both modes, along with `unloadmovie`, `unloadmovienum`, `mcl_unloadclip`,
`load_cancel_via_removemovieclip` and `loadmovienum_cross_version_prototype`.

The driver's drop condition gained `avm1_removed` in the same change — same
class: a `removeMovieClip`'d holder halts its own script execution, so its
loaded movie must not keep running.

### The final runs

Both modes at `1ccb87a95`, `categories=full`, `images=false`, both
**conclusion success**, both complete (no `metadata.incomplete` on any suite).
Graphics run `33826698339`, no-graphics run `33826714102`. Diffed against
`128828002` — this slice's own pre-slice base, not the intermediate commits,
so the numbers are the whole slice.

Both modes were dispatched because the change is shared runtime code with no
graphics guard, which is CLAUDE.md's "when in doubt, run both" case — and it
earned its keep: the `unloadmovie_method` regression above appeared in graphics
only.

#### `mode=graphics` — run `33826698339`

```
=== intersection: 4487 tests (128828002 -> WORKTREE, results_graphics) ===

STATUS HISTOGRAM
  output_mismatch    124 ->   124 (+0)
  pass              4127 ->  4127 (+0)
  ruffle_matched     235 ->   235 (+0)
  runtime_error        1 ->     1 (+0)

  effective         4362 ->  4362 (+0)

GAINS (fail -> effective): 0
REGRESSIONS (effective -> fail): 0
OTHER STATUS MOVES (failing on both sides): 0
```

#### `mode=no-graphics` — run `33826714102`

```
=== intersection: 4487 tests (128828002 -> WORKTREE, results) ===

STATUS HISTOGRAM
  output_mismatch    123 ->   123 (+0)
  pass              4127 ->  4127 (+0)
  ruffle_matched     236 ->   236 (+0)
  runtime_error        1 ->     1 (+0)

  effective         4363 ->  4363 (+0)

GAINS (fail -> effective): 0
REGRESSIONS (effective -> fail): 0
OTHER STATUS MOVES (failing on both sides): 0
```

Every bucket unmoved in both modes — not just the pass/fail line, so a test
that was already failing and started segfaulting would show. The one-test
`output_mismatch`/`ruffle_matched` difference between the modes is the
pre-existing mode difference the two predecessors recorded, present on both
sides of each diff. The `regression` suite reads **80/80 pass** in both modes,
which is the 77 that existed plus this slice's three.

**Read this as the regression check it is, not as the slice's yield.** No
corpus test loads a multi-frame child SWF into an AVM1 clip target — 21 of the
~440 child SWFs have more than one frame and only a handful reach that path —
so a corpus headline cannot move for this work in either direction. The
fixtures in §5 are the evidence; §8's sweep and this are what say nothing else
broke.

## 10. What is left of the arc

- **A loaded movie does not loop, because it does not own its display
  children.** §2.2, with two routes and the measurement that rules out the
  cheap one. This is now the top of the multi-SWF list, alongside the renderer
  item it shares a cause with.
- **Per-movie render tables — a loaded child movie does not render at all.**
  Unchanged and now unblocked: this slice was the gate. It and the looping item
  are the same missing abstraction seen from two sides.
- **`holder.gotoAndStop(n)` does not target the loaded movie's frames.** §2.3.
- **Our MCL load completes a tick later than Flash's**, which
  `from_shumway/avm1/moviecliploader` (`num_frames = 3`) only survives because
  of the same-tick double step. §2.3.
- **Browser-WASM never advances a loaded movie.** §2.3.
- **A second load into the same holder does not clear the first movie's
  children.** §2.3.
- **Four copies of the per-movie context swap** now exist
  (`actionFirePendingDirectLoads`, `actionAdvancePlayingLevels`,
  `actionFirePendingLoadInits` Phase 2, `avm1UnderAvm2RunFrame`). Each was
  duplicated deliberately to keep arcs from perturbing each other; with a fifth
  reason to touch them appearing per slice, consolidation is worth costing.
- **`flashbang_upload_bitmap`'s fix is unverified.** Unchanged.
- **The constant-vs-`dictionary_capacity` divergence.** Unchanged.
