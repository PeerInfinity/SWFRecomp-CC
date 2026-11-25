# One-task session (LOCAL): Flash-oracle harness fixes found by trace-provenance

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by the s28 coordinator `s28-coordinator`
(it will send a handshake: reply to it). Pull first (`git pull --no-rebase`). You succeed `trace-provenance` (record:
`SWFRecompDocs/plans/session28-fanout-reports/trace-provenance.md` §"Harness findings").

## Goals (tools/flash-oracle/ only; S–M)

1. `flashenv.parse_rect` crashes on a 0-bit RECT (gnash swfmill `tags_after_last_showframe`): fix, and re-run that row.
2. **PinStub pollutes `_global`** (`_global.PinStub`, `_quality` leak into `_global` enumeration): build a stub that
   leaves no trace in the test's globals (MTASC, `capture/build.sh`), prove it on the rows trace-provenance named, and
   check it keeps the window pin.
3. The default run cap truncates long dumps and 0.25-fps tests: derive the cap from `num_frames`/`num_ticks` and the
   frame rate (with the overrun direct mode already has), so no capture is silently short; make truncation LOUD.
4. `--log-warnings`: some goldens need it although `test.toml` lacks it — add an auto-detect (golden contains Flash
   warning lines) or document the rule in the README.
5. **Root onLoad trap**: the pinned mode replaces `_level0`, so Flash fires no frame-1 root onLoad (measured s28,
   `w1-local-oracles/w1-drift/README.md`). Make `run_trace.py` warn (or auto-`--no-pin`) when the SWF defines a root
   `onLoad`, if it can be detected cheaply; else document it prominently.
6. Re-run every trace-provenance row whose verdict depended on a harness defect above, and update its doc row
   (append a "harness re-run" note; don't rewrite the table).
Update `tools/flash-oracle/README.md` and memory `flash-player-oracle` (don't duplicate it).

## Constraints

- Local only; the Flash binaries never leave this box (never commit/upload them). Linux projector runs may go in
  parallel; Windows runs strictly one at a time. Any SWFRecomp build: `flock /tmp/swfrecomp-cpu.lock`, `-j4`.
- The tree is SHARED with the coordinator and two ladder sessions; commit only your own files, by name, with the
  harness trailer. No CI dispatch.
- Bracket every `pgrep -f`/`pkill -f` pattern; kill by PID.

## Done

`tools/flash-oracle/` fixes committed and pushed, README + memory updated, a short report at
`SWFRecompDocs/plans/session28-fanout-reports/flash-oracle-harness-report.md`.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
