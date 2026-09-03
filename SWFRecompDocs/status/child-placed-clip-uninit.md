# A child's transform ids indexed the parent's transform table

**Date:** 2026-09-03 · **Arc:** Multi-SWF (loaded children), slice 3
**Baseline:** `e52002d96` · **Brief:** `SWFRecompDocs/prompts/child-placed-clip-uninit-prompt.md`
**Predecessor:** `SWFRecompDocs/status/child-charid-stride-unify.md`

## The bug, named

`_root.holder.mc._x`, where `mc` is placed by a loaded child's own
`PlaceObject2`, returned a different garbage float on every run. It is **not an
unwritten field** — the brief's guess ("a display-list or transform entry whose
position fields are never written") is wrong, and so is anything a zero-init
would have fixed. It is a **read past the end of a static array**:

- A display entry's `transform_id` indexes the transform table of the movie
  whose **tag** placed it. The child's ids index `child_transform_data`; the
  main movie has its own, unrelated `transform_data`.
- Every AVM1 reader indexed the **main** movie's table. For the fixture's
  MTASC parent — no timeline content, so exactly one baked matrix — `draws.c`
  emits `float transform_data[1][16]`. The child emits
  `float child_transform_data[3][16]`. `_x` read `transform_data[1][12]`:
  **one row past the end of a one-row array.**

Instrumented, at the read site:

```
[DBG _x] mc=… name=mc as_set=0 dobj=0x… mc->x=-1.98797e+26 ltid=1 dep=1
        dobj: char_id=1001 tid=1 place_tx=0 place_ty=0 place_a=1
              movie_of_char=1 td[tid][12]=-3.97594e+27
x:-1.98796886290948e+26        (= td[1][12] / 20)
```

`place_tx` is right there on the entry and correct (0 twips, the identity
placement). The getter ignored it and re-indexed the wrong array.

The allocation, precisely: `transform_data` in the **parent's** generated
`draws.c` — a static `[N][16]` array sized by the parent's own baked matrix
count. Nothing "forgot to write" rows 1..N; those rows do not exist. `_name`
and `typeof` read correctly because neither goes near a transform table, which
is exactly why the symptom looked like a partially-initialised object.

## The fix

`ng_cache_transform` (`tag.c`) already resolves the correct table at placement
time — `g_active_transform_data`, which the child-movie init and
`attachMovie`'s imported-character path both swap. It cached the six matrix
values from that table but not **which** table they came from. It now records
it:

```c
static inline void ng_cache_transform(DisplayObject* obj, u32 tid) {
	float (*td)[16] = g_active_transform_data ? g_active_transform_data : transform_data;
	obj->place_transform_data = td;     // NEW
	obj->place_a  = td[tid][0];
	…
}
```

`DisplayObject::place_transform_data` (`swf.h`) is NULL until an entry is
cached, and two accessors in `tag.c` read it:

- `ng_entryTransformData(obj)` — the table to index; the main movie's
  `transform_data` when there is no override. Never NULL.
- `ng_entryChildTransformData(obj)` — the same, but NULL when the answer *is*
  the main movie's table, for callers holding a different handle on it (the
  browser-WASM `_x`/`_y` arms read `app_context->transform_data`, which carries
  the main rows **plus dynamic GPU slots** and must keep being used for
  main-movie entries).

Readers converted (all of them take the entry they already had in hand):

| file | site |
|---|---|
| `tag_stubs.c` | `ng_getTransformXY`, `ng_getTransformXY_d`, `ng_getTransformScaleRotation`, `ng_getTransformScaleRotationSkew`, `ng_getDisplayObjTranslation` |
| `action.c` | the `_x`/`_y` getters' textfield-bounds arms and the `pending_removal` arm; the browser-WASM `_x`/`_y` arms; the nested-textfield initial placement; the orphan-textfield parent/world walks; `COMPUTE_WORLD_MATRIX_DBL`; button child bounds; `compute_highlight_bounds`; `tab_collect_recursive` |

**For a main-movie entry the change is bit-identical**: `place_transform_data`
either is `transform_data` or is NULL, and both resolve to `transform_data`.
Only entries a loaded child placed take a different pointer — and today those
reads are the out-of-bounds ones.

### Why not the two nearby mechanisms

- **`place_a..place_ty` alone.** They are the six values the getters want and
  they are already correct. Using them would have switched *every* root-level
  `_x` read in the corpus from `transform_data[tid]` to a cached copy — a
  corpus-wide behaviour change to fix a child-only bug, and it would go stale
  anywhere `transform_id` moves without a re-cache (graphics `cache_as_bitmap`
  snapping repoints `obj->transform_id` at a dynamic slot mid-compose).
- **`DisplayObject::child_transform_data`, which already exists.** It is keyed
  on the movie that **defined** the character, so a sprite's own frame funcs
  run against the right table. That is a different question from which table
  the **tid** indexes, and the two disagree exactly for imported characters:
  `ng_shared.c:987` copies the child's movie id onto the local char id at
  `tagImportCharacter`, but the parent's tag supplies a **parent** tid. Reusing
  it would have broken `import_assets` / gnash `attachImported` to fix this.
  `swf.h` now carries that distinction in a comment on both fields.

## The 0-sentinel coverage question — answered, and it is now covered

The brief asked whether a real test is possible now that `_x` reads. **It is,
and it is written.** The predecessor listed three reasons the sentinel could
not be observed; the first of them turns out to have been a misreading, and the
real blocker was a fourth thing nobody had looked for.

**The actual blocker: a loaded child's timeline never advances past frame 0.**
The old fixture put the Modify in the child's frame 2, which never executed.
Verified directly — `gdb -ex 'break tagPlaceObject2' -ex run -ex bt` on the
2-frame child gives **exactly one** call:

```
#0  tagPlaceObject2 ()
#1  child_frame_0 ()
#2  actionFirePendingDirectLoads ()
#3  swfStart ()
```

Nothing ever calls `child_frame_1`. Filed as its own BACKLOG entry — every tag
past a loaded child's first frame is dead code today.

**Reason 1 as stated was wrong.** "A `tagPlaceObject2` of any character at an
already-occupied depth with `is_replace == 0` is a no-op" — it is not a no-op,
it is a *refusal that prints*: `tag.c`'s occupied-depth gate emits
`Warning: Failed to place object at depth %zu.` on **stdout**, which is a
graded line. The gate is skipped for `char_id == 0`, so the sentinel decides
which side of it the tag lands on. That is a channel, not a wall.

**The fix: place and modify in the SAME frame.** The child now emits, in frame
1, `PlaceObject2 HasCharacter|HasMatrix|HasName` (depth 1, char 1, `"mc"`,
translate 200/100 twips) followed immediately by `PlaceObject2 Move|HasMatrix`
(no character id, translate 1000/600 twips). The parent still defines the decoy
sprite at char 1000 and never places it.

Three states, all measured:

| state | output |
|---|---|
| before this slice's runtime fix | `x:` / `y:` garbage, different every run (`x:-4.6e-33`, `x:4.8e-38`, `x:9.0e+28` over three runs) |
| `charId()` sabotaged to offset 0 (`std::to_string(id + g_char_id_base)`), rebuilt | `Warning: Failed to place object at depth 1.` **and** `x:10` / `y:5` — the first placement's matrix, because the Modify became a refused place of the parent's decoy |
| correct | `x:50` / `y:30` |

`typeof` / `_name` are retained as controls: they read correctly in all three
states, so a failure that moves them is a different bug.

The mechanical guarantee stays documented and unchanged: recompiling the corpus
with `char_id_base=1000` preserved 264 `CHARID(0)` occurrences and produced
zero `CHARID(1000)`; `scripts/check_charid_wrapping.py` (both `--emitter` and
`--tree`) is the check to re-run if `charId()` is ever touched. The test is now
a second, independent guard rather than the only one being a scan.

## Where the brief was wrong

- **§1's diagnosis.** "The child's placement is producing a display-list or
  transform entry whose position fields are never written." The position fields
  *were* written, correctly, and sit on the entry as `place_tx`/`place_ty`. The
  defect is downstream of them: a reader that re-derives the value from the
  wrong array. The brief's instruction — find the field, don't memset at the
  read site — was right, and following it landed somewhere else than it
  predicted.
- **§2's ordering call was right, for one of the two stated reasons.** It is a
  live out-of-bounds read and this project's determinism is load-bearing, so
  the UB argument holds. The observability argument holds *more* than claimed:
  making `_x` readable did not merely remove one of three obstacles to a
  0-sentinel test, it exposed that two of the three were mis-stated and turned
  the test into a discriminating one in the same change.
- **§3's "if the read turns out shallow, fold in the child-bitmap pair."** The
  read was shallow in lines changed and not in reach: the same wrong-table
  indexing runs through ten more call sites (bounds, hit-test world matrices,
  tab order), all of which had to move for the fix to be coherent. The bitmap
  pair is untouched and is still the next slice.

## Also fixed in passing

`verify_output.py:679-685` still described `generate_child_movie_file` as
re-basing child ids "with ONE substitution keyed on the CHARID() wrapper",
directly above a block correctly saying the recompiler does it. Rewritten to
say why the wrapper survives its substitution (the oracle keys on it).

## Verification

1. **Determinism.** `avm1_parent_child_modify_place` run 3× post-fix: `x:50` /
   `y:30` every time. Pre-fix, same 3 runs: three different garbage floats.
2. **Both modes.** `--mode=graphics` (offscreen Dawn) passes the same rows;
   pre-fix it produced garbage there too, via the same
   `NO_GRAPHICS || OFFSCREEN_RENDER` arm.
3. **Sentinel sabotage** (recompiler rebuilt with `charId()` offsetting 0):
   flips, as tabulated above. Reverted and rebuilt; test green again.
4. **`gcc -fsyntax-only -std=c17 -Wall -Werror=return-type`** over `action.c`,
   `tag.c` and `tag_stubs.c` in a real build dir: no errors, and no warning on
   any changed line (the pre-existing `-Wmisleading-indentation` /
   `-Waddress` / unused-variable noise is unchanged). `verify_output.py`
   compiles with `-w` and shows none of it.
5. **Zero-init audit for the new pointer field.** `place_transform_data` must
   never be read as garbage: `display_list` is `calloc`'d, sprite lists are
   `HCALLOC`'d (both `heap_calloc` implementations zero), `grow_ptr` memsets
   the grown tail, and `ng_spriteDLRealloc` `HCALLOC`s the new buffer. Every
   growth path zeroes.
6. **`ng_cache_transform` reachability.** Checked the preprocessor context of
   all 14 call sites: the main placement/modify paths (`tag.c` :8870, :9107,
   :9479, :9533, :9910, :10095) are unconditional, so the field is populated in
   every build mode including browser-WASM; only :8935 and :9954 are
   browser-WASM-only and :9173/:9371/:9417/:10068/:10117/:10423 are
   NO_GRAPHICS/OFFSCREEN-only.
7. **Regression suite**, `--tests-dir=ruffle-tests/tests/swfs/regression`: see
   below.
8. **CI**, both modes: see below.

## CI

<!-- CI_RESULTS -->

## What is left of the arc

Unchanged from the predecessor except that `_x` is struck and one item is new:

- **`embedded_bitmap_for_char` ignores child movies** + **the renderer's
  per-movie static-bitmap range** — the next slice, as one pair.
- **`flashbang_upload_bitmap`'s fix is unverified.**
- **The constant-vs-`dictionary_capacity` divergence** — only worth doing when
  something needs a stride above 1000.
- **NEW: a loaded child's timeline never advances past frame 0.** Every tag
  after a child's first frame is dead. Nothing in the corpus grades it, which
  is why it survived three slices of multi-SWF work; it is the reason this
  slice's fixture places and modifies inside one frame.
