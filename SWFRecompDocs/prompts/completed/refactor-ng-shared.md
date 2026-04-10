# Refactor: Extract shared ng_* functions from tag_stubs.c

## Problem

Graphics WASM builds (`build_test.sh --graphics` or `verify_output.py --wasm --graphics`) fail at link time with undefined symbols:

```
wasm-ld: error: action.o: undefined symbol: ng_getTextFieldFontId
wasm-ld: error: action.o: undefined symbol: ng_getTextFieldFontHeight
wasm-ld: error: tag.o: undefined symbol: ng_find_font_with_metrics
wasm-ld: error: tag.o: undefined symbol: ng_font_get_metrics
wasm-ld: error: tag.o: undefined symbol: ng_font_get_glyph_base
wasm-ld: error: tag.o: undefined symbol: ng_font_find_glyph
wasm-ld: error: tag.o: undefined symbol: ng_font_glyph_advance_by_idx
wasm-ld: error: tagMain.o: undefined symbol: ng_record_char_path
```

**Root cause:** `action.c` and `tag.c` call `ng_*` functions unconditionally, but
these functions are defined in `tag_stubs.c` which is entirely wrapped in
`#if defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)`. In graphics mode
(USE_WEBGPU without NO_GRAPHICS), `tag_stubs.c` compiles to nothing.

**Complication:** Some `ng_*` functions are ALSO defined in `swf.c` (the graphics
frame loop), creating duplicate symbols if `tag_stubs.c` is included alongside
`swf.c`. Specifically, `swf.c` defines its own `ng_lookupExport` and possibly
others.

## Goal

Extract the shared `ng_*` functions into a new file `ng_shared.c` that is always
compiled (no `#ifdef` guard), so they're available in all three build modes:
- `NO_GRAPHICS` (native trace tests, `swf_core.c`)
- `HEADLESS_GRAPHICS` (offscreen WebGPU, `swf_headless.c`)
- `USE_WEBGPU` (full graphics, `swf.c`)

## Key files

- `SWFModernRuntime/src/libswf/tag_stubs.c` — 5068 lines, guarded by
  `#if defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)`. Contains both
  shared utilities AND NO_GRAPHICS-specific display list management.
- `SWFModernRuntime/src/libswf/swf.c` — graphics frame loop, defines some
  `ng_*` functions (at least `ng_lookupExport` at line ~238).
- `SWFModernRuntime/src/actionmodern/action.c` — calls `ng_*` functions
  without including `tag.h` (uses inline `extern` declarations).
- `SWFModernRuntime/src/libswf/tag.c` — calls `ng_*` functions via `extern`.
- `SWFModernRuntime/include/libswf/tag.h` — declares many `ng_*` functions.

## Steps

### 1. Identify all ng_* callers outside tag_stubs.c

Run:
```bash
grep -n "ng_[a-zA-Z]*(" SWFModernRuntime/src/actionmodern/action.c | grep -v "extern" | sort -u
grep -n "ng_[a-zA-Z]*(" SWFModernRuntime/src/libswf/tag.c | grep -v "extern" | sort -u
```

These are the functions that MUST be available in all build modes.

### 2. Identify duplicates in swf.c

Run:
```bash
grep -n "^[a-zA-Z].*ng_" SWFModernRuntime/src/libswf/swf.c
```

These are the functions that swf.c defines — they'll conflict with tag_stubs.c
if both are compiled. The swf.c versions should be removed once ng_shared.c
provides them.

### 3. Create ng_shared.c

Create `SWFModernRuntime/src/libswf/ng_shared.c` containing:
- All `ng_*` functions called by `action.c` or `tag.c`
- Their required static state (arrays, counters)
- NO `#ifdef NO_GRAPHICS` guard — always compiled

The functions to extract include (at minimum):
- Font functions: `ng_getTextFieldFontId`, `ng_getTextFieldFontHeight`,
  `ng_getFontName`, `ng_getFontBold`, `ng_getFontItalic`,
  `ng_find_font_with_metrics`, `ng_font_get_metrics`,
  `ng_font_get_glyph_base`, `ng_font_find_glyph`,
  `ng_font_glyph_advance_by_idx`
- Export functions: `ng_lookupExport`, `ng_lookupExportForMovie`,
  `ng_lookupExportVersion`, `ng_lookupExportVersionForMovie`,
  `ng_lookupExportName`, `ng_forEachExportName`
- Textfield functions: `ng_getTextFieldFlags`, `ng_getTextFieldBounds`,
  `ng_find_textfield`
- Bounds/path functions: `ng_record_char_bounds`, `ng_record_char_path`,
  `ng_get_char_bounds`, `ng_get_char_paths`
- Enumeration: `ng_enumerateChildren`, `ng_isScriptableChar`
- Display helpers: `ng_sync_root_display_obj`, `ng_get_root_display_obj`
- Other: `ng_getSoundDuration`, `ng_try_reclaim_auto_instance_name`

### 4. Remove extracted functions from tag_stubs.c

Leave ONLY the NO_GRAPHICS-specific code in tag_stubs.c:
- Display list management (tagPlaceObject2 stubs, etc.)
- Sprite frame advancement (`advance_sprite_frames`, `exec_sprite_frame`)
- The `ng_isInsideSprite`, `ng_stopCurrentSprite`, `ng_playCurrentSprite` helpers
- Other functions that are ONLY called from `swf_core.c` or `tag_stubs.c` itself

### 5. Remove duplicates from swf.c

Remove `ng_lookupExport` and any other `ng_*` functions from `swf.c` that are
now provided by `ng_shared.c`.

### 6. Update build scripts

Add `ng_shared.c` to:
- `SWFRecomp/scripts/build_test.sh` — all three mode blocks (NO_GRAPHICS,
  HEADLESS_GRAPHICS, GRAPHICS)
- `ruffle-tests/verify_output.py` — both `compile_native` and `compile_wasm`
  core_sources lists
- `.github/workflows/deploy-pages.yml` and `deploy-pages-build.yml` — WASI
  build step (if it compiles action.o separately, ng_shared.o may be needed)

### 7. Test

```bash
# Native NO_GRAPHICS (should still pass — existing tests)
python3 ruffle-tests/verify_output.py --test=loadmovie --test=three_boxes --diff --verbose

# All runtime-swf demos (NO_GRAPHICS native)
python3 ruffle-tests/verify_output.py --tests-dir=demos/runtime-swf --diff --verbose

# Graphics WASM (the whole point of this refactor)
cd SWFRecomp/tests && source ../../emsdk/emsdk_env.sh
bash ../scripts/build_test.sh graphics/three_boxes wasm --graphics

# NO_GRAPHICS WASM demos
python3 ruffle-tests/verify_output.py --tests-dir=demos/runtime-swf --wasm --deploy-dir=docs/injector --verbose

# Graphics WASM demo (should work after refactor)
python3 ruffle-tests/verify_output.py --tests-dir=demos/runtime-swf --test=display_editor --wasm --graphics --deploy-dir=docs/injector --verbose
```

## Important notes

- Many `ng_*` functions have interdependent static state (arrays like
  `ng_exported_symbols[]`, `ng_fonts[]`, `ng_textfields[]`). These static
  arrays and their registration functions (e.g., `tagRegisterExport`,
  `tagDefineFont`) must move together.
- Some registration functions are called from `tagMain.c` (recompiler output).
  Make sure their signatures don't change.
- `tag_stubs.c` line 1 has the guard: `#if defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)`.
  After extracting shared functions, this guard stays — it still protects
  NO_GRAPHICS-only code.
- The `g_current_sprite_obj` variable is defined in both `tag.c` (line 79,
  inside `#ifdef NO_GRAPHICS`) and `swf.c` (line 45). This is fine because
  only one of them is compiled per build mode. Don't move it to ng_shared.c.
- **Do NOT run the full test suite.** Only run individual tests as shown above.
