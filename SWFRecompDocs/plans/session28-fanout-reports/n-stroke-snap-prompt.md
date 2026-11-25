# One-task session (LOCAL): Flash thin-stroke pixel snapping (N ladder head)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `n-levels-5plus` (record
`SWFRecompDocs/plans/n-levels-5plus-report.md` §4 and §9, code `58a51a781`; ladder `n-play-game` → … → `n-trap-stroke` →
`n-ragdoll-strokes` → `n-l2l4-pixel-pass` → `n-levels-5plus`). The session-28 fan-out coordinator `s28-coordinator`
launched you and will send a handshake: reply to it. Baseline: current origin/master. Pull first (`git pull --no-rebase`).

## Goal (M–L)

Flash Player 32 pixel-snaps thin strokes; Ruffle and we draw every stroke unsnapped (centred on the edge, AA'd). From
the parked fixture `SWFRecompDocs/plans/n-levels-5plus-hairline-fixture/` (Flash golden `output.expected.flash.png`;
60×20 px stroked rects at +0/5/10/15 twips):
- hairline (1 twip) and 1-px (20 twips) strokes are drawn SOLID on pixel `floor(edge)`;
- a 2-px (40 twips) stroke's centre snaps to the nearest pixel edge;
- a 1.5-px stroke is plain AA.
It is the whole remaining gap to Flash on N gameplay and load screens (console box, gold-coin outlines, one-way
platform edges).

1. **Pin the rule** with more Flash captures before implementing (you can run `tools/flash-oracle/run_image.py`
   locally; read its README; direct mode pinned): widths 1..4 px in 0.25-px steps, under scale (0.5×, 2×, `_xscale`
   non-uniform), rotation (is it axis-aligned only?), curves vs straight segments, `lineStyle` scaleMode
   (`normal`/`none`/`horizontal`/`vertical`) and `pixelHinting` true/false — is the snap Flash's pixelHinting applied
   always, or only to thin strokes? Does it apply to AVM2 `Graphics` and to DefineShape strokes alike?
2. **Implement** where the rule needs device space: stroke tessellation is in shape space (recompiler `swf.cpp`), the
   snap needs the final matrix (runtime). Choose the owner (runtime re-tessellation of thin strokes with device-space
   snapping, or a vertex-shader snap for stroke geometry flagged at recompile time) and say why. `MSAA_SAMPLES` never a
   literal 4 in `render_webgpu.c`.
3. **Price on the image corpus**: this moves many image rows whose goldens are Ruffle-made. List every image row with
   strokes whose excess moves (render locally only what you need; the coordinator runs an `images=true` CI run on your
   SHA). Rows with FLASH goldens (`session27-fanout-reports/golden-provenance.md`: e.g. `acid-stroke-0`,
   `acid-shapes*`, `graphics_simple_shapes`, `graphics_draw_triangles`, and the `place_object_test`/`shape_test` Flash
   root captures) are the real oracle: they must move toward Flash. A Ruffle-golden row moving away is a priced
   Flash-over-Ruffle loss (RvF + image-axis marker), not a reason to stop. Cloud workers `w1-acid-flash`,
   `w1-avm2-vector-flash` and `w1-render-flash-headroom` are diagnosing some of those rows in parallel: their reports
   land under `session28-fanout-reports/`; read them if present, and tell the coordinator if your change explains
   their residual.
4. Land the hairline fixture as `regression/` with its Flash golden, and re-check N (native, frame-locked) vs Flash.

Tooling: memory `n-play-game-click`; n_drive README; the exporter on Dx12 inks line-rect corners at 3/4, so use
`WGPU_BACKEND=vulkan` for stroke goldens; WSL Chrome is SwiftShader (function only, never perf).

## Constraints

- Every heavy local build (emcc/wasm, native N, recompiler) runs under `flock /tmp/swfrecomp-cpu.lock`, one at a time,
  `-j4` / `EMCC_CORES=4`. Never run full suites locally. Bracket every `pgrep -f`/`pkill -f` pattern; kill by PID.
- The tree is SHARED with the coordinator (landing cloud patches), `trace-provenance`, and the browser ladder session.
  Stage only your hunks. Message `s28-coordinator` before committing `swf.cpp`/`render_webgpu.c`/`tag.c` changes. Use
  the harness trailer.
- Don't dispatch CI: send the coordinator your SHA; it grades it in an images run.
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.

## Done

- `SWFRecompDocs/plans/n-stroke-snap-report.md`: the rule as pinned (table + captures archived under
  `SWFRecompDocs/plans/n-stroke-snap-captures/`), the implementation, the priced image-row ledger, N vs Flash after,
  and the next slice.
- Commit and push. Update memory `n-play-game-click` (don't duplicate it).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
