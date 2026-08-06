# w2-advance-u16 — DefineFont2/3 layout advance is UNSIGNED

Agent `w2-advance-u16`, session 13 wave 2. Base HEAD `10931d62e`, isolated
worktree `agent-a01a7b03ea563e62a`. Deliverables: `w2-advance-u16.patch`
(5 files, +39/−26) and this report. **Nothing committed anywhere.**

Design source: `SWFRecompDocs/plans/session12-fanout-reports/w2-gfx-autosize-report.md`
**§6.1** (the task brief said §7; §7 is that report's merge-notes section — §6.1
"`visual/fonts/advance_u16` — SOLVED, ~20 min of mechanical work" is the actual
"solved, unshipped: generated-ABI reach" design, and it is what I implemented).
Its predecessor pin is `wave1-gfx-text.md` §E.

---

## 0. Headline result

| | |
|---|---|
| **Image comparison flips (fail → pass)** | **1** — `visual/fonts/advance_u16 [output]` |
| Regressions (pass → fail), pixels | **0** |
| Regressions (pass → fail), trace | **0** |
| Byte-identical (md5) canary comparisons | **48 of 49** |
| Trace status changes across 32 render-canary tests | **0** |
| Extra pure-trace text canary | **11 of 11 pass** |

The flip is an **absolute local verdict**, not an A/B guess:

```
before  FAIL  216 outliers (limit 0), max_diff 255, diff_channels 264/160000
after   PASS    0 outliers (limit 0), max_diff   1, diff_channels  48/160000
```

(`verify_output.compare_images`, the same function CI grades with, tolerance
128 / max_outliers 0 from the test's own `test.toml`.) The A/B bbox is
`(324,2)-(333,20)` — exactly the `x[324,332] y[2,19]` "one glyph too narrow /
absent" region `wave1-gfx-text.md` §E reported.

---

## 1. The bug, confirmed on this tree

`visual/fonts/advance_u16` (AVM1, `createTextField` + embedded `TestFont`,
`text = "aa\nbab"`) carries a DefineFont2 layout advance of **33000** twips on
glyph 0. Ruffle reads that field with `read_u16` (`swf/src/read.rs:1079`,
`Glyph::advance: u16`). We read `SWF_FIELD_SI16`, so 33000 wrapped to −32536
and the second `a` was laid out at x ≈ −317 instead of x ≈ 324 and never drawn.

Generated ABI at HEAD, verbatim:

```c
/* ruffle-tests/.../advance_u16/RecompiledTags/tagMain.c:39  BEFORE */
static const s16 font_1_advances[] = {-32536,102,819,102};
/* AFTER */
static const s32 font_1_advances[] = {33000,102,819,102};
```

**Corroboration that u16 is right, not a Ruffle quirk:** our own AVM2 font path
already does it — `SWFRecomp/src/abc/abc_timeline.cpp:1457` is
`fd.advances.push_back((int32_t) body.u16())`, emitting `static const int32_t
font_N_advances[]`, and `avm2_text.c`'s bundled Noto table is `int32_t`. Only
the legacy/AVM1 `swf.cpp` DefineFont path was signed. This change makes the two
halves of the recompiler agree.

---

## 2. What changed (5 files, +39/−26)

### Recompiler — `SWFRecomp/`

* `include/swf.hpp:251` — `font_advance_tables` value type
  `std::vector<s16>` → `std::vector<s32>`, with a comment recording the wire
  type and why `s32` (not `u16`): the runtime lookups use **−1 as the
  "no such glyph" sentinel**, so the storage type must keep −1 out of band.
* `src/swf.cpp:2337-2352` — the DefineFont2/3 FontAdvanceTable loop:
  `SWF_FIELD_SI16` → `SWF_FIELD_UI16`, store cast `(s16)` → `(s32)`, comment
  rewritten (the SWF spec says SI16; Flash and Ruffle both read it unsigned).
* `src/swf.cpp:2389` — device-font-synth `push_back` cast `(s16)` → `(s32)`
  (type agreement only; stb advances are small).
* `src/swf.cpp:2647` — emitted array type `static const s16 font_N_advances[]`
  → `static const s32 ...`.

`src/swf.cpp:3169-3171` (static-DefineText per-glyph advance accumulation)
already cast to `s32` and needed no edit.

### Runtime — `SWFModernRuntime/`

* `include/libswf/tag.h:196,506` — `tagDefineFontMetrics` /
  `ng_record_font_metrics` param `const s16* advance_table` → `const s32*`.
  **This is the generated-ABI touchpoint**: generated `tagMain.c` passes the
  `font_N_advances` array straight into this prototype.
* `include/libswf/tag.h:513` + `src/libswf/ng_shared.c:507` —
  `ng_font_glyph_advance_by_idx` return `s16` → `s32`.
* `src/libswf/ng_shared.c:378` — `NgFont::advance_table[MAX_FONT_GLYPHS]`
  `s16` → `s32` (with the sentinel comment).
* `src/libswf/ng_shared.c:394,408,461,538` — `builtin_noto_sans_advances`,
  `builtin_font_glyph_advance`, `ng_font_glyph_advance`,
  `ng_record_font_metrics` widened to match.
* `src/libswf/ng_shared.c:1161,1310,1404,1588,1763,2047` — the six
  `s16 adv = ng_font_glyph_advance(...)` locals in the **measurement** paths
  (line widths, wrapping, getTextExtent/autoSize) → `s32`. §6.1 listed only
  the `tag.c` call sites; these matter equally, because a 33000 advance that
  survives to the render path but wraps during measurement would put the box
  bounds and the glyph positions on different arithmetic. Every one of them
  guards on `adv >= 0`, so the sentinel semantics are unchanged.
* `src/libswf/tag.c:4993,5084,5141,5275` — the four
  `s16 adv/a = ng_font_glyph_advance_by_idx(...)` locals in
  `textfield_glyph_render_cb` → `s32`.
* `src/libswf/tag.c:11487` — `tagDefineFontMetrics` definition param.

Nothing else in the tree types a font advance: a repo-wide grep for
`advance_table|_advances\[\]` outside `Recompiled*`/`build` returns only the
files above plus the AVM2 side, which was already `int32_t`.

### Generated-ABI reach (the reason §6.1 was left unshipped)

Two things change shape, and both are **compile-time**, so a stale cache is a
hard error, never silent corruption:

1. `static const s16 font_N_advances[]` → `s32` in every generated
   `RecompiledTags/tagMain.c` that has a DefineFont2/3 with a layout table.
2. `tagDefineFontMetrics` / `ng_record_font_metrics` / the internal
   `ng_font_glyph_*` prototypes.

Consequence: **every cached test dir must be re-recompiled** (`--recompile`),
and the recompiler binary must be rebuilt. Passing an `s16[]` to a
`const s32*` parameter is a C constraint violation — gcc emits an
incompatible-pointer-type diagnostic — so a half-updated cache fails the
compile step loudly rather than reading the table at the wrong stride. CI does
both from a clean checkout automatically; **local agents holding warm
`Recompiled*` caches must pass `--recompile` on first use after this lands.**

Value fidelity: every advance below 32768 is bit-identical through the widening
(same value, wider container), so the ONLY font in the entire corpus whose
generated numbers change is `advance_u16`'s font 1. Verified empirically —
see §3.

---

## 3. Verification (all in this worktree, fresh cmake build of the recompiler)

Recompiler built from scratch here (`cmake -B build -DCMAKE_BUILD_TYPE=Release`
+ `cmake --build build -j4`); no binary copied from the main tree. Test dirs
were `cp -r`'d from the main repo into this worktree's canonical suite paths and
run with `--recompile` on first use, so no cache is shared with sibling agents.

### 3.1 Render canary A/B — `render_canary.py`, 32 tests / 49 comparisons

Both legs captured inside this worktree with `--recompile` (before leg = my
patch reverted + recompiler rebuilt; after leg = patch applied + rebuilt).
List = the full standing `ruffle-tests/render_canary_tests.txt` (all 21
resolvable entries, both tiers, including the text member
`avm1/edittext_tag_indent`) **plus** the 11-test font/text family this change
can physically reach.

```
RENDER CANARY  before=before  after=after   32 tests / 49 comparisons

  IDENTICAL    48
  DIFFERS       1
  APPEARED      0   VANISHED 0   NO_RENDER 0

  DIFFERS:
    visual/fonts/advance_u16  output   [DIFFERS]
        diff_channels 264/160000  mean 0.3443  max 255   bbox (324,2)-(333,20)
        image status: fail -> pass    trace: pass -> pass

  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES:
    visual/fonts/advance_u16  output   fail -> pass        <-- REVIEW
```

Canary members (all IDENTICAL): `avm1/color`, `avm1/bitmap_data_fillrect`,
`avm1/mask_with_drawing`, `avm1/movieclip_setmask`, `avm1/edittext_tag_indent`,
`avm1/focusrect_swf5` (12 cmps), `avm1/bitmapdata_applyfilter_colormatrix`,
`avm2/blend_multiply_alpha`, `visual/simple_shapes/winding_rule`,
`visual/cache_as_bitmap/shape_changed`, `from_shumway/timeline/timeline_as2_5`
(7 cmps), `from_shumway/acid/acid-gradient-0`,
`regression/avm2_timeline_stroke_gradient`, `regression/avm2_timeline_gradients`,
`regression/mask_sibling_union`, `visual/simple_shapes/masks`,
`visual/simple_shapes/gradients/gradients`, `visual/filters/drop_shadow`,
`visual/filters/color_matrix`, `visual/blend_modes/multiply`,
`regression/avm2_morph`, `visual/fonts/leading_define_font`,
`visual/fonts/leading_device_font`, `visual/fonts/leading_embedded_font`,
`visual/fonts/glyph`, `visual/fonts/duplicate_font`, `visual/fonts/device-font`,
`text/auto_size/width`, `text/auto_size/return`,
`avm1/define_font_glyph_table_order`, `avm1/define_font_glyph_table_overlap`.

**48/49 md5-identical is the strong form of the "values < 32768 are
bit-identical" claim**: seven other embedded-font tests (including the two
`define_font_glyph_table_*` tests, which exercise the same DefineFont parse, and
the whole device-font family) rendered byte-for-byte the same PNG through the
widened ABI.

### 3.2 Absolute image verdict on the headline test

```
before (False, '216 outliers exceed limit of 0, max difference 255',
        {diff_channels 264, mean_diff 0.3446, tolerance 128, max_outliers 0})
after  (True,  '0 outliers (limit 0), max difference 1',
        {diff_channels  48, mean_diff 0.0003, tolerance 128, max_outliers 0})
```

The 48 residual diff channels are all `max_diff 1` — sub-LSB antialiasing, well
inside the test's own tolerance of 128 and its `max_outliers = 0` budget.

### 3.3 Trace axis

* All 32 render-canary tests: `trace: pass -> pass`, zero trace status changes
  (graphics mode).
* Pure-trace canary, default (no-graphics) mode, `--recompile`, 11/11 pass:
  `avm1/edittext_leading`, `avm1/edittext_align`, `avm1/edittext_autosize`,
  `avm1/edittext_font_size`, `avm1/edittext_letter_spacing`,
  `avm1/device_font_spacing`, `avm1/edittext_text_height_leading`,
  `avm1/edittext_tag_indent`, `avm1/define_font_glyph_table_order`,
  `avm1/define_font_glyph_table_overlap`, `avm2/edittext_leading`.
* Both build arms compile: the graphics leg builds `swf.c` + `tag.c`, the
  no-graphics leg builds `swf_core.c` + `tag_stubs.c` + `tag.c`. Neither
  stub file references a font advance, so there is no `#ifdef NO_GRAPHICS`
  asymmetry to worry about.

---

## 4. Ledger of expected CI movement

| Axis | Test | HEAD | Expected | Confidence |
|---|---|---|---|---|
| **Image** | `visual/fonts/advance_u16 [output]` | fail (216 outliers) | **pass** | High — absolute local verdict on byte-exact local Dawn |
| Image | everything else in the canary (48 cmps) | — | unchanged | High — md5-identical A/B |
| Trace | all suites | — | **unchanged** | High — inert on the trace axis; 43 trace verdicts held across both modes |

Net expectation: **pixels 286/567 → 287/567 (50.4% → 50.6%)**, trace corpus
unchanged at 4229-eff. No `results.json` / `image_results_graphics.json`
baseline is invalidated beyond that one row.

Not attempted (still open, still pinned): `avm1/define_font_glyph_table_order`
— §6.2 of the source report. Its live suspect is
`entry_offsets.push_back((u16) tag.fields[i].value)` truncating a UI32 wide
offset at `swf.cpp:2246`. Untouched here; that test rendered md5-identical
before/after, so this change neither helps nor hurts it.

---

## 5. Risks for the serial merge

1. **Cache invalidation is the only real risk, and it is loud.** Any agent or
   local checkout holding warm `Recompiled*` dirs must pass `--recompile` after
   this merges; without it gcc fails with an incompatible-pointer-type error on
   `font_N_advances` at the `tagDefineFontMetrics` call. This is a *compile*
   failure, not a wrong-pixels failure — it cannot be mistaken for a
   regression, but it *can* be mistaken for the known "long-compile timeout
   under load" false failure. If a font-bearing test suddenly fails to compile
   after merge, re-run it with `--recompile` before believing it.
   CI is unaffected (clean checkout, always recompiles).

2. **Sibling textual conflicts: none expected.** My files are
   `SWFRecomp/include/swf.hpp`, `SWFRecomp/src/swf.cpp`,
   `SWFModernRuntime/include/libswf/tag.h`,
   `SWFModernRuntime/src/libswf/ng_shared.c`, `SWFModernRuntime/src/libswf/tag.c`.
   * No `render_webgpu.c` change → clear of the sibling doing AVM2 render /
     mask work there, and the s11 `MSAA_SAMPLES` invariant is untouched.
   * My `tag.c` hunks are at 4993 / 5084 / 5141 / 5275 (all inside
     `textfield_glyph_render_cb`) and 11487 (`tagDefineFontMetrics`). The
     announced sibling `tag.c` edits are the AVM2 render path and the
     char-id-0 sentinel — different functions. Note the session-12
     `w2-gfx-autosize` line-advance hunk also lives in
     `textfield_glyph_render_cb` (~5097); it is already in HEAD and my hunks
     sit around it, not on it.
   * No `action.c` change → clear of the ImportAssets agent.
   * No blend-shader change.

3. **`s32` vs `u16` was deliberate.** Storing the value as unsigned would
   collide with the runtime's `-1` "glyph not found" sentinel, which every
   caller tests with `adv >= 0`. `s32` preserves both the full u16 range and
   the sentinel with no call-site logic change. If a future refactor moves to
   an explicit `found` flag, the storage can narrow to `u16` then.

4. **Disposition docs: nothing to add.** `visual/fonts/advance_u16` appears in
   none of `ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`,
   `RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md` or
   `ignored_tests.txt` (re-verified this session). This is a plain parse bug
   fix that moves us *toward* both Flash and Ruffle, not a compat tweak.

5. **Suggested CI:** `mode=graphics`, `categories=all`. The change is a
   recompiler emission change, so `categories=full` is defensible under the
   standing policy; the AVM2 font path is genuinely untouched (it already read
   `u16`), so `all` is sufficient and cheaper. `images=true` is what would
   actually score the flip — otherwise this run is expected to be a pure
   zero-movement trace run.

---

## 6. Housekeeping note for the session lead (not a code issue)

`git stash` state is **shared across all worktrees** — `refs/stash` is a single
repo-wide ref, not per-worktree. I used `git stash push` to build the "before"
leg and a sibling agent pushed a stash in the interval, so my `git stash pop`
applied *their* WIP into my worktree. I restored it immediately and exactly
(`git stash store 7561e54888c109f99bc85b4b35073a5460666820`, putting their entry
back at `stash@{0}` — the identical pre-pop stack position — then reverted their
five files out of my tree and dropped my own entry). Verified: `git stash list`
holds exactly one entry, theirs, and my worktree contains only my five files.
No sibling work was lost. **Standing lesson for parallel worktree sessions: use
`git diff > file.patch` + `git apply -R` / `git apply` for A/B legs, never
`git stash`.**
