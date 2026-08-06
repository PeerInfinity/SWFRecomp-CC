# wave1-gfx-clipping — AVM2 clipping cluster (scrollRect / bitmap fills / MovieClip button states)

Session 11, wave 1, **READ-ONLY**. Baseline `b4c983ea4` (= `origin/master`), CI
run `30713776612` at `c4496a4c8`: trace 4188/4424, pixels 217/566.
`git status` for tracked files is unchanged (only the pre-existing three
untracked dirs plus this report's new directory).

Local repros: `verify_output.py --mode=graphics --images --image-out-dir=<scratch>
--recompile` on `visual/avm2_button_scroll_rect`, `from_shumway/button2`,
`from_shumway/bitmapbuttons`, plus a trace-only run of
`avm2/displayobject_scrollrect`. All under `-P 1` (sequential).

---

## 0. Headline — the arc splits three ways, and only one is a wave-2 target

| target | mechanism verdict | predicted image flips | verdict |
|---|---|---|---|
| **`from_shumway/button2` ×3** | **REFUTED & REDIAGNOSED** — nothing to do with SimpleButton or "Fix B". It is `MovieClip` + `buttonMode` + `_up`/`_over`/`_down` **frame labels**, a Ruffle mechanism we do not implement at all | **+3, exact** | **GO** (small, runtime-only, ~zero regression surface) |
| `visual/avm2_button_scroll_rect` | **CONFIRMED** — AVM2 walk has no clipping of any kind | **0** (34590 → **~96**) — blocked behind an MSAA/`quality` mismatch, §2.4 | **NO-GO for pixels this wave**; correctness/band-move only |
| `from_shumway/bitmapbuttons` | **CONFIRMED + widened** — two independent blockers, one of them a **recompiler** change | **0** (low confidence of a flip even when fully implemented) | **DEFER**, name it as a tranche |

**The single most important finding is §2.4**: `avm2_button_scroll_rect` and
`avm2/displayobject_scrollrect` — the entire AVM2 scrollRect pixel yield — are
gated behind an **antialiasing sample-count mismatch**, not behind clipping. Both
goldens were rendered by Ruffle at `quality = "low"` (**1 sample, no MSAA**;
`~/CC/ruffle/render/src/quality.rs:65-76`) and contain literally 2 and 4 distinct
colours. Our renderer hard-codes `multisample.count = 4`
(`render_webgpu.c:1422`, and 5 more sites). Every curved edge in a
`quality = "low"` test therefore carries an irreducible residual against a
`tolerance = 0 / max_outliers = 0` comparison. **A perfect scrollRect
implementation leaves `avm2_button_scroll_rect` at ~96 outliers and still
`fail`.** Measured, not guessed — §2.4.

**Bonus methodology result (worth promoting to the playbook):** for all three
targets the CI (lavapipe) `output.actual.png` on `origin/ruffle-image-results` is
**byte-identical (same md5)** to my local Dawn render. The playbook's "local Dawn
is not pixel-identical to CI lavapipe" caution held for none of these three. That
does **not** license grading local renders against goldens in general, but it
does mean the ~96-outlier prediction below is a CI number, not a local one.

---

## 0.1 Mandatory pre-checks

| doc | `avm2_button_scroll_rect` | `bitmapbuttons` | `button2` | `displayobject_scrollrect` |
|---|---|---|---|---|
| `avm1/_investigation/ACCEPTED_DIFFS.md` | — | — | — | — |
| `RUFFLE_VS_FLASH_DIFFERENCES.md` | — | — | — | — |
| `RUFFLE_COMPAT_TWEAKS.md` | — | — | — | — |
| `FLASH_BUGS_REPLICATED.md` | — | — | — | — |
| `ruffle-tests/ignored_tests.txt` | — | — | — | — |
| `known_failure` in the image JSON | false | false | false | false |

Nothing in the target set is dispositioned.

---

## 1. Verified current pixel status (from the merged `image_results_graphics.json` @ `c4496a4c8`)

| suite | test | cmp | status | outliers | max_outliers | tol | trace |
|---|---|---|---|---|---|---|---|
| visual | `avm2_button_scroll_rect` | `output` | fail | 34590 | 0 | 0 | pass |
| from_shumway | `bitmapbuttons` | `output` | fail | 618042 | 0 | 4 | pass |
| from_shumway | `button2` | `output.1` | **pass** | 0 | 0 | 0 | pass |
| from_shumway | `button2` | `output.2` | fail | 95634 | 0 | 0 | pass |
| from_shumway | `button2` | `output.3` | fail | 95634 | 0 | 0 | pass |
| from_shumway | `button2` | `output.4` | fail | 95634 | 0 | 0 | pass |
| avm2 | `displayobject_scrollrect` | `output` | fail | 203367 | 0 | 0 | **output_mismatch** |

`avm2_button_scroll_rect` moved 28851 → 34590 exactly as session-10's w2-button
report predicted (the button now draws, unclipped and unoffset). That is
confirmed churn, not a regression.

---

## 2. Target 1 — `visual/avm2_button_scroll_rect`

### 2.1 The script and the geometry, measured

`RecompiledABC/abc0_methods.c:118-141` — `this.button.scrollRect = new
Rectangle(10, 10, 100, 100)`. The button's up-state child is a 156×156 px circle
(`#0099CC`) whose local origin maps to stage (22, 22).

| render | non-white bbox | blue px |
|---|---|---|
| ours (local Dawn == CI lavapipe, md5 `1382a73f`) | (22,22)–(177,177) = **156×156** | 18722 + 331 AA px |
| Ruffle golden | (22,22)–(121,121) = **100×100** | 9617, **2 colours total, zero AA** |

The golden is exactly Ruffle's model: content translated by `(-10,-10)` px and
clipped to the object-local box `(0,0,100,100)`. Re-derived arithmetically —
circle centre after the shift is stage (90,90) r=78; at y=22 its span is
90 ± √(78²−68²) = [51.8, 128.2], clipped to [22,122]; the golden's row-5 span is
[48,120]. Match.

### 2.2 Mechanism — CONFIRMED, the prior claim is NOT stale

`avm2_render_node` (`SWFModernRuntime/src/avm2/avm2_display.c:14843-14894`) is
still ~50 lines: visibility cull → matrix compose → cxform compose → dispatch to
`avm2_render_{bitmap,morph,shape,text,statictext,graphics}` → the session-10
SimpleButton arm (`:14889`) → `for (i < ext->render_len)` (`:14892`). It reads
**none** of `ext->clip_depth`, `ext->mask`, `ext->maskee`, `ext->has_scroll_rect`.
`grep begin_clip|end_clip|scissor` over `SWFModernRuntime/src/avm2/` returns
**zero hits**. Session-10 `wave1-gfx-masks.md` §4 stands.

`scrollRect` storage and its consumers:

| what | where |
|---|---|
| storage `has_scroll_rect` + `sr_xmin/ymin/xmax/ymax` (whole-pixel-rounded twips) | `include/avm2/avm2_globals.h:510-514` |
| getter / setter | `avm2_display.c:10052-10081` |
| **only** non-getter consumer: bounds override | `avm2_display.c:722-731` |
| render walk | **nothing** |

### 2.3 Fix sketch (runtime-only, one wave-2 agent, ~1.5 h)

Ruffle's reference is `apply_standard_mask_and_scroll`
(`~/CC/ruffle/core/src/display_object.rs:1166-1275`), called from
`render_with_options` **after** `transform_stack.push(this.transform())`
(`:957-959`), i.e. the clip rect lives in the object's own local space:

1. `scroll_rect_matrix = <this object's world matrix> * scale(w_px, h_px)` — a
   box at **local (0,0)**, size = the rect's **width/height**, *not* at
   `(x_min, y_min)`.
2. push `translate(-x_min, -y_min)` for **all** content (self + `DisplayObject.mask` + children).
3. `push_mask` → `draw_rect(WHITE, scroll_rect_matrix)` → `activate_mask` → draw →
   `deactivate_mask` → `draw_rect` again (stencil reset) → `pop_mask`.

Port, in `avm2_render_node`:

```c
// after `Mat world = mat_mul(parent_world, &local);`
int clipped = 0; uint32_t clip_xid = 0;
Mat content = world;
if (ext->has_scroll_rect) {
    float m16[16]; avm2_world_to_mat16(&world, m16);
    if (g_avm2_xform_next < context->xform_slot_count) {
        clip_xid = g_avm2_xform_next++;
        renderer_write_transform(context, clip_xid, m16);
        renderer_begin_clip_mask(context);
        renderer_draw_rect(context, 0.0f, 0.0f,
            (float)(ext->sr_xmax - ext->sr_xmin),
            (float)(ext->sr_ymax - ext->sr_ymin), 1,1,1,1, clip_xid, 0);
        renderer_end_clip_mask(context);
        clipped = 1;
    }
    Mat t = mat_translate(-(double)ext->sr_xmin, -(double)ext->sr_ymin);
    content = mat_mul(&world, &t);
}
/* ... every existing use of `world` below becomes `content` ... */
if (clipped) renderer_end_clip(context);
```

Reference pattern for the three renderer calls, already in the tree:
`SWFModernRuntime/src/libswf/tag.c:4729-4733` (the EditText field clip) — the
identical `begin_clip_mask → draw_rect → end_clip_mask` triple.
`render_webgpu_draw_rect` (`render_webgpu.c:2041-2083`) issues through
`render_webgpu_draw_shape`, i.e. it inherits whatever pipeline is bound, which is
why it works as stencil geometry.

**Use a stencil rect, NOT a scissor.** `avm2/displayobject_scrollrect` sets
`circle.transform.matrix = new Matrix(1.3, 0.2, 0.1, 1.2, 40, 50)` — a skewed
world matrix whose scrollRect window is not axis-aligned on screen. Scissor is
wrong there. (`renderer_set_scissor` does not exist anyway.)

**Single nesting level only.** The stencil is one global `ref = 1` region
(`render_webgpu.c:2531-2551`, pipelines at `:1430-1461`), cleared once per pass
(`:1917-1923`), and `end_clip` unconditionally restores `render_pipeline`. That
is `wave1-gfx-masks.md` defect A, unfixed. **The AVM2 walk currently has zero
stencil users**, so a scrollRect clip is safe as long as at most one is active —
which is true for every AVM2 scrollRect test in the corpus. Wave 2 should keep a
depth counter and *skip* an inner clip rather than corrupt the outer one, and say
so in a comment.

**Twins to keep in lockstep** (same rule the session-10 button arm established):
`avm2_cpu_walk` (`avm2_display.c:13976`, `AVM2_CPU_DUMP` only) and the
`BitmapData.draw` walk (`avm2_bitmap.c:2182` region). Ruffle applies
scrollRect in `render_base`, which both of those correspond to. Neither is
graded by default; a comment noting the deferral is acceptable.

`bounds_with_transform:722-731` already overrides bounds with the scrollRect —
**do not touch it**; that is why the trace half of this test passes today.

### 2.4 Predicted flips: **ZERO**. This is the go/no-go.

I simulated a perfect fix by taking our own CI-identical render, translating it
by `(+10,+10)`, and cropping to stage `[22,122)²` (the clip window is on integer
pixel boundaries, so 4× MSAA introduces nothing new at the clip edge):

```
simulated perfect clip vs golden: 32 differing px / 96 differing channels, max diff 128
all 32 are arc-edge AA:  ours (64,179,217)/(128,204,230)/(191,230,242)  vs  golden (0,153,204)/(255,255,255)
```

`max_outliers = 0` ⇒ **96 > 0 ⇒ still `fail`**. Band move 34590 → ~96 (99.7%),
into the `hairline_edge_drift` class.

Root cause, verified on both sides:

* `test.toml` → `player_options.with_renderer.quality = "low"`.
* Ruffle: `StageQuality::Low => 1` sample (`render/src/quality.rs:67`). Golden has
  **2 distinct colours** in 200×200. `avm2/displayobject_scrollrect`'s golden has
  **4** in 550×400. Neither is antialiased.
* Us: `rp_desc.multisample.count = 4` at `render_webgpu.c:1422` (plus `:3258`,
  `:3461`, `:3561`, and the MSAA textures at `:1240`/`:1258`); `quality` from
  `test.toml` is **never read by `verify_output.py`** (`grep quality` → only
  unrelated float-epsilon comments).

**Corpus-wide size of this lever** (new, cross-cutting, not this arc's to fix):

| quality | fail `<100` | `<1000` | `<10000` | `>=10000` | pass |
|---|---|---|---|---|---|
| low | 2 | 17 | 56 | 119 | 138 |
| high | 30 | 9 | 42 | 52 | 72 |

19 `quality = "low"` comparisons are already within 1000 channels; a
`-DRENDER_SAMPLE_COUNT=N` driven from `test.toml` would put
`avm2_button_scroll_rect` and `displayobject_scrollrect` into that same
winnable band. **Recommend filing "honour `player_options.quality` as the MSAA
sample count" as its own board lead.** It is the gate on this arc's pixel yield.

### 2.5 Trace yield of a scrollRect fix: 0 this wave, but there IS a real
### mechanism behind `avm2/displayobject_scrollrect`

Local `--mode=graphics --diff` on `avm2/displayobject_scrollrect` (33 lines,
`output_mismatch`) shows **two** independent defects:

1. **Integer-twips quantization** (the standing
   `ruffle-geometry-is-integer-twips` lever): we print
   `localToGlobal = (x=54.999999552965164, y=76.00000098347664)` where Ruffle
   prints `(x=55, y=76)`. 6 lines. Not this arc.
2. **scrollRect is not in the local↔global transform at all.** Ruffle's
   `local_to_global_matrix_without_own_scroll_rect` / `:1508-1511` folds
   `translate(-x_min,-y_min)` into the chain, and `scroll_rect` is only
   *published* at `pre_render` (`display_object.rs:2429-2430`: `scroll_rect =
   has_scroll_rect.then(next_scroll_rect)`), which is why the expected output's
   "After 50ms delay" block reports **different** localToGlobal values
   (`(x=-16,y=-6)` vs `(x=55,y=76)`) and a different `concatenatedMatrix`
   (`tx=54,ty=64` vs `tx=125,ty=146`). We report the pre-scroll values in both
   blocks — 6 more lines.

A flip needs both, so this test is **not** a one-agent trace win either. Worth
recording: the two-phase `next_scroll_rect → scroll_rect` publish at pre-render
is a semantic we do not model at all.

### 2.6 Risk + canary set (if wave 2 takes it for correctness anyway)

* Regression surface is **thin**: the clip is gated on `ext->has_scroll_rect`,
  which only the setter writes. I scanned every `test.swf` in the corpus for the
  literal `scrollRect` (42 hits) and cross-referenced the image board: the only
  **passing** AVM2 comparisons among them (`bitmap_subclass_properties`,
  `bitmapdata_copychannel`, `pixelbender_effect_{smudge,tintype}`,
  `pixelbender_images`, `regression/avm2_timeline_{gradients,stroke_gradient}`)
  carry the string in a constant pool without ever setting one. **`avm2/blend_scroll`
  is `BitmapData.scroll`, not `scrollRect`** (`Test.as` read) — a name trap.
* Must-be-md5-IDENTICAL canary: `avm2/blend_scroll`, `avm2/bitmap_subclass_properties`,
  `avm2/bitmapdata_copychannel`, `avm2/pixelbender_images`,
  `regression/avm2_timeline_gradients`, `regression/avm2_timeline_stroke_gradient`,
  `from_shumway/button1` (4 cmp), `visual/focus_highlight/focus_highlight_avm2_button_bounds`,
  plus the standing `render_canary_tests.txt`.
* Expected-to-DIFFER ledger: `visual/avm2_button_scroll_rect` (34590 → ~96, still
  fail), `avm2/displayobject_scrollrect` (203367 → smaller, still fail).
* Trace canary: `avm2/displayobject_scrollrect` (must stay `output_mismatch`, not
  regress), `avm2/button_bounds`, `avm2/button_hittest`,
  `avm2/edittext_autosize_lazy_bounds_props`, `avm2/stage_properties2`,
  `regression/avm2_simplebutton_click`.

---

## 3. Target 2 — `from_shumway/button2` ×3 — **REFUTED and rediagnosed. GO.**

### 3.1 What the test actually is

`test.swf` tag histogram: `FileAttributes, Metadata, SetBackgroundColor,
DefineSceneAndFrameLabelData, DefineShape ×3, DefineSprite, PlaceObject2, DoABC,
SymbolClass, ShowFrame, End`. **No `DefineButton2`. No SimpleButton.** Session
10 called it "Sprite + MouseEvent, different owner" and left it; the actual
owner is narrower and much cheaper than that implies.

The whole script (`RecompiledABC/abc0_methods.c`, methods 1 and 2):

```as3
btn2.buttonMode = true;
btn2.stop();
btn2.addEventListener(MouseEvent.CLICK, function (e) { trace("Button clicked"); });
```

and `RecompiledTags/tagMain.c:62-66`:

```c
FrameLabelEntry sprite_4_frame_labels[] = { { "_over", 1 }, { "_down", 2 }, { "_up", 0 } };
```

This is the **MovieClip-as-button** pattern: a MovieClip with `buttonMode` and
`_up`/`_over`/`_down` frame labels auto-navigates on mouse state changes.

Ruffle implements it in `MovieClip::event_dispatch`
(`~/CC/ruffle/core/src/display_object/movie_clip.rs:2908-2925`):

```rust
let frame_name = match event {
    RollOut | ReleaseOutside      => Some("_up"),
    RollOver | Release | DragOut  => Some("_over"),
    Press | DragOver              => Some("_down"),
    _ => None,
};
if let Some(n) = frame_name
   && let Some(f) = self.frame_label_to_number(n, context)
   && self.is_button_mode(context)          // :2299
{ self.goto_frame(context, f, true); }      // stop = true
```

Note the table is **not** the same as `Avm2Button`'s: MovieClip has **no
`MouseUpInside` entry**.

### 3.2 The drop point

`button_mode` is stored (`include/avm2/avm2_globals.h:534`), settable
(`avm2_display.c:12014-12024`), and consumed **only** by mouse-pick / tab-focus
defaults (`avm2_display.c:12637`, `:12736`). **No code anywhere maps a mouse
state onto a frame label.** `grep '_over'` over `SWFModernRuntime/src/avm2/`:
zero hits.

Session 10's `button_clip_state` (`avm2_display.c:10545-10551`) is the exact
hook — it early-returns on anything that is not a `SimpleButton`
(`class_is_a(obj->cls, ctx->builtins.simple_button_class)`), so a MovieClip falls
straight through. Its six call sites in `update_mouse_state` are already in
Ruffle's order and already cover every needed transition
(`:12248` DragOut, `:12250` DragOver, `:12254` RollOut, `:12259` RollOver,
`:12300`-ish Press, `:12325`-ish MouseUpInside, and Release below it).

### 3.3 Proof it is *only* a state swap

Local render of all four frames, byte-identical to the CI actuals on
`origin/ruffle-image-results` (md5 `7f5644f7` for 2/3/4):

| frame | ours | golden |
|---|---|---|
| 1 | white 172183 + `#000099` 47817 | same → **pass** |
| 2 | white 172183 + `#000099` 47817 | white 172183 + `#00FF66` 47817 |
| 3 | white 172183 + `#000099` 47817 | white 172183 + `#FF0066` 47817 |
| 4 | white 172183 + `#000099` 47817 | white 172183 + `#00FF66` 47817 |

**Identical silhouettes, identical pixel counts, two colours each, zero AA.** The
only difference is the fill colour of the three per-frame `DefineShape`s. Get the
goto right and the comparison is byte-exact. `95634 = 47817 × 2` on frames 2 and
4 (`#000099` → `#00FF66` moves G and B) and on frame 3 (`#000099` → `#FF0066`
moves R and B) — exact, both ways.

### 3.4 Fix sketch (runtime-only, ~30-40 lines, one agent, ~1 h)

All in `SWFModernRuntime/src/avm2/avm2_display.c`:

1. `static int label_to_frame_cstr(Avm2DisplayObjectExt*, const char*)` — a
   `const char*` twin of `label_to_frame` (`:6930-6942`), which today only takes
   an `Avm2String*`. Five lines.
2. Extend `button_clip_state` (`:10545`) — rename it or add a sibling
   `mc_button_frame_state`:
   ```c
   if (class_is_a(obj->cls, ctx->builtins.simple_button_class)) { button_set_state(ctx, obj, st); return; }
   if (!class_is_a(obj->cls, ctx->builtins.movieclip_class)) return;
   Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, obj);
   if (e == NULL || !e->button_mode) return;                 // Ruffle is_button_mode
   const char* lbl = st == BTN_ST_UP ? "_up" : st == BTN_ST_OVER ? "_over" : "_down";
   int f = label_to_frame_cstr(e, lbl);
   if (f > 0) mc_goto_frame(ctx, obj, (uint16_t) f, /*stop=*/1);   // :2944
   ```
3. **The one place the tables diverge:** the `MouseUpInside → Up` call site
   (`avm2_display.c` release path, the `if (button == 0 && over != NULL)
   button_clip_state(ctx, over, BTN_ST_UP);` line) must **not** reach the
   MovieClip arm — Ruffle's MovieClip table has no `MouseUpInside` row. Leaving it
   in would fire a spurious `_up` goto (and its frame scripts) between Press and
   Release. Pass a flag, or add a `button_clip_state_btn_only()` for that one site.

Ruffle's `is_button_mode` also returns true for AVM1 clips carrying button
handlers (`movie_clip.rs:2300-2320`); for AVM2 content only `forced_button_mode`
(= `buttonMode`) can be true, so `e->button_mode` alone is the faithful port.

**Timing is already right** — I checked, because an off-by-one tick would turn
+3 into 0:
* `avm2_input_pump_tick` (`:12592`) runs at the **tail** of
  `avm2_display_run_tick` (`:3517`), after frame scripts; `avm2_render_frame`
  runs after that. So an event delivered on tick *N* is visible in tick *N*'s
  capture.
* `input.json` is `Wait, MouseMove(250,200), Wait, MouseDown, Wait, MouseUp` and
  the pump consumes exactly one WAIT group per tick ⇒ t1 `_up` (passes today),
  t2 `_over`, t3 `_down`, t4 MouseUpInside(skipped)+Release→`_over`. Matches all
  three goldens.
* `mc_goto_frame` only defers into `queued_goto_frame` when
  `ext->executing_frame_script` (`:2959`); during the input pump that is 0, so
  `run_goto` executes inline. Good.
* `avm2_input_load(argv[1])` is wired for AVM2 (`wasm_wrappers/main.c:198-201`) —
  the harness **does** replay `input.json` in graphics mode. (The trace
  `Button clicked` passing today already proved MouseDown/MouseUp arrive; this
  confirms the same for MouseMove.)

### 3.5 Predicted flips, risk, canary

* **+3 image comparisons**: `from_shumway/button2` `output.2`, `.3`, `.4`.
  Confidence **high** — exact arithmetic above, no AA anywhere in the test.
* **Trace: 0.** `button2`'s trace already passes and the change adds no trace.
* **Regression surface is essentially nil.** I scanned every `test.swf` in the
  corpus for a NUL-terminated `_over`/`_down` **frame label**: **exactly one hit,
  `from_shumway/button2`.** The goto cannot fire anywhere else, because it
  requires both `buttonMode` and a matching label. The loose substring scan finds
  six more SWFs (`avm2/mouse_over_while_dragging`, `visual/definefont4`,
  `from_shumway/slider_component`, `from_shumway/esc`,
  `avm2/bitmapdata_copypixels_blend_over`, `avm2/stage3d_ignore_sampler_override`) —
  three of them do set `buttonMode`, none has the labels. Put those three in the
  canary anyway.
* Render canary (md5 equality): `from_shumway/button2` (4 cmp, **expect 3
  DIFFER, `output.1` IDENTICAL**), `from_shumway/button1` (4 cmp, IDENTICAL),
  `from_shumway/button3` (4 cmp, AVM1, IDENTICAL), `from_shumway/slider_component`,
  `visual/definefont4`, `avm2/mouse_over_while_dragging`,
  `visual/focus_highlight/focus_highlight_avm2_button_bounds`, plus the standing
  `render_canary_tests.txt`.
* Trace canary (`--mode=graphics --diff`): the 20-test button set from
  `w2-button-report.md` §5 — the `avm2/simplebutton_*` family,
  `avm2/mouse_pick_button_mode`, `avm2/button_bounds`, `avm2/button_hittest`,
  `timeline/swf_9_frame_script_button_order` (`ruffle_matched` at baseline —
  read the trap), and **`regression/avm2_simplebutton_click`**. Plus
  `from_shumway/button2` itself.

---

## 4. Target 3 — `from_shumway/bitmapbuttons` — DEFER, and it is not a button bug

### 4.1 What is actually missing

Our render is a **blank white 590×350 stage** (204740 white + 1752 `(254,254,253)`
+ 8 `(254,254,254)` — 3 distinct colours). The golden is a full photographic UI
with **1817 distinct colours**. This is not "bitmap fills in button states"; the
entire scene — background photo, chrome, everything — is missing.

`RecompiledABC/abc_timeline.c:87-99`, `Avm2ShapeGeom` =
`{char_id, renderable, vert_offset, vert_count, morph_end_offset, is_morph}`:

```
{ 2, 0, ...} { 6, 0, ...} { 7, 1, ...} { 10, 1, ...} { 13, 0, ...}
{ 15, 0, ...} { 18, 0, ...} { 20, 0, ...} { 23, 0, ...} { 26, 0, ...}
```

**8 of 10 shapes carry `renderable = 0`.**

### 4.2 Two independent blockers (both CONFIRMED)

**Blocker A — the recompiler's AVM2 render gate.**
`SWFRecomp/src/swf.cpp:9245-9251`: `if (fs.type >= FILL_BITMAP_REPEAT &&
!tris.empty()) shape_renderable = false;`, written into `geom.renderable`
(`:9339`, `:9358`). The runtime honours it in `resolve_shape_geom`
(`avm2_display.c:451-467`, comment at `:450`: *"bitmap-fill shapes stay
deferred"*), zeroing `shape_vert_offset/count` so `avm2_render_shape` returns
immediately. **Lifting this is a recompiler change** ⇒ cmake rebuild +
`--recompile` for every downstream agent.

**Refutation worth recording:** the *machinery* for static bitmap fills is
complete and shared with AVM1, contrary to the gate's "needs a static bitmap
atlas; a later tranche" comment. The recompiler packs
`fill_styles[i].index = ((current_uninv & 0xFFFF) << 16) | char_id_to_bitmap_id[char_id]`
(`swf.cpp:7062` and `:7458`) into the vertex's `style.y`, and the WGSL vertex
stage decodes exactly that — `inv_mats[style_upper]`, `bitmap_sizes[v_style_id]`
(`render_webgpu.c:120-124`) — with fragment branches for 0x40/0x42 (repeat) and
0x41/0x43 (clipped) at `:246-250`. `avm2_render_shape` (`avm2_display.c:14284-14306`)
draws through the *same* static `renderer_draw_shape` path AVM1 uses, and
`avm2_render_init` already forwards `uninv_mat_data` and `bitmap_data`
(`:14950-14973`). The AVM1 side proves it works end-to-end:
`from_shumway/acid/acid-bitmap-fill-2` **passes**.

**Blocker B — the AVM2 runtime never uploads the static bitmap layers.**
`renderer_upload_bitmap` / `renderer_finalize_bitmaps` have exactly **one**
caller each: `defineBitmap` / `finalizeBitmaps` in
`SWFModernRuntime/src/libswf/tag.c:11683-11692`. Those are called only from the
generated `tagInit()` (`RecompiledTags/tagMain.c:449-473` for this test — 12
`defineBitmap` calls), and `tagInit` is invoked only from `swf.c:1689` and
`swf_core.c:882`. **`runSWF_avm2` (`avm2_main.c:387`) never calls it.** The
in-code comment at `avm2_display.c:14965` — *"AVM2 has no static bitmaps
(BITMAP_COUNT 0)"* — is **stale**: `constants.h` for this test says
`BITMAP_COUNT 12`, `BITMAP_HIGHEST_W 680`, `BITMAP_HIGHEST_H 400`, and
`app_context.bitmap_count = BITMAP_COUNT` is set unconditionally in
`wasm_wrappers/main.c:163`. The texture array is therefore *allocated* with 12
static layers that are never written.

`avm2_generated_bitmaps` (12 entries) exists but is a **different encoding**
(zlib'd straight RGBA for `BitmapData` symbol seeding, `avm2_abc.h:488-501`) with
no offset into the `bitmap_data` blob, so it cannot drive
`renderer_upload_bitmap` as-is. The clean fix is a small recompiler emission —
either a `tagInitBitmaps()` split out of `tagInit`, or a static-bitmap table
(`offset,size,w,h`) in `avm2_movie_tables` — uploaded from `avm2_render_init`
**in the same order** `tagInit` emits, because `render_webgpu_upload_bitmap`
allocates layers with a sequential `ctx->current_bitmap++`
(`render_webgpu.c:2793`) and that index is what the recompiler baked into
`style.y`.

### 4.3 Verdict

**DEFER.** Two blockers, one in the recompiler and one needing a new emission,
and even then the flip is unlikely: `tolerance = 4` with **`max_outliers = 0`**
against a JPEG photograph (`DefineBitsJPEG3`, a 680×400 source composited into a
590×350 stage, i.e. resampled). Every bilinear/decode difference against Ruffle
costs an outlier and the budget is zero. The comparable AVM1 test that passes,
`acid/acid-bitmap-fill-2`, is allowed **8689** outliers.

Name it as a tranche — **"AVM2 static bitmap fills"** — worth doing for the
mechanism (it is the blocker on `from_shumway/acid/acid-image`,
`acid/acid-color` ×2, `acid/acid-big` and any AVM2 game content with library
bitmaps), not for this comparison's flip. If it is taken, measure with a
generous-tolerance AVM2 target first, not `bitmapbuttons`.

---

## 5. Recommendation to the coordinator

| # | item | wave-2 slot | expected board move |
|---|---|---|---|
| 1 | **`button2` MovieClip `_up/_over/_down` + `buttonMode`** | **yes — 1 agent, ~1 h, runtime-only** | **pixels +3**, trace 0, regressions 0 |
| 2 | AVM2 scrollRect clip + scroll translation | optional, 1 agent, ~1.5 h, runtime-only | pixels **+0** (34590 → ~96; 203367 → smaller), trace 0. Correctness + band move only |
| 3 | Honour `player_options.quality` as MSAA sample count | **new board lead**, not this arc | gates item 2 and ~19 other `quality=low` near-passes |
| 4 | AVM2 static bitmap fills (recompiler + upload) | defer / name as tranche | `bitmapbuttons` unlikely to flip; unblocks the acid bitmap family |

Item 1 alone is a clean, isolated +3 with a one-SWF blast radius. Items 2 and 4
should not be scored as pixel yield.

**CI**: everything above is invisible under the standing `images=false` default —
any run meant to observe this arc needs `mode=graphics`, `categories=all`,
**`images=true`**.

**Worktree note** (session-10 trap, still live): a wave-2 agent copying test dirs
into its worktree must pass `--recompile` on first use, or a `RecompiledABC`
copied mid-write reads as `compile_fail` even sequentially. `button2` in
particular had **no** `RecompiledABC` in the main tree before this session; it
does now (generated by my read-only runs, all gitignored).
