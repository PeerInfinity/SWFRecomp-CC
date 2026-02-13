# Current Ruffle Test Status

Last updated: 2026-02-13, commit 28a85fb

## Quick Summary

- **Pass rate**: 100/491 filtered (20.4%), 105/616 raw (17.0%)
- **Main failure type**: output_mismatch (377 filtered)
- **Regressions**: None
- **Recent fixes**: init_array/object_invalid (stack overflow checks), stack underflow protection (3 segfaults fixed), DoAction-without-ShowFrame recompiler bug, primitive_instanceof (__proto__ on wrapper objects)

## Top Near-Passing Tests (best ROI to fix)

### Tier 1: Quick wins (1 line off)

| Test | Match | Issue |
|------|-------|-------|
| `object_constructor` | 32/33 (97%) | `new Object(_root)` — quality property read from _root returns undefined instead of 10 |
| `define_function2` | 7/8 (88%) | A function parameter defaults to undefined instead of expected value 66 |
| `export_assets` | 2/3 (67%) | Symbol export/linkage |
| `goto_both_ways2` | 2/3 (67%) | Goto frame logic |
| `goto_frame_number` | 2/3 (67%) | Goto frame by number |
| `goto_rewind2` | 2/3 (67%) | Goto rewind logic |

### Tier 2: 2-3 lines off

| Test | Match | Issue |
|------|-------|-------|
| `swf7_case_sensitive` | 41/44 (93%) | `clip` variable resolves to undefined; case-insensitive built-in property access |
| `xml_first_last_child` | 6/8 (75%) | XML child navigation |
| `swf4_function_calls` | 5/7 (71%) | SWF4 function calling convention |
| `textfield_text` | 5/7 (71%) | TextField .text property |
| `movieclip_name_from_timeline` | 10/13 (77%) | Timeline-placed clips not accessible by name |
| `empty_movieclip_can_attach_movies` | 8/11 (73%) | attachMovie on empty clips |

### Tier 3: Scope/variable resolution (shared root cause)

| Test | Match | Issue |
|------|-------|-------|
| `set_variable_scope` | 51/58 (88%) | `tellTarget` and `with` block scope resolution |
| `get_variable_in_scope` | 23/29 (79%) | Global/root variable path resolution |

### Tier 4: Bigger impact, more work

| Test | Match | Issue |
|------|-------|-------|
| `array_length` | 35/42 (83%) | Setting `array.length` to negative values |
| `local_to_global` | 40/49 (82%) | MovieClip transform methods |
| `stage_object_children` | 62/83 (75%) | `_root.clip` returns undefined |
| `edittext_html_roundtrip` | 11/17 (65%) | HTML text round-trip (improved from 0/17!) |

### Tier 5: Built-in constructors (one-time implementation)

| Test | Match | Issue |
|------|-------|-------|
| `matrix` | 123/171 (72%) | flash.geom.Matrix not implemented |
| `point` | 124/175 (71%) | flash.geom.Point not implemented |
| `rectangle` | 516/745 (69%) | flash.geom.Rectangle not implemented |
| `transform` | 47/70 (67%) | flash.geom.Transform not implemented |

## Common Failure Patterns

### 1. MovieClip access by name returns undefined
Many tests fail because `_root.clipName` or just `clipName` returns undefined. The runtime needs to resolve instance names placed on the timeline as properties of their parent clip. This is a NO_GRAPHICS mode issue — the display list isn't populated in trace-only mode.

### 2. tellTarget/with scope resolution
Variable lookups inside `tellTarget(mc)` blocks should resolve against the target's scope, but assignments should set properties on the target. Current implementation doesn't distinguish these correctly.

### 3. Built-in Flash classes not implemented
`flash.geom.Matrix`, `Point`, `Rectangle`, `Transform` — these are ActionScript 2.0 built-in classes that need constructor + method implementations. Each one would fix one large test.

### 4. Goto/frame navigation
Several tests (goto_both_ways2, goto_frame_number, goto_rewind2, goto_advance1, etc.) are 1-2 lines off, likely sharing a common root cause in frame navigation logic.

## Recommended Work Order

1. **Investigate goto tests** — several 1-line-off tests may share a root cause (goto_both_ways2, goto_frame_number, goto_rewind2)
2. **Fix object_constructor** — investigate what `new Object(_root)` should return for quality prop
3. **Fix define_function2 parameter issue** — investigate the missing parameter default
4. **Fix array_length negative values** — handle negative length assignment edge cases
5. **Implement flash.geom.Point** — constructor + methods, fixes ~51 lines
6. **Implement flash.geom.Matrix** — constructor + methods, fixes ~48 lines
