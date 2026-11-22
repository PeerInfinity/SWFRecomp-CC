# w2-avm1-filters: land the AVM1 filters prototype + the two XS side bugs (GO)

**NEW FILES**
- `SWFRecompDocs/plans/session25-fanout-reports/w2-avm1-filters-report.md` (this report)
- `SWFRecompDocs/plans/session25-fanout-reports/w2-avm1-filters.patch`
  - = `git diff --binary origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <2 fixture dirs> ruffle-tests/tests/swfs/regression/README.md`.
  - Base `d08236ee`. `git apply --check -R` passes against this branch.
  - `--binary` is REQUIRED: the patch carries the fixture SWFs and PNGs.
- `ruffle-tests/tests/swfs/regression/avm1_runtime_filters_cm_bitmap/`: `create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt`, `output.expected.png`.
- `ruffle-tests/tests/swfs/regression/avm1_nested_po3_filters/`: the same five files.
- `SWFRecompDocs/plans/session25-fanout-reports/w2-avm1-filters-probe/` (evidence, NOT fixtures):
  - `mkside.py` + `side.swf`: the side-bug probe.
  - `side.{master,w1only,full}.png`.
  - `sweep.sh`, `sweep.{before,after}.txt`.
  - `scan_cm.py` + `scan_cm.txt`.
  - `canary.compare.txt`.

**Environment:**
- Cloud box. `SETUP_STATUS` apt / Pillow / Dawn all OK (lavapipe).
- `download_tests.sh avm1 avm2 visual from_shumway from_gnash fonts text` on 2026-11-22. Upstream Ruffle master `3ac8dcb07`.
- **Fidelity:** `from_shumway/bitmapbuttons` renders md5 `a806ccf6` on both legs. That equals the CI actual, as the w1
  established. So the local image verdicts are CI-grade.

## 0. Verdict and EXPECTED-FLIP LEDGER

**GO. One patch: w1 items 1 + 2 + 3a + 4, plus side bugs (a) and (b).**

| axis | expected on CI |
|---|---|
| corpus trace | **0 flips** (both modes) |
| corpus pixel | **0 flips** |
| `regression/avm1_nested_po3_filters` | NEW. Trace: **mismatch → pass** (8 diff lines → 0), both modes. Image: **fail (7131 outliers) → pass (0, max diff 0)** |
| `regression/avm1_runtime_filters_cm_bitmap` | NEW. Trace: **pass on both legs** (the getter was already right). Image: **fail (19584 outliers) → pass (0, max diff 0)** |

Both fixtures fail on clean master and pass with the patch. The image tolerance is 1 with max_outliers 0. That matches the
sibling `avm1_runtime_filters`. Our render equals the Ruffle golden byte-for-byte (max diff 0).

## 1. What landed (functions touched)

### `SWFRecomp/src/swf.cpp`
- **New `struct PlaceCmCompose`** (side bug a).
  - Each PlaceObject3 ColorMatrixFilter is accumulated in list order (`apply`).
  - One cxform is emitted after the list: `cx ∘ CM_n ∘ … ∘ CM_1` (`emit`). The terms are the placement
    CXFORMWITHALPHA's raw mult/add, hoisted as `po_cx_*` in the root arm and `sp_cx_*` in the sprite arm.
  - Before: in the root arm each CM minted its own slot and `cxform_id = color_matrix_cxform_id`. The CM REPLACED the
    placement cxform, and the last CM won.
  - For a single CM with no cxform, the emitted literals are identical to the old ones: `visual/filters/color_matrix` is
    md5-identical.
- **New `static emitSpriteFilterList()`** (w1 item 1).
  - It is called from the DefineSprite PlaceObject3 arm. It emits the sprite placement's whole filter list into a
    per-site `static FilterListData`.
  - The sprite-arm ColorMatrix case now folds into the placement cxform through `PlaceCmCompose`. Before, it did
    `cur_pos += 80`.
- **Sprite arm, GradientGlow / GradientBevel scalar quality:** `& 0x1F` → `& 0x0F` (side bug b).

### `SWFModernRuntime/src/libswf/tag.c`
- New: `cxform_original_id`, `obj_runtime_cm`, `cx_set_identity`, `root_entry_runtime_cxform`, `tagBeginFilterListAt`.
- Split into a wrapper over `*_base`:
  - `root_seed_cxform` (over `root_seed_cxform_base`);
  - `filtered_object_cxform` (over `filtered_object_cxform_base`).
- Edited:
  - `compose_children`: only the w1's own-cxform runtime-CM fold (`own_rt_cm`), plus one term in the slot-mint
    condition. **The dynamic-clip arm is NOT touched**; that is `w2-dynclip-cxform`'s.
  - `dyn_filter_root_draw`: it now draws the subtree's bitmaps.
  - The runtime-cxform loops in `tagRerenderFrame` and `tagShowFrame`.
  - `tagBeginFilterList`, `filterListAppend`, `tagAddSimpleFilterHighlight`, `tagEndFilterList`: these now use the
    `g_current_filter_list` pointer instead of an index.

### `SWFModernRuntime/src/actionmodern/action.c`
- Edited: `dynSubtreeHasDrawings`, `actionSetDynamicFilterRootHook`, `actionIterateAttachedBitmaps`.
- Added: `fillAttachedBitmapInfo` and `actionIterateDynamicSubtreeBitmaps`.
- Edited: `avm1LowerFilterObject` (case 6), `avm1McHasRuntimeFilters`, `avm1ApplyRuntimeFiltersToEntry`.
- `actionGetMemberImpl`'s `filters` arm: it reads `entry->filter_chain` first.

### Headers
- `tag.h` and `action.h`: one prototype each.

**Sibling boundaries:**
- No button or mouse dispatch code is touched (`n-play-game`).
- No hunk touches `fillDrawingInfos` or the dynamic Drawing-API clip cxform (`w2-dynclip-cxform`).
- **Collision note for the coordinator:** `w2-dynclip-cxform` may edit `dyn_filter_root_draw` /
  `actionIterateDynamicSubtreeBitmaps`, or the `obj_runtime_cm` dynamic arm (w1 §3.2 step 3). Apply this patch first.

**Cleanup vs the w1 patch:**
- The "s25 prototype" comment prefixes were removed and the comments reflowed.
- The stale "filters only resolve at root level" getter comment was rewritten.
- A redundant forward declaration was dropped.
- No probes were left in the code.

## 2. Side-bug probe A/B (`w2-avm1-filters-probe/mkside.py`, graphics)

The probe builds a sprite `outer` holding three PlaceObject3s, plus the same three at root depth (y + 160):
- `cxcm`: cx (B×0.5, R+64) + [CM swap R/B];
- `cm2`: [swap, halve];
- `gg`: GradientGlow with onTop set and 2 passes.

The source fill is red.

| cell | master `a0e6bf08` | w1 prototype only `795fd22e` | this patch `6e618022` | Flash order (cx after filters) |
|---|---|---|---|---|
| nested cxcm | (255,0,0) | (0,0,255): cx lost | **(64,0,128)** | (64,0,128) |
| root cxcm | (0,0,255): cx lost | (0,0,255) | **(64,0,128)** | (64,0,128) |
| nested / root cm2 | (255,0,0) / (128,0,0): last CM only | (128,0,0) | **(0,0,128)** | (0,0,128) |
| nested gg vs root gg | differ | **still differ** (scalar quality 16+2) | **identical** | identical |
| nested row vs root row (RGB diff bbox) | differs | differs (gg only) | **None** | — |

- The root gg cell is identical on all three legs. The mask fix only changes the sprite arm.
- The expected values are my reading of the Flash order, not an oracle (LOCAL ORACLE REQUEST below).
- **Corpus reach of (a):** `scan_cm.py` over every downloaded suite found exactly one SWF with ≥2 CMs or cx+CM:
  `avm2/color_matrix_filter` (root `[CM, CM]`).
  - It is trace-only and PASSES on both legs in both modes. Its trace reads the filter objects, not the cxform.
  - No other corpus SWF has an authored CM in a sprite.
- **Reach of (b):** no corpus row has a visible sprite-nested gradient filter (w1 §3.4).

## 3. Sweeps (same box; before = clean `d08236ee`, after = this patch; `--recompile` on every row)

**29-row A/B, both modes (58 runs, `sweep.{before,after}.txt`):**
- The rows are the w1's 27 plus the 2 fixtures.
- Normalised diff: **only the two fixture rows move**, as listed in the ledger. The other two diff hunks are sort-order
  reshuffles of identical lines.
- Every other row is identical in status, diff-line count and actual-PNG md5. That includes:
  - `bitmapbuttons` failing on both legs (pre-existing, = the CI actual);
  - `MovieClip-v7`/`-v8` unchanged.
- The pass rows include `regression/avm1_runtime_filters` and the three `avm1_parent_child_*` regression rows.

**Extra row:** `avm2/color_matrix_filter` PASSES on both legs, graphics and no-graphics.

**FULL render canary** (`render_canary.py capture --recompile --timeout 5400`; the list now has 114 tests):

```
114 tests / 171 comparisons: IDENTICAL 171, DIFFERS 0, APPEARED 0, VANISHED 0
TRACE STATUS CHANGES: (none)   IMAGE STATUS CHANGES: (none)
MISSING 2 = the two new fixtures (appended after the before capture; their before is in the sweep: da3c79b6 / 6e613af6)
```

**Mode parity:**
- No hunk sits in `swf_core.c`, `tag_stubs.c` or a `NO_GRAPHICS`-only arm. The `tag.c` filter-list functions are
  compiled in all builds.
- The no-graphics leg of the sweep is clean anyway.

**Canary list:**
- Both fixtures are appended at EOF (tier 1).
- `visual/filters/color_matrix` is already a standing member (line 153), so it was not duplicated. The comment says so.

## 4. Not finished / holds (unchanged from the w1, completion mechanisms there)

- **Runtime CM on dynamic Drawing-API clips (3b) and the dynamic-clip cxform (#5):** owned by `w2-dynclip-cxform`
  (w1 §3.2). `avm1McHasRuntimeFilters` keeps a CM-only list from making a filter root, so that arc starts clean.
- **Not covered:**
  - text fields and attachMovie'd children under a dynamic filter root (4b, M);
  - Convolution, gradient ramp and AVM1 DisplacementMap (w1 §3.4/§3.5).
- **Limitation kept from the w1:** on a ROOT LEAF combining an authored cxform, a runtime filter and a post-filter CM,
  the filter colour does not get the authored cxform. There is no corpus row.
- **Approximation:** the authored and runtime CM folds lose the per-pass clamp between stacked CMs and the cxform. They
  are exact when no intermediate value leaves [0,1].

## New unclaimed leads
- None beyond the w1's list. The two XS side bugs from it are closed here.
- Lead 4 (authored Convolution renders as a blur, which is neither Flash nor Ruffle) still stands.

## LOCAL ORACLE REQUESTS
1. (Optional; it confirms side bug (a)'s order.) Ruffle exporter at `0ddd12b6a` on `w2-avm1-filters-probe/side.swf`
   (550×400, 1 frame), render only. Expected:
   - cells at (60,55)/(60,215) = (64,0,128);
   - cells at (140,55)/(140,215) = (0,0,128).

   Ruffle renders no gradient glow, so ignore the `gg` cells. If Ruffle disagrees, the compose order in
   `PlaceCmCompose::emit` is the single place to change.
