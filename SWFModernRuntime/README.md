# SWFModernRuntime

The runtime library of [SWFRecomp-CC](https://github.com/PeerInfinity/SWFRecomp-CC): executes the C code that the `SWFRecomp/` recompiler generates from Flash SWF files, natively (headless or with offscreen Dawn/WebGPU rendering) or as WebAssembly in the browser.

Forked in October 2025 from [SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime) by LittleCube. Since July 2026 the two are a **permanent friendly fork** — same idea, diverged architectures, knowledge exchanged but no code merged in either direction. See [`../SWFRecompDocs/merge/upstream-relationship-2026-07.md`](../SWFRecompDocs/merge/upstream-relationship-2026-07.md) for the decision and status, and [`../SWFRecompDocs/upstream-comparison/`](../SWFRecompDocs/upstream-comparison/) for what each side's architecture does better.

## What is This?

This runtime contains an AVM1 (ActionScript 1/2) implementation in `src/actionmodern/`, an AVM2 (ActionScript 3) implementation in `src/avm2/`, the SWF tag/display-list layer in `src/libswf/`, and rendering in `src/rendering/` (native offscreen via Dawn, browser via emscripten + WebGPU). It runs the full Ruffle, Gnash, Shumway and Tamarin test corpora in CI.

**Live Demos:** https://peerinfinity.github.io/SWFRecomp-CC/

## Documentation

Everything lives in the combined repo's [`SWFRecompDocs/`](../SWFRecompDocs/README.md) directory (the upstream `SWFRecompDocs` repository it descends from has been frozen since November 2025):

- **[Session start guide](../ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md)** - Architecture, how to run tests, infrastructure
- **[Reference](../SWFRecompDocs/reference/)** - Technical documentation
- **[Guides](../SWFRecompDocs/guides/)** - Step-by-step guides

**Related Repositories:**
- **[SWFRecomp/](../SWFRecomp/)** - The static recompiler (same repo)
- **[SWFRecomp/SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime)** - Upstream runtime by LittleCube (SDL3, concurrent GC, AS2-prelude stdlib) — tracked, not merged

## Quick Demo

The `trace_swf_4` example is working! It demonstrates:
- SWF bytecode → C code → WebAssembly compilation pipeline
- ActionScript execution in browser
- String operations and console output
- Native performance without Flash Player

**[Try it live!](https://swfrecomp.github.io/SWFRecompDocs/examples/trace-swf-test/)**

## Project Goals

- Compile SWFRecomp-generated C code to WebAssembly
- Add Canvas2D rendering backend (in progress)
- Support SDL3 WebGPU (when available)
- Maintain 100% compatibility with native runtime

## Architecture

```
Flash SWF → SWFRecomp → C Code → Emscripten → WASM → Browser
                                      ↓
                            Canvas2D/WebGL2/WebGPU
```

The generated C code is **100% portable** - it compiles to both native and WASM with the same source.

## Repository Structure

```
SWFModernRuntime/
├── src/                    # Runtime source
│   ├── libswf/            # Core SWF execution
│   ├── actionmodern/      # ActionScript VM with variable storage improvements
│   └── flashbang/         # Native GPU rendering
├── include/               # Header files
├── test_*.c               # Test suite for variable storage
└── Makefile.test*         # Build files for tests
```

## Building

### Run Tests

This repository contains a comprehensive test suite for the variable storage system:

```bash
# Build and run all tests
make -f Makefile.test

# Or run individual test suites
make -f Makefile.test_simple              # Basic variable tests
make -f Makefile.test_string_id           # String ID optimization tests
make -f Makefile.test_simple_string_id    # Simple ID tests
```

### Integration with SWFRecomp

This runtime is used by [SWFRecomp](https://github.com/SWFRecomp/SWFRecomp) when generating WASM builds. See the SWFRecomp repository for complete build instructions and working examples.

## Current Status

| Feature | Status | Notes |
|---------|--------|-------|
| **ActionScript VM** | ✅ Working | String ops, math, variables |
| **Variable Storage** | ✅ Working | Copy-on-Store, array optimization |
| **Memory Management** | ✅ Working | Proper cleanup, no leaks |
| **Test Suite** | ✅ Complete | 1,100+ lines of tests |
| **Frame execution** | ✅ Working | Frame-by-frame playback |
| **Native GPU Rendering** | ✅ Working | SDL3 + WebGPU (upstream) |

## Key Features in This Fork

### Variable Storage Improvements
- **Copy-on-Store**: Variables own their string data
- **Array Optimization**: O(1) lookup for constant strings by ID
- **Memory Management**: Proper heap allocation and cleanup
- **Ownership Tracking**: No memory leaks or dangling pointers

See the [branch differences document](../SWFRecompDocs/deprecated/merge/swfmodernruntime-branch-differences.md) (historical, November 2025) for the details of that first divergence.

## Upstream

There is no sync. Upstream is tracked read-only in the combined repo's gitignored `upstream/` clones (`upstream/MERGE-ANALYSIS.md` is the log); behavioral findings about upstream's code are reported as GitHub issues on the org repo, per the arrangement agreed with LittleCube in July 2026.

## License

Same as upstream SWFModernRuntime (see [LICENSE](LICENSE)).

## Credits

- **Origin:** [SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime) by LittleCube
- **Origin:** [SWFRecomp](https://github.com/SWFRecomp/SWFRecomp) by LittleCube
- **Inspiration:** [N64Recomp](https://github.com/N64Recomp/N64Recomp) by Wiseguy

---

**Note:** This is a friendly fork. The upstream project (by LittleCube) is the architecture-first implementation of the same idea; this fork is the behavioral-parity implementation. The two exchange knowledge, not code.
