# Minesweeper perf — real bottleneck was GPU writeBuffer, not AVM1 walks

**Date:** 2026-06-17
**Commit:** `079c0fefe` (perf(render): batch per-frame dynamic GPU buffer writes)
**Supersedes the diagnosis in:** `SWFRecompDocs/plans/minesweeper-perf-static-subtree-pruning.md`

## TL;DR

The difficulty screen was CPU-bound at ~12fps. The plan doc blamed ~5 recursive
AVM1 display-tree walks (advance/presync/enterframe/button) and proposed
"static-subtree pruning". **That diagnosis was wrong for the browser.** A real
in-browser CPU profile showed the bottleneck is **`writeBuffer` at ~88% of frame
CPU** — the WebGPU renderer issued a separate tiny `wgpuQueueWriteBuffer` per
dynamic shape (every text glyph, drawing-API shape, bitmap quad), hundreds of
calls/frame, and the per-call marshalling overhead dominated. The AVM1 walks are
**<2%** in the browser.

Why the plan doc was wrong: its breakdown came from the **NO_GRAPHICS native
profile**, where rendering is stubbed out, so the AVM1 walks dominate *there* by
construction. That profile does not transfer to the browser (graphics) cost.

## The fix (landed)

`render_webgpu.c`: accumulate each dynamic shape's vertices+color into per-frame
CPU staging mirrors of the dynamic vertex/color regions; flush each as **ONE**
`writeBuffer` in `render_webgpu_close_pass` before the frame's submit.
`queue.writeBuffer` is ordered before submit and each dynamic slot is still
written exactly once to the same offset → **pixel-identical** output. Call count:
hundreds → ~3/frame.

## Results (difficulty screen, perf HUD `window.__swfPerf`)

| metric | before | after |
|---|---|---|
| frame CPU **median** | ~72 ms | **~12 ms** (~6×) |
| delivered fps (median interval) | ~12 | **~21–26** (~2×) |
| `writeBuffer` share of frame CPU | ~88% | dropped out of the CPU-bound role |

Verified pixel-identical in **browser-WASM** and **OFFSCREEN graphics-native**
(Minesweeper + Tetris render correctly; Minesweeper OFFSCREEN trace unchanged at
634 lines).

## Remaining gap to 30fps (future work)

Frame CPU is now bimodal: most frames ~12 ms, but a tail (~p90 110 ms) keeps the
*mean* high and caps delivered fps at ~24. The remaining top profile entries are
GPU-driver ops (`writeBuffer` bytes + `createView`), i.e. the cost is now
**GPU-upload / present-bound**, not CPU-call-overhead-bound. Next levers, in order:

1. **Retained-mode glyph/shape caching** — the static difficulty-screen text is
   re-tessellated + re-uploaded into the dynamic region every frame. Caching
   tessellated glyph geometry (upload once, redraw from a persistent region) would
   cut the per-frame *bytes*, which batching does not.
2. The one-time **construction spike** (~2.5 s `max` frame) is the deep-build of
   the FUIComponent tree; separate from steady-state.

## On the static-subtree pruning (shelved, NOT landed)

The full pruning implementation from the plan doc was built and is correct
(self-healing refresh, all 5 walks pruned, OFFSCREEN gate 634 lines) but shelved:
in the browser it targets <2% of cost, and in NO_GRAPHICS/CI it adds ~10%
overhead (its refresh tree-pass iterates the giant `+16384` attachMovie buffer
that only exists in CI modes). The patch is saved at
`~/avm1_subtree_pruning_shelved.patch` if the AVM1-walk reduction is ever wanted
for a genuinely walk-bound NO_GRAPHICS workload.

## How to reproduce the measurement

```
# in-browser CPU profile (find the real bottleneck) — CDP Profiler, see
# the one-off /tmp/ms_cpuprof.py written this session.
# HUD frame-time:
/tmp/browser-test-venv/bin/python3 tools/divergence/game_drive/minesweeper_perf_probe.py
```
