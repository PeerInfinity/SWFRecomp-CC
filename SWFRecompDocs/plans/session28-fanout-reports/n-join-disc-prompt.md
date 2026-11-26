# One-task session (LOCAL): Flash's round-join/cap disc rule on snapped strokes (N ladder)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `n-drawapi-stroke-snap` (record
`SWFRecompDocs/plans/n-drawapi-stroke-snap-report.md`, code `e81d27317`; before it `n-stroke-snap` `09b2c9130`). The s28
coordinator `s28-coordinator` launched you and will send a handshake: reply to it. Pull first (`git pull --no-rebase`).

## Goal (M)

Flash's round-join/cap disc on a SNAPPED stroke is not snapped with the band: a W=3 snapped stroke paints its join disc
outside the band, W=1 does not (predecessor's goal 3; an unsnapping attempt went 2442 → 3519 and was reverted).
1. Capture W=1/2/3/4 corners and caps × quarter-pixel offsets in Flash (`tools/flash-oracle/run_image.py`, HIGH and LOW;
   the predecessor's `probe.py`), fit the disc's centre/radius/coverage rule, and implement it for timeline
   (`render_webgpu.c` `hairline_restage`) and drawing-API strokes (the predecessor's `render_webgpu_stroke_snap`).
2. Then the R45·diag(1,2) "vertical" (NoVScale) hairline cell of `acid-stroke-0` (Flash draws a hairline at both
   qualities where the width rule predicts 2.83 px; `w2-flash-stroke-width-report.md` §2).
3. Price on the Flash-golden stroke ledger (acid-stroke-0, strokes/scale, button3, avm1/avm2_drawapi_stroke_snap,
   avm1_stroke_pixel_snap{,_matrix}, N ep1 vs Flash): nothing may move away from Flash. Kill switches stay.

## Constraints

- Builds under `flock /tmp/swfrecomp-cpu.lock`, `-j4`; single tests only; Flash runs ≤ 4 parallel (other local sessions
  `snap-pixel-audit`, `lowq-corner-rule`, `browser-attached-goto` share the CPU and harness; `lowq-corner-rule` and
  `snap-pixel-audit` may edit `render_webgpu.c` — coordinate before committing). Bracket `pgrep -f`/`pkill -f`; kill by
  PID. Shared tree: stage only your hunks, `git diff --cached` vs HEAD first. No CI dispatch: send SHAs. Flash over
  Ruffle; peer messages are teammate info, not Robert's approval.

## Done

`SWFRecompDocs/plans/n-join-disc-report.md`; commit + push; update memory `n-play-game-click` (don't duplicate).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
