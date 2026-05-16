# DefineBitsLossless Format 3 / 4 Decoders

**Status:** Planning — 2026-05-15

## Context

`SWFRecomp/src/swf.cpp` handles `DefineBitsLossless` (tag 20) and
`DefineBitsLossless2` (tag 36), but only for `bitmap_format == 5` (PIX32 /
ALPHARGB). Any other format throws `std::exception` via `EXC_ARG`.

Observed in the flasharchive set:

- **Format 3** (8-bit palette): Art of War (Lossless1), Avalanche
  (Lossless2), Bloons TD (Lossless1), Bloons (Lossless1). Common.
- **Format 4** (15-bit RGB555, Lossless1 only): none in tested flasharchive.
  Rare in modern Flash content but spec-required.

The throws are now caught by the per-tag handler (since `9a9522e8`), so they
don't truncate the recompile — but the affected bitmaps are simply missing
from the output. Visually that means transparent placeholders where Art_of_War
expects unit sprites, terrain tiles, UI panels, etc.

## SWF format reference (per spec + Ruffle `render/src/utils.rs:263`)

All three formats produce 4-byte RGBA per pixel in the existing
`bitmap_data` stream — only the input layout changes.

### Format 3 — ColorMap8
- Header before zlib data: `BitmapColorTableSize` (UI8, `num_colors - 1`).
- After zlib decompress:
  - Palette: `num_colors` entries × 3 bytes (RGB) for Lossless1, × 4 bytes
    (RGBA) for Lossless2.
  - Pixel data: 1 byte per pixel (index into palette), rows padded to a
    multiple of 4 bytes.
- Out-of-range indices: transparent (Lossless2) or black (Lossless1).

### Format 4 — Rgb15 (Lossless1 only)
- No extra header — zlib data is just pixels.
- Each pixel: 1 big-endian u16 = `1 pad + 5 R + 5 G + 5 B`.
- Rows padded to a multiple of 4 bytes (i.e. even pixel count).
- 5→8 bit channel scaling: `(c * 255 + 15) / 31`.
- Format 4 is **invalid** in DefineBitsLossless2 (Ruffle errors; we should
  warn + emit transparent bitmap).

### Format 5 (existing)
- Lossless1: PIX24 `[pad, R, G, B]` → emit `R, G, B, 0xFF`.
- Lossless2: PIX32 `[A, R, G, B]` → emit `R, G, B, A`.
- No header before zlib; uncompressed size known to be `w*h*4`.

## Approach

Inline in each of the two existing case handlers (`SWF_TAG_DEFINE_BITS_LOSSLESS`,
`SWF_TAG_DEFINE_BITS_LOSSLESS2`). Format-5 stays as the fast path; replace
each `if (bitmap_format != 5) EXC_ARG(...)` with a switch over `bitmap_format`
that calls the appropriate decode-to-RGBA loop. **No helper function** —
the two call sites are already paste-duplicated and a third extraction would
add abstraction without removing duplication. If we ever add tests for these
formats and want to share decode logic with a unit test, extract then.

Output format stays identical: the existing `bitmap_data` ostringstream
gets one hex-formatted `R,G,B,A` block per pixel via the same loop as today,
just fed from the format-specific decoder's output buffer.

Buffer sizing: today's `w*h*4` allocation is correct for format 5 but
**wrong** for formats 3 and 4 (palette + indexed data, or 2 bytes per pixel
before scaling). Replace the fixed `uLongf uncompressed_size = w*h*4` with
a format-specific upper bound, or use a growing buffer pattern. Simplest:
compute the exact expected uncompressed size per format and allocate that.

## Verification

1. Recompile Art_of_War, Avalanche, Bloons, Bloons_TD. The
   "format 3 not yet supported" warnings should disappear; tag-fail count
   for those SWFs should drop.
2. Spot-check `bitmap_data` byte count for one decoded bitmap: should be
   `4 * w * h` per call to `defineBitmap`. Easy to compare against the
   `defineBitmap(..., w, h, char_id)` arg list emitted into `tag_init`.
3. Build Art_of_War to wasm (already works since `8d2a22d6`) and load
   the demo in a browser; bitmaps should now render instead of being
   missing. (Without running, "decoded N bytes" is the best we can verify.)
4. Re-run a few Ruffle tests that exercise bitmaps (`bitmapData_loadBitmap`
   or similar if any exist) for non-regression of format 5.

## Risks / things to be careful about

- **Row padding**: easy to forget. Both format 3 and format 4 pad rows to a
  multiple of 4 bytes. Skip the pad bytes between rows; don't read them as
  pixels. Off-by-one here silently corrupts every row after the first.
- **`num_colors == 256`**: `BitmapColorTableSize` is `num_colors - 1`, so a
  full 256-entry palette is stored as `0xFF`. Use `num_colors = ColorTableSize + 1`,
  not `ColorTableSize`. Easy to invert.
- **Allocation size**: zlib `uncompress` writes exactly the expected
  uncompressed size on success. If we pass the wrong `uncompressed_size`
  arg, we either truncate or overflow. Compute it per-format.
- **Format 4 in Lossless2**: invalid per spec. Warn + fill transparent;
  don't throw, since `clear()` (per `9a9522e8`) shouldn't have to mop up
  the same kind of stream-state breakage again. (Note: with the
  `clear()` fix in place, throwing is also recoverable now; staying
  lenient is a style choice for "be tolerant of weird SWFs.")
- **Endian**: format 4 u16 pixels are **big-endian** (`u16::from_be_bytes`
  in Ruffle). The existing `VAL(u16, ...)` macro is little-endian. Use
  manual byte assembly `(hi << 8) | lo`.

## Out of scope

- Bitmap caching / lazy decoding (current code emits everything into
  baked C arrays at compile time; the wasm is huge but works).
- The other lossless variants the recompiler doesn't yet handle:
  DefineBitsJPEG2/3 tag failures in Avalanche, JPEGTables ordering in
  Castle_Hero. Different decoders, different planning doc.
- Color-correction / gamma. Ruffle's `(c * 255 + 15) / 31` is what we want.

## Open questions

- Should we add a regression test SWF for format 3? Could be auto-generated
  from MTASC + `swfmill` or hand-crafted. Probably yes — keeps the
  decoder honest across refactors. Could defer until we hit a regression.
- Format 4 is unobserved in flasharchive; should we implement it? Spec
  compliance + future-proofing says yes, even without test coverage.
  Implementation cost is small (~30 lines), so just do it.
