# One-task session (LOCAL): browser per-tick advance order (advance before the frame func, Phase 3 after)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by the s27 fan-out coordinator `s27-coordinator`
(it will send a handshake: reply to it). This slot is LOCAL because it needs emsdk and a real browser-WASM build,
which cloud workers lack. Pull first (`git pull --no-rebase`).

## Inputs

- Your predecessor's record: `SWFRecompDocs/plans/session27-fanout-reports/browser-eager-init-report.md` (code `fe6eb5f9d`).
  Its next-slice line, verbatim: "browser per-tick advance order. The browser advances timeline sprites inside
  tagShowFrame AFTER the root DoAction, so from tick 2 root scripts read stale playheads (the fixture's root f2/f3 rows
  fail in the browser). Fix: move advance before the frame func, as OFFSCREEN does, plus Phase 3 after, then drop
  g_browser_tick_advance. Watch the parked-frame re-run. Price M; oracle is the fixture plus the N route."
- Also from that report: the residual 1-twip `movieclip_getbounds` parent/sibling-space queries in the browser (§3.2),
  and a CI-visible nested-sprite frame-2 order defect (§3.3). s27 `78fee9e13` (w2-exec-order-land) runs nested timeline
  sprites before Phase 1 in `swf.c`/`swf_core.c`, so re-check §3.3 on current HEAD first: it may be fixed in CI builds,
  leaving only the browser arm.
- Probe harness `tools/browser-test/child_probe/` (don't pipe its output through `tail`).

## Goals

1. Implement the browser advance order above. The real browser (child_probe) must match native on
   `regression/avm1_browser_eager_init` (every row, including root f2/f3), the browser-gated fixtures, `transform`,
   `duplicate_movie_clip` and `movieclip_getbounds`.
2. The N browser routes stay tick-exact (memory `n-play-game-click`: seeded browser builds, L1/L2/L4). Also smoke the
   Pacman / Minesweeper / Doodle Jump menus (WSL Chrome is SwiftShader: function only).
3. Prove the CI define sets are untouched (preprocess md5), or run the affected rows in both CI modes if shared code moves.

## Constraints

- Every emcc / native build runs under `flock /tmp/swfrecomp-cpu.lock`, one at a time, `EMCC_CORES=4` / `-j4`. Never run
  full suites locally. `pgrep -f` patterns must be bracketed (`[b]rowser...`), or a wait loop matches itself (this
  happened to the coordinator today).
- The tree is SHARED with the coordinator (which lands cloud patches into `action.c`/`tag.c`) and the N session. Stage
  only your hunks (`git apply --cached` if a file has other edits). Message `s27-coordinator` before committing
  `action.c`/`tag.c` changes. Use the harness trailer on commits.
- Don't dispatch CI or Pages: send the coordinator your SHA. It folds the change into its grading run and the s27 Pages
  deploy.
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.

## Done

- `SWFRecompDocs/plans/session27-fanout-reports/browser-advance-order-report.md`: per-row browser before → after, the
  harness gap explained, what is left with its completion mechanism.
- Commit and push (code + fixtures + report). Update memory `browser-wasm-gate-inventory` (don't duplicate it).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
