# s26 w1-per-movie-displaylist: the per-movie display-list arc behind `avm1/video_prototype_lazy_swf6_child`

**Slot:** wave 1 (diagnosis + measured prototype) · **Branch:** `fanout/w1-per-movie-displaylist`
**Code base:** origin/master `ec07cc9e` (runtime identical to the s26 baseline `697669e5f`) · **Upstream Ruffle tests:** `3e98d9ba6`
**Box:** SETUP_STATUS all OK (apt, Pillow, Dawn/lavapipe).

**New files:** this report and `w1-per-movie-displaylist-prototype.patch`
(`git diff origin/master -- SWFModernRuntime`: 3 files, +323/−8). No source change is committed.

## Verdicts

| item | verdict | flips | price |
|---|---|---|---|
| **Phase 1: holder-owned display list ("shell") for a dynamic clip-target holder + loaded-movie goto route** | **GO** (prototype measured, whole patch) | **+1: `avm1/video_prototype_lazy_swf6_child` 4/8 → pass, both modes** | **M** (it was priced L; see the refutation below) |
| Phase 2: remaining per-tick walks and resolvers over shells (clip-event enterFrame, button/hit, string paths, text-field windows, Phase-3 order) | HOLD: no corpus row moves. Correctness hardening. | 0 | M |
| Phase 3: timeline-placed holders (holder HAS a `display_obj`): loaders swap into its sprite list too | HOLD: no row moves | 0 | S |
| Phase 4: goto fidelity (queue the target frame's DoAction, `survives_rewind`, a bare `gotoAndStop` inside the child rewinds the ROOT, one-frame movies) | HOLD: no row moves; the third bullet is a real latent bug | 0 | S–M |
| Phase 5: unload/reload semantics on a shell, browser-WASM driver | HOLD | 0 | S each |

**Gate measured (graphics = CI mode, plus no-graphics):**
- **Every loaded-child row I could find**: 104 rows, listed in §3. Graphics: **103 identical** to the s26 baseline CI results
  (`9277f3799`), plus the headline flip. No-graphics: 33 rows (all 15 loaded-child regression fixtures, the headline,
  `movieclip_invalid_get_bounds_1..8`, `swf{5_to_6,6_to_5}_cross_call` and the basic loadMovie/MCL rows). **32 are
  identical** and the headline flips.
- **The whole `regression` suite** (130 tests) in both modes: see §5.
- **Pixels**: A/B on the 4 loaded-child regression rows with golden images: see §5.

### Refutation: the arc is not L for this row
s25 priced the row **L** (`w1-avm1-proto-timeline-report.md` §4). That rested on two claims:
1. "the bare `display_obj` allocation regresses ten rows", and
2. "the loaded children are interleaved with the parent's".

Claim 1 is true, but it only rules out *that* vehicle. A holder-side list that is **not** `display_obj` (route 1b in
`child-timeline-advance.md` §2.2) does not touch any of the 48 `display_obj != NULL` reads. Measured: all ten of
those rows are unchanged in both modes.

What the shell does need is to be visible to the handful of consumers that the shared list used to cover **by
accident**:
- the renderer;
- the `getMember` child lookup, which today resolves a loaded child through a ROOT-level name search;
- the sprite advance walk;
- the realloc rebase walk.

The last surprise was not a display-list problem at all: `actionInvalidateCachedMovieClip` matches a clip by
**(name, depth) with no parent**. So once the depth collision is gone, the child's `RemoveObject2(v2)` invalidates the
**parent's** `_root.v2`. That one is small and self-contained.

## 1. The data model today (origin/master line numbers)

- **One global depth-indexed array.** `extern DisplayObject* display_list; size_t max_depth;` (`swf.h:516`).
  Depth *d* is slot `display_list[d]`; a `PlaceObject2(depth d)` writes it (`tag.c:11042 tagPlaceObject2`).
  Nested sprites own a private `sprite_display_list`, and a `_levelN` target gets a heap `display_obj` with one.
- **Where a loaded child's placements land.** `actionFirePendingDirectLoads` (`action.c:26751`) swaps to a private
  list **only for `_levelN`** (`action.c:26849`, comment "Only a _levelN target gets its holder's own display list").
  `actionFirePendingLoadInits` Phase 2 (`action.c:40458`) never swaps, not even for levels.
  `actionAdvancePlayingLevels` (`action.c:25850`) swaps only when the holder already has a `display_obj` with a
  sprite list. So the frames of a `createEmptyMovieClip` holder's movie (the usual clip target) run with
  `display_list` = **the root's global list**.
- **How the keys collide.** The child's `PlaceObject2(depth 2)` and the parent's own `PlaceObject2(depth 2)` both write
  `display_list[2]`. The child's is refused with the graded `Warning: Failed to place object at depth 2.` from the
  Phase-3 occupied-depth gate (`tag.c:11252`). That is the s25 measurement.
- **Ownership stamp.** `DisplayObject.placed_by_holder` (`swf.h:295`), written at `tag.c:11824/12423` from
  `actionCurrentChildMovieMC()`. It lets the wrap clear the movie's own entries
  (`actionClearChildMoviePlacements`, `action.c:25834`). It buys looping, **not** separate keys.
- **Identity of a placed child.** The MovieClip is created with `parent = g_current_context` (= the holder, under the
  loaders' context swap). Sprites get this eagerly (`tag.c:11919` "Phase 7b"), Videos via `actionOnVideoPlaced`
  (`action.c:43041`), and everything else lazily on lookup. So the logical tree is right; only the storage is shared.
- **Lookups that lean on the sharing.** `actionGetMemberImpl`'s child arm (`action.c:60626`) searches
  `mc->display_obj->sprite_display_list`. For a holder with no `display_obj` it **falls back to the ROOT-level name
  search** `ng_findDisplayEntryByName` (`tag_stubs.c:1597`, comment at `action.c:60706`). That fallback is how
  `holder.a` resolves today, and it is also a leak: the same entry answers `_root.a`.
- **Invalidation key.** `actionInvalidateCachedMovieClip(name, swf_depth)` (`action.c:24929`) takes the first live
  clip with that name and depth, **whatever its parent**. Called from `tagRemoveObject2`'s no-UNLOAD arm.
- **Loaded holder goto.** `actionCallMethod`'s gotoAndStop/Play arm (`action.c:74776`) tries
  `ng_gotoFrameByMC`. A holder has no sprite character, so it fails and falls to `actionGotoFrame`, which is a
  **root** goto. So `this.gotoAndStop(2)` inside the child rewinds or advances the parent.

## 2. What the headline needs, line by line

`test.swf` (SWF8) and `child.swf` (SWF6) each place a Video as `v2` at depth 2 on frame 2. The child's frame 1 then
runs `this.gotoAndStop(2)`, `gotoAndStop(1)`, `gotoAndStop(2)` on its own timeline. Baseline lines 4–7 fail:
- 4 and 5 fail because the child's goto never reaches its own timeline.
- 6 and 7 follow from that, because R never gets the lazy props.

Fixing it took four mechanisms, measured in order:

| step | lines matched |
|---|---|
| baseline | 4/8 |
| goto route + shell (the depth collision is gone) | 5/8: line 4 OK |
| + parent-preferred invalidation (a backward goto no longer invalidates `_root.v2`) | **8/8** |
| + shell `getMember` arm (needed by `avm1_child_timeline_loop`, below) | 6/8 at first, because `shell->sprite_max_depth` is stale while the shell is swapped in. Reading the live globals when the shell is the active list gives **8/8** |
| + shell sprite advance (needed by `avm1_parent_child_sprite_meta`, below) | 8/8 |

Two existing rows regressed on the way, and both are fixed in the final patch:
- `regression/avm1_child_timeline_loop` went 34/34 → 25/34 (`h1.a` undefined) until the `getMember` shell arm. It
  proves that the root-name fallback was load-bearing.
- `regression/avm1_parent_child_sprite_meta` went 8/8 → 7/8 (`cB:n`: a 2-frame sprite inside the movie froze) until
  `ng_advance_child_movie_shells`.

## 3. The phased plan of record

### Phase 1 (M): GO, prototype attached and measured
Patch scope. **Functions touched** (siblings: `w1-attached-button-dispatch` is in attached-clip button dispatch; the
local N session may touch `tag.c`/`swf.c`):

*`action.h`*
- `struct MovieClip`: trailing field `void* loaded_dl_shell`.

*`action.c`*
- **new** `actionChildMovieShell(app, mc, create)`: allocates the shell only for a non-root, non-level holder with
  `display_obj == NULL`.
- **new** `static childDLSwapIn` / `childDLSwapOut`: re-entrancy safe, because a goto issued from inside a frame
  that is already swapped in does not double-swap.
- **new** `actionChildMovieGoto(app, mc, frame0, play)`: a tags-only catch-up on the advance entry's cursor, under
  the full per-movie context swap. A backward goto runs `actionClearChildMoviePlacements` first.
- `actionAdvancePlayingLevels`: uses the shell when the holder has no `display_obj`.
- `actionFirePendingDirectLoads`: swaps the shell in for clip targets and clears the shell on reload (Ruffle
  `replace_with_movie`).
- `actionFirePendingLoadInits` (Phase 2): the same swap and clear.
- `actionGetMemberImpl`: a shell child arm. The shell is authoritative for the holder, so there is no root
  fallback.
- `actionCallMethod`: the NG/OFFSCREEN `gotoAndStop/gotoAndPlay`, `prevFrame` and `nextFrame` arms route to
  `actionChildMovieGoto` before `ng_gotoFrameByMC`.
- `actionInvalidateCachedMovieClip`: while a child-movie frame runs, prefer the clip whose parent is the running
  context. It falls back to the old first match when there is none.

*`tag.c`*
- **new** `static ng_advance_child_movie_shells`: called first thing in `ng_advance_attached_clip_playheads`, which
  is the slot both CI tick loops already call right after the root sprite advance.
- **new** `static mc_content_dobj`.
- `render_attached_child` and the `tagRerenderFrame` capture pass: draw a shell under the holder's world transform.
- `ng_spriteDLRealloc`: rebases the shell's base copy and walks it.

No `swf.c`, `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS`-only arm is touched, so mode parity holds by construction
(and was measured).

**Rows moved:** `avm1/video_prototype_lazy_swf6_child` (+1, both modes).

**Rows that must stay put** (all measured identical, §5):
- every loaded-child row in §3a;
- the 10 rows that killed the `display_obj` route: `movieclip_invalid_get_bounds_1..8` and
  `swf{5_to_6,6_to_5}_cross_call`;
- the `regression` suite.

**HOLDs inside Phase 1** (deliberate, each named for wave 2):
- (a) Shell sprites advance after root sprites, with nested children inline (no Phase-3 deferral). The exec order
  differs from Ruffle's newest-first list when parent and child sprites both trace on the same tick. No row shows it.
- (b) `actionChildMovieGoto` suppresses the target frame's DoAction (Flash queues it) and clears everything on a
  backward goto (no `survives_rewind`). That is s25's apply_goto HOLD, unchanged.
- (c) In OFFSCREEN the shell renders only for root-parented holders, the same restriction attached clips already
  have (`render_attached_child` pass, `#ifdef OFFSCREEN_RENDER`).

#### 3a. The loaded-child corpus (every row found; s26-baseline graphics status)
I found these by byte-scanning every test's SWFs (zlib-inflated) for `loadMovie|loadClip|MovieClipLoader|unloadMovie|_level[1-9]`
in `avm1 from_gnash from_shumway regression`, plus every avm1 row that ships more than one SWF. That gives **104 rows**.

Failing or `ruffle_matched` among them, i.e. the fragile or open set, **none moved by Phase 1**:
- `avm1`: `globals_monkeypatch` 49/306, `sandbox_type_remote` 1/3, `video_prototype_lazy_swf6_child` 4/8 (**→ pass**).
- `avm1`, ruffle_matched: `load_cancel_via_unloadclip` 3/3 and `load_cancel_via_unloadmovie` 5/5;
  `mcl_replace_root_swf7_to_swf5` 56/57 and `mcl_replace_root_swf7_to_swf6` 52/57.
- gnash `MovieClip-v5..v8` (352/363, 916/936, 949/969, 1062/1087), `MovieClipLoader-v7/v8` (47/165 each),
  `TextField-v6..v8` (532/545, 557/570, 559/571), `DragDropTest` 40/44, `loading/loadMovieTest` 71/80, `levels` 49/68.

Passing but fragile, i.e. they exercise exactly what Phase 1 rewires, all unchanged:
- `regression/avm1_child_timeline_{advance,frame1_stop,holder_stop,loop}`
- `regression/avm1_parent_child_*` (8 rows), `avm1_mcl_{holder_totalframes,load_tick}`
- `movieclip_invalid_get_bounds_1..8`, `swf5_to_6_cross_call`, `swf6_to_5_cross_call`
- `mcl_loadclip`, `movieclip_state_values`, `loadmovie*`, `unloadmovie*`
- `from_shumway/avm1/moviecliploader`, `from_shumway/avm1/levels`

**Attack on "other loadMovie rows move with this arc":** refuted again, now with the fix in hand. Not one of the 15
open loaded-child rows moves. Their diffs are other mechanisms: the gnash MovieClipLoader-v7/8 rows are MCL event and
`getProgress` semantics; `loadMovieTest`/`DragDropTest` are `_level5`/drag; `levels` is `_levelN` paths. So Phase 1
is a **1-row** yield. Its value is that it removes the shared-key hazard that every later loaded-child fix would
otherwise trip on: looping, nested loads, a goto into a loaded movie, and rendering a holder at its own transform.

### Phase 2 (M): HOLD, no row
The consumers that still see only the root list (the shell is invisible to them):
- **Clip events in shells.** `collect_attached_standalone` (`tag.c:6288`) feeds `ng_upgrade_attached_standalone_initialized`,
  `dispatch_enterframe_clip_actions_impl` and `hasClipEnterFrameHandlers`. It needs a shell arm: yield
  `(shell, holder)` when `loaded_dl_shell` is set.
- **Button state and hit testing** over shells: `ng_update_button_states_in_dl` and `hit_test.c`. Coordinate with
  `w1-attached-button-dispatch`.
- **String and slash paths and enumeration.** `action.c` ~22242/22361 path resolution, `ng_findChildEntryDepth`
  (`tag_stubs.c:1660`), `ng_enumerateChildren` (`ng_shared.c:1513`, used by for-in over a holder), and the ~50
  `ng_findDisplayEntryByName(mc->name)` sites. Each needs "if the holder has a shell, search it". The getMember arm
  is the template.
- **Text-field depth windows** (`actionSetTextFieldDepthWindow`) for DefineEditText a loaded movie placed.
  `avm1_parent_child_text` passes, so placement and render are fine; the window ordering is untested.
- **Phase-3 nested-advance deferral** for shells (HOLD (a) above).

**Completion mechanism:** one `regression/` fixture per consumer, with Ruffle-exporter goldens (LOCAL ORACLE
REQUESTS #1). Priced M because each arm is the getMember template repeated.

### Phase 3 (S): HOLD, no row
The holder already has a `display_obj` with a sprite list (a timeline-placed clip, or `attachMovie`). Today the
loaders run frame 1 into the **global** list while the driver runs frames 2..N into the sprite list; that is the
asymmetry `actionAdvancePlayingLevels`' wrap comment documents. Make both loaders swap into `display_obj`'s sprite
list as well (the `owner` choice in `actionChildMovieGoto` already does). It also covers the MCL path for `_levelN`,
which never swaps today. **Completion:** a fixture that loads into a timeline holder and traces a frame-1 child next
to a parent child at the same depth.

### Phase 4 (S–M): HOLD, one latent bug worth a fixture
- **A bare `gotoAndStop(n)` / `nextFrame()` in the child's own frame code** (ActionGotoFrame/GotoFrame2 with no
  target) reaches `actionGotoFrame`, which is the **root** goto. It rewinds the parent: the "last-frame rewinds
  parent" family again, through a different door. Route `actionGotoFrame` to `actionChildMovieGoto(g_current_context)`
  when `actionCurrentChildMovieMC()` is the running context. No corpus row hits it (s25's byte scan found the
  headline's `child.swf` as the only child SWF with goto at all, and it uses the method form).
- Queue the target frame's DoAction, and apply `survives_rewind` on a backward goto (HOLD (b)).
- A one-frame loaded movie has no advance entry, so `holder.gotoAndStop(1)` still falls to the root goto. Register
  every loaded movie, or make `actionChildMovieGoto` a no-op for any holder with a loaded `movie_id`.

### Phase 5 (S each): HOLD
- `unloadMovie` on a holder with a shell. Today the content stays in the shell (it stops advancing because the pump
  skips `mc->unloaded`, but it still renders). Clear the shell in the unload path, the same loop as the reload clear.
  `unloadmovie*`, `movieclip_state_values` and `load_cancel_*` are unchanged.
- Browser-WASM has no child-movie driver at all (`child-timeline-advance.md` §2.3), unchanged.

## 4. Evidence: the headline

Before (graphics, clean master): `output_mismatch` 4/8, with lines 4–7 as in arc §26.4.
After: **pass** in graphics and no-graphics.

## 5. Gate results

All runs used single-test `verify_output.py --tests-dir=… --test=… --verbose`, at most 2 parallel. The baseline is
the committed s26 results (`_results/results_graphics.json` / `results.json` at `9277f3799` / `dffc41cf2`). The
runtime on this branch is byte-identical to that run's code.

| set | mode | rows | result vs baseline |
|---|---|---|---|
| loaded-child corpus (§3a) | graphics | 104 | 103 identical; `video_prototype_lazy_swf6_child` 4/8 → **pass** |
| loaded-child core (regression ×15, headline, `movieclip_invalid_get_bounds_1..8`, `swf5_to_6_cross_call`, `swf6_to_5_cross_call`, `loadmovie`, `loadmovie_method`, `mcl_loadclip`, `movieclip_state_values`, `load_cancel_via_removemovieclip`, `unloadmovie_method`, shumway `moviecliploader`) | no-graphics | 33 | 32 identical; headline → **pass** |
| whole `regression` suite | graphics | 130 | **130/130 pass** (baseline 130/130) |
| whole `regression` suite | no-graphics | 130 | **130/130 pass** (baseline 130/130) |
| pixels: `regression/avm1_parent_child_{render,text,morph,bitmap_fill}` (tolerance 0 goldens; the content now draws through the shell at the holder's transform) | graphics `--images` | 4 | all **PASS, max diff 0**, the same as the s26 images baseline (max diff 0) |

**Pixel coverage limit:** of the other loaded-child rows with images, `mcl_target_*` and
`movieclip_methods_with_loaded_image` load images, which take no shell (an image load exits before the swap), and
`netstream_play_flv_screen` loads no SWF. So the four goldens above are the whole shell-render surface the corpus
grades. Those goldens are exact, so a local pass at max diff 0 is CI-grade, without needing an
`origin/ruffle-image-results` fidelity check.

**Two intermediate regressions, both fixed in the final patch** (§2):
- `avm1_child_timeline_loop` 34 → 25 before the getMember shell arm;
- `avm1_parent_child_sprite_meta` 8 → 7 before the shell sprite advance.

They are the measured reason those two pieces are in Phase 1 and not Phase 2.

**Recommended wave-2 CI:** `graphics/all` plus `no-graphics/all`. The change is shared runtime in both modes. It is
not AVM2 emission, so `full` is optional. Add `images=true` only if the coordinator wants the pixel axis re-stamped.

## New unclaimed leads
- **`actionInvalidateCachedMovieClip` is parent-blind everywhere, not only for loaded movies.** Any two same-named
  clips at the same AS depth under different parents (two sprites each placing a child `btn` at depth 1, one of them
  removed) can invalidate the wrong one. The prototype scopes the fix to child-movie frames. The general fix is to
  pass the removing list's owner MC and match on it. Unpriced. Build a fixture first.
- **Root-name fallback leak.** For a holder WITHOUT a shell (e.g. one created after its load), `holder.x` still
  resolves any ROOT child named `x`, and `_root.x` resolves a loaded child's `x` on master. Flash would give
  undefined. Phase 2 closes the second half; the first half is an `actionGetMemberImpl` rule change. Needs a fixture
  before touching it (avm1/target_paths pins the sprite half).
- **Bare goto inside a loaded movie rewinds the root** (Phase 4, bullet 1): S, fixture-first.

## LOCAL ORACLE REQUESTS
1. (For Phase 2/4 fixtures, not blocking.) Ruffle exporter `--trace-log`, 6 frames, on a two-SWF fixture: the parent
   `createEmptyMovieClip("h",1); h.loadMovie("c.swf")` places `x` at depth 1. `c.swf` has 3 frames:
   - frame 1 places sprite `x` at depth 1 with `onClipEvent(enterFrame){trace("cx")}`, and runs `trace(_root.x == h.x)`;
   - frame 2 runs a bare `gotoAndStop(1)` (no target);
   - frame 3 runs `trace("c3")`.

   I need: whether `cx` fires every tick, whether `_root.x == h.x` (expected false), and whether the parent's frame
   counter is unaffected by the child's bare goto. The coordinator can build the SWFs with MTASC/swfasm from this
   description; I did not commit fixtures because the goldens must come from outside SWFRecomp.
