# wave-2 `gfx-stencil` — Equal/IncrementClamp stencil nesting (IMPLEMENTATION)

Session 14, wave 2. Worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ac8f288dc1f172f6f`,
base `0a99be1a9`. Brief:
`SWFRecompDocs/plans/session14-fanout-reports/wave1-gfx-stencil.md`.
Patch: `wave2/w2-gfx-stencil.patch` (`git apply --binary`, reverse-apply
verified against the working tree). Nothing committed.

---

## 0. Headline

| | |
|---|---|
| **Flips delivered** | **7 graded comparisons**: `visual/cache_as_bitmap/masks` `output.01`–`.06` (fail → pass) + the new `regression/mask_nested_intersect` (new, passes) |
| **Predicted-but-missed** | `avm2/displayobject_scrollrect` — 12 382 → **10** channels (5 px), still FAIL at `tolerance = 0`. Residual is a 1-sample edge tie on the *green sibling*, not a mask defect (§3.1) |
| **Unpredicted mover** | `visual/simple_shapes/masks` + `masks_equal_clipdepth` — 2 624 → **1 738** channels each, still FAIL. **Every one of the 443 changed pixels went from wrong to matching the golden**; ACCEPTED_DIFFS amended (§3.3) |
| **Canary** | 44/49 tests md5-IDENTICAL; the 5 that DIFFER are exactly the ledger above. `cab_mask_transform` IDENTICAL → the wave-1 refutation holds |
| **Trace axis** | 49/49 trace statuses unchanged (47 pass / 1 output_mismatch / 1 ruffle_matched, both histograms identical). `MaskTest-3` stayed `ruffle_matched` |
| **Leg-1 hygiene** | 15/15 md5-IDENTICAL on the clip-heavy set, as required, plus a static proof (§2) |

---

## 1. What shipped

### 1.1 Renderer — the stencil is now a nesting counter

`ctx->mask_ref` is redefined from "this mask's unique reference" to **Ruffle's
`num_masks`: the nesting LEVEL**. Because the level *is* the stencil reference
under that model, all 20 existing `clip_ref` / `restore_clip` /
`SetStencilReference(ctx->mask_ref)` call sites (including the three
composite/filter ones) kept working untouched, exactly as the brief predicted.

| site | change |
|---|---|
| `render_webgpu.c` pipeline creation | `stencil_write_pipeline`: `Always/Replace` → **`Equal`/`IncrementClamp`** |
| " | **new `stencil_clear_pipeline`**: `Equal`/`DecrementClamp`, colour writes off, `multisample.count = MSAA_SAMPLES` (inherited from the shared `rp_desc` — no literal 4 anywhere), no vertex buffer, and deliberately the **same pipeline layout** as `render_pipeline` so the pass's three bind groups are not unset by the pop draw |
| " (new WGSL, above `create_pipelines`) | `stencil_clear_wgsl` — 6-vertex full-screen **NDC quad** from `@builtin(vertex_index)`, modelled on `blend_shader_wgsl_head`. NOT `render_webgpu_draw_rect` (silently no-ops when the dynamic staging is full → a skipped pop would corrupt the stencil for the rest of the frame; also transform-dependent) |
| `alloc_mask_ref` (25 lines) | **deleted**, with `mask_ref_next` and its per-pass reset. `IncrementClamp` saturates at 255 by construction; `begin_clip_mask` carries a `< 255` guard |
| `begin_clip_mask` | keeps the `mask_capture_depth++ > 0` early-out; then `mask_ref++`, bind write, `SetStencilReference(mask_ref - 1)` (= Ruffle's `push_mask`) |
| `end_clip_mask` | unchanged in shape: bind test at `mask_ref` (= `activate_mask`) |
| `end_clip` | was `mask_ref = 0` (dropped ANY enclosing clip); now pops **exactly one level** via `restore_clip(mask_ref - 1)` |
| `restore_clip(ref)` | pops one level at a time until `mask_ref == ref`, each pop = `pop_mask_level()`: bind clear pipeline, `SetStencilReference(mask_ref)`, draw the NDC quad, `mask_ref--`. Clamps a would-be raise (`ref > mask_ref`) instead of pretending texels came back |
| `render_webgpu.h` | `mask_ref_next` dropped; new `stencil_clear_pipeline` handle; the clip-mask block comment rewritten to describe the counter model |
| offscreen park comment | updated — the parked value is a level, and the offscreen pass's own `stencilClearValue = 0` is exactly that level |

**Why a full-screen decrement instead of Ruffle's geometry replay**: Ruffle
re-draws the masker (`display_object.rs:1256-1269`); we would have to plumb
"re-draw this masker" through five push sites. `Equal(level)` selects precisely
the texels the innermost mask raised, so the quad is equivalent as long as pops
are LIFO — which §1.2 enforces. Cost: one extra draw call per pop.

### 1.2 `tag.c` — pop-before-push hygiene (leg 1), exactly the three named sites

`3528` `render_display_list` (pops with `renderer_restore_clip(context,
pre_clip_ref)`, the variable already there), `5846` `tagRerenderFrame` and
`6814` `tagShowFrame` (pop with `renderer_end_clip`, which under the new model
pops exactly the one level those loops own — this kept the edit inside the three
named sites instead of introducing a `pre_clip_ref` and converting four more
`end_clip` calls, per the coordinator's minimal-footprint instruction).

Without this, a clipDepth entry appearing while an earlier range is still open
pushed a second level with no matching pop and **leaked it for the rest of the
frame**. `avm2_render_node` already had this shape and is untouched.

### 1.3 New regression test — `regression/mask_nested_intersect`

Shipped from session 11's held-back generator
(`session11-fanout-reports/w2-masks-r2-mask_nested_intersect.py`), docstring
rewritten for provenance. Golden exported with
`~/CC/ruffle/target/release/exporter test.swf output.expected.png -s` (the only
legal provenance for a `regression` golden, playbook §7) and verified to be
exactly what the docstring predicts: **3 600 green + 36 400 white, two colours,
no anti-aliasing**. Added to `render_canary_tests.txt`.

It discriminates all three stencil models: 25 200 green px at s11 HEAD, 14 400
under a per-mask-reference fix, 3 600 only under increment/decrement. At the
`before` leg it fails with 32 400 outlier channels; with the patch it **passes
at `tolerance = 0`**.

### 1.4 Comment-only

`avm2_display.c` ×2: the scrollRect push-order rationale (order unchanged — s13
defect C's code is untouched, only its "the inner one wins" justification is now
"both apply, which is what Ruffle renders") and the AVM2 clip-loop comment's
"nesting does not intersect" caveat, which is no longer true. The s12 EditText
guard at `avm2_display.c:15354` was deliberately **left in place** (brief trap 7
— removing it moves ~66 text comparisons and must not ride on this patch).

---

## 2. Leg 1 — md5-identity proof

Captured as a separate leg against `before`, per the brief's risk fence.

```
15 IDENTICAL, 0 DIFFERS   (md5 per comparison PNG; trace status also unchanged)
from_shumway/invalidClipDepth   (257 clip ranges — the pop-before-push canary)
from_shumway/clipping, acid-clip, acid-clip-2, acid-clip-3, MaskTest
visual/simple_shapes/masks, masks_equal_clipdepth
visual/cache_as_bitmap/masks    (7 comparisons)
avm1/mask_reapply, avm1/movieclip_setmask, avm2/mask_reapply
avm2/displayobject_scrollrect
regression/mask_sibling_union, regression/mask_nested_intersect
```

The set is the reachability closure that matters: the edit lives inside
`if (obj->clip_depth > 0)`, so a test with no clip range cannot execute it.
It is also neutral **by construction** under the old model — the pop emits only
`SetPipeline` + `SetStencilReference`, and the immediately following
`begin_clip_mask` overwrites both, with **no draw call in between**. Empirics
and the static argument agree.

(The remaining 34 canary tests were graded in the leg-2 A/B instead of a
third full capture; the machine was carrying four concurrent agents and a
capture leg cost 30–70 min.)

---

## 3. Leg 2 — per-beneficiary absolute numbers

Local Dawn is md5-identical to the CI actual for these comparisons (wave-1
§3.3, re-confirmed: the `before` leg reproduces the CI channel counts
**exactly** — 12 382 / 1 690 / 2 701 / 2 170 / 1 777 / 1 769 / 709), so these
are CI-grade absolute numbers, not just A/B deltas.

### 3.1 `avm2/displayobject_scrollrect` — 12 382 → 10, NOT a flip

```
before: 12382 channels (6191 px) — child crop tested its own full rectangle,
        and the green sibling was punched out entirely (0 green px on stage)
after :    10 channels (5 px)  — G/B swapped on 5 isolated pixels
        (100,94) (92,106) (92,107) (108,135) (109,136)
        actual (0,255,0) [green sibling]  expected (0,0,255) [blue circle]
```

The intersection and the parent-crop hole are **both fixed**: 6 186 of 6 191
wrong pixels are gone, including all 519 missing-green ones. What is left is a
1-sample coverage tie on the green sibling's own edge — a shape the golden and
our render only started to *both* contain because of this patch, so the tie
could not have shown before. `quality = "low"` ⇒ `MSAA_SAMPLES = 1`, the same
`a_epsilon`/`hairline_edge_drift` family as `avm2/displayobject_mask` and
`from_shumway/MaskTest`. At `tolerance = 0, max_outliers = 0` it stays FAIL.

**Wave 1 predicted an exact 0 here; that was the one miss.** The prediction was
built from "expected blue ⊆ our blue", which held — the residual is on a
different object.

### 3.2 `visual/cache_as_bitmap/masks` — six flips, budgets and margins

Three checks per comparison: `>10 ≤ 3200`, `>64 ≤ 350`, `>128 ≤ 0` (a
comparison passes if ANY check passes; all three now pass).

| cmp | before `>10/>64/>128` | after `>10/>64/>128` | headroom `>10` | headroom `>64` | verdict |
|---|---|---|---:|---:|---|
| `.01` | 4839 / 1992 / 1690 | **3075 / 269 / 0** | 125 | 81 | **PASS** |
| `.02` | 5811 / 3074 / 2701 | **2968 / 294 / 0** | 232 | 56 | **PASS** |
| `.03` | 5231 / 2500 / 2170 | **2989 / 289 / 0** | 211 | 61 | **PASS** |
| `.04` | 4972 / 2080 / 1777 | **3094 / 272 / 0** | 106 | 78 | **PASS** |
| `.05` | 4776 / 2051 / 1769 | **2964 / 258 / 0** | 236 | 92 | **PASS** |
| `.06` | 3340 / 973 / 709 | **2623 / 257 / 0** | 577 | 93 | **PASS** |
| `.07` | 2520 / 246 / 0 | **2520 / 246 / 0** | 680 | 104 | pass (unchanged — the must-hold held, byte-identical) |

Wave 1 predicted 3087/269, 2980/294, 3001/289, 3106/270, 2973/260, 2625/259 —
within 13 channels on every row. The tightest margin is `.04` at 106/3200
(3.3%); `>128` is 0 exactly, i.e. row 3 (mask ∩ scrollRect) now renders like
row 2, which is what `.07` predicted. `quality = "high"` ⇒ this family is the
**4-sample** MSAA arm; `displayobject_scrollrect` and both regression masks are
the 1-sample arm. Both arms exercised, no arm-specific defect.

### 3.3 `visual/simple_shapes/masks` + `masks_equal_clipdepth` — 2 624 → 1 738 (band move, HARD-dispositioned)

Not predicted; explained and audited rather than waved through.

```
before vs golden : 1095 mismatching px      after vs golden : 652
before vs after  :  443 px changed, ALL of them wrong→right
     413 px  (255,0,0) → (255,255,255)      [golden: white]
      30 px  (0,153,255) → (255,255,255)    [golden: white]
   443 = 1095 - 652 exactly: no pixel moved AWAY from the golden
```

Those 443 were mask content painting *outside* its clip — over-paint the flat
`Always/Replace` stencil could not contain (it abandoned a mask's texels instead
of popping them). The surviving residual (482 px black-vs-white plus the
saturated-colour swaps) is the documented 1-sample rasteriser tie; both
comparisons still FAIL at `tolerance = 0`, so the disposition stands. I amended
the ACCEPTED_DIFFS entry (it claimed "the mask machinery in these two tests is
correct" — partially refuted) and flagged its counts for re-baselining from the
first `images=true` run carrying this patch.

### 3.4 Everything else — 44/49 IDENTICAL

Byte-identical, in the brief's risk order: `acid-clip-2` (the corpus's most
fragile pass), `invalidClipDepth`, `acid-clip`, `acid-clip-3`, `clipping`,
`MaskTest-3` (trace still `ruffle_matched`), `avm1/mask_reapply` (defect B's
hard gate), `avm2/mask_reapply`, `movieclip_setmask`, `mask_with_drawing`,
`regression/mask_sibling_union`, `avm2/blend_scroll`,
`focus_highlight_empty_clip`; the EditText blast radius
(`edittext_tag_indent`, `edittext_border_transform` ×6, `edittext_scroll` ×2,
`edittext_hscroll` ×2, `acid-textfield-scroll`, `text/auto_size/return`); the
filter/blend blast radius (`drop_shadow`, `blur_quality`, `color_matrix`,
`blend_modes/multiply`, `blend_modes/add`, `avm2/blend_multiply_alpha`); the
`a_epsilon` tripwires (`avm2/displayobject_mask`, `from_shumway/MaskTest`,
`visual/avm2_button_scroll_rect`, `avm2/mouse_pick_dobj_mask`); the s13 defect
B/C tests (`visual/simple_shapes/text_field_mask`, `scroll_rect_mask`); and the
classification discriminator **`visual/cache_as_bitmap/cab_mask_transform`
(IDENTICAL → wave 1 §4.2's refutation of the `cab_mask_*` riders holds)**.

Trace axis: no status changed anywhere (§0). A no-graphics build of
`regression/mask_sibling_union` also compiles and passes, confirming the shared
`tag.c` edit is inert there (`renderer_*` are no-ops under `NO_GRAPHICS`).

---

## 4. Expected CI ledger

| comparison | baseline | expected | confidence |
|---|---:|---|---|
| `visual/cache_as_bitmap/masks [output.01]` | 1690 | **PASS** (3075/3200) | HIGH — local == CI actual on the before leg |
| `… [.02]` | 2701 | **PASS** (2968/3200) | HIGH |
| `… [.03]` | 2170 | **PASS** (2989/3200) | HIGH |
| `… [.04]` | 1777 | **PASS** (3094/3200, 3.3% margin) | MED-HIGH |
| `… [.05]` | 1769 | **PASS** (2964/3200) | HIGH |
| `… [.06]` | 709 | **PASS** (2623/3200) | HIGH |
| `… [.07]` | pass | pass, byte-identical | HIGH |
| `regression/mask_nested_intersect [output]` | new | **PASS**, tol 0 | HIGH (axis-aligned, AA-free) |
| `avm2/displayobject_scrollrect [output]` | 12382 | fail, 10 | HIGH |
| `visual/simple_shapes/masks`, `masks_equal_clipdepth` | 2624 ×2 | fail, 1738 ×2 | HIGH |
| everything else in the canary | — | unchanged | 44/49 md5-identical locally |

**Net: +7 graded comparisons** (6 flips + 1 new test), 0 predicted regressions.

---

## 5. Merge notes for the coordinator

**Files touched** (all inside the worktree):

```
SWFModernRuntime/src/rendering/render_webgpu.c      (~180 lines)
SWFModernRuntime/include/rendering/render_webgpu.h  (pipeline handle + block comment)
SWFModernRuntime/src/libswf/tag.c                   (+35, three sites only)
SWFModernRuntime/src/avm2/avm2_display.c            (comment-only, 2 hunks)
ruffle-tests/render_canary_tests.txt                (+4 lines)
ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md  (+15, one amendment)
ruffle-tests/tests/swfs/regression/mask_nested_intersect/{create_test_swf.py,
    test.swf, test.toml, output.txt, output.expected.png}       (new)
```

`render_webgpu.c` regions, for stacking against `gfx-bitmapfill`: (a) a new
static WGSL string immediately above `create_pipelines` (~line 1295), (b) inside
`create_pipelines`, the `stencil_write_pipeline` block and a new block between
`stencil_test_pipeline` and the blend pipelines (~1447-1520), (c) the pass-open
mask reset (~1990), (d) `alloc_mask_ref` → `pop_mask_level` (~2150), (e) the
clip-mask API (~2640-2710), (f) one comment in `begin_offscreen_pass` (~4180).
Nothing near the bitmap-fill WGSL (~142) or the `bitmap_sizes` upload
(~2932-2936); no reflow.

**Semantic-conflict check the coordinator asked for — what a correct
`begin_clip_mask`/`end_clip_mask` pairing looks like for a caller written on
baseline** (relevant to `gfx-scrollrect`'s new clip push in
`render_display_list` ~3587):

1. `begin_clip_mask` … mask geometry … `end_clip_mask` is unchanged and still
   the right way to open a clip. A caller that only uses the public API needs
   **no edit**.
2. What changed is the *close*. `renderer_end_clip` no longer means "there is
   now no clip"; it means "pop one level". A caller that opened exactly one
   mask and closes with `end_clip` is correct. A caller that opened one mask
   and expected `end_clip` to also drop an *enclosing* clip is now wrong — that
   behaviour is gone (and it was a bug: it is what dropped the outer clip for
   later siblings).
3. **Every push must reach exactly one pop on every path** (`continue`,
   `break`, early `return` included). Under `Always/Replace` an unbalanced pair
   self-healed at the next `end_clip`; under a counter it leaks a level for the
   rest of the frame. The safest form for a new nested push is the
   `saved = renderer_clip_ref(context); … renderer_restore_clip(context, saved);`
   pair (what `avm1_mask_push` and the AVM2 walk use), which is pop-count-exact
   by construction.
4. Pops must be **LIFO**. `restore_clip` clamps a raise, so an out-of-order
   restore silently under-pops rather than corrupting the stencil, but it will
   render wrong.
5. A scrollRect-style crop pushed *inside* a `.mask` now **intersects** it
   rather than replacing it — that is Ruffle's semantics
   (`display_object.rs:1216-1229`) and is the intended interaction, not a
   conflict.

**Follow-ups deliberately NOT in this patch**: removing the s12 EditText guard
(`avm2_display.c:15354`, ~66 text comparisons); converting `tag.c`'s
`tagRerenderFrame`/`tagShowFrame` range-end `end_clip` calls to explicit
`clip_ref`/`restore_clip` pairs (cosmetic under the new model); giving the
three `tag.c` loops Ruffle's real `clip_depth_stack` so nested clip ranges
intersect instead of being flattened by the leg-1 pop (Ruffle
`container.rs:553-593` — our loops still track one scalar).

**Reproduce**: `render_canary.py capture` legs live in
`<scratch>/gfx-stencil/canary/{before,leg1,leg2}` with per-test `meta.json`
(md5s + `image_stats`); `<scratch>/gfx-stencil/{cmp.py,grade.py,pixdiff.py}`
are the manifest-free comparator, the per-band grader (CI's exact arithmetic)
and the colour-pair differ. Note for future sessions: sibling agents `pkill`ed
my capture twice by name — the legs above were captured through renamed copies
of `verify_output.py`/`render_canary.py`, since deleted.
