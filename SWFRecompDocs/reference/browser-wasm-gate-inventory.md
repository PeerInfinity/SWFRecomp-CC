# Browser-WASM gate inventory

**Generated** by `tools/gate_inventory.py` — do not hand-edit the
generated sections. Regenerate with:

```bash
python3 tools/gate_inventory.py --markdown \
    SWFRecompDocs/reference/browser-wasm-gate-inventory.md
```

Source commit: `595667b57` (2026-07-23). Sites are ordered by path then line, so
regenerated inventories diff cleanly.

## Config model

| Config | Known defined | Known undefined | Frame loop |
|---|---|---|---|
| no-graphics | `NO_GRAPHICS` | `HEADLESS_RENDER_ENABLED`, `OFFSCREEN_RENDER`, `USE_WEBGPU`, `__EMSCRIPTEN__` | `swf_core.c` |
| graphics-native | `NDEBUG`, `OFFSCREEN_RENDER`, `USE_WEBGPU` | `NO_GRAPHICS`, `__EMSCRIPTEN__` | `swf.c` |
| browser-WASM | `USE_WEBGPU`, `__EMSCRIPTEN__` | `NO_GRAPHICS`, `OFFSCREEN_RENDER` | `swf.c` |

Every other macro (`WITH_AP`, `SWF_HAVE_LIBAVCODEC`, `HEADLESS_RENDER_ENABLED`
in the graphics configs, `NDEBUG` outside graphics-native, platform macros,
…) is **unknown**: the evaluator uses three-valued logic and reports the site
as `depends` rather than guessing.

## What counts as a site

A *site* is one `#if`/`#elif`/`#else`/`#endif` group whose own arm conditions
name `NO_GRAPHICS`, `OFFSCREEN_RENDER`, or `__EMSCRIPTEN__`. Nested groups
count twice, deliberately: their lines roll up into the enclosing site's
per-config totals, and if the nested condition itself names a key symbol it is
also a site of its own, evaluated *with its enclosing gate stack applied*. A
config the enclosing stack excludes is reported `unreachable` and takes no
part in that site's classification — which is why an `__EMSCRIPTEN__` split
inside `#ifndef NO_GRAPHICS` is not counted as a no-graphics asymmetry, and
why almost everything in `swf.c` lands in `*-partial` (no-graphics never
compiles that file).

Line counts are non-blank, non-comment lines the config actually compiles,
counted recursively through nested gates.

## Summary

Total gate sites: **415** across 25 files.

| Category | Sites | Meaning |
|---|---:|---|
| `browser-none` | 118 | browser-WASM gets **zero** code; both native configs get code |
| `browser-none-partial` | 39 | browser-WASM gets zero code; exactly one native config gets code (the other gets none, or cannot reach the site) |
| `browser-only` | 105 | only browser-WASM gets code (reachable native configs get none) |
| `native-asym` | 38 | no-graphics vs graphics-native disagree; browser-WASM gets code |
| `depends` | 17 | result hinges on a macro outside the three config sets |
| `browser-unreachable` | 10 | the enclosing gate stack excludes browser-WASM entirely |
| `all-configs` | 88 | every reachable config receives code (arms may still differ) |

### By file

| File | Sites | `browser-none` | `browser-none-partial` | `browser-only` | `native-asym` | `depends` | `browser-unreachable` | `all-configs` |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| `SWFModernRuntime/include/audio/audio.h` | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| `SWFModernRuntime/include/libswf/swf.h` | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| `SWFModernRuntime/include/libswf/tag.h` | 2 | 0 | 1 | 0 | 1 | 0 | 0 | 0 |
| `SWFModernRuntime/include/rendering/render_webgpu.h` | 4 | 0 | 3 | 1 | 0 | 0 | 0 | 0 |
| `SWFModernRuntime/include/rendering/renderer.h` | 1 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |
| `SWFModernRuntime/src/actionmodern/action.c` | 133 | 59 | 2 | 24 | 7 | 3 | 1 | 37 |
| `SWFModernRuntime/src/actionmodern/action_queue.c` | 1 | 0 | 0 | 1 | 0 | 0 | 0 | 0 |
| `SWFModernRuntime/src/actionmodern/object.c` | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 0 |
| `SWFModernRuntime/src/actionmodern/rando_ap_wasm.c` | 1 | 0 | 0 | 0 | 0 | 1 | 0 | 0 |
| `SWFModernRuntime/src/audio/audio.c` | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| `SWFModernRuntime/src/audio/audio_output_web.c` | 2 | 0 | 0 | 0 | 1 | 0 | 0 | 1 |
| `SWFModernRuntime/src/avm2/avm2_bytearray.c` | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 |
| `SWFModernRuntime/src/avm2/avm2_display.c` | 6 | 0 | 3 | 2 | 1 | 0 | 0 | 0 |
| `SWFModernRuntime/src/avm2/avm2_external.c` | 7 | 0 | 0 | 5 | 0 | 0 | 0 | 2 |
| `SWFModernRuntime/src/avm2/avm2_main.c` | 8 | 0 | 3 | 3 | 2 | 0 | 0 | 0 |
| `SWFModernRuntime/src/avm2/avm2_media.c` | 12 | 0 | 0 | 0 | 8 | 0 | 0 | 4 |
| `SWFModernRuntime/src/libswf/graphics_stubs.c` | 7 | 0 | 1 | 5 | 1 | 0 | 0 | 0 |
| `SWFModernRuntime/src/libswf/swf.c` | 34 | 0 | 12 | 15 | 1 | 1 | 2 | 3 |
| `SWFModernRuntime/src/libswf/swf_core.c` | 5 | 0 | 1 | 0 | 0 | 0 | 4 | 0 |
| `SWFModernRuntime/src/libswf/tag.c` | 117 | 46 | 3 | 26 | 9 | 0 | 2 | 31 |
| `SWFModernRuntime/src/libswf/tag_stubs.c` | 17 | 5 | 4 | 7 | 0 | 0 | 0 | 1 |
| `SWFModernRuntime/src/memory/heap.c` | 1 | 0 | 0 | 0 | 0 | 1 | 0 | 0 |
| `SWFModernRuntime/src/rendering/render_webgpu.c` | 31 | 0 | 5 | 15 | 3 | 0 | 0 | 8 |
| `SWFRecomp/wasm_wrappers/display_bridge.c` | 11 | 0 | 0 | 0 | 0 | 11 | 0 | 0 |
| `SWFRecomp/wasm_wrappers/main.c` | 5 | 1 | 0 | 1 | 1 | 0 | 1 | 1 |

## Flagged: browser-WASM receives no code

The deliverable. `triage` is intentionally empty — a follow-up session with
deep runtime context fills it with `intentional` / `suspicious` / `bug`.
Absence of an `#else` **is** the signal: a site counts even when the missing
arm is next to a shared fallthrough.

Line columns are `no-graphics / graphics-native / browser-WASM` code lines
(`–` = the config cannot reach the site at all). The arms column gives each
arm's size and which configs take it (`ng`/`gn`/`bw`; a trailing `?` means the
selection depends on a macro outside the config sets).

### `browser-none` — 118 sites

browser-WASM gets zero code; both native configs get code.

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/src/actionmodern/action.c`:9072-9106 | `transformMatrixSetter` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 26/26/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 26L → ng,gn | bug (probe: transform_matrix_set) |
| `SWFModernRuntime/src/actionmodern/action.c`:9146-9150 | `transformCTSetter` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 3/3/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 3L → ng,gn | bug (probe: transform_matrix_set) |
| `SWFModernRuntime/src/actionmodern/action.c`:10907-10923 | `colorGetTransform` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 14/14/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 14L → ng,gn | bug (probe: color_gettransform) |
| `SWFModernRuntime/src/actionmodern/action.c`:17312-17558 | `textFormatSetProperty` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 187/187/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 187L → ng,gn | bug (probe: textformat_from_field) |
| `SWFModernRuntime/src/actionmodern/action.c`:19761-19770 | `xml_create_document` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 8/8/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 8L → ng,gn | intentional |
| `SWFModernRuntime/src/actionmodern/action.c`:20089-20129 | `resolveSlashPathToMC` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 34/34/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 34L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:20135-20138 | `resolveSlashPathToMC` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 2/2/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 2L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:20175-20178 | `resolveSlashPathToMC` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 2/2/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 2L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:20193-20203 | `resolveSlashPathToMC` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 9/9/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 9L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:23937-24087 | `propagateTargetToDescendants` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 92/92/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 92L → ng,gn | intentional-model |
| `SWFModernRuntime/src/actionmodern/action.c`:26084-26096 | `mcReadAlpha` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 6/6/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 6L → ng,gn | bug (probe: alpha_cxform_read) |
| `SWFModernRuntime/src/actionmodern/action.c`:28987-29008 | `setCurrentContext` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 4/4/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 4L → ng,gn | intentional |
| `SWFModernRuntime/src/actionmodern/action.c`:31621-31714 | `actionNextFrame` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 49/49/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 49L → ng,gn | intentional-model |
| `SWFModernRuntime/src/actionmodern/action.c`:32270-32324 | `actionGotoFrame` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 32/27/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 32/27/32L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:32373-32375 | `actionGotoFrame` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:32382-32389 | `actionGotoFrame` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 6/6/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 6L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:32398-32411 | `actionGotoFrame` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 7/7/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 7L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:32524-32553 | `actionGoToLabel` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 13/13/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 13L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:32570-32577 | `actionGoToLabel` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 4/4/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 4L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:32722-32769 | `actionGotoFrame2` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 35/35/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 35L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:32808-32844 | `actionGotoFrame2` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 27/27/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 27L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:32895-32918 | `actionEndDrag` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 17/17/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 17L → ng,gn | couldn't probe (probe: droptarget_scripted — Ruffle oracle blind) |
| `SWFModernRuntime/src/actionmodern/action.c`:40245-40355 | `actionGetVariable` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 79/79/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 79L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:40867-40874 | `actionGetVariable` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 6/6/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 6L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:41645-41656 | `actionGetVariable` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 5/5/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 5L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:41824-41836 | `actionSetVariable` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 9/9/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 9L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:42039-42041 | `actionSetVariable` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:42190-42198 | `actionSetVariable` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 6/6/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 6L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:42480-42487 | `actionSetVariable` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 5/5/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 5L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:42849-42856 | `actionDefineLocal` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 5/5/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 5L → ng,gn | intentional (probe: var_textfield_sync green — TF binding registry) |
| `SWFModernRuntime/src/actionmodern/action.c`:43212-43221 | `actionGetProperty` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 7/7/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 7L → ng,gn | suspicious (unprobed — see Probe adjudication) |
| `SWFModernRuntime/src/actionmodern/action.c`:43230-43242 | `actionGetProperty` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 11/11/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 11L → ng,gn | bug (probe: getproperty_timeline_x) |
| `SWFModernRuntime/src/actionmodern/action.c`:43246-43258 | `actionGetProperty` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 11/11/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 11L → ng,gn | bug (probe: getproperty_timeline_x) |
| `SWFModernRuntime/src/actionmodern/action.c`:43262-43264 | `actionGetProperty` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | bug (probe: getproperty_timeline_x) |
| `SWFModernRuntime/src/actionmodern/action.c`:43268-43270 | `actionGetProperty` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | bug (probe: getproperty_timeline_x) |
| `SWFModernRuntime/src/actionmodern/action.c`:43292-43294 | `actionGetProperty` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | bug (probe: getproperty_timeline_x) |
| `SWFModernRuntime/src/actionmodern/action.c`:43511-43513 | `actionTypeof` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | bug (probe: typeof_textfield_button) |
| `SWFModernRuntime/src/actionmodern/action.c`:43545-43573 | `actionTypeof` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 22/22/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 22L → ng,gn | bug (probe: typeof_textfield_button) |
| `SWFModernRuntime/src/actionmodern/action.c`:43861-43873 | `actionDelete2` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 11/11/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 11L → ng,gn | intentional (probe: delete_child_mc green — gate is a no-op) |
| `SWFModernRuntime/src/actionmodern/action.c`:45877-45894 | `actionCall` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 13/13/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 13L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:46017-46049 | `actionCall` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 28/28/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 28L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:51491-51493 | `actionGetMember` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:51496-51498 | `actionGetMember` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:51501-51503 | `actionGetMember` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:55902-55929 | `actionSetTarget` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 18/18/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 18L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:59207-59212 | `actionCallFunction` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 4/4/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 4L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:65732-65764 | `actionCallMethod` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 30/30/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 30L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:65771-65798 | `actionCallMethod` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 26/26/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 26L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:65974-65992 | `actionCallMethod` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 9/9/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 9L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:66688-66963 | `actionCallMethod` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 244/244/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 244L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:67278-67379 | `actionCallMethod` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 75/75/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 75L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:67424-67435 | `actionCallMethod` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 5/5/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 5L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:67691-67707 | `actionCallMethod` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 10/10/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 10L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:67759-67762 | `actionCallMethod` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 2/2/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 2L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:67794-67797 | `actionCallMethod` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 2/2/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 2L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:67956-68337 | `actionCallMethod` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 236/236/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 236L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:69153-69157 | `actionCallMethod` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 3/3/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 3L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:70182-70191 | `actionStartDrag` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 4/4/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 4L → ng,gn | couldn't probe (probe: droptarget_scripted — Ruffle oracle blind) |
| `SWFModernRuntime/src/actionmodern/action.c`:71861-71915 | `actionUpdateHighlightState` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 41/41/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 41L → ng,gn | deferred (needs Tab-key injection the runner lacks) |
| `SWFModernRuntime/src/actionmodern/object.c`:462-468 | `swfMemMarkUnsafeToWalk` | `!defined(__EMSCRIPTEN__)` | — | 5/5/0 | `!defined(__EMSCRIPTEN__)` 5L → ng,gn | intentional |
| `SWFModernRuntime/src/actionmodern/object.c`:472-476 | `swfMemReportAtExitIfEnabled` | `!defined(__EMSCRIPTEN__)` | — | 3/3/0 | `!defined(__EMSCRIPTEN__)` 3L → ng,gn | intentional |
| `SWFModernRuntime/src/actionmodern/object.c`:530-540 | `allocObject` | `!defined(__EMSCRIPTEN__)` | — | 8/8/0 | `!defined(__EMSCRIPTEN__)` 8L → ng,gn | intentional |
| `SWFModernRuntime/src/avm2/avm2_bytearray.c`:27-30 | — | `!defined(__EMSCRIPTEN__)` | — | 2/2/0 | `!defined(__EMSCRIPTEN__)` 2L → ng,gn | intentional |
| `SWFModernRuntime/src/avm2/avm2_bytearray.c`:475-546 | `charset_classify` | `!defined(__EMSCRIPTEN__)` | — | 67/67/0 | `!defined(__EMSCRIPTEN__)` 67L → ng,gn | deferred (AVM2 — different browser harness) |
| `SWFModernRuntime/src/avm2/avm2_bytearray.c`:1010-1015 | `ba_write_multi_byte` | `!defined(__EMSCRIPTEN__)` | — | 4/4/0 | `!defined(__EMSCRIPTEN__)` 4L → ng,gn | deferred (AVM2 — different browser harness) |
| `SWFModernRuntime/src/avm2/avm2_bytearray.c`:1034-1039 | `ba_read_multi_byte` | `!defined(__EMSCRIPTEN__)` | — | 4/4/0 | `!defined(__EMSCRIPTEN__)` 4L → ng,gn | deferred (AVM2 — different browser harness) |
| `SWFModernRuntime/src/libswf/tag.c`:216-320 | `ng_cache_transform` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 44/44/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 44L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:871-882 | `process_sprite_init_at_depth` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 8/8/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 8L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:933-939 | `ng_set_script_only_mode` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 2/2/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 2L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:1005-1059 | `ng_set_script_only_mode` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 40/40/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 40L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:1124-1126 | `advance_sprite_frames` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:1441-1471 | `advance_sprite_frames` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 18/18/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 18L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:1533-1537 | `advance_sprite_frames` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 3/3/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 3L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:1539-1541 | `advance_sprite_frames` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:1548-1569 | `advance_sprite_frames` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 16/16/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 16L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:1728-1730 | `advance_nested_sprite_frames` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:1883-1891 | `ng_promote_attached_playheads` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 7/7/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 7L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:1897-1919 | `ng_advance_attached_clip_playheads` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 21/21/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 21L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:1958-1960 | `ng_apply_pending_sprite_self_gotos` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:2012-2030 | `ng_apply_pending_sprite_self_gotos` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 16/16/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 16L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:2164-2166 | `presync_nested_sprite_currentframe` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:4360-4369 | `tagFlushPendingEnterFrame` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 2/2/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 2L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:6334-6643 | `tagShowFrame` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 233/233/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 233L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:7155-7372 | `fire_eager_constructors` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 145/145/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 145L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:7486-7525 | `queue_clip_load_events` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 24/24/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 24L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:7529-7531 | `tagPlaceObject2` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:7596-7645 | `tagPlaceObject2` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 25/25/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 25L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:7782-8015 | `tagPlaceObject2` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 123/123/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 123L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:8040-8092 | `tagPlaceObject2` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 27/27/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 27L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:8475-8477 | `tagPlaceObject2` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:8501-8503 | `tagSetClipActions` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:8586-8715 | `tagSetClipActions` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 96/96/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 96L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:8723-8725 | `tagSetClipActions` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:8736-8769 | `tagSetClipActions` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 29/29/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 29L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:9007-9009 | `tagSetClipActions` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:9114-9128 | `tagSetClipActions` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 6/6/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 6L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:9231-9237 | `dlr_rebase_queue_cb` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 5/5/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 5L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:9319-9324 | `dlr_rebase_copies_recurse` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 4/4/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 4L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:9405-9413 | `dlr_scrub_queue_cb` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 7/7/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 7L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:9860-9880 | `tagRemoveObject` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 17/17/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 17L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:9946-9948 | `tagRemoveObject2` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:9951-10050 | `tagRemoveObject2` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 52/52/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 52L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:10074-10090 | `tagRemoveObject2` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 8/8/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 8L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:10149-10164 | `tagRemoveObject2` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 5/5/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 5L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:10331-10333 | `tagDefineButton` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:10759-10767 | `tagSetInstanceName` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 2/2/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 2L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:10776-10850 | `tagSetInstanceName` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 27/27/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 27L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:10855-10858 | `tagSetInstanceName` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 2/2/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 2L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:10862-10864 | `tagSetInstanceName` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:10878-10952 | `tagSetInstanceName` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 59/59/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 59L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:11075-11121 | `hasClipEnterFrameHandlers` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 25/25/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 25L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag.c`:11129-11165 | `ng_fire_child_constructors` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 21/21/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 21L → ng,gn | intentional-model |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:715-748 | `ng_attachMovie` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 24/24/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 24L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:1104-1107 | `ng_gotoFrameCurrentSprite` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 2/2/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 2L → ng,gn | intentional |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:2325-2374 | `ng_getTextFieldIdx` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 24/24/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 24L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:2615-2655 | `ng_getTextFieldIdx` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 32/32/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 32L → ng,gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:2744-2750 | `ng_getTextFieldIdx` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 5/5/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 5L → ng,gn | intentional-paired |
| `SWFRecomp/wasm_wrappers/main.c`:88-90 | `swf_ei_call_internal` | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` | — | 1/1/0 | `defined(NO_GRAPHICS) \|\| defined(OFFSCREEN_RENDER)` 1L → ng,gn | intentional |

### `browser-none-partial` — 39 sites

browser-WASM gets zero code; exactly one native config gets code (the other gets none, or cannot reach the site).

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/include/libswf/tag.h`:44-49 | — | `defined(NO_GRAPHICS)` | — | 2/0/0 | `defined(NO_GRAPHICS)` 2L → ng | intentional |
| `SWFModernRuntime/include/rendering/render_webgpu.h`:140-142 | — | `!defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 1/0/0 | `!defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 1L → ng | intentional-paired |
| `SWFModernRuntime/include/rendering/render_webgpu.h`:144-151 | — | `defined(OFFSCREEN_RENDER)` | — | 0/5/0 | `defined(OFFSCREEN_RENDER)` 5L → gn | intentional-paired |
| `SWFModernRuntime/include/rendering/render_webgpu.h`:272-276 | — | `defined(OFFSCREEN_RENDER)` | — | 0/2/0 | `defined(OFFSCREEN_RENDER)` 2L → gn | intentional-paired |
| `SWFModernRuntime/include/rendering/renderer.h`:56-59 | — | `defined(OFFSCREEN_RENDER)` | `defined(USE_WEBGPU)` | –/2/0 | `defined(OFFSCREEN_RENDER)` 2L → gn | intentional |
| `SWFModernRuntime/src/actionmodern/action.c`:33214-33219 | `actionGetURL` | `defined(OFFSCREEN_RENDER)` | — | 0/4/0 | `defined(OFFSCREEN_RENDER)` 4L → gn | intentional-paired |
| `SWFModernRuntime/src/actionmodern/action.c`:46156-46161 | `actionGetURL2` | `defined(OFFSCREEN_RENDER)` | — | 0/4/0 | `defined(OFFSCREEN_RENDER)` 4L → gn | intentional |
| `SWFModernRuntime/src/avm2/avm2_display.c`:9363-9365 | `avm2_cpu_dump_frame` | `defined(OFFSCREEN_RENDER)` | `defined(OFFSCREEN_RENDER) \|\| (defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS))` | –/1/0 | `defined(OFFSCREEN_RENDER)` 1L → gn | intentional-paired |
| `SWFModernRuntime/src/avm2/avm2_display.c`:9886-9890 | `avm2_render_init` | `defined(OFFSCREEN_RENDER)` | `defined(OFFSCREEN_RENDER) \|\| (defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS))` | –/1/0 | `defined(OFFSCREEN_RENDER)` 1L → gn | intentional |
| `SWFModernRuntime/src/avm2/avm2_display.c`:9893-9914 | `avm2_render_init` | `defined(OFFSCREEN_RENDER)` | `defined(OFFSCREEN_RENDER) \|\| (defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS))` | –/14/0 | `defined(OFFSCREEN_RENDER)` 14L → gn | intentional |
| `SWFModernRuntime/src/avm2/avm2_main.c`:422-425 | `runSWF_avm2` | `defined(OFFSCREEN_RENDER)` | — | 0/2/0 | `defined(OFFSCREEN_RENDER)` 2L → gn | intentional-paired |
| `SWFModernRuntime/src/avm2/avm2_main.c`:561-564 | `runSWF_avm2` | `defined(OFFSCREEN_RENDER)` | — | 0/1/0 | `defined(OFFSCREEN_RENDER)` 1L → gn | intentional-paired |
| `SWFModernRuntime/src/avm2/avm2_main.c`:584-594 | `runSWF_avm2` | `defined(OFFSCREEN_RENDER)` | — | 0/9/0 | `defined(OFFSCREEN_RENDER)` 9L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/graphics_stubs.c`:74-85 | — | `defined(OFFSCREEN_RENDER)` | `defined(USE_WEBGPU) && !defined(NO_GRAPHICS)` | –/10/0 | `defined(OFFSCREEN_RENDER)` 10L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf.c`:15-17 | — | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/1/0 | `defined(OFFSCREEN_RENDER)` 1L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf.c`:391-409 | `tagMain` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/7/0 | `defined(OFFSCREEN_RENDER)` 7L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf.c`:525-610 | `tagMain` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/24/0 | `defined(OFFSCREEN_RENDER)` 24L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf.c`:854-886 | `tagMain` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/15/0 | `defined(OFFSCREEN_RENDER)` 15L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf.c`:901-903 | `tagMain` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/1/0 | `defined(OFFSCREEN_RENDER)` 1L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf.c`:938-967 | `tagMain` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/9/0 | `defined(OFFSCREEN_RENDER)` 9L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf.c`:970-1232 | `tagMain` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/132/0 | `defined(OFFSCREEN_RENDER)` 109/132/109L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf.c`:1377-1381 | `tagMain` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/2/0 | `defined(OFFSCREEN_RENDER)` 2L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf.c`:1542-1546 | `swfStart` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/1/0 | `defined(OFFSCREEN_RENDER)` 1L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf.c`:1548-1581 | `swfStart` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/7/0 | `defined(OFFSCREEN_RENDER)` 7L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf.c`:1585-1594 | `swfStart` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/4/0 | `defined(OFFSCREEN_RENDER)` 4L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf.c`:1598-1615 | `swfStart` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/8/0 | `defined(OFFSCREEN_RENDER)` 8L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/swf_core.c`:1-1641 | — | `defined(NO_GRAPHICS)` | — | 935/0/0 | `defined(NO_GRAPHICS)` 935/905/905L → ng | intentional |
| `SWFModernRuntime/src/libswf/tag.c`:3059-3088 | `render_single_object` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/19/0 | `defined(OFFSCREEN_RENDER)` 19L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:3229-3251 | `render_display_list` | `defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/19/0 | `defined(OFFSCREEN_RENDER)` 19L → gn | intentional-paired |
| `SWFModernRuntime/src/libswf/tag.c`:4975-5315 | `attached_bitmap_render_cb` | `defined(OFFSCREEN_RENDER)` | — | 0/260/0 | `defined(OFFSCREEN_RENDER)` 260L → gn | intentional |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:27-31 | — | `defined(NO_GRAPHICS)` | — | 3/0/0 | `defined(NO_GRAPHICS)` 3L → ng | intentional |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:447-449 | `ng_attachMovie` | `defined(NO_GRAPHICS)` | — | 1/0/0 | `defined(NO_GRAPHICS)` 1L → ng | intentional-paired |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:2975-2989 | `ng_getTextFieldIdx` | `defined(NO_GRAPHICS)` | — | 7/0/0 | `defined(NO_GRAPHICS)` 7L → ng | intentional-paired |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:2994-3030 | `finalizeBitmaps` | `defined(NO_GRAPHICS)` | — | 30/0/0 | `defined(NO_GRAPHICS)` 30L → ng | intentional |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:2615-2634 | `render_webgpu_close_pass` | `defined(OFFSCREEN_RENDER)` | — | 0/15/0 | `defined(OFFSCREEN_RENDER)` 15L → gn | intentional-paired |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:2689-2693 | `render_webgpu_close_pass` | `defined(OFFSCREEN_RENDER)` | — | 1/0/0 | `defined(OFFSCREEN_RENDER)` 0L → gn; `!defined(__EMSCRIPTEN__)` 1L → ng | intentional-paired |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:3577-3580 | `render_webgpu_free` | `!defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 2/0/0 | `!defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 2L → ng | intentional-paired |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:3582-3587 | `render_webgpu_free` | `defined(OFFSCREEN_RENDER)` | — | 0/3/0 | `defined(OFFSCREEN_RENDER)` 3L → gn | intentional-paired |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:3602-3684 | `render_webgpu_free` | `defined(OFFSCREEN_RENDER)` | — | 0/62/0 | `defined(OFFSCREEN_RENDER)` 62L → gn | intentional-paired |

## Secondary: browser-WASM-only arms

Sites where only browser-WASM compiles code — the mirror image; useful for
spotting web paths with no native equivalent (and therefore no test coverage
in either native mode).

### `browser-only` — 105 sites

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/include/rendering/render_webgpu.h`:278-285 | — | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/3 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 3L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:12-14 | — | `defined(__EMSCRIPTEN__)` | — | 0/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:5658-5718 | `actionEI_call` | `defined(__EMSCRIPTEN__)` | — | 0/0/42 | `defined(__EMSCRIPTEN__)` 42L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:31761-31767 | `actionPlay` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/5 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 5L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:31789-31795 | `actionStop` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/5 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 5L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:32261-32269 | `actionGotoFrame` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/7 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 7L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:32336-32356 | `actionGotoFrame` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/12 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 12L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:32490-32503 | `actionGoToLabel` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/12 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 12L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:33369-33378 | `actionGetURL` | `defined(__EMSCRIPTEN__)` | — | 0/0/8 | `defined(__EMSCRIPTEN__)` 8L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:41958-41973 | `actionSetVariable` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/2 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 2L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:42075-42082 | `actionSetVariable` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/6 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 6L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:42155-42157 | `actionSetVariable` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:42160-42162 | `actionSetVariable` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:42166-42168 | `actionSetVariable` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:42172-42174 | `actionSetVariable` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:42178-42180 | `actionSetVariable` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:55484-55486 | `actionCloneSprite` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:55871-55890 | `actionSetTarget` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/8 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 8L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:58803-58810 | `actionCallFunction` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/6 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 6L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:58945-58947 | `actionCallFunction` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:66243-66252 | `actionCallMethod` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/8 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 8L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:69437-69443 | `actionCallMethod` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/2 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 2L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:69453-69484 | `actionCallMethod` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/5 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 5L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:70370-70377 | `mc_get_pixel_aabb_ng` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:70520-70567 | `mc_get_pixel_aabb_ng` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/27 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 27L → bw |  |
| `SWFModernRuntime/src/actionmodern/action_queue.c`:236-247 | `actionDrainAllInPriorityOrder` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/4 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 4L → bw |  |
| `SWFModernRuntime/src/avm2/avm2_display.c`:9366-9368 | `avm2_cpu_dump_frame` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | `defined(OFFSCREEN_RENDER) \|\| (defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS))` | –/0/1 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/avm2/avm2_display.c`:9916-9930 | `avm2_render_finish` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | `defined(OFFSCREEN_RENDER) \|\| (defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS))` | –/0/6 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 6L → bw |  |
| `SWFModernRuntime/src/avm2/avm2_external.c`:45-47 | — | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/avm2/avm2_external.c`:95-241 | `ei_throw_2067` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/126 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 126L → bw |  |
| `SWFModernRuntime/src/avm2/avm2_external.c`:304-306 | `ei_add_callback` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/avm2/avm2_external.c`:322-324 | `ei_add_callback` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/avm2/avm2_external.c`:364-405 | `ei_call` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/34 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 34L → bw |  |
| `SWFModernRuntime/src/avm2/avm2_main.c`:37-48 | — | `defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/5 | `defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 5L → bw |  |
| `SWFModernRuntime/src/avm2/avm2_main.c`:262-265 | `runSWF_avm2` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/2 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 2L → bw |  |
| `SWFModernRuntime/src/avm2/avm2_main.c`:440-514 | `runSWF_avm2` | `defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/54 | `defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 54L → bw |  |
| `SWFModernRuntime/src/libswf/graphics_stubs.c`:43-47 | — | `!defined(OFFSCREEN_RENDER)` | `defined(USE_WEBGPU) && !defined(NO_GRAPHICS)` | –/0/3 | `!defined(OFFSCREEN_RENDER)` 3L → bw |  |
| `SWFModernRuntime/src/libswf/graphics_stubs.c`:58-60 | — | `!defined(OFFSCREEN_RENDER)` | `defined(USE_WEBGPU) && !defined(NO_GRAPHICS)` | –/0/1 | `!defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/libswf/graphics_stubs.c`:64-66 | — | `!defined(OFFSCREEN_RENDER)` | `defined(USE_WEBGPU) && !defined(NO_GRAPHICS)` | –/0/1 | `!defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/libswf/graphics_stubs.c`:89-132 | — | `!defined(OFFSCREEN_RENDER)` | `defined(USE_WEBGPU) && !defined(NO_GRAPHICS)` | –/0/23 | `!defined(OFFSCREEN_RENDER)` 23L → bw |  |
| `SWFModernRuntime/src/libswf/graphics_stubs.c`:141-417 | `ng_queue_slot_unload_events` | `!defined(OFFSCREEN_RENDER)` | `defined(USE_WEBGPU) && !defined(NO_GRAPHICS)` | –/0/132 | `!defined(OFFSCREEN_RENDER)` 132L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:19-141 | — | `defined(__EMSCRIPTEN__)` | `!defined(NO_GRAPHICS)` | –/0/79 | `defined(__EMSCRIPTEN__)` 79L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:363-365 | `ng_executeGotoTagsOnly` | `!defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/1 | `!defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:373-383 | `tagMain` | `defined(__EMSCRIPTEN__)` | `!defined(NO_GRAPHICS)` | –/0/2 | `defined(__EMSCRIPTEN__)` 2L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:512-514 | `tagMain` | `defined(__EMSCRIPTEN__)` | `!defined(NO_GRAPHICS)` | –/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:612-636 | `tagMain` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/8 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 8L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:638-852 | `tagMain` | `!defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/136 | `!defined(OFFSCREEN_RENDER)` 136L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:908-932 | `tagMain` | `!defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/7 | `!defined(OFFSCREEN_RENDER)` 7L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:934-936 | `tagMain` | `!defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/1 | `!defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:1234-1254 | `tagMain` | `!defined(OFFSCREEN_RENDER) && defined(__EMSCRIPTEN__)` | `!defined(NO_GRAPHICS)` | –/0/8 | `!defined(OFFSCREEN_RENDER) && defined(__EMSCRIPTEN__)` 8L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:1326-1329 | `tagMain` | `!defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/2 | `!defined(OFFSCREEN_RENDER)` 2L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:1332-1334 | `tagMain` | `defined(__EMSCRIPTEN__)` | `!defined(NO_GRAPHICS)` | –/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:1336-1338 | `tagMain` | `defined(__EMSCRIPTEN__)` | `!defined(NO_GRAPHICS)` | –/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:1350-1373 | `tagMain` | `defined(__EMSCRIPTEN__)` | `!defined(NO_GRAPHICS)` | –/0/20 | `defined(__EMSCRIPTEN__)` 20L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:1388-1450 | `tagMain` | `!defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/33 | `!defined(OFFSCREEN_RENDER)` 12/12/33L → bw |  |
| `SWFModernRuntime/src/libswf/swf.c`:1636-1641 | `swfStart` | `!defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/4 | `!defined(OFFSCREEN_RENDER)` 4L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:14-16 | — | `defined(__EMSCRIPTEN__)` | — | 0/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:951-953 | `ng_set_script_only_mode` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:1472-1495 | `advance_sprite_frames` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/10 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 10L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:1628-1721 | `advance_sprite_frames` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/54 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 54L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:2210-2487 | `presync_nested_sprite_currentframe` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/155 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 155L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:2804-2826 | `build_cxform_from_obj` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/15 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 15L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:3376-3383 | `tagSetBackgroundColor` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:3930-3976 | `tagSetBackgroundColor` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/41 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 41L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:3997-4002 | `ng_update_button_states` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:4251-4305 | `upgrade_sprite_initialized` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/28 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 28L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:4379-4384 | `tagFlushPendingEnterFrame` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:4645-4687 | `textfield_glyph_render_cb` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/39 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 39L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:4697-4740 | `textfield_glyph_render_cb` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/41 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 41L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:4752-4756 | `textfield_glyph_render_cb` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/3 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 3L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:4794-4801 | `textfield_glyph_render_cb` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/6 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 6L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:4856-4873 | `textfield_glyph_render_cb` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/16 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 16L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:5317-5363 | `tagRerenderFrame` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/34 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 34L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:5409-5428 | `compute_mc_world_xform` | `!defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/13 | `!defined(OFFSCREEN_RENDER)` 13L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:6227-6248 | `tagShowFrame` | `!defined(OFFSCREEN_RENDER)` | `!defined(NO_GRAPHICS)` | –/0/10 | `!defined(OFFSCREEN_RENDER)` 10L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:7534-7594 | `tagPlaceObject2` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/41 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 41L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:8161-8174 | `tagPlaceObject2` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/4 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 4L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:8276-8318 | `tagPlaceObject2` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/22 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 22L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:8506-8527 | `tagSetClipActions` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/11 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 11L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:8545-8584 | `tagSetClipActions` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/24 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 24L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:8840-8868 | `tagSetClipActions` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/22 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 22L → bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:9751-9800 | `invalidate_descendants_of_mc` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/35 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 35L → bw |  |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:491-510 | `ng_attachMovie` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/8 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 8L → bw |  |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:584-619 | `ng_attachMovie` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/8 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 8L → bw |  |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:763-790 | `ng_attachMovie` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/10 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 10L → bw |  |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:1270-1296 | `ng_gotoFrameByMC` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/10 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 10L → bw |  |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:1348-1376 | `ng_gotoFrameByMC` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/14 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 14L → bw |  |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:1378-1404 | `ng_gotoFrameByMC` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/12 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 12L → bw |  |
| `SWFModernRuntime/src/libswf/tag_stubs.c`:2758-2819 | `ng_getTextFieldIdx` | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` | — | 0/0/44 | `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` 44L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:43-68 | — | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/16 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 16L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:510-513 | `create_dummy_texture` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/2 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 2L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:518-771 | `create_dummy_texture` | `defined(__EMSCRIPTEN__)` | — | 0/0/144 | `defined(__EMSCRIPTEN__)` 144L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:934-954 | `render_webgpu_init` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/18 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 18L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:1038-1045 | `create_buffers_and_upload` | `defined(__EMSCRIPTEN__)` | — | 0/0/4 | `defined(__EMSCRIPTEN__)` 4L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:1814-1843 | `render_webgpu_upload_stage_transform` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/8 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 8L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:1851-1863 | `render_webgpu_open_pass` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/7 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 7L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:1873-1884 | `render_webgpu_open_pass` | `defined(__EMSCRIPTEN__)` | `else of render_webgpu.c:1868` | 0/–/6 | `defined(__EMSCRIPTEN__)` 6L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:2636-2657 | `render_webgpu_close_pass` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/15 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 15L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:2661-2663 | `render_webgpu_close_pass` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/1 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 1L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:2665-2673 | `render_webgpu_close_pass` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/5 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 5L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:2675-2687 | `render_webgpu_close_pass` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/7 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 7L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:2695-2710 | `render_webgpu_close_pass` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/5 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 5L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:3589-3594 | `render_webgpu_free` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/4 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 4L → bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:3698-3821 | `render_webgpu_save_png` | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` | — | 0/0/97 | `defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` 97L → bw |  |
| `SWFRecomp/wasm_wrappers/main.c`:25-86 | — | `defined(__EMSCRIPTEN__)` | — | 0/0/31 | `defined(__EMSCRIPTEN__)` 31L → bw |  |

## Secondary: graphics-native vs no-graphics asymmetry

Browser-WASM gets code, but the two native configs disagree. Mostly benign
(`NO_GRAPHICS` stubs vs real renderer), listed for completeness — this is the
population the graphics-per-change CI policy already covers.

### `native-asym` — 38 sites

#### `SWFModernRuntime/include/audio/audio.h` — 1

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/include/audio/audio.h`:27-154 | — | `!defined(NO_GRAPHICS)` | — | 0/74/74 | `!defined(NO_GRAPHICS)` 74L → gn,bw |  |

#### `SWFModernRuntime/include/libswf/swf.h` — 1

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/include/libswf/swf.h`:303-335 | — | `!defined(NO_GRAPHICS)` | — | 0/25/25 | `!defined(NO_GRAPHICS)` 25L → gn,bw |  |

#### `SWFModernRuntime/include/libswf/tag.h` — 1

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/include/libswf/tag.h`:27-29 | — | `!defined(NO_GRAPHICS)` | — | 0/1/1 | `!defined(NO_GRAPHICS)` 1L → gn,bw |  |

#### `SWFModernRuntime/src/actionmodern/action.c` — 7

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/src/actionmodern/action.c`:26842-27194 | `actionIterateTextFieldGlyphs` | `!defined(NO_GRAPHICS)` | — | 0/261/261 | `!defined(NO_GRAPHICS)` 261L → gn,bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:55780-55782 | `actionSetTarget` | `!defined(NO_GRAPHICS)` | — | 0/1/1 | `!defined(NO_GRAPHICS)` 1L → gn,bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:55800-55802 | `actionSetTarget` | `!defined(NO_GRAPHICS)` | — | 0/1/1 | `!defined(NO_GRAPHICS)` 1L → gn,bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:55813-55815 | `actionSetTarget` | `!defined(NO_GRAPHICS)` | — | 0/1/1 | `!defined(NO_GRAPHICS)` 1L → gn,bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:55942-55944 | `actionSetTarget` | `!defined(NO_GRAPHICS)` | — | 0/1/1 | `!defined(NO_GRAPHICS)` 1L → gn,bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:70218-70225 | `actionWaitForFrame` | `!defined(NO_GRAPHICS)` | — | 0/4/4 | `!defined(NO_GRAPHICS)` 4L → gn,bw |  |
| `SWFModernRuntime/src/actionmodern/action.c`:70332-70341 | `actionWaitForFrame2` | `!defined(NO_GRAPHICS)` | — | 0/4/4 | `!defined(NO_GRAPHICS)` 4L → gn,bw |  |

#### `SWFModernRuntime/src/audio/audio.c` — 1

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/src/audio/audio.c`:1-677 | — | `!defined(NO_GRAPHICS)` | — | 0/533/533 | `!defined(NO_GRAPHICS)` 533L → gn,bw |  |

#### `SWFModernRuntime/src/audio/audio_output_web.c` — 1

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/src/audio/audio_output_web.c`:1-125 | — | `!defined(NO_GRAPHICS)` | — | 0/10/80 | `!defined(NO_GRAPHICS)` 10/10/80L → gn,bw |  |

#### `SWFModernRuntime/src/avm2/avm2_display.c` — 1

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/src/avm2/avm2_display.c`:9359-9932 | `avm2_cpu_dump_frame` | `defined(OFFSCREEN_RENDER) \|\| (defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS))` | — | 0/407/398 | `defined(OFFSCREEN_RENDER) \|\| (defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS))` 391/407/398L → gn,bw |  |

#### `SWFModernRuntime/src/avm2/avm2_main.c` — 2

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/src/avm2/avm2_main.c`:252-267 | `runSWF_avm2` | `!defined(NO_GRAPHICS)` | — | 0/1/3 | `!defined(NO_GRAPHICS)` 1/1/3L → gn,bw |  |
| `SWFModernRuntime/src/avm2/avm2_main.c`:410-421 | `runSWF_avm2` | `defined(OFFSCREEN_RENDER) \|\| (defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS))` | — | 0/10/10 | `defined(OFFSCREEN_RENDER) \|\| (defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS))` 10L → gn,bw |  |

#### `SWFModernRuntime/src/avm2/avm2_media.c` — 8

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/src/avm2/avm2_media.c`:29-31 | — | `!defined(NO_GRAPHICS)` | — | 0/1/1 | `!defined(NO_GRAPHICS)` 1L → gn,bw |  |
| `SWFModernRuntime/src/avm2/avm2_media.c`:43-51 | — | `!defined(NO_GRAPHICS)` | — | 0/1/1 | `!defined(NO_GRAPHICS)` 1L → gn,bw |  |
| `SWFModernRuntime/src/avm2/avm2_media.c`:218-229 | `sound_channel_native_init` | `!defined(NO_GRAPHICS)` | — | 0/8/8 | `!defined(NO_GRAPHICS)` 8L → gn,bw |  |
| `SWFModernRuntime/src/avm2/avm2_media.c`:264-272 | `sc_set_sound_transform` | `!defined(NO_GRAPHICS)` | — | 0/7/7 | `!defined(NO_GRAPHICS)` 7L → gn,bw |  |
| `SWFModernRuntime/src/avm2/avm2_media.c`:280-289 | `sc_get_position` | `!defined(NO_GRAPHICS)` | — | 0/6/6 | `!defined(NO_GRAPHICS)` 6L → gn,bw |  |
| `SWFModernRuntime/src/avm2/avm2_media.c`:361-366 | `sm_set_sound_transform` | `!defined(NO_GRAPHICS)` | — | 0/1/1 | `!defined(NO_GRAPHICS)` 1L → gn,bw |  |
| `SWFModernRuntime/src/avm2/avm2_media.c`:516-539 | `sound_play` | `!defined(NO_GRAPHICS)` | — | 0/19/19 | `!defined(NO_GRAPHICS)` 19L → gn,bw |  |
| `SWFModernRuntime/src/avm2/avm2_media.c`:611-617 | `avm2_gc_mark_roots_media` | `!defined(NO_GRAPHICS)` | — | 0/5/5 | `!defined(NO_GRAPHICS)` 5L → gn,bw |  |

#### `SWFModernRuntime/src/libswf/graphics_stubs.c` — 1

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/src/libswf/graphics_stubs.c`:17-419 | — | `defined(USE_WEBGPU) && !defined(NO_GRAPHICS)` | — | 0/20/170 | `defined(USE_WEBGPU) && !defined(NO_GRAPHICS)` 170/20/170L → gn,bw |  |

#### `SWFModernRuntime/src/libswf/swf.c` — 1

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/src/libswf/swf.c`:1-1663 | — | `!defined(NO_GRAPHICS)` | — | 0/543/635 | `!defined(NO_GRAPHICS)` 494/543/635L → gn,bw |  |

#### `SWFModernRuntime/src/libswf/tag.c` — 9

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/src/libswf/tag.c`:18-21 | — | `!defined(NO_GRAPHICS)` | — | 0/2/2 | `!defined(NO_GRAPHICS)` 2L → gn,bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:2489-3333 | `upgrade_attached_clip_initialized` | `!defined(NO_GRAPHICS)` | — | 0/534/511 | `!defined(NO_GRAPHICS)` 468/534/511L → gn,bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:4394-4971 | `tagFlushPendingEnterFrame` | `!defined(NO_GRAPHICS)` | — | 0/311/416 | `!defined(NO_GRAPHICS)` 311/311/416L → gn,bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:5365-5545 | `finalize_pending_removes_recursive` | `!defined(NO_GRAPHICS)` | — | 0/104/117 | `!defined(NO_GRAPHICS)` 79/104/117L → gn,bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:5782-5826 | `tagShowFrame` | `!defined(NO_GRAPHICS)` | — | 0/3/22 | `!defined(NO_GRAPHICS)` 3/3/22L → gn,bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:5828-6319 | `tagShowFrame` | `!defined(NO_GRAPHICS)` | — | 0/322/332 | `!defined(NO_GRAPHICS)` 332/322/332L → gn,bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:9939-9941 | `tagRemoveObject` | `!defined(NO_GRAPHICS)` | — | 0/1/1 | `!defined(NO_GRAPHICS)` 1L → gn,bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:10165-10167 | `tagRemoveObject2` | `!defined(NO_GRAPHICS)` | — | 0/1/1 | `!defined(NO_GRAPHICS)` 1L → gn,bw |  |
| `SWFModernRuntime/src/libswf/tag.c`:11270-11281 | `ng_registerBitmapMetadata` | `!defined(NO_GRAPHICS)` | — | 0/9/9 | `!defined(NO_GRAPHICS)` 9L → gn,bw |  |

#### `SWFModernRuntime/src/rendering/render_webgpu.c` — 3

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFModernRuntime/src/rendering/render_webgpu.c`:826-828 | `render_webgpu_init` | `!defined(OFFSCREEN_RENDER)` | — | 1/0/1 | `!defined(OFFSCREEN_RENDER)` 1L → ng,bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:2716-2721 | `render_webgpu_close_pass` | `!defined(OFFSCREEN_RENDER)` | — | 2/0/2 | `!defined(OFFSCREEN_RENDER)` 2L → ng,bw |  |
| `SWFModernRuntime/src/rendering/render_webgpu.c`:2725-2727 | `render_webgpu_close_pass` | `!defined(OFFSCREEN_RENDER)` | — | 1/0/1 | `!defined(OFFSCREEN_RENDER)` 1L → ng,bw |  |

#### `SWFRecomp/wasm_wrappers/main.c` — 1

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | triage |
|---|---|---|---|---|---|---|
| `SWFRecomp/wasm_wrappers/main.c`:109-134 | `main` | `!defined(NO_GRAPHICS)` | — | 0/24/24 | `!defined(NO_GRAPHICS)` 24L → gn,bw |  |

## Sites whose outcome depends on non-config macros

Reported honestly rather than guessed. The `depends` column names the macros
that decide the site.

### `depends` — 17 sites

| site | function | condition | enclosing | lines ng/gn/bw | arms (size → configs) | depends | triage |
|---|---|---|---|---|---|---|---|
| `SWFModernRuntime/src/actionmodern/action.c`:690-706 | `actionSetTimeoutJmp` | `!defined(__EMSCRIPTEN__) && (defined(__linux__) \|\| defined(__APPLE__))` | — | 0/0/0 | `!defined(__EMSCRIPTEN__) && (defined(__linux__) \|\| defined(__APPLE__))` 15L → ng?,gn? | `__APPLE__`, `__linux__` |  |
| `SWFModernRuntime/src/actionmodern/action.c`:5720-6058 | `actionEI_call` | `defined(WITH_AP) && !defined(__EMSCRIPTEN__)` | — | 0/0/0 | `defined(WITH_AP) && !defined(__EMSCRIPTEN__)` 256L → ng?,gn? | `WITH_AP` |  |
| `SWFModernRuntime/src/actionmodern/action.c`:38316-38349 | `ensureGlobalInit` | `defined(__EMSCRIPTEN__)` | — | 0/0/10 | `defined(__EMSCRIPTEN__)` 10L → bw; `defined(WITH_AP)` 8L → ng?,gn? | `WITH_AP` |  |
| `SWFModernRuntime/src/actionmodern/rando_ap_wasm.c`:17-133 | — | `defined(WITH_AP) && defined(__EMSCRIPTEN__)` | — | 0/0/0 | `defined(WITH_AP) && defined(__EMSCRIPTEN__)` 84L → bw? | `WITH_AP` |  |
| `SWFModernRuntime/src/libswf/swf.c`:1286-1290 | `tagMain` | `defined(OFFSCREEN_RENDER) && defined(MAX_FRAMES)` | `!defined(NO_GRAPHICS)` | –/0/1 | `defined(OFFSCREEN_RENDER) && defined(MAX_FRAMES)` 1L → gn?; `(else)` 1L → bw,gn? | `MAX_FRAMES` |  |
| `SWFModernRuntime/src/memory/heap.c`:52-89 | — | `defined(__wasi__)` | — | 0/0/0 | `defined(__wasi__)` 1L → ng?,gn?,bw?; `defined(__EMSCRIPTEN__) && defined(SWF_AVM2)` 1L → bw?; `defined(__EMSCRIPTEN__)` 1L → bw?; `!defined(__LP64__)` 1L → ng?,gn?; `(else)` 1L → ng?,gn? | `SWF_AVM2`, `__LP64__`, `__wasi__` |  |
| `SWFRecomp/wasm_wrappers/display_bridge.c`:20-22 | — | `defined(__EMSCRIPTEN__)` | `defined(HAS_DISPLAY_BRIDGE)` | 0/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw? | `HAS_DISPLAY_BRIDGE` |  |
| `SWFRecomp/wasm_wrappers/display_bridge.c`:46-48 | — | `defined(__EMSCRIPTEN__)` | `defined(HAS_DISPLAY_BRIDGE)` | 0/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw? | `HAS_DISPLAY_BRIDGE` |  |
| `SWFRecomp/wasm_wrappers/display_bridge.c`:55-57 | `dbgRootFrame` | `defined(__EMSCRIPTEN__)` | `defined(HAS_DISPLAY_BRIDGE)` | 0/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw? | `HAS_DISPLAY_BRIDGE` |  |
| `SWFRecomp/wasm_wrappers/display_bridge.c`:65-67 | `dbgIsPlaying` | `defined(__EMSCRIPTEN__)` | `defined(HAS_DISPLAY_BRIDGE)` | 0/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw? | `HAS_DISPLAY_BRIDGE` |  |
| `SWFRecomp/wasm_wrappers/display_bridge.c`:76-78 | `dbgLastKey` | `defined(__EMSCRIPTEN__)` | `defined(HAS_DISPLAY_BRIDGE)` | 0/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw? | `HAS_DISPLAY_BRIDGE` |  |
| `SWFRecomp/wasm_wrappers/display_bridge.c`:92-94 | `dbgClipInfo` | `defined(__EMSCRIPTEN__)` | `defined(HAS_DISPLAY_BRIDGE)` | 0/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw? | `HAS_DISPLAY_BRIDGE` |  |
| `SWFRecomp/wasm_wrappers/display_bridge.c`:128-130 | `dbgChildState` | `defined(__EMSCRIPTEN__)` | `defined(HAS_DISPLAY_BRIDGE)` | 0/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw? | `HAS_DISPLAY_BRIDGE` |  |
| `SWFRecomp/wasm_wrappers/display_bridge.c`:139-141 | `dbgRootVarNum` | `defined(__EMSCRIPTEN__)` | `defined(HAS_DISPLAY_BRIDGE)` | 0/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw? | `HAS_DISPLAY_BRIDGE` |  |
| `SWFRecomp/wasm_wrappers/display_bridge.c`:193-195 | `getDisplayListJSON` | `defined(__EMSCRIPTEN__)` | `defined(HAS_DISPLAY_BRIDGE)` | 0/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw? | `HAS_DISPLAY_BRIDGE` |  |
| `SWFRecomp/wasm_wrappers/display_bridge.c`:270-272 | `getSpriteChildrenJSON` | `defined(__EMSCRIPTEN__)` | `defined(HAS_DISPLAY_BRIDGE)` | 0/0/1 | `defined(__EMSCRIPTEN__)` 1L → bw? | `HAS_DISPLAY_BRIDGE` |  |
| `SWFRecomp/wasm_wrappers/display_bridge.c`:312-379 | `getSpriteChildrenJSON` | `defined(USE_WEBGPU) && defined(__EMSCRIPTEN__)` | `defined(HAS_DISPLAY_BRIDGE)` | 0/0/54 | `defined(USE_WEBGPU) && defined(__EMSCRIPTEN__)` 54L → bw? | `HAS_DISPLAY_BRIDGE` |  |

<!-- BEGIN HAND-WRITTEN SECTIONS (preserved on regeneration) -->

## Trend: browser-WASM fix rate (hand-written, 2026-07-23)

Everything below the marker is hand-written and preserved when the tool
regenerates the sections above. It answers the Phase 5 question: *has the
browser-WASM bug discovery rate actually decayed, supporting "we caught most of
them"?*

### Raw counts

Commits whose subject mentions browser-WASM (`git log -i --grep='browser-wasm'`):

| Month | subject mentions browser-WASM | of those, `fix…` |
|---|---:|---:|
| 2026-05 | 66 | 1 |
| 2026-06 | 91 | 56 |
| 2026-07 (to the 23rd) | 15 | 5 |

Commits that changed a `#if`-family directive naming one of the three key
symbols under `SWFModernRuntime/` or `SWFRecomp/wasm_wrappers/`
(`git log -G` over the directive pattern) — i.e. gate churn rather than
subject-line self-reporting:

| Month | gate-directive commits | of those, `fix…` |
|---|---:|---:|
| 2026-04 | 25 | 2 |
| 2026-05 | 69 | 3 |
| 2026-06 | 47 | 34 |
| 2026-07 (to the 23rd) | 18 | 6 |

Read alone, this looks like decay: 56 browser-WASM fix commits in June, 5 in
July.

### …but the denominator moved

Weekly, alongside an exposure proxy — commits naming one of the AVM1 browser
games under active debug (pacman / tetris / minesweeper / snake / pong / dj /
glaiel / flasharchive):

| Week | game-debug commits (exposure) | browser-WASM commits | ratio |
|---|---:|---:|---:|
| 2026-W22 | 85 | 59 | 0.69 |
| 2026-W23 | 13 | 3 | 0.23 |
| 2026-W24 | 37 | 19 | 0.51 |
| 2026-W25 | 66 | 34 | 0.52 |
| 2026-W26 | 38 | 35 | **0.92** |
| 2026-W27 | 20 | 5 | 0.25 |
| 2026-W28 | 3 | 1 | — |
| 2026-W29 | 1 | 6 | — |
| 2026-W30 | 1 | 3 | — |

The `fix(browser-wasm)`-prefixed subset per week: W23 1, W24 11, W25 21,
W26 23, W27 4, W30 1.

**The decay is an exposure artifact, not exhaustion.** The per-exposure hit
rate was at its *highest* (0.92) in W26, the last full week of AVM1 browser
game debugging, and the campaign then stopped for reasons unrelated to running
out of bugs: July's browser-WASM commits are AVM2 bring-up features (Stage 13a
browser entry, live keyboard, real audio — 2026-07-13/15/16), not divergence
fixes, and July's overall commit mix is AVM2 perf, the AVM1 dispatch refactor,
and docs. When we stopped looking, we were still finding roughly one browser
branch bug per game-debug commit.

### What this means for the hypothesis

"By now we caught most of them" is **not supported** by the fix-rate curve. The
supporting evidence would be a falling hit rate under *constant* exposure; what
the log shows is constant-or-rising hit rate under *falling* exposure.

The surface that remains is quantified above: **157 sites where browser-WASM
compiles nothing while a native config does** (118 `browser-none` + 39
`browser-none-partial`), concentrated in `action.c` (61) and `tag.c` (49) —
exactly the two shared files where the historic bugs came from. Most are
presumably intentional (offscreen readback, replay input, capture); the triage
pass has to say which. Until then the honest position is: the index is 157
entries long and unread, not empty.

### Follow-up (not done here, deliberately)

1. **Triage pass** — fill the `triage` column (`intentional` / `suspicious` /
   `bug`). Needs deep runtime context; largest-first is a reasonable order
   (`action.c`:17312-17558 is 187 lines browser never sees).
2. **Probe prioritisation** — the `suspicious` rows tell
   `SWFRecompDocs/plans/wasm-probe-suite.md` which probe SWFs pay off first.
3. **Ratchet** (Phase 5 step 4, optional) — CI-fail when the flagged count
   grows without a doc update. Deferred: the count is meaningless until the
   triage column exists, so a ratchet now would just pin 157.

## Triage pass (2026-07-23)

Method: sites whose enclosing function also contains a `browser-only` or
`all-configs` site were classified `intentional-paired` (the browser arm
lives elsewhere in the same function — 98 sites, spot-checked). The 59
unpaired sites were read individually. Verdicts:

- **`intentional-paired` (98)** — split implementations; presumption, not
  proof. Revisit a site only if a browser-specific bug lands in its function.
- **`intentional-model` (21)** — the native sprite-advance/goto machinery
  (`ng_*` helpers in tag.c, rewind cleanup, inline catch-up in
  `actionNextFrame`). Browser-WASM deliberately runs a different, lighter
  model (see tag.c:212 comment and the Phase 3 wrap-promotion gate in swf.c).
  Per-site absence is by design; the RISK is model drift, which per-site
  triage cannot close — that is what the wasm-probe-suite plan is for.
- **`intentional` (17)** — struct-field parity blocks, native-only
  diagnostics (object.c mem tracking), test-harness hooks (fscommand
  `capture`), stub files, headers, the swf_core.c whole-file site.
- **`suspicious` (21)** — browser-WASM silently no-ops or returns degraded
  values with NO parallel path found. None promoted to `bug` without a
  reproducing SWF; these were the probe-suite priority list, and the probe
  pass below has now adjudicated all ten clusters.

## Probe adjudication (2026-07-23)

One probe SWF per suspicious cluster, under
`SWFRecomp/tests/wasm_probes/` (group D in that suite's README). Method per
probe: hand-built swfmill SWF that both `trace()`s the value under test and
encodes it as a marker position, then

1. **Ruffle oracle** — `exporter --trace-log` gives Flash's answer as trace
   text *and* the golden PNG (`tools/capture_ruffle_golden.sh`, which now
   writes `<probe>/ruffle_trace.txt`);
2. **NO_GRAPHICS native** and **graphics-native** runs, to confirm the
   divergence is browser-only and not a probe that tests the wrong thing;
3. **browser-WASM** via `tools/wasm_probe_runner.py`, which as of this pass
   captures page console output and asserts it against `expected_trace.txt`.

Ruffle and both native modes agreed on every probe except
`droptarget_scripted` (see its row). Verdicts:

| cluster | sites | verdict | evidence |
|---|---|---|---|
| `transform.matrix` / `transform.colorTransform` setters | action.c 9072, 9146 | **bug** (probe: `transform_matrix_set`) | assigning a `flash.geom.Matrix` and a `flash.geom.ColorTransform` is discarded: `_x` traces 40 (placement) vs 80 expected, the box neither moves nor tints, 4000 px differ from the Ruffle golden |
| `Color.getTransform` | action.c 10907 | **bug** (probe: `color_gettransform`) | `setTransform({rb:255})` then `getTransform().rb` traces 0 vs 255; the box also renders un-tinted, so *both* halves of the round-trip are gated |
| `TextFormat` from fields | action.c 17312 | **bug** (probe: `textformat_from_field`) | `field.getTextFormat().size`/`.align` trace `undefined`/`undefined` vs 12/`left` |
| `GetProperty` display-truth reads | action.c 43212–43292 | **bug** (probe: `getproperty_timeline_x`) | `_x`/`_y` of a purely timeline-moved clip trace **0, 0** vs 200, 100 — browser-WASM's `mc->x`/`mc->y` never track timeline MOVE tags at all, so the gated display-entry read is the only correct source. Widest blast radius of the set |
| …its invalid-tellTarget half | action.c 43212–43221 | **still suspicious, unprobed** | the pre-existing `settarget_failure_flag` probe is green, but it exercises `SetProperty` after a failed `SetTarget`, not `GetProperty` — this `g_settarget_invalid` early-return is a different site and nothing built here reads a property through it. One more probe would close it |
| `typeof` refinement | action.c 43511, 43545 | **bug** (probe: `typeof_textfield_button`) | SWF8 `typeof` traces `movieclip`/`movieclip` vs `object`/`object` for a textfield and a button |
| `_alpha` placement-cxform read | action.c 26084 | **bug** (probe: `alpha_cxform_read`) | `_alpha` of a clip faded to 50% by a placement CXFORM traces 100 vs 50. The *render* is correct — only the AS read is stale |
| `delete` child-MC guard | action.c 43861 | **intentional** (probe: `delete_child_mc` green) | the gated `success = false` is redundant with the unconditional `success = false` on the line above it; browser traces `false` / `movieclip`, matching Ruffle exactly |
| var→textfield sync on `var` declare | action.c 42849 | **intentional** (probe: `var_textfield_sync` green) | browser matches on `text` **and** on `length` (7, not INIT's 4), so the field's property bag genuinely tracks the write — the equivalent path is the un-gated TextField binding machinery (`actionRegisterTextFieldBinding` / the placement-time initial bind around action.c:21690–21760, mirroring Ruffle's `Avm1TextFieldBinding::bind_variables`), not the gated `ng_syncVarToTextFields` call |
| drag: `_droptarget` + virtual position | action.c 32895, 70182 | **couldn't probe** (probe: `droptarget_scripted`, KNOWN_RED) | browser traces `""` — **and so does Ruffle**. Ruffle derives `_droptarget` from mouse-driven `update_drag`, which never runs without pointer input, so the oracle is blind here; our native builds synthesize `/b` from the virtual hotspot, making the probe's red native-vs-browser rather than Flash-vs-browser. Adjudicating it needs pointer injection the runner lacks *and* the Ruffle exporter cannot mirror. Side finding: native and Ruffle genuinely disagree on scripted-drag `_droptarget` |
| focus rect info | action.c 71861 | **deferred, not probed** | needs Tab-key injection the runner doesn't have. Runner follow-up, tracked in `SWFRecompDocs/plans/wasm-probe-suite.md` |
| ByteArray charset | avm2_bytearray.c 475, 1010, 1034 | **deferred, not probed** | AVM2, which uses a different browser harness. Logged under the AVM2 backlog rather than built here |

**Six bugs, two intentional, one couldn't-probe, two deferred, one still
open** (the invalid-tellTarget `GetProperty` row). The six reds
are the work list for a runtime-fix session; each ships with its probe as the
regression test. No runtime source was changed in this pass.

The reds also answer the trend question at the top of this doc empirically:
of eight clusters that could be probed, six were real gaps. "By now we caught
most of them" is not just unsupported by the fix-rate curve — it is false on
the first eight clusters anyone actually tested.

Triage cells in the tables are preserved across regeneration
(`_harvest_triage` in the tool, added with this pass); a site whose line
numbers shift on regen drops its cell back to empty and should be re-keyed
from this section.
