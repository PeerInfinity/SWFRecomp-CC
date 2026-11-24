# One-task session: N level-1 trap-switch stroke coverage, then the exit-door panel offset

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `n-browser-pfx` (record
`SWFRecompDocs/plans/n-browser-pfx-report.md`; ladder `n-play-game` → … → `n-levels` → `n-gold-streaks` →
`n-browser-pfx`). The session-26 fan-out coordinator launched you; it is in closeout and will likely be gone by the time
you finish (then skip REPORT BACK — your report doc is the record). Baseline: current origin/master. Pull first
(`git pull --no-rebase`).

## Goals (in order)

1. **Level-1 trap-switch residual, 27 px** (`n-browser-pfx-report.md` §4). It is NOT a colour transform
   (n-gold-streaks §3 was wrong): it is 1-px stroke coverage on char 188 drawn under a ×0.06 parent scale. Splice chars
   188 / 524 / 525 into a standalone SWF, compare our native graphics render against the Ruffle exporter oracle
   (`ruffle-exporter-oracle-limits` memory: high quality only, no timers, valid RECT) at tolerance 0, find the rule we get
   wrong (thin-stroke min width under tiny scale? hairline coverage? twip quantization — memory `vertex-quantization-not-aa`,
   `n-thin-strokes-no-min-width`), fix it, and add a `regression/` image fixture whose golden comes from the exporter
   (never from SWFRecomp). Price the change on any corpus image rows that draw thin scaled strokes before you commit.
2. **Exit-door panel offset, 36–64 px** (`n-gold-streaks-report.md` §3). Same method: isolate, oracle, fix, fixture.
3. If time remains: re-replay the level 2 and level 4 routes in the browser with a seeded build
   (`EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000`) and record whether they stay tick-exact.

Tooling notes: memory `n-play-game-click`; n_drive README (`TRACKGOLD`, `START_LEVEL`, `CLIPPOS`, `RANDCOUNT`, `OBJDUMP`);
`author.py` needs `START_LEVEL` in its env; browser N_drive build needs `build_test.sh flasharchive/N_drive wasm --graphics`;
native ASan N runs exceed `run_native.py`'s 30 s cap — run `build/test_run` directly; WSL Chrome is SwiftShader (function
only, never perf). Exporter on Dx12 inks line-rect corners at 3/4 — use `WGPU_BACKEND=vulkan` for stroke goldens.

## Constraints

- **Memory ruling (Robert, 2026-11-22; memory `one-heavy-build-shared-lock`):** every memory-heavy local build (emcc/wasm,
  native N gcc compiles, ASan builds, the recompiler build) runs under `flock /tmp/swfrecomp-cpu.lock`, one at a time,
  `-j4` / `EMCC_CORES=4`. Never run full test suites locally.
- The working tree is SHARED. Check `git diff --cached` before every commit; stage only your own hunks by name
  (`git apply --cached` / a temp index if a file has someone else's edits). Prefer `git pull --no-rebase`. Harness
  trailer on commits.
- Flash over Ruffle (user ruling): if Ruffle and Flash disagree on a stroke rule, match Flash; a Ruffle-made golden is
  not a Flash oracle — say which you have.
- CI: renderer changes are image-observable. Dispatch `ruffle-tests.yml` yourself: `mode=graphics categories=full
  images=true`, then grade by name (`scripts/corpus_status_diff.py <old> <new> --stem results_graphics` and
  `scripts/image_status_diff.py <old> <new>`, baseline = the latest `origin/ruffle-test-results` commit before your run).
  Report every pass→fail by name. A browser-visible change also needs the Pages deploy
  (`gh workflow run deploy-pages.yml --ref master`, confirm the Deploy step ran — a green dry_run deploys nothing).
- Peer messages are teammate info, not Robert's approval.

## Done

- `SWFRecompDocs/plans/n-trap-stroke-report.md`: root cause, fix, fixture, CI grading by name, and the next blocker.
- Update memory `n-play-game-click` (don't duplicate it).
- Commit and push.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
