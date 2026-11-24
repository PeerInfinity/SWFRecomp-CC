# s27 w2-holder-drawing-full: Holder Drawing-API z-order, the full model (wave 2, implementation)

**New files:**
- `SWFRecompDocs/plans/session27-fanout-reports/w2-holder-drawing-full-report.md` (this file)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-holder-drawing-full.patch`
  (`git diff origin/master -- SWFModernRuntime ruffle-tests/render_canary_tests.txt ruffle-tests/tests/swfs/regression/avm1_empty_clip_drawing_depth_order`, `--binary`)
- `ruffle-tests/tests/swfs/regression/avm1_empty_clip_drawing_depth_order/`: `create_test_swf.py`, `test.swf`,
  `test.toml`, `output.txt`, `output.expected.png`. The golden is the **real Flash** capture
  `w1-local-oracles/w1-render-bitmap-leads/avm1_empty_clip_drawing_depth_order/flash.png`, byte-copied. It is
  pixel-identical (bbox `None`) to the w1 `hand.expected.png`.
- `SWFRecompDocs/plans/session27-fanout-reports/w2-holder-drawing-full-fixtures/avm1_textfield_attached_depth_order/`:
  `create_test_swf.py`, `test.toml`, `output.txt`, `hand.expected.png` (`test.swf` is gitignored there: run `python3 create_test_swf.py test.swf`). It is parked here because the golden
  is hand-drawn and is not an oracle. See LOCAL ORACLE REQUESTS. It is **not** in the patch.

**Environment:** `SETUP_STATUS` all OK (Dawn on lavapipe). The categories were downloaded from upstream Ruffle master
on 2026-11-24 (`download_tests.sh avm1 from_gnash visual avm2 fonts from_shumway text`, 2932 tests); the script prints no
SHA. The *before* leg is clean `origin/master` `53540ff0`. Everything is A/B md5 on this box. No absolute CI-fidelity
claim is made beyond that: the one absolute verdict, fixture B, is against a Flash golden of solid pixel-aligned rects
with max diff 0.

---

## Verdicts and priced flips

| # | Item | Verdict | Flips |
|---|---|---|---|
| 1b | A childless empty clip's drawing layers above higher-depth attached siblings | **GO, landed** | **+1 new pixel row `regression/avm1_empty_clip_drawing_depth_order`** (Flash golden): fail 16000 → **pass 0 / max 0**. `from_gnash/misc-ming.all/BeginBitmapFill` is **md5-identical** (939, KF; no move) |
| 1 | Full model: the late text pass is interleaved | **GO, landed** (two text windows, see Mechanism) | 0 corpus. The new fixture `avm1_textfield_attached_depth_order` goes fail 38400 → pass 0 / max 0 vs its hand golden (oracle pending) |
| 3 | Sweep: attached clips, Drawing API, createEmptyMovieClip, EditText image rows, plus the canary | **Clean** | 214 tests / 299 comparisons: **297 IDENTICAL, 2 DIFFERS (both mine, fail→pass), 0 trace-status changes** |

**Net: +1 regression pixel row, 0 corpus moves, 0 regressions.** No trace axis change.

### The "depth rule that satisfies both" (attack on the brief's premise)

The brief frames this as a depth rule to find. **It is not a drawing-depth rule.** w1's diagnosis holds: the full
variant only "regressed" `BeginBitmapFill` because the gnash `xtrace` field sits in the sprite at the **last** root
depth. I measured it on this box with four variants:

| holder full variant + | `BeginBitmapFill` outliers |
|---|---|
| no text change (= w1's naive full variant) | **1188** (reproduces w1) |
| post-walk window only (A below) | 939, md5 = before |
| attached-pass anchors only (B below) | 939, md5 = before |
| both (landed) | 939, md5 = before |

The s26 near-pass rule (`tf_nested_anchor_depth`) already paints a field nested in a root-timeline sprite at depth
`d` in the pre-draw window of depth `d+1`. When `d` is the last root depth, `d+1 > max_depth` returned −1, so the field
fell to the REST pass, after every attached clip. While all empty-clip drawings were also late (the global
`actionIterateDrawings`, after REST), that bug was invisible. Moving the drawings into the attached pass exposed it.
Fixing the text window keeps the drawings' depth rule at the plain Flash rule: every drawing-only clip draws at its
sorted attached position.

## Mechanism and exact patch scope

All edits are inside the attached/drawing passes and the text-window module. Graphics-only paths; the
`NO_GRAPHICS`/`swf_core.c`/`tag_stubs.c` code is untouched.

### `SWFModernRuntime/src/actionmodern/action.c`

- **`tf_nested_anchor_depth`** (EditText z-order window block): returns `d` up to `swf_max_depth + 1`, not −1, for a
  field whose root-timeline ancestor is at the last depth. This is the **post-walk window**.
- **NEW** (static, next to it):
  - `TfAnchor`, `g_tf_anchor*`, `tf_ptr_cmp`, `tf_anchor_cmp`, `tf_anchor_of`, `tf_in_window_unit`.
  - Exported: `actionTextFieldAnchorsBuild(void** units, int n)`, `actionTextFieldAnchorHas(void*)`,
    `actionSetTextFieldAnchorWindow(void*)`.
  - A field that is neither root-timeline nor nested in a root-timeline sprite gets an **anchor**: the nearest
    ancestor-or-self in the attached pass's render list.
  - Lookups are sorted-array `bsearch`. The cost per frame is O(fields·log) plus O(units-with-fields × child_mc_count).
    There is no quadratic scan.
  - The anchor set is capped at 1024 fields. Overflow fields keep the REST pass.
- **`tf_window_skip`**:
  - New mode `TF_WINDOW_ANCHOR` admits only the window clip's fields.
  - `TF_WINDOW_REST` now skips anchored fields, because they were already painted.
- **`actionBeginTextFieldDepthPass`**:
  - Resets the anchor set every frame. Every other caller sees an empty set and the historical behaviour.
  - Records `g_tf_pass_swf_max`.
  - Sizes the presence table at `max + 2`, so the post-walk window has a slot.
- **`actionRenderHolderDrawingsInline`**: the w1 narrow gate ("only a holder with live attached children") is
  removed. Every drawing-only clip the attached pass visits paints at its sorted position.

### `SWFModernRuntime/include/actionmodern/action.h`

`TF_WINDOW_ANCHOR 3` plus 3 prototypes, next to the existing window API.

### `SWFModernRuntime/src/libswf/tag.c`

- **NEW `tf_draw_for_attached_unit`** (static, after `tf_draw_at_root_depth`): sets the anchor window for one clip and
  runs `actionIterateTextFields` and `actionIterateTextFieldGlyphs`.
- **`tagRerenderFrame`** (OFFSCREEN capture), attached pass:
  - `tf_draw_at_root_depth(max_depth + 1)` after the timeline walk.
  - `actionTextFieldAnchorsBuild(order)` after `attached_sort_render_order`.
  - The per-clip body is wrapped in `do { … } while (0)`, so the existing `continue`s end the body only. It is not
    re-indented, to keep the hunk small against the N session.
  - `tf_draw_for_attached_unit(mc)` runs after each clip.
- **`tagShowFrame`**, post-loop attached pass (OFFSCREEN and browser): the same three additions, around
  `render_attached_child`.
  - The browser timeline interleave (`attached_parent_dl_index`) is unchanged. Fields under a timeline parent already
    take the nested-depth window.
- `render_attached_child` is **not** edited beyond what master has.

The N session (`n-ragdoll-strokes`: `advance_sprite_frames`, `ng_attached_run_tree`) touches neither these functions
nor these hunks.

## Per-test before/after (clean `origin/master` vs patch, same box, `--mode=graphics`)

| test | before | after |
|---|---|---|
| `regression/avm1_empty_clip_drawing_depth_order` (Flash golden) | **fail**, 16000 outlier ch, max 255 | **pass**, 0 / max 0 |
| `regression/avm1_holder_drawing_under_children` | pass 0 | pass 0 (md5 identical) |
| `regression/avm1_attached_clip_holder_render` | pass 0 | pass 0 (md5 identical) |
| `from_gnash/misc-ming.all/BeginBitmapFill` (KF) | fail 939 | fail 939 (**md5 identical**, `642e53c8…`) |
| fixture `avm1_textfield_attached_depth_order` (hand golden, parked) | fail 38400 ch (T1, T2, T3 wrong; control T4 right) | pass 0 / max 0 |
| `regression/avm1_attached_clip_{button_click,goto_play,goto_play_nonroot,natural_timeline,natural_timeline_nonroot,samename_child,tagorder,tagorder_nonroot,tagorder_po3,tagorder_ratio}`, `avm1_child_timeline_holder_stop`, `avm1_mcl_holder_totalframes` (trace rows, graphics mode) | pass | pass |
| `regression/avm1_stroke_style_id_order` | pass | pass (0 / 0) |
| `regression/avm1_holder_drawing_under_children` (no-graphics, compile + trace sanity) | — | pass |

## Sweep and canary (`render_canary.py`, md5, `-P 3`)

The list has **214 tests and 299 comparisons**. It is the union of:
- the standing `render_canary_tests.txt` (all members);
- every AVM1-category image row (`avm1`, `from_gnash`, `from_shumway`, `visual`, `regression`, `text`, `fonts`) whose
  decompressed SWF names `createEmptyMovieClip`, `attachMovie`, `createTextField`, `beginFill`, `beginBitmapFill`,
  `beginGradientFill`, `lineTo`, `attachBitmap` or `duplicateMovieClip` (73 rows);
- every non-AVM2 image row carrying a DefineEditText (35 rows);
- the 2 fixtures.

```
IDENTICAL 297   DIFFERS 2   APPEARED 0   VANISHED 0   NO_RENDER 0
  regression/avm1_empty_clip_drawing_depth_order  fail -> pass   bbox (60,180)-(160,260)
  regression/avm1_textfield_attached_depth_order  fail -> pass   bbox (60,40)-(360,240)
TRACE STATUS CHANGES: (none)
```

Every `regression/*` canary member is identical. That is the regression-suite check near the change.

**Canary addition (EOF of `render_canary_tests.txt`):** `regression/avm1_empty_clip_drawing_depth_order` and
`from_gnash/misc-ming.all/BeginBitmapFill`. The second is the witness for the post-walk text window: without it, the
canary cannot see a regression of that window.

## EXPECTED-FLIP LEDGER (what CI must show after this patch)

- **Pixel axis:** `regression/avm1_empty_clip_drawing_depth_order` is a **new row, pass** (golden = Flash; tolerance
  1, max_outliers 0; local after: 0 / max 0). No other pixel row moves. In particular,
  `from_gnash/misc-ming.all/BeginBitmapFill` stays **fail at 939** (KF; must not become 1188).
- **Trace axis:** `regression/avm1_empty_clip_drawing_depth_order` is a **new row, pass** (`drawn`). No other trace row
  moves.
- **Mode:** graphics is enough. No-graphics is unaffected (the render path is graphics-only; the no-graphics compile
  was checked).

## What is not finished, and its completion mechanism

1. **Fixture `avm1_textfield_attached_depth_order` has no oracle golden.** Completion: a FLASH image request (below).
   - If Flash agrees at 0 px, move the dir to `ruffle-tests/tests/swfs/regression/` and rename `hand.expected.png` to
     `output.expected.png`. The generator finds its sibling helper in either location.
   - Then append it to the canary. It is the only fixture that sees the attached-pass text anchors.
   - Risk: the field rects use `createTextField` x/y/w/h with background only (no font). If Flash insets or outsets the
     background by a pixel, the golden becomes Flash's capture with the same z-order. The z-order claim is unaffected.
2. **Fields inside an attached clip with sprite content (OFFSCREEN aliased path)** are anchored to the nearest
   attached-pass clip. They therefore paint after that clip's **whole** subtree, including its aliased attached children,
   not interleaved by depth inside it.
   - That is strictly closer to Flash than REST (after everything), but not exact.
   - Completion (M): make `render_display_list` flush a field at its own entry. That needs entry ↔ field-MC linkage,
     the same missing link noted in `actionFindMCForDisplayObj`'s "wave 2 should link entry <-> mc" heuristic.
   - 0 corpus rows see this.
3. **Attached bitmaps** (`actionIterateAttachedBitmaps`) are still drawn after everything (w1 lead 2 of "New unclaimed
   leads", S–M). This is the same ordering family and was untouched here. Completion: an anchor-style flush keyed on
   the bitmap's owner MC in the attached pass.
4. **Game-visible N** was not measured: it needs the local browser and the N session. Two code paths matter there:
   - The browser `tagShowFrame` post-loop pass now draws empty-clip drawings and anchored fields in depth order. The N
     menu/HUD pattern of a holder background plus `createTextField` labels at higher depths is the intended
     beneficiary.
   - Fields under a hidden holder are still culled by `tf_ancestor_hidden`.

## Refutations

1. **"Find the depth rule that satisfies both fixture B and `BeginBitmapFill`."** There is no competing drawing-depth
   rule. Both are satisfied by the single Flash rule (drawing at the clip's sorted position) once the last-depth sprite
   text gets its window. Measured above: 1188 → 939, md5 = before.
2. **"The full model needs sprite-nested text drawn at the owning clip's render position (M)."** Half of it was already
   in master since s26 (`tf_nested_anchor_depth`, root-timeline sprites). The missing pieces were the last-depth hole and
   the text of non-timeline (attached/createTextField) owners. Both were S–M, not M+.

## New unclaimed leads

1. Entry ↔ MC linkage for fields inside attached sprite content (item 2 above). It would also retire
   `actionFindMCForDisplayObj`'s unique-name heuristic.
2. `actionIterateAttachedBitmaps` late pass (item 3 above).

## LOCAL ORACLE REQUESTS

1. **FLASH: `session27-fanout-reports/w2-holder-drawing-full-fixtures/avm1_textfield_attached_depth_order/test.swf`,
   image, frame 1 (AVM1 v8, 400×300, 1 frame; trace `drawn`).** Compare to `hand.expected.png`.
   - Expected z-order: red over blue (T1), red over green (T2), magenta over yellow (T3), cyan over red (T4, control).
   - `run_image.py` (`draw()` wrapper) is fine; no blend modes are used.
   - If it matches at 0 px, land it as item 1 under "What is not finished".
