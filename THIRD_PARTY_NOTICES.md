# Third-party notices

`LICENSE` (MIT) covers this repository's own code: SWFRecomp and SWFModernRuntime as
published by LittleCube, and this fork's additions to them. It does **not** relicense the
third-party code vendored here. Each piece below keeps its own licence, and its licence text
lives at the path given.

| Piece | Path | Licence | Licence text |
|---|---|---|---|
| zlib | `SWFRecomp/lib/zlib/`, `SWFModernRuntime/lib/zlib/` | zlib | `LICENSE` in each |
| toml++ | `SWFRecomp/lib/tomlplusplus/` | MIT | `SWFRecomp/lib/tomlplusplus/LICENSE` |
| earcut.hpp | `SWFRecomp/lib/earcut/` | ISC | `SWFRecomp/lib/earcut/LICENSE` |
| stb | `SWFRecomp/lib/stb/` | MIT or public domain | `SWFRecomp/lib/stb/LICENSE` |
| XZ Utils / liblzma | `SWFRecomp/lib/lzma/`, `SWFModernRuntime/lib/lzma/` | liblzma: public domain (other parts of the package differ; see `COPYING`) | `COPYING` in each |
| LZMA SDK 18.05 (subset) | `SWFModernRuntime/third_party/lzma/` | public domain | notice at the head of each file; `README.md` |
| QuickJS libregexp / libunicode | `SWFModernRuntime/third_party/quickjs-libregexp/` | MIT | header of each file; `README.md` |
| libtess2 | `SWFModernRuntime/third_party/libtess2/` | SGI Free Software License B 2.0 | `SWFModernRuntime/third_party/libtess2/LICENSE.txt` |
| c-hashmap (Mashpoe) | `SWFModernRuntime/lib/c-hashmap/` | BSD-3-Clause | `SWFModernRuntime/lib/c-hashmap/LICENSE`. `map.c` and `map.h` carry no licence header of their own, so copies of them (the in-browser build bundle) must ship this file |
| o1heap (Pavel Kirienko) | `SWFModernRuntime/lib/o1heap/` | MIT | header of `o1heap.h` |
| SDL3 | `SWFModernRuntime/lib/SDL3/` | zlib (some sub-components differ; see its tree) | `SWFModernRuntime/lib/SDL3/LICENSE.txt` |
| sdl3webgpu | `SWFModernRuntime/lib/sdl3webgpu/` | MIT | header of `sdl3webgpu.c` |
| Ruffle (ported code), plus the ruffle-rs crates h263-rs and rust-flash-lso | 165 functions, blocks, tables and shaders in 63 files of `SWFModernRuntime/` and `SWFRecomp/src/`. Each one names its Ruffle source file in a comment. Per-function table, audited 2026-11-28: [`SWFModernRuntime/third_party/ruffle/README.md`](SWFModernRuntime/third_party/ruffle/README.md) | MIT (Ruffle and h263-rs are MIT OR Apache-2.0, used under MIT; rust-flash-lso is MIT) | `SWFModernRuntime/third_party/ruffle/LICENSE-MIT.txt` (Ruffle), `LICENSE-MIT-h263-rs.txt` and `LICENSE-MIT-rust-flash-lso.txt` beside it |
| W3C SVG feTurbulence reference code (via Ruffle) | the Perlin noise in `SWFModernRuntime/src/actionmodern/action.c` | W3C Software Notice | the notice in the comment above `perlin_turbulence` |
| **Noto Sans** | `SWFRecomp/assets/NotoSans.ttf` (embedded in the Emscripten build of the recompiler as the device-font fallback) | **SIL OFL 1.1** | `SWFRecomp/assets/NotoSans-OFL.txt` |
| 04b_03 font | `SWFRecomp/tests/graphics/define_edit_text/04B_03__.TTF` (test fixture only, not shipped in any build) | its author's own terms | — |

Not tracked, and not covered by anything here: `upstream/` (reference checkouts of other
projects, gitignored) and the mirrored upstream test suites under `ruffle-tests/tests/swfs/`
other than `regression/`, which `download_tests.sh` fetches per run.
