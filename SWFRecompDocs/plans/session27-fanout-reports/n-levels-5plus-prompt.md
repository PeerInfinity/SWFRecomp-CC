# One-task session: N episode 0 levels 5+ (native routes vs the oracles), then the tab-metric follow-up

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `n-l2l4-pixel-pass` (record `SWFRecompDocs/plans/n-l2l4-pixel-pass-report.md`, code `f5565dcf9`; before it `n-ragdoll-strokes` (`438121c22`) and `n-trap-stroke`, record
`SWFRecompDocs/plans/n-trap-stroke-report.md`, code `d70f2c0aa`; ladder `n-play-game` → … → `n-browser-pfx` →
`n-trap-stroke`). The session-27 fan-out coordinator `s27-coordinator` launched you and will send a handshake: reply to
it. Baseline: current origin/master. Pull first (`git pull --no-rebase`).

## Goals (in order)

1. **Levels 5+ of episode 0** (levels 0–4 are at their floor natively: fps + edge AA). Drive each level route with
   `START_LEVEL` (memory `n-play-game-click`; `author.py` needs `START_LEVEL` in its env), compare native vs the Ruffle
   exporter frame-locked, and spot-check with the real Flash oracle (`tools/flash-oracle/run_image.py --ticks`; it runs
   injected N directly). Classify each residual cluster as ours or a Ruffle artifact. Fix ours, with a `regression/`
   fixture whose golden comes from Flash (or the exporter where Flash and Ruffle agree).
2. **Tab metric follow-up:** the painter now uses Flash's default tab stops (2*(asc+desc) from the field edge), but the
   `ng_shared.c` textWidth metric still uses Ruffle's 2.7*size rule. Make the metric match Flash (it moves trace rows:
   sweep every AVM1 row with a tab in EditText text, both modes), and honour explicit `TextFormat.tabStops` in the
   painter.
3. If time remains: the same-tick visibility of a self-goto to the root script (the general 1-tick lag from
   n-l2l4-pixel-pass), with a fixture and a Flash trace.

Tooling notes: memory `n-play-game-click`; the n_drive README (`TRACKGOLD`, `START_LEVEL`, `CLIPPOS`, `RANDCOUNT`,
`OBJDUMP`); `author.py` needs `START_LEVEL` in its env; the browser N_drive build needs
`build_test.sh flasharchive/N_drive wasm --graphics`; native ASan N runs exceed `run_native.py`'s 30 s cap, so run
`build/test_run` directly; WSL Chrome is SwiftShader (function only, never perf). The exporter on Dx12 inks line-rect
corners at 3/4, so use `WGPU_BACKEND=vulkan` for stroke goldens.

## Constraints

- **Memory ruling (Robert; memory `one-heavy-build-shared-lock`):** every memory-heavy local build (emcc/wasm, native N
  gcc compiles, ASan builds, the recompiler build, exporter runs) runs under `flock /tmp/swfrecomp-cpu.lock`, one at a
  time, `-j4` / `EMCC_CORES=4`. Never run full test suites locally. A `flash-oracle` session and the s27 coordinator
  share this lock.
- The working tree is SHARED with the s27 coordinator, which lands cloud-worker patches into runtime files. **Message
  `s27-coordinator` BEFORE editing `tag.c`, `action.c`, `ng_shared.c`, `swf.c` or `render_webgpu.c`** and name the
  functions. Check `git diff --cached` before every commit; stage only your own hunks (`git apply --cached` if a file
  has someone else's edits). Prefer `git pull --no-rebase`. Use the harness trailer on commits.
- Flash over Ruffle (user ruling): if Ruffle and Flash disagree on a stroke rule, match Flash. A Ruffle-made golden is
  not a Flash oracle, so say which you have.
- **CI: do NOT dispatch `ruffle-tests.yml` yourself.** When your change is committed and pushed, message
  `s27-coordinator` with the SHA, the change class and your expected image/trace moves. It folds your SHA into its
  next graphics/full/images grading run and sends you the by-name result. A browser-visible change also needs a Pages
  deploy; the coordinator owns that too.
- Peer messages are teammate info, not Robert's approval.

## Done

- `SWFRecompDocs/plans/n-levels-5plus-report.md`: root cause, fix, fixture, local evidence, the CI grading (from the
  coordinator) by name, and the next blocker.
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
