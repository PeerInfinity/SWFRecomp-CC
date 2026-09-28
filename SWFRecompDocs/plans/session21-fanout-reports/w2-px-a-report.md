# Session 21 · wave 2 · `w2-px-a`: copyPixels alpha out-of-bounds + nested-child transform un-gate

**Deliverables (new files; stage by name):**
- `SWFRecompDocs/plans/session21-fanout-reports/w2-px-a-1-copypixels.patch`
- `SWFRecompDocs/plans/session21-fanout-reports/w2-px-a-2-nested-ungate.patch`
- `SWFRecompDocs/plans/session21-fanout-reports/w2-px-a-report.md` (this file)

Worktree `.claude/worktrees/w2-px-a` (branch `s21-w2-px-a`, base `835d9f539`). The recompiler was
rebuilt in the worktree, not copied from the main tree, because `a3e7d2858` landed after the main
build. No commits.

- **Applying:** each patch passes `git apply --check` alone against the main tree. Both append a
  block at the EOF of `ruffle-tests/render_canary_tests.txt`, so the second one needs `--3way`
  (the usual canary-file conflict; keep both blocks).
- **Sibling overlap:** none with w2-px-b. My `tag.c` hunk is inside `compose_children` (~3232),
  and I touched no EditText border code and no clip matrix storage.

## Verdicts and flips

| patch | comparison | before → after | trace | files |
|---|---|---|---|---|
| **1** `copypixels` | `avm2/bitmapdata_copypixels` [output] | fail 20 800 → **pass, 0 outliers** (max diff 1, tol 2) | pass → pass (23/23) | `avm2_bitmap.c` (+1 canary member) |
| **2** `nested-ungate` | `visual/cache_as_bitmap/nested_rotation` [output] | fail 25 665 → **pass, 0 outliers, max diff 0** | pass → pass | `tag.c` (+1 canary member) |

**+2 image comparisons, 0 trace moves, 0 regressions** in any A/B leg below. Neither patch is
trace-visible, and both are `OFFSCREEN_RENDER`/runtime changes that `NO_GRAPHICS` does not reach
(patch 1 is shared runtime, but its only effect is on pixels that a trace reads through `getPixel`,
and every trace in the sweep is unchanged). A `mode=graphics categories=full` run grades both,
with `images=true` in the session's combined closeout run.

## Patch 1: `bd_copy_pixels` alpha-bitmap out-of-bounds

Ruffle `core/src/bitmap/operations.rs::copy_pixels_with_alpha_source` gates the alpha lookup on the
alpha bitmap's transparency:
- **Transparent alpha bitmap:** out-of-bounds pixels are skipped (`continue`), so the destination
  is left untouched.
- **Opaque alpha bitmap:** the bounds are never consulted, and the pixel is copied with the
  source's own alpha.

We set `a = 0` and wrote the pixel. The patch sets `a = 255` for an opaque alpha bitmap (which
reduces to the source alpha through the existing `a == 255` arm, so the Flash-matching `sa_eff`
rule for non-transparent sources is preserved) and `continue`s out of bounds for a transparent one.
The stale comment ("we do not need a separate branch here") is rewritten.

- The AVM1 twin (`action.c` `bitmapDataCopyPixels`) already had both rules.
- The alpha arm is per-pixel scalar, so the SIMD span kernels and the self-copy ordering are
  untouched.

**Sweep (A/B `cp_before` vs `cp_after`, patch 2 present on both sides, `--recompile` on first
use):** 12 tests / 4 PNGs, all IDENTICAL, trace all pass → pass:
- `avm2/bitmapdata_copypixels_{alpha_combine,alpha_merge,blend,blend_over,self}`
- `avm2/bitmapdata_copypixelstobytearray`, `avm2/bitmapdata_draw_rotation`
- `visual/bitmapdata_copypixels_with_alpha_oob`, `from_shumway/acid/acid-bitmapData-copyPixels`
- `avm1/bitmap_data_copypixels`, `avm1/bitmapdata_copypixels_self`
- `regression/avm2_static_and_store_slots`

On the full set (after2 → after12, 80 tests / 127 PNGs) exactly one PNG moved: the headline, fail → pass.

## Patch 2: un-gate the nested-child `as_set_flags` overlay in `compose_children`

**Why the gate existed.** `git log -S` / blame: the overlay was introduced by `8deefbb5c`
(2026-05-29), "render AS-moved `_x` for nested clips in attached movies (browser-WASM)", for Doodle
Jump's sliding blue platform. Its commit message gives the reason for the gate verbatim: "Both
gated `!NO_GRAPHICS && !OFFSCREEN_RENDER && !HEADLESS_GRAPHICS` (CI compiles neither path)". That
is a precaution to keep CI byte-identical, not a known divergence. `8cf9ce9e4` later only dropped
the dead `HEADLESS_GRAPHICS` term.

**Why CI graphics had no substitute.**
- The top-of-frame `as_set_flags` loops in `tagShowFrame` / `tagRerenderFrame` walk the **root**
  `display_list` only, and for SPRITE entries they defer to the compose loop.
- The compose loop builds an effective AS-aware matrix only for root-level sprites.
- `build_attached_mc_local_xform` matches attachMovie'd clips only (standalone `display_obj`), and
  `apply_dynamic_mc_transforms` skips any MC that has a `display_obj`.

So a timeline-placed child of a sprite whose `_x`/`_rotation` a script sets was drawn at its
placement matrix under `OFFSCREEN_RENDER`. My wave-1 probes showed `a._rotation` reads back 10 and
`a._x = 0` is equally invisible. They also showed the result is independent of cacheAsBitmap and of
`num_frames`.

**Change.** Remove the `#if/#endif` (the block is already inside `compose_children`'s enclosing
`#ifndef NO_GRAPHICS`) and rewrite the comment with the above.

**Why the change is render-only.** The composed matrix lands in a per-frame dynamic GPU slot
(`obj->transform_id` is pushed onto `xform_overrides` and restored). It is the same slot allocation
that already happens for every nested entry. The CPU transform tables read by hit tests /
`getBounds` (`ng_getMatrixFromObj_render_tid` + `ng_get_original_transform_id`) are untouched, so
the patch cannot move a trace. The A/B below confirms that.

**Double-application check.** The overlay sits only in the final `else` (static baked transform)
arm, after the attachMovie arm and the dynamic-slot arm. A nested entry therefore reaches it only
when neither of those matched, and the root-level in-place loop never visits nested lists.

**Cost.** For every NAMED nested entry per frame, it adds a linear scan of `child_mc_cache` until a
`display_obj` match. Browser-WASM has paid this since May. Native CI tests are small, but a test
near the 30 s wall with thousands of named nested children would feel it. None did in the A/B:
after-leg wall time was 6.2 s/test with ccache warm.

### Verification (render canary, md5 bar)

- **Legs:** `before` (master, `--recompile`), `after2` (patch 2 only), `after12` (both patches).
- **Test set:** the standing `render_canary_tests.txt` (51 tests, including 6 `regression` members)
  plus 29 extras. The extras are:
  - every non-AVM2 image-comparison test in the corpus whose SWF contains `_x`, `_y`,
    `_rotation`, `_xscale`, `_yscale` or `transform` member strings (19 tests: `avm1/*`,
    `visual/*`, `from_gnash/misc-ming.all/{BeginBitmapFill,shape_test}`; SWF-string scan
    over decompressed bodies);
  - the 10 `regression` rows nearest the mechanism: `avm1_child_timeline_{advance,frame1_stop,holder_stop,loop}`,
    `avm1_display_prop_coercion`, `avm1_parent_child_{modify_place,render,sprite_meta}`,
    `avm1_root_identity_and_playhead`, `watch_mc_reentrant_setmember`.
- **Result:** 80 tests / 127 PNGs.

```
before → after2 : IDENTICAL 126, DIFFERS 1  (nested_rotation, fail → pass)
                  TRACE STATUS CHANGES: none   (80/80 pass → pass in graphics mode)
after2 → after12: IDENTICAL 126, DIFFERS 1  (bitmapdata_copypixels, fail → pass)
                  TRACE STATUS CHANGES: none
```

**Coverage caveat, stated plainly.** Only one corpus test in this set exercised the un-gated path
visibly (the headline). A nested script-moved child in a test *outside* the scan (for example
gnash SWFs that move clips through numeric `SetProperty` rather than member strings) could still
move. That is why the closeout `images=true` run should be read with `image_status_diff.py` for
pass→fail on this patch's commit. Any such move is expected to be toward Ruffle (the gate hid
Flash behaviour), but a band that worsens needs a named mechanism, per playbook §19.

## Audit: the other browser-only gates in `tag.c` (report only; nothing changed)

`#if !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` (and two `#ifndef OFFSCREEN_RENDER`)
blocks at `835d9f539`. "Twin" means the native paths do the same job by a different route.
"CI-missing" means graded CI behaviour is absent because of the gate.

| line | guards | native twin? | CI-missing? |
|---|---|---|---|
| 1026 / 11530 | fwd decl + def of `invalidate_mc_for_dl_entry` (browser MC invalidation helper) | yes: `fire_entry_unloads` | no |
| 1578 | nested-sprite natural-wrap: invalidate cached child MCs of freed entries (N churn fix) | yes: NO_GRAPHICS/OFFSCREEN unload path directly above | no |
| 1772 | construct registerClass timeline sprites before the frame's root DoAction (Minesweeper) | yes: `process_sprite_needs_init` at placement | no |
| 2359–2636 | deferred gotoAndStop/Play on attachMovie'd clips + `upgrade_attached_clip_initialized` def | native runs attached-clip nav through its own path (memory `attached-clip-gotoandstop-label`) | no evidence |
| **3232** | nested timeline child AS-transform overlay in `compose_children` | **none** | **yes: fixed by patch 2** (`nested_rotation`) |
| 4560 / 5114 / 5181 | DefineButton2 state machine for buttons inside attached clips; AS2 button-fire | yes: comment says native dispatches attached-clip buttons per event | no |
| 5440 / 5568 / 7292 / 7366 | enterFrame clip actions for sprites nested **inside attachMovie'd clips** (`dispatch_attached_clip_enterframe`, `upgrade_attached_clip_initialized`) | **unverified**: no stated native twin; the root walk needs `sprite_initialized ≥ 2`, which ng_attachMovie's copied entry never gets | **possible, trace-visible**. Candidate lead: a regression fixture (library symbol with `onClipEvent(enterFrame)` on a nested child, attached via `attachMovie`) with a Ruffle-exporter oracle. Not measured this slot. |
| **6071** | horizontal `scrollX` layout shift for a focused single-line field | none | **yes, CI-graded.** The comment's premise ("in OFFSCREEN nothing is focused") is refuted by the same evidence that un-gated the caret (s20/s21): `input.json` focus is replayed in CI. Carriers: `visual/cache_as_bitmap/edittext_hscroll` .01/.02 (96 / 960, s18: "we render the unscrolled text"). |
| **6123** | selection-highlight box behind selected glyphs | none | **yes, CI-graded.** Carrier: `visual/cache_as_bitmap/edittext_selection` .02 (6 783; s18: "the selection highlight block is not drawn"). Same refuted premise as 6071. |
| 6929 | recursive finalize of deferred `pending_remove` in nested sprites (Pong) | n/a: the `pending_remove` deferral itself is browser-only; native removes immediately | no |
| 7021 / 7881 (`#ifndef OFFSCREEN_RENDER`) | layer attached clips at their **parent's** depth (Tetris board under game-over overlay); the post-loop pass under OFFSCREEN renders **root-parented attaches only** ("kept out … to stay byte-identical") | partial: non-root attaches that `compose_children` reaches through the parent's sprite list | **possible**: an attached clip parented to a timeline sprite that sits below later timeline content paints in the wrong z-order, or not at all, under CI. Same "byte-identical precaution" wording as 3232. Unmeasured. |
| 8800 | populate CPU `cx_*` from `cxform_data` at placement | yes: `ng_on_place_object2` | no |
| 9245 / 10273 | consume same-tick `pending_remove` at Place (browser deferral) | n/a (deferral is browser-only) | no |
| 9916 | invalidate the replaced entry's MC on PlaceObject2 replace (Doodle Jump) | yes: native unload / replace path | no |
| 10043 / 10619 | inline auto-instance-name for unnamed scriptable placements | yes: `ng_on_place_object2` | no |
| 10312 | frame_func re-run protection (browser loop lacks the `is_playing` gate) | n/a: native loop has the gate | no |

**Leads from the audit, ranked:**
1. **6071 + 6123, the EditText scrollX and selection highlight.** Both are CI-graded, and both
   were gated on a premise that s20/s21 already refuted for the caret. Un-gating is a small parity
   change, but whether it *flips* anything depends on the `with_default_font` glyph residual in
   those rows (s18: `edittext_selection .01` 366 vs budget 8), so price it by building. The
   caret-owner slot (w2-caret-multiline) or a text slot should own it. Do not bundle it into a
   geometry patch.
2. **7021/7881, OFFSCREEN renders only root-parented attached clips in the post-loop pass.** It
   carries the same "stay byte-identical" wording as the gate patch 2 removed. The first step is a
   corpus scan for `attachMovie` on a non-root target in image-graded tests.
3. **5440/5568/7292/7366, onClipEvent(enterFrame) on sprites inside attachMovie'd clips.** This
   would be trace-visible if native lacks it. Build a fixture with a Ruffle oracle before touching
   it.

## Repro

```bash
WT=.claude/worktrees/w2-px-a; export SWFRECOMP_COMPILE_TIMEOUT=2400 DAWN_INSTALL=~/CC/dawn-install
# list = render_canary_tests.txt + 29 extras (scratch: w1-pixel-smalls/ab_list.txt)
python3 ruffle-tests/render_canary.py capture --label before  --tests ab_list.txt --tier all --recompile -P 2 --timeout 5400
git apply w2-px-a-2-nested-ungate.patch   # (tag.c hunk)
python3 ruffle-tests/render_canary.py capture --label after2  --tests ab_list.txt --tier all -P 2 --timeout 5400
git apply w2-px-a-1-copypixels.patch      # (avm2_bitmap.c hunk)
python3 ruffle-tests/render_canary.py capture --label after12 --tests ab_list.txt --tier all -P 2 --timeout 5400
python3 ruffle-tests/render_canary.py compare before after2; python3 ruffle-tests/render_canary.py compare after2 after12
```
