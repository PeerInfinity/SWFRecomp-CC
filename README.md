# SWFRecomp-CC

This repository combines several SWFRecomp repositories into a single workspace to make them easier to work with together. Because the contents were merged from separate repositories, some internal links may be broken and documents may reference repository structures or URLs that no longer apply in this combined layout.

**Documentation:** [SWFRecompDocs/README.md](SWFRecompDocs/README.md)

## Live pages

Served from `docs/` at [peerinfinity.github.io/SWFRecomp-CC](https://peerinfinity.github.io/SWFRecomp-CC/). These need a Chromium-based browser with WebGPU enabled.

| Page | What it is |
|------|------------|
| [Demo gallery](https://peerinfinity.github.io/SWFRecomp-CC/) | Recompiled SWFs running as WebAssembly, with a side-by-side Ruffle comparison view |
| [In-browser recompiler](https://peerinfinity.github.io/SWFRecomp-CC/recompiler/) | Drop a `.swf` in and it is recompiled to C in the page. Download the generated code with a build script, or compile and run it right there — no toolchain installed |
| [Injection demos](https://peerinfinity.github.io/SWFRecomp-CC/injector/) | Runtime SWF injection demos |
| [Image dashboard](https://peerinfinity.github.io/SWFRecomp-CC/image-dashboard/) | Render-comparison dashboard for the graphics test suite (regenerated on each Pages deploy) |

## Contents

| Directory | Description | Original Repository |
|-----------|-------------|---------------------|
| `SWFRecomp/` | Static recompiler — translates Flash SWF bytecode into portable C code | [SWFRecomp/SWFRecomp](https://github.com/SWFRecomp/SWFRecomp) (fork: [PeerInfinity/SWFRecomp](https://github.com/PeerInfinity/SWFRecomp)) |
| `SWFModernRuntime/` | Runtime library — ActionScript runtime, rendering, and WebGPU backend | [SWFRecomp/SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime) (fork: [PeerInfinity/SWFModernRuntime](https://github.com/PeerInfinity/SWFModernRuntime)) |
| `SWFRecompDocs/` | Documentation — guides, specs, plans, and status tracking | [SWFRecomp/SWFRecompDocs](https://github.com/SWFRecomp/SWFRecompDocs) |
| `docs/` | GitHub Pages site — the live pages above, served from this repo | |
| `ruffle-tests/` | Test corpus (~4,500 tests) mirrored from Ruffle, Gnash, Shumway and the Tamarin acceptance suite, plus this project's own regression tests, with the shared runner | |
| `tools/` | Divergence harnesses, browser-test drivers, SWF analysis and performance measurement | |
| `scripts/` | Build, CI and test-result processing scripts | |
| `demos/` | ActionScript sources used by the demo and injector pages | |
| `docs2/` | Second demo site for SWFs that are not OSS-licensed. Local hosting only — deliberately never deployed to Pages, so publishing it would redistribute copyrighted games. Not a superseded copy of `docs/` | |

## Original Repositories

- **SWFRecomp** (by LittleCube): [https://github.com/SWFRecomp/SWFRecomp](https://github.com/SWFRecomp/SWFRecomp)
- **SWFModernRuntime** (by LittleCube): [https://github.com/SWFRecomp/SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime)
- **SWFRecompDocs**: [https://github.com/SWFRecomp/SWFRecompDocs](https://github.com/SWFRecomp/SWFRecompDocs)
- **N64Recomp** (inspiration, by Wiseguy): [https://github.com/N64Recomp/N64Recomp](https://github.com/N64Recomp/N64Recomp)
