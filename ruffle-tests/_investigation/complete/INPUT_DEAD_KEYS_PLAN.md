# Input Dead Keys (Windows) Plan
<!-- TESTS: input_dead_keys_windows -->

Last updated: 2026-03-13

## Status: COMPLETE — 1/1 tests passing (15/15 lines)

### Test Summary

| Test | Expected | Match | Status |
|------|----------|-------|--------|
| `input_dead_keys_windows` | 15 | 15/15 (100%) | PASS |

---

## What the Test Does

Tests Windows dead key behavior with a focused text field. The `input.json` simulates:
1. Press Shift+`"` (the double-quote dead key, physical key code 222)
2. Press `a` — dead key composition: `"` + `a` = `ä` (TextInput with codepoint U+00E4)
3. Press Shift+`"` again
4. Press `r` — no composed form exists, so two TextInput events: `"` then `r`

---

## Fixes Applied

### Fix 1: Key Code Mapping in `verify_output.py`

Added `CHAR_TO_KEYCODE` lookup table mapping shifted/punctuation `Char` values to their physical key codes (e.g., `'"'` → 222 for Quote key). This fixes `ruffle_key_to_flash_code()` which was returning ASCII values (e.g., 34) instead of physical key codes.

### Fix 2: `Key.getCode()` during `onKeyUp`

Updated `EV_KEY_UP` handler in `swf_core.c` to set `last_key_down` and `last_key_ascii` before dispatching keyUp events. Previously `Key.getCode()` during `onKeyUp` returned the code of the last KEY_DOWN, not the key being released.

### Fix 3: Dead Key Composition / TextInput Event Ordering

Added dead key composition logic to `EV_KEY_DOWN` handler in `swf_core.c`. For letter keys (A-Z), the handler peeks ahead at TEXT_INPUT events:

- **Pure composition** (dead key `"` + `a` = `ä`): TextInput codepoint doesn't match the pressed key → process TextInput immediately (insert + onChanged), suppress button keyPress entirely.
- **Dead key flush + raw key** (dead key `"` + `r` = `"` then `r`): non-matching TextInput (dead key flush `"`) processed immediately, button keyPress fires normally, matching TextInput (`r`) suppressed by `g_key_press_consumed`.
- **Normal keys** (non-letter keys like Enter, Space, Tab): always use normal keyPress dispatch regardless of TextInput codepoint mismatch.
