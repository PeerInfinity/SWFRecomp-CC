# Bounds engine unification — Flash-accurate `_width`/`_height`/getBounds/hitTest

Status: **DONE** (P1–P3 landed & CI-green in both modes; legacy engine + entry_idx encoding deleted). Created 2026-05-28.

## Progress log

- **P1** (`12a7bb799`) — pointer-form accessors + `resolveMCDisplayEntry`/`resolveMCDisplayList`
  + `ng_localBoundsOfDL`/`ng_objRootDepth`/`*ByDepth`; `*FromEntry` delegate. Additive.
- **P2 bounds** (`eef77ea7b`) — all 5 `ng_getDisplayEntryBounds` callers → `ng_localBoundsOfDL`.
- **P2 fix** (`432dccb03`) — degenerate (zero-extent) `_matrix` result is ignored in the
  `_width`/`_height` path so the `child_mc_cache` fallback fires for dynamically-attached
  children (ng_attachMovie doesn't cache `place_*`). Fixed the one CI regression (avm1
  `issue_2084`).
- **CI confirmed green both modes** (no-graphics run 26609151375, graphics run 26609152488):
  every suite holds its pre-refactor baseline (avm1 614/614, shumway 73, shumway/avm1 46,
  actionscript.all 124/122, ming 66/65, swfmill 19, mtasc 7, swfc 8). Zero net regressions.
- **P2d/e/f** (`bb75d3120`) — matrix (`getLocalMatrixForMC[_render]`), CT (`getLocalCTRaw`/
  `setLocalCTRaw`), filter accessors migrated to `resolveMCDisplayEntry` + `ng_objRootDepth` +
  the pointer/`*ByDepth` forms. No `entry_idx` callers remain. Local-pass: transform,
  color_transform, color, matrix, bitmap_filters, as_transformed_flag.
- **P3** (next commit) — deleted the legacy `ng_getDisplayEntryBounds`, the dead
  `ng_computeBoundsFromDL_fp16` (+ FP16 macros / `boundsUnionCornerFP` / `g_bounds_recursion_depth`),
  both `ng_entry_to_obj` copies, `getDisplayEntryIdxForMC`, `ng_findDisplayEntryIdx[WithParent]`,
  `ng_getMatrixFromEntry[_render]`, `ng_getCTFromEntry`, `ng_setCTOnEntry`,
  `ng_getDisplayEntryFilterData`, `ng_getExtFilterData`, `ng_getFilterListData`, and their
  decls + dead externs. The `entry_idx` encoding is gone. Surviving engine: the single
  double-precision `ng_computeBoundsFromDL_matrix` (+ `ng_localBoundsOfDL`/`ng_computeBoundsFromDL`).
  Local-pass NO_GRAPHICS: movieclip_getbounds, issue_2084, transform, color_transform, bitmap_filters.
- **Final CI** (P2d/e/f + P3, no-graphics run 26610397596, graphics run 26610398457) —
  **green both modes, every suite delta 0, zero newly-failing.** Bounds-engine
  unification complete. Out-of-scope `delete-v5..v8`/`delete2` red remains (separate
  delete-opcode fix, see baseline note above).

## Motivation

`SWFModernRuntime/src/libswf/tag_stubs.c` currently has **two parallel bounds
engines** that disagree on accuracy. AS-level size/bounds queries are split
across them inconsistently, which produced the Pong paddle-keyboard bug
(commit `66b4ddc07`): `paddle._height` returned the full-stage bounds (401px)
instead of the paddle's own ~50px, inverting the game's clamp range.

That commit was a one-line band-aid on the legacy engine (it fixed the 2-level
case). The legacy engine still has three structural limits. This plan replaces
it with the already-validated pointer-recursive engine so every bounds/size
query goes through one Flash-accurate path.

## Current state

### The engines (all in `tag_stubs.c`, compiled in NO_GRAPHICS, OFFSCREEN_RENDER, and browser-WASM)

| Function | Tree descent | Child transform | Arithmetic | Units | Reads matrix from |
|---|---|---|---|---|---|
| `ng_getDisplayEntryBounds(size_t entry_idx, float*…)` **(legacy)** | integer-encoded `entry_idx`; **2-level cap** in both resolution and recursion | `sx`/`sy`/`tx`/`ty` only — **ignores rotation/skew (b,c)** | float | **pixels** | `transform_data[tid]` |
| `ng_computeBoundsFromDL_fp16(DisplayObject* dl, dl_max, matrix…)` | `DisplayObject*` ptrs; **arbitrary depth** | full 2×3 matrix | Fixed16 16.16, **truncating (matches Ruffle)** | twips | `transform_data[tid]` |
| `ng_computeBoundsFromDL_matrix(DisplayObject* dl, dl_max, matrix…)` | `DisplayObject*` ptrs; **arbitrary depth** | full 2×3 matrix | double (Ruffle-style f32 compose + round per corner) | twips | **cached `child->place_*`** (robust for child SWFs w/ separate `transform_data`) |
| `ng_computeBoundsFromDL(dl, dl_max, out…)` | wrapper: `_matrix` with identity | — | double | twips | — |

`getBounds`/`getRect` (action.c ~65948) already use `ng_computeBoundsFromDL_matrix`
— it walks the display tree by name/path to the MC's own `sprite_display_list`
(arbitrary depth, see action.c:65900–65935) then calls the recursion with an
identity matrix to get local bounds. **This is the path validated by the
graphics-native suite (948/1125).**

### The `entry_idx` encoding (the legacy API's currency)

`entry_idx`: `(size_t)-1` = root; a bare value = root depth; `(parent_d << 20) | child_d`
= one level of nesting. **Only 2 levels representable.**

Producers:
- `ng_findDisplayEntryIdx(name)` — scans **root depths only**, returns a root depth.
- `ng_findDisplayEntryIdxWithParent(name, parent_idx)` — one level of nesting.
- `getDisplayEntryIdxForMC(mc)` — recurses up `mc->parent`, but feeds each level
  through the 2-field encoding, so it **also caps at 2 levels** for the top-level
  query (a 3-deep MC can't be addressed at all).

### Legacy callers to migrate (5 sites)

| Site | What it is | Gate | Needs |
|---|---|---|---|
| action.c:26787 | `mcGetOriginalBounds` — natural unscaled bounds; **feeds `_width`/`_height`** (`mcGetEffectiveSize`), the `_xscale`/`_yscale` setters, and the getBounds fallback | all modes | local pixel bounds, children composed, queried MC's own transform NOT applied; later unioned with `mc->draw_*` by the caller |
| action.c:26897 | `mcGetEffectiveSize` matrix-path (sibling entry of the same family) | all modes | same |
| action.c:9061 | `transform.pixelBounds` getter | `NO_GRAPHICS \|\| OFFSCREEN_RENDER` | local pixel bounds |
| action.c:69619 | focusrect world-bounds draw helper | all modes | local pixel bounds (then applies concat matrix itself) |
| tag_stubs.c:2206 | duplicateMovieClip: capture static clone `width`/`height` | all modes | local pixel bounds of a root-depth source |

**Shared contract of all 5:** return the queried object's **local** bounds (its
own transform excluded — every caller applies the world/own matrix itself) in
**pixels** (float).

## Limitations to fix (the "all of these features")

1. **Recursion depth cap (2 levels).** Band-aided in `66b4ddc07` for exactly 2;
   3+-deep nested sprites still wrong. (Pong is 2-deep: paddle→gab→shapes.)
2. **Top-level resolution cap (2 levels).** `getDisplayEntryIdxForMC` can't even
   address a 3-deep MC.
3. **Rotation/skew ignored.** Legacy composes children with `sx`/`sy`/`tx`/`ty`
   only; a rotated/skewed child inside a queried sprite gets wrong bounds.
4. **Engine duplication.** `_fp16` and `_matrix` are near-identical; only one
   should survive (decision below).

## Target design

One local-bounds helper, `DisplayObject*`-based, arbitrary depth, full matrix —
reusing the engine getBounds already trusts. Sketch:

```c
// Local content bounds (twips) of a sprite's children, queried object's own
// transform NOT applied. dl/dl_max come from the object's sprite_display_list.
int ng_localBoundsOfDL(DisplayObject* dl, size_t dl_max,
                       int* has, double* xmin, double* ymin, double* xmax, double* ymax);
// == ng_computeBoundsFromDL_matrix(dl, dl_max, identity, …)
```

Callers obtain `dl`/`dl_max` from the MC directly (`mc->display_obj->sprite_display_list`
or the by-name tree walk getBounds uses) rather than round-tripping through
`entry_idx`. A thin compatibility shim can keep the old `ng_getDisplayEntryBounds`
signature during migration (resolve entry_idx → dl, delegate, convert twips→px),
then be deleted once all 5 callers move to the pointer form.

## Open decisions (need sign-off before coding)

- **D1 — canonical engine: `_matrix` (double) vs `_fp16` (Fixed16/Ruffle-exact).**
  getBounds currently uses `_matrix`, so picking it keeps the validated path and
  makes `_width`/`_height` consistent with getBounds for free. `_fp16` is closer
  to Ruffle's truncating integer math and may match more trace-test expected
  outputs bit-for-bit. Recommendation: **standardize on `_matrix`** (match the
  proven path), keep `_fp16` only if a measured trace-suite delta justifies it;
  otherwise delete it.
- **D2 — API shape.** (a) keep `ng_getDisplayEntryBounds(entry_idx)` as a shim
  forever, or (b) migrate all 5 callers to a `DisplayObject*`/`MovieClip*` API and
  delete the entry_idx encoding + `getDisplayEntryIdxForMC` +
  `ng_findDisplayEntryIdxWithParent` (if no other users). Recommendation: **(b)**
  — it's the only thing that fixes limitation #2, and it removes a confusing
  encoding. Verify no other consumers of the encoding first.
- **D3 — twips↔pixels & rounding.** Legacy returns px floats with per-corner
  float rounding; the engines return twips. The conversion point and rounding
  mode (`round(x*20)/20` vs Ruffle truncation) materially affect `_width`/`_height`
  outputs. Must be chosen to minimize trace-suite churn; treat as the
  highest-risk detail.

## Implementation phases

- **P0 — confirm inventory.** Grep for every reader of `entry_idx`-encoded values
  and of all four engines; confirm the 5-caller list is complete and nothing else
  depends on the 2-level encoding. (Largely done in this doc; re-verify before P2.)
- **P1 — introduce the unified local-bounds helper** (`ng_localBoundsOfDL` or reuse
  `ng_computeBoundsFromDL`), twips out. No caller changes yet. Build all modes.
- **P2 — migrate callers one at a time**, each its own commit, validated before the
  next:
  1. tag_stubs.c:2206 (clone width/height) — lowest blast radius.
  2. action.c:9061 (`transform.pixelBounds`) + 69619 (focusrect).
  3. action.c:26787/26897 (`mcGetOriginalBounds`/`mcGetEffectiveSize`) — **highest
     risk; gates `_width`/`_height` everywhere.**
- **P3 — delete legacy** `ng_getDisplayEntryBounds` and (per D2) the entry_idx
  encoding helpers once unreferenced.
- **P4 — consolidate `_fp16`/`_matrix`** per D1.

## Validation strategy

Local gates (per CLAUDE.md: individual tests only, never full suites locally):
- Pong: paddle clamp still `[25,375]`, keyboard up/down full range (`pong_paddle_keys.py`),
  gameplay renders (`pong_gameplay.py` DL has depths 7/9/11).
- wasm probes 8/8; DJ menu/info + Snake title/gameplay/keyboard intact;
  DJ divergence trace 407=407.
- Targeted single tests exercising the feature surface (run with `--test=NAME` and
  `--mode=graphics` where relevant): anything touching `_width`/`_height`,
  `getBounds`/`getRect`, `hitTest`, `transform.pixelBounds`, and nested/rotated
  sprites. **Build the explicit list in P0** from the avm1/gnash/shumway suites.

CI gates (the real coverage — user-dispatched):
- **Graphics-native suite** (`gh workflow run ruffle-tests.yml … -f mode=graphics`)
  — currently 948/1125; must not regress.
- **Trace suite** (NO_GRAPHICS) — `ng_getDisplayEntryBounds` compiles here too, so
  `_width`/`_height`/getBounds trace expectations are on the line.
- Old hand-written suite (graphics tests) via its CI.

Land each P2 step, dispatch CI, react to pixel/value diffs before proceeding.
Expect rounding-driven 1-twip diffs (D3); decide per-diff whether to match the
new (correct) value or tune the conversion.

## Risks

- **Precision churn.** `_width`/`_height` rounding shifts could move many trace
  expectations by ±1 twip. Mitigation: phase P2.3 isolated; compare against the
  `_matrix` path getBounds already uses (same arithmetic ⇒ minimal surprise).
- **Shared across 3 build modes.** A regression hits trace + graphics-native +
  browser at once. Mitigation: per-caller commits + CI between.
- **Hidden encoding consumers.** If something other than the 5 sites relies on the
  2-level `entry_idx`, deleting it breaks them. Mitigation: P0 grep gate.

## Rollback

Each phase is an independent commit on master (trunk-based). Revert the offending
P2 commit; the shim (D2a) or the prior caller form is restored without touching
the others.

## Decisions log

User directives (2026-05-28), to apply when implementing:
- **Accuracy target:** match **official Flash behavior where it is known**; fall
  back to **Ruffle behavior** only where Flash's is unknown/unspecified. (Refines
  D1/D3: prefer whichever of `_fp16`/`_matrix` + rounding reproduces Flash; use
  Ruffle's truncating math as the proxy when Flash is unknown.)
- **Proper fix, not a temporary patch** → resolves **D2 = (b)**: migrate all
  callers to a `DisplayObject*`/`MovieClip*` API and delete the `entry_idx`
  encoding; no permanent shim. (The `66b4ddc07` one-line band-aid is superseded
  by this work.)
- **Clean up unnecessary code:** delete the legacy `ng_getDisplayEntryBounds` and
  now-dead encoding helpers (`getDisplayEntryIdxForMC`,
  `ng_findDisplayEntryIdxWithParent`, if unreferenced after migration), and
  consolidate `_fp16`/`_matrix` to one engine (D1).

Process directives:
- **Establish a full-CI baseline BEFORE implementing**, in **both** `no-graphics`
  and `graphics` modes (done at the end of the planning session via the pipeline
  handoff). Record the baseline pass counts here once known.
- **Implement the plan in a fresh session** (this planning session only writes the
  plan + captures the baseline).

### CI baseline (current master @ `dbbac2761`, pre-refactor)

**no-graphics** (run 26604640699, completed success; diff vs 2026-05-25 baseline `fc1fed4aba95`):

| Suite | Passing | Total |
|---|---|---|
| avm1 | 614 | 673 |
| from_shumway | 73 | 92 |
| from_shumway/avm1 | 46 | 47 |
| from_gnash/actionscript.all | 124 | 243 |
| from_gnash/misc-ming.all | 66 | 110 |
| from_gnash/misc-swfmill.all | 19 | 20 |
| from_gnash/misc-mtasc.all | 7 | 9 |
| from_gnash/misc-swfc.all | 8 | 19 |

Only delta vs the 2026-05-25 baseline: **actionscript.all −4** (`delete-v5/v6/v7/v8`,
60/60→42/61) plus avm1 added `delete2`. **Root cause: stale local fixtures +
a real upstream test update — NOT a code regression and NOT this session's
work.** CI runs `ruffle-tests/download_tests.sh` every run, so it tests against
the latest ruffle-rs/ruffle fixtures; the local checkout was stale (`delete-v5`
expected was 60 lines locally, 61 upstream; `delete2` didn't exist locally).
After running `download_tests.sh avm1 from_shumway from_gnash`, local reproduces
the CI failures exactly. The actual gap is **one missing trace line**: the
updated `delete.as` expects Flash's warning `"Parameters of primitive types are
no longer coerced into the required type - Object."`; we don't emit it, so
output is shifted by one line (the other 18 "diffs" are just the off-by-one
alignment). Pre-existing `delete`-opcode diagnostic gap, surfaced by the upstream
update; unrelated to the bounds work. Flag for a separate fix. **Process note:
run `download_tests.sh` locally before the implementation session so local
matches CI.**

**graphics** (run 26605500025, completed success; offscreen Dawn):

| Suite | Passing | Total |
|---|---|---|
| avm1 | 614 | 673 |
| from_shumway | 73 | 92 |
| from_shumway/avm1 | 46 | 47 |
| from_gnash/actionscript.all | 122 | 243 |
| from_gnash/misc-ming.all | 65 | 110 |
| from_gnash/misc-swfmill.all | 19 | 20 |
| from_gnash/misc-mtasc.all | 7 | 9 |
| from_gnash/misc-swfc.all | 8 | 19 |

Deltas vs the previous graphics baseline:
- **Regressions:** actionscript.all −4 (`delete-v5/v6/v7/v8`) — same stale-fixture /
  upstream-`delete.as`-update cause as no-graphics; not a code regression.
- **Improvements** (from the 2026-05-27/28 nested-button + native-objects work,
  not the bounds work): `native_objects_swf6` segfault→output_mismatch
  (1/115→114/115); `ButtonEventsTest` segfault→**ruffle_matched** (40/679→676/679);
  `ButtonPropertiesTest` segfault→ruffle_matched.

**Bottom line for the refactor:** no graphics or trace regressions attributable
to this session's three commits (frame-entry gate, paddle play/stop, bounds
recursion). The only red is the upstream-`delete` fixture update. This is the
clean pre-refactor baseline; the bounds work must hold every passing count above
(especially the `_width`/`_height`/getBounds/hitTest-adjacent tests) and may
*improve* nested-sprite bounds cases.

---

## EXPANDED SCOPE + decisions (2026-05-28, implementation session)

### Decisions resolved with the user
- **D1 — canonical engine = `_matrix` (double).** `ng_computeBoundsFromDL_fp16`
  is **already dead** (only an unused `extern` decl at action.c:65881, zero call
  sites; getBounds uses `_matrix`). Delete `_fp16`; standardize on `_matrix`.
- **D2 = (b)** — pointer/`MovieClip*` API; delete the `entry_idx` encoding.
- **D3 — return twips (double).** New helpers return twips; each caller rounds at
  its own boundary exactly like getBounds (`round(twips)/20.0`). This removes the
  lossy px→twip float round-trip the current bounds callers do (their own
  comments complain about it).
- **Helper shape** — twips out + **extract** getBounds' MC→display-list tree walk
  into a shared resolver (verbatim/behavior-preserving), so all callers gain the
  arbitrary-depth resolution.
- **Cleanup scope (user expanded):** *also* migrate the matrix/CT/filter
  accessors off `entry_idx` and **fully delete the encoding** — not just the
  bounds engine.

### Full `entry_idx` consumer inventory (P0 — complete)

The encoding `(parent_d<<20)|child_d` (2-level cap) is the currency of an entire
accessor family, all funnelling through `ng_entry_to_obj` (duplicated in
**tag_stubs.c:176** and **shape_hit_test.c:41**) — *except* the depth-keyed
filter side-tables. Every consumer:

| Accessor (def) | Reads | Caller(s) in action.c | Pointer-native? |
|---|---|---|---|
| `ng_getDisplayEntryBounds` (tag_stubs.c:1467) **legacy bounds** | composes child DL | 9061, 26787, 26897, 69619; tag_stubs.c:2206 | → replace w/ `ng_localBoundsOfDL` |
| `ng_getMatrixFromEntry` (tag_stubs.c:1335) | `obj->transform_id` | 8452 (`getLocalMatrixForMC`) | yes |
| `ng_getMatrixFromEntry_render` (shape_hit_test.c:68) | `obj->transform_id` | 8513 (`getLocalMatrixForMC_render`) | yes |
| `ng_getCTFromEntry` (tag_stubs.c:1351) | `obj->cx_*` | 8571 (`getLocalCTRaw`) | yes |
| `ng_setCTOnEntry` (tag_stubs.c:1364) | `obj->cx_*` | 8613 (`setLocalCTRaw`) | yes |
| `ng_getDisplayEntryFilterData` (tag_stubs.c:1436) | `obj->filter_*` (own inline decode, **opposite** bit convention!) | 50214 | yes |
| `ng_getExtFilterData` (tag.c:7971) | **depth-keyed side-table** `g_ext_filters` | 50114 | **no** — flat depth |
| `ng_getFilterListData` (tag.c:8100) | **depth-keyed side-table** `g_filter_lists` | 49939 | **no** — flat depth |

All matrix usage funnels through `getLocalMatrixForMC` / `_render` (2 fns); all
CT through `getLocalCTRaw` / `setLocalCTRaw` (2 fns); filters through one region
(`getDisplayEntryIdxForMC` computed once at 49936, reused at 49939/50114/50214).
`ng_findDisplayEntryIdx` (root-only) only used by the two bounds sites
(26783/26892); deletable after they migrate.

### Filter-storage finding (constrains the filter migration)

`ng_getExtFilterData`/`ng_getFilterListData` read **flat depth-keyed** side-tables
populated by the tag parser (`tagBeginFilterList`/`tagSetFilter`, keyed by a root
placement `depth`). They are *not* `DisplayObject`-field reads, so they can't take
a bare pointer. They also key on `entry_idx & 0xFFFFF`, so for **nested** MCs
today's lookup uses child-within-parent depth against a root-depth table → effectively
never matches (filters only resolve at root level today; worse, a coincidental
root-depth collision is a latent false-positive).

**Resolution (behavior-preserving, no tag-parser rewrite):** the resolver yields a
`DisplayObject*`; derive a flat root depth via `ng_objRootDepth(obj)` = `obj -
display_list` when `obj` lies within `[display_list, display_list+max_depth]`,
else `(size_t)-1`. Pass that depth to depth-keyed filter accessors
(`*ByDepth`); skip the lookup when `-1`. Root MCs match as before; nested MCs get
no filter (matches today, and removes the latent false-positive — watch CI for any
filter test that relied on the collision).

### Target API
- action.c: `static DisplayObject* resolveMCDisplayEntry(MovieClip* mc)` — MC's
  **own** entry, arbitrary depth via name-chain walk; NULL for root/dynamic/not-found.
  `static int resolveMCDisplayList(MovieClip*, DisplayObject** dl, size_t* max)` —
  the MC's **children** DL (entry->sprite_display_list, or root display_list for
  root MC), extracted verbatim from getBounds 65889–65935.
- tag_stubs.c / shape_hit_test.c: pointer-form `ng_getMatrixFromObj[_render]`,
  `ng_getCTFromObj`, `ng_setCTOnObj`, `ng_getObjFilterData`, plus
  `ng_localBoundsOfDL(dl, dl_max, double* xmin,ymin,xmax,ymax)` (twips, == `_matrix`
  identity) and `size_t ng_objRootDepth(DisplayObject*)`.
- tag.c: `ng_getExtFilterDataByDepth` / `ng_getFilterListDataByDepth` (flat depth).

### Revised phasing (each its own commit; CI both modes between P2 steps)
- **P1** — add resolvers + pointer-form accessors + `ng_localBoundsOfDL` +
  `ng_objRootDepth`; no caller changes. Build all 3 modes.
- **P2a** — clone width/height (tag_stubs.c:2206) → `ng_localBoundsOfDL`.
- **P2b** — `transform.pixelBounds` (9061) + focusrect (69619) → `ng_localBoundsOfDL`.
- **P2c** — `mcGetOriginalBounds`/`mcGetEffectiveSize` (26787/26897) — **highest bounds risk** (`_width`/`_height`).
- **P2d** — matrix accessors: `getLocalMatrixForMC` + `_render` → resolver + `*FromObj`.
- **P2e** — CT accessors: `getLocalCTRaw`/`setLocalCTRaw` → resolver + `*FromObj`/`*OnObj`.
- **P2f** — filter accessors → resolver + `ng_objRootDepth` + `*ByDepth` / `ng_getObjFilterData`.
- **P3** — delete `ng_getDisplayEntryBounds`, `ng_computeBoundsFromDL_fp16`,
  both `ng_entry_to_obj`, `getDisplayEntryIdxForMC`, `ng_findDisplayEntryIdxWithParent`,
  `ng_findDisplayEntryIdx` (verify unreferenced), and old `*FromEntry`/`*OnEntry` decls.
