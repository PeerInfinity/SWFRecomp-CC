# w2-gfx-scrollRect — AVM1 `MovieClip.scrollRect` (PIXEL axis)

Session 14, wave 2. Implementation of
`SWFRecompDocs/plans/session14-fanout-reports/wave1-gfx-scrollrect.md`.

| | |
|---|---|
| worktree | `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a15d94b793e85ae2c` |
| baseline | `0a99be1a9` (patch left uncommitted in the worktree) |
| patch | `wave2/w2-gfx-scrollrect.patch` — runtime only, 3 files, +331 lines |
| files edited | `SWFModernRuntime/include/actionmodern/action.h`<br>`SWFModernRuntime/src/actionmodern/action.c`<br>`SWFModernRuntime/src/libswf/tag.c` |
| headline | **+1 flip** (`visual/cache_as_bitmap/scroll_rect_scaled`), 2 large band moves, **zero canary movement anywhere else** |
| brief verdict | GO — implemented as specified, with **one refutation** (§4.1) and one hardening (§4.4) |

`render_webgpu.c` / `.h` **untouched** — no new pipeline, so the
`MSAA_SAMPLES`-never-literal-4 invariant is trivially preserved.
`avm2_display.c` / `avm2_globals.c` / `avm2_class.*` untouched. `SWFRecomp/`
(recompiler) untouched — the patch needs no `--recompile` to take effect.

Only the **public clip API** is used (`renderer_clip_ref` /
`renderer_begin_clip_mask` / `renderer_end_clip_mask` /
`renderer_restore_clip`) — no raw stencil refs — so this is insulated from
`gfx-stencil`'s `mask_ref` → `num_masks` semantic change. The two tag.c edit
sites are exactly the two the brief named (`compose_children` right after
`hit_test_mat4_multiply`, and `render_display_list` right after the setMask
push), and neither is at `3533` / `5833` / `6794`.

---

## 1. Ledger — expected CI movement

Absolute channel counts, graded against the mirrored goldens with the native
`--mode=graphics` build (`~/CC/dawn-install`). **The before leg reproduced CI's
published baseline numbers exactly** (18378 / 41846@tol-64 / 11310), which is
the strongest available confirmation of the brief's md5-identity finding.

| comparison | before | after | budget | brief predicted | verdict |
|---|---:|---:|---|---:|---|
| `visual/cache_as_bitmap/scroll_rect_scaled [output]` | 41846 (excess 40946) | **2322** | 2800 @ tol 0 | 1100–2400 | **FLIP → pass** |
| `visual/simple_shapes/scroll_rect_mask [output]` | 11310 | **42** | 0 @ tol 0 | 42 | band **−99.6 %**, not a flip |
| `visual/cache_as_bitmap/scroll_rect [output]` | 18378 | **2056** | 0 @ tol 1 | ~1478 | band **−88.8 %**, not a flip |

**Net predicted flips at CI: +1.** No comparison anywhere worsened.

* **`scroll_rect_scaled` — the flip.** The test carries **two** checks
  (`tol 0 / max_out 2800` and `tol 64 / max_out 900`) and
  `verify_output.compare_images` passes if ANY check passes. The tol-0 check now
  passes at **2322 / 2800** = 17 % headroom. That is exactly the brief's
  *worst-case* five-way simulation ("worst case 707/2322"), so the flip is real
  but not luxurious; a lavapipe-vs-Dawn edge treatment on the 200×200 crop
  boundary is the only thing that could eat 478 channels, and the brief's own
  simulation says none of the five plausible treatments does.
* **`scroll_rect_mask` — 42, on the nose.** 21 isolated single-pixel rasteriser
  ties around the 628 px circumference at `MSAA_SAMPLES = 1`
  (`quality = "low"`). Same class as `avm2_button_scroll_rect`'s residual 9.
  Not scopeable.
* **`scroll_rect` — 2056 vs the predicted ~1478.** The brief attributed 1478 of
  it to the red `DefineShape4` frame rendering 1 px up-left of Ruffle's — a
  `cacheAsBitmap` / `PixelSnapping::Always` defect on a **sibling** of the
  scrolled clip, so structurally out of scope. The extra ~289 channels are the
  same order and the same class. Per the brief's explicit instruction, **not
  chased.** The A/B difference bbox is `(179,117)-(329,261)`, i.e. entirely the
  scrolled region plus that frame.

---

## 2. What was implemented

**`action.h`** — `has_scroll_rect` + `sr_{x,y}{min,max}` (twips) on
`struct MovieClip`, beside `maskee_mc`; `Avm1ScrollRect` +
`actionAvm1ScrollRectCount()` / `actionAvm1GetScrollRects()` declared beside the
setMask registry API.

**`action.c`** —
* a scrollRect registry mirroring the setMask registry's ownership model exactly
  (immortal `MovieClip*` only, liveness a read-time predicate, never a
  `DisplayObject*` across frames);
* `actionAvm1SetScrollRect()`, plus a **setter arm in `actionSetMember`
  immediately after `blendMode`** that returns without falling through to the
  dynamic-property store;
* a **getter arm in `actionGetMember` beside `cacheAsBitmap`** minting a fresh
  `createRectObj` per read, and *only when* `has_scroll_rect` — unset clips fall
  through so `MovieClip.prototype`'s stub answers `undefined`;
* the `extra_props[10]` prototype stub is **untouched**, as required.

**`tag.c`** —
* per-frame `g_scroll_crops[64]` side table (entry → crop transform slot + crop
  size), cleared inside `xform_overrides_reset()` — which is called at exactly
  the two places `g_next_dynamic_xform_slot` is reset, so a recorded slot can
  never outlive its pool. Overwrites rather than appends when an entry is
  composed twice in one frame;
* **the translate**, in `compose_children` immediately after
  `hit_test_mat4_multiply(composed, parent_composed, local_xform)` and *before*
  the dynamic-slot allocation, so the entry's own slot **and** the
  `parent_composed` handed to the SPRITE/BUTTON recursions both carry the shift.
  **Unconditional** — no mask-capture gate;
* **the crop**, in `render_display_list` right after the setMask stencil push:
  `renderer_clip_ref` → `begin_clip_mask` → `renderer_draw_rect(0,0,w,h)` →
  `end_clip_mask`, gated on `!g_clip_mask_capture`, restored with
  `renderer_restore_clip` (never `end_clip`) *before* the setMask restore.

### 2.1 Why suppressing the crop is what moves `scroll_rect_mask`

Confirmed at the source, and confirmed by the measurement.
`draw_mc_mask_geometry` (`tag.c:5669`) increments `g_clip_mask_capture` around
`render_display_list(md->sprite_display_list, …)`, so `mask.circle`'s entry
reaches the crop site *inside* a capture and the crop is skipped — while its
translate, applied at compose time, is already baked into its `transform_id`.
Silhouette = whole 200 px disc shifted by exactly (−10,−10). That is the golden.
Ruffle's mechanism is `RenderContext::maskers_in_progress`
(`render/commands.rs:47`): `push_mask` emits nothing at nesting depth > 0 and the
`draw_rect` command is discarded, but the transform-stack push is not a command
and survives.

---

## 3. Canary results — clean

### 3.1 Render canary (md5 bar)

`ruffle-tests/render_canary.py compare before after` — the full standing
`render_canary_tests.txt` (incl. `regression/` ×3, `avm1/movieclip_setmask`,
`avm1/mask_with_drawing`) **plus the 8 named mask/scrollRect traps and the 3
targets**: 31 tests / 54 comparisons.

```
  IDENTICAL    51
  DIFFERS       3
  APPEARED      0   VANISHED 0   NO_RENDER 0

  DIFFERS:
    visual/cache_as_bitmap/scroll_rect         image fail -> fail   trace pass -> pass
    visual/cache_as_bitmap/scroll_rect_scaled  image fail -> PASS   trace pass -> pass
    visual/simple_shapes/scroll_rect_mask      image fail -> fail   trace pass -> pass

  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: scroll_rect_scaled  fail -> pass
```

**The three DIFFERS are exactly this patch's ledger. Nothing else moved a byte.**

The 8 named traps, absolute numbers before → after (all md5-IDENTICAL):

| trap | before | after |
|---|---:|---:|
| `avm2/displayobject_scrollrect [output]` | 12382 | **12382** |
| `visual/avm2_button_scroll_rect [output]` | 9 | **9** |
| `visual/simple_shapes/text_field_mask [output]` | 56 | **56** |
| `visual/cache_as_bitmap/masks [output.01–.07]` | 1690/2701/2170/1777/1769/709/pass | **unchanged** |
| `from_shumway/acid/acid-clip-2 [output]` | pass 2831/3000 | **pass** |
| `from_shumway/invalidClipDepth [output]` | pass 0 | **pass** |
| `visual/simple_shapes/masks [output]` | 2624 | **2624** |
| `visual/simple_shapes/masks_equal_clipdepth [output]` | 2624 | **2624** |

`regression/{avm2_timeline_stroke_gradient, avm2_timeline_gradients,
mask_sibling_union}` all IDENTICAL; `regression/mask_sibling_union` still exact
at tol 0. Full 86-row table: `wave2/canary_table.txt`; JSON:
`wave2/canary_compare.json`.

### 3.2 Trace canaries (the AS-visible surface the new accessors add)

Run with the **default NO_GRAPHICS build** — which doubles as the second-mode
compile check for the shared `action.c` code, per CLAUDE.md's "when in doubt run
both".

| test | result | brief baseline (matching lines) |
|---|---|---|
| `avm1/movieclip_default_state` | pass **69/69** | pass 69 ✓ |
| `avm1/movieclip_library_state_values` | ruffle_matched **76**/78 | ruffle_matched 76 ✓ |
| `avm1/movieclip_state_values` | pass **114/114** | pass 114 ✓ |
| `avm1/movieclip_setmask` | pass **14/14** | pass 14 ✓ |
| `from_gnash/…/MovieClip-v5` | ruffle_matched **339**/363 | 339 ✓ |
| `from_gnash/…/MovieClip-v6` | output_mismatch **901**/936 | 901 ✓ |
| `from_gnash/…/MovieClip-v7` | output_mismatch **934**/969 | 934 ✓ |
| `from_gnash/…/MovieClip-v8` | output_mismatch **1020**/1087 | 1020 ✓ |

Every `matching_lines` is identical to the brief's documented baseline. The
`expected_lines` denominators differ from the brief's transcription (363 vs 350
etc.); those come from the per-FP-version `output.fp*.txt` variant the runner
selects and cannot be moved by a runtime change — treat the brief's denominators
as a transcription artefact, not a movement.

`MovieClip-v6` first reported **`compile_fail`** in the 4-test batch and came
back `output_mismatch 901/936` on a sequential re-run — the standing
"long-compile failure under load is FALSE" lesson, reproduced.

The remaining 4 of the 7 corpus AVM1 scrollRect users are exactly
`movieclip_default_state` / `movieclip_library_state_values` /
`movieclip_state_values` / `MovieClip-v5..v8` above — **all proved unchanged**.
Grep of their expected outputs confirms the only scrollRect surface any of them
touches is `scrollRect = undefined` (×2) and
`PASSED: MovieClip.prototype.hasOwnProperty("scrollRect")` (×1) — the prototype
stub this patch deliberately does not touch.

---

## 4. Deviations from the brief

### 4.1 REFUTATION — the AVM1 rounding rule is TRUNCATION, not half-to-even

The brief (§5.1 B) says to copy `avm2_display.c:10304`'s `round_half_to_even`
and calls it "load-bearing — `scroll_rect`'s height arrives as 143.95 and must
become 144 twip-pixels, and the golden's 94 px visible band depends on it."

**Both halves are wrong.** Ruffle's *AVM1* `object_to_rectangle`
(`core/src/avm1/globals/movie_clip.rs:148`):

```rust
*value = match object.get_local_stored(name, activation) {
    Some(value) => value.coerce_to_i32(activation)?,   // ES ToInt32 — TRUNCATES
    None => return Ok(None),
}
...
x_max: Twips::from_pixels_i32(x + width),              // i32 + i32, AFTER coercion
```

`coerce_to_i32` is ES `ToInt32` — truncation toward zero — so 143.95 → **143**,
and `x_max` / `y_max` are formed in integer space *after* coercion. The
half-to-even rule in `avm2_display.c` is correct **for AVM2**, whose
`object_to_rectangle` (`display_object.rs:907`) is a genuinely different
function. The two VMs disagree; the patch implements the AVM1 rule and carries a
comment saying so.

It is also **not load-bearing**: after the (−100,−50) translate `a`'s content
ends at local y = 93.95, so a crop height of 143 or 144 is equally non-binding,
and the golden's 94 px band is set by the content edge, not the crop. Measured
result is 2056 either way.

### 4.2 `Value::Object` narrowed to `ACTION_STACK_VALUE_OBJECT`

Ruffle sets `has_scroll_rect` for *any* `Value::Object`, which in AVM1 includes
arrays, functions and movieclips — and then, since `get_local_stored("x")`
misses, leaves the rect unchanged. For a never-before-set clip that means
`has_scroll_rect = 1` with a 0×0 rect, i.e. **the whole subtree disappears**. No
corpus test does this and the failure mode is catastrophic rather than cosmetic,
so the patch accepts only `ACTION_STACK_VALUE_OBJECT`. Documented in-code.

### 4.3 Field reads go through the prototype

Ruffle uses `get_local_stored` (own properties only); the patch uses
`getPropertyWithPrototype`, matching every other Rectangle consumer in
`action.c` (e.g. `rectangleToString`). Strictly more permissive; unobservable
for any Rectangle built by `new flash.geom.Rectangle(...)`.

### 4.4 HARDENING — no crop when the transform pool is exhausted

The brief's sketch (and s13's AVM2 `avm2_push_scroll_rect_mask`) fall back to
transform slot **0** when the dynamic pool runs out. Slot 0 is identity, so the
crop quad would land as a `(0,0)-(w,h)`-**twips** box at the stage origin — a
~5×5 px window that blanks the entry. The patch instead records **no crop** in
that case: the translate still applies and the entry renders uncropped. A
missing crop is a far smaller error than a crop in the wrong place. Same
treatment for `g_scroll_crops[]` overflow past 64.

### 4.5 Scope held to `render_display_list`, per brief §J

The two root loops (`tagRerenderFrame`, `tagShowFrame`), `render_attached_child`
and `render_single_object` were **not** mirrored. They would only matter for a
*root-placed* or *attached* clip carrying a scrollRect, which no corpus test
has. Note the resulting symmetry: such a clip gets no translate either (root
entries are not composed by `compose_children`), so it stays exactly as inert as
it is today rather than becoming half-applied.

---

## 5. Latent AVM2 divergence (recorded, not fixed)

Re-confirmed the brief's §4.1 finding: `avm2_display.c:15547` gates the scroll
**translate** on `g_avm2_mask_capture == 0` along with the crop, while Ruffle
gates only the crop. An AVM2 scrollRect'd object inside a mask therefore renders
its silhouette unshifted. One line (move `world = mat_mul(&world, &sr_tr)`
outside the guard); no test covers it; **not touched** — `avm2_display.c` is
outside this agent's scope and would collide with the sibling agents.

---

## 6. Merge / CI guidance

* Apply `wave2/w2-gfx-scrollrect.patch` (3 files, all runtime). It does **not**
  conflict with `gfx-stencil` on `render_webgpu.c`; the two `tag.c` hunks are at
  `compose_children` ~2941 and `render_display_list` ~3705, away from
  `3533/5833/6794`. If `gfx-stencil` changes the *meaning* of nested
  `begin/end_clip_mask` pairs, re-check `scroll_rect_scaled`'s 2322 — it is the
  only number in this ledger with a budget to lose.
* Dispatch `mode=graphics`, `categories=all`, `images=true` for the closeout
  run. The `action.c` half is mode-shared, and the NO_GRAPHICS build was
  compiled and exercised locally (§3.2), so the weekly canary covers that mode.
* No new ACCEPTED_DIFFS / RUFFLE_VS_FLASH / COMPAT_TWEAKS entries are warranted:
  both remaining band residuals are attributed to *other*, already-named
  mechanisms (one-sample rasteriser ties; `PixelSnapping::Always`), not to
  permanent divergences of this feature.

### Artefacts

| | |
|---|---|
| patch | `wave2/w2-gfx-scrollrect.patch` |
| canary compare | `wave2/canary_compare.json`, `wave2/canary_table.txt` |
| capture legs | `.render_canary/before`, `.render_canary/after` (+ `_compare/before__after`) |
| trace canaries | `wave2/trace/avm1_after.json`, `wave2/trace/gnash_after.json`, `wave2/trace/gnash_v6_after.json` |
| per-target grades | `wave2/grades/after/*.json` |
