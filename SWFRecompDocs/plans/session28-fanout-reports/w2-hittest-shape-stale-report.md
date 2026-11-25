# s28 wave 2: `w2-hittest-shape-stale` report (Flash's same-frame stale bounds for `hitTest(x, y, true)`)

Cloud worker, branch `fanout/w2-hittest-shape-stale`, base `origin/master` `b771eb47`. Box: SETUP_STATUS all OK (apt,
Pillow, Dawn). Corpus: `download_tests.sh avm1 from_gnash from_shumway` on 2026-11-25 (upstream master that day; the
brief names head `c2f7d24b7`; the script prints no SHA).

**New files**
- `SWFRecompDocs/plans/session28-fanout-reports/w2-hittest-shape-stale-report.md` (this report)
- `SWFRecompDocs/plans/session28-fanout-reports/w2-hittest-shape-stale.patch`
- `ruffle-tests/tests/swfs/regression/avm1_hittest_shape_stale_matrix/` (`test.swf`, `test.toml`, `output.txt` = FP32
  pinned capture, `create_test_swf.py`, `avm1asm.py`; the w1-leads probe, regenerates byte-identically)

**Patch note:** generated with `git diff --binary` (the fixture SWF); it also carries the README and ACCEPTED_DIFFS doc edits. Verified with `git apply --check -R`.

**Edited files:** `SWFModernRuntime/include/actionmodern/action.h` (trailing `MovieClip` fields),
`SWFModernRuntime/src/actionmodern/action.c`, `ruffle-tests/tests/swfs/regression/README.md` (fixture row),
`ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md` (Cat 8 intro wording, task 5). All are in the patch.

## Verdict

**GO (M), landed on the branch.** One model fits every Flash datum:

> `hitTest(x, y, true)` first rejects the point against the clip's **world bounds as of the last render** (a cache that
> a same-frame `_x`/`_xscale`/… change on the clip or any ancestor does not refresh). The exact shape test that follows
> uses the **live** matrix. `hitTest(x, y, false)` and `localToGlobal` use the live matrix.

It reproduces all 28 lines of the probe (phases A–G), FP32's lines 35/37/39 of `avm1/movieclip_hittest_shapeflag`, and
**six gnash assertions we used to fail** (`HitTest.as:66/67/73/140/141/142`, gnash's Flash-derived expectations; I did
not ask for these, which makes them independent corroboration).

**Priced flips (trace axis, both modes, local A/B):**
- `from_gnash/actionscript.all/HitTest-v6`: ruffle_matched → **pass**
- `from_gnash/actionscript.all/HitTest-v7`: ruffle_matched → **pass**
- `from_gnash/actionscript.all/HitTest-v8`: stays ruffle_matched, 9 → 3 diff lines
- `regression/avm1_hittest_shape_stale_matrix`: new row, passes (fails on master: 3 lines)
- `avm1/movieclip_hittest_shapeflag`: **stays failing (0 flips)**, as the brief predicted. Against the current Ruffle
  golden it gets 3 lines worse (6 → 9). Once the coordinator lands the flash_fix below, it is back to exactly the 6
  ACCEPTED Cat 8 lines, and every other line equals FP32.

Effective trace count: +0 (ruffle_matched already counts as effective). Raw pass: +2 gnash rows, plus the new
regression row. Pixel axis: 0 moves expected (the code is not render code; the canary is md5-identical, below).

## Mechanism and model fit

### The fit

Clip `c` is a 100×100 square drawn at (0,0) and placed at (100,100). The `hitTest` point is root-local. It is mapped to
global coordinates through `_root`'s live matrix (unchanged from before).

| phase | state (same frame unless noted) | stale box (global x) | live c (global x) | `shape` 150/250/50, model | FP32 |
|---|---|---|---|---|---|
| A | identity; c created this frame | (first query: live) [100,200] | [100,200] | T F F | T F F |
| B | `_root._x=100` | [100,200] | [200,300] | 150→g250: out → F; 250→g350: out → F; 50→g150: in, live local −50 → F | F F F |
| C | next frame | [200,300] | [200,300] | T F F | T F F |
| D | `_root._x=0` | [200,300] | [100,200] | 150: out; 250: in, live local 150 → F; 50: out | F F F |
| E | next frame | [100,200] | [100,200] | T F F | T F F |
| F | `c._x=200` | [100,200] | [200,300] | 150: in, live −50 → F; 250: out → F; 50: out | F F F |
| G | +`_root._xscale=50` | [100,200] | [100,150] | 150→g75 out; 250→g125 in, live local 50 → **T**; 50→g25 out | F T F |

The bounds column (`shapeFlag=false`) uses the live box in every phase and already matched FP32. `localToGlobal` is
unchanged and matched.

The rejected models:
- **"stale clip matrix"** (w1-leads): predicts B = F F **T**. Wrong.
- **"stage-global point"**: predicts B = F **T** F. Wrong.
- **Ruffle (live)**: predicts B = **T** F F. This was our pre-patch output.

`movieclip_hittest_shapeflag` block 2 (`_root._x=400; _root._xscale=50`, same frame as block 1): the stale box is the
donut's untransformed global box, x ∈ [250,550]. `(400,500)`, `(500,400)` and `(400,300)` map to global x 600/650/600:
outside, so **false** = FP32 35/37/39. `(300,400)` maps to global x = 550 **exactly**, on the box edge. It passes the
inclusive reject, and the live shape test says true: **true** = FP32 pinned line 41.

**New evidence the README missed:** the shapeflag `.pinned.txt` and `.nopin.txt` captures are **not** identical. They
differ on line 41 only (pinned `true`, no-pin `false`). The row's stage is 800×800, so the unpinned 640-px window
scales it. A device-space bounds cache moves its edge with that scale, and line 41 sits exactly on the edge. That
fits this model and no live-matrix model. The probe's own stage is 640×520 (unscaled), and there pinned == no-pin, as
the README says. **Use the PINNED capture for the flash_fix** (it is what the CI harness geometry corresponds to).

### Implementation (all in `action.c` / `action.h`; name list for the sibling map)

- `action.h` `struct MovieClip`: **trailing** fields `ht_snap_has`, `ht_snap_registered`, `ht_snap_query_tick`,
  `ht_snap_box[4]` (global twips, same space as the live AABB). Zero-initialised by `calloc`/`HCALLOC`.
- `action.c`: the `COMPUTE_GLOBAL_AABB` macro is **moved verbatim** from inside `actionCallMethod`'s hitTest arm to
  file scope, just above `actionCallMethod`, with its 3 extern declarations. Its body is unchanged, and the arm's
  `#undef` still closes it.
- New, just above `actionCallMethod`:
  - `htSnapCompute` (static)
  - `actionRefreshHitTestSnapshots` (global; called only from `actionDrainDpropsReleases`)
  - `actionHitTestStaleBounds` (static)
  - registry `g_ht_snap_clips`, a growable array. MovieClip structs are never freed, so its pointers stay valid.
- `actionCallMethod` hitTest arm (point form): after the existing live-box check, when `shape_flag` is set, the hit
  is re-decided against `actionHitTestStaleBounds`'s box. The mask skip and the shape refinement are unchanged and still
  use the live matrix. The bounds form (`shapeFlag=false`) and the clip-vs-clip form are untouched.
- `actionDrainDpropsReleases` (the tick-boundary hook, already called in both modes right after `g_tick_count++`, i.e.
  right after the previous tick's render; also the browser post-quit loop) now first calls
  `actionRefreshHitTestSnapshots`.

**Snapshot lifetime:**
- **First shape query** of a clip: cache the live box and register the clip. A clip created or first queried this
  frame has no older render to be stale against (phase A).
- **Every tick boundary:** recompute the box of each clip queried in the last `HT_SNAP_IDLE_TICKS` (256) ticks, and
  drop the rest (bounded per-tick cost). A dropped clip's next query again starts from the live box.
- **A snapshot with no bounds** (the clip was empty at the last render) defers to the live box.

The per-tick cost is zero for a movie that never calls `hitTest(x, y, true)`. No `swf.c`/`swf_core.c`/`tag.c` edit.

**Mode parity:** shared code; the refresh hook is in a function both frame loops call. The gate below ran both modes:
identical before/after rows in each.

## Per-test before/after (same box; before = clean `origin/master` source, after = this patch)

Gate = every avm1/gnash/shumway row whose (decompressed) SWF contains `hitTest`, minus TextSnapshot-only rows, plus the
`regression` hitTest rows and the regression rows that mention it. Columns: status, matching lines, ours_diff_count.
**Graphics and no-graphics are identical row for row**, so one table:

| row | before | after |
|---|---|---|
| avm1/bitmap_data, bitmap_data_hittest, bitmapdata_hittest_default_threshold, bitmapdata_hittest_threshold | pass | pass |
| avm1/hittest_lockroot, hittest_morph, hittest_winding_rule, movieclip_hittest | pass | pass |
| avm1/movieclip_invalid_get_bounds_6, _7, netstream_play_flv_screen | pass | pass |
| **avm1/movieclip_hittest_shapeflag** | output_mismatch, 332/338 (6 diff = Cat 8) | output_mismatch, 329/338 (6 Cat 8 + 35/37/39, where we now equal FP32) |
| from_gnash/actionscript.all/BitmapData-v8 | ruffle_matched 8 | ruffle_matched 8 |
| **from_gnash/actionscript.all/HitTest-v6** | ruffle_matched, 80 match, 8 diff | **pass**, 88 |
| **from_gnash/actionscript.all/HitTest-v7** | ruffle_matched, 80 match, 8 diff | **pass**, 88 |
| **from_gnash/actionscript.all/HitTest-v8** | ruffle_matched, 79 match, 9 diff | ruffle_matched, 85 match, 3 diff (`HitTest.as:77` + 2 summary lines) |
| from_gnash/actionscript.all/MovieClip-v6/v7/v8 | ruffle_matched 20/20/25 | same |
| from_gnash/misc-ming.all/ButtonEventsTest, DrawingApiTest, NetStream-SquareTest, masks_test, matrix_test | ruffle_matched 3/1/79/16/5 | same |
| from_gnash/misc-ming.all/RollOverOutTest, masks_test2 | pass | pass |
| from_shumway/acid/acid-morph (image 2517 ≤ 2600), hitTestStyleChange, hittesting/hittesting, stroke1 | pass | pass |
| from_shumway/avm1movie | ruffle_matched 12 | ruffle_matched 12 |
| regression/avm1_hittest_hairline, avm1_many_chars_registry, avm1_parent_child_morph/render/text | pass | pass |
| **regression/avm1_hittest_shape_stale_matrix** (new) | output_mismatch 25/28 | **pass** |

`movieclip_hittest_shapeflag` after-diff vs the CURRENT (Ruffle) golden: lines 35/37/39 (`false` vs golden `true`,
= FP32), then 71, 171, 173, 175, 177, 296 (Cat 8, unchanged). Line 41 stays `true` (= FP32 pinned).

`HitTest-v8` residual: `HitTest.as:77` `a.hitTest(41, 25, true)`. This is the last probe after `_root._width` was
restored and `_root._xscale = 50` was set in the same frame. Gnash expects `false` for SWF8, but `true` for SWF6/7
(`HitTest.as:75`, which we now pass). The model gives `true` for every version: the root-local point 41 maps to global
20.5, and the stale box starts at 20. So something version-gated (or a pixel snap of the cached box) is unmodelled.
Flash request 2 below. Before the patch we failed it too, so it is not a regression.

### Canary (graphics, md5 A/B)

The full 324-row canary is out of scope by argument. The patch only changes `hitTest(x, y, true)` answers. The refresh
is a no-op loop over an empty registry for any movie that never calls the shape form, so a row can move only through
script behaviour, and the gate above already covers every row that calls `hitTest`. Targeted canary:
`render_canary.py capture` before/after on the two standing members that call `hitTest`
(`avm1/netstream_play_flv_screen`, `from_shumway/acid/acid-morph`) plus six AVM1/gnash/shumway Drawing-API/mask
controls (`avm1/mask_with_drawing`, `avm1/movieclip_setmask`, `avm1/movieclip_line_gradient_style`,
`from_shumway/acid/acid-small`, `from_gnash/misc-ming.all/morph_test1`, `from_shumway/3_joystick`):
**8 tests / 14 PNGs: IDENTICAL 14, DIFFERS 0, no trace or image status changes** (`compare` exit 0).

## EXPECTED-FLIP LEDGER (for the CI check)

Trace axis, both modes:
- `from_gnash/actionscript.all/HitTest-v6`: ruffle_matched → **pass**
- `from_gnash/actionscript.all/HitTest-v7`: ruffle_matched → **pass**
- `from_gnash/actionscript.all/HitTest-v8`: ruffle_matched → ruffle_matched (ours_diff 9 → 3)
- `avm1/movieclip_hittest_shapeflag`: output_mismatch → output_mismatch. Expected-line matches: 332 → 329 against the
  upstream golden. Against the FP32 flash_fix golden it is 330/339 (master) → **333/339**, i.e. exactly the 6 Cat 8
  lines. If the flash_fix lands in the same CI run, expect 333 matching lines. It is in
  `ignored_tests.txt`, so filtered totals don't move.
- `regression/avm1_hittest_shape_stale_matrix`: new row, **pass**

Pixel axis: **no moves** (no moved row has an image comparison; canary md5-identical).

Any other status move in CI is unexpected: report it.

## Drafts for the coordinator (task 3)

### flash_fixes entry (`ruffle-tests/flash_fixes/avm1/movieclip_hittest_shapeflag/output.txt` = the PINNED capture)

```json
{
  "test": "avm1/movieclip_hittest_shapeflag",
  "file": "output.txt",
  "upstream_sha256": "471626e6071f4f73a7223c72f37de8c8d02dc1c79ef44baf4bcd573ff05c349d",
  "fix": "avm1/movieclip_hittest_shapeflag/output.txt",
  "kind": "trace",
  "evidence": "Flash Player 32 LNX debug projector, direct pinned: SWFRecompDocs/plans/session28-fanout-reports/w1-local-oracles/w1-leads/movieclip_hittest_shapeflag.pinned.txt (s28 w1-leads request 2)",
  "reason": "Lines 35/37/39 (second donut block, after _root._x = 400; _root._xscale = 50 in the SAME frame) are false in Flash: the shape hitTest rejects against the clip's last-rendered bounds. Ruffle reads the live matrix (true). Every other line equals the golden. No-pin capture differs on line 41 only (the 800x800 stage is scaled in an unpinned window; the point is on the cached box edge), so the pinned capture is the one to store.",
  "rvf": "RUFFLE_VS_FLASH_DIFFERENCES.md: s28 hitTest shapeFlag same-frame stale bounds",
  "added": "2026-11-25"
}
```

sha256 of the pinned capture: `fe27b6366cc217e8d6be9228a3ad11f5fa2864f9d9cb60c31af27a114deb80fe`. Effect when added:
the row stays failing, on the 6 ACCEPTED Cat 8 lines only (with this patch). Without this patch it would fail on 9.

### RvF entry (append at EOF of `RUFFLE_VS_FLASH_DIFFERENCES.md`)

```markdown
## s28: `hitTest(x, y, true)` uses the clip's last-RENDERED bounds in the frame its transform changes

**Tests:** `avm1/movieclip_hittest_shapeflag` (lines 35/37/39), `regression/avm1_hittest_shape_stale_matrix`;
corroborated by gnash `actionscript.all/HitTest-v6/v7/v8` (`HitTest.as:66/67/73/140/141/142`, Flash-derived
expectations Ruffle fails).
**Evidence:** FP32 LNX debug projector, direct, pinned (== no-pin for the 640x520 probe):
`SWFRecompDocs/plans/session28-fanout-reports/w1-local-oracles/w1-leads/`.

**Flash:** in the frame where `_root._x`, `_root._xscale` or the clip's own `_x` changes, `clip.hitTest(x, y, true)`
first rejects the (root-local → global, live `_root` matrix) point against the clip's world bounds as of the last
render, then runs the exact shape test with the live matrix. `hitTest(x, y, false)` and `localToGlobal` use the live
matrix. The next frame is consistent again. Probe phase B (`_root._x = 100`, square at root (100,100)-(200,200)):
`hit(150,150) shape=false bounds=true`.

**Ruffle:** `movie_clip.rs` `hit_test` maps the point through `_root`'s live matrix and calls `hit_test_shape` with
the live world matrix and live bounds: `shape=true` in phase B, `true` on the golden's lines 35/37/39.

**Decision:** match Flash (`action.c` `actionHitTestStaleBounds`, s28 w2-hittest-shape-stale). The golden is replaced
by the FP32 capture via `flash_fixes`. The row keeps its 6 ACCEPTED Cat 8 lines (our glyph/morph precision, = FP32 ≠
ours).
```

## Task 5: ACCEPTED_DIFFS Cat 8 wording: done

The intro now says the 6 lines disagree with the Ruffle golden **and** with FP32 (the s28 capture equals the golden
there), so they are our inaccuracy, and that FP32 ≠ golden only on 35/37/39. It cites this slot.

## Refutations / premise checks

- **Brief: "phases B, D, F, G differ from ours".** G did **not** differ: FP32 G == our pre-patch output (`shape=true`
  at 250). B, D and F differ. The model explains why G agrees: the live point lands inside both the stale and the live
  box.
- **README: "shapeflag pinned == no-pin".** False on line 41 (see above). It matters for which capture the flash_fix
  stores.
- **w1-leads "stale clip matrix" model:** refuted by phase B (`hit(50)` is false in Flash).

## Limits / not finished (each with its completion mechanism)

1. **Unmodelled cache invalidation.** A clip whose content changed this frame (Drawing API, timeline
   PlaceObject/move) keeps its last-render box until the next tick. A timeline move between the render and the
   frame's scripts is also stale under this model, which is the plausible Flash behaviour but is unprobed. None of
   the 38 gate rows moved the wrong way. Completion: Flash requests 1a–1c.
2. **First query after an idle gap > 256 ticks** uses the live box (Ruffle behaviour) for that one frame. This is a
   cost bound, not Flash behaviour. Completion: none needed unless a game shows it. Raising the constant is free.
3. **`HitTest-v8` `HitTest.as:77`** (SWF8-only expectation). Completion: Flash request 2.

## New unclaimed leads

- `HitTest-v8:77`: a version-gated or pixel-snapped detail of Flash's bounds cache (SWF8 vs 6/7). After request 2,
  likely a one-line rounding change in `actionHitTestStaleBounds`.
- Does the same stale box gate **button / mouse hit testing** (`_droptarget`, rollOver) in the frame a clip moves?
  Unprobed; our mouse path reads live geometry.

## LOCAL ORACLE REQUESTS

1. **FLASH: `regression/avm1_hittest_shape_stale_matrix` variants, trace, direct pinned.** Edit `create_test_swf.py`
   (one phase each, built locally with its own `avm1asm.py`):
   - (a) a clip **created and drawn this frame, after** a render of its parent, then `_root._x` changed before its
     first query: does Flash cache at first query, or only at render?
   - (b) a **nested** parent change: `p.c`, change `p._x` same frame.
   - (c) `_rotation = 45` on `_root` same frame; and a Drawing-API `clear()`+redraw of `c` at a new spot same frame
     (does a geometry change invalidate the cached box?).

   Compare each with this patch's output (`verify_output.py --save-actual`).
2. **FLASH: `from_gnash/actionscript.all/HitTest-v8` and `HitTest-v6`, trace, direct pinned, full output.** Does FP32
   print `PASSED` on `HitTest.as:77` (v8, `a.hitTest(41,25,true) == false`) and `:75` (v6, `== true`)? If FP32 is
   `true` on v8 too, the gnash expectation is FP9-era (flash_fixes candidate for the gnash golden) and this patch
   already matches.
