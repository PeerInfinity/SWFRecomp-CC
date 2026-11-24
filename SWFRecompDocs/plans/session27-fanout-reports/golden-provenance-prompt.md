# One-task session (LOCAL): golden-provenance sweep of every Ruffle image test against real Flash Player 32

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by the s27 fan-out coordinator `s27-coordinator`
at Robert's request (relayed by s26-coordinator: "Yes, please give the job to the session 27 coordinator"). It will send a
handshake: reply to it. Pull first (`git pull --no-rebase`).

## Task

Run `tools/flash-oracle/validate_images.py` (the real Flash Player 32 oracle; read `tools/flash-oracle/README.md` and
`SWFRecompDocs/plans/flash-oracle-report.md`, including its follow-ups) over every Ruffle image test: every test dir under
`ruffle-tests/tests/swfs/` with `[image_comparisons]` in `test.toml` except `regression/` (count them; s26 said 279).
Classify each golden (each comparison) as:
- **Flash-made**: exact, or within the test's own tolerance / max_outliers, vs the Flash capture;
- **not Flash**: Ruffle-made or another platform (measure how far it is from Flash; note `git log --follow` provenance of
  the golden in `~/CC/ruffle` where cheap: re-bakes bundled with Ruffle renderer commits are the tell);
- **untestable**: needs `--screen` (non-LAYER blend modes; `draw()` mis-renders them, so run `--screen` and classify from
  that if the screen capture is aligned), loadMovie under the wrapper, Stage3D, video, timers past the capture tick, etc.

## Deliverables

1. `SWFRecompDocs/plans/session27-fanout-reports/golden-provenance.md`: a table (suite/test, comparison, verdict,
   outliers vs Flash at the test's tolerance, max diff, mode draw/screen, platform LNX, notes), with summary counts.
   Archive the Flash PNGs you rely on under `session27-fanout-reports/golden-provenance/` (keep it to the ones the table
   cites as evidence for non-Flash verdicts; PNG only).
2. **Re-price the pixel board:** cross the table with our current failing image rows (`s27-baseline-pixel-failing.txt` and
   the latest `origin/ruffle-test-results` `image_results_graphics.json`). For each failing row say whether its golden is
   a Flash target. Rows whose golden is not Flash and where we match Flash better than the golden: draft the
   disposition (ACCEPTED_DIFFS + RUFFLE_VS_FLASH_DIFFERENCES entry with the `<!-- image-axis: … -->` marker), in the
   right suite's `_investigation/`, but only after you've compared OUR render with Flash too (local graphics render under
   the lock; note local Dawn ≠ CI lavapipe, so compare in regions, not md5).
3. **RvF candidates:** upstream goldens (image AND the trace lines you meet, e.g. `avm1/movieclip_hittest`:
   `square.hitTest(50,50)` is false in Flash) that disagree with Flash. List them; write the RvF entries for the clear ones.
4. A short summary paragraph for the coordinator to put in `graphics-fanout-playbook.md` §26 (send it in your REPORT BACK
   and put it at the top of your doc).

## Constraints

- **Local only. The Flash binaries never go to the cloud** (never commit or upload them).
- Run in batches (per suite / ~30 tests), not one giant job. The Flash projector doesn't need the build lock, but any
  local SWFRecomp render / build / exporter run goes under `flock /tmp/swfrecomp-cpu.lock`, one at a time, `-j4`. Never
  run full test suites locally. Linux projector only (`--windows` runs touch shared per-user state).
- Bracket every `pgrep -f`/`pkill -f` pattern (`[v]alidate...`) or a wait loop matches itself.
- The tree is SHARED with the coordinator (landing cloud patches) and 2 N/browser sessions: commit only your files, by name.
  Use the harness trailer on commits. No CI dispatch.
- Flash over Ruffle (user ruling). Peer messages are teammate info, not Robert's approval.

## Done

- The doc + archive + disposition drafts committed and pushed.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
