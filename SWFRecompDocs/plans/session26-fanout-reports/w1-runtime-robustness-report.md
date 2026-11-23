# s26 w1-runtime-robustness: silent capacity drops, the float-through-u64 store, strict aliasing

Base: `origin/master` `ec07cc9e` (code `697669e5f`). Cloud box: SETUP_STATUS all OK (apt, Pillow, Dawn).
Downloaded categories: `avm1` (784 tests, `download_tests.sh avm1`; upstream Ruffle master at run time).

**New files** (all under this directory; the fixtures ship INSIDE the prototype patch, not as live test dirs):
- `w1-runtime-robustness-report.md` (this file)
- `w1-runtime-robustness-prototype.patch`: `git diff origin/master -- SWFModernRuntime` plus two new fixture
  generators (`regression/avm1_many_defs_registry/{create_test_swf.py,test.toml}`,
  `regression/avm1_pixelbounds_dynamic_child/{create_test_swf.py,test.toml}`). Each `output.txt` still needs the
  oracle (see LOCAL ORACLE REQUESTS). Generate each `test.swf` with `python3 create_test_swf.py`.

## Verdicts

| # | Item | Verdict | Priced flips |
|---|---|---|---|
| 1 | Fixed-cap table | DONE (below). The brief's 5 caps are verified. Brief numbers match: buttons 64, fonts 32, videos 32, sounds 128, exports 1024. The audit found **4 more that drop on real content**: registerClass 128, bitmaps 128 (BitmapData.loadBitmap), sprite labels 256, init-action guard ids < 512. It also found a 512-glyph font truncation. | — |
| 2 | Growable prototype | **GO for wave 2 / land as-is.** 9 registries made growable. Fixture `avm1_many_defs_registry` flips **8 probe lines** in both modes. **0 movement** on the full regression suite (132) + 40-test argued avm1 sweep, both modes, image lines identical. | No corpus flips (no corpus test exceeds a cap; real-game robustness: N/flasharchive class) |
| 3 | `action.c:10605` u64 store | **FIXED in prototype.** gcc 13 -O2 DROPS this exact store shape in isolation. In today's TU the store survives (asm checked), so it is latent UB, not a live bug. | none (no behaviour change; fixture `avm1_pixelbounds_dynamic_child` passes before and after) |
| 4 | Aliasing | **Recommend BOTH:** add `-fno-strict-aliasing` to every gcc/clang path (zero measured cost) **and** make `VAL()` a `may_alias` typedef macro (one header line, fixes ~800 sites incl. generated code). | see §4 |

## 1. Fixed-cap table

"Drops" = the entry is silently not recorded (no stderr), unless noted. "Exceeds" = real SWF class that can cross it.
N numbers: `n-tile-color-hud-report.md` §85 (57 buttons, 5 fonts, 39 sounds, 197 EditTexts, ~1600 ExportAssets mostly
duplicate). Bloxorz 516 bitmaps: `games/FLASHARCHIVE_BUILD_RESULTS.md:65`. AVM2 (Seedling 284 bitmaps / 88 sounds,
Elephant Quest) never reads these ng_* registries (`grep` of `src/avm2`: no hits), so every row below is **AVM1-only**.

### Definition registries (tag-time; drop = wrong behaviour for the whole run) — all FIXED in prototype

| Name | Value | origin/master file:line | What it drops (observed with the fixture) | Can exceed |
|---|---|---|---|---|
| `MAX_BUTTONS_NG` | 64 | `ng_shared.c:349` | 65th+ DefineButton not a button: `typeof`→`movieclip`, `_width` 200 (whole-stage fallback), no button state machine | big AS1/2 menus/levels (N has 57, close) |
| `MAX_VIDEOS_NG` | 32 | `ng_shared.c:369` | 33rd+ DefineVideoStream not a video: `typeof`→`movieclip`, `_width` 200 | rare (video-heavy movies) |
| `MAX_FONTS_NG` | 32 | `ng_shared.c:472` | 33rd+ font has no metrics: `textWidth` 0, layout on builtin. The same cap also refused device faces (`ng_register_device_font`) | multi-font AS2 UIs, component skins |
| `MAX_FONT_GLYPHS` | 512 | `ng_shared.c:473` | glyphs past 512 of an embedded font: no advance/lookup (CJK / full-charset fonts) | any full-charset embedded font |
| `MAX_FONT_NAMES_NG` | 256 | `ng_shared.c:755` | embedded-font name registrations past 256 (fallback scan masked part of it) | rare |
| `MAX_FONT_EXPORTS_NG` | 256 | `ng_shared.c:758` | `tagRegisterFontExport` sees EVERY export, so any font exported after the 256th distinct linkage name is unresolvable by name | games with many linkage symbols (N-class) |
| `MAX_DEVICE_FONTS_NG` | 16 | `ng_shared.c:961` | test.toml device faces past 16 (harness only) | test harness only |
| `MAX_EXPORTED_SYMBOLS` | 1024 | `ng_shared.c:1308` | distinct linkage names past 1024: attachMovie / registerClass / attachSound / loadBitmap fail (`typeof`→undefined) | asset-heavy AS2 games (N is 1600 ExportAssets but deduped) |
| `MAX_SOUND_METADATA` | 128 | `ng_shared.c:1455` | 129th+ DefineSound: `Sound.duration` undefined | sound-heavy AS2 games |
| `MAX_REGISTERED_CLASSES` | 128 ×2 | `registered_class.c:36` | 129th+ `Object.registerClass` symbol never registered: attached clip has no class (`k` undefined) | class-per-symbol AS2 games |
| `MAX_BITMAP_DEFS` | 128 | `tag.c:15055` | 129th+ bitmap: `BitmapData.loadBitmap` → undefined | **Bloxorz (516)**, any bitmap-heavy AS2 game |
| `MAX_SPRITE_LABEL_ENTRIES` | 256 | `tag.c:13860` | 257th+ labelled sprite: `gotoAndStop("L")` finds nothing (cf stays 1) | big AS1/2 games (labelled state clips) |
| `MAX_INIT_ACTION_CHARS` / `_MOVIES` | 512 / 8 | `tag.c:13844-13846` | sprite id ≥ 512: once-only guard OFF (init re-runs whenever its emission site re-executes); movie ≥ 8 aliases movie 0 (shadows its init) | any SWF with > 512 chars + #initclip. **Fixture shows no re-run** on root revisit (the root prologue is not re-entered), so the risk is the sprite-internal emission (`swf.cpp:7067`) |

### Other fixed caps (audited, NOT changed). Each names its overflow behaviour and a completion mechanism.

| Name | Value | file:line | Overflow behaviour | Verdict |
|---|---|---|---|---|
| `MAX_CXFORM_OVERRIDES` | 256 | `tag.c:3014` | save/restore stack: pushes past 256 are **not restored**. Pushes happen for every entry whose `cxform_id` changes, including inherited parent slots (`tag.c:4011`), not just the 256 dynamic slots. A tinted container with > 256 children leaves stale dynamic slot ids into the next frame. This is the exact hazard the `MAX_XFORM_OVERRIDES` comment (`tag.c:2846`) documents. | **LEAD (pixel):** make it growable (S). Needs a render fixture: tinted parent + 300 children, 2 frames. |
| `MAX_EXT_FILTERS` / `MAX_FILTER_LISTS` | 32 / 32 | `tag.c:14264/14352` | filter side tables keyed by root depth: > 32 filtered root depths lose their filters | LEAD (pixel), S: growable + fixture |
| `MAX_SCROLL_CROPS`, `MAX_TEXT_CULLED` | 64, 64 | `tag.c:2864/2971` | per-frame render tables: entries past 64 lose scrollRect crop / culling | LEAD, low risk |
| `MAX_TF_PARAGRAPHS`, `MAX_LAYOUT_LINES` | 32, 256 (stack locals) | `tag.c:7287`, `ng_shared.c:2116` | text layout of > 32 paragraphs / > 256 lines truncated (render / scroll math) | LEAD for long text fields (high scores, credits) |
| `MAX_SPRITE_PLACEMENT_ENTRIES` | 1024 | `tag.c:13922` | sprites past 1024: survives_rewind degrades to clear-all (documented in place) | fine for now |
| `MAX_FUNCTIONS` | 2048 | `action.c:949` | named top-level DefineFunction past the cap: **prints `ERROR: Function registry full` and does not define the function** (loud but fatal). Natives use part of it. | AS2 class methods are anonymous, so rare. Growable is S. |
| `MAX_LAZY_PROTOS` 128, `MAX_PROTO_STUB_FUNCS` 192, `MAX_WATCH_ENTRIES` 64, `MAX_EI_CALLBACKS` 32, `MAX_CLONE_DEPTH_ENTRIES` 128 (`tag_stubs.c:62`), `MAX_CONSTRUCT_PARAMS` 64 | | `action.c:17473/4971/1030/6652` | runtime registries: silent drop | low priority; same pattern if hit |
| `MAX_CHILD_MOVIECLIPS` 16384, `MAX_XFORM_OVERRIDES` 8192, `MAX_BITMAP_NATIVES` 8192, `MAX_LEVELS` 128 | | `action.c:23030`, `tag.c:2850` | sized well above observed use | leave |
| scope/this/exception/super/special depths, LC/NetStream/socket/timer pools (`MAX_TIMERS` 64, `MAX_SOUND_CHANNELS` 32, ...) | | various | recursion limits and live-object pools, not definition registries | out of scope (Flash has its own limits) |

Recompiler-emitted tables: no fixed caps (`grep MAX_` in `SWFRecomp/src` finds only the emitted `MAX_STRING_ID`; the
tables are sized from the SWF).

## 2. Prototype (`w1-runtime-robustness-prototype.patch`, 560 lines of runtime diff)

Pattern: `be31edbfd`'s `ng_table_grow` (doubling realloc, zero-filled tail, entry dropped only on OOM). It is now
**non-static**, declared in `tag.h`, so `tag.c` and `registered_class.c` reuse it.

**Functions touched** (for `n-pixel-pass` merge planning):
- `ng_shared.c`: `ng_table_grow` (static→extern), `ng_record_button`, `ng_find_video`, `ng_record_video`,
  `ng_getVideoDimensions`, `ng_getVideoCodec`, `ng_getVideoDeblocking`, new `ng_font_slot_reserve`,
  `ng_ensure_builtin_font`, `ng_record_font`, `ng_record_font_metrics`, `ng_add_font_name`, `tagRegisterFontExport`,
  `ng_resolveTextFormatFontId` (dropped the dead overflow fallback), `ng_register_device_font`,
  `ng_register_export_entry`, `ng_registerSoundMetadata`. Struct decls changed: `ng_fonts` (inline 512-glyph tables
  removed, `NG_FONT_CODE/ADV` read `ext_*` only), `ng_videos` (5 parallel arrays → 1 struct), `ng_exported_symbols`
  (`name` heap-owned and never moves, because `ng_getExportNameForCharId` / `ng_forEachExportName` hand the pointer out).
- `tag.c`: `tagDoInitActionGuarded` (bitset over the full u16 id space per movie id, rows lazily allocated),
  `tagSetSpriteLabels`, `ng_registerBitmapMetadata` (+ the two tables' decls).
- `registered_class.c`: `registerClassForSymbolVersion` (+ both table decls).
- `action.c`: `transformPixelBoundsGetter` only (§3).
- `tag.h`: `ng_table_grow` prototype.

Pointer-stability argument for the plain-realloc tables. `ng_getFontName` returns a pointer into `ng_fonts`. All 4
callers (`action.c:19087, 27647, 30922, 60489`) use it before any later font registration can happen. A
pointer-of-entries variant was built and gave byte-identical fixture output; it was dropped for a smaller diff.
In-place font tables are safe because every caller of `tagDefineFontMetrics` is generated `static const` storage
(`swf.cpp:3318-3341`). The device-font and builtin tables are static too.

Memory: `ng_fonts` entry shrinks from ~3.2 KB to ~200 B (no inline 512×(2+4) tables). The fixed BSS arrays are gone
(≈ 100 KB fonts + 147 KB exports + 2×33 KB registered classes, etc.).

### Fixture `regression/avm1_many_defs_registry` (graphics == no-graphics, byte-identical)

One SWF8 crosses each cap by a small margin and probes the LAST definition, plus the first as a control. 70 buttons,
40 DefineFont2 + 2 EditTexts, 40 videos, 130 sounds, 1030 exports, 130 registerClass sprites (exported BEFORE the
export flood, so the export cap doesn't confound), 130 bitmaps, 260 labelled sprites, `#initclip` on sprite id 805.
The root plays 1→2→1→2.

```
         before (origin/master)                       after (prototype) = expected-by-Flash-semantics
btnN  typeof=movieclip w=200                     ->  typeof=object w=10
font1 tw=20 fontN tw=0                           ->  font1 tw=20 fontN tw=40
vidN  typeof=movieclip w=200                     ->  typeof=object w=103
snd1 dur=100 sndN dur=undefined                  ->  sndN dur=200
exp0 typeof=movieclip expN typeof=undefined      ->  expN typeof=movieclip
cls0 k=cls clsN k=undefined                      ->  clsN k=cls
bmp1 1x1 bmpN undefinedxundefined                ->  bmpN 3x2
lbl1 cf=3 lblN cf=1                              ->  lblN cf=3
(f1 ic=1 x2, btn1/vid1 controls, init ic=1: unchanged)
```

These "after" values are my Flash-semantics prediction. The golden must come from the exporter (LOCAL ORACLE
REQUESTS). If the exporter disagrees on a line, that line's fix is still a cap removal, but the expected value has
to be re-derived. Exporter risks to check: `Sound.duration` under the null audio backend, and Video `_width`.

### Sweep (before = clean origin/master, after = prototype)

- Set: full `regression` suite (132 dirs, incl. the 2 new fixtures) plus 40 argued avm1 tests touching each changed
  registry:
  - exports / attach: `attach_movie`, `attach_movie_export_not_yet_run`, `export_assets`, `empty_movieclip_can_attach_movies`
  - registerClass: `register_class`, `register_class_swf6`, `register_class_with_sound`, `loadmovie_registerclass`, `register_and_init_order`
  - init actions: `do_init_action`, `do_init_action_child`
  - labels: `goto_label`
  - buttons: `button_children`, `button_goto`, `button_order`, `button_v5`, `button_v6`, `button_properties_special_cases`, `nested_textfields_in_buttons`
  - fonts: `define_font_glyph_table_order/overlap`, `device_font_spacing`, `edittext_default_format_font_style`, `edittext_font_size`, `text_format_get_text_extent_own`, `text_format_font_max_length`
  - sounds: `sound`, `sound_duration_position_props`, `sound_getters`, `sound_mixed_attach_load`, `sound_nested_clips`
  - videos: `video_width_height`, `video_prototype_lazy`, `video_prototype_lazy_swf6_child`
  - bitmaps: `bitmap_data`, `bitmap_data_thorough`, `bitmapdata_custom_rectangle`
  - pixelBounds readers: `movieclip_state_values`, `movieclip_default_state`, `movieclip_library_state_values`
- Both modes, `-P 2`. Compared the saved actual output byte-for-byte, plus status/image lines.
- **Result: in BOTH modes the only test whose actual output changed is `avm1_many_defs_registry`.** Every PASS status
  and every `[image:...]` line (`max difference`, outliers) is identical before/after.
- `avm1/bitmap_data_thorough` is a multi-subtest directory that `--test=` cannot address. It errors the same way
  before and after (harness artifact, not a verdict).

Expected CI movement if landed: `regression/avm1_many_defs_registry` new (pass once its golden lands), nothing else.
**CI-observable: needs BOTH legs** (`ng_shared.c` / `tag.c` / `registered_class.c` are shared with no-graphics).

## 3. The `action.c:10605` float-through-u64 store

`transformPixelBoundsGetter` unions each createEmptyMovieClip child by re-entering `getBounds(mc)` through
`actionCallMethod`. It built the arg count with
`ActionVar one = {0}; one.type = F32; VAL(float,&one.data.numeric_value)=1.0f;` and `pushVar` reads `.numeric_value`
as `u64`. This is the s25 w2-avm1-with-scope class. It is **not** the harmless zero-store variety: a dropped store
leaves 0 = `getBounds()` with no target space.

Evidence:
- **Standalone reproduction (gcc 13.3 -O2, `alias.c` in the Appendix, shape copied from the site):**
  `t1=0` (store DROPPED; push read 0). `-fno-strict-aliasing` → `t1=3f800000`. `-O1` → kept. clang 18 -O2 → kept.
- **In situ:** `gcc -S -O2` of origin/master `action.c` shows `movl $0x3f800000, 336(%rsp)` before the out-of-line
  `pushVar` call in `transformPixelBoundsGetter`. The store survives today because `pushVar` isn't inlined there. One
  inlining change away from the s25 miscompile.
- Fixture `avm1_pixelbounds_dynamic_child` (child at 50,20, 10×10) traces `(x=50, y=20, w=10, h=10)` before, after,
  and with `-fno-strict-aliasing`, in both modes.

Fix (prototype): `ActionVar one = makeF64(1.0);`. Caveat: `makeF64` itself writes `VAL(double, &v.data.numeric_value)`.
Its read-back (`t3` in the probe) was not dropped, but it is the same UB class. §4's header fix covers it, and all
other sites.

Other `VAL(float, &…numeric_value) = 0.0f` stores (`action.c:10578, 16767, 65685`) write 0 into a zeroed struct, so
a dropped store is harmless (as s25 noted). They are left alone; §4 covers them.

## 4. Strict-aliasing audit and recommendation

**Which build paths have TBAA on.** None passes `-fno-strict-aliasing` anywhere; the only hit is SDL3's own cmake.

| Path | Compiler / opt | Strict aliasing |
|---|---|---|
| `verify_output.py` native (CI trace + graphics, `ruffle-tests.yml`) | gcc -O2 (`verify_output.py:3156`) | **ON** (gcc enables it at -O2) |
| `verify_output.py --asan` | gcc -O1 | off |
| `verify_output.py` wasm leg | emcc -O2 (`:3526`) | ON (clang TBAA) |
| `build_test.sh`, `build_graphics_host.sh`, `profile_game_native.sh` | -O2 | ON |
| `build_wasm_avm2.sh`, `wasm_wrappers/bundle/build.sh` (deploy-pages) | emcc RT -O2 / ABC -O1 | ON |
| `build_wasm_runtime_lib.sh`, `build_wasm_test.sh` | wasi clang -O2 | ON |
| in-browser recompiler (`docs/recompiler/pipeline_graphics.js:170`) | clang -O1 | ON (clang runs TBAA at -O1) |
| `SWFModernRuntime/CMakeLists.txt` | no -O set (build-type default) | depends on `CMAKE_BUILD_TYPE` (Release = -O3 → ON) |

**Type-punning patterns that remain.** `ActionVar.data` is a union of `u64` and a string struct, with **no
float/double member**, so every number access is a pointer pun. Site counts in `SWFModernRuntime/src`:
- `VAL(double,` 352, `VAL(u64,` 315, `VAL(float,` 119, `VAL(u32,` 112.
- 18 already use `memcpy`; a handful are raw `*(float*)&` / `*(u64*)&(double){…}` (`action.c:53992, 76471, 76493`).
- The stack macros (`PUSH`, `STACK_TOP_VALUE`, `action.h:303-355`) write `VAL(u64, &STACK[..])` on a `char` buffer.
  Reading those bytes back as `VAL(float/double, …)` is the same UB.
- Generated code uses the same macros.

There are ~800 sites, so fixing them one by one is not realistic.

**Measured** (origin/master `action.c`, NO_GRAPHICS defines, gcc 13.3 -O2):

| | compile | .text | functions whose code changes |
|---|---|---|---|
| default | 25.4 s | 1 063 447 B | — |
| `-fno-strict-aliasing` | 25.2 s | 1 066 159 B (+0.26 %) | **122 of 1081** (net +2.7 KB; largest: `actionCallMethod` +466 B, `actionGetVariableImpl` +283, `drawingFinalizePath` +265, `bitmapDataColorTransform` +229, `actionNewObject` +221) |

Those 122 functions are exactly where gcc currently exploits TBAA, i.e. where a pun can be reordered or dropped.
Behaviour A/B (`SWFRECOMP_EXTRA_DEFINES=-fno-strict-aliasing`, which `verify_output.py` appends to every compile)
over the same 172-test sweep: see "Aliasing behaviour A/B" below. Run time: every sweep test runs in
`x=0.00-0.42 s`, dominated by startup. There is no representative long-running AVM1 corpus test in the cloud (N and
flasharchive SWFs are not here), so a run-time cost could not be measured beyond "not visible". The flag's codegen
delta (+0.26 % code, 11 % of functions touched) predicts low single-digit-percent at worst on hot interpreter loops.

**Recommendation: both, in this order.**
1. **Header fix (one line, covers every site including generated code).** In `action.h:303` replace
   `#define VAL(type, x) *((type*) x)` with typedef'd may_alias types:
   ```c
   typedef u8 __attribute__((__may_alias__)) VAL_ma_u8;   /* ... u16 u32 u64 s8 s16 s32 float double */
   #define VAL(type, x) (*((VAL_ma_##type*) (x)))
   ```
   Measured on the probe: it fixes `t1`/`t2` under gcc -O2 with strict aliasing still on. A plain
   `(type __attribute__((may_alias))*)` cast does NOT work (gcc ignores the attribute there; measured). VAL is used
   only with single-token types: `double, u64, float, u32, u16, u8, s32, s16, s8`. The few `VAL(type,`/`VAL(what,`
   hits are inside other macro definitions and need a check. Both gcc and clang support `may_alias`. Cost is S (one
   header + a compile of every TU). Risk: the same codegen class as the flag, but only at VAL sites.
2. **Add `-fno-strict-aliasing` to every path above** (verify_output native + wasm `common_flags`/`emcc_args`, the
   `SWFRecomp/scripts/*.sh` CFLAGS arrays, `bundle/build.sh`, `pipeline_graphics.js`, CMake
   `target_compile_options`). This covers the raw `*(T*)&` sites and any future pun. Cost: measured zero compile
   time, +0.26 % code. Because it changes ccache keys, the first CI run after it recompiles everything once.

Doing only (2) leaves correctness dependent on a flag that a new build script can forget. Doing only (1) leaves the
raw puns. Do both. Neither is expected to flip a corpus test (A/B below); it removes a latent miscompile class that
has already cost one session (s25).

### Aliasing behaviour A/B

Setup:
- Clean origin/master versus origin/master + `-fno-strict-aliasing` (`SWFRECOMP_EXTRA_DEFINES`).
- Same 172-test set (regression 132 + 40 avm1), both modes.
- Pass-through confirmed: a bogus `-f` flag through the same variable fails the compile with
  `unrecognized command-line option`.

**Result: byte-identical saved actual output for every test in both modes.** Every status line and every
`[image:...]` line (max difference / outliers) is identical too.

So the flag is behaviour-neutral on today's corpus slice and costs nothing measurable at compile time. The 122
re-scheduled functions currently happen to be benign. That is the argument for landing it: protection at zero
observed cost, not a flip.

## Refutations / premise checks

- Brief numbers (buttons 64, fonts 32, videos 32, sounds 128, exports 1024): all **confirmed** at the cited lines, and
  all confirmed to drop with no diagnostic.
- The premise "10605 is a live miscompile" is **refuted for today's build** (asm keeps the store; fixture output is
  correct). It is confirmed as the exact UB shape gcc -O2 drops in isolation. The fix is prophylactic and priced as
  0 flips.
- The init-action guard (< 512) is a real hole, but the fixture shows **no re-run** on a root frame revisit, so its
  fix is also 0 observed flips.

## New unclaimed leads

1. **`MAX_CXFORM_OVERRIDES` 256 restore-stack overflow** (`tag.c:3014`, pushes at `:4011/:8330/:9304`). It records
   inherited-slot pushes too, so > 256 tinted-subtree entries in one frame leave stale dynamic cxform ids into the
   next frame. Fix S: growable. Needs a 2-frame render fixture (tinted container, 300 children, retint on frame 2).
   It is a pixel-axis lead. N-class content (825 tinted tiles) could be near it if those go through `compose_children`.
2. **Filter side tables 32/32** (`tag.c:14264/14352`) keyed by root depth: > 32 filtered root objects lose filters.
   Fix S + fixture.
3. **Text layout caps** (`MAX_TF_PARAGRAPHS` 32, `MAX_LAYOUT_LINES` 256): long text fields truncate layout / scroll.
4. **`MAX_FUNCTIONS` 2048** refuses (with an ERROR line) to define named functions past the cap. Growable is S.
5. **`MAX_INIT_ACTION_MOVIES` 8 aliasing** is fixed by the prototype's per-movie rows (256 movie ids). A
   ≥ 9-loaded-movie `#initclip` fixture would pin it.

## LOCAL ORACLE REQUESTS

1. `regression/avm1_many_defs_registry/test.swf` (generate with `python3 create_test_swf.py` from the patch):
   `exporter -s -f 6 --trace-log out.txt test.swf out.png`. Need the full trace as `output.txt`. Predicted (= our
   prototype):
   ```
   f1 ic=1
   f1 ic=1
   btn1 typeof=object w=10
   btnN typeof=object w=10
   font1 tw=20 fontN tw=40
   vid1 typeof=object w=64
   vidN typeof=object w=103
   snd1 dur=100 sndN dur=200
   exp0 typeof=movieclip expN typeof=movieclip
   cls0 k=cls clsN k=cls
   bmp1 1x1 bmpN 3x2
   lbl1 cf=3 lblN cf=3
   init ic=1
   ```
   Please also record whether `f1 ic=1` appears twice. Flash re-runs frame 1's DoAction on the gotoAndPlay(1)
   revisit; the init action must not re-run.
2. `regression/avm1_pixelbounds_dynamic_child/test.swf`: `exporter -s -f 1 --trace-log out.txt`. Predicted
   `(x=50, y=20, w=10, h=10)`.

## Appendix: strict-aliasing probe (`alias.c`)

`gcc -O2 alias.c` prints `t1=0 t2=0`. `-O2 -fno-strict-aliasing`, `-O1`, `-DMAYALIAS_TD`, and clang 18 -O2 all print `t1=3f800000 t2=3f800000`.

```c
#include <stdio.h>
typedef unsigned long long u64;
typedef struct { int type; unsigned a, b; union { u64 numeric_value; struct { void* p; } s; } data; } AV;
#ifdef MAYALIAS_TD
typedef float __attribute__((__may_alias__)) VAL_ma_float; typedef double __attribute__((__may_alias__)) VAL_ma_double; typedef u64 __attribute__((__may_alias__)) VAL_ma_u64;
#define VAL(type, x) (*((VAL_ma_##type*) (x)))
#elif defined(MAYALIAS)
#define VAL(type, x) (*((type __attribute__((__may_alias__))*) (x)))
#else
#define VAL(type, x) *((type*) x)
#endif
__attribute__((noinline)) void push(u64* stack, AV* v) { *stack = v->data.numeric_value; }
__attribute__((noinline)) u64 t1(u64* stack) {          /* the action.c:10605 shape */
	AV one = {0}; one.type = 1; VAL(float, &one.data.numeric_value) = 1.0f;
	push(stack, &one); return *stack;
}
static inline u64 rd(AV* a) { return a->data.numeric_value; }
__attribute__((noinline)) u64 t2(AV* a) {               /* store then inline u64 read */
	a->data.numeric_value = 0; VAL(float, &a->data.numeric_value) = 1.0f; return rd(a);
}
__attribute__((noinline)) u64 t3(double d) {            /* makeF64 + read */
	AV v = {0}; VAL(double, &v.data.numeric_value) = d; return v.data.numeric_value;
}
int main(void) { u64 st = 0;
	printf("t1=%llx t2=%llx t3=%llx\n", t1(&st), t2(&(AV){0}), t3(1.0)); return 0; }
```
