# w2-masks-hittest — session 20, wave 2

## NEW FILES (stage these by name — `git add -u` silently drops them)

- `SWFRecompDocs/plans/session20-fanout-reports/w2-masks-hittest.patch`
- `SWFRecompDocs/plans/session20-fanout-reports/w2-masks-hittest-report.md` (this file)

**No new source files.** The patch touches exactly one existing file,
`SWFModernRuntime/src/actionmodern/action.c` — one hunk, +15/−7, entirely inside
`actionCallMethod`'s `hitTest` arm. Nothing to add to `verify_output.py`'s source
list, CMakeLists or the Emscripten build.

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a32ff1d0173ca7df9`

---

## 1. Verdict and priced flips

**GO — landed and verified.**

| test | before | after | value |
|---|---|---|---|
| `from_gnash/misc-ming.all/masks_test` | `output_mismatch`, 124/175 matching, 50 real diff lines | **`ruffle_matched`** | **+1 effective** |
| `avm1/movieclip_hittest_shapeflag` (rider) | `output_mismatch` 332/338, `IGN`+`ACC` | `output_mismatch` 332/338, byte-identical | **0 — dropped, see §5** |

Total priced yield: **+1 effective pass** (4439 → 4440 of 4527 graded), from a
one-hunk runtime change.

### The diff-line-vs-flip distinction, and the residual-16 question

The brief's central pricing claim — *"`masks_test` flips only when all 50 go, so
if the residual 16 is an open-ended tail this row yields 0 flips"* — is
**REFUTED**. Both halves of it were wrong, and in the same direction.

**Regime.** `masks_test/test.toml` is `known_failure = true` at top level, and the
directory ships a bare `output.ruffle.txt` (not `output.fpNN.ruffle.txt`), so the
wave-0 `RTXT` flag is accurate for this row. I checked the directory myself rather
than trusting the flag. The grading target is therefore **`ruffle_matched`**:
`verify_output.py`'s `ruffle_subset_match` (line 3506) promotes when our diff
**line indices** against `output.txt` are a subset of Ruffle's, and
`ruffle_matched` counts toward `effective_pass` (line 3674). A byte match against
`output.txt` was never required.

**The residual 16 is Ruffle's own diff set, verbatim — a closed set, not a tail.**
Measured directly from `output.ruffle.txt` vs `output.txt`:

```
Ruffle's diff indices (16): 141 146 153 154 155 159 161 162 163 164 165 170 171 172 173 174
```

That is 14 shape-arity `hitTest(..., true)` assertions where Flash prints `PASSED`
and Ruffle prints `FAILED`, plus the two summary counters (`#passed: 154` →
`#passed: 140`, `#failed: 0` → `#failed: 14`). Our pre-patch diff set was those
same 16 **plus** 34 others, and `ruffle − ours` was empty. So the row was **one
mechanism away from flipping**, not fifty lines away.

**Shift-artifact check (the coordinator's warning, done positionally).** Our
actual output is exactly 175 lines, the same as `output.txt`, and every line is
positionally aligned: each of the 34 defect lines carries the *same assertion
string at the same index*, differing only `PASSED:` → `FAILED:` — e.g. line 44 is
`staticmc3.hitTest(40, 210, false) [masks_test.c:248]` on both sides. There is no
insertion or deletion anywhere in the file, so the subset test is not flattering
us through a shift, and the small ours-only set is a genuine closed defect set.

---

## 2. Mechanism (and a premise refinement)

**Premise as briefed:** *"34 of the 50 remaining diff lines are `hitTest` on
masked/mask clips — a hit-test slice, not an events one."*

**Confirmed, but under-specified in the way that mattered.** All 34 are the
**bounding-box arity** `hitTest(x, y, false)`, on a clip that `setMask` had turned
into a masker. Every *shape*-arity line we failed was one Ruffle fails too. The
slice reclassification was right; the arity split is what made it a one-liner.

`SWFModernRuntime/src/actionmodern/action.c` (AVM1 `hitTest`, in `actionCallMethod`)
carried, ahead of the `shapeFlag` branch:

```c
// AVM hitTest skips masks (Ruffle: AVM_HIT_TEST contains SKIP_MASK).
// A clip used as a mask returns false from hitTest(x, y, ...).
if (mc != NULL && mc->is_mask) { PUSH(ACTION_STACK_VALUE_BOOLEAN, 0); return; }
```

That is a misread of the oracle. Ruffle's `hit_test`
(`core/src/avm1/globals/movie_clip.rs:246-251`) branches on `shapeFlag`:

```rust
let ret = if shape {
    movie_clip.hit_test_shape(activation.context, point, HitTestOptions::AVM_HIT_TEST)
} else {
    movie_clip.hit_test_bounds(point)
};
```

`AVM_HIT_TEST` is exactly `SKIP_MASK` (`core/src/display_object.rs:3074`), and
`SKIP_MASK` is consumed only inside `hit_test_shape`, which bails when
`self.maskee().is_some()` — i.e. when this clip is somebody's mask
(`core/src/display_object/movie_clip.rs:2695`). The `shapeFlag = false` arm goes
to `hit_test_bounds(point)`, which has **no mask logic at all**: a clip used as a
mask still reports its own world bounds. Our unconditional early return applied
the shape-arity rule to both arities.

This also explains the exact shape of the failures. `masks_test` runs four phases;
the phases where a clip is a masker are precisely where its bbox arity failed:

| phase | maskers (per `avm1_mask_pair`, `action.c:30818`) | our failing bbox lines |
|---|---|---|
| 1 — `setMask` applied | staticmc3, staticmc4, dynamicmc3, dynamicmc4 | 44 45 50 51 60 61 64 65 |
| 2 — depths swapped | same four | 83 84 87 88 99 100 103 104 |
| 3 — mask/maskee swapped (pairs go **circular**, so 7 of 8 clips are maskers) | staticmc2/3/4/5, dynamicmc3/4/5 | 123 124 127 128 131 132 135 136 139 140 143 145 147 148 |
| 4 — all made mouse-sensitive | staticmc3, staticmc4, dynamicmc3, dynamicmc4 | 157 160 167 169 |

**Fix:** gate the skip on `shape_flag`, after the bounding-box test:

```c
int hit = (ptx >= gxmin && ptx <= gxmax && pty >= gymin && pty <= gymax);
if (hit && shape_flag && mc != NULL && mc->is_mask)
    hit = 0;
```

The single-arg `hitTest(target)` form was never affected — the early return lived
inside the `num_args >= 2` arm — and that matches Ruffle, whose `hit_test_object`
is bounds-vs-bounds with no mask logic.

---

## 3. Blast-radius audit — is this misread copied anywhere else?

Asked by the coordinator. **It is a one-site bug.** Every masker gate in the tree,
classified:

| site | kind | verdict |
|---|---|---|
| `action.c:73355` | AVM1 `hitTest(x,y,shapeFlag)` | **the defect — fixed here** |
| `action.c:75877` (`ng_hit_area_tbl_push`) | AVM1 **mouse picking** | **correct, untouched.** Blocks a hit *area* that is a live masker = Ruffle's `MOUSE_PICK = SKIP_MASK \| SKIP_INVISIBLE`. Picking has no shapeFlag arity, so the gating question does not arise. Its TextField carve-out is graded by `avm1/hitarea_sweep`. |
| `avm2_display.c:4295` (`do_hit_test_point`) | AVM2 `hitTestPoint` | **correct already**, and structured exactly like the fix: `if (shape_flag) { hit_test_shape_obj(..., HT_AVM_HIT_TEST) } else { bounds_with_transform(...) }`, no mask logic on the bounds arm. |
| `avm2_display.c:14623` (`hit_test_shape_obj`) | AVM2 shape walk | **correct** — `HT_SKIP_MASK` on `ext->maskee != NULL`, a faithful port of `movie_clip.rs:2695`. |
| `action.c:14379`, `:14505`, `:28345`, `:31054`; `tag.c:5814`, `:7020`, `:7069` | **render** paths (rasterize-to-bitmap, glyph pass, attached-child draw, drawing iterators) | out of scope; all are the correct "a live masker is stencil-only, never content". |
| `action.c:30787/30799/30815/30825` | the `setMask` pairing registry | untouched. |

No second fix, no extra rows to price.

---

## 4. Exact patch scope

`SWFRecomp-CC/SWFModernRuntime/src/actionmodern/action.c`, one hunk at ~73350
(inside `actionCallMethod`'s `hitTest` arm): delete the unconditional `is_mask`
early return, and re-express it after the bbox test as
`if (hit && shape_flag && mc != NULL && mc->is_mask) hit = 0;`, with a comment
citing the three Ruffle lines. Net +15/−7 (the growth is the comment).

**Sibling-collision check:** ~73350 is clear of **w2-coerce**
(`propertyCoerceToNumber` ~15499-15600 and its call sites ~46519, ~59801) and of
**w2-avm1-nearflips** (`XML.load` byte counter, `getURL`). No overlap; no message
needed.

---

## 5. The rider — `avm1/movieclip_hittest_shapeflag`: DROPPED, different mechanism

**Disposition check first (brief rule 2):** it is listed in
`ruffle-tests/ignored_tests.txt:220` and carries **three**
`avm1/_investigation/ACCEPTED_DIFFS.md` entries — Noto Sans vs Flash device-font
glyph outlines, morph fill boundary float-vs-integer precision, and drawing-API
stroke tessellation at a curve boundary.

Re-tested anyway (an ignore entry is a claim, not a verdict). It is **byte-identical
before and after** the patch, at 332/338 with 6 diff lines — and all 6 are the
**shape** arity (`hitTest(x, y, true)`), which is exactly the arity my change does
not touch:

```
 71  _level0.clip.hitTest(300, 400, true)  exp true  act false   (glyph outline)
171  _level0.clip.hitTest(390, 430, true)  exp true  act false   (glyph outline)
173  _level0.clip.hitTest(290, 450, true)  exp true  act false   (glyph outline)
175  _level0.clip.hitTest(190, 480, true)  exp true  act false   (glyph outline)
177  _level0.clip.hitTest(650, 430, true)  exp true  act false   (glyph outline)
296  _level0.clip.hitTest(400, 300, true)  exp false act true    (morph fill boundary)
```

The brief's "plausibly the same mechanism (shape-flag hit testing)" is **refuted**:
this test's residual is device-font and float-precision, not mask state. The SWF
does contain `setMask`, which is why it screened in — but no masker is ever
bbox-hit-tested in it.

**Completion mechanism for this NO-GO:** the glyph-outline lines need Flash's
proprietary device-font outlines (unobtainable — permanent), and line 296 needs
our curve winding solver moved to Ruffle's integer `lerp_twips` + i64
cross-product arithmetic. Both are already dispositioned; it stays on
`ignored_tests.txt`.

**Doc-drift note (not actioned, to avoid colliding with other avm1 agents):**
`ACCEPTED_DIFFS.md` documents 9 diff lines for this test (7 glyph + 1 morph + 1
scribble) at lines 71/163/165/167/171/175/177, 296 and 137. Only 6 remain, and the
drawing-API stroke line (137) and glyph lines 163/165/167 are **gone** — fixed by
some later session without the doc being updated. Someone should re-sync that
entry.

---

## 6. Regression sweep

Scope chosen from the mechanism, not from test names: the change can only be
observed by a `hitTest(x, y, falsy)` on a clip that `setMask` has made a masker
(`is_mask` is set in exactly one place, `avm1_mask_pair`, and `clipDepth` masks
never set it). A byte scan of every `.swf` in `avm1`, `from_gnash`, `from_shumway`,
`regression`, `timeline`, `visual`, `swf`, `text`, `mixed_avm`, `import_assets`,
`fonts` and `audio` (decompressing `CWS`) found **11 SWFs containing both
`setMask` and `hitTest`** — the whole observable radius. All 11 are in the sweep,
plus the picking / button / drag / mask-and-clipDepth neighbours the coordinator
asked for and the `regression` suite.

The sweep was **scoped by argument, then trimmed by argument** (the box was at
load 11.4 on 8 cores with the fleet running, ~200 s per compile). 24 candidates
screened, 7 run. Every drop is disqualified by the test's own expected output, not
by cost:

| dropped | why it cannot observe the change |
|---|---|
| `from_gnash/actionscript.all/MovieClip-v6`, `-v7`, `-v8` | screened in on the SWF *strings* only. Their expected output's sole references are `PASSED: MovieClip.prototype.hasOwnProperty("setMask")`, `typeof(mc.setMask) == 'function'`, `typeof(mc.hitTest) == 'function'` — existence checks. No pairing is ever made, nothing is ever hit-tested. (Also the three most expensive rows, ~900–1100 expected lines each.) |
| `from_gnash/actionscript.all/BitmapData-v8` | its one hitTest line is `Bitmap.prototype.hasOwnProperty('hitTest')` — that is `BitmapData.hitTest` (`bitmapDataHitTest`, registered at `action.c:14938`), a different builtin. |
| `avm1/netstream_play_flv_screen` | both strings present in the SWF, neither appears anywhere in its expected output — dead code path. |
| `avm1/movieclip_setmask`, `mask_reapply`, `mask_with_drawing` | pair masks but never call `hitTest` (byte scan), so an arity change in `hitTest` is unobservable. |
| `avm1/movieclip_hittest`, `hittest_lockroot`, `hittest_winding_rule`, `hittest_morph`; `from_gnash/actionscript.all/HitTest-v6/-v7/-v8`; `from_gnash/misc-ming.all/masks_test2`; `from_shumway/hitTestStyleChange` | call `hitTest` but contain no `setMask`, so no clip in them is ever a masker. (`masks_test2` masks by `clipDepth`, which never sets `is_mask` — that flag is written in exactly one place, `avm1_mask_pair`.) |

Scoping argument in one line: `is_mask` is set only by `setMask`, and the changed
branch is reached only when a clip with `is_mask` receives `hitTest(x, y, falsy)`.
A test must contain **both** to observe it. Picking, buttons, drag, AVM2 and the
render paths are covered by the §3 audit rather than by sampling.

**Results (all `--mode` default / no-graphics; mode parity is complete since s18):**

| test | before | after | verdict |
|---|---|---|---|
| `from_gnash/misc-ming.all/masks_test` | `output_mismatch` 124/175 | **`ruffle_matched`** | **the flip** |
| `avm1/movieclip_hittest_shapeflag` | `output_mismatch` 332/338 | `output_mismatch` 332/338, diff byte-identical | unchanged (rider, `IGN`+`ACC`) |
| `avm1/movieclip_invalid_get_bounds_6` | pass | **pass** | unchanged |
| `avm1/movieclip_invalid_get_bounds_7` | pass | **pass** | unchanged |
| `from_gnash/misc-ming.all/DrawingApiTest` | `output_mismatch` 81/93 act=95 (`RVF KF RTXT`) | `output_mismatch`, **actual output byte-identical** (A/B verified) | unchanged |
| `from_gnash/misc-ming.all/RollOverOutTest` | pass | **pass** | unchanged |
| `regression/mask_nested_intersect` | pass | **pass** | unchanged |
| `regression/mask_sibling_union` | pass | **pass** | unchanged |

**`pass → ruffle_matched` check (brief rule 3, the trap that bit s19 here):
NONE.** No test moved status in either direction except the intended `masks_test`
flip. `DrawingApiTest` was the only row that could plausibly have drifted — it
carries **74** `hitTest` assertions, 12 of which sit in its standing diff — so it
got an explicit A/B leg rather than a status comparison: patch reverted with
`git apply -R` (never `git stash` — `refs/stash` is shared across worktrees),
rebuilt, re-run, and its **actual output compared line by line against the patched
run — byte-identical**, then the patch re-applied. `RollOverOutTest`,
`regression/mask_nested_intersect` and `regression/mask_sibling_union` pass before
and after.

**Procedural note, for anyone reusing the runner.** The trim was first attempted by
rewriting the runner's worklist file in place, keeping the already-consumed lines
byte-identical so the `while read … done < file` loop would pick up the new tail at
its current fd offset. **That does not work**: the editor replaces the inode, so the
loop's open fd still sees the old content. The trim had to be done by stopping the
background task and relaunching with a short list. If you want a mid-flight-editable
worklist, the loop must re-read the file each iteration.

---

## 6b. Ignore lists and stale `_investigation/` entries for `masks_test`

Asked by the coordinator, and the answer is the expensive half.

**Ignore lists: nothing to do.** `masks_test` is **not** on `ruffle-tests/ignored_tests.txt`
and `from_gnash` has no per-suite `ignored_tests.txt` at all (only `from_shumway`,
`avm2` and `from_avmplus` carry one). It has always been graded. No un-ignore.

**`from_gnash/_investigation/` carries four stale entries, and one of them is
actively misleading.** All four still describe the row as `28/175` and blocked on
verifier work, which was the 2026-05-19 picture; s19 unblocked it and this session
closed it.

| file:line | what it says now | why it is wrong |
|---|---|---|
| `incomplete/REMAINING_TAIL_TRIAGE.md:668` | "**`masks_test`** (verifier change required) — needs synthetic keypress mechanism. Promote to standalone plan; this is verifier scope." | **The costly one.** It tells a future session this row needs *verifier* work. It never did: the real blocker was `actionNextFrame`'s deferred-goto arm on a stopped root (s19), and the residual after that was a one-line AVM1 `hitTest` arity bug. A slot taken on this line would have been spent in `verify_output.py`. **Replace with:** `~~masks_test~~ — CLOSED at ruffle_matched (s20). Not verifier scope: s19 fixed broadcaster-dispatch nextFrame, s20 fixed the hitTest bounding-box arity on maskers.` |
| `incomplete/REMAINING_TAIL_TRIAGE.md:470` | "graduated to `incomplete/MASKS_TEST_PLAN.md` (2026-05-19); blocked on synthetic-input infrastructure" | The blocker is gone twice over. |
| `incomplete/MASKS_TEST_PLAN.md` (whole file) | 2-phase plan; "blocked on synthetic-input infrastructure (auto-keypress or `--auto-keypress` flag)"; ":21 masks_test specifically does NOT have input.json"; ":39 28/175, 16.0%, output_mismatch" | The `:21` claim is **false today** — `masks_test/input.json` exists and drives the four `- Press any key to continue -` gates. The file should move `incomplete/` → `complete/` with a closing note. |
| `CURRENT_STATUS.md:190` | already struck through, but the cell still reads "2 phases. Blocked on synthetic-input infrastructure … Then re-baseline." | **Replace the cell with:** `CLOSED 2026-09-18 (s20): ruffle_matched. See SWFRecompDocs/plans/session20-fanout-reports/w2-masks-hittest-report.md.` |
| `incomplete/MISC_MING_SWFC_PLAN.md:39, :99` | lists `masks_test` among the open single-test residuals | drop it from both lists. |

I did **not** edit these myself: `from_gnash/_investigation/` is shared with the
gnash-family agents running this session (`w1-gnash-array`, the `action_order`
owner), and a concurrent edit there is a merge conflict for zero graded value.
Exact replacement text is above for whoever lands it.

---

## 7. Refutations (summary)

1. **"`masks_test` flips only when all 50 diff lines go; if the residual 16 is an
   open tail this row is worth 0 flips."** Refuted. The row is `known_failure`, the
   target is `ruffle_matched`, and the residual 16 is Ruffle's own diff set
   verbatim. One mechanism, +1 effective.
2. **"34 of 50 lines are `hitTest` on masked/mask clips."** Confirmed but
   under-specified: all 34 are the **bounding-box** arity on **masker** clips, and
   every shape-arity line we fail is one Ruffle fails too. That split is what made
   the fix a one-liner.
3. **"This is a hit-test slice, not an events one" (s19).** Confirmed. Nothing in
   the residual touches the broadcaster / `nextFrame` machinery s19 fixed.
4. **"Rider `movieclip_hittest_shapeflag` plausibly shares the mechanism."**
   Refuted — see §5. Byte-identical across the patch.
5. **"AVM hitTest skips masks" (the in-tree comment, since s-unknown).** Refuted
   against the oracle: Ruffle skips masks only on the shape arity.

---

## 8. New unclaimed leads

1. **`masks_test` can go from `ruffle_matched` to a full `pass` (+0 effective, but
   it would beat Ruffle).** The remaining 14 are circular-mask semantics: after
   phase 3 the pairs are mutual (`sm2` masks `sm3` *and* `sm3` masks `sm2`), and
   Flash answers `true` to the shape arity where Ruffle answers `false`. Our
   `avm1_mask_pair` keeps both directions live, so the state is already modelled;
   only the shape-arity masker rule would need a "…unless the masker is itself
   masked by its own maskee" carve-out. **Value: 0 effective**, so this is a
   correctness-only lead — do not spend a slot on it.
2. **`ACCEPTED_DIFFS.md`'s `movieclip_hittest_shapeflag` entries are stale** (9
   documented lines, 6 real; the scribble-stroke case and three glyph lines are
   fixed). A cheap doc re-sync for whoever next owns the avm1 disposition docs.
3. **`from_gnash/misc-ming.all/masks_test2` and `avm1/mask_reapply` /
   `movieclip_setmask` / `mask_with_drawing` all pass**, so the setMask registry
   itself is in good shape. The only remaining trace row in the mask family after
   this patch is the *picking* side — `avm1/hitarea_remove_owner_drag` (2/10),
   already owned and priced elsewhere in §20.5.
4. **`getBounds` on a masker was never checked.** Ruffle's bounds are
   mask-independent (same reason `hit_test_bounds` is), and our
   `COMPUTE_GLOBAL_AABB` is shared between `hitTest` and (separately)
   `getBounds`/`getRect`. No corpus row currently fails on it, but if one appears,
   the fix shape is the same one-liner.
