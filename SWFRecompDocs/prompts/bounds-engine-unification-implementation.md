# Next-session prompt: implement the bounds-engine unification

## Goal

Make `_width`/`_height`, `getBounds`/`getRect`, hit-testing, `transform.pixelBounds`,
and concat-matrix bounds all go through **one** Flash-accurate bounds engine.
Retire the legacy `ng_getDisplayEntryBounds` (2-level nesting cap;
scale+translate-only child composition that ignores rotation/skew) in favour of
the already-validated pointer-recursive, full-matrix engine that `getBounds`
already uses. **Match official Flash behavior where it is known; fall back to
Ruffle behavior only where Flash's is unknown.** This is a **proper fix, not a
temporary patch** — migrate callers and delete the dead code, don't leave a
permanent shim.

## Read first

1. **`SWFRecompDocs/plans/bounds-engine-unification.md`** — the full plan: engine
   inventory table, the 5 legacy call sites with their contracts, the `entry_idx`
   encoding and its limits, open decisions D1–D3, the phased migration, the
   validation strategy, and the **pre-refactor CI baseline** (the pass counts you
   must hold). This prompt is the short version; the plan is authoritative.
2. Memory `graphics_tags.md` → "Nested-sprite bounds recursion" section and the
   "Drawing-API getBounds quirk" notes (Flash expands stroke by FULL thickness;
   `varToDoubleSWF` for Object args; getBounds precision is finicky).
3. `CLAUDE.md` — build commands, "never run full suites locally" rule, the
   accepted-diffs / Ruffle-vs-Flash docs.

## Why this exists

The Pong paddle-keyboard bug (`66b4ddc07`) was a one-line band-aid: `paddle._height`
returned the full-stage background bounds (401px) instead of the paddle's own
~50px because the legacy engine's nested recursion read the wrong display list.
The band-aid fixed only the 2-level case. The legacy engine still can't recurse
3+ deep, can't even *address* a 3-deep MC, and drops rotation/skew on nested
children. This task replaces it properly.

## Prerequisites (do before coding)

1. **`bash ruffle-tests/download_tests.sh avm1 from_shumway from_gnash`** — refresh
   local fixtures so local matches CI (CI downloads fresh upstream tests every
   run). Without this, `verify_output.py --test` lies (stale `output.txt`).
2. **Resolve D1–D3** in the plan (recommendations are in the decisions log;
   confirm with the user if unsure):
   - D1: standardize on `ng_computeBoundsFromDL_matrix` (double; the path
     `getBounds` already uses and the graphics suite validates) unless a measured
     trace delta justifies the `_fp16` (Ruffle-truncating) variant.
   - D2 = (b): migrate all callers to a `DisplayObject*`/`MovieClip*` API; delete
     the `entry_idx` encoding + `getDisplayEntryIdxForMC` +
     `ng_findDisplayEntryIdxWithParent` if unreferenced after migration.
   - D3: pick the twips↔pixels conversion + rounding to minimize trace churn
     (highest-risk detail; the legacy API returns px floats, the engines return
     twips).

## The engines (all in `SWFModernRuntime/src/libswf/tag_stubs.c`; line numbers drift)

- `ng_getDisplayEntryBounds(size_t entry_idx, float* out…)` — **legacy, to delete.**
  Returns local bounds in **pixels**.
- `ng_computeBoundsFromDL_matrix(DisplayObject* dl, dl_max, double a,b,c,d,tx,ty, …)`
  — **the good one** (double, full matrix, arbitrary depth, reads cached
  `child->place_*`). Returns **twips**. `getBounds` (action.c, ~`ng_computeBoundsFromDL_matrix`
  call) uses it with an identity matrix to get local bounds.
- `ng_computeBoundsFromDL_fp16(…)` — Ruffle-exact Fixed16 truncating variant
  (reads `transform_data[tid]`). Consolidate per D1.
- `ng_computeBoundsFromDL(dl, dl_max, out…)` — identity-matrix wrapper over `_matrix`.

## The 5 legacy call sites to migrate (in `action.c` unless noted)

All want the queried object's **local** bounds (its own transform NOT applied —
each caller applies its own/world matrix) in **pixels**:

1. `mcGetOriginalBounds` (~26787) — natural unscaled bounds; **feeds `_width`/`_height`**
   (`mcGetEffectiveSize`), `_xscale`/`_yscale` setters, getBounds fallback. **Highest risk.**
2. `mcGetEffectiveSize` matrix-path (~26897) — same family.
3. `transform.pixelBounds` getter (~9061) — gated `NO_GRAPHICS || OFFSCREEN_RENDER`.
4. focusrect world-bounds helper (~69619).
5. `tag_stubs.c` duplicateMovieClip clone width/height (~2206) — root-depth source.

Note: `mcGetEffectiveSize` already applies the MC's OWN matrix via `getLocalMatrixForMC`
+ corner transform, so the helper must return children-composed LOCAL bounds —
exactly `ng_computeBoundsFromDL_matrix(dl, identity)`.

## Suggested phasing (each its own commit; CI between)

- **P0** — grep gate: confirm nothing outside the 5 sites reads the `entry_idx`
  encoding or the legacy fn. Build the explicit local test list (tests touching
  `_width`/`_height`/getBounds/getRect/hitTest/`transform.pixelBounds`/nested+rotated
  sprites) from the avm1/gnash/shumway suites.
- **P1** — add the unified local-bounds helper (or reuse `ng_computeBoundsFromDL`),
  twips out; no caller changes. Build all three modes.
- **P2** — migrate callers, lowest-blast-radius first: (1) clone width/height →
  (2) pixelBounds + focusrect → (3) `mcGetOriginalBounds`/`mcGetEffectiveSize`
  (the `_width`/`_height` path — most precision-sensitive).
- **P3** — delete legacy `ng_getDisplayEntryBounds` + dead encoding helpers.
- **P4** — consolidate `_fp16`/`_matrix` per D1.

## Validation

- **Local (per CLAUDE.md: individual tests only):** Pong paddle clamp `[25,375]` +
  full-range keyboard (`tools/browser-test/baseline-probes/pong_paddle_keys.py`),
  Pong gameplay DL depths 7/9/11 (`pong_gameplay.py`); wasm probes 8/8
  (`tools/wasm_probe_runner.py`, rebuild probes with `build_wasm_probes.sh --force`);
  DJ menu/info + Snake title/gameplay/keyboard baseline probes; DJ divergence
  407=407 (`tools/divergence/divergence_test.py … --skip-ruffle`); plus the P0
  targeted `--test=NAME` list (use `--mode=graphics` where relevant).
- **CI (the real coverage):** follow `.claude/pipeline-handoff.md` to commit/push/
  trigger/watch/merge/analyze, in **both** `no-graphics` and `graphics` modes, after
  each P2 step. **Hold every passing count in the plan's CI baseline.** Nested-sprite
  bounds cases may *improve*; investigate any change that isn't a clear improvement.

## Out of scope

- The `delete-v5..v8` / `delete2` red (a missing primitive-coercion warning line
  from an upstream `delete.as` update) — separate `delete`-opcode fix, not bounds.
- Nesting deeper than the tests actually exercise — the `_matrix` engine already
  handles arbitrary depth, so this falls out for free; don't over-engineer beyond it.

## Pitfalls

- `tag_stubs.c` compiles in **all three** build modes (NO_GRAPHICS, OFFSCREEN_RENDER,
  browser-WASM) — a regression hits trace + graphics-native + browser at once.
- Units: legacy = px float, engines = twips. Convert at the boundary (`/20`).
- Rounding shifts can move `_width`/`_height` trace expectations by ±1 twip; the
  `_matrix` engine matches what getBounds already does, so prefer it to minimize
  surprise, and diff carefully (D3).
- Semantics: return LOCAL bounds (queried object's own transform excluded).
