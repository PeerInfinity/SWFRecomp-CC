# SWFRecomp-CC

This repository combines several SWFRecomp repositories into a single workspace to make them easier to work with together. Because the contents were merged from separate repositories, some internal links may be broken and documents may reference repository structures or URLs that no longer apply in this combined layout.

**Documentation:** [SWFRecompDocs/README.md](SWFRecompDocs/README.md)

## Live pages

Served from `docs/` at [peerinfinity.github.io/SWFRecomp-CC](https://peerinfinity.github.io/SWFRecomp-CC/). These need a Chromium-based browser with WebGPU enabled.

| Page | What it is |
|------|------------|
| [Demo gallery](https://peerinfinity.github.io/SWFRecomp-CC/) | Recompiled SWFs running as WebAssembly, with a side-by-side Ruffle comparison view |
| [In-browser recompiler](https://peerinfinity.github.io/SWFRecomp-CC/recompiler/) | Drop a `.swf` in and it is recompiled to C in the page. Download the generated code with a build script, or compile and run it right there — no toolchain installed |

Beyond the small test SWFs in the gallery, **Seedling** — a full Flash game — has been put through SWFRecomp into WebAssembly. Those builds live in [seedling-wasm](https://github.com/PeerInfinity/seedling-wasm), whose README links the hosted, playable pages.

## Contents

| Directory | Description | Original Repository |
|-----------|-------------|---------------------|
| `SWFRecomp/` | Static recompiler — translates Flash SWF bytecode into portable C code | [SWFRecomp/SWFRecomp](https://github.com/SWFRecomp/SWFRecomp) (fork: [PeerInfinity/SWFRecomp](https://github.com/PeerInfinity/SWFRecomp)) |
| `SWFModernRuntime/` | Runtime library — ActionScript runtime, rendering, and WebGPU backend | [SWFRecomp/SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime) (fork: [PeerInfinity/SWFModernRuntime](https://github.com/PeerInfinity/SWFModernRuntime)) |
| `SWFRecompDocs/` | Documentation — guides, specs, plans, and status tracking | [SWFRecomp/SWFRecompDocs](https://github.com/SWFRecomp/SWFRecompDocs) |
| `docs/` | GitHub Pages site — the live pages above, served from this repo | |
| `ruffle-tests/` | Test harness, per-suite results, and this project's own hand-written regression tests. The ~4,500-test upstream corpus it runs against (Ruffle, Gnash, Shumway, Tamarin) is **not** stored here — `ruffle-tests/download_tests.sh` fetches it | |
| `tools/` | Divergence harnesses, browser-test drivers, SWF analysis and performance measurement | |
| `scripts/` | Build, CI and test-result processing scripts | |
| `demos/` | ActionScript sources used by the demo pages | |
| `docs2/` | Second demo site for SWFs that are not OSS-licensed. Local hosting only — deliberately never deployed to Pages, so publishing it would redistribute copyrighted games. Not a superseded copy of `docs/` | |

## Original Repositories

- **SWFRecomp** (by LittleCube): [https://github.com/SWFRecomp/SWFRecomp](https://github.com/SWFRecomp/SWFRecomp)
- **SWFModernRuntime** (by LittleCube): [https://github.com/SWFRecomp/SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime)
- **SWFRecompDocs**: [https://github.com/SWFRecomp/SWFRecompDocs](https://github.com/SWFRecomp/SWFRecompDocs)
- **N64Recomp** (inspiration, by Wiseguy): [https://github.com/N64Recomp/N64Recomp](https://github.com/N64Recomp/N64Recomp)
