# Wave-1 diagnosis — `gfx-text-phase`

Session: two-wave graphics fan-out, 2026-08-01. **Read-only; no source edits, no commits.**

Board regenerated from the merged closeout run:
`origin/ruffle-image-results` @ `d7b5f40e6` (2026-08-01 14:06 UTC) + per-suite
`_results/image_results_graphics.json` @ `feb8882b09e238e91ab6444099d6cca237e3a4f9`
(run `30701749687`) — **390 failing comparisons**, `missing_element` 33/22.
Board JSON/MD: `<scratch>/board.json`, `<scratch>/board.md`.

Local reproductions used `--mode=graphics` with `DAWN_INSTALL=~/CC/dawn-install`.
Both local runs reproduced CI's outlier counts **exactly** (simple_loop_test
242/483/21600/7442/7683/14400/14702; fallback_preferences 121914), so the local
actual PNGs are structurally identical to CI's — no cross-backend grading was
done anywhere in this report.

---

## A. The `missing_element` text slice

### A.0 Membership (21 comparisons / 10 tests)

`image_triage.py --cluster missing_element` gives 33 comparisons; the two Text
families are 18 + 3 = **21**.

| # cmp | test | family | band | missing-ink | trace | notes |
|---|---|---|---|---|---|---|
| 12 | `visual/edittext/edittext_selection_leading` (`output.01`–`.12`) | EditText | e_large | .60–.70 | pass | **T1 + T2** |
| 1 | `visual/edittext/edittext_selection_font_size` | embedded fonts | e_large | .67 | pass | **T1 + T2** |
| 1 | `avm2/edittext_autosize_height_dynamic` | EditText | d_moderate | .41 | pass | **T1 only** (border) |
| 1 | `visual/edittext/edittext_device_transform_basic` | EditText | d_moderate | .76 | **fail** | T1 + T3 |
| 1 | `visual/edittext/edittext_device_transform_negative` | EditText | d_moderate | .66 | **fail** | T1 + T3 |
| 1 | `visual/fonts/font_lookup_as3` | embedded fonts | d_moderate | .95 | pass | T3 + T4 |
| 1 | `fonts/embed_matching/fallback_preferences` | embedded fonts | d_moderate | .81 | pass | **T4 + T5** |
| 1 | `from_shumway/hardwrap` | EditText | c_small | 1.00 | pass | T3, **`known_failure`** |
| 1 | `from_shumway/stylesheet` | EditText | c_small | 1.00 | pass | T3, **`known_failure`** |
| 1 | `from_shumway/flash_text_TextField` | EditText | b_tiny | 1.00 | ruffle_matched | T3, **`known_failure`** |

Every one of these is **AVM2 (AS3)** — the three `from_shumway` entries too
(FileAttributes AS3=1). None is dispositioned; none is on a hard ignore list.

Context beyond the slice: the board carries **86 failing Text-family
comparisons** across 11 clusters, so the mechanisms below have riders in
`content_displaced` (12), `diffuse_mixed` (11), `hairline_edge_drift` (19),
`halo_penumbra` (5), `row_banded` (5), `blank_render` (4).

### A.1 Mechanism T1 — AVM2 TextField **background + border rectangles are never drawn** ★ biggest lever

`avm2_render_text` draws glyphs and nothing else.

- `SWFModernRuntime/src/avm2/avm2_display.c:14303` — `avm2_render_text()`:
  `collect_glyphs` → `avm2_render_glyphs`. No box.
- `SWFModernRuntime/src/avm2/avm2_display.c:14205` — `avm2_render_glyphs()`,
  tessellate + `renderer_draw_tris` per glyph, one world-xform slot per field.
- The state exists and is fully wired: `SWFModernRuntime/src/avm2/avm2_text.c:764`
  (`border`, `background` bits), `:771` (`border_color`, `background_color`),
  `:2291`/`:2317` (seeded from the DefineEditText flags), `:3749`–`:3750`
  (getters/setters), `:8763`–`:8773` (registered on the class). It is simply
  never consumed by a renderer.
- The only `renderer_draw_rect` in the whole AVM2 renderer is the session-9
  focus highlight at `avm2_display.c:14391`–`14394` — which is a perfect
  4-edge-border template.
- The CPU twin `avm2_cpu_raster.c` has no bg/border either (grep: zero hits for
  `background|border|selection|highlight`).

Evidence (`edittext_selection_leading output.01`, `edittext_selection_font_size`,
`edittext_autosize_height_dynamic`): our glyphs land in the right places with the
right colour; what is absent is the cyan `backgroundColor` fill, the black 1px
border, and (T2) the selection box. `edittext_autosize_height_dynamic` is the
cleanest single-mechanism case — glyphs match pixel-for-pixel, only the 11
border rectangles are missing.

**Ruffle oracle** (`~/CC/ruffle/core/src/display_object/edit_text.rs`):
- `:2704`–`:2733` — `render_self` draws the box *before* pushing the glyph mask,
  choosing `draw_device_text_box` vs `draw_text_box` on `is_device_font()`.
- `:2930`–`:2958` — `draw_text_box`: `Matrix::create_box(w,h,x_min,y_min)`
  through the transform stack, then `EditTextPixelSnapping::new(quality)`
  applied, `draw_rect` for background, `draw_line_rect` for border.
- `:2845`–`:2910` — `draw_device_text_box`: bounds rounded with
  `round_to_pixel_ties_even()` first, border drawn as four 1px `draw_line`s
  offset by `Twips::HALF_PX`.

**Fix shape.** In `avm2_render_text` (`avm2_display.c:14303`), before the glyph
call: read the four fields via a new small accessor exported from `avm2_text.c`
(pattern: `avm2_text_self_bounds`, declared `avm2_display.c:682`), allocate the
world-xform slot the same way `avm2_render_glyphs` does, and emit the rects in
**field-local twips through that slot** (not in pre-transformed stage space like
the AVM1 path does — see T6 for why that shortcut is a bug). Reuse
`renderer_draw_rect`.

**Effort** S–M (~150 lines, runtime-only, no recompiler change).
**Predicted flips:** 1 near-certain (`edittext_autosize_height_dynamic`), 13
more gated jointly with T2. Riders plausible in `halo_penumbra` /
`content_displaced` (`edittext_background_basic`, `_scale2`,
`edittext_border_basic`, `_scale2`, `edittext_gutter`, `edittext_tag_indent`) —
check each is AVM2 before counting it.

### A.2 Mechanism T2 — AVM2 selection highlight + inverted selected glyphs

`avm2_edittext_collect_glyphs` (`avm2_text.c:3505`) emits only
`{font, glyph, x_twips, y_twips, scale, color}` with
`color = (fmt->color >> 8) & 0xFFFFFF` (`:3547`) — the selection range is never
consulted. There is no selection-box geometry anywhere in the AVM2 renderer
(grep for `selection` in `avm2_text.c` returns only caret **hit-testing** at
`:9168`/`:9201`/`:9304`).

Expected images show a solid black box over the selected run with the selected
glyphs re-drawn in **white on top**; we render the field's magenta glyphs
uniformly.

**Ruffle oracle:** `edit_text.rs:1119`–`1196` (`render_text` →
`render_selection_background` → `render_selection_background_for_line`, which
clips the box to the line and pushes `draw_rect`), and `:1239`–`:1290` (the
per-character branch that swaps in the inverted colour when
`visible_selection.contains(start + pos)`). `visible_selection()` at `:1059`
governs when it shows at all (focus / `always_show_selection`).

**Effort** M. **Gated:** `edittext_selection_leading` ×12,
`edittext_selection_font_size` ×1, plus riders
`avm2/edittext_always_show_selection` (row_banded),
`visual/cache_as_bitmap/edittext_selection` ×3.
**Ship together with T1** — those 13 comparisons need both.
Watch: `test.toml` for `output.09`/`output.11` already carries
`max_outliers = 36` with the upstream note *"White selected text should always
be rendered on top"*, i.e. Ruffle itself is imperfect there.

### A.3 Mechanism T3 — device-font glyph rendering does not exist ⚠ **DEFER**

`avm2_text.c:2483` defines `noto_device_font` with **metrics only** — code table
+ advances + ascent/descent, and the four glyph-outline pointers left NULL.
`resolve_font` (`:2504`) falls back to it whenever the field is not
`embedFonts` or the name doesn't match. The renderer then drops every such
glyph: `avm2_display.c:14233` `if (fd == NULL || fd->glyph_pts == NULL) continue;`.
This is a documented deferral —
`SWFRecompDocs/plans/avm2-native-text-render-plan.md:18` and `:136`
("device-font (non-embedded, no outlines) fields").

Confirmed blank-in-ours / text-in-Ruffle: `from_shumway/hardwrap` (its
DefineFont2 is a 13-byte glyph-less name declaration), `from_shumway/stylesheet`,
the entire right column of `edittext_device_transform_basic`, the left column +
empty-font-name rows of `font_lookup_as3`, and (AVM1 side, same absence)
`visual/fonts/device-font`, `fonts/device_font_kerning`,
`visual/fonts/leading_device_font` in `blank_render`.

**Why defer:** closing it means shipping real glyph outlines for a fallback face
(Ruffle bundles Noto Sans and rasterizes it). That is a data-blob or
TTF-rasterizer arc, not a sweep item — and even then each comparison needs
glyph-metric parity with Ruffle's font to pass. Three of the slice's members
(`hardwrap`, `stylesheet`, `flash_text_TextField`) additionally carry
`known_failure = true` on the image comparison, so **Ruffle is not the oracle
there** and they are not winnable by matching the expected PNG at all.
Worth noting for the trace axis: `edittext_device_transform_basic` and
`_negative` are also **failing on trace** (`output_mismatch`) — device-font
`getCharBoundaries` / `getLineMetrics` / `textWidth`.

### A.4 Mechanism T4 — embedded-font matching has no bold/italic fallback chain

`avm2_text.c:2504` `resolve_font` requires an **exact** `(name, bold, italic)`
match and otherwise drops straight to the device font:

```c
if (fd->glyph_count > 0 && name_eq_ci(fmt->font, fd->name)
    && (fd->bold != 0) == (fmt->bold != 0)
    && (fd->italic != 0) == (fmt->italic != 0))
```

`fonts/embed_matching/fallback_preferences` is *literally the upstream test for
this algorithm* — `~/CC/ruffle/core/src/library.rs:761` `FontMap::find` opens
with the comment *"The order here is specific, and tested in
`tests/swfs/fonts/embed_matching/fallback_preferences`"*. The order
(`library.rs:761`–`830`) is:

1. exact;
2. if `is_italic ^ is_bold`: bold-italic → regular → the opposite one;
3. else: (if bold-italic) regular; then bold; then italic; then (if regular)
   bold-italic.

**Effort** S — a ~35-line port into `resolve_font`; the generated font table
(`Avm2FontData`, `avm2_abc.h:390`) already carries `bold`/`italic` per face and
the recompiler emits every embedded face
(`SWFRecomp/src/abc/abc_timeline.cpp:2115`).
**Gated:** `fallback_preferences`, `fonts/embed_matching/match_style`,
`visual/fonts/font_lookup_as3`, `visual/fonts/duplicate_font`.
**Hard dependency: must ship with T5** — see below.

### A.5 Mechanism T5 — the dynamic vertex budget caps native text at ~74 glyphs/frame ★ highest blast radius

**Proven, not inferred.** In `fallback_preferences` our render stops mid-word:
the final `r` of "Noto Sans Regular" is drawn as a **partial fragment** and
every field after it is blank (row-ink by row, ours vs Ruffle:
`[0,2366,1338,2870,1366,0,0,…]` vs all-20-rows-inked).

```
SWFModernRuntime/src/rendering/render_webgpu.c:973   #define MAX_DYNAMIC_RECTS    1024
SWFModernRuntime/src/rendering/render_webgpu.c:974   #define MAX_DYNAMIC_VERTICES 32768
SWFModernRuntime/src/rendering/render_webgpu.c:2073  if (ctx->dynamic_rect_count >= MAX_DYNAMIC_RECTS) return;
SWFModernRuntime/src/rendering/render_webgpu.c:2074-2075
        if (ctx->dynamic_vertex_used + vertex_count > MAX_DYNAMIC_VERTICES)
                vertex_count = MAX_DYNAMIC_VERTICES - ctx->dynamic_vertex_used;   // <- the partial glyph
```

`avm2_render_glyphs` issues **one `renderer_draw_tris` per glyph**
(`avm2_display.c:14274`), and a 30pt libtess2-CDT glyph from a DefineFont3
(≈114 flattened outline points → ≈110 triangles) costs ≈340–440 vertices. 74
glyphs exhaust 32768. The budget is shared with AVM1 textfield glyphs
(`tag.c:4841`), the drawing API (`tag.c:4895`/`:4907`/`:4939`) and every dynamic
rect; it resets per frame at `render_webgpu.c:1864`–`1865`.

This is why T4 cannot ship alone: making all 20 rows resolve to embedded fonts
raises the frame's glyph count from 74 to ~400 (≈137k vertices) and the cap
would still swallow three quarters of the page.

**Fix options** (do both):
- raise the caps — `MAX_DYNAMIC_VERTICES` 32768 → 262144 (staging mirror grows
  to 4 MB; `prev_dyn_vtx` is another 4 MB but is `__EMSCRIPTEN__`-only,
  `render_webgpu.c:1038`), `MAX_DYNAMIC_RECTS` 1024 → 4096;
- **batch a field's same-colour glyphs into one `draw_tris`** in
  `avm2_render_glyphs` — same vertex count, ~20× fewer rect slots and draw
  calls, and it is a straight win for the AVM2 games track too.

**Blast radius is large** (any previously-truncated frame changes). Capture a
`render_canary.py` before-leg first and expect the closeout `images=true` run to
move unrelated comparisons.

### A.6 Slice-level verdict

| group | comparisons directly gated | effort | confidence |
|---|---|---|---|
| T1 background+border | 16 (of which 1 alone) | S–M | high |
| T2 selection | 13 (overlaps T1), +4 riders | M | medium-high |
| T4 font fallback chain | 4 | S | high (algorithm is published) |
| T5 vertex budget | 1 in-slice, unknown riders | S (+M batching) | proven |
| T3 device fonts | ≥9, 3 of them `known_failure` | XL / arc | **defer** |

Realistic wave-2 target from this slice: **T1+T2+T4+T5 → 14–19 comparisons.**

---

## B. The two "frame-phase" suspects

### B.1 `from_gnash/misc-ming.all/loop/simple_loop_test` — a real one-tick phase bug ★ root-caused

The SWF (`FWS` v6, framerate 2, **framecount 4**) is: frame 1 empty, frame 2
places red@d2, frame 3 adds green@d3, frame 4 adds blue@d4. Captures are
`frame1..frame7` at `trigger = 2..8`.

Measured (modal colours of every capture, local == CI):

| tick | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|
| Ruffle | R | RG | **RGB** | blank | R | RG | RGB |
| ours | R | RG | **blank** | R | RG | blank | R |

Ruffle's period is 4; ours is 3. **The last frame is never displayed, and frame 0
is displayed one tick early.** Everything after tick 3 is exactly one tick ahead.

**Root cause — `SWFModernRuntime/src/libswf/swf.c:1094`–`1112`**, the
`OFFSCREEN_RENDER`-only "Phase 4 (TRANSFORMED_BY_SCRIPT_WRAP_BACK)" block:

```c
if (manual_next_frame && !goto_from_action && next_frame < current_frame
    && current_frame + 1 == g_frame_count && !g_force_quit) {
        ... if (has_stale) { goto_from_action = 1; g_natural_wrap_cleanup_pending = 1; }
}
```

On the tick that runs `frame_3` all five conditions hold (`manual_next_frame=1`
and `next_frame=0` are set by the recompiler's end-of-movie wrap, emitted in
`RecompiledTags/tagMain.c`; `current_frame+1 == 4 == g_frame_count`; depths 2/3/4
are `placed_at_frame > 0` so `has_stale`). It promotes the *natural* wrap into a
*script* goto, and the catch-up loop immediately below (`swf.c:1113`–`1158`)
**executes it in the same tick**: `ng_display_clear_after(0)` →
`actionRewindCleanup` → `frame_funcs[0]`.

The capture then happens *after* that, at `swf.c:1250`
(`capture_tick_after_events` → `tagRerenderFrame`) and `swf.c:1255`
(`capture_tick_post_frame`) — so the saved PNG is frame 0's blank stage, not
frame 4. The catch-up loop leaves `current_frame = 0`, `manual_next_frame = 0`,
so the tail `else if (is_playing) next_frame += 1` (`swf.c:1338`) makes the next
tick run `frame_1` — which is exactly the observed `t5 = R`. The model
reproduces all seven captures.

Note the light wrap path at `swf.c:1279`–`1336` does the *right* thing here: it
cleans up at end-of-tick and lets the next tick run `frame_funcs[0]` normally,
which yields Ruffle's sequence exactly. The Phase-4 promotion is what breaks it.

**Fix (wave-2 brief).** Defer the promotion by one tick. Replace
`goto_from_action = 1` with a pending flag (`g_pending_natural_wrap_promote`)
consumed at the top of the next iteration — right after
`current_frame = next_frame;` (`swf.c:537`) and before
`capture_tick_pre_frame()` (`swf.c:539`) — doing only the *cleanup* half
(`ng_display_clear_after(target)`, `actionRewindCleanup`,
`g_natural_wrap_cleanup_pending = 1`, `g_loopback_replay_armed = 1`) and letting
the tick's own `frame_funcs[current_frame]` call render frame 0. The promotion's
purpose is the `survives_rewind` cleanup semantics, not re-executing the frame.
**A narrower "skip `tagRerenderFrame` this tick" fix is NOT sufficient** — it
would fix `frame3` but leave `frame4`–`frame7` still one tick ahead, because the
catch-up loop consumed frame 0's tick.

- Fix site: `SWFModernRuntime/src/libswf/swf.c:1090`–`1112` (+ consumption near
  `:537`).
- Effort: S–M. Runtime-only, `OFFSCREEN_RENDER`-gated.
- **Regression risk to verify:** the block exists for
  `from_gnash/misc-ming.all/place_and_remove_object_insane_test` (named in the
  comment as the last strict no-graphics/graphics parity gap). Also re-check
  `avm1/default_names`, `from_shumway/avm1/text-bind`,
  `from_shumway/timeline/timeline_as2_1` — all named in the neighbouring
  comments. Any looping root whose last frame places content is in scope, so run
  the trace-side stash-diff sweep broadly, not just the canary.
- **Predicted flips: 5** (`frame3`–`frame7`; `frame1`/`frame2` stay
  dispositioned as hairline pixel-snapping, 242/483 px). The whole test becomes
  a candidate for the accepted-diff entry being narrowed further.

### B.2 `visual/edittext/edittext_border_transform` — **not** a phase bug

The board's frame-phase detector flags it because its six comparisons classify
four different ways, but the per-tick state machine is correct. The test is
**AVM1** (`test.as` + `input.json`), and each tick's key press selects a
border/background/embedFonts combination; our renders carry the right
combination on the right tick every time (tick1 border-only, tick2
background-only, tick3 both, ticks 4–6 the same with `embedFonts = true`).

Two real bugs, one mechanism family:

**(a) The AVM1 background/border box ignores the display object's transform.**

- `SWFModernRuntime/src/actionmodern/action.c:26338` `actionIterateTextFields`
  composes **only parent-chain translations** (`world_x += p->x; world_y += p->y`,
  `:26392`–`:26397`) and reports `info.w = mc->width + 1`, `info.h = mc->height + 1`
  (`:26418`–`:26420`) — the *unscaled* local size.
- `SWFModernRuntime/src/libswf/tag.c:4396` `textfield_render_cb` then draws with
  `renderer_draw_rect(..., 0, 0)` — **transform slot 0, i.e. identity**
  (`:4407`–`:4422`).

So `_xscale`/`_yscale`/`_rotation` on the field and any ancestor matrix
(`mc.transform.matrix` in this test) are all discarded. Visible directly in the
images: the row-1 fields are `(12×12 @100%)`, `(6×12 @200% x)`,
`(12×6 @200% y)` — all 12×12 on screen in Ruffle, but we draw 12×12, 6×12 and
12×6. The 45° field renders as an axis-aligned square where Ruffle shows a
diamond, and the two sheared clips render as squares where Ruffle shows
parallelograms.

*Fix shape:* give the callback the field's world matrix (allocate a transform
slot via `renderer_write_transform`, exactly as `avm2_render_glyphs` does at
`avm2_display.c:14162`) and emit the rect in field-local twips. Extend
`TextFieldRenderInfo` (`SWFModernRuntime/include/actionmodern/action.h:679`)
with the 2×3 matrix instead of the two floats. The same translation-only
shortcut exists in the glyph path (`tag.c:4435`+, `mask_x = info->x * 20.0f + …`)
so a matrix on the struct fixes both.

**(b) The device-font transform cull is missing.** Ruffle
(`edit_text.rs:2698`–`2702`) refuses to render an EditText **at all** when
`is_device_font()` and the transform is not positive-scale-only
(`|b| < 0.006 && |c| < 0.006 && a > 0 && d > 0`). Ticks 1–3 set
`embedFonts = false`, so Ruffle draws only the three positive-scale fields; we
draw all eleven. That is the whole `extra_element` signature of `output.01`/`.03`.

- Fix sites: `action.c:26338` (add the cull + the matrix), `action.h:679`
  (struct), `tag.c:4396` (consume the matrix).
- Effort: M — the matrix plumbing is the real work; the cull is ~10 lines.
- **Predicted flips: up to 6** (`output.01`–`.06`), plus riders
  `visual/edittext/edittext_device_transform_small_shear` (content_displaced),
  `edittext_border_basic_scale2` / `edittext_background_basic_scale2`
  (content_displaced / halo_penumbra) — those two also show whole missing boxes,
  so verify before counting them.
- Caveat: ticks 4–6 (`embedFonts = true`) need the rotated/sheared boxes drawn
  *correctly*, i.e. (a) must land for (b) to pay off; ticks 1–3 need (b).

---

## C. Wave-2 briefs (implementation-ready)

### Brief W2-A — "AVM2 TextField box + selection" (T1 + T2) — **take this first**
Runtime-only, one file pair. Draw background/border in `avm2_render_text`
(`avm2_display.c:14303`) through the field's world-xform slot, mirroring
`edit_text.rs:2704-2733` / `2930-2958` (embedded) and `2845-2910` (device,
`round_to_pixel_ties_even` first). Then teach
`avm2_edittext_collect_glyphs` (`avm2_text.c:3505`) to emit selection-box
placements and the inverted glyph colour per `edit_text.rs:1119-1196` /
`1239-1290`, gated on `visible_selection()` semantics (`edit_text.rs:1059`).
Ledger: `edittext_autosize_height_dynamic` (T1 alone), `edittext_selection_leading`
×12, `edittext_selection_font_size`; watch riders
`edittext_background_basic{,_scale2}`, `edittext_border_basic{,_scale2}`,
`edittext_gutter`, `edittext_tag_indent`, `edittext_always_show_selection`,
`cache_as_bitmap/edittext_selection` ×3.
Canary: the standing set + these tests.

### Brief W2-B — "font fallback chain + vertex budget" (T4 + T5) — **must be one patch**
Port `FontMap::find` (`~/CC/ruffle/core/src/library.rs:761-830`) into
`resolve_font` (`avm2_text.c:2504`); raise `MAX_DYNAMIC_VERTICES`/`MAX_DYNAMIC_RECTS`
(`render_webgpu.c:973-974`) and batch a field's same-colour glyphs into one
`renderer_draw_tris` in `avm2_render_glyphs` (`avm2_display.c:14205`).
Ledger: `fallback_preferences`, `embed_matching/match_style`, `font_lookup_as3`
(partial — its device-font half needs T3), `visual/fonts/duplicate_font`.
**High blast radius**: capture the `render_canary.py` before-leg *first*; expect
unrelated dense-text comparisons to move, and say so in the closeout.

### Brief W2-C — "defer the end-of-movie wrap by one tick" (P1)
`swf.c:1090-1112` → pending flag, consumed near `swf.c:537`; cleanup-only, no
in-tick `frame_funcs[0]`. Ledger: `simple_loop_test` `frame3`–`frame7` (5).
Mandatory verification: `place_and_remove_object_insane_test`, `avm1/default_names`,
`from_shumway/avm1/text-bind`, `from_shumway/timeline/timeline_as2_1`, plus a
broad trace-side stash-diff sweep (this touches every looping root).

### Brief W2-D — "AVM1 textfield box transform + device-font cull" (T6)
`action.h:679` (matrix on `TextFieldRenderInfo`), `action.c:26338` (world matrix
+ Ruffle's positive-scale-only device-font cull), `tag.c:4396` (draw through a
transform slot). Ledger: `edittext_border_transform` ×6; riders
`edittext_device_transform_small_shear`, `edittext_border_basic_scale2`,
`edittext_background_basic_scale2`.
Independent of W2-A (different VM, different files) — safe to run in parallel.

---

## D. Explicitly deferred / not winnable

- **T3, the device-font glyph subsystem.** No fallback face with outlines exists
  in the runtime (`noto_device_font`, `avm2_text.c:2483`, is metrics-only by
  design — `avm2-native-text-render-plan.md:18`). Closing it is a data-blob or
  TTF-rasterizer **arc**, not a sweep item. ≥9 comparisons hang off it
  (`hardwrap`, `stylesheet`, `flash_text_TextField`, the right half of
  `device_transform_basic`/`_negative`, the left half of `font_lookup_as3`,
  `visual/fonts/device-font`, `fonts/device_font_kerning`,
  `visual/fonts/leading_device_font`).
- **`from_shumway/hardwrap`, `stylesheet`, `flash_text_TextField`** —
  `known_failure = true` on the image comparison: **Ruffle does not match the
  expected PNG either**, so they are not winnable by matching it. Leave them off
  every ledger. (They are already excluded from the ranked board.)
- `edittext_selection_leading` `output.09` / `output.11` carry upstream
  `max_outliers = 36` with the note *"White selected text should always be
  rendered on top"* — Ruffle's own selection compositing is imperfect there;
  those two may need a tolerance note rather than a fix.
- **Not investigated** (outside the text slice, listed for completeness):
  `from_shumway/3_joystick` and
  `visual/focus_highlight/focus_highlight_avm2_button_bounds` are in
  `missing_element` but are not Text-family; the latter is already named on the
  playbook board as blocked on AVM2 SimpleButton state-children never entering
  `render_list`.
