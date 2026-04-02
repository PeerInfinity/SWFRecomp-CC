# Global Proto Decls Alignment Plan

Last updated: 2026-04-02

## The Alignment Problem

`global_proto_decls` uses **positional line matching** — actual line N is compared to expected line N. Any line count mismatch in one section shifts ALL subsequent sections. This means changes must be coordinated: adding properties to Key (for example) only helps if the total line count of the Key section matches expected, or the shift is compensated elsewhere.

## Current State

- **Expected output**: 4497 lines
- **Actual output**: 3643 lines (854 fewer lines)
- **Positionally matching**: 986/4497 (22%)
- **First mismatch**: line 743 (missing `constructor, own` on capabilities — Ruffle-specific)

## Root Cause of Line Deficit

The 854-line deficit comes almost entirely from **missing inherited Object.prototype method lines**. In Ruffle, every object/function enumeration includes ~9 inherited Object.prototype methods (watch, unwatch, addProperty, valueOf, toString, hasOwnProperty, isPrototypeOf, isPropertyEnumerable, toLocaleString). In Flash (our implementation), these are DONT_ENUM and don't appear.

This is documented as a permanent Ruffle vs Flash difference in `RUFFLE_VS_FLASH_DIFFERENCES.md`.

## Section-by-Section Breakdown

Expected output order and line counts:

| # | Section | Expected Lines | Inherited ObjProto Lines | Fixable Own Lines | Notes |
|---|---------|---------------|-------------------------|-------------------|-------|
| 1 | TextSnapshot | 16 | 0 | 14 | Already matching |
| 2 | PrintJob | 10 | 0 | 8 | Already matching |
| 3 | MovieClipLoader | 14 | 0 | 12 | Already matching |
| 4 | LocalConnection | 12 | 0 | 10 | Already matching |
| 5 | textRenderer | 10 | 0 | 8 | Already matching |
| 6 | **flash.\*** | **454** | 0 | 391 | flash.* sub-packages recurse into many constructors |
| 7 | **System** | **383** | 126 | 171 | capabilities, IME, security sub-objects with deep recursion |
| 8 | SoundCodec | 137 | 9 | 115 | Has NELLYMOSER/SPEEX constants |
| 9 | **Accessibility** | **172** | 36 | 122 | Missing methods: isActive, sendEvent, updateProperties |
| 10 | Video | 27 | 18 | 7 | |
| 11 | **Stage** | **352** | 72 | 242 | Many properties, broadcaster methods |
| 12 | TextFormat | 25 | 18 | 5 | |
| 13 | TextField | 44 | 18 | 24 | |
| 14 | Button | 32 | 18 | 12 | |
| 15 | **Key** | **434** | 72 | 311 | Missing 19 constants, isAccessible method |
| 16 | **Mouse** | **396** | 72 | 292 | Missing show, hide, setTrailer, setTrailerPosition, setTrailerMode |
| 17 | **Selection** | **409** | 81 | 295 | |
| 18 | LoadVars | 35 | 17 | 16 | |
| 19 | XML | 55 | 18 | 14 | |
| 20 | XMLNode | 45 | 17 | 26 | |
| 21 | Sound | 43 | 18 | 23 | |
| 22 | **Math** | **383** | 171 | 175 | 17 method functions × ~10 lines each |
| 23+ | (remaining ~36 objects) | ~1003 | ~450 | ~400 | Small objects, global functions |

## Why Naive Property Addition Hurts

Adding 19 Key constants adds 19 lines to our Key section. But the expected Key section also has ~72 lines of inherited Object.prototype methods we'll never produce. So:
- Expected Key section: 434 lines
- Current actual Key section: ~174 lines  
- After adding constants: ~193 lines (still 241 lines short)
- **Net effect**: the cumulative shift at Key's end changes, which can MISALIGN all sections after Key

For positional matching, what matters is the **cumulative line count difference** at each point. If a change makes the cumulative difference smaller at one point but larger at another, the net effect on matching lines is unpredictable.

## Strategy: Match Total Line Counts Per Section

To maximize positional matches, each section's actual line count should match its expected line count as closely as possible. Since we can't produce the ~1665 inherited Object.prototype lines, we need to either:

### Option A: Pad sections to expected line counts
Not practical — we'd need to output fake lines, which would be incorrect behavior.

### Option B: Focus on sections where we CAN match the line count
Sections with 0 inherited Object.prototype lines are the best candidates because our line count can exactly match expected:
- TextSnapshot (16) ✓ already matching
- PrintJob (10) ✓ already matching
- MovieClipLoader (14) ✓ already matching  
- LocalConnection (12) ✓ already matching
- textRenderer (10) ✓ already matching
- clearTimeout (12), global functions (12 each)

### Option C: Accept that gains will be incremental
Each Object.prototype method we add `setupNativeFuncOwnProps` to removes one "Testing .prototype" line from our output, reducing the deficit by ~2-10 lines per function (removing prototype header + prototype content, adding __proto__ + constructor). This was the strategy that got us from 884→986.

### Option D: Study cumulative shift to find sweet spots
Map the cumulative line-count difference and find regions where our output happens to realign with expected. Focus improvements in those regions.

## Actionable Items (Sorted by Estimated Impact)

### High Impact (reduces cumulative shift across many lines)

1. **Add `setupNativeFuncOwnProps` to ALL native function objects** that currently lack it
   - Math methods (17 functions: abs, sin, cos, etc.)
   - Key methods (isDown, getCode, getAscii, isToggled) ← partially done in prior attempt
   - Selection methods (getBeginIndex, getEndIndex, getCaretIndex, getFocus, setFocus, setSelection)
   - Stage properties (various)
   - Each removes ~10-12 lines of "Testing .prototype" overhead from actual output
   - **Estimated improvement**: 200-400 lines across the file

2. **MovieClip section is 827 lines TOO LONG** (910 actual vs 83 expected)
   - MovieClip.prototype has many enumerable methods causing massive recursion
   - This excess pushes everything after line 4355 out of alignment
   - Fix: ensure MovieClip.prototype methods have correct DONT_ENUM flags
   - **Estimated improvement**: could realign the last ~140 lines (Function, Object, etc.)

### Medium Impact

3. **Add Key constants** (19 constants, +19 lines to Key section)
   - Only helps if combined with other Key section fixes
   - isAccessible method (+1 line)

4. **Add Mouse methods** (show, hide, setTrailer, setTrailerPosition, setTrailerMode — +5 lines)
   - Same alignment caveat as Key

5. **Add Accessibility methods** (isActive, sendEvent, updateProperties — +3 lines)

### Low Impact (alignment-dependent)

6. **SoundCodec constants** (NELLYMOSER, SPEEX)
7. **Function.prototype apply/call methods**
8. **Stage additional properties** (fullScreenWidth, etc.)

## Measurement Approach

Before making changes, measure the cumulative shift at section boundaries:
```
cumulative_shift[section_end] = actual_lines_so_far - expected_lines_so_far
```

A change is beneficial if it reduces |cumulative_shift| across more section boundaries than it increases it.

## Relationship to GLOBALS_PLAN

This document focuses on the alignment mechanics specific to the positional matching. The substantive implementation work (what properties to add, what flags to set) is tracked in `GLOBALS_PLAN.md` Phases 8c-4, 8c-5, and 8d.
