# A loaded child's embedded assets resolved to character 0

**Date:** 2026-09-03 · **Arc:** Multi-SWF (loaded children), slice 4
**Baseline:** `e960a565e` · **Brief:** `SWFRecompDocs/prompts/child-bitmap-pair-prompt.md`
**Predecessor:** `SWFRecompDocs/status/child-placed-clip-uninit.md`

Half A shipped, and turned out to be **three** defects with **two layers each**,
not one six-line loop. Half B is **not shipped**: it is measurably a facet of a
much larger missing feature, and §4.2 of the brief authorises stopping there.
Section "Half B" below says exactly what it needs and what the measurement was.

## 1. Half A, as found and as fixed

The brief (and the predecessor's BACKLOG entry) said: `embedded_bitmap_for_char`
(`avm2_bitmap.c`) scans only `avm2_generated_bitmaps` and never falls through to
`g_child_movies`, unlike `char_info` / `timeline_for_char`; add the same
six-line loop.

That loop is necessary and **not sufficient**. Added alone, the fixture still
printed `child:pix:0x0`. Measured, by reverting one half at a time:

| state | `child:pix` |
|---|---|
| baseline | `0x0` |
| table fall-through only (the brief's fix) | `0x0` |
| class→char-id fall-through only | `0x0` |
| both | `4x3` |

**The layer the brief did not name.** All three embedded-asset constructors key
on `avm2_display_char_for_class(cls)`, which reads `g_symbol_map` — and
`g_symbol_map` is built **once**, at stage build, from the MAIN movie's
`avm2_generated_symbol_classes` (`avm2_display.c:3633`). A class defined by a
Loader-loaded child is not in it, so `char_id` came back **0** and the payload
table was never consulted at all. `avm2_display_child_char_for_class` already
existed for exactly this — it was added for `Font.registerFont` — and matches
by qualified name against the SymbolClass rows of the movie that DEFINES the
class. Only the bitmap/binary/sound constructors were still on the main-movie-
only entry point.

**And it is three tables, not one.** The same two-layer miss sits on every
embedded-asset kind that a child can define. All three are now fixed and all
three are graded:

| asset | site | pre-fix | post-fix |
|---|---|---|---|
| `[Embed]` PNG → `BitmapData` subclass | `avm2_bitmap.c` `bitmapdata_init` :882, `bitmap_init` :3400, `embedded_bitmap_for_char` :757 | `0x0` | `4x3` |
| `[Embed(mimeType="application/octet-stream")]` → `ByteArray` | `avm2_bytearray.c` `ba_native_init` :1354 | `length 0` | `length 9` |
| `[Embed]` MP3 → `Sound` | `avm2_media.c` `sound_ctor` :485, `sound_data_for_char` :457 | `length 0` | `length 1044` |

The ByteArray and Sound instances were found by grepping the remaining
`avm2_display_char_for_class` call sites once the bitmap shape was understood,
and each was reproduced before it was fixed — neither was fixed on the
assumption that symmetry implied a bug.

`avm2_display_char_for_class` is deliberately left as-is for the hot
instantiation path (its comment says so): the child arm only runs on a
main-movie miss, and with no child movies loaded it is two NULL checks.

## 2. The defining-vs-placing ruling

**Defining.** The brief's guess (§2) was right, and it is the opposite of the
transform-table answer the predecessor established.

Why it has to be the defining movie, rather than being merely convenient:

- The thing being looked up is a **payload** — pixels, bytes, samples — and the
  payload physically lives in the tables of the movie whose `DefineBits*` /
  `DefineBinaryData` / `DefineSound` tag carried it. There is no second copy in
  the placing movie to be right about.
- The only key the caller has is a char id obtained from
  `avm2_display_child_char_for_class`, which is itself keyed on **the class's
  own movie** (`avm2_display_movie_for_abc(c->instance_init.file->data)`). Both
  ends of the lookup are therefore already the defining movie; using the placing
  movie would require inventing a placing movie that these call paths do not
  have — `new Pix()` in a child's script has no placing tag at all.
- The transform case differs because a `transform_id` is not a payload, it is an
  **index into a per-movie array**, and the tag that supplies the index is the
  parent's. That is the distinction `swf.h:290` documents on
  `place_transform_data` / `child_transform_data`.

Because ids are re-based by `char_id_base` at emission, an id can match a row in
at most one movie, so the fall-through order is a performance detail, not a
correctness one.

**Canaries confirmed unmoved** (the suite that would break if the placing movie
had been used, per the predecessor): `import_assets` 3/3 —
`avm1_imports_avm1`, `avm1_non_swf_import`, `empty_url` — and
`from_gnash/misc-ming.all/attachImported` + `attachExtImported`, all locally
green after the change.

## 3. Half B: measured, and not shipped

The brief asked for a per-movie static-bitmap range so a child's `defineBitmap`
calls stop being dropped, plus a trace-visible assertion that one reached the
renderer. What the measurement shows is that the range is one of at least four
per-movie tables the renderer does not have, and that a bitmap arriving in the
pool would be unobservable — by trace **or** by pixel — until the others exist.

### The gates, measured

Instrumented `render_webgpu_upload_bitmap` and `finalizeBitmaps` and ran
`regression/avm1_parent_child_bitmap --mode=graphics` (parent: one 4x4 bitmap;
child: one 2x2):

```
PROBE upload_bitmap w=4 h=4 ok=1 built=0 cur=0 cnt=1     <- root
PROBE finalizeBitmaps                                    <- root's tagInit
PROBE upload_bitmap w=2 h=2 ok=1 built=1 cur=1 cnt=1     <- child: DROPPED
PROBE finalizeBitmaps                                    <- child's tagInit
```

Both gates fire, not one: `bitmap_static_built` is already 1 **and**
`current_bitmap >= bitmap_count` (1 >= 1). And every movie's `tagInit` ends with
`finalizeBitmaps()` — the recompiler emits it per movie (`swf.cpp:894`) and the
child wrapper does not strip it, unlike `tagInitSpriteFrameScripts`.

### Why lifting them renders nothing

A static bitmap is only ever sampled by a **shape with a bitmap fill**, and a
loaded child's shapes are not on the GPU at all:

- The vertex buffer is uploaded **once**, at init, from `ctx->shape_data`
  (`render_webgpu.c` `create_buffers_and_upload`), which is
  `app_context->shape_data` (`swf.c:1581`) — the ROOT's `shape_data` array. A
  child's array is renamed `<prefix>_shape_data` by
  `verify_output.py::generate_child_movie_file` and handed to nobody.
- `renderer_draw_shape(context, ch->shape_offset, ch->size, obj->transform_id,
  obj->cxform_id)` passes a **movie-local** vertex index: `shape_offset` is
  `3*current_tri` in the emitting movie's own numbering (`swf.cpp:10837`). So a
  child's shape draws the root's vertices at that index.
- `obj->transform_id` and `obj->cxform_id` index the root's GPU transform and
  cxform buffers for the same reason. (The predecessor fixed the **CPU** side of
  this — `MovieEntry::transform_data_ptr` / `g_active_transform_data` — which is
  read by AVM1 getters only; nothing points the GPU at it.)
- `MovieEntry` (`swf.h:463`) carries exactly one render array, `transform_data_ptr`,
  and it is CPU-only. There is no plumbing for `shape_data`, `color_data`,
  `gradient_data`, `uninv_mat_data` or the bitmap range.
- The bitmap slot itself is baked movie-locally: a bitmap fill style is
  `((uninv & 0xFFFF) << 16) | char_id_to_bitmap_id[char_id]`
  (`swf.cpp:7462`, `:7877`), where `char_id_to_bitmap_id` counts from 0 in the
  emitting movie.

### And there is no trace-visible assertion available

The brief required one, correctly — image comparisons never gate trace pass/fail
here. But every AS-visible read of a child bitmap goes through a **metadata**
path, not the renderer's slot table: AVM1 `BitmapData.loadBitmap` reads
`ng_getBitmapMetadata` (fixed in slice 2) and AVM2 `[Embed]` reads the movie
tables (fixed here). Nothing in ActionScript can observe `ctx->bitmap_sizes`.
A "trace-visible assertion that a child bitmap reached the renderer" would have
to be a synthetic probe hook written for the purpose — which asserts the
implementation, not the behaviour.

### What half B actually needs

Roughly in dependency order:

1. **Per-movie render tables in `MovieEntry`** — `shape_data`, `color_data`,
   `gradient_data`, `uninv_mat_data`, plus their sizes — and a renderer that
   holds a *list* of movies rather than one set of globals.
2. **Per-movie base offsets applied at draw time** to `shape_offset`,
   `transform_id`, `cxform_id` and the bitmap slot in a fill style — or,
   alternatively, a recompiler that emits child indices already re-based the way
   `charId()` re-bases character ids. (The `charId()` precedent argues for doing
   it in the recompiler; the counter-argument is that a movie's render tables
   are appended at LOAD time, so the base is not known at emission.)
3. **A growable static slot table + a re-entrant finalize.** `bitmap_sizes` /
   `bitmap_ptrs` are `HALLOC`'d to the root's `BITMAP_COUNT` at init and
   `bitmap_sizes_buffer` is a GPU buffer of the same size;
   `build_static_bitmap_pools` allocates each size-class pool exactly once with
   its final layer count and latches `bitmap_static_built`. A child's bitmaps
   arriving later need either a deferred finalize (strip the child's
   `finalizeBitmaps()` in the wrapper, finalize before frame 1) or pools that
   can grow the way the dynamic pools already do. **Read
   memory `bitmap-texture-pools` first** — the pools are size-classed, so "a
   per-movie range" must not be written as an assumption that the static array
   is flat and root-sized.

None of that is a half-slice, and a partial landing is exactly the
"half-landed renderer change" §4.2 warns against. Recommend it be taken
**after** the frame-0 timeline slice, since a child that renders only frame 1
is a thin prize.

## 4. Test changes

`regression/avm2_parent_child_symbol_stride` gains three rows and two assets
(`blob.bin`, `silence.mp3` — a copy of `avm2/sound_valueof/silence.mp3`):

```
 child:tf3:Child_Pix
+child:pix:4x3
+child:blob:9
+child:snd:1044
 root:Child
 done
```

**The control is the same SWF as the MAIN movie.** `child.swf` run directly as
`test.swf` reports `4x3` / `9` / `1044`, before and after the fix — so the rows
measure main-vs-child parity. `1044` is our own `Sound.length`, not an oracle
number; if that computation is ever corrected the row moves with it.

The fixture's frame-1 constraint from the predecessor is respected: everything
these rows read happens in the child root's constructor, which
`actionFirePendingDirectLoads` runs from `child_frame_0`.

## 5. Verification

1. **Half A, per-defect and per-layer**, tabulated in §1 — each of the three
   assets measured at `0`/`0x0` before its fix and at the main-movie control
   value after.
2. **Both modes.** `--mode=no-graphics` and `--mode=graphics` (offscreen Dawn)
   both pass the fixture.
3. **Canaries** (§2): `import_assets` 3/3, gnash `attachImported` /
   `attachExtImported`, and the four other multi-SWF regression tests
   (`avm1_parent_child_bitmap`, `avm1_parent_child_modify_place`,
   `avm1_parent_child_sprite_meta`, `avm1_parent_as3_child_payload`) plus
   `avm2_bitmapdata_draw_textfield` — all green locally.
4. **Main-movie embedded-asset canaries** — the paths whose lookup changed:
   `avm2/bitmapdata_embedded`, `bitmap_subclass`, `bitmap_subclass_properties`,
   `bitmapdata_zero_size`, `bitmapdata_constructor_from_timeline`,
   `bitmap_timeline`, `bytearray`, `bytearray_serialization`,
   `sound_embeddedprops`, `sound_valueof` — all green locally.
5. **`gcc -fsyntax-only -std=c17 -Wall -Werror=return-type`** over
   `avm2_bitmap.c`, `avm2_bytearray.c`, `avm2_media.c` with the harness's own
   include set: clean; the only warnings are pre-existing
   `-Wmisleading-indentation` at `avm2_bitmap.c:229-232`, far from the change.
   (`verify_output.py` compiles with `-w` and would have shown none of it.)
6. **CI:** see §6.

## 6. CI

Both modes at `df9560ff6`, `categories=full`, `images=false`, both **success**.
Graphics run `33808752126`, no-graphics run `33808779440`. Baseline
`c68871311` (the pre-merge master, whose results are the previous publish;
the intervening commit is docs-only and was not what CI graded).

### `mode=graphics` — run `33808752126`

```
=== intersection: 4487 tests (c68871311 -> WORKTREE, results_graphics) ===

STATUS HISTOGRAM
  output_mismatch    124 ->   124 (+0)
  pass              4127 ->  4127 (+0)
  ruffle_matched     235 ->   235 (+0)
  runtime_error        1 ->     1 (+0)

  effective         4362 ->  4362 (+0)

GAINS (fail -> effective): 0
REGRESSIONS (effective -> fail): 0
OTHER STATUS MOVES (failing on both sides): 0
```

### `mode=no-graphics` — run `33808779440`

Dispatched because the three changed lookups are shared runtime code with no
graphics guard (CLAUDE.md: "when in doubt for shared runtime code, run both").

```
=== intersection: 4487 tests (c68871311 -> WORKTREE, results) ===

STATUS HISTOGRAM
  output_mismatch    123 ->   123 (+0)
  pass              4127 ->  4127 (+0)
  ruffle_matched     236 ->   236 (+0)
  runtime_error        1 ->     1 (+0)

  effective         4363 ->  4363 (+0)

GAINS (fail -> effective): 0
REGRESSIONS (effective -> fail): 0
OTHER STATUS MOVES (failing on both sides): 0
```

Every bucket unmoved in both modes, and the same 4487-test intersection on both
sides — no shard was lost. The one-test `output_mismatch`/`ruffle_matched`
difference between the modes is the pre-existing mode difference the two
predecessors recorded, present on both sides of each diff.

The suites this change touches, identical in both modes:

| suite | result |
|---|---|
| `regression` | **77/77**, with `avm2_parent_child_symbol_stride` now grading **6/6** lines (was 4) |
| `import_assets` | **3/3** — the canary for the defining-vs-placing ruling |
| `from_gnash/misc-ming.all` | `attachImported` **pass**, `attachExtImported` **pass** |
| `mixed_avm` | 10 pass / 2 `output_mismatch` — unchanged |

The three new rows are a **pure gain in graded lines, not in graded tests**: the
fixture already passed, so a corpus headline number cannot show this slice's
yield. That is expected — no corpus test loads a child SWF with embedded
assets, which is why the defect survived three slices.

## 7. What is left of the arc

- **A loaded child's timeline never advances past frame 0** — the next slice,
  and the largest. Unchanged.
- **A loaded child movie does not render at all** — rewritten from "a child's
  bitmaps never reach the renderer", which named one facet. See §3.
- **`flashbang_upload_bitmap`'s fix is unverified** — entangled with the
  standing "delete or fold flashbang into render_webgpu.c" question, which is
  worth settling before investing in testing it.
- **The constant-vs-`dictionary_capacity` divergence** — only worth doing when
  something needs a stride above 1000.
