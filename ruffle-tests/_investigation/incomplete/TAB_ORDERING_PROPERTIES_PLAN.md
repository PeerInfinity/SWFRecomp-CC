# Tab Ordering Properties Plan
<!-- TESTS: tab_ordering_properties -->

Last updated: 2026-03-12

## Status: INCOMPLETE — 0/1 tests passing

### Test Summary

| Test | Expected | Match | Issue |
|------|----------|-------|-------|
| `tab_ordering_properties` | 302 | 156/302 (52%) | `tabIndex` coercion + enumerability |

### Related docs
- `complete/TAB_ORDERING_PLAN.md` — tab navigation ordering (16/16 PASS, does not cover property storage semantics)

---

## What the Test Does

Tests `tabEnabled`, `tabIndex`, and `tabChildren` property read/write/enumeration across 4 object types:
1. Editable text field (`text`)
2. Non-editable text field (`text2`)
3. Button (`button`)
4. MovieClip (`_root`)

For each type, the test:
- Reads default values of all 3 properties
- Sets them to various values: `true`, `0`, `false`, `4`, `undefined`, `-4`, `INT_MAX (2147483647)`, `INT_MAX+1`, `"x"` (string), `INT_MIN`, `Object`, `1.1`
- Reads them back to check coercion
- Checks `for..in` enumeration to see which properties appear

---

## Issue 1: `tabIndex` Type Coercion on Text Fields

Text fields coerce `tabIndex` to **unsigned 32-bit integer** on storage:

| Input | Expected readback | Our output |
|-------|-------------------|------------|
| `-4` | `4294967292` | `-4` |
| `"x"` (non-numeric) | `0` | `"x"` |
| `-2147483648` | `2147483648` | `-2147483648` |
| `Object` | `0` | `[object Object]` |
| `1.1` | `1` | `1.1` |

**Fix**: TextField `tabIndex` setter needs to coerce via `(uint32_t)(int32_t)convertToNumber()`, with non-numeric values → 0.

---

## Issue 2: `tabIndex` Type Coercion on Buttons

Buttons coerce `tabIndex` to **signed 32-bit integer**, with a twist — invalid values preserve the last valid value:

| Input | Expected readback | Our output |
|-------|-------------------|------------|
| `2147483648` | `-2147483648` (i32 wrap) | `2147483648` |
| `"x"` (after `-2147483648`) | `-2147483648` (preserved) | `"x"` |
| `Object` (after preserved) | previous value (preserved) | `[object Object]` |
| `1.1` | `1` (truncated) | `1.1` |

**Fix**: Button `tabIndex` setter coerces via `(int32_t)(int64_t)convertToNumber()`. If the input is NaN (non-numeric string, Object), keep the previous value.

---

## Issue 3: `tabIndex` Enumerability on MovieClips

**Expected**: `tabIndex` on MovieClips is **never enumerable** — even after being explicitly set, `for..in` does NOT list it. Only `tabEnabled` and `tabChildren` appear in enumeration.

**Current**: `tabIndex` is stored as a regular dynamic property, so it always appears in `for..in`.

**Fix**: `tabIndex` on MovieClips needs to be a builtin (hidden) property, not a dynamic property. Either:
- Store it in a dedicated field on the MC struct (like `focusrect`), OR
- Set it as a non-enumerable property via ASSetPropFlags-style flag

---

## Implementation Order

1. **TextField `tabIndex` coercion** (Issue 1) — u32 cast in setter
2. **Button `tabIndex` coercion** (Issue 2) — i32 cast with NaN preservation
3. **MC `tabIndex` enumerability** (Issue 3) — make non-enumerable

Issues 1 and 2 are straightforward type coercion in the property setters. Issue 3 requires deciding where to store the property (struct field vs prop flags).

---

## Estimated Impact

The test has ~302 lines. Issues 1-2 affect ~12 value-coercion lines. Issue 3 affects ~20+ enumeration lines plus cascading line-shift. Together these should bring the test to passing or very close.
