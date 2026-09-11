# A MovieClipLoader holder reports the loaded movie's frame counts

**Date:** 2026-09-11 · **Arc:** Multi-SWF (loaded children)
**Baseline:** `15f75a65f` · **Brief:** `/home/robert/.cache/wsl-launch-claude/run.eO2V80Qh/prompt.txt`
(kickoff committed in `15f75a65f`) · **Found in:**
`SWFRecompDocs/status/browser-root-side-gaps.md` §6
**Corpus baselines (read fresh off `origin/ruffle-test-results`):** graphics
`c7d24d557`, no-graphics `c1df12d64`.

A `createEmptyMovieClip` holder that `MovieClipLoader.loadClip` loaded a
multi-frame SWF into now reports the movie's `_totalframes` and
`_framesloaded`, and reads `_currentframe` **1** at `onLoadInit`. Before, it
read `tf:1 fl:1` forever and `cf:0` at `onLoadInit`. Fixture:
`regression/avm1_mcl_holder_totalframes`.

## 1. Mechanism

The two load drains in `action.c` do not write the same fields onto the target
clip.

| field | direct `loadMovie` (`actionFirePendingDirectLoads`) | MCL (`actionFirePendingLoadInits`), before |
|---|---|---|
| `url`, `swf_version`, `movie_id` | yes | yes |
| `byte_size` (`getBytesLoaded`/`getBytesTotal`) | yes | yes (added for `avm2/mouse_pick_avm1_root`) |
| `totalframes`, `framesloaded` | yes | **root replacement and images only** |
| `load_failed = 0` | yes | **images only** |
| `currentframe = 1` | yes, before the movie's init | **root replacement only** |

So for an SWF loaded into an ordinary clip, the holder kept what
`createEmptyMovieClip` gave it (`currentframe 0`, `totalframes 1`,
`framesloaded 1`). The per-tick playhead driver (`actionAdvancePlayingLevels`)
writes `currentframe` whenever it advances the movie, which is why `cf` did walk
1→N on later ticks and why only `tf`/`fl` stayed wrong for good. It never writes
the frame counts. The `cf:0` at `onLoadInit` was the same omission: Phase 2 runs
the movie's frame 1 before Phase 3 broadcasts `onLoadInit`, but nothing had
moved the playhead off 0 by then. The driver's first advance comes later.

`getBytesLoaded` / `getBytesTotal` read `byte_size`, not the frame fields, and
were already right. They were not part of the bug.

**Fix** (`action.c`, two writes, no new mechanism):

1. **Pre-phase**, next to the existing `byte_size` write for an SWF entry:
   `load_failed = 0`, `totalframes = framesloaded = entry->frame_count`. This
   skips `&root_movieclip`, because root replacement keeps its own write in
   Phase 2 and the `mcl_replace_root_*` cluster is graded on it.
2. **Phase 2**, in the `else` arm of the root-replacement block:
   `currentframe = 1` before `init_func` / `frame_funcs[0]`, mirroring the
   direct path.

## 2. What Flash / Ruffle report, and where it was confirmed

**Ruffle source.** `MovieClip::replace_with_movie` (`core/src/display_object/movie_clip.rs:375`)
builds new shared data with `total_frames = movie.num_frames()` and parks
`current_frame` at 0. `loader.rs:1787` calls it when the movie data arrives,
before `onLoadProgress`. `onLoadInit` is queued from `movie_clip_loaded`
(`loader.rs:2353`), which the frame loop reaches only after the clip has
run its first frame (`movie_clip_on_load`, "every MovieClip that has been
initialized (ran its first frame)").

**Ruffle, measured.** Local exporter, `RUFFLE_LOCAL_FETCH_DIR` +
`RUFFLE_MOVIE_URL=https://armorgames.com/test.swf`. The plain `file://` run
cannot load a child: `NullNavigator`, so both holders stay `tf:1 fl:1 bt:0`
(memory `ruffle-oracle-nullnav-perf-watchdog`). A scratch probe with every MCL
event traced, 4-frame child:

```
pre       cf:0 tf:1 fl:1 bl:0  bt:0    (createEmptyMovieClip)
start     cf:0 tf:0 fl:0 bl:0  bt:0    onLoadStart: the "initial loading" movie
progress  cf:0 tf:4 fl:4 bl:35 bt:35   replace_with_movie has run
complete  cf:0 tf:4 fl:4 bl:35 bt:35
t1        cf:1 tf:4 fl:4 ...           (root onEnterFrame)
init      cf:1 tf:4 fl:4 bl:35 bt:35   onLoadInit: the movie's frame 1 has run
t2..t4    cf:2, 3, 4                   then pinned by the child's stop()
```

**So `cf:0` at `onLoadInit` was a second bug, not Flash behaviour.** Ruffle
reads `_currentframe` 1 there, and 0 only in the progress/complete handlers
before it. The corpus has no test that reads a frame property inside an MCL
handler, which is why neither bug was graded. (Checked: no expected output among the MCL / loadClip
tests traces a frame property. The only `frame` lines are
`from_shumway/avm1/moviecliploader`'s own `loader frame N` / `loadee frame N`.)

**Ours, after the fix**, on the same probe: `progress`, `complete` and `init`
match Ruffle exactly. Two diffs remain, both out of scope:

* **`onLoadStart` does not model Ruffle's loading state.** Ruffle reads
  `tf:0 fl:0 bl:0 bt:0` there. We read the loaded movie's values (`tf:4 fl:4
  bl:35 bt:35`; before the fix `tf:1 fl:1 bl:35 bt:35`), because the Pre-phase
  writes everything before Phase 1 fires `onLoadStart`. The byte half of this
  predates this slice. Filed in BACKLOG. Not done here because
  `from_gnash/actionscript.all/MovieClipLoader-v5..v8` assert on
  `getProgress()` bytes inside the handlers, so it needs its own grading.
* **Order and double step.** Ruffle traces `t1` before `init` and walks
  `cf` 1,2,3,4. We fire `init` before `t1` and then step twice (`t1 cf:2`).
  That is the known late-landing MCL load plus the compensating double step
  (BACKLOG §Multi-SWF, brief §2), untouched.

## 3. Fixture — `regression/avm1_mcl_holder_totalframes`

MTASC parent (`Parent.as`, SWF8). Two `createEmptyMovieClip` holders load the
same hand-built 4-frame silent child (`stop()` on frame 4): `m` through
`MovieClipLoader.loadClip`, and `d` through `d.loadMovie` as the **negative
control**. Expected output is the Ruffle exporter's trace (recipe in
`create_test_swf.py`).

The per-tick rows are a change log printed at the end, not one trace per tick.
The child is silent too. Both choices keep the MCL timing residue above out of
the grade.

| row | fixed = Ruffle | full revert | revert Pre-phase write only | revert `currentframe` write only |
|---|---|---|---|---|
| `complete m` | `cf:0 tf:4 fl:4 bt:35` | `cf:0 tf:1 fl:1` | `cf:0 tf:1 fl:1` | = |
| `init m` | `cf:1 tf:4 fl:4 bt:35` | `cf:0 tf:1 fl:1` | `cf:1 tf:1 fl:1` | `cf:0 tf:4 fl:4` |
| `m [...]` | `[tf:4 fl:4 bt:35]` | `[tf:1 fl:1 bt:35]` | `[tf:1 fl:1 bt:35]` | = |
| `d [...]` (control) | `[tf:4 fl:4 bt:35]` | = | = | = |
| `end` | `m cf:4 d cf:4` | = | = | = |

(`=` means the row does not flip.) The `complete` row reads `cf:0` in Ruffle,
which also pins where the `currentframe` write lives: in the Pre-phase it
would read `cf:1` there. Every revert state was measured in BOTH modes, with identical rows (the full revert is the canary's baseline arm).

## 4. Local canary (before any CI)

128 tests, one `--diff -v` capture per state, byte-compared between `HEAD`'s
`action.c` and the fix. The list: all 31 `avm1/` tests matching
`mcl|moviecliploader|loadclip|load_cancel|loadmovie`, plus
`from_shumway/avm1/moviecliploader`, `from_gnash/actionscript.all/MovieClipLoader-v5..v8`,
`from_gnash/misc-ming.all/Version4Loader`, the whole `regression` suite (91
with the new fixture), and `from_gnash/misc-ming.all/loading/loadMovieTest`
run on its own. The gnash `*oadMovie*` glob in the brief matches nothing at the
suite's top level; the loadMovie test is nested one directory down.

| mode | tests | identical | changed |
|---|---|---|---|
| no-graphics | 128 + `loadMovieTest` | all but one | `regression/avm1_mcl_holder_totalframes` MISMATCH → PASS |
| graphics | 128 + `loadMovieTest` | all but one | the same fixture, MISMATCH → PASS |

## 5. CI

Both dispatches `categories=all`, `images=false`, serial. Graphics ran at the fix
commit `60bb82a8a`, no-graphics at the graphics results merge `ea6960eac` on top of it.
**Flat in both modes apart from the new fixture**, as the brief expected.
None of the brief's three upstream-drift tests moved, because both baselines
already include that drift.

| mode | run | vs | intersection | effective | regressions | new fixture |
|---|---|---|---|---|---|---|
| graphics | `34629934795` (green, incl. `wasm-link-smoke`) | `19d9abd4c` (results of the concurrent device-lost slice's run, `fbe53d342`) | 4516 | 4411 → 4411 | 0, no status moves | `pass` (regression 90 → 91 graded) |
| no-graphics | `34632640899` (green; watcher and two pollers OOM-killed on the host, read via the publish commit `67ba188ce`) | `ea6960eac` (no-graphics results `c1df12d64`, the brief's) | 4516 | 4411 → 4411 | 0, no status moves | `pass` (regression 90 → 91 graded) |

The graphics baseline is newer than the brief's `c7d24d557`: the concurrent
slice landed and published between launch and this dispatch, and its results were
already merged when this run started.

## 6. Side effects worth knowing

* `holder.gotoAndStop(n)` on an MCL holder now clamps to the movie's frame
  count instead of 1 (`ng_gotoFrameByMC`'s dynamic-clip arm reads
  `mc->totalframes`). A direct-loadMovie holder already did this. It still
  does not reach the loaded movie's frames (BACKLOG, out of scope). It only
  moves the reported `_currentframe`.
* A successful MCL load into a clip whose previous load failed now clears
  `load_failed`, as the direct path always did. Before, `_totalframes` kept
  reading 0 through the `load_failed` gate.
