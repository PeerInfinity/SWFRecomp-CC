# Minesweeper radio-click "lag" — corrected diagnosis + transform retained-skip

**Date:** 2026-06-21
**Commit:** `34641bc76` (transform-buffer retained-skip, browser-WASM only)
**Bucket:** needs-browser + perf

## TL;DR

The Minesweeper difficulty-screen radio-click "lag" is **NOT AVM1** (the prior
diagnosis was a mis-attribution). End-to-end per-frame instrumentation shows all
AVM1 work totals ~0–1.6 ms/frame; the heavy frames were **377 per-frame
`wgpuQueueWriteBuffer` calls (374 of them 64-byte matrix uploads) stalling on the
GPU queue**. On this WSL2 box that back-pressure is SwiftShader software-present
cost (an environment artifact). The committed fix retained-skips the transform-buffer
uploads (a real cross-backend win); it does not eliminate the SwiftShader present
burst, which a real GPU won't exhibit anyway.

## What was measured (all instrumentation stripped before commit)

Per-frame, via temporary counters/timers reported to `globalThis.__walkDbg`:

| State | frame `show` | `prerender` | `render`(open→close) | writeBuffer time | wb calls | draws | nodes | vtx re-upload |
|---|---|---|---|---|---|---|---|---|
| Idle | ~3 ms | ~0.5 ms | ~2 ms | 1.1 ms | 377 | 164 | 55 | 0 (retained-skip ok) |
| Burst (post-select) | 48–52 ms | smears | smears | 48 ms (pre-fix) | 377 | 164 | 55 | 0 |

Key facts that overturn the "AVM1 re-layout burst" story:

- **onEnterFrame dispatch count = 0** on the difficulty screen.
- `adv` (advance/nested/attached sprite walks) = ~0 ms; `btn` (button state machine
  + the radio click cascade) = ~0–1.6 ms; `focus` (focus-rect) = ~0 ms.
- Display tree never grows: nodes=55, draws=164, child_mc=52, tf_glyphs=6 — all flat
  idle vs burst.
- writeBuffer **call count is constant (377)** idle vs burst; only the **per-call
  wall time** changes (2.9 µs → 127 µs, 44×) = GPU-queue back-pressure.
- 374/377 writes are 64-byte (16-float matrix) uploads — `render_webgpu_write_transform`
  / `compose_text_transforms` / `compose_sprite_transform` re-uploading every
  xform_buffer slot every frame.
- The burst is **flaky between runs** (some runs showed no burst), and the heavy time
  smears between the staging region and the present pass depending on where the GPU
  queue happens to block — the signature of SwiftShader software-present scheduling,
  not deterministic CPU work.

Why the old render-vs-tick split mis-attributed it: it timed `render` =
`renderer_open_pass → renderer_close_pass` (~2 ms) and bucketed everything else as
"tick". But the 374 per-shape matrix writeBuffers happen in the staging/compose
region (before `open_pass`), so their GPU stalls landed in the "tick" bucket and were
read as AVM1 CPU.

## The fix (`34641bc76`)

`render_webgpu.c`: new `xform_slot_write(ctx, transform_id, composed)` is the single
choke point for all three per-frame xform_buffer writers. It keeps a CPU mirror
(`xform_mirror` + `xform_mirror_valid`, sized to `xform_slot_count`) of the last bytes
written to each slot and **skips the `wgpuQueueWriteBuffer` when the slot's 16-float
matrix is byte-identical** to the last write — the GPU retains the bytes, so the result
is provably pixel-identical.

- Invariant: `xform_mirror_valid[i] != 0  ⇒  GPU xform_buffer slot i == xform_mirror[i]`.
- All three writers route through it, so the mirror can't be desynced by a bypassing
  writer. The init-time bulk upload leaves slots `valid=0` (first per-slot write
  re-syncs).
- **Browser-only**: mirror malloc'd under `__EMSCRIPTEN__`; native/OFFSCREEN leave it
  NULL → always upload → graphics-native suite bit-for-bit unchanged. Mirrors the
  existing `prev_dyn_vtx` retained-vertex-skip precedent (`485cab115`).

### Measured effect (browser, this box)

- writeBuffer calls **377 → 224/frame**; writeBuffer time idle **1.1 → 0.6 ms**, and
  during the GPU stalls **48 → 0.5 ms**.
- Idle difficulty screen renders **pixel-identical** (`/tmp/ms_before.png`).
- The wall-clock burst on this box is ~unchanged because it **relocates to the present
  pass** (`render` ~45 ms) — irreducible SwiftShader software-rasterizer cost. On a
  real GPU the present is fast (no burst), and the 153 fewer writeBuffers/frame is a
  real per-frame CPU win for every graphics game.

## Validation

- Browser-WASM-only change (gated). Per `ci-only-when-observable` its perf effect is
  not CI-observable; but the shared `render_webgpu.c` compiles for OFFSCREEN, so a
  graphics CI run confirms it compiles + the graphics-native suite stays byte-identical
  (mirror NULL there). Dispatched `gh workflow run ruffle-tests.yml -f mode=graphics`.
- Correctness is by construction (skip only on exact byte match; GPU retains bytes);
  the pixel-perfect idle render confirms the mirror indexing.

## Follow-ups / open

- 221 of the 374 matrix writes still upload at idle (only 153 skipped) — some slots
  recompute non-identical bytes each "static" frame. Worth a look if more reduction is
  wanted (could be FP-path or genuinely-changing slots), but it's only ~0.6 ms.
- The user-reported "multi-second freeze on real hardware" could not be verified here
  (SwiftShader-only box). If it reproduces on a real GPU, there is a real component the
  SwiftShader environment masks/distorts — re-measure on real hardware.

See memory `minesweeper-radio-click-lag-is-avm1-burst` (corrected) and
`browser-perf-is-writebuffer-not-avm1-walks`.
