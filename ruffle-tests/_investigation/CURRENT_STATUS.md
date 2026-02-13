# Current Ruffle Test Status

Last updated: 2026-02-12, commit bf6dde7

## Quick Summary

- **Pass rate**: 97/491 filtered (19.8%), 101/616 raw (16.4%)
- **Main failure type**: output_mismatch (380 filtered)
- **Regressions**: None
- **Recent fixes**: ASFunction/ASObject type confusion — 6 segfaults fixed, 1 compile_fail fixed

## Top Near-Passing Tests (best ROI to fix)

### Tier 1: Quick wins (1-3 lines off)

| Test | Match | Gap | Issue |
|------|-------|-----|-------|
| `object_constructor` | 32/33 (97%) | 1 line | `new Object(_root)` — the quality property read from _root returns undefined instead of 10 |
| `define_function2` | 7/8 (87.5%) | 1 line | A function parameter defaults to undefined instead of expected value 66 |
| `export_assets` | 2/3 (66.7%) | 1 line | Symbol export/linkage |
| `xml_first_last_child` | 6/8 (75%) | 2 lines | XML child navigation |
| `textfield_text` | 5/7 (71.4%) | 2 lines | TextField .text property |
| `swf4_function_calls` | 5/7 (71.4%) | 2 lines | SWF4 function calling convention |

### Tier 2: Variable scope issues (3-7 lines off, shared root cause)

| Test | Match | Gap | Issue |
|------|-------|-----|-------|
| `swf7_case_sensitive` | 41/44 (93.2%) | 3 lines | `clip` variable resolves to undefined; case-insensitive built-in property access failing |
| `primitive_instanceof` | 34/37 (91.9%) | 3 lines | `new String/Number/Boolean()` objects fail `instanceof` — prototype chain not set on wrappers |
| `set_variable_scope` | 51/58 (87.9%) | 7 lines | `tellTarget` and `with` block scope resolution incorrect |
| `get_variable_in_scope` | 23/29 (79.3%) | 6 lines | Global/root variable path resolution |
| `movieclip_name_from_timeline` | 10/13 (76.9%) | 3 lines | Timeline-placed clips not accessible by name |

### Tier 3: MovieClip/object access (bigger impact, more lines off)

| Test | Match | Gap | Issue |
|------|-------|-----|-------|
| `array_length` | 35/42 (83.3%) | 7 lines | Setting `array.length` to negative values doesn't update |
| `local_to_global` | 40/49 (81.6%) | 9 lines | MovieClip transform methods |
| `movieclip_hittest` | 71/92 (77.2%) | 21 lines | hitTest method |
| `stage_object_children` | 62/83 (74.7%) | 21 lines | `_root.clip` returns undefined |
| `attach_movie` | 43/59 (72.9%) | 16 lines | Dynamic clip creation |

### Tier 4: Built-in constructors (many lines off but one-time implementation)

| Test | Match | Gap | Issue |
|------|-------|-----|-------|
| `matrix` | 123/171 (71.9%) | 48 lines | flash.geom.Matrix not implemented |
| `point` | 124/175 (70.9%) | 51 lines | flash.geom.Point not implemented |
| `rectangle` | 516/745 (69.3%) | 229 lines | flash.geom.Rectangle not implemented |
| `transform` | 47/70 (67.1%) | 23 lines | flash.geom.Transform not implemented |

## Common Failure Patterns

### 1. MovieClip access by name returns undefined
Many tests fail because `_root.clipName` or just `clipName` returns undefined. The runtime needs to resolve instance names placed on the timeline as properties of their parent clip. This is a NO_GRAPHICS mode issue — the display list isn't populated in trace-only mode.

### 2. Prototype chain not set on constructed objects
`new String("x") instanceof String` returns false. The wrapper objects created by `actionNewObject` for primitives don't have their `__proto__` linked to `String.prototype` (or `Number.prototype`, etc.).

### 3. tellTarget/with scope resolution
Variable lookups inside `tellTarget(mc)` blocks should resolve against the target's scope, but assignments should set properties on the target. Current implementation doesn't distinguish these correctly.

### 4. Built-in Flash classes not implemented
`flash.geom.Matrix`, `Point`, `Rectangle`, `Transform` — these are ActionScript 2.0 built-in classes that need constructor + method implementations. Each one would fix one large test.

## Recommended Work Order

1. **Fix primitive_instanceof** — set `__proto__` on wrapper objects to `Constructor.prototype`
2. **Fix array_length negative values** — handle negative length assignment edge cases
3. **Fix define_function2 parameter issue** — investigate the missing parameter default
4. **Fix object_constructor** — investigate what `new Object(_root)` should return for quality prop
5. **Implement flash.geom.Point** — constructor + methods, fixes ~51 lines
6. **Implement flash.geom.Matrix** — constructor + methods, fixes ~48 lines
