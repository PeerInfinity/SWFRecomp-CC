# Runtime fix: AS `_alpha` on dynamic/attached clips now renders (browser-WASM)

**Date:** 2026-06-12. **Trigger:** the dj-loader 3.2 re-test — coins didn't
dim on live collection in-app while Ruffle dimmed them; user decision: fix
the runtime, not work around it. The loader's `_alpha`-based visual design
is unchanged (the increment-3-fixes state stands).

## The bug

Runtime `_alpha` writes on dynamically created clips never reached the
renderer in browser-WASM:

1. The `_alpha` setters stored `mc->alpha` + `as_set_flags|=32` and synced
   the ng display lists — but that sync is `NO_GRAPHICS || OFFSCREEN_RENDER`
   only; the browser arm had NO consumer of `mc->alpha` at all.
2. `compose_children` (tag.c) overlaid AS-set SPATIAL state onto children but
   never honored a child's own color transform, and for **attachMovie'd**
   children the entry it iterates is a SEPARATE struct from `mc->display_obj`
   (standalone allocation, per `build_attached_mc_local_xform`'s own docs) —
   so even a write-through to the display object couldn't reach the render.
3. Drawing-API clips (`createEmptyMovieClip` + beginFill) render via
   `fillDrawingInfos` with `cxform_id = 0` hardcoded — no alpha channel at
   all.

## The fix (shared graphics code, all render tiers)

- `mcSyncAlphaToDisplayObj` (action.c): `_alpha` setters write through to
  `mc->display_obj` (`cx_aa` + `cx_overridden`), initializing zeroed RGB
  multipliers to identity first (ng_attachMovie entries are zero-initialized,
  unlike root placements which run `init_cx_fields` — without this the clip
  would render black).
- `compose_children` (tag.c) now applies a child's OWN runtime cxform: from
  the entry's cx fields when `cx_overridden` (timeline children — their
  `display_obj` IS the entry), or an alpha-only cxform from the matched MC's
  `mc->alpha` for attachMovie'd children (`build_attached_mc_local_xform` now
  also returns the matched MC — the same MC-state channel the spatial overlay
  already used). A per-tick dynamic cxform slot is allocated and propagated
  to the child's subtree via the existing inherit mechanism (channel-true
  parent×child composition remains the pre-existing TODO).
- `fillDrawingInfos` (action.c): folds `mc->alpha` into the flat fill/stroke
  alphas when AS set it (equivalent to an alpha-only cxform for solid colors;
  gradient/bitmap drawing fills still TODO).

## Verification

- Deterministic native captures (new `run_native.py --capture-ticks`): the
  dj_loader region_4_4 run at tick 75 shows the live-collected coin rendered
  FAINT in place, plus a side-by-side full/`_alpha=25` test pair (coin
  sprites AND drawing squares) — full bright, dim faint.
- Browser-WASM (the tier the bug was reported on): the same test pair
  renders full + faint; dim doors/dim drawing squares confirmed in the real
  flow. Ruffle unaffected (its own player).
- The loader gained a DBG-gated `placeAlphaTestClips()` fixture (side-by-side
  full/dim attached coins + drawing squares) and `run_browser.js` gained
  `SHOT_ON_REGEX`/`EVENT_SHOT_DELAY` (event-driven screenshots) — both kept
  for future visual-runtime probes.
- Full regression gate: ruffle-tests CI in BOTH modes (graphics mode runs the
  image comparisons over the whole suite).

## ⚠ AP-side sync

`dj_swf_bridge.js` and the encoder are UNCHANGED, and the loader is
functionally identical (DBG fixture only) — but the **runtime changed**, so
rebuild your local production tier from this commit
(`build_test.sh flasharchive/Doodle_Jump_loader wasm --graphics --clean`)
and re-copy `loader_bytecode.bin` (rebuilt, DBG off). Live-collection coin
dimming should then work in-app; the increment-3 list is fully closed.

## Discovered along the way (noted, not chased)

- Late `attachMovie` from the injected clip's enterFrame renders with a
  1-2 tick delay in browser-WASM (native renders the same attach
  immediately). Cosmetic-scale; not investigated.
- The earlier "name lookup of dynamic clips fails on swfrecomp" finding
  (increment-3 fixes) stands; reference registries remain the right pattern.
