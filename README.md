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
| `SWFRecomp/` | Static recompiler — translates Flash SWF bytecode (AVM1 and AVM2) into portable C code | [SWFRecomp/SWFRecomp](https://github.com/SWFRecomp/SWFRecomp) |
| `SWFModernRuntime/` | Runtime library — AVM1 and AVM2 ActionScript runtimes, rendering, and WebGPU backend | [SWFRecomp/SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime) |
| `SWFRecompDocs/` | Documentation — guides, specs, plans, and status tracking | [SWFRecomp/SWFRecompDocs](https://github.com/SWFRecomp/SWFRecompDocs) (frozen Nov 2025; maintained here since) |
| `docs/` | GitHub Pages site — the live pages above, served from this repo | |
| `ruffle-tests/` | Test harness, per-suite results, and this project's own hand-written regression tests. The ~4,500-test upstream corpus it runs against (Ruffle, Gnash, Shumway, Tamarin) is **not** stored here — `ruffle-tests/download_tests.sh` fetches it | |
| `tools/` | Divergence harnesses, browser-test drivers, SWF analysis and performance measurement | |
| `scripts/` | Build, CI and test-result processing scripts | |
| `demos/` | ActionScript sources used by the demo pages | |
| `docs2/` | Second demo site for SWFs that are not OSS-licensed. Local hosting only — deliberately never deployed to Pages, so publishing it would redistribute copyrighted games. Not a superseded copy of `docs/` | |

## Relationship to the upstream SWFRecomp project

SWFRecomp-CC forked from LittleCube's [SWFRecomp](https://github.com/SWFRecomp/SWFRecomp)
and [SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime) in October 2025.
Since July 2026 the two projects are a **permanent friendly fork**: they share the
idea (recompile SWF bytecode to C, run it natively or as WASM) and exchange
knowledge, but not code — the architectures have diverged too far to merge in
either direction. Upstream is the architecture project (thread-safe context,
concurrent GC, string-ID properties, an AS2 prelude standard library, SDL3);
this repo is the behavioral-parity project (the full Ruffle/Gnash/Shumway/Tamarin
test corpus at 98% effective, AVM1 *and* AVM2, headless and browser-WASM modes,
playable games). Decision record and current status:
[`SWFRecompDocs/merge/upstream-relationship-2026-07.md`](SWFRecompDocs/merge/upstream-relationship-2026-07.md);
analyses of what each side does better and the trap map we maintain for upstream:
[`SWFRecompDocs/upstream-comparison/`](SWFRecompDocs/upstream-comparison/).

- **Upstream (LittleCube):** [SWFRecomp/SWFRecomp](https://github.com/SWFRecomp/SWFRecomp),
  [SWFRecomp/SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime),
  [SWFRecomp/AS2Runtime](https://github.com/SWFRecomp/AS2Runtime),
  [SWFRecomp/mtasc](https://github.com/SWFRecomp/mtasc). Tracked read-only under
  `upstream/` (gitignored); behavioral findings are reported as GitHub issues there.
- **Historical:** [PeerInfinity/SWFRecomp](https://github.com/PeerInfinity/SWFRecomp)
  and [PeerInfinity/SWFModernRuntime](https://github.com/PeerInfinity/SWFModernRuntime)
  carried the 2025 `wasm-support` branches and later LittleCube's PR branches; they
  are not used for current work. [SWFRecomp/SWFRecompDocs](https://github.com/SWFRecomp/SWFRecompDocs)
  is the frozen origin of `SWFRecompDocs/`.
- **Inspiration:** [N64Recomp](https://github.com/N64Recomp/N64Recomp) by Wiseguy.
