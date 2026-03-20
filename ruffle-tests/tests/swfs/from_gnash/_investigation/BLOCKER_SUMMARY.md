# Gnash Blocker Summary

Last updated: 2026-03-19

This document catalogs the root-cause blockers preventing further progress on the Gnash test suites (actionscript.all + misc-swfmill.all). See also `FAILING_TESTS_BY_FEATURE.md` for the full categorized failure list.

---

## Active Blockers

### Blocker 3: array-v5 Runtime Error

**Impact**: 1 test crashes (exit code 1 after ~72s)

OOM (`heap_alloc(16) failed`) after producing ~108 of 560 expected lines. Three root causes identified:
1. **Missing Array.prototype methods** — concat, join, pop, push, reverse, shift, slice, sort, sortOn, splice, unshift not registered as callable properties
2. **Array.toString returns `[object Object]`** — falls through to Object.prototype.toString
3. **Memory leak** — heap exhaustion from unreleased string/array allocations during extensive operations

**Fix complexity**: Medium (method registration) + Unknown (memory leak).

See `ARRAY_V5_PLAN.md` for full analysis.

---

### Blocker 4: ASArray/ASObject Cast Bug in convertFloat

**Impact**: toString_valueOf-v5/v6 (and indirectly other tests)

`convertFloat` calls `getPropertyWithPrototype(obj, "valueOf", 7)` on ARRAY type values but casts `ASArray*` to `ASObject*`. These are different structs — the cast dereferences garbage memory. Previously identified in the initial gnash investigation.

**Root cause**: ARRAY type not handled separately in `convertFloat` and similar property-lookup sites.

**Fix complexity**: Medium — need to use `arr->props` sub-object for property lookups on arrays.

**Status**: Known bug, documented in CURRENT_STATUS.md Phase 2 item 7.

---

### Blocker 5: Recompiler Edge Cases (misc-swfmill tests)

**Impact**: 6 misc-swfmill tests

| Test | Issue | Complexity |
|------|-------|------------|
| zeroframe_definesprite | Corrupted clip action parsing (PlaceObject2 overrun) | Medium |
| dict_event | ConstantPool not persisting across DoAction blocks | Medium |
| initaction_in_definesprite | DoInitAction inside DefineSprite not parsed | Medium-Hard |
| tags_after_last_showframe | Post-ShowFrame tag execution + InitAction ordering | Hard |
| jump_after_end | Jump past END_OF_ACTIONS byte not handled | Hard |
| jump_to_prev_block | Cross-DoAction-block backward jump not supported | Very Hard |

**Root cause**: Various recompiler edge cases for uncommon bytecode patterns. Each is independent.

See `MISC_SWFMILL_PLAN.md` for detailed root cause analysis of all 6.

---

## Resolved Blockers

| Blocker | When | Key Result |
|---------|------|------------|
| Inheritance-v7/v8 segfaults (#1) | 2026-03-19 | Infinite super.method() recursion fixed. Both tests now output_mismatch (~165/182 lines). See `INHERITANCE_SEGFAULT_PLAN.md` |
| Try/finally OOM (#2) | 2026-03-19 | Two bugs: has_jmp_buf not cleared + return-in-finally skipped cleanup. Try-v6/v7/v8 all PASS (20/20). See `TRY_FINALLY_PLAN.md` |
| s16 label overflow (28 compile fails) | 2026-03-18 | All 28 tests now compile |
| Object.prototype SWF5 guard (hasOwnProperty missing) | 2026-03-18 | 20+ tests improved |
| Transform buffer overflow (13 segfaults) | 2026-03-18 | All segfaults fixed (except 2 Inheritance — now also fixed) |
| WITH block duplicate labels (4 compile fails) | 2026-03-18 | All 4 tests now compile |
| ASnative class 101 (Object.prototype methods) | 2026-03-19 | Gnash tests using ASnative(101,N) now work |
| Color prototype unification | 2026-03-19 | `instanceof Color` now works |

---

## Systemic Issues (Not Blockers, But Affect Many Tests)

### SWF Version Multiplier Effect

Each ActionScript class is tested across SWF versions 5-8. SWF5 tests are simpler (fewer assertions); SWF6+ tests exercise `_global.ClassName`, `hasOwnProperty`, `instanceof`, and other version-gated features. A single fix to a class implementation improves 3-4 tests simultaneously.

**Pattern**: 44 passing tests include 17 at v5-only (the v6+ variants fail on version-gated features). Fixing the version-gated features would multiply the passing count quickly.

### Dejagnu Test Framework Overhead

All 190 actionscript.all tests use Dejagnu.swf as a child SWF. This adds significant execution complexity (ImportAssets, child sprite init, setInterval polling, function registration on _root). Any bug in the child SWF lifecycle affects all tests. The framework is now working (since Phase 1 fixes), but edge cases in child sprite execution ordering can cause cascading failures.

### Property Introspection Expectations

Many Gnash tests exercise introspection (hasOwnProperty, typeof, instanceof, for-in) heavily. Our implementation often returns correct values but with wrong property flags (DONT_ENUM, DONT_DELETE), wrong prototype chain structure, or wrong typeof strings. These cause systematic failures across multiple test classes.
