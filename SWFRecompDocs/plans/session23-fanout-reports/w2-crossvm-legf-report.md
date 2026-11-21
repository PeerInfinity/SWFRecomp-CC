# w2-crossvm-legf — session 23 wave 2: cross-VM focus, leg F

New files on this branch:

    SWFRecompDocs/plans/session23-fanout-reports/w2-crossvm-legf-report.md
    SWFRecompDocs/plans/session23-fanout-reports/w2-crossvm-legf.patch

There are no new source files, fixtures or canary-list entries. The patch edits two existing TUs:
`SWFModernRuntime/src/actionmodern/action.c` and `SWFModernRuntime/src/avm2/avm2_display.c`.

Setup: `SETUP_STATUS` all OK (apt, Pillow, Dawn). The corpus came from `download_tests.sh avm2 mixed_avm avm1`
(upstream master on 2026-11-21; the blobless Ruffle clone made at the same time is at `0ddd12b6a`). Base is
origin/master `ad99dc15`. Every A/B below was run on this box: clean origin/master vs. the patch, `--mode=graphics
--verbose` unless it says NG (no-graphics).

## 0. Verdict: GO, +2 pass, both modes

| row | before (graphics) | after (graphics) | before NG | after NG |
|---|---|---|---|---|
| `avm2/focus_events_mixed_avm_edittext` | output_mismatch (31/49 LCS, 12/49 indexed) | **pass 49/49** | output_mismatch | **pass** |
| `avm2/selection_onsetfocus_mixed_avm` | output_mismatch (0/5, emits nothing) | **pass 5/5** | output_mismatch | **pass** |

Dispositions checked. Neither row has `known_failure`, and neither has `output.ruffle.txt` (each `test.toml` is
`num_ticks = 3` only). Neither row appears in `ignored_tests.txt` or the four `_investigation` disposition docs; s21
already showed that the RVF mention was a grep hit, not a disposition. So `output.txt` is Flash's output, Ruffle
matches it, and so do we now.

### EXPECTED-FLIP LEDGER (for the coordinator's CI check)

| test | axis | expected CI move |
|---|---|---|
| `avm2/focus_events_mixed_avm_edittext` | trace | output_mismatch → **pass** (graphics and no-graphics) |
| `avm2/selection_onsetfocus_mixed_avm` | trace | output_mismatch → **pass** (graphics and no-graphics) |
| — | pixel | **none**. Neither row has `[image_comparisons]`, and the 18-row targeted render canary is 65/65 md5-identical. |

Nothing else should move. Any other trace or pixel change in CI is a regression from this patch.

## 1. Mechanisms: what landed, and per-mechanism line movement

Ruffle keeps **one** focus slot for both VMs (`core/src/focus_tracker.rs`, `FocusTracker.focus:
Option<InteractiveObject>`). We have two: AVM2 `g_stage_focus` (`avm2_display.c`) and AVM1 `g_focused_mc` (`action.c`).
The patch makes them behave as one slot under an AVM2 root with an AVM1 child. At most one half is set at a time,
and the AVM2 side drives every change through header-free seams, like the existing AVM1-under-AVM2 ones. Everything
new is gated on `g_avm1_child_levels != 0` (AVM2 side) or `g_avm1_under_avm2_ready` (AVM1 side). Pure AVM2 and pure
AVM1 therefore run the old code paths, apart from the two pure refactors listed in §1.4.

Ablation on one build: two temporary env gates, removed before delivery. The delivered source is byte-identical to
the A/B'd patch.

| configuration | `focus_events` LCS | `selection_onsetfocus` LCS |
|---|---|---|
| origin/master | 31/49 | 0/5 |
| F-slot only (no null/null broadcast, no AVM1 tab entries) | 35/49 | 0/5 |
| + F-bcast | 40/49 | 3/5 |
| + F-tab (= patch) | **49/49** | **5/5** |
| patch minus F-bcast | 44/49 | 2/5 |

The brief's estimates were F-bcast ~7, F-slot ~6 and F-tab ~9. Measured: F-bcast +5 (it is exactly the five
`Selection.onSetFocus: undefined undefined` lines 2/5/20/31/34), F-slot +4 (the ordering and suppression lines), and
F-tab +9. The shapes are as briefed. **F-scope is REFUTED (§2).**

### 1.1 F-slot: unified set_internal (`avm2_display.c`)
- `set_focus` becomes a wrapper over the new `set_focus_x(ctx, new_avm2, new_avm1, by_mouse)`, which is Ruffle
  `FocusTracker::set_internal` over the shared slot. Its early-out is "both halves unchanged". It runs the AVM1 half
  first (`actionAvm1UnderAvm2FocusChange`: the AVM1 `onKillFocus`/`onSetFocus` handlers, then the Selection
  broadcast) and the AVM2 `focusOut`/`focusIn` after. Ruffle's comment: "AVM2's focus events shouldn't fire yet, as
  that only happens after all of AVM1's focus handlers have been fired". An AVM1 object crosses into
  `relatedObject` as null.
- `update_focus_on_press` is Ruffle `update_focus_on_mouse_press` + `set_by_mouse` over both halves. On an AVM1 pick
  (`PICK_IS_AVM1`), the pressed object is the AVM1 click-focus candidate (`actionAvm1UnderAvm2FocusCandidate`, the
  existing AVM1 scan). should_focus = its `is_focusable_by_mouse`, which is a selectable or editable AVM1 text
  field (`mc_is_focusable_by_click`). Clearing a mouse-acquired focus now also covers an AVM1-held focus.
- `dispatch_focus_change_event` target rule (focus_tracker.rs): the old focus's AVM2 object. An **AVM1 old focus
  dispatches nothing**; with no focus, the Stage stands in only when the new object is AVM2 or nothing. This is what
  removes the stray `mouseFocusChange: [object MovieClip]`, and what adds the `mouseFocusChange: null` that comes
  before the AVM1 events.
- `actionMouseAvm1ChildrenUnderAvm2` no longer runs AVM1 click focus after the AVM2 mouseDown (that decision is
  now made on the AVM2 side, before it). What is left of the step there is the caret placement, for presses the
  AVM2 pick handed to AVM1 (`avm1UnderAvm2ClickCaret`).

### 1.2 F-bcast (`action.c`)
`actionAvm1UnderAvm2FocusChange` broadcasts `Selection.onSetFocus(null, null)` for an AVM2-only change. This is
Ruffle `notify_system_listeners(..., "Selection", "onSetFocus", [old.object1_or_null, new.object1_or_null])`, which
runs on every focus change. The broadcast body is factored out of `selection_do_focus_change` into
`selection_broadcast_on_set_focus`; that is a pure refactor, and the AVM1 callers are unchanged.

### 1.3 F-tab (`avm2_display.c` + `action.c`)
`fill_tab_order` descends into an `AVM1Movie` child (`fill_tab_order_avm1`). The AVM1 side
(`actionAvm1UnderAvm2TabCollect`) runs the existing `tab_collect_recursive` over the level root's display list and
returns each object's global top-left and explicit tabIndex. The AVM2 side keys the object as `6*y + x` in twips,
adding the AVM1Movie's world translation. `TabEnt` gains an `avm1` half. `input_handle_tab` matches the current
focus on whichever half it carries, and `focus_change_by_key_x` applies the same dispatch-target rule
(`keyFocusChange` from an AVM1 focus dispatches nothing, and that gives the `keyFocusChange: null` →
`input_txt1.onSetFocus` sequence). Arrow-key navigation (`input_handle_navigate`) passes `with_avm1 = 0`, which keeps
it exactly as before. Ruffle's `navigate` would include AVM1 objects too, but no corpus row grades that (see leads).

### 1.4 Shared-code touch points (pure refactors)
- `mouse_click_focus_at` is split into `click_focus_scan` + the focus decision + `click_focus_place_caret`. It has
  the same statements in the same order. `actionMouseClickFocus` (the pure-AVM1 `swf_core.c` / `swf.c` path) is
  byte-for-byte behaviour-equal: the 5 avm1 canary rows that use `MouseDown` give identical NG results, and all 43
  avm1 canary rows give identical graphics results.
- `selection_do_focus_change` → `selection_broadcast_on_set_focus`, as above.
- No `swf_core.c`, `tag_stubs.c` or `#ifdef NO_GRAPHICS` arm was touched. NG was run anyway.

## 2. Refutation: F-scope ("system-listener root-scope quirk") does not exist

s21 (`w1-mixedavm-tail-report.md` §3) and s22 (`w1-crossvm-report.md` §3) priced a fourth mechanism for
`selection_onsetfocus`: "`txt` resolves to `undefined` inside the listener" because Ruffle's
`notify_system_listeners` runs with `active_clip` = the AVM2 root. **The branch polarity was misread.** Our recompiled
child (`_child_avm1/RecompiledScripts/script_defs.c`, `func2_onSetFocus_0`) is:

```
push oldf; push txt; GetVariable; Equals2; Duplicate; If -> L25; Pop;
push newf; push txt; GetVariable; Equals2;
L25: Not; If -> L36; push undefined; Return;
L36: trace(oldf + " " + newf)
```

That is `if (oldf == txt || newf == txt) return; trace(oldf + " " + newf);`. The source **suppresses** the
txt-involved changes and **traces** the AVM2-only ones, so the oracle output (3× `null null`, nothing for the txt
changes) **requires `txt` to resolve to the field**. If it resolved to `undefined`, `null == undefined` would return
early on every AVM2-only change, and the row would print only the two `txt.*` handler lines. Measured on our build
with a temporary probe: `txt` resolves to the TextField (type 14, the same pointer as the broadcast's `new`), and the
`Equals2` operands are `(field, null)` for the AVM2-only changes and `(field, field)` for the txt ones. The row
passes with **no** scope change. The s21 oracle patch ("return patched out → 7 lines") is consistent with this
reading too: removing the `return` makes every change trace. The s21 lead "Ruffle system-listener scope quirk
(probe it with a pure-AVM1 fixture)" should be **struck**. There is no evidence for it.

## 3. Canary and regression results

**Trace canary** (graphics, `-P 2`, 102 rows): every `mixed_avm/*` (12), `avm2/*focus*|*mouse_pick*|*tab*` (42
including the two headline rows), `avm1/*focus*|*selection*|*tab*` (43), and the `regression/` rows that mention
focus/selection/mouse (`avm2_child_simplebutton`, `avm2_simplebutton_click`, `broadcast_type1_args`,
`mc_event_cross_swf_version`, `mc_event_type1_args`). Compared on (status, matching, expected, actual lines):

- **100/102 identical.** The 2 differences are exactly the ledger:
  `focus_events_mixed_avm_edittext` `(output_mismatch,12,49,47) → (pass,49,49,49)` and
  `selection_onsetfocus_mixed_avm` `(output_mismatch,0,5,0) → (pass,5,5,5)`.
- Before: 96 pass, 3 ruffle_matched, 3 output_mismatch. After: 98 pass, 3 ruffle_matched, 1 output_mismatch.
  The unchanged non-passes are `mixed_avm/avm1_loads_avm2` (NO-GO of record), the KF rows
  `mixed_avm/avm2_loads_avm1_events`, `avm2/edittext_tab_stops` and `avm1/tab_ordering_properties_tab_index_edge_case`
  (all ruffle_matched before and after).
- Neighbours of note, unchanged: `avm2/focus_events_mixed_key_mouse`, `avm2/mouse_pick_loader_avm1` (s22's M-clickfocus
  row) and every `avm2/tab_ordering_*` row.

**NG parity:** 4 rows (both headline rows, `focus_events_mixed_key_mouse`, `mouse_pick_loader_avm1`): before
fail/pass/pass/fail → after pass/pass/pass/pass. The 5 avm1 MouseDown canary rows in NG are identical before and after.

**Render canary** (`render_canary.py capture/compare`, `-P 2`, md5). The standing 501-row list needs suites this slot
did not download, and almost all of it cannot see this change class, so a targeted set was used: every canary row
with `[image_comparisons]` (`avm1/focusrect_*` ×5, `avm2/focus_root_movie`, `avm2/focus_stage`, `avm2/focusrect`,
`avm2/focusrect_focuslost`, `avm2/mouse_pick_*mask*` ×3, `avm1/define_font_glyph_table_*` ×2), plus every
avm1/avm2 row with both `[image_comparisons]` and a `MouseDown` input (`avm1/frame_size_translated_*` ×2,
`avm1/mouse_events_visible_enabled`, `avm2/stage_scale_factor`). The two Stage3D demos were dropped for cost.
**18 tests, 65 PNGs: IDENTICAL 65, DIFFERS 0, no trace/image status change.** No `render_canary_tests.txt` entry
was added. No mixed_avm row carries `[image_comparisons]` (s22 noted the same), so the standing list cannot
see this class, and no corpus row exists that would.

**Regression suite:** all 5 focus/mouse-adjacent `regression/` rows pass before and after. No new fixture: the two
headline rows are Flash-oracle corpus coverage for exactly this behaviour.

## 4. Risk register
- **Shared slot vs. AVM1 `Selection.setFocus`.** AVM1 script can still set `g_focused_mc` while `g_stage_focus` is
  set (two halves at once). The next AVM2-driven change clears both, as Ruffle's single slot would. No corpus row
  does this.
- **AVM1 roll events on Tab under AVM2.** The key path deliberately does not queue AVM1 rollOut/rollOver. Ruffle's
  `roll_over` bails when the hovered object or the new focus is AVM2, which is the common mixed shape, and our
  AVM1 hover state cannot tell the two apart. No corpus row grades it.
- **`tab_collect_recursive` writes `mc->x/mc->y`** (sort keys) for the AVM1 clips it visits. This is pre-existing
  pure-AVM1 Tab behaviour, now also reached from AVM2 Tab when an AVM1 child exists. The AVM1Movie's root is
  assumed to have identity scale (this matches the existing pick/mouse seams, which also pass stage pixels
  unmapped).
- Only the first AVM1 child is walked (`g_avm1u2[0]`, the same one-child limit as every existing bridge).

## 5. Not done / out of scope (with completion mechanism)
- **Arrow-key navigation into AVM1 objects** (Ruffle `FocusTracker::navigate` uses the same `TabOrder::fill`).
  `with_avm1 = 0` keeps it as before. Completion: pass `1` in `input_handle_navigate` and give AVM1 entries
  highlight bounds (`obj_highlight_bounds` needs an AVM1 arm). It has no observer today.
- **Multiple AVM1 children**: see §4. It needs the per-child swap that every bridge lacks.

## 6. New unclaimed leads
- **Strike the s21 "system-listener scope quirk" lead** (§2). Nothing needs probing.
- `TabOrder::fill` for **AVM1 roots with a non-identity Loader transform**: the keys add only the AVM1Movie's world
  translation. A scaled Loader would mis-order. There is no observer.

## LOCAL ORACLE REQUESTS

None.
