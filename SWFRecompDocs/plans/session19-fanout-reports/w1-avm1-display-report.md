# w1-avm1-display — wave-1 diagnosis (AVM1 display / event / timeline-order trace rows)

Session 19, HEAD `254145a5b`, read-only. No source edits, no commits. All runs are single-test
`--mode=no-graphics --diff --verbose` with `SWFRECOMP_COMPILE_TIMEOUT=2400`, sequential (one job,
plus at most one probe alongside). Logs and actual-output captures:
`<scratchpad>/w1-avm1-display/` (`log_*.txt`, `actual_*.txt`, `probe/`).

---

## 0. Verdicts

| # | Slice | Rows | Priced | Files | Verdict |
|---|---|---|---:|---|---|
| **G1** | `MovieClip.prototype` fall-back in the MC **event-handler** lookup | `from_gnash/misc-ming.all/PrototypeEventListeners` 1/32 → **`ruffle_matched`** | **+1 eff** | `action.c` (`mc_call_as2_handler_ng`, ~6 lines) | **GO** (probe-verified premise) |
| **G2** | AVM1 mouse-wheel → hovered TextField `scroll` + `onScroller` dispatch | `avm1/edittext_onscroller` 0/14 → **`ruffle_matched`** | **+1 eff** | `swf_core.c` + `swf.c` (new `EV_MOUSE_WHEEL` arm), `action.c` | **GO** |
| **G3** | `nextFrame()` from a **Key/Mouse listener callback on a stopped root** is silently dropped | `from_gnash/misc-ming.all/masks_test` (stops dead at 28/175) | **unblock**, flip unknown | `action.c::actionNextFrame` (~5 lines) | **GO (cheap), flip to be measured** |
| **G4** | hitArea second arc — **five** mechanisms (A owner-visibility, B mask-as-hitArea, C `_droptarget` snapshot model, D shape-accurate droptarget pick, E accessor `this` binding) | `avm1/hitarea_sweep` 3/33 → **pass** | **+1, all-or-nothing** | `action.c` (pick + accessors), `tag.c` (`ng_compute_droptarget`) | **GO as one slice** (no single half flips it) |
| **G5** | Single **topmost** AVM1 pick (Ruffle `mouse_pick_avm1`) | `avm1/hitarea_remove_owner_drag` 5/10 → pass **only together with C** | +1 (needs G4's C) | `action.c::actionDispatchMCMouseMove` rewrite | **HOLD** — biggest blast radius on the board |
| — | `timeline/missing_frame_scripts` 12/22 | S3 (`!has_end_tag`) **and** S4 (one-tick lag) | +1 only if both | `abc_timeline.cpp`, `avm2_abc.h`, `avm2_display.c` | **HOLD** (re-verified, unchanged) |
| — | `text/links_in_scrolled_text` 0/1 | s16 patch still applies clean; still 0 flips | 0 | text line model (`ng_computeScroll*`) | **HOLD** |
| — | `PlaceAndRemove`, `action_execution_order_test11`, `ActionOrderTest3/4/5`, `_test6`, `_extend_test`, `movieclip_destruction_test3/4` | 9 rows | **0** | — | **NO-GO — re-verified byte-identical at HEAD** |
| — | `from_gnash/misc-swfc.all/gotoFrameFromInterval` (optional item) | dispositioned **and** CI-excluded by name | **0 by construction** | `timer.c` | **NO-GO for score** (robustness item only) |

Biggest refutations: **the sweep needs no topmost pick and almost no shape hit-testing** (§2.2),
**masks_test is not a mask bug at all** (§4), **PrototypeEventListeners is not an early abort**
(§3), and the s18 "heap used before init" lead is really **a silently dropped local variable**
(§8.1).

---

## 1. Board re-verified at HEAD — zero drift

Every row re-run locally; **actual-line counts are identical to the wave-0 inventory (graphics
baseline `aac695228`) on all 16 rows**, and every diff I compared line-for-line against the s17/s18
transcripts is unchanged. No staleness, no upstream movement in this family.

| row | expected/match/actual (inventory) | local re-run (actual lines) |
|---|---|---|
| `avm1/hitarea_sweep` | 3/33, 37 | 37 ✔ |
| `avm1/hitarea_remove_owner_drag` | 5/10, 10 | 10 ✔ |
| `avm1/edittext_onscroller` (KF,RTXT) | 0/14, 0 | 0 ✔ |
| `from_gnash/misc-ming.all/masks_test` (KF,RTXT) | 28/175, 28 | 28 ✔ |
| `timeline/missing_frame_scripts` | 12/22, 27 | 27 ✔ |
| `text/links_in_scrolled_text` | 0/1, 0 | 0 ✔ |
| `…/PrototypeEventListeners` (KF) | 1/32, 12 | 12 ✔ |
| `…/action_order/PlaceAndRemove` | 15/96, 45 | 45 ✔ |
| `…/action_execution_order_test11` | 26/32, 32 | 32 ✔ (same 8/9 swap, same `0+2+1+3+4+5+`) |
| `…/ActionOrderTest3` / `4` / `5` (KF,RTXT) | 4/62,83 · 10/64,94 · 6/51,58 | 83 · 94 · 58 ✔ |
| `…/action_execution_order_test6` (KF,RTXT) | 0/24, 20 | 20 ✔ (Construct-before-Load still inverted) |
| `…/action_execution_order_extend_test` (KF) | 7/32, 28 | 28 ✔ |
| `misc-swfc.all/movieclip_destruction_test3` / `4` (KF) | 5/18,16 · 8/40,24 | 16 · 24 ✔ (same deferred-removal signature) |

**Dispositions checked** (rule 2) for every row above against `avm1/_investigation/{ACCEPTED_DIFFS,
RUFFLE_VS_FLASH_DIFFERENCES,RUFFLE_COMPAT_TWEAKS,FLASH_BUGS_REPLICATED}.md`, the per-suite
`_investigation/` docs, `ruffle-tests/ignored_tests.txt` and every per-suite `ignored_tests.txt`:
**no row on my board is in an ignore list or a disposition doc**, except
`gotoFrameFromInterval` (§7). Hits in `from_gnash/_investigation/CURRENT_STATUS.md` are status
rows, not dispositions.

---

## 2. Head of the brief: the hitArea second arc

### 2.1 `hitarea_sweep` — 33 expected, 37 actual, and only **4 wrong lines**

The "3/33 matching" headline is a line-index artefact: three spurious lines shift the whole
alignment. The complete defect list (expected ↔ our `actual_hitarea_sweep.txt`):

| our line | what we emit | expected | mechanism |
|---|---|---|---|
| 4 | `owner invisible` | *(absent)* | **A** — an **invisible owner** must not pick. Ruffle `movie_clip.rs:2995 if self.visible()` guards the whole pick; our `actionDispatchMCMouseMove`/`…Press`/`…Release` have no visibility check anywhere, and `mc_get_pixel_aabb_ng` only tests `unloaded`, and only in browser-WASM builds. (`btn_oinv._visible=false` + a visible hit area.) |
| 7 | `mask via hit` | *(absent)* | **B** — a hit area that is **currently a mask** does not hit: `area.hit_test_shape(..., SKIP_MASK)` (`movie_clip.rs:3034`) returns false when `maskee().is_some()`. Note the asymmetry the fixture grades: `tfmask` (a **TextField** mask) *does* hit, because `EditText` has no `hit_test_shape` override and the default bounds impl ignores `SKIP_MASK`. Both our `mask via hit` (wrong) and `tfmask` (right) are on that one rule. |
| 23 | `dt: /guide` | *(absent)* | **C** — `_droptarget` is a **stored snapshot**, not a live read. Ruffle updates it only inside `Player::update_drag`, which runs on mouse-event delivery (`player.rs:1408`, *before* the press dispatch) and in the post-frame `update()` tail; `startDrag` itself does **not** update it (`avm1/globals/movie_clip.rs` start_drag). Our `_droptarget` getter calls `actionRefreshDropTargetIfDragged` and recomputes at read time (`action.c:35540`), so the first `onEnterFrame` after `startDrag` sees a target Flash has not computed yet. |
| 26 | `dt: /guide` | `dt: (none)` | **D** — the pick must be **shape-accurate**. `guide` is a 1-px line-art clip spanning the six row guides; its AABB is the whole 20…780 × 70…650 block, so *every* droptarget probe inside the sweep hits it. `actionFindDynamicDropTarget` (`action.c:35435`) is pure `draw_xmin/xmax` AABB. This is the **only** row on either hitArea test where shape-vs-AABB decides anything. |
| 36 | `rm via hit` (extra) | *(absent)* | **E** — `this.removeMovieClip()` inside a MovieClip's `addProperty` getter is a **no-op**. |
| 37 | `btn_rm after: _level0.btn_rm` | `btn_rm after: undefined` | **E** (same cause) |

**E is measured, not inferred.** Probe `<scratchpad>/w1-avm1-display/probe/getter_this/`
(MTASC, `addProperty` on a `createEmptyMovieClip` clip, read the property):

```
typeof this: object          <-- Flash: "movieclip"
this._name: undefined        <-- Flash: "btn_rm"
after get: _level0.btn_rm    <-- this.removeMovieClip() did nothing
after get2: undefined        <-- the same removal via _root.btn_two.removeMovieClip() works
```

Cause: every MC accessor call site passes `mc->dynamic_props` as the receiver
(`action.c:55363/55387/55422`, and `ng_resolve_hit_area` at `:75067`), and
`invokePropertyGetter` (`:8444`) builds `this` as `ACTION_STACK_VALUE_OBJECT`. There is no
dynamic_props → MovieClip re-binding, so `this` is a bare object inside *every* MovieClip
getter/setter in the corpus — not a hitArea-specific bug.

**Pricing:** A, B, C, D, E **all five** are required for the flip; 37 − 4 spurious = 33 lines and the
two rewrites land exactly on the expected text, so the slice is `pass`, not a partial. No single half
scores. A / B / E are each ~5–15 lines; C and D are the real work.

### 2.2 REFUTATION — the brief's (and s18's) framing of this arc is wrong

> "the rest is shape-based (not AABB) picking plus a single topmost pick: today every
> AABB-containing button-mode clip fires, in creation order."

- **`hitarea_sweep` needs no topmost pick at all.** Checked mechanically (script inlined in
  `<scratchpad>/w1-avm1-display/`, run over all 54 pointer positions in `input.json` against every
  button-mode clip's effective hit region, in both the pre- and post-getter-move phases — row 4's
  getters shift `hit_xf` to 530…610 and `btn_xfown` to 650…730): **zero stops are covered by two
  button-mode clips.** The `rollover-fires-on-everything` defect is simply not exercised here.
- **`hitarea_sweep` needs shape hit-testing in exactly one place** — the `_droptarget` pick, for the
  `guide` line-art clip (D). Every other clip in the fixture is an axis-aligned `beginFill`
  rectangle drawn with the drawing API, where the AABB *is* the shape. "Route AVM1 picking through
  `shape_hit_test.c`" (s18 §6.4) is not what this row needs.
- **Two of the four wrong lines are not picking at all**: E is an accessor `this`-binding bug, and C
  is a timing/ownership model for `_droptarget`.
- The s18 claim that survives unchanged: rollover fires on every containing button-mode clip in
  creation order (`actionDispatchMCMouseMove` iterates `child_mc_cache` by index). That is what
  `hitarea_remove_owner_drag` line 3 grades — and nothing else on my board.

### 2.3 `hitarea_remove_owner_drag` — 5/10, exactly two mechanisms

```
expected                     ours
1 ready                      ready
2 dt: (none)                 dt: (none)
3 rollover Rm                rollover Z      <-- G5 (topmost pick): btnZ (depth 1) and btnRm
4 armed                      rollover Rm          (depth 2) occupy the SAME rect; Flash reports
5 drag start                 armed                only the topmost, we fire both in creation order
6 removing owner             drag start
7 dt: /btnRm                 removing owner
8 dt: /btnZ                  dt: /btnZ       <-- C: the pick that REMOVED the owner must still
9 drag end                   drag end             report it; removal takes effect on the NEXT pick
10 rollover Z                rollover Z
```

With **C** (§2.1) the sequence falls out for free, because Ruffle's droptarget pick is where the
`hitArea` getter runs (`require_button_mode == false` resolves the property and discards the value,
`movie_clip.rs:3026`) and `hit_test_shape` does not re-check `avm1_removed`: the owner is returned
on that pick and excluded from the next one. Our getter currently runs in the rollover pre-pass
instead, so by the time `onEnterFrame` reads `_droptarget` the owner is already gone.

**So: C flips nothing alone, but it is shared by both tests; C + the topmost pick flips this row.**

### 2.4 G5 (topmost pick) — what it costs, and why it is HOLD

`actionDispatchMCMouseMove` (`action.c:75294`) fires `onRollOver`/`onRollOut`/`onDragOver`/
`onDragOut` for *every* clip whose (possibly hit-area-substituted) AABB contains the pointer, with
only `mc_has_button_mode_ancestor_with_mouse` as a partial suppressor. Ruffle instead computes one
picked object per pick and derives Roll events from *previous picked* vs *current picked*
(`player.rs::update_mouse_state` + `run_mouse_pick`). Converting means:

1. a render-order comparator across the whole tree (our `ng_hit_order_cmp` compares `mc->depth`
   only, which is wrong for clips with different parents),
2. reconciling with `tag.c`'s separate `ng_update_button_states` DefineButton path, which is a
   second, independent hover state machine,
3. changing RollOut semantics for every AVM1 title with overlapping button clips (a lower clip now
   gets RollOut while the pointer is still inside it).

Canary set if anyone takes it: `avm1/button_*` (9), `avm1/drag*` (3), `avm1/mouse_*` (5),
`avm1/hittest*` (4), `avm1/focus_mouse*`, `from_shumway/avm1/{mouse-transparency,nested-button,
rollover}`, `from_gnash/misc-ming.all/{RollOverOutTest,ButtonEventsTest,DragDropTest}`, and the
whole `regression` suite. Priced **+1 row** (`hitarea_remove_owner_drag`, and only with C) against
the largest behavioural surface on this board → **HOLD**, not a wave-2 slice unless someone budgets
a whole agent to it.

### 2.5 Blast radius for C and D

Corpus scan for `_droptarget` (source + SWF string scan): `avm1/hitarea_sweep`,
`avm1/hitarea_remove_owner_drag`, `avm1/movieclip_state_values`,
`avm1/movieclip_library_state_values`, `avm1/movieclip_default_state`,
`from_gnash/actionscript.all/MovieClip-v5..v8`. The runtime's own comments name two more consumers
to canary: `from_gnash/misc-ming.all/DragDropTest` (dynamic targets) and the static-display-list
precedence case documented in `ng_compute_droptarget` (`text_blocks_clicks`). That is the complete
canary list — the string scan cannot see `GetProperty`-index uses, so run the drag/mouse families
too.

---

## 3. G1 — `PrototypeEventListeners`: not an early abort (**GO, +1 effective**)

s17's board called this "an early abort, so a cascade". **Refuted**: our run completes normally
(`#total tests run: 5` … `END OF TEST` at line 12). What is missing is that **no** clip ever
receives a `MovieClip.prototype`-installed mouse handler:

```
ours:      FAILED: expected: 4 obtained: 0 [./PrototypeEventListeners.as:66]
expected:  _level0.clip2.onMouseDown / PASSED: typeof(this) == "movieclip" / _level0.clip1... 
```

`mc_call_as2_handler_ng` (`action.c:74850`) looks up the handler with
`getPropertyWithPrototype(mc->dynamic_props, …)`, which walks the clip's own `__proto__` chain — but
a plain timeline/`createEmptyMovieClip` clip has no `__proto__` link to `MovieClip.prototype`, so the
walk ends immediately. This is exactly the gap s18's hitArea slice closed for `GetMember`/`SetMember`
**accessors only** (`w2-avm1-hitarea-report.md` §2 M2); the event-dispatch path never got it.

Probe `<scratchpad>/w1-avm1-display/probe/protomouse/` (MTASC:
`MovieClip.prototype.onMouseDown = function(){ trace("proto onMouseDown: " + this); }` plus a
`createEmptyMovieClip` clip and an `input.json` click): **we emit `ready` and `own rollover` and
nothing else** — the prototype handler fires for neither the clip nor `_root`.

**Patch shape:** in `mc_call_as2_handler_ng`, when the proto walk returns no FUNCTION, fall back to
`g_movieclip_constructor.prototype_obj` (function values only). ~6 lines, one file, runtime-only.

**Why `ruffle_matched` is reachable (computed, not guessed).** Grading uses the highest-version
subtest `fp11`, which carries `known_failure = true` and `output.fp11.ruffle.txt`. Ruffle's
diff-index set vs Flash is `{6,8,10,11,12,13,14,16,18,…,32}`; it **matches** Flash at
`{1,2,3,4,5,7,9,15,17}`. So the slice must land exactly the four prototype dispatches
(`clip2`, `clip1`, `Dejagnu.instance1`, `Dejagnu` — reverse-creation order, which is already our
`actionDispatchMCMouseDown` iteration order) with `this` bound to the clip; `_global.onMouseDown`
(Flash line 6) is *not* needed and Ruffle doesn't do it either. Everything from index 6 on is free.
**Medium confidence on the exact index alignment** — the wave-2 agent should diff against
`output.fp11.ruffle.txt` directly and stop when the sets match.

Canaries: `avm1/mouse_events`, `mouse_listeners`, `mouse_events_visible_enabled`,
`as_broadcaster*`, `avm1/register_class*`, `from_gnash/actionscript.all/MovieClip-v*`, plus the
whole `regression` suite (prototype-installed handlers now fire for every clip — Flash-correct, but
it is a behaviour change).

---

## 4. G3 — `masks_test` is not a mask bug (**GO, cheap; flip unknown**)

The brief says "we emit exactly 28, so check for an early stop". Confirmed, and the root cause has
nothing to do with masks: **our 28 lines are all correct** (every `PASSED` matches), and the test
then waits for a keypress:

```
 - Press any key to continue -
```

`RecompiledScripts/script_31.c` does `stop()`, then `l.onKeyUp = function(){ NextFrame }` and
`Key.addListener(l)`. Probe `<scratchpad>/w1-avm1-display/probe/keylistener/` proves the listener
side works (our runtime fires `onKeyDown`/`onKeyUp` for an `Object` listener on a stopped root).
The loss is in `actionNextFrame` (`action.c:34081`): it has an inline-catch-up arm for
`g_inside_event_handler` (set **only** by `mc_call_as2_handler_ng`, `:74874`) and one for
`g_inside_enterframe_dispatch`, but a `Key`/`Mouse` broadcaster callback sets neither, so it falls
to the default `next_frame = current_frame+1; manual_next_frame = 1`. On a **stopped** root the main
loop consumes that at end-of-tick (`swf_core.c:1626`: `current_frame = next_frame; manual_next_frame
= 0`) and the next tick's gate `if (is_playing || manual_next_frame)` is then false — the target
frame's tags and DoAction never run. The playhead moves; nothing executes; the movie is silent for
the remaining 99 ticks. `actionGotoFrame` is unaffected (it sets `goto_from_action`, which the main
loop's catch-up loop honours regardless of `is_playing`) — this is a `NextFrame`/`PrevFrame`-only
hole.

**Patch shape:** in `actionNextFrame`'s default path, when the root is stopped, use the deferred
`goto_from_action = 1` form that the `g_inside_enterframe_dispatch` arm already uses (~5 lines), or
bracket `g_inside_event_handler` around broadcaster dispatch (`actionDispatchKeyDown/Up`,
`actionDispatchMouseDown/Up/Move`, `action.c:38080`) — that flag is read in exactly one place
(`:34115`), so the blast radius is `actionNextFrame` only.

**Flip:** unknown. The row is `known_failure` with an `output.ruffle.txt` that differs from Flash on
only ~6 of 175 lines, so `pass` and `ruffle_matched` cost the same 147 lines; unlocking merely lets
the remaining mask-semantics assertions run for the first time. Price it as **"cheap unblock, then
measure"** — it is ~5 lines and it is a genuine runtime defect regardless of the score.

---

## 5. G2 — `avm1/edittext_onscroller` (**GO, +1 effective**)

We emit **zero** lines. Two gaps:

1. **AVM1 never handles the mouse wheel.** `MOUSE_WHEEL` is parsed into `EV_MOUSE_WHEEL`
   (`swf_core.c:446`, `input_events.c:97`) and then *silently dropped* — there is no
   `case EV_MOUSE_WHEEL` in the AVM1 event switch at all. AVM2 has the whole thing
   (`avm2_text.c:10426 avm2_text_mouse_wheel`, Ruffle's `EditText::event_dispatch(MouseWheel)`),
   so the semantics are already written down on our side of the fence.
2. **`onScroller` is never dispatched.** `scroll` exists as a plain property on the field's props
   object (clamped at `action.c:53057`), but nothing fires the callback on change.

Ruffle's rule: `scroll = clamp(scroll − delta_lines)` on the field under the pointer, then
`onScroller(field)`. The fixture's wheel deltas are ∓3 and the expected walk is 1→4→7→10→7→4→1 —
**no clamping is involved** (20 lines of text in a 100 px field ⇒ `maxscroll` ≫ 10), so this row
does **not** depend on our line model. That is what makes it cheap: the known-weak
`ng_computeScroll*` family (see §6.2) is out of the loop.

`ruffle_matched` is the target and it is exact: Flash fires `onScroller` once more than Ruffle (for
the script-side `tf.scroll = 1` at the end of frame 1), so Ruffle's diff set is
`{2,4,6,8,10,12,13,14}`; emitting Ruffle's 12 lines (wheel-driven events only) is a subset match.
Do **not** add the script-assignment event — it would break the subset.

---

## 6. HOLDs

### 6.1 `timeline/missing_frame_scripts` — 12/22, unchanged; S3 **and** S4 both required
Re-run at HEAD: 27 actual, identical to s17/s18. Our `Spawn` (char 13: 2 ShowFrames, **no End
tag**) loops forever and reaches `Spawn stopped`; five of our lines are `Spawn frame1/frame2/stopped`
lines that must not exist (S3 = `!has_end_tag` in `avm2_display.c:1934 determine_next_frame`), and
the orphan `Container` is one tick behind for the rest of the movie (S4). Removing the Spawn lines
alone leaves Container misaligned ⇒ still `output_mismatch`. s18's relabel stands: S4 is a
main-timeline advance/removal defect, not an orphan-phase one (`w2-avm2-timeline-report.md` §5.4
instrumented the orphan list and `Spawn` never joins it). **HOLD — completion mechanism: pin S4's
one-tick lag first, then land both together.**

### 6.2 `text/links_in_scrolled_text` — 0/1, still 0 flips
Re-verified: 1 expected line, 0 actual. `session16-fanout-reports/w2-smalls-links_in_scrolled_text.patch`
still applies clean at HEAD (`git apply --check`, all three files). s16's completion mechanism is
unchanged and is a **text-layout** task, not a hit-test one: grade `maxscroll`/`bottomScroll` for
this field against Flash, decide whether the phantom trailing line from the HTML→text conversion
participates in the scroll window, and pair it with `text/text_caret_placement_scroll`. Do not merge
the s16 patch alone.

---

## 7. NO-GO family — re-verified, byte-identical

`PlaceAndRemove` (15/96, 45), `action_execution_order_test11` (26/32, same 8/9 `mc21 onLoad` ↔
`mc1 onEnterFrame` swap, same `doActionOrder 0+2+1+3+4+5+`, same `asOrder`), `ActionOrderTest3/4/5`
(83/94/58 actual), `_test6` (20 actual; Construct-before-Load still inverted), `_extend_test` (28),
`movieclip_destruction_test3/4` (16/24, same deferred-removal signature: `nestedMovieClip removed at
frame 10` and `actions here should not be executed` missing, `typeof(nestedMovieClip)` `movieclip`
vs `undefined`, `as_order 0+` vs `0+1+2+`). Diagnosis of record stands
(`session17-fanout-reports/wave1-timeline-order.md` §6–7 and
`session18-fanout-reports/w1-trace-avm1-report.md` N2/N3/N5) — I re-derived nothing.

**`gotoFrameFromInterval` (optional item) — NO-GO for score, by construction.** It is
(a) dispositioned in `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` ("Ruffle's expected output
is an unbounded runaway… do not pursue `ruffle_matched`"), and (b) excluded **by name** in
`.github/workflows/ruffle-tests.yml:880` (`--exclude=gotoFrameFromInterval`), so it is not in the
denominator in either mode: any fix moves the score by exactly **0**. The mechanism is nevertheless
real and Ruffle spells it out: `core/src/timer.rs` has **`MIN_INTERVAL = 10` ms** *and*
**`MAX_TICKS = 10`** per `update_ticks`; our `timer.c::processTimers` has neither (it advances every
timer by a whole `frame_duration_ms` and drains under a 10 000-iteration guard, i.e. 20 000
callbacks per tick for this fixture — s18 `w2-avm1-goto-report.md` §4c). A 10 ms floor **plus** the
per-tick tick cap is the Ruffle-authentic pair; landing only the floor still leaves an unbounded
per-tick drain. Required validation if anyone takes it as a robustness item (browser game hangs, not
score): a full-corpus A/B in **both** modes, because it re-times every `setInterval` in the corpus.

---

## 8. New unclaimed leads

1. **A local variable is silently dropped when a constructor runs before the first function call.**
   The s18 lead "`heap_alloc() called before heap_init()` on `action_execution_order_test11`" is
   mis-stated: the heap *is* initialised (the message prints after `[HEAP] Initialized`). The guard
   that fires is `app_context == NULL`. gdb backtrace on the failing call
   (`<scratchpad>/w1-avm1-display/build_t11`, `break heap_alloc if $rdi == 0`):
   ```
   heap_alloc ← setProperty ← setVariableOnLocalScope ← setVariableByName
              ← func2_anonymous_1 ← actionNewObject ← script_2 ← aq_dispatch_sprite_script
   ```
   `setVariableOnLocalScope` (`action.c:579`) passes the file-static `g_scope_app_context`, which is
   assigned **only** at the entry of `actionCallFunction`/`actionCallMethod` (`:58264`, `:61535`,
   `:67010`) and is still `NULL` when the first user code to run is a `new`-invoked constructor. The
   property name allocation returns NULL and `object.c:1066` **drops the property** (`num_used--`).
   Affects 3 of my rows (`action_execution_order_test6`, `_test11`, `PlaceAndRemove` — all
   `misc-ming.all/action_order`) and is a ~2-line fix (set `g_scope_app_context` in `actionNewObject`,
   or seed it once in `swfStart`). Priced **0 flips** by itself (t11's diff is pure ordering), but it
   should be fixed before anyone re-prices that family, because a dropped `var` inside a constructor
   is exactly the kind of thing that corrupts an order test.
2. **MovieClip accessor `this` is a bare object** (§2.1 E). Every `addProperty` getter/setter on a
   MovieClip receives `this` = the clip's `dynamic_props` ASObject: `typeof this == "object"`,
   `this._name == undefined`, and every MovieClip method call on `this` is a no-op. Corpus-wide, not
   hitArea-specific; candidate canaries are the `avm1/virtual_property*` family.
3. **No AVM1 mouse-wheel path at all** (§5). Beyond `edittext_onscroller`, AVM1
   `TextField.mouseWheelEnabled` and wheel-scrolling of input fields are simply absent in every AVM1
   build; games that scroll text with the wheel cannot work in the browser build either.
4. **`actionMCMouseInsidePick` and `tag.c`'s DefineButton hover loop ignore `hitArea`** (carried from
   s18 §6.3, still open) — and they are also the second hover state machine that any topmost-pick
   work (G5) has to reconcile.
5. **`_droptarget` has no shape hit test** (§2.1 D): `actionFindDynamicDropTarget` is AABB-only over
   `child_mc_cache`, with no visibility check and no parent-order resolution, while
   `MovieClip.hitTest(x, y, true)` already carries a full shape tester (drawing-API fills *and*
   line triangles, plus a `setMask` gate) inline in `action.c:72718`. Factoring that block into a
   reusable `mc_shape_hit_point_ng(mc, x_twips, y_twips)` is the enabling refactor for D, for G5 and
   for the `hitarea_sweep` mask rules — worth doing once rather than three times.
