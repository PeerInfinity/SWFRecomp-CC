# w2-hitarea — wave-2 implementation report (`avm1/hitarea_sweep`, five mechanisms)

Session 19, branched from **master `3cce6a1f7`** (which already carries the sibling AVM1
mouse-dispatch widening, `1c25f09ba`), isolated worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a56288bb3a7a1f23a`. No commits, no pushes.
All runs no-graphics unless marked, `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--diff --verbose`,
never more than one test job at a time. Logs: `<scratchpad>/w2-hitarea/`.

## NEW files (coordinator stages by name)

- `SWFRecompDocs/plans/session19-fanout-reports/w2-hitarea.patch`
- `SWFRecompDocs/plans/session19-fanout-reports/w2-hitarea-report.md` (this file)

No new source files, no new headers, no new TU. **One** source file touched:
`SWFModernRuntime/src/actionmodern/action.c` — runtime only. No recompiler change, no
CMakeLists / Emscripten / `verify_output.py` source-list change. Nothing in `swf_core.c`,
`swf.c`, `input_events.c` or `tag.c`, and no `#ifdef NO_GRAPHICS`-only arm added: the new
`_droptarget` hooks sit inside the three shared AVM1 mouse dispatchers that all three
delivery paths already call, so **`graphics` is the right per-change CI mode**.

Functions touched (for sibling-overlap checking — w2-avm1-sort and w2-setprops are also in
`action.c`): `invokePropertyGetter`, `invokePropertySetter`, `actionFindDynamicDropTarget`,
`actionRefreshDropTargetIfDragged`, `actionDispatchEnterFrameHandlers`,
`actionDispatchMCPress`, `actionDispatchMCRelease`, `actionDispatchMCMouseMove`,
`mc_hit_area_pick_begin`, `mc_hit_pixel_aabb_ng`, `ng_hit_area_tbl_push`. New statics:
`ng_mc_for_dynamic_props`, `ng_mc_pick_visible`, `ng_drawing_art_contains_local`,
`ng_update_drag_droptarget`.

---

## 0. Verdict

**GO — +1, the all-or-nothing flip the brief priced. All five mechanisms landed.**

| test | before (at `3cce6a1f7`) | after | verdict |
|---|---|---|---|
| `avm1/hitarea_sweep` | `output_mismatch` **3/33**, 37 actual | **PASS** 33/33 | **+1** |
| `avm1/hitarea_remove_owner_drag` | `output_mismatch` 5/10, 10 actual | `output_mismatch` 2/10, **11 actual** | no flip; see §4 — the output got *closer*, the index metric lies |

Canaries: **46 avm1 + 4 from_shumway/avm1 + 4 from_gnash/misc-ming.all + 4
from_gnash/actionscript.all + the whole 95-test `regression` suite, every verdict unchanged**,
plus 4/4 in `--mode=graphics` (`hitarea_sweep` passes there too — mode parity holds). The
seven canaries whose verdict is `ruffle_matched` (where a matching status can hide a line
change) were A/B'd on **raw saved output** and are byte-identical; the three
non-hitarea `output_mismatch` canaries have byte-identical diff text. Full ledger in §4.

---

## 1. Baseline re-established against current master (the brief required this)

The wave-0 inventory's numbers predate the sibling AVM1 mouse-dispatch widening. Re-measured
in this worktree at `3cce6a1f7` before any edit
(`<scratchpad>/w2-hitarea/before_sweep.log`): `hitarea_sweep` is **3/33 matching, 37 actual**
— identical to what `w1-avm1-display-report.md` §2.1 recorded, and the same four defective
lines. The widening changed nothing on this test.

Dispositions checked before implementing (grep by test name over
`avm1/_investigation/{ACCEPTED_DIFFS,RUFFLE_VS_FLASH_DIFFERENCES,RUFFLE_COMPAT_TWEAKS,FLASH_BUGS_REPLICATED}.md`,
`ruffle-tests/ignored_tests.txt`, per-suite `ignored_tests.txt`): **no hitarea test appears in
any of them**, and no `known_failure` in any target's `test.toml`. Nothing needs adding to
those docs — every line this patch fixes is a real Flash-parity fix, not a compat tweak.

---

## 2. The five mechanisms, as landed

The brief's diagnosis (`w1-avm1-display-report.md` G4) was **correct on all five counts and on
the all-or-nothing pricing**. 37 actual − 4 defective lines = 33, and the two rewrites land on
the expected text exactly. Confirmed empirically by landing them in two stages: A+B+E alone
took the test to 20/33 with 34 actual lines (`<scratchpad>/w2-hitarea/abe_sweep.log`), and only
C+D on top of that flipped it.

### A — an invisible owner does not pick (`ng_mc_pick_visible`)

Ruffle gates the whole of `mouse_pick_avm1` behind `if self.visible()`
(`movie_clip.rs:2995`), and the parent walk that reaches a child has already passed the
ancestors' gates. We had no visibility check anywhere in the AVM1 MC pick. Added as a
clip-plus-ancestors predicate, applied in four places: the `mc_hit_area_pick_begin` candidate
filter (so an invisible clip's `hitArea` **getter never runs** either), and the three
dispatchers.

In `actionDispatchMCMouseMove` it is folded into `now_inside` rather than used as a `continue`,
so a clip hidden *while hovered* still gets its `onRollOut` — which is what Ruffle's
previous-picked vs current-picked derivation produces. Same shape in `actionDispatchMCRelease`
(`inside` goes false ⇒ `onReleaseOutside`, not silence).

Note the asymmetry the fixture grades and this patch preserves: `SKIP_INVISIBLE` is applied to
the **owner**, never to the hit area ("an invisible hit area still hits",
`movie_clip.rs:3033`) — `btn_inv`'s `invisible` line still fires.

### B — a hit area that is currently a mask hits nothing (`NgHitAreaEntry.blocked`)

`area.hit_test_shape(.., SKIP_MASK)` returns false when `maskee().is_some()`
(`movie_clip.rs:2683`), and Ruffle does **not** then fall back to the owner's own shape: it
only reaches the own-shape arm when the property resolved to no usable display object at all.
Modelled as a `blocked` flag on the per-pick side-table entry, which makes
`mc_hit_pixel_aabb_ng` report "no hit region".

The asymmetry is the interesting half: a **TextField** hit area that is a mask still hits,
because `EditText` has no `hit_test_shape` override and the default bounds implementation
ignores `SKIP_MASK`. The fixture grades both (`btn_mask` silent, `btn_tfmask` firing), so the
flag is gated on `!MC_IS_TEXTFIELD(area)`.

### C — `_droptarget` is a stored snapshot, not a live read (`ng_update_drag_droptarget`)

This is the mechanism with the widest blast radius, and it is a model change, not a bug fix.
Ruffle recomputes the dragged clip's `_droptarget` at exactly two moments:

- on **mouse-event delivery**, *before* that event's own dispatch (`player.rs:1408`), and
- at the **post-action frame tail** (`player.rs:2433`), after `enterFrame` has run.

`startDrag` itself does not update it (`avm1/globals/movie_clip.rs` `start_drag`), so the first
`onEnterFrame` after a `startDrag` inside an `onPress` still reads the *pre-drag* value. Our
`_droptarget` getter instead called `actionRefreshDropTargetIfDragged`, which **recomputed at
read time** — so that first read saw a target Flash had not computed yet, and the sweep emitted
a spurious `dt: /guide` between `drag start` and `dt: /btnB`.

`actionRefreshDropTargetIfDragged` is now a no-op (the four `_droptarget` read sites became
plain field reads) and the recompute moved to `ng_update_drag_droptarget()`, called from the
top of `actionDispatchMCPress` / `…Release` / `…MouseMove` and from the tail of
`actionDispatchEnterFrameHandlers`.

Placing the hooks *inside* the three shared dispatchers rather than in each delivery function
is a deliberate scope choice: `swf_core.c`, `input_events.c` and `swf.c` each call all three, so
one edit covers every mode and keeps the patch out of no-graphics-only code. The fidelity cost
is that a handler running *earlier* in the same mouse event (`onClipEvent(mouseMove)`,
`Mouse.onMouseMove`) sees the previous snapshot rather than the new one; nothing in the corpus
grades that, and it is one line to tighten if it ever matters.

### D — the droptarget pick is shape-accurate (`ng_drawing_art_contains_local`)

`actionFindDynamicDropTarget` was a pure `draw_xmin/xmax` AABB test. Ruffle's drop-target pick
is `run_mouse_pick(context, false)`, which ends in `hit_test_shape` — art, not bounds. The
difference is invisible for the filled rectangles most content draws (bbox *is* the art) and
decisive for line art: the sweep's `guide` is six 1-px horizontal rules whose bbox is the whole
20…780 × 70…650 block, so every probe in the sweep reported `/guide`.

The new helper is the same geometry test `MovieClip.hitTest`'s shapeflag arm already uses —
tessellated fill/line triangles, or a winding test over the raw command list when nothing has
been finalized. It is a **refinement of a bounds test the caller already passed**, and it
returns "hit" for any clip with no tessellated geometry at all (`attachBitmap` clips,
`duplicateMovieClip` clones that carry bounds without a `DrawingState`), so no existing
drop-target answer can be lost to a missing path list.

Only the dynamic-MC arm changed. `tag.c`'s static display-list walk (`find_drop_target_in_dl`,
which runs first and takes precedence) is untouched.

### E — a MovieClip accessor's `this` is the clip (`ng_mc_for_dynamic_props`)

A MovieClip's script-visible properties live in a separate `dynamic_props` `ASObject`, and every
MC accessor call site passes *that* as the receiver, which `invokePropertyGetter` then wrapped as
`ACTION_STACK_VALUE_OBJECT`. So `this` was a bare object inside **every** MovieClip
getter/setter in the corpus: `typeof this` was `"object"`, `this._name` was `undefined`, and
`this.removeMovieClip()` was a silent no-op — which is exactly the sweep's last two lines
(`rm via hit` fired again because `btn_rm` was never removed, and `btn_rm after:` read back
`_level0.btn_rm` instead of `undefined`).

`invokePropertyGetter` / `invokePropertySetter` now map the receiver back to its clip and bind a
`ACTION_STACK_VALUE_MOVIECLIP` `this`, with the `INV_EVENT_THIS_MC | INV_MC_THIS_NULL_PTR`
pairing every other MOVIECLIP-`this` dispatcher in the file uses (so a type-2 body's generated
`preload_this` resolves the clip rather than taking the property bag as an ABI pointer). The
setter path already had `INV_MC_THIS_NULL_PTR` for its `g_event_this_mc` case; it just gained
the `INV_EVENT_THIS_MC` half for receivers it now recognises itself.

The reverse map is a search, because `dynamic_props` carries no owner pointer — but the
`MT_KIND_DPROPS` allocation tag rejects every non-clip receiver in a single load (the
overwhelmingly common case: a plain object's accessor never reaches the scan), and a one-entry
cache absorbs repeated getter calls on the same clip. MovieClip structs are immortal in this
runtime, so the cached pointer cannot dangle.

---

## 3. Refutations and corrections

**R1 — the brief's five-mechanism decomposition and its all-or-nothing pricing both survive,
unchanged.** This is the rarer outcome and worth stating plainly: I found nothing to strike.
The staged measurement (§2) is the receipt.

**R2 — `hitarea_sweep` needed no topmost pick, confirming w1's refutation of the s18 framing.**
The flip landed with `actionDispatchMCMouseMove` still firing on every containing button-mode
clip in creation order. Nothing in this patch touches that loop's structure.

**R3 — `hitarea_remove_owner_drag` is now blocked by G5 (topmost pick) ALONE.** w1 priced it as
"needs the single topmost pick **as well as** mechanism C". C has landed, and the test's output
is now:

```
expected                     ours (after)
1  ready                     ready
2  dt: (none)                dt: (none)
                             rollover Z      <-- the ONLY spurious line (G5)
3  rollover Rm               rollover Rm
4  armed                     armed
5  drag start                drag start
6  removing owner            removing owner
7  dt: /btnRm                dt: /btnRm      <-- NEW, correct (C)
8  dt: /btnZ                 dt: /btnZ
9  drag end                  drag end
10 rollover Z                rollover Z
```

Delete the one extra `rollover Z` and the remaining ten lines are byte-identical to
`output.txt`. **The harness's `matching_lines` went 5 → 2 while the output got strictly
closer** — a pure line-index artefact of one extra line at position 3 (the `diff-line-metrics`
trap). Status is unchanged (`output_mismatch` → `output_mismatch`), so this is not a
regression, and the row is now a **single-mechanism** lead rather than a two-mechanism one.
Whoever takes G5 should expect this test to flip for free.

**R4 — a deliberate, documented deviation retained from s18.** Ruffle stops its pick at the
first (topmost) hit, so a lower clip's `hitArea` getter never runs once a higher clip hits; our
pre-pass resolves every button-mode clip's `hitArea` because our dispatch is not a topmost pick.
Unchanged by this patch, and observable only when two clips both install side-effecting
`hitArea` getters.

**R5 — mechanism B's `blocked` entry does not fire `onRollOut`.** When a hit area *becomes* a
mask while its owner is hovered, `mc_hit_pixel_aabb_ng` returns 0 and the mouse-move loop
`continue`s before touching `mc_mouse_inside`, so no RollOut is delivered. Ruffle would deliver
one. Nothing in the corpus exercises it (the fixture's mask is a mask from the start); the fix
is to give the no-bounds case the same `now_inside = 0` treatment the visibility gate got, which
would also change the *pre-existing* no-bounds path and therefore wants its own measurement.
Named here rather than bundled.

---

## 4. Canary ledger

Baselines read fresh from the main tree's `_results/results_graphics.json` at the session
baseline, and re-confirmed in this worktree for everything that is not a plain `pass` (§4.3).
Bar: a `pass` canary must still pass; a non-`pass` canary must produce byte-identical output.

### 4.1 Headline (no-graphics)

| test | suite | before | after | Δ |
|---|---|---|---|---|
| `hitarea_sweep` | avm1 | `output_mismatch` **3/33**, 37 actual | **PASS** 33/33 | **flip** |
| `hitarea_remove_owner_drag` | avm1 | `output_mismatch` 5/10, 10 actual | `output_mismatch` 2/10, 11 actual | no flip — see R3 |

### 4.2 `--mode=graphics` (`DAWN_INSTALL=/home/robert/CC/dawn-install`)

| test | before | after |
|---|---|---|
| `avm1/hitarea_sweep` | `output_mismatch` | **PASS** |
| `avm1/hitarea_lazy_getter` | pass | **pass** |
| `avm1/drag_drop` | pass | **pass** |
| `avm1/mouse_events` | pass | **pass** |

### 4.3 Canaries — every verdict unchanged

| group | tests | before | after |
|---|---|---|---|
| `avm1/hitarea*` | `hitarea_lazy_getter`, `hitarea_remove_sibling` | 2 pass | **2 pass** |
| `avm1/button_*` | `button_children`, `button_goto`, `button_key_events`, `button_keypress`, `button_keypress_vs_press`, `button_order`, `button_properties_special_cases`, `button_v5`, `button_v6` | 9 pass | **9 pass** |
| `avm1/*drag*` | `drag_drop`, `drag_over_from_outside`, `drag_over_without_startdrag` | 3 pass | **3 pass** |
| `avm1/*mouse*` | `mouse_events`, `mouse_events_visible_enabled`, `mouse_hover_events_while_dragging`, `mouse_listeners`, `mouse_pos`, `mouse_wheel_enabled`, `tab_ordering_events_mouse` | 7 pass | **7 pass** |
| `avm1/focus_mouse*` | `focus_mouse`, `focus_mouse_focusable`, `focus_mouse_rollout` | 3 pass | **3 pass** |
| `avm1/hittest*` + `movieclip_hittest` | `hittest_lockroot`, `hittest_morph`, `hittest_morph_input`, `hittest_winding_rule`, `movieclip_hittest` | 5 pass | **5 pass** |
| `avm1` picking misc | `movieclip_in_removed_button`, `root_button_mode`, `nested_textfields_in_buttons`, `text_blocks_clicks` | 4 pass | **4 pass** |
| `avm1` `_droptarget` consumers | `movieclip_state_values`, `movieclip_default_state` | 2 pass | **2 pass** |
| `avm1` accessor (mechanism E) | `virtual_property_recursion_scope`, `virtual_property_recursion_swf7`, `virtual_property_recursion_double_swf6`, `watch_virtual_property`, `watch_virtual_property_proto`, `infinite_recursion_virtual_property` | 6 pass | **6 pass** |
| `from_shumway/avm1` | `hitarea`, `mouse-transparency`, `nested-button`, `rollover` | 4 pass | **4 pass** |
| `from_gnash/misc-ming.all` | `RollOverOutTest` | pass | **pass** |
| `regression` (whole suite) | 95 tests | 95 pass | **95 pass**, `[diff] pass: 95/95 \| vs prev: no changes` |

**Non-`pass` canaries, A/B'd rather than status-matched** (the `ruffle-matched-trap`): the tree
was reverted with `git apply -R`, the tests re-run, and the results compared.

| test | verdict before = after | evidence |
|---|---|---|
| `avm1/movieclip_hittest_shapeflag` | `output_mismatch` | diff text byte-identical (37 lines both legs) |
| `from_gnash/actionscript.all/MovieClip-v6` | `output_mismatch` | diff text byte-identical (102 lines) |
| `from_gnash/actionscript.all/MovieClip-v7` | `output_mismatch` | diff text byte-identical (102 lines) |
| `from_gnash/actionscript.all/MovieClip-v8` | `output_mismatch` | diff text byte-identical (235 lines) |
| `from_gnash/actionscript.all/MovieClip-v5` | `ruffle_matched` | **raw actual output** byte-identical (`--save-actual`, `cmp`) |
| `from_gnash/misc-ming.all/DragDropTest` | `ruffle_matched` | raw actual output byte-identical |
| `from_gnash/misc-ming.all/ButtonEventsTest` | `ruffle_matched` | raw actual output byte-identical |
| `from_gnash/misc-ming.all/ButtonPropertiesTest` | `ruffle_matched` | raw actual output byte-identical |
| `avm1/movieclip_library_state_values` | `ruffle_matched` | raw actual output byte-identical |
| `avm1/virtual_property_recursion_swf6` | `ruffle_matched` | raw actual output byte-identical |
| `avm1/movieclip_state_values` | `pass` | raw actual output byte-identical (belt-and-braces: it is a `_droptarget` reader) |

`DragDropTest` and `MovieClip-v5..v8` are the mechanism-C blast-radius canaries w1 §2.5
enumerated (the corpus's complete `_droptarget` consumer set, plus the drag/mouse families run
above); `movieclip_hittest_shapeflag` is the mechanism-D one. None moved.

`avm1/movieclip_hittest_shapeflag` was already failing at baseline in exactly this shape
(`hitTest(300, 400, true) -> false`, and the four `(390,430)/(290,450)/(190,480)/(650,430)`
rows) — it is `MovieClip.hitTest`/`shape_hit_test.c`, which this patch does not touch.

---

## 5. Cost / risk notes

- **`ng_mc_pick_visible`** walks the parent chain on every candidate of every pick. Bounded at
  256 links, and it is a field read per level with no allocation.
- **`ng_mc_for_dynamic_props`** is O(1) for every non-MovieClip receiver (one `mt_kind` load)
  and O(1) amortised for repeated accessor calls on the same clip. The worst case — alternating
  accessor calls on two different clips in a large movie — is one `child_mc_cache` scan each,
  which only content that installs `addProperty` accessors on MovieClips can reach.
- **`ng_drawing_art_contains_local`** runs only after the caller's bounds test already passed,
  i.e. at most once per candidate per drop-target pick, and drop-target picks happen only while
  a drag is active.
- **Mechanism C is the one with real reach**: `_droptarget` stops being a live read for every
  title, not just the two tests. The value is now refreshed on every mouse event and once a
  frame, so the only observable difference is content that reads `_droptarget` between a
  `startDrag` and the next mouse event or frame tail — which is precisely the Flash behaviour
  the sweep grades. All six corpus `_droptarget` consumers w1 enumerated were run (§4).

---

## 6. New unclaimed leads

1. **G5 (single topmost AVM1 pick) is now a one-test, one-mechanism lead** for
   `avm1/hitarea_remove_owner_drag` (R3). Still the largest behavioural surface on the board —
   it rewrites Roll events for every overlapping-button AVM1 title and has to reconcile
   `tag.c`'s independent `ng_update_button_states` hover machine — but the pricing improved:
   it no longer has to carry `_droptarget` ownership with it.
2. **`actionMCMouseInsidePick` and `tag.c`'s DefineButton hover loop still ignore `hitArea`**
   (carried from s18 §6.3, untouched here). Completion mechanism: hoist the pre-pass to the
   frame's single input-processing entry point so one table serves every consumer in a frame.
3. **The static display-list drop-target walk (`find_drop_target_in_dl`, `tag.c`) is still
   AABB-only.** Mechanism D fixed only the dynamic-MC arm. A timeline-placed line-art clip is
   still an over-eager drop target. No corpus test grades it today.
4. **Mechanism B's missing RollOut** (R5).
5. **A clip carrying both drawing paths and an `attachBitmap` surface** gets the bounds answer
   from `ng_drawing_art_contains_local` only via the `drawing_state == NULL` arm; if it has
   both, the bitmap's area is not in the path list and a drop-target probe over the bitmap-only
   region would now miss. No corpus content does this (and the pre-patch behaviour was
   over-eager, not under-eager), but it is a one-line guard if anyone hits it.
6. **`_visible` and the `enabled` flag are separate gates.** This patch implements only the
   visibility half of `mouse_pick_avm1`'s preamble; Ruffle also has `if self.mouse_enabled()`
   around the button-mode arm. `avm1/mouse_events_visible_enabled` passes either way, so
   nothing forced it here.
