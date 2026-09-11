# Slice: `MovieClipLoader.loadClip` leaves the holder's `_totalframes` at 1

**Baseline: `master` at launch.** The launching session may have landed another
slice (the AVM2 child SymbolClass binding) since this brief was written. CLAUDE.md
and this project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there; don't
re-derive them.

**Corpus baseline: take the newest graphics and no-graphics results commits on
`origin/ruffle-test-results` that are already merged into `master`, and read the
numbers off them yourself. Never quote a figure from a brief** (memory
`ci-baseline-must-be-read-fresh`). At launch those were `c7d24d557` (graphics)
and `c1df12d64` (no-graphics), merged in `13dfc5b48` / `d1721c233`. Three tests
moved there from **upstream drift**, verified against the Ruffle commits:
`avm2/geom_transform` (`45be8d5365`, DisplayObject.z),
`from_avmplus/ecma3/JSON/adhoc` (`af88e41a58`, a new `output.ruffle.txt`) and
`avm1/bitmapdata_custom_rectangle` (`352718de29`, 34→42 expected lines). They
will show up against any older baseline, and they are not yours.

## 1. The defect

From `SWFRecompDocs/BACKLOG.md` §Multi-SWF, and
`SWFRecompDocs/status/browser-root-side-gaps.md` §6, where it was found:

> A holder that `MovieClipLoader.loadClip` loaded into reports `_totalframes`
> **1**, while the loaded movie's own frames run and `_currentframe` walks 1→3.
> Seen in **every** build, so it is not a browser gap. Direct `loadMovie` gets it
> right (`regression/avm1_child_timeline_advance` reads `tf:5`), so the gap is in
> the MCL registration path, not the movie-entry machinery.

The probe that found it logged `onLoadInit h cf:0 tf:1`. So at `onLoadInit`,
`_currentframe` read **0** as well. Find out what Flash reports there before
treating `cf:0` as correct or as a second bug: check Ruffle's `loader.rs` /
MovieClipLoader handling in `~/CC/ruffle` and the upstream MCL tests' expected
output. The probe harness is `tools/browser-test/child_probe/`. Its parent and
child are a ready-made native repro too.

Start by comparing the two registration paths. Direct `loadMovie` goes through
`actionFirePendingDirectLoads` → `actionRegisterChildMovieAdvance`; find where
that path writes the holder's frame count, and where the MCL path skips or
overwrites it. Check the sibling frame-count readers while you are there:
`_framesloaded`, and `getBytesLoaded` / `getBytesTotal` if they share the field.
Memories `loaded-child-timeline-stuck-frame-0` and `mcl_load_timing` cover the
playhead-state model you will be reading.

## 2. Out of scope (same backlog entry, deliberately not yours)

- The MCL load landing **a tick late**, and the double frame step on
  `_levelN`/MCL targets that compensates for it. Removing that step breaks
  `from_shumway/avm1/moviecliploader`.
- `holder.gotoAndStop(n)` not targeting the loaded movie's frames.
- A second load into the same holder not clearing the first movie's children.

If your fix turns out to need any of these, stop and report rather than widening
the slice.

## 3. Grading

- **The corpus cannot see this defect** (otherwise some test would already
  fail), so add a `regression/` fixture, e.g. `avm1_mcl_holder_totalframes`: an
  MTASC parent that `loadClip`s a multi-frame child into a
  `createEmptyMovieClip` holder, reading `_totalframes` (and any sibling you fix)
  at `onLoadInit` and on later ticks. Include a **negative control**: a
  direct-`loadMovie` holder read the same way, which must stay correct. Rows must
  flip on revert. Take the expected values from Ruffle's behaviour, not from our
  own output. Ship the generator next to the SWF, and add the fixture to the
  `regression/README.md` table.
- **Local canary before any CI** (individual tests only, `-P 5` is safe):
  every `avm1/` test with `mcl`, `moviecliploader`, `loadclip`, `load_cancel` or
  `loadmovie` in its name; `from_shumway/avm1/moviecliploader`; the gnash
  loader tests (`from_gnash/*/*oadMovie*`, `*MovieClipLoader*`); and the
  **whole `regression` suite**. Diff ACTUAL output against a pre-change run,
  not just status (memory `local-regression-sweep-stash-diff`).
- **CI:** AVM1 runtime (`action.c`), so `categories=all`, `images=false`. The
  MCL drains run in both frame loops (`swf.c` and `swf_core.c`), so run
  **both** modes, **serially**. Read each with
  `scripts/corpus_status_diff.py <pre_merge_sha> WORKTREE --per-suite`
  (`--stem results` for no-graphics). Expected: flat corpus apart from the new
  fixture (+1 graded in `regression`). Report any other movement by name.

## 4. Traps

- **A RED `wasm-link-smoke` IS evidence**, even for a change that is
  preprocessor-identical in both CI test modes: that job builds the BROWSER
  config on every dispatch.
- **`single_test` resolves the bare name against `tests/swfs/avm1` ONLY.**
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`from_shumway/as3-loader/bug1157243/empty` is a known load-sensitive
  intermittent**, so do not re-derive it if it moves.
- **`git stash` is shared across worktrees.** Use patch files for
  byte-identity checks.
- Pattern kills are guard-denied. Use literal PIDs.
- Dispatch CI modes serially, and never run a status-poll loop alongside a live
  `gh run watch`. The zero-quota fallback is in `.claude/pipeline-handoff.md`.
- **Another slice may be sharing this tree and CI**: `browser-webgpu-device-lost`
  (browser-only, `render_webgpu.c`). Stage by name only, and **before each
  `ruffle-tests.yml` dispatch, confirm no run of it is in progress or queued**
  (`gh run list --workflow ruffle-tests.yml --status in_progress`, then
  `--status queued`). If one is, `gh run watch` it to completion first.
  Overlapping runs clobber each other's results merge.

## 5. Done means

1. Closeout doc `SWFRecompDocs/status/avm1-mcl-holder-totalframes.md`:
   mechanism, what Flash/Ruffle report and where you confirmed it, the fixture's
   rows with revert attribution, the canary table, and both CI run IDs.
2. BACKLOG §Multi-SWF: strike the `_totalframes` entry. If the `cf:0` question
   resolves either way, record the answer in the MCL-probe entry above it.
3. Memory: add or update whatever is non-obvious (e.g. `mcl_load_timing`).
4. Commit and push to `master`, CI both modes per §3, merge
   `ruffle-test-results`, and report any regressions by name.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
