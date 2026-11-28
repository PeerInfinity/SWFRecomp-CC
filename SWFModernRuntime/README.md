# SWFModernRuntime: the runtime

The runtime library of [SWFRecomp-CC](../README.md). It executes the C that the [`../SWFRecomp/`](../SWFRecomp/README.md)
recompiler generates: the AVM1 and AVM2 virtual machines, the Flash class library, the player loop and display list,
rendering and audio. The same sources build three ways:

| Build | Player loop | Rendering | Used by |
|---|---|---|---|
| no-graphics (`-DNO_GRAPHICS`) | `src/libswf/swf_core.c` | none | the test harness's default mode |
| graphics, native (`-DUSE_WEBGPU -DOFFSCREEN_RENDER`) | `src/libswf/swf.c` | `src/rendering/render_webgpu.c` on [Dawn](https://dawn.googlesource.com/dawn), offscreen on software Vulkan | `--mode=graphics`, the CI grading mode; image captures |
| browser (Emscripten) | `src/libswf/swf.c` | `render_webgpu.c` on the browser's WebGPU | the [live demos](https://peerinfinity.github.io/SWFRecomp-CC/), Seedling |

There is no separate library build step for testing: `ruffle-tests/verify_output.py` compiles the runtime sources it
needs together with each test's generated C. See [`../GETTING_STARTED.md`](../GETTING_STARTED.md).

## Source map

| Path | What |
|---|---|
| `src/actionmodern/` | **AVM1** (ActionScript 1 and 2). `action.c` is the core: values, objects, prototypes, scope chain, the built-in classes and the MovieClip API. Beside it: `variables.c`, `object.c`, `math.c`, `date.c`, `timer.c`, `avm1_amf.c` (SharedObject/AMF0), `registered_class.c`, `image_decode.c`, `video_codec.c`, filter kernels |
| `src/avm2/` | **AVM2** (ActionScript 3): the value model and object/class system (`avm2_value.c`, `avm2_object.c`, `avm2_class.c`), operations (`avm2_ops.c`), GC (`avm2_gc.c`), and the flash.* and top-level classes, one file per area (`avm2_display.c`, `avm2_text.c`, `avm2_bitmap.c`, `avm2_xml.c`/`avm2_e4x.c`, `avm2_net.c`, `avm2_stage3d.c`, …) |
| `src/libswf/` | The player: frame loop (`swf.c` / `swf_core.c`), display list and tag execution (`tag.c`), hit testing and input events |
| `src/rendering/` | `render_webgpu.c`, the WebGPU renderer (shapes, text, bitmaps, filters, blend modes); `render_stub.c`, a no-op renderer that lets the browser build's code paths compile natively for sanitizer runs |
| `src/audio/` | Sound mixing (`audio.c`) and the browser AudioWorklet output |
| `src/memory/` | The heap allocator wrapper (o1heap) |
| `src/flashbang/` | The SDL3 GPU renderer inherited from upstream. Only the CMake build in this directory uses it; the test harness and browser builds do not |
| `include/` | Headers, mirroring `src/` |
| `lib/`, `third_party/` | Vendored libraries (zlib, LZMA, c-hashmap, o1heap, SDL3, libtess2, QuickJS regexp) and the Ruffle licence for ported code; see [`../THIRD_PARTY_NOTICES.md`](../THIRD_PARTY_NOTICES.md) |

The behaviour target is Flash Player 32 (see the [root README](../README.md#the-goal-match-flash-player-32)). Many
functions document which Ruffle or Flash behaviour they reproduce in a comment above them, and the test that pins it.

## Origin

Forked in October 2025 from [SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime) by LittleCube. Since July
2026 the two are a permanent friendly fork: same idea, diverged architectures, knowledge exchanged but no code merged in
either direction ([`../SWFRecompDocs/merge/upstream-relationship-2026-07.md`](../SWFRecompDocs/merge/upstream-relationship-2026-07.md)).
Upstream has SDL3, a thread-safe context, a concurrent GC and an AS2-prelude standard library. This fork added the
AVM2 runtime, the WebGPU renderer used here, and the behaviour work measured by the test corpus.

## Licence

MIT, as upstream ([`LICENSE`](LICENSE)).
