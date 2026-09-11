# avm1_mcl_load_tick

Where a `MovieClipLoader` load lands in the tick. Two coupled facts, fixed
together; each is a one-line-pair discriminator on its own.

1. **`onLoadInit` fires on the tick AFTER the load's own drain**, in the slot
   between that tick's `enterFrame` broadcast and the loaded movie's advance —
   `t1 h.cf=1`, then `onLoadInit cf=1`, then `c2`. Our Phase 3 used to run in
   the same pass as phases 1 and 2, inside `tagShowFrame`, which is ahead of
   the root's first `onEnterFrame`. The queue that defers it is
   `g_pending_load_inits` in `action.c`; the drain is
   `actionDrainPendingLoadInits`, called immediately before
   `actionAdvancePlayingLevels` in `swf_core.c`, `swf.c`, and the
   AVM1-under-AVM2 tick. **The position is the whole point** — draining at the
   existing end-of-tick MCL site instead gives `t1, c2, onLoadInit`.
2. **A MovieClipLoader target starts UNARMED.** The loader runs the movie's
   frame 1 itself (Phase 2) and `actionAdvancePlayingLevels` runs later in the
   *same* tick, so arming at birth ran frame 2 as well. That double step was
   compensating for (1)'s position, not for the delivery tick.

| revert | you get |
|---|---|
| (1) alone | `c1, onLoadInit cf=1, t1 h.cf=1, c2` — onLoadInit above `t1` |
| (2) alone | `c1, c2, t1 h.cf=2, onLoadInit cf=2` — the movie a frame ahead |
| both (the pre-fix state) | `c1, onLoadInit cf=1, c2, t1 h.cf=2, c3, t2 h.cf=3` |

## What this test deliberately does NOT encode

The **delivery** tick. Our `onLoadStart`/`onLoadProgress`/`onLoadComplete`
(and the movie's frame 1) land one tick later than Ruffle's, and that is
**Flash's** order: `from_shumway/avm1/moviecliploader` grades exactly this —
its Flash `output.txt` puts `loader frame 2` before `onLoadStart`, its
`output.ruffle.txt` does not, and we pass it by following Flash. Moving
delivery to Ruffle's tick would turn that `pass` into `ruffle_matched` on a
`known_failure = true` test, i.e. a regression.

So this fixture uses a **one-frame** loader, for which `loadClip` takes the
`_this_tick` bucket and the whole Ruffle trace is reachable without touching
the two-bucket deferral (`builtin_mcl_loadClip`'s `defer_to_next_tick` +
`actionPromotePendingMCLLoads`). A two-frame-loader fixture would encode
Ruffle's delivery tick and must not be created. Analysis:
`SWFRecompDocs/plans/session19-fanout-reports/w1-loaders-report.md` §4.

## The shape

    test.swf   AVM1 (MTASC, Parent.as), ONE frame: createEmptyMovieClip("h"),
               a MovieClipLoader with all four handlers, an _root.onEnterFrame
               tracing `t<N> h.cf=<h._currentframe>` (self-deleting after 6),
               then loadClip("child.swf", h)
    child.swf  hand-assembled, 3 frames: DoAction Push "cN" + Trace per frame,
               with a Stop on frame 3 so the playhead parks (the `t4..t6
               h.cf=3` rows)

`num_ticks = 8` — enough for all six `t` rows plus the load tick.

## Oracle

`output.txt` is the local Ruffle exporter's trace, byte for byte — never our
own output. Recipe (memory `mcl_load_timing`): both SWFs under
`<dir>/armorgames.com/`, then

    RUFFLE_LOCAL_FETCH_DIR=<dir> RUFFLE_MOVIE_URL=https://armorgames.com/test.swf \
      ~/CC/ruffle/target/release/exporter test.swf out -s -f 8 --trace-log ruffle.txt

A plain `file://` movie URL silently never loads the child.

## Rebuild

    python3 create_test_swf.py     # needs ~/CC/mtasc/bin/mtasc
