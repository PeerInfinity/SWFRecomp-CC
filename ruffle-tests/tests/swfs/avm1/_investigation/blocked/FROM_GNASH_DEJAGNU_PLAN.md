# From-Gnash Dejagnu Test Framework — Implementation Plan
<!-- TESTS: -->

Last updated: 2026-03-16

## Status: BLOCKED — Child SWF compilation pipeline issue

## Overview

The `from_gnash` test suite contains ~384 AVM1 trace tests across 5 subcategories.
Currently only `misc-swfmill.all` (15 tests, 4 passing) runs in CI. The rest use
the Dejagnu test framework in various ways and don't produce correct output.

### Test Categories and Dejagnu Patterns

| Subcategory | Tests | Dejagnu Pattern | Bundled SWF? | Status |
|---|---|---|---|---|
| `actionscript.all` | 243 | External `loadMovie("Dejagnu.swf")` + setInterval polling | Yes (per-test, identical copies, 10KB) | BLOCKED — child movie not linked |
| `misc-ming.all` | 111 | Inlined (functions compiled into test SWF) | No (1 exception) | BLOCKED — inlined check functions produce no trace output |
| `misc-mtasc.all` | 9 | Inlined (`__Packages.Dejagnu` AS2 class) | No | NEAR-WORKING — `hello` test: 7/8 lines match, 1 `typeof` failure |
| `misc-swfc.all` | 21 | Inlined (functions compiled into test SWF) | No | BLOCKED — same as misc-ming |
| `misc-swfmill.all` | 15 | None (standalone tests) | No | **IN CI** — 4/14 passing |

### How Dejagnu Works

**External pattern (actionscript.all):**
1. Test SWF frame 1: `loadMovie("Dejagnu.swf", "__shared_assets")`
2. Test SWF uses `setInterval` to poll `_root.dejagnu_module_initialized` every frame
3. Dejagnu.swf's init script defines `check_equals`, `xcheck_equals`, `pass`, `fail`, `note`, `printtotals` as global functions and sets `_root.dejagnu_module_initialized = true`
4. Once initialized, the test's `setInterval` callback clears the interval and runs the actual test assertions
5. Assertions call `check_equals(a, b)` which traces "PASSED: ..." or "FAILED: ..."
6. Final frame calls `printtotals()` which traces "#passed: N / #failed: N / #total tests run: N"

**Dejagnu.swf details:**
- SWF5, 10,574 bytes decompressed, 1 frame
- All 243 copies in `actionscript.all` are identical (md5: `b1fec5ab5f6e19bee63e4064d0e89090`)
- Defines: `check_equals`, `xcheck_equals`, `check`, `xcheck`, `pass`, `fail`, `xfail`, `xpass`, `note`, `info`, `printtotals`, `quit`
- Sets `dejagnu_module_initialized` on `_root`

**Inline pattern (misc-ming, misc-swfc):**
- Dejagnu functions are compiled directly into the test SWF's constant pool
- `dejagnu_module_initialized` is set in the SWF's own init script
- No external loadMovie needed
- These tests produce no check output from our runtime, suggesting the inlined functions aren't being invoked properly (possibly a DoInitAction ordering or scope issue)

**MTASC class pattern (misc-mtasc):**
- Dejagnu is an AS2 class (`__Packages.Dejagnu`) compiled into the SWF
- Class constructor creates a TextField for visual output + uses `trace()` for console output
- Nearly works: `hello` test produces 7/8 correct lines, failing only on `typeof(Dejagnu)` returning "undefined" instead of "function"

---

## Blockers

### Blocker 1: actionscript.all — ImportAssets Doesn't Import Character Definitions

**Symptoms (before ImportAssets fix):** Test outputs "Dejagnu not initialized yet after N iterations. Will try again again"

**Symptoms (after ImportAssets fix, commit bc5e38eb):** Test outputs "SWF5" repeated 11,166 times in 2 ticks, then segfaults (OOM from function registry overflow). The Dejagnu sprite IS being placed and its init scripts DO run (confirmed by function registry filling up), but the test produces no PASSED/FAILED output.

**ImportAssets char_id remapping (FIXED):** `tagImportCharacter` was implemented and the recompiler now emits the char_id→export_name mappings. Verified working: `dejagnu → char_id 1001 → local 2 (CHAR_TYPE_SPRITE)`.

**Remaining issue: massive output loop within a single tick.** With `MAX_FRAMES=3`, only 2 ticks execute, but 22,333 stdout lines are produced. The frame_0 function places the `__shared_assets` sprite, which contains the Dejagnu sprite. The Dejagnu sprite init (`Dejagnu_script_0` + `Dejagnu_script_1`) runs and defines ~30 anonymous functions. Something in this init or the subsequent frame processing causes thousands of re-entries or traces.

**Investigation needed:**
1. The Dejagnu sprite has char_id 2 in the parent, which was imported from char_id 1001. The parent's `__shared_assets` (sprite 1) places char_id 2 at depth 1. This triggers the Dejagnu's `sprite_1_frame_0` which calls `Dejagnu_script_0` and `Dejagnu_script_1`.
2. `Dejagnu_script_1` defines functions on `_root` (via GetVariable("_root") + SetMember) and sets `dejagnu_module_initialized = 1`.
3. The parent's frame 1 runs `script_2` which traces "SWF5" and calls check_equals — but no PASSED/FAILED output appears, meaning check_equals is undefined or returns without tracing.
4. The 11,166 "SWF5" lines per tick suggest either: (a) sprite frame advancement is re-running the Dejagnu init thousands of times, (b) the Dejagnu xtrace function is producing output in a loop, or (c) the frame function is being called repeatedly within a single tick due to goto/catch-up logic.
5. Frame never advances past 0 (playing becomes false on tick 2), suggesting actionStop fires during tick 1 — possibly from the Dejagnu sprite (which has a stop-on-last-frame pattern).

**Root cause hypothesis:** The Dejagnu sprite (1 frame) contains an inner sprite at depth 3000 (_xtrace_win, char_id 1002 = imported from 2, which is a text edit). When placed, `process_sprite_needs_init` may re-trigger the parent sprite's init recursively, or the nested PlaceObject2 inside the Dejagnu sprite may cause cascading re-init.

**Next steps:**
1. Add per-function printf to `Dejagnu_script_0`, `Dejagnu_script_1`, parent's `script_0`, `script_1`, `script_2` to trace execution order
2. Check if `process_sprite_needs_init` is causing recursive re-init
3. Check if `_root.dejagnu_module_initialized` is actually being set (trace it in the parent's script_1 checker callback)
4. Check if the `actionStop()` in the Dejagnu sprite's frame end is stopping the ROOT instead of the sprite

**How ImportAssets is supposed to work in Flash:**
1. Parent SWF's ImportAssets tag specifies a URL and a list of export names to import
2. Flash loads the external SWF, runs its init to discover exports
3. The imported character definitions (sprites, shapes, etc.) are mapped to char_ids in the parent's dictionary
4. When the parent places these char_ids on the timeline, it's actually placing the imported definitions

**What happens in our implementation:**
1. Parent's `tagInit` defines its own sprite 1 (a placeholder `__shared_assets` sprite)
2. Parent's `tagInit` calls `actionImportAssets("Dejagnu.swf")`
3. `actionImportAssets` runs the child's `tagInit`, which defines child sprite 1 (the real Dejagnu sprite with `script_0`/`script_1`) at char_id 1001 (offset by movie_id * 1000)
4. Child's `tagInit` calls `tagRegisterExport("dejagnu", 1001)`
5. Parent's `frame_0` places sprite 1 — which is the parent's empty placeholder, NOT the imported Dejagnu sprite
6. The Dejagnu's `script_0`/`script_1` (which define `check_equals`, `dejagnu_module_initialized`, etc.) never run

**The fix needs to:**
1. After running the child's `tagInit`, look up the exported char_ids by name
2. Replace the parent's char_id mappings with the imported definitions (specifically, the parent's sprite at char_id 1 should now point to the child's sprite definition)
3. This way, when the parent places sprite 1 in `frame_0`, it actually places the Dejagnu sprite, triggering `script_0`/`script_1`

**Implementation approach:**

The recompiler emits `tagDefineSprite(app_context, char_id, frame_funcs, frame_count, twips)` which registers a sprite definition in the runtime's character dictionary. ImportAssets needs to:
- After running child `tagInit`, resolve each imported export name to its child char_id
- Copy or alias the child's character definition to the parent's expected char_id
- The parent SWF's ImportAssets tag in the original SWF specifies which local char_ids map to which export names — the recompiler needs to emit this mapping

**Key observation:** The recompiler currently doesn't emit ImportAssets tag data (which char_ids to import under which names). It only emits `actionImportAssets(url)`. The recompiler needs to also emit the char_id→export_name mapping so the runtime can remap after import.

**Files to modify:**
- `SWFRecomp/src/action/action.cpp` (or tag handling): Emit ImportAssets char_id mappings
- `SWFModernRuntime/src/actionmodern/action.c`: `actionImportAssets` needs to remap char_ids
- `SWFModernRuntime/src/libswf/tag.c` or `tag_stubs.c`: Character dictionary remapping support

### Blocker 2: misc-ming / misc-swfc — Inlined Dejagnu Produces No Output

**Symptoms:** Tests produce empty output or partial output missing all PASSED/FAILED/printtotals lines.

**Root cause (hypothesis):** The inlined Dejagnu functions (`check_equals`, `pass`, `fail`, `printtotals`) are defined via DoInitAction on a library symbol. If the symbol's sprite isn't placed on the timeline, the DoInitAction never fires, and the functions are never defined. The test SWF may rely on specific timeline/sprite placement to trigger the init.

**Investigation steps:**
1. Pick one misc-ming test (e.g., `PlaceObject2Test`) and examine its recompiled C code to see if Dejagnu-related DoInitActions are being emitted
2. Check if the test SWF has a sprite with an associated DoInitAction that defines the check functions
3. Compare the recompiled tag output (`tagMain.c`) with what Ruffle would execute

### Blocker 3: misc-mtasc — `typeof(Dejagnu)` Returns "undefined"

**Symptoms:** `hello` test: `typeof(Dejagnu)` returns "undefined" instead of "function". All other assertions pass.

**Root cause (hypothesis):** The `Dejagnu` class is defined via `__Packages.Dejagnu` (AS2 class mechanism). Our runtime may not resolve `typeof(ClassName)` correctly for AS2 classes — the class constructor function exists but isn't accessible by the simple name `Dejagnu` in the global scope.

**Investigation steps:**
1. Check how `__Packages` classes are registered — the recompiler should emit code that makes the class constructor accessible as a global variable
2. This may be a simpler fix than the other blockers

---

## Priority

| Priority | Category | Tests | Effort | Impact |
|---|---|---|---|---|
| 1 | `actionscript.all` child movie fix | 243 | Medium | Highest — unblocks the largest test suite. Many tests likely pass once Dejagnu initializes. |
| 2 | `misc-mtasc` typeof fix | 9 | Low | Quick win — `hello` is 7/8, others may be close |
| 3 | `misc-ming` / `misc-swfc` init action ordering | 132 | High | Complex — requires understanding DoInitAction targeting for inlined library code |

---

## Appendix: Dejagnu.swf String Constants

Key strings found in Dejagnu.swf's constant pool:
```
check_equals, xcheck_equals, check, xcheck
pass, fail, xpass, xfail
note, info, quit
printtotals
PASSED:, FAILED:
#passed:, #failed:, #total tests run:
dejagnu_module_initialized
fscommand
dejafont
```
