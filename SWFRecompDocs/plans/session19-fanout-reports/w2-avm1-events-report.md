# w2-avm1-events — wave-2 implementation report

Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-aa2477bb253c4c74d`, branched at
`e36bca73e`. No commits, no pushes. All runs single-test, `SWFRECOMP_COMPILE_TIMEOUT=2400`,
two sequential streams (never more than 2 concurrent). Logs:
`<scratchpad>/w2-avm1-events/` (`{A,B,C,D,E,F}_*.log`, `*.summary`).

## 0. Deliverables

| File | Contents |
|---|---|
| `w2-avm1-events.patch` | G1 + G2 + G3 (`action.c`, `swf_core.c`, `input_events.c`) |
| `w2-avm1-events-2-scopectx.patch` | G4 only (`action.c`, 2 sites) |
| `w2-avm1-events-report.md` | this file |

**New files (untracked — stage by name):**
- `ruffle-tests/tests/swfs/regression/ctor_before_first_call_locals/` —
  `create_test_swf.py`, `test.swf`, `test.toml`, `output.txt`.
  Belongs with **patch 2**; expected output is the **Ruffle exporter's** trace
  (`~/CC/ruffle/target/release/exporter --trace-log`), not ours.
  Because a patch cannot carry untracked files, the four files are also copied to
  `SWFRecompDocs/plans/session19-fanout-reports/w2-avm1-events-2-fixture/` in the MAIN tree
  (see its `PLACEMENT.txt`); move them to the path above before staging. They also exist in
  place in the worktree at
  `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-aa2477bb253c4c74d/ruffle-tests/tests/swfs/regression/ctor_before_first_call_locals/`.

Both patches reverse-apply cleanly and are independent (disjoint hunks); apply patch 1 then
patch 2, or either alone.

## 1. Verdicts

| Item | Verdict | Result |
|---|---|---|
| **G1** `MovieClip.prototype` fall-back in MC event dispatch | **DONE, +1 effective** | `from_gnash/misc-ming.all/PrototypeEventListeners` `output_mismatch` (1/32, act 12) → **`ruffle_matched`** |
| **G2** AVM1 mouse wheel → TextField `scroll` + `onScroller` | **DONE, +1 effective** | `avm1/edittext_onscroller` `output_mismatch` (0/14, act 0) → **`ruffle_matched`** |
| **G3** `nextFrame()` from a broadcaster callback on a stopped root | **DONE, 0 flips — unblocked, priced honestly** | `from_gnash/misc-ming.all/masks_test` 28/175 → **124/175**, still `output_mismatch`. 48 real mask assertions now run for the first time and 34 of them fail. **No flip.** |
| **G4** NULL `g_scope_app_context` drops a constructor local | **DONE, 0 flips (as briefed) — defect fixed + fixture** | new `regression/ctor_before_first_call_locals` fail→**pass**; `action_order` rows unchanged (0 flips), and their `heap_alloc() called before heap_init()` stderr is gone |

**Net score: +2 effective** (both `output_mismatch → ruffle_matched`).
**Zero regressions** across 53 sweep tests + the full 93-test `regression` suite + 7 `action_order`
rows + `from_shumway/avm1/doactionorder`.
**Mode parity confirmed**: all four headline tests give byte-identical verdicts under
`--mode=graphics` and no-graphics.

## 2. G1 — `PrototypeEventListeners` (GO confirmed, with one correction to the brief)

The wave-1 mechanism is right: `mc_call_as2_handler_ng` looked the handler up only through
`mc->dynamic_props`'s `__proto__` chain, which for a plain timeline / `createEmptyMovieClip` clip
does not reach `MovieClip.prototype`. Patch adds the same fall-back
`actionDispatchMCOnConstruct` already uses (`getMovieClipPrototype(mc_ver)`, function values only).

**Correction — the ~6-line fix is not sufficient.** With only the prototype fall-back the test went
from 1/32 to 22/32 but stayed `output_mismatch`: `_level0.Dejagnu` never fired. The second half of
the defect is the `mc->dynamic_props == NULL` guard in the *dispatchers*
(`actionDispatchMCMouseDown` / `…MouseUp` / `…MouseMoveGlobal`) — a clip that has never had a
dynamic property written skips dispatch entirely, which is exactly the clip the fall-back exists
for. Both halves are required; neither flips alone. `mc_call_as2_handler_ng`'s own
`mc->dynamic_props == NULL` early-out was relaxed for the same reason.

Grading is against `output.fp11.txt` with `output.fp11.ruffle.txt` as the oracle; we now emit
Ruffle's four prototype dispatches in reverse-creation order (`clip2`, `clip1`,
`Dejagnu.instance1`, `Dejagnu`) and, like Ruffle, **not** Flash's extra `_global.onMouseDown`.
Our diff set is a subset of Ruffle's → `ruffle_matched`.

**Deliberately NOT widened:** the *hit-test* dispatchers (`actionDispatchMCPress`,
`…MCRelease`, `actionDispatchMCMouseMove`'s roll pre-pass) keep their `dynamic_props == NULL`
guard. Flash would fire a prototype-installed `onPress` there too, but nothing on the board needs
it and those are the highest-blast-radius loops on this file. Listed as a lead in §7.

## 3. G2 — `avm1/edittext_onscroller` (GO confirmed exactly as priced)

Two gaps, both closed:

1. `EV_MOUSE_WHEEL` was parsed and then dropped — **no `case` in either AVM1 pump**. Added to
   `swf_core.c` (no-graphics) *and* `input_events.c` (graphics/OFFSCREEN_RENDER); they are separate
   copies of the same switch. AVM2 has its own pump in `avm2_display.c`, untouched.
2. New `actionDispatchMouseWheel(app_context, lines)` in `action.c` mirrors Ruffle:
   `Mouse.onMouseWheel(lines)` broadcast (`player.rs:1276`), then the topmost TextField under the
   pointer gets `scroll = clamp(scroll − lines, 1, maxscroll)` and, **only if the value changed**,
   `onScroller(field)` (`edit_text.rs:3009` + `:2142`, `programmatic = false`).

The brief's "no clamping is involved" held: the walk is 1→4→7→10→7→4→1 with `maxscroll` ≫ 10, so
`ng_computeScroll*` is not in the loop. The script-side `tf.scroll = 2; tf.scroll = 1` deliberately
fires **nothing** (Ruffle's `programmatic = true`); adding it would break the subset match.

Corpus blast radius is exactly two tests: this one, and the image-only
`visual/cache_as_bitmap/edittext_scroll` (no trace output; its render will now actually scroll —
an expected image change, and image comparisons do not gate pass/fail).

## 4. G3 — `masks_test` (GO on the mechanism; **the flip is 0**, and here is where it lands)

Mechanism confirmed exactly. A `Key.addListener` callback goes through
`builtin_broadcaster_broadcastMessage`, never `mc_call_as2_handler_ng`, so neither
`g_inside_event_handler` nor `g_inside_enterframe_dispatch` is set; on a **stopped** root
`actionNextFrame`'s default deferred form is then eaten at end-of-tick and the target frame's tags
and DoAction never run. Fix: a new `g_inside_broadcaster_dispatch` counter bracketing the five
broadcaster dispatchers, ORed into `actionNextFrame`'s existing stopped-root deferred-goto arm
(the arm already used by the `onEnterFrame` entrance). Read in exactly one place, so the blast
radius is `actionNextFrame` only. I did **not** take the alternative of bracketing
`g_inside_event_handler` — that would have routed broadcaster callbacks into the *inline*
`ng_executeGotoCatchUp` arm, a much larger behaviour change.

**Where it lands (measured, both modes):** `28/175 matching → 124/175`, 51 diff lines,
`#passed: 106 / #failed: 48` (was: test never got past `- Press any key to continue -`).
Status stays `output_mismatch`.

**Distance to `ruffle_matched`, computed not guessed.** Ruffle's own diff set against
`output.txt` is 16 line indices, all in 141–174 (1-based). Our 50 differing lines include **34 that
Ruffle gets right**: 44 45 50 51 60 61 64 65 83 84 87 88 99 100 103 104 123 124 127 128 131 132
135 136 139 140 143 145 147 148 157 160 167 169. Every one of them is a mask-semantics assertion of
the form `staticmcN.hitTest(x, y, false)` / `dynamicmcN.hitTest(x, y, true)` on a clip that is a
mask or is masked — i.e. **the next owner of this row is a hit-test/mask agent, not an events
agent.** It is not reachable by any further work in my brief.

## 5. G4 — the NULL-context defect (separate patch)

Confirmed and reproduced from first principles. `setVariableOnLocalScope` allocates the property
name through `setProperty(g_scope_app_context, …)`; that static is latched only by
`actionCallFunction` / `actionCallMethod` / `actionNewMethod`. `actionNewObject` never latched it,
so when the first user code in a movie is a `new`-invoked constructor, `heap_alloc(NULL, …)` fails
and `object.c` **silently drops the property** — the constructor's named parameters read back as
`undefined`. Two sites patched: `actionNewObject` (mirrors `actionNewMethod`) and a
latch-if-NULL in `ensureGlobalInit` so no future entry point can reintroduce the hole.

**Correction to the s18 lead's label:** the stderr is `heap_alloc() called before heap_init()`, but
the heap is initialised — the guard that fires is `app_context == NULL`. The message is misleading
and cost a session; noted here rather than changed (changing it is a one-liner someone else owns).

**Fixture** `regression/ctor_before_first_call_locals` (hand-assembled v8, `DefineFunction2` with
the parameter in register 0 so the prologue goes through `setVariableByName`):

```
p=A      <- fail-before: "p=undefined", plus 2x "ERROR: Failed to allocate property name"
v=L
q=B      } control rows: an ordinary call latches the static, so these always worked
w=M      }
done
```

Expected output is the **Ruffle exporter's** `--trace-log`, not ours.

**Gotcha worth carrying forward:** the exporter refuses every existing `regression/`
hand-assembled SWF (`Texture target cannot be smaller than 1 … (requested 0 x 400)`). The shared
`rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])` literal copied across those
generators encodes `x_max` with its **top bit set**, and Ruffle's `read_rect` reads RECT fields as
*signed*, so a 1600px stage decodes as width 0. My generator ships a `make_rect()` that reserves a
sign bit. Anyone who wants an exporter oracle for an existing `regression/` fixture must fix its
rect first.

**Flip count: 0**, as briefed. The three `action_order` rows are byte-for-byte unchanged
(`action_execution_order_test11` still has the same 8/9 `mc21 onLoad` ↔ `mc1 onEnterFrame` swap and
the same `0+2+1+3+4+5+`); the only observable change is that the stderr errors are gone.

## 6. Tests run — ledger

Baseline for "before" is the wave-0 inventory (`wave0-trace-inventory.txt`, graphics run
34645805030): a test absent from it was passing. Every non-PASS below was verified to reproduce the
inventory's exact `match/expected act=` signature.

**Headlines (both modes, streams E/F — identical):**

| test | before | after |
|---|---|---|
| `from_gnash/misc-ming.all/PrototypeEventListeners` | output_mismatch 1/32 act=12 | **ruffle_matched** |
| `avm1/edittext_onscroller` | output_mismatch 0/14 act=0 | **ruffle_matched** |
| `from_gnash/misc-ming.all/masks_test` | output_mismatch 28/175 act=28 | output_mismatch **124/175 act=175** |
| `regression/ctor_before_first_call_locals` (new) | output_mismatch (1 line) | **pass** |

**G1 blast-radius sweep (53 tests, streams A/B) — all unchanged:**

PASS, before and after: `avm1/` `mouse_events`, `mouse_listeners`, `mouse_events_visible_enabled`,
`mouse_pos`, `mouse_hover_events_while_dragging`, `mouse_wheel_enabled`, `button_children`,
`button_order`, `button_v5`, `button_v6`, `button_properties_special_cases`, `button_key_events`,
`hitarea_remove_sibling`, `hitarea_lazy_getter`, `drag_drop`, `drag_over_from_outside`,
`drag_over_without_startdrag`, `movieclip_hittest`, `focus_mouse`, `focus_mouse_rollout`,
`as_broadcaster`, `as_broadcaster_initialize`, `register_class`, `root_button_mode`,
`nested_textfields_in_buttons`, `tab_ordering_events_mouse`, `movieclip_in_removed_button`,
`edittext_scroll`, `edittext_hscroll`; `from_gnash/misc-ming.all/` `RollOverOutTest`,
`ResolveEventsTest`, `event_handler_scope_test`; `from_gnash/actionscript.all/Function-v6`;
`from_shumway/avm1/` `mouse-transparency`, `nested-button`, `rollover`, `hitarea`;
`text/text_caret_placement_scroll`.

RUFFLE_MATCHED, before and after: `from_gnash/misc-ming.all/` `ButtonEventsTest`,
`ButtonPropertiesTest`, `DragDropTest`, `KeyEventOrder`, `key_event_test`;
`from_gnash/actionscript.all/` `MovieClip-v5`, `Object-v6`.

MISMATCH before **and** after, signature identical to the inventory:

| test | inventory | ours |
|---|---|---|
| `avm1/hitarea_sweep` | 3/33 act=37 | same 4 wrong lines (`owner invisible` spurious at 4, …) |
| `avm1/hitarea_remove_owner_drag` | 5/10 act=10 | same `rollover Z` before `rollover Rm` |
| `avm1/movieclip_hittest_shapeflag` (IGN, ACC) | 332/338 act=338 | 6 diff lines — exact match |
| `from_gnash/actionscript.all/MovieClip-v6` | 901/936 | 35 diff lines — exact match |
| `from_gnash/actionscript.all/MovieClip-v7` | 934/969 | 35 diff lines — exact match |
| `from_gnash/actionscript.all/MovieClip-v8` | 1020/1087 | 67 diff lines — exact match |
| `text/links_in_scrolled_text` | 0/1 act=0 | unchanged (wave-1 HOLD) |

`from_shumway/avm1/doactionorder` reported RECOMP_FAIL in stream B — that path is a **group
directory**, not a test. The two real tests under it (`doactionorder/doactionorder`,
`doactionorder/symbolclass`) were run in stream D and both **PASS**.

**`regression` suite in full (93 tests, streams C/D): 93/93 PASS**, including the new fixture.

**`action_order` family (G4's declared blast radius, stream C/D)** — `action_execution_order_test1`,
`_test2` PASS; `_test6` (20 act), `_test11` (32 act), `_extend_test` (28 act), `PlaceAndRemove`
(45 act), `ActionOrderTest3` (83 act) all MISMATCH with the inventory's exact actual-line counts.

## 7. Risks and residuals

1. **G1 is the real blast radius.** Every AVM1 clip now consults `MovieClip.prototype` for
   `onMouseDown` / `onMouseUp` / `onMouseMove` / `onPress` / `onRelease` / roll events / `onChanged`
   / `onScroller`, and the three global mouse dispatchers no longer skip clips with no
   `dynamic_props`. Nothing in the 53-test sweep or the regression suite moved, but a title that
   assigns `MovieClip.prototype.onMouseDown` now gets Flash's behaviour instead of silence — by
   design, and a behaviour change all the same.
2. **The fall-back uses `MovieClip.prototype` for TextField MCs too.** A TextField's real prototype
   is `TextField.prototype`; the fall-back would wrongly find a handler installed on
   `MovieClip.prototype`. Harmless today (nothing installs mouse handlers there in the corpus) but
   incorrect in principle.
3. `g_inside_broadcaster_dispatch` is a non-static int in `action.c`, matching the style of
   `g_inside_event_handler` next to it. Read in exactly one place (`actionNextFrame`).
4. G2's wheel pick is TextField-only and AABB-only (`mc_get_pixel_aabb_ng`), not Ruffle's
   `mouse_data.hovered`. Correct for every AVM1 wheel target that exists (no other AVM1 display
   object handles `ClipEvent::MouseWheel`), but it will not honour a shaped or occluded field.
5. `actionDispatchMouseWheel` has no display-list fallback for SWF-defined fields never touched by
   script (`actionMouseClickFocus` has one). A wheel over an untouched authored field is still a
   no-op.
6. Functions touched in `action.c` (for the sibling that also edits this file):
   `mc_call_as2_handler_ng`, `actionNextFrame`, `actionDispatchKeyDown`, `actionDispatchKeyUp`,
   `actionDispatchMouseDown`, `actionDispatchMouseUp`, `actionDispatchMouseMove`,
   `actionDispatchMCMouseDown`, `actionDispatchMCMouseUp`, `actionDispatchMCMouseMoveGlobal`,
   new `actionDispatchMouseWheel`; plus (patch 2) `actionNewObject`, `ensureGlobalInit`.
   One new file-scope global, `g_inside_broadcaster_dispatch`.

## 8. New unclaimed leads

1. **`masks_test`'s remaining 34 lines are a mask hit-test slice, fully enumerated in §4.** The row
   is now a clean, isolated target: `hitTest(x, y, false)` returns false where Flash returns true
   for a masked clip, and `hitTest(x, y, true)` disagrees on masked/mask clips. 34 lines to
   `ruffle_matched`, and the fixture grades static and dynamic clips identically, so one rule fixes
   pairs. Same family as wave-1's G4/B (`hitarea_sweep`'s `mask via hit`) — worth pricing together.
2. **The hit-test mouse dispatchers still skip clips with no `dynamic_props`** (§2). Same defect
   class G1 just closed for the global dispatchers; not exercised by anything on the s19 board.
3. **`heap_alloc() called before heap_init()` is the wrong message** for the `app_context == NULL`
   guard (§5). It has now mis-directed at least two sessions. One-line fix in `heap.c`.
4. **Every hand-assembled `regression/` SWF has an invalid header RECT** (§5) — Ruffle decodes the
   stage as 0px wide, so the Ruffle exporter cannot be used as an oracle on any of them without
   regenerating. Cheap to fix in bulk (the `make_rect()` helper is in the new fixture's generator);
   it would unlock exporter-oracled expected output for the whole suite.
5. **No AVM1 `TextField.mouseWheelEnabled` *setter* path was exercised.** The gate is read from
   the property, which we seed `true`; a title that sets it `false` is now honoured, but nothing in
   the corpus covers it.
