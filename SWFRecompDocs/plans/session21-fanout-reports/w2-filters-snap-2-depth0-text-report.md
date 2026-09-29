# w2-filters-snap-2 — AVM1 sprite children at DEPTH 0 were never drawn (lead F1)

Agent `w2-filters-snap`. Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w2-filters-snap-2`
(branch `s21-w2-filters-snap-2`, based on master `cb31af254`). No commits.

**Files delivered:**
- `SWFRecompDocs/plans/session21-fanout-reports/w2-filters-snap-2-depth0-text.patch`.
  It changes `SWFModernRuntime/src/libswf/tag.c` only: 4 loop starts plus comments.
  **No new files.**
- this report.

The patch is independent of `w2-filters-snap.patch`. The two stack in either order;
checked with `git apply --check` on master `cb31af254` with this patch applied.

---

## 0. Verdict

**GO as a correctness fix, 0 flips on its own and 0 flips stacked with the snap.**

| comparison | tol / max | master | + depth-0 | + depth-0 + snap |
|---|---|---:|---:|---:|
| `visual/filters/bevel_inner` | 4 / 18 | 48 134 | 44 225 | 1 741 |
| `visual/filters/bevel_outer` | 3 / 18 | 78 376 | 74 467 | 2 173 |
| `visual/filters/bevel_full` | 4 / 18 | 66 782 | 62 873 | 1 881 |
| `visual/filters/glow_with_alpha_strength` | 4 / 18 | 42 782 | 38 873 | 1 846 |

The depth-0 patch alone removes exactly 3 909 channels per row, which is the label
column: bbox (32,111)–(61,683), identical on all four rows. Stacked with the snap,
these rows are at 1.7–2.2 k against a budget of 18. What remains is the thin-stroke
staircase owner (`w2-filters-snap-report.md` §5 B), so neither patch flips them.
The coordinator's "would turn the band cuts into flip candidates" is therefore
**refuted at the ~100× level**. They become near-single-owner rows, which makes them
clean witnesses for the stroke arc.

---

## 1. Mechanism

In all four SWFs each row label is a `DefineSprite` with **frame count 0 and no
ShowFrame**. Inside, `PlaceObject2` puts a DefineText at **depth 0** (the "50%",
"100%" or "200%" text) and another at depth 1. Sprite 13 also has depth 2
("Strength" plus the ladder).

`tagPlaceObject2` stores depth 0 at `dl[0]` (`ng_ensureDisplayListSize(depth)`, no
rejection). But every AVM1 render and bounds walk in `tag.c` was
`for (i = 1; i <= max; i++)`, so `dl[0]` was placed and never drawn. Ruffle keys its
display list on depth like any other value, and depth 0 renders there.

**The fix**: start at 0 in the four sprite-content walks that decide what is drawn and
how big it is:
- `compose_children`
- `render_display_list`
- `opaque_bg_local_bounds` (the sprite arm)
- `sprite_content_bounds_twips`

An unused `dl[0]` is zero-filled (`char_id == 0`) and skipped by each loop's existing
guard. Two pre-existing walks (`set_enterframe_eligible_recursive`,
`hasClipEnterFrameHandlers_impl`) already start at 0, so `dl[0]` is proven safe to
visit. Every caller of the four functions passes a SPRITE (or loaded-movie) list. The
root display loops in `tagShowFrame` and `tagRerenderFrame` are **not** touched (see
§3).

---

## 2. Blast radius and canary (md5 A/B; before = `git apply -R`)

**Corpus scan.** Every `test.swf` (zlib + LZMA) was walked for PlaceObject1/2/3 at
depth 0. **Sprite-internal depth 0 appears in exactly these four SWFs.** Root depth 0
appears in 20 SWFs (untouched by this patch).

**Standing set:** `render_canary.py` over master's `render_canary_tests.txt` — 51
tests, 89 comparisons: **89 IDENTICAL**. No trace or image status change.

**Extra set:** the 4 rows plus all 13 image-bearing `regression/` rows (including the
loaded-child `avm1_parent_child_*` rows, which reach `render_display_list` through the
loaded-movie arm): **13 IDENTICAL, 4 DIFFERS**. The 4 are the target rows, each moving
by exactly the label bbox. Fail → fail, trace pass → pass.

The no-graphics trace passes (`bevel_outer`), which covers the
`sprite_content_bounds_twips` change.

The comments were added after the A/B. The loop code is byte-identical to what was
measured (checked by diffing the `for` lines).

---

## 3. Not covered (named, not needed by any known row)

- **Root depth 0.** The root display loops (`tagShowFrame` / `tagRerenderFrame`
  ~l.6660 / ~7591 and their siblings) still start at 1. The 20 root-depth-0 SWFs are
  mostly trace tests. Four are image rows (`visual/edittext/edittext_{background,
  border}_basic{,_scale2}`) and they already PASS. Changing the root loops would need
  its own A/B over those.
- **Other sprite walks.** Hit-testing and clip events (`find_drop_target_*`,
  `dispatch_clip_event_*_dl`), eager constructors, unload recursion and
  `ng_display_clear_after` still start at 1. A depth-0 *sprite* child with
  clip events or constructors would still be skipped there. No corpus row exercises
  this.
- The `sprite_max_depth == 0` early-outs (for example "no children to advance") would
  skip a sprite whose ONLY child is at depth 0. That case is not present in the corpus.
