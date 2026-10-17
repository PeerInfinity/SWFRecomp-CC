# s22 wave-2 `w2-atf-dxt5` — Stage3D ATF format 5 (RawCompressedAlpha = raw DXT5) upload

**NEW files:** none (besides this report and `w2-atf-dxt5.patch`). No new `.c`/`.h`, no new fixture dirs.

**Files edited:** `SWFModernRuntime/src/avm2/avm2_stage3d.c`, `SWFModernRuntime/src/avm2/avm2_jpegxr.c`,
`SWFModernRuntime/include/avm2/avm2_jpegxr.h`, `ruffle-tests/render_canary_tests.txt` (one member at EOF).

## Verdict: GO, +1 pixel flip, 0 trace moves

| Ledger | Test | Axis | Before (origin/master `f0f8986ac`) | After (this patch) |
|---|---|---|---|---|
| **flip** | `avm2/stage3d_texture_bytearray_compressed_raw_alpha` | pixel | **fail** — 55079 outliers (limit 66), max diff 178 | **pass** — 0 outliers (limit 66), max diff 3 |
| unchanged | `avm2/stage3d_texture_bytearray_compressed_raw_alpha` | trace | pass | pass |
| unchanged | `avm2/stage3d_texture_bytearray` (ATF fmt 1) | pixel / trace | pass (0/0, max 2) / pass | md5-identical / pass |
| unchanged | `avm2/stage3d_texture_bytearray_compressed_alpha` (ATF fmt 4) | pixel / trace | pass (1/66, max 5) / pass | md5-identical / pass |
| unchanged | `avm2/stage3d_errors_atf` | trace (graphics + no-graphics) | pass | pass |

### EXPECTED-FLIP LEDGER (for CI grading)

- **Pixel axis:** `avm2/stage3d_texture_bytearray_compressed_raw_alpha` fail → pass. Nothing else.
- **Trace axis:** none (the headline row already passes trace; no trace output depends on texel contents).

Note for the grader: `stage3d_texture_bytearray` and `_compressed_alpha` were CI pixel FAILS on the
last images run (`36515003936`, 09-29), but `w2-jpegxr` (`5dee7a4b4`, already on master) flipped them;
they pass locally on clean master and are md5-unchanged by this patch. Book them to w2-jpegxr, not here.

## Fidelity (cloud ↔ CI)

My clean-master *before* render of the headline row is **byte-identical** to CI's actual PNG on
`origin/ruffle-image-results` (`images/avm2/stage3d_texture_bytearray_compressed_raw_alpha/output.actual.png`):
md5 `075a3e4ebf42fb78e99b7d8f65d8ada1` both. So the absolute *after* grade against the golden
(0 / 66 outliers, max diff 3, md5 `021f1b867600f4e43a0934a510526db4`) is CI-grade.

## Mechanism

- ATF header (both `.atf` files): `ATF 00 00 00 FF`, version 3, u32 length; tdata `0x05` = format 5,
  log2 w/h 9/9, 10 mips; first record u32be length `0x40000` = (512/4)² × 16 = one mip-0 DXT5 table.
- Ruffle (`45366370e`, unchanged up to upstream master `653ef4f41` for every file involved):
  `render/src/atf.rs:143-161` reads four records per face/mip (dxt5, pvrtc, etc1, etc2);
  `core/src/avm2/globals/flash/display3D/textures/atf_jpegxr.rs:146-163` uploads face 0 / mip 0's
  `dxt5` record as-is into the texture (wgpu `Bc3RgbaUnorm`). (The brief cited
  `/root/ruffle/render/src/atf_jpegxr.rs`; the file lives under `core/…/textures/`.)
- Before: `texture_upload_compressed` (`avm2_stage3d.c`) only called the JPEG-XR path, whose
  `avm2_atf_jxr_decode` returns 0 for format 5 → texture stayed zero (blank quads).
- Fix: `s3d_upload_atf_raw_dxt5` (`avm2_stage3d.c`, new static, right after `s3d_upload_atf_jxr`) walks
  the header (legacy u24 or extended u32 lengths, as Ruffle's `read_len`), takes the first record,
  requires exactly (w/4)·(h/4)·16 bytes, and decodes each block straight into the RGBA8 texel store.
  Called first in `texture_upload_compressed`; it returns 0 for any non-5 format so formats 1/4 still
  reach `s3d_upload_atf_jxr` exactly as before.
- The BC3 decoder already existed in `avm2_jpegxr.c` (written by w2-jpegxr for format 4) but sat inside
  `#ifdef SWF_HAVE_LIBJXR`. I moved it **above** the ifdef unchanged and exported it as
  `avm2_bc3_decode_block` (declared in `avm2_jpegxr.h`); format 4 now calls the exported name. Format 5
  needs no jxrlib, so it decodes in no-graphics/WASM builds too (`avm2_jpegxr.c` is always compiled:
  CMakeLists:138, verify_output.py:2572). No duplicate decoder.

### Rounding rule (asked by the brief)

Kept Mesa `util_format` s3tc (`texcompress_s3tc_tmp.h`) rounding: 565 endpoints bit-replicated to 8 bits,
colour thirds `(2a+b)/3` and alpha sevenths/fifths `(…)/7`, `(…)/5` by **truncating** integer division,
BC3 colour always four-colour mode. Why: (1) it is Mesa's own CPU s3tc decode (I did not verify which
path lavapipe's sampler takes for BC3, so treat this as "Mesa-family", not "proven lavapipe-exact"); (2) it is already the rule the format-4 path uses, so
both ATF DXT paths share one decoder. Measured: an A/B with *rounded* division (`+1)/3`, `+3)/7`) also
grades 0/66 outliers, max diff 3 — at tol 4 the choice is immaterial for this row, so the shared,
Mesa-faithful rule wins. (Both rules leave the same max diff 3, so the residual is not in the palette rounding; not chased.)

## Canary (render_canary.py, md5 bar)

Set: the standing `render_canary_tests.txt` (77 members) **plus every `stage3d_*` image test** (avm2
`stage3d_*` with `[image_comparisons]` + the `stage3d/` category) = 97 tests / 152 PNGs, deduped.
`before` = clean origin/master, `after` = patch.

```
IDENTICAL 151   DIFFERS 1   APPEARED 0   VANISHED 0   NO_RENDER 0
DIFFERS: avm2/stage3d_texture_bytearray_compressed_raw_alpha  output  image fail -> pass, trace pass -> pass
TRACE STATUS CHANGES: (none)
```

Only the ledger row moved. Standing-set addition: `avm2/stage3d_texture_bytearray_compressed_raw_alpha`
appended at EOF (tier 1) — the set had no ATF-format-5 / jxrlib-free BC3 member.

## Regression suite / mode parity

- `regression/` has no Stage3D fixture; ran nearest neighbours in graphics mode:
  `avm2_embed_bytearray` PASS, `avm2_graphics_runtime` PASS (image SKIP, no golden); the 6 `regression/`
  canary members are md5-identical.
- No-graphics (`swf_core` build, no libjxr define): `stage3d_texture_bytearray_compressed_raw_alpha`,
  `stage3d_texture_bytearray_compressed_alpha`, `stage3d_errors_atf` all PASS (trace); the move of
  `avm2_bc3_decode_block` out of the ifdef compiles and links in that build.
- No `#ifdef NO_GRAPHICS` arms, `swf_core.c` or `tag_stubs.c` touched; no recompiler change.
- No new regression fixture: the behaviour has a corpus test (the headline row), and an extra
  format-5 fixture (legacy u24 header, cube) would need an outside oracle (see below).

Upstream: `download_tests.sh` pulled ruffle master `653ef4f41` (2026-10-17); `git log 45366370e..653ef4f41`
touches none of the headline test files, `render/src/atf.rs` or `core/…/display3D/` — no drift.

## Not done / limits

- Only face 0 / mip 0 is decoded, as in Ruffle; cube ATF-5 uploads land in layer 0 (Ruffle does the same).
- pvrtc/etc1/etc2 records are ignored (Ruffle ignores them too; empty dxt5 → Ruffle stubs, we leave the
  texture untouched because the size check fails).

## New unclaimed leads

none.

## LOCAL ORACLE REQUESTS

none (optional: a Ruffle exporter render of a legacy-header (version 0, u24 lengths) format-5 ATF cube
upload would let a `regression/` fixture pin the u24 branch of `s3d_upload_atf_raw_dxt5`; low value).
