# w1-loaders: wave-1 diagnosis of loaders, MovieClipLoader timing, loaded-child gaps (AVM1 + AVM2 + mixed)

Read `BRIEFS_COMMON.md` first. This is read-only work with no source edits (scratch fixtures in your
scratch dir are fine). Deliverable: `SWFRecompDocs/plans/session19-fanout-reports/w1-loaders-report.md`.
Scratch dir: `<scratchpad>/w1-loaders/`.

Read first: today's closeouts `SWFRecompDocs/status/avm1-mcl-holder-totalframes.md` and
`avm2-child-symbolclass-binding.md`, plus `SWFRecompDocs/BACKLOG.md` (grep `MovieClipLoader`,
`button_data_for_char`, `tick late`), and memory `mcl_load_timing` (it has the exporter recipe for a
parent loading a relative child).

## Your board
**Failing corpus tests (re-run before believing them):**
- `avm2/loader_events_2` 2/35 (KF, RTXT), `avm2/mouse_pick_loader_avm1` 16/42,
  `from_shumway/as3-loader/LoaderLoadBytesTest` 1/4,
  `from_shumway/as3-loader/events/loader-events` 5/36 (KF, RTXT)
- `mixed_avm/avm1_loads_avm2` 3/7 (s18: "harness"; re-verify),
  `mixed_avm/avm2_loads_avm1_events` 7/26 (KF, RTXT)
- LoaderInfo `unload` (arc §19.4, which has no named test; find the corpus test that grades it, if any)

**Leads from today's single-task slices.** No corpus test is known to grade any of them, so SCOPE
them; do not implement:
1. **MCL loads land a tick late**: `onLoadInit` fires before the root's first `onEnterFrame`,
   where Ruffle fires it after. This is the cleanest remaining MCL diff. It is tangled with the
   double frame step that `from_shumway/avm1/moviecliploader` relies on (`num_frames = 3`; it
   reaches `loadee frame 2` only because of the double step). Scope a fix that moves the load
   tick AND drops the double step together. Name the tests that grade each half (gnash
   `MovieClipLoader-v5..v8`, shumway moviecliploader, the `regression/avm1_mcl_*` fixtures) and
   give a Ruffle-exporter oracle trace for a minimal fixture.
2. **MCL `onLoadStart` doesn't see Ruffle's initial-loading state**: tf/fl/bytes read 0 there in
   Ruffle, but we pre-write the loaded movie's values. Gnash `MovieClipLoader-v5..v8` assert on
   `getProgress()` bytes inside handlers, so say exactly which of their lines move.
3. **A loaded child's `SimpleButton` has no states**: `button_data_for_char` (`avm2_display.c`)
   has no `g_child_movies` fall-through, although `Avm2MovieTables` carries `buttons`. This came
   from code reading, not a failing test. Build a minimal parent+child fixture (the exporter is
   the oracle) and confirm or refute it.

For each lead: GO/HOLD/NO-GO, size, files, the regression fixture it needs, and its risk to
currently-passing loader tests.

Siblings: w1-avm1-display (timeline/action order), w1-avm2 (AVM2 singles, including
`bytearray_bad_symbol_class_other_movie`), w1-drift, w1-avm1-builtins, w1-gfx-*.
