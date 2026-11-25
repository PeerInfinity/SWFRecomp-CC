# s28 wave 2: `w2-occupied-depth`: Flash's SWF-5 keep-both PlaceObject rule, and dropping Ruffle's warning line

Cloud worker, 2026-11-25. Base `origin/master` `295a7e077`. Ruffle upstream at download time: master. The download
log prints no SHA; `git ls-remote` shortly after the download gave `d2a801a98`. Graphics runs are on lavapipe.
`place_object_test`'s *before* render reproduces w1's CI-identical numbers exactly (16 342 / 8 384 px vs the Flash
root captures, the same rows w1 proved md5-identical to CI's actual PNG).

**New files** (all in this commit):
- `SWFRecompDocs/plans/session28-fanout-reports/w2-occupied-depth-report.md` (this file)
- `SWFRecompDocs/plans/session28-fanout-reports/w2-occupied-depth.patch`
- `ruffle-tests/tests/swfs/regression/avm1_place_occupied_depth_swf5/`: `create_test_swf.py`, `test.swf`,
  `test.toml`, `output.txt`, `output.expected.png`. **The golden is HELD**: the outputs are a SWFRecomp placeholder
  until FLASH replaces them (see LOCAL ORACLE REQUESTS).

**Edited (docs / lists):** `RUFFLE_VS_FLASH_DIFFERENCES.md` (one new entry at EOF), `regression/README.md` (one row),
`render_canary_tests.txt` (one covering member at EOF).

## Verdict: GO

| Item | Verdict | Flips |
|---|---|---|
| SWF ≤ 5 keep-both (newcomer behind; both render and both resolve by name) | **GO, landed** | trace `place_object_test` RM → **pass** (== FP32) |
| Drop `Warning: Failed to place object at depth N.` (all 3 printf sites, both modes) | **GO, landed** | `place_object_test2` RM → **pass** (with the Ratio fix below). Losses below are held for flash_fixes |
| Ratio gate missing the same-char forward-replace refusal (found here) | **GO, landed** | needed for `place_object_test2` (frames 4–5) |
| `shape_test` pixel gain (w1 priced −1.8k px) | **REFUTED** | net **+206 px** worse vs Flash; see §3 |
| `path_format_test` | stays RM (20/27 lines, was 0/27) | 5 unrelated frame-label path failures; new lead 1 |

## 1. EXPECTED-FLIP LEDGER (for the coordinator's CI check)

Measured A/B on this box: clean `origin/master` vs this patch, both modes. Graphics and no-graphics are identical on
every row below.

### Trace

| test | before | after | note |
|---|---|---|---|
| `from_gnash/misc-ming.all/place_object_test` (SWF 5) | ruffle_matched (0/12) | **pass** (12/12) | == FP32 `place_object_test_v5` capture |
| `from_gnash/misc-ming.all/place_object_test2` (SWF 6) | ruffle_matched (0/19) | **pass** (19/19) | == FP32 capture |
| `avm1/placeobject_occupied_depth` (SWF 15) | pass | **output_mismatch** (golden has 2 warning lines) | ours == FP32 `…_v15` capture byte-for-byte. **Needs the flash_fixes entry the coordinator planned at landing** (golden minus its 2 warning lines). With it: pass |
| `from_shumway/fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` (SWF 13) | pass | **output_mismatch** (31/43) | ours == golden minus its one `Failed to place object at depth 1015.` line, byte-for-byte. **flash_fixes candidate** (FP32 capture needed to confirm; the warning is Ruffle-only on every FP32 run so far). With it: pass |
| `from_gnash/misc-ming.all/path_format_test` (SWF 6) | ruffle_matched (0/27) | ruffle_matched (20/27) | stays RM. FP32 = golden + 1 debug-player line. Our 5 residual FAILs are lead 1 |
| `from_shumway/fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (SWF 11) | pass | pass | its golden carries no warning; we never printed one there |
| `from_gnash/misc-ming.all/shape_test` (SWF 5) | pass | pass | trace unchanged |
| `regression/avm1_place_occupied_depth_swf5` (new) | (refusal output) | pass vs the HELD placeholder | |

**Net trace: +2 pass now. +4 once the 2 flash_fixes entries land; without them it is +2 / −2.**

### Pixels (image axis; no status flips)

`excess` = harness outliers. px = pixels over tol 50, counted as w1 did.

| test | excess before → after | px vs golden before → after | px vs FP32 root capture before → after |
|---|---:|---:|---:|
| `place_object_test` (`known_failure`, tol 50) | 38 238 → **7 461** | 13 981 → **3 017** | 16 342 → **5 388** |
| `shape_test` (`known_failure`, tol 50) | 15 994 → 16 137 | 7 813 → 8 019 | 8 384 → 8 590 |

Both rows stay failing against their non-Flash goldens. `place_object_test` now has both pairs drawn with the correct
stacking, and its xtrace window content == Flash (`#passed: 7`). The remaining 5 388 px vs Flash are:
- the tie-rule stroke offsets (sibling `n-stroke-snap`);
- the black squares' red outline that Flash draws;
- xtrace glyph raster.

**Swap status for the deferred `place_object_test` flash_fixes swap (root capture):** 5 388 px, still above the ~1k
threshold.

## 2. Mechanism (owner `file:line`)

**Choice: an "under chain", not a sub-depth key.**

`display_list` is a dense array indexed by SWF depth. Every walk (render, compose, advance, sprite init, name scans,
remove, swapDepths) indexes it directly. So any fractional or sub-depth key would have to be taught to all of those
walks.

A hidden real slot was also measured and rejected. The free slots lie above SWF depth 65535, so the root list would
grow to 131 072 × ~430 B ≈ 56 MB.

The chain instead reuses the ordinary fresh-place path for everything except "where the entry lives".

- `swf.h` `DisplayObject`: two trailing fields:
  - `ng_under`: the chain hanging off the occupant;
  - `ng_is_under`: set on the heap entry itself.
- `tag.c` `ng_keep_both_applies` / `ng_place_under_park` / `ng_place_under_restore` (new, just above
  `tagPlaceObject2`). On a refused Place (the existing Phase-3 gate in `tagPlaceObject2`, which carries all its replay
  guards) in a SWF ≤ 5 movie:
  1. Park the occupant and zero the slot.
  2. Re-enter `tagPlaceObject2` with the same arguments. This is the normal fresh place: name, MC, eager sprite
     frame 0, child list.
  3. Finish `process_sprite_init_at_depth` while the newcomer still owns the slot.
  4. Move the newcomer into a heap `DisplayObject` and rebind its MC's `display_obj` (`child_mc_cache` by name).
  5. Restore the occupant and append the newcomer at the chain tail, so later newcomers sit deeper.
- `tagPlaceObject2Ratio`: the same keep-both in its Phase-3 gate. That gate lacks `tagPlaceObject2`'s replay guards,
  so keep-both there also requires `!g_loopback_replay && !catch_up_backward`. A replay keeps the refusal.
- **Render:**
  - `render_display_list`, and the root loops in `tagShowFrame` / `tagRerenderFrame`: draw `ng_under` as a 1-element
    list just before the occupant (after the empty-slot skip, before the occupant's clip / mask / blend handling).
  - `compose_children` composes the chain as a sibling under the same parent.
  - Root entries go through `ng_compose_root_under` (new; identity parent).
- **Attached-clip passes:**
  - `offscreen_attached_pass_member` and `render_attached_child` skip `ng_is_under` entries.
  - Without this, the heap entry (outside `display_list`'s address range) was drawn a second time as a standalone
    attached clip at the origin. It was measured on `shape_test` as a stray green L at (10,10).
- **Name lookup** (`action.c` `actionGetVariable`, the CI-mode root bare-name branch, `ng_findDisplayEntryByName`
  miss):
  - `ng_findUnderEntryByName` (new, `tag.c`) searches the chains.
  - A non-scriptable (shape) match aliases `_level0`, like a slot shape.
  - A sprite match resolves to its own MC.
- **Remove** (`clear_display_entry`): removing the occupant drops the whole depth. The chain's MCs are invalidated and
  `ng_under` is cleared. The heap entries are not freed, because a dead MC's `display_obj` may still be read.
- **Warning removal:** the `printf` sites in `tagPlaceObject2` (Phase-3 gate and the same-generation gate) and in
  `tagPlaceObject2Ratio` are gone. They were the only three in the runtime: `swf_core.c`, `tag_stubs.c` and `action.c`
  carry only comments. `tag.c` is shared by both modes, and the no-graphics A/B confirms it.
- **Ratio same-char fix** (`tagPlaceObject2Ratio` Phase-3 gate):
  - It now also refuses a same-character Move=0 Place from a later frame.
  - This is `tagPlaceObject2`'s `ng_same_char_forward_replace` predicate plus the replay guards.
  - Before, gnash `place_object_test2` frame 4 (`static_mc4`, char 4 onto char 4) fell through and renamed the
    occupant; FP32 and Ruffle both refuse it.

**Functions touched:**
- `tag.c`: `tagPlaceObject2`, `tagPlaceObject2Ratio`, `clear_display_entry`, `compose_children`,
  `render_display_list`, `tagRerenderFrame`, `tagShowFrame`, `offscreen_attached_pass_member`,
  `render_attached_child`; new `ng_keep_both_applies`, `ng_place_under_park`, `ng_place_under_restore`,
  `ng_findUnderEntryByName`, `ng_compose_root_under`.
- `action.c`: `actionGetVariable` (one block).
- `swf.h`: `DisplayObject` (trailing fields).

None of these are sibling-map functions. `action.c` is not near `actionDispatchRootOnLoad` / `actionDispatchMCOnLoad`.

**Semantics on the pair, and what is not modelled** (no corpus row exercises these; Flash is unpinned):
- The occupant keeps the slot. `getInstanceAtDepth`, `swapDepths`, a later Move=1 modify and RemoveObject all act on
  it.
- The newcomer's MC keeps its name and AS depth (`getDepth()` == the occupant's).
- **Not modelled:**
  - hit-testing the under entry;
  - advancing a multi-frame under-sprite's timeline (it renders frame 1);
  - depth-keyed queued events for the newcomer (clip LOAD / registerClass ctor): they resolve through
    `display_list[depth]` to the occupant;
  - nested-timeline bare-name lookup (only the root branch of `actionGetVariable` searches chains);
  - an unnamed newcomer sprite. Its MC key `__anon_depth_N__` collides with an unnamed occupant's, so its MC is not
    rebound.
- **Gating:** gated on the ROOT movie's `g_swf_version`. A SWF-5 movie loaded into a v6+ host is not keep-both, and
  the reverse also holds.
- **Completion mechanism** for any of these: a Flash fixture that exercises it, then extend the chain walk at that
  site.

## 3. Refutation: `shape_test` does not gain −1.8k px

w1 priced the duplicate-depth term as "top-left green L (100–160 × 140–200) 1 800 px".

After the patch our render draws sprite 7's green L there, as Flash does. But Flash draws that L with its interior
white and the fill leaked sideways: that is w1's §6 unclosed-fill-path leak. Our closed-path L paints green where
Flash has white. The keep-both term and the §6 term overlap on the same pixels, so fixing keep-both alone nets
**+206 px** vs Flash (8 384 → 8 590), and the same against the golden.

It is a correct display-list change. The pixel residual moves to §6 (recompiler fill tessellation, sibling/unclaimed).
This is not a reason to hold: the row fails before and after, with no status move.

## 4. Gate

**Blast radius, static census.** I wrote a SWF tag walker that simulates each timeline's Place/Remove for every
downloaded corpus SWF (avm1, from_gnash, from_shumway, visual, text, fonts, plus regression). The only Move=0 Places
onto an occupied depth are exactly w1's 7 rows: 4 gnash, `avm1/placeobject_occupied_depth`, 2 shumway fuzz.
- Among the 124 SWF ≤ 5 rows, only `place_object_test` and `shape_test` hit it.
- The warning line appears in exactly 2 goldens (`placeobject_occupied_depth`, `e152812e…`) and 4
  `output.ruffle.txt` files.
- So keep-both, the warning removal and the Ratio same-char refusal cannot move any other timeline-static row.

**A/B runs (clean `origin/master` vs patch, same box):**
- **Graphics (151 tests):** gnash `misc-ming.all`, all 62 top-level tests plus the 54 nested sub-tests in
  `action_order` / `displaylist_depths` / `init_action` / `loading` / `loop` / `register_class`; the 15 avm1
  `*depth*|*place*` rows; both shumway fuzz rows; 18 `regression` rows matching `depth|place|swap|remove|v5|swf5`
  (including the new fixture).
  **Every status and every image message is identical except the ledger rows above.** The 7 "compile_fail /
  recomp_fail" rows in my logs are the container directories (and `_results`) passed as `--test`, a harness artefact
  identical in both legs. Their nested tests were run individually.
- **No-graphics:** the 7 ledger rows plus `shape_test`, the fixture, `mc_method_v5_caller_gate` (SWF 5) and
  `avm1_parent_child_modify_place`. Identical to graphics, same flips.
- **Render canary:** `render_canary.py` capture/compare over every non-`avm2/` member of `render_canary_tests.txt`.
  - Result: 149 tests / **214 PNGs, 214 IDENTICAL**, 0 differs, no trace or image status changes.
  - The 36 `avm2/` members were not run. Every render-path change is behind `ng_under != NULL` / `ng_is_under`, which
    only a SWF ≤ 5 timeline Place can set, so an AVM2 movie cannot reach them. The coordinator's CI covers them.
  - The standing set could not see this change class, so I appended `from_gnash/misc-ming.all/place_object_test`
    (tier 1) at EOF.

## 5. Not finished, and its completion mechanism

- **2 golden swaps** (`avm1/placeobject_occupied_depth`, `from_shumway/fuzz/e152812e…`): the coordinator's flash_fixes
  entries. The first needs no new capture (FP32 `…_v15` is archived and equals our output); the second needs an FP32
  run (request 2).
- **Fixture golden HELD**: FLASH request 1.
- The unmodelled pair semantics in §2: a Flash fixture each, if a corpus row ever needs one.

## New unclaimed leads

1. **`path_format_test` (SWF 6): 5 FAILs at `path_format_test.c:248/254/285–287`.** `_root.x1` / `x4..x6` read `0`
   where Flash has the frame-label strings `mc11_frame4`, `mc1_frame4..6`. A slash/dot path-format variable set from
   a nested clip's frame does not land on `_root`. It is now the row's only trace residual besides FP32's
   debug-projector line (`Parameters of primitive types are no longer coerced…`), which the golden lacks. Fixing it
   would give RM → still RM until that golden gets a flash_fixes swap (golden + the debug line? The coordinator should
   decide whether the debug-player line belongs in a golden).
2. **`shape_test` §6 unclosed fill paths** now owns the top-left L as well (see §3).
3. **`place_object_test`: Flash draws a red outline on both black squares** (visible in the root capture; ours has
   none). Unexplained; possibly the shape's line style vs our stroke emission. Worth a look by `n-stroke-snap`.

## LOCAL ORACLE REQUESTS

1. **FLASH: `ruffle-tests/tests/swfs/regression/avm1_place_occupied_depth_swf5`**, trace + image, direct pinned,
   1 tick (stage 200×100). The SWF is committed (`test.swf`; `create_test_swf.py` rebuilds it). Compare against our
   HELD `output.txt` (6 lines) and `output.expected.png` (red over black at (10,10)/(30,30), blue over green at
   (100,10)/(120,30)). Specific questions:
   - Do the shape names alias `_level0` (`sa==sb: true`)?
   - Is `ma.getDepth() == mb.getDepth()`?
   - Is `mb._x` 120?

   Replace both goldens with Flash's output and drop "HELD" from `test.toml` / the README row.
2. **FLASH: `from_shumway/fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e`**, trace, direct
   pinned, the test's `num_frames`. Expect golden minus `Warning: Failed to place object at depth 1015.`; ours equals
   exactly that. If FP32 agrees, add the flash_fixes entry.
