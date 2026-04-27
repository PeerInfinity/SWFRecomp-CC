# Import Character Plan

<!-- TESTS: attachImported, attachMovieLoopingTest, loading/loadMovieTest -->

<!-- PLAN_META
id: IMPORT_CHARACTER
status: complete
phases:
  - id: 1
    name: "Diagnose: which step of the import pipeline fails for attachImported"
    status: complete
  - id: 2
    name: "Char_id namespace: parent/child dictionary collision audit"
    status: complete (verify_output.py already offsets char_ids by movie_id*1000; no collision)
  - id: 3
    name: "Recursive character closure import — ImportAssets must pull all chars the imported sprite references"
    status: complete (run child's frame_0 with tag_skip_mode=1 to register tagDefineShape calls)
  - id: 4
    name: "_height/_width on imported characters: verify sprite_content_bounds_twips after attachMovie of imported char"
    status: complete (cached place_* + entry_idx fix + twip-rounding)
  - id: 5
    name: "loadMovieTest: separate triage (click-driven loadMovie + JPG/SWF child loading)"
    status: deferred (separate plan, requires click-event driver work)
-->

## 2026-04-27 session results

**attachImported (1/2 → 2/2): PASS.**
**attachMovieLoopingTest (29/41 → 41/41): PASS.**
**loading/loadMovieTest (5/80): unchanged, deferred to a separate plan (requires click-event driver work).**

### Fixes landed

1. **Per-movie export visibility for tagImportCharacter**
   (`SWFModernRuntime/src/libswf/ng_shared.c`). `tagImportCharacter`
   now also calls into the export registry to register the imported
   symbol under the importing movie's `g_current_movie_id`, so
   `ng_lookupExportForMovie("redsquare", parent_movie_id)` succeeds
   when `attachMovie` is called from the parent. Previously the
   symbol was only registered under the source child movie's id, so
   per-movie attach lookups returned -1 and the script fell back to
   `pushUndefined`. Also fixed an `exported_char_id == 0` early-return
   that should have been `(size_t)-1` (the not-found sentinel).

2. **Run child's frame_0 to register character definitions**
   (`SWFModernRuntime/src/actionmodern/action.c::actionImportAssets`).
   The recompiler emits `tagDefineShape`, `ng_record_char_path`,
   `tagDefineButton`, etc. inside the main timeline's `frame_0`, not
   `tagInit`. So `init_func` alone left character bounds unregistered.
   Now we additionally invoke `entry->frame_funcs[0]` with a swapped-
   in scratch `display_list` (so placements can't pollute the parent
   root) and `g_tag_skip_mode = 1` + `catch_up_mode = 1` so
   placements/show_frame are skipped and `actionDrainOnloadAndScript`
   doesn't fire. Definitions still register normally because
   `tagDefineShape` etc. don't gate on either flag.

3. **Switch g_active_transform_data in ng_attachMovie for imported chars**
   (`SWFModernRuntime/src/libswf/tag_stubs.c::ng_attachMovie`). When
   the attached `char_id` belongs to a child movie
   (`g_char_movie_id[char_id] != 0`), swap `g_active_transform_data`
   to that child's `transform_data` table around the `funcs[0]`
   placement-replay so `tagPlaceObject2` caches transforms from the
   correct table. Added accessor
   `ng_getMovieTransformData(movie_id)` in
   `SWFModernRuntime/src/libswf/tag.c` since the table is `static`.

4. **Use cached place_* in sprite_content_bounds_twips**
   (`SWFModernRuntime/src/libswf/tag.c`). Instead of indexing
   `transform_data[child->transform_id]` (which is always parent's
   table), read the cached `child->place_a/d/tx/ty` populated at
   `tagPlaceObject2` time using whichever table was active. Gated to
   `NO_GRAPHICS || HEADLESS_GRAPHICS` since `place_*` is only cached
   in those modes.

5. **Don't treat findDisplayEntryIdx==-1 as "root"**
   (`SWFModernRuntime/src/actionmodern/action.c::mcGetOriginalBounds`).
   `ng_findDisplayEntryIdx(mc->name)` returns `(size_t)-1` for
   not-found, but `ng_getDisplayEntryBounds(-1)` interprets `-1` as
   "iterate the whole root display list" — so a missed lookup
   produced bounds covering everything in root (e.g. the dejagnu
   trace text spanning ~800x600 px) and `_height` came back as
   `604` instead of `60.1`. Distinguish "mc IS root" (entry_idx=-1)
   from "mc lookup failed" (skip the static-bounds path entirely).

6. **Round to twips in mcGetEffectiveSize (rotation==0 branch) +
   in stored-width fallback in mcGetOriginalBounds**
   (`SWFModernRuntime/src/actionmodern/action.c`). Float storage of
   `xscale`/`yscale` introduces ~1e-7 residue when set via
   `_height = N`, making `_height` read back as `15.0000001716614`
   instead of `15`. Flash's coord system is twip-precise, so
   `round(eff_h * 20) / 20` collapses the artifact without losing
   real precision. Matches the rotation branch's existing twip
   rounding. Also re-round `mc->width`/`height` from float to twip
   in the attachMovie-fallback path of `mcGetOriginalBounds` so a
   `1202`-twip / `60.1`-px bound round-trips exactly.

### Verification battery

- AVM1 (in-tree): TBD when battery completes — see commit notes.
- Gnash misc-ming.all: 7/7 PASS (`ResolveEventsTest`,
  `attachExtImported`, `attachImported`, `attachMovieLoopingTest`,
  `attachMovieTest`, `event_handler_scope_test`, `loop/loop_test8`).

## Problem statement

`actionImportAssets` (Tag 57: ImportAssets / Tag 71: ImportAssets2) and
`tagImportCharacter` are wired in the recompiler and runtime —
`SWFRecomp/src/swf.cpp:3979-4012` and
`SWFModernRuntime/src/libswf/ng_shared.c:784`. The mechanism:

1. **Parent SWF**'s tagInit registers its own exports via
   `tagRegisterExport`, then defines its own characters via
   `tagDefineSprite` etc.
2. **Parent's tag_init_scripts** runs `actionImportAssets("child.swf")`
   which finds the child movie's MovieEntry (auto-generated by
   `verify_output.py:1135` `generate_movie_registry`), then calls
   the child's `init_func` (= child's `tagInit`).
3. **Child's tagInit** populates `dictionary[]` with the child's
   characters and calls `tagRegisterExport` for the child's
   ExportAssets.
4. **Parent's tag_init_scripts** then calls
   `tagImportCharacter(local_char_id, "redsquare")` which does
   `dictionary[local_char_id] = dictionary[exported_char_id]`.

The infrastructure exists. But three Gnash tests that exercise the
import path fail despite the wiring:

| Test | Match | Symptom |
|------|-------|---------|
| `attachImported` | 1/2 (50%) | `redsquare._height == 60.1` expected; `_height` reads as empty (no value emitted) |
| `attachMovieLoopingTest` | 29/41 (70.7%) | `hello redsquare` clip-event onLoad fires correctly; `_height == 60.1` expected, gets `604` (10× off); subsequent scaling: `_yscale == 25` expected, gets `2`; FP precision residue (`15.0000001716614` vs `15`) |
| `loading/loadMovieTest` | 5/80 (6.2%) | Click-driven sequence; output truncates at frame 5/80 — different blocker, separate triage |

## Diagnosis: where does the pipeline break

### attachImported produces empty `_height`

The test does `attachMovie("redsquare", "tgt", 1)` then asserts
`tgt._height == 60.1`. We get an empty `obtained:` field — meaning
`_height` returns an empty/undefined value that coerces to `""`.

`mcGetOriginalBounds` (`action.c:21788`) prefers in this order:

1. `loaded_image_width` (image-loaded MCs).
2. `is_button_mc` → button hit shape.
3. `MC_IS_TEXTFIELD` → stored width/height.
4. `ng_getDisplayEntryBounds(entry_idx)` — display list entry bounds.
5. `mc->draw_has_bounds` — Drawing API union.
6. **Fallback:** `mc->width / mc->height` if > 0 (set by
   `ng_attachMovie` line 482-483 from `sprite_content_bounds_twips`).
7. Walk dynamic children.
8. Return `0.0, 0.0`.

For an attachMovied imported sprite:
- Step 1-3: don't apply.
- Step 4: `entry_idx` from `ng_findDisplayEntryIdx(mc->name)`. The
  attached MC is in `child_mc_cache`, not the display list, so
  `entry_idx == SIZE_MAX` and `ng_getDisplayEntryBounds` returns 0.
- Step 5: no Drawing API used.
- **Step 6 is the load-bearing path.** `ng_attachMovie` at
  `tag_stubs.c:478-484` runs `sprite_content_bounds_twips` on the
  attached sprite's display list **after** frame 0 runs and
  populates the bounds.

If `mc->width/height` come back as 0 from
`sprite_content_bounds_twips`, _height returns empty. This happens
when the sprite's frame 0 didn't successfully place its content —
which happens when `tagPlaceObject2(depth, char_id, ...)` inside
the imported sprite's frame_0 references a char_id that's missing
or wrong in the parent's dictionary.

### Hypothesis: char_id namespace collision

The parent and child SWFs each emit their own character pool with
their own char_id numbering. Both write to the **shared**
`dictionary[]` array. Parent's tagInit runs first (populating
parent slots); child's tagInit runs second via `actionImportAssets`
(potentially clobbering parent slots that share child char_ids).

`tagImportCharacter`'s `dictionary[local_char_id] = dictionary[exported_char_id]`
copies one entry, but the imported sprite's frame_0 contains
recompiled C like:

```c
void child_sprite_redsquare_frame_0(SWFAppContext* app_context) {
    tagPlaceObject2(app_context, 1, /* char_id= */ 7, /* transform= */ 3, ...);
}
```

The `7` is the **child's** char_id for redsquare's shape. After
the child's tagInit runs, `dictionary[7]` holds the child's shape —
but only if **no parent character also lives at slot 7**. If the
parent also defined char_id 7 (e.g., a parent's own shape), the
child's tagInit overwrote it. After import, attempting to attachMovie
a parent character that uses char_id 7 would fail.

For the redsquare attach itself: `attachMovie("redsquare", ...)` →
`ng_attachMovie(char_id_for_redsquare, ...)` → runs
redsquare's frame_0 → `tagPlaceObject2(1, 7, ...)`. If
`dictionary[7]` is the child's shape (correct), bounds compute
correctly. So attachImported should work in theory.

**Key investigation step:** verify that `dictionary[7]` (or whatever
char_id redsquare's frame_0 references) is correctly populated after
the child's tagInit runs but before redsquare's frame_0 fires. Use
gdb or printf in `ng_attachMovie` and `sprite_content_bounds_twips`.

### attachMovieLoopingTest's `604` instead of `60.1`

`604` is `60.1 * 10.05` — close to a 10× factor, but not exact. More
likely: `604` is `60.4` rounded after a units-of-1/10 conversion.
Possible bug in `sprite_content_bounds_twips`: a 1202-twip-tall
shape should give `1202 / 20 = 60.1` pixels, but if we accidentally
use `1202 / 2 = 601` (twips/2 instead of twips/20), the result
would be ~601, close to 604.

Or: the imported character's transform matrix is being applied
twice (once at attachMovie placement, once inside the sprite).
A 10× scale matrix would account for the order-of-magnitude.

### attachMovieLoopingTest's `_yscale == 25` got `2`

`25 / 12.5 = 2`. `12.5` is a notable denominator (1/8 of 100). The
test sets `_yscale = 25` then reads it back. If the read computes
yscale from the transform matrix, and the matrix has a nested
import-side scale baked in, the apparent yscale would be
`set_yscale / nested_scale = 25 / X`. If X = 12.5, the result is 2.

This further supports a "transform applied twice" hypothesis for
imported characters.

### attachMovieLoopingTest's FP precision

`15.0000001716614` vs `15`. The residue (~1.7e-7) is single-precision
float roundoff. Likely a `(float)` round-trip in the bounds
computation that double-precision Flash doesn't do. Lower priority —
fixable independently of the import path.

## Phase 1 — Diagnose attachImported

Before designing fixes, determine which step fails:

1. Add `printf` in `actionImportAssets` (action.c:26480) to confirm
   `findMovieEntry("attachMovieTest.swf")` returns non-NULL and the
   child's `init_func` is called.
2. Add `printf` in the child's `tagRegisterExport` to confirm
   `redsquare` registers with the right char_id.
3. Add `printf` in `tagImportCharacter` to confirm the local→export
   remap copies a non-empty `dictionary[exported_char_id]`.
4. Add `printf` in `ng_attachMovie` at line 482 to confirm
   `sprite_content_bounds_twips` returns non-zero bounds.
5. If all the above succeed but `_height` still empty, the bug is
   in `mcGetEffectiveSize`/`mcGetOriginalBounds` reading the wrong
   field. If any fail, that's the bug site.

Cross-reference with `attachMovieLoopingTest`'s 604 / 25→2
symptoms — the imports DO work enough to fire `hello redsquare`
trace, so the basic dictionary remap is functional. The bug is
later: bounds computation specifically.

**Output:** a per-test root-cause table that drives Phases 2-4.

## Phase 2 — Char_id namespace audit

Confirm or refute the "parent/child dictionary collision" hypothesis:

1. Inspect parent and child SWFs with the SWF tag scanner used in
   `ZERO_OUTPUT_TRIAGE_PLAN.md`. List char_ids defined by parent
   vs child:
   ```
   parent: char_ids {1: shape, 2: text, 3: sprite_redsquare_local}
   child:  char_ids {1: shape (redsquare), 2: sprite (redsquare wrapper)}
   ```
2. After parent and child tagInit both run, check `dictionary[1]`,
   `dictionary[2]`, `dictionary[3]`. If parent's char_id 1 was
   silently clobbered by child's char_id 1, that's the collision.
3. If collision occurs, the fix is to allocate the child's
   characters into a non-overlapping char_id range before the
   child's tagInit runs.

**Mitigation options:**

- **Option A: Recompile-time char_id remap.** When recompiling a
  child SWF for use as an import target, the recompiler offsets
  the child's char_ids by a known base (e.g., +10000). Then no
  collision is possible. Requires the recompiler to know it's
  being invoked in "child" mode — `verify_output.py` can pass a
  flag.
- **Option B: Per-movie dictionary.** The runtime keeps separate
  dictionary arrays per movie_id, with `tagImportCharacter`
  resolving via `(movie_id, char_id)` pair. Substantial
  refactor.
- **Option C: Allocate char_ids dynamically at child tagInit
  time.** Each child tagInit, before its first
  `tagDefineSprite` call, asks for a base offset and adds it to
  every char_id. Harder to retrofit (every tag emission needs
  the offset).

Option A is the lightest-touch and matches what
`verify_output.py` already does for `string_id_offset`
(line 1383-1393 — child string IDs are offset to avoid collision).
The same pattern for char_ids would close the gap.

## Phase 3 — Recursive character closure

If Phase 2 confirms collisions and fixes them, attachImported's
char_id 7 lookup returns the child's shape correctly. But
`ImportAssets` only imports the **named** symbol (redsquare). Any
characters redsquare's frame_0 references (its shape, its child
sprites if any) need to be reachable via the parent's dictionary
too.

In Ruffle, this is implicit because the parent and child share a
single character library indexed by `(movie_id, char_id)`. Our
`tagImportCharacter` only copies one entry.

**Fix.** After Phase 2's char_id offset is in place, the child's
characters are already in `dictionary[]` at the offset range. The
parent's `tagImportCharacter("redsquare")` only needs to remap the
local char_id to the child's offset-adjusted slot. The recursive
references inside redsquare's frame_0 already work because they
encode the child-namespace char_ids (which include the offset).

So Phase 3 may be a no-op once Phase 2 lands. Verify by tracing.

## Phase 4 — _height/_width on imported characters

If Phase 1 narrows the problem to bounds computation specifically:

- For attachMovieLoopingTest's 604/60.1 mismatch, audit
  `sprite_content_bounds_twips` (`tag_stubs.c` — search for the
  function). Verify the units conversion: SWF coordinates are in
  twips (1/20 px); `_height` is in pixels.
- For the 25→2 yscale issue, audit how
  `mcGetEffectiveSize`'s `eff_h = nat_h * yscale / 100` interacts
  with the imported-character transform. The PlaceObject2 inside
  the imported sprite may apply a transform that
  `sprite_content_bounds_twips` is supposed to ignore (we want
  natural unscaled bounds), but our impl may include it.
- For the FP residue (`15.0000001716614`), the bounds path
  probably stores `(float)` somewhere where it should be `double`.
  Cross-reference with `bitmap_data_*` and `text_format_*` AVM1
  tests for similar twip→pixel rounding patterns that already
  pass.

## Phase 5 — loadMovieTest separate triage

`loading/loadMovieTest` is at 5/80 — much deeper than the import
character path. The expected output cycles through ~10 click events
that load JPG and SWF children, with assertions between each:

```
0.0: Click on the first image. Wait...
PASSED: true × 4
PASSED: test.swf == test.swf
PASSED: -16376 == -16376
PASSED: 160 == 160
PASSED: true
FAILED: expected: MovieClip.loadMovie , obtained:  ← Dejagnu xfail (expected failure)
0.1: Click on the second image. Wait...
... (repeats)
```

We produce 5 lines and stop. The test SWF has multiple JPG and SWF
children (`blue.jpg`, `blue.swf`, `red.jpg`, `red.swf`, `green.jpg`)
plus `input.json` driving clicks. Likely root cause: **after the
first `loadMovie` invocation, our runtime stalls on something —
either the load doesn't fire `onLoadInit`, or the click handler
doesn't get the loaded MC's reference back, or an assertion fails
silently and stops execution.**

Investigation steps:

1. Run with verbose stderr to catch any `ERROR:` messages.
2. Compare the actual line 5 to expected — both have `PASSED: true`
   at line 5, then expected continues. Where does the test "stop"
   in our impl? Does the next click event fire? Does the next
   assertion run with `undefined`?
3. Likely overlaps `LOADMOVIE_PLAN.md` (already complete in AVM1
   investigation) edges — specifically multi-load cycling and the
   `MovieClip.loadMovie` xfail line which Dejagnu expects to fail.

Treat as a separate plan once Phases 1-4 are diagnosed.

## Verification battery

**Required-pass guardrail:**

- AVM1: `loadmovie`, `loadmovie_unloadmovie`, `loadmovie_*` (~30
  tests). Phase 4's bounds changes interact with attachMovie/
  loadMovie size getters.
- AVM1: `attach_movie`, `attach_movie_stop`,
  `empty_movieclip_can_attach_movies`, `init_object_order`,
  `init_object_invalid`, `movieclip_init_object`. The Phase 2-3
  char_id remap touches the attachMovie path.
- AVM1: `do_init_action_child` (12/12) — uses ImportAssets and
  passes today; must remain green.
- AVM1: `register_class_with_sound` (uses ImportAssets +
  registerClass).
- Gnash misc-ming recently-fixed: `attachMovieTest` (12/12), all
  18 attach/place tests in the recently-fixed battery.
- Shumway: `from_shumway/avm1/duplicateMovieClip/*`,
  `from_shumway/haxe/flocons1` (if it exercises ImportAssets).

**Target tests:**

- `attachImported` from 1/2 to 2/2 — full PASS.
- `attachMovieLoopingTest` from 29/41 to higher (likely full PASS
  if Phase 4 fixes both the 604 and 25→2 issues; FP residue may
  remain a separate line).
- `loading/loadMovieTest` from 5/80 to a deeper diff that exposes
  the click-cycle issue for separate triage.

## Open questions

1. **Does Ruffle already pass attachImported / attachMovieLoopingTest?**
   Check `output.ruffle.txt` files (attachMovieLoopingTest has one;
   attachImported doesn't). If Ruffle passes them, the fixes have
   high confidence. If Ruffle also fails them, the test's expected
   output may be Flash-specific behavior we can match via
   `RUFFLE_VS_FLASH_DIFFERENCES.md` mechanism.
2. **Is `verify_output.py`'s `string_id_offset` precedent the right
   model for char_id offset?** That mechanism handles strings
   correctly today. Confirm by reading
   `verify_output.py:1380-1393` and the recompiler's string ID
   handling — apply the same pattern to char_ids.
3. **Movie ID vs offset.** The runtime already tracks
   `g_char_movie_id[char_id]` (set by tagImportCharacter and
   nullable via `g_current_movie_id`). Could the existing
   movie_id tracking be enough to distinguish parent vs child
   characters without renumbering? If so, the fix is in the
   lookup path, not the recompiler.

## Estimated session budget

- Phase 1 (diagnosis): 2-3 hours of printf-tracing + reading.
- Phase 2 (char_id audit + fix): 3-4 hours, depending on Option
  A/B/C choice. Option A (recompiler offset) is the lightest;
  Option B (per-movie dict) is a multi-day refactor.
- Phase 3 (recursive closure): 0-2 hours, likely subsumed by
  Phase 2.
- Phase 4 (bounds): 2-3 hours.
- Phase 5 (loadMovieTest): separate plan, not in this session
  budget.

Total Phases 1-4: 7-12 hours. Recommended order: 1 → 2 (Option A)
→ 4 → 3 (verify no-op) → 5 (defer).

## Why this is the right shape

The legacy plan note in `MISC_MING_SWFC_PLAN.md` said:
*"actionImportAssets / tagImportCharacter ARE wired in the
recompiler+runtime, but the imported character ends up missing at
attachMovie time. Need to confirm that the verifier actually
compiles the child attachMovieTest.swf AND that the child's
tagRegisterExport runs before the parent's tagImportCharacter
lookup. The child SWF is present in the test dir but I didn't trace
whether its init function fires."*

This plan starts by doing exactly that tracing (Phase 1) — verifying
each step of the pipeline — then fixes whichever step fails. The
hypothesis is char_id namespace collision (Phase 2-3), but Phase 1's
diagnosis determines whether that's the actual bug or a different
one (e.g., Phase 4's bounds math).

Once landed, removes the "attachImported / attachMovieLoopingTest /
loadMovieTest blocked on tagImportCharacter dictionary" entries from
`MISC_MING_SWFC_PLAN.md`'s "Multi-issue / blocked clusters" section.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `MISC_MING_SWFC_PLAN.md` "attachImported, attachMovieLoopingTest, loop_test10, loadMovieTest" entry | This plan addresses 3 of the 4 listed tests. loop_test10 is independent (loop opcode handling). |
| `complete/REGISTERCLASS_PLAN.md` "ExportAssets Parsing" + "do_init_action_child" | Predecessor work that established the export/import infrastructure. `do_init_action_child` (12/12 PASS) demonstrates ImportAssets cross-version works for SOME cases; this plan investigates why it fails for character imports specifically. |
| `complete/LOADMOVIE_PLAN.md` (in AVM1 investigation) | Predecessor for loadMovie infrastructure. Phase 5 (loadMovieTest) likely extends edges this plan didn't cover. |
| `BUTTON_INFRASTRUCTURE_PLAN.md` | loadMovieTest is also click-driven; may overlap input drivers but the failure is a different stage (load mechanics, not input). |
