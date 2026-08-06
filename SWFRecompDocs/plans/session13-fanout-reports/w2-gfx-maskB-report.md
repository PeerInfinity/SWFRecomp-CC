# wave-2 `gfx-maskB` — AVM1 `setMask` for timeline content (mask defect B)

Session 13, wave 2, **IMPLEMENTATION**. Runtime-only change, delivered as a
patch — **nothing was committed anywhere**. Worked in the isolated worktree
`.claude/worktrees/agent-a8a4f9a6a822f964f` (base `10931d62e`); the main repo's
`SWFRecomp/build` was copied in (legal — no `SWFRecomp/src/` file was touched).
All test dirs were `cp -r`'d into the worktree's canonical suite paths and
`--recompile`d on first use; `--tests-dir` never pointed at the main repo.
Local Dawn at `~/CC/dawn-install`.

Design implemented: `SWFRecompDocs/plans/session13-fanout-reports/wave1-gfx-maskB.md`,
**Phase 1 in full plus the §3.7 rider**. Phase 2 (AVM1 `scrollRect` translate)
deliberately NOT implemented — §5.

Deliverables: `w2-gfx-maskB.patch`, this report.

---

## 0. Headline

| | |
|---|---|
| **`visual/simple_shapes/text_field_mask`** | **431 740 → 56** excess outlier channels (**−99.99 %**), 28 mismatching pixels, all isolated tie pixels on the `W` diagonals |
| **`visual/simple_shapes/scroll_rect_mask`** | **434 284 → 11 304** (**−97.4 %**); the mask is now the right *shape*, off by exactly the `(10,10)` scrollRect origin |
| **Flips** | **0** (both land as near-passes, exactly as wave-1 predicted) |
| **Regressions** | **0** — 65 / 67 canary comparisons md5-**IDENTICAL**, `TRACE STATUS CHANGES: (none)`, `IMAGE STATUS CHANGES: (none)` |
| **`avm1/mask_reapply` (mandatory gate)** | **still passes**: 0 outliers, 152 diff channels at `tolerance = 1` — byte-identical to its baseline, and md5-IDENTICAL in the A/B |

Wave-1's refutation holds: this is **mechanism completion + two large band moves**,
not a flip lead. It is still worth shipping — it is the whole missing `setMask`
path that every AVM1 title masking timeline content hits.

---

## 1. What changed

Three files, all runtime. `+379 / −12` lines.

| file | change |
|---|---|
| `SWFModernRuntime/include/actionmodern/action.h` | new `MovieClip.maskee_mc` + 4 accessor declarations |
| `SWFModernRuntime/src/actionmodern/action.c` | setMask pair registry (+helpers); `setMask` rewired onto it; masker skip in `actionIterateTextFields` and `actionIterateAttachedBitmaps` |
| `SWFModernRuntime/src/libswf/tag.c` | entry↔MC matchers, `avm1_mask_push`, `draw_mc_mask_geometry`; hooks in the 3 display-list loops + `render_attached_child`; EditText field-clip gated on `g_clip_mask_capture`; `end_clip` → `restore_clip(pre_clip_ref)` in `render_display_list` |

No AVM2 file is touched — zero textual overlap with the defect-C sibling
(`avm2_render_node` in `avm2_display.c`). No renderer function was added; the
patch only *calls* `renderer_clip_ref` / `renderer_restore_clip`, already
exported in both `renderer.h` arms. `render_webgpu.c` is untouched, so the
`MSAA_SAMPLES` invariant is trivially respected.

### 1.1 State — all on `MovieClip`, zero new `DisplayObject*`

`action.c` gains a 64-entry registry of `{maskee, masker}` `MovieClip*` pairs
plus a count (`actionAvm1MaskPairCount()`). `MovieClip` structs are allocated
once and never freed (dead clips are tombstoned at `depth == INT_MIN`), so a
stored `MovieClip*` can go **stale but never invalid**, and staleness is the
one-line read-time predicate `depth != INT_MIN`. The only `DisplayObject*` the
mask code touches is `mc->display_obj` — **re-read at every use, never stored**.
That is the one entry pointer `ng_spriteDLRealloc` rebases and
`scrub_mc_display_obj_in_range` NULLs.

Consequence, and the whole safety argument: sprite-DL realloc, sprite-DL free,
depth reuse, removal, rewind and re-clone need **no** invalidation hook. The
s10 sketch's `DisplayObject* as_masked_by` (the UAF this redesign exists to
avoid) does not appear anywhere.

`setMask(m)` now goes through `avm1_mask_pair()`, which clears any previous
pairing on **either** side, sets `mask_mc` / `maskee_mc` / `is_mask`, registers
the pair, and **retires `clip_depth = 0` on both entries** via `mc->display_obj`
(no-op when NULL) — Ruffle's `DisplayObject::set_mask`, matching what s12 did
for AVM2 at `avm2_display.c:4217/4229`. `setMask(null)` unpairs both ways.

**This retirement is the hard coupling wave-1 flagged**, and it is why
`avm1/mask_reapply` survives: its second call is the deliberately-backwards
`mask2.setMask(maskee2)`, where `mask2` still carried `clipDepth = 7`. Masker
suppression alone would have suppressed `maskee2` (now a masker) while `mask2`
kept acting as its own timeline stencil — one patch would have vanished.
Retiring both `clip_depth`s turns the second pair into an ordinary
mask/maskee whose intersection is the same rectangle. Verified: the test's
render is **md5-identical** before and after.

### 1.2 Paint-time hooks

Per entry, in `render_display_list`, the `tagShowFrame` loop and the
`tagRerenderFrame` loop — all three behind a single
`actionAvm1MaskPairCount() != 0` branch, so movies that never call `setMask`
pay one integer compare per entry and nothing else:

* `entry_is_live_masker(obj)` → `continue`. A masker is never painted as
  ordinary content.
* `avm1_masker_for_entry(obj)` non-NULL → this entry is a maskee; its paint is
  wrapped in `renderer_clip_ref` → `begin_clip_mask` → `draw_mc_mask_geometry`
  → `end_clip_mask` … `renderer_restore_clip`. **Restore, not `end_clip`** — the
  s12 primitive — so an enclosing clipDepth range survives.

Entry↔MC matching is MC-first: `mc->display_obj == obj`, falling back to
`obj->instance_name` vs `mc->name` when `display_obj == NULL`. The fallback is
load-bearing: in `text_field_mask` the masker is a root-placed `DefineEditText`
wrapper, which has no `display_obj` at all — the exact case that made the s10
entry-pointer design structurally unable to fix its own headline test.

Symmetric masker suppression in the four non-display-list paths:
`actionIterateTextFields` (background/border), `actionIterateAttachedBitmaps`,
`textfield_glyph_render_cb` (glyphs, keyed on the existing `info->mc`), and
`render_attached_child` — which also gets the maskee push/restore for dynamic
clips with display-list content.

### 1.3 `draw_mc_mask_geometry` — three masker kinds, one function

1. **Timeline entry** (`mc->display_obj != NULL`): shape / morph shape /
   sprite-or-button subtree through `render_display_list` under
   `g_clip_mask_capture++` — verbatim the routes the sprite clipDepth branch
   already uses.
2. **Drawing-API clip**: `actionGetMCDrawingPathsByName` + the existing
   `render_drawing_mc_paths_fill_only` (Flash masks ignore stroke).
3. **EditText wrapper**: a filtered replay of `actionIterateTextFieldGlyphs`
   (a file-static "only this MC" filter read by `textfield_glyph_render_cb`).
   Not re-entrant with the ordinary glyph pass by construction — it is only
   invoked from the display-list loops, which run before that pass.

A masker can be more than one kind; all that apply are drawn.

For (3), `textfield_glyph_render_cb`'s **field-bounds clip rect is suppressed
while `g_clip_mask_capture > 0`**. Ruffle's `EditText::render_self` bounds mask
is a *nested* mask inside a mask capture and is therefore ignored; our renderer
already no-ops the nested `begin/end_clip_mask` pair, so only the rect draw
itself needed gating. Without it the masked glyphs would still stop at `x≈192`.
The golden proves the gate is right — see §3.

### 1.4 §3.7 rider — `render_display_list` clip-range close

`renderer_end_clip` zeroes `mask_ref`; called from a walk that was *entered*
under a clip (a clipDepth range inside a clipped sprite, or inside a maskee) it
dropped the enclosing clip for everything drawn afterwards. The walk now
captures `pre_clip_ref = renderer_clip_ref(context)` at entry and restores to
that. `restore_clip(0)` is byte-identical to `end_clip`, so the ordinary
unclipped entry is provably unchanged — and the canary confirms it empirically:
`visual/simple_shapes/masks`, `masks_equal_clipdepth`, `acid-clip`,
`acid-clip-2`, `acid-mask`, `invalidClipDepth`, `clipping`, `MaskTest`,
`MaskTest-3` are all **md5-IDENTICAL**.

---

## 2. Canary results

`ruffle-tests/render_canary.py run --stash SWFModernRuntime` over the standing
set **plus** every must-not-break test wave-1 §4.2 named — **41 tests /
67 comparisons**, `-P 2`, `--recompile` on both legs, local Dawn.

```
RENDER CANARY  before=stash_before  after=stash_after   41 tests / 67 comparisons

  IDENTICAL    65
  DIFFERS       2
  APPEARED      0   VANISHED 0   NO_RENDER 0

  DIFFERS:
    visual/simple_shapes/scroll_rect_mask  output   [DIFFERS]
        diff_channels 440000/880000  mean 127.5   max 255
        image status: fail -> fail    trace: pass -> pass
    visual/simple_shapes/text_field_mask  output   [DIFFERS]
        diff_channels 431748/880000  mean 123.54  max 255
        image status: fail -> fail    trace: pass -> pass

  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

**The only two comparisons that moved are the two that were supposed to move.**

Gate-by-gate:

| gate | result |
|---|---|
| (a) `avm1/mask_reapply` green | **PASS** — md5-IDENTICAL; direct run: `0 outliers (limit 0), max difference 1`, 152 diff channels at tol 1, i.e. its exact baseline figures |
| (b) the 3 baseline-passing `setMask` pixel tests | `avm1/mask_reapply`, `avm1/movieclip_setmask`, `avm1/mask_with_drawing` — all **IDENTICAL**, all still `img pass` |
| (c) md5-identical outside the targets | **65 / 67**; the 2 exceptions are the targets |
| (d) mask-related trace unchanged | 18 mask/clip comparisons across 13 tests, all `trace pass → pass`; `from_shumway/MaskTest-3` stays `ruffle_matched → ruffle_matched` (no hidden regression on a known_failure). Plus a no-graphics run of 5 `regression/` tests — see §2.1 |

Notable IDENTICALs beyond the mask family (the EditText field-clip gate's blast
radius, which wave-1 called out as the second risk): `avm1/edittext_tag_indent`,
`visual/edittext/edittext_border_transform` (6 comparisons),
`visual/cache_as_bitmap/edittext_scroll` + `edittext_hscroll`,
`from_shumway/acid/acid-textfield-scroll`, `avm2/blend_scroll`,
`avm2/displayobject_mask`, `avm2/mask_reapply`, `regression/mask_sibling_union`.

### 2.1 No-graphics arm

`action.c` is shared between modes, so the five `regression/` trace tests
`mask_sibling_union`, `avm2_static_text`, `avm2_timeline_text`,
`mc_method_v5_caller_gate`, `onunload_type1_args` were also run in the default
NO_GRAPHICS mode — **5/5 pass**:

```
=== mask_sibling_union ===        Pass: 1 (100.0%)   Fail: 0
=== avm2_static_text ===          Pass: 1 (100.0%)   Fail: 0
=== avm2_timeline_text ===        Pass: 1 (100.0%)   Fail: 0
=== mc_method_v5_caller_gate ===  Pass: 1 (100.0%)   Fail: 0
=== onunload_type1_args ===       Pass: 1 (100.0%)   Fail: 0
```

Both `tag.c` and
`action.c` additionally pass `gcc -fsyntax-only` clean under `-DNO_GRAPHICS`
and under the browser arm (`-DUSE_WEBGPU` without `OFFSCREEN_RENDER`) — no new
warnings in either.

---

## 3. Band-move evidence

### 3.1 `visual/simple_shapes/text_field_mask` — 431 740 → 56

`clip.setMask(txt); txt.text = "WWWWWWWWWWW"`. Root `d1 = char 2` (sprite
"clip", red-left/blue-right full-stage rects), root `d3 = char 4`
(`DefineEditText` "txt"). `tolerance = 0`, `quality = "low"` → `MSAA_SAMPLES = 1`.

```
                    non-white bbox        colour histogram
before  x 3..192    (grey text on top)    blue 110000 | red 106990 | grey(51,51,51) 3010
after   x 3..549                          white 211359 | blue 4335 | red 4306
golden  x 3..549                          white 211361 | blue 4334 | red 4305
```

Both defect halves are gone: the rects are no longer unmasked (110 000 + 106 990
→ 4 335 + 4 306) and the masker is no longer painted as ordinary grey text
(3 010 grey → 0). **The masked glyphs now extend past `x = 192` all the way to
`x = 549`**, which is precisely the field-clip-suppression prediction — the
field is only ~182 px wide, so without the `g_clip_mask_capture` gate the `W`s
would still be truncated at the third glyph.

Residual: **28 mismatching pixels / 56 channels**. They are isolated single
pixels on the `W` diagonals, in both directions, repeating at the 119-px glyph
advance (`x = 10, 129, 248, 367, 486` on row 131; `33, 152, 271, 390, 509` on
row 139): the same sample-point tie once per glyph at `MSAA_SAMPLES = 1`. Wave-1
predicted "~34 px ≈ ~90 excess channels" from a 3.2-glyph sample; the measured
28 px / 56 ch is that estimate, slightly better. At
`tolerance = 0, max_outliers = 0` this is a **near-pass, not a pass**, and it
sits in the same family as s12's mask-edge residuals
(`displayobject_mask` 8, `MaskTest` 17, `mouse_pick_*_dobj_mask` 24).

### 3.2 `visual/simple_shapes/scroll_rect_mask` — 434 284 → 11 304

`mask.circle.scrollRect = new Rectangle(10,10,100,100); clip.setMask(mask)`.

```
                    non-white bbox            colour histogram
before  (0,0)-(549,399)  full stage           red 99223 | blue 89335 | green 31442
after   (200,100)-(399,299)                   white 188558 | blue 20665 | red 10777
golden  (190,90)-(389,289)                    white 188494 | blue 18746 | red 12760
```

The masker (the green circle sprite) is no longer painted, and the maskee is now
clipped to a 200 px circle of exactly the golden's size — offset by **exactly
`(+10, +10)`**, i.e. the missing `scrollRect` origin translate, and nothing else.
Total non-white 31 442 vs the golden's 31 506. Wave-1 predicted "~17 000 (circle
off by 10 px)"; measured 11 304.

Note the golden applies the scroll **translate** but not the 100×100 **crop** —
exactly as wave-1 explained: a mask pushed inside a mask capture is a no-op in
both renderers. So a future AVM1 `scrollRect` needs no special case on this path.

---

## 4. Expected CI movement

| comparison | baseline | expected after this patch |
|---|---:|---|
| `visual/simple_shapes/text_field_mask` | 431 740 | ~56 (near-pass, still `fail`) |
| `visual/simple_shapes/scroll_rect_mask` | 434 284 | ~11 300 (still `fail`) |
| everything else | — | **byte-identical** |

**Predicted flips: 0.** Predicted trace movement: 0. Predicted regressions: 0.
The pixel scoreboard stays 286/567 (50.4 %); what changes is two very large
band moves and a whole missing mechanism.

Caveat kept explicit: local Dawn ≠ CI lavapipe, so the *absolute* residuals
(56 / 11 304) are local numbers. They are credible because wave-1 measured the
baselines (431 740 / 434 284) locally **byte-exactly equal to the merged CI
values**, and because both residuals reproduce the shape wave-1 predicted from
the CI PNGs. The A/B verdict (what moved and what did not) is machine-local by
construction and is the part that gates.

---

## 5. What I did NOT do, and why

**Phase 2 — AVM1 `scrollRect` translate: not implemented.** It is the only
remaining gap on `scroll_rect_mask`, but it is not a tight, low-risk diff:
`action.c:15726`'s `extra_props[]` stub would have to become a real
getter/setter, and the MC's whole subtree transform would have to gain
`(-x, -y)`. That touches transform composition — a far wider blast radius than
this patch's stencil-only surface, and it would need its own canary sweep
(`visual/cache_as_bitmap/scroll_rect` 18 378 and `scroll_rect_scaled` 41 902 are
AVM1 and use no `setMask` at all). Per wave-1 §4.1 it is worth more as its own
lead than as a rider here. Both `scroll_rect` tests are in my canary set and are
**IDENTICAL**, so nothing about them changed either way.

**Phase 3 — masked EditText** (pushing a masker's stencil around a field that is
itself a maskee): not implemented. No corpus comparison needs it, and it is the
one shape that would make `actionIterateTextFieldGlyphs` re-entrant with itself.
The masker-side suppression in `textfield_glyph_render_cb` is implemented.

---

## 6. Merge risks / notes for the integrator

1. **The `clip_depth = 0` retirement and the masker suppression must stay
   together.** If anyone splits this patch, keeping only the suppression
   regresses `avm1/mask_reapply` (a currently-passing image comparison). They
   are both inside `avm1_mask_pair()` and should stay there.
2. **Never reintroduce a `DisplayObject*` for pairing.** The one-line rule is in
   the header comment on `MovieClip.maskee_mc` and again above the registry in
   `action.c`. If a later iteration "needs" one, that is the s10 design coming
   back — re-read wave-1 §2 and `swf.h:138-155`.
3. **Registry cap is 64 live pairs** (`AVM1_MASK_MAX_PAIRS`). Overflow degrades
   gracefully: the pair's direct `mask_mc`/`maskee_mc`/`is_mask` links are still
   set, only the paint-time lookup misses it, i.e. exactly today's behaviour. No
   corpus SWF comes close (the whole corpus has 16 `setMask` callers).
4. **Masked + blended objects.** In the two root loops the stencil push happens
   *before* `renderer_set_blend_mode`, so a `blend_mode > 1` object that is also
   a maskee renders unmasked — deliberately the pre-patch behaviour, chosen so
   the blend path cannot regress. Nothing in the corpus exercises it.
5. **Sibling collisions:** none expected. The defect-C sibling works in
   `avm2_display.c` (`avm2_render_node`); this patch touches no AVM2 file. The
   `tag.c` hunks are in `render_display_list` (~3450-3660), the `tagRerenderFrame`
   loop (~5820-5890), the `tagShowFrame` loop (~6750-6860), `render_attached_child`
   (~6085) and `textfield_glyph_render_cb` (~4870) — none of them the char-id-0
   depth-sentinel sites. The `action.c` hunks are at `actionIterateTextFields`
   (~26390), the registry block before `actionIterateDrawings` (~28530),
   `actionIterateAttachedBitmaps` (~28860) and `setMask` (~70900) — nowhere near
   the ImportAssets path at ~34563.
6. **CI dispatch:** `mode=graphics`, `categories=all`, `images=false` is the
   right per-change run (this is not a render-baseline run). The two band moves
   will only be visible on a later `images=true` run; trace CI should be a
   clean no-op.

---

## 7. Reproduction

```bash
export DAWN_INSTALL=~/CC/dawn-install
python3 ruffle-tests/verify_output.py --test=simple_shapes/text_field_mask \
    --tests-dir=ruffle-tests/tests/swfs/visual --mode=graphics --images --json out.json
python3 ruffle-tests/verify_output.py --test=simple_shapes/scroll_rect_mask \
    --tests-dir=ruffle-tests/tests/swfs/visual --mode=graphics --images --json out.json
python3 ruffle-tests/verify_output.py --test=mask_reapply --mode=graphics --images --json out.json

# full A/B (the canary list is the standing set + wave-1 §4.2 additions)
python3 ruffle-tests/render_canary.py run --stash SWFModernRuntime \
    --tests <list> --recompile -P 2 --json canary_report.json
```

The image verdict is **only** in the `--json` report; the console `Pass: 1` line
is the trace verdict (render-canary false-positive mode 7).
