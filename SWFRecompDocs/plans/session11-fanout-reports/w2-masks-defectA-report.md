# wave-2 `w2-masks-defectA` — per-mask stencil isolation, shipped

Session 11, wave 2. Implemented in an ISOLATED worktree
(`.claude/worktrees/agent-aeb8cc9c7f9f8c3dc`); **the main tree was never
modified** except for this report and the patch beside it. Test dirs were
COPIED into the worktree at their canonical suite paths, `SWFRecomp/build` was
copied from the main tree (runtime-only diff), every leg used `--recompile`.
No commits, no pushes.

Pins verified: the worktree's HEAD is `b4c983ea4` and `bed9d894b` adds **only**
the eight wave-1 report files (`git diff --stat b4c983ea4 bed9d894b` = 8 `.md`,
0 code), so the code at HEAD *is* the code at the pin. All five file:line
claims in `wave1-gfx-masks.md` §1 re-verified before editing.

Deliverable patch: `w2-masks-defectA.patch` (563 lines, `git diff --binary`,
new files `git add -N`'d).

---

## 0. Headline

| | |
|---|---|
| slice canary (report §4, 18 tests / 36 comparisons) | **33 IDENTICAL, 3 DIFFERS** — the exact predicted ledger |
| standing canary (`render_canary_tests.txt`, 20 tests / 37 comparisons) | **36 IDENTICAL, 1 DIFFERS** (`masks`, already in the ledger) |
| the 3 designated controls | **all IDENTICAL** |
| the 2 traps (`acid-clip-2` 2881/3000, `invalidClipDepth` 257 ranges) | **both IDENTICAL** |
| the 22 text comparisons | **all IDENTICAL** (reproduces wave-1) |
| **flips** | **2** — `from_shumway/acid/acid-clip` fail→pass, and the new `regression/mask_sibling_union` fail→pass |
| band moves | `visual/simple_shapes/{masks, masks_equal_clipdepth}` 248261 → **11000** (−95.6 %), exactly wave-1's predicted landing value |

Wave-1's go/no-go said "0 flips". That was right *for the union-only
diagnostic*. Productionising it — which per the brief also had to fix the six
mask-blind pipeline clobbers, the two hard-coded composite stencil references
and the `tagRerenderFrame` ordering bug — buys **one real corpus flip** on top,
because `acid-clip`'s dominant artifact (the "large pink Y painted unclipped
over the centre of the stage") was a *clobber*, not the union. Wave-1 could not
see that: its 3-edit diagnostic deliberately left every clobber site alone.

---

## 1. What shipped

### 1.1 Design choice: monotonic per-mask reference (not clear-per-mask)

The brief allowed either. Monotonic wins on three counts:

* **It is the measured change.** Wave-1's byte-exact A/B (33/36 identical) was
  a monotonic reference. Clear-per-mask has no measurement behind it.
* **Zero added draw calls in the common case.** Clear-per-mask needs a
  screen-covering stencil rewrite *per mask*; monotonic needs one only on
  wraparound, which no corpus test reaches.
* **A screen-covering rect is the risky primitive here**, because the stage
  transform is arbitrary when a mask opens (`renderer_upload_stage_transform`
  may have installed a root xform). Monotonic confines that risk to the
  wraparound path; clear-per-mask puts it on every mask.

The increment/decrement mask STACK sketched in wave-1 §6 (Equal/IncrementClamp
write + Equal/DecrementClamp clear + a full-screen decrement draw) is the only
design that also gives nesting *intersection* and restores an enclosing mask —
**deliberately not shipped.** It is out of the brief's scope, it needs a
per-loop clip stack in `tag.c` (three loops) to keep begin/end balanced, and an
unbalanced begin under it leaves content clipped *longer* than today, which is
a regression shape monotonic structurally cannot produce. §5 ships its pin test
ready to drop in.

### 1.2 `render_webgpu.c` / `.h` — the mechanism

Two new context fields do the work, plus three bookkeeping ones:

```
mask_ref           stencil reference of the ACTIVE clip (0 = none)
mask_ref_next      per-pass monotonic allocator, 1..255
mask_capture_depth >0 while writing mask geometry (nested sprite masks)
mask_save_sp / mask_save_ref[8] / mask_save_cap[8]   parked across offscreen passes
```

* **`open_pass`** — the stencil `Clear` there is the only stencil reset in the
  pass, so references must be unique *within* it: the allocator restarts
  alongside `stencilClearValue = 0`.
* **`begin_clip_mask`** — allocates a fresh reference and binds
  `stencil_write` at it. Was: `SetStencilReference(…, 1)`, unconditionally.
* **`end_clip_mask`** — binds `stencil_test` at *this* mask's reference.
* **`end_clip`** — clears `mask_ref` and goes through the restore helper.
* **Nested-capture guard.** A mask that is a SPRITE re-enters the display-list
  walk (`tag.c` `g_clip_mask_capture`), and a `clipDepth` entry inside that
  subtree calls `begin/end_clip_mask` again. `mask_capture_depth` makes those
  inner pairs no-ops, so the allocator cannot walk away from the outer mask and
  the inner `end_clip_mask` cannot switch **colour writes back on** in the
  middle of a mask capture (a latent bug at HEAD, independent of defect A).
  `end_clip` is likewise ignored while a capture is open. This is wave-1 §6
  item 8, implemented **entirely inside the renderer** — zero `tag.c` cost.
* **Wraparound.** At 255 masks in one pass the references would alias and the
  union bug would return. `alloc_mask_ref` falls back to a mid-pass clear: a
  screen-covering rect through `stencil_write` (Always/Replace, colour writes
  off) at reference 0 rewrites every texel to 0, then the allocator restarts.
  Unreachable in the corpus (busiest frame = 6 masks; `invalidClipDepth`'s 257
  are one *per frame*), reachable in a real movie.

### 1.3 The six clobber sites + the two composite references

One helper, `static void restore_draw_pipeline(ctx)` =
`mask_ref ? stencil_test @ mask_ref : render_pipeline`. Every site that
clobbered the pipeline for its own draw now returns through it:

| was | site | note |
|---|---|---|
| `SetPipeline(render_pipeline)` | `draw_bitmap_quad_scaled` | bitmap inside a mask keeps its clip |
| `SetPipeline(render_pipeline)` | `draw_bitmap_tris` | ditto |
| `SetPipeline(render_pipeline)` | `composite_blend` | layer composite inside a mask |
| `SetPipeline(render_pipeline)` | `resume_pass` | stencil is `loadOp = Load`, so the clip is still there |
| `SetPipeline(render_pipeline)` | `begin_offscreen_pass` | resolves to `render_pipeline` (state parked, §1.4) |
| `SetPipeline(render_pipeline)` | `composite_filtered` | filtered object inside a mask |
| `default: pipeline = render_pipeline` | `set_blend_mode` | this is also how the loops UNDO a blend (`set_blend_mode(ctx, 0)`) |

Two hard-coded stencil references also had to move:

* `composite_blend(…, stencil_ref)` — callers pass
  `active_clip_depth > 0 ? 1 : 0`, i.e. a *boolean* that only worked while every
  mask wrote 1. The parameter is now ignored (`(void)`) and the reference comes
  from `ctx->mask_ref`; the ABI is unchanged so no caller needed touching.
* `composite_filtered` — hard-coded `SetStencilReference(…, 0)` against a
  pipeline that stencil-tests `Equal`, i.e. a filtered object inside a mask
  composited **outside** it. Now `ctx->mask_ref`; identical (0) when no clip is
  open, which is why nothing moved in the filter canaries.

`set_blend_mode`'s *non*-default arms bind legacy per-draw blend pipelines that
carry no stencil test at all — a blend-mode object inside a mask is still
unclipped for the duration of that draw. Left alone and commented: the
layer-composite path that the display loops actually use for non-trivial modes
*does* test the stencil, and adding stencil variants of five blend pipelines is
a separate change with no test behind it.

### 1.4 Offscreen-pass state parking

`begin_offscreen_pass` renders into its **own** depth-stencil which it CLEARS.
Without parking, two things break the moment the clobber sites start honouring
`mask_ref`: draws inside the offscreen pass would be stencil-tested against a
reference that is 0 everywhere there (→ everything discarded, a black object),
and a mask opened inside the subtree would zero the outer `mask_ref` that the
resumed main pass still needs. `{mask_ref, mask_capture_depth}` are pushed on
entry and popped in `end_offscreen_pass` (8-deep, clamped). The allocator is
deliberately *not* restored — references stay globally monotonic, and the
offscreen stencil starts at 0, so no aliasing is possible either way.

### 1.5 `tag.c` — one hunk

`tagRerenderFrame` (5451): the `if (obj->char_id == 0) continue;` sat **before**
the `i > active_clip_depth` end-of-range check, so an empty depth immediately
after a clip range never reached the check and the clip stayed active for the
next non-empty depth. Reordered to match `render_display_list` (3251-3259) and
`tagShowFrame` (6408-6416). **This is the only `tag.c` edit in the patch.**

---

## 2. Per-comparison band ledger

Outliers vs golden, `before` → `after`, from the `--json` reports of both legs
(not from a regenerated `image_results_graphics.json`).

### 2.1 Moved (3 comparisons)

| comparison | before | after | verdict |
|---|---|---|---|
| `visual/simple_shapes/masks [output]` | 248261 / 0 | **11000** / 0 | fail → fail (band move) |
| `visual/simple_shapes/masks_equal_clipdepth [output]` | 248261 / 0 | **11000** / 0 | fail → fail (byte-identical twin) |
| `from_shumway/acid/acid-clip [output]` | 19356 / 0 | **0** / 0 | **fail → PASS** |

`masks` landing at **exactly 11000** is the fence's headline check
(wave-1 §7.1: "must land at ≈11000, not lower and not higher"). Hit on the
nose. The residual is not mask error — it is the `quality = "low"` golden vs
our unconditional 4× MSAA (wave-1 §1), which a sibling agent owns.

### 2.2 Did not move (33 comparisons)

| group | comparisons | before = after |
|---|---|---|
| **control** `avm2/mask_reapply` | 1 | 36156 |
| **control** `from_shumway/acid/acid-clip-3` `[output]`,`[frame3]` | 2 | 78125, 81307 |
| **control** `visual/simple_shapes/text_field_mask` | 1 | 432212 |
| **trap** `from_shumway/acid/acid-clip-2` | 1 | 2881 / 3000 |
| **trap** `from_shumway/invalidClipDepth` | 1 | 0 / 0 |
| passing masks `avm1/{mask_with_drawing, movieclip_setmask, mask_reapply}`, `from_shumway/clipping`, `from_shumway/MaskTest-3` | 5 | 0 / 0 |
| text `edittext_selection_leading` ×12, `edittext_border_transform` ×6, `edittext_tag_indent`, `movieclip_create_text_field`, `edittext_scroll` ×2 | 22 | unchanged (incl. the six non-zero ones: 36, 36, 52/20, 45/20, 825/5, 821/5) |

All three controls IDENTICAL ⇒ the patch did not reach a mechanism it does not
own. Both traps IDENTICAL, not merely "still passing" (fence §7.2). All 22 text
comparisons IDENTICAL, reproducing wave-1's zero-blast-radius measurement
(fence §7.3).

### 2.3 Standing canary — the blast-radius net

`render_canary_tests.txt` (20 tests / 37 comparisons: filters proper ×2,
blend modes ×2, gradients ×3, bitmaps ×2, cacheAsBitmap, timeline ×7, winding,
colour transform, focus/input ×12, and the 3 standing `regression/` entries),
captured `beforeStd` (via `git stash`) vs `afterStd`:

```
IDENTICAL 36   DIFFERS 1   (visual/simple_shapes/masks — the ledger entry)
```

This is the leg that covers the clobber sites I touched. `visual/filters/*`,
`visual/blend_modes/multiply`, `avm2/blend_multiply_alpha`,
`avm1/bitmapdata_applyfilter_colormatrix`, `avm1/bitmap_data_fillrect`,
`visual/cache_as_bitmap/shape_changed`: **all byte-identical**.

### 2.4 Trace axis

`TRACE STATUS CHANGES: (none)` on both canaries. Note a correction to the
fence: wave-1 §7.4 says `MaskTest-3` "must stay `trace=pass`", but §2 of the
same report says its trace *is* `ruffle_matched`. My `before` leg settles it —
**`ruffle_matched` at HEAD**, `ruffle_matched` after. Unchanged, no regression;
§7.4's wording is the error.

### 2.5 Local-vs-CI grading

Every absolute number quoted above is from a test whose local `before` PNG I
verified byte-identical to the CI-published actual on
`origin/ruffle-image-results` (fetched, never checked out):

| test | local before md5 | CI `output.actual.png` md5 |
|---|---|---|
| `visual/simple_shapes/masks` | `c5fe3f4e` | `c5fe3f4e` |
| `visual/simple_shapes/masks_equal_clipdepth` | `c5fe3f4e` | `c5fe3f4e` |
| `visual/simple_shapes/text_field_mask` | `b8b37a8b` | `b8b37a8b` |
| `avm2/mask_reapply` | `cf83cccd` | `cf83cccd` |
| `from_shumway/acid/acid-clip` | `0607ec5a` | `0607ec5a` |
| `from_shumway/acid/acid-clip-3` | `4943b9b1` | `4943b9b1` |

**This refutes wave-1 §3.6 for `acid-clip`.** That report put local at 55362
outliers vs CI's 19356 and told wave-2 not to quote an absolute grade for it.
My before-leg reproduces CI's 19356 *and* the CI actual byte-for-byte, so the
fail→pass on `acid-clip` is a CI-credible flip, not a local artifact. (Wave-1's
55362 was presumably measured against a different golden basis.)
`acid-clip-2` and `from_shumway/clipping` pass on CI so no actual is published
for them; both were graded md5-only, and both are IDENTICAL.

---

## 3. 18-canary result, verbatim

```
RENDER CANARY  before=before  after=after   18 tests / 36 comparisons
  IDENTICAL    33
  DIFFERS       3
  APPEARED      0   VANISHED 0   NO_RENDER 0
  DIFFERS:
    from_shumway/acid/acid-clip  output   [DIFFERS]
        diff_channels 50062/880000  mean 6.6361  max 255   bbox (105,32)-(342,299)
        image status: fail -> pass    trace: pass -> pass
    visual/simple_shapes/masks  output   [DIFFERS]
        diff_channels 247332/880000  mean 62.2942  max 255   bbox (22,13)-(536,379)
        image status: fail -> fail    trace: pass -> pass
    visual/simple_shapes/masks_equal_clipdepth  output   [DIFFERS]
        diff_channels 247332/880000  mean 62.2942  max 255   bbox (22,13)-(536,379)
        image status: fail -> fail    trace: pass -> pass
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES:
    from_shumway/acid/acid-clip  output   fail -> pass        <-- REVIEW
```

The slice list is wave-1 §4 verbatim (18 tests). It was a scratch file and is
**not** in the patch; the standing `render_canary_tests.txt` gained one line
instead (§5).

---

## 4. Fence audit vs wave-1 §7

| # | requirement | result |
|---|---|---|
| 1 | exactly 3 entries may DIFFER; `masks`/`masks_equal_clipdepth` at ≈11000 | ✅ 3 DIFFERS, both at **exactly 11000** |
| 1 | the 3 controls must not move | ✅ `avm2/mask_reapply`, `acid-clip-3` ×2, `text_field_mask` all IDENTICAL |
| 2 | both traps IDENTICAL, not "still passing" | ✅ `acid-clip-2` 2881/3000 and `invalidClipDepth` 0/0, byte-identical |
| 3 | all passing text comparisons IDENTICAL | ✅ 22/22 sampled IDENTICAL, so the remaining 14 were not captured |
| 4 | `MaskTest-3` trace must not regress | ✅ `ruffle_matched` → `ruffle_matched` (see §2.4 — the fence's "pass" is wrong) |
| 5 | `render_webgpu.c` + `tag.c` only, no `SWFRecomp/` change | ✅ plus `render_webgpu.h` (the new fields) and three test-side files |
| 6 | absolute grades only where local == CI | ✅ verified for all 6 tests quoted (§2.5) |
| 7 | `known_failure` movement is not a flip | ✅ no `known_failure` comparison moved |
| 8 | closeout honesty | see §7 — **2 flips + 2 band moves**, and the flips are `acid-clip` + the new regression test, NOT the `masks` twins |

---

## 5. Regression tests

`regression/` had no mask, clip or `scrollRect` test. It has one now.

### R1 `mask_sibling_union` — ADDED, with a Ruffle golden

`ruffle-tests/tests/swfs/regression/mask_sibling_union/`
(`create_test_swf.py`, `test.swf`, `test.toml`, `output.txt`,
`output.expected.png`).

```
depth 1: shape A = rect   (0,0)-(100,100)  clipDepth = 2   -> masks depth 2
depth 2: shape B = rect   (0,0)-(200,200)  BLUE            <- masked by A
depth 3: shape C = rect (100,100)-(200,200) clipDepth = 4  -> masks depth 4
depth 4: shape D = rect   (0,0)-(200,200)  RED             <- masked by C
```

The golden-cost check the brief asked for came out **cheap**: the Ruffle
exporter binary is already built at `~/CC/ruffle/target/release/exporter`
(19 MB, Jul 22) — no cargo build, ~1 s per golden.
`exporter test.swf output.expected.png -s` produces **exactly** 20000 white /
10000 blue / 10000 red, three distinct colours, zero anti-aliased pixels. The
axis-aligned-rectangle design from wave-1 §5 works exactly as intended.

Measured, both legs local:

| | outliers | verdict |
|---|---|---|
| at HEAD | 20000 (max_diff 255) — red painted over the blue quadrant, 10000 px | **fail** |
| with the patch | **0** (max_diff **0**) — byte-exact against the Ruffle golden | **pass** |

`test.toml` is `tolerance = 0`, `max_outliers = 0`. This is the only mask
comparison in the corpus that is exact at tolerance 0 — the upstream twins
cannot be, because their goldens were exported with `quality = "low"`.
Registered in the suite `README.md` table and added to the standing
`render_canary_tests.txt` (tier 1).

### R2 `mask_nested_intersect` — built and validated, NOT added; ships as an artifact

`w2-masks-r2-mask_nested_intersect.py` (beside this report) is a complete,
runnable generator; its Ruffle golden is exact too (3600 green / 36400 white,
two colours). **It is not in the patch on purpose**: as wave-1 §5 predicted, a
distinct-reference-per-mask fix makes R1 pass but leaves R2 wrong.

| | green pixels | vs golden's 3600 |
|---|---|---|
| at HEAD | 25200 (M1 ∪ M2) | 21600 outliers |
| with this patch | 14400 (M2 alone) | **10800 outliers — still fails** |
| with the increment/decrement stack | 3600 (M1 ∩ M2) | 0 |

Adding it now would put a standing red row in a fully-green hand-written suite
for a gap this patch does not claim to close. It is ready to drop in with the
nesting work — the generator's docstring carries the `test.toml`, the
`output.txt` and the golden command.

### R3 `mask_edittext_stencil_scope` — design only

Not built. Unlike R1/R2 it is **not exact by construction**: it depends on
EditText layout (2 px gutter, baseline from the font ascent, leading, advance)
matching Ruffle's byte-for-byte, so its golden has to be diffed against our own
render before it can be committed or it lands as a permanent red row for a
reason that has nothing to do with masks. Also verify first that the glyph
callback fires at all — it early-returns at `tag.c:4704` when
`ng_find_font_with_metrics` fails. Full tag layout:

```
DefineFont3 id 256   one glyph: filled square [0,EM]x[0,EM], EM = 20480,
                     CodeTable glyph 0 -> 'A'
                     (lift build_statictext.py glyph_square() + define_font3())
DefineShape  id 1    rect (100,100)-(200,140) px   black
DefineShape  id 2    rect   (0,0)-(200,200) px     RED
DefineEditText id 3  bounds (0,100)-(80,140) px = (0,2000)-(1600,2800) twips
                     HasFont(256), FontHeight 400 twips (20 px),
                     UseOutlines + ReadOnly + NoSelect + HasText, text "AAAAAA"
PlaceObject2 depth 1 char 1 clipDepth = 2 / depth 2 char 2 / depth 3 char 3
```

Correct: red only in M's band, squares clipped at x ≈ 78. At HEAD the EditText
pass runs *after* the display loop, finds M still in the stencil, and its field
clip becomes M ∪ fieldRect. **With this patch it should pass** — the display
loop's `end_clip` has already zeroed `mask_ref`, so the field allocates a fresh
reference and its clip is exactly fieldRect.

---

## 6. Files touched

| file | hunks | what |
|---|---|---|
| `SWFModernRuntime/include/rendering/render_webgpu.h` | **1** (@159, +13) | the six new context fields, appended after `blend_shader_pl` |
| `SWFModernRuntime/src/rendering/render_webgpu.c` | **19** (+159/−19) | §6.1 |
| `SWFModernRuntime/src/libswf/tag.c` | **1** (@5451, +9/−4) | `tagRerenderFrame` ordering |
| `ruffle-tests/render_canary_tests.txt` | 1 (+2) | `regression/mask_sibling_union` in tier 1 |
| `ruffle-tests/tests/swfs/regression/README.md` | 1 (+1) | contents-table row |
| `ruffle-tests/tests/swfs/regression/mask_sibling_union/` | new, 5 files | R1 |

### 6.1 Every `render_webgpu.c` hunk, for the coordinator

A sibling agent is editing this file's MSAA sites (`multisample.count = 4` at
~1422 and the pipeline descriptors around 1400-1600). **My patch touches none
of them.** My lowest edit is at 1946; the whole pipeline-creation block
1380-1600 is untouched, so the two patches should not overlap at all.

Hunks, by `-U0` old-file line:

```
1945  open_pass                 reset mask_ref / mask_ref_next / mask_capture_depth / mask_save_sp
2084  (new, +53)                static restore_draw_pipeline() + static alloc_mask_ref()
2378  draw_bitmap_quad_scaled   clobber -> restore_draw_pipeline
2525  draw_bitmap_tris          clobber -> restore_draw_pipeline
2533/2536  begin_clip_mask      capture guard + alloc_mask_ref + per-mask ref
2542/2544  end_clip_mask        capture guard + per-mask ref
2549/2551  end_clip             capture guard + mask_ref = 0 + restore
2564/2565  set_blend_mode       default arm -> restore_draw_pipeline (+ comment)
3648/3652  composite_blend      stencil ref from ctx->mask_ref; clobber -> restore
3697  resume_pass               clobber -> restore
3710  begin_offscreen_pass      park {mask_ref, mask_capture_depth}
3742  begin_offscreen_pass      clobber -> restore
3752  end_offscreen_pass        un-park
3889/3892  composite_filtered   stencil ref 0 -> ctx->mask_ref; clobber -> restore
```

The `tag.c` hunk is a single 13-line window at 5451 — a sibling editing `tag.c`
elsewhere will not conflict; a sibling editing `tagRerenderFrame`'s clip loop
would.

---

## 7. Merge risks and closeout wording

* **`render_webgpu.c` MSAA sibling** — no overlap (§6.1). If that agent adds
  no-MSAA *duplicates* of `stencil_write_pipeline` / `stencil_test_pipeline`,
  those duplicates must also be selected inside `restore_draw_pipeline` and
  `begin/end_clip_mask`; that is the one place the two changes meet.
* **`tag.c` sibling** — one 13-line hunk, in `tagRerenderFrame` only.
* **`render_canary_tests.txt` / `regression/README.md`** — one-line appends;
  trivially mergeable.
* **`composite_blend`'s `stencil_ref` parameter is now ignored.** The signature
  is unchanged so nothing breaks, but anyone reading the callers
  (`active_clip_depth > 0 ? 1 : 0` in three `tag.c` loops) should know the value
  no longer reaches the GPU. Cleaning those call sites is a follow-up, not a
  requirement.
* **CI expectation.** `graphics`, `categories=all`, `images=false` per policy —
  the change is runtime-only and cannot move a trace. To *observe* the two
  pixel flips the coordinator needs an `images=true` baseline run; without one
  the corpus pixel count stays at its last published value.
* **Closeout wording.** Report this as **2 pixel flips**
  (`from_shumway/acid/acid-clip`, `regression/mask_sibling_union`) **+ 2 band
  moves** (`visual/simple_shapes/masks`, `masks_equal_clipdepth`, 248261 →
  11000 each). Do **not** book the `masks` twins as progress — they are
  AA-blocked by `quality = "low"` goldens and will only flip when the MSAA
  sibling's work lands. Note that `mask_sibling_union` adds one comparison to
  the pixel denominator (566 → 567).

---

## 8. Still open (unchanged owners)

Defect B (`setMask` on display-list content), defect C (`scrollRect` stub),
defect D / the AVM2 render walk, the "mask does nothing at all in the `tag.c`
path" bucket (`avm2/mask_reapply`, which stayed at 36156 exactly as wave-1
predicted), nesting *intersection* (R2's 10800 residual), and the corpus-wide
`quality = "low"` MSAA lead. Defect A no longer blocks any of them.
