# Tab Ordering Implementation Plan
<!-- TESTS: tab_ordering_automatic_basic, tab_ordering_automatic_order_grid, tab_ordering_automatic_order_same_position, tab_ordering_children, tab_ordering_custom_basic, tab_ordering_custom_duplicate_index, tab_ordering_custom_i32_vs_u32, tab_ordering_custom_m1, tab_ordering_events, tab_ordering_events_mouse, tab_ordering_movieclip_enabled_default, tab_ordering_reverse, tab_ordering_tabbable, edittext_tab_focus, focusrect_swf5, focusrect_swf6 -->

<!-- PLAN_META
id: TAB_ORDERING
status: complete
dependencies:
  - plan: FOCUS_SYSTEM
    type: requires
    reason: "Tab ordering depends on focus management system"
blockers: []
-->

Last updated: 2026-03-07

## Status: COMPLETE — 16/16 PASS

### Results Summary

| Test | Status | Lines |
|------|--------|-------|
| `tab_ordering_automatic_basic` | **PASS** ✅ | all |
| `tab_ordering_automatic_order_grid` | **PASS** ✅ | all |
| `tab_ordering_automatic_order_same_position` | **PASS** ✅ | 12/12 (fixed by MOUSE_EVENTS_ADVANCED Phase 5: highlight bounds) |
| `tab_ordering_children` | **PASS** ✅ | all |
| `tab_ordering_custom_basic` | **PASS** ✅ | all |
| `tab_ordering_custom_duplicate_index` | **PASS** ✅ | all |
| `tab_ordering_custom_i32_vs_u32` | **PASS** ✅ | all |
| `tab_ordering_custom_m1` | **PASS** ✅ | all |
| `tab_ordering_events` | **PASS** ✅ | 150/150 |
| `tab_ordering_events_mouse` | **PASS** ✅ | 65/65 (fixed by MOUSE_EVENTS_ADVANCED Phase 2: roll dispatch) |
| `tab_ordering_movieclip_enabled_default` | **PASS** ✅ | 462/462 |
| `tab_ordering_reverse` | **PASS** ✅ | all |
| `tab_ordering_tabbable` | **PASS** ✅ | 47/47 |
| `edittext_tab_focus` | **PASS** ✅ | 13/13 (replaceSel + caret tracking now working) |
| `focusrect_swf5` | **PASS** ✅ | all |
| `focusrect_swf6` | **PASS** ✅ | all |

### Changes Made (this session)

1. **Dynamic text field tabbability** (commit b88bd40e): Dynamic text fields (type="dynamic") are never tabbable. Check runtime type property (u16 pointer comparison) before SWF ReadOnly flags.

2. **MC button mode implicit tabbability** (commit b88bd40e): MCs with mouse handlers (onPress, onRelease, onRollOver, onRollOut, onDragOut, onDragOver, onReleaseOutside) are implicitly tabbable (Flash "button mode").

3. **Invisible parent children excluded** (commit b88bd40e): Added `mc->visible` check before recursing into sprite children in `tab_collect_recursive()`.

4. **Button DoAction rollOver/rollOut during Tab** (commit 42661d7e): Button DoAction conditions (0x0001=rollOver, 0x0002=rollOut) now fire during Tab focus changes. DoAction fires BEFORE AS2 onRollOver/onRollOut handlers.

5. **Text field exclusions during Tab focus** (commit 42661d7e): EditText fields excluded from rollOver/rollOut, onKeyDown/onKeyUp, and simulated press/release during Tab focus changes (matching Flash behavior).

6. **Deferred rollOver/rollOut queue** (commit 42661d7e): Selection.setFocus() queues rollOver/rollOut events that fire asynchronously after script completes. Queue flushed after frame scripts and between input events.

### Previously Blocked (Now Resolved)

**tab_ordering_automatic_order_same_position (12/12 PASS):**
- Fixed by MOUSE_EVENTS_ADVANCED Phase 5: highlight bounds computation for tab ordering sort key.

**tab_ordering_events_mouse (65/65 PASS):**
- Fixed by MOUSE_EVENTS_ADVANCED Phase 2: roll dispatch + mouse button state interaction with Tab focus.

**edittext_tab_focus (13/13 PASS):**
- replaceSel and caret position tracking now working.

---

## Key Architecture Notes

### Tab Focus Event Order (synchronous, during Tab)
1. button DoAction rollOut (0x0002) on old — if old is button MC
2. AS2 onRollOut on old — if old is NOT text field
3. button DoAction rollOver (0x0001) on new — if new is button MC
4. AS2 onRollOver on new — if new is NOT text field
5. old.onKillFocus → new.onSetFocus → Selection.broadcastMessage("onSetFocus")

### Selection.setFocus() Event Order (asynchronous)
- onKillFocus/onSetFocus fire immediately (synchronous)
- rollOver/rollOut events are queued and fire after script completes
- Text fields excluded from rollOver/rollOut dispatch
- Queue flushed in swf_core.c: after frame scripts and between input events

### Text Field Behavior During Tab Focus
- Text fields do NOT receive onKeyDown/onKeyUp dispatch
- Text fields do NOT participate in rollOver/rollOut dispatch
- Text fields do NOT receive simulated press/release from Enter/Space
- Input text fields are tabbable by default; dynamic text fields are NEVER tabbable
