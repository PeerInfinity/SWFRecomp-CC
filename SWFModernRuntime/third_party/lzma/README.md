# LZMA SDK (vendored)

Igor Pavlov's LZMA SDK, **public domain** (notice at the head of each file),
vendored for `ByteArray.compress("lzma")` / `uncompress("lzma")`
(`SWFModernRuntime/src/avm2/avm2_bytearray.c`). Version 18.05, taken from
the `C/` directory of https://github.com/jljusten/lzma-sdk.

Files: `LzmaDec.[ch]`, `LzmaEnc.[ch]`, `LzFind.[ch]`, `LzHash.h`,
`7zTypes.h`, `Compiler.h`, `Precomp.h`. The multi-threaded match finder
(`LzFindMt.*`), LZMA2, and everything 7z-archive-related are deliberately
left out.

## Local changes

`Precomp.h` defines `_7ZIP_ST` (single-threaded). It is done there rather
than on the command line because the runtime is compiled by several scripts
that just glob the sources; `Precomp.h` is the first include of every LZMA
`.c` file, so one edit reaches them all. This keeps `LzFindMt` — and its
pthread dependency, which WASM does not want — out of the build.

Everything else is upstream, unmodified.

## Wrapper

`lzma_alone.[ch]` is ours, not upstream. It implements the **LZMA-alone**
container the Flash `ByteArray` API uses — a 13-byte header (1 properties
byte, u32le dictionary size, u64le uncompressed size, all-ones meaning
"unknown, read to the end marker") followed by the raw LZMA stream — which
is also what Ruffle's `lzma_rs::lzma_{compress,decompress}` produce and
consume, and what the `LZMA.jar` blobs embedded in
`from_avmplus/as3/ByteArray/ByteArrayLzmaThirdParty` are in.

It exists as its own translation unit so that no runtime source has to
include `7zTypes.h`, whose `Byte` / `Bool` / `True` / `False` would collide.
`lzma_alone.h` pulls in nothing but `<stddef.h>` and `<stdint.h>`.

The encoder writes `lc=3 lp=0 pb=2` (properties byte `0x5D`, matching
lzma_rs and the corpus blobs) and sets `reduceSize` to the input length so
the dictionary — and the encoder's working set — shrinks to the data at
hand. The dictionary size therefore varies with input, which is legal: it
is recorded in the header and nothing in the corpus compares compressed
bytes.

## Build wiring

Copied flat into the build directory alongside the other vendored trees, by:

- `ruffle-tests/verify_output.py` (`compile_native`, AVM2 branch)
- `ruffle-tests/verify_output_keep.py`
- `SWFRecomp/scripts/build_wasm_avm2.sh`
