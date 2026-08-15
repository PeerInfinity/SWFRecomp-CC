# w2-gfx-shapes-morph — mask-stroke stencil, morph colour truncation, morph end-colour base, three dispositions

Session 16, wave 2. Agent `w2-gfx-shapes-morph`.
Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ace18009389126e2d`.
Baseline `cd04f80b9`. Brief of record: `wave1-gfx-shapes-morph.md`.
**No commits, no pushes.** All edits are in the worktree; the four patches below
are generated against pristine `HEAD` and verified to apply independently.

---

## 0. Verdicts

| item | verdict | measured move | patch |
|---|---|---|---|
| **A — mask stencil omits strokes for timeline-character maskers** | **GO, landed, mechanism CONFIRMED** | `visual/simple_shapes/masks [output]` **1738 → 359** and `visual/simple_shapes/masks_equal_clipdepth [output]` **1738 → 359** (−79.3 %, mean 0.4927 → 0.0940). No flip alone (tol 0); flip candidate with flattening leg C. Two unpredicted BAND MOVES, both improvements: `from_shumway/acid/acid` 17 of its 18 comparisons drop a few channels (all still pass), `from_shumway/acid/acid-clip` max diff 144 → 128, mean 0.1339 → 0.1321 (0 outliers before and after at tol 150). **Zero regressions across 16 graded tests / 36 comparisons.** | `w2-gfx-mask-stroke.patch` |
| **C1 — AVM1 morph colour lerp must TRUNCATE** | **GO, landed, +1 FLIP as predicted** | `visual/cache_as_bitmap/morph [output]` **2832 → 0 outliers, fail → PASS**. The wave-1 falsifiable prediction ("the fill must read exactly (84,0,170,255) and the comparison must report 0 outliers") held exactly. | `w2-gfx-morph-trunc.patch` |
| **B — morph end-colour per-character offset** | **GO as hygiene; the "zero comparisons move" prediction is CONFIRMED empirically** | Emitter now writes the correct per-character base (`acid-morph`: char 1 → 0, char 4 → **1**, char 5 → **2**; all three previously read index 0). Renders and traces are **byte-identical** before/after on `acid-morph`, `cache_as_bitmap/morph`, `invalidClipDepth`, `morphShape`, `avm2_morph`, `masks`, and on the AVM1 trace test `avm1/movieclip_hittest_shapeflag` (trace md5 identical, 332/338 lines both sides). 0 comparisons, 0 trace lines. | `w2-gfx-morph-endcolor.patch` |
| **Docs — three dispositions** | **done** | `bitmapdata_applyfilter_blur` device-font entry added; masks entry amended and NARROWED with measured post-fix numbers; `blur_quality` NO-GO recorded with its completion mechanism; `cache_as_bitmap/morph` recorded as an explicit "never disposition this" row. | `w2-gfx-shapes-docs.patch` |

**Headline: +1 comparison (`visual/cache_as_bitmap/morph`), −79 % on two more
(`masks`, `masks_equal_clipdepth`), zero regressions.**

---

## 1. NEW FILES

**None.** All four patches modify existing tracked files only. Full file list
(8 files, `git apply --stat` on the four patches together):

```
SWFModernRuntime/src/rendering/render_webgpu.c            (item A)
SWFModernRuntime/src/libswf/tag.c                         (items C1 + B)
SWFModernRuntime/include/libswf/tag.h                     (item B)
SWFModernRuntime/include/libswf/swf.h                     (item B)
SWFRecomp/src/swf.cpp                                     (item B)
docs/recompiler/runtime_headers/include_libswf_tag.h      (item B, see §5)
SWFRecompDocs/plans/graphics-fanout-playbook.md           (docs)
ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md  (docs)
```

## 2. Patches — independent by construction, verified

Deliverables are in `SWFRecompDocs/plans/session16-fanout-reports/`:

| patch | files | lines |
|---|---|---|
| `w2-gfx-mask-stroke.patch` | render_webgpu.c | +33 |
| `w2-gfx-morph-trunc.patch` | tag.c | +18 −2 |
| `w2-gfx-morph-endcolor.patch` | tag.c, tag.h, swf.h, swf.cpp, deployed header | +11 −2 |
| `w2-gfx-shapes-docs.patch` | playbook, ACCEPTED_DIFFS | +132 −1 |

The two morph patches touch lines **two apart inside the same two loops**, so
they are emitted with **one line of context (`-U1`)**: with `-U1` their hunks
are disjoint and `git apply` takes them in either order, alone or together.
Verified mechanically (`verify_patches.sh` / `verify_solo.sh`):

```
solo OK   w2-gfx-mask-stroke.patch        order 1: A, trunc, endcolor, docs -> identical to working tree
solo OK   w2-gfx-morph-trunc.patch        order 2: docs, endcolor, trunc, A -> identical to working tree
solo OK   w2-gfx-morph-endcolor.patch
solo OK   w2-gfx-shapes-docs.patch
```

i.e. each applies alone to pristine `HEAD`, and applying all four in any order
reproduces this worktree byte-for-byte.

**Sibling overlap check** (scanned every `w2-*.patch` in the reports dir): the
only other s16 patch that touches any file of mine is
`w2-gfx-filters-sprite.patch`, one hunk in `tag.c` at `render_single_object`
(~line 3462) — ~250 lines away from my nearest edit and in a different
function, so no textual conflict. My `tag.c` helper insertion at ~line 2912
shifts later line numbers by +16, which `git apply` absorbs by context search;
if it ever complains, apply mine first or use `git apply -3`. Nothing else
touches `render_webgpu.c`, `tag.h`, `swf.h`, `swf.cpp`,
`ACCEPTED_DIFFS.md` or `graphics-fanout-playbook.md`.

---

## 3. Item A — mask stencil omits strokes

### 3.1 The change

One new `static` helper `mask_stencil_vert_count()` immediately above
`render_webgpu_draw_shape`, called as that function's first statement
(self-localized per the ownership note; no other symbol in `render_webgpu.c` is
touched, so it cannot collide with the filters-offscreen arc).

Rule (ruffle `render/src/tessellator.rs:149-160` +
`render/wgpu/src/surface/commands.rs:281-288`): while a mask stencil is being
captured (`ctx->mask_capture_depth > 0`), a **static** character's vertex range
is truncated to its **leading run of non-stroke vertices**; a **stroke-only**
range keeps all of its vertices (ruffle's `unwrap_or(len)`); **dynamic**
(drawing-API) ranges — which live past `shape_data_size` — are left alone,
because `tag.c`'s `render_drawing_mc_paths_fill_only` already applies the same
rule there.

Stroke detection: SWFRecomp emits every fill group of a character before every
stroke run, and stroke vertices are the only ones whose style word (word 2 of
the 4-word vertex) sets bit 31 (`SWFRecomp/src/swf.cpp:10313`, `0x80000000`).
I verified the fills-then-strokes ordering directly in `swf.cpp` (the fill-group
loop precedes the `paths[i].line_style` loop) and empirically by decoding
`draws.c` for every masker in the corpus subset (§3.3).

Placement rationale: `mask_capture_depth` is > 0 between
`render_webgpu_begin_clip_mask` and `..._end_clip_mask` for **every** masking
route (clipDepth, sprite maskers, AVM1 `setMask`, EditText / scrollRect
nesting), so one site covers all 12 `renderer_draw_shape` call sites. The
stencil **pop** is a full-screen `Equal`/`DecrementClamp` quad
(`pop_mask_level`), not a geometry replay, so there is no "clear stencil" arm
that could go out of sync with the trimmed draw. No new pipeline is created, so
the `MSAA_SAMPLES` invariant is untouched.

Backend scope: the change is in the `USE_WEBGPU` backend, which serves both the
native `--mode=graphics` build and browser WASM. The legacy flashbang (SDL3)
backend compiles clip masks out entirely (`renderer_begin_clip_mask` →
`((void)0)`, `renderer.h:80+`), so it is unaffected by construction.

Not covered (unchanged follow-up from wave 1): the AVM2 display walk draws
shapes through `renderer_draw_tris` runs, not `renderer_draw_shape`. If an AVM2
masker ever carries stroke runs it needs the same skip in `avm2_display.c`.

### 3.2 Result on the headline pair

| comparison | before | after | Δ |
|---|---:|---:|---|
| `visual/simple_shapes/masks [output]` (tol 0) | 1738 outliers, 652 px, mean 0.4927 | **359 outliers, 188 px, mean 0.0940** | **−79.3 %** |
| `visual/simple_shapes/masks_equal_clipdepth [output]` (tol 0) | 1738 | **359** | **−79.3 %** |

The two twins render **byte-identically to each other** in both legs
(`fb9f2362` before, `faf381c2` after) — the wave-1 observation reproduced.

The residual is the interior curve family, exactly as priced. Post-fix
transition census (`after` vs golden):

```
44 px  expected (0,153,255) -> ours (0,0,0)      28 px  the reverse
27 px  expected (255,0,0)   -> ours (0,0,0)      26 px  the reverse
24 px  expected WHITE       -> ours BLACK        (was 482 px before the fix)
```

The one-sided "expected WHITE → ours BLACK" class — the half-pixel **dilation**
— collapsed from 482 px to 24 px; what is left is *balanced* saturated-palette
swaps in both directions, never more than 4 px in any one row: the 1-sample
tessellation-tie signature. Wave 1 priced the residual at ~264 channels; the
measured value is **359**, and the docs entry is re-scoped to 359, not 264.

### 3.3 Census — the "only one family has a stroke-bearing masker" claim, verified

Re-derived independently from the generated `tagMain.c` + `draws.c` of every
mask-bearing test in my set (note `tagPlaceObject2`'s signature is
`(depth, char_id, xid, cxid, clip_depth, …)` — the char id is the **second**
numeric argument; reading the first gives a wrong masker set):

| test | maskers (char ids) | strokes in masker? |
|---|---|---|
| `visual/simple_shapes/masks` (+ `_equal_clipdepth`) | 1, 3, 5 | **char1: 474 fill / 3549 stroke — TRIMMED**; char3 2289/0; char5 2997/0 |
| `from_shumway/acid/acid-clip` | 2, 5, 8, 13, 15, sprite 7 | shapes all stroke-free (its stroked char9 is not a masker) |
| `from_shumway/acid/acid` | 22 | 6 verts, 0 strokes |
| `from_shumway/3_joystick` | 11 | 6 verts, 0 strokes |
| `regression/mask_sibling_union` | 1, 3 | 0 strokes |
| `regression/mask_nested_intersect` | 1, 2 | 0 strokes |
| `from_shumway/clipping`, `acid-clip-3`, `avm1/mask_reapply`, `avm2/mask_reapply`, `avm1/mask_with_drawing` | sprite maskers | no stroke-bearing shape anywhere in those SWFs |
| `avm1/movieclip_setmask`, `visual/cache_as_bitmap/*`, `scroll_rect_mask`, `text_field_mask`, `invalidClipDepth`, `morphShape`, `winding_rule` | no clipDepth maskers | n/a |

**Confirmed: exactly one family carries a stroke-bearing timeline-character
masker.** The two band moves in §3.4 come from sprite-masker subtrees, which the
static census over root placements cannot see — that is why they were measured.

### 3.4 Full A/B ledger (16 tests, 36 comparisons, md5 bar)

`before…before8` vs `after` (render_canary capture/compare, local Dawn, md5):

| test | md5 | outliers before → after | verdict |
|---|---|---|---|
| `visual/simple_shapes/masks` | CHANGED | 1738 → **359** | **improved** |
| `visual/simple_shapes/masks_equal_clipdepth` | CHANGED | 1738 → **359** | **improved** |
| `visual/cache_as_bitmap/morph` | CHANGED | 2832 → **0**, fail → **PASS** | **FLIP (C1)** |
| `from_shumway/acid/acid` (18 cmps) | CHANGED | 17 of 18 down a few channels (e.g. 8669 → 8659, 12005 → 11989); output.16 unchanged at 12347; max diff 204 unchanged; mean down on every one | **band move, improvement, all still pass** |
| `from_shumway/acid/acid-clip` | CHANGED | 0 → 0 outliers (tol 150); diff channels 7004 → 7013, **max 144 → 128**, mean 0.1339 → 0.1321 | **neutral/improved, still passes** |
| `avm1/mask_with_drawing` | identical | 0 → 0 | drawing-API mask route unchanged ✔ |
| `avm1/movieclip_setmask` | identical | 0 → 0 | `setMask` route unchanged ✔ |
| `avm1/mask_reapply`, `avm2/mask_reapply` | identical | 0 → 0 | ✔ |
| `regression/mask_sibling_union` | identical | 0 → 0 (tol 0, repo golden) | ✔ |
| `regression/mask_nested_intersect` | identical | 0 → 0 (tol 0, repo golden) | Equal/IncrementClamp nesting pinned ✔ |
| `from_shumway/clipping` | identical | 0 → 0 | ✔ |
| `from_shumway/invalidClipDepth` | identical | 0 → 0 (tol 0) | ✔ |
| `from_shumway/3_joystick` | identical | 7482 → 7482 | ✔ |
| `visual/cache_as_bitmap/cab_mask_alpha` | identical | 4644 → 4644 | ✔ |
| `visual/simple_shapes/winding_rule` | identical | 0 → 0 | tessellation control ✔ |
| `avm1/color` | identical | 0 → 0 | solid-fill control ✔ |
| `regression/avm2_morph` | identical | skip (no golden) | ✔ |
| `from_shumway/acid/acid-morph` | identical | 4308 → 4308 | ✔ |
| `from_shumway/timeline/nav/morphShape` | identical (trace) | pass → pass | ✔ |

**Zero pass → fail. Zero band worsenings.** Trace status is unchanged on every
one of the 19 tests (render_canary carries the trace axis for free).

---

## 4. Item C1 — AVM1 morph colour truncation

New `static inline float morph_lerp_color_u8(start, end, t)` above
`compose_children`; both AVM1 morph colour loops (`compose_children`'s
`CHAR_TYPE_MORPH_SHAPE` arm and `tagShowFrame`'s) call it instead of
`sc[k] + t * (ec[k] - sc[k])`.

Ruffle's `lerp_color` is an integer lerp with **truncation on the u8 scale**.
Our AVM2 twins already implement it (`avm2_display.c` `avm2_render_morph`,
`avm2_cpu_raster.c`); only the AVM1 path lerped in normalised float and let the
unorm8 write round to nearest, which is one unit **high** whenever the exact
product lands just above an integer — ratio 43691 on RED→BLUE gives
`a*255 = 84.9975`, ruffle 84, round-to-nearest 85.

**Result: `visual/cache_as_bitmap/morph` 2832 outliers (all red channel, max 1)
→ 0 outliers, `fail → pass`. +1 comparison.**
Morph tripwires all byte-identical: `from_shumway/invalidClipDepth` (tol 0,
passing), `from_shumway/timeline/nav/morphShape`, `regression/avm2_morph`,
`from_shumway/acid/acid-morph` (4308, unchanged — it is the AVM2 path, which
already truncated).

This closes the disposition s14 and s15 recommended twice; the docs patch
records why it must never be dispositioned instead.

---

## 5. Item B — per-character morph end-colour base

`Character` gains `morph_end_color_start`; `tagDefineMorphShape` gains one
parameter (it has exactly one emitter and no hand-written callers); the
recompiler emits `morph_end_color_before`, which it already computes one line
above for `morph_color_count`; both AVM1 read sites index
`morph_end_color_data + (ch->morph_end_color_start + c) * 4`.

Verified by construction on a fresh recompile (recompiler rebuilt in-worktree
with cmake in `SWFRecomp/build2`, binary installed to `SWFRecomp/build/`, all
runs with `--recompile`):

```
before:  tagDefineMorphShape(app_context, 1, 0,   276, 0, 0, 1,     …)
         tagDefineMorphShape(app_context, 4, 546,  36, 276, 1, 1,   …)   <- read end colour [0]
         tagDefineMorphShape(app_context, 5, 582,  18, 312, 2, 1,   …)   <- read end colour [0]
after:   tagDefineMorphShape(app_context, 1, 0,   276, 0, 0, 1, 0,  …)
         tagDefineMorphShape(app_context, 4, 546,  36, 276, 1, 1, 1, …)  <- now [1]
         tagDefineMorphShape(app_context, 5, 582,  18, 312, 2, 1, 2, …)  <- now [2]
```

**Pixel/trace effect: none, as wave 1 predicted.** `acid-morph` (the only corpus
SWF with ≥ 2 morph characters *and* an image comparison) is AVM2 and its
renderer already used the absolute per-vertex end index — its PNG md5 is
identical before and after (`f20557e7`), 4308 outliers both sides. The only AVM1
SWF with ≥ 2 morph characters, `avm1/movieclip_hittest_shapeflag`, has no
`[image_comparisons]`; its **trace is byte-identical** before and after
(md5 `0f5495f4…`, 332/338 matching lines both legs — the six diffs are the three
documented `ACCEPTED_DIFFS` Category-8 entries). Book this as correctness
hygiene, **not** as a pixel or trace win.

**`deploy_wasm_demo.sh` implication.** `SWFRecomp/scripts/deploy_wasm_demo.sh`
copies `SWFModernRuntime/include/libswf/tag.h` to
`docs/recompiler/runtime_headers/include_libswf_tag.h`, and the in-browser
recompiler demo compiles the emitted `tagMain.c` against **that** copy. I
included the same one-line declaration change in that deployed header **inside
this patch**, because the moment the WASM recompiler is redeployed with the new
emitter it will emit a 16-argument call; a stale 15-argument prototype there
would break the demo's in-browser compile. The header sync is *not* sufficient
on its own — the demo still needs a full `deploy_wasm_demo.sh` redeploy (new
`SWFRecomp` WASM blob) for the emitter change to reach the browser. Until that
redeploy, the deployed header is one parameter *ahead* of the deployed emitter,
which is the safe direction only if nothing recompiles in-browser against it;
**flag this to whoever runs the next docs2/demo redeploy.**

---

## 6. Docs (item 4)

`w2-gfx-shapes-docs.patch` contains:

1. **`ACCEPTED_DIFFS.md` — new entry**
   `### avm2/bitmapdata_applyfilter_blur — residual is the default-font text, not the blur`
   with `<!-- image-axis: avm2/bitmapdata_applyfilter_blur output -->`, placed at
   the end of Category 11 (graphics image comparisons). Carries the fixture's own
   `with_default_font = true` / "TODO Fix this test" note, the s15 unfiltered-cell
   evidence (all 534 residual outliers in `y ∈ [96,104]`), the s16 four-band
   re-measurement, the decision, and a **standing invariant** that the blur half is
   *not* dispositioned (re-triage above ~31 k or outside the glyph bands).
   Not added to `ignored_tests.txt` — the trace side passes and the `image-axis`
   marker is what `image_triage.py` reads (same treatment as the masks entry).
2. **`ACCEPTED_DIFFS.md` — masks amendment**, refuting the majority of the entry
   and **narrowing its scope to the 359 measured interior channels**, with the
   before/after numbers and the transition census from §3.2.
3. **`graphics-fanout-playbook.md` §3 — "Image-axis dispositions of record"**, a
   new table enumerating every `<!-- image-axis: -->` entry (h263, deblocking,
   `netstream_play_flv`, the masks pair, the new blur entry) plus an explicit
   **"Explicitly NOT dispositioned (do not add)"** section holding:
   - **`visual/filters/blur_quality` — NO-GO** with the completion mechanism spelled
     out: max diff **9 vs tolerance 6** on 166 986 channels is not a 1-LSB ceiling,
     and **neither test is `known_failure` upstream** so Ruffle clears it — the fix
     route is to dump an intermediate blur pass from the Ruffle exporter for one
     `quality ≥ 7` tile and fit our per-pass rounding to it (measured, ours is
     `0.9951·v + 1.02` vs the golden's `0.9980·v − 0.5`), or move `bd_apply_filter`
     onto the GPU shader that produced the golden's sampling path. Flip to GO when
     that oracle dump exists.
   - **`visual/cache_as_bitmap/morph` — NO-GO**, now moot (fixed in this leg), with
     the standing requirement that any future disposition request must first explain
     why 84-vs-85 is not the truncation rule the AVM2 twin already implements.
4. A one-line correction to §14's s15 board, which still described `blur_quality`
   as a "band ceiling".

---

## 7. Canary blind spot and covering tests (BRIEFS_COMMON s15 lesson)

The standing `render_canary_tests.txt` does contain `visual/simple_shapes/masks`
(tier 2) and `regression/avm2_morph`, but wave 1 is right that it is **blind to
what these two fixes do**: no canary member other than `masks` has a
stroke-bearing masker, and no canary member is an **AVM1** morph with colours.
So a clean canary here means "nothing else moved", not "the fix works".

I therefore graded the covering tests explicitly, and they are the ones that
carry the result:

- Item A covered by **`visual/simple_shapes/masks`** and
  **`visual/simple_shapes/masks_equal_clipdepth`** (1738 → 359 each), with
  `from_shumway/acid/acid` and `from_shumway/acid/acid-clip` as the two
  sprite-masker band moves and 12 further mask tests as md5 tripwires.
- Item C1 covered by **`visual/cache_as_bitmap/morph`** (2832 → 0, the flip),
  with `invalidClipDepth`, `morphShape`, `avm2_morph`, `acid-morph` as tripwires.
- Item B covered by **`avm1/movieclip_hittest_shapeflag`** (trace, byte-identical)
  and by inspecting the regenerated `acid-morph` `tagMain.c` arity.

Canary members run as part of the A/B set: `avm1/color`,
`visual/simple_shapes/winding_rule`, `avm1/mask_with_drawing`,
`avm1/movieclip_setmask`, `regression/mask_sibling_union`,
`regression/mask_nested_intersect`, `regression/avm2_morph`,
`visual/simple_shapes/masks` — **all md5-identical except `masks` itself**.
The remaining canary members (gradients, filters, blend, text, timeline,
bitmap, focusrect, acid-blend-2) were **not** run: the machine was at load
25-42 for most of this leg and each cold test costs a full runtime rebuild.
Justification for the omission: item A is gated on `mask_capture_depth > 0`
and item C1 on `CHAR_TYPE_MORPH_SHAPE`, so a test with neither a mask nor a
morph cannot reach either edit. If the coordinator wants the full canary before
merging, the `before`/`after` labels are still on disk in the worktree's
`.render_canary/` and only the missing members need capturing.

---

## 8. Refutations, corrections and traps (for the s16 closeout)

1. **Wave 1's item-A magnitude was slightly optimistic.** Predicted residual
   ~264 channels; measured **359**. The mechanism is confirmed exactly; only the
   split between "boundary" and "interior" was off by ~95 channels. The docs
   entry now carries the measured number.
2. **Two band moves wave 1's census could not predict** — `from_shumway/acid`
   (18 comparisons) and `from_shumway/acid/acid-clip`. Both have *sprite*
   maskers, and a sprite masker's children are individually drawn during the
   capture, so a stroked shape anywhere in the masker subtree is trimmed even
   though the root placement census sees a stroke-free masker id. Both moved in
   the **improving** direction and neither changed status. **Standing lesson: a
   masker census over root `tagPlaceObject` rows is a lower bound; sprite
   maskers need the subtree.**
3. **`tagPlaceObject2`'s first numeric argument is `depth`, not `char_id`.** My
   first census pass read it as the char id and produced a wrong masker set that
   happened to look plausible. Wave 1's table was right; mine had to be redone.
4. **False `compile_fail`s cost this leg ~40 minutes, in two distinct flavours:**
   (a) `verify_output.py`'s **per-file gcc timeout is 300 s** (`SWFRECOMP_COMPILE_TIMEOUT`)
   and `action.c` exceeds it whenever the shared machine is above load ~25 — five
   tests reported `compile_fail` at exactly 302-304 s; and (b) test dirs `cp -r`'d
   from the main tree while another agent was mid-write carry **partial
   `Recompiled*` caches** whose link fails with `collect2: ld returned 1` (undefined
   `avm2_generated_symbol_class_frames`) — `--recompile` on first use fixes it,
   exactly as BRIEFS_COMMON says. Both are FALSE failures.
5. **Harness trap worth recording:** a long-running **foreground** Bash command in
   this worktree twice took down every *background* task with exit 144 (a
   process-group kill), destroying two partially-complete captures. Detaching with
   `setsid nohup` survives it. Also: `pgrep -f "<pattern>"` in a shell whose own
   command line contains `<pattern>` self-matches and never terminates.
6. **The scratchpad is shared across this session's agents** — another agent
   overwrote my `ledger.py` mid-run. Namespace your scratch files.

## 9. Artefacts (worktree)

- Patches + this report: `SWFRecompDocs/plans/session16-fanout-reports/`.
- Renders and per-test JSON: `.render_canary/{before,before2,before4…before8,after,after2,afterB}/`.
- Scripts: `<scratchpad>/w2shapes/` — `itemA.py`, `itemC1.py`, `itemB.py`,
  `docs.py` (the four edits, re-appliable), `census3.py` (masker/stroke census),
  `led.py` / `detail.py` (ledgers), `patches.sh`, `verify_patches.sh`,
  `verify_solo.sh` (patch generation + independence proof), `cap.sh` /
  `trace_run.sh` (detached, timeout-raised run wrappers).
- Recompiler built in-worktree at `SWFRecomp/build2` (baseline binary was
  byte-identical to the main tree's, confirming the worktree source state).
