# A loaded child movie's bitmaps — status (2026-09-03)

Brief: `SWFRecompDocs/prompts/child-bitmap-registry-prompt.md`.
Baseline: `3fd9b7cc5` (prompt commit `06a039a1a` on top).
Closes the defect the previous slice
(`SWFRecompDocs/status/emission-mode-residuals.md`, §"Residuals of the
residuals") named and deliberately left open: a child SWF's bitmap offsets
indexed the **parent's** `bitmap_data`. Unlike the last four slices this change
is **on by default** — there is no option to turn it off.

## What was actually wrong: TWO defects, stacked

The brief described one. There were two, and the outer one hid the inner one.

### Defect A — `defineBitmap` was missing from the child char-id offset list

`generate_child_movie_file` (`ruffle-tests/verify_output.py`) offsets a child's
character ids by `movie_id * 1000` with **one `re.sub` per emitted call name**
(memory `child-movie-charid-offset-per-callsite`). `defineBitmap` was not in
that list — the same omission that broke `tagDefineSound` until 2026-09-03.

So a child's bitmap registered its metadata under the **raw** char id while
`tagRegisterExport` (offset) published `1001`. `BitmapData.loadBitmap("<child
export>")` resolved the export, then `ng_getBitmapMetadata(1001)` found nothing
and the call returned `undefined`. The wrong-array read was never reached.

### Defect B — the registry recorded *where in an array*, never *which array*

```c
defineBitmap(offset, size, w, h, char_id)          // src/libswf/tag.c
  -> ng_registerBitmapMetadata(char_id, offset, ...)
BitmapData.loadBitmap(name)                        // src/actionmodern/action.c
  -> ng_getBitmapMetadata(char_id, &offset, ...)
  -> GEN_EXTERN_BITMAP_DATA; (u32*)(bitmap_data + offset)
```

`offset` is a byte offset into the **emitting** movie's `bitmap_data`; the
reader dereferenced the root movie's `bitmap_data` global. A child's array is
renamed `<prefix>_bitmap_data` by the child-movie wrapper, so a child's offset
was applied to the parent's pixels.

## The test (the deliverable half)

`ruffle-tests/tests/swfs/regression/avm1_parent_child_bitmap/` — generator,
`Parent.as`, both SWFs, `output.txt`, `test.toml`, per that suite's README.

```
parent test.swf  (AVM1, SWF8, MTASC)   4x4 opaque RED   exported "parentBitmap"
                 loadMovie("child.swf")
child.swf        (AVM1, hand-built)    2x2 opaque BLUE  exported "childBitmap"
```

Each bitmap is the only bitmap in its own movie, so **both sit at offset 0 of
their own array** — the collision that makes a wrong-array read land on real,
in-bounds, deterministic pixels instead of on garbage. The child is 2x2 inside
the parent's 4x4 (16 bytes inside 64), so defect B is a wrong **colour**, not a
crash. `bitmap_data` holds R,G,B,A per pixel and `getPixel` returns `0xRRGGBB`:
red = 16711680, blue = 255.

Two lines per bitmap separate the two registries: `csz:` comes from the
metadata entry (char id → w/h), `cpx:` from the pixel array. A future half-fix
that repairs one and not the other stays visible.

The parent's bitmap is **spliced into MTASC's output** (a plain tag-stream
rewrite in `create_test_swf.py`) because MTASC has no asset-embedding syntax.
The parent row is the control and must keep working; only the `c` rows move.

| | `cpx:` | `csz:` |
|---|---|---|
| `master` (both defects) | `none` | `none` |
| defect A fixed only | **`16711680`** — the PARENT's red | `2x2` |
| both fixed (this commit) | `255` | `2x2` |

All three rows were produced locally. The middle row was forced by temporarily
making `defineBitmap` ignore its new base and use the ambient `bitmap_data`
global — i.e. defect B in isolation, with defect A already fixed. That is the
evidence that the registry change is load-bearing and not just a by-product of
the char-id fix. Both end states verified in `no-graphics` **and**
`--mode=graphics`.

## The fix

**The base travels with the offset, from the TU that owns the array.**

1. **Emission** (`SWFRecomp/src/swf.cpp`, 5 sites — DefineBits, JPEG2, JPEG3/4,
   Lossless, Lossless2): `defineBitmap(bitmap_data, offset, size, w, h,
   char_id)`. `bitmap_data` resolves in `tagMain.c` via its existing
   `#include "draws.h"`, and — this is the point — the child-movie wrapper's
   existing `apply_renames` rewrites it to `<prefix>_bitmap_data` with no new
   machinery, exactly as it already does for `sound_data + N`. The array was
   always emitted into the wrapper; nothing referenced it.
2. **Registry** (`tag.c`, `tag.h`): the entry stores `const u8* pixels` — an
   absolute pointer with the defining movie's base already folded in — instead
   of a bare `size_t offset`. `ng_registerBitmapMetadata` /
   `ng_getBitmapMetadata` change shape accordingly (one caller each).
3. **Reader** (`action.c` `bitmapDataLoadBitmap`): uses that pointer;
   `GEN_EXTERN_BITMAP_DATA` is gone from this function.
4. **Harness** (`verify_output.py`): `defineBitmap` added to the char-id offset
   list. It is the only emitted define whose char id is **last**, so it needed
   its own regex shape rather than the usual `(app_context,\s*)(\d+)`.

The registry half is universal — it holds for any embedder. The char-id half is
`verify_output.py`-specific; `docs/recompiler`'s in-page pipeline recompiles one
root movie and has no child numbering to get wrong (see the last bullet of
`emission-mode-residuals.md`).

## The render path — checked, and it is a different animal

`defineBitmap` also calls `renderer_upload_bitmap(context, offset, size, w, h)`,
which stored the offset in `ctx->bitmap_offsets[i]` and later read
`ctx->bitmap_data + ctx->bitmap_offsets[i]` — `ctx->bitmap_data` being
`app_context.bitmap_data`, i.e. **the root movie's array**
(`SWFRecomp/wasm_wrappers/main.c`). Structurally the same ambiguity.

**But a child's bitmaps never reach it**, for two independent reasons, both
verified in the source:

- `render_webgpu_upload_bitmap` returns early on `ctx->bitmap_static_built`,
  and `finalizeBitmaps()` is emitted at the end of the **root** movie's
  `tagInit`. A child's `tagInit` runs later, from the AVM1 loader.
- The slot table is sized by the root's `BITMAP_COUNT`
  (`ctx->current_bitmap >= ctx->bitmap_count` → return), so even before
  finalize there is no slot for a child's bitmap.

So the render symptom is **"a loaded child's bitmaps do not render at all"**,
not "they render the wrong pixels" — a missing feature, not a corrupt read. It
is out of this slice's scope and is recorded below.

The ambiguity is closed at the source anyway: `renderer_upload_bitmap` now takes
`const u8* pixels` and `ctx->bitmap_offsets` became `ctx->bitmap_ptrs`
(`const u8**`), so if the two gates above are ever lifted the slot table cannot
inherit the bug. For the root movie the stored pointer is byte-for-byte
`bitmap_data + offset`, so nothing about today's rendering changes.

**One real bug fixed in passing.** `flashbang_upload_bitmap` (the SDL3 backend,
not the one CI grades) ignored `offset` entirely and read
`((u32*)context->bitmap_data)[bitmap_pixel]` — the start of the array — so
**every bitmap after the first uploaded the first one's pixels**. Taking the
pointer fixes that as a side effect. Not exercised by any test we run; noted
here so it is not rediscovered as a regression.

## Audit: the other char-id call sites

The brief asked whether any other bitmap-adjacent call is half-applied. Bitmaps
have exactly one emitted call (`defineBitmap`); `tagSetCacheAsBitmap` is
depth-keyed, and shape bitmap FILLS carry a compile-time bitmap **index**
(`char_id_to_bitmap_id`), not a char id. So bitmap-adjacent is now clean.

Widening the same check to the whole offset list found something worth its own
slice. **Four of the list's regexes are dead** — the call name they match is
never emitted by today's recompiler:

| dead regex | what is actually emitted |
|---|---|
| `tagDefineEditText(` | `tagDefineEditTextProps(` |
| `tagDefineFont(` | `tagDefineFontGlyphBase/Info/Metrics(` |
| `tagDefineSoundMeta(` | `tagDefineSound(` (added 2026-09-03) |
| `tagDefineVideoMeta(` | `tagDefineVideoStream(` |

and these **live** calls carry a character / font / sprite id and are **not**
offset, while `tagDefineSprite`, `tagRegisterExport` and `tagPlaceObject2*`
are:

- `tagSetSpritePlacements`, `tagSetSpriteFrameCounts`, `tagSetSpriteLabels`,
  `tagSetSpriteNoEndTag` — sprite ids that must agree with the **offset**
  `tagDefineSprite`. This quartet is half-applied **today**.
- `tagDoInitActionGuarded(app_context, char_id, ...)`
- `tagPlaceObject3`, `tagReplaceObject2RatioWithClipActions` — the
  `tagPlaceObject2\w*` regex matches neither name.
- `tagDefineEditTextProps`, `tagDefineText`, `tagCSMTextSettings`
- `tagDefineFontGlyphBase`, `tagDefineFontInfo`, `tagDefineFontMetrics`
- `tagDefineVideoStream`, `tagVideoFrame`
- `tagImportCharacter`
- `tagDefineButton`'s **4th** argument, `hit_char_id` (only the 2nd is offset).

`tagRemoveObject`, `tagRemoveObject2`, `tagSetInstanceName`,
`tagSetCacheAsBitmap`, `tagSetClipActions`, `tagSetFilter*`,
`tagSetOpaqueBackground` and the filter calls are depth-keyed and correctly
absent.

Deliberately **not** fixed here. Each is a behaviour change for loaded children
with no test in front of it, and this slice's own lesson is that the failing
test is what makes such a change safe: moving a define without its consumers is
how the sound pair broke. The inventory is the deliverable; the next slice
should take it a pair at a time, sprite metadata first (it is the one that is
provably inconsistent rather than merely uniformly raw).

## Verification

1. **The test flips.** `output_mismatch` at `06a039a1a`, `pass` after — shown
   above, both modes, all three states.
2. **`gcc -fsyntax-only -std=c17 -Wall -Werror=return-type`** over the generated
   `movie_child.c` / `tagMain.c` / `draws.c` / `constants.c` of the new test:
   no errors, and only the pre-existing `-Wmissing-braces` on the transform
   arrays plus the pre-existing `MAX_STRING_ID` redefinition note.
   (`verify_output.py` compiles with `-w` and would not have shown either.)
3. **Local sweep**, `--mode=graphics`: `avm1/{bitmap_data_colortransform,
   bitmap_data_thorough, do_init_action_child, cross_movie_root,
   depth_replacement_audio_unloading}`, `avm2/{bitmap_data, bitmapdata_embedded,
   graphics_bitmap_fill}`, `from_gnash/{BitmapData-v8, LoadBitmapTest}`,
   `from_shumway/acid/acid-bitmap-fill-2`,
   `visual/{define_bits_lossless2_rgb15, define_bits_jpeg2_huge,
   bitmapdata_copypixels_with_alpha_oob}`, `regression/*` (whole suite), and
   `mixed_avm/avm1_loads_avm2`. Results below.
4. **CI**: below.

## CI

(filled in after the run)

## Residuals

- **A loaded child's bitmaps still do not RENDER.** Two gates, both in the root
  movie's terms: `finalizeBitmaps()` fires at the end of the root's `tagInit`,
  and the static slot table is sized by the root's `BITMAP_COUNT`. Fixing it
  means giving the renderer a per-movie static-bitmap range, which is a real
  design change, not a registry tweak. `BitmapData.loadBitmap` — the AS-visible
  path — is fixed and is what the corpus exercises.
- **The char-id offset list is still hand-maintained and now demonstrably
  incomplete** (audit above). It should stop being a list of regexes; the
  emitted calls could carry their ids through one wrapper the harness can key
  on. That is the shape of the real fix, and it is bigger than any one slice.
