# Slice: replace the uniform bitmap texture array (original Seedling renders black)

You are starting a fresh session on SWFRecomp-CC at `master` (baseline: the commit
this file was added in — `git log -1 -- SWFRecompDocs/prompts/bitmap-texture-envelope-prompt.md`).
CLAUDE.md is auto-loaded; it authorises commit/push/CI/Pages deploy. Read
`SWFRecompDocs/plans/in-browser-recompiler-refresh-assessment.md` §8 first, then the
code named below. Work in this tree (not the Ruffle-test fan-out — that convention is
for corpus sessions only).

## The problem (measured 2026-09-02)

`SWFModernRuntime/src/rendering/render_webgpu.c` creates ONE 2D texture array,
`bitmap_tex`, for every static bitmap in the movie plus a dynamic-attachBitmap
reserve: `plan_dynamic_bitmaps()` (~line 1070) and the `bitmap_tex` descriptor
(~line 1360). Its size is `(highest_w+1) x (highest_h+1) x (bitmap_count + dynamic cap)`,
where `highest_w`/`highest_h` come from the recompiler's `BITMAP_HIGHEST_W/H` — the
widest and the tallest bitmap of the movie, which need not be the same bitmap.

| Movie | bitmaps | actual RGBA pixel data | envelope allocated | result |
|---|---|---|---|---|
| Seedling **original** (`~/CC/newgrounds/598977_Seedling.swf`) | 284 | 13 MiB | 4481 x 1107 x 284 x 4 B = **5.25 GiB** (+64 dynamic layers) | Dawn `ID3D12Device::CreateCommittedResource` fails, `DXGI_ERROR_DEVICE_REMOVED`, canvas black |
| Seedling teleport (docs2 demos, `~/CC/seedling_teleport_build`) | 281 | 10 MiB | 4481 x 641 x 281 x 4 B = 3.0 GiB | renders (this GPU tolerates it) |

The envelope is set by two unrelated bitmaps: a 4480 x 82 strip and a 486 x 1106 image.
Size histogram of the original: 255 bitmaps <= 256 px, 25 <= 1024, 3 <= 2048, 1 wider.
`BITMAP_ARRAY_HARD_LIMIT` (1.5 GiB) deliberately clamps only the dynamic growth, so a
movie whose static bitmaps already overrun it fails exactly like this.

## Goal

Make the original Seedling (and any movie with one odd-sized bitmap) render, without
regressing the graphics test corpus or the docs2 game demos. Candidate designs, pick
after reading the code and the shader side (how `bitmap_tex` is sampled — layer index
in the vertex data, `MAX_BITMAP_TEXTURE_LAYERS` = 256 also matters):
1. **Size classes:** a few texture arrays (e.g. 256², 1024², 2048², plus per-bitmap
   textures for outliers), layer index remapped at upload/draw time.
2. **Atlas:** pack all bitmaps into one or a few large 2D textures; UV rescale in the
   shader or in the generated vertex data.
3. **Per-bitmap textures + bind-group cache** for the outliers only, keeping the array
   for the common case.
Consider the dynamic `attachBitmap`/BitmapData path (AVM1 and AVM2 both use
`dynamic_bitmap_*`), the AVM2 `avm2_bitmap.c` / `avm2_cpu_raster.c` users, and
uninvertible-matrix / gradient paths that share the sampler bind group. The memory
note [[webgpu-texture-array-layer-limit-blank-render]] records the previous
device-limit incident and the uncaptured-error callback that now exists — use it.

## Repro (ready to run, no rebuild needed)

`~/CC/seedling_original_build/bundle/` is the downloaded build bundle of the original
Seedling (generated C + runtime snapshot + `build.sh`, already built: `out/`).
- Rebuild after a runtime change: copy the changed runtime files over
  `bundle/runtime/src/...` (or re-run the page flow), then `cd bundle && ./build.sh`
  (incremental, ~1 min for a runtime-only change; `RT_OPT=-O1` is faster).
- Run: `python3 -m http.server -d bundle/out 8021` and open it in Windows Chrome via
  the Playwright recipe in `tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`;
  `C:\playwright\run_built.py <url> <png> 25` clicks Run SWF, waits 25 s, screenshots,
  and prints console warnings (the `DEVICE_REMOVED` line is the failure signature).
  Windows python is `"/mnt/c/Program Files/Python312/python.exe"`.
- The teleport control: `docs2/demo.html?test=avm2/seedling` served from `docs2/`.

## Done means

- Original Seedling shows its title screen in Chrome via the repro above.
- `ruffle-tests.yml` in **graphics** mode (`categories=all`, default) green with zero
  regressions per `scripts/corpus_status_diff.py` (the pixel canary too if the change
  touches sampling: see [[graphics-fanout-playbook]] render_canary); the docs2 Seedling
  and Doodle Jump demos still render.
- Closeout: a short status doc under `SWFRecompDocs/status/` with the design chosen and
  measurements (VRAM before/after), memory updated, commit pushed, Pages deploy
  dispatched only if `docs/` changed.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
