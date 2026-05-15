# text-bind Runtime Follow-up — variable binding + invisible glyph render

**Document Version:** 0.1

**Created:** 2026-05-15

**Status:** Plan only. Two distinct runtime bugs uncovered by
[Phase A of the device-font-rendering plan][1] (commit `1401e62c`,
2026-05-14). Phase A made the recompiler synthesize ASCII 32..126
glyphs from `NotoSans.ttf` for zero-glyph `DefineFont2/3`. The
recompiler change works correctly, but the test image is still blank.
Per-test instrumentation isolated two independent downstream bugs in
the runtime, both blocking `from_shumway/avm1/text-bind`:

- **Bug A** — `actionNotifyPropertyChange` updates `htmlText` via
  `setProperty` without re-parsing the new HTML into the TFRunTable.
  The render path reads the run table, so it keeps emitting the
  static initial text (`FAILED`) instead of the bound value
  (`SUCCESS`).
- **Bug B** — in graphics-native mode (`OFFSCREEN_RENDER`),
  `renderer_draw_tris` calls from `textfield_glyph_render_cb` produce
  no visible pixels in the captured PNG, even with valid vertex
  coordinates and color. A sanity rect drawn at the top of
  `tagRerenderFrame`'s render pass is also invisible. Same code path
  successfully renders text for `place_object_test`'s embedded-font
  textfield in the same mode, so the failure is conditional on
  something specific to this test's setup or to a state left over
  from the per-tick `tagShowFrame` passes.

Both bugs are independent. Either alone keeps `text-bind` failing
(Bug A → wrong text rendered; Bug B → no text rendered at all). Both
must be fixed to pass the test.

[1]: device-font-rendering-plan.md

---

## Table of contents

1. [Executive summary](#executive-summary)
2. [Background — what Phase A unblocked](#background--what-phase-a-unblocked)
3. [Bug A — htmlText set-via-binding bypasses run-table reparse](#bug-a--htmltext-set-via-binding-bypasses-run-table-reparse)
4. [Bug B — invisible textfield glyphs in OFFSCREEN_RENDER](#bug-b--invisible-textfield-glyphs-in-offscreen_render)
5. [Test strategy](#test-strategy)
6. [Risk register](#risk-register)
7. [Open questions](#open-questions)

---

## Executive summary

`from_shumway/avm1/text-bind` is the lone image-comparison test that
exercises the `_sans` device-font path. The SWF:

- `DefineFont3 objectID=1 name="_sans"` with empty glyphs
- `DefineEditText objectID=2` (`fontRef=1`, color `#d662c6`, size 42,
  `variableName="_root.testField"`, initialText
  `<font face="_sans">FAILED</font>`, **isHTML=1**)
- `DoAction`: `this.testField = "SUCCESS"`
- `PlaceObject2` at depth 1, 5 `ShowFrame`s, then a depth-1 replace
  via the morphed re-placement at frame 5.

Expected (Ruffle): "SUCCESS" rendered in magenta. Actual: blank
canvas.

Phase A established that the recompiler now emits a full 95-glyph
font table for font_id=1, the runtime correctly resolves
`ng_find_font_with_metrics(1)` to the SWF's font, `ng_font_find_glyph`
returns valid indices, and `renderer_draw_tris(context, ...)` is
invoked with valid vertex coordinates and the expected magenta color.
But the saved PNG is still blank.

Per-test instrumentation surfaced two distinct downstream bugs.
They're independent, and fixing both is required for the test to
pass.

---

## Background — what Phase A unblocked

[device-font-rendering-plan.md][1] Phase A landed in commit
`1401e62c`. Concrete effects on `text-bind`'s recompiled output:

- `tagDefineFontInfo(app_context, 1, "_sans", 0, 0)` (unchanged)
- **NEW** `tagDefineFontMetrics(app_context, 1, 21893, 6000, 0, 20480,
  font_1_codes, font_1_advances, 95)` (95 codepoints 32..126 plus
  matched advance widths)
- **NEW** `tagDefineFontGlyphBase(1, 0)`
- `glyph_data[380][1]` (was `[1][1]`), with 95 valid
  `(tri_offset, tri_size, path_offset, path_size)` entries
- `shape_data[15030][4]` (was `[1][4]`), with ~5000 triangle vertices

Runtime verified via instrumentation:

| Check | Result |
|---|---|
| `ng_find_font_with_metrics(1)` | returns SWF's font 1 (not builtin fallback) |
| `ng_font_find_glyph(font_idx, 'F')` (= cp 70) | returns 38 |
| `glyph_data[4 * 38..4*38+3]` | `(6438, 24, 1057, 14)` — valid |
| `shape_data[6438..6438+23]` | 24 valid float pairs |
| Computed render coords for 'F' | first vertex `(3056, 2083)` twips, last `(2980, 1738)` twips — both inside the textfield mask `(2899, 1400, 7439, 3396)` |
| `info->font_id` / `font_idx` / `context` / `renderer_ok` | all valid |
| Color (`info->text_color = 0xD662C6`) | correct magenta |
| `renderer_draw_tris(context, xy_buf, 24, r, g, b, 1.0, 0, 0)` | invoked, no error |

So the recompiler-side and the call-site of the rendering path are
both correct. The bugs are strictly downstream.

---

## Bug A — htmlText set-via-binding bypasses run-table reparse

### Symptom

Render path (`actionIterateTextFieldGlyphs` →
`textfield_glyph_render_cb`) receives `text='FAILED\xFE'` (the static
initial HTML's plain-text), **not** the bound value `'SUCCESS'`. The
debug instrumentation logged this on every cb call across 6 ticks of
the test.

### Root cause

`actionNotifyPropertyChange` (`action.c:19204`) is the Phase-C
"variable change → bound TextField" propagator. When a property on a
container is written, the function walks
`container->avm1_text_field_bindings` and updates each matching
TextField. For an `isHTML=1` field, it does:

```c
if (is_html && text_len > 0) {
    ActionVar html_val = { … "SUCCESS" … };
    setProperty(app_context, props, "htmlText", 8, &html_val);
    …
    setProperty(app_context, props, "text", 4, &text_val);
    setProperty(app_context, props, "length", 6, &len_val);
}
```

`setProperty` is the low-level ASObject property setter. It writes
the value into the property bag but does **not** trigger any side
effect — in particular, it does not call the
`htmlText`-property-setter logic in `actionSetMember`.

The `htmlText`-property-setter logic, when invoked via
`actionSetMember` for an HTML field (`action.c:44220`), does the work
that matters for rendering:

```c
TFRunTable* table = tf_get_table(mc);
table->from_html_text = 1;
TFRun defaults;
tf_get_defaults(mc, &defaults);
…
tf_parse_html(table, _ht_buf, src_len, &defaults, condense_white,
              g_swf_version, is_multiline);
```

It parses the new HTML into the field's `TFRunTable` (replacing the
existing table). The render path
(`actionIterateTextFieldGlyphs:23750`) reads from this table:

```c
TFRunTable* table = tf_find_table(mc);
…
} else if (table != NULL && table->run_count > 0 && table->text_len > 0) {
    text_utf8 = table->text;
    utf8_len = table->text_len;
    …
}
```

So the render path sees the *initial-construction* table that was
parsed from the original `FAILED` HTML, not the post-binding-update
content. The `htmlText` and `text` properties are updated on the
ASObject, but nothing re-parses the HTML into runs.

This mirrors Ruffle's `EditText::set_html_text` (`edit_text.rs:1083`),
which is what the AVM1 `htmlText` write-and-binding path eventually
ends up calling. Our equivalent of that runs in `actionSetMember` but
not in `actionNotifyPropertyChange`, so the binding path is incomplete.

### Fix

Extract the HTML-parse logic into a helper function and call it from
both `actionSetMember` (existing path) and `actionNotifyPropertyChange`
(new path):

```c
// Re-parse htmlText into the TFRunTable and resync derived properties.
// Called from both the actionSetMember htmlText setter (when AS code
// writes mc.htmlText = ...) and from actionNotifyPropertyChange (when
// a bound variable change propagates).
void actionRebuildTFRunTableFromHtml(SWFAppContext* app_context,
    MovieClip* tf_mc, const uint16_t* html_u16, u32 html_len);
```

Implementation: lift the block in `action.c:44218-44320` into the new
helper. Behavior must be identical between the two callers; gate
condensWhite / multiline / defaults exactly as the existing setMember
path does. Call the helper from `actionNotifyPropertyChange` *after*
`setProperty(props, "htmlText", ...)`.

Scope: ~80 LOC of refactor in `action.c`. No new state, no AS-visible
changes. The plain-text (non-HTML) path in
`actionNotifyPropertyChange` does **not** need this — it only sets
`text`, which the render path already reads from `props` directly
when no run table exists.

### Acceptance criteria

- `text-bind` render path receives `text='SUCCESS'` instead of
  `text='FAILED'` (verified via instrumentation; remove the
  instrumentation before commit).
- `from_gnash/misc-ming.all/DefineEditTextTest`,
  `DefineEditTextVariableNameTest`, `TextFieldHTMLTest` continue to
  pass — these exercise both code paths.
- `avm1/edittext_*` and `avm1/textfield_*` regression sample
  (autosize, bullet, font_size, html_*, var_*) stays green.

### Out of scope

- Plain-text binding propagation (Bug A is HTML-specific).
- Updating `length` / `_tf_fontHeight` / `_tf_letterSpacing` from
  the binding path beyond what `setProperty("text", ...)` already
  does — the helper will fold this in correctly.

---

## Bug B — invisible textfield glyphs in OFFSCREEN_RENDER

### Symptom

In graphics-native mode (`-DOFFSCREEN_RENDER`):

1. `textfield_glyph_render_cb` is called with valid args. `renderer_draw_tris`
   is invoked with valid vertex coordinates inside the canvas
   bounding box and the correct magenta color.
2. A sanity rect drawn at the top of `tagRerenderFrame` (right after
   `renderer_open_pass`, color cyan, position `(1000, 1000, 200, 200)`
   twips = `(50, 50, 10, 10)` px, well inside the 550×400 canvas) is
   also **not** visible in the captured PNG.
3. The captured PNG shows only the background color (white).

### Context

The test's render flow under `OFFSCREEN_RENDER`:

- `tagShowFrame` runs once per tick (6 ticks total). Each tick:
  `renderer_open_pass` → render → `renderer_close_pass`. During
  these passes `capture_requested = 0`, so `close_pass` does **not**
  copy the offscreen texture to the readback buffer.
- After `tagMain` returns, `swf.c:1101` calls
  `renderer_request_capture(context)` (sets `capture_requested = 1`)
  then `tagRerenderFrame(app_context)`. This opens a new pass, draws,
  closes the pass. With `capture_requested = 1`, `close_pass`
  **does** copy the offscreen texture to the readback buffer
  (`render_webgpu.c:2226-2242`).
- `swf.c:1109` calls `capture_save_last_frame()` which calls
  `renderer_save_png` which maps the readback buffer and writes the
  PNG.

So the captured PNG is whatever `tagRerenderFrame`'s pass rendered.

The render pass uses MSAA: MSAA samples are cleared at pass start
(loadOp=Clear, clearValue=background color), draws write into MSAA
samples, end-of-pass resolves MSAA → offscreen texture, then the
copy moves offscreen → readback. All three steps are queued into the
same command encoder and submitted atomically, so the readback
should reflect the resolved MSAA output.

### Why this is mysterious

The same code path renders `_xtrace_win`-style trace text in
`from_gnash/misc-ming.all/place_object_test` correctly (image
RUFFLE_MATCHED). That test exercises `textfield_glyph_render_cb` for
an embedded-font textfield via the **orphan walk**
(`actionIterateOrphanTextFields`). `text-bind` exercises it via the
**MC walk** (`actionIterateTextFieldGlyphs`), because Phase B of the
[textfield variable binding plan][2] now eagerly creates an MC
wrapper for every placed `DefineEditText`.

[2]: textfield-variable-binding-plan.md

Both walks eventually call `textfield_glyph_render_cb` with very
similar `TextFieldGlyphInfo` (same kind of `x`/`y`/`w`/`h`/runs/etc.).
The path through the renderer is identical. Yet `place_object_test`
draws and `text-bind` doesn't.

### Hypotheses to test, in order of likelihood

1. **`tagRerenderFrame` opens a pass but `tagShowFrame`'s pass
   sequence has already exhausted some pool / left some state
   dirty** — e.g., `dynamic_vertex_used` or `dynamic_rect_count` is
   reset by `open_pass`, but a separate per-pass state could be
   broken.
   - **Probe:** add per-pass debug to `close_pass` (vertex/rect
     count, encoder pointer, render pass pointer) — verify
     `tagRerenderFrame`'s pass has fresh counters and submits to
     the GPU.

2. **The cyan sanity rect was drawn but is occluded.** Unlikely
   given the rect is the *first* draw in the pass (nothing exists to
   occlude it yet) and depth/stencil are reset by `open_pass`, but
   worth eliminating.
   - **Probe:** dump the readback bytes (or save a PNG immediately
     after the cyan rect with a one-shot capture detour) before any
     other draws happen.

3. **`renderer_draw_rect` and `renderer_draw_tris` don't survive the
   MSAA resolve correctly when the *only* prior draw was the
   background clear.** Empty render pass corner case? Vertex buffer
   binding state inherited from before `open_pass`?
   - **Probe:** call `renderer_draw_rect` from inside
     `place_object_test`'s render path (which works) vs from
     `text-bind`'s (which doesn't) and observe.

4. **`tagRerenderFrame` is being called but its render pass is
   never submitted to the GPU** (encoder leak, queue submit
   skipped, etc.). The previous tagShowFrame's pass IS submitted
   per tick, so the offscreen texture holds the per-tick render at
   that point. If tagRerenderFrame opens a new pass but never
   submits, the offscreen texture retains the *previous* tick's
   content (post-loop-back to frame 0, the timeline is in an
   unrendered state, so offscreen would be background-only).
   - **Probe:** instrument `wgpuQueueSubmit` to count submit
     invocations and verify the count matches expectations.

5. **Per-tick `tagShowFrame` passes ARE rendering correctly into
   offscreen, then `tagRerenderFrame` opens a fresh pass that
   *clears* the offscreen back to the background.** Each new pass
   with loadOp=Clear targets the MSAA attachment, but the resolve
   target is the offscreen texture — and a pass with no draws
   resolves the cleared MSAA into the offscreen.
   - **Probe:** if hypothesis 5 is right, removing
     `tagRerenderFrame` (and triggering capture before the last
     `tagShowFrame`'s close_pass) should show the per-tick content.

6. **`tagRerenderFrame` runs but `display_list[1]` has been cleared
   by the natural-backward-wrap cleanup** (`swf.c:836-845`) at the
   end of tick 6 (looped from frame 5 → 0). MC walk would still
   fire (MC is in `child_mc_cache`, not `display_list`), but
   anything that depends on a non-zero `display_list[depth].char_id`
   to find the TF (e.g., for transform composition) might miss it.
   - **Probe:** dump `display_list[1].char_id` at the entry to
     `tagRerenderFrame`.

7. **Float / arithmetic edge case in vertex computation breaks the
   geometry shader pipeline silently.** Synthesized glyphs from
   `NotoSans.ttf` via stb_truetype produce specific vertex values;
   maybe a single NaN or out-of-range value in our `xy_buf` corrupts
   the GPU buffer write. The other text test that works uses
   embedded SWF glyphs (different value distribution).
   - **Probe:** scan `xy_buf` for NaN/Inf before
     `renderer_draw_tris`. Compare a synthesized 'F' glyph's
     vertices to an embedded-font 'F' from a working test.

8. **`info->x`, `info->y`, `info->w`, `info->h` from the MC walk
   are subtly different from the orphan walk's, producing a clip
   mask or transform that excludes the rendered glyphs.** Phase B's
   eager wrapper might leave `mc->width` / `mc->height` at 0 or
   `INT_MIN` while the orphan walk reads bounds from the static
   DefineEditText tag.
   - **Probe:** log `mc->width` and `mc->height` for our TF
     vs `place_object_test`'s TF.

### Suggested investigation sequence

Phase A: probe hypotheses 1, 4, 5 in parallel (small per-line
instrumentation in `close_pass`, `wgpuQueueSubmit`, and the
`tagRerenderFrame`/`tagShowFrame` boundary). These would isolate
"is tagRerenderFrame's pass executing at all?" definitively.

Phase B: if Phase A doesn't catch it, probe 2, 6, 8 (more localized
state checks). Hypothesis 8 in particular is cheap — just log
`mc->width` and compare.

Phase C: if still not caught, hypothesis 7 (vertex value check).

Each probe is reversible (single-printf-style instrumentation) and
removable before commit.

### Fix shape (to be confirmed by investigation)

Depends on root cause. Plausible shapes:

- **State-leak in tagRerenderFrame.** Mirror whatever setup
  `tagShowFrame` does that `tagRerenderFrame` skips. Likely 1–10 LOC.
- **MC walk delivers wrong bounds.** Plumb the proper bounds from
  `ng_getTextFieldBounds` through the MC walk too — orphan walk
  already does this; MC walk uses `mc->width` / `mc->height` which
  may be uninitialized for an eagerly-created TF wrapper. ~10 LOC.
- **Empty-content offscreen-clear-only resolve corner case.** Worst
  case; would require a renderer-level fix. Could be sidestepped
  by capturing during the last `tagShowFrame` instead of with a
  separate `tagRerenderFrame`.

### Acceptance criteria

- `text-bind` `output.actual.png` shows magenta "SUCCESS" at the
  expected position (combined with Bug A fix).
- `place_object_test` and the 17 graphics-passing `avm1/edittext_*`
  / `avm1/textfield_*` tests continue to render correctly.
- No regression on other image-comparison tests (sample the 76 known
  image tests via CI dispatch; locally just confirm representative
  ones).

### Out of scope

- Sub-pixel parity with Ruffle's renderer (glyph outline differences
  vs Flash's device-font are already in
  `ACCEPTED_DIFFS.md::movieclip_hittest_shapeflag`).
- Variable binding for non-HTML fields (Bug A handles only HTML;
  plain-text bindings already work).
- Refactoring `tagShowFrame` / `tagRerenderFrame` to share a single
  render core — useful but a separate cleanup.

---

## Test strategy

### Per-bug regression batteries

**Bug A:**

- Driver: `from_shumway/avm1/text-bind` (image — must show
  "SUCCESS", combined with Bug B fix).
- Smoke set:
  `from_gnash/misc-ming.all/{DefineEditTextTest,DefineEditTextVariableNameTest,TextFieldHTMLTest}`,
  `avm1/{edittext_html_align_swf7,edittext_html_align_swf8,
  edittext_html_entity,edittext_var_*}`.

**Bug B:**

- Driver: `from_shumway/avm1/text-bind` (image — must show *any*
  rendered glyphs, even if Bug A still wrong).
- Smoke set: `from_gnash/misc-ming.all/place_object_test` (reference
  working case),
  `avm1/{edittext_autosize,edittext_bullet,edittext_font_size,
  movieclip_create_text_field,frame_size_translated_positive}`,
  any other image-compared test that exercises
  `textfield_glyph_render_cb`.

### Regression sweep

After each fix, run a 20-test mixed graphics-mode battery covering
edittext, textfield, sprite, button, and shape categories. CI
handles the full sweep — locally only sample. Reset
`.pipeline-state` to `idle` only when both fixes land.

### CI-only validation

Full-suite numbers come from the `ruffle-tests.yml` workflow
dispatch in `--mode=graphics`. Bug A may affect default mode
(`NO_GRAPHICS`) too — both modes need the helper extraction. Bug B
is graphics-only.

---

## Risk register

| # | Risk | Bug | Mitigation |
|---|---|---|---|
| 1 | Helper extraction for Bug A inadvertently changes behavior in the existing `actionSetMember` path | A | Bit-for-bit compare against current behavior across the smoke set. Pull the body into the helper, leave the call sites identical; verify the diff is mechanical. |
| 2 | `actionNotifyPropertyChange` calling the helper triggers a feedback loop (binding-write → property-set → binding-write → …) | A | Existing `FIRING_VARIABLE_BINDING` guard in Ruffle; check whether our `g_inside_set_html_text` or equivalent already exists. If not, add a TLS flag during the helper call. |
| 3 | Bug B investigation surfaces a state issue that's specific to natural-loop-back, not to device-font rendering | B | If hypothesis 6 is correct, the fix is in display_list cleanup logic, not in the renderer. Plan handles either outcome. |
| 4 | Fixing Bug B reveals more layers (e.g., MC walk bounds wrong, AND vertex buffer state stale) | B | Phased investigation (3 probe waves) catches multi-layer issues incrementally. |
| 5 | Refactoring HTML-parse into a helper introduces a one-tick lag in run-table updates that breaks a synchronous-bound test | A | Run the smoke set including binding-sync tests; if needed, add an inline call instead of an extracted helper. |
| 6 | Glyph shape differences between synthesized Noto Sans and place_object_test's embedded "Bitstream Vera Sans" cause sub-pixel diffs even after Bug B is fixed | A+B | text-bind's `test.toml` already specifies generous tolerance (`128 / 100` + `64 / 600`). If diffs trip it, add a Ruffle-vs-Flash entry; do not loosen tolerance globally. |
| 7 | The investigation reveals tagRerenderFrame is fundamentally broken for the synthesized-glyph case (e.g., glyph_data layout mismatch between recompiler and runtime) | B | Phase A's recompiler output was hand-verified to match the runtime's expected layout. If a layout mismatch shows up, it's a Phase A correctness bug — fall back and adjust the synthesis output to match. |

---

## Investigation update (2026-05-15)

### Bug A — fixed

Commit `5d7228e8` extracted `tfRebuildFromHtml` from `actionSetMember`'s
HTML branch and called it from `actionNotifyPropertyChange`. Confirmed
via instrumentation that text-bind's render path now receives
`text='SUCCESS'` (the bound value) instead of `'FAILED'` (the static
initial text). Image still fails because Bug B is still active.

### Bug B — narrowed but not solved

Per-test probing (probes from the original plan, then more):

- **Per-tick `tagShowFrame` rendering doesn't reach readback either.**
  Adding `renderer_request_capture(context)` to every per-tick
  `tagShowFrame` pass + disabling the trailing `tagRerenderFrame` made
  no difference. So the bug is not specific to `tagRerenderFrame`'s
  pass; it's specific to the entire OFFSCREEN_RENDER pipeline state
  for this test.
- **Rules out the textfield code path.** Commenting out
  `actionIterateTextFields` / `actionIterateTextFieldGlyphs` /
  `actionIterateOrphanTextFields` calls in tagShowFrame left the
  cyan-sanity rect (drawn at the top of the pass, before any
  textfield code runs) still invisible. So the textfield rendering
  isn't corrupting state for subsequent draws either.
- **Rules out the SWF content.** Stripping `tagInit` to bare bones
  (no `tagDefineFontInfo` / `tagDefineFontMetrics` / `tagDefineText`
  / `tagDefineEditTextProps` calls — just
  `tagInitSpriteFrameScripts` + `initVarArray`) plus stripping
  `frame_0` to just `tagSetBackgroundColor` + `tagShowFrame`
  reproduced the blank canvas. So **even an empty SWF with this
  test's metadata renders blank.**
- **Same code path works for `place_object_test`.** Adding the same
  cyan rect at the top of `tagShowFrame`'s render pass shows up
  visibly at (50, 50) px in `place_object_test`'s
  `output.actual.png`, but not in `text-bind`'s. So
  `renderer_draw_rect` is functionally correct when invoked from the
  same call site in another test.
- **Phase A's synthesized vertex data is well-formed.** Scanned
  `text-bind`'s `shape_data` (15030 vertices, ~5000 triangles) for
  IEEE 754 NaN / Inf / out-of-range values; zero occurrences.
- **Color transform is correct.** `cxform_data[0..19]` is identity
  (the recompiler emits an identity cxform at slot 0 in
  `swf.cpp:544-568`). The cyan rect uses `cxform_id=0`, so the
  shader's `apply_cxform` should not modify the color.
- **Differences between test-bind and place_object_test SWF
  metadata:** canvas 550×400 vs 800×600; FRAME_WIDTH_TWIPS
  11000 vs 16000; SWF_VERSION 17 vs 5; SWF_FRAME_COUNT 6 vs 3.
  Both have BITMAP_COUNT=0.

### Surfaces during investigation

- **ASAN run reports** these warnings during WebGPU device init for
  text-bind (uncertain whether they are causal):
  ```
  Warning: maxDynamicUniformBuffersPerPipelineLayout artificially
           reduced from 500000 to 16 to fit dynamic offset
           allocation limit.
  Warning: maxDynamicStorageBuffersPerPipelineLayout artificially
           reduced from 500000 to 16 to fit dynamic offset
           allocation limit.
  ```
  Same warnings appear for `place_object_test`, so they're not a
  smoking gun, but worth tracking when revisiting.

### Revised hypotheses (after the above probes)

The original plan's hypotheses 1, 2, 3, 5, 6, 7 are largely ruled
out by the probes above (rendering happens, draws are queued, no
NaN/Inf, no `tagRerenderFrame`-specific bug, no MC-bounds issue).
Surviving / new hypotheses:

- **(new) The per-test runtime is loading a stale `.png` from a
  prior failed run.** Not actually — `verify_output.py:2952-2965`
  produces `actual_png = build_dir / "output.png"` afresh each test.
- **(new) The compiled binary has different WebGPU device limits
  depending on a per-SWF compile-time constant that affects
  buffer-size negotiation.** The `MAX_DYNAMIC_RECTS` / `MAX_DYNAMIC_VERTICES`
  constants are fixed but the `xform_buffer` size scales with
  `transform_data_size` (`render_webgpu.c:785-795`). For text-bind,
  `transform_data` has 235 entries × 16 floats = 15040 floats →
  buffer size ~60KB + 512 dynamic slots = 90KB. Below the WebGPU
  default storage-buffer limit (128MB), so shouldn't trip a hard
  cap. But maybe `dynamicOffsetAlignment` interacts oddly with a
  particular total size.
- **(new) Lavapipe-specific bug.** The runner forces
  `VK_DRIVER_FILES=/usr/share/vulkan/icd.d/lvp_icd.json` for WSL2
  compatibility (`verify_output.py:2879-2880`). Lavapipe is a
  software Vulkan implementation; it has occasional issues that
  hardware Vulkan would mask. Worth re-running on hardware Vulkan
  to confirm (or in CI, which uses different driver setup).
- **(new) The bug is data-driven on a value in one of the per-SWF
  arrays — `shape_data`, `transform_data`, `cxform_data`, etc. —
  that is valid as a float but causes the pipeline to misbehave.**
  Could be a particular cxform combination, a transform with
  near-zero determinant, etc. Bisection by zeroing one array at a
  time would isolate it.

### Suggested next steps

- **Bisect by NULLing one app_context array at a time.** Set
  `app_context.shape_data = NULL` (and `shape_data_size = 0`),
  see if cyan reappears. Then try `transform_data`, `cxform_data`,
  etc. Whichever one's removal restores the cyan rect is the
  culprit.
- **Diff the WebGPU pipeline state between text-bind and
  place_object_test at first `tagShowFrame::open_pass`.** Likely
  identical since the code is the same; if not, that's the bug.
- **Try a single-frame stub-SWF with text-bind's exact dimensions.**
  Generate a minimal SWF with width 550, height 400, version 17,
  6 frames, no content. If cyan still doesn't appear, the bug is
  in the renderer init for those specific dimensions. If cyan
  appears, the bug is in some downstream data.
- **Try setting `SWFRECOMP_DEVICE_FONT_FALLBACK=0` and re-running
  text-bind with Phase A's synthesis reverted.** If cyan appears,
  the bug is downstream of Phase A's vertex / glyph data emission.
  If cyan still doesn't appear, the bug is older than Phase A
  (text-bind was always blank, Phase A just made the failure
  more visible because we now expect glyphs to render).
  **CONFIRMED 2026-05-15:** Disabling Phase A's synthesis branch
  (`if (0 && ...)`) and re-running text-bind with a cyan probe rect
  at the top of `tagShowFrame`'s render pass produces the same
  blank canvas. So Bug B is independent of Phase A — text-bind
  was always blank, Phase A just made the "wrong output" more
  visible (since the test now expects glyphs to render).

### Bug B — root cause found via per-frame captures (2026-05-15)

The breakthrough: configure `test.toml` with multiple
`[image_comparisons.frameN]` entries with `trigger = N` for
N = 0..5, plus a small `verify_output.py` tweak to copy actual PNGs
to the test dir even when `expected.png` doesn't exist:

```toml
[image_comparisons."frame1"]
trigger = 1
tolerance = 128
max_outliers = 999999
# ... frame2..frame5 similar
```

Result: each per-tick capture (`frame1.actual.png` through
`frame5.actual.png`) shows **correctly rendered text**. `frame5`
even shows the bound-variable value (`"SUCCESS"`) in magenta at
the expected position. Only the `last_frame` capture
(`output.actual.png`) is blank.

So the *entire rendering pipeline works correctly* throughout the
run. The bug is just that the `last_frame` capture happens at a
moment when the display_list has been wiped.

**Root cause:** `swf.c:836-851` runs a "natural backward wrap"
cleanup at end of each tick where `manual_next_frame` is set and
`next_frame < current_frame`. For `text-bind`, frame_5 sets
`manual_next_frame=1, next_frame=0` (looping back). The cleanup:

1. Walks display_list looking for entries with `placed_at_frame > next_frame=0`.
2. For each, invalidates cached MCs and clears the entry.

After frame_5 ran, depth 1 had `placed_at_frame=5` (the morphed
re-placement). So the cleanup wipes depth 1. The next tick's
frame_0 would re-place it — but if there is no next tick (we're
at `tick_count >= max_ticks`), the cleanup just destroys state for
nothing.

Then the final `tagRerenderFrame` in `swf.c:1101` iterates the
now-empty display_list and the orphan-TF walk finds no TF to
render either.

**Fix (commit `498e5148`):** gate the wrap-back cleanup on
`tick_count < max_ticks` — skip it on the last tick. The skipped
cleanup was pure destruction with no following frame to consume
its preparation. Regression batteries green: `avm1/default_names`
(the canary the wrap-back was originally added for),
`avm1/goto_frame`, `avm1/goto_frame2`,
`avm1/register_class_return_value`.

### Bug C — TFRunTable not rebuilt by placement-time binding

After the wrap-back fix, `text-bind`'s `output.actual.png` shows
"FAILED" instead of "SUCCESS". Same-shape bug as Bug A, different
call site:

- frame_5 re-places depth 1 with `char_id=3` (a fresh EditText
  with `initialText="FAILED"`).
- `findOrCreateMovieClip` detects the textfield-changed case
  (`new_tf_idx != mc->ng_textfield_idx`) and runs the property
  re-init at action.c:19744, calling `tf_parse_html(table,
  raw_html, ...)` — table is now populated with "FAILED" runs.
- Then `actionTryBindTextFieldVariable` (action.c:19543) finds
  the bound variable `_root.testField="SUCCESS"` and does:
  ```c
  setProperty(props, "htmlText", existing_val);  // raw, no parse
  strip_html_tags_u16(...);
  setProperty(props, "text", stripped);
  setProperty(props, "length", stripped_len);
  ```
  Same bug as the pre-Bug-A `actionNotifyPropertyChange`: the
  binding update sets the property bag but doesn't rebuild the
  TFRunTable. So when rendering, the table still has the "FAILED"
  runs from init.

**Fix shape:** call `tfRebuildFromHtml` from
`actionTryBindTextFieldVariable`'s `is_html` branch after
`setProperty("htmlText", ...)`. Identical to the Bug A fix in
shape, just on a different call site. Plain-text path
(non-HTML field) doesn't need the helper.

**Why per-tick captures still showed "SUCCESS":** during ticks 1-4
the TF is `char_id=2` (the original placement), which received the
binding update via Bug A's `actionNotifyPropertyChange` after
`script_0` wrote `this.testField = "SUCCESS"`. That fix correctly
rebuilt TF1's TFRunTable. Tick 5 swapped to `char_id=3` (TF2),
which got the bound value through the placement-time path
(actionTryBindTextFieldVariable), which has the equivalent bug.
But tick 5's per-iteration capture happens *during* tick 5 — and
at that moment, the renderer found TF1's MC still in cache
(depth still valid, not yet INT_MIN), so it rendered TF1's
"SUCCESS"-table not TF2's "FAILED"-table. The final capture
happens after TF1 has been swept; only TF2 is left to render.

## Open questions

- **OQ-1.** Does the `actionNotifyPropertyChange` HTML path also
  need to handle the multiline / condense-white settings the same
  way the `actionSetMember` path does? Probably yes — those affect
  how runs are split, so the rendered output differs. Verify via
  the smoke set.

- **OQ-2.** When the helper re-parses HTML on a binding update,
  does the old `TFRunTable` get freed cleanly? `tf_get_table`
  returns a slot from `g_tf_run_tables[TF_MAX_TABLES]`; the slot is
  per-MC, so re-parsing into the same slot is fine for the table
  storage itself, but any heap-allocated `run.text` / `run.style`
  strings need to be released. Check `tf_parse_html`'s teardown of
  the old runs.

- **OQ-3.** For Bug B, is there a simpler reproducer than text-bind?
  E.g., a minimal test that runs a single `tagShowFrame` then
  `tagRerenderFrame` with one cyan rect — does that rect appear in
  the PNG? If not, the bug is in `tagRerenderFrame` itself; if yes,
  the bug is conditional on something text-bind triggers
  specifically.

- **OQ-4.** Phase C of the [device-font-rendering plan][1] (runtime
  TrueType rasterization) would make Bug B less impactful: glyph
  rendering would no longer route through static `glyph_data` /
  `shape_data`, so even if the current path has issues, the Phase C
  path bypasses them entirely. Is fixing Bug B worth doing if Phase
  C is the eventual destination? Probably yes — Bug B almost
  certainly affects other graphics-mode tests we just haven't
  noticed yet (any test that depends on the post-loop-back final
  render being correct).

- **OQ-5.** Bug A's fix (helper extraction) could also be useful
  for plain-text binding propagation in some edge cases (e.g.,
  setText followed by setVariable). Worth checking if any tests
  depend on that sequence.

---

## Sequence

Bug A first — smaller scope, clearer fix, AS-observable side
effects. Bug B second — investigation-heavy, blocks the image-only
acceptance criterion. Both must land before `text-bind` passes.

If Bug B's investigation reveals a renderer-level issue that
affects other tests in the suite, expand scope into a separate plan
(`offscreen-render-state-leak-plan.md`) before fixing.
