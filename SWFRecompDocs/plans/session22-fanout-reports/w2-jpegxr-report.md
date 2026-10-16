# w2-jpegxr — JPEG-XR decode (jxrlib): Loader `.jxr` + Stage3D ATF formats 1 / 4

**Verdict: GO, +4 pixel flips measured (all four ledger rows pass locally at CI-grade fidelity), 0 trace moves, canary md5-clean outside the ledger.**

## New files

- `SWFModernRuntime/src/avm2/avm2_jpegxr.c` — the ONLY translation unit that includes jxrlib headers. Stubs (return 0) without `SWF_HAVE_LIBJXR`.
- `SWFModernRuntime/include/avm2/avm2_jpegxr.h` — two entry points: `avm2_jxr_decode_rgba`, `avm2_atf_jxr_decode`.
- `SWFRecompDocs/plans/session22-fanout-reports/w2-jpegxr.patch` — the deliverable patch.
- `SWFRecompDocs/plans/session22-fanout-reports/w2-jpegxr-report.md` — this report.

No new fixture dirs. The four corpus rows cover the new behaviour, and their goldens come from outside SWFRecomp (Ruffle).

Patch = `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`. It was generated after the final edit and checked with `git apply --check -R`.

## Environment

- `pkg-config --modversion libjxr liblzma` = `1.2` / `5.4.5`. SETUP_STATUS: apt / Pillow / Dawn all OK.
- Upstream test corpus: `download_tests.sh` at session time (upstream master). My blobless Ruffle clone from the same minute is at `45366370e`, the coordinator's sync point.
- Ruffle's `jpegxr` crate was read at the pinned rev `86cc1749`. The `image` crate was read at `0.25.10` and the `tiff` crate at `0.11.3`, all from `Cargo.lock`.

## EXPECTED-FLIP LEDGER (coordinator: check CI against this)

| test | axis | before → after | notes |
|---|---|---|---|
| `avm2/loader_jpegxr` | pixel | fail → **pass** | tol 1 / 0 |
| `avm2/loader_jpegxr_alpha` | pixel | fail → **pass** | tol 48 / 1500 |
| `avm2/stage3d_texture_bytearray` | pixel | fail → **pass** | tol 4 / 0 |
| `avm2/stage3d_texture_bytearray_compressed_alpha` | pixel | fail → **pass** | tol 4 / 66 |
| all four rows above | trace | pass → pass | no trace move |

**Every other row must be md5-identical.** That includes `avm2/stage3d_texture_bytearray_compressed_raw_alpha`, which is ATF format 5 and belongs to sibling `w2-atf-dxt5`. My decode returns 0 for format 5, so I do not touch that row.

**CI precondition:** the CI box must have `libjxr-dev` (and `liblzma-dev`) installed. `verify_output.py` probes for it with pkg-config. If it is absent, the code compiles to the stub and all four rows fall back to their old blank renders: no crash, and no trace change.

## Per-test before / after (same cloud box, `--mode=graphics`; outliers / limit, max diff)

| test | before (clean origin/master) | after (this patch) | budget |
|---|---|---|---|
| `avm2/loader_jpegxr` | 136033 / 0, max 204 | **0** / 0, max 1 | tol 1 |
| `avm2/loader_jpegxr_alpha` | 11574 / 1500, max 204 | **0** / 1500, max 1 | tol 48 |
| `avm2/stage3d_texture_bytearray` | 35747 / 0, max 170 | **0** / 0, max 2 | tol 4 |
| `avm2/stage3d_texture_bytearray_compressed_alpha` | 58606 / 66, max 178 | **1** / 66, max 5 | tol 4 |

**Fidelity proof:** for all four rows, my *before* render is md5-identical to CI's actual PNG on `origin/ruffle-image-results`:

| test | md5 (CI actual = mine before) |
|---|---|
| `loader_jpegxr` | `920c8444…` |
| `loader_jpegxr_alpha` | `28b7a6f3…` |
| `stage3d_texture_bytearray` | `b7bcf4ee…` |
| `stage3d_texture_bytearray_compressed_alpha` | `075a3e4e…` |

So local absolute grading is CI-grade for these rows.

**Bit-exactness against the goldens:** max diff is 1–2 on three rows and 5 on the format-4 row. On the format-4 row, the one remaining outlier channel is BC3 rounding (see below). The jxrlib decode is effectively identical to Ruffle's.

## Mechanism

### `avm2_jpegxr.c` (new)

**`avm2_jxr_decode_rgba`** reproduces Ruffle's `ImageDecode::convert_to_tiff` followed by `image::to_rgba8`, call for call:

1. Open the decoder: `PKImageDecode_Create_WMP` + `Initialize` on a `CreateWS_Memory` stream.
2. Set `uAlphaMode = 2`.
3. Pick the target format: `PixelFormatLookup` with `LOOKUP_FORWARD`, then `LOOKUP_BACKWARD_TIF`.
4. Convert with a `PKFormatConverter` (`".tiff"`), copying with `PKImageEncode_Transcode`'s common stride.
5. Skip the TIFF round trip. The TIF writer stores rows verbatim, and neither the `image` crate nor the `tiff` crate associates or dissociates alpha.
6. Expand Gray / RGB / RGBA rows at 8 or 16 bits per sample to RGBA8. For 16-bit samples this uses `image`'s rule `(c + 128) / 257`.

`logo.jxr`, written by ImageMagick, is 64bppRGBA, so the 16-bit arm is required. `gradient.jxr` files are 24bppRGB and 32bppBGRA.

**`avm2_atf_jxr_decode`** follows `render/src/atf.rs` and reads face 0 / mip 0 only, as Ruffle does:
- Format 0/1: one JPEG-XR record, decoded with the RGBA path above.
- Format 4 (CompressedAlpha): the reconstruction in `core/.../display3D/textures/atf_jpegxr.rs:49-144`:
  - Each LZMA record gets an 8-byte unknown-size field spliced in, then goes through the xz "alone" decoder. The output size is known exactly: blocks×6 for the DXT1 alpha tables, blocks×4 for the DXT5 colour tables.
  - The alpha endpoint plane comes from the TIFF path (gray). The BGR565 endpoint plane comes from `copy_all`, i.e. raw source format.
  - 16-byte BC3 blocks are rebuilt and then decoded to RGBA (the texel store is RGBA, there is no GPU BC3 texture).

**Ruffle quirk replicated (deliberately):** `atf_jpegxr.rs:107` reads the *second* alpha endpoint at BYTE offset `second_half + 4i` of the RGBA-expanded plane. That is pixel `second_half/4 + i`, not `second_half + i`.
- The BGR plane is indexed correctly in pixels.
- The quirk produces visible ghosted alpha edges on the Ruffle logo.
- The golden `output.expected.png` shows the same ghosting, so it is Ruffle's render. I follow Ruffle byte for byte; the "correct" indexing would not match.
- Disposition note: this is Ruffle-specific behaviour. If the coordinator wants it on record, it belongs in `RUFFLE_COMPAT_TWEAKS.md` (avm2 has no such file today).

**BC3 decode rounding:** I use Mesa `util_format` s3tc (`texcompress_s3tc_tmp.h`):
- 565 endpoints are expanded to 8 bits by bit replication.
- Colour thirds are `(2a+b)/3` and alpha sevenths/fifths are `(a·(8−c)+b·(c−1))/7`, both by truncating division.
- BC3 colour always uses the 4-colour mode.
- Result: 1 outlier channel, max 5, against a budget of tol 4 / 66.

### `avm2_bitmap.c`

- New static `bitmap_from_jpegxr`, reached from the top of `avm2_bitmap_from_image_bytes` when the input sniffs as `II\xBC\x01`.
- The bitmap is always transparent, and pixels are premultiplied with the same truncating rule as the PNG/GIF path.
- **Refuted along the way:** a literal reading of Ruffle (`decode_jpegxr` produces straight RGBA, labelled `BitmapFormat::Rgba` = "premultiplied", then `as_colors` copies it unchanged) suggests storing the pixels un-premultiplied. I tried that: 4191 outliers, because the translucent rows composite additively.
- The golden is the straight-alpha composite of the *jxrlib-decoded* values. At (5,30) the decoded pixel is 250,72,0 @127; over 0xCC that gives 226,137,102, which matches the golden. The source PNG's red of 255 would give 229. With premultiply: 0 outliers, max 1.

### `avm2_display.c` (one condition)

- `is_image` in the loader-complete path now includes `LI_CT_JPEGXR`.
- The old comment saying JPEG-XR "deliberately gets no decode attempt" is replaced.
- Without libjxr the decode returns NULL, so `content` stays null as before. That is all `loader_jpegxr`'s trace grades (`image/jpegxr`).

### `avm2_stage3d.c`

- New static `s3d_upload_atf_jxr`, called once at the end of `texture_upload_compressed`, after the #3679 / #3675 checks.
- It writes face 0 into layer 0, matching Ruffle's `copy_pixels_to_texture(…, 0)`. Like Ruffle, it ignores the texture's declared format.

### Build plumbing

- `verify_output.py`: `src/avm2/avm2_jpegxr.c` is added to `AVM2_CORE_SOURCES`, which is shared by the native and WASM compiles. The existing graphics-mode probe already defines `SWF_HAVE_LIBJXR` and adds the `.pc` flags.
- `CMakeLists.txt`: new `WITH_LIBJXR` option mirroring `WITH_LIBAVCODEC` (ON for native graphics, OFF for NO_GRAPHICS and Emscripten). When ON it adds the TU, `-DSWF_HAVE_LIBJXR` and `PkgConfig::LIBJXR`. LZMA comes from the vendored xz `lzma` target, whose `lzma.h` is already on the include path.
  - Verified: `cmake -DNO_GRAPHICS=ON -DWITH_LIBJXR=ON` configures and compiles `avm2_jpegxr.c.o`.
  - Caveat, not from this patch: the whole CMake runtime build already fails on origin/master because `action.c` can't find `tesselator.h`. CMake has never built `src/avm2`, so only my TU is wired in there.
- Emscripten: `wasm_wrappers/bundle/build.sh` and `scripts/deploy_wasm_demo.sh` copy `src/avm2/*.c` by glob, so the new TU is picked up automatically. It compiles as the stub because nothing defines `SWF_HAVE_LIBJXR` there.
- The stub build compiles warning-free with `-Wall -Wextra`. The no-graphics run of the four rows (no `SWF_HAVE_LIBJXR`) passed: 4/4 trace pass.

## Regression suite and canary

**Render canary** (`render_canary.py` capture/compare, 88 tests / 130 PNGs, before = clean origin/master, after = this patch, same box):
- Members: the full standing `render_canary_tests.txt` (60) plus every `avm2/stage3d_*` and `avm2/loader_*` row that has `[image_comparisons]` (27) plus `stage3d/{sampler_odd_size, scissor_rectangle, scissor_rectangle_invalid, unbound_texture, unbound_texture_multiple}`.
- **126 IDENTICAL, 4 DIFFERS.** The 4 are exactly the ledger rows, all image fail→pass.
- Trace status changes: none. Appeared / vanished / no-render: 0.

**Canary set update:** no standing member reached either path, so I appended three members at EOF, all Tier 2 until graded:
- `avm2/loader_jpegxr_alpha`
- `avm2/stage3d_texture_bytearray_compressed_alpha`
- `avm2/stage3d_texture_bytearray`

The comment block next to them warns that an A/B move on these rows can also mean libjxr went missing from the box, not a code regression.

**Regression suite** (graphics): `avm2_loader_stub`, `avm2_embed_bytearray`, `avm2_bitmapdata_draw_textfield` — all PASS.

**Mode parity:** I touched no `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arms. I ran the four headline rows without graphics anyway: all pass.

## Merge with sibling `w2-atf-dxt5` (both edit `texture_upload_compressed`)

- **My only edits in `avm2_stage3d.c`:**
  - the `#include <avm2/avm2_jpegxr.h>` line;
  - the new static `s3d_upload_atf_jxr`, placed directly above `texture_upload_compressed`;
  - one call line, `s3d_upload_atf_jxr(ctx, te, ba->bytes + offset, ba->len - offset);`, just before the final `return avm2_undefined();` of `texture_upload_compressed`.
- **The two hooks are independent:** `avm2_atf_jxr_decode` returns 0 (no texel write) for any format other than 0/1/4. So the sibling's format-5 call and mine can sit side by side in either order. If they collide textually on that line, keep both calls.
- **Their brief says `stage3d_texture_bytearray` and `_compressed_alpha` "must not change."** That holds for their patch alone. After both patches land, those two rows are expected to move: they are in MY ledger.
- **Dedup opportunity, not required:** both slots carry a CPU BC3 decoder. Mine is `static bc3_decode_block` inside `avm2_jpegxr.c`, deliberately kept TU-local because that file is built only as a stub without libjxr. If the coordinator wants one decoder:
  - Keep the sibling's decoder (it is always compiled, which format 5 needs) and expose it.
  - Then call it from `atf_compressed_alpha` in place of mine. Both follow Mesa rounding as long as the sibling chose Mesa; check their report's rounding rule.
  - If the rules differ, re-run `stage3d_texture_bytearray_compressed_alpha` (my margin: 1/66 channels, max 5 at tol 4).

## Not finished / holds

- Nothing in scope is left open.
- Cube textures: Ruffle decodes face 0 only, and so do I. No corpus row grades JPEG-XR cube faces.
- Mip levels > 0 are ignored, as in Ruffle.

## New unclaimed leads

- **CMake runtime build is broken on master** (`action.c:10 tesselator.h: No such file`, NO_GRAPHICS configure). Nobody builds through `SWFModernRuntime/CMakeLists.txt` today. It also never lists `src/avm2`. Either retire it or re-sync it with `verify_output.py`'s source lists.
- **Ruffle's format-4 alpha-endpoint indexing bug** (`atf_jpegxr.rs:107`) could be filed upstream. Fixing it there would move the golden, and we would follow.

## LOCAL ORACLE REQUESTS

None.
