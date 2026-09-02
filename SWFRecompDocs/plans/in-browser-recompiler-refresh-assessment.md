# In-Browser Recompiler: Refresh Assessment

**Date:** 2026-09-02
**Status:** Assessment (no code changed)
**Parent docs:** `IN_BROWSER_RECOMPILATION_FEASIBILITY.md`, `PHASE1_RECOMPILER_TO_WASM.md`,
`PHASE2_IN_BROWSER_COMPILATION.md`

## 1. Where the tool lives

| Piece | Location | Last real refresh |
|---|---|---|
| Page + pipeline JS | `docs/recompiler/{index.html,pipeline.js,pipeline_graphics.js,wasi_shim.js}` | 2026-04-04 (JS), page 2026-03-20 |
| Recompiler as wasm | `docs/recompiler/SWFRecomp.{js,wasm}` (from `SWFRecomp/scripts/build_wasm_recompiler.sh`) | 2026-03-20 |
| Trace runtime lib | `docs/recompiler/libswfruntime.a` + `runtime_src/{action,object}.o` (from `build_wasm_runtime_lib.sh`, `deploy_wasm_demo.sh`) | lib: 2026-03-20; `.o`: rebuilt by CI at every Pages deploy |
| Runtime headers | `docs/recompiler/runtime_headers/` (11 headers, manifest) | 2026-03-20 (+2 one-line touches) |
| Graphics host | `docs/recompiler/graphics_host.{js,wasm}` (from `build_graphics_host.sh`) + `runtime_src_graphics/` | 2026-03-20 |
| Deploy | `.github/workflows/deploy-pages.yml` (manual dispatch), last run 2026-08-12 | — |
| Live URL | `https://peerinfinity.github.io/SWFRecomp-CC/recompiler/` | — |

Pipeline: `SWFRecomp.wasm` writes C files into MEMFS → `@wasmer/sdk@0.8.0-beta.1`
runs the registry package `clang/clang` (commands `clang-16`, `wasm-ld`; its sysroot
libs were built by clang 12, it has **no `libsetjmp` and no setjmp `#error` guard**;
`0.160000.1` is still the only version on the registry) → trace mode runs the WASI
binary under `wasi_shim.js`; graphics mode links the guest with `--allow-undefined`,
instantiates it against the pre-built Emscripten host's exports and shared memory,
and hand-translates function pointers between guest and host tables.

## 2. Measured current state (Windows Chrome via Playwright, 2026-09-02)

| Target | Trace mode (`add_swf_4`) | Graphics mode (`awful_shape_swf_4`) |
|---|---|---|
| Live Pages site (deployed 2026-08-12) | **FAILS** at wasm-ld: signature mismatches, e.g. `actionGetMCVisible` 2 args in `libswfruntime.a(tag.o)` vs 3 in `action.o` | Works (renders the shape) — but it is the **March runtime** |
| Local `docs/` snapshot (March `.o` files) | Works, correct 11-line trace | Works |

Cause of the live breakage: `deploy-pages.yml` recompiles only `action.o`/`object.o`
from current source at deploy time, while `libswfruntime.a`, the headers and the
graphics host are frozen at 2026-03-20. Any runtime API drift since then breaks the
trace link. Nothing in CI exercises the page.

Drift since the last refresh (`b27d68c1`, 4006 commits):

| Area | Change |
|---|---|
| `SWFModernRuntime/src,include` | 111 files, +160K/−13K lines; 16 new AVM1-side `.c` files, all of `src/avm2/`, `third_party/libtess2` now required by `action.c` |
| `SWFRecomp/src` | 29 files, +19K lines (AVM2/ABC emitter etc.) |
| `wasm_wrappers/main.c` | AVM2 entry, ExternalInterface bridge, viewport fit fields (`render_width`, `stage_scale`, `stage_fit_*`) |
| Recompiler CLI | unchanged: still `SWFRecomp config.toml` with `[input] path_to_swf / output_tags_folder / output_scripts_folder` — `pipeline.js` config still valid |
| Generated file set (AVM1) | unchanged shape: `tagMain.c constants.{c,h} draws.{c,h} script_N.c script_defs.c script_decls.h out.h`; new: `sprite_frame_scripts_data[]` function-pointer table passed to `tagInitSpriteFrameScripts` |

## 3. What a refresh takes

### 3.1 Recompiler wasm — trivial
`build_wasm_recompiler.sh` builds cleanly today with emsdk 5.0.0 (1.3 MB wasm, was 0.65 MB;
the ABC/AVM2 sources are already in the CMake list and the Emscripten block is intact).
No code change needed. Cost: run the script + copy.

### 3.2 Trace mode — small, mechanical (verified end-to-end natively)
Emulating the browser link with wasi-sdk 30 against the **current** runtime:
all 31 runtime TUs compile, the link succeeds with one extra library, and the
resulting wasm runs under Node's WASI producing the correct trace.

Required edits:
1. `build_wasm_runtime_lib.sh`: replace the 9-file source list with `verify_output.py`'s
   no-graphics `core_sources` (minus `action.c`/`object.c`) + `third_party/libtess2/*.c`;
   add `-I lib/o1heap -I lib/stb -I third_party/libtess2`.
2. `deploy_wasm_demo.sh` + both `deploy-pages*.yml`: same include dirs for the `.o`
   precompile (the workflow already has libtess2); copy the new headers that
   `action.h`/`recomp.h` now pull in (`action_internal.h`, `action_queue.h`,
   `actiondate.h`, `actionmath.h`, `actionrando.h`, `actionregclass.h`,
   `actiontimer.h`, `avm1_amf.h`, `sprite_frame_scripts.h`, `video_codec.h`,
   `amf_packet.h`, `curve_flatten.h`, `gradient_ramp.h`, `dialog_events.h`,
   `socket_events.h`, `libswf/capture.h`, `stb_image.h`) into the manifest — or
   simpler, copy the whole `include/` tree.
3. `pipeline.js`: add `-mllvm -wasm-enable-sjlj` is **not** possible for the generated
   files (see 3.4), but the link needs the sjlj helpers that `action.o` now references
   (`__wasm_setjmp`, `__wasm_setjmp_test`, `__wasm_longjmp`): ship wasi-sdk 30's
   `libsetjmp.a` next to `libswfruntime.a` (or fold its objects into the archive) and
   add it to the link line.
4. Fix the deploy invariant: either stop CI rebuilding `action.o`/`object.o` (deploy
   the checked-in set as one consistent snapshot) or have CI rebuild **everything**
   (lib, headers, recompiler wasm, host). The half-rebuild is what broke the live site.

### 3.3 Graphics mode — moderate, and the design has a growing hole
A patched `build_graphics_host.sh` (current source list per `build_test.sh`'s wasm
graphics branch + libtess2 + `-Wno-error=implicit-function-declaration`, stale stubs
removed from `host_main_graphics.c` because 13 of them now exist in the runtime) gets
to the final link. Remaining undefined symbols: `cxform_data`, `glyph_data`,
`bitmap_data` — generated data arrays that `tag.c`, `action.c` and `shape_hit_test.c`
now reference **directly** instead of through `app_context` pointers.

Consequences for the guest/host split:
- Adding zero-length host stubs (as already done for `shape_data` etc.) makes it link,
  but the runtime then reads the host's empty arrays, not the guest's data: cxforms,
  glyph text, bitmaps and shape hit-testing would be wrong. Every new direct access
  in the runtime silently widens this hole.
- `host_main_graphics.c::configureAppContext` must also set `render_width/height =
  width/height` and `stage_scale = stage_fit_x = stage_fit_y = 1` (swf.c now sizes the
  viewport from `render_width`; zero means nothing renders).
- `pipeline_graphics.js` must translate the new `sprite_frame_scripts_data[]` function
  pointers guest→host (same treatment as `sprite_N_frame_funcs`), or `tagInit` hands
  the host guest-table indices.

Recommended direction instead of extending the hand-rolled bridge: build the host with
`-sMAIN_MODULE=2` and compile the guest in-browser as a PIC side module (`-fPIC`,
`wasm-ld --shared`, which clang 16 can emit), then `loadDynamicLibrary` it. Emscripten
then resolves data symbols in both directions via GOT, shares one function table, and
the three bridge hacks (`bridge_globals`, table patching, extern-stripping regexes)
go away. Moderate effort; needs a spike to confirm the wasmer clang produces a `dylink.0`
section Emscripten accepts.

### 3.4 Known gaps that stay after a refresh
- **AVM1 try/catch in-browser.** `ACTION_TRY_SETJMP` inlines `setjmp()` into generated
  script files. The wasmer clang's sysroot has no setjmp implementation, and its
  `-wasm-enable-sjlj` lowering uses the old `saveSetjmp/testSetjmp` helper ABI, not the
  `__wasm_setjmp*` ABI that wasi-sdk 30 objects and `libsetjmp.a` use. Scripts using
  try/catch therefore fail to link in-browser (this was already true in March). Options:
  a ~30-line old-ABI shim linked in, or a newer clang package (none published).
- **AVM2 SWFs.** Not supported by the page (it never was). Generated `abc0_methods.c`
  is routinely MBs, beyond what in-WASI clang handles; the AVM2 runtime (36 files +
  quickjs-regexp + lzma) could be precompiled, but generated code size is the blocker.
- **Firefox** still unsupported (SDK threading/SharedArrayBuffer path).

### 3.5 Effort estimate
| Item | Effort |
|---|---|
| Recompiler wasm rebuild | minutes |
| Trace mode (3.2, items 1–4) | ~half a day incl. a Playwright check |
| Graphics via stubs + JS patches (keeps the hole) | ~1 day |
| Graphics via MAIN_MODULE/side-module redesign | 2–3 days incl. spike |
| try/catch shim | ~half a day |

## 4. Adding a "download the wasm" option

Cheap in both modes — the bytes are already in hand as `Uint8Array`s:
`wasmBytes` in `processSwf` (trace) and `guestWasm` in `processSwfGraphics`. A button
that does `URL.createObjectURL(new Blob([bytes], {type: "application/wasm"}))` +
`<a download="name.wasm">` is ~20 lines in `pipeline.js`, plus a `<button>` in
`index.html`.

What the file is worth depends on the mode:
- **Trace `output.wasm`** is linked by the wasmer clang driver's preset args with
  `--shared-memory`/`-pthread`, so it imports shared memory and `wasix_32v1` functions.
  It runs under the page's `wasi_shim.js` but not under wasmtime/Node WASI as-is.
  Two fixes: (a) offer the shim + a 10-line runner HTML in the download, or (b) drive
  `clang.commands["wasm-ld"]` directly (already referenced in `pipeline_graphics.js`)
  with explicit args and no `--shared-memory`, producing a plain `wasm32-wasi` binary
  that any WASI runtime executes (the native emulation above confirms this works).
  (b) is the better product: a self-contained CLI-runnable artifact.
- **Graphics `guest.wasm`** is not standalone (125 imports from the host). Downloading
  it only makes sense together with `graphics_host.{js,wasm}` and a loader page —
  i.e. a zip of the same bundle `deploy_example.sh` produces for `docs2/examples`.
  With the side-module redesign this becomes a natural "download playable bundle".
- **Generated C** is the most reusable download (zip of `RecompiledTags/` +
  `RecompiledScripts/`); it feeds the native build scripts directly. A small
  zip library (e.g. fflate from a CDN, the page already loads `@wasmer/sdk` from unpkg)
  or a `.tar` written by hand (~40 lines) covers it.

## 5. Verification recipe
- Native emulation of the trace pipeline: `wasi-sdk/bin/clang --target=wasm32-wasi
  ... generated/*.c main.c libswfruntime.a -lsetjmp -mllvm -wasm-enable-sjlj` and run
  under `node:wasi` (script kept in this session's scratchpad as `wasi_trace_emul.sh`).
- Browser: serve `docs/` on `localhost:8010` and drive Windows Chrome per
  `tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`; the probe used here is
  `C:\playwright\recomp_probe.py <url> trace,graphics <tag>` (checks status steps,
  dumps trace output, screenshots the canvas).
