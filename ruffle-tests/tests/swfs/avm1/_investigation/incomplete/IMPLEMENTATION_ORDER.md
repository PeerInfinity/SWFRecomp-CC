# Recommended Implementation Order for Incomplete Plans

Last updated: 2026-03-30

## Overview

This document recommends a prioritized order for implementing the 18 incomplete plans in `_investigation/incomplete/`. Plans are grouped into tiers based on **effort vs. impact**, **dependency chains**, and **current completion state**. Within each tier, plans are ordered by recommended execution sequence.

---

## Tier 1: Close Out Nearly-Finished Work (highest ROI)

These plans are 90%+ complete. Finishing them converts partial work into fully passing tests with minimal additional effort.

### 1. BITMAP_FILTERS_MCFILTERS_PLAN (540/548 -> ~548)
- **Effort:** ~50 lines of C
- **Impact:** Closes out `bitmap_filters` test (the last 4-8 lines)
- **What remains:** Build filter ASObjects from display list data for `mc.filters[0]` getter. PlaceObject3 flags2 fix is done; just need to construct filter objects directly (skip constructor machinery, populate properties manually from display list fields).
- **Why first:** Smallest gap to close. The infrastructure (tagSetFilter, ng_getDisplayEntryFilterData) is already in place from the flags2 fix. This and BITMAP_FILTERS_PLAN share the same test.

### 2. BITMAP_FILTERS_PLAN (544/548)
- **Effort:** Low (4 remaining lines need extended display list storage)
- **Impact:** Closes `bitmap_filters` fully
- **What remains:** 4 lines requiring ColorMatrixFilter matrix, ConvolutionFilter matrix, and gradient arrays stored in display list. These are the extended filter types that tagSetFilter doesn't currently store.
- **Why second:** Depends on #1 for the mc.filters getter. The 4 remaining lines may be accepted as permanent diffs if display list extension is too invasive.

### 3. BITMAP_FILTER_CLONE_PLAN (496/548)
- **Effort:** Low priority — 52 remaining diffs are from embedded filter data (recompiler), angle precision (Ruffle artifact), and complex AS2 duck-typing
- **Impact:** Already 90.5% passing. Remaining items are diminishing returns.
- **What remains:** Phase 6 (mc.filters getter) is shared with #1 above. Remaining 52 diff lines are from unfixable causes.
- **Status:** Effectively done. Merge with #1/#2 above; no separate implementation needed.

### 4. GLOBALS_PLAN (29/31 tests passing)
- **Effort:** Low-medium for remaining actionable items (Key constants, Mouse/Accessibility methods, Transform.prototype properties)
- **Impact:** Could push `global_proto_decls` from 199/4497 to ~500+ matching lines. Won't reach 100% due to DONT_ENUM blocker.
- **What remains:** Phase 8c-4 (missing properties on Key/Mouse/Accessibility), Phase 8c-5 (property flags), Phase 8d (instance construction — blocked).
- **Why here:** Substantial partial work already invested. Adding Key constants (~20 entries) and Mouse methods (~5 methods) is straightforward and recovers dozens of lines in the proto_decls tests.

---

## Tier 2: Actionable Plans with Good Test Line ROI

These are not-yet-started or early-stage plans where the implementation is straightforward and unblocked.

### 5. NETCONNECTION_PLAN — netconnection_close only (3/39 -> ~39)
- **Effort:** ~80 lines (state machine + onStatus dispatch + method registration)
- **Impact:** 36 new passing lines from a single test
- **Dependencies:** None
- **Why here:** Highest lines-per-effort ratio of any unstarted plan. Pure state machine + callback dispatch — no external infrastructure needed. Ignore `netconnection_send_remote` (blocked on AMF/HTTP).

### 6. SOUND_LOADING_PLAN (0/4 -> ~4)
- **Effort:** ~200 lines across 4 phases
- **Impact:** 4 test lines directly (`sound_load_start` + `sound_multiple_load`), but more importantly **unlocks SOUND_DURATION_POSITION_PLAN**
- **Dependencies:** None — MP3 decoder and data embedding exist
- **Why here:** Foundation for all sound tests. The data pipeline (embedded MP3, minimp3 decoder) exists; the main work is wiring loadSound() to the data registry and simulating playback timing for onSoundComplete dispatch.

### 7. SOUND_DURATION_POSITION_PLAN (2/290 -> estimated ~200+)
- **Effort:** ~100 lines beyond SOUND_LOADING
- **Impact:** Up to 290 test lines (sound_duration_position_props), though full pass depends on precise frame timing
- **Dependencies:** SOUND_LOADING_PLAN phases 1-3
- **Why after #6:** Direct dependency. Once loadSound and onSoundComplete work, adding getPosition()/duration property getters and frame-based position tracking is straightforward.

### 8. LOADBITMAP_PLAN
- **Effort:** ~50 lines
- **Impact:** Fixes `bitmap_data_colortransform` image test (78K -> ~0 outliers)
- **Dependencies:** None
- **Note:** Per BITMAPDATA_RENDERING_PLAN, this was **already implemented** in session 2026-03-29. Check if it's actually complete before starting. If done, remove from incomplete/ or mark complete.

---

## Tier 3: Graphics/Rendering Pipeline (Image Tests)

These plans target headless image test rendering. They share infrastructure and have interdependencies. Implement as a batch.

### 9. RUNTIME_TRANSFORM_GPU_PLAN
- **Effort:** Low-medium (~45 lines: buildTransformFromMC + compose_children modification)
- **Impact:** Fixes `display_object_properties` image test, partially fixes `color`
- **Dependencies:** None
- **Why first in graphics tier:** Foundational — many image tests need runtime transform propagation.

### 10. RUNTIME_CXFORM_GPU_PLAN
- **Effort:** Low (~30 lines: cxform composition + child_mc_cache scanning)
- **Impact:** Together with #9, fixes `color` image test
- **Dependencies:** Complements RUNTIME_TRANSFORM_GPU (both needed for `color`)
- **Why together with #9:** Same rendering pipeline, same tests. Implement in the same session.

### 11. DRAWING_API_RENDERING_PLAN
- **Effort:** Low-medium (mostly investigation — infrastructure exists)
- **Impact:** Fixes `movieclip_begin_gradient_fill`, `movieclip_line_gradient_style` image tests
- **Dependencies:** None
- **Why here:** The Drawing API rendering pipeline is ~95% implemented. May just need headless guard fixes and gradient rendering verification.

### 12. RUNTIME_SETMASK_PLAN
- **Effort:** Medium (~110 lines: masked callback + stencil clear + display list extension)
- **Impact:** Fixes `mask_reapply` image test; `mask_with_drawing` and `movieclip_setmask` also need #11
- **Dependencies:** DRAWING_API_RENDERING for 2 of 3 tests
- **Why last in graphics tier:** Depends on #11 for full test coverage. Stencil infrastructure exists; main work is the host-level callback.

---

## Tier 4: Large-Scope / Framework Work

These plans have high potential impact but require significant infrastructure or have complex blockers.

### 13. FROM_GNASH_DEJAGNU_PLAN
- **Effort:** High (multi-phase: ImportAssets remapping, DoInitAction ordering, class resolution)
- **Impact:** Potentially unlocks 243 actionscript.all tests + 132 misc-ming/swfc tests
- **Current state:** Phases partially done. ImportAssets char_id remapping done but functions still not defined on `_root`. Infinite re-entry fixed. Core issue: recompiler doesn't emit ImportAssets char_id -> export_name mapping for proper character dictionary remapping.
- **Recommended approach:**
  1. **misc-mtasc `typeof` fix** (Low effort, 9 tests) — Quick win: fix `typeof(ClassName)` for AS2 `__Packages` classes
  2. **actionscript.all ImportAssets fix** (High effort, 243 tests) — Requires recompiler changes to emit char_id mappings + runtime character dictionary remapping
  3. **misc-ming/misc-swfc DoInitAction** (High effort, 132 tests) — Requires understanding inlined Dejagnu function initialization order
- **Why Tier 4:** The misc-mtasc typeof fix is quick; the rest is deep infrastructure work touching both recompiler and runtime.

### 14. BITMAPDATA_RENDERING_PLAN (5/6 image tests passing)
- **Effort:** Investigation-heavy (remaining issues are precision bugs, not missing features)
- **Impact:** Closes `bitmap_data_colortransform` (726 outliers, 2x value pattern) and `bitmap_data_copypixels` (188K outliers)
- **Why Tier 4:** The 2x value pattern in colortransform and the large copypixels gap suggest subtle premultiply/unpremultiply or rendering pipeline bugs that need deep debugging rather than feature implementation.

### 15. COPYPIXELS_ALPHA_PLAN (in progress, 188K outliers)
- **Effort:** Investigation-heavy
- **Impact:** Fixes `bitmap_data_copypixels` image test
- **Note:** Closely related to #14. Should be debugged together with the BitmapData rendering pipeline.

---

## Tier 5: Blocked or Low Priority

These plans are blocked on missing infrastructure, or their test impact doesn't justify the implementation complexity.

### 16. DISPLACEMENTMAPFILTER_PLAN (0/13)
- **Effort:** Hard (native property setter + valueOf error propagation through try/catch)
- **Impact:** 1 test, 13 lines
- **Why low:** Self-contained but low ROI. The valueOf-throws-during-setter interaction is architecturally novel and could introduce fragility.

### 17. TELLTARGET_PLAN (19/22 passing)
- **Effort:** None needed for TellTarget itself
- **Impact:** Remaining 1 failing test (`string_paths_eval`) is blocked on button dispatch bug
- **Why here:** Nothing to implement — all remaining failures are external blockers. Remove from incomplete/ and consider moving to a "completed" directory.

### 18. HIT_TESTING_PLAN (15/17 passing)
- **Effort:** None for remaining items (device fonts, curve precision are fundamental limitations)
- **Impact:** Remaining 20 diff lines in `movieclip_hittest_shapeflag` are blocked on triangulation approach and missing font outlines
- **Why here:** Same as #17 — effectively complete. The remaining failures are architectural limitations, not missing implementations.

---

## Dependency Graph

```
SOUND_LOADING (#6) ──────> SOUND_DURATION_POSITION (#7)

RUNTIME_TRANSFORM_GPU (#9) ──┐
                              ├──> color image test
RUNTIME_CXFORM_GPU (#10) ────┘

DRAWING_API_RENDERING (#11) ──> RUNTIME_SETMASK (#12)
                              ──> mask_with_drawing, movieclip_setmask

BITMAP_FILTERS_MCFILTERS (#1) ──> BITMAP_FILTERS (#2)

BITMAPDATA_RENDERING (#14) ──> COPYPIXELS_ALPHA (#15)
```

All other plans are independent.

---

## Summary Table

| Order | Plan | Current State | Effort | Lines Gained | Category |
|-------|------|--------------|--------|-------------|----------|
| 1 | BITMAP_FILTERS_MCFILTERS | 540/548 | ~50 lines | ~8 | Close out |
| 2 | BITMAP_FILTERS | 544/548 | Low | ~4 | Close out |
| 3 | BITMAP_FILTER_CLONE | 496/548 | Done (shared w/ #1) | — | Close out |
| 4 | GLOBALS | 29/31 pass | Low-med | ~300 lines in proto_decls | Close out |
| 5 | NETCONNECTION (close) | 3/39 | ~80 lines | ~36 | Quick win |
| 6 | SOUND_LOADING | 0/4 | ~200 lines | ~4 + unlocks #7 | Foundation |
| 7 | SOUND_DURATION_POSITION | 2/290 | ~100 lines | ~200+ | Dependent |
| 8 | LOADBITMAP | Likely done | ~50 lines | 1 image test | Check status |
| 9 | RUNTIME_TRANSFORM_GPU | Not started | ~45 lines | 2 image tests | Graphics |
| 10 | RUNTIME_CXFORM_GPU | Partial | ~30 lines | w/ #9: 1 image test | Graphics |
| 11 | DRAWING_API_RENDERING | Not started | Low-med | 2 image tests | Graphics |
| 12 | RUNTIME_SETMASK | Not started | ~110 lines | 3 image tests | Graphics |
| 13 | FROM_GNASH_DEJAGNU | Partial | High | 243+ tests (potential) | Framework |
| 14 | BITMAPDATA_RENDERING | 5/6 pass | Investigation | 2 image tests | Debug |
| 15 | COPYPIXELS_ALPHA | In progress | Investigation | 1 image test | Debug |
| 16 | DISPLACEMENTMAPFILTER | Blocked | Hard | 13 lines | Low priority |
| 17 | TELLTARGET | 19/22 pass | None needed | Blocked externally | Complete |
| 18 | HIT_TESTING | 15/17 pass | None needed | Blocked structurally | Complete |

---

## Recommended Session Batching

**Session A** (Tier 1 close-outs): #1 + #2 (bitmap_filters mc.filters getter + remaining 4 lines)
**Session B** (Quick wins): #5 (NetConnection close) + #4 (Globals remaining properties)
**Session C** (Sound): #6 + #7 (Sound loading + duration/position — natural chain)
**Session D** (Graphics batch): #9 + #10 (transforms + cxform — same pipeline, same tests)
**Session E** (Graphics batch): #11 + #12 (Drawing API + setMask — dependent chain)
**Session F** (Framework): #13 misc-mtasc typeof fix (quick), then assess actionscript.all feasibility
**Session G** (Debug): #14 + #15 (BitmapData precision issues — investigation session)
