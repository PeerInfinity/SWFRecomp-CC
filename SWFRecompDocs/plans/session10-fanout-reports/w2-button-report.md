# w2-button — AVM2 SimpleButton state-children rendering (wave-2 implementation)

Spec: `wave1-gfx-button.md`. Worktree `agent-a137c932f78e16e25`, baseline
`feb8882b0`. Runtime-only. Deliverable patch: `w2-button.patch`
(3 files, +198/−10, all under `SWFModernRuntime/`). **No commits, no pushes.**

---

## 0. Headline

| axis | before | after | delta |
|---|---|---|---|
| **image comparisons** (in canary) | 0 of 5 arc comparisons pass | **5 pass** | **+5** |
| **trace tests** (25-test canary) | — | 25/25 == baseline | **0**, zero regressions |

The +5: `focus_highlight_avm2_button_bounds/output`, and **all four**
`from_shumway/button1` frames (`output.1`–`output.4`). Wave 1 predicted
Fix A ⇒ +3 and Fix A+B ⇒ +6; the realised number is **+5**, and the
one-comparison shortfall is a wave-1 **misclassification**, not a miss —
see §3.

Trace yield is **0**, exactly as wave 1 predicted. Trace here was purely a
risk axis and the risk did not materialise.

---

## 1. What was implemented

### Fix A — walk arms for the current-state child (as specified)

New `static inline Avm2Object* avm2_button_state_child(const Avm2DisplayObjectExt*)`
in `SWFModernRuntime/include/avm2/avm2_globals.h` (next to the struct, so
`avm2_bitmap.c` can reach it — it is a separate TU from `avm2_display.c`).
Returns the child for the current state, NULL when that state has no records
(Ruffle `get_state_child`: no Up fallback, hit area never painted). Returns
NULL on every non-button, so call sites need no class check.

Four walk arms added, each immediately before the existing
`for (… ext->render_len …)` loop:

| walk | file:line (post-patch) |
|---|---|
| `avm2_render_node` (GPU / graded) | `avm2_display.c:14413` |
| `avm2_cpu_walk` (CPU dump twin) | `avm2_display.c:13843` |
| `bd_draw_shape_walk` (BitmapData.draw) | `avm2_bitmap.c:2121` |
| `render_apply_text_bounds` (lazy autosize) | `avm2_display.c:3002` |

`bounds_with_transform:754` switched from the hardcoded `ext->btn_up` to the
helper.

**`render_list`, `is_container`, `numChildren` and `set_on_parent_field` were
NOT touched.** The button stays a non-container, which is what
`simplebutton_structure` / `_childshuffle` / `_childprops` /
`_multi_children` assert — all four still pass.

The parent-is-NULL gotcha was honoured: every arm keys off `ext->btn_*`, never
off the child's `parent`. `focus_highlight_avm2_button_bounds` (same `Shape`
assigned to three state slots, leaving its `parent` NULL) is one of the tests
that flipped to pass, which is the direct proof.

### Fix A′ — `resolve_shape_geom` in `button_create_state` (NOT in the spec)

**This was the missing half of the drop, and without it Fix A yields +1 instead
of +5.** The first post-patch canary came back with `focus_highlight_avm2_
button_bounds` flipped (632 channels, exactly the predicted excess) and every
*timeline-defined* button still byte-identical to baseline.

Root cause: `button_create_state` (`avm2_display.c:10186`) sets
`cext->char_id` and calls `resolve_static_text`, but **never calls
`resolve_shape_geom`**. Both other place-time paths do both halves
(`place_child:1739`, `replace_child_character:1801`). So every `DefineButton2`
state child that is a `DefineShape` had `shape_vert_count == 0` and the new
walk arm had nothing to draw. One line fixes it.

Bounds are unaffected — `display_self_bounds` reads `char_self_bounds(char_id)`,
not the vert range, and `char_id` was already being set. That is why this line
adds zero trace risk (confirmed: `avm2/button_bounds` still passes).

### Fix B — current-state tracking (as specified)

* `uint8_t btn_state` added to `Avm2DisplayObjectExt` (`avm2_globals.h:580`);
  0=Up/1=Over/2=Down. The ext is `memset(0)` at alloc, so Up is the default and
  every trace run without mouse input sees exactly today's behaviour.
* `button_set_state()` = Ruffle `set_state` (`avm2_button.rs:279-288`): store,
  clear `parent` on the three renderable state children, re-parent + `mark_attached`
  the new current one. Nothing enters or leaves a render list.
* `button_clip_state()` = Ruffle's clip-event → `ButtonState` table
  (`avm2_button.rs:736-743`), no-op on non-buttons.
* Hooked at six points in `update_mouse_state`, each **before** the matching
  AVM2 dispatch, mirroring Ruffle's `handle_clip_event`-then-
  `event_dispatch_to_avm2` order: RollOut→Up, RollOver→Over, DragOut→Over,
  DragOver→Down, Press→Down, MouseUpInside→Up, Release→Over, ReleaseOutside→Up.
  Left button only (Right/Middle variants are absent from Ruffle's table).
* `btn_state_set`'s `is_cur_state` now consults `btn_state` instead of
  hardcoding the `btn_up` offset.

Correctness proof: `from_shumway/button1` `output.2` (OVER, `#99FF00`),
`output.3` (DOWN, `#FF0099`) and `output.4` (OVER again, after
MouseUpInside→Up then Release→Over) **all three flipped to pass**. That is the
whole state machine validated end-to-end, including the subtle
Up-then-Over ordering on release.

**Deliberate deviations from Ruffle, both documented in the code:**
1. `button_set_state` does not clear `hitTestState`'s parent, although
   Ruffle's `all_state_children()` includes it. Ours parents every timeline
   state child to the button at construction; `run_mouse_pick` and
   `obj_highlight_bounds` both read `btn_hit`; no corpus test observes
   `hitTestState.parent`. Changing it is churn with no yield.
2. `set_enabled(false) → Up` (Ruffle `:388`) is not hooked — `btn_enabled` is a
   `STUB_GETSET` with no C-side hook, and no corpus test exercises it.

---

## 2. Per-fix ledger — image axis

Canary: `render_canary.py capture before` (pre-patch) / `capture after` /
`compare`, md5 equality, `-P 2`, local Dawn. **52 PNGs / 15 tests. 46
IDENTICAL, 6 DIFFERS, 0 APPEARED, 0 VANISHED, 0 NO_RENDER.**

| # | comparison | before | after | A/B channels moved | verdict |
|---|---|---|---|---|---|
| 1 | `visual/focus_highlight/focus_highlight_avm2_button_bounds` / `output` | fail (632) | **pass** | 632 | **WON** — Fix A |
| 3 | `from_shumway/button1` / `output.1` | fail (145920) | **pass** | 145920 | **WON** — Fix A + A′ |
| 4 | `from_shumway/button1` / `output.2` | fail (97280) | **pass** | 97280 | **WON** — + Fix B (OVER) |
| 5 | `from_shumway/button1` / `output.3` | fail (97280) | **pass** | 97280 | **WON** — + Fix B (DOWN) |
| 6 | `from_shumway/button1` / `output.4` | fail (97280) | **pass** | 97280 | **WON** — + Fix B (OVER) |
| 7 | `visual/avm2_button_scroll_rect` / `output` | fail (28851) | fail (**34590**) | 57159 | **CHURN, expected** (§4) |
| 8 | `from_shumway/bitmapbuttons` / `output` | fail (618042) | fail (618042) | 0 | unchanged, out of scope (§4) |
| 2 | `visual/cache_as_bitmap/avm2_button` / `output` | fail (4692) | fail (4692) | 0 | **NOT THIS ARC** (§3) |
| — | `visual/cache_as_bitmap/avm2_button_state` | fail | fail | 0 | IDENTICAL ✓ |
| — | `from_shumway/button2` (4 cmp) | 1 pass / 3 fail | same | 0 | IDENTICAL ✓ |
| — | `from_shumway/button3` (4 cmp, AVM1) | 4 pass | same | 0 | IDENTICAL ✓ — no AVM1 spill |
| — | `focus_highlight_avm1_button` (6 cmp) | 6 pass | same | 0 | IDENTICAL ✓ |
| — | `focus_highlight_move` (5), `focus_highlight_basic` (9) | — | same | 0 | IDENTICAL ✓ |
| — | `avm2/focusrect` (12), `focus_root_movie`, `focus_stage`, `focusrect_focuslost` | — | same | 0 | IDENTICAL ✓ |

Every "must be md5-IDENTICAL" entry on wave 1's list is byte-identical. The
only pixels that moved anywhere are on AVM2 buttons.

**Independent re-derivation of the zero-image-regression claim** (I did not
take wave 1's word for it): I re-scanned every `results_graphics.json` in every
suite for image comparisons that **pass** at baseline, decompressed each
`test.swf`, walked the tag stream, and kept rows that are AVM2
(`DoABC` or `SymbolClass`) **and** carry `DefineButton2` or the literal
`SimpleButton`. Result: **0 rows.** No passing image comparison anywhere in the
corpus contains an AVM2 button, so the image axis cannot regress.
(Script kept at `scratchpad/w2button/scan.py`.)

---

## 3. Correction to wave 1: `visual/cache_as_bitmap/avm2_button` is not an AVM2 test

Wave 1 listed this as blocked comparison #2, medium-high confidence, and
predicted Fix A would flip it. It did not move one byte, and it cannot:

* The SWF's tag histogram is `{FileAttributes, Metadata, SetBackgroundColor,
  DefineSceneAndFrameLabelData, DefineShape, DefineButton2, DefineSprite ×2,
  PlaceObject3, ShowFrame, End}` — **no `DoABC` (82), no `SymbolClass` (76)**.
  It is a pure-timeline SWF that merely has the AS3 bit set in FileAttributes.
* The recompiler emits `RecompiledABC/` (and the AVM2 timeline tables) **only
  when a DoABC tag created the emitter** — `SWFRecomp/src/swf.cpp:286`.
  The test directory has no `RecompiledABC/`.
* `verify_output.py:2036` decides the runtime by exactly that:
  `is_avm2 = (test_dir / "RecompiledABC").exists()`. For this test it is False,
  so **`src/avm2` is not compiled into the binary at all**. The button is drawn
  by the AVM1 `libswf/tag.c` `CHAR_TYPE_BUTTON` path.

Wave 1's derivation gate was "FileAttributes AS3 bit **or** DoABC", which
over-matches on exactly this shape. Its missing 2132 green px belong to the
**AVM1** button/render owner. Recommend removing it from this arc's board and
re-filing it against AVM1 rendering.

(`visual/text/String_path_variable_button`, the other button-shaped image
failure, is likewise AVM1 — checked, unaffected.)

---

## 4. Churn and out-of-scope, called out as promised

* **`visual/avm2_button_scroll_rect`: excess 28851 → 34590, still `fail`.**
  Exactly the churn wave 1 flagged: the button now draws, but the AVM2 render
  walk has no clipping of any kind, so it draws **unclipped and unoffset**
  through the `scrollRect`. `has_scroll_rect` is read only by
  `bounds_with_transform:722`; `renderer_begin_clip`/`end_clip` appear nowhere
  in `src/avm2/`. This is a fail→fail move, not a regression, and it is the
  expected price of the +5. Owner: AVM2 scrollRect clipping, a separate arc.
* **`from_shumway/bitmapbuttons`: 618042 unchanged.** Its state children are
  bitmap-fill shapes; `resolve_shape_geom` deliberately leaves those deferred
  (`sg->renderable` is false), so Fix A′ does not reach them. Needs bitmap-fill
  shapes in the AVM2 shape path. Unchanged by this patch, as predicted.
* `cache_as_bitmap/avm2_button_state` (`content_displaced` + blend), and
  `from_shumway/button2` (Sprite + MouseEvent) — different owners, byte-identical
  here, correctly excluded by wave 1.

---

## 5. Trace canary — 25/25 match baseline

`--mode=graphics`, one `--json` per test, `-P 2`. Compared against the
`feb8882b0` CI `results_graphics.json` (mode parity is complete, so the CI
verdict is the local baseline).

| status | tests |
|---|---|
| `pass` (19) | `button_bounds`, `button_hittest`, `button_nested_frame`, `goto_button_nested_framescript`, `mouse_pick_button_mode`, `simplebutton_added_to_stage`, `_childevents`, `_childevents_nested`, `_childevents_sprite`, `_childprops`, `_childshuffle`, `_constr`, `_constr_childevents`, `_constr_params`, `_mouseenabled`, `_multi_children`, `_structure`, `_symbolclass`, `timeline/swf_9_frame_script_button_order`, **`regression/avm2_simplebutton_click`** |
| `output_mismatch` (3) | `button_nested_frame_simple`, `simplebutton_childevents_multichild`, `simplebutton_soundtransform` — all three `output_mismatch` at baseline too |
| `ruffle_matched` (2) | `simplebutton_childevents_script_order`, `timeline/frame_script_button_order` — `ruffle_matched` at baseline (the `Pass: 0` local report is a match, not a regression) |

**Zero pass→fail, zero pass→ruffle_matched.** In particular the four tests
wave 1 flagged as the Fix-B risk set — `mouse_pick_button_mode`,
`regression/avm2_simplebutton_click`, `button1`, `button2` — all pass, and
`button1`/`button2` are additionally clean on the render canary.

**One methodology note for whoever merges.** Five tests first reported
`compile_fail` (`ld returned 1`) — under `-P 2` *and again sequentially*, so it
looked real. It was not: I had copied the test directories (including their
`RecompiledABC/` caches) out of the main tree while other agents were writing
there, and the copies were mid-write. `--recompile` cleared all five to `pass`.
This is the `stale-recompiledabc` trap; it is a **worktree-copy artifact, not a
property of the patch**, and it does not exist in CI (which recompiles from
scratch). Worth adding to the fan-out playbook: **copy test dirs into a
worktree before starting, or pass `--recompile` on first use.**

---

## 6. Merge risks

1. **`avm2_globals.h` is a wide header.** The patch adds one `uint8_t` field
   (into existing padding after `btn_weird_order`, so almost certainly no size
   change) and one `static inline` function. Any concurrent wave-2 patch that
   also edits `Avm2DisplayObjectExt` or the region right after the struct will
   conflict textually. Both hunks are small and independent — resolve by taking
   both.
2. **`avm2_display.c` is edited in 7 places** (bounds, text-bounds walk,
   `button_create_state`, `btn_state_set`, the new state functions, the CPU
   walk, the render walk, `update_mouse_state`). The `update_mouse_state` hunks
   are the most likely to collide with any other mouse/focus rider. Every hunk
   is additive except two one-line replacements (`Avm2Object* state = ext->btn_up;`
   and the `is_cur_state` expression).
3. **`resolve_shape_geom` in `button_create_state` is the load-bearing line.**
   If a merge drops it, the arc silently regresses from +5 to +1 with no trace
   signal at all — the four `button1` comparisons go back to pure white. It is
   worth a post-merge spot check on `from_shumway/button1 output.1`.
4. **The four walk arms must stay in lockstep.** GPU / CPU-dump / BitmapData.draw
   diverge on every button if one is dropped. The code comments say so at each
   site.
5. **No recompiler change**, so downstream agents need neither a cmake rebuild
   nor `--recompile` for *this* patch (they may need `--recompile` for the
   stale-cache reason in §5).

## 7. CI

`mode=graphics`, `categories=all`. **`images=true` is required for any of this
to be visible** — under the standing `images=false` default the entire patch is
invisible in CI. Expected image board move: **+5 comparisons** (1 in `visual`,
4 in `from_shumway`), plus `avm2_button_scroll_rect` fail→fail with excess
28851→34590. Expected trace board move: **0**.
