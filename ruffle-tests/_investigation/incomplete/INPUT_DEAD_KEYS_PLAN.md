# Input Dead Keys (Windows) Plan
<!-- TESTS: input_dead_keys_windows -->

Last updated: 2026-03-12

## Status: INCOMPLETE — 0/1 tests passing

### Test Summary

| Test | Expected | Match | Issue |
|------|----------|-------|-------|
| `input_dead_keys_windows` | 15 | 6/15 (40%) | Key code mapping + dead key composition |

---

## What the Test Does

Tests Windows dead key behavior with a focused text field. The `input.json` simulates:
1. Press Shift+`"` (the double-quote dead key, physical key code 222)
2. Press `a` — dead key composition: `"` + `a` = `ä` (TextInput with codepoint U+00E4)
3. Press Shift+`"` again
4. Press `r` — no composed form exists, so two TextInput events: `"` then `r`

The test has:
- A `Key` listener tracing `keyDown`/`keyUp` with `Key.getCode()`
- A button with onKeyDown/onKeyUp/onPress/onRelease handlers
- A text field with `onChanged` handler tracing text content
- `Selection.setFocus(text)` to focus the text field

---

## Issue 1: Key Code Mapping in `verify_output.py`

**Problem**: The `ruffle_key_to_flash_code()` function in `verify_output.py` (line ~82) maps `{"Char": "\""}` to `ord('"') = 34`. But Flash's `Key.getCode()` returns **physical key codes** (like JavaScript's `event.keyCode`), not ASCII. The `"` character is typed via Shift+Quote, and the Quote key's Flash code is **222**.

**Fix**: Add a lookup table in `verify_output.py` for punctuation `Char` values that maps them to their physical key equivalents:

```python
CHAR_TO_KEYCODE = {
    '"': 222,   # Shift+Quote → Quote key
    "'": 222,   # Quote key
    '!': 49,    # Shift+1
    '@': 50,    # Shift+2
    '#': 51,    # Shift+3
    # ... etc for other shifted characters
}
```

This is a test infrastructure fix, not a runtime fix.

---

## Issue 2: Dead Key Composition / TextInput Events

**Problem**: The test expects dead key composition behavior:
- Dead key `"` + `a` → single TextInput `ä` → `onChanged` fires with `ä`
- Dead key `"` + `r` (no composed form) → two TextInputs: `"` then `r` → `onChanged` fires with accumulated text

**Current**: No dead key composition logic exists. The `TextInput` events from `input.json` should already provide the composed characters directly (they contain the codepoint), but the ordering between `onChanged`, button `onKeyDown`/`onKeyUp`, and `onPress` may be wrong.

**Root cause details**:
- Line 6: expected `text.onChanged ä` but we produce `keyPress a` (button keyPress fires instead of text field onChanged)
- Lines 13-14: expected `text.onChanged ä"` then `keyPress r` but we get reversed order

The `TextInput` event type in input.json should insert text into the focused text field and fire `onChanged`. The `g_key_press_consumed` gating may need to suppress button keyPress when a TextInput was processed.

**Fix**:
1. Ensure `TextInput` events insert the codepoint into the focused text field and fire `onChanged`
2. When a `TextInput` event is processed, set `g_key_press_consumed = 1` to prevent button keyPress from also firing
3. `onChanged` should fire BEFORE the next key event in the sequence

---

## Implementation Order

1. **Key code mapping table** (Issue 1) — fix in `verify_output.py`, straightforward
2. **TextInput → onChanged ordering** (Issue 2) — ensure TextInput inserts into focused text field and suppresses duplicate button keyPress

Issue 1 is a quick test infrastructure fix. Issue 2 requires understanding the TextInput event processing path in the runtime.

---

## Estimated Impact

With both issues fixed, most of the 15 expected lines should match. The key code fix alone won't gain many lines (wrong codes cascade), but combined with correct TextInput handling, the test should pass or be very close.
