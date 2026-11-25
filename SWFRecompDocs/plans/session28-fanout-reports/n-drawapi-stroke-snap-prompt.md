# One-task session (LOCAL): Flash stroke snap for drawing-API strokes + the perf check the timeline snap owes

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `n-stroke-snap` (record
`SWFRecompDocs/plans/n-stroke-snap-report.md`, code `09b2c9130`, docs `ac3294c6b`; N ladder). The s28 coordinator
`s28-coordinator` launched you and will send a handshake: reply to it. Pull first (`git pull --no-rebase`).

## Goals (in order)

1. **Perf check first (S, owed by `09b2c9130`):** every timeline stroke draw is now re-staged on the CPU each frame.
   A/B N in the browser on a REAL GPU (Windows Chrome via WSL interop — memory `windows-playwright-from-wsl`,
   `tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`; WSL Chrome is SwiftShader, never perf) with the snap on vs
   `SWF_STROKE_SNAP=0` (or the parent commit), plus a native frame-time A/B. If the cost is material, cache the
   re-staged geometry per (draw, device matrix) before anything else.
2. **Drawing-API strokes (M):** apply the same Flash rule (report §1: u = round(4·device width); snap only exactly
   axis-aligned segments with u ≤ 4, 8 or 12; pixelHinting → all widths, W = max(1, u/4); AA width 2·floor(u/2)/4) to
   the runtime-tessellated paths: AVM1 Drawing API (`action.c`; thickness truncated to integer px) and AVM2 `Graphics`
   (`avm2_display.c`; thickness ROUNDED). Flash-golden rows to move toward Flash: `from_shumway/acid/acid-shapes*`,
   `avm2/graphics_simple_shapes`, `graphics_draw_triangles`, `graphics_draw_path`, `cache_as_bitmap/drawing_api`, and
   N's drawing-API strokes. Fixtures with Flash goldens (run `tools/flash-oracle/run_image.py`, ≤ 4 parallel).
3. If time remains: cap/join residue (N mines, 2–3 px corners) and the `acid-small` slight move away (report §5.2).

## Coordination

- The cloud slot `w2-flash-stroke-width` (Flash's isotropic stroke WIDTH model, noH/noV flags) and `w2-lowq-sample-point`
  (LOW-quality sample point) are working near you; their reports land under `session28-fanout-reports/`. Keep hunks
  separable; message `s28-coordinator` before committing `action.c` / `avm2_display.c` / `render_webgpu.c` changes.
- Every heavy local build under `flock /tmp/swfrecomp-cpu.lock`, `-j4` / `EMCC_CORES=4`. Never run full suites locally.
  Bracket every `pgrep -f`/`pkill -f` pattern; kill by PID. The tree is SHARED: stage only your hunks.
- Don't dispatch CI: send the coordinator your SHA; it grades in an images run. Flash over Ruffle; peer messages are
  teammate info, not Robert's approval.

## Done

`SWFRecompDocs/plans/n-drawapi-stroke-snap-report.md` (perf numbers, rule coverage, Flash-golden ledger, next slice);
commit + push; update memory `n-play-game-click` (don't duplicate).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
