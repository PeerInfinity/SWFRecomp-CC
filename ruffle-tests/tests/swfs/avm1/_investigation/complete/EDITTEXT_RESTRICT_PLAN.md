# EditText Restrict Plan — COMPLETE

<!-- PLAN_META
id: EDITTEXT_RESTRICT
status: complete
phases:
  - id: 1
    name: "Pattern Tokenizer"
    status: complete
  - id: 2
    name: "Pattern Parser"
    status: complete
  - id: 3
    name: "Character Filter"
    status: complete
  - id: 4
    name: "Integration"
    status: complete
  - id: 5
    name: "Edge Cases"
    status: complete
dependencies:
  - plan: TEXTFIELD
    type: requires
    reason: "restrict property depends on TextField infrastructure"
blockers: []
-->

## Status: COMPLETE (2026-03-03)

**Test:** `edittext_restrict` — **191/191 PASS** (was 145/191)

## Changes Made

1. **Replaced `apply_restrict_filter()`** in `action.c` with proper pattern parser:
   - `restrict_parse_pattern()`: Single-pass parser handling ranges (`a-z`), negation (`^`), escapes (`\\-`), left-truncated ranges (`-b` = `\0`..`b`), inverted ranges (`z-a` = just `z`), multiple dashes, Unicode codepoint ranges
   - `restrict_filter_char()`: ASCII-only case conversion (a-z ↔ A-Z), matching Flash behavior
   - `restrict_utf8_decode()`/`restrict_utf8_encode()`: UTF-8 codepoint helpers for Unicode-aware processing

2. **Added restrict property setter coercion** in `actionSetMember` textfield handler:
   - `null`/`undefined` → stored as NULL (no restriction)
   - Empty string `""` → stored as NULL (no restriction)
   - Non-string types (boolean, number, object) → coerced to string via `convertString`
   - Non-empty strings → stored as-is

## Key Design Decisions

- **ASCII-only case conversion**: Flash only does a-z ↔ A-Z for restrict. Unicode case pairs (ą/Ą, δ/Δ) are NOT converted. Verified against all test patterns.
- **Interval-based allow/disallow lists**: Pattern parsed into `RestrictInterval` arrays (start/end codepoint pairs). Character is allowed if it appears in any allowed interval AND not in any disallowed interval.
- **Caret semantics**: First `^` with empty allow list → implicit allow-all `[0, 0x10FFFF]`. Subsequent carets flip between allow/disallow mode.
- **Dash semantics**: `-` at start (left-truncated) → range from `\0`. `-` at end (right-truncated) → just the left char. Multiple dashes → each pair flush/restart.

**Standalone feature** — no cross-plan dependencies. Self-contained in `action.c`.

---

## Flash restrict Syntax

### Pattern Grammar

| Syntax | Meaning | Example |
|--------|---------|---------|
| `abc` | Allow literal characters a, b, c | `"abc"` → only a, b, c allowed |
| `a-z` | Allow range a through z (inclusive, by Unicode code point) | `"a-z"` → lowercase letters |
| `A-Za-z0-9` | Multiple ranges | Alphanumeric |
| `^a-z` | Disallow a-z (allow everything else) | `"^a-z"` → no lowercase |
| `a-z^e` | Allow a-z, then disallow e | Result: a-d, f-z |
| `\\-` | Escaped literal hyphen | `"\\-"` → only hyphen allowed |
| `\\^` | Escaped literal caret | `"\\^"` → only caret allowed |
| `\\\\` | Escaped literal backslash | |
| `""` / null / undefined | No restriction (allow all) | |
| Non-string (false, 0, NaN, {}) | Restrict to nothing (block all) | |

### Key Behaviors

1. **Ranges use Unicode code points**: `A-z` includes characters 65-122 (A through z, including `[\]^_\``)
2. **Inverted ranges**: `z-a` collapses to just the first character (`z`)
3. **Left-truncated range**: `-z` means `\0` through `z`
4. **Right-truncated range**: `a-` means just `a` (no range)
5. **Lone `^`**: Allow all (negation with nothing to negate)
6. **Double `^^`**: Flip twice = allow all
7. **Case conversion**: If `a` is not allowed but `A` is, typing `a` produces `A`

### Case Conversion Rules

When a character is not directly in the allowed set:
1. Try the character as-is → if allowed, use it
2. Try uppercase version → if allowed, use uppercase
3. Try lowercase version → if allowed, use lowercase
4. Otherwise, reject the character

---

## Current Implementation (Broken)

`apply_restrict_filter()` (action.c ~line 38356):
- Treats the restrict string as a set of literal characters
- No range parsing (`a-z` is treated as 3 characters: 'a', '-', 'z')
- No negation (`^` is treated as a literal)
- No escape handling (`\\-` is treated as 3 characters)
- Naive case handling: lowercases both sides and compares
- No Unicode awareness (byte-level comparison)

This passes 147/191 lines because many test cases happen to work with literal matching (single characters, patterns where the literal chars overlap with what the test types).

---

## Phase 1: Pattern Tokenizer

**Goal:** Convert restrict string into a token stream.

### Token Types
```c
typedef enum {
    RESTRICT_TOKEN_CHAR,   // A literal character (possibly escaped)
    RESTRICT_TOKEN_RANGE,  // The '-' range operator
    RESTRICT_TOKEN_CARET,  // The '^' negation operator
} RestrictTokenType;

typedef struct {
    RestrictTokenType type;
    uint32_t codepoint;    // For CHAR tokens: the Unicode code point
} RestrictToken;
```

### Tokenization Rules

1. `\X` (backslash + any char) → `CHAR(X)` — escape
2. `\` at end of string → ignored (truncated escape)
3. `-` → `RANGE`
4. `^` → `CARET`
5. Any other character → `CHAR(c)`

### Implementation

```c
static int tokenize_restrict(const char* restrict_str, size_t restrict_len,
                              RestrictToken* tokens, int max_tokens) {
    int token_count = 0;
    size_t i = 0;
    while (i < restrict_len && token_count < max_tokens) {
        uint32_t cp;
        int cp_len = utf8_decode(&restrict_str[i], restrict_len - i, &cp);

        if (cp == '\\') {
            // Escape: consume next character
            i += cp_len;
            if (i >= restrict_len) break;  // Truncated escape
            cp_len = utf8_decode(&restrict_str[i], restrict_len - i, &cp);
            tokens[token_count++] = (RestrictToken){RESTRICT_TOKEN_CHAR, cp};
        } else if (cp == '-') {
            tokens[token_count++] = (RestrictToken){RESTRICT_TOKEN_RANGE, 0};
        } else if (cp == '^') {
            tokens[token_count++] = (RestrictToken){RESTRICT_TOKEN_CARET, 0};
        } else {
            tokens[token_count++] = (RestrictToken){RESTRICT_TOKEN_CHAR, cp};
        }
        i += cp_len;
    }
    return token_count;
}
```

### UTF-8 Helper

Need a `utf8_decode(const char* buf, size_t len, uint32_t* out)` function that reads one Unicode code point from UTF-8 and returns the byte length consumed. This may already exist in the codebase or need to be added.

---

## Phase 2: Pattern Parser

**Goal:** Parse token stream into allowed/disallowed interval lists.

### Data Structure

```c
typedef struct {
    uint32_t start;
    uint32_t end;   // Inclusive
} CharInterval;

typedef struct {
    CharInterval allowed[128];
    int allowed_count;
    CharInterval disallowed[128];
    int disallowed_count;
    int is_null;              // true = no restriction (allow all)
    int is_block_all;         // true = non-string value (block all)
} RestrictPattern;
```

### Parsing Algorithm

State machine with `now_allowing` flag:

```
initialize: now_allowing = true, last_char = NONE

for each token:
    CARET:
        if now_allowing && allowed_count == 0:
            // First caret with empty allow list: implicitly allow all
            add_interval(allowed, 0x0, 0x10FFFF)
        flip now_allowing

    CHAR(c):
        if last_char != NONE:
            // Not preceded by RANGE, just add last_char as single
            add_single(current_list, last_char)
        last_char = c

    RANGE:
        if last_char == NONE:
            // Left-truncated: range from 0x0
            last_char = 0x0
            // Next char will complete the range
            expect_range_end = true
            continue
        // Next token should be CHAR for range end
        // (handled on next CHAR token)
        expect_range_end = true
        continue

    // When processing CHAR after RANGE:
    if expect_range_end:
        if last_char <= c:
            add_interval(current_list, last_char, c)
        else:
            // Inverted range: just the first char
            add_single(current_list, last_char)
        last_char = NONE
        expect_range_end = false
    else:
        // Previous last_char was a standalone char
        if last_char != NONE:
            add_single(current_list, last_char)
        last_char = c

// End: flush remaining last_char
if last_char != NONE && !expect_range_end:
    add_single(current_list, last_char)
// Right-truncated range (a-): just add the char
if last_char != NONE && expect_range_end:
    add_single(current_list, last_char)
```

Where `current_list` is `allowed` when `now_allowing == true`, `disallowed` when false.

---

## Phase 3: Character Filter

**Goal:** Given a parsed pattern and an input character, return the allowed character (possibly case-converted) or reject.

### Algorithm

```c
static int char_in_intervals(uint32_t cp, const CharInterval* intervals, int count) {
    for (int i = 0; i < count; i++) {
        if (cp >= intervals[i].start && cp <= intervals[i].end)
            return 1;
    }
    return 0;
}

static int restrict_allows_char(const RestrictPattern* pat, uint32_t cp) {
    int in_allowed = char_in_intervals(cp, pat->allowed, pat->allowed_count);
    int in_disallowed = char_in_intervals(cp, pat->disallowed, pat->disallowed_count);
    return in_allowed && !in_disallowed;
}

// Returns the allowed version of cp, or 0 if rejected
static uint32_t restrict_filter_char(const RestrictPattern* pat, uint32_t cp) {
    if (pat->is_null) return cp;           // No restriction
    if (pat->is_block_all) return 0;       // Block all

    // Try as-is
    if (restrict_allows_char(pat, cp)) return cp;

    // Try uppercase
    uint32_t upper = unicode_to_upper(cp);
    if (upper != cp && restrict_allows_char(pat, upper)) return upper;

    // Try lowercase
    uint32_t lower = unicode_to_lower(cp);
    if (lower != cp && restrict_allows_char(pat, lower)) return lower;

    return 0;  // Rejected
}
```

### Unicode Case Conversion

The codebase already has `unicode_case_tables.h` with binary search lookup for upper→lower and lower→upper mappings. Use these for `unicode_to_upper()` / `unicode_to_lower()`.

---

## Phase 4: Integration

**Goal:** Replace the broken `apply_restrict_filter()` and integrate with TextField property handling.

### 4a. Restrict Property Storage

When `TextField.restrict` is set:

```c
// In TextField property setter:
case PROP_RESTRICT:
    if (value.type == ACTION_STACK_VALUE_STRING) {
        if (value.str_size == 0) {
            // Empty string = no restriction
            tf->restrict_pattern.is_null = 1;
        } else {
            parse_restrict_pattern(value.heap_ptr, value.str_size, &tf->restrict_pattern);
        }
    } else if (value.type == ACTION_STACK_VALUE_NULL ||
               value.type == ACTION_STACK_VALUE_UNDEFINED) {
        tf->restrict_pattern.is_null = 1;
    } else {
        // Non-string (false, 0, NaN, object) = block all
        tf->restrict_pattern.is_block_all = 1;
    }
```

### 4b. Filter Application

Replace `apply_restrict_filter()` with:

```c
static size_t apply_restrict_filter(const char* input, size_t input_len,
                                     const RestrictPattern* pat,
                                     char* output, size_t max_out) {
    size_t out_pos = 0;
    size_t i = 0;
    while (i < input_len && out_pos < max_out - 4) {  // -4 for max UTF-8 char
        uint32_t cp;
        int cp_len = utf8_decode(&input[i], input_len - i, &cp);

        uint32_t filtered = restrict_filter_char(pat, cp);
        if (filtered != 0) {
            int enc_len = utf8_encode(filtered, &output[out_pos], max_out - out_pos);
            out_pos += enc_len;
        }
        i += cp_len;
    }
    output[out_pos] = '\0';
    return out_pos;
}
```

### 4c. Call Sites

Apply the filter at:
1. `EV_TEXT_INPUT` handler — when user types a character
2. Paste operations (`EV_TEXT_CONTROL` paste)
3. Programmatic `TextField.text` assignment (if restrict applies to programmatic sets — verify)
4. `TextField.replaceText()` / `TextField.replaceSel()`

---

## Phase 5: Edge Cases

### Test-Specific Edge Cases (from output.txt analysis)

1. **Non-string restrict values**: `false`, `0`, `0.1`, `NaN`, `true`, `{}` → block all characters
2. **Boolean true**: Coerces to `"true"` → allows only 't', 'r', 'u', 'e'
3. **Number 1**: Coerces to `"1"` → allows only '1'
4. **Number 0.1**: Coerces to `"0.1"` → allows '0', '.', '1'
5. **Range `A-z`**: ASCII 65-122, includes `[\]^_\`` characters
6. **Range `b-a`**: Inverted → just 'b' (Ruffle: max(start,end) single char)
7. **Multiple carets**: `^^` = double flip = allow all
8. **Caret + escape**: `^\^` = disallow literal ^
9. **Unicode ranges**: `α-ω` (Greek lowercase range by code point order)

### Value Coercion for restrict Property

Need to determine: does Flash coerce non-string values to strings before applying restrict, or treat them specially?

From test output:
- `false` → "aa" becomes "" (all blocked). So `false` is NOT coerced to string "false", it blocks all.
- `true` → "truerue" allowed. So `true` IS coerced to string "true", allowing only those chars.
- `0` → "0120" allowed. Coerced to "0".
- `1` → "112" allowed. Coerced to "1".
- `0.1` → "0.10.12" allowed. Coerced to "0.1".
- `NaN` → "aNaNaN" allowed. Coerced to "NaN".

Wait — this contradicts. Let me re-examine: the test sets restrict via ActionScript, and the property setter determines coercion. The Boolean `false` coerces to the string `"false"`, which would allow 'f','a','l','s','e'. But the test shows empty output for false, meaning false blocks all.

**Resolution**: Flash likely checks the type: if the value is Boolean `false`, it's treated as `null` (no restrict? or block all?). Need to verify against the Ruffle source.

From Ruffle (`edit_text.rs`):
```rust
pub fn set_restrict(restrict: Option<WString>) {
    // None = no restriction, Some("") = no restriction
    // Some(pattern) = parse pattern
}
```

Ruffle converts the property to `Option<WString>` — non-string values that coerce to empty string become `None`. Boolean `false` → `"false"` in Ruffle. But the test expects blocking... This needs investigation against actual Flash behavior.

---

## Implementation Priority

| Phase | Effort | Lines Fixed (est.) | Priority |
|-------|--------|-------------------|----------|
| Phase 1: Tokenizer | Small (~50 lines) | 0 (foundation) | Required |
| Phase 2: Parser | Medium (~100 lines) | 0 (foundation) | Required |
| Phase 3: Filter | Small (~40 lines) | 0 (foundation) | Required |
| Phase 4: Integration | Medium (~60 lines) | ~30 | High |
| Phase 5: Edge cases | Small (~30 lines) | ~14 | Medium |

**Total estimate:** ~280 lines of new code, replacing ~30 lines of broken code.

**Expected result:** 147/191 → ~185/191 (remaining ~6 lines likely edge cases needing Flash-specific investigation).

---

## UTF-8 Helpers Needed

The implementation requires two utility functions that may or may not exist:

```c
// Decode one UTF-8 code point. Returns bytes consumed.
static int utf8_decode(const char* buf, size_t len, uint32_t* out);

// Encode one code point to UTF-8. Returns bytes written.
static int utf8_encode(uint32_t cp, char* buf, size_t max);
```

Search the codebase for existing UTF-8 utilities before implementing new ones. The `unicode_case_tables.h` already exists for case conversion.

---

## Regression Guard

```bash
python3 ruffle-tests/verify_output.py --test=edittext_restrict --diff --verbose
python3 ruffle-tests/verify_output.py --test=selection --diff --verbose
python3 ruffle-tests/verify_output.py --test=watch_textfield --diff --verbose
python3 ruffle-tests/verify_output.py --test=textfield_variable --diff --verbose
python3 ruffle-tests/verify_output.py --test=textfield_props_swf5 --diff --verbose
```
