## DefineBits JPEG Robustness (mid-stream EOI+SOI, empty JPEGTables, PNG/GIF, trailing EOI)

**Status:** Planning — 2026-05-16

## Context

`SWFRecomp/src/swf.cpp` decodes JPEG bitmap tags via `stb_image`:

- `SWF_TAG_DEFINE_BITS` (6) — JPEG image data glued to a separate JPEGTables tag.
- `SWF_TAG_DEFINE_BITS_JPEG2` (21) — self-contained JPEG (or PNG/GIF in SWF8+).
- `SWF_TAG_DEFINE_BITS_JPEG3` (35) — self-contained JPEG + separate zlib alpha.
- `SWF_TAG_DEFINE_BITS_JPEG4` (90) — JPEG3 plus a 2-byte deblock-filter param.
- `SWF_TAG_JPEG_TABLES` (8) — encoding-table prelude shared by DefineBits.

Per-tag `try { … } catch (std::exception&) { … clear(); }` (since `9a9522e8`)
keeps a single tag failure from truncating the recompile, but every
failed tag's bitmap is missing from the runtime output — appearing as
a transparent placeholder where art was meant to be.

Observed failures (in `local_batch/`):

- **Avalanche** (SWF v8): 2× `JPEG3 data returned NULL`, 1× `JPEG2 data
  returned NULL`. Extracted bytes pass Pillow but fail stbi with
  `"unknown marker"`. The cause is a spurious `FF D9 FF D8` (EOI+SOI)
  sequence at offset **572**, *mid-stream*, between DQT/DHT tables and
  the JFIF APP0/SOF0 markers. Our handler only strips this when it is
  the leading 4 bytes; Ruffle splices it from anywhere before SOF0.
- **Castle_Hero** (SWF v9): a single `SWF_TAG_JPEG_TABLES` tag with
  **length = 0** triggers `new u8[new_length - 2]` (size_t underflow)
  → `std::bad_alloc`. The exception escapes the per-tag catch (or kills
  `parseAllTags` outright — log shows `Caught exception in parseAllTags:
  std::bad_alloc`). All 11 subsequent `DefineBits` tags then hit
  `EXC("JPEG bitmap tag encountered before JPEGTables!\n")` and fail —
  but each of those DefineBits payloads is a *complete self-contained
  JFIF JPEG* that doesn't need tables at all. Ruffle's
  `glue_tables_to_jpeg` already returns `jpeg_data` as-is when tables
  are missing or `< 2 bytes`.

## SWF format reference (per Ruffle `render/src/utils.rs:20-156`)

### Format detection (DefineBitsJPEG2/3/4 only)

SWF8+ allows non-JPEG image data in these tags. Detect by magic bytes:

```
FF D8 ..              → JPEG (normal SOI)
FF D9 FF D8 ..        → JPEG (erroneous EOI+SOI header, common pre-v8)
89 50 4E 47 0D 0A 1A 0A → PNG
47 49 46 38 37/39 61  → GIF (87a / 89a)
```

If JPEG3/4 alpha data accompanies non-JPEG content, ignore it (Ruffle
warns and ignores). PNG/GIF carry their own alpha.

### `remove_invalid_jpeg_data` (JPEGs only)

The spurious `FF D9 FF D8` can appear *anywhere* before the `FF C0`
SOF0 marker (Ruffle issue #8775; relic of internally-glued
JPEGTables+DefineBits being copied into JPEG2/3 data). Walk JPEG
markers and splice the first occurrence out:

- Markers without a length payload: `D0-D7` (RST), `D8` (SOI), `D9` (EOI).
- All other markers: length follows as `[FF mm len_hi len_lo]`,
  `payload_len = (len_hi << 8) | len_lo` (length includes its own 2
  size bytes; advance by `payload_len + 2` after the marker).
- Stop at `FF C0` (SOF0) — no need to scan into entropy-coded data.
- If a marker that should start with `FF` doesn't, bail (return
  data as-is — it's either not a JPEG or our parsing got lost).

### Trailing EOI safety net

If JPEG data doesn't end with `FF D9`, append it. Optimizers sometimes
strip the final EOI; Flash and Pillow tolerate it but stbi may not.

### `glue_tables_to_jpeg`

```
if jpeg_tables.len() >= 2:
    full = jpeg_tables[..-2] + jpeg_data[2..]    # drop EOI from tables, SOI from data
else:
    full = jpeg_data                              # nothing to glue
```

## Approach

Inline in the existing case handlers — no new helper functions on the
first pass. (Per the format-3/4 plan's pattern: extract later if a
unit test wants to share decode logic.)

1. **`remove_invalid_jpeg_data` walker** — add a small static helper
   `strip_invalid_jpeg_markers(u8* data, size_t& len)` near the JPEG
   handlers. In-place splice (memmove) the first `FF D9 FF D8` found
   before SOF0; otherwise leave untouched. Returns whether a splice
   happened (for logging). The buffer is already heap-owned (`new u8[]`
   in DEFINE_BITS, `cur_pos`-based in JPEG2/3/4 — for the latter, copy
   to a writable buffer first, since `cur_pos` aliases the SWF body).

   *Off-by-one trap:* the EOI+SOI sequence at offset 0 of stripped
   tables, then again mid-stream, is plausible. Strip the leading 4
   bytes first (current behavior), then run the walker on the rest.

2. **Format detection (JPEG2/3/4 only)** — add `detect_image_format(data,
   len) → {JPEG, PNG, GIF, UNKNOWN}` switch on magic bytes. Dispatch:
   - JPEG → existing path (with #1 applied).
   - PNG/GIF → `stbi_load_from_memory(data, len, &w, &h, &comp, 4)`
     (request RGBA so the alpha channel is preserved for PNG; GIF will
     come back opaque). Skip the JPEG3 alpha glue for non-JPEG content
     (warn). Emit `R,G,B,A` per pixel from the 4-channel decoded buffer.
   - UNKNOWN → existing `EXC` (we did our best).

3. **Trailing-EOI safety net** — after marker stripping, before
   `stbi_load_from_memory`, check the last 2 bytes. If `!= FF D9`,
   reallocate +2 and append. Only on the JPEG path.

4. **Empty / short JPEGTables** — in `SWF_TAG_JPEG_TABLES`:
   - If raw `tag.length < 2` (no room for at least SOI/EOI), set
     `jpeg_tables = nullptr; jpeg_tables_size = 0;` and return —
     don't allocate, don't underflow.
   - If `>= 2` but the leading `FF D9 FF D8` strip would leave
     `new_length < 2`, treat the same (degenerate empty tables).

5. **Lenient DefineBits (no/empty tables)** — in `SWF_TAG_DEFINE_BITS`:
   - Drop the `if (jpeg_tables == nullptr) EXC(...)` throw.
   - If `jpeg_tables == nullptr || jpeg_tables_size < 2`, treat the
     tag payload as a self-contained JPEG: skip the glue, apply #1
     (marker walker) and #3 (trailing EOI), then `stbi_load_from_memory`
     directly. Matches Ruffle's `glue_tables_to_jpeg` fall-through.
   - Otherwise glue as today.

## Verification

1. Recompile **Avalanche**: all 3 `JPEG2/3 data returned NULL` warnings
   gone; `defineBitmap(_, byte_count, w, h, _)` for the 3 affected
   char_ids (38, 42, 148) shows `byte_count == 4*w*h`.
2. Recompile **Castle_Hero**: 11 `tag 6 failed: std::exception` +
   1 `tag 8 failed: std::bad_alloc` + the trailing
   `Caught exception in parseAllTags: std::bad_alloc` all gone.
   The 11 DefineBits char_ids decode via the no-tables path.
3. Recompile **Art_of_War**, **Bloons**, **Bloons_TD**: no regressions
   (these only had the format-3 Lossless issue now fixed; they should
   still cleanly recompile with no JPEG warnings introduced).
4. Ruffle smoke tests: re-run `add2`, `goto_label`, `tell_target_invalid`
   for non-regression. (None of these load bitmaps from JPEG tags,
   but they catch any accidental damage to other tag paths via the
   shared parse loop.)

Out-of-scope confirmation: Castle_Hero also has 8× `tag 83 failed:
std::bad_alloc` (DefineShape4) and other non-JPEG issues — those are
their own problem and not touched by this plan.

## Risks / things to be careful about

- **Walker bounds**: marker length is big-endian and includes its own
  2 size bytes. Off-by-one means we either read past end (segfault on
  short data) or skip a marker. Bail (return as-is) on any malformed
  step rather than asserting.
- **Aliasing**: JPEG2/3/4 currently feed `cur_pos` (the SWF body
  buffer) directly to `stbi_load_from_memory`. The in-place splice
  needs a writable copy — `new u8[len]` + memcpy, then memmove inside.
  Free with `delete[]` (the stbi-allocated decoded buffer is freed
  separately with `stbi_image_free`).
- **JPEG3 alpha length when non-JPEG**: alpha data is sized for
  `w * h`. If the embedded PNG decodes to a different `w/h`, the
  zlib decompress sizing breaks. Skip the alpha decompress entirely
  for non-JPEG content (Ruffle warns and ignores).
- **Trailing EOI append**: must happen *after* marker stripping (in
  case the stripped sequence was the only "EOI"). Don't double-append.
- **JPEGTables count check**: the existing `if (jpeg_tables != nullptr)
  EXC("More than one JPEGTables tag detected.\n");` should stay —
  but skip it if the previous tables ended up empty (`jpeg_tables_size
  == 0`) so a later non-empty tables tag can replace them. Otherwise
  a SWF with `<empty JPEGTables> ... <real JPEGTables>` would still fail.
- **stb_image format coverage**: stb_image handles JPEG/PNG/GIF natively.
  Animated GIF only returns first frame — acceptable, matches Ruffle.
- **Warning hygiene**: when we tolerate something Flash-ish (empty
  tables, mid-stream EOI+SOI, trailing-EOI append, non-JPEG content
  in JPEG2/3), emit a one-line `fprintf(stderr, …)` with the char_id
  and what we did. Helps trace future surprises without spamming.

## Out of scope

- Castle_Hero `tag 83 failed: std::bad_alloc` (DefineShape4). Separate
  decoder, separate plan.
- CMYK / L8 / L16 JPEG pixel-format handling. stb_image handles RGB
  and grayscale (auto-expanded by `desired_channels=3`); CMYK is rare
  in SWFs and we'd see it as a stbi failure. Defer until observed.
- Bitmap caching / lazy decoding (still baked into C arrays at
  recompile time; same as the format-3/4 plan).

## Open questions

- Should we add a regression test SWF that exercises each fix path
  (mid-stream EOI+SOI, empty JPEGTables, embedded PNG)? Auto-generated
  from a Python `swf` writer would be cleanest, but it requires
  authoring SWFs by hand. Defer until we hit a regression — the
  Avalanche / Castle_Hero recompiles serve as the smoke test for now.
- Should `strip_invalid_jpeg_markers` become a real helper used by
  the JPEGTables handler too? Currently JPEGTables only strips a
  *leading* `FF D9 FF D8`, but the same mid-stream defect could exist
  in a JPEGTables tag. No observed instances, but cheap to apply
  symmetrically if the helper is already there. Lean toward yes once
  the helper exists.
