# SWFRecomp: the recompiler

SWFRecomp reads a Flash SWF file and writes C. It is the ahead-of-time half of
[SWFRecomp-CC](../README.md); the generated C is compiled together with the runtime in
[`../SWFModernRuntime/`](../SWFModernRuntime/README.md) into a native executable or a WebAssembly page.

To build it and run a test, follow [`../GETTING_STARTED.md`](../GETTING_STARTED.md).

## What it does

```
test.swf ─► SWFRecomp ─► RecompiledScripts/   AVM1 action blocks as C functions
                      ├► RecompiledTags/      the timeline: one function per frame, shapes, fonts, bitmaps, sounds
                      └► RecompiledABC/       AVM2 (ActionScript 3) methods as C, for SWFs with DoABC tags
```

- **AVM1** (ActionScript 1 and 2). Each action block becomes a C function that calls into the runtime's AVM1 VM.
- **AVM2** (ActionScript 3). The ABC bytecode is parsed and verified, and each method body is emitted as C with its
  control flow and registers laid out at recompile time.
- **Display data.** Shapes, morph shapes and glyphs are tessellated at recompile time (libtess2), so the runtime
  receives triangle arrays. Bitmaps, sounds, fonts and text fields are emitted as C data.
- The recompiler detects AVM1 or AVM2 per SWF; nothing needs to be configured.

## Source map

| Path | What |
|---|---|
| `src/main.cpp`, `src/config.cpp` | Entry point; reads a `config.toml` (input SWF, output folders) |
| `src/swf.cpp`, `src/field.cpp` | SWF container: header, decompression (zlib, LZMA), tag stream |
| `src/tag.cpp` | Tag handling: display list tags, shapes, fonts, text, bitmaps, sounds, sprites |
| `src/action/action.cpp` | AVM1 bytecode → C |
| `src/abc/` | AVM2: `abc_parser`, `abc_verifier`, `abc_emit` (→ C), `abc_timeline`, `abc_devicefont`; `abc_dump`/`abc_tool` back `--dump-abc` / `--check-abc` |
| `src/recompilation.cpp` | Drives a whole recompile and writes the output files |
| `lib/` | Vendored zlib, LZMA, toml++, earcut, stb (licences in [`../THIRD_PARTY_NOTICES.md`](../THIRD_PARTY_NOTICES.md)) |
| `wasm_wrappers/` | The `main.c` the test harness links, and the bundle for the in-browser recompiler |
| `scripts/` | Build scripts: `build_test.sh` (native or WASM build of one test), `build_wasm_avm2.sh` / `deploy_wasm_avm2.sh` (AVM2 games in the browser), `build_wasm_recompiler.sh` (the recompiler itself as WASM), `deploy_example.sh` (Pages demos) |
| `tests/` | The original hand-written test suite (one directory per test, runner `tests/all_tests.sh`). The main test corpus is under [`../ruffle-tests/`](../ruffle-tests/README.md) |

## Running it by hand

`verify_output.py` normally runs the recompiler for you. To run it directly, give it a config file:

```bash
cmake -S SWFRecomp -B SWFRecomp/build -DCMAKE_BUILD_TYPE=Release && cmake --build SWFRecomp/build -j"$(nproc)"
cd SWFRecomp/tests/trace_swf_4
../../build/SWFRecomp config.toml        # writes RecompiledScripts/ and RecompiledTags/ here
```

`SWFRecomp --dump-abc <file.swf>` prints a SWF's AVM2 bytecode; `--check-abc` runs only the verifier.

The recompiler is also compiled to WebAssembly for the
[in-browser recompiler](https://peerinfinity.github.io/SWFRecomp-CC/recompiler/) (`scripts/build_wasm_recompiler.sh`).

## Origin

Forked in October 2025 from [SWFRecomp](https://github.com/SWFRecomp/SWFRecomp) by LittleCube, which was inspired by
Wiseguy's [N64Recomp](https://github.com/N64Recomp/N64Recomp). Since July 2026 the two are a permanent friendly fork
that exchange knowledge but not code; see the [root README](../README.md#upstream-swfrecomp). Relative to the fork point
this recompiler adds AVM2, recompile-time tessellation, the emission modes the test corpus uses, and the WASM build of
the recompiler itself.

## Licence

MIT, as upstream ([`LICENSE`](LICENSE)).
