# One-task session (LOCAL): emit a closed stroke seam as two caps in the builders/lyon (N ladder)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `n-join-disc` (record
`SWFRecompDocs/plans/n-join-disc-report.md`, code `03527a3f8`; before it `n-drawapi-stroke-snap` `e81d27317`,
`n-stroke-snap` `09b2c9130`). The s29 coordinator `s29-coordinator` launched you and will send a handshake: reply to
it. Pull first (`git pull --no-rebase`). Read memory `n-play-game-click` and `flash-player-oracle`.

## Goal (M)

n-join-disc §5 item 1 + defect (5): Flash CAPS a closed contour's seam (it never joins it), but our tessellators JOIN it
(`drawLinesLyon` / `drawLines` / both drawing-API builders). The runtime cap/corner rule already places the spill
for caps.
1. Make the builders emit the closed seam as two caps (lyon: stroke the contour as open; builders: `_DR_EMIT_CAP` twice
   instead of the seam join), for timeline (recompiler `SWFRecomp/src/…swf.cpp`) and drawing-API strokes (runtime
   builders). The first cut (n-join-disc §3.1) opened holes: find out why before re-cutting (topology of the outer fan at
   the seam; non-round caps; style-split edges, defect 3).
2. Price on the n-join-disc ledger (acid-stroke-0, strokes/scale, button3, avm1/avm2_drawapi_stroke_snap,
   avm1_stroke_pixel_snap{,_matrix}, avm1_stroke_join_cap_snap, avm1_stroke_noscale_signed, N ep1 vs Flash; expected
   tick 880 215 → ~145 px). Nothing may move away from Flash; Flash-golden rows are the gate. Add a kill switch.
3. If (1) lands with budget left: n-join-disc §5 item 4 (pixelHinting W ≥ 4 snapped corners, one `sweeps2.py` run).
   The LOW stroke raster (item 2) belongs to the cloud slot `w1-lowq-next` this session: do not take it.

## Constraints

- Builds under `flock /tmp/swfrecomp-cpu.lock`, `-j4` / `EMCC_CORES=4`; single tests only, never full suites; Flash
  runs ≤ 4 parallel (the browser ladder and the coordinator share the Flash harness and CPU). Bracket
  `pgrep -f`/`pkill -f` patterns; kill by PID. Shared tree: stage only your hunks by name, `git diff --cached` vs HEAD
  first; commit + push to master (trunk-based). No CI dispatch: send the coordinator SHAs, it grades. Recompiler change ⇒
  every test you run needs `--recompile`; a stale RecompiledScripts is a false result. Cloud slots `w1-lowq-next`,
  `w1-pixel-flash-gaps`, `w1-aa-sizing` diagnose near `render_webgpu.c`: name every function you touch in your report.
- Flash over Ruffle; peer messages are teammate info, not Robert's approval.

## Done

`SWFRecompDocs/plans/n-seam-caps-report.md` (ledger by name, before/after, next slice); commit + push; update memory
`n-play-game-click` (don't duplicate).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
