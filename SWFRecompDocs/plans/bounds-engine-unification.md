# Bounds engine unification — Flash-accurate `_width`/`_height`/getBounds/hitTest

Status: **PLANNING** (no code yet). Created 2026-05-28.

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

### CI baseline (current master, pre-refactor)
(to be filled from the pipeline run)
- no-graphics: _pending_
- graphics: _pending_
