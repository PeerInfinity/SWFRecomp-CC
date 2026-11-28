# SWFRecomp-CC architecture

This page is for people who know Flash internals, and Ruffle in particular, and want to know how this project is
built and where it differs. It describes the tree as of 2026-11-28. File sizes are approximate and grow.

For setup see [`../GETTING_STARTED.md`](../GETTING_STARTED.md). For results and what is still worth doing see
[`plans/PROJECT_STATE.md`](plans/PROJECT_STATE.md). The root [`README.md`](../README.md) has the project summary and
the code map.

## 1. The pipeline

```
                   ┌──────────────────────── recompile time (C++) ────────────────────────┐
test.swf ─► SWFRecomp ─► RecompiledScripts/  AVM1: one C function per action block / DefineFunction
                      ├► RecompiledTags/     the timeline: one C function per frame, plus shapes, fonts,
                      │                      bitmaps and sounds as C data (constants.c, draws.c, tagMain.c)
                      └► RecompiledABC/      AVM2: one C function per method body, plus the ABC tables,
                                             the class registry and the static timeline tables
                   └──────────────────────────────────────────────────────────────────────┘
          generated C  +  SWFModernRuntime/ sources  +  SWFRecomp/wasm_wrappers/main.c
                      │
                      ├─ gcc ─► native binary   (test harness: no-graphics, or graphics on Dawn offscreen)
                      └─ emcc ─► .wasm + page   (browser: WebGPU canvas, Web Audio)
```

- **Ahead of time, whole program.** Every SWF the program will run, including movies it loads with `loadMovie`,
  `MovieClipLoader` or `Loader`, is recompiled at build time. The test harness finds a test's child SWFs (on disk,
  or embedded in a `DefineBinaryData`), recompiles each with its own symbol prefix and character-id offset, and links
  them into the same binary (`find_child_swfs` and `recompile_child_swf` in `ruffle-tests/verify_output.py`). A SWF
  that was not compiled in cannot be loaded at run time.
- **AVM1 or AVM2 is decided per SWF.** The recompiler reads the `FileAttributes`/`DoABC` tags. The harness compiles the
  AVM2 runtime tree only when `RecompiledABC/` exists, and adds `-DSWF_AVM2`, which makes `main.c` enter through
  `runSWF_avm2()` instead of the AVM1 `swfStart()`.
- **No interpreter at run time.** AVM1 jumps become C `goto`s to labels. An AVM2 method's operand stack, locals and
  scope stack become C arrays local to its function. Both VMs still call runtime helpers for nearly every operation
  that touches a value (`actionAdd(app_context)`, `avm2_op_getproperty_static_ic(...)`), so the speed-up comes from
  removing dispatch and decoding, not from compiling ActionScript semantics into raw C arithmetic.

## 2. The recompiler (`SWFRecomp/`, C++)

| File | Role |
|---|---|
| `src/main.cpp`, `src/config.cpp` | Entry point. Reads a `config.toml` (input SWF, output dirs, options) |
| `src/swf.cpp` (~13k lines), `src/field.cpp` | SWF container (zlib/LZMA), the tag stream, and shape and glyph tessellation |
| `src/tag.cpp` | Tag records → C data and the per-frame calls in `tagMain.c` |
| `src/action/action.cpp` (~3k lines) | AVM1 bytecode → C |
| `src/abc/abc_parser.cpp` | ABC parser |
| `src/abc/abc_verifier.cpp` | An avmplus-style verifier, run at recompile time |
| `src/abc/abc_emit.cpp` (~4.5k lines) | AVM2 method bodies → C, the tables and `abc_registry.c` |
| `src/abc/abc_timeline.cpp` | AVM2 static timeline tables (`abc_timeline.c`, `avm2_movie_tables.c`) |
| `src/abc/abc_devicefont.cpp` | Device fonts declared in a Ruffle `test.toml` → generated font rows |
| `src/abc/abc_dump.cpp`, `abc_tool.cpp` | `--dump-abc` and `--check-abc` |
| `src/recompilation.cpp` | Drives one recompile and writes the output files |
| `wasm_wrappers/` | The `main.c` every build links, and the runtime snapshot for the in-browser recompiler |

**AVM1 emission.** `action.cpp` makes two passes over each action block: the first finds the jump targets, and the
second emits C. Each action becomes a push (`PUSH(...)`, `PUSH_STR_ID(...)`) or a call into the runtime
(`actionGetVariable`, `actionCallMethod`, …). Constant-pool and literal strings get a **string id** at recompile
time, and the runtime indexes variables by that id (`getVariableById`, `var_array`). `DefineFunction`/`DefineFunction2`
bodies are emitted as separate C functions. Each frame of each timeline is a C function, `frame_N()`, whose body is
the frame's tags in order (`tagPlaceObject2(...)`, `actionQueueScript(app_context, script_N)`, `tagShowFrame(...)`).

**AVM2 emission.** Each method body is `static Avm2Value abcN_mK(Avm2Activation* act)` with
`Avm2Value loc[], stk[]` and an `Avm2ScopeEntry lscope[]` sized from the method's `max_stack`/`local_count`/scope
depth. Each property-access site gets its own `static Avm2InlineCache` or `Avm2FindCache`. The verifier's types are
used to drop coercions it can prove are no-ops. A body that fails verification is emitted as a stub that throws the
`VerifyError` avmplus would throw, with avmplus's message text. A rejected ABC file becomes a stub script, so the error
surfaces when the file's script is initialised.

**Shapes and text.** Fills, strokes and glyph outlines are tessellated into triangles at recompile time, with libtess2
(shared with the runtime, `SWFModernRuntime/third_party/libtess2`). The earcut path remains for morph shapes, which
need per-vertex correspondence between the start and end shapes. The runtime tessellates only geometry that is
created at run time (the drawing API, AS3 `Graphics`).

**Emission options** (all off by default; when off, the emitted C is byte-identical to before each option existed).
They exist for the in-browser recompiler, whose clang cannot lower `setjmp` and slows super-linearly on huge
translation units:
- `try_helper`: try bodies are lifted into functions that the runtime calls under its own `setjmp`;
- `tu_split`: AVM2 method bodies are split into `abcN_methods_K.c` chunks at method boundaries;
- `skip_avm1_payload`: an AS3 SWF does not emit the bitmap, sound and video data that only the AVM1 path reads.

Each can be set in `config.toml` `[input]`, through an environment variable, or as a `ruffle-tests.yml` input.

## 3. The runtime (`SWFModernRuntime/`, C)

### AVM1: `src/actionmodern/`

- **`action.c`** (~90k lines) is the AVM1 VM: values, objects and prototypes, the scope chain, function calls,
  `super`, `with`, the built-in classes, and the MovieClip, TextField, Button, Sound, BitmapData and filter APIs. Its
  neighbours are `variables.c` (variable storage by string id), `object.c` (`ASObject`/`ASArray` and the collector),
  `math.c`, `date.c`, `timer.c`, `avm1_amf.c` (SharedObject and AMF0), `registered_class.c`, `image_decode.c`,
  `video_codec.c` (Sorenson H.263 and VP6), and the filter kernels.
- **Values.** `ActionVar` is a tagged value (string, f32, f64, null, undefined, boolean, object, array, function,
  movieclip, …). The operand stack is a byte buffer driven by `PUSH`/`POP` macros. `ASObject`, `ASArray` and
  `ASFunction` are **separate C structs**, so code that handles more than one checks the type tag first.
- **Memory.** Objects and arrays are reference-counted. A root-traced mark-sweep collector (`object.c`, roots in
  `actionGcMarkRoots`) runs at tick boundaries as a backstop for cycles. It is on by default; `SWF_GC=0` turns it off.
- **Action queue.** `action_queue.c` holds three priorities (Initialize, Construct, Normal), drained highest first and
  FIFO within a priority, modelled on Ruffle's `ActionQueue` (`core/src/context.rs`).
- **Gotos.** A goto re-runs frame functions with `catch_up_mode` set, so tags execute and scripts are suppressed until
  the target frame. A backward goto first clears what was placed after the target and replays from frame 0
  (`swf_core.c` `ng_runPendingRootGoto` and its `swf.c` twin).

### AVM2: `src/avm2/`

- **Core.** `avm2_value.c` (`Avm2Value`, a tagged value with Integer and Number kept apart), `avm2_object.c`,
  `avm2_class.c` (classes, traits and vtables), `avm2_ops.c` (the opcode helpers that generated code calls; lookup
  order is vtable traits → own dynamic properties → prototype chain), `avm2_function.c`, `avm2_nsqname.c`,
  `avm2_error.c` (typed errors with avmplus's messages; the table is generated from Ruffle's
  `core/src/avm2/error_messages.rs`).
- **Startup.** `avm2_main.c` `runSWF_avm2()` loads every ABC (registering, not running, scripts), applies the
  `SymbolClass` bindings, eager-inits each file's last script, constructs the root class, then runs the tick loop.
  The order follows Ruffle's `movie_clip.rs`. Each top-level entry runs under a catch-all, so an uncaught error aborts
  that entry only and the movie keeps running.
- **Class library.** One file per area: `avm2_display.c` (~23k lines: the display list, `Graphics`, geometry, the
  stage), `avm2_text.c` (TextField, the text engine), `avm2_bitmap.c`, `avm2_events.c`, `avm2_net.c` (Loader,
  URLLoader, sockets), `avm2_xml.c`/`avm2_e4x.c`, `avm2_stage3d.c` (AGAL), `avm2_pixelbender.c`, `avm2_media.c`,
  `avm2_amf.c`, `avm2_regexp.c` (QuickJS's libregexp), `avm2_json.c`, `avm2_vector.c`, `avm2_bytearray.c`, and more.
- **Memory.** `avm2_gc.c` is a mark-sweep collector, separate from AVM1's. It runs **only between ticks**, because
  live operand stacks and locals are on the C stack where it cannot see them, and it scans native extension data
  conservatively as a safety net for missed edges. `AVM2_GC=0` disables it.
- **Native intrinsics.** `avm2_flixel.c` replaces Flixel's `FlxQuadTree`/`FlxList` (and one `FlxTilemap` method) with
  C. The recompiler fingerprints the class bytecode, the runtime installs the C version only on an exact match, and
  `AVM2_NO_INTRINSICS=1` restores the game's own compiled code. Ruffle has no counterpart; it exists because those
  classes were most of the frame time in Robot Wants Kitty.

### The player: `src/libswf/`

| File | Role |
|---|---|
| `swf_core.c` | The **no-graphics** frame loop (`#ifdef NO_GRAPHICS`): bounded ticks, no renderer |
| `swf.c` | The **graphics** frame loop (`#ifndef NO_GRAPHICS`): the native offscreen build and the browser build |
| `tag.c` (~18k lines) | Tag execution and the display list: PlaceObject/RemoveObject, sprites, text layout, filters, the render walk |
| `tag_stubs.c` | Display-list helpers built in both modes; a few sections are `NO_GRAPHICS`-only (the global display list and dictionary storage, catch-up state) |
| `ng_shared.c` | Definition registries (fonts, text fields, exports, bounds, sounds, videos, buttons) shared by every mode |
| `hit_test.c`, `shape_hit_test.c`, `input_events.c` | Hit testing and input |
| `capture.c`, `graphics_stubs.c` | Frame capture for image tests (offscreen only); symbols the browser build needs from the other arms |

### Rendering and audio

- `src/rendering/render_webgpu.c` (~9k lines) is the one renderer, written against the standard `webgpu.h` C API.
  Natively it runs on [Dawn](https://dawn.googlesource.com/dawn); with `-DOFFSCREEN_RENDER` it renders to a buffer,
  which is how CI renders on software Vulkan (lavapipe). In the browser it runs on the browser's WebGPU through
  Emscripten's `emdawnwebgpu` port. Stage quality maps to the MSAA sample count as Ruffle does (`quality.rs`: low 1,
  medium 2, high and best 4). Filters, blend modes and masks are WGSL passes, many of them ported from Ruffle's
  wgpu shaders (§6).
- `src/rendering/render_stub.c` is a no-op renderer, so the browser arms can be compiled natively for sanitizer runs.
- `src/avm2/avm2_cpu_raster.c` is a CPU shape rasteriser for `BitmapData.draw()` (both VMs). It also works in
  no-graphics builds.
- `src/audio/` mixes sound (`audio.c`); in the browser the output is an AudioWorklet (`audio_output_web.c`).
- `src/flashbang/` is the SDL3 GPU renderer inherited from upstream SWFRecomp. Only that directory's CMake build uses
  it; the harness and the browser builds do not.

### The three builds

| Build | Defines | Frame loop | Renderer |
|---|---|---|---|
| no-graphics (harness default) | `-DNO_GRAPHICS` | `swf_core.c` | none |
| graphics, native (`--mode=graphics`, the per-change CI mode) | `-DUSE_WEBGPU -DOFFSCREEN_RENDER` | `swf.c` | `render_webgpu.c` on Dawn, offscreen |
| browser (Emscripten) | `-DUSE_WEBGPU` (AVM1 graphics pages also use `-sASYNCIFY`) | `swf.c` | `render_webgpu.c` on browser WebGPU |

The graphics build is the one CI grades, because it runs the frame loop the browser runs. The no-graphics build is a
faster, separate loop. Trace results are identical between the two modes apart from a few audio rows
([`plans/PROJECT_STATE.md`](plans/PROJECT_STATE.md) §1). Code under `#if NO_GRAPHICS || OFFSCREEN_RENDER` runs in both
harness builds but **not** in the browser, so a browser-only arm can diverge without CI seeing it;
[`reference/browser-wasm-gate-inventory.md`](reference/browser-wasm-gate-inventory.md) tracks those arms.

### The in-browser recompiler

[`docs/recompiler/`](../docs/recompiler/) runs `SWFRecomp` compiled to WebAssembly, then compiles the generated C with
a clang that runs in the page (the Wasmer SDK's clang package), linked against a runtime snapshot. This is why the
emission options in §2 exist.

## 4. The test harness (`ruffle-tests/`)

- **Corpus.** `download_tests.sh` sparse-checks-out Ruffle's `tests/tests/swfs/` (Ruffle's own tests plus those it
  imported from Gnash, Shumway and Tamarin/avmplus) into `ruffle-tests/tests/swfs/<suite>/`. None of it is committed.
  Our own fixtures are in `tests/swfs/regression/` (tracked; most goldens are FP32 captures).
- **One test.** `verify_output.py --test=NAME`:
  1. recompile `test.swf` and its child SWFs;
  2. copy the runtime sources the mode needs into a temp dir and compile them with the generated C (`-O2`, with ccache when it is installed);
  3. run for the `num_frames` in `test.toml`;
  4. compare the trace output with `output.txt`.

  `--mode=graphics` builds the Dawn offscreen binary, and `--images` adds the pixel comparisons from `test.toml`.
  Image results never change a test's status.
- **Determinism.** `MOCK_DATE_TIME` (Ruffle's `--deterministic` epoch by default) seeds `Date` and the `Math.random`
  generator, so two runs at the same commit produce identical results.
- **Statuses.** `pass` is a byte-exact trace. `ruffle_matched` means every remaining diff is one that Ruffle's own
  `output.ruffle.txt` also has (only for tests Ruffle marks `known_failure`); it is **not** a Flash pass. Everything
  else (`output_mismatch`, `runtime_error`, `segfault`, `timeout`, `compile_fail`) is a failure. Tests excluded with a
  reason are in `ignored_tests.txt`, and the reasons are written up under `tests/swfs/avm1/_investigation/`
  (`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md`).
- **CI.** [`ruffle-tests.yml`](../.github/workflows/ruffle-tests.yml) (manual dispatch) shards the corpus over 30
  runners by default.
  - `categories=all` runs the five classic suites; `full` adds `from_avmplus` and the nine small categories.
  - `mode=graphics` is the default; `images=true` is a separate render-baseline run.
  - Results are published to the `ruffle-test-results` branch, then merged into `master` as each suite's `_results/`
    and the tables in [`ruffle-tests/results/`](../ruffle-tests/results/README.md).
  - [`weekly-no-graphics.yml`](../.github/workflows/weekly-no-graphics.yml) runs the no-graphics leg every Sunday.
- **The Flash Player 32 oracle.** [`tools/flash-oracle/`](../tools/flash-oracle/README.md) scripts the real FP32
  debug projectors (Linux under Xvfb, and Windows through WSL) for traces (`run_trace.py`) and screenshots
  (`run_image.py`). The binaries live outside the repository and are never uploaded. When FP32 shows a Ruffle golden
  is wrong, the corrected golden goes in [`ruffle-tests/flash_fixes/`](../ruffle-tests/flash_fixes/README.md)
  (`fixes.json`, re-applied by `apply_flash_fixes.py` after every download). The rule is to match Flash when Flash and
  Ruffle disagree.
- **Divergence harnesses.** [`tools/divergence/`](../tools/divergence/) injects a tracer into a SWF and reports the
  first point where our run differs from Ruffle's or Flash's
  ([`guides/divergence-harness-usage.md`](guides/divergence-harness-usage.md)). The browser harness is in
  [`tools/browser-test/`](../tools/browser-test/) ([`guides/browser-test-harness-usage.md`](guides/browser-test-harness-usage.md)).
- `SWFRecomp/tests/` is the original 2025 hand-written suite (`all_tests.sh`). CI does not run its validators; `ruffle-tests.yml`
  only builds two of its tests (`trace_swf_4`, `graphics/three_boxes`) to WebAssembly as a link check.

## 5. Main differences from Ruffle's design

| | Ruffle | SWFRecomp-CC |
|---|---|---|
| Execution | Interprets AVM1 and AVM2 bytecode at run time (Rust) | Translates bytecode to C before the build; no interpreter |
| Content | Any SWF, loaded at run time | Only the SWFs compiled into the binary; child movies are recompiled and linked with their parent |
| AVM2 verification | Lazily at run time, before a method first runs | In the recompiler; failing bodies become stubs that throw the `VerifyError` |
| Values and objects | One GC-managed heap (`gc-arena`) shared by both VMs | Two separate value models and heaps: AVM1 `ActionVar` (refcounting plus a tick-boundary mark-sweep backstop) and AVM2 `Avm2Value` (mark-sweep between ticks only) |
| Property lookup | At run time | AVM1 names interned to string ids at recompile time; AVM2 per-site static inline caches in the generated C |
| Shapes and glyphs | Tessellated at run time (lyon) | Tessellated at recompile time (libtess2); only run-time geometry is tessellated in the runtime |
| Renderer | Pluggable backends (wgpu, WebGL, canvas) | One C WebGPU renderer, on Dawn natively and on the browser's WebGPU |
| Timeline | Tag stream decoded at run time | Each frame is a compiled C function; gotos replay frame functions with scripts suppressed |
| Behaviour target | Flash Player | Flash Player 32. Ruffle's goldens are the instrument, and FP32 overrides them (`flash_fixes/`) |
| Game-specific code | None | Fingerprint-gated native replacements for a few hot library classes (Flixel) |

Costs of the design that a Ruffle developer will notice:
- **Build time.** Large games produce tens of megabytes of C (Seedling: about 52 MB with `skip_avm1_payload`).
- **No dynamic content.** A SWF missing from the build cannot be loaded at run time.
- **Two of everything.** The two VMs have separate object models, and there are several builds. A behaviour fix
  often has to be made in more than one place, and the browser arms can drift from the CI arms (§3).

Performance work and how it compares with Ruffle's own optimisations:
[`reference/performance-optimizations-vs-ruffle.md`](reference/performance-optimizations-vs-ruffle.md).

## 6. Ruffle-derived code

Ruffle's source is the first reference for how a Flash API behaves, and some of it was ported. Under decision D12
([`plans/repo-cleanup-plan.md`](plans/repo-cleanup-plan.md) §12), that code is used **under Ruffle's MIT licence**
([`../SWFModernRuntime/third_party/ruffle/LICENSE-MIT.txt`](../SWFModernRuntime/third_party/ruffle/LICENSE-MIT.txt),
listed in [`../THIRD_PARTY_NOTICES.md`](../THIRD_PARTY_NOTICES.md)).

The A1 audit (2026-11-28, against Ruffle `0ddd12b6a`) found **165 ported functions, tables and shaders in 63 of our
files**. Each one names its Ruffle source file in a comment, and they are all listed, with their kind (port, close
model, table/constants, shader, generated) and the Ruffle commit where known, in
[`../SWFModernRuntime/third_party/ruffle/README.md`](../SWFModernRuntime/third_party/ruffle/README.md). Where most of
it is:

- **`action.c`** (21 rows): AVM1 number-to-string (`f64_to_string`), the `Array.sort` quicksorts, BitmapData
  operations (noise, Perlin turbulence, `copyPixels`), `AsBroadcaster`, the `flash.geom` classes, and the
  tab-order sort key.
- **The AVM2 class library** (`avm2_display.c` 18, `avm2_text.c` 9, `avm2_bitmap.c` 9, `avm2_stage3d.c` 6,
  `avm2_globals.c` 6, `avm2_net.c` 5, …): geometry surfaces, the unified timer list, text-layout rounding, bitmap
  blend and filter passes, and the avmplus qsort (from Ruffle's AVM2 `array.rs`).
- **The renderer** (`render_webgpu.c`): WGSL shaders for blur, colour matrix, displacement, the glow/shadow/bevel
  composite, the complex blend modes and focal gradients, and the nested stencil-mask model.
- **`tag.c`**: text-field metrics, word wrap, and filter offset tables.
- **The recompiler** (`swf.cpp`, `abc_verifier.cpp`, `abc_timeline.cpp`, `abc_devicefont.cpp`): a few tables and
  algorithms, including the device-font fallback ladder.
- **Ruffle's own dependencies**: the h263-rs deblock filter and YUV conversion in `video_codec.c`, and the AMF wire
  format from rust-flash-lso in `avm2_amf.c`, each under its MIT licence (listed in the same README).
- **Generated from Ruffle's data**: `unicode_case_tables.h` and `avm1_native_table.inc` come from Ruffle's test
  goldens, and the AVM2 error messages from `error_messages.rs`.

Comments that only say our output matches Ruffle's, or describe a behaviour (event order, timeline semantics) that our
own code implements, were not counted as ports. Most of the roughly 2,900 mentions of Ruffle in the source are of that
kind.

## 7. Where to read next

- [`README.md`](README.md): the index of these docs.
- [`plans/PROJECT_STATE.md`](plans/PROJECT_STATE.md) and [`plans/NO_GO_REGISTER.md`](plans/NO_GO_REGISTER.md): the
  current state, and the work ruled out.
- [`../ruffle-tests/README.md`](../ruffle-tests/README.md),
  [`../SWFRecomp/README.md`](../SWFRecomp/README.md), [`../SWFModernRuntime/README.md`](../SWFModernRuntime/README.md):
  the component source maps.
- [`../CLAUDE.md`](../CLAUDE.md): the agent manual, which also lists the runtime traps.
