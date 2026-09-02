# In-Browser Recompiler: Refresh Assessment

**Date:** 2026-09-02
**Status:** Assessment; stage 1 shipped 2026-09-02 (see §6)
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

## 6. Stage 1 shipped (2026-09-02)

Per the user's staging plan: trace mode is removed; the page now only recompiles to
C and offers downloadable zips. Details:
- `docs/recompiler/{index.html,pipeline.js}` rewritten: fresh `SWFRecompModule()`
  instance per run (no cross-run static state), collects `RecompiledTags/`,
  `RecompiledScripts/`, `RecompiledABC/`, shows file table + recompiler log.
- Two downloads (fflate 0.8.2 from unpkg): "Generated C only" and the **build
  bundle** = generated C + `docs/recompiler/bundle/` runtime snapshot (155 files,
  9.4 MB; produced by `deploy_wasm_demo.sh`, listed in `manifest.json`) +
  `build.sh`/`README.md` from `SWFRecomp/wasm_wrappers/bundle/`. `build.sh`
  mirrors `build_test.sh wasm --graphics` (AVM1) and `build_wasm_avm2.sh` (AVM2)
  and fills the stage size into the player page.
- Verified: page → bundle zip (2.5 MB) → `./build.sh` with emsdk 5.0 → WebGPU page
  renders `awful_shape_swf_4` correctly with the current runtime.
- Nothing generated is tracked (`SWFRecomp.{js,wasm}`, `build_info.json`, `bundle/`
  are gitignored): both deploy-pages workflows run `deploy_wasm_demo.sh --build`
  with a pinned, cached emsdk and deploy the result, so `docs/recompiler/` is
  always consistent with the deployed commit. `deploy-pages.yml` has a `dry_run`
  input that builds everything but skips the Pages upload. A submodule for the
  bundle was considered and rejected: the bundle is a pure function of the commit. Trace artifacts (`libswfruntime.a`, `wasi_shim.js`,
  `runtime_src/`) deleted. Graphics-stage files (`pipeline_graphics.js`,
  `graphics_host.*`, `runtime_src_graphics/`, `clang_registry_response.json`,
  `coi-serviceworker.js`) are kept, unreferenced, for stage 2.
- Stage 2 = §3.3 (in-browser C→WASM for graphics), recommended via
  `-sMAIN_MODULE=2` host + in-browser PIC side module.

## 7. Stage 2 design (2026-09-02): in-browser C → WASM for graphics mode

### 7.1 Spike results (what the in-browser compiler can and cannot do)
The only in-browser C compiler available is the wasmer registry package
`clang/clang` 0.160000.1 (no newer version exists). Measured in Chrome via the SDK:
- Its `clang` entrypoint is a **slim driver** (`clang-16-slim` atom) with hard-coded
  presets (`--sysroot`, `--target=wasm32-wasi`, `-Wl,--shared-memory`, `--import-memory`,
  `--export-dynamic`, `--export=__heap_base` ...). It compiles+links in one shot only:
  `-c` fails with "unknown integrated tool '-cc1'", and `-fPIC` (or `-Xclang
  -mrelocation-model pic`) is silently ignored — the objects it feeds to wasm-ld are
  non-PIC (`R_WASM_MEMORY_ADDR_LEB ... recompile with -fPIC`).
- The full `clang-16` atom dies immediately (exit 45, the OOM signature) even on a
  10-line file.
- wasm-ld is LLVM 16: no `--table-base`.
- ⇒ **No PIC side module, so the Emscripten `MAIN_MODULE` route is out.**

What does work (spike in `scratchpad/spike`, verified end to end in Node against an
Emscripten host): a non-PIC guest linked with
`--import-memory --export-table --global-base=<host address> --allow-undefined
--export-all --no-entry`, instantiated against the host's shared memory, with the
guest's own function table **mirrored** into the host's table. The host is built with
`-Wl,--table-base=262144` (Emscripten's LLVM 21 supports it), so host slots
`[1, 262144)` are free and a guest index `i` is placed at host index `i`: guest
function pointers are valid in both modules with **no translation**. Guest data lives
at a host-chosen address (`--global-base` = a static 96 MB arena in the host).

### 7.2 Implementation (shipped 2026-09-02)
- **Runtime:** `include/libswf/generated_data.h` declares the generated tables the
  runtime reads directly (`transform_data`, `shape_data`, `glyph_data`, `text_data`,
  `text_char_codes`, `cxform_data`, `bitmap_data`, `morph_end_shape_data`,
  `frame_label_data`) as arrays normally and as **pointers under `-DDYNAMIC_HOST`**;
  the 34 scattered `extern` declarations in action.c/tag.c/tag_stubs.c/shape_hit_test.c
  became `GEN_EXTERN_*;` macros. Native/CI builds are textually unchanged.
- **Host:** `wasm_wrappers/host_main_graphics.c` (DYNAMIC_HOST): pointer definitions +
  `set*` setters that fill both `app_context` and the pointers, `configureAppContext`
  with the viewport-fit fields, `get_*_addr` for the five bridged globals, weak stubs
  for six NO_GRAPHICS-only symbols that `swf.c`'s dead goto-catch-up path references
  (exporting every symbol keeps that function alive).
  `scripts/build_graphics_host.sh`: current runtime source set + libtess2, export list
  from `llvm-nm` minus `__*`, MODULARIZE (`createGraphicsHost`), and three link
  choices that each fixed a real failure:
  - `-sSHARED_MEMORY=1` at compile time too (the guest's memory import is shared
    because the slim driver forces `--shared-memory`; objects need atomics/bulk-memory).
  - **`-sJSPI` instead of `-sASYNCIFY`.** The renderer waits mid-frame
    (`render_webgpu_open_pass` → `emscripten_sleep`, `wgpuInstanceWaitAny`), reached
    from tag functions that are called from guest frames. ASYNCIFY cannot unwind
    through a non-instrumented guest frame: symptoms were random `unreachable`
    traps, a failing `operator new`, and `puts` re-executed inside `runSWF`. JSPI
    suspends the whole wasm stack in the engine, guest frames included.
  - **`-sSUPPORT_LONGJMP=wasm`** (default is `emscripten`, which routes calls inside
    setjmp-scoped functions through JS `invoke_*` trampolines) and **raw exports for
    the guest's imports**: JSPI refuses to suspend across JS frames, and Emscripten
    wraps every export in a JS `wrapper` under JSPI. `pipeline_graphics.js` captures
    `instance.exports` in the `instantiateWasm` hook before Emscripten wraps them.
  - `-sGLOBAL_BASE=101 MB` + `--table-base=262144`: host data/stack/heap live above
    101 MB and host functions above table slot 262144. The guest is linked at a
    **fixed** `--global-base=64 KB`, so it can be compiled before the host is loaded,
    and its table is mirrored into host slots `[1, n)`.
- **Guest:** `guest_main_graphics.c` exports the table addresses/sizes plus
  `get_frame_funcs`, `get_frame_label_data/count`, `get_text_char_codes` and
  `get_tagInit_ptr` (a function pointer, so `tagInit` is in the guest table).
  `bridge_globals.{h,c}` unchanged (compiled in-browser with the generated C).
  Generated sources get two textual patches before compiling: the bridged-global
  `extern`s are removed, and bare `label_N:` lines get a `;` (clang 16 rejects a
  declaration after a label).
- **Page:** `docs/recompiler/pipeline_graphics.js` — compile guest (headers fetched
  from `bundle/runtime/include`; retries the SDK's intermittent "oneshot canceled"),
  load host, instantiate, mirror table, `bridge_init`, `set*`, `runSWF` (promising
  export). `deploy_wasm_demo.sh` builds the host into `docs/recompiler/host/`
  (gitignored, CI-generated like the bundle).
- Verified in Chrome via Playwright: `awful_shape_swf_4`, `keyboard_input`,
  `define_button2` compile in ~8 s and run with no traps.

### 7.3 Known limitations
- **AVM1 try/catch:** `ACTION_TRY_SETJMP` inlines `setjmp` into generated scripts; the
  slim driver cannot lower it, so the guest imports `setjmp`/`longjmp`. The page maps
  `setjmp` → 0 (try body runs as if nothing can throw) and `longjmp` → JS error. A
  real fix is a recompiler emission mode that runs try bodies through a runtime helper.
- One SWF per page load (the runtime has global state); reload to run another.
- Guest data + 8 MB shadow stack must fit the 96 MB arena; bigger SWFs get a clear
  error pointing at the downloadable bundle.
- Chrome 137+ only (JSPI, SharedArrayBuffer via coi-serviceworker, WebGPU); the page
  checks for `WebAssembly.Suspending` and says so.

## 8. Real games through the page (2026-09-02)

Both originals, dropped on the page (file input), in-browser recompile → bundle
zip → local `build.sh` → Chrome; Doodle Jump additionally through the in-browser
build:

| SWF | In-browser recompile | Bundle | Local build.sh | In-browser run |
|---|---|---|---|---|
| Doodle Jump (flasharchive, 650 KB, AVM1) | 3 s, 48 files, 19 MB C | 4.3 MB | OK, title screen renders | OK: 46 files compile in 61 s, title screen renders |
| Seedling (Newgrounds 598977, 7.8 MB, AS3) | 65 s, 16 files, 182 MB C | 33 MB | builds in 5:38 (1.8 GB RAM, 33 MB wasm); runs, but the canvas stays black: Dawn `DXGI_ERROR_DEVICE_REMOVED` (see below) | refused with the AS3 message (host is AVM1-only) |

Two recompiler-wasm bugs surfaced by Seedling, both fixed in `SWFRecomp/CMakeLists.txt`:
- **C++ exceptions were disabled in the Emscripten build**, so an exception the
  recompiler throws *and catches internally* escaped `main()` as an opaque JS number
  (`Recompiler crashed: 123257736`). Now built with `-fexceptions`; `main()` also
  catches `std::exception` and prints `what()` (exit 2) in every build.
- **Device-font fallback read `assets/NotoSans.ttf` from disk.** The in-browser
  filesystem has no such file, so zero-glyph `_sans`-style fonts and the DefineText
  tags using them were silently dropped (Seedling lost 38 K glyph vertices and 3
  text tags). The font is now `--embed-file`d at the path `loadDeviceFont()` probes.

Residual wasm-vs-native output difference: a few tessellation vertices per complex
shape (Doodle Jump 22872 vs 22878 rows, Seedling 57066 vs 57069) — float-precision
noise in libtess2 under wasm32, not a functional difference.

**Original Seedling renders black (GPU device removed).** Not a pipeline problem: the
bundle builds and runs, but `render_webgpu.c` allocates ONE bitmap texture array of
`(highest_w+1) x (highest_h+1) x (bitmap_count + dynamic cap)` layers. The original has
284 bitmaps whose widest is 4480 px and whose tallest is 1106 px (different bitmaps:
the 1106-tall one is only 486 wide), so the envelope is 4480x1106, i.e. 4481x1107x284x4 B = **5.25 GiB** of static
layers (+64 dynamic), which D3D12 refuses and the device is lost. The teleport build
that powers the docs2 demos has 281 bitmaps but its tallest is 4480x640 (3.0 GiB), which
this GPU tolerates. `BITMAP_ARRAY_HARD_LIMIT` (1.5 GiB) only clamps dynamic growth, by
design. Fixing the original needs a runtime change (per-bitmap textures or an atlas
instead of a uniform array); tracked as a follow-up, outside the in-browser work.
