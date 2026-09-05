# w2-gfx-avm2-blend — wave 2: the AVM2 render walk had no blend arm

**Deliverables** (worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a70419972978a6649`):
`SWFRecompDocs/plans/session18-fanout-reports/w2-gfx-avm2-blend.patch` + this report.

**NEW FILES: none.** No new `.h`, no new TU, no CMake/Emscripten/`verify_output.py`
source-list change. Two existing files touched:

| file | what |
|---|---|
| `SWFModernRuntime/include/avm2/avm2_globals.h` | ONE trailing field on `Avm2DisplayObjectExt`: `uint8_t blend_mode_id` |
| `SWFModernRuntime/src/avm2/avm2_display.c` | `blend_mode_id_from_name()` (new static), the id cache in `set_blend_mode_name` / `do_blendmode_set` / `do_blendshader_set`, the blend arm + `g_avm2_blend_wrapped` sentinel in `avm2_render_node`, and **one extra line in `gfx_set_solid_fill`** (scope note §3) |

Runtime-only — the main tree's `SWFRecomp/build` was copied, no recompiler rebuild.

---

## 0. Verdict

**GO — the +1 flip landed, exactly as w1-gfx-fill §1 A1 priced it.**

| comparison | baseline (CI run `33857494837`, `659153865`) | blend arm only | blend arm + fill-alpha (final) |
|---|---:|---:|---:|
| `avm2/displayobject_blendmode [output]` | **62 400** outliers, max diff 114 | 12 800, max diff 2 | **0**, max diff 1 (tolerance 1) — **PASS** |

The brief's mechanism claim was correct in full: the AVM2 walk asked the renderer for
no blend at all, `renderer_*_blend` was reachable only from `tag.c`, and no
`Avm2TimelineOp` re-plumb was needed. The recompiler already parses and emits the
PlaceObject3 blend byte (`abc_timeline.cpp:1040`, `TLF_HAS_BLEND`) and
`apply_place_object` already routes it — it just landed in a string nothing read.

Two things the brief did **not** predict are in §3 and §5.

---

## 1. Mechanism and patch shape

`DisplayObject.blendMode` had exactly one consumer: the `__blendMode` dont-enum
dynamic property the AS getter reads back. The numeric id now rides alongside it on
the display ext, written at every set site:

* `set_blend_mode_name()` — the timeline path (`apply_place_object`, and through it
  the goto-rewind default at `goto_effective_place`, which forces `blend_mode = 0`).
* `do_blendmode_set()` — the AS setter, keyed off the entry it already matched in
  the `known[]` validation table, so the string and the id cannot disagree.
* `do_blendshader_set()` — `"shader"` caches id 0. We have no shader-blend backend,
  so a shader blend keeps drawing as NORMAL, which is what it did before.

`blend_mode_id_from_name()` is derived from the existing `blend_mode_name()` table
rather than a second table, so the two can never drift.

The arm itself sits at the TOP of `avm2_render_node`, above the filter arm, and is a
line-for-line mirror of `tag.c:6547-6586`:

* `blend_skip` for ALPHA (11) / ERASE (12) — Flash ignores them with no Layer above,
  and we have no layer groups, so that is unconditional (`surface.rs:239-244`).
* `blend_layered` = not skipped **and** `filter_count == 0` **and**
  `renderer_blend_mode_is_layered()` — filter and blend both want `filter_tex_a`,
  so a filtered node keeps the per-draw pipeline, exactly tag.c's `filter_type == 0`.
* layered → `suspend_pass` / `capture_backdrop` / `begin_offscreen_pass` / render /
  `end_offscreen_pass` / `resume_pass` / `composite_blend`.
* otherwise → `set_blend_mode(bm)` … `set_blend_mode(0)`.

**Wrapping the whole node** (its own content *and* its subtree) is what Flash
requires — the object is composited once, never per draw call. The re-entry is a
single sentinel, `g_avm2_blend_wrapped`: the arm is skipped exactly once, for the
object it is currently wrapping, so a descendant with its own `blendMode` still takes
the arm on its own account. Nesting is already refused one level down —
`render_webgpu_blend_mode_is_layered` returns 0 while `offscreen_depth > 0`, so an
inner blend degrades to the legacy per-draw pipeline instead of clobbering the outer
layer. No new depth counter was needed.

`renderer_composite_blend`'s `stencil_ref` argument is legacy (the function reads
`ctx->mask_ref` itself and `(void)`s the parameter); the arm passes the same boolean
tag.c does.

**Mode reach**: the whole render section of `avm2_display.c` is inside
`#if defined(OFFSCREEN_RENDER) || (defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS))`
(`:16859`), so the arm is graphics-native + browser only; NO_GRAPHICS never compiles
it. The ext field and the three set sites are outside that gate and are pure writes.

---

## 2. Why the arm alone was not the flip: 12 800 channels at exactly ±2

With the arm alone the test went 62 400 → 12 800, max diff 114 → 2. Decoded, the
residual was two colour pairs and nothing else:

```
expected (148, 63, 132)  actual (150, 64, 134)   delta (2,1,2)  x4800   # the (100,100) 80x80 rect, ADD alpha 0.1
expected (224, 63, 132)  actual (226, 64, 134)   delta (2,1,2)  x1600   # the 40x40 ADD-0.3 rect inside it
```

Every other region was already exact-or-+1 (inside the test's tolerance 1), including
all three previously-broken ADD rects. Arithmetic on the survivors:

* backdrop = `beginFill(0xFF55D9, 0.5)` over black. Ruffle: alpha byte
  `(0.5*255) as u8` = **127** → `(255, 85, 217)·127/255` = `(127.0, 42.3, 108.1)` =
  the golden `(127, 42, 108)`. Ours kept the float 0.5 → `(128.0, 42.7, 109.0)` =
  `(128, 43, 109)`, +1 in all three (and inside tolerance, which is why nobody had
  seen it).
* the 0.1-alpha rect = `0xD5D5F7` = `(213,213,247)`. Ruffle: alpha byte
  `(0.1*255) as u8` = **25** → adds `(20.9, 20.9, 24.2)` → `+21/+21/+24`. Ours with a
  float 0.1 added `+22/+21/+25`. Stacked on the +1 backdrop that is +2 in R and B —
  over tolerance.

So the leftover was **never the blend**; it was that a `swf::Color` alpha is a BYTE
and Ruffle's `avm2/globals/flash/display/graphics.rs::color_from_args` makes it one by
**truncating** (`(alpha * 255.0) as u8`), while `gfx_set_solid_fill` stored the raw
float. Quantising the same way turns every one of these rows exact.

---

## 3. Scope note — one line outside the brief's stated file region

The brief scoped me to "`avm2_display.c` render walk ONLY". The fill-alpha
quantisation is one line in `gfx_set_solid_fill` (`avm2_display.c`, gfx region):

```c
	g->cfa = (float) ((double) (uint8_t) (a * 255.0) / 255.0);   // was: (float) a
```

It is a **separable hunk** — drop it and you keep the blend arm and the 62 400 → 12 800
band move; keep it and you get the flip. Coordinator's call. Notes for the merge:

* It touches `gfx_set_solid_fill` only, which is `beginFill` + `GraphicsSolidFill`
  (Ruffle `graphics.rs:49` and `:1686`). **`lineStyle` was deliberately left alone**
  even though Ruffle truncates there too (`graphics.rs:378`) — that is stroke
  territory and `w2-gfx-strokes` is editing `gfx_build_stroke`/`gfx_stroke_join` in
  the same file. Filing it as an unclaimed lead instead (§7).
* `w2-gfx-fill-smalls` also edits the gfx region of `avm2_display.c`, but its target
  is `drawPath`'s NaN handling — a different function, no textual overlap.
* Blast radius is genuinely narrow: `(uint8_t)(1.0*255)` is 255, so every
  `beginFill(c)` / `beginFill(c, 1)` is bit-identical. Only AVM2 fills with a
  FRACTIONAL alpha whose `×255` is not an integer move, and they move by at most one
  8-bit step, toward Ruffle.
* It is **not** graphics-only: `avm2_cpu_raster` reads the same fill in NO_GRAPHICS,
  so `BitmapData.draw` of a fractional-alpha AVM2 shape shifts by ≤1 there too — in
  the correct direction, but it is a trace-visible surface. Worth a no-graphics CI leg
  if this hunk is taken.

---

## 4. Canary ledger

Local Dawn is byte-deterministic, so the bar is **md5 identity** on the rendered PNG.
Two `render_canary.py` A/B pairs were captured in this worktree (`B`/`B2` = HEAD with
the patch reverted via `git apply -R`, `A`/`A2` = patched; `--jobs 2`,
`--timeout 5400`, `--recompile` on first use of each copied dir):

```
compare B  -> A    14 tests / 24 comparisons    IDENTICAL 24   DIFFERS 0
compare B2 -> A2   20 tests / 18 comparisons    IDENTICAL 17   DIFFERS 1
                                        TOTAL:  IDENTICAL 41   DIFFERS 1
   APPEARED 0   VANISHED 0   NO_RENDER 0   trace-status changes: NONE
```

**The single DIFFERS is the intended flip and nothing else:**

| test | cmp | verdict | image status | trace |
|---|---|---|---|---|
| `avm2/displayobject_blendmode` | output | **DIFFERS** — 120 000/160 000 diff channels, mean 19.03, max 114, bbox (0,0)-(200,200) | **fail → pass** | pass → pass, byte-identical |

### Pair 1 — standing render canary subset (B → A), 24/24 IDENTICAL

| test | cmps | verdict | image status B→A | trace |
|---|---:|---|---|---|
| `avm1/color` | 1 | IDENTICAL | pass → pass | identical |
| `avm2/blend_multiply_alpha` | 1 | IDENTICAL | pass → pass | identical |
| `avm2/blend_shader_luma_lighten` | 1 | IDENTICAL | fail → fail | identical |
| `from_shumway/acid/acid-blend-2` | 5 | IDENTICAL ×5 | pass → pass | identical |
| `regression/avm2_morph` | 1 | IDENTICAL | skip → skip | identical |
| `regression/avm2_timeline_gradients` | 1 | IDENTICAL | pass → pass | identical |
| `regression/avm2_timeline_stroke_gradient` | 1 | IDENTICAL | pass → pass | identical |
| `regression/mask_nested_intersect` | 1 | IDENTICAL | pass → pass | identical |
| `regression/mask_sibling_union` | 1 | IDENTICAL | pass → pass | identical |
| `visual/blend_modes/masked_layer_cached_children` | 1 | IDENTICAL | pass → pass | identical |
| `visual/blend_modes/multiply` | 1 | IDENTICAL | fail → fail | identical |
| `visual/blend_modes/shader_without_shader` | 1 | IDENTICAL | pass → pass | identical |
| `visual/cache_as_bitmap/masks` | 7 | IDENTICAL ×7 | pass → pass ×7 | identical |
| `visual/filters/glow_pass_scaling` | 1 | IDENTICAL | pass → pass | identical |

### Pair 2 — the rest of the blend family (B2 → A2), 17/18 IDENTICAL

`avm2/displayobject_blendmode` is the DIFFERS above. Everything else:

| test | verdict | image status B2→A2 |
|---|---|---|
| `avm2/blend_scroll` | IDENTICAL | pass → pass |
| `avm2/blend_transform` | IDENTICAL | pass → pass (trace `ruffle_matched` → `ruffle_matched`, unchanged) |
| `avm2/blend_mode_null` | no render (trace-only test) | trace pass → pass |
| `avm2/bitmapdata_copypixels_blend_over` | no render (trace-only test) | trace pass → pass |
| `visual/blend_modes/add` | IDENTICAL | fail → fail |
| `visual/blend_modes/alpha_no_layer` | IDENTICAL | fail → fail |
| `visual/blend_modes/darken` | IDENTICAL | fail → fail |
| `visual/blend_modes/difference` | IDENTICAL | fail → fail |
| `visual/blend_modes/erase_no_layer` | IDENTICAL | fail → fail |
| `visual/blend_modes/hardlight` | IDENTICAL | fail → fail |
| `visual/blend_modes/invert` | IDENTICAL | fail → fail |
| `visual/blend_modes/layer_alpha` | IDENTICAL | fail → fail |
| `visual/blend_modes/layer_erase` | IDENTICAL | fail → fail |
| `visual/blend_modes/lighten` | IDENTICAL | fail → fail |
| `visual/blend_modes/overlay` | IDENTICAL | fail → fail |
| `visual/blend_modes/overlay_onto_stage` | IDENTICAL | pass → pass |
| `visual/blend_modes/screen` | IDENTICAL | fail → fail |
| `visual/blend_modes/shader_as_mask` | IDENTICAL | fail → fail (`known_failure`, untouched) |
| `visual/blend_modes/subtract` | IDENTICAL | fail → fail |

**All 15 AVM1 `visual/blend_modes/*` rows are byte-identical**, which is the brief's
requirement — and expected by construction: 15 of the 18 are AVM1 (checked with
`swf_is_avm2.py`; only `masked_layer_cached_children`, `shader_as_mask` and
`shader_without_shader` are AVM2), and the AVM1 blend route is `tag.c`, untouched.
Their 8–27-outlier residuals are the shared 45° tie rows `w2-gfx-blend-tie` owns; this
patch neither helps nor hurts them.

`avm2/stage3d_blend` was deliberately excluded from the pair: it is a Stage3D-backend
`blank_render` row (1 019 956 outliers at baseline), driven by neither mechanism here.

### Trace canaries

**NO_GRAPHICS** (the mode where the render arm does not exist, but
`gfx_set_solid_fill` still feeds `avm2_cpu_raster`) — patched build, 13/13 PASS:

```
bitmapdata_draw_masks  displayobject_alpha    displayobject_blendmode
displayobject_filters  displayobject_getbounds_shape  displayobject_hittestpoint
displayobject_mask     displayobject_opaque_background  displayobject_rotation
displayobject_scrollrect  displayobject_transform  displayobject_visible
graphics_simple_shapes
```

**Regression suite, `--mode=graphics`, patched build: 89/89 PASS**
(`--tests-dir=ruffle-tests/tests/swfs/regression`, the whole tracked suite, not a
sample). The runner's own `[diff] vs prev` against the suite's checked-in results
reports **no changes** on every test, so no regression test flipped in either
direction and none needed its README read.

### Target, measured three ways

| build | image comparison verdict |
|---|---|
| baseline (CI run `33857494837`, `659153865`) | 62 400 outliers, max diff 114 — FAIL |
| blend arm only | 12 800 outliers, max diff 2 — FAIL |
| blend arm + fill-alpha quantisation | **0 outliers, max diff 1 (tolerance 1) — PASS** |

The last row was reproduced twice: standalone
(`verify_output.py --mode=graphics --images`, `res-after2-target.json`) and inside the
canary pair (`image status fail → pass`).

---

## 5. Refutations

1. **"The tag side works — `avm2/blend_multiply_alpha`, `blend_scroll`,
   `blend_transform` all pass … those carry the blend on the PlaceObject3 tag, which
   reaches `Avm2TimelineOp.blend_mode` → the display entry"** (w1-gfx-fill §1 A1).
   **Refuted.** None of those three places anything with a PlaceObject3 blend byte —
   all three are `BitmapData.draw(source, …, blendMode)`, i.e. the CPU compositor in
   `avm2_bitmap.c`, and their `Test.as` says so verbatim:
   * `blend_multiply_alpha`: `background.draw(data, null, null, "multiply")`
   * `blend_transform`: `data.draw(secondData, null, null, BlendMode.DIFFERENCE)` /
     `BlendMode.SUBTRACT`
   * `blend_scroll`: `data.draw(circle)` + `data.scroll(...)` — no blend argument at all.

   They pass because they never exercise the display-list blend, not because the
   timeline route works. The conclusion the report drew from them (that the tag path
   already reaches the renderer) is unsupported by those rows. It happens to be true
   for **AVM1** (`tag.c` really does have the arm and `visual/blend_modes/*` is 15/18
   AVM1), but there was **no** passing AVM2 witness for the timeline blend route
   anywhere in the evidence. The patch fixes both routes regardless, because
   `apply_place_object` and the AS setter now share one cache.

2. **"62 400 → 0" is right, but the report's tolerance argument was incomplete.**
   §1 A1 says the 14 400 +1-background channels are "already free" at tolerance 1 —
   true, but it is the *interaction* of that +1 with the ADD that produced the ±2
   residual. Fixing only what the report called the mechanism leaves the row failing.
   The full flip needed the fill-alpha quantisation as well (§2–3). A wave-1 pixel
   arithmetic check that stops at "these are inside tolerance today" cannot see that.

3. **`avm2/blend_shader_luma_lighten` — confirmed NOT this arm**, as the brief asked.
   It was captured on BOTH legs of canary pair 1 and came back
   **IDENTICAL** (md5-equal PNG), image status `fail -> fail`, trace `pass -> pass`.
   Nothing about it moved, which is what the brief asked me to establish. Its 1 237
   outliers are therefore NOT a missing blend arm; the w1-gfx-fill §4.6 diagnosis
   (a factor-4 green scale, `expected G ~ 2R` vs `ours G ~ R/2`) stands unchallenged
   and stays with whoever owns the shader arm.

4. **No `Avm2TimelineOp` re-plumb was needed** (brief's own hedge, "if the AVM2
   timeline placement carries one — check `abc_timeline.cpp`"). It does:
   `abc_timeline.cpp:1040` reads the blend byte under `has_blend` and sets
   `TLF_HAS_BLEND`; `apply_place_object` (`avm2_display.c:1844`) already consumed it.
   Zero recompiler changes.

5. **Layer groups stay a HOLD**, as instructed. `blend_skip` reproduces `tag.c`'s
   "ALPHA/ERASE with no Layer above is ignored" unconditionally, so
   `visual/blend_modes/layer_alpha` / `layer_erase` (66 762 / 66 967) are untouched by
   design — `render_webgpu.c:4394` still says we have no layer groups. Note the AVM1
   `alpha_no_layer` / `erase_no_layer` rows are already near-passing (21 outliers), so
   the drop-the-draw rule itself is right; only the grouped case is missing.

---

## 6. Exact patch scope

```
SWFModernRuntime/include/avm2/avm2_globals.h
  Avm2DisplayObjectExt: + uint8_t blend_mode_id           (trailing field, +8 lines)

SWFModernRuntime/src/avm2/avm2_display.c
  + static uint8_t blend_mode_id_from_name(const char*)   (near blend_mode_name)
  ~ set_blend_mode_name()      + 2 lines (cache the id)
  ~ do_blendmode_set()         + 5 lines (record the matched index, cache the id)
  ~ do_blendshader_set()       + 3 lines (shader -> id 0)
  + static Avm2Object* g_avm2_blend_wrapped                (next to g_avm2_alpha_masker)
  ~ avm2_render_node()         + ~55 lines: the blend arm, above the filter arm
  ~ gfx_set_solid_fill()       + 1 line   (fill-alpha byte quantisation; SEPARABLE, §3)
```

No `renderer`/`render_webgpu.c` change; no `MSAA_SAMPLES` question arises.

---

## 7. New unclaimed leads

1. **`lineStyle` alpha is not byte-quantised either.** Ruffle truncates in
   `color_from_args` for strokes too (`graphics.rs:378`); our stroke path keeps the
   float, same as `gfx_set_solid_fill` did. Same one-line shape. Left for
   `w2-gfx-strokes`, who owns that region this session.
2. **AVM1's drawing API has the twin question.** `avm1/…` `beginFill(rgb, alpha)`
   goes through `action.c`'s drawing code; whether Ruffle's AVM1 path quantises the
   same way was not checked here (Ruffle's AVM1 `Graphics` lives in
   `avm1/globals/movie_clip.rs`, a different conversion site).
3. **A shader-blend backend would now have a home.** `do_blendshader_set` caches id 0
   because there is nothing to call; the arm is where a `blendShader` composite would
   plug in, next to `blend_mode_is_complex`.
4. **Nested layered blends still degrade.** `render_webgpu_blend_mode_is_layered`
   refuses while `offscreen_depth > 0`, so a blended object inside a blended (or
   filtered) parent uses the per-draw pipeline — self-overlap inside such a subtree
   will blend with itself. A texture pool for `filter_tex_a` would close it; no corpus
   row is known to need it yet.
5. **`visual/blend_modes/{layer_alpha,layer_erase}`** (66 762 / 66 967) remain the
   largest blend-family rows and are a layer-group arc, unchanged by this slice.
